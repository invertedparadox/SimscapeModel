#ifndef __c1_vehdynlibeom_h__
#define __c1_vehdynlibeom_h__

/* Forward Declarations */

/* Type Definitions */
#ifndef typedef_SFc1_vehdynlibeomInstanceStruct
#define typedef_SFc1_vehdynlibeomInstanceStruct

typedef struct {
  real_T c1_m;
  real_T c1_z1m;
  real_T c1_z2m;
  real_T c1_z3m;
  real_T c1_z4m;
  real_T c1_z5m;
  real_T c1_z6m;
  real_T c1_z7m;
  real_T c1_z1R[3];
  real_T c1_z2R[3];
  real_T c1_z3R[3];
  real_T c1_z4R[3];
  real_T c1_z5R[3];
  real_T c1_z6R[3];
  real_T c1_Iveh[9];
  real_T c1_z1I[9];
  real_T c1_z2I[9];
  real_T c1_z3I[9];
  real_T c1_z4I[9];
  real_T c1_z5I[9];
  real_T c1_z6I[9];
  real_T c1_z7I[9];
  real_T c1_z7R[3];
  real_T c1_a;
  real_T c1_b;
  real_T c1_h;
  real_T c1_w[2];
  real_T c1_d;
  SimStruct *S;
  ChartInfoStruct chartInfo;
  int32_T c1_sfEvent;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_vehdynlibeom;
  uint8_T c1_JITStateAnimation[1];
  uint8_T c1_JITTransitionAnimation[1];
  int32_T c1_IsDebuggerActive;
  int32_T c1_IsSequenceViewerPresent;
  int32_T c1_SequenceViewerOptimization;
  int32_T c1_IsHeatMapPresent;
  void *c1_RuntimeVar;
  uint32_T c1_mlFcnLineNumber;
  void *c1_fcnDataPtrs[34];
  char_T *c1_dataNames[34];
  uint32_T c1_numFcnVars;
  uint32_T c1_ssIds[34];
  uint32_T c1_statuses[34];
  void *c1_outMexFcns[34];
  void *c1_inMexFcns[34];
  CovrtStateflowInstance *c1_covrtInstance;
  void *c1_fEmlrtCtx;
  real_T *c1_Mbar;
  real_T (*c1_Ibar)[9];
  real_T (*c1_Rbar)[3];
  real_T (*c1_Xbar)[3];
  real_T (*c1_Wbar)[4];
  real_T (*c1_HPbar)[12];
} SFc1_vehdynlibeomInstanceStruct;

#endif                                 /* typedef_SFc1_vehdynlibeomInstanceStruct */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_vehdynlibeom_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_vehdynlibeom_get_check_sum(mxArray *plhs[]);
extern void c1_vehdynlibeom_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
