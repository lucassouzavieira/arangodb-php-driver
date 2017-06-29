namespace Arango\Document;

use Arango\Document\Document;
use Arango\Validation\Validation;

/**
 * Value object representing a single Edge document
 *
 * @package Arango/Document
 * @class Edge
 * @author Lucas S. Vieira
 */
class Edge extends Document {

  /**
   * The edge's from (might be null for new documents)
   *
   * @var mixed
   */
   protected from {
     get
   };

   /**
    * The edge's to (might be null for new documents)
    *
    * @var mixed
    */
   protected to {
     get
   };

   /**
    * Edge document indexes
    */
  const ENTRY_FROM = "_from";
  const ENTRY_TO = "_to";

  /**
   * Set the 'from' vertex document-handler
   *
   * TODO Discuss/ Review
   *
   * @param mixed from - From vertex
   *
   * @return Edge
   */
  public function setFrom(from) -> <Edge> {
    let this->from = from;
    return this;
  }

  /**
   * Set the 'to' vertex document-handler
   *
   * TODO Discuss/ Review
   *
   * @param mixed to - To vertex
   *
   * @return Edge
   */
  public function setTo(to) -> <Edge> {
    let this->to = to;
    return this;
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

      if(key == self::ENTRY_FROM) {
        this->setFrom(value);
        return;
      }

      if(key == self::ENTRY_TO) {
        this->setTo(value);
        return;
      }
    }

    if(!this->changed && (!isset(this->values[key]) || this->values[key] != value)) {
      let this->changed = true;
    }

    let this->values[key] = value;
  }

  /**
   * Get all documents attributes for insertion / update
   *
   * @return array - associative array with all documents attributes/values
   */
  public function getAllForInsertUpdate() -> array {
    var data = parent::getAllForInsertUpdate();

    let data["_from"] = this->from;
    let data["_to"] = this->to;

    return data;
  }
}
