namespace Arango\Validation;

use Arango\Exception\ClientException;

/**
 * Container for bind variables
 *
 * @package Arango/Validation
 * @class Bind
 * @author Lucas S. Vieira
 */
class Bind {

  /**
   * Current bind values
   *
   * @var array
   */
  private values = [];

  /**
   * Set the value of a single bind variable
   *
   * Allowed value types for bind parameters are string, int,
   * double, bool and array. Arrays must not contain any other
   * than these types.
   *
   * @throws \Arango\Exception\ClientException
   *
   * @param string key
   * @param mixed value
   *
   * @return void
   */
  public function set(string key, value = null) -> void {
    Validation::validateValue(value);
    let this->values[key] = value;
  }

  /**
   * Get the value of a bind variable with a specific name
   *
   * @param string name
   *
   * @return mixed
   */
  public function get(string name) {
    if(!array_key_exists(name, this->values)){
      return null;
    }

    return this->values[name];
  }

  /**
   * Get the number of bind variables
   *
   * @return int
   */
  public function getCount() -> int {
    return count(this->values);
  }


  /**
   * Get all bind variables
   *
   * @return array
   */
  public function getAll() -> array {
    return this->values;
  }
}
