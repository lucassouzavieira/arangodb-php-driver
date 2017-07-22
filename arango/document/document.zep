
namespace Arango\Document;

use Arango\Validation\Validation;
use Arango\Exception\ClientException;

/**
 * Value object representing a single collection-based document
 *
 * @package Arango/Document
 * @class Document
 * @author Lucas S. Vieira
 */
class Document implements \JsonSerializable, \Serializable {

  /**
   * The document id (might be null for new documents)
   *
   * @var string
   */
  protected id {
    get
  };

  /**
   * The document key (might be null for new documents)
   *
   * @var string
   */
  protected key {
    get
  };

  /**
   * The document revision (might be null for new documents)
   *
   * @var mixed
   */
  protected revision {
    get, set
  };

  /**
   * The document attributes as associative array with names and values
   *
   * @var mixed
   */
  protected values = [];

  /**
   * Flag to indicate whether document was changed locally
   */
  protected changed = false {
    get, set
  };

  /**
   * Flag to indicate whether document is a new document (never been saved to the server)
   */
  protected isNew = false {
    get, set
  };

  /**
   * An array, that defines which attributes should be treated as hidden.
   */
  protected hiddenAttributes = [] {
    get, set
  };

  /**
   * Flag to indicate whether hidden attributes should be ignored or included in returned data-sets
   */
  protected ignoreHiddenAttributes = false {
    get, set
  };

  /**
   * Document indexes
   */
  const ENTRY_ID = "id" ;
  const ENTRY_KEY = "_key" ;
  const ENTRY_REVISION = "_rev";
  const ENTRY_IS_NEW = "_isNew";
  const ENTRY_HIDDEN_ATTRIBUTES = "_hiddenAttributes" ;
  const ENTRY_IGNORE_HIDDEN_ATTRIBUTES = "_ignoreHiddenAttributes" ;

  const OPTION_WAIT_FOR_SYNC = "waitForSync";
  const OPTION_POLICY = "policy";
  const OPTION_KEEP_NULL = "keepNull";

  /**
   * Constructs an empty document
   *
   * @param array options - Initial options for document
   *
   * @return void
   */
  public function __construct(array options = null) {
    if(!is_null(options)){
      if(isset(options[self::ENTRY_HIDDEN_ATTRIBUTES])) {
        this->setHiddenAttributes(options[self::ENTRY_HIDDEN_ATTRIBUTES]);
      }

      if(isset(options[self::ENTRY_IGNORE_HIDDEN_ATTRIBUTES])) {
        this->setIgnoreHiddenAttributes(options[self::ENTRY_IGNORE_HIDDEN_ATTRIBUTES]);
      }

      if(isset(options[self::ENTRY_IS_NEW])) {
        this->setIsNew(options[self::ENTRY_IS_NEW]);
      }
    }
  }

  /**
   * Clone a document
   *
   * @magic
   *
   * @return void
   */
  public function __clone() {
    let this->id = null;
    let this->key = null;
    let this->revision = null;
  }

  /**
   * Get a string representation of the document
   *
   * TODO Review
   *
   * @magic
   *
   * @return string
   */
  public function __toString() -> string {
    return json_encode(this->values);
  }

  /**
   * Set a document attribute
   *
   * @throws \Arango\Exception\ClientException
   *
   * @magic
   * @param string key - Attribute name
   * @param mixed value - Value for attribute
   *
   * @return void
   */
  public function __set(string key, value){
    this->set(key, value);
  }

  /**
   * Get a document attribute
   *
   * @magic
   * @param string key - Attribute name
   *
   * @return mixed | null - Value of attribute, if exists. Return null otherwise
   */
  public function __get(string key){
    return this->get(key);
  }

  /**
   * Factory method to Construct a new document using values passed to populate it
   *
   * @param array values - Initial document values
   * @param array options - Initial options for document
   *
   * @return Document
   */
  public static function createFromArray(array values, array options = null) -> <Document> {
    var document;
    let document = new Document(options);

    var key, value;
    for key, value in values {
      document->set(key, value);
    }

    document->setChanged(true);
    return document;
  }

  /**
   * Set a document attribute
   *
   * @throws \Arango\Exception\ClientException
   *
   * @param string key - Attribute name
   * @param mixed value - Value for attribute
   *
   * @return void
   */
  public function set(string key, value) -> void {
    var underscore = "_";
    Validation::validateValue(value);

    if(key[0] == underscore){
      if(key == self::ENTRY_ID) {
        this->setInternalId(value);
        return;
      }

      if(key == self::ENTRY_KEY) {
        this->setInternalKey(value);
        return;
      }

      if(key == self::ENTRY_REVISION) {
        this->setRevision(value);
        return;
      }

      if(key == self::ENTRY_IS_NEW) {
        this->setIsNew(value);
        return;
      }
    }

    if(!this->changed && (!isset(this->values[key]) || this->values[key] != value)) {
      let this->changed = true;
    }

    let this->values[key] = value;
  }

  /**
   * Get a document attribute
   *
   * @param string key - Attribute name
   *
   * @return mixed | null - Value of attribute, if exists. Return null otherwise
   */
  public function get(string key) {
    if(isset(this->values[key])){
      return this->values[key];
    }

    return null;
  }

  /**
   * Get all documents attributes
   *
   * @param mixed $options - optional, array of options for the getAll function, or the boolean value for $includeInternals
   *                       Options are :
   *                       '_includeInternals' - true to include the internal attributes. Defaults to false
   *                       '_ignoreHiddenAttributes' - true to show hidden attributes. Defaults to false
   *
   * @return array - associative array with all documents attributes/values
   */
  public function getAll(array options = null) -> array {
    boolean includeInternals = false;
    boolean ignoreHiddenAttributes = true;
    var hiddenAttributes = this->hiddenAttributes;

    if(!is_null(options)) {
      if(isset(options["_includeInternals"])) {
        let includeInternals = (boolean) options["_includeInternals"];
      }

      if(isset(options["_ignoreHiddenAttributes"])) {
        let ignoreHiddenAttributes = (boolean) options["_ignoreHiddenAttributes"];
      }

      if(isset(options[self::ENTRY_HIDDEN_ATTRIBUTES])) {
        let hiddenAttributes = options[self::ENTRY_HIDDEN_ATTRIBUTES];
      }
    }

    var data = this->values;
    var nonInternals = ["changed", "values", self::ENTRY_HIDDEN_ATTRIBUTES];

    if(includeInternals) {
      var key, value, underscore = "_";

      for key, value in data {
        if(key[0] == underscore && strpos(key, underscore) != 0 && !in_array(key, nonInternals, true)){
          let data[key] = value;
        }
      }
    }

    if(!ignoreHiddenAttributes) {
      let data = this->filterHiddenAttributes(data, hiddenAttributes);
    }

    if(!is_null(this->key)) {
      let data["_key"] = this->key;
    }

    return data;
  }

  /**
   * Get the collection id
   *
   * Collection ids are generated on the server only. Collection ids are numeric but might be
   * bigger than PHP_INT_MAX. To reliably store a collection id elsewhere, a PHP string should be used
   *
   * @return string | null - Collection id, if exists. Return null otherwise
   */
  public function getCollectionId() -> string | null {
    var data;

    if(!is_null(this->id)){
      let data = explode("/", this->id);
      return data[1];
    }

    return null;
  }

  /**
   * Get all documents attributes for insertion / update
   *
   * @return array - associative array with all documents attributes/values
   */
  public function getAllForInsertUpdate() -> array {
    array data = [];

    var key, value;

    for key, value in this->values {
      if(key == "_id" || key == "_rev") {
        continue;
      }

      if(key == "_key" && value == null){
        continue;
      }

      let data[key] = value;
    }

    if(!is_null(this->key)){
      let data["_key"] = this->key;
    }

    return data;
  }

  /**
   * Returns the attributes with the hidden ones removed
   *
   * @param array attributes
   * @param array hiddenAttributes
   *
   * @return array - Attributes array
   */
  private function filterHiddenAttributes(array attributes, array hiddenAttributes = null) -> array {
    let hiddenAttributes = hiddenAttributes != null ? hiddenAttributes : this->getHiddenAttributes();

    if(count(hiddenAttributes) > 0){
      var key;

      for key, _ in hiddenAttributes {
        if(isset(attributes[key])){
          unset(attributes[key]);
        }
      }
    }

    unset(attributes[self::ENTRY_HIDDEN_ATTRIBUTES]);
    return attributes;
  }

  /**
   * Set the internal document id
   *
   * This will throw if the id of an existing document gets updated to some other id
   *
   * @throws \Arango\Exception\ClientException
   * @param string id - Internal document id
   *
   * @return void
   */
  public function setInternalId(string id) -> void {
    if(!is_null(this->id) && this->id != id) {
      throw new ClientException("Should not update the id of an existing document");
    }

    if(!preg_match("/^[a-zA-Z0-9_-]{1,64}\/[a-zA-Z0-9_:.@\-()+,=;$!*\'%]{1,254}$/", id)){
      throw new ClientException("Invalid format for document id");
    }

    let this->id = id;
  }

  /**
   * Set the internal document key
   *
   * This will throw if the key of an existing document gets updated to some other key
   *
   * @throws \Arango\Exception\ClientException
   * @param string key - Internal document key
   *
   * @return void
   */
  public function setInternalKey(string key) -> void {
    if(!is_null(this->key) && this->key != key) {
      throw new ClientException("Should not update the key of an existing document");
    }

    if(!preg_match("/^[a-zA-Z0-9_:.@\-()+,=;$!*\'%]{1,254}$/", key)){
      throw new ClientException("Invalid format for document key");
    }

    let this->key = key;
  }

  /**
   * Serialize instance as JSON document
   *
   * @return array
   */
  public function jsonSerialize() -> array {
    return this->getAll([
      "_includeInternals" : false,
      "_ignoreHiddenAttributes" : false
    ]);
  }

  /**
   * Returns an array representation for document
   *
   * @return array
   */
  public function toArray() -> array {
    return this->getAll([
      "_includeInternals": false,
      "_ignoreHiddenAttributes": true
    ]);
  }

  /**
   * Serialize instance
   *
   * @return string
   */
  public function serialize() -> string {
    return serialize(this->getAll());
  }

  /**
   * Unserialize instance
   *
   * @return void
   */
  public function unserialize(string serialized) -> void {
    var data = unserialize(serialized);

    if(isset(data["_key"])){
      let this->key = data["_key"];
      unset(data["_key"]);
    }

    let this->values = data;
  }
}
