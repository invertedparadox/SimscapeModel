/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Throttle.c
 *
 * Code generated for Simulink model 'Throttle'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Sep 22 19:17:23 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#include "Throttle.h"
#include "rtwtypes.h"

static uint32_T plook_evenc(real_T u, real_T bp0, real_T bpSpace, uint32_T
  maxIndex, real_T *fraction);
static real_T intrp2d_l(const uint32_T bpIndex[], const real_T frac[], const
  real_T table[], const uint32_T stride);

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

static uint32_T plook_evenc(real_T u, real_T bp0, real_T bpSpace, uint32_T
  maxIndex, real_T *fraction)
{
  uint32_T bpIndex;

  /* Prelookup - Index and Fraction
     Index Search method: 'even'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u <= bp0) {
    bpIndex = 0U;
    *fraction = 0.0;
  } else {
    real_T fbpIndex;
    real_T invSpc;
    invSpc = 1.0 / bpSpace;
    fbpIndex = (u - bp0) * invSpc;
    if (fbpIndex < maxIndex) {
      bpIndex = (uint32_T)fbpIndex;
      *fraction = (u - ((real_T)(uint32_T)fbpIndex * bpSpace + bp0)) * invSpc;
    } else {
      bpIndex = maxIndex - 1U;
      *fraction = 1.0;
    }
  }

  return bpIndex;
}

static real_T intrp2d_l(const uint32_T bpIndex[], const real_T frac[], const
  real_T table[], const uint32_T stride)
{
  real_T yL_0d0;
  real_T yL_0d1;
  uint32_T offset_1d;

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'wrapping'
   */
  offset_1d = bpIndex[1U] * stride + bpIndex[0U];
  yL_0d0 = table[offset_1d];
  yL_0d0 += (table[offset_1d + 1U] - yL_0d0) * frac[0U];
  offset_1d += stride;
  yL_0d1 = table[offset_1d];
  return (((table[offset_1d + 1U] - yL_0d1) * frac[0U] + yL_0d1) - yL_0d0) *
    frac[1U] + yL_0d0;
}

/* Model step function */
void Throttle_step(RT_MODEL *const rtM, ExtU *rtU, ExtY *rtY)
{
  real_T fractions[2];
  real_T fractions_0[2];
  real_T rtb_k_max_idx_0;
  real_T rtb_k_min_idx_0;
  real_T rtb_k_min_idx_1;
  uint32_T bpIndices[2];
  uint32_T bpIndices_0[2];

  /* Outputs for Atomic SubSystem: '<Root>/Throttle Map' */
  /* Lookup_n-D: '<S1>/k_max' */
  profileStart_Throttle_Map(1U); /* original_line:124 */bpIndices[0U] = plook_evenc(rtU->V[0], rtP.voltage_sweep_min[0],
    rtP.voltage_sweep_min[1] - rtP.voltage_sweep_min[0], 25U, &rtb_k_min_idx_1);profileEnd_Throttle_Map(1U); /* original_line:125 */
  fractions[0U] = rtb_k_min_idx_1;
  profileStart_Throttle_Map(2U); /* original_line:127 */bpIndices[1U] = plook_evenc(rtU->w[0], rtP.rpm_sweep_min[0],
    rtP.rpm_sweep_min[1] - rtP.rpm_sweep_min[0], 106U, &rtb_k_min_idx_1);profileEnd_Throttle_Map(2U); /* original_line:128 */
  fractions[1U] = rtb_k_min_idx_1;
  profileStart_Throttle_Map(3U); /* original_line:130 */rtb_k_max_idx_0 = intrp2d_l(bpIndices, fractions, rtP.k_grid_max, 26U);profileEnd_Throttle_Map(3U); /* original_line:130 */
  profileStart_Throttle_Map(4U); /* original_line:131 */bpIndices[0U] = plook_evenc(rtU->V[1], rtP.voltage_sweep_min[0],
    rtP.voltage_sweep_min[1] - rtP.voltage_sweep_min[0], 25U, &rtb_k_min_idx_1);profileEnd_Throttle_Map(4U); /* original_line:132 */
  fractions[0U] = rtb_k_min_idx_1;
  profileStart_Throttle_Map(5U); /* original_line:134 */bpIndices[1U] = plook_evenc(rtU->w[1], rtP.rpm_sweep_min[0],
    rtP.rpm_sweep_min[1] - rtP.rpm_sweep_min[0], 106U, &rtb_k_min_idx_1);profileEnd_Throttle_Map(5U); /* original_line:135 */
  fractions[1U] = rtb_k_min_idx_1;

  /* Lookup_n-D: '<S1>/k_min' */
  profileStart_Throttle_Map(6U); /* original_line:139 */bpIndices_0[0U] = plook_evenc(rtU->V[0], rtP.voltage_sweep_min[0],
    rtP.voltage_sweep_min[1] - rtP.voltage_sweep_min[0], 25U, &rtb_k_min_idx_1);profileEnd_Throttle_Map(6U); /* original_line:140 */
  fractions_0[0U] = rtb_k_min_idx_1;
  profileStart_Throttle_Map(7U); /* original_line:142 */bpIndices_0[1U] = plook_evenc(rtU->w[0], rtP.rpm_sweep_min[0],
    rtP.rpm_sweep_min[1] - rtP.rpm_sweep_min[0], 106U, &rtb_k_min_idx_1);profileEnd_Throttle_Map(7U); /* original_line:143 */
  fractions_0[1U] = rtb_k_min_idx_1;
  profileStart_Throttle_Map(8U); /* original_line:145 */rtb_k_min_idx_0 = intrp2d_l(bpIndices_0, fractions_0, rtP.k_grid_min, 26U);profileEnd_Throttle_Map(8U); /* original_line:145 */
  profileStart_Throttle_Map(9U); /* original_line:146 */bpIndices_0[0U] = plook_evenc(rtU->V[1], rtP.voltage_sweep_min[0],
    rtP.voltage_sweep_min[1] - rtP.voltage_sweep_min[0], 25U, &rtb_k_min_idx_1);profileEnd_Throttle_Map(9U); /* original_line:147 */
  fractions_0[0U] = rtb_k_min_idx_1;
  profileStart_Throttle_Map(10U); /* original_line:149 */bpIndices_0[1U] = plook_evenc(rtU->w[1], rtP.rpm_sweep_min[0],
    rtP.rpm_sweep_min[1] - rtP.rpm_sweep_min[0], 106U, &rtb_k_min_idx_1);profileEnd_Throttle_Map(10U); /* original_line:150 */
  fractions_0[1U] = rtb_k_min_idx_1;
  profileStart_Throttle_Map(11U); /* original_line:152 */rtb_k_min_idx_1 = intrp2d_l(bpIndices_0, fractions_0, rtP.k_grid_min, 26U);profileEnd_Throttle_Map(11U); /* original_line:152 */

  /* Outport: '<Root>/k' incorporates:
   *  Lookup_n-D: '<S1>/k_max'
   *  Product: '<S1>/Product'
   *  Sum: '<S1>/Sum'
   *  Sum: '<S1>/Sum1'
   */
  rtY->k[0] = (rtb_k_max_idx_0 - rtb_k_min_idx_0) * rtU->r[0] + rtb_k_min_idx_0;
  profileStart_Throttle_Map(12U); /* original_line:161 */rtY->k[1] = (intrp2d_l(bpIndices, fractions, rtP.k_grid_max, 26U) -
               rtb_k_min_idx_1) * rtU->r[1] + rtb_k_min_idx_1;profileEnd_Throttle_Map(12U); /* original_line:162 */

  /* End of Outputs for SubSystem: '<Root>/Throttle Map' */
  UNUSED_PARAMETER(rtM);
}

/* Model initialize function */
void Throttle_initialize(RT_MODEL *const rtM)
{
  /* (no initialization code required) */
  UNUSED_PARAMETER(rtM);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
