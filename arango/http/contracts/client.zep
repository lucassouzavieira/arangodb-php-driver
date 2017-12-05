
namespace Arango\Http\Contracts;

use Arango\Http\Contracts\Uri;
use Arango\Http\Contracts\Request;
use Arango\Http\Contracts\Response;

/**
 * Http client interface
 *
 * @package Arango\Http\Contracts
 * @author Lucas S. Vieira
 */
interface Client {

  /**
   * Request to a remote server
   *
   * @param string method The method type
   * @param string|Arango\Http\Contracts\Uri The URL to request or URI object
   * @param mixed data The request body data
   * @param array headers The headers array
   *
   * @return Arango\Http\Contracts\Response
   */
  public function request(string method, url, data = null, array headers = []) -> <Response>;

  /**
   * Send a request to remote
   *
   * @param Arango\Http\Contracts\Request request The PSR-7 Request object
   *
   * @return Arango\Http\Contracts\Response
   */
  public function send(<Request> request) -> <Response>;
}
