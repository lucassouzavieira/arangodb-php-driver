
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
 * Provides access to the results of a collection export
 * The cursor might not contain all results in the beginning. <br>
 *
 * If the result set is too big to be transferred in one go, the
 * cursor might issue additional HTTP requests to fetch the
 * remaining results from the server. <br>
 *
 * @package Arango/Cursor
 * @class ExportCursor
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Cursor_ExportCursor) {

	ZEPHIR_REGISTER_CLASS(Arango\\Cursor, ExportCursor, arango, cursor_exportcursor, NULL, 0);

	return SUCCESS;

}

