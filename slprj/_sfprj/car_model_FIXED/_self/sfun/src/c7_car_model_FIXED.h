#ifndef __c7_car_model_FIXED_h__
#define __c7_car_model_FIXED_h__

/* Forward Declarations */

/* Type Definitions */
#ifndef typedef_SFc7_car_model_FIXEDInstanceStruct
#define typedef_SFc7_car_model_FIXEDInstanceStruct

typedef struct {
  real_T c7_aero_coeff;
  SimStruct *S;
  ChartInfoStruct chartInfo;
  int32_T c7_sfEvent;
  boolean_T c7_doneDoubleBufferReInit;
  uint8_T c7_is_active_c7_car_model_FIXED;
  uint8_T c7_JITStateAnimation[1];
  uint8_T c7_JITTransitionAnimation[1];
  emlrtLocationLoggingDataType c7_emlrtLocationLoggingDataTables[5];
  int32_T c7_IsDebuggerActive;
  int32_T c7_IsSequenceViewerPresent;
  int32_T c7_SequenceViewerOptimization;
  int32_T c7_IsHeatMapPresent;
  void *c7_RuntimeVar;
  emlrtLocationLoggingHistogramType c7_emlrtLocLogHistTables[5];
  boolean_T c7_emlrtLocLogSimulated;
  uint32_T c7_mlFcnLineNumber;
  void *c7_fcnDataPtrs[4];
  char_T *c7_dataNames[4];
  uint32_T c7_numFcnVars;
  uint32_T c7_ssIds[4];
  uint32_T c7_statuses[4];
  void *c7_outMexFcns[4];
  void *c7_inMexFcns[4];
  CovrtStateflowInstance *c7_covrtInstance;
  void *c7_fEmlrtCtx;
  real_T *c7_u;
  real_T (*c7_y)[3];
} SFc7_car_model_FIXEDInstanceStruct;

#endif                                 /* typedef_SFc7_car_model_FIXEDInstanceStruct */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c7_car_model_FIXED_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c7_car_model_FIXED_get_check_sum(mxArray *plhs[]);
extern void c7_car_model_FIXED_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
