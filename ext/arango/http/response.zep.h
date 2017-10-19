
extern zend_class_entry *arango_http_response_ce;

ZEPHIR_INIT_CLASS(Arango_Http_Response);

PHP_METHOD(Arango_Http_Response, __construct);
PHP_METHOD(Arango_Http_Response, getCode);
PHP_METHOD(Arango_Http_Response, getHeader);
PHP_METHOD(Arango_Http_Response, getHeaders);
PHP_METHOD(Arango_Http_Response, getLocation);
PHP_METHOD(Arango_Http_Response, getBody);
PHP_METHOD(Arango_Http_Response, getResult);
PHP_METHOD(Arango_Http_Response, getJson);
PHP_METHOD(Arango_Http_Response, toArray);
PHP_METHOD(Arango_Http_Response, validateBody);
PHP_METHOD(Arango_Http_Response, setBatchPart);

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_http_response___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, response)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, wasAsync)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_http_response_getheader, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_http_response_setbatchpart, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, batchPart, Arango\\Batch\\BatchPart, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(arango_http_response_method_entry) {
	PHP_ME(Arango_Http_Response, __construct, arginfo_arango_http_response___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Arango_Http_Response, getCode, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Http_Response, getHeader, arginfo_arango_http_response_getheader, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Http_Response, getHeaders, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Http_Response, getLocation, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Http_Response, getBody, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Http_Response, getResult, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Http_Response, getJson, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Http_Response, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Http_Response, validateBody, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Arango_Http_Response, setBatchPart, arginfo_arango_http_response_setbatchpart, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
