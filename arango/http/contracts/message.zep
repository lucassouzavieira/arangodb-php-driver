
namespace Arango\Http\Contracts;

use Arango\Http\Contracts\Stream;

/**
 * PSR-7 Message interface
 *
 * @link http://www.php-fig.org/psr/psr-7/
 * @package Arango\Http\Contracts
 * @author Lucas S. Vieira
 */
interface Message {

  /**
   * Retrieves the HTTP protocol version as a string.
   *
   * @return string HTTP protocol version
   */
  public function getProtocolVersion() -> string;

  /**
   * Returns a instance with the specified HTTP protocol version.
   *
   * @param string HTTP protocol version
   * @return static
   */
  public function withProtocolVersion(string version);

  /**
   * Retrieves all message header values.
   *
   * @return string[][] An associative array with message headers
   */
  public function getHeaders() -> array;

  /**
   * Checks if a header exists by the given case-insensitive name.
   *
   * @return bool Returns true if any header names match the given header name. Return false if no matching
   */
  public function hasHeader(string name) -> bool;

  /**
   * Retrieves a message header value by the given case-insensitive name.
   *
   * @param string name case-insensitive header field name
   * @return string[] An array of strings values as provided for given header.
   */
  public function getHeader(string name) -> array;

  /**
   * Retrieves a comma-separated string of the values for a single header.
   *
   * @param string name
   * @return string A string of values as provided for given header concatenated together using a comma.
   */
  public function getHeaderLine(string name) -> string;

  /**
   * Return an instance with the provided value replacing the specified header.
   *
   * @param string name
   * @param string|string[] value header values
   * @return static
   * @throws \InvalidArgumentException for invalid header names or values
   */
  public function withHeader(string name, value);

  /**
   * Return an instance with the specified header appended with the given value.
   *
   * @param string name
   * @param string|string[] value header values
   * @return static
   * @throws \InvalidArgumentException for invalid header names or values
   */
  public function withAddedHeader(string name, value);

  /**
   * Return an instance without the specified header.
   *
   * @param string name
   * @return static
   */
  public function withoutHeader(string name);

  /**
   * Gets the body of the message.
   *
   * @return Arango\Http\Contracts\Stream The body as a Stream
   */
  public function getBody() -> <Stream>;

  /**
   * Return an instance with the specified message body.
   *
   * @param Arango\Http\Contracts\Stream body
   * @return static
   * @throws \InvalidArgumentException When body is not valid
   */
  public function withBody(<Stream> body);
}
