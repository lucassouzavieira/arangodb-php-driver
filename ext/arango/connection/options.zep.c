
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
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


/**
 * Container to manage connection options
 *
 * @package Arango/Connection
 * @class Options
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Connection_Options) {

	ZEPHIR_REGISTER_CLASS(Arango\\Connection, Options, arango, connection_options, arango_connection_options_method_entry, 0);

	/**
	 * The current options
	 *
	 * @var array
	 */
	zend_declare_property_null(arango_connection_options_ce, SL("values"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * The current options
	 *
	 * @var string
	 */
	zend_declare_property_null(arango_connection_options_ce, SL("endpoint"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Endpoint string index constant
	 */
	zephir_declare_class_constant_string(arango_connection_options_ce, SL("ENDPOINT"), "endpoint");

	/**
	 * Host name string index constant (deprecated, use endpoint instead)
	 */
	zephir_declare_class_constant_string(arango_connection_options_ce, SL("HOST"), "host");

	/**
	 * Port number index constant (deprecated, use endpoint instead)
	 */
	zephir_declare_class_constant_string(arango_connection_options_ce, SL("PORT"), "port");

	/**
	 * Timeout value index constant
	 */
	zephir_declare_class_constant_string(arango_connection_options_ce, SL("TIMEOUT"), "timeout");

	/**
	 * Trace function index constant
	 */
	zephir_declare_class_constant_string(arango_connection_options_ce, SL("TRACE"), "trace");

	/**
	 * "verify certificates" index constant
	 */
	zephir_declare_class_constant_string(arango_connection_options_ce, SL("VERIFY_CERT"), "verifyCert");

	/**
	 * "allow self-signed" index constant
	 */
	zephir_declare_class_constant_string(arango_connection_options_ce, SL("ALLOW_SELF_SIGNED"), "allowSelfSigned");

	/**
	 * ciphers allowed to be used in SSL
	 */
	zephir_declare_class_constant_string(arango_connection_options_ce, SL("CIPHERS"), "ciphers");

	/**
	 * Enhanced trace
	 */
	zephir_declare_class_constant_string(arango_connection_options_ce, SL("ENHANCED_TRACE"), "enhancedTrace");

	/**
	 * "Create collections if they don't exist" index constant
	 */
	zephir_declare_class_constant_string(arango_connection_options_ce, SL("CREATE"), "createCollection");

	/**
	 * Update revision constant
	 */
	zephir_declare_class_constant_string(arango_connection_options_ce, SL("REVISION"), "rev");

	/**
	 * Update policy index constant
	 */
	zephir_declare_class_constant_string(arango_connection_options_ce, SL("UPDATE_POLICY"), "policy");

	/**
	 * Update keepNull constant
	 */
	zephir_declare_class_constant_string(arango_connection_options_ce, SL("UPDATE_KEEPNULL"), "keepNull");

	/**
	 * Replace policy index constant
	 */
	zephir_declare_class_constant_string(arango_connection_options_ce, SL("REPLACE_POLICY"), "policy");

	/**
	 * Delete policy index constant
	 */
	zephir_declare_class_constant_string(arango_connection_options_ce, SL("DELETE_POLICY"), "policy");

	/**
	 * Wait for sync index constant
	 */
	zephir_declare_class_constant_string(arango_connection_options_ce, SL("WAIT_SYNC"), "waitForSync");

	/**
	 * Limit index constant
	 */
	zephir_declare_class_constant_string(arango_connection_options_ce, SL("LIMIT"), "limit");

	/**
	 * Skip index constant
	 */
	zephir_declare_class_constant_string(arango_connection_options_ce, SL("SKIP"), "skip");

	/**
	 * Batch size index constant
	 */
	zephir_declare_class_constant_string(arango_connection_options_ce, SL("BATCHSIZE"), "batchSize");

	/**
	 * Journal size index constant
	 */
	zephir_declare_class_constant_string(arango_connection_options_ce, SL("JOURNAL_SIZE"), "journalSize");

	/**
	 * Is system index constant
	 */
	zephir_declare_class_constant_string(arango_connection_options_ce, SL("IS_SYSTEM"), "isSystem");

	/**
	 * Is volatile index constant
	 */
	zephir_declare_class_constant_string(arango_connection_options_ce, SL("IS_VOLATILE"), "isVolatile");

	/**
	 * Authentication user name
	 */
	zephir_declare_class_constant_string(arango_connection_options_ce, SL("AUTH_USER"), "AuthUser");

	/**
	 * Authentication password
	 */
	zephir_declare_class_constant_string(arango_connection_options_ce, SL("AUTH_PASSWD"), "AuthPasswd");

	/**
	 * Authentication type
	 */
	zephir_declare_class_constant_string(arango_connection_options_ce, SL("AUTH_TYPE"), "AuthType");

	/**
	 * Connection
	 */
	zephir_declare_class_constant_string(arango_connection_options_ce, SL("CONNECTION"), "Connection");

	/**
	 * Reconnect flag
	 */
	zephir_declare_class_constant_string(arango_connection_options_ce, SL("RECONNECT"), "Reconnect");

	/**
	 * Batch flag
	 */
	zephir_declare_class_constant_string(arango_connection_options_ce, SL("BATCH"), "Batch");

	/**
	 * Batchpart flag
	 */
	zephir_declare_class_constant_string(arango_connection_options_ce, SL("BATCHPART"), "BatchPart");

	/**
	 * Database flag
	 */
	zephir_declare_class_constant_string(arango_connection_options_ce, SL("DATABASE"), "database");

	/**
	 * UTF-8 CHeck Flag
	 */
	zephir_declare_class_constant_string(arango_connection_options_ce, SL("CHECK_UTF8_CONFORM"), "CheckUtf8Conform");

	zend_class_implements(arango_connection_options_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	return SUCCESS;

}

/**
 * The current options
 */
PHP_METHOD(Arango_Connection_Options, getEndpoint) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "endpoint");

}

/**
 * The current options
 */
PHP_METHOD(Arango_Connection_Options, setEndpoint) {

	zval *endpoint_param = NULL;
	zval endpoint;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&endpoint);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &endpoint_param);

	zephir_get_strval(&endpoint, endpoint_param);


	zephir_update_property_zval(this_ptr, SL("endpoint"), &endpoint);
	RETURN_THIS();

}

/**
 * Set defaults, use options provided by client and validate them
 *
 * @param array $options - initial options
 *
 * @throws Arango\Exception\ClientException
 */
PHP_METHOD(Arango_Connection_Options, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, _0, _1, _2, _3;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	zephir_get_arrval(&options, options_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CALL_SELF(&_1, "getdefaults", NULL, 0);
	zephir_check_call_status();
	zephir_fast_array_merge(&_0, &_1, &options TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("values"), &_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "validate", NULL, 45);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_3, &_2, SL("endpoint"), PH_NOISY | PH_READONLY, "arango/connection/options.zep", 199 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("endpoint"), &_3);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get the default values for the options
 *
 * @return array
 */
PHP_METHOD(Arango_Connection_Options, getDefaults) {

	zval __$null, __$false, __$true;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);


	zephir_create_array(return_value, 28, 0 TSRMLS_CC);
	zephir_array_update_string(return_value, SL("endpoint"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("host"), &__$null, PH_COPY | PH_SEPARATE);
	add_assoc_long_ex(return_value, SL("port"), 8529);
	add_assoc_long_ex(return_value, SL("timeout"), 30);
	zephir_array_update_string(return_value, SL("createCollection"), &__$false, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(return_value, SL("policy"), SL("error"));
	add_assoc_stringl_ex(return_value, SL("policy"), SL("error"));
	add_assoc_stringl_ex(return_value, SL("policy"), SL("error"));
	zephir_array_update_string(return_value, SL("rev"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("waitForSync"), &__$false, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("batchSize"), &__$null, PH_COPY | PH_SEPARATE);
	add_assoc_long_ex(return_value, SL("journalSize"), 33554432);
	zephir_array_update_string(return_value, SL("isSystem"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("isVolatile"), &__$false, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(return_value, SL("Connection"), SL("Keep-Alive"));
	zephir_array_update_string(return_value, SL("trace"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("enhancedTrace"), &__$false, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("verifyCert"), &__$false, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("allowSelfSigned"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("ciphers"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("AuthUser"), &__$null, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(return_value, SL("AuthType"), SL("Basic"));
	zephir_array_update_string(return_value, SL("AuthPasswd"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("Reconnect"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("Batch"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("BatchPart"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("database"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("CheckUtf8Conform"), &__$false, PH_COPY | PH_SEPARATE);
	return;

}

/**
 * Return the supported auth types
 *
 * @return array
 */
PHP_METHOD(Arango_Connection_Options, getSupportedAuthTypes) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_create_array(return_value, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Basic");
	zephir_array_fast_append(return_value, &_0);
	RETURN_MM();

}

/**
 * Return the supported connection types
 *
 * @return array
 */
PHP_METHOD(Arango_Connection_Options, getSupportedConnectionsTypes) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Close");
	zephir_array_fast_append(return_value, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Keep-Alive");
	zephir_array_fast_append(return_value, &_0);
	RETURN_MM();

}

/**
 * Check if an option exists
 *
 * @param string offset
 * @return boolean
 */
PHP_METHOD(Arango_Connection_Options, offsetExists) {

	zval *offset_param = NULL, _0;
	zval offset;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset_param);

	zephir_get_strval(&offset, offset_param);


	zephir_read_property(&_0, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &offset));

}

/**
 * Get an specific option
 *
 * @throws \Arango\Exception\ClientException
 * @param string offset
 * @return mixed
 */
PHP_METHOD(Arango_Connection_Options, offsetGet) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *offset_param = NULL, _0, _3, _4, _1$$3;
	zval offset, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset_param);

	zephir_get_strval(&offset, offset_param);


	zephir_read_property(&_0, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_key_exists(&_0, &offset TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, arango_exception_clientexception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "Invalid option: ", &offset);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 9, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "arango/connection/options.zep", 277 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_3, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_4, &_3, &offset, PH_NOISY | PH_READONLY, "arango/connection/options.zep", 280 TSRMLS_CC);
	RETURN_CTOR(&_4);

}

/**
 * Set and validate a specific option
 *
 * @throws \Exception
 * @param string offset - Name of option
 * @param mixed value - Value for option
 */
PHP_METHOD(Arango_Connection_Options, offsetSet) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *offset_param = NULL, *value, value_sub;
	zval offset;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &offset_param, &value);

	zephir_get_strval(&offset, offset_param);


	zephir_update_property_array(this_ptr, SL("values"), &offset, value TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "validate", NULL, 45);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Remove an option and validate
 *
 * @throws \Exception
 * @param string offset - Name of option
 */
PHP_METHOD(Arango_Connection_Options, offsetUnset) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *offset_param = NULL, _0;
	zval offset;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset_param);

	zephir_get_strval(&offset, offset_param);


	zephir_read_property(&_0, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_0, &offset, PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "validate", NULL, 45);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Validate the options
 *
 * @throws \Arango\Exception\ClientException
 * @return void
 */
PHP_METHOD(Arango_Connection_Options, validate) {

	zend_bool _2, _7, _12, _17, _30, _34, _40;
	zval _0, _1, _3, _4, _5, _6, _8, _9, _10, _11, _13, _14, _15, _16, _18, _19, type, _28, _29, _33, _35, _36, _37, _39, _41, _42, _43, _46, _47, _48, _49, _50, _51, _20$$6, _21$$6, _22$$6, _23$$6, _24$$6, _25$$6, _26$$6, _31$$7, _32$$7;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_27 = NULL, *_38 = NULL, *_44 = NULL, *_45 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_36);
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&_39);
	ZVAL_UNDEF(&_41);
	ZVAL_UNDEF(&_42);
	ZVAL_UNDEF(&_43);
	ZVAL_UNDEF(&_46);
	ZVAL_UNDEF(&_47);
	ZVAL_UNDEF(&_48);
	ZVAL_UNDEF(&_49);
	ZVAL_UNDEF(&_50);
	ZVAL_UNDEF(&_51);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_21$$6);
	ZVAL_UNDEF(&_22$$6);
	ZVAL_UNDEF(&_23$$6);
	ZVAL_UNDEF(&_24$$6);
	ZVAL_UNDEF(&_25$$6);
	ZVAL_UNDEF(&_26$$6);
	ZVAL_UNDEF(&_31$$7);
	ZVAL_UNDEF(&_32$$7);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("host"), PH_NOISY | PH_READONLY, "arango/connection/options.zep", 313 TSRMLS_CC);
	_2 = !(Z_TYPE_P(&_1) == IS_NULL);
	if (_2) {
		zephir_read_property(&_3, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_4, &_3, SL("host"), PH_NOISY | PH_READONLY, "arango/connection/options.zep", 313 TSRMLS_CC);
		_2 = !(Z_TYPE_P(&_4) == IS_STRING);
	}
	if (_2) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(arango_exception_clientexception_ce, "Host should be a string", "arango/connection/options.zep", 314);
		return;
	}
	zephir_read_property(&_5, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_6, &_5, SL("port"), PH_NOISY | PH_READONLY, "arango/connection/options.zep", 317 TSRMLS_CC);
	_7 = !(Z_TYPE_P(&_6) == IS_NULL);
	if (_7) {
		zephir_read_property(&_8, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_9, &_8, SL("port"), PH_NOISY | PH_READONLY, "arango/connection/options.zep", 317 TSRMLS_CC);
		_7 = !(Z_TYPE_P(&_9) == IS_LONG);
	}
	if (_7) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(arango_exception_clientexception_ce, "Port should be an integer", "arango/connection/options.zep", 318);
		return;
	}
	zephir_read_property(&_10, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_11, &_10, SL("host"), PH_NOISY | PH_READONLY, "arango/connection/options.zep", 321 TSRMLS_CC);
	_12 = !(Z_TYPE_P(&_11) == IS_NULL);
	if (_12) {
		zephir_read_property(&_13, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_14, &_13, SL("endpoint"), PH_NOISY | PH_READONLY, "arango/connection/options.zep", 321 TSRMLS_CC);
		_12 = !(Z_TYPE_P(&_14) == IS_NULL);
	}
	if (_12) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(arango_exception_clientexception_ce, "Must not specify both Host and Endpoint", "arango/connection/options.zep", 322);
		return;
	}
	zephir_read_property(&_15, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_16, &_15, SL("host"), PH_NOISY | PH_READONLY, "arango/connection/options.zep", 325 TSRMLS_CC);
	_17 = !(Z_TYPE_P(&_16) == IS_NULL);
	if (!(_17)) {
		zephir_read_property(&_18, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_19, &_18, SL("endpoint"), PH_NOISY | PH_READONLY, "arango/connection/options.zep", 325 TSRMLS_CC);
		_17 = Z_TYPE_P(&_19) == IS_NULL;
	}
	if (_17) {
		zephir_read_property(&_20$$6, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_21$$6, &_20$$6, SL("host"), PH_NOISY | PH_READONLY, "arango/connection/options.zep", 326 TSRMLS_CC);
		zephir_read_property(&_22$$6, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_23$$6, &_22$$6, SL("port"), PH_NOISY | PH_READONLY, "arango/connection/options.zep", 326 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_24$$6);
		ZEPHIR_CONCAT_SVSV(&_24$$6, "tcp://", &_21$$6, ":", &_23$$6);
		ZEPHIR_INIT_VAR(&_25$$6);
		ZVAL_STRING(&_25$$6, "endpoint");
		zephir_update_property_array(this_ptr, SL("values"), &_25$$6, &_24$$6 TSRMLS_CC);
		zephir_read_property(&_26$$6, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset_string(&_26$$6, SL("host"), PH_SEPARATE);
	}
	zephir_read_property(&_28, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_29, &_28, SL("endpoint"), PH_NOISY | PH_READONLY, "arango/connection/options.zep", 331 TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&type, arango_connection_endpoint_ce, "gettype", &_27, 0, &_29);
	zephir_check_call_status();
	_30 = ZEPHIR_IS_STRING(&type, "unix");
	if (!(_30)) {
		_30 = ZEPHIR_IS_STRING(&type, "ssl");
	}
	if (_30) {
		ZEPHIR_INIT_VAR(&_31$$7);
		ZVAL_STRING(&_31$$7, "port");
		ZEPHIR_INIT_VAR(&_32$$7);
		ZVAL_LONG(&_32$$7, 0);
		zephir_update_property_array(this_ptr, SL("values"), &_31$$7, &_32$$7 TSRMLS_CC);
	}
	zephir_read_property(&_33, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
	_34 = zephir_array_isset_string(&_33, SL("AuthType"));
	if (_34) {
		zephir_read_property(&_35, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_36, &_35, SL("AuthType"), PH_NOISY | PH_READONLY, "arango/connection/options.zep", 338 TSRMLS_CC);
		ZEPHIR_CALL_SELF(&_37, "getsupportedauthtypes", &_38, 46);
		zephir_check_call_status();
		_34 = !(zephir_fast_in_array(&_36, &_37 TSRMLS_CC));
	}
	if (_34) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(arango_exception_clientexception_ce, "Unsupported authorization method", "arango/connection/options.zep", 339);
		return;
	}
	zephir_read_property(&_39, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
	_40 = zephir_array_isset_string(&_39, SL("Connection"));
	if (_40) {
		zephir_read_property(&_41, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_42, &_41, SL("Connection"), PH_NOISY | PH_READONLY, "arango/connection/options.zep", 343 TSRMLS_CC);
		ZEPHIR_CALL_SELF(&_43, "getsupportedconnectionstypes", &_44, 47);
		zephir_check_call_status();
		_40 = !(zephir_fast_in_array(&_42, &_43 TSRMLS_CC));
	}
	if (_40) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(arango_exception_clientexception_ce, "Unsupported connection value", "arango/connection/options.zep", 344);
		return;
	}
	zephir_read_property(&_46, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_47, &_46, SL("policy"), PH_NOISY | PH_READONLY, "arango/connection/options.zep", 347 TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(NULL, arango_policies_updatepolicy_ce, "validate", &_45, 0, &_47);
	zephir_check_call_status();
	zephir_read_property(&_48, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_49, &_48, SL("policy"), PH_NOISY | PH_READONLY, "arango/connection/options.zep", 348 TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(NULL, arango_policies_updatepolicy_ce, "validate", &_45, 0, &_49);
	zephir_check_call_status();
	zephir_read_property(&_50, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_51, &_50, SL("policy"), PH_NOISY | PH_READONLY, "arango/connection/options.zep", 349 TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(NULL, arango_policies_updatepolicy_ce, "validate", &_45, 0, &_51);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

