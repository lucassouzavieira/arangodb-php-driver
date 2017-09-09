
namespace Arango\Connection;

/**
 * Trace requests to server
 *
 * @package Arango/Connection
 * @class TraceRequest
 * @author Lucas S. Vieira
 */
class TraceRequest {

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
   * @var string
   */
  private method {
    get
  };

  /**
   * Stores the request URL
   *
   * @var string
   */
  private requestUrl {
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
   * HTTP message type
   *
   * @var string
   */
  private type = "request" {
    get
  };

  /**
   * Set up the Trace
   *
   * @param array headers     - array with HTTP headers
   * @param string method     - HTTP method
   * @param string requestUrl - request URL
   * @param string body       - request body
   */
  public function __construct(array headers, string method, string requestUrl, string body) {
    let this->headers = headers;
    let this->method = method;
    let this->requestUrl = requestUrl;
    let this->body = body;
  }

}
