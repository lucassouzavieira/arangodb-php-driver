
namespace Arango\Handler;

use Arango\Http\Api;
use Arango\Http\Url;
use Arango\Http\Response;
use Arango\Document\Document;
use Arango\Connection\Connection;
use Arango\Exception\ClientException;

/**
 * A handler that manages documents
 *
 * @package Arango/Handler
 * @class DocumentHandler
 * @author Lucas S. Vieira
 */
class DocumentHandler extends Handler {

  /**
   * Class indexes
   */

  const ENTRY_DOCUMENTS = "documents";
  const OPTION_COLLECTION = "collection";
  const OPTION_EXAMPLE = "example";

  /**
   * Get a single document from a collection
   *
   * @throws \Exception
   *
   * @param string documentId
   * @param array options
   *
   * @return Arango\Document\Document
   */
  public function get(string documentId, array options = []) -> <Document> {
    var collection, data, document;

    var documentData;
    let documentData = explode("/", documentId);

    let collection = documentData[0];
    let document = documentData[1];

    let data = this->getDocument(collection, document, options);
    let options["_isNew"] = false;

    return Document::createFromArray(data, options);
  }

  /**
   * Get a single document from server as array
   *
   * @throws Arango\Exception\ClientException
   *
   * @param string collection
   * @param string document
   * @param array options
   *
   * @return array
   */
  protected function getDocument(string collection, string document, array options = []) -> array {
    var url, headerElements;

    let url = Url::buildUrl(Api::DOCUMENT, [collection, document]);
    let headerElements = this->buildRevisionHeaders(options);

    var response;

    let response = this->getConnection()->get(url, headerElements);

    if(response->getCode() == 304) {
      throw new ClientException("Document has not changed");
    }

    return response->toArray();
  }

  /**
   * Build the revision headers for an requisition
   *
   * @param array options
   *
   * @return array
   */
  protected function buildRevisionHeaders(array options) -> array {
    array header = [];

    if(array_key_exists("ifMatch", options) && array_key_exists("revision", options)) {
      if(options["ifMatch"] == true) {
        let header["If-Match"] =  "\"" . options["revision"] . "\"";

        return header;
      }

      let header["If-None-Match"] =  "\"" . options["revision"] . "\"";;
    }

    return header;
  }
}
