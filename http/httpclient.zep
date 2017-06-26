namespace ArangoDB\Http;

use ArangoDB\Connection\Options;
use ArangoDB\Connection\Endpoint;
use ArangoDB\Exception\ConnectException;
use ArangoDB\Exception\ClientException;

/**
 * HttpClient to ArangoDB PHP Driver
 *
 * @package ArangoDB/Http
 * @abstract
 * @class HttpClient
 * @author Lucas S. Vieira
 */
abstract class HttpClient {

  /**
   * HTTP method constants
   */
  const GET = "GET";
  const POST = "POST";
  const PUT = "PUT";
  const DELETE = "DELETE";
  const HEAD = "HEAD";
  const PATCH = "PATCH";

  /**
   * Number of bytes processed in one batch
   */
  const CHUNK_SIZE = 8192;

  /**
   * End of line mark used in HTTP
   */
  const EOL = "\r\n";

  /**
   * Separator between header and body
   */
  const SEPARATOR = "\r\n\r\n";

  /**
   * HTTP protocol version used, hard-coded to version 1.1
   */
  const PROTOCOL = "HTTP/1.1";

  /**
   * Boundary string for batch request parts
   */
  const MIME_BOUNDARY = "XXXsubpartXXX";

  /**
   * HTTP Header for making an operation asynchronous
   */
  const ASYNC_HEADER = "X-Arango-Async";

  /**
   * Validate an HTTP method request name
   *
   * @throws \ArangoDB\Exception\ClientException
   * @param string method - method name
   * @return boolean - always true - throw an exception if method is not valid
   */
  public static function validateMethod(string method) {
    array methods;

    let methods = [
      self::GET, self::PUT, self::POST, self::DELETE, self::HEAD, self::PATCH
    ];

    if(in_array(method, methods)){
      return true;
    }

    throw new ClientException("Invalid request method:  " . method);
  }

  /**
   * Splits an http message into its header and body
   *
   * @param string httpMessage  HTTP message
   * @return array
   */
  public static function parseHttpMessage(string httpMessage){
    return explode(self::SEPARATOR, httpMessage, 2);
  }

  /**
   * Process a string of HTTP headers into an array of header => values
   *
   * @param string headers  HTTP header
   * @return array
   */
  public static function parseHttpHeaders(string headers){
    var httpCode;
    var result;
    array processed;

    var lineNumber, line;

    for lineNumber, line in explode(self::EOL, headers) {
      var key, value;
      var elements;

      /* First line is special */
      if(lineNumber == 0){
        var matches;
        if(preg_match("/^HTTP\/\d+\.\d+\s+(\d+)/", line, matches)){
          let httpCode = (int) matches[1];
        }

        let result = line;
        continue;
      }

      /* Other lines contain key:value headers */
      if(strpos(line, ": ") !== false){
        let elements = explode(": ", line, 2);
      } else {
        let elements = explode(":", line, 2);
      }

      let key = elements[0];
      let value = elements[1];

      let processed[strtolower(key)] = value;
    }

    return [httpCode, result, processed];
  }

  /**
   * Create a one-time HTTP connection by opening a socket to the server
   * It is the caller's responsibility to close the socket
   *
   * @throws \ArangoDB\Exception\ConnectException | \Exception
   * @param Options options - Connection options
   * @return resource - socket with server connection
   */
   public static function createConnection(<Options> options){
     var endpoint;
     var context;
     var socketResource;
     var error;
     var message;

     let endpoint = options[Options::ENDPOINT];
     let context = stream_context_create();

     /* SSL connection */
     if(Endpoint::getType(endpoint) === Endpoint::TYPE_SSL){
       stream_context_set_option(context, "ssl", "verify_peer", options[Options::VERIFY_CERT]);
       stream_context_set_option(context, "ssl", "allow_self_signed", options[Options::ALLOW_SELF_SIGNED]);

       if(!is_null(options[Options::CIPHERS])){
         stream_context_set_option(context, "ssl", "ciphers", options[Options::CIPHERS]);
       }
     }

     let socketResource = stream_socket_client(
       endpoint,
       error,
       message,
       options[Options::TIMEOUT],
       context
     );

     if(!socketResource){
       throw new ConnectException("Cannot connect to endpoint \ " . options[Options::ENDPOINT] . " \: " . message . error );
     }

     stream_set_timeout(socketResource, Options::TIMEOUT);

     return socketResource;
   }

   /**
    * Create a request string (header and body)
    *
    * @param Options options - Connection options
    * @param string header - Pre-assembled header string for connection
    * @param string method - HTTP method
    * @param string url - HTTP url
    * @param string body - Optional body to post
    * @param array customHeaders - Any array containing header elements
    *
    * @throws \ArangoDB\Exception\ClientException
    * @return string - Assembled HTTP request string
    */
   public static function buildRequest(<Options> options,
     string header,
     string method,
     string url,
     string body,
     array customHeaders) -> string {
       var lenght, contentType, customHeader, request;

       let lenght = strlen(body);

       let contentType = "Content-Type: multipart/form-data; boundary=" . self::MIME_BOUNDARY . self::EOL;

       if(!options[Options::BATCH]){
         let contentType = "";

         if(lenght > 0 && options[Options::BATCHPART] == false){
           let contentType = "Content-Type: application/json" . self::EOL;
         }
       }

       let customHeader = "";

       var headerKey, headerValue;

       for headerKey, headerValue in customHeaders {
         let customHeader = customHeader . headerKey . ": " . headerValue . self::EOL;
       }

       // Assemble the request
       let request = sprintf("%s %s %s", method, url, self::PROTOCOL);
       let request = request . header . customHeader . contentType;
       let request = request . sprintf("Content-Length: %s", lenght) . self::EOL . self::EOL;
       let request = request . body;

       return request;
   }

   /**
    * Create a request string (header and body)
    *
    * @param resource socket - Connection socket
    * @param string request - HTTP request as a string
    * @param string method - HTTP method used
    *
    * @throws \ArangoDB\Exception\ClientException
    * @return string - HTTP response string
    */
   public static function transfer(socket, string request, string method) -> string {
     var contentLenght = null, expectedLenght = null;
     var totalRead = 0, contentLenghtPosition = 0;
     var result = "", first = true;
     var read;

     if(!is_resource(socket)){
       throw new ClientException("Invalid socket used");
     }

     fwrite(socket, request);
     fflush(socket);

     while(first || !feof(socket)){
       let read = fread(socket, self::CHUNK_SIZE);

       if(read == false || read == ""){
         break;
       }

       let totalRead = totalRead + strlen(read);

       if(first){
         let result = read;
         let first = false;
       } else {
         let result = result . read;
       }

       if(contentLenght == null){
         var position;

         // 12 = minimum offset (i.e. strlen("HTTP/1.1 xxx") -
         // after that we could see "content-length:"
         let position = stripos(result, "content-lenght", 12);

         if(position != false){
           let contentLenght = (int) substr(result, position + strlen("content-length: "), 10);
           let contentLenghtPosition = position + 17; // 16 + 1

           if(method == "HEAD"){
             let contentLenght = 0;
           }
         }
       }

       if(contentLenght != null && expectedLenght == null){
         var bodyStart;

         let bodyStart = strpos(result, "\r\n\r\n", contentLenghtPosition);

         if(bodyStart != false){
           let bodyStart = bodyStart + strlen("\r\n\r\n");
           let expectedLenght = bodyStart + contentLenght;
         }

         if(expectedLenght != null && totalRead >= expectedLenght){
           break;
         }
       }
     }

     return result;
   }

}
