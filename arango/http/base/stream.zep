
namespace Arango\Http\Base;

use Arango\Http\Contracts\Stream as StreamInterface;

/**
 * Request abstract class
 *
 * @since 1.0
 * @package Arango\Http\Base
 * @author Lucas S. Vieira
 */
class Stream implements StreamInterface {

  const MODE_READ_ONLY_FROM_BEGIN   = "r";
  const MODE_READ_WRITE_RESET       = "r+";
  const MODE_WRITE_ONLY_RESET       = "w";
  const MODE_READ_WRITE_FROM_BEGIN  = "w+";
  const MODE_WRITE_ONLY_FROM_END    = "a";
  const MODE_READ_WRITE_FROM_END    = "a+";
  const MODE_WRITE_ONLY_CREATE      = "x";
  const MODE_READ_WRITE_ONLY_CREATE = "x+";

  /**
   * @var resource|string
   */
  protected stream;

  /**
  * @var resource
  */
  protected streamResource;

  /**
   * Stream init
   *
   * @param string|resource stream The stream resource header
   * @param string          mode   Mode with wich to open stream
   * @throws \InvalidArgumentException if a invalid stream is given
   */
  public function __construct(stream = "php://memory", mode = "r") {
    this->attach(stream, mode);
  }

  /**
   * @see Arango\Http\Contracts\Stream::__toString()
   */
  public function __toString() {
    if(!this->isReadable()) {
      return "";
    }

    var e;

    try {
      this->rewind();
      return this->getContents();
    } catch \Exception, e {
      return e->getMessage();
    }
  }

  /**
   * @see Arango\Http\Contracts\Stream::close()
   */
  public function close() -> void {
    if(this->streamResource) {
      var localResource;

      let localResource = this->detach();
      fclose(localResource);
    }

    return;
  }

  /**
   * @see Arango\Http\Contracts\Stream::detach()
   */
  public function detach() {
    var localResource;

    let localResource = this->streamResource;

    let this->stream = null;
    let this->streamResource = null;

    return localResource;
  }

  /**
   * @see Arango\Http\Contracts\Stream::getSize()
   */
  public function getSize() -> int | null {
    if(!is_resource(this->streamResource)) {
      return null;
    }

    var stats;

    let stats = fstat(this->streamResource);
    return stats["size"];
  }

  /**
   * @see Arango\Http\Contracts\Stream::getSize()
   */
  public function tell() -> int {
    if(!is_resource(this->streamResource)) {
      throw new \RuntimeException("No resource available");
    }

    var result;
    let result = ftell(this->streamResource);

    if(!is_int(result)) {
      throw new \RuntimeException("Error occurred during tell operation");
    }

    return result;
  }

  /**
   * @see Arango\Http\Contracts\Stream::eof()
   */
  public function eof() -> bool {
    if(!is_resource(this->streamResource)) {
      return true;
    }

    return feof(this->streamResource);
  }

  /**
   * @see Arango\Http\Contracts\Stream::isSeekable()
   */
  public function isSeekable() -> bool {
    if(!is_resource(this->streamResource)) {
      return true;
    }

    var meta;
    let meta = stream_get_meta_data(this->streamResource);

    return meta["seekable"];
  }

  /**
   * @see Arango\Http\Contracts\Stream::seek()
   */
  public function seek(int offset, int whence = 0) {
    if(!is_resource(this->streamResource)) {
      throw new \RuntimeException("No resource available");
    }

    if(!this->isSeekable()) {
      throw new \RuntimeException("Stream is not seekable");
    }

    var result;
    let result = fseek(this->streamResource, offset, whence);

    if(result !== 0) {
      throw new \RuntimeException("Error seeking within stream");
    }
  }

  /**
   * @see Arango\Http\Contracts\Stream::rewind()
   */
  public function rewind() {
    this->seek(0);
  }

  /**
   * @see Arango\Http\Contracts\Stream::isWritable()
   */
  public function isWritable() -> bool {
    if(!is_resource(this->streamResource)) {
      return false;
    }

    var meta;
    let meta = stream_get_meta_data(this->streamResource);

    return is_writable(meta["uri"]);
  }

  /**
   * @see Arango\Http\Contracts\Stream::write()
   */
  public function write(string content) -> int {
    if(!is_resource(this->streamResource)) {
      throw new \RuntimeException("No resource available");
    }

    var result = 0;

    if(this->isWritable()) {
      let result = fwrite(this->streamResource, content);
    }


    if(result === false) {
      throw new \RuntimeException("Error writing to stream");
    }

    return result;
  }

  /**
   * @see Arango\Http\Contracts\Stream::isReadable()
   */
  public function isReadable() -> bool {
    if(!is_resource(this->streamResource)) {
      return false;
    }

    var meta, mode;
    let meta = stream_get_meta_data(this->streamResource);
    let mode = meta["mode"];

    return (strstr(mode, "r") || strstr(mode, "+"));
  }

  /**
   * @see Arango\Http\Contracts\Stream::read()
   */
  public function read(int lenght) -> string {
    if(!is_resource(this->streamResource)) {
      throw new \RuntimeException("No resource available");
    }

    if(!this->isReadable()) {
      throw new \RuntimeException("Stream is not readable");
    }

    var result;
    let result = fread(this->streamResource, lenght);

    if(result === false) {
      throw new \RuntimeException("Error reading from stream");
    }

    return result;
  }

  /**
   * @see Arango\Http\Contracts\Stream::getContents()
   */
  public function getContents() -> string {
    if(!is_resource(this->streamResource)) {
      throw new \RuntimeException("No resource available");
    }

    var result = "";

    if(this->isReadable()) {
      let result = stream_get_contents(this->streamResource);

      if(result === false) {
        throw new \RuntimeException("Error reading from stream");
      }
    }

    return result;
  }

  /**
   * @see Arango\Http\Contracts\Stream::getMetadata()
   */
  public function getMetadata(string key = null) {
    var metadata;
    let metadata = stream_get_meta_data(this->streamResource);

    if(is_null(key)) {
      return metadata;
    }

    if(!array_key_exists(key, metadata)) {
      return null;
    }

    return metadata[key];
  }

  /**
   * Attach resource into object
   *
   * @param string|resource stream The stream resource header
   * @param string          mode   Mode with wich to open stream
   * @return static
   * @throws \InvalidArgumentException if a invalid stream is given
   */
  public function attach(stream, mode = "r") {
    let this->stream = stream;

    if(!(is_string(stream) || is_resource(stream))) {
      throw new \InvalidArgumentException("Invalid resource");
    }

    if(is_resource(stream)) {
      let this->streamResource = stream;
    }

    if(is_string(stream)) {
      let this->streamResource = fopen(stream, mode);
    }

    return this;
  }

  /**
   * Return stream resource
   *
   * @return resource|null
   */
  public function getResource() {
    return this->streamResource;
  }
}
