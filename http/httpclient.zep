namespace ArangoDB\Http;

use ArangoDB\Connection\Options;
use ArangoDB\Connection\Endpoint;
use ArangoDB\Exception\ConnectException;

/**
 * HttpClient to ArangoDB PHP Driver
 *
 * TODO A lot of things
 *
 * @package ArangoDB/Http
 * @class HttpClient
 * @author Lucas S. Vieira
 */
class HttpClient {

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
}
