
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "ext/spl/spl_fixedarray.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * Provides batching functionality
 *
 * @package Arango/Batch
 * @class Batch
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Batch_Batch) {

	ZEPHIR_REGISTER_CLASS(Arango\\Batch, Batch, arango, batch_batch, arango_batch_batch_method_entry, 0);

	/**
	 * Document type
	 *
	 * @var string
	 */
	zend_declare_property_string(arango_batch_batch_ce, SL("documentType"), "Document", ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Batch response object
	 *
	 * @var Response
	 */
	zend_declare_property_null(arango_batch_batch_ce, SL("batchResponse"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Flag that signals if this batch was processed or not
	 *
	 * @var boolean
	 */
	zend_declare_property_bool(arango_batch_batch_ce, SL("processed"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Batch size
	 *
	 * @var int
	 */
	zend_declare_property_null(arango_batch_batch_ce, SL("batchSize"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * An array of BatchPart objects
	 *
	 * @var array
	 */
	zend_declare_property_null(arango_batch_batch_ce, SL("batchParts"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * The next batch part Id
	 *
	 * @var int
	 */
	zend_declare_property_null(arango_batch_batch_ce, SL("nextBatchPartId"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * An array of batchPartCursor options
	 *
	 * @var array
	 */
	zend_declare_property_null(arango_batch_batch_ce, SL("batchPartCursorOptions"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * The connection object
	 *
	 * @var Connection
	 */
	zend_declare_property_null(arango_batch_batch_ce, SL("connection"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * The sanitize default value
	 *
	 * @var boolean
	 */
	zend_declare_property_bool(arango_batch_batch_ce, SL("sanitize"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * The batch next id
	 *
	 * @var integer
	 */
	zend_declare_property_null(arango_batch_batch_ce, SL("nextId"), ZEND_ACC_PRIVATE TSRMLS_CC);

	arango_batch_batch_ce->create_object = zephir_init_properties_Arango_Batch_Batch;
	return SUCCESS;

}

/**
 * Document type
 */
PHP_METHOD(Arango_Batch_Batch, getDocumentType) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "documentType");

}

/**
 * Document type
 */
PHP_METHOD(Arango_Batch_Batch, setDocumentType) {

	zval *documentType_param = NULL;
	zval documentType;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&documentType);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &documentType_param);

	zephir_get_strval(&documentType, documentType_param);


	zephir_update_property_zval(this_ptr, SL("documentType"), &documentType);
	RETURN_THIS();

}

/**
 * Constructor for Batch instance. Batch instance by default starts capturing request after initiated.
 * To disable this, pass startCapture=>false inside the options array parameter
 *
 * @param Connection connection
 * @param array      options
 *
 * Options are:
 * "sanitize" = True to remove _id and _rev attributes from result documents returned from this batch. Defaults to false.
 * "startCapture" = Start batch capturing immediately after batch instantiation. Defaults to true.
 * "batchSize" = Defines a fixed array size for holding the batch parts. The id's of the batch parts can only be integers.
 *             When this option is defined, the batch mechanism will use an SplFixedArray instead of the normal PHP arrays.
 *             In most cases, this will result in increased performance of about 5% to 15%, depending on batch size and data.
 *
 */
PHP_METHOD(Arango_Batch_Batch, __construct) {

	zend_bool _1, _8;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options, _6;
	zval *connection, connection_sub, *options_param = NULL, __$true, __$false, _0$$3, _2, _7, _3$$4, _4$$4, _5$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &connection, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	if (zephir_array_isset_string(&options, SL("sanitize"))) {
		ZEPHIR_OBS_VAR(&_0$$3);
		zephir_array_fetch_string(&_0$$3, &options, SL("sanitize"), PH_NOISY, "arango/batch/batch.zep", 111 TSRMLS_CC);
		if (zephir_get_boolval(&_0$$3)) {
			zephir_update_property_zval(this_ptr, SL("sanitize"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("sanitize"), &__$false);
		}
	}
	_1 = zephir_array_isset_string(&options, SL("batchSize"));
	if (_1) {
		zephir_array_fetch_string(&_2, &options, SL("batchSize"), PH_NOISY | PH_READONLY, "arango/batch/batch.zep", 114 TSRMLS_CC);
		_1 = ZEPHIR_GT_LONG(&_2, 0);
	}
	if (_1) {
		ZEPHIR_OBS_VAR(&_3$$4);
		zephir_array_fetch_string(&_3$$4, &options, SL("batchSize"), PH_NOISY, "arango/batch/batch.zep", 115 TSRMLS_CC);
		ZEPHIR_INIT_ZVAL_NREF(_4$$4);
		ZVAL_LONG(&_4$$4, zephir_get_intval(&_3$$4));
		zephir_update_property_zval(this_ptr, SL("batchSize"), &_4$$4);
		ZEPHIR_INIT_VAR(&_5$$4);
		object_init_ex(&_5$$4, spl_ce_SplFixedArray);
		zephir_read_property(&_4$$4, this_ptr, SL("batchSize"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_5$$4, "__construct", NULL, 11, &_4$$4);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("batchParts"), &_5$$4);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setconnection", NULL, 0, connection);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 1, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_7);
	zephir_read_property(&_7, this_ptr, SL("sanitize"), PH_NOISY_CC);
	zephir_array_update_string(&_6, SL("_sanitize"), &_7, PH_COPY | PH_SEPARATE);
	zephir_update_property_zval(this_ptr, SL("batchPartCursorOptions"), &_6);
	_8 = zephir_array_isset_string(&options, SL("startCapture"));
	if (_8) {
		ZEPHIR_OBS_NVAR(&_7);
		zephir_array_fetch_string(&_7, &options, SL("startCapture"), PH_NOISY, "arango/batch/batch.zep", 123 TSRMLS_CC);
		_8 = zephir_get_boolval(&_7);
	}
	if (_8) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "startcapture", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the connection for current batch
 *
 * @param Connection connection
 * @return void
 */
PHP_METHOD(Arango_Batch_Batch, setConnection) {

	zval *connection, connection_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);

	zephir_fetch_params(0, 1, 0, &connection);



	zephir_update_property_zval(this_ptr, SL("connection"), connection);

}

/**
 * Get this batch connection
 *
 * @return \Arango\Connection\Connection
 */
PHP_METHOD(Arango_Batch_Batch, getConnection) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "connection");

}

/**
 * Sets the batch's associated connection into capture mode.
 *
 * @param boolean state
 *
 * @return void
 */
PHP_METHOD(Arango_Batch_Batch, setCapture) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *state_param = NULL, _0, _1;
	zend_bool state;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &state_param);

	state = zephir_get_boolval(state_param);


	zephir_read_property(&_0, this_ptr, SL("connection"), PH_NOISY_CC | PH_READONLY);
	if (state) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_0, "setcapturebatch", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets connection into Batch-Request mode.
 * This is necessary to distinguish between normal and the batch request.
 *
 * @param boolean state
 *
 * @return void
 */
PHP_METHOD(Arango_Batch_Batch, setBatchRequest) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *state_param = NULL, __$true, __$false, _0, _1;
	zend_bool state;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &state_param);

	state = zephir_get_boolval(state_param);


	zephir_read_property(&_0, this_ptr, SL("connection"), PH_NOISY_CC | PH_READONLY);
	if (state) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_0, "setbatchrequest", NULL, 0, &_1);
	zephir_check_call_status();
	if (1) {
		zephir_update_property_zval(this_ptr, SL("processed"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("processed"), &__$false);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the batch active in its associated connection
 *
 * @return void
 */
PHP_METHOD(Arango_Batch_Batch, setActive) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("connection"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setactivebatch", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns true, if this batch is active in its associated connection
 *
 * @return boolean
 */
PHP_METHOD(Arango_Batch_Batch, isActive) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("connection"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "getactivebatch", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(this_ptr, &_1));

}

/**
 * Returns true, if this batch is capturing requests
 *
 * @return boolean
 */
PHP_METHOD(Arango_Batch_Batch, isCapturing) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("connection"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "isinbatchcapturemode", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Activates the batch.
 * This sets the batch active in its associated connection and also starts capturing.
 *
 * @return void
 */
PHP_METHOD(Arango_Batch_Batch, startCapture) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setactive", NULL, 0);
	zephir_check_call_status();
	ZVAL_BOOL(&_0, 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setcapture", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Stop capturing requests.
 * If the batch has not been processed yet,
 * more requests can be appended by calling startCapture() again.
 *
 * @throws \Arango\Exception\ClientException
 *
 * @return void
 */
PHP_METHOD(Arango_Batch_Batch, stopCapture) {

	zend_bool _1;
	zval _0, _2, _3$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isactive", NULL, 0);
	zephir_check_call_status();
	_1 = zephir_is_true(&_0);
	if (_1) {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "iscapturing", NULL, 0);
		zephir_check_call_status();
		_1 = zephir_is_true(&_2);
	}
	if (_1) {
		ZVAL_BOOL(&_3$$3, 0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setcapture", NULL, 0, &_3$$3);
		zephir_check_call_status();
		RETURN_MM_NULL();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(arango_exception_clientexception_ce, "Cannot stop capturing with this batch. Batch is not active", "arango/batch/batch.zep", 225);
	return;

}

/**
 * Sets the id of the next batch-part.
 * The id can later be used to retrieve the batch-part.
 *
 * @param mixed batchPartId
 *
 * @return void
 */
PHP_METHOD(Arango_Batch_Batch, nextBatchPartId) {

	zval *batchPartId, batchPartId_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&batchPartId_sub);

	zephir_fetch_params(0, 1, 0, &batchPartId);



	zephir_update_property_zval(this_ptr, SL("nextBatchPartId"), batchPartId);

}

/**
 * Set client side cursor options (for example: sanitize) for the next batch part.
 *
 * @param mixed batchPartCursorOptions
 *
 * @return void
 */
PHP_METHOD(Arango_Batch_Batch, nextBatchPartCursorOptions) {

	zval *batchPartCursorOptions, batchPartCursorOptions_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&batchPartCursorOptions_sub);

	zephir_fetch_params(0, 1, 0, &batchPartCursorOptions);



	zephir_update_property_zval(this_ptr, SL("batchPartCursorOptions"), batchPartCursorOptions);

}

/**
 * Append the request to the batch-part
 *
 * @throws \Arango\Exception\ClientException
 *
 * @param string method   - The method of request
 * @param string request  - The request that will get appended to the batch
 *
 * @return \Arango\Http\Response
 */
PHP_METHOD(Arango_Batch_Batch, append) {

	zval _18;
	zend_bool _6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *method_param = NULL, *request_param = NULL, __$null, regs, type, batchPart, batchPartId, result, response, _0, _2, _3, _5, _7, _9, _17, _19, _4$$4, _8$$5, nextNumeric$$6, _10$$6, _11$$6, _12$$6, _13$$7, _14$$7, _15$$8;
	zval method, request, _16;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&request);
	ZVAL_UNDEF(&_16);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&regs);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&batchPart);
	ZVAL_UNDEF(&batchPartId);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&nextNumeric$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_18);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &request_param);

	zephir_get_strval(&method, method_param);
	zephir_get_strval(&request, request_param);


	ZEPHIR_CALL_CE_STATIC(&_0, arango_http_client_ce, "isvalidmethod", &_1, 0, &method);
	zephir_check_call_status();
	if (!zephir_is_true(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(arango_exception_clientexception_ce, "Invalid HTTP method supplied for batch", "arango/batch/batch.zep", 265);
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "%/_api/simple/(?P<simple>\\w*)|/_api/(?P<direct>\\w*)%ix");
	zephir_preg_match(&_2, &_3, &request, &regs, 0, 0 , 0  TSRMLS_CC);
	if (!(zephir_array_isset_string(&regs, SL("direct")))) {
		ZEPHIR_INIT_VAR(&_4$$4);
		ZVAL_STRING(&_4$$4, "");
		zephir_array_update_string(&regs, SL("direct"), &_4$$4, PH_COPY | PH_SEPARATE);
	}
	zephir_array_fetch_string(&_5, &regs, SL("direct"), PH_NOISY | PH_READONLY, "arango/batch/batch.zep", 274 TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(&_5, "")) {
		ZEPHIR_OBS_VAR(&type);
		zephir_array_fetch_string(&type, &regs, SL("direct"), PH_NOISY, "arango/batch/batch.zep", 274 TSRMLS_CC);
	} else {
		ZEPHIR_OBS_NVAR(&type);
		zephir_array_fetch_string(&type, &regs, SL("simple"), PH_NOISY, "arango/batch/batch.zep", 274 TSRMLS_CC);
	}
	_6 = ZEPHIR_IS_STRING(&method, "GET");
	if (_6) {
		zephir_array_fetch_string(&_7, &regs, SL("direct"), PH_NOISY | PH_READONLY, "arango/batch/batch.zep", 276 TSRMLS_CC);
		_6 = ZEPHIR_IS_EQUAL(&type, &_7);
	}
	if (_6) {
		ZEPHIR_INIT_VAR(&_8$$5);
		ZEPHIR_CONCAT_SV(&_8$$5, "get", &type);
		ZEPHIR_CPY_WRT(&type, &_8$$5);
	}
	zephir_read_property(&_9, this_ptr, SL("nextBatchPartId"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_9) == IS_NULL) {
		ZEPHIR_INIT_VAR(&nextNumeric$$6);
		ZVAL_LONG(&nextNumeric$$6, 0);
		zephir_read_property(&_10$$6, this_ptr, SL("batchParts"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_11$$6);
		ZVAL_STRING(&_11$$6, "\\SplFixedArray");
		ZEPHIR_CALL_FUNCTION(&_12$$6, "is_a", NULL, 12, &_10$$6, &_11$$6);
		zephir_check_call_status();
		if (zephir_is_true(&_12$$6)) {
			ZEPHIR_OBS_NVAR(&nextNumeric$$6);
			zephir_read_property(&nextNumeric$$6, this_ptr, SL("nextId"), PH_NOISY_CC);
			zephir_read_property(&_13$$7, this_ptr, SL("nextId"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_ZVAL_NREF(_14$$7);
			ZVAL_LONG(&_14$$7, (zephir_get_numberval(&_13$$7) + 1));
			zephir_update_property_zval(this_ptr, SL("nextId"), &_14$$7);
		} else {
			zephir_read_property(&_15$$8, this_ptr, SL("batchParts"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_NVAR(&nextNumeric$$6);
			ZVAL_LONG(&nextNumeric$$6, zephir_fast_count_int(&_15$$8 TSRMLS_CC));
		}
		ZEPHIR_CPY_WRT(&batchPartId, &nextNumeric$$6);
	} else {
		ZEPHIR_OBS_NVAR(&batchPartId);
		zephir_read_property(&batchPartId, this_ptr, SL("nextBatchPartId"), PH_NOISY_CC);
		zephir_update_property_zval(this_ptr, SL("nextBatchPartId"), &__$null);
	}
	ZEPHIR_INIT_VAR(&_16);
	ZEPHIR_CONCAT_SS(&_16, "HTTP/1.1 202 Accepted ", "\r\n");
	ZEPHIR_CPY_WRT(&result, &_16);
	ZEPHIR_INIT_VAR(&_17);
	ZEPHIR_CONCAT_VSS(&_17, &result, "location: /_db/_system/_api/document/0/0", "\r\n");
	ZEPHIR_CPY_WRT(&result, &_17);
	ZEPHIR_INIT_LNVAR(_17);
	ZEPHIR_CONCAT_VSS(&_17, &result, "content-type: application/json; charset=utf-8", "\r\n");
	ZEPHIR_CPY_WRT(&result, &_17);
	ZEPHIR_INIT_LNVAR(_17);
	ZEPHIR_CONCAT_VSS(&_17, &result, "etag: \"0\"", "\r\n");
	ZEPHIR_CPY_WRT(&result, &_17);
	ZEPHIR_INIT_LNVAR(_17);
	ZEPHIR_CONCAT_VSS(&_17, &result, "connection: Close", "\r\n");
	ZEPHIR_CPY_WRT(&result, &_17);
	ZEPHIR_INIT_LNVAR(_17);
	ZEPHIR_CONCAT_VSS(&_17, &result, "{\"error\":false,\"_id\":\"0/0\",\"id\":\"0\",\"_rev\":0,\"hasMore\":1, \"result\":[{}], \"documents\":[{}]}", "\r\n");
	ZEPHIR_CPY_WRT(&result, &_17);
	ZEPHIR_INIT_VAR(&response);
	object_init_ex(&response, arango_http_response_ce);
	ZEPHIR_CALL_METHOD(NULL, &response, "__construct", NULL, 13, &result);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&batchPart);
	object_init_ex(&batchPart, arango_batch_batchpart_ce);
	ZEPHIR_INIT_VAR(&_18);
	zephir_create_array(&_18, 2, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_19);
	zephir_read_property(&_19, this_ptr, SL("batchPartCursorOptions"), PH_NOISY_CC);
	zephir_array_update_string(&_18, SL("cursorOptions"), &_19, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_19);
	zephir_read_property(&_19, this_ptr, SL("documentType"), PH_NOISY_CC);
	zephir_array_update_string(&_18, SL("_documentClass"), &_19, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, &batchPart, "__construct", NULL, 14, this_ptr, &batchPartId, &type, &request, &response, &_18);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("batchParts"), &batchPartId, &batchPart TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, &response, "setbatchpart", NULL, 15, &batchPart);
	zephir_check_call_status();
	RETURN_CCTOR(&response);

}

/**
 * Split batch request and use ContentId as array key
 *
 * @throws \Arango\Exception\ClientException
 *
 * @param mixed pattern
 * @param mixed content
 *
 * @return array
 */
PHP_METHOD(Arango_Batch_Batch, splitWithContentIdKey) {

	zend_string *_2;
	zend_ulong _1;
	zval data;
	zephir_fcall_cache_entry *_3 = NULL, *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern, pattern_sub, *content, content_sub, exploded, key, value, *_0, response$$3, contentId$$3, _4$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern_sub);
	ZVAL_UNDEF(&content_sub);
	ZVAL_UNDEF(&exploded);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&response$$3);
	ZVAL_UNDEF(&contentId$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &pattern, &content);



	ZEPHIR_INIT_VAR(&exploded);
	zephir_fast_explode(&exploded, pattern, content, LONG_MAX TSRMLS_CC);
	zephir_is_iterable(&exploded, 0, "arango/batch/batch.zep", 345);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&exploded), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&key, _2);
		} else {
			ZVAL_LONG(&key, _1);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		ZEPHIR_INIT_NVAR(&response$$3);
		object_init_ex(&response$$3, arango_http_response_ce);
		ZEPHIR_CALL_METHOD(NULL, &response$$3, "__construct", &_3, 13, &value);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "Content-Id");
		ZEPHIR_CALL_METHOD(&contentId$$3, &response$$3, "getheader", &_5, 16, &_4$$3);
		zephir_check_call_status();
		if (!(Z_TYPE_P(&contentId$$3) == IS_NULL)) {
			zephir_array_update_zval(&data, &contentId$$3, &value, PH_COPY | PH_SEPARATE);
			continue;
		}
		zephir_array_update_zval(&data, &key, &value, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CTOR(&data);

}

/**
 * Processes this batch. This sends the captured requests to the server as one batch.
 * Batch if processing of the batch was successful or the HttpResponse object in case of a failure.
 * A successful process just means that tha parts were processed.
 * Each part has it's own response though and should be checked on its own.
 *
 * @throws \Arango\Exception\ClientException
 * @throws \Arango\Exception\Exception
 *
 * @return \Arango\Http\Response | \Arango\Batch\Batch
 */
PHP_METHOD(Arango_Batch_Batch, process) {

	zend_string *_7, *_25;
	zend_ulong _6, _24;
	zval _2, _22, _15$$5, _11$$7;
	zval data, batchParts, combinedDataHeader, _0, _1, _3, batchValue, _4, *_5, params, url, _17, _18, _19, _20, body, _21, key, value, *_23, _8$$5, _9$$5, _14$$5, _10$$7, _12$$7, _13$$8, response$$10, batchPartsResponses$$10, _28$$10, _30$$10;
	zephir_fcall_cache_entry *_16 = NULL, *_26 = NULL, *_27 = NULL, *_29 = NULL, *_31 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&batchParts);
	ZVAL_UNDEF(&combinedDataHeader);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&batchValue);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&body);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&response$$10);
	ZVAL_UNDEF(&batchPartsResponses$$10);
	ZVAL_UNDEF(&_28$$10);
	ZVAL_UNDEF(&_30$$10);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_11$$7);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "iscapturing", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "stopcapture", NULL, 0);
		zephir_check_call_status();
	}
	ZVAL_BOOL(&_1, 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setbatchrequest", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&data);
	ZVAL_STRING(&data, "");
	zephir_read_property(&_1, this_ptr, SL("batchParts"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&batchParts, &_1);
	if (zephir_fast_count_int(&batchParts TSRMLS_CC) == 0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(arango_exception_clientexception_ce, "Cannot process empty batch", "arango/batch/batch.zep", 371);
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SSS(&_2, "--", "XXXsubpartXXX", "\r\n");
	ZEPHIR_CPY_WRT(&combinedDataHeader, &_2);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VSS(&_3, &combinedDataHeader, "Content-Type: application/x-arango-batchpart", "\r\n");
	ZEPHIR_CPY_WRT(&combinedDataHeader, &_3);
	ZEPHIR_INIT_VAR(&_4);
	zephir_is_iterable(&batchParts, 0, "arango/batch/batch.zep", 394);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&batchParts), _6, _7, _5)
	{
		ZEPHIR_INIT_NVAR(&_4);
		if (_7 != NULL) { 
			ZVAL_STR_COPY(&_4, _7);
		} else {
			ZVAL_LONG(&_4, _6);
		}
		ZEPHIR_INIT_NVAR(&batchValue);
		ZVAL_COPY(&batchValue, _5);
		if (Z_TYPE_P(&batchValue) == IS_NULL) {
			continue;
		}
		ZEPHIR_INIT_LNVAR(_8$$5);
		ZEPHIR_CONCAT_VV(&_8$$5, &data, &combinedDataHeader);
		ZEPHIR_CPY_WRT(&data, &_8$$5);
		ZEPHIR_CALL_METHOD(&_9$$5, &batchValue, "getid", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&data);
		if (!(Z_TYPE_P(&_9$$5) == IS_NULL)) {
			ZEPHIR_CALL_METHOD(&_10$$7, &batchValue, "getid", NULL, 0);
			zephir_check_call_status();
			zephir_get_strval(&_11$$7, &_10$$7);
			ZEPHIR_INIT_LNVAR(_12$$7);
			ZEPHIR_CONCAT_VSVS(&_12$$7, &data, "Content-Id: ", &_11$$7, "\r\n\r\n");
			ZEPHIR_CPY_WRT(&data, &_12$$7);
		} else {
			ZEPHIR_INIT_LNVAR(_13$$8);
			ZEPHIR_CONCAT_VS(&_13$$8, &data, "\r\n");
			ZEPHIR_CPY_WRT(&data, &_13$$8);
		}
		ZEPHIR_CALL_METHOD(&_14$$5, &batchValue, "getrequest", NULL, 0);
		zephir_check_call_status();
		zephir_get_strval(&_15$$5, &_14$$5);
		ZEPHIR_INIT_LNVAR(_8$$5);
		ZEPHIR_CONCAT_VVS(&_8$$5, &data, &_15$$5, "\r\n");
		ZEPHIR_CPY_WRT(&data, &_8$$5);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&batchValue);
	ZEPHIR_INIT_NVAR(&_4);
	ZEPHIR_INIT_LNVAR(_3);
	ZEPHIR_CONCAT_VSSSS(&_3, &data, "--", "XXXsubpartXXX", "--", "\r\n\r\n");
	ZEPHIR_CPY_WRT(&data, &_3);
	ZEPHIR_INIT_VAR(&params);
	array_init(&params);
	ZEPHIR_INIT_VAR(&_17);
	ZVAL_STRING(&_17, "/_api/batch");
	ZEPHIR_CALL_CE_STATIC(&url, arango_http_url_ce, "appendparamstourl", &_16, 0, &_17, &params);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("connection"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_18, &_1, "post", NULL, 0, &url, &data);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("batchResponse"), &_18);
	zephir_read_property(&_19, this_ptr, SL("batchResponse"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_20, &_19, "getcode", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_LONG(&_20, 200)) {
		RETURN_MM_MEMBER(getThis(), "batchResponse");
	}
	zephir_read_property(&_21, this_ptr, SL("batchResponse"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&body, &_21, "getbody", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_17);
	ZEPHIR_INIT_LNVAR(_2);
	ZEPHIR_CONCAT_SSS(&_2, "--", "XXXsubpartXXX", "--");
	zephir_fast_trim(&_17, &body, &_2, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_CPY_WRT(&body, &_17);
	ZEPHIR_INIT_VAR(&_22);
	ZEPHIR_CONCAT_SSS(&_22, "--", "XXXsubpartXXX", "\r\n");
	ZEPHIR_CALL_METHOD(&batchParts, this_ptr, "splitwithcontentidkey", NULL, 0, &_22, &body);
	zephir_check_call_status();
	zephir_is_iterable(&batchParts, 0, "arango/batch/batch.zep", 421);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&batchParts), _24, _25, _23)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_25 != NULL) { 
			ZVAL_STR_COPY(&key, _25);
		} else {
			ZVAL_LONG(&key, _24);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _23);
		ZEPHIR_INIT_NVAR(&response$$10);
		object_init_ex(&response$$10, arango_http_response_ce);
		ZEPHIR_CALL_METHOD(NULL, &response$$10, "__construct", &_26, 13, &value);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&body, &response$$10, "getbody", &_27, 17);
		zephir_check_call_status();
		zephir_array_update_zval(&batchPartsResponses$$10, &key, &response$$10, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_28$$10, this_ptr, "getpart", &_29, 0, &key);
		zephir_check_call_status();
		zephir_array_fetch(&_30$$10, &batchPartsResponses$$10, &key, PH_NOISY | PH_READONLY, "arango/batch/batch.zep", 418 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &_28$$10, "setresponse", &_31, 0, &_30$$10);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_THIS();

}

/**
 * Get the batch part identified by array key
 * or its ID (if it was set with nextBatchPartId($id))
 *
 * @throws \Arango\Exception\ClientException
 *
 * @param mixed partId The batch part ID
 *
 * @return batchPart
 */
PHP_METHOD(Arango_Batch_Batch, getPart) {

	zval *partId, partId_sub, _0, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&partId_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	zephir_fetch_params(0, 1, 0, &partId);



	zephir_read_property(&_0, this_ptr, SL("batchParts"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, partId)) {
		zephir_read_property(&_1$$3, this_ptr, SL("batchParts"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, partId, PH_NOISY | PH_READONLY, "arango/batch/batch.zep", 436 TSRMLS_CC);
		RETURN_CTORW(&_2$$3);
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(arango_exception_clientexception_ce, "Request batch part does not exist.", "arango/batch/batch.zep", 439);
	return;

}

zend_object *zephir_init_properties_Arango_Batch_Batch(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("batchPartCursorOptions"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("batchPartCursorOptions"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("batchParts"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("batchParts"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

