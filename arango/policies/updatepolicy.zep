
namespace Arango\Policies;

use Arango\Exception\ClientException;

/**
 * UpdatePolicy class
 *
 * @package Arango/Policies
 * @class UpdatePolicy
 * @author Lucas S. Vieira
 */
class UpdatePolicy implements PolicyInterface {

  /* Last update will win in case of conflicting versions*/
  const LAST = "last";

  /* An error will be returned in case of conflicting versions */
  const ERROR = "error";

  /**
   * Validate a supplied policy value
   *
   * @throws \Arango\Exception\ClientException
   * @param string value - update policy value
   * @return void
   */
  public static function validate(string value) -> void {
    if(value != self::LAST && value != self::ERROR){
      throw new ClientException("Invalid policy");
    }
  }
}
