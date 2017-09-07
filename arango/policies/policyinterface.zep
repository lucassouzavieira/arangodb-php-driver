
namespace Arango\Policies;

/**
 * Policy interface
 *
 * @package Arango\Policies
 * @interface Policy
 * @author Lucas S. Vieira
 */
interface PolicyInterface {

  /**
   * Validate an supplied policy value
   *
   * @throws \Arango\Exception\ClientException
   *
   * @return void
   */
  public static function validate(string value) -> void;
}
