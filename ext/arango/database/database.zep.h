
extern zend_class_entry *arango_database_database_ce;

ZEPHIR_INIT_CLASS(Arango_Database_Database);

PHP_METHOD(Arango_Database_Database, create);
PHP_METHOD(Arango_Database_Database, delete);
PHP_METHOD(Arango_Database_Database, list);
PHP_METHOD(Arango_Database_Database, listUserDatabases);
PHP_METHOD(Arango_Database_Database, info);

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_database_database_create, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, connection, Arango\\Connection\\Connection, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_database_database_delete, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, connection, Arango\\Connection\\Connection, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_database_database_list, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, connection, Arango\\Connection\\Connection, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_database_database_listuserdatabases, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, connection, Arango\\Connection\\Connection, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_database_database_info, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, connection, Arango\\Connection\\Connection, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(arango_database_database_method_entry) {
	PHP_ME(Arango_Database_Database, create, arginfo_arango_database_database_create, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Arango_Database_Database, delete, arginfo_arango_database_database_delete, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Arango_Database_Database, list, arginfo_arango_database_database_list, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Arango_Database_Database, listUserDatabases, arginfo_arango_database_database_listuserdatabases, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Arango_Database_Database, info, arginfo_arango_database_database_info, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
