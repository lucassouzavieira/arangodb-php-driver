
extern zend_class_entry *arango_exception_connectionexception_ce;

ZEPHIR_INIT_CLASS(Arango_Exception_ConnectionException);

PHP_METHOD(Arango_Exception_ConnectionException, __toString);

ZEPHIR_INIT_FUNCS(arango_exception_connectionexception_method_entry) {
	PHP_ME(Arango_Exception_ConnectionException, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
