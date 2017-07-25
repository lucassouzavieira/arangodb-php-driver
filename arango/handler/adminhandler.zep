
namespace Arango\Handler;

use Arango\Http\Api;
use Arango\Http\Url;
use Arango\Http\Response;
use Arango\Handler\Handler;
use Arango\Connection\Connection;

/**
 * A handler that manages admin document
 *
 * @package Arango/Handler
 * @class AdminHandler
 * @author Lucas S. Vieira
 */
class AdminHandler extends Handler {

  /**
   * Details for server version
   */
  const OPTION_DETAILS = "details";

  /**
   * Get the server version
   *
   * @throws \Exception
   *
   * @param boolean details - True to get a more detailed response
   *
   * @return array | string
   */
  public function getServerVersion(boolean details = false) -> array | string {
    var url, response;

    let url = Api::ADMIN_VERSION;

    if(details){
      let url = Url::appendParamsToUrl(url, ["details": true]);
    }

    var data;
    let response = this->getConnection()->get(url);
    let data = response->toArray();

    if(details){
      return data;
    }

    return data["version"];
  }

  /**
   * Get the server role
   *
   * @throws \Exception
   *
   * @return string - server role
   */
  public function getServerRole() -> string {
    var response, data;

    let response = this->getConnection()->get(Api::ADMIN_SERVER_ROLE);
    let data = response->toArray();

    return data["role"];
  }

  /**
   * Get the server time
   *
   * @throws \Exception
   *
   * @return double - a double holding the timestamp
   */
  public function getServerTime() -> double {
    var response, data;

    let response = this->getConnection()->get(Api::ADMIN_TIME);
    let data = response->toArray();

    return data["time"];
  }

  /**
   * Get the server log
   *
   * This will throw if the log cannot be retrieved
   *
   * @throws Exception
   *
   * @param array $options - an array of options that define the result-set:
   *
   * Options are :
   * 'upto' - returns all log entries up to a log-level. Note that log-level must be one of:
   *  - fatal / 0
   *  - error / 1
   *  - warning / 2
   *  - info / 3
   *  - debug / 4
   *
   * 'level'  -  limits the log entries to the ones defined in level. Note that `level` and `upto` are mutably exclusive.
   * 'offset' -  skip the first offset entries.
   * 'size'   -  limit the number of returned log-entries to size.
   * 'start'  -  Returns all log entries such that their log-entry identifier is greater or equal to lid.
   * 'sort'   -  Sort the log-entries either ascending if direction is asc, or descending if it is desc according to their lid. Note that the lid imposes a chronological order.
   * 'search' -  Only return the log-entries containing the text string...
   *
   * @return array - an array holding the various attributes of a log: lid, level, timestamp, text and the total amount of log entries before pagination.
   */
  public function getServerLog(array options = []) -> array {
    var url, response;

    let url = Url::appendParamsToUrl(Api::ADMIN_LOG, options);
    let response = this->getConnection()->get(url);

    return response->toArray();
  }

  /**
   * Reload the server's routing information
   * The call triggers a reload of the routing information from the _routing collection
   * This will throw if the routing cannot be reloaded
   *
   * @throws Exception
   *
   * @return bool
   */
  public function reloadServerRouting() -> boolean {
    this->getConnection()->post(Api::ADMIN_ROUTING_RELOAD, []);
    return true;
  }

  /**
   * Get the server statistics
   * Returns the statistics information. The returned objects contains the statistics figures, grouped together
   * according to the description returned by _admin/statistics-description.
   * For instance, to access a figure userTime from the group system, you first select the sub-object
   * describing the group stored in system and in that sub-object the value for userTime is stored in the
   * attribute of the same name.In case of a distribution, the returned object contains the total count in count
   * and the distribution list in counts.
   * For more information on the statistics returned, please lookup the statistics interface description at
   *
   * @link  https://docs.arangodb.com/HTTP/AdministrationAndMonitoring/index.html
   *
   * This will throw if the statistics cannot be retrieved
   *
   * @throws Exception
   *
   * @return array
   */
  public function getServerStatistics() -> array {
    var response;

    let response = this->getConnection()->get(Api::ADMIN_STATISTICS);
    return response->toArray();
  }

  /**
   * Returns a description of the statistics returned by getServerStatistics().
   * The returned objects contains a list of statistics groups in the attribute groups
   * and a list of statistics figures in the attribute figures.
   * For more information on the statistics returned, please lookup the statistics interface description at
   *
    * @link  https://docs.arangodb.com/HTTP/AdministrationAndMonitoring/index.html
    *
    * This will throw if the statistics-description cannot be retrieved
    *
    * @throws Exception
    *
    * @param array $options - an array of options that define the result-set:
    *
    * Options are :
    * 'granularity' - use minutes for a granularity of minutes, hours for hours, and days for days. The default is minutes.
    * 'figures' - a list of figures, comma-separated. Possible figures are httpConnections. You can use all to get all figures. The default is httpConnections.
    * 'length' - If you want a time series, the maximal length of the series as integer. You can use all to get all available information. You can use current to get the latest interval.
    *
    * @return array
    */
  public function getServerStatisticsDescription(array options = []) -> array {
    var url, response;

    let url = Url::appendParamsToUrl(Api::ADMIN_STATISTICS_DESCRIPTION, options);
    let response = this->getConnection()->get(url);

    return response->toArray();
  }
}
