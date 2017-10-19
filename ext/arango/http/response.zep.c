
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/string.h"


/**
 * Manage HTTP responses from ArangoDB server
 *
 * @package Arango/Http
 * @class Response
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Http_Response) {

	ZEPHIR_REGISTER_CLASS(Arango\\Http, Response, arango, http_response, arango_http_response_method_entry, 0);

	/**
	 * The header retrivied
	 *
	 * @var string
	 */
	zend_declare_property_null(arango_http_response_ce, SL("header"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * The body retrivied
	 *
	 * @var string
	 */
	zend_declare_property_null(arango_http_response_ce, SL("body"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * All headers retrivied as associative array
	 *
	 * @var string
	 */
	zend_declare_property_null(arango_http_response_ce, SL("headers"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * The result status-line
	 *
	 * @var string
	 */
	zend_declare_property_null(arango_http_response_ce, SL("result"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * HTTP status code of the response
	 *
	 * @var string
	 */
	zend_declare_property_null(arango_http_response_ce, SL("httpCode"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 *  Whether or not the response is for an async request without a response body
	 *
	 * @var boolean
	 */
	zend_declare_property_null(arango_http_response_ce, SL("wasAsync"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Whether or not the response is for an async request without a response body
	 *
	 * @var BatchPart
	 */
	zend_declare_property_null(arango_http_response_ce, SL("batchPart"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * HTTP location header
	 */
	zephir_declare_class_constant_string(arango_http_response_ce, SL("HEADER_LOCATION"), "location");

	return SUCCESS;

}

/**
 * Set up the response
 *
 * @throws \Arango\Exception\ClientException
 *
 * @param string response - The complete HTTP response as supplied from server
 * @param string url - The original URL the response is coming from
 * @param string method - The HTTP method that was used when sending data to original URL
 * @param boolean wasAsync - If was an async request
 *
 * @return void
 */
PHP_METHOD(Arango_Http_Response, __construct) {

	zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool wasAsync, _0, _12, _14, _16, _17$$5;
	zval *response_param = NULL, *url_param = NULL, *method_param = NULL, *wasAsync_param = NULL, __$true, __$false, parseMessage, parseHeaders, _4, _5, _7, _8, _9, _10, _11, _13, _15, _1$$4, _18$$6;
	zval response, url, method, _2$$4, _19$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&parseMessage);
	ZVAL_UNDEF(&parseHeaders);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_18$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &response_param, &url_param, &method_param, &wasAsync_param);

	zephir_get_strval(&response, response_param);
	if (!url_param) {
		ZEPHIR_INIT_VAR(&url);
		ZVAL_STRING(&url, "");
	} else {
		zephir_get_strval(&url, url_param);
	}
	if (!method_param) {
		ZEPHIR_INIT_VAR(&method);
		ZVAL_STRING(&method, "");
	} else {
		zephir_get_strval(&method, method_param);
	}
	if (!wasAsync_param) {
		wasAsync = 0;
	} else {
		wasAsync = zephir_get_boolval(wasAsync_param);
	}


	if (wasAsync) {
		zephir_update_property_zval(this_ptr, SL("wasAsync"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("wasAsync"), &__$false);
	}
	_0 = !(Z_TYPE_P(&url) == IS_NULL);
	if (_0) {
		_0 = !(Z_TYPE_P(&method) == IS_NULL);
	}
	if (_0) {
		if (ZEPHIR_IS_STRING(&response, "")) {
			ZEPHIR_INIT_VAR(&_1$$4);
			object_init_ex(&_1$$4, arango_exception_clientexception_ce);
			ZEPHIR_INIT_VAR(&_2$$4);
			ZEPHIR_CONCAT_SVSV(&_2$$4, "Got no response from the server after request to ", &method, " ", &url);
			ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 9, &_2$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$4, "arango/http/response.zep", 89 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_CALL_CE_STATIC(&parseMessage, arango_http_client_ce, "parsehttpmessage", &_3, 0, &response, &url, &method);
	zephir_check_call_status();
	zephir_array_fetch_long(&_4, &parseMessage, 0, PH_NOISY | PH_READONLY, "arango/http/response.zep", 94 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("header"), &_4);
	zephir_array_fetch_long(&_5, &parseMessage, 1, PH_NOISY | PH_READONLY, "arango/http/response.zep", 95 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("body"), &_5);
	zephir_read_property(&_7, this_ptr, SL("header"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_CE_STATIC(&parseHeaders, arango_http_client_ce, "parsehttpheaders", &_6, 0, &_7);
	zephir_check_call_status();
	zephir_array_fetch_long(&_8, &parseHeaders, 0, PH_NOISY | PH_READONLY, "arango/http/response.zep", 98 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("httpCode"), &_8);
	zephir_array_fetch_long(&_9, &parseHeaders, 1, PH_NOISY | PH_READONLY, "arango/http/response.zep", 99 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("result"), &_9);
	zephir_array_fetch_long(&_10, &parseHeaders, 2, PH_NOISY | PH_READONLY, "arango/http/response.zep", 100 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("headers"), &_10);
	zephir_read_property(&_11, this_ptr, SL("body"), PH_NOISY_CC | PH_READONLY);
	_12 = Z_TYPE_P(&_11) == IS_NULL;
	if (_12) {
		zephir_read_property(&_13, this_ptr, SL("httpCode"), PH_NOISY_CC | PH_READONLY);
		_14 = !ZEPHIR_IS_LONG(&_13, 204);
		if (_14) {
			zephir_read_property(&_15, this_ptr, SL("httpCode"), PH_NOISY_CC | PH_READONLY);
			_14 = !ZEPHIR_IS_LONG(&_15, 304);
		}
		_16 = _14;
		if (_16) {
			_16 = !wasAsync;
		}
		_12 = _16;
	}
	if (_12) {
		_17$$5 = !(Z_TYPE_P(&url) == IS_NULL);
		if (_17$$5) {
			_17$$5 = !(Z_TYPE_P(&method) == IS_NULL);
		}
		if (_17$$5) {
			ZEPHIR_INIT_VAR(&_18$$6);
			object_init_ex(&_18$$6, arango_exception_clientexception_ce);
			ZEPHIR_INIT_VAR(&_19$$6);
			ZEPHIR_CONCAT_SVSV(&_19$$6, "Got no response from the server after request to ", &method, " ", &url);
			ZEPHIR_CALL_METHOD(NULL, &_18$$6, "__construct", NULL, 9, &_19$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_18$$6, "arango/http/response.zep", 105 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(arango_exception_clientexception_ce, "Got no response from the server", "arango/http/response.zep", 108);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Return the HTTP status code
 *
 * @return int - HTTP status code
 */
PHP_METHOD(Arango_Http_Response, getCode) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "httpCode");

}

/**
 * Return an individual HTTP headers of the response
 *
 * @param string name - Name of header
 * @return string | null - header value, NULL if header wasn't set in response
 */
PHP_METHOD(Arango_Http_Response, getHeader) {

	zval *name_param = NULL, _0, _1, _2$$3, _3$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strtolower(&_0, &name);
	zephir_get_strval(&name, &_0);
	zephir_read_property(&_1, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, &name)) {
		zephir_read_property(&_2$$3, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_3$$3, &_2$$3, &name, PH_NOISY | PH_READONLY, "arango/http/response.zep", 131 TSRMLS_CC);
		RETURN_CTOR(&_3$$3);
	}
	RETURN_MM_NULL();

}

/**
 * Return the HTTP headers of the response
 *
 * @return array - Array of all headers with values
 */
PHP_METHOD(Arango_Http_Response, getHeaders) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "location");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getheader", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Return the location HTTP header of the response
 *
 * @return string | null - Location header value, NULL if header wasn't set in response
 */
PHP_METHOD(Arango_Http_Response, getLocation) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "location");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getheader", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Return the body of the response
 *
 * @return string - body of the response
 */
PHP_METHOD(Arango_Http_Response, getBody) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "body");

}

/**
 * Return the result line (first header line) of the response
 *
 * @return string - The result line
 */
PHP_METHOD(Arango_Http_Response, getResult) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "result");

}

/**
 * Return the data from the JSON-encoded body
 *
 * @throws \Arango\Exception\ClientException
 * @returns string - JSON-encoded body
 */
PHP_METHOD(Arango_Http_Response, getJson) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "validatebody", NULL, 82);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_MM_MEMBER(getThis(), "body");
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(arango_exception_clientexception_ce, "Got a malformed result from the server", "arango/http/response.zep", 184);
	return;

}

/**
 * Return the data from the JSON-encoded body as associative array
 *
 * @throws \Arango\Exception\ClientException
 * @returns array - Body as array
 */
PHP_METHOD(Arango_Http_Response, toArray) {

	zval __$true, _0, _1$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "validatebody", NULL, 82);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		zephir_read_property(&_1$$3, this_ptr, SL("body"), PH_NOISY_CC | PH_READONLY);
		zephir_json_decode(return_value, &_1$$3, zephir_get_intval(&__$true) );
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(arango_exception_clientexception_ce, "Got a malformed result from the server", "arango/http/response.zep", 198);
	return;

}

/**
 * Validate the body response
 *
 * @returns boolean - True if body is valid, false otherwise
 */
PHP_METHOD(Arango_Http_Response, validateBody) {

	zval __$true, json, _0, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&json);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("body"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&json);
	zephir_json_decode(&json, &_0, zephir_get_intval(&__$true) );
	if (!(Z_TYPE_P(&json) == IS_ARRAY)) {
		zephir_read_property(&_1$$3, this_ptr, SL("wasAsync"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_1$$3)) {
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Set the batchPart of Response
 *
 * @param BatchPart batchPart
 * @return Response
 */
PHP_METHOD(Arango_Http_Response, setBatchPart) {

	zval *batchPart, batchPart_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&batchPart_sub);

	zephir_fetch_params(0, 1, 0, &batchPart);



	zephir_update_property_zval(this_ptr, SL("batchPart"), batchPart);
	RETURN_THISW();

}

