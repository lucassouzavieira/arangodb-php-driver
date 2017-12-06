
namespace Arango\Http\Base;

use Arango\Http\Base\Message;
use Arango\Http\Contracts\Uri as UriInterface;
use Arango\Http\Contracts\Stream as StreamInterface;
use Arango\Http\Contracts\Request as RequestInterface;

/**
 * Request abstract class
 *
 * @since 1.0
 * @package Arango\Http\Base
 * @author Lucas S. Vieira
 */
abstract class Request extends Message implements RequestInterface {

  /**
   * @var Arango\Http\Contracts\Uri
   */
  protected uri;

  /**
   * @var string
   */
  protected method;

  /**
   * @var string
   */
  protected requestTarget;

  /**
   * @var array
   */
  protected allowedMethods = [
    "GET",
    "POST",
    "PUT",
    "PATCH",
    "HEAD",
    "OPTIONS",
    "TRACE",
    "DELETE",
    "CONNECT"
  ];

  /**
   * Request class init
   *
   * @param UriInterface|null       uri     The uri target of this Request
   * @param string                  method  The uri target of this Request
   * @param string|StreamInterface  body    The uri target of this Request
   * @param array                   uri     The uri target of this Request
   */
  public function __construct(<UriInterface> uri = null, string method = "GET", body = "php://memory", headers = [])
  {
  }
}
