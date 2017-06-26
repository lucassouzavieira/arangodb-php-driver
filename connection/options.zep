
namespace ArangoDB\Connection;

use ArangoDB\Exception\ClientException;
use ArangoDB\Policies\UpdatePolicy;

/**
 * Options class
 *
 * Container to manage connection options
 *
 * @package ArangoDB/Connection
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
  const  AUTH_PASSWD = "AuthPasswd";

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
   * @throws \ArangoDB\Exception\ClientException
   * @param string offset
   * @return mixed
   */
  public function offsetGet(string offset){
    if(!array_key_exists(offset, this->values)){
      throw new ClientException("Invalid option: " . offset);
    }
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
   * @throws \ArangoDB\Exception\ClientException
   * @return void
   */
  private function validate() -> void {

  }

}
