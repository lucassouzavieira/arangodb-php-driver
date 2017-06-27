namespace Arango\Http;

use Arango\Http\Client;
use Arango\Batch\BatchPart;
use Arango\Exception\ClientException;

/**
 * Manage HTTP responses from ArangoDB server
 *
 * @package Arango/Http
 * @class Response
 * @author Lucas S. Vieira
 */
class Response {

  /**
   * HTTP location header
   */
  const HEADER_LOCATION = "location";

  /**
   * The header retrivied
   *
   * @var string
   */
  private header;

  /**
   * The body retrivied
   *
   * @var string
   */
  private body;

  /**
   * All headers retrivied as associative array
   *
   * @var string
   */
  private headers;

  /**
   * The result status-line
   *
   * @var string
   */
  private result;

  /**
   * HTTP status code of the response
   *
   * @var string
   */
  private httpCode;

  /**
   *  Whether or not the response is for an async request without a response body
   *
   * @var boolean
   */
  private wasAsync;

  /**
   * Whether or not the response is for an async request without a response body
   *
   * @var BatchPart
   */
  private batchPart;


  /**
   * Set up the response
   *
   * @throws \Arango\Exception\ClientException
   *
   * @param string response - The complete HTTP response as supplied from server
   * @param string url - The original URL the response is coming from
   * @param string method - The HTTP method that was used when sending data to original URL
   * @param boolean wasAsync - If was an async request
   *
   * @return void
   */
  public function __construct(string response, string url = null, string method = null, boolean wasAsync = false) {
    var parseMessage, parseHeaders ;
    let this->wasAsync = wasAsync;

    if(!is_null(url) && !is_null(method)){
      if(response == ""){
        throw new ClientException("Got no response from the server after request to " . method . " " . url);
      }
    }

    let parseMessage = Client::parseHttpMessage(response, url, method);
    let this->header = parseMessage[0];
    let this->body = parseMessage[1];

    let parseHeaders = Client::parseHttpHeaders(this->header);
    let this->httpCode = parseHeaders[0];
    let this->result = parseHeaders[1];
    let this->headers = parseHeaders[2];

    if(is_null(this->body) && (this->httpCode != 204 && this->httpCode != 304 && !wasAsync)){
      /* No response body */
      if(!is_null(url) && !is_null(method)){
        throw new ClientException("Got no response from the server after request to " . method . " " . url);
      }

      throw new ClientException("Got no response from the server");
    }
  }

  /**
   * Return the HTTP status code
   *
   * @return int - HTTP status code
   */
  public function getCode() -> int {
     return this->httpCode;
  }

  /**
   * Return an individual HTTP headers of the response
   *
   * @param string name - Name of header
   * @return string | null - header value, NULL if header wasn't set in response
   */
  public function getHeader(string name) -> string | null {
     let name = strtolower(name);

     if(isset(this->headers[name])){
       return this->headers[name];
     }

     return null;
  }

   /**
    * Return the HTTP headers of the response
    *
    * @return array - Array of all headers with values
    */
   public function getHeaders() -> array {
     return this->getHeader(self::HEADER_LOCATION);
   }

   /**
    * Return the location HTTP header of the response
    *
    * @return string | null - Location header value, NULL if header wasn't set in response
    */
   public function getLocation() -> string | null {
     return this->getHeader(self::HEADER_LOCATION);
   }
}
