#ifndef __c3_car_model_FIXED_h__
#define __c3_car_model_FIXED_h__

/* Forward Declarations */
#ifndef typedef_c3_slBus15_Vel
#define typedef_c3_slBus15_Vel

typedef struct c3_slBus15_Vel_tag c3_slBus15_Vel;

#endif                                 /* typedef_c3_slBus15_Vel */

#ifndef typedef_c3_Disp
#define typedef_c3_Disp

typedef struct c3_Disp_tag c3_Disp;

#endif                                 /* typedef_c3_Disp */

/* Type Definitions */
#ifndef struct_c3_slBus15_Vel_tag
#define struct_c3_slBus15_Vel_tag

struct c3_slBus15_Vel_tag
{
  real_T xdot;
  real_T ydot;
  real_T zdot;
};

#endif                                 /* struct_c3_slBus15_Vel_tag */

#ifndef typedef_c3_slBus15_Vel
#define typedef_c3_slBus15_Vel

typedef struct c3_slBus15_Vel_tag c3_slBus15_Vel;

#endif                                 /* typedef_c3_slBus15_Vel */

#ifndef struct_c3_Disp_tag
#define struct_c3_Disp_tag

struct c3_Disp_tag
{
  real_T X;
  real_T Y;
  real_T Z;
};

#endif                                 /* struct_c3_Disp_tag */

#ifndef typedef_c3_Disp
#define typedef_c3_Disp

typedef struct c3_Disp_tag c3_Disp;

#endif                                 /* typedef_c3_Disp */

#ifndef typedef_SFc3_car_model_FIXEDInstanceStruct
#define typedef_SFc3_car_model_FIXEDInstanceStruct

typedef struct {
  real_T c3_deg2rad;
  real_T c3_selected_track[37971];
  real_T c3_dIndex;
  real_T c3_dx;
  real_T c3_forward_look_straight;
  real_T c3_forward_look_turn;
  real_T c3_q_thresh;
  real_T c3_indicies[27];
  real_T c3_selected_maxvm[63];
  real_T c3_axb;
  SimStruct *S;
  ChartInfoStruct chartInfo;
  int32_T c3_sfEvent;
  boolean_T c3_doneDoubleBufferReInit;
  uint8_T c3_is_active_c3_car_model_FIXED;
  uint8_T c3_JITStateAnimation[1];
  uint8_T c3_JITTransitionAnimation[1];
  emlrtLocationLoggingDataType c3_emlrtLocationLoggingDataTables[195];
  int32_T c3_IsDebuggerActive;
  int32_T c3_IsSequenceViewerPresent;
  int32_T c3_SequenceViewerOptimization;
  int32_T c3_IsHeatMapPresent;
  void *c3_RuntimeVar;
  emlrtLocationLoggingHistogramType c3_emlrtLocLogHistTables[195];
  boolean_T c3_emlrtLocLogSimulated;
  uint32_T c3_mlFcnLineNumber;
  void *c3_fcnDataPtrs[72];
  char_T *c3_dataNames[72];
  uint32_T c3_numFcnVars;
  uint32_T c3_ssIds[72];
  uint32_T c3_statuses[72];
  void *c3_outMexFcns[72];
  void *c3_inMexFcns[72];
  real_T c3_b_selected_track[37971];
  real_T c3_dv[37971];
  real_T c3_b_dv[37971];
  CovrtStateflowInstance *c3_covrtInstance;
  void *c3_fEmlrtCtx;
  real_T *c3_index_small;
  real_T *c3_index_all;
  real_T *c3_psi;
  c3_slBus15_Vel *c3_Vg;
  real_T *c3_yaw;
  c3_Disp *c3_pos;
  real_T (*c3_omega)[4];
  real_T *c3_b_index_small;
  real_T *c3_b_index_all;
  real_T *c3_v_error;
  real_T *c3_d_error;
  real_T *c3_psi_error;
  real_T *c3_v_cog;
  real_T *c3_r_ref;
  real_T *c3_r_error;
  real_T *c3_x_ref;
  real_T *c3_y_ref;
  real_T *c3_yaw_ref;
  real_T (*c3_b_omega)[4];
  real_T *c3_p_error;
  real_T *c3_Vnow;
  real_T *c3_ahead;
  real_T *c3_b_ahead;
  real_T *c3_di_now;
  real_T *c3_di_prev;
} SFc3_car_model_FIXEDInstanceStruct;

#endif                                 /* typedef_SFc3_car_model_FIXEDInstanceStruct */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_car_model_FIXED_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_car_model_FIXED_get_check_sum(mxArray *plhs[]);
extern void c3_car_model_FIXED_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
