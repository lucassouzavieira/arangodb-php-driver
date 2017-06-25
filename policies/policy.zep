
namespace ArangoDB\Policies;

/**
 * Policy interface
 *
 * @package ArangoDB\Policies
 * @author Lucas S. Vieira
 */
interface Policy {

  /**
   * Validate an supplied policy value
   * @return void
   */
  public static function validate(string value) -> void;
}
