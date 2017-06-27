
namespace Arango\Policies;

/**
 * Policy interface
 *
 * @package Arango\Policies
 * @author Lucas S. Vieira
 */
interface Policy {

  /**
   * Validate an supplied policy value
   *
   * @throws \Arango\Exception\ClientException if the value supplied is not valid
   * @return void
   */
  public static function validate(string value) -> void;
}
