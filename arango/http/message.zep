
namespace Arango\Http;

use Arango\Http\Contracts\Stream as StreamInterface;
use Arango\Http\Contracts\Message as MessageInterface;

/**
 * Message abstract class
 *
 * @since 1.0
 * @package Arango\Http
 * @author Lucas S. Vieira
 */
abstract class Message implements MessageInterface {

  /**
   * Http protocol version
   *
   * @var string
   */
  protected protocol = "1.1";

  /**
   * Headers store
   *
   * @var array
   */
  protected headers = [];

  /**
   * @see Arango\Http\Contracts\Message::getProtocolVersion()
   */
  public function getProtocolVersion() -> string {
     return this->protocol;
  }

  /**
   * @see Arango\Http\Contracts\Message::withProtocolVersion()
   */
  public function withProtocolVersion(string version) {
    var message;
    let message = clone this;
    let message->protocol = version;
    return message;
  }

  /**
   * @see Arango\Http\Contracts\Message::getHeaders()
   */
  public function getHeaders() -> array {
    return this->headers;
  }

  /**
   * @see Arango\Http\Contracts\Message::hasHeader()
   */
  public function hasHeader(string name) -> bool {
    return array_key_exists(strtolower(name), this->headers);
  }

  /**
   * @see Arango\Http\Contracts\Message::getHeader()
   */
  public function getHeader(string name) -> array {
    if(!this->hasHeader(name)) {
      return [];
    }

    string normalized;
    let normalized = strtolower(name);

    return [normalized: this->headers[normalized]];
  }

  /**
   * @see Arango\Http\Contracts\Message::getHeaderLine()
   */
  public function getHeaderLine(string name) -> string {
    var value;
    let value = this->getHeader(name);

    if(!count(value)) {
      return "";
    }

    return implode(",", value);
  }
}
