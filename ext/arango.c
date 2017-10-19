
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "arango.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *arango_http_executerequest_ce;
zend_class_entry *arango_policies_policy_ce;
zend_class_entry *arango_handler_handler_ce;
zend_class_entry *arango_exception_exception_ce;
zend_class_entry *arango_document_document_ce;
zend_class_entry *arango_handler_documenthandler_ce;
zend_class_entry *arango_http_request_ce;
zend_class_entry *arango_batch_batch_ce;
zend_class_entry *arango_batch_batchpart_ce;
zend_class_entry *arango_client_configuration_ce;
zend_class_entry *arango_collection_collection_ce;
zend_class_entry *arango_connection_connection_ce;
zend_class_entry *arango_connection_encoding_ce;
zend_class_entry *arango_connection_endpoint_ce;
zend_class_entry *arango_connection_options_ce;
zend_class_entry *arango_connection_tracerequest_ce;
zend_class_entry *arango_connection_traceresponse_ce;
zend_class_entry *arango_cursor_cursor_ce;
zend_class_entry *arango_cursor_exportcursor_ce;
zend_class_entry *arango_database_database_ce;
zend_class_entry *arango_document_edge_ce;
zend_class_entry *arango_document_vertex_ce;
zend_class_entry *arango_exception_clientexception_ce;
zend_class_entry *arango_exception_connectionexception_ce;
zend_class_entry *arango_exception_serverexception_ce;
zend_class_entry *arango_export_export_ce;
zend_class_entry *arango_graph_graph_ce;
zend_class_entry *arango_graph_traversal_ce;
zend_class_entry *arango_handler_adminhandler_ce;
zend_class_entry *arango_handler_collectionhandler_ce;
zend_class_entry *arango_handler_edgehandler_ce;
zend_class_entry *arango_handler_querycachehandler_ce;
zend_class_entry *arango_handler_queryhandler_ce;
zend_class_entry *arango_handler_vertexhandler_ce;
zend_class_entry *arango_http_api_ce;
zend_class_entry *arango_http_client_ce;
zend_class_entry *arango_http_response_ce;
zend_class_entry *arango_http_url_ce;
zend_class_entry *arango_policies_updatepolicy_ce;
zend_class_entry *arango_query_statement_ce;
zend_class_entry *arango_transaction_transaction_ce;
zend_class_entry *arango_validation_bind_ce;
zend_class_entry *arango_validation_validation_ce;

ZEND_DECLARE_MODULE_GLOBALS(arango)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(arango)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Arango_Http_ExecuteRequest);
	ZEPHIR_INIT(Arango_Policies_Policy);
	ZEPHIR_INIT(Arango_Handler_Handler);
	ZEPHIR_INIT(Arango_Exception_Exception);
	ZEPHIR_INIT(Arango_Document_Document);
	ZEPHIR_INIT(Arango_Handler_DocumentHandler);
	ZEPHIR_INIT(Arango_Http_Request);
	ZEPHIR_INIT(Arango_Batch_Batch);
	ZEPHIR_INIT(Arango_Batch_BatchPart);
	ZEPHIR_INIT(Arango_Client_Configuration);
	ZEPHIR_INIT(Arango_Collection_Collection);
	ZEPHIR_INIT(Arango_Connection_Connection);
	ZEPHIR_INIT(Arango_Connection_Encoding);
	ZEPHIR_INIT(Arango_Connection_Endpoint);
	ZEPHIR_INIT(Arango_Connection_Options);
	ZEPHIR_INIT(Arango_Connection_TraceRequest);
	ZEPHIR_INIT(Arango_Connection_TraceResponse);
	ZEPHIR_INIT(Arango_Cursor_Cursor);
	ZEPHIR_INIT(Arango_Cursor_ExportCursor);
	ZEPHIR_INIT(Arango_Database_Database);
	ZEPHIR_INIT(Arango_Document_Edge);
	ZEPHIR_INIT(Arango_Document_Vertex);
	ZEPHIR_INIT(Arango_Exception_ClientException);
	ZEPHIR_INIT(Arango_Exception_ConnectionException);
	ZEPHIR_INIT(Arango_Exception_ServerException);
	ZEPHIR_INIT(Arango_Export_Export);
	ZEPHIR_INIT(Arango_Graph_Graph);
	ZEPHIR_INIT(Arango_Graph_Traversal);
	ZEPHIR_INIT(Arango_Handler_AdminHandler);
	ZEPHIR_INIT(Arango_Handler_CollectionHandler);
	ZEPHIR_INIT(Arango_Handler_EdgeHandler);
	ZEPHIR_INIT(Arango_Handler_QueryCacheHandler);
	ZEPHIR_INIT(Arango_Handler_QueryHandler);
	ZEPHIR_INIT(Arango_Handler_VertexHandler);
	ZEPHIR_INIT(Arango_Http_Api);
	ZEPHIR_INIT(Arango_Http_Client);
	ZEPHIR_INIT(Arango_Http_Response);
	ZEPHIR_INIT(Arango_Http_Url);
	ZEPHIR_INIT(Arango_Policies_UpdatePolicy);
	ZEPHIR_INIT(Arango_Query_Statement);
	ZEPHIR_INIT(Arango_Transaction_Transaction);
	ZEPHIR_INIT(Arango_Validation_Bind);
	ZEPHIR_INIT(Arango_Validation_Validation);
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(arango)
{
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_arango_globals *arango_globals TSRMLS_DC)
{
	arango_globals->initialized = 0;

	/* Memory options */
	arango_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	arango_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	arango_globals->cache_enabled = 1;

	/* Recursive Lock */
	arango_globals->recursive_lock = 0;

	/* Static cache */
	memset(arango_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);


}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_arango_globals *arango_globals TSRMLS_DC)
{

}

static PHP_RINIT_FUNCTION(arango)
{

	zend_arango_globals *arango_globals_ptr;
#ifdef ZTS
	tsrm_ls = ts_resource(0);
#endif
	arango_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(arango_globals_ptr TSRMLS_CC);
	zephir_initialize_memory(arango_globals_ptr TSRMLS_CC);


	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(arango)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(arango)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_ARANGO_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_ARANGO_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_ARANGO_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_ARANGO_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_ARANGO_ZEPVERSION);
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(arango)
{
	php_zephir_init_globals(arango_globals TSRMLS_CC);
	php_zephir_init_module_globals(arango_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(arango)
{

}


zend_function_entry php_arango_functions[] = {
ZEND_FE_END

};

zend_module_entry arango_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_ARANGO_EXTNAME,
	php_arango_functions,
	PHP_MINIT(arango),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(arango),
#else
	NULL,
#endif
	PHP_RINIT(arango),
	PHP_RSHUTDOWN(arango),
	PHP_MINFO(arango),
	PHP_ARANGO_VERSION,
	ZEND_MODULE_GLOBALS(arango),
	PHP_GINIT(arango),
	PHP_GSHUTDOWN(arango),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_ARANGO
ZEND_GET_MODULE(arango)
#endif
