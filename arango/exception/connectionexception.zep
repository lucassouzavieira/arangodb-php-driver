
namespace Arango\Exception;

/**
 * ConnectionException class
 *
 * This exception type will be thrown by the client when there is an error
 *
 * @package Arango/Exception
 * @class ConnectionException
 * @author Lucas S. Vieira
 */
class ConnectionException extends \Exception {

  /**
   * Class where ConnectionException was thrown with Exception message.
   *
   * @return string
   */
  public function __toString() -> string {
    return __CLASS__ . ": " . this->getMessage();
  }
}
