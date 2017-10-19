
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


/**
 * API Helper to Arango HTTP Interface
 *
 * @package Arango/Http
 * @class Api
 * @abstract
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Http_Api) {

	ZEPHIR_REGISTER_CLASS(Arango\\Http, Api, arango, http_api, NULL, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zephir_declare_class_constant_string(arango_http_api_ce, SL("DOCUMENT"), "/_api/document");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("EDGE"), "/_api/document");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("EDGES"), "/_api/edges");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("GRAPH"), "/_api/gharial");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("COLLECTION"), "/_api/collection");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("INDEX"), "/_api/index");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("CURSOR"), "/_api/cursor");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("IMPORT"), "/_api/import");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("EXPORT"), "/_api/export");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("EXPLAIN"), "/_api/explain");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("BATCH"), "/_api/batch");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("QUERY"), "/_api/query");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("TRANSACTION"), "/_api/transaction");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("AQL_USER_FUNCTION"), "/_api/aqlfunction");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("USER"), "/_api/user");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("TRAVERSAL"), "/_api/traversal");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("ENDPOINT"), "/_api/endpoint");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("DATABASE"), "/_api/database");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("QUERY_CACHE"), "/_api/query-cache");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("UPLOAD"), "/_api/upload");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("PART_VERTEX"), "vertex");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("PART_EDGE"), "vertex");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("LOOKUP_BY_KEYS"), "/_api/simple/lookup-by_keys");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("ALL"), "/_api/simple/all");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("ALL_KEYS"), "/_api/simple/all");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("ANY"), "/_api/simple/any");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("FULLTEXT"), "/_api/simple/fulltext");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("REMOVE_BY_KEYS"), "/_api/simple/remove-by-keys");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("EXAMPLE"), "/_api/simple/by-example");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("FIRST_EXAMPLE"), "/_api/simple/first-example");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("UPDATE_BY_EXAMPLE"), "/_api/simple/update-by-example");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("REMOVE_BY_EXAMPLE"), "/_api/simple/remove-by-example");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("REPLACE_BY_EXAMPLE"), "/_api/simple/replace-by-example");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("ADMIN_VERSION"), "/_admin/version");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("ADMIN_SERVER_ROLE"), "/_admin/server/role");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("ADMIN_TIME"), "/_admin/time");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("ADMIN_LOG"), "/_admin/log");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("ADMIN_ROUTING_RELOAD"), "/_admin/routing/reload");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("ADMIN_STATISTICS"), "/_admin/statistics");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("ADMIN_STATISTICS_DESCRIPTION"), "/_admin/statistics-description");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("FOXX_INSTALL"), "/_admin/foxx/install");

	zephir_declare_class_constant_string(arango_http_api_ce, SL("FOXX_UNINSTALL"), "/_admin/foxx/uninstall");

	return SUCCESS;

}

