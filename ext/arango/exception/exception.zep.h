
extern zend_class_entry *arango_exception_exception_ce;

ZEPHIR_INIT_CLASS(Arango_Exception_Exception);

PHP_METHOD(Arango_Exception_Exception, __construct);
PHP_METHOD(Arango_Exception_Exception, enableLogging);
PHP_METHOD(Arango_Exception_Exception, disableLogging);

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_exception_exception___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_OBJ_INFO(0, previous, Arango\\Exception\\Throwable, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(arango_exception_exception_method_entry) {
	PHP_ME(Arango_Exception_Exception, __construct, arginfo_arango_exception_exception___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Arango_Exception_Exception, enableLogging, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Arango_Exception_Exception, disableLogging, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
