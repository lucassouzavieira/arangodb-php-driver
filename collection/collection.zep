
namespace ArangoDB\Collection;

use ArangoDB\Exception\ClientException;

/**
* Collection class
*
* Represents a Collection in ArangoDB Database
*
* @package ArangoDB/Collection
* @class Collection
* @author Lucas S. Vieira
*/
class Collection implements \JsonSerializable {

  /**
  * Collection id (might be NULL for new collections)
  *
  * @var mixed - Collection id
  */
  private id;

  /**
  * Collection name (might be NULL for new collections)
  *
  * @var string - Collection name
  */
  private name;

  /**
  * Collection type (might be NULL for new collections)
  *
  * @var int - Collection type
  */
  private type;

  /**
  * Collection waitForSync value (might be NULL for new collections)
  *
  * @var boolean - waitForSync value
  */
  private waitForSync;

  /**
  * Collection journalSize value (might be NULL for new collections)
  *
  * @var int - journalSize value
  */
  private journalSize;

  /**
  * Collection isSystem value (might be NULL for new collections)
  *
  * @var boolean - isSystem value
  */
  private isSystem;

  /**
  * Collection isVolatile value (might be NULL for new collections)
  *
  * @var boolean - isVolatile value
  */
  private isVolatile;

  /**
  * Collection numberOfShards value (might be NULL for new collections)
  *
  * @var int - numberOfShards value
  */
  private numberOfShards;

  /**
  * Collection shardKeys value (might be NULL for new collections)
  *
  * @var array - shardKeys value
  */
  private shardKeys;

  /**
  * Collection status value (might be NULL for new collections)
  *
  * @var int - status value
  */
  private status;

  /**
  * Collection keyOptions value (might be NULL for new collections)
  *
  * @var array - keyOptions value
  */
  private keyOptions;


  /**
   * Collection indexes
   */
  const ENTRY_ID = "id";
  const ENTRY_NAME = "name";
  const ENTRY_TYPE = "type";
  const ENTRY_WAIT_SYNC = "waitForSync";
  const ENTRY_JOURNAL_SIZE = "journalSize";
  const ENTRY_STATUS = "status";
  const ENTRY_KEY_OPTIONS = "keyOptions";
  const ENTRY_IS_SYSTEM = "isSystem";
  const ENTRY_IS_VOLATILE = "isVolatile";
  const ENTRY_NUMBER_OF_SHARDS = "numberOfShards";
  const ENTRY_SHARD_KEYS = "shardKeys";

  const OPTION_PROPERTIES = "properties";

  const TYPE_DOCUMENT = 2;
  const TYPE_EDGE = 3;

  const STATUS_NEW_BORN = 1;
  const STATUS_UNLOADED = 2;
  const STATUS_LOADED = 3;
  const STATUS_BEING_LOADED = 4;
  const STATUS_DELETED = 5;

  /**
   * Construct a new collection representation
   *
   * @throws ClientException if name has lenght equals 0
   * @param string name
   * @return void
   */
  public function __construct(string name) {
    this->setName(name);
  }

  /**
   * Clone a collection instance
   *
   * @magic
   * @return void
   */
  public function __clone()
  {
    let this->id = null;
    let this->name = null;
    let this->waitForSync = null;
    let this->journalSize = null;
    let this->isSystem = null;
    let this->isVolatile = null;
    let this->numberOfShards = null;
    let this->shardKeys = null;
  }

  /**
   * Get all collection attributes
   *
   * @return array
   */
  public function getAll() -> array {
    array attributes;

    let attributes = [
      self::ENTRY_ID : this->id,
      self::ENTRY_NAME : this->name,
      self::ENTRY_WAIT_SYNC : this->waitForSync,
      self::ENTRY_IS_SYSTEM : this->isSystem,
      self::ENTRY_IS_VOLATILE : this->isVolatile,
      self::ENTRY_TYPE : this->type,
      self::ENTRY_STATUS : this->status,
      self::ENTRY_KEY_OPTIONS : this->keyOptions
    ];

    if(!is_null(this->numberOfShards)){
      array numberOfShards;

      let numberOfShards = [
        self::ENTRY_NUMBER_OF_SHARDS : this->numberOfShards
      ];

      let attributes[] = numberOfShards;
    }

    if(is_array(this->shardKeys)){
      array shardKeys;

      let shardKeys = [
        self::ENTRY_SHARD_KEYS : this->shardKeys
      ];

      let attributes[] = shardKeys;
    }

    return attributes;
  }

  /**
   * Serialize instance as JSON document
   *
   * @return array
   */
  public function jsonSerialize() {
    return this->getAll();
  }

  /**
   * ID setter
   *
   * @param int id
   * @return void
   */
  public function setId(int id) -> void {
    let this->id = id;
  }

  /**
   * ID getter
   *
   * @return int | null
   */
  public function getId() {
    return this->id;
  }

  /**
   * Set the collection name
   *
   * @throws ClientException if name has lenght equals 0
   * @param string name
   * @return void
   */
  public function setName(string name) -> void{
    if(strlen(name) > 0){
      let this->name = name;
      return;
    }

    throw new ClientException("Invalid string for a collection name");
  }

  /**
   * Name getter
   *
   * @return string | null
   */
  public function getName() {
    return this->name;
  }

  /**
   * Type setter
   *
   * @param int tyoe
   * @return void
   */
  public function setType(int type) -> void {
    let this->type = type;
  }

  /**
   * Type getter
   *
   * @return int | null
   */
  public function getType() {
    return this->type;
  }

  /**
   * waitForSync setter
   *
   * @param boolean waitForSync
   * @return void
   */
  public function setWaitForSync(boolean waitForSync) -> void {
    let this->waitForSync = waitForSync;
  }

  /**
   * waitForSync getter
   *
   * @return boolean | null
   */
  public function getWaitForSync() {
    return this->waitForSync;
  }

  /**
   * journalSize setter
   *
   * @param int journalSize
   * @return void
   */
  public function setJournalSize(int journalSize) -> void {
    let this->journalSize = journalSize;
  }

  /**
   * journalSize getter
   *
   * @return int | null
   */
  public function getJournalSize() {
    return this->journalSize;
  }

  /**
   * isSystem setter
   *
   * @param boolean isSystem
   * @return void
   */
  public function setIsSystem(boolean isSystem) -> void {
    let this->isSystem = isSystem;
  }

  /**
   * isSystem getter
   *
   * @return boolean | null
   */
  public function getIsSystem() {
    return this->isSystem;
  }

  /**
   * isVolatile setter
   *
   * @param boolean isVolatile
   * @return void
   */
  public function setIsVolatile(boolean isVolatile) -> void {
    let this->isVolatile = isVolatile;
  }

  /**
   * isVolatile getter
   *
   * @return boolean | null
   */
  public function getIsVolatile() {
    return this->isVolatile;
  }

  /**
   * numberOfShards setter
   *
   * @param int numberOfShards
   * @return void
   */
  public function setNumberOfShards(int numberOfShards) -> void {
    let this->numberOfShards = numberOfShards;
  }

  /**
   * numberOfShards getter
   *
   * @return int | null
   */
  public function getNumberOfShards() {
    return this->numberOfShards;
  }

  /**
   * shardKeys setter
   *
   * @param array shardKeys
   * @return void
   */
  public function setShardKeys(array shardKeys) -> void {
    let this->shardKeys = shardKeys;
  }

  /**
   * shardKeys getter
   *
   * @return array | null
   */
  public function getShardKeys() {
    return this->shardKeys;
  }

  /**
   * status setter
   *
   * @param int shardKeys
   * @return void
   */
  public function setStatus(int status) -> void {
    let this->status = status;
  }

  /**
   * status getter
   *
   * @return int | null
   */
  public function getStatus() {
    return this->status;
  }

  /**
   * keyOptions setter
   *
   * @param array keyOptions
   * @return void
   */
  public function setKeyOptions(array keyOptions) -> void {
    let this->keyOptions = keyOptions;
  }

  /**
   * keyOptions getter
   *
   * @return array | null
   */
  public function getKeyOptions() {
    return this->keyOptions;
  }

}
