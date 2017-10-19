
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"


/**
 * Validation class
 *
 * @package Arango/Validation
 * @class Validation
 * @abstract
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Validation_Validation) {

	ZEPHIR_REGISTER_CLASS(Arango\\Validation, Validation, arango, validation_validation, arango_validation_validation_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

/**
 * String, integer, float, boolean and null values are allowed.
 * Arrays also are allowed if they contain only one of these types.
 *
 * @throw \Arango\Exception\ClientException if value is not valid
 *
 * @param mixed value
 *
 * @return void
 */
PHP_METHOD(Arango_Validation_Validation, validateValue) {

	zend_bool _0, _1, _3, _4;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, _2, data$$4, *_5$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&data$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	_0 = Z_TYPE_P(value) == IS_STRING;
	if (!(_0)) {
		_0 = Z_TYPE_P(value) == IS_LONG;
	}
	_1 = _0;
	if (!(_1)) {
		ZEPHIR_CALL_FUNCTION(&_2, "is_float", NULL, 86, value);
		zephir_check_call_status();
		_1 = zephir_is_true(&_2);
	}
	_3 = _1;
	if (!(_3)) {
		_3 = (Z_TYPE_P(value) == IS_TRUE || Z_TYPE_P(value) == IS_FALSE);
	}
	_4 = _3;
	if (!(_4)) {
		_4 = Z_TYPE_P(value) == IS_NULL;
	}
	if (_4) {
		RETURN_MM_NULL();
	}
	if (Z_TYPE_P(value) == IS_ARRAY) {
		zephir_is_iterable(value, 0, "arango/validation/validation.zep", 38);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(value), _5$$4)
		{
			ZEPHIR_INIT_NVAR(&data$$4);
			ZVAL_COPY(&data$$4, _5$$4);
			ZEPHIR_CALL_SELF(NULL, "validatevalue", &_6, 0, &data$$4);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&data$$4);
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(arango_exception_clientexception_ce, "Invalid bind parameter value", "arango/validation/validation.zep", 40);
	return;

}

