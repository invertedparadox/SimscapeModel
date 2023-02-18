/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SFS.h
 *
 * Code generated for Simulink model 'SFS'.
 *
 * Model version                  : 2.18
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Jan 20 00:17:03 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SFS_h_
#define RTW_HEADER_SFS_h_
#ifndef SFS_COMMON_INCLUDES_
#define SFS_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* SFS_COMMON_INCLUDES_ */

#include "SFS_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  insfilterAsync filter;
  real_T UnitDelay_DSTATE[28];         /* '<S1>/Unit Delay' */
  real_T Pdot[784];
  real_T procNoise[784];
  real_T dfdx[784];
  real_T b[784];
  real_T P_m[784];
  real_T X_c[784];
  real_T obj[784];
  real_T W[784];
  real_T P_k[784];
  real_T UnitDelay1_DSTATE;            /* '<S1>/Unit Delay1' */
} DW;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: initstate
   * Referenced by: '<S1>/Unit Delay'
   */
  real_T UnitDelay_InitialCondition[28];
} ConstP;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T vel[3];                       /* '<Root>/vel' */
  real_T pos[3];                       /* '<Root>/pos' */
  real_T acc[3];                       /* '<Root>/acc' */
  real_T ang_vel[3];                   /* '<Root>/ang_vel' */
  real_T mag[3];                       /* '<Root>/mag' */
  real_T mag_ang;                      /* '<Root>/mag_ang' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T posb[3];                      /* '<Root>/posb' */
  real_T angvel[9];                    /* '<Root>/angvel' */
  real_T velb[3];                      /* '<Root>/velb' */
} ExtY;

/* Code_Instrumentation_Declarations_Placeholder */

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
  DW *dwork;
};

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void SFS_initialize(RT_MODEL *const rtM);
extern void SFS_step(RT_MODEL *const rtM, ExtU *rtU, ExtY *rtY);

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
 * hilite_system('fusionS_22a/SFS')    - opens subsystem fusionS_22a/SFS
 * hilite_system('fusionS_22a/SFS/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'fusionS_22a'
 * '<S1>'   : 'fusionS_22a/SFS'
 * '<S2>'   : 'fusionS_22a/SFS/MATLAB Function'
 * '<S3>'   : 'fusionS_22a/SFS/Matrix Rotation'
 */
#endif                                 /* RTW_HEADER_SFS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
