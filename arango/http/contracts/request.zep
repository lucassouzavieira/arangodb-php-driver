
namespace Arango\Http\Contracts;

use Arango\Http\Contracts\Uri;
use Arango\Http\Contracts\Message;

/**
 * Representation of an outgoing, client-side request.
 *
 * @link http://www.php-fig.org/psr/psr-7/
 * @package Arango\Http\Contracts
 * @author Lucas S. Vieira
 */
interface Request extends Message {

  /**
   * Retrieves the message's request target.
   *
   * @return string
   */
  public function getRequestTarget() -> string;

  /**
   * Return an instance with the specific request-target.
   *
   * @param mixed requestTarget
   * @return static
   */
  public function withRequestTarget(requestTarget);

  /**
   * Retrieves the HTTP method of the request.
   *
   * @return string The request method
   */
  public function getMethod() -> string;

  /**
   * Return an instance with the provided HTTP method.
   *
   * @param string method Case-sensitive method
   * @return static
   * @throws \InvalidArgumentException for invalid HTTP methods
   */
  public function withMethod(string method);

  /**
   *  Retrieves the URI instance.
   *
   * @return Arango\Http\Contracts\Uri
   */
  public function getUri() -> <Uri>;

  /**
   * Returns an instance with the provided URI.
   *
   * @param Arango\Http\Contracts\Uri new request Uri to use
   * @param bool preserveHost Preserve the original state of host header
   * @return static
   */
  public function withUri(<Uri> uri, bool preserveHost = false);
}
