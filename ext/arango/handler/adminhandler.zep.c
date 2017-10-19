
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"


/**
 * A handler that manages admin document
 *
 * @package Arango/Handler
 * @class AdminHandler
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Handler_AdminHandler) {

	ZEPHIR_REGISTER_CLASS_EX(Arango\\Handler, AdminHandler, arango, handler_adminhandler, arango_handler_handler_ce, arango_handler_adminhandler_method_entry, 0);

	/**
	 * Details for server version
	 */
	zephir_declare_class_constant_string(arango_handler_adminhandler_ce, SL("OPTION_DETAILS"), "details");

	return SUCCESS;

}

/**
 * Get the server version
 *
 * @throws \Exception
 *
 * @param boolean details - True to get a more detailed response
 *
 * @return array | string
 */
PHP_METHOD(Arango_Handler_AdminHandler, getServerVersion) {

	zval _2$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *details_param = NULL, __$true, url, response, data, _3, _4, _0$$3;
	zend_bool details;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &details_param);

	if (!details_param) {
		details = 0;
	} else {
		details = zephir_get_boolval(details_param);
	}


	ZEPHIR_INIT_VAR(&url);
	ZVAL_STRING(&url, "/_admin/version");
	if (details) {
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_create_array(&_2$$3, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&_2$$3, SL("details"), &__$true, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_CE_STATIC(&_0$$3, arango_http_url_ce, "appendparamstourl", &_1, 0, &url, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&url, &_0$$3);
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, &_3, "get", NULL, 0, &url);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&data, &response, "toarray", NULL, 0);
	zephir_check_call_status();
	if (details) {
		RETURN_CCTOR(&data);
	}
	zephir_array_fetch_string(&_4, &data, SL("version"), PH_NOISY | PH_READONLY, "arango/handler/adminhandler.zep", 50 TSRMLS_CC);
	RETURN_CTOR(&_4);

}

/**
 * Get the server role
 *
 * @throws \Exception
 *
 * @return string - server role
 */
PHP_METHOD(Arango_Handler_AdminHandler, getServerRole) {

	zval response, data, _0, _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/_admin/server/role");
	ZEPHIR_CALL_METHOD(&response, &_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&data, &response, "toarray", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_string(&_2, &data, SL("role"), PH_NOISY | PH_READONLY, "arango/handler/adminhandler.zep", 66 TSRMLS_CC);
	RETURN_CTOR(&_2);

}

/**
 * Get the server time
 *
 * @throws \Exception
 *
 * @return double - a double holding the timestamp
 */
PHP_METHOD(Arango_Handler_AdminHandler, getServerTime) {

	zval response, data, _0, _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/_admin/time");
	ZEPHIR_CALL_METHOD(&response, &_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&data, &response, "toarray", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_string(&_2, &data, SL("time"), PH_NOISY | PH_READONLY, "arango/handler/adminhandler.zep", 82 TSRMLS_CC);
	RETURN_CTOR(&_2);

}

/**
 * Get the server log
 *
 * This will throw if the log cannot be retrieved
 *
 * @throws Exception
 *
 * @param array $options - an array of options that define the result-set:
 *
 * Options are :
 * 'upto' - returns all log entries up to a log-level. Note that log-level must be one of:
 *  - fatal / 0
 *  - error / 1
 *  - warning / 2
 *  - info / 3
 *  - debug / 4
 *
 * 'level'  -  limits the log entries to the ones defined in level. Note that `level` and `upto` are mutably exclusive.
 * 'offset' -  skip the first offset entries.
 * 'size'   -  limit the number of returned log-entries to size.
 * 'start'  -  Returns all log entries such that their log-entry identifier is greater or equal to lid.
 * 'sort'   -  Sort the log-entries either ascending if direction is asc, or descending if it is desc according to their lid. Note that the lid imposes a chronological order.
 * 'search' -  Only return the log-entries containing the text string...
 *
 * @return array - an array holding the various attributes of a log: lid, level, timestamp, text and the total amount of log entries before pagination.
 */
PHP_METHOD(Arango_Handler_AdminHandler, getServerLog) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *options_param = NULL, url, response, _1, _2;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/_admin/log");
	ZEPHIR_CALL_CE_STATIC(&url, arango_http_url_ce, "appendparamstourl", &_0, 0, &_1, &options);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, &_2, "get", NULL, 0, &url);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&response, "toarray", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Reload the server's routing information
 * The call triggers a reload of the routing information from the _routing collection
 * This will throw if the routing cannot be reloaded
 *
 * @throws Exception
 *
 * @return bool
 */
PHP_METHOD(Arango_Handler_AdminHandler, reloadServerRouting) {

	zval _0, _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "/_admin/routing/reload");
	ZEPHIR_CALL_METHOD(NULL, &_0, "post", NULL, 0, &_2, &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);

}

/**
 * Get the server statistics
 * Returns the statistics information. The returned objects contains the statistics figures, grouped together
 * according to the description returned by _admin/statistics-description.
 * For instance, to access a figure userTime from the group system, you first select the sub-object
 * describing the group stored in system and in that sub-object the value for userTime is stored in the
 * attribute of the same name.In case of a distribution, the returned object contains the total count in count
 * and the distribution list in counts.
 * For more information on the statistics returned, please lookup the statistics interface description at
 *
 * @link  https://docs.arangodb.com/HTTP/AdministrationAndMonitoring/index.html
 *
 * This will throw if the statistics cannot be retrieved
 *
 * @throws Exception
 *
 * @return array
 */
PHP_METHOD(Arango_Handler_AdminHandler, getServerStatistics) {

	zval response, _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/_admin/statistics");
	ZEPHIR_CALL_METHOD(&response, &_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&response, "toarray", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns a description of the statistics returned by getServerStatistics().
 * The returned objects contains a list of statistics groups in the attribute groups
 * and a list of statistics figures in the attribute figures.
 * For more information on the statistics returned, please lookup the statistics interface description at
 *
 * @link  https://docs.arangodb.com/HTTP/AdministrationAndMonitoring/index.html
 *
 * This will throw if the statistics-description cannot be retrieved
 *
 * @throws Exception
 *
 * @param array $options - an array of options that define the result-set:
 *
 * Options are :
 * 'granularity' - use minutes for a granularity of minutes, hours for hours, and days for days. The default is minutes.
 * 'figures' - a list of figures, comma-separated. Possible figures are httpConnections. You can use all to get all figures. The default is httpConnections.
 * 'length' - If you want a time series, the maximal length of the series as integer. You can use all to get all available information. You can use current to get the latest interval.
 *
 * @return array
 */
PHP_METHOD(Arango_Handler_AdminHandler, getServerStatisticsDescription) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *options_param = NULL, url, response, _1, _2;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/_admin/statistics-description");
	ZEPHIR_CALL_CE_STATIC(&url, arango_http_url_ce, "appendparamstourl", &_0, 0, &_1, &options);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, &_2, "get", NULL, 0, &url);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&response, "toarray", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

