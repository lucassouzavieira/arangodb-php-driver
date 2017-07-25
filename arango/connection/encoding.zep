
namespace Arango\Connection;

use Arango\Exception\ClientException;

/**
 * Encoding class
 *
 * Assists in checking and validating string encoding
 *
 * @package Arango\Connection
 * @class Encoding
 * @author Lucas S. Vieira
 */
abstract class Encoding {

  /**
   * This function checks that the encoding of a string is utf.
   * It only checks for printable characters.
   *
   * @param string the data to check
   * @return boolean true if string is UTF-8, false if not
   */
  private static function detectUtf(string value) -> boolean {
    if(preg_match("//u", value)){
      return true;
    }

    return false;
  }

  /**
   * This function checks that the encoding of the keys and
   * values of the array are utf-8, recursively.
   * It will raise an exception if it encounters wrong encoded strings.
   *
   * @throws \Arango\Exception\ClientException
   * @param array $data the data to check
   * @return void
   */
  public static function checkEncoding(array data){
    var key;
    var value;

    for key, value in data {
      if(is_array(value)){
        self::checkEncoding(value);
      }

      if(function_exists("mb_detect_encoding")){
        if(is_string(key) && mb_detect_encoding(key, "UTF-8", true) == false){
          throw new ClientException("Only UTF-8 encoded keys allowed. Wrong encoding in key string: " . key);
        }

        if(is_string(value) && mb_detect_encoding(value, "UTF-8", true) == false){
          throw new ClientException("Only UTF-8 encoded values allowed. Wrong encoding in key string: " . value);
        }

        continue;
      }

      if(is_string(key) && self::detectUtf(key) == false){
        throw new ClientException("Only UTF-8 encoded keys allowed. Wrong encoding in key string: " . key);
      }

      if(is_string(value) && self::detectUtf(value) == false){
        throw new ClientException("Only UTF-8 encoded values allowed. Wrong encoding in key string: " . value);
      }
    }
  }

  /**
   * This is a json_encode() wrapper that also checks if the data is utf-8 conform.
   * internally it calls the check_encoding() method. If that method does not throw
   * an Exception, this method will happily return the json_encoded data.
   *
   * @throws Arango\Exception\ClientException
   *
   * @param array $data    the data to encode
   * @param mixed $options the options for the json_encode() call
   *
   * @return string the result of the json_encode
   */
  public static function jsonWrapper(array data, options = 0) -> string {
    self::checkEncoding(data);

    var response;

    if(empty(data)) {
      let response = json_encode(data, options | JSON_FORCE_OBJECT);

      return response;
    }

    let response = json_encode(data, options);
    return response;
  }
}
