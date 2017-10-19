
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
 * Value object representing a single vertex document
 *
 * @package Arango/Document
 * @class Vertex
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Document_Vertex) {

	ZEPHIR_REGISTER_CLASS_EX(Arango\\Document, Vertex, arango, document_vertex, arango_document_document_ce, NULL, 0);

	return SUCCESS;

}

