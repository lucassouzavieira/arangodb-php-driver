
namespace Arango\Http\Contracts;

/**
 * Describes a data stream.
 *
 * @link http://www.php-fig.org/psr/psr-7/
 * @package Arango\Http\Contracts
 * @author Lucas S. Vieira
 */
interface Stream {

  /**
   * Reads all data from the stream into a string, from the beginning to end.
   *
   * @see http://php.net/manual/en/language.oop5.magic.php#object.tostring
   * @return string
   */
  public function __toString();

  /**
   * Closes the stream and any underlying resources.
   *
   * @return void
   */
  public function close() -> void;

  /**
   * Separates any underlying resources from the stream.
   *
   * @return resource|null underlying strem, if exists
   */
  public function detach();

  /**
   * Get the size of the stream if known.
   *
   * @return int|null size in bytes, if known
   */
  public function getSize() -> int | null;

  /**
   * Returns the current position of the file read/write pointer.
   *
   * @return int position of the file pointer
   * @throws \RuntimeException on error
   */
  public function tell() -> int;

  /**
   * Returns true if the stream is at the end of the stream.
   *
   * @return bool
   */
  public function eof() -> bool;

  /**
   * Returns whether or not the stream is seekable.
   *
   * @return bool
   */
  public function isSeekable() -> bool;

  /**
   * Seek to a position in the stream.
   *
   * @link http://www.php.net/manual/en/function.fseek.php
   * @param int offset Stream offset
   * @param int whence Specifies how the cursor position will be calculated
   *     based on the seek offset. Valid values are identical to the built-in
   *     PHP $whence values for `fseek()`.  SEEK_SET: Set position equal to
   *     offset bytes SEEK_CUR: Set position to current location plus offset
   *     SEEK_END: Set position to end-of-stream plus offset.
   * @throws \RuntimeException on failure
   */
  public function seek(int offset, int whence = 0);

  /**
   * Seek to the beginning of the stream.
   *
   * @see seek()
   * @link http://www.php.net/manual/en/function.fseek.php
   * @throws \RuntimeException
   */
  public function rewind();

  /**
   * Returns whether or not the stream is writable.
   *
   * @return bool
   */
  public function isWritable() -> bool;

  /**
   * Write data to the stream.
   *
   * @param string content The string that is to be written
   * @return int Return the number of bytes written to the stream
   * @throws \RuntimeException
   */
  public function write(string content) -> int;

  /**
   * Returns whether or not the stream is readable.
   *
   * @return bool
   */
  public function isReadable() -> bool;

  /**
   * Read data from the stream.
   *
   * @param int lenght Read up to lenght bytes from the object an return them.
   * @return string Return the data read from stream or a empty string if no bytes are available.
   * @throws \RuntimeException
   */
  public function read(int lenght) -> string;

  /**
   * Returns the remaining contents in a string
   *
   * @return string
   * @throws \RuntimeException
   */
  public function getContents() -> string;

  /**
   * Get stream metadata as an associative array or retrieve a specific key.
   *
   * @link http://php.net/manual/en/function.stream-get-meta-data.php
   * @param string key specific metadata to retrieve
   * @return array|mixed|null Returns an associative array if no key is
   *     provided. Returns a specific key value if a key is provided and the
   *     value is found, or null if the key is not found.
   */
  public function getMetadata(string key = null);
}
