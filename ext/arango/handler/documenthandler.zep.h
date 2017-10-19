
extern zend_class_entry *arango_handler_documenthandler_ce;

ZEPHIR_INIT_CLASS(Arango_Handler_DocumentHandler);

PHP_METHOD(Arango_Handler_DocumentHandler, get);
PHP_METHOD(Arango_Handler_DocumentHandler, getDocument);
PHP_METHOD(Arango_Handler_DocumentHandler, buildRevisionHeaders);
PHP_METHOD(Arango_Handler_DocumentHandler, has);
PHP_METHOD(Arango_Handler_DocumentHandler, getInfo);

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_handler_documenthandler_get, 0, 0, 1)
	ZEND_ARG_INFO(0, documentId)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_handler_documenthandler_getdocument, 0, 0, 2)
	ZEND_ARG_INFO(0, collection)
	ZEND_ARG_INFO(0, document)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_handler_documenthandler_buildrevisionheaders, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_handler_documenthandler_has, 0, 0, 1)
	ZEND_ARG_INFO(0, documentId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_handler_documenthandler_getinfo, 0, 0, 1)
	ZEND_ARG_INFO(0, documentId)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(arango_handler_documenthandler_method_entry) {
	PHP_ME(Arango_Handler_DocumentHandler, get, arginfo_arango_handler_documenthandler_get, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Handler_DocumentHandler, getDocument, arginfo_arango_handler_documenthandler_getdocument, ZEND_ACC_PROTECTED)
	PHP_ME(Arango_Handler_DocumentHandler, buildRevisionHeaders, arginfo_arango_handler_documenthandler_buildrevisionheaders, ZEND_ACC_PROTECTED)
	PHP_ME(Arango_Handler_DocumentHandler, has, arginfo_arango_handler_documenthandler_has, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Handler_DocumentHandler, getInfo, arginfo_arango_handler_documenthandler_getinfo, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
