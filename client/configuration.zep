
namespace ArangoDB\Client;

use ArangoDB\Policies\UpdatePolicy;

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

  const UPDATE_POLICY = UpdatePolicy::ERROR;
  const REPLACE_POLICY = UpdatePolicy::ERROR;
  const DELETE_POLICY = UpdatePolicy::ERROR;

  const CHECK_UTF8_CONFORM = false;
}
