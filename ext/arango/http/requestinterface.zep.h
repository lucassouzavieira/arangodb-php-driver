
extern zend_class_entry *arango_http_requestinterface_ce;

ZEPHIR_INIT_CLASS(Arango_Http_RequestInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_http_requestinterface_executerequest, 0, 0, 4)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_ARRAY_INFO(0, customHeaders, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(arango_http_requestinterface_method_entry) {
	PHP_ABSTRACT_ME(Arango_Http_RequestInterface, executeRequest, arginfo_arango_http_requestinterface_executerequest)
	PHP_FE_END
};
