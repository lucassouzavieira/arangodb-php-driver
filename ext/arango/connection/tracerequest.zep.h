
extern zend_class_entry *arango_connection_tracerequest_ce;

ZEPHIR_INIT_CLASS(Arango_Connection_TraceRequest);

PHP_METHOD(Arango_Connection_TraceRequest, getHeaders);
PHP_METHOD(Arango_Connection_TraceRequest, getMethod);
PHP_METHOD(Arango_Connection_TraceRequest, getRequestUrl);
PHP_METHOD(Arango_Connection_TraceRequest, getBody);
PHP_METHOD(Arango_Connection_TraceRequest, getType);
PHP_METHOD(Arango_Connection_TraceRequest, __construct);
zend_object *zephir_init_properties_Arango_Connection_TraceRequest(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_connection_tracerequest___construct, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0, headers, 0)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, requestUrl)
	ZEND_ARG_INFO(0, body)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(arango_connection_tracerequest_method_entry) {
	PHP_ME(Arango_Connection_TraceRequest, getHeaders, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Connection_TraceRequest, getMethod, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Connection_TraceRequest, getRequestUrl, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Connection_TraceRequest, getBody, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Connection_TraceRequest, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Connection_TraceRequest, __construct, arginfo_arango_connection_tracerequest___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
