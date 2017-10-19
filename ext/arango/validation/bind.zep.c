
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/array.h"


/**
 * Container for bind variables
 *
 * @package Arango/Validation
 * @class Bind
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Validation_Bind) {

	ZEPHIR_REGISTER_CLASS(Arango\\Validation, Bind, arango, validation_bind, arango_validation_bind_method_entry, 0);

	/**
	 * Current bind values
	 *
	 * @var array
	 */
	zend_declare_property_null(arango_validation_bind_ce, SL("values"), ZEND_ACC_PRIVATE TSRMLS_CC);

	arango_validation_bind_ce->create_object = zephir_init_properties_Arango_Validation_Bind;
	return SUCCESS;

}

/**
 * Set the value of a single bind variable
 *
 * Allowed value types for bind parameters are string, int,
 * double, bool and array. Arrays must not contain any other
 * than these types.
 *
 * @throws \Arango\Exception\ClientException
 *
 * @param string key
 * @param mixed value
 *
 * @return void
 */
PHP_METHOD(Arango_Validation_Bind, set) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *key_param = NULL, *value = NULL, value_sub, __$null;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &value);

	zephir_get_strval(&key, key_param);
	if (!value) {
		value = &value_sub;
		value = &__$null;
	}


	ZEPHIR_CALL_CE_STATIC(NULL, arango_validation_validation_ce, "validatevalue", &_0, 0, value);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("values"), &key, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get the value of a bind variable with a specific name
 *
 * @param string name
 *
 * @return mixed
 */
PHP_METHOD(Arango_Validation_Bind, get) {

	zval *name_param = NULL, _0, _1, _2;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_key_exists(&_0, &name TSRMLS_CC))) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_1, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_2, &_1, &name, PH_NOISY | PH_READONLY, "arango/validation/bind.zep", 52 TSRMLS_CC);
	RETURN_CTOR(&_2);

}

/**
 * Get the number of bind variables
 *
 * @return int
 */
PHP_METHOD(Arango_Validation_Bind, getCount) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
	RETURN_LONG(zephir_fast_count_int(&_0 TSRMLS_CC));

}

/**
 * Get all bind variables
 *
 * @return array
 */
PHP_METHOD(Arango_Validation_Bind, getAll) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "values");

}

zend_object *zephir_init_properties_Arango_Validation_Bind(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("values"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

