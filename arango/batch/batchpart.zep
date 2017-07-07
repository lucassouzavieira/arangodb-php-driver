
namespace Arango\Batch;

use Arango\Batch\Batch;
use Arango\Cursor\Cursor;

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
  private cursorOptions = [] {
    get
  };

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
   private type {
     get, set
   };

   /**
    * Batch part request for this instance
    *
    * @var string
    */
   private request {
     get, set
   };

   /**
    * Batch part response for this instance
    *
    * @var string
    */
   private response {
     get, set
   };

   /**
    * Document class for this instance
    *
    * @var string
    */
   private documentClass {
     set
   };

   /**
    * The batch that this instance is part of
    *
    * @var Arango\Batch\Batch
    */
   private batch;

   /**
    * Constructor
    *
    * @param Batch batch     - The batch object, that this part belongs to
    * @param mixed id        - The Id of batch part. Must be unique.
    * @param mixed type      - The type of request
    * @param string request  - The request string
    * @param string response - The response string
    * @param array options   - options like sanitize can be passed to the request/response handler
    *
    * @return void
    */
   public function __construct(<Batch> batch, id, type, string request, string response, array options = []) {
     var sanitize;

     let sanitize = false;
     let options = array_merge(options, this->getCursorOptions());

     if(isset(options["_documentClass"])){
       this->setDocumentClass(options["_documentClass"]);
     }

     this->setBatch(batch);
     this->setId(id);
     this->setType(type);
     this->setRequest(request);
     this->setResponse(response);

     if(isset(options["sanitize"])){
       let this->cursorOptions[Cursor::ENTRY_SANITIZE] = options["sanitize"];
     }
   }

   /**
    * Sets the batch that batch part belongs to
    *
    * @param Batch batch
    *
    * @return void
    */
   public function setBatch(<Batch> batch) -> void {
     let this->batch = batch;
   }

   /**
    * Gets the batch that batch part belongs to
    *
    * @return Batch
    */
   public function getBatch() -> <Batch> {
     return this->batch;
   }
}
