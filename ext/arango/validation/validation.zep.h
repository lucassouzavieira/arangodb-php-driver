
extern zend_class_entry *arango_validation_validation_ce;

ZEPHIR_INIT_CLASS(Arango_Validation_Validation);

PHP_METHOD(Arango_Validation_Validation, validateValue);

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_validation_validation_validatevalue, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(arango_validation_validation_method_entry) {
	PHP_ME(Arango_Validation_Validation, validateValue, arginfo_arango_validation_validation_validatevalue, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
