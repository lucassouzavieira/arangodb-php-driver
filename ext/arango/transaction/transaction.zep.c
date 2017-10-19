
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
 * Transaction class
 *
 * Encapsulates ArangoDB server transactions
 * TODO all
 * @package Arango/Transaction
 * @class Transaction
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Transaction_Transaction) {

	ZEPHIR_REGISTER_CLASS(Arango\\Transaction, Transaction, arango, transaction_transaction, NULL, 0);

	return SUCCESS;

}

