
namespace ArangoDB\Client;

/**
 * Default client configurations
 *
 * @package ArangoDB/Client
 * @abstract
 * @class Configuration
 * @author Lucas S. Vieira
 */
abstract class Configuration {
  const PORT = 8529;
  const TIMEOUT = 30;
  const AUTH_TYPE = 'Basic';
  const WAIT_SYNC = false;
  const JOURNAL_SIZE = 33554432;
  const IS_VOLATILE = false;
  const CREATE = false;
  const CONNECTION = 'Keep-Alive';
  const VERIFY_CERT = false;
  const ALLOW_SELF_SIGNED = true;
  const CIPHERS = null;

  /**
   * TODO Add policies default values
   */
  const UPDATE_POLICY = false;
  const REPLACE_POLICY = false;
  const DELETE_POLICY = false;

  const CHECK_UTF8_CONFORM = false;
}
