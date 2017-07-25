
namespace Arango\Handler;

use Arango\Document\Vertex;
use Arango\Document\Document;
use Arango\Handler\DocumentHandler;

/**
 * A handler that manages vertex documents
 *
 * @package Arango/Handler
 * @class VertexHandler
 * @author Lucas S. Vieira
 */
class VertexHandler extends DocumentHandler {

  /**
   * Intermediate function to call the createFromArray function from the right context
   *
   * @throws Arango\Exception\ClientException
   *
   * @param array $data
   * @param array $options
   *
   * @return Arango\Document\Document
   */
  public function createFromArrayWithContext(array data, array options) -> <Document> {
    return Vertex::createFromArray(data, options);
  }
}
