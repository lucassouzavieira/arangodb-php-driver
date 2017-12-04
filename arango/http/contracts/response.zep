
namespace Arango\Http\Contracts;

use Arango\Http\Contracts\Message;

/**
 * Representation of an outgoing, server-side response.
 *
 * @link http://www.php-fig.org/psr/psr-7/
 * @package Arango\Http\Contracts
 * @author Lucas S. Vieira
 */
interface Response extends Message {

  /**
   * Gets the response status code
   *
   * @return int Status code
   */
  public function getStatusCode() -> int;

  /**
   * Return an instance with the specified status code and, optionally, reason phrase.
   *
   * @param int code The 3-digit integer result code to set
   * @param string reasonPhrase The reason phrase to use with provided status code.
   * @return static
   * @throws \InvalidArgumentException For invalid status code arguments
   */
  public function withStatus(int code, string reasonPhrase = " ");

  /**
   * Gets the response reason phrase associated with the status code.
   *
   * @return string Reason phrase
   */
  public function getReasonPhrase() -> string;
}
