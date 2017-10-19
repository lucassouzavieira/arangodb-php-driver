
extern zend_class_entry *arango_batch_batch_ce;

ZEPHIR_INIT_CLASS(Arango_Batch_Batch);

PHP_METHOD(Arango_Batch_Batch, getDocumentType);
PHP_METHOD(Arango_Batch_Batch, setDocumentType);
PHP_METHOD(Arango_Batch_Batch, __construct);
PHP_METHOD(Arango_Batch_Batch, setConnection);
PHP_METHOD(Arango_Batch_Batch, getConnection);
PHP_METHOD(Arango_Batch_Batch, setCapture);
PHP_METHOD(Arango_Batch_Batch, setBatchRequest);
PHP_METHOD(Arango_Batch_Batch, setActive);
PHP_METHOD(Arango_Batch_Batch, isActive);
PHP_METHOD(Arango_Batch_Batch, isCapturing);
PHP_METHOD(Arango_Batch_Batch, startCapture);
PHP_METHOD(Arango_Batch_Batch, stopCapture);
PHP_METHOD(Arango_Batch_Batch, nextBatchPartId);
PHP_METHOD(Arango_Batch_Batch, nextBatchPartCursorOptions);
PHP_METHOD(Arango_Batch_Batch, append);
PHP_METHOD(Arango_Batch_Batch, splitWithContentIdKey);
PHP_METHOD(Arango_Batch_Batch, process);
PHP_METHOD(Arango_Batch_Batch, getPart);
zend_object *zephir_init_properties_Arango_Batch_Batch(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_batch_batch_setdocumenttype, 0, 0, 1)
	ZEND_ARG_INFO(0, documentType)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_batch_batch___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, connection, Arango\\Connection\\Connection, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_batch_batch_setconnection, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, connection, Arango\\Connection\\Connection, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_batch_batch_setcapture, 0, 0, 1)
	ZEND_ARG_INFO(0, state)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_batch_batch_setbatchrequest, 0, 0, 1)
	ZEND_ARG_INFO(0, state)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_batch_batch_nextbatchpartid, 0, 0, 1)
	ZEND_ARG_INFO(0, batchPartId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_batch_batch_nextbatchpartcursoroptions, 0, 0, 1)
	ZEND_ARG_INFO(0, batchPartCursorOptions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_batch_batch_append, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, request)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_batch_batch_splitwithcontentidkey, 0, 0, 2)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_batch_batch_getpart, 0, 0, 1)
	ZEND_ARG_INFO(0, partId)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(arango_batch_batch_method_entry) {
	PHP_ME(Arango_Batch_Batch, getDocumentType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Batch_Batch, setDocumentType, arginfo_arango_batch_batch_setdocumenttype, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Batch_Batch, __construct, arginfo_arango_batch_batch___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Arango_Batch_Batch, setConnection, arginfo_arango_batch_batch_setconnection, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Batch_Batch, getConnection, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Batch_Batch, setCapture, arginfo_arango_batch_batch_setcapture, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Batch_Batch, setBatchRequest, arginfo_arango_batch_batch_setbatchrequest, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Batch_Batch, setActive, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Batch_Batch, isActive, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Batch_Batch, isCapturing, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Batch_Batch, startCapture, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Batch_Batch, stopCapture, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Batch_Batch, nextBatchPartId, arginfo_arango_batch_batch_nextbatchpartid, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Batch_Batch, nextBatchPartCursorOptions, arginfo_arango_batch_batch_nextbatchpartcursoroptions, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Batch_Batch, append, arginfo_arango_batch_batch_append, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Batch_Batch, splitWithContentIdKey, arginfo_arango_batch_batch_splitwithcontentidkey, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Batch_Batch, process, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Batch_Batch, getPart, arginfo_arango_batch_batch_getpart, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
