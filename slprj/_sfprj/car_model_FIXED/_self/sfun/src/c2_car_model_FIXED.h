#ifndef __c2_car_model_FIXED_h__
#define __c2_car_model_FIXED_h__

/* Forward Declarations */

/* Type Definitions */
#ifndef typedef_SFc2_car_model_FIXEDInstanceStruct
#define typedef_SFc2_car_model_FIXEDInstanceStruct

typedef struct {
  real_T c2_trackW;
  real_T c2_wheelB;
  SimStruct *S;
  ChartInfoStruct chartInfo;
  int32_T c2_sfEvent;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_car_model_FIXED;
  uint8_T c2_JITStateAnimation[1];
  uint8_T c2_JITTransitionAnimation[1];
  emlrtLocationLoggingDataType c2_emlrtLocationLoggingDataTables[7];
  int32_T c2_IsDebuggerActive;
  int32_T c2_IsSequenceViewerPresent;
  int32_T c2_SequenceViewerOptimization;
  int32_T c2_IsHeatMapPresent;
  void *c2_RuntimeVar;
  emlrtLocationLoggingHistogramType c2_emlrtLocLogHistTables[7];
  boolean_T c2_emlrtLocLogSimulated;
  uint32_T c2_mlFcnLineNumber;
  void *c2_fcnDataPtrs[7];
  char_T *c2_dataNames[7];
  uint32_T c2_numFcnVars;
  uint32_T c2_ssIds[7];
  uint32_T c2_statuses[7];
  void *c2_outMexFcns[7];
  void *c2_inMexFcns[7];
  CovrtStateflowInstance *c2_covrtInstance;
  void *c2_fEmlrtCtx;
  real_T (*c2_angles)[3];
  real_T (*c2_angleIn)[3];
  real_T (*c2_GeomXYZ)[3];
  real_T (*c2_GemoXYZIn)[3];
  real_T (*c2_Ground)[4];
} SFc2_car_model_FIXEDInstanceStruct;

#endif                                 /* typedef_SFc2_car_model_FIXEDInstanceStruct */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_car_model_FIXED_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_car_model_FIXED_get_check_sum(mxArray *plhs[]);
extern void c2_car_model_FIXED_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
