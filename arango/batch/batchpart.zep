
namespace Arango\Batch;

use Arango\Batch\Batch;

/**
 * Provides batch part functionality
 *
 * @package Arango/Batch
 * @class Batch
 * @author Lucas S. Vieira
 */
class BatchPart {

  /**
   * An array of BatchPart options
   *
   * @var array
   */
  private cursorOptions = [];

  /**
   * BatchPart id
   *
   * @var mixed
   */
   private id {
     get, set
   };

   /**
    * The type of request
    *
    * @var array
    */
   private type;

   /**
    * An array of Requests for this instance
    *
    * @var array
    */
   private request = [];

   /**
    * An array of Responses for this instance
    *
    * @var array
    */
   private response = [];

   /**
    * The batch that this instance is part of
    *
    * @var Batch
    */
   private batch;

   public function __construct(<Batch> batch, id, type, request, response, options) {

   }
}
