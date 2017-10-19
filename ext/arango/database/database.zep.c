
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


/**
 * Manage Arango databases through Arango's Database API
 *
 * @link https://docs.Arango.com/3.1/HTTP/Database/
 * @package Arango\Database
 * @class Database
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Database_Database) {

	ZEPHIR_REGISTER_CLASS(Arango\\Database, Database, arango, database_database, arango_database_database_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Database indexes
	 */
	zephir_declare_class_constant_string(arango_database_database_ce, SL("NAME"), "name");

	zephir_declare_class_constant_string(arango_database_database_ce, SL("USERS"), "users");

	return SUCCESS;

}

/**
 * Creates a database
 *
 * @throws Arango\Exception\ClientException
 *
 * @link https://docs.arangodb.com/3.2/HTTP/Database/DatabaseManagement.html
 *
 * @param Connection connection
 * @param string name
 *
 * @return array - Database info
 */
PHP_METHOD(Arango_Database_Database, create) {

	zval _2;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name;
	zval *connection, connection_sub, *name_param = NULL, payload, response, users, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&payload);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&users);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &connection, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_INIT_VAR(&users);
	zephir_create_array(&users, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "AuthUser");
	ZEPHIR_CALL_METHOD(&_0, connection, "getoption", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_array_update_string(&users, SL("username"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "AuthPasswd");
	ZEPHIR_CALL_METHOD(&_0, connection, "getoption", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_array_update_string(&users, SL("passwd"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&payload);
	zephir_create_array(&payload, 2, 0 TSRMLS_CC);
	zephir_array_update_string(&payload, SL("name"), &name, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(&_2, &users);
	zephir_array_update_string(&payload, SL("users"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_CE_STATIC(&_0, arango_connection_encoding_ce, "jsonwrapper", &_3, 0, &payload);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "/_api/database");
	ZEPHIR_CALL_METHOD(&response, connection, "post", NULL, 0, &_1, &_0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&response, "toarray", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Deletes a database
 *
 * @throws Arango\Exception\ClientException
 *
 * @link https://docs.arangodb.com/3.2/HTTP/Database/DatabaseManagement.html
 *
 * @param Connection connection   
 * @param string name
 *
 * @return array
 */
PHP_METHOD(Arango_Database_Database, delete) {

	zval _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval name;
	zval *connection, connection_sub, *name_param = NULL, url, response, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &connection, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(&_1, &name);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "/_api/database");
	ZEPHIR_CALL_CE_STATIC(&url, arango_http_url_ce, "buildurl", &_0, 0, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, connection, "delete", NULL, 0, &url);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&response, "toarray", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Lists the databases that exist on the server
 *
 * @throws Arango\Exception\ClientException
 *
 * @link https://docs.arangodb.com/3.2/HTTP/Database/DatabaseManagement.html
 *
 * @param Connection connection
 *
 * @return array
 */
PHP_METHOD(Arango_Database_Database, list) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connection, connection_sub, response, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connection);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "/_api/database");
	ZEPHIR_CALL_METHOD(&response, connection, "get", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&response, "toarray", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Lists user databases
 *
 * @throws Arango\Exception\ClientException
 *
 * @link https://docs.arangodb.com/3.2/HTTP/Database/DatabaseManagement.html
 *
 * @param Connection connection
 *
 * @return array
 */
PHP_METHOD(Arango_Database_Database, listUserDatabases) {

	zval _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *connection, connection_sub, url, response, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connection);



	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "user");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "/_api/database");
	ZEPHIR_CALL_CE_STATIC(&url, arango_http_url_ce, "buildurl", &_0, 0, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, connection, "get", NULL, 0, &url);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&response, "toarray", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Retrieves informations about the current database from server
 *
 * @throws Arango\Exception\ClientException
 *
 * @link https://docs.arangodb.com/3.2/HTTP/Database/DatabaseManagement.html
 *
 * @param Connection connection
 *
 * @return array
 */
PHP_METHOD(Arango_Database_Database, info) {

	zval _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *connection, connection_sub, url, response, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connection);



	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "current");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "/_api/database");
	ZEPHIR_CALL_CE_STATIC(&url, arango_http_url_ce, "buildurl", &_0, 0, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, connection, "get", NULL, 0, &url);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&response, "toarray", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

