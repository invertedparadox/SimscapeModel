/* Include files */

#include "car_model_FIXED_sfun.h"
#include "c1_car_model_FIXED.h"
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
static emlrtMCInfo c1_emlrtMCI = { 82, /* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pName */
};

static emlrtMCInfo c1_b_emlrtMCI = { 13,/* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pName */
};

static emlrtRSInfo c1_emlrtRSI = { 17, /* lineNo */
  "Driver & Environment/Longitudinal Control/ABS/ABS system/MATLAB Function",/* fcnName */
  "#car_model_FIXED:6684"              /* pathName */
};

static emlrtRSInfo c1_b_emlrtRSI = { 18,/* lineNo */
  "Driver & Environment/Longitudinal Control/ABS/ABS system/MATLAB Function",/* fcnName */
  "#car_model_FIXED:6684"              /* pathName */
};

static emlrtRSInfo c1_c_emlrtRSI = { 44,/* lineNo */
  "mpower",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\matfun\\mpower.m"/* pathName */
};

static emlrtRSInfo c1_d_emlrtRSI = { 71,/* lineNo */
  "power",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

/* Function Declarations */
static void initialize_c1_car_model_FIXED(SFc1_car_model_FIXEDInstanceStruct
  *chartInstance);
static void initialize_params_c1_car_model_FIXED
  (SFc1_car_model_FIXEDInstanceStruct *chartInstance);
static void mdl_start_c1_car_model_FIXED(SFc1_car_model_FIXEDInstanceStruct
  *chartInstance);
static void mdl_terminate_c1_car_model_FIXED(SFc1_car_model_FIXEDInstanceStruct *
  chartInstance);
static void mdl_setup_runtime_resources_c1_car_model_FIXED
  (SFc1_car_model_FIXEDInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c1_car_model_FIXED
  (SFc1_car_model_FIXEDInstanceStruct *chartInstance);
static void enable_c1_car_model_FIXED(SFc1_car_model_FIXEDInstanceStruct
  *chartInstance);
static void disable_c1_car_model_FIXED(SFc1_car_model_FIXEDInstanceStruct
  *chartInstance);
static void sf_gateway_c1_car_model_FIXED(SFc1_car_model_FIXEDInstanceStruct
  *chartInstance);
static void ext_mode_exec_c1_car_model_FIXED(SFc1_car_model_FIXEDInstanceStruct *
  chartInstance);
static void c1_update_jit_animation_c1_car_model_FIXED
  (SFc1_car_model_FIXEDInstanceStruct *chartInstance);
static void c1_do_animation_call_c1_car_model_FIXED
  (SFc1_car_model_FIXEDInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_car_model_FIXED
  (SFc1_car_model_FIXEDInstanceStruct *chartInstance);
static void set_sim_state_c1_car_model_FIXED(SFc1_car_model_FIXEDInstanceStruct *
  chartInstance, const mxArray *c1_st);
static void initSimStructsc1_car_model_FIXED(SFc1_car_model_FIXEDInstanceStruct *
  chartInstance);
static void c1_emlrt_update_log_1(SFc1_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c1_in[4], emlrtLocationLoggingDataType c1_table[],
  int32_T c1_index, real_T c1_out[4]);
static real_T c1_emlrt_update_log_2(SFc1_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c1_in, emlrtLocationLoggingDataType c1_table[], int32_T
  c1_index);
static void c1_emlrtInitVarDataTables(SFc1_car_model_FIXEDInstanceStruct
  *chartInstance, emlrtLocationLoggingDataType c1_dataTables[60],
  emlrtLocationLoggingHistogramType c1_histTables[60]);
static real_T c1_sqrt(SFc1_car_model_FIXEDInstanceStruct *chartInstance, const
                      emlrtStack *c1_sp, real_T c1_x);
static real_T c1_emlrt_marshallIn(SFc1_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c1_b_d, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_emlrt_marshallIn(SFc1_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c1_b_tau, const char_T *c1_identifier, real_T
  c1_y[4]);
static void c1_d_emlrt_marshallIn(SFc1_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[4]);
static uint8_T c1_e_emlrt_marshallIn(SFc1_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_car_model_FIXED, const char_T
  *c1_identifier);
static uint8_T c1_f_emlrt_marshallIn(SFc1_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_slStringInitializeDynamicBuffers
  (SFc1_car_model_FIXEDInstanceStruct *chartInstance);
static void c1_chart_data_browse_helper(SFc1_car_model_FIXEDInstanceStruct
  *chartInstance, int32_T c1_ssIdNumber, const mxArray **c1_mxData, uint8_T
  *c1_isValueTooBig);
static void c1_b_emlrt_update_log_1(SFc1_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c1_in[4], emlrtLocationLoggingDataType c1_table[],
  int32_T c1_index);
static void c1_b_sqrt(SFc1_car_model_FIXEDInstanceStruct *chartInstance, const
                      emlrtStack *c1_sp, real_T *c1_x);
static void init_dsm_address_info(SFc1_car_model_FIXEDInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc1_car_model_FIXEDInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_car_model_FIXED(SFc1_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_is_active_c1_car_model_FIXED = 0U;
  chartInstance->c1_emlrtLocLogSimulated = false;
  c1_emlrtInitVarDataTables(chartInstance,
    chartInstance->c1_emlrtLocationLoggingDataTables,
    chartInstance->c1_emlrtLocLogHistTables);
}

static void initialize_params_c1_car_model_FIXED
  (SFc1_car_model_FIXEDInstanceStruct *chartInstance)
{
  real_T c1_b_d;
  real_T c1_d1;
  real_T c1_d2;
  real_T c1_d3;
  sf_mex_import_named("m_all", sf_mex_get_sfun_param(chartInstance->S, 3U, 0U),
                      &c1_b_d, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c1_m_all = c1_b_d;
  sf_mex_import_named("RE", sf_mex_get_sfun_param(chartInstance->S, 1U, 0U),
                      &c1_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c1_RE = c1_d1;
  sf_mex_import_named("IYY", sf_mex_get_sfun_param(chartInstance->S, 0U, 0U),
                      &c1_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c1_IYY = c1_d2;
  sf_mex_import_named("br", sf_mex_get_sfun_param(chartInstance->S, 2U, 0U),
                      &c1_d3, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c1_br = c1_d3;
}

static void mdl_start_c1_car_model_FIXED(SFc1_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void mdl_terminate_c1_car_model_FIXED(SFc1_car_model_FIXEDInstanceStruct *
  chartInstance)
{
  const emlrtLocationLoggingFileInfoType c1_emlrtLocationLoggingFileInfo = {
    "#car_model_FIXED:6684",           /* mexFileName */
    "Mon Apr 17 19:52:44 2023",        /* timestamp */
    "",                                /* buildDir */
    1,                                 /* numFcns */
    256                                /* numHistogramBins */
  };

  const emlrtLocationLoggingFunctionInfoType
    c1_emlrtLocationLoggingFunctionInfoTable[1] = { { "eML_blk_kernel",/* fcnName */
      1,                               /* fcnId */
      60                               /* numInstrPoints */
    } };

  const emlrtLocationLoggingLocationType c1_emlrtLocationInfo[67] = { { 1,/* MxInfoID */
      25,                              /* TextStart */
      6,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      32,                              /* TextStart */
      1,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      34,                              /* TextStart */
      1,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      36,                              /* TextStart */
      7,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      44,                              /* TextStart */
      4,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      49,                              /* TextStart */
      6,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      56,                              /* TextStart */
      5,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      62,                              /* TextStart */
      2,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      65,                              /* TextStart */
      3,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      69,                              /* TextStart */
      2,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      87,                              /* TextStart */
      2,                               /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      92,                              /* TextStart */
      28,                              /* TextLength */
      7,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      92,                              /* TextStart */
      10,                              /* TextLength */
      8,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      92,                              /* TextStart */
      6,                               /* TextLength */
      7,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      105,                             /* TextStart */
      14,                              /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      126,                             /* TextStart */
      2,                               /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      131,                             /* TextStart */
      21,                              /* TextLength */
      7,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      131,                             /* TextStart */
      15,                              /* TextLength */
      8,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      131,                             /* TextStart */
      12,                              /* TextLength */
      7,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      158,                             /* TextStart */
      2,                               /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      163,                             /* TextStart */
      11,                              /* TextLength */
      7,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      180,                             /* TextStart */
      2,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      187,                             /* TextStart */
      17,                              /* TextLength */
      8,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      187,                             /* TextStart */
      15,                              /* TextLength */
      7,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      187,                             /* TextStart */
      9,                               /* TextLength */
      7,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      211,                             /* TextStart */
      3,                               /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      217,                             /* TextStart */
      80,                              /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      217,                             /* TextStart */
      60,                              /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      217,                             /* TextStart */
      39,                              /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      217,                             /* TextStart */
      28,                              /* TextLength */
      7,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      217,                             /* TextStart */
      10,                              /* TextLength */
      8,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      217,                             /* TextStart */
      6,                               /* TextLength */
      7,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      230,                             /* TextStart */
      14,                              /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      246,                             /* TextStart */
      10,                              /* TextLength */
      7,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      257,                             /* TextStart */
      20,                              /* TextLength */
      7,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      257,                             /* TextStart */
      14,                              /* TextLength */
      8,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      257,                             /* TextStart */
      11,                              /* TextLength */
      7,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      279,                             /* TextStart */
      17,                              /* TextLength */
      8,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      279,                             /* TextStart */
      15,                              /* TextLength */
      7,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      279,                             /* TextStart */
      9,                               /* TextLength */
      7,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      308,                             /* TextStart */
      3,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      329,                             /* TextStart */
      2,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      349,                             /* TextStart */
      2,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      369,                             /* TextStart */
      2,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      389,                             /* TextStart */
      2,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      402,                             /* TextStart */
      2,                               /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      407,                             /* TextStart */
      35,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      412,                             /* TextStart */
      29,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      416,                             /* TextStart */
      24,                              /* TextLength */
      8,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      417,                             /* TextStart */
      15,                              /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      417,                             /* TextStart */
      6,                               /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      426,                             /* TextStart */
      6,                               /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      434,                             /* TextStart */
      6,                               /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      444,                             /* TextStart */
      2,                               /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      449,                             /* TextStart */
      35,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      454,                             /* TextStart */
      29,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      458,                             /* TextStart */
      24,                              /* TextLength */
      8,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      459,                             /* TextStart */
      15,                              /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      459,                             /* TextStart */
      6,                               /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      468,                             /* TextStart */
      6,                               /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      476,                             /* TextStart */
      6,                               /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      487,                             /* TextStart */
      1,                               /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      492,                             /* TextStart */
      19,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      496,                             /* TextStart */
      11,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      533,                             /* TextStart */
      1,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      559,                             /* TextStart */
      1,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      577,                             /* TextStart */
      1,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    } };

  const int32_T c1_emlrtLocationLoggingFieldCounts[60] = { 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0 };

  if (chartInstance->c1_emlrtLocLogSimulated) {
    emlrtLocationLoggingClearLog("#car_model_FIXED:6684");
    emlrtLocationLoggingPushLog(&c1_emlrtLocationLoggingFileInfo,
      &c1_emlrtLocationLoggingFunctionInfoTable[0],
      &chartInstance->c1_emlrtLocationLoggingDataTables[0],
      &c1_emlrtLocationInfo[0], NULL, 0U, &c1_emlrtLocationLoggingFieldCounts[0],
      NULL);
    addResultsToFPTRepository("#car_model_FIXED:6684");
  }
}

static void mdl_setup_runtime_resources_c1_car_model_FIXED
  (SFc1_car_model_FIXEDInstanceStruct *chartInstance)
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
    135U);
  covrtChartInitFcn(chartInstance->c1_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c1_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c1_decisionTxtStartIdx, &c1_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c1_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c1_covrtInstance, "", 4U, 0U, 1U, 0U, 3U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 588);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 0U, 74, 82, 299,
                    400, false);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 1U, 515, 528, 540,
                    587, false);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 2U, 540, 554, 568,
                    587, false);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 0U, 77, 82,
    -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 1U, 519,
    527, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 2U, 547,
    554, -1, 4U);
}

static void mdl_cleanup_runtime_resources_c1_car_model_FIXED
  (SFc1_car_model_FIXEDInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c1_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c1_covrtInstance);
}

static void enable_c1_car_model_FIXED(SFc1_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_car_model_FIXED(SFc1_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c1_car_model_FIXED(SFc1_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  emlrtStack c1_b_st;
  emlrtStack c1_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  real_T c1_b_lambda[4];
  real_T c1_b_lambda0[4];
  real_T c1_b_w[4];
  real_T c1_b_w_fake[4];
  real_T c1_dv[4];
  real_T c1_a;
  real_T c1_ab_a;
  real_T c1_b;
  real_T c1_b_IYY;
  real_T c1_b_RE;
  real_T c1_b_a;
  real_T c1_b_br;
  real_T c1_b_c;
  real_T c1_b_d;
  real_T c1_b_d1;
  real_T c1_b_d2;
  real_T c1_b_m_all;
  real_T c1_b_v;
  real_T c1_b_varargin_1;
  real_T c1_b_vdot;
  real_T c1_b_x;
  real_T c1_b_y;
  real_T c1_bb_a;
  real_T c1_c;
  real_T c1_c_IYY;
  real_T c1_c_a;
  real_T c1_c_br;
  real_T c1_c_c;
  real_T c1_c_d;
  real_T c1_c_x;
  real_T c1_c_y;
  real_T c1_cb_a;
  real_T c1_d1;
  real_T c1_d2;
  real_T c1_d3;
  real_T c1_d4;
  real_T c1_d_a;
  real_T c1_d_c;
  real_T c1_d_x;
  real_T c1_d_y;
  real_T c1_db_a;
  real_T c1_e_a;
  real_T c1_e_c;
  real_T c1_e_x;
  real_T c1_e_y;
  real_T c1_eb_a;
  real_T c1_f_a;
  real_T c1_f_c;
  real_T c1_f_x;
  real_T c1_f_y;
  real_T c1_fb_a;
  real_T c1_g_a;
  real_T c1_g_x;
  real_T c1_g_y;
  real_T c1_gb_a;
  real_T c1_h_a;
  real_T c1_h_x;
  real_T c1_i_a;
  real_T c1_i_x;
  real_T c1_j_a;
  real_T c1_j_x;
  real_T c1_k_a;
  real_T c1_k_x;
  real_T c1_l_a;
  real_T c1_l_x;
  real_T c1_m_a;
  real_T c1_m_x;
  real_T c1_maxval;
  real_T c1_minval;
  real_T c1_n_a;
  real_T c1_n_x;
  real_T c1_o_a;
  real_T c1_o_x;
  real_T c1_p_a;
  real_T c1_p_x;
  real_T c1_q_a;
  real_T c1_r_a;
  real_T c1_s_a;
  real_T c1_t_a;
  real_T c1_u_a;
  real_T c1_v_a;
  real_T c1_varargin_1;
  real_T c1_varargin_2;
  real_T c1_w_a;
  real_T c1_x;
  real_T c1_x_a;
  real_T c1_y;
  real_T c1_y_a;
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
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  c1_st.tls = chartInstance->c1_fEmlrtCtx;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  chartInstance->c1_JITTransitionAnimation[0] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  for (c1_i = 0; c1_i < 4; c1_i++) {
    covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 5U,
                      (*chartInstance->c1_lambda)[c1_i]);
  }

  covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 4U, *chartInstance->c1_vdot);
  for (c1_i1 = 0; c1_i1 < 4; c1_i1++) {
    covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 3U,
                      (*chartInstance->c1_lambda0)[c1_i1]);
  }

  covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 2U, *chartInstance->c1_v);
  for (c1_i2 = 0; c1_i2 < 4; c1_i2++) {
    covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 1U, (*chartInstance->c1_w)
                      [c1_i2]);
  }

  for (c1_i3 = 0; c1_i3 < 4; c1_i3++) {
    covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 0U,
                      (*chartInstance->c1_w_fake)[c1_i3]);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  for (c1_i4 = 0; c1_i4 < 4; c1_i4++) {
    c1_b_w_fake[c1_i4] = (*chartInstance->c1_w_fake)[c1_i4];
  }

  for (c1_i5 = 0; c1_i5 < 4; c1_i5++) {
    c1_b_w[c1_i5] = (*chartInstance->c1_w)[c1_i5];
  }

  c1_b_v = *chartInstance->c1_v;
  for (c1_i6 = 0; c1_i6 < 4; c1_i6++) {
    c1_b_lambda0[c1_i6] = (*chartInstance->c1_lambda0)[c1_i6];
  }

  c1_b_vdot = *chartInstance->c1_vdot;
  for (c1_i7 = 0; c1_i7 < 4; c1_i7++) {
    c1_b_lambda[c1_i7] = (*chartInstance->c1_lambda)[c1_i7];
  }

  c1_b_m_all = chartInstance->c1_m_all;
  c1_b_RE = chartInstance->c1_RE;
  c1_b_IYY = chartInstance->c1_IYY;
  c1_b_br = chartInstance->c1_br;

  /* logging input variable 'w_fake' for function 'eML_blk_kernel' */
  /* logging input variable 'w' for function 'eML_blk_kernel' */
  /* logging input variable 'v' for function 'eML_blk_kernel' */
  /* logging input variable 'lambda0' for function 'eML_blk_kernel' */
  /* logging input variable 'vdot' for function 'eML_blk_kernel' */
  /* logging input variable 'lambda' for function 'eML_blk_kernel' */
  /* logging input variable 'm_all' for function 'eML_blk_kernel' */
  /* logging input variable 'RE' for function 'eML_blk_kernel' */
  /* logging input variable 'IYY' for function 'eML_blk_kernel' */
  /* logging input variable 'br' for function 'eML_blk_kernel' */
  chartInstance->c1_emlrtLocLogSimulated = true;

  /* logging input variable 'w_fake' for function 'eML_blk_kernel' */
  for (c1_i8 = 0; c1_i8 < 4; c1_i8++) {
    c1_dv[c1_i8] = c1_b_w_fake[c1_i8];
  }

  c1_b_emlrt_update_log_1(chartInstance, c1_dv,
    chartInstance->c1_emlrtLocationLoggingDataTables, 0);

  /* logging input variable 'w' for function 'eML_blk_kernel' */
  for (c1_i9 = 0; c1_i9 < 4; c1_i9++) {
    c1_dv[c1_i9] = c1_b_w[c1_i9];
  }

  c1_b_emlrt_update_log_1(chartInstance, c1_dv,
    chartInstance->c1_emlrtLocationLoggingDataTables, 1);

  /* logging input variable 'v' for function 'eML_blk_kernel' */
  c1_emlrt_update_log_2(chartInstance, c1_b_v,
                        chartInstance->c1_emlrtLocationLoggingDataTables, 2);

  /* logging input variable 'lambda0' for function 'eML_blk_kernel' */
  for (c1_i10 = 0; c1_i10 < 4; c1_i10++) {
    c1_dv[c1_i10] = c1_b_lambda0[c1_i10];
  }

  c1_b_emlrt_update_log_1(chartInstance, c1_dv,
    chartInstance->c1_emlrtLocationLoggingDataTables, 3);

  /* logging input variable 'vdot' for function 'eML_blk_kernel' */
  c1_emlrt_update_log_2(chartInstance, c1_b_vdot,
                        chartInstance->c1_emlrtLocationLoggingDataTables, 4);

  /* logging input variable 'lambda' for function 'eML_blk_kernel' */
  for (c1_i11 = 0; c1_i11 < 4; c1_i11++) {
    c1_dv[c1_i11] = c1_b_lambda[c1_i11];
  }

  c1_b_emlrt_update_log_1(chartInstance, c1_dv,
    chartInstance->c1_emlrtLocationLoggingDataTables, 5);

  /* logging input variable 'm_all' for function 'eML_blk_kernel' */
  c1_emlrt_update_log_2(chartInstance, c1_b_m_all,
                        chartInstance->c1_emlrtLocationLoggingDataTables, 6);

  /* logging input variable 'RE' for function 'eML_blk_kernel' */
  c1_emlrt_update_log_2(chartInstance, c1_b_RE,
                        chartInstance->c1_emlrtLocationLoggingDataTables, 7);

  /* logging input variable 'IYY' for function 'eML_blk_kernel' */
  c1_emlrt_update_log_2(chartInstance, c1_b_IYY,
                        chartInstance->c1_emlrtLocationLoggingDataTables, 8);

  /* logging input variable 'br' for function 'eML_blk_kernel' */
  c1_emlrt_update_log_2(chartInstance, c1_b_br,
                        chartInstance->c1_emlrtLocationLoggingDataTables, 9);
  covrtEmlFcnEval(chartInstance->c1_covrtInstance, 4U, 0, 0);
  if (covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 0,
                     covrtRelationalopUpdateFcn(chartInstance->c1_covrtInstance,
        4U, 0U, 0U, c1_b_v, 0.0, -1, 4U, c1_b_v > 0.0))) {
    for (c1_i13 = 0; c1_i13 < 4; c1_i13++) {
      c1_dv[c1_i13] = c1_b_lambda[c1_i13] - c1_b_lambda0[c1_i13];
    }

    c1_b_emlrt_update_log_1(chartInstance, c1_dv,
      chartInstance->c1_emlrtLocationLoggingDataTables, 13);
    c1_b_d = c1_emlrt_update_log_2(chartInstance, c1_emlrt_update_log_2
      (chartInstance, -c1_b_IYY * c1_b_v,
       chartInstance->c1_emlrtLocationLoggingDataTables, 12) / c1_b_RE,
      chartInstance->c1_emlrtLocationLoggingDataTables, 11);
    for (c1_i15 = 0; c1_i15 < 4; c1_i15++) {
      c1_dv[c1_i15] *= c1_b_d;
    }

    c1_b_emlrt_update_log_1(chartInstance, c1_dv,
      chartInstance->c1_emlrtLocationLoggingDataTables, 10);
    c1_c_IYY = -c1_b_IYY;
    for (c1_i17 = 0; c1_i17 < 4; c1_i17++) {
      c1_dv[c1_i17] = c1_c_IYY * c1_b_w_fake[c1_i17];
    }

    c1_b_emlrt_update_log_1(chartInstance, c1_dv,
      chartInstance->c1_emlrtLocationLoggingDataTables, 16);
    for (c1_i19 = 0; c1_i19 < 4; c1_i19++) {
      c1_dv[c1_i19] /= c1_b_v;
    }

    c1_b_emlrt_update_log_1(chartInstance, c1_dv,
      chartInstance->c1_emlrtLocationLoggingDataTables, 15);
    for (c1_i20 = 0; c1_i20 < 4; c1_i20++) {
      c1_dv[c1_i20] *= c1_b_vdot;
    }

    c1_b_emlrt_update_log_1(chartInstance, c1_dv,
      chartInstance->c1_emlrtLocationLoggingDataTables, 14);
    c1_c_br = -c1_b_br;
    for (c1_i21 = 0; c1_i21 < 4; c1_i21++) {
      c1_dv[c1_i21] = c1_c_br * c1_b_w_fake[c1_i21];
    }

    c1_b_emlrt_update_log_1(chartInstance, c1_dv,
      chartInstance->c1_emlrtLocationLoggingDataTables, 17);
    c1_emlrt_update_log_2(chartInstance, -c1_emlrt_update_log_2(chartInstance,
      c1_emlrt_update_log_2(chartInstance, c1_emlrt_update_log_2(chartInstance,
      c1_b_m_all * c1_b_RE, chartInstance->c1_emlrtLocationLoggingDataTables, 21)
      * c1_b_vdot, chartInstance->c1_emlrtLocationLoggingDataTables, 20) / 4.0,
      chartInstance->c1_emlrtLocationLoggingDataTables, 19),
                          chartInstance->c1_emlrtLocationLoggingDataTables, 18);
    for (c1_i22 = 0; c1_i22 < 4; c1_i22++) {
      c1_b_lambda[c1_i22] -= c1_b_lambda0[c1_i22];
    }

    c1_b_emlrt_update_log_1(chartInstance, c1_b_lambda,
      chartInstance->c1_emlrtLocationLoggingDataTables, 28);
    c1_d1 = c1_emlrt_update_log_2(chartInstance, c1_emlrt_update_log_2
      (chartInstance, -c1_b_IYY * c1_b_v,
       chartInstance->c1_emlrtLocationLoggingDataTables, 27) / c1_b_RE,
      chartInstance->c1_emlrtLocationLoggingDataTables, 26);
    for (c1_i23 = 0; c1_i23 < 4; c1_i23++) {
      c1_b_lambda[c1_i23] *= c1_d1;
    }

    c1_b_emlrt_update_log_1(chartInstance, c1_b_lambda,
      chartInstance->c1_emlrtLocationLoggingDataTables, 25);
    for (c1_i24 = 0; c1_i24 < 4; c1_i24++) {
      c1_dv[c1_i24] = c1_b_br * c1_b_w_fake[c1_i24];
    }

    c1_b_emlrt_update_log_1(chartInstance, c1_dv,
      chartInstance->c1_emlrtLocationLoggingDataTables, 29);
    for (c1_i25 = 0; c1_i25 < 4; c1_i25++) {
      c1_b_lambda[c1_i25] -= c1_dv[c1_i25];
    }

    c1_b_emlrt_update_log_1(chartInstance, c1_b_lambda,
      chartInstance->c1_emlrtLocationLoggingDataTables, 24);
    for (c1_i26 = 0; c1_i26 < 4; c1_i26++) {
      c1_b_w_fake[c1_i26] *= c1_b_IYY;
    }

    c1_b_emlrt_update_log_1(chartInstance, c1_b_w_fake,
      chartInstance->c1_emlrtLocationLoggingDataTables, 32);
    for (c1_i27 = 0; c1_i27 < 4; c1_i27++) {
      c1_b_w_fake[c1_i27] /= c1_b_v;
    }

    c1_b_emlrt_update_log_1(chartInstance, c1_b_w_fake,
      chartInstance->c1_emlrtLocationLoggingDataTables, 31);
    for (c1_i28 = 0; c1_i28 < 4; c1_i28++) {
      c1_b_w_fake[c1_i28] *= c1_b_vdot;
    }

    c1_b_emlrt_update_log_1(chartInstance, c1_b_w_fake,
      chartInstance->c1_emlrtLocationLoggingDataTables, 30);
    for (c1_i29 = 0; c1_i29 < 4; c1_i29++) {
      c1_b_lambda[c1_i29] -= c1_b_w_fake[c1_i29];
    }

    c1_b_emlrt_update_log_1(chartInstance, c1_b_lambda,
      chartInstance->c1_emlrtLocationLoggingDataTables, 23);
    c1_d3 = c1_emlrt_update_log_2(chartInstance, c1_emlrt_update_log_2
      (chartInstance, c1_emlrt_update_log_2(chartInstance, c1_b_m_all * c1_b_RE,
      chartInstance->c1_emlrtLocationLoggingDataTables, 35) * c1_b_vdot,
       chartInstance->c1_emlrtLocationLoggingDataTables, 34) / 4.0,
      chartInstance->c1_emlrtLocationLoggingDataTables, 33);
    for (c1_i30 = 0; c1_i30 < 4; c1_i30++) {
      c1_b_lambda[c1_i30] -= c1_d3;
    }

    c1_b_emlrt_update_log_1(chartInstance, c1_b_lambda,
      chartInstance->c1_emlrtLocationLoggingDataTables, 22);
  } else {
    for (c1_i12 = 0; c1_i12 < 4; c1_i12++) {
      c1_b_lambda[c1_i12] = 0.0;
    }

    c1_b_emlrt_update_log_1(chartInstance, c1_b_lambda,
      chartInstance->c1_emlrtLocationLoggingDataTables, 36);
    for (c1_i14 = 0; c1_i14 < 4; c1_i14++) {
      c1_dv[c1_i14] = 0.0;
    }

    c1_b_emlrt_update_log_1(chartInstance, c1_dv,
      chartInstance->c1_emlrtLocationLoggingDataTables, 37);
    for (c1_i16 = 0; c1_i16 < 4; c1_i16++) {
      c1_dv[c1_i16] = 0.0;
    }

    c1_b_emlrt_update_log_1(chartInstance, c1_dv,
      chartInstance->c1_emlrtLocationLoggingDataTables, 38);
    for (c1_i18 = 0; c1_i18 < 4; c1_i18++) {
      c1_dv[c1_i18] = 0.0;
    }

    c1_b_emlrt_update_log_1(chartInstance, c1_dv,
      chartInstance->c1_emlrtLocationLoggingDataTables, 39);
    c1_emlrt_update_log_2(chartInstance, 0.0,
                          chartInstance->c1_emlrtLocationLoggingDataTables, 40);
  }

  c1_b_st.site = &c1_emlrtRSI;
  c1_a = c1_b_w[0];
  c1_b_a = c1_a;
  c1_c_a = c1_b_a;
  c1_d_a = c1_c_a;
  c1_e_a = c1_d_a;
  c1_c = c1_e_a * c1_e_a;
  c1_b_st.site = &c1_emlrtRSI;
  c1_f_a = c1_b_w[2];
  c1_g_a = c1_f_a;
  c1_h_a = c1_g_a;
  c1_i_a = c1_h_a;
  c1_j_a = c1_i_a;
  c1_b_c = c1_j_a * c1_j_a;
  c1_b_st.site = &c1_emlrtRSI;
  c1_k_a = c1_b_w[0];
  c1_l_a = c1_k_a;
  c1_m_a = c1_l_a;
  c1_n_a = c1_m_a;
  c1_o_a = c1_n_a;
  c1_c_c = c1_o_a * c1_o_a;
  c1_x = c1_emlrt_update_log_2(chartInstance, c1_emlrt_update_log_2
    (chartInstance, c1_emlrt_update_log_2(chartInstance, c1_c,
    chartInstance->c1_emlrtLocationLoggingDataTables, 45) -
     c1_emlrt_update_log_2(chartInstance, c1_b_c,
    chartInstance->c1_emlrtLocationLoggingDataTables, 46),
     chartInstance->c1_emlrtLocationLoggingDataTables, 44) /
    c1_emlrt_update_log_2(chartInstance, c1_c_c,
    chartInstance->c1_emlrtLocationLoggingDataTables, 47),
    chartInstance->c1_emlrtLocationLoggingDataTables, 43);
  c1_b_x = c1_x;
  c1_c_x = c1_b_x;
  c1_y = muDoubleScalarAbs(c1_c_x);
  c1_d2 = c1_emlrt_update_log_2(chartInstance, c1_y,
    chartInstance->c1_emlrtLocationLoggingDataTables, 42);
  c1_b_st.site = &c1_emlrtRSI;
  c1_b_sqrt(chartInstance, &c1_b_st, &c1_d2);
  c1_b_d1 = c1_emlrt_update_log_2(chartInstance, c1_d2,
    chartInstance->c1_emlrtLocationLoggingDataTables, 41);
  c1_b_st.site = &c1_b_emlrtRSI;
  c1_p_a = c1_b_w[1];
  c1_q_a = c1_p_a;
  c1_r_a = c1_q_a;
  c1_s_a = c1_r_a;
  c1_t_a = c1_s_a;
  c1_d_c = c1_t_a * c1_t_a;
  c1_b_st.site = &c1_b_emlrtRSI;
  c1_u_a = c1_b_w[3];
  c1_v_a = c1_u_a;
  c1_w_a = c1_v_a;
  c1_x_a = c1_w_a;
  c1_y_a = c1_x_a;
  c1_e_c = c1_y_a * c1_y_a;
  c1_b_st.site = &c1_b_emlrtRSI;
  c1_ab_a = c1_b_w[1];
  c1_bb_a = c1_ab_a;
  c1_cb_a = c1_bb_a;
  c1_db_a = c1_cb_a;
  c1_eb_a = c1_db_a;
  c1_f_c = c1_eb_a * c1_eb_a;
  c1_d_x = c1_emlrt_update_log_2(chartInstance, c1_emlrt_update_log_2
    (chartInstance, c1_emlrt_update_log_2(chartInstance, c1_d_c,
    chartInstance->c1_emlrtLocationLoggingDataTables, 52) -
     c1_emlrt_update_log_2(chartInstance, c1_e_c,
    chartInstance->c1_emlrtLocationLoggingDataTables, 53),
     chartInstance->c1_emlrtLocationLoggingDataTables, 51) /
    c1_emlrt_update_log_2(chartInstance, c1_f_c,
    chartInstance->c1_emlrtLocationLoggingDataTables, 54),
    chartInstance->c1_emlrtLocationLoggingDataTables, 50);
  c1_e_x = c1_d_x;
  c1_f_x = c1_e_x;
  c1_b_y = muDoubleScalarAbs(c1_f_x);
  c1_d4 = c1_emlrt_update_log_2(chartInstance, c1_b_y,
    chartInstance->c1_emlrtLocationLoggingDataTables, 49);
  c1_b_st.site = &c1_b_emlrtRSI;
  c1_b_sqrt(chartInstance, &c1_b_st, &c1_d4);
  c1_b_d2 = c1_emlrt_update_log_2(chartInstance, c1_d4,
    chartInstance->c1_emlrtLocationLoggingDataTables, 48);
  c1_varargin_1 = c1_b_d1;
  c1_varargin_2 = c1_b_d2;
  c1_g_x = c1_varargin_1;
  c1_c_y = c1_varargin_2;
  c1_h_x = c1_g_x;
  c1_d_y = c1_c_y;
  c1_i_x = c1_h_x;
  c1_e_y = c1_d_y;
  c1_fb_a = c1_i_x;
  c1_b = c1_e_y;
  c1_j_x = c1_fb_a;
  c1_f_y = c1_b;
  c1_k_x = c1_j_x;
  c1_g_y = c1_f_y;
  c1_maxval = muDoubleScalarMax(c1_k_x, c1_g_y);
  c1_b_varargin_1 = c1_emlrt_update_log_2(chartInstance, c1_maxval,
    chartInstance->c1_emlrtLocationLoggingDataTables, 56);
  c1_l_x = c1_b_varargin_1;
  c1_m_x = c1_l_x;
  c1_n_x = c1_m_x;
  c1_gb_a = c1_n_x;
  c1_o_x = c1_gb_a;
  c1_p_x = c1_o_x;
  c1_minval = muDoubleScalarMin(c1_p_x, 1.0);
  c1_c_d = c1_emlrt_update_log_2(chartInstance, c1_minval,
    chartInstance->c1_emlrtLocationLoggingDataTables, 55);
  if (covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 1,
                     covrtRelationalopUpdateFcn(chartInstance->c1_covrtInstance,
        4U, 0U, 1U, c1_b_w[2], 3.0, -1, 2U, c1_b_w[2] < 3.0))) {
    c1_c_d = c1_emlrt_update_log_2(chartInstance, 1.0,
      chartInstance->c1_emlrtLocationLoggingDataTables, 57);
  } else if (covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 2,
              covrtRelationalopUpdateFcn(chartInstance->c1_covrtInstance, 4U, 0U,
    2U, c1_c_d, 0.5, -1, 4U, c1_c_d > 0.5))) {
    c1_c_d = c1_emlrt_update_log_2(chartInstance, 0.5,
      chartInstance->c1_emlrtLocationLoggingDataTables, 58);
  } else {
    c1_c_d = c1_emlrt_update_log_2(chartInstance, 1.0,
      chartInstance->c1_emlrtLocationLoggingDataTables, 59);
  }

  for (c1_i31 = 0; c1_i31 < 4; c1_i31++) {
    (*chartInstance->c1_tau)[c1_i31] = c1_b_lambda[c1_i31];
  }

  *chartInstance->c1_d = c1_c_d;
  c1_do_animation_call_c1_car_model_FIXED(chartInstance);
  for (c1_i32 = 0; c1_i32 < 4; c1_i32++) {
    covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 6U,
                      (*chartInstance->c1_tau)[c1_i32]);
  }

  covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 7U, *chartInstance->c1_d);
}

static void ext_mode_exec_c1_car_model_FIXED(SFc1_car_model_FIXEDInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void c1_update_jit_animation_c1_car_model_FIXED
  (SFc1_car_model_FIXEDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_do_animation_call_c1_car_model_FIXED
  (SFc1_car_model_FIXEDInstanceStruct *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static const mxArray *get_sim_state_c1_car_model_FIXED
  (SFc1_car_model_FIXEDInstanceStruct *chartInstance)
{
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(3, 1), false);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", chartInstance->c1_d, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", *chartInstance->c1_tau, 0, 0U, 1U,
    0U, 2, 1, 4), false);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y",
    &chartInstance->c1_is_active_c1_car_model_FIXED, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_car_model_FIXED(SFc1_car_model_FIXEDInstanceStruct *
  chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv[4];
  int32_T c1_i;
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_u = sf_mex_dup(c1_st);
  *chartInstance->c1_d = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 0)), "d");
  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
                        "tau", c1_dv);
  for (c1_i = 0; c1_i < 4; c1_i++) {
    (*chartInstance->c1_tau)[c1_i] = c1_dv[c1_i];
  }

  chartInstance->c1_is_active_c1_car_model_FIXED = c1_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)),
     "is_active_c1_car_model_FIXED");
  sf_mex_destroy(&c1_u);
  sf_mex_destroy(&c1_st);
}

static void initSimStructsc1_car_model_FIXED(SFc1_car_model_FIXEDInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void c1_emlrt_update_log_1(SFc1_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c1_in[4], emlrtLocationLoggingDataType c1_table[],
  int32_T c1_index, real_T c1_out[4])
{
  int32_T c1_i;
  for (c1_i = 0; c1_i < 4; c1_i++) {
    c1_out[c1_i] = c1_in[c1_i];
  }

  c1_b_emlrt_update_log_1(chartInstance, c1_out, c1_table, c1_index);
}

static real_T c1_emlrt_update_log_2(SFc1_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c1_in, emlrtLocationLoggingDataType c1_table[], int32_T
  c1_index)
{
  emlrtLocationLoggingDataType *c1_b_table;
  emlrtLocationLoggingHistogramType *c1_histTable;
  real_T c1_inDouble;
  real_T c1_localMax;
  real_T c1_localMin;
  real_T c1_significand;
  int32_T c1_exponent;
  boolean_T c1_isLoggingEnabledHere;
  (void)chartInstance;
  c1_isLoggingEnabledHere = (c1_index >= 0);
  if (c1_isLoggingEnabledHere) {
    c1_b_table = (emlrtLocationLoggingDataType *)&c1_table[c1_index];
    c1_localMin = c1_b_table[0U].SimMin;
    c1_localMax = c1_b_table[0U].SimMax;
    c1_histTable = c1_b_table[0U].HistogramTable;

    /* Simulation Min-Max logging. */
    if (c1_in < c1_localMin) {
      c1_localMin = c1_in;
    }

    if (c1_in > c1_localMax) {
      c1_localMax = c1_in;
    }

    /* Histogram logging. */
    c1_inDouble = c1_in;
    c1_histTable->TotalNumberOfValues++;
    if (c1_inDouble == 0.0) {
      c1_histTable->NumberOfZeros++;
    } else {
      c1_histTable->SimSum += c1_inDouble;
      if ((!muDoubleScalarIsInf(c1_inDouble)) && (!muDoubleScalarIsNaN
           (c1_inDouble))) {
        c1_significand = frexp(c1_inDouble, &c1_exponent);
        if (c1_exponent > 128) {
          c1_exponent = 128;
        }

        if (c1_exponent < -127) {
          c1_exponent = -127;
        }

        if (c1_significand < 0.0) {
          c1_histTable->NumberOfNegativeValues++;
          c1_histTable->HistogramOfNegativeValues[127 + c1_exponent]++;
        } else {
          c1_histTable->NumberOfPositiveValues++;
          c1_histTable->HistogramOfPositiveValues[127 + c1_exponent]++;
        }
      }
    }

    c1_b_table[0U].SimMin = c1_localMin;
    c1_b_table[0U].SimMax = c1_localMax;

    /* IsAlwaysInteger logging. */
    if (c1_in != muDoubleScalarFloor(c1_in)) {
      c1_b_table[0U].IsAlwaysInteger = false;
    }
  }

  return c1_in;
}

static void c1_emlrtInitVarDataTables(SFc1_car_model_FIXEDInstanceStruct
  *chartInstance, emlrtLocationLoggingDataType c1_dataTables[60],
  emlrtLocationLoggingHistogramType c1_histTables[60])
{
  int32_T c1_i;
  int32_T c1_iH;
  (void)chartInstance;
  for (c1_i = 0; c1_i < 60; c1_i++) {
    c1_dataTables[c1_i].SimMin = rtInf;
    c1_dataTables[c1_i].SimMax = rtMinusInf;
    c1_dataTables[c1_i].OverflowWraps = 0;
    c1_dataTables[c1_i].Saturations = 0;
    c1_dataTables[c1_i].IsAlwaysInteger = true;
    c1_dataTables[c1_i].HistogramTable = &c1_histTables[c1_i];
    c1_histTables[c1_i].NumberOfZeros = 0.0;
    c1_histTables[c1_i].NumberOfPositiveValues = 0.0;
    c1_histTables[c1_i].NumberOfNegativeValues = 0.0;
    c1_histTables[c1_i].TotalNumberOfValues = 0.0;
    c1_histTables[c1_i].SimSum = 0.0;
    for (c1_iH = 0; c1_iH < 256; c1_iH++) {
      c1_histTables[c1_i].HistogramOfPositiveValues[c1_iH] = 0.0;
      c1_histTables[c1_i].HistogramOfNegativeValues[c1_iH] = 0.0;
    }
  }
}

const mxArray *sf_c1_car_model_FIXED_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c1_nameCaptureInfo;
}

static real_T c1_sqrt(SFc1_car_model_FIXEDInstanceStruct *chartInstance, const
                      emlrtStack *c1_sp, real_T c1_x)
{
  real_T c1_b_x;
  c1_b_x = c1_x;
  c1_b_sqrt(chartInstance, c1_sp, &c1_b_x);
  return c1_b_x;
}

static real_T c1_emlrt_marshallIn(SFc1_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c1_b_d, const char_T *c1_identifier)
{
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_d), &c1_thisId);
  sf_mex_destroy(&c1_b_d);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_car_model_FIXEDInstanceStruct
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

static void c1_c_emlrt_marshallIn(SFc1_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c1_b_tau, const char_T *c1_identifier, real_T
  c1_y[4])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tau), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_tau);
}

static void c1_d_emlrt_marshallIn(SFc1_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[4])
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

static uint8_T c1_e_emlrt_marshallIn(SFc1_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_car_model_FIXED, const char_T
  *c1_identifier)
{
  emlrtMsgIdentifier c1_thisId;
  uint8_T c1_y;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_car_model_FIXED), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_car_model_FIXED);
  return c1_y;
}

static uint8_T c1_f_emlrt_marshallIn(SFc1_car_model_FIXEDInstanceStruct
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

static void c1_slStringInitializeDynamicBuffers
  (SFc1_car_model_FIXEDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_chart_data_browse_helper(SFc1_car_model_FIXEDInstanceStruct
  *chartInstance, int32_T c1_ssIdNumber, const mxArray **c1_mxData, uint8_T
  *c1_isValueTooBig)
{
  real_T c1_b_d;
  real_T c1_d1;
  real_T c1_d2;
  *c1_mxData = NULL;
  *c1_mxData = NULL;
  *c1_isValueTooBig = 0U;
  switch (c1_ssIdNumber) {
   case 22U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", *chartInstance->c1_w_fake,
      0, 0U, 1U, 0U, 2, 1, 4), false);
    break;

   case 6U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", *chartInstance->c1_w, 0, 0U,
      1U, 0U, 2, 1, 4), false);
    break;

   case 4U:
    c1_b_d = *chartInstance->c1_v;
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", &c1_b_d, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 5U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", *chartInstance->c1_tau, 0,
      0U, 1U, 0U, 2, 1, 4), false);
    break;

   case 7U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", *chartInstance->c1_lambda0,
      0, 0U, 1U, 0U, 2, 1, 4), false);
    break;

   case 8U:
    c1_d1 = *chartInstance->c1_vdot;
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", &c1_d1, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 10U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", *chartInstance->c1_lambda,
      0, 0U, 1U, 0U, 2, 1, 4), false);
    break;

   case 11U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", &chartInstance->c1_m_all, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 12U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", &chartInstance->c1_RE, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 13U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", &chartInstance->c1_IYY, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 14U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", &chartInstance->c1_br, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 15U:
    c1_d2 = *chartInstance->c1_d;
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", &c1_d2, 0, 0U, 0U, 0U, 0),
                  false);
    break;
  }
}

static void c1_b_emlrt_update_log_1(SFc1_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c1_in[4], emlrtLocationLoggingDataType c1_table[],
  int32_T c1_index)
{
  emlrtLocationLoggingDataType *c1_b_table;
  emlrtLocationLoggingHistogramType *c1_histTable;
  real_T c1_inDouble;
  real_T c1_localMax;
  real_T c1_localMin;
  real_T c1_significand;
  int32_T c1_b_i;
  int32_T c1_exponent;
  int32_T c1_i;
  boolean_T c1_isLoggingEnabledHere;
  (void)chartInstance;
  c1_isLoggingEnabledHere = (c1_index >= 0);
  if (c1_isLoggingEnabledHere) {
    c1_b_table = (emlrtLocationLoggingDataType *)&c1_table[c1_index];
    c1_localMin = c1_b_table[0U].SimMin;
    c1_localMax = c1_b_table[0U].SimMax;
    c1_histTable = c1_b_table[0U].HistogramTable;
    for (c1_i = 0; c1_i < 4; c1_i++) {
      /* Simulation Min-Max logging. */
      if (c1_in[c1_i] < c1_localMin) {
        c1_localMin = c1_in[c1_i];
      }

      if (c1_in[c1_i] > c1_localMax) {
        c1_localMax = c1_in[c1_i];
      }

      /* Histogram logging. */
      c1_inDouble = c1_in[c1_i];
      c1_histTable->TotalNumberOfValues++;
      if (c1_inDouble == 0.0) {
        c1_histTable->NumberOfZeros++;
      } else {
        c1_histTable->SimSum += c1_inDouble;
        if ((!muDoubleScalarIsInf(c1_inDouble)) && (!muDoubleScalarIsNaN
             (c1_inDouble))) {
          c1_significand = frexp(c1_inDouble, &c1_exponent);
          if (c1_exponent > 128) {
            c1_exponent = 128;
          }

          if (c1_exponent < -127) {
            c1_exponent = -127;
          }

          if (c1_significand < 0.0) {
            c1_histTable->NumberOfNegativeValues++;
            c1_histTable->HistogramOfNegativeValues[127 + c1_exponent]++;
          } else {
            c1_histTable->NumberOfPositiveValues++;
            c1_histTable->HistogramOfPositiveValues[127 + c1_exponent]++;
          }
        }
      }
    }

    c1_b_table[0U].SimMin = c1_localMin;
    c1_b_table[0U].SimMax = c1_localMax;

    /* IsAlwaysInteger logging. */
    c1_b_i = 0;
    while (c1_b_table[0U].IsAlwaysInteger && (c1_b_i < 4)) {
      if (c1_in[c1_b_i] != muDoubleScalarFloor(c1_in[c1_b_i])) {
        c1_b_table[0U].IsAlwaysInteger = false;
      }

      c1_b_i++;
    }
  }
}

static void c1_b_sqrt(SFc1_car_model_FIXEDInstanceStruct *chartInstance, const
                      emlrtStack *c1_sp, real_T *c1_x)
{
  static char_T c1_cv[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  static char_T c1_cv1[4] = { 's', 'q', 'r', 't' };

  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_y = NULL;
  real_T c1_b_x;
  boolean_T c1_b_p;
  boolean_T c1_p;
  (void)chartInstance;
  c1_b_x = *c1_x;
  if (c1_b_x < 0.0) {
    c1_p = true;
  } else {
    c1_p = false;
  }

  c1_b_p = c1_p;
  if (c1_b_p) {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_cv1, 10, 0U, 1U, 0U, 2, 1, 4),
                  false);
    sf_mex_call(c1_sp, &c1_b_emlrtMCI, "error", 0U, 2U, 14, c1_y, 14,
                sf_mex_call(c1_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c1_sp, NULL, "message", 1U, 2U, 14, c1_b_y, 14, c1_c_y)));
  }

  *c1_x = muDoubleScalarSqrt(*c1_x);
}

static void init_dsm_address_info(SFc1_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc1_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  chartInstance->c1_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c1_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c1_w_fake = (real_T (*)[4])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c1_w = (real_T (*)[4])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_v = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    2);
  chartInstance->c1_tau = (real_T (*)[4])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_lambda0 = (real_T (*)[4])ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c1_vdot = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c1_lambda = (real_T (*)[4])ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c1_d = (real_T *)ssGetOutputPortSignal_wrapper(chartInstance->S,
    2);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c1_car_model_FIXED_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3810959481U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3987469416U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1405977070U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3779073818U);
}

mxArray *sf_c1_car_model_FIXED_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_car_model_FIXED_jit_fallback_info(void)
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

mxArray *sf_c1_car_model_FIXED_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c1_car_model_FIXED(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiDewcTAwAakOYCYiQECWKF8RiBmhtIQcRa4uAIQl1QWpILEi4uSPVOAdF5iLpi"
    "fWFrhmZeWDzbfggFhPhsW8xmRzOeEikPAB3vK9Os5gPQbIOlnIaBfAMhKgYYLLHwGzv0iRLmfGc"
    "X9zAwliaVUcr+CA2X6IfYHEHC/DIr7IfzM4vjE5JLMstT4ZMP45MSi+Nz8lNSceDfPCFcXBqT4A"
    "QD5YB5L"
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_car_model_FIXED_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "soVj7KZ0y8iIXEgJitbPAAE";
}

static void sf_opaque_initialize_c1_car_model_FIXED(void *chartInstanceVar)
{
  initialize_params_c1_car_model_FIXED((SFc1_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
  initialize_c1_car_model_FIXED((SFc1_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_car_model_FIXED(void *chartInstanceVar)
{
  enable_c1_car_model_FIXED((SFc1_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_car_model_FIXED(void *chartInstanceVar)
{
  disable_c1_car_model_FIXED((SFc1_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_car_model_FIXED(void *chartInstanceVar)
{
  sf_gateway_c1_car_model_FIXED((SFc1_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_car_model_FIXED(SimStruct* S)
{
  return get_sim_state_c1_car_model_FIXED((SFc1_car_model_FIXEDInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_car_model_FIXED(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c1_car_model_FIXED((SFc1_car_model_FIXEDInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c1_car_model_FIXED(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_car_model_FIXEDInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_car_model_FIXED_optimization_info();
    }

    mdl_cleanup_runtime_resources_c1_car_model_FIXED
      ((SFc1_car_model_FIXEDInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c1_car_model_FIXED(void *chartInstanceVar)
{
  mdl_start_c1_car_model_FIXED((SFc1_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_mdl_terminate_c1_car_model_FIXED(void *chartInstanceVar)
{
  mdl_terminate_c1_car_model_FIXED((SFc1_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_car_model_FIXED((SFc1_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_car_model_FIXED(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  sf_warn_if_symbolic_dimension_param_changed(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_car_model_FIXED((SFc1_car_model_FIXEDInstanceStruct*)
      sf_get_chart_instance_ptr(S));
    initSimStructsc1_car_model_FIXED((SFc1_car_model_FIXEDInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c1_car_model_FIXED_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [22] = {
    "eNrtWNtu40QYnh6oWFFWFUJCQpXYS25Au4sQe4GgaQ4QaGmE07JaIVUT+088m/GMdw5Jg/YJuOG",
    "W90BIvMnyEFxwB5f8Yztp1g2JJ4U9IEZynLHnm/8w/9Fko31McNzE6/7bhOzg/VW8Nkk+XinmG3",
    "NX/nybfFzMH79GSCgjGIAIbL/PLojfEDbpUEUTTfyHoAl8DVpya5gUbdGX1bFM9EGBCHGDVCrjR",
    "VezxHImhi0rQkdZfxOzMA5iaXl0iBvS6ETwyd/RTa3pIMUGUxCaFkBkYiXtIG5xOliuBWXG9RjC",
    "obaJt640mMCmTlR9bLlhKYfmBYRtoQ1FLegV8gaGGqibCz8lO3l1MEXLJOWMiuq6jqkOIEXrMHC",
    "aRvh7Yg1qrxI2jKkyhxDTEegjNsyoSwGVqDONq3tMUCMVo7yZ8LrbraK8HY4yHqNLcN8zQnkPFd",
    "BhKpkwng4RtFDPTUF7HBrQswNPugE8ss4bzhiMQfmdb78uR6DoAE6EH8/ZGTUvMqOc+VJFrGEJn",
    "FFVC9F2NUR+cQOdTgcUzRG6uI0XFjIVt3VXsRHahm+sazv3XyvW2SS3fr0WNqPbHIG3Xc3otkJR",
    "p5xrP2xXpkcwAp7Rb1BD18Dm9D3AWrOoK9E6XLTxjFhWMPSEAluXImLVrXJUQmWJ7StMUhXgLHF",
    "uABGqecb6bKNVfmS1kUkdQ07j6KgivavYtjCg+jSEyjlGUaYBGc7sypNuxLRzJESjlkwmZeUdch",
    "9cC0p034rGWKoh6tg3mV3qynmCHxqiAQZmA1mQa6J1n1FuK/Kc6AH6D5rHqcYo60cXsc5/1gKHN",
    "IwhcpmTcTjGOIsbVD1i7VJ+DaUdMTNpgA4VS6t6ksWAjknXaak7SeFUDIUci5aSSVBUXkvsCgCj",
    "BlWCicEhpnA1aSHz1bhW8KibRXffIsfpmRpOe842PgOB2dDJ6qoGGqJXNQWWyMjQdbAB+w6LGKG",
    "ZNpioJ3mqz/Oeq98/J5f1+/aC+v2Nufp9r5iHd85Dqs4TV6uct9r3mw0y2+/23H67FfqB7Qo4cg",
    "V3SW96f3cOv7GALpm7u/X35tbf2Hx6/U6J3ub0WTZy/MEc/vUSve0SfqfQ3U/fPgl3f37yx/eNh",
    "z/89vjH3bLcZT42rvCxkf13uHjLr++6Wcz3p/XTLFqPrgS0KnbxVsku3FzLs4cfffng9uQeQ6MY",
    "fMFMr1OrNbP9ftlczu9Wid/p81uuZkNnzmKDCttR0b+5ObV5X1E+z50V+rgxZ1eE/P7p9fDvH5T",
    "PcXsFfg//RSX7fX78v1mJ/62n+N8ihtp/iP9bB9fD5/Q7K/jfL9nrftaDnFOXaeB8cUSbl29dP/",
    "XFkWeMe1n4/F8v/758VfL1zpq4zTVx5Bnjriufbx3ysq9fljdIaf3eCyzHsnjvU4++aHL9Svzqx",
    "HeK+Sez7yH1mPFoQUdWvMamqb/o7X/Evv/01N+0Lm46/RUfzh98UBOUT7AFy1vc4nFHue+fs1cK",
    "qF7c5z6PfDK9H6yoq3ZL/u3mYyYiOdbv3bn74d3r5Ke/ALJfHlI=",
    ""
  };

  static char newstr [1553] = "";
  newstr[0] = '\0';
  for (i = 0; i < 22; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c1_car_model_FIXED(SimStruct *S)
{
  const char* newstr = sf_c1_car_model_FIXED_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(1675058355U));
  ssSetChecksum1(S,(4158108940U));
  ssSetChecksum2(S,(2406106250U));
  ssSetChecksum3(S,(211320044U));
}

static void mdlRTW_c1_car_model_FIXED(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c1_car_model_FIXED(SimStruct *S)
{
  SFc1_car_model_FIXEDInstanceStruct *chartInstance;
  chartInstance = (SFc1_car_model_FIXEDInstanceStruct *)utMalloc(sizeof
    (SFc1_car_model_FIXEDInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc1_car_model_FIXEDInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_car_model_FIXED;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_car_model_FIXED;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c1_car_model_FIXED;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c1_car_model_FIXED;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c1_car_model_FIXED;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_car_model_FIXED;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_car_model_FIXED;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_car_model_FIXED;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_car_model_FIXED;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_car_model_FIXED;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_car_model_FIXED;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_car_model_FIXED;
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

  mdl_setup_runtime_resources_c1_car_model_FIXED(chartInstance);
}

void c1_car_model_FIXED_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c1_car_model_FIXED(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_car_model_FIXED(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_car_model_FIXED(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_car_model_FIXED_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
