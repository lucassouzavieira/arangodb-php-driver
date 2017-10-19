
extern zend_class_entry *arango_handler_collectionhandler_ce;

ZEPHIR_INIT_CLASS(Arango_Handler_CollectionHandler);

PHP_METHOD(Arango_Handler_CollectionHandler, create);
PHP_METHOD(Arango_Handler_CollectionHandler, setCollectionDefaults);
PHP_METHOD(Arango_Handler_CollectionHandler, setCollectionValues);
PHP_METHOD(Arango_Handler_CollectionHandler, has);
PHP_METHOD(Arango_Handler_CollectionHandler, count);
PHP_METHOD(Arango_Handler_CollectionHandler, figures);
PHP_METHOD(Arango_Handler_CollectionHandler, retrieveFromServer);
PHP_METHOD(Arango_Handler_CollectionHandler, getProperties);
PHP_METHOD(Arango_Handler_CollectionHandler, getChecksum);
PHP_METHOD(Arango_Handler_CollectionHandler, getRevision);
PHP_METHOD(Arango_Handler_CollectionHandler, getIndex);
PHP_METHOD(Arango_Handler_CollectionHandler, getIndexes);
PHP_METHOD(Arango_Handler_CollectionHandler, dropIndex);
PHP_METHOD(Arango_Handler_CollectionHandler, any);

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_handler_collectionhandler_create, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_handler_collectionhandler_setcollectiondefaults, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, collection, Arango\\Collection\\Collection, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_handler_collectionhandler_setcollectionvalues, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, collection, Arango\\Collection\\Collection, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_handler_collectionhandler_has, 0, 0, 1)
	ZEND_ARG_INFO(0, collectionId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_handler_collectionhandler_count, 0, 0, 1)
	ZEND_ARG_INFO(0, collectionId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_handler_collectionhandler_figures, 0, 0, 1)
	ZEND_ARG_INFO(0, collectionId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_handler_collectionhandler_retrievefromserver, 0, 0, 1)
	ZEND_ARG_INFO(0, collectionId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_handler_collectionhandler_getproperties, 0, 0, 1)
	ZEND_ARG_INFO(0, collectionId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_handler_collectionhandler_getchecksum, 0, 0, 1)
	ZEND_ARG_INFO(0, collectionId)
	ZEND_ARG_INFO(0, withRevisions)
	ZEND_ARG_INFO(0, withData)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_handler_collectionhandler_getrevision, 0, 0, 1)
	ZEND_ARG_INFO(0, collectionId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_handler_collectionhandler_getindex, 0, 0, 2)
	ZEND_ARG_INFO(0, collectionId)
	ZEND_ARG_INFO(0, indexId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_handler_collectionhandler_getindexes, 0, 0, 1)
	ZEND_ARG_INFO(0, collectionId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_handler_collectionhandler_dropindex, 0, 0, 2)
	ZEND_ARG_INFO(0, collectionId)
	ZEND_ARG_INFO(0, indexId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_handler_collectionhandler_any, 0, 0, 1)
	ZEND_ARG_INFO(0, collectionId)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(arango_handler_collectionhandler_method_entry) {
	PHP_ME(Arango_Handler_CollectionHandler, create, arginfo_arango_handler_collectionhandler_create, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Handler_CollectionHandler, setCollectionDefaults, arginfo_arango_handler_collectionhandler_setcollectiondefaults, ZEND_ACC_PRIVATE)
	PHP_ME(Arango_Handler_CollectionHandler, setCollectionValues, arginfo_arango_handler_collectionhandler_setcollectionvalues, ZEND_ACC_PRIVATE)
	PHP_ME(Arango_Handler_CollectionHandler, has, arginfo_arango_handler_collectionhandler_has, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Handler_CollectionHandler, count, arginfo_arango_handler_collectionhandler_count, ZEND_ACC_PRIVATE)
	PHP_ME(Arango_Handler_CollectionHandler, figures, arginfo_arango_handler_collectionhandler_figures, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Handler_CollectionHandler, retrieveFromServer, arginfo_arango_handler_collectionhandler_retrievefromserver, ZEND_ACC_PRIVATE)
	PHP_ME(Arango_Handler_CollectionHandler, getProperties, arginfo_arango_handler_collectionhandler_getproperties, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Handler_CollectionHandler, getChecksum, arginfo_arango_handler_collectionhandler_getchecksum, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Handler_CollectionHandler, getRevision, arginfo_arango_handler_collectionhandler_getrevision, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Handler_CollectionHandler, getIndex, arginfo_arango_handler_collectionhandler_getindex, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Handler_CollectionHandler, getIndexes, arginfo_arango_handler_collectionhandler_getindexes, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Handler_CollectionHandler, dropIndex, arginfo_arango_handler_collectionhandler_dropindex, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Handler_CollectionHandler, any, arginfo_arango_handler_collectionhandler_any, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
