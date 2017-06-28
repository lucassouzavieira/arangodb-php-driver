
namespace Arango\Document;

use Arango\Validation\Validation;

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
  protected id;

  /**
   * The document key (might be null for new documents)
   *
   * @var string
   */
  protected key;

  /**
   * The document revision (might be null for new documents)
   *
   * @var mixed
   */
  protected revision;

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
        // this->setHiddenAttributes(options[self::ENTRY_HIDDEN_ATTRIBUTES]);
      }

      if(isset(options[self::ENTRY_IGNORE_HIDDEN_ATTRIBUTES])) {
        // this->setHiddenAttributes(options[self::ENTRY_IGNORE_HIDDEN_ATTRIBUTES]);
      }

      if(isset(options[self::ENTRY_IS_NEW])) {
        // this->setHiddenAttributes(options[self::ENTRY_IS_NEW]);
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

    // document->setChanged(true);
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
        // this->setInternalId(value);
        return;
      }

      if(key == self::ENTRY_KEY) {
        // this->setInternalKey(value);
        return;
      }

      if(key == self::ENTRY_REVISION) {
        // this->setRevision(value);
        return;
      }

      if(key == self::ENTRY_IS_NEW) {
        // this->setIsNew(value);
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
   * Serialize instance as JSON document
   *
   * TODO implements
   *
   * @return array
   */
  public function jsonSerialize() -> array {
    return [];
  }

  /**
   * Serialize instance
   *
   * TODO implements
   *
   * @return string
   */
  public function serialize() -> string {
    return "String";
  }

  /**
   * Unserialize instance
   *
   * TODO implements
   *
   * @return void
   */
  public function unserialize(string serialized) -> void {

  }
}
