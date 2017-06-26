
namespace ArangoDB\Connection;

use ArangoDB\Connection\Options;
use ArangoDB\Connection\Encoding;
use ArangoDB\Http\HttpClient;
use ArangoDB\Exception\ClientException;
use ArangoDB\Exception\ConnectException;

/**
 * Connection class
 *
 * Provides access to ArangoDB server
 *
 * As all access is done using HTTP, we do not need to establish a
 * persistent connection and keep its state.
 *
 * Instead, connections are established on the fly for each request
 * and are destroyed afterwards.
 *
 * @package ArangoDB\Connection
 * @class Connection
 * @author Lucas S. Vieira
 */
class Connection {

  /**
   * Connection options
   *
   * @var \ArangoDB\Connection\Options
   */
  private options;

  /**
   * Pre-assembled HTTP headers string for connection
   * This is pre-calculated when connection options are set/changed, to avoid
   * calculation of the same HTTP header values in each request done via the
   * connection
   *
   * @var string
   */
  private httpHeader;

  /**
   * Pre-assembled base URL for the current database
   * This is pre-calculated when connection options are set/changed, to avoid
   * calculation of the same base URL in each request done via the
   * connection
   *
   * @var string
   */
  private baseUrl;

  /**
   * Connection handle, used in case of keep-alive
   *
   * @var resource
   */
  private handle;

  /**
   * Flag if keep-alive connections are used
   *
   * @var boolean
   */
  private useKeepAlive;

  /**
   * Batches array
   *
   * @var boolean
   */
  private batches;

  /**
   * activeBatch object
   *
   * @var Batch
   */
  private activeBatch;

  /**
   * captureBatch boolean
   *
   * @var boolean
   */
  private captureBatch;

  /**
   * batchRequest boolean
   *
   * @var boolean
   */
  private batchRequest;

  /**
   * database string
   *
   * @var string
   */
  private database;

  /**
   * Set up the connection object, validate the options provided
   *
   * @throws \Exception
   * @param array options - initial connection options
   */
  public function __construct(array options){
    let this->options = new Options(options);
    let this->useKeepAlive = (this->options[Options::CONNECTION] == "Keep-alive");
    this->setDatabase(this->options[Options::DATABASE]);
    this->updateHttpHeader();
  }

  /**
   * Close existing connection handle if a keep-alive connection was used
   *
   * @return void
   */
  public function __destruct(){
    if(this->useKeepAlive && is_resource(this->handle)){
      fclose(this->handle);
    }
  }

  /**
   * Validate an option
   *
   * @throws \ArangoDB\Exception\ClientException
   * @param string name - name of options
   * @param value
   * @return boolean
   */
  private static function validateOption(string name, value) -> boolean {
    array validOptions;
    let validOptions = [
      Options::ENDPOINT, Options::HOST, Options::PORT, Options::VERIFY_CERT, Options::CIPHERS, Options::ALLOW_SELF_SIGNED
    ];

    if(in_array(name, validOptions)){
      throw new ClientException("Must not set option " . name . " after connection is created.");
    }

    return true;
  }

  /**
   * Set an option for the connection
   *
   * @throws \ArangoDB\Exception\ClientException
   * @param string name - name of options
   * @param value
   * @return void
   */
  public function setOption(string name, value) -> void {
    if(Connection::validateOption(name, value)){
      let this->options[name] = value;
    }

    if(name == Options::TIMEOUT && is_resource(this->handle)){
      stream_set_timeout(this->handle, value);
    }

    if(name == Options::CONNECTION){
      let this->useKeepAlive = (strtolower(value) === "keep-alive");
    }

    if(name == Options::DATABASE){
      this->setDatabase(value);
    }

    this->updateHttpHeader();
  }

  /**
   * Get an option set for the connection
   *
   * @throws \ArangoDB\Exception\ClientException
   * @param string name - name of options
   * @return mixed
   */
  public function getOption(string name){
    return this->options[name];
  }

  /**
   * Get the options set for the connection
   *
   * @return \ArangoDB\Connection\Options | null
   */
  public function getOptions() -> <Options> | null {
    return this->options;
  }

  /**
   * Set the database name for the connection
   *
   * Further calls to the database will be addressed to the given database
   *
   * @param string name - name of database
   * @return void
   */
  public function setDatabase(string database) -> void {
    let this->options[Options::DATABASE] = database;
    let this->database = database;
    this->updateHttpHeader();
  }

  /**
   * Get the database that is currently used with this connection
   *
   * @return string
   */
  public function getDatabase() -> string {
    return this->database;
  }

  /**
   * Recalculate the static HTTP header string used for all HTTP requests in this connection
   *
   * @return void
   */
  private function updateHttpHeader() -> void {
     var endpoint;

     let this->httpHeader = HttpClient::EOL;
     let endpoint = this->options[Options::ENDPOINT];

     if(Endpoint::getType(endpoint) != Endpoint::TYPE_UNIX){
       let this->httpHeader = this->httpHeader . sprintf("Host: %s%s", Endpoint::getHost(endpoint), HttpClient::EOL);
     }

     if(isset(this->options[Options::AUTH_TYPE]) && isset(this->options[Options::AUTH_USER])){
       /* Add autorization header */
       var authorization;

       let authorization = base64_encode(
         this->options[Options::AUTH_USER] . ":",
         this->options[Options::AUTH_PASSWD]
       );

       let this->httpHeader = this->httpHeader . sprintf(
         "Authorization: %s %s%s",
         this->options[Options::AUTH_TYPE],
         authorization,
         HttpClient::EOL
       );
     }

     if(isset(this->options[Options::CONNECTION])){
       /* Add connection header */
       let this->httpHeader = this->httpHeader . sprintf(
         "Connection: %s%s",
         this->options[Options::CONNECTION],
         HttpClient::EOL
       );
     }

     let this->baseUrl = "/_db/_system";

     if(this->database != ""){
       let this->baseUrl = "/_db/" . urlencode(this->database);
     }
   }

   /**
    * Get a connection handle
    *
    * If keep-alive connections are used, the handle will be stored and re-used
    *
    * @throws \ArangoDB\Exception\ConnectException | \ArangoDB\Exception\ClientException
    * @return resource - connection handler
    */
   public function getHandle(){
     var handle;

     if(this->useKeepAlive && this->handle && is_resource(this->handle)){
       /* Keep-alive connection was created already*/

       let handle = this->handle;

       /* Check if connection is still valid */
       if(!feof(handle)){
         return handle;
       }

       /* Close handle*/
       fclose(this->handle);
       let this->handle = 0;

       if(!this->options[Options::RECONNECT]){
         throw new ClientException("Server has closed connection already");
       }
     }

     let handle = HttpClient::createConnection(this->options);

     if(this->useKeepAlive && is_resource(handle)){
       let this->handle = handle;
     }

     return handle;
   }
}
