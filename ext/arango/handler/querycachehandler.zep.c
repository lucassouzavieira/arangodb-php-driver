
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
#include "kernel/array.h"
#include "kernel/operators.h"


/**
 * AQL query result cache handling
 *
 * @package Arango/Handler
 * @class QueryCacheHandler
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Handler_QueryCacheHandler) {

	ZEPHIR_REGISTER_CLASS_EX(Arango\\Handler, QueryCacheHandler, arango, handler_querycachehandler, arango_handler_handler_ce, arango_handler_querycachehandler_method_entry, 0);

	return SUCCESS;

}

/**
 * Globally turns on the AQL query result cache
 *
 * @throws \Exception
 */
PHP_METHOD(Arango_Handler_QueryCacheHandler, enable) {

	zval _1, _6;
	zval url, _2, _3, _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_5 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "properties");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "/_api/query-cache");
	ZEPHIR_CALL_CE_STATIC(&url, arango_http_url_ce, "buildurl", &_0, 0, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&_6, SL("mode"), SL("on"));
	ZEPHIR_CALL_CE_STATIC(&_4, arango_connection_encoding_ce, "jsonwrapper", &_5, 0, &_6);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_3, "put", NULL, 0, &url, &_4);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Globally turns off the AQL query result cache
 *
 * @throws \Exception
 */
PHP_METHOD(Arango_Handler_QueryCacheHandler, disable) {

	zval _1, _6;
	zval url, _2, _3, _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_5 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "properties");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "/_api/query-cache");
	ZEPHIR_CALL_CE_STATIC(&url, arango_http_url_ce, "buildurl", &_0, 0, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&_6, SL("mode"), SL("off"));
	ZEPHIR_CALL_CE_STATIC(&_4, arango_connection_encoding_ce, "jsonwrapper", &_5, 0, &_6);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_3, "put", NULL, 0, &url, &_4);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Globally sets the AQL query result cache to demand mode
 *
 * @throws \Exception
 */
PHP_METHOD(Arango_Handler_QueryCacheHandler, enableDemandMode) {

	zval _1, _6;
	zval url, _2, _3, _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_5 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "properties");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "/_api/query-cache");
	ZEPHIR_CALL_CE_STATIC(&url, arango_http_url_ce, "buildurl", &_0, 0, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&_6, SL("mode"), SL("demand"));
	ZEPHIR_CALL_CE_STATIC(&_4, arango_connection_encoding_ce, "jsonwrapper", &_5, 0, &_6);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_3, "put", NULL, 0, &url, &_4);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Adjusts the global AQL query result cache properties
 *
 * @throws \Exception
 *
 * @param array properties - The following properties can be used:
 *                            "maxResults": Maximum number of results that the query cache
 *                                           will ber hold per database
 *                            "mode":  Turns the query result cache on or off or sets it to demand mode
 *                                     Passible values are "on", "off", or "demand"
 *
 * @return void
 */
PHP_METHOD(Arango_Handler_QueryCacheHandler, setProperties) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *properties_param = NULL, url, _1, _2, _3;
	zval properties;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&properties);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &properties_param);

	zephir_get_arrval(&properties, properties_param);


	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "/_api/query-cache");
	ZEPHIR_CALL_CE_STATIC(&url, arango_http_url_ce, "buildurl", &_0, 0, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_3, "delete", NULL, 0, &url);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the AQL query result cache properties
 *
 * @throws \Exception
 *
 * @return array
 */
PHP_METHOD(Arango_Handler_QueryCacheHandler, getProperties) {

	zval url, response, _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/_api/query-cache");
	ZEPHIR_CALL_CE_STATIC(&url, arango_http_url_ce, "buildurl", &_0, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, &_2, "get", NULL, 0, &url);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&response, "toarray", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

