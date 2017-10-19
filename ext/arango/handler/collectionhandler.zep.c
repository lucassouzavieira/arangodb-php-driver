
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/exception.h"


/**
 * A handler that manages collections
 * TODO Finish
 * @package Arango/Handler
 * @class CollectionHandler
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Handler_CollectionHandler) {

	ZEPHIR_REGISTER_CLASS_EX(Arango\\Handler, CollectionHandler, arango, handler_collectionhandler, arango_handler_handler_ce, arango_handler_collectionhandler_method_entry, 0);

	/**
	 * Class indexes
	 */
	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("ENTRY_DOCUMENTS"), "documents");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_COLLECTION"), "collection");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_EXAMPLE"), "example");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_NEW_VALUE"), "newValue");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_CREATE_COLLECTION"), "createCollection");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_ATTRIBUTE"), "attribute");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_KEYS"), "keys");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_LEFT"), "left");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_RIGHT"), "right");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_LATITUDE"), "latitude");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_LONGITUDE"), "longitude");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_DISTANCE"), "distance");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_RADIUS"), "radius");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_SKIP"), "skip");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_INDEX"), "index");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_LIMIT"), "limit");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_FIELDS"), "fields");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_UNIQUE"), "unique");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_TYPE"), "type");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_SIZE"), "size");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_GEO_INDEX"), "geo");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_GEO_JSON"), "geoJson");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_IGNORE_NULL"), "ignoreNull");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_CONSTRAINT"), "constraint");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_HASH_INDEX"), "hash");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_FULLTEXT_INDEX"), "fulltext");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_MIN_LENGHT"), "minLenght");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_SKIPLIST_INDEX"), "skiplist");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_PERSISTENT_LENGHT"), "persistent");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_SPARSE"), "sparse");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_COUNT"), "count");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_QUERY"), "query");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_CHECKSUM"), "checksum");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_REVISION"), "revision");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_PROPERTIES"), "properties");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_FIGURES"), "figures");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_LOAD"), "load");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_UNLOAD"), "unload");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_TRUNCATE"), "truncate");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_RENAME"), "rename");

	zephir_declare_class_constant_string(arango_handler_collectionhandler_ce, SL("OPTION_EXCLUDE_SYSTEM"), "excludeSystem");

	return SUCCESS;

}

/**
 * Creates a new collection on the server
 *
 * This will add the collection on the server and return its id <br>
 * The id is mainly returned for backwards compatibility, but you should use the collection name for any reference to the collection.<br>
 * This will throw if the collection cannot be created <br>
 *
 * @throws Exception
 *
 * @param string $name A string with the collection name
 * @param array $options An array of options. Options are :
 *                          'type'            - 2 -> normal collection, 3 -> edge-collection
 *                          'waitForSync'     -  if set to true, then all removal operations will instantly be synchronised to disk / If this is not specified, then the collection's default sync behavior will be applied.
 *                          'journalSize'     -  journalSize value.
 *                          'isSystem'        -  false->user collection(default), true->system collection .
 *                          'isVolatile'      -  false->persistent collection(default), true->volatile (in-memory) collection .
 *                          'numberOfShards'  -  number of shards for the collection.
 *                          'shardKeys'       -  list of shard key attributes.
 *
 * @return mixed - id of collection created
 */
PHP_METHOD(Arango_Handler_CollectionHandler, create) {

	zephir_fcall_cache_entry *_1 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *name_param = NULL, *options_param = NULL, collection, params, _0, type, _2, _4, response, data, _6, _7, _9, _10, _11, _3$$5, _5$$6;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &options_param);

	zephir_get_strval(&name, name_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&collection);
	object_init_ex(&collection, arango_collection_collection_ce);
	ZEPHIR_CALL_METHOD(NULL, &collection, "__construct", NULL, 19, &name);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &collection, "setname", NULL, 63, &name);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "setcollectiondefaults", NULL, 64, &collection);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&collection, &_0);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "setcollectionvalues", NULL, 65, &collection);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&collection, &_0);
	ZEPHIR_CALL_METHOD(&_0, &collection, "gettype", NULL, 66);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_CE_STATIC(&type, arango_collection_collection_ce, "getdefaulttype", &_1, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&type, &collection, "gettype", NULL, 66);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&params);
	zephir_create_array(&params, 7, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_2, &collection, "getname", NULL, 67);
	zephir_check_call_status();
	zephir_array_update_string(&params, SL("name"), &_2, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&params, SL("type"), &type, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_2, &collection, "getwaitforsync", NULL, 68);
	zephir_check_call_status();
	zephir_array_update_string(&params, SL("waitForSync"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_2, &collection, "getjournalsize", NULL, 69);
	zephir_check_call_status();
	zephir_array_update_string(&params, SL("journalSize"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_2, &collection, "getissystem", NULL, 70);
	zephir_check_call_status();
	zephir_array_update_string(&params, SL("isSystem"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_2, &collection, "getisvolatile", NULL, 71);
	zephir_check_call_status();
	zephir_array_update_string(&params, SL("isVolatile"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_2, &collection, "getkeyoptions", NULL, 72);
	zephir_check_call_status();
	zephir_array_update_string(&params, SL("keyOptions"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_2, &collection, "getnumberofshards", NULL, 73);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZEPHIR_CALL_METHOD(&_3$$5, &collection, "getnumberofshards", NULL, 73);
		zephir_check_call_status();
		zephir_array_update_string(&params, SL("numberOfShards"), &_3$$5, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_METHOD(&_4, &collection, "getshardkeys", NULL, 74);
	zephir_check_call_status();
	if (Z_TYPE_P(&_4) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_5$$6, &collection, "getshardkeys", NULL, 74);
		zephir_check_call_status();
		zephir_array_update_string(&params, SL("shardKeys"), &_5$$6, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_7, arango_connection_encoding_ce, "jsonwrapper", &_8, 0, &params);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "/_api/collection");
	ZEPHIR_CALL_METHOD(&response, &_6, "post", NULL, 0, &_9, &_7);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&data, &response, "toarray", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_string(&_10, &data, SL("id"), PH_NOISY | PH_READONLY, "arango/handler/collectionhandler.zep", 126 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, &collection, "setid", NULL, 20, &_10);
	zephir_check_call_status();
	zephir_array_fetch_string(&_11, &data, SL("id"), PH_NOISY | PH_READONLY, "arango/handler/collectionhandler.zep", 127 TSRMLS_CC);
	RETURN_CTOR(&_11);

}

/**
 * Set defaults values for a collection object
 *
 * @param Collection collection - Collection object
 *
 * @return Collection
 */
PHP_METHOD(Arango_Handler_CollectionHandler, setCollectionDefaults) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *collection, collection_sub, _0, _2, _3, _4, _5, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &collection);



	ZEPHIR_CALL_CE_STATIC(&_0, arango_collection_collection_ce, "getdefaulttype", &_1, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, collection, "settype", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "waitForSync");
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getconnectionoption", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, collection, "setwaitforsync", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "journalSize");
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getconnectionoption", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, collection, "setjournalsize", NULL, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "isSystem");
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getconnectionoption", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, collection, "setissystem", NULL, 0, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "isVolatile");
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "getconnectionoption", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, collection, "setisvolatile", NULL, 0, &_6);
	zephir_check_call_status();
	RETVAL_ZVAL(collection, 1, 0);
	RETURN_MM();

}

/**
 * Set options values for a collection object
 *
 * @param Collection collection - Collection object
 *
 * @return Collection
 */
PHP_METHOD(Arango_Handler_CollectionHandler, setCollectionValues) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *collection, collection_sub, *options_param = NULL, _0$$3, _1$$4, _2$$5, _3$$6, _4$$7, _5$$8, _6$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &collection, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	if (zephir_array_isset_string(&options, SL("type"))) {
		zephir_array_fetch_string(&_0$$3, &options, SL("type"), PH_NOISY | PH_READONLY, "arango/handler/collectionhandler.zep", 157 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, collection, "settype", NULL, 0, &_0$$3);
		zephir_check_call_status();
	}
	if (zephir_array_isset_string(&options, SL("waitForSync"))) {
		zephir_array_fetch_string(&_1$$4, &options, SL("waitForSync"), PH_NOISY | PH_READONLY, "arango/handler/collectionhandler.zep", 161 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, collection, "setwaitforsync", NULL, 0, &_1$$4);
		zephir_check_call_status();
	}
	if (zephir_array_isset_string(&options, SL("journalSize"))) {
		zephir_array_fetch_string(&_2$$5, &options, SL("journalSize"), PH_NOISY | PH_READONLY, "arango/handler/collectionhandler.zep", 165 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, collection, "setjournalsize", NULL, 0, &_2$$5);
		zephir_check_call_status();
	}
	if (zephir_array_isset_string(&options, SL("isSystem"))) {
		zephir_array_fetch_string(&_3$$6, &options, SL("isSystem"), PH_NOISY | PH_READONLY, "arango/handler/collectionhandler.zep", 169 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, collection, "setissystem", NULL, 0, &_3$$6);
		zephir_check_call_status();
	}
	if (zephir_array_isset_string(&options, SL("isVolatile"))) {
		zephir_array_fetch_string(&_4$$7, &options, SL("isVolatile"), PH_NOISY | PH_READONLY, "arango/handler/collectionhandler.zep", 173 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, collection, "setisvolatile", NULL, 0, &_4$$7);
		zephir_check_call_status();
	}
	if (zephir_array_isset_string(&options, SL("numberOfShards"))) {
		zephir_array_fetch_string(&_5$$8, &options, SL("numberOfShards"), PH_NOISY | PH_READONLY, "arango/handler/collectionhandler.zep", 177 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, collection, "setnumberofshards", NULL, 0, &_5$$8);
		zephir_check_call_status();
	}
	if (zephir_array_isset_string(&options, SL("shardKeys"))) {
		zephir_array_fetch_string(&_6$$9, &options, SL("shardKeys"), PH_NOISY | PH_READONLY, "arango/handler/collectionhandler.zep", 181 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, collection, "setshardkeys", NULL, 0, &_6$$9);
		zephir_check_call_status();
	}
	RETVAL_ZVAL(collection, 1, 0);
	RETURN_MM();

}

/**
 * Check if a collection exists
 *
 * @throws Arango\Exception\ServerException | \Exception
 *
 * @param mixed collection - Collection ID as string or number
 *
 * @return boolean
 */
PHP_METHOD(Arango_Handler_CollectionHandler, has) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collectionId, collectionId_sub, exception, _1, _0$$3, _2$$4, _3$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collectionId_sub);
	ZVAL_UNDEF(&exception);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &collectionId);




	/* try_start_1: */

		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "getcollectionname", NULL, 0, collectionId);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "retrievefromserver", NULL, 75, &_0$$3);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_1);
		ZVAL_OBJ(&_1, EG(exception));
		Z_ADDREF_P(&_1);
		if (zephir_instance_of_ev(&_1, arango_exception_serverexception_ce TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&exception, &_1);
			ZEPHIR_CALL_METHOD(&_2$$4, &exception, "getcode", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG(&_2$$4, 404)) {
				RETURN_MM_BOOL(0);
			}
			zephir_throw_exception_debug(&exception, "arango/handler/collectionhandler.zep", 209 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		} else {
			if (zephir_instance_of_ev(&_1, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(&exception, &_1);
				ZEPHIR_CALL_METHOD(&_3$$7, &exception, "getcode", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG(&_3$$7, 404)) {
					RETURN_MM_BOOL(0);
				}
				zephir_throw_exception_debug(&exception, "arango/handler/collectionhandler.zep", 209 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * Get the number of documents in a collection
 *
 * @throws \Exception
 *
 * @param mixed collectionId - Collection ID as string or number
 *
 * @return int
 */
PHP_METHOD(Arango_Handler_CollectionHandler, count) {

	zval _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *collectionId, collectionId_sub, url, response, data, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collectionId_sub);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &collectionId);



	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getcollectionname", NULL, 0, collectionId);
	zephir_check_call_status();
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "count");
	zephir_array_fast_append(&_1, &_3);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "/_api/collection");
	ZEPHIR_CALL_CE_STATIC(&url, arango_http_url_ce, "buildurl", &_0, 0, &_3, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, &_2, "get", NULL, 0, &url);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&data, &response, "toarray", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&_4);
	zephir_array_fetch_string(&_4, &data, SL("count"), PH_NOISY, "arango/handler/collectionhandler.zep", 235 TSRMLS_CC);
	RETURN_MM_LONG(zephir_get_intval(&_4));

}

/**
 * Get figures for a collection
 *
 * @throws \Exception
 *
 * @param mixed collectionId - Collection ID as string or number
 *
 * @return array
 */
PHP_METHOD(Arango_Handler_CollectionHandler, figures) {

	zval _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *collectionId, collectionId_sub, url, response, data, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collectionId_sub);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &collectionId);



	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getcollectionname", NULL, 0, collectionId);
	zephir_check_call_status();
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "figures");
	zephir_array_fast_append(&_1, &_3);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "/_api/collection");
	ZEPHIR_CALL_CE_STATIC(&url, arango_http_url_ce, "buildurl", &_0, 0, &_3, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, &_2, "get", NULL, 0, &url);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&data, &response, "toarray", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_string(&_4, &data, SL("figures"), PH_NOISY | PH_READONLY, "arango/handler/collectionhandler.zep", 258 TSRMLS_CC);
	RETURN_CTOR(&_4);

}

/**
 * Get collection from the server
 *
 * @throws \Exception
 *
 * @param mixed collectionId - Collection ID as string or number
 *
 * @return Collection
 */
PHP_METHOD(Arango_Handler_CollectionHandler, retrieveFromServer) {

	zval _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_4 = NULL;
	zval *collectionId, collectionId_sub, url, response, _2, _3, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collectionId_sub);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &collectionId);



	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(&_1, collectionId);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "/_api/collection");
	ZEPHIR_CALL_CE_STATIC(&url, arango_http_url_ce, "buildurl", &_0, 0, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, &_3, "get", NULL, 0, &url);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, &response, "toarray", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_CE_STATIC(arango_collection_collection_ce, "createfromarray", &_4, 0, &_5);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get collection properties from the server
 *
 * @throws \Exception
 *
 * @param mixed collectionId - Collection ID as string or number
 *
 * @return Collection
 */
PHP_METHOD(Arango_Handler_CollectionHandler, getProperties) {

	zval _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_4 = NULL;
	zval *collectionId, collectionId_sub, url, response, _2, _3, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collectionId_sub);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &collectionId);



	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getcollectionname", NULL, 0, collectionId);
	zephir_check_call_status();
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "properties");
	zephir_array_fast_append(&_1, &_3);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "/_api/collection");
	ZEPHIR_CALL_CE_STATIC(&url, arango_http_url_ce, "buildurl", &_0, 0, &_3, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, &_2, "get", NULL, 0, &url);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, &response, "toarray", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_CE_STATIC(arango_collection_collection_ce, "createfromarray", &_4, 0, &_5);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Calculates a checksum of the collection
 *
 * @throws \Exception
 *
 * @param mixed collectionId    - Collection ID as string or number
 * @param boolean withRevisions - Optional boolean wheter or not to include document revision ids in checksum calculation
 * @param boolean withData      - Optional boolean wheter or not to include document body data ids in checksum calculation
 *
 * @return array  - Contains keys "checksum" and "revision"
 */
PHP_METHOD(Arango_Handler_CollectionHandler, getChecksum) {

	zval _1, _5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_4 = NULL;
	zend_bool withRevisions, withData;
	zval *collectionId, collectionId_sub, *withRevisions_param = NULL, *withData_param = NULL, url, response, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collectionId_sub);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &collectionId, &withRevisions_param, &withData_param);

	if (!withRevisions_param) {
		withRevisions = 0;
	} else {
		withRevisions = zephir_get_boolval(withRevisions_param);
	}
	if (!withData_param) {
		withData = 0;
	} else {
		withData = zephir_get_boolval(withData_param);
	}


	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getcollectionname", NULL, 0, collectionId);
	zephir_check_call_status();
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "checksum");
	zephir_array_fast_append(&_1, &_3);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "/_api/collection");
	ZEPHIR_CALL_CE_STATIC(&url, arango_http_url_ce, "buildurl", &_0, 0, &_3, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_BOOL(&_3, withRevisions);
	zephir_array_update_string(&_5, SL("withRevisions"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_BOOL(&_3, withData);
	zephir_array_update_string(&_5, SL("withData"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_CE_STATIC(&_2, arango_http_url_ce, "appendparamstourl", &_4, 0, &url, &_5);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&url, &_2);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, &_2, "get", NULL, 0, &url);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&response, "toarray", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the collection revision ID
 *
 * @throws \Exception
 *
 * @param mixed collectionId - Collection ID as string or number
 *
 * @return array
 */
PHP_METHOD(Arango_Handler_CollectionHandler, getRevision) {

	zval _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *collectionId, collectionId_sub, url, response, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collectionId_sub);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &collectionId);



	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getcollectionname", NULL, 0, collectionId);
	zephir_check_call_status();
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "revision");
	zephir_array_fast_append(&_1, &_3);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "/_api/collection");
	ZEPHIR_CALL_CE_STATIC(&url, arango_http_url_ce, "buildurl", &_0, 0, &_3, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, &_2, "get", NULL, 0, &url);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&response, "toarray", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get the information about an index in a collection
 *
 * @throws \Exception
 *
 * @param string collectionId - Collection ID as string
 * @param string indexId      - Index ID as string
 *
 * @return array
 */
PHP_METHOD(Arango_Handler_CollectionHandler, getIndex) {

	zval _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *collectionId_param = NULL, *indexId_param = NULL, url, response, _2, _3;
	zval collectionId, indexId;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collectionId);
	ZVAL_UNDEF(&indexId);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &collectionId_param, &indexId_param);

	zephir_get_strval(&collectionId, collectionId_param);
	zephir_get_strval(&indexId, indexId_param);


	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_1, &collectionId);
	zephir_array_fast_append(&_1, &indexId);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "/_api/index");
	ZEPHIR_CALL_CE_STATIC(&url, arango_http_url_ce, "buildurl", &_0, 0, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, &_3, "get", NULL, 0, &url);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&response, "toarray", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get indexes of a collection
 *
 * @throws \Exception
 *
 * @param string collectionId - Collection ID as string or number
 *
 * @return array
 */
PHP_METHOD(Arango_Handler_CollectionHandler, getIndexes) {

	zval _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *collectionId, collectionId_sub, url, response, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collectionId_sub);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &collectionId);



	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getcollectionname", NULL, 0, collectionId);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("collection"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "/_api/index");
	ZEPHIR_CALL_CE_STATIC(&url, arango_http_url_ce, "buildurl", &_0, 0, &_3, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, &_2, "get", NULL, 0, &url);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&response, "toarray", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Drop an index
 *
 * @throws \Exception
 *
 * @param string collectionId - Collection ID as string
 * @param string indexId      - Index ID as string
 *
 * @return boolean - always true, will throw an exception if an error
 */
PHP_METHOD(Arango_Handler_CollectionHandler, dropIndex) {

	zval _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *collectionId_param = NULL, *indexId_param = NULL, url, _2, _3;
	zval collectionId, indexId;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collectionId);
	ZVAL_UNDEF(&indexId);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &collectionId_param, &indexId_param);

	zephir_get_strval(&collectionId, collectionId_param);
	zephir_get_strval(&indexId, indexId_param);


	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getcollectionname", NULL, 0, &collectionId);
	zephir_check_call_status();
	zephir_array_fast_append(&_1, &_2);
	zephir_array_fast_append(&_1, &indexId);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "/_api/index");
	ZEPHIR_CALL_CE_STATIC(&url, arango_http_url_ce, "buildurl", &_0, 0, &_3, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_2, "delete", NULL, 0, &url);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);

}

/**
 * Get a random document from the collection
 *
 * @throws \Exception - If document cannot be fetched from the server
 *
 * @param string collectionId - Collection ID as string
 *
 * @return Document
 */
PHP_METHOD(Arango_Handler_CollectionHandler, any) {

	zval *collectionId, collectionId_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collectionId_sub);

	zephir_fetch_params(0, 1, 0, &collectionId);




}

