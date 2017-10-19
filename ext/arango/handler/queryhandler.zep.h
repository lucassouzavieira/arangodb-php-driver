
extern zend_class_entry *arango_handler_queryhandler_ce;

ZEPHIR_INIT_CLASS(Arango_Handler_QueryHandler);

PHP_METHOD(Arango_Handler_QueryHandler, clearSlow);
PHP_METHOD(Arango_Handler_QueryHandler, getSlow);
PHP_METHOD(Arango_Handler_QueryHandler, getCurrent);
PHP_METHOD(Arango_Handler_QueryHandler, kill);

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_handler_queryhandler_kill, 0, 0, 1)
	ZEND_ARG_INFO(0, queryId)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(arango_handler_queryhandler_method_entry) {
	PHP_ME(Arango_Handler_QueryHandler, clearSlow, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Handler_QueryHandler, getSlow, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Handler_QueryHandler, getCurrent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Handler_QueryHandler, kill, arginfo_arango_handler_queryhandler_kill, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
