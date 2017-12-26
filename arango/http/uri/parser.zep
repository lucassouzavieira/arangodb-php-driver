
namespace Arango\Http\Uri;

/**
 * Uri parser
 *
 * @since 1.0
 * @package Arango\Http\Uri
 * @author Lucas S. Vieira
 */
abstract class Parser {

  /**
   * Sub-delimeters used in query strings and fragments
   */
  const SUB_DELIMS = "!\$&\'\(\)\*\+,;=";

  /**
   * unreserved chars used in paths, query strings and fragments
   */
  const UNRESERVED = "a-zA-Z0-9_\-\.~";

  /**
   * Build a query from array
   *
   * @param array params The array of key => values to return as query string
   * @return string
   */
  public static function buildQuery(array params) -> string {
    return urlencode(http_build_query(params, "", "&"));
  }

  /**
   * UTF-8 for parse_url() function
   *
   * @see http://php.net/manual/en/function.parse-url.php
   * @param string params URL to parse
   * @return array|bool Associative array or false to badly URLs
   */
  public static function parseUrl(string url) {
    var result, entities, replacements;

    let result = false;
    let entities = ["%21", "%2A", "%27", "%28", "%29", "%3B", "%3A", "%40", "%26", "%3D", "%24", "%2C", "%2F", "%3F", "%23", "%5B", "%5D"];
    let replacements  = ['!', '*', "'", "(", ")", ";", ":", "@", "&", "=", "$", ",", "/", "?", "#", "[", "]"];

    var encodedUrl, encodedParts;
    let encodedUrl = str_replace(entities, replacements, urlencode(url));

    if(encodedParts) {
      var key, value;

      for key, value in encodedParts {
        let result[key] = urldecode(str_replace(replacements, entities, value));
      }
    }

    return result;
  }
}
