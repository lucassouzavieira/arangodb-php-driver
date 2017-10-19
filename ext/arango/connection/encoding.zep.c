
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
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


/**
 * Assists in checking and validating string encoding
 *
 * @package Arango\Connection
 * @class Encoding
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Connection_Encoding) {

	ZEPHIR_REGISTER_CLASS(Arango\\Connection, Encoding, arango, connection_encoding, arango_connection_encoding_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

/**
 * This function checks that the encoding of a string is utf.
 * It only checks for printable characters.
 *
 * @param string the data to check
 * @return boolean true if string is UTF-8, false if not
 */
PHP_METHOD(Arango_Connection_Encoding, detectUtf) {

	zval *value_param = NULL, _0, _1, _2;
	zval value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	zephir_get_strval(&value, value_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "//u");
	zephir_preg_match(&_1, &_2, &value, &_0, 0, 0 , 0  TSRMLS_CC);
	if (zephir_is_true(&_1)) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * This function checks that the encoding of the keys and
 * values of the array are utf-8, recursively.
 * It will raise an exception if it encounters wrong encoded strings.
 *
 * @throws \Arango\Exception\ClientException
 * @param array $data the data to check
 * @return void
 */
PHP_METHOD(Arango_Connection_Encoding, checkEncoding) {

	zend_bool _4$$5, _11$$5, _15$$3, _20$$3;
	zend_string *_2;
	zend_ulong _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL, *_7 = NULL, *_10 = NULL, *_17 = NULL;
	zval *data_param = NULL, __$true, key, value, *_0, _5$$5, _6$$5, _12$$5, _8$$6, _9$$6, _13$$7, _14$$7, _16$$3, _21$$3, _18$$8, _19$$8, _22$$9, _23$$9;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_21$$3);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_23$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_arrval(&data, data_param);


	zephir_is_iterable(&data, 0, "arango/connection/encoding.zep", 68);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&key, _2);
		} else {
			ZVAL_LONG(&key, _1);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		if (Z_TYPE_P(&value) == IS_ARRAY) {
			ZEPHIR_CALL_SELF(NULL, "checkencoding", &_3, 0, &value);
			zephir_check_call_status();
		}
		if ((zephir_function_exists_ex(SL("mb_detect_encoding") TSRMLS_CC) == SUCCESS)) {
			_4$$5 = Z_TYPE_P(&key) == IS_STRING;
			if (_4$$5) {
				ZEPHIR_INIT_NVAR(&_5$$5);
				ZVAL_STRING(&_5$$5, "UTF-8");
				ZEPHIR_CALL_FUNCTION(&_6$$5, "mb_detect_encoding", &_7, 43, &key, &_5$$5, &__$true);
				zephir_check_call_status();
				_4$$5 = ZEPHIR_IS_FALSE(&_6$$5);
			}
			if (_4$$5) {
				ZEPHIR_INIT_NVAR(&_8$$6);
				object_init_ex(&_8$$6, arango_exception_clientexception_ce);
				ZEPHIR_INIT_LNVAR(_9$$6);
				ZEPHIR_CONCAT_SV(&_9$$6, "Only UTF-8 encoded keys allowed. Wrong encoding in key string: ", &key);
				ZEPHIR_CALL_METHOD(NULL, &_8$$6, "__construct", &_10, 9, &_9$$6);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_8$$6, "arango/connection/encoding.zep", 50 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			_11$$5 = Z_TYPE_P(&value) == IS_STRING;
			if (_11$$5) {
				ZEPHIR_INIT_NVAR(&_5$$5);
				ZVAL_STRING(&_5$$5, "UTF-8");
				ZEPHIR_CALL_FUNCTION(&_12$$5, "mb_detect_encoding", &_7, 43, &value, &_5$$5, &__$true);
				zephir_check_call_status();
				_11$$5 = ZEPHIR_IS_FALSE(&_12$$5);
			}
			if (_11$$5) {
				ZEPHIR_INIT_NVAR(&_13$$7);
				object_init_ex(&_13$$7, arango_exception_clientexception_ce);
				ZEPHIR_INIT_LNVAR(_14$$7);
				ZEPHIR_CONCAT_SV(&_14$$7, "Only UTF-8 encoded values allowed. Wrong encoding in key string: ", &value);
				ZEPHIR_CALL_METHOD(NULL, &_13$$7, "__construct", &_10, 9, &_14$$7);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_13$$7, "arango/connection/encoding.zep", 54 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			continue;
		}
		_15$$3 = Z_TYPE_P(&key) == IS_STRING;
		if (_15$$3) {
			ZEPHIR_CALL_SELF(&_16$$3, "detectutf", &_17, 44, &key);
			zephir_check_call_status();
			_15$$3 = ZEPHIR_IS_FALSE(&_16$$3);
		}
		if (_15$$3) {
			ZEPHIR_INIT_NVAR(&_18$$8);
			object_init_ex(&_18$$8, arango_exception_clientexception_ce);
			ZEPHIR_INIT_LNVAR(_19$$8);
			ZEPHIR_CONCAT_SV(&_19$$8, "Only UTF-8 encoded keys allowed. Wrong encoding in key string: ", &key);
			ZEPHIR_CALL_METHOD(NULL, &_18$$8, "__construct", &_10, 9, &_19$$8);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_18$$8, "arango/connection/encoding.zep", 61 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		_20$$3 = Z_TYPE_P(&value) == IS_STRING;
		if (_20$$3) {
			ZEPHIR_CALL_SELF(&_21$$3, "detectutf", &_17, 44, &value);
			zephir_check_call_status();
			_20$$3 = ZEPHIR_IS_FALSE(&_21$$3);
		}
		if (_20$$3) {
			ZEPHIR_INIT_NVAR(&_22$$9);
			object_init_ex(&_22$$9, arango_exception_clientexception_ce);
			ZEPHIR_INIT_LNVAR(_23$$9);
			ZEPHIR_CONCAT_SV(&_23$$9, "Only UTF-8 encoded values allowed. Wrong encoding in key string: ", &value);
			ZEPHIR_CALL_METHOD(NULL, &_22$$9, "__construct", &_10, 9, &_23$$9);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_22$$9, "arango/connection/encoding.zep", 65 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

/**
 * This is a json_encode() wrapper that also checks if the data is utf-8 conform.
 * internally it calls the check_encoding() method. If that method does not throw
 * an Exception, this method will happily return the json_encoded data.
 *
 * @throws Arango\Exception\ClientException
 *
 * @param array $data    the data to encode
 * @param mixed $options the options for the json_encode() call
 *
 * @return string the result of the json_encode
 */
PHP_METHOD(Arango_Connection_Encoding, jsonWrapper) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *options = NULL, options_sub, response, _0$$3;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&options_sub);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data_param, &options);

	zephir_get_arrval(&data, data_param);
	if (!options) {
		options = &options_sub;
		ZEPHIR_INIT_VAR(options);
		ZVAL_LONG(options, 0);
	}


	ZEPHIR_CALL_SELF(NULL, "checkencoding", NULL, 0, &data);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&data)) {
		ZVAL_LONG(&_0$$3, ((int) (zephir_get_numberval(options)) | 16));
		ZEPHIR_INIT_VAR(&response);
		zephir_json_encode(&response, &data, zephir_get_intval(&_0$$3) );
		RETURN_CCTOR(&response);
	}
	ZEPHIR_INIT_NVAR(&response);
	zephir_json_encode(&response, &data, zephir_get_intval(options) );
	RETURN_CCTOR(&response);

}

