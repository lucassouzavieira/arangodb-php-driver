
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
#include "kernel/string.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/object.h"


/**
 * A handler that manages documents
 *
 * @package Arango/Handler
 * @class DocumentHandler
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Handler_DocumentHandler) {

	ZEPHIR_REGISTER_CLASS_EX(Arango\\Handler, DocumentHandler, arango, handler_documenthandler, arango_handler_handler_ce, arango_handler_documenthandler_method_entry, 0);

	/**
	 * Class indexes
	 */
	zephir_declare_class_constant_string(arango_handler_documenthandler_ce, SL("ENTRY_DOCUMENTS"), "documents");

	zephir_declare_class_constant_string(arango_handler_documenthandler_ce, SL("OPTION_COLLECTION"), "collection");

	zephir_declare_class_constant_string(arango_handler_documenthandler_ce, SL("OPTION_EXAMPLE"), "example");

	return SUCCESS;

}

/**
 * Get a single document from a collection
 *
 * @throws \Exception
 *
 * @param string documentId
 * @param array options
 *
 * @return Arango\Document\Document
 */
PHP_METHOD(Arango_Handler_DocumentHandler, get) {

	zephir_fcall_cache_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *documentId_param = NULL, *options_param = NULL, __$false, collection, data, document, documentData;
	zval documentId;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&documentId);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&document);
	ZVAL_UNDEF(&documentData);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &documentId_param, &options_param);

	zephir_get_strval(&documentId, documentId_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&documentData);
	zephir_fast_explode_str(&documentData, SL("/"), &documentId, LONG_MAX TSRMLS_CC);
	ZEPHIR_OBS_VAR(&collection);
	zephir_array_fetch_long(&collection, &documentData, 0, PH_NOISY, "arango/handler/documenthandler.zep", 45 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&document);
	zephir_array_fetch_long(&document, &documentData, 1, PH_NOISY, "arango/handler/documenthandler.zep", 46 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "getdocument", NULL, 0, &collection, &document, &options);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("_isNew"), &__$false, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_CE_STATIC(arango_document_document_ce, "createfromarray", &_0, 0, &data, &options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get a single document from server as array
 *
 * @throws Arango\Exception\ClientException
 *
 * @param string collection
 * @param string document
 * @param array options
 *
 * @return array
 */
PHP_METHOD(Arango_Handler_DocumentHandler, getDocument) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval options, _1;
	zval *collection_param = NULL, *document_param = NULL, *options_param = NULL, url, headerElements, _2, response, _3, _4;
	zval collection, document;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&document);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&headerElements);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &collection_param, &document_param, &options_param);

	zephir_get_strval(&collection, collection_param);
	zephir_get_strval(&document, document_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_1, &collection);
	zephir_array_fast_append(&_1, &document);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "/_api/document");
	ZEPHIR_CALL_CE_STATIC(&url, arango_http_url_ce, "buildurl", &_0, 0, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&headerElements, this_ptr, "buildrevisionheaders", NULL, 0, &options);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, &_3, "get", NULL, 0, &url, &headerElements);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, &response, "getcode", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_4, 304)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(arango_exception_clientexception_ce, "Document has not changed", "arango/handler/documenthandler.zep", 76);
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD(&response, "toarray", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Build the revision headers for an requisition
 *
 * @link https://github.com/arangodb/arangodb-php/blob/devel/lib/ArangoDBClient/DocumentHandler.php#L161-L169
 * @param array options
 *
 * @return array
 */
PHP_METHOD(Arango_Handler_DocumentHandler, buildRevisionHeaders) {

	zend_bool _1;
	zval *options_param = NULL, _0, _2, _3$$3, _6$$3, _7$$3, _4$$4, _5$$4;
	zval options, header;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&header);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	zephir_get_arrval(&options, options_param);


	ZEPHIR_INIT_VAR(&header);
	array_init(&header);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "ifMatch");
	_1 = zephir_array_key_exists(&options, &_0 TSRMLS_CC);
	if (_1) {
		ZEPHIR_INIT_VAR(&_2);
		ZVAL_STRING(&_2, "revision");
		_1 = zephir_array_key_exists(&options, &_2 TSRMLS_CC);
	}
	if (_1) {
		zephir_array_fetch_string(&_3$$3, &options, SL("ifMatch"), PH_NOISY | PH_READONLY, "arango/handler/documenthandler.zep", 94 TSRMLS_CC);
		if (ZEPHIR_IS_TRUE(&_3$$3)) {
			zephir_array_fetch_string(&_4$$4, &options, SL("revision"), PH_NOISY | PH_READONLY, "arango/handler/documenthandler.zep", 95 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_5$$4);
			ZEPHIR_CONCAT_SVS(&_5$$4, "\"", &_4$$4, "\"");
			zephir_array_update_string(&header, SL("If-Match"), &_5$$4, PH_COPY | PH_SEPARATE);
			RETURN_CTOR(&header);
		}
		zephir_array_fetch_string(&_6$$3, &options, SL("revision"), PH_NOISY | PH_READONLY, "arango/handler/documenthandler.zep", 100 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_7$$3);
		ZEPHIR_CONCAT_SVS(&_7$$3, "\"", &_6$$3, "\"");
		zephir_array_update_string(&header, SL("If-None-Match"), &_7$$3, PH_COPY | PH_SEPARATE);
	}
	RETURN_CTOR(&header);

}

/**
 * Check if a document exists in collection
 *
 * @throws \Arango\Exception\ServerException | \Exception
 * @param string documentId
 *
 * @return boolean
 */
PHP_METHOD(Arango_Handler_DocumentHandler, has) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *documentId_param = NULL, e, _0, _1$$4, _2$$7;
	zval documentId;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&documentId);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &documentId_param);

	zephir_get_strval(&documentId, documentId_param);



	/* try_start_1: */

		ZEPHIR_CALL_METHOD(NULL, this_ptr, "get", NULL, 0, &documentId);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_0);
		ZVAL_OBJ(&_0, EG(exception));
		Z_ADDREF_P(&_0);
		if (zephir_instance_of_ev(&_0, arango_exception_serverexception_ce TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&e, &_0);
			ZEPHIR_CALL_METHOD(&_1$$4, &e, "getcode", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG(&_1$$4, 404)) {
				RETURN_MM_BOOL(0);
			}
			zephir_throw_exception_debug(&e, "arango/handler/documenthandler.zep", 124 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		} else {
			if (zephir_instance_of_ev(&_0, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(&e, &_0);
				ZEPHIR_CALL_METHOD(&_2$$7, &e, "getcode", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG(&_2$$7, 404)) {
					RETURN_MM_BOOL(0);
				}
				zephir_throw_exception_debug(&e, "arango/handler/documenthandler.zep", 124 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * Get informations about a single document
 *
 * @throws \Arango\Exception\ServerException | \Exception
 * @param string documentId
 * @param array options
 *
 * @return array
 */
PHP_METHOD(Arango_Handler_DocumentHandler, getInfo) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval options, _1;
	zval *documentId_param = NULL, *options_param = NULL, collection, document, url, headers, documentData, _2, response, responseHeaders, _3, _4;
	zval documentId;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&documentId);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&document);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&documentData);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&responseHeaders);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &documentId_param, &options_param);

	zephir_get_strval(&documentId, documentId_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&documentData);
	zephir_fast_explode_str(&documentData, SL("/"), &documentId, LONG_MAX TSRMLS_CC);
	ZEPHIR_OBS_VAR(&collection);
	zephir_array_fetch_long(&collection, &documentData, 0, PH_NOISY, "arango/handler/documenthandler.zep", 143 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&document);
	zephir_array_fetch_long(&document, &documentData, 1, PH_NOISY, "arango/handler/documenthandler.zep", 144 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_1, &collection);
	zephir_array_fast_append(&_1, &document);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "/_api/document");
	ZEPHIR_CALL_CE_STATIC(&url, arango_http_url_ce, "buildurl", &_0, 0, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&headers, this_ptr, "buildrevisionheaders", NULL, 0, &options);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, &_3, "head", NULL, 0, &url, &headers);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&responseHeaders, &response, "getheaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, &response, "getcode", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&responseHeaders, SL("httpCode"), &_4, PH_COPY | PH_SEPARATE);
	RETURN_CCTOR(&responseHeaders);

}

