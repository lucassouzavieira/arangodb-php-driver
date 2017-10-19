
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
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


/**
 * Thrown by client when there is error on server side
 *
 * @package Arango/Exception
 * @class ServerException
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Exception_ServerException) {

	ZEPHIR_REGISTER_CLASS_EX(Arango\\Exception, ServerException, arango, exception_serverexception, arango_exception_exception_ce, arango_exception_serverexception_method_entry, 0);

	/**
	 * Optional details for the exception
	 *
	 * @var array
	 */
	zend_declare_property_null(arango_exception_serverexception_ce, SL("details"), ZEND_ACC_PRIVATE TSRMLS_CC);

	arango_exception_serverexception_ce->create_object = zephir_init_properties_Arango_Exception_ServerException;
	/**
	 * Server exception indexes
	 */
	zephir_declare_class_constant_string(arango_exception_serverexception_ce, SL("ENTRY_CODE"), "errorNum");

	zephir_declare_class_constant_string(arango_exception_serverexception_ce, SL("ENTRY_MESSAGE"), "errorMessage");

	return SUCCESS;

}

/**
 * Optional details for the exception
 */
PHP_METHOD(Arango_Exception_ServerException, getDetails) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "details");

}

/**
 * Optional details for the exception
 */
PHP_METHOD(Arango_Exception_ServerException, setDetails) {

	zval *details_param = NULL;
	zval details;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&details);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &details_param);

	zephir_get_arrval(&details, details_param);


	zephir_update_property_zval(this_ptr, SL("details"), &details);
	RETURN_THIS();

}

/**
 * Class where ServerException was thrown with Exception message.
 *
 * @return string
 */
PHP_METHOD(Arango_Exception_ServerException, __toString) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getservercode", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getmessage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SSVSV(return_value, "Arango\\Exception\\ServerException", ": ", &_0, " ", &_1);
	RETURN_MM();

}

/**
 * Get server error code
 * If the server has provided additional details about the error
 * that occurred, this will return the server error code
 *
 * @return int
 */
PHP_METHOD(Arango_Exception_ServerException, getServerCode) {

	zval _0, _1$$3, _2$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("details"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string(&_0, SL("errorNum"))) {
		zephir_read_property(&_1$$3, this_ptr, SL("details"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_2$$3, &_1$$3, SL("errorNum"), PH_NOISY | PH_READONLY, "arango/exception/serverexception.zep", 50 TSRMLS_CC);
		RETURN_CTOR(&_2$$3);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getcode", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get server error message
 * If the server has provided additional details about the error
 * that occurred, this will return the server error string
 *
 * @return string
 */
PHP_METHOD(Arango_Exception_ServerException, getServerMessage) {

	zval _0, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);


	zephir_read_property(&_0, this_ptr, SL("details"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string(&_0, SL("errorMessage"))) {
		zephir_read_property(&_1$$3, this_ptr, SL("details"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_2$$3, &_1$$3, SL("errorMessage"), PH_NOISY | PH_READONLY, "arango/exception/serverexception.zep", 65 TSRMLS_CC);
		RETURN_CTORW(&_2$$3);
	}
	RETURN_STRING("");

}

zend_object *zephir_init_properties_Arango_Exception_ServerException(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("details"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("details"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

