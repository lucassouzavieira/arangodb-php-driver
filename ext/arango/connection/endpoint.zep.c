
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/array.h"


/**
 * An endpoint contains the server location the client connects to
 * the following endpoint types are currently supported:
 *
 * tcp://host:port for tcp connections <br>
 * unix://socket for UNIX sockets (provided the server supports this) <br>
 * ssl://host:port for SSL connections (provided the server supports this) <br>
 *
 * Note: SSL support is added in Arango server 1.1 <br>
 *
 * @package Arango/Connection
 * @class Options
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Connection_Endpoint) {

	ZEPHIR_REGISTER_CLASS(Arango\\Connection, Endpoint, arango, connection_endpoint, arango_connection_endpoint_method_entry, 0);

	/**
	 * Current endpoint value
	 */
	zend_declare_property_null(arango_connection_endpoint_ce, SL("value"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * TCP endpoint type
	 */
	zephir_declare_class_constant_string(arango_connection_endpoint_ce, SL("TYPE_TCP"), "tcp");

	/**
	 * SSL endpoint type
	 */
	zephir_declare_class_constant_string(arango_connection_endpoint_ce, SL("TYPE_SSL"), "ssl");

	/**
	 * UNIX socket endpoint type
	 */
	zephir_declare_class_constant_string(arango_connection_endpoint_ce, SL("TYPE_UNIX"), "unix");

	/**
	 * Regexp for TCP endpoints
	 */
	zephir_declare_class_constant_string(arango_connection_endpoint_ce, SL("REGEXP_TCP"), "/^tcp:\\/\\/(.+?):(\\d+)\\/?$/");

	/**
	 * Regexp for SSL endpoints
	 */
	zephir_declare_class_constant_string(arango_connection_endpoint_ce, SL("REGEXP_SSL"), "/^ssl:\\/\\/(.+?):(\\d+)\\/?$/");

	/**
	 * Regexp for UNIX socket endpoints
	 */
	zephir_declare_class_constant_string(arango_connection_endpoint_ce, SL("REGEXP_UNIX"), "/^unix:\\/\\/(.+)$/");

	/**
	 * Endpoint index
	 */
	zephir_declare_class_constant_string(arango_connection_endpoint_ce, SL("ENTRY_ENDPOINT"), "endpoint");

	/**
	 * Databases index
	 */
	zephir_declare_class_constant_string(arango_connection_endpoint_ce, SL("ENTRY_DATABASES"), "databases");

	return SUCCESS;

}

/**
 * Create a new endpoint
 *
 * @throws \Arango\Exception\ClientException
 * @param string value - endpoint specification
 */
PHP_METHOD(Arango_Connection_Endpoint, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL, _0, _1$$3, _2$$3, _3$$3;
	zval value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	zephir_get_strval(&value, value_param);


	ZEPHIR_CALL_SELF(&_0, "isvalid", NULL, 0, &value);
	zephir_check_call_status();
	if (!zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, arango_exception_clientexception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "Invalid endpoint specification '%s'");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 34, &_2$$3, &value);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 9, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "arango/connection/endpoint.zep", 77 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, SL("value"), &value);
	ZEPHIR_MM_RESTORE();

}

/**
 * Endpoint representation
 *
 * @return string
 */
PHP_METHOD(Arango_Connection_Endpoint, __toString) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "value");

}

/**
 * Return the type of an endpoint
 *
 * @param string value - endpoint specification
 * @return string | null
 */
PHP_METHOD(Arango_Connection_Endpoint, getType) {

	zval *value_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7, _8;
	zval value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	zephir_get_strval(&value, value_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "/^tcp:\\/\\/(.+?):(\\d+)\\/?$/");
	zephir_preg_match(&_1, &_2, &value, &_0, 0, 0 , 0  TSRMLS_CC);
	if (zephir_is_true(&_1)) {
		RETURN_MM_STRING("tcp");
	}
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "/^ssl:\\/\\/(.+?):(\\d+)\\/?$/");
	zephir_preg_match(&_4, &_5, &value, &_3, 0, 0 , 0  TSRMLS_CC);
	if (zephir_is_true(&_4)) {
		RETURN_MM_STRING("ssl");
	}
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_INIT_VAR(&_7);
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "/^unix:\\/\\/(.+)$/");
	zephir_preg_match(&_7, &_8, &value, &_6, 0, 0 , 0  TSRMLS_CC);
	if (zephir_is_true(&_7)) {
		RETURN_MM_STRING("unix");
	}
	RETURN_MM_NULL();

}

/**
 * Return the host of an endpoint
 *
 * @param string value - endpoint specification
 * @return string | null
 */
PHP_METHOD(Arango_Connection_Endpoint, getHost) {

	zval *value_param = NULL, matches, _0, _1, _3, _4, _2$$3, _5$$4;
	zval value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	zephir_get_strval(&value, value_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/^tcp:\\/\\/(.+?):(\\d+)\\/?$/");
	zephir_preg_match(&_0, &_1, &value, &matches, 0, 0 , 0  TSRMLS_CC);
	if (zephir_is_true(&_0)) {
		zephir_array_fetch_long(&_2$$3, &matches, 1, PH_NOISY | PH_READONLY, "arango/connection/endpoint.zep", 124 TSRMLS_CC);
		RETURN_CTOR(&_2$$3);
	}
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "/^ssl:\\/\\/(.+?):(\\d+)\\/?$/");
	zephir_preg_match(&_3, &_4, &value, &matches, 0, 0 , 0  TSRMLS_CC);
	if (zephir_is_true(&_3)) {
		zephir_array_fetch_long(&_5$$4, &matches, 1, PH_NOISY | PH_READONLY, "arango/connection/endpoint.zep", 128 TSRMLS_CC);
		RETURN_CTOR(&_5$$4);
	}
	RETURN_MM_NULL();

}

/**
 * Check if an endpoint specification is valid
 *
 * @param string value - endpoint specification
 * @return string
 */
PHP_METHOD(Arango_Connection_Endpoint, isValid) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL, type, _1;
	zval value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	zephir_get_strval(&value, value_param);


	ZEPHIR_CALL_SELF(&type, "gettype", NULL, 0, &value);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "tcp");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ssl");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "unix");
	zephir_array_fast_append(&_0, &_1);
	RETURN_MM_BOOL(zephir_fast_in_array(&type, &_0 TSRMLS_CC));

}

/**
 * List endpoints
 *
 * This will list the endpoints that are configured on the server
 *
 * @throws \Arango\Exception\ClientException
 * @link https://docs.Arango.com/devel/Manual/Administration/Configuration/Endpoint.html
 * @param Connection connection - the connection to be used
 * @return array
 */
PHP_METHOD(Arango_Connection_Endpoint, listEndpoints) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connection, connection_sub, response, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connection);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "/_api/endpoint");
	ZEPHIR_CALL_METHOD(&response, connection, "get", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&response, "toarray", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

