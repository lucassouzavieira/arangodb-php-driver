
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
#include "kernel/string.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"


/**
 * Helper class to manage URLs
 *
 * @package Arango/Http
 * @class Url
 * @abstract
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Http_Url) {

	ZEPHIR_REGISTER_CLASS(Arango\\Http, Url, arango, http_url, arango_http_url_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

/**
 * Get the document Id from a location header
 *
 * @param string location - HTTP response location header
 *
 * @return string | null - Document id parsed or null if location is not valid
 */
PHP_METHOD(Arango_Http_Url, getDocumentIdFromLocation) {

	zend_bool _6, _2$$3, _5$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *location_param = NULL, parts, collection, id, _0, _1, _3, _4, _7$$8;
	zval location;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&location);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &location_param);

	zephir_get_strval(&location, location_param);


	ZEPHIR_INIT_VAR(&parts);
	zephir_fast_explode_str(&parts, SL("/"), &location, LONG_MAX TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "/_db/");
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strpos(&_1, &location, &_0, 0 );
	if (ZEPHIR_IS_LONG(&_1, 0)) {
		_2$$3 = zephir_array_isset_long(&parts, 4);
		if (_2$$3) {
			_2$$3 = zephir_array_isset_long(&parts, 5);
		}
		if (_2$$3) {
			ZEPHIR_OBS_VAR(&collection);
			zephir_array_fetch_long(&collection, &parts, 4, PH_NOISY, "arango/http/url.zep", 28 TSRMLS_CC);
			ZEPHIR_OBS_VAR(&id);
			zephir_array_fetch_long(&id, &parts, 5, PH_NOISY, "arango/http/url.zep", 29 TSRMLS_CC);
		}
	}
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "/_api/");
	ZEPHIR_INIT_VAR(&_4);
	zephir_fast_strpos(&_4, &location, &_3, 0 );
	if (ZEPHIR_IS_LONG(&_4, 0)) {
		_5$$5 = zephir_array_isset_long(&parts, 2);
		if (_5$$5) {
			_5$$5 = zephir_array_isset_long(&parts, 3);
		}
		if (_5$$5) {
			ZEPHIR_OBS_NVAR(&collection);
			zephir_array_fetch_long(&collection, &parts, 2, PH_NOISY, "arango/http/url.zep", 36 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&id);
			zephir_array_fetch_long(&id, &parts, 3, PH_NOISY, "arango/http/url.zep", 37 TSRMLS_CC);
		}
	}
	_6 = !(Z_TYPE_P(&collection) == IS_NULL);
	if (_6) {
		_6 = !(Z_TYPE_P(&id) == IS_NULL);
	}
	if (_6) {
		if (Z_TYPE_P(&id) == IS_STRING) {
			ZEPHIR_CALL_FUNCTION(&_7$$8, "urldecode", NULL, 83, &id);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&id, &_7$$8);
		}
		ZEPHIR_CONCAT_VSV(return_value, &collection, "/", &id);
		RETURN_MM();
	}
	RETURN_MM_NULL();

}

/**
 * Construct a URL from a base URL and additional parts, separated with "/" each
 *
 * @param string url  - Base URL
 * @param array parts - URL parts to append
 *
 * @return string     - Assembled URL
 */
PHP_METHOD(Arango_Http_Url, buildUrl) {

	zend_string *_3;
	zend_ulong _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_8 = NULL;
	zval parts;
	zval *url_param = NULL, *parts_param = NULL, baseUrl, part, _0, *_1, _4$$3, _5$$3, _7$$3, _9$$3, _6$$4;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&baseUrl);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&parts);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &url_param, &parts_param);

	zephir_get_strval(&url, url_param);
	if (!parts_param) {
		ZEPHIR_INIT_VAR(&parts);
		array_init(&parts);
	} else {
		zephir_get_arrval(&parts, parts_param);
	}


	ZEPHIR_CPY_WRT(&baseUrl, &url);
	ZEPHIR_INIT_VAR(&_0);
	zephir_is_iterable(&parts, 0, "arango/http/url.zep", 74);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&parts), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&_0);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&_0, _3);
		} else {
			ZVAL_LONG(&_0, _2);
		}
		ZEPHIR_INIT_NVAR(&part);
		ZVAL_COPY(&part, _1);
		ZEPHIR_INIT_NVAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "/");
		ZEPHIR_INIT_NVAR(&_5$$3);
		zephir_fast_strpos(&_5$$3, &part, &_4$$3, 0 );
		if (!ZEPHIR_IS_FALSE(&_5$$3)) {
			ZEPHIR_INIT_NVAR(&_6$$4);
			zephir_fast_explode_str(&_6$$4, SL("/"), &part, LONG_MAX TSRMLS_CC);
			ZEPHIR_CPY_WRT(&part, &_6$$4);
		}
		ZEPHIR_CALL_FUNCTION(&_7$$3, "urlencode", &_8, 36, &part);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_9$$3);
		ZEPHIR_CONCAT_VSV(&_9$$3, &baseUrl, "/", &_7$$3);
		ZEPHIR_CPY_WRT(&baseUrl, &_9$$3);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&part);
	ZEPHIR_INIT_NVAR(&_0);
	RETURN_CCTOR(&baseUrl);

}

/**
 * Append parameters to a URL.
 * Parameters values will be URL-encoded
 *
 * @param string url    - Base URL
 * @param array params  - An array of parameters
 *
 * @return string
 */
PHP_METHOD(Arango_Http_Url, appendParamsToUrl) {

	zend_string *_3;
	zend_ulong _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_5 = NULL;
	zval params;
	zval *url_param = NULL, *params_param = NULL, value, _0, *_1, _6, _4$$4;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&params);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &url_param, &params_param);

	zephir_get_strval(&url, url_param);
	zephir_get_arrval(&params, params_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_is_iterable(&params, 0, "arango/http/url.zep", 95);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&params), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&_0);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&_0, _3);
		} else {
			ZVAL_LONG(&_0, _2);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _1);
		if ((Z_TYPE_P(&value) == IS_TRUE || Z_TYPE_P(&value) == IS_FALSE)) {
			ZEPHIR_CALL_SELF(&_4$$4, "getboolstring", &_5, 84, &value);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&value, &_4$$4);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_CALL_FUNCTION(&_6, "http_build_query", NULL, 85, &params);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSV(return_value, &url, "?", &_6);
	RETURN_MM();

}

/**
 * Get a boolean string from an value
 *
 * @param mixed value
 *
 * @return string - "true" if value evaluates to true, "false" otherwise
 */
PHP_METHOD(Arango_Http_Url, getBoolString) {

	zval *value, value_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	ZEPHIR_INIT_VAR(&_0);
	if (zephir_is_true(value)) {
		ZVAL_STRING(&_0, "true");
	} else {
		ZVAL_STRING(&_0, "false");
	}
	RETURN_CCTOR(&_0);

}

