
namespace Arango\Batch;

use Arango\Batch\Batch;
use Arango\Cursor\Cursor;
use Arango\Document\Edge;
use Arango\Document\Document;
use Arango\Handler\EdgeHandler;
use Arango\Exception\ClientException;

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
    * TODO
    *   refactor request setter and getter.
    *   This attribute must be an instance of \Arango\Http\Response
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

   /**
    * Gets the HTTP code for the current batch part
    *
    * @return int | null
    */
   public function getHttpCode() -> int | null {
     return this->getResponse()->getHttpCode();
   }

   /**
    * Get the batch part identified by the array key (0...n)
    * or its id if it was set with nextBatchPartId($id)
    *
    * @throws \Arango\Exception\ClientException
    *
    * @return mixed
    */
   public function getProcessedResponse()
   {
     var documentClass, response, options, body;

     let documentClass = this->documentClass;
     let response = this->getResponse();

     if(!in_array(this->type, [
       "first", "getdocument", "document", "getedge",
       "edge", "getedges", "getcollection", "collection",
       "cursor", "all", "by", "remove"
     ])) {
       throw new ClientException("Could not determine response data type");
     }

     if(this->type == "first") {
       let body = response->toArray();
       if(!isset(body["error"]) || body["error"] == false) {
         let options = this->getCursorOptions();
         let options["_isNew"] = false;
         let response = {documentClass}::createFromArray(body["document"], options);
       } else {
         let response = false;
       }
     }

     if(this->type == "getdocument") {
       let body = response->toArray();
       let options = this->getCursorOptions();
       let options["_isNew"] = false;
       let response = {documentClass}::createFromArray(body, options);
     }

     if(this->type == "document") {
       let body = response->toArray();
       if(!isset(body["error"]) || body["error"] == false) {
         var id;
         let id = body[Document::ENTRY_ID];
         let response = id;
       }
     }

     if(this->type == "getedge") {
       let body = response->toArray();
       let options = this->getCursorOptions();
       let options["_isNew"] = false;
       let response = Edge::createFromArray(body, options);
     }

     if(this->type == "edge") {
       // Verify response type
       let body = response->toArray();
       if(!isset(body["error"]) || body["error"] == false) {
         var id;
         let id = body[Edge::ENTRY_ID];
         let response = id;
       }
     }

     if(this->type == "getedges") {
       let body = response->toArray();
       let options = this->getCursorOptions();
       let options["_isNew"] = false;
       let response = [];

       var data;
       for _, data in body[EdgeHandler::ENTRY_EDGES] {
         let response[] = Edge::createFromArray(data, options);
       }
     }

     return response;
   }
}
