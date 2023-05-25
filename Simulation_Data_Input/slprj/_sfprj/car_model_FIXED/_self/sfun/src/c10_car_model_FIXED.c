/* Include files */

#include "car_model_FIXED_sfun.h"
#include "c10_car_model_FIXED.h"
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
static void initialize_c10_car_model_FIXED(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance);
static void initialize_params_c10_car_model_FIXED
  (SFc10_car_model_FIXEDInstanceStruct *chartInstance);
static void mdl_start_c10_car_model_FIXED(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance);
static void mdl_terminate_c10_car_model_FIXED
  (SFc10_car_model_FIXEDInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c10_car_model_FIXED
  (SFc10_car_model_FIXEDInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c10_car_model_FIXED
  (SFc10_car_model_FIXEDInstanceStruct *chartInstance);
static void enable_c10_car_model_FIXED(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance);
static void disable_c10_car_model_FIXED(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance);
static void sf_gateway_c10_car_model_FIXED(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance);
static void ext_mode_exec_c10_car_model_FIXED
  (SFc10_car_model_FIXEDInstanceStruct *chartInstance);
static void c10_update_jit_animation_c10_car_model_FIXED
  (SFc10_car_model_FIXEDInstanceStruct *chartInstance);
static void c10_do_animation_call_c10_car_model_FIXED
  (SFc10_car_model_FIXEDInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c10_car_model_FIXED
  (SFc10_car_model_FIXEDInstanceStruct *chartInstance);
static void set_sim_state_c10_car_model_FIXED
  (SFc10_car_model_FIXEDInstanceStruct *chartInstance, const mxArray *c10_st);
static void initSimStructsc10_car_model_FIXED
  (SFc10_car_model_FIXEDInstanceStruct *chartInstance);
static void c10_emlrt_update_log_1(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c10_in[3], emlrtLocationLoggingDataType c10_table[],
  int32_T c10_index, real_T c10_out[3]);
static c10_quaternion c10_emlrt_update_log_2(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance, c10_quaternion c10_in, emlrtLocationLoggingDataType c10_table[],
  int32_T c10_index);
static void c10_emlrt_update_log_3(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c10_in[4], emlrtLocationLoggingDataType c10_table[],
  int32_T c10_index, real_T c10_out[4]);
static void c10_emlrtInitVarDataTables(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance, emlrtLocationLoggingDataType c10_dataTables[6],
  emlrtLocationLoggingHistogramType c10_histTables[6]);
static void c10_emlrt_marshallIn(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c10_b_Orientation_c, const char_T
  *c10_identifier, real_T c10_y[4]);
static void c10_b_emlrt_marshallIn(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[4]);
static void c10_c_emlrt_marshallIn(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c10_c_Orientation_e, const char_T
  *c10_identifier, real_T c10_y[3]);
static void c10_d_emlrt_marshallIn(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[3]);
static uint8_T c10_e_emlrt_marshallIn(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c10_b_is_active_c10_car_model_FIXED, const
  char_T *c10_identifier);
static uint8_T c10_f_emlrt_marshallIn(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_slStringInitializeDynamicBuffers
  (SFc10_car_model_FIXEDInstanceStruct *chartInstance);
static void c10_chart_data_browse_helper(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance, int32_T c10_ssIdNumber, const mxArray **c10_mxData, uint8_T
  *c10_isValueTooBig);
static void c10_b_emlrt_update_log_1(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c10_in[3], emlrtLocationLoggingDataType c10_table[],
  int32_T c10_index);
static void c10_b_emlrt_update_log_2(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance, c10_quaternion *c10_in, emlrtLocationLoggingDataType
  c10_table[], int32_T c10_index);
static void c10_b_emlrt_update_log_3(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c10_in[4], emlrtLocationLoggingDataType c10_table[],
  int32_T c10_index);
static void init_dsm_address_info(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c10_car_model_FIXED(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
  chartInstance->c10_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c10_is_active_c10_car_model_FIXED = 0U;
  chartInstance->c10_emlrtLocLogSimulated = false;
  c10_emlrtInitVarDataTables(chartInstance,
    chartInstance->c10_emlrtLocationLoggingDataTables,
    chartInstance->c10_emlrtLocLogHistTables);
}

static void initialize_params_c10_car_model_FIXED
  (SFc10_car_model_FIXEDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_start_c10_car_model_FIXED(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void mdl_terminate_c10_car_model_FIXED
  (SFc10_car_model_FIXEDInstanceStruct *chartInstance)
{
  const emlrtLocationLoggingFileInfoType c10_emlrtLocationLoggingFileInfo = {
    "#car_model_FIXED:5450",           /* mexFileName */
    "Mon Apr 17 21:46:08 2023",        /* timestamp */
    "",                                /* buildDir */
    1,                                 /* numFcns */
    256                                /* numHistogramBins */
  };

  const emlrtLocationLoggingFunctionInfoType
    c10_emlrtLocationLoggingFunctionInfoTable[1] = { { "eML_blk_kernel",/* fcnName */
      1,                               /* fcnId */
      3                                /* numInstrPoints */
    } };

  const emlrtLocationLoggingLocationType c10_emlrtLocationInfo[5] = { { 1,/* MxInfoID */
      47,                              /* TextStart */
      13,                              /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      63,                              /* TextStart */
      13,                              /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      79,                              /* TextStart */
      50,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 5,                            /* MxInfoID */
      132,                             /* TextStart */
      13,                              /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 5,                            /* MxInfoID */
      148,                             /* TextStart */
      22,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    } };

  const int32_T c10_emlrtLocationLoggingFieldCounts[3] = { 0, 4, 0 };

  const char_T *c10_emlrtLocationLoggingFieldNames[4] = { "a", "b", "c", "d" };

  if (chartInstance->c10_emlrtLocLogSimulated) {
    emlrtLocationLoggingClearLog("#car_model_FIXED:5450");
    emlrtLocationLoggingPushLog(&c10_emlrtLocationLoggingFileInfo,
      &c10_emlrtLocationLoggingFunctionInfoTable[0],
      &chartInstance->c10_emlrtLocationLoggingDataTables[0],
      &c10_emlrtLocationInfo[0], NULL, 0U, &c10_emlrtLocationLoggingFieldCounts
      [0], &c10_emlrtLocationLoggingFieldNames[0]);
    addResultsToFPTRepository("#car_model_FIXED:5450");
  }
}

static void mdl_setup_runtime_resources_c10_car_model_FIXED
  (SFc10_car_model_FIXEDInstanceStruct *chartInstance)
{
  static const uint32_T c10_decisionTxtEndIdx = 0U;
  static const uint32_T c10_decisionTxtStartIdx = 0U;
  setDebuggerFlag(chartInstance->S, true);
  setDataBrowseFcn(chartInstance->S, (void *)&c10_chart_data_browse_helper);
  chartInstance->c10_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c10_RuntimeVar,
    &chartInstance->c10_IsDebuggerActive,
    &chartInstance->c10_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c10_mlFcnLineNumber, &chartInstance->c10_IsHeatMapPresent, 0);
  sim_mode_is_external(chartInstance->S);
  covrtCreateStateflowInstanceData(chartInstance->c10_covrtInstance, 1U, 0U, 1U,
    126U);
  covrtChartInitFcn(chartInstance->c10_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c10_covrtInstance, 0U, 0U, false, false,
                    false, 0U, &c10_decisionTxtStartIdx, &c10_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c10_covrtInstance, 0U, 0, NULL, NULL, 0U,
                    NULL);
  covrtEmlInitFcn(chartInstance->c10_covrtInstance, "", 4U, 0U, 1U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c10_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 176);
}

static void mdl_cleanup_runtime_resources_c10_car_model_FIXED
  (SFc10_car_model_FIXEDInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c10_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c10_covrtInstance);
}

static void enable_c10_car_model_FIXED(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c10_car_model_FIXED(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c10_car_model_FIXED(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  c10_quaternion c10_Orientation_q;
  real_T c10_ein[3];
  real_T c10_a;
  real_T c10_ab_x;
  real_T c10_b;
  real_T c10_b_qa;
  real_T c10_b_qb;
  real_T c10_b_qc;
  real_T c10_b_qd;
  real_T c10_b_x;
  real_T c10_bb_x;
  real_T c10_c;
  real_T c10_c_x;
  real_T c10_cb_x;
  real_T c10_d;
  real_T c10_d1;
  real_T c10_d2;
  real_T c10_d3;
  real_T c10_d_x;
  real_T c10_db_x;
  real_T c10_e_x;
  real_T c10_eb_x;
  real_T c10_f_x;
  real_T c10_fb_x;
  real_T c10_g_x;
  real_T c10_gb_x;
  real_T c10_h_x;
  real_T c10_hb_x;
  real_T c10_i_x;
  real_T c10_ib_x;
  real_T c10_j_x;
  real_T c10_jb_x;
  real_T c10_k_x;
  real_T c10_kb_x;
  real_T c10_l_x;
  real_T c10_lb_x;
  real_T c10_m_x;
  real_T c10_mb_x;
  real_T c10_n_x;
  real_T c10_nb_x;
  real_T c10_o_x;
  real_T c10_ob_x;
  real_T c10_p_x;
  real_T c10_pb_x;
  real_T c10_q_x;
  real_T c10_qa;
  real_T c10_qb;
  real_T c10_qb_x;
  real_T c10_qc;
  real_T c10_qd;
  real_T c10_r_x;
  real_T c10_rb_x;
  real_T c10_s_x;
  real_T c10_sb_x;
  real_T c10_t_x;
  real_T c10_tb_x;
  real_T c10_u_x;
  real_T c10_ub_x;
  real_T c10_v_x;
  real_T c10_vb_x;
  real_T c10_w_x;
  real_T c10_wb_x;
  real_T c10_x;
  real_T c10_x_x;
  real_T c10_y_x;
  int32_T c10_i;
  int32_T c10_i1;
  int32_T c10_i2;
  int32_T c10_i3;
  int32_T c10_i4;
  int32_T c10_i5;
  int32_T c10_i6;
  chartInstance->c10_JITTransitionAnimation[0] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  for (c10_i = 0; c10_i < 3; c10_i++) {
    covrtSigUpdateFcn(chartInstance->c10_covrtInstance, 0U,
                      (*chartInstance->c10_Orientation_e)[c10_i]);
  }

  chartInstance->c10_sfEvent = CALL_EVENT;

  /* logging input variable 'Orientation_e' for function 'eML_blk_kernel' */
  chartInstance->c10_emlrtLocLogSimulated = true;

  /* logging input variable 'Orientation_e' for function 'eML_blk_kernel' */
  for (c10_i1 = 0; c10_i1 < 3; c10_i1++) {
    c10_ein[c10_i1] = (*chartInstance->c10_Orientation_e)[c10_i1];
  }

  c10_b_emlrt_update_log_1(chartInstance, c10_ein,
    chartInstance->c10_emlrtLocationLoggingDataTables, 0);
  covrtEmlFcnEval(chartInstance->c10_covrtInstance, 4U, 0, 0);
  for (c10_i2 = 0; c10_i2 < 3; c10_i2++) {
    c10_ein[c10_i2] = (*chartInstance->c10_Orientation_e)[c10_i2];
  }

  for (c10_i3 = 0; c10_i3 < 3; c10_i3++) {
    c10_ein[c10_i3] /= 2.0;
  }

  c10_a = c10_ein[0];
  c10_b = c10_ein[1];
  c10_c = c10_ein[2];
  c10_x = c10_a;
  c10_b_x = c10_x;
  c10_b_x = muDoubleScalarCos(c10_b_x);
  c10_c_x = c10_b;
  c10_d_x = c10_c_x;
  c10_d_x = muDoubleScalarCos(c10_d_x);
  c10_e_x = c10_c;
  c10_f_x = c10_e_x;
  c10_f_x = muDoubleScalarCos(c10_f_x);
  c10_g_x = c10_a;
  c10_h_x = c10_g_x;
  c10_h_x = muDoubleScalarSin(c10_h_x);
  c10_i_x = c10_b;
  c10_j_x = c10_i_x;
  c10_j_x = muDoubleScalarSin(c10_j_x);
  c10_k_x = c10_c;
  c10_l_x = c10_k_x;
  c10_l_x = muDoubleScalarSin(c10_l_x);
  c10_qa = c10_b_x * c10_d_x * c10_f_x - c10_h_x * c10_j_x * c10_l_x;
  c10_m_x = c10_b;
  c10_n_x = c10_m_x;
  c10_n_x = muDoubleScalarCos(c10_n_x);
  c10_o_x = c10_c;
  c10_p_x = c10_o_x;
  c10_p_x = muDoubleScalarCos(c10_p_x);
  c10_q_x = c10_a;
  c10_r_x = c10_q_x;
  c10_r_x = muDoubleScalarSin(c10_r_x);
  c10_s_x = c10_a;
  c10_t_x = c10_s_x;
  c10_t_x = muDoubleScalarCos(c10_t_x);
  c10_u_x = c10_b;
  c10_v_x = c10_u_x;
  c10_v_x = muDoubleScalarSin(c10_v_x);
  c10_w_x = c10_c;
  c10_x_x = c10_w_x;
  c10_x_x = muDoubleScalarSin(c10_x_x);
  c10_qb = c10_n_x * c10_p_x * c10_r_x + c10_t_x * c10_v_x * c10_x_x;
  c10_y_x = c10_a;
  c10_ab_x = c10_y_x;
  c10_ab_x = muDoubleScalarCos(c10_ab_x);
  c10_bb_x = c10_c;
  c10_cb_x = c10_bb_x;
  c10_cb_x = muDoubleScalarCos(c10_cb_x);
  c10_db_x = c10_b;
  c10_eb_x = c10_db_x;
  c10_eb_x = muDoubleScalarSin(c10_eb_x);
  c10_fb_x = c10_b;
  c10_gb_x = c10_fb_x;
  c10_gb_x = muDoubleScalarCos(c10_gb_x);
  c10_hb_x = c10_a;
  c10_ib_x = c10_hb_x;
  c10_ib_x = muDoubleScalarSin(c10_ib_x);
  c10_jb_x = c10_c;
  c10_kb_x = c10_jb_x;
  c10_kb_x = muDoubleScalarSin(c10_kb_x);
  c10_qc = c10_ab_x * c10_cb_x * c10_eb_x - c10_gb_x * c10_ib_x * c10_kb_x;
  c10_lb_x = c10_a;
  c10_mb_x = c10_lb_x;
  c10_mb_x = muDoubleScalarCos(c10_mb_x);
  c10_nb_x = c10_b;
  c10_ob_x = c10_nb_x;
  c10_ob_x = muDoubleScalarCos(c10_ob_x);
  c10_pb_x = c10_c;
  c10_qb_x = c10_pb_x;
  c10_qb_x = muDoubleScalarSin(c10_qb_x);
  c10_rb_x = c10_c;
  c10_sb_x = c10_rb_x;
  c10_sb_x = muDoubleScalarCos(c10_sb_x);
  c10_tb_x = c10_a;
  c10_ub_x = c10_tb_x;
  c10_ub_x = muDoubleScalarSin(c10_ub_x);
  c10_vb_x = c10_b;
  c10_wb_x = c10_vb_x;
  c10_wb_x = muDoubleScalarSin(c10_wb_x);
  c10_qd = c10_mb_x * c10_ob_x * c10_qb_x + c10_sb_x * c10_ub_x * c10_wb_x;
  c10_b_qa = c10_qa;
  c10_b_qb = c10_qb;
  c10_b_qc = c10_qc;
  c10_b_qd = c10_qd;
  c10_d = c10_b_qa;
  c10_d1 = c10_b_qb;
  c10_d2 = c10_b_qc;
  c10_d3 = c10_b_qd;
  c10_Orientation_q.a = c10_d;
  c10_Orientation_q.b = c10_d1;
  c10_Orientation_q.c = c10_d2;
  c10_Orientation_q.d = c10_d3;
  c10_b_emlrt_update_log_2(chartInstance, &c10_Orientation_q,
    chartInstance->c10_emlrtLocationLoggingDataTables, 1);
  (*chartInstance->c10_Orientation_c)[0] = c10_Orientation_q.a;
  (*chartInstance->c10_Orientation_c)[1] = c10_Orientation_q.b;
  (*chartInstance->c10_Orientation_c)[2] = c10_Orientation_q.c;
  (*chartInstance->c10_Orientation_c)[3] = c10_Orientation_q.d;
  c10_b_emlrt_update_log_3(chartInstance, *chartInstance->c10_Orientation_c,
    chartInstance->c10_emlrtLocationLoggingDataTables, 5);
  for (c10_i4 = 0; c10_i4 < 3; c10_i4++) {
    (*chartInstance->c10_b_Orientation_e)[c10_i4] =
      (*chartInstance->c10_Orientation_e)[c10_i4];
  }

  c10_do_animation_call_c10_car_model_FIXED(chartInstance);
  for (c10_i5 = 0; c10_i5 < 4; c10_i5++) {
    covrtSigUpdateFcn(chartInstance->c10_covrtInstance, 1U,
                      (*chartInstance->c10_Orientation_c)[c10_i5]);
  }

  for (c10_i6 = 0; c10_i6 < 3; c10_i6++) {
    covrtSigUpdateFcn(chartInstance->c10_covrtInstance, 2U,
                      (*chartInstance->c10_b_Orientation_e)[c10_i6]);
  }
}

static void ext_mode_exec_c10_car_model_FIXED
  (SFc10_car_model_FIXEDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c10_update_jit_animation_c10_car_model_FIXED
  (SFc10_car_model_FIXEDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c10_do_animation_call_c10_car_model_FIXED
  (SFc10_car_model_FIXEDInstanceStruct *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static const mxArray *get_sim_state_c10_car_model_FIXED
  (SFc10_car_model_FIXEDInstanceStruct *chartInstance)
{
  const mxArray *c10_b_y = NULL;
  const mxArray *c10_c_y = NULL;
  const mxArray *c10_d_y = NULL;
  const mxArray *c10_st;
  const mxArray *c10_y = NULL;
  c10_st = NULL;
  c10_st = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_createcellmatrix(3, 1), false);
  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", *chartInstance->c10_Orientation_c,
    0, 0U, 1U, 0U, 2, 1, 4), false);
  sf_mex_setcell(c10_y, 0, c10_b_y);
  c10_c_y = NULL;
  sf_mex_assign(&c10_c_y, sf_mex_create("y", *chartInstance->c10_b_Orientation_e,
    0, 0U, 1U, 0U, 2, 1, 3), false);
  sf_mex_setcell(c10_y, 1, c10_c_y);
  c10_d_y = NULL;
  sf_mex_assign(&c10_d_y, sf_mex_create("y",
    &chartInstance->c10_is_active_c10_car_model_FIXED, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c10_y, 2, c10_d_y);
  sf_mex_assign(&c10_st, c10_y, false);
  return c10_st;
}

static void set_sim_state_c10_car_model_FIXED
  (SFc10_car_model_FIXEDInstanceStruct *chartInstance, const mxArray *c10_st)
{
  const mxArray *c10_u;
  real_T c10_dv[4];
  real_T c10_dv1[3];
  int32_T c10_i;
  int32_T c10_i1;
  chartInstance->c10_doneDoubleBufferReInit = true;
  c10_u = sf_mex_dup(c10_st);
  c10_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 0)),
                       "Orientation_c", c10_dv);
  for (c10_i = 0; c10_i < 4; c10_i++) {
    (*chartInstance->c10_Orientation_c)[c10_i] = c10_dv[c10_i];
  }

  c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 1)),
    "Orientation_e", c10_dv1);
  for (c10_i1 = 0; c10_i1 < 3; c10_i1++) {
    (*chartInstance->c10_b_Orientation_e)[c10_i1] = c10_dv1[c10_i1];
  }

  chartInstance->c10_is_active_c10_car_model_FIXED = c10_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 2)),
     "is_active_c10_car_model_FIXED");
  sf_mex_destroy(&c10_u);
  sf_mex_destroy(&c10_st);
}

static void initSimStructsc10_car_model_FIXED
  (SFc10_car_model_FIXEDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c10_emlrt_update_log_1(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c10_in[3], emlrtLocationLoggingDataType c10_table[],
  int32_T c10_index, real_T c10_out[3])
{
  int32_T c10_i;
  for (c10_i = 0; c10_i < 3; c10_i++) {
    c10_out[c10_i] = c10_in[c10_i];
  }

  c10_b_emlrt_update_log_1(chartInstance, c10_out, c10_table, c10_index);
}

static c10_quaternion c10_emlrt_update_log_2(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance, c10_quaternion c10_in, emlrtLocationLoggingDataType c10_table[],
  int32_T c10_index)
{
  c10_quaternion c10_out;
  c10_out = c10_in;
  c10_b_emlrt_update_log_2(chartInstance, &c10_out, c10_table, c10_index);
  return c10_out;
}

static void c10_emlrt_update_log_3(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c10_in[4], emlrtLocationLoggingDataType c10_table[],
  int32_T c10_index, real_T c10_out[4])
{
  int32_T c10_i;
  for (c10_i = 0; c10_i < 4; c10_i++) {
    c10_out[c10_i] = c10_in[c10_i];
  }

  c10_b_emlrt_update_log_3(chartInstance, c10_out, c10_table, c10_index);
}

static void c10_emlrtInitVarDataTables(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance, emlrtLocationLoggingDataType c10_dataTables[6],
  emlrtLocationLoggingHistogramType c10_histTables[6])
{
  int32_T c10_i;
  int32_T c10_iH;
  (void)chartInstance;
  for (c10_i = 0; c10_i < 6; c10_i++) {
    c10_dataTables[c10_i].SimMin = rtInf;
    c10_dataTables[c10_i].SimMax = rtMinusInf;
    c10_dataTables[c10_i].OverflowWraps = 0;
    c10_dataTables[c10_i].Saturations = 0;
    c10_dataTables[c10_i].IsAlwaysInteger = true;
    c10_dataTables[c10_i].HistogramTable = &c10_histTables[c10_i];
    c10_histTables[c10_i].NumberOfZeros = 0.0;
    c10_histTables[c10_i].NumberOfPositiveValues = 0.0;
    c10_histTables[c10_i].NumberOfNegativeValues = 0.0;
    c10_histTables[c10_i].TotalNumberOfValues = 0.0;
    c10_histTables[c10_i].SimSum = 0.0;
    for (c10_iH = 0; c10_iH < 256; c10_iH++) {
      c10_histTables[c10_i].HistogramOfPositiveValues[c10_iH] = 0.0;
      c10_histTables[c10_i].HistogramOfNegativeValues[c10_iH] = 0.0;
    }
  }
}

const mxArray *sf_c10_car_model_FIXED_get_eml_resolved_functions_info(void)
{
  const mxArray *c10_nameCaptureInfo = NULL;
  c10_nameCaptureInfo = NULL;
  sf_mex_assign(&c10_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c10_nameCaptureInfo;
}

static void c10_emlrt_marshallIn(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c10_b_Orientation_c, const char_T
  *c10_identifier, real_T c10_y[4])
{
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = (const char_T *)c10_identifier;
  c10_thisId.fParent = NULL;
  c10_thisId.bParentIsCell = false;
  c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_Orientation_c),
    &c10_thisId, c10_y);
  sf_mex_destroy(&c10_b_Orientation_c);
}

static void c10_b_emlrt_marshallIn(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[4])
{
  real_T c10_dv[4];
  int32_T c10_i;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_dv, 1, 0, 0U, 1, 0U, 2, 1,
                4);
  for (c10_i = 0; c10_i < 4; c10_i++) {
    c10_y[c10_i] = c10_dv[c10_i];
  }

  sf_mex_destroy(&c10_u);
}

static void c10_c_emlrt_marshallIn(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c10_c_Orientation_e, const char_T
  *c10_identifier, real_T c10_y[3])
{
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = (const char_T *)c10_identifier;
  c10_thisId.fParent = NULL;
  c10_thisId.bParentIsCell = false;
  c10_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_c_Orientation_e),
    &c10_thisId, c10_y);
  sf_mex_destroy(&c10_c_Orientation_e);
}

static void c10_d_emlrt_marshallIn(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[3])
{
  real_T c10_dv[3];
  int32_T c10_i;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_dv, 1, 0, 0U, 1, 0U, 2, 1,
                3);
  for (c10_i = 0; c10_i < 3; c10_i++) {
    c10_y[c10_i] = c10_dv[c10_i];
  }

  sf_mex_destroy(&c10_u);
}

static uint8_T c10_e_emlrt_marshallIn(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c10_b_is_active_c10_car_model_FIXED, const
  char_T *c10_identifier)
{
  emlrtMsgIdentifier c10_thisId;
  uint8_T c10_y;
  c10_thisId.fIdentifier = (const char_T *)c10_identifier;
  c10_thisId.fParent = NULL;
  c10_thisId.bParentIsCell = false;
  c10_y = c10_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c10_b_is_active_c10_car_model_FIXED), &c10_thisId);
  sf_mex_destroy(&c10_b_is_active_c10_car_model_FIXED);
  return c10_y;
}

static uint8_T c10_f_emlrt_marshallIn(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  uint8_T c10_b_u;
  uint8_T c10_y;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_b_u, 1, 3, 0U, 0, 0U, 0);
  c10_y = c10_b_u;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_slStringInitializeDynamicBuffers
  (SFc10_car_model_FIXEDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c10_chart_data_browse_helper(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance, int32_T c10_ssIdNumber, const mxArray **c10_mxData, uint8_T
  *c10_isValueTooBig)
{
  *c10_mxData = NULL;
  *c10_mxData = NULL;
  *c10_isValueTooBig = 0U;
  switch (c10_ssIdNumber) {
   case 4U:
    sf_mex_assign(c10_mxData, sf_mex_create("mxData",
      *chartInstance->c10_b_Orientation_e, 0, 0U, 1U, 0U, 2, 1, 3), false);
    break;

   case 5U:
    sf_mex_assign(c10_mxData, sf_mex_create("mxData",
      *chartInstance->c10_Orientation_c, 0, 0U, 1U, 0U, 2, 1, 4), false);
    break;

   case 7U:
    sf_mex_assign(c10_mxData, sf_mex_create("mxData",
      *chartInstance->c10_b_Orientation_e, 0, 0U, 1U, 0U, 2, 1, 3), false);
    break;
  }
}

static void c10_b_emlrt_update_log_1(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c10_in[3], emlrtLocationLoggingDataType c10_table[],
  int32_T c10_index)
{
  emlrtLocationLoggingDataType *c10_b_table;
  emlrtLocationLoggingHistogramType *c10_histTable;
  real_T c10_inDouble;
  real_T c10_localMax;
  real_T c10_localMin;
  real_T c10_significand;
  int32_T c10_b_i;
  int32_T c10_exponent;
  int32_T c10_i;
  boolean_T c10_isLoggingEnabledHere;
  (void)chartInstance;
  c10_isLoggingEnabledHere = (c10_index >= 0);
  if (c10_isLoggingEnabledHere) {
    c10_b_table = (emlrtLocationLoggingDataType *)&c10_table[c10_index];
    c10_localMin = c10_b_table[0U].SimMin;
    c10_localMax = c10_b_table[0U].SimMax;
    c10_histTable = c10_b_table[0U].HistogramTable;
    for (c10_i = 0; c10_i < 3; c10_i++) {
      /* Simulation Min-Max logging. */
      if (c10_in[c10_i] < c10_localMin) {
        c10_localMin = c10_in[c10_i];
      }

      if (c10_in[c10_i] > c10_localMax) {
        c10_localMax = c10_in[c10_i];
      }

      /* Histogram logging. */
      c10_inDouble = c10_in[c10_i];
      c10_histTable->TotalNumberOfValues++;
      if (c10_inDouble == 0.0) {
        c10_histTable->NumberOfZeros++;
      } else {
        c10_histTable->SimSum += c10_inDouble;
        if ((!muDoubleScalarIsInf(c10_inDouble)) && (!muDoubleScalarIsNaN
             (c10_inDouble))) {
          c10_significand = frexp(c10_inDouble, &c10_exponent);
          if (c10_exponent > 128) {
            c10_exponent = 128;
          }

          if (c10_exponent < -127) {
            c10_exponent = -127;
          }

          if (c10_significand < 0.0) {
            c10_histTable->NumberOfNegativeValues++;
            c10_histTable->HistogramOfNegativeValues[127 + c10_exponent]++;
          } else {
            c10_histTable->NumberOfPositiveValues++;
            c10_histTable->HistogramOfPositiveValues[127 + c10_exponent]++;
          }
        }
      }
    }

    c10_b_table[0U].SimMin = c10_localMin;
    c10_b_table[0U].SimMax = c10_localMax;

    /* IsAlwaysInteger logging. */
    c10_b_i = 0;
    while (c10_b_table[0U].IsAlwaysInteger && (c10_b_i < 3)) {
      if (c10_in[c10_b_i] != muDoubleScalarFloor(c10_in[c10_b_i])) {
        c10_b_table[0U].IsAlwaysInteger = false;
      }

      c10_b_i++;
    }
  }
}

static void c10_b_emlrt_update_log_2(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance, c10_quaternion *c10_in, emlrtLocationLoggingDataType
  c10_table[], int32_T c10_index)
{
  emlrtLocationLoggingDataType *c10_b_table;
  emlrtLocationLoggingHistogramType *c10_b_histTable;
  emlrtLocationLoggingHistogramType *c10_c_histTable;
  emlrtLocationLoggingHistogramType *c10_d_histTable;
  emlrtLocationLoggingHistogramType *c10_histTable;
  real_T c10_b_inDouble;
  real_T c10_b_localMax;
  real_T c10_b_localMin;
  real_T c10_b_significand;
  real_T c10_c_inDouble;
  real_T c10_c_localMax;
  real_T c10_c_localMin;
  real_T c10_c_significand;
  real_T c10_d_inDouble;
  real_T c10_d_localMax;
  real_T c10_d_localMin;
  real_T c10_d_significand;
  real_T c10_inDouble;
  real_T c10_localMax;
  real_T c10_localMin;
  real_T c10_significand;
  int32_T c10_b_exponent;
  int32_T c10_c_exponent;
  int32_T c10_d_exponent;
  int32_T c10_exponent;
  boolean_T c10_isLoggingEnabledHere;
  (void)chartInstance;
  c10_isLoggingEnabledHere = (c10_index >= 0);
  if (c10_isLoggingEnabledHere) {
    c10_b_table = (emlrtLocationLoggingDataType *)&c10_table[c10_index];
    c10_localMin = c10_b_table[0U].SimMin;
    c10_localMax = c10_b_table[0U].SimMax;
    c10_histTable = c10_b_table[0U].HistogramTable;

    /* Simulation Min-Max logging. */
    if (c10_in->a < c10_localMin) {
      c10_localMin = c10_in->a;
    }

    if (c10_in->a > c10_localMax) {
      c10_localMax = c10_in->a;
    }

    /* Histogram logging. */
    c10_inDouble = c10_in->a;
    c10_histTable->TotalNumberOfValues++;
    if (c10_inDouble == 0.0) {
      c10_histTable->NumberOfZeros++;
    } else {
      c10_histTable->SimSum += c10_inDouble;
      if ((!muDoubleScalarIsInf(c10_inDouble)) && (!muDoubleScalarIsNaN
           (c10_inDouble))) {
        c10_significand = frexp(c10_inDouble, &c10_exponent);
        if (c10_exponent > 128) {
          c10_exponent = 128;
        }

        if (c10_exponent < -127) {
          c10_exponent = -127;
        }

        if (c10_significand < 0.0) {
          c10_histTable->NumberOfNegativeValues++;
          c10_histTable->HistogramOfNegativeValues[127 + c10_exponent]++;
        } else {
          c10_histTable->NumberOfPositiveValues++;
          c10_histTable->HistogramOfPositiveValues[127 + c10_exponent]++;
        }
      }
    }

    c10_b_table[0U].SimMin = c10_localMin;
    c10_b_table[0U].SimMax = c10_localMax;

    /* IsAlwaysInteger logging. */
    if (c10_in->a != muDoubleScalarFloor(c10_in->a)) {
      c10_b_table[0U].IsAlwaysInteger = false;
    }

    c10_b_localMin = c10_b_table[1U].SimMin;
    c10_b_localMax = c10_b_table[1U].SimMax;
    c10_b_histTable = c10_b_table[1U].HistogramTable;

    /* Simulation Min-Max logging. */
    if (c10_in->b < c10_b_localMin) {
      c10_b_localMin = c10_in->b;
    }

    if (c10_in->b > c10_b_localMax) {
      c10_b_localMax = c10_in->b;
    }

    /* Histogram logging. */
    c10_b_inDouble = c10_in->b;
    c10_b_histTable->TotalNumberOfValues++;
    if (c10_b_inDouble == 0.0) {
      c10_b_histTable->NumberOfZeros++;
    } else {
      c10_b_histTable->SimSum += c10_b_inDouble;
      if ((!muDoubleScalarIsInf(c10_b_inDouble)) && (!muDoubleScalarIsNaN
           (c10_b_inDouble))) {
        c10_b_significand = frexp(c10_b_inDouble, &c10_b_exponent);
        if (c10_b_exponent > 128) {
          c10_b_exponent = 128;
        }

        if (c10_b_exponent < -127) {
          c10_b_exponent = -127;
        }

        if (c10_b_significand < 0.0) {
          c10_b_histTable->NumberOfNegativeValues++;
          c10_b_histTable->HistogramOfNegativeValues[127 + c10_b_exponent]++;
        } else {
          c10_b_histTable->NumberOfPositiveValues++;
          c10_b_histTable->HistogramOfPositiveValues[127 + c10_b_exponent]++;
        }
      }
    }

    c10_b_table[1U].SimMin = c10_b_localMin;
    c10_b_table[1U].SimMax = c10_b_localMax;

    /* IsAlwaysInteger logging. */
    if (c10_in->b != muDoubleScalarFloor(c10_in->b)) {
      c10_b_table[1U].IsAlwaysInteger = false;
    }

    c10_c_localMin = c10_b_table[2U].SimMin;
    c10_c_localMax = c10_b_table[2U].SimMax;
    c10_c_histTable = c10_b_table[2U].HistogramTable;

    /* Simulation Min-Max logging. */
    if (c10_in->c < c10_c_localMin) {
      c10_c_localMin = c10_in->c;
    }

    if (c10_in->c > c10_c_localMax) {
      c10_c_localMax = c10_in->c;
    }

    /* Histogram logging. */
    c10_c_inDouble = c10_in->c;
    c10_c_histTable->TotalNumberOfValues++;
    if (c10_c_inDouble == 0.0) {
      c10_c_histTable->NumberOfZeros++;
    } else {
      c10_c_histTable->SimSum += c10_c_inDouble;
      if ((!muDoubleScalarIsInf(c10_c_inDouble)) && (!muDoubleScalarIsNaN
           (c10_c_inDouble))) {
        c10_c_significand = frexp(c10_c_inDouble, &c10_c_exponent);
        if (c10_c_exponent > 128) {
          c10_c_exponent = 128;
        }

        if (c10_c_exponent < -127) {
          c10_c_exponent = -127;
        }

        if (c10_c_significand < 0.0) {
          c10_c_histTable->NumberOfNegativeValues++;
          c10_c_histTable->HistogramOfNegativeValues[127 + c10_c_exponent]++;
        } else {
          c10_c_histTable->NumberOfPositiveValues++;
          c10_c_histTable->HistogramOfPositiveValues[127 + c10_c_exponent]++;
        }
      }
    }

    c10_b_table[2U].SimMin = c10_c_localMin;
    c10_b_table[2U].SimMax = c10_c_localMax;

    /* IsAlwaysInteger logging. */
    if (c10_in->c != muDoubleScalarFloor(c10_in->c)) {
      c10_b_table[2U].IsAlwaysInteger = false;
    }

    c10_d_localMin = c10_b_table[3U].SimMin;
    c10_d_localMax = c10_b_table[3U].SimMax;
    c10_d_histTable = c10_b_table[3U].HistogramTable;

    /* Simulation Min-Max logging. */
    if (c10_in->d < c10_d_localMin) {
      c10_d_localMin = c10_in->d;
    }

    if (c10_in->d > c10_d_localMax) {
      c10_d_localMax = c10_in->d;
    }

    /* Histogram logging. */
    c10_d_inDouble = c10_in->d;
    c10_d_histTable->TotalNumberOfValues++;
    if (c10_d_inDouble == 0.0) {
      c10_d_histTable->NumberOfZeros++;
    } else {
      c10_d_histTable->SimSum += c10_d_inDouble;
      if ((!muDoubleScalarIsInf(c10_d_inDouble)) && (!muDoubleScalarIsNaN
           (c10_d_inDouble))) {
        c10_d_significand = frexp(c10_d_inDouble, &c10_d_exponent);
        if (c10_d_exponent > 128) {
          c10_d_exponent = 128;
        }

        if (c10_d_exponent < -127) {
          c10_d_exponent = -127;
        }

        if (c10_d_significand < 0.0) {
          c10_d_histTable->NumberOfNegativeValues++;
          c10_d_histTable->HistogramOfNegativeValues[127 + c10_d_exponent]++;
        } else {
          c10_d_histTable->NumberOfPositiveValues++;
          c10_d_histTable->HistogramOfPositiveValues[127 + c10_d_exponent]++;
        }
      }
    }

    c10_b_table[3U].SimMin = c10_d_localMin;
    c10_b_table[3U].SimMax = c10_d_localMax;

    /* IsAlwaysInteger logging. */
    if (c10_in->d != muDoubleScalarFloor(c10_in->d)) {
      c10_b_table[3U].IsAlwaysInteger = false;
    }
  }
}

static void c10_b_emlrt_update_log_3(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c10_in[4], emlrtLocationLoggingDataType c10_table[],
  int32_T c10_index)
{
  emlrtLocationLoggingDataType *c10_b_table;
  emlrtLocationLoggingHistogramType *c10_histTable;
  real_T c10_inDouble;
  real_T c10_localMax;
  real_T c10_localMin;
  real_T c10_significand;
  int32_T c10_b_i;
  int32_T c10_exponent;
  int32_T c10_i;
  boolean_T c10_isLoggingEnabledHere;
  (void)chartInstance;
  c10_isLoggingEnabledHere = (c10_index >= 0);
  if (c10_isLoggingEnabledHere) {
    c10_b_table = (emlrtLocationLoggingDataType *)&c10_table[c10_index];
    c10_localMin = c10_b_table[0U].SimMin;
    c10_localMax = c10_b_table[0U].SimMax;
    c10_histTable = c10_b_table[0U].HistogramTable;
    for (c10_i = 0; c10_i < 4; c10_i++) {
      /* Simulation Min-Max logging. */
      if (c10_in[c10_i] < c10_localMin) {
        c10_localMin = c10_in[c10_i];
      }

      if (c10_in[c10_i] > c10_localMax) {
        c10_localMax = c10_in[c10_i];
      }

      /* Histogram logging. */
      c10_inDouble = c10_in[c10_i];
      c10_histTable->TotalNumberOfValues++;
      if (c10_inDouble == 0.0) {
        c10_histTable->NumberOfZeros++;
      } else {
        c10_histTable->SimSum += c10_inDouble;
        if ((!muDoubleScalarIsInf(c10_inDouble)) && (!muDoubleScalarIsNaN
             (c10_inDouble))) {
          c10_significand = frexp(c10_inDouble, &c10_exponent);
          if (c10_exponent > 128) {
            c10_exponent = 128;
          }

          if (c10_exponent < -127) {
            c10_exponent = -127;
          }

          if (c10_significand < 0.0) {
            c10_histTable->NumberOfNegativeValues++;
            c10_histTable->HistogramOfNegativeValues[127 + c10_exponent]++;
          } else {
            c10_histTable->NumberOfPositiveValues++;
            c10_histTable->HistogramOfPositiveValues[127 + c10_exponent]++;
          }
        }
      }
    }

    c10_b_table[0U].SimMin = c10_localMin;
    c10_b_table[0U].SimMax = c10_localMax;

    /* IsAlwaysInteger logging. */
    c10_b_i = 0;
    while (c10_b_table[0U].IsAlwaysInteger && (c10_b_i < 4)) {
      if (c10_in[c10_b_i] != muDoubleScalarFloor(c10_in[c10_b_i])) {
        c10_b_table[0U].IsAlwaysInteger = false;
      }

      c10_b_i++;
    }
  }
}

static void init_dsm_address_info(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc10_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  chartInstance->c10_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c10_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c10_Orientation_e = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c10_Orientation_c = (real_T (*)[4])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c10_b_Orientation_e = (real_T (*)[3])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 2);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c10_car_model_FIXED_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1308925138U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3201391309U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(363255782U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3883683703U);
}

mxArray *sf_c10_car_model_FIXED_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c10_car_model_FIXED_jit_fallback_info(void)
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

mxArray *sf_c10_car_model_FIXED_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c10_car_model_FIXED(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiC+wcTAwAakOYCYiQECWKF8RiBmhtIQcRa4uAIQl1QWpILEi4uSPVOAdF5iLpi"
    "fWFrhmZeWDzbfggFhPhsW8xmRzOeEikPAB3vK9Is4gPQ7IOlnwaKfF0m/AJTvX5SZmleSWJKZnx"
    "efDA0nWHgNnH9kqOKfVKr5R8GBMv0Q+wMI+EcWzT8gfmZxfGJySWZZanyyoUF8cmJRfG5+SmpOv"
    "JtnhKsLkv8A7Konxw=="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c10_car_model_FIXED_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sB1BMPri0FTxkq3dNxq34YB";
}

static void sf_opaque_initialize_c10_car_model_FIXED(void *chartInstanceVar)
{
  initialize_params_c10_car_model_FIXED((SFc10_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
  initialize_c10_car_model_FIXED((SFc10_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c10_car_model_FIXED(void *chartInstanceVar)
{
  enable_c10_car_model_FIXED((SFc10_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c10_car_model_FIXED(void *chartInstanceVar)
{
  disable_c10_car_model_FIXED((SFc10_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c10_car_model_FIXED(void *chartInstanceVar)
{
  sf_gateway_c10_car_model_FIXED((SFc10_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c10_car_model_FIXED(SimStruct* S)
{
  return get_sim_state_c10_car_model_FIXED((SFc10_car_model_FIXEDInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c10_car_model_FIXED(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c10_car_model_FIXED((SFc10_car_model_FIXEDInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c10_car_model_FIXED(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc10_car_model_FIXEDInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_car_model_FIXED_optimization_info();
    }

    mdl_cleanup_runtime_resources_c10_car_model_FIXED
      ((SFc10_car_model_FIXEDInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c10_car_model_FIXED(void *chartInstanceVar)
{
  mdl_start_c10_car_model_FIXED((SFc10_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_mdl_terminate_c10_car_model_FIXED(void *chartInstanceVar)
{
  mdl_terminate_c10_car_model_FIXED((SFc10_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc10_car_model_FIXED((SFc10_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c10_car_model_FIXED(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  sf_warn_if_symbolic_dimension_param_changed(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c10_car_model_FIXED((SFc10_car_model_FIXEDInstanceStruct*)
      sf_get_chart_instance_ptr(S));
    initSimStructsc10_car_model_FIXED((SFc10_car_model_FIXEDInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c10_car_model_FIXED_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [22] = {
    "eNrtWMtu41QYPs2UihEz1UjcJDQjZskGqZ2CxAJBmxtEaqYBp+WyiU7tP/FRjo/dc8kF8QDs2bD",
    "gCZDYsENiyzvMY8yCBUv+YzuZyA2pT9JhLsKS657Y33/5/N+OyVarTfDYxTN5h5AdvL6KZ4Vkxy",
    "v5emvhzH7fJh/n6+9fI8SPAxiA8Ey/zybE7RAm6lBJI0XcD0Ej+BJUzI1msWiJflwey0QfJAgfB",
    "SSx1E56FYsMZ2LYNMK3mtVXIfNDL4wND6ookAYngk//TW9idAc11pkEXzcBAh3K2AzCJqeD1SxI",
    "Pa6F4A+ViZy5UqA9k1hXVdtwzRIOjQn4LaE0RRbUFf56mmqo6YkbydZf5c3QcZRwRkV5rkOqPEg",
    "wOjScJgH+PTEa2SuF9UMqdRVCOgJ1zIap9lhAKe1M4dPnTFAdS0Z5I+I1K62kvx2OPrYxJbjrO0",
    "J/qxLoMImZ0I4J4TWR54ag5xzqcG4Gjno9uDA2G84YjEG6vd9+LR6BpAM4EW42p++oMUmDcp5LJ",
    "bGaRXBG5ZGPsasgcKsbmHTKoxiO0EUxTlhIKW6prmQjjA3XWtey6b9WrTNRFv1qLWyqtzEC57ia",
    "6236okY5V27Ybpwcwwh4qr9ONV0Dm+l3ACvFgm6M0WGrjWPFMoJhJuTYWiwCVj4qRwVU2tgeYpM",
    "qAWeRTQMIkOa56XNBV+WRUTqOalhy6sfHJfVdxraEBtmnPpTuMZIyBWhwGleOegOmbCIhGlnSqZ",
    "elJWQ5uBaUqL4R9XEsh8ixazN7wpXNBDc0BAMszBrSItfA6D6j3JS0OVIDzB8Mj1OFVdZNL2Jt/",
    "qwF9qkfQmA7J+PQxjqLAsq+YmVb/hF6O2J6WgflS5aUzSSDBR2brmWpO03gVAxFPBZNGUdePnmt",
    "iCsArBpUCiYGVWzhctpE48tZLeGim1Z31yHH8kw1p+c2Nj4Dgd3Q+mqnBupjVjUEjsho0CZYj32",
    "HQ4xQTGls1NOs1Wd9z87vn5Mn8/v2kvn99YX5/U6+9vf3ej6VvcgOK71m6+tGfS5vb0HerRL7gT",
    "I4cglH5rjZ9b0F/NYSvWThWtR3s7Lazgr+t5XjDhdwtwt6tgu4nZyzH3//iz/+482fv/B/+emtP",
    "3/7dRP9P9xw22/t5uu7s7lpXqVHlwpZmXh4uxAPdq2q+9V2R7K9ZncyvDgIHk4uDj74pprKe1RZ",
    "be+Ngr2z3+/bWQ2TOK0J0m8F+b7NrqnJ9hNW/kcL9u5cwcfNhXgi5PGnm+HfOCzGwzK+bhf4sus",
    "TybDxpena8wtx/Oz8uXst/sC1+XP/cDN8pr9zhT/3Cv7cS/cmPWo7EPSWV7rda6gjrjjyH+NeFD",
    "v/5+Xp+1emj6+LqzzFueE6cZv65zqfvOjP762ou6Tw/J3n2A+yot67zKnPm1+PiNsc+W6+/mT+n",
    "aQWMh4s2anlt3Ez1V929yWJ778d+ZvNzQ3LX/5B/duDI0H5FLdm2dY3/7kj7XfR+S0JVC3f/z6L",
    "fkKW7IOWzVW3Cvlt12Mmgnis3t9/8OGDTfrTP8aUKHo=",
    ""
  };

  static char newstr [1545] = "";
  newstr[0] = '\0';
  for (i = 0; i < 22; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c10_car_model_FIXED(SimStruct *S)
{
  const char* newstr = sf_c10_car_model_FIXED_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(1827977619U));
  ssSetChecksum1(S,(2618670320U));
  ssSetChecksum2(S,(2561303377U));
  ssSetChecksum3(S,(2914174230U));
}

static void mdlRTW_c10_car_model_FIXED(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c10_car_model_FIXED(SimStruct *S)
{
  SFc10_car_model_FIXEDInstanceStruct *chartInstance;
  chartInstance = (SFc10_car_model_FIXEDInstanceStruct *)utMalloc(sizeof
    (SFc10_car_model_FIXEDInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc10_car_model_FIXEDInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c10_car_model_FIXED;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c10_car_model_FIXED;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c10_car_model_FIXED;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c10_car_model_FIXED;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c10_car_model_FIXED;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c10_car_model_FIXED;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c10_car_model_FIXED;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c10_car_model_FIXED;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c10_car_model_FIXED;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c10_car_model_FIXED;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c10_car_model_FIXED;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c10_car_model_FIXED;
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
    chartInstance->c10_JITStateAnimation,
    chartInstance->c10_JITTransitionAnimation);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c10_car_model_FIXED(chartInstance);
}

void c10_car_model_FIXED_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c10_car_model_FIXED(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c10_car_model_FIXED(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c10_car_model_FIXED(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c10_car_model_FIXED_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
