
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
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"


/**
 * Thrown by client when there is error on client side
 *
 * @package Arango/Exception
 * @class ClientException
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Exception_ClientException) {

	ZEPHIR_REGISTER_CLASS_EX(Arango\\Exception, ClientException, arango, exception_clientexception, arango_exception_exception_ce, arango_exception_clientexception_method_entry, 0);

	return SUCCESS;

}

/**
 * Class where ClientException was thrown with Exception message.
 *
 * @return string
 */
PHP_METHOD(Arango_Exception_ClientException, __toString) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmessage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SSV(return_value, "Arango\\Exception\\ClientException", ": ", &_0);
	RETURN_MM();

}

