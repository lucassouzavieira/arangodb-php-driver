
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
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/memory.h"


/**
 * Validate an supplied update policy value
 *
 * @package Arango/Policies
 * @class UpdatePolicy
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Policies_UpdatePolicy) {

	ZEPHIR_REGISTER_CLASS(Arango\\Policies, UpdatePolicy, arango, policies_updatepolicy, arango_policies_updatepolicy_method_entry, 0);

	zephir_declare_class_constant_string(arango_policies_updatepolicy_ce, SL("LAST"), "last");

	zephir_declare_class_constant_string(arango_policies_updatepolicy_ce, SL("ERROR"), "error");

	zend_class_implements(arango_policies_updatepolicy_ce TSRMLS_CC, 1, arango_policies_policy_ce);
	return SUCCESS;

}

/**
 * Validate a supplied policy value
 *
 * @throws \Arango\Exception\ClientException
 * @param string value
 * @return void
 */
PHP_METHOD(Arango_Policies_UpdatePolicy, validate) {

	zend_bool _0;
	zval *value_param = NULL;
	zval value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	zephir_get_strval(&value, value_param);


	_0 = !ZEPHIR_IS_STRING(&value, "last");
	if (_0) {
		_0 = !ZEPHIR_IS_STRING(&value, "error");
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(arango_exception_clientexception_ce, "Invalid policy", "arango/policies/updatepolicy.zep", 30);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

