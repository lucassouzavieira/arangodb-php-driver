
namespace Arango\Handler;

use Arango\Http\Api;
use Arango\Http\Url;
use Arango\Http\Response;
use Arango\Connection\Options;
use Arango\Connection\Encoding;
use Arango\Connection\Connection;
use Arango\Collection\Collection;
use Arango\Exception\ServerException;

/**
 * A handler that manages collections
 * TODO Finish
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


  /**
   * Creates a new collection on the server
   *
   * This will add the collection on the server and return its id <br>
   * The id is mainly returned for backwards compatibility, but you should use the collection name for any reference to the collection.<br>
   * This will throw if the collection cannot be created <br>
   *
   * @throws Exception
   *
   * @param string $name A string with the collection name
   * @param array $options An array of options. Options are :
   *                          'type'            - 2 -> normal collection, 3 -> edge-collection
   *                          'waitForSync'     -  if set to true, then all removal operations will instantly be synchronised to disk / If this is not specified, then the collection's default sync behavior will be applied.
   *                          'journalSize'     -  journalSize value.
   *                          'isSystem'        -  false->user collection(default), true->system collection .
   *                          'isVolatile'      -  false->persistent collection(default), true->volatile (in-memory) collection .
   *                          'numberOfShards'  -  number of shards for the collection.
   *                          'shardKeys'       -  list of shard key attributes.
   *
   * @return mixed - id of collection created
   */
  public function create(string name, array options = []) -> int | string {
    var collection, params;

    let collection = new Collection(name);
    collection->setName(name);

    // Set defaults and options values to collection object
    let collection = this->setCollectionDefaults(collection);
    let collection = this->setCollectionValues(collection);

    var type;

    let type = collection->getType() ? : Collection::getDefaultType();

    let params = [
      Collection::ENTRY_NAME: collection->getName(),
      Collection::ENTRY_TYPE: type,
      Collection::ENTRY_WAIT_SYNC: collection->getWaitForSync(),
      Collection::ENTRY_JOURNAL_SIZE: collection->getJournalSize(),
      Collection::ENTRY_IS_SYSTEM: collection->getIsSystem(),
      Collection::ENTRY_IS_VOLATILE: collection->getIsVolatile(),
      Collection::ENTRY_KEY_OPTIONS: collection->getKeyOptions()
    ];

    // Set extra cluster attributes
    if(collection->getNumberOfShards()){
      let params[Collection::ENTRY_NUMBER_OF_SHARDS] = collection->getNumberOfShards();
    }

    if(is_array(collection->getShardKeys())){
      let params[Collection::ENTRY_SHARD_KEYS] = collection->getShardKeys();
    }

    var response, data;
    let response = this->getConnection()->post(Api::COLLECTION, Encoding::jsonWrapper(params));
    let data = response->toArray();

    collection->setId(data["id"]);
    return data["id"];
  }

  /**
   * Set defaults values for a collection object
   *
   * @param Collection collection - Collection object
   *
   * @return Collection
   */
  private function setCollectionDefaults(<Collection> collection) -> <Collection> {

    collection->setType(Collection::getDefaultType());
    collection->setWaitForSync(this->getConnectionOption(Options::WAIT_SYNC));
    collection->setJournalSize(this->getConnectionOption(Options::JOURNAL_SIZE));
    collection->setIsSystem(this->getConnectionOption(Options::IS_SYSTEM));
    collection->setIsVolatile(this->getConnectionOption(Options::IS_VOLATILE));

    return collection;
  }

  /**
   * Set options values for a collection object
   *
   * @param Collection collection - Collection object
   *
   * @return Collection
   */
  private function setCollectionValues(<Collection> collection, array options = []) -> <Collection> {
    if(isset(options["type"])) {
      collection->setType(options["type"]);
    }

    if(isset(options["waitForSync"])) {
      collection->setWaitForSync(options["waitForSync"]);
    }

    if(isset(options["journalSize"])) {
      collection->setJournalSize(options["journalSize"]);
    }

    if(isset(options["isSystem"])) {
      collection->setIsSystem(options["isSystem"]);
    }

    if(isset(options["isVolatile"])) {
      collection->setIsVolatile(options["isVolatile"]);
    }

    if(isset(options["numberOfShards"])) {
      collection->setNumberOfShards(options["numberOfShards"]);
    }

    if(isset(options["shardKeys"])) {
      collection->setShardKeys(options["shardKeys"]);
    }

    return collection;
  }

  /**
   * Check if a collection exists
   *
   * @throws Arango\Exception\ServerException | \Exception
   *
   * @param mixed collection - Collection ID as string or number
   *
   * @return boolean
   */
  public function has(collectionId) -> boolean {
    var exception;

    try {

      this->retrieveFromServer(this->getCollectionName(collectionId));

    } catch ServerException | \Exception, exception {

      if(exception->getCode() == 404) {
        return false;
      }

      throw exception;
    }

    return true;
  }

  /**
   * Get the number of documents in a collection
   *
   * @throws \Exception
   *
   * @param mixed collectionId - Collection ID as string or number
   *
   * @return int
   */
  private function count(collectionId) -> int {
    var url, response, data;

    let url = Url::buildUrl(Api::COLLECTION, [
      this->getCollectionName(collectionId),
      self::OPTION_COUNT
    ]);

    let response = this->getConnection()->get(url);
    let data = response->toArray();

    return (int) data[self::OPTION_COUNT];
  }

  /**
   * Get figures for a collection
   *
   * @throws \Exception
   *
   * @param mixed collectionId - Collection ID as string or number
   *
   * @return array
   */
  public function figures(collectionId) -> array {
    var url, response, data;

    let url = Url::buildUrl(Api::COLLECTION, [
      this->getCollectionName(collectionId),
      self::OPTION_FIGURES
    ]);

    let response = this->getConnection()->get(url);
    let data = response->toArray();

    return data[self::OPTION_FIGURES];
  }

  /**
   * Get collection from the server
   *
   * @throws \Exception
   *
   * @param mixed collectionId - Collection ID as string or number
   *
   * @return Collection
   */
  private function retrieveFromServer(collectionId) -> <Collection> {
    var url, response;

    let url = Url::buildUrl(Api::COLLECTION, [collectionId]);
    let response = this->getConnection()->get(url);

    return Collection::createFromArray(response->toArray());
  }

  /**
   * Get collection properties from the server
   *
   * @throws \Exception
   *
   * @param mixed collectionId - Collection ID as string or number
   *
   * @return Collection
   */
  public function getProperties(collectionId) -> <Collection> {
    var url, response;

    let url = Url::buildUrl(Api::COLLECTION, [
      this->getCollectionName(collectionId),
      self::OPTION_PROPERTIES
    ]);

    let response = this->getConnection()->get(url);

    return Collection::createFromArray(response->toArray());
  }

  /**
   * Calculates a checksum of the collection
   *
   * @throws \Exception
   *
   * @param mixed collectionId    - Collection ID as string or number
   * @param boolean withRevisions - Optional boolean wheter or not to include document revision ids in checksum calculation
   * @param boolean withData      - Optional boolean wheter or not to include document body data ids in checksum calculation
   *
   * @return array  - Contains keys "checksum" and "revision"
   */
  public function getChecksum(collectionId, boolean withRevisions = false, boolean withData = false) -> <Collection> {
    var url, response;

    let url = Url::buildUrl(Api::COLLECTION, [
      this->getCollectionName(collectionId),
      self::OPTION_CHECKSUM
    ]);

    let url = Url::appendParamsToUrl(url, [
      "withRevisions": withRevisions,
      "withData": withData
    ]);

    let response = this->getConnection()->get(url);

    return response->toArray();
  }

  /**
   * Returns the collection revision ID
   *
   * @throws \Exception
   *
   * @param mixed collectionId - Collection ID as string or number
   *
   * @return array
   */
  public function getRevision(collectionId) -> array {
    var url, response;

    let url = Url::buildUrl(Api::COLLECTION, [
      this->getCollectionName(collectionId),
      self::OPTION_REVISION
    ]);

    let response = this->getConnection()->get(url);

    return response->toArray();
  }

  /**
   * Get the information about an index in a collection
   *
   * @throws \Exception
   *
   * @param string collectionId - Collection ID as string
   * @param string indexId      - Index ID as string
   *
   * @return array
   */
  public function getIndex(string collectionId, string indexId) -> array {
    var url, response;

    let url = Url::buildUrl(Api::INDEX, [collectionId, indexId]);
    let response = this->getConnection()->get(url);

    return response->toArray();
  }

  /**
   * Get indexes of a collection
   *
   * @throws \Exception
   *
   * @param string collectionId - Collection ID as string or number
   *
   * @return array
   */
  public function getIndexes(collectionId) -> array {
    var url, response;

    let url = Url::buildUrl(Api::INDEX, [
      self::OPTION_COLLECTION: this->getCollectionName(collectionId)
    ]);

    let response = this->getConnection()->get(url);

    return response->toArray();
  }

  /**
   * Drop an index
   *
   * @throws \Exception
   *
   * @param string collectionId - Collection ID as string
   * @param string indexId      - Index ID as string
   *
   * @return boolean - always true, will throw an exception if an error
   */
  public function dropIndex(string collectionId, string indexId) -> boolean {
    var url;

    let url = Url::buildUrl(Api::INDEX, [
      this->getCollectionName(collectionId),
      indexId
    ]);

    this->getConnection()->delete(url);
    return true;
  }

  /**
   * Get a random document from the collection
   *
   * @throws \Exception - If document cannot be fetched from the server
   *
   * @param string collectionId - Collection ID as string
   *
   * @return Document
   */
  public function any(collectionId) -> void {

  }
 }
