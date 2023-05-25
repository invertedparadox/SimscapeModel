/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TVS.h
 *
 * Code generated for Simulink model 'TVS'.
 *
 * Model version                  : 1.142
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon Jan  2 13:45:38 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TVS_h_
#define RTW_HEADER_TVS_h_
#ifndef TVS_COMMON_INCLUDES_
#define TVS_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* TVS_COMMON_INCLUDES_ */

/* Model Code Variants */

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
  real_T UnitDelay_DSTATE[4];          /* '<S1>/Unit Delay' */
  real_T Minimum_Valdata[4];           /* '<S11>/Minimum' */
  real_T Minimum1_Valdata[4];          /* '<S11>/Minimum1' */
  real_T PrevY[4];                     /* '<S4>/Tx_rate_limit' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S5>/Discrete-Time Integrator' */
  real_T UnitDelay5_DSTATE;            /* '<S13>/Unit Delay5' */
  real_T UnitDelay1_DSTATE;            /* '<S13>/Unit Delay1' */
  uint32_T m_bpIndex[4];               /* '<S11>/1-D Lookup Table' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S5>/Discrete-Time Integrator' */
  boolean_T UnitDelay4_DSTATE;         /* '<S13>/Unit Delay4' */
  boolean_T UnitDelay_DSTATE_f;        /* '<S13>/Unit Delay' */
} DW;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: [1:16])
   * Referenced by:
   *   '<S11>/Constant3'
   *   '<S11>/Constant5'
   */
  real_T pooled4[16];

  /* Pooled Parameter (Expression: torque_sweep)
   * Referenced by:
   *   '<S11>/Constant7'
   *   '<S11>/Constant8'
   */
  real_T pooled5[16];

  /* Pooled Parameter (Expression: power_loss_grid)
   * Referenced by:
   *   '<S11>/Constant1'
   *   '<S11>/Constant4'
   */
  real_T pooled8[1712];

  /* Expression: gr
   * Referenced by: '<S10>/Gain1'
   */
  real_T Gain1_Gain[4];

  /* Expression: max_torque
   * Referenced by: '<S11>/1-D Lookup Table'
   */
  real_T uDLookupTable_tableData[68];

  /* Expression: max_rpm
   * Referenced by: '<S11>/1-D Lookup Table'
   */
  real_T uDLookupTable_bp01Data[68];

  /* Expression: max_yaw_field
   * Referenced by: '<S6>/1-D Lookup Table'
   */
  real_T uDLookupTable_tableData_n[10];
} ConstP;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T r_ref;                        /* '<Root>/<r_ref>' */
  real_T driver_input;                 /* '<Root>/<driver_input>' */
  real_T theta;                        /* '<Root>/<steering_angle>' */
  real_T omega[4];                     /* '<Root>/<omega>' */
  real_T pwr_lmt[2];                   /* '<Root>/<power_limits>' */
  real_T motor_V[4];                   /* '<Root>/<motor_voltage>' */
  real_T motor_I[4];                   /* '<Root>/<motor_current>' */
  real_T motor_T[4];                   /* '<Root>/<motor_temp>' */
  real_T battery_V;                    /* '<Root>/<battery_voltage>' */
  real_T FZ[4];                        /* '<Root>/<Fz>' */
  real_T yaw;                          /* '<Root>/<yaw>' */
  real_T vel[3];                       /* '<Root>/<vel>' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Control_Signal;               /* '<Root>/Control_Signal' */
  boolean_T windup;                    /* '<Root>/windup' */
  boolean_T reset;                     /* '<Root>/reset' */
  real_T ref_yaw;                      /* '<Root>/ref_yaw' */
  real_T obj_gain[4];                  /* '<Root>/obj_gain' */
  real_T ub[4];                        /* '<Root>/ub' */
  real_T lb[4];                        /* '<Root>/lb' */
  real_T b;                            /* '<Root>/b' */
  real_T beq;                          /* '<Root>/beq' */
  real_T omega_m_TV[4];                /* '<Root>/omega_m_TV' */
  real_T motor_I[4];                   /* '<Root>/motor_I' */
  real_T power_limits[2];              /* '<Root>/power_limits' */
  real_T motor_T[4];                   /* '<Root>/motor_T' */
  real_T motor_V[4];                   /* '<Root>/motor_V' */
  real_T Tx[4];                        /* '<Root>/Tx' */
  int32_T bigM_flag;                   /* '<Root>/bigM_flag' */
} ExtY;

/* Parameters (default storage) */
struct P_ {
  real_T I;                            /* Variable: I
                                        * Referenced by: '<S5>/I'
                                        */
  real_T Ku;                           /* Variable: Ku
                                        * Referenced by: '<S6>/Gain1'
                                        */
  real_T Kv;                           /* Variable: Kv
                                        * Referenced by: '<S6>/Gain2'
                                        */
  real_T P;                            /* Variable: P
                                        * Referenced by: '<S5>/P'
                                        */
  real_T deadband_angle;               /* Variable: deadband_angle
                                        * Referenced by: '<S7>/Dead Zone'
                                        */
};

/* Parameters (default storage) */
typedef struct P_ P;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P rtP;

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void TVS_initialize(void);
extern void TVS_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S14>/Data Type Duplicate' : Unused code path elimination
 * Block '<S14>/Data Type Propagation' : Unused code path elimination
 * Block '<S15>/Data Type Duplicate' : Unused code path elimination
 * Block '<S15>/Data Type Propagation' : Unused code path elimination
 * Block '<S16>/Data Type Duplicate' : Unused code path elimination
 * Block '<S16>/Data Type Propagation' : Unused code path elimination
 * Block '<S17>/Data Type Duplicate' : Unused code path elimination
 * Block '<S17>/Data Type Propagation' : Unused code path elimination
 * Block '<S6>/Constant' : Unused code path elimination
 * Block '<S6>/Divide' : Unused code path elimination
 * Block '<S6>/GreaterThan' : Unused code path elimination
 * Block '<S6>/Sim Enable' : Unused code path elimination
 */

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
 * hilite_system('car_model/Control Systems/TVS')    - opens subsystem car_model/Control Systems/TVS
 * hilite_system('car_model/Control Systems/TVS/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'car_model/Control Systems'
 * '<S1>'   : 'car_model/Control Systems/TVS'
 * '<S2>'   : 'car_model/Control Systems/TVS/Torque Vectoring Micro Controller'
 * '<S3>'   : 'car_model/Control Systems/TVS/Torque Vectoring Micro Controller/Constraint Generation'
 * '<S4>'   : 'car_model/Control Systems/TVS/Torque Vectoring Micro Controller/Optimization'
 * '<S5>'   : 'car_model/Control Systems/TVS/Torque Vectoring Micro Controller/PI Controller'
 * '<S6>'   : 'car_model/Control Systems/TVS/Torque Vectoring Micro Controller/Reference Model'
 * '<S7>'   : 'car_model/Control Systems/TVS/Torque Vectoring Micro Controller/Steering Model'
 * '<S8>'   : 'car_model/Control Systems/TVS/Torque Vectoring Micro Controller/Tire Model'
 * '<S9>'   : 'car_model/Control Systems/TVS/Torque Vectoring Micro Controller/Constraint Generation/Moment Arm'
 * '<S10>'  : 'car_model/Control Systems/TVS/Torque Vectoring Micro Controller/Constraint Generation/Power Constraint'
 * '<S11>'  : 'car_model/Control Systems/TVS/Torque Vectoring Micro Controller/Constraint Generation/Power Limit'
 * '<S12>'  : 'car_model/Control Systems/TVS/Torque Vectoring Micro Controller/Constraint Generation/Torque Boundary'
 * '<S13>'  : 'car_model/Control Systems/TVS/Torque Vectoring Micro Controller/Constraint Generation/Yaw Constraint'
 * '<S14>'  : 'car_model/Control Systems/TVS/Torque Vectoring Micro Controller/Constraint Generation/Power Limit/Saturation Dynamic'
 * '<S15>'  : 'car_model/Control Systems/TVS/Torque Vectoring Micro Controller/Constraint Generation/Yaw Constraint/Saturation Dynamic1'
 * '<S16>'  : 'car_model/Control Systems/TVS/Torque Vectoring Micro Controller/Constraint Generation/Yaw Constraint/Saturation Dynamic2'
 * '<S17>'  : 'car_model/Control Systems/TVS/Torque Vectoring Micro Controller/PI Controller/Saturation Dynamic'
 * '<S18>'  : 'car_model/Control Systems/TVS/Torque Vectoring Micro Controller/Steering Model/left_steering'
 * '<S19>'  : 'car_model/Control Systems/TVS/Torque Vectoring Micro Controller/Steering Model/right_steering'
 */
#endif                                 /* RTW_HEADER_TVS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
