
namespace Arango\Handler;

/**
 * A handler that manages edges
 *
 * @package Arango/Handler
 * @class CollectionHandler
 * @author Lucas S. Vieira
 */
class CollectionHandler extends Handler {

  /**
   * Class indexes
   */
  const ENTRY_DOCUMENTS = "documents";
  const OPTION_COLLECTION = "collection";
  const OPTION_EXAMPLE = "example";
  const OPTION_NEW_VALUE = "newValue";
  const OPTION_CREATE_COLLECTION = "createCollection";
  const OPTION_ATTRIBUTE = "attribute";
  const OPTION_KEYS = "keys";
  const OPTION_LEFT = "left";
  const OPTION_RIGHT = "right";
  const OPTION_LATITUDE = "latitude";
  const OPTION_LONGITUDE = "longitude";
  const OPTION_DISTANCE = "distance";
  const OPTION_RADIUS = "radius";
  const OPTION_SKIP = "skip";
  const OPTION_INDEX = "index";
  const OPTION_LIMIT = "limit";
  const OPTION_FIELDS = "fields";
  const OPTION_UNIQUE = "unique";
  const OPTION_TYPE = "type";
  const OPTION_SIZE = "size";
  const OPTION_GEO_INDEX = "geo";
  const OPTION_GEO_JSON = "geoJson";
  const OPTION_IGNORE_NULL = "ignoreNull";
  const OPTION_CONSTRAINT = "constraint";
  const OPTION_HASH_INDEX = "hash";
  const OPTION_FULLTEXT_INDEX = "fulltext";
  const OPTION_MIN_LENGHT = "minLenght";
  const OPTION_SKIPLIST_INDEX = "skiplist";
  const OPTION_PERSISTENT_LENGHT = "persistent";
  const OPTION_SPARSE = "sparse";
  const OPTION_COUNT = "count";
  const OPTION_QUERY = "query";
  const OPTION_CHECKSUM = "checksum";
  const OPTION_REVISION = "revision";
  const OPTION_PROPERTIES = "properties";
  const OPTION_FIGURES = "figures";
  const OPTION_LOAD = "load";
  const OPTION_UNLOAD = "unload";
  const OPTION_TRUNCATE = "truncate";
  const OPTION_RENAME = "rename";
  const OPTION_EXCLUDE_SYSTEM = "excludeSystem";
}
