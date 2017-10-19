
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
 * A handler that manages edges
 * TODO all
 * @package Arango/Handler
 * @class EdgeHandler
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Handler_EdgeHandler) {

	ZEPHIR_REGISTER_CLASS_EX(Arango\\Handler, EdgeHandler, arango, handler_edgehandler, arango_handler_documenthandler_ce, NULL, 0);

	/**
	 * Class indexes
	 */
	zephir_declare_class_constant_string(arango_handler_edgehandler_ce, SL("ENTRY_EDGES"), "edges");

	return SUCCESS;

}

