
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Abstracts basic request methods for classes
 *
 * @package Arango/Http
 * @interface Request
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Http_RequestInterface) {

	ZEPHIR_REGISTER_INTERFACE(Arango\\Http, RequestInterface, arango, http_requestinterface, arango_http_requestinterface_method_entry);

	return SUCCESS;

}

/**
 * Execute an HTTP request and return the results
 *
 * This function will throw if no connection to the server can be established or if
 * there is a problem during data exchange with the server.
 *
 * will restore it.
 *
 * @throws \Exception
 *
 * @param string method       - HTTP request method
 * @param string url          - HTTP url
 * @param string data         - HTTP request data
 * @param array customHeaders - Any custom headers for the request
 *
 * @return Response
 */
ZEPHIR_DOC_METHOD(Arango_Http_RequestInterface, executeRequest);

