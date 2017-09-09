
namespace Arango\Exception;

/**
 * Base exception class for specific Arango exceptions
 *
 * @package Arango/Exception
 * @class Exception
 * @author Lucas S. Vieira
 */
abstract class Exception extends \Exception {

  /**
   * @var boolean
   */
  protected static enableLogging = false;

  /**
   * Exception constructor
   *
   * @param string message
   * @param int code
   * @param \Throwable previous
   */
  public function __construct(string message = " ", int code = 0, <Throwable> previous = null) {
    if(self::enableLogging) {
      error_log(get_class(this) . " : " . message);
      error_log("Stack trace: ");

      var stack;
      let stack = explode(PHP_EOL, this->getTraceAsString());
      var message;

      for _, message in stack {
        error_log(" " . message);
      }

      parent::__construct(message, code, previous);
    }
  }

  /**
   * Turn on exception logging
   *
   * @return void
   */
  public static function enableLogging() -> void {
    let self::enableLogging = true;
  }

  /**
   * Turn off exception logging
   *
   * @return void
   */
  public static function disableLogging() -> void {
    let self::enableLogging = false;
  }
}
