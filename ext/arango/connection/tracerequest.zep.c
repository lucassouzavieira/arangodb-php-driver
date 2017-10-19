
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
#include "kernel/operators.h"
#include "kernel/memory.h"


/**
 * Trace requests to server
 *
 * @package Arango/Connection
 * @class TraceRequest
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Connection_TraceRequest) {

	ZEPHIR_REGISTER_CLASS(Arango\\Connection, TraceRequest, arango, connection_tracerequest, arango_connection_tracerequest_method_entry, 0);

	/**
	 * Stores each header as key-element pair in an array
	 *
	 * @var array
	 */
	zend_declare_property_null(arango_connection_tracerequest_ce, SL("headers"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Stores HTTP method
	 *
	 * @var string
	 */
	zend_declare_property_null(arango_connection_tracerequest_ce, SL("method"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Stores the request URL
	 *
	 * @var string
	 */
	zend_declare_property_null(arango_connection_tracerequest_ce, SL("requestUrl"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Stores the string of the body
	 *
	 * @var string
	 */
	zend_declare_property_null(arango_connection_tracerequest_ce, SL("body"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * HTTP message type
	 *
	 * @var string
	 */
	zend_declare_property_string(arango_connection_tracerequest_ce, SL("type"), "request", ZEND_ACC_PRIVATE TSRMLS_CC);

	arango_connection_tracerequest_ce->create_object = zephir_init_properties_Arango_Connection_TraceRequest;
	return SUCCESS;

}

/**
 * Stores each header as key-element pair in an array
 */
PHP_METHOD(Arango_Connection_TraceRequest, getHeaders) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "headers");

}

/**
 * Stores HTTP method
 */
PHP_METHOD(Arango_Connection_TraceRequest, getMethod) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "method");

}

/**
 * Stores the request URL
 */
PHP_METHOD(Arango_Connection_TraceRequest, getRequestUrl) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "requestUrl");

}

/**
 * Stores the string of the body
 */
PHP_METHOD(Arango_Connection_TraceRequest, getBody) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "body");

}

/**
 * HTTP message type
 */
PHP_METHOD(Arango_Connection_TraceRequest, getType) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "type");

}

/**
 * Set up the Trace
 *
 * @param array headers     - array with HTTP headers
 * @param string method     - HTTP method
 * @param string requestUrl - request URL
 * @param string body       - request body
 */
PHP_METHOD(Arango_Connection_TraceRequest, __construct) {

	zval method, requestUrl, body;
	zval *headers_param = NULL, *method_param = NULL, *requestUrl_param = NULL, *body_param = NULL;
	zval headers;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&requestUrl);
	ZVAL_UNDEF(&body);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &headers_param, &method_param, &requestUrl_param, &body_param);

	zephir_get_arrval(&headers, headers_param);
	zephir_get_strval(&method, method_param);
	zephir_get_strval(&requestUrl, requestUrl_param);
	zephir_get_strval(&body, body_param);


	zephir_update_property_zval(this_ptr, SL("headers"), &headers);
	zephir_update_property_zval(this_ptr, SL("method"), &method);
	zephir_update_property_zval(this_ptr, SL("requestUrl"), &requestUrl);
	zephir_update_property_zval(this_ptr, SL("body"), &body);
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Arango_Connection_TraceRequest(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("headers"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

