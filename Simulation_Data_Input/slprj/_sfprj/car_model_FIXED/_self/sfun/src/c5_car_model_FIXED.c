/* Include files */

#include "car_model_FIXED_sfun.h"
#include "c5_car_model_FIXED.h"
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
static emlrtMCInfo c5_emlrtMCI = { 13, /* lineNo */
  13,                                  /* colNo */
  "toLogicalCheck",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\toLogicalCheck.m"/* pName */
};

static emlrtRSInfo c5_emlrtRSI = { 10, /* lineNo */
  "Driver & Environment/Sweep Generator/Sweep Generator",/* fcnName */
  "#car_model_FIXED:6527"              /* pathName */
};

static emlrtRSInfo c5_b_emlrtRSI = { 15,/* lineNo */
  "Driver & Environment/Sweep Generator/Sweep Generator",/* fcnName */
  "#car_model_FIXED:6527"              /* pathName */
};

static emlrtBCInfo c5_emlrtBCI = { 1,  /* iFirst */
  644,                                 /* iLast */
  4,                                   /* lineNo */
  26,                                  /* colNo */
  "selected_sweep",                    /* aName */
  "Driver & Environment/Sweep Generator/Sweep Generator",/* fName */
  "#car_model_FIXED:6527",             /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_emlrtDCI = { 4,  /* lineNo */
  26,                                  /* colNo */
  "Driver & Environment/Sweep Generator/Sweep Generator",/* fName */
  "#car_model_FIXED:6527",             /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_b_emlrtBCI = { 1,/* iFirst */
  644,                                 /* iLast */
  5,                                   /* lineNo */
  28,                                  /* colNo */
  "selected_sweep",                    /* aName */
  "Driver & Environment/Sweep Generator/Sweep Generator",/* fName */
  "#car_model_FIXED:6527",             /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_b_emlrtDCI = { 5,/* lineNo */
  28,                                  /* colNo */
  "Driver & Environment/Sweep Generator/Sweep Generator",/* fName */
  "#car_model_FIXED:6527",             /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_c_emlrtBCI = { 1,/* iFirst */
  644,                                 /* iLast */
  14,                                  /* lineNo */
  24,                                  /* colNo */
  "selected_sweep",                    /* aName */
  "Driver & Environment/Sweep Generator/Sweep Generator",/* fName */
  "#car_model_FIXED:6527",             /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_c_emlrtDCI = { 14,/* lineNo */
  24,                                  /* colNo */
  "Driver & Environment/Sweep Generator/Sweep Generator",/* fName */
  "#car_model_FIXED:6527",             /* pName */
  1                                    /* checkKind */
};

/* Function Declarations */
static void initialize_c5_car_model_FIXED(SFc5_car_model_FIXEDInstanceStruct
  *chartInstance);
static void initialize_params_c5_car_model_FIXED
  (SFc5_car_model_FIXEDInstanceStruct *chartInstance);
static void mdl_start_c5_car_model_FIXED(SFc5_car_model_FIXEDInstanceStruct
  *chartInstance);
static void mdl_terminate_c5_car_model_FIXED(SFc5_car_model_FIXEDInstanceStruct *
  chartInstance);
static void mdl_setup_runtime_resources_c5_car_model_FIXED
  (SFc5_car_model_FIXEDInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c5_car_model_FIXED
  (SFc5_car_model_FIXEDInstanceStruct *chartInstance);
static void enable_c5_car_model_FIXED(SFc5_car_model_FIXEDInstanceStruct
  *chartInstance);
static void disable_c5_car_model_FIXED(SFc5_car_model_FIXEDInstanceStruct
  *chartInstance);
static void sf_gateway_c5_car_model_FIXED(SFc5_car_model_FIXEDInstanceStruct
  *chartInstance);
static void ext_mode_exec_c5_car_model_FIXED(SFc5_car_model_FIXEDInstanceStruct *
  chartInstance);
static void c5_update_jit_animation_c5_car_model_FIXED
  (SFc5_car_model_FIXEDInstanceStruct *chartInstance);
static void c5_do_animation_call_c5_car_model_FIXED
  (SFc5_car_model_FIXEDInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_car_model_FIXED
  (SFc5_car_model_FIXEDInstanceStruct *chartInstance);
static void set_sim_state_c5_car_model_FIXED(SFc5_car_model_FIXEDInstanceStruct *
  chartInstance, const mxArray *c5_st);
static void initSimStructsc5_car_model_FIXED(SFc5_car_model_FIXEDInstanceStruct *
  chartInstance);
static real_T c5_emlrt_update_log_1(SFc5_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c5_in, emlrtLocationLoggingDataType c5_table[], int32_T
  c5_c_index);
static c5_slBus15_Vel c5_emlrt_update_log_2(SFc5_car_model_FIXEDInstanceStruct
  *chartInstance, c5_slBus15_Vel c5_in, emlrtLocationLoggingDataType c5_table[],
  int32_T c5_c_index);
static void c5_emlrt_update_log_3(SFc5_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c5_in[1288], emlrtLocationLoggingDataType c5_table[],
  int32_T c5_c_index, real_T c5_out[1288]);
static void c5_emlrtInitVarDataTables(SFc5_car_model_FIXEDInstanceStruct
  *chartInstance, emlrtLocationLoggingDataType c5_dataTables[20],
  emlrtLocationLoggingHistogramType c5_histTables[20]);
static real_T c5_emlrt_marshallIn(SFc5_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c5_c_ON, const char_T *c5_identifier);
static real_T c5_b_emlrt_marshallIn(SFc5_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static uint8_T c5_c_emlrt_marshallIn(SFc5_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_car_model_FIXED, const char_T
  *c5_identifier);
static uint8_T c5_d_emlrt_marshallIn(SFc5_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_slStringInitializeDynamicBuffers
  (SFc5_car_model_FIXEDInstanceStruct *chartInstance);
static void c5_chart_data_browse_helper(SFc5_car_model_FIXEDInstanceStruct
  *chartInstance, int32_T c5_ssIdNumber, const mxArray **c5_mxData, uint8_T
  *c5_isValueTooBig);
static void c5_b_emlrt_update_log_2(SFc5_car_model_FIXEDInstanceStruct
  *chartInstance, c5_slBus15_Vel *c5_in, emlrtLocationLoggingDataType c5_table[],
  int32_T c5_c_index);
static void c5_b_emlrt_update_log_3(SFc5_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c5_in[1288], emlrtLocationLoggingDataType c5_table[],
  int32_T c5_c_index);
static void init_dsm_address_info(SFc5_car_model_FIXEDInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc5_car_model_FIXEDInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c5_car_model_FIXED(SFc5_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c5_is_active_c5_car_model_FIXED = 0U;
  chartInstance->c5_emlrtLocLogSimulated = false;
  c5_emlrtInitVarDataTables(chartInstance,
    chartInstance->c5_emlrtLocationLoggingDataTables,
    chartInstance->c5_emlrtLocLogHistTables);
}

static void initialize_params_c5_car_model_FIXED
  (SFc5_car_model_FIXEDInstanceStruct *chartInstance)
{
  real_T c5_dv[1288];
  real_T c5_d;
  real_T c5_d1;
  real_T c5_d2;
  int32_T c5_i;
  sf_mex_import_named("selected_sweep", sf_mex_get_sfun_param(chartInstance->S,
    2U, 0U), c5_dv, 0, 0, 0U, 1, 0U, 2, 644, 2);
  for (c5_i = 0; c5_i < 1288; c5_i++) {
    chartInstance->c5_selected_sweep[c5_i] = c5_dv[c5_i];
  }

  sf_mex_import_named("dt_ON", sf_mex_get_sfun_param(chartInstance->S, 1U, 0U),
                      &c5_d, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c5_dt_ON = c5_d;
  sf_mex_import_named("dt_OFF", sf_mex_get_sfun_param(chartInstance->S, 0U, 0U),
                      &c5_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c5_dt_OFF = c5_d1;
  sf_mex_import_named("tvs_t_sim", sf_mex_get_sfun_param(chartInstance->S, 3U,
    0U), &c5_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c5_tvs_t_sim = c5_d2;
}

static void mdl_start_c5_car_model_FIXED(SFc5_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void mdl_terminate_c5_car_model_FIXED(SFc5_car_model_FIXEDInstanceStruct *
  chartInstance)
{
  const emlrtLocationLoggingFileInfoType c5_emlrtLocationLoggingFileInfo = {
    "#car_model_FIXED:6527",           /* mexFileName */
    "Mon Apr 17 21:46:03 2023",        /* timestamp */
    "",                                /* buildDir */
    1,                                 /* numFcns */
    256                                /* numHistogramBins */
  };

  const emlrtLocationLoggingFunctionInfoType
    c5_emlrtLocationLoggingFunctionInfoTable[1] = { { "eML_blk_kernel",/* fcnName */
      1,                               /* fcnId */
      18                               /* numInstrPoints */
    } };

  const emlrtLocationLoggingLocationType c5_emlrtLocationInfo[21] = { { 1,/* MxInfoID */
      55,                              /* TextStart */
      5,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      62,                              /* TextStart */
      3,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      67,                              /* TextStart */
      2,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 3,                            /* MxInfoID */
      71,                              /* TextStart */
      14,                              /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      87,                              /* TextStart */
      5,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      94,                              /* TextStart */
      6,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      102,                             /* TextStart */
      7,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      111,                             /* TextStart */
      9,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      147,                             /* TextStart */
      7,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      183,                             /* TextStart */
      9,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      221,                             /* TextStart */
      7,                               /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      231,                             /* TextStart */
      35,                              /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      241,                             /* TextStart */
      25,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      268,                             /* TextStart */
      7,                               /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      278,                             /* TextStart */
      11,                              /* TextLength */
      5,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      315,                             /* TextStart */
      17,                              /* TextLength */
      7,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      355,                             /* TextStart */
      17,                              /* TextLength */
      7,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      396,                             /* TextStart */
      5,                               /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      404,                             /* TextStart */
      9,                               /* TextLength */
      5,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      419,                             /* TextStart */
      7,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      493,                             /* TextStart */
      2,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    } };

  const int32_T c5_emlrtLocationLoggingFieldCounts[18] = { 0, 3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  const char_T *c5_emlrtLocationLoggingFieldNames[3] = { "xdot", "ydot", "zdot"
  };

  if (chartInstance->c5_emlrtLocLogSimulated) {
    emlrtLocationLoggingClearLog("#car_model_FIXED:6527");
    emlrtLocationLoggingPushLog(&c5_emlrtLocationLoggingFileInfo,
      &c5_emlrtLocationLoggingFunctionInfoTable[0],
      &chartInstance->c5_emlrtLocationLoggingDataTables[0],
      &c5_emlrtLocationInfo[0], NULL, 0U, &c5_emlrtLocationLoggingFieldCounts[0],
      &c5_emlrtLocationLoggingFieldNames[0]);
    addResultsToFPTRepository("#car_model_FIXED:6527");
  }
}

static void mdl_setup_runtime_resources_c5_car_model_FIXED
  (SFc5_car_model_FIXEDInstanceStruct *chartInstance)
{
  static const int32_T c5_postfixPredicateTree[8] = { 0, 1, -3, 2, 3, -1, -3, -2
  };

  static const int32_T c5_condTxtEndIdx[4] = { 342, 348, 383, 390 };

  static const int32_T c5_condTxtStartIdx[4] = { 314, 346, 354, 388 };

  static const int32_T c5_b_postfixPredicateTree[3] = { 0, 1, -3 };

  static const int32_T c5_b_condTxtEndIdx[2] = { 470, 483 };

  static const int32_T c5_b_condTxtStartIdx[2] = { 441, 474 };

  static const uint32_T c5_decisionTxtEndIdx = 0U;
  static const uint32_T c5_decisionTxtStartIdx = 0U;
  setDebuggerFlag(chartInstance->S, true);
  setDataBrowseFcn(chartInstance->S, (void *)&c5_chart_data_browse_helper);
  chartInstance->c5_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c5_RuntimeVar,
    &chartInstance->c5_IsDebuggerActive,
    &chartInstance->c5_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c5_mlFcnLineNumber, &chartInstance->c5_IsHeatMapPresent, 0);
  sim_mode_is_external(chartInstance->S);
  covrtCreateStateflowInstanceData(chartInstance->c5_covrtInstance, 1U, 0U, 1U,
    136U);
  covrtChartInitFcn(chartInstance->c5_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c5_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c5_decisionTxtStartIdx, &c5_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c5_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c5_covrtInstance, "", 4U, 0U, 1U, 0U, 2U, 0U,
                  0U, 0U, 0U, 0U, 6U, 2U);
  covrtEmlFcnInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 524);
  covrtEmlIfInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 0U, 310, 391, -1,
                    523, false);
  covrtEmlIfInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 1U, 437, 484, -1,
                    518, false);
  covrtEmlMCDCInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 0U, 313, 391, 4U,
                      0U, c5_condTxtStartIdx, c5_condTxtEndIdx, 8U,
                      c5_postfixPredicateTree, false);
  covrtEmlMCDCInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 1U, 441, 483, 2U,
                      4U, c5_b_condTxtStartIdx, c5_b_condTxtEndIdx, 3U,
                      c5_b_postfixPredicateTree, false);
  covrtEmlRelationalInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 0U, 314,
    342, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 1U, 354,
    383, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 2U, 441,
    470, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 3U, 474,
    483, -1, 4U);
}

static void mdl_cleanup_runtime_resources_c5_car_model_FIXED
  (SFc5_car_model_FIXEDInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c5_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c5_covrtInstance);
}

static void enable_c5_car_model_FIXED(SFc5_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c5_car_model_FIXED(SFc5_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c5_car_model_FIXED(SFc5_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  static char_T c5_cv[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'l',
    'o', 'g', 'i', 'c', 'a', 'l', 'n', 'a', 'n' };

  static char_T c5_cv1[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'l',
    'o', 'g', 'i', 'c', 'a', 'l', 'n', 'a', 'n' };

  static char_T c5_cv2[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'l',
    'o', 'g', 'i', 'c', 'a', 'l', 'n', 'a', 'n' };

  c5_slBus15_Vel c5_r;
  emlrtStack c5_b_st;
  emlrtStack c5_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_e_y = NULL;
  const mxArray *c5_f_y = NULL;
  const mxArray *c5_g_y = NULL;
  real_T c5_b_selected_sweep[1288];
  real_T c5_dv[1288];
  real_T c5_x[2];
  real_T c5_absxk;
  real_T c5_b_dt_OFF;
  real_T c5_b_dt_ON;
  real_T c5_b_ref_steer;
  real_T c5_b_tvs_t_sim;
  real_T c5_b_vel_err;
  real_T c5_b_x;
  real_T c5_c_ON;
  real_T c5_c_counter;
  real_T c5_c_index;
  real_T c5_c_x;
  real_T c5_d;
  real_T c5_d1;
  real_T c5_d2;
  real_T c5_d_ON;
  real_T c5_d_counter;
  real_T c5_d_index;
  real_T c5_d_x;
  real_T c5_e_x;
  real_T c5_f_x;
  real_T c5_g_x;
  real_T c5_h_x;
  real_T c5_i_x;
  real_T c5_j_x;
  real_T c5_ref_vel;
  real_T c5_scale;
  real_T c5_t;
  real_T c5_y;
  int32_T c5_b_k;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_k;
  boolean_T c5_b;
  boolean_T c5_b_b;
  boolean_T c5_c_b;
  boolean_T c5_guard1 = false;
  boolean_T c5_guard2 = false;
  boolean_T c5_guard3 = false;
  c5_st.tls = chartInstance->c5_fEmlrtCtx;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  chartInstance->c5_JITTransitionAnimation[0] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 3U,
                    *chartInstance->c5_b_counter);
  covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 2U, *chartInstance->c5_ON);
  covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 0U,
                    *chartInstance->c5_index);
  chartInstance->c5_sfEvent = CALL_EVENT;
  c5_c_index = *chartInstance->c5_index;
  c5_c_ON = *chartInstance->c5_ON;
  for (c5_i = 0; c5_i < 1288; c5_i++) {
    c5_b_selected_sweep[c5_i] = chartInstance->c5_selected_sweep[c5_i];
  }

  c5_b_dt_ON = chartInstance->c5_dt_ON;
  c5_b_dt_OFF = chartInstance->c5_dt_OFF;
  c5_c_counter = *chartInstance->c5_b_counter;
  c5_b_tvs_t_sim = chartInstance->c5_tvs_t_sim;

  /* logging input variable 'index' for function 'eML_blk_kernel' */
  /* logging input variable 'vel' for function 'eML_blk_kernel' */
  /* logging input variable 'ON' for function 'eML_blk_kernel' */
  /* logging input variable 'selected_sweep' for function 'eML_blk_kernel' */
  /* logging input variable 'dt_ON' for function 'eML_blk_kernel' */
  /* logging input variable 'dt_OFF' for function 'eML_blk_kernel' */
  /* logging input variable 'counter' for function 'eML_blk_kernel' */
  /* logging input variable 'tvs_t_sim' for function 'eML_blk_kernel' */
  chartInstance->c5_emlrtLocLogSimulated = true;

  /* logging input variable 'index' for function 'eML_blk_kernel' */
  c5_emlrt_update_log_1(chartInstance, c5_c_index,
                        chartInstance->c5_emlrtLocationLoggingDataTables, 0);

  /* logging input variable 'vel' for function 'eML_blk_kernel' */
  c5_r.xdot = *(real_T *)&((char_T *)chartInstance->c5_vel)[0];
  c5_r.ydot = *(real_T *)&((char_T *)chartInstance->c5_vel)[8];
  c5_r.zdot = *(real_T *)&((char_T *)chartInstance->c5_vel)[16];
  c5_b_emlrt_update_log_2(chartInstance, &c5_r,
    chartInstance->c5_emlrtLocationLoggingDataTables, 1);

  /* logging input variable 'ON' for function 'eML_blk_kernel' */
  c5_emlrt_update_log_1(chartInstance, c5_c_ON,
                        chartInstance->c5_emlrtLocationLoggingDataTables, 4);

  /* logging input variable 'selected_sweep' for function 'eML_blk_kernel' */
  for (c5_i1 = 0; c5_i1 < 1288; c5_i1++) {
    c5_dv[c5_i1] = c5_b_selected_sweep[c5_i1];
  }

  c5_b_emlrt_update_log_3(chartInstance, c5_dv,
    chartInstance->c5_emlrtLocationLoggingDataTables, 5);

  /* logging input variable 'dt_ON' for function 'eML_blk_kernel' */
  c5_emlrt_update_log_1(chartInstance, c5_b_dt_ON,
                        chartInstance->c5_emlrtLocationLoggingDataTables, 6);

  /* logging input variable 'dt_OFF' for function 'eML_blk_kernel' */
  c5_emlrt_update_log_1(chartInstance, c5_b_dt_OFF,
                        chartInstance->c5_emlrtLocationLoggingDataTables, 7);

  /* logging input variable 'counter' for function 'eML_blk_kernel' */
  c5_emlrt_update_log_1(chartInstance, c5_c_counter,
                        chartInstance->c5_emlrtLocationLoggingDataTables, 8);

  /* logging input variable 'tvs_t_sim' for function 'eML_blk_kernel' */
  c5_emlrt_update_log_1(chartInstance, c5_b_tvs_t_sim,
                        chartInstance->c5_emlrtLocationLoggingDataTables, 9);
  c5_d_counter = c5_c_counter;
  c5_d_ON = c5_c_ON;
  c5_d_index = c5_c_index;
  covrtEmlFcnEval(chartInstance->c5_covrtInstance, 4U, 0, 0);
  if (c5_d_index != (real_T)(int32_T)muDoubleScalarFloor(c5_d_index)) {
    emlrtIntegerCheckR2012b(c5_d_index, &c5_emlrtDCI, &c5_st);
  }

  c5_i2 = (int32_T)c5_d_index;
  if ((c5_i2 < 1) || (c5_i2 > 644)) {
    emlrtDynamicBoundsCheckR2012b(c5_i2, 1, 644, &c5_emlrtBCI, &c5_st);
  }

  c5_ref_vel = c5_emlrt_update_log_1(chartInstance, c5_b_selected_sweep[c5_i2 -
    1], chartInstance->c5_emlrtLocationLoggingDataTables, 10);
  if (c5_d_index != (real_T)(int32_T)muDoubleScalarFloor(c5_d_index)) {
    emlrtIntegerCheckR2012b(c5_d_index, &c5_b_emlrtDCI, &c5_st);
  }

  c5_i3 = (int32_T)c5_d_index;
  if ((c5_i3 < 1) || (c5_i3 > 644)) {
    emlrtDynamicBoundsCheckR2012b(c5_i3, 1, 644, &c5_b_emlrtBCI, &c5_st);
  }

  c5_b_ref_steer = c5_emlrt_update_log_1(chartInstance,
    c5_b_selected_sweep[c5_i3 + 643],
    chartInstance->c5_emlrtLocationLoggingDataTables, 11);
  c5_x[0] = *(real_T *)&((char_T *)chartInstance->c5_vel)[0];
  c5_x[1] = *(real_T *)&((char_T *)chartInstance->c5_vel)[8];
  c5_y = 0.0;
  c5_scale = 3.3121686421112381E-170;
  for (c5_k = 0; c5_k < 2; c5_k++) {
    c5_b_k = c5_k;
    c5_b_x = c5_x[c5_b_k];
    c5_c_x = c5_b_x;
    c5_d_x = c5_c_x;
    c5_absxk = muDoubleScalarAbs(c5_d_x);
    if (c5_absxk > c5_scale) {
      c5_t = c5_scale / c5_absxk;
      c5_y = 1.0 + c5_y * c5_t * c5_t;
      c5_scale = c5_absxk;
    } else {
      c5_t = c5_absxk / c5_scale;
      c5_y += c5_t * c5_t;
    }
  }

  c5_y = c5_scale * muDoubleScalarSqrt(c5_y);
  c5_b_vel_err = c5_emlrt_update_log_1(chartInstance, c5_ref_vel -
    c5_emlrt_update_log_1(chartInstance, c5_y,
    chartInstance->c5_emlrtLocationLoggingDataTables, 13),
    chartInstance->c5_emlrtLocationLoggingDataTables, 12);
  c5_d_counter = c5_emlrt_update_log_1(chartInstance, c5_d_counter + 1.0,
    chartInstance->c5_emlrtLocationLoggingDataTables, 14);
  c5_d = c5_emlrt_update_log_1(chartInstance, c5_d_counter * c5_b_tvs_t_sim,
    chartInstance->c5_emlrtLocationLoggingDataTables, 15);
  c5_guard1 = false;
  c5_guard2 = false;
  c5_guard3 = false;
  if (covrtEmlCondEval(chartInstance->c5_covrtInstance, 4U, 0, 0,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c5_covrtInstance, 4U, 0U, 0U, c5_d,
                        c5_b_dt_ON, -1, 0U, c5_d == c5_b_dt_ON))) {
    c5_b_st.site = &c5_emlrtRSI;
    c5_e_x = c5_d_ON;
    c5_f_x = c5_e_x;
    c5_b = muDoubleScalarIsNaN(c5_f_x);
    if (c5_b) {
      c5_b_y = NULL;
      sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_cv, 10, 0U, 1U, 0U, 2, 1, 19),
                    false);
      c5_c_y = NULL;
      sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_cv, 10, 0U, 1U, 0U, 2, 1, 19),
                    false);
      sf_mex_call(&c5_b_st, &c5_emlrtMCI, "error", 0U, 2U, 14, c5_b_y, 14,
                  sf_mex_call(&c5_b_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c5_b_st, NULL, "message", 1U, 1U, 14, c5_c_y)));
    }

    if (covrtEmlCondEval(chartInstance->c5_covrtInstance, 4U, 0, 1, c5_d_ON !=
                         0.0)) {
      c5_guard2 = true;
    } else {
      c5_guard3 = true;
    }
  } else {
    c5_guard3 = true;
  }

  if (c5_guard3) {
    c5_d1 = c5_emlrt_update_log_1(chartInstance, c5_d_counter * c5_b_tvs_t_sim,
      chartInstance->c5_emlrtLocationLoggingDataTables, 16);
    if (covrtEmlCondEval(chartInstance->c5_covrtInstance, 4U, 0, 2,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c5_covrtInstance, 4U, 0U, 1U, c5_d1,
                          c5_b_dt_OFF, -1, 0U, c5_d1 == c5_b_dt_OFF))) {
      c5_b_st.site = &c5_emlrtRSI;
      c5_g_x = c5_d_ON;
      c5_h_x = c5_g_x;
      c5_b_b = muDoubleScalarIsNaN(c5_h_x);
      if (c5_b_b) {
        c5_d_y = NULL;
        sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_cv1, 10, 0U, 1U, 0U, 2, 1,
          19), false);
        c5_e_y = NULL;
        sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_cv1, 10, 0U, 1U, 0U, 2, 1,
          19), false);
        sf_mex_call(&c5_b_st, &c5_emlrtMCI, "error", 0U, 2U, 14, c5_d_y, 14,
                    sf_mex_call(&c5_b_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c5_b_st, NULL, "message", 1U, 1U, 14, c5_e_y)));
      }

      if (!covrtEmlCondEval(chartInstance->c5_covrtInstance, 4U, 0, 3, c5_d_ON
                            != 0.0)) {
        c5_guard2 = true;
      } else {
        c5_guard1 = true;
      }
    } else {
      c5_guard1 = true;
    }
  }

  if (c5_guard2) {
    covrtEmlMcdcEval(chartInstance->c5_covrtInstance, 4U, 0, 0, true);
    covrtEmlIfEval(chartInstance->c5_covrtInstance, 4U, 0, 0, true);
    c5_d_index = c5_emlrt_update_log_1(chartInstance, c5_d_index + 1.0,
      chartInstance->c5_emlrtLocationLoggingDataTables, 17);
    c5_d_counter = c5_emlrt_update_log_1(chartInstance, 0.0,
      chartInstance->c5_emlrtLocationLoggingDataTables, 18);
    if (c5_d_index != (real_T)(int32_T)muDoubleScalarFloor(c5_d_index)) {
      emlrtIntegerCheckR2012b(c5_d_index, &c5_c_emlrtDCI, &c5_st);
    }

    c5_i4 = (int32_T)c5_d_index;
    if ((c5_i4 < 1) || (c5_i4 > 644)) {
      emlrtDynamicBoundsCheckR2012b(c5_i4, 1, 644, &c5_c_emlrtBCI, &c5_st);
    }

    c5_d2 = c5_b_selected_sweep[c5_i4 + 643];
    if (covrtEmlCondEval(chartInstance->c5_covrtInstance, 4U, 0, 4,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c5_covrtInstance, 4U, 0U, 2U, c5_d2,
                          0.0, -1, 0U, c5_d2 == 0.0)) && covrtEmlCondEval
        (chartInstance->c5_covrtInstance, 4U, 0, 5, covrtRelationalopUpdateFcn
         (chartInstance->c5_covrtInstance, 4U, 0U, 3U, c5_d_index, 1.0, -1, 4U,
          c5_d_index > 1.0))) {
      covrtEmlMcdcEval(chartInstance->c5_covrtInstance, 4U, 0, 1, true);
      covrtEmlIfEval(chartInstance->c5_covrtInstance, 4U, 0, 1, true);
      c5_b_st.site = &c5_b_emlrtRSI;
      c5_i_x = c5_d_ON;
      c5_j_x = c5_i_x;
      c5_c_b = muDoubleScalarIsNaN(c5_j_x);
      if (c5_c_b) {
        c5_f_y = NULL;
        sf_mex_assign(&c5_f_y, sf_mex_create("y", c5_cv2, 10, 0U, 1U, 0U, 2, 1,
          19), false);
        c5_g_y = NULL;
        sf_mex_assign(&c5_g_y, sf_mex_create("y", c5_cv2, 10, 0U, 1U, 0U, 2, 1,
          19), false);
        sf_mex_call(&c5_b_st, &c5_emlrtMCI, "error", 0U, 2U, 14, c5_f_y, 14,
                    sf_mex_call(&c5_b_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c5_b_st, NULL, "message", 1U, 1U, 14, c5_g_y)));
      }

      c5_d_ON = c5_emlrt_update_log_1(chartInstance, (real_T)!(c5_d_ON != 0.0),
        chartInstance->c5_emlrtLocationLoggingDataTables, 19);
    } else {
      covrtEmlMcdcEval(chartInstance->c5_covrtInstance, 4U, 0, 1, false);
      covrtEmlIfEval(chartInstance->c5_covrtInstance, 4U, 0, 1, false);
    }
  }

  if (c5_guard1) {
    covrtEmlMcdcEval(chartInstance->c5_covrtInstance, 4U, 0, 0, false);
    covrtEmlIfEval(chartInstance->c5_covrtInstance, 4U, 0, 0, false);
  }

  *chartInstance->c5_b_index = c5_d_index;
  *chartInstance->c5_vel_err = c5_b_vel_err;
  *chartInstance->c5_ref_steer = c5_b_ref_steer;
  *chartInstance->c5_b_ON = c5_d_ON;
  *chartInstance->c5_counter = c5_d_counter;
  c5_do_animation_call_c5_car_model_FIXED(chartInstance);
  covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 4U,
                    *chartInstance->c5_b_index);
  covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 5U,
                    *chartInstance->c5_vel_err);
  covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 6U,
                    *chartInstance->c5_ref_steer);
  covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 7U, *chartInstance->c5_b_ON);
  covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 8U,
                    *chartInstance->c5_counter);
}

static void ext_mode_exec_c5_car_model_FIXED(SFc5_car_model_FIXEDInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void c5_update_jit_animation_c5_car_model_FIXED
  (SFc5_car_model_FIXEDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c5_do_animation_call_c5_car_model_FIXED
  (SFc5_car_model_FIXEDInstanceStruct *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static const mxArray *get_sim_state_c5_car_model_FIXED
  (SFc5_car_model_FIXEDInstanceStruct *chartInstance)
{
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_e_y = NULL;
  const mxArray *c5_f_y = NULL;
  const mxArray *c5_g_y = NULL;
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellmatrix(6, 1), false);
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", chartInstance->c5_b_ON, 0, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", chartInstance->c5_counter, 0, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c5_y, 1, c5_c_y);
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", chartInstance->c5_b_index, 0, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c5_y, 2, c5_d_y);
  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", chartInstance->c5_ref_steer, 0, 0U,
    0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 3, c5_e_y);
  c5_f_y = NULL;
  sf_mex_assign(&c5_f_y, sf_mex_create("y", chartInstance->c5_vel_err, 0, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c5_y, 4, c5_f_y);
  c5_g_y = NULL;
  sf_mex_assign(&c5_g_y, sf_mex_create("y",
    &chartInstance->c5_is_active_c5_car_model_FIXED, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 5, c5_g_y);
  sf_mex_assign(&c5_st, c5_y, false);
  return c5_st;
}

static void set_sim_state_c5_car_model_FIXED(SFc5_car_model_FIXEDInstanceStruct *
  chartInstance, const mxArray *c5_st)
{
  const mxArray *c5_u;
  chartInstance->c5_doneDoubleBufferReInit = true;
  c5_u = sf_mex_dup(c5_st);
  *chartInstance->c5_b_ON = c5_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 0)), "ON");
  *chartInstance->c5_counter = c5_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 1)), "counter");
  *chartInstance->c5_b_index = c5_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 2)), "index");
  *chartInstance->c5_ref_steer = c5_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 3)), "ref_steer");
  *chartInstance->c5_vel_err = c5_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 4)), "vel_err");
  chartInstance->c5_is_active_c5_car_model_FIXED = c5_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 5)),
     "is_active_c5_car_model_FIXED");
  sf_mex_destroy(&c5_u);
  sf_mex_destroy(&c5_st);
}

static void initSimStructsc5_car_model_FIXED(SFc5_car_model_FIXEDInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static real_T c5_emlrt_update_log_1(SFc5_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c5_in, emlrtLocationLoggingDataType c5_table[], int32_T
  c5_c_index)
{
  emlrtLocationLoggingDataType *c5_b_table;
  emlrtLocationLoggingHistogramType *c5_histTable;
  real_T c5_inDouble;
  real_T c5_localMax;
  real_T c5_localMin;
  real_T c5_significand;
  int32_T c5_exponent;
  boolean_T c5_isLoggingEnabledHere;
  (void)chartInstance;
  c5_isLoggingEnabledHere = (c5_c_index >= 0);
  if (c5_isLoggingEnabledHere) {
    c5_b_table = (emlrtLocationLoggingDataType *)&c5_table[c5_c_index];
    c5_localMin = c5_b_table[0U].SimMin;
    c5_localMax = c5_b_table[0U].SimMax;
    c5_histTable = c5_b_table[0U].HistogramTable;

    /* Simulation Min-Max logging. */
    if (c5_in < c5_localMin) {
      c5_localMin = c5_in;
    }

    if (c5_in > c5_localMax) {
      c5_localMax = c5_in;
    }

    /* Histogram logging. */
    c5_inDouble = c5_in;
    c5_histTable->TotalNumberOfValues++;
    if (c5_inDouble == 0.0) {
      c5_histTable->NumberOfZeros++;
    } else {
      c5_histTable->SimSum += c5_inDouble;
      if ((!muDoubleScalarIsInf(c5_inDouble)) && (!muDoubleScalarIsNaN
           (c5_inDouble))) {
        c5_significand = frexp(c5_inDouble, &c5_exponent);
        if (c5_exponent > 128) {
          c5_exponent = 128;
        }

        if (c5_exponent < -127) {
          c5_exponent = -127;
        }

        if (c5_significand < 0.0) {
          c5_histTable->NumberOfNegativeValues++;
          c5_histTable->HistogramOfNegativeValues[127 + c5_exponent]++;
        } else {
          c5_histTable->NumberOfPositiveValues++;
          c5_histTable->HistogramOfPositiveValues[127 + c5_exponent]++;
        }
      }
    }

    c5_b_table[0U].SimMin = c5_localMin;
    c5_b_table[0U].SimMax = c5_localMax;

    /* IsAlwaysInteger logging. */
    if (c5_in != muDoubleScalarFloor(c5_in)) {
      c5_b_table[0U].IsAlwaysInteger = false;
    }
  }

  return c5_in;
}

static c5_slBus15_Vel c5_emlrt_update_log_2(SFc5_car_model_FIXEDInstanceStruct
  *chartInstance, c5_slBus15_Vel c5_in, emlrtLocationLoggingDataType c5_table[],
  int32_T c5_c_index)
{
  c5_slBus15_Vel c5_out;
  c5_out = c5_in;
  c5_b_emlrt_update_log_2(chartInstance, &c5_out, c5_table, c5_c_index);
  return c5_out;
}

static void c5_emlrt_update_log_3(SFc5_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c5_in[1288], emlrtLocationLoggingDataType c5_table[],
  int32_T c5_c_index, real_T c5_out[1288])
{
  int32_T c5_i;
  for (c5_i = 0; c5_i < 1288; c5_i++) {
    c5_out[c5_i] = c5_in[c5_i];
  }

  c5_b_emlrt_update_log_3(chartInstance, c5_out, c5_table, c5_c_index);
}

static void c5_emlrtInitVarDataTables(SFc5_car_model_FIXEDInstanceStruct
  *chartInstance, emlrtLocationLoggingDataType c5_dataTables[20],
  emlrtLocationLoggingHistogramType c5_histTables[20])
{
  int32_T c5_i;
  int32_T c5_iH;
  (void)chartInstance;
  for (c5_i = 0; c5_i < 20; c5_i++) {
    c5_dataTables[c5_i].SimMin = rtInf;
    c5_dataTables[c5_i].SimMax = rtMinusInf;
    c5_dataTables[c5_i].OverflowWraps = 0;
    c5_dataTables[c5_i].Saturations = 0;
    c5_dataTables[c5_i].IsAlwaysInteger = true;
    c5_dataTables[c5_i].HistogramTable = &c5_histTables[c5_i];
    c5_histTables[c5_i].NumberOfZeros = 0.0;
    c5_histTables[c5_i].NumberOfPositiveValues = 0.0;
    c5_histTables[c5_i].NumberOfNegativeValues = 0.0;
    c5_histTables[c5_i].TotalNumberOfValues = 0.0;
    c5_histTables[c5_i].SimSum = 0.0;
    for (c5_iH = 0; c5_iH < 256; c5_iH++) {
      c5_histTables[c5_i].HistogramOfPositiveValues[c5_iH] = 0.0;
      c5_histTables[c5_i].HistogramOfNegativeValues[c5_iH] = 0.0;
    }
  }
}

const mxArray *sf_c5_car_model_FIXED_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  sf_mex_assign(&c5_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c5_nameCaptureInfo;
}

static real_T c5_emlrt_marshallIn(SFc5_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c5_c_ON, const char_T *c5_identifier)
{
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  c5_thisId.fIdentifier = (const char_T *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_c_ON), &c5_thisId);
  sf_mex_destroy(&c5_c_ON);
  return c5_y;
}

static real_T c5_b_emlrt_marshallIn(SFc5_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_d;
  real_T c5_y;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static uint8_T c5_c_emlrt_marshallIn(SFc5_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_car_model_FIXED, const char_T
  *c5_identifier)
{
  emlrtMsgIdentifier c5_thisId;
  uint8_T c5_y;
  c5_thisId.fIdentifier = (const char_T *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_y = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_is_active_c5_car_model_FIXED), &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_car_model_FIXED);
  return c5_y;
}

static uint8_T c5_d_emlrt_marshallIn(SFc5_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_b_u;
  uint8_T c5_y;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_b_u, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_b_u;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_slStringInitializeDynamicBuffers
  (SFc5_car_model_FIXEDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c5_chart_data_browse_helper(SFc5_car_model_FIXEDInstanceStruct
  *chartInstance, int32_T c5_ssIdNumber, const mxArray **c5_mxData, uint8_T
  *c5_isValueTooBig)
{
  const mxArray *c5_m = NULL;
  real_T c5_d;
  real_T c5_d1;
  real_T c5_d2;
  real_T c5_d3;
  real_T c5_d4;
  real_T c5_d5;
  real_T c5_d6;
  real_T c5_d7;
  *c5_mxData = NULL;
  *c5_mxData = NULL;
  *c5_isValueTooBig = 0U;
  switch (c5_ssIdNumber) {
   case 11U:
    c5_d = *chartInstance->c5_b_index;
    sf_mex_assign(c5_mxData, sf_mex_create("mxData", &c5_d, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 10U:
    c5_d1 = *chartInstance->c5_b_index;
    sf_mex_assign(c5_mxData, sf_mex_create("mxData", &c5_d1, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 4U:
    c5_m = NULL;
    sf_mex_assign(&c5_m, sf_mex_createstruct("mxData", 0, NULL, 0), false);
    sf_mex_addfield(c5_m, sf_mex_create("mxData", (real_T *)&((char_T *)
      chartInstance->c5_vel)[0], 0, 0U, 0U, 0U, 0), "xdot", "mxData", 0);
    sf_mex_addfield(c5_m, sf_mex_create("mxData", (real_T *)&((char_T *)
      chartInstance->c5_vel)[8], 0, 0U, 0U, 0U, 0), "ydot", "mxData", 0);
    sf_mex_addfield(c5_m, sf_mex_create("mxData", (real_T *)&((char_T *)
      chartInstance->c5_vel)[16], 0, 0U, 0U, 0U, 0), "zdot", "mxData", 0);
    sf_mex_assign(c5_mxData, c5_m, false);
    break;

   case 15U:
    c5_d2 = *chartInstance->c5_b_ON;
    sf_mex_assign(c5_mxData, sf_mex_create("mxData", &c5_d2, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 5U:
    c5_d3 = *chartInstance->c5_vel_err;
    sf_mex_assign(c5_mxData, sf_mex_create("mxData", &c5_d3, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 6U:
    c5_d4 = *chartInstance->c5_ref_steer;
    sf_mex_assign(c5_mxData, sf_mex_create("mxData", &c5_d4, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 14U:
    c5_d5 = *chartInstance->c5_b_ON;
    sf_mex_assign(c5_mxData, sf_mex_create("mxData", &c5_d5, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 7U:
    sf_mex_assign(c5_mxData, sf_mex_create("mxData",
      chartInstance->c5_selected_sweep, 0, 0U, 1U, 0U, 2, 644, 2), false);
    break;

   case 8U:
    sf_mex_assign(c5_mxData, sf_mex_create("mxData", &chartInstance->c5_dt_ON, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 9U:
    sf_mex_assign(c5_mxData, sf_mex_create("mxData", &chartInstance->c5_dt_OFF,
      0, 0U, 0U, 0U, 0), false);
    break;

   case 12U:
    c5_d6 = *chartInstance->c5_counter;
    sf_mex_assign(c5_mxData, sf_mex_create("mxData", &c5_d6, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 13U:
    c5_d7 = *chartInstance->c5_counter;
    sf_mex_assign(c5_mxData, sf_mex_create("mxData", &c5_d7, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 16U:
    sf_mex_assign(c5_mxData, sf_mex_create("mxData",
      &chartInstance->c5_tvs_t_sim, 0, 0U, 0U, 0U, 0), false);
    break;
  }
}

static void c5_b_emlrt_update_log_2(SFc5_car_model_FIXEDInstanceStruct
  *chartInstance, c5_slBus15_Vel *c5_in, emlrtLocationLoggingDataType c5_table[],
  int32_T c5_c_index)
{
  emlrtLocationLoggingDataType *c5_b_table;
  emlrtLocationLoggingHistogramType *c5_b_histTable;
  emlrtLocationLoggingHistogramType *c5_c_histTable;
  emlrtLocationLoggingHistogramType *c5_histTable;
  real_T c5_b_inDouble;
  real_T c5_b_localMax;
  real_T c5_b_localMin;
  real_T c5_b_significand;
  real_T c5_c_inDouble;
  real_T c5_c_localMax;
  real_T c5_c_localMin;
  real_T c5_c_significand;
  real_T c5_inDouble;
  real_T c5_localMax;
  real_T c5_localMin;
  real_T c5_significand;
  int32_T c5_b_exponent;
  int32_T c5_c_exponent;
  int32_T c5_exponent;
  boolean_T c5_isLoggingEnabledHere;
  (void)chartInstance;
  c5_isLoggingEnabledHere = (c5_c_index >= 0);
  if (c5_isLoggingEnabledHere) {
    c5_b_table = (emlrtLocationLoggingDataType *)&c5_table[c5_c_index];
    c5_localMin = c5_b_table[0U].SimMin;
    c5_localMax = c5_b_table[0U].SimMax;
    c5_histTable = c5_b_table[0U].HistogramTable;

    /* Simulation Min-Max logging. */
    if (c5_in->xdot < c5_localMin) {
      c5_localMin = c5_in->xdot;
    }

    if (c5_in->xdot > c5_localMax) {
      c5_localMax = c5_in->xdot;
    }

    /* Histogram logging. */
    c5_inDouble = c5_in->xdot;
    c5_histTable->TotalNumberOfValues++;
    if (c5_inDouble == 0.0) {
      c5_histTable->NumberOfZeros++;
    } else {
      c5_histTable->SimSum += c5_inDouble;
      if ((!muDoubleScalarIsInf(c5_inDouble)) && (!muDoubleScalarIsNaN
           (c5_inDouble))) {
        c5_significand = frexp(c5_inDouble, &c5_exponent);
        if (c5_exponent > 128) {
          c5_exponent = 128;
        }

        if (c5_exponent < -127) {
          c5_exponent = -127;
        }

        if (c5_significand < 0.0) {
          c5_histTable->NumberOfNegativeValues++;
          c5_histTable->HistogramOfNegativeValues[127 + c5_exponent]++;
        } else {
          c5_histTable->NumberOfPositiveValues++;
          c5_histTable->HistogramOfPositiveValues[127 + c5_exponent]++;
        }
      }
    }

    c5_b_table[0U].SimMin = c5_localMin;
    c5_b_table[0U].SimMax = c5_localMax;

    /* IsAlwaysInteger logging. */
    if (c5_in->xdot != muDoubleScalarFloor(c5_in->xdot)) {
      c5_b_table[0U].IsAlwaysInteger = false;
    }

    c5_b_localMin = c5_b_table[1U].SimMin;
    c5_b_localMax = c5_b_table[1U].SimMax;
    c5_b_histTable = c5_b_table[1U].HistogramTable;

    /* Simulation Min-Max logging. */
    if (c5_in->ydot < c5_b_localMin) {
      c5_b_localMin = c5_in->ydot;
    }

    if (c5_in->ydot > c5_b_localMax) {
      c5_b_localMax = c5_in->ydot;
    }

    /* Histogram logging. */
    c5_b_inDouble = c5_in->ydot;
    c5_b_histTable->TotalNumberOfValues++;
    if (c5_b_inDouble == 0.0) {
      c5_b_histTable->NumberOfZeros++;
    } else {
      c5_b_histTable->SimSum += c5_b_inDouble;
      if ((!muDoubleScalarIsInf(c5_b_inDouble)) && (!muDoubleScalarIsNaN
           (c5_b_inDouble))) {
        c5_b_significand = frexp(c5_b_inDouble, &c5_b_exponent);
        if (c5_b_exponent > 128) {
          c5_b_exponent = 128;
        }

        if (c5_b_exponent < -127) {
          c5_b_exponent = -127;
        }

        if (c5_b_significand < 0.0) {
          c5_b_histTable->NumberOfNegativeValues++;
          c5_b_histTable->HistogramOfNegativeValues[127 + c5_b_exponent]++;
        } else {
          c5_b_histTable->NumberOfPositiveValues++;
          c5_b_histTable->HistogramOfPositiveValues[127 + c5_b_exponent]++;
        }
      }
    }

    c5_b_table[1U].SimMin = c5_b_localMin;
    c5_b_table[1U].SimMax = c5_b_localMax;

    /* IsAlwaysInteger logging. */
    if (c5_in->ydot != muDoubleScalarFloor(c5_in->ydot)) {
      c5_b_table[1U].IsAlwaysInteger = false;
    }

    c5_c_localMin = c5_b_table[2U].SimMin;
    c5_c_localMax = c5_b_table[2U].SimMax;
    c5_c_histTable = c5_b_table[2U].HistogramTable;

    /* Simulation Min-Max logging. */
    if (c5_in->zdot < c5_c_localMin) {
      c5_c_localMin = c5_in->zdot;
    }

    if (c5_in->zdot > c5_c_localMax) {
      c5_c_localMax = c5_in->zdot;
    }

    /* Histogram logging. */
    c5_c_inDouble = c5_in->zdot;
    c5_c_histTable->TotalNumberOfValues++;
    if (c5_c_inDouble == 0.0) {
      c5_c_histTable->NumberOfZeros++;
    } else {
      c5_c_histTable->SimSum += c5_c_inDouble;
      if ((!muDoubleScalarIsInf(c5_c_inDouble)) && (!muDoubleScalarIsNaN
           (c5_c_inDouble))) {
        c5_c_significand = frexp(c5_c_inDouble, &c5_c_exponent);
        if (c5_c_exponent > 128) {
          c5_c_exponent = 128;
        }

        if (c5_c_exponent < -127) {
          c5_c_exponent = -127;
        }

        if (c5_c_significand < 0.0) {
          c5_c_histTable->NumberOfNegativeValues++;
          c5_c_histTable->HistogramOfNegativeValues[127 + c5_c_exponent]++;
        } else {
          c5_c_histTable->NumberOfPositiveValues++;
          c5_c_histTable->HistogramOfPositiveValues[127 + c5_c_exponent]++;
        }
      }
    }

    c5_b_table[2U].SimMin = c5_c_localMin;
    c5_b_table[2U].SimMax = c5_c_localMax;

    /* IsAlwaysInteger logging. */
    if (c5_in->zdot != muDoubleScalarFloor(c5_in->zdot)) {
      c5_b_table[2U].IsAlwaysInteger = false;
    }
  }
}

static void c5_b_emlrt_update_log_3(SFc5_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c5_in[1288], emlrtLocationLoggingDataType c5_table[],
  int32_T c5_c_index)
{
  emlrtLocationLoggingDataType *c5_b_table;
  emlrtLocationLoggingHistogramType *c5_histTable;
  real_T c5_inDouble;
  real_T c5_localMax;
  real_T c5_localMin;
  real_T c5_significand;
  int32_T c5_b_i;
  int32_T c5_exponent;
  int32_T c5_i;
  boolean_T c5_isLoggingEnabledHere;
  (void)chartInstance;
  c5_isLoggingEnabledHere = (c5_c_index >= 0);
  if (c5_isLoggingEnabledHere) {
    c5_b_table = (emlrtLocationLoggingDataType *)&c5_table[c5_c_index];
    c5_localMin = c5_b_table[0U].SimMin;
    c5_localMax = c5_b_table[0U].SimMax;
    c5_histTable = c5_b_table[0U].HistogramTable;
    for (c5_i = 0; c5_i < 1288; c5_i++) {
      /* Simulation Min-Max logging. */
      if (c5_in[c5_i] < c5_localMin) {
        c5_localMin = c5_in[c5_i];
      }

      if (c5_in[c5_i] > c5_localMax) {
        c5_localMax = c5_in[c5_i];
      }

      /* Histogram logging. */
      c5_inDouble = c5_in[c5_i];
      c5_histTable->TotalNumberOfValues++;
      if (c5_inDouble == 0.0) {
        c5_histTable->NumberOfZeros++;
      } else {
        c5_histTable->SimSum += c5_inDouble;
        if ((!muDoubleScalarIsInf(c5_inDouble)) && (!muDoubleScalarIsNaN
             (c5_inDouble))) {
          c5_significand = frexp(c5_inDouble, &c5_exponent);
          if (c5_exponent > 128) {
            c5_exponent = 128;
          }

          if (c5_exponent < -127) {
            c5_exponent = -127;
          }

          if (c5_significand < 0.0) {
            c5_histTable->NumberOfNegativeValues++;
            c5_histTable->HistogramOfNegativeValues[127 + c5_exponent]++;
          } else {
            c5_histTable->NumberOfPositiveValues++;
            c5_histTable->HistogramOfPositiveValues[127 + c5_exponent]++;
          }
        }
      }
    }

    c5_b_table[0U].SimMin = c5_localMin;
    c5_b_table[0U].SimMax = c5_localMax;

    /* IsAlwaysInteger logging. */
    c5_b_i = 0;
    while (c5_b_table[0U].IsAlwaysInteger && (c5_b_i < 1288)) {
      if (c5_in[c5_b_i] != muDoubleScalarFloor(c5_in[c5_b_i])) {
        c5_b_table[0U].IsAlwaysInteger = false;
      }

      c5_b_i++;
    }
  }
}

static void init_dsm_address_info(SFc5_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc5_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  chartInstance->c5_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c5_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c5_index = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c5_b_index = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c5_vel = (c5_slBus15_Vel *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c5_ON = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    2);
  chartInstance->c5_vel_err = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c5_ref_steer = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c5_b_ON = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c5_counter = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c5_b_counter = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c5_car_model_FIXED_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3376946576U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2810827614U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(937899071U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(713465099U);
}

mxArray *sf_c5_car_model_FIXED_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c5_car_model_FIXED_jit_fallback_info(void)
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

mxArray *sf_c5_car_model_FIXED_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c5_car_model_FIXED(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiBWYGVgYAPSHEDMxAABrFA+IwNEjhEuzgIXVwDiksqCVJB4cVGyZwqQzkvMBfM"
    "TSys889LyweZbMCDMZ8NiPiOS+ZxQcQj4YE+Zfh0HkH4DJP0sWPQzIekXAPL8/SDhAgufgXO/hg"
    "O6fmzuZ0dxP4SfnF+aV5JaNEj8oUKUP1jR/AHiZ+alpFYwDJb4kAD7w4GAPzjR/AHiF6WmxReXp"
    "AJjBOGPgfePCNnpqyw1Jz61iFrpS8GBMv0Q+wMI+EMGzR8gfmZxfGJySWZZanyyaXxyYlF8bn4K"
    "0GtunhGuLsjxBADXljHW"
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_car_model_FIXED_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "s4qu3JUgCHDtAc1vsRZRLeH";
}

static void sf_opaque_initialize_c5_car_model_FIXED(void *chartInstanceVar)
{
  initialize_params_c5_car_model_FIXED((SFc5_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
  initialize_c5_car_model_FIXED((SFc5_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c5_car_model_FIXED(void *chartInstanceVar)
{
  enable_c5_car_model_FIXED((SFc5_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c5_car_model_FIXED(void *chartInstanceVar)
{
  disable_c5_car_model_FIXED((SFc5_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c5_car_model_FIXED(void *chartInstanceVar)
{
  sf_gateway_c5_car_model_FIXED((SFc5_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c5_car_model_FIXED(SimStruct* S)
{
  return get_sim_state_c5_car_model_FIXED((SFc5_car_model_FIXEDInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c5_car_model_FIXED(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c5_car_model_FIXED((SFc5_car_model_FIXEDInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c5_car_model_FIXED(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_car_model_FIXEDInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_car_model_FIXED_optimization_info();
    }

    mdl_cleanup_runtime_resources_c5_car_model_FIXED
      ((SFc5_car_model_FIXEDInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c5_car_model_FIXED(void *chartInstanceVar)
{
  mdl_start_c5_car_model_FIXED((SFc5_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_mdl_terminate_c5_car_model_FIXED(void *chartInstanceVar)
{
  mdl_terminate_c5_car_model_FIXED((SFc5_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc5_car_model_FIXED((SFc5_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_car_model_FIXED(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  sf_warn_if_symbolic_dimension_param_changed(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_car_model_FIXED((SFc5_car_model_FIXEDInstanceStruct*)
      sf_get_chart_instance_ptr(S));
    initSimStructsc5_car_model_FIXED((SFc5_car_model_FIXEDInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c5_car_model_FIXED_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [23] = {
    "eNrtWU1vG0UYHkdJSkSJKoRUDpEIEoceQKItlTig4sQfxChprKwTUC9msvvaO/Ls7GY+7BjxG7j",
    "wA/gN3PgPXDjyCzhzAVXiwjvrteNsjL3jlDatWGmznt193q95Pzek1DggeGzi+fMWIet4fQPPFT",
    "I61rJ1aeoc3V8ln2Xr794kxI8D6ILwTKfDzonbIUzUpJJGirgfgkZwBCrmRrNYNEQnLo5logMSh",
    "I8EklhqJ76KRYYz0asb4VvO6quQ+aEXxoYHu0iQBoeCD/+Nb2J0EzlWmQRf1wECHcrYdMM6p935",
    "VpB6UAnB7ykTOdtKgfZMYlVVB4ZrlnConYPfEEpTtIJaoK+nqYaKPnczstVXeWN0HCWcUVHc1iF",
    "VHiToHRqOkwD/HhqN1iuE9UMq9S6EtA9qn/VS7rGAQtyZwrdPmaA6lozyWsQrllpBfZscdTzAkO",
    "Cue4T67kqgvSRmQjsGhFdHO9cEPeVQhVPTdeTrwZmx0XDCYADSbX87lbgPknbhULjJnO5R7Tx1y",
    "kksFcRqFsEJlTs++q6CwC1vYNApj6I7QgvJOGEhNXFDtSTro2+45rqGDf+lcp2JRt6vlsKmfGt9",
    "cParCd+6LyqUc+WGbcXJPvSBp/yrVNMlsCP+DmClWNCK0TtstnHMWEYwjIQMW4lFwIp7ZT+HSgv",
    "bEyxSBeAssmEAAZp5IvqE0KI4MkrHUQVTTnV/vyC/q9iG0CA71IfCNUZSpgAFTv3KkW/AlA0kRK",
    "OVdKplYQqjGFwKSlTHiOoglj20sWsxu7CVjQQ3NARdTMwa0iRXQ+8+odwUlDlSXYwfdI9jhVnWj",
    "S9ibfwsBfapH0JgKyfjcIB5FgkU3WJlS/4OattnelgF5UuWFI0kgwkdi661UmuYwLHoiXgg6jKO",
    "vKzzmuNXAJg1qBRMdHexhMthHYUvJrWEs1aa3V2bHGtnqjk9tb7xBQishlZX2zVQH6OqJrBFRoG",
    "ug/XYt9jECMWUxkI9HJX6Ud2z/fseuejfV2f0729P9e93srX/qO1T2Y5sr9KuN76uVcmE3sdT9G",
    "4XmAdWC+DIFdwFv/H13hS+NIMvmbrm+W2sXH5/NcdvBe+U8LC48hTuLTIft57ZrPln9eCXn35/d",
    "uuH97//65sf/17Ev3SFfyn9bXG/rrnNW5vZemvcN02ydP9KIiviD3dz/mDX6pMz8/DL425lr6p3",
    "/Pt9dfT0aB/2UnrbC+Rdz8k7vr9tezUM4jQnSL8RZHObXVMzmics/U+n5F1fYI+NKX8i5I/Pr4f",
    "/sJzfx1n2WrlkrxVy+OSy3748+e+V8/hZ8t/K7bdd+7GxNf+G6PFBIT3WcnqspTN1AOfkpuzHu+",
    "V8fpmlx0ZOj420/nTamN0n89fN0Oedpf0Le/c2yOflX9vl6+FH/JsL9NjK6bGVzrhtajsZaM+um",
    "JsF69G8euCKIy8Y96rI+b9d/nv9nlc/OAu3tiSOvGDcdfVz7XNf9ffn9Vck9/6dG6zHvHzvMu/c",
    "NL1+I27zyHvZ+vHke1slZDyYMfFnj3Eo78x6+pr49zNH+43nr5q1X/aPmacPdwTlQxzxR59Qstt",
    "Nab+vTx5JoGr2d5SXUU/G10X97u1cfNv1ABv3eKA+uv/g0YPr1Kd/AHrBM2g=",
    ""
  };

  static char newstr [1637] = "";
  newstr[0] = '\0';
  for (i = 0; i < 23; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c5_car_model_FIXED(SimStruct *S)
{
  const char* newstr = sf_c5_car_model_FIXED_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(1296364880U));
  ssSetChecksum1(S,(4175868363U));
  ssSetChecksum2(S,(2384564999U));
  ssSetChecksum3(S,(4221526262U));
}

static void mdlRTW_c5_car_model_FIXED(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c5_car_model_FIXED(SimStruct *S)
{
  SFc5_car_model_FIXEDInstanceStruct *chartInstance;
  chartInstance = (SFc5_car_model_FIXEDInstanceStruct *)utMalloc(sizeof
    (SFc5_car_model_FIXEDInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc5_car_model_FIXEDInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_car_model_FIXED;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_car_model_FIXED;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c5_car_model_FIXED;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c5_car_model_FIXED;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c5_car_model_FIXED;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_car_model_FIXED;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c5_car_model_FIXED;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_car_model_FIXED;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_car_model_FIXED;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_car_model_FIXED;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_car_model_FIXED;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c5_car_model_FIXED;
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
    chartInstance->c5_JITStateAnimation,
    chartInstance->c5_JITTransitionAnimation);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c5_car_model_FIXED(chartInstance);
}

void c5_car_model_FIXED_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c5_car_model_FIXED(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_car_model_FIXED(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_car_model_FIXED(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_car_model_FIXED_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
