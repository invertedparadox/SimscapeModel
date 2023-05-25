/* Include files */

#include "car_model_FIXED_sfun.h"
#include "c13_car_model_FIXED.h"
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
static void initialize_c13_car_model_FIXED(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance);
static void initialize_params_c13_car_model_FIXED
  (SFc13_car_model_FIXEDInstanceStruct *chartInstance);
static void mdl_start_c13_car_model_FIXED(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance);
static void mdl_terminate_c13_car_model_FIXED
  (SFc13_car_model_FIXEDInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c13_car_model_FIXED
  (SFc13_car_model_FIXEDInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c13_car_model_FIXED
  (SFc13_car_model_FIXEDInstanceStruct *chartInstance);
static void enable_c13_car_model_FIXED(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance);
static void disable_c13_car_model_FIXED(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance);
static void sf_gateway_c13_car_model_FIXED(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance);
static void ext_mode_exec_c13_car_model_FIXED
  (SFc13_car_model_FIXEDInstanceStruct *chartInstance);
static void c13_update_jit_animation_c13_car_model_FIXED
  (SFc13_car_model_FIXEDInstanceStruct *chartInstance);
static void c13_do_animation_call_c13_car_model_FIXED
  (SFc13_car_model_FIXEDInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c13_car_model_FIXED
  (SFc13_car_model_FIXEDInstanceStruct *chartInstance);
static void set_sim_state_c13_car_model_FIXED
  (SFc13_car_model_FIXEDInstanceStruct *chartInstance, const mxArray *c13_st);
static void initSimStructsc13_car_model_FIXED
  (SFc13_car_model_FIXEDInstanceStruct *chartInstance);
static void c13_emlrt_update_log_1(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c13_in[9], emlrtLocationLoggingDataType c13_table[],
  int32_T c13_index, real_T c13_out[9]);
static void c13_emlrt_update_log_2(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c13_in[28], emlrtLocationLoggingDataType c13_table[],
  int32_T c13_index, real_T c13_out[28]);
static void c13_emlrt_update_log_3(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c13_in[4], emlrtLocationLoggingDataType c13_table[],
  int32_T c13_index, real_T c13_out[4]);
static void c13_emlrt_update_log_4(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c13_in[3], emlrtLocationLoggingDataType c13_table[],
  int32_T c13_index, real_T c13_out[3]);
static void c13_emlrt_update_log_5(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c13_in[3], emlrtLocationLoggingDataType c13_table[],
  int32_T c13_index, real_T c13_out[3]);
static void c13_emlrtInitVarDataTables(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, emlrtLocationLoggingDataType c13_dataTables[14],
  emlrtLocationLoggingHistogramType c13_histTables[14]);
static void c13_emlrt_marshallIn(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c13_b_accel, const char_T *c13_identifier,
  real_T c13_y[3]);
static void c13_b_emlrt_marshallIn(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId,
  real_T c13_y[3]);
static void c13_c_emlrt_marshallIn(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c13_b_ang, const char_T *c13_identifier, real_T
  c13_y[4]);
static void c13_d_emlrt_marshallIn(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId,
  real_T c13_y[4]);
static void c13_e_emlrt_marshallIn(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c13_b_angvel, const char_T *c13_identifier,
  real_T c13_y[3]);
static void c13_f_emlrt_marshallIn(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId,
  real_T c13_y[3]);
static uint8_T c13_g_emlrt_marshallIn(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c13_b_is_active_c13_car_model_FIXED, const
  char_T *c13_identifier);
static uint8_T c13_h_emlrt_marshallIn(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_slStringInitializeDynamicBuffers
  (SFc13_car_model_FIXEDInstanceStruct *chartInstance);
static void c13_chart_data_browse_helper(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, int32_T c13_ssIdNumber, const mxArray **c13_mxData, uint8_T
  *c13_isValueTooBig);
static void c13_b_emlrt_update_log_1(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c13_in[9], emlrtLocationLoggingDataType c13_table[],
  int32_T c13_index);
static void c13_b_emlrt_update_log_2(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c13_in[28], emlrtLocationLoggingDataType c13_table[],
  int32_T c13_index);
static void c13_b_emlrt_update_log_3(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c13_in[4], emlrtLocationLoggingDataType c13_table[],
  int32_T c13_index);
static void c13_b_emlrt_update_log_4(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c13_in[3], emlrtLocationLoggingDataType c13_table[],
  int32_T c13_index);
static void c13_b_emlrt_update_log_5(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c13_in[3], emlrtLocationLoggingDataType c13_table[],
  int32_T c13_index);
static void init_dsm_address_info(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c13_car_model_FIXED(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
  chartInstance->c13_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c13_is_active_c13_car_model_FIXED = 0U;
  chartInstance->c13_emlrtLocLogSimulated = false;
  c13_emlrtInitVarDataTables(chartInstance,
    chartInstance->c13_emlrtLocationLoggingDataTables,
    chartInstance->c13_emlrtLocLogHistTables);
}

static void initialize_params_c13_car_model_FIXED
  (SFc13_car_model_FIXEDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_start_c13_car_model_FIXED(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void mdl_terminate_c13_car_model_FIXED
  (SFc13_car_model_FIXEDInstanceStruct *chartInstance)
{
  const emlrtLocationLoggingFileInfoType c13_emlrtLocationLoggingFileInfo = {
    "#car_model_FIXED:6032",           /* mexFileName */
    "Mon Apr 17 19:53:05 2023",        /* timestamp */
    "",                                /* buildDir */
    1,                                 /* numFcns */
    256                                /* numHistogramBins */
  };

  const emlrtLocationLoggingFunctionInfoType
    c13_emlrtLocationLoggingFunctionInfoTable[1] = { { "eML_blk_kernel",/* fcnName */
      1,                               /* fcnId */
      14                               /* numInstrPoints */
    } };

  const emlrtLocationLoggingLocationType c13_emlrtLocationInfo[15] = { { 1,/* MxInfoID */
      81,                              /* TextStart */
      7,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      90,                              /* TextStart */
      5,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 3,                            /* MxInfoID */
      113,                             /* TextStart */
      3,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 4,                            /* MxInfoID */
      175,                             /* TextStart */
      6,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 5,                            /* MxInfoID */
      253,                             /* TextStart */
      3,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 4,                            /* MxInfoID */
      318,                             /* TextStart */
      3,                               /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 4,                            /* MxInfoID */
      324,                             /* TextStart */
      20,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 5,                            /* MxInfoID */
      386,                             /* TextStart */
      5,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 4,                            /* MxInfoID */
      394,                             /* TextStart */
      20,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 5,                            /* MxInfoID */
      460,                             /* TextStart */
      3,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 5,                            /* MxInfoID */
      546,                             /* TextStart */
      10,                              /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 4,                            /* MxInfoID */
      559,                             /* TextStart */
      20,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 5,                            /* MxInfoID */
      618,                             /* TextStart */
      9,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 4,                            /* MxInfoID */
      630,                             /* TextStart */
      20,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 5,                            /* MxInfoID */
      686,                             /* TextStart */
      8,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    } };

  const int32_T c13_emlrtLocationLoggingFieldCounts[14] = { 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0 };

  if (chartInstance->c13_emlrtLocLogSimulated) {
    emlrtLocationLoggingClearLog("#car_model_FIXED:6032");
    emlrtLocationLoggingPushLog(&c13_emlrtLocationLoggingFileInfo,
      &c13_emlrtLocationLoggingFunctionInfoTable[0],
      &chartInstance->c13_emlrtLocationLoggingDataTables[0],
      &c13_emlrtLocationInfo[0], NULL, 0U, &c13_emlrtLocationLoggingFieldCounts
      [0], NULL);
    addResultsToFPTRepository("#car_model_FIXED:6032");
  }
}

static void mdl_setup_runtime_resources_c13_car_model_FIXED
  (SFc13_car_model_FIXEDInstanceStruct *chartInstance)
{
  static const uint32_T c13_decisionTxtEndIdx = 0U;
  static const uint32_T c13_decisionTxtStartIdx = 0U;
  setDebuggerFlag(chartInstance->S, true);
  setDataBrowseFcn(chartInstance->S, (void *)&c13_chart_data_browse_helper);
  chartInstance->c13_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c13_RuntimeVar,
    &chartInstance->c13_IsDebuggerActive,
    &chartInstance->c13_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c13_mlFcnLineNumber, &chartInstance->c13_IsHeatMapPresent, 0);
  sim_mode_is_external(chartInstance->S);
  covrtCreateStateflowInstanceData(chartInstance->c13_covrtInstance, 1U, 0U, 1U,
    134U);
  covrtChartInitFcn(chartInstance->c13_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c13_covrtInstance, 0U, 0U, false, false,
                    false, 0U, &c13_decisionTxtStartIdx, &c13_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c13_covrtInstance, 0U, 0, NULL, NULL, 0U,
                    NULL);
  covrtEmlInitFcn(chartInstance->c13_covrtInstance, "", 4U, 0U, 1U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c13_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 757);
}

static void mdl_cleanup_runtime_resources_c13_car_model_FIXED
  (SFc13_car_model_FIXEDInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c13_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c13_covrtInstance);
}

static void enable_c13_car_model_FIXED(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c13_car_model_FIXED(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c13_car_model_FIXED(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  real_T c13_dv1[28];
  real_T c13_dv[9];
  real_T c13_b_b[3];
  real_T c13_dv2[3];
  real_T c13_dv3[3];
  real_T c13_dv4[3];
  int32_T c13_i;
  int32_T c13_i1;
  int32_T c13_i10;
  int32_T c13_i11;
  int32_T c13_i12;
  int32_T c13_i13;
  int32_T c13_i14;
  int32_T c13_i15;
  int32_T c13_i16;
  int32_T c13_i17;
  int32_T c13_i18;
  int32_T c13_i19;
  int32_T c13_i2;
  int32_T c13_i20;
  int32_T c13_i21;
  int32_T c13_i22;
  int32_T c13_i23;
  int32_T c13_i24;
  int32_T c13_i25;
  int32_T c13_i26;
  int32_T c13_i27;
  int32_T c13_i28;
  int32_T c13_i29;
  int32_T c13_i3;
  int32_T c13_i30;
  int32_T c13_i31;
  int32_T c13_i32;
  int32_T c13_i33;
  int32_T c13_i34;
  int32_T c13_i35;
  int32_T c13_i36;
  int32_T c13_i37;
  int32_T c13_i38;
  int32_T c13_i39;
  int32_T c13_i4;
  int32_T c13_i40;
  int32_T c13_i41;
  int32_T c13_i42;
  int32_T c13_i43;
  int32_T c13_i44;
  int32_T c13_i45;
  int32_T c13_i46;
  int32_T c13_i47;
  int32_T c13_i48;
  int32_T c13_i49;
  int32_T c13_i5;
  int32_T c13_i50;
  int32_T c13_i51;
  int32_T c13_i52;
  int32_T c13_i53;
  int32_T c13_i54;
  int32_T c13_i55;
  int32_T c13_i56;
  int32_T c13_i57;
  int32_T c13_i58;
  int32_T c13_i59;
  int32_T c13_i6;
  int32_T c13_i60;
  int32_T c13_i7;
  int32_T c13_i8;
  int32_T c13_i9;
  boolean_T c13_b;
  boolean_T c13_b1;
  boolean_T c13_b10;
  boolean_T c13_b11;
  boolean_T c13_b12;
  boolean_T c13_b13;
  boolean_T c13_b14;
  boolean_T c13_b15;
  boolean_T c13_b16;
  boolean_T c13_b17;
  boolean_T c13_b18;
  boolean_T c13_b19;
  boolean_T c13_b2;
  boolean_T c13_b20;
  boolean_T c13_b21;
  boolean_T c13_b22;
  boolean_T c13_b23;
  boolean_T c13_b24;
  boolean_T c13_b25;
  boolean_T c13_b26;
  boolean_T c13_b27;
  boolean_T c13_b28;
  boolean_T c13_b29;
  boolean_T c13_b3;
  boolean_T c13_b30;
  boolean_T c13_b31;
  boolean_T c13_b32;
  boolean_T c13_b33;
  boolean_T c13_b34;
  boolean_T c13_b35;
  boolean_T c13_b36;
  boolean_T c13_b37;
  boolean_T c13_b38;
  boolean_T c13_b39;
  boolean_T c13_b4;
  boolean_T c13_b5;
  boolean_T c13_b6;
  boolean_T c13_b7;
  boolean_T c13_b8;
  boolean_T c13_b9;
  chartInstance->c13_JITTransitionAnimation[0] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  for (c13_i = 0; c13_i < 28; c13_i++) {
    covrtSigUpdateFcn(chartInstance->c13_covrtInstance, 1U,
                      (*chartInstance->c13_state)[c13_i]);
  }

  c13_b = false;
  c13_i1 = 0;
  for (c13_i2 = 0; c13_i2 < 3; c13_i2++) {
    for (c13_i3 = 0; c13_i3 < 3; c13_i3++) {
      c13_b = (c13_b || ((*chartInstance->c13_rot_map)[c13_i3 + c13_i1] > 4.0));
    }

    c13_i1 += 3;
  }

  c13_b1 = c13_b;
  if (c13_b1) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 0U, 1U);
  }

  c13_b2 = false;
  c13_i4 = 0;
  for (c13_i5 = 0; c13_i5 < 3; c13_i5++) {
    for (c13_i6 = 0; c13_i6 < 3; c13_i6++) {
      c13_b2 = (c13_b2 || ((*chartInstance->c13_rot_map)[c13_i6 + c13_i4] < -4.0));
    }

    c13_i4 += 3;
  }

  c13_b3 = c13_b2;
  if (c13_b3) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 0U, 0U);
  }

  for (c13_i7 = 0; c13_i7 < 9; c13_i7++) {
    covrtSigUpdateFcn(chartInstance->c13_covrtInstance, 0U,
                      (*chartInstance->c13_rot_map)[c13_i7]);
  }

  chartInstance->c13_sfEvent = CALL_EVENT;

  /* logging input variable 'rot_map' for function 'eML_blk_kernel' */
  /* logging input variable 'state' for function 'eML_blk_kernel' */
  chartInstance->c13_emlrtLocLogSimulated = true;

  /* logging input variable 'rot_map' for function 'eML_blk_kernel' */
  for (c13_i8 = 0; c13_i8 < 9; c13_i8++) {
    c13_dv[c13_i8] = (*chartInstance->c13_rot_map)[c13_i8];
  }

  c13_b_emlrt_update_log_1(chartInstance, c13_dv,
    chartInstance->c13_emlrtLocationLoggingDataTables, 0);

  /* logging input variable 'state' for function 'eML_blk_kernel' */
  for (c13_i9 = 0; c13_i9 < 28; c13_i9++) {
    c13_dv1[c13_i9] = (*chartInstance->c13_state)[c13_i9];
  }

  c13_b_emlrt_update_log_2(chartInstance, c13_dv1,
    chartInstance->c13_emlrtLocationLoggingDataTables, 1);
  covrtEmlFcnEval(chartInstance->c13_covrtInstance, 4U, 0, 0);
  for (c13_i10 = 0; c13_i10 < 4; c13_i10++) {
    (*chartInstance->c13_ang)[c13_i10] = (*chartInstance->c13_state)[c13_i10];
  }

  c13_b_emlrt_update_log_3(chartInstance, *chartInstance->c13_ang,
    chartInstance->c13_emlrtLocationLoggingDataTables, 2);
  for (c13_i11 = 0; c13_i11 < 3; c13_i11++) {
    (*chartInstance->c13_angvel)[c13_i11] = (*chartInstance->c13_state)[c13_i11
      + 4];
  }

  c13_b_emlrt_update_log_4(chartInstance, *chartInstance->c13_angvel,
    chartInstance->c13_emlrtLocationLoggingDataTables, 3);
  for (c13_i12 = 0; c13_i12 < 3; c13_i12++) {
    (*chartInstance->c13_pos)[c13_i12] = (*chartInstance->c13_state)[c13_i12 + 7];
  }

  c13_b_emlrt_update_log_5(chartInstance, *chartInstance->c13_pos,
    chartInstance->c13_emlrtLocationLoggingDataTables, 4);
  for (c13_i13 = 0; c13_i13 < 3; c13_i13++) {
    c13_b_b[c13_i13] = (*chartInstance->c13_state)[c13_i13 + 10];
  }

  for (c13_i14 = 0; c13_i14 < 3; c13_i14++) {
    (*chartInstance->c13_vel)[c13_i14] = 0.0;
    c13_i16 = 0;
    for (c13_i17 = 0; c13_i17 < 3; c13_i17++) {
      (*chartInstance->c13_vel)[c13_i14] += (*chartInstance->c13_rot_map)
        [c13_i16 + c13_i14] * c13_b_b[c13_i17];
      c13_i16 += 3;
    }
  }

  c13_b_emlrt_update_log_4(chartInstance, *chartInstance->c13_vel,
    chartInstance->c13_emlrtLocationLoggingDataTables, 5);
  for (c13_i15 = 0; c13_i15 < 3; c13_i15++) {
    c13_b_b[c13_i15] = (*chartInstance->c13_state)[c13_i15 + 13];
  }

  for (c13_i18 = 0; c13_i18 < 3; c13_i18++) {
    c13_dv2[c13_i18] = 0.0;
    c13_i20 = 0;
    for (c13_i21 = 0; c13_i21 < 3; c13_i21++) {
      c13_dv2[c13_i18] += (*chartInstance->c13_rot_map)[c13_i20 + c13_i18] *
        c13_b_b[c13_i21];
      c13_i20 += 3;
    }
  }

  for (c13_i19 = 0; c13_i19 < 3; c13_i19++) {
    (*chartInstance->c13_accel)[c13_i19] = c13_dv2[c13_i19];
  }

  c13_b_emlrt_update_log_4(chartInstance, *chartInstance->c13_accel,
    chartInstance->c13_emlrtLocationLoggingDataTables, 7);
  c13_b_emlrt_update_log_5(chartInstance, *chartInstance->c13_accel,
    chartInstance->c13_emlrtLocationLoggingDataTables, 6);
  for (c13_i22 = 0; c13_i22 < 3; c13_i22++) {
    (*chartInstance->c13_mag)[c13_i22] = (*chartInstance->c13_state)[c13_i22 +
      22];
  }

  c13_b_emlrt_update_log_5(chartInstance, *chartInstance->c13_mag,
    chartInstance->c13_emlrtLocationLoggingDataTables, 8);
  for (c13_i23 = 0; c13_i23 < 3; c13_i23++) {
    c13_b_b[c13_i23] = (*chartInstance->c13_state)[c13_i23 + 16];
  }

  for (c13_i24 = 0; c13_i24 < 3; c13_i24++) {
    c13_dv3[c13_i24] = 0.0;
    c13_i26 = 0;
    for (c13_i27 = 0; c13_i27 < 3; c13_i27++) {
      c13_dv3[c13_i24] += (*chartInstance->c13_rot_map)[c13_i26 + c13_i24] *
        c13_b_b[c13_i27];
      c13_i26 += 3;
    }
  }

  for (c13_i25 = 0; c13_i25 < 3; c13_i25++) {
    (*chartInstance->c13_accel_bias)[c13_i25] = c13_dv3[c13_i25];
  }

  c13_b_emlrt_update_log_4(chartInstance, *chartInstance->c13_accel_bias,
    chartInstance->c13_emlrtLocationLoggingDataTables, 10);
  c13_b_emlrt_update_log_5(chartInstance, *chartInstance->c13_accel_bias,
    chartInstance->c13_emlrtLocationLoggingDataTables, 9);
  for (c13_i28 = 0; c13_i28 < 3; c13_i28++) {
    c13_b_b[c13_i28] = (*chartInstance->c13_state)[c13_i28 + 19];
  }

  for (c13_i29 = 0; c13_i29 < 3; c13_i29++) {
    c13_dv4[c13_i29] = 0.0;
    c13_i31 = 0;
    for (c13_i32 = 0; c13_i32 < 3; c13_i32++) {
      c13_dv4[c13_i29] += (*chartInstance->c13_rot_map)[c13_i31 + c13_i29] *
        c13_b_b[c13_i32];
      c13_i31 += 3;
    }
  }

  for (c13_i30 = 0; c13_i30 < 3; c13_i30++) {
    (*chartInstance->c13_gyro_bias)[c13_i30] = c13_dv4[c13_i30];
  }

  c13_b_emlrt_update_log_4(chartInstance, *chartInstance->c13_gyro_bias,
    chartInstance->c13_emlrtLocationLoggingDataTables, 12);
  c13_b_emlrt_update_log_5(chartInstance, *chartInstance->c13_gyro_bias,
    chartInstance->c13_emlrtLocationLoggingDataTables, 11);
  for (c13_i33 = 0; c13_i33 < 3; c13_i33++) {
    (*chartInstance->c13_mag_bias)[c13_i33] = (*chartInstance->c13_state)
      [c13_i33 + 25];
  }

  c13_b_emlrt_update_log_5(chartInstance, *chartInstance->c13_mag_bias,
    chartInstance->c13_emlrtLocationLoggingDataTables, 13);
  c13_do_animation_call_c13_car_model_FIXED(chartInstance);
  c13_b4 = false;
  for (c13_i34 = 0; c13_i34 < 4; c13_i34++) {
    c13_b4 = (c13_b4 || ((*chartInstance->c13_ang)[c13_i34] > 1.0));
  }

  c13_b5 = c13_b4;
  if (c13_b5) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 2U, 1U);
  }

  c13_b6 = false;
  for (c13_i35 = 0; c13_i35 < 4; c13_i35++) {
    c13_b6 = (c13_b6 || ((*chartInstance->c13_ang)[c13_i35] < -1.0));
  }

  c13_b7 = c13_b6;
  if (c13_b7) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 2U, 0U);
  }

  for (c13_i36 = 0; c13_i36 < 4; c13_i36++) {
    covrtSigUpdateFcn(chartInstance->c13_covrtInstance, 2U,
                      (*chartInstance->c13_ang)[c13_i36]);
  }

  c13_b8 = false;
  for (c13_i37 = 0; c13_i37 < 3; c13_i37++) {
    c13_b8 = (c13_b8 || ((*chartInstance->c13_angvel)[c13_i37] > 2.5));
  }

  c13_b9 = c13_b8;
  if (c13_b9) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 3U, 1U);
  }

  c13_b10 = false;
  for (c13_i38 = 0; c13_i38 < 3; c13_i38++) {
    c13_b10 = (c13_b10 || ((*chartInstance->c13_angvel)[c13_i38] < -2.5));
  }

  c13_b11 = c13_b10;
  if (c13_b11) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 3U, 0U);
  }

  for (c13_i39 = 0; c13_i39 < 3; c13_i39++) {
    covrtSigUpdateFcn(chartInstance->c13_covrtInstance, 3U,
                      (*chartInstance->c13_angvel)[c13_i39]);
  }

  c13_b12 = false;
  for (c13_i40 = 0; c13_i40 < 3; c13_i40++) {
    c13_b12 = (c13_b12 || ((*chartInstance->c13_pos)[c13_i40] > 300.0));
  }

  c13_b13 = c13_b12;
  if (c13_b13) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 4U, 1U);
  }

  c13_b14 = false;
  for (c13_i41 = 0; c13_i41 < 3; c13_i41++) {
    c13_b14 = (c13_b14 || ((*chartInstance->c13_pos)[c13_i41] < -300.0));
  }

  c13_b15 = c13_b14;
  if (c13_b15) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 4U, 0U);
  }

  for (c13_i42 = 0; c13_i42 < 3; c13_i42++) {
    covrtSigUpdateFcn(chartInstance->c13_covrtInstance, 4U,
                      (*chartInstance->c13_pos)[c13_i42]);
  }

  c13_b16 = false;
  for (c13_i43 = 0; c13_i43 < 3; c13_i43++) {
    c13_b16 = (c13_b16 || ((*chartInstance->c13_vel)[c13_i43] > 30.0));
  }

  c13_b17 = c13_b16;
  if (c13_b17) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 5U, 1U);
  }

  c13_b18 = false;
  for (c13_i44 = 0; c13_i44 < 3; c13_i44++) {
    c13_b18 = (c13_b18 || ((*chartInstance->c13_vel)[c13_i44] < -30.0));
  }

  c13_b19 = c13_b18;
  if (c13_b19) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 5U, 0U);
  }

  for (c13_i45 = 0; c13_i45 < 3; c13_i45++) {
    covrtSigUpdateFcn(chartInstance->c13_covrtInstance, 5U,
                      (*chartInstance->c13_vel)[c13_i45]);
  }

  c13_b20 = false;
  for (c13_i46 = 0; c13_i46 < 3; c13_i46++) {
    c13_b20 = (c13_b20 || ((*chartInstance->c13_accel)[c13_i46] > 30.0));
  }

  c13_b21 = c13_b20;
  if (c13_b21) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 6U, 1U);
  }

  c13_b22 = false;
  for (c13_i47 = 0; c13_i47 < 3; c13_i47++) {
    c13_b22 = (c13_b22 || ((*chartInstance->c13_accel)[c13_i47] < -30.0));
  }

  c13_b23 = c13_b22;
  if (c13_b23) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 6U, 0U);
  }

  for (c13_i48 = 0; c13_i48 < 3; c13_i48++) {
    covrtSigUpdateFcn(chartInstance->c13_covrtInstance, 6U,
                      (*chartInstance->c13_accel)[c13_i48]);
  }

  c13_b24 = false;
  for (c13_i49 = 0; c13_i49 < 3; c13_i49++) {
    c13_b24 = (c13_b24 || ((*chartInstance->c13_mag)[c13_i49] > 200.0));
  }

  c13_b25 = c13_b24;
  if (c13_b25) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 7U, 1U);
  }

  c13_b26 = false;
  for (c13_i50 = 0; c13_i50 < 3; c13_i50++) {
    c13_b26 = (c13_b26 || ((*chartInstance->c13_mag)[c13_i50] < -200.0));
  }

  c13_b27 = c13_b26;
  if (c13_b27) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 7U, 0U);
  }

  for (c13_i51 = 0; c13_i51 < 3; c13_i51++) {
    covrtSigUpdateFcn(chartInstance->c13_covrtInstance, 7U,
                      (*chartInstance->c13_mag)[c13_i51]);
  }

  c13_b28 = false;
  for (c13_i52 = 0; c13_i52 < 3; c13_i52++) {
    c13_b28 = (c13_b28 || ((*chartInstance->c13_accel_bias)[c13_i52] > 30.0));
  }

  c13_b29 = c13_b28;
  if (c13_b29) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 8U, 1U);
  }

  c13_b30 = false;
  for (c13_i53 = 0; c13_i53 < 3; c13_i53++) {
    c13_b30 = (c13_b30 || ((*chartInstance->c13_accel_bias)[c13_i53] < -30.0));
  }

  c13_b31 = c13_b30;
  if (c13_b31) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 8U, 0U);
  }

  for (c13_i54 = 0; c13_i54 < 3; c13_i54++) {
    covrtSigUpdateFcn(chartInstance->c13_covrtInstance, 8U,
                      (*chartInstance->c13_accel_bias)[c13_i54]);
  }

  c13_b32 = false;
  for (c13_i55 = 0; c13_i55 < 3; c13_i55++) {
    c13_b32 = (c13_b32 || ((*chartInstance->c13_gyro_bias)[c13_i55] > 2.5));
  }

  c13_b33 = c13_b32;
  if (c13_b33) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 9U, 1U);
  }

  c13_b34 = false;
  for (c13_i56 = 0; c13_i56 < 3; c13_i56++) {
    c13_b34 = (c13_b34 || ((*chartInstance->c13_gyro_bias)[c13_i56] < -2.5));
  }

  c13_b35 = c13_b34;
  if (c13_b35) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 9U, 0U);
  }

  for (c13_i57 = 0; c13_i57 < 3; c13_i57++) {
    covrtSigUpdateFcn(chartInstance->c13_covrtInstance, 9U,
                      (*chartInstance->c13_gyro_bias)[c13_i57]);
  }

  c13_b36 = false;
  for (c13_i58 = 0; c13_i58 < 3; c13_i58++) {
    c13_b36 = (c13_b36 || ((*chartInstance->c13_mag_bias)[c13_i58] > 200.0));
  }

  c13_b37 = c13_b36;
  if (c13_b37) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 10U, 1U);
  }

  c13_b38 = false;
  for (c13_i59 = 0; c13_i59 < 3; c13_i59++) {
    c13_b38 = (c13_b38 || ((*chartInstance->c13_mag_bias)[c13_i59] < -200.0));
  }

  c13_b39 = c13_b38;
  if (c13_b39) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 10U, 0U);
  }

  for (c13_i60 = 0; c13_i60 < 3; c13_i60++) {
    covrtSigUpdateFcn(chartInstance->c13_covrtInstance, 10U,
                      (*chartInstance->c13_mag_bias)[c13_i60]);
  }
}

static void ext_mode_exec_c13_car_model_FIXED
  (SFc13_car_model_FIXEDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c13_update_jit_animation_c13_car_model_FIXED
  (SFc13_car_model_FIXEDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c13_do_animation_call_c13_car_model_FIXED
  (SFc13_car_model_FIXEDInstanceStruct *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static const mxArray *get_sim_state_c13_car_model_FIXED
  (SFc13_car_model_FIXEDInstanceStruct *chartInstance)
{
  const mxArray *c13_b_y = NULL;
  const mxArray *c13_c_y = NULL;
  const mxArray *c13_d_y = NULL;
  const mxArray *c13_e_y = NULL;
  const mxArray *c13_f_y = NULL;
  const mxArray *c13_g_y = NULL;
  const mxArray *c13_h_y = NULL;
  const mxArray *c13_i_y = NULL;
  const mxArray *c13_j_y = NULL;
  const mxArray *c13_k_y = NULL;
  const mxArray *c13_st;
  const mxArray *c13_y = NULL;
  c13_st = NULL;
  c13_st = NULL;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_createcellmatrix(10, 1), false);
  c13_b_y = NULL;
  sf_mex_assign(&c13_b_y, sf_mex_create("y", *chartInstance->c13_accel, 0, 0U,
    1U, 0U, 2, 3, 1), false);
  sf_mex_setcell(c13_y, 0, c13_b_y);
  c13_c_y = NULL;
  sf_mex_assign(&c13_c_y, sf_mex_create("y", *chartInstance->c13_accel_bias, 0,
    0U, 1U, 0U, 2, 3, 1), false);
  sf_mex_setcell(c13_y, 1, c13_c_y);
  c13_d_y = NULL;
  sf_mex_assign(&c13_d_y, sf_mex_create("y", *chartInstance->c13_ang, 0, 0U, 1U,
    0U, 2, 4, 1), false);
  sf_mex_setcell(c13_y, 2, c13_d_y);
  c13_e_y = NULL;
  sf_mex_assign(&c13_e_y, sf_mex_create("y", *chartInstance->c13_angvel, 0, 0U,
    1U, 0U, 1, 3), false);
  sf_mex_setcell(c13_y, 3, c13_e_y);
  c13_f_y = NULL;
  sf_mex_assign(&c13_f_y, sf_mex_create("y", *chartInstance->c13_gyro_bias, 0,
    0U, 1U, 0U, 2, 3, 1), false);
  sf_mex_setcell(c13_y, 4, c13_f_y);
  c13_g_y = NULL;
  sf_mex_assign(&c13_g_y, sf_mex_create("y", *chartInstance->c13_mag, 0, 0U, 1U,
    0U, 2, 3, 1), false);
  sf_mex_setcell(c13_y, 5, c13_g_y);
  c13_h_y = NULL;
  sf_mex_assign(&c13_h_y, sf_mex_create("y", *chartInstance->c13_mag_bias, 0, 0U,
    1U, 0U, 2, 3, 1), false);
  sf_mex_setcell(c13_y, 6, c13_h_y);
  c13_i_y = NULL;
  sf_mex_assign(&c13_i_y, sf_mex_create("y", *chartInstance->c13_pos, 0, 0U, 1U,
    0U, 2, 3, 1), false);
  sf_mex_setcell(c13_y, 7, c13_i_y);
  c13_j_y = NULL;
  sf_mex_assign(&c13_j_y, sf_mex_create("y", *chartInstance->c13_vel, 0, 0U, 1U,
    0U, 1, 3), false);
  sf_mex_setcell(c13_y, 8, c13_j_y);
  c13_k_y = NULL;
  sf_mex_assign(&c13_k_y, sf_mex_create("y",
    &chartInstance->c13_is_active_c13_car_model_FIXED, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c13_y, 9, c13_k_y);
  sf_mex_assign(&c13_st, c13_y, false);
  return c13_st;
}

static void set_sim_state_c13_car_model_FIXED
  (SFc13_car_model_FIXEDInstanceStruct *chartInstance, const mxArray *c13_st)
{
  const mxArray *c13_u;
  real_T c13_dv2[4];
  real_T c13_dv[3];
  real_T c13_dv1[3];
  real_T c13_dv3[3];
  real_T c13_dv4[3];
  real_T c13_dv5[3];
  real_T c13_dv6[3];
  real_T c13_dv7[3];
  real_T c13_dv8[3];
  int32_T c13_i;
  int32_T c13_i1;
  int32_T c13_i2;
  int32_T c13_i3;
  int32_T c13_i4;
  int32_T c13_i5;
  int32_T c13_i6;
  int32_T c13_i7;
  int32_T c13_i8;
  chartInstance->c13_doneDoubleBufferReInit = true;
  c13_u = sf_mex_dup(c13_st);
  c13_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c13_u, 0)),
                       "accel", c13_dv);
  for (c13_i = 0; c13_i < 3; c13_i++) {
    (*chartInstance->c13_accel)[c13_i] = c13_dv[c13_i];
  }

  c13_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c13_u, 1)),
                       "accel_bias", c13_dv1);
  for (c13_i1 = 0; c13_i1 < 3; c13_i1++) {
    (*chartInstance->c13_accel_bias)[c13_i1] = c13_dv1[c13_i1];
  }

  c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c13_u, 2)),
    "ang", c13_dv2);
  for (c13_i2 = 0; c13_i2 < 4; c13_i2++) {
    (*chartInstance->c13_ang)[c13_i2] = c13_dv2[c13_i2];
  }

  c13_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c13_u, 3)),
    "angvel", c13_dv3);
  for (c13_i3 = 0; c13_i3 < 3; c13_i3++) {
    (*chartInstance->c13_angvel)[c13_i3] = c13_dv3[c13_i3];
  }

  c13_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c13_u, 4)),
                       "gyro_bias", c13_dv4);
  for (c13_i4 = 0; c13_i4 < 3; c13_i4++) {
    (*chartInstance->c13_gyro_bias)[c13_i4] = c13_dv4[c13_i4];
  }

  c13_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c13_u, 5)),
                       "mag", c13_dv5);
  for (c13_i5 = 0; c13_i5 < 3; c13_i5++) {
    (*chartInstance->c13_mag)[c13_i5] = c13_dv5[c13_i5];
  }

  c13_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c13_u, 6)),
                       "mag_bias", c13_dv6);
  for (c13_i6 = 0; c13_i6 < 3; c13_i6++) {
    (*chartInstance->c13_mag_bias)[c13_i6] = c13_dv6[c13_i6];
  }

  c13_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c13_u, 7)),
                       "pos", c13_dv7);
  for (c13_i7 = 0; c13_i7 < 3; c13_i7++) {
    (*chartInstance->c13_pos)[c13_i7] = c13_dv7[c13_i7];
  }

  c13_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c13_u, 8)),
    "vel", c13_dv8);
  for (c13_i8 = 0; c13_i8 < 3; c13_i8++) {
    (*chartInstance->c13_vel)[c13_i8] = c13_dv8[c13_i8];
  }

  chartInstance->c13_is_active_c13_car_model_FIXED = c13_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c13_u, 9)),
     "is_active_c13_car_model_FIXED");
  sf_mex_destroy(&c13_u);
  sf_mex_destroy(&c13_st);
}

static void initSimStructsc13_car_model_FIXED
  (SFc13_car_model_FIXEDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c13_emlrt_update_log_1(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c13_in[9], emlrtLocationLoggingDataType c13_table[],
  int32_T c13_index, real_T c13_out[9])
{
  int32_T c13_i;
  for (c13_i = 0; c13_i < 9; c13_i++) {
    c13_out[c13_i] = c13_in[c13_i];
  }

  c13_b_emlrt_update_log_1(chartInstance, c13_out, c13_table, c13_index);
}

static void c13_emlrt_update_log_2(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c13_in[28], emlrtLocationLoggingDataType c13_table[],
  int32_T c13_index, real_T c13_out[28])
{
  int32_T c13_i;
  for (c13_i = 0; c13_i < 28; c13_i++) {
    c13_out[c13_i] = c13_in[c13_i];
  }

  c13_b_emlrt_update_log_2(chartInstance, c13_out, c13_table, c13_index);
}

static void c13_emlrt_update_log_3(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c13_in[4], emlrtLocationLoggingDataType c13_table[],
  int32_T c13_index, real_T c13_out[4])
{
  int32_T c13_i;
  for (c13_i = 0; c13_i < 4; c13_i++) {
    c13_out[c13_i] = c13_in[c13_i];
  }

  c13_b_emlrt_update_log_3(chartInstance, c13_out, c13_table, c13_index);
}

static void c13_emlrt_update_log_4(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c13_in[3], emlrtLocationLoggingDataType c13_table[],
  int32_T c13_index, real_T c13_out[3])
{
  int32_T c13_i;
  for (c13_i = 0; c13_i < 3; c13_i++) {
    c13_out[c13_i] = c13_in[c13_i];
  }

  c13_b_emlrt_update_log_4(chartInstance, c13_out, c13_table, c13_index);
}

static void c13_emlrt_update_log_5(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c13_in[3], emlrtLocationLoggingDataType c13_table[],
  int32_T c13_index, real_T c13_out[3])
{
  int32_T c13_i;
  for (c13_i = 0; c13_i < 3; c13_i++) {
    c13_out[c13_i] = c13_in[c13_i];
  }

  c13_b_emlrt_update_log_5(chartInstance, c13_out, c13_table, c13_index);
}

static void c13_emlrtInitVarDataTables(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, emlrtLocationLoggingDataType c13_dataTables[14],
  emlrtLocationLoggingHistogramType c13_histTables[14])
{
  int32_T c13_i;
  int32_T c13_iH;
  (void)chartInstance;
  for (c13_i = 0; c13_i < 14; c13_i++) {
    c13_dataTables[c13_i].SimMin = rtInf;
    c13_dataTables[c13_i].SimMax = rtMinusInf;
    c13_dataTables[c13_i].OverflowWraps = 0;
    c13_dataTables[c13_i].Saturations = 0;
    c13_dataTables[c13_i].IsAlwaysInteger = true;
    c13_dataTables[c13_i].HistogramTable = &c13_histTables[c13_i];
    c13_histTables[c13_i].NumberOfZeros = 0.0;
    c13_histTables[c13_i].NumberOfPositiveValues = 0.0;
    c13_histTables[c13_i].NumberOfNegativeValues = 0.0;
    c13_histTables[c13_i].TotalNumberOfValues = 0.0;
    c13_histTables[c13_i].SimSum = 0.0;
    for (c13_iH = 0; c13_iH < 256; c13_iH++) {
      c13_histTables[c13_i].HistogramOfPositiveValues[c13_iH] = 0.0;
      c13_histTables[c13_i].HistogramOfNegativeValues[c13_iH] = 0.0;
    }
  }
}

const mxArray *sf_c13_car_model_FIXED_get_eml_resolved_functions_info(void)
{
  const mxArray *c13_nameCaptureInfo = NULL;
  c13_nameCaptureInfo = NULL;
  sf_mex_assign(&c13_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c13_nameCaptureInfo;
}

static void c13_emlrt_marshallIn(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c13_b_accel, const char_T *c13_identifier,
  real_T c13_y[3])
{
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = (const char_T *)c13_identifier;
  c13_thisId.fParent = NULL;
  c13_thisId.bParentIsCell = false;
  c13_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_accel), &c13_thisId,
    c13_y);
  sf_mex_destroy(&c13_b_accel);
}

static void c13_b_emlrt_marshallIn(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId,
  real_T c13_y[3])
{
  real_T c13_dv[3];
  int32_T c13_i;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), c13_dv, 1, 0, 0U, 1, 0U, 2, 3,
                1);
  for (c13_i = 0; c13_i < 3; c13_i++) {
    c13_y[c13_i] = c13_dv[c13_i];
  }

  sf_mex_destroy(&c13_u);
}

static void c13_c_emlrt_marshallIn(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c13_b_ang, const char_T *c13_identifier, real_T
  c13_y[4])
{
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = (const char_T *)c13_identifier;
  c13_thisId.fParent = NULL;
  c13_thisId.bParentIsCell = false;
  c13_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_ang), &c13_thisId,
    c13_y);
  sf_mex_destroy(&c13_b_ang);
}

static void c13_d_emlrt_marshallIn(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId,
  real_T c13_y[4])
{
  real_T c13_dv[4];
  int32_T c13_i;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), c13_dv, 1, 0, 0U, 1, 0U, 2, 4,
                1);
  for (c13_i = 0; c13_i < 4; c13_i++) {
    c13_y[c13_i] = c13_dv[c13_i];
  }

  sf_mex_destroy(&c13_u);
}

static void c13_e_emlrt_marshallIn(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c13_b_angvel, const char_T *c13_identifier,
  real_T c13_y[3])
{
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = (const char_T *)c13_identifier;
  c13_thisId.fParent = NULL;
  c13_thisId.bParentIsCell = false;
  c13_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_angvel), &c13_thisId,
    c13_y);
  sf_mex_destroy(&c13_b_angvel);
}

static void c13_f_emlrt_marshallIn(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId,
  real_T c13_y[3])
{
  real_T c13_dv[3];
  int32_T c13_i;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), c13_dv, 1, 0, 0U, 1, 0U, 1, 3);
  for (c13_i = 0; c13_i < 3; c13_i++) {
    c13_y[c13_i] = c13_dv[c13_i];
  }

  sf_mex_destroy(&c13_u);
}

static uint8_T c13_g_emlrt_marshallIn(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c13_b_is_active_c13_car_model_FIXED, const
  char_T *c13_identifier)
{
  emlrtMsgIdentifier c13_thisId;
  uint8_T c13_y;
  c13_thisId.fIdentifier = (const char_T *)c13_identifier;
  c13_thisId.fParent = NULL;
  c13_thisId.bParentIsCell = false;
  c13_y = c13_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c13_b_is_active_c13_car_model_FIXED), &c13_thisId);
  sf_mex_destroy(&c13_b_is_active_c13_car_model_FIXED);
  return c13_y;
}

static uint8_T c13_h_emlrt_marshallIn(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  uint8_T c13_b_u;
  uint8_T c13_y;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_b_u, 1, 3, 0U, 0, 0U, 0);
  c13_y = c13_b_u;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_slStringInitializeDynamicBuffers
  (SFc13_car_model_FIXEDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c13_chart_data_browse_helper(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, int32_T c13_ssIdNumber, const mxArray **c13_mxData, uint8_T
  *c13_isValueTooBig)
{
  *c13_mxData = NULL;
  *c13_mxData = NULL;
  *c13_isValueTooBig = 0U;
  switch (c13_ssIdNumber) {
   case 17U:
    sf_mex_assign(c13_mxData, sf_mex_create("mxData",
      *chartInstance->c13_rot_map, 0, 0U, 1U, 0U, 2, 3, 3), false);
    break;

   case 6U:
    sf_mex_assign(c13_mxData, sf_mex_create("mxData", *chartInstance->c13_state,
      0, 0U, 1U, 0U, 1, 28), false);
    break;

   case 5U:
    sf_mex_assign(c13_mxData, sf_mex_create("mxData", *chartInstance->c13_ang, 0,
      0U, 1U, 0U, 2, 4, 1), false);
    break;

   case 8U:
    sf_mex_assign(c13_mxData, sf_mex_create("mxData", *chartInstance->c13_angvel,
      0, 0U, 1U, 0U, 1, 3), false);
    break;

   case 11U:
    sf_mex_assign(c13_mxData, sf_mex_create("mxData", *chartInstance->c13_pos, 0,
      0U, 1U, 0U, 2, 3, 1), false);
    break;

   case 12U:
    sf_mex_assign(c13_mxData, sf_mex_create("mxData", *chartInstance->c13_vel, 0,
      0U, 1U, 0U, 1, 3), false);
    break;

   case 13U:
    sf_mex_assign(c13_mxData, sf_mex_create("mxData", *chartInstance->c13_accel,
      0, 0U, 1U, 0U, 2, 3, 1), false);
    break;

   case 9U:
    sf_mex_assign(c13_mxData, sf_mex_create("mxData", *chartInstance->c13_mag, 0,
      0U, 1U, 0U, 2, 3, 1), false);
    break;

   case 14U:
    sf_mex_assign(c13_mxData, sf_mex_create("mxData",
      *chartInstance->c13_accel_bias, 0, 0U, 1U, 0U, 2, 3, 1), false);
    break;

   case 15U:
    sf_mex_assign(c13_mxData, sf_mex_create("mxData",
      *chartInstance->c13_gyro_bias, 0, 0U, 1U, 0U, 2, 3, 1), false);
    break;

   case 16U:
    sf_mex_assign(c13_mxData, sf_mex_create("mxData",
      *chartInstance->c13_mag_bias, 0, 0U, 1U, 0U, 2, 3, 1), false);
    break;
  }
}

static void c13_b_emlrt_update_log_1(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c13_in[9], emlrtLocationLoggingDataType c13_table[],
  int32_T c13_index)
{
  emlrtLocationLoggingDataType *c13_b_table;
  emlrtLocationLoggingHistogramType *c13_histTable;
  real_T c13_inDouble;
  real_T c13_localMax;
  real_T c13_localMin;
  real_T c13_significand;
  int32_T c13_b_i;
  int32_T c13_exponent;
  int32_T c13_i;
  boolean_T c13_isLoggingEnabledHere;
  (void)chartInstance;
  c13_isLoggingEnabledHere = (c13_index >= 0);
  if (c13_isLoggingEnabledHere) {
    c13_b_table = (emlrtLocationLoggingDataType *)&c13_table[c13_index];
    c13_localMin = c13_b_table[0U].SimMin;
    c13_localMax = c13_b_table[0U].SimMax;
    c13_histTable = c13_b_table[0U].HistogramTable;
    for (c13_i = 0; c13_i < 9; c13_i++) {
      /* Simulation Min-Max logging. */
      if (c13_in[c13_i] < c13_localMin) {
        c13_localMin = c13_in[c13_i];
      }

      if (c13_in[c13_i] > c13_localMax) {
        c13_localMax = c13_in[c13_i];
      }

      /* Histogram logging. */
      c13_inDouble = c13_in[c13_i];
      c13_histTable->TotalNumberOfValues++;
      if (c13_inDouble == 0.0) {
        c13_histTable->NumberOfZeros++;
      } else {
        c13_histTable->SimSum += c13_inDouble;
        if ((!muDoubleScalarIsInf(c13_inDouble)) && (!muDoubleScalarIsNaN
             (c13_inDouble))) {
          c13_significand = frexp(c13_inDouble, &c13_exponent);
          if (c13_exponent > 128) {
            c13_exponent = 128;
          }

          if (c13_exponent < -127) {
            c13_exponent = -127;
          }

          if (c13_significand < 0.0) {
            c13_histTable->NumberOfNegativeValues++;
            c13_histTable->HistogramOfNegativeValues[127 + c13_exponent]++;
          } else {
            c13_histTable->NumberOfPositiveValues++;
            c13_histTable->HistogramOfPositiveValues[127 + c13_exponent]++;
          }
        }
      }
    }

    c13_b_table[0U].SimMin = c13_localMin;
    c13_b_table[0U].SimMax = c13_localMax;

    /* IsAlwaysInteger logging. */
    c13_b_i = 0;
    while (c13_b_table[0U].IsAlwaysInteger && (c13_b_i < 9)) {
      if (c13_in[c13_b_i] != muDoubleScalarFloor(c13_in[c13_b_i])) {
        c13_b_table[0U].IsAlwaysInteger = false;
      }

      c13_b_i++;
    }
  }
}

static void c13_b_emlrt_update_log_2(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c13_in[28], emlrtLocationLoggingDataType c13_table[],
  int32_T c13_index)
{
  emlrtLocationLoggingDataType *c13_b_table;
  emlrtLocationLoggingHistogramType *c13_histTable;
  real_T c13_inDouble;
  real_T c13_localMax;
  real_T c13_localMin;
  real_T c13_significand;
  int32_T c13_b_i;
  int32_T c13_exponent;
  int32_T c13_i;
  boolean_T c13_isLoggingEnabledHere;
  (void)chartInstance;
  c13_isLoggingEnabledHere = (c13_index >= 0);
  if (c13_isLoggingEnabledHere) {
    c13_b_table = (emlrtLocationLoggingDataType *)&c13_table[c13_index];
    c13_localMin = c13_b_table[0U].SimMin;
    c13_localMax = c13_b_table[0U].SimMax;
    c13_histTable = c13_b_table[0U].HistogramTable;
    for (c13_i = 0; c13_i < 28; c13_i++) {
      /* Simulation Min-Max logging. */
      if (c13_in[c13_i] < c13_localMin) {
        c13_localMin = c13_in[c13_i];
      }

      if (c13_in[c13_i] > c13_localMax) {
        c13_localMax = c13_in[c13_i];
      }

      /* Histogram logging. */
      c13_inDouble = c13_in[c13_i];
      c13_histTable->TotalNumberOfValues++;
      if (c13_inDouble == 0.0) {
        c13_histTable->NumberOfZeros++;
      } else {
        c13_histTable->SimSum += c13_inDouble;
        if ((!muDoubleScalarIsInf(c13_inDouble)) && (!muDoubleScalarIsNaN
             (c13_inDouble))) {
          c13_significand = frexp(c13_inDouble, &c13_exponent);
          if (c13_exponent > 128) {
            c13_exponent = 128;
          }

          if (c13_exponent < -127) {
            c13_exponent = -127;
          }

          if (c13_significand < 0.0) {
            c13_histTable->NumberOfNegativeValues++;
            c13_histTable->HistogramOfNegativeValues[127 + c13_exponent]++;
          } else {
            c13_histTable->NumberOfPositiveValues++;
            c13_histTable->HistogramOfPositiveValues[127 + c13_exponent]++;
          }
        }
      }
    }

    c13_b_table[0U].SimMin = c13_localMin;
    c13_b_table[0U].SimMax = c13_localMax;

    /* IsAlwaysInteger logging. */
    c13_b_i = 0;
    while (c13_b_table[0U].IsAlwaysInteger && (c13_b_i < 28)) {
      if (c13_in[c13_b_i] != muDoubleScalarFloor(c13_in[c13_b_i])) {
        c13_b_table[0U].IsAlwaysInteger = false;
      }

      c13_b_i++;
    }
  }
}

static void c13_b_emlrt_update_log_3(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c13_in[4], emlrtLocationLoggingDataType c13_table[],
  int32_T c13_index)
{
  emlrtLocationLoggingDataType *c13_b_table;
  emlrtLocationLoggingHistogramType *c13_histTable;
  real_T c13_inDouble;
  real_T c13_localMax;
  real_T c13_localMin;
  real_T c13_significand;
  int32_T c13_b_i;
  int32_T c13_exponent;
  int32_T c13_i;
  boolean_T c13_isLoggingEnabledHere;
  (void)chartInstance;
  c13_isLoggingEnabledHere = (c13_index >= 0);
  if (c13_isLoggingEnabledHere) {
    c13_b_table = (emlrtLocationLoggingDataType *)&c13_table[c13_index];
    c13_localMin = c13_b_table[0U].SimMin;
    c13_localMax = c13_b_table[0U].SimMax;
    c13_histTable = c13_b_table[0U].HistogramTable;
    for (c13_i = 0; c13_i < 4; c13_i++) {
      /* Simulation Min-Max logging. */
      if (c13_in[c13_i] < c13_localMin) {
        c13_localMin = c13_in[c13_i];
      }

      if (c13_in[c13_i] > c13_localMax) {
        c13_localMax = c13_in[c13_i];
      }

      /* Histogram logging. */
      c13_inDouble = c13_in[c13_i];
      c13_histTable->TotalNumberOfValues++;
      if (c13_inDouble == 0.0) {
        c13_histTable->NumberOfZeros++;
      } else {
        c13_histTable->SimSum += c13_inDouble;
        if ((!muDoubleScalarIsInf(c13_inDouble)) && (!muDoubleScalarIsNaN
             (c13_inDouble))) {
          c13_significand = frexp(c13_inDouble, &c13_exponent);
          if (c13_exponent > 128) {
            c13_exponent = 128;
          }

          if (c13_exponent < -127) {
            c13_exponent = -127;
          }

          if (c13_significand < 0.0) {
            c13_histTable->NumberOfNegativeValues++;
            c13_histTable->HistogramOfNegativeValues[127 + c13_exponent]++;
          } else {
            c13_histTable->NumberOfPositiveValues++;
            c13_histTable->HistogramOfPositiveValues[127 + c13_exponent]++;
          }
        }
      }
    }

    c13_b_table[0U].SimMin = c13_localMin;
    c13_b_table[0U].SimMax = c13_localMax;

    /* IsAlwaysInteger logging. */
    c13_b_i = 0;
    while (c13_b_table[0U].IsAlwaysInteger && (c13_b_i < 4)) {
      if (c13_in[c13_b_i] != muDoubleScalarFloor(c13_in[c13_b_i])) {
        c13_b_table[0U].IsAlwaysInteger = false;
      }

      c13_b_i++;
    }
  }
}

static void c13_b_emlrt_update_log_4(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c13_in[3], emlrtLocationLoggingDataType c13_table[],
  int32_T c13_index)
{
  emlrtLocationLoggingDataType *c13_b_table;
  emlrtLocationLoggingHistogramType *c13_histTable;
  real_T c13_inDouble;
  real_T c13_localMax;
  real_T c13_localMin;
  real_T c13_significand;
  int32_T c13_b_i;
  int32_T c13_exponent;
  int32_T c13_i;
  boolean_T c13_isLoggingEnabledHere;
  (void)chartInstance;
  c13_isLoggingEnabledHere = (c13_index >= 0);
  if (c13_isLoggingEnabledHere) {
    c13_b_table = (emlrtLocationLoggingDataType *)&c13_table[c13_index];
    c13_localMin = c13_b_table[0U].SimMin;
    c13_localMax = c13_b_table[0U].SimMax;
    c13_histTable = c13_b_table[0U].HistogramTable;
    for (c13_i = 0; c13_i < 3; c13_i++) {
      /* Simulation Min-Max logging. */
      if (c13_in[c13_i] < c13_localMin) {
        c13_localMin = c13_in[c13_i];
      }

      if (c13_in[c13_i] > c13_localMax) {
        c13_localMax = c13_in[c13_i];
      }

      /* Histogram logging. */
      c13_inDouble = c13_in[c13_i];
      c13_histTable->TotalNumberOfValues++;
      if (c13_inDouble == 0.0) {
        c13_histTable->NumberOfZeros++;
      } else {
        c13_histTable->SimSum += c13_inDouble;
        if ((!muDoubleScalarIsInf(c13_inDouble)) && (!muDoubleScalarIsNaN
             (c13_inDouble))) {
          c13_significand = frexp(c13_inDouble, &c13_exponent);
          if (c13_exponent > 128) {
            c13_exponent = 128;
          }

          if (c13_exponent < -127) {
            c13_exponent = -127;
          }

          if (c13_significand < 0.0) {
            c13_histTable->NumberOfNegativeValues++;
            c13_histTable->HistogramOfNegativeValues[127 + c13_exponent]++;
          } else {
            c13_histTable->NumberOfPositiveValues++;
            c13_histTable->HistogramOfPositiveValues[127 + c13_exponent]++;
          }
        }
      }
    }

    c13_b_table[0U].SimMin = c13_localMin;
    c13_b_table[0U].SimMax = c13_localMax;

    /* IsAlwaysInteger logging. */
    c13_b_i = 0;
    while (c13_b_table[0U].IsAlwaysInteger && (c13_b_i < 3)) {
      if (c13_in[c13_b_i] != muDoubleScalarFloor(c13_in[c13_b_i])) {
        c13_b_table[0U].IsAlwaysInteger = false;
      }

      c13_b_i++;
    }
  }
}

static void c13_b_emlrt_update_log_5(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c13_in[3], emlrtLocationLoggingDataType c13_table[],
  int32_T c13_index)
{
  emlrtLocationLoggingDataType *c13_b_table;
  emlrtLocationLoggingHistogramType *c13_histTable;
  real_T c13_inDouble;
  real_T c13_localMax;
  real_T c13_localMin;
  real_T c13_significand;
  int32_T c13_b_i;
  int32_T c13_exponent;
  int32_T c13_i;
  boolean_T c13_isLoggingEnabledHere;
  (void)chartInstance;
  c13_isLoggingEnabledHere = (c13_index >= 0);
  if (c13_isLoggingEnabledHere) {
    c13_b_table = (emlrtLocationLoggingDataType *)&c13_table[c13_index];
    c13_localMin = c13_b_table[0U].SimMin;
    c13_localMax = c13_b_table[0U].SimMax;
    c13_histTable = c13_b_table[0U].HistogramTable;
    for (c13_i = 0; c13_i < 3; c13_i++) {
      /* Simulation Min-Max logging. */
      if (c13_in[c13_i] < c13_localMin) {
        c13_localMin = c13_in[c13_i];
      }

      if (c13_in[c13_i] > c13_localMax) {
        c13_localMax = c13_in[c13_i];
      }

      /* Histogram logging. */
      c13_inDouble = c13_in[c13_i];
      c13_histTable->TotalNumberOfValues++;
      if (c13_inDouble == 0.0) {
        c13_histTable->NumberOfZeros++;
      } else {
        c13_histTable->SimSum += c13_inDouble;
        if ((!muDoubleScalarIsInf(c13_inDouble)) && (!muDoubleScalarIsNaN
             (c13_inDouble))) {
          c13_significand = frexp(c13_inDouble, &c13_exponent);
          if (c13_exponent > 128) {
            c13_exponent = 128;
          }

          if (c13_exponent < -127) {
            c13_exponent = -127;
          }

          if (c13_significand < 0.0) {
            c13_histTable->NumberOfNegativeValues++;
            c13_histTable->HistogramOfNegativeValues[127 + c13_exponent]++;
          } else {
            c13_histTable->NumberOfPositiveValues++;
            c13_histTable->HistogramOfPositiveValues[127 + c13_exponent]++;
          }
        }
      }
    }

    c13_b_table[0U].SimMin = c13_localMin;
    c13_b_table[0U].SimMax = c13_localMax;

    /* IsAlwaysInteger logging. */
    c13_b_i = 0;
    while (c13_b_table[0U].IsAlwaysInteger && (c13_b_i < 3)) {
      if (c13_in[c13_b_i] != muDoubleScalarFloor(c13_in[c13_b_i])) {
        c13_b_table[0U].IsAlwaysInteger = false;
      }

      c13_b_i++;
    }
  }
}

static void init_dsm_address_info(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc13_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  chartInstance->c13_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c13_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c13_rot_map = (real_T (*)[9])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c13_state = (real_T (*)[28])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c13_ang = (real_T (*)[4])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c13_angvel = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c13_pos = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c13_vel = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c13_accel = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c13_mag = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c13_accel_bias = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c13_gyro_bias = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c13_mag_bias = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 9);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c13_car_model_FIXED_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3105237764U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1318023411U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1901579207U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1716963015U);
}

mxArray *sf_c13_car_model_FIXED_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c13_car_model_FIXED_jit_fallback_info(void)
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

mxArray *sf_c13_car_model_FIXED_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c13_car_model_FIXED(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiA24GBgYAPSQIqBiQECWKF8RiDmgtIQcRa4uAIQl1QWpILEi4uSPVOAdF5iLpi"
    "fWFrhmZeWDzbfggFhPhsW8xmRzOeEikPAB3vK9Gs5oOtnwaKfFUm/AJSfmJycmgMNH1g4DZw/dM"
    "D+cCDgDy40f3DB/BGflJlYjPDHwPtHBOwfAwL+YUbxDzNDYl76IHG/AlHpig0tPkB8oB/KQAlrc"
    "PhDj6h0xYnmDxA/vbIoHylZDRL/KJGVrnITB0u6MiAqXXGgxQeID/QDODoGhz/UyIqHgvziQRIP"
    "GmS5H5SxqeN+zPKFNP0Q+wMIuF8WLR2B+JnF8YnJJZllqfHJhsbxyYlF8bn5KcAaxM0zwtUFKZ8"
    "DAKioRpA="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c13_car_model_FIXED_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sZlgZrK2rX9XADtpnHOYTN";
}

static void sf_opaque_initialize_c13_car_model_FIXED(void *chartInstanceVar)
{
  initialize_params_c13_car_model_FIXED((SFc13_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
  initialize_c13_car_model_FIXED((SFc13_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c13_car_model_FIXED(void *chartInstanceVar)
{
  enable_c13_car_model_FIXED((SFc13_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c13_car_model_FIXED(void *chartInstanceVar)
{
  disable_c13_car_model_FIXED((SFc13_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c13_car_model_FIXED(void *chartInstanceVar)
{
  sf_gateway_c13_car_model_FIXED((SFc13_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c13_car_model_FIXED(SimStruct* S)
{
  return get_sim_state_c13_car_model_FIXED((SFc13_car_model_FIXEDInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c13_car_model_FIXED(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c13_car_model_FIXED((SFc13_car_model_FIXEDInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c13_car_model_FIXED(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc13_car_model_FIXEDInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_car_model_FIXED_optimization_info();
    }

    mdl_cleanup_runtime_resources_c13_car_model_FIXED
      ((SFc13_car_model_FIXEDInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c13_car_model_FIXED(void *chartInstanceVar)
{
  mdl_start_c13_car_model_FIXED((SFc13_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_mdl_terminate_c13_car_model_FIXED(void *chartInstanceVar)
{
  mdl_terminate_c13_car_model_FIXED((SFc13_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc13_car_model_FIXED((SFc13_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c13_car_model_FIXED(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  sf_warn_if_symbolic_dimension_param_changed(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c13_car_model_FIXED((SFc13_car_model_FIXEDInstanceStruct*)
      sf_get_chart_instance_ptr(S));
    initSimStructsc13_car_model_FIXED((SFc13_car_model_FIXEDInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c13_car_model_FIXED_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [24] = {
    "eNrtWU1vG0UYXqdplECJIvF1oWrFAVUIUJsKCSQESfxBLZImYp005GJNdl/vjjw7u52ZtWPElT/",
    "AjV+AOHPlCBJ/AKnH/gROiCPv7K5dd23iGaclLmIjezO7+8z7Mc/7MWun0txz8FjHz283HGcFz6",
    "v4WXLy42oxrox98uvLzifF+JuXHceLfQiAu2mnQ88cu4On0QERJJKO/cFJBF+CjFmqaMybvBObY",
    "ynvgADu4QRJLJSVXEmjlFHebaTc05Llg5B6oRvGKfN3cELi73M2+Ce5SaoOUGKNCvBUA8BXoYjT",
    "IGwwEpzvBaH61RC8rkwja19JUG6aaFPlXsoUTRjUz8BrcqkIekHOsNdVREFVndk5Wdsr3SE6jhJ",
    "GCTf3dUikCwmyQ8Fh4uP3fqrQe0ZYLyRC7UBIeiB3aTeTHnMwkk4lPn1KOVGxoITVI1bVsxnae8",
    "DQxj0MCWa7RmjvjgDSTWLKlWVAuA30c52TUwY1OE0DS7kuPEx1NBxR6IOwW99ONe6BIAHsczuds",
    "zWqn2WkHMWSIVbRCI6I2PaQuxJ8u7yBQSddgnSEFk5jhYXMxU3ZErSH3LDNdU0d/nPlujTK2S/n",
    "wmZy6z2w5tVIbsPjVcKYtMO24mQXesAy+TWiyBzYXL4FWErqt2Jkh842lhkr5RQjocBWY+5Tc1b",
    "2SqissN3HImUAp5EOA/DRzSPVRxPNiqNUqjiqYsqp7e4aypvENrkC0SEeGNcYQagEVDjjlaVcn0",
    "odSIhGL6nMSuMZ8hicC+rITspr/Vh00ce2xeyJr3Qk2KHBDzAxK8iSXB3ZfURYaqhzJAOMH6THo",
    "cQsaycXsTp+5gJ7xAvB15WTMtjDPIsTmC6x1CV/G63tUTWogfQETUwjKcWEjkVXe6k1SOCQd3nc",
    "5w0RR27ReZ3DKwDMGkRwyoMdLOFi0EDlzbQW8LCVZXfbJkf7mShGTjU3PgeO1VDbqrsG4mFU1Tm",
    "2yKjQRbAu/RqbGC6pVFioB3mpz+ue7t/vOU/69+Up/furY/37RjH27txte0S0I92stBvN43ptNN",
    "/tsfmuGewHTHDOBM4Z4YbnW2P4yhS5zti5LG9t6ennl0rylvCvUslxW2O4V0pylku4lcJnfz76/",
    "cG3P//069l33//w+MdfXp8lvzIhv5L9r3GPV+32W+vF+K1h3zTK0r2JRGbChzdKfNBjecKCE/HF",
    "pjj++Hi7phJ+b/+r1v3CzzP0famk7/D6Td2rYRBnOUF4Tb/Yt+kxSfP9hJ7/ozF9V2b4Y22MT47",
    "zx2cXw7+7VcZP89fVkr/0mGDzyUr8vTw73tsq83p5xjptFOPMjvYpJXIyHi/Pnte2yvE1zZ4rT9",
    "lzxSGYZRdD/5tGvFoprYceow09TazFsOMDI16tlezQ42Ag4jFaLYg9b8/Fq4gsCq9uG/FqtbQeq",
    "1mfEWTLsRh2vDPXOiSxXJB1uDWX/jqwn43+k/nFDp/LP5ih//USj65n73zaRHf20J7eQa4b9mfn",
    "9Ue2OOdfxr0oev7vl+dvn8n+aGlO3Npz3I89S9xF7bPd973oz59XN5zS8xsLbIdzTr632f8vml2",
    "PHLv9+Y1i/Ono/XM1pMyf8gasuL0LpDPt7n+E339Z+u/NYlzX/it+qDy5u80JG0iabyCGlw+E/r",
    "1pdEsAkdPfK15GPRmeZ+2XrpXiW4/7lPtxX75/Z/PDzYvUp78BStlJVg==",
    ""
  };

  static char newstr [1709] = "";
  newstr[0] = '\0';
  for (i = 0; i < 24; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c13_car_model_FIXED(SimStruct *S)
{
  const char* newstr = sf_c13_car_model_FIXED_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(1473632502U));
  ssSetChecksum1(S,(3316890757U));
  ssSetChecksum2(S,(2811859576U));
  ssSetChecksum3(S,(365210080U));
}

static void mdlRTW_c13_car_model_FIXED(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c13_car_model_FIXED(SimStruct *S)
{
  SFc13_car_model_FIXEDInstanceStruct *chartInstance;
  chartInstance = (SFc13_car_model_FIXEDInstanceStruct *)utMalloc(sizeof
    (SFc13_car_model_FIXEDInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc13_car_model_FIXEDInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c13_car_model_FIXED;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c13_car_model_FIXED;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c13_car_model_FIXED;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c13_car_model_FIXED;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c13_car_model_FIXED;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c13_car_model_FIXED;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c13_car_model_FIXED;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c13_car_model_FIXED;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c13_car_model_FIXED;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c13_car_model_FIXED;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c13_car_model_FIXED;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c13_car_model_FIXED;
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
    chartInstance->c13_JITStateAnimation,
    chartInstance->c13_JITTransitionAnimation);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c13_car_model_FIXED(chartInstance);
}

void c13_car_model_FIXED_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c13_car_model_FIXED(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c13_car_model_FIXED(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c13_car_model_FIXED(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c13_car_model_FIXED_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
