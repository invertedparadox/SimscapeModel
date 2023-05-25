#ifndef __c4_car_model_FIXED_h__
#define __c4_car_model_FIXED_h__

/* Forward Declarations */

/* Type Definitions */
#ifndef typedef_SFc4_car_model_FIXEDInstanceStruct
#define typedef_SFc4_car_model_FIXEDInstanceStruct

typedef struct {
  real_T c4_mu_star;
  real_T c4_lambda_star;
  SimStruct *S;
  ChartInfoStruct chartInfo;
  int32_T c4_sfEvent;
  boolean_T c4_doneDoubleBufferReInit;
  uint8_T c4_is_active_c4_car_model_FIXED;
  uint8_T c4_JITStateAnimation[1];
  uint8_T c4_JITTransitionAnimation[1];
  emlrtLocationLoggingDataType c4_emlrtLocationLoggingDataTables[10];
  int32_T c4_IsDebuggerActive;
  int32_T c4_IsSequenceViewerPresent;
  int32_T c4_SequenceViewerOptimization;
  int32_T c4_IsHeatMapPresent;
  void *c4_RuntimeVar;
  emlrtLocationLoggingHistogramType c4_emlrtLocLogHistTables[10];
  boolean_T c4_emlrtLocLogSimulated;
  uint32_T c4_mlFcnLineNumber;
  void *c4_fcnDataPtrs[4];
  char_T *c4_dataNames[4];
  uint32_T c4_numFcnVars;
  uint32_T c4_ssIds[4];
  uint32_T c4_statuses[4];
  void *c4_outMexFcns[4];
  void *c4_inMexFcns[4];
  CovrtStateflowInstance *c4_covrtInstance;
  void *c4_fEmlrtCtx;
  real_T (*c4_u)[4];
  real_T (*c4_y)[4];
} SFc4_car_model_FIXEDInstanceStruct;

#endif                                 /* typedef_SFc4_car_model_FIXEDInstanceStruct */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_car_model_FIXED_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_car_model_FIXED_get_check_sum(mxArray *plhs[]);
extern void c4_car_model_FIXED_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
