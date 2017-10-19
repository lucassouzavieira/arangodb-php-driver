
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/exception.h"


/**
 * Abstracts basic request methods for classes
 *
 * @package Arango/Http
 * @interface Request
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Http_Request) {

	ZEPHIR_REGISTER_CLASS(Arango\\Http, Request, arango, http_request, arango_http_request_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_class_implements(arango_http_request_ce TSRMLS_CC, 1, arango_http_executerequest_ce);
	return SUCCESS;

}

/**
 * Issue an HTTP GET request
 *
 * @throws \Exception
 *
 * @param string url - GET URL
 * @param array customHeaders
 *
 * @return Response
 */
PHP_METHOD(Arango_Http_Request, get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval customHeaders;
	zval *url_param = NULL, *customHeaders_param = NULL, response, _0, _1;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&customHeaders);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &url_param, &customHeaders_param);

	zephir_get_strval(&url, url_param);
	if (!customHeaders_param) {
		ZEPHIR_INIT_VAR(&customHeaders);
		array_init(&customHeaders);
	} else {
		zephir_get_arrval(&customHeaders, customHeaders_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "GET");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "");
	ZEPHIR_CALL_METHOD(&response, this_ptr, "executerequest", NULL, 0, &_0, &url, &_1, &customHeaders);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parseresponse", NULL, 0, &response);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Issue an HTTP POST request
 *
 * @throws \Exception
 *
 * @param string url - POST URL
 * @param array customHeaders
 *
 * @return Response
 */
PHP_METHOD(Arango_Http_Request, post) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval customHeaders;
	zval *url_param = NULL, *customHeaders_param = NULL, response, _0, _1;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&customHeaders);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &url_param, &customHeaders_param);

	zephir_get_strval(&url, url_param);
	if (!customHeaders_param) {
		ZEPHIR_INIT_VAR(&customHeaders);
		array_init(&customHeaders);
	} else {
		zephir_get_arrval(&customHeaders, customHeaders_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "POST");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "");
	ZEPHIR_CALL_METHOD(&response, this_ptr, "executerequest", NULL, 0, &_0, &url, &_1, &customHeaders);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parseresponse", NULL, 0, &response);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Issue an HTTP PUT request
 *
 * @throws \Exception
 *
 * @param string url - PUT URL
 * @param array customHeaders
 *
 * @return Response
 */
PHP_METHOD(Arango_Http_Request, put) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval customHeaders;
	zval *url_param = NULL, *customHeaders_param = NULL, response, _0, _1;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&customHeaders);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &url_param, &customHeaders_param);

	zephir_get_strval(&url, url_param);
	if (!customHeaders_param) {
		ZEPHIR_INIT_VAR(&customHeaders);
		array_init(&customHeaders);
	} else {
		zephir_get_arrval(&customHeaders, customHeaders_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "PUT");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "");
	ZEPHIR_CALL_METHOD(&response, this_ptr, "executerequest", NULL, 0, &_0, &url, &_1, &customHeaders);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parseresponse", NULL, 0, &response);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Issue an HTTP HEAD request
 *
 * @throws \Exception
 *
 * @param string url - HEAD URL
 * @param array customHeaders
 *
 * @return Response
 */
PHP_METHOD(Arango_Http_Request, head) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval customHeaders;
	zval *url_param = NULL, *customHeaders_param = NULL, response, _0, _1;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&customHeaders);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &url_param, &customHeaders_param);

	zephir_get_strval(&url, url_param);
	if (!customHeaders_param) {
		ZEPHIR_INIT_VAR(&customHeaders);
		array_init(&customHeaders);
	} else {
		zephir_get_arrval(&customHeaders, customHeaders_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HEAD");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "");
	ZEPHIR_CALL_METHOD(&response, this_ptr, "executerequest", NULL, 0, &_0, &url, &_1, &customHeaders);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parseresponse", NULL, 0, &response);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Issue an HTTP PATCH request
 *
 * @throws \Exception
 *
 * @param string url - PATCH URL
 * @param array customHeaders
 *
 * @return Response
 */
PHP_METHOD(Arango_Http_Request, patch) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval customHeaders;
	zval *url_param = NULL, *customHeaders_param = NULL, response, _0, _1;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&customHeaders);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &url_param, &customHeaders_param);

	zephir_get_strval(&url, url_param);
	if (!customHeaders_param) {
		ZEPHIR_INIT_VAR(&customHeaders);
		array_init(&customHeaders);
	} else {
		zephir_get_arrval(&customHeaders, customHeaders_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "PATCH");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "");
	ZEPHIR_CALL_METHOD(&response, this_ptr, "executerequest", NULL, 0, &_0, &url, &_1, &customHeaders);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parseresponse", NULL, 0, &response);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Issue an HTTP DELETE request
 *
 * @throws \Exception
 *
 * @param string url - DELETE URL
 * @param array customHeaders
 *
 * @return Response
 */
PHP_METHOD(Arango_Http_Request, delete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval customHeaders;
	zval *url_param = NULL, *customHeaders_param = NULL, response, _0, _1;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&customHeaders);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &url_param, &customHeaders_param);

	zephir_get_strval(&url, url_param);
	if (!customHeaders_param) {
		ZEPHIR_INIT_VAR(&customHeaders);
		array_init(&customHeaders);
	} else {
		zephir_get_arrval(&customHeaders, customHeaders_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "DELETE");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "");
	ZEPHIR_CALL_METHOD(&response, this_ptr, "executerequest", NULL, 0, &_0, &url, &_1, &customHeaders);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parseresponse", NULL, 0, &response);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Parse the response
 *
 * Return body values as an associative array
 *
 * @throws \Exception
 *
 * @param Response response - The response as supplied by server
 *
 * @return Response
 */
PHP_METHOD(Arango_Http_Request, parseResponse) {

	zend_bool _0, _1$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *response, response_sub, httpCode, body$$3, _4$$3, _5$$3, exception$$4, _2$$4, _3$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&response_sub);
	ZVAL_UNDEF(&httpCode);
	ZVAL_UNDEF(&body$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&exception$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &response);



	ZEPHIR_CALL_METHOD(&httpCode, response, "getcode", NULL, 0);
	zephir_check_call_status();
	_0 = ZEPHIR_LT_LONG(&httpCode, 200);
	if (!(_0)) {
		_0 = ZEPHIR_GE_LONG(&httpCode, 400);
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(&body$$3, response, "toarray", NULL, 0);
		zephir_check_call_status();
		_1$$3 = ((zephir_fast_count_int(&body$$3 TSRMLS_CC)) ? 1 : 0);
		if (_1$$3) {
			_1$$3 = zephir_array_isset_string(&body$$3, SL("errorMessage"));
		}
		if (_1$$3) {
			ZEPHIR_INIT_VAR(&exception$$4);
			object_init_ex(&exception$$4, arango_exception_serverexception_ce);
			zephir_array_fetch_string(&_2$$4, &body$$3, SL("errorMessage"), PH_NOISY | PH_READONLY, "arango/http/request.zep", 144 TSRMLS_CC);
			zephir_array_fetch_string(&_3$$4, &body$$3, SL("code"), PH_NOISY | PH_READONLY, "arango/http/request.zep", 144 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, &exception$$4, "__construct", NULL, 9, &_2$$4, &_3$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &exception$$4, "setdetails", NULL, 10, &body$$3);
			zephir_check_call_status();
			zephir_throw_exception_debug(&exception$$4, "arango/http/request.zep", 146 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_4$$3);
		object_init_ex(&_4$$3, arango_exception_serverexception_ce);
		ZEPHIR_CALL_METHOD(&_5$$3, response, "getresult", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "__construct", NULL, 9, &_5$$3, &httpCode);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$3, "arango/http/request.zep", 149 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETVAL_ZVAL(response, 1, 0);
	RETURN_MM();

}

