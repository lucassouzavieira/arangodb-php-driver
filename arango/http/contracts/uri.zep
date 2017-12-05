
namespace Arango\Http\Contracts;

/**
 * Value object representing a URI.
 *
 * @link http://www.php-fig.org/psr/psr-7/
 * @link http://tools.ietf.org/html/rfc3986 (the URI specification)
 * @package Arango\Http\Contracts
 * @author Lucas S. Vieira
 */
interface Uri {

  /*
   * Return the string representation as a URI reference.
   *
   * @see http://tools.ietf.org/html/rfc3986#section-4.1
   * @see http://php.net/manual/en/language.oop5.magic.php#object.tostring
   * @return string
   */
  public function __toString();

  /**
   * Retrieve the scheme component of the URI.
   *
   * @see https://tools.ietf.org/html/rfc3986#section-3.1
   * @return string The URI scheme
   */
  public function getScheme() -> string;

  /**
   * Retrieve the authority component of the URI.
   *
   * @see https://tools.ietf.org/html/rfc3986#section-3.2
   * @return string The URI authority, in "[user-info@]host[:port]" format.
   */
  public function getAuthority() -> string;

  /**
   * Retrieve the user information component of the URI.
   *
   * @return string The URI user information in "username[:password]" format
   */
  public function getUserInfo() -> string;

  /**
   * Retrieve the host component of the URI.
   *
   * @see https://tools.ietf.org/html/rfc3986#section-3.2.2
   * @return string The URI host
   */
  public function getHost() -> string;

  /**
   * Retrieve the port component of the URI.
   *
   * @return int|null The URI port
   */
  public function getPort() -> int | null;

  /**
   * Retrieve the path component of the URI.
   *
   * @see https://tools.ietf.org/html/rfc3986#section-2
   * @see https://tools.ietf.org/html/rfc3986#section-3.3
   * @return string The URI path
   */
  public function getPath() -> string;

  /**
  * Retrieve the query string of the URI.
  *
  * @see https://tools.ietf.org/html/rfc3986#section-2
  * @see https://tools.ietf.org/html/rfc3986#section-3.4
  * @return string The URI query string
  */
  public function getQuery() -> string;

  /**
  * Retrieve the fragment component of the URI.
  *
  * @see https://tools.ietf.org/html/rfc3986#section-2
  * @see https://tools.ietf.org/html/rfc3986#section-3.5
  * @return string The URI fragment
  */
  public function getFragment() -> string;

  /**
   * Return an instance with the specified scheme.
   *
   * @param string scheme The scheme to use.
   * @return static A new instance with the specified scheme
   * @throws \InvalidArgumentException for invalid or unsupported schemes.
   */
  public function withScheme(string scheme);

  /**
   * Return an instance with the specified user information.
   *
   * @param string user The user name.
   * @param string|null password The password associated with user.
   * @return static A new instance with the specified user information
   */
  public function withUserInfo(string user, string password = null);

  /**
   * Return an instance with the specified host.
   *
   * @param string host The host to use.
   * @return static A new instance with the specified host
   * @throws \InvalidArgumentException for invalids hostnames.
   */
  public function withHost(string host);

  /**
   * Return an instance with the specified port.
   *
   * @param int|null port The port to use.
   * @return static A new instance with the specified port
   * @throws \InvalidArgumentException for invalid ports.
   */
  public function withPort(int port = null);

  /**
   * Return an instance with the specified path.
   *
   * @param string path The path to use.
   * @return static A new instance with the specified path
   * @throws \InvalidArgumentException for invalid paths.
   */
  public function withPath(string path);

  /**
   * Return an instance with the specified query string.
   *
   * @param string query The query string to use.
   * @return static A new instance with the specified query string
   * @throws \InvalidArgumentException for invalid query strings.
   */
  public function withQuery(string query);

  /**
   * Return an instance with the specified fragment.
   *
   * @param string fragment The fragment to use.
   * @return static A new instance with the specified fragment
   */
  public function withFragment(string fragment);
}
