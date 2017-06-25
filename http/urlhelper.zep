
namespace ArangoDB\Http;

/**
* URL Helper to ArangoDB HTTP Interface
* @package ArangoDB/Http
* @class UrlHelper
* @author Lucas S. Vieira
*/
abstract class UrlHelper {
  const DOCUMENT = '/_api/document';
  const EDGE = '/_api/document';
  const EDGES = '/_api/edges';
  const GRAPH = '/_api/gharial';
  const COLLECTION = '/_api/collection';
  const INDEX = '/_api/index';
  const CURSOR = '/_api/cursor';
  const IMPORT = '/_api/import';
  const EXPORT = '/_api/export';
  const EXPLAIN = '/_api/explain';
  const BATCH = '/_api/batch';
  const QUERY = '/_api/query';
  const TRANSACTION = '/_api/transaction';
  const AQL_USER_FUNCTION = '/_api/aqlfunction';

  const USER = '/_api/user';
  const TRAVERSAL = '/_api/traversal';
  const ENDPOINT = '/_api/endpoint';
  const DATABASE = '/_api/database';
  const QUERY_CACHE = '/_api/query-cache';
  const UPLOAD = '/_api/upload';

  const PART_VERTEX = 'vertex';
  const PART_EDGE   = 'vertex';


  const LOOKUP_BY_KEYS = '/_api/simple/lookup-by_keys';
  const URL_ALL = '/_api/simple/all';
  const URL_ALL_KEYS = '/_api/simple/all';
  const URL_ANY = '/_api/simple/any';
  const URL_FULLTEXT = '/_api/simple/fulltext';
  const URL_REMOVE_BY_KEYS = '/_api/simple/remove-by-keys';

  const URL_EXAMPLE = '/_api/simple/by-example';
  const URL_FIRST_EXAMPLE = '/_api/simple/first-example';
  const URL_UPDATE_BY_EXAMPLE = '/_api/simple/update-by-example';
  const URL_REMOVE_BY_EXAMPLE = '/_api/simple/remove-by-example';
  const URL_REPLACE_BY_EXAMPLE = '/_api/simple/replace-by-example';

  const URL_ADMIN_VERSION = '/_admin/version';
  const URL_ADMIN_SERVER_ROLE = '/_admin/server/role';
  const URL_ADMIN_TIME = '/_admin/time';
  const URL_ADMIN_LOG = '/_admin/log';
  const URL_ADMIN_ROUTING_RELOAD = '/_admin/routing/reload';
  const URL_ADMIN_STATISTICS = '/_admin/statistics';
  const URL_ADMIN_STATISTICS_DESCRIPTION = '/_admin/statistics-description';
  const FOXX_INSTALL = '/_admin/foxx/install';
  const FOXX_UNINSTALL = '/_admin/foxx/uninstall';
}
