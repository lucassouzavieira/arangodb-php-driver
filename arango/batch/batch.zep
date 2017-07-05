
namespace Arango\Batch;

use Arango\Http\Response;
use Arango\Connection\Connection;
use Arango\Cursor\Cursor;

/**
 * Provides batching functionality
 *
 * @package Arango/Batch
 * @class Batch
 * @author Lucas S. Vieira
 */
class Batch {

  /**
   * Batch response object
   *
   * @var Response
   */
  private batchResponse;

  /**
   * Flag that signals if this batch was processed or not
   *
   * @var boolean
   */
  private processed = false;

  /**
   * Batch size
   *
   * @var int
   */
  private batchSize;

  /**
   * An array of BatchPart objects
   *
   * @var array
   */
  private batchParts = [];

  /**
   * The next batch part Id
   *
   * @var int
   */
  private nextBatchPartId;

  /**
   * An array of batchPartCursor options
   *
   * @var array
   */
  private batchPartCursorOptions = [];

  /**
   * The connection object
   *
   * @var Connection
   */
  private connection;

  /**
   * The sanitize default value
   *
   * @var boolean
   */
  private sanitize = false;

  /**
   * The batch next id
   *
   * @var integer
   */
  private nextId;

  /**
   * Constructor for Batch instance. Batch instance by default starts capturing request after initiated.
   * To disable this, pass startCapture=>false inside the options array parameter
   *
   * @param Connection connection
   * @param array      options
   *
   * Options are:
   * "sanitize" = True to remove _id and _rev attributes from result documents returned from this batch. Defaults to false.
   * "startCapture" = Start batch capturing immediately after batch instantiation. Defaults to true.
   * "batchSize" = Defines a fixed array size for holding the batch parts. The id's of the batch parts can only be integers.
   *             When this option is defined, the batch mechanism will use an SplFixedArray instead of the normal PHP arrays.
   *             In most cases, this will result in increased performance of about 5% to 15%, depending on batch size and data.
   *
   */
  public function __construct(<Connection> connection, array options = []) {

    if(isset(options["sanitize"])) {
      let this->sanitize = (boolean) options["sanitize"];
    }

    if(isset(options["batchSize"]) && options["batchSize"] > 0) {
      let this->batchSize = (int) options["batchSize"];
      let this->batchParts = new \SplFixedArray(this->batchSize);
    }

    this->setConnection(connection);

    let this->batchPartCursorOptions = [Cursor::ENTRY_SANITIZE : this->sanitize];

    if (isset(options["startCapture"]) && (boolean) options["startCapture"]) {
      // this->startCapture();
    }
  }

  /**
   * Sets the connection for current batch
   *
   * @param Connection connection
   * @return void
   */
  public function setConnection(<Connection> connection) -> void {
    let this->connection = connection;
  }

  /**
   * Get this batch connection
   *
   * @return \Arango\Connection\Connection
   */
  public function getConnection() -> <Connection> {
    return this->connection;
  }

  /**
   * Sets the batch's associated connection into capture mode.
   *
   * @param boolean state
   *
   * @return void
   */
  public function setCapture(boolean state) -> void {
    this->connection->setCaptureBatch(state);
  }

  /**
   * Sets connection into Batch-Request mode.
   * This is necessary to distinguish between normal and the batch request.
   *
   * @param boolean state
   *
   * @return void
   */
  public function setBatchRequest(boolean state) -> void {
    this->connection->setBatchRequest(state);
    let this->processed = true;
  }

  /**
   * Sets the batch active in its associated connection
   *
   * @return void
   */
  public function setActive() -> void {
    this->connection->setActiveBatch(this);
  }

  /**
   * Returns true, if this batch is active in its associated connection
   *
   * @return boolean
   */
  public function isActive() -> boolean {
    return this === this->connection->getActiveBatch();
  }

  /**
   * Returns true, if this batch is capturing requests
   *
   * @return boolean
   */
  public function isCapturing() -> boolean {
    return this->connection->isInBatchCaptureMode();
  }

  /**
   * Activates the batch.
   * This sets the batch active in its associated connection and also starts capturing.
   *
   * @return void
   */
  public function startCapture() -> void {
    this->setActive();
    this->setCapture(true);
  }

  public function append(method, request) {
    return true;
  }
}
