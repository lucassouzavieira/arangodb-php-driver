
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


/**
 * Default client configurations
 *
 * @package Arango/Client
 * @abstract
 * @class Configuration
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Client_Configuration) {

	ZEPHIR_REGISTER_CLASS(Arango\\Client, Configuration, arango, client_configuration, NULL, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zephir_declare_class_constant_long(arango_client_configuration_ce, SL("PORT"), 8529);

	zephir_declare_class_constant_long(arango_client_configuration_ce, SL("TIMEOUT"), 30);

	zephir_declare_class_constant_string(arango_client_configuration_ce, SL("AUTH_TYPE"), "Basic");

	zephir_declare_class_constant_bool(arango_client_configuration_ce, SL("WAIT_SYNC"), 0);

	zephir_declare_class_constant_long(arango_client_configuration_ce, SL("JOURNAL_SIZE"), 33554432);

	zephir_declare_class_constant_bool(arango_client_configuration_ce, SL("IS_VOLATILE"), 0);

	zephir_declare_class_constant_bool(arango_client_configuration_ce, SL("CREATE"), 0);

	zephir_declare_class_constant_string(arango_client_configuration_ce, SL("CONNECTION"), "Keep-Alive");

	zephir_declare_class_constant_bool(arango_client_configuration_ce, SL("VERIFY_CERT"), 0);

	zephir_declare_class_constant_bool(arango_client_configuration_ce, SL("ALLOW_SELF_SIGNED"), 1);

	zephir_declare_class_constant_null(arango_client_configuration_ce, SL("CIPHERS"));

	zephir_declare_class_constant_string(arango_client_configuration_ce, SL("UPDATE_POLICY"), "error");

	zephir_declare_class_constant_string(arango_client_configuration_ce, SL("REPLACE_POLICY"), "error");

	zephir_declare_class_constant_string(arango_client_configuration_ce, SL("DELETE_POLICY"), "error");

	zephir_declare_class_constant_bool(arango_client_configuration_ce, SL("CHECK_UTF8_CONFORM"), 0);

	return SUCCESS;

}

