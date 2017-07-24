
namespace Arango\Handler;

use Arango\Http\Url;
use Arango\Http\Api;

/**
 * A handler that manages queries
 *
 * @package Arango/Handler
 * @class QueryHandler
 * @author Lucas S. Vieira
 */
class QueryHandler extends Handler {

  /**
   * Clears the list of slow queries
   *
   * TODO Review after implements Handler class
   * @throws \Exception
   */
  public function clearSlow() -> void {
    var url;

    let url = Url::buildUrl(Api::QUERY, ["slow"]);
    // this->getConnection()->delete(url);
  }


  /**
   * Returns the list of slow queries
   *
   * TODO Review after implements Handler class and change return type
   * @throws \Exception
   * @return array
   */
  public function getSlow() -> void {
    var url;

    let url = Url::buildUrl(Api::QUERY, ["slow"]);
    // let response = this->getConnection()->get(url);
    // return response->toArray();
  }

  /**
   * Returns the list of currently executing queries
   *
   * TODO Review after implements Handler class and change return type
   * @throws \Exception
   * @return array
   */
  public function getCurrent() -> void {
    var url;

    let url = Url::buildUrl(Api::QUERY, ["current"]);
    // let response = this->getConnection()->get(url);
    // return response->toArray();
  }

  /**
   * Kills a specific query
   *
   * This will send an HTTP DELETE command to server to terminate the query
   * TODO Review after implements Handler class
   * @throws \Exception
   * @return bool
   */
  public function kill(string queryId) -> bool {
    var url;

    let url = Url::buildUrl(Api::QUERY, [queryId]);
    // let response = this->getConnection()->get(url);
    return true;
  }
}
