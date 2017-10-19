
extern zend_class_entry *arango_handler_vertexhandler_ce;

ZEPHIR_INIT_CLASS(Arango_Handler_VertexHandler);

PHP_METHOD(Arango_Handler_VertexHandler, createFromArrayWithContext);

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_handler_vertexhandler_createfromarraywithcontext, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(arango_handler_vertexhandler_method_entry) {
	PHP_ME(Arango_Handler_VertexHandler, createFromArrayWithContext, arginfo_arango_handler_vertexhandler_createfromarraywithcontext, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
