#ifndef __c5_car_model_FIXED_h__
#define __c5_car_model_FIXED_h__

/* Forward Declarations */
#ifndef typedef_c5_slBus15_Vel
#define typedef_c5_slBus15_Vel

typedef struct c5_slBus15_Vel_tag c5_slBus15_Vel;

#endif                                 /* typedef_c5_slBus15_Vel */

/* Type Definitions */
#ifndef struct_c5_slBus15_Vel_tag
#define struct_c5_slBus15_Vel_tag

struct c5_slBus15_Vel_tag
{
  real_T xdot;
  real_T ydot;
  real_T zdot;
};

#endif                                 /* struct_c5_slBus15_Vel_tag */

#ifndef typedef_c5_slBus15_Vel
#define typedef_c5_slBus15_Vel

typedef struct c5_slBus15_Vel_tag c5_slBus15_Vel;

#endif                                 /* typedef_c5_slBus15_Vel */

#ifndef typedef_SFc5_car_model_FIXEDInstanceStruct
#define typedef_SFc5_car_model_FIXEDInstanceStruct

typedef struct {
  real_T c5_selected_sweep[1288];
  real_T c5_dt_ON;
  real_T c5_dt_OFF;
  real_T c5_tvs_t_sim;
  SimStruct *S;
  ChartInfoStruct chartInfo;
  int32_T c5_sfEvent;
  boolean_T c5_doneDoubleBufferReInit;
  uint8_T c5_is_active_c5_car_model_FIXED;
  uint8_T c5_JITStateAnimation[1];
  uint8_T c5_JITTransitionAnimation[1];
  emlrtLocationLoggingDataType c5_emlrtLocationLoggingDataTables[20];
  int32_T c5_IsDebuggerActive;
  int32_T c5_IsSequenceViewerPresent;
  int32_T c5_SequenceViewerOptimization;
  int32_T c5_IsHeatMapPresent;
  void *c5_RuntimeVar;
  emlrtLocationLoggingHistogramType c5_emlrtLocLogHistTables[20];
  boolean_T c5_emlrtLocLogSimulated;
  uint32_T c5_mlFcnLineNumber;
  void *c5_fcnDataPtrs[14];
  char_T *c5_dataNames[14];
  uint32_T c5_numFcnVars;
  uint32_T c5_ssIds[14];
  uint32_T c5_statuses[14];
  void *c5_outMexFcns[14];
  void *c5_inMexFcns[14];
  CovrtStateflowInstance *c5_covrtInstance;
  void *c5_fEmlrtCtx;
  real_T *c5_index;
  real_T *c5_b_index;
  c5_slBus15_Vel *c5_vel;
  real_T *c5_ON;
  real_T *c5_vel_err;
  real_T *c5_ref_steer;
  real_T *c5_b_ON;
  real_T *c5_counter;
  real_T *c5_b_counter;
} SFc5_car_model_FIXEDInstanceStruct;

#endif                                 /* typedef_SFc5_car_model_FIXEDInstanceStruct */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c5_car_model_FIXED_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c5_car_model_FIXED_get_check_sum(mxArray *plhs[]);
extern void c5_car_model_FIXED_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
