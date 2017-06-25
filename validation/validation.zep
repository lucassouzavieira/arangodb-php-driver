
namespace ArangoDB\Validation;

use ArangoDB\Exception\ClientException;

/**
 * Validation class
 *
 * @package ArangoDB/Validation
 * @class Validation
 * @author Lucas S. Vieira
 */
abstract class Validation {

  /**
   * String, integer, float, boolean and null values are allowed.
   * Arrays also are allowed if they contain only one of these types.
   *
   * @throw ClientException if value is not valid
   * @return void
   */
  public static function validateValue(value) -> void {

    if(is_string(value) || is_int(value) || is_float(value) || is_bool(value) || is_null(value)){
      return;
    }

    /* Check all values in array */
    if(is_array(value)){
      var data;
      for data in value {
        self::validateValue(data);
      }
    }

    throw new ClientException("Invalid bind parameter value");
  }
}
