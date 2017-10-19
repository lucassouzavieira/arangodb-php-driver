
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Policy interface
 *
 * @package Arango\Policies
 * @interface Policy
 * @author Lucas S. Vieira
 */
ZEPHIR_INIT_CLASS(Arango_Policies_Policy) {

	ZEPHIR_REGISTER_INTERFACE(Arango\\Policies, Policy, arango, policies_policy, arango_policies_policy_method_entry);

	return SUCCESS;

}

/**
 * Validate an supplied policy value
 *
 * @throws \Arango\Exception\ClientException
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(Arango_Policies_Policy, validate);

