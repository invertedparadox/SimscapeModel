/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Electronics.c
 *
 * Code generated for Simulink model 'Electronics'.
 *
 * Model version                  : 1.228
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Nov 15 21:53:05 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "Electronics.h"
#include "rtwtypes.h"
#include <math.h>
#include <stddef.h>
#define NumBitsPerChar                 8U

static real_T look1_binlg(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
static uint32_T plook_evenc(real_T u, real_T bp0, real_T bpSpace, uint32_T
  maxIndex, real_T *fraction);
static real_T intrp1d_l(uint32_T bpIndex, real_T frac, const real_T table[]);
static void Electronics_Init(DW_Electronics *localDW);
static void Electronics_o(const real_T rtu_TVS_Input[4], const real_T
  rtu_TVS_Input_j[4], const real_T rtu_TVS_Input_d[2], real_T rtu_TVS_Input_c,
  real_T rtu_TVS_Input_b, const real_T rtu_TVS_Input_i[3], const real_T
  rtu_TVS_Input_k[2], real_T rty_TVS_Output[4], int32_T *rty_TVS_Output_j,
  real_T *rty_TVS_Output_d, boolean_T *rty_TVS_Output_c, boolean_T
  *rty_TVS_Output_b, real_T *rty_TVS_Output_i, real_T rty_TVS_Output_k[4],
  real_T rty_TVS_Output_e[4], real_T *rty_TVS_Output_m, real_T
  *rty_TVS_Output_ba, DW_Electronics *localDW);
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

static real_T look1_binlg(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex)
{
  real_T yL_0d0;
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'on'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'on'
   */
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

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'wrapping'
   */
  yL_0d0 = table[iLeft];
  return (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]) * (table[iLeft + 1U]
    - yL_0d0) + yL_0d0;
}

static uint32_T plook_evenc(real_T u, real_T bp0, real_T bpSpace, uint32_T
  maxIndex, real_T *fraction)
{
  real_T fbpIndex;
  real_T invSpc;
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

/* System initialize for atomic system: '<Root>/Electronics' */
static void Electronics_Init(DW_Electronics *localDW)
{
  /* SystemInitialize for Atomic SubSystem: '<S1>/Fixed Point Sub' */
  /* SystemInitialize for Atomic SubSystem: '<S2>/Torque Vectoring Micro Controller' */
  /* InitializeConditions for UnitDelay: '<S17>/Unit Delay4' */
  localDW->UnitDelay4_DSTATE = true;

  /* End of SystemInitialize for SubSystem: '<S2>/Torque Vectoring Micro Controller' */
  /* End of SystemInitialize for SubSystem: '<S1>/Fixed Point Sub' */
}

/* Output and update for atomic system: '<Root>/Electronics' */
static void Electronics_o(const real_T rtu_TVS_Input[4], const real_T
  rtu_TVS_Input_j[4], const real_T rtu_TVS_Input_d[2], real_T rtu_TVS_Input_c,
  real_T rtu_TVS_Input_b, const real_T rtu_TVS_Input_i[3], const real_T
  rtu_TVS_Input_k[2], real_T rty_TVS_Output[4], int32_T *rty_TVS_Output_j,
  real_T *rty_TVS_Output_d, boolean_T *rty_TVS_Output_c, boolean_T
  *rty_TVS_Output_b, real_T *rty_TVS_Output_i, real_T rty_TVS_Output_k[4],
  real_T rty_TVS_Output_e[4], real_T *rty_TVS_Output_m, real_T
  *rty_TVS_Output_ba, DW_Electronics *localDW)
{
  real_T rtb_Abs_m_idx_0;
  real_T rtb_UnitDelay_g_idx_0;
  real_T rtb_UnitDelay_g_idx_1;
  real_T rtb_UnitDelay_g_idx_2;
  int32_T j;
  int32_T rtb_Abs1_tmp;
  int32_T rtb_Abs1_tmp_0;
  int32_T sigIdx;
  uint32_T bpIdx;
  boolean_T rtb_LessThan[4];
  boolean_T rtb_UpperRelop_n_idx_0;
  boolean_T rtb_UpperRelop_n_idx_1;
  boolean_T rtb_UpperRelop_n_idx_2;
  boolean_T rtb_UpperRelop_n_idx_3;

  /* Outputs for Atomic SubSystem: '<S1>/Fixed Point Sub' */
  /* Outputs for Atomic SubSystem: '<S2>/Torque Vectoring Micro Controller' */
  /* Sum: '<S12>/Subtract' */
  localDW->rtb_Gain1_idx_0 = rtu_TVS_Input[0] - rtu_TVS_Input[0];
  localDW->rtb_Gain1_idx_1 = rtu_TVS_Input[1] - rtu_TVS_Input[1];
  localDW->rtb_Gain1_idx_3 = rtu_TVS_Input[2] - rtu_TVS_Input[2];
  localDW->avg_steering_angle = rtu_TVS_Input[3] - rtu_TVS_Input[3];
  rty_TVS_Output[0] = localDW->rtb_Gain1_idx_0;
  rty_TVS_Output[1] = localDW->rtb_Gain1_idx_1;
  rty_TVS_Output[2] = localDW->rtb_Gain1_idx_3;
  rty_TVS_Output[3] = localDW->avg_steering_angle;

  /* Abs: '<S12>/Abs' */
  rty_TVS_Output[0] = fabs(rty_TVS_Output[0]);
  rty_TVS_Output[1] = fabs(rty_TVS_Output[1]);
  rty_TVS_Output[2] = fabs(rty_TVS_Output[2]);
  rty_TVS_Output[3] = fabs(rty_TVS_Output[3]);

  /* Switch: '<S12>/Switch' */
  localDW->rtb_Gain1_idx_0 = rtu_TVS_Input[0];
  localDW->rtb_Gain1_idx_1 = rtu_TVS_Input[1];
  localDW->rtb_Gain1_idx_3 = rtu_TVS_Input[2];
  localDW->avg_steering_angle = rtu_TVS_Input[3];
  rty_TVS_Output[0] = localDW->rtb_Gain1_idx_0;
  rty_TVS_Output[1] = localDW->rtb_Gain1_idx_1;
  rty_TVS_Output[2] = localDW->rtb_Gain1_idx_3;
  rty_TVS_Output[3] = localDW->avg_steering_angle;

  /* Gain: '<S14>/Gain1' */
  rty_TVS_Output[0] *= 6.63043;
  rty_TVS_Output[1] *= 6.63043;
  rty_TVS_Output[2] *= 6.63;
  rty_TVS_Output[3] *= 6.63;

  /* Gain: '<S15>/Gain' incorporates:
   *  Bias: '<S5>/Add Constant'
   */
  localDW->AddConstant[0] = 0.095492965964253843 * rty_TVS_Output[0];
  localDW->AddConstant[1] = 0.095492965964253843 * rty_TVS_Output[1];
  localDW->AddConstant[2] = 0.095492965964253843 * rty_TVS_Output[2];
  localDW->AddConstant[3] = 0.095492965964253843 * rty_TVS_Output[3];

  /* Saturate: '<S15>/Saturation1' incorporates:
   *  Bias: '<S5>/Add Constant'
   */
  if (localDW->AddConstant[0] > 106.0) {
    localDW->AddConstant[0] = 106.0;
  } else if (localDW->AddConstant[0] < 1.0) {
    localDW->AddConstant[0] = 1.0;
  }

  if (localDW->AddConstant[1] > 106.0) {
    localDW->AddConstant[1] = 106.0;
  } else if (localDW->AddConstant[1] < 1.0) {
    localDW->AddConstant[1] = 1.0;
  }

  if (localDW->AddConstant[2] > 106.0) {
    localDW->AddConstant[2] = 106.0;
  } else if (localDW->AddConstant[2] < 1.0) {
    localDW->AddConstant[2] = 1.0;
  }

  if (localDW->AddConstant[3] > 106.0) {
    localDW->AddConstant[3] = 106.0;
  } else if (localDW->AddConstant[3] < 1.0) {
    localDW->AddConstant[3] = 1.0;
  }

  /* End of Saturate: '<S15>/Saturation1' */

  /* RelationalOperator: '<S15>/Less Than' incorporates:
   *  Constant: '<S15>/Constant6'
   */
  rtb_LessThan[0] = (rtu_TVS_Input_j[0] < 75.0);
  rtb_LessThan[1] = (rtu_TVS_Input_j[1] < 75.0);
  rtb_LessThan[2] = (rtu_TVS_Input_j[2] < 75.0);
  rtb_LessThan[3] = (rtu_TVS_Input_j[3] < 75.0);
  for (sigIdx = 0; sigIdx < 4; sigIdx++) {
    /* Switch: '<S15>/Switch' incorporates:
     *  RelationalOperator: '<S15>/Less Than'
     */
    if (rtb_LessThan[sigIdx]) {
      localDW->rtb_Gain1_idx_0 = 5800.0;
    } else {
      localDW->rtb_Gain1_idx_0 = 1800.0;
    }

    /* End of Switch: '<S15>/Switch' */

    /* Abs: '<S15>/Abs1' incorporates:
     *  Bias: '<S15>/Bias'
     *  Bias: '<S5>/Add Constant'
     *  Selector: '<S15>/Selector1'
     */
    localDW->avg_steering_angle = localDW->AddConstant[sigIdx];
    for (j = 0; j < 161; j++) {
      /* Abs: '<S15>/Abs1' incorporates:
       *  Abs: '<S15>/Abs'
       *  Bias: '<S15>/Bias'
       *  Constant: '<S15>/Constant4'
       *  Constant: '<S15>/Constant5'
       *  Gain: '<S15>/Gain3'
       *  Selector: '<S15>/Selector'
       *  Selector: '<S15>/Selector1'
       *  Sum: '<S15>/Sum1'
       */
      rtb_Abs1_tmp = (int32_T)rtConstP.pooled4[j];
      rtb_Abs1_tmp_0 = 161 * sigIdx + j;
      localDW->Abs1[rtb_Abs1_tmp_0] = fabs(rtConstP.pooled8[(((int32_T)
        (localDW->avg_steering_angle + 1.0) - 1) * 161 + rtb_Abs1_tmp) - 1] -
        localDW->rtb_Gain1_idx_0);

      /* Gain: '<S15>/Gain3' incorporates:
       *  Abs: '<S15>/Abs'
       *  Constant: '<S15>/Constant1'
       *  Selector: '<S15>/Selector'
       *  Sum: '<S15>/Sum'
       */
      localDW->Abs_i[rtb_Abs1_tmp_0] = fabs(rtConstP.pooled8[(((int32_T)
        localDW->avg_steering_angle - 1) * 161 + rtb_Abs1_tmp) - 1] -
        localDW->rtb_Gain1_idx_0);
    }
  }

  /* S-Function (sdspstatminmax): '<S15>/Minimum' incorporates:
   *  Abs: '<S15>/Abs'
   *  Bias: '<S5>/Add Constant'
   */
  rtb_Abs1_tmp = 0;
  rtb_Abs1_tmp_0 = 0;
  for (sigIdx = 0; sigIdx < 4; sigIdx++) {
    localDW->Minimum_Valdata[rtb_Abs1_tmp_0] = localDW->Abs_i[rtb_Abs1_tmp];
    localDW->AddConstant[rtb_Abs1_tmp_0] = 1.0;
    rtb_Abs1_tmp++;
    for (j = 0; j < 160; j++) {
      if (localDW->Abs_i[rtb_Abs1_tmp] < localDW->Minimum_Valdata[rtb_Abs1_tmp_0])
      {
        localDW->Minimum_Valdata[rtb_Abs1_tmp_0] = localDW->Abs_i[rtb_Abs1_tmp];
        localDW->AddConstant[rtb_Abs1_tmp_0] = (real_T)j + 2.0;
      }

      rtb_Abs1_tmp++;
    }

    rtb_Abs1_tmp_0++;
  }

  /* End of S-Function (sdspstatminmax): '<S15>/Minimum' */

  /* S-Function (sdspstatminmax): '<S15>/Minimum1' incorporates:
   *  Abs: '<S15>/Abs1'
   *  Bias: '<S5>/Add Constant'
   *  Constant: '<S15>/Constant7'
   *  MinMax: '<S14>/Min2'
   *  Selector: '<S15>/Selector2'
   */
  rtb_Abs1_tmp = 0;
  rtb_Abs1_tmp_0 = 0;
  for (sigIdx = 0; sigIdx < 4; sigIdx++) {
    localDW->Minimum1_Valdata[rtb_Abs1_tmp_0] = localDW->Abs1[rtb_Abs1_tmp];
    localDW->Min2[rtb_Abs1_tmp_0] = 1.0;
    rtb_Abs1_tmp++;
    for (j = 0; j < 160; j++) {
      if (localDW->Abs1[rtb_Abs1_tmp] < localDW->Minimum1_Valdata[rtb_Abs1_tmp_0])
      {
        localDW->Minimum1_Valdata[rtb_Abs1_tmp_0] = localDW->Abs1[rtb_Abs1_tmp];
        localDW->Min2[rtb_Abs1_tmp_0] = (real_T)j + 2.0;
      }

      rtb_Abs1_tmp++;
    }

    rtb_Abs1_tmp_0++;
    localDW->AddConstant[sigIdx] = rtConstP.pooled5[(int32_T)
      localDW->AddConstant[sigIdx] - 1];
  }

  /* End of S-Function (sdspstatminmax): '<S15>/Minimum1' */

  /* Gain: '<S15>/Gain1' */
  localDW->rtb_Gain1_idx_0 = 0.095492965964253843 * rty_TVS_Output[0];
  localDW->rtb_Gain1_idx_1 = 0.095492965964253843 * rty_TVS_Output[1];
  localDW->rtb_Gain1_idx_2 = 0.095492965964253843 * rty_TVS_Output[2];
  localDW->rtb_Gain1_idx_3 = 0.095492965964253843 * rty_TVS_Output[3];

  /* Sum: '<S15>/Sum4' incorporates:
   *  Gain: '<S15>/Gain1'
   *  Gain: '<S15>/Gain2'
   *  Rounding: '<S15>/Floor'
   */
  localDW->avg_steering_angle = rty_TVS_Output[0] - 10.4719755 * floor
    (localDW->rtb_Gain1_idx_0);
  localDW->rtb_Gain1_idx_0 = rty_TVS_Output[1] - 10.4719755 * floor
    (localDW->rtb_Gain1_idx_1);
  localDW->rtb_Gain1_idx_2 = rty_TVS_Output[2] - 10.4719755 * floor
    (localDW->rtb_Gain1_idx_2);
  localDW->rtb_Gain1_idx_3 = rty_TVS_Output[3] - 10.4719755 * floor
    (localDW->rtb_Gain1_idx_3);

  /* Sum: '<S15>/Sum2' incorporates:
   *  Constant: '<S15>/Constant8'
   *  Constant: '<S15>/Constant9'
   *  MinMax: '<S14>/Min2'
   *  Product: '<S15>/Divide'
   *  Product: '<S15>/Product1'
   *  Selector: '<S15>/Selector3'
   *  Sum: '<S15>/Sum3'
   */
  localDW->rtb_Gain1_idx_1 = (rtConstP.pooled5[(int32_T)localDW->Min2[0] - 1] -
    localDW->AddConstant[0]) * (localDW->avg_steering_angle / 10.4719755) +
    localDW->AddConstant[0];
  localDW->rtb_Gain1_idx_0 = (rtConstP.pooled5[(int32_T)localDW->Min2[1] - 1] -
    localDW->AddConstant[1]) * (localDW->rtb_Gain1_idx_0 / 10.4719755) +
    localDW->AddConstant[1];
  localDW->rtb_Gain1_idx_2 = (rtConstP.pooled5[(int32_T)localDW->Min2[2] - 1] -
    localDW->AddConstant[2]) * (localDW->rtb_Gain1_idx_2 / 10.4719755) +
    localDW->AddConstant[2];
  localDW->rtb_Gain1_idx_3 = (rtConstP.pooled5[(int32_T)localDW->Min2[3] - 1] -
    localDW->AddConstant[3]) * (localDW->rtb_Gain1_idx_3 / 10.4719755) +
    localDW->AddConstant[3];

  /* Lookup_n-D: '<S15>/1-D Lookup Table' incorporates:
   *  MinMax: '<S14>/Min2'
   */
  localDW->avg_steering_angle = rty_TVS_Output[0];
  localDW->Min2[0] = look1_binlg(localDW->avg_steering_angle,
    rtConstP.uDLookupTable_bp01Data, rtConstP.uDLookupTable_tableData, 67U);
  localDW->avg_steering_angle = rty_TVS_Output[1];
  localDW->Min2[1] = look1_binlg(localDW->avg_steering_angle,
    rtConstP.uDLookupTable_bp01Data, rtConstP.uDLookupTable_tableData, 67U);
  localDW->avg_steering_angle = rty_TVS_Output[2];
  localDW->Min2[2] = look1_binlg(localDW->avg_steering_angle,
    rtConstP.uDLookupTable_bp01Data, rtConstP.uDLookupTable_tableData, 67U);
  localDW->avg_steering_angle = rty_TVS_Output[3];
  localDW->Min2[3] = look1_binlg(localDW->avg_steering_angle,
    rtConstP.uDLookupTable_bp01Data, rtConstP.uDLookupTable_tableData, 67U);

  /* Switch: '<S18>/Switch2' incorporates:
   *  Bias: '<S5>/Add Constant'
   *  Gain: '<S15>/Gain4'
   *  MinMax: '<S14>/Min2'
   *  RelationalOperator: '<S18>/LowerRelop1'
   *  RelationalOperator: '<S18>/UpperRelop'
   *  Switch: '<S18>/Switch'
   */
  if (localDW->rtb_Gain1_idx_1 > localDW->Min2[0]) {
    localDW->rtb_Gain1_idx_1 = localDW->Min2[0];
  } else if (localDW->rtb_Gain1_idx_1 < -localDW->Min2[0]) {
    /* Switch: '<S18>/Switch' */
    localDW->rtb_Gain1_idx_1 = -localDW->Min2[0];
  }

  localDW->AddConstant[0] = localDW->rtb_Gain1_idx_1;

  /* Sum: '<S15>/Sum2' */
  localDW->rtb_Gain1_idx_1 = localDW->rtb_Gain1_idx_0;

  /* Switch: '<S18>/Switch2' incorporates:
   *  Bias: '<S5>/Add Constant'
   *  Gain: '<S15>/Gain4'
   *  MinMax: '<S14>/Min2'
   *  RelationalOperator: '<S18>/LowerRelop1'
   *  RelationalOperator: '<S18>/UpperRelop'
   *  Switch: '<S18>/Switch'
   */
  if (localDW->rtb_Gain1_idx_0 > localDW->Min2[1]) {
    localDW->rtb_Gain1_idx_1 = localDW->Min2[1];
  } else if (localDW->rtb_Gain1_idx_0 < -localDW->Min2[1]) {
    /* Switch: '<S18>/Switch' */
    localDW->rtb_Gain1_idx_1 = -localDW->Min2[1];
  }

  localDW->AddConstant[1] = localDW->rtb_Gain1_idx_1;

  /* Sum: '<S15>/Sum2' */
  localDW->rtb_Gain1_idx_1 = localDW->rtb_Gain1_idx_2;

  /* Switch: '<S18>/Switch2' incorporates:
   *  Bias: '<S5>/Add Constant'
   *  Gain: '<S15>/Gain4'
   *  MinMax: '<S14>/Min2'
   *  RelationalOperator: '<S18>/LowerRelop1'
   *  RelationalOperator: '<S18>/UpperRelop'
   *  Switch: '<S18>/Switch'
   */
  if (localDW->rtb_Gain1_idx_2 > localDW->Min2[2]) {
    localDW->rtb_Gain1_idx_1 = localDW->Min2[2];
  } else if (localDW->rtb_Gain1_idx_2 < -localDW->Min2[2]) {
    /* Switch: '<S18>/Switch' */
    localDW->rtb_Gain1_idx_1 = -localDW->Min2[2];
  }

  localDW->AddConstant[2] = localDW->rtb_Gain1_idx_1;

  /* Sum: '<S15>/Sum2' */
  localDW->rtb_Gain1_idx_1 = localDW->rtb_Gain1_idx_3;

  /* Switch: '<S18>/Switch2' incorporates:
   *  Gain: '<S15>/Gain4'
   *  MinMax: '<S14>/Min2'
   *  RelationalOperator: '<S18>/LowerRelop1'
   *  RelationalOperator: '<S18>/UpperRelop'
   *  Switch: '<S18>/Switch'
   */
  if (localDW->rtb_Gain1_idx_3 > localDW->Min2[3]) {
    localDW->rtb_Gain1_idx_1 = localDW->Min2[3];
  } else if (localDW->rtb_Gain1_idx_3 < -localDW->Min2[3]) {
    /* Switch: '<S18>/Switch' */
    localDW->rtb_Gain1_idx_1 = -localDW->Min2[3];
  }

  /* Switch: '<S16>/Switch1' incorporates:
   *  Constant: '<S16>/Constant'
   */
  if (rtu_TVS_Input_d[0] >= 1.4) {
    /* Saturate: '<S16>/Min Torque' incorporates:
     *  Gain: '<S16>/Gain4'
     *  Switch: '<S18>/Switch2'
     */
    if (-0.0 * localDW->AddConstant[0] > -0.01) {
      rty_TVS_Output_e[0] = -0.01;
    } else {
      rty_TVS_Output_e[0] = (rtNaN);
    }

    if (-0.0 * localDW->AddConstant[1] > -0.01) {
      rty_TVS_Output_e[1] = -0.01;
    } else {
      rty_TVS_Output_e[1] = (rtNaN);
    }

    if (-localDW->AddConstant[2] > -0.01) {
      rty_TVS_Output_e[2] = -0.01;
    } else if (-localDW->AddConstant[2] < -0.01) {
      rty_TVS_Output_e[2] = -0.01;
    } else {
      rty_TVS_Output_e[2] = -localDW->AddConstant[2];
    }

    if (-localDW->rtb_Gain1_idx_1 > -0.01) {
      rty_TVS_Output_e[3] = -0.01;
    } else if (-localDW->rtb_Gain1_idx_1 < -0.01) {
      rty_TVS_Output_e[3] = -0.01;
    } else {
      rty_TVS_Output_e[3] = -localDW->rtb_Gain1_idx_1;
    }

    /* End of Saturate: '<S16>/Min Torque' */
  } else {
    rty_TVS_Output_e[0] = 0.0;
    rty_TVS_Output_e[1] = 0.0;
    rty_TVS_Output_e[2] = 0.0;
    rty_TVS_Output_e[3] = 0.0;
  }

  /* End of Switch: '<S16>/Switch1' */

  /* DeadZone: '<S11>/Dead Zone' */
  if (rtu_TVS_Input_c > rtP.deadband_angle) {
    localDW->avg_steering_angle = rtu_TVS_Input_c - rtP.deadband_angle;
  } else if (rtu_TVS_Input_c >= -rtP.deadband_angle) {
    localDW->avg_steering_angle = 0.0;
  } else {
    localDW->avg_steering_angle = rtu_TVS_Input_c - (-rtP.deadband_angle);
  }

  /* End of DeadZone: '<S11>/Dead Zone' */

  /* Gain: '<S11>/Gain' */
  localDW->avg_steering_angle *= 0.28194;

  /* Math: '<S22>/Square1' */
  localDW->Square1 = localDW->avg_steering_angle * localDW->avg_steering_angle;

  /* Product: '<S22>/Product' */
  localDW->Square1 *= localDW->avg_steering_angle;

  /* Gain: '<S22>/Gain' */
  localDW->Square1 *= 7.0E-5;

  /* Math: '<S22>/Square' */
  localDW->rtb_Gain1_idx_3 = localDW->avg_steering_angle *
    localDW->avg_steering_angle;

  /* Gain: '<S22>/Gain1' */
  localDW->CCaller_o3 = 0.0038 * localDW->rtb_Gain1_idx_3;

  /* Gain: '<S22>/Gain2' */
  localDW->rtb_Gain1_idx_3 = 0.6535 * localDW->avg_steering_angle;

  /* Sum: '<S22>/Sum of Elements' */
  localDW->Min2[0] = localDW->Square1;
  localDW->Min2[1] = localDW->CCaller_o3;
  localDW->Min2[2] = localDW->rtb_Gain1_idx_3;
  localDW->Square1 = -0.0;
  localDW->Square1 += localDW->Min2[0];
  localDW->Square1 += localDW->Min2[1];
  localDW->Square1 += localDW->Min2[2];
  localDW->Square1 += -0.1061;

  /* Math: '<S23>/Square1' */
  localDW->rtb_Gain1_idx_3 = localDW->avg_steering_angle *
    localDW->avg_steering_angle;

  /* Product: '<S23>/Product' */
  localDW->rtb_Gain1_idx_3 *= localDW->avg_steering_angle;

  /* Gain: '<S23>/Gain' */
  localDW->CCaller_o3 = 7.0E-5 * localDW->rtb_Gain1_idx_3;

  /* Math: '<S23>/Square' */
  localDW->rtb_Gain1_idx_3 = localDW->avg_steering_angle *
    localDW->avg_steering_angle;

  /* Gain: '<S23>/Gain1' */
  localDW->rtb_Gain1_idx_3 *= -0.0038;

  /* Gain: '<S23>/Gain2' */
  localDW->avg_steering_angle *= 0.6535;

  /* Sum: '<S23>/Sum of Elements' */
  localDW->Min2[0] = localDW->CCaller_o3;
  localDW->Min2[1] = localDW->rtb_Gain1_idx_3;
  localDW->Min2[2] = localDW->avg_steering_angle;
  localDW->CCaller_o3 = -0.0;
  localDW->CCaller_o3 += localDW->Min2[0];
  localDW->CCaller_o3 += localDW->Min2[1];
  localDW->CCaller_o3 += localDW->Min2[2];
  localDW->CCaller_o3 += 0.1061;

  /* SignalConversion generated from: '<S11>/Mean' */
  rtb_Abs_m_idx_0 = localDW->Square1;

  /* S-Function (sdspstatfcns): '<S11>/Mean' */
  localDW->avg_steering_angle = rtb_Abs_m_idx_0;
  localDW->avg_steering_angle += localDW->CCaller_o3;
  localDW->avg_steering_angle /= 2.0;

  /* S-Function (sdspstatfcns): '<S17>/Mean' incorporates:
   *  UnitDelay: '<S2>/Unit Delay'
   */
  localDW->Square1 = localDW->UnitDelay_DSTATE[0];
  localDW->Square1 += localDW->UnitDelay_DSTATE[1];
  localDW->Square1 += localDW->UnitDelay_DSTATE[2];
  localDW->Square1 += localDW->UnitDelay_DSTATE[3];
  localDW->Square1 /= 4.0;

  /* Product: '<S17>/Divide' */
  localDW->rtb_Gain1_idx_3 = localDW->Square1 / 2.0;

  /* Gain: '<S17>/Gain' */
  rtb_UnitDelay_g_idx_0 = 0.0 * localDW->rtb_Gain1_idx_3;
  rtb_UnitDelay_g_idx_1 = 0.0 * localDW->rtb_Gain1_idx_3;
  rtb_UnitDelay_g_idx_2 = localDW->rtb_Gain1_idx_3;
  localDW->rtb_UnitDelay_g_idx_3 = localDW->rtb_Gain1_idx_3;

  /* Gain: '<S17>/Gain2' */
  localDW->Min2[0] = 0.0 * localDW->Square1;
  localDW->Min2[1] = 0.0 * localDW->Square1;
  localDW->Min2[2] = localDW->Square1;
  localDW->Min2[3] = localDW->Square1;

  /* Sum: '<S17>/Add' incorporates:
   *  Gain: '<S17>/Gain'
   *  Gain: '<S17>/Gain2'
   */
  localDW->rtb_Gain1_idx_0 = localDW->Min2[0] + rtb_UnitDelay_g_idx_0;
  localDW->Sum2 = localDW->Min2[1] + rtb_UnitDelay_g_idx_1;
  localDW->rtb_Gain1_idx_2 = localDW->Min2[2] + rtb_UnitDelay_g_idx_2;
  localDW->DotProduct2 = localDW->Min2[3] + localDW->rtb_UnitDelay_g_idx_3;

  /* Saturate: '<S16>/Max Torque' incorporates:
   *  Gain: '<S16>/Gain8'
   *  Switch: '<S18>/Switch2'
   */
  if (0.0 * localDW->AddConstant[0] < 0.01) {
    rty_TVS_Output_k[0] = 0.01;
  } else {
    rty_TVS_Output_k[0] = (rtNaN);
  }

  if (0.0 * localDW->AddConstant[1] < 0.01) {
    rty_TVS_Output_k[1] = 0.01;
  } else {
    rty_TVS_Output_k[1] = (rtNaN);
  }

  if (localDW->AddConstant[2] > 25.0) {
    rty_TVS_Output_k[2] = 25.0;
  } else if (localDW->AddConstant[2] < 0.01) {
    rty_TVS_Output_k[2] = 0.01;
  } else {
    rty_TVS_Output_k[2] = localDW->AddConstant[2];
  }

  if (localDW->rtb_Gain1_idx_1 > 25.0) {
    rty_TVS_Output_k[3] = 25.0;
  } else if (localDW->rtb_Gain1_idx_1 < 0.01) {
    rty_TVS_Output_k[3] = 0.01;
  } else {
    rty_TVS_Output_k[3] = localDW->rtb_Gain1_idx_1;
  }

  /* End of Saturate: '<S16>/Max Torque' */

  /* Gain: '<S11>/Gain1' */
  localDW->rtb_Gain1_idx_1 = 0.01745329 * rtb_Abs_m_idx_0;

  /* Gain: '<S13>/Gain' incorporates:
   *  Abs: '<S13>/Abs'
   */
  localDW->rtb_Gain5_idx_1 = 0.15915494309189535 * fabs(localDW->rtb_Gain1_idx_1);

  /* Trigonometry: '<S13>/Cos' */
  localDW->rtb_Gain1_idx_3 = cos(localDW->rtb_Gain5_idx_1);

  /* Signum: '<S13>/Sign' */
  if (!rtIsNaN(localDW->rtb_Gain1_idx_1)) {
    if (localDW->rtb_Gain1_idx_1 < 0.0) {
      localDW->rtb_Gain1_idx_1 = -1.0;
    } else {
      localDW->rtb_Gain1_idx_1 = (localDW->rtb_Gain1_idx_1 > 0.0);
    }
  }

  /* Gain: '<S11>/Gain1' incorporates:
   *  Product: '<S13>/Product1'
   *  Trigonometry: '<S13>/Sin'
   */
  rtb_Abs_m_idx_0 = sin(localDW->rtb_Gain5_idx_1) * localDW->rtb_Gain1_idx_1;
  localDW->rtb_Gain1_idx_1 = 0.01745329 * localDW->CCaller_o3;

  /* Gain: '<S13>/Gain' incorporates:
   *  Abs: '<S13>/Abs'
   */
  localDW->rtb_Gain5_idx_1 = 0.15915494309189535 * fabs(localDW->rtb_Gain1_idx_1);

  /* DotProduct: '<S13>/Dot Product1' incorporates:
   *  Constant: '<S13>/Constant5'
   *  SignalConversion generated from: '<S13>/Dot Product1'
   */
  localDW->rtb_Gain1_idx_3 = localDW->rtb_Gain1_idx_3 * 0.647895 +
    rtb_Abs_m_idx_0 * 0.7922471;

  /* Signum: '<S13>/Sign' */
  if (!rtIsNaN(localDW->rtb_Gain1_idx_1)) {
    if (localDW->rtb_Gain1_idx_1 < 0.0) {
      localDW->rtb_Gain1_idx_1 = -1.0;
    } else {
      localDW->rtb_Gain1_idx_1 = (localDW->rtb_Gain1_idx_1 > 0.0);
    }
  }

  /* DotProduct: '<S13>/Dot Product2' incorporates:
   *  Constant: '<S13>/Constant6'
   *  Product: '<S13>/Product1'
   *  Trigonometry: '<S13>/Cos'
   *  Trigonometry: '<S13>/Sin'
   */
  localDW->rtb_TmpSignalConversionAtDotP_m = sin(localDW->rtb_Gain5_idx_1) *
    localDW->rtb_Gain1_idx_1 * 0.7922471 + cos(localDW->rtb_Gain5_idx_1) *
    -0.647895;

  /* Math: '<S10>/Square' */
  rtb_Abs_m_idx_0 = rtu_TVS_Input_d[0] * rtu_TVS_Input_d[0];
  localDW->CCaller_o3 = rtu_TVS_Input_d[1] * rtu_TVS_Input_d[1];

  /* Sum: '<S10>/Sum' incorporates:
   *  Math: '<S10>/Square'
   */
  localDW->Square1 = -0.0;
  localDW->Square1 += rtb_Abs_m_idx_0;
  localDW->Square1 += localDW->CCaller_o3;

  /* Sqrt: '<S10>/Sqrt' */
  localDW->Square1 = sqrt(localDW->Square1);

  /* Gain: '<S10>/Gain' */
  localDW->CCaller_o3 = rtP.Ku * localDW->Square1;

  /* Lookup_n-D: '<S10>/1-D Lookup Table' incorporates:
   *  CCaller: '<S5>/C Caller'
   */
  bpIdx = plook_evenc(localDW->CCaller_o3, 0.0, 3.0, 9U, &rtb_Abs_m_idx_0);
  localDW->CCaller_o3 = intrp1d_l(bpIdx, rtb_Abs_m_idx_0,
    rtConstP.uDLookupTable_tableData_h);

  /* Gain: '<S11>/Gain2' */
  localDW->avg_steering_angle *= 0.01745329;

  /* Product: '<S10>/Divide1' incorporates:
   *  Constant: '<S10>/Constant1'
   */
  localDW->Square1 = localDW->Square1 * localDW->avg_steering_angle *
    0.63488032505872649;

  /* Abs: '<S10>/Abs' */
  rtb_Abs_m_idx_0 = localDW->CCaller_o3;
  localDW->CCaller_o3 = fabs(localDW->Square1);

  /* MinMax: '<S10>/Min of Elements' */
  localDW->avg_steering_angle = rtb_Abs_m_idx_0;
  if ((localDW->avg_steering_angle <= localDW->CCaller_o3) || rtIsNaN
      (localDW->CCaller_o3)) {
  } else {
    localDW->avg_steering_angle = localDW->CCaller_o3;
  }

  /* End of MinMax: '<S10>/Min of Elements' */

  /* Signum: '<S10>/Sign' */
  if (rtIsNaN(localDW->Square1)) {
  } else if (localDW->Square1 < 0.0) {
    localDW->Square1 = -1.0;
  } else {
    localDW->Square1 = (localDW->Square1 > 0.0);
  }

  /* End of Signum: '<S10>/Sign' */

  /* Product: '<S10>/Product' */
  *rty_TVS_Output_i = localDW->avg_steering_angle * localDW->Square1;

  /* Switch: '<S17>/Switch1' incorporates:
   *  Bias: '<S5>/Add Constant'
   *  Constant: '<S13>/Constant3'
   *  Constant: '<S13>/Constant4'
   *  Constant: '<S17>/Constant'
   *  DotProduct: '<S13>/Dot Product2'
   *  Gain: '<S17>/Gain7'
   *  Product: '<S17>/Product1'
   */
  if (*rty_TVS_Output_i != 0.0) {
    /* RelationalOperator: '<S20>/LowerRelop1' */
    rtb_LessThan[0] = (localDW->rtb_Gain1_idx_0 > rty_TVS_Output_k[0]);
    rtb_LessThan[1] = (rtb_UnitDelay_g_idx_1 > rty_TVS_Output_k[1]);
    rtb_LessThan[2] = (localDW->rtb_Gain1_idx_2 > rty_TVS_Output_k[2]);
    rtb_LessThan[3] = (localDW->rtb_UnitDelay_g_idx_3 > rty_TVS_Output_k[3]);

    /* RelationalOperator: '<S20>/UpperRelop' */
    rtb_UpperRelop_n_idx_0 = (localDW->rtb_Gain1_idx_0 < rty_TVS_Output_e[0]);
    rtb_UpperRelop_n_idx_1 = (rtb_UnitDelay_g_idx_1 < rty_TVS_Output_e[1]);
    rtb_UpperRelop_n_idx_2 = (localDW->rtb_Gain1_idx_2 < rty_TVS_Output_e[2]);
    rtb_UpperRelop_n_idx_3 = (localDW->rtb_UnitDelay_g_idx_3 < rty_TVS_Output_e
      [3]);

    /* Switch: '<S20>/Switch' incorporates:
     *  RelationalOperator: '<S20>/UpperRelop'
     */
    if (rtb_UpperRelop_n_idx_0) {
      /* Switch: '<S20>/Switch2' incorporates:
       *  Product: '<S17>/Product1'
       */
      localDW->rtb_Gain1_idx_0 = rty_TVS_Output_e[0];
    }

    if (rtb_UpperRelop_n_idx_1) {
      /* Switch: '<S20>/Switch2' incorporates:
       *  Product: '<S17>/Product1'
       */
      localDW->rtb_Gain1_idx_1 = rty_TVS_Output_e[1];
    } else {
      /* Switch: '<S20>/Switch2' incorporates:
       *  Product: '<S17>/Product1'
       */
      localDW->rtb_Gain1_idx_1 = rtb_UnitDelay_g_idx_1;
    }

    if (rtb_UpperRelop_n_idx_2) {
      /* Switch: '<S20>/Switch2' incorporates:
       *  Product: '<S17>/Product1'
       */
      localDW->rtb_Gain1_idx_2 = rty_TVS_Output_e[2];
    }

    if (rtb_UpperRelop_n_idx_3) {
      localDW->avg_steering_angle = rty_TVS_Output_e[3];
    } else {
      localDW->avg_steering_angle = localDW->rtb_UnitDelay_g_idx_3;
    }

    /* End of Switch: '<S20>/Switch' */

    /* Switch: '<S20>/Switch2' incorporates:
     *  RelationalOperator: '<S20>/LowerRelop1'
     */
    if (rtb_LessThan[0]) {
      /* Product: '<S17>/Product1' */
      localDW->rtb_Gain1_idx_0 = rty_TVS_Output_k[0];
    }

    if (rtb_LessThan[1]) {
      /* Product: '<S17>/Product1' */
      localDW->rtb_Gain1_idx_1 = rty_TVS_Output_k[1];
    }

    if (rtb_LessThan[2]) {
      /* Product: '<S17>/Product1' */
      localDW->rtb_Gain1_idx_2 = rty_TVS_Output_k[2];
    }

    if (rtb_LessThan[3]) {
      localDW->avg_steering_angle = rty_TVS_Output_k[3];
    }

    localDW->AddConstant[0] = localDW->rtb_Gain1_idx_3 *
      localDW->rtb_Gain1_idx_0 * 0.38765914066666662;
    localDW->AddConstant[1] = localDW->rtb_TmpSignalConversionAtDotP_m *
      localDW->rtb_Gain1_idx_1 * 0.38765914066666662;
    localDW->AddConstant[2] = 0.62102 * localDW->rtb_Gain1_idx_2 * 0.387634;
    localDW->AddConstant[3] = -0.62102 * localDW->avg_steering_angle * 0.387634;
  } else {
    localDW->AddConstant[0] = 0.0;
    localDW->AddConstant[1] = 0.0;
    localDW->AddConstant[2] = 0.0;
    localDW->AddConstant[3] = 0.0;
  }

  /* End of Switch: '<S17>/Switch1' */

  /* Gain: '<S17>/Gain6' incorporates:
   *  DotProduct: '<S13>/Dot Product2'
   */
  localDW->rtb_Gain1_idx_0 = 0.38765914066666662 * localDW->rtb_Gain1_idx_3;
  localDW->rtb_Gain1_idx_1 = 0.38765914066666662 *
    localDW->rtb_TmpSignalConversionAtDotP_m;

  /* MinMax: '<S14>/Min2' */
  localDW->CCaller_o3 = rty_TVS_Output[0];
  localDW->avg_steering_angle = rty_TVS_Output[1];
  localDW->Square1 = rty_TVS_Output[2];
  rtb_Abs_m_idx_0 = rty_TVS_Output[3];

  /* Gain: '<S14>/Gain5' */
  localDW->rtb_Gain1_idx_2 = 0.95 * rty_TVS_Output[0];
  localDW->rtb_Gain5_idx_1 = 0.95 * rty_TVS_Output[1];
  localDW->rtb_Gain5_idx_2 = 0.95 * rty_TVS_Output[2];
  localDW->rtb_Gain5_idx_3 = 0.95 * rty_TVS_Output[3];

  /* Switch: '<S14>/Switch' incorporates:
   *  MinMax: '<S14>/Min2'
   *  Product: '<S14>/Product'
   *  Product: '<S14>/Product1'
   *  SignalConversion generated from: '<S4>/driver_input'
   */
  if (rtu_TVS_Input_b > 0.0) {
    /* MinMax: '<S14>/Min2' */
    if (localDW->CCaller_o3 >= 0.1) {
    } else {
      localDW->CCaller_o3 = 0.1;
    }

    if (localDW->avg_steering_angle >= 0.1) {
    } else {
      localDW->avg_steering_angle = 0.1;
    }

    if (localDW->Square1 >= 0.1) {
    } else {
      localDW->Square1 = 0.1;
    }

    if (!(rtb_Abs_m_idx_0 >= 0.1)) {
      rtb_Abs_m_idx_0 = 0.1;
    }

    /* DotProduct: '<S14>/Dot Product' incorporates:
     *  Constant: '<S14>/Constant'
     */
    localDW->avg_steering_angle = ((0.0 * localDW->CCaller_o3 + 0.0 *
      localDW->avg_steering_angle) + 26.315789473684212 * localDW->Square1) +
      26.315789473684212 * rtb_Abs_m_idx_0;

    /* MinMax: '<S14>/Min' incorporates:
     *  DotProduct: '<S14>/Dot Product'
     */
    localDW->CCaller_o3 = rtu_TVS_Input_k[0];
    if ((localDW->CCaller_o3 <= localDW->avg_steering_angle) || rtIsNaN
        (localDW->avg_steering_angle)) {
      localDW->avg_steering_angle = localDW->CCaller_o3;
    }

    /* End of MinMax: '<S14>/Min' */

    /* Saturate: '<S14>/Discharge Limits' */
    if (localDW->avg_steering_angle > 75000.0) {
      localDW->avg_steering_angle = 75000.0;
    } else if (localDW->avg_steering_angle < 0.0) {
      localDW->avg_steering_angle = 0.0;
    }

    /* End of Saturate: '<S14>/Discharge Limits' */
    *rty_TVS_Output_m = localDW->avg_steering_angle * rtu_TVS_Input_b;
  } else {
    if (localDW->CCaller_o3 >= 0.1) {
    } else {
      /* MinMax: '<S14>/Min2' */
      localDW->CCaller_o3 = 0.1;
    }

    /* MinMax: '<S14>/Min2' */
    if (localDW->avg_steering_angle >= 0.1) {
    } else {
      localDW->avg_steering_angle = 0.1;
    }

    if (localDW->Square1 >= 0.1) {
    } else {
      localDW->Square1 = 0.1;
    }

    if (!(rtb_Abs_m_idx_0 >= 0.1)) {
      rtb_Abs_m_idx_0 = 0.1;
    }

    /* DotProduct: '<S14>/Dot Product' incorporates:
     *  Constant: '<S14>/Constant'
     */
    localDW->CCaller_o3 = ((0.0 * localDW->CCaller_o3 + 0.0 *
      localDW->avg_steering_angle) + 26.315789473684212 * localDW->Square1) +
      26.315789473684212 * rtb_Abs_m_idx_0;

    /* MinMax: '<S14>/Min1' incorporates:
     *  DotProduct: '<S14>/Dot Product'
     */
    localDW->avg_steering_angle = rtu_TVS_Input_k[1];
    if ((localDW->CCaller_o3 <= localDW->avg_steering_angle) || rtIsNaN
        (localDW->avg_steering_angle)) {
      localDW->avg_steering_angle = localDW->CCaller_o3;
    }

    /* End of MinMax: '<S14>/Min1' */

    /* Saturate: '<S14>/Charge Limits' */
    if (localDW->avg_steering_angle > 0.0) {
      localDW->avg_steering_angle = 0.0;
    } else if (localDW->avg_steering_angle < 0.0) {
      localDW->avg_steering_angle = 0.0;
    }

    /* End of Saturate: '<S14>/Charge Limits' */
    *rty_TVS_Output_m = rtu_TVS_Input_b * localDW->avg_steering_angle;
  }

  /* End of Switch: '<S14>/Switch' */

  /* Signum: '<S17>/Sign' */
  localDW->CCaller_o3 = *rty_TVS_Output_m;
  if (rtIsNaN(localDW->CCaller_o3)) {
  } else if (localDW->CCaller_o3 < 0.0) {
    localDW->CCaller_o3 = -1.0;
  } else {
    localDW->CCaller_o3 = (localDW->CCaller_o3 > 0.0);
  }

  /* End of Signum: '<S17>/Sign' */

  /* UnitDelay: '<S17>/Unit Delay5' */
  localDW->avg_steering_angle = localDW->UnitDelay5_DSTATE;

  /* Signum: '<S17>/Sign2' */
  if (rtIsNaN(localDW->avg_steering_angle)) {
    rtb_Abs_m_idx_0 = localDW->avg_steering_angle;
  } else if (localDW->avg_steering_angle < 0.0) {
    rtb_Abs_m_idx_0 = -1.0;
  } else {
    rtb_Abs_m_idx_0 = (localDW->avg_steering_angle > 0.0);
  }

  /* End of Signum: '<S17>/Sign2' */

  /* Abs: '<S17>/Abs' */
  localDW->Abs = fabs(*rty_TVS_Output_i);

  /* UnitDelay: '<S17>/Unit Delay1' */
  localDW->avg_steering_angle = localDW->UnitDelay1_DSTATE;

  /* RelationalOperator: '<S17>/GreaterThan1' incorporates:
   *  Constant: '<S17>/Constant1'
   */
  rtb_UpperRelop_n_idx_0 = (localDW->avg_steering_angle > 0.05);

  /* UnitDelay: '<S17>/Unit Delay' */
  *rty_TVS_Output_c = localDW->UnitDelay_DSTATE_e;

  /* Sum: '<S9>/Sum1' */
  localDW->avg_steering_angle = *rty_TVS_Output_i - rtu_TVS_Input_i[2];

  /* Abs: '<S9>/Abs' */
  localDW->Square1 = fabs(localDW->avg_steering_angle);

  /* RelationalOperator: '<S9>/Less Than' incorporates:
   *  Constant: '<S9>/Constant'
   */
  *rty_TVS_Output_b = (localDW->Square1 < 0.5);

  /* Product: '<S9>/Product' */
  localDW->Square1 = (*rty_TVS_Output_c ? (real_T)*rty_TVS_Output_b : 0.0) *
    localDW->avg_steering_angle;

  /* Gain: '<S9>/Gain' */
  localDW->Square1 *= rtP.I;

  /* UnitDelay: '<S17>/Unit Delay4' */
  *rty_TVS_Output_b = localDW->UnitDelay4_DSTATE;

  /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
  if ((*rty_TVS_Output_b) || (localDW->DiscreteTimeIntegrator_PrevRese != 0)) {
    localDW->DiscreteTimeIntegrator_DSTATE = 0.0;
  }

  /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator = 0.015 * localDW->Square1 +
    localDW->DiscreteTimeIntegrator_DSTATE;

  /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
  if (localDW->DiscreteTimeIntegrator >= 1.0) {
    /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
    localDW->DiscreteTimeIntegrator = 1.0;
  } else if (localDW->DiscreteTimeIntegrator <= -1.0) {
    /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
    localDW->DiscreteTimeIntegrator = -1.0;
  }

  /* Gain: '<S9>/P' */
  localDW->Square1 = rtP.P * localDW->avg_steering_angle;

  /* Sum: '<S9>/Sum7' */
  *rty_TVS_Output_d = localDW->DiscreteTimeIntegrator + localDW->Square1;

  /* Sum: '<S17>/Sum1' incorporates:
   *  Bias: '<S5>/Add Constant'
   */
  localDW->avg_steering_angle = -0.0;
  localDW->avg_steering_angle += localDW->AddConstant[0];
  localDW->avg_steering_angle += localDW->AddConstant[1];
  localDW->avg_steering_angle += localDW->AddConstant[2];
  localDW->avg_steering_angle += localDW->AddConstant[3];

  /* RelationalOperator: '<S19>/LowerRelop1' */
  rtb_UpperRelop_n_idx_1 = (*rty_TVS_Output_d > localDW->avg_steering_angle);

  /* Switch: '<S19>/Switch2' */
  if (!rtb_UpperRelop_n_idx_1) {
    /* Switch: '<S17>/Switch2' incorporates:
     *  Constant: '<S13>/Constant3'
     *  Constant: '<S13>/Constant4'
     *  Constant: '<S17>/Constant'
     *  DotProduct: '<S13>/Dot Product2'
     *  Gain: '<S17>/Gain1'
     *  Product: '<S17>/Product2'
     *  RelationalOperator: '<S21>/LowerRelop1'
     *  Switch: '<S21>/Switch2'
     */
    if (*rty_TVS_Output_i != 0.0) {
      /* RelationalOperator: '<S21>/UpperRelop' incorporates:
       *  RelationalOperator: '<S21>/LowerRelop1'
       */
      rtb_LessThan[0] = (rtb_UnitDelay_g_idx_0 < rty_TVS_Output_e[0]);
      rtb_LessThan[1] = (localDW->Sum2 < rty_TVS_Output_e[1]);
      rtb_LessThan[2] = (rtb_UnitDelay_g_idx_2 < rty_TVS_Output_e[2]);
      rtb_LessThan[3] = (localDW->DotProduct2 < rty_TVS_Output_e[3]);

      /* Switch: '<S21>/Switch' incorporates:
       *  Product: '<S17>/Product2'
       *  RelationalOperator: '<S21>/LowerRelop1'
       */
      if (rtb_LessThan[0]) {
        localDW->AddConstant[0] = rty_TVS_Output_e[0];
      } else {
        localDW->AddConstant[0] = rtb_UnitDelay_g_idx_0;
      }

      if (rtb_LessThan[1]) {
        localDW->AddConstant[1] = rty_TVS_Output_e[1];
      } else {
        localDW->AddConstant[1] = localDW->Sum2;
      }

      if (rtb_LessThan[2]) {
        localDW->AddConstant[2] = rty_TVS_Output_e[2];
      } else {
        localDW->AddConstant[2] = rtb_UnitDelay_g_idx_2;
      }

      if (rtb_LessThan[3]) {
        localDW->AddConstant[3] = rty_TVS_Output_e[3];
      } else {
        localDW->AddConstant[3] = localDW->DotProduct2;
      }

      /* End of Switch: '<S21>/Switch' */

      /* RelationalOperator: '<S21>/LowerRelop1' */
      rtb_LessThan[0] = (rtb_UnitDelay_g_idx_0 > rty_TVS_Output_k[0]);
      rtb_LessThan[1] = (localDW->Sum2 > rty_TVS_Output_k[1]);
      rtb_LessThan[2] = (rtb_UnitDelay_g_idx_2 > rty_TVS_Output_k[2]);
      rtb_LessThan[3] = (localDW->DotProduct2 > rty_TVS_Output_k[3]);

      /* Switch: '<S21>/Switch2' incorporates:
       *  RelationalOperator: '<S21>/LowerRelop1'
       */
      if (rtb_LessThan[0]) {
        /* Product: '<S17>/Product2' */
        localDW->AddConstant[0] = rty_TVS_Output_k[0];
      }

      if (rtb_LessThan[1]) {
        /* Product: '<S17>/Product2' */
        localDW->AddConstant[1] = rty_TVS_Output_k[1];
      }

      if (rtb_LessThan[2]) {
        /* Product: '<S17>/Product2' */
        localDW->AddConstant[2] = rty_TVS_Output_k[2];
      }

      localDW->avg_steering_angle = localDW->AddConstant[3];

      /* Switch: '<S21>/Switch2' incorporates:
       *  Product: '<S17>/Product2'
       *  RelationalOperator: '<S21>/LowerRelop1'
       */
      if (rtb_LessThan[3]) {
        localDW->avg_steering_angle = rty_TVS_Output_k[3];
      }

      rtb_UnitDelay_g_idx_0 = localDW->rtb_Gain1_idx_3 * localDW->AddConstant[0]
        * 0.38765914066666662;
      rtb_UnitDelay_g_idx_1 = localDW->rtb_TmpSignalConversionAtDotP_m *
        localDW->AddConstant[1] * 0.38765914066666662;
      rtb_UnitDelay_g_idx_2 = 0.62102 * localDW->AddConstant[2] * 0.387634;
      localDW->rtb_UnitDelay_g_idx_3 = -0.62102 * localDW->avg_steering_angle *
        0.387634;
    } else {
      rtb_UnitDelay_g_idx_0 = 0.0;
      rtb_UnitDelay_g_idx_1 = 0.0;
      rtb_UnitDelay_g_idx_2 = 0.0;
      localDW->rtb_UnitDelay_g_idx_3 = 0.0;
    }

    /* End of Switch: '<S17>/Switch2' */

    /* Sum: '<S17>/Sum2' incorporates:
     *  Switch: '<S17>/Switch2'
     */
    localDW->Sum2 = ((rtb_UnitDelay_g_idx_0 + rtb_UnitDelay_g_idx_1) +
                     rtb_UnitDelay_g_idx_2) + localDW->rtb_UnitDelay_g_idx_3;

    /* RelationalOperator: '<S19>/UpperRelop' */
    rtb_UpperRelop_n_idx_1 = (*rty_TVS_Output_d < localDW->Sum2);

    /* Switch: '<S19>/Switch' */
    if (rtb_UpperRelop_n_idx_1) {
      localDW->avg_steering_angle = localDW->Sum2;
    } else {
      localDW->avg_steering_angle = *rty_TVS_Output_d;
    }

    /* End of Switch: '<S19>/Switch' */
  }

  /* End of Switch: '<S19>/Switch2' */

  /* Abs: '<S17>/Abs3' */
  localDW->Square1 = fabs(localDW->avg_steering_angle);

  /* RelationalOperator: '<S17>/Equal' incorporates:
   *  Constant: '<S17>/Constant4'
   */
  rtb_UpperRelop_n_idx_1 = (localDW->Square1 < 0.01);

  /* Switch: '<S17>/Switch' incorporates:
   *  Constant: '<S17>/Constant5'
   *  Constant: '<S17>/Constant6'
   */
  if (rtb_UpperRelop_n_idx_1) {
    localDW->Square1 = 0.0001;
  } else {
    localDW->Square1 = 0.0;
  }

  /* End of Switch: '<S17>/Switch' */

  /* Sum: '<S17>/Sum3' */
  *rty_TVS_Output_ba = localDW->avg_steering_angle + localDW->Square1;

  /* Abs: '<S17>/Abs1' */
  localDW->avg_steering_angle = fabs(localDW->avg_steering_angle);

  /* Abs: '<S17>/Abs2' */
  localDW->Square1 = fabs(*rty_TVS_Output_d);

  /* Update for UnitDelay: '<S17>/Unit Delay' incorporates:
   *  RelationalOperator: '<S17>/GreaterThanOrEqual'
   */
  localDW->UnitDelay_DSTATE_e = (localDW->avg_steering_angle < localDW->Square1);

  /* Update for UnitDelay: '<S17>/Unit Delay5' */
  localDW->UnitDelay5_DSTATE = *rty_TVS_Output_m;

  /* Update for UnitDelay: '<S17>/Unit Delay1' */
  localDW->UnitDelay1_DSTATE = localDW->Abs;

  /* Update for UnitDelay: '<S17>/Unit Delay4' incorporates:
   *  Constant: '<S17>/Constant2'
   *  Logic: '<S17>/NOT1'
   *  Logic: '<S17>/NOT2'
   *  Logic: '<S17>/OR'
   *  RelationalOperator: '<S17>/Equal1'
   *  RelationalOperator: '<S17>/Equal2'
   *  RelationalOperator: '<S17>/GreaterThan'
   */
  localDW->UnitDelay4_DSTATE = (((localDW->Abs > 0.05) != (int32_T)
    rtb_UpperRelop_n_idx_0) || (!(localDW->CCaller_o3 == rtb_Abs_m_idx_0)));

  /* Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = localDW->DiscreteTimeIntegrator;
  localDW->DiscreteTimeIntegrator_PrevRese = (int8_T)*rty_TVS_Output_b;

  /* End of Outputs for SubSystem: '<S2>/Torque Vectoring Micro Controller' */

  /* Bias: '<S5>/Add Constant' */
  localDW->AddConstant[0] = rty_TVS_Output_e[0] + 25.0;
  localDW->AddConstant[1] = rty_TVS_Output_e[1] + 25.0;
  localDW->AddConstant[2] = rty_TVS_Output_e[2] + 25.0;
  localDW->AddConstant[3] = rty_TVS_Output_e[3] + 25.0;

  /* Bias: '<S5>/Add Constant1' */
  localDW->rtb_Gain1_idx_3 = rty_TVS_Output_k[0] + 25.0;
  localDW->avg_steering_angle = rty_TVS_Output_k[1] + 25.0;
  localDW->Sum2 = rty_TVS_Output_k[2] + 25.0;
  localDW->DotProduct2 = rty_TVS_Output_k[3] + 25.0;
  rty_TVS_Output[0] = localDW->rtb_Gain1_idx_3;
  rty_TVS_Output[1] = localDW->avg_steering_angle;
  rty_TVS_Output[2] = localDW->Sum2;
  rty_TVS_Output[3] = localDW->DotProduct2;

  /* Sum: '<S5>/Add' incorporates:
   *  Constant: '<S5>/Constant'
   *  DotProduct: '<S5>/Dot Product1'
   *  Gain: '<S17>/Gain6'
   */
  localDW->Sum2 = (((25.0 * localDW->rtb_Gain1_idx_0 + 25.0 *
                     localDW->rtb_Gain1_idx_1) + 6.018211667) + -6.018211667) + *
    rty_TVS_Output_ba;

  /* Sum: '<S5>/Add1' incorporates:
   *  Constant: '<S5>/Constant1'
   *  DotProduct: '<S5>/Dot Product'
   *  Gain: '<S14>/Gain5'
   */
  localDW->DotProduct2 = (((25.0 * localDW->rtb_Gain1_idx_2 + 25.0 *
    localDW->rtb_Gain5_idx_1) + 25.0 * localDW->rtb_Gain5_idx_2) + 25.0 *
    localDW->rtb_Gain5_idx_3) + *rty_TVS_Output_m;

  /* CCaller: '<S5>/C Caller' incorporates:
   *  Constant: '<S5>/Constant2'
   *  Constant: '<S5>/Constant4'
   */
  localDW->rtb_Gain1_idx_3 = 0.0;
  localDW->CCaller_o3 = 0.0;
  localDW->Square1 = 0.0;
  localDW->avg_steering_angle = 0.0;
  *rty_TVS_Output_j = bigM_func(29.074435549999997, 29.074435549999997, 29.07255,
    29.07255, localDW->DotProduct2, localDW->rtb_Gain1_idx_2,
    localDW->rtb_Gain5_idx_1, localDW->rtb_Gain5_idx_2, localDW->rtb_Gain5_idx_3,
    localDW->Sum2, localDW->rtb_Gain1_idx_0, localDW->rtb_Gain1_idx_1,
    0.24072846668, -0.24072846668, localDW->AddConstant[0], localDW->
    AddConstant[1], localDW->AddConstant[2], localDW->AddConstant[3],
    rty_TVS_Output[0], rty_TVS_Output[1], rty_TVS_Output[2], rty_TVS_Output[3],
    &localDW->rtb_Gain1_idx_3, &localDW->CCaller_o3, &localDW->Square1,
    &localDW->avg_steering_angle, 0.2);

  /* Switch: '<S6>/Switch' incorporates:
   *  Bias: '<S6>/Add Constant3'
   */
  if (*rty_TVS_Output_j > 2) {
    rty_TVS_Output[0] = localDW->rtb_Gain1_idx_3;
    rty_TVS_Output[1] = localDW->CCaller_o3;
    rty_TVS_Output[2] = localDW->Square1;
    rty_TVS_Output[3] = localDW->avg_steering_angle;
  } else {
    /* Outputs for Atomic SubSystem: '<S2>/Torque Vectoring Micro Controller' */
    /* Bias: '<S6>/Add Constant3' incorporates:
     *  Gain: '<S6>/Gain'
     *  SignalConversion generated from: '<S4>/driver_input'
     */
    localDW->rtb_Gain1_idx_0 = 0.0 * rtu_TVS_Input_b + 25.0;

    /* End of Outputs for SubSystem: '<S2>/Torque Vectoring Micro Controller' */
    rty_TVS_Output[0] = localDW->rtb_Gain1_idx_0;
    rty_TVS_Output[1] = localDW->rtb_Gain1_idx_0;

    /* Outputs for Atomic SubSystem: '<S2>/Torque Vectoring Micro Controller' */
    /* Bias: '<S6>/Add Constant3' incorporates:
     *  Gain: '<S6>/Gain'
     *  SignalConversion generated from: '<S4>/driver_input'
     */
    localDW->rtb_Gain1_idx_0 = 25.0 * rtu_TVS_Input_b + 25.0;

    /* End of Outputs for SubSystem: '<S2>/Torque Vectoring Micro Controller' */
    rty_TVS_Output[2] = localDW->rtb_Gain1_idx_0;
    rty_TVS_Output[3] = localDW->rtb_Gain1_idx_0;
  }

  /* End of Switch: '<S6>/Switch' */

  /* Bias: '<S6>/Add Constant2' */
  rty_TVS_Output[0] += -25.0;
  rty_TVS_Output[1] += -25.0;
  rty_TVS_Output[2] += -25.0;
  rty_TVS_Output[3] += -25.0;

  /* DeadZone: '<S6>/Dead Zone' */
  if (rty_TVS_Output[0] > 0.02) {
    rty_TVS_Output[0] -= 0.02;
  } else if (rty_TVS_Output[0] >= -0.02) {
    rty_TVS_Output[0] = 0.0;
  } else {
    rty_TVS_Output[0] -= -0.02;
  }

  if (rty_TVS_Output[1] > 0.02) {
    rty_TVS_Output[1] -= 0.02;
  } else if (rty_TVS_Output[1] >= -0.02) {
    rty_TVS_Output[1] = 0.0;
  } else {
    rty_TVS_Output[1] -= -0.02;
  }

  if (rty_TVS_Output[2] > 0.02) {
    rty_TVS_Output[2] -= 0.02;
  } else if (rty_TVS_Output[2] >= -0.02) {
    rty_TVS_Output[2] = 0.0;
  } else {
    rty_TVS_Output[2] -= -0.02;
  }

  if (rty_TVS_Output[3] > 0.02) {
    rty_TVS_Output[3] -= 0.02;
  } else if (rty_TVS_Output[3] >= -0.02) {
    rty_TVS_Output[3] = 0.0;
  } else {
    rty_TVS_Output[3] -= -0.02;
  }

  /* End of DeadZone: '<S6>/Dead Zone' */

  /* RateLimiter: '<S6>/Rate Limiter' */
  localDW->AddConstant[0] = rty_TVS_Output[0] - localDW->PrevY[0];
  localDW->AddConstant[1] = rty_TVS_Output[1] - localDW->PrevY[1];
  localDW->AddConstant[2] = rty_TVS_Output[2] - localDW->PrevY[2];
  localDW->AddConstant[3] = rty_TVS_Output[3] - localDW->PrevY[3];
  if (localDW->AddConstant[0] > 1.875) {
    localDW->avg_steering_angle = localDW->PrevY[0] + 1.875;
  } else if (localDW->AddConstant[0] < -4.5) {
    localDW->avg_steering_angle = localDW->PrevY[0] + -4.5;
  } else {
    localDW->avg_steering_angle = rty_TVS_Output[0];
  }

  rty_TVS_Output[0] = localDW->avg_steering_angle;
  if (localDW->AddConstant[1] > 1.875) {
    localDW->avg_steering_angle = localDW->PrevY[1] + 1.875;
  } else if (localDW->AddConstant[1] < -4.5) {
    localDW->avg_steering_angle = localDW->PrevY[1] + -4.5;
  } else {
    localDW->avg_steering_angle = rty_TVS_Output[1];
  }

  rty_TVS_Output[1] = localDW->avg_steering_angle;
  if (localDW->AddConstant[2] > 1.875) {
    localDW->avg_steering_angle = localDW->PrevY[2] + 1.875;
  } else if (localDW->AddConstant[2] < -4.5) {
    localDW->avg_steering_angle = localDW->PrevY[2] + -4.5;
  } else {
    localDW->avg_steering_angle = rty_TVS_Output[2];
  }

  rty_TVS_Output[2] = localDW->avg_steering_angle;
  if (localDW->AddConstant[3] > 1.875) {
    localDW->avg_steering_angle = localDW->PrevY[3] + 1.875;
  } else if (localDW->AddConstant[3] < -4.5) {
    localDW->avg_steering_angle = localDW->PrevY[3] + -4.5;
  } else {
    localDW->avg_steering_angle = rty_TVS_Output[3];
  }

  rty_TVS_Output[3] = localDW->avg_steering_angle;
  localDW->PrevY[0] = rty_TVS_Output[0];
  localDW->PrevY[1] = rty_TVS_Output[1];
  localDW->PrevY[2] = rty_TVS_Output[2];
  localDW->PrevY[3] = rty_TVS_Output[3];

  /* End of RateLimiter: '<S6>/Rate Limiter' */

  /* Update for UnitDelay: '<S2>/Unit Delay' */
  localDW->UnitDelay_DSTATE[0] = rty_TVS_Output[0];
  localDW->UnitDelay_DSTATE[1] = rty_TVS_Output[1];
  localDW->UnitDelay_DSTATE[2] = rty_TVS_Output[2];
  localDW->UnitDelay_DSTATE[3] = rty_TVS_Output[3];

  /* End of Outputs for SubSystem: '<S1>/Fixed Point Sub' */
}

/* Model step function */
void Electronics_step(RT_MODEL *const rtM, ExtU *rtU, ExtY *rtY)
{
  DW *rtDW = rtM->dwork;

  /* Outputs for Atomic SubSystem: '<Root>/Electronics' */

  /* Inport: '<Root>/omega' incorporates:
   *  Inport: '<Root>/ang_vel'
   *  Inport: '<Root>/driver_input'
   *  Inport: '<Root>/motor_temperature'
   *  Inport: '<Root>/power_limits'
   *  Inport: '<Root>/steering_angle'
   *  Inport: '<Root>/vel'
   *  Outport: '<Root>/Control_Signal'
   *  Outport: '<Root>/Tx'
   *  Outport: '<Root>/b'
   *  Outport: '<Root>/beq'
   *  Outport: '<Root>/bigM_flag'
   *  Outport: '<Root>/lb'
   *  Outport: '<Root>/ref_yaw'
   *  Outport: '<Root>/reset'
   *  Outport: '<Root>/ub'
   *  Outport: '<Root>/windup'
   */
  Electronics_o(rtU->omega, rtU->motor_temperature, rtU->vel,
                rtU->steering_angle, rtU->driver_input, rtU->ang_vel,
                rtU->power_limits, rtY->Tx, &rtY->bigM_flag,
                &rtY->Control_Signal, &rtY->windup, &rtY->reset, &rtY->ref_yaw,
                rtY->ub, rtY->lb, &rtY->b, &rtY->beq, &rtDW->Electronics_o4);

  /* End of Outputs for SubSystem: '<Root>/Electronics' */
}

/* Model initialize function */
void Electronics_initialize(RT_MODEL *const rtM, ExtY *rtY)
{
  DW *rtDW = rtM->dwork;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* SystemInitialize for Atomic SubSystem: '<Root>/Electronics' */
  Electronics_Init(&rtDW->Electronics_o4);

  /* End of SystemInitialize for SubSystem: '<Root>/Electronics' */

  /* ConstCode for Outport: '<Root>/obj_gain' */
  rtY->obj_gain[0] = 29.074435549999997;
  rtY->obj_gain[1] = 29.074435549999997;
  rtY->obj_gain[2] = 29.07255;
  rtY->obj_gain[3] = 29.07255;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
