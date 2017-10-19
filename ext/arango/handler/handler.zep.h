
extern zend_class_entry *arango_handler_handler_ce;

ZEPHIR_INIT_CLASS(Arango_Handler_Handler);

PHP_METHOD(Arango_Handler_Handler, __construct);
PHP_METHOD(Arango_Handler_Handler, getConnection);
PHP_METHOD(Arango_Handler_Handler, getConnectionOption);
PHP_METHOD(Arango_Handler_Handler, jsonWrapper);
PHP_METHOD(Arango_Handler_Handler, getCollectionName);

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_handler_handler___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, connection, Arango\\Connection\\Connection, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_handler_handler_getconnectionoption, 0, 0, 1)
	ZEND_ARG_INFO(0, option)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_handler_handler_jsonwrapper, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, body, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_handler_handler_getcollectionname, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(arango_handler_handler_method_entry) {
	PHP_ME(Arango_Handler_Handler, __construct, arginfo_arango_handler_handler___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Arango_Handler_Handler, getConnection, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Arango_Handler_Handler, getConnectionOption, arginfo_arango_handler_handler_getconnectionoption, ZEND_ACC_PROTECTED)
	PHP_ME(Arango_Handler_Handler, jsonWrapper, arginfo_arango_handler_handler_jsonwrapper, ZEND_ACC_PROTECTED)
	PHP_ME(Arango_Handler_Handler, getCollectionName, arginfo_arango_handler_handler_getcollectionname, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
