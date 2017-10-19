
extern zend_class_entry *arango_http_url_ce;

ZEPHIR_INIT_CLASS(Arango_Http_Url);

PHP_METHOD(Arango_Http_Url, getDocumentIdFromLocation);
PHP_METHOD(Arango_Http_Url, buildUrl);
PHP_METHOD(Arango_Http_Url, appendParamsToUrl);
PHP_METHOD(Arango_Http_Url, getBoolString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_http_url_getdocumentidfromlocation, 0, 0, 1)
	ZEND_ARG_INFO(0, location)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_http_url_buildurl, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_ARRAY_INFO(0, parts, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_http_url_appendparamstourl, 0, 0, 2)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_http_url_getboolstring, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(arango_http_url_method_entry) {
	PHP_ME(Arango_Http_Url, getDocumentIdFromLocation, arginfo_arango_http_url_getdocumentidfromlocation, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Arango_Http_Url, buildUrl, arginfo_arango_http_url_buildurl, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Arango_Http_Url, appendParamsToUrl, arginfo_arango_http_url_appendparamstourl, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Arango_Http_Url, getBoolString, arginfo_arango_http_url_getboolstring, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_FE_END
};
