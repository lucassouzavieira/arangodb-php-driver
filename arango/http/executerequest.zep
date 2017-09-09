
namespace Arango\Http;

use Arango\Http\Response;

/**
 * Abstracts basic request methods for classes
 *
 * @package Arango/Http
 * @interface Request
 * @author Lucas S. Vieira
 */
interface ExecuteRequest {

  /**
   * Execute an HTTP request and return the results
   *
   * This function will throw if no connection to the server can be established or if
   * there is a problem during data exchange with the server.
   *
   * will restore it.
   *
   * @throws \Exception
   *
   * @param string method       - HTTP request method
   * @param string url          - HTTP url
   * @param string data         - HTTP request data
   * @param array customHeaders - Any custom headers for the request
   *
   * @return Response
   */
  protected function executeRequest(string method,
    string url,
    string data,
    array customHeaders) -> <Response>;
}
