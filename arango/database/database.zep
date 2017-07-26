
namespace Arango\Database;

use Arango\Http\Api;
use Arango\Http\Url;
use Arango\Http\Response;
use Arango\Connection\Options;
use Arango\Connection\Encoding;
use Arango\Connection\Connection;

/**
 * Database class
 *
 * Manage Arango databases through Arango's Database API
 *
 * @link https://docs.Arango.com/3.1/HTTP/Database/
 * @package Arango\Database
 * @class Database
 * @author Lucas S. Vieira
 */
abstract class Database {

  /**
   * Database indexes
   */
  const NAME = "name";
  const USERS = "users";

  /**
   * Creates a database
   *
   * @throws Arango\Exception\ClientException
   *
   * @link https://docs.arangodb.com/3.2/HTTP/Database/DatabaseManagement.html
   *
   * @param Connection connection   - Connection to be used
   * @param string name             - Database name
   *
   * @return array - Database info
   */
  public static function create(<Connection> connection, string name) -> array {
    var payload, response, users;

    let users = [
      "username": connection->getOption(Options::AUTH_USER),
      "passwd": connection->getOption(Options::AUTH_PASSWD)
    ];

    let payload = [
      self::NAME: name,
      self::USERS: [users]
    ];

    let response = connection->post(Api::DATABASE, Encoding::jsonWrapper(payload));
    return response->toArray();
  }

  /**
   * Deletes a database
   *
   * @throws Arango\Exception\ClientException
   *
   * @link https://docs.arangodb.com/3.2/HTTP/Database/DatabaseManagement.html
   *
   * @param Connection connection   - Connection to be used
   * @param string name             - Database name
   *
   * @return array - response array
   */
  public static function delete(<Connection> connection, string name) -> array {
    var url, response;

    let url = Url::buildUrl(Api::DATABASE, [name]);
    let response = connection->delete(url);

    return response->toArray();
  }

  /**
   * Lists the databases that exist on the server
   *
   * @throws Arango\Exception\ClientException
   *
   * @link https://docs.arangodb.com/3.2/HTTP/Database/DatabaseManagement.html
   *
   * @param Connection connection   - Connection to be used
   *
   * @return array - response array
   */
  public static function list(<Connection> connection) -> array {
    var response;

    let response = connection->get(Api::DATABASE);
    return response->toArray();
  }

  /**
   * Lists user databases
   *
   * @throws Arango\Exception\ClientException
   *
   * @link https://docs.arangodb.com/3.2/HTTP/Database/DatabaseManagement.html
   *
   * @param Connection connection   - Connection to be used
   *
   * @return array - response array
   */
  public static function listUserDatabases(<Connection> connection) -> array {
    var url, response;

    let url = Url::buildUrl(Api::DATABASE, ["user"]);
    let response = connection->get(url);
    return response->toArray();
  }

  /**
   * Retrieves informations about the current database from server
   *
   * @throws Arango\Exception\ClientException
   *
   * @link https://docs.arangodb.com/3.2/HTTP/Database/DatabaseManagement.html
   *
   * @param Connection connection   - Connection to be used
   *
   * @return array - response array
   */
  public static function info(<Connection> connection) -> array {
    var url, response;

    let url = Url::buildUrl(Api::DATABASE, ["current"]);
    let response = connection->get(url);
    return response->toArray();
  }
}
