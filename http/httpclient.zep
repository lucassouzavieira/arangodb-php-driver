namespace ArangoDB\Http;

/**
 * HttpClient to ArangoDB PHP Driver
 *
 * TODO A lot of things 
 *
 * @package ArangoDB/Http
 * @class HttpClient
 * @author Lucas S. Vieira
 */
class HttpClient {

  /**
   * HTTP method constants
   */
  const GET = "GET";
  const POST = "POST";
  const PUT = "PUT";
  const DELETE = "DELETE";
  const HEAD = "HEAD";
  const PATCH = "PATCH";

  /**
   * Number of bytes processed in one batch
   */
  const CHUNK_SIZE = 8192;

  /**
   * End of line mark used in HTTP
   */
  const EOL = "\r\n";

  /**
   * Separator between header and body
   */
  const SEPARATOR = "\r\n\r\n";

  /**
   * HTTP protocol version used, hard-coded to version 1.1
   */
  const PROTOCOL = "HTTP/1.1";

  /**
   * Boundary string for batch request parts
   */
  const MIME_BOUNDARY = "XXXsubpartXXX";

  /**
   * HTTP Header for making an operation asynchronous
   */
  const ASYNC_HEADER = "X-Arango-Async";
}
