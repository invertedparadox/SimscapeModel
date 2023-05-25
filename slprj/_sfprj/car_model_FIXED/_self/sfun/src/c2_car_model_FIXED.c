/* Include files */

#include "car_model_FIXED_sfun.h"
#include "c2_car_model_FIXED.h"
#include <math.h>
#include "mwmathutil.h"
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

/* Function Declarations */
static void initialize_c2_car_model_FIXED(SFc2_car_model_FIXEDInstanceStruct
  *chartInstance);
static void initialize_params_c2_car_model_FIXED
  (SFc2_car_model_FIXEDInstanceStruct *chartInstance);
static void mdl_start_c2_car_model_FIXED(SFc2_car_model_FIXEDInstanceStruct
  *chartInstance);
static void mdl_terminate_c2_car_model_FIXED(SFc2_car_model_FIXEDInstanceStruct *
  chartInstance);
static void mdl_setup_runtime_resources_c2_car_model_FIXED
  (SFc2_car_model_FIXEDInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c2_car_model_FIXED
  (SFc2_car_model_FIXEDInstanceStruct *chartInstance);
static void enable_c2_car_model_FIXED(SFc2_car_model_FIXEDInstanceStruct
  *chartInstance);
static void disable_c2_car_model_FIXED(SFc2_car_model_FIXEDInstanceStruct
  *chartInstance);
static void sf_gateway_c2_car_model_FIXED(SFc2_car_model_FIXEDInstanceStruct
  *chartInstance);
static void ext_mode_exec_c2_car_model_FIXED(SFc2_car_model_FIXEDInstanceStruct *
  chartInstance);
static void c2_update_jit_animation_c2_car_model_FIXED
  (SFc2_car_model_FIXEDInstanceStruct *chartInstance);
static void c2_do_animation_call_c2_car_model_FIXED
  (SFc2_car_model_FIXEDInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_car_model_FIXED
  (SFc2_car_model_FIXEDInstanceStruct *chartInstance);
static void set_sim_state_c2_car_model_FIXED(SFc2_car_model_FIXEDInstanceStruct *
  chartInstance, const mxArray *c2_st);
static void initSimStructsc2_car_model_FIXED(SFc2_car_model_FIXEDInstanceStruct *
  chartInstance);
static void c2_emlrt_update_log_1(SFc2_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c2_in[3], emlrtLocationLoggingDataType c2_table[],
  int32_T c2_index, real_T c2_out[3]);
static void c2_emlrt_update_log_2(SFc2_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c2_in[4], emlrtLocationLoggingDataType c2_table[],
  int32_T c2_index, real_T c2_out[4]);
static real_T c2_emlrt_update_log_3(SFc2_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c2_in, emlrtLocationLoggingDataType c2_table[], int32_T
  c2_index);
static void c2_emlrtInitVarDataTables(SFc2_car_model_FIXEDInstanceStruct
  *chartInstance, emlrtLocationLoggingDataType c2_dataTables[7],
  emlrtLocationLoggingHistogramType c2_histTables[7]);
static real_T c2_sumColumnB(SFc2_car_model_FIXEDInstanceStruct *chartInstance,
  real_T c2_x[4], int32_T c2_col);
static void c2_emlrt_marshallIn(SFc2_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c2_b_GeomXYZ, const char_T *c2_identifier,
  real_T c2_y[3]);
static void c2_b_emlrt_marshallIn(SFc2_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[3]);
static uint8_T c2_c_emlrt_marshallIn(SFc2_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_car_model_FIXED, const char_T
  *c2_identifier);
static uint8_T c2_d_emlrt_marshallIn(SFc2_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_slStringInitializeDynamicBuffers
  (SFc2_car_model_FIXEDInstanceStruct *chartInstance);
static void c2_chart_data_browse_helper(SFc2_car_model_FIXEDInstanceStruct
  *chartInstance, int32_T c2_ssIdNumber, const mxArray **c2_mxData, uint8_T
  *c2_isValueTooBig);
static void c2_b_emlrt_update_log_1(SFc2_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c2_in[3], emlrtLocationLoggingDataType c2_table[],
  int32_T c2_index);
static void c2_b_emlrt_update_log_2(SFc2_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c2_in[4], emlrtLocationLoggingDataType c2_table[],
  int32_T c2_index);
static void init_dsm_address_info(SFc2_car_model_FIXEDInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc2_car_model_FIXEDInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_car_model_FIXED(SFc2_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_is_active_c2_car_model_FIXED = 0U;
  chartInstance->c2_emlrtLocLogSimulated = false;
  c2_emlrtInitVarDataTables(chartInstance,
    chartInstance->c2_emlrtLocationLoggingDataTables,
    chartInstance->c2_emlrtLocLogHistTables);
}

static void initialize_params_c2_car_model_FIXED
  (SFc2_car_model_FIXEDInstanceStruct *chartInstance)
{
  real_T c2_d;
  real_T c2_d1;
  sf_mex_import_named("trackW", sf_mex_get_sfun_param(chartInstance->S, 0U, 0U),
                      &c2_d, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c2_trackW = c2_d;
  sf_mex_import_named("wheelB", sf_mex_get_sfun_param(chartInstance->S, 1U, 0U),
                      &c2_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c2_wheelB = c2_d1;
}

static void mdl_start_c2_car_model_FIXED(SFc2_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void mdl_terminate_c2_car_model_FIXED(SFc2_car_model_FIXEDInstanceStruct *
  chartInstance)
{
  const emlrtLocationLoggingFileInfoType c2_emlrtLocationLoggingFileInfo = {
    "#car_model_FIXED:2488",           /* mexFileName */
    "Mon Apr 17 19:52:45 2023",        /* timestamp */
    "",                                /* buildDir */
    1,                                 /* numFcns */
    256                                /* numHistogramBins */
  };

  const emlrtLocationLoggingFunctionInfoType
    c2_emlrtLocationLoggingFunctionInfoTable[1] = { { "eML_blk_kernel",/* fcnName */
      1,                               /* fcnId */
      7                                /* numInstrPoints */
    } };

  const emlrtLocationLoggingLocationType c2_emlrtLocationInfo[7] = { { 1,/* MxInfoID */
      35,                              /* TextStart */
      7,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      44,                              /* TextStart */
      9,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      55,                              /* TextStart */
      6,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 3,                            /* MxInfoID */
      62,                              /* TextStart */
      6,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 3,                            /* MxInfoID */
      70,                              /* TextStart */
      6,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      151,                             /* TextStart */
      6,                               /* TextLength */
      4,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      158,                             /* TextStart */
      7,                               /* TextLength */
      4,                               /* Reason */
      false                            /* MoreLocations */
    } };

  const int32_T c2_emlrtLocationLoggingFieldCounts[7] = { 0, 0, 0, 0, 0, 0, 0 };

  if (chartInstance->c2_emlrtLocLogSimulated) {
    emlrtLocationLoggingClearLog("#car_model_FIXED:2488");
    emlrtLocationLoggingPushLog(&c2_emlrtLocationLoggingFileInfo,
      &c2_emlrtLocationLoggingFunctionInfoTable[0],
      &chartInstance->c2_emlrtLocationLoggingDataTables[0],
      &c2_emlrtLocationInfo[0], NULL, 0U, &c2_emlrtLocationLoggingFieldCounts[0],
      NULL);
    addResultsToFPTRepository("#car_model_FIXED:2488");
  }
}

static void mdl_setup_runtime_resources_c2_car_model_FIXED
  (SFc2_car_model_FIXEDInstanceStruct *chartInstance)
{
  static const uint32_T c2_decisionTxtEndIdx = 0U;
  static const uint32_T c2_decisionTxtStartIdx = 0U;
  setDebuggerFlag(chartInstance->S, true);
  setDataBrowseFcn(chartInstance->S, (void *)&c2_chart_data_browse_helper);
  chartInstance->c2_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c2_RuntimeVar,
    &chartInstance->c2_IsDebuggerActive,
    &chartInstance->c2_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c2_mlFcnLineNumber, &chartInstance->c2_IsHeatMapPresent, 0);
  sim_mode_is_external(chartInstance->S);
  covrtCreateStateflowInstanceData(chartInstance->c2_covrtInstance, 1U, 0U, 1U,
    130U);
  covrtChartInitFcn(chartInstance->c2_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c2_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c2_decisionTxtStartIdx, &c2_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c2_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c2_covrtInstance, "", 4U, 0U, 1U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 225);
}

static void mdl_cleanup_runtime_resources_c2_car_model_FIXED
  (SFc2_car_model_FIXEDInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c2_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c2_covrtInstance);
}

static void enable_c2_car_model_FIXED(SFc2_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_car_model_FIXED(SFc2_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c2_car_model_FIXED(SFc2_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  real_T c2_dv1[4];
  real_T c2_dv[3];
  real_T c2_Zcg;
  real_T c2_b_trackW;
  real_T c2_b_wheelB;
  real_T c2_b_x;
  real_T c2_c_trackW;
  real_T c2_c_wheelB;
  real_T c2_psi;
  real_T c2_theta;
  real_T c2_x;
  real_T c2_y;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  chartInstance->c2_JITTransitionAnimation[0] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  for (c2_i = 0; c2_i < 4; c2_i++) {
    covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 2U,
                      (*chartInstance->c2_Ground)[c2_i]);
  }

  for (c2_i1 = 0; c2_i1 < 3; c2_i1++) {
    covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 1U,
                      (*chartInstance->c2_GemoXYZIn)[c2_i1]);
  }

  for (c2_i2 = 0; c2_i2 < 3; c2_i2++) {
    covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 0U,
                      (*chartInstance->c2_angleIn)[c2_i2]);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_b_trackW = chartInstance->c2_trackW;
  c2_b_wheelB = chartInstance->c2_wheelB;

  /* logging input variable 'angleIn' for function 'eML_blk_kernel' */
  /* logging input variable 'GemoXYZIn' for function 'eML_blk_kernel' */
  /* logging input variable 'Ground' for function 'eML_blk_kernel' */
  /* logging input variable 'trackW' for function 'eML_blk_kernel' */
  /* logging input variable 'wheelB' for function 'eML_blk_kernel' */
  chartInstance->c2_emlrtLocLogSimulated = true;

  /* logging input variable 'angleIn' for function 'eML_blk_kernel' */
  for (c2_i3 = 0; c2_i3 < 3; c2_i3++) {
    c2_dv[c2_i3] = (*chartInstance->c2_angleIn)[c2_i3];
  }

  c2_b_emlrt_update_log_1(chartInstance, c2_dv,
    chartInstance->c2_emlrtLocationLoggingDataTables, 0);

  /* logging input variable 'GemoXYZIn' for function 'eML_blk_kernel' */
  for (c2_i4 = 0; c2_i4 < 3; c2_i4++) {
    c2_dv[c2_i4] = (*chartInstance->c2_GemoXYZIn)[c2_i4];
  }

  c2_b_emlrt_update_log_1(chartInstance, c2_dv,
    chartInstance->c2_emlrtLocationLoggingDataTables, 1);

  /* logging input variable 'Ground' for function 'eML_blk_kernel' */
  for (c2_i5 = 0; c2_i5 < 4; c2_i5++) {
    c2_dv1[c2_i5] = (*chartInstance->c2_Ground)[c2_i5];
  }

  c2_b_emlrt_update_log_2(chartInstance, c2_dv1,
    chartInstance->c2_emlrtLocationLoggingDataTables, 2);

  /* logging input variable 'trackW' for function 'eML_blk_kernel' */
  c2_emlrt_update_log_3(chartInstance, c2_b_trackW,
                        chartInstance->c2_emlrtLocationLoggingDataTables, 3);

  /* logging input variable 'wheelB' for function 'eML_blk_kernel' */
  c2_emlrt_update_log_3(chartInstance, c2_b_wheelB,
                        chartInstance->c2_emlrtLocationLoggingDataTables, 4);
  covrtEmlFcnEval(chartInstance->c2_covrtInstance, 4U, 0, 0);
  c2_c_trackW = c2_b_trackW;
  c2_c_wheelB = c2_b_wheelB;
  c2_y = c2_sumColumnB(chartInstance, *chartInstance->c2_Ground, 1);
  c2_Zcg = c2_y / 4.0;
  c2_x = (((*chartInstance->c2_Ground)[0] - (*chartInstance->c2_Ground)[1]) + ((*
            chartInstance->c2_Ground)[2] - (*chartInstance->c2_Ground)[3])) /
    c2_c_trackW / 2.0;
  c2_psi = c2_x;
  c2_psi = muDoubleScalarAtan(c2_psi);
  c2_b_x = (((*chartInstance->c2_Ground)[0] - (*chartInstance->c2_Ground)[2]) +
            ((*chartInstance->c2_Ground)[1] - (*chartInstance->c2_Ground)[3])) /
    c2_c_wheelB / 2.0;
  c2_theta = c2_b_x;
  c2_theta = muDoubleScalarAtan(c2_theta);
  (*chartInstance->c2_angles)[0] = c2_psi;
  (*chartInstance->c2_angles)[1] = c2_theta;
  (*chartInstance->c2_angles)[2] = (*chartInstance->c2_angleIn)[2];
  for (c2_i6 = 0; c2_i6 < 2; c2_i6++) {
    (*chartInstance->c2_GeomXYZ)[c2_i6] = (*chartInstance->c2_GemoXYZIn)[c2_i6];
  }

  (*chartInstance->c2_GeomXYZ)[2] = -c2_Zcg;
  c2_b_emlrt_update_log_1(chartInstance, *chartInstance->c2_angles,
    chartInstance->c2_emlrtLocationLoggingDataTables, 5);
  c2_b_emlrt_update_log_1(chartInstance, *chartInstance->c2_GeomXYZ,
    chartInstance->c2_emlrtLocationLoggingDataTables, 6);
  c2_do_animation_call_c2_car_model_FIXED(chartInstance);
  for (c2_i7 = 0; c2_i7 < 3; c2_i7++) {
    covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 3U,
                      (*chartInstance->c2_angles)[c2_i7]);
  }

  for (c2_i8 = 0; c2_i8 < 3; c2_i8++) {
    covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 4U,
                      (*chartInstance->c2_GeomXYZ)[c2_i8]);
  }
}

static void ext_mode_exec_c2_car_model_FIXED(SFc2_car_model_FIXEDInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void c2_update_jit_animation_c2_car_model_FIXED
  (SFc2_car_model_FIXEDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_do_animation_call_c2_car_model_FIXED
  (SFc2_car_model_FIXEDInstanceStruct *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static const mxArray *get_sim_state_c2_car_model_FIXED
  (SFc2_car_model_FIXEDInstanceStruct *chartInstance)
{
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellmatrix(3, 1), false);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", *chartInstance->c2_GeomXYZ, 0, 0U,
    1U, 0U, 1, 3), false);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", *chartInstance->c2_angles, 0, 0U, 1U,
    0U, 1, 3), false);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y",
    &chartInstance->c2_is_active_c2_car_model_FIXED, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  sf_mex_assign(&c2_st, c2_y, false);
  return c2_st;
}

static void set_sim_state_c2_car_model_FIXED(SFc2_car_model_FIXEDInstanceStruct *
  chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv[3];
  real_T c2_dv1[3];
  int32_T c2_i;
  int32_T c2_i1;
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
                      "GeomXYZ", c2_dv);
  for (c2_i = 0; c2_i < 3; c2_i++) {
    (*chartInstance->c2_GeomXYZ)[c2_i] = c2_dv[c2_i];
  }

  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
                      "angles", c2_dv1);
  for (c2_i1 = 0; c2_i1 < 3; c2_i1++) {
    (*chartInstance->c2_angles)[c2_i1] = c2_dv1[c2_i1];
  }

  chartInstance->c2_is_active_c2_car_model_FIXED = c2_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 2)),
     "is_active_c2_car_model_FIXED");
  sf_mex_destroy(&c2_u);
  sf_mex_destroy(&c2_st);
}

static void initSimStructsc2_car_model_FIXED(SFc2_car_model_FIXEDInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void c2_emlrt_update_log_1(SFc2_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c2_in[3], emlrtLocationLoggingDataType c2_table[],
  int32_T c2_index, real_T c2_out[3])
{
  int32_T c2_i;
  for (c2_i = 0; c2_i < 3; c2_i++) {
    c2_out[c2_i] = c2_in[c2_i];
  }

  c2_b_emlrt_update_log_1(chartInstance, c2_out, c2_table, c2_index);
}

static void c2_emlrt_update_log_2(SFc2_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c2_in[4], emlrtLocationLoggingDataType c2_table[],
  int32_T c2_index, real_T c2_out[4])
{
  int32_T c2_i;
  for (c2_i = 0; c2_i < 4; c2_i++) {
    c2_out[c2_i] = c2_in[c2_i];
  }

  c2_b_emlrt_update_log_2(chartInstance, c2_out, c2_table, c2_index);
}

static real_T c2_emlrt_update_log_3(SFc2_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c2_in, emlrtLocationLoggingDataType c2_table[], int32_T
  c2_index)
{
  emlrtLocationLoggingDataType *c2_b_table;
  emlrtLocationLoggingHistogramType *c2_histTable;
  real_T c2_inDouble;
  real_T c2_localMax;
  real_T c2_localMin;
  real_T c2_significand;
  int32_T c2_exponent;
  boolean_T c2_isLoggingEnabledHere;
  (void)chartInstance;
  c2_isLoggingEnabledHere = (c2_index >= 0);
  if (c2_isLoggingEnabledHere) {
    c2_b_table = (emlrtLocationLoggingDataType *)&c2_table[c2_index];
    c2_localMin = c2_b_table[0U].SimMin;
    c2_localMax = c2_b_table[0U].SimMax;
    c2_histTable = c2_b_table[0U].HistogramTable;

    /* Simulation Min-Max logging. */
    if (c2_in < c2_localMin) {
      c2_localMin = c2_in;
    }

    if (c2_in > c2_localMax) {
      c2_localMax = c2_in;
    }

    /* Histogram logging. */
    c2_inDouble = c2_in;
    c2_histTable->TotalNumberOfValues++;
    if (c2_inDouble == 0.0) {
      c2_histTable->NumberOfZeros++;
    } else {
      c2_histTable->SimSum += c2_inDouble;
      if ((!muDoubleScalarIsInf(c2_inDouble)) && (!muDoubleScalarIsNaN
           (c2_inDouble))) {
        c2_significand = frexp(c2_inDouble, &c2_exponent);
        if (c2_exponent > 128) {
          c2_exponent = 128;
        }

        if (c2_exponent < -127) {
          c2_exponent = -127;
        }

        if (c2_significand < 0.0) {
          c2_histTable->NumberOfNegativeValues++;
          c2_histTable->HistogramOfNegativeValues[127 + c2_exponent]++;
        } else {
          c2_histTable->NumberOfPositiveValues++;
          c2_histTable->HistogramOfPositiveValues[127 + c2_exponent]++;
        }
      }
    }

    c2_b_table[0U].SimMin = c2_localMin;
    c2_b_table[0U].SimMax = c2_localMax;

    /* IsAlwaysInteger logging. */
    if (c2_in != muDoubleScalarFloor(c2_in)) {
      c2_b_table[0U].IsAlwaysInteger = false;
    }
  }

  return c2_in;
}

static void c2_emlrtInitVarDataTables(SFc2_car_model_FIXEDInstanceStruct
  *chartInstance, emlrtLocationLoggingDataType c2_dataTables[7],
  emlrtLocationLoggingHistogramType c2_histTables[7])
{
  int32_T c2_i;
  int32_T c2_iH;
  (void)chartInstance;
  for (c2_i = 0; c2_i < 7; c2_i++) {
    c2_dataTables[c2_i].SimMin = rtInf;
    c2_dataTables[c2_i].SimMax = rtMinusInf;
    c2_dataTables[c2_i].OverflowWraps = 0;
    c2_dataTables[c2_i].Saturations = 0;
    c2_dataTables[c2_i].IsAlwaysInteger = true;
    c2_dataTables[c2_i].HistogramTable = &c2_histTables[c2_i];
    c2_histTables[c2_i].NumberOfZeros = 0.0;
    c2_histTables[c2_i].NumberOfPositiveValues = 0.0;
    c2_histTables[c2_i].NumberOfNegativeValues = 0.0;
    c2_histTables[c2_i].TotalNumberOfValues = 0.0;
    c2_histTables[c2_i].SimSum = 0.0;
    for (c2_iH = 0; c2_iH < 256; c2_iH++) {
      c2_histTables[c2_i].HistogramOfPositiveValues[c2_iH] = 0.0;
      c2_histTables[c2_i].HistogramOfNegativeValues[c2_iH] = 0.0;
    }
  }
}

const mxArray *sf_c2_car_model_FIXED_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c2_nameCaptureInfo;
}

static real_T c2_sumColumnB(SFc2_car_model_FIXEDInstanceStruct *chartInstance,
  real_T c2_x[4], int32_T c2_col)
{
  real_T c2_y;
  int32_T c2_b_col;
  int32_T c2_b_k;
  int32_T c2_i0;
  int32_T c2_k;
  (void)chartInstance;
  c2_b_col = c2_col - 1;
  c2_i0 = c2_b_col << 2;
  c2_y = c2_x[c2_i0];
  for (c2_k = 0; c2_k < 3; c2_k++) {
    c2_b_k = c2_k;
    c2_y += c2_x[(c2_i0 + c2_b_k) + 1];
  }

  return c2_y;
}

static void c2_emlrt_marshallIn(SFc2_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c2_b_GeomXYZ, const char_T *c2_identifier,
  real_T c2_y[3])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char_T *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_GeomXYZ), &c2_thisId,
                        c2_y);
  sf_mex_destroy(&c2_b_GeomXYZ);
}

static void c2_b_emlrt_marshallIn(SFc2_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[3])
{
  real_T c2_dv[3];
  int32_T c2_i;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv, 1, 0, 0U, 1, 0U, 1, 3);
  for (c2_i = 0; c2_i < 3; c2_i++) {
    c2_y[c2_i] = c2_dv[c2_i];
  }

  sf_mex_destroy(&c2_u);
}

static uint8_T c2_c_emlrt_marshallIn(SFc2_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_car_model_FIXED, const char_T
  *c2_identifier)
{
  emlrtMsgIdentifier c2_thisId;
  uint8_T c2_y;
  c2_thisId.fIdentifier = (const char_T *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_car_model_FIXED), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_car_model_FIXED);
  return c2_y;
}

static uint8_T c2_d_emlrt_marshallIn(SFc2_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_b_u;
  uint8_T c2_y;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_b_u, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_b_u;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_slStringInitializeDynamicBuffers
  (SFc2_car_model_FIXEDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_chart_data_browse_helper(SFc2_car_model_FIXEDInstanceStruct
  *chartInstance, int32_T c2_ssIdNumber, const mxArray **c2_mxData, uint8_T
  *c2_isValueTooBig)
{
  *c2_mxData = NULL;
  *c2_mxData = NULL;
  *c2_isValueTooBig = 0U;
  switch (c2_ssIdNumber) {
   case 6U:
    sf_mex_assign(c2_mxData, sf_mex_create("mxData", *chartInstance->c2_angles,
      0, 0U, 1U, 0U, 1, 3), false);
    break;

   case 4U:
    sf_mex_assign(c2_mxData, sf_mex_create("mxData", *chartInstance->c2_angleIn,
      0, 0U, 1U, 0U, 1, 3), false);
    break;

   case 5U:
    sf_mex_assign(c2_mxData, sf_mex_create("mxData", *chartInstance->c2_GeomXYZ,
      0, 0U, 1U, 0U, 1, 3), false);
    break;

   case 7U:
    sf_mex_assign(c2_mxData, sf_mex_create("mxData",
      *chartInstance->c2_GemoXYZIn, 0, 0U, 1U, 0U, 1, 3), false);
    break;

   case 8U:
    sf_mex_assign(c2_mxData, sf_mex_create("mxData", *chartInstance->c2_Ground,
      0, 0U, 1U, 0U, 1, 4), false);
    break;

   case 9U:
    sf_mex_assign(c2_mxData, sf_mex_create("mxData", &chartInstance->c2_trackW,
      0, 0U, 0U, 0U, 0), false);
    break;

   case 10U:
    sf_mex_assign(c2_mxData, sf_mex_create("mxData", &chartInstance->c2_wheelB,
      0, 0U, 0U, 0U, 0), false);
    break;
  }
}

static void c2_b_emlrt_update_log_1(SFc2_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c2_in[3], emlrtLocationLoggingDataType c2_table[],
  int32_T c2_index)
{
  emlrtLocationLoggingDataType *c2_b_table;
  emlrtLocationLoggingHistogramType *c2_histTable;
  real_T c2_inDouble;
  real_T c2_localMax;
  real_T c2_localMin;
  real_T c2_significand;
  int32_T c2_b_i;
  int32_T c2_exponent;
  int32_T c2_i;
  boolean_T c2_isLoggingEnabledHere;
  (void)chartInstance;
  c2_isLoggingEnabledHere = (c2_index >= 0);
  if (c2_isLoggingEnabledHere) {
    c2_b_table = (emlrtLocationLoggingDataType *)&c2_table[c2_index];
    c2_localMin = c2_b_table[0U].SimMin;
    c2_localMax = c2_b_table[0U].SimMax;
    c2_histTable = c2_b_table[0U].HistogramTable;
    for (c2_i = 0; c2_i < 3; c2_i++) {
      /* Simulation Min-Max logging. */
      if (c2_in[c2_i] < c2_localMin) {
        c2_localMin = c2_in[c2_i];
      }

      if (c2_in[c2_i] > c2_localMax) {
        c2_localMax = c2_in[c2_i];
      }

      /* Histogram logging. */
      c2_inDouble = c2_in[c2_i];
      c2_histTable->TotalNumberOfValues++;
      if (c2_inDouble == 0.0) {
        c2_histTable->NumberOfZeros++;
      } else {
        c2_histTable->SimSum += c2_inDouble;
        if ((!muDoubleScalarIsInf(c2_inDouble)) && (!muDoubleScalarIsNaN
             (c2_inDouble))) {
          c2_significand = frexp(c2_inDouble, &c2_exponent);
          if (c2_exponent > 128) {
            c2_exponent = 128;
          }

          if (c2_exponent < -127) {
            c2_exponent = -127;
          }

          if (c2_significand < 0.0) {
            c2_histTable->NumberOfNegativeValues++;
            c2_histTable->HistogramOfNegativeValues[127 + c2_exponent]++;
          } else {
            c2_histTable->NumberOfPositiveValues++;
            c2_histTable->HistogramOfPositiveValues[127 + c2_exponent]++;
          }
        }
      }
    }

    c2_b_table[0U].SimMin = c2_localMin;
    c2_b_table[0U].SimMax = c2_localMax;

    /* IsAlwaysInteger logging. */
    c2_b_i = 0;
    while (c2_b_table[0U].IsAlwaysInteger && (c2_b_i < 3)) {
      if (c2_in[c2_b_i] != muDoubleScalarFloor(c2_in[c2_b_i])) {
        c2_b_table[0U].IsAlwaysInteger = false;
      }

      c2_b_i++;
    }
  }
}

static void c2_b_emlrt_update_log_2(SFc2_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c2_in[4], emlrtLocationLoggingDataType c2_table[],
  int32_T c2_index)
{
  emlrtLocationLoggingDataType *c2_b_table;
  emlrtLocationLoggingHistogramType *c2_histTable;
  real_T c2_inDouble;
  real_T c2_localMax;
  real_T c2_localMin;
  real_T c2_significand;
  int32_T c2_b_i;
  int32_T c2_exponent;
  int32_T c2_i;
  boolean_T c2_isLoggingEnabledHere;
  (void)chartInstance;
  c2_isLoggingEnabledHere = (c2_index >= 0);
  if (c2_isLoggingEnabledHere) {
    c2_b_table = (emlrtLocationLoggingDataType *)&c2_table[c2_index];
    c2_localMin = c2_b_table[0U].SimMin;
    c2_localMax = c2_b_table[0U].SimMax;
    c2_histTable = c2_b_table[0U].HistogramTable;
    for (c2_i = 0; c2_i < 4; c2_i++) {
      /* Simulation Min-Max logging. */
      if (c2_in[c2_i] < c2_localMin) {
        c2_localMin = c2_in[c2_i];
      }

      if (c2_in[c2_i] > c2_localMax) {
        c2_localMax = c2_in[c2_i];
      }

      /* Histogram logging. */
      c2_inDouble = c2_in[c2_i];
      c2_histTable->TotalNumberOfValues++;
      if (c2_inDouble == 0.0) {
        c2_histTable->NumberOfZeros++;
      } else {
        c2_histTable->SimSum += c2_inDouble;
        if ((!muDoubleScalarIsInf(c2_inDouble)) && (!muDoubleScalarIsNaN
             (c2_inDouble))) {
          c2_significand = frexp(c2_inDouble, &c2_exponent);
          if (c2_exponent > 128) {
            c2_exponent = 128;
          }

          if (c2_exponent < -127) {
            c2_exponent = -127;
          }

          if (c2_significand < 0.0) {
            c2_histTable->NumberOfNegativeValues++;
            c2_histTable->HistogramOfNegativeValues[127 + c2_exponent]++;
          } else {
            c2_histTable->NumberOfPositiveValues++;
            c2_histTable->HistogramOfPositiveValues[127 + c2_exponent]++;
          }
        }
      }
    }

    c2_b_table[0U].SimMin = c2_localMin;
    c2_b_table[0U].SimMax = c2_localMax;

    /* IsAlwaysInteger logging. */
    c2_b_i = 0;
    while (c2_b_table[0U].IsAlwaysInteger && (c2_b_i < 4)) {
      if (c2_in[c2_b_i] != muDoubleScalarFloor(c2_in[c2_b_i])) {
        c2_b_table[0U].IsAlwaysInteger = false;
      }

      c2_b_i++;
    }
  }
}

static void init_dsm_address_info(SFc2_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc2_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  chartInstance->c2_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c2_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c2_angles = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_angleIn = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c2_GeomXYZ = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c2_GemoXYZIn = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_Ground = (real_T (*)[4])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c2_car_model_FIXED_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2119940981U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2153830855U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(744848199U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3489021173U);
}

mxArray *sf_c2_car_model_FIXED_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c2_car_model_FIXED_jit_fallback_info(void)
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

mxArray *sf_c2_car_model_FIXED_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c2_car_model_FIXED(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiA+wcTAwAakOYCYiQECWKF8RiBmhtIQcRa4uAIQl1QWpILEi4uSPVOAdF5iLpi"
    "fWFrhmZeWDzbfggFhPhsW8xmRzOeEikPAB3vK9Is4oOtnwaKfHUm/AJTvnpqfGxEZBXY/LJwGzh"
    "8SRPmDDc0fIH5iXnpOajEDlfyh4ECZfoj9AQT8IYPmDxA/szg+Mbkksyw1PtkoPjmxKD43PyU1J"
    "97NM8LVBWYuCAAA7ZAhxw=="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_car_model_FIXED_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "s7qNGAWd62A0blwh8l7q0xB";
}

static void sf_opaque_initialize_c2_car_model_FIXED(void *chartInstanceVar)
{
  initialize_params_c2_car_model_FIXED((SFc2_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
  initialize_c2_car_model_FIXED((SFc2_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_car_model_FIXED(void *chartInstanceVar)
{
  enable_c2_car_model_FIXED((SFc2_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c2_car_model_FIXED(void *chartInstanceVar)
{
  disable_c2_car_model_FIXED((SFc2_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_car_model_FIXED(void *chartInstanceVar)
{
  sf_gateway_c2_car_model_FIXED((SFc2_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c2_car_model_FIXED(SimStruct* S)
{
  return get_sim_state_c2_car_model_FIXED((SFc2_car_model_FIXEDInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c2_car_model_FIXED(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c2_car_model_FIXED((SFc2_car_model_FIXEDInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c2_car_model_FIXED(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_car_model_FIXEDInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_car_model_FIXED_optimization_info();
    }

    mdl_cleanup_runtime_resources_c2_car_model_FIXED
      ((SFc2_car_model_FIXEDInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c2_car_model_FIXED(void *chartInstanceVar)
{
  mdl_start_c2_car_model_FIXED((SFc2_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_mdl_terminate_c2_car_model_FIXED(void *chartInstanceVar)
{
  mdl_terminate_c2_car_model_FIXED((SFc2_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_car_model_FIXED((SFc2_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_car_model_FIXED(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  sf_warn_if_symbolic_dimension_param_changed(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_car_model_FIXED((SFc2_car_model_FIXEDInstanceStruct*)
      sf_get_chart_instance_ptr(S));
    initSimStructsc2_car_model_FIXED((SFc2_car_model_FIXEDInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c2_car_model_FIXED_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [23] = {
    "eNrtWN1u40QUnrSlsGKpVggJhCqxN0hwgVSKYBcJsW3zUyK12wqn3WVvslP7JB5lPOPOjPODeBQ",
    "uuOIBkHgHxC03PAAPwCWXnHGcNOuGZKZl/xCWUndsf+c75/j8jUmleUjw2MDf43cJWcfza/hbIe",
    "PjlWJdmfmNr6+RL4r1d68TEsoIuiCCrNNhQ+J3iCw5poommvgfgibwNWjJM8OkaIqOdMcy0QEFI",
    "kQBqVTGi1ezJONM9BqZCC2zfhCzMA5imfFoDwXS6Ejw0T/xppk5RsYaUxCaBkBkYiWzbtzgtLvY",
    "C8oMqjGEPZ0l3r7SYIIstabqw4wblnKoDyFsCm0oekEvsTcw1EDVDP2cbO3VwQQtk5QzKtx9HVM",
    "dQIrRYeAkjfDvUWbQe07YMKbK7EFM+6APWC9nlwKc2JnGp8+YoEYqRnk94VUrzdHeY442HmJKcN",
    "93hPbuKaC9VDJhPBMiaKCf64KecajBWdb15A3gPLPZcMpgAMrv/Xaqsg+KduFI+Omcv6P6MA/Ka",
    "S45Yg1L4JSq3RBjV0PkVzcw6XRAMRyhhWK8sJC7uKlbivUxNnxrXdOm/5VqXZaMo19fCZvz1vvg",
    "HVdT3kYoqpRz7YdtyfQA+sBz/ho19ArYMb8HWGsWtSRGh602nhUrEwwzocBWpYiYe1T2S6i8sd3",
    "HJuUAZ4lNA4jQzVPVp4KW5VGmjUyqWHJqBweOfJexTWFAdWgIzj1GUaYBFc7jypM3YtomEqLRSy",
    "a30lnCOAevBCW6k4naQKoe+ti3mV34ymaCHxqiLhZmA3mRq2N0n1KeOeqc6C7mD4bHicYq68eLW",
    "Js/VwKHNIwhsp2TcTjEOosCXF+xti1/F63tMzOqgQ4VS10zKcOCjk3Xeqk1SuFE9IQciIaSSVBM",
    "XgviCgCrBlWCie4etnA1aqDyblorOG/l1d13yLF+pobTMxsb+yCwG1pb7dRAQ8yqusARGRW6DjZ",
    "g3+IQIzTTBhv1aNzqx33Pzu9fkYv5fW3O/P7mzPx+q1iH2+2QqnZiZ5V2o/mwXiNTeVsz8m467A",
    "dWHHDkEu6Cb3L+YAZfmcNLZs5lvhsrTz6/WuJbwSuVSiXH7czg3ijxrJVw64XPPlz7vvvr5z/9/",
    "MeP9w7bv/3w/jL+yiX+Sv6/xQ1X/fZbG8V6czI3Tat0/1Ihc4mHt0vxYNf6zvn9/d0H0Wfbu1tn",
    "fBDf5XfOt4Z7ubxfVhbru1rSd3L9tp3VMInzmqDCZlTs2+yaZuP9hJV/d0bf9SX+uDETT4T8ee9",
    "6+Ld2yvh5/nq15C+73geZPPzm0RPx+/zseMfJjvWSHXZNRTcvkf+OHbd3rocf8x8vsWOzZMdmvh",
    "dpU9txoD2/sm041o1FeeuLI88Y97Lo+b9fnr59Ln179Sn2+3k48oxx17XPdx552Z/fWlB3Sen5W",
    "y+wHYvqvc9c+qLZ9TvxmxvfK9ZfTr+LVGPGozk7s+I2bp468+7+R+L7L0//TebkuvVf8QH90Se7",
    "gvIRbsXGW93i8rGy30GntxRQPX+/+zz6yeS8s2SuulnKb7seMBHJgf7o4+1Pt6/Tn/4Gwo8gfQ=",
    "=",
    ""
  };

  static char newstr [1577] = "";
  newstr[0] = '\0';
  for (i = 0; i < 23; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c2_car_model_FIXED(SimStruct *S)
{
  const char* newstr = sf_c2_car_model_FIXED_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(1738277929U));
  ssSetChecksum1(S,(3048356298U));
  ssSetChecksum2(S,(1296017124U));
  ssSetChecksum3(S,(631296863U));
}

static void mdlRTW_c2_car_model_FIXED(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c2_car_model_FIXED(SimStruct *S)
{
  SFc2_car_model_FIXEDInstanceStruct *chartInstance;
  chartInstance = (SFc2_car_model_FIXEDInstanceStruct *)utMalloc(sizeof
    (SFc2_car_model_FIXEDInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc2_car_model_FIXEDInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_car_model_FIXED;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_car_model_FIXED;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c2_car_model_FIXED;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c2_car_model_FIXED;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c2_car_model_FIXED;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_car_model_FIXED;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_car_model_FIXED;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_car_model_FIXED;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_car_model_FIXED;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_car_model_FIXED;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_car_model_FIXED;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_car_model_FIXED;
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
    chartInstance->c2_JITStateAnimation,
    chartInstance->c2_JITTransitionAnimation);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c2_car_model_FIXED(chartInstance);
}

void c2_car_model_FIXED_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c2_car_model_FIXED(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_car_model_FIXED(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_car_model_FIXED(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_car_model_FIXED_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
