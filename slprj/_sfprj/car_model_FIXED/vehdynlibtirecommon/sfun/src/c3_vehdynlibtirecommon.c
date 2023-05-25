/* Include files */

#include "vehdynlibtirecommon_sfun.h"
#include "c3_vehdynlibtirecommon.h"
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
#define c3_const_plySteer              (1.0)
#define CALL_EVENT                     (-1)
#define c3_b_plySteer                  (1.0)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtMCInfo c3_emlrtMCI = { 82, /* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pName */
};

static emlrtMCInfo c3_b_emlrtMCI = { 13,/* lineNo */
  27,                                  /* colNo */
  "assertCompatibleDims",              /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\assertCompatibleDims.m"/* pName */
};

static emlrtMCInfo c3_c_emlrtMCI = { 13,/* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pName */
};

static emlrtMCInfo c3_d_emlrtMCI = { 87,/* lineNo */
  33,                                  /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtMCInfo c3_e_emlrtMCI = { 15,/* lineNo */
  27,                                  /* colNo */
  "assertCompatibleDims",              /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\assertCompatibleDims.m"/* pName */
};

static emlrtMCInfo c3_f_emlrtMCI = { 14,/* lineNo */
  9,                                   /* colNo */
  "acos",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\elfun\\acos.m"/* pName */
};

static emlrtRSInfo c3_emlrtRSI = { 198,/* lineNo */
  "Magic Tire Const Input/Magic Tire Const Input",/* fcnName */
  "#vehdynlibtirecommon:1745"          /* pathName */
};

static emlrtRSInfo c3_b_emlrtRSI = { 1,/* lineNo */
  "vdyncsmtire",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vdynblks\\vdynblksutilities\\vdyncsmtire.p"/* pathName */
};

static emlrtRSInfo c3_c_emlrtRSI = { 71,/* lineNo */
  "power",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRSInfo c3_d_emlrtRSI = { 34,/* lineNo */
  "rdivide_helper",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\rdivide_helper.m"/* pathName */
};

static emlrtRSInfo c3_e_emlrtRSI = { 51,/* lineNo */
  "div",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\div.m"/* pathName */
};

static emlrtRSInfo c3_f_emlrtRSI = { 76,/* lineNo */
  "div",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\div.m"/* pathName */
};

static emlrtRTEInfo c3_emlrtRTEI = { 1,/* lineNo */
  1,                                   /* colNo */
  "vdyncsmtire",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vdynblks\\vdynblksutilities\\vdyncsmtire.p"/* pName */
};

static emlrtRTEInfo c3_b_emlrtRTEI = { 34,/* lineNo */
  1,                                   /* colNo */
  "rdivide_helper",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\rdivide_helper.m"/* pName */
};

static emlrtRTEInfo c3_c_emlrtRTEI = { 71,/* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pName */
};

static emlrtRTEInfo c3_d_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "sqrt",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pName */
};

static emlrtRTEInfo c3_e_emlrtRTEI = { 30,/* lineNo */
  21,                                  /* colNo */
  "applyScalarFunction",               /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunction.m"/* pName */
};

static emlrtRTEInfo c3_f_emlrtRTEI = { 44,/* lineNo */
  34,                                  /* colNo */
  "vAllOrAny",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\vAllOrAny.m"/* pName */
};

static emlrtRTEInfo c3_g_emlrtRTEI = { 128,/* lineNo */
  57,                                  /* colNo */
  "allOrAny",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m"/* pName */
};

static emlrtRTEInfo c3_h_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "atan",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\elfun\\atan.m"/* pName */
};

static emlrtRTEInfo c3_i_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "cos",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\elfun\\cos.m"/* pName */
};

static emlrtRTEInfo c3_j_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "acos",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\elfun\\acos.m"/* pName */
};

static emlrtRTEInfo c3_k_emlrtRTEI = { 12,/* lineNo */
  37,                                  /* colNo */
  "sqrt",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pName */
};

static emlrtRTEInfo c3_l_emlrtRTEI = { 13,/* lineNo */
  37,                                  /* colNo */
  "acos",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\elfun\\acos.m"/* pName */
};

static emlrtRTEInfo c3_m_emlrtRTEI = { 52,/* lineNo */
  9,                                   /* colNo */
  "div",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\div.m"/* pName */
};

static emlrtECInfo c3_emlrtECI = { 2,  /* nDims */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "vdyncsmtire",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vdynblks\\vdynblksutilities\\vdyncsmtire.p"/* pName */
};

static emlrtECInfo c3_b_emlrtECI = { -1,/* nDims */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "vdyncsmtire",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vdynblks\\vdynblksutilities\\vdyncsmtire.p"/* pName */
};

static emlrtECInfo c3_c_emlrtECI = { 1,/* nDims */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "vdyncsmtire",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vdynblks\\vdynblksutilities\\vdyncsmtire.p"/* pName */
};

static emlrtBCInfo c3_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "vdyncsmtire",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vdynblks\\vdynblksutilities\\vdyncsmtire.p",/* pName */
  0                                    /* checkKind */
};

static char_T c3_cv[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
  'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm', 'a', 'i', 'n',
  'E', 'r', 'r', 'o', 'r' };

static char_T c3_cv1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
  'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n', 'E',
  'r', 'r', 'o', 'r' };

/* Function Declarations */
static void initialize_c3_vehdynlibtirecommon
  (SFc3_vehdynlibtirecommonInstanceStruct *chartInstance);
static void initialize_params_c3_vehdynlibtirecommon
  (SFc3_vehdynlibtirecommonInstanceStruct *chartInstance);
static void mdl_start_c3_vehdynlibtirecommon
  (SFc3_vehdynlibtirecommonInstanceStruct *chartInstance);
static void mdl_terminate_c3_vehdynlibtirecommon
  (SFc3_vehdynlibtirecommonInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c3_vehdynlibtirecommon
  (SFc3_vehdynlibtirecommonInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c3_vehdynlibtirecommon
  (SFc3_vehdynlibtirecommonInstanceStruct *chartInstance);
static void enable_c3_vehdynlibtirecommon(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance);
static void disable_c3_vehdynlibtirecommon
  (SFc3_vehdynlibtirecommonInstanceStruct *chartInstance);
static void sf_gateway_c3_vehdynlibtirecommon
  (SFc3_vehdynlibtirecommonInstanceStruct *chartInstance);
static void ext_mode_exec_c3_vehdynlibtirecommon
  (SFc3_vehdynlibtirecommonInstanceStruct *chartInstance);
static void c3_update_jit_animation_c3_vehdynlibtirecommon
  (SFc3_vehdynlibtirecommonInstanceStruct *chartInstance);
static void c3_do_animation_call_c3_vehdynlibtirecommon
  (SFc3_vehdynlibtirecommonInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_vehdynlibtirecommon
  (SFc3_vehdynlibtirecommonInstanceStruct *chartInstance);
static void set_sim_state_c3_vehdynlibtirecommon
  (SFc3_vehdynlibtirecommonInstanceStruct *chartInstance, const mxArray *c3_st);
static void initSimStructsc3_vehdynlibtirecommon
  (SFc3_vehdynlibtirecommonInstanceStruct *chartInstance);
static void c3_vdyncsmtire(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, real_T c3_b_Omega[4], real_T c3_b_Vx[4], real_T
  c3_b_Vy[4], real_T c3_b_psidot[4], real_T c3_gamma[4], real_T c3_press[4],
  real_T c3_scaleFactors[108], real_T c3_b_rhoz[4], real_T c3_b_turnslip, real_T
  c3_b_PRESMAX, real_T c3_b_PRESMIN, real_T c3_b_FZMAX, real_T c3_b_FZMIN,
  real_T c3_b_VXLOW, real_T c3_b_KPUMAX, real_T c3_b_KPUMIN, real_T c3_b_ALPMAX,
  real_T c3_b_ALPMIN, real_T c3_b_CAMMIN, real_T c3_b_CAMMAX, real_T c3_b_LONGVL,
  real_T c3_b_UNLOADED_RADIUS, real_T c3_b_RIM_RADIUS, real_T c3_b_NOMPRES,
  real_T c3_b_FNOMIN, real_T c3_b_VERTICAL_STIFFNESS, real_T c3_b_DREFF, real_T
  c3_b_BREFF, real_T c3_b_FREFF, real_T c3_b_Q_RE0, real_T c3_b_Q_V1, real_T
  c3_b_Q_V2, real_T c3_b_Q_FZ1, real_T c3_b_Q_FZ2, real_T c3_b_Q_FCX, real_T
  c3_b_Q_FCY, real_T c3_b_PFZ1, real_T c3_b_Q_FCY2, real_T c3_b_BOTTOM_OFFST,
  real_T c3_b_BOTTOM_STIFF, real_T c3_b_PCX1, real_T c3_b_PDX1, real_T c3_b_PDX2,
  real_T c3_b_PDX3, real_T c3_b_PEX1, real_T c3_b_PEX2, real_T c3_b_PEX3, real_T
  c3_b_PEX4, real_T c3_b_PKX1, real_T c3_b_PKX2, real_T c3_b_PKX3, real_T
  c3_b_PHX1, real_T c3_b_PHX2, real_T c3_b_PVX1, real_T c3_b_PVX2, real_T
  c3_b_PPX1, real_T c3_b_PPX2, real_T c3_b_PPX3, real_T c3_b_PPX4, real_T
  c3_b_RBX1, real_T c3_b_RBX2, real_T c3_b_RBX3, real_T c3_b_RCX1, real_T
  c3_b_REX1, real_T c3_b_REX2, real_T c3_b_RHX1, real_T c3_b_QSX1, real_T
  c3_b_QSX2, real_T c3_b_QSX3, real_T c3_b_QSX4, real_T c3_b_QSX5, real_T
  c3_b_QSX6, real_T c3_b_QSX7, real_T c3_b_QSX8, real_T c3_b_QSX9, real_T
  c3_b_QSX10, real_T c3_b_QSX11, real_T c3_b_PPMX1, real_T c3_b_PCY1, real_T
  c3_b_PDY1, real_T c3_b_PDY2, real_T c3_b_PDY3, real_T c3_b_PEY1, real_T
  c3_b_PEY2, real_T c3_b_PEY3, real_T c3_b_PEY4, real_T c3_b_PEY5, real_T
  c3_b_PKY1, real_T c3_b_PKY2, real_T c3_b_PKY3, real_T c3_b_PKY4, real_T
  c3_b_PKY5, real_T c3_b_PKY6, real_T c3_b_PKY7, real_T c3_b_PHY1, real_T
  c3_b_PHY2, real_T c3_b_PVY1, real_T c3_b_PVY2, real_T c3_b_PVY3, real_T
  c3_b_PVY4, real_T c3_b_PPY1, real_T c3_b_PPY2, real_T c3_b_PPY3, real_T
  c3_b_PPY4, real_T c3_b_PPY5, real_T c3_b_RBY1, real_T c3_b_RBY2, real_T
  c3_b_RBY3, real_T c3_b_RBY4, real_T c3_b_RCY1, real_T c3_b_REY1, real_T
  c3_b_REY2, real_T c3_b_RHY1, real_T c3_b_RHY2, real_T c3_b_RVY1, real_T
  c3_b_RVY2, real_T c3_b_RVY3, real_T c3_b_RVY4, real_T c3_b_RVY5, real_T
  c3_b_RVY6, real_T c3_b_QSY1, real_T c3_b_QSY2, real_T c3_b_QSY3, real_T
  c3_b_QSY4, real_T c3_b_QSY5, real_T c3_b_QSY6, real_T c3_b_QSY7, real_T
  c3_b_QSY8, real_T c3_b_QBZ1, real_T c3_b_QBZ2, real_T c3_b_QBZ3, real_T
  c3_b_QBZ4, real_T c3_b_QBZ5, real_T c3_b_QBZ6, real_T c3_b_QBZ9, real_T
  c3_b_QBZ10, real_T c3_b_QCZ1, real_T c3_b_QDZ1, real_T c3_b_QDZ2, real_T
  c3_b_QDZ3, real_T c3_b_QDZ4, real_T c3_b_QDZ6, real_T c3_b_QDZ7, real_T
  c3_b_QDZ8, real_T c3_b_QDZ9, real_T c3_b_QDZ10, real_T c3_b_QDZ11, real_T
  c3_b_QEZ1, real_T c3_b_QEZ2, real_T c3_b_QEZ3, real_T c3_b_QEZ4, real_T
  c3_b_QEZ5, real_T c3_b_QHZ1, real_T c3_b_QHZ2, real_T c3_b_QHZ3, real_T
  c3_b_QHZ4, real_T c3_b_PPZ1, real_T c3_b_PPZ2, real_T c3_b_SSZ1, real_T
  c3_b_SSZ2, real_T c3_b_SSZ3, real_T c3_b_SSZ4, real_T c3_b_PDXP1, real_T
  c3_b_PDXP2, real_T c3_b_PDXP3, real_T c3_b_PKYP1, real_T c3_b_PDYP1, real_T
  c3_b_PDYP2, real_T c3_b_PDYP3, real_T c3_b_PDYP4, real_T c3_b_PHYP1, real_T
  c3_b_PHYP2, real_T c3_b_PHYP3, real_T c3_b_PHYP4, real_T c3_b_PECP1, real_T
  c3_b_PECP2, real_T c3_b_QDTP1, real_T c3_b_QCRP1, real_T c3_b_QCRP2, real_T
  c3_b_QBRP1, real_T c3_b_QDRP1, real_T c3_b_QDRP2, real_T c3_b_WIDTH, real_T
  c3_b_Q_RA1, real_T c3_b_Q_RA2, real_T c3_b_Q_RB1, real_T c3_b_Q_RB2, real_T
  c3_b_QSX12, real_T c3_b_QSX13, real_T c3_b_QSX14, real_T c3_b_Q_FZ3, real_T
  c3_b_LONGITUDINAL_STIFFNESS, real_T c3_b_LATERAL_STIFFNESS, real_T c3_b_PCFX1,
  real_T c3_b_PCFX2, real_T c3_b_PCFX3, real_T c3_b_PCFY1, real_T c3_b_PCFY2,
  real_T c3_b_PCFY3, real_T c3_b_Fx_ext[4], real_T c3_b_Fy_ext[4], real_T
  c3_b_vdynMF[279], real_T c3_b_Fx[4], real_T c3_b_Fy[4], real_T c3_Fz[4],
  real_T c3_b_Mx[4], real_T c3_b_My[4], real_T c3_b_Mz[4], real_T c3_b_Re[4],
  real_T c3_kappa[4], real_T c3_alpha[4], real_T c3_b_sig_x[4], real_T
  c3_b_sig_y[4], real_T c3_patch_a[4], real_T c3_patch_b[4]);
static void c3_div0protect(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, real_T c3_u[4], real_T c3_tol, real_T c3_y[4], real_T
  c3_yabs[4]);
static void c3_power(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
                     const emlrtStack *c3_sp, real_T c3_a_data[], int32_T
                     c3_a_size[1], real_T c3_y_data[], int32_T c3_y_size[1]);
static real_T c3_function_handle_parenReference
  (SFc3_vehdynlibtirecommonInstanceStruct *chartInstance, real_T c3_varargin_1);
static void c3_assertCompatibleDims(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance);
static void c3_b_power(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, real_T c3_a_data[], int32_T c3_a_size[2], real_T
  c3_y_data[], int32_T c3_y_size[2]);
static void c3_sqrt(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance, const
                    emlrtStack *c3_sp, real_T c3_x_data[], int32_T c3_x_size[2],
                    real_T c3_b_x_data[], int32_T c3_b_x_size[2]);
static void c3_abs(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance, real_T
                   c3_x_data[], int32_T c3_x_size[1], real_T c3_y_data[],
                   int32_T c3_y_size[1]);
static void c3_b_assertCompatibleDims(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, int32_T c3_x_size[1], int32_T
  c3_y_size[1]);
static void c3_b_sqrt(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
                      const emlrtStack *c3_sp, real_T c3_x[4], real_T c3_b_x[4]);
static void c3_c_power(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, real_T c3_b_a[4], real_T c3_y[4]);
static void c3_b_div0protect(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, real_T c3_u[4], real_T c3_y[4]);
static boolean_T c3_any(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
  boolean_T c3_x[4]);
static void c3_atan(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
                    real_T c3_x_data[], int32_T c3_x_size[1], real_T
                    c3_b_x_data[], int32_T c3_b_x_size[1]);
static void c3_cos(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance, real_T
                   c3_x_data[], int32_T c3_x_size[1], real_T c3_b_x_data[],
                   int32_T c3_b_x_size[1]);
static void c3_c_sqrt(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
                      const emlrtStack *c3_sp, real_T c3_x_data[], int32_T
                      c3_x_size[1], real_T c3_b_x_data[], int32_T c3_b_x_size[1]);
static void c3_magicsin(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
  real_T c3_D[4], real_T c3_C, real_T c3_B[4], real_T c3_E, real_T c3_u[4],
  real_T c3_y[4]);
static void c3_magiccos(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
  real_T c3_C, real_T c3_B[4], real_T c3_E[4], real_T c3_u[4], real_T c3_y[4]);
static void c3_c_assertCompatibleDims(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, int32_T c3_x_size[1], int32_T
  c3_y_size[1]);
static void c3_acos(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance, const
                    emlrtStack *c3_sp, real_T c3_x_data[], int32_T c3_x_size[1],
                    real_T c3_b_x_data[], int32_T c3_b_x_size[1]);
static void c3_b_magicsin(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
  real_T c3_D[4], real_T c3_C[4], real_T c3_B[4], real_T c3_E[4], real_T c3_u[4],
  real_T c3_y[4]);
static void c3_b_magiccos(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
  real_T c3_C, real_T c3_B[4], real_T c3_E[4], real_T c3_u, real_T c3_y[4]);
static void c3_rollingMoment(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, real_T c3_b_Fx[4], real_T c3_Vcx[4],
  real_T c3_Fz[4], real_T c3_press[4], real_T c3_gamma[4], real_T c3_Vo, real_T
  c3_Ro, real_T c3_Fzo, real_T c3_pio, real_T c3_b_QSY1, real_T c3_b_QSY2,
  real_T c3_b_QSY3, real_T c3_b_QSY4, real_T c3_b_QSY5, real_T c3_b_QSY6, real_T
  c3_b_QSY7, real_T c3_b_QSY8, real_T c3_lam_My[4], real_T c3_b_My[4]);
static void c3_d_power(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, real_T c3_b_a[4], real_T c3_b_b, real_T c3_y[4]);
static void c3_c_magiccos(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
  real_T c3_D[4], real_T c3_C[4], real_T c3_B[4], real_T c3_u[4], real_T c3_y[4]);
static void c3_d_magiccos(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
  real_T c3_D[4], real_T c3_C, real_T c3_B[4], real_T c3_E[4], real_T c3_u[4],
  real_T c3_y[4]);
static void c3_b_vdyncsmtire(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, real_T c3_b_Omega[4], real_T c3_b_Vx
  [4], real_T c3_b_Vy[4], real_T c3_b_psidot[4], real_T c3_gamma[4], real_T
  c3_press[4], real_T c3_scaleFactors[108], real_T c3_b_rhoz[4], real_T
  c3_b_turnslip, real_T c3_b_PRESMAX, real_T c3_b_PRESMIN, real_T c3_b_FZMAX,
  real_T c3_b_FZMIN, real_T c3_b_VXLOW, real_T c3_b_KPUMAX, real_T c3_b_KPUMIN,
  real_T c3_b_ALPMAX, real_T c3_b_ALPMIN, real_T c3_b_CAMMIN, real_T c3_b_CAMMAX,
  real_T c3_b_LONGVL, real_T c3_b_UNLOADED_RADIUS, real_T c3_b_RIM_RADIUS,
  real_T c3_b_NOMPRES, real_T c3_b_FNOMIN, real_T c3_b_VERTICAL_STIFFNESS,
  real_T c3_b_DREFF, real_T c3_b_BREFF, real_T c3_b_FREFF, real_T c3_b_Q_RE0,
  real_T c3_b_Q_V1, real_T c3_b_Q_V2, real_T c3_b_Q_FZ1, real_T c3_b_Q_FZ2,
  real_T c3_b_Q_FCX, real_T c3_b_Q_FCY, real_T c3_b_PFZ1, real_T c3_b_Q_FCY2,
  real_T c3_b_BOTTOM_OFFST, real_T c3_b_BOTTOM_STIFF, real_T c3_b_PCX1, real_T
  c3_b_PDX1, real_T c3_b_PDX2, real_T c3_b_PDX3, real_T c3_b_PEX1, real_T
  c3_b_PEX2, real_T c3_b_PEX3, real_T c3_b_PEX4, real_T c3_b_PKX1, real_T
  c3_b_PKX2, real_T c3_b_PKX3, real_T c3_b_PHX1, real_T c3_b_PHX2, real_T
  c3_b_PVX1, real_T c3_b_PVX2, real_T c3_b_PPX1, real_T c3_b_PPX2, real_T
  c3_b_PPX3, real_T c3_b_PPX4, real_T c3_b_RBX1, real_T c3_b_RBX2, real_T
  c3_b_RBX3, real_T c3_b_RCX1, real_T c3_b_REX1, real_T c3_b_REX2, real_T
  c3_b_RHX1, real_T c3_b_QSX1, real_T c3_b_QSX2, real_T c3_b_QSX3, real_T
  c3_b_QSX4, real_T c3_b_QSX5, real_T c3_b_QSX6, real_T c3_b_QSX7, real_T
  c3_b_QSX8, real_T c3_b_QSX9, real_T c3_b_QSX10, real_T c3_b_QSX11, real_T
  c3_b_PPMX1, real_T c3_b_PCY1, real_T c3_b_PDY1, real_T c3_b_PDY2, real_T
  c3_b_PDY3, real_T c3_b_PEY1, real_T c3_b_PEY2, real_T c3_b_PEY3, real_T
  c3_b_PEY4, real_T c3_b_PEY5, real_T c3_b_PKY1, real_T c3_b_PKY2, real_T
  c3_b_PKY3, real_T c3_b_PKY4, real_T c3_b_PKY5, real_T c3_b_PKY6, real_T
  c3_b_PKY7, real_T c3_b_PHY1, real_T c3_b_PHY2, real_T c3_b_PVY1, real_T
  c3_b_PVY2, real_T c3_b_PVY3, real_T c3_b_PVY4, real_T c3_b_PPY1, real_T
  c3_b_PPY2, real_T c3_b_PPY3, real_T c3_b_PPY4, real_T c3_b_PPY5, real_T
  c3_b_RBY1, real_T c3_b_RBY2, real_T c3_b_RBY3, real_T c3_b_RBY4, real_T
  c3_b_RCY1, real_T c3_b_REY1, real_T c3_b_REY2, real_T c3_b_RHY1, real_T
  c3_b_RHY2, real_T c3_b_RVY1, real_T c3_b_RVY2, real_T c3_b_RVY3, real_T
  c3_b_RVY4, real_T c3_b_RVY5, real_T c3_b_RVY6, real_T c3_b_QSY1, real_T
  c3_b_QSY2, real_T c3_b_QSY3, real_T c3_b_QSY4, real_T c3_b_QSY5, real_T
  c3_b_QSY6, real_T c3_b_QSY7, real_T c3_b_QSY8, real_T c3_b_QBZ1, real_T
  c3_b_QBZ2, real_T c3_b_QBZ3, real_T c3_b_QBZ4, real_T c3_b_QBZ5, real_T
  c3_b_QBZ6, real_T c3_b_QBZ9, real_T c3_b_QBZ10, real_T c3_b_QCZ1, real_T
  c3_b_QDZ1, real_T c3_b_QDZ2, real_T c3_b_QDZ3, real_T c3_b_QDZ4, real_T
  c3_b_QDZ6, real_T c3_b_QDZ7, real_T c3_b_QDZ8, real_T c3_b_QDZ9, real_T
  c3_b_QDZ10, real_T c3_b_QDZ11, real_T c3_b_QEZ1, real_T c3_b_QEZ2, real_T
  c3_b_QEZ3, real_T c3_b_QEZ4, real_T c3_b_QEZ5, real_T c3_b_QHZ1, real_T
  c3_b_QHZ2, real_T c3_b_QHZ3, real_T c3_b_QHZ4, real_T c3_b_PPZ1, real_T
  c3_b_PPZ2, real_T c3_b_SSZ1, real_T c3_b_SSZ2, real_T c3_b_SSZ3, real_T
  c3_b_SSZ4, real_T c3_b_PDXP1, real_T c3_b_PDXP2, real_T c3_b_PDXP3, real_T
  c3_b_PKYP1, real_T c3_b_PDYP1, real_T c3_b_PDYP2, real_T c3_b_PDYP3, real_T
  c3_b_PDYP4, real_T c3_b_PHYP1, real_T c3_b_PHYP2, real_T c3_b_PHYP3, real_T
  c3_b_PHYP4, real_T c3_b_PECP1, real_T c3_b_PECP2, real_T c3_b_QDTP1, real_T
  c3_b_QCRP1, real_T c3_b_QCRP2, real_T c3_b_QBRP1, real_T c3_b_QDRP1, real_T
  c3_b_QDRP2, real_T c3_b_WIDTH, real_T c3_b_Q_RA1, real_T c3_b_Q_RA2, real_T
  c3_b_Q_RB1, real_T c3_b_Q_RB2, real_T c3_b_QSX12, real_T c3_b_QSX13, real_T
  c3_b_QSX14, real_T c3_b_Q_FZ3, real_T c3_b_LONGITUDINAL_STIFFNESS, real_T
  c3_b_LATERAL_STIFFNESS, real_T c3_b_PCFX1, real_T c3_b_PCFX2, real_T
  c3_b_PCFX3, real_T c3_b_PCFY1, real_T c3_b_PCFY2, real_T c3_b_PCFY3, real_T
  c3_b_Fx_ext[4], real_T c3_b_Fy_ext[4], real_T c3_b_Fx[4], real_T c3_b_Fy[4],
  real_T c3_Fz[4], real_T c3_b_Mx[4], real_T c3_b_My[4], real_T c3_b_Mz[4],
  real_T c3_b_Re[4], real_T c3_kappa[4], real_T c3_alpha[4], real_T c3_b_sig_x[4],
  real_T c3_b_sig_y[4], real_T c3_patch_a[4], real_T c3_patch_b[4]);
static void c3_emlrt_marshallIn(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance, const mxArray *c3_b_Alpha, const char_T *c3_identifier, real_T
  c3_y[4]);
static void c3_b_emlrt_marshallIn(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[4]);
static uint8_T c3_c_emlrt_marshallIn(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_vehdynlibtirecommon, const
  char_T *c3_identifier);
static uint8_T c3_d_emlrt_marshallIn(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_slStringInitializeDynamicBuffers
  (SFc3_vehdynlibtirecommonInstanceStruct *chartInstance);
static void c3_chart_data_browse_helper(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance, int32_T c3_ssIdNumber, const mxArray **c3_mxData, uint8_T
  *c3_isValueTooBig);
static void c3_d_sqrt(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
                      const emlrtStack *c3_sp, real_T c3_x_data[], int32_T
                      c3_x_size[2]);
static void c3_e_sqrt(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
                      const emlrtStack *c3_sp, real_T c3_x[4]);
static void c3_b_atan(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
                      real_T c3_x_data[], int32_T c3_x_size[1]);
static void c3_b_cos(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
                     real_T c3_x_data[], int32_T c3_x_size[1]);
static void c3_f_sqrt(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
                      const emlrtStack *c3_sp, real_T c3_x_data[], int32_T
                      c3_x_size[1]);
static void c3_b_acos(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
                      const emlrtStack *c3_sp, real_T c3_x_data[], int32_T
                      c3_x_size[1]);
static void c3_binary_expand_op(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance, real_T c3_in1_data[], int32_T c3_in1_size[1], real_T
  c3_in2_data[], int32_T c3_in2_size[1], real_T c3_in3[36], int32_T c3_in4_data[],
  int32_T c3_in4_size[1]);
static void c3_plus(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
                    real_T c3_in1_data[], int32_T c3_in1_size[1], real_T
                    c3_in2_data[], int32_T c3_in2_size[1]);
static void c3_b_binary_expand_op(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance, real_T c3_in1_data[], int32_T c3_in1_size[1], real_T
  c3_in2_data[], int32_T c3_in2_size[1], real_T c3_in3[36], int32_T c3_in4_data[],
  int32_T c3_in4_size[1]);
static void c3_rdivide(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
  real_T c3_in1_data[], int32_T c3_in1_size[1], real_T c3_in2_data[], int32_T
  c3_in2_size[1]);
static void c3_c_binary_expand_op(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance, real_T c3_in1_data[], int32_T c3_in1_size[1], real_T
  c3_in2_data[], int32_T c3_in2_size[1], real_T c3_in3[4], int32_T c3_in4_data[],
  int32_T c3_in4_size[1]);
static void c3_minus(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
                     real_T c3_in1_data[], int32_T c3_in1_size[1], real_T
                     c3_in2_data[], int32_T c3_in2_size[1]);
static void c3_d_binary_expand_op(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance, real_T c3_in1_data[], int32_T c3_in1_size[1], real_T
  c3_in2_data[], int32_T c3_in2_size[1], real_T c3_in3[4], int32_T c3_in4_data[],
  int32_T c3_in4_size[1]);
static void c3_e_binary_expand_op(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance, real_T c3_in1_data[], int32_T c3_in1_size[1], real_T
  c3_in2_data[], int32_T c3_in2_size[1], real_T c3_in3[4], int32_T c3_in4_data[],
  int32_T c3_in4_size[1]);
static void c3_f_binary_expand_op(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance, real_T c3_in1_data[], int32_T c3_in1_size[1], real_T c3_in2[4],
  int32_T c3_in3_data[], int32_T c3_in3_size[1], real_T c3_in4_data[], int32_T
  c3_in4_size[1]);
static void c3_g_binary_expand_op(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance, real_T c3_in1_data[], int32_T c3_in1_size[1], real_T c3_in2[4],
  int32_T c3_in3_data[], int32_T c3_in3_size[1], real_T c3_in4_data[], int32_T
  c3_in4_size[1]);
static void c3_h_binary_expand_op(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance, real_T c3_in1_data[], int32_T c3_in1_size[1], real_T
  c3_in2_data[], int32_T c3_in2_size[1], real_T c3_in3[4], int32_T c3_in4_data[],
  int32_T c3_in4_size[1]);
static void c3_b_minus(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
  real_T c3_in1_data[], int32_T c3_in1_size[2], real_T c3_in2_data[], int32_T
  c3_in2_size[2]);
static void c3_b_rdivide(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
  real_T c3_in1_data[], int32_T c3_in1_size[2], real_T c3_in2_data[], int32_T
  c3_in2_size[2]);
static void c3_times(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
                     real_T c3_in1_data[], int32_T c3_in1_size[2], real_T
                     c3_in2_data[], int32_T c3_in2_size[2]);
static void init_dsm_address_info(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_vehdynlibtirecommon
  (SFc3_vehdynlibtirecommonInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_is_active_c3_vehdynlibtirecommon = 0U;
}

static void initialize_params_c3_vehdynlibtirecommon
  (SFc3_vehdynlibtirecommonInstanceStruct *chartInstance)
{
  real_T c3_dv[279];
  real_T c3_d;
  real_T c3_d1;
  real_T c3_d10;
  real_T c3_d100;
  real_T c3_d101;
  real_T c3_d102;
  real_T c3_d103;
  real_T c3_d104;
  real_T c3_d105;
  real_T c3_d106;
  real_T c3_d107;
  real_T c3_d108;
  real_T c3_d109;
  real_T c3_d11;
  real_T c3_d110;
  real_T c3_d111;
  real_T c3_d112;
  real_T c3_d113;
  real_T c3_d114;
  real_T c3_d115;
  real_T c3_d116;
  real_T c3_d117;
  real_T c3_d118;
  real_T c3_d119;
  real_T c3_d12;
  real_T c3_d120;
  real_T c3_d121;
  real_T c3_d122;
  real_T c3_d123;
  real_T c3_d124;
  real_T c3_d125;
  real_T c3_d126;
  real_T c3_d127;
  real_T c3_d128;
  real_T c3_d129;
  real_T c3_d13;
  real_T c3_d130;
  real_T c3_d131;
  real_T c3_d132;
  real_T c3_d133;
  real_T c3_d134;
  real_T c3_d135;
  real_T c3_d136;
  real_T c3_d137;
  real_T c3_d138;
  real_T c3_d139;
  real_T c3_d14;
  real_T c3_d140;
  real_T c3_d141;
  real_T c3_d142;
  real_T c3_d143;
  real_T c3_d144;
  real_T c3_d145;
  real_T c3_d146;
  real_T c3_d147;
  real_T c3_d148;
  real_T c3_d149;
  real_T c3_d15;
  real_T c3_d150;
  real_T c3_d151;
  real_T c3_d152;
  real_T c3_d153;
  real_T c3_d154;
  real_T c3_d155;
  real_T c3_d156;
  real_T c3_d157;
  real_T c3_d158;
  real_T c3_d159;
  real_T c3_d16;
  real_T c3_d160;
  real_T c3_d161;
  real_T c3_d162;
  real_T c3_d163;
  real_T c3_d164;
  real_T c3_d165;
  real_T c3_d166;
  real_T c3_d167;
  real_T c3_d168;
  real_T c3_d169;
  real_T c3_d17;
  real_T c3_d170;
  real_T c3_d171;
  real_T c3_d172;
  real_T c3_d173;
  real_T c3_d174;
  real_T c3_d175;
  real_T c3_d176;
  real_T c3_d177;
  real_T c3_d178;
  real_T c3_d179;
  real_T c3_d18;
  real_T c3_d180;
  real_T c3_d181;
  real_T c3_d182;
  real_T c3_d183;
  real_T c3_d184;
  real_T c3_d185;
  real_T c3_d186;
  real_T c3_d187;
  real_T c3_d188;
  real_T c3_d189;
  real_T c3_d19;
  real_T c3_d190;
  real_T c3_d191;
  real_T c3_d2;
  real_T c3_d20;
  real_T c3_d21;
  real_T c3_d22;
  real_T c3_d23;
  real_T c3_d24;
  real_T c3_d25;
  real_T c3_d26;
  real_T c3_d27;
  real_T c3_d28;
  real_T c3_d29;
  real_T c3_d3;
  real_T c3_d30;
  real_T c3_d31;
  real_T c3_d32;
  real_T c3_d33;
  real_T c3_d34;
  real_T c3_d35;
  real_T c3_d36;
  real_T c3_d37;
  real_T c3_d38;
  real_T c3_d39;
  real_T c3_d4;
  real_T c3_d40;
  real_T c3_d41;
  real_T c3_d42;
  real_T c3_d43;
  real_T c3_d44;
  real_T c3_d45;
  real_T c3_d46;
  real_T c3_d47;
  real_T c3_d48;
  real_T c3_d49;
  real_T c3_d5;
  real_T c3_d50;
  real_T c3_d51;
  real_T c3_d52;
  real_T c3_d53;
  real_T c3_d54;
  real_T c3_d55;
  real_T c3_d56;
  real_T c3_d57;
  real_T c3_d58;
  real_T c3_d59;
  real_T c3_d6;
  real_T c3_d60;
  real_T c3_d61;
  real_T c3_d62;
  real_T c3_d63;
  real_T c3_d64;
  real_T c3_d65;
  real_T c3_d66;
  real_T c3_d67;
  real_T c3_d68;
  real_T c3_d69;
  real_T c3_d7;
  real_T c3_d70;
  real_T c3_d71;
  real_T c3_d72;
  real_T c3_d73;
  real_T c3_d74;
  real_T c3_d75;
  real_T c3_d76;
  real_T c3_d77;
  real_T c3_d78;
  real_T c3_d79;
  real_T c3_d8;
  real_T c3_d80;
  real_T c3_d81;
  real_T c3_d82;
  real_T c3_d83;
  real_T c3_d84;
  real_T c3_d85;
  real_T c3_d86;
  real_T c3_d87;
  real_T c3_d88;
  real_T c3_d89;
  real_T c3_d9;
  real_T c3_d90;
  real_T c3_d91;
  real_T c3_d92;
  real_T c3_d93;
  real_T c3_d94;
  real_T c3_d95;
  real_T c3_d96;
  real_T c3_d97;
  real_T c3_d98;
  real_T c3_d99;
  int32_T c3_i;
  sf_mex_import_named("plySteer", sf_mex_get_sfun_param(chartInstance->S, 190U,
    0U), &c3_d, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_plySteer = c3_d;
  sf_mex_import_named("turnslip", sf_mex_get_sfun_param(chartInstance->S, 191U,
    0U), &c3_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_turnslip = c3_d1;
  sf_mex_import_named("PRESMAX", sf_mex_get_sfun_param(chartInstance->S, 82U, 0U),
                      &c3_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PRESMAX = c3_d2;
  sf_mex_import_named("PRESMIN", sf_mex_get_sfun_param(chartInstance->S, 83U, 0U),
                      &c3_d3, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PRESMIN = c3_d3;
  sf_mex_import_named("FZMAX", sf_mex_get_sfun_param(chartInstance->S, 10U, 0U),
                      &c3_d4, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_FZMAX = c3_d4;
  sf_mex_import_named("FZMIN", sf_mex_get_sfun_param(chartInstance->S, 11U, 0U),
                      &c3_d5, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_FZMIN = c3_d5;
  sf_mex_import_named("VXLOW", sf_mex_get_sfun_param(chartInstance->S, 188U, 0U),
                      &c3_d6, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_VXLOW = c3_d6;
  sf_mex_import_named("KPUMAX", sf_mex_get_sfun_param(chartInstance->S, 12U, 0U),
                      &c3_d7, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_KPUMAX = c3_d7;
  sf_mex_import_named("KPUMIN", sf_mex_get_sfun_param(chartInstance->S, 13U, 0U),
                      &c3_d8, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_KPUMIN = c3_d8;
  sf_mex_import_named("ALPMAX", sf_mex_get_sfun_param(chartInstance->S, 0U, 0U),
                      &c3_d9, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_ALPMAX = c3_d9;
  sf_mex_import_named("ALPMIN", sf_mex_get_sfun_param(chartInstance->S, 1U, 0U),
                      &c3_d10, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_ALPMIN = c3_d10;
  sf_mex_import_named("CAMMIN", sf_mex_get_sfun_param(chartInstance->S, 6U, 0U),
                      &c3_d11, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_CAMMIN = c3_d11;
  sf_mex_import_named("CAMMAX", sf_mex_get_sfun_param(chartInstance->S, 5U, 0U),
                      &c3_d12, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_CAMMAX = c3_d12;
  sf_mex_import_named("LONGVL", sf_mex_get_sfun_param(chartInstance->S, 16U, 0U),
                      &c3_d13, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_LONGVL = c3_d13;
  sf_mex_import_named("UNLOADED_RADIUS", sf_mex_get_sfun_param(chartInstance->S,
    186U, 0U), &c3_d14, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_UNLOADED_RADIUS = c3_d14;
  sf_mex_import_named("RIM_RADIUS", sf_mex_get_sfun_param(chartInstance->S, 175U,
    0U), &c3_d15, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_RIM_RADIUS = c3_d15;
  sf_mex_import_named("NOMPRES", sf_mex_get_sfun_param(chartInstance->S, 17U, 0U),
                      &c3_d16, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_NOMPRES = c3_d16;
  sf_mex_import_named("FNOMIN", sf_mex_get_sfun_param(chartInstance->S, 8U, 0U),
                      &c3_d17, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_FNOMIN = c3_d17;
  sf_mex_import_named("VERTICAL_STIFFNESS", sf_mex_get_sfun_param
                      (chartInstance->S, 187U, 0U), &c3_d18, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_VERTICAL_STIFFNESS = c3_d18;
  sf_mex_import_named("DREFF", sf_mex_get_sfun_param(chartInstance->S, 7U, 0U),
                      &c3_d19, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_DREFF = c3_d19;
  sf_mex_import_named("BREFF", sf_mex_get_sfun_param(chartInstance->S, 4U, 0U),
                      &c3_d20, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_BREFF = c3_d20;
  sf_mex_import_named("FREFF", sf_mex_get_sfun_param(chartInstance->S, 9U, 0U),
                      &c3_d21, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_FREFF = c3_d21;
  sf_mex_import_named("Q_RE0", sf_mex_get_sfun_param(chartInstance->S, 156U, 0U),
                      &c3_d22, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_Q_RE0 = c3_d22;
  sf_mex_import_named("Q_V1", sf_mex_get_sfun_param(chartInstance->S, 157U, 0U),
                      &c3_d23, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_Q_V1 = c3_d23;
  sf_mex_import_named("Q_V2", sf_mex_get_sfun_param(chartInstance->S, 158U, 0U),
                      &c3_d24, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_Q_V2 = c3_d24;
  sf_mex_import_named("Q_FZ1", sf_mex_get_sfun_param(chartInstance->S, 149U, 0U),
                      &c3_d25, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_Q_FZ1 = c3_d25;
  sf_mex_import_named("Q_FZ2", sf_mex_get_sfun_param(chartInstance->S, 150U, 0U),
                      &c3_d26, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_Q_FZ2 = c3_d26;
  sf_mex_import_named("Q_FCX", sf_mex_get_sfun_param(chartInstance->S, 146U, 0U),
                      &c3_d27, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_Q_FCX = c3_d27;
  sf_mex_import_named("Q_FCY", sf_mex_get_sfun_param(chartInstance->S, 147U, 0U),
                      &c3_d28, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_Q_FCY = c3_d28;
  sf_mex_import_named("PFZ1", sf_mex_get_sfun_param(chartInstance->S, 50U, 0U),
                      &c3_d29, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PFZ1 = c3_d29;
  sf_mex_import_named("Q_FCY2", sf_mex_get_sfun_param(chartInstance->S, 148U, 0U),
                      &c3_d30, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_Q_FCY2 = c3_d30;
  sf_mex_import_named("BOTTOM_OFFST", sf_mex_get_sfun_param(chartInstance->S, 2U,
    0U), &c3_d31, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_BOTTOM_OFFST = c3_d31;
  sf_mex_import_named("BOTTOM_STIFF", sf_mex_get_sfun_param(chartInstance->S, 3U,
    0U), &c3_d32, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_BOTTOM_STIFF = c3_d32;
  sf_mex_import_named("PCX1", sf_mex_get_sfun_param(chartInstance->S, 24U, 0U),
                      &c3_d33, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PCX1 = c3_d33;
  sf_mex_import_named("PDX1", sf_mex_get_sfun_param(chartInstance->S, 26U, 0U),
                      &c3_d34, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PDX1 = c3_d34;
  sf_mex_import_named("PDX2", sf_mex_get_sfun_param(chartInstance->S, 27U, 0U),
                      &c3_d35, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PDX2 = c3_d35;
  sf_mex_import_named("PDX3", sf_mex_get_sfun_param(chartInstance->S, 28U, 0U),
                      &c3_d36, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PDX3 = c3_d36;
  sf_mex_import_named("PEX1", sf_mex_get_sfun_param(chartInstance->S, 41U, 0U),
                      &c3_d37, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PEX1 = c3_d37;
  sf_mex_import_named("PEX2", sf_mex_get_sfun_param(chartInstance->S, 42U, 0U),
                      &c3_d38, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PEX2 = c3_d38;
  sf_mex_import_named("PEX3", sf_mex_get_sfun_param(chartInstance->S, 43U, 0U),
                      &c3_d39, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PEX3 = c3_d39;
  sf_mex_import_named("PEX4", sf_mex_get_sfun_param(chartInstance->S, 44U, 0U),
                      &c3_d40, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PEX4 = c3_d40;
  sf_mex_import_named("PKX1", sf_mex_get_sfun_param(chartInstance->S, 59U, 0U),
                      &c3_d41, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PKX1 = c3_d41;
  sf_mex_import_named("PKX2", sf_mex_get_sfun_param(chartInstance->S, 60U, 0U),
                      &c3_d42, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PKX2 = c3_d42;
  sf_mex_import_named("PKX3", sf_mex_get_sfun_param(chartInstance->S, 61U, 0U),
                      &c3_d43, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PKX3 = c3_d43;
  sf_mex_import_named("PHX1", sf_mex_get_sfun_param(chartInstance->S, 51U, 0U),
                      &c3_d44, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PHX1 = c3_d44;
  sf_mex_import_named("PHX2", sf_mex_get_sfun_param(chartInstance->S, 52U, 0U),
                      &c3_d45, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PHX2 = c3_d45;
  sf_mex_import_named("PVX1", sf_mex_get_sfun_param(chartInstance->S, 84U, 0U),
                      &c3_d46, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PVX1 = c3_d46;
  sf_mex_import_named("PVX2", sf_mex_get_sfun_param(chartInstance->S, 85U, 0U),
                      &c3_d47, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PVX2 = c3_d47;
  sf_mex_import_named("PPX1", sf_mex_get_sfun_param(chartInstance->S, 71U, 0U),
                      &c3_d48, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PPX1 = c3_d48;
  sf_mex_import_named("PPX2", sf_mex_get_sfun_param(chartInstance->S, 72U, 0U),
                      &c3_d49, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PPX2 = c3_d49;
  sf_mex_import_named("PPX3", sf_mex_get_sfun_param(chartInstance->S, 73U, 0U),
                      &c3_d50, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PPX3 = c3_d50;
  sf_mex_import_named("PPX4", sf_mex_get_sfun_param(chartInstance->S, 74U, 0U),
                      &c3_d51, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PPX4 = c3_d51;
  sf_mex_import_named("RBX1", sf_mex_get_sfun_param(chartInstance->S, 159U, 0U),
                      &c3_d52, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_RBX1 = c3_d52;
  sf_mex_import_named("RBX2", sf_mex_get_sfun_param(chartInstance->S, 160U, 0U),
                      &c3_d53, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_RBX2 = c3_d53;
  sf_mex_import_named("RBX3", sf_mex_get_sfun_param(chartInstance->S, 161U, 0U),
                      &c3_d54, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_RBX3 = c3_d54;
  sf_mex_import_named("RCX1", sf_mex_get_sfun_param(chartInstance->S, 166U, 0U),
                      &c3_d55, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_RCX1 = c3_d55;
  sf_mex_import_named("REX1", sf_mex_get_sfun_param(chartInstance->S, 168U, 0U),
                      &c3_d56, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_REX1 = c3_d56;
  sf_mex_import_named("REX2", sf_mex_get_sfun_param(chartInstance->S, 169U, 0U),
                      &c3_d57, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_REX2 = c3_d57;
  sf_mex_import_named("RHX1", sf_mex_get_sfun_param(chartInstance->S, 172U, 0U),
                      &c3_d58, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_RHX1 = c3_d58;
  sf_mex_import_named("QSX1", sf_mex_get_sfun_param(chartInstance->S, 124U, 0U),
                      &c3_d59, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QSX1 = c3_d59;
  sf_mex_import_named("QSX2", sf_mex_get_sfun_param(chartInstance->S, 130U, 0U),
                      &c3_d60, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QSX2 = c3_d60;
  sf_mex_import_named("QSX3", sf_mex_get_sfun_param(chartInstance->S, 131U, 0U),
                      &c3_d61, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QSX3 = c3_d61;
  sf_mex_import_named("QSX4", sf_mex_get_sfun_param(chartInstance->S, 132U, 0U),
                      &c3_d62, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QSX4 = c3_d62;
  sf_mex_import_named("QSX5", sf_mex_get_sfun_param(chartInstance->S, 133U, 0U),
                      &c3_d63, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QSX5 = c3_d63;
  sf_mex_import_named("QSX6", sf_mex_get_sfun_param(chartInstance->S, 134U, 0U),
                      &c3_d64, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QSX6 = c3_d64;
  sf_mex_import_named("QSX7", sf_mex_get_sfun_param(chartInstance->S, 135U, 0U),
                      &c3_d65, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QSX7 = c3_d65;
  sf_mex_import_named("QSX8", sf_mex_get_sfun_param(chartInstance->S, 136U, 0U),
                      &c3_d66, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QSX8 = c3_d66;
  sf_mex_import_named("QSX9", sf_mex_get_sfun_param(chartInstance->S, 137U, 0U),
                      &c3_d67, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QSX9 = c3_d67;
  sf_mex_import_named("QSX10", sf_mex_get_sfun_param(chartInstance->S, 125U, 0U),
                      &c3_d68, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QSX10 = c3_d68;
  sf_mex_import_named("QSX11", sf_mex_get_sfun_param(chartInstance->S, 126U, 0U),
                      &c3_d69, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QSX11 = c3_d69;
  sf_mex_import_named("PPMX1", sf_mex_get_sfun_param(chartInstance->S, 70U, 0U),
                      &c3_d70, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PPMX1 = c3_d70;
  sf_mex_import_named("PCY1", sf_mex_get_sfun_param(chartInstance->S, 25U, 0U),
                      &c3_d71, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PCY1 = c3_d71;
  sf_mex_import_named("PDY1", sf_mex_get_sfun_param(chartInstance->S, 32U, 0U),
                      &c3_d72, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PDY1 = c3_d72;
  sf_mex_import_named("PDY2", sf_mex_get_sfun_param(chartInstance->S, 33U, 0U),
                      &c3_d73, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PDY2 = c3_d73;
  sf_mex_import_named("PDY3", sf_mex_get_sfun_param(chartInstance->S, 34U, 0U),
                      &c3_d74, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PDY3 = c3_d74;
  sf_mex_import_named("PEY1", sf_mex_get_sfun_param(chartInstance->S, 45U, 0U),
                      &c3_d75, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PEY1 = c3_d75;
  sf_mex_import_named("PEY2", sf_mex_get_sfun_param(chartInstance->S, 46U, 0U),
                      &c3_d76, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PEY2 = c3_d76;
  sf_mex_import_named("PEY3", sf_mex_get_sfun_param(chartInstance->S, 47U, 0U),
                      &c3_d77, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PEY3 = c3_d77;
  sf_mex_import_named("PEY4", sf_mex_get_sfun_param(chartInstance->S, 48U, 0U),
                      &c3_d78, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PEY4 = c3_d78;
  sf_mex_import_named("PEY5", sf_mex_get_sfun_param(chartInstance->S, 49U, 0U),
                      &c3_d79, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PEY5 = c3_d79;
  sf_mex_import_named("PKY1", sf_mex_get_sfun_param(chartInstance->S, 62U, 0U),
                      &c3_d80, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PKY1 = c3_d80;
  sf_mex_import_named("PKY2", sf_mex_get_sfun_param(chartInstance->S, 63U, 0U),
                      &c3_d81, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PKY2 = c3_d81;
  sf_mex_import_named("PKY3", sf_mex_get_sfun_param(chartInstance->S, 64U, 0U),
                      &c3_d82, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PKY3 = c3_d82;
  sf_mex_import_named("PKY4", sf_mex_get_sfun_param(chartInstance->S, 65U, 0U),
                      &c3_d83, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PKY4 = c3_d83;
  sf_mex_import_named("PKY5", sf_mex_get_sfun_param(chartInstance->S, 66U, 0U),
                      &c3_d84, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PKY5 = c3_d84;
  sf_mex_import_named("PKY6", sf_mex_get_sfun_param(chartInstance->S, 67U, 0U),
                      &c3_d85, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PKY6 = c3_d85;
  sf_mex_import_named("PKY7", sf_mex_get_sfun_param(chartInstance->S, 68U, 0U),
                      &c3_d86, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PKY7 = c3_d86;
  sf_mex_import_named("PHY1", sf_mex_get_sfun_param(chartInstance->S, 53U, 0U),
                      &c3_d87, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PHY1 = c3_d87;
  sf_mex_import_named("PHY2", sf_mex_get_sfun_param(chartInstance->S, 54U, 0U),
                      &c3_d88, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PHY2 = c3_d88;
  sf_mex_import_named("PVY1", sf_mex_get_sfun_param(chartInstance->S, 86U, 0U),
                      &c3_d89, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PVY1 = c3_d89;
  sf_mex_import_named("PVY2", sf_mex_get_sfun_param(chartInstance->S, 87U, 0U),
                      &c3_d90, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PVY2 = c3_d90;
  sf_mex_import_named("PVY3", sf_mex_get_sfun_param(chartInstance->S, 88U, 0U),
                      &c3_d91, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PVY3 = c3_d91;
  sf_mex_import_named("PVY4", sf_mex_get_sfun_param(chartInstance->S, 89U, 0U),
                      &c3_d92, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PVY4 = c3_d92;
  sf_mex_import_named("PPY1", sf_mex_get_sfun_param(chartInstance->S, 75U, 0U),
                      &c3_d93, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PPY1 = c3_d93;
  sf_mex_import_named("PPY2", sf_mex_get_sfun_param(chartInstance->S, 76U, 0U),
                      &c3_d94, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PPY2 = c3_d94;
  sf_mex_import_named("PPY3", sf_mex_get_sfun_param(chartInstance->S, 77U, 0U),
                      &c3_d95, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PPY3 = c3_d95;
  sf_mex_import_named("PPY4", sf_mex_get_sfun_param(chartInstance->S, 78U, 0U),
                      &c3_d96, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PPY4 = c3_d96;
  sf_mex_import_named("PPY5", sf_mex_get_sfun_param(chartInstance->S, 79U, 0U),
                      &c3_d97, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PPY5 = c3_d97;
  sf_mex_import_named("RBY1", sf_mex_get_sfun_param(chartInstance->S, 162U, 0U),
                      &c3_d98, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_RBY1 = c3_d98;
  sf_mex_import_named("RBY2", sf_mex_get_sfun_param(chartInstance->S, 163U, 0U),
                      &c3_d99, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_RBY2 = c3_d99;
  sf_mex_import_named("RBY3", sf_mex_get_sfun_param(chartInstance->S, 164U, 0U),
                      &c3_d100, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_RBY3 = c3_d100;
  sf_mex_import_named("RBY4", sf_mex_get_sfun_param(chartInstance->S, 165U, 0U),
                      &c3_d101, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_RBY4 = c3_d101;
  sf_mex_import_named("RCY1", sf_mex_get_sfun_param(chartInstance->S, 167U, 0U),
                      &c3_d102, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_RCY1 = c3_d102;
  sf_mex_import_named("REY1", sf_mex_get_sfun_param(chartInstance->S, 170U, 0U),
                      &c3_d103, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_REY1 = c3_d103;
  sf_mex_import_named("REY2", sf_mex_get_sfun_param(chartInstance->S, 171U, 0U),
                      &c3_d104, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_REY2 = c3_d104;
  sf_mex_import_named("RHY1", sf_mex_get_sfun_param(chartInstance->S, 173U, 0U),
                      &c3_d105, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_RHY1 = c3_d105;
  sf_mex_import_named("RHY2", sf_mex_get_sfun_param(chartInstance->S, 174U, 0U),
                      &c3_d106, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_RHY2 = c3_d106;
  sf_mex_import_named("RVY1", sf_mex_get_sfun_param(chartInstance->S, 176U, 0U),
                      &c3_d107, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_RVY1 = c3_d107;
  sf_mex_import_named("RVY2", sf_mex_get_sfun_param(chartInstance->S, 177U, 0U),
                      &c3_d108, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_RVY2 = c3_d108;
  sf_mex_import_named("RVY3", sf_mex_get_sfun_param(chartInstance->S, 178U, 0U),
                      &c3_d109, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_RVY3 = c3_d109;
  sf_mex_import_named("RVY4", sf_mex_get_sfun_param(chartInstance->S, 179U, 0U),
                      &c3_d110, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_RVY4 = c3_d110;
  sf_mex_import_named("RVY5", sf_mex_get_sfun_param(chartInstance->S, 180U, 0U),
                      &c3_d111, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_RVY5 = c3_d111;
  sf_mex_import_named("RVY6", sf_mex_get_sfun_param(chartInstance->S, 181U, 0U),
                      &c3_d112, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_RVY6 = c3_d112;
  sf_mex_import_named("QSY1", sf_mex_get_sfun_param(chartInstance->S, 138U, 0U),
                      &c3_d113, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QSY1 = c3_d113;
  sf_mex_import_named("QSY2", sf_mex_get_sfun_param(chartInstance->S, 139U, 0U),
                      &c3_d114, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QSY2 = c3_d114;
  sf_mex_import_named("QSY3", sf_mex_get_sfun_param(chartInstance->S, 140U, 0U),
                      &c3_d115, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QSY3 = c3_d115;
  sf_mex_import_named("QSY4", sf_mex_get_sfun_param(chartInstance->S, 141U, 0U),
                      &c3_d116, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QSY4 = c3_d116;
  sf_mex_import_named("QSY5", sf_mex_get_sfun_param(chartInstance->S, 142U, 0U),
                      &c3_d117, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QSY5 = c3_d117;
  sf_mex_import_named("QSY6", sf_mex_get_sfun_param(chartInstance->S, 143U, 0U),
                      &c3_d118, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QSY6 = c3_d118;
  sf_mex_import_named("QSY7", sf_mex_get_sfun_param(chartInstance->S, 144U, 0U),
                      &c3_d119, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QSY7 = c3_d119;
  sf_mex_import_named("QSY8", sf_mex_get_sfun_param(chartInstance->S, 145U, 0U),
                      &c3_d120, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QSY8 = c3_d120;
  sf_mex_import_named("QBZ1", sf_mex_get_sfun_param(chartInstance->S, 91U, 0U),
                      &c3_d121, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QBZ1 = c3_d121;
  sf_mex_import_named("QBZ2", sf_mex_get_sfun_param(chartInstance->S, 93U, 0U),
                      &c3_d122, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QBZ2 = c3_d122;
  sf_mex_import_named("QBZ3", sf_mex_get_sfun_param(chartInstance->S, 94U, 0U),
                      &c3_d123, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QBZ3 = c3_d123;
  sf_mex_import_named("QBZ4", sf_mex_get_sfun_param(chartInstance->S, 95U, 0U),
                      &c3_d124, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QBZ4 = c3_d124;
  sf_mex_import_named("QBZ5", sf_mex_get_sfun_param(chartInstance->S, 96U, 0U),
                      &c3_d125, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QBZ5 = c3_d125;
  sf_mex_import_named("QBZ6", sf_mex_get_sfun_param(chartInstance->S, 97U, 0U),
                      &c3_d126, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QBZ6 = c3_d126;
  sf_mex_import_named("QBZ9", sf_mex_get_sfun_param(chartInstance->S, 98U, 0U),
                      &c3_d127, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QBZ9 = c3_d127;
  sf_mex_import_named("QBZ10", sf_mex_get_sfun_param(chartInstance->S, 92U, 0U),
                      &c3_d128, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QBZ10 = c3_d128;
  sf_mex_import_named("QCZ1", sf_mex_get_sfun_param(chartInstance->S, 101U, 0U),
                      &c3_d129, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QCZ1 = c3_d129;
  sf_mex_import_named("QDZ1", sf_mex_get_sfun_param(chartInstance->S, 105U, 0U),
                      &c3_d130, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QDZ1 = c3_d130;
  sf_mex_import_named("QDZ2", sf_mex_get_sfun_param(chartInstance->S, 108U, 0U),
                      &c3_d131, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QDZ2 = c3_d131;
  sf_mex_import_named("QDZ3", sf_mex_get_sfun_param(chartInstance->S, 109U, 0U),
                      &c3_d132, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QDZ3 = c3_d132;
  sf_mex_import_named("QDZ4", sf_mex_get_sfun_param(chartInstance->S, 110U, 0U),
                      &c3_d133, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QDZ4 = c3_d133;
  sf_mex_import_named("QDZ6", sf_mex_get_sfun_param(chartInstance->S, 111U, 0U),
                      &c3_d134, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QDZ6 = c3_d134;
  sf_mex_import_named("QDZ7", sf_mex_get_sfun_param(chartInstance->S, 112U, 0U),
                      &c3_d135, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QDZ7 = c3_d135;
  sf_mex_import_named("QDZ8", sf_mex_get_sfun_param(chartInstance->S, 113U, 0U),
                      &c3_d136, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QDZ8 = c3_d136;
  sf_mex_import_named("QDZ9", sf_mex_get_sfun_param(chartInstance->S, 114U, 0U),
                      &c3_d137, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QDZ9 = c3_d137;
  sf_mex_import_named("QDZ10", sf_mex_get_sfun_param(chartInstance->S, 106U, 0U),
                      &c3_d138, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QDZ10 = c3_d138;
  sf_mex_import_named("QDZ11", sf_mex_get_sfun_param(chartInstance->S, 107U, 0U),
                      &c3_d139, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QDZ11 = c3_d139;
  sf_mex_import_named("QEZ1", sf_mex_get_sfun_param(chartInstance->S, 115U, 0U),
                      &c3_d140, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QEZ1 = c3_d140;
  sf_mex_import_named("QEZ2", sf_mex_get_sfun_param(chartInstance->S, 116U, 0U),
                      &c3_d141, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QEZ2 = c3_d141;
  sf_mex_import_named("QEZ3", sf_mex_get_sfun_param(chartInstance->S, 117U, 0U),
                      &c3_d142, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QEZ3 = c3_d142;
  sf_mex_import_named("QEZ4", sf_mex_get_sfun_param(chartInstance->S, 118U, 0U),
                      &c3_d143, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QEZ4 = c3_d143;
  sf_mex_import_named("QEZ5", sf_mex_get_sfun_param(chartInstance->S, 119U, 0U),
                      &c3_d144, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QEZ5 = c3_d144;
  sf_mex_import_named("QHZ1", sf_mex_get_sfun_param(chartInstance->S, 120U, 0U),
                      &c3_d145, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QHZ1 = c3_d145;
  sf_mex_import_named("QHZ2", sf_mex_get_sfun_param(chartInstance->S, 121U, 0U),
                      &c3_d146, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QHZ2 = c3_d146;
  sf_mex_import_named("QHZ3", sf_mex_get_sfun_param(chartInstance->S, 122U, 0U),
                      &c3_d147, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QHZ3 = c3_d147;
  sf_mex_import_named("QHZ4", sf_mex_get_sfun_param(chartInstance->S, 123U, 0U),
                      &c3_d148, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QHZ4 = c3_d148;
  sf_mex_import_named("PPZ1", sf_mex_get_sfun_param(chartInstance->S, 80U, 0U),
                      &c3_d149, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PPZ1 = c3_d149;
  sf_mex_import_named("PPZ2", sf_mex_get_sfun_param(chartInstance->S, 81U, 0U),
                      &c3_d150, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PPZ2 = c3_d150;
  sf_mex_import_named("SSZ1", sf_mex_get_sfun_param(chartInstance->S, 182U, 0U),
                      &c3_d151, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_SSZ1 = c3_d151;
  sf_mex_import_named("SSZ2", sf_mex_get_sfun_param(chartInstance->S, 183U, 0U),
                      &c3_d152, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_SSZ2 = c3_d152;
  sf_mex_import_named("SSZ3", sf_mex_get_sfun_param(chartInstance->S, 184U, 0U),
                      &c3_d153, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_SSZ3 = c3_d153;
  sf_mex_import_named("SSZ4", sf_mex_get_sfun_param(chartInstance->S, 185U, 0U),
                      &c3_d154, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_SSZ4 = c3_d154;
  sf_mex_import_named("PDXP1", sf_mex_get_sfun_param(chartInstance->S, 29U, 0U),
                      &c3_d155, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PDXP1 = c3_d155;
  sf_mex_import_named("PDXP2", sf_mex_get_sfun_param(chartInstance->S, 30U, 0U),
                      &c3_d156, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PDXP2 = c3_d156;
  sf_mex_import_named("PDXP3", sf_mex_get_sfun_param(chartInstance->S, 31U, 0U),
                      &c3_d157, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PDXP3 = c3_d157;
  sf_mex_import_named("PKYP1", sf_mex_get_sfun_param(chartInstance->S, 69U, 0U),
                      &c3_d158, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PKYP1 = c3_d158;
  sf_mex_import_named("PDYP1", sf_mex_get_sfun_param(chartInstance->S, 35U, 0U),
                      &c3_d159, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PDYP1 = c3_d159;
  sf_mex_import_named("PDYP2", sf_mex_get_sfun_param(chartInstance->S, 36U, 0U),
                      &c3_d160, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PDYP2 = c3_d160;
  sf_mex_import_named("PDYP3", sf_mex_get_sfun_param(chartInstance->S, 37U, 0U),
                      &c3_d161, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PDYP3 = c3_d161;
  sf_mex_import_named("PDYP4", sf_mex_get_sfun_param(chartInstance->S, 38U, 0U),
                      &c3_d162, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PDYP4 = c3_d162;
  sf_mex_import_named("PHYP1", sf_mex_get_sfun_param(chartInstance->S, 55U, 0U),
                      &c3_d163, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PHYP1 = c3_d163;
  sf_mex_import_named("PHYP2", sf_mex_get_sfun_param(chartInstance->S, 56U, 0U),
                      &c3_d164, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PHYP2 = c3_d164;
  sf_mex_import_named("PHYP3", sf_mex_get_sfun_param(chartInstance->S, 57U, 0U),
                      &c3_d165, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PHYP3 = c3_d165;
  sf_mex_import_named("PHYP4", sf_mex_get_sfun_param(chartInstance->S, 58U, 0U),
                      &c3_d166, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PHYP4 = c3_d166;
  sf_mex_import_named("PECP1", sf_mex_get_sfun_param(chartInstance->S, 39U, 0U),
                      &c3_d167, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PECP1 = c3_d167;
  sf_mex_import_named("PECP2", sf_mex_get_sfun_param(chartInstance->S, 40U, 0U),
                      &c3_d168, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PECP2 = c3_d168;
  sf_mex_import_named("QDTP1", sf_mex_get_sfun_param(chartInstance->S, 104U, 0U),
                      &c3_d169, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QDTP1 = c3_d169;
  sf_mex_import_named("QCRP1", sf_mex_get_sfun_param(chartInstance->S, 99U, 0U),
                      &c3_d170, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QCRP1 = c3_d170;
  sf_mex_import_named("QCRP2", sf_mex_get_sfun_param(chartInstance->S, 100U, 0U),
                      &c3_d171, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QCRP2 = c3_d171;
  sf_mex_import_named("QBRP1", sf_mex_get_sfun_param(chartInstance->S, 90U, 0U),
                      &c3_d172, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QBRP1 = c3_d172;
  sf_mex_import_named("QDRP1", sf_mex_get_sfun_param(chartInstance->S, 102U, 0U),
                      &c3_d173, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QDRP1 = c3_d173;
  sf_mex_import_named("QDRP2", sf_mex_get_sfun_param(chartInstance->S, 103U, 0U),
                      &c3_d174, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QDRP2 = c3_d174;
  sf_mex_import_named("WIDTH", sf_mex_get_sfun_param(chartInstance->S, 189U, 0U),
                      &c3_d175, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_WIDTH = c3_d175;
  sf_mex_import_named("Q_RA1", sf_mex_get_sfun_param(chartInstance->S, 152U, 0U),
                      &c3_d176, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_Q_RA1 = c3_d176;
  sf_mex_import_named("Q_RA2", sf_mex_get_sfun_param(chartInstance->S, 153U, 0U),
                      &c3_d177, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_Q_RA2 = c3_d177;
  sf_mex_import_named("Q_RB1", sf_mex_get_sfun_param(chartInstance->S, 154U, 0U),
                      &c3_d178, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_Q_RB1 = c3_d178;
  sf_mex_import_named("Q_RB2", sf_mex_get_sfun_param(chartInstance->S, 155U, 0U),
                      &c3_d179, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_Q_RB2 = c3_d179;
  sf_mex_import_named("QSX12", sf_mex_get_sfun_param(chartInstance->S, 127U, 0U),
                      &c3_d180, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QSX12 = c3_d180;
  sf_mex_import_named("QSX13", sf_mex_get_sfun_param(chartInstance->S, 128U, 0U),
                      &c3_d181, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QSX13 = c3_d181;
  sf_mex_import_named("QSX14", sf_mex_get_sfun_param(chartInstance->S, 129U, 0U),
                      &c3_d182, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_QSX14 = c3_d182;
  sf_mex_import_named("Q_FZ3", sf_mex_get_sfun_param(chartInstance->S, 151U, 0U),
                      &c3_d183, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_Q_FZ3 = c3_d183;
  sf_mex_import_named("LONGITUDINAL_STIFFNESS", sf_mex_get_sfun_param
                      (chartInstance->S, 15U, 0U), &c3_d184, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_LONGITUDINAL_STIFFNESS = c3_d184;
  sf_mex_import_named("LATERAL_STIFFNESS", sf_mex_get_sfun_param
                      (chartInstance->S, 14U, 0U), &c3_d185, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_LATERAL_STIFFNESS = c3_d185;
  sf_mex_import_named("PCFX1", sf_mex_get_sfun_param(chartInstance->S, 18U, 0U),
                      &c3_d186, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PCFX1 = c3_d186;
  sf_mex_import_named("PCFX2", sf_mex_get_sfun_param(chartInstance->S, 19U, 0U),
                      &c3_d187, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PCFX2 = c3_d187;
  sf_mex_import_named("PCFX3", sf_mex_get_sfun_param(chartInstance->S, 20U, 0U),
                      &c3_d188, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PCFX3 = c3_d188;
  sf_mex_import_named("PCFY1", sf_mex_get_sfun_param(chartInstance->S, 21U, 0U),
                      &c3_d189, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PCFY1 = c3_d189;
  sf_mex_import_named("PCFY2", sf_mex_get_sfun_param(chartInstance->S, 22U, 0U),
                      &c3_d190, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PCFY2 = c3_d190;
  sf_mex_import_named("PCFY3", sf_mex_get_sfun_param(chartInstance->S, 23U, 0U),
                      &c3_d191, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_PCFY3 = c3_d191;
  sf_mex_import_named("vdynMF", sf_mex_get_sfun_param(chartInstance->S, 192U, 0U),
                      c3_dv, 0, 0, 0U, 1, 0U, 1, 279);
  for (c3_i = 0; c3_i < 279; c3_i++) {
    chartInstance->c3_vdynMF[c3_i] = c3_dv[c3_i];
  }
}

static void mdl_start_c3_vehdynlibtirecommon
  (SFc3_vehdynlibtirecommonInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_terminate_c3_vehdynlibtirecommon
  (SFc3_vehdynlibtirecommonInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c3_vehdynlibtirecommon
  (SFc3_vehdynlibtirecommonInstanceStruct *chartInstance)
{
  static const uint32_T c3_decisionTxtEndIdx = 0U;
  static const uint32_T c3_decisionTxtStartIdx = 0U;
  setDebuggerFlag(chartInstance->S, true);
  setDataBrowseFcn(chartInstance->S, (void *)&c3_chart_data_browse_helper);
  chartInstance->c3_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c3_RuntimeVar,
    &chartInstance->c3_IsDebuggerActive,
    &chartInstance->c3_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c3_mlFcnLineNumber, &chartInstance->c3_IsHeatMapPresent, 0);
  sim_mode_is_external(chartInstance->S);
  covrtCreateStateflowInstanceData(chartInstance->c3_covrtInstance, 1U, 0U, 1U,
    432U);
  covrtChartInitFcn(chartInstance->c3_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c3_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c3_decisionTxtStartIdx, &c3_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c3_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c3_covrtInstance, "", 4U, 0U, 1U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 42, -1, 5941);
}

static void mdl_cleanup_runtime_resources_c3_vehdynlibtirecommon
  (SFc3_vehdynlibtirecommonInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c3_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c3_covrtInstance);
}

static void enable_c3_vehdynlibtirecommon(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_vehdynlibtirecommon
  (SFc3_vehdynlibtirecommonInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c3_vehdynlibtirecommon
  (SFc3_vehdynlibtirecommonInstanceStruct *chartInstance)
{
  emlrtStack c3_b_st;
  emlrtStack c3_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  real_T c3_dv8[279];
  real_T c3_dv4[108];
  real_T c3_b_Alpha[4];
  real_T c3_b_Fx[4];
  real_T c3_b_Fy[4];
  real_T c3_b_FzTire[4];
  real_T c3_b_Gamma[4];
  real_T c3_b_Kappa[4];
  real_T c3_b_Mx[4];
  real_T c3_b_My[4];
  real_T c3_b_Mz[4];
  real_T c3_b_Re[4];
  real_T c3_b_TirePrs[4];
  real_T c3_b_a[4];
  real_T c3_b_b[4];
  real_T c3_b_sig_x[4];
  real_T c3_b_sig_y[4];
  real_T c3_dv[4];
  real_T c3_dv1[4];
  real_T c3_dv2[4];
  real_T c3_dv3[4];
  real_T c3_dv5[4];
  real_T c3_dv6[4];
  real_T c3_dv7[4];
  real_T c3_b_ALPMAX;
  real_T c3_b_ALPMIN;
  real_T c3_b_BOTTOM_OFFST;
  real_T c3_b_BOTTOM_STIFF;
  real_T c3_b_BREFF;
  real_T c3_b_CAMMAX;
  real_T c3_b_CAMMIN;
  real_T c3_b_DREFF;
  real_T c3_b_FNOMIN;
  real_T c3_b_FREFF;
  real_T c3_b_FZMAX;
  real_T c3_b_FZMIN;
  real_T c3_b_KPUMAX;
  real_T c3_b_KPUMIN;
  real_T c3_b_LATERAL_STIFFNESS;
  real_T c3_b_LONGITUDINAL_STIFFNESS;
  real_T c3_b_LONGVL;
  real_T c3_b_NOMPRES;
  real_T c3_b_PCFX1;
  real_T c3_b_PCFX2;
  real_T c3_b_PCFX3;
  real_T c3_b_PCFY1;
  real_T c3_b_PCFY2;
  real_T c3_b_PCFY3;
  real_T c3_b_PCX1;
  real_T c3_b_PCY1;
  real_T c3_b_PDX1;
  real_T c3_b_PDX2;
  real_T c3_b_PDX3;
  real_T c3_b_PDXP1;
  real_T c3_b_PDXP2;
  real_T c3_b_PDXP3;
  real_T c3_b_PDY1;
  real_T c3_b_PDY2;
  real_T c3_b_PDY3;
  real_T c3_b_PDYP1;
  real_T c3_b_PDYP2;
  real_T c3_b_PDYP3;
  real_T c3_b_PDYP4;
  real_T c3_b_PECP1;
  real_T c3_b_PECP2;
  real_T c3_b_PEX1;
  real_T c3_b_PEX2;
  real_T c3_b_PEX3;
  real_T c3_b_PEX4;
  real_T c3_b_PEY1;
  real_T c3_b_PEY2;
  real_T c3_b_PEY3;
  real_T c3_b_PEY4;
  real_T c3_b_PEY5;
  real_T c3_b_PFZ1;
  real_T c3_b_PHX1;
  real_T c3_b_PHX2;
  real_T c3_b_PHY1;
  real_T c3_b_PHY2;
  real_T c3_b_PHYP1;
  real_T c3_b_PHYP2;
  real_T c3_b_PHYP3;
  real_T c3_b_PHYP4;
  real_T c3_b_PKX1;
  real_T c3_b_PKX2;
  real_T c3_b_PKX3;
  real_T c3_b_PKY1;
  real_T c3_b_PKY2;
  real_T c3_b_PKY3;
  real_T c3_b_PKY4;
  real_T c3_b_PKY5;
  real_T c3_b_PKY6;
  real_T c3_b_PKY7;
  real_T c3_b_PKYP1;
  real_T c3_b_PPMX1;
  real_T c3_b_PPX1;
  real_T c3_b_PPX2;
  real_T c3_b_PPX3;
  real_T c3_b_PPX4;
  real_T c3_b_PPY1;
  real_T c3_b_PPY2;
  real_T c3_b_PPY3;
  real_T c3_b_PPY4;
  real_T c3_b_PPY5;
  real_T c3_b_PPZ1;
  real_T c3_b_PPZ2;
  real_T c3_b_PRESMAX;
  real_T c3_b_PRESMIN;
  real_T c3_b_PVX1;
  real_T c3_b_PVX2;
  real_T c3_b_PVY1;
  real_T c3_b_PVY2;
  real_T c3_b_PVY3;
  real_T c3_b_PVY4;
  real_T c3_b_QBRP1;
  real_T c3_b_QBZ1;
  real_T c3_b_QBZ10;
  real_T c3_b_QBZ2;
  real_T c3_b_QBZ3;
  real_T c3_b_QBZ4;
  real_T c3_b_QBZ5;
  real_T c3_b_QBZ6;
  real_T c3_b_QBZ9;
  real_T c3_b_QCRP1;
  real_T c3_b_QCRP2;
  real_T c3_b_QCZ1;
  real_T c3_b_QDRP1;
  real_T c3_b_QDRP2;
  real_T c3_b_QDTP1;
  real_T c3_b_QDZ1;
  real_T c3_b_QDZ10;
  real_T c3_b_QDZ11;
  real_T c3_b_QDZ2;
  real_T c3_b_QDZ3;
  real_T c3_b_QDZ4;
  real_T c3_b_QDZ6;
  real_T c3_b_QDZ7;
  real_T c3_b_QDZ8;
  real_T c3_b_QDZ9;
  real_T c3_b_QEZ1;
  real_T c3_b_QEZ2;
  real_T c3_b_QEZ3;
  real_T c3_b_QEZ4;
  real_T c3_b_QEZ5;
  real_T c3_b_QHZ1;
  real_T c3_b_QHZ2;
  real_T c3_b_QHZ3;
  real_T c3_b_QHZ4;
  real_T c3_b_QSX1;
  real_T c3_b_QSX10;
  real_T c3_b_QSX11;
  real_T c3_b_QSX12;
  real_T c3_b_QSX13;
  real_T c3_b_QSX14;
  real_T c3_b_QSX2;
  real_T c3_b_QSX3;
  real_T c3_b_QSX4;
  real_T c3_b_QSX5;
  real_T c3_b_QSX6;
  real_T c3_b_QSX7;
  real_T c3_b_QSX8;
  real_T c3_b_QSX9;
  real_T c3_b_QSY1;
  real_T c3_b_QSY2;
  real_T c3_b_QSY3;
  real_T c3_b_QSY4;
  real_T c3_b_QSY5;
  real_T c3_b_QSY6;
  real_T c3_b_QSY7;
  real_T c3_b_QSY8;
  real_T c3_b_Q_FCX;
  real_T c3_b_Q_FCY;
  real_T c3_b_Q_FCY2;
  real_T c3_b_Q_FZ1;
  real_T c3_b_Q_FZ2;
  real_T c3_b_Q_FZ3;
  real_T c3_b_Q_RA1;
  real_T c3_b_Q_RA2;
  real_T c3_b_Q_RB1;
  real_T c3_b_Q_RB2;
  real_T c3_b_Q_RE0;
  real_T c3_b_Q_V1;
  real_T c3_b_Q_V2;
  real_T c3_b_RBX1;
  real_T c3_b_RBX2;
  real_T c3_b_RBX3;
  real_T c3_b_RBY1;
  real_T c3_b_RBY2;
  real_T c3_b_RBY3;
  real_T c3_b_RBY4;
  real_T c3_b_RCX1;
  real_T c3_b_RCY1;
  real_T c3_b_REX1;
  real_T c3_b_REX2;
  real_T c3_b_REY1;
  real_T c3_b_REY2;
  real_T c3_b_RHX1;
  real_T c3_b_RHY1;
  real_T c3_b_RHY2;
  real_T c3_b_RIM_RADIUS;
  real_T c3_b_RVY1;
  real_T c3_b_RVY2;
  real_T c3_b_RVY3;
  real_T c3_b_RVY4;
  real_T c3_b_RVY5;
  real_T c3_b_RVY6;
  real_T c3_b_SSZ1;
  real_T c3_b_SSZ2;
  real_T c3_b_SSZ3;
  real_T c3_b_SSZ4;
  real_T c3_b_UNLOADED_RADIUS;
  real_T c3_b_VERTICAL_STIFFNESS;
  real_T c3_b_VXLOW;
  real_T c3_b_WIDTH;
  real_T c3_b_turnslip;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i10;
  int32_T c3_i11;
  int32_T c3_i12;
  int32_T c3_i13;
  int32_T c3_i14;
  int32_T c3_i15;
  int32_T c3_i16;
  int32_T c3_i17;
  int32_T c3_i18;
  int32_T c3_i19;
  int32_T c3_i2;
  int32_T c3_i20;
  int32_T c3_i21;
  int32_T c3_i22;
  int32_T c3_i23;
  int32_T c3_i24;
  int32_T c3_i25;
  int32_T c3_i26;
  int32_T c3_i27;
  int32_T c3_i28;
  int32_T c3_i29;
  int32_T c3_i3;
  int32_T c3_i30;
  int32_T c3_i31;
  int32_T c3_i32;
  int32_T c3_i33;
  int32_T c3_i34;
  int32_T c3_i35;
  int32_T c3_i36;
  int32_T c3_i37;
  int32_T c3_i38;
  int32_T c3_i39;
  int32_T c3_i4;
  int32_T c3_i40;
  int32_T c3_i41;
  int32_T c3_i42;
  int32_T c3_i43;
  int32_T c3_i44;
  int32_T c3_i45;
  int32_T c3_i46;
  int32_T c3_i5;
  int32_T c3_i6;
  int32_T c3_i7;
  int32_T c3_i8;
  int32_T c3_i9;
  c3_st.tls = chartInstance->c3_fEmlrtCtx;
  c3_b_st.prev = &c3_st;
  c3_b_st.tls = c3_st.tls;
  chartInstance->c3_JITTransitionAnimation[0] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  for (c3_i = 0; c3_i < 4; c3_i++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 9U,
                      (*chartInstance->c3_Fy_ext)[c3_i]);
  }

  for (c3_i1 = 0; c3_i1 < 4; c3_i1++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 8U,
                      (*chartInstance->c3_Fx_ext)[c3_i1]);
  }

  for (c3_i2 = 0; c3_i2 < 4; c3_i2++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 7U,
                      (*chartInstance->c3_rhoz)[c3_i2]);
  }

  for (c3_i3 = 0; c3_i3 < 108; c3_i3++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 6U,
                      (*chartInstance->c3_ScaleFactors)[c3_i3]);
  }

  for (c3_i4 = 0; c3_i4 < 4; c3_i4++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 5U,
                      (*chartInstance->c3_TirePrs)[c3_i4]);
  }

  for (c3_i5 = 0; c3_i5 < 4; c3_i5++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 4U,
                      (*chartInstance->c3_Gamma)[c3_i5]);
  }

  for (c3_i6 = 0; c3_i6 < 4; c3_i6++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 3U,
                      (*chartInstance->c3_psidot)[c3_i6]);
  }

  for (c3_i7 = 0; c3_i7 < 4; c3_i7++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 2U,
                      (*chartInstance->c3_Vy)[c3_i7]);
  }

  for (c3_i8 = 0; c3_i8 < 4; c3_i8++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 1U,
                      (*chartInstance->c3_Vx)[c3_i8]);
  }

  for (c3_i9 = 0; c3_i9 < 4; c3_i9++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 0U,
                      (*chartInstance->c3_Omega)[c3_i9]);
  }

  chartInstance->c3_sfEvent = CALL_EVENT;
  for (c3_i10 = 0; c3_i10 < 4; c3_i10++) {
    c3_b_Gamma[c3_i10] = (*chartInstance->c3_Gamma)[c3_i10];
  }

  for (c3_i11 = 0; c3_i11 < 4; c3_i11++) {
    c3_b_TirePrs[c3_i11] = (*chartInstance->c3_TirePrs)[c3_i11];
  }

  c3_b_turnslip = chartInstance->c3_turnslip;
  c3_b_PRESMAX = chartInstance->c3_PRESMAX;
  c3_b_PRESMIN = chartInstance->c3_PRESMIN;
  c3_b_FZMAX = chartInstance->c3_FZMAX;
  c3_b_FZMIN = chartInstance->c3_FZMIN;
  c3_b_VXLOW = chartInstance->c3_VXLOW;
  c3_b_KPUMAX = chartInstance->c3_KPUMAX;
  c3_b_KPUMIN = chartInstance->c3_KPUMIN;
  c3_b_ALPMAX = chartInstance->c3_ALPMAX;
  c3_b_ALPMIN = chartInstance->c3_ALPMIN;
  c3_b_CAMMIN = chartInstance->c3_CAMMIN;
  c3_b_CAMMAX = chartInstance->c3_CAMMAX;
  c3_b_LONGVL = chartInstance->c3_LONGVL;
  c3_b_UNLOADED_RADIUS = chartInstance->c3_UNLOADED_RADIUS;
  c3_b_RIM_RADIUS = chartInstance->c3_RIM_RADIUS;
  c3_b_NOMPRES = chartInstance->c3_NOMPRES;
  c3_b_FNOMIN = chartInstance->c3_FNOMIN;
  c3_b_VERTICAL_STIFFNESS = chartInstance->c3_VERTICAL_STIFFNESS;
  c3_b_DREFF = chartInstance->c3_DREFF;
  c3_b_BREFF = chartInstance->c3_BREFF;
  c3_b_FREFF = chartInstance->c3_FREFF;
  c3_b_Q_RE0 = chartInstance->c3_Q_RE0;
  c3_b_Q_V1 = chartInstance->c3_Q_V1;
  c3_b_Q_V2 = chartInstance->c3_Q_V2;
  c3_b_Q_FZ1 = chartInstance->c3_Q_FZ1;
  c3_b_Q_FZ2 = chartInstance->c3_Q_FZ2;
  c3_b_Q_FCX = chartInstance->c3_Q_FCX;
  c3_b_Q_FCY = chartInstance->c3_Q_FCY;
  c3_b_PFZ1 = chartInstance->c3_PFZ1;
  c3_b_Q_FCY2 = chartInstance->c3_Q_FCY2;
  c3_b_BOTTOM_OFFST = chartInstance->c3_BOTTOM_OFFST;
  c3_b_BOTTOM_STIFF = chartInstance->c3_BOTTOM_STIFF;
  c3_b_PCX1 = chartInstance->c3_PCX1;
  c3_b_PDX1 = chartInstance->c3_PDX1;
  c3_b_PDX2 = chartInstance->c3_PDX2;
  c3_b_PDX3 = chartInstance->c3_PDX3;
  c3_b_PEX1 = chartInstance->c3_PEX1;
  c3_b_PEX2 = chartInstance->c3_PEX2;
  c3_b_PEX3 = chartInstance->c3_PEX3;
  c3_b_PEX4 = chartInstance->c3_PEX4;
  c3_b_PKX1 = chartInstance->c3_PKX1;
  c3_b_PKX2 = chartInstance->c3_PKX2;
  c3_b_PKX3 = chartInstance->c3_PKX3;
  c3_b_PHX1 = chartInstance->c3_PHX1;
  c3_b_PHX2 = chartInstance->c3_PHX2;
  c3_b_PVX1 = chartInstance->c3_PVX1;
  c3_b_PVX2 = chartInstance->c3_PVX2;
  c3_b_PPX1 = chartInstance->c3_PPX1;
  c3_b_PPX2 = chartInstance->c3_PPX2;
  c3_b_PPX3 = chartInstance->c3_PPX3;
  c3_b_PPX4 = chartInstance->c3_PPX4;
  c3_b_RBX1 = chartInstance->c3_RBX1;
  c3_b_RBX2 = chartInstance->c3_RBX2;
  c3_b_RBX3 = chartInstance->c3_RBX3;
  c3_b_RCX1 = chartInstance->c3_RCX1;
  c3_b_REX1 = chartInstance->c3_REX1;
  c3_b_REX2 = chartInstance->c3_REX2;
  c3_b_RHX1 = chartInstance->c3_RHX1;
  c3_b_QSX1 = chartInstance->c3_QSX1;
  c3_b_QSX2 = chartInstance->c3_QSX2;
  c3_b_QSX3 = chartInstance->c3_QSX3;
  c3_b_QSX4 = chartInstance->c3_QSX4;
  c3_b_QSX5 = chartInstance->c3_QSX5;
  c3_b_QSX6 = chartInstance->c3_QSX6;
  c3_b_QSX7 = chartInstance->c3_QSX7;
  c3_b_QSX8 = chartInstance->c3_QSX8;
  c3_b_QSX9 = chartInstance->c3_QSX9;
  c3_b_QSX10 = chartInstance->c3_QSX10;
  c3_b_QSX11 = chartInstance->c3_QSX11;
  c3_b_PPMX1 = chartInstance->c3_PPMX1;
  c3_b_PCY1 = chartInstance->c3_PCY1;
  c3_b_PDY1 = chartInstance->c3_PDY1;
  c3_b_PDY2 = chartInstance->c3_PDY2;
  c3_b_PDY3 = chartInstance->c3_PDY3;
  c3_b_PEY1 = chartInstance->c3_PEY1;
  c3_b_PEY2 = chartInstance->c3_PEY2;
  c3_b_PEY3 = chartInstance->c3_PEY3;
  c3_b_PEY4 = chartInstance->c3_PEY4;
  c3_b_PEY5 = chartInstance->c3_PEY5;
  c3_b_PKY1 = chartInstance->c3_PKY1;
  c3_b_PKY2 = chartInstance->c3_PKY2;
  c3_b_PKY3 = chartInstance->c3_PKY3;
  c3_b_PKY4 = chartInstance->c3_PKY4;
  c3_b_PKY5 = chartInstance->c3_PKY5;
  c3_b_PKY6 = chartInstance->c3_PKY6;
  c3_b_PKY7 = chartInstance->c3_PKY7;
  c3_b_PHY1 = chartInstance->c3_PHY1;
  c3_b_PHY2 = chartInstance->c3_PHY2;
  c3_b_PVY1 = chartInstance->c3_PVY1;
  c3_b_PVY2 = chartInstance->c3_PVY2;
  c3_b_PVY3 = chartInstance->c3_PVY3;
  c3_b_PVY4 = chartInstance->c3_PVY4;
  c3_b_PPY1 = chartInstance->c3_PPY1;
  c3_b_PPY2 = chartInstance->c3_PPY2;
  c3_b_PPY3 = chartInstance->c3_PPY3;
  c3_b_PPY4 = chartInstance->c3_PPY4;
  c3_b_PPY5 = chartInstance->c3_PPY5;
  c3_b_RBY1 = chartInstance->c3_RBY1;
  c3_b_RBY2 = chartInstance->c3_RBY2;
  c3_b_RBY3 = chartInstance->c3_RBY3;
  c3_b_RBY4 = chartInstance->c3_RBY4;
  c3_b_RCY1 = chartInstance->c3_RCY1;
  c3_b_REY1 = chartInstance->c3_REY1;
  c3_b_REY2 = chartInstance->c3_REY2;
  c3_b_RHY1 = chartInstance->c3_RHY1;
  c3_b_RHY2 = chartInstance->c3_RHY2;
  c3_b_RVY1 = chartInstance->c3_RVY1;
  c3_b_RVY2 = chartInstance->c3_RVY2;
  c3_b_RVY3 = chartInstance->c3_RVY3;
  c3_b_RVY4 = chartInstance->c3_RVY4;
  c3_b_RVY5 = chartInstance->c3_RVY5;
  c3_b_RVY6 = chartInstance->c3_RVY6;
  c3_b_QSY1 = chartInstance->c3_QSY1;
  c3_b_QSY2 = chartInstance->c3_QSY2;
  c3_b_QSY3 = chartInstance->c3_QSY3;
  c3_b_QSY4 = chartInstance->c3_QSY4;
  c3_b_QSY5 = chartInstance->c3_QSY5;
  c3_b_QSY6 = chartInstance->c3_QSY6;
  c3_b_QSY7 = chartInstance->c3_QSY7;
  c3_b_QSY8 = chartInstance->c3_QSY8;
  c3_b_QBZ1 = chartInstance->c3_QBZ1;
  c3_b_QBZ2 = chartInstance->c3_QBZ2;
  c3_b_QBZ3 = chartInstance->c3_QBZ3;
  c3_b_QBZ4 = chartInstance->c3_QBZ4;
  c3_b_QBZ5 = chartInstance->c3_QBZ5;
  c3_b_QBZ6 = chartInstance->c3_QBZ6;
  c3_b_QBZ9 = chartInstance->c3_QBZ9;
  c3_b_QBZ10 = chartInstance->c3_QBZ10;
  c3_b_QCZ1 = chartInstance->c3_QCZ1;
  c3_b_QDZ1 = chartInstance->c3_QDZ1;
  c3_b_QDZ2 = chartInstance->c3_QDZ2;
  c3_b_QDZ3 = chartInstance->c3_QDZ3;
  c3_b_QDZ4 = chartInstance->c3_QDZ4;
  c3_b_QDZ6 = chartInstance->c3_QDZ6;
  c3_b_QDZ7 = chartInstance->c3_QDZ7;
  c3_b_QDZ8 = chartInstance->c3_QDZ8;
  c3_b_QDZ9 = chartInstance->c3_QDZ9;
  c3_b_QDZ10 = chartInstance->c3_QDZ10;
  c3_b_QDZ11 = chartInstance->c3_QDZ11;
  c3_b_QEZ1 = chartInstance->c3_QEZ1;
  c3_b_QEZ2 = chartInstance->c3_QEZ2;
  c3_b_QEZ3 = chartInstance->c3_QEZ3;
  c3_b_QEZ4 = chartInstance->c3_QEZ4;
  c3_b_QEZ5 = chartInstance->c3_QEZ5;
  c3_b_QHZ1 = chartInstance->c3_QHZ1;
  c3_b_QHZ2 = chartInstance->c3_QHZ2;
  c3_b_QHZ3 = chartInstance->c3_QHZ3;
  c3_b_QHZ4 = chartInstance->c3_QHZ4;
  c3_b_PPZ1 = chartInstance->c3_PPZ1;
  c3_b_PPZ2 = chartInstance->c3_PPZ2;
  c3_b_SSZ1 = chartInstance->c3_SSZ1;
  c3_b_SSZ2 = chartInstance->c3_SSZ2;
  c3_b_SSZ3 = chartInstance->c3_SSZ3;
  c3_b_SSZ4 = chartInstance->c3_SSZ4;
  c3_b_PDXP1 = chartInstance->c3_PDXP1;
  c3_b_PDXP2 = chartInstance->c3_PDXP2;
  c3_b_PDXP3 = chartInstance->c3_PDXP3;
  c3_b_PKYP1 = chartInstance->c3_PKYP1;
  c3_b_PDYP1 = chartInstance->c3_PDYP1;
  c3_b_PDYP2 = chartInstance->c3_PDYP2;
  c3_b_PDYP3 = chartInstance->c3_PDYP3;
  c3_b_PDYP4 = chartInstance->c3_PDYP4;
  c3_b_PHYP1 = chartInstance->c3_PHYP1;
  c3_b_PHYP2 = chartInstance->c3_PHYP2;
  c3_b_PHYP3 = chartInstance->c3_PHYP3;
  c3_b_PHYP4 = chartInstance->c3_PHYP4;
  c3_b_PECP1 = chartInstance->c3_PECP1;
  c3_b_PECP2 = chartInstance->c3_PECP2;
  c3_b_QDTP1 = chartInstance->c3_QDTP1;
  c3_b_QCRP1 = chartInstance->c3_QCRP1;
  c3_b_QCRP2 = chartInstance->c3_QCRP2;
  c3_b_QBRP1 = chartInstance->c3_QBRP1;
  c3_b_QDRP1 = chartInstance->c3_QDRP1;
  c3_b_QDRP2 = chartInstance->c3_QDRP2;
  c3_b_WIDTH = chartInstance->c3_WIDTH;
  c3_b_Q_RA1 = chartInstance->c3_Q_RA1;
  c3_b_Q_RA2 = chartInstance->c3_Q_RA2;
  c3_b_Q_RB1 = chartInstance->c3_Q_RB1;
  c3_b_Q_RB2 = chartInstance->c3_Q_RB2;
  c3_b_QSX12 = chartInstance->c3_QSX12;
  c3_b_QSX13 = chartInstance->c3_QSX13;
  c3_b_QSX14 = chartInstance->c3_QSX14;
  c3_b_Q_FZ3 = chartInstance->c3_Q_FZ3;
  c3_b_LONGITUDINAL_STIFFNESS = chartInstance->c3_LONGITUDINAL_STIFFNESS;
  c3_b_LATERAL_STIFFNESS = chartInstance->c3_LATERAL_STIFFNESS;
  c3_b_PCFX1 = chartInstance->c3_PCFX1;
  c3_b_PCFX2 = chartInstance->c3_PCFX2;
  c3_b_PCFX3 = chartInstance->c3_PCFX3;
  c3_b_PCFY1 = chartInstance->c3_PCFY1;
  c3_b_PCFY2 = chartInstance->c3_PCFY2;
  c3_b_PCFY3 = chartInstance->c3_PCFY3;
  covrtEmlFcnEval(chartInstance->c3_covrtInstance, 4U, 0, 0);
  c3_b_st.site = &c3_emlrtRSI;
  for (c3_i12 = 0; c3_i12 < 4; c3_i12++) {
    c3_dv[c3_i12] = (*chartInstance->c3_Omega)[c3_i12];
  }

  for (c3_i13 = 0; c3_i13 < 4; c3_i13++) {
    c3_dv1[c3_i13] = (*chartInstance->c3_Vx)[c3_i13];
  }

  for (c3_i14 = 0; c3_i14 < 4; c3_i14++) {
    c3_dv2[c3_i14] = (*chartInstance->c3_Vy)[c3_i14];
  }

  for (c3_i15 = 0; c3_i15 < 4; c3_i15++) {
    c3_dv3[c3_i15] = (*chartInstance->c3_psidot)[c3_i15];
  }

  for (c3_i16 = 0; c3_i16 < 108; c3_i16++) {
    c3_dv4[c3_i16] = (*chartInstance->c3_ScaleFactors)[c3_i16];
  }

  for (c3_i17 = 0; c3_i17 < 4; c3_i17++) {
    c3_dv5[c3_i17] = (*chartInstance->c3_rhoz)[c3_i17];
  }

  for (c3_i18 = 0; c3_i18 < 4; c3_i18++) {
    c3_dv6[c3_i18] = (*chartInstance->c3_Fx_ext)[c3_i18];
  }

  for (c3_i19 = 0; c3_i19 < 4; c3_i19++) {
    c3_dv7[c3_i19] = (*chartInstance->c3_Fy_ext)[c3_i19];
  }

  for (c3_i20 = 0; c3_i20 < 279; c3_i20++) {
    c3_dv8[c3_i20] = chartInstance->c3_vdynMF[c3_i20];
  }

  c3_vdyncsmtire(chartInstance, &c3_b_st, c3_dv, c3_dv1, c3_dv2, c3_dv3,
                 c3_b_Gamma, c3_b_TirePrs, c3_dv4, c3_dv5, c3_b_turnslip,
                 c3_b_PRESMAX, c3_b_PRESMIN, c3_b_FZMAX, c3_b_FZMIN, c3_b_VXLOW,
                 c3_b_KPUMAX, c3_b_KPUMIN, c3_b_ALPMAX, c3_b_ALPMIN, c3_b_CAMMIN,
                 c3_b_CAMMAX, c3_b_LONGVL, c3_b_UNLOADED_RADIUS, c3_b_RIM_RADIUS,
                 c3_b_NOMPRES, c3_b_FNOMIN, c3_b_VERTICAL_STIFFNESS, c3_b_DREFF,
                 c3_b_BREFF, c3_b_FREFF, c3_b_Q_RE0, c3_b_Q_V1, c3_b_Q_V2,
                 c3_b_Q_FZ1, c3_b_Q_FZ2, c3_b_Q_FCX, c3_b_Q_FCY, c3_b_PFZ1,
                 c3_b_Q_FCY2, c3_b_BOTTOM_OFFST, c3_b_BOTTOM_STIFF, c3_b_PCX1,
                 c3_b_PDX1, c3_b_PDX2, c3_b_PDX3, c3_b_PEX1, c3_b_PEX2,
                 c3_b_PEX3, c3_b_PEX4, c3_b_PKX1, c3_b_PKX2, c3_b_PKX3,
                 c3_b_PHX1, c3_b_PHX2, c3_b_PVX1, c3_b_PVX2, c3_b_PPX1,
                 c3_b_PPX2, c3_b_PPX3, c3_b_PPX4, c3_b_RBX1, c3_b_RBX2,
                 c3_b_RBX3, c3_b_RCX1, c3_b_REX1, c3_b_REX2, c3_b_RHX1,
                 c3_b_QSX1, c3_b_QSX2, c3_b_QSX3, c3_b_QSX4, c3_b_QSX5,
                 c3_b_QSX6, c3_b_QSX7, c3_b_QSX8, c3_b_QSX9, c3_b_QSX10,
                 c3_b_QSX11, c3_b_PPMX1, c3_b_PCY1, c3_b_PDY1, c3_b_PDY2,
                 c3_b_PDY3, c3_b_PEY1, c3_b_PEY2, c3_b_PEY3, c3_b_PEY4,
                 c3_b_PEY5, c3_b_PKY1, c3_b_PKY2, c3_b_PKY3, c3_b_PKY4,
                 c3_b_PKY5, c3_b_PKY6, c3_b_PKY7, c3_b_PHY1, c3_b_PHY2,
                 c3_b_PVY1, c3_b_PVY2, c3_b_PVY3, c3_b_PVY4, c3_b_PPY1,
                 c3_b_PPY2, c3_b_PPY3, c3_b_PPY4, c3_b_PPY5, c3_b_RBY1,
                 c3_b_RBY2, c3_b_RBY3, c3_b_RBY4, c3_b_RCY1, c3_b_REY1,
                 c3_b_REY2, c3_b_RHY1, c3_b_RHY2, c3_b_RVY1, c3_b_RVY2,
                 c3_b_RVY3, c3_b_RVY4, c3_b_RVY5, c3_b_RVY6, c3_b_QSY1,
                 c3_b_QSY2, c3_b_QSY3, c3_b_QSY4, c3_b_QSY5, c3_b_QSY6,
                 c3_b_QSY7, c3_b_QSY8, c3_b_QBZ1, c3_b_QBZ2, c3_b_QBZ3,
                 c3_b_QBZ4, c3_b_QBZ5, c3_b_QBZ6, c3_b_QBZ9, c3_b_QBZ10,
                 c3_b_QCZ1, c3_b_QDZ1, c3_b_QDZ2, c3_b_QDZ3, c3_b_QDZ4,
                 c3_b_QDZ6, c3_b_QDZ7, c3_b_QDZ8, c3_b_QDZ9, c3_b_QDZ10,
                 c3_b_QDZ11, c3_b_QEZ1, c3_b_QEZ2, c3_b_QEZ3, c3_b_QEZ4,
                 c3_b_QEZ5, c3_b_QHZ1, c3_b_QHZ2, c3_b_QHZ3, c3_b_QHZ4,
                 c3_b_PPZ1, c3_b_PPZ2, c3_b_SSZ1, c3_b_SSZ2, c3_b_SSZ3,
                 c3_b_SSZ4, c3_b_PDXP1, c3_b_PDXP2, c3_b_PDXP3, c3_b_PKYP1,
                 c3_b_PDYP1, c3_b_PDYP2, c3_b_PDYP3, c3_b_PDYP4, c3_b_PHYP1,
                 c3_b_PHYP2, c3_b_PHYP3, c3_b_PHYP4, c3_b_PECP1, c3_b_PECP2,
                 c3_b_QDTP1, c3_b_QCRP1, c3_b_QCRP2, c3_b_QBRP1, c3_b_QDRP1,
                 c3_b_QDRP2, c3_b_WIDTH, c3_b_Q_RA1, c3_b_Q_RA2, c3_b_Q_RB1,
                 c3_b_Q_RB2, c3_b_QSX12, c3_b_QSX13, c3_b_QSX14, c3_b_Q_FZ3,
                 c3_b_LONGITUDINAL_STIFFNESS, c3_b_LATERAL_STIFFNESS, c3_b_PCFX1,
                 c3_b_PCFX2, c3_b_PCFX3, c3_b_PCFY1, c3_b_PCFY2, c3_b_PCFY3,
                 c3_dv6, c3_dv7, c3_dv8, c3_b_Fx, c3_b_Fy, c3_b_FzTire, c3_b_Mx,
                 c3_b_My, c3_b_Mz, c3_b_Re, c3_b_Kappa, c3_b_Alpha, c3_b_sig_x,
                 c3_b_sig_y, c3_b_a, c3_b_b);
  for (c3_i21 = 0; c3_i21 < 4; c3_i21++) {
    (*chartInstance->c3_Fx)[c3_i21] = c3_b_Fx[c3_i21];
  }

  for (c3_i22 = 0; c3_i22 < 4; c3_i22++) {
    (*chartInstance->c3_Fy)[c3_i22] = c3_b_Fy[c3_i22];
  }

  for (c3_i23 = 0; c3_i23 < 4; c3_i23++) {
    (*chartInstance->c3_FzTire)[c3_i23] = c3_b_FzTire[c3_i23];
  }

  for (c3_i24 = 0; c3_i24 < 4; c3_i24++) {
    (*chartInstance->c3_Mx)[c3_i24] = c3_b_Mx[c3_i24];
  }

  for (c3_i25 = 0; c3_i25 < 4; c3_i25++) {
    (*chartInstance->c3_My)[c3_i25] = c3_b_My[c3_i25];
  }

  for (c3_i26 = 0; c3_i26 < 4; c3_i26++) {
    (*chartInstance->c3_Mz)[c3_i26] = c3_b_Mz[c3_i26];
  }

  for (c3_i27 = 0; c3_i27 < 4; c3_i27++) {
    (*chartInstance->c3_Re)[c3_i27] = c3_b_Re[c3_i27];
  }

  for (c3_i28 = 0; c3_i28 < 4; c3_i28++) {
    (*chartInstance->c3_Kappa)[c3_i28] = c3_b_Kappa[c3_i28];
  }

  for (c3_i29 = 0; c3_i29 < 4; c3_i29++) {
    (*chartInstance->c3_Alpha)[c3_i29] = c3_b_Alpha[c3_i29];
  }

  for (c3_i30 = 0; c3_i30 < 4; c3_i30++) {
    (*chartInstance->c3_sig_x)[c3_i30] = c3_b_sig_x[c3_i30];
  }

  for (c3_i31 = 0; c3_i31 < 4; c3_i31++) {
    (*chartInstance->c3_sig_y)[c3_i31] = c3_b_sig_y[c3_i31];
  }

  for (c3_i32 = 0; c3_i32 < 4; c3_i32++) {
    (*chartInstance->c3_a)[c3_i32] = c3_b_a[c3_i32];
  }

  for (c3_i33 = 0; c3_i33 < 4; c3_i33++) {
    (*chartInstance->c3_b)[c3_i33] = c3_b_b[c3_i33];
  }

  c3_do_animation_call_c3_vehdynlibtirecommon(chartInstance);
  for (c3_i34 = 0; c3_i34 < 4; c3_i34++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 10U,
                      (*chartInstance->c3_Fx)[c3_i34]);
  }

  for (c3_i35 = 0; c3_i35 < 4; c3_i35++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 11U,
                      (*chartInstance->c3_Fy)[c3_i35]);
  }

  for (c3_i36 = 0; c3_i36 < 4; c3_i36++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 12U,
                      (*chartInstance->c3_FzTire)[c3_i36]);
  }

  for (c3_i37 = 0; c3_i37 < 4; c3_i37++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 13U,
                      (*chartInstance->c3_Mx)[c3_i37]);
  }

  for (c3_i38 = 0; c3_i38 < 4; c3_i38++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 14U,
                      (*chartInstance->c3_My)[c3_i38]);
  }

  for (c3_i39 = 0; c3_i39 < 4; c3_i39++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 15U,
                      (*chartInstance->c3_Mz)[c3_i39]);
  }

  for (c3_i40 = 0; c3_i40 < 4; c3_i40++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 16U,
                      (*chartInstance->c3_Re)[c3_i40]);
  }

  for (c3_i41 = 0; c3_i41 < 4; c3_i41++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 17U,
                      (*chartInstance->c3_Kappa)[c3_i41]);
  }

  for (c3_i42 = 0; c3_i42 < 4; c3_i42++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 18U,
                      (*chartInstance->c3_Alpha)[c3_i42]);
  }

  for (c3_i43 = 0; c3_i43 < 4; c3_i43++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 19U,
                      (*chartInstance->c3_sig_x)[c3_i43]);
  }

  for (c3_i44 = 0; c3_i44 < 4; c3_i44++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 20U,
                      (*chartInstance->c3_sig_y)[c3_i44]);
  }

  for (c3_i45 = 0; c3_i45 < 4; c3_i45++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 21U,
                      (*chartInstance->c3_a)[c3_i45]);
  }

  for (c3_i46 = 0; c3_i46 < 4; c3_i46++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 22U,
                      (*chartInstance->c3_b)[c3_i46]);
  }
}

static void ext_mode_exec_c3_vehdynlibtirecommon
  (SFc3_vehdynlibtirecommonInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_update_jit_animation_c3_vehdynlibtirecommon
  (SFc3_vehdynlibtirecommonInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_do_animation_call_c3_vehdynlibtirecommon
  (SFc3_vehdynlibtirecommonInstanceStruct *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static const mxArray *get_sim_state_c3_vehdynlibtirecommon
  (SFc3_vehdynlibtirecommonInstanceStruct *chartInstance)
{
  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_d_y = NULL;
  const mxArray *c3_e_y = NULL;
  const mxArray *c3_f_y = NULL;
  const mxArray *c3_g_y = NULL;
  const mxArray *c3_h_y = NULL;
  const mxArray *c3_i_y = NULL;
  const mxArray *c3_j_y = NULL;
  const mxArray *c3_k_y = NULL;
  const mxArray *c3_l_y = NULL;
  const mxArray *c3_m_y = NULL;
  const mxArray *c3_n_y = NULL;
  const mxArray *c3_o_y = NULL;
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(14, 1), false);
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", *chartInstance->c3_Alpha, 0, 0U, 1U,
    0U, 1, 4), false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", *chartInstance->c3_Fx, 0, 0U, 1U, 0U,
    1, 4), false);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", *chartInstance->c3_Fy, 0, 0U, 1U, 0U,
    1, 4), false);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", *chartInstance->c3_FzTire, 0, 0U, 1U,
    0U, 1, 4), false);
  sf_mex_setcell(c3_y, 3, c3_e_y);
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", *chartInstance->c3_Kappa, 0, 0U, 1U,
    0U, 1, 4), false);
  sf_mex_setcell(c3_y, 4, c3_f_y);
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", *chartInstance->c3_Mx, 0, 0U, 1U, 0U,
    1, 4), false);
  sf_mex_setcell(c3_y, 5, c3_g_y);
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", *chartInstance->c3_My, 0, 0U, 1U, 0U,
    1, 4), false);
  sf_mex_setcell(c3_y, 6, c3_h_y);
  c3_i_y = NULL;
  sf_mex_assign(&c3_i_y, sf_mex_create("y", *chartInstance->c3_Mz, 0, 0U, 1U, 0U,
    1, 4), false);
  sf_mex_setcell(c3_y, 7, c3_i_y);
  c3_j_y = NULL;
  sf_mex_assign(&c3_j_y, sf_mex_create("y", *chartInstance->c3_Re, 0, 0U, 1U, 0U,
    1, 4), false);
  sf_mex_setcell(c3_y, 8, c3_j_y);
  c3_k_y = NULL;
  sf_mex_assign(&c3_k_y, sf_mex_create("y", *chartInstance->c3_a, 0, 0U, 1U, 0U,
    1, 4), false);
  sf_mex_setcell(c3_y, 9, c3_k_y);
  c3_l_y = NULL;
  sf_mex_assign(&c3_l_y, sf_mex_create("y", *chartInstance->c3_b, 0, 0U, 1U, 0U,
    1, 4), false);
  sf_mex_setcell(c3_y, 10, c3_l_y);
  c3_m_y = NULL;
  sf_mex_assign(&c3_m_y, sf_mex_create("y", *chartInstance->c3_sig_x, 0, 0U, 1U,
    0U, 1, 4), false);
  sf_mex_setcell(c3_y, 11, c3_m_y);
  c3_n_y = NULL;
  sf_mex_assign(&c3_n_y, sf_mex_create("y", *chartInstance->c3_sig_y, 0, 0U, 1U,
    0U, 1, 4), false);
  sf_mex_setcell(c3_y, 12, c3_n_y);
  c3_o_y = NULL;
  sf_mex_assign(&c3_o_y, sf_mex_create("y",
    &chartInstance->c3_is_active_c3_vehdynlibtirecommon, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c3_y, 13, c3_o_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_vehdynlibtirecommon
  (SFc3_vehdynlibtirecommonInstanceStruct *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T c3_dv[4];
  real_T c3_dv1[4];
  real_T c3_dv10[4];
  real_T c3_dv11[4];
  real_T c3_dv12[4];
  real_T c3_dv2[4];
  real_T c3_dv3[4];
  real_T c3_dv4[4];
  real_T c3_dv5[4];
  real_T c3_dv6[4];
  real_T c3_dv7[4];
  real_T c3_dv8[4];
  real_T c3_dv9[4];
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i10;
  int32_T c3_i11;
  int32_T c3_i12;
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_i4;
  int32_T c3_i5;
  int32_T c3_i6;
  int32_T c3_i7;
  int32_T c3_i8;
  int32_T c3_i9;
  chartInstance->c3_doneDoubleBufferReInit = true;
  c3_u = sf_mex_dup(c3_st);
  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 0)),
                      "Alpha", c3_dv);
  for (c3_i = 0; c3_i < 4; c3_i++) {
    (*chartInstance->c3_Alpha)[c3_i] = c3_dv[c3_i];
  }

  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)), "Fx",
                      c3_dv1);
  for (c3_i1 = 0; c3_i1 < 4; c3_i1++) {
    (*chartInstance->c3_Fx)[c3_i1] = c3_dv1[c3_i1];
  }

  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 2)), "Fy",
                      c3_dv2);
  for (c3_i2 = 0; c3_i2 < 4; c3_i2++) {
    (*chartInstance->c3_Fy)[c3_i2] = c3_dv2[c3_i2];
  }

  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 3)),
                      "FzTire", c3_dv3);
  for (c3_i3 = 0; c3_i3 < 4; c3_i3++) {
    (*chartInstance->c3_FzTire)[c3_i3] = c3_dv3[c3_i3];
  }

  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 4)),
                      "Kappa", c3_dv4);
  for (c3_i4 = 0; c3_i4 < 4; c3_i4++) {
    (*chartInstance->c3_Kappa)[c3_i4] = c3_dv4[c3_i4];
  }

  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 5)), "Mx",
                      c3_dv5);
  for (c3_i5 = 0; c3_i5 < 4; c3_i5++) {
    (*chartInstance->c3_Mx)[c3_i5] = c3_dv5[c3_i5];
  }

  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 6)), "My",
                      c3_dv6);
  for (c3_i6 = 0; c3_i6 < 4; c3_i6++) {
    (*chartInstance->c3_My)[c3_i6] = c3_dv6[c3_i6];
  }

  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 7)), "Mz",
                      c3_dv7);
  for (c3_i7 = 0; c3_i7 < 4; c3_i7++) {
    (*chartInstance->c3_Mz)[c3_i7] = c3_dv7[c3_i7];
  }

  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 8)), "Re",
                      c3_dv8);
  for (c3_i8 = 0; c3_i8 < 4; c3_i8++) {
    (*chartInstance->c3_Re)[c3_i8] = c3_dv8[c3_i8];
  }

  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 9)), "a",
                      c3_dv9);
  for (c3_i9 = 0; c3_i9 < 4; c3_i9++) {
    (*chartInstance->c3_a)[c3_i9] = c3_dv9[c3_i9];
  }

  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 10)), "b",
                      c3_dv10);
  for (c3_i10 = 0; c3_i10 < 4; c3_i10++) {
    (*chartInstance->c3_b)[c3_i10] = c3_dv10[c3_i10];
  }

  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 11)),
                      "sig_x", c3_dv11);
  for (c3_i11 = 0; c3_i11 < 4; c3_i11++) {
    (*chartInstance->c3_sig_x)[c3_i11] = c3_dv11[c3_i11];
  }

  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 12)),
                      "sig_y", c3_dv12);
  for (c3_i12 = 0; c3_i12 < 4; c3_i12++) {
    (*chartInstance->c3_sig_y)[c3_i12] = c3_dv12[c3_i12];
  }

  chartInstance->c3_is_active_c3_vehdynlibtirecommon = c3_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 13)),
     "is_active_c3_vehdynlibtirecommon");
  sf_mex_destroy(&c3_u);
  sf_mex_destroy(&c3_st);
}

static void initSimStructsc3_vehdynlibtirecommon
  (SFc3_vehdynlibtirecommonInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

const mxArray *sf_c3_vehdynlibtirecommon_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c3_nameCaptureInfo;
}

static void c3_vdyncsmtire(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, real_T c3_b_Omega[4], real_T c3_b_Vx[4], real_T
  c3_b_Vy[4], real_T c3_b_psidot[4], real_T c3_gamma[4], real_T c3_press[4],
  real_T c3_scaleFactors[108], real_T c3_b_rhoz[4], real_T c3_b_turnslip, real_T
  c3_b_PRESMAX, real_T c3_b_PRESMIN, real_T c3_b_FZMAX, real_T c3_b_FZMIN,
  real_T c3_b_VXLOW, real_T c3_b_KPUMAX, real_T c3_b_KPUMIN, real_T c3_b_ALPMAX,
  real_T c3_b_ALPMIN, real_T c3_b_CAMMIN, real_T c3_b_CAMMAX, real_T c3_b_LONGVL,
  real_T c3_b_UNLOADED_RADIUS, real_T c3_b_RIM_RADIUS, real_T c3_b_NOMPRES,
  real_T c3_b_FNOMIN, real_T c3_b_VERTICAL_STIFFNESS, real_T c3_b_DREFF, real_T
  c3_b_BREFF, real_T c3_b_FREFF, real_T c3_b_Q_RE0, real_T c3_b_Q_V1, real_T
  c3_b_Q_V2, real_T c3_b_Q_FZ1, real_T c3_b_Q_FZ2, real_T c3_b_Q_FCX, real_T
  c3_b_Q_FCY, real_T c3_b_PFZ1, real_T c3_b_Q_FCY2, real_T c3_b_BOTTOM_OFFST,
  real_T c3_b_BOTTOM_STIFF, real_T c3_b_PCX1, real_T c3_b_PDX1, real_T c3_b_PDX2,
  real_T c3_b_PDX3, real_T c3_b_PEX1, real_T c3_b_PEX2, real_T c3_b_PEX3, real_T
  c3_b_PEX4, real_T c3_b_PKX1, real_T c3_b_PKX2, real_T c3_b_PKX3, real_T
  c3_b_PHX1, real_T c3_b_PHX2, real_T c3_b_PVX1, real_T c3_b_PVX2, real_T
  c3_b_PPX1, real_T c3_b_PPX2, real_T c3_b_PPX3, real_T c3_b_PPX4, real_T
  c3_b_RBX1, real_T c3_b_RBX2, real_T c3_b_RBX3, real_T c3_b_RCX1, real_T
  c3_b_REX1, real_T c3_b_REX2, real_T c3_b_RHX1, real_T c3_b_QSX1, real_T
  c3_b_QSX2, real_T c3_b_QSX3, real_T c3_b_QSX4, real_T c3_b_QSX5, real_T
  c3_b_QSX6, real_T c3_b_QSX7, real_T c3_b_QSX8, real_T c3_b_QSX9, real_T
  c3_b_QSX10, real_T c3_b_QSX11, real_T c3_b_PPMX1, real_T c3_b_PCY1, real_T
  c3_b_PDY1, real_T c3_b_PDY2, real_T c3_b_PDY3, real_T c3_b_PEY1, real_T
  c3_b_PEY2, real_T c3_b_PEY3, real_T c3_b_PEY4, real_T c3_b_PEY5, real_T
  c3_b_PKY1, real_T c3_b_PKY2, real_T c3_b_PKY3, real_T c3_b_PKY4, real_T
  c3_b_PKY5, real_T c3_b_PKY6, real_T c3_b_PKY7, real_T c3_b_PHY1, real_T
  c3_b_PHY2, real_T c3_b_PVY1, real_T c3_b_PVY2, real_T c3_b_PVY3, real_T
  c3_b_PVY4, real_T c3_b_PPY1, real_T c3_b_PPY2, real_T c3_b_PPY3, real_T
  c3_b_PPY4, real_T c3_b_PPY5, real_T c3_b_RBY1, real_T c3_b_RBY2, real_T
  c3_b_RBY3, real_T c3_b_RBY4, real_T c3_b_RCY1, real_T c3_b_REY1, real_T
  c3_b_REY2, real_T c3_b_RHY1, real_T c3_b_RHY2, real_T c3_b_RVY1, real_T
  c3_b_RVY2, real_T c3_b_RVY3, real_T c3_b_RVY4, real_T c3_b_RVY5, real_T
  c3_b_RVY6, real_T c3_b_QSY1, real_T c3_b_QSY2, real_T c3_b_QSY3, real_T
  c3_b_QSY4, real_T c3_b_QSY5, real_T c3_b_QSY6, real_T c3_b_QSY7, real_T
  c3_b_QSY8, real_T c3_b_QBZ1, real_T c3_b_QBZ2, real_T c3_b_QBZ3, real_T
  c3_b_QBZ4, real_T c3_b_QBZ5, real_T c3_b_QBZ6, real_T c3_b_QBZ9, real_T
  c3_b_QBZ10, real_T c3_b_QCZ1, real_T c3_b_QDZ1, real_T c3_b_QDZ2, real_T
  c3_b_QDZ3, real_T c3_b_QDZ4, real_T c3_b_QDZ6, real_T c3_b_QDZ7, real_T
  c3_b_QDZ8, real_T c3_b_QDZ9, real_T c3_b_QDZ10, real_T c3_b_QDZ11, real_T
  c3_b_QEZ1, real_T c3_b_QEZ2, real_T c3_b_QEZ3, real_T c3_b_QEZ4, real_T
  c3_b_QEZ5, real_T c3_b_QHZ1, real_T c3_b_QHZ2, real_T c3_b_QHZ3, real_T
  c3_b_QHZ4, real_T c3_b_PPZ1, real_T c3_b_PPZ2, real_T c3_b_SSZ1, real_T
  c3_b_SSZ2, real_T c3_b_SSZ3, real_T c3_b_SSZ4, real_T c3_b_PDXP1, real_T
  c3_b_PDXP2, real_T c3_b_PDXP3, real_T c3_b_PKYP1, real_T c3_b_PDYP1, real_T
  c3_b_PDYP2, real_T c3_b_PDYP3, real_T c3_b_PDYP4, real_T c3_b_PHYP1, real_T
  c3_b_PHYP2, real_T c3_b_PHYP3, real_T c3_b_PHYP4, real_T c3_b_PECP1, real_T
  c3_b_PECP2, real_T c3_b_QDTP1, real_T c3_b_QCRP1, real_T c3_b_QCRP2, real_T
  c3_b_QBRP1, real_T c3_b_QDRP1, real_T c3_b_QDRP2, real_T c3_b_WIDTH, real_T
  c3_b_Q_RA1, real_T c3_b_Q_RA2, real_T c3_b_Q_RB1, real_T c3_b_Q_RB2, real_T
  c3_b_QSX12, real_T c3_b_QSX13, real_T c3_b_QSX14, real_T c3_b_Q_FZ3, real_T
  c3_b_LONGITUDINAL_STIFFNESS, real_T c3_b_LATERAL_STIFFNESS, real_T c3_b_PCFX1,
  real_T c3_b_PCFX2, real_T c3_b_PCFX3, real_T c3_b_PCFY1, real_T c3_b_PCFY2,
  real_T c3_b_PCFY3, real_T c3_b_Fx_ext[4], real_T c3_b_Fy_ext[4], real_T
  c3_b_vdynMF[279], real_T c3_b_Fx[4], real_T c3_b_Fy[4], real_T c3_Fz[4],
  real_T c3_b_Mx[4], real_T c3_b_My[4], real_T c3_b_Mz[4], real_T c3_b_Re[4],
  real_T c3_kappa[4], real_T c3_alpha[4], real_T c3_b_sig_x[4], real_T
  c3_b_sig_y[4], real_T c3_patch_a[4], real_T c3_patch_b[4])
{
  emlrtStack c3_b_st;
  emlrtStack c3_c_st;
  emlrtStack c3_st;
  real_T c3_zeta[36];
  real_T c3_Bykappa[4];
  real_T c3_FzUnSat[4];
  real_T c3_Fz_btm[4];
  real_T c3_Fzo_prime[4];
  real_T c3_Kyalpha[4];
  real_T c3_Kyalpha_prime[4];
  real_T c3_SHy[4];
  real_T c3_SHyphi[4];
  real_T c3_SVygamma[4];
  real_T c3_Vc_prime[4];
  real_T c3_Vc_prime_data[4];
  real_T c3_Vs[4];
  real_T c3_Vsy[4];
  real_T c3_Vx_data[4];
  real_T c3_ab_tmp_data[4];
  real_T c3_b_Bykappa[4];
  real_T c3_b_FzUnSat[4];
  real_T c3_b_Vc_prime_data[4];
  real_T c3_b_Vsy[4];
  real_T c3_b_gamma[4];
  real_T c3_b_press[4];
  real_T c3_c_UNLOADED_RADIUS[4];
  real_T c3_c_Vc_prime_data[4];
  real_T c3_cosprimealpha[4];
  real_T c3_d_tmp_data[4];
  real_T c3_dfz[4];
  real_T c3_dpi[4];
  real_T c3_e_UNLOADED_RADIUS[4];
  real_T c3_e_y[4];
  real_T c3_epsilon_gamma[4];
  real_T c3_f_x[4];
  real_T c3_gamma_star[4];
  real_T c3_hb_tmp_data[4];
  real_T c3_lam_Cx[4];
  real_T c3_lam_Cy[4];
  real_T c3_lam_Cz[4];
  real_T c3_lam_Cz_data[4];
  real_T c3_lam_Ex[4];
  real_T c3_lam_Ey[4];
  real_T c3_lam_Fzo[4];
  real_T c3_lam_Hx[4];
  real_T c3_lam_Hy[4];
  real_T c3_lam_Kxkappa[4];
  real_T c3_lam_Kyalpha[4];
  real_T c3_lam_Kygamma[4];
  real_T c3_lam_Kzgamma[4];
  real_T c3_lam_Mphi[4];
  real_T c3_lam_Mr[4];
  real_T c3_lam_My[4];
  real_T c3_lam_VMx[4];
  real_T c3_lam_Vx[4];
  real_T c3_lam_Vy[4];
  real_T c3_lam_Vykappa[4];
  real_T c3_lam_muV[4];
  real_T c3_lam_mux[4];
  real_T c3_lam_mux_prime[4];
  real_T c3_lam_muy[4];
  real_T c3_lam_muy_prime[4];
  real_T c3_lam_s[4];
  real_T c3_lam_t[4];
  real_T c3_lam_xalpha[4];
  real_T c3_lam_ykappa[4];
  real_T c3_mu_x[4];
  real_T c3_mu_y[4];
  real_T c3_phi_t[4];
  real_T c3_rhoz_data[4];
  real_T c3_tmpDrphiVar_data[4];
  real_T c3_y_data[4];
  real_T c3_b_y_data[1];
  real_T c3_c_tmp_data[1];
  real_T c3_dv[1];
  real_T c3_dv1[1];
  real_T c3_dv2[1];
  real_T c3_dv3[1];
  real_T c3_dv4[1];
  real_T c3_dv5[1];
  real_T c3_dv6[1];
  real_T c3_x_data[1];
  real_T c3_CDrphi;
  real_T c3_CHyphi;
  real_T c3_Ct;
  real_T c3_EDrphi;
  real_T c3_EHyphi;
  real_T c3_ab_a;
  real_T c3_ab_x;
  real_T c3_ab_y;
  real_T c3_ac_x;
  real_T c3_ac_y;
  real_T c3_ad_x;
  real_T c3_ae_x;
  real_T c3_b_a;
  real_T c3_b_y;
  real_T c3_bb_a;
  real_T c3_bb_x;
  real_T c3_bb_y;
  real_T c3_bc_x;
  real_T c3_bc_y;
  real_T c3_bd_x;
  real_T c3_be_x;
  real_T c3_c_PKYP1;
  real_T c3_c_QBRP1;
  real_T c3_c_QCRP2;
  real_T c3_c_QDTP1;
  real_T c3_c_RIM_RADIUS;
  real_T c3_c_a;
  real_T c3_c_x;
  real_T c3_c_y;
  real_T c3_cb_a;
  real_T c3_cb_x;
  real_T c3_cb_y;
  real_T c3_cc_x;
  real_T c3_cc_y;
  real_T c3_cd_x;
  real_T c3_ce_x;
  real_T c3_d;
  real_T c3_d_UNLOADED_RADIUS;
  real_T c3_d_a;
  real_T c3_d_x;
  real_T c3_d_y;
  real_T c3_db_a;
  real_T c3_db_x;
  real_T c3_db_y;
  real_T c3_dc_x;
  real_T c3_dd_x;
  real_T c3_de_x;
  real_T c3_e_a;
  real_T c3_e_x;
  real_T c3_eb_a;
  real_T c3_eb_x;
  real_T c3_eb_y;
  real_T c3_ec_x;
  real_T c3_ed_x;
  real_T c3_ee_x;
  real_T c3_ex;
  real_T c3_f_a;
  real_T c3_f_y;
  real_T c3_fb_a;
  real_T c3_fb_x;
  real_T c3_fb_y;
  real_T c3_fc_x;
  real_T c3_fd_x;
  real_T c3_fe_x;
  real_T c3_g_a;
  real_T c3_g_x;
  real_T c3_g_y;
  real_T c3_gb_a;
  real_T c3_gb_x;
  real_T c3_gb_y;
  real_T c3_gc_x;
  real_T c3_gd_x;
  real_T c3_ge_x;
  real_T c3_h_a;
  real_T c3_h_x;
  real_T c3_h_y;
  real_T c3_hb_a;
  real_T c3_hb_x;
  real_T c3_hb_y;
  real_T c3_hc_x;
  real_T c3_hd_x;
  real_T c3_he_x;
  real_T c3_i_a;
  real_T c3_i_x;
  real_T c3_i_y;
  real_T c3_ib_a;
  real_T c3_ib_x;
  real_T c3_ib_y;
  real_T c3_ic_x;
  real_T c3_id_x;
  real_T c3_ie_x;
  real_T c3_j_a;
  real_T c3_j_x;
  real_T c3_j_y;
  real_T c3_jb_a;
  real_T c3_jb_x;
  real_T c3_jb_y;
  real_T c3_jc_x;
  real_T c3_jd_x;
  real_T c3_je_x;
  real_T c3_k_a;
  real_T c3_k_x;
  real_T c3_k_y;
  real_T c3_kb_a;
  real_T c3_kb_x;
  real_T c3_kb_y;
  real_T c3_kc_x;
  real_T c3_kd_x;
  real_T c3_ke_x;
  real_T c3_l_a;
  real_T c3_l_x;
  real_T c3_l_y;
  real_T c3_lb_a;
  real_T c3_lb_x;
  real_T c3_lb_y;
  real_T c3_lc_x;
  real_T c3_ld_x;
  real_T c3_le_x;
  real_T c3_m_a;
  real_T c3_m_x;
  real_T c3_m_y;
  real_T c3_mb_a;
  real_T c3_mb_x;
  real_T c3_mb_y;
  real_T c3_mc_x;
  real_T c3_md_x;
  real_T c3_me_x;
  real_T c3_n_a;
  real_T c3_n_x;
  real_T c3_n_y;
  real_T c3_nb_a;
  real_T c3_nb_x;
  real_T c3_nb_y;
  real_T c3_nc_x;
  real_T c3_nd_x;
  real_T c3_ne_x;
  real_T c3_o_a;
  real_T c3_o_x;
  real_T c3_o_y;
  real_T c3_ob_a;
  real_T c3_ob_x;
  real_T c3_ob_y;
  real_T c3_oc_x;
  real_T c3_od_x;
  real_T c3_p_a;
  real_T c3_p_x;
  real_T c3_p_y;
  real_T c3_pb_a;
  real_T c3_pb_x;
  real_T c3_pb_y;
  real_T c3_pc_x;
  real_T c3_pd_x;
  real_T c3_q_a;
  real_T c3_q_x;
  real_T c3_q_y;
  real_T c3_qb_a;
  real_T c3_qb_x;
  real_T c3_qb_y;
  real_T c3_qc_x;
  real_T c3_qd_x;
  real_T c3_r;
  real_T c3_r_a;
  real_T c3_r_x;
  real_T c3_r_y;
  real_T c3_rb_a;
  real_T c3_rb_x;
  real_T c3_rb_y;
  real_T c3_rc_x;
  real_T c3_rd_x;
  real_T c3_s_a;
  real_T c3_s_x;
  real_T c3_s_y;
  real_T c3_sb_x;
  real_T c3_sb_y;
  real_T c3_sc_x;
  real_T c3_sd_x;
  real_T c3_t_a;
  real_T c3_t_x;
  real_T c3_t_y;
  real_T c3_tb_x;
  real_T c3_tb_y;
  real_T c3_tc_x;
  real_T c3_td_x;
  real_T c3_u_a;
  real_T c3_u_x;
  real_T c3_u_y;
  real_T c3_ub_x;
  real_T c3_ub_y;
  real_T c3_uc_x;
  real_T c3_ud_x;
  real_T c3_v_a;
  real_T c3_v_x;
  real_T c3_v_y;
  real_T c3_vb_x;
  real_T c3_vb_y;
  real_T c3_vc_x;
  real_T c3_vd_x;
  real_T c3_w_a;
  real_T c3_w_x;
  real_T c3_w_y;
  real_T c3_wb_x;
  real_T c3_wb_y;
  real_T c3_wc_x;
  real_T c3_wd_x;
  real_T c3_x_a;
  real_T c3_x_x;
  real_T c3_x_y;
  real_T c3_xb_x;
  real_T c3_xb_y;
  real_T c3_xc_x;
  real_T c3_xd_x;
  real_T c3_y_a;
  real_T c3_y_x;
  real_T c3_y_y;
  real_T c3_yb_x;
  real_T c3_yb_y;
  real_T c3_yc_x;
  real_T c3_yd_x;
  int32_T c3_b_tmp_data[4];
  int32_T c3_bb_tmp_data[4];
  int32_T c3_cb_tmp_data[4];
  int32_T c3_db_tmp_data[4];
  int32_T c3_e_tmp_data[4];
  int32_T c3_eb_tmp_data[4];
  int32_T c3_f_tmp_data[4];
  int32_T c3_fb_tmp_data[4];
  int32_T c3_g_tmp_data[4];
  int32_T c3_gb_tmp_data[4];
  int32_T c3_h_tmp_data[4];
  int32_T c3_i_tmp_data[4];
  int32_T c3_ib_tmp_data[4];
  int32_T c3_j_tmp_data[4];
  int32_T c3_jb_tmp_data[4];
  int32_T c3_k_tmp_data[4];
  int32_T c3_l_tmp_data[4];
  int32_T c3_m_tmp_data[4];
  int32_T c3_n_tmp_data[4];
  int32_T c3_o_tmp_data[4];
  int32_T c3_p_tmp_data[4];
  int32_T c3_q_tmp_data[4];
  int32_T c3_r_tmp_data[4];
  int32_T c3_s_tmp_data[4];
  int32_T c3_t_tmp_data[4];
  int32_T c3_u_tmp_data[4];
  int32_T c3_v_tmp_data[4];
  int32_T c3_w_tmp_data[4];
  int32_T c3_x_tmp_data[4];
  int32_T c3_y_tmp_data[4];
  int32_T c3_b_y_size[2];
  int32_T c3_c_tmp_size[2];
  int32_T c3_iv[2];
  int32_T c3_iv1[2];
  int32_T c3_iv10[2];
  int32_T c3_iv11[2];
  int32_T c3_iv12[2];
  int32_T c3_iv13[2];
  int32_T c3_iv14[2];
  int32_T c3_iv15[2];
  int32_T c3_iv16[2];
  int32_T c3_iv2[2];
  int32_T c3_iv3[2];
  int32_T c3_iv4[2];
  int32_T c3_iv5[2];
  int32_T c3_iv6[2];
  int32_T c3_iv7[2];
  int32_T c3_iv8[2];
  int32_T c3_iv9[2];
  int32_T c3_tmp_size[2];
  int32_T c3_x_size[2];
  int32_T c3_Vc_prime_size[1];
  int32_T c3_Vx_size[1];
  int32_T c3_ab_tmp_size[1];
  int32_T c3_b_Vc_prime_size[1];
  int32_T c3_b_tmp_size[1];
  int32_T c3_bb_tmp_size[1];
  int32_T c3_c_Vc_prime_size[1];
  int32_T c3_cb_tmp_size[1];
  int32_T c3_d_tmp_size[1];
  int32_T c3_db_tmp_size[1];
  int32_T c3_e_tmp_size[1];
  int32_T c3_eb_tmp_size[1];
  int32_T c3_ec_trueCount[1];
  int32_T c3_f_tmp_size[1];
  int32_T c3_fb_tmp_size[1];
  int32_T c3_g_tmp_size[1];
  int32_T c3_gb_tmp_size[1];
  int32_T c3_h_tmp_size[1];
  int32_T c3_hb_tmp_size[1];
  int32_T c3_i_tmp_size[1];
  int32_T c3_ib_tmp_size[1];
  int32_T c3_j_tmp_size[1];
  int32_T c3_jb_tmp_size[1];
  int32_T c3_k_tmp_size[1];
  int32_T c3_kb_tmp_size[1];
  int32_T c3_l_tmp_size[1];
  int32_T c3_lam_Cz_size[1];
  int32_T c3_lb_tmp_size[1];
  int32_T c3_m_tmp_size[1];
  int32_T c3_n_tmp_size[1];
  int32_T c3_o_tmp_size[1];
  int32_T c3_p_tmp_size[1];
  int32_T c3_q_tmp_size[1];
  int32_T c3_r_tmp_size[1];
  int32_T c3_rhoz_size[1];
  int32_T c3_s_tmp_size[1];
  int32_T c3_t_tmp_size[1];
  int32_T c3_tmpDrphiVar_size[1];
  int32_T c3_tmp_data[1];
  int32_T c3_u_tmp_size[1];
  int32_T c3_v_tmp_size[1];
  int32_T c3_w_tmp_size[1];
  int32_T c3_x_tmp_size[1];
  int32_T c3_y_size[1];
  int32_T c3_y_tmp_size[1];
  int32_T c3_ab_i;
  int32_T c3_ab_k;
  int32_T c3_ab_loop_ub;
  int32_T c3_ab_partialTrueCount;
  int32_T c3_ab_trueCount;
  int32_T c3_ac_i;
  int32_T c3_ac_k;
  int32_T c3_ac_loop_ub;
  int32_T c3_ac_trueCount;
  int32_T c3_ad_i;
  int32_T c3_ad_k;
  int32_T c3_ae_i;
  int32_T c3_ae_k;
  int32_T c3_af_i;
  int32_T c3_af_k;
  int32_T c3_ag_k;
  int32_T c3_ah_k;
  int32_T c3_b_end;
  int32_T c3_b_i;
  int32_T c3_b_k;
  int32_T c3_b_loop_ub;
  int32_T c3_b_partialTrueCount;
  int32_T c3_b_trueCount;
  int32_T c3_bb_i;
  int32_T c3_bb_k;
  int32_T c3_bb_loop_ub;
  int32_T c3_bb_partialTrueCount;
  int32_T c3_bb_trueCount;
  int32_T c3_bc_i;
  int32_T c3_bc_k;
  int32_T c3_bc_loop_ub;
  int32_T c3_bc_trueCount;
  int32_T c3_bd_i;
  int32_T c3_bd_k;
  int32_T c3_be_i;
  int32_T c3_be_k;
  int32_T c3_bf_i;
  int32_T c3_bf_k;
  int32_T c3_bg_k;
  int32_T c3_bh_k;
  int32_T c3_c_i;
  int32_T c3_c_k;
  int32_T c3_c_loop_ub;
  int32_T c3_c_partialTrueCount;
  int32_T c3_c_trueCount;
  int32_T c3_cb_i;
  int32_T c3_cb_k;
  int32_T c3_cb_loop_ub;
  int32_T c3_cb_partialTrueCount;
  int32_T c3_cb_trueCount;
  int32_T c3_cc_i;
  int32_T c3_cc_k;
  int32_T c3_cc_loop_ub;
  int32_T c3_cc_trueCount;
  int32_T c3_cd_i;
  int32_T c3_cd_k;
  int32_T c3_ce_i;
  int32_T c3_ce_k;
  int32_T c3_cf_i;
  int32_T c3_cf_k;
  int32_T c3_cg_k;
  int32_T c3_ch_k;
  int32_T c3_d_i;
  int32_T c3_d_k;
  int32_T c3_d_loop_ub;
  int32_T c3_d_partialTrueCount;
  int32_T c3_d_trueCount;
  int32_T c3_db_i;
  int32_T c3_db_k;
  int32_T c3_db_loop_ub;
  int32_T c3_db_partialTrueCount;
  int32_T c3_db_trueCount;
  int32_T c3_dc_i;
  int32_T c3_dc_k;
  int32_T c3_dc_loop_ub;
  int32_T c3_dc_trueCount;
  int32_T c3_dd_i;
  int32_T c3_dd_k;
  int32_T c3_de_i;
  int32_T c3_de_k;
  int32_T c3_df_i;
  int32_T c3_df_k;
  int32_T c3_dg_k;
  int32_T c3_dh_k;
  int32_T c3_e_i;
  int32_T c3_e_k;
  int32_T c3_e_loop_ub;
  int32_T c3_e_partialTrueCount;
  int32_T c3_e_trueCount;
  int32_T c3_eb_i;
  int32_T c3_eb_k;
  int32_T c3_eb_loop_ub;
  int32_T c3_eb_partialTrueCount;
  int32_T c3_eb_trueCount;
  int32_T c3_ec_i;
  int32_T c3_ec_k;
  int32_T c3_ec_loop_ub;
  int32_T c3_ed_i;
  int32_T c3_ed_k;
  int32_T c3_ee_i;
  int32_T c3_ee_k;
  int32_T c3_ef_i;
  int32_T c3_ef_k;
  int32_T c3_eg_k;
  int32_T c3_eh_k;
  int32_T c3_end;
  int32_T c3_f_i;
  int32_T c3_f_k;
  int32_T c3_f_loop_ub;
  int32_T c3_f_partialTrueCount;
  int32_T c3_f_trueCount;
  int32_T c3_fb_i;
  int32_T c3_fb_k;
  int32_T c3_fb_loop_ub;
  int32_T c3_fb_partialTrueCount;
  int32_T c3_fb_trueCount;
  int32_T c3_fc_i;
  int32_T c3_fc_k;
  int32_T c3_fc_loop_ub;
  int32_T c3_fc_trueCount;
  int32_T c3_fd_i;
  int32_T c3_fd_k;
  int32_T c3_fe_i;
  int32_T c3_fe_k;
  int32_T c3_ff_i;
  int32_T c3_ff_k;
  int32_T c3_fg_k;
  int32_T c3_fh_k;
  int32_T c3_g_i;
  int32_T c3_g_k;
  int32_T c3_g_loop_ub;
  int32_T c3_g_partialTrueCount;
  int32_T c3_g_trueCount;
  int32_T c3_gb_i;
  int32_T c3_gb_k;
  int32_T c3_gb_loop_ub;
  int32_T c3_gb_partialTrueCount;
  int32_T c3_gb_trueCount;
  int32_T c3_gc_i;
  int32_T c3_gc_k;
  int32_T c3_gc_loop_ub;
  int32_T c3_gc_trueCount;
  int32_T c3_gd_i;
  int32_T c3_gd_k;
  int32_T c3_ge_i;
  int32_T c3_ge_k;
  int32_T c3_gf_i;
  int32_T c3_gf_k;
  int32_T c3_gg_k;
  int32_T c3_gh_k;
  int32_T c3_h_i;
  int32_T c3_h_k;
  int32_T c3_h_loop_ub;
  int32_T c3_h_partialTrueCount;
  int32_T c3_h_trueCount;
  int32_T c3_hb_i;
  int32_T c3_hb_k;
  int32_T c3_hb_loop_ub;
  int32_T c3_hb_partialTrueCount;
  int32_T c3_hb_trueCount;
  int32_T c3_hc_i;
  int32_T c3_hc_k;
  int32_T c3_hc_loop_ub;
  int32_T c3_hc_trueCount;
  int32_T c3_hd_i;
  int32_T c3_hd_k;
  int32_T c3_he_i;
  int32_T c3_he_k;
  int32_T c3_hf_i;
  int32_T c3_hf_k;
  int32_T c3_hg_k;
  int32_T c3_hh_k;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i10;
  int32_T c3_i100;
  int32_T c3_i101;
  int32_T c3_i102;
  int32_T c3_i103;
  int32_T c3_i104;
  int32_T c3_i105;
  int32_T c3_i106;
  int32_T c3_i107;
  int32_T c3_i108;
  int32_T c3_i109;
  int32_T c3_i11;
  int32_T c3_i110;
  int32_T c3_i111;
  int32_T c3_i112;
  int32_T c3_i113;
  int32_T c3_i114;
  int32_T c3_i115;
  int32_T c3_i116;
  int32_T c3_i117;
  int32_T c3_i118;
  int32_T c3_i119;
  int32_T c3_i12;
  int32_T c3_i120;
  int32_T c3_i121;
  int32_T c3_i122;
  int32_T c3_i123;
  int32_T c3_i124;
  int32_T c3_i125;
  int32_T c3_i126;
  int32_T c3_i127;
  int32_T c3_i128;
  int32_T c3_i129;
  int32_T c3_i13;
  int32_T c3_i130;
  int32_T c3_i131;
  int32_T c3_i132;
  int32_T c3_i133;
  int32_T c3_i134;
  int32_T c3_i135;
  int32_T c3_i136;
  int32_T c3_i137;
  int32_T c3_i138;
  int32_T c3_i139;
  int32_T c3_i14;
  int32_T c3_i140;
  int32_T c3_i141;
  int32_T c3_i142;
  int32_T c3_i143;
  int32_T c3_i144;
  int32_T c3_i145;
  int32_T c3_i146;
  int32_T c3_i147;
  int32_T c3_i148;
  int32_T c3_i149;
  int32_T c3_i15;
  int32_T c3_i150;
  int32_T c3_i151;
  int32_T c3_i152;
  int32_T c3_i153;
  int32_T c3_i154;
  int32_T c3_i155;
  int32_T c3_i156;
  int32_T c3_i157;
  int32_T c3_i158;
  int32_T c3_i159;
  int32_T c3_i16;
  int32_T c3_i160;
  int32_T c3_i161;
  int32_T c3_i162;
  int32_T c3_i163;
  int32_T c3_i164;
  int32_T c3_i165;
  int32_T c3_i166;
  int32_T c3_i167;
  int32_T c3_i168;
  int32_T c3_i169;
  int32_T c3_i17;
  int32_T c3_i170;
  int32_T c3_i171;
  int32_T c3_i172;
  int32_T c3_i173;
  int32_T c3_i174;
  int32_T c3_i175;
  int32_T c3_i176;
  int32_T c3_i177;
  int32_T c3_i178;
  int32_T c3_i179;
  int32_T c3_i18;
  int32_T c3_i180;
  int32_T c3_i181;
  int32_T c3_i182;
  int32_T c3_i183;
  int32_T c3_i184;
  int32_T c3_i185;
  int32_T c3_i186;
  int32_T c3_i187;
  int32_T c3_i188;
  int32_T c3_i189;
  int32_T c3_i19;
  int32_T c3_i190;
  int32_T c3_i191;
  int32_T c3_i192;
  int32_T c3_i193;
  int32_T c3_i194;
  int32_T c3_i195;
  int32_T c3_i196;
  int32_T c3_i197;
  int32_T c3_i198;
  int32_T c3_i199;
  int32_T c3_i2;
  int32_T c3_i20;
  int32_T c3_i200;
  int32_T c3_i201;
  int32_T c3_i202;
  int32_T c3_i203;
  int32_T c3_i204;
  int32_T c3_i205;
  int32_T c3_i206;
  int32_T c3_i207;
  int32_T c3_i208;
  int32_T c3_i209;
  int32_T c3_i21;
  int32_T c3_i210;
  int32_T c3_i211;
  int32_T c3_i212;
  int32_T c3_i213;
  int32_T c3_i214;
  int32_T c3_i215;
  int32_T c3_i216;
  int32_T c3_i217;
  int32_T c3_i218;
  int32_T c3_i219;
  int32_T c3_i22;
  int32_T c3_i220;
  int32_T c3_i221;
  int32_T c3_i222;
  int32_T c3_i223;
  int32_T c3_i224;
  int32_T c3_i225;
  int32_T c3_i226;
  int32_T c3_i227;
  int32_T c3_i228;
  int32_T c3_i229;
  int32_T c3_i23;
  int32_T c3_i230;
  int32_T c3_i231;
  int32_T c3_i232;
  int32_T c3_i233;
  int32_T c3_i234;
  int32_T c3_i235;
  int32_T c3_i236;
  int32_T c3_i237;
  int32_T c3_i238;
  int32_T c3_i239;
  int32_T c3_i24;
  int32_T c3_i240;
  int32_T c3_i241;
  int32_T c3_i242;
  int32_T c3_i243;
  int32_T c3_i244;
  int32_T c3_i245;
  int32_T c3_i246;
  int32_T c3_i247;
  int32_T c3_i248;
  int32_T c3_i249;
  int32_T c3_i25;
  int32_T c3_i250;
  int32_T c3_i251;
  int32_T c3_i252;
  int32_T c3_i253;
  int32_T c3_i254;
  int32_T c3_i255;
  int32_T c3_i256;
  int32_T c3_i257;
  int32_T c3_i258;
  int32_T c3_i259;
  int32_T c3_i26;
  int32_T c3_i260;
  int32_T c3_i261;
  int32_T c3_i262;
  int32_T c3_i263;
  int32_T c3_i264;
  int32_T c3_i265;
  int32_T c3_i266;
  int32_T c3_i267;
  int32_T c3_i268;
  int32_T c3_i269;
  int32_T c3_i27;
  int32_T c3_i270;
  int32_T c3_i271;
  int32_T c3_i272;
  int32_T c3_i273;
  int32_T c3_i274;
  int32_T c3_i275;
  int32_T c3_i276;
  int32_T c3_i277;
  int32_T c3_i278;
  int32_T c3_i279;
  int32_T c3_i28;
  int32_T c3_i280;
  int32_T c3_i281;
  int32_T c3_i282;
  int32_T c3_i283;
  int32_T c3_i284;
  int32_T c3_i285;
  int32_T c3_i286;
  int32_T c3_i287;
  int32_T c3_i288;
  int32_T c3_i289;
  int32_T c3_i29;
  int32_T c3_i3;
  int32_T c3_i30;
  int32_T c3_i31;
  int32_T c3_i32;
  int32_T c3_i33;
  int32_T c3_i34;
  int32_T c3_i35;
  int32_T c3_i36;
  int32_T c3_i37;
  int32_T c3_i38;
  int32_T c3_i39;
  int32_T c3_i4;
  int32_T c3_i40;
  int32_T c3_i41;
  int32_T c3_i42;
  int32_T c3_i43;
  int32_T c3_i44;
  int32_T c3_i45;
  int32_T c3_i46;
  int32_T c3_i47;
  int32_T c3_i48;
  int32_T c3_i49;
  int32_T c3_i5;
  int32_T c3_i50;
  int32_T c3_i51;
  int32_T c3_i52;
  int32_T c3_i53;
  int32_T c3_i54;
  int32_T c3_i55;
  int32_T c3_i56;
  int32_T c3_i57;
  int32_T c3_i58;
  int32_T c3_i59;
  int32_T c3_i6;
  int32_T c3_i60;
  int32_T c3_i61;
  int32_T c3_i62;
  int32_T c3_i63;
  int32_T c3_i64;
  int32_T c3_i65;
  int32_T c3_i66;
  int32_T c3_i67;
  int32_T c3_i68;
  int32_T c3_i69;
  int32_T c3_i7;
  int32_T c3_i70;
  int32_T c3_i71;
  int32_T c3_i72;
  int32_T c3_i73;
  int32_T c3_i74;
  int32_T c3_i75;
  int32_T c3_i76;
  int32_T c3_i77;
  int32_T c3_i78;
  int32_T c3_i79;
  int32_T c3_i8;
  int32_T c3_i80;
  int32_T c3_i81;
  int32_T c3_i82;
  int32_T c3_i83;
  int32_T c3_i84;
  int32_T c3_i85;
  int32_T c3_i86;
  int32_T c3_i87;
  int32_T c3_i88;
  int32_T c3_i89;
  int32_T c3_i9;
  int32_T c3_i90;
  int32_T c3_i91;
  int32_T c3_i92;
  int32_T c3_i93;
  int32_T c3_i94;
  int32_T c3_i95;
  int32_T c3_i96;
  int32_T c3_i97;
  int32_T c3_i98;
  int32_T c3_i99;
  int32_T c3_i_i;
  int32_T c3_i_k;
  int32_T c3_i_loop_ub;
  int32_T c3_i_partialTrueCount;
  int32_T c3_i_trueCount;
  int32_T c3_ib_i;
  int32_T c3_ib_k;
  int32_T c3_ib_loop_ub;
  int32_T c3_ib_partialTrueCount;
  int32_T c3_ib_trueCount;
  int32_T c3_ic_i;
  int32_T c3_ic_k;
  int32_T c3_ic_loop_ub;
  int32_T c3_ic_trueCount;
  int32_T c3_id_i;
  int32_T c3_id_k;
  int32_T c3_ie_i;
  int32_T c3_ie_k;
  int32_T c3_if_i;
  int32_T c3_if_k;
  int32_T c3_ig_k;
  int32_T c3_ih_k;
  int32_T c3_j_i;
  int32_T c3_j_k;
  int32_T c3_j_loop_ub;
  int32_T c3_j_partialTrueCount;
  int32_T c3_j_trueCount;
  int32_T c3_jb_i;
  int32_T c3_jb_k;
  int32_T c3_jb_loop_ub;
  int32_T c3_jb_partialTrueCount;
  int32_T c3_jb_trueCount;
  int32_T c3_jc_i;
  int32_T c3_jc_k;
  int32_T c3_jc_trueCount;
  int32_T c3_jd_i;
  int32_T c3_jd_k;
  int32_T c3_je_i;
  int32_T c3_je_k;
  int32_T c3_jf_i;
  int32_T c3_jf_k;
  int32_T c3_jg_k;
  int32_T c3_jh_k;
  int32_T c3_k;
  int32_T c3_k_i;
  int32_T c3_k_k;
  int32_T c3_k_loop_ub;
  int32_T c3_k_partialTrueCount;
  int32_T c3_k_trueCount;
  int32_T c3_kb_i;
  int32_T c3_kb_k;
  int32_T c3_kb_loop_ub;
  int32_T c3_kb_partialTrueCount;
  int32_T c3_kb_trueCount;
  int32_T c3_kc_i;
  int32_T c3_kc_k;
  int32_T c3_kc_trueCount;
  int32_T c3_kd_i;
  int32_T c3_kd_k;
  int32_T c3_ke_i;
  int32_T c3_ke_k;
  int32_T c3_kf_i;
  int32_T c3_kf_k;
  int32_T c3_kg_k;
  int32_T c3_kh_k;
  int32_T c3_l_i;
  int32_T c3_l_k;
  int32_T c3_l_loop_ub;
  int32_T c3_l_partialTrueCount;
  int32_T c3_l_trueCount;
  int32_T c3_lb_i;
  int32_T c3_lb_k;
  int32_T c3_lb_loop_ub;
  int32_T c3_lb_partialTrueCount;
  int32_T c3_lb_trueCount;
  int32_T c3_lc_i;
  int32_T c3_lc_k;
  int32_T c3_ld_i;
  int32_T c3_ld_k;
  int32_T c3_le_i;
  int32_T c3_le_k;
  int32_T c3_lf_k;
  int32_T c3_lg_k;
  int32_T c3_loop_ub;
  int32_T c3_m_i;
  int32_T c3_m_k;
  int32_T c3_m_loop_ub;
  int32_T c3_m_partialTrueCount;
  int32_T c3_m_trueCount;
  int32_T c3_mb_i;
  int32_T c3_mb_k;
  int32_T c3_mb_loop_ub;
  int32_T c3_mb_partialTrueCount;
  int32_T c3_mb_trueCount;
  int32_T c3_mc_i;
  int32_T c3_mc_k;
  int32_T c3_md_i;
  int32_T c3_md_k;
  int32_T c3_me_i;
  int32_T c3_me_k;
  int32_T c3_mf_k;
  int32_T c3_mg_k;
  int32_T c3_n_i;
  int32_T c3_n_k;
  int32_T c3_n_loop_ub;
  int32_T c3_n_partialTrueCount;
  int32_T c3_n_trueCount;
  int32_T c3_nb_i;
  int32_T c3_nb_k;
  int32_T c3_nb_loop_ub;
  int32_T c3_nb_partialTrueCount;
  int32_T c3_nb_trueCount;
  int32_T c3_nc_i;
  int32_T c3_nc_k;
  int32_T c3_nd_i;
  int32_T c3_nd_k;
  int32_T c3_ne_i;
  int32_T c3_ne_k;
  int32_T c3_nf_k;
  int32_T c3_ng_k;
  int32_T c3_o_i;
  int32_T c3_o_k;
  int32_T c3_o_loop_ub;
  int32_T c3_o_partialTrueCount;
  int32_T c3_o_trueCount;
  int32_T c3_ob_i;
  int32_T c3_ob_k;
  int32_T c3_ob_loop_ub;
  int32_T c3_ob_trueCount;
  int32_T c3_oc_i;
  int32_T c3_oc_k;
  int32_T c3_od_i;
  int32_T c3_od_k;
  int32_T c3_oe_i;
  int32_T c3_oe_k;
  int32_T c3_of_k;
  int32_T c3_og_k;
  int32_T c3_p_i;
  int32_T c3_p_k;
  int32_T c3_p_loop_ub;
  int32_T c3_p_partialTrueCount;
  int32_T c3_p_trueCount;
  int32_T c3_partialTrueCount;
  int32_T c3_pb_i;
  int32_T c3_pb_k;
  int32_T c3_pb_loop_ub;
  int32_T c3_pb_trueCount;
  int32_T c3_pc_i;
  int32_T c3_pc_k;
  int32_T c3_pd_i;
  int32_T c3_pd_k;
  int32_T c3_pe_i;
  int32_T c3_pe_k;
  int32_T c3_pf_k;
  int32_T c3_pg_k;
  int32_T c3_q_i;
  int32_T c3_q_k;
  int32_T c3_q_loop_ub;
  int32_T c3_q_partialTrueCount;
  int32_T c3_q_trueCount;
  int32_T c3_qb_i;
  int32_T c3_qb_k;
  int32_T c3_qb_loop_ub;
  int32_T c3_qb_trueCount;
  int32_T c3_qc_i;
  int32_T c3_qc_k;
  int32_T c3_qd_i;
  int32_T c3_qd_k;
  int32_T c3_qe_i;
  int32_T c3_qe_k;
  int32_T c3_qf_k;
  int32_T c3_qg_k;
  int32_T c3_r_i;
  int32_T c3_r_k;
  int32_T c3_r_loop_ub;
  int32_T c3_r_partialTrueCount;
  int32_T c3_r_trueCount;
  int32_T c3_rb_i;
  int32_T c3_rb_k;
  int32_T c3_rb_loop_ub;
  int32_T c3_rb_trueCount;
  int32_T c3_rc_i;
  int32_T c3_rc_k;
  int32_T c3_rd_i;
  int32_T c3_rd_k;
  int32_T c3_re_i;
  int32_T c3_re_k;
  int32_T c3_rf_k;
  int32_T c3_rg_k;
  int32_T c3_s_i;
  int32_T c3_s_k;
  int32_T c3_s_loop_ub;
  int32_T c3_s_partialTrueCount;
  int32_T c3_s_trueCount;
  int32_T c3_sb_i;
  int32_T c3_sb_k;
  int32_T c3_sb_loop_ub;
  int32_T c3_sb_trueCount;
  int32_T c3_sc_i;
  int32_T c3_sc_k;
  int32_T c3_sd_i;
  int32_T c3_sd_k;
  int32_T c3_se_i;
  int32_T c3_se_k;
  int32_T c3_sf_k;
  int32_T c3_sg_k;
  int32_T c3_t_i;
  int32_T c3_t_k;
  int32_T c3_t_loop_ub;
  int32_T c3_t_partialTrueCount;
  int32_T c3_t_trueCount;
  int32_T c3_tb_i;
  int32_T c3_tb_k;
  int32_T c3_tb_loop_ub;
  int32_T c3_tb_trueCount;
  int32_T c3_tc_i;
  int32_T c3_tc_k;
  int32_T c3_td_i;
  int32_T c3_td_k;
  int32_T c3_te_i;
  int32_T c3_te_k;
  int32_T c3_tf_k;
  int32_T c3_tg_k;
  int32_T c3_trueCount;
  int32_T c3_u_i;
  int32_T c3_u_k;
  int32_T c3_u_loop_ub;
  int32_T c3_u_partialTrueCount;
  int32_T c3_u_trueCount;
  int32_T c3_ub_i;
  int32_T c3_ub_k;
  int32_T c3_ub_loop_ub;
  int32_T c3_ub_trueCount;
  int32_T c3_uc_i;
  int32_T c3_uc_k;
  int32_T c3_ud_i;
  int32_T c3_ud_k;
  int32_T c3_ue_i;
  int32_T c3_ue_k;
  int32_T c3_uf_k;
  int32_T c3_ug_k;
  int32_T c3_v_i;
  int32_T c3_v_k;
  int32_T c3_v_loop_ub;
  int32_T c3_v_partialTrueCount;
  int32_T c3_v_trueCount;
  int32_T c3_vb_i;
  int32_T c3_vb_k;
  int32_T c3_vb_loop_ub;
  int32_T c3_vb_trueCount;
  int32_T c3_vc_i;
  int32_T c3_vc_k;
  int32_T c3_vd_i;
  int32_T c3_vd_k;
  int32_T c3_ve_i;
  int32_T c3_ve_k;
  int32_T c3_vf_k;
  int32_T c3_vg_k;
  int32_T c3_w_i;
  int32_T c3_w_k;
  int32_T c3_w_loop_ub;
  int32_T c3_w_partialTrueCount;
  int32_T c3_w_trueCount;
  int32_T c3_wb_i;
  int32_T c3_wb_k;
  int32_T c3_wb_loop_ub;
  int32_T c3_wb_trueCount;
  int32_T c3_wc_i;
  int32_T c3_wc_k;
  int32_T c3_wd_i;
  int32_T c3_wd_k;
  int32_T c3_we_i;
  int32_T c3_we_k;
  int32_T c3_wf_k;
  int32_T c3_wg_k;
  int32_T c3_x_i;
  int32_T c3_x_k;
  int32_T c3_x_loop_ub;
  int32_T c3_x_partialTrueCount;
  int32_T c3_x_trueCount;
  int32_T c3_xb_i;
  int32_T c3_xb_k;
  int32_T c3_xb_loop_ub;
  int32_T c3_xb_trueCount;
  int32_T c3_xc_i;
  int32_T c3_xc_k;
  int32_T c3_xd_i;
  int32_T c3_xd_k;
  int32_T c3_xe_i;
  int32_T c3_xe_k;
  int32_T c3_xf_k;
  int32_T c3_xg_k;
  int32_T c3_y_i;
  int32_T c3_y_k;
  int32_T c3_y_loop_ub;
  int32_T c3_y_partialTrueCount;
  int32_T c3_y_trueCount;
  int32_T c3_yb_i;
  int32_T c3_yb_k;
  int32_T c3_yb_loop_ub;
  int32_T c3_yb_trueCount;
  int32_T c3_yc_i;
  int32_T c3_yc_k;
  int32_T c3_yd_i;
  int32_T c3_yd_k;
  int32_T c3_ye_i;
  int32_T c3_ye_k;
  int32_T c3_yf_k;
  int32_T c3_yg_k;
  boolean_T c3_b_isLowSpeed[4];
  boolean_T c3_isLowSpeed[4];
  boolean_T c3_bv[1];
  boolean_T c3_b_b;
  boolean_T c3_b_x;
  boolean_T c3_tempInds;
  boolean_T c3_x;
  boolean_T c3_y;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_b_st.prev = &c3_st;
  c3_b_st.tls = c3_st.tls;
  c3_c_st.prev = &c3_b_st;
  c3_c_st.tls = c3_b_st.tls;
  if (c3_b_vdynMF[3] == 1.0) {
    c3_i = 0;
    for (c3_i2 = 0; c3_i2 < 4; c3_i2++) {
      c3_lam_Fzo[c3_i2] = c3_scaleFactors[c3_i];
      c3_i += 27;
    }

    c3_i4 = 0;
    for (c3_i5 = 0; c3_i5 < 4; c3_i5++) {
      c3_lam_mux[c3_i5] = c3_scaleFactors[c3_i4 + 1];
      c3_i4 += 27;
    }

    c3_i6 = 0;
    for (c3_i7 = 0; c3_i7 < 4; c3_i7++) {
      c3_lam_muy[c3_i7] = c3_scaleFactors[c3_i6 + 2];
      c3_i6 += 27;
    }

    c3_i8 = 0;
    for (c3_i9 = 0; c3_i9 < 4; c3_i9++) {
      c3_lam_muV[c3_i9] = c3_scaleFactors[c3_i8 + 3];
      c3_i8 += 27;
    }

    c3_i10 = 0;
    for (c3_i11 = 0; c3_i11 < 4; c3_i11++) {
      c3_lam_Kxkappa[c3_i11] = c3_scaleFactors[c3_i10 + 4];
      c3_i10 += 27;
    }

    c3_i12 = 0;
    for (c3_i13 = 0; c3_i13 < 4; c3_i13++) {
      c3_lam_Kyalpha[c3_i13] = c3_scaleFactors[c3_i12 + 5];
      c3_i12 += 27;
    }

    c3_i14 = 0;
    for (c3_i15 = 0; c3_i15 < 4; c3_i15++) {
      c3_lam_Cx[c3_i15] = c3_scaleFactors[c3_i14 + 6];
      c3_i14 += 27;
    }

    c3_i16 = 0;
    for (c3_i17 = 0; c3_i17 < 4; c3_i17++) {
      c3_lam_Cy[c3_i17] = c3_scaleFactors[c3_i16 + 7];
      c3_i16 += 27;
    }

    c3_i18 = 0;
    for (c3_i19 = 0; c3_i19 < 4; c3_i19++) {
      c3_lam_Ex[c3_i19] = c3_scaleFactors[c3_i18 + 8];
      c3_i18 += 27;
    }

    c3_i20 = 0;
    for (c3_i21 = 0; c3_i21 < 4; c3_i21++) {
      c3_lam_Ey[c3_i21] = c3_scaleFactors[c3_i20 + 9];
      c3_i20 += 27;
    }

    c3_i22 = 0;
    for (c3_i23 = 0; c3_i23 < 4; c3_i23++) {
      c3_lam_Hx[c3_i23] = c3_scaleFactors[c3_i22 + 10];
      c3_i22 += 27;
    }

    c3_i24 = 0;
    for (c3_i25 = 0; c3_i25 < 4; c3_i25++) {
      c3_lam_Hy[c3_i25] = c3_scaleFactors[c3_i24 + 11];
      c3_i24 += 27;
    }

    c3_i26 = 0;
    for (c3_i27 = 0; c3_i27 < 4; c3_i27++) {
      c3_lam_Vx[c3_i27] = c3_scaleFactors[c3_i26 + 12];
      c3_i26 += 27;
    }

    c3_i28 = 0;
    for (c3_i29 = 0; c3_i29 < 4; c3_i29++) {
      c3_lam_Vy[c3_i29] = c3_scaleFactors[c3_i28 + 13];
      c3_i28 += 27;
    }

    c3_i30 = 0;
    for (c3_i31 = 0; c3_i31 < 4; c3_i31++) {
      c3_lam_Kygamma[c3_i31] = c3_scaleFactors[c3_i30 + 14];
      c3_i30 += 27;
    }

    c3_i32 = 0;
    for (c3_i33 = 0; c3_i33 < 4; c3_i33++) {
      c3_lam_Kzgamma[c3_i33] = c3_scaleFactors[c3_i32 + 15];
      c3_i32 += 27;
    }

    c3_i34 = 0;
    for (c3_i35 = 0; c3_i35 < 4; c3_i35++) {
      c3_lam_t[c3_i35] = c3_scaleFactors[c3_i34 + 16];
      c3_i34 += 27;
    }

    c3_i36 = 0;
    for (c3_i37 = 0; c3_i37 < 4; c3_i37++) {
      c3_lam_Mr[c3_i37] = c3_scaleFactors[c3_i36 + 17];
      c3_i36 += 27;
    }

    c3_i38 = 0;
    for (c3_i39 = 0; c3_i39 < 4; c3_i39++) {
      c3_lam_xalpha[c3_i39] = c3_scaleFactors[c3_i38 + 18];
      c3_i38 += 27;
    }

    c3_i40 = 0;
    for (c3_i41 = 0; c3_i41 < 4; c3_i41++) {
      c3_lam_ykappa[c3_i41] = c3_scaleFactors[c3_i40 + 19];
      c3_i40 += 27;
    }

    c3_i42 = 0;
    for (c3_i43 = 0; c3_i43 < 4; c3_i43++) {
      c3_lam_Vykappa[c3_i43] = c3_scaleFactors[c3_i42 + 20];
      c3_i42 += 27;
    }

    c3_i44 = 0;
    for (c3_i45 = 0; c3_i45 < 4; c3_i45++) {
      c3_lam_s[c3_i45] = c3_scaleFactors[c3_i44 + 21];
      c3_i44 += 27;
    }

    c3_i46 = 0;
    for (c3_i47 = 0; c3_i47 < 4; c3_i47++) {
      c3_lam_Cz[c3_i47] = c3_scaleFactors[c3_i46 + 22];
      c3_i46 += 27;
    }

    c3_i48 = 0;
    for (c3_i49 = 0; c3_i49 < 4; c3_i49++) {
      c3_b_Mx[c3_i49] = c3_scaleFactors[c3_i48 + 23];
      c3_i48 += 27;
    }

    c3_i50 = 0;
    for (c3_i51 = 0; c3_i51 < 4; c3_i51++) {
      c3_lam_VMx[c3_i51] = c3_scaleFactors[c3_i50 + 24];
      c3_i50 += 27;
    }

    c3_i52 = 0;
    for (c3_i53 = 0; c3_i53 < 4; c3_i53++) {
      c3_lam_My[c3_i53] = c3_scaleFactors[c3_i52 + 25];
      c3_i52 += 27;
    }

    c3_i54 = 0;
    for (c3_i55 = 0; c3_i55 < 4; c3_i55++) {
      c3_lam_Mphi[c3_i55] = c3_scaleFactors[c3_i54 + 26];
      c3_i54 += 27;
    }

    c3_st.site = &c3_b_emlrtRSI;
    c3_div0protect(chartInstance, &c3_st, c3_b_Vx, c3_b_VXLOW, c3_Fz_btm, c3_Vsy);
    for (c3_b_i = 0; c3_b_i < 4; c3_b_i++) {
      if (c3_gamma[c3_b_i] < c3_b_CAMMIN) {
        c3_gamma[c3_b_i] = c3_b_CAMMIN;
      }
    }

    for (c3_c_i = 0; c3_c_i < 4; c3_c_i++) {
      if (c3_gamma[c3_c_i] > c3_b_CAMMAX) {
        c3_gamma[c3_c_i] = c3_b_CAMMAX;
      }
    }

    for (c3_d_i = 0; c3_d_i < 4; c3_d_i++) {
      if (c3_press[c3_d_i] < c3_b_PRESMIN) {
        c3_press[c3_d_i] = c3_b_PRESMIN;
      }
    }

    for (c3_e_i = 0; c3_e_i < 4; c3_e_i++) {
      if (c3_press[c3_e_i] > c3_b_PRESMAX) {
        c3_press[c3_e_i] = c3_b_PRESMAX;
      }
    }

    for (c3_i56 = 0; c3_i56 < 4; c3_i56++) {
      c3_dpi[c3_i56] = (c3_press[c3_i56] - c3_b_NOMPRES) / c3_b_NOMPRES;
    }

    for (c3_f_i = 0; c3_f_i < 4; c3_f_i++) {
      if (c3_lam_mux[c3_f_i] <= 0.0) {
        c3_lam_mux[c3_f_i] = 2.2204460492503131E-16;
      }
    }

    for (c3_g_i = 0; c3_g_i < 4; c3_g_i++) {
      if (c3_lam_muy[c3_g_i] <= 0.0) {
        c3_lam_muy[c3_g_i] = 2.2204460492503131E-16;
      }
    }

    c3_x = (c3_b_Q_FZ1 == 0.0);
    c3_b_x = c3_x;
    if (!c3_b_x) {
      c3_b_b = true;
    } else {
      c3_b_b = false;
    }

    c3_y = !c3_b_b;
    if (c3_y) {
      c3_st.site = &c3_b_emlrtRSI;
      c3_b_a = c3_b_VERTICAL_STIFFNESS * c3_b_UNLOADED_RADIUS / c3_b_FNOMIN;
      c3_b_st.site = &c3_c_emlrtRSI;
      c3_c_a = c3_b_a;
      c3_d_a = c3_c_a;
      c3_e_a = c3_d_a;
      c3_b_y = c3_e_a * c3_e_a;
      c3_tempInds = (c3_b_y - 4.0 * c3_b_Q_FZ2 < 0.0);
      c3_dv[0] = c3_b_Q_FZ1;
      c3_bv[0] = c3_tempInds;
      c3_trueCount = 0;
      for (c3_h_i = 0; c3_h_i < 1; c3_h_i++) {
        if (c3_bv[0]) {
          c3_trueCount++;
        }
      }

      c3_tmp_size[0] = 1;
      c3_tmp_size[1] = c3_trueCount;
      c3_partialTrueCount = 0;
      for (c3_i_i = 0; c3_i_i < 1; c3_i_i++) {
        if (c3_bv[0]) {
          c3_tmp_data[c3_partialTrueCount] = c3_i_i + 1;
          c3_partialTrueCount++;
        }
      }

      c3_loop_ub = c3_tmp_size[0] * c3_tmp_size[1] - 1;
      for (c3_i63 = 0; c3_i63 <= c3_loop_ub; c3_i63++) {
        c3_dv[c3_tmp_data[c3_i63] - 1] = c3_b_Q_FZ2 * 0.0;
      }

      c3_b_Q_FZ1 = c3_dv[0];
      c3_bv[0] = !c3_tempInds;
      c3_b_trueCount = 0;
      for (c3_j_i = 0; c3_j_i < 1; c3_j_i++) {
        if (c3_bv[0]) {
          c3_b_trueCount++;
        }
      }

      c3_x_size[0] = 1;
      c3_x_size[1] = c3_b_trueCount;
      c3_b_loop_ub = c3_b_trueCount - 1;
      for (c3_i66 = 0; c3_i66 <= c3_b_loop_ub; c3_i66++) {
        c3_x_data[c3_i66] = c3_b_VERTICAL_STIFFNESS;
      }

      c3_bv[0] = !c3_tempInds;
      c3_d_trueCount = 0;
      for (c3_l_i = 0; c3_l_i < 1; c3_l_i++) {
        if (c3_bv[0]) {
          c3_d_trueCount++;
        }
      }

      c3_c_tmp_size[0] = 1;
      c3_c_tmp_size[1] = c3_d_trueCount;
      c3_c_loop_ub = c3_d_trueCount - 1;
      for (c3_i68 = 0; c3_i68 <= c3_c_loop_ub; c3_i68++) {
        c3_c_tmp_data[c3_i68] = c3_b_UNLOADED_RADIUS;
      }

      if ((c3_x_size[1] != c3_c_tmp_size[1]) && ((c3_x_size[1] != 1) &&
           (c3_c_tmp_size[1] != 1))) {
        emlrtDimSizeImpxCheckR2021b(c3_x_size[1], c3_c_tmp_size[1], &c3_emlrtECI,
          (emlrtConstCTX)c3_sp);
      }

      c3_bv[0] = !c3_tempInds;
      c3_e_trueCount = 0;
      for (c3_n_i = 0; c3_n_i < 1; c3_n_i++) {
        if (c3_bv[0]) {
          c3_e_trueCount++;
        }
      }

      c3_st.site = &c3_b_emlrtRSI;
      if (c3_x_size[1] == c3_c_tmp_size[1]) {
        c3_i71 = c3_x_size[0] * c3_x_size[1];
        c3_x_size[0] = 1;
        c3_f_loop_ub = c3_i71 - 1;
        for (c3_i72 = 0; c3_i72 <= c3_f_loop_ub; c3_i72++) {
          c3_x_data[c3_i72] *= c3_c_tmp_data[c3_i72];
        }
      } else {
        c3_times(chartInstance, c3_x_data, c3_x_size, c3_c_tmp_data,
                 c3_c_tmp_size);
      }

      c3_b_y_size[0] = 1;
      c3_b_y_size[1] = c3_e_trueCount;
      c3_g_loop_ub = c3_e_trueCount - 1;
      for (c3_i73 = 0; c3_i73 <= c3_g_loop_ub; c3_i73++) {
        c3_b_y_data[c3_i73] = c3_b_FNOMIN;
      }

      c3_b_st.site = &c3_d_emlrtRSI;
      c3_c_st.site = &c3_e_emlrtRSI;
      if (c3_x_size[1] == c3_b_y_size[1]) {
        c3_i75 = c3_x_size[0] * c3_x_size[1];
        c3_x_size[0] = 1;
        c3_i_loop_ub = c3_i75 - 1;
        for (c3_i76 = 0; c3_i76 <= c3_i_loop_ub; c3_i76++) {
          c3_x_data[c3_i76] /= c3_b_y_data[c3_i76];
        }
      } else {
        c3_b_rdivide(chartInstance, c3_x_data, c3_x_size, c3_b_y_data,
                     c3_b_y_size);
      }

      c3_st.site = &c3_b_emlrtRSI;
      c3_b_power(chartInstance, &c3_st, c3_x_data, c3_x_size, c3_c_tmp_data,
                 c3_c_tmp_size);
      c3_bv[0] = !c3_tempInds;
      c3_g_trueCount = 0;
      for (c3_q_i = 0; c3_q_i < 1; c3_q_i++) {
        if (c3_bv[0]) {
          c3_g_trueCount++;
        }
      }

      c3_b_y_size[0] = 1;
      c3_b_y_size[1] = c3_g_trueCount;
      c3_k_loop_ub = c3_g_trueCount - 1;
      for (c3_i78 = 0; c3_i78 <= c3_k_loop_ub; c3_i78++) {
        c3_b_y_data[c3_i78] = 4.0 * c3_b_Q_FZ2;
      }

      if ((c3_c_tmp_size[1] != c3_b_y_size[1]) && ((c3_c_tmp_size[1] != 1) &&
           (c3_b_y_size[1] != 1))) {
        emlrtDimSizeImpxCheckR2021b(c3_c_tmp_size[1], c3_b_y_size[1],
          &c3_emlrtECI, (emlrtConstCTX)c3_sp);
      }

      if (c3_c_tmp_size[1] == c3_b_y_size[1]) {
        c3_i79 = c3_c_tmp_size[0] * c3_c_tmp_size[1];
        c3_c_tmp_size[0] = 1;
        c3_l_loop_ub = c3_i79 - 1;
        for (c3_i80 = 0; c3_i80 <= c3_l_loop_ub; c3_i80++) {
          c3_c_tmp_data[c3_i80] -= c3_b_y_data[c3_i80];
        }
      } else {
        c3_b_minus(chartInstance, c3_c_tmp_data, c3_c_tmp_size, c3_b_y_data,
                   c3_b_y_size);
      }

      c3_st.site = &c3_b_emlrtRSI;
      c3_d_sqrt(chartInstance, &c3_st, c3_c_tmp_data, c3_c_tmp_size);
      c3_bv[0] = !c3_tempInds;
      c3_j_trueCount = 0;
      for (c3_u_i = 0; c3_u_i < 1; c3_u_i++) {
        if (c3_bv[0]) {
          c3_j_trueCount++;
        }
      }

      if (c3_j_trueCount != c3_c_tmp_size[1]) {
        emlrtSubAssignSizeCheck1dR2017a(c3_j_trueCount, c3_c_tmp_size[1],
          &c3_b_emlrtECI, (emlrtConstCTX)c3_sp);
      }

      c3_dv1[0] = c3_b_Q_FZ1;
      c3_bv[0] = !c3_tempInds;
      c3_e_partialTrueCount = 0;
      for (c3_w_i = 0; c3_w_i < 1; c3_w_i++) {
        if (c3_bv[0]) {
          c3_dv1[c3_w_i] = c3_c_tmp_data[c3_e_partialTrueCount];
          c3_e_partialTrueCount++;
        }
      }

      c3_b_Q_FZ1 = c3_dv1[0];
    }

    for (c3_i57 = 0; c3_i57 < 4; c3_i57++) {
      c3_Fzo_prime[c3_i57] = c3_lam_Fzo[c3_i57] * c3_b_FNOMIN;
    }

    for (c3_k = 0; c3_k < 4; c3_k++) {
      c3_b_k = c3_k;
      c3_c_x = c3_b_Omega[c3_b_k];
      c3_c_y = muDoubleScalarAbs(c3_c_x);
      c3_Fz[c3_b_k] = c3_c_y;
    }

    for (c3_i58 = 0; c3_i58 < 4; c3_i58++) {
      c3_Vc_prime[c3_i58] = c3_b_Q_FCX * c3_b_Fx_ext[c3_i58] / c3_b_FNOMIN;
    }

    for (c3_c_k = 0; c3_c_k < 4; c3_c_k++) {
      c3_d_k = c3_c_k;
      c3_f_a = c3_Vc_prime[c3_d_k];
      c3_d_y = c3_f_a * c3_f_a;
      c3_e_y[c3_d_k] = c3_d_y;
    }

    for (c3_i59 = 0; c3_i59 < 4; c3_i59++) {
      c3_Vc_prime[c3_i59] = c3_b_Q_FCY * c3_b_Fy_ext[c3_i59] / c3_b_FNOMIN;
    }

    for (c3_e_k = 0; c3_e_k < 4; c3_e_k++) {
      c3_f_k = c3_e_k;
      c3_g_a = c3_Vc_prime[c3_f_k];
      c3_f_y = c3_g_a * c3_g_a;
      c3_SVygamma[c3_f_k] = c3_f_y;
    }

    for (c3_i60 = 0; c3_i60 < 4; c3_i60++) {
      c3_Vc_prime[c3_i60] = c3_b_rhoz[c3_i60] / c3_b_UNLOADED_RADIUS;
    }

    for (c3_g_k = 0; c3_g_k < 4; c3_g_k++) {
      c3_h_k = c3_g_k;
      c3_h_a = c3_Vc_prime[c3_h_k];
      c3_g_y = c3_h_a * c3_h_a;
      c3_SHyphi[c3_h_k] = c3_g_y;
    }

    for (c3_i61 = 0; c3_i61 < 4; c3_i61++) {
      c3_Fz[c3_i61] = (((1.0 + c3_b_Q_V2 * c3_Fz[c3_i61] * c3_b_UNLOADED_RADIUS /
                         c3_b_LONGVL) - c3_e_y[c3_i61]) - c3_SVygamma[c3_i61]) *
        ((c3_b_Q_FZ1 + c3_b_Q_FZ3 * c3_gamma[c3_i61] * c3_gamma[c3_i61]) *
         c3_b_rhoz[c3_i61] / c3_b_UNLOADED_RADIUS + c3_b_Q_FZ2 *
         c3_SHyphi[c3_i61]) * (c3_b_PFZ1 * c3_dpi[c3_i61] + 1.0) *
        c3_Fzo_prime[c3_i61];
    }

    for (c3_i62 = 0; c3_i62 < 4; c3_i62++) {
      c3_Fz_btm[c3_i62] = c3_gamma[c3_i62];
    }

    for (c3_i_k = 0; c3_i_k < 4; c3_i_k++) {
      c3_j_k = c3_i_k;
      c3_d_x = c3_Fz_btm[c3_j_k];
      c3_e_x = c3_d_x;
      c3_e_x = muDoubleScalarCos(c3_e_x);
      c3_Fz_btm[c3_j_k] = c3_e_x;
    }

    c3_c_RIM_RADIUS = c3_b_RIM_RADIUS + c3_b_BOTTOM_OFFST;
    for (c3_i64 = 0; c3_i64 < 4; c3_i64++) {
      c3_Fz_btm[c3_i64] = c3_b_BOTTOM_STIFF * (c3_c_RIM_RADIUS -
        (c3_b_UNLOADED_RADIUS + c3_b_rhoz[c3_i64]) / c3_Fz_btm[c3_i64]);
    }

    for (c3_i65 = 0; c3_i65 < 4; c3_i65++) {
      c3_f_x[c3_i65] = c3_Fz[c3_i65];
    }

    for (c3_k_k = 0; c3_k_k < 4; c3_k_k++) {
      c3_l_k = c3_k_k;
      c3_g_x = c3_f_x[c3_l_k];
      c3_h_y = c3_Fz_btm[c3_l_k];
      c3_h_x = c3_g_x;
      c3_i_y = c3_h_y;
      c3_ex = muDoubleScalarMax(c3_h_x, c3_i_y);
      c3_Fz[c3_l_k] = c3_ex;
    }

    for (c3_i67 = 0; c3_i67 < 4; c3_i67++) {
      c3_patch_b[c3_i67] = c3_b_VERTICAL_STIFFNESS * c3_lam_Cz[c3_i67];
    }

    c3_c_trueCount = 0;
    for (c3_k_i = 0; c3_k_i < 4; c3_k_i++) {
      if (c3_b_rhoz[c3_k_i] > 0.0) {
        c3_c_trueCount++;
      }
    }

    c3_b_tmp_size[0] = c3_c_trueCount;
    c3_b_partialTrueCount = 0;
    for (c3_m_i = 0; c3_m_i < 4; c3_m_i++) {
      if (c3_b_rhoz[c3_m_i] > 0.0) {
        c3_b_tmp_data[c3_b_partialTrueCount] = c3_m_i + 1;
        c3_b_partialTrueCount++;
      }
    }

    c3_st.site = &c3_b_emlrtRSI;
    c3_tmpDrphiVar_size[0] = c3_b_tmp_size[0];
    c3_d_loop_ub = c3_b_tmp_size[0] - 1;
    for (c3_i69 = 0; c3_i69 <= c3_d_loop_ub; c3_i69++) {
      c3_tmpDrphiVar_data[c3_i69] = c3_Fz[c3_b_tmp_data[c3_i69] - 1];
    }

    c3_rhoz_size[0] = c3_b_tmp_size[0];
    c3_e_loop_ub = c3_b_tmp_size[0] - 1;
    for (c3_i70 = 0; c3_i70 <= c3_e_loop_ub; c3_i70++) {
      c3_rhoz_data[c3_i70] = c3_b_rhoz[c3_b_tmp_data[c3_i70] - 1];
    }

    c3_abs(chartInstance, c3_rhoz_data, c3_rhoz_size, c3_y_data, c3_y_size);
    c3_b_st.site = &c3_d_emlrtRSI;
    c3_c_st.site = &c3_e_emlrtRSI;
    c3_b_assertCompatibleDims(chartInstance, &c3_c_st, c3_tmpDrphiVar_size,
      c3_y_size);
    if (c3_tmpDrphiVar_size[0] == c3_y_size[0]) {
      c3_h_loop_ub = c3_tmpDrphiVar_size[0] - 1;
      for (c3_i74 = 0; c3_i74 <= c3_h_loop_ub; c3_i74++) {
        c3_tmpDrphiVar_data[c3_i74] /= c3_y_data[c3_i74];
      }
    } else {
      c3_rdivide(chartInstance, c3_tmpDrphiVar_data, c3_tmpDrphiVar_size,
                 c3_y_data, c3_y_size);
    }

    c3_f_trueCount = 0;
    for (c3_o_i = 0; c3_o_i < 4; c3_o_i++) {
      if (c3_b_rhoz[c3_o_i] > 0.0) {
        c3_f_trueCount++;
      }
    }

    c3_d_tmp_size[0] = c3_f_trueCount;
    c3_c_partialTrueCount = 0;
    for (c3_p_i = 0; c3_p_i < 4; c3_p_i++) {
      if (c3_b_rhoz[c3_p_i] > 0.0) {
        c3_d_tmp_data[c3_c_partialTrueCount] = c3_b_Q_FCY2 * c3_b_Fy_ext[c3_p_i]
          / c3_b_FNOMIN;
        c3_c_partialTrueCount++;
      }
    }

    if ((c3_tmpDrphiVar_size[0] != c3_d_tmp_size[0]) && ((c3_tmpDrphiVar_size[0]
          != 1) && (c3_d_tmp_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(c3_tmpDrphiVar_size[0], c3_d_tmp_size[0],
        &c3_c_emlrtECI, (emlrtConstCTX)c3_sp);
    }

    if (c3_tmpDrphiVar_size[0] == c3_d_tmp_size[0]) {
      c3_j_loop_ub = c3_tmpDrphiVar_size[0] - 1;
      for (c3_i77 = 0; c3_i77 <= c3_j_loop_ub; c3_i77++) {
        c3_tmpDrphiVar_data[c3_i77] += c3_d_tmp_data[c3_i77];
      }
    } else {
      c3_plus(chartInstance, c3_tmpDrphiVar_data, c3_tmpDrphiVar_size,
              c3_d_tmp_data, c3_d_tmp_size);
    }

    c3_h_trueCount = 0;
    for (c3_r_i = 0; c3_r_i < 4; c3_r_i++) {
      if (c3_b_rhoz[c3_r_i] > 0.0) {
        c3_h_trueCount++;
      }
    }

    if ((c3_tmpDrphiVar_size[0] != c3_h_trueCount) && ((c3_tmpDrphiVar_size[0]
          != 1) && (c3_h_trueCount != 1))) {
      emlrtDimSizeImpxCheckR2021b(c3_tmpDrphiVar_size[0], c3_h_trueCount,
        &c3_c_emlrtECI, (emlrtConstCTX)c3_sp);
    }

    c3_i_trueCount = 0;
    for (c3_s_i = 0; c3_s_i < 4; c3_s_i++) {
      if (c3_b_rhoz[c3_s_i] > 0.0) {
        c3_i_trueCount++;
      }
    }

    c3_e_tmp_size[0] = c3_i_trueCount;
    c3_d_partialTrueCount = 0;
    for (c3_t_i = 0; c3_t_i < 4; c3_t_i++) {
      if (c3_b_rhoz[c3_t_i] > 0.0) {
        c3_e_tmp_data[c3_d_partialTrueCount] = c3_t_i + 1;
        c3_d_partialTrueCount++;
      }
    }

    if (c3_tmpDrphiVar_size[0] == c3_e_tmp_size[0]) {
      c3_d_tmp_size[0] = c3_tmpDrphiVar_size[0];
      c3_m_loop_ub = c3_tmpDrphiVar_size[0] - 1;
      for (c3_i81 = 0; c3_i81 <= c3_m_loop_ub; c3_i81++) {
        c3_d_tmp_data[c3_i81] = c3_tmpDrphiVar_data[c3_i81] *
          c3_lam_Cz[c3_e_tmp_data[c3_i81] - 1];
      }
    } else {
      c3_h_binary_expand_op(chartInstance, c3_d_tmp_data, c3_d_tmp_size,
                            c3_tmpDrphiVar_data, c3_tmpDrphiVar_size, c3_lam_Cz,
                            c3_e_tmp_data, c3_e_tmp_size);
    }

    c3_k_trueCount = 0;
    for (c3_v_i = 0; c3_v_i < 4; c3_v_i++) {
      if (c3_b_rhoz[c3_v_i] > 0.0) {
        c3_k_trueCount++;
      }
    }

    if (c3_k_trueCount != c3_d_tmp_size[0]) {
      emlrtSubAssignSizeCheck1dR2017a(c3_k_trueCount, c3_d_tmp_size[0],
        &c3_b_emlrtECI, (emlrtConstCTX)c3_sp);
    }

    c3_f_partialTrueCount = 0;
    for (c3_x_i = 0; c3_x_i < 4; c3_x_i++) {
      if (c3_b_rhoz[c3_x_i] > 0.0) {
        c3_patch_b[c3_x_i] = c3_d_tmp_data[c3_f_partialTrueCount];
        c3_f_partialTrueCount++;
      }
    }

    for (c3_i82 = 0; c3_i82 < 4; c3_i82++) {
      c3_FzUnSat[c3_i82] = c3_Fz[c3_i82];
    }

    for (c3_y_i = 0; c3_y_i < 4; c3_y_i++) {
      if (c3_Fz[c3_y_i] < c3_b_FZMIN) {
        c3_Fz[c3_y_i] = c3_b_FZMIN;
      }
    }

    for (c3_ab_i = 0; c3_ab_i < 4; c3_ab_i++) {
      if (c3_Fz[c3_ab_i] > c3_b_FZMAX) {
        c3_Fz[c3_ab_i] = c3_b_FZMAX;
      }
    }

    for (c3_i83 = 0; c3_i83 < 4; c3_i83++) {
      c3_dfz[c3_i83] = (c3_Fz[c3_i83] - c3_Fzo_prime[c3_i83]) /
        c3_Fzo_prime[c3_i83];
    }

    for (c3_i84 = 0; c3_i84 < 4; c3_i84++) {
      c3_epsilon_gamma[c3_i84] = c3_b_PECP1 * (c3_b_PECP2 * c3_dfz[c3_i84] + 1.0);
    }

    for (c3_i85 = 0; c3_i85 < 4; c3_i85++) {
      c3_Vc_prime[c3_i85] = c3_b_Omega[c3_i85] * c3_b_UNLOADED_RADIUS /
        c3_b_LONGVL;
    }

    for (c3_m_k = 0; c3_m_k < 4; c3_m_k++) {
      c3_n_k = c3_m_k;
      c3_i_a = c3_Vc_prime[c3_n_k];
      c3_j_y = c3_i_a * c3_i_a;
      c3_b_Re[c3_n_k] = c3_j_y;
    }

    for (c3_i86 = 0; c3_i86 < 4; c3_i86++) {
      c3_b_Re[c3_i86] = c3_b_UNLOADED_RADIUS * (c3_b_Q_RE0 + c3_b_Q_V1 *
        c3_b_Re[c3_i86]);
    }

    c3_i_x = c3_b_FNOMIN;
    c3_j_x = c3_i_x;
    for (c3_i87 = 0; c3_i87 < 4; c3_i87++) {
      c3_Fz_btm[c3_i87] = c3_j_x / c3_patch_b[c3_i87];
    }

    for (c3_i88 = 0; c3_i88 < 4; c3_i88++) {
      c3_f_x[c3_i88] = c3_b_BREFF * (c3_FzUnSat[c3_i88] / c3_b_FNOMIN);
    }

    for (c3_o_k = 0; c3_o_k < 4; c3_o_k++) {
      c3_p_k = c3_o_k;
      c3_k_x = c3_f_x[c3_p_k];
      c3_l_x = c3_k_x;
      c3_l_x = muDoubleScalarAtan(c3_l_x);
      c3_f_x[c3_p_k] = c3_l_x;
    }

    for (c3_i89 = 0; c3_i89 < 4; c3_i89++) {
      c3_b_Re[c3_i89] -= c3_Fz_btm[c3_i89] * (c3_b_DREFF * c3_f_x[c3_i89] +
        c3_b_FREFF * (c3_FzUnSat[c3_i89] / c3_b_FNOMIN));
    }

    for (c3_bb_i = 0; c3_bb_i < 4; c3_bb_i++) {
      if (c3_b_Re[c3_bb_i] < 0.001) {
        c3_b_Re[c3_bb_i] = 0.001;
      }
    }

    for (c3_i90 = 0; c3_i90 < 4; c3_i90++) {
      c3_patch_a[c3_i90] = c3_FzUnSat[c3_i90] / (c3_patch_b[c3_i90] *
        c3_b_UNLOADED_RADIUS);
    }

    c3_st.site = &c3_b_emlrtRSI;
    c3_e_sqrt(chartInstance, &c3_st, c3_patch_a);
    for (c3_i91 = 0; c3_i91 < 4; c3_i91++) {
      c3_patch_a[c3_i91] = c3_b_UNLOADED_RADIUS * (c3_b_Q_RA2 *
        (c3_FzUnSat[c3_i91] / (c3_patch_b[c3_i91] * c3_b_UNLOADED_RADIUS)) +
        c3_b_Q_RA1 * c3_patch_a[c3_i91]);
    }

    for (c3_i92 = 0; c3_i92 < 4; c3_i92++) {
      c3_b_FzUnSat[c3_i92] = c3_FzUnSat[c3_i92] / (c3_patch_b[c3_i92] *
        c3_b_UNLOADED_RADIUS);
    }

    c3_st.site = &c3_b_emlrtRSI;
    c3_c_power(chartInstance, &c3_st, c3_b_FzUnSat, c3_Fz_btm);
    for (c3_i93 = 0; c3_i93 < 4; c3_i93++) {
      c3_patch_b[c3_i93] = c3_b_WIDTH * (c3_b_Q_RB2 * (c3_FzUnSat[c3_i93] /
        (c3_patch_b[c3_i93] * c3_b_UNLOADED_RADIUS)) + c3_b_Q_RB1 *
        c3_Fz_btm[c3_i93]);
    }

    for (c3_i94 = 0; c3_i94 < 4; c3_i94++) {
      c3_kappa[c3_i94] = (c3_b_Re[c3_i94] * c3_b_Omega[c3_i94] - c3_b_Vx[c3_i94])
        / c3_Vsy[c3_i94];
    }

    for (c3_cb_i = 0; c3_cb_i < 4; c3_cb_i++) {
      if (c3_kappa[c3_cb_i] < c3_b_KPUMIN) {
        c3_kappa[c3_cb_i] = c3_b_KPUMIN;
      }
    }

    for (c3_db_i = 0; c3_db_i < 4; c3_db_i++) {
      if (c3_kappa[c3_db_i] > c3_b_KPUMAX) {
        c3_kappa[c3_db_i] = c3_b_KPUMAX;
      }
    }

    for (c3_i95 = 0; c3_i95 < 4; c3_i95++) {
      c3_lam_Hx[c3_i95] = c3_kappa[c3_i95] + (c3_b_PHX1 + c3_b_PHX2 *
        c3_dfz[c3_i95]) * c3_lam_Hx[c3_i95];
    }

    for (c3_q_k = 0; c3_q_k < 4; c3_q_k++) {
      c3_r_k = c3_q_k;
      c3_k_y = c3_b_Vy[c3_r_k];
      c3_m_x = c3_Vsy[c3_r_k];
      c3_r = muDoubleScalarAtan2(c3_k_y, c3_m_x);
      c3_alpha[c3_r_k] = c3_r;
    }

    for (c3_eb_i = 0; c3_eb_i < 4; c3_eb_i++) {
      if (c3_alpha[c3_eb_i] < c3_b_ALPMIN) {
        c3_alpha[c3_eb_i] = c3_b_ALPMIN;
      }
    }

    for (c3_fb_i = 0; c3_fb_i < 4; c3_fb_i++) {
      if (c3_alpha[c3_fb_i] > c3_b_ALPMAX) {
        c3_alpha[c3_fb_i] = c3_b_ALPMAX;
      }
    }

    for (c3_i96 = 0; c3_i96 < 4; c3_i96++) {
      c3_gamma_star[c3_i96] = c3_gamma[c3_i96];
    }

    for (c3_s_k = 0; c3_s_k < 4; c3_s_k++) {
      c3_t_k = c3_s_k;
      c3_n_x = c3_gamma_star[c3_t_k];
      c3_o_x = c3_n_x;
      c3_o_x = muDoubleScalarSin(c3_o_x);
      c3_gamma_star[c3_t_k] = c3_o_x;
    }

    for (c3_i97 = 0; c3_i97 < 4; c3_i97++) {
      c3_Fz_btm[c3_i97] = -c3_Vsy[c3_i97] * c3_kappa[c3_i97];
    }

    for (c3_i98 = 0; c3_i98 < 4; c3_i98++) {
      c3_f_x[c3_i98] = c3_alpha[c3_i98];
    }

    for (c3_u_k = 0; c3_u_k < 4; c3_u_k++) {
      c3_v_k = c3_u_k;
      c3_p_x = c3_f_x[c3_v_k];
      c3_q_x = c3_p_x;
      c3_q_x = muDoubleScalarTan(c3_q_x);
      c3_f_x[c3_v_k] = c3_q_x;
    }

    for (c3_i99 = 0; c3_i99 < 4; c3_i99++) {
      c3_Vsy[c3_i99] = -c3_Vsy[c3_i99] * c3_f_x[c3_i99];
    }

    for (c3_w_k = 0; c3_w_k < 4; c3_w_k++) {
      c3_y_k = c3_w_k;
      c3_j_a = c3_Fz_btm[c3_y_k];
      c3_l_y = c3_j_a * c3_j_a;
      c3_Vs[c3_y_k] = c3_l_y;
    }

    for (c3_x_k = 0; c3_x_k < 4; c3_x_k++) {
      c3_ab_k = c3_x_k;
      c3_k_a = c3_Vsy[c3_ab_k];
      c3_m_y = c3_k_a * c3_k_a;
      c3_e_y[c3_ab_k] = c3_m_y;
    }

    for (c3_i100 = 0; c3_i100 < 4; c3_i100++) {
      c3_Vs[c3_i100] += c3_e_y[c3_i100];
    }

    c3_st.site = &c3_b_emlrtRSI;
    c3_e_sqrt(chartInstance, &c3_st, c3_Vs);
    c3_st.site = &c3_b_emlrtRSI;
    c3_div0protect(chartInstance, &c3_st, c3_b_Vx, c3_b_VXLOW, c3_phi_t,
                   c3_Fz_btm);
    for (c3_bb_k = 0; c3_bb_k < 4; c3_bb_k++) {
      c3_db_k = c3_bb_k;
      c3_l_a = c3_b_Vx[c3_db_k];
      c3_n_y = c3_l_a * c3_l_a;
      c3_lam_Cz[c3_db_k] = c3_n_y;
    }

    for (c3_cb_k = 0; c3_cb_k < 4; c3_cb_k++) {
      c3_eb_k = c3_cb_k;
      c3_m_a = c3_Vsy[c3_eb_k];
      c3_o_y = c3_m_a * c3_m_a;
      c3_e_y[c3_eb_k] = c3_o_y;
    }

    for (c3_i101 = 0; c3_i101 < 4; c3_i101++) {
      c3_lam_Cz[c3_i101] += c3_e_y[c3_i101];
    }

    c3_st.site = &c3_b_emlrtRSI;
    c3_e_sqrt(chartInstance, &c3_st, c3_lam_Cz);
    c3_st.site = &c3_b_emlrtRSI;
    c3_div0protect(chartInstance, &c3_st, c3_lam_Cz, c3_b_VXLOW,
                   c3_cosprimealpha, c3_Fz_btm);
    c3_st.site = &c3_b_emlrtRSI;
    c3_b_div0protect(chartInstance, &c3_st, c3_lam_Cz, c3_Vc_prime);
    for (c3_i102 = 0; c3_i102 < 4; c3_i102++) {
      c3_Fz_btm[c3_i102] = c3_b_Re[c3_i102] * c3_b_Omega[c3_i102] -
        c3_b_Vx[c3_i102];
    }

    for (c3_fb_k = 0; c3_fb_k < 4; c3_fb_k++) {
      c3_hb_k = c3_fb_k;
      c3_n_a = c3_Fz_btm[c3_hb_k];
      c3_p_y = c3_n_a * c3_n_a;
      c3_e_y[c3_hb_k] = c3_p_y;
    }

    for (c3_gb_k = 0; c3_gb_k < 4; c3_gb_k++) {
      c3_ib_k = c3_gb_k;
      c3_o_a = c3_Vsy[c3_ib_k];
      c3_q_y = c3_o_a * c3_o_a;
      c3_SVygamma[c3_ib_k] = c3_q_y;
    }

    for (c3_i103 = 0; c3_i103 < 4; c3_i103++) {
      c3_e_y[c3_i103] += c3_SVygamma[c3_i103];
    }

    c3_st.site = &c3_b_emlrtRSI;
    c3_e_sqrt(chartInstance, &c3_st, c3_e_y);
    for (c3_i104 = 0; c3_i104 < 4; c3_i104++) {
      c3_isLowSpeed[c3_i104] = (c3_e_y[c3_i104] < c3_b_VXLOW);
    }

    for (c3_i105 = 0; c3_i105 < 4; c3_i105++) {
      c3_lam_mux[c3_i105] /= c3_lam_muV[c3_i105] * c3_Vs[c3_i105] / c3_b_LONGVL
        + 1.0;
    }

    for (c3_i106 = 0; c3_i106 < 4; c3_i106++) {
      c3_lam_mux_prime[c3_i106] = c3_lam_mux[c3_i106] * 10.0 / (9.0 *
        c3_lam_mux[c3_i106] + 1.0);
    }

    for (c3_jb_k = 0; c3_jb_k < 4; c3_jb_k++) {
      c3_lb_k = c3_jb_k;
      c3_p_a = c3_dpi[c3_lb_k];
      c3_r_y = c3_p_a * c3_p_a;
      c3_mu_x[c3_lb_k] = c3_r_y;
    }

    for (c3_kb_k = 0; c3_kb_k < 4; c3_kb_k++) {
      c3_mb_k = c3_kb_k;
      c3_q_a = c3_gamma[c3_mb_k];
      c3_s_y = c3_q_a * c3_q_a;
      c3_e_y[c3_mb_k] = c3_s_y;
    }

    for (c3_i107 = 0; c3_i107 < 4; c3_i107++) {
      c3_mu_x[c3_i107] = (c3_b_PDX1 + c3_b_PDX2 * c3_dfz[c3_i107]) * ((c3_b_PPX3
        * c3_dpi[c3_i107] + 1.0) + c3_b_PPX4 * c3_mu_x[c3_i107]) * (1.0 -
        c3_b_PDX3 * c3_e_y[c3_i107]) * c3_lam_mux[c3_i107];
    }

    for (c3_i108 = 0; c3_i108 < 4; c3_i108++) {
      c3_lam_muy[c3_i108] /= c3_lam_muV[c3_i108] * c3_Vs[c3_i108] / c3_b_LONGVL
        + 1.0;
    }

    for (c3_i109 = 0; c3_i109 < 4; c3_i109++) {
      c3_lam_muy_prime[c3_i109] = c3_lam_muy[c3_i109] * 10.0 / (9.0 *
        c3_lam_muy[c3_i109] + 1.0);
    }

    for (c3_nb_k = 0; c3_nb_k < 4; c3_nb_k++) {
      c3_pb_k = c3_nb_k;
      c3_r_a = c3_dpi[c3_pb_k];
      c3_t_y = c3_r_a * c3_r_a;
      c3_mu_y[c3_pb_k] = c3_t_y;
    }

    for (c3_ob_k = 0; c3_ob_k < 4; c3_ob_k++) {
      c3_qb_k = c3_ob_k;
      c3_s_a = c3_gamma_star[c3_qb_k];
      c3_u_y = c3_s_a * c3_s_a;
      c3_e_y[c3_qb_k] = c3_u_y;
    }

    for (c3_i110 = 0; c3_i110 < 4; c3_i110++) {
      c3_mu_y[c3_i110] = (c3_b_PDY1 + c3_b_PDY2 * c3_dfz[c3_i110]) * ((c3_b_PPY3
        * c3_dpi[c3_i110] + 1.0) + c3_b_PPY4 * c3_mu_y[c3_i110]) * (1.0 -
        c3_b_PDY3 * c3_e_y[c3_i110]) * c3_lam_muy[c3_i110];
    }

    for (c3_i111 = 0; c3_i111 < 4; c3_i111++) {
      c3_phi_t[c3_i111] = -c3_b_psidot[c3_i111] / c3_phi_t[c3_i111];
    }

    for (c3_i112 = 0; c3_i112 < 4; c3_i112++) {
      c3_f_x[c3_i112] = c3_alpha[c3_i112];
    }

    for (c3_rb_k = 0; c3_rb_k < 4; c3_rb_k++) {
      c3_sb_k = c3_rb_k;
      c3_r_x = c3_f_x[c3_sb_k];
      c3_s_x = c3_r_x;
      c3_s_x = muDoubleScalarCos(c3_s_x);
      c3_f_x[c3_sb_k] = c3_s_x;
    }

    for (c3_i113 = 0; c3_i113 < 4; c3_i113++) {
      c3_phi_t[c3_i113] *= c3_f_x[c3_i113];
    }

    c3_l_trueCount = 0;
    for (c3_gb_i = 0; c3_gb_i < 4; c3_gb_i++) {
      if (c3_isLowSpeed[c3_gb_i]) {
        c3_l_trueCount++;
      }
    }

    c3_f_tmp_size[0] = c3_l_trueCount;
    c3_g_partialTrueCount = 0;
    for (c3_hb_i = 0; c3_hb_i < 4; c3_hb_i++) {
      if (c3_isLowSpeed[c3_hb_i]) {
        c3_f_tmp_data[c3_g_partialTrueCount] = c3_hb_i + 1;
        c3_g_partialTrueCount++;
      }
    }

    c3_Vx_size[0] = c3_f_tmp_size[0];
    c3_n_loop_ub = c3_f_tmp_size[0] - 1;
    for (c3_i114 = 0; c3_i114 <= c3_n_loop_ub; c3_i114++) {
      c3_Vx_data[c3_i114] = c3_b_Vx[c3_f_tmp_data[c3_i114] - 1];
    }

    c3_abs(chartInstance, c3_Vx_data, c3_Vx_size, c3_d_tmp_data, c3_d_tmp_size);
    c3_o_loop_ub = c3_d_tmp_size[0] - 1;
    for (c3_i115 = 0; c3_i115 <= c3_o_loop_ub; c3_i115++) {
      c3_d_tmp_data[c3_i115] /= c3_b_VXLOW;
    }

    c3_m_trueCount = 0;
    for (c3_ib_i = 0; c3_ib_i < 4; c3_ib_i++) {
      if (c3_isLowSpeed[c3_ib_i]) {
        c3_m_trueCount++;
      }
    }

    if ((c3_m_trueCount != c3_d_tmp_size[0]) && ((c3_m_trueCount != 1) &&
         (c3_d_tmp_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(c3_m_trueCount, c3_d_tmp_size[0],
        &c3_c_emlrtECI, (emlrtConstCTX)c3_sp);
    }

    c3_n_trueCount = 0;
    for (c3_jb_i = 0; c3_jb_i < 4; c3_jb_i++) {
      if (c3_isLowSpeed[c3_jb_i]) {
        c3_n_trueCount++;
      }
    }

    c3_g_tmp_size[0] = c3_n_trueCount;
    c3_h_partialTrueCount = 0;
    for (c3_kb_i = 0; c3_kb_i < 4; c3_kb_i++) {
      if (c3_isLowSpeed[c3_kb_i]) {
        c3_g_tmp_data[c3_h_partialTrueCount] = c3_kb_i + 1;
        c3_h_partialTrueCount++;
      }
    }

    if (c3_g_tmp_size[0] == c3_d_tmp_size[0]) {
      c3_tmpDrphiVar_size[0] = c3_g_tmp_size[0];
      c3_p_loop_ub = c3_g_tmp_size[0] - 1;
      for (c3_i116 = 0; c3_i116 <= c3_p_loop_ub; c3_i116++) {
        c3_tmpDrphiVar_data[c3_i116] = c3_phi_t[c3_g_tmp_data[c3_i116] - 1] *
          c3_d_tmp_data[c3_i116];
      }
    } else {
      c3_g_binary_expand_op(chartInstance, c3_tmpDrphiVar_data,
                            c3_tmpDrphiVar_size, c3_phi_t, c3_g_tmp_data,
                            c3_g_tmp_size, c3_d_tmp_data, c3_d_tmp_size);
    }

    c3_o_trueCount = 0;
    for (c3_lb_i = 0; c3_lb_i < 4; c3_lb_i++) {
      if (c3_isLowSpeed[c3_lb_i]) {
        c3_o_trueCount++;
      }
    }

    if (c3_o_trueCount != c3_tmpDrphiVar_size[0]) {
      emlrtSubAssignSizeCheck1dR2017a(c3_o_trueCount, c3_tmpDrphiVar_size[0],
        &c3_b_emlrtECI, (emlrtConstCTX)c3_sp);
    }

    c3_i_partialTrueCount = 0;
    for (c3_mb_i = 0; c3_mb_i < 4; c3_mb_i++) {
      if (c3_isLowSpeed[c3_mb_i]) {
        c3_phi_t[c3_mb_i] = c3_tmpDrphiVar_data[c3_i_partialTrueCount];
        c3_i_partialTrueCount++;
      }
    }

    for (c3_i117 = 0; c3_i117 < 4; c3_i117++) {
      c3_Vc_prime[c3_i117] = 1.0 / c3_Vc_prime[c3_i117];
    }

    for (c3_tb_k = 0; c3_tb_k < 4; c3_tb_k++) {
      c3_ub_k = c3_tb_k;
      c3_t_x = c3_b_Omega[c3_ub_k];
      c3_v_y = muDoubleScalarAbs(c3_t_x);
      c3_e_y[c3_ub_k] = c3_v_y;
    }

    for (c3_i118 = 0; c3_i118 < 4; c3_i118++) {
      c3_f_x[c3_i118] = c3_gamma[c3_i118];
    }

    for (c3_vb_k = 0; c3_vb_k < 4; c3_vb_k++) {
      c3_wb_k = c3_vb_k;
      c3_u_x = c3_f_x[c3_wb_k];
      c3_v_x = c3_u_x;
      c3_v_x = muDoubleScalarSin(c3_v_x);
      c3_f_x[c3_wb_k] = c3_v_x;
    }

    for (c3_i119 = 0; c3_i119 < 4; c3_i119++) {
      c3_Vc_prime[c3_i119] = -c3_Vc_prime[c3_i119] * (c3_b_psidot[c3_i119] -
        (1.0 - c3_epsilon_gamma[c3_i119]) * c3_e_y[c3_i119] * c3_f_x[c3_i119]);
    }

    if (c3_b_turnslip == 1.0) {
      for (c3_xb_k = 0; c3_xb_k < 4; c3_xb_k++) {
        c3_yb_k = c3_xb_k;
        c3_w_x = c3_Vc_prime[c3_yb_k];
        c3_w_y = muDoubleScalarAbs(c3_w_x);
        c3_e_y[c3_yb_k] = c3_w_y;
      }

      for (c3_i121 = 0; c3_i121 < 4; c3_i121++) {
        c3_isLowSpeed[c3_i121] = (c3_e_y[c3_i121] > 0.01);
      }
    } else {
      for (c3_i120 = 0; c3_i120 < 4; c3_i120++) {
        c3_isLowSpeed[c3_i120] = false;
      }
    }

    for (c3_i122 = 0; c3_i122 < 4; c3_i122++) {
      c3_Vs[c3_i122] = c3_b_RHY1 + c3_b_RHY2 * c3_dfz[c3_i122];
    }

    for (c3_i123 = 0; c3_i123 < 4; c3_i123++) {
      c3_Vsy[c3_i123] = c3_b_REY1 + c3_b_REY2 * c3_dfz[c3_i123];
    }

    for (c3_nb_i = 0; c3_nb_i < 4; c3_nb_i++) {
      if (c3_b_REY1 + c3_b_REY2 * c3_dfz[c3_nb_i] > 1.0) {
        c3_Vsy[c3_nb_i] = 1.0;
      }
    }

    for (c3_ac_k = 0; c3_ac_k < 4; c3_ac_k++) {
      c3_bc_k = c3_ac_k;
      c3_t_a = c3_gamma_star[c3_bc_k];
      c3_x_y = c3_t_a * c3_t_a;
      c3_Bykappa[c3_bc_k] = c3_x_y;
    }

    for (c3_i124 = 0; c3_i124 < 4; c3_i124++) {
      c3_f_x[c3_i124] = c3_b_RBY2 * (c3_alpha[c3_i124] - c3_b_RBY3);
    }

    for (c3_cc_k = 0; c3_cc_k < 4; c3_cc_k++) {
      c3_ec_k = c3_cc_k;
      c3_x_x = c3_f_x[c3_ec_k];
      c3_y_x = c3_x_x;
      c3_y_x = muDoubleScalarAtan(c3_y_x);
      c3_f_x[c3_ec_k] = c3_y_x;
    }

    for (c3_dc_k = 0; c3_dc_k < 4; c3_dc_k++) {
      c3_fc_k = c3_dc_k;
      c3_ab_x = c3_f_x[c3_fc_k];
      c3_bb_x = c3_ab_x;
      c3_bb_x = muDoubleScalarCos(c3_bb_x);
      c3_f_x[c3_fc_k] = c3_bb_x;
    }

    for (c3_i125 = 0; c3_i125 < 4; c3_i125++) {
      c3_Bykappa[c3_i125] = (c3_b_RBY1 + c3_b_RBY4 * c3_Bykappa[c3_i125]) *
        c3_f_x[c3_i125] * c3_lam_ykappa[c3_i125];
    }

    for (c3_ob_i = 0; c3_ob_i < 4; c3_ob_i++) {
      if (c3_Bykappa[c3_ob_i] < 0.0) {
        c3_Bykappa[c3_ob_i] = 0.0;
      }
    }

    for (c3_i126 = 0; c3_i126 < 4; c3_i126++) {
      c3_lam_ykappa[c3_i126] = c3_kappa[c3_i126] + c3_Vs[c3_i126];
    }

    for (c3_i127 = 0; c3_i127 < 36; c3_i127++) {
      c3_zeta[c3_i127] = 1.0;
    }

    c3_p_trueCount = 0;
    for (c3_pb_i = 0; c3_pb_i < 4; c3_pb_i++) {
      if (c3_isLowSpeed[c3_pb_i]) {
        c3_p_trueCount++;
      }
    }

    c3_h_tmp_size[0] = c3_p_trueCount;
    c3_j_partialTrueCount = 0;
    for (c3_qb_i = 0; c3_qb_i < 4; c3_qb_i++) {
      if (c3_isLowSpeed[c3_qb_i]) {
        c3_h_tmp_data[c3_j_partialTrueCount] = c3_qb_i + 1;
        c3_j_partialTrueCount++;
      }
    }

    c3_iv[1] = c3_h_tmp_size[0];
    c3_q_loop_ub = c3_iv[1] - 1;
    for (c3_i128 = 0; c3_i128 <= c3_q_loop_ub; c3_i128++) {
      c3_zeta[9 * (c3_h_tmp_data[c3_i128] - 1)] = 0.0;
    }

    if (c3_any(chartInstance, c3_isLowSpeed)) {
      for (c3_i129 = 0; c3_i129 < 4; c3_i129++) {
        c3_Fz_btm[c3_i129] = c3_b_PDXP3 * c3_kappa[c3_i129];
      }

      for (c3_hc_k = 0; c3_hc_k < 4; c3_hc_k++) {
        c3_lc_k = c3_hc_k;
        c3_db_x = c3_Fz_btm[c3_lc_k];
        c3_eb_x = c3_db_x;
        c3_eb_x = muDoubleScalarAtan(c3_eb_x);
        c3_Fz_btm[c3_lc_k] = c3_eb_x;
      }

      for (c3_kc_k = 0; c3_kc_k < 4; c3_kc_k++) {
        c3_nc_k = c3_kc_k;
        c3_fb_x = c3_Fz_btm[c3_nc_k];
        c3_gb_x = c3_fb_x;
        c3_gb_x = muDoubleScalarCos(c3_gb_x);
        c3_Fz_btm[c3_nc_k] = c3_gb_x;
      }

      for (c3_i131 = 0; c3_i131 < 4; c3_i131++) {
        c3_Fz_btm[c3_i131] *= c3_b_PDXP1 * (c3_b_PDXP2 * c3_dfz[c3_i131] + 1.0);
      }

      for (c3_i132 = 0; c3_i132 < 4; c3_i132++) {
        c3_lam_Cz[c3_i132] = c3_alpha[c3_i132];
      }

      for (c3_qc_k = 0; c3_qc_k < 4; c3_qc_k++) {
        c3_sc_k = c3_qc_k;
        c3_jb_x = c3_lam_Cz[c3_sc_k];
        c3_lb_x = c3_jb_x;
        c3_lb_x = muDoubleScalarTan(c3_lb_x);
        c3_lam_Cz[c3_sc_k] = c3_lb_x;
      }

      for (c3_i134 = 0; c3_i134 < 4; c3_i134++) {
        c3_lam_Cz[c3_i134] *= c3_b_PDYP3;
      }

      for (c3_uc_k = 0; c3_uc_k < 4; c3_uc_k++) {
        c3_xc_k = c3_uc_k;
        c3_nb_x = c3_lam_Cz[c3_xc_k];
        c3_ob_x = c3_nb_x;
        c3_ob_x = muDoubleScalarAtan(c3_ob_x);
        c3_lam_Cz[c3_xc_k] = c3_ob_x;
      }

      for (c3_wc_k = 0; c3_wc_k < 4; c3_wc_k++) {
        c3_ad_k = c3_wc_k;
        c3_pb_x = c3_lam_Cz[c3_ad_k];
        c3_qb_x = c3_pb_x;
        c3_qb_x = muDoubleScalarCos(c3_qb_x);
        c3_lam_Cz[c3_ad_k] = c3_qb_x;
      }

      for (c3_i138 = 0; c3_i138 < 4; c3_i138++) {
        c3_lam_Cz[c3_i138] *= c3_b_PDYP1 * (c3_b_PDYP2 * c3_dfz[c3_i138] + 1.0);
      }

      c3_q_trueCount = 0;
      for (c3_rb_i = 0; c3_rb_i < 4; c3_rb_i++) {
        if (c3_isLowSpeed[c3_rb_i]) {
          c3_q_trueCount++;
        }
      }

      c3_i_tmp_size[0] = c3_q_trueCount;
      c3_k_partialTrueCount = 0;
      for (c3_sb_i = 0; c3_sb_i < 4; c3_sb_i++) {
        if (c3_isLowSpeed[c3_sb_i]) {
          c3_i_tmp_data[c3_k_partialTrueCount] = c3_sb_i + 1;
          c3_k_partialTrueCount++;
        }
      }

      c3_d_tmp_size[0] = c3_i_tmp_size[0];
      c3_r_loop_ub = c3_i_tmp_size[0] - 1;
      for (c3_i142 = 0; c3_i142 <= c3_r_loop_ub; c3_i142++) {
        c3_d_tmp_data[c3_i142] = c3_Fz_btm[c3_i_tmp_data[c3_i142] - 1] *
          c3_b_UNLOADED_RADIUS * c3_Vc_prime[c3_i_tmp_data[c3_i142] - 1];
      }

      c3_b_atan(chartInstance, c3_d_tmp_data, c3_d_tmp_size);
      c3_b_cos(chartInstance, c3_d_tmp_data, c3_d_tmp_size);
      c3_r_trueCount = 0;
      for (c3_tb_i = 0; c3_tb_i < 4; c3_tb_i++) {
        if (c3_isLowSpeed[c3_tb_i]) {
          c3_r_trueCount++;
        }
      }

      c3_iv1[0] = 1;
      c3_iv1[1] = c3_r_trueCount;
      emlrtSubAssignSizeCheckR2012b(&c3_iv1[0], 2, &c3_d_tmp_size[0], 1,
        &c3_b_emlrtECI, (void *)c3_sp);
      c3_s_trueCount = 0;
      for (c3_vb_i = 0; c3_vb_i < 4; c3_vb_i++) {
        if (c3_isLowSpeed[c3_vb_i]) {
          c3_s_trueCount++;
        }
      }

      c3_j_tmp_size[0] = c3_s_trueCount;
      c3_l_partialTrueCount = 0;
      for (c3_wb_i = 0; c3_wb_i < 4; c3_wb_i++) {
        if (c3_isLowSpeed[c3_wb_i]) {
          c3_j_tmp_data[c3_l_partialTrueCount] = c3_wb_i + 1;
          c3_l_partialTrueCount++;
        }
      }

      c3_iv2[1] = c3_j_tmp_size[0];
      c3_s_loop_ub = c3_iv2[1] - 1;
      for (c3_i145 = 0; c3_i145 <= c3_s_loop_ub; c3_i145++) {
        c3_zeta[1 + 9 * (c3_j_tmp_data[c3_i145] - 1)] = c3_d_tmp_data[c3_i145];
      }

      c3_t_trueCount = 0;
      for (c3_yb_i = 0; c3_yb_i < 4; c3_yb_i++) {
        if (c3_isLowSpeed[c3_yb_i]) {
          c3_t_trueCount++;
        }
      }

      c3_k_tmp_size[0] = c3_t_trueCount;
      c3_m_partialTrueCount = 0;
      for (c3_ac_i = 0; c3_ac_i < 4; c3_ac_i++) {
        if (c3_isLowSpeed[c3_ac_i]) {
          c3_k_tmp_data[c3_m_partialTrueCount] = c3_ac_i + 1;
          c3_m_partialTrueCount++;
        }
      }

      c3_Vc_prime_size[0] = c3_k_tmp_size[0];
      c3_t_loop_ub = c3_k_tmp_size[0] - 1;
      for (c3_i150 = 0; c3_i150 <= c3_t_loop_ub; c3_i150++) {
        c3_Vc_prime_data[c3_i150] = c3_Vc_prime[c3_k_tmp_data[c3_i150] - 1];
      }

      c3_abs(chartInstance, c3_Vc_prime_data, c3_Vc_prime_size, c3_d_tmp_data,
             c3_d_tmp_size);
      c3_u_loop_ub = c3_d_tmp_size[0] - 1;
      for (c3_i153 = 0; c3_i153 <= c3_u_loop_ub; c3_i153++) {
        c3_d_tmp_data[c3_i153] *= c3_b_UNLOADED_RADIUS;
      }

      c3_u_trueCount = 0;
      for (c3_bc_i = 0; c3_bc_i < 4; c3_bc_i++) {
        if (c3_isLowSpeed[c3_bc_i]) {
          c3_u_trueCount++;
        }
      }

      c3_l_tmp_size[0] = c3_u_trueCount;
      c3_n_partialTrueCount = 0;
      for (c3_cc_i = 0; c3_cc_i < 4; c3_cc_i++) {
        if (c3_isLowSpeed[c3_cc_i]) {
          c3_l_tmp_data[c3_n_partialTrueCount] = c3_cc_i + 1;
          c3_n_partialTrueCount++;
        }
      }

      c3_b_Vc_prime_size[0] = c3_l_tmp_size[0];
      c3_v_loop_ub = c3_l_tmp_size[0] - 1;
      for (c3_i157 = 0; c3_i157 <= c3_v_loop_ub; c3_i157++) {
        c3_b_Vc_prime_data[c3_i157] = c3_Vc_prime[c3_l_tmp_data[c3_i157] - 1];
      }

      c3_abs(chartInstance, c3_b_Vc_prime_data, c3_b_Vc_prime_size,
             c3_tmpDrphiVar_data, c3_tmpDrphiVar_size);
      c3_w_loop_ub = c3_tmpDrphiVar_size[0] - 1;
      for (c3_i159 = 0; c3_i159 <= c3_w_loop_ub; c3_i159++) {
        c3_tmpDrphiVar_data[c3_i159] *= c3_b_UNLOADED_RADIUS;
      }

      c3_st.site = &c3_b_emlrtRSI;
      c3_f_sqrt(chartInstance, &c3_st, c3_tmpDrphiVar_data, c3_tmpDrphiVar_size);
      c3_x_loop_ub = c3_tmpDrphiVar_size[0] - 1;
      for (c3_i162 = 0; c3_i162 <= c3_x_loop_ub; c3_i162++) {
        c3_tmpDrphiVar_data[c3_i162] *= c3_b_PDYP4;
      }

      if ((c3_d_tmp_size[0] != c3_tmpDrphiVar_size[0]) && ((c3_d_tmp_size[0] !=
            1) && (c3_tmpDrphiVar_size[0] != 1))) {
        emlrtDimSizeImpxCheckR2021b(c3_d_tmp_size[0], c3_tmpDrphiVar_size[0],
          &c3_c_emlrtECI, (emlrtConstCTX)c3_sp);
      }

      if (c3_d_tmp_size[0] == c3_tmpDrphiVar_size[0]) {
        c3_bb_loop_ub = c3_d_tmp_size[0] - 1;
        for (c3_i166 = 0; c3_i166 <= c3_bb_loop_ub; c3_i166++) {
          c3_d_tmp_data[c3_i166] += c3_tmpDrphiVar_data[c3_i166];
        }
      } else {
        c3_plus(chartInstance, c3_d_tmp_data, c3_d_tmp_size, c3_tmpDrphiVar_data,
                c3_tmpDrphiVar_size);
      }

      c3_w_trueCount = 0;
      for (c3_ic_i = 0; c3_ic_i < 4; c3_ic_i++) {
        if (c3_isLowSpeed[c3_ic_i]) {
          c3_w_trueCount++;
        }
      }

      if ((c3_w_trueCount != c3_d_tmp_size[0]) && ((c3_w_trueCount != 1) &&
           (c3_d_tmp_size[0] != 1))) {
        emlrtDimSizeImpxCheckR2021b(c3_w_trueCount, c3_d_tmp_size[0],
          &c3_c_emlrtECI, (emlrtConstCTX)c3_sp);
      }

      c3_x_trueCount = 0;
      for (c3_kc_i = 0; c3_kc_i < 4; c3_kc_i++) {
        if (c3_isLowSpeed[c3_kc_i]) {
          c3_x_trueCount++;
        }
      }

      c3_n_tmp_size[0] = c3_x_trueCount;
      c3_p_partialTrueCount = 0;
      for (c3_mc_i = 0; c3_mc_i < 4; c3_mc_i++) {
        if (c3_isLowSpeed[c3_mc_i]) {
          c3_n_tmp_data[c3_p_partialTrueCount] = c3_mc_i + 1;
          c3_p_partialTrueCount++;
        }
      }

      if (c3_n_tmp_size[0] == c3_d_tmp_size[0]) {
        c3_tmpDrphiVar_size[0] = c3_n_tmp_size[0];
        c3_db_loop_ub = c3_n_tmp_size[0] - 1;
        for (c3_i172 = 0; c3_i172 <= c3_db_loop_ub; c3_i172++) {
          c3_tmpDrphiVar_data[c3_i172] = c3_lam_Cz[c3_n_tmp_data[c3_i172] - 1] *
            c3_d_tmp_data[c3_i172];
        }
      } else {
        c3_g_binary_expand_op(chartInstance, c3_tmpDrphiVar_data,
                              c3_tmpDrphiVar_size, c3_lam_Cz, c3_n_tmp_data,
                              c3_n_tmp_size, c3_d_tmp_data, c3_d_tmp_size);
      }

      c3_b_atan(chartInstance, c3_tmpDrphiVar_data, c3_tmpDrphiVar_size);
      c3_b_cos(chartInstance, c3_tmpDrphiVar_data, c3_tmpDrphiVar_size);
      c3_bb_trueCount = 0;
      for (c3_pc_i = 0; c3_pc_i < 4; c3_pc_i++) {
        if (c3_isLowSpeed[c3_pc_i]) {
          c3_bb_trueCount++;
        }
      }

      c3_iv3[0] = 1;
      c3_iv3[1] = c3_bb_trueCount;
      emlrtSubAssignSizeCheckR2012b(&c3_iv3[0], 2, &c3_tmpDrphiVar_size[0], 1,
        &c3_b_emlrtECI, (void *)c3_sp);
      c3_db_trueCount = 0;
      for (c3_rc_i = 0; c3_rc_i < 4; c3_rc_i++) {
        if (c3_isLowSpeed[c3_rc_i]) {
          c3_db_trueCount++;
        }
      }

      c3_p_tmp_size[0] = c3_db_trueCount;
      c3_r_partialTrueCount = 0;
      for (c3_tc_i = 0; c3_tc_i < 4; c3_tc_i++) {
        if (c3_isLowSpeed[c3_tc_i]) {
          c3_p_tmp_data[c3_r_partialTrueCount] = c3_tc_i + 1;
          c3_r_partialTrueCount++;
        }
      }

      c3_iv5[1] = c3_p_tmp_size[0];
      c3_fb_loop_ub = c3_iv5[1] - 1;
      for (c3_i180 = 0; c3_i180 <= c3_fb_loop_ub; c3_i180++) {
        c3_zeta[2 + 9 * (c3_p_tmp_data[c3_i180] - 1)] =
          c3_tmpDrphiVar_data[c3_i180];
      }

      c3_fb_trueCount = 0;
      for (c3_wc_i = 0; c3_wc_i < 4; c3_wc_i++) {
        if (c3_isLowSpeed[c3_wc_i]) {
          c3_fb_trueCount++;
        }
      }

      c3_r_tmp_size[0] = c3_fb_trueCount;
      c3_t_partialTrueCount = 0;
      for (c3_yc_i = 0; c3_yc_i < 4; c3_yc_i++) {
        if (c3_isLowSpeed[c3_yc_i]) {
          c3_r_tmp_data[c3_t_partialTrueCount] = c3_yc_i + 1;
          c3_t_partialTrueCount++;
        }
      }

      c3_st.site = &c3_b_emlrtRSI;
      c3_ab_a = c3_b_UNLOADED_RADIUS;
      c3_b_st.site = &c3_c_emlrtRSI;
      c3_bb_a = c3_ab_a;
      c3_cb_a = c3_bb_a;
      c3_db_a = c3_cb_a;
      c3_fb_y = c3_db_a * c3_db_a;
      c3_c_Vc_prime_size[0] = c3_r_tmp_size[0];
      c3_ib_loop_ub = c3_r_tmp_size[0] - 1;
      for (c3_i187 = 0; c3_i187 <= c3_ib_loop_ub; c3_i187++) {
        c3_c_Vc_prime_data[c3_i187] = c3_Vc_prime[c3_r_tmp_data[c3_i187] - 1];
      }

      c3_st.site = &c3_b_emlrtRSI;
      c3_power(chartInstance, &c3_st, c3_c_Vc_prime_data, c3_c_Vc_prime_size,
               c3_d_tmp_data, c3_d_tmp_size);
      c3_c_PKYP1 = c3_b_PKYP1 * c3_fb_y;
      c3_jb_loop_ub = c3_d_tmp_size[0] - 1;
      for (c3_i191 = 0; c3_i191 <= c3_jb_loop_ub; c3_i191++) {
        c3_d_tmp_data[c3_i191] *= c3_c_PKYP1;
      }

      c3_b_atan(chartInstance, c3_d_tmp_data, c3_d_tmp_size);
      c3_b_cos(chartInstance, c3_d_tmp_data, c3_d_tmp_size);
      c3_jb_trueCount = 0;
      for (c3_gd_i = 0; c3_gd_i < 4; c3_gd_i++) {
        if (c3_isLowSpeed[c3_gd_i]) {
          c3_jb_trueCount++;
        }
      }

      c3_iv8[0] = 1;
      c3_iv8[1] = c3_jb_trueCount;
      emlrtSubAssignSizeCheckR2012b(&c3_iv8[0], 2, &c3_d_tmp_size[0], 1,
        &c3_b_emlrtECI, (void *)c3_sp);
      c3_kb_trueCount = 0;
      for (c3_id_i = 0; c3_id_i < 4; c3_id_i++) {
        if (c3_isLowSpeed[c3_id_i]) {
          c3_kb_trueCount++;
        }
      }

      c3_u_tmp_size[0] = c3_kb_trueCount;
      c3_w_partialTrueCount = 0;
      for (c3_ld_i = 0; c3_ld_i < 4; c3_ld_i++) {
        if (c3_isLowSpeed[c3_ld_i]) {
          c3_u_tmp_data[c3_w_partialTrueCount] = c3_ld_i + 1;
          c3_w_partialTrueCount++;
        }
      }

      c3_iv10[1] = c3_u_tmp_size[0];
      c3_lb_loop_ub = c3_iv10[1] - 1;
      for (c3_i200 = 0; c3_i200 <= c3_lb_loop_ub; c3_i200++) {
        c3_zeta[3 + 9 * (c3_u_tmp_data[c3_i200] - 1)] = c3_d_tmp_data[c3_i200];
      }
    }

    for (c3_gc_k = 0; c3_gc_k < 4; c3_gc_k++) {
      c3_jc_k = c3_gc_k;
      c3_cb_x = c3_gamma_star[c3_jc_k];
      c3_y_y = muDoubleScalarAbs(c3_cb_x);
      c3_Kyalpha[c3_jc_k] = c3_y_y;
    }

    for (c3_ic_k = 0; c3_ic_k < 4; c3_ic_k++) {
      c3_mc_k = c3_ic_k;
      c3_u_a = c3_gamma_star[c3_mc_k];
      c3_ab_y = c3_u_a * c3_u_a;
      c3_e_y[c3_mc_k] = c3_ab_y;
    }

    for (c3_i130 = 0; c3_i130 < 4; c3_i130++) {
      c3_e_y[c3_i130] = c3_Fz[c3_i130] / c3_Fzo_prime[c3_i130] / (c3_b_PKY2 +
        c3_b_PKY5 * c3_e_y[c3_i130]) / (c3_b_PPY2 * c3_dpi[c3_i130] + 1.0);
    }

    for (c3_oc_k = 0; c3_oc_k < 4; c3_oc_k++) {
      c3_pc_k = c3_oc_k;
      c3_hb_x = c3_e_y[c3_pc_k];
      c3_ib_x = c3_hb_x;
      c3_ib_x = muDoubleScalarAtan(c3_ib_x);
      c3_e_y[c3_pc_k] = c3_ib_x;
    }

    for (c3_i133 = 0; c3_i133 < 4; c3_i133++) {
      c3_e_y[c3_i133] *= c3_b_PKY4;
    }

    for (c3_rc_k = 0; c3_rc_k < 4; c3_rc_k++) {
      c3_tc_k = c3_rc_k;
      c3_kb_x = c3_e_y[c3_tc_k];
      c3_mb_x = c3_kb_x;
      c3_mb_x = muDoubleScalarSin(c3_mb_x);
      c3_e_y[c3_tc_k] = c3_mb_x;
    }

    c3_i135 = 0;
    for (c3_i136 = 0; c3_i136 < 4; c3_i136++) {
      c3_Kyalpha[c3_i136] = c3_b_PKY1 * c3_Fzo_prime[c3_i136] * (c3_b_PPY1 *
        c3_dpi[c3_i136] + 1.0) * (1.0 - c3_b_PKY3 * c3_Kyalpha[c3_i136]) *
        c3_e_y[c3_i136] * c3_zeta[c3_i135 + 3] * c3_lam_Kyalpha[c3_i136];
      c3_i135 += 9;
    }

    for (c3_vc_k = 0; c3_vc_k < 4; c3_vc_k++) {
      c3_yc_k = c3_vc_k;
      c3_v_a = c3_gamma_star[c3_yc_k];
      c3_bb_y = c3_v_a * c3_v_a;
      c3_lam_Cz[c3_yc_k] = c3_bb_y;
    }

    for (c3_i137 = 0; c3_i137 < 4; c3_i137++) {
      c3_lam_Cz[c3_i137] = c3_Fz[c3_i137] / c3_Fzo_prime[c3_i137] / (c3_b_PKY2 +
        c3_b_PKY5 * c3_lam_Cz[c3_i137]) / (c3_b_PPY2 * c3_dpi[c3_i137] + 1.0);
    }

    for (c3_bd_k = 0; c3_bd_k < 4; c3_bd_k++) {
      c3_cd_k = c3_bd_k;
      c3_rb_x = c3_lam_Cz[c3_cd_k];
      c3_sb_x = c3_rb_x;
      c3_sb_x = muDoubleScalarAtan(c3_sb_x);
      c3_lam_Cz[c3_cd_k] = c3_sb_x;
    }

    for (c3_i139 = 0; c3_i139 < 4; c3_i139++) {
      c3_lam_Cz[c3_i139] *= c3_b_PKY4;
    }

    for (c3_dd_k = 0; c3_dd_k < 4; c3_dd_k++) {
      c3_ed_k = c3_dd_k;
      c3_tb_x = c3_lam_Cz[c3_ed_k];
      c3_ub_x = c3_tb_x;
      c3_ub_x = muDoubleScalarSin(c3_ub_x);
      c3_lam_Cz[c3_ed_k] = c3_ub_x;
    }

    c3_d = 1.0 - c3_b_PKY3 * 0.0;
    c3_i140 = 0;
    for (c3_i141 = 0; c3_i141 < 4; c3_i141++) {
      c3_lam_Cz[c3_i141] = c3_b_PKY1 * c3_Fzo_prime[c3_i141] * (c3_b_PPY1 *
        c3_dpi[c3_i141] + 1.0) * c3_d * c3_lam_Cz[c3_i141] * c3_zeta[c3_i140 + 3]
        * c3_lam_Kyalpha[c3_i141];
      c3_i140 += 9;
    }

    c3_st.site = &c3_b_emlrtRSI;
    c3_div0protect(chartInstance, &c3_st, c3_Kyalpha, 0.0001, c3_Kyalpha_prime,
                   c3_Fz_btm);
    c3_st.site = &c3_b_emlrtRSI;
    c3_div0protect(chartInstance, &c3_st, c3_lam_Cz, 0.0001, c3_lam_mux,
                   c3_Fz_btm);
    c3_dv2[0] = c3_b_PHYP1;
    c3_bv[0] = (c3_b_PHYP1 < 0.0);
    for (c3_ub_i = 0; c3_ub_i < 1; c3_ub_i++) {
      if (c3_bv[0]) {
        c3_dv2[c3_ub_i] = 0.0;
      }
    }

    c3_CHyphi = c3_dv2[0];
    for (c3_i143 = 0; c3_i143 < 4; c3_i143++) {
      c3_Fz_btm[c3_i143] = c3_b_Vx[c3_i143];
    }

    for (c3_fd_k = 0; c3_fd_k < 4; c3_fd_k++) {
      c3_gd_k = c3_fd_k;
      c3_vb_x = c3_Fz_btm[c3_gd_k];
      c3_wb_x = c3_vb_x;
      c3_wb_x = muDoubleScalarTanh(c3_wb_x);
      c3_Fz_btm[c3_gd_k] = c3_wb_x;
    }

    for (c3_i144 = 0; c3_i144 < 4; c3_i144++) {
      c3_Fz_btm[c3_i144] *= c3_b_PHYP2 + c3_b_PHYP3 * c3_dfz[c3_i144];
    }

    c3_dv3[0] = c3_b_PHYP4;
    c3_bv[0] = (c3_b_PHYP4 > 1.0);
    for (c3_xb_i = 0; c3_xb_i < 1; c3_xb_i++) {
      if (c3_bv[0]) {
        c3_dv3[c3_xb_i] = 1.0;
      }
    }

    c3_EHyphi = c3_dv3[0];
    for (c3_i146 = 0; c3_i146 < 4; c3_i146++) {
      c3_lam_Cz[c3_i146] = c3_Fz[c3_i146] * (c3_b_PKY6 + c3_b_PKY7 *
        c3_dfz[c3_i146]) * (c3_b_PPY5 * c3_dpi[c3_i146] + 1.0) *
        c3_lam_Kygamma[c3_i146] / (1.0 - c3_epsilon_gamma[c3_i146]);
    }

    for (c3_i147 = 0; c3_i147 < 4; c3_i147++) {
      c3_lam_Cz[c3_i147] /= c3_CHyphi * c3_Fz_btm[c3_i147] * c3_lam_mux[c3_i147];
    }

    for (c3_i148 = 0; c3_i148 < 4; c3_i148++) {
      c3_f_x[c3_i148] = c3_b_Vx[c3_i148];
    }

    for (c3_hd_k = 0; c3_hd_k < 4; c3_hd_k++) {
      c3_id_k = c3_hd_k;
      c3_xb_x = c3_f_x[c3_id_k];
      c3_yb_x = c3_xb_x;
      c3_yb_x = muDoubleScalarTanh(c3_yb_x);
      c3_f_x[c3_id_k] = c3_yb_x;
    }

    for (c3_i149 = 0; c3_i149 < 4; c3_i149++) {
      c3_c_UNLOADED_RADIUS[c3_i149] = c3_b_UNLOADED_RADIUS * c3_Vc_prime[c3_i149];
    }

    c3_magicsin(chartInstance, c3_Fz_btm, c3_CHyphi, c3_lam_Cz, c3_EHyphi,
                c3_c_UNLOADED_RADIUS, c3_SHyphi);
    for (c3_i151 = 0; c3_i151 < 4; c3_i151++) {
      c3_SHyphi[c3_i151] *= c3_f_x[c3_i151];
    }

    c3_i152 = 0;
    for (c3_i154 = 0; c3_i154 < 4; c3_i154++) {
      c3_SVygamma[c3_i154] = c3_Fz[c3_i154] * (c3_b_PVY3 + c3_b_PVY4 *
        c3_dfz[c3_i154]) * c3_gamma_star[c3_i154] * c3_zeta[c3_i152 + 2] *
        c3_lam_Kygamma[c3_i154] * c3_lam_muy_prime[c3_i154];
      c3_i152 += 9;
    }

    for (c3_i155 = 0; c3_i155 < 4; c3_i155++) {
      c3_SHy[c3_i155] = 0.0;
    }

    c3_magiccos(chartInstance, c3_b_RCY1, c3_Bykappa, c3_Vsy, c3_Vs, c3_Fz_btm);
    c3_magiccos(chartInstance, c3_b_RCY1, c3_Bykappa, c3_Vsy, c3_lam_ykappa,
                c3_Vs);
    for (c3_i156 = 0; c3_i156 < 4; c3_i156++) {
      c3_Vs[c3_i156] /= c3_Fz_btm[c3_i156];
    }

    for (c3_dc_i = 0; c3_dc_i < 4; c3_dc_i++) {
      if (c3_Vs[c3_dc_i] < 0.0) {
        c3_Vs[c3_dc_i] = 0.0;
      }
    }

    if (c3_any(chartInstance, c3_isLowSpeed)) {
      c3_v_trueCount = 0;
      for (c3_ec_i = 0; c3_ec_i < 4; c3_ec_i++) {
        if (c3_isLowSpeed[c3_ec_i]) {
          c3_v_trueCount++;
        }
      }

      c3_m_tmp_size[0] = c3_v_trueCount;
      c3_o_partialTrueCount = 0;
      for (c3_gc_i = 0; c3_gc_i < 4; c3_gc_i++) {
        if (c3_isLowSpeed[c3_gc_i]) {
          c3_m_tmp_data[c3_o_partialTrueCount] = c3_gc_i + 1;
          c3_o_partialTrueCount++;
        }
      }

      c3_st.site = &c3_b_emlrtRSI;
      c3_tmpDrphiVar_size[0] = c3_m_tmp_size[0];
      c3_y_loop_ub = c3_m_tmp_size[0] - 1;
      for (c3_i163 = 0; c3_i163 <= c3_y_loop_ub; c3_i163++) {
        c3_tmpDrphiVar_data[c3_i163] = c3_SVygamma[c3_m_tmp_data[c3_i163] - 1];
      }

      c3_y_size[0] = c3_m_tmp_size[0];
      c3_ab_loop_ub = c3_m_tmp_size[0] - 1;
      for (c3_i165 = 0; c3_i165 <= c3_ab_loop_ub; c3_i165++) {
        c3_y_data[c3_i165] = c3_Kyalpha_prime[c3_m_tmp_data[c3_i165] - 1];
      }

      c3_b_st.site = &c3_d_emlrtRSI;
      c3_c_st.site = &c3_e_emlrtRSI;
      c3_c_assertCompatibleDims(chartInstance, &c3_c_st, c3_tmpDrphiVar_size,
        c3_y_size);
      c3_cb_loop_ub = c3_tmpDrphiVar_size[0] - 1;
      for (c3_i169 = 0; c3_i169 <= c3_cb_loop_ub; c3_i169++) {
        c3_tmpDrphiVar_data[c3_i169] /= c3_y_data[c3_i169];
      }

      c3_y_trueCount = 0;
      for (c3_lc_i = 0; c3_lc_i < 4; c3_lc_i++) {
        if (c3_isLowSpeed[c3_lc_i]) {
          c3_y_trueCount++;
        }
      }

      if ((c3_y_trueCount != c3_tmpDrphiVar_size[0]) && ((c3_y_trueCount != 1) &&
           (c3_tmpDrphiVar_size[0] != 1))) {
        emlrtDimSizeImpxCheckR2021b(c3_y_trueCount, c3_tmpDrphiVar_size[0],
          &c3_c_emlrtECI, (emlrtConstCTX)c3_sp);
      }

      c3_ab_trueCount = 0;
      for (c3_nc_i = 0; c3_nc_i < 4; c3_nc_i++) {
        if (c3_isLowSpeed[c3_nc_i]) {
          c3_ab_trueCount++;
        }
      }

      c3_o_tmp_size[0] = c3_ab_trueCount;
      c3_q_partialTrueCount = 0;
      for (c3_oc_i = 0; c3_oc_i < 4; c3_oc_i++) {
        if (c3_isLowSpeed[c3_oc_i]) {
          c3_o_tmp_data[c3_q_partialTrueCount] = c3_oc_i + 1;
          c3_q_partialTrueCount++;
        }
      }

      if (c3_o_tmp_size[0] == c3_tmpDrphiVar_size[0]) {
        c3_d_tmp_size[0] = c3_o_tmp_size[0];
        c3_eb_loop_ub = c3_o_tmp_size[0] - 1;
        for (c3_i176 = 0; c3_i176 <= c3_eb_loop_ub; c3_i176++) {
          c3_d_tmp_data[c3_i176] = (c3_SHyphi[c3_o_tmp_data[c3_i176] - 1] + 1.0)
            - c3_tmpDrphiVar_data[c3_i176];
        }
      } else {
        c3_f_binary_expand_op(chartInstance, c3_d_tmp_data, c3_d_tmp_size,
                              c3_SHyphi, c3_o_tmp_data, c3_o_tmp_size,
                              c3_tmpDrphiVar_data, c3_tmpDrphiVar_size);
      }

      c3_cb_trueCount = 0;
      for (c3_qc_i = 0; c3_qc_i < 4; c3_qc_i++) {
        if (c3_isLowSpeed[c3_qc_i]) {
          c3_cb_trueCount++;
        }
      }

      c3_iv4[0] = 1;
      c3_iv4[1] = c3_cb_trueCount;
      emlrtSubAssignSizeCheckR2012b(&c3_iv4[0], 2, &c3_d_tmp_size[0], 1,
        &c3_b_emlrtECI, (void *)c3_sp);
      c3_eb_trueCount = 0;
      for (c3_uc_i = 0; c3_uc_i < 4; c3_uc_i++) {
        if (c3_isLowSpeed[c3_uc_i]) {
          c3_eb_trueCount++;
        }
      }

      c3_q_tmp_size[0] = c3_eb_trueCount;
      c3_s_partialTrueCount = 0;
      for (c3_vc_i = 0; c3_vc_i < 4; c3_vc_i++) {
        if (c3_isLowSpeed[c3_vc_i]) {
          c3_q_tmp_data[c3_s_partialTrueCount] = c3_vc_i + 1;
          c3_s_partialTrueCount++;
        }
      }

      c3_iv6[1] = c3_q_tmp_size[0];
      c3_gb_loop_ub = c3_iv6[1] - 1;
      for (c3_i182 = 0; c3_i182 <= c3_gb_loop_ub; c3_i182++) {
        c3_zeta[4 + 9 * (c3_q_tmp_data[c3_i182] - 1)] = c3_d_tmp_data[c3_i182];
      }

      c3_gb_trueCount = 0;
      for (c3_ad_i = 0; c3_ad_i < 4; c3_ad_i++) {
        if (c3_isLowSpeed[c3_ad_i]) {
          c3_gb_trueCount++;
        }
      }

      c3_s_tmp_size[0] = c3_gb_trueCount;
      c3_u_partialTrueCount = 0;
      for (c3_bd_i = 0; c3_bd_i < 4; c3_bd_i++) {
        if (c3_isLowSpeed[c3_bd_i]) {
          c3_s_tmp_data[c3_u_partialTrueCount] = c3_bd_i + 1;
          c3_u_partialTrueCount++;
        }
      }

      c3_c_QDTP1 = c3_b_QDTP1 * c3_b_UNLOADED_RADIUS;
      c3_d_tmp_size[0] = c3_s_tmp_size[0];
      c3_hb_loop_ub = c3_s_tmp_size[0] - 1;
      for (c3_i186 = 0; c3_i186 <= c3_hb_loop_ub; c3_i186++) {
        c3_d_tmp_data[c3_i186] = c3_c_QDTP1 * c3_Vc_prime[c3_s_tmp_data[c3_i186]
          - 1];
      }

      c3_b_atan(chartInstance, c3_d_tmp_data, c3_d_tmp_size);
      c3_b_cos(chartInstance, c3_d_tmp_data, c3_d_tmp_size);
      c3_hb_trueCount = 0;
      for (c3_ed_i = 0; c3_ed_i < 4; c3_ed_i++) {
        if (c3_isLowSpeed[c3_ed_i]) {
          c3_hb_trueCount++;
        }
      }

      c3_iv7[0] = 1;
      c3_iv7[1] = c3_hb_trueCount;
      emlrtSubAssignSizeCheckR2012b(&c3_iv7[0], 2, &c3_d_tmp_size[0], 1,
        &c3_b_emlrtECI, (void *)c3_sp);
      c3_ib_trueCount = 0;
      for (c3_fd_i = 0; c3_fd_i < 4; c3_fd_i++) {
        if (c3_isLowSpeed[c3_fd_i]) {
          c3_ib_trueCount++;
        }
      }

      c3_t_tmp_size[0] = c3_ib_trueCount;
      c3_v_partialTrueCount = 0;
      for (c3_hd_i = 0; c3_hd_i < 4; c3_hd_i++) {
        if (c3_isLowSpeed[c3_hd_i]) {
          c3_t_tmp_data[c3_v_partialTrueCount] = c3_hd_i + 1;
          c3_v_partialTrueCount++;
        }
      }

      c3_iv9[1] = c3_t_tmp_size[0];
      c3_kb_loop_ub = c3_iv9[1] - 1;
      for (c3_i196 = 0; c3_i196 <= c3_kb_loop_ub; c3_i196++) {
        c3_zeta[5 + 9 * (c3_t_tmp_data[c3_i196] - 1)] = c3_d_tmp_data[c3_i196];
      }

      c3_mb_trueCount = 0;
      for (c3_kd_i = 0; c3_kd_i < 4; c3_kd_i++) {
        if (c3_isLowSpeed[c3_kd_i]) {
          c3_mb_trueCount++;
        }
      }

      c3_w_tmp_size[0] = c3_mb_trueCount;
      c3_y_partialTrueCount = 0;
      for (c3_nd_i = 0; c3_nd_i < 4; c3_nd_i++) {
        if (c3_isLowSpeed[c3_nd_i]) {
          c3_w_tmp_data[c3_y_partialTrueCount] = c3_nd_i + 1;
          c3_y_partialTrueCount++;
        }
      }

      c3_c_QBRP1 = c3_b_QBRP1 * c3_b_UNLOADED_RADIUS;
      c3_d_tmp_size[0] = c3_w_tmp_size[0];
      c3_nb_loop_ub = c3_w_tmp_size[0] - 1;
      for (c3_i202 = 0; c3_i202 <= c3_nb_loop_ub; c3_i202++) {
        c3_d_tmp_data[c3_i202] = c3_c_QBRP1 * c3_Vc_prime[c3_w_tmp_data[c3_i202]
          - 1];
      }

      c3_b_atan(chartInstance, c3_d_tmp_data, c3_d_tmp_size);
      c3_b_cos(chartInstance, c3_d_tmp_data, c3_d_tmp_size);
      c3_pb_trueCount = 0;
      for (c3_sd_i = 0; c3_sd_i < 4; c3_sd_i++) {
        if (c3_isLowSpeed[c3_sd_i]) {
          c3_pb_trueCount++;
        }
      }

      c3_iv11[0] = 1;
      c3_iv11[1] = c3_pb_trueCount;
      emlrtSubAssignSizeCheckR2012b(&c3_iv11[0], 2, &c3_d_tmp_size[0], 1,
        &c3_b_emlrtECI, (void *)c3_sp);
      c3_qb_trueCount = 0;
      for (c3_ud_i = 0; c3_ud_i < 4; c3_ud_i++) {
        if (c3_isLowSpeed[c3_ud_i]) {
          c3_qb_trueCount++;
        }
      }

      c3_y_tmp_size[0] = c3_qb_trueCount;
      c3_bb_partialTrueCount = 0;
      for (c3_vd_i = 0; c3_vd_i < 4; c3_vd_i++) {
        if (c3_isLowSpeed[c3_vd_i]) {
          c3_y_tmp_data[c3_bb_partialTrueCount] = c3_vd_i + 1;
          c3_bb_partialTrueCount++;
        }
      }

      c3_iv12[1] = c3_y_tmp_size[0];
      c3_qb_loop_ub = c3_iv12[1] - 1;
      for (c3_i211 = 0; c3_i211 <= c3_qb_loop_ub; c3_i211++) {
        c3_zeta[6 + 9 * (c3_y_tmp_data[c3_i211] - 1)] = c3_d_tmp_data[c3_i211];
      }

      for (c3_i213 = 0; c3_i213 < 4; c3_i213++) {
        c3_lam_mux[c3_i213] = c3_Fz[c3_i213] / c3_Fzo_prime[c3_i213];
      }

      c3_st.site = &c3_b_emlrtRSI;
      c3_e_sqrt(chartInstance, &c3_st, c3_lam_mux);
      for (c3_i216 = 0; c3_i216 < 4; c3_i216++) {
        c3_lam_mux[c3_i216] = c3_b_QCRP1 * c3_mu_y[c3_i216] *
          c3_b_UNLOADED_RADIUS * c3_Fz[c3_i216] * c3_lam_mux[c3_i216] *
          c3_lam_Mphi[c3_i216];
      }

      for (c3_xd_i = 0; c3_xd_i < 4; c3_xd_i++) {
        if (c3_lam_mux[c3_xd_i] < 0.0) {
          c3_lam_mux[c3_xd_i] = 1.0E-6;
        }
      }

      for (c3_ke_k = 0; c3_ke_k < 4; c3_ke_k++) {
        c3_me_k = c3_ke_k;
        c3_sc_x = c3_phi_t[c3_me_k];
        c3_hb_y = muDoubleScalarAbs(c3_sc_x);
        c3_lam_muV[c3_me_k] = c3_hb_y;
      }

      c3_c_QCRP2 = c3_b_QCRP2 * c3_b_UNLOADED_RADIUS;
      for (c3_i219 = 0; c3_i219 < 4; c3_i219++) {
        c3_lam_muV[c3_i219] *= c3_c_QCRP2;
      }

      for (c3_oe_k = 0; c3_oe_k < 4; c3_oe_k++) {
        c3_pe_k = c3_oe_k;
        c3_vc_x = c3_lam_muV[c3_pe_k];
        c3_wc_x = c3_vc_x;
        c3_wc_x = muDoubleScalarAtan(c3_wc_x);
        c3_lam_muV[c3_pe_k] = c3_wc_x;
      }

      for (c3_i221 = 0; c3_i221 < 4; c3_i221++) {
        c3_lam_muV[c3_i221] = c3_lam_mux[c3_i221] * 2.0 / 3.1415926535897931 *
          c3_lam_muV[c3_i221] * c3_Vs[c3_i221];
      }

      c3_dv4[0] = c3_b_QDRP1;
      c3_bv[0] = (c3_b_QDRP1 < 0.0);
      for (c3_ce_i = 0; c3_ce_i < 1; c3_ce_i++) {
        if (c3_bv[0]) {
          c3_dv4[c3_ce_i] = 0.0;
        }
      }

      c3_CDrphi = c3_dv4[0];
      c3_dv5[0] = c3_b_QDRP2;
      c3_bv[0] = (c3_b_QDRP2 < 0.0);
      for (c3_ee_i = 0; c3_ee_i < 1; c3_ee_i++) {
        if (c3_bv[0]) {
          c3_dv5[c3_ee_i] = 0.0;
        }
      }

      c3_EDrphi = c3_dv5[0];
      c3_bd_x = 1.5707963267948966 * c3_CDrphi;
      c3_cd_x = c3_bd_x;
      c3_cd_x = muDoubleScalarSin(c3_cd_x);
      for (c3_i227 = 0; c3_i227 < 4; c3_i227++) {
        c3_lam_mux[c3_i227] /= c3_cd_x;
      }

      for (c3_bf_k = 0; c3_bf_k < 4; c3_bf_k++) {
        c3_df_k = c3_bf_k;
        c3_hd_x = c3_gamma[c3_df_k];
        c3_kb_y = muDoubleScalarAbs(c3_hd_x);
        c3_Fz_btm[c3_df_k] = c3_kb_y;
      }

      for (c3_i229 = 0; c3_i229 < 4; c3_i229++) {
        c3_Fz_btm[c3_i229] = c3_Fz[c3_i229] * c3_b_UNLOADED_RADIUS * ((c3_b_QDZ8
          + c3_b_QDZ9 * c3_dfz[c3_i229]) + (c3_b_QDZ10 + c3_b_QDZ11 *
          c3_dfz[c3_i229]) * c3_Fz_btm[c3_i229]) * c3_lam_Kzgamma[c3_i229];
      }

      for (c3_i231 = 0; c3_i231 < 4; c3_i231++) {
        c3_f_x[c3_i231] = 1.0 - c3_epsilon_gamma[c3_i231];
      }

      for (c3_gf_k = 0; c3_gf_k < 4; c3_gf_k++) {
        c3_jf_k = c3_gf_k;
        c3_ld_x = c3_f_x[c3_jf_k];
        c3_nd_x = c3_ld_x;
        c3_nd_x = muDoubleScalarSign(c3_nd_x);
        c3_f_x[c3_jf_k] = c3_nd_x;
      }

      for (c3_i232 = 0; c3_i232 < 4; c3_i232++) {
        c3_Fz_btm[c3_i232] /= c3_CDrphi * c3_lam_mux[c3_i232] * (1.0 -
          c3_epsilon_gamma[c3_i232]) + 0.0001 * c3_f_x[c3_i232];
      }

      c3_d_UNLOADED_RADIUS = -c3_b_UNLOADED_RADIUS;
      for (c3_i234 = 0; c3_i234 < 4; c3_i234++) {
        c3_e_UNLOADED_RADIUS[c3_i234] = c3_d_UNLOADED_RADIUS *
          c3_Vc_prime[c3_i234];
      }

      c3_magicsin(chartInstance, c3_lam_mux, c3_CDrphi, c3_Fz_btm, c3_EDrphi,
                  c3_e_UNLOADED_RADIUS, c3_lam_Cz);
      for (c3_i237 = 0; c3_i237 < 4; c3_i237++) {
        c3_Fz_btm[c3_i237] = c3_lam_Cz[c3_i237];
      }

      for (c3_lf_k = 0; c3_lf_k < 4; c3_lf_k++) {
        c3_mf_k = c3_lf_k;
        c3_pd_x = c3_Fz_btm[c3_mf_k];
        c3_qd_x = c3_pd_x;
        c3_qd_x = muDoubleScalarSign(c3_qd_x);
        c3_Fz_btm[c3_mf_k] = c3_qd_x;
      }

      for (c3_je_i = 0; c3_je_i < 4; c3_je_i++) {
        if (c3_Fz_btm[c3_je_i] == 0.0) {
          c3_Fz_btm[c3_je_i] = 1.0;
        }
      }

      c3_xb_trueCount = 0;
      for (c3_le_i = 0; c3_le_i < 4; c3_le_i++) {
        if (c3_isLowSpeed[c3_le_i]) {
          c3_xb_trueCount++;
        }
      }

      c3_fb_tmp_size[0] = c3_xb_trueCount;
      c3_gb_partialTrueCount = 0;
      for (c3_me_i = 0; c3_me_i < 4; c3_me_i++) {
        if (c3_isLowSpeed[c3_me_i]) {
          c3_db_tmp_data[c3_gb_partialTrueCount] = c3_me_i + 1;
          c3_gb_partialTrueCount++;
        }
      }

      c3_lam_Cz_size[0] = c3_fb_tmp_size[0];
      c3_vb_loop_ub = c3_fb_tmp_size[0] - 1;
      for (c3_i243 = 0; c3_i243 <= c3_vb_loop_ub; c3_i243++) {
        c3_lam_Cz_data[c3_i243] = c3_lam_Cz[c3_db_tmp_data[c3_i243] - 1];
      }

      c3_abs(chartInstance, c3_lam_Cz_data, c3_lam_Cz_size, c3_d_tmp_data,
             c3_d_tmp_size);
      c3_wb_loop_ub = c3_d_tmp_size[0] - 1;
      for (c3_i244 = 0; c3_i244 <= c3_wb_loop_ub; c3_i244++) {
        c3_d_tmp_data[c3_i244] = -c3_d_tmp_data[c3_i244];
      }

      c3_yb_trueCount = 0;
      for (c3_pe_i = 0; c3_pe_i < 4; c3_pe_i++) {
        if (c3_isLowSpeed[c3_pe_i]) {
          c3_yb_trueCount++;
        }
      }

      if ((c3_d_tmp_size[0] != c3_yb_trueCount) && ((c3_d_tmp_size[0] != 1) &&
           (c3_yb_trueCount != 1))) {
        emlrtDimSizeImpxCheckR2021b(c3_d_tmp_size[0], c3_yb_trueCount,
          &c3_c_emlrtECI, (emlrtConstCTX)c3_sp);
      }

      c3_ac_trueCount = 0;
      for (c3_qe_i = 0; c3_qe_i < 4; c3_qe_i++) {
        if (c3_isLowSpeed[c3_qe_i]) {
          c3_ac_trueCount++;
        }
      }

      c3_gb_tmp_size[0] = c3_ac_trueCount;
      c3_hb_partialTrueCount = 0;
      for (c3_re_i = 0; c3_re_i < 4; c3_re_i++) {
        if (c3_isLowSpeed[c3_re_i]) {
          c3_eb_tmp_data[c3_hb_partialTrueCount] = c3_re_i + 1;
          c3_hb_partialTrueCount++;
        }
      }

      c3_st.site = &c3_b_emlrtRSI;
      c3_tmpDrphiVar_size[0] = c3_gb_tmp_size[0];
      c3_xb_loop_ub = c3_gb_tmp_size[0] - 1;
      for (c3_i249 = 0; c3_i249 <= c3_xb_loop_ub; c3_i249++) {
        c3_tmpDrphiVar_data[c3_i249] = c3_lam_muV[c3_eb_tmp_data[c3_i249] - 1];
      }

      if (c3_d_tmp_size[0] == c3_gb_tmp_size[0]) {
        c3_y_size[0] = c3_d_tmp_size[0];
        c3_yb_loop_ub = c3_d_tmp_size[0] - 1;
        for (c3_i251 = 0; c3_i251 <= c3_yb_loop_ub; c3_i251++) {
          c3_y_data[c3_i251] = c3_d_tmp_data[c3_i251] + 0.0001 *
            c3_Fz_btm[c3_eb_tmp_data[c3_i251] - 1];
        }
      } else {
        c3_e_binary_expand_op(chartInstance, c3_y_data, c3_y_size, c3_d_tmp_data,
                              c3_d_tmp_size, c3_Fz_btm, c3_eb_tmp_data,
                              c3_gb_tmp_size);
      }

      c3_b_st.site = &c3_d_emlrtRSI;
      c3_c_st.site = &c3_e_emlrtRSI;
      c3_b_assertCompatibleDims(chartInstance, &c3_c_st, c3_tmpDrphiVar_size,
        c3_y_size);
      if (c3_tmpDrphiVar_size[0] == c3_y_size[0]) {
        c3_ac_loop_ub = c3_tmpDrphiVar_size[0] - 1;
        for (c3_i253 = 0; c3_i253 <= c3_ac_loop_ub; c3_i253++) {
          c3_tmpDrphiVar_data[c3_i253] /= c3_y_data[c3_i253];
        }
      } else {
        c3_rdivide(chartInstance, c3_tmpDrphiVar_data, c3_tmpDrphiVar_size,
                   c3_y_data, c3_y_size);
      }

      c3_end = c3_tmpDrphiVar_size[0] - 1;
      for (c3_te_i = 0; c3_te_i <= c3_end; c3_te_i++) {
        if (c3_tmpDrphiVar_data[c3_te_i] > 1.0) {
          c3_i257 = c3_te_i + 1;
          if ((c3_i257 < 1) || (c3_i257 > c3_tmpDrphiVar_size[0])) {
            emlrtDynamicBoundsCheckR2012b(c3_i257, 1, c3_tmpDrphiVar_size[0],
              &c3_emlrtBCI, (emlrtConstCTX)c3_sp);
          }

          c3_tmpDrphiVar_data[c3_i257 - 1] = 1.0;
        }
      }

      c3_b_end = c3_tmpDrphiVar_size[0] - 1;
      for (c3_ue_i = 0; c3_ue_i <= c3_b_end; c3_ue_i++) {
        if (c3_tmpDrphiVar_data[c3_ue_i] < -1.0) {
          c3_i260 = c3_ue_i + 1;
          if ((c3_i260 < 1) || (c3_i260 > c3_tmpDrphiVar_size[0])) {
            emlrtDynamicBoundsCheckR2012b(c3_i260, 1, c3_tmpDrphiVar_size[0],
              &c3_emlrtBCI, (emlrtConstCTX)c3_sp);
          }

          c3_tmpDrphiVar_data[c3_i260 - 1] = -1.0;
        }
      }

      c3_st.site = &c3_b_emlrtRSI;
      c3_b_acos(chartInstance, &c3_st, c3_tmpDrphiVar_data, c3_tmpDrphiVar_size);
      c3_bc_loop_ub = c3_tmpDrphiVar_size[0] - 1;
      for (c3_i262 = 0; c3_i262 <= c3_bc_loop_ub; c3_i262++) {
        c3_tmpDrphiVar_data[c3_i262] *= 0.63661977236758138;
      }

      c3_bc_trueCount = 0;
      for (c3_ve_i = 0; c3_ve_i < 4; c3_ve_i++) {
        if (c3_isLowSpeed[c3_ve_i]) {
          c3_bc_trueCount++;
        }
      }

      c3_iv13[0] = 1;
      c3_iv13[1] = c3_bc_trueCount;
      emlrtSubAssignSizeCheckR2012b(&c3_iv13[0], 2, &c3_tmpDrphiVar_size[0], 1,
        &c3_b_emlrtECI, (void *)c3_sp);
      c3_cc_trueCount = 0;
      for (c3_we_i = 0; c3_we_i < 4; c3_we_i++) {
        if (c3_isLowSpeed[c3_we_i]) {
          c3_cc_trueCount++;
        }
      }

      c3_hb_tmp_size[0] = c3_cc_trueCount;
      c3_ib_partialTrueCount = 0;
      for (c3_xe_i = 0; c3_xe_i < 4; c3_xe_i++) {
        if (c3_isLowSpeed[c3_xe_i]) {
          c3_fb_tmp_data[c3_ib_partialTrueCount] = c3_xe_i + 1;
          c3_ib_partialTrueCount++;
        }
      }

      c3_iv14[1] = c3_hb_tmp_size[0];
      c3_cc_loop_ub = c3_iv14[1] - 1;
      for (c3_i266 = 0; c3_i266 <= c3_cc_loop_ub; c3_i266++) {
        c3_zeta[7 + 9 * (c3_fb_tmp_data[c3_i266] - 1)] =
          c3_tmpDrphiVar_data[c3_i266];
      }

      c3_dc_trueCount = 0;
      for (c3_ye_i = 0; c3_ye_i < 4; c3_ye_i++) {
        if (c3_isLowSpeed[c3_ye_i]) {
          c3_dc_trueCount++;
        }
      }

      c3_iv15[0] = 1;
      c3_iv15[1] = c3_dc_trueCount;
      c3_ec_trueCount[0] = c3_dc_trueCount;
      emlrtSubAssignSizeCheckR2012b(&c3_iv15[0], 2, &c3_ec_trueCount[0], 1,
        &c3_b_emlrtECI, (void *)c3_sp);
      c3_fc_trueCount = 0;
      for (c3_af_i = 0; c3_af_i < 4; c3_af_i++) {
        if (c3_isLowSpeed[c3_af_i]) {
          c3_fc_trueCount++;
        }
      }

      c3_ib_tmp_size[0] = c3_fc_trueCount;
      c3_jb_partialTrueCount = 0;
      for (c3_bf_i = 0; c3_bf_i < 4; c3_bf_i++) {
        if (c3_isLowSpeed[c3_bf_i]) {
          c3_gb_tmp_data[c3_jb_partialTrueCount] = c3_bf_i + 1;
          c3_jb_partialTrueCount++;
        }
      }

      c3_iv16[1] = c3_ib_tmp_size[0];
      c3_dc_loop_ub = c3_iv16[1] - 1;
      for (c3_i271 = 0; c3_i271 <= c3_dc_loop_ub; c3_i271++) {
        c3_zeta[8 + 9 * (c3_gb_tmp_data[c3_i271] - 1)] =
          c3_lam_Cz[c3_gb_tmp_data[c3_i271] - 1] + 1.0;
      }

      c3_gc_trueCount = 0;
      for (c3_cf_i = 0; c3_cf_i < 4; c3_cf_i++) {
        if (c3_isLowSpeed[c3_cf_i]) {
          c3_gc_trueCount++;
        }
      }

      c3_jb_tmp_size[0] = c3_gc_trueCount;
      c3_kb_partialTrueCount = 0;
      for (c3_df_i = 0; c3_df_i < 4; c3_df_i++) {
        if (c3_isLowSpeed[c3_df_i]) {
          c3_hb_tmp_data[c3_kb_partialTrueCount] = (c3_b_PHY1 + c3_b_PHY2 *
            c3_dfz[c3_df_i]) * c3_lam_Hy[c3_df_i];
          c3_kb_partialTrueCount++;
        }
      }

      c3_hc_trueCount = 0;
      for (c3_ef_i = 0; c3_ef_i < 4; c3_ef_i++) {
        if (c3_isLowSpeed[c3_ef_i]) {
          c3_hc_trueCount++;
        }
      }

      if ((c3_jb_tmp_size[0] != c3_hc_trueCount) && ((c3_jb_tmp_size[0] != 1) &&
           (c3_hc_trueCount != 1))) {
        emlrtDimSizeImpxCheckR2021b(c3_jb_tmp_size[0], c3_hc_trueCount,
          &c3_c_emlrtECI, (emlrtConstCTX)c3_sp);
      }

      c3_ic_trueCount = 0;
      for (c3_ff_i = 0; c3_ff_i < 4; c3_ff_i++) {
        if (c3_isLowSpeed[c3_ff_i]) {
          c3_ic_trueCount++;
        }
      }

      c3_kb_tmp_size[0] = c3_ic_trueCount;
      c3_lb_partialTrueCount = 0;
      for (c3_gf_i = 0; c3_gf_i < 4; c3_gf_i++) {
        if (c3_isLowSpeed[c3_gf_i]) {
          c3_ib_tmp_data[c3_lb_partialTrueCount] = c3_gf_i + 1;
          c3_lb_partialTrueCount++;
        }
      }

      if (c3_jb_tmp_size[0] == c3_kb_tmp_size[0]) {
        c3_d_tmp_size[0] = c3_jb_tmp_size[0];
        c3_ec_loop_ub = c3_jb_tmp_size[0] - 1;
        for (c3_i280 = 0; c3_i280 <= c3_ec_loop_ub; c3_i280++) {
          c3_d_tmp_data[c3_i280] = c3_hb_tmp_data[c3_i280] +
            c3_SHyphi[c3_ib_tmp_data[c3_i280] - 1];
        }
      } else {
        c3_d_binary_expand_op(chartInstance, c3_d_tmp_data, c3_d_tmp_size,
                              c3_hb_tmp_data, c3_jb_tmp_size, c3_SHyphi,
                              c3_ib_tmp_data, c3_kb_tmp_size);
      }

      c3_jc_trueCount = 0;
      for (c3_hf_i = 0; c3_hf_i < 4; c3_hf_i++) {
        if (c3_isLowSpeed[c3_hf_i]) {
          c3_jc_trueCount++;
        }
      }

      c3_lb_tmp_size[0] = c3_jc_trueCount;
      c3_mb_partialTrueCount = 0;
      for (c3_if_i = 0; c3_if_i < 4; c3_if_i++) {
        if (c3_isLowSpeed[c3_if_i]) {
          c3_jb_tmp_data[c3_mb_partialTrueCount] = c3_if_i + 1;
          c3_mb_partialTrueCount++;
        }
      }

      c3_st.site = &c3_b_emlrtRSI;
      c3_tmpDrphiVar_size[0] = c3_lb_tmp_size[0];
      c3_fc_loop_ub = c3_lb_tmp_size[0] - 1;
      for (c3_i284 = 0; c3_i284 <= c3_fc_loop_ub; c3_i284++) {
        c3_tmpDrphiVar_data[c3_i284] = c3_SVygamma[c3_jb_tmp_data[c3_i284] - 1];
      }

      c3_y_size[0] = c3_lb_tmp_size[0];
      c3_gc_loop_ub = c3_lb_tmp_size[0] - 1;
      for (c3_i286 = 0; c3_i286 <= c3_gc_loop_ub; c3_i286++) {
        c3_y_data[c3_i286] = c3_Kyalpha_prime[c3_jb_tmp_data[c3_i286] - 1];
      }

      c3_b_st.site = &c3_d_emlrtRSI;
      c3_c_st.site = &c3_e_emlrtRSI;
      c3_c_assertCompatibleDims(chartInstance, &c3_c_st, c3_tmpDrphiVar_size,
        c3_y_size);
      c3_hc_loop_ub = c3_tmpDrphiVar_size[0] - 1;
      for (c3_i288 = 0; c3_i288 <= c3_hc_loop_ub; c3_i288++) {
        c3_tmpDrphiVar_data[c3_i288] /= c3_y_data[c3_i288];
      }

      if ((c3_d_tmp_size[0] != c3_tmpDrphiVar_size[0]) && ((c3_d_tmp_size[0] !=
            1) && (c3_tmpDrphiVar_size[0] != 1))) {
        emlrtDimSizeImpxCheckR2021b(c3_d_tmp_size[0], c3_tmpDrphiVar_size[0],
          &c3_c_emlrtECI, (emlrtConstCTX)c3_sp);
      }

      if (c3_d_tmp_size[0] == c3_tmpDrphiVar_size[0]) {
        c3_ic_loop_ub = c3_d_tmp_size[0] - 1;
        for (c3_i289 = 0; c3_i289 <= c3_ic_loop_ub; c3_i289++) {
          c3_d_tmp_data[c3_i289] -= c3_tmpDrphiVar_data[c3_i289];
        }
      } else {
        c3_minus(chartInstance, c3_d_tmp_data, c3_d_tmp_size,
                 c3_tmpDrphiVar_data, c3_tmpDrphiVar_size);
      }

      c3_kc_trueCount = 0;
      for (c3_jf_i = 0; c3_jf_i < 4; c3_jf_i++) {
        if (c3_isLowSpeed[c3_jf_i]) {
          c3_kc_trueCount++;
        }
      }

      if (c3_kc_trueCount != c3_d_tmp_size[0]) {
        emlrtSubAssignSizeCheck1dR2017a(c3_kc_trueCount, c3_d_tmp_size[0],
          &c3_b_emlrtECI, (emlrtConstCTX)c3_sp);
      }

      c3_nb_partialTrueCount = 0;
      for (c3_kf_i = 0; c3_kf_i < 4; c3_kf_i++) {
        if (c3_isLowSpeed[c3_kf_i]) {
          c3_SHy[c3_kf_i] = c3_d_tmp_data[c3_nb_partialTrueCount];
          c3_nb_partialTrueCount++;
        }
      }
    }

    for (c3_i158 = 0; c3_i158 < 4; c3_i158++) {
      c3_Vsy[c3_i158] = c3_b_PCX1 * c3_lam_Cx[c3_i158];
    }

    for (c3_fc_i = 0; c3_fc_i < 4; c3_fc_i++) {
      if (c3_b_PCX1 * c3_lam_Cx[c3_fc_i] < 0.0) {
        c3_Vsy[c3_fc_i] = 0.0;
      }
    }

    c3_i160 = 0;
    for (c3_i161 = 0; c3_i161 < 4; c3_i161++) {
      c3_mu_x[c3_i161] = c3_mu_x[c3_i161] * c3_Fz[c3_i161] * c3_zeta[c3_i160 + 1];
      c3_i160 += 9;
    }

    for (c3_hc_i = 0; c3_hc_i < 4; c3_hc_i++) {
      if (c3_mu_x[c3_hc_i] < 0.0) {
        c3_mu_x[c3_hc_i] = 0.0;
      }
    }

    for (c3_jd_k = 0; c3_jd_k < 4; c3_jd_k++) {
      c3_kd_k = c3_jd_k;
      c3_w_a = c3_dfz[c3_kd_k];
      c3_cb_y = c3_w_a * c3_w_a;
      c3_SHyphi[c3_kd_k] = c3_cb_y;
    }

    for (c3_i164 = 0; c3_i164 < 4; c3_i164++) {
      c3_f_x[c3_i164] = 10.0 * c3_lam_Hx[c3_i164];
    }

    for (c3_ld_k = 0; c3_ld_k < 4; c3_ld_k++) {
      c3_md_k = c3_ld_k;
      c3_ac_x = c3_f_x[c3_md_k];
      c3_bc_x = c3_ac_x;
      c3_bc_x = muDoubleScalarTanh(c3_bc_x);
      c3_f_x[c3_md_k] = c3_bc_x;
    }

    for (c3_i167 = 0; c3_i167 < 4; c3_i167++) {
      c3_SHyphi[c3_i167] = ((c3_b_PEX1 + c3_b_PEX2 * c3_dfz[c3_i167]) +
                            c3_b_PEX3 * c3_SHyphi[c3_i167]) * (1.0 - c3_b_PEX4 *
        c3_f_x[c3_i167]) * c3_lam_Ex[c3_i167];
    }

    for (c3_jc_i = 0; c3_jc_i < 4; c3_jc_i++) {
      if (c3_SHyphi[c3_jc_i] > 1.0) {
        c3_SHyphi[c3_jc_i] = 1.0;
      }
    }

    for (c3_i168 = 0; c3_i168 < 4; c3_i168++) {
      c3_phi_t[c3_i168] = c3_b_PKX3 * c3_dfz[c3_i168];
    }

    for (c3_nd_k = 0; c3_nd_k < 4; c3_nd_k++) {
      c3_pd_k = c3_nd_k;
      c3_cc_x = c3_phi_t[c3_pd_k];
      c3_dc_x = c3_cc_x;
      c3_dc_x = muDoubleScalarExp(c3_dc_x);
      c3_phi_t[c3_pd_k] = c3_dc_x;
    }

    for (c3_od_k = 0; c3_od_k < 4; c3_od_k++) {
      c3_qd_k = c3_od_k;
      c3_x_a = c3_dpi[c3_qd_k];
      c3_db_y = c3_x_a * c3_x_a;
      c3_e_y[c3_qd_k] = c3_db_y;
    }

    for (c3_i170 = 0; c3_i170 < 4; c3_i170++) {
      c3_phi_t[c3_i170] = c3_Fz[c3_i170] * (c3_b_PKX1 + c3_b_PKX2 *
        c3_dfz[c3_i170]) * c3_phi_t[c3_i170] * ((c3_b_PPX1 * c3_dpi[c3_i170] +
        1.0) + c3_b_PPX2 * c3_e_y[c3_i170]) * c3_lam_Kxkappa[c3_i170];
    }

    for (c3_i171 = 0; c3_i171 < 4; c3_i171++) {
      c3_b_Vsy[c3_i171] = c3_Vsy[c3_i171] * c3_mu_x[c3_i171];
    }

    c3_st.site = &c3_b_emlrtRSI;
    c3_div0protect(chartInstance, &c3_st, c3_b_Vsy, 0.0001, c3_lam_Cz, c3_Fz_btm);
    for (c3_i173 = 0; c3_i173 < 4; c3_i173++) {
      c3_lam_Cz[c3_i173] = c3_phi_t[c3_i173] / c3_lam_Cz[c3_i173];
    }

    c3_i174 = 0;
    for (c3_i175 = 0; c3_i175 < 4; c3_i175++) {
      c3_lam_mux_prime[c3_i175] = c3_Fz[c3_i175] * (c3_b_PVX1 + c3_b_PVX2 *
        c3_dfz[c3_i175]) * c3_lam_mux_prime[c3_i175] * c3_lam_Vx[c3_i175] *
        c3_zeta[c3_i174 + 1];
      c3_i174 += 9;
    }

    c3_b_magicsin(chartInstance, c3_mu_x, c3_Vsy, c3_lam_Cz, c3_SHyphi,
                  c3_lam_Hx, c3_b_Fx);
    for (c3_i177 = 0; c3_i177 < 4; c3_i177++) {
      c3_b_Fx[c3_i177] += c3_lam_mux_prime[c3_i177];
    }

    for (c3_i178 = 0; c3_i178 < 4; c3_i178++) {
      c3_lam_mux[c3_i178] = c3_b_REX1 + c3_b_REX2 * c3_dfz[c3_i178];
    }

    for (c3_sc_i = 0; c3_sc_i < 4; c3_sc_i++) {
      if (c3_b_REX1 + c3_b_REX2 * c3_dfz[c3_sc_i] > 1.0) {
        c3_lam_mux[c3_sc_i] = 1.0;
      }
    }

    for (c3_rd_k = 0; c3_rd_k < 4; c3_rd_k++) {
      c3_sd_k = c3_rd_k;
      c3_y_a = c3_gamma_star[c3_sd_k];
      c3_eb_y = c3_y_a * c3_y_a;
      c3_lam_muV[c3_sd_k] = c3_eb_y;
    }

    for (c3_i179 = 0; c3_i179 < 4; c3_i179++) {
      c3_f_x[c3_i179] = c3_b_RBX2 * c3_kappa[c3_i179];
    }

    for (c3_td_k = 0; c3_td_k < 4; c3_td_k++) {
      c3_vd_k = c3_td_k;
      c3_ec_x = c3_f_x[c3_vd_k];
      c3_fc_x = c3_ec_x;
      c3_fc_x = muDoubleScalarAtan(c3_fc_x);
      c3_f_x[c3_vd_k] = c3_fc_x;
    }

    for (c3_ud_k = 0; c3_ud_k < 4; c3_ud_k++) {
      c3_wd_k = c3_ud_k;
      c3_gc_x = c3_f_x[c3_wd_k];
      c3_hc_x = c3_gc_x;
      c3_hc_x = muDoubleScalarCos(c3_hc_x);
      c3_f_x[c3_wd_k] = c3_hc_x;
    }

    for (c3_i181 = 0; c3_i181 < 4; c3_i181++) {
      c3_lam_muV[c3_i181] = (c3_b_RBX1 + c3_b_RBX3 * c3_lam_muV[c3_i181]) *
        c3_f_x[c3_i181] * c3_lam_xalpha[c3_i181];
    }

    for (c3_xc_i = 0; c3_xc_i < 4; c3_xc_i++) {
      if (c3_lam_muV[c3_xc_i] < 0.0) {
        c3_lam_muV[c3_xc_i] = 0.0;
      }
    }

    for (c3_i183 = 0; c3_i183 < 4; c3_i183++) {
      c3_Fz_btm[c3_i183] = c3_alpha[c3_i183] + c3_b_RHX1;
    }

    c3_magiccos(chartInstance, c3_b_RCX1, c3_lam_muV, c3_lam_mux, c3_Fz_btm,
                c3_lam_Cz);
    c3_b_magiccos(chartInstance, c3_b_RCX1, c3_lam_muV, c3_lam_mux, c3_b_RHX1,
                  c3_Fz_btm);
    for (c3_i184 = 0; c3_i184 < 4; c3_i184++) {
      c3_lam_Cz[c3_i184] /= c3_Fz_btm[c3_i184];
    }

    for (c3_cd_i = 0; c3_cd_i < 4; c3_cd_i++) {
      if (c3_lam_Cz[c3_cd_i] < 0.0) {
        c3_lam_Cz[c3_cd_i] = 0.0;
      }
    }

    for (c3_i185 = 0; c3_i185 < 4; c3_i185++) {
      c3_b_Fx[c3_i185] *= c3_lam_Cz[c3_i185];
    }

    for (c3_i188 = 0; c3_i188 < 4; c3_i188++) {
      c3_Bykappa[c3_i188] = c3_b_PCY1 * c3_lam_Cy[c3_i188];
    }

    for (c3_dd_i = 0; c3_dd_i < 4; c3_dd_i++) {
      if (c3_b_PCY1 * c3_lam_Cy[c3_dd_i] < 0.0) {
        c3_Bykappa[c3_dd_i] = 0.0;
      }
    }

    c3_i189 = 0;
    for (c3_i190 = 0; c3_i190 < 4; c3_i190++) {
      c3_lam_Cz[c3_i190] = c3_mu_y[c3_i190] * c3_Fz[c3_i190] * c3_zeta[c3_i189 +
        2];
      c3_i189 += 9;
    }

    for (c3_i192 = 0; c3_i192 < 4; c3_i192++) {
      c3_b_Bykappa[c3_i192] = c3_Bykappa[c3_i192] * c3_lam_Cz[c3_i192];
    }

    c3_st.site = &c3_b_emlrtRSI;
    c3_div0protect(chartInstance, &c3_st, c3_b_Bykappa, 0.0001, c3_lam_ykappa,
                   c3_Fz_btm);
    for (c3_i193 = 0; c3_i193 < 4; c3_i193++) {
      c3_lam_ykappa[c3_i193] = c3_Kyalpha[c3_i193] / c3_lam_ykappa[c3_i193];
    }

    for (c3_i194 = 0; c3_i194 < 4; c3_i194++) {
      c3_b_isLowSpeed[c3_i194] = !c3_isLowSpeed[c3_i194];
    }

    if (c3_any(chartInstance, c3_b_isLowSpeed)) {
      c3_lb_trueCount = 0;
      for (c3_jd_i = 0; c3_jd_i < 4; c3_jd_i++) {
        if (!c3_isLowSpeed[c3_jd_i]) {
          c3_lb_trueCount++;
        }
      }

      c3_v_tmp_size[0] = c3_lb_trueCount;
      c3_x_partialTrueCount = 0;
      for (c3_md_i = 0; c3_md_i < 4; c3_md_i++) {
        if (!c3_isLowSpeed[c3_md_i]) {
          c3_v_tmp_data[c3_x_partialTrueCount] = c3_md_i + 1;
          c3_x_partialTrueCount++;
        }
      }

      c3_d_tmp_size[0] = c3_v_tmp_size[0];
      c3_mb_loop_ub = c3_v_tmp_size[0] - 1;
      for (c3_i201 = 0; c3_i201 <= c3_mb_loop_ub; c3_i201++) {
        c3_d_tmp_data[c3_i201] = c3_Fz[c3_v_tmp_data[c3_i201] - 1] * (c3_b_PKY6
          + c3_b_PKY7 * c3_dfz[c3_v_tmp_data[c3_i201] - 1]) * (c3_b_PPY5 *
          c3_dpi[c3_v_tmp_data[c3_i201] - 1] + 1.0) *
          c3_lam_Kygamma[c3_v_tmp_data[c3_i201] - 1] *
          c3_gamma_star[c3_v_tmp_data[c3_i201] - 1];
      }

      c3_nb_trueCount = 0;
      for (c3_pd_i = 0; c3_pd_i < 4; c3_pd_i++) {
        if (!c3_isLowSpeed[c3_pd_i]) {
          c3_nb_trueCount++;
        }
      }

      if ((c3_d_tmp_size[0] != c3_nb_trueCount) && ((c3_d_tmp_size[0] != 1) &&
           (c3_nb_trueCount != 1))) {
        emlrtDimSizeImpxCheckR2021b(c3_d_tmp_size[0], c3_nb_trueCount,
          &c3_c_emlrtECI, (emlrtConstCTX)c3_sp);
      }

      c3_ob_trueCount = 0;
      for (c3_rd_i = 0; c3_rd_i < 4; c3_rd_i++) {
        if (!c3_isLowSpeed[c3_rd_i]) {
          c3_ob_trueCount++;
        }
      }

      c3_x_tmp_size[0] = c3_ob_trueCount;
      c3_ab_partialTrueCount = 0;
      for (c3_td_i = 0; c3_td_i < 4; c3_td_i++) {
        if (!c3_isLowSpeed[c3_td_i]) {
          c3_x_tmp_data[c3_ab_partialTrueCount] = c3_td_i + 1;
          c3_ab_partialTrueCount++;
        }
      }

      c3_st.site = &c3_b_emlrtRSI;
      if (c3_d_tmp_size[0] == c3_x_tmp_size[0]) {
        c3_tmpDrphiVar_size[0] = c3_d_tmp_size[0];
        c3_ob_loop_ub = c3_d_tmp_size[0] - 1;
        for (c3_i207 = 0; c3_i207 <= c3_ob_loop_ub; c3_i207++) {
          c3_tmpDrphiVar_data[c3_i207] = c3_d_tmp_data[c3_i207] -
            c3_SVygamma[c3_x_tmp_data[c3_i207] - 1];
        }
      } else {
        c3_c_binary_expand_op(chartInstance, c3_tmpDrphiVar_data,
                              c3_tmpDrphiVar_size, c3_d_tmp_data, c3_d_tmp_size,
                              c3_SVygamma, c3_x_tmp_data, c3_x_tmp_size);
      }

      c3_y_size[0] = c3_x_tmp_size[0];
      c3_pb_loop_ub = c3_x_tmp_size[0] - 1;
      for (c3_i209 = 0; c3_i209 <= c3_pb_loop_ub; c3_i209++) {
        c3_y_data[c3_i209] = c3_Kyalpha_prime[c3_x_tmp_data[c3_i209] - 1];
      }

      c3_b_st.site = &c3_d_emlrtRSI;
      c3_c_st.site = &c3_e_emlrtRSI;
      c3_b_assertCompatibleDims(chartInstance, &c3_c_st, c3_tmpDrphiVar_size,
        c3_y_size);
      if (c3_tmpDrphiVar_size[0] == c3_y_size[0]) {
        c3_rb_loop_ub = c3_tmpDrphiVar_size[0] - 1;
        for (c3_i214 = 0; c3_i214 <= c3_rb_loop_ub; c3_i214++) {
          c3_tmpDrphiVar_data[c3_i214] /= c3_y_data[c3_i214];
        }
      } else {
        c3_rdivide(chartInstance, c3_tmpDrphiVar_data, c3_tmpDrphiVar_size,
                   c3_y_data, c3_y_size);
      }

      c3_rb_trueCount = 0;
      for (c3_wd_i = 0; c3_wd_i < 4; c3_wd_i++) {
        if (!c3_isLowSpeed[c3_wd_i]) {
          c3_rb_trueCount++;
        }
      }

      c3_ab_tmp_size[0] = c3_rb_trueCount;
      if ((c3_tmpDrphiVar_size[0] != c3_ab_tmp_size[0]) &&
          ((c3_tmpDrphiVar_size[0] != 1) && (c3_ab_tmp_size[0] != 1))) {
        emlrtDimSizeImpxCheckR2021b(c3_tmpDrphiVar_size[0], c3_ab_tmp_size[0],
          &c3_c_emlrtECI, (emlrtConstCTX)c3_sp);
      }

      c3_sb_trueCount = 0;
      for (c3_yd_i = 0; c3_yd_i < 4; c3_yd_i++) {
        if (!c3_isLowSpeed[c3_yd_i]) {
          c3_sb_trueCount++;
        }
      }

      c3_bb_tmp_size[0] = c3_sb_trueCount;
      c3_cb_partialTrueCount = 0;
      for (c3_ae_i = 0; c3_ae_i < 4; c3_ae_i++) {
        if (!c3_isLowSpeed[c3_ae_i]) {
          c3_ab_tmp_data[c3_cb_partialTrueCount] = (c3_b_PHY1 + c3_b_PHY2 *
            c3_dfz[c3_ae_i]) * c3_lam_Hy[c3_ae_i];
          c3_cb_partialTrueCount++;
        }
      }

      c3_tb_trueCount = 0;
      for (c3_be_i = 0; c3_be_i < 4; c3_be_i++) {
        if (!c3_isLowSpeed[c3_be_i]) {
          c3_tb_trueCount++;
        }
      }

      c3_cb_tmp_size[0] = c3_tb_trueCount;
      c3_db_partialTrueCount = 0;
      for (c3_de_i = 0; c3_de_i < 4; c3_de_i++) {
        if (!c3_isLowSpeed[c3_de_i]) {
          c3_bb_tmp_data[c3_db_partialTrueCount] = c3_de_i + 1;
          c3_db_partialTrueCount++;
        }
      }

      if (c3_tmpDrphiVar_size[0] == c3_cb_tmp_size[0]) {
        c3_d_tmp_size[0] = c3_tmpDrphiVar_size[0];
        c3_sb_loop_ub = c3_tmpDrphiVar_size[0] - 1;
        for (c3_i224 = 0; c3_i224 <= c3_sb_loop_ub; c3_i224++) {
          c3_d_tmp_data[c3_i224] = c3_tmpDrphiVar_data[c3_i224] * c3_zeta[9 *
            (c3_bb_tmp_data[c3_i224] - 1)];
        }
      } else {
        c3_b_binary_expand_op(chartInstance, c3_d_tmp_data, c3_d_tmp_size,
                              c3_tmpDrphiVar_data, c3_tmpDrphiVar_size, c3_zeta,
                              c3_bb_tmp_data, c3_cb_tmp_size);
      }

      if ((c3_bb_tmp_size[0] != c3_d_tmp_size[0]) && ((c3_bb_tmp_size[0] != 1) &&
           (c3_d_tmp_size[0] != 1))) {
        emlrtDimSizeImpxCheckR2021b(c3_bb_tmp_size[0], c3_d_tmp_size[0],
          &c3_c_emlrtECI, (emlrtConstCTX)c3_sp);
      }

      if (c3_bb_tmp_size[0] == c3_d_tmp_size[0]) {
        c3_tb_loop_ub = c3_bb_tmp_size[0] - 1;
        for (c3_i226 = 0; c3_i226 <= c3_tb_loop_ub; c3_i226++) {
          c3_ab_tmp_data[c3_i226] += c3_d_tmp_data[c3_i226];
        }
      } else {
        c3_plus(chartInstance, c3_ab_tmp_data, c3_bb_tmp_size, c3_d_tmp_data,
                c3_d_tmp_size);
      }

      c3_ub_trueCount = 0;
      for (c3_fe_i = 0; c3_fe_i < 4; c3_fe_i++) {
        if (!c3_isLowSpeed[c3_fe_i]) {
          c3_ub_trueCount++;
        }
      }

      c3_db_tmp_size[0] = c3_ub_trueCount;
      if ((c3_bb_tmp_size[0] != c3_db_tmp_size[0]) && ((c3_bb_tmp_size[0] != 1) &&
           (c3_db_tmp_size[0] != 1))) {
        emlrtDimSizeImpxCheckR2021b(c3_bb_tmp_size[0], c3_db_tmp_size[0],
          &c3_c_emlrtECI, (emlrtConstCTX)c3_sp);
      }

      c3_vb_trueCount = 0;
      for (c3_ge_i = 0; c3_ge_i < 4; c3_ge_i++) {
        if (!c3_isLowSpeed[c3_ge_i]) {
          c3_vb_trueCount++;
        }
      }

      c3_eb_tmp_size[0] = c3_vb_trueCount;
      c3_eb_partialTrueCount = 0;
      for (c3_he_i = 0; c3_he_i < 4; c3_he_i++) {
        if (!c3_isLowSpeed[c3_he_i]) {
          c3_cb_tmp_data[c3_eb_partialTrueCount] = c3_he_i + 1;
          c3_eb_partialTrueCount++;
        }
      }

      if (c3_bb_tmp_size[0] == c3_eb_tmp_size[0]) {
        c3_d_tmp_size[0] = c3_bb_tmp_size[0];
        c3_ub_loop_ub = c3_bb_tmp_size[0] - 1;
        for (c3_i238 = 0; c3_i238 <= c3_ub_loop_ub; c3_i238++) {
          c3_d_tmp_data[c3_i238] = c3_ab_tmp_data[c3_i238] + c3_zeta[4 + 9 *
            (c3_cb_tmp_data[c3_i238] - 1)];
        }
      } else {
        c3_binary_expand_op(chartInstance, c3_d_tmp_data, c3_d_tmp_size,
                            c3_ab_tmp_data, c3_bb_tmp_size, c3_zeta,
                            c3_cb_tmp_data, c3_eb_tmp_size);
      }

      c3_wb_trueCount = 0;
      for (c3_ie_i = 0; c3_ie_i < 4; c3_ie_i++) {
        if (!c3_isLowSpeed[c3_ie_i]) {
          c3_wb_trueCount++;
        }
      }

      if (c3_wb_trueCount != c3_d_tmp_size[0]) {
        emlrtSubAssignSizeCheck1dR2017a(c3_wb_trueCount, c3_d_tmp_size[0],
          &c3_b_emlrtECI, (emlrtConstCTX)c3_sp);
      }

      c3_fb_partialTrueCount = 0;
      for (c3_ke_i = 0; c3_ke_i < 4; c3_ke_i++) {
        if (!c3_isLowSpeed[c3_ke_i]) {
          c3_SHy[c3_ke_i] = c3_d_tmp_data[c3_fb_partialTrueCount] - 1.0;
          c3_fb_partialTrueCount++;
        }
      }
    }

    c3_i195 = 0;
    for (c3_i197 = 0; c3_i197 < 4; c3_i197++) {
      c3_lam_Vy[c3_i197] = c3_Fz[c3_i197] * (c3_b_PVY1 + c3_b_PVY2 *
        c3_dfz[c3_i197]) * c3_lam_Vy[c3_i197] * c3_lam_muy_prime[c3_i197] *
        c3_zeta[c3_i195 + 2] + c3_SVygamma[c3_i197];
      c3_i195 += 9;
    }

    for (c3_i198 = 0; c3_i198 < 4; c3_i198++) {
      c3_lam_mux[c3_i198] = c3_alpha[c3_i198] + c3_SHy[c3_i198];
    }

    for (c3_i199 = 0; c3_i199 < 4; c3_i199++) {
      c3_Fz_btm[c3_i199] = c3_lam_mux[c3_i199];
    }

    for (c3_xd_k = 0; c3_xd_k < 4; c3_xd_k++) {
      c3_yd_k = c3_xd_k;
      c3_ic_x = c3_Fz_btm[c3_yd_k];
      c3_jc_x = c3_ic_x;
      c3_jc_x = muDoubleScalarSign(c3_jc_x);
      c3_Fz_btm[c3_yd_k] = c3_jc_x;
    }

    for (c3_od_i = 0; c3_od_i < 4; c3_od_i++) {
      if (c3_Fz_btm[c3_od_i] == 0.0) {
        c3_Fz_btm[c3_od_i] = 1.0;
      }
    }

    for (c3_ae_k = 0; c3_ae_k < 4; c3_ae_k++) {
      c3_be_k = c3_ae_k;
      c3_eb_a = c3_gamma_star[c3_be_k];
      c3_gb_y = c3_eb_a * c3_eb_a;
      c3_lam_muV[c3_be_k] = c3_gb_y;
    }

    for (c3_i203 = 0; c3_i203 < 4; c3_i203++) {
      c3_lam_muV[c3_i203] = (c3_b_PEY1 + c3_b_PEY2 * c3_dfz[c3_i203]) * ((1.0 +
        c3_b_PEY5 * c3_lam_muV[c3_i203]) - (c3_b_PEY3 + c3_b_PEY4 *
        c3_gamma_star[c3_i203]) * c3_Fz_btm[c3_i203]) * c3_lam_Ey[c3_i203];
    }

    for (c3_qd_i = 0; c3_qd_i < 4; c3_qd_i++) {
      if (c3_lam_muV[c3_qd_i] > 1.0) {
        c3_lam_muV[c3_qd_i] = 1.0;
      }
    }

    c3_b_magicsin(chartInstance, c3_lam_Cz, c3_Bykappa, c3_lam_ykappa,
                  c3_lam_muV, c3_lam_mux, c3_b_Fy);
    for (c3_i204 = 0; c3_i204 < 4; c3_i204++) {
      c3_b_Fy[c3_i204] += c3_lam_Vy[c3_i204];
    }

    for (c3_i205 = 0; c3_i205 < 4; c3_i205++) {
      c3_f_x[c3_i205] = c3_b_RVY4 * c3_alpha[c3_i205];
    }

    for (c3_ce_k = 0; c3_ce_k < 4; c3_ce_k++) {
      c3_ee_k = c3_ce_k;
      c3_kc_x = c3_f_x[c3_ee_k];
      c3_lc_x = c3_kc_x;
      c3_lc_x = muDoubleScalarAtan(c3_lc_x);
      c3_f_x[c3_ee_k] = c3_lc_x;
    }

    for (c3_de_k = 0; c3_de_k < 4; c3_de_k++) {
      c3_fe_k = c3_de_k;
      c3_mc_x = c3_f_x[c3_fe_k];
      c3_nc_x = c3_mc_x;
      c3_nc_x = muDoubleScalarCos(c3_nc_x);
      c3_f_x[c3_fe_k] = c3_nc_x;
    }

    c3_i206 = 0;
    for (c3_i208 = 0; c3_i208 < 4; c3_i208++) {
      c3_mu_y[c3_i208] = c3_mu_y[c3_i208] * c3_Fz[c3_i208] * ((c3_b_RVY1 +
        c3_b_RVY2 * c3_dfz[c3_i208]) + c3_b_RVY3 * c3_gamma_star[c3_i208]) *
        c3_f_x[c3_i208] * c3_zeta[c3_i206 + 2];
      c3_i206 += 9;
    }

    for (c3_i210 = 0; c3_i210 < 4; c3_i210++) {
      c3_f_x[c3_i210] = c3_b_RVY6 * c3_kappa[c3_i210];
    }

    for (c3_ge_k = 0; c3_ge_k < 4; c3_ge_k++) {
      c3_he_k = c3_ge_k;
      c3_oc_x = c3_f_x[c3_he_k];
      c3_pc_x = c3_oc_x;
      c3_pc_x = muDoubleScalarAtan(c3_pc_x);
      c3_f_x[c3_he_k] = c3_pc_x;
    }

    for (c3_i212 = 0; c3_i212 < 4; c3_i212++) {
      c3_f_x[c3_i212] *= c3_b_RVY5;
    }

    for (c3_ie_k = 0; c3_ie_k < 4; c3_ie_k++) {
      c3_je_k = c3_ie_k;
      c3_qc_x = c3_f_x[c3_je_k];
      c3_rc_x = c3_qc_x;
      c3_rc_x = muDoubleScalarSin(c3_rc_x);
      c3_f_x[c3_je_k] = c3_rc_x;
    }

    for (c3_i215 = 0; c3_i215 < 4; c3_i215++) {
      c3_mu_y[c3_i215] = c3_mu_y[c3_i215] * c3_f_x[c3_i215] *
        c3_lam_Vykappa[c3_i215];
    }

    for (c3_i217 = 0; c3_i217 < 4; c3_i217++) {
      c3_b_Fy[c3_i217] = c3_b_Fy[c3_i217] * c3_Vs[c3_i217] + c3_mu_y[c3_i217];
    }

    for (c3_i218 = 0; c3_i218 < 4; c3_i218++) {
      c3_b_My[c3_i218] = 10.0 * c3_b_Omega[c3_i218];
    }

    for (c3_le_k = 0; c3_le_k < 4; c3_le_k++) {
      c3_ne_k = c3_le_k;
      c3_tc_x = c3_b_My[c3_ne_k];
      c3_uc_x = c3_tc_x;
      c3_uc_x = muDoubleScalarTanh(c3_uc_x);
      c3_b_My[c3_ne_k] = c3_uc_x;
    }

    c3_st.site = &c3_b_emlrtRSI;
    c3_rollingMoment(chartInstance, &c3_st, c3_b_Fx, c3_b_Vx, c3_FzUnSat,
                     c3_press, c3_gamma, c3_b_LONGVL, c3_b_UNLOADED_RADIUS,
                     c3_b_FNOMIN, c3_b_NOMPRES, c3_b_QSY1, c3_b_QSY2, c3_b_QSY3,
                     c3_b_QSY4, c3_b_QSY5, c3_b_QSY6, c3_b_QSY7, c3_b_QSY8,
                     c3_lam_My, c3_Fz_btm);
    for (c3_i220 = 0; c3_i220 < 4; c3_i220++) {
      c3_b_My[c3_i220] *= c3_Fz_btm[c3_i220];
    }

    for (c3_qe_k = 0; c3_qe_k < 4; c3_qe_k++) {
      c3_re_k = c3_qe_k;
      c3_xc_x = c3_gamma[c3_re_k];
      c3_ib_y = muDoubleScalarAbs(c3_xc_x);
      c3_e_y[c3_re_k] = c3_ib_y;
    }

    for (c3_i222 = 0; c3_i222 < 4; c3_i222++) {
      c3_Vc_prime[c3_i222] = c3_b_QSX6 * c3_Fz[c3_i222] / c3_b_FNOMIN;
    }

    for (c3_se_k = 0; c3_se_k < 4; c3_se_k++) {
      c3_ue_k = c3_se_k;
      c3_fb_a = c3_Vc_prime[c3_ue_k];
      c3_jb_y = c3_fb_a * c3_fb_a;
      c3_SVygamma[c3_ue_k] = c3_jb_y;
    }

    for (c3_te_k = 0; c3_te_k < 4; c3_te_k++) {
      c3_ve_k = c3_te_k;
      c3_yc_x = c3_SVygamma[c3_ve_k];
      c3_ad_x = c3_yc_x;
      c3_ad_x = muDoubleScalarAtan(c3_ad_x);
      c3_SVygamma[c3_ve_k] = c3_ad_x;
    }

    for (c3_i223 = 0; c3_i223 < 4; c3_i223++) {
      c3_SVygamma[c3_i223] *= c3_b_QSX5;
    }

    for (c3_we_k = 0; c3_we_k < 4; c3_we_k++) {
      c3_xe_k = c3_we_k;
      c3_dd_x = c3_SVygamma[c3_xe_k];
      c3_ed_x = c3_dd_x;
      c3_ed_x = muDoubleScalarCos(c3_ed_x);
      c3_SVygamma[c3_xe_k] = c3_ed_x;
    }

    for (c3_i225 = 0; c3_i225 < 4; c3_i225++) {
      c3_f_x[c3_i225] = c3_b_QSX9 * c3_b_Fy[c3_i225] / c3_b_FNOMIN;
    }

    for (c3_ye_k = 0; c3_ye_k < 4; c3_ye_k++) {
      c3_af_k = c3_ye_k;
      c3_fd_x = c3_f_x[c3_af_k];
      c3_gd_x = c3_fd_x;
      c3_gd_x = muDoubleScalarAtan(c3_gd_x);
      c3_f_x[c3_af_k] = c3_gd_x;
    }

    for (c3_i228 = 0; c3_i228 < 4; c3_i228++) {
      c3_f_x[c3_i228] = c3_b_QSX7 * c3_gamma[c3_i228] + c3_b_QSX8 *
        c3_f_x[c3_i228];
    }

    for (c3_cf_k = 0; c3_cf_k < 4; c3_cf_k++) {
      c3_ef_k = c3_cf_k;
      c3_id_x = c3_f_x[c3_ef_k];
      c3_jd_x = c3_id_x;
      c3_jd_x = muDoubleScalarSin(c3_jd_x);
      c3_f_x[c3_ef_k] = c3_jd_x;
    }

    for (c3_i230 = 0; c3_i230 < 4; c3_i230++) {
      c3_Fz_btm[c3_i230] = c3_b_QSX11 * c3_Fz[c3_i230] / c3_b_FNOMIN;
    }

    for (c3_ff_k = 0; c3_ff_k < 4; c3_ff_k++) {
      c3_if_k = c3_ff_k;
      c3_kd_x = c3_Fz_btm[c3_if_k];
      c3_md_x = c3_kd_x;
      c3_md_x = muDoubleScalarAtan(c3_md_x);
      c3_Fz_btm[c3_if_k] = c3_md_x;
    }

    for (c3_hf_k = 0; c3_hf_k < 4; c3_hf_k++) {
      c3_kf_k = c3_hf_k;
      c3_od_x = c3_gamma[c3_kf_k];
      c3_lb_y = muDoubleScalarAbs(c3_od_x);
      c3_SHyphi[c3_kf_k] = c3_lb_y;
    }

    for (c3_i233 = 0; c3_i233 < 4; c3_i233++) {
      c3_b_Mx[c3_i233] = c3_b_UNLOADED_RADIUS * c3_Fz[c3_i233] * c3_b_Mx[c3_i233]
        * (((((c3_b_QSX1 * c3_lam_VMx[c3_i233] - c3_b_QSX2 * c3_gamma[c3_i233] *
               (c3_b_PPMX1 * c3_dpi[c3_i233] + 1.0)) - c3_b_QSX12 *
              c3_gamma[c3_i233] * c3_e_y[c3_i233]) + c3_b_QSX3 * c3_b_Fy[c3_i233]
             / c3_b_FNOMIN) + c3_b_QSX4 * c3_SVygamma[c3_i233] * c3_f_x[c3_i233])
           + c3_b_QSX10 * c3_Fz_btm[c3_i233] * c3_gamma[c3_i233]) +
        c3_b_UNLOADED_RADIUS * c3_b_Fy[c3_i233] * c3_b_Mx[c3_i233] * (c3_b_QSX13
        + c3_b_QSX14 * c3_SHyphi[c3_i233]);
    }

    for (c3_i235 = 0; c3_i235 < 4; c3_i235++) {
      c3_cosprimealpha[c3_i235] = c3_b_Vx[c3_i235] / c3_cosprimealpha[c3_i235];
    }

    for (c3_i236 = 0; c3_i236 < 4; c3_i236++) {
      c3_Fz_btm[c3_i236] = (c3_b_QHZ1 + c3_b_QHZ2 * c3_dfz[c3_i236]) +
        (c3_b_QHZ3 + c3_b_QHZ4 * c3_dfz[c3_i236]) * c3_gamma_star[c3_i236];
    }

    for (c3_i239 = 0; c3_i239 < 4; c3_i239++) {
      c3_Fz_btm[c3_i239] += c3_alpha[c3_i239];
    }

    for (c3_i240 = 0; c3_i240 < 4; c3_i240++) {
      c3_SHy[c3_i240] += c3_lam_Vy[c3_i240] / c3_Kyalpha_prime[c3_i240];
    }

    for (c3_i241 = 0; c3_i241 < 4; c3_i241++) {
      c3_SHy[c3_i241] += c3_alpha[c3_i241];
    }

    for (c3_nf_k = 0; c3_nf_k < 4; c3_nf_k++) {
      c3_pf_k = c3_nf_k;
      c3_gb_a = c3_dfz[c3_pf_k];
      c3_mb_y = c3_gb_a * c3_gb_a;
      c3_Vsy[c3_pf_k] = c3_mb_y;
    }

    for (c3_of_k = 0; c3_of_k < 4; c3_of_k++) {
      c3_rf_k = c3_of_k;
      c3_rd_x = c3_gamma[c3_rf_k];
      c3_nb_y = muDoubleScalarAbs(c3_rd_x);
      c3_e_y[c3_rf_k] = c3_nb_y;
    }

    for (c3_qf_k = 0; c3_qf_k < 4; c3_qf_k++) {
      c3_sf_k = c3_qf_k;
      c3_hb_a = c3_gamma_star[c3_sf_k];
      c3_ob_y = c3_hb_a * c3_hb_a;
      c3_SVygamma[c3_sf_k] = c3_ob_y;
    }

    for (c3_i242 = 0; c3_i242 < 4; c3_i242++) {
      c3_Vsy[c3_i242] = ((c3_b_QBZ1 + c3_b_QBZ2 * c3_dfz[c3_i242]) + c3_b_QBZ3 *
                         c3_Vsy[c3_i242]) * (((c3_b_QBZ4 * c3_gamma[c3_i242] +
        1.0) + c3_b_QBZ5 * c3_e_y[c3_i242]) + c3_b_QBZ6 * c3_SVygamma[c3_i242]) *
        c3_lam_Kyalpha[c3_i242] / c3_lam_muy[c3_i242];
    }

    for (c3_ne_i = 0; c3_ne_i < 4; c3_ne_i++) {
      if (c3_Vsy[c3_ne_i] < 0.0) {
        c3_Vsy[c3_ne_i] = 0.0;
      }
    }

    c3_dv6[0] = c3_b_QCZ1;
    c3_bv[0] = (c3_b_QCZ1 < 0.0);
    for (c3_oe_i = 0; c3_oe_i < 1; c3_oe_i++) {
      if (c3_bv[0]) {
        c3_dv6[c3_oe_i] = 0.0;
      }
    }

    c3_Ct = c3_dv6[0];
    c3_sd_x = c3_b_UNLOADED_RADIUS;
    c3_td_x = c3_sd_x;
    for (c3_i245 = 0; c3_i245 < 4; c3_i245++) {
      c3_Fzo_prime[c3_i245] = c3_td_x / c3_Fzo_prime[c3_i245];
    }

    for (c3_tf_k = 0; c3_tf_k < 4; c3_tf_k++) {
      c3_uf_k = c3_tf_k;
      c3_ib_a = c3_gamma[c3_uf_k];
      c3_pb_y = c3_ib_a * c3_ib_a;
      c3_Vs[c3_uf_k] = c3_pb_y;
    }

    c3_i246 = 0;
    for (c3_i247 = 0; c3_i247 < 4; c3_i247++) {
      c3_Vs[c3_i247] = (c3_b_QDZ1 + c3_b_QDZ2 * c3_dfz[c3_i247]) * (1.0 -
        c3_b_PPZ1 * c3_dpi[c3_i247]) * ((c3_b_QDZ3 * c3_gamma[c3_i247] + 1.0) +
        c3_b_QDZ4 * c3_Vs[c3_i247]) * c3_Fz[c3_i247] * c3_Fzo_prime[c3_i247] *
        c3_lam_t[c3_i247] * c3_zeta[c3_i246 + 5];
      c3_i246 += 9;
    }

    for (c3_vf_k = 0; c3_vf_k < 4; c3_vf_k++) {
      c3_wf_k = c3_vf_k;
      c3_jb_a = c3_dfz[c3_wf_k];
      c3_qb_y = c3_jb_a * c3_jb_a;
      c3_SHyphi[c3_wf_k] = c3_qb_y;
    }

    for (c3_i248 = 0; c3_i248 < 4; c3_i248++) {
      c3_f_x[c3_i248] = c3_Vsy[c3_i248] * c3_Ct * c3_Fz_btm[c3_i248];
    }

    for (c3_xf_k = 0; c3_xf_k < 4; c3_xf_k++) {
      c3_yf_k = c3_xf_k;
      c3_ud_x = c3_f_x[c3_yf_k];
      c3_vd_x = c3_ud_x;
      c3_vd_x = muDoubleScalarAtan(c3_vd_x);
      c3_f_x[c3_yf_k] = c3_vd_x;
    }

    for (c3_i250 = 0; c3_i250 < 4; c3_i250++) {
      c3_SHyphi[c3_i250] = ((c3_b_QEZ1 + c3_b_QEZ2 * c3_dfz[c3_i250]) +
                            c3_b_QEZ3 * c3_SHyphi[c3_i250]) * (1.0 + (c3_b_QEZ4
        + c3_b_QEZ5 * c3_gamma_star[c3_i250]) * 2.0 / 3.1415926535897931 *
        c3_f_x[c3_i250]);
    }

    for (c3_se_i = 0; c3_se_i < 4; c3_se_i++) {
      if (c3_SHyphi[c3_se_i] > 1.0) {
        c3_SHyphi[c3_se_i] = 1.0;
      }
    }

    for (c3_i252 = 0; c3_i252 < 4; c3_i252++) {
      c3_e_y[c3_i252] = 10.0 * c3_b_Vx[c3_i252];
    }

    for (c3_ag_k = 0; c3_ag_k < 4; c3_ag_k++) {
      c3_cg_k = c3_ag_k;
      c3_wd_x = c3_gamma_star[c3_cg_k];
      c3_rb_y = muDoubleScalarAbs(c3_wd_x);
      c3_SVygamma[c3_cg_k] = c3_rb_y;
    }

    for (c3_bg_k = 0; c3_bg_k < 4; c3_bg_k++) {
      c3_dg_k = c3_bg_k;
      c3_xd_x = c3_e_y[c3_dg_k];
      c3_yd_x = c3_xd_x;
      c3_yd_x = muDoubleScalarTanh(c3_yd_x);
      c3_e_y[c3_dg_k] = c3_yd_x;
    }

    c3_i254 = 0;
    for (c3_i255 = 0; c3_i255 < 4; c3_i255++) {
      c3_lam_Mr[c3_i255] = (c3_Fz[c3_i255] * c3_b_UNLOADED_RADIUS * ((c3_b_QDZ6
        + c3_b_QDZ7 * c3_dfz[c3_i255]) * c3_lam_Mr[c3_i255] * c3_zeta[c3_i254 +
        2] + ((c3_b_QDZ8 + c3_b_QDZ9 * c3_dfz[c3_i255]) * (c3_b_PPZ2 *
        c3_dpi[c3_i255] + 1.0) + (c3_b_QDZ10 + c3_b_QDZ11 * c3_dfz[c3_i255]) *
              c3_SVygamma[c3_i255]) * c3_gamma_star[c3_i255] *
        c3_lam_Kzgamma[c3_i255] * c3_zeta[c3_i254]) * c3_lam_muy[c3_i255] *
                            c3_e_y[c3_i255] * c3_cosprimealpha[c3_i255] +
                            c3_zeta[c3_i254 + 8]) - 1.0;
      c3_i254 += 9;
    }

    c3_i256 = 0;
    for (c3_i258 = 0; c3_i258 < 4; c3_i258++) {
      c3_lam_muV[c3_i258] = c3_zeta[c3_i256 + 7];
      c3_i256 += 9;
    }

    c3_i259 = 0;
    for (c3_i261 = 0; c3_i261 < 4; c3_i261++) {
      c3_lam_Kyalpha[c3_i261] = (c3_b_QBZ9 * c3_lam_Kyalpha[c3_i261] /
        c3_lam_muy[c3_i261] + c3_b_QBZ10 * c3_lam_ykappa[c3_i261] *
        c3_Bykappa[c3_i261]) * c3_zeta[c3_i259 + 6];
      c3_i259 += 9;
    }

    for (c3_i263 = 0; c3_i263 < 4; c3_i263++) {
      c3_f_x[c3_i263] = c3_SHy[c3_i263];
    }

    for (c3_eg_k = 0; c3_eg_k < 4; c3_eg_k++) {
      c3_gg_k = c3_eg_k;
      c3_ae_x = c3_f_x[c3_gg_k];
      c3_be_x = c3_ae_x;
      c3_be_x = muDoubleScalarTan(c3_be_x);
      c3_f_x[c3_gg_k] = c3_be_x;
    }

    for (c3_fg_k = 0; c3_fg_k < 4; c3_fg_k++) {
      c3_hg_k = c3_fg_k;
      c3_kb_a = c3_f_x[c3_hg_k];
      c3_sb_y = c3_kb_a * c3_kb_a;
      c3_lam_mux[c3_hg_k] = c3_sb_y;
    }

    for (c3_i264 = 0; c3_i264 < 4; c3_i264++) {
      c3_Vc_prime[c3_i264] = c3_phi_t[c3_i264] / c3_Kyalpha_prime[c3_i264];
    }

    for (c3_ig_k = 0; c3_ig_k < 4; c3_ig_k++) {
      c3_kg_k = c3_ig_k;
      c3_lb_a = c3_Vc_prime[c3_kg_k];
      c3_tb_y = c3_lb_a * c3_lb_a;
      c3_e_y[c3_kg_k] = c3_tb_y;
    }

    for (c3_jg_k = 0; c3_jg_k < 4; c3_jg_k++) {
      c3_lg_k = c3_jg_k;
      c3_mb_a = c3_kappa[c3_lg_k];
      c3_ub_y = c3_mb_a * c3_mb_a;
      c3_SVygamma[c3_lg_k] = c3_ub_y;
    }

    for (c3_i265 = 0; c3_i265 < 4; c3_i265++) {
      c3_lam_mux[c3_i265] += c3_e_y[c3_i265] * c3_SVygamma[c3_i265];
    }

    c3_st.site = &c3_b_emlrtRSI;
    c3_e_sqrt(chartInstance, &c3_st, c3_lam_mux);
    for (c3_mg_k = 0; c3_mg_k < 4; c3_mg_k++) {
      c3_ng_k = c3_mg_k;
      c3_ce_x = c3_lam_mux[c3_ng_k];
      c3_de_x = c3_ce_x;
      c3_de_x = muDoubleScalarAtan(c3_de_x);
      c3_lam_mux[c3_ng_k] = c3_de_x;
    }

    for (c3_i267 = 0; c3_i267 < 4; c3_i267++) {
      c3_SHy[c3_i267] *= 1000.0;
    }

    for (c3_og_k = 0; c3_og_k < 4; c3_og_k++) {
      c3_pg_k = c3_og_k;
      c3_ee_x = c3_SHy[c3_pg_k];
      c3_fe_x = c3_ee_x;
      c3_fe_x = muDoubleScalarTanh(c3_fe_x);
      c3_SHy[c3_pg_k] = c3_fe_x;
    }

    for (c3_i268 = 0; c3_i268 < 4; c3_i268++) {
      c3_lam_mux[c3_i268] *= c3_SHy[c3_i268];
    }

    for (c3_i269 = 0; c3_i269 < 4; c3_i269++) {
      c3_f_x[c3_i269] = c3_Fz_btm[c3_i269];
    }

    for (c3_qg_k = 0; c3_qg_k < 4; c3_qg_k++) {
      c3_sg_k = c3_qg_k;
      c3_ge_x = c3_f_x[c3_sg_k];
      c3_he_x = c3_ge_x;
      c3_he_x = muDoubleScalarTan(c3_he_x);
      c3_f_x[c3_sg_k] = c3_he_x;
    }

    for (c3_rg_k = 0; c3_rg_k < 4; c3_rg_k++) {
      c3_tg_k = c3_rg_k;
      c3_nb_a = c3_f_x[c3_tg_k];
      c3_vb_y = c3_nb_a * c3_nb_a;
      c3_lam_Cz[c3_tg_k] = c3_vb_y;
    }

    for (c3_i270 = 0; c3_i270 < 4; c3_i270++) {
      c3_Kyalpha_prime[c3_i270] = c3_phi_t[c3_i270] / c3_Kyalpha_prime[c3_i270];
    }

    for (c3_ug_k = 0; c3_ug_k < 4; c3_ug_k++) {
      c3_wg_k = c3_ug_k;
      c3_ob_a = c3_Kyalpha_prime[c3_wg_k];
      c3_wb_y = c3_ob_a * c3_ob_a;
      c3_e_y[c3_wg_k] = c3_wb_y;
    }

    for (c3_vg_k = 0; c3_vg_k < 4; c3_vg_k++) {
      c3_xg_k = c3_vg_k;
      c3_pb_a = c3_kappa[c3_xg_k];
      c3_xb_y = c3_pb_a * c3_pb_a;
      c3_SVygamma[c3_xg_k] = c3_xb_y;
    }

    for (c3_i272 = 0; c3_i272 < 4; c3_i272++) {
      c3_lam_Cz[c3_i272] += c3_e_y[c3_i272] * c3_SVygamma[c3_i272];
    }

    c3_st.site = &c3_b_emlrtRSI;
    c3_e_sqrt(chartInstance, &c3_st, c3_lam_Cz);
    for (c3_yg_k = 0; c3_yg_k < 4; c3_yg_k++) {
      c3_ah_k = c3_yg_k;
      c3_ie_x = c3_lam_Cz[c3_ah_k];
      c3_je_x = c3_ie_x;
      c3_je_x = muDoubleScalarAtan(c3_je_x);
      c3_lam_Cz[c3_ah_k] = c3_je_x;
    }

    for (c3_i273 = 0; c3_i273 < 4; c3_i273++) {
      c3_Fz_btm[c3_i273] *= 1000.0;
    }

    for (c3_bh_k = 0; c3_bh_k < 4; c3_bh_k++) {
      c3_ch_k = c3_bh_k;
      c3_ke_x = c3_Fz_btm[c3_ch_k];
      c3_le_x = c3_ke_x;
      c3_le_x = muDoubleScalarTanh(c3_le_x);
      c3_Fz_btm[c3_ch_k] = c3_le_x;
    }

    for (c3_i274 = 0; c3_i274 < 4; c3_i274++) {
      c3_lam_Cz[c3_i274] *= c3_Fz_btm[c3_i274];
    }

    c3_c_magiccos(chartInstance, c3_lam_Mr, c3_lam_muV, c3_lam_Kyalpha,
                  c3_lam_mux, c3_Fz_btm);
    c3_d_magiccos(chartInstance, c3_Vs, c3_Ct, c3_Vsy, c3_SHyphi, c3_lam_Cz,
                  c3_b_Mz);
    for (c3_i275 = 0; c3_i275 < 4; c3_i275++) {
      c3_b_Mz[c3_i275] *= c3_cosprimealpha[c3_i275];
    }

    for (c3_i276 = 0; c3_i276 < 4; c3_i276++) {
      c3_b_Mz[c3_i276] *= c3_lam_Fzo[c3_i276];
    }

    for (c3_i277 = 0; c3_i277 < 4; c3_i277++) {
      c3_gamma_star[c3_i277] = c3_b_UNLOADED_RADIUS * ((c3_b_SSZ1 + c3_b_SSZ2 *
        c3_b_Fy[c3_i277] / c3_b_FNOMIN) + (c3_b_SSZ3 + c3_b_SSZ4 *
        c3_dfz[c3_i277]) * c3_gamma_star[c3_i277]) * c3_lam_s[c3_i277];
    }

    for (c3_i278 = 0; c3_i278 < 4; c3_i278++) {
      c3_mu_y[c3_i278] = c3_b_Fy[c3_i278] - c3_mu_y[c3_i278];
    }

    for (c3_i279 = 0; c3_i279 < 4; c3_i279++) {
      c3_b_Mz[c3_i279] = -c3_b_Mz[c3_i279] * c3_mu_y[c3_i279];
    }

    for (c3_i281 = 0; c3_i281 < 4; c3_i281++) {
      c3_b_Mz[c3_i281] = (c3_b_Mz[c3_i281] + c3_Fz_btm[c3_i281]) +
        c3_gamma_star[c3_i281] * c3_b_Fx[c3_i281];
    }

    for (c3_dh_k = 0; c3_dh_k < 4; c3_dh_k++) {
      c3_eh_k = c3_dh_k;
      c3_qb_a = c3_dfz[c3_eh_k];
      c3_yb_y = c3_qb_a * c3_qb_a;
      c3_Fz_btm[c3_eh_k] = c3_yb_y;
    }

    for (c3_i282 = 0; c3_i282 < 4; c3_i282++) {
      c3_Fz_btm[c3_i282] = c3_b_LONGITUDINAL_STIFFNESS * ((c3_b_PCFX1 *
        c3_dfz[c3_i282] + 1.0) + c3_b_PCFX2 * c3_Fz_btm[c3_i282]) * (c3_b_PCFX3 *
        c3_dpi[c3_i282] + 1.0);
    }

    for (c3_fh_k = 0; c3_fh_k < 4; c3_fh_k++) {
      c3_gh_k = c3_fh_k;
      c3_rb_a = c3_dfz[c3_gh_k];
      c3_ac_y = c3_rb_a * c3_rb_a;
      c3_e_y[c3_gh_k] = c3_ac_y;
    }

    for (c3_i283 = 0; c3_i283 < 4; c3_i283++) {
      c3_dfz[c3_i283] = c3_b_LATERAL_STIFFNESS * ((c3_b_PCFY1 * c3_dfz[c3_i283]
        + 1.0) + c3_b_PCFY2 * c3_e_y[c3_i283]) * (c3_b_PCFY3 * c3_dpi[c3_i283] +
        1.0);
    }

    for (c3_i285 = 0; c3_i285 < 4; c3_i285++) {
      c3_phi_t[c3_i285] /= c3_Fz_btm[c3_i285];
    }

    for (c3_hh_k = 0; c3_hh_k < 4; c3_hh_k++) {
      c3_ih_k = c3_hh_k;
      c3_me_x = c3_phi_t[c3_ih_k];
      c3_bc_y = muDoubleScalarAbs(c3_me_x);
      c3_b_sig_x[c3_ih_k] = c3_bc_y;
    }

    for (c3_i287 = 0; c3_i287 < 4; c3_i287++) {
      c3_Kyalpha[c3_i287] /= c3_dfz[c3_i287];
    }

    for (c3_jh_k = 0; c3_jh_k < 4; c3_jh_k++) {
      c3_kh_k = c3_jh_k;
      c3_ne_x = c3_Kyalpha[c3_kh_k];
      c3_cc_y = muDoubleScalarAbs(c3_ne_x);
      c3_b_sig_y[c3_kh_k] = c3_cc_y;
    }
  } else {
    c3_st.site = &c3_b_emlrtRSI;
    for (c3_i1 = 0; c3_i1 < 4; c3_i1++) {
      c3_b_gamma[c3_i1] = c3_gamma[c3_i1];
    }

    for (c3_i3 = 0; c3_i3 < 4; c3_i3++) {
      c3_b_press[c3_i3] = c3_press[c3_i3];
    }

    c3_b_vdyncsmtire(chartInstance, &c3_st, c3_b_Omega, c3_b_Vx, c3_b_Vy,
                     c3_b_psidot, c3_b_gamma, c3_b_press, c3_scaleFactors,
                     c3_b_rhoz, c3_b_turnslip, c3_b_PRESMAX, c3_b_PRESMIN,
                     c3_b_FZMAX, c3_b_FZMIN, c3_b_VXLOW, c3_b_KPUMAX,
                     c3_b_KPUMIN, c3_b_ALPMAX, c3_b_ALPMIN, c3_b_CAMMIN,
                     c3_b_CAMMAX, c3_b_LONGVL, c3_b_UNLOADED_RADIUS,
                     c3_b_RIM_RADIUS, c3_b_NOMPRES, c3_b_FNOMIN, c3_b_vdynMF[38],
                     c3_b_vdynMF[43], c3_b_vdynMF[42], c3_b_vdynMF[44],
                     c3_b_vdynMF[45], c3_b_vdynMF[46], c3_b_vdynMF[47],
                     c3_b_vdynMF[48], c3_b_vdynMF[49], c3_b_vdynMF[51],
                     c3_b_vdynMF[52], c3_b_vdynMF[54], c3_b_vdynMF[55],
                     c3_b_vdynMF[62], c3_b_vdynMF[63], c3_b_vdynMF[134],
                     c3_b_vdynMF[135], c3_b_vdynMF[136], c3_b_vdynMF[137],
                     c3_b_vdynMF[138], c3_b_vdynMF[139], c3_b_vdynMF[140],
                     c3_b_vdynMF[141], c3_b_vdynMF[142], c3_b_vdynMF[143],
                     c3_b_vdynMF[144], c3_b_vdynMF[145], c3_b_vdynMF[146],
                     c3_b_vdynMF[147], c3_b_vdynMF[148], c3_b_vdynMF[149],
                     c3_b_vdynMF[150], c3_b_vdynMF[151], c3_b_vdynMF[152],
                     c3_b_vdynMF[153], c3_b_vdynMF[154], c3_b_vdynMF[155],
                     c3_b_vdynMF[156], c3_b_vdynMF[157], c3_b_vdynMF[158],
                     c3_b_vdynMF[159], c3_b_vdynMF[160], c3_b_vdynMF[161],
                     c3_b_vdynMF[162], c3_b_vdynMF[163], c3_b_vdynMF[164],
                     c3_b_vdynMF[165], c3_b_vdynMF[166], c3_b_vdynMF[167],
                     c3_b_vdynMF[168], c3_b_vdynMF[169], c3_b_vdynMF[170],
                     c3_b_vdynMF[174], c3_b_vdynMF[175], c3_b_vdynMF[176],
                     c3_b_vdynMF[177], c3_b_vdynMF[178], c3_b_vdynMF[179],
                     c3_b_vdynMF[180], c3_b_vdynMF[181], c3_b_vdynMF[182],
                     c3_b_vdynMF[183], c3_b_vdynMF[184], c3_b_vdynMF[185],
                     c3_b_vdynMF[186], c3_b_vdynMF[187], c3_b_vdynMF[188],
                     c3_b_vdynMF[189], c3_b_vdynMF[190], c3_b_vdynMF[191],
                     c3_b_vdynMF[192], c3_b_vdynMF[193], c3_b_vdynMF[194],
                     c3_b_vdynMF[195], c3_b_vdynMF[196], c3_b_vdynMF[197],
                     c3_b_vdynMF[198], c3_b_vdynMF[199], c3_b_vdynMF[200],
                     c3_b_vdynMF[201], c3_b_vdynMF[202], c3_b_vdynMF[203],
                     c3_b_vdynMF[204], c3_b_vdynMF[205], c3_b_vdynMF[206],
                     c3_b_vdynMF[207], c3_b_vdynMF[208], c3_b_vdynMF[209],
                     c3_b_vdynMF[210], c3_b_vdynMF[211], c3_b_vdynMF[212],
                     c3_b_vdynMF[213], c3_b_vdynMF[214], c3_b_vdynMF[215],
                     c3_b_vdynMF[216], c3_b_vdynMF[217], c3_b_vdynMF[218],
                     c3_b_vdynMF[219], c3_b_vdynMF[220], c3_b_vdynMF[221],
                     c3_b_vdynMF[222], c3_b_vdynMF[223], c3_b_vdynMF[224],
                     c3_b_vdynMF[225], c3_b_vdynMF[226], c3_b_vdynMF[227],
                     c3_b_vdynMF[228], c3_b_vdynMF[229], c3_b_vdynMF[230],
                     c3_b_vdynMF[231], c3_b_vdynMF[232], c3_b_vdynMF[233],
                     c3_b_vdynMF[234], c3_b_vdynMF[235], c3_b_vdynMF[236],
                     c3_b_vdynMF[237], c3_b_vdynMF[238], c3_b_vdynMF[239],
                     c3_b_vdynMF[240], c3_b_vdynMF[242], c3_b_vdynMF[242],
                     c3_b_vdynMF[243], c3_b_vdynMF[244], c3_b_vdynMF[245],
                     c3_b_vdynMF[246], c3_b_vdynMF[247], c3_b_vdynMF[248],
                     c3_b_vdynMF[249], c3_b_vdynMF[250], c3_b_vdynMF[251],
                     c3_b_vdynMF[252], c3_b_vdynMF[253], c3_b_vdynMF[254],
                     c3_b_vdynMF[255], c3_b_vdynMF[256], c3_b_vdynMF[257],
                     c3_b_vdynMF[258], c3_b_vdynMF[259], c3_b_vdynMF[260],
                     c3_b_vdynMF[261], c3_b_vdynMF[262], c3_b_vdynMF[263],
                     c3_b_vdynMF[264], c3_b_vdynMF[265], c3_b_vdynMF[266],
                     c3_b_vdynMF[267], c3_b_vdynMF[268], c3_b_vdynMF[269],
                     c3_b_vdynMF[270], c3_b_vdynMF[271], c3_b_vdynMF[272],
                     c3_b_vdynMF[273], c3_b_vdynMF[274], c3_b_vdynMF[275],
                     c3_b_vdynMF[276], c3_b_vdynMF[277], c3_b_vdynMF[278],
                     c3_b_WIDTH, c3_b_vdynMF[86], c3_b_vdynMF[87], c3_b_vdynMF
                     [88], c3_b_vdynMF[89], c3_b_vdynMF[171], c3_b_vdynMF[172],
                     c3_b_vdynMF[173], c3_b_vdynMF[50], c3_b_vdynMF[64],
                     c3_b_vdynMF[65], c3_b_vdynMF[79], c3_b_vdynMF[80],
                     c3_b_vdynMF[81], c3_b_vdynMF[82], c3_b_vdynMF[83],
                     c3_b_vdynMF[84], c3_b_Fx_ext, c3_b_Fy_ext, c3_b_Fx, c3_b_Fy,
                     c3_Fz, c3_b_Mx, c3_b_My, c3_b_Mz, c3_b_Re, c3_kappa,
                     c3_alpha, c3_b_sig_x, c3_b_sig_y, c3_patch_a, c3_patch_b);
  }
}

static void c3_div0protect(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, real_T c3_u[4], real_T c3_tol, real_T c3_y[4], real_T
  c3_yabs[4])
{
  emlrtStack c3_st;
  real_T c3_y_data[4];
  real_T c3_yabs_data[4];
  real_T c3_b_x;
  real_T c3_b_y;
  real_T c3_c_x;
  real_T c3_x;
  int32_T c3_tmp_data[4];
  int32_T c3_tmp_size[1];
  int32_T c3_y_size[1];
  int32_T c3_yabs_size[1];
  int32_T c3_b_i;
  int32_T c3_b_k;
  int32_T c3_b_loop_ub;
  int32_T c3_b_partialTrueCount;
  int32_T c3_b_trueCount;
  int32_T c3_c_i;
  int32_T c3_c_loop_ub;
  int32_T c3_d_i;
  int32_T c3_e_i;
  int32_T c3_f_i;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_k;
  int32_T c3_loop_ub;
  int32_T c3_partialTrueCount;
  int32_T c3_trueCount;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  for (c3_k = 0; c3_k < 4; c3_k++) {
    c3_b_k = c3_k;
    c3_x = c3_u[c3_b_k];
    c3_b_y = muDoubleScalarAbs(c3_x);
    c3_yabs[c3_b_k] = c3_b_y;
  }

  c3_trueCount = 0;
  for (c3_i = 0; c3_i < 4; c3_i++) {
    if (c3_yabs[c3_i] < c3_tol) {
      c3_trueCount++;
    }
  }

  c3_tmp_size[0] = c3_trueCount;
  c3_partialTrueCount = 0;
  for (c3_b_i = 0; c3_b_i < 4; c3_b_i++) {
    if (c3_yabs[c3_b_i] < c3_tol) {
      c3_tmp_data[c3_partialTrueCount] = c3_b_i + 1;
      c3_partialTrueCount++;
    }
  }

  c3_b_x = 2.0 * c3_tol;
  c3_yabs_size[0] = c3_tmp_size[0];
  c3_loop_ub = c3_tmp_size[0] - 1;
  for (c3_c_i = 0; c3_c_i <= c3_loop_ub; c3_c_i++) {
    c3_yabs_data[c3_c_i] = c3_yabs[c3_tmp_data[c3_c_i] - 1] / c3_tol;
  }

  c3_st.site = &c3_b_emlrtRSI;
  c3_power(chartInstance, &c3_st, c3_yabs_data, c3_yabs_size, c3_y_data,
           c3_y_size);
  c3_b_loop_ub = c3_y_size[0] - 1;
  for (c3_i1 = 0; c3_i1 <= c3_b_loop_ub; c3_i1++) {
    c3_y_data[c3_i1] = 3.0 - c3_y_data[c3_i1];
  }

  c3_c_x = c3_b_x;
  c3_c_loop_ub = c3_y_size[0] - 1;
  for (c3_i2 = 0; c3_i2 <= c3_c_loop_ub; c3_i2++) {
    c3_y_data[c3_i2] = c3_c_x / c3_y_data[c3_i2];
  }

  c3_b_trueCount = 0;
  for (c3_d_i = 0; c3_d_i < 4; c3_d_i++) {
    if (c3_yabs[c3_d_i] < c3_tol) {
      c3_b_trueCount++;
    }
  }

  if (c3_b_trueCount != c3_y_size[0]) {
    emlrtSubAssignSizeCheck1dR2017a(c3_b_trueCount, c3_y_size[0], &c3_b_emlrtECI,
      (emlrtConstCTX)c3_sp);
  }

  c3_b_partialTrueCount = 0;
  for (c3_e_i = 0; c3_e_i < 4; c3_e_i++) {
    if (c3_yabs[c3_e_i] < c3_tol) {
      c3_yabs[c3_e_i] = c3_y_data[c3_b_partialTrueCount];
      c3_b_partialTrueCount++;
    }
  }

  for (c3_i3 = 0; c3_i3 < 4; c3_i3++) {
    c3_y[c3_i3] = c3_yabs[c3_i3];
  }

  for (c3_f_i = 0; c3_f_i < 4; c3_f_i++) {
    if (c3_u[c3_f_i] < 0.0) {
      c3_y[c3_f_i] = -c3_yabs[c3_f_i];
    }
  }
}

static void c3_power(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
                     const emlrtStack *c3_sp, real_T c3_a_data[], int32_T
                     c3_a_size[1], real_T c3_y_data[], int32_T c3_y_size[1])
{
  emlrtStack c3_st;
  const mxArray *c3_b_y = NULL;
  const mxArray *c3_y = NULL;
  int32_T c3_i;
  int32_T c3_loop_ub;
  boolean_T c3_p;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_st.site = &c3_c_emlrtRSI;
  c3_p = false;
  if (c3_p) {
    c3_y = NULL;
    sf_mex_assign(&c3_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    c3_b_y = NULL;
    sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    sf_mex_call(&c3_st, &c3_emlrtMCI, "error", 0U, 2U, 14, c3_y, 14, sf_mex_call
                (&c3_st, NULL, "getString", 1U, 1U, 14, sf_mex_call(&c3_st, NULL,
      "message", 1U, 1U, 14, c3_b_y)));
  }

  c3_y_size[0] = c3_a_size[0];
  c3_loop_ub = c3_a_size[0] - 1;
  for (c3_i = 0; c3_i <= c3_loop_ub; c3_i++) {
    c3_y_data[c3_i] = c3_function_handle_parenReference(chartInstance,
      c3_a_data[c3_i]);
  }
}

static real_T c3_function_handle_parenReference
  (SFc3_vehdynlibtirecommonInstanceStruct *chartInstance, real_T c3_varargin_1)
{
  real_T c3_b_a;
  real_T c3_x;
  (void)chartInstance;
  c3_x = c3_varargin_1;
  c3_b_a = c3_x;
  return c3_b_a * c3_b_a;
}

static void c3_assertCompatibleDims(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c3_b_power(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, real_T c3_a_data[], int32_T c3_a_size[2], real_T
  c3_y_data[], int32_T c3_y_size[2])
{
  emlrtStack c3_st;
  const mxArray *c3_b_y = NULL;
  const mxArray *c3_y = NULL;
  int32_T c3_i;
  int32_T c3_loop_ub;
  boolean_T c3_p;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_st.site = &c3_c_emlrtRSI;
  c3_p = false;
  if (c3_p) {
    c3_y = NULL;
    sf_mex_assign(&c3_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    c3_b_y = NULL;
    sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    sf_mex_call(&c3_st, &c3_emlrtMCI, "error", 0U, 2U, 14, c3_y, 14, sf_mex_call
                (&c3_st, NULL, "getString", 1U, 1U, 14, sf_mex_call(&c3_st, NULL,
      "message", 1U, 1U, 14, c3_b_y)));
  }

  c3_y_size[0] = 1;
  c3_y_size[1] = c3_a_size[1];
  c3_loop_ub = c3_a_size[0] * c3_a_size[1] - 1;
  for (c3_i = 0; c3_i <= c3_loop_ub; c3_i++) {
    c3_y_data[c3_i] = c3_function_handle_parenReference(chartInstance,
      c3_a_data[c3_i]);
  }
}

static void c3_sqrt(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance, const
                    emlrtStack *c3_sp, real_T c3_x_data[], int32_T c3_x_size[2],
                    real_T c3_b_x_data[], int32_T c3_b_x_size[2])
{
  int32_T c3_i;
  int32_T c3_loop_ub;
  c3_b_x_size[0] = 1;
  c3_b_x_size[1] = c3_x_size[1];
  c3_loop_ub = c3_x_size[0] * c3_x_size[1] - 1;
  for (c3_i = 0; c3_i <= c3_loop_ub; c3_i++) {
    c3_b_x_data[c3_i] = c3_x_data[c3_i];
  }

  c3_d_sqrt(chartInstance, c3_sp, c3_b_x_data, c3_b_x_size);
}

static void c3_abs(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance, real_T
                   c3_x_data[], int32_T c3_x_size[1], real_T c3_y_data[],
                   int32_T c3_y_size[1])
{
  real_T c3_dv[2];
  real_T c3_x;
  real_T c3_y;
  int32_T c3_b_k;
  int32_T c3_i;
  int32_T c3_k;
  int32_T c3_nx;
  (void)chartInstance;
  c3_nx = c3_x_size[0];
  c3_dv[0] = (real_T)c3_x_size[0];
  c3_y_size[0] = (int32_T)c3_dv[0];
  c3_i = (uint8_T)c3_nx - 1;
  for (c3_k = 0; c3_k <= c3_i; c3_k++) {
    c3_b_k = c3_k;
    c3_x = c3_x_data[c3_b_k];
    c3_y = muDoubleScalarAbs(c3_x);
    c3_y_data[c3_b_k] = c3_y;
  }
}

static void c3_b_assertCompatibleDims(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, int32_T c3_x_size[1], int32_T
  c3_y_size[1])
{
  static char_T c3_b_cv[30] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'i', 'z',
    'e', 'D', 'i', 'm', 'e', 'n', 's', 'i', 'o', 'n', 's', 'M', 'u', 's', 't',
    'M', 'a', 't', 'c', 'h' };

  const mxArray *c3_b_y = NULL;
  const mxArray *c3_y = NULL;
  int32_T c3_sxk;
  int32_T c3_syk;
  boolean_T c3_b_dimagree;
  boolean_T c3_dimagree;
  (void)chartInstance;
  c3_sxk = c3_x_size[0];
  c3_syk = c3_y_size[0];
  if ((c3_sxk == 1) || (c3_syk == 1) || (c3_sxk == c3_syk)) {
    c3_dimagree = true;
  } else {
    c3_dimagree = false;
  }

  if (c3_dimagree) {
    c3_dimagree = true;
  } else {
    c3_dimagree = false;
  }

  c3_b_dimagree = c3_dimagree;
  if (!c3_b_dimagree) {
    c3_y = NULL;
    sf_mex_assign(&c3_y, sf_mex_create("y", c3_b_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c3_b_y = NULL;
    sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_b_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call(c3_sp, &c3_b_emlrtMCI, "error", 0U, 2U, 14, c3_y, 14,
                sf_mex_call(c3_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c3_sp, NULL, "message", 1U, 1U, 14, c3_b_y)));
  }
}

static void c3_b_sqrt(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
                      const emlrtStack *c3_sp, real_T c3_x[4], real_T c3_b_x[4])
{
  int32_T c3_i;
  for (c3_i = 0; c3_i < 4; c3_i++) {
    c3_b_x[c3_i] = c3_x[c3_i];
  }

  c3_e_sqrt(chartInstance, c3_sp, c3_b_x);
}

static void c3_c_power(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, real_T c3_b_a[4], real_T c3_y[4])
{
  emlrtStack c3_st;
  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_y = NULL;
  real_T c3_x_data[4];
  real_T c3_c_a;
  real_T c3_d_a;
  real_T c3_d_y;
  int32_T c3_b_k;
  int32_T c3_c_k;
  int32_T c3_d_k;
  int32_T c3_i;
  int32_T c3_k;
  boolean_T c3_b_p;
  boolean_T c3_c_p;
  boolean_T c3_p;
  (void)chartInstance;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_st.site = &c3_c_emlrtRSI;
  for (c3_i = 0; c3_i < 4; c3_i++) {
    c3_x_data[c3_i] = c3_b_a[c3_i];
  }

  c3_p = false;
  for (c3_k = 0; c3_k < 4; c3_k++) {
    c3_b_k = c3_k;
    if (c3_p) {
      c3_b_p = true;
    } else {
      c3_c_a = c3_x_data[c3_b_k];
      c3_c_p = (c3_c_a < 0.0);
      if (c3_c_p) {
        c3_b_p = true;
      } else {
        c3_b_p = false;
      }
    }

    c3_p = c3_b_p;
  }

  if (c3_p) {
    c3_b_y = NULL;
    sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    c3_c_y = NULL;
    sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    sf_mex_call(&c3_st, &c3_emlrtMCI, "error", 0U, 2U, 14, c3_b_y, 14,
                sf_mex_call(&c3_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c3_st, NULL, "message", 1U, 1U, 14, c3_c_y)));
  }

  for (c3_c_k = 0; c3_c_k < 4; c3_c_k++) {
    c3_d_k = c3_c_k;
    c3_d_a = c3_b_a[c3_d_k];
    c3_d_y = muDoubleScalarPower(c3_d_a, 0.33333333333333331);
    c3_y[c3_d_k] = c3_d_y;
  }
}

static void c3_b_div0protect(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, real_T c3_u[4], real_T c3_y[4])
{
  emlrtStack c3_st;
  real_T c3_y_data[4];
  real_T c3_yabs[4];
  real_T c3_yabs_data[4];
  real_T c3_b_y;
  real_T c3_x;
  int32_T c3_tmp_data[4];
  int32_T c3_tmp_size[1];
  int32_T c3_y_size[1];
  int32_T c3_yabs_size[1];
  int32_T c3_b_i;
  int32_T c3_b_k;
  int32_T c3_b_loop_ub;
  int32_T c3_b_partialTrueCount;
  int32_T c3_b_trueCount;
  int32_T c3_c_i;
  int32_T c3_c_loop_ub;
  int32_T c3_d_i;
  int32_T c3_e_i;
  int32_T c3_f_i;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_k;
  int32_T c3_loop_ub;
  int32_T c3_partialTrueCount;
  int32_T c3_trueCount;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  for (c3_k = 0; c3_k < 4; c3_k++) {
    c3_b_k = c3_k;
    c3_x = c3_u[c3_b_k];
    c3_b_y = muDoubleScalarAbs(c3_x);
    c3_yabs[c3_b_k] = c3_b_y;
  }

  c3_trueCount = 0;
  for (c3_i = 0; c3_i < 4; c3_i++) {
    if (c3_yabs[c3_i] < 0.0001) {
      c3_trueCount++;
    }
  }

  c3_tmp_size[0] = c3_trueCount;
  c3_partialTrueCount = 0;
  for (c3_b_i = 0; c3_b_i < 4; c3_b_i++) {
    if (c3_yabs[c3_b_i] < 0.0001) {
      c3_tmp_data[c3_partialTrueCount] = c3_b_i + 1;
      c3_partialTrueCount++;
    }
  }

  c3_yabs_size[0] = c3_tmp_size[0];
  c3_loop_ub = c3_tmp_size[0] - 1;
  for (c3_c_i = 0; c3_c_i <= c3_loop_ub; c3_c_i++) {
    c3_yabs_data[c3_c_i] = c3_yabs[c3_tmp_data[c3_c_i] - 1] / 0.0001;
  }

  c3_st.site = &c3_b_emlrtRSI;
  c3_power(chartInstance, &c3_st, c3_yabs_data, c3_yabs_size, c3_y_data,
           c3_y_size);
  c3_b_loop_ub = c3_y_size[0] - 1;
  for (c3_i1 = 0; c3_i1 <= c3_b_loop_ub; c3_i1++) {
    c3_y_data[c3_i1] = 3.0 - c3_y_data[c3_i1];
  }

  c3_c_loop_ub = c3_y_size[0] - 1;
  for (c3_i2 = 0; c3_i2 <= c3_c_loop_ub; c3_i2++) {
    c3_y_data[c3_i2] = 0.0002 / c3_y_data[c3_i2];
  }

  c3_b_trueCount = 0;
  for (c3_d_i = 0; c3_d_i < 4; c3_d_i++) {
    if (c3_yabs[c3_d_i] < 0.0001) {
      c3_b_trueCount++;
    }
  }

  if (c3_b_trueCount != c3_y_size[0]) {
    emlrtSubAssignSizeCheck1dR2017a(c3_b_trueCount, c3_y_size[0], &c3_b_emlrtECI,
      (emlrtConstCTX)c3_sp);
  }

  c3_b_partialTrueCount = 0;
  for (c3_e_i = 0; c3_e_i < 4; c3_e_i++) {
    if (c3_yabs[c3_e_i] < 0.0001) {
      c3_yabs[c3_e_i] = c3_y_data[c3_b_partialTrueCount];
      c3_b_partialTrueCount++;
    }
  }

  for (c3_i3 = 0; c3_i3 < 4; c3_i3++) {
    c3_y[c3_i3] = c3_yabs[c3_i3];
  }

  for (c3_f_i = 0; c3_f_i < 4; c3_f_i++) {
    if (c3_u[c3_f_i] < 0.0) {
      c3_y[c3_f_i] = -c3_yabs[c3_f_i];
    }
  }
}

static boolean_T c3_any(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
  boolean_T c3_x[4])
{
  real_T c3_b_k;
  int32_T c3_i;
  int32_T c3_k;
  boolean_T c3_x_data[4];
  boolean_T c3_b_b;
  boolean_T c3_exitg1;
  boolean_T c3_y;
  (void)chartInstance;
  for (c3_i = 0; c3_i < 4; c3_i++) {
    c3_x_data[c3_i] = c3_x[c3_i];
  }

  c3_y = false;
  c3_k = 0;
  c3_exitg1 = false;
  while ((!c3_exitg1) && (c3_k < 4)) {
    c3_b_k = (real_T)c3_k + 1.0;
    if (!c3_x_data[(int32_T)c3_b_k - 1]) {
      c3_b_b = true;
    } else {
      c3_b_b = false;
    }

    if (!c3_b_b) {
      c3_y = true;
      c3_exitg1 = true;
    } else {
      c3_k++;
    }
  }

  return c3_y;
}

static void c3_atan(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
                    real_T c3_x_data[], int32_T c3_x_size[1], real_T
                    c3_b_x_data[], int32_T c3_b_x_size[1])
{
  int32_T c3_i;
  int32_T c3_loop_ub;
  c3_b_x_size[0] = c3_x_size[0];
  c3_loop_ub = c3_x_size[0] - 1;
  for (c3_i = 0; c3_i <= c3_loop_ub; c3_i++) {
    c3_b_x_data[c3_i] = c3_x_data[c3_i];
  }

  c3_b_atan(chartInstance, c3_b_x_data, c3_b_x_size);
}

static void c3_cos(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance, real_T
                   c3_x_data[], int32_T c3_x_size[1], real_T c3_b_x_data[],
                   int32_T c3_b_x_size[1])
{
  int32_T c3_i;
  int32_T c3_loop_ub;
  c3_b_x_size[0] = c3_x_size[0];
  c3_loop_ub = c3_x_size[0] - 1;
  for (c3_i = 0; c3_i <= c3_loop_ub; c3_i++) {
    c3_b_x_data[c3_i] = c3_x_data[c3_i];
  }

  c3_b_cos(chartInstance, c3_b_x_data, c3_b_x_size);
}

static void c3_c_sqrt(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
                      const emlrtStack *c3_sp, real_T c3_x_data[], int32_T
                      c3_x_size[1], real_T c3_b_x_data[], int32_T c3_b_x_size[1])
{
  int32_T c3_i;
  int32_T c3_loop_ub;
  c3_b_x_size[0] = c3_x_size[0];
  c3_loop_ub = c3_x_size[0] - 1;
  for (c3_i = 0; c3_i <= c3_loop_ub; c3_i++) {
    c3_b_x_data[c3_i] = c3_x_data[c3_i];
  }

  c3_f_sqrt(chartInstance, c3_sp, c3_b_x_data, c3_b_x_size);
}

static void c3_magicsin(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
  real_T c3_D[4], real_T c3_C, real_T c3_B[4], real_T c3_E, real_T c3_u[4],
  real_T c3_y[4])
{
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_e_x;
  real_T c3_f_x;
  real_T c3_x;
  int32_T c3_b_k;
  int32_T c3_c_k;
  int32_T c3_d_k;
  int32_T c3_e_k;
  int32_T c3_f_k;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_k;
  (void)chartInstance;
  for (c3_i = 0; c3_i < 4; c3_i++) {
    c3_y[c3_i] = c3_B[c3_i] * c3_u[c3_i];
  }

  for (c3_k = 0; c3_k < 4; c3_k++) {
    c3_b_k = c3_k;
    c3_x = c3_y[c3_b_k];
    c3_b_x = c3_x;
    c3_b_x = muDoubleScalarAtan(c3_b_x);
    c3_y[c3_b_k] = c3_b_x;
  }

  for (c3_i1 = 0; c3_i1 < 4; c3_i1++) {
    c3_y[c3_i1] = c3_B[c3_i1] * c3_u[c3_i1] - c3_E * (c3_B[c3_i1] * c3_u[c3_i1]
      - c3_y[c3_i1]);
  }

  for (c3_c_k = 0; c3_c_k < 4; c3_c_k++) {
    c3_d_k = c3_c_k;
    c3_c_x = c3_y[c3_d_k];
    c3_d_x = c3_c_x;
    c3_d_x = muDoubleScalarAtan(c3_d_x);
    c3_y[c3_d_k] = c3_d_x;
  }

  for (c3_i2 = 0; c3_i2 < 4; c3_i2++) {
    c3_y[c3_i2] *= c3_C;
  }

  for (c3_e_k = 0; c3_e_k < 4; c3_e_k++) {
    c3_f_k = c3_e_k;
    c3_e_x = c3_y[c3_f_k];
    c3_f_x = c3_e_x;
    c3_f_x = muDoubleScalarSin(c3_f_x);
    c3_y[c3_f_k] = c3_f_x;
  }

  for (c3_i3 = 0; c3_i3 < 4; c3_i3++) {
    c3_y[c3_i3] *= c3_D[c3_i3];
  }
}

static void c3_magiccos(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
  real_T c3_C, real_T c3_B[4], real_T c3_E[4], real_T c3_u[4], real_T c3_y[4])
{
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_e_x;
  real_T c3_f_x;
  real_T c3_x;
  int32_T c3_b_k;
  int32_T c3_c_k;
  int32_T c3_d_k;
  int32_T c3_e_k;
  int32_T c3_f_k;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_k;
  (void)chartInstance;
  for (c3_i = 0; c3_i < 4; c3_i++) {
    c3_y[c3_i] = c3_B[c3_i] * c3_u[c3_i];
  }

  for (c3_k = 0; c3_k < 4; c3_k++) {
    c3_b_k = c3_k;
    c3_x = c3_y[c3_b_k];
    c3_b_x = c3_x;
    c3_b_x = muDoubleScalarAtan(c3_b_x);
    c3_y[c3_b_k] = c3_b_x;
  }

  for (c3_i1 = 0; c3_i1 < 4; c3_i1++) {
    c3_y[c3_i1] = c3_B[c3_i1] * c3_u[c3_i1] - c3_E[c3_i1] * (c3_B[c3_i1] *
      c3_u[c3_i1] - c3_y[c3_i1]);
  }

  for (c3_c_k = 0; c3_c_k < 4; c3_c_k++) {
    c3_d_k = c3_c_k;
    c3_c_x = c3_y[c3_d_k];
    c3_d_x = c3_c_x;
    c3_d_x = muDoubleScalarAtan(c3_d_x);
    c3_y[c3_d_k] = c3_d_x;
  }

  for (c3_i2 = 0; c3_i2 < 4; c3_i2++) {
    c3_y[c3_i2] *= c3_C;
  }

  for (c3_e_k = 0; c3_e_k < 4; c3_e_k++) {
    c3_f_k = c3_e_k;
    c3_e_x = c3_y[c3_f_k];
    c3_f_x = c3_e_x;
    c3_f_x = muDoubleScalarCos(c3_f_x);
    c3_y[c3_f_k] = c3_f_x;
  }
}

static void c3_c_assertCompatibleDims(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, int32_T c3_x_size[1], int32_T
  c3_y_size[1])
{
  static char_T c3_b_cv[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd', 'i', 'm',
    'a', 'g', 'r', 'e', 'e' };

  const mxArray *c3_b_y = NULL;
  const mxArray *c3_y = NULL;
  boolean_T c3_b_p;
  boolean_T c3_p;
  (void)chartInstance;
  c3_p = ((real_T)c3_x_size[0] == (real_T)c3_y_size[0]);
  c3_b_p = c3_p;
  if (!c3_b_p) {
    c3_y = NULL;
    sf_mex_assign(&c3_y, sf_mex_create("y", c3_b_cv, 10, 0U, 1U, 0U, 2, 1, 15),
                  false);
    c3_b_y = NULL;
    sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_b_cv, 10, 0U, 1U, 0U, 2, 1, 15),
                  false);
    sf_mex_call(c3_sp, &c3_e_emlrtMCI, "error", 0U, 2U, 14, c3_y, 14,
                sf_mex_call(c3_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c3_sp, NULL, "message", 1U, 1U, 14, c3_b_y)));
  }
}

static void c3_acos(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance, const
                    emlrtStack *c3_sp, real_T c3_x_data[], int32_T c3_x_size[1],
                    real_T c3_b_x_data[], int32_T c3_b_x_size[1])
{
  int32_T c3_i;
  int32_T c3_loop_ub;
  c3_b_x_size[0] = c3_x_size[0];
  c3_loop_ub = c3_x_size[0] - 1;
  for (c3_i = 0; c3_i <= c3_loop_ub; c3_i++) {
    c3_b_x_data[c3_i] = c3_x_data[c3_i];
  }

  c3_b_acos(chartInstance, c3_sp, c3_b_x_data, c3_b_x_size);
}

static void c3_b_magicsin(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
  real_T c3_D[4], real_T c3_C[4], real_T c3_B[4], real_T c3_E[4], real_T c3_u[4],
  real_T c3_y[4])
{
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_e_x;
  real_T c3_f_x;
  real_T c3_x;
  int32_T c3_b_k;
  int32_T c3_c_k;
  int32_T c3_d_k;
  int32_T c3_e_k;
  int32_T c3_f_k;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_k;
  (void)chartInstance;
  for (c3_i = 0; c3_i < 4; c3_i++) {
    c3_y[c3_i] = c3_B[c3_i] * c3_u[c3_i];
  }

  for (c3_k = 0; c3_k < 4; c3_k++) {
    c3_b_k = c3_k;
    c3_x = c3_y[c3_b_k];
    c3_b_x = c3_x;
    c3_b_x = muDoubleScalarAtan(c3_b_x);
    c3_y[c3_b_k] = c3_b_x;
  }

  for (c3_i1 = 0; c3_i1 < 4; c3_i1++) {
    c3_y[c3_i1] = c3_B[c3_i1] * c3_u[c3_i1] - c3_E[c3_i1] * (c3_B[c3_i1] *
      c3_u[c3_i1] - c3_y[c3_i1]);
  }

  for (c3_c_k = 0; c3_c_k < 4; c3_c_k++) {
    c3_d_k = c3_c_k;
    c3_c_x = c3_y[c3_d_k];
    c3_d_x = c3_c_x;
    c3_d_x = muDoubleScalarAtan(c3_d_x);
    c3_y[c3_d_k] = c3_d_x;
  }

  for (c3_i2 = 0; c3_i2 < 4; c3_i2++) {
    c3_y[c3_i2] *= c3_C[c3_i2];
  }

  for (c3_e_k = 0; c3_e_k < 4; c3_e_k++) {
    c3_f_k = c3_e_k;
    c3_e_x = c3_y[c3_f_k];
    c3_f_x = c3_e_x;
    c3_f_x = muDoubleScalarSin(c3_f_x);
    c3_y[c3_f_k] = c3_f_x;
  }

  for (c3_i3 = 0; c3_i3 < 4; c3_i3++) {
    c3_y[c3_i3] *= c3_D[c3_i3];
  }
}

static void c3_b_magiccos(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
  real_T c3_C, real_T c3_B[4], real_T c3_E[4], real_T c3_u, real_T c3_y[4])
{
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_e_x;
  real_T c3_f_x;
  real_T c3_x;
  int32_T c3_b_k;
  int32_T c3_c_k;
  int32_T c3_d_k;
  int32_T c3_e_k;
  int32_T c3_f_k;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_k;
  (void)chartInstance;
  for (c3_i = 0; c3_i < 4; c3_i++) {
    c3_y[c3_i] = c3_B[c3_i] * c3_u;
  }

  for (c3_k = 0; c3_k < 4; c3_k++) {
    c3_b_k = c3_k;
    c3_x = c3_y[c3_b_k];
    c3_b_x = c3_x;
    c3_b_x = muDoubleScalarAtan(c3_b_x);
    c3_y[c3_b_k] = c3_b_x;
  }

  for (c3_i1 = 0; c3_i1 < 4; c3_i1++) {
    c3_y[c3_i1] = c3_B[c3_i1] * c3_u - c3_E[c3_i1] * (c3_B[c3_i1] * c3_u -
      c3_y[c3_i1]);
  }

  for (c3_c_k = 0; c3_c_k < 4; c3_c_k++) {
    c3_d_k = c3_c_k;
    c3_c_x = c3_y[c3_d_k];
    c3_d_x = c3_c_x;
    c3_d_x = muDoubleScalarAtan(c3_d_x);
    c3_y[c3_d_k] = c3_d_x;
  }

  for (c3_i2 = 0; c3_i2 < 4; c3_i2++) {
    c3_y[c3_i2] *= c3_C;
  }

  for (c3_e_k = 0; c3_e_k < 4; c3_e_k++) {
    c3_f_k = c3_e_k;
    c3_e_x = c3_y[c3_f_k];
    c3_f_x = c3_e_x;
    c3_f_x = muDoubleScalarCos(c3_f_x);
    c3_y[c3_f_k] = c3_f_x;
  }
}

static void c3_rollingMoment(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, real_T c3_b_Fx[4], real_T c3_Vcx[4],
  real_T c3_Fz[4], real_T c3_press[4], real_T c3_gamma[4], real_T c3_Vo, real_T
  c3_Ro, real_T c3_Fzo, real_T c3_pio, real_T c3_b_QSY1, real_T c3_b_QSY2,
  real_T c3_b_QSY3, real_T c3_b_QSY4, real_T c3_b_QSY5, real_T c3_b_QSY6, real_T
  c3_b_QSY7, real_T c3_b_QSY8, real_T c3_lam_My[4], real_T c3_b_My[4])
{
  emlrtStack c3_st;
  real_T c3_b_Fz[4];
  real_T c3_b_press[4];
  real_T c3_c_y[4];
  real_T c3_dv[4];
  real_T c3_x[4];
  real_T c3_b_Ro;
  real_T c3_b_a;
  real_T c3_b_x;
  real_T c3_b_y;
  real_T c3_y;
  int32_T c3_b_k;
  int32_T c3_c_k;
  int32_T c3_d_k;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_i4;
  int32_T c3_k;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  for (c3_i = 0; c3_i < 4; c3_i++) {
    c3_x[c3_i] = c3_Vcx[c3_i] / c3_Vo;
  }

  for (c3_k = 0; c3_k < 4; c3_k++) {
    c3_b_k = c3_k;
    c3_b_x = c3_x[c3_b_k];
    c3_y = muDoubleScalarAbs(c3_b_x);
    c3_b_My[c3_b_k] = c3_y;
  }

  for (c3_i1 = 0; c3_i1 < 4; c3_i1++) {
    c3_x[c3_i1] = c3_Vcx[c3_i1] / c3_Vo;
  }

  for (c3_c_k = 0; c3_c_k < 4; c3_c_k++) {
    c3_d_k = c3_c_k;
    c3_b_a = c3_x[c3_d_k];
    c3_b_y = muDoubleScalarPower(c3_b_a, 4.0);
    c3_c_y[c3_d_k] = c3_b_y;
  }

  for (c3_i2 = 0; c3_i2 < 4; c3_i2++) {
    c3_b_Fz[c3_i2] = c3_Fz[c3_i2] / c3_Fzo;
  }

  c3_st.site = &c3_b_emlrtRSI;
  c3_d_power(chartInstance, &c3_st, c3_b_Fz, c3_b_QSY7, c3_x);
  for (c3_i3 = 0; c3_i3 < 4; c3_i3++) {
    c3_b_press[c3_i3] = c3_press[c3_i3] / c3_pio;
  }

  c3_st.site = &c3_b_emlrtRSI;
  c3_d_power(chartInstance, &c3_st, c3_b_press, c3_b_QSY8, c3_dv);
  c3_b_Ro = -c3_Ro * c3_Fzo;
  for (c3_i4 = 0; c3_i4 < 4; c3_i4++) {
    c3_b_My[c3_i4] = c3_b_Ro * c3_lam_My[c3_i4] * ((((c3_b_QSY1 + c3_b_QSY2 *
      (c3_b_Fx[c3_i4] / c3_Fzo)) + c3_b_QSY3 * c3_b_My[c3_i4]) + c3_b_QSY4 *
      c3_c_y[c3_i4]) + (c3_b_QSY5 + c3_b_QSY6 * (c3_Fz[c3_i4] / c3_Fzo)) *
      c3_gamma[c3_i4] * c3_gamma[c3_i4]) * (c3_x[c3_i4] * c3_dv[c3_i4]);
  }
}

static void c3_d_power(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, real_T c3_b_a[4], real_T c3_b_b, real_T c3_y[4])
{
  emlrtStack c3_st;
  const mxArray *c3_b_y = NULL;
  const mxArray *c3_d_y = NULL;
  real_T c3_x_data[4];
  real_T c3_b_x;
  real_T c3_c_a;
  real_T c3_c_b;
  real_T c3_c_x;
  real_T c3_c_y;
  real_T c3_d_a;
  real_T c3_d_b;
  real_T c3_e_b;
  real_T c3_e_y;
  real_T c3_f_y;
  real_T c3_g_b;
  real_T c3_h_b;
  real_T c3_x;
  int32_T c3_b_k;
  int32_T c3_c_k;
  int32_T c3_d_k;
  int32_T c3_i;
  int32_T c3_k;
  boolean_T c3_b_p;
  boolean_T c3_c_p;
  boolean_T c3_d_p;
  boolean_T c3_e_p;
  boolean_T c3_f_b;
  boolean_T c3_p;
  (void)chartInstance;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_st.site = &c3_c_emlrtRSI;
  c3_c_b = c3_b_b;
  c3_d_b = c3_c_b;
  c3_e_b = c3_d_b;
  c3_x = c3_e_b;
  c3_f_b = muDoubleScalarIsNaN(c3_x);
  if (!c3_f_b) {
    c3_b_x = c3_e_b;
    c3_c_x = c3_b_x;
    c3_c_x = muDoubleScalarFloor(c3_c_x);
    if (c3_c_x != c3_e_b) {
      c3_p = true;
    } else {
      c3_p = false;
    }
  } else {
    c3_p = false;
  }

  c3_b_p = c3_p;
  if (c3_b_p) {
    for (c3_i = 0; c3_i < 4; c3_i++) {
      c3_x_data[c3_i] = c3_b_a[c3_i];
    }

    c3_c_p = false;
    for (c3_k = 0; c3_k < 4; c3_k++) {
      c3_b_k = c3_k;
      if (c3_c_p) {
        c3_d_p = true;
      } else {
        c3_c_a = c3_x_data[c3_b_k];
        c3_e_p = (c3_c_a < 0.0);
        if (c3_e_p) {
          c3_d_p = true;
        } else {
          c3_d_p = false;
        }
      }

      c3_c_p = c3_d_p;
    }
  } else {
    c3_c_p = false;
  }

  if (c3_c_p) {
    c3_b_y = NULL;
    sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    c3_d_y = NULL;
    sf_mex_assign(&c3_d_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    sf_mex_call(&c3_st, &c3_emlrtMCI, "error", 0U, 2U, 14, c3_b_y, 14,
                sf_mex_call(&c3_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c3_st, NULL, "message", 1U, 1U, 14, c3_d_y)));
  }

  c3_g_b = c3_c_b;
  c3_c_y = c3_g_b;
  c3_e_y = c3_c_y;
  for (c3_c_k = 0; c3_c_k < 4; c3_c_k++) {
    c3_d_k = c3_c_k;
    c3_d_a = c3_b_a[c3_d_k];
    c3_h_b = c3_e_y;
    c3_f_y = muDoubleScalarPower(c3_d_a, c3_h_b);
    c3_y[c3_d_k] = c3_f_y;
  }
}

static void c3_c_magiccos(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
  real_T c3_D[4], real_T c3_C[4], real_T c3_B[4], real_T c3_u[4], real_T c3_y[4])
{
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_e_x;
  real_T c3_f_x;
  real_T c3_x;
  int32_T c3_b_k;
  int32_T c3_c_k;
  int32_T c3_d_k;
  int32_T c3_e_k;
  int32_T c3_f_k;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_k;
  (void)chartInstance;
  for (c3_i = 0; c3_i < 4; c3_i++) {
    c3_y[c3_i] = c3_B[c3_i] * c3_u[c3_i];
  }

  for (c3_k = 0; c3_k < 4; c3_k++) {
    c3_b_k = c3_k;
    c3_x = c3_y[c3_b_k];
    c3_b_x = c3_x;
    c3_b_x = muDoubleScalarAtan(c3_b_x);
    c3_y[c3_b_k] = c3_b_x;
  }

  for (c3_i1 = 0; c3_i1 < 4; c3_i1++) {
    c3_y[c3_i1] = c3_B[c3_i1] * c3_u[c3_i1] - 0.0 * (c3_B[c3_i1] * c3_u[c3_i1] -
      c3_y[c3_i1]);
  }

  for (c3_c_k = 0; c3_c_k < 4; c3_c_k++) {
    c3_d_k = c3_c_k;
    c3_c_x = c3_y[c3_d_k];
    c3_d_x = c3_c_x;
    c3_d_x = muDoubleScalarAtan(c3_d_x);
    c3_y[c3_d_k] = c3_d_x;
  }

  for (c3_i2 = 0; c3_i2 < 4; c3_i2++) {
    c3_y[c3_i2] *= c3_C[c3_i2];
  }

  for (c3_e_k = 0; c3_e_k < 4; c3_e_k++) {
    c3_f_k = c3_e_k;
    c3_e_x = c3_y[c3_f_k];
    c3_f_x = c3_e_x;
    c3_f_x = muDoubleScalarCos(c3_f_x);
    c3_y[c3_f_k] = c3_f_x;
  }

  for (c3_i3 = 0; c3_i3 < 4; c3_i3++) {
    c3_y[c3_i3] *= c3_D[c3_i3];
  }
}

static void c3_d_magiccos(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
  real_T c3_D[4], real_T c3_C, real_T c3_B[4], real_T c3_E[4], real_T c3_u[4],
  real_T c3_y[4])
{
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_e_x;
  real_T c3_f_x;
  real_T c3_x;
  int32_T c3_b_k;
  int32_T c3_c_k;
  int32_T c3_d_k;
  int32_T c3_e_k;
  int32_T c3_f_k;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_k;
  (void)chartInstance;
  for (c3_i = 0; c3_i < 4; c3_i++) {
    c3_y[c3_i] = c3_B[c3_i] * c3_u[c3_i];
  }

  for (c3_k = 0; c3_k < 4; c3_k++) {
    c3_b_k = c3_k;
    c3_x = c3_y[c3_b_k];
    c3_b_x = c3_x;
    c3_b_x = muDoubleScalarAtan(c3_b_x);
    c3_y[c3_b_k] = c3_b_x;
  }

  for (c3_i1 = 0; c3_i1 < 4; c3_i1++) {
    c3_y[c3_i1] = c3_B[c3_i1] * c3_u[c3_i1] - c3_E[c3_i1] * (c3_B[c3_i1] *
      c3_u[c3_i1] - c3_y[c3_i1]);
  }

  for (c3_c_k = 0; c3_c_k < 4; c3_c_k++) {
    c3_d_k = c3_c_k;
    c3_c_x = c3_y[c3_d_k];
    c3_d_x = c3_c_x;
    c3_d_x = muDoubleScalarAtan(c3_d_x);
    c3_y[c3_d_k] = c3_d_x;
  }

  for (c3_i2 = 0; c3_i2 < 4; c3_i2++) {
    c3_y[c3_i2] *= c3_C;
  }

  for (c3_e_k = 0; c3_e_k < 4; c3_e_k++) {
    c3_f_k = c3_e_k;
    c3_e_x = c3_y[c3_f_k];
    c3_f_x = c3_e_x;
    c3_f_x = muDoubleScalarCos(c3_f_x);
    c3_y[c3_f_k] = c3_f_x;
  }

  for (c3_i3 = 0; c3_i3 < 4; c3_i3++) {
    c3_y[c3_i3] *= c3_D[c3_i3];
  }
}

static void c3_b_vdyncsmtire(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, real_T c3_b_Omega[4], real_T c3_b_Vx
  [4], real_T c3_b_Vy[4], real_T c3_b_psidot[4], real_T c3_gamma[4], real_T
  c3_press[4], real_T c3_scaleFactors[108], real_T c3_b_rhoz[4], real_T
  c3_b_turnslip, real_T c3_b_PRESMAX, real_T c3_b_PRESMIN, real_T c3_b_FZMAX,
  real_T c3_b_FZMIN, real_T c3_b_VXLOW, real_T c3_b_KPUMAX, real_T c3_b_KPUMIN,
  real_T c3_b_ALPMAX, real_T c3_b_ALPMIN, real_T c3_b_CAMMIN, real_T c3_b_CAMMAX,
  real_T c3_b_LONGVL, real_T c3_b_UNLOADED_RADIUS, real_T c3_b_RIM_RADIUS,
  real_T c3_b_NOMPRES, real_T c3_b_FNOMIN, real_T c3_b_VERTICAL_STIFFNESS,
  real_T c3_b_DREFF, real_T c3_b_BREFF, real_T c3_b_FREFF, real_T c3_b_Q_RE0,
  real_T c3_b_Q_V1, real_T c3_b_Q_V2, real_T c3_b_Q_FZ1, real_T c3_b_Q_FZ2,
  real_T c3_b_Q_FCX, real_T c3_b_Q_FCY, real_T c3_b_PFZ1, real_T c3_b_Q_FCY2,
  real_T c3_b_BOTTOM_OFFST, real_T c3_b_BOTTOM_STIFF, real_T c3_b_PCX1, real_T
  c3_b_PDX1, real_T c3_b_PDX2, real_T c3_b_PDX3, real_T c3_b_PEX1, real_T
  c3_b_PEX2, real_T c3_b_PEX3, real_T c3_b_PEX4, real_T c3_b_PKX1, real_T
  c3_b_PKX2, real_T c3_b_PKX3, real_T c3_b_PHX1, real_T c3_b_PHX2, real_T
  c3_b_PVX1, real_T c3_b_PVX2, real_T c3_b_PPX1, real_T c3_b_PPX2, real_T
  c3_b_PPX3, real_T c3_b_PPX4, real_T c3_b_RBX1, real_T c3_b_RBX2, real_T
  c3_b_RBX3, real_T c3_b_RCX1, real_T c3_b_REX1, real_T c3_b_REX2, real_T
  c3_b_RHX1, real_T c3_b_QSX1, real_T c3_b_QSX2, real_T c3_b_QSX3, real_T
  c3_b_QSX4, real_T c3_b_QSX5, real_T c3_b_QSX6, real_T c3_b_QSX7, real_T
  c3_b_QSX8, real_T c3_b_QSX9, real_T c3_b_QSX10, real_T c3_b_QSX11, real_T
  c3_b_PPMX1, real_T c3_b_PCY1, real_T c3_b_PDY1, real_T c3_b_PDY2, real_T
  c3_b_PDY3, real_T c3_b_PEY1, real_T c3_b_PEY2, real_T c3_b_PEY3, real_T
  c3_b_PEY4, real_T c3_b_PEY5, real_T c3_b_PKY1, real_T c3_b_PKY2, real_T
  c3_b_PKY3, real_T c3_b_PKY4, real_T c3_b_PKY5, real_T c3_b_PKY6, real_T
  c3_b_PKY7, real_T c3_b_PHY1, real_T c3_b_PHY2, real_T c3_b_PVY1, real_T
  c3_b_PVY2, real_T c3_b_PVY3, real_T c3_b_PVY4, real_T c3_b_PPY1, real_T
  c3_b_PPY2, real_T c3_b_PPY3, real_T c3_b_PPY4, real_T c3_b_PPY5, real_T
  c3_b_RBY1, real_T c3_b_RBY2, real_T c3_b_RBY3, real_T c3_b_RBY4, real_T
  c3_b_RCY1, real_T c3_b_REY1, real_T c3_b_REY2, real_T c3_b_RHY1, real_T
  c3_b_RHY2, real_T c3_b_RVY1, real_T c3_b_RVY2, real_T c3_b_RVY3, real_T
  c3_b_RVY4, real_T c3_b_RVY5, real_T c3_b_RVY6, real_T c3_b_QSY1, real_T
  c3_b_QSY2, real_T c3_b_QSY3, real_T c3_b_QSY4, real_T c3_b_QSY5, real_T
  c3_b_QSY6, real_T c3_b_QSY7, real_T c3_b_QSY8, real_T c3_b_QBZ1, real_T
  c3_b_QBZ2, real_T c3_b_QBZ3, real_T c3_b_QBZ4, real_T c3_b_QBZ5, real_T
  c3_b_QBZ6, real_T c3_b_QBZ9, real_T c3_b_QBZ10, real_T c3_b_QCZ1, real_T
  c3_b_QDZ1, real_T c3_b_QDZ2, real_T c3_b_QDZ3, real_T c3_b_QDZ4, real_T
  c3_b_QDZ6, real_T c3_b_QDZ7, real_T c3_b_QDZ8, real_T c3_b_QDZ9, real_T
  c3_b_QDZ10, real_T c3_b_QDZ11, real_T c3_b_QEZ1, real_T c3_b_QEZ2, real_T
  c3_b_QEZ3, real_T c3_b_QEZ4, real_T c3_b_QEZ5, real_T c3_b_QHZ1, real_T
  c3_b_QHZ2, real_T c3_b_QHZ3, real_T c3_b_QHZ4, real_T c3_b_PPZ1, real_T
  c3_b_PPZ2, real_T c3_b_SSZ1, real_T c3_b_SSZ2, real_T c3_b_SSZ3, real_T
  c3_b_SSZ4, real_T c3_b_PDXP1, real_T c3_b_PDXP2, real_T c3_b_PDXP3, real_T
  c3_b_PKYP1, real_T c3_b_PDYP1, real_T c3_b_PDYP2, real_T c3_b_PDYP3, real_T
  c3_b_PDYP4, real_T c3_b_PHYP1, real_T c3_b_PHYP2, real_T c3_b_PHYP3, real_T
  c3_b_PHYP4, real_T c3_b_PECP1, real_T c3_b_PECP2, real_T c3_b_QDTP1, real_T
  c3_b_QCRP1, real_T c3_b_QCRP2, real_T c3_b_QBRP1, real_T c3_b_QDRP1, real_T
  c3_b_QDRP2, real_T c3_b_WIDTH, real_T c3_b_Q_RA1, real_T c3_b_Q_RA2, real_T
  c3_b_Q_RB1, real_T c3_b_Q_RB2, real_T c3_b_QSX12, real_T c3_b_QSX13, real_T
  c3_b_QSX14, real_T c3_b_Q_FZ3, real_T c3_b_LONGITUDINAL_STIFFNESS, real_T
  c3_b_LATERAL_STIFFNESS, real_T c3_b_PCFX1, real_T c3_b_PCFX2, real_T
  c3_b_PCFX3, real_T c3_b_PCFY1, real_T c3_b_PCFY2, real_T c3_b_PCFY3, real_T
  c3_b_Fx_ext[4], real_T c3_b_Fy_ext[4], real_T c3_b_Fx[4], real_T c3_b_Fy[4],
  real_T c3_Fz[4], real_T c3_b_Mx[4], real_T c3_b_My[4], real_T c3_b_Mz[4],
  real_T c3_b_Re[4], real_T c3_kappa[4], real_T c3_alpha[4], real_T c3_b_sig_x[4],
  real_T c3_b_sig_y[4], real_T c3_patch_a[4], real_T c3_patch_b[4])
{
  emlrtStack c3_b_st;
  emlrtStack c3_c_st;
  emlrtStack c3_st;
  real_T c3_zeta[36];
  real_T c3_Bykappa[4];
  real_T c3_FzUnSat[4];
  real_T c3_Fz_btm[4];
  real_T c3_Fzo_prime[4];
  real_T c3_Kyalpha[4];
  real_T c3_Kyalpha_prime[4];
  real_T c3_SHy[4];
  real_T c3_SHyphi[4];
  real_T c3_SVygamma[4];
  real_T c3_Vc_prime[4];
  real_T c3_Vc_prime_data[4];
  real_T c3_Vs[4];
  real_T c3_Vsy[4];
  real_T c3_Vx_data[4];
  real_T c3_ab_tmp_data[4];
  real_T c3_b_Bykappa[4];
  real_T c3_b_FzUnSat[4];
  real_T c3_b_Vc_prime_data[4];
  real_T c3_b_Vsy[4];
  real_T c3_c_UNLOADED_RADIUS[4];
  real_T c3_c_Vc_prime_data[4];
  real_T c3_cosprimealpha[4];
  real_T c3_d_tmp_data[4];
  real_T c3_dfz[4];
  real_T c3_dpi[4];
  real_T c3_e_UNLOADED_RADIUS[4];
  real_T c3_e_y[4];
  real_T c3_epsilon_gamma[4];
  real_T c3_f_x[4];
  real_T c3_gamma_star[4];
  real_T c3_hb_tmp_data[4];
  real_T c3_lam_Cx[4];
  real_T c3_lam_Cy[4];
  real_T c3_lam_Cz[4];
  real_T c3_lam_Cz_data[4];
  real_T c3_lam_Ex[4];
  real_T c3_lam_Ey[4];
  real_T c3_lam_Fzo[4];
  real_T c3_lam_Hx[4];
  real_T c3_lam_Hy[4];
  real_T c3_lam_Kxkappa[4];
  real_T c3_lam_Kyalpha[4];
  real_T c3_lam_Kygamma[4];
  real_T c3_lam_Kzgamma[4];
  real_T c3_lam_Mphi[4];
  real_T c3_lam_Mr[4];
  real_T c3_lam_My[4];
  real_T c3_lam_VMx[4];
  real_T c3_lam_Vx[4];
  real_T c3_lam_Vy[4];
  real_T c3_lam_Vykappa[4];
  real_T c3_lam_muV[4];
  real_T c3_lam_mux[4];
  real_T c3_lam_mux_prime[4];
  real_T c3_lam_muy[4];
  real_T c3_lam_muy_prime[4];
  real_T c3_lam_s[4];
  real_T c3_lam_t[4];
  real_T c3_lam_xalpha[4];
  real_T c3_lam_ykappa[4];
  real_T c3_mu_x[4];
  real_T c3_mu_y[4];
  real_T c3_phi_t[4];
  real_T c3_rhoz_data[4];
  real_T c3_tmpDrphiVar_data[4];
  real_T c3_y_data[4];
  real_T c3_b_y_data[1];
  real_T c3_c_tmp_data[1];
  real_T c3_dv[1];
  real_T c3_dv1[1];
  real_T c3_dv2[1];
  real_T c3_dv3[1];
  real_T c3_dv4[1];
  real_T c3_dv5[1];
  real_T c3_dv6[1];
  real_T c3_x_data[1];
  real_T c3_CDrphi;
  real_T c3_CHyphi;
  real_T c3_Ct;
  real_T c3_EDrphi;
  real_T c3_EHyphi;
  real_T c3_ab_a;
  real_T c3_ab_x;
  real_T c3_ab_y;
  real_T c3_ac_x;
  real_T c3_ac_y;
  real_T c3_ad_x;
  real_T c3_ae_x;
  real_T c3_b_a;
  real_T c3_b_y;
  real_T c3_bb_a;
  real_T c3_bb_x;
  real_T c3_bb_y;
  real_T c3_bc_x;
  real_T c3_bc_y;
  real_T c3_bd_x;
  real_T c3_be_x;
  real_T c3_c_PKYP1;
  real_T c3_c_QBRP1;
  real_T c3_c_QCRP2;
  real_T c3_c_QDTP1;
  real_T c3_c_RIM_RADIUS;
  real_T c3_c_a;
  real_T c3_c_x;
  real_T c3_c_y;
  real_T c3_cb_a;
  real_T c3_cb_x;
  real_T c3_cb_y;
  real_T c3_cc_x;
  real_T c3_cc_y;
  real_T c3_cd_x;
  real_T c3_ce_x;
  real_T c3_d;
  real_T c3_d_UNLOADED_RADIUS;
  real_T c3_d_a;
  real_T c3_d_x;
  real_T c3_d_y;
  real_T c3_db_a;
  real_T c3_db_x;
  real_T c3_db_y;
  real_T c3_dc_x;
  real_T c3_dd_x;
  real_T c3_de_x;
  real_T c3_e_a;
  real_T c3_e_x;
  real_T c3_eb_a;
  real_T c3_eb_x;
  real_T c3_eb_y;
  real_T c3_ec_x;
  real_T c3_ed_x;
  real_T c3_ee_x;
  real_T c3_ex;
  real_T c3_f_a;
  real_T c3_f_y;
  real_T c3_fb_a;
  real_T c3_fb_x;
  real_T c3_fb_y;
  real_T c3_fc_x;
  real_T c3_fd_x;
  real_T c3_fe_x;
  real_T c3_g_a;
  real_T c3_g_x;
  real_T c3_g_y;
  real_T c3_gb_a;
  real_T c3_gb_x;
  real_T c3_gb_y;
  real_T c3_gc_x;
  real_T c3_gd_x;
  real_T c3_ge_x;
  real_T c3_h_a;
  real_T c3_h_x;
  real_T c3_h_y;
  real_T c3_hb_a;
  real_T c3_hb_x;
  real_T c3_hb_y;
  real_T c3_hc_x;
  real_T c3_hd_x;
  real_T c3_he_x;
  real_T c3_i_a;
  real_T c3_i_x;
  real_T c3_i_y;
  real_T c3_ib_a;
  real_T c3_ib_x;
  real_T c3_ib_y;
  real_T c3_ic_x;
  real_T c3_id_x;
  real_T c3_ie_x;
  real_T c3_j_a;
  real_T c3_j_x;
  real_T c3_j_y;
  real_T c3_jb_a;
  real_T c3_jb_x;
  real_T c3_jb_y;
  real_T c3_jc_x;
  real_T c3_jd_x;
  real_T c3_je_x;
  real_T c3_k_a;
  real_T c3_k_x;
  real_T c3_k_y;
  real_T c3_kb_a;
  real_T c3_kb_x;
  real_T c3_kb_y;
  real_T c3_kc_x;
  real_T c3_kd_x;
  real_T c3_ke_x;
  real_T c3_l_a;
  real_T c3_l_x;
  real_T c3_l_y;
  real_T c3_lb_a;
  real_T c3_lb_x;
  real_T c3_lb_y;
  real_T c3_lc_x;
  real_T c3_ld_x;
  real_T c3_le_x;
  real_T c3_m_a;
  real_T c3_m_x;
  real_T c3_m_y;
  real_T c3_mb_a;
  real_T c3_mb_x;
  real_T c3_mb_y;
  real_T c3_mc_x;
  real_T c3_md_x;
  real_T c3_me_x;
  real_T c3_n_a;
  real_T c3_n_x;
  real_T c3_n_y;
  real_T c3_nb_a;
  real_T c3_nb_x;
  real_T c3_nb_y;
  real_T c3_nc_x;
  real_T c3_nd_x;
  real_T c3_ne_x;
  real_T c3_o_a;
  real_T c3_o_x;
  real_T c3_o_y;
  real_T c3_ob_a;
  real_T c3_ob_x;
  real_T c3_ob_y;
  real_T c3_oc_x;
  real_T c3_od_x;
  real_T c3_p_a;
  real_T c3_p_x;
  real_T c3_p_y;
  real_T c3_pb_a;
  real_T c3_pb_x;
  real_T c3_pb_y;
  real_T c3_pc_x;
  real_T c3_pd_x;
  real_T c3_q_a;
  real_T c3_q_x;
  real_T c3_q_y;
  real_T c3_qb_a;
  real_T c3_qb_x;
  real_T c3_qb_y;
  real_T c3_qc_x;
  real_T c3_qd_x;
  real_T c3_r;
  real_T c3_r_a;
  real_T c3_r_x;
  real_T c3_r_y;
  real_T c3_rb_a;
  real_T c3_rb_x;
  real_T c3_rb_y;
  real_T c3_rc_x;
  real_T c3_rd_x;
  real_T c3_s_a;
  real_T c3_s_x;
  real_T c3_s_y;
  real_T c3_sb_x;
  real_T c3_sb_y;
  real_T c3_sc_x;
  real_T c3_sd_x;
  real_T c3_t_a;
  real_T c3_t_x;
  real_T c3_t_y;
  real_T c3_tb_x;
  real_T c3_tb_y;
  real_T c3_tc_x;
  real_T c3_td_x;
  real_T c3_u_a;
  real_T c3_u_x;
  real_T c3_u_y;
  real_T c3_ub_x;
  real_T c3_ub_y;
  real_T c3_uc_x;
  real_T c3_ud_x;
  real_T c3_v_a;
  real_T c3_v_x;
  real_T c3_v_y;
  real_T c3_vb_x;
  real_T c3_vb_y;
  real_T c3_vc_x;
  real_T c3_vd_x;
  real_T c3_w_a;
  real_T c3_w_x;
  real_T c3_w_y;
  real_T c3_wb_x;
  real_T c3_wb_y;
  real_T c3_wc_x;
  real_T c3_wd_x;
  real_T c3_x_a;
  real_T c3_x_x;
  real_T c3_x_y;
  real_T c3_xb_x;
  real_T c3_xb_y;
  real_T c3_xc_x;
  real_T c3_xd_x;
  real_T c3_y_a;
  real_T c3_y_x;
  real_T c3_y_y;
  real_T c3_yb_x;
  real_T c3_yb_y;
  real_T c3_yc_x;
  real_T c3_yd_x;
  int32_T c3_b_tmp_data[4];
  int32_T c3_bb_tmp_data[4];
  int32_T c3_cb_tmp_data[4];
  int32_T c3_db_tmp_data[4];
  int32_T c3_e_tmp_data[4];
  int32_T c3_eb_tmp_data[4];
  int32_T c3_f_tmp_data[4];
  int32_T c3_fb_tmp_data[4];
  int32_T c3_g_tmp_data[4];
  int32_T c3_gb_tmp_data[4];
  int32_T c3_h_tmp_data[4];
  int32_T c3_i_tmp_data[4];
  int32_T c3_ib_tmp_data[4];
  int32_T c3_j_tmp_data[4];
  int32_T c3_jb_tmp_data[4];
  int32_T c3_k_tmp_data[4];
  int32_T c3_l_tmp_data[4];
  int32_T c3_m_tmp_data[4];
  int32_T c3_n_tmp_data[4];
  int32_T c3_o_tmp_data[4];
  int32_T c3_p_tmp_data[4];
  int32_T c3_q_tmp_data[4];
  int32_T c3_r_tmp_data[4];
  int32_T c3_s_tmp_data[4];
  int32_T c3_t_tmp_data[4];
  int32_T c3_u_tmp_data[4];
  int32_T c3_v_tmp_data[4];
  int32_T c3_w_tmp_data[4];
  int32_T c3_x_tmp_data[4];
  int32_T c3_y_tmp_data[4];
  int32_T c3_b_y_size[2];
  int32_T c3_c_tmp_size[2];
  int32_T c3_iv[2];
  int32_T c3_iv1[2];
  int32_T c3_iv10[2];
  int32_T c3_iv11[2];
  int32_T c3_iv12[2];
  int32_T c3_iv13[2];
  int32_T c3_iv14[2];
  int32_T c3_iv15[2];
  int32_T c3_iv16[2];
  int32_T c3_iv2[2];
  int32_T c3_iv3[2];
  int32_T c3_iv4[2];
  int32_T c3_iv5[2];
  int32_T c3_iv6[2];
  int32_T c3_iv7[2];
  int32_T c3_iv8[2];
  int32_T c3_iv9[2];
  int32_T c3_tmp_size[2];
  int32_T c3_x_size[2];
  int32_T c3_Vc_prime_size[1];
  int32_T c3_Vx_size[1];
  int32_T c3_ab_tmp_size[1];
  int32_T c3_b_Vc_prime_size[1];
  int32_T c3_b_tmp_size[1];
  int32_T c3_bb_tmp_size[1];
  int32_T c3_c_Vc_prime_size[1];
  int32_T c3_cb_tmp_size[1];
  int32_T c3_d_tmp_size[1];
  int32_T c3_db_tmp_size[1];
  int32_T c3_e_tmp_size[1];
  int32_T c3_eb_tmp_size[1];
  int32_T c3_ec_trueCount[1];
  int32_T c3_f_tmp_size[1];
  int32_T c3_fb_tmp_size[1];
  int32_T c3_g_tmp_size[1];
  int32_T c3_gb_tmp_size[1];
  int32_T c3_h_tmp_size[1];
  int32_T c3_hb_tmp_size[1];
  int32_T c3_i_tmp_size[1];
  int32_T c3_ib_tmp_size[1];
  int32_T c3_j_tmp_size[1];
  int32_T c3_jb_tmp_size[1];
  int32_T c3_k_tmp_size[1];
  int32_T c3_kb_tmp_size[1];
  int32_T c3_l_tmp_size[1];
  int32_T c3_lam_Cz_size[1];
  int32_T c3_lb_tmp_size[1];
  int32_T c3_m_tmp_size[1];
  int32_T c3_n_tmp_size[1];
  int32_T c3_o_tmp_size[1];
  int32_T c3_p_tmp_size[1];
  int32_T c3_q_tmp_size[1];
  int32_T c3_r_tmp_size[1];
  int32_T c3_rhoz_size[1];
  int32_T c3_s_tmp_size[1];
  int32_T c3_t_tmp_size[1];
  int32_T c3_tmpDrphiVar_size[1];
  int32_T c3_tmp_data[1];
  int32_T c3_u_tmp_size[1];
  int32_T c3_v_tmp_size[1];
  int32_T c3_w_tmp_size[1];
  int32_T c3_x_tmp_size[1];
  int32_T c3_y_size[1];
  int32_T c3_y_tmp_size[1];
  int32_T c3_ab_i;
  int32_T c3_ab_k;
  int32_T c3_ab_loop_ub;
  int32_T c3_ab_partialTrueCount;
  int32_T c3_ab_trueCount;
  int32_T c3_ac_i;
  int32_T c3_ac_k;
  int32_T c3_ac_loop_ub;
  int32_T c3_ac_trueCount;
  int32_T c3_ad_i;
  int32_T c3_ad_k;
  int32_T c3_ae_i;
  int32_T c3_ae_k;
  int32_T c3_af_i;
  int32_T c3_af_k;
  int32_T c3_ag_k;
  int32_T c3_ah_k;
  int32_T c3_b_end;
  int32_T c3_b_i;
  int32_T c3_b_k;
  int32_T c3_b_loop_ub;
  int32_T c3_b_partialTrueCount;
  int32_T c3_b_trueCount;
  int32_T c3_bb_i;
  int32_T c3_bb_k;
  int32_T c3_bb_loop_ub;
  int32_T c3_bb_partialTrueCount;
  int32_T c3_bb_trueCount;
  int32_T c3_bc_i;
  int32_T c3_bc_k;
  int32_T c3_bc_loop_ub;
  int32_T c3_bc_trueCount;
  int32_T c3_bd_i;
  int32_T c3_bd_k;
  int32_T c3_be_i;
  int32_T c3_be_k;
  int32_T c3_bf_i;
  int32_T c3_bf_k;
  int32_T c3_bg_k;
  int32_T c3_bh_k;
  int32_T c3_c_i;
  int32_T c3_c_k;
  int32_T c3_c_loop_ub;
  int32_T c3_c_partialTrueCount;
  int32_T c3_c_trueCount;
  int32_T c3_cb_i;
  int32_T c3_cb_k;
  int32_T c3_cb_loop_ub;
  int32_T c3_cb_partialTrueCount;
  int32_T c3_cb_trueCount;
  int32_T c3_cc_i;
  int32_T c3_cc_k;
  int32_T c3_cc_loop_ub;
  int32_T c3_cc_trueCount;
  int32_T c3_cd_i;
  int32_T c3_cd_k;
  int32_T c3_ce_i;
  int32_T c3_ce_k;
  int32_T c3_cf_i;
  int32_T c3_cf_k;
  int32_T c3_cg_k;
  int32_T c3_ch_k;
  int32_T c3_d_i;
  int32_T c3_d_k;
  int32_T c3_d_loop_ub;
  int32_T c3_d_partialTrueCount;
  int32_T c3_d_trueCount;
  int32_T c3_db_i;
  int32_T c3_db_k;
  int32_T c3_db_loop_ub;
  int32_T c3_db_partialTrueCount;
  int32_T c3_db_trueCount;
  int32_T c3_dc_i;
  int32_T c3_dc_k;
  int32_T c3_dc_loop_ub;
  int32_T c3_dc_trueCount;
  int32_T c3_dd_i;
  int32_T c3_dd_k;
  int32_T c3_de_i;
  int32_T c3_de_k;
  int32_T c3_df_i;
  int32_T c3_df_k;
  int32_T c3_dg_k;
  int32_T c3_dh_k;
  int32_T c3_e_i;
  int32_T c3_e_k;
  int32_T c3_e_loop_ub;
  int32_T c3_e_partialTrueCount;
  int32_T c3_e_trueCount;
  int32_T c3_eb_i;
  int32_T c3_eb_k;
  int32_T c3_eb_loop_ub;
  int32_T c3_eb_partialTrueCount;
  int32_T c3_eb_trueCount;
  int32_T c3_ec_i;
  int32_T c3_ec_k;
  int32_T c3_ec_loop_ub;
  int32_T c3_ed_i;
  int32_T c3_ed_k;
  int32_T c3_ee_i;
  int32_T c3_ee_k;
  int32_T c3_ef_i;
  int32_T c3_ef_k;
  int32_T c3_eg_k;
  int32_T c3_eh_k;
  int32_T c3_end;
  int32_T c3_f_i;
  int32_T c3_f_k;
  int32_T c3_f_loop_ub;
  int32_T c3_f_partialTrueCount;
  int32_T c3_f_trueCount;
  int32_T c3_fb_i;
  int32_T c3_fb_k;
  int32_T c3_fb_loop_ub;
  int32_T c3_fb_partialTrueCount;
  int32_T c3_fb_trueCount;
  int32_T c3_fc_i;
  int32_T c3_fc_k;
  int32_T c3_fc_loop_ub;
  int32_T c3_fc_trueCount;
  int32_T c3_fd_i;
  int32_T c3_fd_k;
  int32_T c3_fe_i;
  int32_T c3_fe_k;
  int32_T c3_ff_i;
  int32_T c3_ff_k;
  int32_T c3_fg_k;
  int32_T c3_fh_k;
  int32_T c3_g_i;
  int32_T c3_g_k;
  int32_T c3_g_loop_ub;
  int32_T c3_g_partialTrueCount;
  int32_T c3_g_trueCount;
  int32_T c3_gb_i;
  int32_T c3_gb_k;
  int32_T c3_gb_loop_ub;
  int32_T c3_gb_partialTrueCount;
  int32_T c3_gb_trueCount;
  int32_T c3_gc_i;
  int32_T c3_gc_k;
  int32_T c3_gc_loop_ub;
  int32_T c3_gc_trueCount;
  int32_T c3_gd_i;
  int32_T c3_gd_k;
  int32_T c3_ge_i;
  int32_T c3_ge_k;
  int32_T c3_gf_i;
  int32_T c3_gf_k;
  int32_T c3_gg_k;
  int32_T c3_gh_k;
  int32_T c3_h_i;
  int32_T c3_h_k;
  int32_T c3_h_loop_ub;
  int32_T c3_h_partialTrueCount;
  int32_T c3_h_trueCount;
  int32_T c3_hb_i;
  int32_T c3_hb_k;
  int32_T c3_hb_loop_ub;
  int32_T c3_hb_partialTrueCount;
  int32_T c3_hb_trueCount;
  int32_T c3_hc_i;
  int32_T c3_hc_k;
  int32_T c3_hc_loop_ub;
  int32_T c3_hc_trueCount;
  int32_T c3_hd_i;
  int32_T c3_hd_k;
  int32_T c3_he_i;
  int32_T c3_he_k;
  int32_T c3_hf_i;
  int32_T c3_hf_k;
  int32_T c3_hg_k;
  int32_T c3_hh_k;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i10;
  int32_T c3_i100;
  int32_T c3_i101;
  int32_T c3_i102;
  int32_T c3_i103;
  int32_T c3_i104;
  int32_T c3_i105;
  int32_T c3_i106;
  int32_T c3_i107;
  int32_T c3_i108;
  int32_T c3_i109;
  int32_T c3_i11;
  int32_T c3_i110;
  int32_T c3_i111;
  int32_T c3_i112;
  int32_T c3_i113;
  int32_T c3_i114;
  int32_T c3_i115;
  int32_T c3_i116;
  int32_T c3_i117;
  int32_T c3_i118;
  int32_T c3_i119;
  int32_T c3_i12;
  int32_T c3_i120;
  int32_T c3_i121;
  int32_T c3_i122;
  int32_T c3_i123;
  int32_T c3_i124;
  int32_T c3_i125;
  int32_T c3_i126;
  int32_T c3_i127;
  int32_T c3_i128;
  int32_T c3_i129;
  int32_T c3_i13;
  int32_T c3_i130;
  int32_T c3_i131;
  int32_T c3_i132;
  int32_T c3_i133;
  int32_T c3_i134;
  int32_T c3_i135;
  int32_T c3_i136;
  int32_T c3_i137;
  int32_T c3_i138;
  int32_T c3_i139;
  int32_T c3_i14;
  int32_T c3_i140;
  int32_T c3_i141;
  int32_T c3_i142;
  int32_T c3_i143;
  int32_T c3_i144;
  int32_T c3_i145;
  int32_T c3_i146;
  int32_T c3_i147;
  int32_T c3_i148;
  int32_T c3_i149;
  int32_T c3_i15;
  int32_T c3_i150;
  int32_T c3_i151;
  int32_T c3_i152;
  int32_T c3_i153;
  int32_T c3_i154;
  int32_T c3_i155;
  int32_T c3_i156;
  int32_T c3_i157;
  int32_T c3_i158;
  int32_T c3_i159;
  int32_T c3_i16;
  int32_T c3_i160;
  int32_T c3_i161;
  int32_T c3_i162;
  int32_T c3_i163;
  int32_T c3_i164;
  int32_T c3_i165;
  int32_T c3_i166;
  int32_T c3_i167;
  int32_T c3_i168;
  int32_T c3_i169;
  int32_T c3_i17;
  int32_T c3_i170;
  int32_T c3_i171;
  int32_T c3_i172;
  int32_T c3_i173;
  int32_T c3_i174;
  int32_T c3_i175;
  int32_T c3_i176;
  int32_T c3_i177;
  int32_T c3_i178;
  int32_T c3_i179;
  int32_T c3_i18;
  int32_T c3_i180;
  int32_T c3_i181;
  int32_T c3_i182;
  int32_T c3_i183;
  int32_T c3_i184;
  int32_T c3_i185;
  int32_T c3_i186;
  int32_T c3_i187;
  int32_T c3_i188;
  int32_T c3_i189;
  int32_T c3_i19;
  int32_T c3_i190;
  int32_T c3_i191;
  int32_T c3_i192;
  int32_T c3_i193;
  int32_T c3_i194;
  int32_T c3_i195;
  int32_T c3_i196;
  int32_T c3_i197;
  int32_T c3_i198;
  int32_T c3_i199;
  int32_T c3_i2;
  int32_T c3_i20;
  int32_T c3_i200;
  int32_T c3_i201;
  int32_T c3_i202;
  int32_T c3_i203;
  int32_T c3_i204;
  int32_T c3_i205;
  int32_T c3_i206;
  int32_T c3_i207;
  int32_T c3_i208;
  int32_T c3_i209;
  int32_T c3_i21;
  int32_T c3_i210;
  int32_T c3_i211;
  int32_T c3_i212;
  int32_T c3_i213;
  int32_T c3_i214;
  int32_T c3_i215;
  int32_T c3_i216;
  int32_T c3_i217;
  int32_T c3_i218;
  int32_T c3_i219;
  int32_T c3_i22;
  int32_T c3_i220;
  int32_T c3_i221;
  int32_T c3_i222;
  int32_T c3_i223;
  int32_T c3_i224;
  int32_T c3_i225;
  int32_T c3_i226;
  int32_T c3_i227;
  int32_T c3_i228;
  int32_T c3_i229;
  int32_T c3_i23;
  int32_T c3_i230;
  int32_T c3_i231;
  int32_T c3_i232;
  int32_T c3_i233;
  int32_T c3_i234;
  int32_T c3_i235;
  int32_T c3_i236;
  int32_T c3_i237;
  int32_T c3_i238;
  int32_T c3_i239;
  int32_T c3_i24;
  int32_T c3_i240;
  int32_T c3_i241;
  int32_T c3_i242;
  int32_T c3_i243;
  int32_T c3_i244;
  int32_T c3_i245;
  int32_T c3_i246;
  int32_T c3_i247;
  int32_T c3_i248;
  int32_T c3_i249;
  int32_T c3_i25;
  int32_T c3_i250;
  int32_T c3_i251;
  int32_T c3_i252;
  int32_T c3_i253;
  int32_T c3_i254;
  int32_T c3_i255;
  int32_T c3_i256;
  int32_T c3_i257;
  int32_T c3_i258;
  int32_T c3_i259;
  int32_T c3_i26;
  int32_T c3_i260;
  int32_T c3_i261;
  int32_T c3_i262;
  int32_T c3_i263;
  int32_T c3_i264;
  int32_T c3_i265;
  int32_T c3_i266;
  int32_T c3_i267;
  int32_T c3_i268;
  int32_T c3_i269;
  int32_T c3_i27;
  int32_T c3_i270;
  int32_T c3_i271;
  int32_T c3_i272;
  int32_T c3_i273;
  int32_T c3_i274;
  int32_T c3_i275;
  int32_T c3_i276;
  int32_T c3_i277;
  int32_T c3_i278;
  int32_T c3_i279;
  int32_T c3_i28;
  int32_T c3_i280;
  int32_T c3_i281;
  int32_T c3_i282;
  int32_T c3_i283;
  int32_T c3_i284;
  int32_T c3_i285;
  int32_T c3_i286;
  int32_T c3_i287;
  int32_T c3_i29;
  int32_T c3_i3;
  int32_T c3_i30;
  int32_T c3_i31;
  int32_T c3_i32;
  int32_T c3_i33;
  int32_T c3_i34;
  int32_T c3_i35;
  int32_T c3_i36;
  int32_T c3_i37;
  int32_T c3_i38;
  int32_T c3_i39;
  int32_T c3_i4;
  int32_T c3_i40;
  int32_T c3_i41;
  int32_T c3_i42;
  int32_T c3_i43;
  int32_T c3_i44;
  int32_T c3_i45;
  int32_T c3_i46;
  int32_T c3_i47;
  int32_T c3_i48;
  int32_T c3_i49;
  int32_T c3_i5;
  int32_T c3_i50;
  int32_T c3_i51;
  int32_T c3_i52;
  int32_T c3_i53;
  int32_T c3_i54;
  int32_T c3_i55;
  int32_T c3_i56;
  int32_T c3_i57;
  int32_T c3_i58;
  int32_T c3_i59;
  int32_T c3_i6;
  int32_T c3_i60;
  int32_T c3_i61;
  int32_T c3_i62;
  int32_T c3_i63;
  int32_T c3_i64;
  int32_T c3_i65;
  int32_T c3_i66;
  int32_T c3_i67;
  int32_T c3_i68;
  int32_T c3_i69;
  int32_T c3_i7;
  int32_T c3_i70;
  int32_T c3_i71;
  int32_T c3_i72;
  int32_T c3_i73;
  int32_T c3_i74;
  int32_T c3_i75;
  int32_T c3_i76;
  int32_T c3_i77;
  int32_T c3_i78;
  int32_T c3_i79;
  int32_T c3_i8;
  int32_T c3_i80;
  int32_T c3_i81;
  int32_T c3_i82;
  int32_T c3_i83;
  int32_T c3_i84;
  int32_T c3_i85;
  int32_T c3_i86;
  int32_T c3_i87;
  int32_T c3_i88;
  int32_T c3_i89;
  int32_T c3_i9;
  int32_T c3_i90;
  int32_T c3_i91;
  int32_T c3_i92;
  int32_T c3_i93;
  int32_T c3_i94;
  int32_T c3_i95;
  int32_T c3_i96;
  int32_T c3_i97;
  int32_T c3_i98;
  int32_T c3_i99;
  int32_T c3_i_i;
  int32_T c3_i_k;
  int32_T c3_i_loop_ub;
  int32_T c3_i_partialTrueCount;
  int32_T c3_i_trueCount;
  int32_T c3_ib_i;
  int32_T c3_ib_k;
  int32_T c3_ib_loop_ub;
  int32_T c3_ib_partialTrueCount;
  int32_T c3_ib_trueCount;
  int32_T c3_ic_i;
  int32_T c3_ic_k;
  int32_T c3_ic_loop_ub;
  int32_T c3_ic_trueCount;
  int32_T c3_id_i;
  int32_T c3_id_k;
  int32_T c3_ie_i;
  int32_T c3_ie_k;
  int32_T c3_if_i;
  int32_T c3_if_k;
  int32_T c3_ig_k;
  int32_T c3_ih_k;
  int32_T c3_j_i;
  int32_T c3_j_k;
  int32_T c3_j_loop_ub;
  int32_T c3_j_partialTrueCount;
  int32_T c3_j_trueCount;
  int32_T c3_jb_i;
  int32_T c3_jb_k;
  int32_T c3_jb_loop_ub;
  int32_T c3_jb_partialTrueCount;
  int32_T c3_jb_trueCount;
  int32_T c3_jc_i;
  int32_T c3_jc_k;
  int32_T c3_jc_trueCount;
  int32_T c3_jd_i;
  int32_T c3_jd_k;
  int32_T c3_je_i;
  int32_T c3_je_k;
  int32_T c3_jf_i;
  int32_T c3_jf_k;
  int32_T c3_jg_k;
  int32_T c3_jh_k;
  int32_T c3_k;
  int32_T c3_k_i;
  int32_T c3_k_k;
  int32_T c3_k_loop_ub;
  int32_T c3_k_partialTrueCount;
  int32_T c3_k_trueCount;
  int32_T c3_kb_i;
  int32_T c3_kb_k;
  int32_T c3_kb_loop_ub;
  int32_T c3_kb_partialTrueCount;
  int32_T c3_kb_trueCount;
  int32_T c3_kc_i;
  int32_T c3_kc_k;
  int32_T c3_kc_trueCount;
  int32_T c3_kd_i;
  int32_T c3_kd_k;
  int32_T c3_ke_i;
  int32_T c3_ke_k;
  int32_T c3_kf_i;
  int32_T c3_kf_k;
  int32_T c3_kg_k;
  int32_T c3_kh_k;
  int32_T c3_l_i;
  int32_T c3_l_k;
  int32_T c3_l_loop_ub;
  int32_T c3_l_partialTrueCount;
  int32_T c3_l_trueCount;
  int32_T c3_lb_i;
  int32_T c3_lb_k;
  int32_T c3_lb_loop_ub;
  int32_T c3_lb_partialTrueCount;
  int32_T c3_lb_trueCount;
  int32_T c3_lc_i;
  int32_T c3_lc_k;
  int32_T c3_ld_i;
  int32_T c3_ld_k;
  int32_T c3_le_i;
  int32_T c3_le_k;
  int32_T c3_lf_k;
  int32_T c3_lg_k;
  int32_T c3_loop_ub;
  int32_T c3_m_i;
  int32_T c3_m_k;
  int32_T c3_m_loop_ub;
  int32_T c3_m_partialTrueCount;
  int32_T c3_m_trueCount;
  int32_T c3_mb_i;
  int32_T c3_mb_k;
  int32_T c3_mb_loop_ub;
  int32_T c3_mb_partialTrueCount;
  int32_T c3_mb_trueCount;
  int32_T c3_mc_i;
  int32_T c3_mc_k;
  int32_T c3_md_i;
  int32_T c3_md_k;
  int32_T c3_me_i;
  int32_T c3_me_k;
  int32_T c3_mf_k;
  int32_T c3_mg_k;
  int32_T c3_n_i;
  int32_T c3_n_k;
  int32_T c3_n_loop_ub;
  int32_T c3_n_partialTrueCount;
  int32_T c3_n_trueCount;
  int32_T c3_nb_i;
  int32_T c3_nb_k;
  int32_T c3_nb_loop_ub;
  int32_T c3_nb_partialTrueCount;
  int32_T c3_nb_trueCount;
  int32_T c3_nc_i;
  int32_T c3_nc_k;
  int32_T c3_nd_i;
  int32_T c3_nd_k;
  int32_T c3_ne_i;
  int32_T c3_ne_k;
  int32_T c3_nf_k;
  int32_T c3_ng_k;
  int32_T c3_o_i;
  int32_T c3_o_k;
  int32_T c3_o_loop_ub;
  int32_T c3_o_partialTrueCount;
  int32_T c3_o_trueCount;
  int32_T c3_ob_i;
  int32_T c3_ob_k;
  int32_T c3_ob_loop_ub;
  int32_T c3_ob_trueCount;
  int32_T c3_oc_i;
  int32_T c3_oc_k;
  int32_T c3_od_i;
  int32_T c3_od_k;
  int32_T c3_oe_i;
  int32_T c3_oe_k;
  int32_T c3_of_k;
  int32_T c3_og_k;
  int32_T c3_p_i;
  int32_T c3_p_k;
  int32_T c3_p_loop_ub;
  int32_T c3_p_partialTrueCount;
  int32_T c3_p_trueCount;
  int32_T c3_partialTrueCount;
  int32_T c3_pb_i;
  int32_T c3_pb_k;
  int32_T c3_pb_loop_ub;
  int32_T c3_pb_trueCount;
  int32_T c3_pc_i;
  int32_T c3_pc_k;
  int32_T c3_pd_i;
  int32_T c3_pd_k;
  int32_T c3_pe_i;
  int32_T c3_pe_k;
  int32_T c3_pf_k;
  int32_T c3_pg_k;
  int32_T c3_q_i;
  int32_T c3_q_k;
  int32_T c3_q_loop_ub;
  int32_T c3_q_partialTrueCount;
  int32_T c3_q_trueCount;
  int32_T c3_qb_i;
  int32_T c3_qb_k;
  int32_T c3_qb_loop_ub;
  int32_T c3_qb_trueCount;
  int32_T c3_qc_i;
  int32_T c3_qc_k;
  int32_T c3_qd_i;
  int32_T c3_qd_k;
  int32_T c3_qe_i;
  int32_T c3_qe_k;
  int32_T c3_qf_k;
  int32_T c3_qg_k;
  int32_T c3_r_i;
  int32_T c3_r_k;
  int32_T c3_r_loop_ub;
  int32_T c3_r_partialTrueCount;
  int32_T c3_r_trueCount;
  int32_T c3_rb_i;
  int32_T c3_rb_k;
  int32_T c3_rb_loop_ub;
  int32_T c3_rb_trueCount;
  int32_T c3_rc_i;
  int32_T c3_rc_k;
  int32_T c3_rd_i;
  int32_T c3_rd_k;
  int32_T c3_re_i;
  int32_T c3_re_k;
  int32_T c3_rf_k;
  int32_T c3_rg_k;
  int32_T c3_s_i;
  int32_T c3_s_k;
  int32_T c3_s_loop_ub;
  int32_T c3_s_partialTrueCount;
  int32_T c3_s_trueCount;
  int32_T c3_sb_i;
  int32_T c3_sb_k;
  int32_T c3_sb_loop_ub;
  int32_T c3_sb_trueCount;
  int32_T c3_sc_i;
  int32_T c3_sc_k;
  int32_T c3_sd_i;
  int32_T c3_sd_k;
  int32_T c3_se_i;
  int32_T c3_se_k;
  int32_T c3_sf_k;
  int32_T c3_sg_k;
  int32_T c3_t_i;
  int32_T c3_t_k;
  int32_T c3_t_loop_ub;
  int32_T c3_t_partialTrueCount;
  int32_T c3_t_trueCount;
  int32_T c3_tb_i;
  int32_T c3_tb_k;
  int32_T c3_tb_loop_ub;
  int32_T c3_tb_trueCount;
  int32_T c3_tc_i;
  int32_T c3_tc_k;
  int32_T c3_td_i;
  int32_T c3_td_k;
  int32_T c3_te_i;
  int32_T c3_te_k;
  int32_T c3_tf_k;
  int32_T c3_tg_k;
  int32_T c3_trueCount;
  int32_T c3_u_i;
  int32_T c3_u_k;
  int32_T c3_u_loop_ub;
  int32_T c3_u_partialTrueCount;
  int32_T c3_u_trueCount;
  int32_T c3_ub_i;
  int32_T c3_ub_k;
  int32_T c3_ub_loop_ub;
  int32_T c3_ub_trueCount;
  int32_T c3_uc_i;
  int32_T c3_uc_k;
  int32_T c3_ud_i;
  int32_T c3_ud_k;
  int32_T c3_ue_i;
  int32_T c3_ue_k;
  int32_T c3_uf_k;
  int32_T c3_ug_k;
  int32_T c3_v_i;
  int32_T c3_v_k;
  int32_T c3_v_loop_ub;
  int32_T c3_v_partialTrueCount;
  int32_T c3_v_trueCount;
  int32_T c3_vb_i;
  int32_T c3_vb_k;
  int32_T c3_vb_loop_ub;
  int32_T c3_vb_trueCount;
  int32_T c3_vc_i;
  int32_T c3_vc_k;
  int32_T c3_vd_i;
  int32_T c3_vd_k;
  int32_T c3_ve_i;
  int32_T c3_ve_k;
  int32_T c3_vf_k;
  int32_T c3_vg_k;
  int32_T c3_w_i;
  int32_T c3_w_k;
  int32_T c3_w_loop_ub;
  int32_T c3_w_partialTrueCount;
  int32_T c3_w_trueCount;
  int32_T c3_wb_i;
  int32_T c3_wb_k;
  int32_T c3_wb_loop_ub;
  int32_T c3_wb_trueCount;
  int32_T c3_wc_i;
  int32_T c3_wc_k;
  int32_T c3_wd_i;
  int32_T c3_wd_k;
  int32_T c3_we_i;
  int32_T c3_we_k;
  int32_T c3_wf_k;
  int32_T c3_wg_k;
  int32_T c3_x_i;
  int32_T c3_x_k;
  int32_T c3_x_loop_ub;
  int32_T c3_x_partialTrueCount;
  int32_T c3_x_trueCount;
  int32_T c3_xb_i;
  int32_T c3_xb_k;
  int32_T c3_xb_loop_ub;
  int32_T c3_xb_trueCount;
  int32_T c3_xc_i;
  int32_T c3_xc_k;
  int32_T c3_xd_i;
  int32_T c3_xd_k;
  int32_T c3_xe_i;
  int32_T c3_xe_k;
  int32_T c3_xf_k;
  int32_T c3_xg_k;
  int32_T c3_y_i;
  int32_T c3_y_k;
  int32_T c3_y_loop_ub;
  int32_T c3_y_partialTrueCount;
  int32_T c3_y_trueCount;
  int32_T c3_yb_i;
  int32_T c3_yb_k;
  int32_T c3_yb_loop_ub;
  int32_T c3_yb_trueCount;
  int32_T c3_yc_i;
  int32_T c3_yc_k;
  int32_T c3_yd_i;
  int32_T c3_yd_k;
  int32_T c3_ye_i;
  int32_T c3_ye_k;
  int32_T c3_yf_k;
  int32_T c3_yg_k;
  boolean_T c3_b_isLowSpeed[4];
  boolean_T c3_isLowSpeed[4];
  boolean_T c3_bv[1];
  boolean_T c3_b_b;
  boolean_T c3_b_x;
  boolean_T c3_tempInds;
  boolean_T c3_x;
  boolean_T c3_y;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_b_st.prev = &c3_st;
  c3_b_st.tls = c3_st.tls;
  c3_c_st.prev = &c3_b_st;
  c3_c_st.tls = c3_b_st.tls;
  c3_i = 0;
  for (c3_i1 = 0; c3_i1 < 4; c3_i1++) {
    c3_lam_Fzo[c3_i1] = c3_scaleFactors[c3_i];
    c3_i += 27;
  }

  c3_i2 = 0;
  for (c3_i3 = 0; c3_i3 < 4; c3_i3++) {
    c3_lam_mux[c3_i3] = c3_scaleFactors[c3_i2 + 1];
    c3_i2 += 27;
  }

  c3_i4 = 0;
  for (c3_i5 = 0; c3_i5 < 4; c3_i5++) {
    c3_lam_muy[c3_i5] = c3_scaleFactors[c3_i4 + 2];
    c3_i4 += 27;
  }

  c3_i6 = 0;
  for (c3_i7 = 0; c3_i7 < 4; c3_i7++) {
    c3_lam_muV[c3_i7] = c3_scaleFactors[c3_i6 + 3];
    c3_i6 += 27;
  }

  c3_i8 = 0;
  for (c3_i9 = 0; c3_i9 < 4; c3_i9++) {
    c3_lam_Kxkappa[c3_i9] = c3_scaleFactors[c3_i8 + 4];
    c3_i8 += 27;
  }

  c3_i10 = 0;
  for (c3_i11 = 0; c3_i11 < 4; c3_i11++) {
    c3_lam_Kyalpha[c3_i11] = c3_scaleFactors[c3_i10 + 5];
    c3_i10 += 27;
  }

  c3_i12 = 0;
  for (c3_i13 = 0; c3_i13 < 4; c3_i13++) {
    c3_lam_Cx[c3_i13] = c3_scaleFactors[c3_i12 + 6];
    c3_i12 += 27;
  }

  c3_i14 = 0;
  for (c3_i15 = 0; c3_i15 < 4; c3_i15++) {
    c3_lam_Cy[c3_i15] = c3_scaleFactors[c3_i14 + 7];
    c3_i14 += 27;
  }

  c3_i16 = 0;
  for (c3_i17 = 0; c3_i17 < 4; c3_i17++) {
    c3_lam_Ex[c3_i17] = c3_scaleFactors[c3_i16 + 8];
    c3_i16 += 27;
  }

  c3_i18 = 0;
  for (c3_i19 = 0; c3_i19 < 4; c3_i19++) {
    c3_lam_Ey[c3_i19] = c3_scaleFactors[c3_i18 + 9];
    c3_i18 += 27;
  }

  c3_i20 = 0;
  for (c3_i21 = 0; c3_i21 < 4; c3_i21++) {
    c3_lam_Hx[c3_i21] = c3_scaleFactors[c3_i20 + 10];
    c3_i20 += 27;
  }

  c3_i22 = 0;
  for (c3_i23 = 0; c3_i23 < 4; c3_i23++) {
    c3_lam_Hy[c3_i23] = c3_scaleFactors[c3_i22 + 11];
    c3_i22 += 27;
  }

  c3_i24 = 0;
  for (c3_i25 = 0; c3_i25 < 4; c3_i25++) {
    c3_lam_Vx[c3_i25] = c3_scaleFactors[c3_i24 + 12];
    c3_i24 += 27;
  }

  c3_i26 = 0;
  for (c3_i27 = 0; c3_i27 < 4; c3_i27++) {
    c3_lam_Vy[c3_i27] = c3_scaleFactors[c3_i26 + 13];
    c3_i26 += 27;
  }

  c3_i28 = 0;
  for (c3_i29 = 0; c3_i29 < 4; c3_i29++) {
    c3_lam_Kygamma[c3_i29] = c3_scaleFactors[c3_i28 + 14];
    c3_i28 += 27;
  }

  c3_i30 = 0;
  for (c3_i31 = 0; c3_i31 < 4; c3_i31++) {
    c3_lam_Kzgamma[c3_i31] = c3_scaleFactors[c3_i30 + 15];
    c3_i30 += 27;
  }

  c3_i32 = 0;
  for (c3_i33 = 0; c3_i33 < 4; c3_i33++) {
    c3_lam_t[c3_i33] = c3_scaleFactors[c3_i32 + 16];
    c3_i32 += 27;
  }

  c3_i34 = 0;
  for (c3_i35 = 0; c3_i35 < 4; c3_i35++) {
    c3_lam_Mr[c3_i35] = c3_scaleFactors[c3_i34 + 17];
    c3_i34 += 27;
  }

  c3_i36 = 0;
  for (c3_i37 = 0; c3_i37 < 4; c3_i37++) {
    c3_lam_xalpha[c3_i37] = c3_scaleFactors[c3_i36 + 18];
    c3_i36 += 27;
  }

  c3_i38 = 0;
  for (c3_i39 = 0; c3_i39 < 4; c3_i39++) {
    c3_lam_ykappa[c3_i39] = c3_scaleFactors[c3_i38 + 19];
    c3_i38 += 27;
  }

  c3_i40 = 0;
  for (c3_i41 = 0; c3_i41 < 4; c3_i41++) {
    c3_lam_Vykappa[c3_i41] = c3_scaleFactors[c3_i40 + 20];
    c3_i40 += 27;
  }

  c3_i42 = 0;
  for (c3_i43 = 0; c3_i43 < 4; c3_i43++) {
    c3_lam_s[c3_i43] = c3_scaleFactors[c3_i42 + 21];
    c3_i42 += 27;
  }

  c3_i44 = 0;
  for (c3_i45 = 0; c3_i45 < 4; c3_i45++) {
    c3_lam_Cz[c3_i45] = c3_scaleFactors[c3_i44 + 22];
    c3_i44 += 27;
  }

  c3_i46 = 0;
  for (c3_i47 = 0; c3_i47 < 4; c3_i47++) {
    c3_b_Mx[c3_i47] = c3_scaleFactors[c3_i46 + 23];
    c3_i46 += 27;
  }

  c3_i48 = 0;
  for (c3_i49 = 0; c3_i49 < 4; c3_i49++) {
    c3_lam_VMx[c3_i49] = c3_scaleFactors[c3_i48 + 24];
    c3_i48 += 27;
  }

  c3_i50 = 0;
  for (c3_i51 = 0; c3_i51 < 4; c3_i51++) {
    c3_lam_My[c3_i51] = c3_scaleFactors[c3_i50 + 25];
    c3_i50 += 27;
  }

  c3_i52 = 0;
  for (c3_i53 = 0; c3_i53 < 4; c3_i53++) {
    c3_lam_Mphi[c3_i53] = c3_scaleFactors[c3_i52 + 26];
    c3_i52 += 27;
  }

  c3_st.site = &c3_b_emlrtRSI;
  c3_div0protect(chartInstance, &c3_st, c3_b_Vx, c3_b_VXLOW, c3_Fz_btm, c3_Vsy);
  for (c3_b_i = 0; c3_b_i < 4; c3_b_i++) {
    if (c3_gamma[c3_b_i] < c3_b_CAMMIN) {
      c3_gamma[c3_b_i] = c3_b_CAMMIN;
    }
  }

  for (c3_c_i = 0; c3_c_i < 4; c3_c_i++) {
    if (c3_gamma[c3_c_i] > c3_b_CAMMAX) {
      c3_gamma[c3_c_i] = c3_b_CAMMAX;
    }
  }

  for (c3_d_i = 0; c3_d_i < 4; c3_d_i++) {
    if (c3_press[c3_d_i] < c3_b_PRESMIN) {
      c3_press[c3_d_i] = c3_b_PRESMIN;
    }
  }

  for (c3_e_i = 0; c3_e_i < 4; c3_e_i++) {
    if (c3_press[c3_e_i] > c3_b_PRESMAX) {
      c3_press[c3_e_i] = c3_b_PRESMAX;
    }
  }

  for (c3_i54 = 0; c3_i54 < 4; c3_i54++) {
    c3_dpi[c3_i54] = (c3_press[c3_i54] - c3_b_NOMPRES) / c3_b_NOMPRES;
  }

  for (c3_f_i = 0; c3_f_i < 4; c3_f_i++) {
    if (c3_lam_mux[c3_f_i] <= 0.0) {
      c3_lam_mux[c3_f_i] = 2.2204460492503131E-16;
    }
  }

  for (c3_g_i = 0; c3_g_i < 4; c3_g_i++) {
    if (c3_lam_muy[c3_g_i] <= 0.0) {
      c3_lam_muy[c3_g_i] = 2.2204460492503131E-16;
    }
  }

  c3_x = (c3_b_Q_FZ1 == 0.0);
  c3_b_x = c3_x;
  if (!c3_b_x) {
    c3_b_b = true;
  } else {
    c3_b_b = false;
  }

  c3_y = !c3_b_b;
  if (c3_y) {
    c3_st.site = &c3_b_emlrtRSI;
    c3_b_a = c3_b_VERTICAL_STIFFNESS * c3_b_UNLOADED_RADIUS / c3_b_FNOMIN;
    c3_b_st.site = &c3_c_emlrtRSI;
    c3_c_a = c3_b_a;
    c3_d_a = c3_c_a;
    c3_e_a = c3_d_a;
    c3_b_y = c3_e_a * c3_e_a;
    c3_tempInds = (c3_b_y - 4.0 * c3_b_Q_FZ2 < 0.0);
    c3_dv[0] = c3_b_Q_FZ1;
    c3_bv[0] = c3_tempInds;
    c3_trueCount = 0;
    for (c3_h_i = 0; c3_h_i < 1; c3_h_i++) {
      if (c3_bv[0]) {
        c3_trueCount++;
      }
    }

    c3_tmp_size[0] = 1;
    c3_tmp_size[1] = c3_trueCount;
    c3_partialTrueCount = 0;
    for (c3_i_i = 0; c3_i_i < 1; c3_i_i++) {
      if (c3_bv[0]) {
        c3_tmp_data[c3_partialTrueCount] = c3_i_i + 1;
        c3_partialTrueCount++;
      }
    }

    c3_loop_ub = c3_tmp_size[0] * c3_tmp_size[1] - 1;
    for (c3_i61 = 0; c3_i61 <= c3_loop_ub; c3_i61++) {
      c3_dv[c3_tmp_data[c3_i61] - 1] = c3_b_Q_FZ2 * 0.0;
    }

    c3_b_Q_FZ1 = c3_dv[0];
    c3_bv[0] = !c3_tempInds;
    c3_b_trueCount = 0;
    for (c3_j_i = 0; c3_j_i < 1; c3_j_i++) {
      if (c3_bv[0]) {
        c3_b_trueCount++;
      }
    }

    c3_x_size[0] = 1;
    c3_x_size[1] = c3_b_trueCount;
    c3_b_loop_ub = c3_b_trueCount - 1;
    for (c3_i64 = 0; c3_i64 <= c3_b_loop_ub; c3_i64++) {
      c3_x_data[c3_i64] = c3_b_VERTICAL_STIFFNESS;
    }

    c3_bv[0] = !c3_tempInds;
    c3_d_trueCount = 0;
    for (c3_l_i = 0; c3_l_i < 1; c3_l_i++) {
      if (c3_bv[0]) {
        c3_d_trueCount++;
      }
    }

    c3_c_tmp_size[0] = 1;
    c3_c_tmp_size[1] = c3_d_trueCount;
    c3_c_loop_ub = c3_d_trueCount - 1;
    for (c3_i66 = 0; c3_i66 <= c3_c_loop_ub; c3_i66++) {
      c3_c_tmp_data[c3_i66] = c3_b_UNLOADED_RADIUS;
    }

    if ((c3_x_size[1] != c3_c_tmp_size[1]) && ((c3_x_size[1] != 1) &&
         (c3_c_tmp_size[1] != 1))) {
      emlrtDimSizeImpxCheckR2021b(c3_x_size[1], c3_c_tmp_size[1], &c3_emlrtECI,
        (emlrtConstCTX)c3_sp);
    }

    c3_bv[0] = !c3_tempInds;
    c3_e_trueCount = 0;
    for (c3_n_i = 0; c3_n_i < 1; c3_n_i++) {
      if (c3_bv[0]) {
        c3_e_trueCount++;
      }
    }

    c3_st.site = &c3_b_emlrtRSI;
    if (c3_x_size[1] == c3_c_tmp_size[1]) {
      c3_i69 = c3_x_size[0] * c3_x_size[1];
      c3_x_size[0] = 1;
      c3_f_loop_ub = c3_i69 - 1;
      for (c3_i70 = 0; c3_i70 <= c3_f_loop_ub; c3_i70++) {
        c3_x_data[c3_i70] *= c3_c_tmp_data[c3_i70];
      }
    } else {
      c3_times(chartInstance, c3_x_data, c3_x_size, c3_c_tmp_data, c3_c_tmp_size);
    }

    c3_b_y_size[0] = 1;
    c3_b_y_size[1] = c3_e_trueCount;
    c3_g_loop_ub = c3_e_trueCount - 1;
    for (c3_i71 = 0; c3_i71 <= c3_g_loop_ub; c3_i71++) {
      c3_b_y_data[c3_i71] = c3_b_FNOMIN;
    }

    c3_b_st.site = &c3_d_emlrtRSI;
    c3_c_st.site = &c3_e_emlrtRSI;
    if (c3_x_size[1] == c3_b_y_size[1]) {
      c3_i73 = c3_x_size[0] * c3_x_size[1];
      c3_x_size[0] = 1;
      c3_i_loop_ub = c3_i73 - 1;
      for (c3_i74 = 0; c3_i74 <= c3_i_loop_ub; c3_i74++) {
        c3_x_data[c3_i74] /= c3_b_y_data[c3_i74];
      }
    } else {
      c3_b_rdivide(chartInstance, c3_x_data, c3_x_size, c3_b_y_data, c3_b_y_size);
    }

    c3_st.site = &c3_b_emlrtRSI;
    c3_b_power(chartInstance, &c3_st, c3_x_data, c3_x_size, c3_c_tmp_data,
               c3_c_tmp_size);
    c3_bv[0] = !c3_tempInds;
    c3_g_trueCount = 0;
    for (c3_q_i = 0; c3_q_i < 1; c3_q_i++) {
      if (c3_bv[0]) {
        c3_g_trueCount++;
      }
    }

    c3_b_y_size[0] = 1;
    c3_b_y_size[1] = c3_g_trueCount;
    c3_k_loop_ub = c3_g_trueCount - 1;
    for (c3_i76 = 0; c3_i76 <= c3_k_loop_ub; c3_i76++) {
      c3_b_y_data[c3_i76] = 4.0 * c3_b_Q_FZ2;
    }

    if ((c3_c_tmp_size[1] != c3_b_y_size[1]) && ((c3_c_tmp_size[1] != 1) &&
         (c3_b_y_size[1] != 1))) {
      emlrtDimSizeImpxCheckR2021b(c3_c_tmp_size[1], c3_b_y_size[1], &c3_emlrtECI,
        (emlrtConstCTX)c3_sp);
    }

    if (c3_c_tmp_size[1] == c3_b_y_size[1]) {
      c3_i77 = c3_c_tmp_size[0] * c3_c_tmp_size[1];
      c3_c_tmp_size[0] = 1;
      c3_l_loop_ub = c3_i77 - 1;
      for (c3_i78 = 0; c3_i78 <= c3_l_loop_ub; c3_i78++) {
        c3_c_tmp_data[c3_i78] -= c3_b_y_data[c3_i78];
      }
    } else {
      c3_b_minus(chartInstance, c3_c_tmp_data, c3_c_tmp_size, c3_b_y_data,
                 c3_b_y_size);
    }

    c3_st.site = &c3_b_emlrtRSI;
    c3_d_sqrt(chartInstance, &c3_st, c3_c_tmp_data, c3_c_tmp_size);
    c3_bv[0] = !c3_tempInds;
    c3_j_trueCount = 0;
    for (c3_u_i = 0; c3_u_i < 1; c3_u_i++) {
      if (c3_bv[0]) {
        c3_j_trueCount++;
      }
    }

    if (c3_j_trueCount != c3_c_tmp_size[1]) {
      emlrtSubAssignSizeCheck1dR2017a(c3_j_trueCount, c3_c_tmp_size[1],
        &c3_b_emlrtECI, (emlrtConstCTX)c3_sp);
    }

    c3_dv1[0] = c3_b_Q_FZ1;
    c3_bv[0] = !c3_tempInds;
    c3_e_partialTrueCount = 0;
    for (c3_w_i = 0; c3_w_i < 1; c3_w_i++) {
      if (c3_bv[0]) {
        c3_dv1[c3_w_i] = c3_c_tmp_data[c3_e_partialTrueCount];
        c3_e_partialTrueCount++;
      }
    }

    c3_b_Q_FZ1 = c3_dv1[0];
  }

  for (c3_i55 = 0; c3_i55 < 4; c3_i55++) {
    c3_Fzo_prime[c3_i55] = c3_lam_Fzo[c3_i55] * c3_b_FNOMIN;
  }

  for (c3_k = 0; c3_k < 4; c3_k++) {
    c3_b_k = c3_k;
    c3_c_x = c3_b_Omega[c3_b_k];
    c3_c_y = muDoubleScalarAbs(c3_c_x);
    c3_Fz[c3_b_k] = c3_c_y;
  }

  for (c3_i56 = 0; c3_i56 < 4; c3_i56++) {
    c3_Vc_prime[c3_i56] = c3_b_Q_FCX * c3_b_Fx_ext[c3_i56] / c3_b_FNOMIN;
  }

  for (c3_c_k = 0; c3_c_k < 4; c3_c_k++) {
    c3_d_k = c3_c_k;
    c3_f_a = c3_Vc_prime[c3_d_k];
    c3_d_y = c3_f_a * c3_f_a;
    c3_e_y[c3_d_k] = c3_d_y;
  }

  for (c3_i57 = 0; c3_i57 < 4; c3_i57++) {
    c3_Vc_prime[c3_i57] = c3_b_Q_FCY * c3_b_Fy_ext[c3_i57] / c3_b_FNOMIN;
  }

  for (c3_e_k = 0; c3_e_k < 4; c3_e_k++) {
    c3_f_k = c3_e_k;
    c3_g_a = c3_Vc_prime[c3_f_k];
    c3_f_y = c3_g_a * c3_g_a;
    c3_SVygamma[c3_f_k] = c3_f_y;
  }

  for (c3_i58 = 0; c3_i58 < 4; c3_i58++) {
    c3_Vc_prime[c3_i58] = c3_b_rhoz[c3_i58] / c3_b_UNLOADED_RADIUS;
  }

  for (c3_g_k = 0; c3_g_k < 4; c3_g_k++) {
    c3_h_k = c3_g_k;
    c3_h_a = c3_Vc_prime[c3_h_k];
    c3_g_y = c3_h_a * c3_h_a;
    c3_SHyphi[c3_h_k] = c3_g_y;
  }

  for (c3_i59 = 0; c3_i59 < 4; c3_i59++) {
    c3_Fz[c3_i59] = (((1.0 + c3_b_Q_V2 * c3_Fz[c3_i59] * c3_b_UNLOADED_RADIUS /
                       c3_b_LONGVL) - c3_e_y[c3_i59]) - c3_SVygamma[c3_i59]) *
      ((c3_b_Q_FZ1 + c3_b_Q_FZ3 * c3_gamma[c3_i59] * c3_gamma[c3_i59]) *
       c3_b_rhoz[c3_i59] / c3_b_UNLOADED_RADIUS + c3_b_Q_FZ2 * c3_SHyphi[c3_i59])
      * (c3_b_PFZ1 * c3_dpi[c3_i59] + 1.0) * c3_Fzo_prime[c3_i59];
  }

  for (c3_i60 = 0; c3_i60 < 4; c3_i60++) {
    c3_Fz_btm[c3_i60] = c3_gamma[c3_i60];
  }

  for (c3_i_k = 0; c3_i_k < 4; c3_i_k++) {
    c3_j_k = c3_i_k;
    c3_d_x = c3_Fz_btm[c3_j_k];
    c3_e_x = c3_d_x;
    c3_e_x = muDoubleScalarCos(c3_e_x);
    c3_Fz_btm[c3_j_k] = c3_e_x;
  }

  c3_c_RIM_RADIUS = c3_b_RIM_RADIUS + c3_b_BOTTOM_OFFST;
  for (c3_i62 = 0; c3_i62 < 4; c3_i62++) {
    c3_Fz_btm[c3_i62] = c3_b_BOTTOM_STIFF * (c3_c_RIM_RADIUS -
      (c3_b_UNLOADED_RADIUS + c3_b_rhoz[c3_i62]) / c3_Fz_btm[c3_i62]);
  }

  for (c3_i63 = 0; c3_i63 < 4; c3_i63++) {
    c3_f_x[c3_i63] = c3_Fz[c3_i63];
  }

  for (c3_k_k = 0; c3_k_k < 4; c3_k_k++) {
    c3_l_k = c3_k_k;
    c3_g_x = c3_f_x[c3_l_k];
    c3_h_y = c3_Fz_btm[c3_l_k];
    c3_h_x = c3_g_x;
    c3_i_y = c3_h_y;
    c3_ex = muDoubleScalarMax(c3_h_x, c3_i_y);
    c3_Fz[c3_l_k] = c3_ex;
  }

  for (c3_i65 = 0; c3_i65 < 4; c3_i65++) {
    c3_patch_b[c3_i65] = c3_b_VERTICAL_STIFFNESS * c3_lam_Cz[c3_i65];
  }

  c3_c_trueCount = 0;
  for (c3_k_i = 0; c3_k_i < 4; c3_k_i++) {
    if (c3_b_rhoz[c3_k_i] > 0.0) {
      c3_c_trueCount++;
    }
  }

  c3_b_tmp_size[0] = c3_c_trueCount;
  c3_b_partialTrueCount = 0;
  for (c3_m_i = 0; c3_m_i < 4; c3_m_i++) {
    if (c3_b_rhoz[c3_m_i] > 0.0) {
      c3_b_tmp_data[c3_b_partialTrueCount] = c3_m_i + 1;
      c3_b_partialTrueCount++;
    }
  }

  c3_st.site = &c3_b_emlrtRSI;
  c3_tmpDrphiVar_size[0] = c3_b_tmp_size[0];
  c3_d_loop_ub = c3_b_tmp_size[0] - 1;
  for (c3_i67 = 0; c3_i67 <= c3_d_loop_ub; c3_i67++) {
    c3_tmpDrphiVar_data[c3_i67] = c3_Fz[c3_b_tmp_data[c3_i67] - 1];
  }

  c3_rhoz_size[0] = c3_b_tmp_size[0];
  c3_e_loop_ub = c3_b_tmp_size[0] - 1;
  for (c3_i68 = 0; c3_i68 <= c3_e_loop_ub; c3_i68++) {
    c3_rhoz_data[c3_i68] = c3_b_rhoz[c3_b_tmp_data[c3_i68] - 1];
  }

  c3_abs(chartInstance, c3_rhoz_data, c3_rhoz_size, c3_y_data, c3_y_size);
  c3_b_st.site = &c3_d_emlrtRSI;
  c3_c_st.site = &c3_e_emlrtRSI;
  c3_b_assertCompatibleDims(chartInstance, &c3_c_st, c3_tmpDrphiVar_size,
    c3_y_size);
  if (c3_tmpDrphiVar_size[0] == c3_y_size[0]) {
    c3_h_loop_ub = c3_tmpDrphiVar_size[0] - 1;
    for (c3_i72 = 0; c3_i72 <= c3_h_loop_ub; c3_i72++) {
      c3_tmpDrphiVar_data[c3_i72] /= c3_y_data[c3_i72];
    }
  } else {
    c3_rdivide(chartInstance, c3_tmpDrphiVar_data, c3_tmpDrphiVar_size,
               c3_y_data, c3_y_size);
  }

  c3_f_trueCount = 0;
  for (c3_o_i = 0; c3_o_i < 4; c3_o_i++) {
    if (c3_b_rhoz[c3_o_i] > 0.0) {
      c3_f_trueCount++;
    }
  }

  c3_d_tmp_size[0] = c3_f_trueCount;
  c3_c_partialTrueCount = 0;
  for (c3_p_i = 0; c3_p_i < 4; c3_p_i++) {
    if (c3_b_rhoz[c3_p_i] > 0.0) {
      c3_d_tmp_data[c3_c_partialTrueCount] = c3_b_Q_FCY2 * c3_b_Fy_ext[c3_p_i] /
        c3_b_FNOMIN;
      c3_c_partialTrueCount++;
    }
  }

  if ((c3_tmpDrphiVar_size[0] != c3_d_tmp_size[0]) && ((c3_tmpDrphiVar_size[0]
        != 1) && (c3_d_tmp_size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(c3_tmpDrphiVar_size[0], c3_d_tmp_size[0],
      &c3_c_emlrtECI, (emlrtConstCTX)c3_sp);
  }

  if (c3_tmpDrphiVar_size[0] == c3_d_tmp_size[0]) {
    c3_j_loop_ub = c3_tmpDrphiVar_size[0] - 1;
    for (c3_i75 = 0; c3_i75 <= c3_j_loop_ub; c3_i75++) {
      c3_tmpDrphiVar_data[c3_i75] += c3_d_tmp_data[c3_i75];
    }
  } else {
    c3_plus(chartInstance, c3_tmpDrphiVar_data, c3_tmpDrphiVar_size,
            c3_d_tmp_data, c3_d_tmp_size);
  }

  c3_h_trueCount = 0;
  for (c3_r_i = 0; c3_r_i < 4; c3_r_i++) {
    if (c3_b_rhoz[c3_r_i] > 0.0) {
      c3_h_trueCount++;
    }
  }

  if ((c3_tmpDrphiVar_size[0] != c3_h_trueCount) && ((c3_tmpDrphiVar_size[0] !=
        1) && (c3_h_trueCount != 1))) {
    emlrtDimSizeImpxCheckR2021b(c3_tmpDrphiVar_size[0], c3_h_trueCount,
      &c3_c_emlrtECI, (emlrtConstCTX)c3_sp);
  }

  c3_i_trueCount = 0;
  for (c3_s_i = 0; c3_s_i < 4; c3_s_i++) {
    if (c3_b_rhoz[c3_s_i] > 0.0) {
      c3_i_trueCount++;
    }
  }

  c3_e_tmp_size[0] = c3_i_trueCount;
  c3_d_partialTrueCount = 0;
  for (c3_t_i = 0; c3_t_i < 4; c3_t_i++) {
    if (c3_b_rhoz[c3_t_i] > 0.0) {
      c3_e_tmp_data[c3_d_partialTrueCount] = c3_t_i + 1;
      c3_d_partialTrueCount++;
    }
  }

  if (c3_tmpDrphiVar_size[0] == c3_e_tmp_size[0]) {
    c3_d_tmp_size[0] = c3_tmpDrphiVar_size[0];
    c3_m_loop_ub = c3_tmpDrphiVar_size[0] - 1;
    for (c3_i79 = 0; c3_i79 <= c3_m_loop_ub; c3_i79++) {
      c3_d_tmp_data[c3_i79] = c3_tmpDrphiVar_data[c3_i79] *
        c3_lam_Cz[c3_e_tmp_data[c3_i79] - 1];
    }
  } else {
    c3_h_binary_expand_op(chartInstance, c3_d_tmp_data, c3_d_tmp_size,
                          c3_tmpDrphiVar_data, c3_tmpDrphiVar_size, c3_lam_Cz,
                          c3_e_tmp_data, c3_e_tmp_size);
  }

  c3_k_trueCount = 0;
  for (c3_v_i = 0; c3_v_i < 4; c3_v_i++) {
    if (c3_b_rhoz[c3_v_i] > 0.0) {
      c3_k_trueCount++;
    }
  }

  if (c3_k_trueCount != c3_d_tmp_size[0]) {
    emlrtSubAssignSizeCheck1dR2017a(c3_k_trueCount, c3_d_tmp_size[0],
      &c3_b_emlrtECI, (emlrtConstCTX)c3_sp);
  }

  c3_f_partialTrueCount = 0;
  for (c3_x_i = 0; c3_x_i < 4; c3_x_i++) {
    if (c3_b_rhoz[c3_x_i] > 0.0) {
      c3_patch_b[c3_x_i] = c3_d_tmp_data[c3_f_partialTrueCount];
      c3_f_partialTrueCount++;
    }
  }

  for (c3_i80 = 0; c3_i80 < 4; c3_i80++) {
    c3_FzUnSat[c3_i80] = c3_Fz[c3_i80];
  }

  for (c3_y_i = 0; c3_y_i < 4; c3_y_i++) {
    if (c3_Fz[c3_y_i] < c3_b_FZMIN) {
      c3_Fz[c3_y_i] = c3_b_FZMIN;
    }
  }

  for (c3_ab_i = 0; c3_ab_i < 4; c3_ab_i++) {
    if (c3_Fz[c3_ab_i] > c3_b_FZMAX) {
      c3_Fz[c3_ab_i] = c3_b_FZMAX;
    }
  }

  for (c3_i81 = 0; c3_i81 < 4; c3_i81++) {
    c3_dfz[c3_i81] = (c3_Fz[c3_i81] - c3_Fzo_prime[c3_i81]) /
      c3_Fzo_prime[c3_i81];
  }

  for (c3_i82 = 0; c3_i82 < 4; c3_i82++) {
    c3_epsilon_gamma[c3_i82] = c3_b_PECP1 * (c3_b_PECP2 * c3_dfz[c3_i82] + 1.0);
  }

  for (c3_i83 = 0; c3_i83 < 4; c3_i83++) {
    c3_Vc_prime[c3_i83] = c3_b_Omega[c3_i83] * c3_b_UNLOADED_RADIUS /
      c3_b_LONGVL;
  }

  for (c3_m_k = 0; c3_m_k < 4; c3_m_k++) {
    c3_n_k = c3_m_k;
    c3_i_a = c3_Vc_prime[c3_n_k];
    c3_j_y = c3_i_a * c3_i_a;
    c3_b_Re[c3_n_k] = c3_j_y;
  }

  for (c3_i84 = 0; c3_i84 < 4; c3_i84++) {
    c3_b_Re[c3_i84] = c3_b_UNLOADED_RADIUS * (c3_b_Q_RE0 + c3_b_Q_V1 *
      c3_b_Re[c3_i84]);
  }

  c3_i_x = c3_b_FNOMIN;
  c3_j_x = c3_i_x;
  for (c3_i85 = 0; c3_i85 < 4; c3_i85++) {
    c3_Fz_btm[c3_i85] = c3_j_x / c3_patch_b[c3_i85];
  }

  for (c3_i86 = 0; c3_i86 < 4; c3_i86++) {
    c3_f_x[c3_i86] = c3_b_BREFF * (c3_FzUnSat[c3_i86] / c3_b_FNOMIN);
  }

  for (c3_o_k = 0; c3_o_k < 4; c3_o_k++) {
    c3_p_k = c3_o_k;
    c3_k_x = c3_f_x[c3_p_k];
    c3_l_x = c3_k_x;
    c3_l_x = muDoubleScalarAtan(c3_l_x);
    c3_f_x[c3_p_k] = c3_l_x;
  }

  for (c3_i87 = 0; c3_i87 < 4; c3_i87++) {
    c3_b_Re[c3_i87] -= c3_Fz_btm[c3_i87] * (c3_b_DREFF * c3_f_x[c3_i87] +
      c3_b_FREFF * (c3_FzUnSat[c3_i87] / c3_b_FNOMIN));
  }

  for (c3_bb_i = 0; c3_bb_i < 4; c3_bb_i++) {
    if (c3_b_Re[c3_bb_i] < 0.001) {
      c3_b_Re[c3_bb_i] = 0.001;
    }
  }

  for (c3_i88 = 0; c3_i88 < 4; c3_i88++) {
    c3_patch_a[c3_i88] = c3_FzUnSat[c3_i88] / (c3_patch_b[c3_i88] *
      c3_b_UNLOADED_RADIUS);
  }

  c3_st.site = &c3_b_emlrtRSI;
  c3_e_sqrt(chartInstance, &c3_st, c3_patch_a);
  for (c3_i89 = 0; c3_i89 < 4; c3_i89++) {
    c3_patch_a[c3_i89] = c3_b_UNLOADED_RADIUS * (c3_b_Q_RA2 * (c3_FzUnSat[c3_i89]
      / (c3_patch_b[c3_i89] * c3_b_UNLOADED_RADIUS)) + c3_b_Q_RA1 *
      c3_patch_a[c3_i89]);
  }

  for (c3_i90 = 0; c3_i90 < 4; c3_i90++) {
    c3_b_FzUnSat[c3_i90] = c3_FzUnSat[c3_i90] / (c3_patch_b[c3_i90] *
      c3_b_UNLOADED_RADIUS);
  }

  c3_st.site = &c3_b_emlrtRSI;
  c3_c_power(chartInstance, &c3_st, c3_b_FzUnSat, c3_Fz_btm);
  for (c3_i91 = 0; c3_i91 < 4; c3_i91++) {
    c3_patch_b[c3_i91] = c3_b_WIDTH * (c3_b_Q_RB2 * (c3_FzUnSat[c3_i91] /
      (c3_patch_b[c3_i91] * c3_b_UNLOADED_RADIUS)) + c3_b_Q_RB1 *
      c3_Fz_btm[c3_i91]);
  }

  for (c3_i92 = 0; c3_i92 < 4; c3_i92++) {
    c3_kappa[c3_i92] = (c3_b_Re[c3_i92] * c3_b_Omega[c3_i92] - c3_b_Vx[c3_i92]) /
      c3_Vsy[c3_i92];
  }

  for (c3_cb_i = 0; c3_cb_i < 4; c3_cb_i++) {
    if (c3_kappa[c3_cb_i] < c3_b_KPUMIN) {
      c3_kappa[c3_cb_i] = c3_b_KPUMIN;
    }
  }

  for (c3_db_i = 0; c3_db_i < 4; c3_db_i++) {
    if (c3_kappa[c3_db_i] > c3_b_KPUMAX) {
      c3_kappa[c3_db_i] = c3_b_KPUMAX;
    }
  }

  for (c3_i93 = 0; c3_i93 < 4; c3_i93++) {
    c3_lam_Hx[c3_i93] = c3_kappa[c3_i93] + (c3_b_PHX1 + c3_b_PHX2 *
      c3_dfz[c3_i93]) * c3_lam_Hx[c3_i93];
  }

  for (c3_q_k = 0; c3_q_k < 4; c3_q_k++) {
    c3_r_k = c3_q_k;
    c3_k_y = c3_b_Vy[c3_r_k];
    c3_m_x = c3_Vsy[c3_r_k];
    c3_r = muDoubleScalarAtan2(c3_k_y, c3_m_x);
    c3_alpha[c3_r_k] = c3_r;
  }

  for (c3_eb_i = 0; c3_eb_i < 4; c3_eb_i++) {
    if (c3_alpha[c3_eb_i] < c3_b_ALPMIN) {
      c3_alpha[c3_eb_i] = c3_b_ALPMIN;
    }
  }

  for (c3_fb_i = 0; c3_fb_i < 4; c3_fb_i++) {
    if (c3_alpha[c3_fb_i] > c3_b_ALPMAX) {
      c3_alpha[c3_fb_i] = c3_b_ALPMAX;
    }
  }

  for (c3_i94 = 0; c3_i94 < 4; c3_i94++) {
    c3_gamma_star[c3_i94] = c3_gamma[c3_i94];
  }

  for (c3_s_k = 0; c3_s_k < 4; c3_s_k++) {
    c3_t_k = c3_s_k;
    c3_n_x = c3_gamma_star[c3_t_k];
    c3_o_x = c3_n_x;
    c3_o_x = muDoubleScalarSin(c3_o_x);
    c3_gamma_star[c3_t_k] = c3_o_x;
  }

  for (c3_i95 = 0; c3_i95 < 4; c3_i95++) {
    c3_Fz_btm[c3_i95] = -c3_Vsy[c3_i95] * c3_kappa[c3_i95];
  }

  for (c3_i96 = 0; c3_i96 < 4; c3_i96++) {
    c3_f_x[c3_i96] = c3_alpha[c3_i96];
  }

  for (c3_u_k = 0; c3_u_k < 4; c3_u_k++) {
    c3_v_k = c3_u_k;
    c3_p_x = c3_f_x[c3_v_k];
    c3_q_x = c3_p_x;
    c3_q_x = muDoubleScalarTan(c3_q_x);
    c3_f_x[c3_v_k] = c3_q_x;
  }

  for (c3_i97 = 0; c3_i97 < 4; c3_i97++) {
    c3_Vsy[c3_i97] = -c3_Vsy[c3_i97] * c3_f_x[c3_i97];
  }

  for (c3_w_k = 0; c3_w_k < 4; c3_w_k++) {
    c3_y_k = c3_w_k;
    c3_j_a = c3_Fz_btm[c3_y_k];
    c3_l_y = c3_j_a * c3_j_a;
    c3_Vs[c3_y_k] = c3_l_y;
  }

  for (c3_x_k = 0; c3_x_k < 4; c3_x_k++) {
    c3_ab_k = c3_x_k;
    c3_k_a = c3_Vsy[c3_ab_k];
    c3_m_y = c3_k_a * c3_k_a;
    c3_e_y[c3_ab_k] = c3_m_y;
  }

  for (c3_i98 = 0; c3_i98 < 4; c3_i98++) {
    c3_Vs[c3_i98] += c3_e_y[c3_i98];
  }

  c3_st.site = &c3_b_emlrtRSI;
  c3_e_sqrt(chartInstance, &c3_st, c3_Vs);
  c3_st.site = &c3_b_emlrtRSI;
  c3_div0protect(chartInstance, &c3_st, c3_b_Vx, c3_b_VXLOW, c3_phi_t, c3_Fz_btm);
  for (c3_bb_k = 0; c3_bb_k < 4; c3_bb_k++) {
    c3_db_k = c3_bb_k;
    c3_l_a = c3_b_Vx[c3_db_k];
    c3_n_y = c3_l_a * c3_l_a;
    c3_lam_Cz[c3_db_k] = c3_n_y;
  }

  for (c3_cb_k = 0; c3_cb_k < 4; c3_cb_k++) {
    c3_eb_k = c3_cb_k;
    c3_m_a = c3_Vsy[c3_eb_k];
    c3_o_y = c3_m_a * c3_m_a;
    c3_e_y[c3_eb_k] = c3_o_y;
  }

  for (c3_i99 = 0; c3_i99 < 4; c3_i99++) {
    c3_lam_Cz[c3_i99] += c3_e_y[c3_i99];
  }

  c3_st.site = &c3_b_emlrtRSI;
  c3_e_sqrt(chartInstance, &c3_st, c3_lam_Cz);
  c3_st.site = &c3_b_emlrtRSI;
  c3_div0protect(chartInstance, &c3_st, c3_lam_Cz, c3_b_VXLOW, c3_cosprimealpha,
                 c3_Fz_btm);
  c3_st.site = &c3_b_emlrtRSI;
  c3_b_div0protect(chartInstance, &c3_st, c3_lam_Cz, c3_Vc_prime);
  for (c3_i100 = 0; c3_i100 < 4; c3_i100++) {
    c3_Fz_btm[c3_i100] = c3_b_Re[c3_i100] * c3_b_Omega[c3_i100] -
      c3_b_Vx[c3_i100];
  }

  for (c3_fb_k = 0; c3_fb_k < 4; c3_fb_k++) {
    c3_hb_k = c3_fb_k;
    c3_n_a = c3_Fz_btm[c3_hb_k];
    c3_p_y = c3_n_a * c3_n_a;
    c3_e_y[c3_hb_k] = c3_p_y;
  }

  for (c3_gb_k = 0; c3_gb_k < 4; c3_gb_k++) {
    c3_ib_k = c3_gb_k;
    c3_o_a = c3_Vsy[c3_ib_k];
    c3_q_y = c3_o_a * c3_o_a;
    c3_SVygamma[c3_ib_k] = c3_q_y;
  }

  for (c3_i101 = 0; c3_i101 < 4; c3_i101++) {
    c3_e_y[c3_i101] += c3_SVygamma[c3_i101];
  }

  c3_st.site = &c3_b_emlrtRSI;
  c3_e_sqrt(chartInstance, &c3_st, c3_e_y);
  for (c3_i102 = 0; c3_i102 < 4; c3_i102++) {
    c3_isLowSpeed[c3_i102] = (c3_e_y[c3_i102] < c3_b_VXLOW);
  }

  for (c3_i103 = 0; c3_i103 < 4; c3_i103++) {
    c3_lam_mux[c3_i103] /= c3_lam_muV[c3_i103] * c3_Vs[c3_i103] / c3_b_LONGVL +
      1.0;
  }

  for (c3_i104 = 0; c3_i104 < 4; c3_i104++) {
    c3_lam_mux_prime[c3_i104] = c3_lam_mux[c3_i104] * 10.0 / (9.0 *
      c3_lam_mux[c3_i104] + 1.0);
  }

  for (c3_jb_k = 0; c3_jb_k < 4; c3_jb_k++) {
    c3_lb_k = c3_jb_k;
    c3_p_a = c3_dpi[c3_lb_k];
    c3_r_y = c3_p_a * c3_p_a;
    c3_mu_x[c3_lb_k] = c3_r_y;
  }

  for (c3_kb_k = 0; c3_kb_k < 4; c3_kb_k++) {
    c3_mb_k = c3_kb_k;
    c3_q_a = c3_gamma[c3_mb_k];
    c3_s_y = c3_q_a * c3_q_a;
    c3_e_y[c3_mb_k] = c3_s_y;
  }

  for (c3_i105 = 0; c3_i105 < 4; c3_i105++) {
    c3_mu_x[c3_i105] = (c3_b_PDX1 + c3_b_PDX2 * c3_dfz[c3_i105]) * ((c3_b_PPX3 *
      c3_dpi[c3_i105] + 1.0) + c3_b_PPX4 * c3_mu_x[c3_i105]) * (1.0 - c3_b_PDX3 *
      c3_e_y[c3_i105]) * c3_lam_mux[c3_i105];
  }

  for (c3_i106 = 0; c3_i106 < 4; c3_i106++) {
    c3_lam_muy[c3_i106] /= c3_lam_muV[c3_i106] * c3_Vs[c3_i106] / c3_b_LONGVL +
      1.0;
  }

  for (c3_i107 = 0; c3_i107 < 4; c3_i107++) {
    c3_lam_muy_prime[c3_i107] = c3_lam_muy[c3_i107] * 10.0 / (9.0 *
      c3_lam_muy[c3_i107] + 1.0);
  }

  for (c3_nb_k = 0; c3_nb_k < 4; c3_nb_k++) {
    c3_pb_k = c3_nb_k;
    c3_r_a = c3_dpi[c3_pb_k];
    c3_t_y = c3_r_a * c3_r_a;
    c3_mu_y[c3_pb_k] = c3_t_y;
  }

  for (c3_ob_k = 0; c3_ob_k < 4; c3_ob_k++) {
    c3_qb_k = c3_ob_k;
    c3_s_a = c3_gamma_star[c3_qb_k];
    c3_u_y = c3_s_a * c3_s_a;
    c3_e_y[c3_qb_k] = c3_u_y;
  }

  for (c3_i108 = 0; c3_i108 < 4; c3_i108++) {
    c3_mu_y[c3_i108] = (c3_b_PDY1 + c3_b_PDY2 * c3_dfz[c3_i108]) * ((c3_b_PPY3 *
      c3_dpi[c3_i108] + 1.0) + c3_b_PPY4 * c3_mu_y[c3_i108]) * (1.0 - c3_b_PDY3 *
      c3_e_y[c3_i108]) * c3_lam_muy[c3_i108];
  }

  for (c3_i109 = 0; c3_i109 < 4; c3_i109++) {
    c3_phi_t[c3_i109] = -c3_b_psidot[c3_i109] / c3_phi_t[c3_i109];
  }

  for (c3_i110 = 0; c3_i110 < 4; c3_i110++) {
    c3_f_x[c3_i110] = c3_alpha[c3_i110];
  }

  for (c3_rb_k = 0; c3_rb_k < 4; c3_rb_k++) {
    c3_sb_k = c3_rb_k;
    c3_r_x = c3_f_x[c3_sb_k];
    c3_s_x = c3_r_x;
    c3_s_x = muDoubleScalarCos(c3_s_x);
    c3_f_x[c3_sb_k] = c3_s_x;
  }

  for (c3_i111 = 0; c3_i111 < 4; c3_i111++) {
    c3_phi_t[c3_i111] *= c3_f_x[c3_i111];
  }

  c3_l_trueCount = 0;
  for (c3_gb_i = 0; c3_gb_i < 4; c3_gb_i++) {
    if (c3_isLowSpeed[c3_gb_i]) {
      c3_l_trueCount++;
    }
  }

  c3_f_tmp_size[0] = c3_l_trueCount;
  c3_g_partialTrueCount = 0;
  for (c3_hb_i = 0; c3_hb_i < 4; c3_hb_i++) {
    if (c3_isLowSpeed[c3_hb_i]) {
      c3_f_tmp_data[c3_g_partialTrueCount] = c3_hb_i + 1;
      c3_g_partialTrueCount++;
    }
  }

  c3_Vx_size[0] = c3_f_tmp_size[0];
  c3_n_loop_ub = c3_f_tmp_size[0] - 1;
  for (c3_i112 = 0; c3_i112 <= c3_n_loop_ub; c3_i112++) {
    c3_Vx_data[c3_i112] = c3_b_Vx[c3_f_tmp_data[c3_i112] - 1];
  }

  c3_abs(chartInstance, c3_Vx_data, c3_Vx_size, c3_d_tmp_data, c3_d_tmp_size);
  c3_o_loop_ub = c3_d_tmp_size[0] - 1;
  for (c3_i113 = 0; c3_i113 <= c3_o_loop_ub; c3_i113++) {
    c3_d_tmp_data[c3_i113] /= c3_b_VXLOW;
  }

  c3_m_trueCount = 0;
  for (c3_ib_i = 0; c3_ib_i < 4; c3_ib_i++) {
    if (c3_isLowSpeed[c3_ib_i]) {
      c3_m_trueCount++;
    }
  }

  if ((c3_m_trueCount != c3_d_tmp_size[0]) && ((c3_m_trueCount != 1) &&
       (c3_d_tmp_size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(c3_m_trueCount, c3_d_tmp_size[0], &c3_c_emlrtECI,
      (emlrtConstCTX)c3_sp);
  }

  c3_n_trueCount = 0;
  for (c3_jb_i = 0; c3_jb_i < 4; c3_jb_i++) {
    if (c3_isLowSpeed[c3_jb_i]) {
      c3_n_trueCount++;
    }
  }

  c3_g_tmp_size[0] = c3_n_trueCount;
  c3_h_partialTrueCount = 0;
  for (c3_kb_i = 0; c3_kb_i < 4; c3_kb_i++) {
    if (c3_isLowSpeed[c3_kb_i]) {
      c3_g_tmp_data[c3_h_partialTrueCount] = c3_kb_i + 1;
      c3_h_partialTrueCount++;
    }
  }

  if (c3_g_tmp_size[0] == c3_d_tmp_size[0]) {
    c3_tmpDrphiVar_size[0] = c3_g_tmp_size[0];
    c3_p_loop_ub = c3_g_tmp_size[0] - 1;
    for (c3_i114 = 0; c3_i114 <= c3_p_loop_ub; c3_i114++) {
      c3_tmpDrphiVar_data[c3_i114] = c3_phi_t[c3_g_tmp_data[c3_i114] - 1] *
        c3_d_tmp_data[c3_i114];
    }
  } else {
    c3_g_binary_expand_op(chartInstance, c3_tmpDrphiVar_data,
                          c3_tmpDrphiVar_size, c3_phi_t, c3_g_tmp_data,
                          c3_g_tmp_size, c3_d_tmp_data, c3_d_tmp_size);
  }

  c3_o_trueCount = 0;
  for (c3_lb_i = 0; c3_lb_i < 4; c3_lb_i++) {
    if (c3_isLowSpeed[c3_lb_i]) {
      c3_o_trueCount++;
    }
  }

  if (c3_o_trueCount != c3_tmpDrphiVar_size[0]) {
    emlrtSubAssignSizeCheck1dR2017a(c3_o_trueCount, c3_tmpDrphiVar_size[0],
      &c3_b_emlrtECI, (emlrtConstCTX)c3_sp);
  }

  c3_i_partialTrueCount = 0;
  for (c3_mb_i = 0; c3_mb_i < 4; c3_mb_i++) {
    if (c3_isLowSpeed[c3_mb_i]) {
      c3_phi_t[c3_mb_i] = c3_tmpDrphiVar_data[c3_i_partialTrueCount];
      c3_i_partialTrueCount++;
    }
  }

  for (c3_i115 = 0; c3_i115 < 4; c3_i115++) {
    c3_Vc_prime[c3_i115] = 1.0 / c3_Vc_prime[c3_i115];
  }

  for (c3_tb_k = 0; c3_tb_k < 4; c3_tb_k++) {
    c3_ub_k = c3_tb_k;
    c3_t_x = c3_b_Omega[c3_ub_k];
    c3_v_y = muDoubleScalarAbs(c3_t_x);
    c3_e_y[c3_ub_k] = c3_v_y;
  }

  for (c3_i116 = 0; c3_i116 < 4; c3_i116++) {
    c3_f_x[c3_i116] = c3_gamma[c3_i116];
  }

  for (c3_vb_k = 0; c3_vb_k < 4; c3_vb_k++) {
    c3_wb_k = c3_vb_k;
    c3_u_x = c3_f_x[c3_wb_k];
    c3_v_x = c3_u_x;
    c3_v_x = muDoubleScalarSin(c3_v_x);
    c3_f_x[c3_wb_k] = c3_v_x;
  }

  for (c3_i117 = 0; c3_i117 < 4; c3_i117++) {
    c3_Vc_prime[c3_i117] = -c3_Vc_prime[c3_i117] * (c3_b_psidot[c3_i117] - (1.0
      - c3_epsilon_gamma[c3_i117]) * c3_e_y[c3_i117] * c3_f_x[c3_i117]);
  }

  if (c3_b_turnslip == 1.0) {
    for (c3_xb_k = 0; c3_xb_k < 4; c3_xb_k++) {
      c3_yb_k = c3_xb_k;
      c3_w_x = c3_Vc_prime[c3_yb_k];
      c3_w_y = muDoubleScalarAbs(c3_w_x);
      c3_e_y[c3_yb_k] = c3_w_y;
    }

    for (c3_i119 = 0; c3_i119 < 4; c3_i119++) {
      c3_isLowSpeed[c3_i119] = (c3_e_y[c3_i119] > 0.01);
    }
  } else {
    for (c3_i118 = 0; c3_i118 < 4; c3_i118++) {
      c3_isLowSpeed[c3_i118] = false;
    }
  }

  for (c3_i120 = 0; c3_i120 < 4; c3_i120++) {
    c3_Vs[c3_i120] = c3_b_RHY1 + c3_b_RHY2 * c3_dfz[c3_i120];
  }

  for (c3_i121 = 0; c3_i121 < 4; c3_i121++) {
    c3_Vsy[c3_i121] = c3_b_REY1 + c3_b_REY2 * c3_dfz[c3_i121];
  }

  for (c3_nb_i = 0; c3_nb_i < 4; c3_nb_i++) {
    if (c3_b_REY1 + c3_b_REY2 * c3_dfz[c3_nb_i] > 1.0) {
      c3_Vsy[c3_nb_i] = 1.0;
    }
  }

  for (c3_ac_k = 0; c3_ac_k < 4; c3_ac_k++) {
    c3_bc_k = c3_ac_k;
    c3_t_a = c3_gamma_star[c3_bc_k];
    c3_x_y = c3_t_a * c3_t_a;
    c3_Bykappa[c3_bc_k] = c3_x_y;
  }

  for (c3_i122 = 0; c3_i122 < 4; c3_i122++) {
    c3_f_x[c3_i122] = c3_b_RBY2 * (c3_alpha[c3_i122] - c3_b_RBY3);
  }

  for (c3_cc_k = 0; c3_cc_k < 4; c3_cc_k++) {
    c3_ec_k = c3_cc_k;
    c3_x_x = c3_f_x[c3_ec_k];
    c3_y_x = c3_x_x;
    c3_y_x = muDoubleScalarAtan(c3_y_x);
    c3_f_x[c3_ec_k] = c3_y_x;
  }

  for (c3_dc_k = 0; c3_dc_k < 4; c3_dc_k++) {
    c3_fc_k = c3_dc_k;
    c3_ab_x = c3_f_x[c3_fc_k];
    c3_bb_x = c3_ab_x;
    c3_bb_x = muDoubleScalarCos(c3_bb_x);
    c3_f_x[c3_fc_k] = c3_bb_x;
  }

  for (c3_i123 = 0; c3_i123 < 4; c3_i123++) {
    c3_Bykappa[c3_i123] = (c3_b_RBY1 + c3_b_RBY4 * c3_Bykappa[c3_i123]) *
      c3_f_x[c3_i123] * c3_lam_ykappa[c3_i123];
  }

  for (c3_ob_i = 0; c3_ob_i < 4; c3_ob_i++) {
    if (c3_Bykappa[c3_ob_i] < 0.0) {
      c3_Bykappa[c3_ob_i] = 0.0;
    }
  }

  for (c3_i124 = 0; c3_i124 < 4; c3_i124++) {
    c3_lam_ykappa[c3_i124] = c3_kappa[c3_i124] + c3_Vs[c3_i124];
  }

  for (c3_i125 = 0; c3_i125 < 36; c3_i125++) {
    c3_zeta[c3_i125] = 1.0;
  }

  c3_p_trueCount = 0;
  for (c3_pb_i = 0; c3_pb_i < 4; c3_pb_i++) {
    if (c3_isLowSpeed[c3_pb_i]) {
      c3_p_trueCount++;
    }
  }

  c3_h_tmp_size[0] = c3_p_trueCount;
  c3_j_partialTrueCount = 0;
  for (c3_qb_i = 0; c3_qb_i < 4; c3_qb_i++) {
    if (c3_isLowSpeed[c3_qb_i]) {
      c3_h_tmp_data[c3_j_partialTrueCount] = c3_qb_i + 1;
      c3_j_partialTrueCount++;
    }
  }

  c3_iv[1] = c3_h_tmp_size[0];
  c3_q_loop_ub = c3_iv[1] - 1;
  for (c3_i126 = 0; c3_i126 <= c3_q_loop_ub; c3_i126++) {
    c3_zeta[9 * (c3_h_tmp_data[c3_i126] - 1)] = 0.0;
  }

  if (c3_any(chartInstance, c3_isLowSpeed)) {
    for (c3_i127 = 0; c3_i127 < 4; c3_i127++) {
      c3_Fz_btm[c3_i127] = c3_b_PDXP3 * c3_kappa[c3_i127];
    }

    for (c3_hc_k = 0; c3_hc_k < 4; c3_hc_k++) {
      c3_lc_k = c3_hc_k;
      c3_db_x = c3_Fz_btm[c3_lc_k];
      c3_eb_x = c3_db_x;
      c3_eb_x = muDoubleScalarAtan(c3_eb_x);
      c3_Fz_btm[c3_lc_k] = c3_eb_x;
    }

    for (c3_kc_k = 0; c3_kc_k < 4; c3_kc_k++) {
      c3_nc_k = c3_kc_k;
      c3_fb_x = c3_Fz_btm[c3_nc_k];
      c3_gb_x = c3_fb_x;
      c3_gb_x = muDoubleScalarCos(c3_gb_x);
      c3_Fz_btm[c3_nc_k] = c3_gb_x;
    }

    for (c3_i129 = 0; c3_i129 < 4; c3_i129++) {
      c3_Fz_btm[c3_i129] *= c3_b_PDXP1 * (c3_b_PDXP2 * c3_dfz[c3_i129] + 1.0);
    }

    for (c3_i130 = 0; c3_i130 < 4; c3_i130++) {
      c3_lam_Cz[c3_i130] = c3_alpha[c3_i130];
    }

    for (c3_qc_k = 0; c3_qc_k < 4; c3_qc_k++) {
      c3_sc_k = c3_qc_k;
      c3_jb_x = c3_lam_Cz[c3_sc_k];
      c3_lb_x = c3_jb_x;
      c3_lb_x = muDoubleScalarTan(c3_lb_x);
      c3_lam_Cz[c3_sc_k] = c3_lb_x;
    }

    for (c3_i132 = 0; c3_i132 < 4; c3_i132++) {
      c3_lam_Cz[c3_i132] *= c3_b_PDYP3;
    }

    for (c3_uc_k = 0; c3_uc_k < 4; c3_uc_k++) {
      c3_xc_k = c3_uc_k;
      c3_nb_x = c3_lam_Cz[c3_xc_k];
      c3_ob_x = c3_nb_x;
      c3_ob_x = muDoubleScalarAtan(c3_ob_x);
      c3_lam_Cz[c3_xc_k] = c3_ob_x;
    }

    for (c3_wc_k = 0; c3_wc_k < 4; c3_wc_k++) {
      c3_ad_k = c3_wc_k;
      c3_pb_x = c3_lam_Cz[c3_ad_k];
      c3_qb_x = c3_pb_x;
      c3_qb_x = muDoubleScalarCos(c3_qb_x);
      c3_lam_Cz[c3_ad_k] = c3_qb_x;
    }

    for (c3_i136 = 0; c3_i136 < 4; c3_i136++) {
      c3_lam_Cz[c3_i136] *= c3_b_PDYP1 * (c3_b_PDYP2 * c3_dfz[c3_i136] + 1.0);
    }

    c3_q_trueCount = 0;
    for (c3_rb_i = 0; c3_rb_i < 4; c3_rb_i++) {
      if (c3_isLowSpeed[c3_rb_i]) {
        c3_q_trueCount++;
      }
    }

    c3_i_tmp_size[0] = c3_q_trueCount;
    c3_k_partialTrueCount = 0;
    for (c3_sb_i = 0; c3_sb_i < 4; c3_sb_i++) {
      if (c3_isLowSpeed[c3_sb_i]) {
        c3_i_tmp_data[c3_k_partialTrueCount] = c3_sb_i + 1;
        c3_k_partialTrueCount++;
      }
    }

    c3_d_tmp_size[0] = c3_i_tmp_size[0];
    c3_r_loop_ub = c3_i_tmp_size[0] - 1;
    for (c3_i140 = 0; c3_i140 <= c3_r_loop_ub; c3_i140++) {
      c3_d_tmp_data[c3_i140] = c3_Fz_btm[c3_i_tmp_data[c3_i140] - 1] *
        c3_b_UNLOADED_RADIUS * c3_Vc_prime[c3_i_tmp_data[c3_i140] - 1];
    }

    c3_b_atan(chartInstance, c3_d_tmp_data, c3_d_tmp_size);
    c3_b_cos(chartInstance, c3_d_tmp_data, c3_d_tmp_size);
    c3_r_trueCount = 0;
    for (c3_tb_i = 0; c3_tb_i < 4; c3_tb_i++) {
      if (c3_isLowSpeed[c3_tb_i]) {
        c3_r_trueCount++;
      }
    }

    c3_iv1[0] = 1;
    c3_iv1[1] = c3_r_trueCount;
    emlrtSubAssignSizeCheckR2012b(&c3_iv1[0], 2, &c3_d_tmp_size[0], 1,
      &c3_b_emlrtECI, (void *)c3_sp);
    c3_s_trueCount = 0;
    for (c3_vb_i = 0; c3_vb_i < 4; c3_vb_i++) {
      if (c3_isLowSpeed[c3_vb_i]) {
        c3_s_trueCount++;
      }
    }

    c3_j_tmp_size[0] = c3_s_trueCount;
    c3_l_partialTrueCount = 0;
    for (c3_wb_i = 0; c3_wb_i < 4; c3_wb_i++) {
      if (c3_isLowSpeed[c3_wb_i]) {
        c3_j_tmp_data[c3_l_partialTrueCount] = c3_wb_i + 1;
        c3_l_partialTrueCount++;
      }
    }

    c3_iv2[1] = c3_j_tmp_size[0];
    c3_s_loop_ub = c3_iv2[1] - 1;
    for (c3_i143 = 0; c3_i143 <= c3_s_loop_ub; c3_i143++) {
      c3_zeta[1 + 9 * (c3_j_tmp_data[c3_i143] - 1)] = c3_d_tmp_data[c3_i143];
    }

    c3_t_trueCount = 0;
    for (c3_yb_i = 0; c3_yb_i < 4; c3_yb_i++) {
      if (c3_isLowSpeed[c3_yb_i]) {
        c3_t_trueCount++;
      }
    }

    c3_k_tmp_size[0] = c3_t_trueCount;
    c3_m_partialTrueCount = 0;
    for (c3_ac_i = 0; c3_ac_i < 4; c3_ac_i++) {
      if (c3_isLowSpeed[c3_ac_i]) {
        c3_k_tmp_data[c3_m_partialTrueCount] = c3_ac_i + 1;
        c3_m_partialTrueCount++;
      }
    }

    c3_Vc_prime_size[0] = c3_k_tmp_size[0];
    c3_t_loop_ub = c3_k_tmp_size[0] - 1;
    for (c3_i148 = 0; c3_i148 <= c3_t_loop_ub; c3_i148++) {
      c3_Vc_prime_data[c3_i148] = c3_Vc_prime[c3_k_tmp_data[c3_i148] - 1];
    }

    c3_abs(chartInstance, c3_Vc_prime_data, c3_Vc_prime_size, c3_d_tmp_data,
           c3_d_tmp_size);
    c3_u_loop_ub = c3_d_tmp_size[0] - 1;
    for (c3_i151 = 0; c3_i151 <= c3_u_loop_ub; c3_i151++) {
      c3_d_tmp_data[c3_i151] *= c3_b_UNLOADED_RADIUS;
    }

    c3_u_trueCount = 0;
    for (c3_bc_i = 0; c3_bc_i < 4; c3_bc_i++) {
      if (c3_isLowSpeed[c3_bc_i]) {
        c3_u_trueCount++;
      }
    }

    c3_l_tmp_size[0] = c3_u_trueCount;
    c3_n_partialTrueCount = 0;
    for (c3_cc_i = 0; c3_cc_i < 4; c3_cc_i++) {
      if (c3_isLowSpeed[c3_cc_i]) {
        c3_l_tmp_data[c3_n_partialTrueCount] = c3_cc_i + 1;
        c3_n_partialTrueCount++;
      }
    }

    c3_b_Vc_prime_size[0] = c3_l_tmp_size[0];
    c3_v_loop_ub = c3_l_tmp_size[0] - 1;
    for (c3_i155 = 0; c3_i155 <= c3_v_loop_ub; c3_i155++) {
      c3_b_Vc_prime_data[c3_i155] = c3_Vc_prime[c3_l_tmp_data[c3_i155] - 1];
    }

    c3_abs(chartInstance, c3_b_Vc_prime_data, c3_b_Vc_prime_size,
           c3_tmpDrphiVar_data, c3_tmpDrphiVar_size);
    c3_w_loop_ub = c3_tmpDrphiVar_size[0] - 1;
    for (c3_i157 = 0; c3_i157 <= c3_w_loop_ub; c3_i157++) {
      c3_tmpDrphiVar_data[c3_i157] *= c3_b_UNLOADED_RADIUS;
    }

    c3_st.site = &c3_b_emlrtRSI;
    c3_f_sqrt(chartInstance, &c3_st, c3_tmpDrphiVar_data, c3_tmpDrphiVar_size);
    c3_x_loop_ub = c3_tmpDrphiVar_size[0] - 1;
    for (c3_i160 = 0; c3_i160 <= c3_x_loop_ub; c3_i160++) {
      c3_tmpDrphiVar_data[c3_i160] *= c3_b_PDYP4;
    }

    if ((c3_d_tmp_size[0] != c3_tmpDrphiVar_size[0]) && ((c3_d_tmp_size[0] != 1)
         && (c3_tmpDrphiVar_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(c3_d_tmp_size[0], c3_tmpDrphiVar_size[0],
        &c3_c_emlrtECI, (emlrtConstCTX)c3_sp);
    }

    if (c3_d_tmp_size[0] == c3_tmpDrphiVar_size[0]) {
      c3_bb_loop_ub = c3_d_tmp_size[0] - 1;
      for (c3_i164 = 0; c3_i164 <= c3_bb_loop_ub; c3_i164++) {
        c3_d_tmp_data[c3_i164] += c3_tmpDrphiVar_data[c3_i164];
      }
    } else {
      c3_plus(chartInstance, c3_d_tmp_data, c3_d_tmp_size, c3_tmpDrphiVar_data,
              c3_tmpDrphiVar_size);
    }

    c3_w_trueCount = 0;
    for (c3_ic_i = 0; c3_ic_i < 4; c3_ic_i++) {
      if (c3_isLowSpeed[c3_ic_i]) {
        c3_w_trueCount++;
      }
    }

    if ((c3_w_trueCount != c3_d_tmp_size[0]) && ((c3_w_trueCount != 1) &&
         (c3_d_tmp_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(c3_w_trueCount, c3_d_tmp_size[0],
        &c3_c_emlrtECI, (emlrtConstCTX)c3_sp);
    }

    c3_x_trueCount = 0;
    for (c3_kc_i = 0; c3_kc_i < 4; c3_kc_i++) {
      if (c3_isLowSpeed[c3_kc_i]) {
        c3_x_trueCount++;
      }
    }

    c3_n_tmp_size[0] = c3_x_trueCount;
    c3_p_partialTrueCount = 0;
    for (c3_mc_i = 0; c3_mc_i < 4; c3_mc_i++) {
      if (c3_isLowSpeed[c3_mc_i]) {
        c3_n_tmp_data[c3_p_partialTrueCount] = c3_mc_i + 1;
        c3_p_partialTrueCount++;
      }
    }

    if (c3_n_tmp_size[0] == c3_d_tmp_size[0]) {
      c3_tmpDrphiVar_size[0] = c3_n_tmp_size[0];
      c3_db_loop_ub = c3_n_tmp_size[0] - 1;
      for (c3_i170 = 0; c3_i170 <= c3_db_loop_ub; c3_i170++) {
        c3_tmpDrphiVar_data[c3_i170] = c3_lam_Cz[c3_n_tmp_data[c3_i170] - 1] *
          c3_d_tmp_data[c3_i170];
      }
    } else {
      c3_g_binary_expand_op(chartInstance, c3_tmpDrphiVar_data,
                            c3_tmpDrphiVar_size, c3_lam_Cz, c3_n_tmp_data,
                            c3_n_tmp_size, c3_d_tmp_data, c3_d_tmp_size);
    }

    c3_b_atan(chartInstance, c3_tmpDrphiVar_data, c3_tmpDrphiVar_size);
    c3_b_cos(chartInstance, c3_tmpDrphiVar_data, c3_tmpDrphiVar_size);
    c3_bb_trueCount = 0;
    for (c3_pc_i = 0; c3_pc_i < 4; c3_pc_i++) {
      if (c3_isLowSpeed[c3_pc_i]) {
        c3_bb_trueCount++;
      }
    }

    c3_iv3[0] = 1;
    c3_iv3[1] = c3_bb_trueCount;
    emlrtSubAssignSizeCheckR2012b(&c3_iv3[0], 2, &c3_tmpDrphiVar_size[0], 1,
      &c3_b_emlrtECI, (void *)c3_sp);
    c3_db_trueCount = 0;
    for (c3_rc_i = 0; c3_rc_i < 4; c3_rc_i++) {
      if (c3_isLowSpeed[c3_rc_i]) {
        c3_db_trueCount++;
      }
    }

    c3_p_tmp_size[0] = c3_db_trueCount;
    c3_r_partialTrueCount = 0;
    for (c3_tc_i = 0; c3_tc_i < 4; c3_tc_i++) {
      if (c3_isLowSpeed[c3_tc_i]) {
        c3_p_tmp_data[c3_r_partialTrueCount] = c3_tc_i + 1;
        c3_r_partialTrueCount++;
      }
    }

    c3_iv5[1] = c3_p_tmp_size[0];
    c3_fb_loop_ub = c3_iv5[1] - 1;
    for (c3_i178 = 0; c3_i178 <= c3_fb_loop_ub; c3_i178++) {
      c3_zeta[2 + 9 * (c3_p_tmp_data[c3_i178] - 1)] =
        c3_tmpDrphiVar_data[c3_i178];
    }

    c3_fb_trueCount = 0;
    for (c3_wc_i = 0; c3_wc_i < 4; c3_wc_i++) {
      if (c3_isLowSpeed[c3_wc_i]) {
        c3_fb_trueCount++;
      }
    }

    c3_r_tmp_size[0] = c3_fb_trueCount;
    c3_t_partialTrueCount = 0;
    for (c3_yc_i = 0; c3_yc_i < 4; c3_yc_i++) {
      if (c3_isLowSpeed[c3_yc_i]) {
        c3_r_tmp_data[c3_t_partialTrueCount] = c3_yc_i + 1;
        c3_t_partialTrueCount++;
      }
    }

    c3_st.site = &c3_b_emlrtRSI;
    c3_ab_a = c3_b_UNLOADED_RADIUS;
    c3_b_st.site = &c3_c_emlrtRSI;
    c3_bb_a = c3_ab_a;
    c3_cb_a = c3_bb_a;
    c3_db_a = c3_cb_a;
    c3_fb_y = c3_db_a * c3_db_a;
    c3_c_Vc_prime_size[0] = c3_r_tmp_size[0];
    c3_ib_loop_ub = c3_r_tmp_size[0] - 1;
    for (c3_i185 = 0; c3_i185 <= c3_ib_loop_ub; c3_i185++) {
      c3_c_Vc_prime_data[c3_i185] = c3_Vc_prime[c3_r_tmp_data[c3_i185] - 1];
    }

    c3_st.site = &c3_b_emlrtRSI;
    c3_power(chartInstance, &c3_st, c3_c_Vc_prime_data, c3_c_Vc_prime_size,
             c3_d_tmp_data, c3_d_tmp_size);
    c3_c_PKYP1 = c3_b_PKYP1 * c3_fb_y;
    c3_jb_loop_ub = c3_d_tmp_size[0] - 1;
    for (c3_i189 = 0; c3_i189 <= c3_jb_loop_ub; c3_i189++) {
      c3_d_tmp_data[c3_i189] *= c3_c_PKYP1;
    }

    c3_b_atan(chartInstance, c3_d_tmp_data, c3_d_tmp_size);
    c3_b_cos(chartInstance, c3_d_tmp_data, c3_d_tmp_size);
    c3_jb_trueCount = 0;
    for (c3_gd_i = 0; c3_gd_i < 4; c3_gd_i++) {
      if (c3_isLowSpeed[c3_gd_i]) {
        c3_jb_trueCount++;
      }
    }

    c3_iv8[0] = 1;
    c3_iv8[1] = c3_jb_trueCount;
    emlrtSubAssignSizeCheckR2012b(&c3_iv8[0], 2, &c3_d_tmp_size[0], 1,
      &c3_b_emlrtECI, (void *)c3_sp);
    c3_kb_trueCount = 0;
    for (c3_id_i = 0; c3_id_i < 4; c3_id_i++) {
      if (c3_isLowSpeed[c3_id_i]) {
        c3_kb_trueCount++;
      }
    }

    c3_u_tmp_size[0] = c3_kb_trueCount;
    c3_w_partialTrueCount = 0;
    for (c3_ld_i = 0; c3_ld_i < 4; c3_ld_i++) {
      if (c3_isLowSpeed[c3_ld_i]) {
        c3_u_tmp_data[c3_w_partialTrueCount] = c3_ld_i + 1;
        c3_w_partialTrueCount++;
      }
    }

    c3_iv10[1] = c3_u_tmp_size[0];
    c3_lb_loop_ub = c3_iv10[1] - 1;
    for (c3_i198 = 0; c3_i198 <= c3_lb_loop_ub; c3_i198++) {
      c3_zeta[3 + 9 * (c3_u_tmp_data[c3_i198] - 1)] = c3_d_tmp_data[c3_i198];
    }
  }

  for (c3_gc_k = 0; c3_gc_k < 4; c3_gc_k++) {
    c3_jc_k = c3_gc_k;
    c3_cb_x = c3_gamma_star[c3_jc_k];
    c3_y_y = muDoubleScalarAbs(c3_cb_x);
    c3_Kyalpha[c3_jc_k] = c3_y_y;
  }

  for (c3_ic_k = 0; c3_ic_k < 4; c3_ic_k++) {
    c3_mc_k = c3_ic_k;
    c3_u_a = c3_gamma_star[c3_mc_k];
    c3_ab_y = c3_u_a * c3_u_a;
    c3_e_y[c3_mc_k] = c3_ab_y;
  }

  for (c3_i128 = 0; c3_i128 < 4; c3_i128++) {
    c3_e_y[c3_i128] = c3_Fz[c3_i128] / c3_Fzo_prime[c3_i128] / (c3_b_PKY2 +
      c3_b_PKY5 * c3_e_y[c3_i128]) / (c3_b_PPY2 * c3_dpi[c3_i128] + 1.0);
  }

  for (c3_oc_k = 0; c3_oc_k < 4; c3_oc_k++) {
    c3_pc_k = c3_oc_k;
    c3_hb_x = c3_e_y[c3_pc_k];
    c3_ib_x = c3_hb_x;
    c3_ib_x = muDoubleScalarAtan(c3_ib_x);
    c3_e_y[c3_pc_k] = c3_ib_x;
  }

  for (c3_i131 = 0; c3_i131 < 4; c3_i131++) {
    c3_e_y[c3_i131] *= c3_b_PKY4;
  }

  for (c3_rc_k = 0; c3_rc_k < 4; c3_rc_k++) {
    c3_tc_k = c3_rc_k;
    c3_kb_x = c3_e_y[c3_tc_k];
    c3_mb_x = c3_kb_x;
    c3_mb_x = muDoubleScalarSin(c3_mb_x);
    c3_e_y[c3_tc_k] = c3_mb_x;
  }

  c3_i133 = 0;
  for (c3_i134 = 0; c3_i134 < 4; c3_i134++) {
    c3_Kyalpha[c3_i134] = c3_b_PKY1 * c3_Fzo_prime[c3_i134] * (c3_b_PPY1 *
      c3_dpi[c3_i134] + 1.0) * (1.0 - c3_b_PKY3 * c3_Kyalpha[c3_i134]) *
      c3_e_y[c3_i134] * c3_zeta[c3_i133 + 3] * c3_lam_Kyalpha[c3_i134];
    c3_i133 += 9;
  }

  for (c3_vc_k = 0; c3_vc_k < 4; c3_vc_k++) {
    c3_yc_k = c3_vc_k;
    c3_v_a = c3_gamma_star[c3_yc_k];
    c3_bb_y = c3_v_a * c3_v_a;
    c3_lam_Cz[c3_yc_k] = c3_bb_y;
  }

  for (c3_i135 = 0; c3_i135 < 4; c3_i135++) {
    c3_lam_Cz[c3_i135] = c3_Fz[c3_i135] / c3_Fzo_prime[c3_i135] / (c3_b_PKY2 +
      c3_b_PKY5 * c3_lam_Cz[c3_i135]) / (c3_b_PPY2 * c3_dpi[c3_i135] + 1.0);
  }

  for (c3_bd_k = 0; c3_bd_k < 4; c3_bd_k++) {
    c3_cd_k = c3_bd_k;
    c3_rb_x = c3_lam_Cz[c3_cd_k];
    c3_sb_x = c3_rb_x;
    c3_sb_x = muDoubleScalarAtan(c3_sb_x);
    c3_lam_Cz[c3_cd_k] = c3_sb_x;
  }

  for (c3_i137 = 0; c3_i137 < 4; c3_i137++) {
    c3_lam_Cz[c3_i137] *= c3_b_PKY4;
  }

  for (c3_dd_k = 0; c3_dd_k < 4; c3_dd_k++) {
    c3_ed_k = c3_dd_k;
    c3_tb_x = c3_lam_Cz[c3_ed_k];
    c3_ub_x = c3_tb_x;
    c3_ub_x = muDoubleScalarSin(c3_ub_x);
    c3_lam_Cz[c3_ed_k] = c3_ub_x;
  }

  c3_d = 1.0 - c3_b_PKY3 * 0.0;
  c3_i138 = 0;
  for (c3_i139 = 0; c3_i139 < 4; c3_i139++) {
    c3_lam_Cz[c3_i139] = c3_b_PKY1 * c3_Fzo_prime[c3_i139] * (c3_b_PPY1 *
      c3_dpi[c3_i139] + 1.0) * c3_d * c3_lam_Cz[c3_i139] * c3_zeta[c3_i138 + 3] *
      c3_lam_Kyalpha[c3_i139];
    c3_i138 += 9;
  }

  c3_st.site = &c3_b_emlrtRSI;
  c3_div0protect(chartInstance, &c3_st, c3_Kyalpha, 0.0001, c3_Kyalpha_prime,
                 c3_Fz_btm);
  c3_st.site = &c3_b_emlrtRSI;
  c3_div0protect(chartInstance, &c3_st, c3_lam_Cz, 0.0001, c3_lam_mux, c3_Fz_btm);
  c3_dv2[0] = c3_b_PHYP1;
  c3_bv[0] = (c3_b_PHYP1 < 0.0);
  for (c3_ub_i = 0; c3_ub_i < 1; c3_ub_i++) {
    if (c3_bv[0]) {
      c3_dv2[c3_ub_i] = 0.0;
    }
  }

  c3_CHyphi = c3_dv2[0];
  for (c3_i141 = 0; c3_i141 < 4; c3_i141++) {
    c3_Fz_btm[c3_i141] = c3_b_Vx[c3_i141];
  }

  for (c3_fd_k = 0; c3_fd_k < 4; c3_fd_k++) {
    c3_gd_k = c3_fd_k;
    c3_vb_x = c3_Fz_btm[c3_gd_k];
    c3_wb_x = c3_vb_x;
    c3_wb_x = muDoubleScalarTanh(c3_wb_x);
    c3_Fz_btm[c3_gd_k] = c3_wb_x;
  }

  for (c3_i142 = 0; c3_i142 < 4; c3_i142++) {
    c3_Fz_btm[c3_i142] *= c3_b_PHYP2 + c3_b_PHYP3 * c3_dfz[c3_i142];
  }

  c3_dv3[0] = c3_b_PHYP4;
  c3_bv[0] = (c3_b_PHYP4 > 1.0);
  for (c3_xb_i = 0; c3_xb_i < 1; c3_xb_i++) {
    if (c3_bv[0]) {
      c3_dv3[c3_xb_i] = 1.0;
    }
  }

  c3_EHyphi = c3_dv3[0];
  for (c3_i144 = 0; c3_i144 < 4; c3_i144++) {
    c3_lam_Cz[c3_i144] = c3_Fz[c3_i144] * (c3_b_PKY6 + c3_b_PKY7 *
      c3_dfz[c3_i144]) * (c3_b_PPY5 * c3_dpi[c3_i144] + 1.0) *
      c3_lam_Kygamma[c3_i144] / (1.0 - c3_epsilon_gamma[c3_i144]);
  }

  for (c3_i145 = 0; c3_i145 < 4; c3_i145++) {
    c3_lam_Cz[c3_i145] /= c3_CHyphi * c3_Fz_btm[c3_i145] * c3_lam_mux[c3_i145];
  }

  for (c3_i146 = 0; c3_i146 < 4; c3_i146++) {
    c3_f_x[c3_i146] = c3_b_Vx[c3_i146];
  }

  for (c3_hd_k = 0; c3_hd_k < 4; c3_hd_k++) {
    c3_id_k = c3_hd_k;
    c3_xb_x = c3_f_x[c3_id_k];
    c3_yb_x = c3_xb_x;
    c3_yb_x = muDoubleScalarTanh(c3_yb_x);
    c3_f_x[c3_id_k] = c3_yb_x;
  }

  for (c3_i147 = 0; c3_i147 < 4; c3_i147++) {
    c3_c_UNLOADED_RADIUS[c3_i147] = c3_b_UNLOADED_RADIUS * c3_Vc_prime[c3_i147];
  }

  c3_magicsin(chartInstance, c3_Fz_btm, c3_CHyphi, c3_lam_Cz, c3_EHyphi,
              c3_c_UNLOADED_RADIUS, c3_SHyphi);
  for (c3_i149 = 0; c3_i149 < 4; c3_i149++) {
    c3_SHyphi[c3_i149] *= c3_f_x[c3_i149];
  }

  c3_i150 = 0;
  for (c3_i152 = 0; c3_i152 < 4; c3_i152++) {
    c3_SVygamma[c3_i152] = c3_Fz[c3_i152] * (c3_b_PVY3 + c3_b_PVY4 *
      c3_dfz[c3_i152]) * c3_gamma_star[c3_i152] * c3_zeta[c3_i150 + 2] *
      c3_lam_Kygamma[c3_i152] * c3_lam_muy_prime[c3_i152];
    c3_i150 += 9;
  }

  for (c3_i153 = 0; c3_i153 < 4; c3_i153++) {
    c3_SHy[c3_i153] = 0.0;
  }

  c3_magiccos(chartInstance, c3_b_RCY1, c3_Bykappa, c3_Vsy, c3_Vs, c3_Fz_btm);
  c3_magiccos(chartInstance, c3_b_RCY1, c3_Bykappa, c3_Vsy, c3_lam_ykappa, c3_Vs);
  for (c3_i154 = 0; c3_i154 < 4; c3_i154++) {
    c3_Vs[c3_i154] /= c3_Fz_btm[c3_i154];
  }

  for (c3_dc_i = 0; c3_dc_i < 4; c3_dc_i++) {
    if (c3_Vs[c3_dc_i] < 0.0) {
      c3_Vs[c3_dc_i] = 0.0;
    }
  }

  if (c3_any(chartInstance, c3_isLowSpeed)) {
    c3_v_trueCount = 0;
    for (c3_ec_i = 0; c3_ec_i < 4; c3_ec_i++) {
      if (c3_isLowSpeed[c3_ec_i]) {
        c3_v_trueCount++;
      }
    }

    c3_m_tmp_size[0] = c3_v_trueCount;
    c3_o_partialTrueCount = 0;
    for (c3_gc_i = 0; c3_gc_i < 4; c3_gc_i++) {
      if (c3_isLowSpeed[c3_gc_i]) {
        c3_m_tmp_data[c3_o_partialTrueCount] = c3_gc_i + 1;
        c3_o_partialTrueCount++;
      }
    }

    c3_st.site = &c3_b_emlrtRSI;
    c3_tmpDrphiVar_size[0] = c3_m_tmp_size[0];
    c3_y_loop_ub = c3_m_tmp_size[0] - 1;
    for (c3_i161 = 0; c3_i161 <= c3_y_loop_ub; c3_i161++) {
      c3_tmpDrphiVar_data[c3_i161] = c3_SVygamma[c3_m_tmp_data[c3_i161] - 1];
    }

    c3_y_size[0] = c3_m_tmp_size[0];
    c3_ab_loop_ub = c3_m_tmp_size[0] - 1;
    for (c3_i163 = 0; c3_i163 <= c3_ab_loop_ub; c3_i163++) {
      c3_y_data[c3_i163] = c3_Kyalpha_prime[c3_m_tmp_data[c3_i163] - 1];
    }

    c3_b_st.site = &c3_d_emlrtRSI;
    c3_c_st.site = &c3_e_emlrtRSI;
    c3_c_assertCompatibleDims(chartInstance, &c3_c_st, c3_tmpDrphiVar_size,
      c3_y_size);
    c3_cb_loop_ub = c3_tmpDrphiVar_size[0] - 1;
    for (c3_i167 = 0; c3_i167 <= c3_cb_loop_ub; c3_i167++) {
      c3_tmpDrphiVar_data[c3_i167] /= c3_y_data[c3_i167];
    }

    c3_y_trueCount = 0;
    for (c3_lc_i = 0; c3_lc_i < 4; c3_lc_i++) {
      if (c3_isLowSpeed[c3_lc_i]) {
        c3_y_trueCount++;
      }
    }

    if ((c3_y_trueCount != c3_tmpDrphiVar_size[0]) && ((c3_y_trueCount != 1) &&
         (c3_tmpDrphiVar_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(c3_y_trueCount, c3_tmpDrphiVar_size[0],
        &c3_c_emlrtECI, (emlrtConstCTX)c3_sp);
    }

    c3_ab_trueCount = 0;
    for (c3_nc_i = 0; c3_nc_i < 4; c3_nc_i++) {
      if (c3_isLowSpeed[c3_nc_i]) {
        c3_ab_trueCount++;
      }
    }

    c3_o_tmp_size[0] = c3_ab_trueCount;
    c3_q_partialTrueCount = 0;
    for (c3_oc_i = 0; c3_oc_i < 4; c3_oc_i++) {
      if (c3_isLowSpeed[c3_oc_i]) {
        c3_o_tmp_data[c3_q_partialTrueCount] = c3_oc_i + 1;
        c3_q_partialTrueCount++;
      }
    }

    if (c3_o_tmp_size[0] == c3_tmpDrphiVar_size[0]) {
      c3_d_tmp_size[0] = c3_o_tmp_size[0];
      c3_eb_loop_ub = c3_o_tmp_size[0] - 1;
      for (c3_i174 = 0; c3_i174 <= c3_eb_loop_ub; c3_i174++) {
        c3_d_tmp_data[c3_i174] = (c3_SHyphi[c3_o_tmp_data[c3_i174] - 1] + 1.0) -
          c3_tmpDrphiVar_data[c3_i174];
      }
    } else {
      c3_f_binary_expand_op(chartInstance, c3_d_tmp_data, c3_d_tmp_size,
                            c3_SHyphi, c3_o_tmp_data, c3_o_tmp_size,
                            c3_tmpDrphiVar_data, c3_tmpDrphiVar_size);
    }

    c3_cb_trueCount = 0;
    for (c3_qc_i = 0; c3_qc_i < 4; c3_qc_i++) {
      if (c3_isLowSpeed[c3_qc_i]) {
        c3_cb_trueCount++;
      }
    }

    c3_iv4[0] = 1;
    c3_iv4[1] = c3_cb_trueCount;
    emlrtSubAssignSizeCheckR2012b(&c3_iv4[0], 2, &c3_d_tmp_size[0], 1,
      &c3_b_emlrtECI, (void *)c3_sp);
    c3_eb_trueCount = 0;
    for (c3_uc_i = 0; c3_uc_i < 4; c3_uc_i++) {
      if (c3_isLowSpeed[c3_uc_i]) {
        c3_eb_trueCount++;
      }
    }

    c3_q_tmp_size[0] = c3_eb_trueCount;
    c3_s_partialTrueCount = 0;
    for (c3_vc_i = 0; c3_vc_i < 4; c3_vc_i++) {
      if (c3_isLowSpeed[c3_vc_i]) {
        c3_q_tmp_data[c3_s_partialTrueCount] = c3_vc_i + 1;
        c3_s_partialTrueCount++;
      }
    }

    c3_iv6[1] = c3_q_tmp_size[0];
    c3_gb_loop_ub = c3_iv6[1] - 1;
    for (c3_i180 = 0; c3_i180 <= c3_gb_loop_ub; c3_i180++) {
      c3_zeta[4 + 9 * (c3_q_tmp_data[c3_i180] - 1)] = c3_d_tmp_data[c3_i180];
    }

    c3_gb_trueCount = 0;
    for (c3_ad_i = 0; c3_ad_i < 4; c3_ad_i++) {
      if (c3_isLowSpeed[c3_ad_i]) {
        c3_gb_trueCount++;
      }
    }

    c3_s_tmp_size[0] = c3_gb_trueCount;
    c3_u_partialTrueCount = 0;
    for (c3_bd_i = 0; c3_bd_i < 4; c3_bd_i++) {
      if (c3_isLowSpeed[c3_bd_i]) {
        c3_s_tmp_data[c3_u_partialTrueCount] = c3_bd_i + 1;
        c3_u_partialTrueCount++;
      }
    }

    c3_c_QDTP1 = c3_b_QDTP1 * c3_b_UNLOADED_RADIUS;
    c3_d_tmp_size[0] = c3_s_tmp_size[0];
    c3_hb_loop_ub = c3_s_tmp_size[0] - 1;
    for (c3_i184 = 0; c3_i184 <= c3_hb_loop_ub; c3_i184++) {
      c3_d_tmp_data[c3_i184] = c3_c_QDTP1 * c3_Vc_prime[c3_s_tmp_data[c3_i184] -
        1];
    }

    c3_b_atan(chartInstance, c3_d_tmp_data, c3_d_tmp_size);
    c3_b_cos(chartInstance, c3_d_tmp_data, c3_d_tmp_size);
    c3_hb_trueCount = 0;
    for (c3_ed_i = 0; c3_ed_i < 4; c3_ed_i++) {
      if (c3_isLowSpeed[c3_ed_i]) {
        c3_hb_trueCount++;
      }
    }

    c3_iv7[0] = 1;
    c3_iv7[1] = c3_hb_trueCount;
    emlrtSubAssignSizeCheckR2012b(&c3_iv7[0], 2, &c3_d_tmp_size[0], 1,
      &c3_b_emlrtECI, (void *)c3_sp);
    c3_ib_trueCount = 0;
    for (c3_fd_i = 0; c3_fd_i < 4; c3_fd_i++) {
      if (c3_isLowSpeed[c3_fd_i]) {
        c3_ib_trueCount++;
      }
    }

    c3_t_tmp_size[0] = c3_ib_trueCount;
    c3_v_partialTrueCount = 0;
    for (c3_hd_i = 0; c3_hd_i < 4; c3_hd_i++) {
      if (c3_isLowSpeed[c3_hd_i]) {
        c3_t_tmp_data[c3_v_partialTrueCount] = c3_hd_i + 1;
        c3_v_partialTrueCount++;
      }
    }

    c3_iv9[1] = c3_t_tmp_size[0];
    c3_kb_loop_ub = c3_iv9[1] - 1;
    for (c3_i194 = 0; c3_i194 <= c3_kb_loop_ub; c3_i194++) {
      c3_zeta[5 + 9 * (c3_t_tmp_data[c3_i194] - 1)] = c3_d_tmp_data[c3_i194];
    }

    c3_mb_trueCount = 0;
    for (c3_kd_i = 0; c3_kd_i < 4; c3_kd_i++) {
      if (c3_isLowSpeed[c3_kd_i]) {
        c3_mb_trueCount++;
      }
    }

    c3_w_tmp_size[0] = c3_mb_trueCount;
    c3_y_partialTrueCount = 0;
    for (c3_nd_i = 0; c3_nd_i < 4; c3_nd_i++) {
      if (c3_isLowSpeed[c3_nd_i]) {
        c3_w_tmp_data[c3_y_partialTrueCount] = c3_nd_i + 1;
        c3_y_partialTrueCount++;
      }
    }

    c3_c_QBRP1 = c3_b_QBRP1 * c3_b_UNLOADED_RADIUS;
    c3_d_tmp_size[0] = c3_w_tmp_size[0];
    c3_nb_loop_ub = c3_w_tmp_size[0] - 1;
    for (c3_i200 = 0; c3_i200 <= c3_nb_loop_ub; c3_i200++) {
      c3_d_tmp_data[c3_i200] = c3_c_QBRP1 * c3_Vc_prime[c3_w_tmp_data[c3_i200] -
        1];
    }

    c3_b_atan(chartInstance, c3_d_tmp_data, c3_d_tmp_size);
    c3_b_cos(chartInstance, c3_d_tmp_data, c3_d_tmp_size);
    c3_pb_trueCount = 0;
    for (c3_sd_i = 0; c3_sd_i < 4; c3_sd_i++) {
      if (c3_isLowSpeed[c3_sd_i]) {
        c3_pb_trueCount++;
      }
    }

    c3_iv11[0] = 1;
    c3_iv11[1] = c3_pb_trueCount;
    emlrtSubAssignSizeCheckR2012b(&c3_iv11[0], 2, &c3_d_tmp_size[0], 1,
      &c3_b_emlrtECI, (void *)c3_sp);
    c3_qb_trueCount = 0;
    for (c3_ud_i = 0; c3_ud_i < 4; c3_ud_i++) {
      if (c3_isLowSpeed[c3_ud_i]) {
        c3_qb_trueCount++;
      }
    }

    c3_y_tmp_size[0] = c3_qb_trueCount;
    c3_bb_partialTrueCount = 0;
    for (c3_vd_i = 0; c3_vd_i < 4; c3_vd_i++) {
      if (c3_isLowSpeed[c3_vd_i]) {
        c3_y_tmp_data[c3_bb_partialTrueCount] = c3_vd_i + 1;
        c3_bb_partialTrueCount++;
      }
    }

    c3_iv12[1] = c3_y_tmp_size[0];
    c3_qb_loop_ub = c3_iv12[1] - 1;
    for (c3_i209 = 0; c3_i209 <= c3_qb_loop_ub; c3_i209++) {
      c3_zeta[6 + 9 * (c3_y_tmp_data[c3_i209] - 1)] = c3_d_tmp_data[c3_i209];
    }

    for (c3_i211 = 0; c3_i211 < 4; c3_i211++) {
      c3_lam_mux[c3_i211] = c3_Fz[c3_i211] / c3_Fzo_prime[c3_i211];
    }

    c3_st.site = &c3_b_emlrtRSI;
    c3_e_sqrt(chartInstance, &c3_st, c3_lam_mux);
    for (c3_i214 = 0; c3_i214 < 4; c3_i214++) {
      c3_lam_mux[c3_i214] = c3_b_QCRP1 * c3_mu_y[c3_i214] * c3_b_UNLOADED_RADIUS
        * c3_Fz[c3_i214] * c3_lam_mux[c3_i214] * c3_lam_Mphi[c3_i214];
    }

    for (c3_xd_i = 0; c3_xd_i < 4; c3_xd_i++) {
      if (c3_lam_mux[c3_xd_i] < 0.0) {
        c3_lam_mux[c3_xd_i] = 1.0E-6;
      }
    }

    for (c3_ke_k = 0; c3_ke_k < 4; c3_ke_k++) {
      c3_me_k = c3_ke_k;
      c3_sc_x = c3_phi_t[c3_me_k];
      c3_hb_y = muDoubleScalarAbs(c3_sc_x);
      c3_lam_muV[c3_me_k] = c3_hb_y;
    }

    c3_c_QCRP2 = c3_b_QCRP2 * c3_b_UNLOADED_RADIUS;
    for (c3_i217 = 0; c3_i217 < 4; c3_i217++) {
      c3_lam_muV[c3_i217] *= c3_c_QCRP2;
    }

    for (c3_oe_k = 0; c3_oe_k < 4; c3_oe_k++) {
      c3_pe_k = c3_oe_k;
      c3_vc_x = c3_lam_muV[c3_pe_k];
      c3_wc_x = c3_vc_x;
      c3_wc_x = muDoubleScalarAtan(c3_wc_x);
      c3_lam_muV[c3_pe_k] = c3_wc_x;
    }

    for (c3_i219 = 0; c3_i219 < 4; c3_i219++) {
      c3_lam_muV[c3_i219] = c3_lam_mux[c3_i219] * 2.0 / 3.1415926535897931 *
        c3_lam_muV[c3_i219] * c3_Vs[c3_i219];
    }

    c3_dv4[0] = c3_b_QDRP1;
    c3_bv[0] = (c3_b_QDRP1 < 0.0);
    for (c3_ce_i = 0; c3_ce_i < 1; c3_ce_i++) {
      if (c3_bv[0]) {
        c3_dv4[c3_ce_i] = 0.0;
      }
    }

    c3_CDrphi = c3_dv4[0];
    c3_dv5[0] = c3_b_QDRP2;
    c3_bv[0] = (c3_b_QDRP2 < 0.0);
    for (c3_ee_i = 0; c3_ee_i < 1; c3_ee_i++) {
      if (c3_bv[0]) {
        c3_dv5[c3_ee_i] = 0.0;
      }
    }

    c3_EDrphi = c3_dv5[0];
    c3_bd_x = 1.5707963267948966 * c3_CDrphi;
    c3_cd_x = c3_bd_x;
    c3_cd_x = muDoubleScalarSin(c3_cd_x);
    for (c3_i225 = 0; c3_i225 < 4; c3_i225++) {
      c3_lam_mux[c3_i225] /= c3_cd_x;
    }

    for (c3_bf_k = 0; c3_bf_k < 4; c3_bf_k++) {
      c3_df_k = c3_bf_k;
      c3_hd_x = c3_gamma[c3_df_k];
      c3_kb_y = muDoubleScalarAbs(c3_hd_x);
      c3_Fz_btm[c3_df_k] = c3_kb_y;
    }

    for (c3_i227 = 0; c3_i227 < 4; c3_i227++) {
      c3_Fz_btm[c3_i227] = c3_Fz[c3_i227] * c3_b_UNLOADED_RADIUS * ((c3_b_QDZ8 +
        c3_b_QDZ9 * c3_dfz[c3_i227]) + (c3_b_QDZ10 + c3_b_QDZ11 * c3_dfz[c3_i227])
        * c3_Fz_btm[c3_i227]) * c3_lam_Kzgamma[c3_i227];
    }

    for (c3_i229 = 0; c3_i229 < 4; c3_i229++) {
      c3_f_x[c3_i229] = 1.0 - c3_epsilon_gamma[c3_i229];
    }

    for (c3_gf_k = 0; c3_gf_k < 4; c3_gf_k++) {
      c3_jf_k = c3_gf_k;
      c3_ld_x = c3_f_x[c3_jf_k];
      c3_nd_x = c3_ld_x;
      c3_nd_x = muDoubleScalarSign(c3_nd_x);
      c3_f_x[c3_jf_k] = c3_nd_x;
    }

    for (c3_i230 = 0; c3_i230 < 4; c3_i230++) {
      c3_Fz_btm[c3_i230] /= c3_CDrphi * c3_lam_mux[c3_i230] * (1.0 -
        c3_epsilon_gamma[c3_i230]) + 0.0001 * c3_f_x[c3_i230];
    }

    c3_d_UNLOADED_RADIUS = -c3_b_UNLOADED_RADIUS;
    for (c3_i232 = 0; c3_i232 < 4; c3_i232++) {
      c3_e_UNLOADED_RADIUS[c3_i232] = c3_d_UNLOADED_RADIUS * c3_Vc_prime[c3_i232];
    }

    c3_magicsin(chartInstance, c3_lam_mux, c3_CDrphi, c3_Fz_btm, c3_EDrphi,
                c3_e_UNLOADED_RADIUS, c3_lam_Cz);
    for (c3_i235 = 0; c3_i235 < 4; c3_i235++) {
      c3_Fz_btm[c3_i235] = c3_lam_Cz[c3_i235];
    }

    for (c3_lf_k = 0; c3_lf_k < 4; c3_lf_k++) {
      c3_mf_k = c3_lf_k;
      c3_pd_x = c3_Fz_btm[c3_mf_k];
      c3_qd_x = c3_pd_x;
      c3_qd_x = muDoubleScalarSign(c3_qd_x);
      c3_Fz_btm[c3_mf_k] = c3_qd_x;
    }

    for (c3_je_i = 0; c3_je_i < 4; c3_je_i++) {
      if (c3_Fz_btm[c3_je_i] == 0.0) {
        c3_Fz_btm[c3_je_i] = 1.0;
      }
    }

    c3_xb_trueCount = 0;
    for (c3_le_i = 0; c3_le_i < 4; c3_le_i++) {
      if (c3_isLowSpeed[c3_le_i]) {
        c3_xb_trueCount++;
      }
    }

    c3_fb_tmp_size[0] = c3_xb_trueCount;
    c3_gb_partialTrueCount = 0;
    for (c3_me_i = 0; c3_me_i < 4; c3_me_i++) {
      if (c3_isLowSpeed[c3_me_i]) {
        c3_db_tmp_data[c3_gb_partialTrueCount] = c3_me_i + 1;
        c3_gb_partialTrueCount++;
      }
    }

    c3_lam_Cz_size[0] = c3_fb_tmp_size[0];
    c3_vb_loop_ub = c3_fb_tmp_size[0] - 1;
    for (c3_i241 = 0; c3_i241 <= c3_vb_loop_ub; c3_i241++) {
      c3_lam_Cz_data[c3_i241] = c3_lam_Cz[c3_db_tmp_data[c3_i241] - 1];
    }

    c3_abs(chartInstance, c3_lam_Cz_data, c3_lam_Cz_size, c3_d_tmp_data,
           c3_d_tmp_size);
    c3_wb_loop_ub = c3_d_tmp_size[0] - 1;
    for (c3_i242 = 0; c3_i242 <= c3_wb_loop_ub; c3_i242++) {
      c3_d_tmp_data[c3_i242] = -c3_d_tmp_data[c3_i242];
    }

    c3_yb_trueCount = 0;
    for (c3_pe_i = 0; c3_pe_i < 4; c3_pe_i++) {
      if (c3_isLowSpeed[c3_pe_i]) {
        c3_yb_trueCount++;
      }
    }

    if ((c3_d_tmp_size[0] != c3_yb_trueCount) && ((c3_d_tmp_size[0] != 1) &&
         (c3_yb_trueCount != 1))) {
      emlrtDimSizeImpxCheckR2021b(c3_d_tmp_size[0], c3_yb_trueCount,
        &c3_c_emlrtECI, (emlrtConstCTX)c3_sp);
    }

    c3_ac_trueCount = 0;
    for (c3_qe_i = 0; c3_qe_i < 4; c3_qe_i++) {
      if (c3_isLowSpeed[c3_qe_i]) {
        c3_ac_trueCount++;
      }
    }

    c3_gb_tmp_size[0] = c3_ac_trueCount;
    c3_hb_partialTrueCount = 0;
    for (c3_re_i = 0; c3_re_i < 4; c3_re_i++) {
      if (c3_isLowSpeed[c3_re_i]) {
        c3_eb_tmp_data[c3_hb_partialTrueCount] = c3_re_i + 1;
        c3_hb_partialTrueCount++;
      }
    }

    c3_st.site = &c3_b_emlrtRSI;
    c3_tmpDrphiVar_size[0] = c3_gb_tmp_size[0];
    c3_xb_loop_ub = c3_gb_tmp_size[0] - 1;
    for (c3_i247 = 0; c3_i247 <= c3_xb_loop_ub; c3_i247++) {
      c3_tmpDrphiVar_data[c3_i247] = c3_lam_muV[c3_eb_tmp_data[c3_i247] - 1];
    }

    if (c3_d_tmp_size[0] == c3_gb_tmp_size[0]) {
      c3_y_size[0] = c3_d_tmp_size[0];
      c3_yb_loop_ub = c3_d_tmp_size[0] - 1;
      for (c3_i249 = 0; c3_i249 <= c3_yb_loop_ub; c3_i249++) {
        c3_y_data[c3_i249] = c3_d_tmp_data[c3_i249] + 0.0001 *
          c3_Fz_btm[c3_eb_tmp_data[c3_i249] - 1];
      }
    } else {
      c3_e_binary_expand_op(chartInstance, c3_y_data, c3_y_size, c3_d_tmp_data,
                            c3_d_tmp_size, c3_Fz_btm, c3_eb_tmp_data,
                            c3_gb_tmp_size);
    }

    c3_b_st.site = &c3_d_emlrtRSI;
    c3_c_st.site = &c3_e_emlrtRSI;
    c3_b_assertCompatibleDims(chartInstance, &c3_c_st, c3_tmpDrphiVar_size,
      c3_y_size);
    if (c3_tmpDrphiVar_size[0] == c3_y_size[0]) {
      c3_ac_loop_ub = c3_tmpDrphiVar_size[0] - 1;
      for (c3_i251 = 0; c3_i251 <= c3_ac_loop_ub; c3_i251++) {
        c3_tmpDrphiVar_data[c3_i251] /= c3_y_data[c3_i251];
      }
    } else {
      c3_rdivide(chartInstance, c3_tmpDrphiVar_data, c3_tmpDrphiVar_size,
                 c3_y_data, c3_y_size);
    }

    c3_end = c3_tmpDrphiVar_size[0] - 1;
    for (c3_te_i = 0; c3_te_i <= c3_end; c3_te_i++) {
      if (c3_tmpDrphiVar_data[c3_te_i] > 1.0) {
        c3_i255 = c3_te_i + 1;
        if ((c3_i255 < 1) || (c3_i255 > c3_tmpDrphiVar_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c3_i255, 1, c3_tmpDrphiVar_size[0],
            &c3_emlrtBCI, (emlrtConstCTX)c3_sp);
        }

        c3_tmpDrphiVar_data[c3_i255 - 1] = 1.0;
      }
    }

    c3_b_end = c3_tmpDrphiVar_size[0] - 1;
    for (c3_ue_i = 0; c3_ue_i <= c3_b_end; c3_ue_i++) {
      if (c3_tmpDrphiVar_data[c3_ue_i] < -1.0) {
        c3_i258 = c3_ue_i + 1;
        if ((c3_i258 < 1) || (c3_i258 > c3_tmpDrphiVar_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c3_i258, 1, c3_tmpDrphiVar_size[0],
            &c3_emlrtBCI, (emlrtConstCTX)c3_sp);
        }

        c3_tmpDrphiVar_data[c3_i258 - 1] = -1.0;
      }
    }

    c3_st.site = &c3_b_emlrtRSI;
    c3_b_acos(chartInstance, &c3_st, c3_tmpDrphiVar_data, c3_tmpDrphiVar_size);
    c3_bc_loop_ub = c3_tmpDrphiVar_size[0] - 1;
    for (c3_i260 = 0; c3_i260 <= c3_bc_loop_ub; c3_i260++) {
      c3_tmpDrphiVar_data[c3_i260] *= 0.63661977236758138;
    }

    c3_bc_trueCount = 0;
    for (c3_ve_i = 0; c3_ve_i < 4; c3_ve_i++) {
      if (c3_isLowSpeed[c3_ve_i]) {
        c3_bc_trueCount++;
      }
    }

    c3_iv13[0] = 1;
    c3_iv13[1] = c3_bc_trueCount;
    emlrtSubAssignSizeCheckR2012b(&c3_iv13[0], 2, &c3_tmpDrphiVar_size[0], 1,
      &c3_b_emlrtECI, (void *)c3_sp);
    c3_cc_trueCount = 0;
    for (c3_we_i = 0; c3_we_i < 4; c3_we_i++) {
      if (c3_isLowSpeed[c3_we_i]) {
        c3_cc_trueCount++;
      }
    }

    c3_hb_tmp_size[0] = c3_cc_trueCount;
    c3_ib_partialTrueCount = 0;
    for (c3_xe_i = 0; c3_xe_i < 4; c3_xe_i++) {
      if (c3_isLowSpeed[c3_xe_i]) {
        c3_fb_tmp_data[c3_ib_partialTrueCount] = c3_xe_i + 1;
        c3_ib_partialTrueCount++;
      }
    }

    c3_iv14[1] = c3_hb_tmp_size[0];
    c3_cc_loop_ub = c3_iv14[1] - 1;
    for (c3_i264 = 0; c3_i264 <= c3_cc_loop_ub; c3_i264++) {
      c3_zeta[7 + 9 * (c3_fb_tmp_data[c3_i264] - 1)] =
        c3_tmpDrphiVar_data[c3_i264];
    }

    c3_dc_trueCount = 0;
    for (c3_ye_i = 0; c3_ye_i < 4; c3_ye_i++) {
      if (c3_isLowSpeed[c3_ye_i]) {
        c3_dc_trueCount++;
      }
    }

    c3_iv15[0] = 1;
    c3_iv15[1] = c3_dc_trueCount;
    c3_ec_trueCount[0] = c3_dc_trueCount;
    emlrtSubAssignSizeCheckR2012b(&c3_iv15[0], 2, &c3_ec_trueCount[0], 1,
      &c3_b_emlrtECI, (void *)c3_sp);
    c3_fc_trueCount = 0;
    for (c3_af_i = 0; c3_af_i < 4; c3_af_i++) {
      if (c3_isLowSpeed[c3_af_i]) {
        c3_fc_trueCount++;
      }
    }

    c3_ib_tmp_size[0] = c3_fc_trueCount;
    c3_jb_partialTrueCount = 0;
    for (c3_bf_i = 0; c3_bf_i < 4; c3_bf_i++) {
      if (c3_isLowSpeed[c3_bf_i]) {
        c3_gb_tmp_data[c3_jb_partialTrueCount] = c3_bf_i + 1;
        c3_jb_partialTrueCount++;
      }
    }

    c3_iv16[1] = c3_ib_tmp_size[0];
    c3_dc_loop_ub = c3_iv16[1] - 1;
    for (c3_i269 = 0; c3_i269 <= c3_dc_loop_ub; c3_i269++) {
      c3_zeta[8 + 9 * (c3_gb_tmp_data[c3_i269] - 1)] =
        c3_lam_Cz[c3_gb_tmp_data[c3_i269] - 1] + 1.0;
    }

    c3_gc_trueCount = 0;
    for (c3_cf_i = 0; c3_cf_i < 4; c3_cf_i++) {
      if (c3_isLowSpeed[c3_cf_i]) {
        c3_gc_trueCount++;
      }
    }

    c3_jb_tmp_size[0] = c3_gc_trueCount;
    c3_kb_partialTrueCount = 0;
    for (c3_df_i = 0; c3_df_i < 4; c3_df_i++) {
      if (c3_isLowSpeed[c3_df_i]) {
        c3_hb_tmp_data[c3_kb_partialTrueCount] = (c3_b_PHY1 + c3_b_PHY2 *
          c3_dfz[c3_df_i]) * c3_lam_Hy[c3_df_i];
        c3_kb_partialTrueCount++;
      }
    }

    c3_hc_trueCount = 0;
    for (c3_ef_i = 0; c3_ef_i < 4; c3_ef_i++) {
      if (c3_isLowSpeed[c3_ef_i]) {
        c3_hc_trueCount++;
      }
    }

    if ((c3_jb_tmp_size[0] != c3_hc_trueCount) && ((c3_jb_tmp_size[0] != 1) &&
         (c3_hc_trueCount != 1))) {
      emlrtDimSizeImpxCheckR2021b(c3_jb_tmp_size[0], c3_hc_trueCount,
        &c3_c_emlrtECI, (emlrtConstCTX)c3_sp);
    }

    c3_ic_trueCount = 0;
    for (c3_ff_i = 0; c3_ff_i < 4; c3_ff_i++) {
      if (c3_isLowSpeed[c3_ff_i]) {
        c3_ic_trueCount++;
      }
    }

    c3_kb_tmp_size[0] = c3_ic_trueCount;
    c3_lb_partialTrueCount = 0;
    for (c3_gf_i = 0; c3_gf_i < 4; c3_gf_i++) {
      if (c3_isLowSpeed[c3_gf_i]) {
        c3_ib_tmp_data[c3_lb_partialTrueCount] = c3_gf_i + 1;
        c3_lb_partialTrueCount++;
      }
    }

    if (c3_jb_tmp_size[0] == c3_kb_tmp_size[0]) {
      c3_d_tmp_size[0] = c3_jb_tmp_size[0];
      c3_ec_loop_ub = c3_jb_tmp_size[0] - 1;
      for (c3_i278 = 0; c3_i278 <= c3_ec_loop_ub; c3_i278++) {
        c3_d_tmp_data[c3_i278] = c3_hb_tmp_data[c3_i278] +
          c3_SHyphi[c3_ib_tmp_data[c3_i278] - 1];
      }
    } else {
      c3_d_binary_expand_op(chartInstance, c3_d_tmp_data, c3_d_tmp_size,
                            c3_hb_tmp_data, c3_jb_tmp_size, c3_SHyphi,
                            c3_ib_tmp_data, c3_kb_tmp_size);
    }

    c3_jc_trueCount = 0;
    for (c3_hf_i = 0; c3_hf_i < 4; c3_hf_i++) {
      if (c3_isLowSpeed[c3_hf_i]) {
        c3_jc_trueCount++;
      }
    }

    c3_lb_tmp_size[0] = c3_jc_trueCount;
    c3_mb_partialTrueCount = 0;
    for (c3_if_i = 0; c3_if_i < 4; c3_if_i++) {
      if (c3_isLowSpeed[c3_if_i]) {
        c3_jb_tmp_data[c3_mb_partialTrueCount] = c3_if_i + 1;
        c3_mb_partialTrueCount++;
      }
    }

    c3_st.site = &c3_b_emlrtRSI;
    c3_tmpDrphiVar_size[0] = c3_lb_tmp_size[0];
    c3_fc_loop_ub = c3_lb_tmp_size[0] - 1;
    for (c3_i282 = 0; c3_i282 <= c3_fc_loop_ub; c3_i282++) {
      c3_tmpDrphiVar_data[c3_i282] = c3_SVygamma[c3_jb_tmp_data[c3_i282] - 1];
    }

    c3_y_size[0] = c3_lb_tmp_size[0];
    c3_gc_loop_ub = c3_lb_tmp_size[0] - 1;
    for (c3_i284 = 0; c3_i284 <= c3_gc_loop_ub; c3_i284++) {
      c3_y_data[c3_i284] = c3_Kyalpha_prime[c3_jb_tmp_data[c3_i284] - 1];
    }

    c3_b_st.site = &c3_d_emlrtRSI;
    c3_c_st.site = &c3_e_emlrtRSI;
    c3_c_assertCompatibleDims(chartInstance, &c3_c_st, c3_tmpDrphiVar_size,
      c3_y_size);
    c3_hc_loop_ub = c3_tmpDrphiVar_size[0] - 1;
    for (c3_i286 = 0; c3_i286 <= c3_hc_loop_ub; c3_i286++) {
      c3_tmpDrphiVar_data[c3_i286] /= c3_y_data[c3_i286];
    }

    if ((c3_d_tmp_size[0] != c3_tmpDrphiVar_size[0]) && ((c3_d_tmp_size[0] != 1)
         && (c3_tmpDrphiVar_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(c3_d_tmp_size[0], c3_tmpDrphiVar_size[0],
        &c3_c_emlrtECI, (emlrtConstCTX)c3_sp);
    }

    if (c3_d_tmp_size[0] == c3_tmpDrphiVar_size[0]) {
      c3_ic_loop_ub = c3_d_tmp_size[0] - 1;
      for (c3_i287 = 0; c3_i287 <= c3_ic_loop_ub; c3_i287++) {
        c3_d_tmp_data[c3_i287] -= c3_tmpDrphiVar_data[c3_i287];
      }
    } else {
      c3_minus(chartInstance, c3_d_tmp_data, c3_d_tmp_size, c3_tmpDrphiVar_data,
               c3_tmpDrphiVar_size);
    }

    c3_kc_trueCount = 0;
    for (c3_jf_i = 0; c3_jf_i < 4; c3_jf_i++) {
      if (c3_isLowSpeed[c3_jf_i]) {
        c3_kc_trueCount++;
      }
    }

    if (c3_kc_trueCount != c3_d_tmp_size[0]) {
      emlrtSubAssignSizeCheck1dR2017a(c3_kc_trueCount, c3_d_tmp_size[0],
        &c3_b_emlrtECI, (emlrtConstCTX)c3_sp);
    }

    c3_nb_partialTrueCount = 0;
    for (c3_kf_i = 0; c3_kf_i < 4; c3_kf_i++) {
      if (c3_isLowSpeed[c3_kf_i]) {
        c3_SHy[c3_kf_i] = c3_d_tmp_data[c3_nb_partialTrueCount];
        c3_nb_partialTrueCount++;
      }
    }
  }

  for (c3_i156 = 0; c3_i156 < 4; c3_i156++) {
    c3_Vsy[c3_i156] = c3_b_PCX1 * c3_lam_Cx[c3_i156];
  }

  for (c3_fc_i = 0; c3_fc_i < 4; c3_fc_i++) {
    if (c3_b_PCX1 * c3_lam_Cx[c3_fc_i] < 0.0) {
      c3_Vsy[c3_fc_i] = 0.0;
    }
  }

  c3_i158 = 0;
  for (c3_i159 = 0; c3_i159 < 4; c3_i159++) {
    c3_mu_x[c3_i159] = c3_mu_x[c3_i159] * c3_Fz[c3_i159] * c3_zeta[c3_i158 + 1];
    c3_i158 += 9;
  }

  for (c3_hc_i = 0; c3_hc_i < 4; c3_hc_i++) {
    if (c3_mu_x[c3_hc_i] < 0.0) {
      c3_mu_x[c3_hc_i] = 0.0;
    }
  }

  for (c3_jd_k = 0; c3_jd_k < 4; c3_jd_k++) {
    c3_kd_k = c3_jd_k;
    c3_w_a = c3_dfz[c3_kd_k];
    c3_cb_y = c3_w_a * c3_w_a;
    c3_SHyphi[c3_kd_k] = c3_cb_y;
  }

  for (c3_i162 = 0; c3_i162 < 4; c3_i162++) {
    c3_f_x[c3_i162] = 10.0 * c3_lam_Hx[c3_i162];
  }

  for (c3_ld_k = 0; c3_ld_k < 4; c3_ld_k++) {
    c3_md_k = c3_ld_k;
    c3_ac_x = c3_f_x[c3_md_k];
    c3_bc_x = c3_ac_x;
    c3_bc_x = muDoubleScalarTanh(c3_bc_x);
    c3_f_x[c3_md_k] = c3_bc_x;
  }

  for (c3_i165 = 0; c3_i165 < 4; c3_i165++) {
    c3_SHyphi[c3_i165] = ((c3_b_PEX1 + c3_b_PEX2 * c3_dfz[c3_i165]) + c3_b_PEX3 *
                          c3_SHyphi[c3_i165]) * (1.0 - c3_b_PEX4 *
      c3_f_x[c3_i165]) * c3_lam_Ex[c3_i165];
  }

  for (c3_jc_i = 0; c3_jc_i < 4; c3_jc_i++) {
    if (c3_SHyphi[c3_jc_i] > 1.0) {
      c3_SHyphi[c3_jc_i] = 1.0;
    }
  }

  for (c3_i166 = 0; c3_i166 < 4; c3_i166++) {
    c3_phi_t[c3_i166] = c3_b_PKX3 * c3_dfz[c3_i166];
  }

  for (c3_nd_k = 0; c3_nd_k < 4; c3_nd_k++) {
    c3_pd_k = c3_nd_k;
    c3_cc_x = c3_phi_t[c3_pd_k];
    c3_dc_x = c3_cc_x;
    c3_dc_x = muDoubleScalarExp(c3_dc_x);
    c3_phi_t[c3_pd_k] = c3_dc_x;
  }

  for (c3_od_k = 0; c3_od_k < 4; c3_od_k++) {
    c3_qd_k = c3_od_k;
    c3_x_a = c3_dpi[c3_qd_k];
    c3_db_y = c3_x_a * c3_x_a;
    c3_e_y[c3_qd_k] = c3_db_y;
  }

  for (c3_i168 = 0; c3_i168 < 4; c3_i168++) {
    c3_phi_t[c3_i168] = c3_Fz[c3_i168] * (c3_b_PKX1 + c3_b_PKX2 * c3_dfz[c3_i168])
      * c3_phi_t[c3_i168] * ((c3_b_PPX1 * c3_dpi[c3_i168] + 1.0) + c3_b_PPX2 *
      c3_e_y[c3_i168]) * c3_lam_Kxkappa[c3_i168];
  }

  for (c3_i169 = 0; c3_i169 < 4; c3_i169++) {
    c3_b_Vsy[c3_i169] = c3_Vsy[c3_i169] * c3_mu_x[c3_i169];
  }

  c3_st.site = &c3_b_emlrtRSI;
  c3_div0protect(chartInstance, &c3_st, c3_b_Vsy, 0.0001, c3_lam_Cz, c3_Fz_btm);
  for (c3_i171 = 0; c3_i171 < 4; c3_i171++) {
    c3_lam_Cz[c3_i171] = c3_phi_t[c3_i171] / c3_lam_Cz[c3_i171];
  }

  c3_i172 = 0;
  for (c3_i173 = 0; c3_i173 < 4; c3_i173++) {
    c3_lam_mux_prime[c3_i173] = c3_Fz[c3_i173] * (c3_b_PVX1 + c3_b_PVX2 *
      c3_dfz[c3_i173]) * c3_lam_mux_prime[c3_i173] * c3_lam_Vx[c3_i173] *
      c3_zeta[c3_i172 + 1];
    c3_i172 += 9;
  }

  c3_b_magicsin(chartInstance, c3_mu_x, c3_Vsy, c3_lam_Cz, c3_SHyphi, c3_lam_Hx,
                c3_b_Fx);
  for (c3_i175 = 0; c3_i175 < 4; c3_i175++) {
    c3_b_Fx[c3_i175] += c3_lam_mux_prime[c3_i175];
  }

  for (c3_i176 = 0; c3_i176 < 4; c3_i176++) {
    c3_lam_mux[c3_i176] = c3_b_REX1 + c3_b_REX2 * c3_dfz[c3_i176];
  }

  for (c3_sc_i = 0; c3_sc_i < 4; c3_sc_i++) {
    if (c3_b_REX1 + c3_b_REX2 * c3_dfz[c3_sc_i] > 1.0) {
      c3_lam_mux[c3_sc_i] = 1.0;
    }
  }

  for (c3_rd_k = 0; c3_rd_k < 4; c3_rd_k++) {
    c3_sd_k = c3_rd_k;
    c3_y_a = c3_gamma_star[c3_sd_k];
    c3_eb_y = c3_y_a * c3_y_a;
    c3_lam_muV[c3_sd_k] = c3_eb_y;
  }

  for (c3_i177 = 0; c3_i177 < 4; c3_i177++) {
    c3_f_x[c3_i177] = c3_b_RBX2 * c3_kappa[c3_i177];
  }

  for (c3_td_k = 0; c3_td_k < 4; c3_td_k++) {
    c3_vd_k = c3_td_k;
    c3_ec_x = c3_f_x[c3_vd_k];
    c3_fc_x = c3_ec_x;
    c3_fc_x = muDoubleScalarAtan(c3_fc_x);
    c3_f_x[c3_vd_k] = c3_fc_x;
  }

  for (c3_ud_k = 0; c3_ud_k < 4; c3_ud_k++) {
    c3_wd_k = c3_ud_k;
    c3_gc_x = c3_f_x[c3_wd_k];
    c3_hc_x = c3_gc_x;
    c3_hc_x = muDoubleScalarCos(c3_hc_x);
    c3_f_x[c3_wd_k] = c3_hc_x;
  }

  for (c3_i179 = 0; c3_i179 < 4; c3_i179++) {
    c3_lam_muV[c3_i179] = (c3_b_RBX1 + c3_b_RBX3 * c3_lam_muV[c3_i179]) *
      c3_f_x[c3_i179] * c3_lam_xalpha[c3_i179];
  }

  for (c3_xc_i = 0; c3_xc_i < 4; c3_xc_i++) {
    if (c3_lam_muV[c3_xc_i] < 0.0) {
      c3_lam_muV[c3_xc_i] = 0.0;
    }
  }

  for (c3_i181 = 0; c3_i181 < 4; c3_i181++) {
    c3_Fz_btm[c3_i181] = c3_alpha[c3_i181] + c3_b_RHX1;
  }

  c3_magiccos(chartInstance, c3_b_RCX1, c3_lam_muV, c3_lam_mux, c3_Fz_btm,
              c3_lam_Cz);
  c3_b_magiccos(chartInstance, c3_b_RCX1, c3_lam_muV, c3_lam_mux, c3_b_RHX1,
                c3_Fz_btm);
  for (c3_i182 = 0; c3_i182 < 4; c3_i182++) {
    c3_lam_Cz[c3_i182] /= c3_Fz_btm[c3_i182];
  }

  for (c3_cd_i = 0; c3_cd_i < 4; c3_cd_i++) {
    if (c3_lam_Cz[c3_cd_i] < 0.0) {
      c3_lam_Cz[c3_cd_i] = 0.0;
    }
  }

  for (c3_i183 = 0; c3_i183 < 4; c3_i183++) {
    c3_b_Fx[c3_i183] *= c3_lam_Cz[c3_i183];
  }

  for (c3_i186 = 0; c3_i186 < 4; c3_i186++) {
    c3_Bykappa[c3_i186] = c3_b_PCY1 * c3_lam_Cy[c3_i186];
  }

  for (c3_dd_i = 0; c3_dd_i < 4; c3_dd_i++) {
    if (c3_b_PCY1 * c3_lam_Cy[c3_dd_i] < 0.0) {
      c3_Bykappa[c3_dd_i] = 0.0;
    }
  }

  c3_i187 = 0;
  for (c3_i188 = 0; c3_i188 < 4; c3_i188++) {
    c3_lam_Cz[c3_i188] = c3_mu_y[c3_i188] * c3_Fz[c3_i188] * c3_zeta[c3_i187 + 2];
    c3_i187 += 9;
  }

  for (c3_i190 = 0; c3_i190 < 4; c3_i190++) {
    c3_b_Bykappa[c3_i190] = c3_Bykappa[c3_i190] * c3_lam_Cz[c3_i190];
  }

  c3_st.site = &c3_b_emlrtRSI;
  c3_div0protect(chartInstance, &c3_st, c3_b_Bykappa, 0.0001, c3_lam_ykappa,
                 c3_Fz_btm);
  for (c3_i191 = 0; c3_i191 < 4; c3_i191++) {
    c3_lam_ykappa[c3_i191] = c3_Kyalpha[c3_i191] / c3_lam_ykappa[c3_i191];
  }

  for (c3_i192 = 0; c3_i192 < 4; c3_i192++) {
    c3_b_isLowSpeed[c3_i192] = !c3_isLowSpeed[c3_i192];
  }

  if (c3_any(chartInstance, c3_b_isLowSpeed)) {
    c3_lb_trueCount = 0;
    for (c3_jd_i = 0; c3_jd_i < 4; c3_jd_i++) {
      if (!c3_isLowSpeed[c3_jd_i]) {
        c3_lb_trueCount++;
      }
    }

    c3_v_tmp_size[0] = c3_lb_trueCount;
    c3_x_partialTrueCount = 0;
    for (c3_md_i = 0; c3_md_i < 4; c3_md_i++) {
      if (!c3_isLowSpeed[c3_md_i]) {
        c3_v_tmp_data[c3_x_partialTrueCount] = c3_md_i + 1;
        c3_x_partialTrueCount++;
      }
    }

    c3_d_tmp_size[0] = c3_v_tmp_size[0];
    c3_mb_loop_ub = c3_v_tmp_size[0] - 1;
    for (c3_i199 = 0; c3_i199 <= c3_mb_loop_ub; c3_i199++) {
      c3_d_tmp_data[c3_i199] = c3_Fz[c3_v_tmp_data[c3_i199] - 1] * (c3_b_PKY6 +
        c3_b_PKY7 * c3_dfz[c3_v_tmp_data[c3_i199] - 1]) * (c3_b_PPY5 *
        c3_dpi[c3_v_tmp_data[c3_i199] - 1] + 1.0) *
        c3_lam_Kygamma[c3_v_tmp_data[c3_i199] - 1] *
        c3_gamma_star[c3_v_tmp_data[c3_i199] - 1];
    }

    c3_nb_trueCount = 0;
    for (c3_pd_i = 0; c3_pd_i < 4; c3_pd_i++) {
      if (!c3_isLowSpeed[c3_pd_i]) {
        c3_nb_trueCount++;
      }
    }

    if ((c3_d_tmp_size[0] != c3_nb_trueCount) && ((c3_d_tmp_size[0] != 1) &&
         (c3_nb_trueCount != 1))) {
      emlrtDimSizeImpxCheckR2021b(c3_d_tmp_size[0], c3_nb_trueCount,
        &c3_c_emlrtECI, (emlrtConstCTX)c3_sp);
    }

    c3_ob_trueCount = 0;
    for (c3_rd_i = 0; c3_rd_i < 4; c3_rd_i++) {
      if (!c3_isLowSpeed[c3_rd_i]) {
        c3_ob_trueCount++;
      }
    }

    c3_x_tmp_size[0] = c3_ob_trueCount;
    c3_ab_partialTrueCount = 0;
    for (c3_td_i = 0; c3_td_i < 4; c3_td_i++) {
      if (!c3_isLowSpeed[c3_td_i]) {
        c3_x_tmp_data[c3_ab_partialTrueCount] = c3_td_i + 1;
        c3_ab_partialTrueCount++;
      }
    }

    c3_st.site = &c3_b_emlrtRSI;
    if (c3_d_tmp_size[0] == c3_x_tmp_size[0]) {
      c3_tmpDrphiVar_size[0] = c3_d_tmp_size[0];
      c3_ob_loop_ub = c3_d_tmp_size[0] - 1;
      for (c3_i205 = 0; c3_i205 <= c3_ob_loop_ub; c3_i205++) {
        c3_tmpDrphiVar_data[c3_i205] = c3_d_tmp_data[c3_i205] -
          c3_SVygamma[c3_x_tmp_data[c3_i205] - 1];
      }
    } else {
      c3_c_binary_expand_op(chartInstance, c3_tmpDrphiVar_data,
                            c3_tmpDrphiVar_size, c3_d_tmp_data, c3_d_tmp_size,
                            c3_SVygamma, c3_x_tmp_data, c3_x_tmp_size);
    }

    c3_y_size[0] = c3_x_tmp_size[0];
    c3_pb_loop_ub = c3_x_tmp_size[0] - 1;
    for (c3_i207 = 0; c3_i207 <= c3_pb_loop_ub; c3_i207++) {
      c3_y_data[c3_i207] = c3_Kyalpha_prime[c3_x_tmp_data[c3_i207] - 1];
    }

    c3_b_st.site = &c3_d_emlrtRSI;
    c3_c_st.site = &c3_e_emlrtRSI;
    c3_b_assertCompatibleDims(chartInstance, &c3_c_st, c3_tmpDrphiVar_size,
      c3_y_size);
    if (c3_tmpDrphiVar_size[0] == c3_y_size[0]) {
      c3_rb_loop_ub = c3_tmpDrphiVar_size[0] - 1;
      for (c3_i212 = 0; c3_i212 <= c3_rb_loop_ub; c3_i212++) {
        c3_tmpDrphiVar_data[c3_i212] /= c3_y_data[c3_i212];
      }
    } else {
      c3_rdivide(chartInstance, c3_tmpDrphiVar_data, c3_tmpDrphiVar_size,
                 c3_y_data, c3_y_size);
    }

    c3_rb_trueCount = 0;
    for (c3_wd_i = 0; c3_wd_i < 4; c3_wd_i++) {
      if (!c3_isLowSpeed[c3_wd_i]) {
        c3_rb_trueCount++;
      }
    }

    c3_ab_tmp_size[0] = c3_rb_trueCount;
    if ((c3_tmpDrphiVar_size[0] != c3_ab_tmp_size[0]) && ((c3_tmpDrphiVar_size[0]
          != 1) && (c3_ab_tmp_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(c3_tmpDrphiVar_size[0], c3_ab_tmp_size[0],
        &c3_c_emlrtECI, (emlrtConstCTX)c3_sp);
    }

    c3_sb_trueCount = 0;
    for (c3_yd_i = 0; c3_yd_i < 4; c3_yd_i++) {
      if (!c3_isLowSpeed[c3_yd_i]) {
        c3_sb_trueCount++;
      }
    }

    c3_bb_tmp_size[0] = c3_sb_trueCount;
    c3_cb_partialTrueCount = 0;
    for (c3_ae_i = 0; c3_ae_i < 4; c3_ae_i++) {
      if (!c3_isLowSpeed[c3_ae_i]) {
        c3_ab_tmp_data[c3_cb_partialTrueCount] = (c3_b_PHY1 + c3_b_PHY2 *
          c3_dfz[c3_ae_i]) * c3_lam_Hy[c3_ae_i];
        c3_cb_partialTrueCount++;
      }
    }

    c3_tb_trueCount = 0;
    for (c3_be_i = 0; c3_be_i < 4; c3_be_i++) {
      if (!c3_isLowSpeed[c3_be_i]) {
        c3_tb_trueCount++;
      }
    }

    c3_cb_tmp_size[0] = c3_tb_trueCount;
    c3_db_partialTrueCount = 0;
    for (c3_de_i = 0; c3_de_i < 4; c3_de_i++) {
      if (!c3_isLowSpeed[c3_de_i]) {
        c3_bb_tmp_data[c3_db_partialTrueCount] = c3_de_i + 1;
        c3_db_partialTrueCount++;
      }
    }

    if (c3_tmpDrphiVar_size[0] == c3_cb_tmp_size[0]) {
      c3_d_tmp_size[0] = c3_tmpDrphiVar_size[0];
      c3_sb_loop_ub = c3_tmpDrphiVar_size[0] - 1;
      for (c3_i222 = 0; c3_i222 <= c3_sb_loop_ub; c3_i222++) {
        c3_d_tmp_data[c3_i222] = c3_tmpDrphiVar_data[c3_i222] * c3_zeta[9 *
          (c3_bb_tmp_data[c3_i222] - 1)];
      }
    } else {
      c3_b_binary_expand_op(chartInstance, c3_d_tmp_data, c3_d_tmp_size,
                            c3_tmpDrphiVar_data, c3_tmpDrphiVar_size, c3_zeta,
                            c3_bb_tmp_data, c3_cb_tmp_size);
    }

    if ((c3_bb_tmp_size[0] != c3_d_tmp_size[0]) && ((c3_bb_tmp_size[0] != 1) &&
         (c3_d_tmp_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(c3_bb_tmp_size[0], c3_d_tmp_size[0],
        &c3_c_emlrtECI, (emlrtConstCTX)c3_sp);
    }

    if (c3_bb_tmp_size[0] == c3_d_tmp_size[0]) {
      c3_tb_loop_ub = c3_bb_tmp_size[0] - 1;
      for (c3_i224 = 0; c3_i224 <= c3_tb_loop_ub; c3_i224++) {
        c3_ab_tmp_data[c3_i224] += c3_d_tmp_data[c3_i224];
      }
    } else {
      c3_plus(chartInstance, c3_ab_tmp_data, c3_bb_tmp_size, c3_d_tmp_data,
              c3_d_tmp_size);
    }

    c3_ub_trueCount = 0;
    for (c3_fe_i = 0; c3_fe_i < 4; c3_fe_i++) {
      if (!c3_isLowSpeed[c3_fe_i]) {
        c3_ub_trueCount++;
      }
    }

    c3_db_tmp_size[0] = c3_ub_trueCount;
    if ((c3_bb_tmp_size[0] != c3_db_tmp_size[0]) && ((c3_bb_tmp_size[0] != 1) &&
         (c3_db_tmp_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(c3_bb_tmp_size[0], c3_db_tmp_size[0],
        &c3_c_emlrtECI, (emlrtConstCTX)c3_sp);
    }

    c3_vb_trueCount = 0;
    for (c3_ge_i = 0; c3_ge_i < 4; c3_ge_i++) {
      if (!c3_isLowSpeed[c3_ge_i]) {
        c3_vb_trueCount++;
      }
    }

    c3_eb_tmp_size[0] = c3_vb_trueCount;
    c3_eb_partialTrueCount = 0;
    for (c3_he_i = 0; c3_he_i < 4; c3_he_i++) {
      if (!c3_isLowSpeed[c3_he_i]) {
        c3_cb_tmp_data[c3_eb_partialTrueCount] = c3_he_i + 1;
        c3_eb_partialTrueCount++;
      }
    }

    if (c3_bb_tmp_size[0] == c3_eb_tmp_size[0]) {
      c3_d_tmp_size[0] = c3_bb_tmp_size[0];
      c3_ub_loop_ub = c3_bb_tmp_size[0] - 1;
      for (c3_i236 = 0; c3_i236 <= c3_ub_loop_ub; c3_i236++) {
        c3_d_tmp_data[c3_i236] = c3_ab_tmp_data[c3_i236] + c3_zeta[4 + 9 *
          (c3_cb_tmp_data[c3_i236] - 1)];
      }
    } else {
      c3_binary_expand_op(chartInstance, c3_d_tmp_data, c3_d_tmp_size,
                          c3_ab_tmp_data, c3_bb_tmp_size, c3_zeta,
                          c3_cb_tmp_data, c3_eb_tmp_size);
    }

    c3_wb_trueCount = 0;
    for (c3_ie_i = 0; c3_ie_i < 4; c3_ie_i++) {
      if (!c3_isLowSpeed[c3_ie_i]) {
        c3_wb_trueCount++;
      }
    }

    if (c3_wb_trueCount != c3_d_tmp_size[0]) {
      emlrtSubAssignSizeCheck1dR2017a(c3_wb_trueCount, c3_d_tmp_size[0],
        &c3_b_emlrtECI, (emlrtConstCTX)c3_sp);
    }

    c3_fb_partialTrueCount = 0;
    for (c3_ke_i = 0; c3_ke_i < 4; c3_ke_i++) {
      if (!c3_isLowSpeed[c3_ke_i]) {
        c3_SHy[c3_ke_i] = c3_d_tmp_data[c3_fb_partialTrueCount] - 1.0;
        c3_fb_partialTrueCount++;
      }
    }
  }

  c3_i193 = 0;
  for (c3_i195 = 0; c3_i195 < 4; c3_i195++) {
    c3_lam_Vy[c3_i195] = c3_Fz[c3_i195] * (c3_b_PVY1 + c3_b_PVY2 *
      c3_dfz[c3_i195]) * c3_lam_Vy[c3_i195] * c3_lam_muy_prime[c3_i195] *
      c3_zeta[c3_i193 + 2] + c3_SVygamma[c3_i195];
    c3_i193 += 9;
  }

  for (c3_i196 = 0; c3_i196 < 4; c3_i196++) {
    c3_lam_mux[c3_i196] = c3_alpha[c3_i196] + c3_SHy[c3_i196];
  }

  for (c3_i197 = 0; c3_i197 < 4; c3_i197++) {
    c3_Fz_btm[c3_i197] = c3_lam_mux[c3_i197];
  }

  for (c3_xd_k = 0; c3_xd_k < 4; c3_xd_k++) {
    c3_yd_k = c3_xd_k;
    c3_ic_x = c3_Fz_btm[c3_yd_k];
    c3_jc_x = c3_ic_x;
    c3_jc_x = muDoubleScalarSign(c3_jc_x);
    c3_Fz_btm[c3_yd_k] = c3_jc_x;
  }

  for (c3_od_i = 0; c3_od_i < 4; c3_od_i++) {
    if (c3_Fz_btm[c3_od_i] == 0.0) {
      c3_Fz_btm[c3_od_i] = 1.0;
    }
  }

  for (c3_ae_k = 0; c3_ae_k < 4; c3_ae_k++) {
    c3_be_k = c3_ae_k;
    c3_eb_a = c3_gamma_star[c3_be_k];
    c3_gb_y = c3_eb_a * c3_eb_a;
    c3_lam_muV[c3_be_k] = c3_gb_y;
  }

  for (c3_i201 = 0; c3_i201 < 4; c3_i201++) {
    c3_lam_muV[c3_i201] = (c3_b_PEY1 + c3_b_PEY2 * c3_dfz[c3_i201]) * ((1.0 +
      c3_b_PEY5 * c3_lam_muV[c3_i201]) - (c3_b_PEY3 + c3_b_PEY4 *
      c3_gamma_star[c3_i201]) * c3_Fz_btm[c3_i201]) * c3_lam_Ey[c3_i201];
  }

  for (c3_qd_i = 0; c3_qd_i < 4; c3_qd_i++) {
    if (c3_lam_muV[c3_qd_i] > 1.0) {
      c3_lam_muV[c3_qd_i] = 1.0;
    }
  }

  c3_b_magicsin(chartInstance, c3_lam_Cz, c3_Bykappa, c3_lam_ykappa, c3_lam_muV,
                c3_lam_mux, c3_b_Fy);
  for (c3_i202 = 0; c3_i202 < 4; c3_i202++) {
    c3_b_Fy[c3_i202] += c3_lam_Vy[c3_i202];
  }

  for (c3_i203 = 0; c3_i203 < 4; c3_i203++) {
    c3_f_x[c3_i203] = c3_b_RVY4 * c3_alpha[c3_i203];
  }

  for (c3_ce_k = 0; c3_ce_k < 4; c3_ce_k++) {
    c3_ee_k = c3_ce_k;
    c3_kc_x = c3_f_x[c3_ee_k];
    c3_lc_x = c3_kc_x;
    c3_lc_x = muDoubleScalarAtan(c3_lc_x);
    c3_f_x[c3_ee_k] = c3_lc_x;
  }

  for (c3_de_k = 0; c3_de_k < 4; c3_de_k++) {
    c3_fe_k = c3_de_k;
    c3_mc_x = c3_f_x[c3_fe_k];
    c3_nc_x = c3_mc_x;
    c3_nc_x = muDoubleScalarCos(c3_nc_x);
    c3_f_x[c3_fe_k] = c3_nc_x;
  }

  c3_i204 = 0;
  for (c3_i206 = 0; c3_i206 < 4; c3_i206++) {
    c3_mu_y[c3_i206] = c3_mu_y[c3_i206] * c3_Fz[c3_i206] * ((c3_b_RVY1 +
      c3_b_RVY2 * c3_dfz[c3_i206]) + c3_b_RVY3 * c3_gamma_star[c3_i206]) *
      c3_f_x[c3_i206] * c3_zeta[c3_i204 + 2];
    c3_i204 += 9;
  }

  for (c3_i208 = 0; c3_i208 < 4; c3_i208++) {
    c3_f_x[c3_i208] = c3_b_RVY6 * c3_kappa[c3_i208];
  }

  for (c3_ge_k = 0; c3_ge_k < 4; c3_ge_k++) {
    c3_he_k = c3_ge_k;
    c3_oc_x = c3_f_x[c3_he_k];
    c3_pc_x = c3_oc_x;
    c3_pc_x = muDoubleScalarAtan(c3_pc_x);
    c3_f_x[c3_he_k] = c3_pc_x;
  }

  for (c3_i210 = 0; c3_i210 < 4; c3_i210++) {
    c3_f_x[c3_i210] *= c3_b_RVY5;
  }

  for (c3_ie_k = 0; c3_ie_k < 4; c3_ie_k++) {
    c3_je_k = c3_ie_k;
    c3_qc_x = c3_f_x[c3_je_k];
    c3_rc_x = c3_qc_x;
    c3_rc_x = muDoubleScalarSin(c3_rc_x);
    c3_f_x[c3_je_k] = c3_rc_x;
  }

  for (c3_i213 = 0; c3_i213 < 4; c3_i213++) {
    c3_mu_y[c3_i213] = c3_mu_y[c3_i213] * c3_f_x[c3_i213] *
      c3_lam_Vykappa[c3_i213];
  }

  for (c3_i215 = 0; c3_i215 < 4; c3_i215++) {
    c3_b_Fy[c3_i215] = c3_b_Fy[c3_i215] * c3_Vs[c3_i215] + c3_mu_y[c3_i215];
  }

  for (c3_i216 = 0; c3_i216 < 4; c3_i216++) {
    c3_b_My[c3_i216] = 10.0 * c3_b_Omega[c3_i216];
  }

  for (c3_le_k = 0; c3_le_k < 4; c3_le_k++) {
    c3_ne_k = c3_le_k;
    c3_tc_x = c3_b_My[c3_ne_k];
    c3_uc_x = c3_tc_x;
    c3_uc_x = muDoubleScalarTanh(c3_uc_x);
    c3_b_My[c3_ne_k] = c3_uc_x;
  }

  c3_st.site = &c3_b_emlrtRSI;
  c3_rollingMoment(chartInstance, &c3_st, c3_b_Fx, c3_b_Vx, c3_FzUnSat, c3_press,
                   c3_gamma, c3_b_LONGVL, c3_b_UNLOADED_RADIUS, c3_b_FNOMIN,
                   c3_b_NOMPRES, c3_b_QSY1, c3_b_QSY2, c3_b_QSY3, c3_b_QSY4,
                   c3_b_QSY5, c3_b_QSY6, c3_b_QSY7, c3_b_QSY8, c3_lam_My,
                   c3_Fz_btm);
  for (c3_i218 = 0; c3_i218 < 4; c3_i218++) {
    c3_b_My[c3_i218] *= c3_Fz_btm[c3_i218];
  }

  for (c3_qe_k = 0; c3_qe_k < 4; c3_qe_k++) {
    c3_re_k = c3_qe_k;
    c3_xc_x = c3_gamma[c3_re_k];
    c3_ib_y = muDoubleScalarAbs(c3_xc_x);
    c3_e_y[c3_re_k] = c3_ib_y;
  }

  for (c3_i220 = 0; c3_i220 < 4; c3_i220++) {
    c3_Vc_prime[c3_i220] = c3_b_QSX6 * c3_Fz[c3_i220] / c3_b_FNOMIN;
  }

  for (c3_se_k = 0; c3_se_k < 4; c3_se_k++) {
    c3_ue_k = c3_se_k;
    c3_fb_a = c3_Vc_prime[c3_ue_k];
    c3_jb_y = c3_fb_a * c3_fb_a;
    c3_SVygamma[c3_ue_k] = c3_jb_y;
  }

  for (c3_te_k = 0; c3_te_k < 4; c3_te_k++) {
    c3_ve_k = c3_te_k;
    c3_yc_x = c3_SVygamma[c3_ve_k];
    c3_ad_x = c3_yc_x;
    c3_ad_x = muDoubleScalarAtan(c3_ad_x);
    c3_SVygamma[c3_ve_k] = c3_ad_x;
  }

  for (c3_i221 = 0; c3_i221 < 4; c3_i221++) {
    c3_SVygamma[c3_i221] *= c3_b_QSX5;
  }

  for (c3_we_k = 0; c3_we_k < 4; c3_we_k++) {
    c3_xe_k = c3_we_k;
    c3_dd_x = c3_SVygamma[c3_xe_k];
    c3_ed_x = c3_dd_x;
    c3_ed_x = muDoubleScalarCos(c3_ed_x);
    c3_SVygamma[c3_xe_k] = c3_ed_x;
  }

  for (c3_i223 = 0; c3_i223 < 4; c3_i223++) {
    c3_f_x[c3_i223] = c3_b_QSX9 * c3_b_Fy[c3_i223] / c3_b_FNOMIN;
  }

  for (c3_ye_k = 0; c3_ye_k < 4; c3_ye_k++) {
    c3_af_k = c3_ye_k;
    c3_fd_x = c3_f_x[c3_af_k];
    c3_gd_x = c3_fd_x;
    c3_gd_x = muDoubleScalarAtan(c3_gd_x);
    c3_f_x[c3_af_k] = c3_gd_x;
  }

  for (c3_i226 = 0; c3_i226 < 4; c3_i226++) {
    c3_f_x[c3_i226] = c3_b_QSX7 * c3_gamma[c3_i226] + c3_b_QSX8 * c3_f_x[c3_i226];
  }

  for (c3_cf_k = 0; c3_cf_k < 4; c3_cf_k++) {
    c3_ef_k = c3_cf_k;
    c3_id_x = c3_f_x[c3_ef_k];
    c3_jd_x = c3_id_x;
    c3_jd_x = muDoubleScalarSin(c3_jd_x);
    c3_f_x[c3_ef_k] = c3_jd_x;
  }

  for (c3_i228 = 0; c3_i228 < 4; c3_i228++) {
    c3_Fz_btm[c3_i228] = c3_b_QSX11 * c3_Fz[c3_i228] / c3_b_FNOMIN;
  }

  for (c3_ff_k = 0; c3_ff_k < 4; c3_ff_k++) {
    c3_if_k = c3_ff_k;
    c3_kd_x = c3_Fz_btm[c3_if_k];
    c3_md_x = c3_kd_x;
    c3_md_x = muDoubleScalarAtan(c3_md_x);
    c3_Fz_btm[c3_if_k] = c3_md_x;
  }

  for (c3_hf_k = 0; c3_hf_k < 4; c3_hf_k++) {
    c3_kf_k = c3_hf_k;
    c3_od_x = c3_gamma[c3_kf_k];
    c3_lb_y = muDoubleScalarAbs(c3_od_x);
    c3_SHyphi[c3_kf_k] = c3_lb_y;
  }

  for (c3_i231 = 0; c3_i231 < 4; c3_i231++) {
    c3_b_Mx[c3_i231] = c3_b_UNLOADED_RADIUS * c3_Fz[c3_i231] * c3_b_Mx[c3_i231] *
      (((((c3_b_QSX1 * c3_lam_VMx[c3_i231] - c3_b_QSX2 * c3_gamma[c3_i231] *
           (c3_b_PPMX1 * c3_dpi[c3_i231] + 1.0)) - c3_b_QSX12 * c3_gamma[c3_i231]
          * c3_e_y[c3_i231]) + c3_b_QSX3 * c3_b_Fy[c3_i231] / c3_b_FNOMIN) +
        c3_b_QSX4 * c3_SVygamma[c3_i231] * c3_f_x[c3_i231]) + c3_b_QSX10 *
       c3_Fz_btm[c3_i231] * c3_gamma[c3_i231]) + c3_b_UNLOADED_RADIUS *
      c3_b_Fy[c3_i231] * c3_b_Mx[c3_i231] * (c3_b_QSX13 + c3_b_QSX14 *
      c3_SHyphi[c3_i231]);
  }

  for (c3_i233 = 0; c3_i233 < 4; c3_i233++) {
    c3_cosprimealpha[c3_i233] = c3_b_Vx[c3_i233] / c3_cosprimealpha[c3_i233];
  }

  for (c3_i234 = 0; c3_i234 < 4; c3_i234++) {
    c3_Fz_btm[c3_i234] = (c3_b_QHZ1 + c3_b_QHZ2 * c3_dfz[c3_i234]) + (c3_b_QHZ3
      + c3_b_QHZ4 * c3_dfz[c3_i234]) * c3_gamma_star[c3_i234];
  }

  for (c3_i237 = 0; c3_i237 < 4; c3_i237++) {
    c3_Fz_btm[c3_i237] += c3_alpha[c3_i237];
  }

  for (c3_i238 = 0; c3_i238 < 4; c3_i238++) {
    c3_SHy[c3_i238] += c3_lam_Vy[c3_i238] / c3_Kyalpha_prime[c3_i238];
  }

  for (c3_i239 = 0; c3_i239 < 4; c3_i239++) {
    c3_SHy[c3_i239] += c3_alpha[c3_i239];
  }

  for (c3_nf_k = 0; c3_nf_k < 4; c3_nf_k++) {
    c3_pf_k = c3_nf_k;
    c3_gb_a = c3_dfz[c3_pf_k];
    c3_mb_y = c3_gb_a * c3_gb_a;
    c3_Vsy[c3_pf_k] = c3_mb_y;
  }

  for (c3_of_k = 0; c3_of_k < 4; c3_of_k++) {
    c3_rf_k = c3_of_k;
    c3_rd_x = c3_gamma[c3_rf_k];
    c3_nb_y = muDoubleScalarAbs(c3_rd_x);
    c3_e_y[c3_rf_k] = c3_nb_y;
  }

  for (c3_qf_k = 0; c3_qf_k < 4; c3_qf_k++) {
    c3_sf_k = c3_qf_k;
    c3_hb_a = c3_gamma_star[c3_sf_k];
    c3_ob_y = c3_hb_a * c3_hb_a;
    c3_SVygamma[c3_sf_k] = c3_ob_y;
  }

  for (c3_i240 = 0; c3_i240 < 4; c3_i240++) {
    c3_Vsy[c3_i240] = ((c3_b_QBZ1 + c3_b_QBZ2 * c3_dfz[c3_i240]) + c3_b_QBZ3 *
                       c3_Vsy[c3_i240]) * (((c3_b_QBZ4 * c3_gamma[c3_i240] + 1.0)
      + c3_b_QBZ5 * c3_e_y[c3_i240]) + c3_b_QBZ6 * c3_SVygamma[c3_i240]) *
      c3_lam_Kyalpha[c3_i240] / c3_lam_muy[c3_i240];
  }

  for (c3_ne_i = 0; c3_ne_i < 4; c3_ne_i++) {
    if (c3_Vsy[c3_ne_i] < 0.0) {
      c3_Vsy[c3_ne_i] = 0.0;
    }
  }

  c3_dv6[0] = c3_b_QCZ1;
  c3_bv[0] = (c3_b_QCZ1 < 0.0);
  for (c3_oe_i = 0; c3_oe_i < 1; c3_oe_i++) {
    if (c3_bv[0]) {
      c3_dv6[c3_oe_i] = 0.0;
    }
  }

  c3_Ct = c3_dv6[0];
  c3_sd_x = c3_b_UNLOADED_RADIUS;
  c3_td_x = c3_sd_x;
  for (c3_i243 = 0; c3_i243 < 4; c3_i243++) {
    c3_Fzo_prime[c3_i243] = c3_td_x / c3_Fzo_prime[c3_i243];
  }

  for (c3_tf_k = 0; c3_tf_k < 4; c3_tf_k++) {
    c3_uf_k = c3_tf_k;
    c3_ib_a = c3_gamma[c3_uf_k];
    c3_pb_y = c3_ib_a * c3_ib_a;
    c3_Vs[c3_uf_k] = c3_pb_y;
  }

  c3_i244 = 0;
  for (c3_i245 = 0; c3_i245 < 4; c3_i245++) {
    c3_Vs[c3_i245] = (c3_b_QDZ1 + c3_b_QDZ2 * c3_dfz[c3_i245]) * (1.0 -
      c3_b_PPZ1 * c3_dpi[c3_i245]) * ((c3_b_QDZ3 * c3_gamma[c3_i245] + 1.0) +
      c3_b_QDZ4 * c3_Vs[c3_i245]) * c3_Fz[c3_i245] * c3_Fzo_prime[c3_i245] *
      c3_lam_t[c3_i245] * c3_zeta[c3_i244 + 5];
    c3_i244 += 9;
  }

  for (c3_vf_k = 0; c3_vf_k < 4; c3_vf_k++) {
    c3_wf_k = c3_vf_k;
    c3_jb_a = c3_dfz[c3_wf_k];
    c3_qb_y = c3_jb_a * c3_jb_a;
    c3_SHyphi[c3_wf_k] = c3_qb_y;
  }

  for (c3_i246 = 0; c3_i246 < 4; c3_i246++) {
    c3_f_x[c3_i246] = c3_Vsy[c3_i246] * c3_Ct * c3_Fz_btm[c3_i246];
  }

  for (c3_xf_k = 0; c3_xf_k < 4; c3_xf_k++) {
    c3_yf_k = c3_xf_k;
    c3_ud_x = c3_f_x[c3_yf_k];
    c3_vd_x = c3_ud_x;
    c3_vd_x = muDoubleScalarAtan(c3_vd_x);
    c3_f_x[c3_yf_k] = c3_vd_x;
  }

  for (c3_i248 = 0; c3_i248 < 4; c3_i248++) {
    c3_SHyphi[c3_i248] = ((c3_b_QEZ1 + c3_b_QEZ2 * c3_dfz[c3_i248]) + c3_b_QEZ3 *
                          c3_SHyphi[c3_i248]) * (1.0 + (c3_b_QEZ4 + c3_b_QEZ5 *
      c3_gamma_star[c3_i248]) * 2.0 / 3.1415926535897931 * c3_f_x[c3_i248]);
  }

  for (c3_se_i = 0; c3_se_i < 4; c3_se_i++) {
    if (c3_SHyphi[c3_se_i] > 1.0) {
      c3_SHyphi[c3_se_i] = 1.0;
    }
  }

  for (c3_i250 = 0; c3_i250 < 4; c3_i250++) {
    c3_e_y[c3_i250] = 10.0 * c3_b_Vx[c3_i250];
  }

  for (c3_ag_k = 0; c3_ag_k < 4; c3_ag_k++) {
    c3_cg_k = c3_ag_k;
    c3_wd_x = c3_gamma_star[c3_cg_k];
    c3_rb_y = muDoubleScalarAbs(c3_wd_x);
    c3_SVygamma[c3_cg_k] = c3_rb_y;
  }

  for (c3_bg_k = 0; c3_bg_k < 4; c3_bg_k++) {
    c3_dg_k = c3_bg_k;
    c3_xd_x = c3_e_y[c3_dg_k];
    c3_yd_x = c3_xd_x;
    c3_yd_x = muDoubleScalarTanh(c3_yd_x);
    c3_e_y[c3_dg_k] = c3_yd_x;
  }

  c3_i252 = 0;
  for (c3_i253 = 0; c3_i253 < 4; c3_i253++) {
    c3_lam_Mr[c3_i253] = (c3_Fz[c3_i253] * c3_b_UNLOADED_RADIUS * ((c3_b_QDZ6 +
      c3_b_QDZ7 * c3_dfz[c3_i253]) * c3_lam_Mr[c3_i253] * c3_zeta[c3_i252 + 2] +
      ((c3_b_QDZ8 + c3_b_QDZ9 * c3_dfz[c3_i253]) * (c3_b_PPZ2 * c3_dpi[c3_i253]
      + 1.0) + (c3_b_QDZ10 + c3_b_QDZ11 * c3_dfz[c3_i253]) * c3_SVygamma[c3_i253])
      * c3_gamma_star[c3_i253] * c3_lam_Kzgamma[c3_i253] * c3_zeta[c3_i252]) *
                          c3_lam_muy[c3_i253] * c3_e_y[c3_i253] *
                          c3_cosprimealpha[c3_i253] + c3_zeta[c3_i252 + 8]) -
      1.0;
    c3_i252 += 9;
  }

  c3_i254 = 0;
  for (c3_i256 = 0; c3_i256 < 4; c3_i256++) {
    c3_lam_muV[c3_i256] = c3_zeta[c3_i254 + 7];
    c3_i254 += 9;
  }

  c3_i257 = 0;
  for (c3_i259 = 0; c3_i259 < 4; c3_i259++) {
    c3_lam_Kyalpha[c3_i259] = (c3_b_QBZ9 * c3_lam_Kyalpha[c3_i259] /
      c3_lam_muy[c3_i259] + c3_b_QBZ10 * c3_lam_ykappa[c3_i259] *
      c3_Bykappa[c3_i259]) * c3_zeta[c3_i257 + 6];
    c3_i257 += 9;
  }

  for (c3_i261 = 0; c3_i261 < 4; c3_i261++) {
    c3_f_x[c3_i261] = c3_SHy[c3_i261];
  }

  for (c3_eg_k = 0; c3_eg_k < 4; c3_eg_k++) {
    c3_gg_k = c3_eg_k;
    c3_ae_x = c3_f_x[c3_gg_k];
    c3_be_x = c3_ae_x;
    c3_be_x = muDoubleScalarTan(c3_be_x);
    c3_f_x[c3_gg_k] = c3_be_x;
  }

  for (c3_fg_k = 0; c3_fg_k < 4; c3_fg_k++) {
    c3_hg_k = c3_fg_k;
    c3_kb_a = c3_f_x[c3_hg_k];
    c3_sb_y = c3_kb_a * c3_kb_a;
    c3_lam_mux[c3_hg_k] = c3_sb_y;
  }

  for (c3_i262 = 0; c3_i262 < 4; c3_i262++) {
    c3_Vc_prime[c3_i262] = c3_phi_t[c3_i262] / c3_Kyalpha_prime[c3_i262];
  }

  for (c3_ig_k = 0; c3_ig_k < 4; c3_ig_k++) {
    c3_kg_k = c3_ig_k;
    c3_lb_a = c3_Vc_prime[c3_kg_k];
    c3_tb_y = c3_lb_a * c3_lb_a;
    c3_e_y[c3_kg_k] = c3_tb_y;
  }

  for (c3_jg_k = 0; c3_jg_k < 4; c3_jg_k++) {
    c3_lg_k = c3_jg_k;
    c3_mb_a = c3_kappa[c3_lg_k];
    c3_ub_y = c3_mb_a * c3_mb_a;
    c3_SVygamma[c3_lg_k] = c3_ub_y;
  }

  for (c3_i263 = 0; c3_i263 < 4; c3_i263++) {
    c3_lam_mux[c3_i263] += c3_e_y[c3_i263] * c3_SVygamma[c3_i263];
  }

  c3_st.site = &c3_b_emlrtRSI;
  c3_e_sqrt(chartInstance, &c3_st, c3_lam_mux);
  for (c3_mg_k = 0; c3_mg_k < 4; c3_mg_k++) {
    c3_ng_k = c3_mg_k;
    c3_ce_x = c3_lam_mux[c3_ng_k];
    c3_de_x = c3_ce_x;
    c3_de_x = muDoubleScalarAtan(c3_de_x);
    c3_lam_mux[c3_ng_k] = c3_de_x;
  }

  for (c3_i265 = 0; c3_i265 < 4; c3_i265++) {
    c3_SHy[c3_i265] *= 1000.0;
  }

  for (c3_og_k = 0; c3_og_k < 4; c3_og_k++) {
    c3_pg_k = c3_og_k;
    c3_ee_x = c3_SHy[c3_pg_k];
    c3_fe_x = c3_ee_x;
    c3_fe_x = muDoubleScalarTanh(c3_fe_x);
    c3_SHy[c3_pg_k] = c3_fe_x;
  }

  for (c3_i266 = 0; c3_i266 < 4; c3_i266++) {
    c3_lam_mux[c3_i266] *= c3_SHy[c3_i266];
  }

  for (c3_i267 = 0; c3_i267 < 4; c3_i267++) {
    c3_f_x[c3_i267] = c3_Fz_btm[c3_i267];
  }

  for (c3_qg_k = 0; c3_qg_k < 4; c3_qg_k++) {
    c3_sg_k = c3_qg_k;
    c3_ge_x = c3_f_x[c3_sg_k];
    c3_he_x = c3_ge_x;
    c3_he_x = muDoubleScalarTan(c3_he_x);
    c3_f_x[c3_sg_k] = c3_he_x;
  }

  for (c3_rg_k = 0; c3_rg_k < 4; c3_rg_k++) {
    c3_tg_k = c3_rg_k;
    c3_nb_a = c3_f_x[c3_tg_k];
    c3_vb_y = c3_nb_a * c3_nb_a;
    c3_lam_Cz[c3_tg_k] = c3_vb_y;
  }

  for (c3_i268 = 0; c3_i268 < 4; c3_i268++) {
    c3_Kyalpha_prime[c3_i268] = c3_phi_t[c3_i268] / c3_Kyalpha_prime[c3_i268];
  }

  for (c3_ug_k = 0; c3_ug_k < 4; c3_ug_k++) {
    c3_wg_k = c3_ug_k;
    c3_ob_a = c3_Kyalpha_prime[c3_wg_k];
    c3_wb_y = c3_ob_a * c3_ob_a;
    c3_e_y[c3_wg_k] = c3_wb_y;
  }

  for (c3_vg_k = 0; c3_vg_k < 4; c3_vg_k++) {
    c3_xg_k = c3_vg_k;
    c3_pb_a = c3_kappa[c3_xg_k];
    c3_xb_y = c3_pb_a * c3_pb_a;
    c3_SVygamma[c3_xg_k] = c3_xb_y;
  }

  for (c3_i270 = 0; c3_i270 < 4; c3_i270++) {
    c3_lam_Cz[c3_i270] += c3_e_y[c3_i270] * c3_SVygamma[c3_i270];
  }

  c3_st.site = &c3_b_emlrtRSI;
  c3_e_sqrt(chartInstance, &c3_st, c3_lam_Cz);
  for (c3_yg_k = 0; c3_yg_k < 4; c3_yg_k++) {
    c3_ah_k = c3_yg_k;
    c3_ie_x = c3_lam_Cz[c3_ah_k];
    c3_je_x = c3_ie_x;
    c3_je_x = muDoubleScalarAtan(c3_je_x);
    c3_lam_Cz[c3_ah_k] = c3_je_x;
  }

  for (c3_i271 = 0; c3_i271 < 4; c3_i271++) {
    c3_Fz_btm[c3_i271] *= 1000.0;
  }

  for (c3_bh_k = 0; c3_bh_k < 4; c3_bh_k++) {
    c3_ch_k = c3_bh_k;
    c3_ke_x = c3_Fz_btm[c3_ch_k];
    c3_le_x = c3_ke_x;
    c3_le_x = muDoubleScalarTanh(c3_le_x);
    c3_Fz_btm[c3_ch_k] = c3_le_x;
  }

  for (c3_i272 = 0; c3_i272 < 4; c3_i272++) {
    c3_lam_Cz[c3_i272] *= c3_Fz_btm[c3_i272];
  }

  c3_c_magiccos(chartInstance, c3_lam_Mr, c3_lam_muV, c3_lam_Kyalpha, c3_lam_mux,
                c3_Fz_btm);
  c3_d_magiccos(chartInstance, c3_Vs, c3_Ct, c3_Vsy, c3_SHyphi, c3_lam_Cz,
                c3_b_Mz);
  for (c3_i273 = 0; c3_i273 < 4; c3_i273++) {
    c3_b_Mz[c3_i273] *= c3_cosprimealpha[c3_i273];
  }

  for (c3_i274 = 0; c3_i274 < 4; c3_i274++) {
    c3_b_Mz[c3_i274] *= c3_lam_Fzo[c3_i274];
  }

  for (c3_i275 = 0; c3_i275 < 4; c3_i275++) {
    c3_gamma_star[c3_i275] = c3_b_UNLOADED_RADIUS * ((c3_b_SSZ1 + c3_b_SSZ2 *
      c3_b_Fy[c3_i275] / c3_b_FNOMIN) + (c3_b_SSZ3 + c3_b_SSZ4 * c3_dfz[c3_i275])
      * c3_gamma_star[c3_i275]) * c3_lam_s[c3_i275];
  }

  for (c3_i276 = 0; c3_i276 < 4; c3_i276++) {
    c3_mu_y[c3_i276] = c3_b_Fy[c3_i276] - c3_mu_y[c3_i276];
  }

  for (c3_i277 = 0; c3_i277 < 4; c3_i277++) {
    c3_b_Mz[c3_i277] = -c3_b_Mz[c3_i277] * c3_mu_y[c3_i277];
  }

  for (c3_i279 = 0; c3_i279 < 4; c3_i279++) {
    c3_b_Mz[c3_i279] = (c3_b_Mz[c3_i279] + c3_Fz_btm[c3_i279]) +
      c3_gamma_star[c3_i279] * c3_b_Fx[c3_i279];
  }

  for (c3_dh_k = 0; c3_dh_k < 4; c3_dh_k++) {
    c3_eh_k = c3_dh_k;
    c3_qb_a = c3_dfz[c3_eh_k];
    c3_yb_y = c3_qb_a * c3_qb_a;
    c3_Fz_btm[c3_eh_k] = c3_yb_y;
  }

  for (c3_i280 = 0; c3_i280 < 4; c3_i280++) {
    c3_Fz_btm[c3_i280] = c3_b_LONGITUDINAL_STIFFNESS * ((c3_b_PCFX1 *
      c3_dfz[c3_i280] + 1.0) + c3_b_PCFX2 * c3_Fz_btm[c3_i280]) * (c3_b_PCFX3 *
      c3_dpi[c3_i280] + 1.0);
  }

  for (c3_fh_k = 0; c3_fh_k < 4; c3_fh_k++) {
    c3_gh_k = c3_fh_k;
    c3_rb_a = c3_dfz[c3_gh_k];
    c3_ac_y = c3_rb_a * c3_rb_a;
    c3_e_y[c3_gh_k] = c3_ac_y;
  }

  for (c3_i281 = 0; c3_i281 < 4; c3_i281++) {
    c3_dfz[c3_i281] = c3_b_LATERAL_STIFFNESS * ((c3_b_PCFY1 * c3_dfz[c3_i281] +
      1.0) + c3_b_PCFY2 * c3_e_y[c3_i281]) * (c3_b_PCFY3 * c3_dpi[c3_i281] + 1.0);
  }

  for (c3_i283 = 0; c3_i283 < 4; c3_i283++) {
    c3_phi_t[c3_i283] /= c3_Fz_btm[c3_i283];
  }

  for (c3_hh_k = 0; c3_hh_k < 4; c3_hh_k++) {
    c3_ih_k = c3_hh_k;
    c3_me_x = c3_phi_t[c3_ih_k];
    c3_bc_y = muDoubleScalarAbs(c3_me_x);
    c3_b_sig_x[c3_ih_k] = c3_bc_y;
  }

  for (c3_i285 = 0; c3_i285 < 4; c3_i285++) {
    c3_Kyalpha[c3_i285] /= c3_dfz[c3_i285];
  }

  for (c3_jh_k = 0; c3_jh_k < 4; c3_jh_k++) {
    c3_kh_k = c3_jh_k;
    c3_ne_x = c3_Kyalpha[c3_kh_k];
    c3_cc_y = muDoubleScalarAbs(c3_ne_x);
    c3_b_sig_y[c3_kh_k] = c3_cc_y;
  }
}

static void c3_emlrt_marshallIn(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance, const mxArray *c3_b_Alpha, const char_T *c3_identifier, real_T
  c3_y[4])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char_T *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_Alpha), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_Alpha);
}

static void c3_b_emlrt_marshallIn(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[4])
{
  real_T c3_dv[4];
  int32_T c3_i;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv, 1, 0, 0U, 1, 0U, 1, 4);
  for (c3_i = 0; c3_i < 4; c3_i++) {
    c3_y[c3_i] = c3_dv[c3_i];
  }

  sf_mex_destroy(&c3_u);
}

static uint8_T c3_c_emlrt_marshallIn(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_vehdynlibtirecommon, const
  char_T *c3_identifier)
{
  emlrtMsgIdentifier c3_thisId;
  uint8_T c3_y;
  c3_thisId.fIdentifier = (const char_T *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_vehdynlibtirecommon), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_vehdynlibtirecommon);
  return c3_y;
}

static uint8_T c3_d_emlrt_marshallIn(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_b_u;
  uint8_T c3_y;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b_u, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_b_u;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_slStringInitializeDynamicBuffers
  (SFc3_vehdynlibtirecommonInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_chart_data_browse_helper(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance, int32_T c3_ssIdNumber, const mxArray **c3_mxData, uint8_T
  *c3_isValueTooBig)
{
  *c3_mxData = NULL;
  *c3_mxData = NULL;
  *c3_isValueTooBig = 0U;
  switch (c3_ssIdNumber) {
   case 6U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_Omega, 0,
      0U, 1U, 0U, 1, 4), false);
    break;

   case 10U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_Vx, 0,
      0U, 1U, 0U, 1, 4), false);
    break;

   case 11U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_Vy, 0,
      0U, 1U, 0U, 1, 4), false);
    break;

   case 125U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_psidot,
      0, 0U, 1U, 0U, 1, 4), false);
    break;

   case 32U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_Gamma, 0,
      0U, 1U, 0U, 1, 4), false);
    break;

   case 28U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_TirePrs,
      0, 0U, 1U, 0U, 1, 4), false);
    break;

   case 12U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData",
      *chartInstance->c3_ScaleFactors, 0, 0U, 1U, 0U, 2, 27, 4), false);
    break;

   case 349U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_rhoz, 0,
      0U, 1U, 0U, 1, 4), false);
    break;

   case 358U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_plySteer,
      0, 0U, 0U, 0U, 0), false);
    break;

   case 555U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_turnslip,
      0, 0U, 0U, 0U, 0), false);
    break;

   case 120U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_Fx, 0,
      0U, 1U, 0U, 1, 4), false);
    break;

   case 121U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_Fy, 0,
      0U, 1U, 0U, 1, 4), false);
    break;

   case 4U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_FzTire,
      0, 0U, 1U, 0U, 1, 4), false);
    break;

   case 117U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_Mx, 0,
      0U, 1U, 0U, 1, 4), false);
    break;

   case 118U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_My, 0,
      0U, 1U, 0U, 1, 4), false);
    break;

   case 119U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_Mz, 0,
      0U, 1U, 0U, 1, 4), false);
    break;

   case 357U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_Re, 0,
      0U, 1U, 0U, 1, 4), false);
    break;

   case 21U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_Kappa, 0,
      0U, 1U, 0U, 1, 4), false);
    break;

   case 22U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_Alpha, 0,
      0U, 1U, 0U, 1, 4), false);
    break;

   case 547U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_sig_x, 0,
      0U, 1U, 0U, 1, 4), false);
    break;

   case 548U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_sig_y, 0,
      0U, 1U, 0U, 1, 4), false);
    break;

   case 142U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PRESMAX,
      0, 0U, 0U, 0U, 0), false);
    break;

   case 359U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PRESMIN,
      0, 0U, 0U, 0U, 0), false);
    break;

   case 360U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_FZMAX, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 361U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_FZMIN, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 362U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_VXLOW, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 363U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_KPUMAX,
      0, 0U, 0U, 0U, 0), false);
    break;

   case 364U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_KPUMIN,
      0, 0U, 0U, 0U, 0), false);
    break;

   case 365U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_ALPMAX,
      0, 0U, 0U, 0U, 0), false);
    break;

   case 366U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_ALPMIN,
      0, 0U, 0U, 0U, 0), false);
    break;

   case 367U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_CAMMIN,
      0, 0U, 0U, 0U, 0), false);
    break;

   case 368U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_CAMMAX,
      0, 0U, 0U, 0U, 0), false);
    break;

   case 369U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_LONGVL,
      0, 0U, 0U, 0U, 0), false);
    break;

   case 370U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData",
      &chartInstance->c3_UNLOADED_RADIUS, 0, 0U, 0U, 0U, 0), false);
    break;

   case 551U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData",
      &chartInstance->c3_RIM_RADIUS, 0, 0U, 0U, 0U, 0), false);
    break;

   case 371U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_NOMPRES,
      0, 0U, 0U, 0U, 0), false);
    break;

   case 372U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_FNOMIN,
      0, 0U, 0U, 0U, 0), false);
    break;

   case 373U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData",
      &chartInstance->c3_VERTICAL_STIFFNESS, 0, 0U, 0U, 0U, 0), false);
    break;

   case 530U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_DREFF, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 531U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_BREFF, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 532U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_FREFF, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 523U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_Q_RE0, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 524U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_Q_V1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 374U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_Q_V2, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 375U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_Q_FZ1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 376U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_Q_FZ2, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 378U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_Q_FCX, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 379U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_Q_FCY, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 380U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PFZ1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 377U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_Q_FCY2,
      0, 0U, 0U, 0U, 0), false);
    break;

   case 552U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData",
      &chartInstance->c3_BOTTOM_OFFST, 0, 0U, 0U, 0U, 0), false);
    break;

   case 553U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData",
      &chartInstance->c3_BOTTOM_STIFF, 0, 0U, 0U, 0U, 0), false);
    break;

   case 381U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PCX1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 382U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PDX1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 383U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PDX2, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 384U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PDX3, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 385U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PEX1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 386U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PEX2, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 387U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PEX3, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 388U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PEX4, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 389U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PKX1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 390U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PKX2, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 391U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PKX3, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 392U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PHX1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 393U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PHX2, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 394U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PVX1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 395U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PVX2, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 396U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PPX1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 397U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PPX2, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 398U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PPX3, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 399U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PPX4, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 400U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_RBX1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 401U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_RBX2, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 402U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_RBX3, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 403U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_RCX1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 404U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_REX1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 405U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_REX2, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 406U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_RHX1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 407U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QSX1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 408U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QSX2, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 409U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QSX3, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 410U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QSX4, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 411U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QSX5, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 412U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QSX6, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 413U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QSX7, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 414U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QSX8, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 415U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QSX9, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 416U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QSX10, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 417U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QSX11, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 418U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PPMX1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 419U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PCY1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 420U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PDY1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 421U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PDY2, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 422U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PDY3, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 423U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PEY1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 424U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PEY2, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 425U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PEY3, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 426U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PEY4, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 427U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PEY5, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 428U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PKY1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 429U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PKY2, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 430U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PKY3, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 431U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PKY4, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 432U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PKY5, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 433U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PKY6, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 434U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PKY7, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 435U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PHY1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 436U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PHY2, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 437U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PVY1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 438U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PVY2, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 439U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PVY3, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 440U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PVY4, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 441U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PPY1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 442U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PPY2, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 443U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PPY3, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 444U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PPY4, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 445U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PPY5, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 446U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_RBY1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 447U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_RBY2, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 448U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_RBY3, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 449U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_RBY4, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 450U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_RCY1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 451U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_REY1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 452U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_REY2, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 453U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_RHY1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 454U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_RHY2, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 455U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_RVY1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 456U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_RVY2, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 457U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_RVY3, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 458U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_RVY4, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 459U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_RVY5, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 460U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_RVY6, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 461U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QSY1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 462U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QSY2, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 463U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QSY3, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 464U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QSY4, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 465U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QSY5, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 466U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QSY6, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 467U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QSY7, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 468U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QSY8, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 469U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QBZ1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 470U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QBZ2, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 471U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QBZ3, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 472U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QBZ4, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 473U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QBZ5, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 474U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QBZ6, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 475U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QBZ9, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 476U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QBZ10, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 477U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QCZ1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 478U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QDZ1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 479U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QDZ2, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 480U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QDZ3, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 481U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QDZ4, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 482U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QDZ6, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 483U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QDZ7, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 484U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QDZ8, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 485U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QDZ9, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 486U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QDZ10, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 487U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QDZ11, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 488U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QEZ1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 489U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QEZ2, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 490U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QEZ3, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 491U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QEZ4, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 492U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QEZ5, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 493U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QHZ1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 494U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QHZ2, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 495U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QHZ3, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 496U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QHZ4, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 497U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PPZ1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 498U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PPZ2, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 499U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_SSZ1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 500U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_SSZ2, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 501U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_SSZ3, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 502U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_SSZ4, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 503U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PDXP1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 504U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PDXP2, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 505U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PDXP3, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 506U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PKYP1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 507U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PDYP1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 508U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PDYP2, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 509U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PDYP3, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 510U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PDYP4, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 511U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PHYP1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 512U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PHYP2, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 513U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PHYP3, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 514U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PHYP4, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 515U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PECP1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 516U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PECP2, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 517U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QDTP1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 518U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QCRP1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 519U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QCRP2, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 520U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QBRP1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 521U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QDRP1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 522U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QDRP2, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 525U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_WIDTH, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 526U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_Q_RA1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 527U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_Q_RA2, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 528U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_Q_RB1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 529U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_Q_RB2, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 533U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QSX12, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 534U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QSX13, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 535U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_QSX14, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 536U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_a, 0, 0U,
      1U, 0U, 1, 4), false);
    break;

   case 537U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_b, 0, 0U,
      1U, 0U, 1, 4), false);
    break;

   case 538U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_Q_FZ3, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 539U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData",
      &chartInstance->c3_LONGITUDINAL_STIFFNESS, 0, 0U, 0U, 0U, 0), false);
    break;

   case 540U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData",
      &chartInstance->c3_LATERAL_STIFFNESS, 0, 0U, 0U, 0U, 0), false);
    break;

   case 541U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PCFX1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 542U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PCFX2, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 543U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PCFX3, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 544U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PCFY1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 545U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PCFY2, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 546U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_PCFY3, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 549U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_Fx_ext,
      0, 0U, 1U, 0U, 1, 4), false);
    break;

   case 550U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_Fy_ext,
      0, 0U, 1U, 0U, 1, 4), false);
    break;

   case 554U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", chartInstance->c3_vdynMF, 0,
      0U, 1U, 0U, 1, 279), false);
    break;
  }
}

static void c3_d_sqrt(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
                      const emlrtStack *c3_sp, real_T c3_x_data[], int32_T
                      c3_x_size[2])
{
  static char_T c3_b_cv[4] = { 's', 'q', 'r', 't' };

  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_y = NULL;
  real_T c3_b_x_data[1];
  real_T c3_b_x;
  real_T c3_d;
  real_T c3_x;
  int32_T c3_b_x_size[2];
  int32_T c3_b_k;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_k;
  int32_T c3_loop_ub;
  int32_T c3_nx;
  boolean_T c3_b_p;
  boolean_T c3_p;
  (void)chartInstance;
  c3_b_x_size[1] = c3_x_size[1];
  c3_loop_ub = c3_x_size[0] * c3_x_size[1] - 1;
  for (c3_i = 0; c3_i <= c3_loop_ub; c3_i++) {
    c3_b_x_data[c3_i] = c3_x_data[c3_i];
  }

  c3_p = false;
  c3_d = (real_T)c3_b_x_size[1];
  c3_i1 = (int32_T)c3_d - 1;
  for (c3_k = 0; c3_k <= c3_i1; c3_k++) {
    if (c3_p || (c3_b_x_data[0] < 0.0)) {
      c3_b_p = true;
    } else {
      c3_b_p = false;
    }

    c3_p = c3_b_p;
  }

  if (c3_p) {
    c3_y = NULL;
    sf_mex_assign(&c3_y, sf_mex_create("y", c3_cv1, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c3_b_y = NULL;
    sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_cv1, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c3_c_y = NULL;
    sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_b_cv, 10, 0U, 1U, 0U, 2, 1, 4),
                  false);
    sf_mex_call(c3_sp, &c3_c_emlrtMCI, "error", 0U, 2U, 14, c3_y, 14,
                sf_mex_call(c3_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c3_sp, NULL, "message", 1U, 2U, 14, c3_b_y, 14, c3_c_y)));
  }

  c3_nx = c3_x_size[1];
  c3_i2 = (uint8_T)c3_nx - 1;
  for (c3_b_k = 0; c3_b_k <= c3_i2; c3_b_k++) {
    c3_x = c3_x_data[0];
    c3_b_x = c3_x;
    c3_b_x = muDoubleScalarSqrt(c3_b_x);
    c3_x_data[0] = c3_b_x;
  }
}

static void c3_e_sqrt(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
                      const emlrtStack *c3_sp, real_T c3_x[4])
{
  static char_T c3_b_cv[4] = { 's', 'q', 'r', 't' };

  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_y = NULL;
  real_T c3_b_x[4];
  real_T c3_b_k;
  real_T c3_c_x;
  real_T c3_d_x;
  int32_T c3_c_k;
  int32_T c3_d_k;
  int32_T c3_i;
  int32_T c3_k;
  boolean_T c3_b_p;
  boolean_T c3_p;
  (void)chartInstance;
  for (c3_i = 0; c3_i < 4; c3_i++) {
    c3_b_x[c3_i] = c3_x[c3_i];
  }

  c3_p = false;
  for (c3_k = 0; c3_k < 4; c3_k++) {
    c3_b_k = (real_T)c3_k + 1.0;
    if (c3_p || (c3_b_x[(int32_T)c3_b_k - 1] < 0.0)) {
      c3_b_p = true;
    } else {
      c3_b_p = false;
    }

    c3_p = c3_b_p;
  }

  if (c3_p) {
    c3_y = NULL;
    sf_mex_assign(&c3_y, sf_mex_create("y", c3_cv1, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c3_b_y = NULL;
    sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_cv1, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c3_c_y = NULL;
    sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_b_cv, 10, 0U, 1U, 0U, 2, 1, 4),
                  false);
    sf_mex_call(c3_sp, &c3_c_emlrtMCI, "error", 0U, 2U, 14, c3_y, 14,
                sf_mex_call(c3_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c3_sp, NULL, "message", 1U, 2U, 14, c3_b_y, 14, c3_c_y)));
  }

  for (c3_c_k = 0; c3_c_k < 4; c3_c_k++) {
    c3_d_k = c3_c_k;
    c3_c_x = c3_x[c3_d_k];
    c3_d_x = c3_c_x;
    c3_d_x = muDoubleScalarSqrt(c3_d_x);
    c3_x[c3_d_k] = c3_d_x;
  }
}

static void c3_b_atan(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
                      real_T c3_x_data[], int32_T c3_x_size[1])
{
  real_T c3_b_x;
  real_T c3_x;
  int32_T c3_b_k;
  int32_T c3_i;
  int32_T c3_k;
  int32_T c3_nx;
  (void)chartInstance;
  c3_nx = c3_x_size[0];
  c3_i = (uint8_T)c3_nx - 1;
  for (c3_k = 0; c3_k <= c3_i; c3_k++) {
    c3_b_k = c3_k;
    c3_x = c3_x_data[c3_b_k];
    c3_b_x = c3_x;
    c3_b_x = muDoubleScalarAtan(c3_b_x);
    c3_x_data[c3_b_k] = c3_b_x;
  }
}

static void c3_b_cos(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
                     real_T c3_x_data[], int32_T c3_x_size[1])
{
  real_T c3_b_x;
  real_T c3_x;
  int32_T c3_b_k;
  int32_T c3_i;
  int32_T c3_k;
  int32_T c3_nx;
  (void)chartInstance;
  c3_nx = c3_x_size[0];
  c3_i = (uint8_T)c3_nx - 1;
  for (c3_k = 0; c3_k <= c3_i; c3_k++) {
    c3_b_k = c3_k;
    c3_x = c3_x_data[c3_b_k];
    c3_b_x = c3_x;
    c3_b_x = muDoubleScalarCos(c3_b_x);
    c3_x_data[c3_b_k] = c3_b_x;
  }
}

static void c3_f_sqrt(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
                      const emlrtStack *c3_sp, real_T c3_x_data[], int32_T
                      c3_x_size[1])
{
  static char_T c3_b_cv[4] = { 's', 'q', 'r', 't' };

  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_y = NULL;
  real_T c3_b_x_data[4];
  real_T c3_b_k;
  real_T c3_b_x;
  real_T c3_d;
  real_T c3_x;
  int32_T c3_b_x_size[1];
  int32_T c3_c_k;
  int32_T c3_d_k;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_k;
  int32_T c3_loop_ub;
  int32_T c3_nx;
  boolean_T c3_b_p;
  boolean_T c3_p;
  (void)chartInstance;
  c3_b_x_size[0] = c3_x_size[0];
  c3_loop_ub = c3_x_size[0] - 1;
  for (c3_i = 0; c3_i <= c3_loop_ub; c3_i++) {
    c3_b_x_data[c3_i] = c3_x_data[c3_i];
  }

  c3_p = false;
  c3_d = (real_T)c3_b_x_size[0];
  c3_i1 = (int32_T)c3_d - 1;
  for (c3_k = 0; c3_k <= c3_i1; c3_k++) {
    c3_b_k = (real_T)c3_k + 1.0;
    if (c3_p || (c3_b_x_data[(int32_T)c3_b_k - 1] < 0.0)) {
      c3_b_p = true;
    } else {
      c3_b_p = false;
    }

    c3_p = c3_b_p;
  }

  if (c3_p) {
    c3_y = NULL;
    sf_mex_assign(&c3_y, sf_mex_create("y", c3_cv1, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c3_b_y = NULL;
    sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_cv1, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c3_c_y = NULL;
    sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_b_cv, 10, 0U, 1U, 0U, 2, 1, 4),
                  false);
    sf_mex_call(c3_sp, &c3_c_emlrtMCI, "error", 0U, 2U, 14, c3_y, 14,
                sf_mex_call(c3_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c3_sp, NULL, "message", 1U, 2U, 14, c3_b_y, 14, c3_c_y)));
  }

  c3_nx = c3_x_size[0];
  c3_i2 = (uint8_T)c3_nx - 1;
  for (c3_c_k = 0; c3_c_k <= c3_i2; c3_c_k++) {
    c3_d_k = c3_c_k;
    c3_x = c3_x_data[c3_d_k];
    c3_b_x = c3_x;
    c3_b_x = muDoubleScalarSqrt(c3_b_x);
    c3_x_data[c3_d_k] = c3_b_x;
  }
}

static void c3_b_acos(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
                      const emlrtStack *c3_sp, real_T c3_x_data[], int32_T
                      c3_x_size[1])
{
  static char_T c3_b_cv[4] = { 'a', 'c', 'o', 's' };

  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_y = NULL;
  real_T c3_b_x_data[4];
  real_T c3_b_k;
  real_T c3_b_x;
  real_T c3_d;
  real_T c3_x;
  int32_T c3_b_x_size[1];
  int32_T c3_c_k;
  int32_T c3_d_k;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_k;
  int32_T c3_loop_ub;
  int32_T c3_nx;
  boolean_T c3_b1;
  boolean_T c3_b_b;
  boolean_T c3_b_p;
  boolean_T c3_p;
  (void)chartInstance;
  c3_b_x_size[0] = c3_x_size[0];
  c3_loop_ub = c3_x_size[0] - 1;
  for (c3_i = 0; c3_i <= c3_loop_ub; c3_i++) {
    c3_b_x_data[c3_i] = c3_x_data[c3_i];
  }

  c3_p = false;
  c3_d = (real_T)c3_b_x_size[0];
  c3_i1 = (int32_T)c3_d - 1;
  for (c3_k = 0; c3_k <= c3_i1; c3_k++) {
    c3_b_k = (real_T)c3_k + 1.0;
    if (c3_p) {
      c3_b_p = true;
    } else {
      c3_b_b = (c3_b_x_data[(int32_T)c3_b_k - 1] < -1.0);
      c3_b1 = (c3_b_x_data[(int32_T)c3_b_k - 1] > 1.0);
      if (c3_b_b || c3_b1) {
        c3_b_p = true;
      } else {
        c3_b_p = false;
      }
    }

    c3_p = c3_b_p;
  }

  if (c3_p) {
    c3_y = NULL;
    sf_mex_assign(&c3_y, sf_mex_create("y", c3_cv1, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c3_b_y = NULL;
    sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_cv1, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c3_c_y = NULL;
    sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_b_cv, 10, 0U, 1U, 0U, 2, 1, 4),
                  false);
    sf_mex_call(c3_sp, &c3_f_emlrtMCI, "error", 0U, 2U, 14, c3_y, 14,
                sf_mex_call(c3_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c3_sp, NULL, "message", 1U, 2U, 14, c3_b_y, 14, c3_c_y)));
  }

  c3_nx = c3_x_size[0];
  c3_i2 = (uint8_T)c3_nx - 1;
  for (c3_c_k = 0; c3_c_k <= c3_i2; c3_c_k++) {
    c3_d_k = c3_c_k;
    c3_x = c3_x_data[c3_d_k];
    c3_b_x = c3_x;
    c3_b_x = muDoubleScalarAcos(c3_b_x);
    c3_x_data[c3_d_k] = c3_b_x;
  }
}

static void c3_binary_expand_op(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance, real_T c3_in1_data[], int32_T c3_in1_size[1], real_T
  c3_in2_data[], int32_T c3_in2_size[1], real_T c3_in3[36], int32_T c3_in4_data[],
  int32_T c3_in4_size[1])
{
  real_T c3_b_in2_data[4];
  int32_T c3_b_in2_size[1];
  int32_T c3_aux_0_0;
  int32_T c3_aux_1_0;
  int32_T c3_b_loop_ub;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_loop_ub;
  int32_T c3_stride_0_0;
  int32_T c3_stride_1_0;
  (void)chartInstance;
  if (c3_in4_size[0] == 1) {
    c3_b_in2_size[0] = c3_in2_size[0];
  } else {
    c3_b_in2_size[0] = c3_in4_size[0];
  }

  c3_stride_0_0 = (c3_in2_size[0] != 1);
  c3_stride_1_0 = (c3_in4_size[0] != 1);
  c3_aux_0_0 = 0;
  c3_aux_1_0 = 0;
  if (c3_in4_size[0] == 1) {
    c3_i = c3_in2_size[0];
  } else {
    c3_i = c3_in4_size[0];
  }

  c3_loop_ub = c3_i - 1;
  for (c3_i1 = 0; c3_i1 <= c3_loop_ub; c3_i1++) {
    c3_b_in2_data[c3_i1] = c3_in2_data[c3_aux_0_0] + c3_in3[4 + 9 *
      (c3_in4_data[c3_aux_1_0] - 1)];
    c3_aux_1_0 += c3_stride_1_0;
    c3_aux_0_0 += c3_stride_0_0;
  }

  c3_in1_size[0] = c3_b_in2_size[0];
  c3_b_loop_ub = c3_b_in2_size[0] - 1;
  for (c3_i2 = 0; c3_i2 <= c3_b_loop_ub; c3_i2++) {
    c3_in1_data[c3_i2] = c3_b_in2_data[c3_i2];
  }
}

static void c3_plus(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
                    real_T c3_in1_data[], int32_T c3_in1_size[1], real_T
                    c3_in2_data[], int32_T c3_in2_size[1])
{
  real_T c3_b_in1_data[4];
  int32_T c3_b_in1_size[1];
  int32_T c3_aux_0_0;
  int32_T c3_aux_1_0;
  int32_T c3_b_loop_ub;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_loop_ub;
  int32_T c3_stride_0_0;
  int32_T c3_stride_1_0;
  (void)chartInstance;
  if (c3_in2_size[0] == 1) {
    c3_b_in1_size[0] = c3_in1_size[0];
  } else {
    c3_b_in1_size[0] = c3_in2_size[0];
  }

  c3_stride_0_0 = (c3_in1_size[0] != 1);
  c3_stride_1_0 = (c3_in2_size[0] != 1);
  c3_aux_0_0 = 0;
  c3_aux_1_0 = 0;
  if (c3_in2_size[0] == 1) {
    c3_i = c3_in1_size[0];
  } else {
    c3_i = c3_in2_size[0];
  }

  c3_loop_ub = c3_i - 1;
  for (c3_i1 = 0; c3_i1 <= c3_loop_ub; c3_i1++) {
    c3_b_in1_data[c3_i1] = c3_in1_data[c3_aux_0_0] + c3_in2_data[c3_aux_1_0];
    c3_aux_1_0 += c3_stride_1_0;
    c3_aux_0_0 += c3_stride_0_0;
  }

  c3_in1_size[0] = c3_b_in1_size[0];
  c3_b_loop_ub = c3_b_in1_size[0] - 1;
  for (c3_i2 = 0; c3_i2 <= c3_b_loop_ub; c3_i2++) {
    c3_in1_data[c3_i2] = c3_b_in1_data[c3_i2];
  }
}

static void c3_b_binary_expand_op(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance, real_T c3_in1_data[], int32_T c3_in1_size[1], real_T
  c3_in2_data[], int32_T c3_in2_size[1], real_T c3_in3[36], int32_T c3_in4_data[],
  int32_T c3_in4_size[1])
{
  real_T c3_b_in2_data[4];
  int32_T c3_b_in2_size[1];
  int32_T c3_aux_0_0;
  int32_T c3_aux_1_0;
  int32_T c3_b_loop_ub;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_loop_ub;
  int32_T c3_stride_0_0;
  int32_T c3_stride_1_0;
  (void)chartInstance;
  if (c3_in4_size[0] == 1) {
    c3_b_in2_size[0] = c3_in2_size[0];
  } else {
    c3_b_in2_size[0] = c3_in4_size[0];
  }

  c3_stride_0_0 = (c3_in2_size[0] != 1);
  c3_stride_1_0 = (c3_in4_size[0] != 1);
  c3_aux_0_0 = 0;
  c3_aux_1_0 = 0;
  if (c3_in4_size[0] == 1) {
    c3_i = c3_in2_size[0];
  } else {
    c3_i = c3_in4_size[0];
  }

  c3_loop_ub = c3_i - 1;
  for (c3_i1 = 0; c3_i1 <= c3_loop_ub; c3_i1++) {
    c3_b_in2_data[c3_i1] = c3_in2_data[c3_aux_0_0] * c3_in3[9 *
      (c3_in4_data[c3_aux_1_0] - 1)];
    c3_aux_1_0 += c3_stride_1_0;
    c3_aux_0_0 += c3_stride_0_0;
  }

  c3_in1_size[0] = c3_b_in2_size[0];
  c3_b_loop_ub = c3_b_in2_size[0] - 1;
  for (c3_i2 = 0; c3_i2 <= c3_b_loop_ub; c3_i2++) {
    c3_in1_data[c3_i2] = c3_b_in2_data[c3_i2];
  }
}

static void c3_rdivide(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
  real_T c3_in1_data[], int32_T c3_in1_size[1], real_T c3_in2_data[], int32_T
  c3_in2_size[1])
{
  real_T c3_b_in1_data[4];
  int32_T c3_b_in1_size[1];
  int32_T c3_aux_0_0;
  int32_T c3_aux_1_0;
  int32_T c3_b_loop_ub;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_loop_ub;
  int32_T c3_stride_0_0;
  int32_T c3_stride_1_0;
  (void)chartInstance;
  if (c3_in2_size[0] == 1) {
    c3_b_in1_size[0] = c3_in1_size[0];
  } else {
    c3_b_in1_size[0] = c3_in2_size[0];
  }

  c3_stride_0_0 = (c3_in1_size[0] != 1);
  c3_stride_1_0 = (c3_in2_size[0] != 1);
  c3_aux_0_0 = 0;
  c3_aux_1_0 = 0;
  if (c3_in2_size[0] == 1) {
    c3_i = c3_in1_size[0];
  } else {
    c3_i = c3_in2_size[0];
  }

  c3_loop_ub = c3_i - 1;
  for (c3_i1 = 0; c3_i1 <= c3_loop_ub; c3_i1++) {
    c3_b_in1_data[c3_i1] = c3_in1_data[c3_aux_0_0] / c3_in2_data[c3_aux_1_0];
    c3_aux_1_0 += c3_stride_1_0;
    c3_aux_0_0 += c3_stride_0_0;
  }

  c3_in1_size[0] = c3_b_in1_size[0];
  c3_b_loop_ub = c3_b_in1_size[0] - 1;
  for (c3_i2 = 0; c3_i2 <= c3_b_loop_ub; c3_i2++) {
    c3_in1_data[c3_i2] = c3_b_in1_data[c3_i2];
  }
}

static void c3_c_binary_expand_op(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance, real_T c3_in1_data[], int32_T c3_in1_size[1], real_T
  c3_in2_data[], int32_T c3_in2_size[1], real_T c3_in3[4], int32_T c3_in4_data[],
  int32_T c3_in4_size[1])
{
  real_T c3_b_in2_data[4];
  int32_T c3_b_in2_size[1];
  int32_T c3_aux_0_0;
  int32_T c3_aux_1_0;
  int32_T c3_b_loop_ub;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_loop_ub;
  int32_T c3_stride_0_0;
  int32_T c3_stride_1_0;
  (void)chartInstance;
  if (c3_in4_size[0] == 1) {
    c3_b_in2_size[0] = c3_in2_size[0];
  } else {
    c3_b_in2_size[0] = c3_in4_size[0];
  }

  c3_stride_0_0 = (c3_in2_size[0] != 1);
  c3_stride_1_0 = (c3_in4_size[0] != 1);
  c3_aux_0_0 = 0;
  c3_aux_1_0 = 0;
  if (c3_in4_size[0] == 1) {
    c3_i = c3_in2_size[0];
  } else {
    c3_i = c3_in4_size[0];
  }

  c3_loop_ub = c3_i - 1;
  for (c3_i1 = 0; c3_i1 <= c3_loop_ub; c3_i1++) {
    c3_b_in2_data[c3_i1] = c3_in2_data[c3_aux_0_0] -
      c3_in3[c3_in4_data[c3_aux_1_0] - 1];
    c3_aux_1_0 += c3_stride_1_0;
    c3_aux_0_0 += c3_stride_0_0;
  }

  c3_in1_size[0] = c3_b_in2_size[0];
  c3_b_loop_ub = c3_b_in2_size[0] - 1;
  for (c3_i2 = 0; c3_i2 <= c3_b_loop_ub; c3_i2++) {
    c3_in1_data[c3_i2] = c3_b_in2_data[c3_i2];
  }
}

static void c3_minus(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
                     real_T c3_in1_data[], int32_T c3_in1_size[1], real_T
                     c3_in2_data[], int32_T c3_in2_size[1])
{
  real_T c3_b_in1_data[4];
  int32_T c3_b_in1_size[1];
  int32_T c3_aux_0_0;
  int32_T c3_aux_1_0;
  int32_T c3_b_loop_ub;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_loop_ub;
  int32_T c3_stride_0_0;
  int32_T c3_stride_1_0;
  (void)chartInstance;
  if (c3_in2_size[0] == 1) {
    c3_b_in1_size[0] = c3_in1_size[0];
  } else {
    c3_b_in1_size[0] = c3_in2_size[0];
  }

  c3_stride_0_0 = (c3_in1_size[0] != 1);
  c3_stride_1_0 = (c3_in2_size[0] != 1);
  c3_aux_0_0 = 0;
  c3_aux_1_0 = 0;
  if (c3_in2_size[0] == 1) {
    c3_i = c3_in1_size[0];
  } else {
    c3_i = c3_in2_size[0];
  }

  c3_loop_ub = c3_i - 1;
  for (c3_i1 = 0; c3_i1 <= c3_loop_ub; c3_i1++) {
    c3_b_in1_data[c3_i1] = c3_in1_data[c3_aux_0_0] - c3_in2_data[c3_aux_1_0];
    c3_aux_1_0 += c3_stride_1_0;
    c3_aux_0_0 += c3_stride_0_0;
  }

  c3_in1_size[0] = c3_b_in1_size[0];
  c3_b_loop_ub = c3_b_in1_size[0] - 1;
  for (c3_i2 = 0; c3_i2 <= c3_b_loop_ub; c3_i2++) {
    c3_in1_data[c3_i2] = c3_b_in1_data[c3_i2];
  }
}

static void c3_d_binary_expand_op(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance, real_T c3_in1_data[], int32_T c3_in1_size[1], real_T
  c3_in2_data[], int32_T c3_in2_size[1], real_T c3_in3[4], int32_T c3_in4_data[],
  int32_T c3_in4_size[1])
{
  real_T c3_b_in2_data[4];
  int32_T c3_b_in2_size[1];
  int32_T c3_aux_0_0;
  int32_T c3_aux_1_0;
  int32_T c3_b_loop_ub;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_loop_ub;
  int32_T c3_stride_0_0;
  int32_T c3_stride_1_0;
  (void)chartInstance;
  if (c3_in4_size[0] == 1) {
    c3_b_in2_size[0] = c3_in2_size[0];
  } else {
    c3_b_in2_size[0] = c3_in4_size[0];
  }

  c3_stride_0_0 = (c3_in2_size[0] != 1);
  c3_stride_1_0 = (c3_in4_size[0] != 1);
  c3_aux_0_0 = 0;
  c3_aux_1_0 = 0;
  if (c3_in4_size[0] == 1) {
    c3_i = c3_in2_size[0];
  } else {
    c3_i = c3_in4_size[0];
  }

  c3_loop_ub = c3_i - 1;
  for (c3_i1 = 0; c3_i1 <= c3_loop_ub; c3_i1++) {
    c3_b_in2_data[c3_i1] = c3_in2_data[c3_aux_0_0] +
      c3_in3[c3_in4_data[c3_aux_1_0] - 1];
    c3_aux_1_0 += c3_stride_1_0;
    c3_aux_0_0 += c3_stride_0_0;
  }

  c3_in1_size[0] = c3_b_in2_size[0];
  c3_b_loop_ub = c3_b_in2_size[0] - 1;
  for (c3_i2 = 0; c3_i2 <= c3_b_loop_ub; c3_i2++) {
    c3_in1_data[c3_i2] = c3_b_in2_data[c3_i2];
  }
}

static void c3_e_binary_expand_op(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance, real_T c3_in1_data[], int32_T c3_in1_size[1], real_T
  c3_in2_data[], int32_T c3_in2_size[1], real_T c3_in3[4], int32_T c3_in4_data[],
  int32_T c3_in4_size[1])
{
  real_T c3_b_in2_data[4];
  int32_T c3_b_in2_size[1];
  int32_T c3_aux_0_0;
  int32_T c3_aux_1_0;
  int32_T c3_b_loop_ub;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_loop_ub;
  int32_T c3_stride_0_0;
  int32_T c3_stride_1_0;
  (void)chartInstance;
  if (c3_in4_size[0] == 1) {
    c3_b_in2_size[0] = c3_in2_size[0];
  } else {
    c3_b_in2_size[0] = c3_in4_size[0];
  }

  c3_stride_0_0 = (c3_in2_size[0] != 1);
  c3_stride_1_0 = (c3_in4_size[0] != 1);
  c3_aux_0_0 = 0;
  c3_aux_1_0 = 0;
  if (c3_in4_size[0] == 1) {
    c3_i = c3_in2_size[0];
  } else {
    c3_i = c3_in4_size[0];
  }

  c3_loop_ub = c3_i - 1;
  for (c3_i1 = 0; c3_i1 <= c3_loop_ub; c3_i1++) {
    c3_b_in2_data[c3_i1] = c3_in2_data[c3_aux_0_0] + 0.0001 *
      c3_in3[c3_in4_data[c3_aux_1_0] - 1];
    c3_aux_1_0 += c3_stride_1_0;
    c3_aux_0_0 += c3_stride_0_0;
  }

  c3_in1_size[0] = c3_b_in2_size[0];
  c3_b_loop_ub = c3_b_in2_size[0] - 1;
  for (c3_i2 = 0; c3_i2 <= c3_b_loop_ub; c3_i2++) {
    c3_in1_data[c3_i2] = c3_b_in2_data[c3_i2];
  }
}

static void c3_f_binary_expand_op(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance, real_T c3_in1_data[], int32_T c3_in1_size[1], real_T c3_in2[4],
  int32_T c3_in3_data[], int32_T c3_in3_size[1], real_T c3_in4_data[], int32_T
  c3_in4_size[1])
{
  real_T c3_in2_data[4];
  int32_T c3_in2_size[1];
  int32_T c3_aux_0_0;
  int32_T c3_aux_1_0;
  int32_T c3_b_loop_ub;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_loop_ub;
  int32_T c3_stride_0_0;
  int32_T c3_stride_1_0;
  (void)chartInstance;
  if (c3_in4_size[0] == 1) {
    c3_in2_size[0] = c3_in3_size[0];
  } else {
    c3_in2_size[0] = c3_in4_size[0];
  }

  c3_stride_0_0 = (c3_in3_size[0] != 1);
  c3_stride_1_0 = (c3_in4_size[0] != 1);
  c3_aux_0_0 = 0;
  c3_aux_1_0 = 0;
  if (c3_in4_size[0] == 1) {
    c3_i = c3_in3_size[0];
  } else {
    c3_i = c3_in4_size[0];
  }

  c3_loop_ub = c3_i - 1;
  for (c3_i1 = 0; c3_i1 <= c3_loop_ub; c3_i1++) {
    c3_in2_data[c3_i1] = (c3_in2[c3_in3_data[c3_aux_0_0] - 1] + 1.0) -
      c3_in4_data[c3_aux_1_0];
    c3_aux_1_0 += c3_stride_1_0;
    c3_aux_0_0 += c3_stride_0_0;
  }

  c3_in1_size[0] = c3_in2_size[0];
  c3_b_loop_ub = c3_in2_size[0] - 1;
  for (c3_i2 = 0; c3_i2 <= c3_b_loop_ub; c3_i2++) {
    c3_in1_data[c3_i2] = c3_in2_data[c3_i2];
  }
}

static void c3_g_binary_expand_op(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance, real_T c3_in1_data[], int32_T c3_in1_size[1], real_T c3_in2[4],
  int32_T c3_in3_data[], int32_T c3_in3_size[1], real_T c3_in4_data[], int32_T
  c3_in4_size[1])
{
  real_T c3_in2_data[4];
  int32_T c3_in2_size[1];
  int32_T c3_aux_0_0;
  int32_T c3_aux_1_0;
  int32_T c3_b_loop_ub;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_loop_ub;
  int32_T c3_stride_0_0;
  int32_T c3_stride_1_0;
  (void)chartInstance;
  if (c3_in4_size[0] == 1) {
    c3_in2_size[0] = c3_in3_size[0];
  } else {
    c3_in2_size[0] = c3_in4_size[0];
  }

  c3_stride_0_0 = (c3_in3_size[0] != 1);
  c3_stride_1_0 = (c3_in4_size[0] != 1);
  c3_aux_0_0 = 0;
  c3_aux_1_0 = 0;
  if (c3_in4_size[0] == 1) {
    c3_i = c3_in3_size[0];
  } else {
    c3_i = c3_in4_size[0];
  }

  c3_loop_ub = c3_i - 1;
  for (c3_i1 = 0; c3_i1 <= c3_loop_ub; c3_i1++) {
    c3_in2_data[c3_i1] = c3_in2[c3_in3_data[c3_aux_0_0] - 1] *
      c3_in4_data[c3_aux_1_0];
    c3_aux_1_0 += c3_stride_1_0;
    c3_aux_0_0 += c3_stride_0_0;
  }

  c3_in1_size[0] = c3_in2_size[0];
  c3_b_loop_ub = c3_in2_size[0] - 1;
  for (c3_i2 = 0; c3_i2 <= c3_b_loop_ub; c3_i2++) {
    c3_in1_data[c3_i2] = c3_in2_data[c3_i2];
  }
}

static void c3_h_binary_expand_op(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance, real_T c3_in1_data[], int32_T c3_in1_size[1], real_T
  c3_in2_data[], int32_T c3_in2_size[1], real_T c3_in3[4], int32_T c3_in4_data[],
  int32_T c3_in4_size[1])
{
  real_T c3_b_in2_data[4];
  int32_T c3_b_in2_size[1];
  int32_T c3_aux_0_0;
  int32_T c3_aux_1_0;
  int32_T c3_b_loop_ub;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_loop_ub;
  int32_T c3_stride_0_0;
  int32_T c3_stride_1_0;
  (void)chartInstance;
  if (c3_in4_size[0] == 1) {
    c3_b_in2_size[0] = c3_in2_size[0];
  } else {
    c3_b_in2_size[0] = c3_in4_size[0];
  }

  c3_stride_0_0 = (c3_in2_size[0] != 1);
  c3_stride_1_0 = (c3_in4_size[0] != 1);
  c3_aux_0_0 = 0;
  c3_aux_1_0 = 0;
  if (c3_in4_size[0] == 1) {
    c3_i = c3_in2_size[0];
  } else {
    c3_i = c3_in4_size[0];
  }

  c3_loop_ub = c3_i - 1;
  for (c3_i1 = 0; c3_i1 <= c3_loop_ub; c3_i1++) {
    c3_b_in2_data[c3_i1] = c3_in2_data[c3_aux_0_0] *
      c3_in3[c3_in4_data[c3_aux_1_0] - 1];
    c3_aux_1_0 += c3_stride_1_0;
    c3_aux_0_0 += c3_stride_0_0;
  }

  c3_in1_size[0] = c3_b_in2_size[0];
  c3_b_loop_ub = c3_b_in2_size[0] - 1;
  for (c3_i2 = 0; c3_i2 <= c3_b_loop_ub; c3_i2++) {
    c3_in1_data[c3_i2] = c3_b_in2_data[c3_i2];
  }
}

static void c3_b_minus(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
  real_T c3_in1_data[], int32_T c3_in1_size[2], real_T c3_in2_data[], int32_T
  c3_in2_size[2])
{
  real_T c3_b_in1_data[1];
  int32_T c3_b_in1_size[2];
  int32_T c3_aux_0_1;
  int32_T c3_aux_1_1;
  int32_T c3_b_loop_ub;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_loop_ub;
  int32_T c3_stride_0_1;
  int32_T c3_stride_1_1;
  (void)chartInstance;
  if (c3_in2_size[1] == 1) {
    c3_b_in1_size[1] = c3_in1_size[1];
  } else {
    c3_b_in1_size[1] = c3_in2_size[1];
  }

  c3_stride_0_1 = (c3_in1_size[1] != 1);
  c3_stride_1_1 = (c3_in2_size[1] != 1);
  c3_aux_0_1 = 0;
  c3_aux_1_1 = 0;
  if (c3_in2_size[1] == 1) {
    c3_i = c3_in1_size[1];
  } else {
    c3_i = c3_in2_size[1];
  }

  c3_loop_ub = c3_i - 1;
  for (c3_i1 = 0; c3_i1 <= c3_loop_ub; c3_i1++) {
    c3_b_in1_data[c3_i1] = c3_in1_data[c3_aux_0_1] - c3_in2_data[c3_aux_1_1];
    c3_aux_1_1 += c3_stride_1_1;
    c3_aux_0_1 += c3_stride_0_1;
  }

  c3_in1_size[0] = 1;
  c3_in1_size[1] = c3_b_in1_size[1];
  c3_b_loop_ub = c3_b_in1_size[1] - 1;
  for (c3_i2 = 0; c3_i2 <= c3_b_loop_ub; c3_i2++) {
    c3_in1_data[c3_i2] = c3_b_in1_data[c3_i2];
  }
}

static void c3_b_rdivide(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
  real_T c3_in1_data[], int32_T c3_in1_size[2], real_T c3_in2_data[], int32_T
  c3_in2_size[2])
{
  real_T c3_b_in1_data[1];
  int32_T c3_b_in1_size[2];
  int32_T c3_aux_0_1;
  int32_T c3_aux_1_1;
  int32_T c3_b_loop_ub;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_loop_ub;
  int32_T c3_stride_0_1;
  int32_T c3_stride_1_1;
  (void)chartInstance;
  if (c3_in2_size[1] == 1) {
    c3_b_in1_size[1] = c3_in1_size[1];
  } else {
    c3_b_in1_size[1] = c3_in2_size[1];
  }

  c3_stride_0_1 = (c3_in1_size[1] != 1);
  c3_stride_1_1 = (c3_in2_size[1] != 1);
  c3_aux_0_1 = 0;
  c3_aux_1_1 = 0;
  if (c3_in2_size[1] == 1) {
    c3_i = c3_in1_size[1];
  } else {
    c3_i = c3_in2_size[1];
  }

  c3_loop_ub = c3_i - 1;
  for (c3_i1 = 0; c3_i1 <= c3_loop_ub; c3_i1++) {
    c3_b_in1_data[c3_i1] = c3_in1_data[c3_aux_0_1] / c3_in2_data[c3_aux_1_1];
    c3_aux_1_1 += c3_stride_1_1;
    c3_aux_0_1 += c3_stride_0_1;
  }

  c3_in1_size[0] = 1;
  c3_in1_size[1] = c3_b_in1_size[1];
  c3_b_loop_ub = c3_b_in1_size[1] - 1;
  for (c3_i2 = 0; c3_i2 <= c3_b_loop_ub; c3_i2++) {
    c3_in1_data[c3_i2] = c3_b_in1_data[c3_i2];
  }
}

static void c3_times(SFc3_vehdynlibtirecommonInstanceStruct *chartInstance,
                     real_T c3_in1_data[], int32_T c3_in1_size[2], real_T
                     c3_in2_data[], int32_T c3_in2_size[2])
{
  real_T c3_b_in1_data[1];
  int32_T c3_b_in1_size[2];
  int32_T c3_aux_0_1;
  int32_T c3_aux_1_1;
  int32_T c3_b_loop_ub;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_loop_ub;
  int32_T c3_stride_0_1;
  int32_T c3_stride_1_1;
  (void)chartInstance;
  if (c3_in2_size[1] == 1) {
    c3_b_in1_size[1] = c3_in1_size[1];
  } else {
    c3_b_in1_size[1] = c3_in2_size[1];
  }

  c3_stride_0_1 = (c3_in1_size[1] != 1);
  c3_stride_1_1 = (c3_in2_size[1] != 1);
  c3_aux_0_1 = 0;
  c3_aux_1_1 = 0;
  if (c3_in2_size[1] == 1) {
    c3_i = c3_in1_size[1];
  } else {
    c3_i = c3_in2_size[1];
  }

  c3_loop_ub = c3_i - 1;
  for (c3_i1 = 0; c3_i1 <= c3_loop_ub; c3_i1++) {
    c3_b_in1_data[c3_i1] = c3_in1_data[c3_aux_0_1] * c3_in2_data[c3_aux_1_1];
    c3_aux_1_1 += c3_stride_1_1;
    c3_aux_0_1 += c3_stride_0_1;
  }

  c3_in1_size[0] = 1;
  c3_in1_size[1] = c3_b_in1_size[1];
  c3_b_loop_ub = c3_b_in1_size[1] - 1;
  for (c3_i2 = 0; c3_i2 <= c3_b_loop_ub; c3_i2++) {
    c3_in1_data[c3_i2] = c3_b_in1_data[c3_i2];
  }
}

static void init_dsm_address_info(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc3_vehdynlibtirecommonInstanceStruct
  *chartInstance)
{
  chartInstance->c3_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c3_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c3_Omega = (real_T (*)[4])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c3_Vx = (real_T (*)[4])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_Vy = (real_T (*)[4])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c3_psidot = (real_T (*)[4])ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c3_Gamma = (real_T (*)[4])ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c3_TirePrs = (real_T (*)[4])ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c3_ScaleFactors = (real_T (*)[108])ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c3_rhoz = (real_T (*)[4])ssGetInputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c3_Fx = (real_T (*)[4])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_Fy = (real_T (*)[4])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c3_FzTire = (real_T (*)[4])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c3_Mx = (real_T (*)[4])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c3_My = (real_T (*)[4])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c3_Mz = (real_T (*)[4])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c3_Re = (real_T (*)[4])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c3_Kappa = (real_T (*)[4])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c3_Alpha = (real_T (*)[4])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 9);
  chartInstance->c3_sig_x = (real_T (*)[4])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 10);
  chartInstance->c3_sig_y = (real_T (*)[4])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 11);
  chartInstance->c3_a = (real_T (*)[4])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 12);
  chartInstance->c3_b = (real_T (*)[4])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 13);
  chartInstance->c3_Fx_ext = (real_T (*)[4])ssGetInputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c3_Fy_ext = (real_T (*)[4])ssGetInputPortSignal_wrapper
    (chartInstance->S, 9);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c3_vehdynlibtirecommon_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2191560757U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1601078755U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(610085067U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(352275795U);
}

mxArray *sf_c3_vehdynlibtirecommon_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_vehdynlibtirecommon_jit_fallback_info(void)
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

mxArray *sf_c3_vehdynlibtirecommon_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c3_vehdynlibtirecommon(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiBW4GZgYAPSHEDMxAABrFA+I1QNI1ycBS6uAMQllQWpIPHiomTPFCCdl5gL5ie"
    "WVnjmpeWD9VowIMxnw2I+I5L5nFBxCPhgT5l+Mwd0/SxY9LMi6ReA8h1zCjISoX6HhdPA+SMO7A"
    "8DAv5gQvEHE4NbxSBxvwOZ7q8cLOEvQFQ6YkNLRyC+W1VIZlHqYPGHKdn5wTuxoGDQ5AeHWLLSk"
    "+9gyQ8NZLp/sOSHA2S6v2qQuD+gjCz3Bw2WfHyggSj3M6K4n5Fh0OTfE+S5P2mwuF+ikexytDgz"
    "Pb5isPhDgTJ/VFLNHwoOlOmH2B9AwB8KaP4A8TOL4xOTSzLLUuOTjePLUjNSKvNyMpNKgHV2cn5"
    "ubn4ezH8APLBWzw=="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_vehdynlibtirecommon_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sQodmGbbwq0HrbUGKPJAB4";
}

static void sf_opaque_initialize_c3_vehdynlibtirecommon(void *chartInstanceVar)
{
  initialize_params_c3_vehdynlibtirecommon
    ((SFc3_vehdynlibtirecommonInstanceStruct*) chartInstanceVar);
  initialize_c3_vehdynlibtirecommon((SFc3_vehdynlibtirecommonInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_vehdynlibtirecommon(void *chartInstanceVar)
{
  enable_c3_vehdynlibtirecommon((SFc3_vehdynlibtirecommonInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c3_vehdynlibtirecommon(void *chartInstanceVar)
{
  disable_c3_vehdynlibtirecommon((SFc3_vehdynlibtirecommonInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c3_vehdynlibtirecommon(void *chartInstanceVar)
{
  sf_gateway_c3_vehdynlibtirecommon((SFc3_vehdynlibtirecommonInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c3_vehdynlibtirecommon(SimStruct*
  S)
{
  return get_sim_state_c3_vehdynlibtirecommon
    ((SFc3_vehdynlibtirecommonInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_vehdynlibtirecommon(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c3_vehdynlibtirecommon((SFc3_vehdynlibtirecommonInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c3_vehdynlibtirecommon(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_vehdynlibtirecommonInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_vehdynlibtirecommon_optimization_info();
    }

    mdl_cleanup_runtime_resources_c3_vehdynlibtirecommon
      ((SFc3_vehdynlibtirecommonInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c3_vehdynlibtirecommon(void *chartInstanceVar)
{
  mdl_start_c3_vehdynlibtirecommon((SFc3_vehdynlibtirecommonInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_mdl_terminate_c3_vehdynlibtirecommon(void
  *chartInstanceVar)
{
  mdl_terminate_c3_vehdynlibtirecommon((SFc3_vehdynlibtirecommonInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_vehdynlibtirecommon((SFc3_vehdynlibtirecommonInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_vehdynlibtirecommon(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  sf_warn_if_symbolic_dimension_param_changed(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_vehdynlibtirecommon
      ((SFc3_vehdynlibtirecommonInstanceStruct*)sf_get_chart_instance_ptr(S));
    initSimStructsc3_vehdynlibtirecommon((SFc3_vehdynlibtirecommonInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c3_vehdynlibtirecommon_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [24] = {
    "eNrtWc1v40QUn1Tdiv2qegIOSEScEBJS2WURBwRp89EN29CwSYuEWKqJ/RKPYo/dmXE+Kg7LnTN",
    "/CuK43PbAgeP+BZw5InHhje1kUzdsPA6760VYct2x/Zv3fs/vayak1GwRPLbxfPwOIVt4fQ3PDR",
    "IfV5JxaeGM72+ST5Lxd9cJsXwbBsA7Yb/PJsTs4KHXpoJ6kpgfnHpwH6Tvhor5vMn7fnYs430Qw",
    "C2cIPCFMpIrmRe6jA8bIbe0ZPmVwyyn4/iha+/jhNQ+4u70n+QGoWqjxBoTYKkGgK0c4YcDp+HS",
    "wbOtINS46oA1lKFnbCsJqhMGmqpsha5igQv1CVhNLhVFK8gVfDuKKqiqiZmRNV/ZmaF9L3AZ5dl",
    "t7VDZgQC9Q8FxYOPfo1Ch9TJhLYcKtQ8OHYE8ZMNIus8hk3Qm8e0e41T5glG37rlVPVtGvm0XOb",
    "YwJFzTb4R89wXQYeAzrgwDotNAO9c57blQg144MJTbgbNQR8MJgzEIs+/br/ojEHQAR9xM5+gb1",
    "SeRU85jKSNWMQ9OqNiz0Hcl2GZ5A4NOdii6I3RxGiMsRCZuyq5gI/QN01zX1OGfK9eFXuz9Mhc2",
    "klsfgbFfzeU2LF6lrivNsF0/OIQRuJH8GlU0BzaWbwCWktldH71DZxvDjBVyhpGQYKs+t1l2rxy",
    "lUFFh+wKLVAY483QYgI1mnqs+n2hVHIVS+V4VU07t8DCjvMvYJlcg+tSCzDVGUCYBFY78ylCuza",
    "QOJESjlVTEMvMMcQzmghLZD3lt7Ish2ti0mD21lY4EMzTYA0zMCqIkV0fvPqFumFFnTw4wftA9j",
    "iVmWTO5iNXxkwtsUcsBW1dO5kIL8yxOkPUTS13y95DtiKlpDaQlWJA1kkJM6Fh0tZW60wCO+ZD7",
    "Y94QvtdJOq9n+BUAZg0qOOODfSzhYtpA5bNpLeCsG2V30yZH25kql/a0bxwAx2qouequgVoYVXW",
    "OLTIqtA62w86xieGSSYWFehqX+rju6f79Lnnav28u6d9fX+jfd5Kxdft0BI495S7rKd2O+p6nk4",
    "2eb3dhvhsZ1gO/kNU4cglH5vrPru8u4EtL5JKFq36/svD+1Y2L719LyduY3Zsfy+e5mZK7mZpnK",
    "7Gh+PX31g/WE/Lg5933vvnprx/T/NP6lC7pU4r+17jfrputv7aT8VuzPmqetUeXElte/5Bf+rZ3",
    "0OuNz3bvit7xwb3253v7H8bzlVfou53Sd3a/rHs3DOooRwiraSfrOD2mYby+0NiPF/TdWmGPqwv",
    "+Rcgfn62H/6iSxi+z15WUvfR4zw0cmvLnl8fj20raH5fx2LjAY4M0JgXRv5JT/2lR7L+TyY+2Un",
    "6kx43zLmbjovC4kzse7tEgKEw8VB7k8qdWUeLhYU79ixIPj3Lqf14Q/dujXPrfL0ocP3qYSf/SB",
    "f1LpDDx+zif/r2i6P/m97nzqGSD00lReJTX4zH913iUK+vhY/ntFTzKKR7laM/zlOqVLZwuX0Et",
    "8su7HjDFkReMe1X0/N8uz59flv2BazlxN3PiyAvGrcvPdN/jVX//WXWcpN7fKTCP9DXv/lfReD0",
    "hZvtRbyfjT+e/v1Qd5tpLdoCTx4dA+8ue/kf8+09D+72RjOvafskP9V/f3uPUnUoWb1/PbreF/r",
    "11/kgAlcv31V9GPVm2n7qsr7qRim89HjNu+2P5/ge37txapz79DXK4Wqc=",
    ""
  };

  static char newstr [1709] = "";
  newstr[0] = '\0';
  for (i = 0; i < 24; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c3_vehdynlibtirecommon(SimStruct *S)
{
  const char* newstr = sf_c3_vehdynlibtirecommon_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(1306971250U));
  ssSetChecksum1(S,(14181260U));
  ssSetChecksum2(S,(707835997U));
  ssSetChecksum3(S,(2533078620U));
}

static void mdlRTW_c3_vehdynlibtirecommon(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c3_vehdynlibtirecommon(SimStruct *S)
{
  SFc3_vehdynlibtirecommonInstanceStruct *chartInstance;
  chartInstance = (SFc3_vehdynlibtirecommonInstanceStruct *)utMalloc(sizeof
    (SFc3_vehdynlibtirecommonInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc3_vehdynlibtirecommonInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_vehdynlibtirecommon;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_vehdynlibtirecommon;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c3_vehdynlibtirecommon;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c3_vehdynlibtirecommon;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c3_vehdynlibtirecommon;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_vehdynlibtirecommon;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c3_vehdynlibtirecommon;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_vehdynlibtirecommon;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_vehdynlibtirecommon;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_vehdynlibtirecommon;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_vehdynlibtirecommon;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_vehdynlibtirecommon;
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
    chartInstance->c3_JITStateAnimation,
    chartInstance->c3_JITTransitionAnimation);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c3_vehdynlibtirecommon(chartInstance);
}

void c3_vehdynlibtirecommon_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c3_vehdynlibtirecommon(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_vehdynlibtirecommon(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_vehdynlibtirecommon(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_vehdynlibtirecommon_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
