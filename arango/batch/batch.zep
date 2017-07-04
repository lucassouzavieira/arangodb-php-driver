
namespace Arango\Batch;

use Arango\Http\Response;
use Arango\Connection\Connection;

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

  public function append(method, request) {
    return true;
  }
}
