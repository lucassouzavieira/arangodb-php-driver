
namespace Arango\Connection;

use Arango\Exception\ClientException;

/**
 * TraceResponse class
 *
 * Trace responses from server
 *
 * @package Arango/Connection
 * @class TraceResponse
 * @author Lucas S. Vieira
 */
class TraceResponse {

  /**
   * Stores each header as key-element pair in an array
   *
   * @var array
   */
  private headers = [] {
    get
  };

  /**
   * Stores HTTP method
   *
   * @var int
   */
  private httpCode {
    get
  };

  /**
   * Stores the string of the body
   *
   * @var string
   */
  private body {
    get
  };

  /**
   * The time taken to send the request and receive an Response from server
   *
   * @var float
   */
  private timeTaken {
    get
  };

  /**
   * HTTP message type
   *
   * @var string
   */
  private type = "request" {
    get
  };

  /**
   * Used to look up the definition for an http code
   *
   * @link https://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html
   * @var array
   */
  private httpCodeDefinitions = [
        100 : "Continue",
        101 : "Switching Protocols",
        200 : "OK",
        201 : "Created",
        202 : "Accepted",
        203 : "Non-Authoritative Information",
        204 : "No Content",
        205 : "Reset Content",
        206 : "Partial Content",
        300 : "Multiple Choices",
        301 : "Moved Permanently",
        302 : "Found",
        303 : "See Other",
        304 : "Not Modified",
        305 : "Use Proxy",
        307 : "Temporary Redirect",
        400 : "Bad Request",
        401 : "Unauthorized",
        402 : "Payment Required",
        403 : "Forbidden",
        404 : "Not Found",
        405 : "Method Not Allowed",
        406 : "Not Acceptable",
        407 : "Proxy Authentication Required",
        408 : "Request Timeout",
        409 : "Conflict",
        410 : "Gone",
        411 : "Length Required",
        412 : "Precondition Failed",
        413 : "Request Entity Too Large",
        414 : "Request-URI Too Long",
        415 : "Unsupported Media Type",
        416 : "Requested Range Not Satisfiable",
        417 : "Expectation Failed",
        418 : "I\"m a teapot",
        500 : "Internal Server Error",
        501 : "Not Implemented",
        502 : "Bad Gateway",
        503 : "Service Unavailable",
        504 : "Gateway Timeout",
        505 : "HTTP Version Not Supported"
    ];

    /**
     * Set up the Trace
     *
     * @throws Arango\Exception\ClientException
     *
     * @param array headers    - array with HTTP headers
     * @param int httpCode     - HTTP code
     * @param string body      - request body
     * @param float timeTaken  - time taken to make request and receive an response
     */
    public function __construct(array headers, int httpCode, string body, float timeTaken) {
      if(!array_key_exists(httpCode, this->httpCodeDefinitions)) {
        throw new ClientException("Invalid HTTP Code given");
      }

      let this->headers = headers;
      let this->httpCode = httpCode;
      let this->body = body;
      let this->timeTaken = timeTaken;
    }

    /**
     * Get HTTP Code definition
     *
     * @return string
     */
    public function getHttpCodeDefinition() -> string {
      return this->httpCodeDefinitions[this->httpCode];
    }
}
