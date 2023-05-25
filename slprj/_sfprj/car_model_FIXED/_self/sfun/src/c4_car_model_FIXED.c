/* Include files */

#include "car_model_FIXED_sfun.h"
#include "c4_car_model_FIXED.h"
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
static emlrtMCInfo c4_emlrtMCI = { 82, /* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pName */
};

static emlrtRSInfo c4_emlrtRSI = { 3,  /* lineNo */
  "Driver & Environment/Longitudinal Control/ABS/ABS system/MATLAB Function1",/* fcnName */
  "#car_model_FIXED:6685"              /* pathName */
};

static emlrtRSInfo c4_b_emlrtRSI = { 71,/* lineNo */
  "power",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

/* Function Declarations */
static void initialize_c4_car_model_FIXED(SFc4_car_model_FIXEDInstanceStruct
  *chartInstance);
static void initialize_params_c4_car_model_FIXED
  (SFc4_car_model_FIXEDInstanceStruct *chartInstance);
static void mdl_start_c4_car_model_FIXED(SFc4_car_model_FIXEDInstanceStruct
  *chartInstance);
static void mdl_terminate_c4_car_model_FIXED(SFc4_car_model_FIXEDInstanceStruct *
  chartInstance);
static void mdl_setup_runtime_resources_c4_car_model_FIXED
  (SFc4_car_model_FIXEDInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c4_car_model_FIXED
  (SFc4_car_model_FIXEDInstanceStruct *chartInstance);
static void enable_c4_car_model_FIXED(SFc4_car_model_FIXEDInstanceStruct
  *chartInstance);
static void disable_c4_car_model_FIXED(SFc4_car_model_FIXEDInstanceStruct
  *chartInstance);
static void sf_gateway_c4_car_model_FIXED(SFc4_car_model_FIXEDInstanceStruct
  *chartInstance);
static void ext_mode_exec_c4_car_model_FIXED(SFc4_car_model_FIXEDInstanceStruct *
  chartInstance);
static void c4_update_jit_animation_c4_car_model_FIXED
  (SFc4_car_model_FIXEDInstanceStruct *chartInstance);
static void c4_do_animation_call_c4_car_model_FIXED
  (SFc4_car_model_FIXEDInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_car_model_FIXED
  (SFc4_car_model_FIXEDInstanceStruct *chartInstance);
static void set_sim_state_c4_car_model_FIXED(SFc4_car_model_FIXEDInstanceStruct *
  chartInstance, const mxArray *c4_st);
static void initSimStructsc4_car_model_FIXED(SFc4_car_model_FIXEDInstanceStruct *
  chartInstance);
static void c4_emlrt_update_log_1(SFc4_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c4_in[4], emlrtLocationLoggingDataType c4_table[],
  int32_T c4_index, real_T c4_out[4]);
static real_T c4_emlrt_update_log_2(SFc4_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c4_in, emlrtLocationLoggingDataType c4_table[], int32_T
  c4_index);
static void c4_emlrtInitVarDataTables(SFc4_car_model_FIXEDInstanceStruct
  *chartInstance, emlrtLocationLoggingDataType c4_dataTables[10],
  emlrtLocationLoggingHistogramType c4_histTables[10]);
static void c4_emlrt_marshallIn(SFc4_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c4_b_y, const char_T *c4_identifier, real_T
  c4_c_y[4]);
static void c4_b_emlrt_marshallIn(SFc4_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c4_b_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_b_y[4]);
static uint8_T c4_c_emlrt_marshallIn(SFc4_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_car_model_FIXED, const char_T
  *c4_identifier);
static uint8_T c4_d_emlrt_marshallIn(SFc4_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c4_b_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_slStringInitializeDynamicBuffers
  (SFc4_car_model_FIXEDInstanceStruct *chartInstance);
static void c4_chart_data_browse_helper(SFc4_car_model_FIXEDInstanceStruct
  *chartInstance, int32_T c4_ssIdNumber, const mxArray **c4_mxData, uint8_T
  *c4_isValueTooBig);
static void c4_b_emlrt_update_log_1(SFc4_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c4_in[4], emlrtLocationLoggingDataType c4_table[],
  int32_T c4_index);
static int32_T c4__s32_add__(SFc4_car_model_FIXEDInstanceStruct *chartInstance,
  int32_T c4_b, int32_T c4_c, int32_T c4_EMLOvCount_src_loc, uint32_T
  c4_ssid_src_loc, int32_T c4_offset_src_loc, int32_T c4_length_src_loc);
static int32_T c4__s32_minus__(SFc4_car_model_FIXEDInstanceStruct *chartInstance,
  int32_T c4_b, int32_T c4_c, int32_T c4_EMLOvCount_src_loc, uint32_T
  c4_ssid_src_loc, int32_T c4_offset_src_loc, int32_T c4_length_src_loc);
static void init_dsm_address_info(SFc4_car_model_FIXEDInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc4_car_model_FIXEDInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c4_car_model_FIXED(SFc4_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_is_active_c4_car_model_FIXED = 0U;
  chartInstance->c4_emlrtLocLogSimulated = false;
  c4_emlrtInitVarDataTables(chartInstance,
    chartInstance->c4_emlrtLocationLoggingDataTables,
    chartInstance->c4_emlrtLocLogHistTables);
}

static void initialize_params_c4_car_model_FIXED
  (SFc4_car_model_FIXEDInstanceStruct *chartInstance)
{
  real_T c4_d;
  real_T c4_d1;
  sf_mex_import_named("mu_star", sf_mex_get_sfun_param(chartInstance->S, 1U, 0U),
                      &c4_d, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c4_mu_star = c4_d;
  sf_mex_import_named("lambda_star", sf_mex_get_sfun_param(chartInstance->S, 0U,
    0U), &c4_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c4_lambda_star = c4_d1;
}

static void mdl_start_c4_car_model_FIXED(SFc4_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void mdl_terminate_c4_car_model_FIXED(SFc4_car_model_FIXEDInstanceStruct *
  chartInstance)
{
  const emlrtLocationLoggingFileInfoType c4_emlrtLocationLoggingFileInfo = {
    "#car_model_FIXED:6685",           /* mexFileName */
    "Mon Apr 17 19:52:48 2023",        /* timestamp */
    "",                                /* buildDir */
    1,                                 /* numFcns */
    256                                /* numHistogramBins */
  };

  const emlrtLocationLoggingFunctionInfoType
    c4_emlrtLocationLoggingFunctionInfoTable[1] = { { "eML_blk_kernel",/* fcnName */
      1,                               /* fcnId */
      10                               /* numInstrPoints */
    } };

  const emlrtLocationLoggingLocationType c4_emlrtLocationInfo[11] = { { 1,/* MxInfoID */
      17,                              /* TextStart */
      1,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      19,                              /* TextStart */
      7,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      28,                              /* TextStart */
      11,                              /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      46,                              /* TextStart */
      1,                               /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      51,                              /* TextStart */
      49,                              /* TextLength */
      8,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      51,                              /* TextStart */
      26,                              /* TextLength */
      7,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      51,                              /* TextStart */
      23,                              /* TextLength */
      7,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      51,                              /* TextStart */
      10,                              /* TextLength */
      7,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      80,                              /* TextStart */
      19,                              /* TextLength */
      5,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      80,                              /* TextStart */
      14,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      95,                              /* TextStart */
      4,                               /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    } };

  const int32_T c4_emlrtLocationLoggingFieldCounts[10] = { 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0 };

  if (chartInstance->c4_emlrtLocLogSimulated) {
    emlrtLocationLoggingClearLog("#car_model_FIXED:6685");
    emlrtLocationLoggingPushLog(&c4_emlrtLocationLoggingFileInfo,
      &c4_emlrtLocationLoggingFunctionInfoTable[0],
      &chartInstance->c4_emlrtLocationLoggingDataTables[0],
      &c4_emlrtLocationInfo[0], NULL, 0U, &c4_emlrtLocationLoggingFieldCounts[0],
      NULL);
    addResultsToFPTRepository("#car_model_FIXED:6685");
  }
}

static void mdl_setup_runtime_resources_c4_car_model_FIXED
  (SFc4_car_model_FIXEDInstanceStruct *chartInstance)
{
  static const uint32_T c4_decisionTxtEndIdx = 0U;
  static const uint32_T c4_decisionTxtStartIdx = 0U;
  setDebuggerFlag(chartInstance->S, true);
  setDataBrowseFcn(chartInstance->S, (void *)&c4_chart_data_browse_helper);
  chartInstance->c4_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c4_RuntimeVar,
    &chartInstance->c4_IsDebuggerActive,
    &chartInstance->c4_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c4_mlFcnLineNumber, &chartInstance->c4_IsHeatMapPresent, 0);
  sim_mode_is_external(chartInstance->S);
  covrtCreateStateflowInstanceData(chartInstance->c4_covrtInstance, 1U, 0U, 1U,
    127U);
  covrtChartInitFcn(chartInstance->c4_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c4_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c4_decisionTxtStartIdx, &c4_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c4_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c4_covrtInstance, "", 4U, 0U, 1U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 107);
}

static void mdl_cleanup_runtime_resources_c4_car_model_FIXED
  (SFc4_car_model_FIXEDInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c4_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c4_covrtInstance);
}

static void enable_c4_car_model_FIXED(SFc4_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c4_car_model_FIXED(SFc4_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c4_car_model_FIXED(SFc4_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  real_T c4_b_y[4];
  real_T c4_a;
  real_T c4_b_a;
  real_T c4_b_lambda_star;
  real_T c4_b_mu_star;
  real_T c4_c_a;
  real_T c4_c_y;
  real_T c4_d;
  real_T c4_d1;
  real_T c4_d_a;
  real_T c4_d_y;
  real_T c4_e_a;
  int32_T c4_b_k;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_k;
  chartInstance->c4_JITTransitionAnimation[0] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  for (c4_i = 0; c4_i < 4; c4_i++) {
    covrtSigUpdateFcn(chartInstance->c4_covrtInstance, 0U, (*chartInstance->c4_u)
                      [c4_i]);
  }

  chartInstance->c4_sfEvent = CALL_EVENT;
  c4_b_mu_star = chartInstance->c4_mu_star;
  c4_b_lambda_star = chartInstance->c4_lambda_star;

  /* logging input variable 'u' for function 'eML_blk_kernel' */
  /* logging input variable 'mu_star' for function 'eML_blk_kernel' */
  /* logging input variable 'lambda_star' for function 'eML_blk_kernel' */
  chartInstance->c4_emlrtLocLogSimulated = true;

  /* logging input variable 'u' for function 'eML_blk_kernel' */
  for (c4_i1 = 0; c4_i1 < 4; c4_i1++) {
    c4_b_y[c4_i1] = (*chartInstance->c4_u)[c4_i1];
  }

  c4_b_emlrt_update_log_1(chartInstance, c4_b_y,
    chartInstance->c4_emlrtLocationLoggingDataTables, 0);

  /* logging input variable 'mu_star' for function 'eML_blk_kernel' */
  c4_emlrt_update_log_2(chartInstance, c4_b_mu_star,
                        chartInstance->c4_emlrtLocationLoggingDataTables, 1);

  /* logging input variable 'lambda_star' for function 'eML_blk_kernel' */
  c4_emlrt_update_log_2(chartInstance, c4_b_lambda_star,
                        chartInstance->c4_emlrtLocationLoggingDataTables, 2);
  covrtEmlFcnEval(chartInstance->c4_covrtInstance, 4U, 0, 0);
  c4_a = c4_b_lambda_star;
  c4_b_a = c4_a;
  c4_c_a = c4_b_a;
  c4_d_a = c4_c_a;
  c4_c_y = c4_d_a * c4_d_a;
  for (c4_k = 0; c4_k < 4; c4_k++) {
    c4_b_k = c4__s32_add__(chartInstance, 1, c4_k, 363, 1U, 95, 4);
    c4_e_a = (*chartInstance->c4_u)[c4__s32_minus__(chartInstance, c4_b_k, 1,
      364, 1U, 95, 4)];
    c4_d_y = c4_e_a * c4_e_a;
    c4_b_y[c4__s32_minus__(chartInstance, c4_b_k, 1, 365, 1U, 95, 4)] = c4_d_y;
  }

  c4_d = c4_emlrt_update_log_2(chartInstance, c4_emlrt_update_log_2
    (chartInstance, 2.0 * c4_b_mu_star,
     chartInstance->c4_emlrtLocationLoggingDataTables, 6) * c4_b_lambda_star,
    chartInstance->c4_emlrtLocationLoggingDataTables, 5);
  for (c4_i2 = 0; c4_i2 < 4; c4_i2++) {
    (*chartInstance->c4_y)[c4_i2] = c4_d * (*chartInstance->c4_u)[c4_i2];
  }

  c4_b_emlrt_update_log_1(chartInstance, *chartInstance->c4_y,
    chartInstance->c4_emlrtLocationLoggingDataTables, 4);
  c4_b_emlrt_update_log_1(chartInstance, c4_b_y,
    chartInstance->c4_emlrtLocationLoggingDataTables, 9);
  c4_d1 = c4_emlrt_update_log_2(chartInstance, c4_c_y,
    chartInstance->c4_emlrtLocationLoggingDataTables, 8);
  for (c4_i3 = 0; c4_i3 < 4; c4_i3++) {
    c4_b_y[c4_i3] += c4_d1;
  }

  c4_b_emlrt_update_log_1(chartInstance, c4_b_y,
    chartInstance->c4_emlrtLocationLoggingDataTables, 7);
  for (c4_i4 = 0; c4_i4 < 4; c4_i4++) {
    (*chartInstance->c4_y)[c4_i4] /= c4_b_y[c4_i4];
  }

  c4_b_emlrt_update_log_1(chartInstance, *chartInstance->c4_y,
    chartInstance->c4_emlrtLocationLoggingDataTables, 3);
  c4_do_animation_call_c4_car_model_FIXED(chartInstance);
  for (c4_i5 = 0; c4_i5 < 4; c4_i5++) {
    covrtSigUpdateFcn(chartInstance->c4_covrtInstance, 1U, (*chartInstance->c4_y)
                      [c4_i5]);
  }
}

static void ext_mode_exec_c4_car_model_FIXED(SFc4_car_model_FIXEDInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void c4_update_jit_animation_c4_car_model_FIXED
  (SFc4_car_model_FIXEDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c4_do_animation_call_c4_car_model_FIXED
  (SFc4_car_model_FIXEDInstanceStruct *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static const mxArray *get_sim_state_c4_car_model_FIXED
  (SFc4_car_model_FIXEDInstanceStruct *chartInstance)
{
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_st;
  c4_st = NULL;
  c4_st = NULL;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_createcellmatrix(2, 1), false);
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", *chartInstance->c4_y, 0, 0U, 1U, 0U,
    2, 1, 4), false);
  sf_mex_setcell(c4_b_y, 0, c4_c_y);
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y",
    &chartInstance->c4_is_active_c4_car_model_FIXED, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_b_y, 1, c4_d_y);
  sf_mex_assign(&c4_st, c4_b_y, false);
  return c4_st;
}

static void set_sim_state_c4_car_model_FIXED(SFc4_car_model_FIXEDInstanceStruct *
  chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_b_u;
  real_T c4_dv[4];
  int32_T c4_i;
  chartInstance->c4_doneDoubleBufferReInit = true;
  c4_b_u = sf_mex_dup(c4_st);
  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_b_u, 0)), "y",
                      c4_dv);
  for (c4_i = 0; c4_i < 4; c4_i++) {
    (*chartInstance->c4_y)[c4_i] = c4_dv[c4_i];
  }

  chartInstance->c4_is_active_c4_car_model_FIXED = c4_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_b_u, 1)),
     "is_active_c4_car_model_FIXED");
  sf_mex_destroy(&c4_b_u);
  sf_mex_destroy(&c4_st);
}

static void initSimStructsc4_car_model_FIXED(SFc4_car_model_FIXEDInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void c4_emlrt_update_log_1(SFc4_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c4_in[4], emlrtLocationLoggingDataType c4_table[],
  int32_T c4_index, real_T c4_out[4])
{
  int32_T c4_i;
  for (c4_i = 0; c4_i < 4; c4_i++) {
    c4_out[c4_i] = c4_in[c4_i];
  }

  c4_b_emlrt_update_log_1(chartInstance, c4_out, c4_table, c4_index);
}

static real_T c4_emlrt_update_log_2(SFc4_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c4_in, emlrtLocationLoggingDataType c4_table[], int32_T
  c4_index)
{
  emlrtLocationLoggingDataType *c4_b_table;
  emlrtLocationLoggingHistogramType *c4_histTable;
  real_T c4_inDouble;
  real_T c4_localMax;
  real_T c4_localMin;
  real_T c4_significand;
  int32_T c4_exponent;
  boolean_T c4_isLoggingEnabledHere;
  (void)chartInstance;
  c4_isLoggingEnabledHere = (c4_index >= 0);
  if (c4_isLoggingEnabledHere) {
    c4_b_table = (emlrtLocationLoggingDataType *)&c4_table[c4_index];
    c4_localMin = c4_b_table[0U].SimMin;
    c4_localMax = c4_b_table[0U].SimMax;
    c4_histTable = c4_b_table[0U].HistogramTable;

    /* Simulation Min-Max logging. */
    if (c4_in < c4_localMin) {
      c4_localMin = c4_in;
    }

    if (c4_in > c4_localMax) {
      c4_localMax = c4_in;
    }

    /* Histogram logging. */
    c4_inDouble = c4_in;
    c4_histTable->TotalNumberOfValues++;
    if (c4_inDouble == 0.0) {
      c4_histTable->NumberOfZeros++;
    } else {
      c4_histTable->SimSum += c4_inDouble;
      if ((!muDoubleScalarIsInf(c4_inDouble)) && (!muDoubleScalarIsNaN
           (c4_inDouble))) {
        c4_significand = frexp(c4_inDouble, &c4_exponent);
        if (c4_exponent > 128) {
          c4_exponent = 128;
        }

        if (c4_exponent < -127) {
          c4_exponent = -127;
        }

        if (c4_significand < 0.0) {
          c4_histTable->NumberOfNegativeValues++;
          c4_histTable->HistogramOfNegativeValues[127 + c4_exponent]++;
        } else {
          c4_histTable->NumberOfPositiveValues++;
          c4_histTable->HistogramOfPositiveValues[127 + c4_exponent]++;
        }
      }
    }

    c4_b_table[0U].SimMin = c4_localMin;
    c4_b_table[0U].SimMax = c4_localMax;

    /* IsAlwaysInteger logging. */
    if (c4_in != muDoubleScalarFloor(c4_in)) {
      c4_b_table[0U].IsAlwaysInteger = false;
    }
  }

  return c4_in;
}

static void c4_emlrtInitVarDataTables(SFc4_car_model_FIXEDInstanceStruct
  *chartInstance, emlrtLocationLoggingDataType c4_dataTables[10],
  emlrtLocationLoggingHistogramType c4_histTables[10])
{
  int32_T c4_i;
  int32_T c4_iH;
  (void)chartInstance;
  for (c4_i = 0; c4_i < 10; c4_i++) {
    c4_dataTables[c4_i].SimMin = rtInf;
    c4_dataTables[c4_i].SimMax = rtMinusInf;
    c4_dataTables[c4_i].OverflowWraps = 0;
    c4_dataTables[c4_i].Saturations = 0;
    c4_dataTables[c4_i].IsAlwaysInteger = true;
    c4_dataTables[c4_i].HistogramTable = &c4_histTables[c4_i];
    c4_histTables[c4_i].NumberOfZeros = 0.0;
    c4_histTables[c4_i].NumberOfPositiveValues = 0.0;
    c4_histTables[c4_i].NumberOfNegativeValues = 0.0;
    c4_histTables[c4_i].TotalNumberOfValues = 0.0;
    c4_histTables[c4_i].SimSum = 0.0;
    for (c4_iH = 0; c4_iH < 256; c4_iH++) {
      c4_histTables[c4_i].HistogramOfPositiveValues[c4_iH] = 0.0;
      c4_histTables[c4_i].HistogramOfNegativeValues[c4_iH] = 0.0;
    }
  }
}

const mxArray *sf_c4_car_model_FIXED_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c4_nameCaptureInfo;
}

static void c4_emlrt_marshallIn(SFc4_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c4_b_y, const char_T *c4_identifier, real_T
  c4_c_y[4])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char_T *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_y), &c4_thisId, c4_c_y);
  sf_mex_destroy(&c4_b_y);
}

static void c4_b_emlrt_marshallIn(SFc4_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c4_b_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_b_y[4])
{
  real_T c4_dv[4];
  int32_T c4_i;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_b_u), c4_dv, 1, 0, 0U, 1, 0U, 2, 1, 4);
  for (c4_i = 0; c4_i < 4; c4_i++) {
    c4_b_y[c4_i] = c4_dv[c4_i];
  }

  sf_mex_destroy(&c4_b_u);
}

static uint8_T c4_c_emlrt_marshallIn(SFc4_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_car_model_FIXED, const char_T
  *c4_identifier)
{
  emlrtMsgIdentifier c4_thisId;
  uint8_T c4_b_y;
  c4_thisId.fIdentifier = (const char_T *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_b_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_car_model_FIXED), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_car_model_FIXED);
  return c4_b_y;
}

static uint8_T c4_d_emlrt_marshallIn(SFc4_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c4_b_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_b_y;
  uint8_T c4_c_u;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_b_u), &c4_c_u, 1, 3, 0U, 0, 0U, 0);
  c4_b_y = c4_c_u;
  sf_mex_destroy(&c4_b_u);
  return c4_b_y;
}

static void c4_slStringInitializeDynamicBuffers
  (SFc4_car_model_FIXEDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c4_chart_data_browse_helper(SFc4_car_model_FIXEDInstanceStruct
  *chartInstance, int32_T c4_ssIdNumber, const mxArray **c4_mxData, uint8_T
  *c4_isValueTooBig)
{
  *c4_mxData = NULL;
  *c4_mxData = NULL;
  *c4_isValueTooBig = 0U;
  switch (c4_ssIdNumber) {
   case 4U:
    sf_mex_assign(c4_mxData, sf_mex_create("mxData", *chartInstance->c4_u, 0, 0U,
      1U, 0U, 2, 1, 4), false);
    break;

   case 5U:
    sf_mex_assign(c4_mxData, sf_mex_create("mxData", *chartInstance->c4_y, 0, 0U,
      1U, 0U, 2, 1, 4), false);
    break;

   case 6U:
    sf_mex_assign(c4_mxData, sf_mex_create("mxData", &chartInstance->c4_mu_star,
      0, 0U, 0U, 0U, 0), false);
    break;

   case 7U:
    sf_mex_assign(c4_mxData, sf_mex_create("mxData",
      &chartInstance->c4_lambda_star, 0, 0U, 0U, 0U, 0), false);
    break;
  }
}

static void c4_b_emlrt_update_log_1(SFc4_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c4_in[4], emlrtLocationLoggingDataType c4_table[],
  int32_T c4_index)
{
  emlrtLocationLoggingDataType *c4_b_table;
  emlrtLocationLoggingHistogramType *c4_histTable;
  real_T c4_inDouble;
  real_T c4_localMax;
  real_T c4_localMin;
  real_T c4_significand;
  int32_T c4_b_i;
  int32_T c4_exponent;
  int32_T c4_i;
  boolean_T c4_isLoggingEnabledHere;
  (void)chartInstance;
  c4_isLoggingEnabledHere = (c4_index >= 0);
  if (c4_isLoggingEnabledHere) {
    c4_b_table = (emlrtLocationLoggingDataType *)&c4_table[c4_index];
    c4_localMin = c4_b_table[0U].SimMin;
    c4_localMax = c4_b_table[0U].SimMax;
    c4_histTable = c4_b_table[0U].HistogramTable;
    for (c4_i = 0; c4_i < 4; c4_i++) {
      /* Simulation Min-Max logging. */
      if (c4_in[c4_i] < c4_localMin) {
        c4_localMin = c4_in[c4_i];
      }

      if (c4_in[c4_i] > c4_localMax) {
        c4_localMax = c4_in[c4_i];
      }

      /* Histogram logging. */
      c4_inDouble = c4_in[c4_i];
      c4_histTable->TotalNumberOfValues++;
      if (c4_inDouble == 0.0) {
        c4_histTable->NumberOfZeros++;
      } else {
        c4_histTable->SimSum += c4_inDouble;
        if ((!muDoubleScalarIsInf(c4_inDouble)) && (!muDoubleScalarIsNaN
             (c4_inDouble))) {
          c4_significand = frexp(c4_inDouble, &c4_exponent);
          if (c4_exponent > 128) {
            c4_exponent = 128;
          }

          if (c4_exponent < -127) {
            c4_exponent = -127;
          }

          if (c4_significand < 0.0) {
            c4_histTable->NumberOfNegativeValues++;
            c4_histTable->HistogramOfNegativeValues[127 + c4_exponent]++;
          } else {
            c4_histTable->NumberOfPositiveValues++;
            c4_histTable->HistogramOfPositiveValues[127 + c4_exponent]++;
          }
        }
      }
    }

    c4_b_table[0U].SimMin = c4_localMin;
    c4_b_table[0U].SimMax = c4_localMax;

    /* IsAlwaysInteger logging. */
    c4_b_i = 0;
    while (c4_b_table[0U].IsAlwaysInteger && (c4_b_i < 4)) {
      if (c4_in[c4_b_i] != muDoubleScalarFloor(c4_in[c4_b_i])) {
        c4_b_table[0U].IsAlwaysInteger = false;
      }

      c4_b_i++;
    }
  }
}

static int32_T c4__s32_add__(SFc4_car_model_FIXEDInstanceStruct *chartInstance,
  int32_T c4_b, int32_T c4_c, int32_T c4_EMLOvCount_src_loc, uint32_T
  c4_ssid_src_loc, int32_T c4_offset_src_loc, int32_T c4_length_src_loc)
{
  real_T c4_d;
  int32_T c4_PICOffset;
  int32_T c4_a;
  observerLogReadPIC(&c4_PICOffset);
  c4_a = c4_b + c4_c;
  if (((c4_a ^ c4_b) & (c4_a ^ c4_c)) < 0) {
    sf_data_overflow_error(chartInstance->S, c4_ssid_src_loc, c4_offset_src_loc,
      c4_length_src_loc);
    c4_d = 1.0;
    observerLog(c4_EMLOvCount_src_loc + c4_PICOffset, &c4_d, 1);
  }

  return c4_a;
}

static int32_T c4__s32_minus__(SFc4_car_model_FIXEDInstanceStruct *chartInstance,
  int32_T c4_b, int32_T c4_c, int32_T c4_EMLOvCount_src_loc, uint32_T
  c4_ssid_src_loc, int32_T c4_offset_src_loc, int32_T c4_length_src_loc)
{
  real_T c4_d;
  int32_T c4_PICOffset;
  int32_T c4_a;
  observerLogReadPIC(&c4_PICOffset);
  c4_a = c4_b - c4_c;
  if (((c4_b ^ c4_a) & (c4_b ^ c4_c)) < 0) {
    sf_data_overflow_error(chartInstance->S, c4_ssid_src_loc, c4_offset_src_loc,
      c4_length_src_loc);
    c4_d = 1.0;
    observerLog(c4_EMLOvCount_src_loc + c4_PICOffset, &c4_d, 1);
  }

  return c4_a;
}

static void init_dsm_address_info(SFc4_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc4_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  chartInstance->c4_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c4_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c4_u = (real_T (*)[4])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c4_y = (real_T (*)[4])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c4_car_model_FIXED_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2467907369U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(594260755U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4234221883U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1237078674U);
}

mxArray *sf_c4_car_model_FIXED_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c4_car_model_FIXED_jit_fallback_info(void)
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

mxArray *sf_c4_car_model_FIXED_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c4_car_model_FIXED(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiD+wcjAwAakOYCYiQECWKF8RqgYI1ycBS6uAMQllQWpIPHiomTPFCCdl5gL5ie"
    "WVnjmpeWDzbdgQJjPhsV8RiTzOaHiEPDBnjL9Ig4g/QZI+lkI6BcAsiqh4QILH/LtV3CgTD/E/g"
    "AC7pdBcT+En1kcn5hcklmWGp9sEp+cWBSfm5+SmhPv5hnh6sKA5D8ASAwaQQ=="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_car_model_FIXED_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "snpVbkJM5ucxIKoy8S5hbjE";
}

static void sf_opaque_initialize_c4_car_model_FIXED(void *chartInstanceVar)
{
  initialize_params_c4_car_model_FIXED((SFc4_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
  initialize_c4_car_model_FIXED((SFc4_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c4_car_model_FIXED(void *chartInstanceVar)
{
  enable_c4_car_model_FIXED((SFc4_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c4_car_model_FIXED(void *chartInstanceVar)
{
  disable_c4_car_model_FIXED((SFc4_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c4_car_model_FIXED(void *chartInstanceVar)
{
  sf_gateway_c4_car_model_FIXED((SFc4_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c4_car_model_FIXED(SimStruct* S)
{
  return get_sim_state_c4_car_model_FIXED((SFc4_car_model_FIXEDInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c4_car_model_FIXED(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c4_car_model_FIXED((SFc4_car_model_FIXEDInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c4_car_model_FIXED(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_car_model_FIXEDInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_car_model_FIXED_optimization_info();
    }

    mdl_cleanup_runtime_resources_c4_car_model_FIXED
      ((SFc4_car_model_FIXEDInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c4_car_model_FIXED(void *chartInstanceVar)
{
  mdl_start_c4_car_model_FIXED((SFc4_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_mdl_terminate_c4_car_model_FIXED(void *chartInstanceVar)
{
  mdl_terminate_c4_car_model_FIXED((SFc4_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_car_model_FIXED((SFc4_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_car_model_FIXED(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  sf_warn_if_symbolic_dimension_param_changed(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_car_model_FIXED((SFc4_car_model_FIXEDInstanceStruct*)
      sf_get_chart_instance_ptr(S));
    initSimStructsc4_car_model_FIXED((SFc4_car_model_FIXEDInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c4_car_model_FIXED_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [22] = {
    "eNrtWE1v40QYnkalYrWlqhASQqq0e+DABQkWKu0BLW0TBwINjXBaEJdqYr+Jh4xnvPORNGiv3Dl",
    "z2AsXjoh/wL/gN3Da4x55x3HTyA2pJ4Gyi7DkOGP7eb/m/TTZaLUJHjt4/vAWIVt4fRXPGpkerx",
    "Trjblzen+TfFSsn9wlJJIxDECEtt9nF8TvEDbtUEVTTfwPQVP4ErTk1jApWqIvq2OZ6IMCESGBT",
    "CrjxVez1HImhk0rIsdZf5WwKAkTaXl8hARpfCL45K/4ZtZ0kGODKYhMEyA2iZJ2kDQ5HSy3gjLj",
    "egLRUNvU21YaTGgzp6puW25YxiG4gKgltKFoBX2DvqGhBurmws/ITl8dXqJlmnFGRXVbJ1SHkKF",
    "3GDjNYvw9sQatVwkbJVSZI0joCPQxG+bcpYBK3JnGt3tMUCMVozxIed1Rq6hvh6OObQwJ7rtHqO",
    "+RAjrMJBPGMyDCJto5ELTHoQE9O/DkG8Jj66LhjMEYlN/+9utyBIoO4ET4yZzvUXCRO+UslipiD",
    "UvhjKrDCH1XQ+yXNzDodEjRHaGLZLywkJu4pbuKjdA3fHNdy4X/SrnOplPv1ythc77BCLz9asa3",
    "GYk65Vz7YbsyO4YR8Jx/gxq6AnbK3wOsNYu7Er3DZRvPjGUFw0gosHUpYlbdK0clVF7YvsAiVQH",
    "OUhcGEKOZZ6LPCN0UR1YbmdYx5TSOjyvyu45tCQOqTyOoXGMUZRpQ4NyvPPnGTLtAQjRayeRaVq",
    "YwjcGVoET3rWiMpRqijX2L2ZWtXCT4oSEeYGI2kCe5AL37jHJbUeZUDzB+0D1ONWZZP76IdfGzE",
    "jiiUQKxq5yMQxvzLBKousXalfxD1HbEzKQBOlIsqxpJFhM6Fl1npe4kg1MxFHIsmkqmYdF5LfEr",
    "AMwaVAkmBkdYwtWkicJXk1rB426e3X2bHGdnajjtOd/4BARWQ6er6xpohFEVCGyRUaB1sCH7Dps",
    "YoZk2WKgn01I/rXuuf/+UXPXvmwv699fn+vfdYh19eB5RdZ66XuW82fo6aJAZvffm6G1XmAdqFX",
    "DkGu6K3+X1nTn8xgK+ZO5a5nentlzOGv7bKHAHc7jXSnw2S7itwmZPf3py8uOv328/C85+e/rL2",
    "3+sw//nmt+8tVOs9y77plmWHl1LZFX84c2SP7i1FtlZb/hZe99GF63P5eRhuJ/0vg1yes83lstb",
    "K8l7ef++69UwiPOcoKJWXMxtbk3tdJ5w9B/Oybt1gz3uzPkTIc8+Xg//xkF5HzdvwO/iv0nJb1f",
    "nf/9gPfyUf+cG+fdK+72X9+7n1GVoOF+cCXb+hjjzxZFbxr0scv5vl39evyp17rZx5JZx6+rnW7",
    "9f9veX1Q1Sen/3BdZjWb736eNeNL1+J3591r1i/Wj2HaGeMB4vmGSKxzhs9Bc9/Y/493NP+132l",
    "YGzX/HB+ZsPDgXlExxdpqNhcbuj3HfD2SMFVC+eD/+NekIWzAmL+qrtUny79ZiJWI71u+8/2H+w",
    "Tn36E87SGxI=",
    ""
  };

  static char newstr [1513] = "";
  newstr[0] = '\0';
  for (i = 0; i < 22; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c4_car_model_FIXED(SimStruct *S)
{
  const char* newstr = sf_c4_car_model_FIXED_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(1333568414U));
  ssSetChecksum1(S,(210088602U));
  ssSetChecksum2(S,(3243656688U));
  ssSetChecksum3(S,(3928273054U));
}

static void mdlRTW_c4_car_model_FIXED(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c4_car_model_FIXED(SimStruct *S)
{
  SFc4_car_model_FIXEDInstanceStruct *chartInstance;
  chartInstance = (SFc4_car_model_FIXEDInstanceStruct *)utMalloc(sizeof
    (SFc4_car_model_FIXEDInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc4_car_model_FIXEDInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_car_model_FIXED;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_car_model_FIXED;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c4_car_model_FIXED;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c4_car_model_FIXED;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c4_car_model_FIXED;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_car_model_FIXED;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_car_model_FIXED;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_car_model_FIXED;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_car_model_FIXED;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_car_model_FIXED;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_car_model_FIXED;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_car_model_FIXED;
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
    chartInstance->c4_JITStateAnimation,
    chartInstance->c4_JITTransitionAnimation);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c4_car_model_FIXED(chartInstance);
}

void c4_car_model_FIXED_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c4_car_model_FIXED(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_car_model_FIXED(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_car_model_FIXED(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_car_model_FIXED_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
