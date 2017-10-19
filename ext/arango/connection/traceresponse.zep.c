
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
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


/**
 * Trace responses from server
 *
 * @package Arango/Connection
 * @class TraceResponse
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Connection_TraceResponse) {

	ZEPHIR_REGISTER_CLASS(Arango\\Connection, TraceResponse, arango, connection_traceresponse, arango_connection_traceresponse_method_entry, 0);

	/**
	 * Stores each header as key-element pair in an array
	 *
	 * @var array
	 */
	zend_declare_property_null(arango_connection_traceresponse_ce, SL("headers"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Stores HTTP method
	 *
	 * @var int
	 */
	zend_declare_property_null(arango_connection_traceresponse_ce, SL("httpCode"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Stores the string of the body
	 *
	 * @var string
	 */
	zend_declare_property_null(arango_connection_traceresponse_ce, SL("body"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * The time taken to send the request and receive an Response from server
	 *
	 * @var float
	 */
	zend_declare_property_null(arango_connection_traceresponse_ce, SL("timeTaken"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * HTTP message type
	 *
	 * @var string
	 */
	zend_declare_property_string(arango_connection_traceresponse_ce, SL("type"), "request", ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Used to look up the definition for an http code
	 *
	 * @link https://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html
	 * @var array
	 */
	zend_declare_property_null(arango_connection_traceresponse_ce, SL("httpCodeDefinitions"), ZEND_ACC_PRIVATE TSRMLS_CC);

	arango_connection_traceresponse_ce->create_object = zephir_init_properties_Arango_Connection_TraceResponse;
	return SUCCESS;

}

/**
 * Stores each header as key-element pair in an array
 */
PHP_METHOD(Arango_Connection_TraceResponse, getHeaders) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "headers");

}

/**
 * Stores HTTP method
 */
PHP_METHOD(Arango_Connection_TraceResponse, getHttpCode) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "httpCode");

}

/**
 * Stores the string of the body
 */
PHP_METHOD(Arango_Connection_TraceResponse, getBody) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "body");

}

/**
 * The time taken to send the request and receive an Response from server
 */
PHP_METHOD(Arango_Connection_TraceResponse, getTimeTaken) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "timeTaken");

}

/**
 * HTTP message type
 */
PHP_METHOD(Arango_Connection_TraceResponse, getType) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "type");

}

/**
 * Set up the Trace
 *
 * @throws Arango\Exception\ClientException
 *
 * @param array headers    - array with HTTP headers
 * @param int httpCode     - HTTP code
 * @param string body      - request body
 * @param float timeTaken  - time taken to make request and receive an response
 */
PHP_METHOD(Arango_Connection_TraceResponse, __construct) {

	double timeTaken;
	zval body;
	zend_long httpCode;
	zval *headers_param = NULL, *httpCode_param = NULL, *body_param = NULL, *timeTaken_param = NULL, _0, _1, _2;
	zval headers;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&body);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &headers_param, &httpCode_param, &body_param, &timeTaken_param);

	zephir_get_arrval(&headers, headers_param);
	httpCode = zephir_get_intval(httpCode_param);
	zephir_get_strval(&body, body_param);
	timeTaken = zephir_get_doubleval(timeTaken_param);


	zephir_read_property(&_0, this_ptr, SL("httpCodeDefinitions"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, httpCode);
	if (!(zephir_array_key_exists(&_0, &_1 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(arango_exception_clientexception_ce, "Invalid HTTP Code given", "arango/connection/traceresponse.zep", 122);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("headers"), &headers);
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_LONG(&_2, httpCode);
	zephir_update_property_zval(this_ptr, SL("httpCode"), &_2);
	zephir_update_property_zval(this_ptr, SL("body"), &body);
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_DOUBLE(&_2, timeTaken);
	zephir_update_property_zval(this_ptr, SL("timeTaken"), &_2);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get HTTP Code definition
 *
 * @return string
 */
PHP_METHOD(Arango_Connection_TraceResponse, getHttpCodeDefinition) {

	zval _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("httpCodeDefinitions"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, this_ptr, SL("httpCode"), PH_NOISY_CC);
	zephir_array_fetch(&_1, &_0, &_2, PH_NOISY | PH_READONLY, "arango/connection/traceresponse.zep", 137 TSRMLS_CC);
	RETURN_CTOR(&_1);

}

zend_object *zephir_init_properties_Arango_Connection_TraceResponse(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3;
	zval _0, _2, _3$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("httpCodeDefinitions"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 41, 0 TSRMLS_CC);
			add_index_stringl(&_1$$3, 100, SL("Continue"));
			add_index_stringl(&_1$$3, 101, SL("Switching Protocols"));
			add_index_stringl(&_1$$3, 200, SL("OK"));
			add_index_stringl(&_1$$3, 201, SL("Created"));
			add_index_stringl(&_1$$3, 202, SL("Accepted"));
			add_index_stringl(&_1$$3, 203, SL("Non-Authoritative Information"));
			add_index_stringl(&_1$$3, 204, SL("No Content"));
			add_index_stringl(&_1$$3, 205, SL("Reset Content"));
			add_index_stringl(&_1$$3, 206, SL("Partial Content"));
			add_index_stringl(&_1$$3, 300, SL("Multiple Choices"));
			add_index_stringl(&_1$$3, 301, SL("Moved Permanently"));
			add_index_stringl(&_1$$3, 302, SL("Found"));
			add_index_stringl(&_1$$3, 303, SL("See Other"));
			add_index_stringl(&_1$$3, 304, SL("Not Modified"));
			add_index_stringl(&_1$$3, 305, SL("Use Proxy"));
			add_index_stringl(&_1$$3, 307, SL("Temporary Redirect"));
			add_index_stringl(&_1$$3, 400, SL("Bad Request"));
			add_index_stringl(&_1$$3, 401, SL("Unauthorized"));
			add_index_stringl(&_1$$3, 402, SL("Payment Required"));
			add_index_stringl(&_1$$3, 403, SL("Forbidden"));
			add_index_stringl(&_1$$3, 404, SL("Not Found"));
			add_index_stringl(&_1$$3, 405, SL("Method Not Allowed"));
			add_index_stringl(&_1$$3, 406, SL("Not Acceptable"));
			add_index_stringl(&_1$$3, 407, SL("Proxy Authentication Required"));
			add_index_stringl(&_1$$3, 408, SL("Request Timeout"));
			add_index_stringl(&_1$$3, 409, SL("Conflict"));
			add_index_stringl(&_1$$3, 410, SL("Gone"));
			add_index_stringl(&_1$$3, 411, SL("Length Required"));
			add_index_stringl(&_1$$3, 412, SL("Precondition Failed"));
			add_index_stringl(&_1$$3, 413, SL("Request Entity Too Large"));
			add_index_stringl(&_1$$3, 414, SL("Request-URI Too Long"));
			add_index_stringl(&_1$$3, 415, SL("Unsupported Media Type"));
			add_index_stringl(&_1$$3, 416, SL("Requested Range Not Satisfiable"));
			add_index_stringl(&_1$$3, 417, SL("Expectation Failed"));
			add_index_stringl(&_1$$3, 418, SL("I\"m a teapot"));
			add_index_stringl(&_1$$3, 500, SL("Internal Server Error"));
			add_index_stringl(&_1$$3, 501, SL("Not Implemented"));
			add_index_stringl(&_1$$3, 502, SL("Bad Gateway"));
			add_index_stringl(&_1$$3, 503, SL("Service Unavailable"));
			add_index_stringl(&_1$$3, 504, SL("Gateway Timeout"));
			add_index_stringl(&_1$$3, 505, SL("HTTP Version Not Supported"));
			zephir_update_property_zval(this_ptr, SL("httpCodeDefinitions"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("headers"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

