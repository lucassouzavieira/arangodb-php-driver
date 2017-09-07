
namespace Arango\Exception;

/**
 * Thrown by client when there is error on server side
 *
 * @package Arango/Exception
 * @class ServerException
 * @author Lucas S. Vieira
 */
class ServerException extends \Exception {

  /**
   * Optional details for the exception
   *
   * @var array
   */
  private details = [] {
    get, set
  };

  /**
   * Server exception indexes
   */
  const ENTRY_CODE = "errorNum";
  const ENTRY_MESSAGE = "errorMessage";


  /**
   * Class where ServerException was thrown with Exception message.
   *
   * @return string
   */
  public function __toString() -> string {
    return __CLASS__ . ": " . this->getServerCode() . " " . this->getMessage();
  }


  /**
   * Get server error code
   * If the server has provided additional details about the error
   * that occurred, this will return the server error code
   *
   * @return int
   */
  public function getServerCode() -> int {
    if(isset(this->details[self::ENTRY_CODE])){
      return this->details[self::ENTRY_CODE];
    }

    return this->getCode();
  }

  /**
   * Get server error message
   * If the server has provided additional details about the error
   * that occurred, this will return the server error string
   *
   * @return string
   */
  public function getServerMessage() -> string {
    if(isset(this->details[self::ENTRY_MESSAGE])){
      return this->details[self::ENTRY_MESSAGE];
    }

    return "";
  }
}
