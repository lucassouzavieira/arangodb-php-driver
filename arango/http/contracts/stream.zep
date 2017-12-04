
namespace Arango\Http\Contracts;

/**
 * Describes a data stream.
 *
 * @link http://www.php-fig.org/psr/psr-7/
 * @package Arango\Http\Contracts
 * @author Lucas S. Vieira
 */
interface Stream {
  public function __toString();

  public function close();

  public function detach();

  public function getSize();

  public function tell();

  public function eof();

  public function isSeekable();

  public function seek(int offset, int whence);

  public function rewind();

  public function isWritable() -> bool;

  public function write();

  public function isReadable();

  public function read(int lenght);

  public function getContents();

  public function getMetadata(string key = null);
}
