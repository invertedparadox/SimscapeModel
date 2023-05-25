/* Include files */

#include "car_model_FIXED_sfun.h"
#include "c7_car_model_FIXED.h"
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
static emlrtMCInfo c7_emlrtMCI = { 82, /* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pName */
};

static emlrtRSInfo c7_emlrtRSI = { 3,  /* lineNo */
  "Vehicle Model/Vehicle/6DOF/Suspension to Chasiss Transforms/MATLAB Function",/* fcnName */
  "#car_model_FIXED:5904"              /* pathName */
};

static emlrtRSInfo c7_b_emlrtRSI = { 44,/* lineNo */
  "mpower",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\matfun\\mpower.m"/* pathName */
};

static emlrtRSInfo c7_c_emlrtRSI = { 71,/* lineNo */
  "power",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

/* Function Declarations */
static void initialize_c7_car_model_FIXED(SFc7_car_model_FIXEDInstanceStruct
  *chartInstance);
static void initialize_params_c7_car_model_FIXED
  (SFc7_car_model_FIXEDInstanceStruct *chartInstance);
static void mdl_start_c7_car_model_FIXED(SFc7_car_model_FIXEDInstanceStruct
  *chartInstance);
static void mdl_terminate_c7_car_model_FIXED(SFc7_car_model_FIXEDInstanceStruct *
  chartInstance);
static void mdl_setup_runtime_resources_c7_car_model_FIXED
  (SFc7_car_model_FIXEDInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c7_car_model_FIXED
  (SFc7_car_model_FIXEDInstanceStruct *chartInstance);
static void enable_c7_car_model_FIXED(SFc7_car_model_FIXEDInstanceStruct
  *chartInstance);
static void disable_c7_car_model_FIXED(SFc7_car_model_FIXEDInstanceStruct
  *chartInstance);
static void sf_gateway_c7_car_model_FIXED(SFc7_car_model_FIXEDInstanceStruct
  *chartInstance);
static void ext_mode_exec_c7_car_model_FIXED(SFc7_car_model_FIXEDInstanceStruct *
  chartInstance);
static void c7_update_jit_animation_c7_car_model_FIXED
  (SFc7_car_model_FIXEDInstanceStruct *chartInstance);
static void c7_do_animation_call_c7_car_model_FIXED
  (SFc7_car_model_FIXEDInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c7_car_model_FIXED
  (SFc7_car_model_FIXEDInstanceStruct *chartInstance);
static void set_sim_state_c7_car_model_FIXED(SFc7_car_model_FIXEDInstanceStruct *
  chartInstance, const mxArray *c7_st);
static void initSimStructsc7_car_model_FIXED(SFc7_car_model_FIXEDInstanceStruct *
  chartInstance);
static real_T c7_emlrt_update_log_1(SFc7_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c7_in, emlrtLocationLoggingDataType c7_table[], int32_T
  c7_index);
static void c7_emlrt_update_log_2(SFc7_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c7_in[3], emlrtLocationLoggingDataType c7_table[],
  int32_T c7_index, real_T c7_out[3]);
static void c7_emlrtInitVarDataTables(SFc7_car_model_FIXEDInstanceStruct
  *chartInstance, emlrtLocationLoggingDataType c7_dataTables[5],
  emlrtLocationLoggingHistogramType c7_histTables[5]);
static void c7_emlrt_marshallIn(SFc7_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c7_b_y, const char_T *c7_identifier, real_T
  c7_c_y[3]);
static void c7_b_emlrt_marshallIn(SFc7_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c7_b_u, const emlrtMsgIdentifier *c7_parentId,
  real_T c7_b_y[3]);
static uint8_T c7_c_emlrt_marshallIn(SFc7_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c7_b_is_active_c7_car_model_FIXED, const char_T
  *c7_identifier);
static uint8_T c7_d_emlrt_marshallIn(SFc7_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c7_b_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_slStringInitializeDynamicBuffers
  (SFc7_car_model_FIXEDInstanceStruct *chartInstance);
static void c7_chart_data_browse_helper(SFc7_car_model_FIXEDInstanceStruct
  *chartInstance, int32_T c7_ssIdNumber, const mxArray **c7_mxData, uint8_T
  *c7_isValueTooBig);
static void c7_b_emlrt_update_log_2(SFc7_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c7_in[3], emlrtLocationLoggingDataType c7_table[],
  int32_T c7_index);
static void init_dsm_address_info(SFc7_car_model_FIXEDInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc7_car_model_FIXEDInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c7_car_model_FIXED(SFc7_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
  chartInstance->c7_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c7_is_active_c7_car_model_FIXED = 0U;
  chartInstance->c7_emlrtLocLogSimulated = false;
  c7_emlrtInitVarDataTables(chartInstance,
    chartInstance->c7_emlrtLocationLoggingDataTables,
    chartInstance->c7_emlrtLocLogHistTables);
}

static void initialize_params_c7_car_model_FIXED
  (SFc7_car_model_FIXEDInstanceStruct *chartInstance)
{
  real_T c7_d;
  sf_mex_import_named("aero_coeff", sf_mex_get_sfun_param(chartInstance->S, 0U,
    0U), &c7_d, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c7_aero_coeff = c7_d;
}

static void mdl_start_c7_car_model_FIXED(SFc7_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void mdl_terminate_c7_car_model_FIXED(SFc7_car_model_FIXEDInstanceStruct *
  chartInstance)
{
  const emlrtLocationLoggingFileInfoType c7_emlrtLocationLoggingFileInfo = {
    "#car_model_FIXED:5904",           /* mexFileName */
    "Mon Apr 17 21:46:04 2023",        /* timestamp */
    "",                                /* buildDir */
    1,                                 /* numFcns */
    256                                /* numHistogramBins */
  };

  const emlrtLocationLoggingFunctionInfoType
    c7_emlrtLocationLoggingFunctionInfoTable[1] = { { "eML_blk_kernel",/* fcnName */
      1,                               /* fcnId */
      5                                /* numInstrPoints */
    } };

  const emlrtLocationLoggingLocationType c7_emlrtLocationInfo[6] = { { 1,/* MxInfoID */
      17,                              /* TextStart */
      1,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      20,                              /* TextStart */
      10,                              /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      33,                              /* TextStart */
      2,                               /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      38,                              /* TextStart */
      14,                              /* TextLength */
      7,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      49,                              /* TextStart */
      3,                               /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      56,                              /* TextStart */
      1,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    } };

  const int32_T c7_emlrtLocationLoggingFieldCounts[5] = { 0, 0, 0, 0, 0 };

  if (chartInstance->c7_emlrtLocLogSimulated) {
    emlrtLocationLoggingClearLog("#car_model_FIXED:5904");
    emlrtLocationLoggingPushLog(&c7_emlrtLocationLoggingFileInfo,
      &c7_emlrtLocationLoggingFunctionInfoTable[0],
      &chartInstance->c7_emlrtLocationLoggingDataTables[0],
      &c7_emlrtLocationInfo[0], NULL, 0U, &c7_emlrtLocationLoggingFieldCounts[0],
      NULL);
    addResultsToFPTRepository("#car_model_FIXED:5904");
  }
}

static void mdl_setup_runtime_resources_c7_car_model_FIXED
  (SFc7_car_model_FIXEDInstanceStruct *chartInstance)
{
  static const uint32_T c7_decisionTxtEndIdx = 0U;
  static const uint32_T c7_decisionTxtStartIdx = 0U;
  setDebuggerFlag(chartInstance->S, true);
  setDataBrowseFcn(chartInstance->S, (void *)&c7_chart_data_browse_helper);
  chartInstance->c7_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c7_RuntimeVar,
    &chartInstance->c7_IsDebuggerActive,
    &chartInstance->c7_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c7_mlFcnLineNumber, &chartInstance->c7_IsHeatMapPresent, 0);
  sim_mode_is_external(chartInstance->S);
  covrtCreateStateflowInstanceData(chartInstance->c7_covrtInstance, 1U, 0U, 1U,
    126U);
  covrtChartInitFcn(chartInstance->c7_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c7_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c7_decisionTxtStartIdx, &c7_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c7_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c7_covrtInstance, "", 4U, 0U, 1U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c7_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 70);
}

static void mdl_cleanup_runtime_resources_c7_car_model_FIXED
  (SFc7_car_model_FIXEDInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c7_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c7_covrtInstance);
}

static void enable_c7_car_model_FIXED(SFc7_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c7_car_model_FIXED(SFc7_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c7_car_model_FIXED(SFc7_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  real_T c7_Fz;
  real_T c7_a;
  real_T c7_b_a;
  real_T c7_b_aero_coeff;
  real_T c7_b_u;
  real_T c7_c;
  real_T c7_c_a;
  real_T c7_d_a;
  real_T c7_e_a;
  int32_T c7_i;
  chartInstance->c7_JITTransitionAnimation[0] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  covrtSigUpdateFcn(chartInstance->c7_covrtInstance, 0U, *chartInstance->c7_u);
  chartInstance->c7_sfEvent = CALL_EVENT;
  c7_b_u = *chartInstance->c7_u;
  c7_b_aero_coeff = chartInstance->c7_aero_coeff;

  /* logging input variable 'u' for function 'eML_blk_kernel' */
  /* logging input variable 'aero_coeff' for function 'eML_blk_kernel' */
  chartInstance->c7_emlrtLocLogSimulated = true;

  /* logging input variable 'u' for function 'eML_blk_kernel' */
  c7_emlrt_update_log_1(chartInstance, c7_b_u,
                        chartInstance->c7_emlrtLocationLoggingDataTables, 0);

  /* logging input variable 'aero_coeff' for function 'eML_blk_kernel' */
  c7_emlrt_update_log_1(chartInstance, c7_b_aero_coeff,
                        chartInstance->c7_emlrtLocationLoggingDataTables, 1);
  covrtEmlFcnEval(chartInstance->c7_covrtInstance, 4U, 0, 0);
  c7_a = c7_b_u;
  c7_b_a = c7_a;
  c7_c_a = c7_b_a;
  c7_d_a = c7_c_a;
  c7_e_a = c7_d_a;
  c7_c = c7_e_a * c7_e_a;
  c7_Fz = c7_emlrt_update_log_1(chartInstance, c7_b_aero_coeff *
    c7_emlrt_update_log_1(chartInstance, c7_c,
    chartInstance->c7_emlrtLocationLoggingDataTables, 3),
    chartInstance->c7_emlrtLocationLoggingDataTables, 2);
  (*chartInstance->c7_y)[0] = 0.0;
  (*chartInstance->c7_y)[1] = 0.0;
  (*chartInstance->c7_y)[2] = c7_Fz;
  c7_b_emlrt_update_log_2(chartInstance, *chartInstance->c7_y,
    chartInstance->c7_emlrtLocationLoggingDataTables, 4);
  c7_do_animation_call_c7_car_model_FIXED(chartInstance);
  for (c7_i = 0; c7_i < 3; c7_i++) {
    covrtSigUpdateFcn(chartInstance->c7_covrtInstance, 1U, (*chartInstance->c7_y)
                      [c7_i]);
  }
}

static void ext_mode_exec_c7_car_model_FIXED(SFc7_car_model_FIXEDInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void c7_update_jit_animation_c7_car_model_FIXED
  (SFc7_car_model_FIXEDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c7_do_animation_call_c7_car_model_FIXED
  (SFc7_car_model_FIXEDInstanceStruct *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static const mxArray *get_sim_state_c7_car_model_FIXED
  (SFc7_car_model_FIXEDInstanceStruct *chartInstance)
{
  const mxArray *c7_b_y = NULL;
  const mxArray *c7_c_y = NULL;
  const mxArray *c7_d_y = NULL;
  const mxArray *c7_st;
  c7_st = NULL;
  c7_st = NULL;
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_createcellmatrix(2, 1), false);
  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y", *chartInstance->c7_y, 0, 0U, 1U, 0U,
    2, 1, 3), false);
  sf_mex_setcell(c7_b_y, 0, c7_c_y);
  c7_d_y = NULL;
  sf_mex_assign(&c7_d_y, sf_mex_create("y",
    &chartInstance->c7_is_active_c7_car_model_FIXED, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_b_y, 1, c7_d_y);
  sf_mex_assign(&c7_st, c7_b_y, false);
  return c7_st;
}

static void set_sim_state_c7_car_model_FIXED(SFc7_car_model_FIXEDInstanceStruct *
  chartInstance, const mxArray *c7_st)
{
  const mxArray *c7_b_u;
  real_T c7_dv[3];
  int32_T c7_i;
  chartInstance->c7_doneDoubleBufferReInit = true;
  c7_b_u = sf_mex_dup(c7_st);
  c7_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c7_b_u, 0)), "y",
                      c7_dv);
  for (c7_i = 0; c7_i < 3; c7_i++) {
    (*chartInstance->c7_y)[c7_i] = c7_dv[c7_i];
  }

  chartInstance->c7_is_active_c7_car_model_FIXED = c7_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c7_b_u, 1)),
     "is_active_c7_car_model_FIXED");
  sf_mex_destroy(&c7_b_u);
  sf_mex_destroy(&c7_st);
}

static void initSimStructsc7_car_model_FIXED(SFc7_car_model_FIXEDInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static real_T c7_emlrt_update_log_1(SFc7_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c7_in, emlrtLocationLoggingDataType c7_table[], int32_T
  c7_index)
{
  emlrtLocationLoggingDataType *c7_b_table;
  emlrtLocationLoggingHistogramType *c7_histTable;
  real_T c7_inDouble;
  real_T c7_localMax;
  real_T c7_localMin;
  real_T c7_significand;
  int32_T c7_exponent;
  boolean_T c7_isLoggingEnabledHere;
  (void)chartInstance;
  c7_isLoggingEnabledHere = (c7_index >= 0);
  if (c7_isLoggingEnabledHere) {
    c7_b_table = (emlrtLocationLoggingDataType *)&c7_table[c7_index];
    c7_localMin = c7_b_table[0U].SimMin;
    c7_localMax = c7_b_table[0U].SimMax;
    c7_histTable = c7_b_table[0U].HistogramTable;

    /* Simulation Min-Max logging. */
    if (c7_in < c7_localMin) {
      c7_localMin = c7_in;
    }

    if (c7_in > c7_localMax) {
      c7_localMax = c7_in;
    }

    /* Histogram logging. */
    c7_inDouble = c7_in;
    c7_histTable->TotalNumberOfValues++;
    if (c7_inDouble == 0.0) {
      c7_histTable->NumberOfZeros++;
    } else {
      c7_histTable->SimSum += c7_inDouble;
      if ((!muDoubleScalarIsInf(c7_inDouble)) && (!muDoubleScalarIsNaN
           (c7_inDouble))) {
        c7_significand = frexp(c7_inDouble, &c7_exponent);
        if (c7_exponent > 128) {
          c7_exponent = 128;
        }

        if (c7_exponent < -127) {
          c7_exponent = -127;
        }

        if (c7_significand < 0.0) {
          c7_histTable->NumberOfNegativeValues++;
          c7_histTable->HistogramOfNegativeValues[127 + c7_exponent]++;
        } else {
          c7_histTable->NumberOfPositiveValues++;
          c7_histTable->HistogramOfPositiveValues[127 + c7_exponent]++;
        }
      }
    }

    c7_b_table[0U].SimMin = c7_localMin;
    c7_b_table[0U].SimMax = c7_localMax;

    /* IsAlwaysInteger logging. */
    if (c7_in != muDoubleScalarFloor(c7_in)) {
      c7_b_table[0U].IsAlwaysInteger = false;
    }
  }

  return c7_in;
}

static void c7_emlrt_update_log_2(SFc7_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c7_in[3], emlrtLocationLoggingDataType c7_table[],
  int32_T c7_index, real_T c7_out[3])
{
  int32_T c7_i;
  for (c7_i = 0; c7_i < 3; c7_i++) {
    c7_out[c7_i] = c7_in[c7_i];
  }

  c7_b_emlrt_update_log_2(chartInstance, c7_out, c7_table, c7_index);
}

static void c7_emlrtInitVarDataTables(SFc7_car_model_FIXEDInstanceStruct
  *chartInstance, emlrtLocationLoggingDataType c7_dataTables[5],
  emlrtLocationLoggingHistogramType c7_histTables[5])
{
  int32_T c7_i;
  int32_T c7_iH;
  (void)chartInstance;
  for (c7_i = 0; c7_i < 5; c7_i++) {
    c7_dataTables[c7_i].SimMin = rtInf;
    c7_dataTables[c7_i].SimMax = rtMinusInf;
    c7_dataTables[c7_i].OverflowWraps = 0;
    c7_dataTables[c7_i].Saturations = 0;
    c7_dataTables[c7_i].IsAlwaysInteger = true;
    c7_dataTables[c7_i].HistogramTable = &c7_histTables[c7_i];
    c7_histTables[c7_i].NumberOfZeros = 0.0;
    c7_histTables[c7_i].NumberOfPositiveValues = 0.0;
    c7_histTables[c7_i].NumberOfNegativeValues = 0.0;
    c7_histTables[c7_i].TotalNumberOfValues = 0.0;
    c7_histTables[c7_i].SimSum = 0.0;
    for (c7_iH = 0; c7_iH < 256; c7_iH++) {
      c7_histTables[c7_i].HistogramOfPositiveValues[c7_iH] = 0.0;
      c7_histTables[c7_i].HistogramOfNegativeValues[c7_iH] = 0.0;
    }
  }
}

const mxArray *sf_c7_car_model_FIXED_get_eml_resolved_functions_info(void)
{
  const mxArray *c7_nameCaptureInfo = NULL;
  c7_nameCaptureInfo = NULL;
  sf_mex_assign(&c7_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c7_nameCaptureInfo;
}

static void c7_emlrt_marshallIn(SFc7_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c7_b_y, const char_T *c7_identifier, real_T
  c7_c_y[3])
{
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = (const char_T *)c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_y), &c7_thisId, c7_c_y);
  sf_mex_destroy(&c7_b_y);
}

static void c7_b_emlrt_marshallIn(SFc7_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c7_b_u, const emlrtMsgIdentifier *c7_parentId,
  real_T c7_b_y[3])
{
  real_T c7_dv[3];
  int32_T c7_i;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_b_u), c7_dv, 1, 0, 0U, 1, 0U, 2, 1, 3);
  for (c7_i = 0; c7_i < 3; c7_i++) {
    c7_b_y[c7_i] = c7_dv[c7_i];
  }

  sf_mex_destroy(&c7_b_u);
}

static uint8_T c7_c_emlrt_marshallIn(SFc7_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c7_b_is_active_c7_car_model_FIXED, const char_T
  *c7_identifier)
{
  emlrtMsgIdentifier c7_thisId;
  uint8_T c7_b_y;
  c7_thisId.fIdentifier = (const char_T *)c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_b_y = c7_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c7_b_is_active_c7_car_model_FIXED), &c7_thisId);
  sf_mex_destroy(&c7_b_is_active_c7_car_model_FIXED);
  return c7_b_y;
}

static uint8_T c7_d_emlrt_marshallIn(SFc7_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c7_b_u, const emlrtMsgIdentifier *c7_parentId)
{
  uint8_T c7_b_y;
  uint8_T c7_c_u;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_b_u), &c7_c_u, 1, 3, 0U, 0, 0U, 0);
  c7_b_y = c7_c_u;
  sf_mex_destroy(&c7_b_u);
  return c7_b_y;
}

static void c7_slStringInitializeDynamicBuffers
  (SFc7_car_model_FIXEDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c7_chart_data_browse_helper(SFc7_car_model_FIXEDInstanceStruct
  *chartInstance, int32_T c7_ssIdNumber, const mxArray **c7_mxData, uint8_T
  *c7_isValueTooBig)
{
  real_T c7_d;
  *c7_mxData = NULL;
  *c7_mxData = NULL;
  *c7_isValueTooBig = 0U;
  switch (c7_ssIdNumber) {
   case 4U:
    c7_d = *chartInstance->c7_u;
    sf_mex_assign(c7_mxData, sf_mex_create("mxData", &c7_d, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 5U:
    sf_mex_assign(c7_mxData, sf_mex_create("mxData", *chartInstance->c7_y, 0, 0U,
      1U, 0U, 2, 1, 3), false);
    break;

   case 6U:
    sf_mex_assign(c7_mxData, sf_mex_create("mxData",
      &chartInstance->c7_aero_coeff, 0, 0U, 0U, 0U, 0), false);
    break;
  }
}

static void c7_b_emlrt_update_log_2(SFc7_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c7_in[3], emlrtLocationLoggingDataType c7_table[],
  int32_T c7_index)
{
  emlrtLocationLoggingDataType *c7_b_table;
  emlrtLocationLoggingHistogramType *c7_histTable;
  real_T c7_inDouble;
  real_T c7_localMax;
  real_T c7_localMin;
  real_T c7_significand;
  int32_T c7_b_i;
  int32_T c7_exponent;
  int32_T c7_i;
  boolean_T c7_isLoggingEnabledHere;
  (void)chartInstance;
  c7_isLoggingEnabledHere = (c7_index >= 0);
  if (c7_isLoggingEnabledHere) {
    c7_b_table = (emlrtLocationLoggingDataType *)&c7_table[c7_index];
    c7_localMin = c7_b_table[0U].SimMin;
    c7_localMax = c7_b_table[0U].SimMax;
    c7_histTable = c7_b_table[0U].HistogramTable;
    for (c7_i = 0; c7_i < 3; c7_i++) {
      /* Simulation Min-Max logging. */
      if (c7_in[c7_i] < c7_localMin) {
        c7_localMin = c7_in[c7_i];
      }

      if (c7_in[c7_i] > c7_localMax) {
        c7_localMax = c7_in[c7_i];
      }

      /* Histogram logging. */
      c7_inDouble = c7_in[c7_i];
      c7_histTable->TotalNumberOfValues++;
      if (c7_inDouble == 0.0) {
        c7_histTable->NumberOfZeros++;
      } else {
        c7_histTable->SimSum += c7_inDouble;
        if ((!muDoubleScalarIsInf(c7_inDouble)) && (!muDoubleScalarIsNaN
             (c7_inDouble))) {
          c7_significand = frexp(c7_inDouble, &c7_exponent);
          if (c7_exponent > 128) {
            c7_exponent = 128;
          }

          if (c7_exponent < -127) {
            c7_exponent = -127;
          }

          if (c7_significand < 0.0) {
            c7_histTable->NumberOfNegativeValues++;
            c7_histTable->HistogramOfNegativeValues[127 + c7_exponent]++;
          } else {
            c7_histTable->NumberOfPositiveValues++;
            c7_histTable->HistogramOfPositiveValues[127 + c7_exponent]++;
          }
        }
      }
    }

    c7_b_table[0U].SimMin = c7_localMin;
    c7_b_table[0U].SimMax = c7_localMax;

    /* IsAlwaysInteger logging. */
    c7_b_i = 0;
    while (c7_b_table[0U].IsAlwaysInteger && (c7_b_i < 3)) {
      if (c7_in[c7_b_i] != muDoubleScalarFloor(c7_in[c7_b_i])) {
        c7_b_table[0U].IsAlwaysInteger = false;
      }

      c7_b_i++;
    }
  }
}

static void init_dsm_address_info(SFc7_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc7_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  chartInstance->c7_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c7_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c7_u = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    0);
  chartInstance->c7_y = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c7_car_model_FIXED_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3146882134U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3796542434U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4047239248U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3532304428U);
}

mxArray *sf_c7_car_model_FIXED_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c7_car_model_FIXED_jit_fallback_info(void)
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

mxArray *sf_c7_car_model_FIXED_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c7_car_model_FIXED(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiD+wcjAwAakOYCYiQECWKF8RqgYI1ycBS6uAMQllQWpIPHiomTPFCCdl5gL5ie"
    "WVnjmpeWDzbdgQJjPhsV8RiTzOaHiEPDBnjL9Ig4g/QZI+lkI6BcAsiqh4QILH/LtV3CgTD/E/g"
    "AC7pdBcT+En1kcn5hcklmWGp9sHp+cWBSfm5+SmhPv5hnh6sKA5D8ASGMaRA=="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c7_car_model_FIXED_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sRfF8tmCyCA3hjw7FEn1bTF";
}

static void sf_opaque_initialize_c7_car_model_FIXED(void *chartInstanceVar)
{
  initialize_params_c7_car_model_FIXED((SFc7_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
  initialize_c7_car_model_FIXED((SFc7_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c7_car_model_FIXED(void *chartInstanceVar)
{
  enable_c7_car_model_FIXED((SFc7_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c7_car_model_FIXED(void *chartInstanceVar)
{
  disable_c7_car_model_FIXED((SFc7_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c7_car_model_FIXED(void *chartInstanceVar)
{
  sf_gateway_c7_car_model_FIXED((SFc7_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c7_car_model_FIXED(SimStruct* S)
{
  return get_sim_state_c7_car_model_FIXED((SFc7_car_model_FIXEDInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c7_car_model_FIXED(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c7_car_model_FIXED((SFc7_car_model_FIXEDInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c7_car_model_FIXED(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc7_car_model_FIXEDInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_car_model_FIXED_optimization_info();
    }

    mdl_cleanup_runtime_resources_c7_car_model_FIXED
      ((SFc7_car_model_FIXEDInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c7_car_model_FIXED(void *chartInstanceVar)
{
  mdl_start_c7_car_model_FIXED((SFc7_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_mdl_terminate_c7_car_model_FIXED(void *chartInstanceVar)
{
  mdl_terminate_c7_car_model_FIXED((SFc7_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc7_car_model_FIXED((SFc7_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c7_car_model_FIXED(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  sf_warn_if_symbolic_dimension_param_changed(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c7_car_model_FIXED((SFc7_car_model_FIXEDInstanceStruct*)
      sf_get_chart_instance_ptr(S));
    initSimStructsc7_car_model_FIXED((SFc7_car_model_FIXEDInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c7_car_model_FIXED_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [22] = {
    "eNrtWE1v40QYnlSlYmGpKoQESJV2j1wQ7C5o94CgrRNDpJZG67SsuEQT+008ZDz2zkfSIH4EJ34",
    "CQuI/cOXIlQN3Lhw4oT3yjuOkkRsST1KW3RWWHGdsP+/XvJ8mteYJwWMXz2/fJmQHry/juUUmx0",
    "vFujZ3Tu5vk4+K9TevEhKmEfRBBKbXYxfE7RAmaVFJE0XcD0ETeAgq5UazVDRFL62OZaIHEkSIB",
    "LJUaie+iiWGMzHwjQgtZ/VFzMI4iFPDoyMkSKNTwcf/xDczuoUc60xCqH2ASMcyNf3Y57S/3ApS",
    "j7wYwoEyibOtFOjAZFZVdWK4ZhmHxgWETaE0RSuoFfoGmmrw9IWbka2+Kpii0yTjjIrqto6pCiB",
    "D79BwlkX4e2o0Wq8SNoyp1EcQ0yGoYzbIuacCKnFnCt/uMkF1KhnljYR7llpFfVscdTzBkOCue4",
    "T6HkmggyxlQjsGROCjnRuCdjnUoWv6jnwDeGxsNJwzGIF029+elw5B0j6cCjeZ8z1qXOROOYuli",
    "ljNEjin8jBE31UQueUNDDoVUHRHaCMZJyzkJm6qtmRD9A3XXNe04b9WrjPJxPvVWticb2MIzn41",
    "4+uHwqOcKzdsO82OYQg851+nmq6BnfB3ACvFonaK3mGzjWPGMoJhJBRYLxURq+6VwxIqL2yfY5G",
    "qAGeJDQOI0Mwz0WeEVsWRUTpNPEw59ePjivyuYptCg+zRECrXGEmZAhQ49ytHvhFTNpAQjVbSuZ",
    "aVKUxicC0oUT0j6qNUDtDGrsXs0lY2EtzQEPUxMWvIk1wDvfucclNR5kT1MX7QPc4UZlk3voi18",
    "bMWOKRhDJGtnIzDCeZZJFB1i5Ut+Yeo7ZDpcR1UKFlWNZIMJnQsutZK7XEGZ2Ig0pHwZZoERee1",
    "xK8AMGtQKZjoH2EJl2Mfha8mtYTH7Ty7uzY51s5Uc9q1vvEpCKyGVlfbNdAQo6ohsEVGgTbBBux",
    "rbGKEYkpjoR5PSv2k7tn+/TNy2b9vL+jfX5/r3/eKdXi/E1LZSWyv0vGbjxp1MqP3/hy9mxXmgV",
    "oFHLmCu+Q3vb4zh68t4EvmrmV+N7aWy7mF/6ZyHszhXivx2S7hdgqb/fLjrd8+ePTz99/99Psfb",
    "73y3l+b8P9hy23e2i3W+9O+aZalh1cSWRV/eLPkD3atHvb8Bzrxxt7hvfir0X2/Ie50235O70lt",
    "ubxbJXmn92/bXg2DOM8JMmxGxdxm19RM5glL/8GcvDsr7HFjzp8I+fOTzfBvHJT3cXsFfg//jUt",
    "+uz7/2web4Sf8Wyvk3y/t937eu3eozdDQWZwJdq8hzlxx5Cnjnhc5/7fLv6/fddW568SRp4zbVD",
    "/X+v28v7+sbpDS+3vPsB7L8r1LH/es6fUrceuzbhXrj2ffEbyY8WjBJFM8xmGjt+jpC+LfTxztN",
    "+0rG9Z+xQfnL+8dCsrHOLpMRsPidkva74azRxKoWjwf/hf1hCyYExb1VTdL8W3XIyaidKTevXP3",
    "w7ub1Ke/AWIwGsA=",
    ""
  };

  static char newstr [1517] = "";
  newstr[0] = '\0';
  for (i = 0; i < 22; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c7_car_model_FIXED(SimStruct *S)
{
  const char* newstr = sf_c7_car_model_FIXED_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(3693063119U));
  ssSetChecksum1(S,(2798082100U));
  ssSetChecksum2(S,(3974610582U));
  ssSetChecksum3(S,(4130277912U));
}

static void mdlRTW_c7_car_model_FIXED(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c7_car_model_FIXED(SimStruct *S)
{
  SFc7_car_model_FIXEDInstanceStruct *chartInstance;
  chartInstance = (SFc7_car_model_FIXEDInstanceStruct *)utMalloc(sizeof
    (SFc7_car_model_FIXEDInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc7_car_model_FIXEDInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c7_car_model_FIXED;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c7_car_model_FIXED;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c7_car_model_FIXED;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c7_car_model_FIXED;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c7_car_model_FIXED;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c7_car_model_FIXED;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c7_car_model_FIXED;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c7_car_model_FIXED;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c7_car_model_FIXED;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c7_car_model_FIXED;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c7_car_model_FIXED;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c7_car_model_FIXED;
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
    chartInstance->c7_JITStateAnimation,
    chartInstance->c7_JITTransitionAnimation);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c7_car_model_FIXED(chartInstance);
}

void c7_car_model_FIXED_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c7_car_model_FIXED(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c7_car_model_FIXED(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c7_car_model_FIXED(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c7_car_model_FIXED_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
