/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SFS_types.h
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

#ifndef RTW_HEADER_SFS_types_h_
#define RTW_HEADER_SFS_types_h_

/* Custom Type definition for MATLAB Function: '<S1>/MATLAB Function' */
#ifndef struct_tag_Qswwf45pAGwdJmfEwBddhC
#define struct_tag_Qswwf45pAGwdJmfEwBddhC

struct tag_Qswwf45pAGwdJmfEwBddhC
{
  int32_T __dummy;
};

#endif                                 /* struct_tag_Qswwf45pAGwdJmfEwBddhC */

#ifndef typedef_fusion_internal_frames_NED
#define typedef_fusion_internal_frames_NED

typedef struct tag_Qswwf45pAGwdJmfEwBddhC fusion_internal_frames_NED;

#endif                                 /* typedef_fusion_internal_frames_NED */

#ifndef struct_tag_qHRwoV6ocLgXRwuZ4G6fCE
#define struct_tag_qHRwoV6ocLgXRwuZ4G6fCE

struct tag_qHRwoV6ocLgXRwuZ4G6fCE
{
  real_T OrientationIdx[4];
  fusion_internal_frames_NED ReferenceFrameObject;
  real_T ReferenceLocation[3];
  real_T QuaternionNoise[4];
  real_T AngularVelocityNoise[3];
  real_T PositionNoise[3];
  real_T VelocityNoise[3];
  real_T AccelerationNoise[3];
  real_T GyroscopeBiasNoise[3];
  real_T AccelerometerBiasNoise[3];
  real_T GeomagneticVectorNoise[3];
  real_T MagnetometerBiasNoise[3];
  real_T pState[28];
  real_T pStateCovariance[784];
};

#endif                                 /* struct_tag_qHRwoV6ocLgXRwuZ4G6fCE */

#ifndef typedef_insfilterAsync
#define typedef_insfilterAsync

typedef struct tag_qHRwoV6ocLgXRwuZ4G6fCE insfilterAsync;

#endif                                 /* typedef_insfilterAsync */

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

#endif                                 /* RTW_HEADER_SFS_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
