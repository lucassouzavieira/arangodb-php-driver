
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
 * A handler that manages queries
 *
 * @package Arango/Handler
 * @class QueryHandler
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Handler_QueryHandler) {

	ZEPHIR_REGISTER_CLASS_EX(Arango\\Handler, QueryHandler, arango, handler_queryhandler, arango_handler_handler_ce, arango_handler_queryhandler_method_entry, 0);

	return SUCCESS;

}

/**
 * Clears the list of slow queries
 *
 * @throws \Exception
 */
PHP_METHOD(Arango_Handler_QueryHandler, clearSlow) {

	zval _1;
	zval url, _2, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "slow");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "/_api/query");
	ZEPHIR_CALL_CE_STATIC(&url, arango_http_url_ce, "buildurl", &_0, 0, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_3, "delete", NULL, 0, &url);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the list of slow queries
 *
 * @throws \Exception
 *
 * @return array
 */
PHP_METHOD(Arango_Handler_QueryHandler, getSlow) {

	zval _1;
	zval url, response, _2, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "slow");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "/_api/query");
	ZEPHIR_CALL_CE_STATIC(&url, arango_http_url_ce, "buildurl", &_0, 0, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, &_3, "get", NULL, 0, &url);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&response, "toarray", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the list of currently executing queries
 *
 * @throws \Exception
 *
 * @return array
 */
PHP_METHOD(Arango_Handler_QueryHandler, getCurrent) {

	zval _1;
	zval url, response, _2, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "current");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "/_api/query");
	ZEPHIR_CALL_CE_STATIC(&url, arango_http_url_ce, "buildurl", &_0, 0, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, &_3, "get", NULL, 0, &url);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&response, "toarray", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Kills a specific query
 *
 * This will send an HTTP DELETE command to server to terminate the query
 *
 * @throws \Exception
 *
 * @return bool
 */
PHP_METHOD(Arango_Handler_QueryHandler, kill) {

	zval _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *queryId_param = NULL, url, response, _2, _3;
	zval queryId;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&queryId);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &queryId_param);

	zephir_get_strval(&queryId, queryId_param);


	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(&_1, &queryId);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "/_api/query");
	ZEPHIR_CALL_CE_STATIC(&url, arango_http_url_ce, "buildurl", &_0, 0, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, &_3, "get", NULL, 0, &url);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);

}

