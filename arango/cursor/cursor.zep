
namespace Arango\Cursor;

use Arango\Connection\Connection;
use Arango\Http\Url;
use Arango\Document\Document;
use Arango\Document\Edge;
use Arango\Exception\ClientException;

/**
 * Provides access to the results of an AQL query or another statement
 * The cursor might not contain all results in the beginning
 *
 * If the result set is too big to be transferred in one go, the
 * cursor might issue additional HTTP requests to fetch the
 * remaining results from the server.
 *
 * @package Arango/Cursor
 * @class Cursor
 * @author Lucas S. Vieira
 */
class Cursor implements \Iterator {

  /**
   * The connection object
   *
   * @var Connection
   */
  private connection;

  /**
   * Cursor options
   *
   * @var array
   */
  private options;

  /**
   * Result data
   *
   * @var array
   */
  private data;

  /**
   * Result set
   *
   * @var array
   */
  private result;

  /**
   * If server has more results
   *
   * @var boolean
   */
  private hasMore;

  /**
   * Cursor Id - might be null if Cursor does not have an id
   *
   * @var mixed
   */
  private id {
    get
  };

  /**
   * Current position in result set iteration (zero-based)
   *
   * @var int
   */
  private position;

  /**
   * Total length of result set (in number of documents)
   *
   * @var int
   */
  private length;

  /**
   * Full count of the result set (ignoring the outermost LIMIT)
   *
   * @var int
   */
  private fullCount {
    get
  };

  /**
   * Extra data (statistics) returned from the statement
   *
   * @var array
   */
  private extra {
    get
  };

  /**
   * Number of HTTP calls that were made to build the cursor result
   *
   * @var array
   */
  private fetches = 1 {
    get
  };

  /**
   * Whether or not the query result was served from the AQL query result cache
   *
   * @var boolean
   */
  private cached {
    get
  };

  /**
   * Results entries for class parameters
   */
  const ENTRY_ID =  "id";
  const ENTRY_HAS_MORE = "hasMore";
  const ENTRY_RESULT = "result";
  const ENTRY_EXTRA = "extra";
  const ENTRY_STATS = "stats";
  const ENTRY_COUNT = "fullCount";
  const ENTRY_CACHE = "cache";
  const ENTRY_CACHED = "cached";
  const ENTRY_SANITIZE = "_sanitize";
  const ENTRY_FLAT = "_flat";
  const ENTRY_TYPE = "objectType";
  const ENTRY_BASE_URL = "baseurl";

  /**
   * Initialise the cursor with the first results and some metadata
   *
   * @param Connection connection - connection to be used
   * @param array data -  initial result data as returned by the server
   * @param array options - cursor options
   *
   * @throws \Arango\Exception\ClientException
   */
  public function __construct(<Connection> connection, array data, array options) {
    let this->connection = connection;
    let this->data = data;
    let this->id = null;
    let this->extra = [];
    let this->cached = false;

    if(isset(data[self::ENTRY_ID])){
      let this->id = data[self::ENTRY_ID];
    }

    if(isset(data[self::ENTRY_EXTRA])){
      let this->extra = data[self::ENTRY_EXTRA];

      if(isset(this->extra[self::ENTRY_STATS][self::ENTRY_COUNT])){
        let this->fullCount = this->extra[self::ENTRY_STATS][self::ENTRY_COUNT];
      }
    }

    if(isset(data[self::ENTRY_CACHED])){
      let this->cached = data[self::ENTRY_CACHED];
    }

    if(!isset(data[self::ENTRY_HAS_MORE])){
      throw new ClientException("'hasMore' attribute missing");
    }

    let this->hasMore = (boolean) data[self::ENTRY_HAS_MORE];

    let options["_isNew"] = false;

    let this->options = options;
    let this->result = [];

    // this->add((array) data[self::ENTRY_RESULT]);
    this->updateLenght();
    this->rewind();
  }

  /**
   * Create an array of results from the input array
   *
   * @param array data
   *
   * @return void
   */
  private function addFlatFromArray(array data) -> void {
    let this->result[] = data;
  }

  /**
   * Create a document from the input array
   *
   * @throws \Arango\Exception\ClientException
   *
   * @param array data
   *
   * @return void
   */
  private function addDocumentsFromArray(array data) -> void {
    let this->result[] = Document::createFromArray(data, this->options);
  }

  /**
   * Create an array of paths from input array
   *
   * @throws \Arango\Exception\ClientException
   *
   * @param array data - array of incoming paths Arrays
   *
   * @return void
   */
  private function addPathsFromArray(array data) -> void {
    var entry;

    let entry = [
      "vertices" : [],
      "edges" : [],
      "source" : Document::createFromArray(data["source"], this->options),
      "destination" : Document::createFromArray(data["destination"], this->options)
    ];

    var value;
    for value in data["vertices"] {
      let entry["vertices"][] = Document::createFromArray(value, this->options);
    }

    for value in data["edges"] {
      let entry["edges"][] = Edge::createFromArray(value, this->options);
    }

    let this->result = entry;
  }

  /**
   * Create an array of shortest paths from the input array
   *
   * @throws \Arango\Exception\ClientException
   *
   * @param array data - array of incoming paths Arrays
   *
   * @return void
   */
  private function addShortestPathFromArray(array data) -> void {
    var entry, path;

    if(!isset(data["vertices"])){
      return;
    }

    let entry = [
      "paths" : [],
      "source" : Document::createFromArray(data["source"], this->options),
      "distance" : data["distance"],
      "destination" : Document::createFromArray(data["destination"], this->options)
    ];

    let path = [
      "vertices" : [],
      "edges" : []
    ];

    var value;
    for value in data["vertices"] {
      let path["vertices"][] = value;
    }

    for value in data["edges"] {
      let entry["edges"][] = Edge::createFromArray(value, this->options);
    }

    let entry["paths"] = path;

    let this->result = entry;
  }

  /**
   * Rewind the cursor, necessary for Iterator
   *
   * @returns void
   */
  public function rewind() -> void {
    let this->position = 0;
  }

  /**
   * Return the current result row, necessary for Iterator
   *
   * @returns array - The current result row as an associative array
   */
  public function current() -> array {
    return this->result[this->position];
  }

  /**
   * Return the index of the current result row, necessary for Iterator
   *
   * @returns int - The current result row index
   */
  public function key() -> int {
    return this->position;
  }

  /**
   * Advance the cursor, necessary for Iterator
   *
   * @return void
   */
  public function next() -> void {
    let this->position = this->position + 1;
  }

  /**
   *  Check if cursor can be advanced further, necessary for Iterator
   *
   * This might issue additional HTTP requests to fetch any outstanding
   * results from the server
   *
   * @throws \Exception
   * @return boolean - True if the cursor can be advanced further, false if cursor is at end
   */
  public function valid() -> boolean {

    if(this->position <= this->length - 1) {
      return true;
    }

    if(!this->hasMore || !this->id) {
      return false;
    }

    // this->fetchOutstanding();
    return (this->position <= this->length - 1);
  }

  /**
   * Sanitize the result set rows
   *
   * This will remove the _id and _rev attributes from the results if the
   * "sanitize" option is set
   *
   * @param array rows - Array of rows to be sanitized
   *
   * @return array - Sanitized rows
   */
  private function sanitize(array rows) -> array {

    if(isset(this->options[self::ENTRY_SANITIZE]) && this->options[self::ENTRY_SANITIZE]){
      var key, value;
      for key, value in rows {
        if(is_array(value) && isset(value[Document::ENTRY_ID])){
          unset(rows[key][Document::ENTRY_ID]);
        }

        if(is_array(value) && isset(value[Document::ENTRY_REVISION])){
          unset(rows[key][Document::ENTRY_REVISION]);
        }
      }
    }

    return rows;
  }

  /**
   * Set the length of the fetched result set
   *
   * @return void
   */
  private function updateLenght() -> void {
    let this->length = count(this->result);
  }

  /**
   * Return the base url for cursor
   *
   * @return string
   */
  private function url() -> string {
    if(isset(this->options[self::ENTRY_BASE_URL])){
      return this->options[self::ENTRY_BASE_URL];
    }

    return Url::CURSOR;
  }

  /**
   * Get a statistical figure value from the query result
   *
   * @param string name - Name of figure to return
   *
   * @return int
   */
  private function getStatValue(string name) -> int {
    if(isset(this->options[self::ENTRY_STATS][name])){
      return this->options[self::ENTRY_STATS][name];
    }

    return 0;
  }

  /**
   * Get MetaData of the current cursor
   *
   * @return array
   */
  public function getMetadata() -> array | null {
    return this->data;
  }

  /**
   * Return the warnings issued during query execution
   *
   * @return array
   */
  public function getWarnings() -> array {
    if(isset(this->extra["warnings"])){
      return this->extra["warnings"];
    }

    return [];
  }

  /**
   * Return the number of writes executed by the query
   *
   * @return int
   */
  public function getWritesExecuted() -> int {
    return this->getStatValue("writesExecuted");
  }

  /**
   * Return the number of ignored write operations from the query
   *
   * @return int
   */
  public function getWritesIgnored() -> int {
    return this->getStatValue("writesIgnored");
  }

  /**
   * Return the number of documents iterated over in full scans
   *
   * @return int
   */
  public function getScannedFull() -> int {
    return this->getStatValue("scannedFull");
  }

  /**
   * Return the number of documents iterated over in index scans
   *
   * @return int
   */
  public function getScannedIndex() -> int {
    return this->getStatValue("scannedIndex");
  }

  /**
   * Return the number of documents filtered by query
   *
   * @return int
   */
  public function getFiltered() -> int {
    return this->getStatValue("filtered");
  }
}