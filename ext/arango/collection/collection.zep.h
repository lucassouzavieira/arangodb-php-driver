
extern zend_class_entry *arango_collection_collection_ce;

ZEPHIR_INIT_CLASS(Arango_Collection_Collection);

PHP_METHOD(Arango_Collection_Collection, __construct);
PHP_METHOD(Arango_Collection_Collection, __clone);
PHP_METHOD(Arango_Collection_Collection, __toString);
PHP_METHOD(Arango_Collection_Collection, getAll);
PHP_METHOD(Arango_Collection_Collection, jsonSerialize);
PHP_METHOD(Arango_Collection_Collection, setId);
PHP_METHOD(Arango_Collection_Collection, getId);
PHP_METHOD(Arango_Collection_Collection, setName);
PHP_METHOD(Arango_Collection_Collection, getName);
PHP_METHOD(Arango_Collection_Collection, setType);
PHP_METHOD(Arango_Collection_Collection, getType);
PHP_METHOD(Arango_Collection_Collection, setWaitForSync);
PHP_METHOD(Arango_Collection_Collection, getWaitForSync);
PHP_METHOD(Arango_Collection_Collection, setJournalSize);
PHP_METHOD(Arango_Collection_Collection, getJournalSize);
PHP_METHOD(Arango_Collection_Collection, setIsSystem);
PHP_METHOD(Arango_Collection_Collection, getIsSystem);
PHP_METHOD(Arango_Collection_Collection, setIsVolatile);
PHP_METHOD(Arango_Collection_Collection, getIsVolatile);
PHP_METHOD(Arango_Collection_Collection, setNumberOfShards);
PHP_METHOD(Arango_Collection_Collection, getNumberOfShards);
PHP_METHOD(Arango_Collection_Collection, setShardKeys);
PHP_METHOD(Arango_Collection_Collection, getShardKeys);
PHP_METHOD(Arango_Collection_Collection, setStatus);
PHP_METHOD(Arango_Collection_Collection, getStatus);
PHP_METHOD(Arango_Collection_Collection, setKeyOptions);
PHP_METHOD(Arango_Collection_Collection, getKeyOptions);
PHP_METHOD(Arango_Collection_Collection, getDefaultType);
PHP_METHOD(Arango_Collection_Collection, createFromArray);
PHP_METHOD(Arango_Collection_Collection, validateArray);

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_collection_collection___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_collection_collection_setid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_collection_collection_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_collection_collection_settype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_collection_collection_setwaitforsync, 0, 0, 1)
	ZEND_ARG_INFO(0, waitForSync)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_collection_collection_setjournalsize, 0, 0, 1)
	ZEND_ARG_INFO(0, journalSize)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_collection_collection_setissystem, 0, 0, 1)
	ZEND_ARG_INFO(0, isSystem)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_collection_collection_setisvolatile, 0, 0, 1)
	ZEND_ARG_INFO(0, isVolatile)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_collection_collection_setnumberofshards, 0, 0, 1)
	ZEND_ARG_INFO(0, numberOfShards)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_collection_collection_setshardkeys, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, shardKeys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_collection_collection_setstatus, 0, 0, 1)
	ZEND_ARG_INFO(0, status)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_collection_collection_setkeyoptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keyOptions, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_collection_collection_createfromarray, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_collection_collection_validatearray, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(arango_collection_collection_method_entry) {
	PHP_ME(Arango_Collection_Collection, __construct, arginfo_arango_collection_collection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Arango_Collection_Collection, __clone, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Collection_Collection, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Collection_Collection, getAll, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Collection_Collection, jsonSerialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Collection_Collection, setId, arginfo_arango_collection_collection_setid, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Collection_Collection, getId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Collection_Collection, setName, arginfo_arango_collection_collection_setname, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Collection_Collection, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Collection_Collection, setType, arginfo_arango_collection_collection_settype, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Collection_Collection, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Collection_Collection, setWaitForSync, arginfo_arango_collection_collection_setwaitforsync, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Collection_Collection, getWaitForSync, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Collection_Collection, setJournalSize, arginfo_arango_collection_collection_setjournalsize, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Collection_Collection, getJournalSize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Collection_Collection, setIsSystem, arginfo_arango_collection_collection_setissystem, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Collection_Collection, getIsSystem, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Collection_Collection, setIsVolatile, arginfo_arango_collection_collection_setisvolatile, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Collection_Collection, getIsVolatile, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Collection_Collection, setNumberOfShards, arginfo_arango_collection_collection_setnumberofshards, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Collection_Collection, getNumberOfShards, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Collection_Collection, setShardKeys, arginfo_arango_collection_collection_setshardkeys, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Collection_Collection, getShardKeys, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Collection_Collection, setStatus, arginfo_arango_collection_collection_setstatus, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Collection_Collection, getStatus, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Collection_Collection, setKeyOptions, arginfo_arango_collection_collection_setkeyoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Collection_Collection, getKeyOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Collection_Collection, getDefaultType, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Arango_Collection_Collection, createFromArray, arginfo_arango_collection_collection_createfromarray, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Arango_Collection_Collection, validateArray, arginfo_arango_collection_collection_validatearray, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
