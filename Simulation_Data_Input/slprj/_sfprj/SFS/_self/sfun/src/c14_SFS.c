/* Include files */

#include "SFS_sfun.h"
#include "c14_SFS.h"
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
static emlrtMCInfo c14_emlrtMCI = { 13,/* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pName */
};

static emlrtRSInfo c14_emlrtRSI = { 3, /* lineNo */
  "SNED to VNED",                      /* fcnName */
  "#SFS:4"                             /* pathName */
};

static emlrtRSInfo c14_b_emlrtRSI = { 4,/* lineNo */
  "SNED to VNED",                      /* fcnName */
  "#SFS:4"                             /* pathName */
};

static emlrtRSInfo c14_c_emlrtRSI = { 19,/* lineNo */
  "rotmat",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\rotations\\rotationslib\\+matlabshared\\+rotations\\+internal\\@quaternionBase\\rotmat.m"/* pathName */
};

static emlrtRSInfo c14_d_emlrtRSI = { 10,/* lineNo */
  "normalize",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\rotations\\rotationslib\\+matlabshared\\+rotations\\+internal\\@quaternionBase\\normaliz"
  "e.m"                                /* pathName */
};

/* Function Declarations */
static void initialize_c14_SFS(SFc14_SFSInstanceStruct *chartInstance);
static void initialize_params_c14_SFS(SFc14_SFSInstanceStruct *chartInstance);
static void mdl_start_c14_SFS(SFc14_SFSInstanceStruct *chartInstance);
static void mdl_terminate_c14_SFS(SFc14_SFSInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c14_SFS(SFc14_SFSInstanceStruct
  *chartInstance);
static void mdl_cleanup_runtime_resources_c14_SFS(SFc14_SFSInstanceStruct
  *chartInstance);
static void enable_c14_SFS(SFc14_SFSInstanceStruct *chartInstance);
static void disable_c14_SFS(SFc14_SFSInstanceStruct *chartInstance);
static void sf_gateway_c14_SFS(SFc14_SFSInstanceStruct *chartInstance);
static void ext_mode_exec_c14_SFS(SFc14_SFSInstanceStruct *chartInstance);
static void c14_update_jit_animation_c14_SFS(SFc14_SFSInstanceStruct
  *chartInstance);
static void c14_do_animation_call_c14_SFS(SFc14_SFSInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c14_SFS(SFc14_SFSInstanceStruct
  *chartInstance);
static void set_sim_state_c14_SFS(SFc14_SFSInstanceStruct *chartInstance, const
  mxArray *c14_st);
static void initSimStructsc14_SFS(SFc14_SFSInstanceStruct *chartInstance);
static void c14_emlrt_update_log_1(SFc14_SFSInstanceStruct *chartInstance,
  real_T c14_in[3], emlrtLocationLoggingDataType c14_table[], int32_T c14_index,
  real_T c14_out[3]);
static real_T c14_emlrt_update_log_2(SFc14_SFSInstanceStruct *chartInstance,
  real_T c14_in, emlrtLocationLoggingDataType c14_table[], int32_T c14_index);
static void c14_emlrt_update_log_3(SFc14_SFSInstanceStruct *chartInstance,
  real_T c14_in[9], emlrtLocationLoggingDataType c14_table[], int32_T c14_index,
  real_T c14_out[9]);
static c14_quaternion c14_emlrt_update_log_4(SFc14_SFSInstanceStruct
  *chartInstance, c14_quaternion c14_in, emlrtLocationLoggingDataType c14_table[],
  int32_T c14_index);
static c14_rtString c14_emlrt_update_log_5(SFc14_SFSInstanceStruct
  *chartInstance, c14_rtString c14_in, emlrtLocationLoggingDataType c14_table[],
  int32_T c14_index);
static c14_rtString_1 c14_emlrt_update_log_6(SFc14_SFSInstanceStruct
  *chartInstance, c14_rtString_1 c14_in, emlrtLocationLoggingDataType c14_table[],
  int32_T c14_index);
static c14_rtString_2 c14_emlrt_update_log_7(SFc14_SFSInstanceStruct
  *chartInstance, c14_rtString_2 c14_in, emlrtLocationLoggingDataType c14_table[],
  int32_T c14_index);
static void c14_emlrt_update_log_8(SFc14_SFSInstanceStruct *chartInstance,
  real_T c14_in[3], emlrtLocationLoggingDataType c14_table[], int32_T c14_index,
  real_T c14_out[3]);
static void c14_emlrt_update_log_9(SFc14_SFSInstanceStruct *chartInstance,
  real_T c14_in[3], emlrtLocationLoggingDataType c14_table[], int32_T c14_index,
  real_T c14_out[3]);
static void c14_emlrtInitVarDataTables(SFc14_SFSInstanceStruct *chartInstance,
  emlrtLocationLoggingDataType c14_dataTables[30],
  emlrtLocationLoggingHistogramType c14_histTables[30]);
static c14_quaternion c14_quaternionBase_normalize(SFc14_SFSInstanceStruct
  *chartInstance, const emlrtStack *c14_sp, c14_quaternion c14_q);
static void c14_emlrt_marshallIn(SFc14_SFSInstanceStruct *chartInstance, const
  mxArray *c14_b_accel_VNED, const char_T *c14_identifier, real_T c14_y[3]);
static void c14_b_emlrt_marshallIn(SFc14_SFSInstanceStruct *chartInstance, const
  mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId, real_T c14_y[3]);
static uint8_T c14_c_emlrt_marshallIn(SFc14_SFSInstanceStruct *chartInstance,
  const mxArray *c14_b_is_active_c14_SFS, const char_T *c14_identifier);
static uint8_T c14_d_emlrt_marshallIn(SFc14_SFSInstanceStruct *chartInstance,
  const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_slStringInitializeDynamicBuffers(SFc14_SFSInstanceStruct
  *chartInstance);
static void c14_chart_data_browse_helper(SFc14_SFSInstanceStruct *chartInstance,
  int32_T c14_ssIdNumber, const mxArray **c14_mxData, uint8_T *c14_isValueTooBig);
static void c14_b_emlrt_update_log_1(SFc14_SFSInstanceStruct *chartInstance,
  real_T c14_in[3], emlrtLocationLoggingDataType c14_table[], int32_T c14_index);
static void c14_b_emlrt_update_log_3(SFc14_SFSInstanceStruct *chartInstance,
  real_T c14_in[9], emlrtLocationLoggingDataType c14_table[], int32_T c14_index);
static void c14_b_emlrt_update_log_4(SFc14_SFSInstanceStruct *chartInstance,
  c14_quaternion *c14_in, emlrtLocationLoggingDataType c14_table[], int32_T
  c14_index);
static void c14_b_emlrt_update_log_5(SFc14_SFSInstanceStruct *chartInstance,
  c14_rtString *c14_in, emlrtLocationLoggingDataType c14_table[], int32_T
  c14_index);
static void c14_b_emlrt_update_log_6(SFc14_SFSInstanceStruct *chartInstance,
  c14_rtString_1 *c14_in, emlrtLocationLoggingDataType c14_table[], int32_T
  c14_index);
static void c14_b_emlrt_update_log_7(SFc14_SFSInstanceStruct *chartInstance,
  c14_rtString_2 *c14_in, emlrtLocationLoggingDataType c14_table[], int32_T
  c14_index);
static void c14_b_emlrt_update_log_8(SFc14_SFSInstanceStruct *chartInstance,
  real_T c14_in[3], emlrtLocationLoggingDataType c14_table[], int32_T c14_index);
static void c14_b_emlrt_update_log_9(SFc14_SFSInstanceStruct *chartInstance,
  real_T c14_in[3], emlrtLocationLoggingDataType c14_table[], int32_T c14_index);
static void c14_b_quaternionBase_normalize(SFc14_SFSInstanceStruct
  *chartInstance, const emlrtStack *c14_sp, c14_quaternion *c14_q);
static void init_dsm_address_info(SFc14_SFSInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc14_SFSInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c14_SFS(SFc14_SFSInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
  chartInstance->c14_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c14_is_active_c14_SFS = 0U;
  chartInstance->c14_emlrtLocLogSimulated = false;
  c14_emlrtInitVarDataTables(chartInstance,
    chartInstance->c14_emlrtLocationLoggingDataTables,
    chartInstance->c14_emlrtLocLogHistTables);
}

static void initialize_params_c14_SFS(SFc14_SFSInstanceStruct *chartInstance)
{
  real_T c14_d;
  sf_mex_import_named("phi", sf_mex_get_sfun_param(chartInstance->S, 0U, 0U),
                      &c14_d, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c14_phi = c14_d;
}

static void mdl_start_c14_SFS(SFc14_SFSInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_terminate_c14_SFS(SFc14_SFSInstanceStruct *chartInstance)
{
  const emlrtLocationLoggingFileInfoType c14_emlrtLocationLoggingFileInfo = {
    "#SFS:4",                          /* mexFileName */
    "Mon Apr 17 21:59:11 2023",        /* timestamp */
    "",                                /* buildDir */
    1,                                 /* numFcns */
    256                                /* numHistogramBins */
  };

  const emlrtLocationLoggingFunctionInfoType
    c14_emlrtLocationLoggingFunctionInfoTable[1] = { { "eML_blk_kernel",/* fcnName */
      1,                               /* fcnId */
      24                               /* numInstrPoints */
    } };

  const emlrtLocationLoggingLocationType c14_emlrtLocationInfo[26] = { { 1,/* MxInfoID */
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
    }, { 13,                           /* MxInfoID */
      312,                             /* TextStart */
      10,                              /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 14,                           /* MxInfoID */
      326,                             /* TextStart */
      22,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 13,                           /* MxInfoID */
      389,                             /* TextStart */
      9,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 14,                           /* MxInfoID */
      402,                             /* TextStart */
      21,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 13,                           /* MxInfoID */
      471,                             /* TextStart */
      8,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 14,                           /* MxInfoID */
      483,                             /* TextStart */
      20,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    } };

  const int32_T c14_emlrtLocationLoggingFieldCounts[24] = { 0, 0, 0, 0, 0, 4, 0,
    1, 1, 1, 1, 0, 4, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 };

  const char_T *c14_emlrtLocationLoggingFieldNames[16] = { "a", "b", "c", "d",
    "__$isSimulinkString.__dummy", "__$isSimulinkString.__dummy",
    "__$isSimulinkString.__dummy", "__$isSimulinkString.__dummy", "a", "b", "c",
    "d", "__$isSimulinkString.__dummy", "__$isSimulinkString.__dummy",
    "__$isSimulinkString.__dummy", "__$isSimulinkString.__dummy" };

  if (chartInstance->c14_emlrtLocLogSimulated) {
    emlrtLocationLoggingClearLog("#SFS:4");
    emlrtLocationLoggingPushLog(&c14_emlrtLocationLoggingFileInfo,
      &c14_emlrtLocationLoggingFunctionInfoTable[0],
      &chartInstance->c14_emlrtLocationLoggingDataTables[0],
      &c14_emlrtLocationInfo[0], NULL, 0U, &c14_emlrtLocationLoggingFieldCounts
      [0], &c14_emlrtLocationLoggingFieldNames[0]);
    addResultsToFPTRepository("#SFS:4");
  }
}

static void mdl_setup_runtime_resources_c14_SFS(SFc14_SFSInstanceStruct
  *chartInstance)
{
  static const uint32_T c14_decisionTxtEndIdx = 0U;
  static const uint32_T c14_decisionTxtStartIdx = 0U;
  setDebuggerFlag(chartInstance->S, true);
  setDataBrowseFcn(chartInstance->S, (void *)&c14_chart_data_browse_helper);
  chartInstance->c14_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c14_RuntimeVar,
    &chartInstance->c14_IsDebuggerActive,
    &chartInstance->c14_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c14_mlFcnLineNumber, &chartInstance->c14_IsHeatMapPresent, 0);
  sim_mode_is_external(chartInstance->S);
  covrtCreateStateflowInstanceData(chartInstance->c14_covrtInstance, 1U, 0U, 1U,
    14U);
  covrtChartInitFcn(chartInstance->c14_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c14_covrtInstance, 0U, 0U, false, false,
                    false, 0U, &c14_decisionTxtStartIdx, &c14_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c14_covrtInstance, 0U, 0, NULL, NULL, 0U,
                    NULL);
  covrtEmlInitFcn(chartInstance->c14_covrtInstance, "", 4U, 0U, 1U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c14_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 543);
}

static void mdl_cleanup_runtime_resources_c14_SFS(SFc14_SFSInstanceStruct
  *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c14_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c14_covrtInstance);
}

static void enable_c14_SFS(SFc14_SFSInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c14_SFS(SFc14_SFSInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c14_SFS(SFc14_SFSInstanceStruct *chartInstance)
{
  static char_T c14_cv[6] = { 'e', 'u', 'l', 'e', 'r', 'd' };

  static char_T c14_cv2[5] = { 'f', 'r', 'a', 'm', 'e' };

  static char_T c14_cv1[3] = { 'X', 'Y', 'Z' };

  c14_quaternion c14_d_obj;
  c14_rtString c14_obj;
  c14_rtString_1 c14_b_obj;
  c14_rtString_2 c14_c_obj;
  emlrtStack c14_b_st;
  emlrtStack c14_c_st;
  emlrtStack c14_st = { NULL,          /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  real_T c14_b_rmat[9];
  real_T c14_rmat[9];
  real_T c14_c_rmat[3];
  real_T c14_d_rmat[3];
  real_T c14_e_rmat[3];
  real_T c14_varargin_1[3];
  real_T c14_a;
  real_T c14_aasq;
  real_T c14_ab2;
  real_T c14_ab_x;
  real_T c14_ac2;
  real_T c14_ac_x;
  real_T c14_ad2;
  real_T c14_ad_x;
  real_T c14_b_a;
  real_T c14_b_aasq;
  real_T c14_b_ab2;
  real_T c14_b_ac2;
  real_T c14_b_ad2;
  real_T c14_b_b;
  real_T c14_b_bbsq;
  real_T c14_b_bc2;
  real_T c14_b_bd2;
  real_T c14_b_c;
  real_T c14_b_ccsq;
  real_T c14_b_cd2;
  real_T c14_b_ddsq;
  real_T c14_b_phi;
  real_T c14_b_qa;
  real_T c14_b_qb;
  real_T c14_b_qc;
  real_T c14_b_qd;
  real_T c14_b_ta;
  real_T c14_b_tb;
  real_T c14_b_tc;
  real_T c14_b_td;
  real_T c14_b_x;
  real_T c14_bb_x;
  real_T c14_bbsq;
  real_T c14_bc2;
  real_T c14_bc_x;
  real_T c14_bd2;
  real_T c14_bd_x;
  real_T c14_c;
  real_T c14_c_b;
  real_T c14_c_qa;
  real_T c14_c_qb;
  real_T c14_c_qc;
  real_T c14_c_qd;
  real_T c14_c_x;
  real_T c14_cb_x;
  real_T c14_cc_x;
  real_T c14_ccsq;
  real_T c14_cd2;
  real_T c14_cd_x;
  real_T c14_d;
  real_T c14_d1;
  real_T c14_d2;
  real_T c14_d3;
  real_T c14_d4;
  real_T c14_d5;
  real_T c14_d6;
  real_T c14_d7;
  real_T c14_d8;
  real_T c14_d9;
  real_T c14_d_qa;
  real_T c14_d_qb;
  real_T c14_d_qc;
  real_T c14_d_qd;
  real_T c14_d_x;
  real_T c14_db_x;
  real_T c14_dc_x;
  real_T c14_dd_x;
  real_T c14_ddsq;
  real_T c14_e_x;
  real_T c14_eb_x;
  real_T c14_ec_x;
  real_T c14_ed_x;
  real_T c14_f_x;
  real_T c14_fb_x;
  real_T c14_fc_x;
  real_T c14_fd_x;
  real_T c14_g_x;
  real_T c14_gb_x;
  real_T c14_gc_x;
  real_T c14_gd_x;
  real_T c14_h_x;
  real_T c14_hb_x;
  real_T c14_hc_x;
  real_T c14_hd_x;
  real_T c14_i_x;
  real_T c14_ib_x;
  real_T c14_ic_x;
  real_T c14_id_x;
  real_T c14_j_x;
  real_T c14_jb_x;
  real_T c14_jc_x;
  real_T c14_jd_x;
  real_T c14_k_x;
  real_T c14_kb_x;
  real_T c14_kc_x;
  real_T c14_kd_x;
  real_T c14_l_x;
  real_T c14_lb_x;
  real_T c14_lc_x;
  real_T c14_ld_x;
  real_T c14_m_x;
  real_T c14_mb_x;
  real_T c14_mc_x;
  real_T c14_md_x;
  real_T c14_n_x;
  real_T c14_nb_x;
  real_T c14_nc_x;
  real_T c14_nd_x;
  real_T c14_o_x;
  real_T c14_ob_x;
  real_T c14_oc_x;
  real_T c14_od_x;
  real_T c14_p_x;
  real_T c14_pb_x;
  real_T c14_pc_x;
  real_T c14_pd_x;
  real_T c14_q_x;
  real_T c14_qa;
  real_T c14_qb;
  real_T c14_qb_x;
  real_T c14_qc;
  real_T c14_qc_x;
  real_T c14_qd;
  real_T c14_qd_x;
  real_T c14_r_x;
  real_T c14_rb_x;
  real_T c14_rc_x;
  real_T c14_rd_x;
  real_T c14_s_x;
  real_T c14_sb_x;
  real_T c14_sc_x;
  real_T c14_sd_x;
  real_T c14_t_x;
  real_T c14_ta;
  real_T c14_tb;
  real_T c14_tb_x;
  real_T c14_tc;
  real_T c14_tc_x;
  real_T c14_td;
  real_T c14_td_x;
  real_T c14_u_x;
  real_T c14_ub_x;
  real_T c14_uc_x;
  real_T c14_ud_x;
  real_T c14_v_x;
  real_T c14_vb_x;
  real_T c14_vc_x;
  real_T c14_w_x;
  real_T c14_wb_x;
  real_T c14_wc_x;
  real_T c14_x;
  real_T c14_x_x;
  real_T c14_xb_x;
  real_T c14_xc_x;
  real_T c14_y_x;
  real_T c14_yb_x;
  real_T c14_yc_x;
  int32_T c14_i;
  int32_T c14_i1;
  int32_T c14_i10;
  int32_T c14_i11;
  int32_T c14_i12;
  int32_T c14_i13;
  int32_T c14_i14;
  int32_T c14_i15;
  int32_T c14_i16;
  int32_T c14_i17;
  int32_T c14_i18;
  int32_T c14_i19;
  int32_T c14_i2;
  int32_T c14_i20;
  int32_T c14_i21;
  int32_T c14_i22;
  int32_T c14_i23;
  int32_T c14_i24;
  int32_T c14_i25;
  int32_T c14_i26;
  int32_T c14_i27;
  int32_T c14_i28;
  int32_T c14_i29;
  int32_T c14_i3;
  int32_T c14_i30;
  int32_T c14_i31;
  int32_T c14_i32;
  int32_T c14_i33;
  int32_T c14_i34;
  int32_T c14_i35;
  int32_T c14_i36;
  int32_T c14_i37;
  int32_T c14_i38;
  int32_T c14_i39;
  int32_T c14_i4;
  int32_T c14_i40;
  int32_T c14_i41;
  int32_T c14_i42;
  int32_T c14_i43;
  int32_T c14_i44;
  int32_T c14_i45;
  int32_T c14_i46;
  int32_T c14_i47;
  int32_T c14_i5;
  int32_T c14_i6;
  int32_T c14_i7;
  int32_T c14_i8;
  int32_T c14_i9;
  boolean_T c14_b;
  boolean_T c14_b1;
  boolean_T c14_b10;
  boolean_T c14_b11;
  boolean_T c14_b12;
  boolean_T c14_b13;
  boolean_T c14_b14;
  boolean_T c14_b15;
  boolean_T c14_b16;
  boolean_T c14_b17;
  boolean_T c14_b18;
  boolean_T c14_b19;
  boolean_T c14_b2;
  boolean_T c14_b20;
  boolean_T c14_b21;
  boolean_T c14_b22;
  boolean_T c14_b23;
  boolean_T c14_b3;
  boolean_T c14_b4;
  boolean_T c14_b5;
  boolean_T c14_b6;
  boolean_T c14_b7;
  boolean_T c14_b8;
  boolean_T c14_b9;
  c14_st.tls = chartInstance->c14_fEmlrtCtx;
  c14_b_st.prev = &c14_st;
  c14_b_st.tls = c14_st.tls;
  c14_c_st.prev = &c14_b_st;
  c14_c_st.tls = c14_b_st.tls;
  chartInstance->c14_JITTransitionAnimation[0] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  c14_b = false;
  for (c14_i = 0; c14_i < 3; c14_i++) {
    c14_b = (c14_b || ((*chartInstance->c14_mag_SNED)[c14_i] > 200.0));
  }

  c14_b1 = c14_b;
  if (c14_b1) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 2U, 1U);
  }

  c14_b2 = false;
  for (c14_i1 = 0; c14_i1 < 3; c14_i1++) {
    c14_b2 = (c14_b2 || ((*chartInstance->c14_mag_SNED)[c14_i1] < -200.0));
  }

  c14_b3 = c14_b2;
  if (c14_b3) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 2U, 0U);
  }

  for (c14_i2 = 0; c14_i2 < 3; c14_i2++) {
    covrtSigUpdateFcn(chartInstance->c14_covrtInstance, 2U,
                      (*chartInstance->c14_mag_SNED)[c14_i2]);
  }

  c14_b4 = false;
  for (c14_i3 = 0; c14_i3 < 3; c14_i3++) {
    c14_b4 = (c14_b4 || ((*chartInstance->c14_gyro_SNED)[c14_i3] > 2.5));
  }

  c14_b5 = c14_b4;
  if (c14_b5) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 1U, 1U);
  }

  c14_b6 = false;
  for (c14_i4 = 0; c14_i4 < 3; c14_i4++) {
    c14_b6 = (c14_b6 || ((*chartInstance->c14_gyro_SNED)[c14_i4] < -2.5));
  }

  c14_b7 = c14_b6;
  if (c14_b7) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 1U, 0U);
  }

  for (c14_i5 = 0; c14_i5 < 3; c14_i5++) {
    covrtSigUpdateFcn(chartInstance->c14_covrtInstance, 1U,
                      (*chartInstance->c14_gyro_SNED)[c14_i5]);
  }

  c14_b8 = false;
  for (c14_i6 = 0; c14_i6 < 3; c14_i6++) {
    c14_b8 = (c14_b8 || ((*chartInstance->c14_accel_SNED)[c14_i6] > 30.0));
  }

  c14_b9 = c14_b8;
  if (c14_b9) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 0U, 1U);
  }

  c14_b10 = false;
  for (c14_i7 = 0; c14_i7 < 3; c14_i7++) {
    c14_b10 = (c14_b10 || ((*chartInstance->c14_accel_SNED)[c14_i7] < -30.0));
  }

  c14_b11 = c14_b10;
  if (c14_b11) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 0U, 0U);
  }

  for (c14_i8 = 0; c14_i8 < 3; c14_i8++) {
    covrtSigUpdateFcn(chartInstance->c14_covrtInstance, 0U,
                      (*chartInstance->c14_accel_SNED)[c14_i8]);
  }

  chartInstance->c14_sfEvent = CALL_EVENT;
  c14_b_phi = chartInstance->c14_phi;

  /* logging input variable 'accel_SNED' for function 'eML_blk_kernel' */
  /* logging input variable 'gyro_SNED' for function 'eML_blk_kernel' */
  /* logging input variable 'mag_SNED' for function 'eML_blk_kernel' */
  /* logging input variable 'phi' for function 'eML_blk_kernel' */
  chartInstance->c14_emlrtLocLogSimulated = true;

  /* logging input variable 'accel_SNED' for function 'eML_blk_kernel' */
  for (c14_i9 = 0; c14_i9 < 3; c14_i9++) {
    c14_varargin_1[c14_i9] = (*chartInstance->c14_accel_SNED)[c14_i9];
  }

  c14_b_emlrt_update_log_1(chartInstance, c14_varargin_1,
    chartInstance->c14_emlrtLocationLoggingDataTables, 0);

  /* logging input variable 'gyro_SNED' for function 'eML_blk_kernel' */
  for (c14_i10 = 0; c14_i10 < 3; c14_i10++) {
    c14_varargin_1[c14_i10] = (*chartInstance->c14_gyro_SNED)[c14_i10];
  }

  c14_b_emlrt_update_log_1(chartInstance, c14_varargin_1,
    chartInstance->c14_emlrtLocationLoggingDataTables, 1);

  /* logging input variable 'mag_SNED' for function 'eML_blk_kernel' */
  for (c14_i11 = 0; c14_i11 < 3; c14_i11++) {
    c14_varargin_1[c14_i11] = (*chartInstance->c14_mag_SNED)[c14_i11];
  }

  c14_b_emlrt_update_log_1(chartInstance, c14_varargin_1,
    chartInstance->c14_emlrtLocationLoggingDataTables, 2);

  /* logging input variable 'phi' for function 'eML_blk_kernel' */
  c14_emlrt_update_log_2(chartInstance, c14_b_phi,
    chartInstance->c14_emlrtLocationLoggingDataTables, 3);
  covrtEmlFcnEval(chartInstance->c14_covrtInstance, 4U, 0, 0);
  for (c14_i12 = 0; c14_i12 < 6; c14_i12++) {
    c14_obj.Value[c14_i12] = c14_cv[c14_i12];
  }

  c14_b_emlrt_update_log_5(chartInstance, &c14_obj,
    chartInstance->c14_emlrtLocationLoggingDataTables, 10);
  for (c14_i13 = 0; c14_i13 < 3; c14_i13++) {
    c14_b_obj.Value[c14_i13] = c14_cv1[c14_i13];
  }

  c14_b_emlrt_update_log_6(chartInstance, &c14_b_obj,
    chartInstance->c14_emlrtLocationLoggingDataTables, 11);
  for (c14_i14 = 0; c14_i14 < 5; c14_i14++) {
    c14_c_obj.Value[c14_i14] = c14_cv2[c14_i14];
  }

  c14_b_emlrt_update_log_7(chartInstance, &c14_c_obj,
    chartInstance->c14_emlrtLocationLoggingDataTables, 12);
  for (c14_i15 = 0; c14_i15 < 5; c14_i15++) {
    c14_c_obj.Value[c14_i15] = c14_cv2[c14_i15];
  }

  c14_b_emlrt_update_log_7(chartInstance, &c14_c_obj,
    chartInstance->c14_emlrtLocationLoggingDataTables, 13);
  c14_d = c14_emlrt_update_log_2(chartInstance, c14_b_phi - 180.0,
    chartInstance->c14_emlrtLocationLoggingDataTables, 9);
  c14_varargin_1[0] = 0.0;
  c14_varargin_1[1] = c14_d;
  c14_varargin_1[2] = 0.0;
  for (c14_i16 = 0; c14_i16 < 3; c14_i16++) {
    c14_varargin_1[c14_i16] *= 0.017453292519943295;
  }

  for (c14_i17 = 0; c14_i17 < 3; c14_i17++) {
    c14_varargin_1[c14_i17] /= 2.0;
  }

  c14_a = c14_varargin_1[0];
  c14_b_b = c14_varargin_1[1];
  c14_c = c14_varargin_1[2];
  c14_x = c14_a;
  c14_b_x = c14_x;
  c14_b_x = muDoubleScalarCos(c14_b_x);
  c14_c_x = c14_b_b;
  c14_d_x = c14_c_x;
  c14_d_x = muDoubleScalarCos(c14_d_x);
  c14_e_x = c14_c;
  c14_f_x = c14_e_x;
  c14_f_x = muDoubleScalarCos(c14_f_x);
  c14_g_x = c14_a;
  c14_h_x = c14_g_x;
  c14_h_x = muDoubleScalarSin(c14_h_x);
  c14_i_x = c14_b_b;
  c14_j_x = c14_i_x;
  c14_j_x = muDoubleScalarSin(c14_j_x);
  c14_k_x = c14_c;
  c14_l_x = c14_k_x;
  c14_l_x = muDoubleScalarSin(c14_l_x);
  c14_qa = c14_b_x * c14_d_x * c14_f_x - c14_h_x * c14_j_x * c14_l_x;
  c14_m_x = c14_b_b;
  c14_n_x = c14_m_x;
  c14_n_x = muDoubleScalarCos(c14_n_x);
  c14_o_x = c14_c;
  c14_p_x = c14_o_x;
  c14_p_x = muDoubleScalarCos(c14_p_x);
  c14_q_x = c14_a;
  c14_r_x = c14_q_x;
  c14_r_x = muDoubleScalarSin(c14_r_x);
  c14_s_x = c14_a;
  c14_t_x = c14_s_x;
  c14_t_x = muDoubleScalarCos(c14_t_x);
  c14_u_x = c14_b_b;
  c14_v_x = c14_u_x;
  c14_v_x = muDoubleScalarSin(c14_v_x);
  c14_w_x = c14_c;
  c14_x_x = c14_w_x;
  c14_x_x = muDoubleScalarSin(c14_x_x);
  c14_qb = c14_n_x * c14_p_x * c14_r_x + c14_t_x * c14_v_x * c14_x_x;
  c14_y_x = c14_a;
  c14_ab_x = c14_y_x;
  c14_ab_x = muDoubleScalarCos(c14_ab_x);
  c14_bb_x = c14_c;
  c14_cb_x = c14_bb_x;
  c14_cb_x = muDoubleScalarCos(c14_cb_x);
  c14_db_x = c14_b_b;
  c14_eb_x = c14_db_x;
  c14_eb_x = muDoubleScalarSin(c14_eb_x);
  c14_fb_x = c14_b_b;
  c14_gb_x = c14_fb_x;
  c14_gb_x = muDoubleScalarCos(c14_gb_x);
  c14_hb_x = c14_a;
  c14_ib_x = c14_hb_x;
  c14_ib_x = muDoubleScalarSin(c14_ib_x);
  c14_jb_x = c14_c;
  c14_kb_x = c14_jb_x;
  c14_kb_x = muDoubleScalarSin(c14_kb_x);
  c14_qc = c14_ab_x * c14_cb_x * c14_eb_x - c14_gb_x * c14_ib_x * c14_kb_x;
  c14_lb_x = c14_a;
  c14_mb_x = c14_lb_x;
  c14_mb_x = muDoubleScalarCos(c14_mb_x);
  c14_nb_x = c14_b_b;
  c14_ob_x = c14_nb_x;
  c14_ob_x = muDoubleScalarCos(c14_ob_x);
  c14_pb_x = c14_c;
  c14_qb_x = c14_pb_x;
  c14_qb_x = muDoubleScalarSin(c14_qb_x);
  c14_rb_x = c14_c;
  c14_sb_x = c14_rb_x;
  c14_sb_x = muDoubleScalarCos(c14_sb_x);
  c14_tb_x = c14_a;
  c14_ub_x = c14_tb_x;
  c14_ub_x = muDoubleScalarSin(c14_ub_x);
  c14_vb_x = c14_b_b;
  c14_wb_x = c14_vb_x;
  c14_wb_x = muDoubleScalarSin(c14_wb_x);
  c14_qd = c14_mb_x * c14_ob_x * c14_qb_x + c14_sb_x * c14_ub_x * c14_wb_x;
  c14_b_qa = c14_qa;
  c14_b_qb = c14_qb;
  c14_b_qc = c14_qc;
  c14_b_qd = c14_qd;
  c14_d1 = c14_b_qa;
  c14_d2 = c14_b_qb;
  c14_d3 = c14_b_qc;
  c14_d4 = c14_b_qd;
  c14_d_obj.a = c14_d1;
  c14_d_obj.b = c14_d2;
  c14_d_obj.c = c14_d3;
  c14_d_obj.d = c14_d4;
  c14_b_st.site = &c14_emlrtRSI;
  c14_b_emlrt_update_log_4(chartInstance, &c14_d_obj,
    chartInstance->c14_emlrtLocationLoggingDataTables, 5);
  c14_c_st.site = &c14_c_emlrtRSI;
  c14_b_quaternionBase_normalize(chartInstance, &c14_c_st, &c14_d_obj);
  c14_ta = c14_d_obj.a;
  c14_tb = c14_d_obj.b;
  c14_tc = c14_d_obj.c;
  c14_td = c14_d_obj.d;
  c14_ab2 = c14_ta * c14_tb * 2.0;
  c14_ac2 = c14_ta * c14_tc * 2.0;
  c14_ad2 = c14_ta * c14_td * 2.0;
  c14_bc2 = c14_tb * c14_tc * 2.0;
  c14_bd2 = c14_tb * c14_td * 2.0;
  c14_cd2 = c14_tc * c14_td * 2.0;
  c14_aasq = c14_ta * c14_ta * 2.0 - 1.0;
  c14_bbsq = c14_tb * c14_tb * 2.0;
  c14_ccsq = c14_tc * c14_tc * 2.0;
  c14_ddsq = c14_td * c14_td * 2.0;
  c14_rmat[0] = c14_aasq + c14_bbsq;
  c14_rmat[3] = c14_bc2 + c14_ad2;
  c14_rmat[6] = c14_bd2 - c14_ac2;
  c14_rmat[1] = c14_bc2 - c14_ad2;
  c14_rmat[4] = c14_aasq + c14_ccsq;
  c14_rmat[7] = c14_cd2 + c14_ab2;
  c14_rmat[2] = c14_bd2 + c14_ac2;
  c14_rmat[5] = c14_cd2 - c14_ab2;
  c14_rmat[8] = c14_aasq + c14_ddsq;
  c14_b_emlrt_update_log_3(chartInstance, c14_rmat,
    chartInstance->c14_emlrtLocationLoggingDataTables, 4);
  for (c14_i18 = 0; c14_i18 < 6; c14_i18++) {
    c14_obj.Value[c14_i18] = c14_cv[c14_i18];
  }

  c14_b_emlrt_update_log_5(chartInstance, &c14_obj,
    chartInstance->c14_emlrtLocationLoggingDataTables, 20);
  for (c14_i19 = 0; c14_i19 < 3; c14_i19++) {
    c14_b_obj.Value[c14_i19] = c14_cv1[c14_i19];
  }

  c14_b_emlrt_update_log_6(chartInstance, &c14_b_obj,
    chartInstance->c14_emlrtLocationLoggingDataTables, 21);
  for (c14_i20 = 0; c14_i20 < 5; c14_i20++) {
    c14_c_obj.Value[c14_i20] = c14_cv2[c14_i20];
  }

  c14_b_emlrt_update_log_7(chartInstance, &c14_c_obj,
    chartInstance->c14_emlrtLocationLoggingDataTables, 22);
  for (c14_i21 = 0; c14_i21 < 5; c14_i21++) {
    c14_c_obj.Value[c14_i21] = c14_cv2[c14_i21];
  }

  c14_b_emlrt_update_log_7(chartInstance, &c14_c_obj,
    chartInstance->c14_emlrtLocationLoggingDataTables, 23);
  c14_d5 = c14_emlrt_update_log_2(chartInstance, 180.0 - c14_b_phi,
    chartInstance->c14_emlrtLocationLoggingDataTables, 19);
  c14_varargin_1[0] = 180.0;
  c14_varargin_1[1] = c14_d5;
  c14_varargin_1[2] = 0.0;
  for (c14_i22 = 0; c14_i22 < 3; c14_i22++) {
    c14_varargin_1[c14_i22] *= 0.017453292519943295;
  }

  for (c14_i23 = 0; c14_i23 < 3; c14_i23++) {
    c14_varargin_1[c14_i23] /= 2.0;
  }

  c14_b_a = c14_varargin_1[0];
  c14_c_b = c14_varargin_1[1];
  c14_b_c = c14_varargin_1[2];
  c14_xb_x = c14_b_a;
  c14_yb_x = c14_xb_x;
  c14_yb_x = muDoubleScalarCos(c14_yb_x);
  c14_ac_x = c14_c_b;
  c14_bc_x = c14_ac_x;
  c14_bc_x = muDoubleScalarCos(c14_bc_x);
  c14_cc_x = c14_b_c;
  c14_dc_x = c14_cc_x;
  c14_dc_x = muDoubleScalarCos(c14_dc_x);
  c14_ec_x = c14_b_a;
  c14_fc_x = c14_ec_x;
  c14_fc_x = muDoubleScalarSin(c14_fc_x);
  c14_gc_x = c14_c_b;
  c14_hc_x = c14_gc_x;
  c14_hc_x = muDoubleScalarSin(c14_hc_x);
  c14_ic_x = c14_b_c;
  c14_jc_x = c14_ic_x;
  c14_jc_x = muDoubleScalarSin(c14_jc_x);
  c14_c_qa = c14_yb_x * c14_bc_x * c14_dc_x - c14_fc_x * c14_hc_x * c14_jc_x;
  c14_kc_x = c14_c_b;
  c14_lc_x = c14_kc_x;
  c14_lc_x = muDoubleScalarCos(c14_lc_x);
  c14_mc_x = c14_b_c;
  c14_nc_x = c14_mc_x;
  c14_nc_x = muDoubleScalarCos(c14_nc_x);
  c14_oc_x = c14_b_a;
  c14_pc_x = c14_oc_x;
  c14_pc_x = muDoubleScalarSin(c14_pc_x);
  c14_qc_x = c14_b_a;
  c14_rc_x = c14_qc_x;
  c14_rc_x = muDoubleScalarCos(c14_rc_x);
  c14_sc_x = c14_c_b;
  c14_tc_x = c14_sc_x;
  c14_tc_x = muDoubleScalarSin(c14_tc_x);
  c14_uc_x = c14_b_c;
  c14_vc_x = c14_uc_x;
  c14_vc_x = muDoubleScalarSin(c14_vc_x);
  c14_c_qb = c14_lc_x * c14_nc_x * c14_pc_x + c14_rc_x * c14_tc_x * c14_vc_x;
  c14_wc_x = c14_b_a;
  c14_xc_x = c14_wc_x;
  c14_xc_x = muDoubleScalarCos(c14_xc_x);
  c14_yc_x = c14_b_c;
  c14_ad_x = c14_yc_x;
  c14_ad_x = muDoubleScalarCos(c14_ad_x);
  c14_bd_x = c14_c_b;
  c14_cd_x = c14_bd_x;
  c14_cd_x = muDoubleScalarSin(c14_cd_x);
  c14_dd_x = c14_c_b;
  c14_ed_x = c14_dd_x;
  c14_ed_x = muDoubleScalarCos(c14_ed_x);
  c14_fd_x = c14_b_a;
  c14_gd_x = c14_fd_x;
  c14_gd_x = muDoubleScalarSin(c14_gd_x);
  c14_hd_x = c14_b_c;
  c14_id_x = c14_hd_x;
  c14_id_x = muDoubleScalarSin(c14_id_x);
  c14_c_qc = c14_xc_x * c14_ad_x * c14_cd_x - c14_ed_x * c14_gd_x * c14_id_x;
  c14_jd_x = c14_b_a;
  c14_kd_x = c14_jd_x;
  c14_kd_x = muDoubleScalarCos(c14_kd_x);
  c14_ld_x = c14_c_b;
  c14_md_x = c14_ld_x;
  c14_md_x = muDoubleScalarCos(c14_md_x);
  c14_nd_x = c14_b_c;
  c14_od_x = c14_nd_x;
  c14_od_x = muDoubleScalarSin(c14_od_x);
  c14_pd_x = c14_b_c;
  c14_qd_x = c14_pd_x;
  c14_qd_x = muDoubleScalarCos(c14_qd_x);
  c14_rd_x = c14_b_a;
  c14_sd_x = c14_rd_x;
  c14_sd_x = muDoubleScalarSin(c14_sd_x);
  c14_td_x = c14_c_b;
  c14_ud_x = c14_td_x;
  c14_ud_x = muDoubleScalarSin(c14_ud_x);
  c14_c_qd = c14_kd_x * c14_md_x * c14_od_x + c14_qd_x * c14_sd_x * c14_ud_x;
  c14_d_qa = c14_c_qa;
  c14_d_qb = c14_c_qb;
  c14_d_qc = c14_c_qc;
  c14_d_qd = c14_c_qd;
  c14_d6 = c14_d_qa;
  c14_d7 = c14_d_qb;
  c14_d8 = c14_d_qc;
  c14_d9 = c14_d_qd;
  c14_d_obj.a = c14_d6;
  c14_d_obj.b = c14_d7;
  c14_d_obj.c = c14_d8;
  c14_d_obj.d = c14_d9;
  c14_b_st.site = &c14_b_emlrtRSI;
  c14_b_emlrt_update_log_4(chartInstance, &c14_d_obj,
    chartInstance->c14_emlrtLocationLoggingDataTables, 15);
  c14_c_st.site = &c14_c_emlrtRSI;
  c14_b_quaternionBase_normalize(chartInstance, &c14_c_st, &c14_d_obj);
  c14_b_ta = c14_d_obj.a;
  c14_b_tb = c14_d_obj.b;
  c14_b_tc = c14_d_obj.c;
  c14_b_td = c14_d_obj.d;
  c14_b_ab2 = c14_b_ta * c14_b_tb * 2.0;
  c14_b_ac2 = c14_b_ta * c14_b_tc * 2.0;
  c14_b_ad2 = c14_b_ta * c14_b_td * 2.0;
  c14_b_bc2 = c14_b_tb * c14_b_tc * 2.0;
  c14_b_bd2 = c14_b_tb * c14_b_td * 2.0;
  c14_b_cd2 = c14_b_tc * c14_b_td * 2.0;
  c14_b_aasq = c14_b_ta * c14_b_ta * 2.0 - 1.0;
  c14_b_bbsq = c14_b_tb * c14_b_tb * 2.0;
  c14_b_ccsq = c14_b_tc * c14_b_tc * 2.0;
  c14_b_ddsq = c14_b_td * c14_b_td * 2.0;
  c14_b_rmat[0] = c14_b_aasq + c14_b_bbsq;
  c14_b_rmat[3] = c14_b_bc2 + c14_b_ad2;
  c14_b_rmat[6] = c14_b_bd2 - c14_b_ac2;
  c14_b_rmat[1] = c14_b_bc2 - c14_b_ad2;
  c14_b_rmat[4] = c14_b_aasq + c14_b_ccsq;
  c14_b_rmat[7] = c14_b_cd2 + c14_b_ab2;
  c14_b_rmat[2] = c14_b_bd2 + c14_b_ac2;
  c14_b_rmat[5] = c14_b_cd2 - c14_b_ab2;
  c14_b_rmat[8] = c14_b_aasq + c14_b_ddsq;
  c14_b_emlrt_update_log_3(chartInstance, c14_b_rmat,
    chartInstance->c14_emlrtLocationLoggingDataTables, 14);
  for (c14_i24 = 0; c14_i24 < 3; c14_i24++) {
    c14_varargin_1[c14_i24] = (*chartInstance->c14_accel_SNED)[c14_i24];
  }

  for (c14_i25 = 0; c14_i25 < 3; c14_i25++) {
    c14_c_rmat[c14_i25] = 0.0;
    c14_i27 = 0;
    for (c14_i28 = 0; c14_i28 < 3; c14_i28++) {
      c14_c_rmat[c14_i25] += c14_rmat[c14_i27 + c14_i25] *
        c14_varargin_1[c14_i28];
      c14_i27 += 3;
    }
  }

  for (c14_i26 = 0; c14_i26 < 3; c14_i26++) {
    (*chartInstance->c14_accel_VNED)[c14_i26] = c14_c_rmat[c14_i26];
  }

  c14_b_emlrt_update_log_9(chartInstance, *chartInstance->c14_accel_VNED,
    chartInstance->c14_emlrtLocationLoggingDataTables, 25);
  c14_b_emlrt_update_log_8(chartInstance, *chartInstance->c14_accel_VNED,
    chartInstance->c14_emlrtLocationLoggingDataTables, 24);
  for (c14_i29 = 0; c14_i29 < 3; c14_i29++) {
    c14_varargin_1[c14_i29] = (*chartInstance->c14_gyro_SNED)[c14_i29];
  }

  for (c14_i30 = 0; c14_i30 < 3; c14_i30++) {
    c14_d_rmat[c14_i30] = 0.0;
    c14_i32 = 0;
    for (c14_i33 = 0; c14_i33 < 3; c14_i33++) {
      c14_d_rmat[c14_i30] += c14_rmat[c14_i32 + c14_i30] *
        c14_varargin_1[c14_i33];
      c14_i32 += 3;
    }
  }

  for (c14_i31 = 0; c14_i31 < 3; c14_i31++) {
    (*chartInstance->c14_gyro_VNED)[c14_i31] = c14_d_rmat[c14_i31];
  }

  c14_b_emlrt_update_log_9(chartInstance, *chartInstance->c14_gyro_VNED,
    chartInstance->c14_emlrtLocationLoggingDataTables, 27);
  c14_b_emlrt_update_log_8(chartInstance, *chartInstance->c14_gyro_VNED,
    chartInstance->c14_emlrtLocationLoggingDataTables, 26);
  for (c14_i34 = 0; c14_i34 < 3; c14_i34++) {
    c14_varargin_1[c14_i34] = (*chartInstance->c14_mag_SNED)[c14_i34];
  }

  for (c14_i35 = 0; c14_i35 < 3; c14_i35++) {
    c14_e_rmat[c14_i35] = 0.0;
    c14_i37 = 0;
    for (c14_i38 = 0; c14_i38 < 3; c14_i38++) {
      c14_e_rmat[c14_i35] += c14_b_rmat[c14_i37 + c14_i35] *
        c14_varargin_1[c14_i38];
      c14_i37 += 3;
    }
  }

  for (c14_i36 = 0; c14_i36 < 3; c14_i36++) {
    (*chartInstance->c14_mag_VNED)[c14_i36] = c14_e_rmat[c14_i36];
  }

  c14_b_emlrt_update_log_9(chartInstance, *chartInstance->c14_mag_VNED,
    chartInstance->c14_emlrtLocationLoggingDataTables, 29);
  c14_b_emlrt_update_log_8(chartInstance, *chartInstance->c14_mag_VNED,
    chartInstance->c14_emlrtLocationLoggingDataTables, 28);
  c14_do_animation_call_c14_SFS(chartInstance);
  c14_b12 = false;
  for (c14_i39 = 0; c14_i39 < 3; c14_i39++) {
    c14_b12 = (c14_b12 || ((*chartInstance->c14_accel_VNED)[c14_i39] > 30.0));
  }

  c14_b13 = c14_b12;
  if (c14_b13) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 3U, 1U);
  }

  c14_b14 = false;
  for (c14_i40 = 0; c14_i40 < 3; c14_i40++) {
    c14_b14 = (c14_b14 || ((*chartInstance->c14_accel_VNED)[c14_i40] < -30.0));
  }

  c14_b15 = c14_b14;
  if (c14_b15) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 3U, 0U);
  }

  for (c14_i41 = 0; c14_i41 < 3; c14_i41++) {
    covrtSigUpdateFcn(chartInstance->c14_covrtInstance, 3U,
                      (*chartInstance->c14_accel_VNED)[c14_i41]);
  }

  c14_b16 = false;
  for (c14_i42 = 0; c14_i42 < 3; c14_i42++) {
    c14_b16 = (c14_b16 || ((*chartInstance->c14_gyro_VNED)[c14_i42] > 2.5));
  }

  c14_b17 = c14_b16;
  if (c14_b17) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 4U, 1U);
  }

  c14_b18 = false;
  for (c14_i43 = 0; c14_i43 < 3; c14_i43++) {
    c14_b18 = (c14_b18 || ((*chartInstance->c14_gyro_VNED)[c14_i43] < -2.5));
  }

  c14_b19 = c14_b18;
  if (c14_b19) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 4U, 0U);
  }

  for (c14_i44 = 0; c14_i44 < 3; c14_i44++) {
    covrtSigUpdateFcn(chartInstance->c14_covrtInstance, 4U,
                      (*chartInstance->c14_gyro_VNED)[c14_i44]);
  }

  c14_b20 = false;
  for (c14_i45 = 0; c14_i45 < 3; c14_i45++) {
    c14_b20 = (c14_b20 || ((*chartInstance->c14_mag_VNED)[c14_i45] > 200.0));
  }

  c14_b21 = c14_b20;
  if (c14_b21) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 5U, 1U);
  }

  c14_b22 = false;
  for (c14_i46 = 0; c14_i46 < 3; c14_i46++) {
    c14_b22 = (c14_b22 || ((*chartInstance->c14_mag_VNED)[c14_i46] < -200.0));
  }

  c14_b23 = c14_b22;
  if (c14_b23) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 5U, 0U);
  }

  for (c14_i47 = 0; c14_i47 < 3; c14_i47++) {
    covrtSigUpdateFcn(chartInstance->c14_covrtInstance, 5U,
                      (*chartInstance->c14_mag_VNED)[c14_i47]);
  }
}

static void ext_mode_exec_c14_SFS(SFc14_SFSInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c14_update_jit_animation_c14_SFS(SFc14_SFSInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c14_do_animation_call_c14_SFS(SFc14_SFSInstanceStruct *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static const mxArray *get_sim_state_c14_SFS(SFc14_SFSInstanceStruct
  *chartInstance)
{
  const mxArray *c14_b_y = NULL;
  const mxArray *c14_c_y = NULL;
  const mxArray *c14_d_y = NULL;
  const mxArray *c14_e_y = NULL;
  const mxArray *c14_st;
  const mxArray *c14_y = NULL;
  c14_st = NULL;
  c14_st = NULL;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_createcellmatrix(4, 1), false);
  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_create("y", *chartInstance->c14_accel_VNED, 0,
    0U, 1U, 0U, 2, 1, 3), false);
  sf_mex_setcell(c14_y, 0, c14_b_y);
  c14_c_y = NULL;
  sf_mex_assign(&c14_c_y, sf_mex_create("y", *chartInstance->c14_gyro_VNED, 0,
    0U, 1U, 0U, 2, 1, 3), false);
  sf_mex_setcell(c14_y, 1, c14_c_y);
  c14_d_y = NULL;
  sf_mex_assign(&c14_d_y, sf_mex_create("y", *chartInstance->c14_mag_VNED, 0, 0U,
    1U, 0U, 2, 1, 3), false);
  sf_mex_setcell(c14_y, 2, c14_d_y);
  c14_e_y = NULL;
  sf_mex_assign(&c14_e_y, sf_mex_create("y",
    &chartInstance->c14_is_active_c14_SFS, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c14_y, 3, c14_e_y);
  sf_mex_assign(&c14_st, c14_y, false);
  return c14_st;
}

static void set_sim_state_c14_SFS(SFc14_SFSInstanceStruct *chartInstance, const
  mxArray *c14_st)
{
  const mxArray *c14_u;
  real_T c14_dv[3];
  real_T c14_dv1[3];
  real_T c14_dv2[3];
  int32_T c14_i;
  int32_T c14_i1;
  int32_T c14_i2;
  chartInstance->c14_doneDoubleBufferReInit = true;
  c14_u = sf_mex_dup(c14_st);
  c14_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c14_u, 0)),
                       "accel_VNED", c14_dv);
  for (c14_i = 0; c14_i < 3; c14_i++) {
    (*chartInstance->c14_accel_VNED)[c14_i] = c14_dv[c14_i];
  }

  c14_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c14_u, 1)),
                       "gyro_VNED", c14_dv1);
  for (c14_i1 = 0; c14_i1 < 3; c14_i1++) {
    (*chartInstance->c14_gyro_VNED)[c14_i1] = c14_dv1[c14_i1];
  }

  c14_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c14_u, 2)),
                       "mag_VNED", c14_dv2);
  for (c14_i2 = 0; c14_i2 < 3; c14_i2++) {
    (*chartInstance->c14_mag_VNED)[c14_i2] = c14_dv2[c14_i2];
  }

  chartInstance->c14_is_active_c14_SFS = c14_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c14_u, 3)), "is_active_c14_SFS");
  sf_mex_destroy(&c14_u);
  sf_mex_destroy(&c14_st);
}

static void initSimStructsc14_SFS(SFc14_SFSInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c14_emlrt_update_log_1(SFc14_SFSInstanceStruct *chartInstance,
  real_T c14_in[3], emlrtLocationLoggingDataType c14_table[], int32_T c14_index,
  real_T c14_out[3])
{
  int32_T c14_i;
  for (c14_i = 0; c14_i < 3; c14_i++) {
    c14_out[c14_i] = c14_in[c14_i];
  }

  c14_b_emlrt_update_log_1(chartInstance, c14_out, c14_table, c14_index);
}

static real_T c14_emlrt_update_log_2(SFc14_SFSInstanceStruct *chartInstance,
  real_T c14_in, emlrtLocationLoggingDataType c14_table[], int32_T c14_index)
{
  emlrtLocationLoggingDataType *c14_b_table;
  emlrtLocationLoggingHistogramType *c14_histTable;
  real_T c14_inDouble;
  real_T c14_localMax;
  real_T c14_localMin;
  real_T c14_significand;
  int32_T c14_exponent;
  boolean_T c14_isLoggingEnabledHere;
  (void)chartInstance;
  c14_isLoggingEnabledHere = (c14_index >= 0);
  if (c14_isLoggingEnabledHere) {
    c14_b_table = (emlrtLocationLoggingDataType *)&c14_table[c14_index];
    c14_localMin = c14_b_table[0U].SimMin;
    c14_localMax = c14_b_table[0U].SimMax;
    c14_histTable = c14_b_table[0U].HistogramTable;

    /* Simulation Min-Max logging. */
    if (c14_in < c14_localMin) {
      c14_localMin = c14_in;
    }

    if (c14_in > c14_localMax) {
      c14_localMax = c14_in;
    }

    /* Histogram logging. */
    c14_inDouble = c14_in;
    c14_histTable->TotalNumberOfValues++;
    if (c14_inDouble == 0.0) {
      c14_histTable->NumberOfZeros++;
    } else {
      c14_histTable->SimSum += c14_inDouble;
      if ((!muDoubleScalarIsInf(c14_inDouble)) && (!muDoubleScalarIsNaN
           (c14_inDouble))) {
        c14_significand = frexp(c14_inDouble, &c14_exponent);
        if (c14_exponent > 128) {
          c14_exponent = 128;
        }

        if (c14_exponent < -127) {
          c14_exponent = -127;
        }

        if (c14_significand < 0.0) {
          c14_histTable->NumberOfNegativeValues++;
          c14_histTable->HistogramOfNegativeValues[127 + c14_exponent]++;
        } else {
          c14_histTable->NumberOfPositiveValues++;
          c14_histTable->HistogramOfPositiveValues[127 + c14_exponent]++;
        }
      }
    }

    c14_b_table[0U].SimMin = c14_localMin;
    c14_b_table[0U].SimMax = c14_localMax;

    /* IsAlwaysInteger logging. */
    if (c14_in != muDoubleScalarFloor(c14_in)) {
      c14_b_table[0U].IsAlwaysInteger = false;
    }
  }

  return c14_in;
}

static void c14_emlrt_update_log_3(SFc14_SFSInstanceStruct *chartInstance,
  real_T c14_in[9], emlrtLocationLoggingDataType c14_table[], int32_T c14_index,
  real_T c14_out[9])
{
  int32_T c14_i;
  for (c14_i = 0; c14_i < 9; c14_i++) {
    c14_out[c14_i] = c14_in[c14_i];
  }

  c14_b_emlrt_update_log_3(chartInstance, c14_out, c14_table, c14_index);
}

static c14_quaternion c14_emlrt_update_log_4(SFc14_SFSInstanceStruct
  *chartInstance, c14_quaternion c14_in, emlrtLocationLoggingDataType c14_table[],
  int32_T c14_index)
{
  c14_quaternion c14_out;
  c14_out = c14_in;
  c14_b_emlrt_update_log_4(chartInstance, &c14_out, c14_table, c14_index);
  return c14_out;
}

static c14_rtString c14_emlrt_update_log_5(SFc14_SFSInstanceStruct
  *chartInstance, c14_rtString c14_in, emlrtLocationLoggingDataType c14_table[],
  int32_T c14_index)
{
  c14_rtString c14_out;
  c14_out = c14_in;
  c14_b_emlrt_update_log_5(chartInstance, &c14_out, c14_table, c14_index);
  return c14_out;
}

static c14_rtString_1 c14_emlrt_update_log_6(SFc14_SFSInstanceStruct
  *chartInstance, c14_rtString_1 c14_in, emlrtLocationLoggingDataType c14_table[],
  int32_T c14_index)
{
  c14_rtString_1 c14_out;
  c14_out = c14_in;
  c14_b_emlrt_update_log_6(chartInstance, &c14_out, c14_table, c14_index);
  return c14_out;
}

static c14_rtString_2 c14_emlrt_update_log_7(SFc14_SFSInstanceStruct
  *chartInstance, c14_rtString_2 c14_in, emlrtLocationLoggingDataType c14_table[],
  int32_T c14_index)
{
  c14_rtString_2 c14_out;
  c14_out = c14_in;
  c14_b_emlrt_update_log_7(chartInstance, &c14_out, c14_table, c14_index);
  return c14_out;
}

static void c14_emlrt_update_log_8(SFc14_SFSInstanceStruct *chartInstance,
  real_T c14_in[3], emlrtLocationLoggingDataType c14_table[], int32_T c14_index,
  real_T c14_out[3])
{
  int32_T c14_i;
  for (c14_i = 0; c14_i < 3; c14_i++) {
    c14_out[c14_i] = c14_in[c14_i];
  }

  c14_b_emlrt_update_log_8(chartInstance, c14_out, c14_table, c14_index);
}

static void c14_emlrt_update_log_9(SFc14_SFSInstanceStruct *chartInstance,
  real_T c14_in[3], emlrtLocationLoggingDataType c14_table[], int32_T c14_index,
  real_T c14_out[3])
{
  int32_T c14_i;
  for (c14_i = 0; c14_i < 3; c14_i++) {
    c14_out[c14_i] = c14_in[c14_i];
  }

  c14_b_emlrt_update_log_9(chartInstance, c14_out, c14_table, c14_index);
}

static void c14_emlrtInitVarDataTables(SFc14_SFSInstanceStruct *chartInstance,
  emlrtLocationLoggingDataType c14_dataTables[30],
  emlrtLocationLoggingHistogramType c14_histTables[30])
{
  int32_T c14_i;
  int32_T c14_iH;
  (void)chartInstance;
  for (c14_i = 0; c14_i < 30; c14_i++) {
    c14_dataTables[c14_i].SimMin = rtInf;
    c14_dataTables[c14_i].SimMax = rtMinusInf;
    c14_dataTables[c14_i].OverflowWraps = 0;
    c14_dataTables[c14_i].Saturations = 0;
    c14_dataTables[c14_i].IsAlwaysInteger = true;
    c14_dataTables[c14_i].HistogramTable = &c14_histTables[c14_i];
    c14_histTables[c14_i].NumberOfZeros = 0.0;
    c14_histTables[c14_i].NumberOfPositiveValues = 0.0;
    c14_histTables[c14_i].NumberOfNegativeValues = 0.0;
    c14_histTables[c14_i].TotalNumberOfValues = 0.0;
    c14_histTables[c14_i].SimSum = 0.0;
    for (c14_iH = 0; c14_iH < 256; c14_iH++) {
      c14_histTables[c14_i].HistogramOfPositiveValues[c14_iH] = 0.0;
      c14_histTables[c14_i].HistogramOfNegativeValues[c14_iH] = 0.0;
    }
  }
}

const mxArray *sf_c14_SFS_get_eml_resolved_functions_info(void)
{
  const mxArray *c14_nameCaptureInfo = NULL;
  c14_nameCaptureInfo = NULL;
  sf_mex_assign(&c14_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c14_nameCaptureInfo;
}

static c14_quaternion c14_quaternionBase_normalize(SFc14_SFSInstanceStruct
  *chartInstance, const emlrtStack *c14_sp, c14_quaternion c14_q)
{
  c14_quaternion c14_b_q;
  c14_b_q = c14_q;
  c14_b_quaternionBase_normalize(chartInstance, c14_sp, &c14_b_q);
  return c14_b_q;
}

static void c14_emlrt_marshallIn(SFc14_SFSInstanceStruct *chartInstance, const
  mxArray *c14_b_accel_VNED, const char_T *c14_identifier, real_T c14_y[3])
{
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = (const char_T *)c14_identifier;
  c14_thisId.fParent = NULL;
  c14_thisId.bParentIsCell = false;
  c14_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_b_accel_VNED),
    &c14_thisId, c14_y);
  sf_mex_destroy(&c14_b_accel_VNED);
}

static void c14_b_emlrt_marshallIn(SFc14_SFSInstanceStruct *chartInstance, const
  mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId, real_T c14_y[3])
{
  real_T c14_dv[3];
  int32_T c14_i;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), c14_dv, 1, 0, 0U, 1, 0U, 2, 1,
                3);
  for (c14_i = 0; c14_i < 3; c14_i++) {
    c14_y[c14_i] = c14_dv[c14_i];
  }

  sf_mex_destroy(&c14_u);
}

static uint8_T c14_c_emlrt_marshallIn(SFc14_SFSInstanceStruct *chartInstance,
  const mxArray *c14_b_is_active_c14_SFS, const char_T *c14_identifier)
{
  emlrtMsgIdentifier c14_thisId;
  uint8_T c14_y;
  c14_thisId.fIdentifier = (const char_T *)c14_identifier;
  c14_thisId.fParent = NULL;
  c14_thisId.bParentIsCell = false;
  c14_y = c14_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c14_b_is_active_c14_SFS), &c14_thisId);
  sf_mex_destroy(&c14_b_is_active_c14_SFS);
  return c14_y;
}

static uint8_T c14_d_emlrt_marshallIn(SFc14_SFSInstanceStruct *chartInstance,
  const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  uint8_T c14_b_u;
  uint8_T c14_y;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_b_u, 1, 3, 0U, 0, 0U, 0);
  c14_y = c14_b_u;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_slStringInitializeDynamicBuffers(SFc14_SFSInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c14_chart_data_browse_helper(SFc14_SFSInstanceStruct *chartInstance,
  int32_T c14_ssIdNumber, const mxArray **c14_mxData, uint8_T *c14_isValueTooBig)
{
  *c14_mxData = NULL;
  *c14_mxData = NULL;
  *c14_isValueTooBig = 0U;
  switch (c14_ssIdNumber) {
   case 5U:
    sf_mex_assign(c14_mxData, sf_mex_create("mxData",
      *chartInstance->c14_accel_VNED, 0, 0U, 1U, 0U, 2, 1, 3), false);
    break;

   case 8U:
    sf_mex_assign(c14_mxData, sf_mex_create("mxData",
      *chartInstance->c14_gyro_VNED, 0, 0U, 1U, 0U, 2, 1, 3), false);
    break;

   case 4U:
    sf_mex_assign(c14_mxData, sf_mex_create("mxData",
      *chartInstance->c14_accel_SNED, 0, 0U, 1U, 0U, 2, 3, 1), false);
    break;

   case 6U:
    sf_mex_assign(c14_mxData, sf_mex_create("mxData",
      *chartInstance->c14_gyro_SNED, 0, 0U, 1U, 0U, 2, 3, 1), false);
    break;

   case 7U:
    sf_mex_assign(c14_mxData, sf_mex_create("mxData",
      *chartInstance->c14_mag_SNED, 0, 0U, 1U, 0U, 2, 3, 1), false);
    break;

   case 9U:
    sf_mex_assign(c14_mxData, sf_mex_create("mxData",
      *chartInstance->c14_mag_VNED, 0, 0U, 1U, 0U, 2, 1, 3), false);
    break;

   case 14U:
    sf_mex_assign(c14_mxData, sf_mex_create("mxData", &chartInstance->c14_phi, 0,
      0U, 0U, 0U, 0), false);
    break;
  }
}

static void c14_b_emlrt_update_log_1(SFc14_SFSInstanceStruct *chartInstance,
  real_T c14_in[3], emlrtLocationLoggingDataType c14_table[], int32_T c14_index)
{
  emlrtLocationLoggingDataType *c14_b_table;
  emlrtLocationLoggingHistogramType *c14_histTable;
  real_T c14_inDouble;
  real_T c14_localMax;
  real_T c14_localMin;
  real_T c14_significand;
  int32_T c14_b_i;
  int32_T c14_exponent;
  int32_T c14_i;
  boolean_T c14_isLoggingEnabledHere;
  (void)chartInstance;
  c14_isLoggingEnabledHere = (c14_index >= 0);
  if (c14_isLoggingEnabledHere) {
    c14_b_table = (emlrtLocationLoggingDataType *)&c14_table[c14_index];
    c14_localMin = c14_b_table[0U].SimMin;
    c14_localMax = c14_b_table[0U].SimMax;
    c14_histTable = c14_b_table[0U].HistogramTable;
    for (c14_i = 0; c14_i < 3; c14_i++) {
      /* Simulation Min-Max logging. */
      if (c14_in[c14_i] < c14_localMin) {
        c14_localMin = c14_in[c14_i];
      }

      if (c14_in[c14_i] > c14_localMax) {
        c14_localMax = c14_in[c14_i];
      }

      /* Histogram logging. */
      c14_inDouble = c14_in[c14_i];
      c14_histTable->TotalNumberOfValues++;
      if (c14_inDouble == 0.0) {
        c14_histTable->NumberOfZeros++;
      } else {
        c14_histTable->SimSum += c14_inDouble;
        if ((!muDoubleScalarIsInf(c14_inDouble)) && (!muDoubleScalarIsNaN
             (c14_inDouble))) {
          c14_significand = frexp(c14_inDouble, &c14_exponent);
          if (c14_exponent > 128) {
            c14_exponent = 128;
          }

          if (c14_exponent < -127) {
            c14_exponent = -127;
          }

          if (c14_significand < 0.0) {
            c14_histTable->NumberOfNegativeValues++;
            c14_histTable->HistogramOfNegativeValues[127 + c14_exponent]++;
          } else {
            c14_histTable->NumberOfPositiveValues++;
            c14_histTable->HistogramOfPositiveValues[127 + c14_exponent]++;
          }
        }
      }
    }

    c14_b_table[0U].SimMin = c14_localMin;
    c14_b_table[0U].SimMax = c14_localMax;

    /* IsAlwaysInteger logging. */
    c14_b_i = 0;
    while (c14_b_table[0U].IsAlwaysInteger && (c14_b_i < 3)) {
      if (c14_in[c14_b_i] != muDoubleScalarFloor(c14_in[c14_b_i])) {
        c14_b_table[0U].IsAlwaysInteger = false;
      }

      c14_b_i++;
    }
  }
}

static void c14_b_emlrt_update_log_3(SFc14_SFSInstanceStruct *chartInstance,
  real_T c14_in[9], emlrtLocationLoggingDataType c14_table[], int32_T c14_index)
{
  emlrtLocationLoggingDataType *c14_b_table;
  emlrtLocationLoggingHistogramType *c14_histTable;
  real_T c14_inDouble;
  real_T c14_localMax;
  real_T c14_localMin;
  real_T c14_significand;
  int32_T c14_b_i;
  int32_T c14_exponent;
  int32_T c14_i;
  boolean_T c14_isLoggingEnabledHere;
  (void)chartInstance;
  c14_isLoggingEnabledHere = (c14_index >= 0);
  if (c14_isLoggingEnabledHere) {
    c14_b_table = (emlrtLocationLoggingDataType *)&c14_table[c14_index];
    c14_localMin = c14_b_table[0U].SimMin;
    c14_localMax = c14_b_table[0U].SimMax;
    c14_histTable = c14_b_table[0U].HistogramTable;
    for (c14_i = 0; c14_i < 9; c14_i++) {
      /* Simulation Min-Max logging. */
      if (c14_in[c14_i] < c14_localMin) {
        c14_localMin = c14_in[c14_i];
      }

      if (c14_in[c14_i] > c14_localMax) {
        c14_localMax = c14_in[c14_i];
      }

      /* Histogram logging. */
      c14_inDouble = c14_in[c14_i];
      c14_histTable->TotalNumberOfValues++;
      if (c14_inDouble == 0.0) {
        c14_histTable->NumberOfZeros++;
      } else {
        c14_histTable->SimSum += c14_inDouble;
        if ((!muDoubleScalarIsInf(c14_inDouble)) && (!muDoubleScalarIsNaN
             (c14_inDouble))) {
          c14_significand = frexp(c14_inDouble, &c14_exponent);
          if (c14_exponent > 128) {
            c14_exponent = 128;
          }

          if (c14_exponent < -127) {
            c14_exponent = -127;
          }

          if (c14_significand < 0.0) {
            c14_histTable->NumberOfNegativeValues++;
            c14_histTable->HistogramOfNegativeValues[127 + c14_exponent]++;
          } else {
            c14_histTable->NumberOfPositiveValues++;
            c14_histTable->HistogramOfPositiveValues[127 + c14_exponent]++;
          }
        }
      }
    }

    c14_b_table[0U].SimMin = c14_localMin;
    c14_b_table[0U].SimMax = c14_localMax;

    /* IsAlwaysInteger logging. */
    c14_b_i = 0;
    while (c14_b_table[0U].IsAlwaysInteger && (c14_b_i < 9)) {
      if (c14_in[c14_b_i] != muDoubleScalarFloor(c14_in[c14_b_i])) {
        c14_b_table[0U].IsAlwaysInteger = false;
      }

      c14_b_i++;
    }
  }
}

static void c14_b_emlrt_update_log_4(SFc14_SFSInstanceStruct *chartInstance,
  c14_quaternion *c14_in, emlrtLocationLoggingDataType c14_table[], int32_T
  c14_index)
{
  emlrtLocationLoggingDataType *c14_b_table;
  emlrtLocationLoggingHistogramType *c14_b_histTable;
  emlrtLocationLoggingHistogramType *c14_c_histTable;
  emlrtLocationLoggingHistogramType *c14_d_histTable;
  emlrtLocationLoggingHistogramType *c14_histTable;
  real_T c14_b_inDouble;
  real_T c14_b_localMax;
  real_T c14_b_localMin;
  real_T c14_b_significand;
  real_T c14_c_inDouble;
  real_T c14_c_localMax;
  real_T c14_c_localMin;
  real_T c14_c_significand;
  real_T c14_d_inDouble;
  real_T c14_d_localMax;
  real_T c14_d_localMin;
  real_T c14_d_significand;
  real_T c14_inDouble;
  real_T c14_localMax;
  real_T c14_localMin;
  real_T c14_significand;
  int32_T c14_b_exponent;
  int32_T c14_c_exponent;
  int32_T c14_d_exponent;
  int32_T c14_exponent;
  boolean_T c14_isLoggingEnabledHere;
  (void)chartInstance;
  c14_isLoggingEnabledHere = (c14_index >= 0);
  if (c14_isLoggingEnabledHere) {
    c14_b_table = (emlrtLocationLoggingDataType *)&c14_table[c14_index];
    c14_localMin = c14_b_table[0U].SimMin;
    c14_localMax = c14_b_table[0U].SimMax;
    c14_histTable = c14_b_table[0U].HistogramTable;

    /* Simulation Min-Max logging. */
    if (c14_in->a < c14_localMin) {
      c14_localMin = c14_in->a;
    }

    if (c14_in->a > c14_localMax) {
      c14_localMax = c14_in->a;
    }

    /* Histogram logging. */
    c14_inDouble = c14_in->a;
    c14_histTable->TotalNumberOfValues++;
    if (c14_inDouble == 0.0) {
      c14_histTable->NumberOfZeros++;
    } else {
      c14_histTable->SimSum += c14_inDouble;
      if ((!muDoubleScalarIsInf(c14_inDouble)) && (!muDoubleScalarIsNaN
           (c14_inDouble))) {
        c14_significand = frexp(c14_inDouble, &c14_exponent);
        if (c14_exponent > 128) {
          c14_exponent = 128;
        }

        if (c14_exponent < -127) {
          c14_exponent = -127;
        }

        if (c14_significand < 0.0) {
          c14_histTable->NumberOfNegativeValues++;
          c14_histTable->HistogramOfNegativeValues[127 + c14_exponent]++;
        } else {
          c14_histTable->NumberOfPositiveValues++;
          c14_histTable->HistogramOfPositiveValues[127 + c14_exponent]++;
        }
      }
    }

    c14_b_table[0U].SimMin = c14_localMin;
    c14_b_table[0U].SimMax = c14_localMax;

    /* IsAlwaysInteger logging. */
    if (c14_in->a != muDoubleScalarFloor(c14_in->a)) {
      c14_b_table[0U].IsAlwaysInteger = false;
    }

    c14_b_localMin = c14_b_table[1U].SimMin;
    c14_b_localMax = c14_b_table[1U].SimMax;
    c14_b_histTable = c14_b_table[1U].HistogramTable;

    /* Simulation Min-Max logging. */
    if (c14_in->b < c14_b_localMin) {
      c14_b_localMin = c14_in->b;
    }

    if (c14_in->b > c14_b_localMax) {
      c14_b_localMax = c14_in->b;
    }

    /* Histogram logging. */
    c14_b_inDouble = c14_in->b;
    c14_b_histTable->TotalNumberOfValues++;
    if (c14_b_inDouble == 0.0) {
      c14_b_histTable->NumberOfZeros++;
    } else {
      c14_b_histTable->SimSum += c14_b_inDouble;
      if ((!muDoubleScalarIsInf(c14_b_inDouble)) && (!muDoubleScalarIsNaN
           (c14_b_inDouble))) {
        c14_b_significand = frexp(c14_b_inDouble, &c14_b_exponent);
        if (c14_b_exponent > 128) {
          c14_b_exponent = 128;
        }

        if (c14_b_exponent < -127) {
          c14_b_exponent = -127;
        }

        if (c14_b_significand < 0.0) {
          c14_b_histTable->NumberOfNegativeValues++;
          c14_b_histTable->HistogramOfNegativeValues[127 + c14_b_exponent]++;
        } else {
          c14_b_histTable->NumberOfPositiveValues++;
          c14_b_histTable->HistogramOfPositiveValues[127 + c14_b_exponent]++;
        }
      }
    }

    c14_b_table[1U].SimMin = c14_b_localMin;
    c14_b_table[1U].SimMax = c14_b_localMax;

    /* IsAlwaysInteger logging. */
    if (c14_in->b != muDoubleScalarFloor(c14_in->b)) {
      c14_b_table[1U].IsAlwaysInteger = false;
    }

    c14_c_localMin = c14_b_table[2U].SimMin;
    c14_c_localMax = c14_b_table[2U].SimMax;
    c14_c_histTable = c14_b_table[2U].HistogramTable;

    /* Simulation Min-Max logging. */
    if (c14_in->c < c14_c_localMin) {
      c14_c_localMin = c14_in->c;
    }

    if (c14_in->c > c14_c_localMax) {
      c14_c_localMax = c14_in->c;
    }

    /* Histogram logging. */
    c14_c_inDouble = c14_in->c;
    c14_c_histTable->TotalNumberOfValues++;
    if (c14_c_inDouble == 0.0) {
      c14_c_histTable->NumberOfZeros++;
    } else {
      c14_c_histTable->SimSum += c14_c_inDouble;
      if ((!muDoubleScalarIsInf(c14_c_inDouble)) && (!muDoubleScalarIsNaN
           (c14_c_inDouble))) {
        c14_c_significand = frexp(c14_c_inDouble, &c14_c_exponent);
        if (c14_c_exponent > 128) {
          c14_c_exponent = 128;
        }

        if (c14_c_exponent < -127) {
          c14_c_exponent = -127;
        }

        if (c14_c_significand < 0.0) {
          c14_c_histTable->NumberOfNegativeValues++;
          c14_c_histTable->HistogramOfNegativeValues[127 + c14_c_exponent]++;
        } else {
          c14_c_histTable->NumberOfPositiveValues++;
          c14_c_histTable->HistogramOfPositiveValues[127 + c14_c_exponent]++;
        }
      }
    }

    c14_b_table[2U].SimMin = c14_c_localMin;
    c14_b_table[2U].SimMax = c14_c_localMax;

    /* IsAlwaysInteger logging. */
    if (c14_in->c != muDoubleScalarFloor(c14_in->c)) {
      c14_b_table[2U].IsAlwaysInteger = false;
    }

    c14_d_localMin = c14_b_table[3U].SimMin;
    c14_d_localMax = c14_b_table[3U].SimMax;
    c14_d_histTable = c14_b_table[3U].HistogramTable;

    /* Simulation Min-Max logging. */
    if (c14_in->d < c14_d_localMin) {
      c14_d_localMin = c14_in->d;
    }

    if (c14_in->d > c14_d_localMax) {
      c14_d_localMax = c14_in->d;
    }

    /* Histogram logging. */
    c14_d_inDouble = c14_in->d;
    c14_d_histTable->TotalNumberOfValues++;
    if (c14_d_inDouble == 0.0) {
      c14_d_histTable->NumberOfZeros++;
    } else {
      c14_d_histTable->SimSum += c14_d_inDouble;
      if ((!muDoubleScalarIsInf(c14_d_inDouble)) && (!muDoubleScalarIsNaN
           (c14_d_inDouble))) {
        c14_d_significand = frexp(c14_d_inDouble, &c14_d_exponent);
        if (c14_d_exponent > 128) {
          c14_d_exponent = 128;
        }

        if (c14_d_exponent < -127) {
          c14_d_exponent = -127;
        }

        if (c14_d_significand < 0.0) {
          c14_d_histTable->NumberOfNegativeValues++;
          c14_d_histTable->HistogramOfNegativeValues[127 + c14_d_exponent]++;
        } else {
          c14_d_histTable->NumberOfPositiveValues++;
          c14_d_histTable->HistogramOfPositiveValues[127 + c14_d_exponent]++;
        }
      }
    }

    c14_b_table[3U].SimMin = c14_d_localMin;
    c14_b_table[3U].SimMax = c14_d_localMax;

    /* IsAlwaysInteger logging. */
    if (c14_in->d != muDoubleScalarFloor(c14_in->d)) {
      c14_b_table[3U].IsAlwaysInteger = false;
    }
  }
}

static void c14_b_emlrt_update_log_5(SFc14_SFSInstanceStruct *chartInstance,
  c14_rtString *c14_in, emlrtLocationLoggingDataType c14_table[], int32_T
  c14_index)
{
  emlrtLocationLoggingDataType *c14_b_table;
  emlrtLocationLoggingHistogramType *c14_histTable;
  real_T c14_d;
  real_T c14_d1;
  real_T c14_inDouble;
  real_T c14_significand;
  int32_T c14_exponent;
  int32_T c14_i;
  int32_T c14_i1;
  int32_T c14_localMax;
  int32_T c14_localMin;
  boolean_T c14_isLoggingEnabledHere;
  (void)chartInstance;
  c14_isLoggingEnabledHere = (c14_index >= 0);
  if (c14_isLoggingEnabledHere) {
    c14_b_table = (emlrtLocationLoggingDataType *)&c14_table[c14_index];
    c14_d = muDoubleScalarFloor(c14_b_table[0U].SimMin);
    if (c14_d < 2.147483648E+9) {
      if (c14_d >= -2.147483648E+9) {
        c14_i = (int32_T)c14_d;
      } else {
        c14_i = MIN_int32_T;
      }
    } else if (c14_d >= 2.147483648E+9) {
      c14_i = MAX_int32_T;
    } else {
      c14_i = 0;
    }

    c14_localMin = c14_i;
    c14_d1 = muDoubleScalarFloor(c14_b_table[0U].SimMax);
    if (c14_d1 < 2.147483648E+9) {
      if (c14_d1 >= -2.147483648E+9) {
        c14_i1 = (int32_T)c14_d1;
      } else {
        c14_i1 = MIN_int32_T;
      }
    } else if (c14_d1 >= 2.147483648E+9) {
      c14_i1 = MAX_int32_T;
    } else {
      c14_i1 = 0;
    }

    c14_localMax = c14_i1;
    c14_histTable = c14_b_table[0U].HistogramTable;

    /* Simulation Min-Max logging. */
    if (c14_in->__$isSimulinkString.__dummy < c14_localMin) {
      c14_localMin = c14_in->__$isSimulinkString.__dummy;
    }

    if (c14_in->__$isSimulinkString.__dummy > c14_localMax) {
      c14_localMax = c14_in->__$isSimulinkString.__dummy;
    }

    /* Histogram logging. */
    c14_inDouble = (real_T)c14_in->__$isSimulinkString.__dummy;
    c14_histTable->TotalNumberOfValues++;
    if (c14_inDouble == 0.0) {
      c14_histTable->NumberOfZeros++;
    } else {
      c14_histTable->SimSum += c14_inDouble;
      if ((!muDoubleScalarIsInf(c14_inDouble)) && (!muDoubleScalarIsNaN
           (c14_inDouble))) {
        c14_significand = frexp(c14_inDouble, &c14_exponent);
        if (c14_exponent > 128) {
          c14_exponent = 128;
        }

        if (c14_exponent < -127) {
          c14_exponent = -127;
        }

        if (c14_significand < 0.0) {
          c14_histTable->NumberOfNegativeValues++;
          c14_histTable->HistogramOfNegativeValues[127 + c14_exponent]++;
        } else {
          c14_histTable->NumberOfPositiveValues++;
          c14_histTable->HistogramOfPositiveValues[127 + c14_exponent]++;
        }
      }
    }

    c14_b_table[0U].SimMin = (real_T)c14_localMin;
    c14_b_table[0U].SimMax = (real_T)c14_localMax;

    /* IsAlwaysInteger logging. */
    /* Data type is always integer. */
  }
}

static void c14_b_emlrt_update_log_6(SFc14_SFSInstanceStruct *chartInstance,
  c14_rtString_1 *c14_in, emlrtLocationLoggingDataType c14_table[], int32_T
  c14_index)
{
  emlrtLocationLoggingDataType *c14_b_table;
  emlrtLocationLoggingHistogramType *c14_histTable;
  real_T c14_d;
  real_T c14_d1;
  real_T c14_inDouble;
  real_T c14_significand;
  int32_T c14_exponent;
  int32_T c14_i;
  int32_T c14_i1;
  int32_T c14_localMax;
  int32_T c14_localMin;
  boolean_T c14_isLoggingEnabledHere;
  (void)chartInstance;
  c14_isLoggingEnabledHere = (c14_index >= 0);
  if (c14_isLoggingEnabledHere) {
    c14_b_table = (emlrtLocationLoggingDataType *)&c14_table[c14_index];
    c14_d = muDoubleScalarFloor(c14_b_table[0U].SimMin);
    if (c14_d < 2.147483648E+9) {
      if (c14_d >= -2.147483648E+9) {
        c14_i = (int32_T)c14_d;
      } else {
        c14_i = MIN_int32_T;
      }
    } else if (c14_d >= 2.147483648E+9) {
      c14_i = MAX_int32_T;
    } else {
      c14_i = 0;
    }

    c14_localMin = c14_i;
    c14_d1 = muDoubleScalarFloor(c14_b_table[0U].SimMax);
    if (c14_d1 < 2.147483648E+9) {
      if (c14_d1 >= -2.147483648E+9) {
        c14_i1 = (int32_T)c14_d1;
      } else {
        c14_i1 = MIN_int32_T;
      }
    } else if (c14_d1 >= 2.147483648E+9) {
      c14_i1 = MAX_int32_T;
    } else {
      c14_i1 = 0;
    }

    c14_localMax = c14_i1;
    c14_histTable = c14_b_table[0U].HistogramTable;

    /* Simulation Min-Max logging. */
    if (c14_in->__$isSimulinkString.__dummy < c14_localMin) {
      c14_localMin = c14_in->__$isSimulinkString.__dummy;
    }

    if (c14_in->__$isSimulinkString.__dummy > c14_localMax) {
      c14_localMax = c14_in->__$isSimulinkString.__dummy;
    }

    /* Histogram logging. */
    c14_inDouble = (real_T)c14_in->__$isSimulinkString.__dummy;
    c14_histTable->TotalNumberOfValues++;
    if (c14_inDouble == 0.0) {
      c14_histTable->NumberOfZeros++;
    } else {
      c14_histTable->SimSum += c14_inDouble;
      if ((!muDoubleScalarIsInf(c14_inDouble)) && (!muDoubleScalarIsNaN
           (c14_inDouble))) {
        c14_significand = frexp(c14_inDouble, &c14_exponent);
        if (c14_exponent > 128) {
          c14_exponent = 128;
        }

        if (c14_exponent < -127) {
          c14_exponent = -127;
        }

        if (c14_significand < 0.0) {
          c14_histTable->NumberOfNegativeValues++;
          c14_histTable->HistogramOfNegativeValues[127 + c14_exponent]++;
        } else {
          c14_histTable->NumberOfPositiveValues++;
          c14_histTable->HistogramOfPositiveValues[127 + c14_exponent]++;
        }
      }
    }

    c14_b_table[0U].SimMin = (real_T)c14_localMin;
    c14_b_table[0U].SimMax = (real_T)c14_localMax;

    /* IsAlwaysInteger logging. */
    /* Data type is always integer. */
  }
}

static void c14_b_emlrt_update_log_7(SFc14_SFSInstanceStruct *chartInstance,
  c14_rtString_2 *c14_in, emlrtLocationLoggingDataType c14_table[], int32_T
  c14_index)
{
  emlrtLocationLoggingDataType *c14_b_table;
  emlrtLocationLoggingHistogramType *c14_histTable;
  real_T c14_d;
  real_T c14_d1;
  real_T c14_inDouble;
  real_T c14_significand;
  int32_T c14_exponent;
  int32_T c14_i;
  int32_T c14_i1;
  int32_T c14_localMax;
  int32_T c14_localMin;
  boolean_T c14_isLoggingEnabledHere;
  (void)chartInstance;
  c14_isLoggingEnabledHere = (c14_index >= 0);
  if (c14_isLoggingEnabledHere) {
    c14_b_table = (emlrtLocationLoggingDataType *)&c14_table[c14_index];
    c14_d = muDoubleScalarFloor(c14_b_table[0U].SimMin);
    if (c14_d < 2.147483648E+9) {
      if (c14_d >= -2.147483648E+9) {
        c14_i = (int32_T)c14_d;
      } else {
        c14_i = MIN_int32_T;
      }
    } else if (c14_d >= 2.147483648E+9) {
      c14_i = MAX_int32_T;
    } else {
      c14_i = 0;
    }

    c14_localMin = c14_i;
    c14_d1 = muDoubleScalarFloor(c14_b_table[0U].SimMax);
    if (c14_d1 < 2.147483648E+9) {
      if (c14_d1 >= -2.147483648E+9) {
        c14_i1 = (int32_T)c14_d1;
      } else {
        c14_i1 = MIN_int32_T;
      }
    } else if (c14_d1 >= 2.147483648E+9) {
      c14_i1 = MAX_int32_T;
    } else {
      c14_i1 = 0;
    }

    c14_localMax = c14_i1;
    c14_histTable = c14_b_table[0U].HistogramTable;

    /* Simulation Min-Max logging. */
    if (c14_in->__$isSimulinkString.__dummy < c14_localMin) {
      c14_localMin = c14_in->__$isSimulinkString.__dummy;
    }

    if (c14_in->__$isSimulinkString.__dummy > c14_localMax) {
      c14_localMax = c14_in->__$isSimulinkString.__dummy;
    }

    /* Histogram logging. */
    c14_inDouble = (real_T)c14_in->__$isSimulinkString.__dummy;
    c14_histTable->TotalNumberOfValues++;
    if (c14_inDouble == 0.0) {
      c14_histTable->NumberOfZeros++;
    } else {
      c14_histTable->SimSum += c14_inDouble;
      if ((!muDoubleScalarIsInf(c14_inDouble)) && (!muDoubleScalarIsNaN
           (c14_inDouble))) {
        c14_significand = frexp(c14_inDouble, &c14_exponent);
        if (c14_exponent > 128) {
          c14_exponent = 128;
        }

        if (c14_exponent < -127) {
          c14_exponent = -127;
        }

        if (c14_significand < 0.0) {
          c14_histTable->NumberOfNegativeValues++;
          c14_histTable->HistogramOfNegativeValues[127 + c14_exponent]++;
        } else {
          c14_histTable->NumberOfPositiveValues++;
          c14_histTable->HistogramOfPositiveValues[127 + c14_exponent]++;
        }
      }
    }

    c14_b_table[0U].SimMin = (real_T)c14_localMin;
    c14_b_table[0U].SimMax = (real_T)c14_localMax;

    /* IsAlwaysInteger logging. */
    /* Data type is always integer. */
  }
}

static void c14_b_emlrt_update_log_8(SFc14_SFSInstanceStruct *chartInstance,
  real_T c14_in[3], emlrtLocationLoggingDataType c14_table[], int32_T c14_index)
{
  emlrtLocationLoggingDataType *c14_b_table;
  emlrtLocationLoggingHistogramType *c14_histTable;
  real_T c14_inDouble;
  real_T c14_localMax;
  real_T c14_localMin;
  real_T c14_significand;
  int32_T c14_b_i;
  int32_T c14_exponent;
  int32_T c14_i;
  boolean_T c14_isLoggingEnabledHere;
  (void)chartInstance;
  c14_isLoggingEnabledHere = (c14_index >= 0);
  if (c14_isLoggingEnabledHere) {
    c14_b_table = (emlrtLocationLoggingDataType *)&c14_table[c14_index];
    c14_localMin = c14_b_table[0U].SimMin;
    c14_localMax = c14_b_table[0U].SimMax;
    c14_histTable = c14_b_table[0U].HistogramTable;
    for (c14_i = 0; c14_i < 3; c14_i++) {
      /* Simulation Min-Max logging. */
      if (c14_in[c14_i] < c14_localMin) {
        c14_localMin = c14_in[c14_i];
      }

      if (c14_in[c14_i] > c14_localMax) {
        c14_localMax = c14_in[c14_i];
      }

      /* Histogram logging. */
      c14_inDouble = c14_in[c14_i];
      c14_histTable->TotalNumberOfValues++;
      if (c14_inDouble == 0.0) {
        c14_histTable->NumberOfZeros++;
      } else {
        c14_histTable->SimSum += c14_inDouble;
        if ((!muDoubleScalarIsInf(c14_inDouble)) && (!muDoubleScalarIsNaN
             (c14_inDouble))) {
          c14_significand = frexp(c14_inDouble, &c14_exponent);
          if (c14_exponent > 128) {
            c14_exponent = 128;
          }

          if (c14_exponent < -127) {
            c14_exponent = -127;
          }

          if (c14_significand < 0.0) {
            c14_histTable->NumberOfNegativeValues++;
            c14_histTable->HistogramOfNegativeValues[127 + c14_exponent]++;
          } else {
            c14_histTable->NumberOfPositiveValues++;
            c14_histTable->HistogramOfPositiveValues[127 + c14_exponent]++;
          }
        }
      }
    }

    c14_b_table[0U].SimMin = c14_localMin;
    c14_b_table[0U].SimMax = c14_localMax;

    /* IsAlwaysInteger logging. */
    c14_b_i = 0;
    while (c14_b_table[0U].IsAlwaysInteger && (c14_b_i < 3)) {
      if (c14_in[c14_b_i] != muDoubleScalarFloor(c14_in[c14_b_i])) {
        c14_b_table[0U].IsAlwaysInteger = false;
      }

      c14_b_i++;
    }
  }
}

static void c14_b_emlrt_update_log_9(SFc14_SFSInstanceStruct *chartInstance,
  real_T c14_in[3], emlrtLocationLoggingDataType c14_table[], int32_T c14_index)
{
  emlrtLocationLoggingDataType *c14_b_table;
  emlrtLocationLoggingHistogramType *c14_histTable;
  real_T c14_inDouble;
  real_T c14_localMax;
  real_T c14_localMin;
  real_T c14_significand;
  int32_T c14_b_i;
  int32_T c14_exponent;
  int32_T c14_i;
  boolean_T c14_isLoggingEnabledHere;
  (void)chartInstance;
  c14_isLoggingEnabledHere = (c14_index >= 0);
  if (c14_isLoggingEnabledHere) {
    c14_b_table = (emlrtLocationLoggingDataType *)&c14_table[c14_index];
    c14_localMin = c14_b_table[0U].SimMin;
    c14_localMax = c14_b_table[0U].SimMax;
    c14_histTable = c14_b_table[0U].HistogramTable;
    for (c14_i = 0; c14_i < 3; c14_i++) {
      /* Simulation Min-Max logging. */
      if (c14_in[c14_i] < c14_localMin) {
        c14_localMin = c14_in[c14_i];
      }

      if (c14_in[c14_i] > c14_localMax) {
        c14_localMax = c14_in[c14_i];
      }

      /* Histogram logging. */
      c14_inDouble = c14_in[c14_i];
      c14_histTable->TotalNumberOfValues++;
      if (c14_inDouble == 0.0) {
        c14_histTable->NumberOfZeros++;
      } else {
        c14_histTable->SimSum += c14_inDouble;
        if ((!muDoubleScalarIsInf(c14_inDouble)) && (!muDoubleScalarIsNaN
             (c14_inDouble))) {
          c14_significand = frexp(c14_inDouble, &c14_exponent);
          if (c14_exponent > 128) {
            c14_exponent = 128;
          }

          if (c14_exponent < -127) {
            c14_exponent = -127;
          }

          if (c14_significand < 0.0) {
            c14_histTable->NumberOfNegativeValues++;
            c14_histTable->HistogramOfNegativeValues[127 + c14_exponent]++;
          } else {
            c14_histTable->NumberOfPositiveValues++;
            c14_histTable->HistogramOfPositiveValues[127 + c14_exponent]++;
          }
        }
      }
    }

    c14_b_table[0U].SimMin = c14_localMin;
    c14_b_table[0U].SimMax = c14_localMax;

    /* IsAlwaysInteger logging. */
    c14_b_i = 0;
    while (c14_b_table[0U].IsAlwaysInteger && (c14_b_i < 3)) {
      if (c14_in[c14_b_i] != muDoubleScalarFloor(c14_in[c14_b_i])) {
        c14_b_table[0U].IsAlwaysInteger = false;
      }

      c14_b_i++;
    }
  }
}

static void c14_b_quaternionBase_normalize(SFc14_SFSInstanceStruct
  *chartInstance, const emlrtStack *c14_sp, c14_quaternion *c14_q)
{
  static char_T c14_cv[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  static char_T c14_cv1[4] = { 's', 'q', 'r', 't' };

  emlrtStack c14_st;
  const mxArray *c14_b_y = NULL;
  const mxArray *c14_c_y = NULL;
  const mxArray *c14_y = NULL;
  real_T c14_b_x;
  real_T c14_n;
  real_T c14_x;
  boolean_T c14_b_p;
  boolean_T c14_p;
  (void)chartInstance;
  c14_st.prev = c14_sp;
  c14_st.tls = c14_sp->tls;
  c14_st.site = &c14_d_emlrtRSI;
  c14_x = ((c14_q->a * c14_q->a + c14_q->b * c14_q->b) + c14_q->c * c14_q->c) +
    c14_q->d * c14_q->d;
  c14_n = c14_x;
  c14_b_x = c14_n;
  if (c14_b_x < 0.0) {
    c14_p = true;
  } else {
    c14_p = false;
  }

  c14_b_p = c14_p;
  if (c14_b_p) {
    c14_y = NULL;
    sf_mex_assign(&c14_y, sf_mex_create("y", c14_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c14_b_y = NULL;
    sf_mex_assign(&c14_b_y, sf_mex_create("y", c14_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c14_c_y = NULL;
    sf_mex_assign(&c14_c_y, sf_mex_create("y", c14_cv1, 10, 0U, 1U, 0U, 2, 1, 4),
                  false);
    sf_mex_call(&c14_st, &c14_emlrtMCI, "error", 0U, 2U, 14, c14_y, 14,
                sf_mex_call(&c14_st, NULL, "getString", 1U, 1U, 14, sf_mex_call(
      &c14_st, NULL, "message", 1U, 2U, 14, c14_b_y, 14, c14_c_y)));
  }

  c14_n = muDoubleScalarSqrt(c14_n);
  c14_q->a /= c14_n;
  c14_q->b /= c14_n;
  c14_q->c /= c14_n;
  c14_q->d /= c14_n;
}

static void init_dsm_address_info(SFc14_SFSInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc14_SFSInstanceStruct *chartInstance)
{
  chartInstance->c14_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c14_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c14_accel_VNED = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c14_gyro_VNED = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c14_accel_SNED = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c14_gyro_SNED = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c14_mag_SNED = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c14_mag_VNED = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c14_SFS_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1600350983U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1856948991U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3417696938U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3718953249U);
}

mxArray *sf_c14_SFS_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c14_SFS_jit_fallback_info(void)
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

mxArray *sf_c14_SFS_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c14_SFS(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiCewczAwAakOYCYiQECWKF8RiBmgdIQcRa4uAIQl1QWpILEi4uSPVOAdF5iLpi"
    "fWFrhmZeWDzbfggFhPhsW8xmRzOeEikPAB3vK9Is4gPQ7IOlnwaKfC0m/AJSfmJycmhMf5ufqAh"
    "HnY0DQA+cfBaL8w4nmHxA/vbIoH8k7g8Q/Sg7o+rH5hwPNPyB+bmI62DvU8YeCA2X6IfZ7EPCHI"
    "Jo/QPzM4vjE5JLMstT4ZEOT+GC3YLT4AQA8fSTq"
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c14_SFS_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "smkA14q2tPjal9hfdQFox6E";
}

static void sf_opaque_initialize_c14_SFS(void *chartInstanceVar)
{
  initialize_params_c14_SFS((SFc14_SFSInstanceStruct*) chartInstanceVar);
  initialize_c14_SFS((SFc14_SFSInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c14_SFS(void *chartInstanceVar)
{
  enable_c14_SFS((SFc14_SFSInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c14_SFS(void *chartInstanceVar)
{
  disable_c14_SFS((SFc14_SFSInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c14_SFS(void *chartInstanceVar)
{
  sf_gateway_c14_SFS((SFc14_SFSInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c14_SFS(SimStruct* S)
{
  return get_sim_state_c14_SFS((SFc14_SFSInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c14_SFS(SimStruct* S, const mxArray *st)
{
  set_sim_state_c14_SFS((SFc14_SFSInstanceStruct*)sf_get_chart_instance_ptr(S),
                        st);
}

static void sf_opaque_cleanup_runtime_resources_c14_SFS(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc14_SFSInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_SFS_optimization_info();
    }

    mdl_cleanup_runtime_resources_c14_SFS((SFc14_SFSInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c14_SFS(void *chartInstanceVar)
{
  mdl_start_c14_SFS((SFc14_SFSInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_mdl_terminate_c14_SFS(void *chartInstanceVar)
{
  mdl_terminate_c14_SFS((SFc14_SFSInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc14_SFS((SFc14_SFSInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c14_SFS(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  sf_warn_if_symbolic_dimension_param_changed(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c14_SFS((SFc14_SFSInstanceStruct*)
      sf_get_chart_instance_ptr(S));
    initSimStructsc14_SFS((SFc14_SFSInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c14_SFS_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [22] = {
    "eNrtWctuI0UULSchJBBGMxKIxSARsUBskCZhQIOEIIkfjKVkEmgnSGyiSve1u8bVVZ162DHiH2D",
    "JN7BF4lv4C1iwYMmtdttj2sbuciCTQbTktKrdp26dU/dVDqk0jwhed/CzfZ+Qdbxv4GeFDK+X8n",
    "Fl4jN8vkY+ycffvkpIKCPogAhsu82uiN8lbHJCFU008b8ETeBL0JJbw6RoirYsj2WiDQpEiBOkU",
    "hkvu5olljPRbVgROsv6q5iFcRBLy6MDnJBGx4IP/s5uas0JWqwxBaFpAEQmVtJ24gannfkqKNOv",
    "xhB2tU28tdJgAps6qvrIcsNSDvUrCJtCG4oq6AV8A0MNVM2Vn8iOrw5GaJmknFFRXuuY6gBS9A4",
    "Dp2mEf4+tQfVKYcOYKnMAMe2BPmTdzLoUUMo60/j2BRPUSMUorye86mYryfeEI8cjDAnuu0fI90",
    "AB7aaSCeMZEEEDda4LesGhBhe242k3gEvrouGMQR+U3/62q7IHinbgWPitOduj+lXmlONYKok1L",
    "IEzqvZD9F0NkV/ewKDTAUV3hBZO44WFTOKmbinWQ9/wzXVNF/5L5TqbDL1fL4XN7NZ74O1XY7uN",
    "UFQp59oP25LpIfSAZ/Zr1NAlsEP7HmCtWdSS6B0u23hmLCsYRkKOrUoRsfJe2SugssL2BItUCTh",
    "LXBhAhDKPlz6eaFEcWW1kUsWUUzs8LGlvGtsUBlSbhlC6xijKNOCCM7/ytBsx7QIJ0aiSyViWnm",
    "EYg0tBiW5bUetL1UWNfYvZM61cJPihIepgYjaQJbk6evcZ5bbkmhPdwfhB9zjVmGX97CLWxc9S4",
    "JCGMUSucjIOR5hncYKyW6xdyd9Htj1mBjXQoWJp2UiymNCx6DqVWoMUTkVXyL5oKJkEeec1x68A",
    "MGtQJZjoHGAJV4MGLr7cqhVctrLs7tvkOJ2p4fTC+cbnILAaOq6ua6AhRlVdYIuMC7oONmDfYBM",
    "jNNMGC/VgWOqHdc/174/Is/59bUb//vJE/343H4c7D8+xb8jwDybwWyX6/0pudx6OTOHIeL2j+3",
    "sT+MoMu2TiXrS3ufLX91cL9lbwSaVSyXB7E7jXCnbWCrj1XKPvf2+/+3P66xtbP93/8fF3Fb3If",
    "mXKfmWs0+M1v/PVnXz81qhPGmfl3lTiyuZfsP9vFvbfjXXS3d95eLlrTp5S/nHcjr5oyKuP6tl8",
    "P6zOX+9aYb2j59uuN8OgzXKACptRfk5zY2qH54eiv64v0GNzwp8I+e2z6+Ff3yv6wyy9Xino5cY",
    "Um01+fvakXpv24+fHZ7sUn80CHzfuDJScoHNL+LyzVyafbRT4bGR5tJPR+Wd4bO9dD18uLu8VeN",
    "zLzlTn1FVOOB9l6On9WTYP+eLIDeNelHX+r8u/z69MH7J6wzhyw7jr8vPtr1709x/Mybek8P7dW",
    "8xjXr736bNvG69fiF8f/HY+/nT8u041ZjyacbLMv8bDX3vWt/8R//7DU79R3193+uX/APj6g31B",
    "+QCPksOjev74RLnfccdfKaB69nn9edST0X1Rn7tViG837jMRyb5+f2f3w93r1Kc/Af1KHqQ=",
    ""
  };

  static char newstr [1573] = "";
  newstr[0] = '\0';
  for (i = 0; i < 22; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c14_SFS(SimStruct *S)
{
  const char* newstr = sf_c14_SFS_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(644281488U));
  ssSetChecksum1(S,(368013494U));
  ssSetChecksum2(S,(2853942028U));
  ssSetChecksum3(S,(1929482056U));
}

static void mdlRTW_c14_SFS(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c14_SFS(SimStruct *S)
{
  SFc14_SFSInstanceStruct *chartInstance;
  chartInstance = (SFc14_SFSInstanceStruct *)utMalloc(sizeof
    (SFc14_SFSInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc14_SFSInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c14_SFS;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c14_SFS;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c14_SFS;
  chartInstance->chartInfo.mdlTerminate = sf_opaque_mdl_terminate_c14_SFS;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c14_SFS;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c14_SFS;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c14_SFS;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c14_SFS;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c14_SFS;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c14_SFS;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c14_SFS;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c14_SFS;
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
    chartInstance->c14_JITStateAnimation,
    chartInstance->c14_JITTransitionAnimation);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c14_SFS(chartInstance);
}

void c14_SFS_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c14_SFS(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c14_SFS(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c14_SFS(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c14_SFS_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
