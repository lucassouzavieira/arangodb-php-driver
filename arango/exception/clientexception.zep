
namespace Arango\Exception;

/**
 * ClientException class
 *
 * Thrown by client when there is error on client side
 *
 * @package Arango/Exception
 * @class ClientException
 * @author Lucas S. Vieira
 */
class ClientException extends \Exception {

  /**
   * TODO add class name
   **/
  public function __toString(){
    return this->getMessage();
  }
}
