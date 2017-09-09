
namespace Arango\Exception;

use Arango\Exception\Exception;

/**
 * Thrown by client when there is error on client side
 *
 * @package Arango/Exception
 * @class ClientException
 * @author Lucas S. Vieira
 */
class ClientException extends Exception {

  /**
   * Class where ClientException was thrown with Exception message.
   *
   * @return string
   */
  public function __toString() -> string {
    return __CLASS__ . ": " . this->getMessage();
  }
}
