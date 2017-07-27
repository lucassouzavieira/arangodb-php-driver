
namespace Arango\Export;

use Arango\Connection\Connection;

/**
 * Collection export
 * TODO all
 * @package Arango/Export
 * @class Export
 * @author Lucas S. Vieira
 */
class Export {

  /**
   * Connection object
   *
   * @var Connection
   */
  private connection;

  /**
   * Collection object
   *
   * @var Connection
   */
  private collection;

  /**
   * The current batch size
   *
   * @var Connection
   */
  private batchSize;

  /**
   * Flat flag (If set, the query results will be treated as a simple array, not documents)
   *
   * @var boolean
   */
  private flat = false;

  /**
   * Flush flag (if set, then all documents from the collection that are currently only
   * in the write-ahead log (WAL) will be moved to the collection's datafiles. This may cause
   * an initial delay in the export, but will lead to the documents in the WAL not being
   * excluded from the export run. If the flush flag is set to false, the documents still
   * in the WAL may be missing in the export result.
   *
   * @var boolean
   */
  private flush = true;

  /**
   * The underlying collection type
   *
   * @var string
   */
  private type;

  /**
   * Exports restrictions
   * Null if for no restrictions or an array with a "type" and a "fields" index
   *
   * @var mixed
   */
  private restrictions;

  /**
   * Optional limit for export
   * If specified and positive, will cap the amount of
   * documents in the cursor to the specified value
   *
   * @var int
   */
  private limit = 0;

  /**
   * Export indexes
   */
  const COUNT = "count";
  const BATCH_SIZE = "batchSize";
  const FLUSH = "flush";
  const RESTRICT = "restrict";
  const LIMIT = "limit";

  /**
   * Initialize the export
   *
   * @throws \Exception
   *
   * @param Connection connection - The Connection object
   * @param Collection collection - The Collection to export
   * @param array options         - The export options
   */
  public function __construct(<Connection> connection, <Collection> collection, array options = []) {

  }
}
