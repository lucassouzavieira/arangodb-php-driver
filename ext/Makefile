srcdir = /home/lucas/Code/arangodb-php-driver/ext
builddir = /home/lucas/Code/arangodb-php-driver/ext
top_srcdir = /home/lucas/Code/arangodb-php-driver/ext
top_builddir = /home/lucas/Code/arangodb-php-driver/ext
EGREP = /usr/bin/grep -E
SED = /usr/bin/sed
CONFIGURE_COMMAND = './configure' '--enable-arango'
CONFIGURE_OPTIONS = '--enable-arango'
SHLIB_SUFFIX_NAME = so
SHLIB_DL_SUFFIX_NAME = so
ZEND_EXT_TYPE = zend_extension
RE2C = re2c
AWK = gawk
shared_objects_arango = arango.lo kernel/main.lo kernel/memory.lo kernel/exception.lo kernel/debug.lo kernel/backtrace.lo kernel/object.lo kernel/array.lo kernel/string.lo kernel/fcall.lo kernel/require.lo kernel/file.lo kernel/operators.lo kernel/math.lo kernel/concat.lo kernel/variables.lo kernel/filter.lo kernel/iterator.lo kernel/time.lo kernel/exit.lo arango/handler/handler.lo arango/exception/exception.lo arango/document/document.lo arango/handler/documenthandler.lo arango/http/executerequest.lo arango/http/request.lo arango/policies/policy.lo arango/batch/batch.lo arango/batch/batchpart.lo arango/client/configuration.lo arango/collection/collection.lo arango/connection/connection.lo arango/connection/encoding.lo arango/connection/endpoint.lo arango/connection/options.lo arango/connection/tracerequest.lo arango/connection/traceresponse.lo arango/cursor/cursor.lo arango/cursor/exportcursor.lo arango/database/database.lo arango/document/edge.lo arango/document/vertex.lo arango/exception/clientexception.lo arango/exception/connectionexception.lo arango/exception/serverexception.lo arango/export/export.lo arango/graph/graph.lo arango/graph/traversal.lo arango/handler/adminhandler.lo arango/handler/collectionhandler.lo arango/handler/edgehandler.lo arango/handler/querycachehandler.lo arango/handler/queryhandler.lo arango/handler/vertexhandler.lo arango/http/api.lo arango/http/client.lo arango/http/response.lo arango/http/url.lo arango/policies/updatepolicy.lo arango/query/statement.lo arango/transaction/transaction.lo arango/validation/bind.lo arango/validation/validation.lo
PHP_PECL_EXTENSION = arango
ARANGO_SHARED_LIBADD =
PHP_MODULES = $(phplibdir)/arango.la
PHP_ZEND_EX =
all_targets = $(PHP_MODULES) $(PHP_ZEND_EX)
install_targets = install-modules install-headers
prefix = /usr
exec_prefix = $(prefix)
libdir = ${exec_prefix}/lib
prefix = /usr
phplibdir = /home/lucas/Code/arangodb-php-driver/ext/modules
phpincludedir = /usr/include/php
CC = gcc
CFLAGS = -O2 -fvisibility=hidden -Wparentheses -flto -DZEPHIR_RELEASE=1
CFLAGS_CLEAN = $(CFLAGS)
CPP = gcc -E
CPPFLAGS = -DHAVE_CONFIG_H
CXX =
CXXFLAGS =
CXXFLAGS_CLEAN = $(CXXFLAGS)
EXTENSION_DIR = /usr/lib64/php/modules
PHP_EXECUTABLE = /usr/bin/php
EXTRA_LDFLAGS =
EXTRA_LIBS =
INCLUDES = -I/usr/include/php -I/usr/include/php/main -I/usr/include/php/TSRM -I/usr/include/php/Zend -I/usr/include/php/ext -I/usr/include/php/ext/date/lib
LFLAGS =
LDFLAGS =
SHARED_LIBTOOL =
LIBTOOL = $(SHELL) $(top_builddir)/libtool
SHELL = /bin/sh
INSTALL_HEADERS = ext/arango/php_ARANGO.h
mkinstalldirs = $(top_srcdir)/build/shtool mkdir -p
INSTALL = $(top_srcdir)/build/shtool install -c
INSTALL_DATA = $(INSTALL) -m 644

DEFS = -DPHP_ATOM_INC -I$(top_builddir)/include -I$(top_builddir)/main -I$(top_srcdir)
COMMON_FLAGS = $(DEFS) $(INCLUDES) $(EXTRA_INCLUDES) $(CPPFLAGS) $(PHP_FRAMEWORKPATH)

all: $(all_targets) 
	@echo
	@echo "Build complete."
	@echo "Don't forget to run 'make test'."
	@echo

build-modules: $(PHP_MODULES) $(PHP_ZEND_EX)

build-binaries: $(PHP_BINARIES)

libphp$(PHP_MAJOR_VERSION).la: $(PHP_GLOBAL_OBJS) $(PHP_SAPI_OBJS)
	$(LIBTOOL) --mode=link $(CC) $(CFLAGS) $(EXTRA_CFLAGS) -rpath $(phptempdir) $(EXTRA_LDFLAGS) $(LDFLAGS) $(PHP_RPATHS) $(PHP_GLOBAL_OBJS) $(PHP_SAPI_OBJS) $(EXTRA_LIBS) $(ZEND_EXTRA_LIBS) -o $@
	-@$(LIBTOOL) --silent --mode=install cp $@ $(phptempdir)/$@ >/dev/null 2>&1

libs/libphp$(PHP_MAJOR_VERSION).bundle: $(PHP_GLOBAL_OBJS) $(PHP_SAPI_OBJS)
	$(CC) $(MH_BUNDLE_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) $(LDFLAGS) $(EXTRA_LDFLAGS) $(PHP_GLOBAL_OBJS:.lo=.o) $(PHP_SAPI_OBJS:.lo=.o) $(PHP_FRAMEWORKS) $(EXTRA_LIBS) $(ZEND_EXTRA_LIBS) -o $@ && cp $@ libs/libphp$(PHP_MAJOR_VERSION).so

install: $(all_targets) $(install_targets)

install-sapi: $(OVERALL_TARGET)
	@echo "Installing PHP SAPI module:       $(PHP_SAPI)"
	-@$(mkinstalldirs) $(INSTALL_ROOT)$(bindir)
	-@if test ! -r $(phptempdir)/libphp$(PHP_MAJOR_VERSION).$(SHLIB_DL_SUFFIX_NAME); then \
		for i in 0.0.0 0.0 0; do \
			if test -r $(phptempdir)/libphp$(PHP_MAJOR_VERSION).$(SHLIB_DL_SUFFIX_NAME).$$i; then \
				$(LN_S) $(phptempdir)/libphp$(PHP_MAJOR_VERSION).$(SHLIB_DL_SUFFIX_NAME).$$i $(phptempdir)/libphp$(PHP_MAJOR_VERSION).$(SHLIB_DL_SUFFIX_NAME); \
				break; \
			fi; \
		done; \
	fi
	@$(INSTALL_IT)

install-binaries: build-binaries $(install_binary_targets)

install-modules: build-modules
	@test -d modules && \
	$(mkinstalldirs) $(INSTALL_ROOT)$(EXTENSION_DIR)
	@echo "Installing shared extensions:     $(INSTALL_ROOT)$(EXTENSION_DIR)/"
	@rm -f modules/*.la >/dev/null 2>&1
	@$(INSTALL) modules/* $(INSTALL_ROOT)$(EXTENSION_DIR)

install-headers:
	-@if test "$(INSTALL_HEADERS)"; then \
		for i in `echo $(INSTALL_HEADERS)`; do \
			i=`$(top_srcdir)/build/shtool path -d $$i`; \
			paths="$$paths $(INSTALL_ROOT)$(phpincludedir)/$$i"; \
		done; \
		$(mkinstalldirs) $$paths && \
		echo "Installing header files:          $(INSTALL_ROOT)$(phpincludedir)/" && \
		for i in `echo $(INSTALL_HEADERS)`; do \
			if test "$(PHP_PECL_EXTENSION)"; then \
				src=`echo $$i | $(SED) -e "s#ext/$(PHP_PECL_EXTENSION)/##g"`; \
			else \
				src=$$i; \
			fi; \
			if test -f "$(top_srcdir)/$$src"; then \
				$(INSTALL_DATA) $(top_srcdir)/$$src $(INSTALL_ROOT)$(phpincludedir)/$$i; \
			elif test -f "$(top_builddir)/$$src"; then \
				$(INSTALL_DATA) $(top_builddir)/$$src $(INSTALL_ROOT)$(phpincludedir)/$$i; \
			else \
				(cd $(top_srcdir)/$$src && $(INSTALL_DATA) *.h $(INSTALL_ROOT)$(phpincludedir)/$$i; \
				cd $(top_builddir)/$$src && $(INSTALL_DATA) *.h $(INSTALL_ROOT)$(phpincludedir)/$$i) 2>/dev/null || true; \
			fi \
		done; \
	fi

PHP_TEST_SETTINGS = -d 'open_basedir=' -d 'output_buffering=0' -d 'memory_limit=-1'
PHP_TEST_SHARED_EXTENSIONS =  ` \
	if test "x$(PHP_MODULES)" != "x"; then \
		for i in $(PHP_MODULES)""; do \
			. $$i; $(top_srcdir)/build/shtool echo -n -- " -d extension=$$dlname"; \
		done; \
	fi; \
	if test "x$(PHP_ZEND_EX)" != "x"; then \
		for i in $(PHP_ZEND_EX)""; do \
			. $$i; $(top_srcdir)/build/shtool echo -n -- " -d $(ZEND_EXT_TYPE)=$(top_builddir)/modules/$$dlname"; \
		done; \
	fi`
PHP_DEPRECATED_DIRECTIVES_REGEX = '^(magic_quotes_(gpc|runtime|sybase)?|(zend_)?extension(_debug)?(_ts)?)[\t\ ]*='

test: all
	@if test ! -z "$(PHP_EXECUTABLE)" && test -x "$(PHP_EXECUTABLE)"; then \
		INI_FILE=`$(PHP_EXECUTABLE) -d 'display_errors=stderr' -r 'echo php_ini_loaded_file();' 2> /dev/null`; \
		if test "$$INI_FILE"; then \
			$(EGREP) -h -v $(PHP_DEPRECATED_DIRECTIVES_REGEX) "$$INI_FILE" > $(top_builddir)/tmp-php.ini; \
		else \
			echo > $(top_builddir)/tmp-php.ini; \
		fi; \
		INI_SCANNED_PATH=`$(PHP_EXECUTABLE) -d 'display_errors=stderr' -r '$$a = explode(",\n", trim(php_ini_scanned_files())); echo $$a[0];' 2> /dev/null`; \
		if test "$$INI_SCANNED_PATH"; then \
			INI_SCANNED_PATH=`$(top_srcdir)/build/shtool path -d $$INI_SCANNED_PATH`; \
			$(EGREP) -h -v $(PHP_DEPRECATED_DIRECTIVES_REGEX) "$$INI_SCANNED_PATH"/*.ini >> $(top_builddir)/tmp-php.ini; \
		fi; \
		TEST_PHP_EXECUTABLE=$(PHP_EXECUTABLE) \
		TEST_PHP_SRCDIR=$(top_srcdir) \
		CC="$(CC)" \
			$(PHP_EXECUTABLE) -n -c $(top_builddir)/tmp-php.ini $(PHP_TEST_SETTINGS) $(top_srcdir)/run-tests.php -n -c $(top_builddir)/tmp-php.ini -d extension_dir=$(top_builddir)/modules/ $(PHP_TEST_SHARED_EXTENSIONS) $(TESTS); \
		TEST_RESULT_EXIT_CODE=$$?; \
		rm $(top_builddir)/tmp-php.ini; \
		exit $$TEST_RESULT_EXIT_CODE; \
	else \
		echo "ERROR: Cannot run tests without CLI sapi."; \
	fi

clean:
	find . -name \*.gcno -o -name \*.gcda | xargs rm -f
	find . -name \*.lo -o -name \*.o | xargs rm -f
	find . -name \*.la -o -name \*.a | xargs rm -f 
	find . -name \*.so | xargs rm -f
	find . -name .libs -a -type d|xargs rm -rf
	rm -f libphp$(PHP_MAJOR_VERSION).la $(SAPI_CLI_PATH) $(SAPI_CGI_PATH) $(SAPI_MILTER_PATH) $(SAPI_LITESPEED_PATH) $(SAPI_FPM_PATH) $(OVERALL_TARGET) modules/* libs/*

distclean: clean
	rm -f Makefile config.cache config.log config.status Makefile.objects Makefile.fragments libtool main/php_config.h main/internal_functions_cli.c main/internal_functions.c stamp-h sapi/apache/libphp$(PHP_MAJOR_VERSION).module sapi/apache_hooks/libphp$(PHP_MAJOR_VERSION).module buildmk.stamp Zend/zend_dtrace_gen.h Zend/zend_dtrace_gen.h.bak Zend/zend_config.h TSRM/tsrm_config.h
	rm -f php7.spec main/build-defs.h scripts/phpize
	rm -f ext/date/lib/timelib_config.h ext/mbstring/oniguruma/config.h ext/mbstring/libmbfl/config.h ext/oci8/oci8_dtrace_gen.h ext/oci8/oci8_dtrace_gen.h.bak
	rm -f scripts/man1/phpize.1 scripts/php-config scripts/man1/php-config.1 sapi/cli/php.1 sapi/cgi/php-cgi.1 ext/phar/phar.1 ext/phar/phar.phar.1
	rm -f sapi/fpm/php-fpm.conf sapi/fpm/init.d.php-fpm sapi/fpm/php-fpm.service sapi/fpm/php-fpm.8 sapi/fpm/status.html
	rm -f ext/iconv/php_have_bsd_iconv.h ext/iconv/php_have_glibc_iconv.h ext/iconv/php_have_ibm_iconv.h ext/iconv/php_have_iconv.h ext/iconv/php_have_libiconv.h ext/iconv/php_iconv_aliased_libiconv.h ext/iconv/php_iconv_supports_errno.h ext/iconv/php_php_iconv_h_path.h ext/iconv/php_php_iconv_impl.h
	rm -f ext/phar/phar.phar ext/phar/phar.php
	if test "$(srcdir)" != "$(builddir)"; then \
	  rm -f ext/phar/phar/phar.inc; \
	fi
	$(EGREP) define'.*include/php' $(top_srcdir)/configure | $(SED) 's/.*>//'|xargs rm -f

prof-gen:
	CCACHE_DISABLE=1 $(MAKE) PROF_FLAGS=-fprofile-generate all

prof-clean:
	find . -name \*.lo -o -name \*.o | xargs rm -f
	find . -name \*.la -o -name \*.a | xargs rm -f 
	find . -name \*.so | xargs rm -f
	rm -f libphp$(PHP_MAJOR_VERSION).la $(SAPI_CLI_PATH) $(SAPI_CGI_PATH) $(SAPI_MILTER_PATH) $(SAPI_LITESPEED_PATH) $(SAPI_FPM_PATH) $(OVERALL_TARGET) modules/* libs/*

prof-use:
	CCACHE_DISABLE=1 $(MAKE) PROF_FLAGS=-fprofile-use all


.PHONY: all clean install distclean test prof-gen prof-clean prof-use
.NOEXPORT:
arango.lo: /home/lucas/Code/arangodb-php-driver/ext/arango.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango.c -o arango.lo 
kernel/main.lo: /home/lucas/Code/arangodb-php-driver/ext/kernel/main.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/kernel/main.c -o kernel/main.lo 
kernel/memory.lo: /home/lucas/Code/arangodb-php-driver/ext/kernel/memory.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/kernel/memory.c -o kernel/memory.lo 
kernel/exception.lo: /home/lucas/Code/arangodb-php-driver/ext/kernel/exception.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/kernel/exception.c -o kernel/exception.lo 
kernel/debug.lo: /home/lucas/Code/arangodb-php-driver/ext/kernel/debug.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/kernel/debug.c -o kernel/debug.lo 
kernel/backtrace.lo: /home/lucas/Code/arangodb-php-driver/ext/kernel/backtrace.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/kernel/backtrace.c -o kernel/backtrace.lo 
kernel/object.lo: /home/lucas/Code/arangodb-php-driver/ext/kernel/object.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/kernel/object.c -o kernel/object.lo 
kernel/array.lo: /home/lucas/Code/arangodb-php-driver/ext/kernel/array.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/kernel/array.c -o kernel/array.lo 
kernel/string.lo: /home/lucas/Code/arangodb-php-driver/ext/kernel/string.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/kernel/string.c -o kernel/string.lo 
kernel/fcall.lo: /home/lucas/Code/arangodb-php-driver/ext/kernel/fcall.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/kernel/fcall.c -o kernel/fcall.lo 
kernel/require.lo: /home/lucas/Code/arangodb-php-driver/ext/kernel/require.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/kernel/require.c -o kernel/require.lo 
kernel/file.lo: /home/lucas/Code/arangodb-php-driver/ext/kernel/file.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/kernel/file.c -o kernel/file.lo 
kernel/operators.lo: /home/lucas/Code/arangodb-php-driver/ext/kernel/operators.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/kernel/operators.c -o kernel/operators.lo 
kernel/math.lo: /home/lucas/Code/arangodb-php-driver/ext/kernel/math.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/kernel/math.c -o kernel/math.lo 
kernel/concat.lo: /home/lucas/Code/arangodb-php-driver/ext/kernel/concat.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/kernel/concat.c -o kernel/concat.lo 
kernel/variables.lo: /home/lucas/Code/arangodb-php-driver/ext/kernel/variables.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/kernel/variables.c -o kernel/variables.lo 
kernel/filter.lo: /home/lucas/Code/arangodb-php-driver/ext/kernel/filter.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/kernel/filter.c -o kernel/filter.lo 
kernel/iterator.lo: /home/lucas/Code/arangodb-php-driver/ext/kernel/iterator.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/kernel/iterator.c -o kernel/iterator.lo 
kernel/time.lo: /home/lucas/Code/arangodb-php-driver/ext/kernel/time.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/kernel/time.c -o kernel/time.lo 
kernel/exit.lo: /home/lucas/Code/arangodb-php-driver/ext/kernel/exit.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/kernel/exit.c -o kernel/exit.lo 
arango/handler/handler.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/handler/handler.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/handler/handler.zep.c -o arango/handler/handler.lo 
arango/exception/exception.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/exception/exception.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/exception/exception.zep.c -o arango/exception/exception.lo 
arango/document/document.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/document/document.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/document/document.zep.c -o arango/document/document.lo 
arango/handler/documenthandler.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/handler/documenthandler.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/handler/documenthandler.zep.c -o arango/handler/documenthandler.lo 
arango/http/executerequest.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/http/executerequest.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/http/executerequest.zep.c -o arango/http/executerequest.lo 
arango/http/request.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/http/request.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/http/request.zep.c -o arango/http/request.lo 
arango/policies/policy.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/policies/policy.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/policies/policy.zep.c -o arango/policies/policy.lo 
arango/batch/batch.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/batch/batch.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/batch/batch.zep.c -o arango/batch/batch.lo 
arango/batch/batchpart.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/batch/batchpart.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/batch/batchpart.zep.c -o arango/batch/batchpart.lo 
arango/client/configuration.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/client/configuration.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/client/configuration.zep.c -o arango/client/configuration.lo 
arango/collection/collection.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/collection/collection.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/collection/collection.zep.c -o arango/collection/collection.lo 
arango/connection/connection.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/connection/connection.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/connection/connection.zep.c -o arango/connection/connection.lo 
arango/connection/encoding.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/connection/encoding.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/connection/encoding.zep.c -o arango/connection/encoding.lo 
arango/connection/endpoint.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/connection/endpoint.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/connection/endpoint.zep.c -o arango/connection/endpoint.lo 
arango/connection/options.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/connection/options.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/connection/options.zep.c -o arango/connection/options.lo 
arango/connection/tracerequest.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/connection/tracerequest.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/connection/tracerequest.zep.c -o arango/connection/tracerequest.lo 
arango/connection/traceresponse.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/connection/traceresponse.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/connection/traceresponse.zep.c -o arango/connection/traceresponse.lo 
arango/cursor/cursor.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/cursor/cursor.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/cursor/cursor.zep.c -o arango/cursor/cursor.lo 
arango/cursor/exportcursor.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/cursor/exportcursor.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/cursor/exportcursor.zep.c -o arango/cursor/exportcursor.lo 
arango/database/database.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/database/database.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/database/database.zep.c -o arango/database/database.lo 
arango/document/edge.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/document/edge.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/document/edge.zep.c -o arango/document/edge.lo 
arango/document/vertex.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/document/vertex.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/document/vertex.zep.c -o arango/document/vertex.lo 
arango/exception/clientexception.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/exception/clientexception.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/exception/clientexception.zep.c -o arango/exception/clientexception.lo 
arango/exception/connectionexception.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/exception/connectionexception.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/exception/connectionexception.zep.c -o arango/exception/connectionexception.lo 
arango/exception/serverexception.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/exception/serverexception.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/exception/serverexception.zep.c -o arango/exception/serverexception.lo 
arango/export/export.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/export/export.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/export/export.zep.c -o arango/export/export.lo 
arango/graph/graph.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/graph/graph.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/graph/graph.zep.c -o arango/graph/graph.lo 
arango/graph/traversal.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/graph/traversal.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/graph/traversal.zep.c -o arango/graph/traversal.lo 
arango/handler/adminhandler.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/handler/adminhandler.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/handler/adminhandler.zep.c -o arango/handler/adminhandler.lo 
arango/handler/collectionhandler.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/handler/collectionhandler.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/handler/collectionhandler.zep.c -o arango/handler/collectionhandler.lo 
arango/handler/edgehandler.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/handler/edgehandler.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/handler/edgehandler.zep.c -o arango/handler/edgehandler.lo 
arango/handler/querycachehandler.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/handler/querycachehandler.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/handler/querycachehandler.zep.c -o arango/handler/querycachehandler.lo 
arango/handler/queryhandler.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/handler/queryhandler.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/handler/queryhandler.zep.c -o arango/handler/queryhandler.lo 
arango/handler/vertexhandler.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/handler/vertexhandler.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/handler/vertexhandler.zep.c -o arango/handler/vertexhandler.lo 
arango/http/api.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/http/api.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/http/api.zep.c -o arango/http/api.lo 
arango/http/client.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/http/client.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/http/client.zep.c -o arango/http/client.lo 
arango/http/response.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/http/response.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/http/response.zep.c -o arango/http/response.lo 
arango/http/url.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/http/url.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/http/url.zep.c -o arango/http/url.lo 
arango/policies/updatepolicy.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/policies/updatepolicy.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/policies/updatepolicy.zep.c -o arango/policies/updatepolicy.lo 
arango/query/statement.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/query/statement.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/query/statement.zep.c -o arango/query/statement.lo 
arango/transaction/transaction.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/transaction/transaction.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/transaction/transaction.zep.c -o arango/transaction/transaction.lo 
arango/validation/bind.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/validation/bind.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/validation/bind.zep.c -o arango/validation/bind.lo 
arango/validation/validation.lo: /home/lucas/Code/arangodb-php-driver/ext/arango/validation/validation.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/lucas/Code/arangodb-php-driver/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/lucas/Code/arangodb-php-driver/ext/arango/validation/validation.zep.c -o arango/validation/validation.lo 
$(phplibdir)/arango.la: ./arango.la
	$(LIBTOOL) --mode=install cp ./arango.la $(phplibdir)

./arango.la: $(shared_objects_arango) $(ARANGO_SHARED_DEPENDENCIES)
	$(LIBTOOL) --mode=link $(CC) $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) $(LDFLAGS) -o $@ -export-dynamic -avoid-version -prefer-pic -module -rpath $(phplibdir) $(EXTRA_LDFLAGS) $(shared_objects_arango) $(ARANGO_SHARED_LIBADD)

