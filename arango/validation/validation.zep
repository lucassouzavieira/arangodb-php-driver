
namespace Arango\Validation;

use Arango\Exception\ClientException;

/**
 * Validation class
 *
 * @package Arango/Validation
 * @class Validation
 * @abstract
 * @author Lucas S. Vieira
 */
abstract class Validation {

  /**
   * String, integer, float, boolean and null values are allowed.
   * Arrays also are allowed if they contain only one of these types.
   *
   * @throw \Arango\Exception\ClientException if value is not valid
   * @param mixed value - Value to validate
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
