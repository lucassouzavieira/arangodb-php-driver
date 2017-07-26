
namespace Arango\Handler;

use Arango\Http\Api;
use Arango\Http\Url;
use Arango\Http\Response;
use Arango\Connection\Encoding;
use Arango\Connection\Connection;

/**
 * AQL query result cache handling
 *
 * @package Arango/Handler
 * @class QueryCacheHandler
 * @author Lucas S. Vieira
 */
class QueryCacheHandler extends Handler {

  /**
   * Globally turns on the AQL query result cache
   *
   * @throws \Exception
   */
  public function enable() -> void {
    var url;

    let url = Url::buildUrl(Api::QUERY_CACHE, ["properties"]);
    this->getConnection()->put(url, Encoding::jsonWrapper(["mode": "on"]));
  }

  /**
   * Globally turns off the AQL query result cache
   *
   * @throws \Exception
   */
  public function disable() -> void {
    var url;

    let url = Url::buildUrl(Api::QUERY_CACHE, ["properties"]);
    this->getConnection()->put(url, Encoding::jsonWrapper(["mode": "off"]));
  }

  /**
   * Globally sets the AQL query result cache to demand mode
   *
   * @throws \Exception
   */
  public function enableDemandMode() -> void {
    var url;

    let url = Url::buildUrl(Api::QUERY_CACHE, ["properties"]);
    this->getConnection()->put(url, Encoding::jsonWrapper(["mode": "demand"]));
  }


  /**
   * Adjusts the global AQL query result cache properties
   *
   * @throws \Exception
   *
   * @param array properties - The following properties can be used:
   *                            "maxResults": Maximum number of results that the query cache
   *                                           will ber hold per database
   *                            "mode":  Turns the query result cache on or off or sets it to demand mode
   *                                     Passible values are "on", "off", or "demand"
   *
   * @return void
   */
  public function setProperties(array properties) -> void {
    var url;

    let url = Url::buildUrl(Api::QUERY_CACHE, []);
    this->getConnection()->delete(url);
  }

  /**
   * Returns the AQL query result cache properties
   *
   * @throws \Exception
   *
   * @return array
   */
  public function getProperties() -> array {
    var url, response;

    let url = Url::buildUrl(Api::QUERY_CACHE);
    let response = this->getConnection()->get(url);

    return response->toArray();
  }

}
