
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


/**
 * A handler that manages vertex documents
 *
 * @package Arango/Handler
 * @class VertexHandler
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Handler_VertexHandler) {

	ZEPHIR_REGISTER_CLASS_EX(Arango\\Handler, VertexHandler, arango, handler_vertexhandler, arango_handler_documenthandler_ce, arango_handler_vertexhandler_method_entry, 0);

	return SUCCESS;

}

/**
 * Intermediate function to call the createFromArray function from the right context
 *
 * @throws Arango\Exception\ClientException
 *
 * @param array $data
 * @param array $options
 *
 * @return Arango\Document\Vertex
 */
PHP_METHOD(Arango_Handler_VertexHandler, createFromArrayWithContext) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *data_param = NULL, *options_param = NULL;
	zval data, options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &data_param, &options_param);

	zephir_get_arrval(&data, data_param);
	zephir_get_arrval(&options, options_param);


	ZEPHIR_RETURN_CALL_CE_STATIC(arango_document_vertex_ce, "createfromarray", &_0, 0, &data, &options);
	zephir_check_call_status();
	RETURN_MM();

}

