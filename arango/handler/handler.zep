
namespace Arango\Handler;

use Arango\Connection\Encoding;
use Arango\Connection\Connection;
use Arango\Collection\Collection;
use Arango\Document\Document;

/**
 * A base class for REST-based handlers
 * TODO all
 * @package Arango/Handler
 * @class Handler
 * @author Lucas S. Vieira
 */
abstract class Handler {

  /**
   * Connection object
   *
   * @var Connection
   */
  private connection;

  /**
   * Construct a new handler
   *
   * @param Connection connection - Connection to be used
   */
  public function __construct(<Connection> connection) {
    let this->connection = connection;
  }

  /**
   * Returns the connection object
   *
   * @return Arango\Connection\Connection
   */
  protected function getConnection() -> <Connection> {
    return this->connection;
  }

  /**
   * Returns an connection option
   *
   * @param string option - Option name
   *
   * @return mixed
   */
  protected function getConnectionOption(string option) {
    return this->getConnection()->getOption(option);
  }

  /**
   * Return a JSON encoded string for the array given.
   *
   * @throws Arango\Exception\ClientException
   *
   * @param array body - The body to encode into JSON
   *
   * @return string    - JSON string of the body
   */
  protected function jsonWrapper(array body) -> string {
    return Encoding::jsonWrapper(body);
  }

  /**
   * Turn a value into a Collection name
   *
   * @param mixed value - Document, Collection or string
   * @link https://github.com/arangodb/arangodb-php/blob/devel/lib/ArangoDBClient/Handler.php#L148-L158
   * @return string     - Collection name or empty string if the value is not an Document or Collection
   */
  protected function getCollectionName(value) -> string {
    if(value instanceof Collection) {
      return value->getName();
    }

    if(value instanceof Document) {
      return value->getConnectionId();
    }

    // Fallback is empty string
    return "";
  }
}
