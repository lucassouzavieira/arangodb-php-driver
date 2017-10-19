
extern zend_class_entry *arango_http_client_ce;

ZEPHIR_INIT_CLASS(Arango_Http_Client);

PHP_METHOD(Arango_Http_Client, validateMethod);
PHP_METHOD(Arango_Http_Client, parseHttpMessage);
PHP_METHOD(Arango_Http_Client, parseHttpHeaders);
PHP_METHOD(Arango_Http_Client, createConnection);
PHP_METHOD(Arango_Http_Client, buildRequest);
PHP_METHOD(Arango_Http_Client, transfer);
PHP_METHOD(Arango_Http_Client, isValidMethod);

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_http_client_validatemethod, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_http_client_parsehttpmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, httpMessage)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_http_client_parsehttpheaders, 0, 0, 1)
	ZEND_ARG_INFO(0, headers)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_http_client_createconnection, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, options, Arango\\Connection\\Options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_http_client_buildrequest, 0, 0, 6)
	ZEND_ARG_OBJ_INFO(0, options, Arango\\Connection\\Options, 0)
	ZEND_ARG_INFO(0, header)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, body)
	ZEND_ARG_ARRAY_INFO(0, customHeaders, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_http_client_transfer, 0, 0, 3)
	ZEND_ARG_INFO(0, socket)
	ZEND_ARG_INFO(0, request)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_http_client_isvalidmethod, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(arango_http_client_method_entry) {
	PHP_ME(Arango_Http_Client, validateMethod, arginfo_arango_http_client_validatemethod, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Arango_Http_Client, parseHttpMessage, arginfo_arango_http_client_parsehttpmessage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Arango_Http_Client, parseHttpHeaders, arginfo_arango_http_client_parsehttpheaders, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Arango_Http_Client, createConnection, arginfo_arango_http_client_createconnection, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Arango_Http_Client, buildRequest, arginfo_arango_http_client_buildrequest, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Arango_Http_Client, transfer, arginfo_arango_http_client_transfer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Arango_Http_Client, isValidMethod, arginfo_arango_http_client_isvalidmethod, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
