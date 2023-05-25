/* Include files */

#include "car_model_FIXED_sfun.h"
#include "c8_car_model_FIXED.h"
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
static emlrtMCInfo c8_emlrtMCI = { 13, /* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pName */
};

static emlrtRSInfo c8_emlrtRSI = { 3,  /* lineNo */
  "Vehicle Model/Electronics/Navigation Sensors/VNED to SNED",/* fcnName */
  "#car_model_FIXED:5480"              /* pathName */
};

static emlrtRSInfo c8_b_emlrtRSI = { 4,/* lineNo */
  "Vehicle Model/Electronics/Navigation Sensors/VNED to SNED",/* fcnName */
  "#car_model_FIXED:5480"              /* pathName */
};

static emlrtRSInfo c8_c_emlrtRSI = { 7,/* lineNo */
  "Vehicle Model/Electronics/Navigation Sensors/VNED to SNED",/* fcnName */
  "#car_model_FIXED:5480"              /* pathName */
};

static emlrtRSInfo c8_d_emlrtRSI = { 8,/* lineNo */
  "Vehicle Model/Electronics/Navigation Sensors/VNED to SNED",/* fcnName */
  "#car_model_FIXED:5480"              /* pathName */
};

static emlrtRSInfo c8_e_emlrtRSI = { 9,/* lineNo */
  "Vehicle Model/Electronics/Navigation Sensors/VNED to SNED",/* fcnName */
  "#car_model_FIXED:5480"              /* pathName */
};

static emlrtRSInfo c8_f_emlrtRSI = { 19,/* lineNo */
  "rotmat",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\rotations\\rotationslib\\+matlabshared\\+rotations\\+internal\\@quaternionBase\\rotmat.m"/* pathName */
};

static emlrtRSInfo c8_g_emlrtRSI = { 10,/* lineNo */
  "normalize",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\rotations\\rotationslib\\+matlabshared\\+rotations\\+internal\\@quaternionBase\\normaliz"
  "e.m"                                /* pathName */
};

static emlrtRSInfo c8_h_emlrtRSI = { 20,/* lineNo */
  "mldivide",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m"/* pathName */
};

static emlrtRSInfo c8_i_emlrtRSI = { 42,/* lineNo */
  "mldivide",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m"/* pathName */
};

static emlrtRSInfo c8_j_emlrtRSI = { 61,/* lineNo */
  "lusolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo c8_k_emlrtRSI = { 293,/* lineNo */
  "lusolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo c8_l_emlrtRSI = { 90,/* lineNo */
  "lusolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo c8_m_emlrtRSI = { 14,/* lineNo */
  "warning",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\warning.m"/* pathName */
};

/* Function Declarations */
static void initialize_c8_car_model_FIXED(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance);
static void initialize_params_c8_car_model_FIXED
  (SFc8_car_model_FIXEDInstanceStruct *chartInstance);
static void mdl_start_c8_car_model_FIXED(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance);
static void mdl_terminate_c8_car_model_FIXED(SFc8_car_model_FIXEDInstanceStruct *
  chartInstance);
static void mdl_setup_runtime_resources_c8_car_model_FIXED
  (SFc8_car_model_FIXEDInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c8_car_model_FIXED
  (SFc8_car_model_FIXEDInstanceStruct *chartInstance);
static void enable_c8_car_model_FIXED(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance);
static void disable_c8_car_model_FIXED(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance);
static void sf_gateway_c8_car_model_FIXED(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance);
static void ext_mode_exec_c8_car_model_FIXED(SFc8_car_model_FIXEDInstanceStruct *
  chartInstance);
static void c8_update_jit_animation_c8_car_model_FIXED
  (SFc8_car_model_FIXEDInstanceStruct *chartInstance);
static void c8_do_animation_call_c8_car_model_FIXED
  (SFc8_car_model_FIXEDInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c8_car_model_FIXED
  (SFc8_car_model_FIXEDInstanceStruct *chartInstance);
static void set_sim_state_c8_car_model_FIXED(SFc8_car_model_FIXEDInstanceStruct *
  chartInstance, const mxArray *c8_st);
static void initSimStructsc8_car_model_FIXED(SFc8_car_model_FIXEDInstanceStruct *
  chartInstance);
static void c8_emlrt_update_log_1(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c8_in[3], emlrtLocationLoggingDataType c8_table[],
  int32_T c8_index, real_T c8_out[3]);
static real_T c8_emlrt_update_log_2(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c8_in, emlrtLocationLoggingDataType c8_table[], int32_T
  c8_index);
static void c8_emlrt_update_log_3(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c8_in[9], emlrtLocationLoggingDataType c8_table[],
  int32_T c8_index, real_T c8_out[9]);
static c8_quaternion c8_emlrt_update_log_4(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, c8_quaternion c8_in, emlrtLocationLoggingDataType c8_table[],
  int32_T c8_index);
static c8_rtString c8_emlrt_update_log_5(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, c8_rtString c8_in, emlrtLocationLoggingDataType c8_table[],
  int32_T c8_index);
static c8_rtString_1 c8_emlrt_update_log_6(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, c8_rtString_1 c8_in, emlrtLocationLoggingDataType c8_table[],
  int32_T c8_index);
static c8_rtString_2 c8_emlrt_update_log_7(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, c8_rtString_2 c8_in, emlrtLocationLoggingDataType c8_table[],
  int32_T c8_index);
static void c8_emlrt_update_log_8(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c8_in[3], emlrtLocationLoggingDataType c8_table[],
  int32_T c8_index, real_T c8_out[3]);
static void c8_emlrtInitVarDataTables(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, emlrtLocationLoggingDataType c8_dataTables[30],
  emlrtLocationLoggingHistogramType c8_histTables[30]);
static c8_quaternion c8_quaternionBase_normalize
  (SFc8_car_model_FIXEDInstanceStruct *chartInstance, const emlrtStack *c8_sp,
   c8_quaternion c8_q);
static void c8_mldivide(SFc8_car_model_FIXEDInstanceStruct *chartInstance, const
  emlrtStack *c8_sp, real_T c8_A[9], real_T c8_B[3], real_T c8_Y[3]);
static void c8_warning(SFc8_car_model_FIXEDInstanceStruct *chartInstance, const
  emlrtStack *c8_sp);
static void c8_emlrt_marshallIn(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c8_b_accel_SNED, const char_T *c8_identifier,
  real_T c8_y[3]);
static void c8_b_emlrt_marshallIn(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  real_T c8_y[3]);
static uint8_T c8_c_emlrt_marshallIn(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c8_b_is_active_c8_car_model_FIXED, const char_T
  *c8_identifier);
static uint8_T c8_d_emlrt_marshallIn(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_slStringInitializeDynamicBuffers
  (SFc8_car_model_FIXEDInstanceStruct *chartInstance);
static void c8_chart_data_browse_helper(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, int32_T c8_ssIdNumber, const mxArray **c8_mxData, uint8_T
  *c8_isValueTooBig);
static const mxArray *c8_feval(SFc8_car_model_FIXEDInstanceStruct *chartInstance,
  const emlrtStack *c8_sp, const mxArray *c8_input0, const mxArray *c8_input1);
static void c8_b_feval(SFc8_car_model_FIXEDInstanceStruct *chartInstance, const
  emlrtStack *c8_sp, const mxArray *c8_input0, const mxArray *c8_input1);
static void c8_b_emlrt_update_log_1(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c8_in[3], emlrtLocationLoggingDataType c8_table[],
  int32_T c8_index);
static void c8_b_emlrt_update_log_3(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c8_in[9], emlrtLocationLoggingDataType c8_table[],
  int32_T c8_index);
static void c8_b_emlrt_update_log_4(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, c8_quaternion *c8_in, emlrtLocationLoggingDataType c8_table[],
  int32_T c8_index);
static void c8_b_emlrt_update_log_5(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, c8_rtString *c8_in, emlrtLocationLoggingDataType c8_table[],
  int32_T c8_index);
static void c8_b_emlrt_update_log_6(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, c8_rtString_1 *c8_in, emlrtLocationLoggingDataType c8_table[],
  int32_T c8_index);
static void c8_b_emlrt_update_log_7(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, c8_rtString_2 *c8_in, emlrtLocationLoggingDataType c8_table[],
  int32_T c8_index);
static void c8_b_emlrt_update_log_8(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c8_in[3], emlrtLocationLoggingDataType c8_table[],
  int32_T c8_index);
static void c8_b_quaternionBase_normalize(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, const emlrtStack *c8_sp, c8_quaternion *c8_q);
static void init_dsm_address_info(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c8_car_model_FIXED(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
  chartInstance->c8_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c8_is_active_c8_car_model_FIXED = 0U;
  chartInstance->c8_emlrtLocLogSimulated = false;
  c8_emlrtInitVarDataTables(chartInstance,
    chartInstance->c8_emlrtLocationLoggingDataTables,
    chartInstance->c8_emlrtLocLogHistTables);
}

static void initialize_params_c8_car_model_FIXED
  (SFc8_car_model_FIXEDInstanceStruct *chartInstance)
{
  real_T c8_d;
  sf_mex_import_named("phi", sf_mex_get_sfun_param(chartInstance->S, 0U, 0U),
                      &c8_d, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c8_phi = c8_d;
}

static void mdl_start_c8_car_model_FIXED(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void mdl_terminate_c8_car_model_FIXED(SFc8_car_model_FIXEDInstanceStruct *
  chartInstance)
{
  const emlrtLocationLoggingFileInfoType c8_emlrtLocationLoggingFileInfo = {
    "#car_model_FIXED:5480",           /* mexFileName */
    "Mon Apr 17 19:52:51 2023",        /* timestamp */
    "",                                /* buildDir */
    1,                                 /* numFcns */
    256                                /* numHistogramBins */
  };

  const emlrtLocationLoggingFunctionInfoType
    c8_emlrtLocationLoggingFunctionInfoTable[1] = { { "eML_blk_kernel",/* fcnName */
      1,                               /* fcnId */
      24                               /* numInstrPoints */
    } };

  const emlrtLocationLoggingLocationType c8_emlrtLocationInfo[26] = { { 1,/* MxInfoID */
      55,                              /* TextStart */
      10,                              /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      67,                              /* TextStart */
      9,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      78,                              /* TextStart */
      8,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      88,                              /* TextStart */
      3,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 3,                            /* MxInfoID */
      112,                             /* TextStart */
      11,                              /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 3,                            /* MxInfoID */
      126,                             /* TextStart */
      68,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 4,                            /* MxInfoID */
      133,                             /* TextStart */
      52,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      148,                             /* TextStart */
      9,                               /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 6,                            /* MxInfoID */
      162,                             /* TextStart */
      8,                               /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 9,                            /* MxInfoID */
      171,                             /* TextStart */
      5,                               /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 11,                           /* MxInfoID */
      177,                             /* TextStart */
      7,                               /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 11,                           /* MxInfoID */
      186,                             /* TextStart */
      7,                               /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 3,                            /* MxInfoID */
      196,                             /* TextStart */
      11,                              /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 3,                            /* MxInfoID */
      210,                             /* TextStart */
      70,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 4,                            /* MxInfoID */
      217,                             /* TextStart */
      54,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      234,                             /* TextStart */
      9,                               /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 6,                            /* MxInfoID */
      248,                             /* TextStart */
      8,                               /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 9,                            /* MxInfoID */
      257,                             /* TextStart */
      5,                               /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 11,                           /* MxInfoID */
      263,                             /* TextStart */
      7,                               /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 11,                           /* MxInfoID */
      272,                             /* TextStart */
      7,                               /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      312,                             /* TextStart */
      10,                              /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 13,                           /* MxInfoID */
      325,                             /* TextStart */
      22,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      349,                             /* TextStart */
      9,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 13,                           /* MxInfoID */
      361,                             /* TextStart */
      21,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      384,                             /* TextStart */
      8,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 13,                           /* MxInfoID */
      395,                             /* TextStart */
      20,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    } };

  const int32_T c8_emlrtLocationLoggingFieldCounts[24] = { 0, 0, 0, 0, 0, 4, 0,
    1, 1, 1, 1, 0, 4, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 };

  const char_T *c8_emlrtLocationLoggingFieldNames[16] = { "a", "b", "c", "d",
    "__$isSimulinkString.__dummy", "__$isSimulinkString.__dummy",
    "__$isSimulinkString.__dummy", "__$isSimulinkString.__dummy", "a", "b", "c",
    "d", "__$isSimulinkString.__dummy", "__$isSimulinkString.__dummy",
    "__$isSimulinkString.__dummy", "__$isSimulinkString.__dummy" };

  if (chartInstance->c8_emlrtLocLogSimulated) {
    emlrtLocationLoggingClearLog("#car_model_FIXED:5480");
    emlrtLocationLoggingPushLog(&c8_emlrtLocationLoggingFileInfo,
      &c8_emlrtLocationLoggingFunctionInfoTable[0],
      &chartInstance->c8_emlrtLocationLoggingDataTables[0],
      &c8_emlrtLocationInfo[0], NULL, 0U, &c8_emlrtLocationLoggingFieldCounts[0],
      &c8_emlrtLocationLoggingFieldNames[0]);
    addResultsToFPTRepository("#car_model_FIXED:5480");
  }
}

static void mdl_setup_runtime_resources_c8_car_model_FIXED
  (SFc8_car_model_FIXEDInstanceStruct *chartInstance)
{
  static const uint32_T c8_decisionTxtEndIdx = 0U;
  static const uint32_T c8_decisionTxtStartIdx = 0U;
  setDebuggerFlag(chartInstance->S, true);
  setDataBrowseFcn(chartInstance->S, (void *)&c8_chart_data_browse_helper);
  chartInstance->c8_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c8_RuntimeVar,
    &chartInstance->c8_IsDebuggerActive,
    &chartInstance->c8_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c8_mlFcnLineNumber, &chartInstance->c8_IsHeatMapPresent, 0);
  sim_mode_is_external(chartInstance->S);
  covrtCreateStateflowInstanceData(chartInstance->c8_covrtInstance, 1U, 0U, 1U,
    130U);
  covrtChartInitFcn(chartInstance->c8_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c8_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c8_decisionTxtStartIdx, &c8_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c8_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c8_covrtInstance, "", 4U, 0U, 1U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c8_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 421);
}

static void mdl_cleanup_runtime_resources_c8_car_model_FIXED
  (SFc8_car_model_FIXEDInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c8_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c8_covrtInstance);
}

static void enable_c8_car_model_FIXED(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c8_car_model_FIXED(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c8_car_model_FIXED(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  static char_T c8_cv[6] = { 'e', 'u', 'l', 'e', 'r', 'd' };

  static char_T c8_cv2[5] = { 'f', 'r', 'a', 'm', 'e' };

  static char_T c8_cv1[3] = { 'X', 'Y', 'Z' };

  c8_quaternion c8_d_obj;
  c8_rtString c8_obj;
  c8_rtString_1 c8_b_obj;
  c8_rtString_2 c8_c_obj;
  emlrtStack c8_b_st;
  emlrtStack c8_c_st;
  emlrtStack c8_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  real_T c8_b_rmat[9];
  real_T c8_rmat[9];
  real_T c8_b_gyro_SNED[3];
  real_T c8_dv[3];
  real_T c8_dv1[3];
  real_T c8_dv2[3];
  real_T c8_dv3[3];
  real_T c8_varargin_1[3];
  real_T c8_a;
  real_T c8_aasq;
  real_T c8_ab2;
  real_T c8_ab_x;
  real_T c8_ac2;
  real_T c8_ac_x;
  real_T c8_ad2;
  real_T c8_ad_x;
  real_T c8_b;
  real_T c8_b_a;
  real_T c8_b_aasq;
  real_T c8_b_ab2;
  real_T c8_b_ac2;
  real_T c8_b_ad2;
  real_T c8_b_b;
  real_T c8_b_bbsq;
  real_T c8_b_bc2;
  real_T c8_b_bd2;
  real_T c8_b_c;
  real_T c8_b_ccsq;
  real_T c8_b_cd2;
  real_T c8_b_ddsq;
  real_T c8_b_phi;
  real_T c8_b_qa;
  real_T c8_b_qb;
  real_T c8_b_qc;
  real_T c8_b_qd;
  real_T c8_b_ta;
  real_T c8_b_tb;
  real_T c8_b_tc;
  real_T c8_b_td;
  real_T c8_b_x;
  real_T c8_bb_x;
  real_T c8_bbsq;
  real_T c8_bc2;
  real_T c8_bc_x;
  real_T c8_bd2;
  real_T c8_bd_x;
  real_T c8_c;
  real_T c8_c_qa;
  real_T c8_c_qb;
  real_T c8_c_qc;
  real_T c8_c_qd;
  real_T c8_c_x;
  real_T c8_cb_x;
  real_T c8_cc_x;
  real_T c8_ccsq;
  real_T c8_cd2;
  real_T c8_cd_x;
  real_T c8_d;
  real_T c8_d1;
  real_T c8_d2;
  real_T c8_d3;
  real_T c8_d4;
  real_T c8_d5;
  real_T c8_d6;
  real_T c8_d7;
  real_T c8_d8;
  real_T c8_d9;
  real_T c8_d_qa;
  real_T c8_d_qb;
  real_T c8_d_qc;
  real_T c8_d_qd;
  real_T c8_d_x;
  real_T c8_db_x;
  real_T c8_dc_x;
  real_T c8_dd_x;
  real_T c8_ddsq;
  real_T c8_e_x;
  real_T c8_eb_x;
  real_T c8_ec_x;
  real_T c8_ed_x;
  real_T c8_f_x;
  real_T c8_fb_x;
  real_T c8_fc_x;
  real_T c8_fd_x;
  real_T c8_g_x;
  real_T c8_gb_x;
  real_T c8_gc_x;
  real_T c8_gd_x;
  real_T c8_h_x;
  real_T c8_hb_x;
  real_T c8_hc_x;
  real_T c8_hd_x;
  real_T c8_i_x;
  real_T c8_ib_x;
  real_T c8_ic_x;
  real_T c8_id_x;
  real_T c8_j_x;
  real_T c8_jb_x;
  real_T c8_jc_x;
  real_T c8_jd_x;
  real_T c8_k_x;
  real_T c8_kb_x;
  real_T c8_kc_x;
  real_T c8_kd_x;
  real_T c8_l_x;
  real_T c8_lb_x;
  real_T c8_lc_x;
  real_T c8_ld_x;
  real_T c8_m_x;
  real_T c8_mb_x;
  real_T c8_mc_x;
  real_T c8_md_x;
  real_T c8_n_x;
  real_T c8_nb_x;
  real_T c8_nc_x;
  real_T c8_nd_x;
  real_T c8_o_x;
  real_T c8_ob_x;
  real_T c8_oc_x;
  real_T c8_od_x;
  real_T c8_p_x;
  real_T c8_pb_x;
  real_T c8_pc_x;
  real_T c8_pd_x;
  real_T c8_q_x;
  real_T c8_qa;
  real_T c8_qb;
  real_T c8_qb_x;
  real_T c8_qc;
  real_T c8_qc_x;
  real_T c8_qd;
  real_T c8_qd_x;
  real_T c8_r_x;
  real_T c8_rb_x;
  real_T c8_rc_x;
  real_T c8_rd_x;
  real_T c8_s_x;
  real_T c8_sb_x;
  real_T c8_sc_x;
  real_T c8_sd_x;
  real_T c8_t_x;
  real_T c8_ta;
  real_T c8_tb;
  real_T c8_tb_x;
  real_T c8_tc;
  real_T c8_tc_x;
  real_T c8_td;
  real_T c8_td_x;
  real_T c8_u_x;
  real_T c8_ub_x;
  real_T c8_uc_x;
  real_T c8_ud_x;
  real_T c8_v_x;
  real_T c8_vb_x;
  real_T c8_vc_x;
  real_T c8_w_x;
  real_T c8_wb_x;
  real_T c8_wc_x;
  real_T c8_x;
  real_T c8_x_x;
  real_T c8_xb_x;
  real_T c8_xc_x;
  real_T c8_y_x;
  real_T c8_yb_x;
  real_T c8_yc_x;
  int32_T c8_i;
  int32_T c8_i1;
  int32_T c8_i10;
  int32_T c8_i11;
  int32_T c8_i12;
  int32_T c8_i13;
  int32_T c8_i14;
  int32_T c8_i15;
  int32_T c8_i16;
  int32_T c8_i17;
  int32_T c8_i18;
  int32_T c8_i19;
  int32_T c8_i2;
  int32_T c8_i20;
  int32_T c8_i21;
  int32_T c8_i22;
  int32_T c8_i23;
  int32_T c8_i24;
  int32_T c8_i25;
  int32_T c8_i26;
  int32_T c8_i3;
  int32_T c8_i4;
  int32_T c8_i5;
  int32_T c8_i6;
  int32_T c8_i7;
  int32_T c8_i8;
  int32_T c8_i9;
  c8_st.tls = chartInstance->c8_fEmlrtCtx;
  c8_b_st.prev = &c8_st;
  c8_b_st.tls = c8_st.tls;
  c8_c_st.prev = &c8_b_st;
  c8_c_st.tls = c8_b_st.tls;
  chartInstance->c8_JITTransitionAnimation[0] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  for (c8_i = 0; c8_i < 3; c8_i++) {
    covrtSigUpdateFcn(chartInstance->c8_covrtInstance, 2U,
                      (*chartInstance->c8_mag_VNED)[c8_i]);
  }

  for (c8_i1 = 0; c8_i1 < 3; c8_i1++) {
    covrtSigUpdateFcn(chartInstance->c8_covrtInstance, 1U,
                      (*chartInstance->c8_gyro_VNED)[c8_i1]);
  }

  for (c8_i2 = 0; c8_i2 < 3; c8_i2++) {
    covrtSigUpdateFcn(chartInstance->c8_covrtInstance, 0U,
                      (*chartInstance->c8_accel_VNED)[c8_i2]);
  }

  chartInstance->c8_sfEvent = CALL_EVENT;
  c8_b_phi = chartInstance->c8_phi;

  /* logging input variable 'accel_VNED' for function 'eML_blk_kernel' */
  /* logging input variable 'gyro_VNED' for function 'eML_blk_kernel' */
  /* logging input variable 'mag_VNED' for function 'eML_blk_kernel' */
  /* logging input variable 'phi' for function 'eML_blk_kernel' */
  chartInstance->c8_emlrtLocLogSimulated = true;

  /* logging input variable 'accel_VNED' for function 'eML_blk_kernel' */
  for (c8_i3 = 0; c8_i3 < 3; c8_i3++) {
    c8_varargin_1[c8_i3] = (*chartInstance->c8_accel_VNED)[c8_i3];
  }

  c8_b_emlrt_update_log_1(chartInstance, c8_varargin_1,
    chartInstance->c8_emlrtLocationLoggingDataTables, 0);

  /* logging input variable 'gyro_VNED' for function 'eML_blk_kernel' */
  for (c8_i4 = 0; c8_i4 < 3; c8_i4++) {
    c8_varargin_1[c8_i4] = (*chartInstance->c8_gyro_VNED)[c8_i4];
  }

  c8_b_emlrt_update_log_1(chartInstance, c8_varargin_1,
    chartInstance->c8_emlrtLocationLoggingDataTables, 1);

  /* logging input variable 'mag_VNED' for function 'eML_blk_kernel' */
  for (c8_i5 = 0; c8_i5 < 3; c8_i5++) {
    c8_varargin_1[c8_i5] = (*chartInstance->c8_mag_VNED)[c8_i5];
  }

  c8_b_emlrt_update_log_1(chartInstance, c8_varargin_1,
    chartInstance->c8_emlrtLocationLoggingDataTables, 2);

  /* logging input variable 'phi' for function 'eML_blk_kernel' */
  c8_emlrt_update_log_2(chartInstance, c8_b_phi,
                        chartInstance->c8_emlrtLocationLoggingDataTables, 3);
  covrtEmlFcnEval(chartInstance->c8_covrtInstance, 4U, 0, 0);
  for (c8_i6 = 0; c8_i6 < 6; c8_i6++) {
    c8_obj.Value[c8_i6] = c8_cv[c8_i6];
  }

  c8_b_emlrt_update_log_5(chartInstance, &c8_obj,
    chartInstance->c8_emlrtLocationLoggingDataTables, 10);
  for (c8_i7 = 0; c8_i7 < 3; c8_i7++) {
    c8_b_obj.Value[c8_i7] = c8_cv1[c8_i7];
  }

  c8_b_emlrt_update_log_6(chartInstance, &c8_b_obj,
    chartInstance->c8_emlrtLocationLoggingDataTables, 11);
  for (c8_i8 = 0; c8_i8 < 5; c8_i8++) {
    c8_c_obj.Value[c8_i8] = c8_cv2[c8_i8];
  }

  c8_b_emlrt_update_log_7(chartInstance, &c8_c_obj,
    chartInstance->c8_emlrtLocationLoggingDataTables, 12);
  for (c8_i9 = 0; c8_i9 < 5; c8_i9++) {
    c8_c_obj.Value[c8_i9] = c8_cv2[c8_i9];
  }

  c8_b_emlrt_update_log_7(chartInstance, &c8_c_obj,
    chartInstance->c8_emlrtLocationLoggingDataTables, 13);
  c8_d = c8_emlrt_update_log_2(chartInstance, c8_b_phi - 180.0,
    chartInstance->c8_emlrtLocationLoggingDataTables, 9);
  c8_varargin_1[0] = 0.0;
  c8_varargin_1[1] = c8_d;
  c8_varargin_1[2] = 0.0;
  for (c8_i10 = 0; c8_i10 < 3; c8_i10++) {
    c8_varargin_1[c8_i10] *= 0.017453292519943295;
  }

  for (c8_i11 = 0; c8_i11 < 3; c8_i11++) {
    c8_varargin_1[c8_i11] /= 2.0;
  }

  c8_a = c8_varargin_1[0];
  c8_b = c8_varargin_1[1];
  c8_c = c8_varargin_1[2];
  c8_x = c8_a;
  c8_b_x = c8_x;
  c8_b_x = muDoubleScalarCos(c8_b_x);
  c8_c_x = c8_b;
  c8_d_x = c8_c_x;
  c8_d_x = muDoubleScalarCos(c8_d_x);
  c8_e_x = c8_c;
  c8_f_x = c8_e_x;
  c8_f_x = muDoubleScalarCos(c8_f_x);
  c8_g_x = c8_a;
  c8_h_x = c8_g_x;
  c8_h_x = muDoubleScalarSin(c8_h_x);
  c8_i_x = c8_b;
  c8_j_x = c8_i_x;
  c8_j_x = muDoubleScalarSin(c8_j_x);
  c8_k_x = c8_c;
  c8_l_x = c8_k_x;
  c8_l_x = muDoubleScalarSin(c8_l_x);
  c8_qa = c8_b_x * c8_d_x * c8_f_x - c8_h_x * c8_j_x * c8_l_x;
  c8_m_x = c8_b;
  c8_n_x = c8_m_x;
  c8_n_x = muDoubleScalarCos(c8_n_x);
  c8_o_x = c8_c;
  c8_p_x = c8_o_x;
  c8_p_x = muDoubleScalarCos(c8_p_x);
  c8_q_x = c8_a;
  c8_r_x = c8_q_x;
  c8_r_x = muDoubleScalarSin(c8_r_x);
  c8_s_x = c8_a;
  c8_t_x = c8_s_x;
  c8_t_x = muDoubleScalarCos(c8_t_x);
  c8_u_x = c8_b;
  c8_v_x = c8_u_x;
  c8_v_x = muDoubleScalarSin(c8_v_x);
  c8_w_x = c8_c;
  c8_x_x = c8_w_x;
  c8_x_x = muDoubleScalarSin(c8_x_x);
  c8_qb = c8_n_x * c8_p_x * c8_r_x + c8_t_x * c8_v_x * c8_x_x;
  c8_y_x = c8_a;
  c8_ab_x = c8_y_x;
  c8_ab_x = muDoubleScalarCos(c8_ab_x);
  c8_bb_x = c8_c;
  c8_cb_x = c8_bb_x;
  c8_cb_x = muDoubleScalarCos(c8_cb_x);
  c8_db_x = c8_b;
  c8_eb_x = c8_db_x;
  c8_eb_x = muDoubleScalarSin(c8_eb_x);
  c8_fb_x = c8_b;
  c8_gb_x = c8_fb_x;
  c8_gb_x = muDoubleScalarCos(c8_gb_x);
  c8_hb_x = c8_a;
  c8_ib_x = c8_hb_x;
  c8_ib_x = muDoubleScalarSin(c8_ib_x);
  c8_jb_x = c8_c;
  c8_kb_x = c8_jb_x;
  c8_kb_x = muDoubleScalarSin(c8_kb_x);
  c8_qc = c8_ab_x * c8_cb_x * c8_eb_x - c8_gb_x * c8_ib_x * c8_kb_x;
  c8_lb_x = c8_a;
  c8_mb_x = c8_lb_x;
  c8_mb_x = muDoubleScalarCos(c8_mb_x);
  c8_nb_x = c8_b;
  c8_ob_x = c8_nb_x;
  c8_ob_x = muDoubleScalarCos(c8_ob_x);
  c8_pb_x = c8_c;
  c8_qb_x = c8_pb_x;
  c8_qb_x = muDoubleScalarSin(c8_qb_x);
  c8_rb_x = c8_c;
  c8_sb_x = c8_rb_x;
  c8_sb_x = muDoubleScalarCos(c8_sb_x);
  c8_tb_x = c8_a;
  c8_ub_x = c8_tb_x;
  c8_ub_x = muDoubleScalarSin(c8_ub_x);
  c8_vb_x = c8_b;
  c8_wb_x = c8_vb_x;
  c8_wb_x = muDoubleScalarSin(c8_wb_x);
  c8_qd = c8_mb_x * c8_ob_x * c8_qb_x + c8_sb_x * c8_ub_x * c8_wb_x;
  c8_b_qa = c8_qa;
  c8_b_qb = c8_qb;
  c8_b_qc = c8_qc;
  c8_b_qd = c8_qd;
  c8_d1 = c8_b_qa;
  c8_d2 = c8_b_qb;
  c8_d3 = c8_b_qc;
  c8_d4 = c8_b_qd;
  c8_d_obj.a = c8_d1;
  c8_d_obj.b = c8_d2;
  c8_d_obj.c = c8_d3;
  c8_d_obj.d = c8_d4;
  c8_b_st.site = &c8_emlrtRSI;
  c8_b_emlrt_update_log_4(chartInstance, &c8_d_obj,
    chartInstance->c8_emlrtLocationLoggingDataTables, 5);
  c8_c_st.site = &c8_f_emlrtRSI;
  c8_b_quaternionBase_normalize(chartInstance, &c8_c_st, &c8_d_obj);
  c8_ta = c8_d_obj.a;
  c8_tb = c8_d_obj.b;
  c8_tc = c8_d_obj.c;
  c8_td = c8_d_obj.d;
  c8_ab2 = c8_ta * c8_tb * 2.0;
  c8_ac2 = c8_ta * c8_tc * 2.0;
  c8_ad2 = c8_ta * c8_td * 2.0;
  c8_bc2 = c8_tb * c8_tc * 2.0;
  c8_bd2 = c8_tb * c8_td * 2.0;
  c8_cd2 = c8_tc * c8_td * 2.0;
  c8_aasq = c8_ta * c8_ta * 2.0 - 1.0;
  c8_bbsq = c8_tb * c8_tb * 2.0;
  c8_ccsq = c8_tc * c8_tc * 2.0;
  c8_ddsq = c8_td * c8_td * 2.0;
  c8_rmat[0] = c8_aasq + c8_bbsq;
  c8_rmat[3] = c8_bc2 + c8_ad2;
  c8_rmat[6] = c8_bd2 - c8_ac2;
  c8_rmat[1] = c8_bc2 - c8_ad2;
  c8_rmat[4] = c8_aasq + c8_ccsq;
  c8_rmat[7] = c8_cd2 + c8_ab2;
  c8_rmat[2] = c8_bd2 + c8_ac2;
  c8_rmat[5] = c8_cd2 - c8_ab2;
  c8_rmat[8] = c8_aasq + c8_ddsq;
  c8_b_emlrt_update_log_3(chartInstance, c8_rmat,
    chartInstance->c8_emlrtLocationLoggingDataTables, 4);
  for (c8_i12 = 0; c8_i12 < 6; c8_i12++) {
    c8_obj.Value[c8_i12] = c8_cv[c8_i12];
  }

  c8_b_emlrt_update_log_5(chartInstance, &c8_obj,
    chartInstance->c8_emlrtLocationLoggingDataTables, 20);
  for (c8_i13 = 0; c8_i13 < 3; c8_i13++) {
    c8_b_obj.Value[c8_i13] = c8_cv1[c8_i13];
  }

  c8_b_emlrt_update_log_6(chartInstance, &c8_b_obj,
    chartInstance->c8_emlrtLocationLoggingDataTables, 21);
  for (c8_i14 = 0; c8_i14 < 5; c8_i14++) {
    c8_c_obj.Value[c8_i14] = c8_cv2[c8_i14];
  }

  c8_b_emlrt_update_log_7(chartInstance, &c8_c_obj,
    chartInstance->c8_emlrtLocationLoggingDataTables, 22);
  for (c8_i15 = 0; c8_i15 < 5; c8_i15++) {
    c8_c_obj.Value[c8_i15] = c8_cv2[c8_i15];
  }

  c8_b_emlrt_update_log_7(chartInstance, &c8_c_obj,
    chartInstance->c8_emlrtLocationLoggingDataTables, 23);
  c8_d5 = c8_emlrt_update_log_2(chartInstance, 180.0 - c8_b_phi,
    chartInstance->c8_emlrtLocationLoggingDataTables, 19);
  c8_varargin_1[0] = 180.0;
  c8_varargin_1[1] = c8_d5;
  c8_varargin_1[2] = 0.0;
  for (c8_i16 = 0; c8_i16 < 3; c8_i16++) {
    c8_varargin_1[c8_i16] *= 0.017453292519943295;
  }

  for (c8_i17 = 0; c8_i17 < 3; c8_i17++) {
    c8_varargin_1[c8_i17] /= 2.0;
  }

  c8_b_a = c8_varargin_1[0];
  c8_b_b = c8_varargin_1[1];
  c8_b_c = c8_varargin_1[2];
  c8_xb_x = c8_b_a;
  c8_yb_x = c8_xb_x;
  c8_yb_x = muDoubleScalarCos(c8_yb_x);
  c8_ac_x = c8_b_b;
  c8_bc_x = c8_ac_x;
  c8_bc_x = muDoubleScalarCos(c8_bc_x);
  c8_cc_x = c8_b_c;
  c8_dc_x = c8_cc_x;
  c8_dc_x = muDoubleScalarCos(c8_dc_x);
  c8_ec_x = c8_b_a;
  c8_fc_x = c8_ec_x;
  c8_fc_x = muDoubleScalarSin(c8_fc_x);
  c8_gc_x = c8_b_b;
  c8_hc_x = c8_gc_x;
  c8_hc_x = muDoubleScalarSin(c8_hc_x);
  c8_ic_x = c8_b_c;
  c8_jc_x = c8_ic_x;
  c8_jc_x = muDoubleScalarSin(c8_jc_x);
  c8_c_qa = c8_yb_x * c8_bc_x * c8_dc_x - c8_fc_x * c8_hc_x * c8_jc_x;
  c8_kc_x = c8_b_b;
  c8_lc_x = c8_kc_x;
  c8_lc_x = muDoubleScalarCos(c8_lc_x);
  c8_mc_x = c8_b_c;
  c8_nc_x = c8_mc_x;
  c8_nc_x = muDoubleScalarCos(c8_nc_x);
  c8_oc_x = c8_b_a;
  c8_pc_x = c8_oc_x;
  c8_pc_x = muDoubleScalarSin(c8_pc_x);
  c8_qc_x = c8_b_a;
  c8_rc_x = c8_qc_x;
  c8_rc_x = muDoubleScalarCos(c8_rc_x);
  c8_sc_x = c8_b_b;
  c8_tc_x = c8_sc_x;
  c8_tc_x = muDoubleScalarSin(c8_tc_x);
  c8_uc_x = c8_b_c;
  c8_vc_x = c8_uc_x;
  c8_vc_x = muDoubleScalarSin(c8_vc_x);
  c8_c_qb = c8_lc_x * c8_nc_x * c8_pc_x + c8_rc_x * c8_tc_x * c8_vc_x;
  c8_wc_x = c8_b_a;
  c8_xc_x = c8_wc_x;
  c8_xc_x = muDoubleScalarCos(c8_xc_x);
  c8_yc_x = c8_b_c;
  c8_ad_x = c8_yc_x;
  c8_ad_x = muDoubleScalarCos(c8_ad_x);
  c8_bd_x = c8_b_b;
  c8_cd_x = c8_bd_x;
  c8_cd_x = muDoubleScalarSin(c8_cd_x);
  c8_dd_x = c8_b_b;
  c8_ed_x = c8_dd_x;
  c8_ed_x = muDoubleScalarCos(c8_ed_x);
  c8_fd_x = c8_b_a;
  c8_gd_x = c8_fd_x;
  c8_gd_x = muDoubleScalarSin(c8_gd_x);
  c8_hd_x = c8_b_c;
  c8_id_x = c8_hd_x;
  c8_id_x = muDoubleScalarSin(c8_id_x);
  c8_c_qc = c8_xc_x * c8_ad_x * c8_cd_x - c8_ed_x * c8_gd_x * c8_id_x;
  c8_jd_x = c8_b_a;
  c8_kd_x = c8_jd_x;
  c8_kd_x = muDoubleScalarCos(c8_kd_x);
  c8_ld_x = c8_b_b;
  c8_md_x = c8_ld_x;
  c8_md_x = muDoubleScalarCos(c8_md_x);
  c8_nd_x = c8_b_c;
  c8_od_x = c8_nd_x;
  c8_od_x = muDoubleScalarSin(c8_od_x);
  c8_pd_x = c8_b_c;
  c8_qd_x = c8_pd_x;
  c8_qd_x = muDoubleScalarCos(c8_qd_x);
  c8_rd_x = c8_b_a;
  c8_sd_x = c8_rd_x;
  c8_sd_x = muDoubleScalarSin(c8_sd_x);
  c8_td_x = c8_b_b;
  c8_ud_x = c8_td_x;
  c8_ud_x = muDoubleScalarSin(c8_ud_x);
  c8_c_qd = c8_kd_x * c8_md_x * c8_od_x + c8_qd_x * c8_sd_x * c8_ud_x;
  c8_d_qa = c8_c_qa;
  c8_d_qb = c8_c_qb;
  c8_d_qc = c8_c_qc;
  c8_d_qd = c8_c_qd;
  c8_d6 = c8_d_qa;
  c8_d7 = c8_d_qb;
  c8_d8 = c8_d_qc;
  c8_d9 = c8_d_qd;
  c8_d_obj.a = c8_d6;
  c8_d_obj.b = c8_d7;
  c8_d_obj.c = c8_d8;
  c8_d_obj.d = c8_d9;
  c8_b_st.site = &c8_b_emlrtRSI;
  c8_b_emlrt_update_log_4(chartInstance, &c8_d_obj,
    chartInstance->c8_emlrtLocationLoggingDataTables, 15);
  c8_c_st.site = &c8_f_emlrtRSI;
  c8_b_quaternionBase_normalize(chartInstance, &c8_c_st, &c8_d_obj);
  c8_b_ta = c8_d_obj.a;
  c8_b_tb = c8_d_obj.b;
  c8_b_tc = c8_d_obj.c;
  c8_b_td = c8_d_obj.d;
  c8_b_ab2 = c8_b_ta * c8_b_tb * 2.0;
  c8_b_ac2 = c8_b_ta * c8_b_tc * 2.0;
  c8_b_ad2 = c8_b_ta * c8_b_td * 2.0;
  c8_b_bc2 = c8_b_tb * c8_b_tc * 2.0;
  c8_b_bd2 = c8_b_tb * c8_b_td * 2.0;
  c8_b_cd2 = c8_b_tc * c8_b_td * 2.0;
  c8_b_aasq = c8_b_ta * c8_b_ta * 2.0 - 1.0;
  c8_b_bbsq = c8_b_tb * c8_b_tb * 2.0;
  c8_b_ccsq = c8_b_tc * c8_b_tc * 2.0;
  c8_b_ddsq = c8_b_td * c8_b_td * 2.0;
  c8_b_rmat[0] = c8_b_aasq + c8_b_bbsq;
  c8_b_rmat[3] = c8_b_bc2 + c8_b_ad2;
  c8_b_rmat[6] = c8_b_bd2 - c8_b_ac2;
  c8_b_rmat[1] = c8_b_bc2 - c8_b_ad2;
  c8_b_rmat[4] = c8_b_aasq + c8_b_ccsq;
  c8_b_rmat[7] = c8_b_cd2 + c8_b_ab2;
  c8_b_rmat[2] = c8_b_bd2 + c8_b_ac2;
  c8_b_rmat[5] = c8_b_cd2 - c8_b_ab2;
  c8_b_rmat[8] = c8_b_aasq + c8_b_ddsq;
  c8_b_emlrt_update_log_3(chartInstance, c8_b_rmat,
    chartInstance->c8_emlrtLocationLoggingDataTables, 14);
  c8_b_st.site = &c8_c_emlrtRSI;
  for (c8_i18 = 0; c8_i18 < 3; c8_i18++) {
    c8_dv[c8_i18] = (*chartInstance->c8_accel_VNED)[c8_i18];
  }

  c8_mldivide(chartInstance, &c8_b_st, c8_rmat, c8_dv, c8_varargin_1);
  c8_b_emlrt_update_log_8(chartInstance, c8_varargin_1,
    chartInstance->c8_emlrtLocationLoggingDataTables, 25);
  c8_b_emlrt_update_log_1(chartInstance, c8_varargin_1,
    chartInstance->c8_emlrtLocationLoggingDataTables, 24);
  c8_b_st.site = &c8_d_emlrtRSI;
  for (c8_i19 = 0; c8_i19 < 3; c8_i19++) {
    c8_dv1[c8_i19] = (*chartInstance->c8_gyro_VNED)[c8_i19];
  }

  c8_mldivide(chartInstance, &c8_b_st, c8_rmat, c8_dv1, c8_b_gyro_SNED);
  c8_b_emlrt_update_log_8(chartInstance, c8_b_gyro_SNED,
    chartInstance->c8_emlrtLocationLoggingDataTables, 27);
  c8_b_emlrt_update_log_1(chartInstance, c8_b_gyro_SNED,
    chartInstance->c8_emlrtLocationLoggingDataTables, 26);
  c8_b_st.site = &c8_e_emlrtRSI;
  for (c8_i20 = 0; c8_i20 < 3; c8_i20++) {
    c8_dv2[c8_i20] = (*chartInstance->c8_mag_VNED)[c8_i20];
  }

  c8_mldivide(chartInstance, &c8_b_st, c8_b_rmat, c8_dv2, c8_dv3);
  for (c8_i21 = 0; c8_i21 < 3; c8_i21++) {
    (*chartInstance->c8_mag_SNED)[c8_i21] = c8_dv3[c8_i21];
  }

  c8_b_emlrt_update_log_8(chartInstance, *chartInstance->c8_mag_SNED,
    chartInstance->c8_emlrtLocationLoggingDataTables, 29);
  c8_b_emlrt_update_log_1(chartInstance, *chartInstance->c8_mag_SNED,
    chartInstance->c8_emlrtLocationLoggingDataTables, 28);
  for (c8_i22 = 0; c8_i22 < 3; c8_i22++) {
    (*chartInstance->c8_accel_SNED)[c8_i22] = c8_varargin_1[c8_i22];
  }

  for (c8_i23 = 0; c8_i23 < 3; c8_i23++) {
    (*chartInstance->c8_gyro_SNED)[c8_i23] = c8_b_gyro_SNED[c8_i23];
  }

  c8_do_animation_call_c8_car_model_FIXED(chartInstance);
  for (c8_i24 = 0; c8_i24 < 3; c8_i24++) {
    covrtSigUpdateFcn(chartInstance->c8_covrtInstance, 3U,
                      (*chartInstance->c8_accel_SNED)[c8_i24]);
  }

  for (c8_i25 = 0; c8_i25 < 3; c8_i25++) {
    covrtSigUpdateFcn(chartInstance->c8_covrtInstance, 4U,
                      (*chartInstance->c8_gyro_SNED)[c8_i25]);
  }

  for (c8_i26 = 0; c8_i26 < 3; c8_i26++) {
    covrtSigUpdateFcn(chartInstance->c8_covrtInstance, 5U,
                      (*chartInstance->c8_mag_SNED)[c8_i26]);
  }
}

static void ext_mode_exec_c8_car_model_FIXED(SFc8_car_model_FIXEDInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void c8_update_jit_animation_c8_car_model_FIXED
  (SFc8_car_model_FIXEDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c8_do_animation_call_c8_car_model_FIXED
  (SFc8_car_model_FIXEDInstanceStruct *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static const mxArray *get_sim_state_c8_car_model_FIXED
  (SFc8_car_model_FIXEDInstanceStruct *chartInstance)
{
  const mxArray *c8_b_y = NULL;
  const mxArray *c8_c_y = NULL;
  const mxArray *c8_d_y = NULL;
  const mxArray *c8_e_y = NULL;
  const mxArray *c8_st;
  const mxArray *c8_y = NULL;
  c8_st = NULL;
  c8_st = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_createcellmatrix(4, 1), false);
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", *chartInstance->c8_accel_SNED, 0, 0U,
    1U, 0U, 2, 3, 1), false);
  sf_mex_setcell(c8_y, 0, c8_b_y);
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", *chartInstance->c8_gyro_SNED, 0, 0U,
    1U, 0U, 2, 3, 1), false);
  sf_mex_setcell(c8_y, 1, c8_c_y);
  c8_d_y = NULL;
  sf_mex_assign(&c8_d_y, sf_mex_create("y", *chartInstance->c8_mag_SNED, 0, 0U,
    1U, 0U, 2, 3, 1), false);
  sf_mex_setcell(c8_y, 2, c8_d_y);
  c8_e_y = NULL;
  sf_mex_assign(&c8_e_y, sf_mex_create("y",
    &chartInstance->c8_is_active_c8_car_model_FIXED, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 3, c8_e_y);
  sf_mex_assign(&c8_st, c8_y, false);
  return c8_st;
}

static void set_sim_state_c8_car_model_FIXED(SFc8_car_model_FIXEDInstanceStruct *
  chartInstance, const mxArray *c8_st)
{
  const mxArray *c8_u;
  real_T c8_dv[3];
  real_T c8_dv1[3];
  real_T c8_dv2[3];
  int32_T c8_i;
  int32_T c8_i1;
  int32_T c8_i2;
  chartInstance->c8_doneDoubleBufferReInit = true;
  c8_u = sf_mex_dup(c8_st);
  c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 0)),
                      "accel_SNED", c8_dv);
  for (c8_i = 0; c8_i < 3; c8_i++) {
    (*chartInstance->c8_accel_SNED)[c8_i] = c8_dv[c8_i];
  }

  c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 1)),
                      "gyro_SNED", c8_dv1);
  for (c8_i1 = 0; c8_i1 < 3; c8_i1++) {
    (*chartInstance->c8_gyro_SNED)[c8_i1] = c8_dv1[c8_i1];
  }

  c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 2)),
                      "mag_SNED", c8_dv2);
  for (c8_i2 = 0; c8_i2 < 3; c8_i2++) {
    (*chartInstance->c8_mag_SNED)[c8_i2] = c8_dv2[c8_i2];
  }

  chartInstance->c8_is_active_c8_car_model_FIXED = c8_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 3)),
     "is_active_c8_car_model_FIXED");
  sf_mex_destroy(&c8_u);
  sf_mex_destroy(&c8_st);
}

static void initSimStructsc8_car_model_FIXED(SFc8_car_model_FIXEDInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void c8_emlrt_update_log_1(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c8_in[3], emlrtLocationLoggingDataType c8_table[],
  int32_T c8_index, real_T c8_out[3])
{
  int32_T c8_i;
  for (c8_i = 0; c8_i < 3; c8_i++) {
    c8_out[c8_i] = c8_in[c8_i];
  }

  c8_b_emlrt_update_log_1(chartInstance, c8_out, c8_table, c8_index);
}

static real_T c8_emlrt_update_log_2(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c8_in, emlrtLocationLoggingDataType c8_table[], int32_T
  c8_index)
{
  emlrtLocationLoggingDataType *c8_b_table;
  emlrtLocationLoggingHistogramType *c8_histTable;
  real_T c8_inDouble;
  real_T c8_localMax;
  real_T c8_localMin;
  real_T c8_significand;
  int32_T c8_exponent;
  boolean_T c8_isLoggingEnabledHere;
  (void)chartInstance;
  c8_isLoggingEnabledHere = (c8_index >= 0);
  if (c8_isLoggingEnabledHere) {
    c8_b_table = (emlrtLocationLoggingDataType *)&c8_table[c8_index];
    c8_localMin = c8_b_table[0U].SimMin;
    c8_localMax = c8_b_table[0U].SimMax;
    c8_histTable = c8_b_table[0U].HistogramTable;

    /* Simulation Min-Max logging. */
    if (c8_in < c8_localMin) {
      c8_localMin = c8_in;
    }

    if (c8_in > c8_localMax) {
      c8_localMax = c8_in;
    }

    /* Histogram logging. */
    c8_inDouble = c8_in;
    c8_histTable->TotalNumberOfValues++;
    if (c8_inDouble == 0.0) {
      c8_histTable->NumberOfZeros++;
    } else {
      c8_histTable->SimSum += c8_inDouble;
      if ((!muDoubleScalarIsInf(c8_inDouble)) && (!muDoubleScalarIsNaN
           (c8_inDouble))) {
        c8_significand = frexp(c8_inDouble, &c8_exponent);
        if (c8_exponent > 128) {
          c8_exponent = 128;
        }

        if (c8_exponent < -127) {
          c8_exponent = -127;
        }

        if (c8_significand < 0.0) {
          c8_histTable->NumberOfNegativeValues++;
          c8_histTable->HistogramOfNegativeValues[127 + c8_exponent]++;
        } else {
          c8_histTable->NumberOfPositiveValues++;
          c8_histTable->HistogramOfPositiveValues[127 + c8_exponent]++;
        }
      }
    }

    c8_b_table[0U].SimMin = c8_localMin;
    c8_b_table[0U].SimMax = c8_localMax;

    /* IsAlwaysInteger logging. */
    if (c8_in != muDoubleScalarFloor(c8_in)) {
      c8_b_table[0U].IsAlwaysInteger = false;
    }
  }

  return c8_in;
}

static void c8_emlrt_update_log_3(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c8_in[9], emlrtLocationLoggingDataType c8_table[],
  int32_T c8_index, real_T c8_out[9])
{
  int32_T c8_i;
  for (c8_i = 0; c8_i < 9; c8_i++) {
    c8_out[c8_i] = c8_in[c8_i];
  }

  c8_b_emlrt_update_log_3(chartInstance, c8_out, c8_table, c8_index);
}

static c8_quaternion c8_emlrt_update_log_4(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, c8_quaternion c8_in, emlrtLocationLoggingDataType c8_table[],
  int32_T c8_index)
{
  c8_quaternion c8_out;
  c8_out = c8_in;
  c8_b_emlrt_update_log_4(chartInstance, &c8_out, c8_table, c8_index);
  return c8_out;
}

static c8_rtString c8_emlrt_update_log_5(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, c8_rtString c8_in, emlrtLocationLoggingDataType c8_table[],
  int32_T c8_index)
{
  c8_rtString c8_out;
  c8_out = c8_in;
  c8_b_emlrt_update_log_5(chartInstance, &c8_out, c8_table, c8_index);
  return c8_out;
}

static c8_rtString_1 c8_emlrt_update_log_6(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, c8_rtString_1 c8_in, emlrtLocationLoggingDataType c8_table[],
  int32_T c8_index)
{
  c8_rtString_1 c8_out;
  c8_out = c8_in;
  c8_b_emlrt_update_log_6(chartInstance, &c8_out, c8_table, c8_index);
  return c8_out;
}

static c8_rtString_2 c8_emlrt_update_log_7(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, c8_rtString_2 c8_in, emlrtLocationLoggingDataType c8_table[],
  int32_T c8_index)
{
  c8_rtString_2 c8_out;
  c8_out = c8_in;
  c8_b_emlrt_update_log_7(chartInstance, &c8_out, c8_table, c8_index);
  return c8_out;
}

static void c8_emlrt_update_log_8(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c8_in[3], emlrtLocationLoggingDataType c8_table[],
  int32_T c8_index, real_T c8_out[3])
{
  int32_T c8_i;
  for (c8_i = 0; c8_i < 3; c8_i++) {
    c8_out[c8_i] = c8_in[c8_i];
  }

  c8_b_emlrt_update_log_8(chartInstance, c8_out, c8_table, c8_index);
}

static void c8_emlrtInitVarDataTables(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, emlrtLocationLoggingDataType c8_dataTables[30],
  emlrtLocationLoggingHistogramType c8_histTables[30])
{
  int32_T c8_i;
  int32_T c8_iH;
  (void)chartInstance;
  for (c8_i = 0; c8_i < 30; c8_i++) {
    c8_dataTables[c8_i].SimMin = rtInf;
    c8_dataTables[c8_i].SimMax = rtMinusInf;
    c8_dataTables[c8_i].OverflowWraps = 0;
    c8_dataTables[c8_i].Saturations = 0;
    c8_dataTables[c8_i].IsAlwaysInteger = true;
    c8_dataTables[c8_i].HistogramTable = &c8_histTables[c8_i];
    c8_histTables[c8_i].NumberOfZeros = 0.0;
    c8_histTables[c8_i].NumberOfPositiveValues = 0.0;
    c8_histTables[c8_i].NumberOfNegativeValues = 0.0;
    c8_histTables[c8_i].TotalNumberOfValues = 0.0;
    c8_histTables[c8_i].SimSum = 0.0;
    for (c8_iH = 0; c8_iH < 256; c8_iH++) {
      c8_histTables[c8_i].HistogramOfPositiveValues[c8_iH] = 0.0;
      c8_histTables[c8_i].HistogramOfNegativeValues[c8_iH] = 0.0;
    }
  }
}

const mxArray *sf_c8_car_model_FIXED_get_eml_resolved_functions_info(void)
{
  const mxArray *c8_nameCaptureInfo = NULL;
  c8_nameCaptureInfo = NULL;
  sf_mex_assign(&c8_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c8_nameCaptureInfo;
}

static c8_quaternion c8_quaternionBase_normalize
  (SFc8_car_model_FIXEDInstanceStruct *chartInstance, const emlrtStack *c8_sp,
   c8_quaternion c8_q)
{
  c8_quaternion c8_b_q;
  c8_b_q = c8_q;
  c8_b_quaternionBase_normalize(chartInstance, c8_sp, &c8_b_q);
  return c8_b_q;
}

static void c8_mldivide(SFc8_car_model_FIXEDInstanceStruct *chartInstance, const
  emlrtStack *c8_sp, real_T c8_A[9], real_T c8_B[3], real_T c8_Y[3])
{
  emlrtStack c8_b_st;
  emlrtStack c8_c_st;
  emlrtStack c8_d_st;
  emlrtStack c8_e_st;
  emlrtStack c8_st;
  real_T c8_b_A[9];
  real_T c8_a21;
  real_T c8_b_d;
  real_T c8_b_x;
  real_T c8_b_y;
  real_T c8_c_d;
  real_T c8_c_x;
  real_T c8_c_y;
  real_T c8_d;
  real_T c8_d_x;
  real_T c8_d_y;
  real_T c8_e_x;
  real_T c8_e_y;
  real_T c8_f_x;
  real_T c8_g_x;
  real_T c8_h_x;
  real_T c8_i_x;
  real_T c8_j_x;
  real_T c8_k_x;
  real_T c8_l_x;
  real_T c8_m_x;
  real_T c8_maxval;
  real_T c8_n_x;
  real_T c8_o_x;
  real_T c8_p_x;
  real_T c8_q_x;
  real_T c8_r_x;
  real_T c8_s_x;
  real_T c8_t_x;
  real_T c8_x;
  real_T c8_y;
  int32_T c8_i;
  int32_T c8_r1;
  int32_T c8_r2;
  int32_T c8_r3;
  int32_T c8_rtemp;
  c8_st.prev = c8_sp;
  c8_st.tls = c8_sp->tls;
  c8_st.site = &c8_h_emlrtRSI;
  c8_b_st.prev = &c8_st;
  c8_b_st.tls = c8_st.tls;
  c8_c_st.prev = &c8_b_st;
  c8_c_st.tls = c8_b_st.tls;
  c8_d_st.prev = &c8_c_st;
  c8_d_st.tls = c8_c_st.tls;
  c8_e_st.prev = &c8_d_st;
  c8_e_st.tls = c8_d_st.tls;
  c8_b_st.site = &c8_i_emlrtRSI;
  c8_c_st.site = &c8_j_emlrtRSI;
  for (c8_i = 0; c8_i < 9; c8_i++) {
    c8_b_A[c8_i] = c8_A[c8_i];
  }

  c8_r1 = 0;
  c8_r2 = 1;
  c8_r3 = 2;
  c8_x = c8_b_A[0];
  c8_b_x = c8_x;
  c8_c_x = c8_b_x;
  c8_d_x = c8_c_x;
  c8_y = muDoubleScalarAbs(c8_d_x);
  c8_maxval = c8_y;
  c8_e_x = c8_b_A[1];
  c8_f_x = c8_e_x;
  c8_g_x = c8_f_x;
  c8_h_x = c8_g_x;
  c8_b_y = muDoubleScalarAbs(c8_h_x);
  c8_a21 = c8_b_y;
  if (c8_a21 > c8_maxval) {
    c8_maxval = c8_a21;
    c8_r1 = 1;
    c8_r2 = 0;
  }

  c8_i_x = c8_b_A[2];
  c8_j_x = c8_i_x;
  c8_k_x = c8_j_x;
  c8_l_x = c8_k_x;
  c8_c_y = muDoubleScalarAbs(c8_l_x);
  c8_d = c8_c_y;
  if (c8_d > c8_maxval) {
    c8_r1 = 2;
    c8_r2 = 1;
    c8_r3 = 0;
  }

  c8_b_A[c8_r2] /= c8_b_A[c8_r1];
  c8_b_A[c8_r3] /= c8_b_A[c8_r1];
  c8_b_A[3 + c8_r2] -= c8_b_A[c8_r2] * c8_b_A[3 + c8_r1];
  c8_b_A[3 + c8_r3] -= c8_b_A[c8_r3] * c8_b_A[3 + c8_r1];
  c8_b_A[6 + c8_r2] -= c8_b_A[c8_r2] * c8_b_A[6 + c8_r1];
  c8_b_A[6 + c8_r3] -= c8_b_A[c8_r3] * c8_b_A[6 + c8_r1];
  c8_m_x = c8_b_A[3 + c8_r3];
  c8_n_x = c8_m_x;
  c8_o_x = c8_n_x;
  c8_p_x = c8_o_x;
  c8_d_y = muDoubleScalarAbs(c8_p_x);
  c8_b_d = c8_d_y;
  c8_q_x = c8_b_A[3 + c8_r2];
  c8_r_x = c8_q_x;
  c8_s_x = c8_r_x;
  c8_t_x = c8_s_x;
  c8_e_y = muDoubleScalarAbs(c8_t_x);
  c8_c_d = c8_e_y;
  if (c8_b_d > c8_c_d) {
    c8_rtemp = c8_r2 + 1;
    c8_r2 = c8_r3;
    c8_r3 = c8_rtemp - 1;
  }

  c8_b_A[3 + c8_r3] /= c8_b_A[3 + c8_r2];
  c8_b_A[6 + c8_r3] -= c8_b_A[3 + c8_r3] * c8_b_A[6 + c8_r2];
  if ((c8_b_A[c8_r1] == 0.0) || (c8_b_A[3 + c8_r2] == 0.0) || (c8_b_A[6 + c8_r3]
       == 0.0)) {
    c8_d_st.site = &c8_k_emlrtRSI;
    c8_e_st.site = &c8_l_emlrtRSI;
    c8_warning(chartInstance, &c8_e_st);
  }

  c8_Y[0] = c8_B[c8_r1];
  c8_Y[1] = c8_B[c8_r2] - c8_Y[0] * c8_b_A[c8_r2];
  c8_Y[2] = (c8_B[c8_r3] - c8_Y[0] * c8_b_A[c8_r3]) - c8_Y[1] * c8_b_A[3 + c8_r3];
  c8_Y[2] /= c8_b_A[6 + c8_r3];
  c8_Y[0] -= c8_Y[2] * c8_b_A[6 + c8_r1];
  c8_Y[1] -= c8_Y[2] * c8_b_A[6 + c8_r2];
  c8_Y[1] /= c8_b_A[3 + c8_r2];
  c8_Y[0] -= c8_Y[1] * c8_b_A[3 + c8_r1];
  c8_Y[0] /= c8_b_A[c8_r1];
}

static void c8_warning(SFc8_car_model_FIXEDInstanceStruct *chartInstance, const
  emlrtStack *c8_sp)
{
  static char_T c8_msgID[21] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'i',
    'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a', 't', 'r', 'i', 'x' };

  static char_T c8_cv[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  static char_T c8_cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  emlrtStack c8_st;
  const mxArray *c8_b_y = NULL;
  const mxArray *c8_c_y = NULL;
  const mxArray *c8_y = NULL;
  c8_st.prev = c8_sp;
  c8_st.tls = c8_sp->tls;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_cv, 10, 0U, 1U, 0U, 2, 1, 7), false);
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_cv1, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", c8_msgID, 10, 0U, 1U, 0U, 2, 1, 21),
                false);
  c8_st.site = &c8_m_emlrtRSI;
  c8_b_feval(chartInstance, &c8_st, c8_y, c8_feval(chartInstance, &c8_st, c8_b_y,
              c8_c_y));
}

static void c8_emlrt_marshallIn(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c8_b_accel_SNED, const char_T *c8_identifier,
  real_T c8_y[3])
{
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = (const char_T *)c8_identifier;
  c8_thisId.fParent = NULL;
  c8_thisId.bParentIsCell = false;
  c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_accel_SNED), &c8_thisId,
                        c8_y);
  sf_mex_destroy(&c8_b_accel_SNED);
}

static void c8_b_emlrt_marshallIn(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  real_T c8_y[3])
{
  real_T c8_dv[3];
  int32_T c8_i;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), c8_dv, 1, 0, 0U, 1, 0U, 2, 3, 1);
  for (c8_i = 0; c8_i < 3; c8_i++) {
    c8_y[c8_i] = c8_dv[c8_i];
  }

  sf_mex_destroy(&c8_u);
}

static uint8_T c8_c_emlrt_marshallIn(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c8_b_is_active_c8_car_model_FIXED, const char_T
  *c8_identifier)
{
  emlrtMsgIdentifier c8_thisId;
  uint8_T c8_y;
  c8_thisId.fIdentifier = (const char_T *)c8_identifier;
  c8_thisId.fParent = NULL;
  c8_thisId.bParentIsCell = false;
  c8_y = c8_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_b_is_active_c8_car_model_FIXED), &c8_thisId);
  sf_mex_destroy(&c8_b_is_active_c8_car_model_FIXED);
  return c8_y;
}

static uint8_T c8_d_emlrt_marshallIn(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  uint8_T c8_b_u;
  uint8_T c8_y;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_b_u, 1, 3, 0U, 0, 0U, 0);
  c8_y = c8_b_u;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_slStringInitializeDynamicBuffers
  (SFc8_car_model_FIXEDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c8_chart_data_browse_helper(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, int32_T c8_ssIdNumber, const mxArray **c8_mxData, uint8_T
  *c8_isValueTooBig)
{
  *c8_mxData = NULL;
  *c8_mxData = NULL;
  *c8_isValueTooBig = 0U;
  switch (c8_ssIdNumber) {
   case 5U:
    sf_mex_assign(c8_mxData, sf_mex_create("mxData",
      *chartInstance->c8_accel_SNED, 0, 0U, 1U, 0U, 2, 3, 1), false);
    break;

   case 8U:
    sf_mex_assign(c8_mxData, sf_mex_create("mxData",
      *chartInstance->c8_gyro_SNED, 0, 0U, 1U, 0U, 2, 3, 1), false);
    break;

   case 4U:
    sf_mex_assign(c8_mxData, sf_mex_create("mxData",
      *chartInstance->c8_accel_VNED, 0, 0U, 1U, 0U, 2, 3, 1), false);
    break;

   case 6U:
    sf_mex_assign(c8_mxData, sf_mex_create("mxData",
      *chartInstance->c8_gyro_VNED, 0, 0U, 1U, 0U, 2, 3, 1), false);
    break;

   case 7U:
    sf_mex_assign(c8_mxData, sf_mex_create("mxData", *chartInstance->c8_mag_VNED,
      0, 0U, 1U, 0U, 2, 3, 1), false);
    break;

   case 9U:
    sf_mex_assign(c8_mxData, sf_mex_create("mxData", *chartInstance->c8_mag_SNED,
      0, 0U, 1U, 0U, 2, 3, 1), false);
    break;

   case 11U:
    sf_mex_assign(c8_mxData, sf_mex_create("mxData", &chartInstance->c8_phi, 0,
      0U, 0U, 0U, 0), false);
    break;
  }
}

static const mxArray *c8_feval(SFc8_car_model_FIXEDInstanceStruct *chartInstance,
  const emlrtStack *c8_sp, const mxArray *c8_input0, const mxArray *c8_input1)
{
  const mxArray *c8_m = NULL;
  (void)chartInstance;
  c8_m = NULL;
  sf_mex_assign(&c8_m, sf_mex_call(c8_sp, NULL, "feval", 1U, 2U, 14, sf_mex_dup
    (c8_input0), 14, sf_mex_dup(c8_input1)), false);
  sf_mex_destroy(&c8_input0);
  sf_mex_destroy(&c8_input1);
  return c8_m;
}

static void c8_b_feval(SFc8_car_model_FIXEDInstanceStruct *chartInstance, const
  emlrtStack *c8_sp, const mxArray *c8_input0, const mxArray *c8_input1)
{
  (void)chartInstance;
  sf_mex_call(c8_sp, NULL, "feval", 0U, 2U, 14, sf_mex_dup(c8_input0), 14,
              sf_mex_dup(c8_input1));
  sf_mex_destroy(&c8_input0);
  sf_mex_destroy(&c8_input1);
}

static void c8_b_emlrt_update_log_1(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c8_in[3], emlrtLocationLoggingDataType c8_table[],
  int32_T c8_index)
{
  emlrtLocationLoggingDataType *c8_b_table;
  emlrtLocationLoggingHistogramType *c8_histTable;
  real_T c8_inDouble;
  real_T c8_localMax;
  real_T c8_localMin;
  real_T c8_significand;
  int32_T c8_b_i;
  int32_T c8_exponent;
  int32_T c8_i;
  boolean_T c8_isLoggingEnabledHere;
  (void)chartInstance;
  c8_isLoggingEnabledHere = (c8_index >= 0);
  if (c8_isLoggingEnabledHere) {
    c8_b_table = (emlrtLocationLoggingDataType *)&c8_table[c8_index];
    c8_localMin = c8_b_table[0U].SimMin;
    c8_localMax = c8_b_table[0U].SimMax;
    c8_histTable = c8_b_table[0U].HistogramTable;
    for (c8_i = 0; c8_i < 3; c8_i++) {
      /* Simulation Min-Max logging. */
      if (c8_in[c8_i] < c8_localMin) {
        c8_localMin = c8_in[c8_i];
      }

      if (c8_in[c8_i] > c8_localMax) {
        c8_localMax = c8_in[c8_i];
      }

      /* Histogram logging. */
      c8_inDouble = c8_in[c8_i];
      c8_histTable->TotalNumberOfValues++;
      if (c8_inDouble == 0.0) {
        c8_histTable->NumberOfZeros++;
      } else {
        c8_histTable->SimSum += c8_inDouble;
        if ((!muDoubleScalarIsInf(c8_inDouble)) && (!muDoubleScalarIsNaN
             (c8_inDouble))) {
          c8_significand = frexp(c8_inDouble, &c8_exponent);
          if (c8_exponent > 128) {
            c8_exponent = 128;
          }

          if (c8_exponent < -127) {
            c8_exponent = -127;
          }

          if (c8_significand < 0.0) {
            c8_histTable->NumberOfNegativeValues++;
            c8_histTable->HistogramOfNegativeValues[127 + c8_exponent]++;
          } else {
            c8_histTable->NumberOfPositiveValues++;
            c8_histTable->HistogramOfPositiveValues[127 + c8_exponent]++;
          }
        }
      }
    }

    c8_b_table[0U].SimMin = c8_localMin;
    c8_b_table[0U].SimMax = c8_localMax;

    /* IsAlwaysInteger logging. */
    c8_b_i = 0;
    while (c8_b_table[0U].IsAlwaysInteger && (c8_b_i < 3)) {
      if (c8_in[c8_b_i] != muDoubleScalarFloor(c8_in[c8_b_i])) {
        c8_b_table[0U].IsAlwaysInteger = false;
      }

      c8_b_i++;
    }
  }
}

static void c8_b_emlrt_update_log_3(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c8_in[9], emlrtLocationLoggingDataType c8_table[],
  int32_T c8_index)
{
  emlrtLocationLoggingDataType *c8_b_table;
  emlrtLocationLoggingHistogramType *c8_histTable;
  real_T c8_inDouble;
  real_T c8_localMax;
  real_T c8_localMin;
  real_T c8_significand;
  int32_T c8_b_i;
  int32_T c8_exponent;
  int32_T c8_i;
  boolean_T c8_isLoggingEnabledHere;
  (void)chartInstance;
  c8_isLoggingEnabledHere = (c8_index >= 0);
  if (c8_isLoggingEnabledHere) {
    c8_b_table = (emlrtLocationLoggingDataType *)&c8_table[c8_index];
    c8_localMin = c8_b_table[0U].SimMin;
    c8_localMax = c8_b_table[0U].SimMax;
    c8_histTable = c8_b_table[0U].HistogramTable;
    for (c8_i = 0; c8_i < 9; c8_i++) {
      /* Simulation Min-Max logging. */
      if (c8_in[c8_i] < c8_localMin) {
        c8_localMin = c8_in[c8_i];
      }

      if (c8_in[c8_i] > c8_localMax) {
        c8_localMax = c8_in[c8_i];
      }

      /* Histogram logging. */
      c8_inDouble = c8_in[c8_i];
      c8_histTable->TotalNumberOfValues++;
      if (c8_inDouble == 0.0) {
        c8_histTable->NumberOfZeros++;
      } else {
        c8_histTable->SimSum += c8_inDouble;
        if ((!muDoubleScalarIsInf(c8_inDouble)) && (!muDoubleScalarIsNaN
             (c8_inDouble))) {
          c8_significand = frexp(c8_inDouble, &c8_exponent);
          if (c8_exponent > 128) {
            c8_exponent = 128;
          }

          if (c8_exponent < -127) {
            c8_exponent = -127;
          }

          if (c8_significand < 0.0) {
            c8_histTable->NumberOfNegativeValues++;
            c8_histTable->HistogramOfNegativeValues[127 + c8_exponent]++;
          } else {
            c8_histTable->NumberOfPositiveValues++;
            c8_histTable->HistogramOfPositiveValues[127 + c8_exponent]++;
          }
        }
      }
    }

    c8_b_table[0U].SimMin = c8_localMin;
    c8_b_table[0U].SimMax = c8_localMax;

    /* IsAlwaysInteger logging. */
    c8_b_i = 0;
    while (c8_b_table[0U].IsAlwaysInteger && (c8_b_i < 9)) {
      if (c8_in[c8_b_i] != muDoubleScalarFloor(c8_in[c8_b_i])) {
        c8_b_table[0U].IsAlwaysInteger = false;
      }

      c8_b_i++;
    }
  }
}

static void c8_b_emlrt_update_log_4(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, c8_quaternion *c8_in, emlrtLocationLoggingDataType c8_table[],
  int32_T c8_index)
{
  emlrtLocationLoggingDataType *c8_b_table;
  emlrtLocationLoggingHistogramType *c8_b_histTable;
  emlrtLocationLoggingHistogramType *c8_c_histTable;
  emlrtLocationLoggingHistogramType *c8_d_histTable;
  emlrtLocationLoggingHistogramType *c8_histTable;
  real_T c8_b_inDouble;
  real_T c8_b_localMax;
  real_T c8_b_localMin;
  real_T c8_b_significand;
  real_T c8_c_inDouble;
  real_T c8_c_localMax;
  real_T c8_c_localMin;
  real_T c8_c_significand;
  real_T c8_d_inDouble;
  real_T c8_d_localMax;
  real_T c8_d_localMin;
  real_T c8_d_significand;
  real_T c8_inDouble;
  real_T c8_localMax;
  real_T c8_localMin;
  real_T c8_significand;
  int32_T c8_b_exponent;
  int32_T c8_c_exponent;
  int32_T c8_d_exponent;
  int32_T c8_exponent;
  boolean_T c8_isLoggingEnabledHere;
  (void)chartInstance;
  c8_isLoggingEnabledHere = (c8_index >= 0);
  if (c8_isLoggingEnabledHere) {
    c8_b_table = (emlrtLocationLoggingDataType *)&c8_table[c8_index];
    c8_localMin = c8_b_table[0U].SimMin;
    c8_localMax = c8_b_table[0U].SimMax;
    c8_histTable = c8_b_table[0U].HistogramTable;

    /* Simulation Min-Max logging. */
    if (c8_in->a < c8_localMin) {
      c8_localMin = c8_in->a;
    }

    if (c8_in->a > c8_localMax) {
      c8_localMax = c8_in->a;
    }

    /* Histogram logging. */
    c8_inDouble = c8_in->a;
    c8_histTable->TotalNumberOfValues++;
    if (c8_inDouble == 0.0) {
      c8_histTable->NumberOfZeros++;
    } else {
      c8_histTable->SimSum += c8_inDouble;
      if ((!muDoubleScalarIsInf(c8_inDouble)) && (!muDoubleScalarIsNaN
           (c8_inDouble))) {
        c8_significand = frexp(c8_inDouble, &c8_exponent);
        if (c8_exponent > 128) {
          c8_exponent = 128;
        }

        if (c8_exponent < -127) {
          c8_exponent = -127;
        }

        if (c8_significand < 0.0) {
          c8_histTable->NumberOfNegativeValues++;
          c8_histTable->HistogramOfNegativeValues[127 + c8_exponent]++;
        } else {
          c8_histTable->NumberOfPositiveValues++;
          c8_histTable->HistogramOfPositiveValues[127 + c8_exponent]++;
        }
      }
    }

    c8_b_table[0U].SimMin = c8_localMin;
    c8_b_table[0U].SimMax = c8_localMax;

    /* IsAlwaysInteger logging. */
    if (c8_in->a != muDoubleScalarFloor(c8_in->a)) {
      c8_b_table[0U].IsAlwaysInteger = false;
    }

    c8_b_localMin = c8_b_table[1U].SimMin;
    c8_b_localMax = c8_b_table[1U].SimMax;
    c8_b_histTable = c8_b_table[1U].HistogramTable;

    /* Simulation Min-Max logging. */
    if (c8_in->b < c8_b_localMin) {
      c8_b_localMin = c8_in->b;
    }

    if (c8_in->b > c8_b_localMax) {
      c8_b_localMax = c8_in->b;
    }

    /* Histogram logging. */
    c8_b_inDouble = c8_in->b;
    c8_b_histTable->TotalNumberOfValues++;
    if (c8_b_inDouble == 0.0) {
      c8_b_histTable->NumberOfZeros++;
    } else {
      c8_b_histTable->SimSum += c8_b_inDouble;
      if ((!muDoubleScalarIsInf(c8_b_inDouble)) && (!muDoubleScalarIsNaN
           (c8_b_inDouble))) {
        c8_b_significand = frexp(c8_b_inDouble, &c8_b_exponent);
        if (c8_b_exponent > 128) {
          c8_b_exponent = 128;
        }

        if (c8_b_exponent < -127) {
          c8_b_exponent = -127;
        }

        if (c8_b_significand < 0.0) {
          c8_b_histTable->NumberOfNegativeValues++;
          c8_b_histTable->HistogramOfNegativeValues[127 + c8_b_exponent]++;
        } else {
          c8_b_histTable->NumberOfPositiveValues++;
          c8_b_histTable->HistogramOfPositiveValues[127 + c8_b_exponent]++;
        }
      }
    }

    c8_b_table[1U].SimMin = c8_b_localMin;
    c8_b_table[1U].SimMax = c8_b_localMax;

    /* IsAlwaysInteger logging. */
    if (c8_in->b != muDoubleScalarFloor(c8_in->b)) {
      c8_b_table[1U].IsAlwaysInteger = false;
    }

    c8_c_localMin = c8_b_table[2U].SimMin;
    c8_c_localMax = c8_b_table[2U].SimMax;
    c8_c_histTable = c8_b_table[2U].HistogramTable;

    /* Simulation Min-Max logging. */
    if (c8_in->c < c8_c_localMin) {
      c8_c_localMin = c8_in->c;
    }

    if (c8_in->c > c8_c_localMax) {
      c8_c_localMax = c8_in->c;
    }

    /* Histogram logging. */
    c8_c_inDouble = c8_in->c;
    c8_c_histTable->TotalNumberOfValues++;
    if (c8_c_inDouble == 0.0) {
      c8_c_histTable->NumberOfZeros++;
    } else {
      c8_c_histTable->SimSum += c8_c_inDouble;
      if ((!muDoubleScalarIsInf(c8_c_inDouble)) && (!muDoubleScalarIsNaN
           (c8_c_inDouble))) {
        c8_c_significand = frexp(c8_c_inDouble, &c8_c_exponent);
        if (c8_c_exponent > 128) {
          c8_c_exponent = 128;
        }

        if (c8_c_exponent < -127) {
          c8_c_exponent = -127;
        }

        if (c8_c_significand < 0.0) {
          c8_c_histTable->NumberOfNegativeValues++;
          c8_c_histTable->HistogramOfNegativeValues[127 + c8_c_exponent]++;
        } else {
          c8_c_histTable->NumberOfPositiveValues++;
          c8_c_histTable->HistogramOfPositiveValues[127 + c8_c_exponent]++;
        }
      }
    }

    c8_b_table[2U].SimMin = c8_c_localMin;
    c8_b_table[2U].SimMax = c8_c_localMax;

    /* IsAlwaysInteger logging. */
    if (c8_in->c != muDoubleScalarFloor(c8_in->c)) {
      c8_b_table[2U].IsAlwaysInteger = false;
    }

    c8_d_localMin = c8_b_table[3U].SimMin;
    c8_d_localMax = c8_b_table[3U].SimMax;
    c8_d_histTable = c8_b_table[3U].HistogramTable;

    /* Simulation Min-Max logging. */
    if (c8_in->d < c8_d_localMin) {
      c8_d_localMin = c8_in->d;
    }

    if (c8_in->d > c8_d_localMax) {
      c8_d_localMax = c8_in->d;
    }

    /* Histogram logging. */
    c8_d_inDouble = c8_in->d;
    c8_d_histTable->TotalNumberOfValues++;
    if (c8_d_inDouble == 0.0) {
      c8_d_histTable->NumberOfZeros++;
    } else {
      c8_d_histTable->SimSum += c8_d_inDouble;
      if ((!muDoubleScalarIsInf(c8_d_inDouble)) && (!muDoubleScalarIsNaN
           (c8_d_inDouble))) {
        c8_d_significand = frexp(c8_d_inDouble, &c8_d_exponent);
        if (c8_d_exponent > 128) {
          c8_d_exponent = 128;
        }

        if (c8_d_exponent < -127) {
          c8_d_exponent = -127;
        }

        if (c8_d_significand < 0.0) {
          c8_d_histTable->NumberOfNegativeValues++;
          c8_d_histTable->HistogramOfNegativeValues[127 + c8_d_exponent]++;
        } else {
          c8_d_histTable->NumberOfPositiveValues++;
          c8_d_histTable->HistogramOfPositiveValues[127 + c8_d_exponent]++;
        }
      }
    }

    c8_b_table[3U].SimMin = c8_d_localMin;
    c8_b_table[3U].SimMax = c8_d_localMax;

    /* IsAlwaysInteger logging. */
    if (c8_in->d != muDoubleScalarFloor(c8_in->d)) {
      c8_b_table[3U].IsAlwaysInteger = false;
    }
  }
}

static void c8_b_emlrt_update_log_5(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, c8_rtString *c8_in, emlrtLocationLoggingDataType c8_table[],
  int32_T c8_index)
{
  emlrtLocationLoggingDataType *c8_b_table;
  emlrtLocationLoggingHistogramType *c8_histTable;
  real_T c8_d;
  real_T c8_d1;
  real_T c8_inDouble;
  real_T c8_significand;
  int32_T c8_exponent;
  int32_T c8_i;
  int32_T c8_i1;
  int32_T c8_localMax;
  int32_T c8_localMin;
  boolean_T c8_isLoggingEnabledHere;
  (void)chartInstance;
  c8_isLoggingEnabledHere = (c8_index >= 0);
  if (c8_isLoggingEnabledHere) {
    c8_b_table = (emlrtLocationLoggingDataType *)&c8_table[c8_index];
    c8_d = muDoubleScalarFloor(c8_b_table[0U].SimMin);
    if (c8_d < 2.147483648E+9) {
      if (c8_d >= -2.147483648E+9) {
        c8_i = (int32_T)c8_d;
      } else {
        c8_i = MIN_int32_T;
      }
    } else if (c8_d >= 2.147483648E+9) {
      c8_i = MAX_int32_T;
    } else {
      c8_i = 0;
    }

    c8_localMin = c8_i;
    c8_d1 = muDoubleScalarFloor(c8_b_table[0U].SimMax);
    if (c8_d1 < 2.147483648E+9) {
      if (c8_d1 >= -2.147483648E+9) {
        c8_i1 = (int32_T)c8_d1;
      } else {
        c8_i1 = MIN_int32_T;
      }
    } else if (c8_d1 >= 2.147483648E+9) {
      c8_i1 = MAX_int32_T;
    } else {
      c8_i1 = 0;
    }

    c8_localMax = c8_i1;
    c8_histTable = c8_b_table[0U].HistogramTable;

    /* Simulation Min-Max logging. */
    if (c8_in->__$isSimulinkString.__dummy < c8_localMin) {
      c8_localMin = c8_in->__$isSimulinkString.__dummy;
    }

    if (c8_in->__$isSimulinkString.__dummy > c8_localMax) {
      c8_localMax = c8_in->__$isSimulinkString.__dummy;
    }

    /* Histogram logging. */
    c8_inDouble = (real_T)c8_in->__$isSimulinkString.__dummy;
    c8_histTable->TotalNumberOfValues++;
    if (c8_inDouble == 0.0) {
      c8_histTable->NumberOfZeros++;
    } else {
      c8_histTable->SimSum += c8_inDouble;
      if ((!muDoubleScalarIsInf(c8_inDouble)) && (!muDoubleScalarIsNaN
           (c8_inDouble))) {
        c8_significand = frexp(c8_inDouble, &c8_exponent);
        if (c8_exponent > 128) {
          c8_exponent = 128;
        }

        if (c8_exponent < -127) {
          c8_exponent = -127;
        }

        if (c8_significand < 0.0) {
          c8_histTable->NumberOfNegativeValues++;
          c8_histTable->HistogramOfNegativeValues[127 + c8_exponent]++;
        } else {
          c8_histTable->NumberOfPositiveValues++;
          c8_histTable->HistogramOfPositiveValues[127 + c8_exponent]++;
        }
      }
    }

    c8_b_table[0U].SimMin = (real_T)c8_localMin;
    c8_b_table[0U].SimMax = (real_T)c8_localMax;

    /* IsAlwaysInteger logging. */
    /* Data type is always integer. */
  }
}

static void c8_b_emlrt_update_log_6(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, c8_rtString_1 *c8_in, emlrtLocationLoggingDataType c8_table[],
  int32_T c8_index)
{
  emlrtLocationLoggingDataType *c8_b_table;
  emlrtLocationLoggingHistogramType *c8_histTable;
  real_T c8_d;
  real_T c8_d1;
  real_T c8_inDouble;
  real_T c8_significand;
  int32_T c8_exponent;
  int32_T c8_i;
  int32_T c8_i1;
  int32_T c8_localMax;
  int32_T c8_localMin;
  boolean_T c8_isLoggingEnabledHere;
  (void)chartInstance;
  c8_isLoggingEnabledHere = (c8_index >= 0);
  if (c8_isLoggingEnabledHere) {
    c8_b_table = (emlrtLocationLoggingDataType *)&c8_table[c8_index];
    c8_d = muDoubleScalarFloor(c8_b_table[0U].SimMin);
    if (c8_d < 2.147483648E+9) {
      if (c8_d >= -2.147483648E+9) {
        c8_i = (int32_T)c8_d;
      } else {
        c8_i = MIN_int32_T;
      }
    } else if (c8_d >= 2.147483648E+9) {
      c8_i = MAX_int32_T;
    } else {
      c8_i = 0;
    }

    c8_localMin = c8_i;
    c8_d1 = muDoubleScalarFloor(c8_b_table[0U].SimMax);
    if (c8_d1 < 2.147483648E+9) {
      if (c8_d1 >= -2.147483648E+9) {
        c8_i1 = (int32_T)c8_d1;
      } else {
        c8_i1 = MIN_int32_T;
      }
    } else if (c8_d1 >= 2.147483648E+9) {
      c8_i1 = MAX_int32_T;
    } else {
      c8_i1 = 0;
    }

    c8_localMax = c8_i1;
    c8_histTable = c8_b_table[0U].HistogramTable;

    /* Simulation Min-Max logging. */
    if (c8_in->__$isSimulinkString.__dummy < c8_localMin) {
      c8_localMin = c8_in->__$isSimulinkString.__dummy;
    }

    if (c8_in->__$isSimulinkString.__dummy > c8_localMax) {
      c8_localMax = c8_in->__$isSimulinkString.__dummy;
    }

    /* Histogram logging. */
    c8_inDouble = (real_T)c8_in->__$isSimulinkString.__dummy;
    c8_histTable->TotalNumberOfValues++;
    if (c8_inDouble == 0.0) {
      c8_histTable->NumberOfZeros++;
    } else {
      c8_histTable->SimSum += c8_inDouble;
      if ((!muDoubleScalarIsInf(c8_inDouble)) && (!muDoubleScalarIsNaN
           (c8_inDouble))) {
        c8_significand = frexp(c8_inDouble, &c8_exponent);
        if (c8_exponent > 128) {
          c8_exponent = 128;
        }

        if (c8_exponent < -127) {
          c8_exponent = -127;
        }

        if (c8_significand < 0.0) {
          c8_histTable->NumberOfNegativeValues++;
          c8_histTable->HistogramOfNegativeValues[127 + c8_exponent]++;
        } else {
          c8_histTable->NumberOfPositiveValues++;
          c8_histTable->HistogramOfPositiveValues[127 + c8_exponent]++;
        }
      }
    }

    c8_b_table[0U].SimMin = (real_T)c8_localMin;
    c8_b_table[0U].SimMax = (real_T)c8_localMax;

    /* IsAlwaysInteger logging. */
    /* Data type is always integer. */
  }
}

static void c8_b_emlrt_update_log_7(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, c8_rtString_2 *c8_in, emlrtLocationLoggingDataType c8_table[],
  int32_T c8_index)
{
  emlrtLocationLoggingDataType *c8_b_table;
  emlrtLocationLoggingHistogramType *c8_histTable;
  real_T c8_d;
  real_T c8_d1;
  real_T c8_inDouble;
  real_T c8_significand;
  int32_T c8_exponent;
  int32_T c8_i;
  int32_T c8_i1;
  int32_T c8_localMax;
  int32_T c8_localMin;
  boolean_T c8_isLoggingEnabledHere;
  (void)chartInstance;
  c8_isLoggingEnabledHere = (c8_index >= 0);
  if (c8_isLoggingEnabledHere) {
    c8_b_table = (emlrtLocationLoggingDataType *)&c8_table[c8_index];
    c8_d = muDoubleScalarFloor(c8_b_table[0U].SimMin);
    if (c8_d < 2.147483648E+9) {
      if (c8_d >= -2.147483648E+9) {
        c8_i = (int32_T)c8_d;
      } else {
        c8_i = MIN_int32_T;
      }
    } else if (c8_d >= 2.147483648E+9) {
      c8_i = MAX_int32_T;
    } else {
      c8_i = 0;
    }

    c8_localMin = c8_i;
    c8_d1 = muDoubleScalarFloor(c8_b_table[0U].SimMax);
    if (c8_d1 < 2.147483648E+9) {
      if (c8_d1 >= -2.147483648E+9) {
        c8_i1 = (int32_T)c8_d1;
      } else {
        c8_i1 = MIN_int32_T;
      }
    } else if (c8_d1 >= 2.147483648E+9) {
      c8_i1 = MAX_int32_T;
    } else {
      c8_i1 = 0;
    }

    c8_localMax = c8_i1;
    c8_histTable = c8_b_table[0U].HistogramTable;

    /* Simulation Min-Max logging. */
    if (c8_in->__$isSimulinkString.__dummy < c8_localMin) {
      c8_localMin = c8_in->__$isSimulinkString.__dummy;
    }

    if (c8_in->__$isSimulinkString.__dummy > c8_localMax) {
      c8_localMax = c8_in->__$isSimulinkString.__dummy;
    }

    /* Histogram logging. */
    c8_inDouble = (real_T)c8_in->__$isSimulinkString.__dummy;
    c8_histTable->TotalNumberOfValues++;
    if (c8_inDouble == 0.0) {
      c8_histTable->NumberOfZeros++;
    } else {
      c8_histTable->SimSum += c8_inDouble;
      if ((!muDoubleScalarIsInf(c8_inDouble)) && (!muDoubleScalarIsNaN
           (c8_inDouble))) {
        c8_significand = frexp(c8_inDouble, &c8_exponent);
        if (c8_exponent > 128) {
          c8_exponent = 128;
        }

        if (c8_exponent < -127) {
          c8_exponent = -127;
        }

        if (c8_significand < 0.0) {
          c8_histTable->NumberOfNegativeValues++;
          c8_histTable->HistogramOfNegativeValues[127 + c8_exponent]++;
        } else {
          c8_histTable->NumberOfPositiveValues++;
          c8_histTable->HistogramOfPositiveValues[127 + c8_exponent]++;
        }
      }
    }

    c8_b_table[0U].SimMin = (real_T)c8_localMin;
    c8_b_table[0U].SimMax = (real_T)c8_localMax;

    /* IsAlwaysInteger logging. */
    /* Data type is always integer. */
  }
}

static void c8_b_emlrt_update_log_8(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c8_in[3], emlrtLocationLoggingDataType c8_table[],
  int32_T c8_index)
{
  emlrtLocationLoggingDataType *c8_b_table;
  emlrtLocationLoggingHistogramType *c8_histTable;
  real_T c8_inDouble;
  real_T c8_localMax;
  real_T c8_localMin;
  real_T c8_significand;
  int32_T c8_b_i;
  int32_T c8_exponent;
  int32_T c8_i;
  boolean_T c8_isLoggingEnabledHere;
  (void)chartInstance;
  c8_isLoggingEnabledHere = (c8_index >= 0);
  if (c8_isLoggingEnabledHere) {
    c8_b_table = (emlrtLocationLoggingDataType *)&c8_table[c8_index];
    c8_localMin = c8_b_table[0U].SimMin;
    c8_localMax = c8_b_table[0U].SimMax;
    c8_histTable = c8_b_table[0U].HistogramTable;
    for (c8_i = 0; c8_i < 3; c8_i++) {
      /* Simulation Min-Max logging. */
      if (c8_in[c8_i] < c8_localMin) {
        c8_localMin = c8_in[c8_i];
      }

      if (c8_in[c8_i] > c8_localMax) {
        c8_localMax = c8_in[c8_i];
      }

      /* Histogram logging. */
      c8_inDouble = c8_in[c8_i];
      c8_histTable->TotalNumberOfValues++;
      if (c8_inDouble == 0.0) {
        c8_histTable->NumberOfZeros++;
      } else {
        c8_histTable->SimSum += c8_inDouble;
        if ((!muDoubleScalarIsInf(c8_inDouble)) && (!muDoubleScalarIsNaN
             (c8_inDouble))) {
          c8_significand = frexp(c8_inDouble, &c8_exponent);
          if (c8_exponent > 128) {
            c8_exponent = 128;
          }

          if (c8_exponent < -127) {
            c8_exponent = -127;
          }

          if (c8_significand < 0.0) {
            c8_histTable->NumberOfNegativeValues++;
            c8_histTable->HistogramOfNegativeValues[127 + c8_exponent]++;
          } else {
            c8_histTable->NumberOfPositiveValues++;
            c8_histTable->HistogramOfPositiveValues[127 + c8_exponent]++;
          }
        }
      }
    }

    c8_b_table[0U].SimMin = c8_localMin;
    c8_b_table[0U].SimMax = c8_localMax;

    /* IsAlwaysInteger logging. */
    c8_b_i = 0;
    while (c8_b_table[0U].IsAlwaysInteger && (c8_b_i < 3)) {
      if (c8_in[c8_b_i] != muDoubleScalarFloor(c8_in[c8_b_i])) {
        c8_b_table[0U].IsAlwaysInteger = false;
      }

      c8_b_i++;
    }
  }
}

static void c8_b_quaternionBase_normalize(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance, const emlrtStack *c8_sp, c8_quaternion *c8_q)
{
  static char_T c8_cv[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  static char_T c8_cv1[4] = { 's', 'q', 'r', 't' };

  emlrtStack c8_st;
  const mxArray *c8_b_y = NULL;
  const mxArray *c8_c_y = NULL;
  const mxArray *c8_y = NULL;
  real_T c8_b_x;
  real_T c8_n;
  real_T c8_x;
  boolean_T c8_b_p;
  boolean_T c8_p;
  (void)chartInstance;
  c8_st.prev = c8_sp;
  c8_st.tls = c8_sp->tls;
  c8_st.site = &c8_g_emlrtRSI;
  c8_x = ((c8_q->a * c8_q->a + c8_q->b * c8_q->b) + c8_q->c * c8_q->c) + c8_q->d
    * c8_q->d;
  c8_n = c8_x;
  c8_b_x = c8_n;
  if (c8_b_x < 0.0) {
    c8_p = true;
  } else {
    c8_p = false;
  }

  c8_b_p = c8_p;
  if (c8_b_p) {
    c8_y = NULL;
    sf_mex_assign(&c8_y, sf_mex_create("y", c8_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c8_b_y = NULL;
    sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c8_c_y = NULL;
    sf_mex_assign(&c8_c_y, sf_mex_create("y", c8_cv1, 10, 0U, 1U, 0U, 2, 1, 4),
                  false);
    sf_mex_call(&c8_st, &c8_emlrtMCI, "error", 0U, 2U, 14, c8_y, 14, sf_mex_call
                (&c8_st, NULL, "getString", 1U, 1U, 14, sf_mex_call(&c8_st, NULL,
      "message", 1U, 2U, 14, c8_b_y, 14, c8_c_y)));
  }

  c8_n = muDoubleScalarSqrt(c8_n);
  c8_q->a /= c8_n;
  c8_q->b /= c8_n;
  c8_q->c /= c8_n;
  c8_q->d /= c8_n;
}

static void init_dsm_address_info(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc8_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  chartInstance->c8_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c8_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c8_accel_SNED = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c8_gyro_SNED = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c8_accel_VNED = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c8_gyro_VNED = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c8_mag_VNED = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c8_mag_SNED = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c8_car_model_FIXED_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(746951U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1376549398U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2196033671U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3728787005U);
}

mxArray *sf_c8_car_model_FIXED_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c8_car_model_FIXED_jit_fallback_info(void)
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

mxArray *sf_c8_car_model_FIXED_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c8_car_model_FIXED(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiBewMzAwAakOYCYiQECWKF8RiBmgdIQcRa4uAIQl1QWpILEi4uSPVOAdF5iLpi"
    "fWFrhmZeWDzbfggFhPhsW8xmRzOeEikPAB3vK9Is4gPQ7IOlnwaKfC0m/AJSfmJycmhMf7OfqAh"
    "HnY0DQA+cfBaL8w4nmHxA/vbIoH8k7g8Q/Sg7o+rH5hwPNPyB+bmI62DvU8YeCA2X6IfYHEPCHD"
    "Jo/QPzM4vjE5JLMstT4ZIv45MSi+Nz8FGDCc/OMgEQVzH8AzMspYw=="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_car_model_FIXED_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sIGoQh1EzRG2NYhkWn6kyIB";
}

static void sf_opaque_initialize_c8_car_model_FIXED(void *chartInstanceVar)
{
  initialize_params_c8_car_model_FIXED((SFc8_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
  initialize_c8_car_model_FIXED((SFc8_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c8_car_model_FIXED(void *chartInstanceVar)
{
  enable_c8_car_model_FIXED((SFc8_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c8_car_model_FIXED(void *chartInstanceVar)
{
  disable_c8_car_model_FIXED((SFc8_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c8_car_model_FIXED(void *chartInstanceVar)
{
  sf_gateway_c8_car_model_FIXED((SFc8_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c8_car_model_FIXED(SimStruct* S)
{
  return get_sim_state_c8_car_model_FIXED((SFc8_car_model_FIXEDInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c8_car_model_FIXED(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c8_car_model_FIXED((SFc8_car_model_FIXEDInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c8_car_model_FIXED(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc8_car_model_FIXEDInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_car_model_FIXED_optimization_info();
    }

    mdl_cleanup_runtime_resources_c8_car_model_FIXED
      ((SFc8_car_model_FIXEDInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c8_car_model_FIXED(void *chartInstanceVar)
{
  mdl_start_c8_car_model_FIXED((SFc8_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_mdl_terminate_c8_car_model_FIXED(void *chartInstanceVar)
{
  mdl_terminate_c8_car_model_FIXED((SFc8_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc8_car_model_FIXED((SFc8_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c8_car_model_FIXED(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  sf_warn_if_symbolic_dimension_param_changed(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c8_car_model_FIXED((SFc8_car_model_FIXEDInstanceStruct*)
      sf_get_chart_instance_ptr(S));
    initSimStructsc8_car_model_FIXED((SFc8_car_model_FIXEDInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c8_car_model_FIXED_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [23] = {
    "eNrtWc1v40QUd9pQtbBUK4TEgUpUSCAuSLtFi/aAoM1XidSPsE67wIFoar/Eo4xnvPORNCuuXPg",
    "r+Ec48UeAxJk73BDiwBvHSYMbEk8L3S5aS641tn/z3u/5faZeqXno4bGJ58M3PW8Nr+t4rnjj46",
    "VsXZo5x/fL3kfZ+utXPC8QIfSA+6bbpeee28FN3CKSxMpzPziJ4REowYymgjd5VxTHUt4FCTzAD",
    "RIhtZNcRWPDKO83DA+sZPU4okHkR8KwsIIbkvCYs9E/yU2MbqHEGpUQ6AZAqCMpTC9qMNJbbAWp",
    "h9UIgr4ysbOtFGjfJJaqOjRM04RB/RyCJleaoBXUEr6+Jhqq+tzNyJav8idoESeMEl7c1hFRPiT",
    "oHRpOkhD/HhuN1iuEDSIidQUiMgB1QPupdMGhkHSq8O0zyokWkhJWj1nV7laQb4shx0MMCeb6jZ",
    "BvRQLpJ4Jy7RgQfgPtXOfkjEENzkzPUa4PT4yNhlMKQ5Bu37dbFQOQpAfH3E3n9BvVz1OnnMZSQ",
    "aymMZwSuReg7yoI3fIGBp3yCbojtHEbJyykJm6qtqQD9A3XXNe04X+lXGfisferK2FTufUBOPvV",
    "VG4j4FXCmHLDtkVyAANgqfwa0eQK2LF8B7BSNGwL9A6bbRwzluEUIyHDVgUPaXGvHORQaWE7wiJ",
    "VAE5jGwYQopmnqk83WhZHRmkRVzHl1A4OCsq7jG1yDbJLAihcYyShClDh1K8c5YZU2UBCNFpJpy",
    "wL7zCOwStBPdU1vDYUso82di1mF7aykeCGhrCHiVlDmuTq6N2nhJmCOseqh/GD7nGiMMu6yUWsj",
    "Z8rgQMSRBDaykkZHGKexQ2KfmJlS/4esh1QPaqBCiRNikaSwYSORddaqT1K4IT3uRjyhhSxn3Ve",
    "C/wKALMGkZzyXgVLuBw1UPliWkt40k6zu2uTY+1MNCNn1jf2gWM1tFxt10ACjKo6xxYZFboO1qd",
    "PsYnhiiqNhXo0LvXjumf790+9i/69PKd/f22mf7+brYOHnYDITmx7lU6j+Xm95k33uzez350C80",
    "CpAM67hLuQN7m+N4MvzZHrzVzz8jZW/v7+ak7eCt4plUopbncG92pOTjmHW8tsJh58+8uP3e9/+",
    "O3nd/7486tv3l0mv3RJfmlqp1bZbd7azNZbk75pmqUHlxJZEX94I+cPdq2a++Kz6H796aP9naMv",
    "ov5j/mF/1Kyk+323uljfck7fyf1t26thEKc5QQbNMJvb7JqY8TyRzp8z+q4tscfGjD953q+fXA/",
    "/+m7eH+bZ6+WcveyaYPPJOv7RbNxM5+lnxme7EJ+NHB+77o2kmKFzS/i8vZvHz+OznuOznubVXk",
    "rn3+GxvXs9fBb3S3hs5XhspTNWh9hKCp35GXuzYD5clI9ccd4N454XPV/Y5b/nV6QfWb1hnHfDu",
    "Ovyc+2znvf37y3Iu17u/bu3mMeifO/Sb982Xj95bv3wW9n64+nvPdWIsnDOxJk9xqGwO+/p/8S/",
    "f3e036T/r1v7Zf8Y+PKDPU7YCEfM8Qif3W5J+/vu9JEEoubP8c+inkyuy/rdO7n4tush5aEYqvf",
    "v7zzYuU59+gs1fipN",
    ""
  };

  static char newstr [1593] = "";
  newstr[0] = '\0';
  for (i = 0; i < 23; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c8_car_model_FIXED(SimStruct *S)
{
  const char* newstr = sf_c8_car_model_FIXED_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(3851040111U));
  ssSetChecksum1(S,(3283969751U));
  ssSetChecksum2(S,(4196785137U));
  ssSetChecksum3(S,(646274812U));
}

static void mdlRTW_c8_car_model_FIXED(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c8_car_model_FIXED(SimStruct *S)
{
  SFc8_car_model_FIXEDInstanceStruct *chartInstance;
  chartInstance = (SFc8_car_model_FIXEDInstanceStruct *)utMalloc(sizeof
    (SFc8_car_model_FIXEDInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc8_car_model_FIXEDInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c8_car_model_FIXED;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c8_car_model_FIXED;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c8_car_model_FIXED;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c8_car_model_FIXED;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c8_car_model_FIXED;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c8_car_model_FIXED;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c8_car_model_FIXED;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c8_car_model_FIXED;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c8_car_model_FIXED;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c8_car_model_FIXED;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c8_car_model_FIXED;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c8_car_model_FIXED;
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
    chartInstance->c8_JITStateAnimation,
    chartInstance->c8_JITTransitionAnimation);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c8_car_model_FIXED(chartInstance);
}

void c8_car_model_FIXED_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c8_car_model_FIXED(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_car_model_FIXED(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_car_model_FIXED(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_car_model_FIXED_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
