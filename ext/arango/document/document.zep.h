
extern zend_class_entry *arango_document_document_ce;

ZEPHIR_INIT_CLASS(Arango_Document_Document);

PHP_METHOD(Arango_Document_Document, getId);
PHP_METHOD(Arango_Document_Document, getKey);
PHP_METHOD(Arango_Document_Document, getRevision);
PHP_METHOD(Arango_Document_Document, setRevision);
PHP_METHOD(Arango_Document_Document, getChanged);
PHP_METHOD(Arango_Document_Document, setChanged);
PHP_METHOD(Arango_Document_Document, getIsNew);
PHP_METHOD(Arango_Document_Document, setIsNew);
PHP_METHOD(Arango_Document_Document, getHiddenAttributes);
PHP_METHOD(Arango_Document_Document, setHiddenAttributes);
PHP_METHOD(Arango_Document_Document, getIgnoreHiddenAttributes);
PHP_METHOD(Arango_Document_Document, setIgnoreHiddenAttributes);
PHP_METHOD(Arango_Document_Document, __construct);
PHP_METHOD(Arango_Document_Document, __clone);
PHP_METHOD(Arango_Document_Document, __toString);
PHP_METHOD(Arango_Document_Document, __set);
PHP_METHOD(Arango_Document_Document, __get);
PHP_METHOD(Arango_Document_Document, createFromArray);
PHP_METHOD(Arango_Document_Document, set);
PHP_METHOD(Arango_Document_Document, get);
PHP_METHOD(Arango_Document_Document, getAll);
PHP_METHOD(Arango_Document_Document, getCollectionId);
PHP_METHOD(Arango_Document_Document, getAllForInsertUpdate);
PHP_METHOD(Arango_Document_Document, filterHiddenAttributes);
PHP_METHOD(Arango_Document_Document, setInternalId);
PHP_METHOD(Arango_Document_Document, setInternalKey);
PHP_METHOD(Arango_Document_Document, jsonSerialize);
PHP_METHOD(Arango_Document_Document, toArray);
PHP_METHOD(Arango_Document_Document, serialize);
PHP_METHOD(Arango_Document_Document, unserialize);
zend_object *zephir_init_properties_Arango_Document_Document(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_document_document_setrevision, 0, 0, 1)
	ZEND_ARG_INFO(0, revision)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_document_document_setchanged, 0, 0, 1)
	ZEND_ARG_INFO(0, changed)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_document_document_setisnew, 0, 0, 1)
	ZEND_ARG_INFO(0, isNew)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_document_document_sethiddenattributes, 0, 0, 1)
	ZEND_ARG_INFO(0, hiddenAttributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_document_document_setignorehiddenattributes, 0, 0, 1)
	ZEND_ARG_INFO(0, ignoreHiddenAttributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_document_document___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_document_document___set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_document_document___get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_document_document_createfromarray, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_document_document_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_document_document_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_document_document_getall, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_document_document_filterhiddenattributes, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
	ZEND_ARG_ARRAY_INFO(0, hiddenAttributes, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_document_document_setinternalid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_document_document_setinternalkey, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_document_document_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, serialized)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(arango_document_document_method_entry) {
	PHP_ME(Arango_Document_Document, getId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Document_Document, getKey, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Document_Document, getRevision, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Document_Document, setRevision, arginfo_arango_document_document_setrevision, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Document_Document, getChanged, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Document_Document, setChanged, arginfo_arango_document_document_setchanged, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Document_Document, getIsNew, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Document_Document, setIsNew, arginfo_arango_document_document_setisnew, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Document_Document, getHiddenAttributes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Document_Document, setHiddenAttributes, arginfo_arango_document_document_sethiddenattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Document_Document, getIgnoreHiddenAttributes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Document_Document, setIgnoreHiddenAttributes, arginfo_arango_document_document_setignorehiddenattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Document_Document, __construct, arginfo_arango_document_document___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Arango_Document_Document, __clone, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Document_Document, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Document_Document, __set, arginfo_arango_document_document___set, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Document_Document, __get, arginfo_arango_document_document___get, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Document_Document, createFromArray, arginfo_arango_document_document_createfromarray, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Arango_Document_Document, set, arginfo_arango_document_document_set, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Document_Document, get, arginfo_arango_document_document_get, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Document_Document, getAll, arginfo_arango_document_document_getall, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Document_Document, getCollectionId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Document_Document, getAllForInsertUpdate, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Document_Document, filterHiddenAttributes, arginfo_arango_document_document_filterhiddenattributes, ZEND_ACC_PRIVATE)
	PHP_ME(Arango_Document_Document, setInternalId, arginfo_arango_document_document_setinternalid, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Document_Document, setInternalKey, arginfo_arango_document_document_setinternalkey, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Document_Document, jsonSerialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Document_Document, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Document_Document, serialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Document_Document, unserialize, arginfo_arango_document_document_unserialize, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
