
extern zend_class_entry *arango_document_edge_ce;

ZEPHIR_INIT_CLASS(Arango_Document_Edge);

PHP_METHOD(Arango_Document_Edge, getFrom);
PHP_METHOD(Arango_Document_Edge, getTo);
PHP_METHOD(Arango_Document_Edge, setFrom);
PHP_METHOD(Arango_Document_Edge, setTo);
PHP_METHOD(Arango_Document_Edge, set);
PHP_METHOD(Arango_Document_Edge, getAllForInsertUpdate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_document_edge_setfrom, 0, 0, 1)
	ZEND_ARG_INFO(0, from)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_document_edge_setto, 0, 0, 1)
	ZEND_ARG_INFO(0, to)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_document_edge_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(arango_document_edge_method_entry) {
	PHP_ME(Arango_Document_Edge, getFrom, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Document_Edge, getTo, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Document_Edge, setFrom, arginfo_arango_document_edge_setfrom, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Document_Edge, setTo, arginfo_arango_document_edge_setto, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Document_Edge, set, arginfo_arango_document_edge_set, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Document_Edge, getAllForInsertUpdate, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
