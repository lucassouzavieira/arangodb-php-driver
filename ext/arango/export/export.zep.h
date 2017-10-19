
extern zend_class_entry *arango_export_export_ce;

ZEPHIR_INIT_CLASS(Arango_Export_Export);

PHP_METHOD(Arango_Export_Export, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_arango_export_export___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, connection, Arango\\Connection\\Connection, 0)
	ZEND_ARG_OBJ_INFO(0, collection, Arango\\Export\\Collection, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(arango_export_export_method_entry) {
	PHP_ME(Arango_Export_Export, __construct, arginfo_arango_export_export___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
