
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
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"


/**
 * Provides batch part functionality
 *
 * @package Arango/Batch
 * @class Batch
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Batch_BatchPart) {

	ZEPHIR_REGISTER_CLASS(Arango\\Batch, BatchPart, arango, batch_batchpart, arango_batch_batchpart_method_entry, 0);

	/**
	 * An array of BatchPart options
	 *
	 * @var array
	 */
	zend_declare_property_null(arango_batch_batchpart_ce, SL("cursorOptions"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * BatchPart id
	 *
	 * @var mixed
	 */
	zend_declare_property_null(arango_batch_batchpart_ce, SL("id"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * The type of request
	 *
	 * @var array
	 */
	zend_declare_property_null(arango_batch_batchpart_ce, SL("type"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Request object for this instance
	 *
	 * @var Arango\Http\Response
	 */
	zend_declare_property_null(arango_batch_batchpart_ce, SL("request"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Batch part response for this instance
	 *
	 * @var string
	 */
	zend_declare_property_null(arango_batch_batchpart_ce, SL("response"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Document class for this instance
	 *
	 * @var string
	 */
	zend_declare_property_null(arango_batch_batchpart_ce, SL("documentClass"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * The batch that this instance is part of
	 *
	 * @var Arango\Batch\Batch
	 */
	zend_declare_property_null(arango_batch_batchpart_ce, SL("batch"), ZEND_ACC_PRIVATE TSRMLS_CC);

	arango_batch_batchpart_ce->create_object = zephir_init_properties_Arango_Batch_BatchPart;
	return SUCCESS;

}

/**
 * An array of BatchPart options
 */
PHP_METHOD(Arango_Batch_BatchPart, getCursorOptions) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "cursorOptions");

}

/**
 * BatchPart id
 */
PHP_METHOD(Arango_Batch_BatchPart, getId) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "id");

}

/**
 * BatchPart id
 */
PHP_METHOD(Arango_Batch_BatchPart, setId) {

	zval *id, id_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);

	zephir_fetch_params(0, 1, 0, &id);



	zephir_update_property_zval(this_ptr, SL("id"), id);
	RETURN_THISW();

}

/**
 * The type of request
 */
PHP_METHOD(Arango_Batch_BatchPart, getType) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "type");

}

/**
 * The type of request
 */
PHP_METHOD(Arango_Batch_BatchPart, setType) {

	zval *type_param = NULL;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	zephir_get_arrval(&type, type_param);


	zephir_update_property_zval(this_ptr, SL("type"), &type);
	RETURN_THIS();

}

/**
 * Batch part response for this instance
 */
PHP_METHOD(Arango_Batch_BatchPart, getResponse) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "response");

}

/**
 * Batch part response for this instance
 */
PHP_METHOD(Arango_Batch_BatchPart, setResponse) {

	zval *response_param = NULL;
	zval response;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&response);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &response_param);

	zephir_get_strval(&response, response_param);


	zephir_update_property_zval(this_ptr, SL("response"), &response);
	RETURN_THIS();

}

/**
 * Document class for this instance
 */
PHP_METHOD(Arango_Batch_BatchPart, setDocumentClass) {

	zval *documentClass_param = NULL;
	zval documentClass;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&documentClass);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &documentClass_param);

	zephir_get_strval(&documentClass, documentClass_param);


	zephir_update_property_zval(this_ptr, SL("documentClass"), &documentClass);
	RETURN_THIS();

}

/**
 * Constructor
 *
 * @param Batch batch
 * @param mixed id
 * @param mixed type
 * @param Arango\Http\Request request
 * @param string response
 * @param array options
 *
 * @return void
 */
PHP_METHOD(Arango_Batch_BatchPart, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval response;
	zval *batch, batch_sub, *id, id_sub, *type, type_sub, *request, request_sub, *response_param = NULL, *options_param = NULL, __$false, _0, _1, _3, _2$$3, _4$$4, _5$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&batch_sub);
	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&type_sub);
	ZVAL_UNDEF(&request_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 1, &batch, &id, &type, &request, &response_param, &options_param);

	zephir_get_strval(&response, response_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getcursoroptions", NULL, 0);
	zephir_check_call_status();
	zephir_fast_array_merge(&_0, &options, &_1 TSRMLS_CC);
	ZEPHIR_CPY_WRT(&options, &_0);
	if (zephir_array_isset_string(&options, SL("_documentClass"))) {
		zephir_array_fetch_string(&_2$$3, &options, SL("_documentClass"), PH_NOISY | PH_READONLY, "arango/batch/batchpart.zep", 96 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdocumentclass", NULL, 0, &_2$$3);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setbatch", NULL, 0, batch);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setid", NULL, 0, id);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "settype", NULL, 0, type);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setrequest", NULL, 0, request);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setresponse", NULL, 0, &response);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "_sanitize");
	zephir_update_property_array(this_ptr, SL("cursorOptions"), &_3, &__$false TSRMLS_CC);
	if (zephir_array_isset_string(&options, SL("sanitize"))) {
		zephir_array_fetch_string(&_4$$4, &options, SL("sanitize"), PH_NOISY | PH_READONLY, "arango/batch/batchpart.zep", 108 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_STRING(&_5$$4, "_sanitize");
		zephir_update_property_array(this_ptr, SL("cursorOptions"), &_5$$4, &_4$$4 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the batch that batch part belongs to
 *
 * @param Batch batch
 *
 * @return void
 */
PHP_METHOD(Arango_Batch_BatchPart, setBatch) {

	zval *batch, batch_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&batch_sub);

	zephir_fetch_params(0, 1, 0, &batch);



	zephir_update_property_zval(this_ptr, SL("batch"), batch);

}

/**
 * Gets the batch that batch part belongs to
 *
 * @return Batch
 */
PHP_METHOD(Arango_Batch_BatchPart, getBatch) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "batch");

}

/**
 * Sets the Request for this batch part
 *
 * @param Request request
 *
 * @return void
 */
PHP_METHOD(Arango_Batch_BatchPart, setRequest) {

	zval *request, request_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);

	zephir_fetch_params(0, 1, 0, &request);



	zephir_update_property_zval(this_ptr, SL("request"), request);

}

/**
 * Gets the Request object for this batch part
 *
 * @return Arango\Http\Request
 */
PHP_METHOD(Arango_Batch_BatchPart, getRequest) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "request");

}

/**
 * Gets the HTTP code for the current batch part
 *
 * @return int | null
 */
PHP_METHOD(Arango_Batch_BatchPart, getHttpCode) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getresponse", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getcode", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get the batch part identified by the array key (0...n)
 * or its id if it was set with nextBatchPartId($id)
 *
 * @throws \Arango\Exception\ClientException
 *
 * @return mixed
 */
PHP_METHOD(Arango_Batch_BatchPart, getProcessedResponse) {

	zend_string *_24$$13;
	zend_ulong _23$$13;
	zend_class_entry *_8$$5, *_10$$7;
	zend_bool _4$$4, _12$$8, _17$$11;
	zval _1;
	zval __$false, documentClass, response, options, body, _0, _2, _3, _9, _11, _14, _16, _19, _5$$4, _7$$5, _13$$8, id$$9, _18$$11, id$$12, data$$13, _20$$13, _21$$13, *_22$$13, _25$$14;
	zephir_fcall_cache_entry *_6 = NULL, *_15 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&documentClass);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&body);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&id$$9);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&id$$12);
	ZVAL_UNDEF(&data$$13);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&_25$$14);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("documentClass"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&documentClass, &_0);
	ZEPHIR_CALL_METHOD(&response, this_ptr, "getresponse", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("type"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 12, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "first");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "getdocument");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "document");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "getedge");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "edge");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "getedges");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "getcollection");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "collection");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "cursor");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "all");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "by");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "remove");
	zephir_array_fast_append(&_1, &_2);
	if (!(zephir_fast_in_array(&_0, &_1 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(arango_exception_clientexception_ce, "Could not determine response data type", "arango/batch/batchpart.zep", 181);
		return;
	}
	zephir_read_property(&_3, this_ptr, SL("type"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_STRING(&_3, "first")) {
		ZEPHIR_CALL_METHOD(&body, &response, "toarray", NULL, 0);
		zephir_check_call_status();
		_4$$4 = !(zephir_array_isset_string(&body, SL("error")));
		if (!(_4$$4)) {
			zephir_array_fetch_string(&_5$$4, &body, SL("error"), PH_NOISY | PH_READONLY, "arango/batch/batchpart.zep", 186 TSRMLS_CC);
			_4$$4 = ZEPHIR_IS_FALSE(&_5$$4);
		}
		if (_4$$4) {
			ZEPHIR_CALL_METHOD(&options, this_ptr, "getcursoroptions", &_6, 0);
			zephir_check_call_status();
			zephir_array_update_string(&options, SL("_isNew"), &__$false, PH_COPY | PH_SEPARATE);
			zephir_array_fetch_string(&_7$$5, &body, SL("document"), PH_NOISY | PH_READONLY, "arango/batch/batchpart.zep", 189 TSRMLS_CC);
			_8$$5 = zephir_fetch_class(&documentClass TSRMLS_CC);
			ZEPHIR_CALL_CE_STATIC(&response, _8$$5, "createfromarray", NULL, 0, &_7$$5, &options);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&response);
			ZVAL_BOOL(&response, 0);
		}
	}
	zephir_read_property(&_9, this_ptr, SL("type"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_STRING(&_9, "getdocument")) {
		ZEPHIR_CALL_METHOD(&body, &response, "toarray", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&options, this_ptr, "getcursoroptions", &_6, 0);
		zephir_check_call_status();
		zephir_array_update_string(&options, SL("_isNew"), &__$false, PH_COPY | PH_SEPARATE);
		_10$$7 = zephir_fetch_class(&documentClass TSRMLS_CC);
		ZEPHIR_CALL_CE_STATIC(&response, _10$$7, "createfromarray", NULL, 0, &body, &options);
		zephir_check_call_status();
	}
	zephir_read_property(&_11, this_ptr, SL("type"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_STRING(&_11, "document")) {
		ZEPHIR_CALL_METHOD(&body, &response, "toarray", NULL, 0);
		zephir_check_call_status();
		_12$$8 = !(zephir_array_isset_string(&body, SL("error")));
		if (!(_12$$8)) {
			zephir_array_fetch_string(&_13$$8, &body, SL("error"), PH_NOISY | PH_READONLY, "arango/batch/batchpart.zep", 204 TSRMLS_CC);
			_12$$8 = ZEPHIR_IS_FALSE(&_13$$8);
		}
		if (_12$$8) {
			ZEPHIR_OBS_VAR(&id$$9);
			zephir_array_fetch_string(&id$$9, &body, SL("id"), PH_NOISY, "arango/batch/batchpart.zep", 206 TSRMLS_CC);
			ZEPHIR_CPY_WRT(&response, &id$$9);
		}
	}
	zephir_read_property(&_14, this_ptr, SL("type"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_STRING(&_14, "getedge")) {
		ZEPHIR_CALL_METHOD(&body, &response, "toarray", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&options, this_ptr, "getcursoroptions", &_6, 0);
		zephir_check_call_status();
		zephir_array_update_string(&options, SL("_isNew"), &__$false, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_CE_STATIC(&response, arango_document_edge_ce, "createfromarray", &_15, 0, &body, &options);
		zephir_check_call_status();
	}
	zephir_read_property(&_16, this_ptr, SL("type"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_STRING(&_16, "edge")) {
		ZEPHIR_CALL_METHOD(&body, &response, "toarray", NULL, 0);
		zephir_check_call_status();
		_17$$11 = !(zephir_array_isset_string(&body, SL("error")));
		if (!(_17$$11)) {
			zephir_array_fetch_string(&_18$$11, &body, SL("error"), PH_NOISY | PH_READONLY, "arango/batch/batchpart.zep", 221 TSRMLS_CC);
			_17$$11 = ZEPHIR_IS_FALSE(&_18$$11);
		}
		if (_17$$11) {
			ZEPHIR_OBS_VAR(&id$$12);
			zephir_array_fetch_string(&id$$12, &body, SL("id"), PH_NOISY, "arango/batch/batchpart.zep", 223 TSRMLS_CC);
			ZEPHIR_CPY_WRT(&response, &id$$12);
		}
	}
	zephir_read_property(&_19, this_ptr, SL("type"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_STRING(&_19, "getedges")) {
		ZEPHIR_CALL_METHOD(&body, &response, "toarray", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&options, this_ptr, "getcursoroptions", &_6, 0);
		zephir_check_call_status();
		zephir_array_update_string(&options, SL("_isNew"), &__$false, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&response);
		array_init(&response);
		zephir_array_fetch_string(&_20$$13, &body, SL("edges"), PH_NOISY | PH_READONLY, "arango/batch/batchpart.zep", 235 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_21$$13);
		zephir_is_iterable(&_20$$13, 0, "arango/batch/batchpart.zep", 238);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_20$$13), _23$$13, _24$$13, _22$$13)
		{
			ZEPHIR_INIT_NVAR(&_21$$13);
			if (_24$$13 != NULL) { 
				ZVAL_STR_COPY(&_21$$13, _24$$13);
			} else {
				ZVAL_LONG(&_21$$13, _23$$13);
			}
			ZEPHIR_INIT_NVAR(&data$$13);
			ZVAL_COPY(&data$$13, _22$$13);
			ZEPHIR_CALL_CE_STATIC(&_25$$14, arango_document_edge_ce, "createfromarray", &_15, 0, &data$$13, &options);
			zephir_check_call_status();
			zephir_array_append(&response, &_25$$14, PH_SEPARATE, "arango/batch/batchpart.zep", 236);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&data$$13);
		ZEPHIR_INIT_NVAR(&_21$$13);
	}
	RETURN_CCTOR(&response);

}

zend_object *zephir_init_properties_Arango_Batch_BatchPart(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("cursorOptions"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("cursorOptions"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

