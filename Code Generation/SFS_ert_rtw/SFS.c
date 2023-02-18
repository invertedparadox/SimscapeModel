/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SFS.c
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

#include "SFS.h"
#include "rtwtypes.h"
#include <string.h>
#include <math.h>
#include <float.h>
#include <stddef.h>
#define NumBitsPerChar                 8U

extern real_T rt_remd_snf(real_T u0, real_T u1);
extern real_T rt_modd_snf(real_T u0, real_T u1);

/* Forward declaration for local functions */
static void BasicEKF_repairQuaternion(const insfilterAsync *obj, real_T x[28]);
static void BasicEKF_correctEqn(const insfilterAsync *obj, real_T x[28], real_T
  P_0[784], const real_T h[3], const real_T H[84], const real_T z[3], const
  real_T R[9], real_T innov[3], real_T innovCov[9], DW *rtDW);
static void AsyncMARGGPSFuserBase_fuseaccel(insfilterAsync *obj, const real_T
  accel[3], real_T Raccel, DW *rtDW);
static void cosd(real_T *x);
static void sind(real_T *x);
static void lla2ecef(const real_T llaPos[3], real_T ecefPos[3]);
static void AsyncMARGGPSFuserBase_fusegps(insfilterAsync *obj, const real_T lla
  [3], real_T Rpos, const real_T vel[3], real_T Rvel, DW *rtDW);
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

/* Function for MATLAB Function: '<S1>/MATLAB Function' */
static void BasicEKF_repairQuaternion(const insfilterAsync *obj, real_T x[28])
{
  real_T n;
  real_T n_tmp;
  real_T n_tmp_0;
  real_T n_tmp_1;
  real_T qparts_idx_0;
  qparts_idx_0 = x[(int32_T)obj->OrientationIdx[0] - 1];
  n_tmp = x[(int32_T)obj->OrientationIdx[1] - 1];
  n_tmp_0 = x[(int32_T)obj->OrientationIdx[2] - 1];
  n_tmp_1 = x[(int32_T)obj->OrientationIdx[3] - 1];
  n = sqrt(((qparts_idx_0 * qparts_idx_0 + n_tmp * n_tmp) + n_tmp_0 * n_tmp_0) +
           n_tmp_1 * n_tmp_1);
  qparts_idx_0 /= n;
  if (qparts_idx_0 < 0.0) {
    x[(int32_T)obj->OrientationIdx[0] - 1] = -qparts_idx_0;
    x[(int32_T)obj->OrientationIdx[1] - 1] = -(n_tmp / n);
    x[(int32_T)obj->OrientationIdx[2] - 1] = -(n_tmp_0 / n);
    x[(int32_T)obj->OrientationIdx[3] - 1] = -(n_tmp_1 / n);
  } else {
    x[(int32_T)obj->OrientationIdx[0] - 1] = qparts_idx_0;
    x[(int32_T)obj->OrientationIdx[1] - 1] = n_tmp / n;
    x[(int32_T)obj->OrientationIdx[2] - 1] = n_tmp_0 / n;
    x[(int32_T)obj->OrientationIdx[3] - 1] = n_tmp_1 / n;
  }
}

/* Function for MATLAB Function: '<S1>/MATLAB Function' */
static void BasicEKF_correctEqn(const insfilterAsync *obj, real_T x[28], real_T
  P_0[784], const real_T h[3], const real_T H[84], const real_T z[3], const
  real_T R[9], real_T innov[3], real_T innovCov[9], DW *rtDW)
{
  real_T B_0[84];
  real_T H_0[84];
  real_T W[84];
  real_T A[9];
  real_T a21;
  real_T maxval;
  int32_T W_tmp;
  int32_T W_tmp_0;
  int32_T W_tmp_1;
  int32_T r1;
  int32_T r2;
  int32_T r3;
  int32_T rtemp;
  for (W_tmp_0 = 0; W_tmp_0 < 3; W_tmp_0++) {
    for (W_tmp_1 = 0; W_tmp_1 < 28; W_tmp_1++) {
      W_tmp = 3 * W_tmp_1 + W_tmp_0;
      W[W_tmp_1 + 28 * W_tmp_0] = H[W_tmp];
      H_0[W_tmp] = 0.0;
      for (rtemp = 0; rtemp < 28; rtemp++) {
        H_0[W_tmp] += H[3 * rtemp + W_tmp_0] * P_0[28 * W_tmp_1 + rtemp];
      }
    }
  }

  for (W_tmp_0 = 0; W_tmp_0 < 3; W_tmp_0++) {
    for (W_tmp_1 = 0; W_tmp_1 < 3; W_tmp_1++) {
      maxval = 0.0;
      for (rtemp = 0; rtemp < 28; rtemp++) {
        maxval += H_0[3 * rtemp + W_tmp_0] * W[28 * W_tmp_1 + rtemp];
      }

      rtemp = 3 * W_tmp_1 + W_tmp_0;
      innovCov[rtemp] = R[rtemp] + maxval;
    }

    innov[W_tmp_0] = z[W_tmp_0] - h[W_tmp_0];
    for (W_tmp_1 = 0; W_tmp_1 < 28; W_tmp_1++) {
      W_tmp = 28 * W_tmp_0 + W_tmp_1;
      B_0[W_tmp] = 0.0;
      for (rtemp = 0; rtemp < 28; rtemp++) {
        B_0[W_tmp] += P_0[28 * rtemp + W_tmp_1] * W[28 * W_tmp_0 + rtemp];
      }
    }
  }

  memcpy(&A[0], &innovCov[0], 9U * sizeof(real_T));
  r1 = 0;
  r2 = 1;
  r3 = 2;
  maxval = fabs(innovCov[0]);
  a21 = fabs(innovCov[1]);
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    r2 = 0;
  }

  if (fabs(innovCov[2]) > maxval) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }

  A[r2] = innovCov[r2] / innovCov[r1];
  A[r3] /= A[r1];
  A[r2 + 3] -= A[r1 + 3] * A[r2];
  A[r3 + 3] -= A[r1 + 3] * A[r3];
  A[r2 + 6] -= A[r1 + 6] * A[r2];
  A[r3 + 6] -= A[r1 + 6] * A[r3];
  if (fabs(A[r3 + 3]) > fabs(A[r2 + 3])) {
    rtemp = r2;
    r2 = r3;
    r3 = rtemp;
  }

  A[r3 + 3] /= A[r2 + 3];
  A[r3 + 6] -= A[r3 + 3] * A[r2 + 6];
  for (rtemp = 0; rtemp < 28; rtemp++) {
    W_tmp = 28 * r1 + rtemp;
    W[W_tmp] = B_0[rtemp] / A[r1];
    W_tmp_0 = 28 * r2 + rtemp;
    W[W_tmp_0] = B_0[rtemp + 28] - A[r1 + 3] * W[W_tmp];
    W_tmp_1 = 28 * r3 + rtemp;
    W[W_tmp_1] = B_0[rtemp + 56] - A[r1 + 6] * W[W_tmp];
    W[W_tmp_0] /= A[r2 + 3];
    W[W_tmp_1] -= A[r2 + 6] * W[W_tmp_0];
    W[W_tmp_1] /= A[r3 + 6];
    W[W_tmp_0] -= A[r3 + 3] * W[W_tmp_1];
    W[W_tmp] -= W[W_tmp_1] * A[r3];
    W[W_tmp] -= W[W_tmp_0] * A[r2];
    for (W_tmp_0 = 0; W_tmp_0 < 28; W_tmp_0++) {
      W_tmp = 28 * W_tmp_0 + rtemp;
      rtDW->W[W_tmp] = 0.0;
      rtDW->W[W_tmp] += H[3 * W_tmp_0] * W[rtemp];
      rtDW->W[W_tmp] += H[3 * W_tmp_0 + 1] * W[rtemp + 28];
      rtDW->W[W_tmp] += H[3 * W_tmp_0 + 2] * W[rtemp + 56];
    }

    for (W_tmp_0 = 0; W_tmp_0 < 28; W_tmp_0++) {
      maxval = 0.0;
      for (W_tmp_1 = 0; W_tmp_1 < 28; W_tmp_1++) {
        maxval += rtDW->W[28 * W_tmp_1 + rtemp] * P_0[28 * W_tmp_0 + W_tmp_1];
      }

      W_tmp_1 = 28 * W_tmp_0 + rtemp;
      rtDW->P_k[W_tmp_1] = P_0[W_tmp_1] - maxval;
    }
  }

  memcpy(&P_0[0], &rtDW->P_k[0], 784U * sizeof(real_T));
  for (W_tmp_0 = 0; W_tmp_0 < 28; W_tmp_0++) {
    x[W_tmp_0] += (W[W_tmp_0 + 28] * innov[1] + W[W_tmp_0] * innov[0]) +
      W[W_tmp_0 + 56] * innov[2];
  }

  BasicEKF_repairQuaternion(obj, x);
}

/* Function for MATLAB Function: '<S1>/MATLAB Function' */
static void AsyncMARGGPSFuserBase_fuseaccel(insfilterAsync *obj, const real_T
  accel[3], real_T Raccel, DW *rtDW)
{
  real_T tmp[84];
  real_T val[28];
  real_T measNoise[9];
  real_T resCov[9];
  real_T obj_0[3];
  real_T res[3];
  real_T obj_tmp;
  real_T obj_tmp_0;
  real_T obj_tmp_1;
  real_T obj_tmp_2;
  real_T obj_tmp_3;
  real_T obj_tmp_4;
  real_T obj_tmp_5;
  real_T obj_tmp_6;
  real_T obj_tmp_7;
  real_T obj_tmp_8;
  real_T obj_tmp_9;
  real_T obj_tmp_a;
  real_T tmp_0;
  real_T tmp_1;
  real_T tmp_2;
  real_T tmp_3;
  real_T tmp_4;
  real_T tmp_5;
  real_T tmp_6;
  real_T tmp_7;
  real_T tmp_8;
  real_T tmp_9;
  memset(&measNoise[0], 0, 9U * sizeof(real_T));
  measNoise[0] = Raccel;
  measNoise[4] = Raccel;
  measNoise[8] = Raccel;
  memcpy(&rtDW->P_m[0], &obj->pStateCovariance[0], 784U * sizeof(real_T));
  memcpy(&val[0], &obj->pState[0], 28U * sizeof(real_T));
  obj_tmp = obj->pState[0] * obj->pState[0];
  obj_tmp_0 = obj->pState[1] * obj->pState[1];
  obj_tmp_1 = obj->pState[2] * obj->pState[2];
  obj_tmp_2 = obj->pState[3] * obj->pState[3];
  obj_tmp_3 = 2.0 * obj->pState[0] * obj->pState[3];
  obj_tmp_4 = 2.0 * obj->pState[1] * obj->pState[2];
  obj_tmp_8 = 2.0 * obj->pState[0] * obj->pState[2];
  obj_tmp_9 = 2.0 * obj->pState[1] * obj->pState[3];
  obj_tmp_a = obj_tmp_8 - obj_tmp_9;
  obj_0[0] = ((obj->pState[16] - (((obj_tmp + obj_tmp_0) - obj_tmp_1) -
    obj_tmp_2) * obj->pState[13]) + (obj->pState[15] - 9.81) * obj_tmp_a) -
    (obj_tmp_3 + obj_tmp_4) * obj->pState[14];
  obj_tmp_5 = obj_tmp - obj_tmp_0;
  obj_tmp_6 = 2.0 * obj->pState[0] * obj->pState[1];
  obj_tmp_7 = 2.0 * obj->pState[2] * obj->pState[3];
  obj_tmp_3 -= obj_tmp_4;
  obj_0[1] = ((obj->pState[17] - ((obj_tmp_5 + obj_tmp_1) - obj_tmp_2) *
               obj->pState[14]) - (obj_tmp_6 + obj_tmp_7) * (obj->pState[15] -
    9.81)) + obj_tmp_3 * obj->pState[13];
  obj_tmp_6 -= obj_tmp_7;
  obj_0[2] = ((obj->pState[18] - ((obj_tmp_5 - obj_tmp_1) + obj_tmp_2) *
               (obj->pState[15] - 9.81)) + obj_tmp_6 * obj->pState[14]) -
    (obj_tmp_8 + obj_tmp_9) * obj->pState[13];
  obj_tmp_8 = 2.0 * obj->pState[3] * obj->pState[14];
  obj_tmp_5 = 2.0 * obj->pState[2] * (obj->pState[15] - 9.81);
  tmp_5 = 2.0 * obj->pState[0] * obj->pState[13];
  tmp_9 = (obj_tmp_5 - obj_tmp_8) - tmp_5;
  tmp[0] = tmp_9;
  tmp_4 = (-2.0 * obj->pState[3] * (obj->pState[15] - 9.81) - 2.0 * obj->pState
           [2] * obj->pState[14]) - 2.0 * obj->pState[1] * obj->pState[13];
  tmp[3] = tmp_4;
  tmp_1 = 2.0 * obj->pState[1] * obj->pState[14];
  tmp_2 = 2.0 * obj->pState[0] * (obj->pState[15] - 9.81);
  tmp_3 = 2.0 * obj->pState[2] * obj->pState[13];
  tmp[6] = (tmp_2 - tmp_1) + tmp_3;
  tmp_6 = 2.0 * obj->pState[1] * (obj->pState[15] - 9.81);
  tmp_7 = 2.0 * obj->pState[0] * obj->pState[14];
  tmp_8 = 2.0 * obj->pState[3] * obj->pState[13];
  tmp_0 = (tmp_8 - tmp_7) - tmp_6;
  tmp[9] = tmp_0;
  tmp[12] = 0.0;
  tmp[15] = 0.0;
  tmp[18] = 0.0;
  tmp[21] = 0.0;
  tmp[24] = 0.0;
  tmp[27] = 0.0;
  tmp[30] = 0.0;
  tmp[33] = 0.0;
  tmp[36] = 0.0;
  tmp[39] = ((-obj_tmp - obj_tmp_0) + obj_tmp_1) + obj_tmp_2;
  tmp[42] = -2.0 * obj->pState[0] * obj->pState[3] - obj_tmp_4;
  tmp[45] = obj_tmp_a;
  tmp[48] = 1.0;
  tmp[51] = 0.0;
  tmp[54] = 0.0;
  tmp[57] = 0.0;
  tmp[60] = 0.0;
  tmp[63] = 0.0;
  tmp[66] = 0.0;
  tmp[69] = 0.0;
  tmp[72] = 0.0;
  tmp[75] = 0.0;
  tmp[78] = 0.0;
  tmp[81] = 0.0;
  tmp[1] = tmp_0;
  tmp_1 = (tmp_1 - tmp_2) - tmp_3;
  tmp[4] = tmp_1;
  tmp[7] = tmp_4;
  tmp[10] = (obj_tmp_8 - obj_tmp_5) + tmp_5;
  tmp[13] = 0.0;
  tmp[16] = 0.0;
  tmp[19] = 0.0;
  tmp[22] = 0.0;
  tmp[25] = 0.0;
  tmp[28] = 0.0;
  tmp[31] = 0.0;
  tmp[34] = 0.0;
  tmp[37] = 0.0;
  tmp[40] = obj_tmp_3;
  obj_tmp_8 = -obj_tmp + obj_tmp_0;
  tmp[43] = (obj_tmp_8 - obj_tmp_1) + obj_tmp_2;
  tmp[46] = -2.0 * obj->pState[0] * obj->pState[1] - obj_tmp_7;
  tmp[49] = 0.0;
  tmp[52] = 1.0;
  tmp[55] = 0.0;
  tmp[58] = 0.0;
  tmp[61] = 0.0;
  tmp[64] = 0.0;
  tmp[67] = 0.0;
  tmp[70] = 0.0;
  tmp[73] = 0.0;
  tmp[76] = 0.0;
  tmp[79] = 0.0;
  tmp[82] = 0.0;
  tmp[2] = tmp_1;
  tmp[5] = (tmp_6 + tmp_7) - tmp_8;
  tmp[8] = tmp_9;
  tmp[11] = tmp_4;
  tmp[14] = 0.0;
  tmp[17] = 0.0;
  tmp[20] = 0.0;
  tmp[23] = 0.0;
  tmp[26] = 0.0;
  tmp[29] = 0.0;
  tmp[32] = 0.0;
  tmp[35] = 0.0;
  tmp[38] = 0.0;
  tmp[41] = -2.0 * obj->pState[0] * obj->pState[2] - obj_tmp_9;
  tmp[44] = obj_tmp_6;
  tmp[47] = (obj_tmp_8 + obj_tmp_1) - obj_tmp_2;
  tmp[50] = 0.0;
  tmp[53] = 0.0;
  tmp[56] = 1.0;
  tmp[59] = 0.0;
  tmp[62] = 0.0;
  tmp[65] = 0.0;
  tmp[68] = 0.0;
  tmp[71] = 0.0;
  tmp[74] = 0.0;
  tmp[77] = 0.0;
  tmp[80] = 0.0;
  tmp[83] = 0.0;
  BasicEKF_correctEqn(obj, val, rtDW->P_m, obj_0, tmp, accel, measNoise, res,
                      resCov, rtDW);
  memcpy(&obj->pStateCovariance[0], &rtDW->P_m[0], 784U * sizeof(real_T));
  memcpy(&obj->pState[0], &val[0], 28U * sizeof(real_T));
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else if ((u1 != 0.0) && (u1 != trunc(u1))) {
    real_T q;
    q = fabs(u0 / u1);
    if (!(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q)) {
      y = 0.0 * u0;
    } else {
      y = fmod(u0, u1);
    }
  } else {
    y = fmod(u0, u1);
  }

  return y;
}

/* Function for MATLAB Function: '<S1>/MATLAB Function' */
static void cosd(real_T *x)
{
  if (rtIsInf(*x) || rtIsNaN(*x)) {
    *x = (rtNaN);
  } else {
    real_T absx;
    real_T b_x;
    int8_T n;
    b_x = rt_remd_snf(*x, 360.0);
    absx = fabs(b_x);
    if (absx > 180.0) {
      if (b_x > 0.0) {
        b_x -= 360.0;
      } else {
        b_x += 360.0;
      }

      absx = fabs(b_x);
    }

    if (absx <= 45.0) {
      b_x *= 0.017453292519943295;
      n = 0;
    } else if (absx <= 135.0) {
      if (b_x > 0.0) {
        b_x = (b_x - 90.0) * 0.017453292519943295;
        n = 1;
      } else {
        b_x = (b_x + 90.0) * 0.017453292519943295;
        n = -1;
      }
    } else if (b_x > 0.0) {
      b_x = (b_x - 180.0) * 0.017453292519943295;
      n = 2;
    } else {
      b_x = (b_x + 180.0) * 0.017453292519943295;
      n = -2;
    }

    switch (n) {
     case 0:
      *x = cos(b_x);
      break;

     case 1:
      *x = -sin(b_x);
      break;

     case -1:
      *x = sin(b_x);
      break;

     default:
      *x = -cos(b_x);
      break;
    }
  }
}

/* Function for MATLAB Function: '<S1>/MATLAB Function' */
static void sind(real_T *x)
{
  if (rtIsInf(*x) || rtIsNaN(*x)) {
    *x = (rtNaN);
  } else {
    real_T absx;
    real_T b_x;
    int8_T n;
    b_x = rt_remd_snf(*x, 360.0);
    absx = fabs(b_x);
    if (absx > 180.0) {
      if (b_x > 0.0) {
        b_x -= 360.0;
      } else {
        b_x += 360.0;
      }

      absx = fabs(b_x);
    }

    if (absx <= 45.0) {
      b_x *= 0.017453292519943295;
      n = 0;
    } else if (absx <= 135.0) {
      if (b_x > 0.0) {
        b_x = (b_x - 90.0) * 0.017453292519943295;
        n = 1;
      } else {
        b_x = (b_x + 90.0) * 0.017453292519943295;
        n = -1;
      }
    } else if (b_x > 0.0) {
      b_x = (b_x - 180.0) * 0.017453292519943295;
      n = 2;
    } else {
      b_x = (b_x + 180.0) * 0.017453292519943295;
      n = -2;
    }

    switch (n) {
     case 0:
      *x = sin(b_x);
      break;

     case 1:
      *x = cos(b_x);
      break;

     case -1:
      *x = -cos(b_x);
      break;

     default:
      *x = -sin(b_x);
      break;
    }
  }
}

/* Function for MATLAB Function: '<S1>/MATLAB Function' */
static void lla2ecef(const real_T llaPos[3], real_T ecefPos[3])
{
  real_T N;
  real_T b;
  real_T c;
  real_T d;
  real_T sinphi;
  sinphi = llaPos[0];
  sind(&sinphi);
  N = 6.378137E+6 / sqrt(1.0 - sinphi * sinphi * 0.0066943799901413165);
  b = llaPos[0];
  cosd(&b);
  b *= N + llaPos[2];
  c = llaPos[1];
  cosd(&c);
  d = llaPos[1];
  sind(&d);
  ecefPos[0] = b * c;
  ecefPos[1] = b * d;
  ecefPos[2] = (N * 0.99330562000985867 + llaPos[2]) * sinphi;
}

/* Function for MATLAB Function: '<S1>/MATLAB Function' */
static void AsyncMARGGPSFuserBase_fusegps(insfilterAsync *obj, const real_T lla
  [3], real_T Rpos, const real_T vel[3], real_T Rvel, DW *rtDW)
{
  real_T A_tmp[168];
  real_T X_0[168];
  real_T A[36];
  real_T R[36];
  real_T val[28];
  real_T varargin_1[9];
  real_T varargin_2[9];
  real_T obj_0[6];
  real_T pos[6];
  real_T pos_0[6];
  real_T tmp_0[3];
  real_T tmp_1[3];
  real_T coslambda;
  real_T cosphi;
  real_T ecefPosWithENUOrigin_idx_0;
  real_T ecefPosWithENUOrigin_idx_1;
  real_T ecefPosWithENUOrigin_idx_2;
  real_T sinlambda;
  real_T sinphi;
  int32_T b_ix;
  int32_T i;
  int32_T ix;
  int32_T iy;
  int32_T j;
  int32_T jj;
  int32_T jp;
  int8_T ipiv[6];
  static const int8_T e[168] = { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T H[168] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  const int8_T *A_tmp_0;
  const int8_T *X_tmp;
  memset(&varargin_1[0], 0, 9U * sizeof(real_T));
  varargin_1[0] = Rpos;
  varargin_1[4] = Rpos;
  varargin_1[8] = Rpos;
  memset(&varargin_2[0], 0, 9U * sizeof(real_T));
  varargin_2[0] = Rvel;
  varargin_2[4] = Rvel;
  varargin_2[8] = Rvel;
  memset(&R[0], 0, 36U * sizeof(real_T));
  for (j = 0; j < 3; j++) {
    R[6 * j] = varargin_1[3 * j];
    i = (j + 3) * 6;
    R[i + 3] = varargin_2[3 * j];
    jj = 3 * j + 1;
    R[6 * j + 1] = varargin_1[jj];
    R[i + 4] = varargin_2[jj];
    jj = 3 * j + 2;
    R[6 * j + 2] = varargin_1[jj];
    R[i + 5] = varargin_2[jj];
  }

  real_T tmp;
  cosphi = obj->ReferenceLocation[0];
  cosd(&cosphi);
  sinphi = obj->ReferenceLocation[0];
  sind(&sinphi);
  coslambda = obj->ReferenceLocation[1];
  cosd(&coslambda);
  sinlambda = obj->ReferenceLocation[1];
  sind(&sinlambda);
  lla2ecef(lla, tmp_0);
  lla2ecef(obj->ReferenceLocation, tmp_1);
  ecefPosWithENUOrigin_idx_0 = tmp_0[0] - tmp_1[0];
  ecefPosWithENUOrigin_idx_1 = tmp_0[1] - tmp_1[1];
  ecefPosWithENUOrigin_idx_2 = tmp_0[2] - tmp_1[2];
  tmp = coslambda * ecefPosWithENUOrigin_idx_0 + sinlambda *
    ecefPosWithENUOrigin_idx_1;
  pos[0] = -sinphi * tmp + cosphi * ecefPosWithENUOrigin_idx_2;
  ecefPosWithENUOrigin_idx_2 = cosphi * tmp + sinphi *
    ecefPosWithENUOrigin_idx_2;
  X_tmp = &e[0];
  for (j = 0; j < 6; j++) {
    for (jj = 0; jj < 28; jj++) {
      i = 28 * j + jj;
      X_0[i] = 0.0;
      for (iy = 0; iy < 28; iy++) {
        X_0[i] += obj->pStateCovariance[28 * iy + jj] * (real_T)X_tmp[28 * j +
          iy];
      }
    }
  }

  A_tmp_0 = &H[0];
  for (j = 0; j < 6; j++) {
    for (jj = 0; jj < 28; jj++) {
      i = 6 * jj + j;
      A_tmp[i] = 0.0;
      for (iy = 0; iy < 28; iy++) {
        A_tmp[i] += (real_T)A_tmp_0[6 * iy + j] * obj->pStateCovariance[28 * jj
          + iy];
      }
    }

    for (jj = 0; jj < 6; jj++) {
      cosphi = 0.0;
      for (iy = 0; iy < 28; iy++) {
        cosphi += A_tmp[6 * iy + j] * (real_T)X_tmp[28 * jj + iy];
      }

      i = 6 * jj + j;
      A[i] = R[i] + cosphi;
    }

    ipiv[j] = (int8_T)(j + 1);
  }

  for (j = 0; j < 5; j++) {
    jj = j * 7;
    iy = 6 - j;
    b_ix = 0;
    cosphi = fabs(A[jj]);
    for (jp = 2; jp <= iy; jp++) {
      sinphi = fabs(A[(jj + jp) - 1]);
      if (sinphi > cosphi) {
        b_ix = jp - 1;
        cosphi = sinphi;
      }
    }

    if (A[jj + b_ix] != 0.0) {
      if (b_ix != 0) {
        iy = j + b_ix;
        ipiv[j] = (int8_T)(iy + 1);
        b_ix = j;
        for (jp = 0; jp < 6; jp++) {
          cosphi = A[b_ix];
          A[b_ix] = A[iy];
          A[iy] = cosphi;
          b_ix += 6;
          iy += 6;
        }
      }

      iy = (jj - j) + 6;
      for (jp = jj + 2; jp <= iy; jp++) {
        A[jp - 1] /= A[jj];
      }
    }

    b_ix = 4 - j;
    ix = jj + 8;
    for (jp = 0; jp <= b_ix; jp++) {
      cosphi = A[(jp * 6 + jj) + 6];
      if (cosphi != 0.0) {
        i = (ix - j) + 4;
        for (iy = ix; iy <= i; iy++) {
          A[iy - 1] += A[((jj + iy) - ix) + 1] * -cosphi;
        }
      }

      ix += 6;
    }
  }

  for (j = 0; j < 6; j++) {
    jj = 28 * j;
    b_ix = 6 * j;
    for (jp = 0; jp < j; jp++) {
      ix = 28 * jp;
      cosphi = A[jp + b_ix];
      if (cosphi != 0.0) {
        for (iy = 0; iy < 28; iy++) {
          i = iy + jj;
          X_0[i] -= X_0[iy + ix] * cosphi;
        }
      }
    }

    cosphi = 1.0 / A[j + b_ix];
    for (jp = 0; jp < 28; jp++) {
      i = jp + jj;
      X_0[i] *= cosphi;
    }
  }

  for (j = 5; j >= 0; j--) {
    iy = 28 * j;
    b_ix = 6 * j - 1;
    for (jj = j + 2; jj < 7; jj++) {
      ix = (jj - 1) * 28;
      if (A[jj + b_ix] != 0.0) {
        for (jp = 0; jp < 28; jp++) {
          i = jp + iy;
          X_0[i] -= A[jj + b_ix] * X_0[jp + ix];
        }
      }
    }
  }

  for (j = 4; j >= 0; j--) {
    int8_T ipiv_0;
    ipiv_0 = ipiv[j];
    if (j + 1 != ipiv_0) {
      for (jj = 0; jj < 28; jj++) {
        iy = 28 * j + jj;
        cosphi = X_0[iy];
        i = (ipiv_0 - 1) * 28 + jj;
        X_0[iy] = X_0[i];
        X_0[i] = cosphi;
      }
    }
  }

  pos[3] = vel[0];
  pos[1] = -sinlambda * ecefPosWithENUOrigin_idx_0 + coslambda *
    ecefPosWithENUOrigin_idx_1;
  pos[4] = vel[1];
  pos[2] = -ecefPosWithENUOrigin_idx_2;
  pos[5] = vel[2];
  obj_0[0] = obj->pState[7];
  obj_0[1] = obj->pState[8];
  obj_0[2] = obj->pState[9];
  obj_0[3] = obj->pState[10];
  obj_0[4] = obj->pState[11];
  obj_0[5] = obj->pState[12];
  for (j = 0; j < 6; j++) {
    pos_0[j] = pos[j] - obj_0[j];
  }

  for (j = 0; j < 28; j++) {
    cosphi = 0.0;
    for (jj = 0; jj < 6; jj++) {
      cosphi += X_0[28 * jj + j] * pos_0[jj];
    }

    val[j] = obj->pState[j] + cosphi;
  }

  BasicEKF_repairQuaternion(obj, val);
  for (j = 0; j < 28; j++) {
    for (jj = 0; jj < 28; jj++) {
      i = 28 * jj + j;
      rtDW->X_c[i] = 0.0;
      for (iy = 0; iy < 6; iy++) {
        rtDW->X_c[i] += X_0[28 * iy + j] * (real_T)A_tmp_0[6 * jj + iy];
      }
    }

    for (jj = 0; jj < 28; jj++) {
      cosphi = 0.0;
      for (iy = 0; iy < 28; iy++) {
        cosphi += rtDW->X_c[28 * iy + j] * obj->pStateCovariance[28 * jj + iy];
      }

      i = 28 * jj + j;
      rtDW->obj[i] = obj->pStateCovariance[i] - cosphi;
    }
  }

  memcpy(&obj->pStateCovariance[0], &rtDW->obj[0], 784U * sizeof(real_T));
  memcpy(&obj->pState[0], &val[0], 28U * sizeof(real_T));
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    boolean_T yEq;
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      real_T q;
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
    }
  }

  return y;
}

/* Model step function */
void SFS_step(RT_MODEL *const rtM, ExtU *rtU, ExtY *rtY)
{
  DW *rtDW = rtM->dwork;
  real_T tmp[84];
  real_T xk[28];
  real_T measNoise[9];
  real_T resCov[9];
  real_T filter[3];
  real_T res[3];
  real_T aasq;
  real_T ab2;
  real_T ac2;
  real_T ad2;
  real_T bc2;
  real_T bd2;
  real_T cd2;
  real_T dfdx_tmp;
  real_T dfdx_tmp_0;
  real_T n;
  int32_T i;
  int32_T i_0;
  int32_T i_1;
  static const real_T b[784] = { 0.001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001 };

  static const real_T i_2[28] = { 1.0E-6, 1.0E-6, 1.0E-6, 1.0E-6, 0.005, 0.005,
    0.005, 1.0E-6, 1.0E-6, 1.0E-6, 1.0E-6, 1.0E-6, 1.0E-6, 50.0, 50.0, 50.0,
    0.0001, 0.0001, 0.0001, 1.0E-10, 1.0E-10, 1.0E-10, 1.0E-6, 1.0E-6, 1.0E-6,
    0.1, 0.1, 0.1 };

  static const int8_T c[28] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T d[28] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T e[28] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T f[28] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T g[28] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T h[28] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const real_T k[84] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   *  UnitDelay: '<S1>/Unit Delay1'
   */
  rtDW->filter.QuaternionNoise[0] = 1.0E-6;
  rtDW->filter.QuaternionNoise[1] = 1.0E-6;
  rtDW->filter.QuaternionNoise[2] = 1.0E-6;
  rtDW->filter.QuaternionNoise[3] = 1.0E-6;
  rtDW->filter.AngularVelocityNoise[0] = 0.005;
  rtDW->filter.PositionNoise[0] = 1.0E-6;
  rtDW->filter.VelocityNoise[0] = 1.0E-6;
  rtDW->filter.AccelerationNoise[0] = 50.0;
  rtDW->filter.GyroscopeBiasNoise[0] = 1.0E-10;
  rtDW->filter.AccelerometerBiasNoise[0] = 0.0001;
  rtDW->filter.GeomagneticVectorNoise[0] = 1.0E-6;
  rtDW->filter.MagnetometerBiasNoise[0] = 0.1;
  rtDW->filter.AngularVelocityNoise[1] = 0.005;
  rtDW->filter.PositionNoise[1] = 1.0E-6;
  rtDW->filter.VelocityNoise[1] = 1.0E-6;
  rtDW->filter.AccelerationNoise[1] = 50.0;
  rtDW->filter.GyroscopeBiasNoise[1] = 1.0E-10;
  rtDW->filter.AccelerometerBiasNoise[1] = 0.0001;
  rtDW->filter.GeomagneticVectorNoise[1] = 1.0E-6;
  rtDW->filter.MagnetometerBiasNoise[1] = 0.1;
  rtDW->filter.AngularVelocityNoise[2] = 0.005;
  rtDW->filter.PositionNoise[2] = 1.0E-6;
  rtDW->filter.VelocityNoise[2] = 1.0E-6;
  rtDW->filter.AccelerationNoise[2] = 50.0;
  rtDW->filter.GyroscopeBiasNoise[2] = 1.0E-10;
  rtDW->filter.AccelerometerBiasNoise[2] = 0.0001;
  rtDW->filter.GeomagneticVectorNoise[2] = 1.0E-6;
  rtDW->filter.MagnetometerBiasNoise[2] = 0.1;
  rtDW->filter.ReferenceLocation[0] = 0.0;
  rtDW->filter.ReferenceLocation[1] = 0.0;
  rtDW->filter.ReferenceLocation[2] = 0.0;
  rtDW->filter.OrientationIdx[0] = 1.0;
  rtDW->filter.OrientationIdx[1] = 2.0;
  rtDW->filter.OrientationIdx[2] = 3.0;
  rtDW->filter.OrientationIdx[3] = 4.0;
  for (i = 0; i < 784; i++) {
    rtDW->filter.pStateCovariance[i] = b[i];
    rtDW->procNoise[i] = 0.0;
  }

  rtDW->Pdot[0] = 0.0;
  n = -rtDW->UnitDelay_DSTATE[4] / 2.0;
  rtDW->Pdot[28] = n;
  aasq = -rtDW->UnitDelay_DSTATE[5] / 2.0;
  rtDW->Pdot[56] = aasq;
  dfdx_tmp = -rtDW->UnitDelay_DSTATE[6] / 2.0;
  rtDW->Pdot[84] = dfdx_tmp;
  dfdx_tmp_0 = -rtDW->UnitDelay_DSTATE[1] / 2.0;
  rtDW->Pdot[112] = dfdx_tmp_0;
  ab2 = -rtDW->UnitDelay_DSTATE[2] / 2.0;
  rtDW->Pdot[140] = ab2;
  ac2 = -rtDW->UnitDelay_DSTATE[3] / 2.0;
  rtDW->Pdot[168] = ac2;
  rtDW->Pdot[196] = 0.0;
  rtDW->Pdot[224] = 0.0;
  rtDW->Pdot[252] = 0.0;
  rtDW->Pdot[280] = 0.0;
  rtDW->Pdot[308] = 0.0;
  rtDW->Pdot[336] = 0.0;
  rtDW->Pdot[364] = 0.0;
  rtDW->Pdot[392] = 0.0;
  rtDW->Pdot[420] = 0.0;
  rtDW->Pdot[448] = 0.0;
  rtDW->Pdot[476] = 0.0;
  rtDW->Pdot[504] = 0.0;
  rtDW->Pdot[532] = 0.0;
  rtDW->Pdot[560] = 0.0;
  rtDW->Pdot[588] = 0.0;
  rtDW->Pdot[616] = 0.0;
  rtDW->Pdot[644] = 0.0;
  rtDW->Pdot[672] = 0.0;
  rtDW->Pdot[700] = 0.0;
  rtDW->Pdot[728] = 0.0;
  rtDW->Pdot[756] = 0.0;
  rtDW->Pdot[1] = rtDW->UnitDelay_DSTATE[4] / 2.0;
  rtDW->Pdot[29] = 0.0;
  rtDW->Pdot[57] = rtDW->UnitDelay_DSTATE[6] / 2.0;
  rtDW->Pdot[85] = aasq;
  rtDW->Pdot[113] = rtDW->UnitDelay_DSTATE[0] / 2.0;
  rtDW->Pdot[141] = ac2;
  rtDW->Pdot[169] = rtDW->UnitDelay_DSTATE[2] / 2.0;
  rtDW->Pdot[197] = 0.0;
  rtDW->Pdot[225] = 0.0;
  rtDW->Pdot[253] = 0.0;
  rtDW->Pdot[281] = 0.0;
  rtDW->Pdot[309] = 0.0;
  rtDW->Pdot[337] = 0.0;
  rtDW->Pdot[365] = 0.0;
  rtDW->Pdot[393] = 0.0;
  rtDW->Pdot[421] = 0.0;
  rtDW->Pdot[449] = 0.0;
  rtDW->Pdot[477] = 0.0;
  rtDW->Pdot[505] = 0.0;
  rtDW->Pdot[533] = 0.0;
  rtDW->Pdot[561] = 0.0;
  rtDW->Pdot[589] = 0.0;
  rtDW->Pdot[617] = 0.0;
  rtDW->Pdot[645] = 0.0;
  rtDW->Pdot[673] = 0.0;
  rtDW->Pdot[701] = 0.0;
  rtDW->Pdot[729] = 0.0;
  rtDW->Pdot[757] = 0.0;
  rtDW->Pdot[2] = rtDW->UnitDelay_DSTATE[5] / 2.0;
  rtDW->Pdot[30] = dfdx_tmp;
  rtDW->Pdot[58] = 0.0;
  rtDW->Pdot[86] = rtDW->UnitDelay_DSTATE[4] / 2.0;
  rtDW->Pdot[114] = rtDW->UnitDelay_DSTATE[3] / 2.0;
  rtDW->Pdot[142] = rtDW->UnitDelay_DSTATE[0] / 2.0;
  rtDW->Pdot[170] = dfdx_tmp_0;
  rtDW->Pdot[198] = 0.0;
  rtDW->Pdot[226] = 0.0;
  rtDW->Pdot[254] = 0.0;
  rtDW->Pdot[282] = 0.0;
  rtDW->Pdot[310] = 0.0;
  rtDW->Pdot[338] = 0.0;
  rtDW->Pdot[366] = 0.0;
  rtDW->Pdot[394] = 0.0;
  rtDW->Pdot[422] = 0.0;
  rtDW->Pdot[450] = 0.0;
  rtDW->Pdot[478] = 0.0;
  rtDW->Pdot[506] = 0.0;
  rtDW->Pdot[534] = 0.0;
  rtDW->Pdot[562] = 0.0;
  rtDW->Pdot[590] = 0.0;
  rtDW->Pdot[618] = 0.0;
  rtDW->Pdot[646] = 0.0;
  rtDW->Pdot[674] = 0.0;
  rtDW->Pdot[702] = 0.0;
  rtDW->Pdot[730] = 0.0;
  rtDW->Pdot[758] = 0.0;
  rtDW->Pdot[3] = rtDW->UnitDelay_DSTATE[6] / 2.0;
  rtDW->Pdot[31] = rtDW->UnitDelay_DSTATE[5] / 2.0;
  rtDW->Pdot[59] = n;
  rtDW->Pdot[87] = 0.0;
  rtDW->Pdot[115] = ab2;
  rtDW->Pdot[143] = rtDW->UnitDelay_DSTATE[1] / 2.0;
  rtDW->Pdot[171] = rtDW->UnitDelay_DSTATE[0] / 2.0;
  rtDW->Pdot[199] = 0.0;
  rtDW->Pdot[227] = 0.0;
  rtDW->Pdot[255] = 0.0;
  rtDW->Pdot[283] = 0.0;
  rtDW->Pdot[311] = 0.0;
  rtDW->Pdot[339] = 0.0;
  rtDW->Pdot[367] = 0.0;
  rtDW->Pdot[395] = 0.0;
  rtDW->Pdot[423] = 0.0;
  rtDW->Pdot[451] = 0.0;
  rtDW->Pdot[479] = 0.0;
  rtDW->Pdot[507] = 0.0;
  rtDW->Pdot[535] = 0.0;
  rtDW->Pdot[563] = 0.0;
  rtDW->Pdot[591] = 0.0;
  rtDW->Pdot[619] = 0.0;
  rtDW->Pdot[647] = 0.0;
  rtDW->Pdot[675] = 0.0;
  rtDW->Pdot[703] = 0.0;
  rtDW->Pdot[731] = 0.0;
  rtDW->Pdot[759] = 0.0;
  for (i = 0; i < 28; i++) {
    rtDW->procNoise[i + 28 * i] = i_2[i];
    rtDW->Pdot[28 * i + 4] = 0.0;
    rtDW->Pdot[28 * i + 5] = 0.0;
    rtDW->Pdot[28 * i + 6] = 0.0;
    rtDW->Pdot[28 * i + 7] = c[i];
    rtDW->Pdot[28 * i + 8] = d[i];
    rtDW->Pdot[28 * i + 9] = e[i];
    rtDW->Pdot[28 * i + 10] = f[i];
    rtDW->Pdot[28 * i + 11] = g[i];
    rtDW->Pdot[28 * i + 12] = h[i];
    rtDW->Pdot[28 * i + 13] = 0.0;
    rtDW->Pdot[28 * i + 14] = 0.0;
    rtDW->Pdot[28 * i + 15] = 0.0;
    rtDW->Pdot[28 * i + 16] = 0.0;
    rtDW->Pdot[28 * i + 17] = 0.0;
    rtDW->Pdot[28 * i + 18] = 0.0;
    rtDW->Pdot[28 * i + 19] = 0.0;
    rtDW->Pdot[28 * i + 20] = 0.0;
    rtDW->Pdot[28 * i + 21] = 0.0;
    rtDW->Pdot[28 * i + 22] = 0.0;
    rtDW->Pdot[28 * i + 23] = 0.0;
    rtDW->Pdot[28 * i + 24] = 0.0;
    rtDW->Pdot[28 * i + 25] = 0.0;
    rtDW->Pdot[28 * i + 26] = 0.0;
    rtDW->Pdot[28 * i + 27] = 0.0;
  }

  for (i = 0; i < 28; i++) {
    for (i_0 = 0; i_0 < 28; i_0++) {
      int32_T dfdx_tmp_1;
      dfdx_tmp_1 = 28 * i_0 + i;
      rtDW->dfdx[dfdx_tmp_1] = 0.0;
      rtDW->b[dfdx_tmp_1] = 0.0;
      for (i_1 = 0; i_1 < 28; i_1++) {
        int32_T dfdx_tmp_2;
        dfdx_tmp_2 = 28 * i_1 + i;
        rtDW->dfdx[dfdx_tmp_1] += b[28 * i_0 + i_1] * rtDW->Pdot[dfdx_tmp_2];
        rtDW->b[dfdx_tmp_1] += rtDW->Pdot[28 * i_1 + i_0] * b[dfdx_tmp_2];
      }
    }
  }

  for (i = 0; i < 784; i++) {
    rtDW->Pdot[i] = (rtDW->dfdx[i] + rtDW->b[i]) + rtDW->procNoise[i];
  }

  rtDW->filter.pState[0] = ((-(rtDW->UnitDelay_DSTATE[1] *
    rtDW->UnitDelay_DSTATE[4]) / 2.0 - rtDW->UnitDelay_DSTATE[2] *
    rtDW->UnitDelay_DSTATE[5] / 2.0) - rtDW->UnitDelay_DSTATE[3] *
    rtDW->UnitDelay_DSTATE[6] / 2.0) * 0.01 + rtDW->UnitDelay_DSTATE[0];
  rtDW->filter.pState[1] = ((rtDW->UnitDelay_DSTATE[0] * rtDW->UnitDelay_DSTATE
    [4] / 2.0 - rtDW->UnitDelay_DSTATE[3] * rtDW->UnitDelay_DSTATE[5] / 2.0) +
    rtDW->UnitDelay_DSTATE[2] * rtDW->UnitDelay_DSTATE[6] / 2.0) * 0.01 +
    rtDW->UnitDelay_DSTATE[1];
  rtDW->filter.pState[2] = ((rtDW->UnitDelay_DSTATE[3] * rtDW->UnitDelay_DSTATE
    [4] / 2.0 + rtDW->UnitDelay_DSTATE[0] * rtDW->UnitDelay_DSTATE[5] / 2.0) -
    rtDW->UnitDelay_DSTATE[1] * rtDW->UnitDelay_DSTATE[6] / 2.0) * 0.01 +
    rtDW->UnitDelay_DSTATE[2];
  rtDW->filter.pState[3] = ((rtDW->UnitDelay_DSTATE[1] * rtDW->UnitDelay_DSTATE
    [5] / 2.0 - rtDW->UnitDelay_DSTATE[2] * rtDW->UnitDelay_DSTATE[4] / 2.0) +
    rtDW->UnitDelay_DSTATE[0] * rtDW->UnitDelay_DSTATE[6] / 2.0) * 0.01 +
    rtDW->UnitDelay_DSTATE[3];
  rtDW->filter.pState[4] = rtDW->UnitDelay_DSTATE[4];
  rtDW->filter.pState[5] = rtDW->UnitDelay_DSTATE[5];
  rtDW->filter.pState[6] = rtDW->UnitDelay_DSTATE[6];
  rtDW->filter.pState[7] = 0.01 * rtDW->UnitDelay_DSTATE[10] +
    rtDW->UnitDelay_DSTATE[7];
  rtDW->filter.pState[8] = 0.01 * rtDW->UnitDelay_DSTATE[11] +
    rtDW->UnitDelay_DSTATE[8];
  rtDW->filter.pState[9] = 0.01 * rtDW->UnitDelay_DSTATE[12] +
    rtDW->UnitDelay_DSTATE[9];
  rtDW->filter.pState[10] = 0.01 * rtDW->UnitDelay_DSTATE[13] +
    rtDW->UnitDelay_DSTATE[10];
  rtDW->filter.pState[11] = 0.01 * rtDW->UnitDelay_DSTATE[14] +
    rtDW->UnitDelay_DSTATE[11];
  rtDW->filter.pState[12] = 0.01 * rtDW->UnitDelay_DSTATE[15] +
    rtDW->UnitDelay_DSTATE[12];
  memcpy(&rtDW->filter.pState[13], &rtDW->UnitDelay_DSTATE[13], 15U * sizeof
         (real_T));
  BasicEKF_repairQuaternion(&rtDW->filter, rtDW->filter.pState);
  for (i = 0; i < 28; i++) {
    for (i_0 = 0; i_0 < 28; i_0++) {
      i_1 = 28 * i + i_0;
      rtDW->filter.pStateCovariance[i_1] = (rtDW->Pdot[28 * i_0 + i] +
        rtDW->Pdot[i_1]) * 0.5 * 0.01 + b[i_1];
    }
  }

  real_T tmp_0;
  real_T tmp_1;
  real_T tmp_2;
  real_T tmp_3;
  real_T tmp_4;
  real_T tmp_5;
  real_T tmp_6;
  real_T tmp_7;
  real_T tmp_8;
  real_T tmp_9;
  real_T xk_tmp;
  real_T xk_tmp_0;
  real_T xk_tmp_1;
  real_T xk_tmp_2;
  AsyncMARGGPSFuserBase_fuseaccel(&rtDW->filter, rtU->acc, 0.0017167500000000002,
    rtDW);
  memset(&measNoise[0], 0, 9U * sizeof(real_T));
  measNoise[0] = 0.004;
  measNoise[4] = 0.004;
  measNoise[8] = 0.004;
  memcpy(&xk[0], &rtDW->filter.pState[0], 28U * sizeof(real_T));
  xk[24] = rtDW->filter.pState[24];
  xk[23] = rtDW->filter.pState[23];
  xk[22] = rtDW->filter.pState[22];
  memcpy(&rtDW->procNoise[0], &rtDW->filter.pStateCovariance[0], 784U * sizeof
         (real_T));
  filter[0] = rtDW->filter.pState[4] + rtDW->filter.pState[19];
  filter[1] = rtDW->filter.pState[5] + rtDW->filter.pState[20];
  filter[2] = rtDW->filter.pState[6] + rtDW->filter.pState[21];
  BasicEKF_correctEqn(&rtDW->filter, xk, rtDW->procNoise, filter, k,
                      rtU->ang_vel, measNoise, res, resCov, rtDW);
  memcpy(&rtDW->filter.pStateCovariance[0], &rtDW->procNoise[0], 784U * sizeof
         (real_T));
  memcpy(&rtDW->filter.pState[0], &xk[0], 28U * sizeof(real_T));
  memset(&measNoise[0], 0, 9U * sizeof(real_T));
  measNoise[0] = 0.0;
  measNoise[4] = 0.0;
  measNoise[8] = 0.0;
  n = xk[0] * xk[0];
  aasq = xk[1] * xk[1];
  xk_tmp = xk[2] * xk[2];
  xk_tmp_0 = xk[3] * xk[3];
  dfdx_tmp = 2.0 * xk[0] * xk[3];
  dfdx_tmp_0 = 2.0 * xk[1] * xk[2];
  ab2 = 2.0 * xk[0] * xk[2];
  ac2 = 2.0 * xk[1] * xk[3];
  ad2 = ((n + aasq) - xk_tmp) - xk_tmp_0;
  bc2 = dfdx_tmp + dfdx_tmp_0;
  filter[0] = ((ad2 * xk[22] + xk[25]) - (ab2 - ac2) * xk[24]) + bc2 * xk[23];
  n -= aasq;
  aasq = 2.0 * xk[0] * xk[1];
  bd2 = 2.0 * xk[2] * xk[3];
  cd2 = (n + xk_tmp) - xk_tmp_0;
  xk_tmp_1 = aasq + bd2;
  filter[1] = ((cd2 * xk[23] + xk[26]) + xk_tmp_1 * xk[24]) - (dfdx_tmp -
    dfdx_tmp_0) * xk[22];
  xk_tmp_2 = ab2 + ac2;
  n = (n - xk_tmp) + xk_tmp_0;
  filter[2] = ((n * xk[24] + xk[27]) - (aasq - bd2) * xk[23]) + xk_tmp_2 * xk[22];
  xk_tmp = 2.0 * xk[24] * xk[2];
  xk_tmp_0 = 2.0 * xk[23] * xk[3];
  tmp_5 = 2.0 * xk[22] * xk[0];
  tmp_9 = (xk_tmp_0 - xk_tmp) + tmp_5;
  tmp[0] = tmp_9;
  tmp_4 = (2.0 * xk[24] * xk[3] + 2.0 * xk[23] * xk[2]) + 2.0 * xk[22] * xk[1];
  tmp[3] = tmp_4;
  tmp_1 = 2.0 * xk[24] * xk[0];
  tmp_2 = 2.0 * xk[23] * xk[1];
  tmp_3 = 2.0 * xk[22] * xk[2];
  tmp[6] = (tmp_2 - tmp_1) - tmp_3;
  tmp_6 = 2.0 * xk[22] * xk[3];
  tmp_7 = 2.0 * xk[23] * xk[0];
  tmp_8 = 2.0 * xk[24] * xk[1];
  tmp_0 = (tmp_8 + tmp_7) - tmp_6;
  tmp[9] = tmp_0;
  tmp[12] = 0.0;
  tmp[15] = 0.0;
  tmp[18] = 0.0;
  tmp[21] = 0.0;
  tmp[24] = 0.0;
  tmp[27] = 0.0;
  tmp[30] = 0.0;
  tmp[33] = 0.0;
  tmp[36] = 0.0;
  tmp[39] = 0.0;
  tmp[42] = 0.0;
  tmp[45] = 0.0;
  tmp[48] = 0.0;
  tmp[51] = 0.0;
  tmp[54] = 0.0;
  tmp[57] = 0.0;
  tmp[60] = 0.0;
  tmp[63] = 0.0;
  tmp[66] = ad2;
  tmp[69] = bc2;
  tmp[72] = ac2 - ab2;
  tmp[75] = 1.0;
  tmp[78] = 0.0;
  tmp[81] = 0.0;
  tmp[1] = tmp_0;
  tmp_1 = (tmp_1 - tmp_2) + tmp_3;
  tmp[4] = tmp_1;
  tmp[7] = tmp_4;
  tmp[10] = (xk_tmp - xk_tmp_0) - tmp_5;
  tmp[13] = 0.0;
  tmp[16] = 0.0;
  tmp[19] = 0.0;
  tmp[22] = 0.0;
  tmp[25] = 0.0;
  tmp[28] = 0.0;
  tmp[31] = 0.0;
  tmp[34] = 0.0;
  tmp[37] = 0.0;
  tmp[40] = 0.0;
  tmp[43] = 0.0;
  tmp[46] = 0.0;
  tmp[49] = 0.0;
  tmp[52] = 0.0;
  tmp[55] = 0.0;
  tmp[58] = 0.0;
  tmp[61] = 0.0;
  tmp[64] = 0.0;
  tmp[67] = dfdx_tmp_0 - dfdx_tmp;
  tmp[70] = cd2;
  tmp[73] = xk_tmp_1;
  tmp[76] = 0.0;
  tmp[79] = 1.0;
  tmp[82] = 0.0;
  tmp[2] = tmp_1;
  tmp[5] = (tmp_6 - tmp_7) - tmp_8;
  tmp[8] = tmp_9;
  tmp[11] = tmp_4;
  tmp[14] = 0.0;
  tmp[17] = 0.0;
  tmp[20] = 0.0;
  tmp[23] = 0.0;
  tmp[26] = 0.0;
  tmp[29] = 0.0;
  tmp[32] = 0.0;
  tmp[35] = 0.0;
  tmp[38] = 0.0;
  tmp[41] = 0.0;
  tmp[44] = 0.0;
  tmp[47] = 0.0;
  tmp[50] = 0.0;
  tmp[53] = 0.0;
  tmp[56] = 0.0;
  tmp[59] = 0.0;
  tmp[62] = 0.0;
  tmp[65] = 0.0;
  tmp[68] = xk_tmp_2;
  tmp[71] = bd2 - aasq;
  tmp[74] = n;
  tmp[77] = 0.0;
  tmp[80] = 0.0;
  tmp[83] = 1.0;
  BasicEKF_correctEqn(&rtDW->filter, xk, rtDW->procNoise, filter, tmp, rtU->mag,
                      measNoise, res, resCov, rtDW);
  memcpy(&rtDW->filter.pStateCovariance[0], &rtDW->procNoise[0], 784U * sizeof
         (real_T));
  memcpy(&rtDW->filter.pState[0], &xk[0], 28U * sizeof(real_T));
  if (!(rtDW->UnitDelay1_DSTATE != 0.0)) {
    AsyncMARGGPSFuserBase_fusegps(&rtDW->filter, rtU->pos, 0.0, rtU->vel, 0.0,
      rtDW);
  }

  memcpy(&xk[0], &rtDW->filter.pState[0], 28U * sizeof(real_T));
  n = sqrt(((xk[0] * xk[0] + xk[1] * xk[1]) + xk[2] * xk[2]) + xk[3] * xk[3]);
  aasq = xk[0] / n;
  dfdx_tmp = xk[1] / n;
  dfdx_tmp_0 = xk[2] / n;
  n = xk[3] / n;
  ab2 = aasq * dfdx_tmp * 2.0;
  ac2 = aasq * dfdx_tmp_0 * 2.0;
  ad2 = aasq * n * 2.0;
  bc2 = dfdx_tmp * dfdx_tmp_0 * 2.0;
  bd2 = dfdx_tmp * n * 2.0;
  cd2 = dfdx_tmp_0 * n * 2.0;
  aasq = aasq * aasq * 2.0 - 1.0;
  memcpy(&xk[0], &rtDW->filter.pState[0], 28U * sizeof(real_T));

  /* Outport: '<Root>/posb' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function'
   */
  rtY->posb[0] = xk[7];
  rtY->posb[1] = xk[8];
  rtY->posb[2] = xk[9];

  /* MATLAB Function: '<S1>/MATLAB Function' */
  memcpy(&xk[0], &rtDW->filter.pState[0], 28U * sizeof(real_T));

  /* Update for UnitDelay: '<S1>/Unit Delay' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function'
   */
  memcpy(&rtDW->UnitDelay_DSTATE[0], &rtDW->filter.pState[0], 28U * sizeof
         (real_T));

  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtDW->UnitDelay_DSTATE[24] = rtDW->filter.pState[24];
  rtDW->UnitDelay_DSTATE[23] = rtDW->filter.pState[23];
  rtDW->UnitDelay_DSTATE[22] = rtDW->filter.pState[22];

  /* Outport: '<Root>/angvel' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function'
   */
  rtY->angvel[0] = dfdx_tmp * dfdx_tmp * 2.0 + aasq;
  rtY->angvel[3] = bc2 + ad2;
  rtY->angvel[6] = bd2 - ac2;
  rtY->angvel[1] = bc2 - ad2;
  rtY->angvel[4] = dfdx_tmp_0 * dfdx_tmp_0 * 2.0 + aasq;
  rtY->angvel[7] = cd2 + ab2;
  rtY->angvel[2] = bd2 + ac2;
  rtY->angvel[5] = cd2 - ab2;
  rtY->angvel[8] = n * n * 2.0 + aasq;

  /* Outport: '<Root>/velb' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function'
   */
  rtY->velb[0] = xk[10];
  rtY->velb[1] = xk[11];
  rtY->velb[2] = xk[12];

  /* Update for UnitDelay: '<S1>/Unit Delay1' incorporates:
   *  Bias: '<S1>/Bias'
   *  Constant: '<S1>/Constant'
   *  Math: '<S1>/Mod'
   */
  rtDW->UnitDelay1_DSTATE = rt_modd_snf(rtDW->UnitDelay1_DSTATE + 1.0, 4.0);
}

/* Model initialize function */
void SFS_initialize(RT_MODEL *const rtM)
{
  DW *rtDW = rtM->dwork;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay' */
  memcpy(&rtDW->UnitDelay_DSTATE[0], &rtConstP.UnitDelay_InitialCondition[0],
         28U * sizeof(real_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
