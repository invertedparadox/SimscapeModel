#ifndef __c1_car_model_FIXED_h__
#define __c1_car_model_FIXED_h__

/* Forward Declarations */

/* Type Definitions */
#ifndef typedef_SFc1_car_model_FIXEDInstanceStruct
#define typedef_SFc1_car_model_FIXEDInstanceStruct

typedef struct {
  real_T c1_m_all;
  real_T c1_RE;
  real_T c1_IYY;
  real_T c1_br;
  SimStruct *S;
  ChartInfoStruct chartInfo;
  int32_T c1_sfEvent;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_car_model_FIXED;
  uint8_T c1_JITStateAnimation[1];
  uint8_T c1_JITTransitionAnimation[1];
  emlrtLocationLoggingDataType c1_emlrtLocationLoggingDataTables[60];
  int32_T c1_IsDebuggerActive;
  int32_T c1_IsSequenceViewerPresent;
  int32_T c1_SequenceViewerOptimization;
  int32_T c1_IsHeatMapPresent;
  void *c1_RuntimeVar;
  emlrtLocationLoggingHistogramType c1_emlrtLocLogHistTables[60];
  boolean_T c1_emlrtLocLogSimulated;
  uint32_T c1_mlFcnLineNumber;
  void *c1_fcnDataPtrs[18];
  char_T *c1_dataNames[18];
  uint32_T c1_numFcnVars;
  uint32_T c1_ssIds[18];
  uint32_T c1_statuses[18];
  void *c1_outMexFcns[18];
  void *c1_inMexFcns[18];
  CovrtStateflowInstance *c1_covrtInstance;
  void *c1_fEmlrtCtx;
  real_T (*c1_w_fake)[4];
  real_T (*c1_w)[4];
  real_T *c1_v;
  real_T (*c1_tau)[4];
  real_T (*c1_lambda0)[4];
  real_T *c1_vdot;
  real_T (*c1_lambda)[4];
  real_T *c1_d;
} SFc1_car_model_FIXEDInstanceStruct;

#endif                                 /* typedef_SFc1_car_model_FIXEDInstanceStruct */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_car_model_FIXED_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_car_model_FIXED_get_check_sum(mxArray *plhs[]);
extern void c1_car_model_FIXED_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
