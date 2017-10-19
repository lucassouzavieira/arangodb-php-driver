
extern zend_class_entry *arango_policies_policyinterface_ce;

ZEPHIR_INIT_CLASS(Arango_Policies_PolicyInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_policies_policyinterface_validate, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(arango_policies_policyinterface_method_entry) {
	ZEND_FENTRY(validate, NULL, arginfo_arango_policies_policyinterface_validate, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
