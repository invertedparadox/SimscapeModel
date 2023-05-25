/* Include files */

#include "vehdynlibeom_sfun.h"
#include "c1_vehdynlibeom.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

/* Forward Declarations */

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtMCInfo c1_emlrtMCI = { 87, /* lineNo */
  33,                                  /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtRSInfo c1_emlrtRSI = { 15, /* lineNo */
  "xdot",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xdot.m"/* pathName */
};

static emlrtRSInfo c1_b_emlrtRSI = { 32,/* lineNo */
  "xdotx",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xdotx.m"/* pathName */
};

static emlrtRSInfo c1_c_emlrtRSI = { 20,/* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRTEInfo c1_emlrtRTEI = { 25,/* lineNo */
  23,                                  /* colNo */
  "dot",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\specfun\\dot.m"/* pName */
};

static emlrtRTEInfo c1_b_emlrtRTEI = { 25,/* lineNo */
  43,                                  /* colNo */
  "dot",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\specfun\\dot.m"/* pName */
};

/* Function Declarations */
static void initialize_c1_vehdynlibeom(SFc1_vehdynlibeomInstanceStruct
  *chartInstance);
static void initialize_params_c1_vehdynlibeom(SFc1_vehdynlibeomInstanceStruct
  *chartInstance);
static void mdl_start_c1_vehdynlibeom(SFc1_vehdynlibeomInstanceStruct
  *chartInstance);
static void mdl_terminate_c1_vehdynlibeom(SFc1_vehdynlibeomInstanceStruct
  *chartInstance);
static void mdl_setup_runtime_resources_c1_vehdynlibeom
  (SFc1_vehdynlibeomInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c1_vehdynlibeom
  (SFc1_vehdynlibeomInstanceStruct *chartInstance);
static void enable_c1_vehdynlibeom(SFc1_vehdynlibeomInstanceStruct
  *chartInstance);
static void disable_c1_vehdynlibeom(SFc1_vehdynlibeomInstanceStruct
  *chartInstance);
static void sf_gateway_c1_vehdynlibeom(SFc1_vehdynlibeomInstanceStruct
  *chartInstance);
static void ext_mode_exec_c1_vehdynlibeom(SFc1_vehdynlibeomInstanceStruct
  *chartInstance);
static void c1_update_jit_animation_c1_vehdynlibeom
  (SFc1_vehdynlibeomInstanceStruct *chartInstance);
static void c1_do_animation_call_c1_vehdynlibeom(SFc1_vehdynlibeomInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c1_vehdynlibeom
  (SFc1_vehdynlibeomInstanceStruct *chartInstance);
static void set_sim_state_c1_vehdynlibeom(SFc1_vehdynlibeomInstanceStruct
  *chartInstance, const mxArray *c1_st);
static void initSimStructsc1_vehdynlibeom(SFc1_vehdynlibeomInstanceStruct
  *chartInstance);
static real_T c1_sumColumnB(SFc1_vehdynlibeomInstanceStruct *chartInstance,
  real_T c1_x[8]);
static real_T c1_b_sumColumnB(SFc1_vehdynlibeomInstanceStruct *chartInstance,
  real_T c1_x[24], int32_T c1_col);
static void c1_emlrt_marshallIn(SFc1_vehdynlibeomInstanceStruct *chartInstance,
  const mxArray *c1_b_HPbar, const char_T *c1_identifier, real_T c1_y[12]);
static void c1_b_emlrt_marshallIn(SFc1_vehdynlibeomInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[12]);
static void c1_c_emlrt_marshallIn(SFc1_vehdynlibeomInstanceStruct *chartInstance,
  const mxArray *c1_b_Ibar, const char_T *c1_identifier, real_T c1_y[9]);
static void c1_d_emlrt_marshallIn(SFc1_vehdynlibeomInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[9]);
static real_T c1_e_emlrt_marshallIn(SFc1_vehdynlibeomInstanceStruct
  *chartInstance, const mxArray *c1_b_Mbar, const char_T *c1_identifier);
static real_T c1_f_emlrt_marshallIn(SFc1_vehdynlibeomInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_g_emlrt_marshallIn(SFc1_vehdynlibeomInstanceStruct *chartInstance,
  const mxArray *c1_b_Rbar, const char_T *c1_identifier, real_T c1_y[3]);
static void c1_h_emlrt_marshallIn(SFc1_vehdynlibeomInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[3]);
static void c1_i_emlrt_marshallIn(SFc1_vehdynlibeomInstanceStruct *chartInstance,
  const mxArray *c1_b_Wbar, const char_T *c1_identifier, real_T c1_y[4]);
static void c1_j_emlrt_marshallIn(SFc1_vehdynlibeomInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[4]);
static uint8_T c1_k_emlrt_marshallIn(SFc1_vehdynlibeomInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_vehdynlibeom, const char_T
  *c1_identifier);
static uint8_T c1_l_emlrt_marshallIn(SFc1_vehdynlibeomInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_slStringInitializeDynamicBuffers(SFc1_vehdynlibeomInstanceStruct *
  chartInstance);
static void c1_chart_data_browse_helper(SFc1_vehdynlibeomInstanceStruct
  *chartInstance, int32_T c1_ssIdNumber, const mxArray **c1_mxData, uint8_T
  *c1_isValueTooBig);
static void init_dsm_address_info(SFc1_vehdynlibeomInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc1_vehdynlibeomInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_vehdynlibeom(SFc1_vehdynlibeomInstanceStruct
  *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_is_active_c1_vehdynlibeom = 0U;
}

static void initialize_params_c1_vehdynlibeom(SFc1_vehdynlibeomInstanceStruct
  *chartInstance)
{
  real_T c1_dv10[9];
  real_T c1_dv11[9];
  real_T c1_dv12[9];
  real_T c1_dv13[9];
  real_T c1_dv6[9];
  real_T c1_dv7[9];
  real_T c1_dv8[9];
  real_T c1_dv9[9];
  real_T c1_dv[3];
  real_T c1_dv1[3];
  real_T c1_dv14[3];
  real_T c1_dv2[3];
  real_T c1_dv3[3];
  real_T c1_dv4[3];
  real_T c1_dv5[3];
  real_T c1_dv15[2];
  real_T c1_b_d;
  real_T c1_d1;
  real_T c1_d10;
  real_T c1_d11;
  real_T c1_d2;
  real_T c1_d3;
  real_T c1_d4;
  real_T c1_d5;
  real_T c1_d6;
  real_T c1_d7;
  real_T c1_d8;
  real_T c1_d9;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  sf_mex_import_named("m", sf_mex_get_sfun_param(chartInstance->S, 5U, 0U),
                      &c1_b_d, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c1_m = c1_b_d;
  sf_mex_import_named("z1m", sf_mex_get_sfun_param(chartInstance->S, 9U, 0U),
                      &c1_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c1_z1m = c1_d1;
  sf_mex_import_named("z2m", sf_mex_get_sfun_param(chartInstance->S, 12U, 0U),
                      &c1_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c1_z2m = c1_d2;
  sf_mex_import_named("z3m", sf_mex_get_sfun_param(chartInstance->S, 15U, 0U),
                      &c1_d3, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c1_z3m = c1_d3;
  sf_mex_import_named("z4m", sf_mex_get_sfun_param(chartInstance->S, 18U, 0U),
                      &c1_d4, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c1_z4m = c1_d4;
  sf_mex_import_named("z5m", sf_mex_get_sfun_param(chartInstance->S, 21U, 0U),
                      &c1_d5, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c1_z5m = c1_d5;
  sf_mex_import_named("z6m", sf_mex_get_sfun_param(chartInstance->S, 24U, 0U),
                      &c1_d6, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c1_z6m = c1_d6;
  sf_mex_import_named("z7m", sf_mex_get_sfun_param(chartInstance->S, 27U, 0U),
                      &c1_d7, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c1_z7m = c1_d7;
  sf_mex_import_named("z1R", sf_mex_get_sfun_param(chartInstance->S, 8U, 0U),
                      c1_dv, 0, 0, 0U, 1, 0U, 2, 1, 3);
  for (c1_i = 0; c1_i < 3; c1_i++) {
    chartInstance->c1_z1R[c1_i] = c1_dv[c1_i];
  }

  sf_mex_import_named("z2R", sf_mex_get_sfun_param(chartInstance->S, 11U, 0U),
                      c1_dv1, 0, 0, 0U, 1, 0U, 2, 1, 3);
  for (c1_i1 = 0; c1_i1 < 3; c1_i1++) {
    chartInstance->c1_z2R[c1_i1] = c1_dv1[c1_i1];
  }

  sf_mex_import_named("z3R", sf_mex_get_sfun_param(chartInstance->S, 14U, 0U),
                      c1_dv2, 0, 0, 0U, 1, 0U, 2, 1, 3);
  for (c1_i2 = 0; c1_i2 < 3; c1_i2++) {
    chartInstance->c1_z3R[c1_i2] = c1_dv2[c1_i2];
  }

  sf_mex_import_named("z4R", sf_mex_get_sfun_param(chartInstance->S, 17U, 0U),
                      c1_dv3, 0, 0, 0U, 1, 0U, 2, 1, 3);
  for (c1_i3 = 0; c1_i3 < 3; c1_i3++) {
    chartInstance->c1_z4R[c1_i3] = c1_dv3[c1_i3];
  }

  sf_mex_import_named("z5R", sf_mex_get_sfun_param(chartInstance->S, 20U, 0U),
                      c1_dv4, 0, 0, 0U, 1, 0U, 2, 1, 3);
  for (c1_i4 = 0; c1_i4 < 3; c1_i4++) {
    chartInstance->c1_z5R[c1_i4] = c1_dv4[c1_i4];
  }

  sf_mex_import_named("z6R", sf_mex_get_sfun_param(chartInstance->S, 23U, 0U),
                      c1_dv5, 0, 0, 0U, 1, 0U, 2, 1, 3);
  for (c1_i5 = 0; c1_i5 < 3; c1_i5++) {
    chartInstance->c1_z6R[c1_i5] = c1_dv5[c1_i5];
  }

  sf_mex_import_named("Iveh", sf_mex_get_sfun_param(chartInstance->S, 0U, 0U),
                      c1_dv6, 0, 0, 0U, 1, 0U, 2, 3, 3);
  for (c1_i6 = 0; c1_i6 < 9; c1_i6++) {
    chartInstance->c1_Iveh[c1_i6] = c1_dv6[c1_i6];
  }

  sf_mex_import_named("z1I", sf_mex_get_sfun_param(chartInstance->S, 7U, 0U),
                      c1_dv7, 0, 0, 0U, 1, 0U, 2, 3, 3);
  for (c1_i7 = 0; c1_i7 < 9; c1_i7++) {
    chartInstance->c1_z1I[c1_i7] = c1_dv7[c1_i7];
  }

  sf_mex_import_named("z2I", sf_mex_get_sfun_param(chartInstance->S, 10U, 0U),
                      c1_dv8, 0, 0, 0U, 1, 0U, 2, 3, 3);
  for (c1_i8 = 0; c1_i8 < 9; c1_i8++) {
    chartInstance->c1_z2I[c1_i8] = c1_dv8[c1_i8];
  }

  sf_mex_import_named("z3I", sf_mex_get_sfun_param(chartInstance->S, 13U, 0U),
                      c1_dv9, 0, 0, 0U, 1, 0U, 2, 3, 3);
  for (c1_i9 = 0; c1_i9 < 9; c1_i9++) {
    chartInstance->c1_z3I[c1_i9] = c1_dv9[c1_i9];
  }

  sf_mex_import_named("z4I", sf_mex_get_sfun_param(chartInstance->S, 16U, 0U),
                      c1_dv10, 0, 0, 0U, 1, 0U, 2, 3, 3);
  for (c1_i10 = 0; c1_i10 < 9; c1_i10++) {
    chartInstance->c1_z4I[c1_i10] = c1_dv10[c1_i10];
  }

  sf_mex_import_named("z5I", sf_mex_get_sfun_param(chartInstance->S, 19U, 0U),
                      c1_dv11, 0, 0, 0U, 1, 0U, 2, 3, 3);
  for (c1_i11 = 0; c1_i11 < 9; c1_i11++) {
    chartInstance->c1_z5I[c1_i11] = c1_dv11[c1_i11];
  }

  sf_mex_import_named("z6I", sf_mex_get_sfun_param(chartInstance->S, 22U, 0U),
                      c1_dv12, 0, 0, 0U, 1, 0U, 2, 3, 3);
  for (c1_i12 = 0; c1_i12 < 9; c1_i12++) {
    chartInstance->c1_z6I[c1_i12] = c1_dv12[c1_i12];
  }

  sf_mex_import_named("z7I", sf_mex_get_sfun_param(chartInstance->S, 25U, 0U),
                      c1_dv13, 0, 0, 0U, 1, 0U, 2, 3, 3);
  for (c1_i13 = 0; c1_i13 < 9; c1_i13++) {
    chartInstance->c1_z7I[c1_i13] = c1_dv13[c1_i13];
  }

  sf_mex_import_named("z7R", sf_mex_get_sfun_param(chartInstance->S, 26U, 0U),
                      c1_dv14, 0, 0, 0U, 1, 0U, 2, 1, 3);
  for (c1_i14 = 0; c1_i14 < 3; c1_i14++) {
    chartInstance->c1_z7R[c1_i14] = c1_dv14[c1_i14];
  }

  sf_mex_import_named("a", sf_mex_get_sfun_param(chartInstance->S, 1U, 0U),
                      &c1_d8, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c1_a = c1_d8;
  sf_mex_import_named("b", sf_mex_get_sfun_param(chartInstance->S, 2U, 0U),
                      &c1_d9, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c1_b = c1_d9;
  sf_mex_import_named("h", sf_mex_get_sfun_param(chartInstance->S, 4U, 0U),
                      &c1_d10, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c1_h = c1_d10;
  sf_mex_import_named("w", sf_mex_get_sfun_param(chartInstance->S, 6U, 0U),
                      c1_dv15, 0, 0, 0U, 1, 0U, 1, 2);
  for (c1_i15 = 0; c1_i15 < 2; c1_i15++) {
    chartInstance->c1_w[c1_i15] = c1_dv15[c1_i15];
  }

  sf_mex_import_named("d", sf_mex_get_sfun_param(chartInstance->S, 3U, 0U),
                      &c1_d11, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c1_d = c1_d11;
}

static void mdl_start_c1_vehdynlibeom(SFc1_vehdynlibeomInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void mdl_terminate_c1_vehdynlibeom(SFc1_vehdynlibeomInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c1_vehdynlibeom
  (SFc1_vehdynlibeomInstanceStruct *chartInstance)
{
  static const uint32_T c1_decisionTxtEndIdx = 0U;
  static const uint32_T c1_decisionTxtStartIdx = 0U;
  setDebuggerFlag(chartInstance->S, true);
  setDataBrowseFcn(chartInstance->S, (void *)&c1_chart_data_browse_helper);
  chartInstance->c1_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c1_RuntimeVar,
    &chartInstance->c1_IsDebuggerActive,
    &chartInstance->c1_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c1_mlFcnLineNumber, &chartInstance->c1_IsHeatMapPresent, 0);
  sim_mode_is_external(chartInstance->S);
  covrtCreateStateflowInstanceData(chartInstance->c1_covrtInstance, 1U, 0U, 1U,
    251U);
  covrtChartInitFcn(chartInstance->c1_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c1_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c1_decisionTxtStartIdx, &c1_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c1_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c1_covrtInstance, "", 4U, 0U, 1U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 395);
}

static void mdl_cleanup_runtime_resources_c1_vehdynlibeom
  (SFc1_vehdynlibeomInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c1_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c1_covrtInstance);
}

static void enable_c1_vehdynlibeom(SFc1_vehdynlibeomInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_vehdynlibeom(SFc1_vehdynlibeomInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c1_vehdynlibeom(SFc1_vehdynlibeomInstanceStruct
  *chartInstance)
{
  static real_T c1_dv1[9] = { 1.0, -1.0, -1.0, -1.0, 1.0, -1.0, -1.0, -1.0, 1.0
  };

  static real_T c1_h_b[9] = { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 };

  static real_T c1_dv[3] = { -1.0, 1.0, -1.0 };

  ptrdiff_t c1_incx_t;
  ptrdiff_t c1_incy_t;
  ptrdiff_t c1_n_t;
  real_T c1_Imat[72];
  real_T c1_Itemp[72];
  real_T c1_R[24];
  real_T c1_f_b[24];
  real_T c1_Rload[21];
  real_T c1_d_b[21];
  real_T c1_e_b[21];
  real_T c1_b_y[9];
  real_T c1_c_y[9];
  real_T c1_M[8];
  real_T c1_a_data[3];
  real_T c1_b_data[3];
  real_T c1_d_a[3];
  real_T c1_e_a[3];
  real_T c1_g_b[3];
  real_T c1_b_w[2];
  real_T c1_b_M;
  real_T c1_b_Mbar;
  real_T c1_b_a;
  real_T c1_b_b;
  real_T c1_b_d;
  real_T c1_b_h;
  real_T c1_b_idx;
  real_T c1_b_m;
  real_T c1_b_z1m;
  real_T c1_b_z2m;
  real_T c1_b_z3m;
  real_T c1_b_z4m;
  real_T c1_b_z5m;
  real_T c1_b_z6m;
  real_T c1_b_z7m;
  real_T c1_c_Mbar;
  real_T c1_c_a;
  real_T c1_c_b;
  real_T c1_c_d;
  real_T c1_c_h;
  real_T c1_c_m;
  real_T c1_c_z1m;
  real_T c1_c_z2m;
  real_T c1_c_z3m;
  real_T c1_c_z4m;
  real_T c1_c_z5m;
  real_T c1_c_z6m;
  real_T c1_c_z7m;
  real_T c1_f_a;
  real_T c1_y;
  int32_T c1_b_col;
  int32_T c1_b_iacol;
  int32_T c1_b_ibcol;
  int32_T c1_b_ibmat;
  int32_T c1_b_itilerow;
  int32_T c1_b_j;
  int32_T c1_b_jcol;
  int32_T c1_b_jtilecol;
  int32_T c1_b_k;
  int32_T c1_b_xj;
  int32_T c1_c_iacol;
  int32_T c1_c_ibcol;
  int32_T c1_c_ibmat;
  int32_T c1_c_idx;
  int32_T c1_c_itilerow;
  int32_T c1_c_j;
  int32_T c1_c_jcol;
  int32_T c1_c_k;
  int32_T c1_c_xj;
  int32_T c1_col;
  int32_T c1_d_idx;
  int32_T c1_d_itilerow;
  int32_T c1_d_j;
  int32_T c1_d_jcol;
  int32_T c1_e_idx;
  int32_T c1_e_itilerow;
  int32_T c1_e_j;
  int32_T c1_e_jcol;
  int32_T c1_f_idx;
  int32_T c1_f_itilerow;
  int32_T c1_f_j;
  int32_T c1_f_jcol;
  int32_T c1_g_idx;
  int32_T c1_g_j;
  int32_T c1_h_idx;
  int32_T c1_h_j;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i2;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  int32_T c1_i3;
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_i32;
  int32_T c1_i33;
  int32_T c1_i34;
  int32_T c1_i35;
  int32_T c1_i36;
  int32_T c1_i37;
  int32_T c1_i38;
  int32_T c1_i39;
  int32_T c1_i4;
  int32_T c1_i40;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_i_j;
  int32_T c1_iacol;
  int32_T c1_ibcol;
  int32_T c1_ibmat;
  int32_T c1_ibtile;
  int32_T c1_idx;
  int32_T c1_itilerow;
  int32_T c1_ix;
  int32_T c1_iy;
  int32_T c1_j;
  int32_T c1_jcol;
  int32_T c1_jtilecol;
  int32_T c1_k;
  int32_T c1_xj;
  int32_T c1_xoffset;
  chartInstance->c1_JITTransitionAnimation[0] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_b_m = chartInstance->c1_m;
  c1_b_z1m = chartInstance->c1_z1m;
  c1_b_z2m = chartInstance->c1_z2m;
  c1_b_z3m = chartInstance->c1_z3m;
  c1_b_z4m = chartInstance->c1_z4m;
  c1_b_z5m = chartInstance->c1_z5m;
  c1_b_z6m = chartInstance->c1_z6m;
  c1_b_z7m = chartInstance->c1_z7m;
  c1_b_a = chartInstance->c1_a;
  c1_b_b = chartInstance->c1_b;
  c1_b_h = chartInstance->c1_h;
  c1_b_d = chartInstance->c1_d;
  covrtEmlFcnEval(chartInstance->c1_covrtInstance, 4U, 0, 0);
  c1_c_m = c1_b_m;
  c1_c_z1m = c1_b_z1m;
  c1_c_z2m = c1_b_z2m;
  c1_c_z3m = c1_b_z3m;
  c1_c_z4m = c1_b_z4m;
  c1_c_z5m = c1_b_z5m;
  c1_c_z6m = c1_b_z6m;
  c1_c_z7m = c1_b_z7m;
  c1_c_a = c1_b_a;
  c1_c_b = c1_b_b;
  c1_c_h = c1_b_h;
  for (c1_i = 0; c1_i < 2; c1_i++) {
    c1_b_w[c1_i] = chartInstance->c1_w[c1_i];
  }

  c1_c_d = c1_b_d;
  c1_d_a[0] = c1_c_a;
  c1_d_a[1] = -c1_c_d;
  c1_d_a[2] = c1_c_h;
  for (c1_jcol = 0; c1_jcol < 3; c1_jcol++) {
    c1_c_jcol = c1_jcol;
    c1_iacol = c1_c_jcol;
    c1_ibmat = c1_c_jcol * 7 - 1;
    for (c1_itilerow = 0; c1_itilerow < 7; c1_itilerow++) {
      c1_c_itilerow = c1_itilerow;
      c1_ibcol = c1_ibmat + c1_c_itilerow;
      c1_d_b[c1_ibcol + 1] = c1_d_a[c1_iacol];
    }
  }

  for (c1_b_jcol = 0; c1_b_jcol < 3; c1_b_jcol++) {
    c1_d_jcol = c1_b_jcol;
    c1_b_iacol = c1_d_jcol;
    c1_b_ibmat = c1_d_jcol * 7 - 1;
    for (c1_b_itilerow = 0; c1_b_itilerow < 7; c1_b_itilerow++) {
      c1_d_itilerow = c1_b_itilerow;
      c1_b_ibcol = c1_b_ibmat + c1_d_itilerow;
      c1_e_b[c1_b_ibcol + 1] = c1_dv[c1_b_iacol];
    }
  }

  c1_i1 = 0;
  for (c1_i2 = 0; c1_i2 < 3; c1_i2++) {
    c1_Rload[c1_i1] = c1_d_b[c1_i1] + chartInstance->c1_z1R[c1_i2] *
      c1_e_b[c1_i1];
    c1_i1 += 7;
  }

  c1_i3 = 0;
  for (c1_i4 = 0; c1_i4 < 3; c1_i4++) {
    c1_Rload[c1_i3 + 1] = c1_d_b[c1_i3 + 1] + chartInstance->c1_z2R[c1_i4] *
      c1_e_b[c1_i3 + 1];
    c1_i3 += 7;
  }

  c1_i5 = 0;
  for (c1_i6 = 0; c1_i6 < 3; c1_i6++) {
    c1_Rload[c1_i5 + 2] = c1_d_b[c1_i5 + 2] + chartInstance->c1_z3R[c1_i6] *
      c1_e_b[c1_i5 + 2];
    c1_i5 += 7;
  }

  c1_i7 = 0;
  for (c1_i8 = 0; c1_i8 < 3; c1_i8++) {
    c1_Rload[c1_i7 + 3] = c1_d_b[c1_i7 + 3] + chartInstance->c1_z4R[c1_i8] *
      c1_e_b[c1_i7 + 3];
    c1_i7 += 7;
  }

  c1_i9 = 0;
  for (c1_i10 = 0; c1_i10 < 3; c1_i10++) {
    c1_Rload[c1_i9 + 4] = c1_d_b[c1_i9 + 4] + chartInstance->c1_z5R[c1_i10] *
      c1_e_b[c1_i9 + 4];
    c1_i9 += 7;
  }

  c1_i11 = 0;
  for (c1_i12 = 0; c1_i12 < 3; c1_i12++) {
    c1_Rload[c1_i11 + 5] = c1_d_b[c1_i11 + 5] + chartInstance->c1_z6R[c1_i12] *
      c1_e_b[c1_i11 + 5];
    c1_i11 += 7;
  }

  c1_i13 = 0;
  for (c1_i14 = 0; c1_i14 < 3; c1_i14++) {
    c1_Rload[c1_i13 + 6] = c1_d_b[c1_i13 + 6] + chartInstance->c1_z7R[c1_i14] *
      c1_e_b[c1_i13 + 6];
    c1_i13 += 7;
  }

  c1_i15 = 0;
  for (c1_i16 = 0; c1_i16 < 3; c1_i16++) {
    c1_R[c1_i15] = 0.0;
    c1_i15 += 8;
  }

  c1_i17 = 0;
  c1_i18 = 0;
  for (c1_i19 = 0; c1_i19 < 3; c1_i19++) {
    for (c1_i20 = 0; c1_i20 < 7; c1_i20++) {
      c1_R[(c1_i20 + c1_i17) + 1] = c1_Rload[c1_i20 + c1_i18];
    }

    c1_i17 += 8;
    c1_i18 += 7;
  }

  c1_M[0] = c1_c_m;
  c1_M[1] = c1_c_z1m;
  c1_M[2] = c1_c_z2m;
  c1_M[3] = c1_c_z3m;
  c1_M[4] = c1_c_z4m;
  c1_M[5] = c1_c_z5m;
  c1_M[6] = c1_c_z6m;
  c1_M[7] = c1_c_z7m;
  c1_iy = -1;
  for (c1_j = 0; c1_j < 9; c1_j++) {
    c1_c_j = c1_j;
    c1_iy++;
    c1_Imat[c1_iy] = chartInstance->c1_Iveh[c1_c_j];
  }

  for (c1_b_j = 0; c1_b_j < 9; c1_b_j++) {
    c1_c_j = c1_b_j;
    c1_iy++;
    c1_Imat[c1_iy] = chartInstance->c1_z1I[c1_c_j];
  }

  for (c1_d_j = 0; c1_d_j < 9; c1_d_j++) {
    c1_c_j = c1_d_j;
    c1_iy++;
    c1_Imat[c1_iy] = chartInstance->c1_z2I[c1_c_j];
  }

  for (c1_e_j = 0; c1_e_j < 9; c1_e_j++) {
    c1_c_j = c1_e_j;
    c1_iy++;
    c1_Imat[c1_iy] = chartInstance->c1_z3I[c1_c_j];
  }

  for (c1_f_j = 0; c1_f_j < 9; c1_f_j++) {
    c1_c_j = c1_f_j;
    c1_iy++;
    c1_Imat[c1_iy] = chartInstance->c1_z4I[c1_c_j];
  }

  for (c1_g_j = 0; c1_g_j < 9; c1_g_j++) {
    c1_c_j = c1_g_j;
    c1_iy++;
    c1_Imat[c1_iy] = chartInstance->c1_z5I[c1_c_j];
  }

  for (c1_h_j = 0; c1_h_j < 9; c1_h_j++) {
    c1_c_j = c1_h_j;
    c1_iy++;
    c1_Imat[c1_iy] = chartInstance->c1_z6I[c1_c_j];
  }

  for (c1_i_j = 0; c1_i_j < 9; c1_i_j++) {
    c1_c_j = c1_i_j;
    c1_iy++;
    c1_Imat[c1_iy] = chartInstance->c1_z7I[c1_c_j];
  }

  for (c1_jtilecol = 0; c1_jtilecol < 3; c1_jtilecol++) {
    c1_b_jtilecol = c1_jtilecol;
    c1_ibtile = (c1_b_jtilecol << 3) - 1;
    for (c1_k = 0; c1_k < 8; c1_k++) {
      c1_b_k = c1_k;
      c1_f_b[(c1_ibtile + c1_b_k) + 1] = c1_M[c1_b_k];
    }
  }

  c1_y = c1_sumColumnB(chartInstance, c1_M);
  for (c1_i21 = 0; c1_i21 < 24; c1_i21++) {
    c1_f_b[c1_i21] = c1_f_b[c1_i21] * c1_R[c1_i21] / c1_y;
  }

  for (c1_col = 0; c1_col < 3; c1_col++) {
    c1_b_col = c1_col;
    (*chartInstance->c1_Rbar)[c1_b_col] = c1_b_sumColumnB(chartInstance, c1_f_b,
      c1_b_col + 1);
  }

  c1_b_Mbar = c1_sumColumnB(chartInstance, c1_M);
  for (c1_e_jcol = 0; c1_e_jcol < 3; c1_e_jcol++) {
    c1_f_jcol = c1_e_jcol;
    c1_c_iacol = c1_f_jcol;
    c1_c_ibmat = (c1_f_jcol << 3) - 1;
    for (c1_e_itilerow = 0; c1_e_itilerow < 8; c1_e_itilerow++) {
      c1_f_itilerow = c1_e_itilerow;
      c1_c_ibcol = c1_c_ibmat + c1_f_itilerow;
      c1_f_b[c1_c_ibcol + 1] = (*chartInstance->c1_Rbar)[c1_c_iacol];
    }
  }

  for (c1_i22 = 0; c1_i22 < 24; c1_i22++) {
    c1_R[c1_i22] -= c1_f_b[c1_i22];
  }

  for (c1_idx = 0; c1_idx < 8; c1_idx++) {
    c1_b_idx = (real_T)c1_idx + 1.0;
    c1_c_idx = (int32_T)c1_b_idx - 1;
    for (c1_i23 = 0; c1_i23 < 3; c1_i23++) {
      c1_e_a[c1_i23] = c1_R[c1_c_idx + (c1_i23 << 3)];
    }

    c1_d_idx = (int32_T)c1_b_idx - 1;
    for (c1_i24 = 0; c1_i24 < 3; c1_i24++) {
      c1_d_a[c1_i24] = c1_R[c1_d_idx + (c1_i24 << 3)];
    }

    c1_e_idx = (int32_T)c1_b_idx - 1;
    for (c1_i26 = 0; c1_i26 < 3; c1_i26++) {
      c1_g_b[c1_i26] = c1_R[c1_e_idx + (c1_i26 << 3)];
    }

    for (c1_i27 = 0; c1_i27 < 3; c1_i27++) {
      c1_a_data[c1_i27] = c1_d_a[c1_i27];
    }

    for (c1_i28 = 0; c1_i28 < 3; c1_i28++) {
      c1_b_data[c1_i28] = c1_g_b[c1_i28];
    }

    c1_n_t = (ptrdiff_t)3;
    c1_incx_t = (ptrdiff_t)1;
    c1_incy_t = (ptrdiff_t)1;
    c1_f_a = ddot(&c1_n_t, &c1_a_data[0], &c1_incx_t, &c1_b_data[0], &c1_incy_t);
    for (c1_i29 = 0; c1_i29 < 9; c1_i29++) {
      c1_b_y[c1_i29] = c1_f_a * c1_h_b[c1_i29];
    }

    c1_f_idx = (int32_T)c1_b_idx - 1;
    for (c1_i30 = 0; c1_i30 < 3; c1_i30++) {
      c1_g_b[c1_i30] = c1_R[c1_f_idx + (c1_i30 << 3)];
    }

    c1_i31 = 0;
    for (c1_i32 = 0; c1_i32 < 3; c1_i32++) {
      for (c1_i33 = 0; c1_i33 < 3; c1_i33++) {
        c1_c_y[c1_i33 + c1_i31] = c1_e_a[c1_i33] * c1_g_b[c1_i32];
      }

      c1_i31 += 3;
    }

    c1_g_idx = (int32_T)c1_b_idx - 1;
    c1_b_M = c1_M[(int32_T)c1_b_idx - 1];
    c1_h_idx = (int32_T)c1_b_idx - 1;
    for (c1_i35 = 0; c1_i35 < 3; c1_i35++) {
      for (c1_i37 = 0; c1_i37 < 3; c1_i37++) {
        c1_Itemp[(c1_i37 + 3 * c1_i35) + 9 * c1_h_idx] = c1_Imat[(c1_i37 + 3 *
          c1_i35) + 9 * c1_g_idx] + c1_b_M * (c1_b_y[c1_i37 + 3 * c1_i35] -
          c1_c_y[c1_i37 + 3 * c1_i35]) * c1_dv1[c1_i37 + 3 * c1_i35];
      }
    }
  }

  for (c1_xj = 0; c1_xj < 9; c1_xj++) {
    c1_b_xj = c1_xj;
    (*chartInstance->c1_Ibar)[c1_b_xj] = c1_Itemp[c1_b_xj];
  }

  for (c1_c_k = 0; c1_c_k < 7; c1_c_k++) {
    c1_xoffset = (c1_c_k + 1) * 9;
    for (c1_c_xj = 0; c1_c_xj < 9; c1_c_xj++) {
      c1_b_xj = c1_c_xj;
      c1_ix = c1_xoffset + c1_b_xj;
      (*chartInstance->c1_Ibar)[c1_b_xj] += c1_Itemp[c1_ix];
    }
  }

  c1_c_Mbar = c1_b_Mbar;
  (*chartInstance->c1_Xbar)[0] = c1_c_a - (*chartInstance->c1_Rbar)[0];
  (*chartInstance->c1_Xbar)[1] = c1_c_b + (*chartInstance->c1_Rbar)[0];
  (*chartInstance->c1_Xbar)[2] = c1_c_h - (*chartInstance->c1_Rbar)[2];
  for (c1_i25 = 0; c1_i25 < 2; c1_i25++) {
    c1_b_w[c1_i25] /= 2.0;
  }

  (*chartInstance->c1_Wbar)[0] = c1_b_w[0] + (*chartInstance->c1_Rbar)[1];
  (*chartInstance->c1_Wbar)[1] = c1_b_w[0] - (*chartInstance->c1_Rbar)[1];
  (*chartInstance->c1_Wbar)[2] = c1_b_w[1] + (*chartInstance->c1_Rbar)[1];
  (*chartInstance->c1_Wbar)[3] = c1_b_w[1] - (*chartInstance->c1_Rbar)[1];
  (*chartInstance->c1_HPbar)[0] = (*chartInstance->c1_Xbar)[0];
  (*chartInstance->c1_HPbar)[3] = (*chartInstance->c1_Xbar)[0];
  (*chartInstance->c1_HPbar)[6] = -(*chartInstance->c1_Xbar)[1];
  (*chartInstance->c1_HPbar)[9] = -(*chartInstance->c1_Xbar)[1];
  (*chartInstance->c1_HPbar)[1] = -(*chartInstance->c1_Wbar)[0];
  (*chartInstance->c1_HPbar)[4] = (*chartInstance->c1_Wbar)[1];
  (*chartInstance->c1_HPbar)[7] = -(*chartInstance->c1_Wbar)[2];
  (*chartInstance->c1_HPbar)[10] = (*chartInstance->c1_Wbar)[3];
  (*chartInstance->c1_HPbar)[2] = (*chartInstance->c1_Xbar)[2];
  (*chartInstance->c1_HPbar)[5] = (*chartInstance->c1_Xbar)[2];
  (*chartInstance->c1_HPbar)[8] = (*chartInstance->c1_Xbar)[2];
  (*chartInstance->c1_HPbar)[11] = (*chartInstance->c1_Xbar)[2];
  *chartInstance->c1_Mbar = c1_c_Mbar;
  c1_do_animation_call_c1_vehdynlibeom(chartInstance);
  covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 0U, *chartInstance->c1_Mbar);
  for (c1_i34 = 0; c1_i34 < 9; c1_i34++) {
    covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 1U,
                      (*chartInstance->c1_Ibar)[c1_i34]);
  }

  for (c1_i36 = 0; c1_i36 < 3; c1_i36++) {
    covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 2U,
                      (*chartInstance->c1_Rbar)[c1_i36]);
  }

  for (c1_i38 = 0; c1_i38 < 3; c1_i38++) {
    covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 3U,
                      (*chartInstance->c1_Xbar)[c1_i38]);
  }

  for (c1_i39 = 0; c1_i39 < 4; c1_i39++) {
    covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 4U,
                      (*chartInstance->c1_Wbar)[c1_i39]);
  }

  for (c1_i40 = 0; c1_i40 < 12; c1_i40++) {
    covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 5U,
                      (*chartInstance->c1_HPbar)[c1_i40]);
  }
}

static void ext_mode_exec_c1_vehdynlibeom(SFc1_vehdynlibeomInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c1_update_jit_animation_c1_vehdynlibeom
  (SFc1_vehdynlibeomInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_do_animation_call_c1_vehdynlibeom(SFc1_vehdynlibeomInstanceStruct
  *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static const mxArray *get_sim_state_c1_vehdynlibeom
  (SFc1_vehdynlibeomInstanceStruct *chartInstance)
{
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  const mxArray *c1_e_y = NULL;
  const mxArray *c1_f_y = NULL;
  const mxArray *c1_g_y = NULL;
  const mxArray *c1_h_y = NULL;
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(7, 1), false);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", *chartInstance->c1_HPbar, 0, 0U, 1U,
    0U, 2, 3, 4), false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", *chartInstance->c1_Ibar, 0, 0U, 1U,
    0U, 2, 3, 3), false);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", chartInstance->c1_Mbar, 0, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", *chartInstance->c1_Rbar, 0, 0U, 1U,
    0U, 2, 1, 3), false);
  sf_mex_setcell(c1_y, 3, c1_e_y);
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", *chartInstance->c1_Wbar, 0, 0U, 1U,
    0U, 2, 1, 4), false);
  sf_mex_setcell(c1_y, 4, c1_f_y);
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", *chartInstance->c1_Xbar, 0, 0U, 1U,
    0U, 2, 1, 3), false);
  sf_mex_setcell(c1_y, 5, c1_g_y);
  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y",
    &chartInstance->c1_is_active_c1_vehdynlibeom, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 6, c1_h_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_vehdynlibeom(SFc1_vehdynlibeomInstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv[12];
  real_T c1_dv1[9];
  real_T c1_dv3[4];
  real_T c1_dv2[3];
  real_T c1_dv4[3];
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
                      "HPbar", c1_dv);
  for (c1_i = 0; c1_i < 12; c1_i++) {
    (*chartInstance->c1_HPbar)[c1_i] = c1_dv[c1_i];
  }

  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
                        "Ibar", c1_dv1);
  for (c1_i1 = 0; c1_i1 < 9; c1_i1++) {
    (*chartInstance->c1_Ibar)[c1_i1] = c1_dv1[c1_i1];
  }

  *chartInstance->c1_Mbar = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 2)), "Mbar");
  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 3)),
                        "Rbar", c1_dv2);
  for (c1_i2 = 0; c1_i2 < 3; c1_i2++) {
    (*chartInstance->c1_Rbar)[c1_i2] = c1_dv2[c1_i2];
  }

  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 4)),
                        "Wbar", c1_dv3);
  for (c1_i3 = 0; c1_i3 < 4; c1_i3++) {
    (*chartInstance->c1_Wbar)[c1_i3] = c1_dv3[c1_i3];
  }

  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 5)),
                        "Xbar", c1_dv4);
  for (c1_i4 = 0; c1_i4 < 3; c1_i4++) {
    (*chartInstance->c1_Xbar)[c1_i4] = c1_dv4[c1_i4];
  }

  chartInstance->c1_is_active_c1_vehdynlibeom = c1_k_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 6)),
     "is_active_c1_vehdynlibeom");
  sf_mex_destroy(&c1_u);
  sf_mex_destroy(&c1_st);
}

static void initSimStructsc1_vehdynlibeom(SFc1_vehdynlibeomInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

const mxArray *sf_c1_vehdynlibeom_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c1_nameCaptureInfo;
}

static real_T c1_sumColumnB(SFc1_vehdynlibeomInstanceStruct *chartInstance,
  real_T c1_x[8])
{
  real_T c1_y;
  int32_T c1_b_k;
  int32_T c1_k;
  (void)chartInstance;
  c1_y = c1_x[0];
  for (c1_k = 0; c1_k < 7; c1_k++) {
    c1_b_k = c1_k;
    c1_y += c1_x[c1_b_k + 1];
  }

  return c1_y;
}

static real_T c1_b_sumColumnB(SFc1_vehdynlibeomInstanceStruct *chartInstance,
  real_T c1_x[24], int32_T c1_col)
{
  real_T c1_y;
  int32_T c1_b_col;
  int32_T c1_b_k;
  int32_T c1_i0;
  int32_T c1_k;
  (void)chartInstance;
  c1_b_col = c1_col - 1;
  c1_i0 = c1_b_col << 3;
  c1_y = c1_x[c1_i0];
  for (c1_k = 0; c1_k < 7; c1_k++) {
    c1_b_k = c1_k;
    c1_y += c1_x[(c1_i0 + c1_b_k) + 1];
  }

  return c1_y;
}

static void c1_emlrt_marshallIn(SFc1_vehdynlibeomInstanceStruct *chartInstance,
  const mxArray *c1_b_HPbar, const char_T *c1_identifier, real_T c1_y[12])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_HPbar), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_HPbar);
}

static void c1_b_emlrt_marshallIn(SFc1_vehdynlibeomInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[12])
{
  real_T c1_dv[12];
  int32_T c1_i;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv, 1, 0, 0U, 1, 0U, 2, 3, 4);
  for (c1_i = 0; c1_i < 12; c1_i++) {
    c1_y[c1_i] = c1_dv[c1_i];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_c_emlrt_marshallIn(SFc1_vehdynlibeomInstanceStruct *chartInstance,
  const mxArray *c1_b_Ibar, const char_T *c1_identifier, real_T c1_y[9])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_Ibar), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_Ibar);
}

static void c1_d_emlrt_marshallIn(SFc1_vehdynlibeomInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[9])
{
  real_T c1_dv[9];
  int32_T c1_i;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c1_i = 0; c1_i < 9; c1_i++) {
    c1_y[c1_i] = c1_dv[c1_i];
  }

  sf_mex_destroy(&c1_u);
}

static real_T c1_e_emlrt_marshallIn(SFc1_vehdynlibeomInstanceStruct
  *chartInstance, const mxArray *c1_b_Mbar, const char_T *c1_identifier)
{
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_Mbar), &c1_thisId);
  sf_mex_destroy(&c1_b_Mbar);
  return c1_y;
}

static real_T c1_f_emlrt_marshallIn(SFc1_vehdynlibeomInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_b_d;
  real_T c1_y;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_b_d, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_b_d;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_g_emlrt_marshallIn(SFc1_vehdynlibeomInstanceStruct *chartInstance,
  const mxArray *c1_b_Rbar, const char_T *c1_identifier, real_T c1_y[3])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_Rbar), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_Rbar);
}

static void c1_h_emlrt_marshallIn(SFc1_vehdynlibeomInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[3])
{
  real_T c1_dv[3];
  int32_T c1_i;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv, 1, 0, 0U, 1, 0U, 2, 1, 3);
  for (c1_i = 0; c1_i < 3; c1_i++) {
    c1_y[c1_i] = c1_dv[c1_i];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_i_emlrt_marshallIn(SFc1_vehdynlibeomInstanceStruct *chartInstance,
  const mxArray *c1_b_Wbar, const char_T *c1_identifier, real_T c1_y[4])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_Wbar), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_Wbar);
}

static void c1_j_emlrt_marshallIn(SFc1_vehdynlibeomInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[4])
{
  real_T c1_dv[4];
  int32_T c1_i;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv, 1, 0, 0U, 1, 0U, 2, 1, 4);
  for (c1_i = 0; c1_i < 4; c1_i++) {
    c1_y[c1_i] = c1_dv[c1_i];
  }

  sf_mex_destroy(&c1_u);
}

static uint8_T c1_k_emlrt_marshallIn(SFc1_vehdynlibeomInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_vehdynlibeom, const char_T
  *c1_identifier)
{
  emlrtMsgIdentifier c1_thisId;
  uint8_T c1_y;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_vehdynlibeom), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_vehdynlibeom);
  return c1_y;
}

static uint8_T c1_l_emlrt_marshallIn(SFc1_vehdynlibeomInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_b_u;
  uint8_T c1_y;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_b_u, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_b_u;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_slStringInitializeDynamicBuffers(SFc1_vehdynlibeomInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void c1_chart_data_browse_helper(SFc1_vehdynlibeomInstanceStruct
  *chartInstance, int32_T c1_ssIdNumber, const mxArray **c1_mxData, uint8_T
  *c1_isValueTooBig)
{
  real_T c1_b_d;
  *c1_mxData = NULL;
  *c1_mxData = NULL;
  *c1_isValueTooBig = 0U;
  switch (c1_ssIdNumber) {
   case 15U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", &chartInstance->c1_m, 0, 0U,
      0U, 0U, 0), false);
    break;

   case 5U:
    c1_b_d = *chartInstance->c1_Mbar;
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", &c1_b_d, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 4U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", &chartInstance->c1_z1m, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 6U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", &chartInstance->c1_z2m, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 7U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", &chartInstance->c1_z3m, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 8U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", &chartInstance->c1_z4m, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 9U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", &chartInstance->c1_z5m, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 10U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", &chartInstance->c1_z6m, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 11U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", &chartInstance->c1_z7m, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 12U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", chartInstance->c1_z1R, 0,
      0U, 1U, 0U, 2, 1, 3), false);
    break;

   case 13U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", chartInstance->c1_z2R, 0,
      0U, 1U, 0U, 2, 1, 3), false);
    break;

   case 14U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", chartInstance->c1_z3R, 0,
      0U, 1U, 0U, 2, 1, 3), false);
    break;

   case 18U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", chartInstance->c1_z4R, 0,
      0U, 1U, 0U, 2, 1, 3), false);
    break;

   case 16U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", chartInstance->c1_z5R, 0,
      0U, 1U, 0U, 2, 1, 3), false);
    break;

   case 17U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", chartInstance->c1_z6R, 0,
      0U, 1U, 0U, 2, 1, 3), false);
    break;

   case 32U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", chartInstance->c1_Iveh, 0,
      0U, 1U, 0U, 2, 3, 3), false);
    break;

   case 19U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", chartInstance->c1_z1I, 0,
      0U, 1U, 0U, 2, 3, 3), false);
    break;

   case 20U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", chartInstance->c1_z2I, 0,
      0U, 1U, 0U, 2, 3, 3), false);
    break;

   case 21U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", chartInstance->c1_z3I, 0,
      0U, 1U, 0U, 2, 3, 3), false);
    break;

   case 22U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", chartInstance->c1_z4I, 0,
      0U, 1U, 0U, 2, 3, 3), false);
    break;

   case 23U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", chartInstance->c1_z5I, 0,
      0U, 1U, 0U, 2, 3, 3), false);
    break;

   case 24U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", chartInstance->c1_z6I, 0,
      0U, 1U, 0U, 2, 3, 3), false);
    break;

   case 25U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", chartInstance->c1_z7I, 0,
      0U, 1U, 0U, 2, 3, 3), false);
    break;

   case 28U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", *chartInstance->c1_Ibar, 0,
      0U, 1U, 0U, 2, 3, 3), false);
    break;

   case 29U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", *chartInstance->c1_Rbar, 0,
      0U, 1U, 0U, 2, 1, 3), false);
    break;

   case 26U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", chartInstance->c1_z7R, 0,
      0U, 1U, 0U, 2, 1, 3), false);
    break;

   case 37U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", *chartInstance->c1_Xbar, 0,
      0U, 1U, 0U, 2, 1, 3), false);
    break;

   case 38U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", *chartInstance->c1_Wbar, 0,
      0U, 1U, 0U, 2, 1, 4), false);
    break;

   case 33U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", &chartInstance->c1_a, 0, 0U,
      0U, 0U, 0), false);
    break;

   case 34U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", &chartInstance->c1_b, 0, 0U,
      0U, 0U, 0), false);
    break;

   case 35U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", &chartInstance->c1_h, 0, 0U,
      0U, 0U, 0), false);
    break;

   case 36U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", chartInstance->c1_w, 0, 0U,
      1U, 0U, 1, 2), false);
    break;

   case 39U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", &chartInstance->c1_d, 0, 0U,
      0U, 0U, 0), false);
    break;

   case 40U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", *chartInstance->c1_HPbar, 0,
      0U, 1U, 0U, 2, 3, 4), false);
    break;
  }
}

static void init_dsm_address_info(SFc1_vehdynlibeomInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc1_vehdynlibeomInstanceStruct
  *chartInstance)
{
  chartInstance->c1_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c1_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c1_Mbar = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_Ibar = (real_T (*)[9])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c1_Rbar = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c1_Xbar = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c1_Wbar = (real_T (*)[4])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c1_HPbar = (real_T (*)[12])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 6);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c1_vehdynlibeom_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4190523202U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1798884352U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1983543655U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(338411016U);
}

mxArray *sf_c1_vehdynlibeom_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString("coder.internal.blas.BLASApi"));
  return(mxcell3p);
}

mxArray *sf_c1_vehdynlibeom_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("early");
  mxArray *fallbackReason = mxCreateString("fixpt_minmax_logging");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c1_vehdynlibeom_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c1_vehdynlibeom(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiA+wMrAwAakOYCYiQECWKF8RiBmh9IQcRa4uAIQl1QWpILEi4uSPVOAdF5iLpi"
    "fWFrhmZeWDzbfggFhPhsW8xmRzOeEikPAB3vK9Ls4oOtnwaKfFUm/AJTvEZCUWAQNH1g4DZw/bM"
    "D+MCDgDxYUf7AweAK9MDjcL0KW+30HjfttyXJ/0KBxvzNZ7g8fLO5vcCLL/RFUc7+CA2X6IfYHE"
    "HC/JFo5BOJnFscnJpdklqXGJxvGl6VmpFTm5WQmpebnIpkLAgCetzLy"
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_vehdynlibeom_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sJmgGq4rSUSzb102XlY8tS";
}

static void sf_opaque_initialize_c1_vehdynlibeom(void *chartInstanceVar)
{
  initialize_params_c1_vehdynlibeom((SFc1_vehdynlibeomInstanceStruct*)
    chartInstanceVar);
  initialize_c1_vehdynlibeom((SFc1_vehdynlibeomInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_vehdynlibeom(void *chartInstanceVar)
{
  enable_c1_vehdynlibeom((SFc1_vehdynlibeomInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_vehdynlibeom(void *chartInstanceVar)
{
  disable_c1_vehdynlibeom((SFc1_vehdynlibeomInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_vehdynlibeom(void *chartInstanceVar)
{
  sf_gateway_c1_vehdynlibeom((SFc1_vehdynlibeomInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_vehdynlibeom(SimStruct* S)
{
  return get_sim_state_c1_vehdynlibeom((SFc1_vehdynlibeomInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_vehdynlibeom(SimStruct* S, const mxArray *
  st)
{
  set_sim_state_c1_vehdynlibeom((SFc1_vehdynlibeomInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c1_vehdynlibeom(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_vehdynlibeomInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_vehdynlibeom_optimization_info();
    }

    mdl_cleanup_runtime_resources_c1_vehdynlibeom
      ((SFc1_vehdynlibeomInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c1_vehdynlibeom(void *chartInstanceVar)
{
  mdl_start_c1_vehdynlibeom((SFc1_vehdynlibeomInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_mdl_terminate_c1_vehdynlibeom(void *chartInstanceVar)
{
  mdl_terminate_c1_vehdynlibeom((SFc1_vehdynlibeomInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_vehdynlibeom((SFc1_vehdynlibeomInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_vehdynlibeom(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  sf_warn_if_symbolic_dimension_param_changed(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_vehdynlibeom((SFc1_vehdynlibeomInstanceStruct*)
      sf_get_chart_instance_ptr(S));
    initSimStructsc1_vehdynlibeom((SFc1_vehdynlibeomInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c1_vehdynlibeom_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [23] = {
    "eNrtWU9vG0UUn0RJSkUpPaBCoYgeuSA1gUqVKJDEf1qjhFhdJ225ROPdZ+/Is7Ob+WPHEQfEN+D",
    "Md+gH4MR34MJH4MiRI2/WG9dsjL2zpo2LWGmznt39zfu9t+/fTMhKY5/gcR3P5oeEbOD1DTxXye",
    "hYz8YrE+fo/hp5kI2/e5MQPw6gC8IznQ47JW6HMFGTShop4n4IGsFjUDE3msWiITpxcSwTHZAgf",
    "JwgiaV2kqtYZDgTvboRvpWsnoTMD70wNjzYxQlpcCD48J/kJkY3UWKVSfB1HSDQoYxNN6xz2p1t",
    "BakHlRD8njKRs60UaM8kVlW1b7hmCYfaKfgNoTRFK6g5+nqaaqjoUzcjW32Vd46Oo4QzKorbOqT",
    "KgwS9Q8NhEuDfA6PReoWwfkil3oWQ9kHtsV4qPRZQSDpT+HabCapjySivRbxiZyuob5OjjvsYEt",
    "z1G6G+uxJoL4mZ0I4B4dXRzjVB2xyq0DZdR7kenBgbDUcMBiDdvm+nEvdB0i4cCDfO6TeqnaZOO",
    "Y6lgljNIjiicsdH31UQuOUNDDrlUXRHaOE0TlhITdxQLcn66Buuua5hw79UrjPRyPtVKWwqt9YH",
    "Z78ay637okI5V27YVpzsQR94Kr9KNS2BHcl3ACvFglaM3mGzjWPGMoJhJGTYSiwCVtwr+zlUWti",
    "+wSJVAM4iGwYQoJnH1McTzYsjo3QcVTDlVPf2Csq7iG0IDbJDfShcYyRlCpBw6leOcgOmbCAhGq",
    "2kUy0LzzCKwVJQojpGVAex7KGNXYvZC1vZSHBDQ9DFxKwhTXI19O4jyk1BzpHqYvygexwqzLJuc",
    "hFr46cU2Kd+CIGtnIzDPuZZnKDoJ1a25O+gtn2mh1VQvmRJ0UgymNCx6FortYYJHIqeiAeiLuPI",
    "yzqvGX4FgFmDSsFEdxdLuBzWkXwx1hJOWml2d21yrJ2p5rRtfeMhCKyGVlfbNVAfo6omsEVGQot",
    "gPXaGTYxQTGks1MNRqR/VPdu/b5MX/fvalP797Yn+/UY29jeP+xAGQ8FZG+IonefuxDzXCqwDbm",
    "fyZ+HIBRwZ8z6/fjyBX5kil0xc8/Kurs7muYq/VqbY6a2cnLUcbiOz1ec3f33+870f33/v+dlPy",
    "e8/fLCI/GTDbZ11PRvfPu+Xxtm5fyGB2XcfzfGDmzk/sGP1ddR9ePKZ9A69s/bm3a2n/Nl97Y3m",
    "+2V9Nt8rOb7n9+/YHg2DN80F0m8E2XrNjqkZrSPs/Pcn+G7MscfVCX8i5I+vFsNXt/P4afZaz9n",
    "Ljh8121Tm/Pfy9HiwnffHaXqs/U2PNdJAFZaD/zul+O8vDf8vSvF/vDT8K6X4P1kW/t/vluL/9F",
    "/jf2d7MXy2/zaH/61cHrqVrr2Pqe2w4DhfyS/W17L1yhVHXjHudeH5v11evn5F+lVSErfxiuWRS",
    "9LPtQ9/3d+fVTdI7v0bS6zHrHzvsh5bNr1+I27rpY+y8ZfjfcBKyHgwZScie7wHtDPt6X/Ev/90",
    "tN+72bhm7Zf9w+jbT3cE5UPFRtso57eb0u77jx9JoGr6/s5l1JOi+yLXcvFtxwMmgnigPtncure",
    "1SH36C+TKMM4=",
    ""
  };

  static char newstr [1589] = "";
  newstr[0] = '\0';
  for (i = 0; i < 23; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c1_vehdynlibeom(SimStruct *S)
{
  const char* newstr = sf_c1_vehdynlibeom_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(2933069371U));
  ssSetChecksum1(S,(445724090U));
  ssSetChecksum2(S,(2608508440U));
  ssSetChecksum3(S,(461564016U));
}

static void mdlRTW_c1_vehdynlibeom(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c1_vehdynlibeom(SimStruct *S)
{
  SFc1_vehdynlibeomInstanceStruct *chartInstance;
  chartInstance = (SFc1_vehdynlibeomInstanceStruct *)utMalloc(sizeof
    (SFc1_vehdynlibeomInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc1_vehdynlibeomInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_vehdynlibeom;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_vehdynlibeom;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c1_vehdynlibeom;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c1_vehdynlibeom;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c1_vehdynlibeom;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_vehdynlibeom;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_vehdynlibeom;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_vehdynlibeom;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_vehdynlibeom;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_vehdynlibeom;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_vehdynlibeom;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_vehdynlibeom;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->chartInfo.chartStateSetterFcn = NULL;
  chartInstance->chartInfo.chartStateGetterFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0,
    chartInstance->c1_JITStateAnimation,
    chartInstance->c1_JITTransitionAnimation);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c1_vehdynlibeom(chartInstance);
}

void c1_vehdynlibeom_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c1_vehdynlibeom(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_vehdynlibeom(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_vehdynlibeom(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_vehdynlibeom_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
