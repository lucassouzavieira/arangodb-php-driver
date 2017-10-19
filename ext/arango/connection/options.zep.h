
extern zend_class_entry *arango_connection_options_ce;

ZEPHIR_INIT_CLASS(Arango_Connection_Options);

PHP_METHOD(Arango_Connection_Options, getEndpoint);
PHP_METHOD(Arango_Connection_Options, setEndpoint);
PHP_METHOD(Arango_Connection_Options, __construct);
PHP_METHOD(Arango_Connection_Options, getDefaults);
PHP_METHOD(Arango_Connection_Options, getSupportedAuthTypes);
PHP_METHOD(Arango_Connection_Options, getSupportedConnectionsTypes);
PHP_METHOD(Arango_Connection_Options, offsetExists);
PHP_METHOD(Arango_Connection_Options, offsetGet);
PHP_METHOD(Arango_Connection_Options, offsetSet);
PHP_METHOD(Arango_Connection_Options, offsetUnset);
PHP_METHOD(Arango_Connection_Options, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_connection_options_setendpoint, 0, 0, 1)
	ZEND_ARG_INFO(0, endpoint)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_connection_options___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_connection_options_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_connection_options_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_connection_options_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_connection_options_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(arango_connection_options_method_entry) {
	PHP_ME(Arango_Connection_Options, getEndpoint, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Connection_Options, setEndpoint, arginfo_arango_connection_options_setendpoint, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Connection_Options, __construct, arginfo_arango_connection_options___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Arango_Connection_Options, getDefaults, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Arango_Connection_Options, getSupportedAuthTypes, NULL, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Arango_Connection_Options, getSupportedConnectionsTypes, NULL, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Arango_Connection_Options, offsetExists, arginfo_arango_connection_options_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Connection_Options, offsetGet, arginfo_arango_connection_options_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Connection_Options, offsetSet, arginfo_arango_connection_options_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Connection_Options, offsetUnset, arginfo_arango_connection_options_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Connection_Options, validate, NULL, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
