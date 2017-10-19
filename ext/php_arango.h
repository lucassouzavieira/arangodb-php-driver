
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_ARANGO_H
#define PHP_ARANGO_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_ARANGO_NAME        "ArangoDB PHP Driver"
#define PHP_ARANGO_VERSION     "0.0.3"
#define PHP_ARANGO_EXTNAME     "arango"
#define PHP_ARANGO_AUTHOR      "Lucas S. Vieira"
#define PHP_ARANGO_ZEPVERSION  "0.9.11-1f84124d4a"
#define PHP_ARANGO_DESCRIPTION "ArangoDB PHP Driver"



ZEND_BEGIN_MODULE_GLOBALS(arango)

	int initialized;

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	
ZEND_END_MODULE_GLOBALS(arango)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(arango)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) ZEND_MODULE_GLOBALS_ACCESSOR(arango, v)
#else
	#define ZEPHIR_GLOBAL(v) (arango_globals.v)
#endif

#ifdef ZTS
	void ***tsrm_ls;
	#define ZEPHIR_VGLOBAL ((zend_arango_globals *) (*((void ***) tsrm_get_ls_cache()))[TSRM_UNSHUFFLE_RSRC_ID(arango_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(arango_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def arango_globals
#define zend_zephir_globals_def zend_arango_globals

extern zend_module_entry arango_module_entry;
#define phpext_arango_ptr &arango_module_entry

#endif
