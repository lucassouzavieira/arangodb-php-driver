
namespace Arango\Connection;

use Arango\Connection\Endpoint;
use Arango\Policies\UpdatePolicy;
use Arango\Exception\ClientException;

/**
 * Options class
 *
 * Container to manage connection options
 *
 * @package Arango/Connection
 * @class Options
 * @author Lucas S. Vieira
 */
class Options implements \ArrayAccess {

  /**
   * Endpoint string index constant
   */
  const ENDPOINT = "endpoint";

  /**
   * Host name string index constant (deprecated, use endpoint instead)
   */
  const HOST = "host";

  /**
   * Port number index constant (deprecated, use endpoint instead)
   */
  const PORT = "port";

  /**
   * Timeout value index constant
   */
  const TIMEOUT = "timeout";

  /**
   * Trace function index constant
   */
  const TRACE = "trace";

  /**
   * "verify certificates" index constant
   */
  const VERIFY_CERT = "verifyCert";

  /**
   * "allow self-signed" index constant
   */
  const ALLOW_SELF_SIGNED = "allowSelfSigned";

  /**
   * ciphers allowed to be used in SSL
   */
  const CIPHERS = "ciphers";

  /**
   * Enhanced trace
   */
  const ENHANCED_TRACE = "enhancedTrace";

  /**
   * "Create collections if they don't exist" index constant
   */
  const CREATE = "createCollection";

  /**
   * Update revision constant
   */
  const REVISION = "rev";

  /**
   * Update policy index constant
   */
  const UPDATE_POLICY = "policy";

  /**
   * Update keepNull constant
   */
  const UPDATE_KEEPNULL = "keepNull";

  /**
   * Replace policy index constant
   */
  const REPLACE_POLICY = "policy";

  /**
   * Delete policy index constant
   */
  const DELETE_POLICY = "policy";

  /**
   * Wait for sync index constant
   */
  const WAIT_SYNC = "waitForSync";

  /**
   * Limit index constant
   */
  const LIMIT = "limit";

  /**
   * Skip index constant
   */
  const SKIP = "skip";

  /**
   * Batch size index constant
   */
  const BATCHSIZE = "batchSize";

  /**
   * Journal size index constant
   */
  const JOURNAL_SIZE = "journalSize";

  /**
   * Is system index constant
   */
  const IS_SYSTEM = "isSystem";

  /**
   * Is volatile index constant
   */
  const IS_VOLATILE = "isVolatile";

  /**
   * Authentication user name
   */
  const AUTH_USER = "AuthUser";

  /**
   * Authentication password
   */
  const AUTH_PASSWD = "AuthPasswd";

  /**
   * Authentication type
   */
  const AUTH_TYPE = "AuthType";

  /**
   * Connection
   */
  const CONNECTION = "Connection";

  /**
   * Reconnect flag
   */
  const RECONNECT = "Reconnect";

  /**
   * Batch flag
   */
  const BATCH = "Batch";

  /**
   * Batchpart flag
   */
  const BATCHPART = "BatchPart";

  /**
   * Database flag
   */
  const DATABASE = "database";

  /**
   * UTF-8 CHeck Flag
   */
  const CHECK_UTF8_CONFORM = "CheckUtf8Conform";


  /**
   * The current options
   *
   * @var array
   */
  private values;

  /**
   * The current options
   *
   * @var Endpoint
   */
  private endpoint;

  /**
   * Set defaults, use options provided by client and validate them
   *
   * @param array $options - initial options
   *
   * @throws Arango\Exception\ClientException
   */
  public function __construct(array options) {
    let this->values = array_merge(self::getDefaults(), options);
    this->validate();
  }

  /**
   * Get the default values for the options
   *
   * @return array
   */
  public static function getDefaults() -> array {
    return [
      self::ENDPOINT : null,
      self::HOST : null,
      self::PORT : 8529,
      self::TIMEOUT : 30,
      self::CREATE : false,
      self::UPDATE_POLICY : UpdatePolicy::ERROR,
      self::REPLACE_POLICY : UpdatePolicy::ERROR,
      self::DELETE_POLICY : UpdatePolicy::ERROR,
      self::REVISION : null,
      self::WAIT_SYNC : false,
      self::BATCHSIZE : null,
      self::JOURNAL_SIZE : 33554432,
      self::IS_SYSTEM : null,
      self::IS_VOLATILE : false,
      self::CONNECTION : "Keep-Alive",
      self::TRACE : null,
      self::ENHANCED_TRACE : false,
      self::VERIFY_CERT : false,
      self::ALLOW_SELF_SIGNED : true,
      self::CIPHERS : null,
      self::AUTH_USER : null,
      self::AUTH_TYPE : "Basic",
      self::AUTH_PASSWD : null,
      self::RECONNECT : null,
      self::BATCH : null,
      self::BATCHPART : null,
      self::DATABASE : null,
      self::CHECK_UTF8_CONFORM : false
    ];
  }

  /**
   * Return the supported auth types
   *
   * @return array
   */
  private static function getSupportedAuthTypes() -> array {
    return ["Basic"];
  }

  /**
   * Return the supported connection types
   *
   * @return array
   */
  private static function getSupportedConnectionsTypes() -> array {
    return ["Close", "Keep-Alive"];
  }

  /**
   * Check if an option exists
   *
   * @param string offset
   * @return boolean
   */
  public function offsetExists(string offset){
    return isset(this->values[offset]);
  }

  /**
   * Get an specific option
   *
   * @throws \Arango\Exception\ClientException
   * @param string offset
   * @return mixed
   */
  public function offsetGet(string offset){
    if(!array_key_exists(offset, this->values)){
      throw new ClientException("Invalid option: " . offset);
    }

    return this->values[offset];
  }

  /**
   * Set and validate a specific option
   *
   * @throws \Exception
   * @param string offset - Name of option
   * @param mixed value - Value for option
   */
  public function offsetSet(string offset, value) {
    let this->values[offset] = value;
    this->validate();
  }

  /**
   * Remove an option and validate
   *
   * @throws \Exception
   * @param string offset - Name of option
   */
  public function offsetUnset(string offset) {
    unset(this->values[offset]);
    this->validate();
  }

  /**
   * Validate the options
   *
   * @throws \Arango\Exception\ClientException
   * @return void
   */
  private function validate() -> void {
    if(isset(this->values[self::HOST]) && !is_string(this->values[self::HOST])) {
      throw new ClientException("Host should be a string");
    }

    if(isset(this->values[self::PORT]) && !is_int(this->values[self::PORT])) {
      throw new ClientException("Host should be an integer");
    }

    if(isset(this->values[self::HOST]) && !is_string(this->values[self::HOST])) {
      throw new ClientException("Host should be a string");
    }

    if(isset(this->values[self::HOST]) && !is_null(this->values[self::ENDPOINT])) {
      throw new ClientException("Must not specify both Host and Endpoint");
    }

    if(isset(this->values[self::HOST]) || !isset(this->values[self::ENDPOINT])) {
      let this->values[self::ENDPOINT] = "tcp://" .
              this->values[self::HOST] . ":" . this->values[self::PORT];
      unset(this->values[self::HOST]);
    }

    var type;
    let type = Endpoint::getType(this->values[self::ENDPOINT]);

    if(type == Endpoint::TYPE_UNIX || type == Endpoint::TYPE_SSL) {
      let this->values[self::PORT] = 0;
    }

    if(isset(this->values[self::AUTH_TYPE]) &&
        !in_array(this->values[self::AUTH_TYPE], self::getSupportedAuthTypes())) {
      throw new ClientException("Unsupported authorization method");
    }

    if(isset(this->values[self::CONNECTION]) &&
        !in_array(this->values[self::CONNECTION], self::getSupportedConnectionsTypes())) {
      throw new ClientException("Unsupported connection value");
    }

    UpdatePolicy::validate(this->values[self::UPDATE_POLICY]);
    UpdatePolicy::validate(this->values[self::REPLACE_POLICY]);
    UpdatePolicy::validate(this->values[self::DELETE_POLICY]);
  }
}
