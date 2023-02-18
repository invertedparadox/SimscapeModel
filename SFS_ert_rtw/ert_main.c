/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'SFS'.
 *
 * Model version                  : 2.107
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sat Feb 18 10:30:45 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include <stddef.h>
#include <stdio.h>            /* This example main program uses printf/fflush */
#include "SFS.h"                       /* Model header file */

static RT_MODEL rtM_;
static RT_MODEL *const rtMPtr = &rtM_; /* Real-time model */
static DW rtDW;                        /* Observable states */

/* '<Root>/vel' */
static real_T rtU_vel[3];

/* '<Root>/pos' */
static real_T rtU_pos[3];

/* '<Root>/acc' */
static real_T rtU_acc[3];

/* '<Root>/mag' */
static real_T rtU_mag[3];

/* '<Root>/gyro' */
static real_T rtU_gyro[3];

/* '<Root>/GS' */
static real_T rtU_GS;

/* '<Root>/Course' */
static real_T rtU_Course;

/* '<Root>/battery_V' */
static real_T rtU_battery_V;

/* '<Root>/battery_I' */
static real_T rtU_battery_I;

/* '<Root>/motor_V' */
static real_T rtU_motor_V[4];

/* '<Root>/motor_I' */
static real_T rtU_motor_I[4];

/* '<Root>/pwr_lmt' */
static real_T rtU_pwr_lmt[2];

/* '<Root>/motor_T' */
static real_T rtU_motor_T[4];

/* '<Root>/motor_FT' */
static real_T rtU_motor_FT[2];

/* '<Root>/batt_T' */
static real_T rtU_batt_T;

/* '<Root>/batt_FT' */
static real_T rtU_batt_FT;

/* '<Root>/omega' */
static real_T rtU_omega[4];

/* '<Root>/theta' */
static real_T rtU_theta;

/* '<Root>/shock_L' */
static real_T rtU_shock_L[4];

/* '<Root>/FZ' */
static real_T rtU_FZ[4];

/* '<Root>/angvel_VNED' */
static real_T rtY_angvel_VNED[3];

/* '<Root>/ang_NED' */
static real_T rtY_ang_NED[4];

/* '<Root>/pos_VNED' */
static real_T rtY_pos_VNED[3];

/* '<Root>/vel_VNED' */
static real_T rtY_vel_VNED[3];

/* '<Root>/acc_VNED' */
static real_T rtY_acc_VNED[3];

/* '<Root>/mag_VNED' */
static real_T rtY_mag_VNED[3];

/* '<Root>/acc_bias_VNED' */
static real_T rtY_acc_bias_VNED[3];

/* '<Root>/gyro_bias_VNED' */
static real_T rtY_gyro_bias_VNED[3];

/* '<Root>/mag_bias_VNED' */
static real_T rtY_mag_bias_VNED[3];

/*
 * Associating rt_OneStep with a real-time clock or interrupt service routine
 * is what makes the generated code "real-time".  The function rt_OneStep is
 * always associated with the base rate of the model.  Subrates are managed
 * by the base rate from inside the generated code.  Enabling/disabling
 * interrupts and floating point context switches are target specific.  This
 * example code indicates where these should take place relative to executing
 * the generated code step function.  Overrun behavior should be tailored to
 * your application needs.  This example simply sets an error status in the
 * real-time model and returns from rt_OneStep.
 */
void rt_OneStep(RT_MODEL *const rtM);
void rt_OneStep(RT_MODEL *const rtM)
{
  static boolean_T OverrunFlag = false;

  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag) {
    rtmSetErrorStatus(rtM, "Overrun");
    return;
  }

  OverrunFlag = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */

  /* Step the model */
  SFS_step(rtM, rtU_vel, rtU_pos, rtU_acc, rtU_mag, rtU_gyro, rtY_angvel_VNED,
           rtY_ang_NED, rtY_pos_VNED, rtY_vel_VNED, rtY_acc_VNED, rtY_mag_VNED,
           rtY_acc_bias_VNED, rtY_gyro_bias_VNED, rtY_mag_bias_VNED);

  /* Get model outputs here */

  /* Indicate task complete */
  OverrunFlag = false;

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
}

/*
 * The example main function illustrates what is required by your
 * application code to initialize, execute, and terminate the generated code.
 * Attaching rt_OneStep to a real-time clock is target specific. This example
 * illustrates how you do this relative to initializing the model.
 */
int_T main(int_T argc, const char *argv[])
{
  RT_MODEL *const rtM = rtMPtr;

  /* Unused arguments */
  (void)(argc);
  (void)(argv);

  /* Pack model data into RTM */
  rtM->dwork = &rtDW;

  /* Initialize model */
  SFS_initialize(rtM);

  /* Attach rt_OneStep to a timer or interrupt service routine with
   * period 0.005 seconds (base rate of the model) here.
   * The call syntax for rt_OneStep is
   *
   *  rt_OneStep(rtM);
   */
  printf("Warning: The simulation will run forever. "
         "Generated ERT main won't simulate model step behavior. "
         "To change this behavior select the 'MAT-file logging' option.\n");
  fflush((NULL));
  while (rtmGetErrorStatus(rtM) == (NULL)) {
    /*  Perform application tasks here */
  }

  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
