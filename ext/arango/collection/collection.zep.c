
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/exception.h"


/**
 * Represents a Collection in Arango Database
 *
 * @package Arango/Collection
 * @class Collection
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Collection_Collection) {

	ZEPHIR_REGISTER_CLASS(Arango\\Collection, Collection, arango, collection_collection, arango_collection_collection_method_entry, 0);

	/**
	 * Collection id (might be NULL for new collections)
	 *
	 * @var mixed
	 */
	zend_declare_property_null(arango_collection_collection_ce, SL("id"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Collection name (might be NULL for new collections)
	 *
	 * @var string
	 */
	zend_declare_property_null(arango_collection_collection_ce, SL("name"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Collection type (might be NULL for new collections)
	 *
	 * @var int
	 */
	zend_declare_property_null(arango_collection_collection_ce, SL("type"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Collection waitForSync value (might be NULL for new collections)
	 *
	 * @var boolean
	 */
	zend_declare_property_null(arango_collection_collection_ce, SL("waitForSync"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Collection journalSize value (might be NULL for new collections)
	 *
	 * @var int
	 */
	zend_declare_property_null(arango_collection_collection_ce, SL("journalSize"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Collection isSystem value (might be NULL for new collections)
	 *
	 * @var boolean
	 */
	zend_declare_property_null(arango_collection_collection_ce, SL("isSystem"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Collection isVolatile value (might be NULL for new collections)
	 *
	 * @var boolean
	 */
	zend_declare_property_null(arango_collection_collection_ce, SL("isVolatile"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Collection numberOfShards value (might be NULL for new collections)
	 *
	 * @var int
	 */
	zend_declare_property_null(arango_collection_collection_ce, SL("numberOfShards"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Collection shardKeys value (might be NULL for new collections)
	 *
	 * @var array
	 */
	zend_declare_property_null(arango_collection_collection_ce, SL("shardKeys"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Collection status value (might be NULL for new collections)
	 *
	 * @var int
	 */
	zend_declare_property_null(arango_collection_collection_ce, SL("status"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Collection keyOptions value (might be NULL for new collections)
	 *
	 * @var array
	 */
	zend_declare_property_null(arango_collection_collection_ce, SL("keyOptions"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Collection indexes
	 */
	zephir_declare_class_constant_string(arango_collection_collection_ce, SL("ENTRY_ID"), "id");

	zephir_declare_class_constant_string(arango_collection_collection_ce, SL("ENTRY_NAME"), "name");

	zephir_declare_class_constant_string(arango_collection_collection_ce, SL("ENTRY_TYPE"), "type");

	zephir_declare_class_constant_string(arango_collection_collection_ce, SL("ENTRY_WAIT_SYNC"), "waitForSync");

	zephir_declare_class_constant_string(arango_collection_collection_ce, SL("ENTRY_JOURNAL_SIZE"), "journalSize");

	zephir_declare_class_constant_string(arango_collection_collection_ce, SL("ENTRY_STATUS"), "status");

	zephir_declare_class_constant_string(arango_collection_collection_ce, SL("ENTRY_KEY_OPTIONS"), "keyOptions");

	zephir_declare_class_constant_string(arango_collection_collection_ce, SL("ENTRY_IS_SYSTEM"), "isSystem");

	zephir_declare_class_constant_string(arango_collection_collection_ce, SL("ENTRY_IS_VOLATILE"), "isVolatile");

	zephir_declare_class_constant_string(arango_collection_collection_ce, SL("ENTRY_NUMBER_OF_SHARDS"), "numberOfShards");

	zephir_declare_class_constant_string(arango_collection_collection_ce, SL("ENTRY_SHARD_KEYS"), "shardKeys");

	zephir_declare_class_constant_string(arango_collection_collection_ce, SL("OPTION_PROPERTIES"), "properties");

	zephir_declare_class_constant_long(arango_collection_collection_ce, SL("TYPE_DOCUMENT"), 2);

	zephir_declare_class_constant_long(arango_collection_collection_ce, SL("TYPE_EDGE"), 3);

	zephir_declare_class_constant_long(arango_collection_collection_ce, SL("STATUS_NEW_BORN"), 1);

	zephir_declare_class_constant_long(arango_collection_collection_ce, SL("STATUS_UNLOADED"), 2);

	zephir_declare_class_constant_long(arango_collection_collection_ce, SL("STATUS_LOADED"), 3);

	zephir_declare_class_constant_long(arango_collection_collection_ce, SL("STATUS_BEING_LOADED"), 4);

	zephir_declare_class_constant_long(arango_collection_collection_ce, SL("STATUS_DELETED"), 5);

	zend_class_implements(arango_collection_collection_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("jsonserializable")));
	return SUCCESS;

}

/**
 * Construct a new collection representation
 *
 * @throws \Arango\Exception\ClientException if name has lenght equals 0
 * @param string name
 * @return void
 */
PHP_METHOD(Arango_Collection_Collection, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setname", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Clone a collection instance
 *
 * @magic
 * @return void
 */
PHP_METHOD(Arango_Collection_Collection, __clone) {

	zval __$null;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);


	zephir_update_property_zval(this_ptr, SL("id"), &__$null);
	zephir_update_property_zval(this_ptr, SL("name"), &__$null);
	zephir_update_property_zval(this_ptr, SL("waitForSync"), &__$null);
	zephir_update_property_zval(this_ptr, SL("journalSize"), &__$null);
	zephir_update_property_zval(this_ptr, SL("isSystem"), &__$null);
	zephir_update_property_zval(this_ptr, SL("isVolatile"), &__$null);
	zephir_update_property_zval(this_ptr, SL("numberOfShards"), &__$null);
	zephir_update_property_zval(this_ptr, SL("shardKeys"), &__$null);

}

/**
 * Get an string representation of collection
 *
 * @magic
 * @return string
 */
PHP_METHOD(Arango_Collection_Collection, __toString) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getall", NULL, 0);
	zephir_check_call_status();
	ZVAL_LONG(&_1, 256);
	zephir_json_encode(return_value, &_0, zephir_get_intval(&_1) );
	RETURN_MM();

}

/**
 * Get all collection attributes
 *
 * @return array
 */
PHP_METHOD(Arango_Collection_Collection, getAll) {

	zval _0, _1, _3, _2$$3, _4$$4;
	zval attributes, numberOfShards$$3, shardKeys$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&numberOfShards$$3);
	ZVAL_UNDEF(&shardKeys$$4);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&attributes);
	zephir_create_array(&attributes, 8, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("id"), PH_NOISY_CC);
	zephir_array_update_string(&attributes, SL("id"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("name"), PH_NOISY_CC);
	zephir_array_update_string(&attributes, SL("name"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("waitForSync"), PH_NOISY_CC);
	zephir_array_update_string(&attributes, SL("waitForSync"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("isSystem"), PH_NOISY_CC);
	zephir_array_update_string(&attributes, SL("isSystem"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("isVolatile"), PH_NOISY_CC);
	zephir_array_update_string(&attributes, SL("isVolatile"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("type"), PH_NOISY_CC);
	zephir_array_update_string(&attributes, SL("type"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("status"), PH_NOISY_CC);
	zephir_array_update_string(&attributes, SL("status"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("keyOptions"), PH_NOISY_CC);
	zephir_array_update_string(&attributes, SL("keyOptions"), &_0, PH_COPY | PH_SEPARATE);
	zephir_read_property(&_1, this_ptr, SL("numberOfShards"), PH_NOISY_CC | PH_READONLY);
	if (!(Z_TYPE_P(&_1) == IS_NULL)) {
		ZEPHIR_INIT_VAR(&numberOfShards$$3);
		zephir_create_array(&numberOfShards$$3, 1, 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&_2$$3);
		zephir_read_property(&_2$$3, this_ptr, SL("numberOfShards"), PH_NOISY_CC);
		zephir_array_update_string(&numberOfShards$$3, SL("numberOfShards"), &_2$$3, PH_COPY | PH_SEPARATE);
		zephir_array_append(&attributes, &numberOfShards$$3, PH_SEPARATE, "arango/collection/collection.zep", 185);
	}
	zephir_read_property(&_3, this_ptr, SL("shardKeys"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_3) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&shardKeys$$4);
		zephir_create_array(&shardKeys$$4, 1, 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&_4$$4);
		zephir_read_property(&_4$$4, this_ptr, SL("shardKeys"), PH_NOISY_CC);
		zephir_array_update_string(&shardKeys$$4, SL("shardKeys"), &_4$$4, PH_COPY | PH_SEPARATE);
		zephir_array_append(&attributes, &shardKeys$$4, PH_SEPARATE, "arango/collection/collection.zep", 195);
	}
	RETURN_CTOR(&attributes);

}

/**
 * Serialize instance as JSON document
 *
 * @return array
 */
PHP_METHOD(Arango_Collection_Collection, jsonSerialize) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getall", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * ID setter
 *
 * @param int id
 * @return void
 */
PHP_METHOD(Arango_Collection_Collection, setId) {

	zval *id_param = NULL, _0;
	zend_long id;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &id_param);

	id = zephir_get_intval(id_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, id);
	zephir_update_property_zval(this_ptr, SL("id"), &_0);

}

/**
 * ID getter
 *
 * @return int | null
 */
PHP_METHOD(Arango_Collection_Collection, getId) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "id");

}

/**
 * Set the collection name
 *
 * @throws \Arango\Exception\ClientException if name has lenght equals 0
 * @param string name
 * @return void
 */
PHP_METHOD(Arango_Collection_Collection, setName) {

	zval *name_param = NULL;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	if (zephir_fast_strlen_ev(&name) > 0) {
		zephir_update_property_zval(this_ptr, SL("name"), &name);
		RETURN_MM_NULL();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(arango_exception_clientexception_ce, "Invalid string for a collection name", "arango/collection/collection.zep", 242);
	return;

}

/**
 * Name getter
 *
 * @return string | null
 */
PHP_METHOD(Arango_Collection_Collection, getName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "name");

}

/**
 * Type setter
 *
 * @param int tyoe
 * @return void
 */
PHP_METHOD(Arango_Collection_Collection, setType) {

	zval *type_param = NULL, _0;
	zend_long type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &type_param);

	type = zephir_get_intval(type_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, type);
	zephir_update_property_zval(this_ptr, SL("type"), &_0);

}

/**
 * Type getter
 *
 * @return int | null
 */
PHP_METHOD(Arango_Collection_Collection, getType) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "type");

}

/**
 * waitForSync setter
 *
 * @param boolean waitForSync
 * @return void
 */
PHP_METHOD(Arango_Collection_Collection, setWaitForSync) {

	zval *waitForSync_param = NULL, __$true, __$false;
	zend_bool waitForSync;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &waitForSync_param);

	waitForSync = zephir_get_boolval(waitForSync_param);


	if (waitForSync) {
		zephir_update_property_zval(this_ptr, SL("waitForSync"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("waitForSync"), &__$false);
	}

}

/**
 * waitForSync getter
 *
 * @return boolean | null
 */
PHP_METHOD(Arango_Collection_Collection, getWaitForSync) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "waitForSync");

}

/**
 * journalSize setter
 *
 * @param int journalSize
 * @return void
 */
PHP_METHOD(Arango_Collection_Collection, setJournalSize) {

	zval *journalSize_param = NULL, _0;
	zend_long journalSize;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &journalSize_param);

	journalSize = zephir_get_intval(journalSize_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, journalSize);
	zephir_update_property_zval(this_ptr, SL("journalSize"), &_0);

}

/**
 * journalSize getter
 *
 * @return int | null
 */
PHP_METHOD(Arango_Collection_Collection, getJournalSize) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "journalSize");

}

/**
 * isSystem setter
 *
 * @param boolean isSystem
 * @return void
 */
PHP_METHOD(Arango_Collection_Collection, setIsSystem) {

	zval *isSystem_param = NULL, __$true, __$false;
	zend_bool isSystem;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &isSystem_param);

	isSystem = zephir_get_boolval(isSystem_param);


	if (isSystem) {
		zephir_update_property_zval(this_ptr, SL("isSystem"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("isSystem"), &__$false);
	}

}

/**
 * isSystem getter
 *
 * @return boolean | null
 */
PHP_METHOD(Arango_Collection_Collection, getIsSystem) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "isSystem");

}

/**
 * isVolatile setter
 *
 * @param boolean isVolatile
 * @return void
 */
PHP_METHOD(Arango_Collection_Collection, setIsVolatile) {

	zval *isVolatile_param = NULL, __$true, __$false;
	zend_bool isVolatile;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &isVolatile_param);

	isVolatile = zephir_get_boolval(isVolatile_param);


	if (isVolatile) {
		zephir_update_property_zval(this_ptr, SL("isVolatile"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("isVolatile"), &__$false);
	}

}

/**
 * isVolatile getter
 *
 * @return boolean | null
 */
PHP_METHOD(Arango_Collection_Collection, getIsVolatile) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "isVolatile");

}

/**
 * numberOfShards setter
 *
 * @param int numberOfShards
 * @return void
 */
PHP_METHOD(Arango_Collection_Collection, setNumberOfShards) {

	zval *numberOfShards_param = NULL, _0;
	zend_long numberOfShards;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &numberOfShards_param);

	numberOfShards = zephir_get_intval(numberOfShards_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, numberOfShards);
	zephir_update_property_zval(this_ptr, SL("numberOfShards"), &_0);

}

/**
 * numberOfShards getter
 *
 * @return int | null
 */
PHP_METHOD(Arango_Collection_Collection, getNumberOfShards) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "numberOfShards");

}

/**
 * shardKeys setter
 *
 * @param array shardKeys
 * @return void
 */
PHP_METHOD(Arango_Collection_Collection, setShardKeys) {

	zval *shardKeys_param = NULL;
	zval shardKeys;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&shardKeys);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &shardKeys_param);

	zephir_get_arrval(&shardKeys, shardKeys_param);


	zephir_update_property_zval(this_ptr, SL("shardKeys"), &shardKeys);
	ZEPHIR_MM_RESTORE();

}

/**
 * shardKeys getter
 *
 * @return array | null
 */
PHP_METHOD(Arango_Collection_Collection, getShardKeys) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "shardKeys");

}

/**
 * status setter
 *
 * @param int shardKeys
 * @return void
 */
PHP_METHOD(Arango_Collection_Collection, setStatus) {

	zval *status_param = NULL, _0;
	zend_long status;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &status_param);

	status = zephir_get_intval(status_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, status);
	zephir_update_property_zval(this_ptr, SL("status"), &_0);

}

/**
 * status getter
 *
 * @return int | null
 */
PHP_METHOD(Arango_Collection_Collection, getStatus) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "status");

}

/**
 * keyOptions setter
 *
 * @param array keyOptions
 * @return void
 */
PHP_METHOD(Arango_Collection_Collection, setKeyOptions) {

	zval *keyOptions_param = NULL;
	zval keyOptions;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyOptions);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyOptions_param);

	zephir_get_arrval(&keyOptions, keyOptions_param);


	zephir_update_property_zval(this_ptr, SL("keyOptions"), &keyOptions);
	ZEPHIR_MM_RESTORE();

}

/**
 * keyOptions getter
 *
 * @return array | null
 */
PHP_METHOD(Arango_Collection_Collection, getKeyOptions) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "keyOptions");

}

/**
 * Get default Collection type
 *
 * @return string
 */
PHP_METHOD(Arango_Collection_Collection, getDefaultType) {

	zval *this_ptr = getThis();


	RETURN_LONG(2);

}

/**
 * Factory method to construct a new Collection
 *
 * @throws \Arango\Exception\ClientException
 * @param array values - Initial values for collection
 * @return Collection
 */
PHP_METHOD(Arango_Collection_Collection, createFromArray) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *values_param = NULL, _0, collection$$3, _2$$3, _3$$3, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3, _9$$3, _10$$3, _11$$3, _12$$3;
	zval values;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&collection$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &values_param);

	zephir_get_arrval(&values, values_param);


	ZEPHIR_CALL_SELF(&_0, "validatearray", &_1, 18, &values);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&collection$$3);
		object_init_ex(&collection$$3, arango_collection_collection_ce);
		zephir_array_fetch_string(&_2$$3, &values, SL("name"), PH_NOISY | PH_READONLY, "arango/collection/collection.zep", 444 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &collection$$3, "__construct", NULL, 19, &_2$$3);
		zephir_check_call_status();
		zephir_array_fetch_string(&_3$$3, &values, SL("id"), PH_NOISY | PH_READONLY, "arango/collection/collection.zep", 445 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &collection$$3, "setid", NULL, 20, &_3$$3);
		zephir_check_call_status();
		zephir_array_fetch_string(&_4$$3, &values, SL("type"), PH_NOISY | PH_READONLY, "arango/collection/collection.zep", 446 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &collection$$3, "settype", NULL, 21, &_4$$3);
		zephir_check_call_status();
		zephir_array_fetch_string(&_5$$3, &values, SL("waitForSync"), PH_NOISY | PH_READONLY, "arango/collection/collection.zep", 447 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &collection$$3, "setwaitforsync", NULL, 22, &_5$$3);
		zephir_check_call_status();
		zephir_array_fetch_string(&_6$$3, &values, SL("journalSize"), PH_NOISY | PH_READONLY, "arango/collection/collection.zep", 448 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &collection$$3, "setjournalsize", NULL, 23, &_6$$3);
		zephir_check_call_status();
		zephir_array_fetch_string(&_7$$3, &values, SL("isSystem"), PH_NOISY | PH_READONLY, "arango/collection/collection.zep", 449 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &collection$$3, "setissystem", NULL, 24, &_7$$3);
		zephir_check_call_status();
		zephir_array_fetch_string(&_8$$3, &values, SL("isVolatile"), PH_NOISY | PH_READONLY, "arango/collection/collection.zep", 450 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &collection$$3, "setisvolatile", NULL, 25, &_8$$3);
		zephir_check_call_status();
		zephir_array_fetch_string(&_9$$3, &values, SL("numberOfShards"), PH_NOISY | PH_READONLY, "arango/collection/collection.zep", 451 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &collection$$3, "setnumberofshards", NULL, 26, &_9$$3);
		zephir_check_call_status();
		zephir_array_fetch_string(&_10$$3, &values, SL("shardKeys"), PH_NOISY | PH_READONLY, "arango/collection/collection.zep", 452 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &collection$$3, "setshardkeys", NULL, 27, &_10$$3);
		zephir_check_call_status();
		zephir_array_fetch_string(&_11$$3, &values, SL("status"), PH_NOISY | PH_READONLY, "arango/collection/collection.zep", 453 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &collection$$3, "setstatus", NULL, 28, &_11$$3);
		zephir_check_call_status();
		zephir_array_fetch_string(&_12$$3, &values, SL("keyOptions"), PH_NOISY | PH_READONLY, "arango/collection/collection.zep", 454 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &collection$$3, "setkeyoptions", NULL, 29, &_12$$3);
		zephir_check_call_status();
		RETURN_CCTOR(&collection$$3);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Validate an array to create a new Collection
 *
 * @throws \Arango\Exception\ClientException
 * @param array values - array to validate
 * @return boolean
 */
PHP_METHOD(Arango_Collection_Collection, validateArray) {

	zend_bool _5, _8, _11, _14, _17, _20, _23, _26, _29, _32, _35;
	zend_string *_3;
	zend_ulong _2;
	zval *values_param = NULL, key, _0, *_1, _4, _6, _7, _9, _10, _12, _13, _15, _16, _18, _19, _21, _22, _24, _25, _27, _28, _30, _31, _33, _34, _36;
	zval values;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_36);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &values_param);

	zephir_get_arrval(&values, values_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_is_iterable(&values, 0, "arango/collection/collection.zep", 478);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&values), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&key, _3);
		} else {
			ZVAL_LONG(&key, _2);
		}
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_COPY(&_0, _1);
		if (!(Z_TYPE_P(&key) == IS_STRING)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(arango_exception_clientexception_ce, "Invalid collection attribute type", "arango/collection/collection.zep", 473);
			return;
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "id");
	_5 = !(zephir_array_key_exists(&values, &_4 TSRMLS_CC));
	if (!(_5)) {
		zephir_array_fetch_string(&_6, &values, SL("id"), PH_NOISY | PH_READONLY, "arango/collection/collection.zep", 478 TSRMLS_CC);
		_5 = !(Z_TYPE_P(&_6) == IS_LONG);
	}
	if (_5) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(arango_exception_clientexception_ce, "Invalid type or missing id attribute", "arango/collection/collection.zep", 479);
		return;
	}
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "name");
	_8 = !(zephir_array_key_exists(&values, &_7 TSRMLS_CC));
	if (!(_8)) {
		zephir_array_fetch_string(&_9, &values, SL("name"), PH_NOISY | PH_READONLY, "arango/collection/collection.zep", 483 TSRMLS_CC);
		_8 = !(Z_TYPE_P(&_9) == IS_STRING);
	}
	if (_8) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(arango_exception_clientexception_ce, "Invalid type or missing name attribute", "arango/collection/collection.zep", 484);
		return;
	}
	ZEPHIR_INIT_VAR(&_10);
	ZVAL_STRING(&_10, "type");
	_11 = !(zephir_array_key_exists(&values, &_10 TSRMLS_CC));
	if (!(_11)) {
		zephir_array_fetch_string(&_12, &values, SL("type"), PH_NOISY | PH_READONLY, "arango/collection/collection.zep", 488 TSRMLS_CC);
		_11 = !(Z_TYPE_P(&_12) == IS_LONG);
	}
	if (_11) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(arango_exception_clientexception_ce, "Invalid type or missing type attribute", "arango/collection/collection.zep", 489);
		return;
	}
	ZEPHIR_INIT_VAR(&_13);
	ZVAL_STRING(&_13, "waitForSync");
	_14 = !(zephir_array_key_exists(&values, &_13 TSRMLS_CC));
	if (!(_14)) {
		zephir_array_fetch_string(&_15, &values, SL("waitForSync"), PH_NOISY | PH_READONLY, "arango/collection/collection.zep", 493 TSRMLS_CC);
		_14 = !((Z_TYPE_P(&_15) == IS_TRUE || Z_TYPE_P(&_15) == IS_FALSE));
	}
	if (_14) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(arango_exception_clientexception_ce, "Invalid type or missing waitForSync attribute", "arango/collection/collection.zep", 494);
		return;
	}
	ZEPHIR_INIT_VAR(&_16);
	ZVAL_STRING(&_16, "journalSize");
	_17 = !(zephir_array_key_exists(&values, &_16 TSRMLS_CC));
	if (!(_17)) {
		zephir_array_fetch_string(&_18, &values, SL("journalSize"), PH_NOISY | PH_READONLY, "arango/collection/collection.zep", 498 TSRMLS_CC);
		_17 = !(Z_TYPE_P(&_18) == IS_LONG);
	}
	if (_17) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(arango_exception_clientexception_ce, "Invalid type or missing journalSize attribute", "arango/collection/collection.zep", 499);
		return;
	}
	ZEPHIR_INIT_VAR(&_19);
	ZVAL_STRING(&_19, "isSystem");
	_20 = !(zephir_array_key_exists(&values, &_19 TSRMLS_CC));
	if (!(_20)) {
		zephir_array_fetch_string(&_21, &values, SL("isSystem"), PH_NOISY | PH_READONLY, "arango/collection/collection.zep", 503 TSRMLS_CC);
		_20 = !((Z_TYPE_P(&_21) == IS_TRUE || Z_TYPE_P(&_21) == IS_FALSE));
	}
	if (_20) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(arango_exception_clientexception_ce, "Invalid type or missing isSystem attribute", "arango/collection/collection.zep", 504);
		return;
	}
	ZEPHIR_INIT_VAR(&_22);
	ZVAL_STRING(&_22, "isVolatile");
	_23 = !(zephir_array_key_exists(&values, &_22 TSRMLS_CC));
	if (!(_23)) {
		zephir_array_fetch_string(&_24, &values, SL("isVolatile"), PH_NOISY | PH_READONLY, "arango/collection/collection.zep", 508 TSRMLS_CC);
		_23 = !((Z_TYPE_P(&_24) == IS_TRUE || Z_TYPE_P(&_24) == IS_FALSE));
	}
	if (_23) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(arango_exception_clientexception_ce, "Invalid type or missing isVolatile attribute", "arango/collection/collection.zep", 509);
		return;
	}
	ZEPHIR_INIT_VAR(&_25);
	ZVAL_STRING(&_25, "numberOfShards");
	_26 = !(zephir_array_key_exists(&values, &_25 TSRMLS_CC));
	if (!(_26)) {
		zephir_array_fetch_string(&_27, &values, SL("numberOfShards"), PH_NOISY | PH_READONLY, "arango/collection/collection.zep", 513 TSRMLS_CC);
		_26 = !(Z_TYPE_P(&_27) == IS_LONG);
	}
	if (_26) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(arango_exception_clientexception_ce, "Invalid type or missing numberOfShards attribute", "arango/collection/collection.zep", 514);
		return;
	}
	ZEPHIR_INIT_VAR(&_28);
	ZVAL_STRING(&_28, "shardKeys");
	_29 = !(zephir_array_key_exists(&values, &_28 TSRMLS_CC));
	if (!(_29)) {
		zephir_array_fetch_string(&_30, &values, SL("shardKeys"), PH_NOISY | PH_READONLY, "arango/collection/collection.zep", 518 TSRMLS_CC);
		_29 = !(Z_TYPE_P(&_30) == IS_ARRAY);
	}
	if (_29) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(arango_exception_clientexception_ce, "Invalid type or missing shardKeys attribute", "arango/collection/collection.zep", 519);
		return;
	}
	ZEPHIR_INIT_VAR(&_31);
	ZVAL_STRING(&_31, "status");
	_32 = !(zephir_array_key_exists(&values, &_31 TSRMLS_CC));
	if (!(_32)) {
		zephir_array_fetch_string(&_33, &values, SL("status"), PH_NOISY | PH_READONLY, "arango/collection/collection.zep", 523 TSRMLS_CC);
		_32 = !(Z_TYPE_P(&_33) == IS_LONG);
	}
	if (_32) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(arango_exception_clientexception_ce, "Invalid type or missing status attribute", "arango/collection/collection.zep", 524);
		return;
	}
	ZEPHIR_INIT_VAR(&_34);
	ZVAL_STRING(&_34, "keyOptions");
	_35 = !(zephir_array_key_exists(&values, &_34 TSRMLS_CC));
	if (!(_35)) {
		zephir_array_fetch_string(&_36, &values, SL("keyOptions"), PH_NOISY | PH_READONLY, "arango/collection/collection.zep", 528 TSRMLS_CC);
		_35 = !(Z_TYPE_P(&_36) == IS_ARRAY);
	}
	if (_35) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(arango_exception_clientexception_ce, "Invalid type or missing keyOptions attribute", "arango/collection/collection.zep", 529);
		return;
	}
	RETURN_MM_BOOL(1);

}

