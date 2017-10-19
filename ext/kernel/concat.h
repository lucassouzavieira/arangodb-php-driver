
#ifndef ZEPHIR_KERNEL_CONCAT_H
#define ZEPHIR_KERNEL_CONCAT_H
#include <php.h>
#include <Zend/zend.h>
#include "kernel/main.h"
#define ZEPHIR_CONCAT_SS(result, op1, op2) \
	 zephir_concat_ss(result, op1, sizeof(op1)-1, op2, sizeof(op2)-1, 0);
#define ZEPHIR_SCONCAT_SS(result, op1, op2) \
	 zephir_concat_ss(result, op1, sizeof(op1)-1, op2, sizeof(op2)-1, 1);

#define ZEPHIR_CONCAT_SSS(result, op1, op2, op3) \
	 zephir_concat_sss(result, op1, sizeof(op1)-1, op2, sizeof(op2)-1, op3, sizeof(op3)-1, 0);
#define ZEPHIR_SCONCAT_SSS(result, op1, op2, op3) \
	 zephir_concat_sss(result, op1, sizeof(op1)-1, op2, sizeof(op2)-1, op3, sizeof(op3)-1, 1);

#define ZEPHIR_CONCAT_SSV(result, op1, op2, op3) \
	 zephir_concat_ssv(result, op1, sizeof(op1)-1, op2, sizeof(op2)-1, op3, 0);
#define ZEPHIR_SCONCAT_SSV(result, op1, op2, op3) \
	 zephir_concat_ssv(result, op1, sizeof(op1)-1, op2, sizeof(op2)-1, op3, 1);

#define ZEPHIR_CONCAT_SSVSV(result, op1, op2, op3, op4, op5) \
	 zephir_concat_ssvsv(result, op1, sizeof(op1)-1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, op5, 0);
#define ZEPHIR_SCONCAT_SSVSV(result, op1, op2, op3, op4, op5) \
	 zephir_concat_ssvsv(result, op1, sizeof(op1)-1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, op5, 1);

#define ZEPHIR_CONCAT_SV(result, op1, op2) \
	 zephir_concat_sv(result, op1, sizeof(op1)-1, op2, 0);
#define ZEPHIR_SCONCAT_SV(result, op1, op2) \
	 zephir_concat_sv(result, op1, sizeof(op1)-1, op2, 1);

#define ZEPHIR_CONCAT_SVS(result, op1, op2, op3) \
	 zephir_concat_svs(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, 0);
#define ZEPHIR_SCONCAT_SVS(result, op1, op2, op3) \
	 zephir_concat_svs(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, 1);

#define ZEPHIR_CONCAT_SVSV(result, op1, op2, op3, op4) \
	 zephir_concat_svsv(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, 0);
#define ZEPHIR_SCONCAT_SVSV(result, op1, op2, op3, op4) \
	 zephir_concat_svsv(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, 1);

#define ZEPHIR_CONCAT_SVSVV(result, op1, op2, op3, op4, op5) \
	 zephir_concat_svsvv(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, 0);
#define ZEPHIR_SCONCAT_SVSVV(result, op1, op2, op3, op4, op5) \
	 zephir_concat_svsvv(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, 1);

#define ZEPHIR_CONCAT_VS(result, op1, op2) \
	 zephir_concat_vs(result, op1, op2, sizeof(op2)-1, 0);
#define ZEPHIR_SCONCAT_VS(result, op1, op2) \
	 zephir_concat_vs(result, op1, op2, sizeof(op2)-1, 1);

#define ZEPHIR_CONCAT_VSS(result, op1, op2, op3) \
	 zephir_concat_vss(result, op1, op2, sizeof(op2)-1, op3, sizeof(op3)-1, 0);
#define ZEPHIR_SCONCAT_VSS(result, op1, op2, op3) \
	 zephir_concat_vss(result, op1, op2, sizeof(op2)-1, op3, sizeof(op3)-1, 1);

#define ZEPHIR_CONCAT_VSSSS(result, op1, op2, op3, op4, op5) \
	 zephir_concat_vssss(result, op1, op2, sizeof(op2)-1, op3, sizeof(op3)-1, op4, sizeof(op4)-1, op5, sizeof(op5)-1, 0);
#define ZEPHIR_SCONCAT_VSSSS(result, op1, op2, op3, op4, op5) \
	 zephir_concat_vssss(result, op1, op2, sizeof(op2)-1, op3, sizeof(op3)-1, op4, sizeof(op4)-1, op5, sizeof(op5)-1, 1);

#define ZEPHIR_CONCAT_VSV(result, op1, op2, op3) \
	 zephir_concat_vsv(result, op1, op2, sizeof(op2)-1, op3, 0);
#define ZEPHIR_SCONCAT_VSV(result, op1, op2, op3) \
	 zephir_concat_vsv(result, op1, op2, sizeof(op2)-1, op3, 1);

#define ZEPHIR_CONCAT_VSVS(result, op1, op2, op3, op4) \
	 zephir_concat_vsvs(result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, 0);
#define ZEPHIR_SCONCAT_VSVS(result, op1, op2, op3, op4) \
	 zephir_concat_vsvs(result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, 1);

#define ZEPHIR_CONCAT_VV(result, op1, op2) \
	 zephir_concat_vv(result, op1, op2, 0);
#define ZEPHIR_SCONCAT_VV(result, op1, op2) \
	 zephir_concat_vv(result, op1, op2, 1);

#define ZEPHIR_CONCAT_VVS(result, op1, op2, op3) \
	 zephir_concat_vvs(result, op1, op2, op3, sizeof(op3)-1, 0);
#define ZEPHIR_SCONCAT_VVS(result, op1, op2, op3) \
	 zephir_concat_vvs(result, op1, op2, op3, sizeof(op3)-1, 1);

#define ZEPHIR_CONCAT_VVSS(result, op1, op2, op3, op4) \
	 zephir_concat_vvss(result, op1, op2, op3, sizeof(op3)-1, op4, sizeof(op4)-1, 0);
#define ZEPHIR_SCONCAT_VVSS(result, op1, op2, op3, op4) \
	 zephir_concat_vvss(result, op1, op2, op3, sizeof(op3)-1, op4, sizeof(op4)-1, 1);

#define ZEPHIR_CONCAT_VVSVS(result, op1, op2, op3, op4, op5) \
	 zephir_concat_vvsvs(result, op1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, 0);
#define ZEPHIR_SCONCAT_VVSVS(result, op1, op2, op3, op4, op5) \
	 zephir_concat_vvsvs(result, op1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, 1);

#define ZEPHIR_CONCAT_VVVV(result, op1, op2, op3, op4) \
	 zephir_concat_vvvv(result, op1, op2, op3, op4, 0);
#define ZEPHIR_SCONCAT_VVVV(result, op1, op2, op3, op4) \
	 zephir_concat_vvvv(result, op1, op2, op3, op4, 1);


void zephir_concat_ss(zval *result, const char *op1, zend_uint op1_len, const char *op2, zend_uint op2_len, int self_var);
void zephir_concat_sss(zval *result, const char *op1, zend_uint op1_len, const char *op2, zend_uint op2_len, const char *op3, zend_uint op3_len, int self_var);
void zephir_concat_ssv(zval *result, const char *op1, zend_uint op1_len, const char *op2, zend_uint op2_len, zval *op3, int self_var);
void zephir_concat_ssvsv(zval *result, const char *op1, zend_uint op1_len, const char *op2, zend_uint op2_len, zval *op3, const char *op4, zend_uint op4_len, zval *op5, int self_var);
void zephir_concat_sv(zval *result, const char *op1, zend_uint op1_len, zval *op2, int self_var);
void zephir_concat_svs(zval *result, const char *op1, zend_uint op1_len, zval *op2, const char *op3, zend_uint op3_len, int self_var);
void zephir_concat_svsv(zval *result, const char *op1, zend_uint op1_len, zval *op2, const char *op3, zend_uint op3_len, zval *op4, int self_var);
void zephir_concat_svsvv(zval *result, const char *op1, zend_uint op1_len, zval *op2, const char *op3, zend_uint op3_len, zval *op4, zval *op5, int self_var);
void zephir_concat_vs(zval *result, zval *op1, const char *op2, zend_uint op2_len, int self_var);
void zephir_concat_vss(zval *result, zval *op1, const char *op2, zend_uint op2_len, const char *op3, zend_uint op3_len, int self_var);
void zephir_concat_vssss(zval *result, zval *op1, const char *op2, zend_uint op2_len, const char *op3, zend_uint op3_len, const char *op4, zend_uint op4_len, const char *op5, zend_uint op5_len, int self_var);
void zephir_concat_vsv(zval *result, zval *op1, const char *op2, zend_uint op2_len, zval *op3, int self_var);
void zephir_concat_vsvs(zval *result, zval *op1, const char *op2, zend_uint op2_len, zval *op3, const char *op4, zend_uint op4_len, int self_var);
void zephir_concat_vv(zval *result, zval *op1, zval *op2, int self_var);
void zephir_concat_vvs(zval *result, zval *op1, zval *op2, const char *op3, zend_uint op3_len, int self_var);
void zephir_concat_vvss(zval *result, zval *op1, zval *op2, const char *op3, zend_uint op3_len, const char *op4, zend_uint op4_len, int self_var);
void zephir_concat_vvsvs(zval *result, zval *op1, zval *op2, const char *op3, zend_uint op3_len, zval *op4, const char *op5, zend_uint op5_len, int self_var);
void zephir_concat_vvvv(zval *result, zval *op1, zval *op2, zval *op3, zval *op4, int self_var);
void zephir_concat_function(zval *result, zval *op1, zval *op2);
#endif /* ZEPHIR_KERNEL_CONCAT_H */
