/* Include files */

#define IN_SF_MACHINE_SOURCE           1
#include "car_model_FIXED_sfun.h"
#include "c1_car_model_FIXED.h"
#include "c2_car_model_FIXED.h"
#include "c3_car_model_FIXED.h"
#include "c4_car_model_FIXED.h"
#include "c5_car_model_FIXED.h"
#include "c7_car_model_FIXED.h"
#include "c8_car_model_FIXED.h"
#include "c10_car_model_FIXED.h"
#include "c11_car_model_FIXED.h"
#include "c13_car_model_FIXED.h"
#include "c14_car_model_FIXED.h"

/* Forward Declarations */
/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
void car_model_FIXED_initializer(void)
{
}

void car_model_FIXED_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_car_model_FIXED_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_car_model_FIXED_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_car_model_FIXED_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_car_model_FIXED_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_car_model_FIXED_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_car_model_FIXED_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_car_model_FIXED_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_car_model_FIXED_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_car_model_FIXED_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_car_model_FIXED_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_car_model_FIXED_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==14) {
    c14_car_model_FIXED_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_car_model_FIXED_process_check_sum_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1865229688U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3043499483U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2614094398U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(920893376U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_car_model_FIXED_get_check_sum(mxArray *plhs[]);
          sf_c1_car_model_FIXED_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_car_model_FIXED_get_check_sum(mxArray *plhs[]);
          sf_c2_car_model_FIXED_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_car_model_FIXED_get_check_sum(mxArray *plhs[]);
          sf_c3_car_model_FIXED_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_car_model_FIXED_get_check_sum(mxArray *plhs[]);
          sf_c4_car_model_FIXED_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_car_model_FIXED_get_check_sum(mxArray *plhs[]);
          sf_c5_car_model_FIXED_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_car_model_FIXED_get_check_sum(mxArray *plhs[]);
          sf_c7_car_model_FIXED_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_car_model_FIXED_get_check_sum(mxArray *plhs[]);
          sf_c8_car_model_FIXED_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_car_model_FIXED_get_check_sum(mxArray *plhs[]);
          sf_c10_car_model_FIXED_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_car_model_FIXED_get_check_sum(mxArray *plhs[]);
          sf_c11_car_model_FIXED_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_car_model_FIXED_get_check_sum(mxArray *plhs[]);
          sf_c13_car_model_FIXED_get_check_sum(plhs);
          break;
        }

       case 14:
        {
          extern void sf_c14_car_model_FIXED_get_check_sum(mxArray *plhs[]);
          sf_c14_car_model_FIXED_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2405185931U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1565414716U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(611325405U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(540362971U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2044872726U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3206868133U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2350582055U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(639202807U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_car_model_FIXED_get_eml_resolved_functions_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  char instanceChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    mxGetString(prhs[2], instanceChksum,sizeof(instanceChksum)/sizeof(char));
    instanceChksum[(sizeof(instanceChksum)/sizeof(char)-1)] = '\0';
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(instanceChksum, "soVj7KZ0y8iIXEgJitbPAAE") == 0) {
          extern const mxArray
            *sf_c1_car_model_FIXED_get_eml_resolved_functions_info(void);
          mxArray *persistentMxArray = (mxArray *)
            sf_c1_car_model_FIXED_get_eml_resolved_functions_info();
          plhs[0] = mxDuplicateArray(persistentMxArray);
          mxDestroyArray(persistentMxArray);
          break;
        }
      }

     case 2:
      {
        if (strcmp(instanceChksum, "s7qNGAWd62A0blwh8l7q0xB") == 0) {
          extern const mxArray
            *sf_c2_car_model_FIXED_get_eml_resolved_functions_info(void);
          mxArray *persistentMxArray = (mxArray *)
            sf_c2_car_model_FIXED_get_eml_resolved_functions_info();
          plhs[0] = mxDuplicateArray(persistentMxArray);
          mxDestroyArray(persistentMxArray);
          break;
        }
      }

     case 3:
      {
        if (strcmp(instanceChksum, "s1rdZU9ozvyr7BKgH3old8C") == 0) {
          extern const mxArray
            *sf_c3_car_model_FIXED_get_eml_resolved_functions_info(void);
          mxArray *persistentMxArray = (mxArray *)
            sf_c3_car_model_FIXED_get_eml_resolved_functions_info();
          plhs[0] = mxDuplicateArray(persistentMxArray);
          mxDestroyArray(persistentMxArray);
          break;
        }
      }

     case 4:
      {
        if (strcmp(instanceChksum, "snpVbkJM5ucxIKoy8S5hbjE") == 0) {
          extern const mxArray
            *sf_c4_car_model_FIXED_get_eml_resolved_functions_info(void);
          mxArray *persistentMxArray = (mxArray *)
            sf_c4_car_model_FIXED_get_eml_resolved_functions_info();
          plhs[0] = mxDuplicateArray(persistentMxArray);
          mxDestroyArray(persistentMxArray);
          break;
        }
      }

     case 5:
      {
        if (strcmp(instanceChksum, "s4qu3JUgCHDtAc1vsRZRLeH") == 0) {
          extern const mxArray
            *sf_c5_car_model_FIXED_get_eml_resolved_functions_info(void);
          mxArray *persistentMxArray = (mxArray *)
            sf_c5_car_model_FIXED_get_eml_resolved_functions_info();
          plhs[0] = mxDuplicateArray(persistentMxArray);
          mxDestroyArray(persistentMxArray);
          break;
        }
      }

     case 7:
      {
        if (strcmp(instanceChksum, "sRfF8tmCyCA3hjw7FEn1bTF") == 0) {
          extern const mxArray
            *sf_c7_car_model_FIXED_get_eml_resolved_functions_info(void);
          mxArray *persistentMxArray = (mxArray *)
            sf_c7_car_model_FIXED_get_eml_resolved_functions_info();
          plhs[0] = mxDuplicateArray(persistentMxArray);
          mxDestroyArray(persistentMxArray);
          break;
        }
      }

     case 8:
      {
        if (strcmp(instanceChksum, "sIGoQh1EzRG2NYhkWn6kyIB") == 0) {
          extern const mxArray
            *sf_c8_car_model_FIXED_get_eml_resolved_functions_info(void);
          mxArray *persistentMxArray = (mxArray *)
            sf_c8_car_model_FIXED_get_eml_resolved_functions_info();
          plhs[0] = mxDuplicateArray(persistentMxArray);
          mxDestroyArray(persistentMxArray);
          break;
        }
      }

     case 10:
      {
        if (strcmp(instanceChksum, "sB1BMPri0FTxkq3dNxq34YB") == 0) {
          extern const mxArray
            *sf_c10_car_model_FIXED_get_eml_resolved_functions_info(void);
          mxArray *persistentMxArray = (mxArray *)
            sf_c10_car_model_FIXED_get_eml_resolved_functions_info();
          plhs[0] = mxDuplicateArray(persistentMxArray);
          mxDestroyArray(persistentMxArray);
          break;
        }
      }

     case 11:
      {
        if (strcmp(instanceChksum, "sVUJGr4RxeYCNLlr98V5jYH") == 0) {
          extern const mxArray
            *sf_c11_car_model_FIXED_get_eml_resolved_functions_info(void);
          mxArray *persistentMxArray = (mxArray *)
            sf_c11_car_model_FIXED_get_eml_resolved_functions_info();
          plhs[0] = mxDuplicateArray(persistentMxArray);
          mxDestroyArray(persistentMxArray);
          break;
        }
      }

     case 13:
      {
        if (strcmp(instanceChksum, "sZlgZrK2rX9XADtpnHOYTN") == 0) {
          extern const mxArray
            *sf_c13_car_model_FIXED_get_eml_resolved_functions_info(void);
          mxArray *persistentMxArray = (mxArray *)
            sf_c13_car_model_FIXED_get_eml_resolved_functions_info();
          plhs[0] = mxDuplicateArray(persistentMxArray);
          mxDestroyArray(persistentMxArray);
          break;
        }
      }

     case 14:
      {
        if (strcmp(instanceChksum, "sjvjQp4IUyV4PyB3PR9rYqC") == 0) {
          extern const mxArray
            *sf_c14_car_model_FIXED_get_eml_resolved_functions_info(void);
          mxArray *persistentMxArray = (mxArray *)
            sf_c14_car_model_FIXED_get_eml_resolved_functions_info();
          plhs[0] = mxDuplicateArray(persistentMxArray);
          mxDestroyArray(persistentMxArray);
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_car_model_FIXED_third_party_uses_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "soVj7KZ0y8iIXEgJitbPAAE") == 0) {
          extern mxArray *sf_c1_car_model_FIXED_third_party_uses_info(void);
          plhs[0] = sf_c1_car_model_FIXED_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "s7qNGAWd62A0blwh8l7q0xB") == 0) {
          extern mxArray *sf_c2_car_model_FIXED_third_party_uses_info(void);
          plhs[0] = sf_c2_car_model_FIXED_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "s1rdZU9ozvyr7BKgH3old8C") == 0) {
          extern mxArray *sf_c3_car_model_FIXED_third_party_uses_info(void);
          plhs[0] = sf_c3_car_model_FIXED_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "snpVbkJM5ucxIKoy8S5hbjE") == 0) {
          extern mxArray *sf_c4_car_model_FIXED_third_party_uses_info(void);
          plhs[0] = sf_c4_car_model_FIXED_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "s4qu3JUgCHDtAc1vsRZRLeH") == 0) {
          extern mxArray *sf_c5_car_model_FIXED_third_party_uses_info(void);
          plhs[0] = sf_c5_car_model_FIXED_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "sRfF8tmCyCA3hjw7FEn1bTF") == 0) {
          extern mxArray *sf_c7_car_model_FIXED_third_party_uses_info(void);
          plhs[0] = sf_c7_car_model_FIXED_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "sIGoQh1EzRG2NYhkWn6kyIB") == 0) {
          extern mxArray *sf_c8_car_model_FIXED_third_party_uses_info(void);
          plhs[0] = sf_c8_car_model_FIXED_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "sB1BMPri0FTxkq3dNxq34YB") == 0) {
          extern mxArray *sf_c10_car_model_FIXED_third_party_uses_info(void);
          plhs[0] = sf_c10_car_model_FIXED_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "sVUJGr4RxeYCNLlr98V5jYH") == 0) {
          extern mxArray *sf_c11_car_model_FIXED_third_party_uses_info(void);
          plhs[0] = sf_c11_car_model_FIXED_third_party_uses_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "sZlgZrK2rX9XADtpnHOYTN") == 0) {
          extern mxArray *sf_c13_car_model_FIXED_third_party_uses_info(void);
          plhs[0] = sf_c13_car_model_FIXED_third_party_uses_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "sjvjQp4IUyV4PyB3PR9rYqC") == 0) {
          extern mxArray *sf_c14_car_model_FIXED_third_party_uses_info(void);
          plhs[0] = sf_c14_car_model_FIXED_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_car_model_FIXED_jit_fallback_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the jit_fallback_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_jit_fallback_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "soVj7KZ0y8iIXEgJitbPAAE") == 0) {
          extern mxArray *sf_c1_car_model_FIXED_jit_fallback_info(void);
          plhs[0] = sf_c1_car_model_FIXED_jit_fallback_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "s7qNGAWd62A0blwh8l7q0xB") == 0) {
          extern mxArray *sf_c2_car_model_FIXED_jit_fallback_info(void);
          plhs[0] = sf_c2_car_model_FIXED_jit_fallback_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "s1rdZU9ozvyr7BKgH3old8C") == 0) {
          extern mxArray *sf_c3_car_model_FIXED_jit_fallback_info(void);
          plhs[0] = sf_c3_car_model_FIXED_jit_fallback_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "snpVbkJM5ucxIKoy8S5hbjE") == 0) {
          extern mxArray *sf_c4_car_model_FIXED_jit_fallback_info(void);
          plhs[0] = sf_c4_car_model_FIXED_jit_fallback_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "s4qu3JUgCHDtAc1vsRZRLeH") == 0) {
          extern mxArray *sf_c5_car_model_FIXED_jit_fallback_info(void);
          plhs[0] = sf_c5_car_model_FIXED_jit_fallback_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "sRfF8tmCyCA3hjw7FEn1bTF") == 0) {
          extern mxArray *sf_c7_car_model_FIXED_jit_fallback_info(void);
          plhs[0] = sf_c7_car_model_FIXED_jit_fallback_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "sIGoQh1EzRG2NYhkWn6kyIB") == 0) {
          extern mxArray *sf_c8_car_model_FIXED_jit_fallback_info(void);
          plhs[0] = sf_c8_car_model_FIXED_jit_fallback_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "sB1BMPri0FTxkq3dNxq34YB") == 0) {
          extern mxArray *sf_c10_car_model_FIXED_jit_fallback_info(void);
          plhs[0] = sf_c10_car_model_FIXED_jit_fallback_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "sVUJGr4RxeYCNLlr98V5jYH") == 0) {
          extern mxArray *sf_c11_car_model_FIXED_jit_fallback_info(void);
          plhs[0] = sf_c11_car_model_FIXED_jit_fallback_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "sZlgZrK2rX9XADtpnHOYTN") == 0) {
          extern mxArray *sf_c13_car_model_FIXED_jit_fallback_info(void);
          plhs[0] = sf_c13_car_model_FIXED_jit_fallback_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "sjvjQp4IUyV4PyB3PR9rYqC") == 0) {
          extern mxArray *sf_c14_car_model_FIXED_jit_fallback_info(void);
          plhs[0] = sf_c14_car_model_FIXED_jit_fallback_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_car_model_FIXED_get_post_codegen_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get_post_codegen_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_post_codegen_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "soVj7KZ0y8iIXEgJitbPAAE") == 0) {
          const char *sf_c1_car_model_FIXED_get_post_codegen_info(void);
          const char* encoded_post_codegen_info =
            sf_c1_car_model_FIXED_get_post_codegen_info();
          plhs[0] = sf_mex_decode(encoded_post_codegen_info);
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "s7qNGAWd62A0blwh8l7q0xB") == 0) {
          const char *sf_c2_car_model_FIXED_get_post_codegen_info(void);
          const char* encoded_post_codegen_info =
            sf_c2_car_model_FIXED_get_post_codegen_info();
          plhs[0] = sf_mex_decode(encoded_post_codegen_info);
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "s1rdZU9ozvyr7BKgH3old8C") == 0) {
          const char *sf_c3_car_model_FIXED_get_post_codegen_info(void);
          const char* encoded_post_codegen_info =
            sf_c3_car_model_FIXED_get_post_codegen_info();
          plhs[0] = sf_mex_decode(encoded_post_codegen_info);
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "snpVbkJM5ucxIKoy8S5hbjE") == 0) {
          const char *sf_c4_car_model_FIXED_get_post_codegen_info(void);
          const char* encoded_post_codegen_info =
            sf_c4_car_model_FIXED_get_post_codegen_info();
          plhs[0] = sf_mex_decode(encoded_post_codegen_info);
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "s4qu3JUgCHDtAc1vsRZRLeH") == 0) {
          const char *sf_c5_car_model_FIXED_get_post_codegen_info(void);
          const char* encoded_post_codegen_info =
            sf_c5_car_model_FIXED_get_post_codegen_info();
          plhs[0] = sf_mex_decode(encoded_post_codegen_info);
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "sRfF8tmCyCA3hjw7FEn1bTF") == 0) {
          const char *sf_c7_car_model_FIXED_get_post_codegen_info(void);
          const char* encoded_post_codegen_info =
            sf_c7_car_model_FIXED_get_post_codegen_info();
          plhs[0] = sf_mex_decode(encoded_post_codegen_info);
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "sIGoQh1EzRG2NYhkWn6kyIB") == 0) {
          const char *sf_c8_car_model_FIXED_get_post_codegen_info(void);
          const char* encoded_post_codegen_info =
            sf_c8_car_model_FIXED_get_post_codegen_info();
          plhs[0] = sf_mex_decode(encoded_post_codegen_info);
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "sB1BMPri0FTxkq3dNxq34YB") == 0) {
          const char *sf_c10_car_model_FIXED_get_post_codegen_info(void);
          const char* encoded_post_codegen_info =
            sf_c10_car_model_FIXED_get_post_codegen_info();
          plhs[0] = sf_mex_decode(encoded_post_codegen_info);
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "sVUJGr4RxeYCNLlr98V5jYH") == 0) {
          const char *sf_c11_car_model_FIXED_get_post_codegen_info(void);
          const char* encoded_post_codegen_info =
            sf_c11_car_model_FIXED_get_post_codegen_info();
          plhs[0] = sf_mex_decode(encoded_post_codegen_info);
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "sZlgZrK2rX9XADtpnHOYTN") == 0) {
          const char *sf_c13_car_model_FIXED_get_post_codegen_info(void);
          const char* encoded_post_codegen_info =
            sf_c13_car_model_FIXED_get_post_codegen_info();
          plhs[0] = sf_mex_decode(encoded_post_codegen_info);
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "sjvjQp4IUyV4PyB3PR9rYqC") == 0) {
          const char *sf_c14_car_model_FIXED_get_post_codegen_info(void);
          const char* encoded_post_codegen_info =
            sf_c14_car_model_FIXED_get_post_codegen_info();
          plhs[0] = sf_mex_decode(encoded_post_codegen_info);
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_car_model_FIXED_updateBuildInfo_args_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "soVj7KZ0y8iIXEgJitbPAAE") == 0) {
          extern mxArray *sf_c1_car_model_FIXED_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_car_model_FIXED_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "s7qNGAWd62A0blwh8l7q0xB") == 0) {
          extern mxArray *sf_c2_car_model_FIXED_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_car_model_FIXED_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "s1rdZU9ozvyr7BKgH3old8C") == 0) {
          extern mxArray *sf_c3_car_model_FIXED_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_car_model_FIXED_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "snpVbkJM5ucxIKoy8S5hbjE") == 0) {
          extern mxArray *sf_c4_car_model_FIXED_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_car_model_FIXED_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "s4qu3JUgCHDtAc1vsRZRLeH") == 0) {
          extern mxArray *sf_c5_car_model_FIXED_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_car_model_FIXED_updateBuildInfo_args_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "sRfF8tmCyCA3hjw7FEn1bTF") == 0) {
          extern mxArray *sf_c7_car_model_FIXED_updateBuildInfo_args_info(void);
          plhs[0] = sf_c7_car_model_FIXED_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "sIGoQh1EzRG2NYhkWn6kyIB") == 0) {
          extern mxArray *sf_c8_car_model_FIXED_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_car_model_FIXED_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "sB1BMPri0FTxkq3dNxq34YB") == 0) {
          extern mxArray *sf_c10_car_model_FIXED_updateBuildInfo_args_info(void);
          plhs[0] = sf_c10_car_model_FIXED_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "sVUJGr4RxeYCNLlr98V5jYH") == 0) {
          extern mxArray *sf_c11_car_model_FIXED_updateBuildInfo_args_info(void);
          plhs[0] = sf_c11_car_model_FIXED_updateBuildInfo_args_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "sZlgZrK2rX9XADtpnHOYTN") == 0) {
          extern mxArray *sf_c13_car_model_FIXED_updateBuildInfo_args_info(void);
          plhs[0] = sf_c13_car_model_FIXED_updateBuildInfo_args_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "sjvjQp4IUyV4PyB3PR9rYqC") == 0) {
          extern mxArray *sf_c14_car_model_FIXED_updateBuildInfo_args_info(void);
          plhs[0] = sf_c14_car_model_FIXED_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void car_model_FIXED_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
typedef struct SfOptimizationInfoFlagsTag {
  boolean_T isRtwGen;
  boolean_T isModelRef;
  boolean_T isExternal;
} SfOptimizationInfoFlags;

static SfOptimizationInfoFlags sOptimizationInfoFlags;
void unload_car_model_FIXED_optimization_info(void);
mxArray* load_car_model_FIXED_optimization_info(boolean_T isRtwGen, boolean_T
  isModelRef, boolean_T isExternal)
{
  if (sOptimizationInfoFlags.isRtwGen != isRtwGen ||
      sOptimizationInfoFlags.isModelRef != isModelRef ||
      sOptimizationInfoFlags.isExternal != isExternal) {
    unload_car_model_FIXED_optimization_info();
  }

  sOptimizationInfoFlags.isRtwGen = isRtwGen;
  sOptimizationInfoFlags.isModelRef = isModelRef;
  sOptimizationInfoFlags.isExternal = isExternal;
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("car_model_FIXED",
      "car_model_FIXED");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_car_model_FIXED_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
