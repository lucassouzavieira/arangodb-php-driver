
namespace Arango\Exception;

/**
 * ConnectException class
 *
 * This exception type will be thrown by the client when there is an error
 *
 * @package Arango/Exception
 * @class ConnectException
 * @author Lucas S. Vieira
 */
class ConnectException extends \Exception {

  /**
   * TODO add class name
   **/
  public function __toString(){
    return this->getMessage();
  }
}
