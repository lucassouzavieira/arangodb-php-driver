
extern zend_class_entry *arango_http_request_ce;

ZEPHIR_INIT_CLASS(Arango_Http_Request);

PHP_METHOD(Arango_Http_Request, get);
PHP_METHOD(Arango_Http_Request, post);
PHP_METHOD(Arango_Http_Request, put);
PHP_METHOD(Arango_Http_Request, head);
PHP_METHOD(Arango_Http_Request, patch);
PHP_METHOD(Arango_Http_Request, delete);
PHP_METHOD(Arango_Http_Request, parseResponse);

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_http_request_get, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_ARRAY_INFO(0, customHeaders, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_http_request_post, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_ARRAY_INFO(0, customHeaders, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_http_request_put, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_ARRAY_INFO(0, customHeaders, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_http_request_head, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_ARRAY_INFO(0, customHeaders, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_http_request_patch, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_ARRAY_INFO(0, customHeaders, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_http_request_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_ARRAY_INFO(0, customHeaders, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_http_request_parseresponse, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, response, Arango\\Http\\Response, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(arango_http_request_method_entry) {
	PHP_ME(Arango_Http_Request, get, arginfo_arango_http_request_get, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Http_Request, post, arginfo_arango_http_request_post, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Http_Request, put, arginfo_arango_http_request_put, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Http_Request, head, arginfo_arango_http_request_head, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Http_Request, patch, arginfo_arango_http_request_patch, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Http_Request, delete, arginfo_arango_http_request_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Http_Request, parseResponse, arginfo_arango_http_request_parseresponse, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
