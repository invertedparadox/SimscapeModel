/* Include files */

#include "car_model_FIXED_sfun.h"
#include "c11_car_model_FIXED.h"
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
static emlrtMCInfo c11_emlrtMCI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validatefinite",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatefinite.m"/* pName */
};

static emlrtMCInfo c11_b_emlrtMCI = { 28,/* lineNo */
  27,                                  /* colNo */
  "validatege",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatege.m"/* pName */
};

static emlrtMCInfo c11_c_emlrtMCI = { 28,/* lineNo */
  27,                                  /* colNo */
  "validatele",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatele.m"/* pName */
};

static emlrtMCInfo c11_d_emlrtMCI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validatenonnan",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatenonnan.m"/* pName */
};

static emlrtMCInfo c11_e_emlrtMCI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validatepositive",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatepositive.m"/* pName */
};

static emlrtMCInfo c11_f_emlrtMCI = { 13,/* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pName */
};

static emlrtMCInfo c11_g_emlrtMCI = { 82,/* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pName */
};

static emlrtMCInfo c11_h_emlrtMCI = { 13,/* lineNo */
  13,                                  /* colNo */
  "toLogicalCheck",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\toLogicalCheck.m"/* pName */
};

static emlrtMCInfo c11_i_emlrtMCI = { 87,/* lineNo */
  33,                                  /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtRSInfo c11_emlrtRSI = { 3, /* lineNo */
  "Control Systems/Sensor Fusion/fusion",/* fcnName */
  "#car_model_FIXED:6049"              /* pathName */
};

static emlrtRSInfo c11_b_emlrtRSI = { 4,/* lineNo */
  "Control Systems/Sensor Fusion/fusion",/* fcnName */
  "#car_model_FIXED:6049"              /* pathName */
};

static emlrtRSInfo c11_c_emlrtRSI = { 5,/* lineNo */
  "Control Systems/Sensor Fusion/fusion",/* fcnName */
  "#car_model_FIXED:6049"              /* pathName */
};

static emlrtRSInfo c11_d_emlrtRSI = { 6,/* lineNo */
  "Control Systems/Sensor Fusion/fusion",/* fcnName */
  "#car_model_FIXED:6049"              /* pathName */
};

static emlrtRSInfo c11_e_emlrtRSI = { 8,/* lineNo */
  "Control Systems/Sensor Fusion/fusion",/* fcnName */
  "#car_model_FIXED:6049"              /* pathName */
};

static emlrtRSInfo c11_f_emlrtRSI = { 9,/* lineNo */
  "Control Systems/Sensor Fusion/fusion",/* fcnName */
  "#car_model_FIXED:6049"              /* pathName */
};

static emlrtRSInfo c11_g_emlrtRSI = { 10,/* lineNo */
  "Control Systems/Sensor Fusion/fusion",/* fcnName */
  "#car_model_FIXED:6049"              /* pathName */
};

static emlrtRSInfo c11_h_emlrtRSI = { 11,/* lineNo */
  "Control Systems/Sensor Fusion/fusion",/* fcnName */
  "#car_model_FIXED:6049"              /* pathName */
};

static emlrtRSInfo c11_i_emlrtRSI = { 12,/* lineNo */
  "Control Systems/Sensor Fusion/fusion",/* fcnName */
  "#car_model_FIXED:6049"              /* pathName */
};

static emlrtRSInfo c11_j_emlrtRSI = { 13,/* lineNo */
  "Control Systems/Sensor Fusion/fusion",/* fcnName */
  "#car_model_FIXED:6049"              /* pathName */
};

static emlrtRSInfo c11_k_emlrtRSI = { 14,/* lineNo */
  "Control Systems/Sensor Fusion/fusion",/* fcnName */
  "#car_model_FIXED:6049"              /* pathName */
};

static emlrtRSInfo c11_l_emlrtRSI = { 15,/* lineNo */
  "Control Systems/Sensor Fusion/fusion",/* fcnName */
  "#car_model_FIXED:6049"              /* pathName */
};

static emlrtRSInfo c11_m_emlrtRSI = { 16,/* lineNo */
  "Control Systems/Sensor Fusion/fusion",/* fcnName */
  "#car_model_FIXED:6049"              /* pathName */
};

static emlrtRSInfo c11_n_emlrtRSI = { 19,/* lineNo */
  "Control Systems/Sensor Fusion/fusion",/* fcnName */
  "#car_model_FIXED:6049"              /* pathName */
};

static emlrtRSInfo c11_o_emlrtRSI = { 21,/* lineNo */
  "Control Systems/Sensor Fusion/fusion",/* fcnName */
  "#car_model_FIXED:6049"              /* pathName */
};

static emlrtRSInfo c11_p_emlrtRSI = { 22,/* lineNo */
  "Control Systems/Sensor Fusion/fusion",/* fcnName */
  "#car_model_FIXED:6049"              /* pathName */
};

static emlrtRSInfo c11_q_emlrtRSI = { 23,/* lineNo */
  "Control Systems/Sensor Fusion/fusion",/* fcnName */
  "#car_model_FIXED:6049"              /* pathName */
};

static emlrtRSInfo c11_r_emlrtRSI = { 25,/* lineNo */
  "Control Systems/Sensor Fusion/fusion",/* fcnName */
  "#car_model_FIXED:6049"              /* pathName */
};

static emlrtRSInfo c11_s_emlrtRSI = { 26,/* lineNo */
  "Control Systems/Sensor Fusion/fusion",/* fcnName */
  "#car_model_FIXED:6049"              /* pathName */
};

static emlrtRSInfo c11_t_emlrtRSI = { 31,/* lineNo */
  "Control Systems/Sensor Fusion/fusion",/* fcnName */
  "#car_model_FIXED:6049"              /* pathName */
};

static emlrtRSInfo c11_u_emlrtRSI = { 34,/* lineNo */
  "Control Systems/Sensor Fusion/fusion",/* fcnName */
  "#car_model_FIXED:6049"              /* pathName */
};

static emlrtRSInfo c11_v_emlrtRSI = { 35,/* lineNo */
  "Control Systems/Sensor Fusion/fusion",/* fcnName */
  "#car_model_FIXED:6049"              /* pathName */
};

static emlrtRSInfo c11_w_emlrtRSI = { 10,/* lineNo */
  "insfilterAsyncCG",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\+coder\\insfilterAsyncCG.m"/* pathName */
};

static emlrtRSInfo c11_x_emlrtRSI = { 118,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_y_emlrtRSI = { 119,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_ab_emlrtRSI = { 28,/* lineNo */
  "INSFilterEKF",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\INSFilterEKF.m"/* pathName */
};

static emlrtRSInfo c11_bb_emlrtRSI = { 30,/* lineNo */
  "BasicEKF",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\BasicEKF.m"/* pathName */
};

static emlrtRSInfo c11_cb_emlrtRSI = { 1,/* lineNo */
  "PositioningHandleBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\PositioningHandleBase.p"/* pathName */
};

static emlrtRSInfo c11_db_emlrtRSI = { 32,/* lineNo */
  "INSFilterEKF",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\INSFilterEKF.m"/* pathName */
};

static emlrtRSInfo c11_eb_emlrtRSI = { 36,/* lineNo */
  "INSFilterEKF",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\INSFilterEKF.m"/* pathName */
};

static emlrtRSInfo c11_fb_emlrtRSI = { 40,/* lineNo */
  "INSFilterEKF",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\INSFilterEKF.m"/* pathName */
};

static emlrtRSInfo c11_gb_emlrtRSI = { 93,/* lineNo */
  "validateattributes",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\lang\\validateattributes.m"/* pathName */
};

static emlrtRSInfo c11_hb_emlrtRSI = { 666,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_ib_emlrtRSI = { 689,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_jb_emlrtRSI = { 670,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_kb_emlrtRSI = { 707,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_lb_emlrtRSI = { 536,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_mb_emlrtRSI = { 550,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_nb_emlrtRSI = { 564,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_ob_emlrtRSI = { 578,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_pb_emlrtRSI = { 592,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_qb_emlrtRSI = { 606,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_rb_emlrtRSI = { 620,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_sb_emlrtRSI = { 634,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_tb_emlrtRSI = { 648,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_ub_emlrtRSI = { 147,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_vb_emlrtRSI = { 148,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_wb_emlrtRSI = { 152,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_xb_emlrtRSI = { 154,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_yb_emlrtRSI = { 158,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_ac_emlrtRSI = { 162,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_bc_emlrtRSI = { 164,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_cc_emlrtRSI = { 165,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_dc_emlrtRSI = { 15,/* lineNo */
  "ContinuousEKFPredictor",            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\utilities\\utilities\\+positioning\\+internal\\ContinuousEKFPredictor.m"/* pathName */
};

static emlrtRSInfo c11_ec_emlrtRSI = { 94,/* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pathName */
};

static emlrtRSInfo c11_fc_emlrtRSI = { 142,/* lineNo */
  "mtimes",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\mtimes.m"/* pathName */
};

static emlrtRSInfo c11_gc_emlrtRSI = { 178,/* lineNo */
  "mtimes",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\mtimes.m"/* pathName */
};

static emlrtRSInfo c11_hc_emlrtRSI = { 156,/* lineNo */
  "BasicEKF",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\BasicEKF.m"/* pathName */
};

static emlrtRSInfo c11_ic_emlrtRSI = { 363,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_jc_emlrtRSI = { 784,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_kc_emlrtRSI = { 785,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_lc_emlrtRSI = { 786,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_mc_emlrtRSI = { 787,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_nc_emlrtRSI = { 788,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_oc_emlrtRSI = { 790,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_pc_emlrtRSI = { 791,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_qc_emlrtRSI = { 1056,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_rc_emlrtRSI = { 1057,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_sc_emlrtRSI = { 1058,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_tc_emlrtRSI = { 44,/* lineNo */
  "mpower",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\matfun\\mpower.m"/* pathName */
};

static emlrtRSInfo c11_uc_emlrtRSI = { 71,/* lineNo */
  "power",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRSInfo c11_vc_emlrtRSI = { 1100,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_wc_emlrtRSI = { 1101,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_xc_emlrtRSI = { 1102,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_yc_emlrtRSI = { 138,/* lineNo */
  "BasicEKF",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\BasicEKF.m"/* pathName */
};

static emlrtRSInfo c11_ad_emlrtRSI = { 141,/* lineNo */
  "BasicEKF",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\BasicEKF.m"/* pathName */
};

static emlrtRSInfo c11_bd_emlrtRSI = { 17,/* lineNo */
  "EKF",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\utilities\\utilities\\+positioning\\+internal\\EKF.m"/* pathName */
};

static emlrtRSInfo c11_cd_emlrtRSI = { 19,/* lineNo */
  "EKF",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\utilities\\utilities\\+positioning\\+internal\\EKF.m"/* pathName */
};

static emlrtRSInfo c11_dd_emlrtRSI = { 21,/* lineNo */
  "EKF",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\utilities\\utilities\\+positioning\\+internal\\EKF.m"/* pathName */
};

static emlrtRSInfo c11_ed_emlrtRSI = { 12,/* lineNo */
  "EKF",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\utilities\\utilities\\+positioning\\+internal\\EKF.m"/* pathName */
};

static emlrtRSInfo c11_fd_emlrtRSI = { 20,/* lineNo */
  "mrdivide_helper",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\mrdivide_helper.m"/* pathName */
};

static emlrtRSInfo c11_gd_emlrtRSI = { 42,/* lineNo */
  "mrdivide_helper",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\mrdivide_helper.m"/* pathName */
};

static emlrtRSInfo c11_hd_emlrtRSI = { 61,/* lineNo */
  "lusolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo c11_id_emlrtRSI = { 293,/* lineNo */
  "lusolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo c11_jd_emlrtRSI = { 90,/* lineNo */
  "lusolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo c11_kd_emlrtRSI = { 14,/* lineNo */
  "warning",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\warning.m"/* pathName */
};

static emlrtRSInfo c11_ld_emlrtRSI = { 441,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_md_emlrtRSI = { 520,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_nd_emlrtRSI = { 938,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_od_emlrtRSI = { 939,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_pd_emlrtRSI = { 940,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_qd_emlrtRSI = { 957,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_rd_emlrtRSI = { 958,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_sd_emlrtRSI = { 959,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_td_emlrtRSI = { 269,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_ud_emlrtRSI = { 283,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_vd_emlrtRSI = { 285,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_wd_emlrtRSI = { 1238,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_xd_emlrtRSI = { 81,/* lineNo */
  "NED",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\sensorsim\\coordinates\\+fusion\\+internal\\+frames\\NED.m"/* pathName */
};

static emlrtRSInfo c11_yd_emlrtRSI = { 28,/* lineNo */
  "lla2ned",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\sensorsim\\coordinates\\+fusion\\+internal\\+frames\\lla2ned.m"/* pathName */
};

static emlrtRSInfo c11_ae_emlrtRSI = { 28,/* lineNo */
  "lla2enu",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\sensorsim\\coordinates\\+fusion\\+internal\\+frames\\lla2enu.m"/* pathName */
};

static emlrtRSInfo c11_be_emlrtRSI = { 29,/* lineNo */
  "lla2enu",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\sensorsim\\coordinates\\+fusion\\+internal\\+frames\\lla2enu.m"/* pathName */
};

static emlrtRSInfo c11_ce_emlrtRSI = { 30,/* lineNo */
  "lla2ecef",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\sensorsim\\coordinates\\+fusion\\+internal\\+frames\\lla2ecef.m"/* pathName */
};

static emlrtRSInfo c11_de_emlrtRSI = { 78,/* lineNo */
  "geodetic2cylindrical",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\mapgeodesy\\+map\\+geodesy\\+internal\\geodetic2cylindrical.m"/* pathName */
};

static emlrtRSInfo c11_ee_emlrtRSI = { 36,/* lineNo */
  "ecef2enu",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\sensorsim\\coordinates\\+fusion\\+internal\\+frames\\ecef2enu.m"/* pathName */
};

static emlrtRSInfo c11_fe_emlrtRSI = { 67,/* lineNo */
  "lusolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo c11_ge_emlrtRSI = { 112,/* lineNo */
  "lusolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo c11_he_emlrtRSI = { 107,/* lineNo */
  "lusolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo c11_ie_emlrtRSI = { 135,/* lineNo */
  "lusolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo c11_je_emlrtRSI = { 140,/* lineNo */
  "lusolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo c11_ke_emlrtRSI = { 142,/* lineNo */
  "lusolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo c11_le_emlrtRSI = { 30,/* lineNo */
  "xgetrf",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"/* pathName */
};

static emlrtRSInfo c11_me_emlrtRSI = { 36,/* lineNo */
  "xzgetrf",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgetrf.m"/* pathName */
};

static emlrtRSInfo c11_ne_emlrtRSI = { 50,/* lineNo */
  "xzgetrf",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgetrf.m"/* pathName */
};

static emlrtRSInfo c11_oe_emlrtRSI = { 58,/* lineNo */
  "xzgetrf",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgetrf.m"/* pathName */
};

static emlrtRSInfo c11_pe_emlrtRSI = { 23,/* lineNo */
  "ixamax",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\ixamax.m"/* pathName */
};

static emlrtRSInfo c11_qe_emlrtRSI = { 24,/* lineNo */
  "ixamax",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\ixamax.m"/* pathName */
};

static emlrtRSInfo c11_re_emlrtRSI = { 20,/* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo c11_se_emlrtRSI = { 45,/* lineNo */
  "xgeru",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgeru.m"/* pathName */
};

static emlrtRSInfo c11_te_emlrtRSI = { 45,/* lineNo */
  "xger",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xger.m"/* pathName */
};

static emlrtRSInfo c11_ue_emlrtRSI = { 15,/* lineNo */
  "xger",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xger.m"/* pathName */
};

static emlrtRSInfo c11_ve_emlrtRSI = { 41,/* lineNo */
  "xgerx",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgerx.m"/* pathName */
};

static emlrtRSInfo c11_we_emlrtRSI = { 54,/* lineNo */
  "xgerx",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgerx.m"/* pathName */
};

static emlrtRSInfo c11_xe_emlrtRSI = { 59,/* lineNo */
  "xtrsm",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xtrsm.m"/* pathName */
};

static emlrtRSInfo c11_ye_emlrtRSI = { 143,/* lineNo */
  "xtrsm",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xtrsm.m"/* pathName */
};

static emlrtRSInfo c11_af_emlrtRSI = { 167,/* lineNo */
  "xtrsm",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xtrsm.m"/* pathName */
};

static emlrtRSInfo c11_bf_emlrtRSI = { 136,/* lineNo */
  "mtimes",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\mtimes.m"/* pathName */
};

static emlrtRSInfo c11_cf_emlrtRSI = { 51,/* lineNo */
  "mtimes",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\mtimes.m"/* pathName */
};

static emlrtRSInfo c11_df_emlrtRSI = { 150,/* lineNo */
  "mtimes",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\mtimes.m"/* pathName */
};

static emlrtRSInfo c11_ef_emlrtRSI = { 95,/* lineNo */
  "INSFilterEKF",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\INSFilterEKF.m"/* pathName */
};

static emlrtRSInfo c11_ff_emlrtRSI = { 97,/* lineNo */
  "INSFilterEKF",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\INSFilterEKF.m"/* pathName */
};

static emlrtRSInfo c11_gf_emlrtRSI = { 102,/* lineNo */
  "INSFilterEKF",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\INSFilterEKF.m"/* pathName */
};

static emlrtRSInfo c11_hf_emlrtRSI = { 103,/* lineNo */
  "INSFilterEKF",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\INSFilterEKF.m"/* pathName */
};

static emlrtRSInfo c11_if_emlrtRSI = { 745,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_jf_emlrtRSI = { 19,/* lineNo */
  "rotmat",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\rotations\\rotationslib\\+matlabshared\\+rotations\\+internal\\@quaternionBase\\rotmat.m"/* pathName */
};

static emlrtRSInfo c11_kf_emlrtRSI = { 10,/* lineNo */
  "normalize",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\rotations\\rotationslib\\+matlabshared\\+rotations\\+internal\\@quaternionBase\\normaliz"
  "e.m"                                /* pathName */
};

static emlrtRSInfo c11_lf_emlrtRSI = { 750,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_mf_emlrtRSI = { 755,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_nf_emlrtRSI = { 662,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtRSInfo c11_of_emlrtRSI = { 673,/* lineNo */
  "AsyncMARGGPSFuserBase",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\AsyncMARGGPSFuserBase.m"/* pathName */
};

static emlrtBCInfo c11_emlrtBCI = { 1, /* iFirst */
  28,                                  /* iLast */
  155,                                 /* lineNo */
  24,                                  /* colNo */
  "",                                  /* aName */
  "BasicEKF",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\BasicEKF.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c11_emlrtDCI = { 155,/* lineNo */
  24,                                  /* colNo */
  "BasicEKF",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\BasicEKF.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c11_b_emlrtBCI = { 1,/* iFirst */
  28,                                  /* iLast */
  161,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "BasicEKF",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\BasicEKF.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c11_b_emlrtDCI = { 161,/* lineNo */
  17,                                  /* colNo */
  "BasicEKF",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\BasicEKF.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c11_c_emlrtBCI = { 1,/* iFirst */
  28,                                  /* iLast */
  159,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "BasicEKF",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\BasicEKF.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c11_c_emlrtDCI = { 159,/* lineNo */
  17,                                  /* colNo */
  "BasicEKF",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\positioning\\positioning\\+fusion\\+internal\\BasicEKF.m",/* pName */
  1                                    /* checkKind */
};

static char_T c11_cv[21] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'e', 'x', 'p',
  'e', 'c', 't', 'e', 'd', 'N', 'o', 'n', 'N', 'a', 'N' };

static char_T c11_cv1[46] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
  'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't', 'r',
  'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'N', 'o',
  'n', 'N', 'a', 'N' };

static char_T c11_cv2[23] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'e', 'x', 'p',
  'e', 'c', 't', 'e', 'd', 'P', 'o', 's', 'i', 't', 'i', 'v', 'e' };

static char_T c11_cv3[48] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
  'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't', 'r',
  'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'P', 'o',
  's', 'i', 't', 'i', 'v', 'e' };

static char_T c11_cv4[21] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'e', 'x', 'p',
  'e', 'c', 't', 'e', 'd', 'F', 'i', 'n', 'i', 't', 'e' };

static char_T c11_cv5[46] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
  'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't', 'r',
  'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'F', 'i',
  'n', 'i', 't', 'e' };

/* Function Declarations */
static void initialize_c11_car_model_FIXED(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance);
static void initialize_params_c11_car_model_FIXED
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance);
static void mdl_start_c11_car_model_FIXED(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance);
static void mdl_terminate_c11_car_model_FIXED
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c11_car_model_FIXED
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c11_car_model_FIXED
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance);
static void enable_c11_car_model_FIXED(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance);
static void disable_c11_car_model_FIXED(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance);
static void sf_gateway_c11_car_model_FIXED(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance);
static void ext_mode_exec_c11_car_model_FIXED
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance);
static void c11_update_jit_animation_c11_car_model_FIXED
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance);
static void c11_do_animation_call_c11_car_model_FIXED
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c11_car_model_FIXED
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance);
static void set_sim_state_c11_car_model_FIXED
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance, const mxArray *c11_st);
static void initSimStructsc11_car_model_FIXED
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance);
static real_T c11_emlrt_update_log_1(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c11_in, emlrtLocationLoggingDataType c11_table[],
  int32_T c11_index);
static void c11_emlrt_update_log_2(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c11_in[3], emlrtLocationLoggingDataType c11_table[],
  int32_T c11_index, real_T c11_out[3]);
static void c11_emlrt_update_log_3(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c11_in[28], emlrtLocationLoggingDataType c11_table[],
  int32_T c11_index, real_T c11_out[28]);
static void c11_emlrt_update_log_4(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c11_in[784], emlrtLocationLoggingDataType c11_table[],
  int32_T c11_index, real_T c11_out[784]);
static void c11_emlrt_update_log_5(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c11_in[9], emlrtLocationLoggingDataType c11_table[],
  int32_T c11_index, real_T c11_out[9]);
static void c11_emlrtInitVarDataTables(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, emlrtLocationLoggingDataType c11_dataTables[22],
  emlrtLocationLoggingHistogramType c11_histTables[22]);
static void c11_INSFilterEKF_set_ReferenceLocation
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance, const emlrtStack *c11_sp,
   c11_insfilterAsync *c11_obj, real_T c11_val[3]);
static void c11_AsyncMARGGPSFuserBase_setState
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance, const emlrtStack *c11_sp,
   c11_insfilterAsync *c11_obj, real_T c11_val[28]);
static void c11_AsyncMARGGPSFuserBase_setStateCovariance
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance, const emlrtStack *c11_sp,
   c11_insfilterAsync *c11_obj, real_T c11_val[784]);
static void c11_AsyncMARGGPSFuserBase_set_QuaternionNoise
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance, const emlrtStack *c11_sp,
   c11_insfilterAsync *c11_obj, real_T c11_val[4]);
static void c11_AsyncMARGGPSFuserBase_set_AngularVelocityNoise
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance, const emlrtStack *c11_sp,
   c11_insfilterAsync *c11_obj, real_T c11_val[3]);
static void c11_AsyncMARGGPSFuserBase_set_PositionNoise
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance, const emlrtStack *c11_sp,
   c11_insfilterAsync *c11_obj, real_T c11_val[3]);
static void c11_AsyncMARGGPSFuserBase_set_VelocityNoise
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance, const emlrtStack *c11_sp,
   c11_insfilterAsync *c11_obj, real_T c11_val[3]);
static void c11_AsyncMARGGPSFuserBase_set_GyroscopeBiasNoise
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance, const emlrtStack *c11_sp,
   c11_insfilterAsync *c11_obj, real_T c11_val[3]);
static void c11_AsyncMARGGPSFuserBase_set_AccelerometerBiasNoise
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance, const emlrtStack *c11_sp,
   c11_insfilterAsync *c11_obj, real_T c11_val[3]);
static void c11_AsyncMARGGPSFuserBase_set_GeomagneticVectorNoise
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance, const emlrtStack *c11_sp,
   c11_insfilterAsync *c11_obj, real_T c11_val[3]);
static void c11_AsyncMARGGPSFuserBase_set_MagnetometerBiasNoise
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance, const emlrtStack *c11_sp,
   c11_insfilterAsync *c11_obj, real_T c11_val[3]);
static void c11_AsyncMARGGPSFuserBase_predict
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance, const emlrtStack *c11_sp,
   c11_insfilterAsync *c11_obj, real_T c11_dt);
static void c11_mtimes(SFc11_car_model_FIXEDInstanceStruct *chartInstance,
  real_T c11_A[784], real_T c11_B[784], real_T c11_C[784]);
static real_T c11_sumColumnB(SFc11_car_model_FIXEDInstanceStruct *chartInstance,
  real_T c11_x[4], int32_T c11_col);
static real_T c11_sqrt(SFc11_car_model_FIXEDInstanceStruct *chartInstance, const
  emlrtStack *c11_sp, real_T c11_x);
static void c11_AsyncMARGGPSFuserBase_fuseaccel
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance, const emlrtStack *c11_sp,
   c11_insfilterAsync *c11_obj, real_T c11_accel[3], real_T c11_Raccel);
static void c11_AsyncMARGGPSFuserBase_accelMeasFcn
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance, real_T c11_x[28], real_T
   c11_z[3]);
static void c11_BasicEKF_correctEqn(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, const emlrtStack *c11_sp, c11_insfilterAsync *c11_obj, real_T
  c11_x[28], real_T c11_P[784], real_T c11_h[3], real_T c11_H[84], real_T c11_z
  [3], real_T c11_R[9], real_T c11_b_x[28], real_T c11_b_P[784], real_T
  c11_innov[3], real_T c11_innovCov[9]);
static void c11_warning(SFc11_car_model_FIXEDInstanceStruct *chartInstance,
  const emlrtStack *c11_sp);
static void c11_AsyncMARGGPSFuserBase_fusemag
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance, const emlrtStack *c11_sp,
   c11_insfilterAsync *c11_obj, real_T c11_mag[3], real_T c11_Rmag);
static void c11_AsyncMARGGPSFuserBase_magMeasFcn
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance, real_T c11_x[28], real_T
   c11_z[3]);
static void c11_AsyncMARGGPSFuserBase_fusegps
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance, const emlrtStack *c11_sp,
   c11_insfilterAsync *c11_obj, real_T c11_lla[3], real_T c11_Rpos, real_T
   c11_vel[3], real_T c11_Rvel);
static void c11_lla2ecef(SFc11_car_model_FIXEDInstanceStruct *chartInstance,
  const emlrtStack *c11_sp, real_T c11_llaPos[3], real_T c11_ecefPos[3]);
static real_T c11_sind(SFc11_car_model_FIXEDInstanceStruct *chartInstance,
  real_T c11_x);
static real_T c11_cosd(SFc11_car_model_FIXEDInstanceStruct *chartInstance,
  real_T c11_x);
static void c11_AsyncMARGGPSFuserBase_basicCorrect
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance, const emlrtStack *c11_sp,
   c11_insfilterAsync *c11_obj, real_T c11_z[6], real_T c11_measNoise[36],
   real_T c11_innov[6], real_T c11_innovCov[36]);
static void c11_mrdiv(SFc11_car_model_FIXEDInstanceStruct *chartInstance, const
                      emlrtStack *c11_sp, real_T c11_A[168], real_T c11_B[36],
                      real_T c11_Y[168]);
static void c11_check_forloop_overflow_error(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, const emlrtStack *c11_sp, boolean_T c11_overflow);
static void c11_INSFilterEKF_pose(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, const emlrtStack *c11_sp, c11_insfilterAsync *c11_obj, real_T
  c11_pos[3], real_T c11_orient[9], real_T c11_vel[3]);
static real_T c11_emlrt_marshallIn(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c11_c_count, const char_T *c11_identifier);
static real_T c11_b_emlrt_marshallIn(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_c_emlrt_marshallIn(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c11_b_cov_out, const char_T *c11_identifier,
  real_T c11_y[784]);
static void c11_d_emlrt_marshallIn(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[784]);
static void c11_e_emlrt_marshallIn(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c11_b_rot_map, const char_T *c11_identifier,
  real_T c11_y[9]);
static void c11_f_emlrt_marshallIn(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[9]);
static void c11_g_emlrt_marshallIn(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c11_b_state_out, const char_T *c11_identifier,
  real_T c11_y[28]);
static void c11_h_emlrt_marshallIn(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[28]);
static uint8_T c11_i_emlrt_marshallIn(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c11_b_is_active_c11_car_model_FIXED, const
  char_T *c11_identifier);
static uint8_T c11_j_emlrt_marshallIn(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_slStringInitializeDynamicBuffers
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance);
static void c11_chart_data_browse_helper(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, int32_T c11_ssIdNumber, const mxArray **c11_mxData, uint8_T
  *c11_isValueTooBig);
static const mxArray *c11_feval(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, const emlrtStack *c11_sp, const mxArray *c11_input0, const
  mxArray *c11_input1);
static void c11_b_feval(SFc11_car_model_FIXEDInstanceStruct *chartInstance,
  const emlrtStack *c11_sp, const mxArray *c11_input0, const mxArray *c11_input1);
static void c11_b_emlrt_update_log_2(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c11_in[3], emlrtLocationLoggingDataType c11_table[],
  int32_T c11_index);
static void c11_b_emlrt_update_log_3(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c11_in[28], emlrtLocationLoggingDataType c11_table[],
  int32_T c11_index);
static void c11_b_emlrt_update_log_4(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c11_in[784], emlrtLocationLoggingDataType c11_table[],
  int32_T c11_index);
static void c11_b_emlrt_update_log_5(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c11_in[9], emlrtLocationLoggingDataType c11_table[],
  int32_T c11_index);
static void c11_b_sqrt(SFc11_car_model_FIXEDInstanceStruct *chartInstance, const
  emlrtStack *c11_sp, real_T *c11_x);
static void c11_b_BasicEKF_correctEqn(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, const emlrtStack *c11_sp, c11_insfilterAsync *c11_obj, real_T
  c11_x[28], real_T c11_P[784], real_T c11_h[3], real_T c11_H[84], real_T c11_z
  [3], real_T c11_R[9], real_T c11_innov[3], real_T c11_innovCov[9]);
static void c11_b_sind(SFc11_car_model_FIXEDInstanceStruct *chartInstance,
  real_T *c11_x);
static void c11_b_cosd(SFc11_car_model_FIXEDInstanceStruct *chartInstance,
  real_T *c11_x);
static void init_dsm_address_info(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c11_car_model_FIXED(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
  chartInstance->c11_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c11_is_active_c11_car_model_FIXED = 0U;
  chartInstance->c11_emlrtLocLogSimulated = false;
  c11_emlrtInitVarDataTables(chartInstance,
    chartInstance->c11_emlrtLocationLoggingDataTables,
    chartInstance->c11_emlrtLocLogHistTables);
}

static void initialize_params_c11_car_model_FIXED
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance)
{
  real_T c11_dv1[28];
  real_T c11_dv[3];
  real_T c11_d;
  real_T c11_d1;
  real_T c11_d2;
  real_T c11_d3;
  real_T c11_d4;
  real_T c11_d5;
  real_T c11_d6;
  int32_T c11_i;
  int32_T c11_i1;
  sf_mex_import_named("covG", sf_mex_get_sfun_param(chartInstance->S, 1U, 0U),
                      &c11_d, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c11_covG = c11_d;
  sf_mex_import_named("covA", sf_mex_get_sfun_param(chartInstance->S, 0U, 0U),
                      &c11_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c11_covA = c11_d1;
  sf_mex_import_named("covM", sf_mex_get_sfun_param(chartInstance->S, 2U, 0U),
                      &c11_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c11_covM = c11_d2;
  sf_mex_import_named("covP", sf_mex_get_sfun_param(chartInstance->S, 3U, 0U),
                      &c11_d3, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c11_covP = c11_d3;
  sf_mex_import_named("covV", sf_mex_get_sfun_param(chartInstance->S, 4U, 0U),
                      &c11_d4, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c11_covV = c11_d4;
  sf_mex_import_named("fusion_t", sf_mex_get_sfun_param(chartInstance->S, 5U, 0U),
                      &c11_d5, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c11_fusion_t = c11_d5;
  sf_mex_import_named("location_lla_IC", sf_mex_get_sfun_param(chartInstance->S,
    7U, 0U), c11_dv, 0, 0, 0U, 1, 0U, 2, 1, 3);
  for (c11_i = 0; c11_i < 3; c11_i++) {
    chartInstance->c11_location_lla_IC[c11_i] = c11_dv[c11_i];
  }

  sf_mex_import_named("noise_state", sf_mex_get_sfun_param(chartInstance->S, 8U,
    0U), c11_dv1, 0, 0, 0U, 1, 0U, 1, 28);
  for (c11_i1 = 0; c11_i1 < 28; c11_i1++) {
    chartInstance->c11_noise_state[c11_i1] = c11_dv1[c11_i1];
  }

  sf_mex_import_named("gps_ratio", sf_mex_get_sfun_param(chartInstance->S, 6U,
    0U), &c11_d6, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c11_gps_ratio = c11_d6;
}

static void mdl_start_c11_car_model_FIXED(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void mdl_terminate_c11_car_model_FIXED
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance)
{
  const emlrtLocationLoggingFileInfoType c11_emlrtLocationLoggingFileInfo = {
    "#car_model_FIXED:6049",           /* mexFileName */
    "Mon Apr 17 19:53:00 2023",        /* timestamp */
    "",                                /* buildDir */
    1,                                 /* numFcns */
    256                                /* numHistogramBins */
  };

  const emlrtLocationLoggingFunctionInfoType
    c11_emlrtLocationLoggingFunctionInfoTable[1] = { { "eML_blk_kernel",/* fcnName */
      1,                               /* fcnId */
      22                               /* numInstrPoints */
    } };

  const emlrtLocationLoggingLocationType c11_emlrtLocationInfo[25] = { { 1,/* MxInfoID */
      55,                              /* TextStart */
      5,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      62,                              /* TextStart */
      8,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      72,                              /* TextStart */
      8,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      82,                              /* TextStart */
      12,                              /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      95,                              /* TextStart */
      15,                              /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      112,                             /* TextStart */
      8,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 3,                            /* MxInfoID */
      122,                             /* TextStart */
      8,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 4,                            /* MxInfoID */
      132,                             /* TextStart */
      6,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      140,                             /* TextStart */
      4,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      146,                             /* TextStart */
      4,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      152,                             /* TextStart */
      4,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      158,                             /* TextStart */
      4,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      164,                             /* TextStart */
      4,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      170,                             /* TextStart */
      8,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      180,                             /* TextStart */
      15,                              /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 3,                            /* MxInfoID */
      197,                             /* TextStart */
      11,                              /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      210,                             /* TextStart */
      9,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1014,                            /* TextStart */
      5,                               /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1022,                            /* TextStart */
      25,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1026,                            /* TextStart */
      9,                               /* TextLength */
      5,                               /* Reason */
      false                            /* MoreLocations */
    }, { 3,                            /* MxInfoID */
      1131,                            /* TextStart */
      9,                               /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 3,                            /* MxInfoID */
      1143,                            /* TextStart */
      12,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 4,                            /* MxInfoID */
      1157,                            /* TextStart */
      7,                               /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 4,                            /* MxInfoID */
      1167,                            /* TextStart */
      22,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 10,                           /* MxInfoID */
      1053,                            /* TextStart */
      7,                               /* TextLength */
      4,                               /* Reason */
      false                            /* MoreLocations */
    } };

  const int32_T c11_emlrtLocationLoggingFieldCounts[22] = { 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  if (chartInstance->c11_emlrtLocLogSimulated) {
    emlrtLocationLoggingClearLog("#car_model_FIXED:6049");
    emlrtLocationLoggingPushLog(&c11_emlrtLocationLoggingFileInfo,
      &c11_emlrtLocationLoggingFunctionInfoTable[0],
      &chartInstance->c11_emlrtLocationLoggingDataTables[0],
      &c11_emlrtLocationInfo[0], NULL, 0U, &c11_emlrtLocationLoggingFieldCounts
      [0], NULL);
    addResultsToFPTRepository("#car_model_FIXED:6049");
  }
}

static void mdl_setup_runtime_resources_c11_car_model_FIXED
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance)
{
  static const int32_T c11_postfixPredicateTree[2] = { 0, -1 };

  static const int32_T c11_condTxtEndIdx[1] = { 959 };

  static const int32_T c11_condTxtStartIdx[1] = { 954 };

  static const uint32_T c11_decisionTxtEndIdx = 0U;
  static const uint32_T c11_decisionTxtStartIdx = 0U;
  setDebuggerFlag(chartInstance->S, true);
  setDataBrowseFcn(chartInstance->S, (void *)&c11_chart_data_browse_helper);
  chartInstance->c11_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c11_RuntimeVar,
    &chartInstance->c11_IsDebuggerActive,
    &chartInstance->c11_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c11_mlFcnLineNumber, &chartInstance->c11_IsHeatMapPresent, 0);
  sim_mode_is_external(chartInstance->S);
  covrtCreateStateflowInstanceData(chartInstance->c11_covrtInstance, 1U, 0U, 1U,
    144U);
  covrtChartInitFcn(chartInstance->c11_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c11_covrtInstance, 0U, 0U, false, false,
                    false, 0U, &c11_decisionTxtStartIdx, &c11_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c11_covrtInstance, 0U, 0, NULL, NULL, 0U,
                    NULL);
  covrtEmlInitFcn(chartInstance->c11_covrtInstance, "", 4U, 0U, 1U, 0U, 1U, 0U,
                  0U, 0U, 0U, 0U, 1U, 1U);
  covrtEmlFcnInitFcn(chartInstance->c11_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 1195);
  covrtEmlIfInitFcn(chartInstance->c11_covrtInstance, 4U, 0U, 0U, 950, 959, -1,
                    1012, false);
  covrtEmlMCDCInitFcn(chartInstance->c11_covrtInstance, 4U, 0U, 0U, 953, 959, 1U,
                      0U, c11_condTxtStartIdx, c11_condTxtEndIdx, 2U,
                      c11_postfixPredicateTree, false);
}

static void mdl_cleanup_runtime_resources_c11_car_model_FIXED
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c11_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c11_covrtInstance);
}

static void enable_c11_car_model_FIXED(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c11_car_model_FIXED(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c11_car_model_FIXED(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  static real_T c11_dv3[84] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static char_T c11_b_cv3[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o',
    'l', 'o', 'g', 'i', 'c', 'a', 'l', 'n', 'a', 'n' };

  static char_T c11_b_cv[17] = { 'A', 'c', 'c', 'e', 'l', 'e', 'r', 'a', 't',
    'i', 'o', 'n', 'N', 'o', 'i', 's', 'e' };

  static char_T c11_b_cv1[17] = { 'A', 'c', 'c', 'e', 'l', 'e', 'r', 'a', 't',
    'i', 'o', 'n', 'N', 'o', 'i', 's', 'e' };

  static char_T c11_b_cv2[17] = { 'A', 'c', 'c', 'e', 'l', 'e', 'r', 'a', 't',
    'i', 'o', 'n', 'N', 'o', 'i', 's', 'e' };

  c11_insfilterAsync c11_filter;
  c11_insfilterAsync *c11_b_obj;
  c11_insfilterAsync *c11_c_obj;
  c11_insfilterAsync *c11_d_obj;
  c11_insfilterAsync *c11_e_obj;
  c11_insfilterAsync *c11_f_obj;
  c11_insfilterAsync *c11_g_obj;
  c11_insfilterAsync *c11_h_obj;
  c11_insfilterAsync *c11_i_obj;
  c11_insfilterAsync *c11_j_obj;
  c11_insfilterAsync *c11_k_obj;
  c11_insfilterAsync *c11_l_obj;
  c11_insfilterAsync *c11_m_obj;
  c11_insfilterAsync *c11_n_obj;
  c11_insfilterAsync *c11_o_obj;
  c11_insfilterAsync *c11_obj;
  c11_insfilterAsync *c11_p_obj;
  c11_insfilterAsync *c11_q_obj;
  c11_insfilterAsync *c11_r_obj;
  c11_insfilterAsync *c11_s_obj;
  c11_insfilterAsync *c11_this;
  emlrtStack c11_b_st;
  emlrtStack c11_c_st;
  emlrtStack c11_d_st;
  emlrtStack c11_st = { NULL,          /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *c11_b_y = NULL;
  const mxArray *c11_c_y = NULL;
  const mxArray *c11_d_y = NULL;
  const mxArray *c11_e_y = NULL;
  const mxArray *c11_f_y = NULL;
  const mxArray *c11_g_y = NULL;
  const mxArray *c11_h_y = NULL;
  const mxArray *c11_i_y = NULL;
  const mxArray *c11_j_y = NULL;
  const mxArray *c11_k_y = NULL;
  const mxArray *c11_y = NULL;
  real_T c11_P[784];
  real_T c11_dv1[784];
  real_T c11_dv2[84];
  real_T c11_b_noise_state[28];
  real_T c11_dv[28];
  real_T c11_xk[28];
  real_T c11_Rgyromat[9];
  real_T c11_dv4[9];
  real_T c11_innovCov[9];
  real_T c11_c_noise_state[4];
  real_T c11_b_acceleration[3];
  real_T c11_b_location_lla_IC[3];
  real_T c11_b_magField[3];
  real_T c11_b_position[3];
  real_T c11_b_velocity[3];
  real_T c11_d_noise_state[3];
  real_T c11_e_noise_state[3];
  real_T c11_f_noise_state[3];
  real_T c11_g_noise_state[3];
  real_T c11_h[3];
  real_T c11_h_noise_state[3];
  real_T c11_i_noise_state[3];
  real_T c11_z[3];
  real_T c11_Rgyro;
  real_T c11_Rin;
  real_T c11_a;
  real_T c11_b_Rin;
  real_T c11_b_a;
  real_T c11_b_covA;
  real_T c11_b_covG;
  real_T c11_b_covM;
  real_T c11_b_covP;
  real_T c11_b_covV;
  real_T c11_b_fusion_t;
  real_T c11_b_gps_ratio;
  real_T c11_b_k;
  real_T c11_b_magE;
  real_T c11_b_magN;
  real_T c11_b_x;
  real_T c11_c_count;
  real_T c11_c_x;
  real_T c11_d_count;
  real_T c11_d_k;
  real_T c11_d_x;
  real_T c11_e_x;
  real_T c11_f_k;
  real_T c11_f_x;
  real_T c11_g_b;
  real_T c11_g_x;
  real_T c11_gyrox_b;
  real_T c11_gyroy_b;
  real_T c11_gyroz_b;
  real_T c11_h_x;
  real_T c11_i_x;
  real_T c11_j_x;
  real_T c11_k_x;
  real_T c11_l_x;
  real_T c11_l_y;
  real_T c11_m_x;
  real_T c11_m_y;
  real_T c11_magE;
  real_T c11_magN;
  real_T c11_n_x;
  real_T c11_n_y;
  real_T c11_o_x;
  real_T c11_q;
  real_T c11_r;
  real_T c11_wx;
  real_T c11_wy;
  real_T c11_wz;
  real_T c11_x;
  int32_T c11_b_j;
  int32_T c11_c_k;
  int32_T c11_e_k;
  int32_T c11_i;
  int32_T c11_i1;
  int32_T c11_i10;
  int32_T c11_i11;
  int32_T c11_i12;
  int32_T c11_i13;
  int32_T c11_i14;
  int32_T c11_i15;
  int32_T c11_i16;
  int32_T c11_i17;
  int32_T c11_i18;
  int32_T c11_i19;
  int32_T c11_i2;
  int32_T c11_i20;
  int32_T c11_i21;
  int32_T c11_i22;
  int32_T c11_i23;
  int32_T c11_i24;
  int32_T c11_i25;
  int32_T c11_i26;
  int32_T c11_i27;
  int32_T c11_i28;
  int32_T c11_i29;
  int32_T c11_i3;
  int32_T c11_i30;
  int32_T c11_i31;
  int32_T c11_i32;
  int32_T c11_i33;
  int32_T c11_i34;
  int32_T c11_i35;
  int32_T c11_i36;
  int32_T c11_i37;
  int32_T c11_i38;
  int32_T c11_i39;
  int32_T c11_i4;
  int32_T c11_i40;
  int32_T c11_i41;
  int32_T c11_i42;
  int32_T c11_i43;
  int32_T c11_i44;
  int32_T c11_i45;
  int32_T c11_i46;
  int32_T c11_i47;
  int32_T c11_i48;
  int32_T c11_i49;
  int32_T c11_i5;
  int32_T c11_i50;
  int32_T c11_i51;
  int32_T c11_i52;
  int32_T c11_i53;
  int32_T c11_i54;
  int32_T c11_i55;
  int32_T c11_i56;
  int32_T c11_i57;
  int32_T c11_i58;
  int32_T c11_i59;
  int32_T c11_i6;
  int32_T c11_i60;
  int32_T c11_i61;
  int32_T c11_i7;
  int32_T c11_i8;
  int32_T c11_i9;
  int32_T c11_j;
  int32_T c11_k;
  boolean_T c11_b;
  boolean_T c11_b1;
  boolean_T c11_b10;
  boolean_T c11_b11;
  boolean_T c11_b12;
  boolean_T c11_b13;
  boolean_T c11_b14;
  boolean_T c11_b15;
  boolean_T c11_b16;
  boolean_T c11_b17;
  boolean_T c11_b18;
  boolean_T c11_b19;
  boolean_T c11_b2;
  boolean_T c11_b20;
  boolean_T c11_b21;
  boolean_T c11_b22;
  boolean_T c11_b23;
  boolean_T c11_b24;
  boolean_T c11_b25;
  boolean_T c11_b26;
  boolean_T c11_b27;
  boolean_T c11_b28;
  boolean_T c11_b3;
  boolean_T c11_b4;
  boolean_T c11_b5;
  boolean_T c11_b6;
  boolean_T c11_b7;
  boolean_T c11_b8;
  boolean_T c11_b9;
  boolean_T c11_b_b;
  boolean_T c11_b_p;
  boolean_T c11_c_b;
  boolean_T c11_c_p;
  boolean_T c11_d_b;
  boolean_T c11_d_p;
  boolean_T c11_e_b;
  boolean_T c11_e_p;
  boolean_T c11_exitg1;
  boolean_T c11_f_b;
  boolean_T c11_h_b;
  boolean_T c11_i_b;
  boolean_T c11_j_b;
  boolean_T c11_k_b;
  boolean_T c11_p;
  boolean_T c11_rEQ0;
  c11_st.tls = chartInstance->c11_fEmlrtCtx;
  c11_b_st.prev = &c11_st;
  c11_b_st.tls = c11_st.tls;
  c11_c_st.prev = &c11_b_st;
  c11_c_st.tls = c11_b_st.tls;
  c11_d_st.prev = &c11_c_st;
  c11_d_st.tls = c11_c_st.tls;
  chartInstance->c11_JITTransitionAnimation[0] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  for (c11_i = 0; c11_i < 784; c11_i++) {
    covrtSigUpdateFcn(chartInstance->c11_covrtInstance, 7U,
                      (*chartInstance->c11_cov_in)[c11_i]);
  }

  for (c11_i1 = 0; c11_i1 < 28; c11_i1++) {
    covrtSigUpdateFcn(chartInstance->c11_covrtInstance, 6U,
                      (*chartInstance->c11_state_in)[c11_i1]);
  }

  c11_b = false;
  for (c11_i2 = 0; c11_i2 < 3; c11_i2++) {
    c11_b = (c11_b || ((*chartInstance->c11_magField)[c11_i2] > 200.0));
  }

  c11_b1 = c11_b;
  if (c11_b1) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 5U, 1U);
  }

  c11_b2 = false;
  for (c11_i3 = 0; c11_i3 < 3; c11_i3++) {
    c11_b2 = (c11_b2 || ((*chartInstance->c11_magField)[c11_i3] < -200.0));
  }

  c11_b3 = c11_b2;
  if (c11_b3) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 5U, 0U);
  }

  for (c11_i4 = 0; c11_i4 < 3; c11_i4++) {
    covrtSigUpdateFcn(chartInstance->c11_covrtInstance, 5U,
                      (*chartInstance->c11_magField)[c11_i4]);
  }

  c11_b4 = false;
  for (c11_i5 = 0; c11_i5 < 3; c11_i5++) {
    c11_b4 = (c11_b4 || ((*chartInstance->c11_angularVelocity)[c11_i5] > 2.5));
  }

  c11_b5 = c11_b4;
  if (c11_b5) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 4U, 1U);
  }

  c11_b6 = false;
  for (c11_i6 = 0; c11_i6 < 3; c11_i6++) {
    c11_b6 = (c11_b6 || ((*chartInstance->c11_angularVelocity)[c11_i6] < -2.5));
  }

  c11_b7 = c11_b6;
  if (c11_b7) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 4U, 0U);
  }

  for (c11_i7 = 0; c11_i7 < 3; c11_i7++) {
    covrtSigUpdateFcn(chartInstance->c11_covrtInstance, 4U,
                      (*chartInstance->c11_angularVelocity)[c11_i7]);
  }

  c11_b8 = false;
  for (c11_i8 = 0; c11_i8 < 3; c11_i8++) {
    c11_b8 = (c11_b8 || ((*chartInstance->c11_acceleration)[c11_i8] > 30.0));
  }

  c11_b9 = c11_b8;
  if (c11_b9) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 3U, 1U);
  }

  c11_b10 = false;
  for (c11_i9 = 0; c11_i9 < 3; c11_i9++) {
    c11_b10 = (c11_b10 || ((*chartInstance->c11_acceleration)[c11_i9] < -30.0));
  }

  c11_b11 = c11_b10;
  if (c11_b11) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 3U, 0U);
  }

  for (c11_i10 = 0; c11_i10 < 3; c11_i10++) {
    covrtSigUpdateFcn(chartInstance->c11_covrtInstance, 3U,
                      (*chartInstance->c11_acceleration)[c11_i10]);
  }

  c11_b12 = false;
  for (c11_i11 = 0; c11_i11 < 3; c11_i11++) {
    c11_b12 = (c11_b12 || ((*chartInstance->c11_position)[c11_i11] > 300.0));
  }

  c11_b13 = c11_b12;
  if (c11_b13) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 2U, 1U);
  }

  c11_b14 = false;
  for (c11_i12 = 0; c11_i12 < 3; c11_i12++) {
    c11_b14 = (c11_b14 || ((*chartInstance->c11_position)[c11_i12] < -300.0));
  }

  c11_b15 = c11_b14;
  if (c11_b15) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 2U, 0U);
  }

  for (c11_i13 = 0; c11_i13 < 3; c11_i13++) {
    covrtSigUpdateFcn(chartInstance->c11_covrtInstance, 2U,
                      (*chartInstance->c11_position)[c11_i13]);
  }

  c11_b16 = false;
  for (c11_i14 = 0; c11_i14 < 3; c11_i14++) {
    c11_b16 = (c11_b16 || ((*chartInstance->c11_velocity)[c11_i14] > 30.0));
  }

  c11_b17 = c11_b16;
  if (c11_b17) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 1U, 1U);
  }

  c11_b18 = false;
  for (c11_i15 = 0; c11_i15 < 3; c11_i15++) {
    c11_b18 = (c11_b18 || ((*chartInstance->c11_velocity)[c11_i15] < -30.0));
  }

  c11_b19 = c11_b18;
  if (c11_b19) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 1U, 0U);
  }

  for (c11_i16 = 0; c11_i16 < 3; c11_i16++) {
    covrtSigUpdateFcn(chartInstance->c11_covrtInstance, 1U,
                      (*chartInstance->c11_velocity)[c11_i16]);
  }

  if (*chartInstance->c11_count > 1.0) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 0U, 1U);
  }

  if (*chartInstance->c11_count < 0.0) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 0U, 0U);
  }

  covrtSigUpdateFcn(chartInstance->c11_covrtInstance, 0U,
                    *chartInstance->c11_count);
  chartInstance->c11_sfEvent = CALL_EVENT;
  c11_c_count = *chartInstance->c11_count;
  for (c11_i17 = 0; c11_i17 < 3; c11_i17++) {
    c11_b_velocity[c11_i17] = (*chartInstance->c11_velocity)[c11_i17];
  }

  for (c11_i18 = 0; c11_i18 < 3; c11_i18++) {
    c11_b_position[c11_i18] = (*chartInstance->c11_position)[c11_i18];
  }

  for (c11_i19 = 0; c11_i19 < 3; c11_i19++) {
    c11_b_acceleration[c11_i19] = (*chartInstance->c11_acceleration)[c11_i19];
  }

  for (c11_i20 = 0; c11_i20 < 3; c11_i20++) {
    c11_z[c11_i20] = (*chartInstance->c11_angularVelocity)[c11_i20];
  }

  for (c11_i21 = 0; c11_i21 < 3; c11_i21++) {
    c11_b_magField[c11_i21] = (*chartInstance->c11_magField)[c11_i21];
  }

  for (c11_i22 = 0; c11_i22 < 28; c11_i22++) {
    c11_xk[c11_i22] = (*chartInstance->c11_state_in)[c11_i22];
  }

  for (c11_i23 = 0; c11_i23 < 784; c11_i23++) {
    c11_P[c11_i23] = (*chartInstance->c11_cov_in)[c11_i23];
  }

  c11_b_covG = chartInstance->c11_covG;
  c11_b_covA = chartInstance->c11_covA;
  c11_b_covM = chartInstance->c11_covM;
  c11_b_covP = chartInstance->c11_covP;
  c11_b_covV = chartInstance->c11_covV;
  c11_b_fusion_t = chartInstance->c11_fusion_t;
  for (c11_i24 = 0; c11_i24 < 3; c11_i24++) {
    c11_b_location_lla_IC[c11_i24] = chartInstance->c11_location_lla_IC[c11_i24];
  }

  for (c11_i25 = 0; c11_i25 < 28; c11_i25++) {
    c11_b_noise_state[c11_i25] = chartInstance->c11_noise_state[c11_i25];
  }

  c11_b_gps_ratio = chartInstance->c11_gps_ratio;

  /* logging input variable 'count' for function 'eML_blk_kernel' */
  /* logging input variable 'velocity' for function 'eML_blk_kernel' */
  /* logging input variable 'position' for function 'eML_blk_kernel' */
  /* logging input variable 'acceleration' for function 'eML_blk_kernel' */
  /* logging input variable 'angularVelocity' for function 'eML_blk_kernel' */
  /* logging input variable 'magField' for function 'eML_blk_kernel' */
  /* logging input variable 'state_in' for function 'eML_blk_kernel' */
  /* logging input variable 'cov_in' for function 'eML_blk_kernel' */
  /* logging input variable 'covG' for function 'eML_blk_kernel' */
  /* logging input variable 'covA' for function 'eML_blk_kernel' */
  /* logging input variable 'covM' for function 'eML_blk_kernel' */
  /* logging input variable 'covP' for function 'eML_blk_kernel' */
  /* logging input variable 'covV' for function 'eML_blk_kernel' */
  /* logging input variable 'fusion_t' for function 'eML_blk_kernel' */
  /* logging input variable 'location_lla_IC' for function 'eML_blk_kernel' */
  /* logging input variable 'noise_state' for function 'eML_blk_kernel' */
  /* logging input variable 'gps_ratio' for function 'eML_blk_kernel' */
  chartInstance->c11_emlrtLocLogSimulated = true;

  /* logging input variable 'count' for function 'eML_blk_kernel' */
  c11_emlrt_update_log_1(chartInstance, c11_c_count,
    chartInstance->c11_emlrtLocationLoggingDataTables, 0);

  /* logging input variable 'velocity' for function 'eML_blk_kernel' */
  for (c11_i26 = 0; c11_i26 < 3; c11_i26++) {
    c11_h[c11_i26] = c11_b_velocity[c11_i26];
  }

  c11_b_emlrt_update_log_2(chartInstance, c11_h,
    chartInstance->c11_emlrtLocationLoggingDataTables, 1);

  /* logging input variable 'position' for function 'eML_blk_kernel' */
  for (c11_i27 = 0; c11_i27 < 3; c11_i27++) {
    c11_h[c11_i27] = c11_b_position[c11_i27];
  }

  c11_b_emlrt_update_log_2(chartInstance, c11_h,
    chartInstance->c11_emlrtLocationLoggingDataTables, 2);

  /* logging input variable 'acceleration' for function 'eML_blk_kernel' */
  for (c11_i28 = 0; c11_i28 < 3; c11_i28++) {
    c11_h[c11_i28] = c11_b_acceleration[c11_i28];
  }

  c11_b_emlrt_update_log_2(chartInstance, c11_h,
    chartInstance->c11_emlrtLocationLoggingDataTables, 3);

  /* logging input variable 'angularVelocity' for function 'eML_blk_kernel' */
  for (c11_i29 = 0; c11_i29 < 3; c11_i29++) {
    c11_h[c11_i29] = c11_z[c11_i29];
  }

  c11_b_emlrt_update_log_2(chartInstance, c11_h,
    chartInstance->c11_emlrtLocationLoggingDataTables, 4);

  /* logging input variable 'magField' for function 'eML_blk_kernel' */
  for (c11_i30 = 0; c11_i30 < 3; c11_i30++) {
    c11_h[c11_i30] = c11_b_magField[c11_i30];
  }

  c11_b_emlrt_update_log_2(chartInstance, c11_h,
    chartInstance->c11_emlrtLocationLoggingDataTables, 5);

  /* logging input variable 'state_in' for function 'eML_blk_kernel' */
  for (c11_i31 = 0; c11_i31 < 28; c11_i31++) {
    c11_dv[c11_i31] = c11_xk[c11_i31];
  }

  c11_b_emlrt_update_log_3(chartInstance, c11_dv,
    chartInstance->c11_emlrtLocationLoggingDataTables, 6);

  /* logging input variable 'cov_in' for function 'eML_blk_kernel' */
  for (c11_i32 = 0; c11_i32 < 784; c11_i32++) {
    c11_dv1[c11_i32] = c11_P[c11_i32];
  }

  c11_b_emlrt_update_log_4(chartInstance, c11_dv1,
    chartInstance->c11_emlrtLocationLoggingDataTables, 7);

  /* logging input variable 'covG' for function 'eML_blk_kernel' */
  c11_emlrt_update_log_1(chartInstance, c11_b_covG,
    chartInstance->c11_emlrtLocationLoggingDataTables, 8);

  /* logging input variable 'covA' for function 'eML_blk_kernel' */
  c11_emlrt_update_log_1(chartInstance, c11_b_covA,
    chartInstance->c11_emlrtLocationLoggingDataTables, 9);

  /* logging input variable 'covM' for function 'eML_blk_kernel' */
  c11_emlrt_update_log_1(chartInstance, c11_b_covM,
    chartInstance->c11_emlrtLocationLoggingDataTables, 10);

  /* logging input variable 'covP' for function 'eML_blk_kernel' */
  c11_emlrt_update_log_1(chartInstance, c11_b_covP,
    chartInstance->c11_emlrtLocationLoggingDataTables, 11);

  /* logging input variable 'covV' for function 'eML_blk_kernel' */
  c11_emlrt_update_log_1(chartInstance, c11_b_covV,
    chartInstance->c11_emlrtLocationLoggingDataTables, 12);

  /* logging input variable 'fusion_t' for function 'eML_blk_kernel' */
  c11_emlrt_update_log_1(chartInstance, c11_b_fusion_t,
    chartInstance->c11_emlrtLocationLoggingDataTables, 13);

  /* logging input variable 'location_lla_IC' for function 'eML_blk_kernel' */
  for (c11_i33 = 0; c11_i33 < 3; c11_i33++) {
    c11_h[c11_i33] = c11_b_location_lla_IC[c11_i33];
  }

  c11_b_emlrt_update_log_2(chartInstance, c11_h,
    chartInstance->c11_emlrtLocationLoggingDataTables, 14);

  /* logging input variable 'noise_state' for function 'eML_blk_kernel' */
  for (c11_i34 = 0; c11_i34 < 28; c11_i34++) {
    c11_dv[c11_i34] = c11_b_noise_state[c11_i34];
  }

  c11_b_emlrt_update_log_3(chartInstance, c11_dv,
    chartInstance->c11_emlrtLocationLoggingDataTables, 15);

  /* logging input variable 'gps_ratio' for function 'eML_blk_kernel' */
  c11_emlrt_update_log_1(chartInstance, c11_b_gps_ratio,
    chartInstance->c11_emlrtLocationLoggingDataTables, 16);
  c11_d_count = c11_c_count;
  covrtEmlFcnEval(chartInstance->c11_covrtInstance, 4U, 0, 0);
  c11_b_st.site = &c11_emlrtRSI;
  c11_obj = &c11_filter;
  c11_b_obj = c11_obj;
  c11_c_st.site = &c11_w_emlrtRSI;
  c11_c_obj = c11_b_obj;
  c11_b_obj = c11_c_obj;
  c11_d_st.site = &c11_x_emlrtRSI;
  c11_d_obj = c11_b_obj;
  c11_b_obj = c11_d_obj;
  c11_d_st.site = &c11_y_emlrtRSI;
  c11_e_obj = c11_b_obj;
  c11_b_obj = c11_e_obj;
  c11_f_obj = c11_b_obj;
  c11_b_obj = c11_f_obj;
  c11_g_obj = c11_b_obj;
  c11_b_obj = c11_g_obj;
  c11_this = c11_b_obj;
  c11_b_obj = c11_this;
  c11_h_obj = c11_b_obj;
  c11_b_obj = c11_h_obj;
  for (c11_i35 = 0; c11_i35 < 4; c11_i35++) {
    c11_b_obj->OrientationIdx[c11_i35] = 1.0 + (real_T)c11_i35;
  }

  c11_b_st.site = &c11_b_emlrtRSI;
  c11_INSFilterEKF_set_ReferenceLocation(chartInstance, &c11_b_st, &c11_filter,
    c11_b_location_lla_IC);
  c11_b_st.site = &c11_c_emlrtRSI;
  c11_i_obj = &c11_filter;
  c11_c_st.site = &c11_hb_emlrtRSI;
  c11_AsyncMARGGPSFuserBase_setState(chartInstance, &c11_c_st, c11_i_obj, c11_xk);
  c11_b_st.site = &c11_d_emlrtRSI;
  c11_j_obj = &c11_filter;
  c11_c_st.site = &c11_jb_emlrtRSI;
  c11_AsyncMARGGPSFuserBase_setStateCovariance(chartInstance, &c11_c_st,
    c11_j_obj, c11_P);
  c11_b_st.site = &c11_e_emlrtRSI;
  for (c11_i36 = 0; c11_i36 < 4; c11_i36++) {
    c11_c_noise_state[c11_i36] = c11_b_noise_state[c11_i36];
  }

  c11_AsyncMARGGPSFuserBase_set_QuaternionNoise(chartInstance, &c11_b_st,
    &c11_filter, c11_c_noise_state);
  c11_b_st.site = &c11_f_emlrtRSI;
  for (c11_i37 = 0; c11_i37 < 3; c11_i37++) {
    c11_d_noise_state[c11_i37] = c11_b_noise_state[c11_i37 + 4];
  }

  c11_AsyncMARGGPSFuserBase_set_AngularVelocityNoise(chartInstance, &c11_b_st,
    &c11_filter, c11_d_noise_state);
  c11_b_st.site = &c11_g_emlrtRSI;
  for (c11_i38 = 0; c11_i38 < 3; c11_i38++) {
    c11_e_noise_state[c11_i38] = c11_b_noise_state[c11_i38 + 7];
  }

  c11_AsyncMARGGPSFuserBase_set_PositionNoise(chartInstance, &c11_b_st,
    &c11_filter, c11_e_noise_state);
  c11_b_st.site = &c11_h_emlrtRSI;
  for (c11_i39 = 0; c11_i39 < 3; c11_i39++) {
    c11_f_noise_state[c11_i39] = c11_b_noise_state[c11_i39 + 10];
  }

  c11_AsyncMARGGPSFuserBase_set_VelocityNoise(chartInstance, &c11_b_st,
    &c11_filter, c11_f_noise_state);
  c11_b_st.site = &c11_i_emlrtRSI;
  c11_k_obj = &c11_filter;
  for (c11_i40 = 0; c11_i40 < 3; c11_i40++) {
    c11_b_location_lla_IC[c11_i40] = c11_b_noise_state[c11_i40 + 13];
  }

  c11_c_st.site = &c11_pb_emlrtRSI;
  c11_d_st.site = &c11_gb_emlrtRSI;
  c11_p = true;
  c11_k = 0;
  c11_exitg1 = false;
  while ((!c11_exitg1) && (c11_k < 3)) {
    c11_b_k = 1.0 + (real_T)c11_k;
    c11_x = c11_b_location_lla_IC[(int32_T)c11_b_k - 1];
    c11_b_x = c11_x;
    c11_b_b = muDoubleScalarIsInf(c11_b_x);
    c11_b21 = !c11_b_b;
    c11_c_x = c11_x;
    c11_c_b = muDoubleScalarIsNaN(c11_c_x);
    c11_b22 = !c11_c_b;
    c11_d_b = (c11_b21 && c11_b22);
    if (c11_d_b) {
      c11_k++;
    } else {
      c11_p = false;
      c11_exitg1 = true;
    }
  }

  if (c11_p) {
    c11_b20 = true;
  } else {
    c11_b20 = false;
  }

  if (!c11_b20) {
    c11_y = NULL;
    sf_mex_assign(&c11_y, sf_mex_create("y", c11_cv4, 10, 0U, 1U, 0U, 2, 1, 21),
                  false);
    c11_b_y = NULL;
    sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_cv5, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c11_c_y = NULL;
    sf_mex_assign(&c11_c_y, sf_mex_create("y", c11_b_cv, 10, 0U, 1U, 0U, 2, 1,
      17), false);
    sf_mex_call(&c11_d_st, &c11_emlrtMCI, "error", 0U, 2U, 14, c11_y, 14,
                sf_mex_call(&c11_d_st, NULL, "getString", 1U, 1U, 14,
      sf_mex_call(&c11_d_st, NULL, "message", 1U, 2U, 14, c11_b_y, 14, c11_c_y)));
  }

  c11_d_st.site = &c11_gb_emlrtRSI;
  c11_b_p = true;
  c11_c_k = 0;
  c11_exitg1 = false;
  while ((!c11_exitg1) && (c11_c_k < 3)) {
    c11_d_k = 1.0 + (real_T)c11_c_k;
    c11_d_x = c11_b_location_lla_IC[(int32_T)c11_d_k - 1];
    c11_c_p = !(c11_d_x <= 0.0);
    if (c11_c_p) {
      c11_c_k++;
    } else {
      c11_b_p = false;
      c11_exitg1 = true;
    }
  }

  if (c11_b_p) {
    c11_b23 = true;
  } else {
    c11_b23 = false;
  }

  if (!c11_b23) {
    c11_d_y = NULL;
    sf_mex_assign(&c11_d_y, sf_mex_create("y", c11_cv2, 10, 0U, 1U, 0U, 2, 1, 23),
                  false);
    c11_e_y = NULL;
    sf_mex_assign(&c11_e_y, sf_mex_create("y", c11_cv3, 10, 0U, 1U, 0U, 2, 1, 48),
                  false);
    c11_f_y = NULL;
    sf_mex_assign(&c11_f_y, sf_mex_create("y", c11_b_cv1, 10, 0U, 1U, 0U, 2, 1,
      17), false);
    sf_mex_call(&c11_d_st, &c11_e_emlrtMCI, "error", 0U, 2U, 14, c11_d_y, 14,
                sf_mex_call(&c11_d_st, NULL, "getString", 1U, 1U, 14,
      sf_mex_call(&c11_d_st, NULL, "message", 1U, 2U, 14, c11_e_y, 14, c11_f_y)));
  }

  c11_d_st.site = &c11_gb_emlrtRSI;
  c11_d_p = true;
  c11_e_k = 0;
  c11_exitg1 = false;
  while ((!c11_exitg1) && (c11_e_k < 3)) {
    c11_f_k = 1.0 + (real_T)c11_e_k;
    c11_e_x = c11_b_location_lla_IC[(int32_T)c11_f_k - 1];
    c11_f_x = c11_e_x;
    c11_e_b = muDoubleScalarIsNaN(c11_f_x);
    c11_e_p = !c11_e_b;
    if (c11_e_p) {
      c11_e_k++;
    } else {
      c11_d_p = false;
      c11_exitg1 = true;
    }
  }

  if (c11_d_p) {
    c11_b24 = true;
  } else {
    c11_b24 = false;
  }

  if (!c11_b24) {
    c11_g_y = NULL;
    sf_mex_assign(&c11_g_y, sf_mex_create("y", c11_cv, 10, 0U, 1U, 0U, 2, 1, 21),
                  false);
    c11_h_y = NULL;
    sf_mex_assign(&c11_h_y, sf_mex_create("y", c11_cv1, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c11_i_y = NULL;
    sf_mex_assign(&c11_i_y, sf_mex_create("y", c11_b_cv2, 10, 0U, 1U, 0U, 2, 1,
      17), false);
    sf_mex_call(&c11_d_st, &c11_d_emlrtMCI, "error", 0U, 2U, 14, c11_g_y, 14,
                sf_mex_call(&c11_d_st, NULL, "getString", 1U, 1U, 14,
      sf_mex_call(&c11_d_st, NULL, "message", 1U, 2U, 14, c11_h_y, 14, c11_i_y)));
  }

  for (c11_i41 = 0; c11_i41 < 3; c11_i41++) {
    c11_k_obj->AccelerationNoise[c11_i41] = c11_b_location_lla_IC[c11_i41];
  }

  c11_b_st.site = &c11_j_emlrtRSI;
  for (c11_i42 = 0; c11_i42 < 3; c11_i42++) {
    c11_g_noise_state[c11_i42] = c11_b_noise_state[c11_i42 + 16];
  }

  c11_AsyncMARGGPSFuserBase_set_GyroscopeBiasNoise(chartInstance, &c11_b_st,
    &c11_filter, c11_g_noise_state);
  c11_b_st.site = &c11_k_emlrtRSI;
  for (c11_i43 = 0; c11_i43 < 3; c11_i43++) {
    c11_h_noise_state[c11_i43] = c11_b_noise_state[c11_i43 + 19];
  }

  c11_AsyncMARGGPSFuserBase_set_AccelerometerBiasNoise(chartInstance, &c11_b_st,
    &c11_filter, c11_h_noise_state);
  c11_b_st.site = &c11_l_emlrtRSI;
  for (c11_i44 = 0; c11_i44 < 3; c11_i44++) {
    c11_i_noise_state[c11_i44] = c11_b_noise_state[c11_i44 + 22];
  }

  c11_AsyncMARGGPSFuserBase_set_GeomagneticVectorNoise(chartInstance, &c11_b_st,
    &c11_filter, c11_i_noise_state);
  c11_b_st.site = &c11_m_emlrtRSI;
  c11_AsyncMARGGPSFuserBase_set_MagnetometerBiasNoise(chartInstance, &c11_b_st,
    &c11_filter, &c11_b_noise_state[25]);
  c11_b_st.site = &c11_n_emlrtRSI;
  c11_AsyncMARGGPSFuserBase_predict(chartInstance, &c11_b_st, &c11_filter,
    c11_b_fusion_t);
  c11_b_st.site = &c11_o_emlrtRSI;
  c11_AsyncMARGGPSFuserBase_fuseaccel(chartInstance, &c11_b_st, &c11_filter,
    c11_b_acceleration, c11_b_covA);
  c11_b_st.site = &c11_p_emlrtRSI;
  c11_l_obj = &c11_filter;
  c11_Rgyro = c11_b_covG;
  c11_Rin = c11_Rgyro;
  c11_b_Rin = c11_Rin;
  c11_a = c11_b_Rin;
  for (c11_i45 = 0; c11_i45 < 3; c11_i45++) {
    c11_h[c11_i45] = c11_a;
  }

  for (c11_i46 = 0; c11_i46 < 9; c11_i46++) {
    c11_Rgyromat[c11_i46] = 0.0;
  }

  for (c11_j = 0; c11_j < 3; c11_j++) {
    c11_b_j = c11_j;
    c11_Rgyromat[c11_b_j + 3 * c11_b_j] = c11_h[c11_b_j];
  }

  c11_c_st.site = &c11_ld_emlrtRSI;
  c11_m_obj = c11_l_obj;
  c11_d_st.site = &c11_jc_emlrtRSI;
  c11_n_obj = c11_m_obj;
  for (c11_i47 = 0; c11_i47 < 28; c11_i47++) {
    c11_xk[c11_i47] = c11_n_obj->pState[c11_i47];
  }

  c11_magN = c11_xk[22];
  c11_magE = c11_xk[23];
  c11_xk[22] = c11_magN;
  c11_xk[23] = c11_magE;
  c11_wx = c11_xk[4];
  c11_wy = c11_xk[5];
  c11_wz = c11_xk[6];
  c11_gyrox_b = c11_xk[19];
  c11_gyroy_b = c11_xk[20];
  c11_gyroz_b = c11_xk[21];
  c11_h[0] = c11_gyrox_b + c11_wx;
  c11_h[1] = c11_gyroy_b + c11_wy;
  c11_h[2] = c11_gyroz_b + c11_wz;
  c11_d_st.site = &c11_mc_emlrtRSI;
  c11_o_obj = c11_m_obj;
  for (c11_i48 = 0; c11_i48 < 784; c11_i48++) {
    c11_P[c11_i48] = c11_o_obj->pStateCovariance[c11_i48];
  }

  c11_d_st.site = &c11_nc_emlrtRSI;
  for (c11_i49 = 0; c11_i49 < 84; c11_i49++) {
    c11_dv2[c11_i49] = c11_dv3[c11_i49];
  }

  c11_b_BasicEKF_correctEqn(chartInstance, &c11_d_st, c11_m_obj, c11_xk, c11_P,
    c11_h, c11_dv2, c11_z, c11_Rgyromat, c11_b_location_lla_IC, c11_innovCov);
  c11_d_st.site = &c11_oc_emlrtRSI;
  c11_AsyncMARGGPSFuserBase_setStateCovariance(chartInstance, &c11_d_st,
    c11_m_obj, c11_P);
  c11_d_st.site = &c11_pc_emlrtRSI;
  c11_AsyncMARGGPSFuserBase_setState(chartInstance, &c11_d_st, c11_m_obj, c11_xk);
  c11_b_st.site = &c11_q_emlrtRSI;
  c11_AsyncMARGGPSFuserBase_fusemag(chartInstance, &c11_b_st, &c11_filter,
    c11_b_magField, c11_b_covM);
  c11_b_st.site = &c11_r_emlrtRSI;
  c11_g_x = c11_d_count;
  c11_h_x = c11_g_x;
  c11_f_b = muDoubleScalarIsNaN(c11_h_x);
  if (c11_f_b) {
    c11_j_y = NULL;
    sf_mex_assign(&c11_j_y, sf_mex_create("y", c11_b_cv3, 10, 0U, 1U, 0U, 2, 1,
      19), false);
    c11_k_y = NULL;
    sf_mex_assign(&c11_k_y, sf_mex_create("y", c11_b_cv3, 10, 0U, 1U, 0U, 2, 1,
      19), false);
    sf_mex_call(&c11_b_st, &c11_h_emlrtMCI, "error", 0U, 2U, 14, c11_j_y, 14,
                sf_mex_call(&c11_b_st, NULL, "getString", 1U, 1U, 14,
      sf_mex_call(&c11_b_st, NULL, "message", 1U, 1U, 14, c11_k_y)));
  }

  if (covrtEmlIfEval(chartInstance->c11_covrtInstance, 4U, 0, 0,
                     covrtEmlMcdcEval(chartInstance->c11_covrtInstance, 4U, 0, 0,
        !covrtEmlCondEval(chartInstance->c11_covrtInstance, 4U, 0, 0,
                          c11_d_count != 0.0)))) {
    c11_b_st.site = &c11_s_emlrtRSI;
    c11_AsyncMARGGPSFuserBase_fusegps(chartInstance, &c11_b_st, &c11_filter,
      c11_b_position, c11_b_covP, c11_b_velocity, c11_b_covV);
  }

  c11_i_x = c11_emlrt_update_log_1(chartInstance, c11_d_count + 1.0,
    chartInstance->c11_emlrtLocationLoggingDataTables, 18);
  c11_l_y = c11_b_gps_ratio;
  c11_b_a = c11_i_x;
  c11_g_b = c11_l_y;
  c11_j_x = c11_b_a;
  c11_m_y = c11_g_b;
  c11_k_x = c11_j_x;
  c11_n_y = c11_m_y;
  c11_r = c11_k_x;
  if (c11_n_y == 0.0) {
    if (c11_k_x == 0.0) {
      c11_r = c11_n_y;
    }
  } else {
    c11_l_x = c11_k_x;
    c11_h_b = muDoubleScalarIsNaN(c11_l_x);
    if (c11_h_b) {
      c11_r = rtNaN;
    } else {
      c11_m_x = c11_n_y;
      c11_i_b = muDoubleScalarIsNaN(c11_m_x);
      if (c11_i_b) {
        c11_r = rtNaN;
      } else {
        c11_n_x = c11_k_x;
        c11_j_b = muDoubleScalarIsInf(c11_n_x);
        if (c11_j_b) {
          c11_r = rtNaN;
        } else if (c11_k_x == 0.0) {
          c11_r = 0.0 / c11_n_y;
        } else {
          c11_o_x = c11_n_y;
          c11_k_b = muDoubleScalarIsInf(c11_o_x);
          if (c11_k_b) {
            if ((c11_n_y < 0.0) != (c11_k_x < 0.0)) {
              c11_r = c11_n_y;
            }
          } else {
            c11_r = muDoubleScalarRem(c11_k_x, c11_n_y);
            c11_rEQ0 = (c11_r == 0.0);
            if ((!c11_rEQ0) && (c11_n_y > muDoubleScalarFloor(c11_n_y))) {
              c11_q = muDoubleScalarAbs(c11_k_x / c11_n_y);
              c11_rEQ0 = !(muDoubleScalarAbs(c11_q - muDoubleScalarFloor(c11_q +
                0.5)) > 2.2204460492503131E-16 * c11_q);
            }

            if (c11_rEQ0) {
              c11_r = c11_n_y * 0.0;
            } else if ((c11_k_x < 0.0) != (c11_n_y < 0.0)) {
              c11_r += c11_n_y;
            }
          }
        }
      }
    }
  }

  c11_d_count = c11_emlrt_update_log_1(chartInstance, c11_r,
    chartInstance->c11_emlrtLocationLoggingDataTables, 17);
  c11_b_st.site = &c11_t_emlrtRSI;
  c11_INSFilterEKF_pose(chartInstance, &c11_b_st, &c11_filter, c11_h, c11_dv4,
                        c11_b_location_lla_IC);
  for (c11_i50 = 0; c11_i50 < 9; c11_i50++) {
    (*chartInstance->c11_rot_map)[c11_i50] = c11_dv4[c11_i50];
  }

  c11_b_emlrt_update_log_5(chartInstance, *chartInstance->c11_rot_map,
    chartInstance->c11_emlrtLocationLoggingDataTables, 21);
  c11_b_st.site = &c11_u_emlrtRSI;
  c11_p_obj = &c11_filter;
  c11_c_st.site = &c11_nf_emlrtRSI;
  c11_q_obj = c11_p_obj;
  for (c11_i51 = 0; c11_i51 < 28; c11_i51++) {
    (*chartInstance->c11_state_out)[c11_i51] = c11_q_obj->pState[c11_i51];
  }

  c11_b_magN = (*chartInstance->c11_state_out)[22];
  c11_b_magE = (*chartInstance->c11_state_out)[23];
  (*chartInstance->c11_state_out)[22] = c11_b_magN;
  (*chartInstance->c11_state_out)[23] = c11_b_magE;
  c11_b_emlrt_update_log_3(chartInstance, *chartInstance->c11_state_out,
    chartInstance->c11_emlrtLocationLoggingDataTables, 19);
  c11_b_st.site = &c11_v_emlrtRSI;
  c11_r_obj = &c11_filter;
  c11_c_st.site = &c11_of_emlrtRSI;
  c11_s_obj = c11_r_obj;
  for (c11_i52 = 0; c11_i52 < 784; c11_i52++) {
    (*chartInstance->c11_cov_out)[c11_i52] = c11_s_obj->pStateCovariance[c11_i52];
  }

  c11_b_emlrt_update_log_4(chartInstance, *chartInstance->c11_cov_out,
    chartInstance->c11_emlrtLocationLoggingDataTables, 20);
  *chartInstance->c11_b_count = c11_d_count;
  c11_do_animation_call_c11_car_model_FIXED(chartInstance);
  if (*chartInstance->c11_b_count > 1.0) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 8U, 1U);
  }

  if (*chartInstance->c11_b_count < 0.0) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 8U, 0U);
  }

  covrtSigUpdateFcn(chartInstance->c11_covrtInstance, 8U,
                    *chartInstance->c11_b_count);
  c11_b25 = false;
  c11_i53 = 0;
  for (c11_i54 = 0; c11_i54 < 3; c11_i54++) {
    for (c11_i55 = 0; c11_i55 < 3; c11_i55++) {
      c11_b25 = (c11_b25 || ((*chartInstance->c11_rot_map)[c11_i55 + c11_i53] >
                  4.0));
    }

    c11_i53 += 3;
  }

  c11_b26 = c11_b25;
  if (c11_b26) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 9U, 1U);
  }

  c11_b27 = false;
  c11_i56 = 0;
  for (c11_i57 = 0; c11_i57 < 3; c11_i57++) {
    for (c11_i58 = 0; c11_i58 < 3; c11_i58++) {
      c11_b27 = (c11_b27 || ((*chartInstance->c11_rot_map)[c11_i58 + c11_i56] <
                  -4.0));
    }

    c11_i56 += 3;
  }

  c11_b28 = c11_b27;
  if (c11_b28) {
    sf_data_range_error(chartInstance->S, 0U, 0U, 0U, 9U, 0U);
  }

  for (c11_i59 = 0; c11_i59 < 9; c11_i59++) {
    covrtSigUpdateFcn(chartInstance->c11_covrtInstance, 9U,
                      (*chartInstance->c11_rot_map)[c11_i59]);
  }

  for (c11_i60 = 0; c11_i60 < 28; c11_i60++) {
    covrtSigUpdateFcn(chartInstance->c11_covrtInstance, 10U,
                      (*chartInstance->c11_state_out)[c11_i60]);
  }

  for (c11_i61 = 0; c11_i61 < 784; c11_i61++) {
    covrtSigUpdateFcn(chartInstance->c11_covrtInstance, 11U,
                      (*chartInstance->c11_cov_out)[c11_i61]);
  }
}

static void ext_mode_exec_c11_car_model_FIXED
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c11_update_jit_animation_c11_car_model_FIXED
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c11_do_animation_call_c11_car_model_FIXED
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static const mxArray *get_sim_state_c11_car_model_FIXED
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance)
{
  const mxArray *c11_b_y = NULL;
  const mxArray *c11_c_y = NULL;
  const mxArray *c11_d_y = NULL;
  const mxArray *c11_e_y = NULL;
  const mxArray *c11_f_y = NULL;
  const mxArray *c11_st;
  const mxArray *c11_y = NULL;
  c11_st = NULL;
  c11_st = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_createcellmatrix(5, 1), false);
  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", chartInstance->c11_b_count, 0, 0U,
    0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 0, c11_b_y);
  c11_c_y = NULL;
  sf_mex_assign(&c11_c_y, sf_mex_create("y", *chartInstance->c11_cov_out, 0, 0U,
    1U, 0U, 2, 28, 28), false);
  sf_mex_setcell(c11_y, 1, c11_c_y);
  c11_d_y = NULL;
  sf_mex_assign(&c11_d_y, sf_mex_create("y", *chartInstance->c11_rot_map, 0, 0U,
    1U, 0U, 2, 3, 3), false);
  sf_mex_setcell(c11_y, 2, c11_d_y);
  c11_e_y = NULL;
  sf_mex_assign(&c11_e_y, sf_mex_create("y", *chartInstance->c11_state_out, 0,
    0U, 1U, 0U, 1, 28), false);
  sf_mex_setcell(c11_y, 3, c11_e_y);
  c11_f_y = NULL;
  sf_mex_assign(&c11_f_y, sf_mex_create("y",
    &chartInstance->c11_is_active_c11_car_model_FIXED, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 4, c11_f_y);
  sf_mex_assign(&c11_st, c11_y, false);
  return c11_st;
}

static void set_sim_state_c11_car_model_FIXED
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance, const mxArray *c11_st)
{
  const mxArray *c11_u;
  real_T c11_dv[784];
  real_T c11_dv2[28];
  real_T c11_dv1[9];
  int32_T c11_i;
  int32_T c11_i1;
  int32_T c11_i2;
  chartInstance->c11_doneDoubleBufferReInit = true;
  c11_u = sf_mex_dup(c11_st);
  *chartInstance->c11_b_count = c11_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c11_u, 0)), "count");
  c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 1)),
    "cov_out", c11_dv);
  for (c11_i = 0; c11_i < 784; c11_i++) {
    (*chartInstance->c11_cov_out)[c11_i] = c11_dv[c11_i];
  }

  c11_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 2)),
    "rot_map", c11_dv1);
  for (c11_i1 = 0; c11_i1 < 9; c11_i1++) {
    (*chartInstance->c11_rot_map)[c11_i1] = c11_dv1[c11_i1];
  }

  c11_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 3)),
    "state_out", c11_dv2);
  for (c11_i2 = 0; c11_i2 < 28; c11_i2++) {
    (*chartInstance->c11_state_out)[c11_i2] = c11_dv2[c11_i2];
  }

  chartInstance->c11_is_active_c11_car_model_FIXED = c11_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 4)),
     "is_active_c11_car_model_FIXED");
  sf_mex_destroy(&c11_u);
  sf_mex_destroy(&c11_st);
}

static void initSimStructsc11_car_model_FIXED
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c11_emlrt_update_log_1(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c11_in, emlrtLocationLoggingDataType c11_table[],
  int32_T c11_index)
{
  emlrtLocationLoggingDataType *c11_b_table;
  emlrtLocationLoggingHistogramType *c11_histTable;
  real_T c11_inDouble;
  real_T c11_localMax;
  real_T c11_localMin;
  real_T c11_significand;
  int32_T c11_exponent;
  boolean_T c11_isLoggingEnabledHere;
  (void)chartInstance;
  c11_isLoggingEnabledHere = (c11_index >= 0);
  if (c11_isLoggingEnabledHere) {
    c11_b_table = (emlrtLocationLoggingDataType *)&c11_table[c11_index];
    c11_localMin = c11_b_table[0U].SimMin;
    c11_localMax = c11_b_table[0U].SimMax;
    c11_histTable = c11_b_table[0U].HistogramTable;

    /* Simulation Min-Max logging. */
    if (c11_in < c11_localMin) {
      c11_localMin = c11_in;
    }

    if (c11_in > c11_localMax) {
      c11_localMax = c11_in;
    }

    /* Histogram logging. */
    c11_inDouble = c11_in;
    c11_histTable->TotalNumberOfValues++;
    if (c11_inDouble == 0.0) {
      c11_histTable->NumberOfZeros++;
    } else {
      c11_histTable->SimSum += c11_inDouble;
      if ((!muDoubleScalarIsInf(c11_inDouble)) && (!muDoubleScalarIsNaN
           (c11_inDouble))) {
        c11_significand = frexp(c11_inDouble, &c11_exponent);
        if (c11_exponent > 128) {
          c11_exponent = 128;
        }

        if (c11_exponent < -127) {
          c11_exponent = -127;
        }

        if (c11_significand < 0.0) {
          c11_histTable->NumberOfNegativeValues++;
          c11_histTable->HistogramOfNegativeValues[127 + c11_exponent]++;
        } else {
          c11_histTable->NumberOfPositiveValues++;
          c11_histTable->HistogramOfPositiveValues[127 + c11_exponent]++;
        }
      }
    }

    c11_b_table[0U].SimMin = c11_localMin;
    c11_b_table[0U].SimMax = c11_localMax;

    /* IsAlwaysInteger logging. */
    if (c11_in != muDoubleScalarFloor(c11_in)) {
      c11_b_table[0U].IsAlwaysInteger = false;
    }
  }

  return c11_in;
}

static void c11_emlrt_update_log_2(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c11_in[3], emlrtLocationLoggingDataType c11_table[],
  int32_T c11_index, real_T c11_out[3])
{
  int32_T c11_i;
  for (c11_i = 0; c11_i < 3; c11_i++) {
    c11_out[c11_i] = c11_in[c11_i];
  }

  c11_b_emlrt_update_log_2(chartInstance, c11_out, c11_table, c11_index);
}

static void c11_emlrt_update_log_3(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c11_in[28], emlrtLocationLoggingDataType c11_table[],
  int32_T c11_index, real_T c11_out[28])
{
  int32_T c11_i;
  for (c11_i = 0; c11_i < 28; c11_i++) {
    c11_out[c11_i] = c11_in[c11_i];
  }

  c11_b_emlrt_update_log_3(chartInstance, c11_out, c11_table, c11_index);
}

static void c11_emlrt_update_log_4(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c11_in[784], emlrtLocationLoggingDataType c11_table[],
  int32_T c11_index, real_T c11_out[784])
{
  int32_T c11_i;
  for (c11_i = 0; c11_i < 784; c11_i++) {
    c11_out[c11_i] = c11_in[c11_i];
  }

  c11_b_emlrt_update_log_4(chartInstance, c11_out, c11_table, c11_index);
}

static void c11_emlrt_update_log_5(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c11_in[9], emlrtLocationLoggingDataType c11_table[],
  int32_T c11_index, real_T c11_out[9])
{
  int32_T c11_i;
  for (c11_i = 0; c11_i < 9; c11_i++) {
    c11_out[c11_i] = c11_in[c11_i];
  }

  c11_b_emlrt_update_log_5(chartInstance, c11_out, c11_table, c11_index);
}

static void c11_emlrtInitVarDataTables(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, emlrtLocationLoggingDataType c11_dataTables[22],
  emlrtLocationLoggingHistogramType c11_histTables[22])
{
  int32_T c11_i;
  int32_T c11_iH;
  (void)chartInstance;
  for (c11_i = 0; c11_i < 22; c11_i++) {
    c11_dataTables[c11_i].SimMin = rtInf;
    c11_dataTables[c11_i].SimMax = rtMinusInf;
    c11_dataTables[c11_i].OverflowWraps = 0;
    c11_dataTables[c11_i].Saturations = 0;
    c11_dataTables[c11_i].IsAlwaysInteger = true;
    c11_dataTables[c11_i].HistogramTable = &c11_histTables[c11_i];
    c11_histTables[c11_i].NumberOfZeros = 0.0;
    c11_histTables[c11_i].NumberOfPositiveValues = 0.0;
    c11_histTables[c11_i].NumberOfNegativeValues = 0.0;
    c11_histTables[c11_i].TotalNumberOfValues = 0.0;
    c11_histTables[c11_i].SimSum = 0.0;
    for (c11_iH = 0; c11_iH < 256; c11_iH++) {
      c11_histTables[c11_i].HistogramOfPositiveValues[c11_iH] = 0.0;
      c11_histTables[c11_i].HistogramOfNegativeValues[c11_iH] = 0.0;
    }
  }
}

const mxArray *sf_c11_car_model_FIXED_get_eml_resolved_functions_info(void)
{
  const mxArray *c11_nameCaptureInfo = NULL;
  c11_nameCaptureInfo = NULL;
  sf_mex_assign(&c11_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c11_nameCaptureInfo;
}

static void c11_INSFilterEKF_set_ReferenceLocation
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance, const emlrtStack *c11_sp,
   c11_insfilterAsync *c11_obj, real_T c11_val[3])
{
  static char_T c11_b_cv2[39] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'v', 'a',
    'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't', 'r', 'i', 'b', 'u', 't', 'e',
    's', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'A', 'r', 'r', 'a', 'y' };

  static char_T c11_cv12[39] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'v', 'a',
    'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't', 'r', 'i', 'b', 'u', 't', 'e',
    's', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'A', 'r', 'r', 'a', 'y' };

  static char_T c11_cv17[39] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'v', 'a',
    'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't', 'r', 'i', 'b', 'u', 't', 'e',
    's', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'A', 'r', 'r', 'a', 'y' };

  static char_T c11_cv7[39] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'v', 'a', 'l',
    'i', 'd', 'a', 't', 'e', 'a', 't', 't', 'r', 'i', 'b', 'u', 't', 'e', 's',
    ':', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'A', 'r', 'r', 'a', 'y' };

  static char_T c11_b_cv1[22] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o',
    't', 'G', 'r', 'e', 'a', 't', 'e', 'r', 'E', 'q', 'u', 'a', 'l' };

  static char_T c11_cv11[22] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o',
    't', 'G', 'r', 'e', 'a', 't', 'e', 'r', 'E', 'q', 'u', 'a', 'l' };

  static char_T c11_b_cv5[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o',
    't', 'L', 'e', 's', 's', 'E', 'q', 'u', 'a', 'l' };

  static char_T c11_cv15[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o',
    't', 'L', 'e', 's', 's', 'E', 'q', 'u', 'a', 'l' };

  static char_T c11_b_cv[17] = { 'R', 'e', 'f', 'e', 'r', 'e', 'n', 'c', 'e',
    'L', 'o', 'c', 'a', 't', 'i', 'o', 'n' };

  static char_T c11_cv13[9] = { 'L', 'o', 'n', 'g', 'i', 't', 'u', 'd', 'e' };

  static char_T c11_cv18[9] = { 'L', 'o', 'n', 'g', 'i', 't', 'u', 'd', 'e' };

  static char_T c11_b_cv3[8] = { 'L', 'a', 't', 'i', 't', 'u', 'd', 'e' };

  static char_T c11_cv8[8] = { 'L', 'a', 't', 'i', 't', 'u', 'd', 'e' };

  static char_T c11_cv16[4] = { '-', '1', '8', '0' };

  static char_T c11_cv20[3] = { '1', '8', '0' };

  static char_T c11_cv6[3] = { '-', '9', '0' };

  static char_T c11_b_cv4[2] = { '>', '=' };

  static char_T c11_cv10[2] = { '9', '0' };

  static char_T c11_cv14[2] = { '>', '=' };

  static char_T c11_cv19[2] = { '<', '=' };

  static char_T c11_cv9[2] = { '<', '=' };

  emlrtStack c11_b_st;
  emlrtStack c11_st;
  const mxArray *c11_b_y = NULL;
  const mxArray *c11_c_y = NULL;
  const mxArray *c11_d_y = NULL;
  const mxArray *c11_e_y = NULL;
  const mxArray *c11_f_y = NULL;
  const mxArray *c11_g_y = NULL;
  const mxArray *c11_h_y = NULL;
  const mxArray *c11_i_y = NULL;
  const mxArray *c11_j_y = NULL;
  const mxArray *c11_k_y = NULL;
  const mxArray *c11_l_y = NULL;
  const mxArray *c11_m_y = NULL;
  const mxArray *c11_n_y = NULL;
  const mxArray *c11_o_y = NULL;
  const mxArray *c11_p_y = NULL;
  const mxArray *c11_q_y = NULL;
  const mxArray *c11_r_y = NULL;
  const mxArray *c11_s_y = NULL;
  const mxArray *c11_t_y = NULL;
  const mxArray *c11_u_y = NULL;
  const mxArray *c11_v_y = NULL;
  const mxArray *c11_w_y = NULL;
  const mxArray *c11_y = NULL;
  real_T c11_a;
  real_T c11_b_a;
  real_T c11_b_k;
  real_T c11_b_x;
  real_T c11_c_a;
  real_T c11_c_x;
  real_T c11_d_a;
  real_T c11_e_a;
  real_T c11_f_a;
  real_T c11_g_a;
  real_T c11_h_a;
  real_T c11_i_a;
  real_T c11_j_a;
  real_T c11_x;
  int32_T c11_i;
  int32_T c11_k;
  boolean_T c11_b;
  boolean_T c11_b1;
  boolean_T c11_b2;
  boolean_T c11_b_b;
  boolean_T c11_b_p;
  boolean_T c11_c_b;
  boolean_T c11_c_p;
  boolean_T c11_d_b;
  boolean_T c11_d_p;
  boolean_T c11_e_p;
  boolean_T c11_exitg1;
  boolean_T c11_p;
  (void)chartInstance;
  c11_st.prev = c11_sp;
  c11_st.tls = c11_sp->tls;
  c11_b_st.prev = &c11_st;
  c11_b_st.tls = c11_st.tls;
  c11_st.site = &c11_db_emlrtRSI;
  c11_b_st.site = &c11_gb_emlrtRSI;
  c11_p = true;
  c11_k = 0;
  c11_exitg1 = false;
  while ((!c11_exitg1) && (c11_k < 3)) {
    c11_b_k = 1.0 + (real_T)c11_k;
    c11_x = c11_val[(int32_T)c11_b_k - 1];
    c11_b_x = c11_x;
    c11_b_b = muDoubleScalarIsInf(c11_b_x);
    c11_b1 = !c11_b_b;
    c11_c_x = c11_x;
    c11_c_b = muDoubleScalarIsNaN(c11_c_x);
    c11_b2 = !c11_c_b;
    c11_d_b = (c11_b1 && c11_b2);
    if (c11_d_b) {
      c11_k++;
    } else {
      c11_p = false;
      c11_exitg1 = true;
    }
  }

  if (c11_p) {
    c11_b = true;
  } else {
    c11_b = false;
  }

  if (!c11_b) {
    c11_y = NULL;
    sf_mex_assign(&c11_y, sf_mex_create("y", c11_cv4, 10, 0U, 1U, 0U, 2, 1, 21),
                  false);
    c11_b_y = NULL;
    sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_cv5, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c11_c_y = NULL;
    sf_mex_assign(&c11_c_y, sf_mex_create("y", c11_b_cv, 10, 0U, 1U, 0U, 2, 1,
      17), false);
    sf_mex_call(&c11_b_st, &c11_emlrtMCI, "error", 0U, 2U, 14, c11_y, 14,
                sf_mex_call(&c11_b_st, NULL, "getString", 1U, 1U, 14,
      sf_mex_call(&c11_b_st, NULL, "message", 1U, 2U, 14, c11_b_y, 14, c11_c_y)));
  }

  c11_st.site = &c11_eb_emlrtRSI;
  c11_a = c11_val[0];
  c11_b_st.site = &c11_gb_emlrtRSI;
  c11_b_a = c11_a;
  c11_c_a = c11_b_a;
  c11_b_p = true;
  if (!(c11_c_a >= -90.0)) {
    c11_b_p = false;
  }

  if (!c11_b_p) {
    c11_d_y = NULL;
    sf_mex_assign(&c11_d_y, sf_mex_create("y", c11_b_cv1, 10, 0U, 1U, 0U, 2, 1,
      22), false);
    c11_e_y = NULL;
    sf_mex_assign(&c11_e_y, sf_mex_create("y", c11_b_cv2, 10, 0U, 1U, 0U, 2, 1,
      39), false);
    c11_f_y = NULL;
    sf_mex_assign(&c11_f_y, sf_mex_create("y", c11_b_cv3, 10, 0U, 1U, 0U, 2, 1,
      8), false);
    c11_g_y = NULL;
    sf_mex_assign(&c11_g_y, sf_mex_create("y", c11_b_cv4, 10, 0U, 1U, 0U, 2, 1,
      2), false);
    c11_i_y = NULL;
    sf_mex_assign(&c11_i_y, sf_mex_create("y", c11_cv6, 10, 0U, 1U, 0U, 2, 1, 3),
                  false);
    sf_mex_call(&c11_b_st, &c11_b_emlrtMCI, "error", 0U, 2U, 14, c11_d_y, 14,
                sf_mex_call(&c11_b_st, NULL, "getString", 1U, 1U, 14,
      sf_mex_call(&c11_b_st, NULL, "message", 1U, 4U, 14, c11_e_y, 14, c11_f_y,
                  14, c11_g_y, 14, c11_i_y)));
  }

  c11_b_st.site = &c11_gb_emlrtRSI;
  c11_d_a = c11_a;
  c11_e_a = c11_d_a;
  c11_c_p = true;
  if (!(c11_e_a <= 90.0)) {
    c11_c_p = false;
  }

  if (!c11_c_p) {
    c11_h_y = NULL;
    sf_mex_assign(&c11_h_y, sf_mex_create("y", c11_b_cv5, 10, 0U, 1U, 0U, 2, 1,
      19), false);
    c11_j_y = NULL;
    sf_mex_assign(&c11_j_y, sf_mex_create("y", c11_cv7, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    c11_k_y = NULL;
    sf_mex_assign(&c11_k_y, sf_mex_create("y", c11_cv8, 10, 0U, 1U, 0U, 2, 1, 8),
                  false);
    c11_l_y = NULL;
    sf_mex_assign(&c11_l_y, sf_mex_create("y", c11_cv9, 10, 0U, 1U, 0U, 2, 1, 2),
                  false);
    c11_m_y = NULL;
    sf_mex_assign(&c11_m_y, sf_mex_create("y", c11_cv10, 10, 0U, 1U, 0U, 2, 1, 2),
                  false);
    sf_mex_call(&c11_b_st, &c11_c_emlrtMCI, "error", 0U, 2U, 14, c11_h_y, 14,
                sf_mex_call(&c11_b_st, NULL, "getString", 1U, 1U, 14,
      sf_mex_call(&c11_b_st, NULL, "message", 1U, 4U, 14, c11_j_y, 14, c11_k_y,
                  14, c11_l_y, 14, c11_m_y)));
  }

  c11_st.site = &c11_fb_emlrtRSI;
  c11_f_a = c11_val[1];
  c11_b_st.site = &c11_gb_emlrtRSI;
  c11_g_a = c11_f_a;
  c11_h_a = c11_g_a;
  c11_d_p = true;
  if (!(c11_h_a >= -180.0)) {
    c11_d_p = false;
  }

  if (!c11_d_p) {
    c11_n_y = NULL;
    sf_mex_assign(&c11_n_y, sf_mex_create("y", c11_cv11, 10, 0U, 1U, 0U, 2, 1,
      22), false);
    c11_o_y = NULL;
    sf_mex_assign(&c11_o_y, sf_mex_create("y", c11_cv12, 10, 0U, 1U, 0U, 2, 1,
      39), false);
    c11_p_y = NULL;
    sf_mex_assign(&c11_p_y, sf_mex_create("y", c11_cv13, 10, 0U, 1U, 0U, 2, 1, 9),
                  false);
    c11_q_y = NULL;
    sf_mex_assign(&c11_q_y, sf_mex_create("y", c11_cv14, 10, 0U, 1U, 0U, 2, 1, 2),
                  false);
    c11_s_y = NULL;
    sf_mex_assign(&c11_s_y, sf_mex_create("y", c11_cv16, 10, 0U, 1U, 0U, 2, 1, 4),
                  false);
    sf_mex_call(&c11_b_st, &c11_b_emlrtMCI, "error", 0U, 2U, 14, c11_n_y, 14,
                sf_mex_call(&c11_b_st, NULL, "getString", 1U, 1U, 14,
      sf_mex_call(&c11_b_st, NULL, "message", 1U, 4U, 14, c11_o_y, 14, c11_p_y,
                  14, c11_q_y, 14, c11_s_y)));
  }

  c11_b_st.site = &c11_gb_emlrtRSI;
  c11_i_a = c11_f_a;
  c11_j_a = c11_i_a;
  c11_e_p = true;
  if (!(c11_j_a <= 180.0)) {
    c11_e_p = false;
  }

  if (!c11_e_p) {
    c11_r_y = NULL;
    sf_mex_assign(&c11_r_y, sf_mex_create("y", c11_cv15, 10, 0U, 1U, 0U, 2, 1,
      19), false);
    c11_t_y = NULL;
    sf_mex_assign(&c11_t_y, sf_mex_create("y", c11_cv17, 10, 0U, 1U, 0U, 2, 1,
      39), false);
    c11_u_y = NULL;
    sf_mex_assign(&c11_u_y, sf_mex_create("y", c11_cv18, 10, 0U, 1U, 0U, 2, 1, 9),
                  false);
    c11_v_y = NULL;
    sf_mex_assign(&c11_v_y, sf_mex_create("y", c11_cv19, 10, 0U, 1U, 0U, 2, 1, 2),
                  false);
    c11_w_y = NULL;
    sf_mex_assign(&c11_w_y, sf_mex_create("y", c11_cv20, 10, 0U, 1U, 0U, 2, 1, 3),
                  false);
    sf_mex_call(&c11_b_st, &c11_c_emlrtMCI, "error", 0U, 2U, 14, c11_r_y, 14,
                sf_mex_call(&c11_b_st, NULL, "getString", 1U, 1U, 14,
      sf_mex_call(&c11_b_st, NULL, "message", 1U, 4U, 14, c11_t_y, 14, c11_u_y,
                  14, c11_v_y, 14, c11_w_y)));
  }

  for (c11_i = 0; c11_i < 3; c11_i++) {
    c11_obj->ReferenceLocation[c11_i] = c11_val[c11_i];
  }
}

static void c11_AsyncMARGGPSFuserBase_setState
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance, const emlrtStack *c11_sp,
   c11_insfilterAsync *c11_obj, real_T c11_val[28])
{
  static char_T c11_b_cv[5] = { 'S', 't', 'a', 't', 'e' };

  static char_T c11_b_cv1[5] = { 'S', 't', 'a', 't', 'e' };

  emlrtStack c11_b_st;
  emlrtStack c11_st;
  const mxArray *c11_b_y = NULL;
  const mxArray *c11_c_y = NULL;
  const mxArray *c11_d_y = NULL;
  const mxArray *c11_e_y = NULL;
  const mxArray *c11_f_y = NULL;
  const mxArray *c11_y = NULL;
  real_T c11_b_k;
  real_T c11_b_x;
  real_T c11_c_x;
  real_T c11_d_k;
  real_T c11_d_x;
  real_T c11_e_x;
  real_T c11_magX;
  real_T c11_magY;
  real_T c11_x;
  int32_T c11_c_k;
  int32_T c11_i;
  int32_T c11_k;
  boolean_T c11_b;
  boolean_T c11_b1;
  boolean_T c11_b2;
  boolean_T c11_b3;
  boolean_T c11_b_b;
  boolean_T c11_b_p;
  boolean_T c11_c_b;
  boolean_T c11_c_p;
  boolean_T c11_d_b;
  boolean_T c11_e_b;
  boolean_T c11_exitg1;
  boolean_T c11_p;
  (void)chartInstance;
  c11_st.prev = c11_sp;
  c11_st.tls = c11_sp->tls;
  c11_b_st.prev = &c11_st;
  c11_b_st.tls = c11_st.tls;
  c11_st.site = &c11_ib_emlrtRSI;
  c11_b_st.site = &c11_gb_emlrtRSI;
  c11_p = true;
  c11_k = 0;
  c11_exitg1 = false;
  while ((!c11_exitg1) && (c11_k < 28)) {
    c11_b_k = 1.0 + (real_T)c11_k;
    c11_x = c11_val[(int32_T)c11_b_k - 1];
    c11_b_x = c11_x;
    c11_b_b = muDoubleScalarIsInf(c11_b_x);
    c11_b1 = !c11_b_b;
    c11_c_x = c11_x;
    c11_c_b = muDoubleScalarIsNaN(c11_c_x);
    c11_b2 = !c11_c_b;
    c11_d_b = (c11_b1 && c11_b2);
    if (c11_d_b) {
      c11_k++;
    } else {
      c11_p = false;
      c11_exitg1 = true;
    }
  }

  if (c11_p) {
    c11_b = true;
  } else {
    c11_b = false;
  }

  if (!c11_b) {
    c11_y = NULL;
    sf_mex_assign(&c11_y, sf_mex_create("y", c11_cv4, 10, 0U, 1U, 0U, 2, 1, 21),
                  false);
    c11_b_y = NULL;
    sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_cv5, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c11_c_y = NULL;
    sf_mex_assign(&c11_c_y, sf_mex_create("y", c11_b_cv, 10, 0U, 1U, 0U, 2, 1, 5),
                  false);
    sf_mex_call(&c11_b_st, &c11_emlrtMCI, "error", 0U, 2U, 14, c11_y, 14,
                sf_mex_call(&c11_b_st, NULL, "getString", 1U, 1U, 14,
      sf_mex_call(&c11_b_st, NULL, "message", 1U, 2U, 14, c11_b_y, 14, c11_c_y)));
  }

  c11_b_st.site = &c11_gb_emlrtRSI;
  c11_b_p = true;
  c11_c_k = 0;
  c11_exitg1 = false;
  while ((!c11_exitg1) && (c11_c_k < 28)) {
    c11_d_k = 1.0 + (real_T)c11_c_k;
    c11_d_x = c11_val[(int32_T)c11_d_k - 1];
    c11_e_x = c11_d_x;
    c11_e_b = muDoubleScalarIsNaN(c11_e_x);
    c11_c_p = !c11_e_b;
    if (c11_c_p) {
      c11_c_k++;
    } else {
      c11_b_p = false;
      c11_exitg1 = true;
    }
  }

  if (c11_b_p) {
    c11_b3 = true;
  } else {
    c11_b3 = false;
  }

  if (!c11_b3) {
    c11_d_y = NULL;
    sf_mex_assign(&c11_d_y, sf_mex_create("y", c11_cv, 10, 0U, 1U, 0U, 2, 1, 21),
                  false);
    c11_e_y = NULL;
    sf_mex_assign(&c11_e_y, sf_mex_create("y", c11_cv1, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c11_f_y = NULL;
    sf_mex_assign(&c11_f_y, sf_mex_create("y", c11_b_cv1, 10, 0U, 1U, 0U, 2, 1,
      5), false);
    sf_mex_call(&c11_b_st, &c11_d_emlrtMCI, "error", 0U, 2U, 14, c11_d_y, 14,
                sf_mex_call(&c11_b_st, NULL, "getString", 1U, 1U, 14,
      sf_mex_call(&c11_b_st, NULL, "message", 1U, 2U, 14, c11_e_y, 14, c11_f_y)));
  }

  c11_magX = c11_val[22];
  c11_magY = c11_val[23];
  c11_val[22] = c11_magX;
  c11_val[23] = c11_magY;
  for (c11_i = 0; c11_i < 28; c11_i++) {
    c11_obj->pState[c11_i] = c11_val[c11_i];
  }
}

static void c11_AsyncMARGGPSFuserBase_setStateCovariance
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance, const emlrtStack *c11_sp,
   c11_insfilterAsync *c11_obj, real_T c11_val[784])
{
  static char_T c11_b_cv[15] = { 'S', 't', 'a', 't', 'e', 'C', 'o', 'v', 'a',
    'r', 'i', 'a', 'n', 'c', 'e' };

  static char_T c11_b_cv1[15] = { 'S', 't', 'a', 't', 'e', 'C', 'o', 'v', 'a',
    'r', 'i', 'a', 'n', 'c', 'e' };

  emlrtStack c11_b_st;
  emlrtStack c11_st;
  const mxArray *c11_b_y = NULL;
  const mxArray *c11_c_y = NULL;
  const mxArray *c11_d_y = NULL;
  const mxArray *c11_e_y = NULL;
  const mxArray *c11_f_y = NULL;
  const mxArray *c11_y = NULL;
  real_T c11_b_k;
  real_T c11_b_x;
  real_T c11_c_x;
  real_T c11_d_k;
  real_T c11_d_x;
  real_T c11_e_x;
  real_T c11_x;
  int32_T c11_c_k;
  int32_T c11_i;
  int32_T c11_k;
  boolean_T c11_b;
  boolean_T c11_b1;
  boolean_T c11_b2;
  boolean_T c11_b3;
  boolean_T c11_b_b;
  boolean_T c11_b_p;
  boolean_T c11_c_b;
  boolean_T c11_c_p;
  boolean_T c11_d_b;
  boolean_T c11_e_b;
  boolean_T c11_exitg1;
  boolean_T c11_p;
  (void)chartInstance;
  c11_st.prev = c11_sp;
  c11_st.tls = c11_sp->tls;
  c11_b_st.prev = &c11_st;
  c11_b_st.tls = c11_st.tls;
  c11_st.site = &c11_kb_emlrtRSI;
  c11_b_st.site = &c11_gb_emlrtRSI;
  c11_p = true;
  c11_k = 0;
  c11_exitg1 = false;
  while ((!c11_exitg1) && (c11_k < 784)) {
    c11_b_k = 1.0 + (real_T)c11_k;
    c11_x = c11_val[(int32_T)c11_b_k - 1];
    c11_b_x = c11_x;
    c11_b_b = muDoubleScalarIsInf(c11_b_x);
    c11_b1 = !c11_b_b;
    c11_c_x = c11_x;
    c11_c_b = muDoubleScalarIsNaN(c11_c_x);
    c11_b2 = !c11_c_b;
    c11_d_b = (c11_b1 && c11_b2);
    if (c11_d_b) {
      c11_k++;
    } else {
      c11_p = false;
      c11_exitg1 = true;
    }
  }

  if (c11_p) {
    c11_b = true;
  } else {
    c11_b = false;
  }

  if (!c11_b) {
    c11_y = NULL;
    sf_mex_assign(&c11_y, sf_mex_create("y", c11_cv4, 10, 0U, 1U, 0U, 2, 1, 21),
                  false);
    c11_b_y = NULL;
    sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_cv5, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c11_c_y = NULL;
    sf_mex_assign(&c11_c_y, sf_mex_create("y", c11_b_cv, 10, 0U, 1U, 0U, 2, 1,
      15), false);
    sf_mex_call(&c11_b_st, &c11_emlrtMCI, "error", 0U, 2U, 14, c11_y, 14,
                sf_mex_call(&c11_b_st, NULL, "getString", 1U, 1U, 14,
      sf_mex_call(&c11_b_st, NULL, "message", 1U, 2U, 14, c11_b_y, 14, c11_c_y)));
  }

  c11_b_st.site = &c11_gb_emlrtRSI;
  c11_b_p = true;
  c11_c_k = 0;
  c11_exitg1 = false;
  while ((!c11_exitg1) && (c11_c_k < 784)) {
    c11_d_k = 1.0 + (real_T)c11_c_k;
    c11_d_x = c11_val[(int32_T)c11_d_k - 1];
    c11_e_x = c11_d_x;
    c11_e_b = muDoubleScalarIsNaN(c11_e_x);
    c11_c_p = !c11_e_b;
    if (c11_c_p) {
      c11_c_k++;
    } else {
      c11_b_p = false;
      c11_exitg1 = true;
    }
  }

  if (c11_b_p) {
    c11_b3 = true;
  } else {
    c11_b3 = false;
  }

  if (!c11_b3) {
    c11_d_y = NULL;
    sf_mex_assign(&c11_d_y, sf_mex_create("y", c11_cv, 10, 0U, 1U, 0U, 2, 1, 21),
                  false);
    c11_e_y = NULL;
    sf_mex_assign(&c11_e_y, sf_mex_create("y", c11_cv1, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c11_f_y = NULL;
    sf_mex_assign(&c11_f_y, sf_mex_create("y", c11_b_cv1, 10, 0U, 1U, 0U, 2, 1,
      15), false);
    sf_mex_call(&c11_b_st, &c11_d_emlrtMCI, "error", 0U, 2U, 14, c11_d_y, 14,
                sf_mex_call(&c11_b_st, NULL, "getString", 1U, 1U, 14,
      sf_mex_call(&c11_b_st, NULL, "message", 1U, 2U, 14, c11_e_y, 14, c11_f_y)));
  }

  for (c11_i = 0; c11_i < 784; c11_i++) {
    c11_obj->pStateCovariance[c11_i] = c11_val[c11_i];
  }
}

static void c11_AsyncMARGGPSFuserBase_set_QuaternionNoise
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance, const emlrtStack *c11_sp,
   c11_insfilterAsync *c11_obj, real_T c11_val[4])
{
  static char_T c11_b_cv[15] = { 'Q', 'u', 'a', 't', 'e', 'r', 'n', 'i', 'o',
    'n', 'N', 'o', 'i', 's', 'e' };

  static char_T c11_b_cv1[15] = { 'Q', 'u', 'a', 't', 'e', 'r', 'n', 'i', 'o',
    'n', 'N', 'o', 'i', 's', 'e' };

  static char_T c11_b_cv2[15] = { 'Q', 'u', 'a', 't', 'e', 'r', 'n', 'i', 'o',
    'n', 'N', 'o', 'i', 's', 'e' };

  emlrtStack c11_b_st;
  emlrtStack c11_st;
  const mxArray *c11_b_y = NULL;
  const mxArray *c11_c_y = NULL;
  const mxArray *c11_d_y = NULL;
  const mxArray *c11_e_y = NULL;
  const mxArray *c11_f_y = NULL;
  const mxArray *c11_g_y = NULL;
  const mxArray *c11_h_y = NULL;
  const mxArray *c11_i_y = NULL;
  const mxArray *c11_y = NULL;
  real_T c11_b_k;
  real_T c11_b_x;
  real_T c11_c_x;
  real_T c11_d_k;
  real_T c11_d_x;
  real_T c11_e_x;
  real_T c11_f_k;
  real_T c11_f_x;
  real_T c11_x;
  int32_T c11_c_k;
  int32_T c11_e_k;
  int32_T c11_i;
  int32_T c11_k;
  boolean_T c11_b;
  boolean_T c11_b1;
  boolean_T c11_b2;
  boolean_T c11_b3;
  boolean_T c11_b4;
  boolean_T c11_b_b;
  boolean_T c11_b_p;
  boolean_T c11_c_b;
  boolean_T c11_c_p;
  boolean_T c11_d_b;
  boolean_T c11_d_p;
  boolean_T c11_e_b;
  boolean_T c11_e_p;
  boolean_T c11_exitg1;
  boolean_T c11_p;
  (void)chartInstance;
  c11_st.prev = c11_sp;
  c11_st.tls = c11_sp->tls;
  c11_b_st.prev = &c11_st;
  c11_b_st.tls = c11_st.tls;
  c11_st.site = &c11_lb_emlrtRSI;
  c11_b_st.site = &c11_gb_emlrtRSI;
  c11_p = true;
  c11_k = 0;
  c11_exitg1 = false;
  while ((!c11_exitg1) && (c11_k < 4)) {
    c11_b_k = 1.0 + (real_T)c11_k;
    c11_x = c11_val[(int32_T)c11_b_k - 1];
    c11_b_x = c11_x;
    c11_b_b = muDoubleScalarIsInf(c11_b_x);
    c11_b1 = !c11_b_b;
    c11_c_x = c11_x;
    c11_c_b = muDoubleScalarIsNaN(c11_c_x);
    c11_b2 = !c11_c_b;
    c11_d_b = (c11_b1 && c11_b2);
    if (c11_d_b) {
      c11_k++;
    } else {
      c11_p = false;
      c11_exitg1 = true;
    }
  }

  if (c11_p) {
    c11_b = true;
  } else {
    c11_b = false;
  }

  if (!c11_b) {
    c11_y = NULL;
    sf_mex_assign(&c11_y, sf_mex_create("y", c11_cv4, 10, 0U, 1U, 0U, 2, 1, 21),
                  false);
    c11_b_y = NULL;
    sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_cv5, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c11_c_y = NULL;
    sf_mex_assign(&c11_c_y, sf_mex_create("y", c11_b_cv, 10, 0U, 1U, 0U, 2, 1,
      15), false);
    sf_mex_call(&c11_b_st, &c11_emlrtMCI, "error", 0U, 2U, 14, c11_y, 14,
                sf_mex_call(&c11_b_st, NULL, "getString", 1U, 1U, 14,
      sf_mex_call(&c11_b_st, NULL, "message", 1U, 2U, 14, c11_b_y, 14, c11_c_y)));
  }

  c11_b_st.site = &c11_gb_emlrtRSI;
  c11_b_p = true;
  c11_c_k = 0;
  c11_exitg1 = false;
  while ((!c11_exitg1) && (c11_c_k < 4)) {
    c11_d_k = 1.0 + (real_T)c11_c_k;
    c11_d_x = c11_val[(int32_T)c11_d_k - 1];
    c11_c_p = !(c11_d_x <= 0.0);
    if (c11_c_p) {
      c11_c_k++;
    } else {
      c11_b_p = false;
      c11_exitg1 = true;
    }
  }

  if (c11_b_p) {
    c11_b3 = true;
  } else {
    c11_b3 = false;
  }

  if (!c11_b3) {
    c11_d_y = NULL;
    sf_mex_assign(&c11_d_y, sf_mex_create("y", c11_cv2, 10, 0U, 1U, 0U, 2, 1, 23),
                  false);
    c11_e_y = NULL;
    sf_mex_assign(&c11_e_y, sf_mex_create("y", c11_cv3, 10, 0U, 1U, 0U, 2, 1, 48),
                  false);
    c11_f_y = NULL;
    sf_mex_assign(&c11_f_y, sf_mex_create("y", c11_b_cv1, 10, 0U, 1U, 0U, 2, 1,
      15), false);
    sf_mex_call(&c11_b_st, &c11_e_emlrtMCI, "error", 0U, 2U, 14, c11_d_y, 14,
                sf_mex_call(&c11_b_st, NULL, "getString", 1U, 1U, 14,
      sf_mex_call(&c11_b_st, NULL, "message", 1U, 2U, 14, c11_e_y, 14, c11_f_y)));
  }

  c11_b_st.site = &c11_gb_emlrtRSI;
  c11_d_p = true;
  c11_e_k = 0;
  c11_exitg1 = false;
  while ((!c11_exitg1) && (c11_e_k < 4)) {
    c11_f_k = 1.0 + (real_T)c11_e_k;
    c11_e_x = c11_val[(int32_T)c11_f_k - 1];
    c11_f_x = c11_e_x;
    c11_e_b = muDoubleScalarIsNaN(c11_f_x);
    c11_e_p = !c11_e_b;
    if (c11_e_p) {
      c11_e_k++;
    } else {
      c11_d_p = false;
      c11_exitg1 = true;
    }
  }

  if (c11_d_p) {
    c11_b4 = true;
  } else {
    c11_b4 = false;
  }

  if (!c11_b4) {
    c11_g_y = NULL;
    sf_mex_assign(&c11_g_y, sf_mex_create("y", c11_cv, 10, 0U, 1U, 0U, 2, 1, 21),
                  false);
    c11_h_y = NULL;
    sf_mex_assign(&c11_h_y, sf_mex_create("y", c11_cv1, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c11_i_y = NULL;
    sf_mex_assign(&c11_i_y, sf_mex_create("y", c11_b_cv2, 10, 0U, 1U, 0U, 2, 1,
      15), false);
    sf_mex_call(&c11_b_st, &c11_d_emlrtMCI, "error", 0U, 2U, 14, c11_g_y, 14,
                sf_mex_call(&c11_b_st, NULL, "getString", 1U, 1U, 14,
      sf_mex_call(&c11_b_st, NULL, "message", 1U, 2U, 14, c11_h_y, 14, c11_i_y)));
  }

  for (c11_i = 0; c11_i < 4; c11_i++) {
    c11_obj->QuaternionNoise[c11_i] = c11_val[c11_i];
  }
}

static void c11_AsyncMARGGPSFuserBase_set_AngularVelocityNoise
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance, const emlrtStack *c11_sp,
   c11_insfilterAsync *c11_obj, real_T c11_val[3])
{
  static char_T c11_b_cv[20] = { 'A', 'n', 'g', 'u', 'l', 'a', 'r', 'V', 'e',
    'l', 'o', 'c', 'i', 't', 'y', 'N', 'o', 'i', 's', 'e' };

  static char_T c11_b_cv1[20] = { 'A', 'n', 'g', 'u', 'l', 'a', 'r', 'V', 'e',
    'l', 'o', 'c', 'i', 't', 'y', 'N', 'o', 'i', 's', 'e' };

  static char_T c11_b_cv2[20] = { 'A', 'n', 'g', 'u', 'l', 'a', 'r', 'V', 'e',
    'l', 'o', 'c', 'i', 't', 'y', 'N', 'o', 'i', 's', 'e' };

  emlrtStack c11_b_st;
  emlrtStack c11_st;
  const mxArray *c11_b_y = NULL;
  const mxArray *c11_c_y = NULL;
  const mxArray *c11_d_y = NULL;
  const mxArray *c11_e_y = NULL;
  const mxArray *c11_f_y = NULL;
  const mxArray *c11_g_y = NULL;
  const mxArray *c11_h_y = NULL;
  const mxArray *c11_i_y = NULL;
  const mxArray *c11_y = NULL;
  real_T c11_b_k;
  real_T c11_b_x;
  real_T c11_c_x;
  real_T c11_d_k;
  real_T c11_d_x;
  real_T c11_e_x;
  real_T c11_f_k;
  real_T c11_f_x;
  real_T c11_x;
  int32_T c11_c_k;
  int32_T c11_e_k;
  int32_T c11_i;
  int32_T c11_k;
  boolean_T c11_b;
  boolean_T c11_b1;
  boolean_T c11_b2;
  boolean_T c11_b3;
  boolean_T c11_b4;
  boolean_T c11_b_b;
  boolean_T c11_b_p;
  boolean_T c11_c_b;
  boolean_T c11_c_p;
  boolean_T c11_d_b;
  boolean_T c11_d_p;
  boolean_T c11_e_b;
  boolean_T c11_e_p;
  boolean_T c11_exitg1;
  boolean_T c11_p;
  (void)chartInstance;
  c11_st.prev = c11_sp;
  c11_st.tls = c11_sp->tls;
  c11_b_st.prev = &c11_st;
  c11_b_st.tls = c11_st.tls;
  c11_st.site = &c11_mb_emlrtRSI;
  c11_b_st.site = &c11_gb_emlrtRSI;
  c11_p = true;
  c11_k = 0;
  c11_exitg1 = false;
  while ((!c11_exitg1) && (c11_k < 3)) {
    c11_b_k = 1.0 + (real_T)c11_k;
    c11_x = c11_val[(int32_T)c11_b_k - 1];
    c11_b_x = c11_x;
    c11_b_b = muDoubleScalarIsInf(c11_b_x);
    c11_b1 = !c11_b_b;
    c11_c_x = c11_x;
    c11_c_b = muDoubleScalarIsNaN(c11_c_x);
    c11_b2 = !c11_c_b;
    c11_d_b = (c11_b1 && c11_b2);
    if (c11_d_b) {
      c11_k++;
    } else {
      c11_p = false;
      c11_exitg1 = true;
    }
  }

  if (c11_p) {
    c11_b = true;
  } else {
    c11_b = false;
  }

  if (!c11_b) {
    c11_y = NULL;
    sf_mex_assign(&c11_y, sf_mex_create("y", c11_cv4, 10, 0U, 1U, 0U, 2, 1, 21),
                  false);
    c11_b_y = NULL;
    sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_cv5, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c11_c_y = NULL;
    sf_mex_assign(&c11_c_y, sf_mex_create("y", c11_b_cv, 10, 0U, 1U, 0U, 2, 1,
      20), false);
    sf_mex_call(&c11_b_st, &c11_emlrtMCI, "error", 0U, 2U, 14, c11_y, 14,
                sf_mex_call(&c11_b_st, NULL, "getString", 1U, 1U, 14,
      sf_mex_call(&c11_b_st, NULL, "message", 1U, 2U, 14, c11_b_y, 14, c11_c_y)));
  }

  c11_b_st.site = &c11_gb_emlrtRSI;
  c11_b_p = true;
  c11_c_k = 0;
  c11_exitg1 = false;
  while ((!c11_exitg1) && (c11_c_k < 3)) {
    c11_d_k = 1.0 + (real_T)c11_c_k;
    c11_d_x = c11_val[(int32_T)c11_d_k - 1];
    c11_c_p = !(c11_d_x <= 0.0);
    if (c11_c_p) {
      c11_c_k++;
    } else {
      c11_b_p = false;
      c11_exitg1 = true;
    }
  }

  if (c11_b_p) {
    c11_b3 = true;
  } else {
    c11_b3 = false;
  }

  if (!c11_b3) {
    c11_d_y = NULL;
    sf_mex_assign(&c11_d_y, sf_mex_create("y", c11_cv2, 10, 0U, 1U, 0U, 2, 1, 23),
                  false);
    c11_e_y = NULL;
    sf_mex_assign(&c11_e_y, sf_mex_create("y", c11_cv3, 10, 0U, 1U, 0U, 2, 1, 48),
                  false);
    c11_f_y = NULL;
    sf_mex_assign(&c11_f_y, sf_mex_create("y", c11_b_cv1, 10, 0U, 1U, 0U, 2, 1,
      20), false);
    sf_mex_call(&c11_b_st, &c11_e_emlrtMCI, "error", 0U, 2U, 14, c11_d_y, 14,
                sf_mex_call(&c11_b_st, NULL, "getString", 1U, 1U, 14,
      sf_mex_call(&c11_b_st, NULL, "message", 1U, 2U, 14, c11_e_y, 14, c11_f_y)));
  }

  c11_b_st.site = &c11_gb_emlrtRSI;
  c11_d_p = true;
  c11_e_k = 0;
  c11_exitg1 = false;
  while ((!c11_exitg1) && (c11_e_k < 3)) {
    c11_f_k = 1.0 + (real_T)c11_e_k;
    c11_e_x = c11_val[(int32_T)c11_f_k - 1];
    c11_f_x = c11_e_x;
    c11_e_b = muDoubleScalarIsNaN(c11_f_x);
    c11_e_p = !c11_e_b;
    if (c11_e_p) {
      c11_e_k++;
    } else {
      c11_d_p = false;
      c11_exitg1 = true;
    }
  }

  if (c11_d_p) {
    c11_b4 = true;
  } else {
    c11_b4 = false;
  }

  if (!c11_b4) {
    c11_g_y = NULL;
    sf_mex_assign(&c11_g_y, sf_mex_create("y", c11_cv, 10, 0U, 1U, 0U, 2, 1, 21),
                  false);
    c11_h_y = NULL;
    sf_mex_assign(&c11_h_y, sf_mex_create("y", c11_cv1, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c11_i_y = NULL;
    sf_mex_assign(&c11_i_y, sf_mex_create("y", c11_b_cv2, 10, 0U, 1U, 0U, 2, 1,
      20), false);
    sf_mex_call(&c11_b_st, &c11_d_emlrtMCI, "error", 0U, 2U, 14, c11_g_y, 14,
                sf_mex_call(&c11_b_st, NULL, "getString", 1U, 1U, 14,
      sf_mex_call(&c11_b_st, NULL, "message", 1U, 2U, 14, c11_h_y, 14, c11_i_y)));
  }

  for (c11_i = 0; c11_i < 3; c11_i++) {
    c11_obj->AngularVelocityNoise[c11_i] = c11_val[c11_i];
  }
}

static void c11_AsyncMARGGPSFuserBase_set_PositionNoise
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance, const emlrtStack *c11_sp,
   c11_insfilterAsync *c11_obj, real_T c11_val[3])
{
  static char_T c11_b_cv[13] = { 'P', 'o', 's', 'i', 't', 'i', 'o', 'n', 'N',
    'o', 'i', 's', 'e' };

  static char_T c11_b_cv1[13] = { 'P', 'o', 's', 'i', 't', 'i', 'o', 'n', 'N',
    'o', 'i', 's', 'e' };

  static char_T c11_b_cv2[13] = { 'P', 'o', 's', 'i', 't', 'i', 'o', 'n', 'N',
    'o', 'i', 's', 'e' };

  emlrtStack c11_b_st;
  emlrtStack c11_st;
  const mxArray *c11_b_y = NULL;
  const mxArray *c11_c_y = NULL;
  const mxArray *c11_d_y = NULL;
  const mxArray *c11_e_y = NULL;
  const mxArray *c11_f_y = NULL;
  const mxArray *c11_g_y = NULL;
  const mxArray *c11_h_y = NULL;
  const mxArray *c11_i_y = NULL;
  const mxArray *c11_y = NULL;
  real_T c11_b_k;
  real_T c11_b_x;
  real_T c11_c_x;
  real_T c11_d_k;
  real_T c11_d_x;
  real_T c11_e_x;
  real_T c11_f_k;
  real_T c11_f_x;
  real_T c11_x;
  int32_T c11_c_k;
  int32_T c11_e_k;
  int32_T c11_i;
  int32_T c11_k;
  boolean_T c11_b;
  boolean_T c11_b1;
  boolean_T c11_b2;
  boolean_T c11_b3;
  boolean_T c11_b4;
  boolean_T c11_b_b;
  boolean_T c11_b_p;
  boolean_T c11_c_b;
  boolean_T c11_c_p;
  boolean_T c11_d_b;
  boolean_T c11_d_p;
  boolean_T c11_e_b;
  boolean_T c11_e_p;
  boolean_T c11_exitg1;
  boolean_T c11_p;
  (void)chartInstance;
  c11_st.prev = c11_sp;
  c11_st.tls = c11_sp->tls;
  c11_b_st.prev = &c11_st;
  c11_b_st.tls = c11_st.tls;
  c11_st.site = &c11_nb_emlrtRSI;
  c11_b_st.site = &c11_gb_emlrtRSI;
  c11_p = true;
  c11_k = 0;
  c11_exitg1 = false;
  while ((!c11_exitg1) && (c11_k < 3)) {
    c11_b_k = 1.0 + (real_T)c11_k;
    c11_x = c11_val[(int32_T)c11_b_k - 1];
    c11_b_x = c11_x;
    c11_b_b = muDoubleScalarIsInf(c11_b_x);
    c11_b1 = !c11_b_b;
    c11_c_x = c11_x;
    c11_c_b = muDoubleScalarIsNaN(c11_c_x);
    c11_b2 = !c11_c_b;
    c11_d_b = (c11_b1 && c11_b2);
    if (c11_d_b) {
      c11_k++;
    } else {
      c11_p = false;
      c11_exitg1 = true;
    }
  }

  if (c11_p) {
    c11_b = true;
  } else {
    c11_b = false;
  }

  if (!c11_b) {
    c11_y = NULL;
    sf_mex_assign(&c11_y, sf_mex_create("y", c11_cv4, 10, 0U, 1U, 0U, 2, 1, 21),
                  false);
    c11_b_y = NULL;
    sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_cv5, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c11_c_y = NULL;
    sf_mex_assign(&c11_c_y, sf_mex_create("y", c11_b_cv, 10, 0U, 1U, 0U, 2, 1,
      13), false);
    sf_mex_call(&c11_b_st, &c11_emlrtMCI, "error", 0U, 2U, 14, c11_y, 14,
                sf_mex_call(&c11_b_st, NULL, "getString", 1U, 1U, 14,
      sf_mex_call(&c11_b_st, NULL, "message", 1U, 2U, 14, c11_b_y, 14, c11_c_y)));
  }

  c11_b_st.site = &c11_gb_emlrtRSI;
  c11_b_p = true;
  c11_c_k = 0;
  c11_exitg1 = false;
  while ((!c11_exitg1) && (c11_c_k < 3)) {
    c11_d_k = 1.0 + (real_T)c11_c_k;
    c11_d_x = c11_val[(int32_T)c11_d_k - 1];
    c11_c_p = !(c11_d_x <= 0.0);
    if (c11_c_p) {
      c11_c_k++;
    } else {
      c11_b_p = false;
      c11_exitg1 = true;
    }
  }

  if (c11_b_p) {
    c11_b3 = true;
  } else {
    c11_b3 = false;
  }

  if (!c11_b3) {
    c11_d_y = NULL;
    sf_mex_assign(&c11_d_y, sf_mex_create("y", c11_cv2, 10, 0U, 1U, 0U, 2, 1, 23),
                  false);
    c11_e_y = NULL;
    sf_mex_assign(&c11_e_y, sf_mex_create("y", c11_cv3, 10, 0U, 1U, 0U, 2, 1, 48),
                  false);
    c11_f_y = NULL;
    sf_mex_assign(&c11_f_y, sf_mex_create("y", c11_b_cv1, 10, 0U, 1U, 0U, 2, 1,
      13), false);
    sf_mex_call(&c11_b_st, &c11_e_emlrtMCI, "error", 0U, 2U, 14, c11_d_y, 14,
                sf_mex_call(&c11_b_st, NULL, "getString", 1U, 1U, 14,
      sf_mex_call(&c11_b_st, NULL, "message", 1U, 2U, 14, c11_e_y, 14, c11_f_y)));
  }

  c11_b_st.site = &c11_gb_emlrtRSI;
  c11_d_p = true;
  c11_e_k = 0;
  c11_exitg1 = false;
  while ((!c11_exitg1) && (c11_e_k < 3)) {
    c11_f_k = 1.0 + (real_T)c11_e_k;
    c11_e_x = c11_val[(int32_T)c11_f_k - 1];
    c11_f_x = c11_e_x;
    c11_e_b = muDoubleScalarIsNaN(c11_f_x);
    c11_e_p = !c11_e_b;
    if (c11_e_p) {
      c11_e_k++;
    } else {
      c11_d_p = false;
      c11_exitg1 = true;
    }
  }

  if (c11_d_p) {
    c11_b4 = true;
  } else {
    c11_b4 = false;
  }

  if (!c11_b4) {
    c11_g_y = NULL;
    sf_mex_assign(&c11_g_y, sf_mex_create("y", c11_cv, 10, 0U, 1U, 0U, 2, 1, 21),
                  false);
    c11_h_y = NULL;
    sf_mex_assign(&c11_h_y, sf_mex_create("y", c11_cv1, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c11_i_y = NULL;
    sf_mex_assign(&c11_i_y, sf_mex_create("y", c11_b_cv2, 10, 0U, 1U, 0U, 2, 1,
      13), false);
    sf_mex_call(&c11_b_st, &c11_d_emlrtMCI, "error", 0U, 2U, 14, c11_g_y, 14,
                sf_mex_call(&c11_b_st, NULL, "getString", 1U, 1U, 14,
      sf_mex_call(&c11_b_st, NULL, "message", 1U, 2U, 14, c11_h_y, 14, c11_i_y)));
  }

  for (c11_i = 0; c11_i < 3; c11_i++) {
    c11_obj->PositionNoise[c11_i] = c11_val[c11_i];
  }
}

static void c11_AsyncMARGGPSFuserBase_set_VelocityNoise
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance, const emlrtStack *c11_sp,
   c11_insfilterAsync *c11_obj, real_T c11_val[3])
{
  static char_T c11_b_cv[13] = { 'V', 'e', 'l', 'o', 'c', 'i', 't', 'y', 'N',
    'o', 'i', 's', 'e' };

  static char_T c11_b_cv1[13] = { 'V', 'e', 'l', 'o', 'c', 'i', 't', 'y', 'N',
    'o', 'i', 's', 'e' };

  static char_T c11_b_cv2[13] = { 'V', 'e', 'l', 'o', 'c', 'i', 't', 'y', 'N',
    'o', 'i', 's', 'e' };

  emlrtStack c11_b_st;
  emlrtStack c11_st;
  const mxArray *c11_b_y = NULL;
  const mxArray *c11_c_y = NULL;
  const mxArray *c11_d_y = NULL;
  const mxArray *c11_e_y = NULL;
  const mxArray *c11_f_y = NULL;
  const mxArray *c11_g_y = NULL;
  const mxArray *c11_h_y = NULL;
  const mxArray *c11_i_y = NULL;
  const mxArray *c11_y = NULL;
  real_T c11_b_k;
  real_T c11_b_x;
  real_T c11_c_x;
  real_T c11_d_k;
  real_T c11_d_x;
  real_T c11_e_x;
  real_T c11_f_k;
  real_T c11_f_x;
  real_T c11_x;
  int32_T c11_c_k;
  int32_T c11_e_k;
  int32_T c11_i;
  int32_T c11_k;
  boolean_T c11_b;
  boolean_T c11_b1;
  boolean_T c11_b2;
  boolean_T c11_b3;
  boolean_T c11_b4;
  boolean_T c11_b_b;
  boolean_T c11_b_p;
  boolean_T c11_c_b;
  boolean_T c11_c_p;
  boolean_T c11_d_b;
  boolean_T c11_d_p;
  boolean_T c11_e_b;
  boolean_T c11_e_p;
  boolean_T c11_exitg1;
  boolean_T c11_p;
  (void)chartInstance;
  c11_st.prev = c11_sp;
  c11_st.tls = c11_sp->tls;
  c11_b_st.prev = &c11_st;
  c11_b_st.tls = c11_st.tls;
  c11_st.site = &c11_ob_emlrtRSI;
  c11_b_st.site = &c11_gb_emlrtRSI;
  c11_p = true;
  c11_k = 0;
  c11_exitg1 = false;
  while ((!c11_exitg1) && (c11_k < 3)) {
    c11_b_k = 1.0 + (real_T)c11_k;
    c11_x = c11_val[(int32_T)c11_b_k - 1];
    c11_b_x = c11_x;
    c11_b_b = muDoubleScalarIsInf(c11_b_x);
    c11_b1 = !c11_b_b;
    c11_c_x = c11_x;
    c11_c_b = muDoubleScalarIsNaN(c11_c_x);
    c11_b2 = !c11_c_b;
    c11_d_b = (c11_b1 && c11_b2);
    if (c11_d_b) {
      c11_k++;
    } else {
      c11_p = false;
      c11_exitg1 = true;
    }
  }

  if (c11_p) {
    c11_b = true;
  } else {
    c11_b = false;
  }

  if (!c11_b) {
    c11_y = NULL;
    sf_mex_assign(&c11_y, sf_mex_create("y", c11_cv4, 10, 0U, 1U, 0U, 2, 1, 21),
                  false);
    c11_b_y = NULL;
    sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_cv5, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c11_c_y = NULL;
    sf_mex_assign(&c11_c_y, sf_mex_create("y", c11_b_cv, 10, 0U, 1U, 0U, 2, 1,
      13), false);
    sf_mex_call(&c11_b_st, &c11_emlrtMCI, "error", 0U, 2U, 14, c11_y, 14,
                sf_mex_call(&c11_b_st, NULL, "getString", 1U, 1U, 14,
      sf_mex_call(&c11_b_st, NULL, "message", 1U, 2U, 14, c11_b_y, 14, c11_c_y)));
  }

  c11_b_st.site = &c11_gb_emlrtRSI;
  c11_b_p = true;
  c11_c_k = 0;
  c11_exitg1 = false;
  while ((!c11_exitg1) && (c11_c_k < 3)) {
    c11_d_k = 1.0 + (real_T)c11_c_k;
    c11_d_x = c11_val[(int32_T)c11_d_k - 1];
    c11_c_p = !(c11_d_x <= 0.0);
    if (c11_c_p) {
      c11_c_k++;
    } else {
      c11_b_p = false;
      c11_exitg1 = true;
    }
  }

  if (c11_b_p) {
    c11_b3 = true;
  } else {
    c11_b3 = false;
  }

  if (!c11_b3) {
    c11_d_y = NULL;
    sf_mex_assign(&c11_d_y, sf_mex_create("y", c11_cv2, 10, 0U, 1U, 0U, 2, 1, 23),
                  false);
    c11_e_y = NULL;
    sf_mex_assign(&c11_e_y, sf_mex_create("y", c11_cv3, 10, 0U, 1U, 0U, 2, 1, 48),
                  false);
    c11_f_y = NULL;
    sf_mex_assign(&c11_f_y, sf_mex_create("y", c11_b_cv1, 10, 0U, 1U, 0U, 2, 1,
      13), false);
    sf_mex_call(&c11_b_st, &c11_e_emlrtMCI, "error", 0U, 2U, 14, c11_d_y, 14,
                sf_mex_call(&c11_b_st, NULL, "getString", 1U, 1U, 14,
      sf_mex_call(&c11_b_st, NULL, "message", 1U, 2U, 14, c11_e_y, 14, c11_f_y)));
  }

  c11_b_st.site = &c11_gb_emlrtRSI;
  c11_d_p = true;
  c11_e_k = 0;
  c11_exitg1 = false;
  while ((!c11_exitg1) && (c11_e_k < 3)) {
    c11_f_k = 1.0 + (real_T)c11_e_k;
    c11_e_x = c11_val[(int32_T)c11_f_k - 1];
    c11_f_x = c11_e_x;
    c11_e_b = muDoubleScalarIsNaN(c11_f_x);
    c11_e_p = !c11_e_b;
    if (c11_e_p) {
      c11_e_k++;
    } else {
      c11_d_p = false;
      c11_exitg1 = true;
    }
  }

  if (c11_d_p) {
    c11_b4 = true;
  } else {
    c11_b4 = false;
  }

  if (!c11_b4) {
    c11_g_y = NULL;
    sf_mex_assign(&c11_g_y, sf_mex_create("y", c11_cv, 10, 0U, 1U, 0U, 2, 1, 21),
                  false);
    c11_h_y = NULL;
    sf_mex_assign(&c11_h_y, sf_mex_create("y", c11_cv1, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c11_i_y = NULL;
    sf_mex_assign(&c11_i_y, sf_mex_create("y", c11_b_cv2, 10, 0U, 1U, 0U, 2, 1,
      13), false);
    sf_mex_call(&c11_b_st, &c11_d_emlrtMCI, "error", 0U, 2U, 14, c11_g_y, 14,
                sf_mex_call(&c11_b_st, NULL, "getString", 1U, 1U, 14,
      sf_mex_call(&c11_b_st, NULL, "message", 1U, 2U, 14, c11_h_y, 14, c11_i_y)));
  }

  for (c11_i = 0; c11_i < 3; c11_i++) {
    c11_obj->VelocityNoise[c11_i] = c11_val[c11_i];
  }
}

static void c11_AsyncMARGGPSFuserBase_set_GyroscopeBiasNoise
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance, const emlrtStack *c11_sp,
   c11_insfilterAsync *c11_obj, real_T c11_val[3])
{
  static char_T c11_b_cv[18] = { 'G', 'y', 'r', 'o', 's', 'c', 'o', 'p', 'e',
    'B', 'i', 'a', 's', 'N', 'o', 'i', 's', 'e' };

  static char_T c11_b_cv1[18] = { 'G', 'y', 'r', 'o', 's', 'c', 'o', 'p', 'e',
    'B', 'i', 'a', 's', 'N', 'o', 'i', 's', 'e' };

  static char_T c11_b_cv2[18] = { 'G', 'y', 'r', 'o', 's', 'c', 'o', 'p', 'e',
    'B', 'i', 'a', 's', 'N', 'o', 'i', 's', 'e' };

  emlrtStack c11_b_st;
  emlrtStack c11_st;
  const mxArray *c11_b_y = NULL;
  const mxArray *c11_c_y = NULL;
  const mxArray *c11_d_y = NULL;
  const mxArray *c11_e_y = NULL;
  const mxArray *c11_f_y = NULL;
  const mxArray *c11_g_y = NULL;
  const mxArray *c11_h_y = NULL;
  const mxArray *c11_i_y = NULL;
  const mxArray *c11_y = NULL;
  real_T c11_b_k;
  real_T c11_b_x;
  real_T c11_c_x;
  real_T c11_d_k;
  real_T c11_d_x;
  real_T c11_e_x;
  real_T c11_f_k;
  real_T c11_f_x;
  real_T c11_x;
  int32_T c11_c_k;
  int32_T c11_e_k;
  int32_T c11_i;
  int32_T c11_k;
  boolean_T c11_b;
  boolean_T c11_b1;
  boolean_T c11_b2;
  boolean_T c11_b3;
  boolean_T c11_b4;
  boolean_T c11_b_b;
  boolean_T c11_b_p;
  boolean_T c11_c_b;
  boolean_T c11_c_p;
  boolean_T c11_d_b;
  boolean_T c11_d_p;
  boolean_T c11_e_b;
  boolean_T c11_e_p;
  boolean_T c11_exitg1;
  boolean_T c11_p;
  (void)chartInstance;
  c11_st.prev = c11_sp;
  c11_st.tls = c11_sp->tls;
  c11_b_st.prev = &c11_st;
  c11_b_st.tls = c11_st.tls;
  c11_st.site = &c11_qb_emlrtRSI;
  c11_b_st.site = &c11_gb_emlrtRSI;
  c11_p = true;
  c11_k = 0;
  c11_exitg1 = false;
  while ((!c11_exitg1) && (c11_k < 3)) {
    c11_b_k = 1.0 + (real_T)c11_k;
    c11_x = c11_val[(int32_T)c11_b_k - 1];
    c11_b_x = c11_x;
    c11_b_b = muDoubleScalarIsInf(c11_b_x);
    c11_b1 = !c11_b_b;
    c11_c_x = c11_x;
    c11_c_b = muDoubleScalarIsNaN(c11_c_x);
    c11_b2 = !c11_c_b;
    c11_d_b = (c11_b1 && c11_b2);
    if (c11_d_b) {
      c11_k++;
    } else {
      c11_p = false;
      c11_exitg1 = true;
    }
  }

  if (c11_p) {
    c11_b = true;
  } else {
    c11_b = false;
  }

  if (!c11_b) {
    c11_y = NULL;
    sf_mex_assign(&c11_y, sf_mex_create("y", c11_cv4, 10, 0U, 1U, 0U, 2, 1, 21),
                  false);
    c11_b_y = NULL;
    sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_cv5, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c11_c_y = NULL;
    sf_mex_assign(&c11_c_y, sf_mex_create("y", c11_b_cv, 10, 0U, 1U, 0U, 2, 1,
      18), false);
    sf_mex_call(&c11_b_st, &c11_emlrtMCI, "error", 0U, 2U, 14, c11_y, 14,
                sf_mex_call(&c11_b_st, NULL, "getString", 1U, 1U, 14,
      sf_mex_call(&c11_b_st, NULL, "message", 1U, 2U, 14, c11_b_y, 14, c11_c_y)));
  }

  c11_b_st.site = &c11_gb_emlrtRSI;
  c11_b_p = true;
  c11_c_k = 0;
  c11_exitg1 = false;
  while ((!c11_exitg1) && (c11_c_k < 3)) {
    c11_d_k = 1.0 + (real_T)c11_c_k;
    c11_d_x = c11_val[(int32_T)c11_d_k - 1];
    c11_c_p = !(c11_d_x <= 0.0);
    if (c11_c_p) {
      c11_c_k++;
    } else {
      c11_b_p = false;
      c11_exitg1 = true;
    }
  }

  if (c11_b_p) {
    c11_b3 = true;
  } else {
    c11_b3 = false;
  }

  if (!c11_b3) {
    c11_d_y = NULL;
    sf_mex_assign(&c11_d_y, sf_mex_create("y", c11_cv2, 10, 0U, 1U, 0U, 2, 1, 23),
                  false);
    c11_e_y = NULL;
    sf_mex_assign(&c11_e_y, sf_mex_create("y", c11_cv3, 10, 0U, 1U, 0U, 2, 1, 48),
                  false);
    c11_f_y = NULL;
    sf_mex_assign(&c11_f_y, sf_mex_create("y", c11_b_cv1, 10, 0U, 1U, 0U, 2, 1,
      18), false);
    sf_mex_call(&c11_b_st, &c11_e_emlrtMCI, "error", 0U, 2U, 14, c11_d_y, 14,
                sf_mex_call(&c11_b_st, NULL, "getString", 1U, 1U, 14,
      sf_mex_call(&c11_b_st, NULL, "message", 1U, 2U, 14, c11_e_y, 14, c11_f_y)));
  }

  c11_b_st.site = &c11_gb_emlrtRSI;
  c11_d_p = true;
  c11_e_k = 0;
  c11_exitg1 = false;
  while ((!c11_exitg1) && (c11_e_k < 3)) {
    c11_f_k = 1.0 + (real_T)c11_e_k;
    c11_e_x = c11_val[(int32_T)c11_f_k - 1];
    c11_f_x = c11_e_x;
    c11_e_b = muDoubleScalarIsNaN(c11_f_x);
    c11_e_p = !c11_e_b;
    if (c11_e_p) {
      c11_e_k++;
    } else {
      c11_d_p = false;
      c11_exitg1 = true;
    }
  }

  if (c11_d_p) {
    c11_b4 = true;
  } else {
    c11_b4 = false;
  }

  if (!c11_b4) {
    c11_g_y = NULL;
    sf_mex_assign(&c11_g_y, sf_mex_create("y", c11_cv, 10, 0U, 1U, 0U, 2, 1, 21),
                  false);
    c11_h_y = NULL;
    sf_mex_assign(&c11_h_y, sf_mex_create("y", c11_cv1, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c11_i_y = NULL;
    sf_mex_assign(&c11_i_y, sf_mex_create("y", c11_b_cv2, 10, 0U, 1U, 0U, 2, 1,
      18), false);
    sf_mex_call(&c11_b_st, &c11_d_emlrtMCI, "error", 0U, 2U, 14, c11_g_y, 14,
                sf_mex_call(&c11_b_st, NULL, "getString", 1U, 1U, 14,
      sf_mex_call(&c11_b_st, NULL, "message", 1U, 2U, 14, c11_h_y, 14, c11_i_y)));
  }

  for (c11_i = 0; c11_i < 3; c11_i++) {
    c11_obj->GyroscopeBiasNoise[c11_i] = c11_val[c11_i];
  }
}

static void c11_AsyncMARGGPSFuserBase_set_AccelerometerBiasNoise
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance, const emlrtStack *c11_sp,
   c11_insfilterAsync *c11_obj, real_T c11_val[3])
{
  static char_T c11_b_cv[22] = { 'A', 'c', 'c', 'e', 'l', 'e', 'r', 'o', 'm',
    'e', 't', 'e', 'r', 'B', 'i', 'a', 's', 'N', 'o', 'i', 's', 'e' };

  static char_T c11_b_cv1[22] = { 'A', 'c', 'c', 'e', 'l', 'e', 'r', 'o', 'm',
    'e', 't', 'e', 'r', 'B', 'i', 'a', 's', 'N', 'o', 'i', 's', 'e' };

  static char_T c11_b_cv2[22] = { 'A', 'c', 'c', 'e', 'l', 'e', 'r', 'o', 'm',
    'e', 't', 'e', 'r', 'B', 'i', 'a', 's', 'N', 'o', 'i', 's', 'e' };

  emlrtStack c11_b_st;
  emlrtStack c11_st;
  const mxArray *c11_b_y = NULL;
  const mxArray *c11_c_y = NULL;
  const mxArray *c11_d_y = NULL;
  const mxArray *c11_e_y = NULL;
  const mxArray *c11_f_y = NULL;
  const mxArray *c11_g_y = NULL;
  const mxArray *c11_h_y = NULL;
  const mxArray *c11_i_y = NULL;
  const mxArray *c11_y = NULL;
  real_T c11_b_k;
  real_T c11_b_x;
  real_T c11_c_x;
  real_T c11_d_k;
  real_T c11_d_x;
  real_T c11_e_x;
  real_T c11_f_k;
  real_T c11_f_x;
  real_T c11_x;
  int32_T c11_c_k;
  int32_T c11_e_k;
  int32_T c11_i;
  int32_T c11_k;
  boolean_T c11_b;
  boolean_T c11_b1;
  boolean_T c11_b2;
  boolean_T c11_b3;
  boolean_T c11_b4;
  boolean_T c11_b_b;
  boolean_T c11_b_p;
  boolean_T c11_c_b;
  boolean_T c11_c_p;
  boolean_T c11_d_b;
  boolean_T c11_d_p;
  boolean_T c11_e_b;
  boolean_T c11_e_p;
  boolean_T c11_exitg1;
  boolean_T c11_p;
  (void)chartInstance;
  c11_st.prev = c11_sp;
  c11_st.tls = c11_sp->tls;
  c11_b_st.prev = &c11_st;
  c11_b_st.tls = c11_st.tls;
  c11_st.site = &c11_rb_emlrtRSI;
  c11_b_st.site = &c11_gb_emlrtRSI;
  c11_p = true;
  c11_k = 0;
  c11_exitg1 = false;
  while ((!c11_exitg1) && (c11_k < 3)) {
    c11_b_k = 1.0 + (real_T)c11_k;
    c11_x = c11_val[(int32_T)c11_b_k - 1];
    c11_b_x = c11_x;
    c11_b_b = muDoubleScalarIsInf(c11_b_x);
    c11_b1 = !c11_b_b;
    c11_c_x = c11_x;
    c11_c_b = muDoubleScalarIsNaN(c11_c_x);
    c11_b2 = !c11_c_b;
    c11_d_b = (c11_b1 && c11_b2);
    if (c11_d_b) {
      c11_k++;
    } else {
      c11_p = false;
      c11_exitg1 = true;
    }
  }

  if (c11_p) {
    c11_b = true;
  } else {
    c11_b = false;
  }

  if (!c11_b) {
    c11_y = NULL;
    sf_mex_assign(&c11_y, sf_mex_create("y", c11_cv4, 10, 0U, 1U, 0U, 2, 1, 21),
                  false);
    c11_b_y = NULL;
    sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_cv5, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c11_c_y = NULL;
    sf_mex_assign(&c11_c_y, sf_mex_create("y", c11_b_cv, 10, 0U, 1U, 0U, 2, 1,
      22), false);
    sf_mex_call(&c11_b_st, &c11_emlrtMCI, "error", 0U, 2U, 14, c11_y, 14,
                sf_mex_call(&c11_b_st, NULL, "getString", 1U, 1U, 14,
      sf_mex_call(&c11_b_st, NULL, "message", 1U, 2U, 14, c11_b_y, 14, c11_c_y)));
  }

  c11_b_st.site = &c11_gb_emlrtRSI;
  c11_b_p = true;
  c11_c_k = 0;
  c11_exitg1 = false;
  while ((!c11_exitg1) && (c11_c_k < 3)) {
    c11_d_k = 1.0 + (real_T)c11_c_k;
    c11_d_x = c11_val[(int32_T)c11_d_k - 1];
    c11_c_p = !(c11_d_x <= 0.0);
    if (c11_c_p) {
      c11_c_k++;
    } else {
      c11_b_p = false;
      c11_exitg1 = true;
    }
  }

  if (c11_b_p) {
    c11_b3 = true;
  } else {
    c11_b3 = false;
  }

  if (!c11_b3) {
    c11_d_y = NULL;
    sf_mex_assign(&c11_d_y, sf_mex_create("y", c11_cv2, 10, 0U, 1U, 0U, 2, 1, 23),
                  false);
    c11_e_y = NULL;
    sf_mex_assign(&c11_e_y, sf_mex_create("y", c11_cv3, 10, 0U, 1U, 0U, 2, 1, 48),
                  false);
    c11_f_y = NULL;
    sf_mex_assign(&c11_f_y, sf_mex_create("y", c11_b_cv1, 10, 0U, 1U, 0U, 2, 1,
      22), false);
    sf_mex_call(&c11_b_st, &c11_e_emlrtMCI, "error", 0U, 2U, 14, c11_d_y, 14,
                sf_mex_call(&c11_b_st, NULL, "getString", 1U, 1U, 14,
      sf_mex_call(&c11_b_st, NULL, "message", 1U, 2U, 14, c11_e_y, 14, c11_f_y)));
  }

  c11_b_st.site = &c11_gb_emlrtRSI;
  c11_d_p = true;
  c11_e_k = 0;
  c11_exitg1 = false;
  while ((!c11_exitg1) && (c11_e_k < 3)) {
    c11_f_k = 1.0 + (real_T)c11_e_k;
    c11_e_x = c11_val[(int32_T)c11_f_k - 1];
    c11_f_x = c11_e_x;
    c11_e_b = muDoubleScalarIsNaN(c11_f_x);
    c11_e_p = !c11_e_b;
    if (c11_e_p) {
      c11_e_k++;
    } else {
      c11_d_p = false;
      c11_exitg1 = true;
    }
  }

  if (c11_d_p) {
    c11_b4 = true;
  } else {
    c11_b4 = false;
  }

  if (!c11_b4) {
    c11_g_y = NULL;
    sf_mex_assign(&c11_g_y, sf_mex_create("y", c11_cv, 10, 0U, 1U, 0U, 2, 1, 21),
                  false);
    c11_h_y = NULL;
    sf_mex_assign(&c11_h_y, sf_mex_create("y", c11_cv1, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c11_i_y = NULL;
    sf_mex_assign(&c11_i_y, sf_mex_create("y", c11_b_cv2, 10, 0U, 1U, 0U, 2, 1,
      22), false);
    sf_mex_call(&c11_b_st, &c11_d_emlrtMCI, "error", 0U, 2U, 14, c11_g_y, 14,
                sf_mex_call(&c11_b_st, NULL, "getString", 1U, 1U, 14,
      sf_mex_call(&c11_b_st, NULL, "message", 1U, 2U, 14, c11_h_y, 14, c11_i_y)));
  }

  for (c11_i = 0; c11_i < 3; c11_i++) {
    c11_obj->AccelerometerBiasNoise[c11_i] = c11_val[c11_i];
  }
}

static void c11_AsyncMARGGPSFuserBase_set_GeomagneticVectorNoise
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance, const emlrtStack *c11_sp,
   c11_insfilterAsync *c11_obj, real_T c11_val[3])
{
  static char_T c11_b_cv[22] = { 'G', 'e', 'o', 'm', 'a', 'g', 'n', 'e', 't',
    'i', 'c', 'V', 'e', 'c', 't', 'o', 'r', 'N', 'o', 'i', 's', 'e' };

  static char_T c11_b_cv1[22] = { 'G', 'e', 'o', 'm', 'a', 'g', 'n', 'e', 't',
    'i', 'c', 'V', 'e', 'c', 't', 'o', 'r', 'N', 'o', 'i', 's', 'e' };

  static char_T c11_b_cv2[22] = { 'G', 'e', 'o', 'm', 'a', 'g', 'n', 'e', 't',
    'i', 'c', 'V', 'e', 'c', 't', 'o', 'r', 'N', 'o', 'i', 's', 'e' };

  emlrtStack c11_b_st;
  emlrtStack c11_st;
  const mxArray *c11_b_y = NULL;
  const mxArray *c11_c_y = NULL;
  const mxArray *c11_d_y = NULL;
  const mxArray *c11_e_y = NULL;
  const mxArray *c11_f_y = NULL;
  const mxArray *c11_g_y = NULL;
  const mxArray *c11_h_y = NULL;
  const mxArray *c11_i_y = NULL;
  const mxArray *c11_y = NULL;
  real_T c11_b_k;
  real_T c11_b_x;
  real_T c11_c_x;
  real_T c11_d_k;
  real_T c11_d_x;
  real_T c11_e_x;
  real_T c11_f_k;
  real_T c11_f_x;
  real_T c11_x;
  int32_T c11_c_k;
  int32_T c11_e_k;
  int32_T c11_i;
  int32_T c11_k;
  boolean_T c11_b;
  boolean_T c11_b1;
  boolean_T c11_b2;
  boolean_T c11_b3;
  boolean_T c11_b4;
  boolean_T c11_b_b;
  boolean_T c11_b_p;
  boolean_T c11_c_b;
  boolean_T c11_c_p;
  boolean_T c11_d_b;
  boolean_T c11_d_p;
  boolean_T c11_e_b;
  boolean_T c11_e_p;
  boolean_T c11_exitg1;
  boolean_T c11_p;
  (void)chartInstance;
  c11_st.prev = c11_sp;
  c11_st.tls = c11_sp->tls;
  c11_b_st.prev = &c11_st;
  c11_b_st.tls = c11_st.tls;
  c11_st.site = &c11_sb_emlrtRSI;
  c11_b_st.site = &c11_gb_emlrtRSI;
  c11_p = true;
  c11_k = 0;
  c11_exitg1 = false;
  while ((!c11_exitg1) && (c11_k < 3)) {
    c11_b_k = 1.0 + (real_T)c11_k;
    c11_x = c11_val[(int32_T)c11_b_k - 1];
    c11_b_x = c11_x;
    c11_b_b = muDoubleScalarIsInf(c11_b_x);
    c11_b1 = !c11_b_b;
    c11_c_x = c11_x;
    c11_c_b = muDoubleScalarIsNaN(c11_c_x);
    c11_b2 = !c11_c_b;
    c11_d_b = (c11_b1 && c11_b2);
    if (c11_d_b) {
      c11_k++;
    } else {
      c11_p = false;
      c11_exitg1 = true;
    }
  }

  if (c11_p) {
    c11_b = true;
  } else {
    c11_b = false;
  }

  if (!c11_b) {
    c11_y = NULL;
    sf_mex_assign(&c11_y, sf_mex_create("y", c11_cv4, 10, 0U, 1U, 0U, 2, 1, 21),
                  false);
    c11_b_y = NULL;
    sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_cv5, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c11_c_y = NULL;
    sf_mex_assign(&c11_c_y, sf_mex_create("y", c11_b_cv, 10, 0U, 1U, 0U, 2, 1,
      22), false);
    sf_mex_call(&c11_b_st, &c11_emlrtMCI, "error", 0U, 2U, 14, c11_y, 14,
                sf_mex_call(&c11_b_st, NULL, "getString", 1U, 1U, 14,
      sf_mex_call(&c11_b_st, NULL, "message", 1U, 2U, 14, c11_b_y, 14, c11_c_y)));
  }

  c11_b_st.site = &c11_gb_emlrtRSI;
  c11_b_p = true;
  c11_c_k = 0;
  c11_exitg1 = false;
  while ((!c11_exitg1) && (c11_c_k < 3)) {
    c11_d_k = 1.0 + (real_T)c11_c_k;
    c11_d_x = c11_val[(int32_T)c11_d_k - 1];
    c11_c_p = !(c11_d_x <= 0.0);
    if (c11_c_p) {
      c11_c_k++;
    } else {
      c11_b_p = false;
      c11_exitg1 = true;
    }
  }

  if (c11_b_p) {
    c11_b3 = true;
  } else {
    c11_b3 = false;
  }

  if (!c11_b3) {
    c11_d_y = NULL;
    sf_mex_assign(&c11_d_y, sf_mex_create("y", c11_cv2, 10, 0U, 1U, 0U, 2, 1, 23),
                  false);
    c11_e_y = NULL;
    sf_mex_assign(&c11_e_y, sf_mex_create("y", c11_cv3, 10, 0U, 1U, 0U, 2, 1, 48),
                  false);
    c11_f_y = NULL;
    sf_mex_assign(&c11_f_y, sf_mex_create("y", c11_b_cv1, 10, 0U, 1U, 0U, 2, 1,
      22), false);
    sf_mex_call(&c11_b_st, &c11_e_emlrtMCI, "error", 0U, 2U, 14, c11_d_y, 14,
                sf_mex_call(&c11_b_st, NULL, "getString", 1U, 1U, 14,
      sf_mex_call(&c11_b_st, NULL, "message", 1U, 2U, 14, c11_e_y, 14, c11_f_y)));
  }

  c11_b_st.site = &c11_gb_emlrtRSI;
  c11_d_p = true;
  c11_e_k = 0;
  c11_exitg1 = false;
  while ((!c11_exitg1) && (c11_e_k < 3)) {
    c11_f_k = 1.0 + (real_T)c11_e_k;
    c11_e_x = c11_val[(int32_T)c11_f_k - 1];
    c11_f_x = c11_e_x;
    c11_e_b = muDoubleScalarIsNaN(c11_f_x);
    c11_e_p = !c11_e_b;
    if (c11_e_p) {
      c11_e_k++;
    } else {
      c11_d_p = false;
      c11_exitg1 = true;
    }
  }

  if (c11_d_p) {
    c11_b4 = true;
  } else {
    c11_b4 = false;
  }

  if (!c11_b4) {
    c11_g_y = NULL;
    sf_mex_assign(&c11_g_y, sf_mex_create("y", c11_cv, 10, 0U, 1U, 0U, 2, 1, 21),
                  false);
    c11_h_y = NULL;
    sf_mex_assign(&c11_h_y, sf_mex_create("y", c11_cv1, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c11_i_y = NULL;
    sf_mex_assign(&c11_i_y, sf_mex_create("y", c11_b_cv2, 10, 0U, 1U, 0U, 2, 1,
      22), false);
    sf_mex_call(&c11_b_st, &c11_d_emlrtMCI, "error", 0U, 2U, 14, c11_g_y, 14,
                sf_mex_call(&c11_b_st, NULL, "getString", 1U, 1U, 14,
      sf_mex_call(&c11_b_st, NULL, "message", 1U, 2U, 14, c11_h_y, 14, c11_i_y)));
  }

  for (c11_i = 0; c11_i < 3; c11_i++) {
    c11_obj->GeomagneticVectorNoise[c11_i] = c11_val[c11_i];
  }
}

static void c11_AsyncMARGGPSFuserBase_set_MagnetometerBiasNoise
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance, const emlrtStack *c11_sp,
   c11_insfilterAsync *c11_obj, real_T c11_val[3])
{
  static char_T c11_b_cv[21] = { 'M', 'a', 'g', 'n', 'e', 't', 'o', 'm', 'e',
    't', 'e', 'r', 'B', 'i', 'a', 's', 'N', 'o', 'i', 's', 'e' };

  static char_T c11_b_cv1[21] = { 'M', 'a', 'g', 'n', 'e', 't', 'o', 'm', 'e',
    't', 'e', 'r', 'B', 'i', 'a', 's', 'N', 'o', 'i', 's', 'e' };

  static char_T c11_b_cv2[21] = { 'M', 'a', 'g', 'n', 'e', 't', 'o', 'm', 'e',
    't', 'e', 'r', 'B', 'i', 'a', 's', 'N', 'o', 'i', 's', 'e' };

  emlrtStack c11_b_st;
  emlrtStack c11_st;
  const mxArray *c11_b_y = NULL;
  const mxArray *c11_c_y = NULL;
  const mxArray *c11_d_y = NULL;
  const mxArray *c11_e_y = NULL;
  const mxArray *c11_f_y = NULL;
  const mxArray *c11_g_y = NULL;
  const mxArray *c11_h_y = NULL;
  const mxArray *c11_i_y = NULL;
  const mxArray *c11_y = NULL;
  real_T c11_b_k;
  real_T c11_b_x;
  real_T c11_c_x;
  real_T c11_d_k;
  real_T c11_d_x;
  real_T c11_e_x;
  real_T c11_f_k;
  real_T c11_f_x;
  real_T c11_x;
  int32_T c11_c_k;
  int32_T c11_e_k;
  int32_T c11_i;
  int32_T c11_k;
  boolean_T c11_b;
  boolean_T c11_b1;
  boolean_T c11_b2;
  boolean_T c11_b3;
  boolean_T c11_b4;
  boolean_T c11_b_b;
  boolean_T c11_b_p;
  boolean_T c11_c_b;
  boolean_T c11_c_p;
  boolean_T c11_d_b;
  boolean_T c11_d_p;
  boolean_T c11_e_b;
  boolean_T c11_e_p;
  boolean_T c11_exitg1;
  boolean_T c11_p;
  (void)chartInstance;
  c11_st.prev = c11_sp;
  c11_st.tls = c11_sp->tls;
  c11_b_st.prev = &c11_st;
  c11_b_st.tls = c11_st.tls;
  c11_st.site = &c11_tb_emlrtRSI;
  c11_b_st.site = &c11_gb_emlrtRSI;
  c11_p = true;
  c11_k = 0;
  c11_exitg1 = false;
  while ((!c11_exitg1) && (c11_k < 3)) {
    c11_b_k = 1.0 + (real_T)c11_k;
    c11_x = c11_val[(int32_T)c11_b_k - 1];
    c11_b_x = c11_x;
    c11_b_b = muDoubleScalarIsInf(c11_b_x);
    c11_b1 = !c11_b_b;
    c11_c_x = c11_x;
    c11_c_b = muDoubleScalarIsNaN(c11_c_x);
    c11_b2 = !c11_c_b;
    c11_d_b = (c11_b1 && c11_b2);
    if (c11_d_b) {
      c11_k++;
    } else {
      c11_p = false;
      c11_exitg1 = true;
    }
  }

  if (c11_p) {
    c11_b = true;
  } else {
    c11_b = false;
  }

  if (!c11_b) {
    c11_y = NULL;
    sf_mex_assign(&c11_y, sf_mex_create("y", c11_cv4, 10, 0U, 1U, 0U, 2, 1, 21),
                  false);
    c11_b_y = NULL;
    sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_cv5, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c11_c_y = NULL;
    sf_mex_assign(&c11_c_y, sf_mex_create("y", c11_b_cv, 10, 0U, 1U, 0U, 2, 1,
      21), false);
    sf_mex_call(&c11_b_st, &c11_emlrtMCI, "error", 0U, 2U, 14, c11_y, 14,
                sf_mex_call(&c11_b_st, NULL, "getString", 1U, 1U, 14,
      sf_mex_call(&c11_b_st, NULL, "message", 1U, 2U, 14, c11_b_y, 14, c11_c_y)));
  }

  c11_b_st.site = &c11_gb_emlrtRSI;
  c11_b_p = true;
  c11_c_k = 0;
  c11_exitg1 = false;
  while ((!c11_exitg1) && (c11_c_k < 3)) {
    c11_d_k = 1.0 + (real_T)c11_c_k;
    c11_d_x = c11_val[(int32_T)c11_d_k - 1];
    c11_c_p = !(c11_d_x <= 0.0);
    if (c11_c_p) {
      c11_c_k++;
    } else {
      c11_b_p = false;
      c11_exitg1 = true;
    }
  }

  if (c11_b_p) {
    c11_b3 = true;
  } else {
    c11_b3 = false;
  }

  if (!c11_b3) {
    c11_d_y = NULL;
    sf_mex_assign(&c11_d_y, sf_mex_create("y", c11_cv2, 10, 0U, 1U, 0U, 2, 1, 23),
                  false);
    c11_e_y = NULL;
    sf_mex_assign(&c11_e_y, sf_mex_create("y", c11_cv3, 10, 0U, 1U, 0U, 2, 1, 48),
                  false);
    c11_f_y = NULL;
    sf_mex_assign(&c11_f_y, sf_mex_create("y", c11_b_cv1, 10, 0U, 1U, 0U, 2, 1,
      21), false);
    sf_mex_call(&c11_b_st, &c11_e_emlrtMCI, "error", 0U, 2U, 14, c11_d_y, 14,
                sf_mex_call(&c11_b_st, NULL, "getString", 1U, 1U, 14,
      sf_mex_call(&c11_b_st, NULL, "message", 1U, 2U, 14, c11_e_y, 14, c11_f_y)));
  }

  c11_b_st.site = &c11_gb_emlrtRSI;
  c11_d_p = true;
  c11_e_k = 0;
  c11_exitg1 = false;
  while ((!c11_exitg1) && (c11_e_k < 3)) {
    c11_f_k = 1.0 + (real_T)c11_e_k;
    c11_e_x = c11_val[(int32_T)c11_f_k - 1];
    c11_f_x = c11_e_x;
    c11_e_b = muDoubleScalarIsNaN(c11_f_x);
    c11_e_p = !c11_e_b;
    if (c11_e_p) {
      c11_e_k++;
    } else {
      c11_d_p = false;
      c11_exitg1 = true;
    }
  }

  if (c11_d_p) {
    c11_b4 = true;
  } else {
    c11_b4 = false;
  }

  if (!c11_b4) {
    c11_g_y = NULL;
    sf_mex_assign(&c11_g_y, sf_mex_create("y", c11_cv, 10, 0U, 1U, 0U, 2, 1, 21),
                  false);
    c11_h_y = NULL;
    sf_mex_assign(&c11_h_y, sf_mex_create("y", c11_cv1, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c11_i_y = NULL;
    sf_mex_assign(&c11_i_y, sf_mex_create("y", c11_b_cv2, 10, 0U, 1U, 0U, 2, 1,
      21), false);
    sf_mex_call(&c11_b_st, &c11_d_emlrtMCI, "error", 0U, 2U, 14, c11_g_y, 14,
                sf_mex_call(&c11_b_st, NULL, "getString", 1U, 1U, 14,
      sf_mex_call(&c11_b_st, NULL, "message", 1U, 2U, 14, c11_h_y, 14, c11_i_y)));
  }

  for (c11_i = 0; c11_i < 3; c11_i++) {
    c11_obj->MagnetometerBiasNoise[c11_i] = c11_val[c11_i];
  }
}

static void c11_AsyncMARGGPSFuserBase_predict
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance, const emlrtStack *c11_sp,
   c11_insfilterAsync *c11_obj, real_T c11_dt)
{
  static real_T c11_dv[28] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0 };

  static real_T c11_dv1[28] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0 };

  static real_T c11_dv2[28] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0 };

  static real_T c11_dv3[28] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0 };

  static real_T c11_dv4[28] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0 };

  static real_T c11_dv5[28] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0 };

  static char_T c11_b_cv[2] = { 'd', 't' };

  ptrdiff_t c11_k_t;
  ptrdiff_t c11_lda_t;
  ptrdiff_t c11_ldb_t;
  ptrdiff_t c11_ldc_t;
  ptrdiff_t c11_m_t;
  ptrdiff_t c11_n_t;
  c11_insfilterAsync *c11_b_obj;
  c11_insfilterAsync *c11_c_obj;
  c11_insfilterAsync *c11_d_obj;
  c11_insfilterAsync *c11_e_obj;
  emlrtStack c11_b_st;
  emlrtStack c11_st;
  const mxArray *c11_b_y = NULL;
  const mxArray *c11_c_y = NULL;
  const mxArray *c11_y = NULL;
  real_T c11_P[784];
  real_T c11_Pdot[784];
  real_T c11_addProcNoise[784];
  real_T c11_d_y[784];
  real_T c11_dfdx[784];
  real_T c11_xdot[28];
  real_T c11_xk[28];
  real_T c11_f_y[4];
  real_T c11_idx[4];
  real_T c11_qparts[4];
  real_T c11_a;
  real_T c11_ad;
  real_T c11_ae;
  real_T c11_alpha1;
  real_T c11_an;
  real_T c11_b_a;
  real_T c11_b_dt;
  real_T c11_b_q0;
  real_T c11_b_q1;
  real_T c11_b_q2;
  real_T c11_b_q3;
  real_T c11_b_wx;
  real_T c11_b_wy;
  real_T c11_b_wz;
  real_T c11_b_x;
  real_T c11_beta1;
  real_T c11_c_a;
  real_T c11_c_dt;
  real_T c11_c_x;
  real_T c11_d_a;
  real_T c11_e_y;
  real_T c11_g_y;
  real_T c11_magE;
  real_T c11_magN;
  real_T c11_n;
  real_T c11_q0;
  real_T c11_q1;
  real_T c11_q2;
  real_T c11_q3;
  real_T c11_vd;
  real_T c11_ve;
  real_T c11_vn;
  real_T c11_wx;
  real_T c11_wy;
  real_T c11_wz;
  real_T c11_x;
  int32_T c11_b_j;
  int32_T c11_b_k;
  int32_T c11_i;
  int32_T c11_i1;
  int32_T c11_i10;
  int32_T c11_i11;
  int32_T c11_i12;
  int32_T c11_i13;
  int32_T c11_i14;
  int32_T c11_i15;
  int32_T c11_i16;
  int32_T c11_i17;
  int32_T c11_i18;
  int32_T c11_i19;
  int32_T c11_i2;
  int32_T c11_i20;
  int32_T c11_i21;
  int32_T c11_i22;
  int32_T c11_i23;
  int32_T c11_i24;
  int32_T c11_i25;
  int32_T c11_i26;
  int32_T c11_i27;
  int32_T c11_i28;
  int32_T c11_i29;
  int32_T c11_i3;
  int32_T c11_i30;
  int32_T c11_i31;
  int32_T c11_i32;
  int32_T c11_i33;
  int32_T c11_i34;
  int32_T c11_i35;
  int32_T c11_i36;
  int32_T c11_i37;
  int32_T c11_i38;
  int32_T c11_i39;
  int32_T c11_i4;
  int32_T c11_i40;
  int32_T c11_i41;
  int32_T c11_i42;
  int32_T c11_i43;
  int32_T c11_i44;
  int32_T c11_i45;
  int32_T c11_i46;
  int32_T c11_i47;
  int32_T c11_i48;
  int32_T c11_i49;
  int32_T c11_i5;
  int32_T c11_i50;
  int32_T c11_i51;
  int32_T c11_i52;
  int32_T c11_i53;
  int32_T c11_i54;
  int32_T c11_i55;
  int32_T c11_i56;
  int32_T c11_i57;
  int32_T c11_i58;
  int32_T c11_i59;
  int32_T c11_i6;
  int32_T c11_i60;
  int32_T c11_i61;
  int32_T c11_i62;
  int32_T c11_i63;
  int32_T c11_i64;
  int32_T c11_i65;
  int32_T c11_i66;
  int32_T c11_i67;
  int32_T c11_i68;
  int32_T c11_i69;
  int32_T c11_i7;
  int32_T c11_i70;
  int32_T c11_i71;
  int32_T c11_i72;
  int32_T c11_i73;
  int32_T c11_i74;
  int32_T c11_i75;
  int32_T c11_i76;
  int32_T c11_i8;
  int32_T c11_i9;
  int32_T c11_j;
  int32_T c11_k;
  char_T c11_TRANSA1;
  char_T c11_TRANSB1;
  boolean_T c11_b;
  boolean_T c11_b1;
  boolean_T c11_b2;
  boolean_T c11_b_b;
  boolean_T c11_c_b;
  boolean_T c11_d_b;
  boolean_T c11_p;
  c11_st.prev = c11_sp;
  c11_st.tls = c11_sp->tls;
  c11_b_st.prev = &c11_st;
  c11_b_st.tls = c11_st.tls;
  c11_st.site = &c11_ub_emlrtRSI;
  c11_b_obj = c11_obj;
  for (c11_i = 0; c11_i < 28; c11_i++) {
    c11_xk[c11_i] = c11_b_obj->pState[c11_i];
  }

  c11_magN = c11_xk[22];
  c11_magE = c11_xk[23];
  c11_xk[22] = c11_magN;
  c11_xk[23] = c11_magE;
  c11_st.site = &c11_vb_emlrtRSI;
  c11_a = c11_dt;
  c11_b_st.site = &c11_gb_emlrtRSI;
  c11_b_a = c11_a;
  c11_c_a = c11_b_a;
  c11_p = true;
  c11_x = c11_c_a;
  c11_b_x = c11_x;
  c11_b = muDoubleScalarIsInf(c11_b_x);
  c11_b_b = !c11_b;
  c11_c_x = c11_x;
  c11_c_b = muDoubleScalarIsNaN(c11_c_x);
  c11_b1 = !c11_c_b;
  c11_d_b = (c11_b_b && c11_b1);
  if (!c11_d_b) {
    c11_p = false;
  }

  if (c11_p) {
    c11_b2 = true;
  } else {
    c11_b2 = false;
  }

  if (!c11_b2) {
    c11_y = NULL;
    sf_mex_assign(&c11_y, sf_mex_create("y", c11_cv4, 10, 0U, 1U, 0U, 2, 1, 21),
                  false);
    c11_b_y = NULL;
    sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_cv5, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c11_c_y = NULL;
    sf_mex_assign(&c11_c_y, sf_mex_create("y", c11_b_cv, 10, 0U, 1U, 0U, 2, 1, 2),
                  false);
    sf_mex_call(&c11_b_st, &c11_emlrtMCI, "error", 0U, 2U, 14, c11_y, 14,
                sf_mex_call(&c11_b_st, NULL, "getString", 1U, 1U, 14,
      sf_mex_call(&c11_b_st, NULL, "message", 1U, 2U, 14, c11_b_y, 14, c11_c_y)));
  }

  c11_st.site = &c11_wb_emlrtRSI;
  c11_c_obj = c11_obj;
  for (c11_i1 = 0; c11_i1 < 784; c11_i1++) {
    c11_P[c11_i1] = c11_c_obj->pStateCovariance[c11_i1];
  }

  c11_st.site = &c11_xb_emlrtRSI;
  c11_d_obj = c11_obj;
  for (c11_i2 = 0; c11_i2 < 4; c11_i2++) {
    c11_xdot[c11_i2] = c11_d_obj->QuaternionNoise[c11_i2];
  }

  for (c11_i3 = 0; c11_i3 < 3; c11_i3++) {
    c11_xdot[c11_i3 + 4] = c11_d_obj->AngularVelocityNoise[c11_i3];
  }

  for (c11_i4 = 0; c11_i4 < 3; c11_i4++) {
    c11_xdot[c11_i4 + 7] = c11_d_obj->PositionNoise[c11_i4];
  }

  for (c11_i5 = 0; c11_i5 < 3; c11_i5++) {
    c11_xdot[c11_i5 + 10] = c11_d_obj->VelocityNoise[c11_i5];
  }

  for (c11_i6 = 0; c11_i6 < 3; c11_i6++) {
    c11_xdot[c11_i6 + 13] = c11_d_obj->AccelerationNoise[c11_i6];
  }

  for (c11_i7 = 0; c11_i7 < 3; c11_i7++) {
    c11_xdot[c11_i7 + 16] = c11_d_obj->AccelerometerBiasNoise[c11_i7];
  }

  for (c11_i8 = 0; c11_i8 < 3; c11_i8++) {
    c11_xdot[c11_i8 + 19] = c11_d_obj->GyroscopeBiasNoise[c11_i8];
  }

  for (c11_i9 = 0; c11_i9 < 3; c11_i9++) {
    c11_xdot[c11_i9 + 22] = c11_d_obj->GeomagneticVectorNoise[c11_i9];
  }

  for (c11_i10 = 0; c11_i10 < 3; c11_i10++) {
    c11_xdot[c11_i10 + 25] = c11_d_obj->MagnetometerBiasNoise[c11_i10];
  }

  for (c11_i11 = 0; c11_i11 < 784; c11_i11++) {
    c11_addProcNoise[c11_i11] = 0.0;
  }

  for (c11_j = 0; c11_j < 28; c11_j++) {
    c11_b_j = c11_j;
    c11_addProcNoise[c11_b_j + 28 * c11_b_j] = c11_xdot[c11_b_j];
  }

  for (c11_i12 = 0; c11_i12 < 28; c11_i12++) {
    c11_xdot[c11_i12] = c11_xk[c11_i12];
  }

  c11_q0 = c11_xdot[0];
  c11_q1 = c11_xdot[1];
  c11_q2 = c11_xdot[2];
  c11_q3 = c11_xdot[3];
  c11_wx = c11_xdot[4];
  c11_wy = c11_xdot[5];
  c11_wz = c11_xdot[6];
  c11_vn = c11_xdot[10];
  c11_ve = c11_xdot[11];
  c11_vd = c11_xdot[12];
  c11_an = c11_xdot[13];
  c11_ae = c11_xdot[14];
  c11_ad = c11_xdot[15];
  c11_xdot[0] = (-(c11_q1 * c11_wx) / 2.0 - c11_q2 * c11_wy / 2.0) - c11_q3 *
    c11_wz / 2.0;
  c11_xdot[1] = (c11_q0 * c11_wx / 2.0 - c11_q3 * c11_wy / 2.0) + c11_q2 *
    c11_wz / 2.0;
  c11_xdot[2] = (c11_q3 * c11_wx / 2.0 + c11_q0 * c11_wy / 2.0) - c11_q1 *
    c11_wz / 2.0;
  c11_xdot[3] = (c11_q1 * c11_wy / 2.0 - c11_q2 * c11_wx / 2.0) + c11_q0 *
    c11_wz / 2.0;
  c11_xdot[4] = 0.0;
  c11_xdot[5] = 0.0;
  c11_xdot[6] = 0.0;
  c11_xdot[7] = c11_vn;
  c11_xdot[8] = c11_ve;
  c11_xdot[9] = c11_vd;
  c11_xdot[10] = c11_an;
  c11_xdot[11] = c11_ae;
  c11_xdot[12] = c11_ad;
  c11_xdot[13] = 0.0;
  c11_xdot[14] = 0.0;
  c11_xdot[15] = 0.0;
  c11_xdot[16] = 0.0;
  c11_xdot[17] = 0.0;
  c11_xdot[18] = 0.0;
  c11_xdot[19] = 0.0;
  c11_xdot[20] = 0.0;
  c11_xdot[21] = 0.0;
  c11_xdot[22] = 0.0;
  c11_xdot[23] = 0.0;
  c11_xdot[24] = 0.0;
  c11_xdot[25] = 0.0;
  c11_xdot[26] = 0.0;
  c11_xdot[27] = 0.0;
  c11_b_q0 = c11_xk[0];
  c11_b_q1 = c11_xk[1];
  c11_b_q2 = c11_xk[2];
  c11_b_q3 = c11_xk[3];
  c11_b_wx = c11_xk[4];
  c11_b_wy = c11_xk[5];
  c11_b_wz = c11_xk[6];
  c11_dfdx[0] = 0.0;
  c11_dfdx[28] = -c11_b_wx / 2.0;
  c11_dfdx[56] = -c11_b_wy / 2.0;
  c11_dfdx[84] = -c11_b_wz / 2.0;
  c11_dfdx[112] = -c11_b_q1 / 2.0;
  c11_dfdx[140] = -c11_b_q2 / 2.0;
  c11_dfdx[168] = -c11_b_q3 / 2.0;
  c11_dfdx[196] = 0.0;
  c11_dfdx[224] = 0.0;
  c11_dfdx[252] = 0.0;
  c11_dfdx[280] = 0.0;
  c11_dfdx[308] = 0.0;
  c11_dfdx[336] = 0.0;
  c11_dfdx[364] = 0.0;
  c11_dfdx[392] = 0.0;
  c11_dfdx[420] = 0.0;
  c11_dfdx[448] = 0.0;
  c11_dfdx[476] = 0.0;
  c11_dfdx[504] = 0.0;
  c11_dfdx[532] = 0.0;
  c11_dfdx[560] = 0.0;
  c11_dfdx[588] = 0.0;
  c11_dfdx[616] = 0.0;
  c11_dfdx[644] = 0.0;
  c11_dfdx[672] = 0.0;
  c11_dfdx[700] = 0.0;
  c11_dfdx[728] = 0.0;
  c11_dfdx[756] = 0.0;
  c11_dfdx[1] = c11_b_wx / 2.0;
  c11_dfdx[29] = 0.0;
  c11_dfdx[57] = c11_b_wz / 2.0;
  c11_dfdx[85] = -c11_b_wy / 2.0;
  c11_dfdx[113] = c11_b_q0 / 2.0;
  c11_dfdx[141] = -c11_b_q3 / 2.0;
  c11_dfdx[169] = c11_b_q2 / 2.0;
  c11_dfdx[197] = 0.0;
  c11_dfdx[225] = 0.0;
  c11_dfdx[253] = 0.0;
  c11_dfdx[281] = 0.0;
  c11_dfdx[309] = 0.0;
  c11_dfdx[337] = 0.0;
  c11_dfdx[365] = 0.0;
  c11_dfdx[393] = 0.0;
  c11_dfdx[421] = 0.0;
  c11_dfdx[449] = 0.0;
  c11_dfdx[477] = 0.0;
  c11_dfdx[505] = 0.0;
  c11_dfdx[533] = 0.0;
  c11_dfdx[561] = 0.0;
  c11_dfdx[589] = 0.0;
  c11_dfdx[617] = 0.0;
  c11_dfdx[645] = 0.0;
  c11_dfdx[673] = 0.0;
  c11_dfdx[701] = 0.0;
  c11_dfdx[729] = 0.0;
  c11_dfdx[757] = 0.0;
  c11_dfdx[2] = c11_b_wy / 2.0;
  c11_dfdx[30] = -c11_b_wz / 2.0;
  c11_dfdx[58] = 0.0;
  c11_dfdx[86] = c11_b_wx / 2.0;
  c11_dfdx[114] = c11_b_q3 / 2.0;
  c11_dfdx[142] = c11_b_q0 / 2.0;
  c11_dfdx[170] = -c11_b_q1 / 2.0;
  c11_dfdx[198] = 0.0;
  c11_dfdx[226] = 0.0;
  c11_dfdx[254] = 0.0;
  c11_dfdx[282] = 0.0;
  c11_dfdx[310] = 0.0;
  c11_dfdx[338] = 0.0;
  c11_dfdx[366] = 0.0;
  c11_dfdx[394] = 0.0;
  c11_dfdx[422] = 0.0;
  c11_dfdx[450] = 0.0;
  c11_dfdx[478] = 0.0;
  c11_dfdx[506] = 0.0;
  c11_dfdx[534] = 0.0;
  c11_dfdx[562] = 0.0;
  c11_dfdx[590] = 0.0;
  c11_dfdx[618] = 0.0;
  c11_dfdx[646] = 0.0;
  c11_dfdx[674] = 0.0;
  c11_dfdx[702] = 0.0;
  c11_dfdx[730] = 0.0;
  c11_dfdx[758] = 0.0;
  c11_dfdx[3] = c11_b_wz / 2.0;
  c11_dfdx[31] = c11_b_wy / 2.0;
  c11_dfdx[59] = -c11_b_wx / 2.0;
  c11_dfdx[87] = 0.0;
  c11_dfdx[115] = -c11_b_q2 / 2.0;
  c11_dfdx[143] = c11_b_q1 / 2.0;
  c11_dfdx[171] = c11_b_q0 / 2.0;
  c11_dfdx[199] = 0.0;
  c11_dfdx[227] = 0.0;
  c11_dfdx[255] = 0.0;
  c11_dfdx[283] = 0.0;
  c11_dfdx[311] = 0.0;
  c11_dfdx[339] = 0.0;
  c11_dfdx[367] = 0.0;
  c11_dfdx[395] = 0.0;
  c11_dfdx[423] = 0.0;
  c11_dfdx[451] = 0.0;
  c11_dfdx[479] = 0.0;
  c11_dfdx[507] = 0.0;
  c11_dfdx[535] = 0.0;
  c11_dfdx[563] = 0.0;
  c11_dfdx[591] = 0.0;
  c11_dfdx[619] = 0.0;
  c11_dfdx[647] = 0.0;
  c11_dfdx[675] = 0.0;
  c11_dfdx[703] = 0.0;
  c11_dfdx[731] = 0.0;
  c11_dfdx[759] = 0.0;
  c11_i13 = 0;
  for (c11_i14 = 0; c11_i14 < 28; c11_i14++) {
    c11_dfdx[c11_i13 + 4] = 0.0;
    c11_i13 += 28;
  }

  c11_i15 = 0;
  for (c11_i16 = 0; c11_i16 < 28; c11_i16++) {
    c11_dfdx[c11_i15 + 5] = 0.0;
    c11_i15 += 28;
  }

  c11_i17 = 0;
  for (c11_i18 = 0; c11_i18 < 28; c11_i18++) {
    c11_dfdx[c11_i17 + 6] = 0.0;
    c11_i17 += 28;
  }

  c11_i19 = 0;
  for (c11_i20 = 0; c11_i20 < 28; c11_i20++) {
    c11_dfdx[c11_i19 + 7] = c11_dv[c11_i20];
    c11_i19 += 28;
  }

  c11_i21 = 0;
  for (c11_i22 = 0; c11_i22 < 28; c11_i22++) {
    c11_dfdx[c11_i21 + 8] = c11_dv1[c11_i22];
    c11_i21 += 28;
  }

  c11_i23 = 0;
  for (c11_i24 = 0; c11_i24 < 28; c11_i24++) {
    c11_dfdx[c11_i23 + 9] = c11_dv2[c11_i24];
    c11_i23 += 28;
  }

  c11_i25 = 0;
  for (c11_i26 = 0; c11_i26 < 28; c11_i26++) {
    c11_dfdx[c11_i25 + 10] = c11_dv3[c11_i26];
    c11_i25 += 28;
  }

  c11_i27 = 0;
  for (c11_i28 = 0; c11_i28 < 28; c11_i28++) {
    c11_dfdx[c11_i27 + 11] = c11_dv4[c11_i28];
    c11_i27 += 28;
  }

  c11_i29 = 0;
  for (c11_i30 = 0; c11_i30 < 28; c11_i30++) {
    c11_dfdx[c11_i29 + 12] = c11_dv5[c11_i30];
    c11_i29 += 28;
  }

  c11_i31 = 0;
  for (c11_i32 = 0; c11_i32 < 28; c11_i32++) {
    c11_dfdx[c11_i31 + 13] = 0.0;
    c11_i31 += 28;
  }

  c11_i33 = 0;
  for (c11_i34 = 0; c11_i34 < 28; c11_i34++) {
    c11_dfdx[c11_i33 + 14] = 0.0;
    c11_i33 += 28;
  }

  c11_i35 = 0;
  for (c11_i36 = 0; c11_i36 < 28; c11_i36++) {
    c11_dfdx[c11_i35 + 15] = 0.0;
    c11_i35 += 28;
  }

  c11_i37 = 0;
  for (c11_i38 = 0; c11_i38 < 28; c11_i38++) {
    c11_dfdx[c11_i37 + 16] = 0.0;
    c11_i37 += 28;
  }

  c11_i39 = 0;
  for (c11_i40 = 0; c11_i40 < 28; c11_i40++) {
    c11_dfdx[c11_i39 + 17] = 0.0;
    c11_i39 += 28;
  }

  c11_i41 = 0;
  for (c11_i42 = 0; c11_i42 < 28; c11_i42++) {
    c11_dfdx[c11_i41 + 18] = 0.0;
    c11_i41 += 28;
  }

  c11_i43 = 0;
  for (c11_i44 = 0; c11_i44 < 28; c11_i44++) {
    c11_dfdx[c11_i43 + 19] = 0.0;
    c11_i43 += 28;
  }

  c11_i45 = 0;
  for (c11_i46 = 0; c11_i46 < 28; c11_i46++) {
    c11_dfdx[c11_i45 + 20] = 0.0;
    c11_i45 += 28;
  }

  c11_i47 = 0;
  for (c11_i48 = 0; c11_i48 < 28; c11_i48++) {
    c11_dfdx[c11_i47 + 21] = 0.0;
    c11_i47 += 28;
  }

  c11_i49 = 0;
  for (c11_i50 = 0; c11_i50 < 28; c11_i50++) {
    c11_dfdx[c11_i49 + 22] = 0.0;
    c11_i49 += 28;
  }

  c11_i51 = 0;
  for (c11_i52 = 0; c11_i52 < 28; c11_i52++) {
    c11_dfdx[c11_i51 + 23] = 0.0;
    c11_i51 += 28;
  }

  c11_i53 = 0;
  for (c11_i54 = 0; c11_i54 < 28; c11_i54++) {
    c11_dfdx[c11_i53 + 24] = 0.0;
    c11_i53 += 28;
  }

  c11_i55 = 0;
  for (c11_i56 = 0; c11_i56 < 28; c11_i56++) {
    c11_dfdx[c11_i55 + 25] = 0.0;
    c11_i55 += 28;
  }

  c11_i57 = 0;
  for (c11_i58 = 0; c11_i58 < 28; c11_i58++) {
    c11_dfdx[c11_i57 + 26] = 0.0;
    c11_i57 += 28;
  }

  c11_i59 = 0;
  for (c11_i60 = 0; c11_i60 < 28; c11_i60++) {
    c11_dfdx[c11_i59 + 27] = 0.0;
    c11_i59 += 28;
  }

  c11_st.site = &c11_yb_emlrtRSI;
  c11_b_st.site = &c11_dc_emlrtRSI;
  c11_mtimes(chartInstance, c11_dfdx, c11_P, c11_Pdot);
  c11_b_st.site = &c11_dc_emlrtRSI;
  c11_TRANSB1 = 'T';
  c11_TRANSA1 = 'N';
  c11_alpha1 = 1.0;
  c11_beta1 = 0.0;
  c11_m_t = (ptrdiff_t)28;
  c11_n_t = (ptrdiff_t)28;
  c11_k_t = (ptrdiff_t)28;
  c11_lda_t = (ptrdiff_t)28;
  c11_ldb_t = (ptrdiff_t)28;
  c11_ldc_t = (ptrdiff_t)28;
  dgemm(&c11_TRANSA1, &c11_TRANSB1, &c11_m_t, &c11_n_t, &c11_k_t, &c11_alpha1,
        &c11_P[0], &c11_lda_t, &c11_dfdx[0], &c11_ldb_t, &c11_beta1, &c11_d_y[0],
        &c11_ldc_t);
  for (c11_i61 = 0; c11_i61 < 784; c11_i61++) {
    c11_Pdot[c11_i61] = (c11_Pdot[c11_i61] + c11_d_y[c11_i61]) +
      c11_addProcNoise[c11_i61];
  }

  c11_i62 = 0;
  for (c11_i63 = 0; c11_i63 < 28; c11_i63++) {
    c11_i65 = 0;
    for (c11_i66 = 0; c11_i66 < 28; c11_i66++) {
      c11_addProcNoise[c11_i66 + c11_i62] = c11_Pdot[c11_i66 + c11_i62] +
        c11_Pdot[c11_i65 + c11_i63];
      c11_i65 += 28;
    }

    c11_i62 += 28;
  }

  for (c11_i64 = 0; c11_i64 < 784; c11_i64++) {
    c11_Pdot[c11_i64] = 0.5 * c11_addProcNoise[c11_i64];
  }

  c11_b_dt = c11_dt;
  for (c11_i67 = 0; c11_i67 < 28; c11_i67++) {
    c11_xk[c11_i67] += c11_b_dt * c11_xdot[c11_i67];
  }

  c11_c_dt = c11_dt;
  for (c11_i68 = 0; c11_i68 < 784; c11_i68++) {
    c11_P[c11_i68] += c11_c_dt * c11_Pdot[c11_i68];
  }

  c11_st.site = &c11_ac_emlrtRSI;
  c11_e_obj = c11_obj;
  for (c11_i69 = 0; c11_i69 < 4; c11_i69++) {
    c11_idx[c11_i69] = c11_e_obj->OrientationIdx[c11_i69];
  }

  for (c11_i70 = 0; c11_i70 < 4; c11_i70++) {
    if (c11_idx[c11_i70] != (real_T)(int32_T)muDoubleScalarFloor(c11_idx[c11_i70]))
    {
      emlrtIntegerCheckR2012b(c11_idx[c11_i70], &c11_emlrtDCI, &c11_st);
    }

    c11_i71 = (int32_T)c11_idx[c11_i70];
    if ((c11_i71 < 1) || (c11_i71 > 28)) {
      emlrtDynamicBoundsCheckR2012b(c11_i71, 1, 28, &c11_emlrtBCI, &c11_st);
    }

    c11_qparts[c11_i70] = c11_xk[c11_i71 - 1];
  }

  for (c11_k = 0; c11_k < 4; c11_k++) {
    c11_b_k = c11_k;
    c11_d_a = c11_qparts[c11_b_k];
    c11_g_y = c11_d_a * c11_d_a;
    c11_f_y[c11_b_k] = c11_g_y;
  }

  c11_e_y = c11_sumColumnB(chartInstance, c11_f_y, 1);
  c11_n = c11_e_y;
  c11_b_st.site = &c11_hc_emlrtRSI;
  c11_b_sqrt(chartInstance, &c11_b_st, &c11_n);
  for (c11_i72 = 0; c11_i72 < 4; c11_i72++) {
    c11_qparts[c11_i72] /= c11_n;
  }

  if (c11_qparts[0] < 0.0) {
    for (c11_i74 = 0; c11_i74 < 4; c11_i74++) {
      if (c11_idx[c11_i74] != (real_T)(int32_T)muDoubleScalarFloor
          (c11_idx[c11_i74])) {
        emlrtIntegerCheckR2012b(c11_idx[c11_i74], &c11_c_emlrtDCI, &c11_st);
      }

      c11_i76 = (int32_T)c11_idx[c11_i74];
      if ((c11_i76 < 1) || (c11_i76 > 28)) {
        emlrtDynamicBoundsCheckR2012b(c11_i76, 1, 28, &c11_c_emlrtBCI, &c11_st);
      }

      c11_xk[c11_i76 - 1] = -c11_qparts[c11_i74];
    }
  } else {
    for (c11_i73 = 0; c11_i73 < 4; c11_i73++) {
      if (c11_idx[c11_i73] != (real_T)(int32_T)muDoubleScalarFloor
          (c11_idx[c11_i73])) {
        emlrtIntegerCheckR2012b(c11_idx[c11_i73], &c11_b_emlrtDCI, &c11_st);
      }

      c11_i75 = (int32_T)c11_idx[c11_i73];
      if ((c11_i75 < 1) || (c11_i75 > 28)) {
        emlrtDynamicBoundsCheckR2012b(c11_i75, 1, 28, &c11_b_emlrtBCI, &c11_st);
      }

      c11_xk[c11_i75 - 1] = c11_qparts[c11_i73];
    }
  }

  c11_st.site = &c11_bc_emlrtRSI;
  c11_AsyncMARGGPSFuserBase_setStateCovariance(chartInstance, &c11_st, c11_obj,
    c11_P);
  c11_st.site = &c11_cc_emlrtRSI;
  c11_AsyncMARGGPSFuserBase_setState(chartInstance, &c11_st, c11_obj, c11_xk);
}

static void c11_mtimes(SFc11_car_model_FIXEDInstanceStruct *chartInstance,
  real_T c11_A[784], real_T c11_B[784], real_T c11_C[784])
{
  ptrdiff_t c11_k_t;
  ptrdiff_t c11_lda_t;
  ptrdiff_t c11_ldb_t;
  ptrdiff_t c11_ldc_t;
  ptrdiff_t c11_m_t;
  ptrdiff_t c11_n_t;
  real_T c11_alpha1;
  real_T c11_beta1;
  char_T c11_TRANSA1;
  char_T c11_TRANSB1;
  (void)chartInstance;
  c11_TRANSB1 = 'N';
  c11_TRANSA1 = 'N';
  c11_alpha1 = 1.0;
  c11_beta1 = 0.0;
  c11_m_t = (ptrdiff_t)28;
  c11_n_t = (ptrdiff_t)28;
  c11_k_t = (ptrdiff_t)28;
  c11_lda_t = (ptrdiff_t)28;
  c11_ldb_t = (ptrdiff_t)28;
  c11_ldc_t = (ptrdiff_t)28;
  dgemm(&c11_TRANSA1, &c11_TRANSB1, &c11_m_t, &c11_n_t, &c11_k_t, &c11_alpha1,
        &c11_A[0], &c11_lda_t, &c11_B[0], &c11_ldb_t, &c11_beta1, &c11_C[0],
        &c11_ldc_t);
}

static real_T c11_sumColumnB(SFc11_car_model_FIXEDInstanceStruct *chartInstance,
  real_T c11_x[4], int32_T c11_col)
{
  real_T c11_y;
  int32_T c11_b_col;
  int32_T c11_b_k;
  int32_T c11_i0;
  int32_T c11_k;
  (void)chartInstance;
  c11_b_col = c11_col - 1;
  c11_i0 = c11_b_col << 2;
  c11_y = c11_x[c11_i0];
  for (c11_k = 0; c11_k < 3; c11_k++) {
    c11_b_k = c11_k;
    c11_y += c11_x[(c11_i0 + c11_b_k) + 1];
  }

  return c11_y;
}

static real_T c11_sqrt(SFc11_car_model_FIXEDInstanceStruct *chartInstance, const
  emlrtStack *c11_sp, real_T c11_x)
{
  real_T c11_b_x;
  c11_b_x = c11_x;
  c11_b_sqrt(chartInstance, c11_sp, &c11_b_x);
  return c11_b_x;
}

static void c11_AsyncMARGGPSFuserBase_fuseaccel
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance, const emlrtStack *c11_sp,
   c11_insfilterAsync *c11_obj, real_T c11_accel[3], real_T c11_Raccel)
{
  c11_insfilterAsync *c11_b_obj;
  c11_insfilterAsync *c11_c_obj;
  c11_insfilterAsync *c11_d_obj;
  emlrtStack c11_b_st;
  emlrtStack c11_st;
  real_T c11_P[784];
  real_T c11_dhdx[84];
  real_T c11_xk[28];
  real_T c11_Raccelmat[9];
  real_T c11_innovCov[9];
  real_T c11_grav[3];
  real_T c11_h[3];
  real_T c11_z[3];
  real_T c11_Rin;
  real_T c11_a;
  real_T c11_ab_a;
  real_T c11_ac_a;
  real_T c11_ad;
  real_T c11_ae;
  real_T c11_an;
  real_T c11_b_Rin;
  real_T c11_b_a;
  real_T c11_b_c;
  real_T c11_bb_a;
  real_T c11_bc_a;
  real_T c11_c;
  real_T c11_c_a;
  real_T c11_c_c;
  real_T c11_cb_a;
  real_T c11_cc_a;
  real_T c11_d_a;
  real_T c11_d_c;
  real_T c11_db_a;
  real_T c11_dc_a;
  real_T c11_e_a;
  real_T c11_e_c;
  real_T c11_eb_a;
  real_T c11_ec_a;
  real_T c11_f_a;
  real_T c11_f_c;
  real_T c11_fb_a;
  real_T c11_fc_a;
  real_T c11_g_a;
  real_T c11_g_c;
  real_T c11_gb_a;
  real_T c11_gc_a;
  real_T c11_gnavx;
  real_T c11_gnavy;
  real_T c11_gnavz;
  real_T c11_h_a;
  real_T c11_h_c;
  real_T c11_hb_a;
  real_T c11_hc_a;
  real_T c11_i_a;
  real_T c11_i_c;
  real_T c11_ib_a;
  real_T c11_ic_a;
  real_T c11_j_a;
  real_T c11_j_c;
  real_T c11_jb_a;
  real_T c11_jc_a;
  real_T c11_k_a;
  real_T c11_k_c;
  real_T c11_kb_a;
  real_T c11_kc_a;
  real_T c11_l_a;
  real_T c11_l_c;
  real_T c11_lb_a;
  real_T c11_m_a;
  real_T c11_magE;
  real_T c11_magN;
  real_T c11_mb_a;
  real_T c11_n_a;
  real_T c11_nb_a;
  real_T c11_o_a;
  real_T c11_ob_a;
  real_T c11_p_a;
  real_T c11_pb_a;
  real_T c11_q0;
  real_T c11_q1;
  real_T c11_q2;
  real_T c11_q3;
  real_T c11_q_a;
  real_T c11_qb_a;
  real_T c11_r_a;
  real_T c11_rb_a;
  real_T c11_s_a;
  real_T c11_sb_a;
  real_T c11_t_a;
  real_T c11_tb_a;
  real_T c11_u_a;
  real_T c11_ub_a;
  real_T c11_v_a;
  real_T c11_vb_a;
  real_T c11_w_a;
  real_T c11_wb_a;
  real_T c11_x_a;
  real_T c11_xb_a;
  real_T c11_y_a;
  real_T c11_yb_a;
  int32_T c11_b_j;
  int32_T c11_i;
  int32_T c11_i1;
  int32_T c11_i2;
  int32_T c11_i3;
  int32_T c11_i4;
  int32_T c11_i5;
  int32_T c11_j;
  c11_st.prev = c11_sp;
  c11_st.tls = c11_sp->tls;
  c11_b_st.prev = &c11_st;
  c11_b_st.tls = c11_st.tls;
  c11_Rin = c11_Raccel;
  c11_b_Rin = c11_Rin;
  c11_a = c11_b_Rin;
  for (c11_i = 0; c11_i < 3; c11_i++) {
    c11_grav[c11_i] = c11_a;
  }

  for (c11_i1 = 0; c11_i1 < 9; c11_i1++) {
    c11_Raccelmat[c11_i1] = 0.0;
  }

  for (c11_j = 0; c11_j < 3; c11_j++) {
    c11_b_j = c11_j;
    c11_Raccelmat[c11_b_j + 3 * c11_b_j] = c11_grav[c11_b_j];
  }

  for (c11_i2 = 0; c11_i2 < 3; c11_i2++) {
    c11_z[c11_i2] = c11_accel[c11_i2];
  }

  c11_st.site = &c11_ic_emlrtRSI;
  c11_b_obj = c11_obj;
  c11_b_st.site = &c11_jc_emlrtRSI;
  c11_c_obj = c11_b_obj;
  for (c11_i3 = 0; c11_i3 < 28; c11_i3++) {
    c11_xk[c11_i3] = c11_c_obj->pState[c11_i3];
  }

  c11_magN = c11_xk[22];
  c11_magE = c11_xk[23];
  c11_xk[22] = c11_magN;
  c11_xk[23] = c11_magE;
  c11_b_st.site = &c11_kc_emlrtRSI;
  c11_AsyncMARGGPSFuserBase_accelMeasFcn(chartInstance, c11_xk, c11_h);
  c11_b_st.site = &c11_lc_emlrtRSI;
  c11_q0 = c11_xk[0];
  c11_q1 = c11_xk[1];
  c11_q2 = c11_xk[2];
  c11_q3 = c11_xk[3];
  c11_an = c11_xk[13];
  c11_ae = c11_xk[14];
  c11_ad = c11_xk[15];
  for (c11_i4 = 0; c11_i4 < 3; c11_i4++) {
    c11_grav[c11_i4] = 0.0;
  }

  c11_grav[2] = 9.81;
  c11_gnavx = c11_grav[0];
  c11_gnavy = c11_grav[1];
  c11_gnavz = c11_grav[2];
  c11_b_a = c11_q0;
  c11_c_a = c11_b_a;
  c11_d_a = c11_c_a;
  c11_e_a = c11_d_a;
  c11_f_a = c11_e_a;
  c11_c = c11_f_a * c11_f_a;
  c11_g_a = c11_q1;
  c11_h_a = c11_g_a;
  c11_i_a = c11_h_a;
  c11_j_a = c11_i_a;
  c11_k_a = c11_j_a;
  c11_b_c = c11_k_a * c11_k_a;
  c11_l_a = c11_q2;
  c11_m_a = c11_l_a;
  c11_n_a = c11_m_a;
  c11_o_a = c11_n_a;
  c11_p_a = c11_o_a;
  c11_c_c = c11_p_a * c11_p_a;
  c11_q_a = c11_q3;
  c11_r_a = c11_q_a;
  c11_s_a = c11_r_a;
  c11_t_a = c11_s_a;
  c11_u_a = c11_t_a;
  c11_d_c = c11_u_a * c11_u_a;
  c11_v_a = c11_q0;
  c11_w_a = c11_v_a;
  c11_x_a = c11_w_a;
  c11_y_a = c11_x_a;
  c11_ab_a = c11_y_a;
  c11_e_c = c11_ab_a * c11_ab_a;
  c11_bb_a = c11_q1;
  c11_cb_a = c11_bb_a;
  c11_db_a = c11_cb_a;
  c11_eb_a = c11_db_a;
  c11_fb_a = c11_eb_a;
  c11_f_c = c11_fb_a * c11_fb_a;
  c11_gb_a = c11_q2;
  c11_hb_a = c11_gb_a;
  c11_ib_a = c11_hb_a;
  c11_jb_a = c11_ib_a;
  c11_kb_a = c11_jb_a;
  c11_g_c = c11_kb_a * c11_kb_a;
  c11_lb_a = c11_q3;
  c11_mb_a = c11_lb_a;
  c11_nb_a = c11_mb_a;
  c11_ob_a = c11_nb_a;
  c11_pb_a = c11_ob_a;
  c11_h_c = c11_pb_a * c11_pb_a;
  c11_qb_a = c11_q0;
  c11_rb_a = c11_qb_a;
  c11_sb_a = c11_rb_a;
  c11_tb_a = c11_sb_a;
  c11_ub_a = c11_tb_a;
  c11_i_c = c11_ub_a * c11_ub_a;
  c11_vb_a = c11_q1;
  c11_wb_a = c11_vb_a;
  c11_xb_a = c11_wb_a;
  c11_yb_a = c11_xb_a;
  c11_ac_a = c11_yb_a;
  c11_j_c = c11_ac_a * c11_ac_a;
  c11_bc_a = c11_q2;
  c11_cc_a = c11_bc_a;
  c11_dc_a = c11_cc_a;
  c11_ec_a = c11_dc_a;
  c11_fc_a = c11_ec_a;
  c11_k_c = c11_fc_a * c11_fc_a;
  c11_gc_a = c11_q3;
  c11_hc_a = c11_gc_a;
  c11_ic_a = c11_hc_a;
  c11_jc_a = c11_ic_a;
  c11_kc_a = c11_jc_a;
  c11_l_c = c11_kc_a * c11_kc_a;
  c11_dhdx[0] = (2.0 * c11_q2 * (c11_ad - c11_gnavz) - 2.0 * c11_q3 * (c11_ae -
    c11_gnavy)) - 2.0 * c11_q0 * (c11_an - c11_gnavx);
  c11_dhdx[3] = (-2.0 * c11_q3 * (c11_ad - c11_gnavz) - 2.0 * c11_q2 * (c11_ae -
    c11_gnavy)) - 2.0 * c11_q1 * (c11_an - c11_gnavx);
  c11_dhdx[6] = (2.0 * c11_q0 * (c11_ad - c11_gnavz) - 2.0 * c11_q1 * (c11_ae -
    c11_gnavy)) + 2.0 * c11_q2 * (c11_an - c11_gnavx);
  c11_dhdx[9] = (2.0 * c11_q3 * (c11_an - c11_gnavx) - 2.0 * c11_q0 * (c11_ae -
    c11_gnavy)) - 2.0 * c11_q1 * (c11_ad - c11_gnavz);
  c11_dhdx[12] = 0.0;
  c11_dhdx[15] = 0.0;
  c11_dhdx[18] = 0.0;
  c11_dhdx[21] = 0.0;
  c11_dhdx[24] = 0.0;
  c11_dhdx[27] = 0.0;
  c11_dhdx[30] = 0.0;
  c11_dhdx[33] = 0.0;
  c11_dhdx[36] = 0.0;
  c11_dhdx[39] = ((-c11_c - c11_b_c) + c11_c_c) + c11_d_c;
  c11_dhdx[42] = -2.0 * c11_q0 * c11_q3 - 2.0 * c11_q1 * c11_q2;
  c11_dhdx[45] = 2.0 * c11_q0 * c11_q2 - 2.0 * c11_q1 * c11_q3;
  c11_dhdx[48] = 1.0;
  c11_dhdx[51] = 0.0;
  c11_dhdx[54] = 0.0;
  c11_dhdx[57] = 0.0;
  c11_dhdx[60] = 0.0;
  c11_dhdx[63] = 0.0;
  c11_dhdx[66] = 0.0;
  c11_dhdx[69] = 0.0;
  c11_dhdx[72] = 0.0;
  c11_dhdx[75] = 0.0;
  c11_dhdx[78] = 0.0;
  c11_dhdx[81] = 0.0;
  c11_dhdx[1] = (2.0 * c11_q3 * (c11_an - c11_gnavx) - 2.0 * c11_q0 * (c11_ae -
    c11_gnavy)) - 2.0 * c11_q1 * (c11_ad - c11_gnavz);
  c11_dhdx[4] = (2.0 * c11_q1 * (c11_ae - c11_gnavy) - 2.0 * c11_q0 * (c11_ad -
    c11_gnavz)) - 2.0 * c11_q2 * (c11_an - c11_gnavx);
  c11_dhdx[7] = (-2.0 * c11_q3 * (c11_ad - c11_gnavz) - 2.0 * c11_q2 * (c11_ae -
    c11_gnavy)) - 2.0 * c11_q1 * (c11_an - c11_gnavx);
  c11_dhdx[10] = (2.0 * c11_q3 * (c11_ae - c11_gnavy) - 2.0 * c11_q2 * (c11_ad -
    c11_gnavz)) + 2.0 * c11_q0 * (c11_an - c11_gnavx);
  c11_dhdx[13] = 0.0;
  c11_dhdx[16] = 0.0;
  c11_dhdx[19] = 0.0;
  c11_dhdx[22] = 0.0;
  c11_dhdx[25] = 0.0;
  c11_dhdx[28] = 0.0;
  c11_dhdx[31] = 0.0;
  c11_dhdx[34] = 0.0;
  c11_dhdx[37] = 0.0;
  c11_dhdx[40] = 2.0 * c11_q0 * c11_q3 - 2.0 * c11_q1 * c11_q2;
  c11_dhdx[43] = ((-c11_e_c + c11_f_c) - c11_g_c) + c11_h_c;
  c11_dhdx[46] = -2.0 * c11_q0 * c11_q1 - 2.0 * c11_q2 * c11_q3;
  c11_dhdx[49] = 0.0;
  c11_dhdx[52] = 1.0;
  c11_dhdx[55] = 0.0;
  c11_dhdx[58] = 0.0;
  c11_dhdx[61] = 0.0;
  c11_dhdx[64] = 0.0;
  c11_dhdx[67] = 0.0;
  c11_dhdx[70] = 0.0;
  c11_dhdx[73] = 0.0;
  c11_dhdx[76] = 0.0;
  c11_dhdx[79] = 0.0;
  c11_dhdx[82] = 0.0;
  c11_dhdx[2] = (2.0 * c11_q1 * (c11_ae - c11_gnavy) - 2.0 * c11_q0 * (c11_ad -
    c11_gnavz)) - 2.0 * c11_q2 * (c11_an - c11_gnavx);
  c11_dhdx[5] = (2.0 * c11_q1 * (c11_ad - c11_gnavz) + 2.0 * c11_q0 * (c11_ae -
    c11_gnavy)) - 2.0 * c11_q3 * (c11_an - c11_gnavx);
  c11_dhdx[8] = (2.0 * c11_q2 * (c11_ad - c11_gnavz) - 2.0 * c11_q3 * (c11_ae -
    c11_gnavy)) - 2.0 * c11_q0 * (c11_an - c11_gnavx);
  c11_dhdx[11] = (-2.0 * c11_q3 * (c11_ad - c11_gnavz) - 2.0 * c11_q2 * (c11_ae
    - c11_gnavy)) - 2.0 * c11_q1 * (c11_an - c11_gnavx);
  c11_dhdx[14] = 0.0;
  c11_dhdx[17] = 0.0;
  c11_dhdx[20] = 0.0;
  c11_dhdx[23] = 0.0;
  c11_dhdx[26] = 0.0;
  c11_dhdx[29] = 0.0;
  c11_dhdx[32] = 0.0;
  c11_dhdx[35] = 0.0;
  c11_dhdx[38] = 0.0;
  c11_dhdx[41] = -2.0 * c11_q0 * c11_q2 - 2.0 * c11_q1 * c11_q3;
  c11_dhdx[44] = 2.0 * c11_q0 * c11_q1 - 2.0 * c11_q2 * c11_q3;
  c11_dhdx[47] = ((-c11_i_c + c11_j_c) + c11_k_c) - c11_l_c;
  c11_dhdx[50] = 0.0;
  c11_dhdx[53] = 0.0;
  c11_dhdx[56] = 1.0;
  c11_dhdx[59] = 0.0;
  c11_dhdx[62] = 0.0;
  c11_dhdx[65] = 0.0;
  c11_dhdx[68] = 0.0;
  c11_dhdx[71] = 0.0;
  c11_dhdx[74] = 0.0;
  c11_dhdx[77] = 0.0;
  c11_dhdx[80] = 0.0;
  c11_dhdx[83] = 0.0;
  c11_b_st.site = &c11_mc_emlrtRSI;
  c11_d_obj = c11_b_obj;
  for (c11_i5 = 0; c11_i5 < 784; c11_i5++) {
    c11_P[c11_i5] = c11_d_obj->pStateCovariance[c11_i5];
  }

  c11_b_st.site = &c11_nc_emlrtRSI;
  c11_b_BasicEKF_correctEqn(chartInstance, &c11_b_st, c11_b_obj, c11_xk, c11_P,
    c11_h, c11_dhdx, c11_z, c11_Raccelmat, c11_grav, c11_innovCov);
  c11_b_st.site = &c11_oc_emlrtRSI;
  c11_AsyncMARGGPSFuserBase_setStateCovariance(chartInstance, &c11_b_st,
    c11_b_obj, c11_P);
  c11_b_st.site = &c11_pc_emlrtRSI;
  c11_AsyncMARGGPSFuserBase_setState(chartInstance, &c11_b_st, c11_b_obj, c11_xk);
}

static void c11_AsyncMARGGPSFuserBase_accelMeasFcn
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance, real_T c11_x[28], real_T
   c11_z[3])
{
  real_T c11_grav[3];
  real_T c11_a;
  real_T c11_ab_a;
  real_T c11_ac_a;
  real_T c11_accx_b;
  real_T c11_accy_b;
  real_T c11_accz_b;
  real_T c11_ad;
  real_T c11_ae;
  real_T c11_an;
  real_T c11_b_a;
  real_T c11_b_c;
  real_T c11_bb_a;
  real_T c11_bc_a;
  real_T c11_c;
  real_T c11_c_a;
  real_T c11_c_c;
  real_T c11_cb_a;
  real_T c11_cc_a;
  real_T c11_d_a;
  real_T c11_d_c;
  real_T c11_db_a;
  real_T c11_dc_a;
  real_T c11_e_a;
  real_T c11_e_c;
  real_T c11_eb_a;
  real_T c11_ec_a;
  real_T c11_f_a;
  real_T c11_f_c;
  real_T c11_fb_a;
  real_T c11_fc_a;
  real_T c11_g_a;
  real_T c11_g_c;
  real_T c11_gb_a;
  real_T c11_gc_a;
  real_T c11_gnavx;
  real_T c11_gnavy;
  real_T c11_gnavz;
  real_T c11_h_a;
  real_T c11_h_c;
  real_T c11_hb_a;
  real_T c11_hc_a;
  real_T c11_i_a;
  real_T c11_i_c;
  real_T c11_ib_a;
  real_T c11_ic_a;
  real_T c11_j_a;
  real_T c11_j_c;
  real_T c11_jb_a;
  real_T c11_jc_a;
  real_T c11_k_a;
  real_T c11_k_c;
  real_T c11_kb_a;
  real_T c11_l_a;
  real_T c11_l_c;
  real_T c11_lb_a;
  real_T c11_m_a;
  real_T c11_mb_a;
  real_T c11_n_a;
  real_T c11_nb_a;
  real_T c11_o_a;
  real_T c11_ob_a;
  real_T c11_p_a;
  real_T c11_pb_a;
  real_T c11_q0;
  real_T c11_q1;
  real_T c11_q2;
  real_T c11_q3;
  real_T c11_q_a;
  real_T c11_qb_a;
  real_T c11_r_a;
  real_T c11_rb_a;
  real_T c11_s_a;
  real_T c11_sb_a;
  real_T c11_t_a;
  real_T c11_tb_a;
  real_T c11_u_a;
  real_T c11_ub_a;
  real_T c11_v_a;
  real_T c11_vb_a;
  real_T c11_w_a;
  real_T c11_wb_a;
  real_T c11_x_a;
  real_T c11_xb_a;
  real_T c11_y_a;
  real_T c11_yb_a;
  int32_T c11_i;
  (void)chartInstance;
  c11_q0 = c11_x[0];
  c11_q1 = c11_x[1];
  c11_q2 = c11_x[2];
  c11_q3 = c11_x[3];
  c11_an = c11_x[13];
  c11_ae = c11_x[14];
  c11_ad = c11_x[15];
  c11_accx_b = c11_x[16];
  c11_accy_b = c11_x[17];
  c11_accz_b = c11_x[18];
  for (c11_i = 0; c11_i < 3; c11_i++) {
    c11_grav[c11_i] = 0.0;
  }

  c11_grav[2] = 9.81;
  c11_gnavx = c11_grav[0];
  c11_gnavy = c11_grav[1];
  c11_gnavz = c11_grav[2];
  c11_a = c11_q0;
  c11_b_a = c11_a;
  c11_c_a = c11_b_a;
  c11_d_a = c11_c_a;
  c11_e_a = c11_d_a;
  c11_c = c11_e_a * c11_e_a;
  c11_f_a = c11_q1;
  c11_g_a = c11_f_a;
  c11_h_a = c11_g_a;
  c11_i_a = c11_h_a;
  c11_j_a = c11_i_a;
  c11_b_c = c11_j_a * c11_j_a;
  c11_k_a = c11_q2;
  c11_l_a = c11_k_a;
  c11_m_a = c11_l_a;
  c11_n_a = c11_m_a;
  c11_o_a = c11_n_a;
  c11_c_c = c11_o_a * c11_o_a;
  c11_p_a = c11_q3;
  c11_q_a = c11_p_a;
  c11_r_a = c11_q_a;
  c11_s_a = c11_r_a;
  c11_t_a = c11_s_a;
  c11_d_c = c11_t_a * c11_t_a;
  c11_u_a = c11_q0;
  c11_v_a = c11_u_a;
  c11_w_a = c11_v_a;
  c11_x_a = c11_w_a;
  c11_y_a = c11_x_a;
  c11_e_c = c11_y_a * c11_y_a;
  c11_ab_a = c11_q1;
  c11_bb_a = c11_ab_a;
  c11_cb_a = c11_bb_a;
  c11_db_a = c11_cb_a;
  c11_eb_a = c11_db_a;
  c11_f_c = c11_eb_a * c11_eb_a;
  c11_fb_a = c11_q2;
  c11_gb_a = c11_fb_a;
  c11_hb_a = c11_gb_a;
  c11_ib_a = c11_hb_a;
  c11_jb_a = c11_ib_a;
  c11_g_c = c11_jb_a * c11_jb_a;
  c11_kb_a = c11_q3;
  c11_lb_a = c11_kb_a;
  c11_mb_a = c11_lb_a;
  c11_nb_a = c11_mb_a;
  c11_ob_a = c11_nb_a;
  c11_h_c = c11_ob_a * c11_ob_a;
  c11_pb_a = c11_q0;
  c11_qb_a = c11_pb_a;
  c11_rb_a = c11_qb_a;
  c11_sb_a = c11_rb_a;
  c11_tb_a = c11_sb_a;
  c11_i_c = c11_tb_a * c11_tb_a;
  c11_ub_a = c11_q1;
  c11_vb_a = c11_ub_a;
  c11_wb_a = c11_vb_a;
  c11_xb_a = c11_wb_a;
  c11_yb_a = c11_xb_a;
  c11_j_c = c11_yb_a * c11_yb_a;
  c11_ac_a = c11_q2;
  c11_bc_a = c11_ac_a;
  c11_cc_a = c11_bc_a;
  c11_dc_a = c11_cc_a;
  c11_ec_a = c11_dc_a;
  c11_k_c = c11_ec_a * c11_ec_a;
  c11_fc_a = c11_q3;
  c11_gc_a = c11_fc_a;
  c11_hc_a = c11_gc_a;
  c11_ic_a = c11_hc_a;
  c11_jc_a = c11_ic_a;
  c11_l_c = c11_jc_a * c11_jc_a;
  c11_z[0] = ((c11_accx_b - (c11_an - c11_gnavx) * (((c11_c + c11_b_c) - c11_c_c)
    - c11_d_c)) + (c11_ad - c11_gnavz) * (2.0 * c11_q0 * c11_q2 - 2.0 * c11_q1 *
    c11_q3)) - (c11_ae - c11_gnavy) * (2.0 * c11_q0 * c11_q3 + 2.0 * c11_q1 *
    c11_q2);
  c11_z[1] = ((c11_accy_b - (c11_ae - c11_gnavy) * (((c11_e_c - c11_f_c) +
    c11_g_c) - c11_h_c)) - (c11_ad - c11_gnavz) * (2.0 * c11_q0 * c11_q1 + 2.0 *
    c11_q2 * c11_q3)) + (c11_an - c11_gnavx) * (2.0 * c11_q0 * c11_q3 - 2.0 *
    c11_q1 * c11_q2);
  c11_z[2] = ((c11_accz_b - (c11_ad - c11_gnavz) * (((c11_i_c - c11_j_c) -
    c11_k_c) + c11_l_c)) + (c11_ae - c11_gnavy) * (2.0 * c11_q0 * c11_q1 - 2.0 *
    c11_q2 * c11_q3)) - (c11_an - c11_gnavx) * (2.0 * c11_q0 * c11_q2 + 2.0 *
    c11_q1 * c11_q3);
}

static void c11_BasicEKF_correctEqn(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, const emlrtStack *c11_sp, c11_insfilterAsync *c11_obj, real_T
  c11_x[28], real_T c11_P[784], real_T c11_h[3], real_T c11_H[84], real_T c11_z
  [3], real_T c11_R[9], real_T c11_b_x[28], real_T c11_b_P[784], real_T
  c11_innov[3], real_T c11_innovCov[9])
{
  real_T c11_b_H[84];
  real_T c11_b_R[9];
  real_T c11_b_h[3];
  real_T c11_b_z[3];
  int32_T c11_i;
  int32_T c11_i1;
  int32_T c11_i2;
  int32_T c11_i3;
  int32_T c11_i4;
  int32_T c11_i5;
  for (c11_i = 0; c11_i < 28; c11_i++) {
    c11_b_x[c11_i] = c11_x[c11_i];
  }

  for (c11_i1 = 0; c11_i1 < 784; c11_i1++) {
    c11_b_P[c11_i1] = c11_P[c11_i1];
  }

  for (c11_i2 = 0; c11_i2 < 3; c11_i2++) {
    c11_b_h[c11_i2] = c11_h[c11_i2];
  }

  for (c11_i3 = 0; c11_i3 < 84; c11_i3++) {
    c11_b_H[c11_i3] = c11_H[c11_i3];
  }

  for (c11_i4 = 0; c11_i4 < 3; c11_i4++) {
    c11_b_z[c11_i4] = c11_z[c11_i4];
  }

  for (c11_i5 = 0; c11_i5 < 9; c11_i5++) {
    c11_b_R[c11_i5] = c11_R[c11_i5];
  }

  c11_b_BasicEKF_correctEqn(chartInstance, c11_sp, c11_obj, c11_b_x, c11_b_P,
    c11_b_h, c11_b_H, c11_b_z, c11_b_R, c11_innov, c11_innovCov);
}

static void c11_warning(SFc11_car_model_FIXEDInstanceStruct *chartInstance,
  const emlrtStack *c11_sp)
{
  static char_T c11_msgID[21] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'i',
    'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a', 't', 'r', 'i', 'x' };

  static char_T c11_b_cv[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  static char_T c11_b_cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  emlrtStack c11_st;
  const mxArray *c11_b_y = NULL;
  const mxArray *c11_c_y = NULL;
  const mxArray *c11_y = NULL;
  c11_st.prev = c11_sp;
  c11_st.tls = c11_sp->tls;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_b_cv, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_b_cv1, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c11_c_y = NULL;
  sf_mex_assign(&c11_c_y, sf_mex_create("y", c11_msgID, 10, 0U, 1U, 0U, 2, 1, 21),
                false);
  c11_st.site = &c11_kd_emlrtRSI;
  c11_b_feval(chartInstance, &c11_st, c11_y, c11_feval(chartInstance, &c11_st,
    c11_b_y, c11_c_y));
}

static void c11_AsyncMARGGPSFuserBase_fusemag
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance, const emlrtStack *c11_sp,
   c11_insfilterAsync *c11_obj, real_T c11_mag[3], real_T c11_Rmag)
{
  c11_insfilterAsync *c11_b_obj;
  c11_insfilterAsync *c11_c_obj;
  c11_insfilterAsync *c11_d_obj;
  emlrtStack c11_b_st;
  emlrtStack c11_st;
  real_T c11_P[784];
  real_T c11_dhdx[84];
  real_T c11_xk[28];
  real_T c11_Rmagmat[9];
  real_T c11_innovCov[9];
  real_T c11_h[3];
  real_T c11_innov[3];
  real_T c11_z[3];
  real_T c11_Rin;
  real_T c11_a;
  real_T c11_ab_a;
  real_T c11_ac_a;
  real_T c11_b_Rin;
  real_T c11_b_a;
  real_T c11_b_c;
  real_T c11_bb_a;
  real_T c11_bc_a;
  real_T c11_c;
  real_T c11_c_a;
  real_T c11_c_c;
  real_T c11_cb_a;
  real_T c11_cc_a;
  real_T c11_d_a;
  real_T c11_d_c;
  real_T c11_db_a;
  real_T c11_dc_a;
  real_T c11_e_a;
  real_T c11_e_c;
  real_T c11_eb_a;
  real_T c11_ec_a;
  real_T c11_f_a;
  real_T c11_f_c;
  real_T c11_fb_a;
  real_T c11_fc_a;
  real_T c11_g_a;
  real_T c11_g_c;
  real_T c11_gb_a;
  real_T c11_gc_a;
  real_T c11_h_a;
  real_T c11_h_c;
  real_T c11_hb_a;
  real_T c11_hc_a;
  real_T c11_i_a;
  real_T c11_i_c;
  real_T c11_ib_a;
  real_T c11_ic_a;
  real_T c11_j_a;
  real_T c11_j_c;
  real_T c11_jb_a;
  real_T c11_jc_a;
  real_T c11_k_a;
  real_T c11_k_c;
  real_T c11_kb_a;
  real_T c11_kc_a;
  real_T c11_l_a;
  real_T c11_l_c;
  real_T c11_lb_a;
  real_T c11_m_a;
  real_T c11_magE;
  real_T c11_magN;
  real_T c11_magNavX;
  real_T c11_magNavY;
  real_T c11_magNavZ;
  real_T c11_mb_a;
  real_T c11_n_a;
  real_T c11_nb_a;
  real_T c11_o_a;
  real_T c11_ob_a;
  real_T c11_p_a;
  real_T c11_pb_a;
  real_T c11_q0;
  real_T c11_q1;
  real_T c11_q2;
  real_T c11_q3;
  real_T c11_q_a;
  real_T c11_qb_a;
  real_T c11_r_a;
  real_T c11_rb_a;
  real_T c11_s_a;
  real_T c11_sb_a;
  real_T c11_t_a;
  real_T c11_tb_a;
  real_T c11_u_a;
  real_T c11_ub_a;
  real_T c11_v_a;
  real_T c11_vb_a;
  real_T c11_w_a;
  real_T c11_wb_a;
  real_T c11_x_a;
  real_T c11_xb_a;
  real_T c11_y_a;
  real_T c11_yb_a;
  int32_T c11_b_j;
  int32_T c11_i;
  int32_T c11_i1;
  int32_T c11_i2;
  int32_T c11_i3;
  int32_T c11_i4;
  int32_T c11_j;
  c11_st.prev = c11_sp;
  c11_st.tls = c11_sp->tls;
  c11_b_st.prev = &c11_st;
  c11_b_st.tls = c11_st.tls;
  c11_Rin = c11_Rmag;
  c11_b_Rin = c11_Rin;
  c11_a = c11_b_Rin;
  for (c11_i = 0; c11_i < 3; c11_i++) {
    c11_z[c11_i] = c11_a;
  }

  for (c11_i1 = 0; c11_i1 < 9; c11_i1++) {
    c11_Rmagmat[c11_i1] = 0.0;
  }

  for (c11_j = 0; c11_j < 3; c11_j++) {
    c11_b_j = c11_j;
    c11_Rmagmat[c11_b_j + 3 * c11_b_j] = c11_z[c11_b_j];
  }

  for (c11_i2 = 0; c11_i2 < 3; c11_i2++) {
    c11_z[c11_i2] = c11_mag[c11_i2];
  }

  c11_st.site = &c11_md_emlrtRSI;
  c11_b_obj = c11_obj;
  c11_b_st.site = &c11_jc_emlrtRSI;
  c11_c_obj = c11_b_obj;
  for (c11_i3 = 0; c11_i3 < 28; c11_i3++) {
    c11_xk[c11_i3] = c11_c_obj->pState[c11_i3];
  }

  c11_magN = c11_xk[22];
  c11_magE = c11_xk[23];
  c11_xk[22] = c11_magN;
  c11_xk[23] = c11_magE;
  c11_b_st.site = &c11_kc_emlrtRSI;
  c11_AsyncMARGGPSFuserBase_magMeasFcn(chartInstance, c11_xk, c11_h);
  c11_b_st.site = &c11_lc_emlrtRSI;
  c11_q0 = c11_xk[0];
  c11_q1 = c11_xk[1];
  c11_q2 = c11_xk[2];
  c11_q3 = c11_xk[3];
  c11_magNavX = c11_xk[22];
  c11_magNavY = c11_xk[23];
  c11_magNavZ = c11_xk[24];
  c11_b_a = c11_q0;
  c11_c_a = c11_b_a;
  c11_d_a = c11_c_a;
  c11_e_a = c11_d_a;
  c11_f_a = c11_e_a;
  c11_c = c11_f_a * c11_f_a;
  c11_g_a = c11_q1;
  c11_h_a = c11_g_a;
  c11_i_a = c11_h_a;
  c11_j_a = c11_i_a;
  c11_k_a = c11_j_a;
  c11_b_c = c11_k_a * c11_k_a;
  c11_l_a = c11_q2;
  c11_m_a = c11_l_a;
  c11_n_a = c11_m_a;
  c11_o_a = c11_n_a;
  c11_p_a = c11_o_a;
  c11_c_c = c11_p_a * c11_p_a;
  c11_q_a = c11_q3;
  c11_r_a = c11_q_a;
  c11_s_a = c11_r_a;
  c11_t_a = c11_s_a;
  c11_u_a = c11_t_a;
  c11_d_c = c11_u_a * c11_u_a;
  c11_v_a = c11_q0;
  c11_w_a = c11_v_a;
  c11_x_a = c11_w_a;
  c11_y_a = c11_x_a;
  c11_ab_a = c11_y_a;
  c11_e_c = c11_ab_a * c11_ab_a;
  c11_bb_a = c11_q1;
  c11_cb_a = c11_bb_a;
  c11_db_a = c11_cb_a;
  c11_eb_a = c11_db_a;
  c11_fb_a = c11_eb_a;
  c11_f_c = c11_fb_a * c11_fb_a;
  c11_gb_a = c11_q2;
  c11_hb_a = c11_gb_a;
  c11_ib_a = c11_hb_a;
  c11_jb_a = c11_ib_a;
  c11_kb_a = c11_jb_a;
  c11_g_c = c11_kb_a * c11_kb_a;
  c11_lb_a = c11_q3;
  c11_mb_a = c11_lb_a;
  c11_nb_a = c11_mb_a;
  c11_ob_a = c11_nb_a;
  c11_pb_a = c11_ob_a;
  c11_h_c = c11_pb_a * c11_pb_a;
  c11_qb_a = c11_q0;
  c11_rb_a = c11_qb_a;
  c11_sb_a = c11_rb_a;
  c11_tb_a = c11_sb_a;
  c11_ub_a = c11_tb_a;
  c11_i_c = c11_ub_a * c11_ub_a;
  c11_vb_a = c11_q1;
  c11_wb_a = c11_vb_a;
  c11_xb_a = c11_wb_a;
  c11_yb_a = c11_xb_a;
  c11_ac_a = c11_yb_a;
  c11_j_c = c11_ac_a * c11_ac_a;
  c11_bc_a = c11_q2;
  c11_cc_a = c11_bc_a;
  c11_dc_a = c11_cc_a;
  c11_ec_a = c11_dc_a;
  c11_fc_a = c11_ec_a;
  c11_k_c = c11_fc_a * c11_fc_a;
  c11_gc_a = c11_q3;
  c11_hc_a = c11_gc_a;
  c11_ic_a = c11_hc_a;
  c11_jc_a = c11_ic_a;
  c11_kc_a = c11_jc_a;
  c11_l_c = c11_kc_a * c11_kc_a;
  c11_dhdx[0] = (2.0 * c11_magNavY * c11_q3 - 2.0 * c11_magNavZ * c11_q2) + 2.0 *
    c11_magNavX * c11_q0;
  c11_dhdx[3] = (2.0 * c11_magNavZ * c11_q3 + 2.0 * c11_magNavY * c11_q2) + 2.0 *
    c11_magNavX * c11_q1;
  c11_dhdx[6] = (2.0 * c11_magNavY * c11_q1 - 2.0 * c11_magNavZ * c11_q0) - 2.0 *
    c11_magNavX * c11_q2;
  c11_dhdx[9] = (2.0 * c11_magNavZ * c11_q1 + 2.0 * c11_magNavY * c11_q0) - 2.0 *
    c11_magNavX * c11_q3;
  c11_dhdx[12] = 0.0;
  c11_dhdx[15] = 0.0;
  c11_dhdx[18] = 0.0;
  c11_dhdx[21] = 0.0;
  c11_dhdx[24] = 0.0;
  c11_dhdx[27] = 0.0;
  c11_dhdx[30] = 0.0;
  c11_dhdx[33] = 0.0;
  c11_dhdx[36] = 0.0;
  c11_dhdx[39] = 0.0;
  c11_dhdx[42] = 0.0;
  c11_dhdx[45] = 0.0;
  c11_dhdx[48] = 0.0;
  c11_dhdx[51] = 0.0;
  c11_dhdx[54] = 0.0;
  c11_dhdx[57] = 0.0;
  c11_dhdx[60] = 0.0;
  c11_dhdx[63] = 0.0;
  c11_dhdx[66] = ((c11_c + c11_b_c) - c11_c_c) - c11_d_c;
  c11_dhdx[69] = 2.0 * c11_q0 * c11_q3 + 2.0 * c11_q1 * c11_q2;
  c11_dhdx[72] = 2.0 * c11_q1 * c11_q3 - 2.0 * c11_q0 * c11_q2;
  c11_dhdx[75] = 1.0;
  c11_dhdx[78] = 0.0;
  c11_dhdx[81] = 0.0;
  c11_dhdx[1] = (2.0 * c11_magNavZ * c11_q1 + 2.0 * c11_magNavY * c11_q0) - 2.0 *
    c11_magNavX * c11_q3;
  c11_dhdx[4] = (2.0 * c11_magNavZ * c11_q0 - 2.0 * c11_magNavY * c11_q1) + 2.0 *
    c11_magNavX * c11_q2;
  c11_dhdx[7] = (2.0 * c11_magNavZ * c11_q3 + 2.0 * c11_magNavY * c11_q2) + 2.0 *
    c11_magNavX * c11_q1;
  c11_dhdx[10] = (2.0 * c11_magNavZ * c11_q2 - 2.0 * c11_magNavY * c11_q3) - 2.0
    * c11_magNavX * c11_q0;
  c11_dhdx[13] = 0.0;
  c11_dhdx[16] = 0.0;
  c11_dhdx[19] = 0.0;
  c11_dhdx[22] = 0.0;
  c11_dhdx[25] = 0.0;
  c11_dhdx[28] = 0.0;
  c11_dhdx[31] = 0.0;
  c11_dhdx[34] = 0.0;
  c11_dhdx[37] = 0.0;
  c11_dhdx[40] = 0.0;
  c11_dhdx[43] = 0.0;
  c11_dhdx[46] = 0.0;
  c11_dhdx[49] = 0.0;
  c11_dhdx[52] = 0.0;
  c11_dhdx[55] = 0.0;
  c11_dhdx[58] = 0.0;
  c11_dhdx[61] = 0.0;
  c11_dhdx[64] = 0.0;
  c11_dhdx[67] = 2.0 * c11_q1 * c11_q2 - 2.0 * c11_q0 * c11_q3;
  c11_dhdx[70] = ((c11_e_c - c11_f_c) + c11_g_c) - c11_h_c;
  c11_dhdx[73] = 2.0 * c11_q0 * c11_q1 + 2.0 * c11_q2 * c11_q3;
  c11_dhdx[76] = 0.0;
  c11_dhdx[79] = 1.0;
  c11_dhdx[82] = 0.0;
  c11_dhdx[2] = (2.0 * c11_magNavZ * c11_q0 - 2.0 * c11_magNavY * c11_q1) + 2.0 *
    c11_magNavX * c11_q2;
  c11_dhdx[5] = (2.0 * c11_magNavX * c11_q3 - 2.0 * c11_magNavY * c11_q0) - 2.0 *
    c11_magNavZ * c11_q1;
  c11_dhdx[8] = (2.0 * c11_magNavY * c11_q3 - 2.0 * c11_magNavZ * c11_q2) + 2.0 *
    c11_magNavX * c11_q0;
  c11_dhdx[11] = (2.0 * c11_magNavZ * c11_q3 + 2.0 * c11_magNavY * c11_q2) + 2.0
    * c11_magNavX * c11_q1;
  c11_dhdx[14] = 0.0;
  c11_dhdx[17] = 0.0;
  c11_dhdx[20] = 0.0;
  c11_dhdx[23] = 0.0;
  c11_dhdx[26] = 0.0;
  c11_dhdx[29] = 0.0;
  c11_dhdx[32] = 0.0;
  c11_dhdx[35] = 0.0;
  c11_dhdx[38] = 0.0;
  c11_dhdx[41] = 0.0;
  c11_dhdx[44] = 0.0;
  c11_dhdx[47] = 0.0;
  c11_dhdx[50] = 0.0;
  c11_dhdx[53] = 0.0;
  c11_dhdx[56] = 0.0;
  c11_dhdx[59] = 0.0;
  c11_dhdx[62] = 0.0;
  c11_dhdx[65] = 0.0;
  c11_dhdx[68] = 2.0 * c11_q0 * c11_q2 + 2.0 * c11_q1 * c11_q3;
  c11_dhdx[71] = 2.0 * c11_q2 * c11_q3 - 2.0 * c11_q0 * c11_q1;
  c11_dhdx[74] = ((c11_i_c - c11_j_c) - c11_k_c) + c11_l_c;
  c11_dhdx[77] = 0.0;
  c11_dhdx[80] = 0.0;
  c11_dhdx[83] = 1.0;
  c11_b_st.site = &c11_mc_emlrtRSI;
  c11_d_obj = c11_b_obj;
  for (c11_i4 = 0; c11_i4 < 784; c11_i4++) {
    c11_P[c11_i4] = c11_d_obj->pStateCovariance[c11_i4];
  }

  c11_b_st.site = &c11_nc_emlrtRSI;
  c11_b_BasicEKF_correctEqn(chartInstance, &c11_b_st, c11_b_obj, c11_xk, c11_P,
    c11_h, c11_dhdx, c11_z, c11_Rmagmat, c11_innov, c11_innovCov);
  c11_b_st.site = &c11_oc_emlrtRSI;
  c11_AsyncMARGGPSFuserBase_setStateCovariance(chartInstance, &c11_b_st,
    c11_b_obj, c11_P);
  c11_b_st.site = &c11_pc_emlrtRSI;
  c11_AsyncMARGGPSFuserBase_setState(chartInstance, &c11_b_st, c11_b_obj, c11_xk);
}

static void c11_AsyncMARGGPSFuserBase_magMeasFcn
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance, real_T c11_x[28], real_T
   c11_z[3])
{
  real_T c11_a;
  real_T c11_ab_a;
  real_T c11_ac_a;
  real_T c11_b_a;
  real_T c11_b_c;
  real_T c11_bb_a;
  real_T c11_bc_a;
  real_T c11_c;
  real_T c11_c_a;
  real_T c11_c_c;
  real_T c11_cb_a;
  real_T c11_cc_a;
  real_T c11_d_a;
  real_T c11_d_c;
  real_T c11_db_a;
  real_T c11_dc_a;
  real_T c11_e_a;
  real_T c11_e_c;
  real_T c11_eb_a;
  real_T c11_ec_a;
  real_T c11_f_a;
  real_T c11_f_c;
  real_T c11_fb_a;
  real_T c11_fc_a;
  real_T c11_g_a;
  real_T c11_g_c;
  real_T c11_gb_a;
  real_T c11_gc_a;
  real_T c11_h_a;
  real_T c11_h_c;
  real_T c11_hb_a;
  real_T c11_hc_a;
  real_T c11_i_a;
  real_T c11_i_c;
  real_T c11_ib_a;
  real_T c11_ic_a;
  real_T c11_j_a;
  real_T c11_j_c;
  real_T c11_jb_a;
  real_T c11_jc_a;
  real_T c11_k_a;
  real_T c11_k_c;
  real_T c11_kb_a;
  real_T c11_l_a;
  real_T c11_l_c;
  real_T c11_lb_a;
  real_T c11_m_a;
  real_T c11_magBiasX;
  real_T c11_magBiasY;
  real_T c11_magBiasZ;
  real_T c11_magNavX;
  real_T c11_magNavY;
  real_T c11_magNavZ;
  real_T c11_mb_a;
  real_T c11_mx;
  real_T c11_my;
  real_T c11_mz;
  real_T c11_n_a;
  real_T c11_nb_a;
  real_T c11_o_a;
  real_T c11_ob_a;
  real_T c11_p_a;
  real_T c11_pb_a;
  real_T c11_q0;
  real_T c11_q1;
  real_T c11_q2;
  real_T c11_q3;
  real_T c11_q_a;
  real_T c11_qb_a;
  real_T c11_r_a;
  real_T c11_rb_a;
  real_T c11_s_a;
  real_T c11_sb_a;
  real_T c11_t_a;
  real_T c11_tb_a;
  real_T c11_u_a;
  real_T c11_ub_a;
  real_T c11_v_a;
  real_T c11_vb_a;
  real_T c11_w_a;
  real_T c11_wb_a;
  real_T c11_x_a;
  real_T c11_xb_a;
  real_T c11_y_a;
  real_T c11_yb_a;
  (void)chartInstance;
  c11_q0 = c11_x[0];
  c11_q1 = c11_x[1];
  c11_q2 = c11_x[2];
  c11_q3 = c11_x[3];
  c11_magNavX = c11_x[22];
  c11_magNavY = c11_x[23];
  c11_magNavZ = c11_x[24];
  c11_magBiasX = c11_x[25];
  c11_magBiasY = c11_x[26];
  c11_magBiasZ = c11_x[27];
  c11_a = c11_q0;
  c11_b_a = c11_a;
  c11_c_a = c11_b_a;
  c11_d_a = c11_c_a;
  c11_e_a = c11_d_a;
  c11_c = c11_e_a * c11_e_a;
  c11_f_a = c11_q1;
  c11_g_a = c11_f_a;
  c11_h_a = c11_g_a;
  c11_i_a = c11_h_a;
  c11_j_a = c11_i_a;
  c11_b_c = c11_j_a * c11_j_a;
  c11_k_a = c11_q2;
  c11_l_a = c11_k_a;
  c11_m_a = c11_l_a;
  c11_n_a = c11_m_a;
  c11_o_a = c11_n_a;
  c11_c_c = c11_o_a * c11_o_a;
  c11_p_a = c11_q3;
  c11_q_a = c11_p_a;
  c11_r_a = c11_q_a;
  c11_s_a = c11_r_a;
  c11_t_a = c11_s_a;
  c11_d_c = c11_t_a * c11_t_a;
  c11_mx = ((c11_magBiasX + c11_magNavX * (((c11_c + c11_b_c) - c11_c_c) -
              c11_d_c)) - c11_magNavZ * (2.0 * c11_q0 * c11_q2 - 2.0 * c11_q1 *
             c11_q3)) + c11_magNavY * (2.0 * c11_q0 * c11_q3 + 2.0 * c11_q1 *
    c11_q2);
  c11_u_a = c11_q0;
  c11_v_a = c11_u_a;
  c11_w_a = c11_v_a;
  c11_x_a = c11_w_a;
  c11_y_a = c11_x_a;
  c11_e_c = c11_y_a * c11_y_a;
  c11_ab_a = c11_q1;
  c11_bb_a = c11_ab_a;
  c11_cb_a = c11_bb_a;
  c11_db_a = c11_cb_a;
  c11_eb_a = c11_db_a;
  c11_f_c = c11_eb_a * c11_eb_a;
  c11_fb_a = c11_q2;
  c11_gb_a = c11_fb_a;
  c11_hb_a = c11_gb_a;
  c11_ib_a = c11_hb_a;
  c11_jb_a = c11_ib_a;
  c11_g_c = c11_jb_a * c11_jb_a;
  c11_kb_a = c11_q3;
  c11_lb_a = c11_kb_a;
  c11_mb_a = c11_lb_a;
  c11_nb_a = c11_mb_a;
  c11_ob_a = c11_nb_a;
  c11_h_c = c11_ob_a * c11_ob_a;
  c11_my = ((c11_magBiasY + c11_magNavY * (((c11_e_c - c11_f_c) + c11_g_c) -
              c11_h_c)) + c11_magNavZ * (2.0 * c11_q0 * c11_q1 + 2.0 * c11_q2 *
             c11_q3)) - c11_magNavX * (2.0 * c11_q0 * c11_q3 - 2.0 * c11_q1 *
    c11_q2);
  c11_pb_a = c11_q0;
  c11_qb_a = c11_pb_a;
  c11_rb_a = c11_qb_a;
  c11_sb_a = c11_rb_a;
  c11_tb_a = c11_sb_a;
  c11_i_c = c11_tb_a * c11_tb_a;
  c11_ub_a = c11_q1;
  c11_vb_a = c11_ub_a;
  c11_wb_a = c11_vb_a;
  c11_xb_a = c11_wb_a;
  c11_yb_a = c11_xb_a;
  c11_j_c = c11_yb_a * c11_yb_a;
  c11_ac_a = c11_q2;
  c11_bc_a = c11_ac_a;
  c11_cc_a = c11_bc_a;
  c11_dc_a = c11_cc_a;
  c11_ec_a = c11_dc_a;
  c11_k_c = c11_ec_a * c11_ec_a;
  c11_fc_a = c11_q3;
  c11_gc_a = c11_fc_a;
  c11_hc_a = c11_gc_a;
  c11_ic_a = c11_hc_a;
  c11_jc_a = c11_ic_a;
  c11_l_c = c11_jc_a * c11_jc_a;
  c11_mz = ((c11_magBiasZ + c11_magNavZ * (((c11_i_c - c11_j_c) - c11_k_c) +
              c11_l_c)) - c11_magNavY * (2.0 * c11_q0 * c11_q1 - 2.0 * c11_q2 *
             c11_q3)) + c11_magNavX * (2.0 * c11_q0 * c11_q2 + 2.0 * c11_q1 *
    c11_q3);
  c11_z[0] = c11_mx;
  c11_z[1] = c11_my;
  c11_z[2] = c11_mz;
}

static void c11_AsyncMARGGPSFuserBase_fusegps
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance, const emlrtStack *c11_sp,
   c11_insfilterAsync *c11_obj, real_T c11_lla[3], real_T c11_Rpos, real_T
   c11_vel[3], real_T c11_Rvel)
{
  static char_T c11_b_cv[27] = { 'l', 'a', 't', 'i', 't', 'u', 'd', 'e', '-',
    'l', 'o', 'n', 'g', 'i', 't', 'u', 'd', 'e', '-', 'a', 'l', 't', 'i', 't',
    'u', 'd', 'e' };

  emlrtStack c11_b_st;
  emlrtStack c11_c_st;
  emlrtStack c11_d_st;
  emlrtStack c11_e_st;
  emlrtStack c11_st;
  const mxArray *c11_b_y = NULL;
  const mxArray *c11_c_y = NULL;
  const mxArray *c11_y = NULL;
  real_T c11_measNoise[36];
  real_T c11_resCov[36];
  real_T c11_Rposmat[9];
  real_T c11_Rvelmat[9];
  real_T c11_b_z[6];
  real_T c11_res[6];
  real_T c11_ecef0[3];
  real_T c11_ecefPos[3];
  real_T c11_enuPos[3];
  real_T c11_pos[3];
  real_T c11_Rin;
  real_T c11_a;
  real_T c11_b_Rin;
  real_T c11_b_a;
  real_T c11_b_k;
  real_T c11_b_x;
  real_T c11_c_Rin;
  real_T c11_c_x;
  real_T c11_coslambda;
  real_T c11_cosphi;
  real_T c11_d_Rin;
  real_T c11_d_x;
  real_T c11_d_y;
  real_T c11_lambda;
  real_T c11_phi;
  real_T c11_sinlambda;
  real_T c11_sinphi;
  real_T c11_tmp;
  real_T c11_uEast;
  real_T c11_vNorth;
  real_T c11_wUp;
  real_T c11_x;
  real_T c11_z;
  int32_T c11_b_j;
  int32_T c11_c_j;
  int32_T c11_d_j;
  int32_T c11_i;
  int32_T c11_i1;
  int32_T c11_i10;
  int32_T c11_i11;
  int32_T c11_i12;
  int32_T c11_i13;
  int32_T c11_i14;
  int32_T c11_i15;
  int32_T c11_i16;
  int32_T c11_i2;
  int32_T c11_i3;
  int32_T c11_i4;
  int32_T c11_i5;
  int32_T c11_i6;
  int32_T c11_i7;
  int32_T c11_i8;
  int32_T c11_i9;
  int32_T c11_j;
  int32_T c11_k;
  boolean_T c11_b;
  boolean_T c11_b1;
  boolean_T c11_b2;
  boolean_T c11_b_b;
  boolean_T c11_c_b;
  boolean_T c11_d_b;
  boolean_T c11_exitg1;
  boolean_T c11_p;
  c11_st.prev = c11_sp;
  c11_st.tls = c11_sp->tls;
  c11_b_st.prev = &c11_st;
  c11_b_st.tls = c11_st.tls;
  c11_c_st.prev = &c11_b_st;
  c11_c_st.tls = c11_b_st.tls;
  c11_d_st.prev = &c11_c_st;
  c11_d_st.tls = c11_c_st.tls;
  c11_e_st.prev = &c11_d_st;
  c11_e_st.tls = c11_d_st.tls;
  c11_st.site = &c11_td_emlrtRSI;
  c11_b_st.site = &c11_wd_emlrtRSI;
  c11_c_st.site = &c11_gb_emlrtRSI;
  c11_p = true;
  c11_k = 0;
  c11_exitg1 = false;
  while ((!c11_exitg1) && (c11_k < 3)) {
    c11_b_k = 1.0 + (real_T)c11_k;
    c11_x = c11_lla[(int32_T)c11_b_k - 1];
    c11_b_x = c11_x;
    c11_b_b = muDoubleScalarIsInf(c11_b_x);
    c11_b1 = !c11_b_b;
    c11_c_x = c11_x;
    c11_c_b = muDoubleScalarIsNaN(c11_c_x);
    c11_b2 = !c11_c_b;
    c11_d_b = (c11_b1 && c11_b2);
    if (c11_d_b) {
      c11_k++;
    } else {
      c11_p = false;
      c11_exitg1 = true;
    }
  }

  if (c11_p) {
    c11_b = true;
  } else {
    c11_b = false;
  }

  if (!c11_b) {
    c11_y = NULL;
    sf_mex_assign(&c11_y, sf_mex_create("y", c11_cv4, 10, 0U, 1U, 0U, 2, 1, 21),
                  false);
    c11_b_y = NULL;
    sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_cv5, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c11_c_y = NULL;
    sf_mex_assign(&c11_c_y, sf_mex_create("y", c11_b_cv, 10, 0U, 1U, 0U, 2, 1,
      27), false);
    sf_mex_call(&c11_c_st, &c11_emlrtMCI, "error", 0U, 2U, 14, c11_y, 14,
                sf_mex_call(&c11_c_st, NULL, "getString", 1U, 1U, 14,
      sf_mex_call(&c11_c_st, NULL, "message", 1U, 2U, 14, c11_b_y, 14, c11_c_y)));
  }

  c11_Rin = c11_Rpos;
  c11_b_Rin = c11_Rin;
  c11_a = c11_b_Rin;
  for (c11_i = 0; c11_i < 3; c11_i++) {
    c11_enuPos[c11_i] = c11_a;
  }

  for (c11_i1 = 0; c11_i1 < 9; c11_i1++) {
    c11_Rposmat[c11_i1] = 0.0;
  }

  for (c11_j = 0; c11_j < 3; c11_j++) {
    c11_b_j = c11_j;
    c11_Rposmat[c11_b_j + 3 * c11_b_j] = c11_enuPos[c11_b_j];
  }

  c11_c_Rin = c11_Rvel;
  c11_d_Rin = c11_c_Rin;
  c11_b_a = c11_d_Rin;
  for (c11_i2 = 0; c11_i2 < 3; c11_i2++) {
    c11_enuPos[c11_i2] = c11_b_a;
  }

  for (c11_i3 = 0; c11_i3 < 9; c11_i3++) {
    c11_Rvelmat[c11_i3] = 0.0;
  }

  for (c11_c_j = 0; c11_c_j < 3; c11_c_j++) {
    c11_d_j = c11_c_j;
    c11_Rvelmat[c11_d_j + 3 * c11_d_j] = c11_enuPos[c11_d_j];
  }

  for (c11_i4 = 0; c11_i4 < 36; c11_i4++) {
    c11_measNoise[c11_i4] = 0.0;
  }

  c11_i5 = 0;
  c11_i6 = 0;
  for (c11_i7 = 0; c11_i7 < 3; c11_i7++) {
    for (c11_i9 = 0; c11_i9 < 3; c11_i9++) {
      c11_measNoise[c11_i9 + c11_i5] = c11_Rposmat[c11_i9 + c11_i6];
    }

    c11_i5 += 6;
    c11_i6 += 3;
  }

  c11_i8 = 0;
  c11_i10 = 0;
  for (c11_i11 = 0; c11_i11 < 3; c11_i11++) {
    for (c11_i12 = 0; c11_i12 < 3; c11_i12++) {
      c11_measNoise[(c11_i12 + c11_i8) + 21] = c11_Rvelmat[c11_i12 + c11_i10];
    }

    c11_i8 += 6;
    c11_i10 += 3;
  }

  c11_st.site = &c11_ud_emlrtRSI;
  for (c11_i13 = 0; c11_i13 < 3; c11_i13++) {
    c11_enuPos[c11_i13] = c11_obj->ReferenceLocation[c11_i13];
  }

  c11_b_st.site = &c11_xd_emlrtRSI;
  c11_c_st.site = &c11_yd_emlrtRSI;
  c11_d_st.site = &c11_ae_emlrtRSI;
  c11_lla2ecef(chartInstance, &c11_d_st, c11_lla, c11_ecefPos);
  c11_d_st.site = &c11_be_emlrtRSI;
  c11_phi = c11_enuPos[0];
  c11_lambda = c11_enuPos[1];
  c11_cosphi = c11_phi;
  c11_b_cosd(chartInstance, &c11_cosphi);
  c11_sinphi = c11_phi;
  c11_b_sind(chartInstance, &c11_sinphi);
  c11_coslambda = c11_lambda;
  c11_b_cosd(chartInstance, &c11_coslambda);
  c11_sinlambda = c11_lambda;
  c11_b_sind(chartInstance, &c11_sinlambda);
  c11_e_st.site = &c11_ee_emlrtRSI;
  c11_lla2ecef(chartInstance, &c11_e_st, c11_enuPos, c11_ecef0);
  for (c11_i14 = 0; c11_i14 < 3; c11_i14++) {
    c11_ecefPos[c11_i14] -= c11_ecef0[c11_i14];
  }

  c11_d_x = c11_ecefPos[0];
  c11_d_y = c11_ecefPos[1];
  c11_z = c11_ecefPos[2];
  c11_uEast = -c11_sinlambda * c11_d_x + c11_coslambda * c11_d_y;
  c11_tmp = c11_coslambda * c11_d_x + c11_sinlambda * c11_d_y;
  c11_vNorth = -c11_sinphi * c11_tmp + c11_cosphi * c11_z;
  c11_wUp = c11_cosphi * c11_tmp + c11_sinphi * c11_z;
  c11_enuPos[0] = c11_uEast;
  c11_enuPos[1] = c11_vNorth;
  c11_enuPos[2] = c11_wUp;
  c11_pos[0] = c11_enuPos[1];
  c11_pos[1] = c11_enuPos[0];
  c11_pos[2] = -c11_enuPos[2];
  for (c11_i15 = 0; c11_i15 < 3; c11_i15++) {
    c11_b_z[c11_i15] = c11_pos[c11_i15];
  }

  for (c11_i16 = 0; c11_i16 < 3; c11_i16++) {
    c11_b_z[c11_i16 + 3] = c11_vel[c11_i16];
  }

  c11_st.site = &c11_vd_emlrtRSI;
  c11_AsyncMARGGPSFuserBase_basicCorrect(chartInstance, &c11_st, c11_obj,
    c11_b_z, c11_measNoise, c11_res, c11_resCov);
}

static void c11_lla2ecef(SFc11_car_model_FIXEDInstanceStruct *chartInstance,
  const emlrtStack *c11_sp, real_T c11_llaPos[3], real_T c11_ecefPos[3])
{
  emlrtStack c11_b_st;
  emlrtStack c11_st;
  real_T c11_N;
  real_T c11_a;
  real_T c11_b_a;
  real_T c11_b_h;
  real_T c11_b_phi;
  real_T c11_b_y;
  real_T c11_c_a;
  real_T c11_cosphi;
  real_T c11_d;
  real_T c11_d1;
  real_T c11_d2;
  real_T c11_d_a;
  real_T c11_h;
  real_T c11_lambda;
  real_T c11_phi;
  real_T c11_rho;
  real_T c11_sinphi;
  real_T c11_x;
  real_T c11_y;
  real_T c11_z;
  c11_st.prev = c11_sp;
  c11_st.tls = c11_sp->tls;
  c11_b_st.prev = &c11_st;
  c11_b_st.tls = c11_st.tls;
  c11_phi = c11_llaPos[0];
  c11_lambda = c11_llaPos[1];
  c11_h = c11_llaPos[2];
  c11_st.site = &c11_ce_emlrtRSI;
  c11_b_phi = c11_phi;
  c11_b_h = c11_h;
  c11_sinphi = c11_b_phi;
  c11_b_sind(chartInstance, &c11_sinphi);
  c11_cosphi = c11_b_phi;
  c11_b_cosd(chartInstance, &c11_cosphi);
  c11_b_st.site = &c11_de_emlrtRSI;
  c11_a = c11_sinphi;
  c11_b_a = c11_a;
  c11_c_a = c11_b_a;
  c11_d_a = c11_c_a;
  c11_y = c11_d_a * c11_d_a;
  c11_d = 1.0 - 0.0066943799901413165 * c11_y;
  c11_b_st.site = &c11_de_emlrtRSI;
  c11_b_sqrt(chartInstance, &c11_b_st, &c11_d);
  c11_N = 6.378137E+6 / c11_d;
  c11_rho = (c11_N + c11_b_h) * c11_cosphi;
  c11_z = (c11_N * 0.99330562000985867 + c11_b_h) * c11_sinphi;
  c11_d1 = c11_lambda;
  c11_b_cosd(chartInstance, &c11_d1);
  c11_x = c11_rho * c11_d1;
  c11_d2 = c11_lambda;
  c11_b_sind(chartInstance, &c11_d2);
  c11_b_y = c11_rho * c11_d2;
  c11_ecefPos[0] = c11_x;
  c11_ecefPos[1] = c11_b_y;
  c11_ecefPos[2] = c11_z;
}

static real_T c11_sind(SFc11_car_model_FIXEDInstanceStruct *chartInstance,
  real_T c11_x)
{
  real_T c11_b_x;
  c11_b_x = c11_x;
  c11_b_sind(chartInstance, &c11_b_x);
  return c11_b_x;
}

static real_T c11_cosd(SFc11_car_model_FIXEDInstanceStruct *chartInstance,
  real_T c11_x)
{
  real_T c11_b_x;
  c11_b_x = c11_x;
  c11_b_cosd(chartInstance, &c11_b_x);
  return c11_b_x;
}

static void c11_AsyncMARGGPSFuserBase_basicCorrect
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance, const emlrtStack *c11_sp,
   c11_insfilterAsync *c11_obj, real_T c11_z[6], real_T c11_measNoise[36],
   real_T c11_innov[6], real_T c11_innovCov[36])
{
  static real_T c11_H[168] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  ptrdiff_t c11_b_k_t;
  ptrdiff_t c11_b_lda_t;
  ptrdiff_t c11_b_ldb_t;
  ptrdiff_t c11_b_ldc_t;
  ptrdiff_t c11_b_m_t;
  ptrdiff_t c11_b_n_t;
  ptrdiff_t c11_c_k_t;
  ptrdiff_t c11_c_lda_t;
  ptrdiff_t c11_c_ldb_t;
  ptrdiff_t c11_c_ldc_t;
  ptrdiff_t c11_c_m_t;
  ptrdiff_t c11_c_n_t;
  ptrdiff_t c11_d_k_t;
  ptrdiff_t c11_d_lda_t;
  ptrdiff_t c11_d_ldb_t;
  ptrdiff_t c11_d_ldc_t;
  ptrdiff_t c11_d_m_t;
  ptrdiff_t c11_d_n_t;
  ptrdiff_t c11_k_t;
  ptrdiff_t c11_lda_t;
  ptrdiff_t c11_ldb_t;
  ptrdiff_t c11_ldc_t;
  ptrdiff_t c11_m_t;
  ptrdiff_t c11_n_t;
  c11_insfilterAsync *c11_b_obj;
  c11_insfilterAsync *c11_c_obj;
  c11_insfilterAsync *c11_d_obj;
  c11_insfilterAsync *c11_e_obj;
  emlrtStack c11_b_st;
  emlrtStack c11_c_st;
  emlrtStack c11_d_st;
  emlrtStack c11_st;
  real_T c11_P[784];
  real_T c11_c_y[784];
  real_T c11_d_y[784];
  real_T c11_W[168];
  real_T c11_y[168];
  real_T c11_b_y[28];
  real_T c11_xk[28];
  real_T c11_f_y[4];
  real_T c11_idx[4];
  real_T c11_qparts[4];
  real_T c11_a;
  real_T c11_alpha1;
  real_T c11_b_alpha1;
  real_T c11_b_beta1;
  real_T c11_beta1;
  real_T c11_c_alpha1;
  real_T c11_c_beta1;
  real_T c11_d_alpha1;
  real_T c11_d_beta1;
  real_T c11_e_y;
  real_T c11_g_y;
  real_T c11_magE;
  real_T c11_magN;
  real_T c11_n;
  real_T c11_pnx;
  real_T c11_pny;
  real_T c11_pnz;
  real_T c11_vnx;
  real_T c11_vny;
  real_T c11_vnz;
  int32_T c11_b_k;
  int32_T c11_i;
  int32_T c11_i1;
  int32_T c11_i10;
  int32_T c11_i11;
  int32_T c11_i12;
  int32_T c11_i13;
  int32_T c11_i14;
  int32_T c11_i15;
  int32_T c11_i16;
  int32_T c11_i2;
  int32_T c11_i3;
  int32_T c11_i4;
  int32_T c11_i5;
  int32_T c11_i6;
  int32_T c11_i7;
  int32_T c11_i8;
  int32_T c11_i9;
  int32_T c11_k;
  char_T c11_TRANSA1;
  char_T c11_TRANSB1;
  char_T c11_b_TRANSA1;
  char_T c11_b_TRANSB1;
  char_T c11_c_TRANSA1;
  char_T c11_c_TRANSB1;
  char_T c11_d_TRANSA1;
  char_T c11_d_TRANSB1;
  c11_st.prev = c11_sp;
  c11_st.tls = c11_sp->tls;
  c11_st.site = &c11_jc_emlrtRSI;
  c11_b_st.prev = &c11_st;
  c11_b_st.tls = c11_st.tls;
  c11_c_st.prev = &c11_b_st;
  c11_c_st.tls = c11_b_st.tls;
  c11_d_st.prev = &c11_c_st;
  c11_d_st.tls = c11_c_st.tls;
  c11_b_obj = c11_obj;
  for (c11_i = 0; c11_i < 28; c11_i++) {
    c11_xk[c11_i] = c11_b_obj->pState[c11_i];
  }

  c11_magN = c11_xk[22];
  c11_magE = c11_xk[23];
  c11_xk[22] = c11_magN;
  c11_xk[23] = c11_magE;
  c11_pnx = c11_xk[7];
  c11_pny = c11_xk[8];
  c11_pnz = c11_xk[9];
  c11_vnx = c11_xk[10];
  c11_vny = c11_xk[11];
  c11_vnz = c11_xk[12];
  c11_innov[0] = c11_pnx;
  c11_innov[1] = c11_pny;
  c11_innov[2] = c11_pnz;
  c11_innov[3] = c11_vnx;
  c11_innov[4] = c11_vny;
  c11_innov[5] = c11_vnz;
  c11_st.site = &c11_mc_emlrtRSI;
  c11_c_obj = c11_obj;
  for (c11_i1 = 0; c11_i1 < 784; c11_i1++) {
    c11_P[c11_i1] = c11_c_obj->pStateCovariance[c11_i1];
  }

  c11_st.site = &c11_nc_emlrtRSI;
  c11_d_obj = c11_obj;
  c11_b_st.site = &c11_yc_emlrtRSI;
  c11_c_st.site = &c11_bd_emlrtRSI;
  c11_d_st.site = &c11_ed_emlrtRSI;
  c11_TRANSB1 = 'N';
  c11_TRANSA1 = 'N';
  c11_alpha1 = 1.0;
  c11_beta1 = 0.0;
  c11_m_t = (ptrdiff_t)6;
  c11_n_t = (ptrdiff_t)28;
  c11_k_t = (ptrdiff_t)28;
  c11_lda_t = (ptrdiff_t)6;
  c11_ldb_t = (ptrdiff_t)28;
  c11_ldc_t = (ptrdiff_t)6;
  dgemm(&c11_TRANSA1, &c11_TRANSB1, &c11_m_t, &c11_n_t, &c11_k_t, &c11_alpha1,
        &c11_H[0], &c11_lda_t, &c11_P[0], &c11_ldb_t, &c11_beta1, &c11_y[0],
        &c11_ldc_t);
  c11_d_st.site = &c11_ed_emlrtRSI;
  c11_b_TRANSB1 = 'T';
  c11_b_TRANSA1 = 'N';
  c11_b_alpha1 = 1.0;
  c11_b_beta1 = 0.0;
  c11_b_m_t = (ptrdiff_t)6;
  c11_b_n_t = (ptrdiff_t)6;
  c11_b_k_t = (ptrdiff_t)28;
  c11_b_lda_t = (ptrdiff_t)6;
  c11_b_ldb_t = (ptrdiff_t)6;
  c11_b_ldc_t = (ptrdiff_t)6;
  dgemm(&c11_b_TRANSA1, &c11_b_TRANSB1, &c11_b_m_t, &c11_b_n_t, &c11_b_k_t,
        &c11_b_alpha1, &c11_y[0], &c11_b_lda_t, &c11_H[0], &c11_b_ldb_t,
        &c11_b_beta1, &c11_innovCov[0], &c11_b_ldc_t);
  for (c11_i2 = 0; c11_i2 < 36; c11_i2++) {
    c11_innovCov[c11_i2] += c11_measNoise[c11_i2];
  }

  for (c11_i3 = 0; c11_i3 < 6; c11_i3++) {
    c11_innov[c11_i3] = c11_z[c11_i3] - c11_innov[c11_i3];
  }

  c11_c_st.site = &c11_cd_emlrtRSI;
  c11_d_st.site = &c11_ec_emlrtRSI;
  c11_c_TRANSB1 = 'T';
  c11_c_TRANSA1 = 'N';
  c11_c_alpha1 = 1.0;
  c11_c_beta1 = 0.0;
  c11_c_m_t = (ptrdiff_t)28;
  c11_c_n_t = (ptrdiff_t)6;
  c11_c_k_t = (ptrdiff_t)28;
  c11_c_lda_t = (ptrdiff_t)28;
  c11_c_ldb_t = (ptrdiff_t)6;
  c11_c_ldc_t = (ptrdiff_t)28;
  dgemm(&c11_c_TRANSA1, &c11_c_TRANSB1, &c11_c_m_t, &c11_c_n_t, &c11_c_k_t,
        &c11_c_alpha1, &c11_P[0], &c11_c_lda_t, &c11_H[0], &c11_c_ldb_t,
        &c11_c_beta1, &c11_y[0], &c11_c_ldc_t);
  c11_c_st.site = &c11_cd_emlrtRSI;
  c11_d_st.site = &c11_fd_emlrtRSI;
  c11_mrdiv(chartInstance, &c11_d_st, c11_y, c11_innovCov, c11_W);
  for (c11_i4 = 0; c11_i4 < 28; c11_i4++) {
    c11_b_y[c11_i4] = 0.0;
    c11_i6 = 0;
    for (c11_i7 = 0; c11_i7 < 6; c11_i7++) {
      c11_b_y[c11_i4] += c11_W[c11_i6 + c11_i4] * c11_innov[c11_i7];
      c11_i6 += 28;
    }
  }

  for (c11_i5 = 0; c11_i5 < 28; c11_i5++) {
    c11_xk[c11_i5] += c11_b_y[c11_i5];
  }

  c11_c_st.site = &c11_dd_emlrtRSI;
  c11_d_TRANSB1 = 'N';
  c11_d_TRANSA1 = 'N';
  c11_d_alpha1 = 1.0;
  c11_d_beta1 = 0.0;
  c11_d_m_t = (ptrdiff_t)28;
  c11_d_n_t = (ptrdiff_t)28;
  c11_d_k_t = (ptrdiff_t)6;
  c11_d_lda_t = (ptrdiff_t)28;
  c11_d_ldb_t = (ptrdiff_t)6;
  c11_d_ldc_t = (ptrdiff_t)28;
  dgemm(&c11_d_TRANSA1, &c11_d_TRANSB1, &c11_d_m_t, &c11_d_n_t, &c11_d_k_t,
        &c11_d_alpha1, &c11_W[0], &c11_d_lda_t, &c11_H[0], &c11_d_ldb_t,
        &c11_d_beta1, &c11_c_y[0], &c11_d_ldc_t);
  c11_c_st.site = &c11_dd_emlrtRSI;
  c11_mtimes(chartInstance, c11_c_y, c11_P, c11_d_y);
  for (c11_i8 = 0; c11_i8 < 784; c11_i8++) {
    c11_P[c11_i8] -= c11_d_y[c11_i8];
  }

  c11_b_st.site = &c11_ad_emlrtRSI;
  c11_e_obj = c11_d_obj;
  for (c11_i9 = 0; c11_i9 < 4; c11_i9++) {
    c11_idx[c11_i9] = c11_e_obj->OrientationIdx[c11_i9];
  }

  for (c11_i10 = 0; c11_i10 < 4; c11_i10++) {
    if (c11_idx[c11_i10] != (real_T)(int32_T)muDoubleScalarFloor(c11_idx[c11_i10]))
    {
      emlrtIntegerCheckR2012b(c11_idx[c11_i10], &c11_emlrtDCI, &c11_b_st);
    }

    c11_i11 = (int32_T)c11_idx[c11_i10];
    if ((c11_i11 < 1) || (c11_i11 > 28)) {
      emlrtDynamicBoundsCheckR2012b(c11_i11, 1, 28, &c11_emlrtBCI, &c11_b_st);
    }

    c11_qparts[c11_i10] = c11_xk[c11_i11 - 1];
  }

  for (c11_k = 0; c11_k < 4; c11_k++) {
    c11_b_k = c11_k;
    c11_a = c11_qparts[c11_b_k];
    c11_g_y = c11_a * c11_a;
    c11_f_y[c11_b_k] = c11_g_y;
  }

  c11_e_y = c11_sumColumnB(chartInstance, c11_f_y, 1);
  c11_n = c11_e_y;
  c11_c_st.site = &c11_hc_emlrtRSI;
  c11_b_sqrt(chartInstance, &c11_c_st, &c11_n);
  for (c11_i12 = 0; c11_i12 < 4; c11_i12++) {
    c11_qparts[c11_i12] /= c11_n;
  }

  if (c11_qparts[0] < 0.0) {
    for (c11_i14 = 0; c11_i14 < 4; c11_i14++) {
      if (c11_idx[c11_i14] != (real_T)(int32_T)muDoubleScalarFloor
          (c11_idx[c11_i14])) {
        emlrtIntegerCheckR2012b(c11_idx[c11_i14], &c11_c_emlrtDCI, &c11_b_st);
      }

      c11_i16 = (int32_T)c11_idx[c11_i14];
      if ((c11_i16 < 1) || (c11_i16 > 28)) {
        emlrtDynamicBoundsCheckR2012b(c11_i16, 1, 28, &c11_c_emlrtBCI, &c11_b_st);
      }

      c11_xk[c11_i16 - 1] = -c11_qparts[c11_i14];
    }
  } else {
    for (c11_i13 = 0; c11_i13 < 4; c11_i13++) {
      if (c11_idx[c11_i13] != (real_T)(int32_T)muDoubleScalarFloor
          (c11_idx[c11_i13])) {
        emlrtIntegerCheckR2012b(c11_idx[c11_i13], &c11_b_emlrtDCI, &c11_b_st);
      }

      c11_i15 = (int32_T)c11_idx[c11_i13];
      if ((c11_i15 < 1) || (c11_i15 > 28)) {
        emlrtDynamicBoundsCheckR2012b(c11_i15, 1, 28, &c11_b_emlrtBCI, &c11_b_st);
      }

      c11_xk[c11_i15 - 1] = c11_qparts[c11_i13];
    }
  }

  c11_st.site = &c11_oc_emlrtRSI;
  c11_AsyncMARGGPSFuserBase_setStateCovariance(chartInstance, &c11_st, c11_obj,
    c11_P);
  c11_st.site = &c11_pc_emlrtRSI;
  c11_AsyncMARGGPSFuserBase_setState(chartInstance, &c11_st, c11_obj, c11_xk);
}

static void c11_mrdiv(SFc11_car_model_FIXEDInstanceStruct *chartInstance, const
                      emlrtStack *c11_sp, real_T c11_A[168], real_T c11_B[36],
                      real_T c11_Y[168])
{
  emlrtStack c11_b_st;
  emlrtStack c11_c_st;
  emlrtStack c11_d_st;
  emlrtStack c11_e_st;
  emlrtStack c11_f_st;
  emlrtStack c11_g_st;
  emlrtStack c11_h_st;
  emlrtStack c11_i_st;
  emlrtStack c11_j_st;
  emlrtStack c11_k_st;
  emlrtStack c11_st;
  real_T c11_b_A[36];
  real_T c11_b_temp;
  real_T c11_b_x;
  real_T c11_b_y;
  real_T c11_c_temp;
  real_T c11_c_x;
  real_T c11_c_y;
  real_T c11_d_temp;
  real_T c11_d_x;
  real_T c11_d_y;
  real_T c11_e_x;
  real_T c11_f_x;
  real_T c11_g_x;
  real_T c11_h_x;
  real_T c11_i_x;
  real_T c11_s;
  real_T c11_smax;
  real_T c11_temp;
  real_T c11_x;
  real_T c11_y;
  real_T c11_yjy;
  real_T c11_z;
  int32_T c11_ipiv[6];
  int32_T c11_a;
  int32_T c11_b;
  int32_T c11_b_a;
  int32_T c11_b_b;
  int32_T c11_b_c;
  int32_T c11_b_i;
  int32_T c11_b_ia0;
  int32_T c11_b_info;
  int32_T c11_b_ix;
  int32_T c11_b_ix0;
  int32_T c11_b_iy0;
  int32_T c11_b_j;
  int32_T c11_b_jAcol;
  int32_T c11_b_jBcol;
  int32_T c11_b_k;
  int32_T c11_b_kBcol;
  int32_T c11_b_m;
  int32_T c11_b_n;
  int32_T c11_c;
  int32_T c11_c_a;
  int32_T c11_c_b;
  int32_T c11_c_c;
  int32_T c11_c_i;
  int32_T c11_c_ia0;
  int32_T c11_c_info;
  int32_T c11_c_ix;
  int32_T c11_c_ix0;
  int32_T c11_c_iy0;
  int32_T c11_c_j;
  int32_T c11_c_k;
  int32_T c11_c_m;
  int32_T c11_c_n;
  int32_T c11_d_a;
  int32_T c11_d_b;
  int32_T c11_d_c;
  int32_T c11_d_i;
  int32_T c11_d_ia0;
  int32_T c11_d_ix0;
  int32_T c11_d_iy0;
  int32_T c11_d_j;
  int32_T c11_d_k;
  int32_T c11_d_m;
  int32_T c11_d_n;
  int32_T c11_e_a;
  int32_T c11_e_b;
  int32_T c11_e_c;
  int32_T c11_e_i;
  int32_T c11_e_ix0;
  int32_T c11_e_iy0;
  int32_T c11_e_j;
  int32_T c11_e_k;
  int32_T c11_e_n;
  int32_T c11_f_a;
  int32_T c11_f_b;
  int32_T c11_f_c;
  int32_T c11_f_i;
  int32_T c11_f_ix0;
  int32_T c11_f_iy0;
  int32_T c11_f_j;
  int32_T c11_f_n;
  int32_T c11_g_a;
  int32_T c11_g_b;
  int32_T c11_g_c;
  int32_T c11_g_i;
  int32_T c11_g_ix0;
  int32_T c11_g_j;
  int32_T c11_h_a;
  int32_T c11_h_b;
  int32_T c11_h_i;
  int32_T c11_h_ix0;
  int32_T c11_i;
  int32_T c11_i1;
  int32_T c11_i2;
  int32_T c11_i3;
  int32_T c11_i4;
  int32_T c11_i5;
  int32_T c11_i6;
  int32_T c11_i7;
  int32_T c11_i_a;
  int32_T c11_i_b;
  int32_T c11_i_i;
  int32_T c11_ia0;
  int32_T c11_ijA;
  int32_T c11_info;
  int32_T c11_ix;
  int32_T c11_ix0;
  int32_T c11_iy;
  int32_T c11_iy0;
  int32_T c11_j;
  int32_T c11_jA;
  int32_T c11_jAcol;
  int32_T c11_jBcol;
  int32_T c11_j_a;
  int32_T c11_j_b;
  int32_T c11_jj;
  int32_T c11_jm1;
  int32_T c11_jp;
  int32_T c11_jp1j;
  int32_T c11_jpiv;
  int32_T c11_jpiv_offset;
  int32_T c11_jprow;
  int32_T c11_jrow;
  int32_T c11_jy;
  int32_T c11_k;
  int32_T c11_kBcol;
  int32_T c11_k_a;
  int32_T c11_k_b;
  int32_T c11_l_a;
  int32_T c11_l_b;
  int32_T c11_m;
  int32_T c11_m_a;
  int32_T c11_m_b;
  int32_T c11_mmj;
  int32_T c11_n;
  int32_T c11_n_a;
  int32_T c11_n_b;
  int32_T c11_o_a;
  int32_T c11_o_b;
  int32_T c11_p_a;
  int32_T c11_p_b;
  int32_T c11_q_a;
  int32_T c11_q_b;
  int32_T c11_r_a;
  int32_T c11_r_b;
  int32_T c11_s_a;
  int32_T c11_s_b;
  int32_T c11_t_a;
  int32_T c11_t_b;
  int32_T c11_u_a;
  int32_T c11_v_a;
  int32_T c11_w_a;
  int32_T c11_x_a;
  boolean_T c11_b_overflow;
  boolean_T c11_c_overflow;
  boolean_T c11_d_overflow;
  boolean_T c11_e_overflow;
  boolean_T c11_f_overflow;
  boolean_T c11_overflow;
  c11_st.prev = c11_sp;
  c11_st.tls = c11_sp->tls;
  c11_st.site = &c11_gd_emlrtRSI;
  c11_b_st.prev = &c11_st;
  c11_b_st.tls = c11_st.tls;
  c11_c_st.prev = &c11_b_st;
  c11_c_st.tls = c11_b_st.tls;
  c11_d_st.prev = &c11_c_st;
  c11_d_st.tls = c11_c_st.tls;
  c11_e_st.prev = &c11_d_st;
  c11_e_st.tls = c11_d_st.tls;
  c11_f_st.prev = &c11_e_st;
  c11_f_st.tls = c11_e_st.tls;
  c11_g_st.prev = &c11_f_st;
  c11_g_st.tls = c11_f_st.tls;
  c11_h_st.prev = &c11_g_st;
  c11_h_st.tls = c11_g_st.tls;
  c11_i_st.prev = &c11_h_st;
  c11_i_st.tls = c11_h_st.tls;
  c11_j_st.prev = &c11_i_st;
  c11_j_st.tls = c11_i_st.tls;
  c11_k_st.prev = &c11_j_st;
  c11_k_st.tls = c11_j_st.tls;
  c11_b_st.site = &c11_fe_emlrtRSI;
  for (c11_i = 0; c11_i < 168; c11_i++) {
    c11_Y[c11_i] = c11_A[c11_i];
  }

  c11_c_st.site = &c11_he_emlrtRSI;
  c11_d_st.site = &c11_ie_emlrtRSI;
  for (c11_i1 = 0; c11_i1 < 36; c11_i1++) {
    c11_b_A[c11_i1] = c11_B[c11_i1];
  }

  c11_e_st.site = &c11_le_emlrtRSI;
  for (c11_i2 = 0; c11_i2 < 6; c11_i2++) {
    c11_ipiv[c11_i2] = 1 + c11_i2;
  }

  c11_info = 0;
  for (c11_j = 0; c11_j < 5; c11_j++) {
    c11_b_j = 1 + c11_j;
    c11_a = c11_b_j - 1;
    c11_jm1 = c11_a;
    c11_b = c11_b_j;
    c11_mmj = 6 - c11_b;
    c11_b_a = c11_jm1;
    c11_c = c11_b_a * 7;
    c11_b_b = c11_c + 1;
    c11_jj = c11_b_b;
    c11_c_a = c11_jj + 1;
    c11_jp1j = c11_c_a;
    c11_d_a = c11_mmj + 1;
    c11_b_c = c11_d_a;
    c11_f_st.site = &c11_me_emlrtRSI;
    c11_n = c11_b_c;
    c11_ix0 = c11_jj;
    c11_g_st.site = &c11_pe_emlrtRSI;
    c11_b_n = c11_n;
    c11_b_ix0 = c11_ix0;
    if (c11_b_n < 1) {
      c11_e_a = -1;
    } else {
      c11_e_a = 0;
      if (c11_b_n > 1) {
        c11_ix = c11_b_ix0 - 1;
        c11_x = c11_b_A[c11_b_ix0 - 1];
        c11_b_x = c11_x;
        c11_c_x = c11_b_x;
        c11_d_x = c11_c_x;
        c11_b_y = muDoubleScalarAbs(c11_d_x);
        c11_smax = c11_b_y;
        c11_h_st.site = &c11_qe_emlrtRSI;
        c11_h_b = c11_b_n;
        c11_i_b = c11_h_b;
        if (c11_i_b < 2) {
          c11_c_overflow = false;
        } else {
          c11_c_overflow = (c11_i_b > 2147483646);
        }

        if (c11_c_overflow) {
          c11_i_st.site = &c11_re_emlrtRSI;
          c11_check_forloop_overflow_error(chartInstance, &c11_i_st,
            c11_c_overflow);
        }

        for (c11_d_k = 2; c11_d_k <= c11_b_n; c11_d_k++) {
          c11_o_a = c11_ix + 1;
          c11_ix = c11_o_a;
          c11_e_x = c11_b_A[c11_ix];
          c11_f_x = c11_e_x;
          c11_g_x = c11_f_x;
          c11_h_x = c11_g_x;
          c11_c_y = muDoubleScalarAbs(c11_h_x);
          c11_s = c11_c_y;
          if (c11_s > c11_smax) {
            c11_e_a = c11_d_k - 1;
            c11_smax = c11_s;
          }
        }
      }
    }

    c11_jpiv_offset = c11_e_a;
    c11_f_a = c11_jj;
    c11_e_b = c11_jpiv_offset;
    c11_jpiv = (c11_f_a + c11_e_b) - 1;
    if (c11_b_A[c11_jpiv] != 0.0) {
      if (c11_jpiv_offset != 0) {
        c11_g_a = c11_b_j;
        c11_g_b = c11_jpiv_offset;
        c11_e_c = c11_g_a + c11_g_b;
        c11_ipiv[c11_b_j - 1] = c11_e_c;
        c11_k_b = c11_jm1 + 1;
        c11_jrow = c11_k_b;
        c11_l_a = c11_jrow;
        c11_l_b = c11_jpiv_offset;
        c11_jprow = c11_l_a + c11_l_b;
        c11_c_ix0 = c11_jrow;
        c11_iy0 = c11_jprow;
        c11_e_ix0 = c11_c_ix0;
        c11_c_iy0 = c11_iy0;
        c11_b_ix = c11_e_ix0 - 1;
        c11_iy = c11_c_iy0 - 1;
        for (c11_e_k = 0; c11_e_k < 6; c11_e_k++) {
          c11_c_temp = c11_b_A[c11_b_ix];
          c11_b_A[c11_b_ix] = c11_b_A[c11_iy];
          c11_b_A[c11_iy] = c11_c_temp;
          c11_p_a = c11_b_ix + 6;
          c11_b_ix = c11_p_a;
          c11_q_a = c11_iy + 6;
          c11_iy = c11_q_a;
        }
      }

      c11_h_a = c11_mmj - 1;
      c11_d_c = c11_h_a;
      c11_j_a = c11_jp1j;
      c11_j_b = c11_d_c;
      c11_i5 = c11_j_a + c11_j_b;
      c11_f_st.site = &c11_ne_emlrtRSI;
      c11_m_a = c11_jp1j;
      c11_m_b = c11_i5;
      c11_n_a = c11_m_a;
      c11_n_b = c11_m_b;
      if (c11_n_a > c11_n_b) {
        c11_d_overflow = false;
      } else {
        c11_d_overflow = (c11_n_b > 2147483646);
      }

      if (c11_d_overflow) {
        c11_g_st.site = &c11_re_emlrtRSI;
        c11_check_forloop_overflow_error(chartInstance, &c11_g_st,
          c11_d_overflow);
      }

      for (c11_i_i = c11_jp1j; c11_i_i <= c11_i5; c11_i_i++) {
        c11_i_x = c11_b_A[c11_i_i - 1];
        c11_d_y = c11_b_A[c11_jj - 1];
        c11_z = c11_i_x / c11_d_y;
        c11_b_A[c11_i_i - 1] = c11_z;
      }
    } else {
      c11_info = c11_b_j;
    }

    c11_f_b = c11_b_j;
    c11_c_c = 6 - c11_f_b;
    c11_i_a = c11_jj + 6;
    c11_f_c = c11_i_a;
    c11_k_a = c11_jj + 7;
    c11_g_c = c11_k_a;
    c11_f_st.site = &c11_oe_emlrtRSI;
    c11_m = c11_mmj;
    c11_c_n = c11_c_c;
    c11_d_ix0 = c11_jp1j;
    c11_b_iy0 = c11_f_c;
    c11_ia0 = c11_g_c;
    c11_g_st.site = &c11_se_emlrtRSI;
    c11_b_m = c11_m;
    c11_d_n = c11_c_n;
    c11_f_ix0 = c11_d_ix0;
    c11_d_iy0 = c11_b_iy0;
    c11_b_ia0 = c11_ia0;
    c11_h_st.site = &c11_te_emlrtRSI;
    c11_c_m = c11_b_m;
    c11_e_n = c11_d_n;
    c11_g_ix0 = c11_f_ix0;
    c11_e_iy0 = c11_d_iy0;
    c11_c_ia0 = c11_b_ia0;
    c11_i_st.site = &c11_ue_emlrtRSI;
    c11_d_m = c11_c_m;
    c11_f_n = c11_e_n;
    c11_h_ix0 = c11_g_ix0;
    c11_f_iy0 = c11_e_iy0;
    c11_d_ia0 = c11_c_ia0;
    c11_r_a = c11_d_ia0 - 1;
    c11_jA = c11_r_a;
    c11_jy = c11_f_iy0;
    c11_j_st.site = &c11_ve_emlrtRSI;
    c11_o_b = c11_f_n;
    c11_p_b = c11_o_b;
    if (c11_p_b < 1) {
      c11_e_overflow = false;
    } else {
      c11_e_overflow = (c11_p_b > 2147483646);
    }

    if (c11_e_overflow) {
      c11_k_st.site = &c11_re_emlrtRSI;
      c11_check_forloop_overflow_error(chartInstance, &c11_k_st, c11_e_overflow);
    }

    for (c11_g_j = 0; c11_g_j < c11_f_n; c11_g_j++) {
      c11_yjy = c11_b_A[c11_jy - 1];
      if (c11_yjy != 0.0) {
        c11_d_temp = -c11_yjy;
        c11_c_ix = c11_h_ix0 - 1;
        c11_q_b = c11_jA + 1;
        c11_i6 = c11_q_b;
        c11_u_a = c11_d_m;
        c11_r_b = c11_jA;
        c11_i7 = c11_u_a + c11_r_b;
        c11_j_st.site = &c11_we_emlrtRSI;
        c11_v_a = c11_i6;
        c11_s_b = c11_i7;
        c11_w_a = c11_v_a;
        c11_t_b = c11_s_b;
        if (c11_w_a > c11_t_b) {
          c11_f_overflow = false;
        } else {
          c11_f_overflow = (c11_t_b > 2147483646);
        }

        if (c11_f_overflow) {
          c11_k_st.site = &c11_re_emlrtRSI;
          c11_check_forloop_overflow_error(chartInstance, &c11_k_st,
            c11_f_overflow);
        }

        for (c11_ijA = c11_i6; c11_ijA <= c11_i7; c11_ijA++) {
          c11_b_A[c11_ijA - 1] += c11_b_A[c11_c_ix] * c11_d_temp;
          c11_x_a = c11_c_ix + 1;
          c11_c_ix = c11_x_a;
        }
      }

      c11_s_a = c11_jy + 6;
      c11_jy = c11_s_a;
      c11_t_a = c11_jA + 6;
      c11_jA = c11_t_a;
    }
  }

  if (((real_T)c11_info == 0.0) && (!(c11_b_A[35] != 0.0))) {
    c11_info = 6;
  }

  c11_b_info = c11_info;
  c11_c_info = c11_b_info;
  c11_d_st.site = &c11_je_emlrtRSI;
  c11_e_st.site = &c11_xe_emlrtRSI;
  for (c11_c_j = 0; c11_c_j < 6; c11_c_j++) {
    c11_d_j = c11_c_j;
    c11_jBcol = 28 * c11_d_j - 1;
    c11_jAcol = 6 * c11_d_j - 1;
    c11_i3 = c11_d_j;
    c11_f_st.site = &c11_ye_emlrtRSI;
    c11_c_b = c11_i3;
    c11_d_b = c11_c_b;
    if (c11_d_b < 1) {
      c11_b_overflow = false;
    } else {
      c11_b_overflow = (c11_d_b > 2147483646);
    }

    if (c11_b_overflow) {
      c11_g_st.site = &c11_re_emlrtRSI;
      c11_check_forloop_overflow_error(chartInstance, &c11_g_st, c11_b_overflow);
    }

    for (c11_b_k = 0; c11_b_k < c11_i3; c11_b_k++) {
      c11_c_k = c11_b_k;
      c11_b_kBcol = 28 * c11_c_k - 1;
      if (c11_b_A[(c11_c_k + c11_jAcol) + 1] != 0.0) {
        for (c11_g_i = 0; c11_g_i < 28; c11_g_i++) {
          c11_h_i = 1 + c11_g_i;
          c11_Y[c11_h_i + c11_jBcol] -= c11_b_A[(c11_c_k + c11_jAcol) + 1] *
            c11_Y[c11_h_i + c11_b_kBcol];
        }
      }
    }

    c11_y = c11_b_A[(c11_d_j + c11_jAcol) + 1];
    c11_b_temp = 1.0 / c11_y;
    for (c11_e_i = 0; c11_e_i < 28; c11_e_i++) {
      c11_h_i = 1 + c11_e_i;
      c11_Y[c11_h_i + c11_jBcol] *= c11_b_temp;
    }
  }

  c11_d_st.site = &c11_ke_emlrtRSI;
  c11_e_st.site = &c11_xe_emlrtRSI;
  for (c11_e_j = 5; c11_e_j >= 0; c11_e_j--) {
    c11_b_jBcol = 28 * c11_e_j - 1;
    c11_b_jAcol = 6 * c11_e_j - 1;
    c11_i4 = c11_e_j;
    c11_f_st.site = &c11_af_emlrtRSI;
    c11_overflow = false;
    if (c11_overflow) {
      c11_g_st.site = &c11_re_emlrtRSI;
      c11_check_forloop_overflow_error(chartInstance, &c11_g_st, c11_overflow);
    }

    for (c11_k = c11_i4 + 2; c11_k < 7; c11_k++) {
      c11_kBcol = 28 * (c11_k - 1) - 1;
      if (c11_b_A[c11_k + c11_b_jAcol] != 0.0) {
        for (c11_d_i = 0; c11_d_i < 28; c11_d_i++) {
          c11_f_i = 1 + c11_d_i;
          c11_Y[c11_f_i + c11_b_jBcol] -= c11_b_A[c11_k + c11_b_jAcol] *
            c11_Y[c11_f_i + c11_kBcol];
        }
      }
    }
  }

  for (c11_f_j = 4; c11_f_j >= 0; c11_f_j--) {
    if (c11_ipiv[c11_f_j] != c11_f_j + 1) {
      c11_jp = c11_ipiv[c11_f_j] - 1;
      for (c11_b_i = 0; c11_b_i < 28; c11_b_i++) {
        c11_c_i = c11_b_i;
        c11_temp = c11_Y[c11_c_i + 28 * c11_f_j];
        c11_Y[c11_c_i + 28 * c11_f_j] = c11_Y[c11_c_i + 28 * c11_jp];
        c11_Y[c11_c_i + 28 * c11_jp] = c11_temp;
      }
    }
  }

  if ((real_T)c11_c_info > 0.0) {
    c11_c_st.site = &c11_ge_emlrtRSI;
    c11_d_st.site = &c11_jd_emlrtRSI;
    c11_warning(chartInstance, &c11_d_st);
  }
}

static void c11_check_forloop_overflow_error(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, const emlrtStack *c11_sp, boolean_T c11_overflow)
{
  static char_T c11_b_cv[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o',
    'p', '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  static char_T c11_b_cv1[5] = { 'i', 'n', 't', '3', '2' };

  const mxArray *c11_b_y = NULL;
  const mxArray *c11_c_y = NULL;
  const mxArray *c11_y = NULL;
  (void)chartInstance;
  if (c11_overflow) {
    c11_y = NULL;
    sf_mex_assign(&c11_y, sf_mex_create("y", c11_b_cv, 10, 0U, 1U, 0U, 2, 1, 34),
                  false);
    c11_b_y = NULL;
    sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_b_cv, 10, 0U, 1U, 0U, 2, 1,
      34), false);
    c11_c_y = NULL;
    sf_mex_assign(&c11_c_y, sf_mex_create("y", c11_b_cv1, 10, 0U, 1U, 0U, 2, 1,
      5), false);
    sf_mex_call(c11_sp, &c11_i_emlrtMCI, "error", 0U, 2U, 14, c11_y, 14,
                sf_mex_call(c11_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c11_sp, NULL, "message", 1U, 2U, 14, c11_b_y, 14, c11_c_y)));
  }
}

static void c11_INSFilterEKF_pose(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, const emlrtStack *c11_sp, c11_insfilterAsync *c11_obj, real_T
  c11_pos[3], real_T c11_orient[9], real_T c11_vel[3])
{
  c11_insfilterAsync *c11_b_obj;
  c11_insfilterAsync *c11_c_obj;
  c11_insfilterAsync *c11_d_obj;
  c11_insfilterAsync *c11_e_obj;
  c11_insfilterAsync *c11_f_obj;
  c11_insfilterAsync *c11_g_obj;
  c11_quaternion c11_q;
  emlrtStack c11_b_st;
  emlrtStack c11_c_st;
  emlrtStack c11_st;
  real_T c11_s[28];
  real_T c11_varargin_1[4];
  real_T c11_aasq;
  real_T c11_ab2;
  real_T c11_ac2;
  real_T c11_ad2;
  real_T c11_b_magE;
  real_T c11_b_magN;
  real_T c11_bbsq;
  real_T c11_bc2;
  real_T c11_bd2;
  real_T c11_c_magE;
  real_T c11_c_magN;
  real_T c11_ccsq;
  real_T c11_cd2;
  real_T c11_ddsq;
  real_T c11_magE;
  real_T c11_magN;
  real_T c11_n;
  real_T c11_ta;
  real_T c11_tb;
  real_T c11_tc;
  real_T c11_td;
  int32_T c11_i;
  int32_T c11_i1;
  int32_T c11_i2;
  int32_T c11_i3;
  int32_T c11_i4;
  int32_T c11_i5;
  c11_st.prev = c11_sp;
  c11_st.tls = c11_sp->tls;
  c11_st.site = &c11_ef_emlrtRSI;
  c11_b_st.prev = &c11_st;
  c11_b_st.tls = c11_st.tls;
  c11_c_st.prev = &c11_b_st;
  c11_c_st.tls = c11_b_st.tls;
  c11_b_obj = c11_obj;
  c11_b_st.site = &c11_if_emlrtRSI;
  c11_c_obj = c11_b_obj;
  for (c11_i = 0; c11_i < 28; c11_i++) {
    c11_s[c11_i] = c11_c_obj->pState[c11_i];
  }

  c11_magN = c11_s[22];
  c11_magE = c11_s[23];
  c11_s[22] = c11_magN;
  c11_s[23] = c11_magE;
  for (c11_i1 = 0; c11_i1 < 4; c11_i1++) {
    c11_varargin_1[c11_i1] = c11_s[c11_i1];
  }

  c11_q.a = c11_varargin_1[0];
  c11_q.b = c11_varargin_1[1];
  c11_q.c = c11_varargin_1[2];
  c11_q.d = c11_varargin_1[3];
  c11_st.site = &c11_ff_emlrtRSI;
  c11_b_st.site = &c11_jf_emlrtRSI;
  c11_n = ((c11_q.a * c11_q.a + c11_q.b * c11_q.b) + c11_q.c * c11_q.c) +
    c11_q.d * c11_q.d;
  c11_c_st.site = &c11_kf_emlrtRSI;
  c11_b_sqrt(chartInstance, &c11_c_st, &c11_n);
  c11_q.a /= c11_n;
  c11_q.b /= c11_n;
  c11_q.c /= c11_n;
  c11_q.d /= c11_n;
  c11_ta = c11_q.a;
  c11_tb = c11_q.b;
  c11_tc = c11_q.c;
  c11_td = c11_q.d;
  c11_ab2 = c11_ta * c11_tb * 2.0;
  c11_ac2 = c11_ta * c11_tc * 2.0;
  c11_ad2 = c11_ta * c11_td * 2.0;
  c11_bc2 = c11_tb * c11_tc * 2.0;
  c11_bd2 = c11_tb * c11_td * 2.0;
  c11_cd2 = c11_tc * c11_td * 2.0;
  c11_aasq = c11_ta * c11_ta * 2.0 - 1.0;
  c11_bbsq = c11_tb * c11_tb * 2.0;
  c11_ccsq = c11_tc * c11_tc * 2.0;
  c11_ddsq = c11_td * c11_td * 2.0;
  c11_orient[0] = c11_aasq + c11_bbsq;
  c11_orient[3] = c11_bc2 + c11_ad2;
  c11_orient[6] = c11_bd2 - c11_ac2;
  c11_orient[1] = c11_bc2 - c11_ad2;
  c11_orient[4] = c11_aasq + c11_ccsq;
  c11_orient[7] = c11_cd2 + c11_ab2;
  c11_orient[2] = c11_bd2 + c11_ac2;
  c11_orient[5] = c11_cd2 - c11_ab2;
  c11_orient[8] = c11_aasq + c11_ddsq;
  c11_st.site = &c11_gf_emlrtRSI;
  c11_d_obj = c11_obj;
  c11_b_st.site = &c11_lf_emlrtRSI;
  c11_e_obj = c11_d_obj;
  for (c11_i2 = 0; c11_i2 < 28; c11_i2++) {
    c11_s[c11_i2] = c11_e_obj->pState[c11_i2];
  }

  c11_b_magN = c11_s[22];
  c11_b_magE = c11_s[23];
  c11_s[22] = c11_b_magN;
  c11_s[23] = c11_b_magE;
  for (c11_i3 = 0; c11_i3 < 3; c11_i3++) {
    c11_pos[c11_i3] = c11_s[c11_i3 + 7];
  }

  c11_st.site = &c11_hf_emlrtRSI;
  c11_f_obj = c11_obj;
  c11_b_st.site = &c11_mf_emlrtRSI;
  c11_g_obj = c11_f_obj;
  for (c11_i4 = 0; c11_i4 < 28; c11_i4++) {
    c11_s[c11_i4] = c11_g_obj->pState[c11_i4];
  }

  c11_c_magN = c11_s[22];
  c11_c_magE = c11_s[23];
  c11_s[22] = c11_c_magN;
  c11_s[23] = c11_c_magE;
  for (c11_i5 = 0; c11_i5 < 3; c11_i5++) {
    c11_vel[c11_i5] = c11_s[c11_i5 + 10];
  }
}

static real_T c11_emlrt_marshallIn(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c11_c_count, const char_T *c11_identifier)
{
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y;
  c11_thisId.fIdentifier = (const char_T *)c11_identifier;
  c11_thisId.fParent = NULL;
  c11_thisId.bParentIsCell = false;
  c11_y = c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_c_count),
    &c11_thisId);
  sf_mex_destroy(&c11_c_count);
  return c11_y;
}

static real_T c11_b_emlrt_marshallIn(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  real_T c11_d;
  real_T c11_y;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_d, 1, 0, 0U, 0, 0U, 0);
  c11_y = c11_d;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_c_emlrt_marshallIn(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c11_b_cov_out, const char_T *c11_identifier,
  real_T c11_y[784])
{
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = (const char_T *)c11_identifier;
  c11_thisId.fParent = NULL;
  c11_thisId.bParentIsCell = false;
  c11_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_cov_out), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_b_cov_out);
}

static void c11_d_emlrt_marshallIn(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[784])
{
  real_T c11_dv[784];
  int32_T c11_i;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv, 1, 0, 0U, 1, 0U, 2, 28,
                28);
  for (c11_i = 0; c11_i < 784; c11_i++) {
    c11_y[c11_i] = c11_dv[c11_i];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_e_emlrt_marshallIn(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c11_b_rot_map, const char_T *c11_identifier,
  real_T c11_y[9])
{
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = (const char_T *)c11_identifier;
  c11_thisId.fParent = NULL;
  c11_thisId.bParentIsCell = false;
  c11_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_rot_map), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_b_rot_map);
}

static void c11_f_emlrt_marshallIn(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[9])
{
  real_T c11_dv[9];
  int32_T c11_i;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c11_i = 0; c11_i < 9; c11_i++) {
    c11_y[c11_i] = c11_dv[c11_i];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_g_emlrt_marshallIn(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c11_b_state_out, const char_T *c11_identifier,
  real_T c11_y[28])
{
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = (const char_T *)c11_identifier;
  c11_thisId.fParent = NULL;
  c11_thisId.bParentIsCell = false;
  c11_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_state_out), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_b_state_out);
}

static void c11_h_emlrt_marshallIn(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[28])
{
  real_T c11_dv[28];
  int32_T c11_i;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv, 1, 0, 0U, 1, 0U, 1, 28);
  for (c11_i = 0; c11_i < 28; c11_i++) {
    c11_y[c11_i] = c11_dv[c11_i];
  }

  sf_mex_destroy(&c11_u);
}

static uint8_T c11_i_emlrt_marshallIn(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c11_b_is_active_c11_car_model_FIXED, const
  char_T *c11_identifier)
{
  emlrtMsgIdentifier c11_thisId;
  uint8_T c11_y;
  c11_thisId.fIdentifier = (const char_T *)c11_identifier;
  c11_thisId.fParent = NULL;
  c11_thisId.bParentIsCell = false;
  c11_y = c11_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_b_is_active_c11_car_model_FIXED), &c11_thisId);
  sf_mex_destroy(&c11_b_is_active_c11_car_model_FIXED);
  return c11_y;
}

static uint8_T c11_j_emlrt_marshallIn(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  uint8_T c11_b_u;
  uint8_T c11_y;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_b_u, 1, 3, 0U, 0, 0U, 0);
  c11_y = c11_b_u;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_slStringInitializeDynamicBuffers
  (SFc11_car_model_FIXEDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c11_chart_data_browse_helper(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, int32_T c11_ssIdNumber, const mxArray **c11_mxData, uint8_T
  *c11_isValueTooBig)
{
  real_T c11_d;
  real_T c11_d1;
  *c11_mxData = NULL;
  *c11_mxData = NULL;
  *c11_isValueTooBig = 0U;
  switch (c11_ssIdNumber) {
   case 41U:
    c11_d = *chartInstance->c11_b_count;
    sf_mex_assign(c11_mxData, sf_mex_create("mxData", &c11_d, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 42U:
    c11_d1 = *chartInstance->c11_b_count;
    sf_mex_assign(c11_mxData, sf_mex_create("mxData", &c11_d1, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 14U:
    sf_mex_assign(c11_mxData, sf_mex_create("mxData",
      *chartInstance->c11_rot_map, 0, 0U, 1U, 0U, 2, 3, 3), false);
    break;

   case 4U:
    sf_mex_assign(c11_mxData, sf_mex_create("mxData",
      *chartInstance->c11_velocity, 0, 0U, 1U, 0U, 2, 1, 3), false);
    break;

   case 27U:
    sf_mex_assign(c11_mxData, sf_mex_create("mxData",
      *chartInstance->c11_state_out, 0, 0U, 1U, 0U, 1, 28), false);
    break;

   case 6U:
    sf_mex_assign(c11_mxData, sf_mex_create("mxData",
      *chartInstance->c11_position, 0, 0U, 1U, 0U, 2, 1, 3), false);
    break;

   case 7U:
    sf_mex_assign(c11_mxData, sf_mex_create("mxData",
      *chartInstance->c11_acceleration, 0, 0U, 1U, 0U, 2, 1, 3), false);
    break;

   case 8U:
    sf_mex_assign(c11_mxData, sf_mex_create("mxData",
      *chartInstance->c11_angularVelocity, 0, 0U, 1U, 0U, 2, 1, 3), false);
    break;

   case 13U:
    sf_mex_assign(c11_mxData, sf_mex_create("mxData",
      *chartInstance->c11_magField, 0, 0U, 1U, 0U, 2, 1, 3), false);
    break;

   case 9U:
    sf_mex_assign(c11_mxData, sf_mex_create("mxData",
      *chartInstance->c11_state_in, 0, 0U, 1U, 0U, 1, 28), false);
    break;

   case 36U:
    sf_mex_assign(c11_mxData, sf_mex_create("mxData", *chartInstance->c11_cov_in,
      0, 0U, 1U, 0U, 2, 28, 28), false);
    break;

   case 16U:
    sf_mex_assign(c11_mxData, sf_mex_create("mxData", &chartInstance->c11_covG,
      0, 0U, 0U, 0U, 0), false);
    break;

   case 17U:
    sf_mex_assign(c11_mxData, sf_mex_create("mxData", &chartInstance->c11_covA,
      0, 0U, 0U, 0U, 0), false);
    break;

   case 18U:
    sf_mex_assign(c11_mxData, sf_mex_create("mxData", &chartInstance->c11_covM,
      0, 0U, 0U, 0U, 0), false);
    break;

   case 20U:
    sf_mex_assign(c11_mxData, sf_mex_create("mxData", &chartInstance->c11_covP,
      0, 0U, 0U, 0U, 0), false);
    break;

   case 23U:
    sf_mex_assign(c11_mxData, sf_mex_create("mxData", &chartInstance->c11_covV,
      0, 0U, 0U, 0U, 0), false);
    break;

   case 29U:
    sf_mex_assign(c11_mxData, sf_mex_create("mxData",
      &chartInstance->c11_fusion_t, 0, 0U, 0U, 0U, 0), false);
    break;

   case 31U:
    sf_mex_assign(c11_mxData, sf_mex_create("mxData",
      chartInstance->c11_location_lla_IC, 0, 0U, 1U, 0U, 2, 1, 3), false);
    break;

   case 37U:
    sf_mex_assign(c11_mxData, sf_mex_create("mxData",
      *chartInstance->c11_cov_out, 0, 0U, 1U, 0U, 2, 28, 28), false);
    break;

   case 40U:
    sf_mex_assign(c11_mxData, sf_mex_create("mxData",
      chartInstance->c11_noise_state, 0, 0U, 1U, 0U, 1, 28), false);
    break;

   case 43U:
    sf_mex_assign(c11_mxData, sf_mex_create("mxData",
      &chartInstance->c11_gps_ratio, 0, 0U, 0U, 0U, 0), false);
    break;
  }
}

static const mxArray *c11_feval(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, const emlrtStack *c11_sp, const mxArray *c11_input0, const
  mxArray *c11_input1)
{
  const mxArray *c11_m = NULL;
  (void)chartInstance;
  c11_m = NULL;
  sf_mex_assign(&c11_m, sf_mex_call(c11_sp, NULL, "feval", 1U, 2U, 14,
    sf_mex_dup(c11_input0), 14, sf_mex_dup(c11_input1)), false);
  sf_mex_destroy(&c11_input0);
  sf_mex_destroy(&c11_input1);
  return c11_m;
}

static void c11_b_feval(SFc11_car_model_FIXEDInstanceStruct *chartInstance,
  const emlrtStack *c11_sp, const mxArray *c11_input0, const mxArray *c11_input1)
{
  (void)chartInstance;
  sf_mex_call(c11_sp, NULL, "feval", 0U, 2U, 14, sf_mex_dup(c11_input0), 14,
              sf_mex_dup(c11_input1));
  sf_mex_destroy(&c11_input0);
  sf_mex_destroy(&c11_input1);
}

static void c11_b_emlrt_update_log_2(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c11_in[3], emlrtLocationLoggingDataType c11_table[],
  int32_T c11_index)
{
  emlrtLocationLoggingDataType *c11_b_table;
  emlrtLocationLoggingHistogramType *c11_histTable;
  real_T c11_inDouble;
  real_T c11_localMax;
  real_T c11_localMin;
  real_T c11_significand;
  int32_T c11_b_i;
  int32_T c11_exponent;
  int32_T c11_i;
  boolean_T c11_isLoggingEnabledHere;
  (void)chartInstance;
  c11_isLoggingEnabledHere = (c11_index >= 0);
  if (c11_isLoggingEnabledHere) {
    c11_b_table = (emlrtLocationLoggingDataType *)&c11_table[c11_index];
    c11_localMin = c11_b_table[0U].SimMin;
    c11_localMax = c11_b_table[0U].SimMax;
    c11_histTable = c11_b_table[0U].HistogramTable;
    for (c11_i = 0; c11_i < 3; c11_i++) {
      /* Simulation Min-Max logging. */
      if (c11_in[c11_i] < c11_localMin) {
        c11_localMin = c11_in[c11_i];
      }

      if (c11_in[c11_i] > c11_localMax) {
        c11_localMax = c11_in[c11_i];
      }

      /* Histogram logging. */
      c11_inDouble = c11_in[c11_i];
      c11_histTable->TotalNumberOfValues++;
      if (c11_inDouble == 0.0) {
        c11_histTable->NumberOfZeros++;
      } else {
        c11_histTable->SimSum += c11_inDouble;
        if ((!muDoubleScalarIsInf(c11_inDouble)) && (!muDoubleScalarIsNaN
             (c11_inDouble))) {
          c11_significand = frexp(c11_inDouble, &c11_exponent);
          if (c11_exponent > 128) {
            c11_exponent = 128;
          }

          if (c11_exponent < -127) {
            c11_exponent = -127;
          }

          if (c11_significand < 0.0) {
            c11_histTable->NumberOfNegativeValues++;
            c11_histTable->HistogramOfNegativeValues[127 + c11_exponent]++;
          } else {
            c11_histTable->NumberOfPositiveValues++;
            c11_histTable->HistogramOfPositiveValues[127 + c11_exponent]++;
          }
        }
      }
    }

    c11_b_table[0U].SimMin = c11_localMin;
    c11_b_table[0U].SimMax = c11_localMax;

    /* IsAlwaysInteger logging. */
    c11_b_i = 0;
    while (c11_b_table[0U].IsAlwaysInteger && (c11_b_i < 3)) {
      if (c11_in[c11_b_i] != muDoubleScalarFloor(c11_in[c11_b_i])) {
        c11_b_table[0U].IsAlwaysInteger = false;
      }

      c11_b_i++;
    }
  }
}

static void c11_b_emlrt_update_log_3(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c11_in[28], emlrtLocationLoggingDataType c11_table[],
  int32_T c11_index)
{
  emlrtLocationLoggingDataType *c11_b_table;
  emlrtLocationLoggingHistogramType *c11_histTable;
  real_T c11_inDouble;
  real_T c11_localMax;
  real_T c11_localMin;
  real_T c11_significand;
  int32_T c11_b_i;
  int32_T c11_exponent;
  int32_T c11_i;
  boolean_T c11_isLoggingEnabledHere;
  (void)chartInstance;
  c11_isLoggingEnabledHere = (c11_index >= 0);
  if (c11_isLoggingEnabledHere) {
    c11_b_table = (emlrtLocationLoggingDataType *)&c11_table[c11_index];
    c11_localMin = c11_b_table[0U].SimMin;
    c11_localMax = c11_b_table[0U].SimMax;
    c11_histTable = c11_b_table[0U].HistogramTable;
    for (c11_i = 0; c11_i < 28; c11_i++) {
      /* Simulation Min-Max logging. */
      if (c11_in[c11_i] < c11_localMin) {
        c11_localMin = c11_in[c11_i];
      }

      if (c11_in[c11_i] > c11_localMax) {
        c11_localMax = c11_in[c11_i];
      }

      /* Histogram logging. */
      c11_inDouble = c11_in[c11_i];
      c11_histTable->TotalNumberOfValues++;
      if (c11_inDouble == 0.0) {
        c11_histTable->NumberOfZeros++;
      } else {
        c11_histTable->SimSum += c11_inDouble;
        if ((!muDoubleScalarIsInf(c11_inDouble)) && (!muDoubleScalarIsNaN
             (c11_inDouble))) {
          c11_significand = frexp(c11_inDouble, &c11_exponent);
          if (c11_exponent > 128) {
            c11_exponent = 128;
          }

          if (c11_exponent < -127) {
            c11_exponent = -127;
          }

          if (c11_significand < 0.0) {
            c11_histTable->NumberOfNegativeValues++;
            c11_histTable->HistogramOfNegativeValues[127 + c11_exponent]++;
          } else {
            c11_histTable->NumberOfPositiveValues++;
            c11_histTable->HistogramOfPositiveValues[127 + c11_exponent]++;
          }
        }
      }
    }

    c11_b_table[0U].SimMin = c11_localMin;
    c11_b_table[0U].SimMax = c11_localMax;

    /* IsAlwaysInteger logging. */
    c11_b_i = 0;
    while (c11_b_table[0U].IsAlwaysInteger && (c11_b_i < 28)) {
      if (c11_in[c11_b_i] != muDoubleScalarFloor(c11_in[c11_b_i])) {
        c11_b_table[0U].IsAlwaysInteger = false;
      }

      c11_b_i++;
    }
  }
}

static void c11_b_emlrt_update_log_4(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c11_in[784], emlrtLocationLoggingDataType c11_table[],
  int32_T c11_index)
{
  emlrtLocationLoggingDataType *c11_b_table;
  emlrtLocationLoggingHistogramType *c11_histTable;
  real_T c11_inDouble;
  real_T c11_localMax;
  real_T c11_localMin;
  real_T c11_significand;
  int32_T c11_b_i;
  int32_T c11_exponent;
  int32_T c11_i;
  boolean_T c11_isLoggingEnabledHere;
  (void)chartInstance;
  c11_isLoggingEnabledHere = (c11_index >= 0);
  if (c11_isLoggingEnabledHere) {
    c11_b_table = (emlrtLocationLoggingDataType *)&c11_table[c11_index];
    c11_localMin = c11_b_table[0U].SimMin;
    c11_localMax = c11_b_table[0U].SimMax;
    c11_histTable = c11_b_table[0U].HistogramTable;
    for (c11_i = 0; c11_i < 784; c11_i++) {
      /* Simulation Min-Max logging. */
      if (c11_in[c11_i] < c11_localMin) {
        c11_localMin = c11_in[c11_i];
      }

      if (c11_in[c11_i] > c11_localMax) {
        c11_localMax = c11_in[c11_i];
      }

      /* Histogram logging. */
      c11_inDouble = c11_in[c11_i];
      c11_histTable->TotalNumberOfValues++;
      if (c11_inDouble == 0.0) {
        c11_histTable->NumberOfZeros++;
      } else {
        c11_histTable->SimSum += c11_inDouble;
        if ((!muDoubleScalarIsInf(c11_inDouble)) && (!muDoubleScalarIsNaN
             (c11_inDouble))) {
          c11_significand = frexp(c11_inDouble, &c11_exponent);
          if (c11_exponent > 128) {
            c11_exponent = 128;
          }

          if (c11_exponent < -127) {
            c11_exponent = -127;
          }

          if (c11_significand < 0.0) {
            c11_histTable->NumberOfNegativeValues++;
            c11_histTable->HistogramOfNegativeValues[127 + c11_exponent]++;
          } else {
            c11_histTable->NumberOfPositiveValues++;
            c11_histTable->HistogramOfPositiveValues[127 + c11_exponent]++;
          }
        }
      }
    }

    c11_b_table[0U].SimMin = c11_localMin;
    c11_b_table[0U].SimMax = c11_localMax;

    /* IsAlwaysInteger logging. */
    c11_b_i = 0;
    while (c11_b_table[0U].IsAlwaysInteger && (c11_b_i < 784)) {
      if (c11_in[c11_b_i] != muDoubleScalarFloor(c11_in[c11_b_i])) {
        c11_b_table[0U].IsAlwaysInteger = false;
      }

      c11_b_i++;
    }
  }
}

static void c11_b_emlrt_update_log_5(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c11_in[9], emlrtLocationLoggingDataType c11_table[],
  int32_T c11_index)
{
  emlrtLocationLoggingDataType *c11_b_table;
  emlrtLocationLoggingHistogramType *c11_histTable;
  real_T c11_inDouble;
  real_T c11_localMax;
  real_T c11_localMin;
  real_T c11_significand;
  int32_T c11_b_i;
  int32_T c11_exponent;
  int32_T c11_i;
  boolean_T c11_isLoggingEnabledHere;
  (void)chartInstance;
  c11_isLoggingEnabledHere = (c11_index >= 0);
  if (c11_isLoggingEnabledHere) {
    c11_b_table = (emlrtLocationLoggingDataType *)&c11_table[c11_index];
    c11_localMin = c11_b_table[0U].SimMin;
    c11_localMax = c11_b_table[0U].SimMax;
    c11_histTable = c11_b_table[0U].HistogramTable;
    for (c11_i = 0; c11_i < 9; c11_i++) {
      /* Simulation Min-Max logging. */
      if (c11_in[c11_i] < c11_localMin) {
        c11_localMin = c11_in[c11_i];
      }

      if (c11_in[c11_i] > c11_localMax) {
        c11_localMax = c11_in[c11_i];
      }

      /* Histogram logging. */
      c11_inDouble = c11_in[c11_i];
      c11_histTable->TotalNumberOfValues++;
      if (c11_inDouble == 0.0) {
        c11_histTable->NumberOfZeros++;
      } else {
        c11_histTable->SimSum += c11_inDouble;
        if ((!muDoubleScalarIsInf(c11_inDouble)) && (!muDoubleScalarIsNaN
             (c11_inDouble))) {
          c11_significand = frexp(c11_inDouble, &c11_exponent);
          if (c11_exponent > 128) {
            c11_exponent = 128;
          }

          if (c11_exponent < -127) {
            c11_exponent = -127;
          }

          if (c11_significand < 0.0) {
            c11_histTable->NumberOfNegativeValues++;
            c11_histTable->HistogramOfNegativeValues[127 + c11_exponent]++;
          } else {
            c11_histTable->NumberOfPositiveValues++;
            c11_histTable->HistogramOfPositiveValues[127 + c11_exponent]++;
          }
        }
      }
    }

    c11_b_table[0U].SimMin = c11_localMin;
    c11_b_table[0U].SimMax = c11_localMax;

    /* IsAlwaysInteger logging. */
    c11_b_i = 0;
    while (c11_b_table[0U].IsAlwaysInteger && (c11_b_i < 9)) {
      if (c11_in[c11_b_i] != muDoubleScalarFloor(c11_in[c11_b_i])) {
        c11_b_table[0U].IsAlwaysInteger = false;
      }

      c11_b_i++;
    }
  }
}

static void c11_b_sqrt(SFc11_car_model_FIXEDInstanceStruct *chartInstance, const
  emlrtStack *c11_sp, real_T *c11_x)
{
  static char_T c11_b_cv[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i',
    'n', 'E', 'r', 'r', 'o', 'r' };

  static char_T c11_b_cv1[4] = { 's', 'q', 'r', 't' };

  const mxArray *c11_b_y = NULL;
  const mxArray *c11_c_y = NULL;
  const mxArray *c11_y = NULL;
  real_T c11_b_x;
  boolean_T c11_b_p;
  boolean_T c11_p;
  (void)chartInstance;
  c11_b_x = *c11_x;
  if (c11_b_x < 0.0) {
    c11_p = true;
  } else {
    c11_p = false;
  }

  c11_b_p = c11_p;
  if (c11_b_p) {
    c11_y = NULL;
    sf_mex_assign(&c11_y, sf_mex_create("y", c11_b_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c11_b_y = NULL;
    sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_b_cv, 10, 0U, 1U, 0U, 2, 1,
      30), false);
    c11_c_y = NULL;
    sf_mex_assign(&c11_c_y, sf_mex_create("y", c11_b_cv1, 10, 0U, 1U, 0U, 2, 1,
      4), false);
    sf_mex_call(c11_sp, &c11_f_emlrtMCI, "error", 0U, 2U, 14, c11_y, 14,
                sf_mex_call(c11_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c11_sp, NULL, "message", 1U, 2U, 14, c11_b_y, 14, c11_c_y)));
  }

  *c11_x = muDoubleScalarSqrt(*c11_x);
}

static void c11_b_BasicEKF_correctEqn(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance, const emlrtStack *c11_sp, c11_insfilterAsync *c11_obj, real_T
  c11_x[28], real_T c11_P[784], real_T c11_h[3], real_T c11_H[84], real_T c11_z
  [3], real_T c11_R[9], real_T c11_innov[3], real_T c11_innovCov[9])
{
  ptrdiff_t c11_b_k_t;
  ptrdiff_t c11_b_lda_t;
  ptrdiff_t c11_b_ldb_t;
  ptrdiff_t c11_b_ldc_t;
  ptrdiff_t c11_b_m_t;
  ptrdiff_t c11_b_n_t;
  ptrdiff_t c11_c_k_t;
  ptrdiff_t c11_c_lda_t;
  ptrdiff_t c11_c_ldb_t;
  ptrdiff_t c11_c_ldc_t;
  ptrdiff_t c11_c_m_t;
  ptrdiff_t c11_c_n_t;
  ptrdiff_t c11_k_t;
  ptrdiff_t c11_lda_t;
  ptrdiff_t c11_ldb_t;
  ptrdiff_t c11_ldc_t;
  ptrdiff_t c11_m_t;
  ptrdiff_t c11_n_t;
  c11_insfilterAsync *c11_b_obj;
  emlrtStack c11_b_st;
  emlrtStack c11_c_st;
  emlrtStack c11_d_st;
  emlrtStack c11_e_st;
  emlrtStack c11_f_st;
  emlrtStack c11_g_st;
  emlrtStack c11_st;
  real_T c11_h_y[784];
  real_T c11_i_y[784];
  real_T c11_W[84];
  real_T c11_y[84];
  real_T c11_g_y[28];
  real_T c11_A[9];
  real_T c11_idx[4];
  real_T c11_k_y[4];
  real_T c11_qparts[4];
  real_T c11_a;
  real_T c11_a21;
  real_T c11_alpha1;
  real_T c11_b_alpha1;
  real_T c11_b_beta1;
  real_T c11_b_d;
  real_T c11_b_x;
  real_T c11_b_y;
  real_T c11_beta1;
  real_T c11_c_alpha1;
  real_T c11_c_beta1;
  real_T c11_c_d;
  real_T c11_c_x;
  real_T c11_c_y;
  real_T c11_d;
  real_T c11_d_x;
  real_T c11_d_y;
  real_T c11_e_x;
  real_T c11_e_y;
  real_T c11_f_x;
  real_T c11_f_y;
  real_T c11_g_x;
  real_T c11_h_x;
  real_T c11_i_x;
  real_T c11_j_x;
  real_T c11_j_y;
  real_T c11_k_x;
  real_T c11_l_x;
  real_T c11_l_y;
  real_T c11_m_x;
  real_T c11_maxval;
  real_T c11_n;
  real_T c11_n_x;
  real_T c11_o_x;
  real_T c11_p_x;
  real_T c11_q_x;
  real_T c11_r_x;
  real_T c11_s_x;
  real_T c11_t_x;
  real_T c11_u_x;
  int32_T c11_b_k;
  int32_T c11_c_k;
  int32_T c11_d_k;
  int32_T c11_i;
  int32_T c11_i1;
  int32_T c11_i10;
  int32_T c11_i11;
  int32_T c11_i12;
  int32_T c11_i13;
  int32_T c11_i14;
  int32_T c11_i15;
  int32_T c11_i16;
  int32_T c11_i17;
  int32_T c11_i18;
  int32_T c11_i19;
  int32_T c11_i2;
  int32_T c11_i20;
  int32_T c11_i3;
  int32_T c11_i4;
  int32_T c11_i5;
  int32_T c11_i6;
  int32_T c11_i7;
  int32_T c11_i8;
  int32_T c11_i9;
  int32_T c11_k;
  int32_T c11_r1;
  int32_T c11_r2;
  int32_T c11_r3;
  int32_T c11_rtemp;
  char_T c11_TRANSA1;
  char_T c11_TRANSB1;
  char_T c11_b_TRANSA1;
  char_T c11_b_TRANSB1;
  char_T c11_c_TRANSA1;
  char_T c11_c_TRANSB1;
  c11_st.prev = c11_sp;
  c11_st.tls = c11_sp->tls;
  c11_st.site = &c11_yc_emlrtRSI;
  c11_b_st.prev = &c11_st;
  c11_b_st.tls = c11_st.tls;
  c11_c_st.prev = &c11_b_st;
  c11_c_st.tls = c11_b_st.tls;
  c11_d_st.prev = &c11_c_st;
  c11_d_st.tls = c11_c_st.tls;
  c11_e_st.prev = &c11_d_st;
  c11_e_st.tls = c11_d_st.tls;
  c11_f_st.prev = &c11_e_st;
  c11_f_st.tls = c11_e_st.tls;
  c11_g_st.prev = &c11_f_st;
  c11_g_st.tls = c11_f_st.tls;
  c11_b_st.site = &c11_bd_emlrtRSI;
  c11_c_st.site = &c11_ed_emlrtRSI;
  c11_d_st.site = &c11_ec_emlrtRSI;
  c11_e_st.site = &c11_fc_emlrtRSI;
  c11_f_st.site = &c11_gc_emlrtRSI;
  c11_TRANSB1 = 'N';
  c11_TRANSA1 = 'N';
  c11_alpha1 = 1.0;
  c11_beta1 = 0.0;
  c11_m_t = (ptrdiff_t)3;
  c11_n_t = (ptrdiff_t)28;
  c11_k_t = (ptrdiff_t)28;
  c11_lda_t = (ptrdiff_t)3;
  c11_ldb_t = (ptrdiff_t)28;
  c11_ldc_t = (ptrdiff_t)3;
  dgemm(&c11_TRANSA1, &c11_TRANSB1, &c11_m_t, &c11_n_t, &c11_k_t, &c11_alpha1,
        &c11_H[0], &c11_lda_t, &c11_P[0], &c11_ldb_t, &c11_beta1, &c11_y[0],
        &c11_ldc_t);
  for (c11_i = 0; c11_i < 3; c11_i++) {
    c11_i2 = 0;
    for (c11_i3 = 0; c11_i3 < 3; c11_i3++) {
      c11_innovCov[c11_i2 + c11_i] = 0.0;
      c11_i5 = 0;
      for (c11_i6 = 0; c11_i6 < 28; c11_i6++) {
        c11_innovCov[c11_i2 + c11_i] += c11_y[c11_i5 + c11_i] * c11_H[c11_i5 +
          c11_i3];
        c11_i5 += 3;
      }

      c11_i2 += 3;
    }
  }

  for (c11_i1 = 0; c11_i1 < 9; c11_i1++) {
    c11_innovCov[c11_i1] += c11_R[c11_i1];
  }

  for (c11_i4 = 0; c11_i4 < 3; c11_i4++) {
    c11_innov[c11_i4] = c11_z[c11_i4] - c11_h[c11_i4];
  }

  c11_b_st.site = &c11_cd_emlrtRSI;
  c11_c_st.site = &c11_ec_emlrtRSI;
  c11_d_st.site = &c11_fc_emlrtRSI;
  c11_e_st.site = &c11_gc_emlrtRSI;
  c11_b_TRANSB1 = 'T';
  c11_b_TRANSA1 = 'N';
  c11_b_alpha1 = 1.0;
  c11_b_beta1 = 0.0;
  c11_b_m_t = (ptrdiff_t)28;
  c11_b_n_t = (ptrdiff_t)3;
  c11_b_k_t = (ptrdiff_t)28;
  c11_b_lda_t = (ptrdiff_t)28;
  c11_b_ldb_t = (ptrdiff_t)3;
  c11_b_ldc_t = (ptrdiff_t)28;
  dgemm(&c11_b_TRANSA1, &c11_b_TRANSB1, &c11_b_m_t, &c11_b_n_t, &c11_b_k_t,
        &c11_b_alpha1, &c11_P[0], &c11_b_lda_t, &c11_H[0], &c11_b_ldb_t,
        &c11_b_beta1, &c11_y[0], &c11_b_ldc_t);
  c11_b_st.site = &c11_cd_emlrtRSI;
  c11_c_st.site = &c11_fd_emlrtRSI;
  c11_d_st.site = &c11_gd_emlrtRSI;
  c11_e_st.site = &c11_hd_emlrtRSI;
  for (c11_i7 = 0; c11_i7 < 9; c11_i7++) {
    c11_A[c11_i7] = c11_innovCov[c11_i7];
  }

  c11_r1 = 0;
  c11_r2 = 1;
  c11_r3 = 2;
  c11_b_x = c11_A[0];
  c11_c_x = c11_b_x;
  c11_d_x = c11_c_x;
  c11_e_x = c11_d_x;
  c11_b_y = muDoubleScalarAbs(c11_e_x);
  c11_maxval = c11_b_y;
  c11_f_x = c11_A[1];
  c11_g_x = c11_f_x;
  c11_h_x = c11_g_x;
  c11_i_x = c11_h_x;
  c11_c_y = muDoubleScalarAbs(c11_i_x);
  c11_a21 = c11_c_y;
  if (c11_a21 > c11_maxval) {
    c11_maxval = c11_a21;
    c11_r1 = 1;
    c11_r2 = 0;
  }

  c11_j_x = c11_A[2];
  c11_k_x = c11_j_x;
  c11_l_x = c11_k_x;
  c11_m_x = c11_l_x;
  c11_d_y = muDoubleScalarAbs(c11_m_x);
  c11_d = c11_d_y;
  if (c11_d > c11_maxval) {
    c11_r1 = 2;
    c11_r2 = 1;
    c11_r3 = 0;
  }

  c11_A[c11_r2] /= c11_A[c11_r1];
  c11_A[c11_r3] /= c11_A[c11_r1];
  c11_A[3 + c11_r2] -= c11_A[c11_r2] * c11_A[3 + c11_r1];
  c11_A[3 + c11_r3] -= c11_A[c11_r3] * c11_A[3 + c11_r1];
  c11_A[6 + c11_r2] -= c11_A[c11_r2] * c11_A[6 + c11_r1];
  c11_A[6 + c11_r3] -= c11_A[c11_r3] * c11_A[6 + c11_r1];
  c11_n_x = c11_A[3 + c11_r3];
  c11_o_x = c11_n_x;
  c11_p_x = c11_o_x;
  c11_q_x = c11_p_x;
  c11_e_y = muDoubleScalarAbs(c11_q_x);
  c11_b_d = c11_e_y;
  c11_r_x = c11_A[3 + c11_r2];
  c11_s_x = c11_r_x;
  c11_t_x = c11_s_x;
  c11_u_x = c11_t_x;
  c11_f_y = muDoubleScalarAbs(c11_u_x);
  c11_c_d = c11_f_y;
  if (c11_b_d > c11_c_d) {
    c11_rtemp = c11_r2 + 1;
    c11_r2 = c11_r3;
    c11_r3 = c11_rtemp - 1;
  }

  c11_A[3 + c11_r3] /= c11_A[3 + c11_r2];
  c11_A[6 + c11_r3] -= c11_A[3 + c11_r3] * c11_A[6 + c11_r2];
  if ((c11_A[c11_r1] == 0.0) || (c11_A[3 + c11_r2] == 0.0) || (c11_A[6 + c11_r3]
       == 0.0)) {
    c11_f_st.site = &c11_id_emlrtRSI;
    c11_g_st.site = &c11_jd_emlrtRSI;
    c11_warning(chartInstance, &c11_g_st);
  }

  for (c11_k = 0; c11_k < 28; c11_k++) {
    c11_b_k = c11_k;
    c11_W[c11_b_k + 28 * c11_r1] = c11_y[c11_b_k] / c11_A[c11_r1];
    c11_W[c11_b_k + 28 * c11_r2] = c11_y[28 + c11_b_k] - c11_W[c11_b_k + 28 *
      c11_r1] * c11_A[3 + c11_r1];
    c11_W[c11_b_k + 28 * c11_r3] = c11_y[56 + c11_b_k] - c11_W[c11_b_k + 28 *
      c11_r1] * c11_A[6 + c11_r1];
    c11_W[c11_b_k + 28 * c11_r2] /= c11_A[3 + c11_r2];
    c11_W[c11_b_k + 28 * c11_r3] -= c11_W[c11_b_k + 28 * c11_r2] * c11_A[6 +
      c11_r2];
    c11_W[c11_b_k + 28 * c11_r3] /= c11_A[6 + c11_r3];
    c11_W[c11_b_k + 28 * c11_r2] -= c11_W[c11_b_k + 28 * c11_r3] * c11_A[3 +
      c11_r3];
    c11_W[c11_b_k + 28 * c11_r1] -= c11_W[c11_b_k + 28 * c11_r3] * c11_A[c11_r3];
    c11_W[c11_b_k + 28 * c11_r1] -= c11_W[c11_b_k + 28 * c11_r2] * c11_A[c11_r2];
  }

  for (c11_i8 = 0; c11_i8 < 28; c11_i8++) {
    c11_g_y[c11_i8] = 0.0;
    c11_i10 = 0;
    for (c11_i11 = 0; c11_i11 < 3; c11_i11++) {
      c11_g_y[c11_i8] += c11_W[c11_i10 + c11_i8] * c11_innov[c11_i11];
      c11_i10 += 28;
    }
  }

  for (c11_i9 = 0; c11_i9 < 28; c11_i9++) {
    c11_x[c11_i9] += c11_g_y[c11_i9];
  }

  c11_b_st.site = &c11_dd_emlrtRSI;
  c11_c_st.site = &c11_ec_emlrtRSI;
  c11_d_st.site = &c11_fc_emlrtRSI;
  c11_e_st.site = &c11_gc_emlrtRSI;
  c11_c_TRANSB1 = 'N';
  c11_c_TRANSA1 = 'N';
  c11_c_alpha1 = 1.0;
  c11_c_beta1 = 0.0;
  c11_c_m_t = (ptrdiff_t)28;
  c11_c_n_t = (ptrdiff_t)28;
  c11_c_k_t = (ptrdiff_t)3;
  c11_c_lda_t = (ptrdiff_t)28;
  c11_c_ldb_t = (ptrdiff_t)3;
  c11_c_ldc_t = (ptrdiff_t)28;
  dgemm(&c11_c_TRANSA1, &c11_c_TRANSB1, &c11_c_m_t, &c11_c_n_t, &c11_c_k_t,
        &c11_c_alpha1, &c11_W[0], &c11_c_lda_t, &c11_H[0], &c11_c_ldb_t,
        &c11_c_beta1, &c11_h_y[0], &c11_c_ldc_t);
  c11_b_st.site = &c11_dd_emlrtRSI;
  c11_c_st.site = &c11_ec_emlrtRSI;
  c11_mtimes(chartInstance, c11_h_y, c11_P, c11_i_y);
  for (c11_i12 = 0; c11_i12 < 784; c11_i12++) {
    c11_P[c11_i12] -= c11_i_y[c11_i12];
  }

  c11_st.site = &c11_ad_emlrtRSI;
  c11_b_obj = c11_obj;
  for (c11_i13 = 0; c11_i13 < 4; c11_i13++) {
    c11_idx[c11_i13] = c11_b_obj->OrientationIdx[c11_i13];
  }

  for (c11_i14 = 0; c11_i14 < 4; c11_i14++) {
    if (c11_idx[c11_i14] != (real_T)(int32_T)muDoubleScalarFloor(c11_idx[c11_i14]))
    {
      emlrtIntegerCheckR2012b(c11_idx[c11_i14], &c11_emlrtDCI, &c11_st);
    }

    c11_i15 = (int32_T)c11_idx[c11_i14];
    if ((c11_i15 < 1) || (c11_i15 > 28)) {
      emlrtDynamicBoundsCheckR2012b(c11_i15, 1, 28, &c11_emlrtBCI, &c11_st);
    }

    c11_qparts[c11_i14] = c11_x[c11_i15 - 1];
  }

  for (c11_c_k = 0; c11_c_k < 4; c11_c_k++) {
    c11_d_k = c11_c_k;
    c11_a = c11_qparts[c11_d_k];
    c11_l_y = c11_a * c11_a;
    c11_k_y[c11_d_k] = c11_l_y;
  }

  c11_j_y = c11_sumColumnB(chartInstance, c11_k_y, 1);
  c11_n = c11_j_y;
  c11_b_st.site = &c11_hc_emlrtRSI;
  c11_b_sqrt(chartInstance, &c11_b_st, &c11_n);
  for (c11_i16 = 0; c11_i16 < 4; c11_i16++) {
    c11_qparts[c11_i16] /= c11_n;
  }

  if (c11_qparts[0] < 0.0) {
    for (c11_i18 = 0; c11_i18 < 4; c11_i18++) {
      if (c11_idx[c11_i18] != (real_T)(int32_T)muDoubleScalarFloor
          (c11_idx[c11_i18])) {
        emlrtIntegerCheckR2012b(c11_idx[c11_i18], &c11_c_emlrtDCI, &c11_st);
      }

      c11_i20 = (int32_T)c11_idx[c11_i18];
      if ((c11_i20 < 1) || (c11_i20 > 28)) {
        emlrtDynamicBoundsCheckR2012b(c11_i20, 1, 28, &c11_c_emlrtBCI, &c11_st);
      }

      c11_x[c11_i20 - 1] = -c11_qparts[c11_i18];
    }
  } else {
    for (c11_i17 = 0; c11_i17 < 4; c11_i17++) {
      if (c11_idx[c11_i17] != (real_T)(int32_T)muDoubleScalarFloor
          (c11_idx[c11_i17])) {
        emlrtIntegerCheckR2012b(c11_idx[c11_i17], &c11_b_emlrtDCI, &c11_st);
      }

      c11_i19 = (int32_T)c11_idx[c11_i17];
      if ((c11_i19 < 1) || (c11_i19 > 28)) {
        emlrtDynamicBoundsCheckR2012b(c11_i19, 1, 28, &c11_b_emlrtBCI, &c11_st);
      }

      c11_x[c11_i19 - 1] = c11_qparts[c11_i17];
    }
  }
}

static void c11_b_sind(SFc11_car_model_FIXEDInstanceStruct *chartInstance,
  real_T *c11_x)
{
  real_T c11_a;
  real_T c11_absx;
  real_T c11_b_x;
  real_T c11_c_x;
  real_T c11_d_x;
  real_T c11_e_x;
  real_T c11_f_x;
  real_T c11_g_x;
  real_T c11_h_x;
  real_T c11_i_x;
  real_T c11_j_x;
  real_T c11_k_x;
  real_T c11_l_x;
  real_T c11_m_x;
  real_T c11_n_x;
  int8_T c11_n;
  boolean_T c11_b;
  boolean_T c11_b1;
  boolean_T c11_b_b;
  boolean_T c11_c_b;
  boolean_T c11_d_b;
  (void)chartInstance;
  c11_b_x = *c11_x;
  c11_c_x = c11_b_x;
  c11_d_x = c11_c_x;
  c11_b = muDoubleScalarIsInf(c11_d_x);
  c11_b_b = !c11_b;
  c11_e_x = c11_c_x;
  c11_c_b = muDoubleScalarIsNaN(c11_e_x);
  c11_b1 = !c11_c_b;
  c11_d_b = (c11_b_b && c11_b1);
  if (!c11_d_b) {
    c11_g_x = rtNaN;
  } else {
    c11_f_x = c11_b_x;
    c11_h_x = c11_f_x;
    c11_i_x = c11_h_x;
    c11_a = c11_i_x;
    c11_j_x = c11_a;
    c11_h_x = muDoubleScalarRem(c11_j_x, 360.0);
    c11_k_x = c11_h_x;
    c11_absx = muDoubleScalarAbs(c11_k_x);
    if (c11_absx > 180.0) {
      if (c11_h_x > 0.0) {
        c11_h_x -= 360.0;
      } else {
        c11_h_x += 360.0;
      }

      c11_l_x = c11_h_x;
      c11_m_x = c11_l_x;
      c11_n_x = c11_m_x;
      c11_absx = muDoubleScalarAbs(c11_n_x);
    }

    if (c11_absx <= 45.0) {
      c11_h_x *= 0.017453292519943295;
      c11_n = 0;
    } else if (c11_absx <= 135.0) {
      if (c11_h_x > 0.0) {
        c11_h_x = 0.017453292519943295 * (c11_h_x - 90.0);
        c11_n = 1;
      } else {
        c11_h_x = 0.017453292519943295 * (c11_h_x + 90.0);
        c11_n = -1;
      }
    } else if (c11_h_x > 0.0) {
      c11_h_x = 0.017453292519943295 * (c11_h_x - 180.0);
      c11_n = 2;
    } else {
      c11_h_x = 0.017453292519943295 * (c11_h_x + 180.0);
      c11_n = -2;
    }

    if ((real_T)c11_n == 0.0) {
      c11_g_x = muDoubleScalarSin(c11_h_x);
    } else if ((real_T)c11_n == 1.0) {
      c11_g_x = muDoubleScalarCos(c11_h_x);
    } else if ((real_T)c11_n == -1.0) {
      c11_g_x = -muDoubleScalarCos(c11_h_x);
    } else {
      c11_g_x = -muDoubleScalarSin(c11_h_x);
    }
  }

  *c11_x = c11_g_x;
}

static void c11_b_cosd(SFc11_car_model_FIXEDInstanceStruct *chartInstance,
  real_T *c11_x)
{
  real_T c11_a;
  real_T c11_absx;
  real_T c11_b_x;
  real_T c11_c_x;
  real_T c11_d_x;
  real_T c11_e_x;
  real_T c11_f_x;
  real_T c11_g_x;
  real_T c11_h_x;
  real_T c11_i_x;
  real_T c11_j_x;
  real_T c11_k_x;
  real_T c11_l_x;
  real_T c11_m_x;
  int8_T c11_n;
  boolean_T c11_b;
  boolean_T c11_b1;
  boolean_T c11_b_b;
  boolean_T c11_c_b;
  boolean_T c11_d_b;
  (void)chartInstance;
  c11_b_x = *c11_x;
  c11_c_x = c11_b_x;
  c11_d_x = c11_c_x;
  c11_b = muDoubleScalarIsInf(c11_d_x);
  c11_b_b = !c11_b;
  c11_e_x = c11_c_x;
  c11_c_b = muDoubleScalarIsNaN(c11_e_x);
  c11_b1 = !c11_c_b;
  c11_d_b = (c11_b_b && c11_b1);
  if (!c11_d_b) {
    *c11_x = rtNaN;
  } else {
    c11_f_x = c11_b_x;
    c11_g_x = c11_f_x;
    c11_h_x = c11_g_x;
    c11_a = c11_h_x;
    c11_i_x = c11_a;
    c11_g_x = muDoubleScalarRem(c11_i_x, 360.0);
    c11_j_x = c11_g_x;
    c11_absx = muDoubleScalarAbs(c11_j_x);
    if (c11_absx > 180.0) {
      if (c11_g_x > 0.0) {
        c11_g_x -= 360.0;
      } else {
        c11_g_x += 360.0;
      }

      c11_k_x = c11_g_x;
      c11_l_x = c11_k_x;
      c11_m_x = c11_l_x;
      c11_absx = muDoubleScalarAbs(c11_m_x);
    }

    if (c11_absx <= 45.0) {
      c11_g_x *= 0.017453292519943295;
      c11_n = 0;
    } else if (c11_absx <= 135.0) {
      if (c11_g_x > 0.0) {
        c11_g_x = 0.017453292519943295 * (c11_g_x - 90.0);
        c11_n = 1;
      } else {
        c11_g_x = 0.017453292519943295 * (c11_g_x + 90.0);
        c11_n = -1;
      }
    } else if (c11_g_x > 0.0) {
      c11_g_x = 0.017453292519943295 * (c11_g_x - 180.0);
      c11_n = 2;
    } else {
      c11_g_x = 0.017453292519943295 * (c11_g_x + 180.0);
      c11_n = -2;
    }

    if ((real_T)c11_n == 0.0) {
      *c11_x = muDoubleScalarCos(c11_g_x);
    } else if ((real_T)c11_n == 1.0) {
      *c11_x = -muDoubleScalarSin(c11_g_x);
    } else if ((real_T)c11_n == -1.0) {
      *c11_x = muDoubleScalarSin(c11_g_x);
    } else {
      *c11_x = -muDoubleScalarCos(c11_g_x);
    }
  }
}

static void init_dsm_address_info(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc11_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  chartInstance->c11_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c11_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c11_count = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c11_b_count = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c11_rot_map = (real_T (*)[9])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c11_velocity = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c11_state_out = (real_T (*)[28])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c11_position = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c11_acceleration = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c11_angularVelocity = (real_T (*)[3])
    ssGetInputPortSignal_wrapper(chartInstance->S, 4);
  chartInstance->c11_magField = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c11_state_in = (real_T (*)[28])ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c11_cov_in = (real_T (*)[784])ssGetInputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c11_cov_out = (real_T (*)[784])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c11_car_model_FIXED_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1708903449U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(955532810U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2470039776U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(662445396U);
}

mxArray *sf_c11_car_model_FIXED_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString("coder.internal.blas.BLASApi"));
  return(mxcell3p);
}

mxArray *sf_c11_car_model_FIXED_jit_fallback_info(void)
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

mxArray *sf_c11_car_model_FIXED_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c11_car_model_FIXED(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiBOYGFgYAPSHEDMxAABrFA+I5TNCBdngYsrAHFJZUEqSLy4KNkzBUjnJeaC+Ym"
    "lFZ55aflg8y0YEOazYTGfEcl8Tqg4BHywp0y/qwO6fhYC/hOA8pPzS/NKoOEDC6cB80eDE1H+YE"
    "fzBzvYH2Xx+aUlg8MfDDpk+6MovyQ+N7FgkPjDGuwPBwL+4ETzB4hfXJJYkgqOEYQ/KPePggNl+"
    "iH2BxDwjyyaf0D8zOL4xOSSzLLU+GRDw/jkxKL43PyU1Jx4N88IVxck/wEAPo8vtg=="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c11_car_model_FIXED_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sVUJGr4RxeYCNLlr98V5jYH";
}

static void sf_opaque_initialize_c11_car_model_FIXED(void *chartInstanceVar)
{
  initialize_params_c11_car_model_FIXED((SFc11_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
  initialize_c11_car_model_FIXED((SFc11_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c11_car_model_FIXED(void *chartInstanceVar)
{
  enable_c11_car_model_FIXED((SFc11_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c11_car_model_FIXED(void *chartInstanceVar)
{
  disable_c11_car_model_FIXED((SFc11_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c11_car_model_FIXED(void *chartInstanceVar)
{
  sf_gateway_c11_car_model_FIXED((SFc11_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c11_car_model_FIXED(SimStruct* S)
{
  return get_sim_state_c11_car_model_FIXED((SFc11_car_model_FIXEDInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c11_car_model_FIXED(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c11_car_model_FIXED((SFc11_car_model_FIXEDInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c11_car_model_FIXED(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc11_car_model_FIXEDInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_car_model_FIXED_optimization_info();
    }

    mdl_cleanup_runtime_resources_c11_car_model_FIXED
      ((SFc11_car_model_FIXEDInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c11_car_model_FIXED(void *chartInstanceVar)
{
  mdl_start_c11_car_model_FIXED((SFc11_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_mdl_terminate_c11_car_model_FIXED(void *chartInstanceVar)
{
  mdl_terminate_c11_car_model_FIXED((SFc11_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc11_car_model_FIXED((SFc11_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c11_car_model_FIXED(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  sf_warn_if_symbolic_dimension_param_changed(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c11_car_model_FIXED((SFc11_car_model_FIXEDInstanceStruct*)
      sf_get_chart_instance_ptr(S));
    initSimStructsc11_car_model_FIXED((SFc11_car_model_FIXEDInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c11_car_model_FIXED_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [23] = {
    "eNrtWU9vG0UUn0ROmogSReLApRU9cqBSU1rRCgRJ/Kc1Spqo6wTaizvZffYOnp3Zzh87Rhz4Fnw",
    "FjkhIfBW48wXggMSRN+u1azZuvOOIkCJWsjeznt+893vz/s2GLDX3CV4b7usGIat4W8PPMhldK/",
    "l4aeozel4hn+Tjb94iJJQRdEEEttNhp8TvEjY5pIommvhfgibwFLTk1jApmqIjy2OZ6IACEeICq",
    "VTGS65mieVM9BpWhE6y/iJmYRzE0vJoFxek0YHgw9fJTa05RIk1piA0DYDIxErabtzgtHu+FZQZ",
    "VGMIe9om3rbSYAKbOqp633LDUg71UwibQhuKVtBz+AaGGqiaUz8jO746GKNlknJGRXlbx1QHkKJ",
    "3GDhKI/w+sAatVwobxlSZXYhpH/Qe62XSpYBS0pnG2SdMUCMVo7ye8KpbrSTfQ44c9zEkuO8eId",
    "9dBbSXSiaMZ0AEDbRzXdATDjU4sV1PuQG8tC4ajhkMQPntb6cq+6BoFw6En87ZHtVPM6ecxFJJr",
    "GEJHFO1E6Lvaoj88gYGnQ4ouiO0cBkvLGQmbuqWYn30Dd9c13Thv1Cus8nI+/VC2ExuvQ/efjWR",
    "2whFlXKu/bAtme5BH3gmv0YNXQA7ku8B1ppFLYne4bKNZ8aygmEk5NiqFBEr75X9AiorbE+wSJW",
    "As8SFAURo5onqk4XmxZHVRiZVTDm1vb2S8s5im8KA6tAQStcYRZkGVDjzK0+5EdMukBCNVjIZy9",
    "IrjGJwISjRHStqA6l6aGPfYvbKVi4S/NAQdTExG8iSXB29+5hyW1LnRHcxftA9jjRmWT+5iHXxs",
    "xA4pGEMkaucjMM+5llcoOwWa1fyd5Btn5lhDXSoWFo2kiwmdCy6zkqtYQpHoifkQDSUTIK88zrH",
    "rwAwa1AlmOjuYglXwwYqX05rBS9bWXb3bXKcnanh9MT5xiMQWA0dV9c10BCjqi6wRUaFLoIN2Nf",
    "YxAjNtMFCPRyV+lHdc/37Y/Kqf6/M6N/fmerfN/NxuLXVDqlqJ65ZaTeaX9Zrk/XuTK13vcR5YL",
    "0EjpzBkYm88f39KfzSDLlk6u7mP5iav7789/lrBXnL42f55fDbU/i3C/IqBfxqbruP7v3+xw8/b",
    "X13++GPz7//+cWvRd5FPZbO6LGU/e1wmyt+566NfHxj3D9NsnX/TEIr4xfvFvzCjfXx0eeP1L2n",
    "p/Cs+mSPq4cPju9/9exxtt6Lyvn6rhT0HT+/5Xo2DOYsN6iwGeXnNzemdnSuKO7n6hx7rE/5FSG",
    "/fXYxfH27iK/M4beZj0Nps3PFxmv88lJ5fLtbise1Ao9rGY9+W+L56krwIB8szENJ005oekV4fL",
    "xdzDOzeKwXeKyPa2i2I2fz5OL63Nq+GH4k/3AOn5sFPjezs2Kbuo4A2rMrzzS/RfOpL45cMu5N0",
    "fN/u/zz/Mr0VWsL4ioL4sgl4y7Kz7dffNPn3zkn75LC/M0rzIOck+99zg1XjdcvxK+ffy8ffzp5",
    "b1WNGY9mnJzzn/Fw25n163/Ev//0tN/4/FJ39sv/wfH8wx1B+RCPyqNXEfnjQ+XeU09+UkD17Pc",
    "R/0Y9Gd/n9YnXC/HtxgMmIjnQt7fu3r97kfr0F+cmL0o=",
    ""
  };

  static char newstr [1621] = "";
  newstr[0] = '\0';
  for (i = 0; i < 23; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c11_car_model_FIXED(SimStruct *S)
{
  const char* newstr = sf_c11_car_model_FIXED_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(4126225463U));
  ssSetChecksum1(S,(2536617648U));
  ssSetChecksum2(S,(1521695021U));
  ssSetChecksum3(S,(3814774696U));
}

static void mdlRTW_c11_car_model_FIXED(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c11_car_model_FIXED(SimStruct *S)
{
  SFc11_car_model_FIXEDInstanceStruct *chartInstance;
  chartInstance = (SFc11_car_model_FIXEDInstanceStruct *)utMalloc(sizeof
    (SFc11_car_model_FIXEDInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc11_car_model_FIXEDInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c11_car_model_FIXED;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c11_car_model_FIXED;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c11_car_model_FIXED;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c11_car_model_FIXED;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c11_car_model_FIXED;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c11_car_model_FIXED;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c11_car_model_FIXED;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c11_car_model_FIXED;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c11_car_model_FIXED;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c11_car_model_FIXED;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c11_car_model_FIXED;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c11_car_model_FIXED;
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
    chartInstance->c11_JITStateAnimation,
    chartInstance->c11_JITTransitionAnimation);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c11_car_model_FIXED(chartInstance);
}

void c11_car_model_FIXED_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c11_car_model_FIXED(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c11_car_model_FIXED(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c11_car_model_FIXED(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c11_car_model_FIXED_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}