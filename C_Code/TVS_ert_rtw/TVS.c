/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TVS.c
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

#include "TVS.h"
#include <math.h>
#include "rtwtypes.h"
#include <stddef.h>
#define NumBitsPerChar                 8U

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
static real_T look1_pbinlg(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T prevIndex[], uint32_T maxIndex);
static uint32_T plook_evenc(real_T u, real_T bp0, real_T bpSpace, uint32_T
  maxIndex, real_T *fraction);
static real_T intrp1d_l(uint32_T bpIndex, real_T frac, const real_T table[]);
static real_T rtGetNaN(void);
static real32_T rtGetNaNF(void);
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

static real_T look1_pbinlg(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T prevIndex[], uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T bpIdx;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'on'
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'on'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'on'
   */
  if (u0 < bp0[maxIndex]) {
    uint32_T found;
    uint32_T iLeft;
    uint32_T iRght;

    /* Binary Search using Previous Index */
    bpIdx = prevIndex[0U];
    iLeft = 0U;
    iRght = maxIndex;
    found = 0U;
    while (found == 0U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx - 1U;
        bpIdx = ((bpIdx + iLeft) - 1U) >> 1U;
      } else if (u0 < bp0[bpIdx + 1U]) {
        found = 1U;
      } else {
        iLeft = bpIdx + 1U;
        bpIdx = ((bpIdx + iRght) + 1U) >> 1U;
      }
    }

    frac = (u0 - bp0[bpIdx]) / (bp0[bpIdx + 1U] - bp0[bpIdx]);
  } else {
    bpIdx = maxIndex - 1U;
    frac = 1.0;
  }

  prevIndex[0U] = bpIdx;

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'wrapping'
   */
  yL_0d0 = table[bpIdx];
  return (table[bpIdx + 1U] - yL_0d0) * frac + yL_0d0;
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

/* Model step function */
void TVS_step(void)
{
  real_T rtb_Abs1[64];
  real_T rtb_Abs_d[64];
  real_T rtb_Gain1[4];
  real_T rtb_Gain6[4];
  real_T rtb_Switch1_f[4];
  real_T rtb_UnitDelay[4];
  real_T I_control;
  real_T rtb_Abs_j_idx_0;
  real_T rtb_Add_idx_0;
  real_T rtb_Add_idx_1;
  real_T rtb_Add_idx_2;
  real_T rtb_Add_idx_3;
  real_T rtb_DotProduct1;
  real_T rtb_Gain1_by;
  real_T rtb_Gain_idx_0;
  real_T rtb_Gain_idx_1;
  real_T rtb_Gain_idx_2;
  real_T rtb_Gain_idx_3;
  real_T rtb_Square1;
  real_T rtb_Square1_p;
  real_T rtb_Switch1_idx_0;
  real_T rtb_Switch1_idx_1;
  real_T rtb_Switch1_idx_2;
  real_T rtb_Switch1_idx_3;
  real_T rtb_TFL;
  real_T rtb_TFR;
  real_T rtb_Tx_deadband_idx_0;
  real_T rtb_b_b;
  real_T rtb_motor_temp_idx_0;
  real_T rtb_motor_temp_idx_1;
  real_T rtb_motor_temp_idx_2;
  real_T rtb_motor_temp_idx_3;
  real_T rtb_power_limits_idx_0;
  real_T rtb_power_limits_idx_1;
  real_T u0;
  real_T y;
  real_T y_0;
  real_T y_1;
  int32_T i;
  int32_T n;
  int32_T rtb_Abs1_tmp;
  int32_T rtb_exitflag;
  uint32_T bpIdx;
  boolean_T rtb_GreaterThan1;
  boolean_T rtb_UnitDelay4;
  boolean_T rtb_UnitDelay_g;

  /* Outputs for Atomic SubSystem: '<Root>/TVS' */
  /* SignalConversion generated from: '<S1>/<motor_temp>' incorporates:
   *  Inport: '<Root>/<motor_temp>'
   */
  rtb_motor_temp_idx_0 = rtU.motor_T[0];
  rtb_motor_temp_idx_1 = rtU.motor_T[1];
  rtb_motor_temp_idx_2 = rtU.motor_T[2];
  rtb_motor_temp_idx_3 = rtU.motor_T[3];

  /* SignalConversion generated from: '<S1>/<power_limits>' incorporates:
   *  Inport: '<Root>/<power_limits>'
   */
  rtb_power_limits_idx_0 = rtU.pwr_lmt[0];
  rtb_power_limits_idx_1 = rtU.pwr_lmt[1];

  /* Outputs for Atomic SubSystem: '<S1>/Torque Vectoring Micro Controller' */
  for (i = 0; i < 4; i++) {
    /* UnitDelay: '<S1>/Unit Delay' */
    rtb_UnitDelay[i] = rtDW.UnitDelay_DSTATE[i];

    /* Gain: '<S10>/Gain1' incorporates:
     *  Inport: '<Root>/<omega>'
     */
    rtb_Gain1_by = rtConstP.Gain1_Gain[i] * rtU.omega[i];

    /* Gain: '<S11>/Gain' */
    rtb_Square1_p = 0.095492965964253843 * rtb_Gain1_by;

    /* Saturate: '<S11>/Saturation1' */
    if (rtb_Square1_p > 106.0) {
      rtb_Square1_p = 106.0;
    } else if (rtb_Square1_p < 1.0) {
      rtb_Square1_p = 1.0;
    }

    /* Switch: '<S11>/Switch' incorporates:
     *  Constant: '<S11>/Constant6'
     *  Inport: '<Root>/<motor_temp>'
     *  RelationalOperator: '<S11>/Less Than'
     *  SignalConversion generated from: '<S1>/<motor_temp>'
     */
    if (rtU.motor_T[i] < 75.0) {
      rtb_Switch1_idx_0 = 5800.0;
    } else {
      rtb_Switch1_idx_0 = 1800.0;
    }

    /* End of Switch: '<S11>/Switch' */
    for (n = 0; n < 16; n++) {
      /* Abs: '<S11>/Abs1' incorporates:
       *  Abs: '<S11>/Abs'
       *  Bias: '<S11>/Bias'
       *  Constant: '<S11>/Constant4'
       *  Constant: '<S11>/Constant5'
       *  Gain: '<S11>/Gain3'
       *  Selector: '<S11>/Selector'
       *  Selector: '<S11>/Selector1'
       *  Sum: '<S11>/Sum1'
       */
      rtb_exitflag = (int32_T)rtConstP.pooled4[n];
      rtb_Abs1_tmp = (i << 4) + n;
      rtb_Abs1[rtb_Abs1_tmp] = fabs(rtConstP.pooled8[((((int32_T)(rtb_Square1_p
        + 1.0) - 1) << 4) + rtb_exitflag) - 1] - rtb_Switch1_idx_0);

      /* Gain: '<S11>/Gain3' incorporates:
       *  Abs: '<S11>/Abs'
       *  Constant: '<S11>/Constant1'
       *  Selector: '<S11>/Selector'
       *  Sum: '<S11>/Sum'
       */
      rtb_Abs_d[rtb_Abs1_tmp] = fabs(rtConstP.pooled8[((((int32_T)rtb_Square1_p
        - 1) << 4) + rtb_exitflag) - 1] - rtb_Switch1_idx_0);
    }

    /* Gain: '<S10>/Gain1' */
    rtb_Gain1[i] = rtb_Gain1_by;

    /* Saturate: '<S11>/Saturation1' incorporates:
     *  Switch: '<S13>/Switch1'
     */
    rtb_Switch1_f[i] = rtb_Square1_p;
  }

  /* S-Function (sdspstatminmax): '<S11>/Minimum' incorporates:
   *  Abs: '<S11>/Abs'
   *  Switch: '<S13>/Switch1'
   */
  i = 0;
  n = 0;
  for (rtb_exitflag = 0; rtb_exitflag < 4; rtb_exitflag++) {
    rtDW.Minimum_Valdata[n] = rtb_Abs_d[i];
    rtb_Switch1_f[n] = 1.0;
    i++;
    for (rtb_Abs1_tmp = 0; rtb_Abs1_tmp < 15; rtb_Abs1_tmp++) {
      if (rtb_Abs_d[i] < rtDW.Minimum_Valdata[n]) {
        rtDW.Minimum_Valdata[n] = rtb_Abs_d[i];
        rtb_Switch1_f[n] = (real_T)rtb_Abs1_tmp + 2.0;
      }

      i++;
    }

    n++;
  }

  /* End of S-Function (sdspstatminmax): '<S11>/Minimum' */

  /* S-Function (sdspstatminmax): '<S11>/Minimum1' incorporates:
   *  Abs: '<S11>/Abs1'
   *  Constant: '<S11>/Constant7'
   *  Gain: '<S13>/Gain6'
   *  Selector: '<S11>/Selector2'
   *  Switch: '<S13>/Switch1'
   */
  i = 0;
  n = 0;
  for (rtb_exitflag = 0; rtb_exitflag < 4; rtb_exitflag++) {
    rtDW.Minimum1_Valdata[n] = rtb_Abs1[i];
    rtb_Gain6[n] = 1.0;
    i++;
    for (rtb_Abs1_tmp = 0; rtb_Abs1_tmp < 15; rtb_Abs1_tmp++) {
      if (rtb_Abs1[i] < rtDW.Minimum1_Valdata[n]) {
        rtDW.Minimum1_Valdata[n] = rtb_Abs1[i];
        rtb_Gain6[n] = (real_T)rtb_Abs1_tmp + 2.0;
      }

      i++;
    }

    n++;
    rtb_Switch1_f[rtb_exitflag] = rtConstP.pooled5[(int32_T)
      rtb_Switch1_f[rtb_exitflag] - 1];
  }

  /* End of S-Function (sdspstatminmax): '<S11>/Minimum1' */

  /* Sum: '<S11>/Sum2' incorporates:
   *  Constant: '<S11>/Constant8'
   *  Constant: '<S11>/Constant9'
   *  Gain: '<S10>/Gain1'
   *  Gain: '<S11>/Gain1'
   *  Gain: '<S11>/Gain2'
   *  Gain: '<S13>/Gain6'
   *  Product: '<S11>/Divide'
   *  Product: '<S11>/Product1'
   *  Rounding: '<S11>/Floor'
   *  Selector: '<S11>/Selector3'
   *  Sum: '<S11>/Sum3'
   *  Sum: '<S11>/Sum4'
   */
  rtb_Gain1_by = (rtb_Gain1[0] - floor(0.095492965964253843 * rtb_Gain1[0]) *
                  10.4719755) / 10.4719755 * (rtConstP.pooled5[(int32_T)
    rtb_Gain6[0] - 1] - rtb_Switch1_f[0]) + rtb_Switch1_f[0];
  rtb_Switch1_idx_0 = (rtb_Gain1[1] - floor(0.095492965964253843 * rtb_Gain1[1])
                       * 10.4719755) / 10.4719755 * (rtConstP.pooled5[(int32_T)
    rtb_Gain6[1] - 1] - rtb_Switch1_f[1]) + rtb_Switch1_f[1];
  rtb_Switch1_idx_1 = (rtb_Gain1[2] - floor(0.095492965964253843 * rtb_Gain1[2])
                       * 10.4719755) / 10.4719755 * (rtConstP.pooled5[(int32_T)
    rtb_Gain6[2] - 1] - rtb_Switch1_f[2]) + rtb_Switch1_f[2];
  rtb_Switch1_idx_2 = (rtb_Gain1[3] - floor(0.095492965964253843 * rtb_Gain1[3])
                       * 10.4719755) / 10.4719755 * (rtConstP.pooled5[(int32_T)
    rtb_Gain6[3] - 1] - rtb_Switch1_f[3]) + rtb_Switch1_f[3];

  /* Lookup_n-D: '<S11>/1-D Lookup Table' incorporates:
   *  Gain: '<S10>/Gain1'
   *  Gain: '<S13>/Gain6'
   */
  rtb_Gain6[0] = look1_pbinlg(rtb_Gain1[0], rtConstP.uDLookupTable_bp01Data,
    rtConstP.uDLookupTable_tableData, &rtDW.m_bpIndex[0], 67U);
  rtb_Gain6[1] = look1_pbinlg(rtb_Gain1[1], rtConstP.uDLookupTable_bp01Data,
    rtConstP.uDLookupTable_tableData, &rtDW.m_bpIndex[1], 67U);
  rtb_Gain6[2] = look1_pbinlg(rtb_Gain1[2], rtConstP.uDLookupTable_bp01Data,
    rtConstP.uDLookupTable_tableData, &rtDW.m_bpIndex[2], 67U);
  rtb_Gain6[3] = look1_pbinlg(rtb_Gain1[3], rtConstP.uDLookupTable_bp01Data,
    rtConstP.uDLookupTable_tableData, &rtDW.m_bpIndex[3], 67U);

  /* Switch: '<S14>/Switch2' incorporates:
   *  Gain: '<S11>/Gain4'
   *  Gain: '<S13>/Gain6'
   *  RelationalOperator: '<S14>/LowerRelop1'
   *  RelationalOperator: '<S14>/UpperRelop'
   *  Switch: '<S13>/Switch1'
   *  Switch: '<S14>/Switch'
   */
  if (rtb_Gain1_by > rtb_Gain6[0]) {
    rtb_Gain1_by = rtb_Gain6[0];
  } else if (rtb_Gain1_by < -rtb_Gain6[0]) {
    /* Switch: '<S14>/Switch' */
    rtb_Gain1_by = -rtb_Gain6[0];
  }

  rtb_Switch1_f[0] = rtb_Gain1_by;

  /* Sum: '<S11>/Sum2' */
  rtb_Gain1_by = rtb_Switch1_idx_0;

  /* Switch: '<S14>/Switch2' incorporates:
   *  Gain: '<S11>/Gain4'
   *  Gain: '<S13>/Gain6'
   *  RelationalOperator: '<S14>/LowerRelop1'
   *  RelationalOperator: '<S14>/UpperRelop'
   *  Switch: '<S13>/Switch1'
   *  Switch: '<S14>/Switch'
   */
  if (rtb_Switch1_idx_0 > rtb_Gain6[1]) {
    rtb_Gain1_by = rtb_Gain6[1];
  } else if (rtb_Switch1_idx_0 < -rtb_Gain6[1]) {
    /* Switch: '<S14>/Switch' */
    rtb_Gain1_by = -rtb_Gain6[1];
  }

  rtb_Switch1_f[1] = rtb_Gain1_by;

  /* Sum: '<S11>/Sum2' */
  rtb_Gain1_by = rtb_Switch1_idx_1;

  /* Switch: '<S14>/Switch2' incorporates:
   *  Gain: '<S11>/Gain4'
   *  Gain: '<S13>/Gain6'
   *  RelationalOperator: '<S14>/LowerRelop1'
   *  RelationalOperator: '<S14>/UpperRelop'
   *  Switch: '<S13>/Switch1'
   *  Switch: '<S14>/Switch'
   */
  if (rtb_Switch1_idx_1 > rtb_Gain6[2]) {
    rtb_Gain1_by = rtb_Gain6[2];
  } else if (rtb_Switch1_idx_1 < -rtb_Gain6[2]) {
    /* Switch: '<S14>/Switch' */
    rtb_Gain1_by = -rtb_Gain6[2];
  }

  rtb_Switch1_f[2] = rtb_Gain1_by;

  /* Sum: '<S11>/Sum2' */
  rtb_Gain1_by = rtb_Switch1_idx_2;

  /* Switch: '<S14>/Switch2' incorporates:
   *  Gain: '<S11>/Gain4'
   *  Gain: '<S13>/Gain6'
   *  RelationalOperator: '<S14>/LowerRelop1'
   *  RelationalOperator: '<S14>/UpperRelop'
   *  Switch: '<S14>/Switch'
   */
  if (rtb_Switch1_idx_2 > rtb_Gain6[3]) {
    rtb_Gain1_by = rtb_Gain6[3];
  } else if (rtb_Switch1_idx_2 < -rtb_Gain6[3]) {
    /* Switch: '<S14>/Switch' */
    rtb_Gain1_by = -rtb_Gain6[3];
  }

  /* Switch: '<S12>/Switch1' incorporates:
   *  Constant: '<S12>/Constant'
   *  Inport: '<Root>/<vel>'
   */
  if (rtU.vel[2] >= 1.4) {
    /* Saturate: '<S12>/Min Torque' incorporates:
     *  Gain: '<S12>/Gain4'
     *  Switch: '<S14>/Switch2'
     */
    if (-0.0 * rtb_Switch1_f[0] > -0.01) {
      rtb_Switch1_idx_0 = -0.01;
    } else {
      rtb_Switch1_idx_0 = (rtNaN);
    }

    if (-0.0 * rtb_Switch1_f[1] > -0.01) {
      rtb_Switch1_idx_1 = -0.01;
    } else {
      rtb_Switch1_idx_1 = (rtNaN);
    }

    if (-rtb_Switch1_f[2] > -0.01) {
      rtb_Switch1_idx_2 = -0.01;
    } else if (-rtb_Switch1_f[2] < -0.01) {
      rtb_Switch1_idx_2 = -0.01;
    } else {
      rtb_Switch1_idx_2 = -rtb_Switch1_f[2];
    }

    if (-rtb_Gain1_by > -0.01) {
      rtb_Switch1_idx_3 = -0.01;
    } else if (-rtb_Gain1_by < -0.01) {
      rtb_Switch1_idx_3 = -0.01;
    } else {
      rtb_Switch1_idx_3 = -rtb_Gain1_by;
    }

    /* End of Saturate: '<S12>/Min Torque' */
  } else {
    rtb_Switch1_idx_0 = 0.0;
    rtb_Switch1_idx_1 = 0.0;
    rtb_Switch1_idx_2 = 0.0;
    rtb_Switch1_idx_3 = 0.0;
  }

  /* End of Switch: '<S12>/Switch1' */

  /* DeadZone: '<S7>/Dead Zone' incorporates:
   *  Inport: '<Root>/<steering_angle>'
   */
  if (rtU.theta > rtP.deadband_angle) {
    rtb_TFR = rtU.theta - rtP.deadband_angle;
  } else if (rtU.theta >= -rtP.deadband_angle) {
    rtb_TFR = 0.0;
  } else {
    rtb_TFR = rtU.theta - (-rtP.deadband_angle);
  }

  /* End of DeadZone: '<S7>/Dead Zone' */

  /* Gain: '<S7>/Gain' */
  rtb_TFR *= 0.28194;

  /* Math: '<S18>/Square1' */
  rtb_Square1 = rtb_TFR * rtb_TFR;

  /* Product: '<S18>/Product' */
  rtb_Square1_p = rtb_Square1 * rtb_TFR;

  /* Gain: '<S18>/Gain' */
  rtb_TFL = 7.0E-5 * rtb_Square1_p;

  /* Math: '<S18>/Square' */
  rtb_Square1 = rtb_TFR * rtb_TFR;

  /* Gain: '<S18>/Gain2' */
  rtb_b_b = 0.6535 * rtb_TFR;

  /* Sum: '<S18>/Sum of Elements' incorporates:
   *  Gain: '<S18>/Gain1'
   */
  rtb_Gain6[0] = rtb_TFL;
  rtb_TFL = -0.0;
  rtb_TFL += rtb_Gain6[0];
  rtb_TFL += 0.0038 * rtb_Square1;
  rtb_TFL += rtb_b_b;
  rtb_TFL += -0.1061;

  /* Math: '<S19>/Square1' */
  rtb_Square1 = rtb_TFR * rtb_TFR;

  /* Product: '<S19>/Product' */
  rtb_Square1_p = rtb_Square1 * rtb_TFR;

  /* Math: '<S19>/Square' */
  rtb_Square1 = rtb_TFR * rtb_TFR;

  /* Gain: '<S19>/Gain2' */
  rtb_TFR *= 0.6535;

  /* Sum: '<S19>/Sum of Elements' */
  rtb_Gain6[2] = rtb_TFR;

  /* SignalConversion generated from: '<S7>/Mean' */
  rtb_Abs_j_idx_0 = rtb_TFL;

  /* Sum: '<S19>/Sum of Elements' incorporates:
   *  Gain: '<S19>/Gain'
   *  Gain: '<S19>/Gain1'
   */
  rtb_DotProduct1 = ((7.0E-5 * rtb_Square1_p + -0.0038 * rtb_Square1) +
                     rtb_Gain6[2]) + 0.1061;

  /* S-Function (sdspstatfcns): '<S7>/Mean' */
  rtb_TFR = rtb_Abs_j_idx_0;
  rtb_TFR += rtb_DotProduct1;
  rtb_b_b = rtb_TFR / 2.0;

  /* S-Function (sdspstatfcns): '<S13>/Mean' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtb_Square1 = (((rtb_UnitDelay[0] + rtb_UnitDelay[1]) + rtb_UnitDelay[2]) +
                 rtb_UnitDelay[3]) / 4.0;

  /* Product: '<S13>/Divide' */
  rtb_TFR = rtb_Square1 / 2.0;

  /* Gain: '<S13>/Gain' */
  rtb_Gain_idx_0 = 0.0 * rtb_TFR;
  rtb_Gain_idx_1 = 0.0 * rtb_TFR;
  rtb_Gain_idx_2 = rtb_TFR;
  rtb_Gain_idx_3 = rtb_TFR;

  /* Sum: '<S13>/Add' incorporates:
   *  Gain: '<S13>/Gain'
   *  Gain: '<S13>/Gain2'
   */
  rtb_Add_idx_0 = 0.0 * rtb_Square1 + rtb_Gain_idx_0;

  /* Gain: '<S12>/Gain8' incorporates:
   *  Switch: '<S14>/Switch2'
   */
  rtb_Square1_p = 0.0 * rtb_Switch1_f[0];

  /* Saturate: '<S12>/Max Torque' incorporates:
   *  Gain: '<S12>/Gain8'
   *  Switch: '<S14>/Switch2'
   */
  if (0.0 * rtb_Switch1_f[0] < 0.01) {
    y = 0.01;
  } else {
    y = (rtNaN);
  }

  /* Sum: '<S13>/Add' incorporates:
   *  Gain: '<S13>/Gain'
   *  Gain: '<S13>/Gain2'
   */
  rtb_Add_idx_1 = 0.0 * rtb_Square1 + rtb_Gain_idx_1;

  /* Gain: '<S12>/Gain8' incorporates:
   *  Switch: '<S14>/Switch2'
   */
  u0 = 0.0 * rtb_Switch1_f[1];

  /* Saturate: '<S12>/Max Torque' incorporates:
   *  Gain: '<S12>/Gain8'
   *  Switch: '<S14>/Switch2'
   */
  if (0.0 * rtb_Switch1_f[1] < 0.01) {
    y_0 = 0.01;
  } else {
    y_0 = (rtNaN);
  }

  /* Sum: '<S13>/Add' incorporates:
   *  Gain: '<S13>/Gain'
   *  Gain: '<S13>/Gain2'
   */
  rtb_Add_idx_2 = rtb_Square1 + rtb_Gain_idx_2;

  /* Saturate: '<S12>/Max Torque' incorporates:
   *  Gain: '<S12>/Gain8'
   *  Switch: '<S14>/Switch2'
   */
  if (rtb_Switch1_f[2] > 25.0) {
    y_1 = 25.0;
    rtb_UnitDelay[2] = 25.0;
  } else {
    if (rtb_Switch1_f[2] < 0.01) {
      y_1 = 0.01;
    } else {
      y_1 = rtb_Switch1_f[2];
    }

    if (rtb_Switch1_f[2] < 0.01) {
      rtb_UnitDelay[2] = 0.01;
    } else {
      rtb_UnitDelay[2] = rtb_Switch1_f[2];
    }
  }

  /* Sum: '<S13>/Add' incorporates:
   *  Gain: '<S13>/Gain'
   *  Gain: '<S13>/Gain2'
   */
  rtb_Add_idx_3 = rtb_Square1 + rtb_Gain_idx_3;

  /* Saturate: '<S12>/Max Torque' */
  if (rtb_Gain1_by > 25.0) {
    rtb_UnitDelay[3] = 25.0;
  } else if (rtb_Gain1_by < 0.01) {
    rtb_UnitDelay[3] = 0.01;
  } else {
    rtb_UnitDelay[3] = rtb_Gain1_by;
  }

  /* Gain: '<S7>/Gain1' */
  rtb_Square1 = 0.01745329 * rtb_Abs_j_idx_0;

  /* Gain: '<S9>/Gain' incorporates:
   *  Abs: '<S9>/Abs'
   */
  rtb_TFR = 0.15915494309189535 * fabs(rtb_Square1);

  /* Trigonometry: '<S9>/Cos' */
  rtb_TFL = cos(rtb_TFR);

  /* Signum: '<S9>/Sign' */
  if (!rtIsNaN(rtb_Square1)) {
    if (rtb_Square1 < 0.0) {
      rtb_Square1 = -1.0;
    } else {
      rtb_Square1 = (rtb_Square1 > 0.0);
    }
  }

  /* Gain: '<S7>/Gain1' incorporates:
   *  Product: '<S9>/Product1'
   *  Sum: '<S19>/Sum of Elements'
   *  Trigonometry: '<S9>/Sin'
   */
  rtb_Abs_j_idx_0 = sin(rtb_TFR) * rtb_Square1;
  rtb_Square1 = 0.01745329 * rtb_DotProduct1;

  /* Gain: '<S9>/Gain' incorporates:
   *  Abs: '<S9>/Abs'
   */
  rtb_TFR = 0.15915494309189535 * fabs(rtb_Square1);

  /* DotProduct: '<S9>/Dot Product1' incorporates:
   *  Constant: '<S9>/Constant5'
   *  SignalConversion generated from: '<S9>/Dot Product1'
   */
  rtb_DotProduct1 = rtb_TFL * 0.647895 + rtb_Abs_j_idx_0 * 0.7922471;

  /* Signum: '<S9>/Sign' */
  if (!rtIsNaN(rtb_Square1)) {
    if (rtb_Square1 < 0.0) {
      rtb_Square1 = -1.0;
    } else {
      rtb_Square1 = (rtb_Square1 > 0.0);
    }
  }

  /* DotProduct: '<S9>/Dot Product2' incorporates:
   *  Constant: '<S9>/Constant6'
   *  Product: '<S9>/Product1'
   *  Trigonometry: '<S9>/Cos'
   *  Trigonometry: '<S9>/Sin'
   */
  rtb_Abs_j_idx_0 = sin(rtb_TFR) * rtb_Square1 * 0.7922471 + cos(rtb_TFR) *
    -0.647895;

  /* Lookup_n-D: '<S6>/1-D Lookup Table' incorporates:
   *  Inport: '<Root>/<vel>'
   */
  bpIdx = plook_evenc(rtU.vel[2], 0.0, 3.0, 9U, &rtb_Square1);

  /* Math: '<S6>/Square' incorporates:
   *  Inport: '<Root>/<vel>'
   */
  rtb_TFL = rtU.vel[2] * rtU.vel[2];

  /* Gain: '<S6>/Gain1' */
  rtb_TFR = rtP.Ku * rtb_TFL;

  /* Sum: '<S6>/Sum' incorporates:
   *  Constant: '<S6>/Constant1'
   */
  rtb_TFL = rtb_TFR + 0.63488032505872649;

  /* Product: '<S6>/Divide1' incorporates:
   *  Gain: '<S7>/Gain2'
   *  Inport: '<Root>/<vel>'
   */
  rtb_TFL = rtU.vel[2] * rtb_TFL * (0.01745329 * rtb_b_b);

  /* Abs: '<S6>/Abs' */
  rtb_b_b = fabs(rtb_TFL);

  /* MinMax: '<S6>/Min of Elements' incorporates:
   *  Abs: '<S6>/Abs'
   *  Gain: '<S6>/Gain2'
   *  Lookup_n-D: '<S6>/1-D Lookup Table'
   */
  rtb_TFR = fabs(rtP.Kv * intrp1d_l(bpIdx, rtb_Square1,
    rtConstP.uDLookupTable_tableData_n));
  rtb_TFR = fmin(rtb_TFR, rtb_b_b);

  /* Signum: '<S6>/Sign' */
  if (rtIsNaN(rtb_TFL)) {
  } else if (rtb_TFL < 0.0) {
    rtb_TFL = -1.0;
  } else {
    rtb_TFL = (rtb_TFL > 0.0);
  }

  /* End of Signum: '<S6>/Sign' */

  /* Product: '<S6>/Product' incorporates:
   *  MinMax: '<S6>/Min of Elements'
   */
  rtb_b_b = rtb_TFR * rtb_TFL;

  /* Switch: '<S13>/Switch1' incorporates:
   *  Constant: '<S13>/Constant'
   *  Constant: '<S9>/Constant3'
   *  Constant: '<S9>/Constant4'
   *  Gain: '<S13>/Gain7'
   *  Product: '<S13>/Product1'
   *  Switch: '<S15>/Switch'
   */
  if (rtb_b_b != 0.0) {
    rtb_Switch1_f[0] = rtb_DotProduct1 * rtb_Add_idx_0 * 0.38765914066666662;
    rtb_Switch1_f[1] = rtb_Abs_j_idx_0 * rtb_Gain_idx_1 * 0.38765914066666662;

    /* Switch: '<S15>/Switch2' incorporates:
     *  Gain: '<S13>/Gain7'
     *  Product: '<S13>/Product1'
     *  RelationalOperator: '<S15>/LowerRelop1'
     *  RelationalOperator: '<S15>/UpperRelop'
     *  Saturate: '<S12>/Max Torque'
     *  Switch: '<S12>/Switch1'
     *  Switch: '<S13>/Switch1'
     *  Switch: '<S15>/Switch'
     */
    if (rtb_Add_idx_2 > rtb_UnitDelay[2]) {
      rtb_Add_idx_2 = rtb_UnitDelay[2];
    } else if (rtb_Add_idx_2 < rtb_Switch1_idx_2) {
      rtb_Add_idx_2 = rtb_Switch1_idx_2;
    }

    rtb_Switch1_f[2] = 0.62102 * rtb_Add_idx_2 * 0.387634;

    /* Switch: '<S15>/Switch2' incorporates:
     *  Constant: '<S9>/Constant3'
     *  Gain: '<S13>/Gain7'
     *  Product: '<S13>/Product1'
     *  RelationalOperator: '<S15>/LowerRelop1'
     *  RelationalOperator: '<S15>/UpperRelop'
     *  Saturate: '<S12>/Max Torque'
     *  Switch: '<S12>/Switch1'
     *  Switch: '<S13>/Switch1'
     *  Switch: '<S15>/Switch'
     */
    if (rtb_Gain_idx_3 > rtb_UnitDelay[3]) {
      rtb_Gain_idx_3 = rtb_UnitDelay[3];
    } else if (rtb_Gain_idx_3 < rtb_Switch1_idx_3) {
      /* Switch: '<S15>/Switch' incorporates:
       *  Switch: '<S12>/Switch1'
       */
      rtb_Gain_idx_3 = rtb_Switch1_idx_3;
    }

    rtb_Switch1_f[3] = -0.62102 * rtb_Gain_idx_3 * 0.387634;
  } else {
    rtb_Switch1_f[0] = 0.0;
    rtb_Switch1_f[1] = 0.0;
    rtb_Switch1_f[2] = 0.0;
    rtb_Switch1_f[3] = 0.0;
  }

  /* End of Switch: '<S13>/Switch1' */

  /* Gain: '<S13>/Gain6' */
  rtb_Gain6[0] = 0.38765914066666662 * rtb_DotProduct1;
  rtb_Gain6[1] = 0.38765914066666662 * rtb_Abs_j_idx_0;

  /* Gain: '<S10>/Gain5' incorporates:
   *  DeadZone: '<S4>/Tx_deadband'
   *  Gain: '<S10>/Gain1'
   */
  rtb_Tx_deadband_idx_0 = 0.95 * rtb_Gain1[0];
  rtb_Gain_idx_1 = 0.95 * rtb_Gain1[1];
  rtb_Gain_idx_3 = 0.95 * rtb_Gain1[2];
  rtb_Add_idx_0 = 0.95 * rtb_Gain1[3];

  /* DotProduct: '<S10>/Dot Product' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/Constant1'
   *  Gain: '<S10>/Gain1'
   *  Gain: '<S10>/Gain5'
   *  MinMax: '<S10>/Min2'
   */
  rtb_TFR = ((0.0 * fmax(rtb_Gain1[0], 0.1) + 0.0 * fmax(rtb_Gain1[1], 0.1)) +
             26.315789473684212 * fmax(rtb_Gain1[2], 0.1)) + 26.315789473684212 *
    fmax(rtb_Gain1[3], 0.1);

  /* Switch: '<S10>/Switch' incorporates:
   *  Inport: '<Root>/<driver_input>'
   *  Product: '<S10>/Product'
   *  Product: '<S10>/Product1'
   */
  if (rtU.driver_input > 0.0) {
    /* MinMax: '<S10>/Min' incorporates:
     *  Inport: '<Root>/<power_limits>'
     *  SignalConversion generated from: '<S1>/<power_limits>'
     */
    rtb_Square1 = fmin(rtU.pwr_lmt[0], rtb_TFR);

    /* Saturate: '<S10>/Discharge Limits' */
    if (rtb_Square1 > 75000.0) {
      rtb_Square1 = 75000.0;
    } else if (rtb_Square1 < 0.0) {
      rtb_Square1 = 0.0;
    }

    /* End of Saturate: '<S10>/Discharge Limits' */
    rtb_Add_idx_2 = rtb_Square1 * rtU.driver_input;
  } else {
    /* MinMax: '<S10>/Min1' incorporates:
     *  Inport: '<Root>/<power_limits>'
     *  SignalConversion generated from: '<S1>/<power_limits>'
     */
    rtb_Square1 = fmin(rtb_TFR, rtU.pwr_lmt[1]);

    /* Saturate: '<S10>/Charge Limits' */
    if (rtb_Square1 > 0.0) {
      rtb_Square1 = 0.0;
    } else if (rtb_Square1 < 0.0) {
      rtb_Square1 = 0.0;
    }

    /* End of Saturate: '<S10>/Charge Limits' */
    rtb_Add_idx_2 = rtU.driver_input * rtb_Square1;
  }

  /* End of Switch: '<S10>/Switch' */

  /* Sum: '<S13>/Sum1' incorporates:
   *  Switch: '<S13>/Switch1'
   */
  rtb_Square1 = ((rtb_Switch1_f[0] + rtb_Switch1_f[1]) + rtb_Switch1_f[2]) +
    rtb_Switch1_f[3];

  /* UnitDelay: '<S13>/Unit Delay4' */
  rtb_UnitDelay4 = rtDW.UnitDelay4_DSTATE;

  /* UnitDelay: '<S13>/Unit Delay' */
  rtb_UnitDelay_g = rtDW.UnitDelay_DSTATE_f;

  /* Sum: '<S5>/Sum1' incorporates:
   *  Inport: '<Root>/<yaw>'
   */
  rtb_TFL = rtb_b_b - rtU.yaw;

  /* Product: '<S5>/Product' incorporates:
   *  UnitDelay: '<S13>/Unit Delay'
   */
  rtb_TFR = (real_T)rtDW.UnitDelay_DSTATE_f * rtb_TFL;

  /* Gain: '<S5>/I' */
  rtb_TFR *= rtP.I;

  /* DiscreteIntegrator: '<S5>/Discrete-Time Integrator' incorporates:
   *  UnitDelay: '<S13>/Unit Delay4'
   */
  if (rtDW.UnitDelay4_DSTATE || (rtDW.DiscreteTimeIntegrator_PrevRese != 0)) {
    rtDW.DiscreteTimeIntegrator_DSTATE = 0.0;
  }

  /* DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
  I_control = 0.015 * rtb_TFR + rtDW.DiscreteTimeIntegrator_DSTATE;

  /* DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
  if (I_control >= 1.0) {
    /* DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
    I_control = 1.0;
  } else if (I_control <= -1.0) {
    /* DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
    I_control = -1.0;
  }

  /* Saturate: '<S5>/Saturation' */
  if (rtb_TFL > 2.5) {
    rtb_TFL = 2.5;
  } else if (rtb_TFL < -2.5) {
    rtb_TFL = -2.5;
  }

  /* End of Saturate: '<S5>/Saturation' */

  /* Gain: '<S5>/P' */
  rtb_TFR = rtP.P * rtb_TFL;

  /* Sum: '<S5>/Sum7' */
  rtb_TFR += I_control;

  /* Switch: '<S17>/Switch2' incorporates:
   *  RelationalOperator: '<S17>/LowerRelop1'
   */
  if (!(rtb_TFR > rtb_Square1)) {
    /* Switch: '<S13>/Switch2' incorporates:
     *  Constant: '<S13>/Constant'
     *  Constant: '<S9>/Constant3'
     *  Constant: '<S9>/Constant4'
     *  Gain: '<S13>/Gain1'
     *  Product: '<S13>/Product2'
     *  Switch: '<S16>/Switch'
     */
    if (rtb_b_b != 0.0) {
      rtb_Switch1_f[0] = rtb_DotProduct1 * rtb_Gain_idx_0 * 0.38765914066666662;
      rtb_Switch1_f[1] = rtb_Abs_j_idx_0 * rtb_Add_idx_1 * 0.38765914066666662;

      /* Switch: '<S16>/Switch2' incorporates:
       *  Gain: '<S13>/Gain1'
       *  Product: '<S13>/Product2'
       *  RelationalOperator: '<S16>/LowerRelop1'
       *  RelationalOperator: '<S16>/UpperRelop'
       *  Saturate: '<S12>/Max Torque'
       *  Switch: '<S12>/Switch1'
       *  Switch: '<S13>/Switch2'
       *  Switch: '<S16>/Switch'
       */
      if (rtb_Gain_idx_2 > rtb_UnitDelay[2]) {
        rtb_Gain_idx_2 = rtb_UnitDelay[2];
      } else if (rtb_Gain_idx_2 < rtb_Switch1_idx_2) {
        rtb_Gain_idx_2 = rtb_Switch1_idx_2;
      }

      rtb_Switch1_f[2] = 0.62102 * rtb_Gain_idx_2 * 0.387634;

      /* Switch: '<S16>/Switch2' incorporates:
       *  Constant: '<S9>/Constant3'
       *  Gain: '<S13>/Gain1'
       *  Product: '<S13>/Product2'
       *  RelationalOperator: '<S16>/LowerRelop1'
       *  RelationalOperator: '<S16>/UpperRelop'
       *  Saturate: '<S12>/Max Torque'
       *  Switch: '<S12>/Switch1'
       *  Switch: '<S13>/Switch2'
       *  Switch: '<S16>/Switch'
       */
      if (rtb_Add_idx_3 > rtb_UnitDelay[3]) {
        rtb_Add_idx_3 = rtb_UnitDelay[3];
      } else if (rtb_Add_idx_3 < rtb_Switch1_idx_3) {
        /* Switch: '<S16>/Switch' incorporates:
         *  Switch: '<S12>/Switch1'
         */
        rtb_Add_idx_3 = rtb_Switch1_idx_3;
      }

      rtb_Switch1_f[3] = -0.62102 * rtb_Add_idx_3 * 0.387634;
    } else {
      rtb_Switch1_f[0] = 0.0;
      rtb_Switch1_f[1] = 0.0;
      rtb_Switch1_f[2] = 0.0;
      rtb_Switch1_f[3] = 0.0;
    }

    /* End of Switch: '<S13>/Switch2' */

    /* Sum: '<S13>/Sum2' incorporates:
     *  Switch: '<S13>/Switch2'
     */
    rtb_Gain_idx_2 = ((rtb_Switch1_f[0] + rtb_Switch1_f[1]) + rtb_Switch1_f[2])
      + rtb_Switch1_f[3];

    /* Switch: '<S17>/Switch' incorporates:
     *  RelationalOperator: '<S17>/UpperRelop'
     */
    if (rtb_TFR < rtb_Gain_idx_2) {
      rtb_Square1 = rtb_Gain_idx_2;
    } else {
      rtb_Square1 = rtb_TFR;
    }

    /* End of Switch: '<S17>/Switch' */
  }

  /* End of Switch: '<S17>/Switch2' */

  /* Abs: '<S13>/Abs3' incorporates:
   *  Abs: '<S13>/Abs1'
   */
  rtb_Gain_idx_0 = fabs(rtb_Square1);

  /* Switch: '<S13>/Switch' incorporates:
   *  Abs: '<S13>/Abs3'
   *  Constant: '<S13>/Constant4'
   *  Constant: '<S13>/Constant5'
   *  Constant: '<S13>/Constant6'
   *  RelationalOperator: '<S13>/Equal'
   */
  if (rtb_Gain_idx_0 < 0.01) {
    rtb_DotProduct1 = 0.0001;
  } else {
    rtb_DotProduct1 = 0.0;
  }

  /* End of Switch: '<S13>/Switch' */

  /* Sum: '<S13>/Sum3' */
  rtb_Gain_idx_2 = rtb_Square1 + rtb_DotProduct1;

  /* CCaller: '<S4>/C Caller' incorporates:
   *  Constant: '<S4>/Tx_initial'
   */
  rtb_TFL = 0.0;
  rtb_TFR = 0.0;
  rtb_Abs_j_idx_0 = 0.0;
  rtb_DotProduct1 = 0.0;

  /* Saturate: '<S12>/Max Torque' */
  if (rtb_Square1_p < 0.01) {
    rtb_Square1_p = 0.01;
  } else {
    rtb_Square1_p = (rtNaN);
  }

  if (u0 < 0.01) {
    u0 = 0.01;
  } else {
    u0 = (rtNaN);
  }

  /* CCaller: '<S4>/C Caller' incorporates:
   *  Bias: '<S4>/lb_offset'
   *  Bias: '<S4>/ub_offset'
   *  Constant: '<S4>/optimization_offset_A'
   *  Constant: '<S4>/optimization_offset_Aeq'
   *  Constant: '<S4>/yaw_error_limit'
   *  Constant: '<S8>/Constant3'
   *  DeadZone: '<S4>/Tx_deadband'
   *  DotProduct: '<S4>/A Dot'
   *  DotProduct: '<S4>/Aeq Dot'
   *  Saturate: '<S12>/Max Torque'
   *  Sum: '<S4>/b Add'
   *  Sum: '<S4>/beq Add'
   *  Switch: '<S12>/Switch1'
   */
  rtb_exitflag = bigM_func(29.074435549999997, 29.074435549999997, 29.07255,
    29.07255, (((25.0 * rtb_Tx_deadband_idx_0 + 25.0 * rtb_Gain_idx_1) + 25.0 *
                rtb_Gain_idx_3) + 25.0 * rtb_Add_idx_0) + rtb_Add_idx_2,
    rtb_Tx_deadband_idx_0, rtb_Gain_idx_1, rtb_Gain_idx_3, rtb_Add_idx_0,
    (((25.0 * rtb_Gain6[0] + 25.0 * rtb_Gain6[1]) + 6.018211667) + -6.018211667)
    + rtb_Gain_idx_2, rtb_Gain6[0], rtb_Gain6[1], 0.24072846668, -0.24072846668,
    rtb_Switch1_idx_0 + 25.0, rtb_Switch1_idx_1 + 25.0, rtb_Switch1_idx_2 + 25.0,
    rtb_Switch1_idx_3 + 25.0, rtb_Square1_p + 25.0, u0 + 25.0, rtb_UnitDelay[2]
    + 25.0, rtb_UnitDelay[3] + 25.0, &rtb_TFL, &rtb_TFR, &rtb_Abs_j_idx_0,
    &rtb_DotProduct1, 0.2);

  /* Switch: '<S4>/Tx_choose' incorporates:
   *  Bias: '<S4>/Tx_equal_offset'
   *  Gain: '<S4>/Tx_equal_gain'
   *  Inport: '<Root>/<driver_input>'
   */
  if (rtb_exitflag > 2) {
    rtb_Tx_deadband_idx_0 = rtb_TFL;
    rtb_Gain_idx_1 = rtb_TFR;
    rtb_Gain_idx_3 = rtb_Abs_j_idx_0;
    rtb_Add_idx_0 = rtb_DotProduct1;
  } else {
    /* Bias: '<S4>/Tx_equal_offset' incorporates:
     *  Gain: '<S4>/Tx_equal_gain'
     *  Inport: '<Root>/<driver_input>'
     */
    rtb_Tx_deadband_idx_0 = 0.0 * rtU.driver_input + 25.0;
    rtb_Gain_idx_1 = rtb_Tx_deadband_idx_0;
    rtb_Gain_idx_3 = 25.0 * rtU.driver_input + 25.0;
    rtb_Add_idx_0 = 25.0 * rtU.driver_input + 25.0;
  }

  /* End of Switch: '<S4>/Tx_choose' */

  /* DeadZone: '<S4>/Tx_deadband' incorporates:
   *  Bias: '<S4>/Tx_reverse_offset'
   */
  if (rtb_Tx_deadband_idx_0 + -25.0 > 0.02) {
    u0 = (rtb_Tx_deadband_idx_0 + -25.0) - 0.02;
  } else if (rtb_Tx_deadband_idx_0 + -25.0 >= -0.02) {
    u0 = 0.0;
  } else {
    u0 = (rtb_Tx_deadband_idx_0 + -25.0) - -0.02;
  }

  /* RateLimiter: '<S4>/Tx_rate_limit' */
  rtb_Square1_p = u0 - rtDW.PrevY[0];
  if (rtb_Square1_p > 1.875) {
    rtb_Square1_p = rtDW.PrevY[0] + 1.875;
  } else if (rtb_Square1_p < -4.5) {
    rtb_Square1_p = rtDW.PrevY[0] + -4.5;
  } else {
    rtb_Square1_p = u0;
  }

  rtDW.PrevY[0] = rtb_Square1_p;
  rtb_Switch1_f[0] = rtb_Square1_p;

  /* DeadZone: '<S4>/Tx_deadband' incorporates:
   *  Bias: '<S4>/Tx_reverse_offset'
   */
  if (rtb_Gain_idx_1 + -25.0 > 0.02) {
    u0 = (rtb_Gain_idx_1 + -25.0) - 0.02;
  } else if (rtb_Gain_idx_1 + -25.0 >= -0.02) {
    u0 = 0.0;
  } else {
    u0 = (rtb_Gain_idx_1 + -25.0) - -0.02;
  }

  /* RateLimiter: '<S4>/Tx_rate_limit' */
  rtb_Square1_p = u0 - rtDW.PrevY[1];
  if (rtb_Square1_p > 1.875) {
    rtb_Square1_p = rtDW.PrevY[1] + 1.875;
  } else if (rtb_Square1_p < -4.5) {
    rtb_Square1_p = rtDW.PrevY[1] + -4.5;
  } else {
    rtb_Square1_p = u0;
  }

  rtDW.PrevY[1] = rtb_Square1_p;
  rtb_Switch1_f[1] = rtb_Square1_p;

  /* DeadZone: '<S4>/Tx_deadband' incorporates:
   *  Bias: '<S4>/Tx_reverse_offset'
   */
  if (rtb_Gain_idx_3 + -25.0 > 0.02) {
    u0 = (rtb_Gain_idx_3 + -25.0) - 0.02;
  } else if (rtb_Gain_idx_3 + -25.0 >= -0.02) {
    u0 = 0.0;
  } else {
    u0 = (rtb_Gain_idx_3 + -25.0) - -0.02;
  }

  /* RateLimiter: '<S4>/Tx_rate_limit' */
  rtb_Square1_p = u0 - rtDW.PrevY[2];
  if (rtb_Square1_p > 1.875) {
    rtb_Square1_p = rtDW.PrevY[2] + 1.875;
  } else if (rtb_Square1_p < -4.5) {
    rtb_Square1_p = rtDW.PrevY[2] + -4.5;
  } else {
    rtb_Square1_p = u0;
  }

  rtDW.PrevY[2] = rtb_Square1_p;
  rtb_Switch1_f[2] = rtb_Square1_p;

  /* DeadZone: '<S4>/Tx_deadband' incorporates:
   *  Bias: '<S4>/Tx_reverse_offset'
   */
  if (rtb_Add_idx_0 + -25.0 > 0.02) {
    u0 = (rtb_Add_idx_0 + -25.0) - 0.02;
  } else if (rtb_Add_idx_0 + -25.0 >= -0.02) {
    u0 = 0.0;
  } else {
    u0 = (rtb_Add_idx_0 + -25.0) - -0.02;
  }

  /* RateLimiter: '<S4>/Tx_rate_limit' */
  rtb_Square1_p = u0 - rtDW.PrevY[3];
  if (rtb_Square1_p > 1.875) {
    rtb_Square1_p = rtDW.PrevY[3] + 1.875;
  } else if (rtb_Square1_p < -4.5) {
    rtb_Square1_p = rtDW.PrevY[3] + -4.5;
  } else {
    rtb_Square1_p = u0;
  }

  rtDW.PrevY[3] = rtb_Square1_p;

  /* Abs: '<S13>/Abs1' incorporates:
   *  Abs: '<S13>/Abs2'
   */
  rtb_Abs_j_idx_0 = rtb_Gain_idx_0;
  rtb_DotProduct1 = rtb_Abs_j_idx_0;

  /* Update for UnitDelay: '<S13>/Unit Delay' incorporates:
   *  RelationalOperator: '<S13>/GreaterThanOrEqual'
   */
  rtDW.UnitDelay_DSTATE_f = (rtb_DotProduct1 < rtb_Abs_j_idx_0);

  /* UnitDelay: '<S13>/Unit Delay5' */
  rtb_DotProduct1 = rtDW.UnitDelay5_DSTATE;

  /* Signum: '<S13>/Sign2' */
  if (rtIsNaN(rtb_DotProduct1)) {
    rtb_TFR = rtb_DotProduct1;
  } else if (rtb_DotProduct1 < 0.0) {
    rtb_TFR = -1.0;
  } else {
    rtb_TFR = (rtb_DotProduct1 > 0.0);
  }

  /* End of Signum: '<S13>/Sign2' */

  /* Abs: '<S13>/Abs' */
  rtb_TFL = fabs(rtb_b_b);

  /* UnitDelay: '<S13>/Unit Delay1' */
  rtb_DotProduct1 = rtDW.UnitDelay1_DSTATE;

  /* RelationalOperator: '<S13>/GreaterThan1' incorporates:
   *  Constant: '<S13>/Constant1'
   */
  rtb_GreaterThan1 = (rtb_DotProduct1 > 0.05);

  /* Signum: '<S13>/Sign' */
  if (rtIsNaN(rtb_Add_idx_2)) {
    rtb_Gain_idx_0 = rtb_Add_idx_2;
  } else if (rtb_Add_idx_2 < 0.0) {
    rtb_Gain_idx_0 = -1.0;
  } else {
    rtb_Gain_idx_0 = (rtb_Add_idx_2 > 0.0);
  }

  /* End of Signum: '<S13>/Sign' */

  /* Update for UnitDelay: '<S13>/Unit Delay4' incorporates:
   *  Constant: '<S13>/Constant2'
   *  Logic: '<S13>/NOT1'
   *  Logic: '<S13>/NOT2'
   *  Logic: '<S13>/OR'
   *  RelationalOperator: '<S13>/Equal1'
   *  RelationalOperator: '<S13>/Equal2'
   *  RelationalOperator: '<S13>/GreaterThan'
   */
  rtDW.UnitDelay4_DSTATE = (((rtb_TFL > 0.05) != (int32_T)rtb_GreaterThan1) || (
    !(rtb_Gain_idx_0 == rtb_TFR)));

  /* Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE = I_control;
  rtDW.DiscreteTimeIntegrator_PrevRese = (int8_T)rtb_UnitDelay4;

  /* Update for UnitDelay: '<S13>/Unit Delay5' */
  rtDW.UnitDelay5_DSTATE = rtb_Add_idx_2;

  /* Update for UnitDelay: '<S13>/Unit Delay1' */
  rtDW.UnitDelay1_DSTATE = rtb_TFL;

  /* End of Outputs for SubSystem: '<S1>/Torque Vectoring Micro Controller' */

  /* Update for UnitDelay: '<S1>/Unit Delay' incorporates:
   *  RateLimiter: '<S4>/Tx_rate_limit'
   */
  rtDW.UnitDelay_DSTATE[0] = rtb_Switch1_f[0];

  /* Outputs for Atomic SubSystem: '<S1>/Torque Vectoring Micro Controller' */
  /* Outport: '<Root>/ub' incorporates:
   *  Saturate: '<S12>/Max Torque'
   */
  rtY.ub[0] = y;

  /* End of Outputs for SubSystem: '<S1>/Torque Vectoring Micro Controller' */
  /* End of Outputs for SubSystem: '<Root>/TVS' */

  /* Outport: '<Root>/lb' */
  rtY.lb[0] = rtb_Switch1_idx_0;

  /* Outport: '<Root>/omega_m_TV' */
  rtY.omega_m_TV[0] = rtb_Gain1[0];

  /* Outputs for Atomic SubSystem: '<Root>/TVS' */
  /* Outport: '<Root>/motor_I' incorporates:
   *  Inport: '<Root>/<motor_current>'
   *  SignalConversion generated from: '<S1>/<motor_current>'
   */
  rtY.motor_I[0] = rtU.motor_I[0];

  /* End of Outputs for SubSystem: '<Root>/TVS' */

  /* Outport: '<Root>/motor_T' */
  rtY.motor_T[0] = rtb_motor_temp_idx_0;

  /* Outputs for Atomic SubSystem: '<Root>/TVS' */
  /* Outport: '<Root>/motor_V' incorporates:
   *  Inport: '<Root>/<motor_voltage>'
   *  SignalConversion generated from: '<S1>/<motor_voltage>'
   */
  rtY.motor_V[0] = rtU.motor_V[0];

  /* Outport: '<Root>/Tx' incorporates:
   *  RateLimiter: '<S4>/Tx_rate_limit'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtY.Tx[0] = rtb_Switch1_f[0];

  /* Update for UnitDelay: '<S1>/Unit Delay' incorporates:
   *  RateLimiter: '<S4>/Tx_rate_limit'
   */
  rtDW.UnitDelay_DSTATE[1] = rtb_Switch1_f[1];

  /* Outputs for Atomic SubSystem: '<S1>/Torque Vectoring Micro Controller' */
  /* Outport: '<Root>/ub' incorporates:
   *  Saturate: '<S12>/Max Torque'
   */
  rtY.ub[1] = y_0;

  /* End of Outputs for SubSystem: '<S1>/Torque Vectoring Micro Controller' */
  /* End of Outputs for SubSystem: '<Root>/TVS' */

  /* Outport: '<Root>/lb' */
  rtY.lb[1] = rtb_Switch1_idx_1;

  /* Outport: '<Root>/omega_m_TV' */
  rtY.omega_m_TV[1] = rtb_Gain1[1];

  /* Outputs for Atomic SubSystem: '<Root>/TVS' */
  /* Outport: '<Root>/motor_I' incorporates:
   *  Inport: '<Root>/<motor_current>'
   *  SignalConversion generated from: '<S1>/<motor_current>'
   */
  rtY.motor_I[1] = rtU.motor_I[1];

  /* End of Outputs for SubSystem: '<Root>/TVS' */

  /* Outport: '<Root>/motor_T' */
  rtY.motor_T[1] = rtb_motor_temp_idx_1;

  /* Outputs for Atomic SubSystem: '<Root>/TVS' */
  /* Outport: '<Root>/motor_V' incorporates:
   *  Inport: '<Root>/<motor_voltage>'
   *  SignalConversion generated from: '<S1>/<motor_voltage>'
   */
  rtY.motor_V[1] = rtU.motor_V[1];

  /* Outport: '<Root>/Tx' incorporates:
   *  RateLimiter: '<S4>/Tx_rate_limit'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtY.Tx[1] = rtb_Switch1_f[1];

  /* Update for UnitDelay: '<S1>/Unit Delay' incorporates:
   *  RateLimiter: '<S4>/Tx_rate_limit'
   */
  rtDW.UnitDelay_DSTATE[2] = rtb_Switch1_f[2];

  /* Outputs for Atomic SubSystem: '<S1>/Torque Vectoring Micro Controller' */
  /* Outport: '<Root>/ub' incorporates:
   *  Saturate: '<S12>/Max Torque'
   */
  rtY.ub[2] = y_1;

  /* End of Outputs for SubSystem: '<S1>/Torque Vectoring Micro Controller' */
  /* End of Outputs for SubSystem: '<Root>/TVS' */

  /* Outport: '<Root>/lb' */
  rtY.lb[2] = rtb_Switch1_idx_2;

  /* Outport: '<Root>/omega_m_TV' */
  rtY.omega_m_TV[2] = rtb_Gain1[2];

  /* Outputs for Atomic SubSystem: '<Root>/TVS' */
  /* Outport: '<Root>/motor_I' incorporates:
   *  Inport: '<Root>/<motor_current>'
   *  SignalConversion generated from: '<S1>/<motor_current>'
   */
  rtY.motor_I[2] = rtU.motor_I[2];

  /* End of Outputs for SubSystem: '<Root>/TVS' */

  /* Outport: '<Root>/motor_T' */
  rtY.motor_T[2] = rtb_motor_temp_idx_2;

  /* Outputs for Atomic SubSystem: '<Root>/TVS' */
  /* Outport: '<Root>/motor_V' incorporates:
   *  Inport: '<Root>/<motor_voltage>'
   *  SignalConversion generated from: '<S1>/<motor_voltage>'
   */
  rtY.motor_V[2] = rtU.motor_V[2];

  /* Outport: '<Root>/Tx' incorporates:
   *  RateLimiter: '<S4>/Tx_rate_limit'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtY.Tx[2] = rtb_Switch1_f[2];

  /* Update for UnitDelay: '<S1>/Unit Delay' */
  rtDW.UnitDelay_DSTATE[3] = rtb_Square1_p;

  /* Outputs for Atomic SubSystem: '<S1>/Torque Vectoring Micro Controller' */
  /* Saturate: '<S12>/Max Torque' */
  if (rtb_Gain1_by > 25.0) {
    /* Outport: '<Root>/ub' */
    rtY.ub[3] = 25.0;
  } else if (rtb_Gain1_by < 0.01) {
    /* Outport: '<Root>/ub' */
    rtY.ub[3] = 0.01;
  } else {
    /* Outport: '<Root>/ub' */
    rtY.ub[3] = rtb_Gain1_by;
  }

  /* End of Outputs for SubSystem: '<S1>/Torque Vectoring Micro Controller' */
  /* End of Outputs for SubSystem: '<Root>/TVS' */

  /* Outport: '<Root>/lb' */
  rtY.lb[3] = rtb_Switch1_idx_3;

  /* Outport: '<Root>/omega_m_TV' */
  rtY.omega_m_TV[3] = rtb_Gain1[3];

  /* Outputs for Atomic SubSystem: '<Root>/TVS' */
  /* Outport: '<Root>/motor_I' incorporates:
   *  Inport: '<Root>/<motor_current>'
   *  SignalConversion generated from: '<S1>/<motor_current>'
   */
  rtY.motor_I[3] = rtU.motor_I[3];

  /* End of Outputs for SubSystem: '<Root>/TVS' */

  /* Outport: '<Root>/motor_T' */
  rtY.motor_T[3] = rtb_motor_temp_idx_3;

  /* Outputs for Atomic SubSystem: '<Root>/TVS' */
  /* Outport: '<Root>/motor_V' incorporates:
   *  Inport: '<Root>/<motor_voltage>'
   *  SignalConversion generated from: '<S1>/<motor_voltage>'
   */
  rtY.motor_V[3] = rtU.motor_V[3];

  /* End of Outputs for SubSystem: '<Root>/TVS' */

  /* Outport: '<Root>/Tx' */
  rtY.Tx[3] = rtb_Square1_p;

  /* Outport: '<Root>/power_limits' */
  rtY.power_limits[0] = rtb_power_limits_idx_0;
  rtY.power_limits[1] = rtb_power_limits_idx_1;

  /* Outport: '<Root>/Control_Signal' */
  rtY.Control_Signal = rtb_Square1;

  /* Outport: '<Root>/windup' */
  rtY.windup = rtb_UnitDelay_g;

  /* Outport: '<Root>/reset' */
  rtY.reset = rtb_UnitDelay4;

  /* Outport: '<Root>/ref_yaw' */
  rtY.ref_yaw = rtb_b_b;

  /* Outport: '<Root>/b' */
  rtY.b = rtb_Add_idx_2;

  /* Outport: '<Root>/beq' */
  rtY.beq = rtb_Gain_idx_2;

  /* Outport: '<Root>/bigM_flag' */
  rtY.bigM_flag = rtb_exitflag;
}

/* Model initialize function */
void TVS_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* SystemInitialize for Atomic SubSystem: '<Root>/TVS' */
  /* SystemInitialize for Atomic SubSystem: '<S1>/Torque Vectoring Micro Controller' */
  /* InitializeConditions for UnitDelay: '<S13>/Unit Delay4' */
  rtDW.UnitDelay4_DSTATE = true;

  /* End of SystemInitialize for SubSystem: '<S1>/Torque Vectoring Micro Controller' */
  /* End of SystemInitialize for SubSystem: '<Root>/TVS' */

  /* ConstCode for Outport: '<Root>/obj_gain' incorporates:
   *  Constant: '<S8>/Constant3'
   */
  rtY.obj_gain[0] = 29.074435549999997;
  rtY.obj_gain[1] = 29.074435549999997;
  rtY.obj_gain[2] = 29.07255;
  rtY.obj_gain[3] = 29.07255;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
