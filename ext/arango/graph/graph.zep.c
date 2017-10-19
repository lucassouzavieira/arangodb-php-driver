
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
 * Represents a graph
 * TODO all
 * @package Arango/Graph
 * @class Graph
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Graph_Graph) {

	ZEPHIR_REGISTER_CLASS(Arango\\Graph, Graph, arango, graph_graph, NULL, 0);

	return SUCCESS;

}

