
extern zend_class_entry *arango_batch_batchpart_ce;

ZEPHIR_INIT_CLASS(Arango_Batch_BatchPart);

PHP_METHOD(Arango_Batch_BatchPart, getCursorOptions);
PHP_METHOD(Arango_Batch_BatchPart, getId);
PHP_METHOD(Arango_Batch_BatchPart, setId);
PHP_METHOD(Arango_Batch_BatchPart, getType);
PHP_METHOD(Arango_Batch_BatchPart, setType);
PHP_METHOD(Arango_Batch_BatchPart, getResponse);
PHP_METHOD(Arango_Batch_BatchPart, setResponse);
PHP_METHOD(Arango_Batch_BatchPart, setDocumentClass);
PHP_METHOD(Arango_Batch_BatchPart, __construct);
PHP_METHOD(Arango_Batch_BatchPart, setBatch);
PHP_METHOD(Arango_Batch_BatchPart, getBatch);
PHP_METHOD(Arango_Batch_BatchPart, setRequest);
PHP_METHOD(Arango_Batch_BatchPart, getRequest);
PHP_METHOD(Arango_Batch_BatchPart, getHttpCode);
PHP_METHOD(Arango_Batch_BatchPart, getProcessedResponse);
zend_object *zephir_init_properties_Arango_Batch_BatchPart(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_batch_batchpart_setid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_batch_batchpart_settype, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, type, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_batch_batchpart_setresponse, 0, 0, 1)
	ZEND_ARG_INFO(0, response)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_batch_batchpart_setdocumentclass, 0, 0, 1)
	ZEND_ARG_INFO(0, documentClass)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_batch_batchpart___construct, 0, 0, 5)
	ZEND_ARG_OBJ_INFO(0, batch, Arango\\Batch\\Batch, 0)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_OBJ_INFO(0, request, Arango\\Batch\\Request, 0)
	ZEND_ARG_INFO(0, response)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_batch_batchpart_setbatch, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, batch, Arango\\Batch\\Batch, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_batch_batchpart_setrequest, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Arango\\Batch\\Request, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(arango_batch_batchpart_method_entry) {
	PHP_ME(Arango_Batch_BatchPart, getCursorOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Batch_BatchPart, getId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Batch_BatchPart, setId, arginfo_arango_batch_batchpart_setid, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Batch_BatchPart, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Batch_BatchPart, setType, arginfo_arango_batch_batchpart_settype, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Batch_BatchPart, getResponse, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Batch_BatchPart, setResponse, arginfo_arango_batch_batchpart_setresponse, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Batch_BatchPart, setDocumentClass, arginfo_arango_batch_batchpart_setdocumentclass, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Batch_BatchPart, __construct, arginfo_arango_batch_batchpart___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Arango_Batch_BatchPart, setBatch, arginfo_arango_batch_batchpart_setbatch, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Batch_BatchPart, getBatch, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Batch_BatchPart, setRequest, arginfo_arango_batch_batchpart_setrequest, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Batch_BatchPart, getRequest, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Batch_BatchPart, getHttpCode, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Batch_BatchPart, getProcessedResponse, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
