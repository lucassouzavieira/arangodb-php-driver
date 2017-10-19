
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
#include "ext/spl/spl_iterators.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"


/**
 * Provides access to the results of an AQL query or another statement
 * The cursor might not contain all results in the beginning. <br>
 *
 * If the result set is too big to be transferred in one go, the
 * cursor might issue additional HTTP requests to fetch the
 * remaining results from the server. <br>
 *
 * @package Arango/Cursor
 * @class Cursor
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Cursor_Cursor) {

	ZEPHIR_REGISTER_CLASS(Arango\\Cursor, Cursor, arango, cursor_cursor, arango_cursor_cursor_method_entry, 0);

	/**
	 * The connection object
	 *
	 * @var Connection
	 */
	zend_declare_property_null(arango_cursor_cursor_ce, SL("connection"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Cursor options
	 *
	 * @var array
	 */
	zend_declare_property_null(arango_cursor_cursor_ce, SL("options"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Result data
	 *
	 * @var array
	 */
	zend_declare_property_null(arango_cursor_cursor_ce, SL("data"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Result set
	 *
	 * @var array
	 */
	zend_declare_property_null(arango_cursor_cursor_ce, SL("result"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * If server has more results
	 *
	 * @var boolean
	 */
	zend_declare_property_null(arango_cursor_cursor_ce, SL("hasMore"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Cursor Id - might be null if Cursor does not have an id
	 *
	 * @var mixed
	 */
	zend_declare_property_null(arango_cursor_cursor_ce, SL("id"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Current position in result set iteration (zero-based)
	 *
	 * @var int
	 */
	zend_declare_property_null(arango_cursor_cursor_ce, SL("position"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Total length of result set (in number of documents)
	 *
	 * @var int
	 */
	zend_declare_property_null(arango_cursor_cursor_ce, SL("length"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Full count of the result set (ignoring the outermost LIMIT)
	 *
	 * @var int
	 */
	zend_declare_property_null(arango_cursor_cursor_ce, SL("fullCount"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Extra data (statistics) returned from the statement
	 *
	 * @var array
	 */
	zend_declare_property_null(arango_cursor_cursor_ce, SL("extra"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Number of HTTP calls that were made to build the cursor result
	 *
	 * @var array
	 */
	zend_declare_property_long(arango_cursor_cursor_ce, SL("fetches"), 1, ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Whether or not the query result was served from the AQL query result cache
	 *
	 * @var boolean
	 */
	zend_declare_property_null(arango_cursor_cursor_ce, SL("cached"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Results entries for class parameters
	 */
	zephir_declare_class_constant_string(arango_cursor_cursor_ce, SL("ENTRY_ID"), "id");

	zephir_declare_class_constant_string(arango_cursor_cursor_ce, SL("ENTRY_HAS_MORE"), "hasMore");

	zephir_declare_class_constant_string(arango_cursor_cursor_ce, SL("ENTRY_RESULT"), "result");

	zephir_declare_class_constant_string(arango_cursor_cursor_ce, SL("ENTRY_EXTRA"), "extra");

	zephir_declare_class_constant_string(arango_cursor_cursor_ce, SL("ENTRY_STATS"), "stats");

	zephir_declare_class_constant_string(arango_cursor_cursor_ce, SL("ENTRY_COUNT"), "fullCount");

	zephir_declare_class_constant_string(arango_cursor_cursor_ce, SL("ENTRY_CACHE"), "cache");

	zephir_declare_class_constant_string(arango_cursor_cursor_ce, SL("ENTRY_CACHED"), "cached");

	zephir_declare_class_constant_string(arango_cursor_cursor_ce, SL("ENTRY_SANITIZE"), "_sanitize");

	zephir_declare_class_constant_string(arango_cursor_cursor_ce, SL("ENTRY_FLAT"), "_flat");

	zephir_declare_class_constant_string(arango_cursor_cursor_ce, SL("ENTRY_TYPE"), "objectType");

	zephir_declare_class_constant_string(arango_cursor_cursor_ce, SL("ENTRY_BASE_URL"), "baseurl");

	zend_class_implements(arango_cursor_cursor_ce TSRMLS_CC, 1, zend_ce_iterator);
	zend_class_implements(arango_cursor_cursor_ce TSRMLS_CC, 1, spl_ce_Countable);
	return SUCCESS;

}

/**
 * Cursor Id - might be null if Cursor does not have an id
 */
PHP_METHOD(Arango_Cursor_Cursor, getId) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "id");

}

/**
 * Full count of the result set (ignoring the outermost LIMIT)
 */
PHP_METHOD(Arango_Cursor_Cursor, getFullCount) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "fullCount");

}

/**
 * Extra data (statistics) returned from the statement
 */
PHP_METHOD(Arango_Cursor_Cursor, getExtra) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "extra");

}

/**
 * Number of HTTP calls that were made to build the cursor result
 */
PHP_METHOD(Arango_Cursor_Cursor, getFetches) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "fetches");

}

/**
 * Whether or not the query result was served from the AQL query result cache
 */
PHP_METHOD(Arango_Cursor_Cursor, getCached) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "cached");

}

/**
 * Initialise the cursor with the first results and some metadata
 *
 * @param Connection connection - connection to be used
 * @param array data -  initial result data as returned by the server
 * @param array options - cursor options
 *
 * @throws \Arango\Exception\ClientException
 */
PHP_METHOD(Arango_Cursor_Cursor, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval data, options;
	zval *connection, connection_sub, *data_param = NULL, *options_param = NULL, __$null, __$true, __$false, _0, _9, _10, _1$$3, _2$$4, _3$$4, _4$$4, _5$$5, _6$$5, _7$$5, _8$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &connection, &data_param, &options_param);

	zephir_get_arrval(&data, data_param);
	zephir_get_arrval(&options, options_param);


	zephir_update_property_zval(this_ptr, SL("connection"), connection);
	zephir_update_property_zval(this_ptr, SL("data"), &data);
	zephir_update_property_zval(this_ptr, SL("id"), &__$null);
	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, SL("extra"), &_0);
	if (0) {
		zephir_update_property_zval(this_ptr, SL("cached"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("cached"), &__$false);
	}
	if (zephir_array_isset_string(&data, SL("id"))) {
		zephir_array_fetch_string(&_1$$3, &data, SL("id"), PH_NOISY | PH_READONLY, "arango/cursor/cursor.zep", 152 TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("id"), &_1$$3);
	}
	if (zephir_array_isset_string(&data, SL("extra"))) {
		zephir_array_fetch_string(&_2$$4, &data, SL("extra"), PH_NOISY | PH_READONLY, "arango/cursor/cursor.zep", 156 TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("extra"), &_2$$4);
		zephir_read_property(&_3$$4, this_ptr, SL("extra"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_4$$4, &_3$$4, SL("stats"), PH_READONLY, "arango/cursor/cursor.zep", 158 TSRMLS_CC);
		if (zephir_array_isset_string(&_4$$4, SL("fullCount"))) {
			zephir_read_property(&_5$$5, this_ptr, SL("extra"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch_string(&_6$$5, &_5$$5, SL("stats"), PH_NOISY | PH_READONLY, "arango/cursor/cursor.zep", 159 TSRMLS_CC);
			zephir_array_fetch_string(&_7$$5, &_6$$5, SL("fullCount"), PH_NOISY | PH_READONLY, "arango/cursor/cursor.zep", 159 TSRMLS_CC);
			zephir_update_property_zval(this_ptr, SL("fullCount"), &_7$$5);
		}
	}
	if (zephir_array_isset_string(&data, SL("cached"))) {
		zephir_array_fetch_string(&_8$$6, &data, SL("cached"), PH_NOISY | PH_READONLY, "arango/cursor/cursor.zep", 164 TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("cached"), &_8$$6);
	}
	if (!(zephir_array_isset_string(&data, SL("hasMore")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(arango_exception_clientexception_ce, "'hasMore' attribute missing", "arango/cursor/cursor.zep", 168);
		return;
	}
	ZEPHIR_OBS_VAR(&_9);
	zephir_array_fetch_string(&_9, &data, SL("hasMore"), PH_NOISY, "arango/cursor/cursor.zep", 171 TSRMLS_CC);
	if (zephir_get_boolval(&_9)) {
		zephir_update_property_zval(this_ptr, SL("hasMore"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("hasMore"), &__$false);
	}
	zephir_array_update_string(&options, SL("_isNew"), &__$false, PH_COPY | PH_SEPARATE);
	zephir_update_property_zval(this_ptr, SL("options"), &options);
	ZEPHIR_INIT_VAR(&_10);
	array_init(&_10);
	zephir_update_property_zval(this_ptr, SL("result"), &_10);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "updatelength", NULL, 48);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "rewind", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Create an array of results from the input array
 *
 * @param array data
 *
 * @return void
 */
PHP_METHOD(Arango_Cursor_Cursor, addFlatFromArray) {

	zval *data_param = NULL;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_arrval(&data, data_param);


	zephir_update_property_array_append(this_ptr, SL("result"), &data TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Create a document from the input array
 *
 * @throws \Arango\Exception\ClientException
 *
 * @param array data
 *
 * @return void
 */
PHP_METHOD(Arango_Cursor_Cursor, addDocumentsFromArray) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *data_param = NULL, _0, _2;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_arrval(&data, data_param);


	zephir_read_property(&_2, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_CE_STATIC(&_0, arango_document_document_ce, "createfromarray", &_1, 0, &data, &_2);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("result"), &_0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Create an array of paths from input array
 *
 * @throws \Arango\Exception\ClientException
 *
 * @param array data - array of incoming paths Arrays
 *
 * @return void
 */
PHP_METHOD(Arango_Cursor_Cursor, addPathsFromArray) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *data_param = NULL, entry, _0, _1, _3, _4, _5, _6, value, _7, *_8, _11, *_12, _9$$3, _10$$3, _13$$4, _14$$4;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&entry);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_arrval(&data, data_param);


	ZEPHIR_INIT_VAR(&entry);
	zephir_create_array(&entry, 4, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_array_update_string(&entry, SL("vertices"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	array_init(&_0);
	zephir_array_update_string(&entry, SL("edges"), &_0, PH_COPY | PH_SEPARATE);
	zephir_array_fetch_string(&_3, &data, SL("source"), PH_NOISY | PH_READONLY, "arango/cursor/cursor.zep", 222 TSRMLS_CC);
	zephir_read_property(&_4, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_CE_STATIC(&_1, arango_document_document_ce, "createfromarray", &_2, 0, &_3, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&entry, SL("source"), &_1, PH_COPY | PH_SEPARATE);
	zephir_array_fetch_string(&_5, &data, SL("destination"), PH_NOISY | PH_READONLY, "arango/cursor/cursor.zep", 223 TSRMLS_CC);
	zephir_read_property(&_6, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_CE_STATIC(&_1, arango_document_document_ce, "createfromarray", &_2, 0, &_5, &_6);
	zephir_check_call_status();
	zephir_array_update_string(&entry, SL("destination"), &_1, PH_COPY | PH_SEPARATE);
	zephir_array_fetch_string(&_7, &data, SL("vertices"), PH_NOISY | PH_READONLY, "arango/cursor/cursor.zep", 227 TSRMLS_CC);
	zephir_is_iterable(&_7, 0, "arango/cursor/cursor.zep", 231);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_7), _8)
	{
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _8);
		zephir_read_property(&_10$$3, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_CE_STATIC(&_9$$3, arango_document_document_ce, "createfromarray", &_2, 0, &value, &_10$$3);
		zephir_check_call_status();
		zephir_array_update_multi(&entry, &_9$$3 TSRMLS_CC, SL("sa"), 3, SL("vertices"));
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	zephir_array_fetch_string(&_11, &data, SL("edges"), PH_NOISY | PH_READONLY, "arango/cursor/cursor.zep", 231 TSRMLS_CC);
	zephir_is_iterable(&_11, 0, "arango/cursor/cursor.zep", 235);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_11), _12)
	{
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _12);
		zephir_read_property(&_14$$4, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_CE_STATIC(&_13$$4, arango_document_edge_ce, "createfromarray", &_2, 0, &value, &_14$$4);
		zephir_check_call_status();
		zephir_array_update_multi(&entry, &_13$$4 TSRMLS_CC, SL("sa"), 3, SL("edges"));
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	zephir_update_property_array_append(this_ptr, SL("result"), &entry TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Create an array of shortest paths from the input array
 *
 * @throws \Arango\Exception\ClientException
 *
 * @param array data - array of incoming paths Arrays
 *
 * @return void
 */
PHP_METHOD(Arango_Cursor_Cursor, addShortestPathFromArray) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *data_param = NULL, entry, path, _0, _1, _3, _4, _5, _6, _7, value, _8, *_9, _10, *_11, _12$$5, _13$$5;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&entry);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_arrval(&data, data_param);


	if (!(zephir_array_isset_string(&data, SL("vertices")))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&entry);
	zephir_create_array(&entry, 4, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_array_update_string(&entry, SL("paths"), &_0, PH_COPY | PH_SEPARATE);
	zephir_array_fetch_string(&_3, &data, SL("source"), PH_NOISY | PH_READONLY, "arango/cursor/cursor.zep", 256 TSRMLS_CC);
	zephir_read_property(&_4, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_CE_STATIC(&_1, arango_document_document_ce, "createfromarray", &_2, 0, &_3, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&entry, SL("source"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(&_5);
	zephir_array_fetch_string(&_5, &data, SL("distance"), PH_NOISY, "arango/cursor/cursor.zep", 257 TSRMLS_CC);
	zephir_array_update_string(&entry, SL("distance"), &_5, PH_COPY | PH_SEPARATE);
	zephir_array_fetch_string(&_6, &data, SL("destination"), PH_NOISY | PH_READONLY, "arango/cursor/cursor.zep", 258 TSRMLS_CC);
	zephir_read_property(&_7, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_CE_STATIC(&_1, arango_document_document_ce, "createfromarray", &_2, 0, &_6, &_7);
	zephir_check_call_status();
	zephir_array_update_string(&entry, SL("destination"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&path);
	zephir_create_array(&path, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_0);
	array_init(&_0);
	zephir_array_update_string(&path, SL("vertices"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	array_init(&_0);
	zephir_array_update_string(&path, SL("edges"), &_0, PH_COPY | PH_SEPARATE);
	zephir_array_fetch_string(&_8, &data, SL("vertices"), PH_NOISY | PH_READONLY, "arango/cursor/cursor.zep", 267 TSRMLS_CC);
	zephir_is_iterable(&_8, 0, "arango/cursor/cursor.zep", 271);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_8), _9)
	{
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _9);
		zephir_array_update_multi(&path, &value TSRMLS_CC, SL("sa"), 3, SL("vertices"));
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	zephir_array_fetch_string(&_10, &data, SL("edges"), PH_NOISY | PH_READONLY, "arango/cursor/cursor.zep", 271 TSRMLS_CC);
	zephir_is_iterable(&_10, 0, "arango/cursor/cursor.zep", 275);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_10), _11)
	{
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _11);
		zephir_read_property(&_13$$5, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_CE_STATIC(&_12$$5, arango_document_edge_ce, "createfromarray", &_2, 0, &value, &_13$$5);
		zephir_check_call_status();
		zephir_array_update_multi(&entry, &_12$$5 TSRMLS_CC, SL("sa"), 3, SL("edges"));
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	zephir_array_update_string(&entry, SL("paths"), &path, PH_COPY | PH_SEPARATE);
	zephir_update_property_array_append(this_ptr, SL("result"), &entry TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Create an array of distances from the input array
 *
 * @param array data - array of incoming "paths" Arrays
 *
 * @return void
 */
PHP_METHOD(Arango_Cursor_Cursor, addDistanceToFromArray) {

	zval *data_param = NULL, entry, _0;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&entry);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_arrval(&data, data_param);


	ZEPHIR_INIT_VAR(&entry);
	zephir_create_array(&entry, 3, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_0);
	zephir_array_fetch_string(&_0, &data, SL("startVertex"), PH_NOISY, "arango/cursor/cursor.zep", 291 TSRMLS_CC);
	zephir_array_update_string(&entry, SL("source"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_array_fetch_string(&_0, &data, SL("distance"), PH_NOISY, "arango/cursor/cursor.zep", 292 TSRMLS_CC);
	zephir_array_update_string(&entry, SL("distance"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_array_fetch_string(&_0, &data, SL("vertex"), PH_NOISY, "arango/cursor/cursor.zep", 294 TSRMLS_CC);
	zephir_array_update_string(&entry, SL("destination"), &_0, PH_COPY | PH_SEPARATE);
	zephir_update_property_array_append(this_ptr, SL("result"), &entry TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Create an array of common neighbors from the input array
 *
 * @throws \Arango\Exception\ClientException
 *
 * @param array data - array of incoming "paths" Arrays
 *
 * @return void
 */
PHP_METHOD(Arango_Cursor_Cursor, addCommonNeighborsFromArray) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_8 = NULL;
	zval *data_param = NULL, left, right, _0, _2, _3, neighbor, _5, *_6, _1$$3, _4$$4, _7$$5;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&left);
	ZVAL_UNDEF(&right);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&neighbor);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_7$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_arrval(&data, data_param);


	ZEPHIR_OBS_VAR(&left);
	zephir_array_fetch_string(&left, &data, SL("left"), PH_NOISY, "arango/cursor/cursor.zep", 311 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&right);
	zephir_array_fetch_string(&right, &data, SL("right"), PH_NOISY, "arango/cursor/cursor.zep", 312 TSRMLS_CC);
	zephir_read_property(&_0, this_ptr, SL("result"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &left))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		array_init(&_1$$3);
		zephir_update_property_array(this_ptr, SL("result"), &left, &_1$$3 TSRMLS_CC);
	}
	zephir_read_property(&_2, this_ptr, SL("result"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_3, &_2, &left, PH_READONLY, "arango/cursor/cursor.zep", 318 TSRMLS_CC);
	if (!(zephir_array_isset(&_3, &right))) {
		ZEPHIR_INIT_VAR(&_4$$4);
		array_init(&_4$$4);
		zephir_update_property_array_multi(this_ptr, SL("result"), &_4$$4 TSRMLS_CC, SL("zz"), 2, &left, &right);
	}
	zephir_array_fetch_string(&_5, &data, SL("neighbors"), PH_NOISY | PH_READONLY, "arango/cursor/cursor.zep", 324 TSRMLS_CC);
	zephir_is_iterable(&_5, 0, "arango/cursor/cursor.zep", 327);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_5), _6)
	{
		ZEPHIR_INIT_NVAR(&neighbor);
		ZVAL_COPY(&neighbor, _6);
		ZEPHIR_CALL_CE_STATIC(&_7$$5, arango_document_document_ce, "createfromarray", &_8, 0, &neighbor);
		zephir_check_call_status();
		zephir_update_property_array_multi(this_ptr, SL("result"), &_7$$5 TSRMLS_CC, SL("zza"), 3, &left, &right);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&neighbor);
	ZEPHIR_MM_RESTORE();

}

/**
 * Create an array of common properties from the input array
 *
 * @param array data - array of incoming "paths" Arrays
 *
 * @return void
 */
PHP_METHOD(Arango_Cursor_Cursor, addCommonPropertiesFromArray) {

	zval *data_param = NULL, keys, _0, _1, common, _2, _3, *_4, id$$3, _5$$3;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&common);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&id$$3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_arrval(&data, data_param);


	ZEPHIR_INIT_VAR(&keys);
	zephir_array_keys(&keys, &data TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_array_fetch_long(&_1, &keys, 0, PH_NOISY, "arango/cursor/cursor.zep", 340 TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("result"), &_1, &_0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_3);
	zephir_array_fetch_long(&_3, &keys, 0, PH_NOISY, "arango/cursor/cursor.zep", 343 TSRMLS_CC);
	zephir_array_fetch(&_2, &data, &_3, PH_NOISY | PH_READONLY, "arango/cursor/cursor.zep", 343 TSRMLS_CC);
	zephir_is_iterable(&_2, 0, "arango/cursor/cursor.zep", 349);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_2), _4)
	{
		ZEPHIR_INIT_NVAR(&common);
		ZVAL_COPY(&common, _4);
		ZEPHIR_OBS_NVAR(&id$$3);
		zephir_array_fetch_string(&id$$3, &common, SL("_id"), PH_NOISY, "arango/cursor/cursor.zep", 345 TSRMLS_CC);
		zephir_array_unset_string(&common, SL("_id"), PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_5$$3);
		zephir_array_fetch_long(&_5$$3, &keys, 0, PH_NOISY, "arango/cursor/cursor.zep", 347 TSRMLS_CC);
		zephir_update_property_array_multi(this_ptr, SL("result"), &common TSRMLS_CC, SL("zz"), 2, &_5$$3, &id$$3);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&common);
	ZEPHIR_MM_RESTORE();

}

/**
 * Create an array of figuresfrom the input array
 *
 * @param array data - array of incoming "paths" Arrays
 *
 * @return void
 */
PHP_METHOD(Arango_Cursor_Cursor, addFigureFromArray) {

	zval *data_param = NULL;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_arrval(&data, data_param);


	zephir_update_property_zval(this_ptr, SL("result"), &data);
	ZEPHIR_MM_RESTORE();

}

/**
 * Create an array of Edges from the input array
 *
 * @param array data - array of incoming "paths" Arrays
 *
 * @return void
 */
PHP_METHOD(Arango_Cursor_Cursor, addEdgesFromArray) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *data_param = NULL, _0, _2;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_arrval(&data, data_param);


	zephir_read_property(&_2, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_CE_STATIC(&_0, arango_document_edge_ce, "createfromarray", &_1, 0, &data, &_2);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("result"), &_0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Create an array of Vertex from the input array
 *
 * @throws \Arango\Exception\ClientException
 *
 * @param array data - array of incoming "paths" Arrays
 *
 * @return void
 */
PHP_METHOD(Arango_Cursor_Cursor, addVerticesFromArray) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *data_param = NULL, _0, _2;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_arrval(&data, data_param);


	zephir_read_property(&_2, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_CE_STATIC(&_0, arango_document_vertex_ce, "createfromarray", &_1, 0, &data, &_2);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("result"), &_0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Fetch outstanding results from the server
 *
 * @throws \Exception
 * @return void
 */
PHP_METHOD(Arango_Cursor_Cursor, fetchOutstanding) {

	zval __$true, __$false, __$null, response, data, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("connection"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "url", NULL, 49);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, SL("id"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VSV(&_3, &_1, "/", &_2);
	ZEPHIR_INIT_VAR(&_4);
	array_init(&_4);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "");
	ZEPHIR_CALL_METHOD(&response, &_0, "put", NULL, 0, &_3, &_5, &_4);
	zephir_check_call_status();
	zephir_read_property(&_6, this_ptr, SL("fetches"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_ZVAL_NREF(_7);
	ZVAL_LONG(&_7, (zephir_get_numberval(&_6) + 1));
	zephir_update_property_zval(this_ptr, SL("fetches"), &_7);
	ZEPHIR_CALL_METHOD(&data, &response, "getjson", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&_8);
	zephir_array_fetch_string(&_8, &data, SL("hasMore"), PH_NOISY, "arango/cursor/cursor.zep", 398 TSRMLS_CC);
	if (zephir_get_boolval(&_8)) {
		zephir_update_property_zval(this_ptr, SL("hasMore"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("hasMore"), &__$false);
	}
	zephir_array_fetch_string(&_9, &data, SL("result"), PH_NOISY | PH_READONLY, "arango/cursor/cursor.zep", 399 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", NULL, 50, &_9);
	zephir_check_call_status();
	zephir_read_property(&_7, this_ptr, SL("hasMore"), PH_NOISY_CC | PH_READONLY);
	if (!zephir_is_true(&_7)) {
		zephir_update_property_zval(this_ptr, SL("id"), &__$null);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "updatelength", NULL, 48);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Rewind the cursor, necessary for Iterator
 *
 * @returns void
 */
PHP_METHOD(Arango_Cursor_Cursor, rewind) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval(this_ptr, SL("position"), &_0);

}

/**
 * Return the current result row, necessary for Iterator
 *
 * @returns array - The current result row as an associative array
 */
PHP_METHOD(Arango_Cursor_Cursor, current) {

	zval _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("result"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, this_ptr, SL("position"), PH_NOISY_CC);
	zephir_array_fetch(&_1, &_0, &_2, PH_NOISY | PH_READONLY, "arango/cursor/cursor.zep", 424 TSRMLS_CC);
	RETURN_CTOR(&_1);

}

/**
 * Return the index of the current result row, necessary for Iterator
 *
 * @returns int - The current result row index
 */
PHP_METHOD(Arango_Cursor_Cursor, key) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "position");

}

/**
 * Advance the cursor, necessary for Iterator
 *
 * @return void
 */
PHP_METHOD(Arango_Cursor_Cursor, next) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("position"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(&_1, (zephir_get_numberval(&_0) + 1));
	zephir_update_property_zval(this_ptr, SL("position"), &_1);

}

/**
 *  Check if cursor can be advanced further, necessary for Iterator
 *
 * This might issue additional HTTP requests to fetch any outstanding
 * results from the server
 *
 * @throws \Exception
 * @return boolean - True if the cursor can be advanced further, false if cursor is at end
 */
PHP_METHOD(Arango_Cursor_Cursor, valid) {

	zend_bool _3;
	zval _0, _1, _2, _4, _5, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);


	zephir_read_property(&_0, this_ptr, SL("position"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("length"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_LE_LONG(&_0, (zephir_get_numberval(&_1) - 1))) {
		RETURN_BOOL(1);
	}
	zephir_read_property(&_2, this_ptr, SL("hasMore"), PH_NOISY_CC | PH_READONLY);
	_3 = !zephir_is_true(&_2);
	if (!(_3)) {
		zephir_read_property(&_4, this_ptr, SL("id"), PH_NOISY_CC | PH_READONLY);
		_3 = !zephir_is_true(&_4);
	}
	if (_3) {
		RETURN_BOOL(0);
	}
	zephir_read_property(&_5, this_ptr, SL("position"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_6, this_ptr, SL("length"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(ZEPHIR_LE_LONG(&_5, (zephir_get_numberval(&_6) - 1)));

}

/**
 * Sanitize the result set rows
 *
 * This will remove the _id and _rev attributes from the results if the
 * "sanitize" option is set
 *
 * @param array rows - Array of rows to be sanitized
 *
 * @return array - Sanitized rows
 */
PHP_METHOD(Arango_Cursor_Cursor, sanitize) {

	zend_string *_6$$3;
	zend_ulong _5$$3;
	zend_bool _1, _7$$4, _9$$4;
	zval *rows_param = NULL, _0, _2, _3, key$$3, value$$3, *_4$$3, _8$$5, _10$$6;
	zval rows;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rows);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&key$$3);
	ZVAL_UNDEF(&value$$3);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_10$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &rows_param);

	zephir_get_arrval(&rows, rows_param);


	zephir_read_property(&_0, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset_string(&_0, SL("_sanitize"));
	if (_1) {
		zephir_read_property(&_2, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_3, &_2, SL("_sanitize"), PH_NOISY | PH_READONLY, "arango/cursor/cursor.zep", 480 TSRMLS_CC);
		_1 = zephir_is_true(&_3);
	}
	if (_1) {
		zephir_is_iterable(&rows, 0, "arango/cursor/cursor.zep", 491);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&rows), _5$$3, _6$$3, _4$$3)
		{
			ZEPHIR_INIT_NVAR(&key$$3);
			if (_6$$3 != NULL) { 
				ZVAL_STR_COPY(&key$$3, _6$$3);
			} else {
				ZVAL_LONG(&key$$3, _5$$3);
			}
			ZEPHIR_INIT_NVAR(&value$$3);
			ZVAL_COPY(&value$$3, _4$$3);
			_7$$4 = Z_TYPE_P(&value$$3) == IS_ARRAY;
			if (_7$$4) {
				_7$$4 = zephir_array_isset_string(&value$$3, SL("id"));
			}
			if (_7$$4) {
				zephir_array_fetch(&_8$$5, &rows, &key$$3, PH_NOISY | PH_READONLY, "arango/cursor/cursor.zep", 484 TSRMLS_CC);
				zephir_array_unset_string(&_8$$5, SL("id"), PH_SEPARATE);
			}
			_9$$4 = Z_TYPE_P(&value$$3) == IS_ARRAY;
			if (_9$$4) {
				_9$$4 = zephir_array_isset_string(&value$$3, SL("_rev"));
			}
			if (_9$$4) {
				zephir_array_fetch(&_10$$6, &rows, &key$$3, PH_NOISY | PH_READONLY, "arango/cursor/cursor.zep", 488 TSRMLS_CC);
				zephir_array_unset_string(&_10$$6, SL("_rev"), PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value$$3);
		ZEPHIR_INIT_NVAR(&key$$3);
	}
	RETURN_CTOR(&rows);

}

/**
 * Set the length of the fetched result set
 *
 * @return void
 */
PHP_METHOD(Arango_Cursor_Cursor, updateLength) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("result"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(&_1, zephir_fast_count_int(&_0 TSRMLS_CC));
	zephir_update_property_zval(this_ptr, SL("length"), &_1);

}

/**
 * \Countable method
 *
 * @return int
 */
PHP_METHOD(Arango_Cursor_Cursor, count) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "length");

}

/**
 * Return the base url for cursor
 *
 * @return string
 */
PHP_METHOD(Arango_Cursor_Cursor, url) {

	zval _0, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);


	zephir_read_property(&_0, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string(&_0, SL("baseurl"))) {
		zephir_read_property(&_1$$3, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_2$$3, &_1$$3, SL("baseurl"), PH_NOISY | PH_READONLY, "arango/cursor/cursor.zep", 520 TSRMLS_CC);
		RETURN_CTORW(&_2$$3);
	}
	RETURN_STRING("/_api/cursor");

}

/**
 * Create an array of results from the input array
 *
 * @param array data - incoming results
 *
 * @return int
 */
PHP_METHOD(Arango_Cursor_Cursor, add) {

	zend_bool _5$$3, _7$$3;
	zend_string *_4;
	zend_ulong _3;
	zephir_fcall_cache_entry *_10 = NULL, *_12 = NULL, *_15 = NULL, *_16 = NULL, *_17 = NULL, *_18 = NULL, *_19 = NULL, *_20 = NULL, *_21 = NULL, *_22 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, row, _0, _1, *_2, _6$$3, _8$$3, _9$$3, _11$$3, _13$$3, _14$$3;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&row);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_14$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_arrval(&data, data_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "sanitize", NULL, 51, &data);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	zephir_is_iterable(&_0, 0, "arango/cursor/cursor.zep", 577);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _3, _4, _2)
	{
		ZEPHIR_INIT_NVAR(&_1);
		if (_4 != NULL) { 
			ZVAL_STR_COPY(&_1, _4);
		} else {
			ZVAL_LONG(&_1, _3);
		}
		ZEPHIR_INIT_NVAR(&row);
		ZVAL_COPY(&row, _2);
		_5$$3 = !(Z_TYPE_P(&row) == IS_ARRAY);
		if (!(_5$$3)) {
			zephir_read_property(&_6$$3, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
			_7$$3 = zephir_array_isset_string(&_6$$3, SL("_flat"));
			if (_7$$3) {
				zephir_read_property(&_8$$3, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_OBS_NVAR(&_9$$3);
				zephir_array_fetch_string(&_9$$3, &_8$$3, SL("_flat"), PH_NOISY, "arango/cursor/cursor.zep", 537 TSRMLS_CC);
				_7$$3 = zephir_is_true(&_9$$3);
			}
			_5$$3 = _7$$3;
		}
		if (_5$$3) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "addflatfromarray", &_10, 52, &row);
			zephir_check_call_status();
			continue;
		}
		zephir_read_property(&_11$$3, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		if (!(zephir_array_isset_string(&_11$$3, SL("objectType")))) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "adddocumentsfromarray", &_12, 53, &row);
			zephir_check_call_status();
			continue;
		}
		zephir_read_property(&_13$$3, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_NVAR(&_14$$3);
		zephir_array_fetch_string(&_14$$3, &_13$$3, SL("objectType"), PH_NOISY, "arango/cursor/cursor.zep", 547 TSRMLS_CC);
		do {
			if (ZEPHIR_IS_STRING(&_14$$3, "edge")) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "addedgesfromarray", &_15, 54, &row);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_STRING(&_14$$3, "vertex")) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "addverticesfromarray", &_16, 55, &row);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_STRING(&_14$$3, "path")) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "addpathsfromarray", &_17, 56, &row);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_STRING(&_14$$3, "shortestPath")) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "addshortestpathfromarray", &_18, 57, &row);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_STRING(&_14$$3, "distanceTo")) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "adddistancetofromarray", &_19, 58, &row);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_STRING(&_14$$3, "commonNeighbors")) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "addcommonneighborsfromarray", &_20, 59, &row);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_STRING(&_14$$3, "commonProperties")) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "addcommonpropertiesfromarray", &_21, 60, &row);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_STRING(&_14$$3, "figure")) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "addfigurefromarray", &_22, 61, &row);
				zephir_check_call_status();
				break;
			}
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "adddocumentsfromarray", &_12, 53, &row);
			zephir_check_call_status();
			break;
		} while(0);

	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&row);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get a statistical figure value from the query result
 *
 * @param string name - Name of figure to return
 *
 * @return int
 */
PHP_METHOD(Arango_Cursor_Cursor, getStatValue) {

	zval *name_param = NULL, _0, _1, _2$$3, _3$$3, _4$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("stats"), PH_READONLY, "arango/cursor/cursor.zep", 587 TSRMLS_CC);
	if (zephir_array_isset(&_1, &name)) {
		zephir_read_property(&_2$$3, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_3$$3, &_2$$3, SL("stats"), PH_NOISY | PH_READONLY, "arango/cursor/cursor.zep", 588 TSRMLS_CC);
		zephir_array_fetch(&_4$$3, &_3$$3, &name, PH_NOISY | PH_READONLY, "arango/cursor/cursor.zep", 588 TSRMLS_CC);
		RETURN_CTOR(&_4$$3);
	}
	RETURN_MM_LONG(0);

}

/**
 * Get MetaData of the current cursor
 *
 * @return array
 */
PHP_METHOD(Arango_Cursor_Cursor, getMetadata) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "data");

}

/**
 * Return the warnings issued during query execution
 *
 * @return array
 */
PHP_METHOD(Arango_Cursor_Cursor, getWarnings) {

	zval _0, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);


	zephir_read_property(&_0, this_ptr, SL("extra"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string(&_0, SL("warnings"))) {
		zephir_read_property(&_1$$3, this_ptr, SL("extra"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_2$$3, &_1$$3, SL("warnings"), PH_NOISY | PH_READONLY, "arango/cursor/cursor.zep", 610 TSRMLS_CC);
		RETURN_CTORW(&_2$$3);
	}
	array_init(return_value);
	return;

}

/**
 * Return the number of writes executed by the query
 *
 * @return int
 */
PHP_METHOD(Arango_Cursor_Cursor, getWritesExecuted) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "writesExecuted");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getstatvalue", NULL, 62, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Return the number of ignored write operations from the query
 *
 * @return int
 */
PHP_METHOD(Arango_Cursor_Cursor, getWritesIgnored) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "writesIgnored");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getstatvalue", NULL, 62, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Return the number of documents iterated over in full scans
 *
 * @return int
 */
PHP_METHOD(Arango_Cursor_Cursor, getScannedFull) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "scannedFull");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getstatvalue", NULL, 62, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Return the number of documents iterated over in index scans
 *
 * @return int
 */
PHP_METHOD(Arango_Cursor_Cursor, getScannedIndex) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "scannedIndex");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getstatvalue", NULL, 62, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Return the number of documents filtered by query
 *
 * @return int
 */
PHP_METHOD(Arango_Cursor_Cursor, getFiltered) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "filtered");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getstatvalue", NULL, 62, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

