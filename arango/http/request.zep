
namespace Arango\Http;

use Arango\Http\Client;
use Arango\Http\Response;
use Arango\Exception\ServerException;

/**
 * Abstracts basic request methods for classes
 *
 * @package Arango/Http
 * @interface Request
 * @author Lucas S. Vieira
 */
abstract class Request implements RequestInterface {

  /**
   * Issue an HTTP GET request
   *
   * @throws \Exception
   *
   * @param string url - GET URL
   * @param array customHeaders
   *
   * @return Response
   */
  public function get(string url, array customHeaders = []) -> <Response> {
    var response;

    let response = this->executeRequest(Client::GET, url, "", customHeaders);
    return this->parseResponse(response);
  }

  /**
   * Issue an HTTP POST request
   *
   * @throws \Exception
   *
   * @param string url - POST URL
   * @param array customHeaders
   *
   * @return Response
   */
  public function post(string url, array customHeaders = []) -> <Response> {
    var response;

    let response = this->executeRequest(Client::POST, url, "", customHeaders);
    return this->parseResponse(response);
  }

  /**
   * Issue an HTTP PUT request
   *
   * @throws \Exception
   *
   * @param string url - PUT URL
   * @param array customHeaders
   *
   * @return Response
   */
  public function put(string url, array customHeaders = []) -> <Response> {
    var response;

    let response = this->executeRequest(Client::PUT, url, "", customHeaders);
    return this->parseResponse(response);
  }

  /**
   * Issue an HTTP HEAD request
   *
   * @throws \Exception
   *
   * @param string url - HEAD URL
   * @param array customHeaders
   *
   * @return Response
   */
  public function head(string url, array customHeaders = []) -> <Response> {
    var response;

    let response = this->executeRequest(Client::HEAD, url, "", customHeaders);
    return this->parseResponse(response);
  }

  /**
   * Issue an HTTP PATCH request
   *
   * @throws \Exception
   *
   * @param string url - PATCH URL
   * @param array customHeaders
   *
   * @return Response
   */
  public function patch(string url, array customHeaders = []) -> <Response> {
    var response;

    let response = this->executeRequest(Client::PATCH, url, "", customHeaders);
    return this->parseResponse(response);
  }

  /**
   * Issue an HTTP DELETE request
   *
   * @throws \Exception
   *
   * @param string url - DELETE URL
   * @param array customHeaders
   *
   * @return Response
   */
  public function delete(string url, array customHeaders = []) -> <Response> {
    var response;

    let response = this->executeRequest(Client::DELETE, url, "", customHeaders);
    return this->parseResponse(response);
  }

  /**
   * Parse the response
   *
   * Return body values as an associative array
   *
   * @throws \Exception
   *
   * @param Response response - The response as supplied by server
   *
   * @return Response
   */
  public function parseResponse(<Response> response) -> <Response> {
    var httpCode;

    let httpCode = response->getCode();

    if(httpCode < 200 || httpCode >= 400) {
      // Server failure
      var body;
      let body = response->toArray();

      // Check for failure details
      if(count(body) && isset(body["errorMessage"])) {
        var exception;

        let exception = new ServerException(body["errorMessage"], body["code"]);
        exception->setDetails(body);
        throw exception;
      }

      throw new ServerException($response->getResult(), httpCode);
    }

    return response;
  }
}
