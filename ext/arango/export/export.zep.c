
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


/**
 * Collection export
 * TODO all
 * @package Arango/Export
 * @class Export
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Export_Export) {

	ZEPHIR_REGISTER_CLASS(Arango\\Export, Export, arango, export_export, arango_export_export_method_entry, 0);

	/**
	 * Connection object
	 *
	 * @var Connection
	 */
	zend_declare_property_null(arango_export_export_ce, SL("connection"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Collection object
	 *
	 * @var Connection
	 */
	zend_declare_property_null(arango_export_export_ce, SL("collection"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * The current batch size
	 *
	 * @var Connection
	 */
	zend_declare_property_null(arango_export_export_ce, SL("batchSize"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Flat flag (If set, the query results will be treated as a simple array, not documents)
	 *
	 * @var boolean
	 */
	zend_declare_property_bool(arango_export_export_ce, SL("flat"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Flush flag (if set, then all documents from the collection that are currently only
	 * in the write-ahead log (WAL) will be moved to the collection's datafiles. This may cause
	 * an initial delay in the export, but will lead to the documents in the WAL not being
	 * excluded from the export run. If the flush flag is set to false, the documents still
	 * in the WAL may be missing in the export result.
	 *
	 * @var boolean
	 */
	zend_declare_property_bool(arango_export_export_ce, SL("flush"), 1, ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * The underlying collection type
	 *
	 * @var string
	 */
	zend_declare_property_null(arango_export_export_ce, SL("type"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Exports restrictions
	 * Null if for no restrictions or an array with a "type" and a "fields" index
	 *
	 * @var mixed
	 */
	zend_declare_property_null(arango_export_export_ce, SL("restrictions"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Optional limit for export
	 * If specified and positive, will cap the amount of
	 * documents in the cursor to the specified value
	 *
	 * @var int
	 */
	zend_declare_property_long(arango_export_export_ce, SL("limit"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Export indexes
	 */
	zephir_declare_class_constant_string(arango_export_export_ce, SL("COUNT"), "count");

	zephir_declare_class_constant_string(arango_export_export_ce, SL("BATCH_SIZE"), "batchSize");

	zephir_declare_class_constant_string(arango_export_export_ce, SL("FLUSH"), "flush");

	zephir_declare_class_constant_string(arango_export_export_ce, SL("RESTRICT"), "restrict");

	zephir_declare_class_constant_string(arango_export_export_ce, SL("LIMIT"), "limit");

	return SUCCESS;

}

/**
 * Initialize the export
 *
 * @throws \Exception
 *
 * @param Connection connection - The Connection object
 * @param Collection collection - The Collection to export
 * @param array options         - The export options
 */
PHP_METHOD(Arango_Export_Export, __construct) {

	zval options;
	zval *connection, connection_sub, *collection, collection_sub, *options_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&collection_sub);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &connection, &collection, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}



}

