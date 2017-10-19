
extern zend_class_entry *arango_cursor_cursor_ce;

ZEPHIR_INIT_CLASS(Arango_Cursor_Cursor);

PHP_METHOD(Arango_Cursor_Cursor, getId);
PHP_METHOD(Arango_Cursor_Cursor, getFullCount);
PHP_METHOD(Arango_Cursor_Cursor, getExtra);
PHP_METHOD(Arango_Cursor_Cursor, getFetches);
PHP_METHOD(Arango_Cursor_Cursor, getCached);
PHP_METHOD(Arango_Cursor_Cursor, __construct);
PHP_METHOD(Arango_Cursor_Cursor, addFlatFromArray);
PHP_METHOD(Arango_Cursor_Cursor, addDocumentsFromArray);
PHP_METHOD(Arango_Cursor_Cursor, addPathsFromArray);
PHP_METHOD(Arango_Cursor_Cursor, addShortestPathFromArray);
PHP_METHOD(Arango_Cursor_Cursor, addDistanceToFromArray);
PHP_METHOD(Arango_Cursor_Cursor, addCommonNeighborsFromArray);
PHP_METHOD(Arango_Cursor_Cursor, addCommonPropertiesFromArray);
PHP_METHOD(Arango_Cursor_Cursor, addFigureFromArray);
PHP_METHOD(Arango_Cursor_Cursor, addEdgesFromArray);
PHP_METHOD(Arango_Cursor_Cursor, addVerticesFromArray);
PHP_METHOD(Arango_Cursor_Cursor, fetchOutstanding);
PHP_METHOD(Arango_Cursor_Cursor, rewind);
PHP_METHOD(Arango_Cursor_Cursor, current);
PHP_METHOD(Arango_Cursor_Cursor, key);
PHP_METHOD(Arango_Cursor_Cursor, next);
PHP_METHOD(Arango_Cursor_Cursor, valid);
PHP_METHOD(Arango_Cursor_Cursor, sanitize);
PHP_METHOD(Arango_Cursor_Cursor, updateLength);
PHP_METHOD(Arango_Cursor_Cursor, count);
PHP_METHOD(Arango_Cursor_Cursor, url);
PHP_METHOD(Arango_Cursor_Cursor, add);
PHP_METHOD(Arango_Cursor_Cursor, getStatValue);
PHP_METHOD(Arango_Cursor_Cursor, getMetadata);
PHP_METHOD(Arango_Cursor_Cursor, getWarnings);
PHP_METHOD(Arango_Cursor_Cursor, getWritesExecuted);
PHP_METHOD(Arango_Cursor_Cursor, getWritesIgnored);
PHP_METHOD(Arango_Cursor_Cursor, getScannedFull);
PHP_METHOD(Arango_Cursor_Cursor, getScannedIndex);
PHP_METHOD(Arango_Cursor_Cursor, getFiltered);

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_cursor_cursor___construct, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, connection, Arango\\Connection\\Connection, 0)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_cursor_cursor_addflatfromarray, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_cursor_cursor_adddocumentsfromarray, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_cursor_cursor_addpathsfromarray, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_cursor_cursor_addshortestpathfromarray, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_cursor_cursor_adddistancetofromarray, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_cursor_cursor_addcommonneighborsfromarray, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_cursor_cursor_addcommonpropertiesfromarray, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_cursor_cursor_addfigurefromarray, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_cursor_cursor_addedgesfromarray, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_cursor_cursor_addverticesfromarray, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_cursor_cursor_sanitize, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, rows, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_cursor_cursor_add, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_cursor_cursor_getstatvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(arango_cursor_cursor_method_entry) {
	PHP_ME(Arango_Cursor_Cursor, getId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Cursor_Cursor, getFullCount, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Cursor_Cursor, getExtra, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Cursor_Cursor, getFetches, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Cursor_Cursor, getCached, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Cursor_Cursor, __construct, arginfo_arango_cursor_cursor___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Arango_Cursor_Cursor, addFlatFromArray, arginfo_arango_cursor_cursor_addflatfromarray, ZEND_ACC_PRIVATE)
	PHP_ME(Arango_Cursor_Cursor, addDocumentsFromArray, arginfo_arango_cursor_cursor_adddocumentsfromarray, ZEND_ACC_PRIVATE)
	PHP_ME(Arango_Cursor_Cursor, addPathsFromArray, arginfo_arango_cursor_cursor_addpathsfromarray, ZEND_ACC_PRIVATE)
	PHP_ME(Arango_Cursor_Cursor, addShortestPathFromArray, arginfo_arango_cursor_cursor_addshortestpathfromarray, ZEND_ACC_PRIVATE)
	PHP_ME(Arango_Cursor_Cursor, addDistanceToFromArray, arginfo_arango_cursor_cursor_adddistancetofromarray, ZEND_ACC_PRIVATE)
	PHP_ME(Arango_Cursor_Cursor, addCommonNeighborsFromArray, arginfo_arango_cursor_cursor_addcommonneighborsfromarray, ZEND_ACC_PRIVATE)
	PHP_ME(Arango_Cursor_Cursor, addCommonPropertiesFromArray, arginfo_arango_cursor_cursor_addcommonpropertiesfromarray, ZEND_ACC_PRIVATE)
	PHP_ME(Arango_Cursor_Cursor, addFigureFromArray, arginfo_arango_cursor_cursor_addfigurefromarray, ZEND_ACC_PRIVATE)
	PHP_ME(Arango_Cursor_Cursor, addEdgesFromArray, arginfo_arango_cursor_cursor_addedgesfromarray, ZEND_ACC_PRIVATE)
	PHP_ME(Arango_Cursor_Cursor, addVerticesFromArray, arginfo_arango_cursor_cursor_addverticesfromarray, ZEND_ACC_PRIVATE)
	PHP_ME(Arango_Cursor_Cursor, fetchOutstanding, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Arango_Cursor_Cursor, rewind, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Cursor_Cursor, current, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Cursor_Cursor, key, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Cursor_Cursor, next, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Cursor_Cursor, valid, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Cursor_Cursor, sanitize, arginfo_arango_cursor_cursor_sanitize, ZEND_ACC_PRIVATE)
	PHP_ME(Arango_Cursor_Cursor, updateLength, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Arango_Cursor_Cursor, count, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Cursor_Cursor, url, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Arango_Cursor_Cursor, add, arginfo_arango_cursor_cursor_add, ZEND_ACC_PRIVATE)
	PHP_ME(Arango_Cursor_Cursor, getStatValue, arginfo_arango_cursor_cursor_getstatvalue, ZEND_ACC_PRIVATE)
	PHP_ME(Arango_Cursor_Cursor, getMetadata, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Cursor_Cursor, getWarnings, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Cursor_Cursor, getWritesExecuted, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Cursor_Cursor, getWritesIgnored, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Cursor_Cursor, getScannedFull, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Cursor_Cursor, getScannedIndex, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Arango_Cursor_Cursor, getFiltered, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
