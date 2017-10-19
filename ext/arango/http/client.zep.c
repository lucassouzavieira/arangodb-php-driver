
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
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/file.h"


/**
 * HTTP Client to Arango PHP Driver
 *
 * @package Arango/Http
 * @abstract
 * @class Client
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Http_Client) {

	ZEPHIR_REGISTER_CLASS(Arango\\Http, Client, arango, http_client, arango_http_client_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * HTTP method constants
	 */
	zephir_declare_class_constant_string(arango_http_client_ce, SL("GET"), "GET");

	zephir_declare_class_constant_string(arango_http_client_ce, SL("POST"), "POST");

	zephir_declare_class_constant_string(arango_http_client_ce, SL("PUT"), "PUT");

	zephir_declare_class_constant_string(arango_http_client_ce, SL("DELETE"), "DELETE");

	zephir_declare_class_constant_string(arango_http_client_ce, SL("HEAD"), "HEAD");

	zephir_declare_class_constant_string(arango_http_client_ce, SL("PATCH"), "PATCH");

	/**
	 * Number of bytes processed in one batch
	 */
	zephir_declare_class_constant_long(arango_http_client_ce, SL("CHUNK_SIZE"), 8192);

	/**
	 * End of line mark used in HTTP
	 */
	zephir_declare_class_constant_string(arango_http_client_ce, SL("EOL"), "\r\n");

	/**
	 * Separator between header and body
	 */
	zephir_declare_class_constant_string(arango_http_client_ce, SL("SEPARATOR"), "\r\n\r\n");

	/**
	 * HTTP protocol version used, hard-coded to version 1.1
	 */
	zephir_declare_class_constant_string(arango_http_client_ce, SL("PROTOCOL"), "HTTP/1.1");

	/**
	 * Boundary string for batch request parts
	 */
	zephir_declare_class_constant_string(arango_http_client_ce, SL("MIME_BOUNDARY"), "XXXsubpartXXX");

	/**
	 * HTTP Header for making an operation asynchronous
	 */
	zephir_declare_class_constant_string(arango_http_client_ce, SL("ASYNC_HEADER"), "X-Arango-Async");

	return SUCCESS;

}

/**
 * Validate an HTTP method request name
 *
 * @throws \Arango\Exception\ClientException
 * @param string method - method name
 * @return boolean - always true - throw an exception if method is not valid
 */
PHP_METHOD(Arango_Http_Client, validateMethod) {

	zval methods;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, _0;
	zval method, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&methods);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &method_param);

	zephir_get_strval(&method, method_param);


	ZEPHIR_INIT_VAR(&methods);
	zephir_create_array(&methods, 6, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "GET");
	zephir_array_fast_append(&methods, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "PUT");
	zephir_array_fast_append(&methods, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "POST");
	zephir_array_fast_append(&methods, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "DELETE");
	zephir_array_fast_append(&methods, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "HEAD");
	zephir_array_fast_append(&methods, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "PATCH");
	zephir_array_fast_append(&methods, &_0);
	if (zephir_fast_in_array(&method, &methods TSRMLS_CC)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_NVAR(&_0);
	object_init_ex(&_0, arango_exception_clientexception_ce);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SV(&_1, "Invalid request method:  ", &method);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 9, &_1);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "arango/http/client.zep", 77 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Splits an http message into its header and body
 *
 * @param string httpMessage  HTTP message
 * @return array
 */
PHP_METHOD(Arango_Http_Client, parseHttpMessage) {

	zval *httpMessage_param = NULL, _0;
	zval httpMessage;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&httpMessage);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &httpMessage_param);

	zephir_get_strval(&httpMessage, httpMessage_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "\r\n\r\n");
	zephir_fast_explode(return_value, &_0, &httpMessage, 2  TSRMLS_CC);
	RETURN_MM();

}

/**
 * Process a string of HTTP headers into an array of header => values
 *
 * @param string headers  HTTP header
 * @return array
 */
PHP_METHOD(Arango_Http_Client, parseHttpHeaders) {

	zend_string *_4;
	zend_ulong _3;
	zval processed;
	zend_long httpCode = 0;
	zval *headers_param = NULL, result, lineNumber, line, _0, _1, *_2, _11, key$$3, value$$3, elements$$3, _8$$3, _9$$3, _10$$3, matches$$4, _5$$4, _6$$4, _7$$5;
	zval headers;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&lineNumber);
	ZVAL_UNDEF(&line);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&key$$3);
	ZVAL_UNDEF(&value$$3);
	ZVAL_UNDEF(&elements$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&matches$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&processed);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &headers_param);

	zephir_get_strval(&headers, headers_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "\r\n");
	zephir_fast_explode(&_0, &_1, &headers, LONG_MAX TSRMLS_CC);
	zephir_is_iterable(&_0, 0, "arango/http/client.zep", 131);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _3, _4, _2)
	{
		ZEPHIR_INIT_NVAR(&lineNumber);
		if (_4 != NULL) { 
			ZVAL_STR_COPY(&lineNumber, _4);
		} else {
			ZVAL_LONG(&lineNumber, _3);
		}
		ZEPHIR_INIT_NVAR(&line);
		ZVAL_COPY(&line, _2);
		if (ZEPHIR_IS_LONG(&lineNumber, 0)) {
			ZEPHIR_INIT_NVAR(&_5$$4);
			ZEPHIR_INIT_NVAR(&_6$$4);
			ZVAL_STRING(&_6$$4, "/^HTTP\\/\\d+\\.\\d+\\s+(\\d+)/");
			zephir_preg_match(&_5$$4, &_6$$4, &line, &matches$$4, 0, 0 , 0  TSRMLS_CC);
			if (zephir_is_true(&_5$$4)) {
				ZEPHIR_OBS_NVAR(&_7$$5);
				zephir_array_fetch_long(&_7$$5, &matches$$4, 1, PH_NOISY, "arango/http/client.zep", 111 TSRMLS_CC);
				httpCode = zephir_get_intval(&_7$$5);
			}
			ZEPHIR_CPY_WRT(&result, &line);
			continue;
		}
		ZEPHIR_INIT_NVAR(&_8$$3);
		ZVAL_STRING(&_8$$3, ": ");
		ZEPHIR_INIT_NVAR(&_9$$3);
		zephir_fast_strpos(&_9$$3, &line, &_8$$3, 0 );
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&_9$$3)) {
			ZEPHIR_INIT_NVAR(&elements$$3);
			zephir_fast_explode_str(&elements$$3, SL(": "), &line, 2  TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(&elements$$3);
			zephir_fast_explode_str(&elements$$3, SL(":"), &line, 2  TSRMLS_CC);
		}
		ZEPHIR_OBS_NVAR(&key$$3);
		zephir_array_fetch_long(&key$$3, &elements$$3, 0, PH_NOISY, "arango/http/client.zep", 125 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&value$$3);
		zephir_array_fetch_long(&value$$3, &elements$$3, 1, PH_NOISY, "arango/http/client.zep", 126 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_10$$3);
		zephir_fast_strtolower(&_10$$3, &key$$3);
		zephir_array_update_zval(&processed, &_10$$3, &value$$3, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&line);
	ZEPHIR_INIT_NVAR(&lineNumber);
	zephir_create_array(return_value, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_LONG(&_11, httpCode);
	zephir_array_fast_append(return_value, &_11);
	zephir_array_fast_append(return_value, &result);
	zephir_array_fast_append(return_value, &processed);
	RETURN_MM();

}

/**
 * Create a one-time HTTP connection by opening a socket to the server
 * It is the caller's responsibility to close the socket
 *
 * @throws \Arango\Exception\ConnectionException | \Exception
 * @param Options options - Connection options
 * @return resource - socket with server connection
 */
PHP_METHOD(Arango_Http_Client, createConnection) {

	zephir_fcall_cache_entry *_1 = NULL, *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options, options_sub, endpoint, context, socketResource, error, message, _0, _11, _12, _13, _17, _2$$3, _3$$3, _4$$3, _6$$3, _7$$3, _8$$4, _9$$4, _10$$4, _14$$5, _15$$5, _16$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options_sub);
	ZVAL_UNDEF(&endpoint);
	ZVAL_UNDEF(&context);
	ZVAL_UNDEF(&socketResource);
	ZVAL_UNDEF(&error);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options);



	ZEPHIR_OBS_VAR(&endpoint);
	zephir_array_fetch_string(&endpoint, options, SL("endpoint"), PH_NOISY, "arango/http/client.zep", 149 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&context, "stream_context_create", NULL, 76);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_0, arango_connection_endpoint_ce, "gettype", &_1, 0, &endpoint);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING_IDENTICAL(&_0, "ssl")) {
		zephir_array_fetch_string(&_2$$3, options, SL("verifyCert"), PH_NOISY | PH_READONLY, "arango/http/client.zep", 154 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "ssl");
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "verify_peer");
		ZEPHIR_CALL_FUNCTION(NULL, "stream_context_set_option", &_5, 77, &context, &_3$$3, &_4$$3, &_2$$3);
		zephir_check_call_status();
		zephir_array_fetch_string(&_6$$3, options, SL("allowSelfSigned"), PH_NOISY | PH_READONLY, "arango/http/client.zep", 155 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "ssl");
		ZEPHIR_INIT_NVAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "allow_self_signed");
		ZEPHIR_CALL_FUNCTION(NULL, "stream_context_set_option", &_5, 77, &context, &_3$$3, &_4$$3, &_6$$3);
		zephir_check_call_status();
		zephir_array_fetch_string(&_7$$3, options, SL("ciphers"), PH_NOISY | PH_READONLY, "arango/http/client.zep", 157 TSRMLS_CC);
		if (!(Z_TYPE_P(&_7$$3) == IS_NULL)) {
			zephir_array_fetch_string(&_8$$4, options, SL("ciphers"), PH_NOISY | PH_READONLY, "arango/http/client.zep", 158 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_9$$4);
			ZVAL_STRING(&_9$$4, "ssl");
			ZEPHIR_INIT_VAR(&_10$$4);
			ZVAL_STRING(&_10$$4, "ciphers");
			ZEPHIR_CALL_FUNCTION(NULL, "stream_context_set_option", &_5, 77, &context, &_9$$4, &_10$$4, &_8$$4);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_METHOD(&_11, options, "getendpoint", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_string(&_12, options, SL("timeout"), PH_NOISY | PH_READONLY, "arango/http/client.zep", 166 TSRMLS_CC);
	ZVAL_LONG(&_13, 4);
	ZEPHIR_MAKE_REF(&error);
	ZEPHIR_MAKE_REF(&message);
	ZEPHIR_CALL_FUNCTION(&socketResource, "stream_socket_client", NULL, 78, &_11, &error, &message, &_12, &_13, &context);
	ZEPHIR_UNREF(&error);
	ZEPHIR_UNREF(&message);
	zephir_check_call_status();
	if (!zephir_is_true(&socketResource)) {
		ZEPHIR_INIT_VAR(&_14$$5);
		object_init_ex(&_14$$5, arango_exception_connectionexception_ce);
		zephir_array_fetch_string(&_15$$5, options, SL("endpoint"), PH_NOISY | PH_READONLY, "arango/http/client.zep", 172 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_16$$5);
		ZEPHIR_CONCAT_SVSVV(&_16$$5, "Cannot connect to endpoint \\ ", &_15$$5, " \\: ", &message, &error);
		ZEPHIR_CALL_METHOD(NULL, &_14$$5, "__construct", NULL, 9, &_16$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_14$$5, "arango/http/client.zep", 172 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_fetch_string(&_17, options, SL("timeout"), PH_NOISY | PH_READONLY, "arango/http/client.zep", 175 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "stream_set_timeout", NULL, 33, &socketResource, &_17);
	zephir_check_call_status();
	RETURN_CCTOR(&socketResource);

}

/**
 * Create a request string (header and body)
 *
 * @param Options options - Connection options
 * @param string header - Pre-assembled header string for connection
 * @param string method - HTTP method
 * @param string url - HTTP url
 * @param string body - Optional body to post
 * @param array customHeaders - Any array containing header elements
 *
 * @throws \Arango\Exception\ClientException
 * @return string - Assembled HTTP request string
 */
PHP_METHOD(Arango_Http_Client, buildRequest) {

	zend_bool _2$$3;
	zend_string *_7;
	zend_ulong _6;
	zephir_fcall_cache_entry *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval customHeaders;
	zval header, method, url, body, _0, _4$$4;
	zval *options, options_sub, *header_param = NULL, *method_param = NULL, *url_param = NULL, *body_param = NULL, *customHeaders_param = NULL, lenght, contentType, customHeader, request, _1, headerKey, headerValue, *_5, _9, _10, _12, _13, _3$$3, _8$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options_sub);
	ZVAL_UNDEF(&lenght);
	ZVAL_UNDEF(&contentType);
	ZVAL_UNDEF(&customHeader);
	ZVAL_UNDEF(&request);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&headerKey);
	ZVAL_UNDEF(&headerValue);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&header);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&body);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&customHeaders);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 6, 0, &options, &header_param, &method_param, &url_param, &body_param, &customHeaders_param);

	zephir_get_strval(&header, header_param);
	zephir_get_strval(&method, method_param);
	zephir_get_strval(&url, url_param);
	zephir_get_strval(&body, body_param);
	zephir_get_arrval(&customHeaders, customHeaders_param);


	ZEPHIR_CALL_SELF(NULL, "validatemethod", NULL, 0, &method);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&lenght);
	ZVAL_LONG(&lenght, zephir_fast_strlen_ev(&body));
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SSS(&_0, "Content-Type: multipart/form-data; boundary=", "XXXsubpartXXX", "\r\n");
	ZEPHIR_CPY_WRT(&contentType, &_0);
	zephir_array_fetch_string(&_1, options, SL("Batch"), PH_NOISY | PH_READONLY, "arango/http/client.zep", 206 TSRMLS_CC);
	if (!zephir_is_true(&_1)) {
		ZEPHIR_INIT_NVAR(&contentType);
		ZVAL_STRING(&contentType, "");
		_2$$3 = ZEPHIR_GT_LONG(&lenght, 0);
		if (_2$$3) {
			zephir_array_fetch_string(&_3$$3, options, SL("BatchPart"), PH_NOISY | PH_READONLY, "arango/http/client.zep", 209 TSRMLS_CC);
			_2$$3 = ZEPHIR_IS_FALSE(&_3$$3);
		}
		if (_2$$3) {
			ZEPHIR_INIT_VAR(&_4$$4);
			ZEPHIR_CONCAT_SS(&_4$$4, "Content-Type: application/json", "\r\n");
			ZEPHIR_CPY_WRT(&contentType, &_4$$4);
		}
	}
	ZEPHIR_INIT_VAR(&customHeader);
	ZVAL_STRING(&customHeader, "");
	zephir_is_iterable(&customHeaders, 0, "arango/http/client.zep", 223);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&customHeaders), _6, _7, _5)
	{
		ZEPHIR_INIT_NVAR(&headerKey);
		if (_7 != NULL) { 
			ZVAL_STR_COPY(&headerKey, _7);
		} else {
			ZVAL_LONG(&headerKey, _6);
		}
		ZEPHIR_INIT_NVAR(&headerValue);
		ZVAL_COPY(&headerValue, _5);
		ZEPHIR_INIT_LNVAR(_8$$5);
		ZEPHIR_CONCAT_VVSVS(&_8$$5, &customHeader, &headerKey, ": ", &headerValue, "\r\n");
		ZEPHIR_CPY_WRT(&customHeader, &_8$$5);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&headerValue);
	ZEPHIR_INIT_NVAR(&headerKey);
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "%s %s %s");
	ZEPHIR_INIT_VAR(&_10);
	ZVAL_STRING(&_10, "HTTP/1.1");
	ZEPHIR_CALL_FUNCTION(&request, "sprintf", &_11, 34, &_9, &method, &url, &_10);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_12);
	ZEPHIR_CONCAT_VVVV(&_12, &request, &header, &customHeader, &contentType);
	ZEPHIR_CPY_WRT(&request, &_12);
	ZEPHIR_INIT_NVAR(&_9);
	ZVAL_STRING(&_9, "Content-Length: %s");
	ZEPHIR_CALL_FUNCTION(&_13, "sprintf", &_11, 34, &_9, &lenght);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_12);
	ZEPHIR_CONCAT_VVSS(&_12, &request, &_13, "\r\n", "\r\n");
	ZEPHIR_CPY_WRT(&request, &_12);
	ZEPHIR_INIT_LNVAR(_12);
	ZEPHIR_CONCAT_VV(&_12, &request, &body);
	ZEPHIR_CPY_WRT(&request, &_12);
	RETURN_CCTOR(&request);

}

/**
 * Execute an HTTP request on an opened socket
 *
 * It is the caller's responsibility to close the socket
 *
 * @param resource socket - Connection socket
 * @param string request - HTTP request as a string
 * @param string method - HTTP method used
 *
 * @throws \Arango\Exception\ClientException
 * @return string - HTTP response string
 */
PHP_METHOD(Arango_Http_Client, transfer) {

	zend_bool first, _0, _3$$4, _12$$4, _17$$11;
	zephir_fcall_cache_entry *_2 = NULL, *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, totalRead, contentLenghtPosition, _16$$12;
	zval request, method;
	zval *socket, socket_sub, *request_param = NULL, *method_param = NULL, contentLenght, expectedLenght, result, read, _1$$4, _4$$7, position$$8, _5$$8, _6$$8, _8$$9, _9$$9, _10$$9, _11$$9, bodyStart$$11, _13$$11, _14$$11, _15$$12;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&socket_sub);
	ZVAL_UNDEF(&contentLenght);
	ZVAL_UNDEF(&expectedLenght);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&read);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&position$$8);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&bodyStart$$11);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&request);
	ZVAL_UNDEF(&method);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &socket, &request_param, &method_param);

	zephir_get_strval(&request, request_param);
	zephir_get_strval(&method, method_param);


	ZEPHIR_INIT_VAR(&contentLenght);
	ZVAL_NULL(&contentLenght);
	ZEPHIR_INIT_VAR(&expectedLenght);
	ZVAL_NULL(&expectedLenght);
	totalRead = 0;
	contentLenghtPosition = 0;
	ZEPHIR_INIT_VAR(&result);
	ZVAL_STRING(&result, "");
	first = 1;
	if (!(Z_TYPE_P(socket) == IS_RESOURCE)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(arango_exception_clientexception_ce, "Invalid socket used", "arango/http/client.zep", 250);
		return;
	}
	zephir_fwrite(NULL, socket, &request TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "fflush", NULL, 79, socket);
	zephir_check_call_status();
	while (1) {
		_0 = first;
		if (!(_0)) {
			_0 = !(zephir_feof(socket TSRMLS_CC));
		}
		if (!(_0)) {
			break;
		}
		ZVAL_LONG(&_1$$4, 8192);
		ZEPHIR_CALL_FUNCTION(&read, "fread", &_2, 80, socket, &_1$$4);
		zephir_check_call_status();
		_3$$4 = ZEPHIR_IS_FALSE(&read);
		if (!(_3$$4)) {
			_3$$4 = ZEPHIR_IS_STRING(&read, "");
		}
		if (_3$$4) {
			break;
		}
		totalRead = (totalRead + zephir_fast_strlen_ev(&read));
		if (first) {
			ZEPHIR_CPY_WRT(&result, &read);
			first = 0;
		} else {
			ZEPHIR_INIT_LNVAR(_4$$7);
			ZEPHIR_CONCAT_VV(&_4$$7, &result, &read);
			ZEPHIR_CPY_WRT(&result, &_4$$7);
		}
		if (Z_TYPE_P(&contentLenght) == IS_NULL) {
			ZEPHIR_INIT_NVAR(&_5$$8);
			ZVAL_STRING(&_5$$8, "content-lenght");
			ZVAL_LONG(&_6$$8, 12);
			ZEPHIR_CALL_FUNCTION(&position$$8, "stripos", &_7, 81, &result, &_5$$8, &_6$$8);
			zephir_check_call_status();
			if (!ZEPHIR_IS_FALSE(&position$$8)) {
				ZEPHIR_INIT_NVAR(&_8$$9);
				ZVAL_STRING(&_8$$9, "content-length: ");
				ZVAL_LONG(&_9$$9, (zephir_get_numberval(&position$$8) + zephir_fast_strlen_ev(&_8$$9)));
				ZVAL_LONG(&_10$$9, 10);
				ZEPHIR_INIT_NVAR(&_11$$9);
				zephir_substr(&_11$$9, &result, zephir_get_intval(&_9$$9), 10 , 0);
				ZEPHIR_INIT_NVAR(&contentLenght);
				ZVAL_LONG(&contentLenght, zephir_get_intval(&_11$$9));
				contentLenghtPosition = (zephir_get_numberval(&position$$8) + 17);
				if (ZEPHIR_IS_STRING(&method, "HEAD")) {
					ZEPHIR_INIT_NVAR(&contentLenght);
					ZVAL_LONG(&contentLenght, 0);
				}
			}
		}
		_12$$4 = Z_TYPE_P(&contentLenght) != IS_NULL;
		if (_12$$4) {
			_12$$4 = Z_TYPE_P(&expectedLenght) == IS_NULL;
		}
		if (_12$$4) {
			ZEPHIR_INIT_NVAR(&_13$$11);
			ZVAL_STRING(&_13$$11, "\r\n\r\n");
			ZVAL_LONG(&_14$$11, contentLenghtPosition);
			ZEPHIR_INIT_NVAR(&bodyStart$$11);
			zephir_fast_strpos(&bodyStart$$11, &result, &_13$$11, zephir_get_intval(&_14$$11) );
			if (!ZEPHIR_IS_FALSE(&bodyStart$$11)) {
				ZEPHIR_INIT_NVAR(&_15$$12);
				ZVAL_STRING(&_15$$12, "\r\n\r\n");
				_16$$12 = (zephir_get_numberval(&bodyStart$$11) + zephir_fast_strlen_ev(&_15$$12));
				ZEPHIR_INIT_NVAR(&bodyStart$$11);
				ZVAL_LONG(&bodyStart$$11, _16$$12);
				ZEPHIR_INIT_NVAR(&expectedLenght);
				zephir_add_function(&expectedLenght, &bodyStart$$11, &contentLenght);
			}
			_17$$11 = Z_TYPE_P(&expectedLenght) != IS_NULL;
			if (_17$$11) {
				_17$$11 = ZEPHIR_LE_LONG(&expectedLenght, totalRead);
			}
			if (_17$$11) {
				break;
			}
		}
	}
	RETURN_CCTOR(&result);

}

/**
 * Validate the method name
 *
 * @param string method
 *
 * @return boolean
 */
PHP_METHOD(Arango_Http_Client, isValidMethod) {

	zval _0;
	zval *method_param = NULL, _1;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &method_param);

	zephir_get_strval(&method, method_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 6, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "GET");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "POST");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "PUT");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "DELETE");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "HEAD");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "PATCH");
	zephir_array_fast_append(&_0, &_1);
	RETURN_MM_BOOL(zephir_fast_in_array(&method, &_0 TSRMLS_CC));

}

