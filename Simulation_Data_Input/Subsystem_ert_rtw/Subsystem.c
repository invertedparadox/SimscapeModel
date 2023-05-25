/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Subsystem.c
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

#include "Subsystem.h"
#include "rtwtypes.h"
#include <math.h>

/* Forward declaration for local functions */
static void quaternionBase_rotmat(real_T q_a, real_T q_b, real_T q_c, real_T q_d,
  real_T r[9]);

/*===========*
 * Constants *
 *===========*/
#define RT_PI                          3.14159265358979323846
#define RT_PIF                         3.1415927F
#define RT_LN_10                       2.30258509299404568402
#define RT_LN_10F                      2.3025851F
#define RT_LOG10E                      0.43429448190325182765
#define RT_LOG10EF                     0.43429449F
#define RT_E                           2.7182818284590452354
#define RT_EF                          2.7182817F

/*
 * UNUSED_PARAMETER(x)
 *   Used to specify that a function parameter (argument) is required but not
 *   accessed by the function body.
 */
#ifndef UNUSED_PARAMETER
#if defined(__LCC__)
#define UNUSED_PARAMETER(x)                                      /* do nothing */
#else

/*
 * This is the semi-ANSI standard way of indicating that an
 * unused function parameter is required.
 */
#define UNUSED_PARAMETER(x)            (void) (x)
#endif
#endif

/* Function for MATLAB Function: '<S1>/SNED to VNED' */
static void quaternionBase_rotmat(real_T q_a, real_T q_b, real_T q_c, real_T q_d,
  real_T r[9])
{
  real_T aasq;
  real_T ac2;
  real_T ad2;
  real_T bc2;
  real_T bd2;
  real_T cd2;
  real_T n;
  n = sqrt(((q_a * q_a + q_b * q_b) + q_c * q_c) + q_d * q_d);
  q_a /= n;
  q_b /= n;
  q_c /= n;
  q_d /= n;
  n = q_a * q_b * 2.0;
  ac2 = q_a * q_c * 2.0;
  ad2 = q_a * q_d * 2.0;
  bc2 = q_b * q_c * 2.0;
  bd2 = q_b * q_d * 2.0;
  cd2 = q_c * q_d * 2.0;
  aasq = q_a * q_a * 2.0 - 1.0;
  r[0] = q_b * q_b * 2.0 + aasq;
  r[3] = bc2 + ad2;
  r[6] = bd2 - ac2;
  r[1] = bc2 - ad2;
  r[4] = q_c * q_c * 2.0 + aasq;
  r[7] = cd2 + n;
  r[2] = bd2 + ac2;
  r[5] = cd2 - n;
  r[8] = q_d * q_d * 2.0 + aasq;
}

/* Model step function */
void Subsystem_step(RT_MODEL *const rtM, ExtU *rtU, ExtY *rtY)
{
  DW *rtDW = rtM->dwork;
  real_T IMUNED2VNED[9];
  real_T rtb_filtered_gyro[3];
  real_T IMUNED2VNED_tmp;
  real_T IMUNED2VNED_tmp_0;
  real_T ein_idx_1;
  int32_T i;

  /* MATLAB Function: '<S1>/SNED to VNED' incorporates:
   *  Sum: '<S1>/Sum'
   */
  ein_idx_1 = (rtP.phi - 180.0) * 0.017453292519943295 / 2.0;
  IMUNED2VNED_tmp = cos(ein_idx_1);
  IMUNED2VNED_tmp_0 = sin(ein_idx_1);
  quaternionBase_rotmat(IMUNED2VNED_tmp - 0.0 * IMUNED2VNED_tmp_0 * 0.0,
                        IMUNED2VNED_tmp * 0.0 + sin(ein_idx_1) * 0.0,
                        IMUNED2VNED_tmp_0 - cos(ein_idx_1) * 0.0 * 0.0, cos
                        (ein_idx_1) * 0.0 + 0.0 * sin(ein_idx_1), IMUNED2VNED);
  ein_idx_1 = (180.0 - rtP.phi) * 0.017453292519943295 / 2.0;
  for (i = 0; i < 3; i++) {
    IMUNED2VNED_tmp = IMUNED2VNED[i + 3];
    IMUNED2VNED_tmp_0 = IMUNED2VNED[i + 6];

    /* Outport: '<Root>/accel_VNED' */
    rtY->accel_VNED[i] = (IMUNED2VNED_tmp * rtU->acc[1] + IMUNED2VNED[i] *
                          rtU->acc[0]) + IMUNED2VNED_tmp_0 * rtU->acc[2];

    /* Sum: '<S1>/Sum' incorporates:
     *  Gain: '<S1>/Gain'
     *  Gain: '<S1>/Gain1'
     *  UnitDelay: '<S1>/Unit Delay'
     */
    IMUNED2VNED_tmp = ((IMUNED2VNED_tmp * rtU->gyro[1] + IMUNED2VNED[i] *
                        rtU->gyro[0]) + IMUNED2VNED_tmp_0 * rtU->gyro[2]) * 0.1
      + 0.9 * rtDW->UnitDelay_DSTATE[i];

    /* Outport: '<Root>/gyro_VNED' */
    rtY->gyro_VNED[i] = IMUNED2VNED_tmp;
    rtb_filtered_gyro[i] = IMUNED2VNED_tmp;
  }

  IMUNED2VNED_tmp = sin(ein_idx_1);
  ein_idx_1 = cos(ein_idx_1);
  quaternionBase_rotmat(6.123233995736766E-17 * ein_idx_1 - IMUNED2VNED_tmp *
                        0.0, 6.123233995736766E-17 * IMUNED2VNED_tmp * 0.0 +
                        ein_idx_1, 6.123233995736766E-17 * IMUNED2VNED_tmp -
                        ein_idx_1 * 0.0, 6.123233995736766E-17 * ein_idx_1 * 0.0
                        + IMUNED2VNED_tmp, IMUNED2VNED);
  for (i = 0; i < 3; i++) {
    /* Outport: '<Root>/mag_VNED' */
    rtY->mag_VNED[i] = (IMUNED2VNED[i + 3] * rtU->mag[1] + IMUNED2VNED[i] *
                        rtU->mag[0]) + IMUNED2VNED[i + 6] * rtU->mag[2];

    /* Update for UnitDelay: '<S1>/Unit Delay' incorporates:
     *  Sum: '<S1>/Sum'
     */
    rtDW->UnitDelay_DSTATE[i] = rtb_filtered_gyro[i];
  }

  /* End of MATLAB Function: '<S1>/SNED to VNED' */
}

/* Model initialize function */
void Subsystem_initialize(RT_MODEL *const rtM)
{
  /* (no initialization code required) */
  UNUSED_PARAMETER(rtM);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
