PHP_ARG_ENABLE(arango, whether to enable arango, [ --enable-arango   Enable Arango])

if test "$PHP_ARANGO" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, ARANGO_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_ARANGO, 1, [Whether you have Arango])
	arango_sources="arango.c kernel/main.c kernel/memory.c kernel/exception.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c arango/handler/handler.zep.c
	arango/exception/exception.zep.c
	arango/document/document.zep.c
	arango/handler/documenthandler.zep.c
	arango/http/executerequest.zep.c
	arango/http/request.zep.c
	arango/policies/policy.zep.c
	arango/batch/batch.zep.c
	arango/batch/batchpart.zep.c
	arango/client/configuration.zep.c
	arango/collection/collection.zep.c
	arango/connection/connection.zep.c
	arango/connection/encoding.zep.c
	arango/connection/endpoint.zep.c
	arango/connection/options.zep.c
	arango/connection/tracerequest.zep.c
	arango/connection/traceresponse.zep.c
	arango/cursor/cursor.zep.c
	arango/cursor/exportcursor.zep.c
	arango/database/database.zep.c
	arango/document/edge.zep.c
	arango/document/vertex.zep.c
	arango/exception/clientexception.zep.c
	arango/exception/connectionexception.zep.c
	arango/exception/serverexception.zep.c
	arango/export/export.zep.c
	arango/graph/graph.zep.c
	arango/graph/traversal.zep.c
	arango/handler/adminhandler.zep.c
	arango/handler/collectionhandler.zep.c
	arango/handler/edgehandler.zep.c
	arango/handler/querycachehandler.zep.c
	arango/handler/queryhandler.zep.c
	arango/handler/vertexhandler.zep.c
	arango/http/api.zep.c
	arango/http/client.zep.c
	arango/http/response.zep.c
	arango/http/url.zep.c
	arango/policies/updatepolicy.zep.c
	arango/query/statement.zep.c
	arango/transaction/transaction.zep.c
	arango/validation/bind.zep.c
	arango/validation/validation.zep.c "
	PHP_NEW_EXTENSION(arango, $arango_sources, $ext_shared,, )
	PHP_SUBST(ARANGO_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([arango], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([arango], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/arango], [php_ARANGO.h])

fi
