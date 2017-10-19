
extern zend_class_entry *arango_policies_updatepolicy_ce;

ZEPHIR_INIT_CLASS(Arango_Policies_UpdatePolicy);

PHP_METHOD(Arango_Policies_UpdatePolicy, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_policies_updatepolicy_validate, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(arango_policies_updatepolicy_method_entry) {
	PHP_ME(Arango_Policies_UpdatePolicy, validate, arginfo_arango_policies_updatepolicy_validate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
