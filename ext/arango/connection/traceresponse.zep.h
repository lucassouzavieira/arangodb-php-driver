
extern zend_class_entry *arango_connection_traceresponse_ce;

ZEPHIR_INIT_CLASS(Arango_Connection_TraceResponse);

PHP_METHOD(Arango_Connection_TraceResponse, getHeaders);
PHP_METHOD(Arango_Connection_TraceResponse, getHttpCode);
PHP_METHOD(Arango_Connection_TraceResponse, getBody);
PHP_METHOD(Arango_Connection_TraceResponse, getTimeTaken);
PHP_METHOD(Arango_Connection_TraceResponse, getType);
PHP_METHOD(Arango_Connection_TraceResponse, __construct);
PHP_METHOD(Arango_Connection_TraceResponse, getHttpCodeDefinition);
zend_object *zephir_init_properties_Arango_Connection_TraceResponse(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_connection_traceresponse___construct, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0, headers, 0)
	ZEND_ARG_INFO(0, httpCode)
	ZEND_ARG_INFO(0, body)
	ZEND_ARG_INFO(0, timeTaken)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(arango_connection_traceresponse_method_entry) {
	PHP_ME(Arango_Connection_TraceResponse, getHeaders, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Connection_TraceResponse, getHttpCode, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Connection_TraceResponse, getBody, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Connection_TraceResponse, getTimeTaken, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Connection_TraceResponse, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Connection_TraceResponse, __construct, arginfo_arango_connection_traceresponse___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Arango_Connection_TraceResponse, getHttpCodeDefinition, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
