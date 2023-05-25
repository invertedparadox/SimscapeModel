#ifndef __c13_car_model_FIXED_h__
#define __c13_car_model_FIXED_h__

/* Forward Declarations */

/* Type Definitions */
#ifndef typedef_SFc13_car_model_FIXEDInstanceStruct
#define typedef_SFc13_car_model_FIXEDInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  int32_T c13_sfEvent;
  boolean_T c13_doneDoubleBufferReInit;
  uint8_T c13_is_active_c13_car_model_FIXED;
  uint8_T c13_JITStateAnimation[1];
  uint8_T c13_JITTransitionAnimation[1];
  emlrtLocationLoggingDataType c13_emlrtLocationLoggingDataTables[14];
  int32_T c13_IsDebuggerActive;
  int32_T c13_IsSequenceViewerPresent;
  int32_T c13_SequenceViewerOptimization;
  int32_T c13_IsHeatMapPresent;
  void *c13_RuntimeVar;
  emlrtLocationLoggingHistogramType c13_emlrtLocLogHistTables[14];
  boolean_T c13_emlrtLocLogSimulated;
  uint32_T c13_mlFcnLineNumber;
  void *c13_fcnDataPtrs[11];
  char_T *c13_dataNames[11];
  uint32_T c13_numFcnVars;
  uint32_T c13_ssIds[11];
  uint32_T c13_statuses[11];
  void *c13_outMexFcns[11];
  void *c13_inMexFcns[11];
  CovrtStateflowInstance *c13_covrtInstance;
  void *c13_fEmlrtCtx;
  real_T (*c13_rot_map)[9];
  real_T (*c13_state)[28];
  real_T (*c13_ang)[4];
  real_T (*c13_angvel)[3];
  real_T (*c13_pos)[3];
  real_T (*c13_vel)[3];
  real_T (*c13_accel)[3];
  real_T (*c13_mag)[3];
  real_T (*c13_accel_bias)[3];
  real_T (*c13_gyro_bias)[3];
  real_T (*c13_mag_bias)[3];
} SFc13_car_model_FIXEDInstanceStruct;

#endif                                 /* typedef_SFc13_car_model_FIXEDInstanceStruct */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c13_car_model_FIXED_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c13_car_model_FIXED_get_check_sum(mxArray *plhs[]);
extern void c13_car_model_FIXED_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
