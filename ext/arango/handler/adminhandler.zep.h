
extern zend_class_entry *arango_handler_adminhandler_ce;

ZEPHIR_INIT_CLASS(Arango_Handler_AdminHandler);

PHP_METHOD(Arango_Handler_AdminHandler, getServerVersion);
PHP_METHOD(Arango_Handler_AdminHandler, getServerRole);
PHP_METHOD(Arango_Handler_AdminHandler, getServerTime);
PHP_METHOD(Arango_Handler_AdminHandler, getServerLog);
PHP_METHOD(Arango_Handler_AdminHandler, reloadServerRouting);
PHP_METHOD(Arango_Handler_AdminHandler, getServerStatistics);
PHP_METHOD(Arango_Handler_AdminHandler, getServerStatisticsDescription);

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_handler_adminhandler_getserverversion, 0, 0, 0)
	ZEND_ARG_INFO(0, details)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_handler_adminhandler_getserverlog, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_handler_adminhandler_getserverstatisticsdescription, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(arango_handler_adminhandler_method_entry) {
	PHP_ME(Arango_Handler_AdminHandler, getServerVersion, arginfo_arango_handler_adminhandler_getserverversion, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Handler_AdminHandler, getServerRole, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Handler_AdminHandler, getServerTime, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Handler_AdminHandler, getServerLog, arginfo_arango_handler_adminhandler_getserverlog, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Handler_AdminHandler, reloadServerRouting, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Handler_AdminHandler, getServerStatistics, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Handler_AdminHandler, getServerStatisticsDescription, arginfo_arango_handler_adminhandler_getserverstatisticsdescription, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
