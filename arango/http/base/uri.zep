
namespace Arango\Http\Base;

use Arango\Http\Contracts\Uri as UriInterface;

/**
 * Uri abstract class
 *
 * @since 1.0
 * @package Arango\Http\Base
 * @author Lucas S. Vieira
 */
abstract class Uri implements UriInterface {
  const SCHEME_HTTP = "http";
  const SCHEME_HTTPS = "https";

  /**
   * @var string
   */
  protected uri = null;

  /**
   * @var string
   */
  protected scheme = null;

  /**
   * @var string
   */
  protected host = null;

  /**
   * @var int
   */
  protected port = null;

  /**
   * @var string
   */
  protected username = null;

  /**
   * @var string
   */
  protected password = null;

  /**
   * @var string
   */
  protected path = null;

  /**
   * @var string
   */
  protected query = null;

  /**
   * @var array
   */
  protected values = [];
}
