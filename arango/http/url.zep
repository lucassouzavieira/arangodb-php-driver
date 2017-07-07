
namespace Arango\Http;

/**
 * Url Helper class
 *
 * @package Arango/Http
 * @class Url
 * @abstract
 * @author Lucas S. Vieira
 */
abstract class Url {

  /**
   * Get the document Id from a location header
   *
   * @param string location - HTTP response location header
   *
   * @return string | null - Document id parsed or null if location is not valid
   */
  public static function getDocumentIdFromLocation(string location) -> string | null {
    var parts, collection, id;
    let parts = explode("/", location);

    if(strpos(location, "/_db/") == 0) {
      // The location is something like /_db/<dbname>/_api/document/<collection>/<key>
      if(isset(parts[4]) && isset(parts[5])){
        let collection = parts[4];
        let id = parts[5];
      }
    }

    if(strpos(location, "/_api/") == 0) {
      // Then, the location is something like /_api/document/<collection>/<key>
      if(isset(parts[2]) && isset(parts[3])){
        let collection = parts[2];
        let id = parts[3];
      }
    }

    if(!is_null(collection) && !is_null(id)) {
      if(is_string(id)){
        let id = urldecode(id);
      }

      return collection . "/" . id;
    }

    return null;
  }

  /**
   * Construct a URL from a base URL and additional parts, separated with "/" each
   *
   * @param string url  - Base URL
   * @param array parts - URL parts to append
   *
   * @return string     - Assembled URL
   */
  public static function buildUrl(string url, array parts = []) -> string {
    var baseUrl;

    let baseUrl = url;

    var part;
    for _, part in parts {
      if(strpos(part, "/") != false){
        let part = explode("/", part);
      }

      let baseUrl = baseUrl . "/" . urlencode(part);
    }

    return baseUrl;
  }

  /**
   * Append parameters to a URL.
   * Parameters values will be URL-encoded
   *
   * @param string url    - Base URL
   * @param array params  - An array of parameters
   *
   * @return string
   */
  public static function appendParamsToUrl(string url, array params) -> string {
    var key, value;

    for key, value in params {
      if(is_bool(value)){
        let value = self::getBoolString(value);
      }
    }

    return url . "?" . http_build_query(params);
  }

  /**
   * Get a boolean string from an value
   *
   * @param mixed value
   *
   * @return string - "true" if value evaluates to true, "false" otherwise
   */
  private static function getBoolString(value) -> string {
    return value ? "true" : "false";
  }
}
