
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
 * Container for AQL queries
 * TODO all
 * @package Arango/Query
 * @class Statement
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Query_Statement) {

	ZEPHIR_REGISTER_CLASS(Arango\\Query, Statement, arango, query_statement, NULL, 0);

	return SUCCESS;

}

