/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Subsystem.h
 *
 * Code generated for Simulink model 'Subsystem'.
 *
 * Model version                  : 2.444
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Apr 20 13:52:16 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Subsystem_h_
#define RTW_HEADER_Subsystem_h_
#ifndef Subsystem_COMMON_INCLUDES_
#define Subsystem_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Subsystem_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE[3];          /* '<S1>/Unit Delay' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T acc[3];                       /* '<Root>/accel' */
  real_T gyro[3];                      /* '<Root>/gyro' */
  real_T mag[3];                       /* '<Root>/mag' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T accel_VNED[3];                /* '<Root>/accel_VNED' */
  real_T gyro_VNED[3];                 /* '<Root>/gyro_VNED' */
  real_T mag_VNED[3];                  /* '<Root>/mag_VNED' */
} ExtY;

/* Parameters (default storage) */
struct P_ {
  real_T phi;                          /* Variable: phi
                                        * Referenced by: '<S1>/SNED to VNED'
                                        */
};

/* Parameters (default storage) */
typedef struct P_ P;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
  DW *dwork;
};

/* Block parameters (default storage) */
extern P rtP;

/* Model entry point functions */
extern void Subsystem_initialize(RT_MODEL *const rtM);
extern void Subsystem_step(RT_MODEL *const rtM, ExtU *rtU, ExtY *rtY);

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
 * hilite_system('car_model_temp/Control Systems/Subsystem')    - opens subsystem car_model_temp/Control Systems/Subsystem
 * hilite_system('car_model_temp/Control Systems/Subsystem/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'car_model_temp/Control Systems'
 * '<S1>'   : 'car_model_temp/Control Systems/Subsystem'
 * '<S2>'   : 'car_model_temp/Control Systems/Subsystem/SNED to VNED'
 */
#endif                                 /* RTW_HEADER_Subsystem_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
