
extern zend_class_entry *arango_handler_querycachehandler_ce;

ZEPHIR_INIT_CLASS(Arango_Handler_QueryCacheHandler);

PHP_METHOD(Arango_Handler_QueryCacheHandler, enable);
PHP_METHOD(Arango_Handler_QueryCacheHandler, disable);
PHP_METHOD(Arango_Handler_QueryCacheHandler, enableDemandMode);
PHP_METHOD(Arango_Handler_QueryCacheHandler, setProperties);
PHP_METHOD(Arango_Handler_QueryCacheHandler, getProperties);

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_handler_querycachehandler_setproperties, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, properties, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(arango_handler_querycachehandler_method_entry) {
	PHP_ME(Arango_Handler_QueryCacheHandler, enable, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Handler_QueryCacheHandler, disable, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Handler_QueryCacheHandler, enableDemandMode, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Handler_QueryCacheHandler, setProperties, arginfo_arango_handler_querycachehandler_setproperties, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Handler_QueryCacheHandler, getProperties, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
