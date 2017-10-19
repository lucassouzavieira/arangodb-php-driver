
extern zend_class_entry *arango_validation_bind_ce;

ZEPHIR_INIT_CLASS(Arango_Validation_Bind);

PHP_METHOD(Arango_Validation_Bind, set);
PHP_METHOD(Arango_Validation_Bind, get);
PHP_METHOD(Arango_Validation_Bind, getCount);
PHP_METHOD(Arango_Validation_Bind, getAll);
zend_object *zephir_init_properties_Arango_Validation_Bind(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_validation_bind_set, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_validation_bind_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(arango_validation_bind_method_entry) {
	PHP_ME(Arango_Validation_Bind, set, arginfo_arango_validation_bind_set, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Validation_Bind, get, arginfo_arango_validation_bind_get, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Validation_Bind, getCount, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Validation_Bind, getAll, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
