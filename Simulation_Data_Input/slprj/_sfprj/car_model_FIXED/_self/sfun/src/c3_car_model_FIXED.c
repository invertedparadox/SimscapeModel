/* Include files */

#include "car_model_FIXED_sfun.h"
#include "c3_car_model_FIXED.h"
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
#define c3_const_dIndex                (50.0)
#define CALL_EVENT                     (-1)
#define c3_b_dIndex                    (50.0)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtMCInfo c3_emlrtMCI = { 13, /* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pName */
};

static emlrtMCInfo c3_b_emlrtMCI = { 87,/* lineNo */
  33,                                  /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtMCInfo c3_c_emlrtMCI = { 82,/* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pName */
};

static emlrtMCInfo c3_d_emlrtMCI = { 13,/* lineNo */
  13,                                  /* colNo */
  "toLogicalCheck",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\toLogicalCheck.m"/* pName */
};

static emlrtMCInfo c3_e_emlrtMCI = { 14,/* lineNo */
  9,                                   /* colNo */
  "acos",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\elfun\\acos.m"/* pName */
};

static emlrtRSInfo c3_emlrtRSI = { 18, /* lineNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fcnName */
  "#car_model_FIXED:6421"              /* pathName */
};

static emlrtRSInfo c3_b_emlrtRSI = { 37,/* lineNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fcnName */
  "#car_model_FIXED:6421"              /* pathName */
};

static emlrtRSInfo c3_c_emlrtRSI = { 39,/* lineNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fcnName */
  "#car_model_FIXED:6421"              /* pathName */
};

static emlrtRSInfo c3_d_emlrtRSI = { 45,/* lineNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fcnName */
  "#car_model_FIXED:6421"              /* pathName */
};

static emlrtRSInfo c3_e_emlrtRSI = { 50,/* lineNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fcnName */
  "#car_model_FIXED:6421"              /* pathName */
};

static emlrtRSInfo c3_f_emlrtRSI = { 55,/* lineNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fcnName */
  "#car_model_FIXED:6421"              /* pathName */
};

static emlrtRSInfo c3_g_emlrtRSI = { 60,/* lineNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fcnName */
  "#car_model_FIXED:6421"              /* pathName */
};

static emlrtRSInfo c3_h_emlrtRSI = { 67,/* lineNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fcnName */
  "#car_model_FIXED:6421"              /* pathName */
};

static emlrtRSInfo c3_i_emlrtRSI = { 204,/* lineNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fcnName */
  "#car_model_FIXED:6421"              /* pathName */
};

static emlrtRSInfo c3_j_emlrtRSI = { 205,/* lineNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fcnName */
  "#car_model_FIXED:6421"              /* pathName */
};

static emlrtRSInfo c3_k_emlrtRSI = { 44,/* lineNo */
  "mpower",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\matfun\\mpower.m"/* pathName */
};

static emlrtRSInfo c3_l_emlrtRSI = { 71,/* lineNo */
  "power",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRSInfo c3_m_emlrtRSI = { 15,/* lineNo */
  "xdot",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xdot.m"/* pathName */
};

static emlrtRSInfo c3_n_emlrtRSI = { 32,/* lineNo */
  "xdotx",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xdotx.m"/* pathName */
};

static emlrtRSInfo c3_o_emlrtRSI = { 20,/* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRTEInfo c3_emlrtRTEI = { 25,/* lineNo */
  23,                                  /* colNo */
  "dot",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\specfun\\dot.m"/* pName */
};

static emlrtRTEInfo c3_b_emlrtRTEI = { 25,/* lineNo */
  43,                                  /* colNo */
  "dot",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\specfun\\dot.m"/* pName */
};

static emlrtBCInfo c3_emlrtBCI = { 1,  /* iFirst */
  4219,                                /* iLast */
  3,                                   /* lineNo */
  24,                                  /* colNo */
  "selected_track",                    /* aName */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_emlrtDCI = { 3,  /* lineNo */
  24,                                  /* colNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_b_emlrtBCI = { 1,/* iFirst */
  4219,                                /* iLast */
  4,                                   /* lineNo */
  24,                                  /* colNo */
  "selected_track",                    /* aName */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_b_emlrtDCI = { 4,/* lineNo */
  24,                                  /* colNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_c_emlrtBCI = { 1,/* iFirst */
  21,                                  /* iLast */
  6,                                   /* lineNo */
  27,                                  /* colNo */
  "selected_maxvm",                    /* aName */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_c_emlrtDCI = { 6,/* lineNo */
  27,                                  /* colNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_d_emlrtBCI = { 1,/* iFirst */
  21,                                  /* iLast */
  10,                                  /* lineNo */
  32,                                  /* colNo */
  "selected_maxvm",                    /* aName */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_d_emlrtDCI = { 10,/* lineNo */
  32,                                  /* colNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_e_emlrtBCI = { 1,/* iFirst */
  21,                                  /* iLast */
  11,                                  /* lineNo */
  29,                                  /* colNo */
  "selected_maxvm",                    /* aName */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_e_emlrtDCI = { 11,/* lineNo */
  29,                                  /* colNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_f_emlrtBCI = { 1,/* iFirst */
  4219,                                /* iLast */
  23,                                  /* lineNo */
  24,                                  /* colNo */
  "selected_track",                    /* aName */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_f_emlrtDCI = { 23,/* lineNo */
  24,                                  /* colNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_g_emlrtBCI = { 1,/* iFirst */
  4219,                                /* iLast */
  24,                                  /* lineNo */
  24,                                  /* colNo */
  "selected_track",                    /* aName */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_g_emlrtDCI = { 24,/* lineNo */
  24,                                  /* colNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_h_emlrtBCI = { 1,/* iFirst */
  4219,                                /* iLast */
  25,                                  /* lineNo */
  29,                                  /* colNo */
  "selected_track",                    /* aName */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_h_emlrtDCI = { 25,/* lineNo */
  29,                                  /* colNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_i_emlrtBCI = { 1,/* iFirst */
  4219,                                /* iLast */
  26,                                  /* lineNo */
  29,                                  /* colNo */
  "selected_track",                    /* aName */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_i_emlrtDCI = { 26,/* lineNo */
  29,                                  /* colNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_j_emlrtBCI = { 1,/* iFirst */
  4219,                                /* iLast */
  27,                                  /* lineNo */
  24,                                  /* colNo */
  "selected_track",                    /* aName */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_j_emlrtDCI = { 27,/* lineNo */
  24,                                  /* colNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_k_emlrtBCI = { 1,/* iFirst */
  4219,                                /* iLast */
  28,                                  /* lineNo */
  29,                                  /* colNo */
  "selected_track",                    /* aName */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_k_emlrtDCI = { 28,/* lineNo */
  29,                                  /* colNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_l_emlrtBCI = { 1,/* iFirst */
  4219,                                /* iLast */
  29,                                  /* lineNo */
  25,                                  /* colNo */
  "selected_track",                    /* aName */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_l_emlrtDCI = { 29,/* lineNo */
  25,                                  /* colNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_m_emlrtBCI = { 1,/* iFirst */
  4219,                                /* iLast */
  30,                                  /* lineNo */
  27,                                  /* colNo */
  "selected_track",                    /* aName */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_m_emlrtDCI = { 30,/* lineNo */
  27,                                  /* colNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_n_emlrtBCI = { 1,/* iFirst */
  4219,                                /* iLast */
  31,                                  /* lineNo */
  32,                                  /* colNo */
  "selected_track",                    /* aName */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_n_emlrtDCI = { 31,/* lineNo */
  32,                                  /* colNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_o_emlrtBCI = { 1,/* iFirst */
  4219,                                /* iLast */
  32,                                  /* lineNo */
  28,                                  /* colNo */
  "selected_track",                    /* aName */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_o_emlrtDCI = { 32,/* lineNo */
  28,                                  /* colNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_p_emlrtBCI = { 1,/* iFirst */
  4219,                                /* iLast */
  33,                                  /* lineNo */
  26,                                  /* colNo */
  "selected_track",                    /* aName */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_p_emlrtDCI = { 33,/* lineNo */
  26,                                  /* colNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_q_emlrtBCI = { 1,/* iFirst */
  4219,                                /* iLast */
  34,                                  /* lineNo */
  25,                                  /* colNo */
  "selected_track",                    /* aName */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_q_emlrtDCI = { 34,/* lineNo */
  25,                                  /* colNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_r_emlrtBCI = { 1,/* iFirst */
  27,                                  /* iLast */
  172,                                 /* lineNo */
  33,                                  /* colNo */
  "indicies",                          /* aName */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_r_emlrtDCI = { 172,/* lineNo */
  33,                                  /* colNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_s_emlrtBCI = { 1,/* iFirst */
  27,                                  /* iLast */
  179,                                 /* lineNo */
  17,                                  /* colNo */
  "indicies",                          /* aName */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_s_emlrtDCI = { 179,/* lineNo */
  17,                                  /* colNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_t_emlrtBCI = { 1,/* iFirst */
  27,                                  /* iLast */
  173,                                 /* lineNo */
  18,                                  /* colNo */
  "indicies",                          /* aName */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_t_emlrtDCI = { 173,/* lineNo */
  18,                                  /* colNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_u_emlrtBCI = { 1,/* iFirst */
  27,                                  /* iLast */
  179,                                 /* lineNo */
  38,                                  /* colNo */
  "indicies",                          /* aName */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_u_emlrtDCI = { 179,/* lineNo */
  38,                                  /* colNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_v_emlrtBCI = { 1,/* iFirst */
  27,                                  /* iLast */
  173,                                 /* lineNo */
  36,                                  /* colNo */
  "indicies",                          /* aName */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_v_emlrtDCI = { 173,/* lineNo */
  36,                                  /* colNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_w_emlrtBCI = { 1,/* iFirst */
  27,                                  /* iLast */
  173,                                 /* lineNo */
  54,                                  /* colNo */
  "indicies",                          /* aName */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_w_emlrtDCI = { 173,/* lineNo */
  54,                                  /* colNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_x_emlrtBCI = { 1,/* iFirst */
  27,                                  /* iLast */
  173,                                 /* lineNo */
  72,                                  /* colNo */
  "indicies",                          /* aName */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_x_emlrtDCI = { 173,/* lineNo */
  72,                                  /* colNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_y_emlrtBCI = { 1,/* iFirst */
  27,                                  /* iLast */
  181,                                 /* lineNo */
  21,                                  /* colNo */
  "indicies",                          /* aName */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_y_emlrtDCI = { 181,/* lineNo */
  21,                                  /* colNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_ab_emlrtBCI = { 1,/* iFirst */
  27,                                  /* iLast */
  187,                                 /* lineNo */
  17,                                  /* colNo */
  "indicies",                          /* aName */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_ab_emlrtDCI = { 187,/* lineNo */
  17,                                  /* colNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_bb_emlrtBCI = { 1,/* iFirst */
  27,                                  /* iLast */
  173,                                 /* lineNo */
  90,                                  /* colNo */
  "indicies",                          /* aName */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_bb_emlrtDCI = { 173,/* lineNo */
  90,                                  /* colNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_cb_emlrtBCI = { 1,/* iFirst */
  27,                                  /* iLast */
  173,                                 /* lineNo */
  108,                                 /* colNo */
  "indicies",                          /* aName */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_cb_emlrtDCI = { 173,/* lineNo */
  108,                                 /* colNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_db_emlrtBCI = { 1,/* iFirst */
  27,                                  /* iLast */
  187,                                 /* lineNo */
  38,                                  /* colNo */
  "indicies",                          /* aName */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_db_emlrtDCI = { 187,/* lineNo */
  38,                                  /* colNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_eb_emlrtBCI = { 1,/* iFirst */
  27,                                  /* iLast */
  189,                                 /* lineNo */
  21,                                  /* colNo */
  "indicies",                          /* aName */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_eb_emlrtDCI = { 189,/* lineNo */
  21,                                  /* colNo */
  "Driver & Environment/Reference Generator/Reference Geneator",/* fName */
  "#car_model_FIXED:6421",             /* pName */
  1                                    /* checkKind */
};

static char_T c3_cv[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
  'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n', 'E',
  'r', 'r', 'o', 'r' };

/* Function Declarations */
static void initialize_c3_car_model_FIXED(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance);
static void initialize_params_c3_car_model_FIXED
  (SFc3_car_model_FIXEDInstanceStruct *chartInstance);
static void mdl_start_c3_car_model_FIXED(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance);
static void mdl_terminate_c3_car_model_FIXED(SFc3_car_model_FIXEDInstanceStruct *
  chartInstance);
static void mdl_setup_runtime_resources_c3_car_model_FIXED
  (SFc3_car_model_FIXEDInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c3_car_model_FIXED
  (SFc3_car_model_FIXEDInstanceStruct *chartInstance);
static void enable_c3_car_model_FIXED(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance);
static void disable_c3_car_model_FIXED(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance);
static void sf_gateway_c3_car_model_FIXED(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance);
static void ext_mode_exec_c3_car_model_FIXED(SFc3_car_model_FIXEDInstanceStruct *
  chartInstance);
static void c3_update_jit_animation_c3_car_model_FIXED
  (SFc3_car_model_FIXEDInstanceStruct *chartInstance);
static void c3_do_animation_call_c3_car_model_FIXED
  (SFc3_car_model_FIXEDInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_car_model_FIXED
  (SFc3_car_model_FIXEDInstanceStruct *chartInstance);
static void set_sim_state_c3_car_model_FIXED(SFc3_car_model_FIXEDInstanceStruct *
  chartInstance, const mxArray *c3_st);
static void initSimStructsc3_car_model_FIXED(SFc3_car_model_FIXEDInstanceStruct *
  chartInstance);
static real_T c3_emlrt_update_log_1(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c3_in, emlrtLocationLoggingDataType c3_table[], int32_T
  c3_index);
static c3_slBus15_Vel c3_emlrt_update_log_2(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, c3_slBus15_Vel c3_in, emlrtLocationLoggingDataType c3_table[],
  int32_T c3_index);
static c3_Disp c3_emlrt_update_log_3(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, c3_Disp c3_in, emlrtLocationLoggingDataType c3_table[],
  int32_T c3_index);
static void c3_emlrt_update_log_4(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c3_in[4], emlrtLocationLoggingDataType c3_table[],
  int32_T c3_index, real_T c3_out[4]);
static void c3_emlrt_update_log_5(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c3_in[37971], emlrtLocationLoggingDataType c3_table[],
  int32_T c3_index, real_T c3_out[37971]);
static void c3_emlrt_update_log_6(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c3_in[27], emlrtLocationLoggingDataType c3_table[],
  int32_T c3_index, real_T c3_out[27]);
static void c3_emlrt_update_log_7(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c3_in[63], emlrtLocationLoggingDataType c3_table[],
  int32_T c3_index, real_T c3_out[63]);
static void c3_emlrt_update_log_8(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c3_in[51], emlrtLocationLoggingDataType c3_table[],
  int32_T c3_index, real_T c3_out[51]);
static void c3_emlrt_update_log_9(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c3_in[2], emlrtLocationLoggingDataType c3_table[],
  int32_T c3_index, real_T c3_out[2]);
static void c3_emlrtInitVarDataTables(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, emlrtLocationLoggingDataType c3_dataTables[195],
  emlrtLocationLoggingHistogramType c3_histTables[195]);
static void c3_sqrt(SFc3_car_model_FIXEDInstanceStruct *chartInstance, const
                    emlrtStack *c3_sp, real_T c3_x[51], real_T c3_b_x[51]);
static void c3_minimum(SFc3_car_model_FIXEDInstanceStruct *chartInstance, real_T
  c3_x[51], real_T *c3_ex, int32_T *c3_idx);
static real_T c3_b_sqrt(SFc3_car_model_FIXEDInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, real_T c3_x);
static real_T c3_dot(SFc3_car_model_FIXEDInstanceStruct *chartInstance, real_T
                     c3_a[2], real_T c3_b[2]);
static real_T c3_norm(SFc3_car_model_FIXEDInstanceStruct *chartInstance, real_T
                      c3_x[2]);
static real_T c3_acos(SFc3_car_model_FIXEDInstanceStruct *chartInstance, const
                      emlrtStack *c3_sp, real_T c3_x);
static real_T c3_emlrt_marshallIn(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c3_b_Vnow, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_emlrt_marshallIn(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c3_c_omega, const char_T *c3_identifier, real_T
  c3_y[4]);
static void c3_d_emlrt_marshallIn(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[4]);
static uint8_T c3_e_emlrt_marshallIn(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_car_model_FIXED, const char_T
  *c3_identifier);
static uint8_T c3_f_emlrt_marshallIn(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_slStringInitializeDynamicBuffers
  (SFc3_car_model_FIXEDInstanceStruct *chartInstance);
static void c3_chart_data_browse_helper(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, int32_T c3_ssIdNumber, const mxArray **c3_mxData, uint8_T
  *c3_isValueTooBig);
static void c3_b_emlrt_update_log_2(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, c3_slBus15_Vel *c3_in, emlrtLocationLoggingDataType c3_table[],
  int32_T c3_index);
static void c3_b_emlrt_update_log_3(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, c3_Disp *c3_in, emlrtLocationLoggingDataType c3_table[],
  int32_T c3_index);
static void c3_b_emlrt_update_log_4(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c3_in[4], emlrtLocationLoggingDataType c3_table[],
  int32_T c3_index);
static void c3_b_emlrt_update_log_5(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c3_in[37971], emlrtLocationLoggingDataType c3_table[],
  int32_T c3_index);
static void c3_b_emlrt_update_log_6(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c3_in[27], emlrtLocationLoggingDataType c3_table[],
  int32_T c3_index);
static void c3_b_emlrt_update_log_7(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c3_in[63], emlrtLocationLoggingDataType c3_table[],
  int32_T c3_index);
static void c3_b_emlrt_update_log_8(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c3_in[51], emlrtLocationLoggingDataType c3_table[],
  int32_T c3_index);
static void c3_b_emlrt_update_log_9(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c3_in[2], emlrtLocationLoggingDataType c3_table[],
  int32_T c3_index);
static void c3_c_sqrt(SFc3_car_model_FIXEDInstanceStruct *chartInstance, const
                      emlrtStack *c3_sp, real_T c3_x[51]);
static void c3_d_sqrt(SFc3_car_model_FIXEDInstanceStruct *chartInstance, const
                      emlrtStack *c3_sp, real_T *c3_x);
static void c3_b_acos(SFc3_car_model_FIXEDInstanceStruct *chartInstance, const
                      emlrtStack *c3_sp, real_T *c3_x);
static int32_T c3__s32_add__(SFc3_car_model_FIXEDInstanceStruct *chartInstance,
  int32_T c3_b, int32_T c3_c, int32_T c3_EMLOvCount_src_loc, uint32_T
  c3_ssid_src_loc, int32_T c3_offset_src_loc, int32_T c3_length_src_loc);
static int32_T c3__s32_minus__(SFc3_car_model_FIXEDInstanceStruct *chartInstance,
  int32_T c3_b, int32_T c3_c, int32_T c3_EMLOvCount_src_loc, uint32_T
  c3_ssid_src_loc, int32_T c3_offset_src_loc, int32_T c3_length_src_loc);
static void init_dsm_address_info(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_car_model_FIXED(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_is_active_c3_car_model_FIXED = 0U;
  chartInstance->c3_emlrtLocLogSimulated = false;
  c3_emlrtInitVarDataTables(chartInstance,
    chartInstance->c3_emlrtLocationLoggingDataTables,
    chartInstance->c3_emlrtLocLogHistTables);
}

static void initialize_params_c3_car_model_FIXED
  (SFc3_car_model_FIXEDInstanceStruct *chartInstance)
{
  real_T c3_dv2[63];
  real_T c3_dv1[27];
  real_T c3_d;
  real_T c3_d1;
  real_T c3_d2;
  real_T c3_d3;
  real_T c3_d4;
  real_T c3_d5;
  real_T c3_d6;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  sf_mex_import_named("deg2rad", sf_mex_get_sfun_param(chartInstance->S, 2U, 0U),
                      &c3_d, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_deg2rad = c3_d;
  sf_mex_import_named("selected_track", sf_mex_get_sfun_param(chartInstance->S,
    9U, 0U), chartInstance->c3_b_dv, 0, 0, 0U, 1, 0U, 2, 4219, 9);
  for (c3_i = 0; c3_i < 37971; c3_i++) {
    chartInstance->c3_selected_track[c3_i] = chartInstance->c3_b_dv[c3_i];
  }

  sf_mex_import_named("dIndex", sf_mex_get_sfun_param(chartInstance->S, 1U, 0U),
                      &c3_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_dIndex = c3_d1;
  sf_mex_import_named("dx", sf_mex_get_sfun_param(chartInstance->S, 3U, 0U),
                      &c3_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_dx = c3_d2;
  sf_mex_import_named("forward_look_straight", sf_mex_get_sfun_param
                      (chartInstance->S, 4U, 0U), &c3_d3, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_forward_look_straight = c3_d3;
  sf_mex_import_named("forward_look_turn", sf_mex_get_sfun_param
                      (chartInstance->S, 5U, 0U), &c3_d4, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_forward_look_turn = c3_d4;
  sf_mex_import_named("q_thresh", sf_mex_get_sfun_param(chartInstance->S, 7U, 0U),
                      &c3_d5, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_q_thresh = c3_d5;
  sf_mex_import_named("indicies", sf_mex_get_sfun_param(chartInstance->S, 6U, 0U),
                      c3_dv1, 0, 0, 0U, 1, 0U, 2, 1, 27);
  for (c3_i1 = 0; c3_i1 < 27; c3_i1++) {
    chartInstance->c3_indicies[c3_i1] = c3_dv1[c3_i1];
  }

  sf_mex_import_named("selected_maxvm", sf_mex_get_sfun_param(chartInstance->S,
    8U, 0U), c3_dv2, 0, 0, 0U, 1, 0U, 2, 21, 3);
  for (c3_i2 = 0; c3_i2 < 63; c3_i2++) {
    chartInstance->c3_selected_maxvm[c3_i2] = c3_dv2[c3_i2];
  }

  sf_mex_import_named("axb", sf_mex_get_sfun_param(chartInstance->S, 0U, 0U),
                      &c3_d6, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_axb = c3_d6;
}

static void mdl_start_c3_car_model_FIXED(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void mdl_terminate_c3_car_model_FIXED(SFc3_car_model_FIXEDInstanceStruct *
  chartInstance)
{
  const emlrtLocationLoggingFileInfoType c3_emlrtLocationLoggingFileInfo = {
    "#car_model_FIXED:6421",           /* mexFileName */
    "Mon Apr 17 21:46:01 2023",        /* timestamp */
    "",                                /* buildDir */
    1,                                 /* numFcns */
    256                                /* numHistogramBins */
  };

  const emlrtLocationLoggingFunctionInfoType
    c3_emlrtLocationLoggingFunctionInfoTable[1] = { { "eML_blk_kernel",/* fcnName */
      1,                               /* fcnId */
      191                              /* numInstrPoints */
    } };

  const emlrtLocationLoggingLocationType c3_emlrtLocationInfo[216] = { { 1,/* MxInfoID */
      155,                             /* TextStart */
      11,                              /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      168,                             /* TextStart */
      9,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      179,                             /* TextStart */
      3,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      184,                             /* TextStart */
      7,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 2,                            /* MxInfoID */
      193,                             /* TextStart */
      2,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      197,                             /* TextStart */
      3,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 3,                            /* MxInfoID */
      202,                             /* TextStart */
      3,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 4,                            /* MxInfoID */
      207,                             /* TextStart */
      5,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      214,                             /* TextStart */
      5,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 5,                            /* MxInfoID */
      221,                             /* TextStart */
      14,                              /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      245,                             /* TextStart */
      2,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      249,                             /* TextStart */
      21,                              /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      272,                             /* TextStart */
      17,                              /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      291,                             /* TextStart */
      8,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 6,                            /* MxInfoID */
      301,                             /* TextStart */
      8,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 7,                            /* MxInfoID */
      311,                             /* TextStart */
      14,                              /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      327,                             /* TextStart */
      3,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      332,                             /* TextStart */
      7,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 8,                            /* MxInfoID */
      357,                             /* TextStart */
      5,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 8,                            /* MxInfoID */
      411,                             /* TextStart */
      5,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      466,                             /* TextStart */
      8,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      508,                             /* TextStart */
      8,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      579,                             /* TextStart */
      9,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      606,                             /* TextStart */
      13,                              /* TextLength */
      5,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      628,                             /* TextStart */
      6,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      652,                             /* TextStart */
      13,                              /* TextLength */
      5,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      679,                             /* TextStart */
      9,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      705,                             /* TextStart */
      6,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 8,                            /* MxInfoID */
      753,                             /* TextStart */
      11,                              /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 8,                            /* MxInfoID */
      767,                             /* TextStart */
      45,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 8,                            /* MxInfoID */
      772,                             /* TextStart */
      39,                              /* TextLength */
      5,                               /* Reason */
      false                            /* MoreLocations */
    }, { 8,                            /* MxInfoID */
      772,                             /* TextStart */
      18,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 8,                            /* MxInfoID */
      773,                             /* TextStart */
      13,                              /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 8,                            /* MxInfoID */
      793,                             /* TextStart */
      18,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 8,                            /* MxInfoID */
      794,                             /* TextStart */
      13,                              /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      853,                             /* TextStart */
      9,                               /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      865,                             /* TextStart */
      25,                              /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      865,                             /* TextStart */
      21,                              /* TextLength */
      5,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      920,                             /* TextStart */
      5,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      958,                             /* TextStart */
      5,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      996,                             /* TextStart */
      10,                              /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1024,                            /* TextStart */
      11,                              /* TextLength */
      5,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1041,                            /* TextStart */
      10,                              /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1069,                            /* TextStart */
      11,                              /* TextLength */
      5,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1086,                            /* TextStart */
      5,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1124,                            /* TextStart */
      10,                              /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1152,                            /* TextStart */
      31,                              /* TextLength */
      5,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1189,                            /* TextStart */
      6,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1213,                            /* TextStart */
      27,                              /* TextLength */
      5,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1246,                            /* TextStart */
      8,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1287,                            /* TextStart */
      13,                              /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1318,                            /* TextStart */
      31,                              /* TextLength */
      5,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1355,                            /* TextStart */
      9,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1382,                            /* TextStart */
      27,                              /* TextLength */
      5,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1415,                            /* TextStart */
      7,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1455,                            /* TextStart */
      6,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1513,                            /* TextStart */
      5,                               /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1521,                            /* TextStart */
      31,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1526,                            /* TextStart */
      25,                              /* TextLength */
      5,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1527,                            /* TextStart */
      9,                               /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1541,                            /* TextStart */
      9,                               /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1568,                            /* TextStart */
      2,                               /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1573,                            /* TextStart */
      20,                              /* TextLength */
      5,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1574,                            /* TextStart */
      9,                               /* TextLength */
      7,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1604,                            /* TextStart */
      2,                               /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1609,                            /* TextStart */
      9,                               /* TextLength */
      7,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1625,                            /* TextStart */
      3,                               /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1631,                            /* TextStart */
      20,                              /* TextLength */
      5,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1631,                            /* TextStart */
      7,                               /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1642,                            /* TextStart */
      8,                               /* TextLength */
      7,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1642,                            /* TextStart */
      5,                               /* TextLength */
      7,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1669,                            /* TextStart */
      5,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1689,                            /* TextStart */
      5,                               /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1697,                            /* TextStart */
      9,                               /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1713,                            /* TextStart */
      9,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1733,                            /* TextStart */
      22,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1737,                            /* TextStart */
      17,                              /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1806,                            /* TextStart */
      4,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1828,                            /* TextStart */
      11,                              /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1842,                            /* TextStart */
      15,                              /* TextLength */
      5,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1863,                            /* TextStart */
      5,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1878,                            /* TextStart */
      9,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1902,                            /* TextStart */
      16,                              /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1939,                            /* TextStart */
      4,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1961,                            /* TextStart */
      11,                              /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      1975,                            /* TextStart */
      15,                              /* TextLength */
      5,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2001,                            /* TextStart */
      4,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2028,                            /* TextStart */
      16,                              /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2069,                            /* TextStart */
      5,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2138,                            /* TextStart */
      7,                               /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2148,                            /* TextStart */
      16,                              /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2148,                            /* TextStart */
      12,                              /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2251,                            /* TextStart */
      8,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2281,                            /* TextStart */
      5,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2375,                            /* TextStart */
      8,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2401,                            /* TextStart */
      5,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2422,                            /* TextStart */
      4,                               /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2429,                            /* TextStart */
      16,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2433,                            /* TextStart */
      11,                              /* TextLength */
      8,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2447,                            /* TextStart */
      7,                               /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2457,                            /* TextStart */
      38,                              /* TextLength */
      7,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2470,                            /* TextStart */
      24,                              /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2471,                            /* TextStart */
      9,                               /* TextLength */
      8,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2485,                            /* TextStart */
      8,                               /* TextLength */
      8,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2518,                            /* TextStart */
      7,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2540,                            /* TextStart */
      7,                               /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2550,                            /* TextStart */
      24,                              /* TextLength */
      8,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2550,                            /* TextStart */
      16,                              /* TextLength */
      7,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2596,                            /* TextStart */
      10,                              /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2617,                            /* TextStart */
      18,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2621,                            /* TextStart */
      13,                              /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2646,                            /* TextStart */
      9,                               /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2659,                            /* TextStart */
      13,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2697,                            /* TextStart */
      10,                              /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2749,                            /* TextStart */
      10,                              /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2777,                            /* TextStart */
      18,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2781,                            /* TextStart */
      13,                              /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2805,                            /* TextStart */
      9,                               /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2817,                            /* TextStart */
      41,                              /* TextLength */
      8,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2817,                            /* TextStart */
      31,                              /* TextLength */
      7,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2830,                            /* TextStart */
      18,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2834,                            /* TextStart */
      13,                              /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2869,                            /* TextStart */
      9,                               /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2881,                            /* TextStart */
      62,                              /* TextLength */
      8,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2881,                            /* TextStart */
      52,                              /* TextLength */
      7,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2895,                            /* TextStart */
      37,                              /* TextLength */
      5,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2896,                            /* TextStart */
      17,                              /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2901,                            /* TextStart */
      12,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2918,                            /* TextStart */
      13,                              /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      2923,                            /* TextStart */
      8,                               /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      3001,                            /* TextStart */
      13,                              /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      3034,                            /* TextStart */
      13,                              /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      3067,                            /* TextStart */
      2,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      3086,                            /* TextStart */
      13,                              /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      3120,                            /* TextStart */
      2,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      3144,                            /* TextStart */
      2,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      3167,                            /* TextStart */
      13,                              /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      3201,                            /* TextStart */
      13,                              /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      3234,                            /* TextStart */
      2,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      3253,                            /* TextStart */
      13,                              /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      3287,                            /* TextStart */
      2,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      3310,                            /* TextStart */
      2,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      3337,                            /* TextStart */
      13,                              /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      3370,                            /* TextStart */
      2,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      3389,                            /* TextStart */
      13,                              /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      3423,                            /* TextStart */
      2,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      3447,                            /* TextStart */
      2,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      3563,                            /* TextStart */
      2,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      3607,                            /* TextStart */
      2,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      3631,                            /* TextStart */
      2,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      3704,                            /* TextStart */
      2,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      3748,                            /* TextStart */
      2,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      3771,                            /* TextStart */
      2,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      3823,                            /* TextStart */
      2,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      3867,                            /* TextStart */
      2,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      3891,                            /* TextStart */
      2,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      3961,                            /* TextStart */
      13,                              /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      3988,                            /* TextStart */
      23,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      3992,                            /* TextStart */
      18,                              /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      4015,                            /* TextStart */
      18,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      4019,                            /* TextStart */
      13,                              /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      4039,                            /* TextStart */
      23,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      4043,                            /* TextStart */
      18,                              /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      4066,                            /* TextStart */
      18,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      4070,                            /* TextStart */
      13,                              /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      4089,                            /* TextStart */
      13,                              /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      4140,                            /* TextStart */
      4,                               /* TextLength */
      5,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      4171,                            /* TextStart */
      4,                               /* TextLength */
      5,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      4207,                            /* TextStart */
      4,                               /* TextLength */
      5,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      4243,                            /* TextStart */
      4,                               /* TextLength */
      5,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      4274,                            /* TextStart */
      13,                              /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      4311,                            /* TextStart */
      13,                              /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      4397,                            /* TextStart */
      6,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      4450,                            /* TextStart */
      6,                               /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      4459,                            /* TextStart */
      9,                               /* TextLength */
      5,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      4487,                            /* TextStart */
      6,                               /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      4496,                            /* TextStart */
      9,                               /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      4574,                            /* TextStart */
      6,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      4627,                            /* TextStart */
      6,                               /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      4636,                            /* TextStart */
      9,                               /* TextLength */
      5,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      4664,                            /* TextStart */
      6,                               /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      4673,                            /* TextStart */
      9,                               /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 9,                            /* MxInfoID */
      4701,                            /* TextStart */
      16,                              /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 9,                            /* MxInfoID */
      4742,                            /* TextStart */
      15,                              /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 9,                            /* MxInfoID */
      4780,                            /* TextStart */
      20,                              /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 9,                            /* MxInfoID */
      4833,                            /* TextStart */
      19,                              /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 9,                            /* MxInfoID */
      4880,                            /* TextStart */
      7,                               /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 9,                            /* MxInfoID */
      4890,                            /* TextStart */
      34,                              /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 9,                            /* MxInfoID */
      4930,                            /* TextStart */
      7,                               /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 9,                            /* MxInfoID */
      4940,                            /* TextStart */
      37,                              /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 9,                            /* MxInfoID */
      4983,                            /* TextStart */
      8,                               /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 9,                            /* MxInfoID */
      4994,                            /* TextStart */
      38,                              /* TextLength */
      6,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      5043,                            /* TextStart */
      13,                              /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      5059,                            /* TextStart */
      59,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      5064,                            /* TextStart */
      53,                              /* TextLength */
      8,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      5064,                            /* TextStart */
      21,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      5089,                            /* TextStart */
      27,                              /* TextLength */
      7,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      5089,                            /* TextStart */
      13,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      5103,                            /* TextStart */
      13,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      5124,                            /* TextStart */
      14,                              /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      5141,                            /* TextStart */
      61,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      5146,                            /* TextStart */
      55,                              /* TextLength */
      8,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      5146,                            /* TextStart */
      22,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      5172,                            /* TextStart */
      28,                              /* TextLength */
      7,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      5172,                            /* TextStart */
      13,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      5186,                            /* TextStart */
      14,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      5255,                            /* TextStart */
      13,                              /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      5291,                            /* TextStart */
      13,                              /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      5324,                            /* TextStart */
      7,                               /* TextLength */
      2,                               /* Reason */
      true                             /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      5334,                            /* TextStart */
      21,                              /* TextLength */
      7,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      5407,                            /* TextStart */
      15,                              /* TextLength */
      3,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      5444,                            /* TextStart */
      7,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      5472,                            /* TextStart */
      7,                               /* TextLength */
      2,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      237,                             /* TextStart */
      6,                               /* TextLength */
      1,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      815,                             /* TextStart */
      5,                               /* TextLength */
      4,                               /* Reason */
      false                            /* MoreLocations */
    }, { 1,                            /* MxInfoID */
      822,                             /* TextStart */
      9,                               /* TextLength */
      4,                               /* Reason */
      false                            /* MoreLocations */
    } };

  const int32_T c3_emlrtLocationLoggingFieldCounts[191] = { 0, 0, 0, 0, 3, 0, 3,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0 };

  const char_T *c3_emlrtLocationLoggingFieldNames[6] = { "xdot", "ydot", "zdot",
    "X", "Y", "Z" };

  if (chartInstance->c3_emlrtLocLogSimulated) {
    emlrtLocationLoggingClearLog("#car_model_FIXED:6421");
    emlrtLocationLoggingPushLog(&c3_emlrtLocationLoggingFileInfo,
      &c3_emlrtLocationLoggingFunctionInfoTable[0],
      &chartInstance->c3_emlrtLocationLoggingDataTables[0],
      &c3_emlrtLocationInfo[0], NULL, 0U, &c3_emlrtLocationLoggingFieldCounts[0],
      &c3_emlrtLocationLoggingFieldNames[0]);
    addResultsToFPTRepository("#car_model_FIXED:6421");
  }
}

static void mdl_setup_runtime_resources_c3_car_model_FIXED
  (SFc3_car_model_FIXEDInstanceStruct *chartInstance)
{
  static const int32_T c3_postfixPredicateTree[6] = { 0, 1, -3, 2, -1, -3 };

  static const int32_T c3_e_postfixPredicateTree[5] = { 0, 1, -3, 2, -3 };

  static const int32_T c3_i_postfixPredicateTree[5] = { 0, 1, -2, 2, -2 };

  static const int32_T c3_b_postfixPredicateTree[4] = { 0, 1, -1, -3 };

  static const int32_T c3_c_postfixPredicateTree[4] = { 0, 1, -1, -3 };

  static const int32_T c3_condTxtEndIdx[3] = { 1762, 1788, 1800 };

  static const int32_T c3_condTxtStartIdx[3] = { 1733, 1768, 1795 };

  static const int32_T c3_d_postfixPredicateTree[3] = { 0, 1, -2 };

  static const int32_T c3_e_condTxtEndIdx[3] = { 2330, 2350, 2369 };

  static const int32_T c3_e_condTxtStartIdx[3] = { 2309, 2336, 2356 };

  static const int32_T c3_f_postfixPredicateTree[3] = { 0, 1, -3 };

  static const int32_T c3_g_postfixPredicateTree[3] = { 0, 1, -3 };

  static const int32_T c3_h_postfixPredicateTree[3] = { 0, 1, -3 };

  static const int32_T c3_i_condTxtEndIdx[3] = { 4192, 4228, 4264 };

  static const int32_T c3_i_condTxtStartIdx[3] = { 4162, 4198, 4234 };

  static const int32_T c3_j_postfixPredicateTree[3] = { 0, 1, -2 };

  static const int32_T c3_k_postfixPredicateTree[3] = { 0, 1, -2 };

  static const int32_T c3_l_postfixPredicateTree[3] = { 0, 1, -3 };

  static const int32_T c3_b_condTxtEndIdx[2] = { 1923, 1934 };

  static const int32_T c3_b_condTxtStartIdx[2] = { 1901, 1929 };

  static const int32_T c3_c_condTxtEndIdx[2] = { 2049, 2064 };

  static const int32_T c3_c_condTxtStartIdx[2] = { 2027, 2055 };

  static const int32_T c3_d_condTxtEndIdx[2] = { 2220, 2245 };

  static const int32_T c3_d_condTxtStartIdx[2] = { 2195, 2226 };

  static const int32_T c3_f_condTxtEndIdx[2] = { 2640, 2672 };

  static const int32_T c3_f_condTxtStartIdx[2] = { 2617, 2646 };

  static const int32_T c3_g_condTxtEndIdx[2] = { 4033, 4084 };

  static const int32_T c3_g_condTxtStartIdx[2] = { 3988, 4039 };

  static const int32_T c3_h_condTxtEndIdx[2] = { 4125, 4151 };

  static const int32_T c3_h_condTxtStartIdx[2] = { 4117, 4131 };

  static const int32_T c3_j_condTxtEndIdx[2] = { 4367, 4388 };

  static const int32_T c3_j_condTxtStartIdx[2] = { 4350, 4371 };

  static const int32_T c3_k_condTxtEndIdx[2] = { 4544, 4565 };

  static const int32_T c3_k_condTxtStartIdx[2] = { 4527, 4548 };

  static const int32_T c3_l_condTxtEndIdx[2] = { 5422, 5438 };

  static const int32_T c3_l_condTxtStartIdx[2] = { 5392, 5428 };

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
    158U);
  covrtChartInitFcn(chartInstance->c3_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c3_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c3_decisionTxtStartIdx, &c3_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c3_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c3_covrtInstance, "", 4U, 0U, 1U, 0U, 39U, 0U,
                  0U, 0U, 0U, 0U, 27U, 12U);
  covrtEmlFcnInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 5501);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 0U, 549, 574, 670,
                    722, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 1U, 1555, 1563,
                    1595, 1623, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 2U, 1654, 1664,
                    1680, 1711, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 3U, 1729, 1801,
                    1893, 2021, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 4U, 1893, 1934,
                    1992, 2021, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 5U, 2023, 2064, -1,
                    2083, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 6U, 2191, 2246,
                    2301, 2417, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 7U, 2301, 2370, -1,
                    2417, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 8U, 2498, 2513,
                    2531, 2579, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 9U, 2613, 2673,
                    2722, 2769, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 10U, 2678, 2688, -1,
                    2721, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 11U, 2722, 2744, -1,
                    2769, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 12U, 2774, 2800,
                    2860, 2948, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 13U, 2997, 3026,
                    3159, 3465, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 14U, 3030, 3059,
                    3078, 3158, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 15U, 3078, 3112,
                    3132, 3158, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 16U, 3159, 3193,
                    3325, 3465, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 17U, 3197, 3226,
                    3245, 3324, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 18U, 3245, 3279,
                    3298, 3324, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 19U, 3333, 3362,
                    3381, 3461, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 20U, 3381, 3415,
                    3435, 3461, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 21U, 3509, 3530,
                    3646, 3909, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 22U, 3534, 3555,
                    3574, 3645, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 23U, 3574, 3599,
                    3619, 3645, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 24U, 3646, 3671,
                    3786, 3909, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 25U, 3675, 3696,
                    3715, 3785, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 26U, 3715, 3740,
                    3759, 3785, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 27U, 3794, 3815,
                    3834, 3905, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 28U, 3834, 3859,
                    3879, 3905, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 29U, 3947, 3957,
                    3980, 5322, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 30U, 3980, 4085,
                    4108, 5322, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 31U, 4108, 4153,
                    4338, 5322, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 32U, 4158, 4265,
                    4298, 4337, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 33U, 4347, 4388,
                    4417, 4514, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 34U, 4417, 4441,
                    4474, 4514, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 35U, 4524, 4565,
                    4594, 4691, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 36U, 4594, 4618,
                    4651, 4691, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 37U, 5213, 5246,
                    5278, 5318, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 38U, 5388, 5439,
                    5463, 5496, false);
  covrtEmlMCDCInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 0U, 1732, 1801,
                      3U, 0U, c3_condTxtStartIdx, c3_condTxtEndIdx, 6U,
                      c3_postfixPredicateTree, false);
  covrtEmlMCDCInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 1U, 1900, 1934,
                      2U, 3U, c3_b_condTxtStartIdx, c3_b_condTxtEndIdx, 4U,
                      c3_b_postfixPredicateTree, false);
  covrtEmlMCDCInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 2U, 2026, 2064,
                      2U, 5U, c3_c_condTxtStartIdx, c3_c_condTxtEndIdx, 4U,
                      c3_c_postfixPredicateTree, false);
  covrtEmlMCDCInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 3U, 2194, 2246,
                      2U, 7U, c3_d_condTxtStartIdx, c3_d_condTxtEndIdx, 3U,
                      c3_d_postfixPredicateTree, false);
  covrtEmlMCDCInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 4U, 2308, 2370,
                      3U, 9U, c3_e_condTxtStartIdx, c3_e_condTxtEndIdx, 5U,
                      c3_e_postfixPredicateTree, false);
  covrtEmlMCDCInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 5U, 2616, 2673,
                      2U, 12U, c3_f_condTxtStartIdx, c3_f_condTxtEndIdx, 3U,
                      c3_f_postfixPredicateTree, false);
  covrtEmlMCDCInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 6U, 3987, 4085,
                      2U, 14U, c3_g_condTxtStartIdx, c3_g_condTxtEndIdx, 3U,
                      c3_g_postfixPredicateTree, false);
  covrtEmlMCDCInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 7U, 4116, 4152,
                      2U, 16U, c3_h_condTxtStartIdx, c3_h_condTxtEndIdx, 3U,
                      c3_h_postfixPredicateTree, false);
  covrtEmlMCDCInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 8U, 4161, 4265,
                      3U, 18U, c3_i_condTxtStartIdx, c3_i_condTxtEndIdx, 5U,
                      c3_i_postfixPredicateTree, false);
  covrtEmlMCDCInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 9U, 4350, 4388,
                      2U, 21U, c3_j_condTxtStartIdx, c3_j_condTxtEndIdx, 3U,
                      c3_j_postfixPredicateTree, false);
  covrtEmlMCDCInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 10U, 4527, 4565,
                      2U, 23U, c3_k_condTxtStartIdx, c3_k_condTxtEndIdx, 3U,
                      c3_k_postfixPredicateTree, false);
  covrtEmlMCDCInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 11U, 5391, 5439,
                      2U, 25U, c3_l_condTxtStartIdx, c3_l_condTxtEndIdx, 3U,
                      c3_l_postfixPredicateTree, false);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 0U, 552,
    574, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 1U, 1657,
    1664, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 2U, 1733,
    1762, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 3U, 1768,
    1788, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 4U, 1901,
    1923, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 5U, 2027,
    2049, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 6U, 2195,
    2220, -1, 1U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 7U, 2226,
    2245, -1, 1U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 8U, 2309,
    2330, -1, 1U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 9U, 2336,
    2350, -1, 1U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 10U, 2356,
    2369, -1, 1U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 11U, 2501,
    2513, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 12U, 2617,
    2640, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 13U, 2646,
    2672, -1, 1U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 14U, 2681,
    2688, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 15U, 2730,
    2743, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 16U, 2777,
    2800, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 17U, 3000,
    3026, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 18U, 3033,
    3059, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 19U, 3085,
    3112, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 20U, 3166,
    3193, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 21U, 3200,
    3226, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 22U, 3252,
    3279, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 23U, 3336,
    3362, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 24U, 3388,
    3415, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 25U, 3512,
    3530, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 26U, 3537,
    3555, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 27U, 3581,
    3599, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 28U, 3653,
    3671, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 29U, 3678,
    3696, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 30U, 3722,
    3740, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 31U, 3797,
    3815, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 32U, 3841,
    3859, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 33U, 3950,
    3957, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 34U, 3988,
    4033, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 35U, 4039,
    4084, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 36U, 4117,
    4125, -1, 1U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 37U, 4131,
    4151, -1, 1U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 38U, 4162,
    4192, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 39U, 4198,
    4228, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 40U, 4234,
    4264, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 41U, 4350,
    4367, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 42U, 4371,
    4388, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 43U, 4424,
    4441, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 44U, 4527,
    4544, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 45U, 4548,
    4565, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 46U, 4601,
    4618, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 47U, 5216,
    5246, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 48U, 5392,
    5422, -1, 1U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 49U, 5428,
    5438, -1, 1U);
}

static void mdl_cleanup_runtime_resources_c3_car_model_FIXED
  (SFc3_car_model_FIXEDInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c3_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c3_covrtInstance);
}

static void enable_c3_car_model_FIXED(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_car_model_FIXED(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c3_car_model_FIXED(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  static char_T c3_b_cv[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'l',
    'o', 'g', 'i', 'c', 'a', 'l', 'n', 'a', 'n' };

  static char_T c3_cv1[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'l',
    'o', 'g', 'i', 'c', 'a', 'l', 'n', 'a', 'n' };

  static char_T c3_cv2[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'l',
    'o', 'g', 'i', 'c', 'a', 'l', 'n', 'a', 'n' };

  static char_T c3_cv3[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'l',
    'o', 'g', 'i', 'c', 'a', 'l', 'n', 'a', 'n' };

  c3_Disp c3_b_pos;
  c3_Disp c3_r1;
  c3_slBus15_Vel c3_b_Vg;
  c3_slBus15_Vel c3_r;
  emlrtStack c3_b_st;
  emlrtStack c3_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *c3_c_y = NULL;
  const mxArray *c3_d_y = NULL;
  const mxArray *c3_f_y = NULL;
  const mxArray *c3_g_y = NULL;
  const mxArray *c3_h_y = NULL;
  const mxArray *c3_i_y = NULL;
  const mxArray *c3_j_y = NULL;
  const mxArray *c3_k_y = NULL;
  real_T c3_b_selected_maxvm[63];
  real_T c3_dv2[63];
  real_T c3_X_all[51];
  real_T c3_Y_all[51];
  real_T c3_d_error_all[51];
  real_T c3_b_indicies[27];
  real_T c3_dv1[27];
  real_T c3_c_omega[4];
  real_T c3_axis_coordiantes[2];
  real_T c3_next_ref_coordinates[2];
  real_T c3_ref_coordiantes[2];
  real_T c3_vehicle_coordinates[2];
  real_T c3_Qc;
  real_T c3_Qn;
  real_T c3_Vmax_next;
  real_T c3_Vmax_now;
  real_T c3_Vnext;
  real_T c3_a;
  real_T c3_ab_x;
  real_T c3_b_Vnow;
  real_T c3_b_a;
  real_T c3_b_axb;
  real_T c3_b_c;
  real_T c3_b_d_error;
  real_T c3_b_deg2rad;
  real_T c3_b_di_now;
  real_T c3_b_di_prev;
  real_T c3_b_dx;
  real_T c3_b_forward_look_straight;
  real_T c3_b_forward_look_turn;
  real_T c3_b_min_d;
  real_T c3_b_min_index;
  real_T c3_b_p_error;
  real_T c3_b_psi;
  real_T c3_b_psi_error;
  real_T c3_b_q_thresh;
  real_T c3_b_r_error;
  real_T c3_b_r_ref;
  real_T c3_b_v_cog;
  real_T c3_b_v_error;
  real_T c3_b_x;
  real_T c3_b_x_ref;
  real_T c3_b_y;
  real_T c3_b_y_ref;
  real_T c3_b_yaw;
  real_T c3_b_yaw_ref;
  real_T c3_bb_x;
  real_T c3_c;
  real_T c3_c_a;
  real_T c3_c_ahead;
  real_T c3_c_c;
  real_T c3_c_index_all;
  real_T c3_c_index_small;
  real_T c3_c_x;
  real_T c3_cb_x;
  real_T c3_d;
  real_T c3_d1;
  real_T c3_d10;
  real_T c3_d11;
  real_T c3_d12;
  real_T c3_d13;
  real_T c3_d14;
  real_T c3_d15;
  real_T c3_d16;
  real_T c3_d17;
  real_T c3_d18;
  real_T c3_d19;
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
  real_T c3_d6;
  real_T c3_d7;
  real_T c3_d8;
  real_T c3_d9;
  real_T c3_d_a;
  real_T c3_d_ahead;
  real_T c3_d_index_all;
  real_T c3_d_index_small;
  real_T c3_d_next;
  real_T c3_d_x;
  real_T c3_db_x;
  real_T c3_det;
  real_T c3_di;
  real_T c3_e_a;
  real_T c3_e_x;
  real_T c3_e_y;
  real_T c3_eb_x;
  real_T c3_ex;
  real_T c3_f_a;
  real_T c3_f_x;
  real_T c3_fb_x;
  real_T c3_g_a;
  real_T c3_g_x;
  real_T c3_gb_x;
  real_T c3_h_a;
  real_T c3_h_x;
  real_T c3_hb_x;
  real_T c3_i_a;
  real_T c3_i_x;
  real_T c3_ib_x;
  real_T c3_increment;
  real_T c3_j_a;
  real_T c3_j_x;
  real_T c3_jb_x;
  real_T c3_k_a;
  real_T c3_k_x;
  real_T c3_kb_x;
  real_T c3_l_a;
  real_T c3_l_x;
  real_T c3_l_y;
  real_T c3_lb_x;
  real_T c3_m_a;
  real_T c3_m_x;
  real_T c3_m_y;
  real_T c3_mb_x;
  real_T c3_min_d;
  real_T c3_min_index;
  real_T c3_minval;
  real_T c3_n_a;
  real_T c3_n_x;
  real_T c3_n_y;
  real_T c3_nb_x;
  real_T c3_num_elem;
  real_T c3_o_a;
  real_T c3_o_x;
  real_T c3_o_y;
  real_T c3_ob_x;
  real_T c3_p_a;
  real_T c3_p_x;
  real_T c3_p_y;
  real_T c3_pb_x;
  real_T c3_psi_ref;
  real_T c3_q_a;
  real_T c3_q_x;
  real_T c3_q_y;
  real_T c3_qb_x;
  real_T c3_r_IC;
  real_T c3_r_straight;
  real_T c3_r_turn;
  real_T c3_r_x;
  real_T c3_r_y;
  real_T c3_rb_x;
  real_T c3_s_x;
  real_T c3_s_y;
  real_T c3_sb_x;
  real_T c3_sign_distance;
  real_T c3_sign_steer;
  real_T c3_straight_next;
  real_T c3_t_x;
  real_T c3_t_y;
  real_T c3_tb_x;
  real_T c3_theta_next_ref;
  real_T c3_theta_veh_ref;
  real_T c3_turn_next;
  real_T c3_turn_ref;
  real_T c3_u_x;
  real_T c3_u_y;
  real_T c3_ub_x;
  real_T c3_v_x;
  real_T c3_vb_x;
  real_T c3_w_x;
  real_T c3_x;
  real_T c3_x_axis;
  real_T c3_x_ref_next;
  real_T c3_x_x;
  real_T c3_y;
  real_T c3_y_axis;
  real_T c3_y_ref_next;
  real_T c3_y_x;
  int32_T c3_b_k;
  int32_T c3_c_k;
  int32_T c3_d_k;
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
  int32_T c3_i47;
  int32_T c3_i48;
  int32_T c3_i5;
  int32_T c3_i6;
  int32_T c3_i7;
  int32_T c3_i8;
  int32_T c3_i9;
  int32_T c3_idx;
  int32_T c3_iindx;
  int32_T c3_k;
  boolean_T c3_b;
  boolean_T c3_b_b;
  boolean_T c3_c_b;
  boolean_T c3_d_b;
  boolean_T c3_guard1 = false;
  boolean_T c3_guard2 = false;
  boolean_T c3_guard3 = false;
  boolean_T c3_guard4 = false;
  c3_st.tls = chartInstance->c3_fEmlrtCtx;
  c3_b_st.prev = &c3_st;
  c3_b_st.tls = c3_st.tls;
  chartInstance->c3_JITTransitionAnimation[0] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 8U,
                    *chartInstance->c3_di_prev);
  covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 7U,
                    *chartInstance->c3_b_ahead);
  for (c3_i = 0; c3_i < 4; c3_i++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 6U,
                      (*chartInstance->c3_omega)[c3_i]);
  }

  covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 4U, *chartInstance->c3_yaw);
  covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 2U, *chartInstance->c3_psi);
  covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 1U,
                    *chartInstance->c3_index_all);
  covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 0U,
                    *chartInstance->c3_index_small);
  chartInstance->c3_sfEvent = CALL_EVENT;
  c3_c_index_small = *chartInstance->c3_index_small;
  c3_c_index_all = *chartInstance->c3_index_all;
  c3_b_psi = *chartInstance->c3_psi;
  c3_b_deg2rad = chartInstance->c3_deg2rad;
  c3_b_Vg.xdot = *(real_T *)&((char_T *)chartInstance->c3_Vg)[0];
  c3_b_Vg.ydot = *(real_T *)&((char_T *)chartInstance->c3_Vg)[8];
  c3_b_Vg.zdot = *(real_T *)&((char_T *)chartInstance->c3_Vg)[16];
  c3_b_yaw = *chartInstance->c3_yaw;
  c3_b_pos.X = *(real_T *)&((char_T *)chartInstance->c3_pos)[0];
  c3_b_pos.Y = *(real_T *)&((char_T *)chartInstance->c3_pos)[8];
  c3_b_pos.Z = *(real_T *)&((char_T *)chartInstance->c3_pos)[16];
  c3_c_ahead = *chartInstance->c3_b_ahead;
  for (c3_i1 = 0; c3_i1 < 37971; c3_i1++) {
    chartInstance->c3_b_selected_track[c3_i1] = chartInstance->
      c3_selected_track[c3_i1];
  }

  c3_b_dx = chartInstance->c3_dx;
  c3_b_forward_look_straight = chartInstance->c3_forward_look_straight;
  c3_b_forward_look_turn = chartInstance->c3_forward_look_turn;
  c3_b_q_thresh = chartInstance->c3_q_thresh;
  for (c3_i2 = 0; c3_i2 < 27; c3_i2++) {
    c3_b_indicies[c3_i2] = chartInstance->c3_indicies[c3_i2];
  }

  for (c3_i3 = 0; c3_i3 < 63; c3_i3++) {
    c3_b_selected_maxvm[c3_i3] = chartInstance->c3_selected_maxvm[c3_i3];
  }

  c3_b_axb = chartInstance->c3_axb;
  c3_b_di_prev = *chartInstance->c3_di_prev;

  /* logging input variable 'index_small' for function 'eML_blk_kernel' */
  /* logging input variable 'index_all' for function 'eML_blk_kernel' */
  /* logging input variable 'psi' for function 'eML_blk_kernel' */
  /* logging input variable 'deg2rad' for function 'eML_blk_kernel' */
  /* logging input variable 'Vg' for function 'eML_blk_kernel' */
  /* logging input variable 'yaw' for function 'eML_blk_kernel' */
  /* logging input variable 'pos' for function 'eML_blk_kernel' */
  /* logging input variable 'omega' for function 'eML_blk_kernel' */
  /* logging input variable 'ahead' for function 'eML_blk_kernel' */
  /* logging input variable 'selected_track' for function 'eML_blk_kernel' */
  /* logging input variable 'dx' for function 'eML_blk_kernel' */
  /* logging input variable 'forward_look_straight' for function 'eML_blk_kernel' */
  /* logging input variable 'forward_look_turn' for function 'eML_blk_kernel' */
  /* logging input variable 'q_thresh' for function 'eML_blk_kernel' */
  /* logging input variable 'indicies' for function 'eML_blk_kernel' */
  /* logging input variable 'selected_maxvm' for function 'eML_blk_kernel' */
  /* logging input variable 'axb' for function 'eML_blk_kernel' */
  /* logging input variable 'di_prev' for function 'eML_blk_kernel' */
  chartInstance->c3_emlrtLocLogSimulated = true;
  c3_emlrt_update_log_1(chartInstance, c3_b_dIndex,
                        chartInstance->c3_emlrtLocationLoggingDataTables, 192);

  /* logging input variable 'index_small' for function 'eML_blk_kernel' */
  c3_emlrt_update_log_1(chartInstance, c3_c_index_small,
                        chartInstance->c3_emlrtLocationLoggingDataTables, 0);

  /* logging input variable 'index_all' for function 'eML_blk_kernel' */
  c3_emlrt_update_log_1(chartInstance, c3_c_index_all,
                        chartInstance->c3_emlrtLocationLoggingDataTables, 1);

  /* logging input variable 'psi' for function 'eML_blk_kernel' */
  c3_emlrt_update_log_1(chartInstance, c3_b_psi,
                        chartInstance->c3_emlrtLocationLoggingDataTables, 2);

  /* logging input variable 'deg2rad' for function 'eML_blk_kernel' */
  c3_emlrt_update_log_1(chartInstance, c3_b_deg2rad,
                        chartInstance->c3_emlrtLocationLoggingDataTables, 3);

  /* logging input variable 'Vg' for function 'eML_blk_kernel' */
  c3_r = c3_b_Vg;
  c3_b_emlrt_update_log_2(chartInstance, &c3_r,
    chartInstance->c3_emlrtLocationLoggingDataTables, 4);

  /* logging input variable 'yaw' for function 'eML_blk_kernel' */
  c3_emlrt_update_log_1(chartInstance, c3_b_yaw,
                        chartInstance->c3_emlrtLocationLoggingDataTables, 7);

  /* logging input variable 'pos' for function 'eML_blk_kernel' */
  c3_r1 = c3_b_pos;
  c3_b_emlrt_update_log_3(chartInstance, &c3_r1,
    chartInstance->c3_emlrtLocationLoggingDataTables, 8);

  /* logging input variable 'omega' for function 'eML_blk_kernel' */
  for (c3_i4 = 0; c3_i4 < 4; c3_i4++) {
    c3_c_omega[c3_i4] = (*chartInstance->c3_omega)[c3_i4];
  }

  c3_b_emlrt_update_log_4(chartInstance, c3_c_omega,
    chartInstance->c3_emlrtLocationLoggingDataTables, 11);

  /* logging input variable 'ahead' for function 'eML_blk_kernel' */
  c3_emlrt_update_log_1(chartInstance, c3_c_ahead,
                        chartInstance->c3_emlrtLocationLoggingDataTables, 12);

  /* logging input variable 'selected_track' for function 'eML_blk_kernel' */
  for (c3_i5 = 0; c3_i5 < 37971; c3_i5++) {
    chartInstance->c3_dv[c3_i5] = chartInstance->c3_b_selected_track[c3_i5];
  }

  c3_b_emlrt_update_log_5(chartInstance, chartInstance->c3_dv,
    chartInstance->c3_emlrtLocationLoggingDataTables, 13);

  /* logging input variable 'dx' for function 'eML_blk_kernel' */
  c3_emlrt_update_log_1(chartInstance, c3_b_dx,
                        chartInstance->c3_emlrtLocationLoggingDataTables, 14);

  /* logging input variable 'forward_look_straight' for function 'eML_blk_kernel' */
  c3_emlrt_update_log_1(chartInstance, c3_b_forward_look_straight,
                        chartInstance->c3_emlrtLocationLoggingDataTables, 15);

  /* logging input variable 'forward_look_turn' for function 'eML_blk_kernel' */
  c3_emlrt_update_log_1(chartInstance, c3_b_forward_look_turn,
                        chartInstance->c3_emlrtLocationLoggingDataTables, 16);

  /* logging input variable 'q_thresh' for function 'eML_blk_kernel' */
  c3_emlrt_update_log_1(chartInstance, c3_b_q_thresh,
                        chartInstance->c3_emlrtLocationLoggingDataTables, 17);

  /* logging input variable 'indicies' for function 'eML_blk_kernel' */
  for (c3_i6 = 0; c3_i6 < 27; c3_i6++) {
    c3_dv1[c3_i6] = c3_b_indicies[c3_i6];
  }

  c3_b_emlrt_update_log_6(chartInstance, c3_dv1,
    chartInstance->c3_emlrtLocationLoggingDataTables, 18);

  /* logging input variable 'selected_maxvm' for function 'eML_blk_kernel' */
  for (c3_i7 = 0; c3_i7 < 63; c3_i7++) {
    c3_dv2[c3_i7] = c3_b_selected_maxvm[c3_i7];
  }

  c3_b_emlrt_update_log_7(chartInstance, c3_dv2,
    chartInstance->c3_emlrtLocationLoggingDataTables, 19);

  /* logging input variable 'axb' for function 'eML_blk_kernel' */
  c3_emlrt_update_log_1(chartInstance, c3_b_axb,
                        chartInstance->c3_emlrtLocationLoggingDataTables, 20);

  /* logging input variable 'di_prev' for function 'eML_blk_kernel' */
  c3_emlrt_update_log_1(chartInstance, c3_b_di_prev,
                        chartInstance->c3_emlrtLocationLoggingDataTables, 21);
  c3_d_ahead = c3_c_ahead;
  for (c3_i8 = 0; c3_i8 < 4; c3_i8++) {
    c3_c_omega[c3_i8] = (*chartInstance->c3_omega)[c3_i8];
  }

  c3_d_index_all = c3_c_index_all;
  c3_d_index_small = c3_c_index_small;
  covrtEmlFcnEval(chartInstance->c3_covrtInstance, 4U, 0, 0);
  for (c3_i9 = 0; c3_i9 < 51; c3_i9++) {
    c3_d = c3_d_index_all + (real_T)c3_i9;
    if (c3_d != (real_T)(int32_T)muDoubleScalarFloor(c3_d)) {
      emlrtIntegerCheckR2012b(c3_d, &c3_emlrtDCI, &c3_st);
    }

    c3_i11 = (int32_T)c3_d;
    if ((c3_i11 < 1) || (c3_i11 > 4219)) {
      emlrtDynamicBoundsCheckR2012b(c3_i11, 1, 4219, &c3_emlrtBCI, &c3_st);
    }

    c3_Y_all[c3_i9] = chartInstance->c3_b_selected_track[c3_i11 + 4218];
  }

  c3_b_emlrt_update_log_8(chartInstance, c3_Y_all,
    chartInstance->c3_emlrtLocationLoggingDataTables, 22);
  for (c3_i10 = 0; c3_i10 < 51; c3_i10++) {
    c3_d1 = c3_d_index_all + (real_T)c3_i10;
    if (c3_d1 != (real_T)(int32_T)muDoubleScalarFloor(c3_d1)) {
      emlrtIntegerCheckR2012b(c3_d1, &c3_b_emlrtDCI, &c3_st);
    }

    c3_i13 = (int32_T)c3_d1;
    if ((c3_i13 < 1) || (c3_i13 > 4219)) {
      emlrtDynamicBoundsCheckR2012b(c3_i13, 1, 4219, &c3_b_emlrtBCI, &c3_st);
    }

    c3_X_all[c3_i10] = chartInstance->c3_b_selected_track[c3_i13 + 8437];
  }

  c3_b_emlrt_update_log_8(chartInstance, c3_X_all,
    chartInstance->c3_emlrtLocationLoggingDataTables, 23);
  if (c3_d_index_small != (real_T)(int32_T)muDoubleScalarFloor(c3_d_index_small))
  {
    emlrtIntegerCheckR2012b(c3_d_index_small, &c3_c_emlrtDCI, &c3_st);
  }

  c3_i12 = (int32_T)c3_d_index_small;
  if ((c3_i12 < 1) || (c3_i12 > 21)) {
    emlrtDynamicBoundsCheckR2012b(c3_i12, 1, 21, &c3_c_emlrtBCI, &c3_st);
  }

  c3_Vmax_now = c3_emlrt_update_log_1(chartInstance, c3_b_selected_maxvm[c3_i12
    + 41], chartInstance->c3_emlrtLocationLoggingDataTables, 24);
  c3_num_elem = c3_emlrt_update_log_1(chartInstance, 21.0,
    chartInstance->c3_emlrtLocationLoggingDataTables, 25);
  if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 0,
                     covrtRelationalopUpdateFcn(chartInstance->c3_covrtInstance,
        4U, 0U, 0U, c3_num_elem, c3_d_index_small, -1, 4U, c3_num_elem >
        c3_d_index_small))) {
    c3_d2 = c3_emlrt_update_log_1(chartInstance, c3_d_index_small + 1.0,
      chartInstance->c3_emlrtLocationLoggingDataTables, 27);
    if (c3_d2 != (real_T)(int32_T)muDoubleScalarFloor(c3_d2)) {
      emlrtIntegerCheckR2012b(c3_d2, &c3_d_emlrtDCI, &c3_st);
    }

    c3_i15 = (int32_T)c3_d2;
    if ((c3_i15 < 1) || (c3_i15 > 21)) {
      emlrtDynamicBoundsCheckR2012b(c3_i15, 1, 21, &c3_d_emlrtBCI, &c3_st);
    }

    c3_Vmax_next = c3_emlrt_update_log_1(chartInstance,
      c3_b_selected_maxvm[c3_i15 + 41],
      chartInstance->c3_emlrtLocationLoggingDataTables, 26);
    c3_d3 = c3_emlrt_update_log_1(chartInstance, c3_d_index_small + 1.0,
      chartInstance->c3_emlrtLocationLoggingDataTables, 29);
    if (c3_d3 != (real_T)(int32_T)muDoubleScalarFloor(c3_d3)) {
      emlrtIntegerCheckR2012b(c3_d3, &c3_e_emlrtDCI, &c3_st);
    }

    c3_i17 = (int32_T)c3_d3;
    if ((c3_i17 < 1) || (c3_i17 > 21)) {
      emlrtDynamicBoundsCheckR2012b(c3_i17, 1, 21, &c3_e_emlrtBCI, &c3_st);
    }

    c3_d_next = c3_emlrt_update_log_1(chartInstance, c3_b_selected_maxvm[c3_i17
      - 1], chartInstance->c3_emlrtLocationLoggingDataTables, 28);
  } else {
    c3_Vmax_next = c3_emlrt_update_log_1(chartInstance, c3_Vmax_now,
      chartInstance->c3_emlrtLocationLoggingDataTables, 30);
    c3_d_next = c3_emlrt_update_log_1(chartInstance, 100.0,
      chartInstance->c3_emlrtLocationLoggingDataTables, 31);
  }

  for (c3_i14 = 0; c3_i14 < 51; c3_i14++) {
    c3_Y_all[c3_i14] -= c3_b_pos.Y;
  }

  c3_b_emlrt_update_log_8(chartInstance, c3_Y_all,
    chartInstance->c3_emlrtLocationLoggingDataTables, 35);
  for (c3_k = 0; c3_k < 51; c3_k++) {
    c3_b_k = c3__s32_add__(chartInstance, c3_k, 1, 242, 1U, 772, 18);
    c3_a = c3_Y_all[c3__s32_minus__(chartInstance, c3_b_k, 1, 243, 1U, 772, 18)];
    c3_y = c3_a * c3_a;
    c3_d_error_all[c3__s32_minus__(chartInstance, c3_b_k, 1, 245, 1U, 772, 18)] =
      c3_y;
  }

  for (c3_i16 = 0; c3_i16 < 51; c3_i16++) {
    c3_X_all[c3_i16] -= c3_b_pos.X;
  }

  c3_b_emlrt_update_log_8(chartInstance, c3_X_all,
    chartInstance->c3_emlrtLocationLoggingDataTables, 37);
  for (c3_c_k = 0; c3_c_k < 51; c3_c_k++) {
    c3_d_k = c3__s32_add__(chartInstance, c3_c_k, 1, 246, 1U, 793, 18);
    c3_b_a = c3_X_all[c3__s32_minus__(chartInstance, c3_d_k, 1, 247, 1U, 793, 18)];
    c3_b_y = c3_b_a * c3_b_a;
    c3_Y_all[c3__s32_minus__(chartInstance, c3_d_k, 1, 248, 1U, 793, 18)] =
      c3_b_y;
  }

  c3_b_emlrt_update_log_8(chartInstance, c3_d_error_all,
    chartInstance->c3_emlrtLocationLoggingDataTables, 34);
  c3_b_emlrt_update_log_8(chartInstance, c3_Y_all,
    chartInstance->c3_emlrtLocationLoggingDataTables, 36);
  for (c3_i18 = 0; c3_i18 < 51; c3_i18++) {
    c3_d_error_all[c3_i18] += c3_Y_all[c3_i18];
  }

  c3_b_emlrt_update_log_8(chartInstance, c3_d_error_all,
    chartInstance->c3_emlrtLocationLoggingDataTables, 33);
  c3_b_st.site = &c3_emlrtRSI;
  c3_c_sqrt(chartInstance, &c3_b_st, c3_d_error_all);
  c3_b_emlrt_update_log_8(chartInstance, c3_d_error_all,
    chartInstance->c3_emlrtLocationLoggingDataTables, 32);
  c3_minimum(chartInstance, c3_d_error_all, &c3_ex, &c3_idx);
  c3_minval = c3_ex;
  c3_iindx = c3_idx;
  c3_min_d = c3_minval;
  c3_min_index = (real_T)c3_iindx;
  c3_b_min_d = c3_emlrt_update_log_1(chartInstance, c3_min_d,
    chartInstance->c3_emlrtLocationLoggingDataTables, 193);
  c3_b_min_index = c3_emlrt_update_log_1(chartInstance, c3_min_index,
    chartInstance->c3_emlrtLocationLoggingDataTables, 194);
  c3_d_index_all = c3_emlrt_update_log_1(chartInstance, c3_emlrt_update_log_1
    (chartInstance, c3_d_index_all + c3_b_min_index,
     chartInstance->c3_emlrtLocationLoggingDataTables, 39) - 1.0,
    chartInstance->c3_emlrtLocationLoggingDataTables, 38);
  if (c3_d_index_all != (real_T)(int32_T)muDoubleScalarFloor(c3_d_index_all)) {
    emlrtIntegerCheckR2012b(c3_d_index_all, &c3_f_emlrtDCI, &c3_st);
  }

  c3_i19 = (int32_T)c3_d_index_all;
  if ((c3_i19 < 1) || (c3_i19 > 4219)) {
    emlrtDynamicBoundsCheckR2012b(c3_i19, 1, 4219, &c3_f_emlrtBCI, &c3_st);
  }

  c3_b_y_ref = c3_emlrt_update_log_1(chartInstance,
    chartInstance->c3_b_selected_track[c3_i19 + 4218],
    chartInstance->c3_emlrtLocationLoggingDataTables, 40);
  if (c3_d_index_all != (real_T)(int32_T)muDoubleScalarFloor(c3_d_index_all)) {
    emlrtIntegerCheckR2012b(c3_d_index_all, &c3_g_emlrtDCI, &c3_st);
  }

  c3_i20 = (int32_T)c3_d_index_all;
  if ((c3_i20 < 1) || (c3_i20 > 4219)) {
    emlrtDynamicBoundsCheckR2012b(c3_i20, 1, 4219, &c3_g_emlrtBCI, &c3_st);
  }

  c3_b_x_ref = c3_emlrt_update_log_1(chartInstance,
    chartInstance->c3_b_selected_track[c3_i20 + 8437],
    chartInstance->c3_emlrtLocationLoggingDataTables, 41);
  c3_d4 = c3_emlrt_update_log_1(chartInstance, c3_d_index_all + 5.0,
    chartInstance->c3_emlrtLocationLoggingDataTables, 43);
  if (c3_d4 != (real_T)(int32_T)muDoubleScalarFloor(c3_d4)) {
    emlrtIntegerCheckR2012b(c3_d4, &c3_h_emlrtDCI, &c3_st);
  }

  c3_i21 = (int32_T)c3_d4;
  if ((c3_i21 < 1) || (c3_i21 > 4219)) {
    emlrtDynamicBoundsCheckR2012b(c3_i21, 1, 4219, &c3_h_emlrtBCI, &c3_st);
  }

  c3_y_ref_next = c3_emlrt_update_log_1(chartInstance,
    chartInstance->c3_b_selected_track[c3_i21 + 4218],
    chartInstance->c3_emlrtLocationLoggingDataTables, 42);
  c3_d5 = c3_emlrt_update_log_1(chartInstance, c3_d_index_all + 5.0,
    chartInstance->c3_emlrtLocationLoggingDataTables, 45);
  if (c3_d5 != (real_T)(int32_T)muDoubleScalarFloor(c3_d5)) {
    emlrtIntegerCheckR2012b(c3_d5, &c3_i_emlrtDCI, &c3_st);
  }

  c3_i22 = (int32_T)c3_d5;
  if ((c3_i22 < 1) || (c3_i22 > 4219)) {
    emlrtDynamicBoundsCheckR2012b(c3_i22, 1, 4219, &c3_i_emlrtBCI, &c3_st);
  }

  c3_x_ref_next = c3_emlrt_update_log_1(chartInstance,
    chartInstance->c3_b_selected_track[c3_i22 + 8437],
    chartInstance->c3_emlrtLocationLoggingDataTables, 44);
  if (c3_d_index_all != (real_T)(int32_T)muDoubleScalarFloor(c3_d_index_all)) {
    emlrtIntegerCheckR2012b(c3_d_index_all, &c3_j_emlrtDCI, &c3_st);
  }

  c3_i23 = (int32_T)c3_d_index_all;
  if ((c3_i23 < 1) || (c3_i23 > 4219)) {
    emlrtDynamicBoundsCheckR2012b(c3_i23, 1, 4219, &c3_j_emlrtBCI, &c3_st);
  }

  c3_b_r_ref = c3_emlrt_update_log_1(chartInstance,
    chartInstance->c3_b_selected_track[c3_i23 + 12656],
    chartInstance->c3_emlrtLocationLoggingDataTables, 46);
  c3_d6 = c3_emlrt_update_log_1(chartInstance, c3_d_index_all +
    c3_b_forward_look_straight, chartInstance->c3_emlrtLocationLoggingDataTables,
    48);
  if (c3_d6 != (real_T)(int32_T)muDoubleScalarFloor(c3_d6)) {
    emlrtIntegerCheckR2012b(c3_d6, &c3_k_emlrtDCI, &c3_st);
  }

  c3_i24 = (int32_T)c3_d6;
  if ((c3_i24 < 1) || (c3_i24 > 4219)) {
    emlrtDynamicBoundsCheckR2012b(c3_i24, 1, 4219, &c3_k_emlrtBCI, &c3_st);
  }

  c3_r_straight = c3_emlrt_update_log_1(chartInstance,
    chartInstance->c3_b_selected_track[c3_i24 + 12656],
    chartInstance->c3_emlrtLocationLoggingDataTables, 47);
  c3_d7 = c3_emlrt_update_log_1(chartInstance, c3_d_index_all +
    c3_b_forward_look_turn, chartInstance->c3_emlrtLocationLoggingDataTables, 50);
  if (c3_d7 != (real_T)(int32_T)muDoubleScalarFloor(c3_d7)) {
    emlrtIntegerCheckR2012b(c3_d7, &c3_l_emlrtDCI, &c3_st);
  }

  c3_i25 = (int32_T)c3_d7;
  if ((c3_i25 < 1) || (c3_i25 > 4219)) {
    emlrtDynamicBoundsCheckR2012b(c3_i25, 1, 4219, &c3_l_emlrtBCI, &c3_st);
  }

  c3_r_turn = c3_emlrt_update_log_1(chartInstance,
    chartInstance->c3_b_selected_track[c3_i25 + 12656],
    chartInstance->c3_emlrtLocationLoggingDataTables, 49);
  if (c3_d_index_all != (real_T)(int32_T)muDoubleScalarFloor(c3_d_index_all)) {
    emlrtIntegerCheckR2012b(c3_d_index_all, &c3_m_emlrtDCI, &c3_st);
  }

  c3_i26 = (int32_T)c3_d_index_all;
  if ((c3_i26 < 1) || (c3_i26 > 4219)) {
    emlrtDynamicBoundsCheckR2012b(c3_i26, 1, 4219, &c3_m_emlrtBCI, &c3_st);
  }

  c3_turn_ref = c3_emlrt_update_log_1(chartInstance,
    chartInstance->c3_b_selected_track[c3_i26 + 16875],
    chartInstance->c3_emlrtLocationLoggingDataTables, 51);
  c3_d8 = c3_emlrt_update_log_1(chartInstance, c3_d_index_all +
    c3_b_forward_look_straight, chartInstance->c3_emlrtLocationLoggingDataTables,
    53);
  if (c3_d8 != (real_T)(int32_T)muDoubleScalarFloor(c3_d8)) {
    emlrtIntegerCheckR2012b(c3_d8, &c3_n_emlrtDCI, &c3_st);
  }

  c3_i27 = (int32_T)c3_d8;
  if ((c3_i27 < 1) || (c3_i27 > 4219)) {
    emlrtDynamicBoundsCheckR2012b(c3_i27, 1, 4219, &c3_n_emlrtBCI, &c3_st);
  }

  c3_straight_next = c3_emlrt_update_log_1(chartInstance,
    chartInstance->c3_b_selected_track[c3_i27 + 16875],
    chartInstance->c3_emlrtLocationLoggingDataTables, 52);
  c3_d9 = c3_emlrt_update_log_1(chartInstance, c3_d_index_all +
    c3_b_forward_look_turn, chartInstance->c3_emlrtLocationLoggingDataTables, 55);
  if (c3_d9 != (real_T)(int32_T)muDoubleScalarFloor(c3_d9)) {
    emlrtIntegerCheckR2012b(c3_d9, &c3_o_emlrtDCI, &c3_st);
  }

  c3_i28 = (int32_T)c3_d9;
  if ((c3_i28 < 1) || (c3_i28 > 4219)) {
    emlrtDynamicBoundsCheckR2012b(c3_i28, 1, 4219, &c3_o_emlrtBCI, &c3_st);
  }

  c3_turn_next = c3_emlrt_update_log_1(chartInstance,
    chartInstance->c3_b_selected_track[c3_i28 + 16875],
    chartInstance->c3_emlrtLocationLoggingDataTables, 54);
  if (c3_d_index_all != (real_T)(int32_T)muDoubleScalarFloor(c3_d_index_all)) {
    emlrtIntegerCheckR2012b(c3_d_index_all, &c3_p_emlrtDCI, &c3_st);
  }

  c3_i29 = (int32_T)c3_d_index_all;
  if ((c3_i29 < 1) || (c3_i29 > 4219)) {
    emlrtDynamicBoundsCheckR2012b(c3_i29, 1, 4219, &c3_p_emlrtBCI, &c3_st);
  }

  c3_psi_ref = c3_emlrt_update_log_1(chartInstance,
    chartInstance->c3_b_selected_track[c3_i29 + 29532],
    chartInstance->c3_emlrtLocationLoggingDataTables, 56);
  if (c3_d_index_all != (real_T)(int32_T)muDoubleScalarFloor(c3_d_index_all)) {
    emlrtIntegerCheckR2012b(c3_d_index_all, &c3_q_emlrtDCI, &c3_st);
  }

  c3_i30 = (int32_T)c3_d_index_all;
  if ((c3_i30 < 1) || (c3_i30 > 4219)) {
    emlrtDynamicBoundsCheckR2012b(c3_i30, 1, 4219, &c3_q_emlrtBCI, &c3_st);
  }

  c3_b_di_now = c3_emlrt_update_log_1(chartInstance,
    chartInstance->c3_b_selected_track[c3_i30 + 33751],
    chartInstance->c3_emlrtLocationLoggingDataTables, 57);
  c3_b_st.site = &c3_b_emlrtRSI;
  c3_c_a = c3_b_Vg.xdot;
  c3_d_a = c3_c_a;
  c3_e_a = c3_d_a;
  c3_f_a = c3_e_a;
  c3_g_a = c3_f_a;
  c3_c = c3_g_a * c3_g_a;
  c3_b_st.site = &c3_b_emlrtRSI;
  c3_h_a = c3_b_Vg.ydot;
  c3_i_a = c3_h_a;
  c3_j_a = c3_i_a;
  c3_k_a = c3_j_a;
  c3_l_a = c3_k_a;
  c3_b_c = c3_l_a * c3_l_a;
  c3_d10 = c3_emlrt_update_log_1(chartInstance, c3_emlrt_update_log_1
    (chartInstance, c3_c, chartInstance->c3_emlrtLocationLoggingDataTables, 60)
    + c3_emlrt_update_log_1(chartInstance, c3_b_c,
    chartInstance->c3_emlrtLocationLoggingDataTables, 61),
    chartInstance->c3_emlrtLocationLoggingDataTables, 59);
  c3_b_st.site = &c3_b_emlrtRSI;
  c3_d_sqrt(chartInstance, &c3_b_st, &c3_d10);
  c3_b_v_cog = c3_emlrt_update_log_1(chartInstance, c3_d10,
    chartInstance->c3_emlrtLocationLoggingDataTables, 58);
  c3_b_st.site = &c3_c_emlrtRSI;
  c3_x = c3_d_ahead;
  c3_b_x = c3_x;
  c3_b = muDoubleScalarIsNaN(c3_b_x);
  if (c3_b) {
    c3_c_y = NULL;
    sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_b_cv, 10, 0U, 1U, 0U, 2, 1, 19),
                  false);
    c3_d_y = NULL;
    sf_mex_assign(&c3_d_y, sf_mex_create("y", c3_b_cv, 10, 0U, 1U, 0U, 2, 1, 19),
                  false);
    sf_mex_call(&c3_b_st, &c3_d_emlrtMCI, "error", 0U, 2U, 14, c3_c_y, 14,
                sf_mex_call(&c3_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c3_b_st, NULL, "message", 1U, 1U, 14, c3_d_y)));
  }

  if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 1, c3_d_ahead !=
                     0.0)) {
    c3_di = c3_emlrt_update_log_1(chartInstance, c3_emlrt_update_log_1
      (chartInstance, c3_b_di_now * c3_b_dx,
       chartInstance->c3_emlrtLocationLoggingDataTables, 63) + c3_d_next,
      chartInstance->c3_emlrtLocationLoggingDataTables, 62);
  } else {
    c3_di = c3_emlrt_update_log_1(chartInstance, c3_b_di_now * c3_b_dx,
      chartInstance->c3_emlrtLocationLoggingDataTables, 64);
  }

  c3_b_st.site = &c3_d_emlrtRSI;
  c3_m_a = c3_b_v_cog;
  c3_n_a = c3_m_a;
  c3_o_a = c3_n_a;
  c3_p_a = c3_o_a;
  c3_q_a = c3_p_a;
  c3_c_c = c3_q_a * c3_q_a;
  c3_det = c3_emlrt_update_log_1(chartInstance, c3_emlrt_update_log_1
    (chartInstance, c3_c_c, chartInstance->c3_emlrtLocationLoggingDataTables, 66)
    + c3_emlrt_update_log_1(chartInstance, c3_emlrt_update_log_1(chartInstance,
    2.0 * c3_b_axb, chartInstance->c3_emlrtLocationLoggingDataTables, 68) *
    c3_di, chartInstance->c3_emlrtLocationLoggingDataTables, 67),
    chartInstance->c3_emlrtLocationLoggingDataTables, 65);
  if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 2,
                     covrtRelationalopUpdateFcn(chartInstance->c3_covrtInstance,
        4U, 0U, 1U, c3_det, 0.0, -1, 2U, c3_det < 0.0))) {
    c3_Vnext = c3_emlrt_update_log_1(chartInstance, 0.0,
      chartInstance->c3_emlrtLocationLoggingDataTables, 69);
  } else {
    c3_d11 = c3_det;
    c3_b_st.site = &c3_e_emlrtRSI;
    c3_d_sqrt(chartInstance, &c3_b_st, &c3_d11);
    c3_Vnext = c3_emlrt_update_log_1(chartInstance, c3_d11,
      chartInstance->c3_emlrtLocationLoggingDataTables, 70);
  }

  c3_increment = c3_emlrt_update_log_1(chartInstance, 0.0,
    chartInstance->c3_emlrtLocationLoggingDataTables, 71);
  c3_c_x = c3_emlrt_update_log_1(chartInstance, c3_Vmax_next - c3_Vnext,
    chartInstance->c3_emlrtLocationLoggingDataTables, 73);
  c3_d_x = c3_c_x;
  c3_e_x = c3_d_x;
  c3_e_y = muDoubleScalarAbs(c3_e_x);
  c3_d12 = c3_emlrt_update_log_1(chartInstance, c3_e_y,
    chartInstance->c3_emlrtLocationLoggingDataTables, 72);
  c3_guard1 = false;
  c3_guard2 = false;
  if (covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 0,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c3_covrtInstance, 4U, 0U, 2U, c3_d12,
                        0.25, -1, 2U, c3_d12 < 0.25)) && covrtEmlCondEval
      (chartInstance->c3_covrtInstance, 4U, 0, 1, covrtRelationalopUpdateFcn
       (chartInstance->c3_covrtInstance, 4U, 0U, 3U, c3_Vmax_now, c3_Vmax_next,
        -1, 4U, c3_Vmax_now > c3_Vmax_next))) {
    c3_b_st.site = &c3_f_emlrtRSI;
    c3_f_x = c3_d_ahead;
    c3_g_x = c3_f_x;
    c3_b_b = muDoubleScalarIsNaN(c3_g_x);
    if (c3_b_b) {
      c3_f_y = NULL;
      sf_mex_assign(&c3_f_y, sf_mex_create("y", c3_cv1, 10, 0U, 1U, 0U, 2, 1, 19),
                    false);
      c3_g_y = NULL;
      sf_mex_assign(&c3_g_y, sf_mex_create("y", c3_cv1, 10, 0U, 1U, 0U, 2, 1, 19),
                    false);
      sf_mex_call(&c3_b_st, &c3_d_emlrtMCI, "error", 0U, 2U, 14, c3_f_y, 14,
                  sf_mex_call(&c3_b_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c3_b_st, NULL, "message", 1U, 1U, 14, c3_g_y)));
    }

    if (!covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 2, c3_d_ahead
                          != 0.0)) {
      covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 0, true);
      covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 3, true);
      c3_b_Vnow = c3_emlrt_update_log_1(chartInstance, c3_Vmax_next,
        chartInstance->c3_emlrtLocationLoggingDataTables, 74);
      c3_d_index_small = c3_emlrt_update_log_1(chartInstance, c3_d_index_small +
        1.0, chartInstance->c3_emlrtLocationLoggingDataTables, 75);
      c3_d_ahead = c3_emlrt_update_log_1(chartInstance, 1.0,
        chartInstance->c3_emlrtLocationLoggingDataTables, 76);
      c3_increment = c3_emlrt_update_log_1(chartInstance, 1.0,
        chartInstance->c3_emlrtLocationLoggingDataTables, 77);
    } else {
      c3_guard2 = true;
    }
  } else {
    c3_guard2 = true;
  }

  if (c3_guard2) {
    covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 0, false);
    covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 3, false);
    c3_d13 = c3_emlrt_update_log_1(chartInstance, c3_b_di_now - c3_b_di_prev,
      chartInstance->c3_emlrtLocationLoggingDataTables, 78);
    if (covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 3,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c3_covrtInstance, 4U, 0U, 4U, c3_d13,
                          0.0, -1, 4U, c3_d13 > 0.0))) {
      c3_b_st.site = &c3_g_emlrtRSI;
      c3_h_x = c3_d_ahead;
      c3_i_x = c3_h_x;
      c3_c_b = muDoubleScalarIsNaN(c3_i_x);
      if (c3_c_b) {
        c3_h_y = NULL;
        sf_mex_assign(&c3_h_y, sf_mex_create("y", c3_cv2, 10, 0U, 1U, 0U, 2, 1,
          19), false);
        c3_j_y = NULL;
        sf_mex_assign(&c3_j_y, sf_mex_create("y", c3_cv2, 10, 0U, 1U, 0U, 2, 1,
          19), false);
        sf_mex_call(&c3_b_st, &c3_d_emlrtMCI, "error", 0U, 2U, 14, c3_h_y, 14,
                    sf_mex_call(&c3_b_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c3_b_st, NULL, "message", 1U, 1U, 14, c3_j_y)));
      }

      if (!covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 4,
                            c3_d_ahead != 0.0)) {
        covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 1, true);
        covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 4, true);
        c3_b_Vnow = c3_emlrt_update_log_1(chartInstance, c3_Vmax_next,
          chartInstance->c3_emlrtLocationLoggingDataTables, 79);
        c3_d_index_small = c3_emlrt_update_log_1(chartInstance, c3_d_index_small
          + 1.0, chartInstance->c3_emlrtLocationLoggingDataTables, 80);
      } else {
        c3_guard1 = true;
      }
    } else {
      c3_guard1 = true;
    }
  }

  if (c3_guard1) {
    covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 1, false);
    covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 4, false);
    c3_b_Vnow = c3_emlrt_update_log_1(chartInstance, c3_Vmax_now,
      chartInstance->c3_emlrtLocationLoggingDataTables, 81);
  }

  c3_d14 = c3_emlrt_update_log_1(chartInstance, c3_b_di_now - c3_b_di_prev,
    chartInstance->c3_emlrtLocationLoggingDataTables, 82);
  c3_guard1 = false;
  if (covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 5,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c3_covrtInstance, 4U, 0U, 5U, c3_d14, 0.0,
                        -1, 4U, c3_d14 > 0.0))) {
    c3_b_st.site = &c3_h_emlrtRSI;
    c3_j_x = c3_increment;
    c3_k_x = c3_j_x;
    c3_d_b = muDoubleScalarIsNaN(c3_k_x);
    if (c3_d_b) {
      c3_i_y = NULL;
      sf_mex_assign(&c3_i_y, sf_mex_create("y", c3_cv3, 10, 0U, 1U, 0U, 2, 1, 19),
                    false);
      c3_k_y = NULL;
      sf_mex_assign(&c3_k_y, sf_mex_create("y", c3_cv3, 10, 0U, 1U, 0U, 2, 1, 19),
                    false);
      sf_mex_call(&c3_b_st, &c3_d_emlrtMCI, "error", 0U, 2U, 14, c3_i_y, 14,
                  sf_mex_call(&c3_b_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c3_b_st, NULL, "message", 1U, 1U, 14, c3_k_y)));
    }

    if (!covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 6,
                          c3_increment != 0.0)) {
      covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 2, true);
      covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 5, true);
      c3_d_ahead = c3_emlrt_update_log_1(chartInstance, 0.0,
        chartInstance->c3_emlrtLocationLoggingDataTables, 83);
    } else {
      c3_guard1 = true;
    }
  } else {
    c3_guard1 = true;
  }

  if (c3_guard1) {
    covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 2, false);
    covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 5, false);
  }

  c3_b_v_error = c3_emlrt_update_log_1(chartInstance, c3_emlrt_update_log_1
    (chartInstance, c3_b_Vnow - c3_b_v_cog,
     chartInstance->c3_emlrtLocationLoggingDataTables, 85) - 1.0,
    chartInstance->c3_emlrtLocationLoggingDataTables, 84);
  if (covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 7,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c3_covrtInstance, 4U, 0U, 6U, c3_turn_ref,
                        c3_straight_next, -1, 1U, c3_turn_ref !=
                        c3_straight_next)) || covrtEmlCondEval
      (chartInstance->c3_covrtInstance, 4U, 0, 8, covrtRelationalopUpdateFcn
       (chartInstance->c3_covrtInstance, 4U, 0U, 7U, c3_b_r_ref, c3_r_straight,
        -1, 1U, c3_b_r_ref != c3_r_straight))) {
    covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 3, true);
    covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 6, true);
    c3_turn_ref = c3_emlrt_update_log_1(chartInstance, c3_straight_next,
      chartInstance->c3_emlrtLocationLoggingDataTables, 86);
    c3_b_r_ref = c3_emlrt_update_log_1(chartInstance, c3_r_straight,
      chartInstance->c3_emlrtLocationLoggingDataTables, 87);
  } else {
    covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 3, false);
    covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 6, false);
    if (covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 9,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c3_covrtInstance, 4U, 0U, 8U,
                          c3_turn_ref, c3_turn_next, -1, 1U, c3_turn_ref !=
                          c3_turn_next)) && covrtEmlCondEval
        (chartInstance->c3_covrtInstance, 4U, 0, 10, covrtRelationalopUpdateFcn
         (chartInstance->c3_covrtInstance, 4U, 0U, 9U, c3_turn_next, 0.0, -1, 1U,
          c3_turn_next != 0.0)) && covrtEmlCondEval
        (chartInstance->c3_covrtInstance, 4U, 0, 11, covrtRelationalopUpdateFcn
         (chartInstance->c3_covrtInstance, 4U, 0U, 10U, c3_turn_ref, 0.0, -1, 1U,
          c3_turn_ref != 0.0))) {
      covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 4, true);
      covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 7, true);
      c3_turn_ref = c3_emlrt_update_log_1(chartInstance, c3_turn_next,
        chartInstance->c3_emlrtLocationLoggingDataTables, 88);
      c3_b_r_ref = c3_emlrt_update_log_1(chartInstance, c3_r_turn,
        chartInstance->c3_emlrtLocationLoggingDataTables, 89);
    } else {
      covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 4, false);
      covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 7, false);
    }
  }

  c3_l_x = c3_emlrt_update_log_1(chartInstance, c3_b_v_cog / c3_b_yaw,
    chartInstance->c3_emlrtLocationLoggingDataTables, 91);
  c3_m_x = c3_l_x;
  c3_n_x = c3_m_x;
  c3_l_y = muDoubleScalarAbs(c3_n_x);
  c3_r_IC = c3_emlrt_update_log_1(chartInstance, c3_l_y,
    chartInstance->c3_emlrtLocationLoggingDataTables, 90);
  c3_b_r_error = c3_emlrt_update_log_1(chartInstance, c3_turn_ref *
    c3_emlrt_update_log_1(chartInstance, c3_emlrt_update_log_1(chartInstance,
    1.0 / c3_b_r_ref, chartInstance->c3_emlrtLocationLoggingDataTables, 94) -
    c3_emlrt_update_log_1(chartInstance, 1.0 / c3_r_IC,
    chartInstance->c3_emlrtLocationLoggingDataTables, 95),
    chartInstance->c3_emlrtLocationLoggingDataTables, 93),
    chartInstance->c3_emlrtLocationLoggingDataTables, 92);
  if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 8,
                     covrtRelationalopUpdateFcn(chartInstance->c3_covrtInstance,
        4U, 0U, 11U, c3_b_r_ref, rtInf, -1, 0U, c3_b_r_ref == rtInf))) {
    c3_b_yaw_ref = c3_emlrt_update_log_1(chartInstance, 0.0,
      chartInstance->c3_emlrtLocationLoggingDataTables, 96);
  } else {
    c3_b_yaw_ref = c3_emlrt_update_log_1(chartInstance, c3_emlrt_update_log_1
      (chartInstance, c3_turn_ref * c3_b_v_cog,
       chartInstance->c3_emlrtLocationLoggingDataTables, 98) / c3_b_r_ref,
      chartInstance->c3_emlrtLocationLoggingDataTables, 97);
  }

  c3_sign_steer = c3_emlrt_update_log_1(chartInstance, 1.0,
    chartInstance->c3_emlrtLocationLoggingDataTables, 99);
  c3_o_x = c3_emlrt_update_log_1(chartInstance, c3_b_psi - c3_psi_ref,
    chartInstance->c3_emlrtLocationLoggingDataTables, 101);
  c3_p_x = c3_o_x;
  c3_q_x = c3_p_x;
  c3_m_y = muDoubleScalarAbs(c3_q_x);
  c3_d15 = c3_emlrt_update_log_1(chartInstance, c3_m_y,
    chartInstance->c3_emlrtLocationLoggingDataTables, 100);
  c3_guard1 = false;
  if (covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 12,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c3_covrtInstance, 4U, 0U, 12U, c3_d15,
                        3.1415926535897931, -1, 4U, c3_d15 > 3.1415926535897931)))
  {
    c3_r_x = c3_b_psi;
    c3_s_x = c3_r_x;
    c3_s_x = muDoubleScalarSign(c3_s_x);
    c3_d16 = c3_emlrt_update_log_1(chartInstance, c3_s_x,
      chartInstance->c3_emlrtLocationLoggingDataTables, 102);
    c3_u_x = c3_psi_ref;
    c3_w_x = c3_u_x;
    c3_w_x = muDoubleScalarSign(c3_w_x);
    c3_d17 = c3_emlrt_update_log_1(chartInstance, c3_w_x,
      chartInstance->c3_emlrtLocationLoggingDataTables, 103);
    if (covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 13,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c3_covrtInstance, 4U, 0U, 13U, c3_d16,
                          c3_d17, -1, 1U, c3_d16 != c3_d17))) {
      covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 5, true);
      covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 9, true);
      if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 10,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c3_covrtInstance, 4U, 0U, 14U, c3_b_psi,
                          0.0, -1, 2U, c3_b_psi < 0.0))) {
        c3_sign_steer = c3_emlrt_update_log_1(chartInstance, -1.0,
          chartInstance->c3_emlrtLocationLoggingDataTables, 104);
      }
    } else {
      c3_guard1 = true;
    }
  } else {
    c3_guard1 = true;
  }

  if (c3_guard1) {
    covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 5, false);
    covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 9, false);
    if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 11,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c3_covrtInstance, 4U, 0U, 15U, c3_b_psi,
                        c3_psi_ref, -1, 4U, c3_b_psi > c3_psi_ref))) {
      c3_sign_steer = c3_emlrt_update_log_1(chartInstance, -1.0,
        chartInstance->c3_emlrtLocationLoggingDataTables, 105);
    }
  }

  c3_t_x = c3_emlrt_update_log_1(chartInstance, c3_psi_ref - c3_b_psi,
    chartInstance->c3_emlrtLocationLoggingDataTables, 107);
  c3_v_x = c3_t_x;
  c3_x_x = c3_v_x;
  c3_n_y = muDoubleScalarAbs(c3_x_x);
  c3_d18 = c3_emlrt_update_log_1(chartInstance, c3_n_y,
    chartInstance->c3_emlrtLocationLoggingDataTables, 106);
  if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 12,
                     covrtRelationalopUpdateFcn(chartInstance->c3_covrtInstance,
        4U, 0U, 16U, c3_d18, 3.1415926535897931, -1, 2U, c3_d18 <
        3.1415926535897931))) {
    c3_ab_x = c3_emlrt_update_log_1(chartInstance, c3_psi_ref - c3_b_psi,
      chartInstance->c3_emlrtLocationLoggingDataTables, 111);
    c3_cb_x = c3_ab_x;
    c3_eb_x = c3_cb_x;
    c3_p_y = muDoubleScalarAbs(c3_eb_x);
    c3_b_psi_error = c3_emlrt_update_log_1(chartInstance, c3_emlrt_update_log_1
      (chartInstance, c3_sign_steer * c3_emlrt_update_log_1(chartInstance,
      c3_p_y, chartInstance->c3_emlrtLocationLoggingDataTables, 110),
       chartInstance->c3_emlrtLocationLoggingDataTables, 109) / c3_b_deg2rad,
      chartInstance->c3_emlrtLocationLoggingDataTables, 108);
  } else {
    c3_y_x = c3_psi_ref;
    c3_bb_x = c3_y_x;
    c3_db_x = c3_bb_x;
    c3_o_y = muDoubleScalarAbs(c3_db_x);
    c3_fb_x = c3_b_psi;
    c3_gb_x = c3_fb_x;
    c3_hb_x = c3_gb_x;
    c3_q_y = muDoubleScalarAbs(c3_hb_x);
    c3_b_psi_error = c3_emlrt_update_log_1(chartInstance, c3_emlrt_update_log_1
      (chartInstance, c3_sign_steer * c3_emlrt_update_log_1(chartInstance,
      c3_emlrt_update_log_1(chartInstance, 3.1415926535897931 -
      c3_emlrt_update_log_1(chartInstance, c3_o_y,
      chartInstance->c3_emlrtLocationLoggingDataTables, 116),
      chartInstance->c3_emlrtLocationLoggingDataTables, 115) +
      c3_emlrt_update_log_1(chartInstance, 3.1415926535897931 -
      c3_emlrt_update_log_1(chartInstance, c3_q_y,
      chartInstance->c3_emlrtLocationLoggingDataTables, 118),
      chartInstance->c3_emlrtLocationLoggingDataTables, 117),
      chartInstance->c3_emlrtLocationLoggingDataTables, 114),
       chartInstance->c3_emlrtLocationLoggingDataTables, 113) / c3_b_deg2rad,
      chartInstance->c3_emlrtLocationLoggingDataTables, 112);
  }

  c3_d19 = c3_emlrt_update_log_1(chartInstance, c3_b_pos.Y - c3_b_y_ref,
    chartInstance->c3_emlrtLocationLoggingDataTables, 119);
  if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 13,
                     covrtRelationalopUpdateFcn(chartInstance->c3_covrtInstance,
        4U, 0U, 17U, c3_d19, c3_b_q_thresh, -1, 4U, c3_d19 > c3_b_q_thresh))) {
    c3_d21 = c3_emlrt_update_log_1(chartInstance, c3_b_pos.X - c3_b_x_ref,
      chartInstance->c3_emlrtLocationLoggingDataTables, 120);
    if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 14,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c3_covrtInstance, 4U, 0U, 18U, c3_d21,
                        c3_b_q_thresh, -1, 4U, c3_d21 > c3_b_q_thresh))) {
      c3_Qc = c3_emlrt_update_log_1(chartInstance, 5.0,
        chartInstance->c3_emlrtLocationLoggingDataTables, 121);
    } else {
      c3_d24 = c3_emlrt_update_log_1(chartInstance, c3_b_pos.X - c3_b_x_ref,
        chartInstance->c3_emlrtLocationLoggingDataTables, 122);
      if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 15,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c3_covrtInstance, 4U, 0U, 19U, c3_d24,
                          -c3_b_q_thresh, -1, 2U, c3_d24 < -c3_b_q_thresh))) {
        c3_Qc = c3_emlrt_update_log_1(chartInstance, 11.0,
          chartInstance->c3_emlrtLocationLoggingDataTables, 123);
      } else {
        c3_Qc = c3_emlrt_update_log_1(chartInstance, 4.0,
          chartInstance->c3_emlrtLocationLoggingDataTables, 124);
      }
    }
  } else {
    c3_d20 = c3_emlrt_update_log_1(chartInstance, c3_b_pos.Y - c3_b_y_ref,
      chartInstance->c3_emlrtLocationLoggingDataTables, 125);
    if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 16,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c3_covrtInstance, 4U, 0U, 20U, c3_d20,
                        -c3_b_q_thresh, -1, 2U, c3_d20 < -c3_b_q_thresh))) {
      c3_d23 = c3_emlrt_update_log_1(chartInstance, c3_b_pos.X - c3_b_x_ref,
        chartInstance->c3_emlrtLocationLoggingDataTables, 126);
      if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 17,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c3_covrtInstance, 4U, 0U, 21U, c3_d23,
                          c3_b_q_thresh, -1, 4U, c3_d23 > c3_b_q_thresh))) {
        c3_Qc = c3_emlrt_update_log_1(chartInstance, 7.0,
          chartInstance->c3_emlrtLocationLoggingDataTables, 127);
      } else {
        c3_d26 = c3_emlrt_update_log_1(chartInstance, c3_b_pos.X - c3_b_x_ref,
          chartInstance->c3_emlrtLocationLoggingDataTables, 128);
        if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 18,
                           covrtRelationalopUpdateFcn
                           (chartInstance->c3_covrtInstance, 4U, 0U, 22U, c3_d26,
                            -c3_b_q_thresh, -1, 2U, c3_d26 < -c3_b_q_thresh))) {
          c3_Qc = c3_emlrt_update_log_1(chartInstance, 9.0,
            chartInstance->c3_emlrtLocationLoggingDataTables, 129);
        } else {
          c3_Qc = c3_emlrt_update_log_1(chartInstance, 8.0,
            chartInstance->c3_emlrtLocationLoggingDataTables, 130);
        }
      }
    } else {
      c3_d22 = c3_emlrt_update_log_1(chartInstance, c3_b_pos.X - c3_b_x_ref,
        chartInstance->c3_emlrtLocationLoggingDataTables, 131);
      if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 19,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c3_covrtInstance, 4U, 0U, 23U, c3_d22,
                          c3_b_q_thresh, -1, 4U, c3_d22 > c3_b_q_thresh))) {
        c3_Qc = c3_emlrt_update_log_1(chartInstance, 6.0,
          chartInstance->c3_emlrtLocationLoggingDataTables, 132);
      } else {
        c3_d25 = c3_emlrt_update_log_1(chartInstance, c3_b_pos.X - c3_b_x_ref,
          chartInstance->c3_emlrtLocationLoggingDataTables, 133);
        if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 20,
                           covrtRelationalopUpdateFcn
                           (chartInstance->c3_covrtInstance, 4U, 0U, 24U, c3_d25,
                            -c3_b_q_thresh, -1, 2U, c3_d25 < -c3_b_q_thresh))) {
          c3_Qc = c3_emlrt_update_log_1(chartInstance, 10.0,
            chartInstance->c3_emlrtLocationLoggingDataTables, 134);
        } else {
          c3_Qc = c3_emlrt_update_log_1(chartInstance, 0.0,
            chartInstance->c3_emlrtLocationLoggingDataTables, 135);
        }
      }
    }
  }

  if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 21,
                     covrtRelationalopUpdateFcn(chartInstance->c3_covrtInstance,
        4U, 0U, 25U, c3_y_ref_next, c3_b_y_ref, -1, 4U, c3_y_ref_next >
        c3_b_y_ref))) {
    if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 22,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c3_covrtInstance, 4U, 0U, 26U,
                        c3_x_ref_next, c3_b_x_ref, -1, 4U, c3_x_ref_next >
                        c3_b_x_ref))) {
      c3_Qn = c3_emlrt_update_log_1(chartInstance, 5.0,
        chartInstance->c3_emlrtLocationLoggingDataTables, 136);
    } else if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 23,
                covrtRelationalopUpdateFcn(chartInstance->c3_covrtInstance, 4U,
                 0U, 27U, c3_x_ref_next, c3_b_x_ref, -1, 2U, c3_x_ref_next <
                 c3_b_x_ref))) {
      c3_Qn = c3_emlrt_update_log_1(chartInstance, 11.0,
        chartInstance->c3_emlrtLocationLoggingDataTables, 137);
    } else {
      c3_Qn = c3_emlrt_update_log_1(chartInstance, 4.0,
        chartInstance->c3_emlrtLocationLoggingDataTables, 138);
    }
  } else if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 24,
              covrtRelationalopUpdateFcn(chartInstance->c3_covrtInstance, 4U, 0U,
    28U, c3_y_ref_next, c3_b_y_ref, -1, 2U, c3_y_ref_next < c3_b_y_ref))) {
    if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 25,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c3_covrtInstance, 4U, 0U, 29U,
                        c3_x_ref_next, c3_b_x_ref, -1, 4U, c3_x_ref_next >
                        c3_b_x_ref))) {
      c3_Qn = c3_emlrt_update_log_1(chartInstance, 7.0,
        chartInstance->c3_emlrtLocationLoggingDataTables, 139);
    } else if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 26,
                covrtRelationalopUpdateFcn(chartInstance->c3_covrtInstance, 4U,
                 0U, 30U, c3_x_ref_next, c3_b_x_ref, -1, 2U, c3_x_ref_next <
                 c3_b_x_ref))) {
      c3_Qn = c3_emlrt_update_log_1(chartInstance, 9.0,
        chartInstance->c3_emlrtLocationLoggingDataTables, 140);
    } else {
      c3_Qn = c3_emlrt_update_log_1(chartInstance, 8.0,
        chartInstance->c3_emlrtLocationLoggingDataTables, 141);
    }
  } else if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 27,
              covrtRelationalopUpdateFcn(chartInstance->c3_covrtInstance, 4U, 0U,
    31U, c3_x_ref_next, c3_b_x_ref, -1, 4U, c3_x_ref_next > c3_b_x_ref))) {
    c3_Qn = c3_emlrt_update_log_1(chartInstance, 6.0,
      chartInstance->c3_emlrtLocationLoggingDataTables, 142);
  } else if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 28,
              covrtRelationalopUpdateFcn(chartInstance->c3_covrtInstance, 4U, 0U,
    32U, c3_x_ref_next, c3_b_x_ref, -1, 2U, c3_x_ref_next < c3_b_x_ref))) {
    c3_Qn = c3_emlrt_update_log_1(chartInstance, 10.0,
      chartInstance->c3_emlrtLocationLoggingDataTables, 143);
  } else {
    c3_Qn = c3_emlrt_update_log_1(chartInstance, 0.0,
      chartInstance->c3_emlrtLocationLoggingDataTables, 144);
  }

  if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 29,
                     covrtRelationalopUpdateFcn(chartInstance->c3_covrtInstance,
        4U, 0U, 33U, c3_Qc, 0.0, -1, 0U, c3_Qc == 0.0))) {
    c3_sign_distance = c3_emlrt_update_log_1(chartInstance, 0.0,
      chartInstance->c3_emlrtLocationLoggingDataTables, 145);
  } else {
    c3_ib_x = c3_emlrt_update_log_1(chartInstance, c3_x_ref_next - c3_b_x_ref,
      chartInstance->c3_emlrtLocationLoggingDataTables, 147);
    c3_jb_x = c3_ib_x;
    c3_kb_x = c3_jb_x;
    c3_r_y = muDoubleScalarAbs(c3_kb_x);
    c3_d27 = c3_emlrt_update_log_1(chartInstance, c3_r_y,
      chartInstance->c3_emlrtLocationLoggingDataTables, 146);
    c3_nb_x = c3_emlrt_update_log_1(chartInstance, c3_b_pos.X - c3_b_x_ref,
      chartInstance->c3_emlrtLocationLoggingDataTables, 149);
    c3_ob_x = c3_nb_x;
    c3_pb_x = c3_ob_x;
    c3_s_y = muDoubleScalarAbs(c3_pb_x);
    c3_d29 = c3_emlrt_update_log_1(chartInstance, c3_s_y,
      chartInstance->c3_emlrtLocationLoggingDataTables, 148);
    c3_guard1 = false;
    c3_guard2 = false;
    c3_guard3 = false;
    if (covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 14,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c3_covrtInstance, 4U, 0U, 34U, c3_d27,
                          c3_d29, -1, 0U, c3_d27 == c3_d29))) {
      c3_qb_x = c3_emlrt_update_log_1(chartInstance, c3_y_ref_next - c3_b_y_ref,
        chartInstance->c3_emlrtLocationLoggingDataTables, 151);
      c3_rb_x = c3_qb_x;
      c3_sb_x = c3_rb_x;
      c3_t_y = muDoubleScalarAbs(c3_sb_x);
      c3_d30 = c3_emlrt_update_log_1(chartInstance, c3_t_y,
        chartInstance->c3_emlrtLocationLoggingDataTables, 150);
      c3_tb_x = c3_emlrt_update_log_1(chartInstance, c3_b_pos.Y - c3_b_y_ref,
        chartInstance->c3_emlrtLocationLoggingDataTables, 153);
      c3_ub_x = c3_tb_x;
      c3_vb_x = c3_ub_x;
      c3_u_y = muDoubleScalarAbs(c3_vb_x);
      c3_d32 = c3_emlrt_update_log_1(chartInstance, c3_u_y,
        chartInstance->c3_emlrtLocationLoggingDataTables, 152);
      if (covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 15,
                           covrtRelationalopUpdateFcn
                           (chartInstance->c3_covrtInstance, 4U, 0U, 35U, c3_d30,
                            c3_d32, -1, 0U, c3_d30 == c3_d32))) {
        covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 6, true);
        covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 30, true);
        c3_sign_distance = c3_emlrt_update_log_1(chartInstance, 0.0,
          chartInstance->c3_emlrtLocationLoggingDataTables, 154);
      } else {
        c3_guard3 = true;
      }
    } else {
      c3_guard3 = true;
    }

    if (c3_guard3) {
      covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 6, false);
      covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 30, false);
      if (covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 16,
                           covrtRelationalopUpdateFcn
                           (chartInstance->c3_covrtInstance, 4U, 0U, 36U, c3_Qc,
                            c3_Qn, -1, 1U, c3_Qc != c3_Qn))) {
        c3_d31 = c3_emlrt_update_log_1(chartInstance, c3_Qc + 4.0,
          chartInstance->c3_emlrtLocationLoggingDataTables, 155);
        if (c3_d31 != (real_T)(int32_T)muDoubleScalarFloor(c3_d31)) {
          emlrtIntegerCheckR2012b(c3_d31, &c3_r_emlrtDCI, &c3_st);
        }

        c3_i31 = (int32_T)c3_d31;
        if ((c3_i31 < 1) || (c3_i31 > 27)) {
          emlrtDynamicBoundsCheckR2012b(c3_i31, 1, 27, &c3_r_emlrtBCI, &c3_st);
        }

        c3_d33 = c3_b_indicies[c3_i31 - 1];
        if (covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 17,
                             covrtRelationalopUpdateFcn
                             (chartInstance->c3_covrtInstance, 4U, 0U, 37U,
                              c3_d33, c3_Qn, -1, 1U, c3_d33 != c3_Qn))) {
          covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 7, true);
          covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 31, true);
          c3_d35 = c3_emlrt_update_log_1(chartInstance, c3_Qc + 1.0,
            chartInstance->c3_emlrtLocationLoggingDataTables, 156);
          if (c3_d35 != (real_T)(int32_T)muDoubleScalarFloor(c3_d35)) {
            emlrtIntegerCheckR2012b(c3_d35, &c3_t_emlrtDCI, &c3_st);
          }

          c3_i35 = (int32_T)c3_d35;
          if ((c3_i35 < 1) || (c3_i35 > 27)) {
            emlrtDynamicBoundsCheckR2012b(c3_i35, 1, 27, &c3_t_emlrtBCI, &c3_st);
          }

          c3_d37 = c3_b_indicies[c3_i35 - 1];
          if (c3_Qn != (real_T)(int32_T)muDoubleScalarFloor(c3_Qn)) {
            emlrtIntegerCheckR2012b(c3_Qn, &c3_v_emlrtDCI, &c3_st);
          }

          c3_i37 = (int32_T)c3_Qn;
          if ((c3_i37 < 1) || (c3_i37 > 27)) {
            emlrtDynamicBoundsCheckR2012b(c3_i37, 1, 27, &c3_v_emlrtBCI, &c3_st);
          }

          c3_d39 = c3_b_indicies[c3_i37 - 1];
          if (covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 18,
                               covrtRelationalopUpdateFcn
                               (chartInstance->c3_covrtInstance, 4U, 0U, 38U,
                                c3_d37, c3_d39, -1, 0U, c3_d37 == c3_d39))) {
            c3_guard2 = true;
          } else {
            c3_d40 = c3_emlrt_update_log_1(chartInstance, c3_Qc + 2.0,
              chartInstance->c3_emlrtLocationLoggingDataTables, 157);
            if (c3_d40 != (real_T)(int32_T)muDoubleScalarFloor(c3_d40)) {
              emlrtIntegerCheckR2012b(c3_d40, &c3_w_emlrtDCI, &c3_st);
            }

            c3_i41 = (int32_T)c3_d40;
            if ((c3_i41 < 1) || (c3_i41 > 27)) {
              emlrtDynamicBoundsCheckR2012b(c3_i41, 1, 27, &c3_w_emlrtBCI,
                &c3_st);
            }

            c3_d43 = c3_b_indicies[c3_i41 - 1];
            if (c3_Qn != (real_T)(int32_T)muDoubleScalarFloor(c3_Qn)) {
              emlrtIntegerCheckR2012b(c3_Qn, &c3_x_emlrtDCI, &c3_st);
            }

            c3_i42 = (int32_T)c3_Qn;
            if ((c3_i42 < 1) || (c3_i42 > 27)) {
              emlrtDynamicBoundsCheckR2012b(c3_i42, 1, 27, &c3_x_emlrtBCI,
                &c3_st);
            }

            c3_d44 = c3_b_indicies[c3_i42 - 1];
            if (covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 19,
                                 covrtRelationalopUpdateFcn
                                 (chartInstance->c3_covrtInstance, 4U, 0U, 39U,
                                  c3_d43, c3_d44, -1, 0U, c3_d43 == c3_d44))) {
              c3_guard2 = true;
            } else {
              c3_d46 = c3_emlrt_update_log_1(chartInstance, c3_Qc + 3.0,
                chartInstance->c3_emlrtLocationLoggingDataTables, 158);
              if (c3_d46 != (real_T)(int32_T)muDoubleScalarFloor(c3_d46)) {
                emlrtIntegerCheckR2012b(c3_d46, &c3_bb_emlrtDCI, &c3_st);
              }

              c3_i45 = (int32_T)c3_d46;
              if ((c3_i45 < 1) || (c3_i45 > 27)) {
                emlrtDynamicBoundsCheckR2012b(c3_i45, 1, 27, &c3_bb_emlrtBCI,
                  &c3_st);
              }

              c3_d47 = c3_b_indicies[c3_i45 - 1];
              if (c3_Qn != (real_T)(int32_T)muDoubleScalarFloor(c3_Qn)) {
                emlrtIntegerCheckR2012b(c3_Qn, &c3_cb_emlrtDCI, &c3_st);
              }

              c3_i48 = (int32_T)c3_Qn;
              if ((c3_i48 < 1) || (c3_i48 > 27)) {
                emlrtDynamicBoundsCheckR2012b(c3_i48, 1, 27, &c3_cb_emlrtBCI,
                  &c3_st);
              }

              c3_d49 = c3_b_indicies[c3_i48 - 1];
              if (covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 20,
                                   covrtRelationalopUpdateFcn
                                   (chartInstance->c3_covrtInstance, 4U, 0U, 40U,
                                    c3_d47, c3_d49, -1, 0U, c3_d47 == c3_d49)))
              {
                c3_guard2 = true;
              } else {
                covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 8,
                                 false);
                covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 32, false);
                c3_sign_distance = c3_emlrt_update_log_1(chartInstance, 1.0,
                  chartInstance->c3_emlrtLocationLoggingDataTables, 160);
              }
            }
          }
        } else {
          c3_guard1 = true;
        }
      } else {
        c3_guard1 = true;
      }
    }

    if (c3_guard2) {
      covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 8, true);
      covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 32, true);
      c3_sign_distance = c3_emlrt_update_log_1(chartInstance, -1.0,
        chartInstance->c3_emlrtLocationLoggingDataTables, 159);
    }

    if (c3_guard1) {
      covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 7, false);
      covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 31, false);
      if (c3_Qc != (real_T)(int32_T)muDoubleScalarFloor(c3_Qc)) {
        emlrtIntegerCheckR2012b(c3_Qc, &c3_s_emlrtDCI, &c3_st);
      }

      c3_i33 = (int32_T)c3_Qc;
      if ((c3_i33 < 1) || (c3_i33 > 27)) {
        emlrtDynamicBoundsCheckR2012b(c3_i33, 1, 27, &c3_s_emlrtBCI, &c3_st);
      }

      c3_d34 = c3_b_indicies[c3_i33 - 1];
      c3_guard4 = false;
      if (covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 21,
                           covrtRelationalopUpdateFcn
                           (chartInstance->c3_covrtInstance, 4U, 0U, 41U, c3_d34,
                            1.0, -1, 0U, c3_d34 == 1.0))) {
        c3_guard4 = true;
      } else {
        if (c3_Qc != (real_T)(int32_T)muDoubleScalarFloor(c3_Qc)) {
          emlrtIntegerCheckR2012b(c3_Qc, &c3_u_emlrtDCI, &c3_st);
        }

        c3_i34 = (int32_T)c3_Qc;
        if ((c3_i34 < 1) || (c3_i34 > 27)) {
          emlrtDynamicBoundsCheckR2012b(c3_i34, 1, 27, &c3_u_emlrtBCI, &c3_st);
        }

        c3_d36 = c3_b_indicies[c3_i34 - 1];
        if (covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 22,
                             covrtRelationalopUpdateFcn
                             (chartInstance->c3_covrtInstance, 4U, 0U, 42U,
                              c3_d36, 3.0, -1, 0U, c3_d36 == 3.0))) {
          c3_guard4 = true;
        } else {
          covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 9, false);
          covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 33, false);
          if (c3_Qc != (real_T)(int32_T)muDoubleScalarFloor(c3_Qc)) {
            emlrtIntegerCheckR2012b(c3_Qc, &c3_y_emlrtDCI, &c3_st);
          }

          c3_i39 = (int32_T)c3_Qc;
          if ((c3_i39 < 1) || (c3_i39 > 27)) {
            emlrtDynamicBoundsCheckR2012b(c3_i39, 1, 27, &c3_y_emlrtBCI, &c3_st);
          }

          c3_d41 = c3_b_indicies[c3_i39 - 1];
          if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 34,
                             covrtRelationalopUpdateFcn
                             (chartInstance->c3_covrtInstance, 4U, 0U, 43U,
                              c3_d41, 4.0, -1, 0U, c3_d41 == 4.0))) {
            c3_y_axis = c3_emlrt_update_log_1(chartInstance, c3_b_y_ref + 1.0,
              chartInstance->c3_emlrtLocationLoggingDataTables, 162);
          } else {
            c3_y_axis = c3_emlrt_update_log_1(chartInstance, c3_b_y_ref - 1.0,
              chartInstance->c3_emlrtLocationLoggingDataTables, 163);
          }
        }
      }

      if (c3_guard4) {
        covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 9, true);
        covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 33, true);
        c3_y_axis = c3_emlrt_update_log_1(chartInstance, c3_b_y_ref,
          chartInstance->c3_emlrtLocationLoggingDataTables, 161);
      }

      if (c3_Qc != (real_T)(int32_T)muDoubleScalarFloor(c3_Qc)) {
        emlrtIntegerCheckR2012b(c3_Qc, &c3_ab_emlrtDCI, &c3_st);
      }

      c3_i36 = (int32_T)c3_Qc;
      if ((c3_i36 < 1) || (c3_i36 > 27)) {
        emlrtDynamicBoundsCheckR2012b(c3_i36, 1, 27, &c3_ab_emlrtBCI, &c3_st);
      }

      c3_d38 = c3_b_indicies[c3_i36 - 1];
      c3_guard4 = false;
      if (covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 23,
                           covrtRelationalopUpdateFcn
                           (chartInstance->c3_covrtInstance, 4U, 0U, 44U, c3_d38,
                            2.0, -1, 0U, c3_d38 == 2.0))) {
        c3_guard4 = true;
      } else {
        if (c3_Qc != (real_T)(int32_T)muDoubleScalarFloor(c3_Qc)) {
          emlrtIntegerCheckR2012b(c3_Qc, &c3_db_emlrtDCI, &c3_st);
        }

        c3_i40 = (int32_T)c3_Qc;
        if ((c3_i40 < 1) || (c3_i40 > 27)) {
          emlrtDynamicBoundsCheckR2012b(c3_i40, 1, 27, &c3_db_emlrtBCI, &c3_st);
        }

        c3_d42 = c3_b_indicies[c3_i40 - 1];
        if (covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 24,
                             covrtRelationalopUpdateFcn
                             (chartInstance->c3_covrtInstance, 4U, 0U, 45U,
                              c3_d42, 4.0, -1, 0U, c3_d42 == 4.0))) {
          c3_guard4 = true;
        } else {
          covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 10, false);
          covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 35, false);
          if (c3_Qc != (real_T)(int32_T)muDoubleScalarFloor(c3_Qc)) {
            emlrtIntegerCheckR2012b(c3_Qc, &c3_eb_emlrtDCI, &c3_st);
          }

          c3_i43 = (int32_T)c3_Qc;
          if ((c3_i43 < 1) || (c3_i43 > 27)) {
            emlrtDynamicBoundsCheckR2012b(c3_i43, 1, 27, &c3_eb_emlrtBCI, &c3_st);
          }

          c3_d45 = c3_b_indicies[c3_i43 - 1];
          if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 36,
                             covrtRelationalopUpdateFcn
                             (chartInstance->c3_covrtInstance, 4U, 0U, 46U,
                              c3_d45, 1.0, -1, 0U, c3_d45 == 1.0))) {
            c3_x_axis = c3_emlrt_update_log_1(chartInstance, c3_b_x_ref + 1.0,
              chartInstance->c3_emlrtLocationLoggingDataTables, 165);
          } else {
            c3_x_axis = c3_emlrt_update_log_1(chartInstance, c3_b_x_ref - 1.0,
              chartInstance->c3_emlrtLocationLoggingDataTables, 166);
          }
        }
      }

      if (c3_guard4) {
        covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 10, true);
        covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 35, true);
        c3_x_axis = c3_emlrt_update_log_1(chartInstance, c3_b_x_ref,
          chartInstance->c3_emlrtLocationLoggingDataTables, 164);
      }

      c3_axis_coordiantes[0] = c3_y_axis;
      c3_axis_coordiantes[1] = c3_x_axis;
      c3_b_emlrt_update_log_9(chartInstance, c3_axis_coordiantes,
        chartInstance->c3_emlrtLocationLoggingDataTables, 167);
      c3_ref_coordiantes[0] = c3_b_y_ref;
      c3_ref_coordiantes[1] = c3_b_x_ref;
      c3_b_emlrt_update_log_9(chartInstance, c3_ref_coordiantes,
        chartInstance->c3_emlrtLocationLoggingDataTables, 168);
      c3_next_ref_coordinates[0] = c3_y_ref_next;
      c3_next_ref_coordinates[1] = c3_x_ref_next;
      c3_b_emlrt_update_log_9(chartInstance, c3_next_ref_coordinates,
        chartInstance->c3_emlrtLocationLoggingDataTables, 169);
      c3_vehicle_coordinates[0] = c3_b_pos.Y;
      c3_vehicle_coordinates[1] = c3_b_pos.X;
      c3_b_emlrt_update_log_9(chartInstance, c3_vehicle_coordinates,
        chartInstance->c3_emlrtLocationLoggingDataTables, 170);
      for (c3_i44 = 0; c3_i44 < 2; c3_i44++) {
        c3_axis_coordiantes[c3_i44] -= c3_ref_coordiantes[c3_i44];
      }

      c3_b_emlrt_update_log_9(chartInstance, c3_axis_coordiantes,
        chartInstance->c3_emlrtLocationLoggingDataTables, 171);
      for (c3_i46 = 0; c3_i46 < 2; c3_i46++) {
        c3_vehicle_coordinates[c3_i46] -= c3_ref_coordiantes[c3_i46];
      }

      c3_b_emlrt_update_log_9(chartInstance, c3_vehicle_coordinates,
        chartInstance->c3_emlrtLocationLoggingDataTables, 172);
      for (c3_i47 = 0; c3_i47 < 2; c3_i47++) {
        c3_next_ref_coordinates[c3_i47] -= c3_ref_coordiantes[c3_i47];
      }

      c3_b_emlrt_update_log_9(chartInstance, c3_next_ref_coordinates,
        chartInstance->c3_emlrtLocationLoggingDataTables, 173);
      c3_d48 = c3_emlrt_update_log_1(chartInstance, c3_emlrt_update_log_1
        (chartInstance, c3_dot(chartInstance, c3_axis_coordiantes,
        c3_vehicle_coordinates),
         chartInstance->c3_emlrtLocationLoggingDataTables, 176) /
        c3_emlrt_update_log_1(chartInstance, c3_emlrt_update_log_1(chartInstance,
        c3_norm(chartInstance, c3_axis_coordiantes),
        chartInstance->c3_emlrtLocationLoggingDataTables, 178) *
        c3_emlrt_update_log_1(chartInstance, c3_norm(chartInstance,
        c3_vehicle_coordinates),
        chartInstance->c3_emlrtLocationLoggingDataTables, 179),
        chartInstance->c3_emlrtLocationLoggingDataTables, 177),
        chartInstance->c3_emlrtLocationLoggingDataTables, 175);
      c3_b_st.site = &c3_i_emlrtRSI;
      c3_b_acos(chartInstance, &c3_b_st, &c3_d48);
      c3_theta_veh_ref = c3_emlrt_update_log_1(chartInstance, c3_d48,
        chartInstance->c3_emlrtLocationLoggingDataTables, 174);
      c3_d50 = c3_emlrt_update_log_1(chartInstance, c3_emlrt_update_log_1
        (chartInstance, c3_dot(chartInstance, c3_axis_coordiantes,
        c3_next_ref_coordinates),
         chartInstance->c3_emlrtLocationLoggingDataTables, 182) /
        c3_emlrt_update_log_1(chartInstance, c3_emlrt_update_log_1(chartInstance,
        c3_norm(chartInstance, c3_axis_coordiantes),
        chartInstance->c3_emlrtLocationLoggingDataTables, 184) *
        c3_emlrt_update_log_1(chartInstance, c3_norm(chartInstance,
        c3_next_ref_coordinates),
        chartInstance->c3_emlrtLocationLoggingDataTables, 185),
        chartInstance->c3_emlrtLocationLoggingDataTables, 183),
        chartInstance->c3_emlrtLocationLoggingDataTables, 181);
      c3_b_st.site = &c3_j_emlrtRSI;
      c3_b_acos(chartInstance, &c3_b_st, &c3_d50);
      c3_theta_next_ref = c3_emlrt_update_log_1(chartInstance, c3_d50,
        chartInstance->c3_emlrtLocationLoggingDataTables, 180);
      if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 37,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c3_covrtInstance, 4U, 0U, 47U,
                          c3_theta_veh_ref, c3_theta_next_ref, -1, 2U,
                          c3_theta_veh_ref < c3_theta_next_ref))) {
        c3_sign_distance = c3_emlrt_update_log_1(chartInstance, 1.0,
          chartInstance->c3_emlrtLocationLoggingDataTables, 186);
      } else {
        c3_sign_distance = c3_emlrt_update_log_1(chartInstance, -1.0,
          chartInstance->c3_emlrtLocationLoggingDataTables, 187);
      }
    }
  }

  c3_b_d_error = c3_emlrt_update_log_1(chartInstance, c3_sign_distance *
    c3_b_min_d, chartInstance->c3_emlrtLocationLoggingDataTables, 188);
  c3_lb_x = c3_b_psi_error;
  c3_mb_x = c3_lb_x;
  c3_mb_x = muDoubleScalarSign(c3_mb_x);
  c3_d28 = c3_emlrt_update_log_1(chartInstance, c3_mb_x,
    chartInstance->c3_emlrtLocationLoggingDataTables, 189);
  if (covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 25,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c3_covrtInstance, 4U, 0U, 48U,
                        c3_sign_distance, c3_d28, -1, 1U, c3_sign_distance !=
                        c3_d28)) && covrtEmlCondEval
      (chartInstance->c3_covrtInstance, 4U, 0, 26, covrtRelationalopUpdateFcn
       (chartInstance->c3_covrtInstance, 4U, 0U, 49U, c3_b_d_error, 0.0, -1, 1U,
        c3_b_d_error != 0.0))) {
    covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 11, true);
    covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 38, true);
    c3_b_p_error = c3_emlrt_update_log_1(chartInstance, c3_b_d_error,
      chartInstance->c3_emlrtLocationLoggingDataTables, 190);
  } else {
    covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 11, false);
    covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 38, false);
    c3_b_p_error = c3_emlrt_update_log_1(chartInstance, c3_b_psi_error,
      chartInstance->c3_emlrtLocationLoggingDataTables, 191);
  }

  *chartInstance->c3_b_index_small = c3_d_index_small;
  *chartInstance->c3_b_index_all = c3_d_index_all;
  *chartInstance->c3_v_error = c3_b_v_error;
  *chartInstance->c3_d_error = c3_b_d_error;
  *chartInstance->c3_psi_error = c3_b_psi_error;
  *chartInstance->c3_v_cog = c3_b_v_cog;
  *chartInstance->c3_r_ref = c3_b_r_ref;
  *chartInstance->c3_r_error = c3_b_r_error;
  *chartInstance->c3_x_ref = c3_b_x_ref;
  *chartInstance->c3_y_ref = c3_b_y_ref;
  *chartInstance->c3_yaw_ref = c3_b_yaw_ref;
  for (c3_i32 = 0; c3_i32 < 4; c3_i32++) {
    (*chartInstance->c3_b_omega)[c3_i32] = c3_c_omega[c3_i32];
  }

  *chartInstance->c3_p_error = c3_b_p_error;
  *chartInstance->c3_Vnow = c3_b_Vnow;
  *chartInstance->c3_ahead = c3_d_ahead;
  *chartInstance->c3_di_now = c3_b_di_now;
  c3_do_animation_call_c3_car_model_FIXED(chartInstance);
  covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 9U,
                    *chartInstance->c3_b_index_small);
  covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 10U,
                    *chartInstance->c3_b_index_all);
  covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 11U,
                    *chartInstance->c3_v_error);
  covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 12U,
                    *chartInstance->c3_d_error);
  covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 13U,
                    *chartInstance->c3_psi_error);
  covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 14U,
                    *chartInstance->c3_v_cog);
  covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 15U,
                    *chartInstance->c3_r_ref);
  covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 16U,
                    *chartInstance->c3_r_error);
  covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 17U,
                    *chartInstance->c3_x_ref);
  covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 18U,
                    *chartInstance->c3_y_ref);
  covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 19U,
                    *chartInstance->c3_yaw_ref);
  for (c3_i38 = 0; c3_i38 < 4; c3_i38++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 20U,
                      (*chartInstance->c3_b_omega)[c3_i38]);
  }

  covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 21U,
                    *chartInstance->c3_p_error);
  covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 22U,
                    *chartInstance->c3_Vnow);
  covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 23U,
                    *chartInstance->c3_ahead);
  covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 24U,
                    *chartInstance->c3_di_now);
}

static void ext_mode_exec_c3_car_model_FIXED(SFc3_car_model_FIXEDInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void c3_update_jit_animation_c3_car_model_FIXED
  (SFc3_car_model_FIXEDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_do_animation_call_c3_car_model_FIXED
  (SFc3_car_model_FIXEDInstanceStruct *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static const mxArray *get_sim_state_c3_car_model_FIXED
  (SFc3_car_model_FIXEDInstanceStruct *chartInstance)
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
  const mxArray *c3_p_y = NULL;
  const mxArray *c3_q_y = NULL;
  const mxArray *c3_r_y = NULL;
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(17, 1), false);
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", chartInstance->c3_Vnow, 0, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", chartInstance->c3_ahead, 0, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", chartInstance->c3_d_error, 0, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", chartInstance->c3_di_now, 0, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c3_y, 3, c3_e_y);
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", chartInstance->c3_b_index_all, 0, 0U,
    0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 4, c3_f_y);
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", chartInstance->c3_b_index_small, 0,
    0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 5, c3_g_y);
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", *chartInstance->c3_b_omega, 0, 0U,
    1U, 0U, 1, 4), false);
  sf_mex_setcell(c3_y, 6, c3_h_y);
  c3_i_y = NULL;
  sf_mex_assign(&c3_i_y, sf_mex_create("y", chartInstance->c3_p_error, 0, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c3_y, 7, c3_i_y);
  c3_j_y = NULL;
  sf_mex_assign(&c3_j_y, sf_mex_create("y", chartInstance->c3_psi_error, 0, 0U,
    0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 8, c3_j_y);
  c3_k_y = NULL;
  sf_mex_assign(&c3_k_y, sf_mex_create("y", chartInstance->c3_r_error, 0, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c3_y, 9, c3_k_y);
  c3_l_y = NULL;
  sf_mex_assign(&c3_l_y, sf_mex_create("y", chartInstance->c3_r_ref, 0, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c3_y, 10, c3_l_y);
  c3_m_y = NULL;
  sf_mex_assign(&c3_m_y, sf_mex_create("y", chartInstance->c3_v_cog, 0, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c3_y, 11, c3_m_y);
  c3_n_y = NULL;
  sf_mex_assign(&c3_n_y, sf_mex_create("y", chartInstance->c3_v_error, 0, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c3_y, 12, c3_n_y);
  c3_o_y = NULL;
  sf_mex_assign(&c3_o_y, sf_mex_create("y", chartInstance->c3_x_ref, 0, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c3_y, 13, c3_o_y);
  c3_p_y = NULL;
  sf_mex_assign(&c3_p_y, sf_mex_create("y", chartInstance->c3_y_ref, 0, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c3_y, 14, c3_p_y);
  c3_q_y = NULL;
  sf_mex_assign(&c3_q_y, sf_mex_create("y", chartInstance->c3_yaw_ref, 0, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c3_y, 15, c3_q_y);
  c3_r_y = NULL;
  sf_mex_assign(&c3_r_y, sf_mex_create("y",
    &chartInstance->c3_is_active_c3_car_model_FIXED, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 16, c3_r_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_car_model_FIXED(SFc3_car_model_FIXEDInstanceStruct *
  chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T c3_c_dv[4];
  int32_T c3_i;
  chartInstance->c3_doneDoubleBufferReInit = true;
  c3_u = sf_mex_dup(c3_st);
  *chartInstance->c3_Vnow = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 0)), "Vnow");
  *chartInstance->c3_ahead = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 1)), "ahead");
  *chartInstance->c3_d_error = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 2)), "d_error");
  *chartInstance->c3_di_now = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 3)), "di_now");
  *chartInstance->c3_b_index_all = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 4)), "index_all");
  *chartInstance->c3_b_index_small = c3_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 5)), "index_small");
  c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 6)),
                        "omega", c3_c_dv);
  for (c3_i = 0; c3_i < 4; c3_i++) {
    (*chartInstance->c3_b_omega)[c3_i] = c3_c_dv[c3_i];
  }

  *chartInstance->c3_p_error = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 7)), "p_error");
  *chartInstance->c3_psi_error = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 8)), "psi_error");
  *chartInstance->c3_r_error = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 9)), "r_error");
  *chartInstance->c3_r_ref = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 10)), "r_ref");
  *chartInstance->c3_v_cog = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 11)), "v_cog");
  *chartInstance->c3_v_error = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 12)), "v_error");
  *chartInstance->c3_x_ref = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 13)), "x_ref");
  *chartInstance->c3_y_ref = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 14)), "y_ref");
  *chartInstance->c3_yaw_ref = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 15)), "yaw_ref");
  chartInstance->c3_is_active_c3_car_model_FIXED = c3_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 16)),
     "is_active_c3_car_model_FIXED");
  sf_mex_destroy(&c3_u);
  sf_mex_destroy(&c3_st);
}

static void initSimStructsc3_car_model_FIXED(SFc3_car_model_FIXEDInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static real_T c3_emlrt_update_log_1(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c3_in, emlrtLocationLoggingDataType c3_table[], int32_T
  c3_index)
{
  emlrtLocationLoggingDataType *c3_b_table;
  emlrtLocationLoggingHistogramType *c3_histTable;
  real_T c3_inDouble;
  real_T c3_localMax;
  real_T c3_localMin;
  real_T c3_significand;
  int32_T c3_exponent;
  boolean_T c3_isLoggingEnabledHere;
  (void)chartInstance;
  c3_isLoggingEnabledHere = (c3_index >= 0);
  if (c3_isLoggingEnabledHere) {
    c3_b_table = (emlrtLocationLoggingDataType *)&c3_table[c3_index];
    c3_localMin = c3_b_table[0U].SimMin;
    c3_localMax = c3_b_table[0U].SimMax;
    c3_histTable = c3_b_table[0U].HistogramTable;

    /* Simulation Min-Max logging. */
    if (c3_in < c3_localMin) {
      c3_localMin = c3_in;
    }

    if (c3_in > c3_localMax) {
      c3_localMax = c3_in;
    }

    /* Histogram logging. */
    c3_inDouble = c3_in;
    c3_histTable->TotalNumberOfValues++;
    if (c3_inDouble == 0.0) {
      c3_histTable->NumberOfZeros++;
    } else {
      c3_histTable->SimSum += c3_inDouble;
      if ((!muDoubleScalarIsInf(c3_inDouble)) && (!muDoubleScalarIsNaN
           (c3_inDouble))) {
        c3_significand = frexp(c3_inDouble, &c3_exponent);
        if (c3_exponent > 128) {
          c3_exponent = 128;
        }

        if (c3_exponent < -127) {
          c3_exponent = -127;
        }

        if (c3_significand < 0.0) {
          c3_histTable->NumberOfNegativeValues++;
          c3_histTable->HistogramOfNegativeValues[127 + c3_exponent]++;
        } else {
          c3_histTable->NumberOfPositiveValues++;
          c3_histTable->HistogramOfPositiveValues[127 + c3_exponent]++;
        }
      }
    }

    c3_b_table[0U].SimMin = c3_localMin;
    c3_b_table[0U].SimMax = c3_localMax;

    /* IsAlwaysInteger logging. */
    if (c3_in != muDoubleScalarFloor(c3_in)) {
      c3_b_table[0U].IsAlwaysInteger = false;
    }
  }

  return c3_in;
}

static c3_slBus15_Vel c3_emlrt_update_log_2(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, c3_slBus15_Vel c3_in, emlrtLocationLoggingDataType c3_table[],
  int32_T c3_index)
{
  c3_slBus15_Vel c3_out;
  c3_out = c3_in;
  c3_b_emlrt_update_log_2(chartInstance, &c3_out, c3_table, c3_index);
  return c3_out;
}

static c3_Disp c3_emlrt_update_log_3(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, c3_Disp c3_in, emlrtLocationLoggingDataType c3_table[],
  int32_T c3_index)
{
  c3_Disp c3_out;
  c3_out = c3_in;
  c3_b_emlrt_update_log_3(chartInstance, &c3_out, c3_table, c3_index);
  return c3_out;
}

static void c3_emlrt_update_log_4(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c3_in[4], emlrtLocationLoggingDataType c3_table[],
  int32_T c3_index, real_T c3_out[4])
{
  int32_T c3_i;
  for (c3_i = 0; c3_i < 4; c3_i++) {
    c3_out[c3_i] = c3_in[c3_i];
  }

  c3_b_emlrt_update_log_4(chartInstance, c3_out, c3_table, c3_index);
}

static void c3_emlrt_update_log_5(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c3_in[37971], emlrtLocationLoggingDataType c3_table[],
  int32_T c3_index, real_T c3_out[37971])
{
  int32_T c3_i;
  for (c3_i = 0; c3_i < 37971; c3_i++) {
    c3_out[c3_i] = c3_in[c3_i];
  }

  c3_b_emlrt_update_log_5(chartInstance, c3_out, c3_table, c3_index);
}

static void c3_emlrt_update_log_6(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c3_in[27], emlrtLocationLoggingDataType c3_table[],
  int32_T c3_index, real_T c3_out[27])
{
  int32_T c3_i;
  for (c3_i = 0; c3_i < 27; c3_i++) {
    c3_out[c3_i] = c3_in[c3_i];
  }

  c3_b_emlrt_update_log_6(chartInstance, c3_out, c3_table, c3_index);
}

static void c3_emlrt_update_log_7(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c3_in[63], emlrtLocationLoggingDataType c3_table[],
  int32_T c3_index, real_T c3_out[63])
{
  int32_T c3_i;
  for (c3_i = 0; c3_i < 63; c3_i++) {
    c3_out[c3_i] = c3_in[c3_i];
  }

  c3_b_emlrt_update_log_7(chartInstance, c3_out, c3_table, c3_index);
}

static void c3_emlrt_update_log_8(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c3_in[51], emlrtLocationLoggingDataType c3_table[],
  int32_T c3_index, real_T c3_out[51])
{
  int32_T c3_i;
  for (c3_i = 0; c3_i < 51; c3_i++) {
    c3_out[c3_i] = c3_in[c3_i];
  }

  c3_b_emlrt_update_log_8(chartInstance, c3_out, c3_table, c3_index);
}

static void c3_emlrt_update_log_9(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c3_in[2], emlrtLocationLoggingDataType c3_table[],
  int32_T c3_index, real_T c3_out[2])
{
  int32_T c3_i;
  for (c3_i = 0; c3_i < 2; c3_i++) {
    c3_out[c3_i] = c3_in[c3_i];
  }

  c3_b_emlrt_update_log_9(chartInstance, c3_out, c3_table, c3_index);
}

static void c3_emlrtInitVarDataTables(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, emlrtLocationLoggingDataType c3_dataTables[195],
  emlrtLocationLoggingHistogramType c3_histTables[195])
{
  int32_T c3_i;
  int32_T c3_iH;
  (void)chartInstance;
  for (c3_i = 0; c3_i < 195; c3_i++) {
    c3_dataTables[c3_i].SimMin = rtInf;
    c3_dataTables[c3_i].SimMax = rtMinusInf;
    c3_dataTables[c3_i].OverflowWraps = 0;
    c3_dataTables[c3_i].Saturations = 0;
    c3_dataTables[c3_i].IsAlwaysInteger = true;
    c3_dataTables[c3_i].HistogramTable = &c3_histTables[c3_i];
    c3_histTables[c3_i].NumberOfZeros = 0.0;
    c3_histTables[c3_i].NumberOfPositiveValues = 0.0;
    c3_histTables[c3_i].NumberOfNegativeValues = 0.0;
    c3_histTables[c3_i].TotalNumberOfValues = 0.0;
    c3_histTables[c3_i].SimSum = 0.0;
    for (c3_iH = 0; c3_iH < 256; c3_iH++) {
      c3_histTables[c3_i].HistogramOfPositiveValues[c3_iH] = 0.0;
      c3_histTables[c3_i].HistogramOfNegativeValues[c3_iH] = 0.0;
    }
  }
}

const mxArray *sf_c3_car_model_FIXED_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c3_nameCaptureInfo;
}

static void c3_sqrt(SFc3_car_model_FIXEDInstanceStruct *chartInstance, const
                    emlrtStack *c3_sp, real_T c3_x[51], real_T c3_b_x[51])
{
  int32_T c3_i;
  for (c3_i = 0; c3_i < 51; c3_i++) {
    c3_b_x[c3_i] = c3_x[c3_i];
  }

  c3_c_sqrt(chartInstance, c3_sp, c3_b_x);
}

static void c3_minimum(SFc3_car_model_FIXEDInstanceStruct *chartInstance, real_T
  c3_x[51], real_T *c3_ex, int32_T *c3_idx)
{
  real_T c3_b_ex;
  real_T c3_b_x;
  real_T c3_c_ex;
  real_T c3_c_x;
  real_T c3_d_ex;
  real_T c3_d_x;
  real_T c3_e_x;
  int32_T c3_b_idx;
  int32_T c3_b_k;
  int32_T c3_c_idx;
  int32_T c3_d_idx;
  int32_T c3_first;
  int32_T c3_i;
  int32_T c3_k;
  boolean_T c3_b;
  boolean_T c3_b_b;
  boolean_T c3_b_p;
  boolean_T c3_exitg1;
  boolean_T c3_p;
  (void)chartInstance;
  c3_b_x = c3_x[0];
  c3_c_x = c3_b_x;
  c3_b = muDoubleScalarIsNaN(c3_c_x);
  c3_p = !c3_b;
  if (c3_p) {
    c3_b_idx = 1;
  } else {
    c3_b_idx = 0;
    c3_k = 2;
    c3_exitg1 = false;
    while ((!c3_exitg1) && (c3_k < 52)) {
      c3_d_x = c3_x[c3_k - 1];
      c3_e_x = c3_d_x;
      c3_b_b = muDoubleScalarIsNaN(c3_e_x);
      c3_b_p = !c3_b_b;
      if (c3_b_p) {
        c3_b_idx = c3_k;
        c3_exitg1 = true;
      } else {
        c3_k++;
      }
    }
  }

  if (c3_b_idx == 0) {
    c3_b_ex = c3_x[0];
    c3_b_idx = 1;
  } else {
    c3_first = c3_b_idx;
    c3_c_ex = c3_x[c3_first - 1];
    c3_c_idx = c3_first;
    c3_i = c3_first;
    for (c3_b_k = c3_i + 1; c3_b_k < 52; c3_b_k++) {
      if (c3_c_ex > c3_x[c3_b_k - 1]) {
        c3_c_ex = c3_x[c3_b_k - 1];
        c3_c_idx = c3_b_k;
      }
    }

    c3_b_ex = c3_c_ex;
    c3_b_idx = c3_c_idx;
  }

  c3_d_ex = c3_b_ex;
  c3_d_idx = c3_b_idx;
  *c3_ex = c3_d_ex;
  *c3_idx = c3_d_idx;
}

static real_T c3_b_sqrt(SFc3_car_model_FIXEDInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, real_T c3_x)
{
  real_T c3_b_x;
  c3_b_x = c3_x;
  c3_d_sqrt(chartInstance, c3_sp, &c3_b_x);
  return c3_b_x;
}

static real_T c3_dot(SFc3_car_model_FIXEDInstanceStruct *chartInstance, real_T
                     c3_a[2], real_T c3_b[2])
{
  ptrdiff_t c3_incx_t;
  ptrdiff_t c3_incy_t;
  ptrdiff_t c3_n_t;
  real_T c3_a_data[2];
  real_T c3_b_data[2];
  int32_T c3_i;
  int32_T c3_i1;
  (void)chartInstance;
  for (c3_i = 0; c3_i < 2; c3_i++) {
    c3_a_data[c3_i] = c3_a[c3_i];
  }

  for (c3_i1 = 0; c3_i1 < 2; c3_i1++) {
    c3_b_data[c3_i1] = c3_b[c3_i1];
  }

  c3_n_t = (ptrdiff_t)2;
  c3_incx_t = (ptrdiff_t)1;
  c3_incy_t = (ptrdiff_t)1;
  return ddot(&c3_n_t, &c3_a_data[0], &c3_incx_t, &c3_b_data[0], &c3_incy_t);
}

static real_T c3_norm(SFc3_car_model_FIXEDInstanceStruct *chartInstance, real_T
                      c3_x[2])
{
  real_T c3_absxk;
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_scale;
  real_T c3_t;
  real_T c3_y;
  int32_T c3_b_k;
  int32_T c3_k;
  (void)chartInstance;
  c3_y = 0.0;
  c3_scale = 3.3121686421112381E-170;
  for (c3_k = 0; c3_k < 2; c3_k++) {
    c3_b_k = c3_k;
    c3_b_x = c3_x[c3_b_k];
    c3_c_x = c3_b_x;
    c3_d_x = c3_c_x;
    c3_absxk = muDoubleScalarAbs(c3_d_x);
    if (c3_absxk > c3_scale) {
      c3_t = c3_scale / c3_absxk;
      c3_y = 1.0 + c3_y * c3_t * c3_t;
      c3_scale = c3_absxk;
    } else {
      c3_t = c3_absxk / c3_scale;
      c3_y += c3_t * c3_t;
    }
  }

  return c3_scale * muDoubleScalarSqrt(c3_y);
}

static real_T c3_acos(SFc3_car_model_FIXEDInstanceStruct *chartInstance, const
                      emlrtStack *c3_sp, real_T c3_x)
{
  real_T c3_b_x;
  c3_b_x = c3_x;
  c3_b_acos(chartInstance, c3_sp, &c3_b_x);
  return c3_b_x;
}

static real_T c3_emlrt_marshallIn(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c3_b_Vnow, const char_T *c3_identifier)
{
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  c3_thisId.fIdentifier = (const char_T *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_Vnow), &c3_thisId);
  sf_mex_destroy(&c3_b_Vnow);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_d;
  real_T c3_y;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_emlrt_marshallIn(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c3_c_omega, const char_T *c3_identifier, real_T
  c3_y[4])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char_T *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_c_omega), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_c_omega);
}

static void c3_d_emlrt_marshallIn(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[4])
{
  real_T c3_c_dv[4];
  int32_T c3_i;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_c_dv, 1, 0, 0U, 1, 0U, 1, 4);
  for (c3_i = 0; c3_i < 4; c3_i++) {
    c3_y[c3_i] = c3_c_dv[c3_i];
  }

  sf_mex_destroy(&c3_u);
}

static uint8_T c3_e_emlrt_marshallIn(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_car_model_FIXED, const char_T
  *c3_identifier)
{
  emlrtMsgIdentifier c3_thisId;
  uint8_T c3_y;
  c3_thisId.fIdentifier = (const char_T *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_car_model_FIXED), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_car_model_FIXED);
  return c3_y;
}

static uint8_T c3_f_emlrt_marshallIn(SFc3_car_model_FIXEDInstanceStruct
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
  (SFc3_car_model_FIXEDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_chart_data_browse_helper(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, int32_T c3_ssIdNumber, const mxArray **c3_mxData, uint8_T
  *c3_isValueTooBig)
{
  const mxArray *c3_m = NULL;
  const mxArray *c3_m1 = NULL;
  real_T c3_d;
  real_T c3_d1;
  real_T c3_d10;
  real_T c3_d11;
  real_T c3_d12;
  real_T c3_d13;
  real_T c3_d14;
  real_T c3_d15;
  real_T c3_d16;
  real_T c3_d17;
  real_T c3_d18;
  real_T c3_d19;
  real_T c3_d2;
  real_T c3_d20;
  real_T c3_d3;
  real_T c3_d4;
  real_T c3_d5;
  real_T c3_d6;
  real_T c3_d7;
  real_T c3_d8;
  real_T c3_d9;
  *c3_mxData = NULL;
  *c3_mxData = NULL;
  *c3_isValueTooBig = 0U;
  switch (c3_ssIdNumber) {
   case 13U:
    c3_d = *chartInstance->c3_b_index_small;
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &c3_d, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 85U:
    c3_d1 = *chartInstance->c3_b_index_all;
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &c3_d1, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 9U:
    c3_d2 = *chartInstance->c3_psi;
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &c3_d2, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 25U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_deg2rad,
      0, 0U, 0U, 0U, 0), false);
    break;

   case 26U:
    c3_m = NULL;
    sf_mex_assign(&c3_m, sf_mex_createstruct("mxData", 0, NULL, 0), false);
    sf_mex_addfield(c3_m, sf_mex_create("mxData", (real_T *)&((char_T *)
      chartInstance->c3_Vg)[0], 0, 0U, 0U, 0U, 0), "xdot", "mxData", 0);
    sf_mex_addfield(c3_m, sf_mex_create("mxData", (real_T *)&((char_T *)
      chartInstance->c3_Vg)[8], 0, 0U, 0U, 0U, 0), "ydot", "mxData", 0);
    sf_mex_addfield(c3_m, sf_mex_create("mxData", (real_T *)&((char_T *)
      chartInstance->c3_Vg)[16], 0, 0U, 0U, 0U, 0), "zdot", "mxData", 0);
    sf_mex_assign(c3_mxData, c3_m, false);
    break;

   case 74U:
    c3_d3 = *chartInstance->c3_yaw;
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &c3_d3, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 10U:
    c3_m1 = NULL;
    sf_mex_assign(&c3_m1, sf_mex_createstruct("mxData", 0, NULL, 0), false);
    sf_mex_addfield(c3_m1, sf_mex_create("mxData", (real_T *)&((char_T *)
      chartInstance->c3_pos)[0], 0, 0U, 0U, 0U, 0), "X", "mxData", 0);
    sf_mex_addfield(c3_m1, sf_mex_create("mxData", (real_T *)&((char_T *)
      chartInstance->c3_pos)[8], 0, 0U, 0U, 0U, 0), "Y", "mxData", 0);
    sf_mex_addfield(c3_m1, sf_mex_create("mxData", (real_T *)&((char_T *)
      chartInstance->c3_pos)[16], 0, 0U, 0U, 0U, 0), "Z", "mxData", 0);
    sf_mex_assign(c3_mxData, c3_m1, false);
    break;

   case 91U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_b_omega,
      0, 0U, 1U, 0U, 1, 4), false);
    break;

   case 12U:
    c3_d4 = *chartInstance->c3_b_index_small;
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &c3_d4, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 86U:
    c3_d5 = *chartInstance->c3_b_index_all;
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &c3_d5, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 27U:
    c3_d6 = *chartInstance->c3_v_error;
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &c3_d6, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 5U:
    c3_d7 = *chartInstance->c3_d_error;
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &c3_d7, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 7U:
    c3_d8 = *chartInstance->c3_psi_error;
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &c3_d8, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 28U:
    c3_d9 = *chartInstance->c3_v_cog;
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &c3_d9, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 60U:
    c3_d10 = *chartInstance->c3_r_ref;
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &c3_d10, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 61U:
    c3_d11 = *chartInstance->c3_r_error;
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &c3_d11, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 70U:
    c3_d12 = *chartInstance->c3_x_ref;
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &c3_d12, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 71U:
    c3_d13 = *chartInstance->c3_y_ref;
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &c3_d13, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 83U:
    c3_d14 = *chartInstance->c3_yaw_ref;
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &c3_d14, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 64U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_b_omega,
      0, 0U, 1U, 0U, 1, 4), false);
    break;

   case 92U:
    c3_d15 = *chartInstance->c3_p_error;
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &c3_d15, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 93U:
    c3_d16 = *chartInstance->c3_Vnow;
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &c3_d16, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 66U:
    c3_d17 = *chartInstance->c3_ahead;
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &c3_d17, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 67U:
    c3_d18 = *chartInstance->c3_ahead;
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &c3_d18, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 72U:
    *c3_isValueTooBig = 1U;
    break;

   case 75U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_dIndex,
      0, 0U, 0U, 0U, 0), false);
    break;

   case 76U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_dx, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 77U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData",
      &chartInstance->c3_forward_look_straight, 0, 0U, 0U, 0U, 0), false);
    break;

   case 78U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData",
      &chartInstance->c3_forward_look_turn, 0, 0U, 0U, 0U, 0), false);
    break;

   case 79U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_q_thresh,
      0, 0U, 0U, 0U, 0), false);
    break;

   case 80U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", chartInstance->c3_indicies,
      0, 0U, 1U, 0U, 2, 1, 27), false);
    break;

   case 84U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData",
      chartInstance->c3_selected_maxvm, 0, 0U, 1U, 0U, 2, 21, 3), false);
    break;

   case 87U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_axb, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 88U:
    c3_d19 = *chartInstance->c3_di_now;
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &c3_d19, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 89U:
    c3_d20 = *chartInstance->c3_di_prev;
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &c3_d20, 0, 0U, 0U, 0U, 0),
                  false);
    break;
  }
}

static void c3_b_emlrt_update_log_2(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, c3_slBus15_Vel *c3_in, emlrtLocationLoggingDataType c3_table[],
  int32_T c3_index)
{
  emlrtLocationLoggingDataType *c3_b_table;
  emlrtLocationLoggingHistogramType *c3_b_histTable;
  emlrtLocationLoggingHistogramType *c3_c_histTable;
  emlrtLocationLoggingHistogramType *c3_histTable;
  real_T c3_b_inDouble;
  real_T c3_b_localMax;
  real_T c3_b_localMin;
  real_T c3_b_significand;
  real_T c3_c_inDouble;
  real_T c3_c_localMax;
  real_T c3_c_localMin;
  real_T c3_c_significand;
  real_T c3_inDouble;
  real_T c3_localMax;
  real_T c3_localMin;
  real_T c3_significand;
  int32_T c3_b_exponent;
  int32_T c3_c_exponent;
  int32_T c3_exponent;
  boolean_T c3_isLoggingEnabledHere;
  (void)chartInstance;
  c3_isLoggingEnabledHere = (c3_index >= 0);
  if (c3_isLoggingEnabledHere) {
    c3_b_table = (emlrtLocationLoggingDataType *)&c3_table[c3_index];
    c3_localMin = c3_b_table[0U].SimMin;
    c3_localMax = c3_b_table[0U].SimMax;
    c3_histTable = c3_b_table[0U].HistogramTable;

    /* Simulation Min-Max logging. */
    if (c3_in->xdot < c3_localMin) {
      c3_localMin = c3_in->xdot;
    }

    if (c3_in->xdot > c3_localMax) {
      c3_localMax = c3_in->xdot;
    }

    /* Histogram logging. */
    c3_inDouble = c3_in->xdot;
    c3_histTable->TotalNumberOfValues++;
    if (c3_inDouble == 0.0) {
      c3_histTable->NumberOfZeros++;
    } else {
      c3_histTable->SimSum += c3_inDouble;
      if ((!muDoubleScalarIsInf(c3_inDouble)) && (!muDoubleScalarIsNaN
           (c3_inDouble))) {
        c3_significand = frexp(c3_inDouble, &c3_exponent);
        if (c3_exponent > 128) {
          c3_exponent = 128;
        }

        if (c3_exponent < -127) {
          c3_exponent = -127;
        }

        if (c3_significand < 0.0) {
          c3_histTable->NumberOfNegativeValues++;
          c3_histTable->HistogramOfNegativeValues[127 + c3_exponent]++;
        } else {
          c3_histTable->NumberOfPositiveValues++;
          c3_histTable->HistogramOfPositiveValues[127 + c3_exponent]++;
        }
      }
    }

    c3_b_table[0U].SimMin = c3_localMin;
    c3_b_table[0U].SimMax = c3_localMax;

    /* IsAlwaysInteger logging. */
    if (c3_in->xdot != muDoubleScalarFloor(c3_in->xdot)) {
      c3_b_table[0U].IsAlwaysInteger = false;
    }

    c3_b_localMin = c3_b_table[1U].SimMin;
    c3_b_localMax = c3_b_table[1U].SimMax;
    c3_b_histTable = c3_b_table[1U].HistogramTable;

    /* Simulation Min-Max logging. */
    if (c3_in->ydot < c3_b_localMin) {
      c3_b_localMin = c3_in->ydot;
    }

    if (c3_in->ydot > c3_b_localMax) {
      c3_b_localMax = c3_in->ydot;
    }

    /* Histogram logging. */
    c3_b_inDouble = c3_in->ydot;
    c3_b_histTable->TotalNumberOfValues++;
    if (c3_b_inDouble == 0.0) {
      c3_b_histTable->NumberOfZeros++;
    } else {
      c3_b_histTable->SimSum += c3_b_inDouble;
      if ((!muDoubleScalarIsInf(c3_b_inDouble)) && (!muDoubleScalarIsNaN
           (c3_b_inDouble))) {
        c3_b_significand = frexp(c3_b_inDouble, &c3_b_exponent);
        if (c3_b_exponent > 128) {
          c3_b_exponent = 128;
        }

        if (c3_b_exponent < -127) {
          c3_b_exponent = -127;
        }

        if (c3_b_significand < 0.0) {
          c3_b_histTable->NumberOfNegativeValues++;
          c3_b_histTable->HistogramOfNegativeValues[127 + c3_b_exponent]++;
        } else {
          c3_b_histTable->NumberOfPositiveValues++;
          c3_b_histTable->HistogramOfPositiveValues[127 + c3_b_exponent]++;
        }
      }
    }

    c3_b_table[1U].SimMin = c3_b_localMin;
    c3_b_table[1U].SimMax = c3_b_localMax;

    /* IsAlwaysInteger logging. */
    if (c3_in->ydot != muDoubleScalarFloor(c3_in->ydot)) {
      c3_b_table[1U].IsAlwaysInteger = false;
    }

    c3_c_localMin = c3_b_table[2U].SimMin;
    c3_c_localMax = c3_b_table[2U].SimMax;
    c3_c_histTable = c3_b_table[2U].HistogramTable;

    /* Simulation Min-Max logging. */
    if (c3_in->zdot < c3_c_localMin) {
      c3_c_localMin = c3_in->zdot;
    }

    if (c3_in->zdot > c3_c_localMax) {
      c3_c_localMax = c3_in->zdot;
    }

    /* Histogram logging. */
    c3_c_inDouble = c3_in->zdot;
    c3_c_histTable->TotalNumberOfValues++;
    if (c3_c_inDouble == 0.0) {
      c3_c_histTable->NumberOfZeros++;
    } else {
      c3_c_histTable->SimSum += c3_c_inDouble;
      if ((!muDoubleScalarIsInf(c3_c_inDouble)) && (!muDoubleScalarIsNaN
           (c3_c_inDouble))) {
        c3_c_significand = frexp(c3_c_inDouble, &c3_c_exponent);
        if (c3_c_exponent > 128) {
          c3_c_exponent = 128;
        }

        if (c3_c_exponent < -127) {
          c3_c_exponent = -127;
        }

        if (c3_c_significand < 0.0) {
          c3_c_histTable->NumberOfNegativeValues++;
          c3_c_histTable->HistogramOfNegativeValues[127 + c3_c_exponent]++;
        } else {
          c3_c_histTable->NumberOfPositiveValues++;
          c3_c_histTable->HistogramOfPositiveValues[127 + c3_c_exponent]++;
        }
      }
    }

    c3_b_table[2U].SimMin = c3_c_localMin;
    c3_b_table[2U].SimMax = c3_c_localMax;

    /* IsAlwaysInteger logging. */
    if (c3_in->zdot != muDoubleScalarFloor(c3_in->zdot)) {
      c3_b_table[2U].IsAlwaysInteger = false;
    }
  }
}

static void c3_b_emlrt_update_log_3(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, c3_Disp *c3_in, emlrtLocationLoggingDataType c3_table[],
  int32_T c3_index)
{
  emlrtLocationLoggingDataType *c3_b_table;
  emlrtLocationLoggingHistogramType *c3_b_histTable;
  emlrtLocationLoggingHistogramType *c3_c_histTable;
  emlrtLocationLoggingHistogramType *c3_histTable;
  real_T c3_b_inDouble;
  real_T c3_b_localMax;
  real_T c3_b_localMin;
  real_T c3_b_significand;
  real_T c3_c_inDouble;
  real_T c3_c_localMax;
  real_T c3_c_localMin;
  real_T c3_c_significand;
  real_T c3_inDouble;
  real_T c3_localMax;
  real_T c3_localMin;
  real_T c3_significand;
  int32_T c3_b_exponent;
  int32_T c3_c_exponent;
  int32_T c3_exponent;
  boolean_T c3_isLoggingEnabledHere;
  (void)chartInstance;
  c3_isLoggingEnabledHere = (c3_index >= 0);
  if (c3_isLoggingEnabledHere) {
    c3_b_table = (emlrtLocationLoggingDataType *)&c3_table[c3_index];
    c3_localMin = c3_b_table[0U].SimMin;
    c3_localMax = c3_b_table[0U].SimMax;
    c3_histTable = c3_b_table[0U].HistogramTable;

    /* Simulation Min-Max logging. */
    if (c3_in->X < c3_localMin) {
      c3_localMin = c3_in->X;
    }

    if (c3_in->X > c3_localMax) {
      c3_localMax = c3_in->X;
    }

    /* Histogram logging. */
    c3_inDouble = c3_in->X;
    c3_histTable->TotalNumberOfValues++;
    if (c3_inDouble == 0.0) {
      c3_histTable->NumberOfZeros++;
    } else {
      c3_histTable->SimSum += c3_inDouble;
      if ((!muDoubleScalarIsInf(c3_inDouble)) && (!muDoubleScalarIsNaN
           (c3_inDouble))) {
        c3_significand = frexp(c3_inDouble, &c3_exponent);
        if (c3_exponent > 128) {
          c3_exponent = 128;
        }

        if (c3_exponent < -127) {
          c3_exponent = -127;
        }

        if (c3_significand < 0.0) {
          c3_histTable->NumberOfNegativeValues++;
          c3_histTable->HistogramOfNegativeValues[127 + c3_exponent]++;
        } else {
          c3_histTable->NumberOfPositiveValues++;
          c3_histTable->HistogramOfPositiveValues[127 + c3_exponent]++;
        }
      }
    }

    c3_b_table[0U].SimMin = c3_localMin;
    c3_b_table[0U].SimMax = c3_localMax;

    /* IsAlwaysInteger logging. */
    if (c3_in->X != muDoubleScalarFloor(c3_in->X)) {
      c3_b_table[0U].IsAlwaysInteger = false;
    }

    c3_b_localMin = c3_b_table[1U].SimMin;
    c3_b_localMax = c3_b_table[1U].SimMax;
    c3_b_histTable = c3_b_table[1U].HistogramTable;

    /* Simulation Min-Max logging. */
    if (c3_in->Y < c3_b_localMin) {
      c3_b_localMin = c3_in->Y;
    }

    if (c3_in->Y > c3_b_localMax) {
      c3_b_localMax = c3_in->Y;
    }

    /* Histogram logging. */
    c3_b_inDouble = c3_in->Y;
    c3_b_histTable->TotalNumberOfValues++;
    if (c3_b_inDouble == 0.0) {
      c3_b_histTable->NumberOfZeros++;
    } else {
      c3_b_histTable->SimSum += c3_b_inDouble;
      if ((!muDoubleScalarIsInf(c3_b_inDouble)) && (!muDoubleScalarIsNaN
           (c3_b_inDouble))) {
        c3_b_significand = frexp(c3_b_inDouble, &c3_b_exponent);
        if (c3_b_exponent > 128) {
          c3_b_exponent = 128;
        }

        if (c3_b_exponent < -127) {
          c3_b_exponent = -127;
        }

        if (c3_b_significand < 0.0) {
          c3_b_histTable->NumberOfNegativeValues++;
          c3_b_histTable->HistogramOfNegativeValues[127 + c3_b_exponent]++;
        } else {
          c3_b_histTable->NumberOfPositiveValues++;
          c3_b_histTable->HistogramOfPositiveValues[127 + c3_b_exponent]++;
        }
      }
    }

    c3_b_table[1U].SimMin = c3_b_localMin;
    c3_b_table[1U].SimMax = c3_b_localMax;

    /* IsAlwaysInteger logging. */
    if (c3_in->Y != muDoubleScalarFloor(c3_in->Y)) {
      c3_b_table[1U].IsAlwaysInteger = false;
    }

    c3_c_localMin = c3_b_table[2U].SimMin;
    c3_c_localMax = c3_b_table[2U].SimMax;
    c3_c_histTable = c3_b_table[2U].HistogramTable;

    /* Simulation Min-Max logging. */
    if (c3_in->Z < c3_c_localMin) {
      c3_c_localMin = c3_in->Z;
    }

    if (c3_in->Z > c3_c_localMax) {
      c3_c_localMax = c3_in->Z;
    }

    /* Histogram logging. */
    c3_c_inDouble = c3_in->Z;
    c3_c_histTable->TotalNumberOfValues++;
    if (c3_c_inDouble == 0.0) {
      c3_c_histTable->NumberOfZeros++;
    } else {
      c3_c_histTable->SimSum += c3_c_inDouble;
      if ((!muDoubleScalarIsInf(c3_c_inDouble)) && (!muDoubleScalarIsNaN
           (c3_c_inDouble))) {
        c3_c_significand = frexp(c3_c_inDouble, &c3_c_exponent);
        if (c3_c_exponent > 128) {
          c3_c_exponent = 128;
        }

        if (c3_c_exponent < -127) {
          c3_c_exponent = -127;
        }

        if (c3_c_significand < 0.0) {
          c3_c_histTable->NumberOfNegativeValues++;
          c3_c_histTable->HistogramOfNegativeValues[127 + c3_c_exponent]++;
        } else {
          c3_c_histTable->NumberOfPositiveValues++;
          c3_c_histTable->HistogramOfPositiveValues[127 + c3_c_exponent]++;
        }
      }
    }

    c3_b_table[2U].SimMin = c3_c_localMin;
    c3_b_table[2U].SimMax = c3_c_localMax;

    /* IsAlwaysInteger logging. */
    if (c3_in->Z != muDoubleScalarFloor(c3_in->Z)) {
      c3_b_table[2U].IsAlwaysInteger = false;
    }
  }
}

static void c3_b_emlrt_update_log_4(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c3_in[4], emlrtLocationLoggingDataType c3_table[],
  int32_T c3_index)
{
  emlrtLocationLoggingDataType *c3_b_table;
  emlrtLocationLoggingHistogramType *c3_histTable;
  real_T c3_inDouble;
  real_T c3_localMax;
  real_T c3_localMin;
  real_T c3_significand;
  int32_T c3_b_i;
  int32_T c3_exponent;
  int32_T c3_i;
  boolean_T c3_isLoggingEnabledHere;
  (void)chartInstance;
  c3_isLoggingEnabledHere = (c3_index >= 0);
  if (c3_isLoggingEnabledHere) {
    c3_b_table = (emlrtLocationLoggingDataType *)&c3_table[c3_index];
    c3_localMin = c3_b_table[0U].SimMin;
    c3_localMax = c3_b_table[0U].SimMax;
    c3_histTable = c3_b_table[0U].HistogramTable;
    for (c3_i = 0; c3_i < 4; c3_i++) {
      /* Simulation Min-Max logging. */
      if (c3_in[c3_i] < c3_localMin) {
        c3_localMin = c3_in[c3_i];
      }

      if (c3_in[c3_i] > c3_localMax) {
        c3_localMax = c3_in[c3_i];
      }

      /* Histogram logging. */
      c3_inDouble = c3_in[c3_i];
      c3_histTable->TotalNumberOfValues++;
      if (c3_inDouble == 0.0) {
        c3_histTable->NumberOfZeros++;
      } else {
        c3_histTable->SimSum += c3_inDouble;
        if ((!muDoubleScalarIsInf(c3_inDouble)) && (!muDoubleScalarIsNaN
             (c3_inDouble))) {
          c3_significand = frexp(c3_inDouble, &c3_exponent);
          if (c3_exponent > 128) {
            c3_exponent = 128;
          }

          if (c3_exponent < -127) {
            c3_exponent = -127;
          }

          if (c3_significand < 0.0) {
            c3_histTable->NumberOfNegativeValues++;
            c3_histTable->HistogramOfNegativeValues[127 + c3_exponent]++;
          } else {
            c3_histTable->NumberOfPositiveValues++;
            c3_histTable->HistogramOfPositiveValues[127 + c3_exponent]++;
          }
        }
      }
    }

    c3_b_table[0U].SimMin = c3_localMin;
    c3_b_table[0U].SimMax = c3_localMax;

    /* IsAlwaysInteger logging. */
    c3_b_i = 0;
    while (c3_b_table[0U].IsAlwaysInteger && (c3_b_i < 4)) {
      if (c3_in[c3_b_i] != muDoubleScalarFloor(c3_in[c3_b_i])) {
        c3_b_table[0U].IsAlwaysInteger = false;
      }

      c3_b_i++;
    }
  }
}

static void c3_b_emlrt_update_log_5(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c3_in[37971], emlrtLocationLoggingDataType c3_table[],
  int32_T c3_index)
{
  emlrtLocationLoggingDataType *c3_b_table;
  emlrtLocationLoggingHistogramType *c3_histTable;
  real_T c3_inDouble;
  real_T c3_localMax;
  real_T c3_localMin;
  real_T c3_significand;
  int32_T c3_b_i;
  int32_T c3_exponent;
  int32_T c3_i;
  boolean_T c3_isLoggingEnabledHere;
  (void)chartInstance;
  c3_isLoggingEnabledHere = (c3_index >= 0);
  if (c3_isLoggingEnabledHere) {
    c3_b_table = (emlrtLocationLoggingDataType *)&c3_table[c3_index];
    c3_localMin = c3_b_table[0U].SimMin;
    c3_localMax = c3_b_table[0U].SimMax;
    c3_histTable = c3_b_table[0U].HistogramTable;
    for (c3_i = 0; c3_i < 37971; c3_i++) {
      /* Simulation Min-Max logging. */
      if (c3_in[c3_i] < c3_localMin) {
        c3_localMin = c3_in[c3_i];
      }

      if (c3_in[c3_i] > c3_localMax) {
        c3_localMax = c3_in[c3_i];
      }

      /* Histogram logging. */
      c3_inDouble = c3_in[c3_i];
      c3_histTable->TotalNumberOfValues++;
      if (c3_inDouble == 0.0) {
        c3_histTable->NumberOfZeros++;
      } else {
        c3_histTable->SimSum += c3_inDouble;
        if ((!muDoubleScalarIsInf(c3_inDouble)) && (!muDoubleScalarIsNaN
             (c3_inDouble))) {
          c3_significand = frexp(c3_inDouble, &c3_exponent);
          if (c3_exponent > 128) {
            c3_exponent = 128;
          }

          if (c3_exponent < -127) {
            c3_exponent = -127;
          }

          if (c3_significand < 0.0) {
            c3_histTable->NumberOfNegativeValues++;
            c3_histTable->HistogramOfNegativeValues[127 + c3_exponent]++;
          } else {
            c3_histTable->NumberOfPositiveValues++;
            c3_histTable->HistogramOfPositiveValues[127 + c3_exponent]++;
          }
        }
      }
    }

    c3_b_table[0U].SimMin = c3_localMin;
    c3_b_table[0U].SimMax = c3_localMax;

    /* IsAlwaysInteger logging. */
    c3_b_i = 0;
    while (c3_b_table[0U].IsAlwaysInteger && (c3_b_i < 37971)) {
      if (c3_in[c3_b_i] != muDoubleScalarFloor(c3_in[c3_b_i])) {
        c3_b_table[0U].IsAlwaysInteger = false;
      }

      c3_b_i++;
    }
  }
}

static void c3_b_emlrt_update_log_6(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c3_in[27], emlrtLocationLoggingDataType c3_table[],
  int32_T c3_index)
{
  emlrtLocationLoggingDataType *c3_b_table;
  emlrtLocationLoggingHistogramType *c3_histTable;
  real_T c3_inDouble;
  real_T c3_localMax;
  real_T c3_localMin;
  real_T c3_significand;
  int32_T c3_b_i;
  int32_T c3_exponent;
  int32_T c3_i;
  boolean_T c3_isLoggingEnabledHere;
  (void)chartInstance;
  c3_isLoggingEnabledHere = (c3_index >= 0);
  if (c3_isLoggingEnabledHere) {
    c3_b_table = (emlrtLocationLoggingDataType *)&c3_table[c3_index];
    c3_localMin = c3_b_table[0U].SimMin;
    c3_localMax = c3_b_table[0U].SimMax;
    c3_histTable = c3_b_table[0U].HistogramTable;
    for (c3_i = 0; c3_i < 27; c3_i++) {
      /* Simulation Min-Max logging. */
      if (c3_in[c3_i] < c3_localMin) {
        c3_localMin = c3_in[c3_i];
      }

      if (c3_in[c3_i] > c3_localMax) {
        c3_localMax = c3_in[c3_i];
      }

      /* Histogram logging. */
      c3_inDouble = c3_in[c3_i];
      c3_histTable->TotalNumberOfValues++;
      if (c3_inDouble == 0.0) {
        c3_histTable->NumberOfZeros++;
      } else {
        c3_histTable->SimSum += c3_inDouble;
        if ((!muDoubleScalarIsInf(c3_inDouble)) && (!muDoubleScalarIsNaN
             (c3_inDouble))) {
          c3_significand = frexp(c3_inDouble, &c3_exponent);
          if (c3_exponent > 128) {
            c3_exponent = 128;
          }

          if (c3_exponent < -127) {
            c3_exponent = -127;
          }

          if (c3_significand < 0.0) {
            c3_histTable->NumberOfNegativeValues++;
            c3_histTable->HistogramOfNegativeValues[127 + c3_exponent]++;
          } else {
            c3_histTable->NumberOfPositiveValues++;
            c3_histTable->HistogramOfPositiveValues[127 + c3_exponent]++;
          }
        }
      }
    }

    c3_b_table[0U].SimMin = c3_localMin;
    c3_b_table[0U].SimMax = c3_localMax;

    /* IsAlwaysInteger logging. */
    c3_b_i = 0;
    while (c3_b_table[0U].IsAlwaysInteger && (c3_b_i < 27)) {
      if (c3_in[c3_b_i] != muDoubleScalarFloor(c3_in[c3_b_i])) {
        c3_b_table[0U].IsAlwaysInteger = false;
      }

      c3_b_i++;
    }
  }
}

static void c3_b_emlrt_update_log_7(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c3_in[63], emlrtLocationLoggingDataType c3_table[],
  int32_T c3_index)
{
  emlrtLocationLoggingDataType *c3_b_table;
  emlrtLocationLoggingHistogramType *c3_histTable;
  real_T c3_inDouble;
  real_T c3_localMax;
  real_T c3_localMin;
  real_T c3_significand;
  int32_T c3_b_i;
  int32_T c3_exponent;
  int32_T c3_i;
  boolean_T c3_isLoggingEnabledHere;
  (void)chartInstance;
  c3_isLoggingEnabledHere = (c3_index >= 0);
  if (c3_isLoggingEnabledHere) {
    c3_b_table = (emlrtLocationLoggingDataType *)&c3_table[c3_index];
    c3_localMin = c3_b_table[0U].SimMin;
    c3_localMax = c3_b_table[0U].SimMax;
    c3_histTable = c3_b_table[0U].HistogramTable;
    for (c3_i = 0; c3_i < 63; c3_i++) {
      /* Simulation Min-Max logging. */
      if (c3_in[c3_i] < c3_localMin) {
        c3_localMin = c3_in[c3_i];
      }

      if (c3_in[c3_i] > c3_localMax) {
        c3_localMax = c3_in[c3_i];
      }

      /* Histogram logging. */
      c3_inDouble = c3_in[c3_i];
      c3_histTable->TotalNumberOfValues++;
      if (c3_inDouble == 0.0) {
        c3_histTable->NumberOfZeros++;
      } else {
        c3_histTable->SimSum += c3_inDouble;
        if ((!muDoubleScalarIsInf(c3_inDouble)) && (!muDoubleScalarIsNaN
             (c3_inDouble))) {
          c3_significand = frexp(c3_inDouble, &c3_exponent);
          if (c3_exponent > 128) {
            c3_exponent = 128;
          }

          if (c3_exponent < -127) {
            c3_exponent = -127;
          }

          if (c3_significand < 0.0) {
            c3_histTable->NumberOfNegativeValues++;
            c3_histTable->HistogramOfNegativeValues[127 + c3_exponent]++;
          } else {
            c3_histTable->NumberOfPositiveValues++;
            c3_histTable->HistogramOfPositiveValues[127 + c3_exponent]++;
          }
        }
      }
    }

    c3_b_table[0U].SimMin = c3_localMin;
    c3_b_table[0U].SimMax = c3_localMax;

    /* IsAlwaysInteger logging. */
    c3_b_i = 0;
    while (c3_b_table[0U].IsAlwaysInteger && (c3_b_i < 63)) {
      if (c3_in[c3_b_i] != muDoubleScalarFloor(c3_in[c3_b_i])) {
        c3_b_table[0U].IsAlwaysInteger = false;
      }

      c3_b_i++;
    }
  }
}

static void c3_b_emlrt_update_log_8(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c3_in[51], emlrtLocationLoggingDataType c3_table[],
  int32_T c3_index)
{
  emlrtLocationLoggingDataType *c3_b_table;
  emlrtLocationLoggingHistogramType *c3_histTable;
  real_T c3_inDouble;
  real_T c3_localMax;
  real_T c3_localMin;
  real_T c3_significand;
  int32_T c3_b_i;
  int32_T c3_exponent;
  int32_T c3_i;
  boolean_T c3_isLoggingEnabledHere;
  (void)chartInstance;
  c3_isLoggingEnabledHere = (c3_index >= 0);
  if (c3_isLoggingEnabledHere) {
    c3_b_table = (emlrtLocationLoggingDataType *)&c3_table[c3_index];
    c3_localMin = c3_b_table[0U].SimMin;
    c3_localMax = c3_b_table[0U].SimMax;
    c3_histTable = c3_b_table[0U].HistogramTable;
    for (c3_i = 0; c3_i < 51; c3_i++) {
      /* Simulation Min-Max logging. */
      if (c3_in[c3_i] < c3_localMin) {
        c3_localMin = c3_in[c3_i];
      }

      if (c3_in[c3_i] > c3_localMax) {
        c3_localMax = c3_in[c3_i];
      }

      /* Histogram logging. */
      c3_inDouble = c3_in[c3_i];
      c3_histTable->TotalNumberOfValues++;
      if (c3_inDouble == 0.0) {
        c3_histTable->NumberOfZeros++;
      } else {
        c3_histTable->SimSum += c3_inDouble;
        if ((!muDoubleScalarIsInf(c3_inDouble)) && (!muDoubleScalarIsNaN
             (c3_inDouble))) {
          c3_significand = frexp(c3_inDouble, &c3_exponent);
          if (c3_exponent > 128) {
            c3_exponent = 128;
          }

          if (c3_exponent < -127) {
            c3_exponent = -127;
          }

          if (c3_significand < 0.0) {
            c3_histTable->NumberOfNegativeValues++;
            c3_histTable->HistogramOfNegativeValues[127 + c3_exponent]++;
          } else {
            c3_histTable->NumberOfPositiveValues++;
            c3_histTable->HistogramOfPositiveValues[127 + c3_exponent]++;
          }
        }
      }
    }

    c3_b_table[0U].SimMin = c3_localMin;
    c3_b_table[0U].SimMax = c3_localMax;

    /* IsAlwaysInteger logging. */
    c3_b_i = 0;
    while (c3_b_table[0U].IsAlwaysInteger && (c3_b_i < 51)) {
      if (c3_in[c3_b_i] != muDoubleScalarFloor(c3_in[c3_b_i])) {
        c3_b_table[0U].IsAlwaysInteger = false;
      }

      c3_b_i++;
    }
  }
}

static void c3_b_emlrt_update_log_9(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance, real_T c3_in[2], emlrtLocationLoggingDataType c3_table[],
  int32_T c3_index)
{
  emlrtLocationLoggingDataType *c3_b_table;
  emlrtLocationLoggingHistogramType *c3_histTable;
  real_T c3_inDouble;
  real_T c3_localMax;
  real_T c3_localMin;
  real_T c3_significand;
  int32_T c3_b_i;
  int32_T c3_exponent;
  int32_T c3_i;
  boolean_T c3_isLoggingEnabledHere;
  (void)chartInstance;
  c3_isLoggingEnabledHere = (c3_index >= 0);
  if (c3_isLoggingEnabledHere) {
    c3_b_table = (emlrtLocationLoggingDataType *)&c3_table[c3_index];
    c3_localMin = c3_b_table[0U].SimMin;
    c3_localMax = c3_b_table[0U].SimMax;
    c3_histTable = c3_b_table[0U].HistogramTable;
    for (c3_i = 0; c3_i < 2; c3_i++) {
      /* Simulation Min-Max logging. */
      if (c3_in[c3_i] < c3_localMin) {
        c3_localMin = c3_in[c3_i];
      }

      if (c3_in[c3_i] > c3_localMax) {
        c3_localMax = c3_in[c3_i];
      }

      /* Histogram logging. */
      c3_inDouble = c3_in[c3_i];
      c3_histTable->TotalNumberOfValues++;
      if (c3_inDouble == 0.0) {
        c3_histTable->NumberOfZeros++;
      } else {
        c3_histTable->SimSum += c3_inDouble;
        if ((!muDoubleScalarIsInf(c3_inDouble)) && (!muDoubleScalarIsNaN
             (c3_inDouble))) {
          c3_significand = frexp(c3_inDouble, &c3_exponent);
          if (c3_exponent > 128) {
            c3_exponent = 128;
          }

          if (c3_exponent < -127) {
            c3_exponent = -127;
          }

          if (c3_significand < 0.0) {
            c3_histTable->NumberOfNegativeValues++;
            c3_histTable->HistogramOfNegativeValues[127 + c3_exponent]++;
          } else {
            c3_histTable->NumberOfPositiveValues++;
            c3_histTable->HistogramOfPositiveValues[127 + c3_exponent]++;
          }
        }
      }
    }

    c3_b_table[0U].SimMin = c3_localMin;
    c3_b_table[0U].SimMax = c3_localMax;

    /* IsAlwaysInteger logging. */
    c3_b_i = 0;
    while (c3_b_table[0U].IsAlwaysInteger && (c3_b_i < 2)) {
      if (c3_in[c3_b_i] != muDoubleScalarFloor(c3_in[c3_b_i])) {
        c3_b_table[0U].IsAlwaysInteger = false;
      }

      c3_b_i++;
    }
  }
}

static void c3_c_sqrt(SFc3_car_model_FIXEDInstanceStruct *chartInstance, const
                      emlrtStack *c3_sp, real_T c3_x[51])
{
  static char_T c3_b_cv[4] = { 's', 'q', 'r', 't' };

  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_y = NULL;
  real_T c3_b_x[51];
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
  for (c3_i = 0; c3_i < 51; c3_i++) {
    c3_b_x[c3_i] = c3_x[c3_i];
  }

  c3_p = false;
  for (c3_k = 0; c3_k < 51; c3_k++) {
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
    sf_mex_assign(&c3_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c3_b_y = NULL;
    sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c3_c_y = NULL;
    sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_b_cv, 10, 0U, 1U, 0U, 2, 1, 4),
                  false);
    sf_mex_call(c3_sp, &c3_emlrtMCI, "error", 0U, 2U, 14, c3_y, 14, sf_mex_call
                (c3_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call(c3_sp, NULL,
      "message", 1U, 2U, 14, c3_b_y, 14, c3_c_y)));
  }

  for (c3_c_k = 0; c3_c_k < 51; c3_c_k++) {
    c3_d_k = c3_c_k;
    c3_c_x = c3_x[c3_d_k];
    c3_d_x = c3_c_x;
    c3_d_x = muDoubleScalarSqrt(c3_d_x);
    c3_x[c3_d_k] = c3_d_x;
  }
}

static void c3_d_sqrt(SFc3_car_model_FIXEDInstanceStruct *chartInstance, const
                      emlrtStack *c3_sp, real_T *c3_x)
{
  static char_T c3_b_cv[4] = { 's', 'q', 'r', 't' };

  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_y = NULL;
  real_T c3_b_x;
  boolean_T c3_b_p;
  boolean_T c3_p;
  (void)chartInstance;
  c3_b_x = *c3_x;
  if (c3_b_x < 0.0) {
    c3_p = true;
  } else {
    c3_p = false;
  }

  c3_b_p = c3_p;
  if (c3_b_p) {
    c3_y = NULL;
    sf_mex_assign(&c3_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c3_b_y = NULL;
    sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c3_c_y = NULL;
    sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_b_cv, 10, 0U, 1U, 0U, 2, 1, 4),
                  false);
    sf_mex_call(c3_sp, &c3_emlrtMCI, "error", 0U, 2U, 14, c3_y, 14, sf_mex_call
                (c3_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call(c3_sp, NULL,
      "message", 1U, 2U, 14, c3_b_y, 14, c3_c_y)));
  }

  *c3_x = muDoubleScalarSqrt(*c3_x);
}

static void c3_b_acos(SFc3_car_model_FIXEDInstanceStruct *chartInstance, const
                      emlrtStack *c3_sp, real_T *c3_x)
{
  static char_T c3_b_cv[4] = { 'a', 'c', 'o', 's' };

  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_y = NULL;
  real_T c3_b_x;
  boolean_T c3_b;
  boolean_T c3_b1;
  boolean_T c3_b_p;
  boolean_T c3_p;
  (void)chartInstance;
  c3_b_x = *c3_x;
  c3_b = (c3_b_x < -1.0);
  c3_b1 = (c3_b_x > 1.0);
  if (c3_b || c3_b1) {
    c3_p = true;
  } else {
    c3_p = false;
  }

  c3_b_p = c3_p;
  if (c3_b_p) {
    c3_y = NULL;
    sf_mex_assign(&c3_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c3_b_y = NULL;
    sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c3_c_y = NULL;
    sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_b_cv, 10, 0U, 1U, 0U, 2, 1, 4),
                  false);
    sf_mex_call(c3_sp, &c3_e_emlrtMCI, "error", 0U, 2U, 14, c3_y, 14,
                sf_mex_call(c3_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c3_sp, NULL, "message", 1U, 2U, 14, c3_b_y, 14, c3_c_y)));
  }

  *c3_x = muDoubleScalarAcos(*c3_x);
}

static int32_T c3__s32_add__(SFc3_car_model_FIXEDInstanceStruct *chartInstance,
  int32_T c3_b, int32_T c3_c, int32_T c3_EMLOvCount_src_loc, uint32_T
  c3_ssid_src_loc, int32_T c3_offset_src_loc, int32_T c3_length_src_loc)
{
  real_T c3_d;
  int32_T c3_PICOffset;
  int32_T c3_a;
  observerLogReadPIC(&c3_PICOffset);
  c3_a = c3_b + c3_c;
  if (((c3_a ^ c3_b) & (c3_a ^ c3_c)) < 0) {
    sf_data_overflow_error(chartInstance->S, c3_ssid_src_loc, c3_offset_src_loc,
      c3_length_src_loc);
    c3_d = 1.0;
    observerLog(c3_EMLOvCount_src_loc + c3_PICOffset, &c3_d, 1);
  }

  return c3_a;
}

static int32_T c3__s32_minus__(SFc3_car_model_FIXEDInstanceStruct *chartInstance,
  int32_T c3_b, int32_T c3_c, int32_T c3_EMLOvCount_src_loc, uint32_T
  c3_ssid_src_loc, int32_T c3_offset_src_loc, int32_T c3_length_src_loc)
{
  real_T c3_d;
  int32_T c3_PICOffset;
  int32_T c3_a;
  observerLogReadPIC(&c3_PICOffset);
  c3_a = c3_b - c3_c;
  if (((c3_b ^ c3_a) & (c3_b ^ c3_c)) < 0) {
    sf_data_overflow_error(chartInstance->S, c3_ssid_src_loc, c3_offset_src_loc,
      c3_length_src_loc);
    c3_d = 1.0;
    observerLog(c3_EMLOvCount_src_loc + c3_PICOffset, &c3_d, 1);
  }

  return c3_a;
}

static void init_dsm_address_info(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc3_car_model_FIXEDInstanceStruct
  *chartInstance)
{
  chartInstance->c3_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c3_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c3_index_small = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c3_index_all = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_psi = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c3_Vg = (c3_slBus15_Vel *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c3_yaw = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c3_pos = (c3_Disp *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c3_omega = (real_T (*)[4])ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c3_b_index_small = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_b_index_all = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c3_v_error = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c3_d_error = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c3_psi_error = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c3_v_cog = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c3_r_ref = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c3_r_error = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c3_x_ref = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 9);
  chartInstance->c3_y_ref = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 10);
  chartInstance->c3_yaw_ref = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 11);
  chartInstance->c3_b_omega = (real_T (*)[4])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 12);
  chartInstance->c3_p_error = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 13);
  chartInstance->c3_Vnow = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 14);
  chartInstance->c3_ahead = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 15);
  chartInstance->c3_b_ahead = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c3_di_now = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 16);
  chartInstance->c3_di_prev = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 8);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c3_car_model_FIXED_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(991410037U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(635897193U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1359025094U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1840302883U);
}

mxArray *sf_c3_car_model_FIXED_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString("coder.internal.blas.BLASApi"));
  return(mxcell3p);
}

mxArray *sf_c3_car_model_FIXED_jit_fallback_info(void)
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

mxArray *sf_c3_car_model_FIXED_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c3_car_model_FIXED(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNrNlcFKw0AQhjeSRkuxKHjsoUePghdBwRxUyMFSQVtvy5Ld1kCSDZuaJrc8mkcfx0dwN1lrXAI"
    "NW6G7MAz/wEzmY2YIsLxHwN+Q2+cxAA73R9wOQP16UlvcTqWv4/YmPua2KhIi4inzPcx9jKJKo/"
    "fcixe0qn8Ffus7LfWtRv2+jNfv63anfHfuivyLRr7dkm838k+4msV0PZR6r/2XU1fNb+u/96f/W"
    "qM3grDsf+8c4KwTx6HCITSGhDHKDOGYdeJwFA6hcQD5Vhkyj/Kl4nC3cPQVDqGDGJMcojBscOx/"
    "LuedeAYKz2DDk0Y/RGbw6N89jcgSGcMx1777xKi7H2nfS5IGksSgeykn2nNhRs1lon0nDDKyMOZ"
    "ObrQ5MujTpTEc19p7lZm0V+WT9jxyk/bqQ5+jMIrjWXuvCrSuSP6HY+zull9/f7qFY6RwCB2kEP"
    "mrICPQv4Q+YjCimITwwXu9v2v+V74BKrx5oQ=="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_car_model_FIXED_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "s1rdZU9ozvyr7BKgH3old8C";
}

static void sf_opaque_initialize_c3_car_model_FIXED(void *chartInstanceVar)
{
  initialize_params_c3_car_model_FIXED((SFc3_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
  initialize_c3_car_model_FIXED((SFc3_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_car_model_FIXED(void *chartInstanceVar)
{
  enable_c3_car_model_FIXED((SFc3_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c3_car_model_FIXED(void *chartInstanceVar)
{
  disable_c3_car_model_FIXED((SFc3_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c3_car_model_FIXED(void *chartInstanceVar)
{
  sf_gateway_c3_car_model_FIXED((SFc3_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c3_car_model_FIXED(SimStruct* S)
{
  return get_sim_state_c3_car_model_FIXED((SFc3_car_model_FIXEDInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_car_model_FIXED(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c3_car_model_FIXED((SFc3_car_model_FIXEDInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c3_car_model_FIXED(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_car_model_FIXEDInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_car_model_FIXED_optimization_info();
    }

    mdl_cleanup_runtime_resources_c3_car_model_FIXED
      ((SFc3_car_model_FIXEDInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c3_car_model_FIXED(void *chartInstanceVar)
{
  mdl_start_c3_car_model_FIXED((SFc3_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_mdl_terminate_c3_car_model_FIXED(void *chartInstanceVar)
{
  mdl_terminate_c3_car_model_FIXED((SFc3_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_car_model_FIXED((SFc3_car_model_FIXEDInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_car_model_FIXED(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  sf_warn_if_symbolic_dimension_param_changed(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_car_model_FIXED((SFc3_car_model_FIXEDInstanceStruct*)
      sf_get_chart_instance_ptr(S));
    initSimStructsc3_car_model_FIXED((SFc3_car_model_FIXEDInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c3_car_model_FIXED_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [26] = {
    "eNrtWs1v40QUd6tuIbRbFYTgQCX2grQXJHZXiEWsIG0+2Ih+BJy2aC/R1H6JR7FnvDPjfKxA6h/",
    "Av4GEOHDjDjfEjRv/AjeOHHnjOGnW9bYeF7ZehKU0Hdu/ee/35n15HGuptWfhsYGf8B3LWsXvl/",
    "GzbE2PG8l4aeEzPb9iPUjGX61ZlsNd6AOzo16Pji2zg0VBmwgSSMv8YCSAL0ByP1KUsxbr8fxYy",
    "noggDk4QciFMpIraRD5lA2aEXO0ZHnsUcezPR757g5OSNwD5k+eJTeMVBsl1qkARzUBXOUJHvW9",
    "pk/6F1tBqFHNA2cgo8DYVhKUHYWaqtyLfEVDHxpjcFpMKoJWkJfwtRVRUFNjMyNrvtKeoXkQ+pS",
    "w/Lb2iLQhRO9QcBi6+PcgUmi9XFjHI0LtgEeGIHfpIJbOGeSSTiXefUIZUVxQ4jcCv6Zny8m37S",
    "PHPQwJ33SNkO+OADIIOWXKMCDsJtq5wciJD3U4ifqGcm14HOloOKIwAmG2vr0aH4IgfThgZjrHa",
    "9QYx045j6WcWEUDOCJi20HfleCa5Q0MOmkTdEfo4DRGWIhN3JIdQYfoG6a5rqXDv1Cui4Kp98tC",
    "2FhuYwjGfjWX23RYjfi+NMN2eLgLQ/Bj+XWiSAHsVL4BWErqdjh6h842hhkrYhQjIcHWOHNpfq8",
    "cplBxYdvHIpUDTgMdBuCimeeqzye6LI4iqXhQw5RT393NKe88tsUUiB5xIHeNEYRKQIVjvzKU61",
    "KpAwnRaCUVs8w9wzQGC0Et2YtYfcTFAG1sWszObKUjwQwNbh8Ts4I4yTXQu4+IH+XUOZB9jB90j",
    "0OJWdZMLmJ1/BQCO8TxwNWVk/qwh3kWJ8i7xFKX/G1kO6RqUgfpCBrmjaQIEzoWXW2lziSEQzZg",
    "fMSaggd20nld4FcAmDWIYJT1d7CEi0kTlc+ntYDHnTi7mzY52s5E+eRE+8anwLAaaq66ayAORlW",
    "DYYuMCl0Fa9Mn2MQwSaXCQj2Zlvpp3dP9+0PrrH9fyejfX1vo3zeTsXOv6xDRDXSv0m22vmzUrf",
    "l87y3Mt57jeeCVHDjrHO5M3uz79gJ+KUOutfCt768u3F9Zfvr+Skre8uzc7HjGPDdTcldS86wmN",
    "mysf//Wj7++8fNv33z73debf/yQ5p/WZ+mcPkvx/xo33jB7/tpIxluzPmqetYfnElse/3gz5R96",
    "LO8I99Hhh/zJcCI+2Pms//Ae9937tXi+X25erO+rKX1n52/p3g2DOs4Rwmm5yXOcHpNo+nyh57+",
    "/oO/qJfaoLPiXZf35yZXw1eNqeh2z7LXylL1WrCNMUYt+fG36n7araXyW/jdS663HxMNH11Q8Xh",
    "sP6/VcPF5K8dBjtwtCcFESHke5eKymeKzGPVIXvaok63F6WE3nySwelRSPSrzn4cK4iy1TRr6/v",
    "nW5nYvPWorP2pyPDGaMysGneNzzAPqkNDyOC8d9WKq43yocL6GkCZMSxcvpfuF1EaVal/3CcSK6",
    "AnqliZMHhXkMuw7vl4bHR4X9algmvzr9vPB6jMvkVz8V5zEpFY9OYb+akFHM5J/hcat6NfxUfvs",
    "SHlspHlvx3nyX6B0Y6GY/6S/yK/rcaoqznjPuRdHzf7v8+/zy7GNVCuI2C+Ks54y7Kj/T/bkX/f",
    "6L9oGs1P2bJeZxUb432actG6/fLbN907eT8cfz94Q1j/puxpuK5PIukF7W1f+If/9laL/ZPnFD2",
    "y/5Qcmje9uM+BNJp69ZZqfbQv8uYH5JAJHZ73+uo55k7ftn9VXrqfjW4xFlLh/Jd+/cff/uVerT",
    "3wXxegc=",
    ""
  };

  static char newstr [1809] = "";
  newstr[0] = '\0';
  for (i = 0; i < 26; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c3_car_model_FIXED(SimStruct *S)
{
  const char* newstr = sf_c3_car_model_FIXED_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(464129093U));
  ssSetChecksum1(S,(3239496373U));
  ssSetChecksum2(S,(2829421777U));
  ssSetChecksum3(S,(2934509693U));
}

static void mdlRTW_c3_car_model_FIXED(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c3_car_model_FIXED(SimStruct *S)
{
  SFc3_car_model_FIXEDInstanceStruct *chartInstance;
  chartInstance = (SFc3_car_model_FIXEDInstanceStruct *)utMalloc(sizeof
    (SFc3_car_model_FIXEDInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc3_car_model_FIXEDInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_car_model_FIXED;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_car_model_FIXED;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c3_car_model_FIXED;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c3_car_model_FIXED;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c3_car_model_FIXED;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_car_model_FIXED;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_car_model_FIXED;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_car_model_FIXED;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_car_model_FIXED;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_car_model_FIXED;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_car_model_FIXED;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_car_model_FIXED;
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

  mdl_setup_runtime_resources_c3_car_model_FIXED(chartInstance);
}

void c3_car_model_FIXED_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c3_car_model_FIXED(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_car_model_FIXED(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_car_model_FIXED(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_car_model_FIXED_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
