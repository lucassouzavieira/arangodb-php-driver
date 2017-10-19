
extern zend_class_entry *arango_connection_encoding_ce;

ZEPHIR_INIT_CLASS(Arango_Connection_Encoding);

PHP_METHOD(Arango_Connection_Encoding, detectUtf);
PHP_METHOD(Arango_Connection_Encoding, checkEncoding);
PHP_METHOD(Arango_Connection_Encoding, jsonWrapper);

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_connection_encoding_detectutf, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_connection_encoding_checkencoding, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_connection_encoding_jsonwrapper, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(arango_connection_encoding_method_entry) {
	PHP_ME(Arango_Connection_Encoding, detectUtf, arginfo_arango_connection_encoding_detectutf, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Arango_Connection_Encoding, checkEncoding, arginfo_arango_connection_encoding_checkencoding, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Arango_Connection_Encoding, jsonWrapper, arginfo_arango_connection_encoding_jsonwrapper, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
