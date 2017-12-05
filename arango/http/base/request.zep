
namespace Arango\Http\Base;

use Arango\Http\Base\Message;
use Arango\Http\Contracts\Stream as StreamInterface;
use Arango\Http\Contracts\Request as RequestInterface;

/**
 * Request abstract class
 *
 * @since 1.0
 * @package Arango\Http\Base
 * @author Lucas S. Vieira
 */
abstract class Request extends Message implements RequestInterface {
}
