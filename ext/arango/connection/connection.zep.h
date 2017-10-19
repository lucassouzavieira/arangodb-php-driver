
extern zend_class_entry *arango_connection_connection_ce;

ZEPHIR_INIT_CLASS(Arango_Connection_Connection);

PHP_METHOD(Arango_Connection_Connection, __construct);
PHP_METHOD(Arango_Connection_Connection, __destruct);
PHP_METHOD(Arango_Connection_Connection, validateOption);
PHP_METHOD(Arango_Connection_Connection, setOption);
PHP_METHOD(Arango_Connection_Connection, setActiveBatch);
PHP_METHOD(Arango_Connection_Connection, getActiveBatch);
PHP_METHOD(Arango_Connection_Connection, getOption);
PHP_METHOD(Arango_Connection_Connection, getOptions);
PHP_METHOD(Arango_Connection_Connection, setDatabase);
PHP_METHOD(Arango_Connection_Connection, getDatabase);
PHP_METHOD(Arango_Connection_Connection, updateHttpHeader);
PHP_METHOD(Arango_Connection_Connection, getHandle);
PHP_METHOD(Arango_Connection_Connection, executeRequest);
PHP_METHOD(Arango_Connection_Connection, doBatch);
PHP_METHOD(Arango_Connection_Connection, isInBatchCaptureMode);
PHP_METHOD(Arango_Connection_Connection, stopCaptureBatch);
PHP_METHOD(Arango_Connection_Connection, setCaptureBatch);

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_connection_connection___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_connection_connection_validateoption, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_connection_connection_setoption, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_connection_connection_setactivebatch, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, batch, Arango\\Batch\\Batch, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_connection_connection_getoption, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_connection_connection_setdatabase, 0, 0, 1)
	ZEND_ARG_INFO(0, database)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_connection_connection_executerequest, 0, 0, 4)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_ARRAY_INFO(0, customHeaders, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_connection_connection_dobatch, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, request)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_connection_connection_setcapturebatch, 0, 0, 1)
	ZEND_ARG_INFO(0, state)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(arango_connection_connection_method_entry) {
	PHP_ME(Arango_Connection_Connection, __construct, arginfo_arango_connection_connection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Arango_Connection_Connection, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(Arango_Connection_Connection, validateOption, arginfo_arango_connection_connection_validateoption, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Arango_Connection_Connection, setOption, arginfo_arango_connection_connection_setoption, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Connection_Connection, setActiveBatch, arginfo_arango_connection_connection_setactivebatch, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Connection_Connection, getActiveBatch, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Connection_Connection, getOption, arginfo_arango_connection_connection_getoption, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Connection_Connection, getOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Connection_Connection, setDatabase, arginfo_arango_connection_connection_setdatabase, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Connection_Connection, getDatabase, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Connection_Connection, updateHttpHeader, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Arango_Connection_Connection, getHandle, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Connection_Connection, executeRequest, arginfo_arango_connection_connection_executerequest, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Connection_Connection, doBatch, arginfo_arango_connection_connection_dobatch, ZEND_ACC_PRIVATE)
	PHP_ME(Arango_Connection_Connection, isInBatchCaptureMode, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Connection_Connection, stopCaptureBatch, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Connection_Connection, setCaptureBatch, arginfo_arango_connection_connection_setcapturebatch, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
