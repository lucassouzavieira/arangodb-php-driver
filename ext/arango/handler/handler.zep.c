
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


/**
 * A base class for REST-based handlers
 *
 * @package Arango/Handler
 * @class Handler
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Handler_Handler) {

	ZEPHIR_REGISTER_CLASS(Arango\\Handler, Handler, arango, handler_handler, arango_handler_handler_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Connection object
	 *
	 * @var Connection
	 */
	zend_declare_property_null(arango_handler_handler_ce, SL("connection"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Construct a new handler
 *
 * @param Connection connection - Connection to be used
 */
PHP_METHOD(Arango_Handler_Handler, __construct) {

	zval *connection, connection_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);

	zephir_fetch_params(0, 1, 0, &connection);



	zephir_update_property_zval(this_ptr, SL("connection"), connection);

}

/**
 * Returns the connection object
 *
 * @return Arango\Connection\Connection
 */
PHP_METHOD(Arango_Handler_Handler, getConnection) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "connection");

}

/**
 * Returns an connection option
 *
 * @param string option - Option name
 *
 * @return mixed
 */
PHP_METHOD(Arango_Handler_Handler, getConnectionOption) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *option_param = NULL, _0;
	zval option;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &option_param);

	zephir_get_strval(&option, option_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getoption", NULL, 0, &option);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Return a JSON encoded string for the array given.
 *
 * @throws Arango\Exception\ClientException
 *
 * @param array body - The body to encode into JSON
 *
 * @return string    - JSON string of the body
 */
PHP_METHOD(Arango_Handler_Handler, jsonWrapper) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *body_param = NULL;
	zval body;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&body);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &body_param);

	zephir_get_arrval(&body, body_param);


	ZEPHIR_RETURN_CALL_CE_STATIC(arango_connection_encoding_ce, "jsonwrapper", &_0, 0, &body);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Turn a value into a Collection name
 *
 * @param mixed value - Document, Collection or string
 * @link https://github.com/arangodb/arangodb-php/blob/devel/lib/ArangoDBClient/Handler.php#L148-L158
 * @return string     - Collection name or empty string if the value is not an Document or Collection
 */
PHP_METHOD(Arango_Handler_Handler, getCollectionName) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	if (Z_TYPE_P(value) == IS_STRING) {
		RETVAL_ZVAL(value, 1, 0);
		RETURN_MM();
	}
	if (zephir_instance_of_ev(value, arango_collection_collection_ce TSRMLS_CC)) {
		ZEPHIR_RETURN_CALL_METHOD(value, "getname", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (zephir_instance_of_ev(value, arango_document_document_ce TSRMLS_CC)) {
		ZEPHIR_RETURN_CALL_METHOD(value, "getconnectionid", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_STRING("");

}

