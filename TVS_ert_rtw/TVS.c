/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TVS.c
 *
 * Code generated for Simulink model 'TVS'.
 *
 * Model version                  : 2.417
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Mar 31 15:56:05 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "TVS.h"
#include "rtwtypes.h"
#include <math.h>
#include <stddef.h>
#define period                         (0.015)
#define NumBitsPerChar                 8U

static real_T look1_binlc(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
static real_T look2_binlc(real_T u0, real_T u1, const real_T bp0[], const real_T
  bp1[], const real_T table[], const uint32_T maxIndex[], uint32_T stride);
static uint32_T plook_evenca(real_T u, real_T bp0, real_T bpSpace, uint32_T
  maxIndex, real_T *fraction);
static real_T intrp1d_la(uint32_T bpIndex, real_T frac, const real_T table[],
  uint32_T maxIndex);
static uint32_T plook_evenc(real_T u, real_T bp0, real_T bpSpace, uint32_T
  maxIndex, real_T *fraction);
static real_T intrp1d_l(uint32_T bpIndex, real_T frac, const real_T table[]);
static void rate_scheduler(RT_MODEL *const rtM);
static real_T rtGetNaN(void);
static real32_T rtGetNaNF(void);

#define NOT_USING_NONFINITE_LITERALS   1

extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
static void rt_InitInfAndNaN(size_t realSize);
static boolean_T rtIsInf(real_T value);
static boolean_T rtIsInfF(real32_T value);
static boolean_T rtIsNaN(real_T value);
static boolean_T rtIsNaNF(real32_T value);
typedef struct {
  struct {
    uint32_T wordH;
    uint32_T wordL;
  } words;
} BigEndianIEEEDouble;

typedef struct {
  struct {
    uint32_T wordL;
    uint32_T wordH;
  } words;
} LittleEndianIEEEDouble;

typedef struct {
  union {
    real32_T wordLreal;
    uint32_T wordLuint;
  } wordL;
} IEEESingle;

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;
real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;
static real_T rtGetInf(void);
static real32_T rtGetInfF(void);
static real_T rtGetMinusInf(void);
static real32_T rtGetMinusInfF(void);

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

/*
 * Initialize rtNaN needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetNaN(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T nan = 0.0;
  if (bitsPerReal == 32U) {
    nan = rtGetNaNF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF80000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    nan = tmpVal.fltVal;
  }

  return nan;
}

/*
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetNaNF(void)
{
  IEEESingle nanF = { { 0.0F } };

  nanF.wordL.wordLuint = 0xFFC00000U;
  return nanF.wordL.wordLreal;
}

/*
 * Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 * generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
static void rt_InitInfAndNaN(size_t realSize)
{
  (void) (realSize);
  rtNaN = rtGetNaN();
  rtNaNF = rtGetNaNF();
  rtInf = rtGetInf();
  rtInfF = rtGetInfF();
  rtMinusInf = rtGetMinusInf();
  rtMinusInfF = rtGetMinusInfF();
}

/* Test if value is infinite */
static boolean_T rtIsInf(real_T value)
{
  return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Test if single-precision value is infinite */
static boolean_T rtIsInfF(real32_T value)
{
  return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Test if value is not a number */
static boolean_T rtIsNaN(real_T value)
{
  boolean_T result = (boolean_T) 0;
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  if (bitsPerReal == 32U) {
    result = rtIsNaNF((real32_T)value);
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.fltVal = value;
    result = (boolean_T)((tmpVal.bitVal.words.wordH & 0x7FF00000) == 0x7FF00000 &&
                         ( (tmpVal.bitVal.words.wordH & 0x000FFFFF) != 0 ||
                          (tmpVal.bitVal.words.wordL != 0) ));
  }

  return result;
}

/* Test if single-precision value is not a number */
static boolean_T rtIsNaNF(real32_T value)
{
  IEEESingle tmp;
  tmp.wordL.wordLreal = value;
  return (boolean_T)( (tmp.wordL.wordLuint & 0x7F800000) == 0x7F800000 &&
                     (tmp.wordL.wordLuint & 0x007FFFFF) != 0 );
}

/*
 * Initialize rtInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T inf = 0.0;
  if (bitsPerReal == 32U) {
    inf = rtGetInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0x7FF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    inf = tmpVal.fltVal;
  }

  return inf;
}

/*
 * Initialize rtInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetInfF(void)
{
  IEEESingle infF;
  infF.wordL.wordLuint = 0x7F800000U;
  return infF.wordL.wordLreal;
}

/*
 * Initialize rtMinusInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetMinusInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T minf = 0.0;
  if (bitsPerReal == 32U) {
    minf = rtGetMinusInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    minf = tmpVal.fltVal;
  }

  return minf;
}

/*
 * Initialize rtMinusInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetMinusInfF(void)
{
  IEEESingle minfF;
  minfF.wordL.wordLuint = 0xFF800000U;
  return minfF.wordL.wordLreal;
}

static real_T look1_binlc(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T iLeft;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u0 < bp0[maxIndex]) {
    uint32_T bpIdx;
    uint32_T iRght;

    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = 1.0;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

static real_T look2_binlc(real_T u0, real_T u1, const real_T bp0[], const real_T
  bp1[], const real_T table[], const uint32_T maxIndex[], uint32_T stride)
{
  real_T fractions[2];
  real_T frac;
  real_T yL_0d0;
  real_T yL_0d1;
  uint32_T bpIndices[2];
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 2-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u0 < bp0[maxIndex[0U]]) {
    /* Binary Search */
    bpIdx = maxIndex[0U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[0U];
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex[0U] - 1U;
    frac = 1.0;
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u1 <= bp1[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Binary Search */
    bpIdx = maxIndex[1U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[1U];
    while (iRght - iLeft > 1U) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u1 - bp1[iLeft]) / (bp1[iLeft + 1U] - bp1[iLeft]);
  } else {
    iLeft = maxIndex[1U] - 1U;
    frac = 1.0;
  }

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'wrapping'
   */
  bpIdx = iLeft * stride + bpIndices[0U];
  yL_0d0 = table[bpIdx];
  yL_0d0 += (table[bpIdx + 1U] - yL_0d0) * fractions[0U];
  bpIdx += stride;
  yL_0d1 = table[bpIdx];
  return (((table[bpIdx + 1U] - yL_0d1) * fractions[0U] + yL_0d1) - yL_0d0) *
    frac + yL_0d0;
}

static uint32_T plook_evenca(real_T u, real_T bp0, real_T bpSpace, uint32_T
  maxIndex, real_T *fraction)
{
  uint32_T bpIndex;

  /* Prelookup - Index and Fraction
     Index Search method: 'even'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
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
      bpIndex = maxIndex;
      *fraction = 0.0;
    }
  }

  return bpIndex;
}

static real_T intrp1d_la(uint32_T bpIndex, real_T frac, const real_T table[],
  uint32_T maxIndex)
{
  real_T y;

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Overflow mode: 'wrapping'
   */
  if (bpIndex == maxIndex) {
    y = table[bpIndex];
  } else {
    real_T yL_0d0;
    yL_0d0 = table[bpIndex];
    y = (table[bpIndex + 1U] - yL_0d0) * frac + yL_0d0;
  }

  return y;
}

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

static real_T intrp1d_l(uint32_T bpIndex, real_T frac, const real_T table[])
{
  real_T yL_0d0;

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'wrapping'
   */
  yL_0d0 = table[bpIndex];
  return (table[bpIndex + 1U] - yL_0d0) * frac + yL_0d0;
}

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(RT_MODEL *const rtM)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (rtM->Timing.TaskCounters.TID[1])++;
  if ((rtM->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.01s, 0.0s] */
    rtM->Timing.TaskCounters.TID[1] = 0;
  }

  (rtM->Timing.TaskCounters.TID[2])++;
  if ((rtM->Timing.TaskCounters.TID[2]) > 2) {/* Sample time: [0.015s, 0.0s] */
    rtM->Timing.TaskCounters.TID[2] = 0;
  }
}

/* Model step function */
void TVS_step(RT_MODEL *const rtM, ExtU *rtU, ExtY *rtY)
{
  DW *rtDW = rtM->dwork;
  real_T rtb_Add_idx_0;
  real_T rtb_Add_idx_1;
  real_T rtb_FRMomentArm;
  real_T rtb_Gain4_idx_2;
  real_T rtb_RAWTorqueCMDNm;
  real_T rtb_TRR;
  if (rtM->Timing.TaskCounters.TID[2] == 0) {
    real_T rtb_Add_idx_2;
    real_T rtb_Add_idx_3;
    real_T rtb_Gain4_idx_0;
    real_T rtb_Gain4_idx_1;
    real_T rtb_MaxAllowedPackCurrentA;
    real_T rtb_MaxIndividualMotorTorqueN_0;
    real_T rtb_MaxIndividualMotorTorqueN_1;
    real_T rtb_MaxIndividualMotorTorqueN_c;
    real_T rtb_MaxIndividualMotorTorqueNm_;
    real_T rtb_MinIndividualMotorTorqueN_0;
    real_T rtb_MinIndividualMotorTorqueN_1;
    real_T rtb_MinIndividualMotorTorqueN_2;
    real_T rtb_MinIndividualMotorTorqueNm_;
    real_T rtb_Saturation3_idx_1;
    real_T rtb_Saturation3_idx_3;
    real_T rtb_Sum4;
    real_T rtb_Tx_idx_0;
    real_T rtb_Tx_idx_1;
    real_T rtb_Tx_idx_2;
    real_T rtb_Tx_m;
    real_T rtb_b_b;
    real_T rtb_beq_b;
    real_T rtb_current_limits_idx_0;
    real_T rtb_current_limits_idx_1;
    real_T rtb_omega_m_idx_0;
    real_T rtb_omega_m_idx_1;
    real_T rtb_omega_m_idx_2;
    real_T rtb_omega_m_idx_3;
    real_T rtb_ref_ang_acc;
    real_T rtb_ub_b_idx_0;
    real_T rtb_ub_b_idx_1;
    real_T rtb_ub_b_idx_2;
    uint32_T bpIdx;
    uint32_T bpIdx_0;

    /* Outputs for Atomic SubSystem: '<Root>/TVS' */
    /* RateLimiter: '<S2>/Tx_rate_limit' */
    rtb_Saturation3_idx_1 = rtP.Torque_Up_Rate_Limit * period;
    rtb_Sum4 = -rtP.Torque_Down_Rate_Limit * period;

    /* Gain: '<S1>/Gain1' incorporates:
     *  Inport: '<Root>/omega'
     */
    rtb_omega_m_idx_0 = 8.747863247863247 * rtU->omega[0];

    /* Gain: '<S2>/Tx_equal_gain' incorporates:
     *  Gain: '<S3>/Gain8'
     */
    rtb_MaxIndividualMotorTorqueN_c = rtP.ABS_MAX_TORQUE[0] * rtP.MOTOR_ENABLE[0];

    /* Bias: '<S2>/Tx_reverse_offset' incorporates:
     *  Bias: '<S2>/Tx_equal_offset'
     *  Gain: '<S2>/Tx_equal_gain'
     */
    rtb_current_limits_idx_0 = (rtb_MaxIndividualMotorTorqueN_c *
      rtU->driver_input + rtP.ABS_MAX_TORQUE[0]) - rtP.ABS_MAX_TORQUE[0];

    /* DeadZone: '<S2>/Tx_deadband' */
    if (rtb_current_limits_idx_0 > 0.1) {
      rtb_current_limits_idx_0 -= 0.1;
    } else if (rtb_current_limits_idx_0 >= -0.1) {
      rtb_current_limits_idx_0 = 0.0;
    } else {
      rtb_current_limits_idx_0 -= -0.1;
    }

    /* RateLimiter: '<S2>/Tx_rate_limit' */
    rtb_Tx_m = rtb_current_limits_idx_0 - rtDW->PrevY[0];
    if (rtb_Tx_m > rtb_Saturation3_idx_1) {
      rtb_Tx_m = rtDW->PrevY[0] + rtb_Saturation3_idx_1;
    } else if (rtb_Tx_m < rtb_Sum4) {
      rtb_Tx_m = rtDW->PrevY[0] + rtb_Sum4;
    } else {
      rtb_Tx_m = rtb_current_limits_idx_0;
    }

    rtDW->PrevY[0] = rtb_Tx_m;

    /* Saturate: '<S3>/Max Torque' incorporates:
     *  Gain: '<S3>/Gain8'
     */
    if (rtb_MaxIndividualMotorTorqueN_c > rtP.ABS_MAX_TORQUE[0]) {
      rtb_MaxIndividualMotorTorqueN_c = rtP.ABS_MAX_TORQUE[0];
    } else if (rtb_MaxIndividualMotorTorqueN_c < 0.01) {
      rtb_MaxIndividualMotorTorqueN_c = 0.01;
    }

    /* End of Outputs for SubSystem: '<Root>/TVS' */
    rtb_MaxIndividualMotorTorqueNm_ = rtb_MaxIndividualMotorTorqueN_c;

    /* Outputs for Atomic SubSystem: '<Root>/TVS' */
    /* Bias: '<S2>/Tx_reverse_offset' incorporates:
     *  Bias: '<S2>/ub_offset'
     */
    rtb_ub_b_idx_0 = rtb_MaxIndividualMotorTorqueN_c + rtP.ABS_MAX_TORQUE[0];

    /* RateLimiter: '<S2>/Tx_rate_limit' */
    rtb_Tx_idx_0 = rtb_Tx_m;

    /* Gain: '<S1>/Gain1' incorporates:
     *  Inport: '<Root>/omega'
     */
    rtb_omega_m_idx_1 = 8.747863247863247 * rtU->omega[1];

    /* Gain: '<S2>/Tx_equal_gain' incorporates:
     *  Gain: '<S3>/Gain8'
     */
    rtb_MaxIndividualMotorTorqueN_c = rtP.ABS_MAX_TORQUE[1] * rtP.MOTOR_ENABLE[1];

    /* Bias: '<S2>/Tx_reverse_offset' incorporates:
     *  Bias: '<S2>/Tx_equal_offset'
     *  Gain: '<S2>/Tx_equal_gain'
     */
    rtb_current_limits_idx_0 = (rtb_MaxIndividualMotorTorqueN_c *
      rtU->driver_input + rtP.ABS_MAX_TORQUE[1]) - rtP.ABS_MAX_TORQUE[1];

    /* DeadZone: '<S2>/Tx_deadband' */
    if (rtb_current_limits_idx_0 > 0.1) {
      rtb_current_limits_idx_0 -= 0.1;
    } else if (rtb_current_limits_idx_0 >= -0.1) {
      rtb_current_limits_idx_0 = 0.0;
    } else {
      rtb_current_limits_idx_0 -= -0.1;
    }

    /* RateLimiter: '<S2>/Tx_rate_limit' */
    rtb_Tx_m = rtb_current_limits_idx_0 - rtDW->PrevY[1];
    if (rtb_Tx_m > rtb_Saturation3_idx_1) {
      rtb_Tx_m = rtDW->PrevY[1] + rtb_Saturation3_idx_1;
    } else if (rtb_Tx_m < rtb_Sum4) {
      rtb_Tx_m = rtDW->PrevY[1] + rtb_Sum4;
    } else {
      rtb_Tx_m = rtb_current_limits_idx_0;
    }

    rtDW->PrevY[1] = rtb_Tx_m;

    /* Saturate: '<S3>/Max Torque' incorporates:
     *  Gain: '<S3>/Gain8'
     */
    if (rtb_MaxIndividualMotorTorqueN_c > rtP.ABS_MAX_TORQUE[1]) {
      rtb_MaxIndividualMotorTorqueN_c = rtP.ABS_MAX_TORQUE[1];
    } else if (rtb_MaxIndividualMotorTorqueN_c < 0.01) {
      rtb_MaxIndividualMotorTorqueN_c = 0.01;
    }

    /* End of Outputs for SubSystem: '<Root>/TVS' */
    rtb_MaxIndividualMotorTorqueN_0 = rtb_MaxIndividualMotorTorqueN_c;

    /* Outputs for Atomic SubSystem: '<Root>/TVS' */
    /* Bias: '<S2>/Tx_reverse_offset' incorporates:
     *  Bias: '<S2>/ub_offset'
     */
    rtb_ub_b_idx_1 = rtb_MaxIndividualMotorTorqueN_c + rtP.ABS_MAX_TORQUE[1];

    /* RateLimiter: '<S2>/Tx_rate_limit' */
    rtb_Tx_idx_1 = rtb_Tx_m;

    /* Gain: '<S1>/Gain1' incorporates:
     *  Inport: '<Root>/omega'
     */
    rtb_omega_m_idx_2 = 8.747863247863247 * rtU->omega[2];

    /* Gain: '<S2>/Tx_equal_gain' incorporates:
     *  Gain: '<S3>/Gain8'
     */
    rtb_MaxIndividualMotorTorqueN_c = rtP.ABS_MAX_TORQUE[2] * rtP.MOTOR_ENABLE[2];

    /* Bias: '<S2>/Tx_reverse_offset' incorporates:
     *  Bias: '<S2>/Tx_equal_offset'
     *  Gain: '<S2>/Tx_equal_gain'
     */
    rtb_current_limits_idx_0 = (rtb_MaxIndividualMotorTorqueN_c *
      rtU->driver_input + rtP.ABS_MAX_TORQUE[2]) - rtP.ABS_MAX_TORQUE[2];

    /* DeadZone: '<S2>/Tx_deadband' */
    if (rtb_current_limits_idx_0 > 0.1) {
      rtb_current_limits_idx_0 -= 0.1;
    } else if (rtb_current_limits_idx_0 >= -0.1) {
      rtb_current_limits_idx_0 = 0.0;
    } else {
      rtb_current_limits_idx_0 -= -0.1;
    }

    /* RateLimiter: '<S2>/Tx_rate_limit' */
    rtb_Tx_m = rtb_current_limits_idx_0 - rtDW->PrevY[2];
    if (rtb_Tx_m > rtb_Saturation3_idx_1) {
      rtb_Tx_m = rtDW->PrevY[2] + rtb_Saturation3_idx_1;
    } else if (rtb_Tx_m < rtb_Sum4) {
      rtb_Tx_m = rtDW->PrevY[2] + rtb_Sum4;
    } else {
      rtb_Tx_m = rtb_current_limits_idx_0;
    }

    rtDW->PrevY[2] = rtb_Tx_m;

    /* Saturate: '<S3>/Max Torque' incorporates:
     *  Gain: '<S3>/Gain8'
     */
    if (rtb_MaxIndividualMotorTorqueN_c > rtP.ABS_MAX_TORQUE[2]) {
      rtb_MaxIndividualMotorTorqueN_c = rtP.ABS_MAX_TORQUE[2];
    } else if (rtb_MaxIndividualMotorTorqueN_c < 0.01) {
      rtb_MaxIndividualMotorTorqueN_c = 0.01;
    }

    /* End of Outputs for SubSystem: '<Root>/TVS' */
    rtb_MaxIndividualMotorTorqueN_1 = rtb_MaxIndividualMotorTorqueN_c;

    /* Outputs for Atomic SubSystem: '<Root>/TVS' */
    /* Bias: '<S2>/Tx_reverse_offset' incorporates:
     *  Bias: '<S2>/ub_offset'
     */
    rtb_ub_b_idx_2 = rtb_MaxIndividualMotorTorqueN_c + rtP.ABS_MAX_TORQUE[2];

    /* RateLimiter: '<S2>/Tx_rate_limit' */
    rtb_Tx_idx_2 = rtb_Tx_m;

    /* Gain: '<S1>/Gain1' incorporates:
     *  Inport: '<Root>/omega'
     */
    rtb_omega_m_idx_3 = 8.747863247863247 * rtU->omega[3];

    /* Gain: '<S2>/Tx_equal_gain' incorporates:
     *  Gain: '<S3>/Gain8'
     */
    rtb_MaxIndividualMotorTorqueN_c = rtP.ABS_MAX_TORQUE[3] * rtP.MOTOR_ENABLE[3];

    /* Bias: '<S2>/Tx_reverse_offset' incorporates:
     *  Bias: '<S2>/Tx_equal_offset'
     *  Gain: '<S2>/Tx_equal_gain'
     */
    rtb_current_limits_idx_0 = (rtb_MaxIndividualMotorTorqueN_c *
      rtU->driver_input + rtP.ABS_MAX_TORQUE[3]) - rtP.ABS_MAX_TORQUE[3];

    /* DeadZone: '<S2>/Tx_deadband' */
    if (rtb_current_limits_idx_0 > 0.1) {
      rtb_current_limits_idx_0 -= 0.1;
    } else if (rtb_current_limits_idx_0 >= -0.1) {
      rtb_current_limits_idx_0 = 0.0;
    } else {
      rtb_current_limits_idx_0 -= -0.1;
    }

    /* RateLimiter: '<S2>/Tx_rate_limit' */
    rtb_Tx_m = rtb_current_limits_idx_0 - rtDW->PrevY[3];
    if (rtb_Tx_m > rtb_Saturation3_idx_1) {
      rtb_Tx_m = rtDW->PrevY[3] + rtb_Saturation3_idx_1;
    } else if (rtb_Tx_m < rtb_Sum4) {
      rtb_Tx_m = rtDW->PrevY[3] + rtb_Sum4;
    } else {
      rtb_Tx_m = rtb_current_limits_idx_0;
    }

    rtDW->PrevY[3] = rtb_Tx_m;

    /* Saturate: '<S3>/Max Torque' incorporates:
     *  Gain: '<S3>/Gain8'
     */
    if (rtb_MaxIndividualMotorTorqueN_c > rtP.ABS_MAX_TORQUE[3]) {
      rtb_MaxIndividualMotorTorqueN_c = rtP.ABS_MAX_TORQUE[3];
    } else if (rtb_MaxIndividualMotorTorqueN_c < 0.01) {
      rtb_MaxIndividualMotorTorqueN_c = 0.01;
    }

    /* Sum: '<S5>/Sum4' incorporates:
     *  Constant: '<S5>/Constant2'
     */
    rtb_Sum4 = ((rtP.MOTOR_ENABLE[0] + rtP.MOTOR_ENABLE[1]) + rtP.MOTOR_ENABLE[2])
      + rtP.MOTOR_ENABLE[3];

    /* SignalConversion generated from: '<S1>/current_limits' */
    rtb_current_limits_idx_0 = rtU->pwr_lmt[0];
    rtb_current_limits_idx_1 = rtU->pwr_lmt[1];

    /* Lookup_n-D: '<S3>/Temperature to Motor Current Limit Map' incorporates:
     *  MinMax: '<S3>/Max'
     */
    bpIdx = plook_evenca(fmax(fmax(fmax(rtU->motor_T[0], rtU->motor_T[1]),
      rtU->motor_T[2]), rtU->motor_T[3]), 75.0, 2.0, 10U, &rtb_RAWTorqueCMDNm);

    /* Lookup_n-D: '<S3>/Temperature to Motor Controller Current Limit Map' incorporates:
     *  MinMax: '<S3>/Max1'
     */
    bpIdx_0 = plook_evenca(fmax(fmax(fmax(rtU->mc_T[0], rtU->mc_T[1]), rtU->
      mc_T[2]), rtU->mc_T[3]), 25.0, 25.0, 2U, &rtb_FRMomentArm);

    /* MinMax: '<S3>/Minimum' incorporates:
     *  Lookup_n-D: '<S3>/Temperature to Motor Controller Current Limit Map'
     *  Lookup_n-D: '<S3>/Temperature to Motor Current Limit Map'
     *  SignalConversion generated from: '<S1>/current_limits'
     */
    rtb_MaxAllowedPackCurrentA = fmin(fmin(rtU->pwr_lmt[0], intrp1d_la(bpIdx,
      rtb_RAWTorqueCMDNm, rtConstP.TemperaturetoMotorCurrentLimitM, 10U)),
      intrp1d_la(bpIdx_0, rtb_FRMomentArm,
                 rtConstP.TemperaturetoMotorControllerCur, 2U));

    /* Switch: '<S3>/Max Torque Command Selector' incorporates:
     *  Constant: '<S3>/Abs Max Torque CMD (Nm)'
     *  Gain: '<S3>/Current to Torque'
     *  Sum: '<S3>/Subtract'
     */
    if (rtb_MaxAllowedPackCurrentA - rtU->battery_I > rtP.CURRENT_BUFFER) {
      rtb_MaxAllowedPackCurrentA = 50.0;
    } else {
      rtb_MaxAllowedPackCurrentA *= 50.0 / rtP.BATTERY_CURRENT_MAX;
    }

    /* End of Switch: '<S3>/Max Torque Command Selector' */

    /* Lookup_n-D: '<S3>/Throttle Map ' */
    bpIdx = plook_evenc(rtU->driver_input, 0.0, 0.1, 10U, &rtb_RAWTorqueCMDNm);

    /* Gain: '<S3>/Throttle to Torque' incorporates:
     *  Lookup_n-D: '<S3>/Throttle Map '
     */
    rtb_RAWTorqueCMDNm = 50.0 * intrp1d_l(bpIdx, rtb_RAWTorqueCMDNm,
      rtConstP.pooled10);

    /* Switch: '<S6>/Switch2' incorporates:
     *  Constant: '<S3>/Min Throttle Command (Nm)'
     *  RelationalOperator: '<S6>/LowerRelop1'
     *  RelationalOperator: '<S6>/UpperRelop'
     *  Switch: '<S6>/Switch'
     */
    if (rtb_RAWTorqueCMDNm > rtb_MaxAllowedPackCurrentA) {
      rtb_RAWTorqueCMDNm = rtb_MaxAllowedPackCurrentA;
    } else if (rtb_RAWTorqueCMDNm < 0.1) {
      /* Switch: '<S6>/Switch' incorporates:
       *  Constant: '<S3>/Min Throttle Command (Nm)'
       */
      rtb_RAWTorqueCMDNm = 0.1;
    }

    /* End of Switch: '<S6>/Switch2' */

    /* Product: '<S5>/Divide' incorporates:
     *  Gain: '<S5>/Gain2'
     */
    rtb_FRMomentArm = rtP.MOTOR_ENABLE[0] * rtb_RAWTorqueCMDNm / rtb_Sum4;

    /* Gain: '<S5>/Gain4' */
    rtb_Saturation3_idx_3 = 0.5 * rtb_FRMomentArm;

    /* Sum: '<S5>/Add' */
    rtb_Add_idx_0 = rtb_FRMomentArm + rtb_Saturation3_idx_3;

    /* Gain: '<S5>/Gain4' */
    rtb_Gain4_idx_0 = rtb_Saturation3_idx_3;

    /* Product: '<S5>/Divide' incorporates:
     *  Gain: '<S5>/Gain2'
     */
    rtb_FRMomentArm = rtP.MOTOR_ENABLE[1] * rtb_RAWTorqueCMDNm / rtb_Sum4;

    /* Gain: '<S5>/Gain4' */
    rtb_Saturation3_idx_3 = 0.5 * rtb_FRMomentArm;

    /* Sum: '<S5>/Add' */
    rtb_Add_idx_1 = rtb_FRMomentArm + rtb_Saturation3_idx_3;

    /* Gain: '<S5>/Gain4' */
    rtb_Gain4_idx_1 = rtb_Saturation3_idx_3;

    /* Product: '<S5>/Divide' incorporates:
     *  Gain: '<S5>/Gain2'
     */
    rtb_FRMomentArm = rtP.MOTOR_ENABLE[2] * rtb_RAWTorqueCMDNm / rtb_Sum4;

    /* Gain: '<S5>/Gain4' */
    rtb_Saturation3_idx_3 = 0.5 * rtb_FRMomentArm;

    /* Sum: '<S5>/Add' */
    rtb_Add_idx_2 = rtb_FRMomentArm + rtb_Saturation3_idx_3;

    /* Gain: '<S5>/Gain4' */
    rtb_Gain4_idx_2 = rtb_Saturation3_idx_3;

    /* Product: '<S5>/Divide' incorporates:
     *  Gain: '<S5>/Gain2'
     */
    rtb_FRMomentArm = rtP.MOTOR_ENABLE[3] * rtb_RAWTorqueCMDNm / rtb_Sum4;

    /* Gain: '<S5>/Gain4' */
    rtb_Saturation3_idx_3 = 0.5 * rtb_FRMomentArm;

    /* Sum: '<S5>/Add' */
    rtb_Add_idx_3 = rtb_FRMomentArm + rtb_Saturation3_idx_3;

    /* Sqrt: '<S1>/Sqrt' incorporates:
     *  DotProduct: '<S1>/Dot Product'
     */
    rtb_b_b = sqrt((rtU->vel_VNED[0] * rtU->vel_VNED[0] + rtU->vel_VNED[1] *
                    rtU->vel_VNED[1]) + rtU->vel_VNED[2] * rtU->vel_VNED[2]);

    /* Switch: '<S3>/Switch1' incorporates:
     *  Constant: '<S3>/Constant2'
     */
    if (rtb_b_b >= 1.4) {
      /* Gain: '<S3>/Gain4' incorporates:
       *  Constant: '<S3>/Constant3'
       */
      rtb_MinIndividualMotorTorqueNm_ = -rtP.MOTOR_ENABLE[0] *
        rtP.ABS_MAX_TORQUE[0];

      /* Saturate: '<S3>/Min Torque' */
      if (rtb_MinIndividualMotorTorqueNm_ > 0.01) {
        rtb_MinIndividualMotorTorqueNm_ = 0.01;
      } else if (rtb_MinIndividualMotorTorqueNm_ < 0.0) {
        rtb_MinIndividualMotorTorqueNm_ = 0.0;
      }

      /* Gain: '<S3>/Gain4' incorporates:
       *  Constant: '<S3>/Constant3'
       */
      rtb_MinIndividualMotorTorqueN_0 = -rtP.MOTOR_ENABLE[1] *
        rtP.ABS_MAX_TORQUE[1];

      /* Saturate: '<S3>/Min Torque' */
      if (rtb_MinIndividualMotorTorqueN_0 > 0.01) {
        rtb_MinIndividualMotorTorqueN_0 = 0.01;
      } else if (rtb_MinIndividualMotorTorqueN_0 < 0.0) {
        rtb_MinIndividualMotorTorqueN_0 = 0.0;
      }

      /* Gain: '<S3>/Gain4' incorporates:
       *  Constant: '<S3>/Constant3'
       */
      rtb_MinIndividualMotorTorqueN_1 = -rtP.MOTOR_ENABLE[2] *
        rtP.ABS_MAX_TORQUE[2];

      /* Saturate: '<S3>/Min Torque' */
      if (rtb_MinIndividualMotorTorqueN_1 > 0.01) {
        rtb_MinIndividualMotorTorqueN_1 = 0.01;
      } else if (rtb_MinIndividualMotorTorqueN_1 < 0.0) {
        rtb_MinIndividualMotorTorqueN_1 = 0.0;
      }

      /* Gain: '<S3>/Gain4' incorporates:
       *  Constant: '<S3>/Constant3'
       */
      rtb_MinIndividualMotorTorqueN_2 = -rtP.MOTOR_ENABLE[3] *
        rtP.ABS_MAX_TORQUE[3];

      /* Saturate: '<S3>/Min Torque' */
      if (rtb_MinIndividualMotorTorqueN_2 > 0.01) {
        rtb_MinIndividualMotorTorqueN_2 = 0.01;
      } else if (rtb_MinIndividualMotorTorqueN_2 < 0.0) {
        rtb_MinIndividualMotorTorqueN_2 = 0.0;
      }
    } else {
      rtb_MinIndividualMotorTorqueNm_ = 0.0;
      rtb_MinIndividualMotorTorqueN_0 = 0.0;
      rtb_MinIndividualMotorTorqueN_1 = 0.0;
      rtb_MinIndividualMotorTorqueN_2 = 0.0;
    }

    /* End of Switch: '<S3>/Switch1' */

    /* Lookup_n-D: '<S5>/1-D Lookup Table' */
    rtb_Sum4 = look1_binlc(rtU->theta, rtConstP.pooled11,
      rtConstP.uDLookupTable_tableData, 260U);

    /* Lookup_n-D: '<S5>/1-D Lookup Table1' */
    rtb_FRMomentArm = look1_binlc(rtU->theta, rtConstP.pooled11,
      rtConstP.uDLookupTable1_tableData, 260U);

    /* Product: '<S5>/Product3' incorporates:
     *  Abs: '<S5>/Abs1'
     *  Constant: '<S5>/Constant1'
     *  RelationalOperator: '<S5>/GreaterThan'
     */
    rtb_beq_b = (real_T)(fabs(rtU->theta) > rtP.deadband_angle) * rtU->theta;

    /* Signum: '<S5>/Sign' */
    if (rtIsNaN(rtb_beq_b)) {
      rtb_Saturation3_idx_1 = (rtNaN);
    } else if (rtb_beq_b < 0.0) {
      rtb_Saturation3_idx_1 = -1.0;
    } else {
      rtb_Saturation3_idx_1 = (rtb_beq_b > 0.0);
    }

    /* Product: '<S5>/Product' incorporates:
     *  Abs: '<S5>/Abs'
     *  Constant: '<S5>/Constant5'
     *  Lookup_n-D: '<S5>/2-D Lookup Table'
     *  Signum: '<S5>/Sign'
     *  Sum: '<S2>/b Add'
     */
    rtb_b_b = rtb_Saturation3_idx_1 * look2_binlc(fabs(rtb_beq_b), rtb_b_b,
      rtConstP.uDLookupTable_bp01Data, rtConstP.uDLookupTable_bp02Data,
      rtConstP.uDLookupTable_tableData_p, rtConstP.uDLookupTable_maxIndex, 27U) *
      rtP.TVS_Intensity;

    /* Switch: '<S5>/Switch1' incorporates:
     *  Constant: '<S5>/Constant'
     *  Product: '<S5>/Product1'
     *  SignalConversion generated from: '<S2>/Aeq Dot'
     *  Switch: '<S13>/Switch2'
     */
    if (rtb_b_b != 0.0) {
      /* Switch: '<S13>/Switch2' incorporates:
       *  RelationalOperator: '<S13>/LowerRelop1'
       *  RelationalOperator: '<S13>/UpperRelop'
       *  Switch: '<S13>/Switch'
       */
      if (rtb_Add_idx_0 > rtb_MaxIndividualMotorTorqueNm_) {
        rtb_Add_idx_0 = rtb_MaxIndividualMotorTorqueNm_;
      } else if (rtb_Add_idx_0 < rtb_MinIndividualMotorTorqueNm_) {
        /* Switch: '<S13>/Switch' */
        rtb_Add_idx_0 = rtb_MinIndividualMotorTorqueNm_;
      }

      rtb_beq_b = rtb_Sum4 * rtb_Add_idx_0;

      /* Switch: '<S13>/Switch2' incorporates:
       *  Product: '<S5>/Product1'
       *  RelationalOperator: '<S13>/LowerRelop1'
       *  RelationalOperator: '<S13>/UpperRelop'
       *  SignalConversion generated from: '<S2>/Aeq Dot'
       *  Switch: '<S13>/Switch'
       */
      if (rtb_Gain4_idx_1 > rtb_MaxIndividualMotorTorqueN_0) {
        rtb_Gain4_idx_1 = rtb_MaxIndividualMotorTorqueN_0;
      } else if (rtb_Gain4_idx_1 < rtb_MinIndividualMotorTorqueN_0) {
        /* Switch: '<S13>/Switch' */
        rtb_Gain4_idx_1 = rtb_MinIndividualMotorTorqueN_0;
      }

      rtb_Saturation3_idx_1 = rtb_FRMomentArm * rtb_Gain4_idx_1;

      /* Switch: '<S13>/Switch2' incorporates:
       *  Product: '<S5>/Product1'
       *  RelationalOperator: '<S13>/LowerRelop1'
       *  RelationalOperator: '<S13>/UpperRelop'
       *  SignalConversion generated from: '<S2>/Aeq Dot'
       *  Switch: '<S13>/Switch'
       */
      if (rtb_Add_idx_2 > rtb_MaxIndividualMotorTorqueN_1) {
        rtb_Add_idx_2 = rtb_MaxIndividualMotorTorqueN_1;
      } else if (rtb_Add_idx_2 < rtb_MinIndividualMotorTorqueN_1) {
        /* Switch: '<S13>/Switch' */
        rtb_Add_idx_2 = rtb_MinIndividualMotorTorqueN_1;
      }

      rtb_Add_idx_2 *= 0.621;

      /* Switch: '<S13>/Switch2' incorporates:
       *  Product: '<S5>/Product1'
       *  RelationalOperator: '<S13>/LowerRelop1'
       *  RelationalOperator: '<S13>/UpperRelop'
       *  Switch: '<S13>/Switch'
       */
      if (rtb_Saturation3_idx_3 > rtb_MaxIndividualMotorTorqueN_c) {
        rtb_Saturation3_idx_3 = rtb_MaxIndividualMotorTorqueN_c;
      } else if (rtb_Saturation3_idx_3 < rtb_MinIndividualMotorTorqueN_2) {
        /* Switch: '<S13>/Switch' */
        rtb_Saturation3_idx_3 = rtb_MinIndividualMotorTorqueN_2;
      }

      rtb_Saturation3_idx_3 *= -0.621;
    } else {
      rtb_beq_b = 0.001;
      rtb_Saturation3_idx_1 = 0.001;
      rtb_Add_idx_2 = 0.001;
      rtb_Saturation3_idx_3 = 0.001;
    }

    /* End of Switch: '<S5>/Switch1' */

    /* Saturate: '<S5>/Saturation3' */
    if (rtb_beq_b <= 0.001) {
      rtb_beq_b = 0.001;
    }

    if (rtb_Saturation3_idx_1 <= 0.001) {
      rtb_Saturation3_idx_1 = 0.001;
    }

    if (rtb_Add_idx_2 <= 0.001) {
      rtb_Add_idx_2 = 0.001;
    }

    /* Switch: '<S5>/Switch2' incorporates:
     *  Product: '<S5>/Product2'
     *  SignalConversion generated from: '<S2>/Aeq Dot'
     *  Switch: '<S14>/Switch2'
     */
    if (rtb_b_b != 0.0) {
      /* Switch: '<S14>/Switch2' incorporates:
       *  RelationalOperator: '<S14>/LowerRelop1'
       *  RelationalOperator: '<S14>/UpperRelop'
       *  Switch: '<S14>/Switch'
       */
      if (rtb_Gain4_idx_0 > rtb_MaxIndividualMotorTorqueNm_) {
        rtb_Gain4_idx_0 = rtb_MaxIndividualMotorTorqueNm_;
      } else if (rtb_Gain4_idx_0 < rtb_MinIndividualMotorTorqueNm_) {
        /* Switch: '<S14>/Switch' */
        rtb_Gain4_idx_0 = rtb_MinIndividualMotorTorqueNm_;
      }

      rtb_Gain4_idx_0 *= rtb_Sum4;

      /* Switch: '<S14>/Switch2' incorporates:
       *  Product: '<S5>/Product2'
       *  RelationalOperator: '<S14>/LowerRelop1'
       *  RelationalOperator: '<S14>/UpperRelop'
       *  SignalConversion generated from: '<S2>/Aeq Dot'
       *  Switch: '<S14>/Switch'
       */
      if (rtb_Add_idx_1 > rtb_MaxIndividualMotorTorqueN_0) {
        rtb_Add_idx_1 = rtb_MaxIndividualMotorTorqueN_0;
      } else if (rtb_Add_idx_1 < rtb_MinIndividualMotorTorqueN_0) {
        /* Switch: '<S14>/Switch' */
        rtb_Add_idx_1 = rtb_MinIndividualMotorTorqueN_0;
      }

      rtb_Add_idx_1 *= rtb_FRMomentArm;

      /* Switch: '<S14>/Switch2' incorporates:
       *  Product: '<S5>/Product2'
       *  RelationalOperator: '<S14>/LowerRelop1'
       *  RelationalOperator: '<S14>/UpperRelop'
       *  SignalConversion generated from: '<S2>/Aeq Dot'
       *  Switch: '<S14>/Switch'
       */
      if (rtb_Gain4_idx_2 > rtb_MaxIndividualMotorTorqueN_1) {
        rtb_Gain4_idx_2 = rtb_MaxIndividualMotorTorqueN_1;
      } else if (rtb_Gain4_idx_2 < rtb_MinIndividualMotorTorqueN_1) {
        /* Switch: '<S14>/Switch' */
        rtb_Gain4_idx_2 = rtb_MinIndividualMotorTorqueN_1;
      }

      rtb_Gain4_idx_2 *= 0.621;

      /* Switch: '<S14>/Switch2' incorporates:
       *  Product: '<S5>/Product2'
       *  RelationalOperator: '<S14>/LowerRelop1'
       *  RelationalOperator: '<S14>/UpperRelop'
       *  Switch: '<S14>/Switch'
       */
      if (rtb_Add_idx_3 > rtb_MaxIndividualMotorTorqueN_c) {
        rtb_Add_idx_3 = rtb_MaxIndividualMotorTorqueN_c;
      } else if (rtb_Add_idx_3 < rtb_MinIndividualMotorTorqueN_2) {
        /* Switch: '<S14>/Switch' */
        rtb_Add_idx_3 = rtb_MinIndividualMotorTorqueN_2;
      }

      rtb_Add_idx_0 = -0.621 * rtb_Add_idx_3;
    } else {
      rtb_Gain4_idx_0 = -0.001;
      rtb_Add_idx_1 = -0.001;
      rtb_Gain4_idx_2 = -0.001;
      rtb_Add_idx_0 = -0.001;
    }

    /* End of Switch: '<S5>/Switch2' */

    /* Saturate: '<S5>/Saturation3' */
    if (rtb_Saturation3_idx_3 <= 0.001) {
      rtb_Saturation3_idx_3 = 0.001;
    }

    /* Sum: '<S5>/Sum2' incorporates:
     *  Saturate: '<S5>/Saturation3'
     */
    rtb_Add_idx_3 = ((rtb_beq_b + rtb_Saturation3_idx_1) + rtb_Add_idx_2) +
      rtb_Saturation3_idx_3;

    /* Sum: '<S5>/Sum' incorporates:
     *  Gain: '<S5>/Gain'
     *  Gain: '<S5>/Gain1'
     *  Sum: '<S5>/Sum1'
     *  UnitDelay: '<S5>/Unit Delay'
     */
    rtb_beq_b = (rtb_b_b - rtU->angvel_VNED[2]) * rtP.alpha_error + (1.0 -
      rtP.alpha_error) * rtDW->UnitDelay_DSTATE;

    /* Saturate: '<S5>/Saturation' */
    if (rtb_beq_b > 2.5) {
      rtb_Saturation3_idx_1 = 2.5;
    } else if (rtb_beq_b < -2.5) {
      rtb_Saturation3_idx_1 = -2.5;
    } else {
      rtb_Saturation3_idx_1 = rtb_beq_b;
    }

    /* Gain: '<S5>/P' incorporates:
     *  Saturate: '<S5>/Saturation'
     */
    rtb_Saturation3_idx_3 = rtP.P * rtb_Saturation3_idx_1;

    /* UnitDelay: '<S15>/Unit Delay' */
    rtb_Add_idx_2 = rtDW->UnitDelay_DSTATE_b;

    /* Gain: '<S11>/Gain' */
    rtb_Gain4_idx_1 = rtP.I * 0.015 * rtb_beq_b;

    /* Switch: '<S11>/Switch1' incorporates:
     *  Constant: '<S11>/Constant2'
     *  Gain: '<S11>/Gain1'
     *  Sum: '<S11>/Sum3'
     *  UnitDelay: '<S11>/Unit Delay1'
     *  UnitDelay: '<S15>/Unit Delay'
     */
    if (rtDW->UnitDelay_DSTATE_b > 0.0) {
      rtb_Saturation3_idx_1 = 0.0;
    } else {
      rtb_Saturation3_idx_1 = (rtb_Gain4_idx_1 + rtDW->UnitDelay1_DSTATE) * 0.5;
    }

    /* Sum: '<S11>/Sum2' incorporates:
     *  Switch: '<S11>/Switch1'
     *  UnitDelay: '<S11>/Unit Delay2'
     */
    rtb_Saturation3_idx_1 += rtDW->UnitDelay2_DSTATE;

    /* Sum: '<S5>/Sum7' */
    rtb_ref_ang_acc = rtb_Saturation3_idx_3 + rtb_Saturation3_idx_1;

    /* Saturate: '<S5>/Saturation4' */
    if (rtb_Gain4_idx_0 >= -0.001) {
      rtb_Gain4_idx_0 = -0.001;
    }

    if (rtb_Add_idx_1 >= -0.001) {
      rtb_Add_idx_1 = -0.001;
    }

    if (rtb_Gain4_idx_2 >= -0.001) {
      rtb_Gain4_idx_2 = -0.001;
    }

    if (rtb_Add_idx_0 >= -0.001) {
      rtb_Add_idx_0 = -0.001;
    }

    /* Sum: '<S5>/Sum3' incorporates:
     *  Saturate: '<S5>/Saturation4'
     */
    rtb_Gain4_idx_0 = ((rtb_Gain4_idx_0 + rtb_Add_idx_1) + rtb_Gain4_idx_2) +
      rtb_Add_idx_0;

    /* Switch: '<S12>/Switch2' incorporates:
     *  RelationalOperator: '<S12>/LowerRelop1'
     *  RelationalOperator: '<S12>/UpperRelop'
     *  Switch: '<S12>/Switch'
     */
    if (rtb_ref_ang_acc > rtb_Add_idx_3) {
      rtb_ref_ang_acc = rtb_Add_idx_3;
    } else if (rtb_ref_ang_acc < rtb_Gain4_idx_0) {
      /* Switch: '<S12>/Switch' */
      rtb_ref_ang_acc = rtb_Gain4_idx_0;
    }

    /* End of Switch: '<S12>/Switch2' */

    /* Switch: '<S5>/Switch' incorporates:
     *  Saturate: '<S5>/Saturation2'
     */
    if (rtb_ref_ang_acc > 0.0) {
      /* Saturate: '<S5>/Saturation1' */
      if (rtb_ref_ang_acc <= 0.001) {
        rtb_ref_ang_acc = 0.001;
      }

      /* End of Saturate: '<S5>/Saturation1' */
    } else if (rtb_ref_ang_acc >= -0.001) {
      /* Saturate: '<S5>/Saturation2' */
      rtb_ref_ang_acc = -0.001;
    }

    /* End of Switch: '<S5>/Switch' */

    /* CCaller: '<S2>/C Caller' incorporates:
     *  Constant: '<S2>/Tx_initial'
     */
    rtb_Add_idx_1 = 0.0;
    rtb_Gain4_idx_2 = 0.0;
    rtb_Add_idx_0 = 0.0;
    rtb_TRR = 0.0;

    /* Outport: '<Root>/bigM_flag' incorporates:
     *  Bias: '<S2>/lb_offset'
     *  Bias: '<S2>/ub_offset'
     *  CCaller: '<S2>/C Caller'
     *  Constant: '<S2>/Constant1'
     *  Constant: '<S2>/optimization_offset_A'
     *  Constant: '<S2>/optimization_offset_Aeq'
     *  Constant: '<S2>/yaw_error_limit'
     *  Constant: '<S5>/Constant3'
     *  Constant: '<S5>/Constant4'
     *  DotProduct: '<S2>/A Dot'
     *  DotProduct: '<S2>/Aeq Dot'
     *  SignalConversion generated from: '<S2>/Aeq Dot'
     *  Sum: '<S2>/b Add'
     *  Sum: '<S2>/beq Add'
     */
    rtY->bigM_flag = bigM_func(39.2280863132881, 39.2280863132881,
      39.2280863132881, 39.2280863132881, (((rtP.ABS_MAX_TORQUE[0] +
      rtP.ABS_MAX_TORQUE[1]) + rtP.ABS_MAX_TORQUE[2]) + rtP.ABS_MAX_TORQUE[3]) +
      rtb_RAWTorqueCMDNm, 1.0, 1.0, 1.0, 1.0, (((rtP.ABS_MAX_TORQUE[0] *
      rtb_Sum4 + rtP.ABS_MAX_TORQUE[1] * rtb_FRMomentArm) + rtP.ABS_MAX_TORQUE[2]
      * 0.621) + rtP.ABS_MAX_TORQUE[3] * -0.621) + rtb_ref_ang_acc, rtb_Sum4,
      rtb_FRMomentArm, 0.621, -0.621, rtb_MinIndividualMotorTorqueNm_ +
      rtP.ABS_MAX_TORQUE[0], rtb_MinIndividualMotorTorqueN_0 +
      rtP.ABS_MAX_TORQUE[1], rtb_MinIndividualMotorTorqueN_1 +
      rtP.ABS_MAX_TORQUE[2], rtb_MinIndividualMotorTorqueN_2 +
      rtP.ABS_MAX_TORQUE[3], rtb_ub_b_idx_0, rtb_ub_b_idx_1, rtb_ub_b_idx_2,
      rtb_MaxIndividualMotorTorqueN_c + rtP.ABS_MAX_TORQUE[3], &rtb_Add_idx_1,
      &rtb_Gain4_idx_2, &rtb_Add_idx_0, &rtb_TRR, 0.2);

    /* Switch: '<S11>/Switch2' */
    if (rtb_Add_idx_2 > 0.0) {
      /* Update for UnitDelay: '<S11>/Unit Delay2' incorporates:
       *  Sum: '<S11>/Sum1'
       */
      rtDW->UnitDelay2_DSTATE = rtb_ref_ang_acc - rtb_Saturation3_idx_3;
    } else {
      /* Update for UnitDelay: '<S11>/Unit Delay2' */
      rtDW->UnitDelay2_DSTATE = rtb_Saturation3_idx_1;
    }

    /* End of Switch: '<S11>/Switch2' */

    /* Switch: '<S15>/Switch1' incorporates:
     *  Bias: '<S15>/Bias'
     *  Bias: '<S15>/Bias1'
     *  Bias: '<S15>/Bias2'
     *  Bias: '<S15>/Bias3'
     *  Logic: '<S15>/AND'
     *  Logic: '<S15>/OR'
     *  RelationalOperator: '<S15>/Less Than'
     *  RelationalOperator: '<S15>/Less Than1'
     *  RelationalOperator: '<S15>/Less Than2'
     *  RelationalOperator: '<S15>/Less Than3'
     *  Switch: '<S15>/Switch'
     */
    if ((rtb_ref_ang_acc < rtb_Gain4_idx_0 - 0.1) || (rtb_ref_ang_acc >
         rtb_Add_idx_3 + 0.1)) {
      /* Update for UnitDelay: '<S15>/Unit Delay' */
      rtDW->UnitDelay_DSTATE_b = 1.0;
    } else if ((rtb_ref_ang_acc > rtb_Gain4_idx_0 + 0.1) && (rtb_ref_ang_acc <
                rtb_Add_idx_3 - 0.1)) {
      /* Switch: '<S15>/Switch' incorporates:
       *  UnitDelay: '<S15>/Unit Delay'
       */
      rtDW->UnitDelay_DSTATE_b = 0.0;
    } else {
      /* Update for UnitDelay: '<S15>/Unit Delay' incorporates:
       *  Switch: '<S15>/Switch'
       */
      rtDW->UnitDelay_DSTATE_b = rtb_Add_idx_2;
    }

    /* End of Switch: '<S15>/Switch1' */

    /* Update for UnitDelay: '<S5>/Unit Delay' */
    rtDW->UnitDelay_DSTATE = rtb_beq_b;

    /* Update for UnitDelay: '<S11>/Unit Delay1' */
    rtDW->UnitDelay1_DSTATE = rtb_Gain4_idx_1;

    /* End of Outputs for SubSystem: '<Root>/TVS' */

    /* Outport: '<Root>/Aeq' incorporates:
     *  Constant: '<S5>/Constant3'
     *  Constant: '<S5>/Constant4'
     */
    rtY->Aeq[0] = rtb_Sum4;
    rtY->Aeq[1] = rtb_FRMomentArm;
    rtY->Aeq[2] = 0.621;
    rtY->Aeq[3] = -0.621;

    /* Outport: '<Root>/obj_gain' */
    rtY->obj_gain[0] = 39.2280863132881;

    /* Outport: '<Root>/lb' */
    rtY->lb[0] = rtb_MinIndividualMotorTorqueNm_;

    /* Outport: '<Root>/ub' */
    rtY->ub[0] = rtb_MaxIndividualMotorTorqueNm_;

    /* Outport: '<Root>/Tx' incorporates:
     *  RateLimiter: '<S2>/Tx_rate_limit'
     */
    rtY->Tx[0] = rtb_Tx_idx_0;

    /* Outport: '<Root>/omega_m_TV' incorporates:
     *  Gain: '<S1>/Gain1'
     */
    rtY->omega_m_TV[0] = rtb_omega_m_idx_0;

    /* Outputs for Atomic SubSystem: '<Root>/TVS' */
    /* Outport: '<Root>/motor_I' incorporates:
     *  Inport: '<Root>/motor_current'
     *  SignalConversion generated from: '<S1>/motor_current'
     */
    rtY->motor_I[0] = rtU->motor_I[0];

    /* Outport: '<Root>/motor_V' incorporates:
     *  SignalConversion generated from: '<S1>/motor_voltage'
     */
    rtY->motor_V[0] = rtU->motor_V[0];

    /* End of Outputs for SubSystem: '<Root>/TVS' */

    /* Outport: '<Root>/obj_gain' */
    rtY->obj_gain[1] = 39.2280863132881;

    /* Outport: '<Root>/lb' */
    rtY->lb[1] = rtb_MinIndividualMotorTorqueN_0;

    /* Outport: '<Root>/ub' */
    rtY->ub[1] = rtb_MaxIndividualMotorTorqueN_0;

    /* Outport: '<Root>/Tx' incorporates:
     *  RateLimiter: '<S2>/Tx_rate_limit'
     */
    rtY->Tx[1] = rtb_Tx_idx_1;

    /* Outport: '<Root>/omega_m_TV' incorporates:
     *  Gain: '<S1>/Gain1'
     */
    rtY->omega_m_TV[1] = rtb_omega_m_idx_1;

    /* Outputs for Atomic SubSystem: '<Root>/TVS' */
    /* Outport: '<Root>/motor_I' incorporates:
     *  Inport: '<Root>/motor_current'
     *  SignalConversion generated from: '<S1>/motor_current'
     */
    rtY->motor_I[1] = rtU->motor_I[1];

    /* Outport: '<Root>/motor_V' incorporates:
     *  SignalConversion generated from: '<S1>/motor_voltage'
     */
    rtY->motor_V[1] = rtU->motor_V[1];

    /* End of Outputs for SubSystem: '<Root>/TVS' */

    /* Outport: '<Root>/obj_gain' */
    rtY->obj_gain[2] = 39.2280863132881;

    /* Outport: '<Root>/lb' */
    rtY->lb[2] = rtb_MinIndividualMotorTorqueN_1;

    /* Outport: '<Root>/ub' */
    rtY->ub[2] = rtb_MaxIndividualMotorTorqueN_1;

    /* Outport: '<Root>/Tx' incorporates:
     *  RateLimiter: '<S2>/Tx_rate_limit'
     */
    rtY->Tx[2] = rtb_Tx_idx_2;

    /* Outport: '<Root>/omega_m_TV' incorporates:
     *  Gain: '<S1>/Gain1'
     */
    rtY->omega_m_TV[2] = rtb_omega_m_idx_2;

    /* Outputs for Atomic SubSystem: '<Root>/TVS' */
    /* Outport: '<Root>/motor_I' incorporates:
     *  Inport: '<Root>/motor_current'
     *  SignalConversion generated from: '<S1>/motor_current'
     */
    rtY->motor_I[2] = rtU->motor_I[2];

    /* Outport: '<Root>/motor_V' incorporates:
     *  SignalConversion generated from: '<S1>/motor_voltage'
     */
    rtY->motor_V[2] = rtU->motor_V[2];

    /* End of Outputs for SubSystem: '<Root>/TVS' */

    /* Outport: '<Root>/obj_gain' */
    rtY->obj_gain[3] = 39.2280863132881;

    /* Outport: '<Root>/lb' */
    rtY->lb[3] = rtb_MinIndividualMotorTorqueN_2;

    /* Outport: '<Root>/ub' */
    rtY->ub[3] = rtb_MaxIndividualMotorTorqueN_c;

    /* Outport: '<Root>/Tx' */
    rtY->Tx[3] = rtb_Tx_m;

    /* Outport: '<Root>/omega_m_TV' incorporates:
     *  Gain: '<S1>/Gain1'
     */
    rtY->omega_m_TV[3] = rtb_omega_m_idx_3;

    /* Outputs for Atomic SubSystem: '<Root>/TVS' */
    /* Outport: '<Root>/motor_I' incorporates:
     *  Inport: '<Root>/motor_current'
     *  SignalConversion generated from: '<S1>/motor_current'
     */
    rtY->motor_I[3] = rtU->motor_I[3];

    /* Outport: '<Root>/motor_V' incorporates:
     *  SignalConversion generated from: '<S1>/motor_voltage'
     */
    rtY->motor_V[3] = rtU->motor_V[3];

    /* End of Outputs for SubSystem: '<Root>/TVS' */

    /* Outport: '<Root>/I_limits' */
    rtY->I_limits[0] = rtb_current_limits_idx_0;
    rtY->I_limits[1] = rtb_current_limits_idx_1;

    /* Outport: '<Root>/ref_yaw' */
    rtY->ref_yaw = rtb_b_b;

    /* Outport: '<Root>/beq' */
    rtY->beq = rtb_ref_ang_acc;

    /* Outport: '<Root>/windup' */
    rtY->windup = rtb_Add_idx_2;

    /* Outport: '<Root>/b' */
    rtY->b = rtb_RAWTorqueCMDNm;

    /* Outport: '<Root>/max_b' */
    rtY->max_b = rtb_MaxAllowedPackCurrentA;

    /* Outport: '<Root>/max_ang_acc' */
    rtY->max_ang_acc = rtU->battery_V;

    /* Outport: '<Root>/min_ang_acc' */
    rtY->min_ang_acc = rtU->battery_V;

    /* Outport: '<Root>/batt_V' */
    rtY->batt_V = rtU->battery_V;
  }

  rate_scheduler(rtM);
}

/* Model initialize function */
void TVS_initialize(RT_MODEL *const rtM)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  UNUSED_PARAMETER(rtM);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
