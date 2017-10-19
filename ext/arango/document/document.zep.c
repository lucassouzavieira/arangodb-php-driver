
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/exception.h"


/**
 * Value object representing a single collection-based document
 *
 * @package Arango/Document
 * @class Document
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Document_Document) {

	ZEPHIR_REGISTER_CLASS(Arango\\Document, Document, arango, document_document, arango_document_document_method_entry, 0);

	/**
	 * The document id (might be null for new documents)
	 *
	 * @var string
	 */
	zend_declare_property_null(arango_document_document_ce, SL("id"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * The document key (might be null for new documents)
	 *
	 * @var string
	 */
	zend_declare_property_null(arango_document_document_ce, SL("key"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * The document revision (might be null for new documents)
	 *
	 * @var mixed
	 */
	zend_declare_property_null(arango_document_document_ce, SL("revision"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * The document attributes as associative array with names and values
	 *
	 * @var mixed
	 */
	zend_declare_property_null(arango_document_document_ce, SL("values"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Flag to indicate whether document was changed locally
	 */
	zend_declare_property_bool(arango_document_document_ce, SL("changed"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Flag to indicate whether document is a new document (never been saved to the server)
	 */
	zend_declare_property_bool(arango_document_document_ce, SL("isNew"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * An array, that defines which attributes should be treated as hidden.
	 */
	zend_declare_property_null(arango_document_document_ce, SL("hiddenAttributes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Flag to indicate whether hidden attributes should be ignored or included in returned data-sets
	 */
	zend_declare_property_bool(arango_document_document_ce, SL("ignoreHiddenAttributes"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	arango_document_document_ce->create_object = zephir_init_properties_Arango_Document_Document;
	/**
	 * Document indexes
	 */
	zephir_declare_class_constant_string(arango_document_document_ce, SL("ENTRY_ID"), "id");

	zephir_declare_class_constant_string(arango_document_document_ce, SL("ENTRY_KEY"), "_key");

	zephir_declare_class_constant_string(arango_document_document_ce, SL("ENTRY_REVISION"), "_rev");

	zephir_declare_class_constant_string(arango_document_document_ce, SL("ENTRY_IS_NEW"), "_isNew");

	zephir_declare_class_constant_string(arango_document_document_ce, SL("ENTRY_HIDDEN_ATTRIBUTES"), "_hiddenAttributes");

	zephir_declare_class_constant_string(arango_document_document_ce, SL("ENTRY_IGNORE_HIDDEN_ATTRIBUTES"), "_ignoreHiddenAttributes");

	zephir_declare_class_constant_string(arango_document_document_ce, SL("OPTION_WAIT_FOR_SYNC"), "waitForSync");

	zephir_declare_class_constant_string(arango_document_document_ce, SL("OPTION_POLICY"), "policy");

	zephir_declare_class_constant_string(arango_document_document_ce, SL("OPTION_KEEP_NULL"), "keepNull");

	zend_class_implements(arango_document_document_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("jsonserializable")));
	zend_class_implements(arango_document_document_ce TSRMLS_CC, 1, zend_ce_serializable);
	return SUCCESS;

}

/**
 * The document id (might be null for new documents)
 */
PHP_METHOD(Arango_Document_Document, getId) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "id");

}

/**
 * The document key (might be null for new documents)
 */
PHP_METHOD(Arango_Document_Document, getKey) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "key");

}

/**
 * The document revision (might be null for new documents)
 */
PHP_METHOD(Arango_Document_Document, getRevision) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "revision");

}

/**
 * The document revision (might be null for new documents)
 */
PHP_METHOD(Arango_Document_Document, setRevision) {

	zval *revision, revision_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&revision_sub);

	zephir_fetch_params(0, 1, 0, &revision);



	zephir_update_property_zval(this_ptr, SL("revision"), revision);
	RETURN_THISW();

}

/**
 * Flag to indicate whether document was changed locally
 */
PHP_METHOD(Arango_Document_Document, getChanged) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "changed");

}

/**
 * Flag to indicate whether document was changed locally
 */
PHP_METHOD(Arango_Document_Document, setChanged) {

	zval *changed, changed_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&changed_sub);

	zephir_fetch_params(0, 1, 0, &changed);



	zephir_update_property_zval(this_ptr, SL("changed"), changed);
	RETURN_THISW();

}

/**
 * Flag to indicate whether document is a new document (never been saved to the server)
 */
PHP_METHOD(Arango_Document_Document, getIsNew) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "isNew");

}

/**
 * Flag to indicate whether document is a new document (never been saved to the server)
 */
PHP_METHOD(Arango_Document_Document, setIsNew) {

	zval *isNew, isNew_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&isNew_sub);

	zephir_fetch_params(0, 1, 0, &isNew);



	zephir_update_property_zval(this_ptr, SL("isNew"), isNew);
	RETURN_THISW();

}

/**
 * An array, that defines which attributes should be treated as hidden.
 */
PHP_METHOD(Arango_Document_Document, getHiddenAttributes) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "hiddenAttributes");

}

/**
 * An array, that defines which attributes should be treated as hidden.
 */
PHP_METHOD(Arango_Document_Document, setHiddenAttributes) {

	zval *hiddenAttributes, hiddenAttributes_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&hiddenAttributes_sub);

	zephir_fetch_params(0, 1, 0, &hiddenAttributes);



	zephir_update_property_zval(this_ptr, SL("hiddenAttributes"), hiddenAttributes);
	RETURN_THISW();

}

/**
 * Flag to indicate whether hidden attributes should be ignored or included in returned data-sets
 */
PHP_METHOD(Arango_Document_Document, getIgnoreHiddenAttributes) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "ignoreHiddenAttributes");

}

/**
 * Flag to indicate whether hidden attributes should be ignored or included in returned data-sets
 */
PHP_METHOD(Arango_Document_Document, setIgnoreHiddenAttributes) {

	zval *ignoreHiddenAttributes, ignoreHiddenAttributes_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ignoreHiddenAttributes_sub);

	zephir_fetch_params(0, 1, 0, &ignoreHiddenAttributes);



	zephir_update_property_zval(this_ptr, SL("ignoreHiddenAttributes"), ignoreHiddenAttributes);
	RETURN_THISW();

}

/**
 * Constructs an empty document
 *
 * @param array options - Initial options for document
 *
 * @return void
 */
PHP_METHOD(Arango_Document_Document, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, _0$$4, _1$$5, _2$$6;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	if (!(Z_TYPE_P(&options) == IS_NULL)) {
		if (zephir_array_isset_string(&options, SL("_hiddenAttributes"))) {
			zephir_array_fetch_string(&_0$$4, &options, SL("_hiddenAttributes"), PH_NOISY | PH_READONLY, "arango/document/document.zep", 102 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "sethiddenattributes", NULL, 0, &_0$$4);
			zephir_check_call_status();
		}
		if (zephir_array_isset_string(&options, SL("_ignoreHiddenAttributes"))) {
			zephir_array_fetch_string(&_1$$5, &options, SL("_ignoreHiddenAttributes"), PH_NOISY | PH_READONLY, "arango/document/document.zep", 106 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setignorehiddenattributes", NULL, 0, &_1$$5);
			zephir_check_call_status();
		}
		if (zephir_array_isset_string(&options, SL("_isNew"))) {
			zephir_array_fetch_string(&_2$$6, &options, SL("_isNew"), PH_NOISY | PH_READONLY, "arango/document/document.zep", 110 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setisnew", NULL, 0, &_2$$6);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Clone a document
 *
 * @magic
 *
 * @return void
 */
PHP_METHOD(Arango_Document_Document, __clone) {

	zval __$null;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);


	zephir_update_property_zval(this_ptr, SL("id"), &__$null);
	zephir_update_property_zval(this_ptr, SL("key"), &__$null);
	zephir_update_property_zval(this_ptr, SL("revision"), &__$null);

}

/**
 * Get a string representation of the document
 *
 * @magic
 *
 * @return string
 */
PHP_METHOD(Arango_Document_Document, __toString) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getall", NULL, 0);
	zephir_check_call_status();
	zephir_json_encode(return_value, &_0, 0 );
	RETURN_MM();

}

/**
 * Set a document attribute
 *
 * @throws \Arango\Exception\ClientException
 *
 * @magic
 * @param string key - Attribute name
 * @param mixed value - Value for attribute
 *
 * @return void
 */
PHP_METHOD(Arango_Document_Document, __set) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, value_sub;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(&key, key_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &key, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Get a document attribute
 *
 * @magic
 * @param string key - Attribute name
 *
 * @return mixed | null - Value of attribute, if exists. Return null otherwise
 */
PHP_METHOD(Arango_Document_Document, __get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(&key, key_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, &key);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Factory method to Construct a new document using values passed to populate it
 *
 * @param array values - Initial document values
 * @param array options - Initial options for document
 *
 * @return Document
 */
PHP_METHOD(Arango_Document_Document, createFromArray) {

	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *values_param = NULL, *options_param = NULL, document, key, value, *_0, _4;
	zval values, options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&document);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &values_param, &options_param);

	zephir_get_arrval(&values, values_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&document);
	object_init_ex(&document, arango_document_document_ce);
	ZEPHIR_CALL_METHOD(NULL, &document, "__construct", NULL, 2, &options);
	zephir_check_call_status();
	zephir_is_iterable(&values, 0, "arango/document/document.zep", 183);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&values), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&key, _2);
		} else {
			ZVAL_LONG(&key, _1);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		ZEPHIR_CALL_METHOD(NULL, &document, "set", &_3, 3, &key, &value);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZVAL_BOOL(&_4, 1);
	ZEPHIR_CALL_METHOD(NULL, &document, "setchanged", NULL, 4, &_4);
	zephir_check_call_status();
	RETURN_CCTOR(&document);

}

/**
 * Set a document attribute
 *
 * @throws \Arango\Exception\ClientException
 *
 * @param string key - Attribute name
 * @param mixed value - Value for attribute
 *
 * @return void
 */
PHP_METHOD(Arango_Document_Document, set) {

	zend_bool _3, _5;
	unsigned char _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *key_param = NULL, *value, value_sub, __$true, __$false, underscore, _2, _4, _6, _7;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&underscore);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(&key, key_param);


	ZEPHIR_INIT_VAR(&underscore);
	ZVAL_STRING(&underscore, "_");
	ZEPHIR_CALL_CE_STATIC(NULL, arango_validation_validation_ce, "validatevalue", &_0, 0, value);
	zephir_check_call_status();
	_1 = ZEPHIR_STRING_OFFSET(&key, 0);
	if (ZEPHIR_IS_LONG(&underscore, &_1)) {
		if (ZEPHIR_IS_STRING(&key, "id")) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setinternalid", NULL, 0, value);
			zephir_check_call_status();
			RETURN_MM_NULL();
		}
		if (ZEPHIR_IS_STRING(&key, "_key")) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setinternalkey", NULL, 0, value);
			zephir_check_call_status();
			RETURN_MM_NULL();
		}
		if (ZEPHIR_IS_STRING(&key, "_rev")) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setrevision", NULL, 0, value);
			zephir_check_call_status();
			RETURN_MM_NULL();
		}
		if (ZEPHIR_IS_STRING(&key, "_isNew")) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setisnew", NULL, 0, value);
			zephir_check_call_status();
			RETURN_MM_NULL();
		}
	}
	zephir_read_property(&_2, this_ptr, SL("changed"), PH_NOISY_CC | PH_READONLY);
	_3 = !zephir_is_true(&_2);
	if (_3) {
		zephir_read_property(&_4, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
		_5 = !(zephir_array_isset(&_4, &key));
		if (!(_5)) {
			zephir_read_property(&_6, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_7, &_6, &key, PH_NOISY | PH_READONLY, "arango/document/document.zep", 223 TSRMLS_CC);
			_5 = !ZEPHIR_IS_EQUAL(&_7, value);
		}
		_3 = _5;
	}
	if (_3) {
		if (1) {
			zephir_update_property_zval(this_ptr, SL("changed"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("changed"), &__$false);
		}
	}
	zephir_update_property_array(this_ptr, SL("values"), &key, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get a document attribute
 *
 * @param string key - Attribute name
 *
 * @return mixed | null - Value of attribute, if exists. Return null otherwise
 */
PHP_METHOD(Arango_Document_Document, get) {

	zval *key_param = NULL, _0, _1$$3, _2$$3;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(&key, key_param);


	zephir_read_property(&_0, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &key)) {
		zephir_read_property(&_1$$3, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &key, PH_NOISY | PH_READONLY, "arango/document/document.zep", 239 TSRMLS_CC);
		RETURN_CTOR(&_2$$3);
	}
	RETURN_MM_NULL();

}

/**
 * Get all documents attributes
 *
 * @param mixed $options - optional, array of options for the getAll function, or the boolean value for $includeInternals
 *                       Options are :
 *                       '_includeInternals' - true to include the internal attributes. Defaults to false
 *                       '_ignoreHiddenAttributes' - true to show hidden attributes. Defaults to false
 *
 * @return array - associative array with all documents attributes/values
 */
PHP_METHOD(Arango_Document_Document, getAll) {

	zend_string *_6$$7;
	zend_ulong _5$$7;
	zend_bool includeInternals, ignoreHiddenAttributes, _8$$8, _10$$8;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_12 = NULL;
	zval *options_param = NULL, __$true, hiddenAttributes, _0, data, nonInternals, _3, _1$$4, _2$$5, key$$7, value$$7, underscore$$7, *_4$$7, _7$$8, _9$$8, _11$$8, _13$$10, _14$$11;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&hiddenAttributes);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&nonInternals);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&key$$7);
	ZVAL_UNDEF(&value$$7);
	ZVAL_UNDEF(&underscore$$7);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_14$$11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	includeInternals = 0;
	ignoreHiddenAttributes = 1;
	zephir_read_property(&_0, this_ptr, SL("hiddenAttributes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&hiddenAttributes, &_0);
	if (!(Z_TYPE_P(&options) == IS_NULL)) {
		if (zephir_array_isset_string(&options, SL("_includeInternals"))) {
			ZEPHIR_OBS_VAR(&_1$$4);
			zephir_array_fetch_string(&_1$$4, &options, SL("_includeInternals"), PH_NOISY, "arango/document/document.zep", 262 TSRMLS_CC);
			includeInternals = zephir_get_boolval(&_1$$4);
		}
		if (zephir_array_isset_string(&options, SL("_ignoreHiddenAttributes"))) {
			ZEPHIR_OBS_VAR(&_2$$5);
			zephir_array_fetch_string(&_2$$5, &options, SL("_ignoreHiddenAttributes"), PH_NOISY, "arango/document/document.zep", 266 TSRMLS_CC);
			ignoreHiddenAttributes = zephir_get_boolval(&_2$$5);
		}
		if (zephir_array_isset_string(&options, SL("_hiddenAttributes"))) {
			ZEPHIR_OBS_NVAR(&hiddenAttributes);
			zephir_array_fetch_string(&hiddenAttributes, &options, SL("_hiddenAttributes"), PH_NOISY, "arango/document/document.zep", 270 TSRMLS_CC);
		}
	}
	ZEPHIR_OBS_VAR(&data);
	zephir_read_property(&data, this_ptr, SL("values"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&nonInternals);
	zephir_create_array(&nonInternals, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "changed");
	zephir_array_fast_append(&nonInternals, &_3);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "values");
	zephir_array_fast_append(&nonInternals, &_3);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "_hiddenAttributes");
	zephir_array_fast_append(&nonInternals, &_3);
	if (includeInternals) {
		ZEPHIR_INIT_VAR(&underscore$$7);
		ZVAL_STRING(&underscore$$7, "_");
		zephir_is_iterable(&data, 1, "arango/document/document.zep", 285);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _5$$7, _6$$7, _4$$7)
		{
			ZEPHIR_INIT_NVAR(&key$$7);
			if (_6$$7 != NULL) { 
				ZVAL_STR_COPY(&key$$7, _6$$7);
			} else {
				ZVAL_LONG(&key$$7, _5$$7);
			}
			ZEPHIR_INIT_NVAR(&value$$7);
			ZVAL_COPY(&value$$7, _4$$7);
			zephir_array_fetch_long(&_7$$8, &key$$7, 0, PH_NOISY | PH_READONLY, "arango/document/document.zep", 281 TSRMLS_CC);
			_8$$8 = ZEPHIR_IS_EQUAL(&_7$$8, &underscore$$7);
			if (_8$$8) {
				ZEPHIR_INIT_NVAR(&_9$$8);
				zephir_fast_strpos(&_9$$8, &key$$7, &underscore$$7, 0 );
				_8$$8 = !ZEPHIR_IS_LONG(&_9$$8, 0);
			}
			_10$$8 = _8$$8;
			if (_10$$8) {
				ZEPHIR_CALL_FUNCTION(&_11$$8, "in_array", &_12, 5, &key$$7, &nonInternals, &__$true);
				zephir_check_call_status();
				_10$$8 = !zephir_is_true(&_11$$8);
			}
			if (_10$$8) {
				zephir_array_update_zval(&data, &key$$7, &value$$7, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value$$7);
		ZEPHIR_INIT_NVAR(&key$$7);
	}
	if (!ignoreHiddenAttributes) {
		ZEPHIR_CALL_METHOD(&_13$$10, this_ptr, "filterhiddenattributes", NULL, 6, &data, &hiddenAttributes);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&data, &_13$$10);
	}
	zephir_read_property(&_0, this_ptr, SL("key"), PH_NOISY_CC | PH_READONLY);
	if (!(Z_TYPE_P(&_0) == IS_NULL)) {
		zephir_read_property(&_14$$11, this_ptr, SL("key"), PH_NOISY_CC | PH_READONLY);
		zephir_array_update_string(&data, SL("_key"), &_14$$11, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(&data);

}

/**
 * Get the collection id
 *
 * Collection ids are generated on the server only. Collection ids are numeric but might be
 * bigger than PHP_INT_MAX. To reliably store a collection id elsewhere, a PHP string should be used
 *
 * @return string | null - Collection id, if exists. Return null otherwise
 */
PHP_METHOD(Arango_Document_Document, getCollectionId) {

	zval data, _0, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("id"), PH_NOISY_CC | PH_READONLY);
	if (!(Z_TYPE_P(&_0) == IS_NULL)) {
		zephir_read_property(&_1$$3, this_ptr, SL("id"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&data);
		zephir_fast_explode_str(&data, SL("/"), &_1$$3, LONG_MAX TSRMLS_CC);
		zephir_array_fetch_long(&_2$$3, &data, 1, PH_NOISY | PH_READONLY, "arango/document/document.zep", 311 TSRMLS_CC);
		RETURN_CTOR(&_2$$3);
	}
	RETURN_MM_NULL();

}

/**
 * Get all documents attributes for insertion / update
 *
 * @return array - associative array with all documents attributes/values
 */
PHP_METHOD(Arango_Document_Document, getAllForInsertUpdate) {

	zend_bool _4$$3, _5$$3;
	zend_string *_3;
	zend_ulong _2;
	zval key, value, _0, *_1, _6, _7$$6;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7$$6);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&data);
	array_init(&data);
	zephir_read_property(&_0, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "arango/document/document.zep", 339);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&key, _3);
		} else {
			ZVAL_LONG(&key, _2);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _1);
		_4$$3 = ZEPHIR_IS_STRING(&key, "_id");
		if (!(_4$$3)) {
			_4$$3 = ZEPHIR_IS_STRING(&key, "_rev");
		}
		if (_4$$3) {
			continue;
		}
		_5$$3 = ZEPHIR_IS_STRING(&key, "_key");
		if (_5$$3) {
			_5$$3 = Z_TYPE_P(&value) == IS_NULL;
		}
		if (_5$$3) {
			continue;
		}
		zephir_array_update_zval(&data, &key, &value, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	zephir_read_property(&_6, this_ptr, SL("key"), PH_NOISY_CC | PH_READONLY);
	if (!(Z_TYPE_P(&_6) == IS_NULL)) {
		zephir_read_property(&_7$$6, this_ptr, SL("key"), PH_NOISY_CC | PH_READONLY);
		zephir_array_update_string(&data, SL("_key"), &_7$$6, PH_COPY | PH_SEPARATE);
	}
	RETURN_CTOR(&data);

}

/**
 * Returns the attributes with the hidden ones removed
 *
 * @param array attributes
 * @param array hiddenAttributes
 *
 * @return array - Attributes array
 */
PHP_METHOD(Arango_Document_Document, filterHiddenAttributes) {

	zend_string *_4$$3;
	zend_ulong _3$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, *hiddenAttributes_param = NULL, _0, key$$3, _1$$3, *_2$$3;
	zval attributes, hiddenAttributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&hiddenAttributes);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&key$$3);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &attributes_param, &hiddenAttributes_param);

	zephir_get_arrval(&attributes, attributes_param);
	if (!hiddenAttributes_param) {
		ZEPHIR_INIT_VAR(&hiddenAttributes);
		array_init(&hiddenAttributes);
	} else {
		zephir_get_arrval(&hiddenAttributes, hiddenAttributes_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	if (!ZEPHIR_IS_STRING(&hiddenAttributes, "")) {
		ZEPHIR_CPY_WRT(&_0, &hiddenAttributes);
	} else {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "gethiddenattributes", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CPY_WRT(&hiddenAttributes, &_0);
	if (zephir_fast_count_int(&hiddenAttributes TSRMLS_CC) > 0) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_is_iterable(&hiddenAttributes, 0, "arango/document/document.zep", 365);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&hiddenAttributes), _3$$3, _4$$3, _2$$3)
		{
			ZEPHIR_INIT_NVAR(&key$$3);
			if (_4$$3 != NULL) { 
				ZVAL_STR_COPY(&key$$3, _4$$3);
			} else {
				ZVAL_LONG(&key$$3, _3$$3);
			}
			ZEPHIR_INIT_NVAR(&_1$$3);
			ZVAL_COPY(&_1$$3, _2$$3);
			if (zephir_array_isset(&attributes, &key$$3)) {
				zephir_array_unset(&attributes, &key$$3, PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZEPHIR_INIT_NVAR(&key$$3);
	}
	zephir_array_unset_string(&attributes, SL("_hiddenAttributes"), PH_SEPARATE);
	RETURN_CTOR(&attributes);

}

/**
 * Set the internal document id
 *
 * This will throw if the id of an existing document gets updated to some other id
 *
 * @throws \Arango\Exception\ClientException
 * @param string id - Internal document id
 *
 * @return void
 */
PHP_METHOD(Arango_Document_Document, setInternalId) {

	zend_bool _1;
	zval *id_param = NULL, _0, _2, _3, _4, _5;
	zval id;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	zephir_get_strval(&id, id_param);


	zephir_read_property(&_0, this_ptr, SL("id"), PH_NOISY_CC | PH_READONLY);
	_1 = !(Z_TYPE_P(&_0) == IS_NULL);
	if (_1) {
		zephir_read_property(&_2, this_ptr, SL("id"), PH_NOISY_CC | PH_READONLY);
		_1 = !ZEPHIR_IS_EQUAL(&_2, &id);
	}
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(arango_exception_clientexception_ce, "Should not update the id of an existing document", "arango/document/document.zep", 383);
		return;
	}
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "/^[a-zA-Z0-9_-]{1,64}\\/[a-zA-Z0-9_:.@\\-()+,=;$!*\\'%]{1,254}$/");
	zephir_preg_match(&_4, &_5, &id, &_3, 0, 0 , 0  TSRMLS_CC);
	if (!zephir_is_true(&_4)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(arango_exception_clientexception_ce, "Invalid format for document id", "arango/document/document.zep", 387);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("id"), &id);
	ZEPHIR_MM_RESTORE();

}

/**
 * Set the internal document key
 *
 * This will throw if the key of an existing document gets updated to some other key
 *
 * @throws \Arango\Exception\ClientException
 * @param string key - Internal document key
 *
 * @return void
 */
PHP_METHOD(Arango_Document_Document, setInternalKey) {

	zend_bool _1;
	zval *key_param = NULL, _0, _2, _3, _4, _5;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(&key, key_param);


	zephir_read_property(&_0, this_ptr, SL("key"), PH_NOISY_CC | PH_READONLY);
	_1 = !(Z_TYPE_P(&_0) == IS_NULL);
	if (_1) {
		zephir_read_property(&_2, this_ptr, SL("key"), PH_NOISY_CC | PH_READONLY);
		_1 = !ZEPHIR_IS_EQUAL(&_2, &key);
	}
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(arango_exception_clientexception_ce, "Should not update the key of an existing document", "arango/document/document.zep", 405);
		return;
	}
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "/^[a-zA-Z0-9_:.@\\-()+,=;$!*\\'%]{1,254}$/");
	zephir_preg_match(&_4, &_5, &key, &_3, 0, 0 , 0  TSRMLS_CC);
	if (!zephir_is_true(&_4)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(arango_exception_clientexception_ce, "Invalid format for document key", "arango/document/document.zep", 409);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("key"), &key);
	ZEPHIR_MM_RESTORE();

}

/**
 * Serialize instance as JSON document
 *
 * @return array
 */
PHP_METHOD(Arango_Document_Document, jsonSerialize) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$false;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	zephir_array_update_string(&_0, SL("_includeInternals"), &__$false, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("_ignoreHiddenAttributes"), &__$false, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getall", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns an array representation for document
 *
 * @return array
 */
PHP_METHOD(Arango_Document_Document, toArray) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$false, __$true;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	zephir_array_update_string(&_0, SL("_includeInternals"), &__$false, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("_ignoreHiddenAttributes"), &__$true, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getall", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Serialize instance
 *
 * @return string
 */
PHP_METHOD(Arango_Document_Document, serialize) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getall", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 7, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Unserialize instance
 *
 * @return void
 */
PHP_METHOD(Arango_Document_Document, unserialize) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *serialized_param = NULL, data, _0$$3;
	zval serialized;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serialized);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &serialized_param);

	zephir_get_strval(&serialized, serialized_param);


	ZEPHIR_CALL_FUNCTION(&data, "unserialize", NULL, 8, &serialized);
	zephir_check_call_status();
	if (zephir_array_isset_string(&data, SL("_key"))) {
		zephir_array_fetch_string(&_0$$3, &data, SL("_key"), PH_NOISY | PH_READONLY, "arango/document/document.zep", 457 TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("key"), &_0$$3);
		zephir_array_unset_string(&data, SL("_key"), PH_SEPARATE);
	}
	zephir_update_property_zval(this_ptr, SL("values"), &data);
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Arango_Document_Document(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("hiddenAttributes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("hiddenAttributes"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("values"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

