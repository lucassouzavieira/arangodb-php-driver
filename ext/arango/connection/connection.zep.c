
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/file.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/time.h"


/**
 * Provides access to Arango server <br>
 *
 * As all access is done using HTTP, we do not need to establish a
 * persistent connection and keep its state. <br>
 *
 * Instead, connections are established on the fly for each request
 * and are destroyed afterwards. <br>
 *
 * @package Arango\Connection
 * @class Connection
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Connection_Connection) {

	ZEPHIR_REGISTER_CLASS_EX(Arango\\Connection, Connection, arango, connection_connection, arango_http_request_ce, arango_connection_connection_method_entry, 0);

	/**
	 * Connection options
	 *
	 * @var \Arango\Connection\Options
	 */
	zend_declare_property_null(arango_connection_connection_ce, SL("options"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Pre-assembled HTTP headers string for connection
	 * This is pre-calculated when connection options are set/changed, to avoid
	 * calculation of the same HTTP header values in each request done via the
	 * connection
	 *
	 * @var string
	 */
	zend_declare_property_null(arango_connection_connection_ce, SL("httpHeader"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Pre-assembled base URL for the current database
	 * This is pre-calculated when connection options are set/changed, to avoid
	 * calculation of the same base URL in each request done via the
	 * connection
	 *
	 * @var string
	 */
	zend_declare_property_null(arango_connection_connection_ce, SL("baseUrl"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Connection handle, used in case of keep-alive
	 *
	 * @var resource
	 */
	zend_declare_property_null(arango_connection_connection_ce, SL("handle"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Flag if keep-alive connections are used
	 *
	 * @var boolean
	 */
	zend_declare_property_null(arango_connection_connection_ce, SL("useKeepAlive"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Batches array
	 *
	 * @var boolean
	 */
	zend_declare_property_null(arango_connection_connection_ce, SL("batches"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * activeBatch object
	 *
	 * @var Batch
	 */
	zend_declare_property_null(arango_connection_connection_ce, SL("activeBatch"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * captureBatch boolean
	 *
	 * @var boolean
	 */
	zend_declare_property_null(arango_connection_connection_ce, SL("captureBatch"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * batchRequest boolean
	 *
	 * @var boolean
	 */
	zend_declare_property_null(arango_connection_connection_ce, SL("batchRequest"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * database string
	 *
	 * @var string
	 */
	zend_declare_property_null(arango_connection_connection_ce, SL("database"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

/**
 * Set up the connection object, validate the options provided
 *
 * @throws \Exception
 * @param array options - initial connection options
 */
PHP_METHOD(Arango_Connection_Connection, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, __$true, __$false, _0, _1, _2, _3, _4, _5;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	zephir_get_arrval(&options, options_param);


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, arango_connection_options_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 30, &options);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("options"), &_0);
	if (0) {
		zephir_update_property_zval(this_ptr, SL("useKeepAlive"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("useKeepAlive"), &__$false);
	}
	zephir_read_property(&_1, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "Connection");
	ZEPHIR_CALL_METHOD(&_2, &_1, "offsetget", NULL, 0, &_3);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(&_2, "Keep-Alive")) {
		if (1) {
			zephir_update_property_zval(this_ptr, SL("useKeepAlive"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("useKeepAlive"), &__$false);
		}
	}
	zephir_read_property(&_4, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "database");
	ZEPHIR_CALL_METHOD(&_5, &_4, "offsetget", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdatabase", NULL, 0, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "updatehttpheader", NULL, 31);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Close existing connection handle if a keep-alive connection was used
 *
 * @return void
 */
PHP_METHOD(Arango_Connection_Connection, __destruct) {

	zend_bool _1;
	zval _0, _2, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);


	zephir_read_property(&_0, this_ptr, SL("useKeepAlive"), PH_NOISY_CC | PH_READONLY);
	_1 = zephir_is_true(&_0);
	if (_1) {
		zephir_read_property(&_2, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
		_1 = Z_TYPE_P(&_2) == IS_RESOURCE;
	}
	if (_1) {
		zephir_read_property(&_3$$3, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
		zephir_fclose(&_3$$3 TSRMLS_CC);
	}

}

/**
 * Validate an option
 *
 * @throws \Arango\Exception\ClientException
 * @param string name - name of options
 * @param value
 * @return boolean
 */
PHP_METHOD(Arango_Connection_Connection, validateOption) {

	zval validOptions;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value, value_sub, _0, _1$$3;
	zval name, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&validOptions);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	zephir_get_strval(&name, name_param);


	ZEPHIR_INIT_VAR(&validOptions);
	zephir_create_array(&validOptions, 6, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "endpoint");
	zephir_array_fast_append(&validOptions, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "host");
	zephir_array_fast_append(&validOptions, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "port");
	zephir_array_fast_append(&validOptions, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "verifyCert");
	zephir_array_fast_append(&validOptions, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "ciphers");
	zephir_array_fast_append(&validOptions, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "allowSelfSigned");
	zephir_array_fast_append(&validOptions, &_0);
	if (zephir_fast_in_array(&name, &validOptions TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, arango_exception_clientexception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Must not set option ", &name, " after connection is created.");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 9, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "arango/connection/connection.zep", 151 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

/**
 * Set an option for the connection
 *
 * @throws \Arango\Exception\ClientException
 * @param string name - name of options
 * @param value
 * @return void
 */
PHP_METHOD(Arango_Connection_Connection, setOption) {

	zend_bool _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *name_param = NULL, *value, value_sub, __$true, __$false, _0, _3, _4$$4, _5$$5;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	zephir_get_strval(&name, name_param);


	ZEPHIR_CALL_SELF(&_0, "validateoption", &_1, 32, &name, value);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		zephir_update_property_array(this_ptr, SL("options"), &name, value TSRMLS_CC);
	}
	_2 = ZEPHIR_IS_STRING(&name, "timeout");
	if (_2) {
		zephir_read_property(&_3, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
		_2 = Z_TYPE_P(&_3) == IS_RESOURCE;
	}
	if (_2) {
		zephir_read_property(&_4$$4, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "stream_set_timeout", NULL, 33, &_4$$4, value);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_STRING(&name, "Connection")) {
		ZEPHIR_INIT_VAR(&_5$$5);
		zephir_fast_strtolower(&_5$$5, value);
		if (ZEPHIR_IS_STRING_IDENTICAL(&_5$$5, "keep-alive")) {
			zephir_update_property_zval(this_ptr, SL("useKeepAlive"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("useKeepAlive"), &__$false);
		}
	}
	if (ZEPHIR_IS_STRING(&name, "database")) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdatabase", NULL, 0, value);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "updatehttpheader", NULL, 31);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Set an active batch
 *
 * @param Batch name - name of options
 * @return void
 */
PHP_METHOD(Arango_Connection_Connection, setActiveBatch) {

	zval *batch, batch_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&batch_sub);

	zephir_fetch_params(0, 1, 0, &batch);



	zephir_update_property_zval(this_ptr, SL("activeBatch"), batch);

}

/**
 * Get an active batch
 *
 * @return Batch | null
 */
PHP_METHOD(Arango_Connection_Connection, getActiveBatch) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "activeBatch");

}

/**
 * Get an option set for the connection
 *
 * @throws \Arango\Exception\ClientException
 * @param string name - name of options
 * @return mixed
 */
PHP_METHOD(Arango_Connection_Connection, getOption) {

	zval *name_param = NULL, _0, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_1, &_0, &name, PH_NOISY | PH_READONLY, "arango/connection/connection.zep", 213 TSRMLS_CC);
	RETURN_CTOR(&_1);

}

/**
 * Get the options set for the connection
 *
 * @return \Arango\Connection\Options | null
 */
PHP_METHOD(Arango_Connection_Connection, getOptions) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "options");

}

/**
 * Set the database name for the connection
 *
 * Further calls to the database will be addressed to the given database
 *
 * @param string name - name of database
 * @return void
 */
PHP_METHOD(Arango_Connection_Connection, setDatabase) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *database_param = NULL, _0, _1;
	zval database;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&database);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &database_param);

	zephir_get_strval(&database, database_param);


	zephir_read_property(&_0, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "database");
	ZEPHIR_CALL_METHOD(NULL, &_0, "offsetset", NULL, 0, &_1, &database);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("database"), &database);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "updatehttpheader", NULL, 31);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Get the database that is currently used with this connection
 *
 * @return string
 */
PHP_METHOD(Arango_Connection_Connection, getDatabase) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "database");

}

/**
 * Recalculate the static HTTP header string used for all HTTP requests in this connection
 *
 * @return void
 */
PHP_METHOD(Arango_Connection_Connection, updateHttpHeader) {

	zend_bool _14;
	zval endpoint, _0, _1, _2, _12, _13, _15, _16, _29, _30, _38, _4$$3, _5$$3, _7$$3, _8$$3, _9$$3, _11$$3, authorization$$4, _17$$4, _18$$4, _19$$4, _20$$4, _21$$4, _22$$4, _23$$4, _24$$4, _25$$4, _26$$4, _27$$4, _28$$4, _31$$5, _32$$5, _33$$5, _34$$5, _35$$5, _36$$5, _37$$5, _39$$6, _40$$6, _41$$6;
	zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&endpoint);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_38);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&authorization$$4);
	ZVAL_UNDEF(&_17$$4);
	ZVAL_UNDEF(&_18$$4);
	ZVAL_UNDEF(&_19$$4);
	ZVAL_UNDEF(&_20$$4);
	ZVAL_UNDEF(&_21$$4);
	ZVAL_UNDEF(&_22$$4);
	ZVAL_UNDEF(&_23$$4);
	ZVAL_UNDEF(&_24$$4);
	ZVAL_UNDEF(&_25$$4);
	ZVAL_UNDEF(&_26$$4);
	ZVAL_UNDEF(&_27$$4);
	ZVAL_UNDEF(&_28$$4);
	ZVAL_UNDEF(&_31$$5);
	ZVAL_UNDEF(&_32$$5);
	ZVAL_UNDEF(&_33$$5);
	ZVAL_UNDEF(&_34$$5);
	ZVAL_UNDEF(&_35$$5);
	ZVAL_UNDEF(&_36$$5);
	ZVAL_UNDEF(&_37$$5);
	ZVAL_UNDEF(&_39$$6);
	ZVAL_UNDEF(&_40$$6);
	ZVAL_UNDEF(&_41$$6);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "\r\n");
	zephir_update_property_zval(this_ptr, SL("httpHeader"), &_0);
	zephir_read_property(&_1, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "endpoint");
	ZEPHIR_CALL_METHOD(&endpoint, &_1, "offsetget", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_2, arango_connection_endpoint_ce, "gettype", &_3, 0, &endpoint);
	zephir_check_call_status();
	if (!ZEPHIR_IS_STRING(&_2, "unix")) {
		zephir_read_property(&_4$$3, this_ptr, SL("httpHeader"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_CE_STATIC(&_5$$3, arango_connection_endpoint_ce, "gethost", &_6, 0, &endpoint);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "Host: %s%s");
		ZEPHIR_INIT_VAR(&_8$$3);
		ZVAL_STRING(&_8$$3, "\r\n");
		ZEPHIR_CALL_FUNCTION(&_9$$3, "sprintf", &_10, 34, &_7$$3, &_5$$3, &_8$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_11$$3);
		ZEPHIR_CONCAT_VV(&_11$$3, &_4$$3, &_9$$3);
		zephir_update_property_zval(this_ptr, SL("httpHeader"), &_11$$3);
	}
	zephir_read_property(&_12, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "AuthType");
	ZEPHIR_CALL_METHOD(&_13, &_12, "offsetexists", NULL, 0, &_0);
	zephir_check_call_status();
	_14 = zephir_is_true(&_13);
	if (_14) {
		zephir_read_property(&_15, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "AuthUser");
		ZEPHIR_CALL_METHOD(&_16, &_15, "offsetexists", NULL, 0, &_0);
		zephir_check_call_status();
		_14 = zephir_is_true(&_16);
	}
	if (_14) {
		zephir_read_property(&_17$$4, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_19$$4);
		ZVAL_STRING(&_19$$4, "AuthUser");
		ZEPHIR_CALL_METHOD(&_18$$4, &_17$$4, "offsetget", NULL, 0, &_19$$4);
		zephir_check_call_status();
		zephir_read_property(&_20$$4, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_19$$4);
		ZVAL_STRING(&_19$$4, "AuthPasswd");
		ZEPHIR_CALL_METHOD(&_21$$4, &_20$$4, "offsetget", NULL, 0, &_19$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_22$$4);
		ZEPHIR_CONCAT_VSV(&_22$$4, &_18$$4, ":", &_21$$4);
		ZEPHIR_CALL_FUNCTION(&authorization$$4, "base64_encode", NULL, 35, &_22$$4);
		zephir_check_call_status();
		zephir_read_property(&_23$$4, this_ptr, SL("httpHeader"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_24$$4, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_19$$4);
		ZVAL_STRING(&_19$$4, "AuthType");
		ZEPHIR_CALL_METHOD(&_25$$4, &_24$$4, "offsetget", NULL, 0, &_19$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_19$$4);
		ZVAL_STRING(&_19$$4, "Authorization: %s %s%s");
		ZEPHIR_INIT_VAR(&_26$$4);
		ZVAL_STRING(&_26$$4, "\r\n");
		ZEPHIR_CALL_FUNCTION(&_27$$4, "sprintf", &_10, 34, &_19$$4, &_25$$4, &authorization$$4, &_26$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_28$$4);
		ZEPHIR_CONCAT_VV(&_28$$4, &_23$$4, &_27$$4);
		zephir_update_property_zval(this_ptr, SL("httpHeader"), &_28$$4);
	}
	zephir_read_property(&_29, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Connection");
	ZEPHIR_CALL_METHOD(&_30, &_29, "offsetexists", NULL, 0, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_30)) {
		zephir_read_property(&_31$$5, this_ptr, SL("httpHeader"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_32$$5, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_34$$5);
		ZVAL_STRING(&_34$$5, "Connection");
		ZEPHIR_CALL_METHOD(&_33$$5, &_32$$5, "offsetget", NULL, 0, &_34$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_34$$5);
		ZVAL_STRING(&_34$$5, "Connection: %s%s");
		ZEPHIR_INIT_VAR(&_35$$5);
		ZVAL_STRING(&_35$$5, "\r\n");
		ZEPHIR_CALL_FUNCTION(&_36$$5, "sprintf", &_10, 34, &_34$$5, &_33$$5, &_35$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_37$$5);
		ZEPHIR_CONCAT_VV(&_37$$5, &_31$$5, &_36$$5);
		zephir_update_property_zval(this_ptr, SL("httpHeader"), &_37$$5);
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/_db/_system");
	zephir_update_property_zval(this_ptr, SL("baseUrl"), &_0);
	zephir_read_property(&_38, this_ptr, SL("database"), PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_STRING(&_38, "")) {
		zephir_read_property(&_39$$6, this_ptr, SL("database"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_40$$6, "urlencode", NULL, 36, &_39$$6);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_41$$6);
		ZEPHIR_CONCAT_SV(&_41$$6, "/_db/", &_40$$6);
		zephir_update_property_zval(this_ptr, SL("baseUrl"), &_41$$6);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Get a connection handle
 *
 * If keep-alive connections are used, the handle will be stored and re-used
 *
 * @throws \Arango\Exception\ConnectionException | \Arango\Exception\ClientException
 * @return resource - connection handler
 */
PHP_METHOD(Arango_Connection_Connection, getHandle) {

	zend_bool _1, _3, _11;
	zval handle, _0, _2, _4, _9, _10, _5$$3, _6$$3, _7$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_8 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handle);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("useKeepAlive"), PH_NOISY_CC | PH_READONLY);
	_1 = zephir_is_true(&_0);
	if (_1) {
		zephir_read_property(&_2, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
		_1 = zephir_is_true(&_2);
	}
	_3 = _1;
	if (_3) {
		zephir_read_property(&_4, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
		_3 = Z_TYPE_P(&_4) == IS_RESOURCE;
	}
	if (_3) {
		zephir_read_property(&_5$$3, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&handle, &_5$$3);
		if (!(zephir_feof(&handle TSRMLS_CC))) {
			RETURN_CCTOR(&handle);
		}
		zephir_read_property(&_5$$3, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
		zephir_fclose(&_5$$3 TSRMLS_CC);
		ZEPHIR_INIT_ZVAL_NREF(_6$$3);
		ZVAL_LONG(&_6$$3, 0);
		zephir_update_property_zval(this_ptr, SL("handle"), &_6$$3);
		zephir_read_property(&_6$$3, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_7$$3, &_6$$3, SL("Reconnect"), PH_NOISY | PH_READONLY, "arango/connection/connection.zep", 320 TSRMLS_CC);
		if (!zephir_is_true(&_7$$3)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(arango_exception_clientexception_ce, "Server has closed connection already", "arango/connection/connection.zep", 321);
			return;
		}
	}
	zephir_read_property(&_9, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_CE_STATIC(&handle, arango_http_client_ce, "createconnection", &_8, 0, &_9);
	zephir_check_call_status();
	zephir_read_property(&_10, this_ptr, SL("useKeepAlive"), PH_NOISY_CC | PH_READONLY);
	_11 = zephir_is_true(&_10);
	if (_11) {
		_11 = Z_TYPE_P(&handle) == IS_RESOURCE;
	}
	if (_11) {
		zephir_update_property_zval(this_ptr, SL("handle"), &handle);
	}
	RETURN_CCTOR(&handle);

}

/**
 * Execute an HTTP request and return the results
 *
 * This function will throw if no connection to the server can be established or if
 * there is a problem during data exchange with the server.
 *
 * @throws \Exception
 *
 * @param string method       - HTTP request method
 * @param string url          - HTTP url
 * @param string data         - HTTP request data
 * @param array customHeaders - Any custom headers for the request
 *
 * @return Response
 */
PHP_METHOD(Arango_Connection_Connection, executeRequest) {

	zend_bool wasAsync;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_7 = NULL, *_23 = NULL, *_24 = NULL, *_28 = NULL;
	zval customHeaders;
	zval *method_param = NULL, *url_param = NULL, *data_param = NULL, *customHeaders_param = NULL, __$true, __$false, request, handle, response, _0, _2, traceFunc, _20, _3$$5, _13$$5, _4$$6, _5$$6, _6$$6, _8$$6, _9$$6, _10$$6, _11$$7, _12$$7, batchPart$$8, _14$$10, _15$$10, _16$$10, _17$$10, _18$$10, _19$$10, _21$$11, _22$$11, header$$12, headers$$12, _25$$12, _26$$12, _27$$13, startTime$$14, timeTaken$$14, status$$14, result$$14, _30$$14, _34$$14, _35$$14, _29$$16, _31$$17, _32$$17, _33$$17, _36$$19, _37$$19, _38$$20, _39$$20, _40$$20, _41$$20, _42$$21;
	zval method, url, data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&data);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&request);
	ZVAL_UNDEF(&handle);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&traceFunc);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&batchPart$$8);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_21$$11);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&header$$12);
	ZVAL_UNDEF(&headers$$12);
	ZVAL_UNDEF(&_25$$12);
	ZVAL_UNDEF(&_26$$12);
	ZVAL_UNDEF(&_27$$13);
	ZVAL_UNDEF(&startTime$$14);
	ZVAL_UNDEF(&timeTaken$$14);
	ZVAL_UNDEF(&status$$14);
	ZVAL_UNDEF(&result$$14);
	ZVAL_UNDEF(&_30$$14);
	ZVAL_UNDEF(&_34$$14);
	ZVAL_UNDEF(&_35$$14);
	ZVAL_UNDEF(&_29$$16);
	ZVAL_UNDEF(&_31$$17);
	ZVAL_UNDEF(&_32$$17);
	ZVAL_UNDEF(&_33$$17);
	ZVAL_UNDEF(&_36$$19);
	ZVAL_UNDEF(&_37$$19);
	ZVAL_UNDEF(&_38$$20);
	ZVAL_UNDEF(&_39$$20);
	ZVAL_UNDEF(&_40$$20);
	ZVAL_UNDEF(&_41$$20);
	ZVAL_UNDEF(&_42$$21);
	ZVAL_UNDEF(&customHeaders);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &method_param, &url_param, &data_param, &customHeaders_param);

	zephir_get_strval(&method, method_param);
	zephir_get_strval(&url, url_param);
	zephir_get_strval(&data, data_param);
	zephir_get_arrval(&customHeaders, customHeaders_param);


	wasAsync = 0;
	zephir_read_property(&_0, this_ptr, SL("httpHeader"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_STRING(&_0, "")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Invalid HTTP header", "arango/connection/connection.zep", 354);
		return;
	}
	if (zephir_array_isset_string(&customHeaders, SL("X-Arango-Async"))) {
		wasAsync = 1;
	}
	ZEPHIR_CALL_CE_STATIC(NULL, arango_http_client_ce, "validatemethod", &_1, 0, &method);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, SL("batchRequest"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_FALSE(&_2)) {
		zephir_read_property(&_3$$5, this_ptr, SL("captureBatch"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_TRUE(&_3$$5)) {
			zephir_read_property(&_4$$6, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_5$$6);
			ZVAL_STRING(&_5$$6, "BatchPart");
			ZVAL_BOOL(&_6$$6, 1);
			ZEPHIR_CALL_METHOD(NULL, &_4$$6, "offsetset", NULL, 0, &_5$$6, &_6$$6);
			zephir_check_call_status();
			zephir_read_property(&_6$$6, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_8$$6, this_ptr, SL("httpHeader"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_CE_STATIC(&request, arango_http_client_ce, "buildrequest", &_7, 0, &_6$$6, &_8$$6, &method, &url, &data, &customHeaders);
			zephir_check_call_status();
			zephir_read_property(&_9$$6, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_NVAR(&_5$$6);
			ZVAL_STRING(&_5$$6, "BatchPart");
			ZVAL_BOOL(&_10$$6, 0);
			ZEPHIR_CALL_METHOD(NULL, &_9$$6, "offsetset", NULL, 0, &_5$$6, &_10$$6);
			zephir_check_call_status();
		} else {
			zephir_read_property(&_11$$7, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_12$$7, this_ptr, SL("httpHeader"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_CE_STATIC(&request, arango_http_client_ce, "buildrequest", &_7, 0, &_11$$7, &_12$$7, &method, &url, &data, &customHeaders);
			zephir_check_call_status();
		}
		zephir_read_property(&_13$$5, this_ptr, SL("captureBatch"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_TRUE(&_13$$5)) {
			ZEPHIR_CALL_METHOD(&batchPart$$8, this_ptr, "dobatch", NULL, 37, &method, &request);
			zephir_check_call_status();
			if (!(Z_TYPE_P(&batchPart$$8) == IS_NULL)) {
				RETURN_CCTOR(&batchPart$$8);
			}
		}
	} else {
		if (0) {
			zephir_update_property_zval(this_ptr, SL("batchRequest"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("batchRequest"), &__$false);
		}
		zephir_read_property(&_14$$10, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_15$$10);
		ZVAL_STRING(&_15$$10, "BatchPart");
		ZVAL_BOOL(&_16$$10, 1);
		ZEPHIR_CALL_METHOD(NULL, &_14$$10, "offsetset", NULL, 0, &_15$$10, &_16$$10);
		zephir_check_call_status();
		zephir_read_property(&_16$$10, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_17$$10, this_ptr, SL("httpHeader"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_CE_STATIC(&request, arango_http_client_ce, "buildrequest", &_7, 0, &_16$$10, &_17$$10, &method, &url, &data, &customHeaders);
		zephir_check_call_status();
		zephir_read_property(&_18$$10, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_15$$10);
		ZVAL_STRING(&_15$$10, "BatchPart");
		ZVAL_BOOL(&_19$$10, 0);
		ZEPHIR_CALL_METHOD(NULL, &_18$$10, "offsetset", NULL, 0, &_15$$10, &_19$$10);
		zephir_check_call_status();
	}
	zephir_read_property(&_20, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&traceFunc);
	zephir_array_fetch_string(&traceFunc, &_20, SL("trace"), PH_NOISY, "arango/connection/connection.zep", 392 TSRMLS_CC);
	if (zephir_is_true(&traceFunc)) {
		zephir_read_property(&_21$$11, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_22$$11, &_21$$11, SL("enhancedTrace"), PH_NOISY | PH_READONLY, "arango/connection/connection.zep", 395 TSRMLS_CC);
		if (zephir_is_true(&_22$$11)) {
			ZEPHIR_CALL_CE_STATIC(&header$$12, arango_http_client_ce, "parsehttpmessage", &_23, 0, &request, &url, &method);
			zephir_check_call_status();
			ZEPHIR_CALL_CE_STATIC(&headers$$12, arango_http_client_ce, "parsehttpheaders", &_24, 0, &header$$12);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_25$$12);
			object_init_ex(&_25$$12, arango_connection_tracerequest_ce);
			zephir_array_fetch_long(&_26$$12, &headers$$12, 2, PH_NOISY | PH_READONLY, "arango/connection/connection.zep", 400 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, &_25$$12, "__construct", NULL, 38, &_26$$12, &method, &url, &data);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(NULL, "tracefunc", NULL, 0, &_25$$12);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_27$$13);
			ZVAL_STRING(&_27$$13, "send");
			ZEPHIR_CALL_FUNCTION(NULL, "tracefunc", NULL, 0, &_27$$13, &request);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_METHOD(&handle, this_ptr, "gethandle", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&handle)) {
		if (zephir_is_true(&traceFunc)) {
			ZEPHIR_INIT_VAR(&startTime$$14);
			zephir_microtime(&startTime$$14, &__$true TSRMLS_CC);
		}
		ZEPHIR_CALL_CE_STATIC(&result$$14, arango_http_client_ce, "transfer", &_28, 0, &handle, &request, &method);
		zephir_check_call_status();
		if (zephir_is_true(&traceFunc)) {
			ZEPHIR_INIT_VAR(&_29$$16);
			zephir_microtime(&_29$$16, &__$true TSRMLS_CC);
			ZEPHIR_INIT_VAR(&timeTaken$$14);
			zephir_sub_function(&timeTaken$$14, &_29$$16, &startTime$$14);
		}
		ZEPHIR_CALL_FUNCTION(&status$$14, "socket_get_status", NULL, 39, &handle);
		zephir_check_call_status();
		zephir_array_fetch_string(&_30$$14, &status$$14, SL("timed_out"), PH_NOISY | PH_READONLY, "arango/connection/connection.zep", 424 TSRMLS_CC);
		if (zephir_is_true(&_30$$14)) {
			ZEPHIR_INIT_VAR(&_31$$17);
			object_init_ex(&_31$$17, arango_exception_clientexception_ce);
			ZEPHIR_INIT_VAR(&_32$$17);
			ZVAL_STRING(&_32$$17, "Got a timeout while waiting for the server\\'s response");
			ZVAL_LONG(&_33$$17, 408);
			ZEPHIR_CALL_METHOD(NULL, &_31$$17, "__construct", NULL, 9, &_32$$17, &_33$$17);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_31$$17, "arango/connection/connection.zep", 425 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property(&_34$$14, this_ptr, SL("useKeepAlive"), PH_NOISY_CC | PH_READONLY);
		if (!zephir_is_true(&_34$$14)) {
			zephir_fclose(&handle TSRMLS_CC);
		}
		ZEPHIR_INIT_VAR(&response);
		object_init_ex(&response, arango_http_response_ce);
		if (wasAsync) {
			ZVAL_BOOL(&_35$$14, 1);
		} else {
			ZVAL_BOOL(&_35$$14, 0);
		}
		ZEPHIR_CALL_METHOD(NULL, &response, "__construct", NULL, 13, &result$$14, &url, &method, &_35$$14);
		zephir_check_call_status();
		if (zephir_is_true(&traceFunc)) {
			zephir_read_property(&_36$$19, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch_string(&_37$$19, &_36$$19, SL("enhancedTrace"), PH_NOISY | PH_READONLY, "arango/connection/connection.zep", 436 TSRMLS_CC);
			if (zephir_is_true(&_37$$19)) {
				ZEPHIR_INIT_VAR(&_38$$20);
				object_init_ex(&_38$$20, arango_connection_traceresponse_ce);
				ZEPHIR_CALL_METHOD(&_39$$20, &response, "getheaders", NULL, 40);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_40$$20, &response, "getcode", NULL, 41);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_41$$20, &response, "getbody", NULL, 17);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_38$$20, "__construct", NULL, 42, &_39$$20, &_40$$20, &_41$$20, &timeTaken$$14);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(NULL, "tracefunc", NULL, 0, &_38$$20);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_VAR(&_42$$21);
				ZVAL_STRING(&_42$$21, "receive");
				ZEPHIR_CALL_FUNCTION(NULL, "tracefunc", NULL, 0, &_42$$21, &result$$14);
				zephir_check_call_status();
			}
		}
		RETURN_CCTOR(&response);
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(arango_exception_clientexception_ce, "Whoops, this should never happen", "arango/connection/connection.zep", 451);
	return;

}

/**
 * This is a helper function to executeRequest that captures requests if we're in batch mode
 *
 * @throws \Arango\Exception\ClientException
 *
 * @param string method - The method request
 * @param string request - The request to proccess
 *
 * This checks if we're in batch mode and returns a placeholder object,
 * since we need to return some object that is expected by the caller.
 * if we're not in batch mode it does not return anything.
 *
 * @return BatchPart | null
 */
PHP_METHOD(Arango_Connection_Connection, doBatch) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, *request_param = NULL, batchPart, _0, batch$$3;
	zval method, request;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&request);
	ZVAL_UNDEF(&batchPart);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&batch$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &request_param);

	zephir_get_strval(&method, method_param);
	zephir_get_strval(&request, request_param);


	ZEPHIR_INIT_VAR(&batchPart);
	ZVAL_NULL(&batchPart);
	zephir_read_property(&_0, this_ptr, SL("captureBatch"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(&batch$$3, this_ptr, "getactivebatch", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&batchPart, &batch$$3, "append", NULL, 0, &method, &request);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&batchPart);

}

/**
 * Returns true if this connection is in Batch-Capture mode
 *
 * @return boolean
 */
PHP_METHOD(Arango_Connection_Connection, isInBatchCaptureMode) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "captureBatch");

}

/**
 * Stop capturing commands
 *
 * @return void
 */
PHP_METHOD(Arango_Connection_Connection, stopCaptureBatch) {

	zval __$true, __$false;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);


	if (0) {
		zephir_update_property_zval(this_ptr, SL("captureBatch"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("captureBatch"), &__$false);
	}

}

/**
 * Sets the batch capture state (true, if capturing)
 *
 * @param boolean state True to turn on capture batch mode, false to turn off
 *
 * @return void
 */
PHP_METHOD(Arango_Connection_Connection, setCaptureBatch) {

	zval *state_param = NULL, __$true, __$false;
	zend_bool state;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &state_param);

	state = zephir_get_boolval(state_param);


	if (state) {
		zephir_update_property_zval(this_ptr, SL("captureBatch"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("captureBatch"), &__$false);
	}

}

