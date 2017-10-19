
extern zend_class_entry *arango_connection_endpoint_ce;

ZEPHIR_INIT_CLASS(Arango_Connection_Endpoint);

PHP_METHOD(Arango_Connection_Endpoint, __construct);
PHP_METHOD(Arango_Connection_Endpoint, __toString);
PHP_METHOD(Arango_Connection_Endpoint, getType);
PHP_METHOD(Arango_Connection_Endpoint, getHost);
PHP_METHOD(Arango_Connection_Endpoint, isValid);
PHP_METHOD(Arango_Connection_Endpoint, listEndpoints);

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_connection_endpoint___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_connection_endpoint_gettype, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_connection_endpoint_gethost, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_connection_endpoint_isvalid, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_connection_endpoint_listendpoints, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, connection, Arango\\Connection\\Connection, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(arango_connection_endpoint_method_entry) {
	PHP_ME(Arango_Connection_Endpoint, __construct, arginfo_arango_connection_endpoint___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Arango_Connection_Endpoint, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Connection_Endpoint, getType, arginfo_arango_connection_endpoint_gettype, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Arango_Connection_Endpoint, getHost, arginfo_arango_connection_endpoint_gethost, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Arango_Connection_Endpoint, isValid, arginfo_arango_connection_endpoint_isvalid, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Arango_Connection_Endpoint, listEndpoints, arginfo_arango_connection_endpoint_listendpoints, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
