
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"


/**
 * Value object representing a single Edge document
 *
 * @package Arango/Document
 * @class Edge
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Document_Edge) {

	ZEPHIR_REGISTER_CLASS_EX(Arango\\Document, Edge, arango, document_edge, arango_document_document_ce, arango_document_edge_method_entry, 0);

	/**
	 * The edge's from (might be null for new documents)
	 *
	 * @var mixed
	 */
	zend_declare_property_null(arango_document_edge_ce, SL("from"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * The edge's to (might be null for new documents)
	 *
	 * @var mixed
	 */
	zend_declare_property_null(arango_document_edge_ce, SL("to"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Edge document indexes
	 */
	zephir_declare_class_constant_string(arango_document_edge_ce, SL("ENTRY_FROM"), "_from");

	zephir_declare_class_constant_string(arango_document_edge_ce, SL("ENTRY_TO"), "_to");

	return SUCCESS;

}

/**
 * The edge's from (might be null for new documents)
 */
PHP_METHOD(Arango_Document_Edge, getFrom) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "from");

}

/**
 * The edge's to (might be null for new documents)
 */
PHP_METHOD(Arango_Document_Edge, getTo) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "to");

}

/**
 * Set the 'from' vertex document-handler
 *
 * TODO Discuss/ Review
 *
 * @param mixed from - From vertex
 *
 * @return Edge
 */
PHP_METHOD(Arango_Document_Edge, setFrom) {

	zval *from, from_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&from_sub);

	zephir_fetch_params(0, 1, 0, &from);



	zephir_update_property_zval(this_ptr, SL("from"), from);
	RETURN_THISW();

}

/**
 * Set the 'to' vertex document-handler
 *
 * TODO Discuss/ Review
 *
 * @param mixed to - To vertex
 *
 * @return Edge
 */
PHP_METHOD(Arango_Document_Edge, setTo) {

	zval *to, to_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&to_sub);

	zephir_fetch_params(0, 1, 0, &to);



	zephir_update_property_zval(this_ptr, SL("to"), to);
	RETURN_THISW();

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
PHP_METHOD(Arango_Document_Edge, set) {

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
		if (ZEPHIR_IS_STRING(&key, "_from")) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setfrom", NULL, 0, value);
			zephir_check_call_status();
			RETURN_MM_NULL();
		}
		if (ZEPHIR_IS_STRING(&key, "_to")) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setto", NULL, 0, value);
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
			zephir_array_fetch(&_7, &_6, &key, PH_NOISY | PH_READONLY, "arango/document/edge.zep", 113 TSRMLS_CC);
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
 * Get all documents attributes for insertion / update
 *
 * @return array - associative array with all documents attributes/values
 */
PHP_METHOD(Arango_Document_Edge, getAllForInsertUpdate) {

	zval data, _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_PARENT(&data, arango_document_edge_ce, getThis(), "getallforinsertupdate", &_0, 0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("from"), PH_NOISY_CC | PH_READONLY);
	zephir_array_update_string(&data, SL("_from"), &_1, PH_COPY | PH_SEPARATE);
	zephir_read_property(&_2, this_ptr, SL("to"), PH_NOISY_CC | PH_READONLY);
	zephir_array_update_string(&data, SL("_to"), &_2, PH_COPY | PH_SEPARATE);
	RETURN_CCTOR(&data);

}

