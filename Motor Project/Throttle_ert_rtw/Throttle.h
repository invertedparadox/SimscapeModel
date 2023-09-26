/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Throttle.h
 *
 * Code generated for Simulink model 'Throttle'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Sep 22 23:14:02 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Throttle_h_
#define RTW_HEADER_Throttle_h_
#ifndef Throttle_COMMON_INCLUDES_
#define Throttle_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Throttle_COMMON_INCLUDES_ */

#include "Throttle_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T r[2];                         /* '<Root>/r' */
  real_T V[2];                         /* '<Root>/V' */
  real_T w[2];                         /* '<Root>/w' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T k[2];                         /* '<Root>/k' */
} ExtY;

/* Parameters (default storage) */
struct P_ {
  real_T k_grid_max[2782];             /* Variable: k_grid_max
                                        * Referenced by: '<S1>/k_max'
                                        */
  real_T k_grid_min[2782];             /* Variable: k_grid_min
                                        * Referenced by: '<S1>/k_min'
                                        */
  real_T rpm_sweep_min[107];           /* Variable: rpm_sweep_min
                                        * Referenced by:
                                        *   '<S1>/k_max'
                                        *   '<S1>/k_min'
                                        */
  real_T voltage_sweep_min[26];        /* Variable: voltage_sweep_min
                                        * Referenced by:
                                        *   '<S1>/k_max'
                                        *   '<S1>/k_min'
                                        */
};

/* Code_Instrumentation_Declarations_Placeholder */

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P rtP;

/* Model entry point functions */
extern void Throttle_initialize(RT_MODEL *const rtM);
extern void Throttle_step(RT_MODEL *const rtM, ExtU *rtU, ExtY *rtY);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('Throttle_Map/Throttle Map')    - opens subsystem Throttle_Map/Throttle Map
 * hilite_system('Throttle_Map/Throttle Map/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Throttle_Map'
 * '<S1>'   : 'Throttle_Map/Throttle Map'
 */
#endif                                 /* RTW_HEADER_Throttle_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
