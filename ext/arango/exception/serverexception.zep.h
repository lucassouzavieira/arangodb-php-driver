
extern zend_class_entry *arango_exception_serverexception_ce;

ZEPHIR_INIT_CLASS(Arango_Exception_ServerException);

PHP_METHOD(Arango_Exception_ServerException, getDetails);
PHP_METHOD(Arango_Exception_ServerException, setDetails);
PHP_METHOD(Arango_Exception_ServerException, __toString);
PHP_METHOD(Arango_Exception_ServerException, getServerCode);
PHP_METHOD(Arango_Exception_ServerException, getServerMessage);
zend_object *zephir_init_properties_Arango_Exception_ServerException(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_exception_serverexception_setdetails, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, details, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(arango_exception_serverexception_method_entry) {
	PHP_ME(Arango_Exception_ServerException, getDetails, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Exception_ServerException, setDetails, arginfo_arango_exception_serverexception_setdetails, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Exception_ServerException, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Exception_ServerException, getServerCode, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Exception_ServerException, getServerMessage, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
