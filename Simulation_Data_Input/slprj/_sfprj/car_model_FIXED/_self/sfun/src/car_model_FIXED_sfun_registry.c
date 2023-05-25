#include "car_model_FIXED_sfun.h"
#define PROCESS_MEX_SFUNCTION_CMD_LINE_CALL

unsigned int sf_process_check_sum_call( int nlhs, mxArray * plhs[], int nrhs,
  const mxArray * prhs[] )
{
  extern unsigned int sf_car_model_FIXED_process_check_sum_call( int nlhs,
    mxArray * plhs[], int nrhs, const mxArray * prhs[] );
  extern unsigned int sf_vehdynlibtirecommon_process_check_sum_call( int nlhs,
    mxArray * plhs[], int nrhs, const mxArray * prhs[] );
  extern unsigned int sf_vehdynlibeom_process_check_sum_call( int nlhs, mxArray *
    plhs[], int nrhs, const mxArray * prhs[] );
  if (sf_car_model_FIXED_process_check_sum_call(nlhs,plhs,nrhs,prhs))
    return 1;
  if (sf_vehdynlibtirecommon_process_check_sum_call(nlhs,plhs,nrhs,prhs))
    return 1;
  if (sf_vehdynlibeom_process_check_sum_call(nlhs,plhs,nrhs,prhs))
    return 1;
  return 0;
}

unsigned int sf_process_get_third_party_uses_info_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  extern unsigned int sf_car_model_FIXED_third_party_uses_info( int nlhs,
    mxArray * plhs[], int nrhs, const mxArray * prhs[] );
  extern unsigned int sf_vehdynlibtirecommon_third_party_uses_info( int nlhs,
    mxArray * plhs[], int nrhs, const mxArray * prhs[] );
  extern unsigned int sf_vehdynlibeom_third_party_uses_info( int nlhs, mxArray *
    plhs[], int nrhs, const mxArray * prhs[] );
  char commandName[64];
  char machineName[128];
  if (nrhs < 4) {
    return 0;
  }

  if (!mxIsChar(prhs[0]) || !mxIsChar(prhs[1]))
    return 0;
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;
  mxGetString(prhs[1], machineName,sizeof(machineName)/sizeof(char));
  machineName[(sizeof(machineName)/sizeof(char)-1)] = '\0';
  if (strcmp(machineName, "car_model_FIXED") == 0) {
    const mxArray *newRhs[3] = { NULL, NULL, NULL };

    newRhs[0] = prhs[0];
    newRhs[1] = prhs[2];
    newRhs[2] = prhs[3];
    return sf_car_model_FIXED_third_party_uses_info(nlhs,plhs,3,newRhs);
  }

  if (strcmp(machineName, "vehdynlibtirecommon") == 0) {
    const mxArray *newRhs[3] = { NULL, NULL, NULL };

    newRhs[0] = prhs[0];
    newRhs[1] = prhs[2];
    newRhs[2] = prhs[3];
    return sf_vehdynlibtirecommon_third_party_uses_info(nlhs,plhs,3,newRhs);
  }

  if (strcmp(machineName, "vehdynlibeom") == 0) {
    const mxArray *newRhs[3] = { NULL, NULL, NULL };

    newRhs[0] = prhs[0];
    newRhs[1] = prhs[2];
    newRhs[2] = prhs[3];
    return sf_vehdynlibeom_third_party_uses_info(nlhs,plhs,3,newRhs);
  }

  return 0;
}

unsigned int sf_process_get_jit_fallback_info_call( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  extern unsigned int sf_car_model_FIXED_jit_fallback_info( int nlhs, mxArray *
    plhs[], int nrhs, const mxArray * prhs[] );
  extern unsigned int sf_vehdynlibtirecommon_jit_fallback_info( int nlhs,
    mxArray * plhs[], int nrhs, const mxArray * prhs[] );
  extern unsigned int sf_vehdynlibeom_jit_fallback_info( int nlhs, mxArray *
    plhs[], int nrhs, const mxArray * prhs[] );
  char commandName[64];
  char machineName[128];
  if (nrhs < 4) {
    return 0;
  }

  if (!mxIsChar(prhs[0]) || !mxIsChar(prhs[1]))
    return 0;
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_jit_fallback_info"))
    return 0;
  mxGetString(prhs[1], machineName,sizeof(machineName)/sizeof(char));
  machineName[(sizeof(machineName)/sizeof(char)-1)] = '\0';
  if (strcmp(machineName, "car_model_FIXED") == 0) {
    const mxArray *newRhs[3] = { NULL, NULL, NULL };

    newRhs[0] = prhs[0];
    newRhs[1] = prhs[2];
    newRhs[2] = prhs[3];
    return sf_car_model_FIXED_jit_fallback_info(nlhs,plhs,3,newRhs);
  }

  if (strcmp(machineName, "vehdynlibtirecommon") == 0) {
    const mxArray *newRhs[3] = { NULL, NULL, NULL };

    newRhs[0] = prhs[0];
    newRhs[1] = prhs[2];
    newRhs[2] = prhs[3];
    return sf_vehdynlibtirecommon_jit_fallback_info(nlhs,plhs,3,newRhs);
  }

  if (strcmp(machineName, "vehdynlibeom") == 0) {
    const mxArray *newRhs[3] = { NULL, NULL, NULL };

    newRhs[0] = prhs[0];
    newRhs[1] = prhs[2];
    newRhs[2] = prhs[3];
    return sf_vehdynlibeom_jit_fallback_info(nlhs,plhs,3,newRhs);
  }

  return 0;
}

unsigned int sf_process_get_post_codegen_info_call( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  extern unsigned int sf_car_model_FIXED_get_post_codegen_info( int nlhs,
    mxArray * plhs[], int nrhs, const mxArray * prhs[] );
  extern unsigned int sf_vehdynlibtirecommon_get_post_codegen_info( int nlhs,
    mxArray * plhs[], int nrhs, const mxArray * prhs[] );
  extern unsigned int sf_vehdynlibeom_get_post_codegen_info( int nlhs, mxArray *
    plhs[], int nrhs, const mxArray * prhs[] );
  char commandName[64];
  char machineName[128];
  if (nrhs < 4) {
    return 0;
  }

  if (!mxIsChar(prhs[0]) || !mxIsChar(prhs[1]))
    return 0;
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_post_codegen_info"))
    return 0;
  mxGetString(prhs[1], machineName,sizeof(machineName)/sizeof(char));
  machineName[(sizeof(machineName)/sizeof(char)-1)] = '\0';
  if (strcmp(machineName, "car_model_FIXED") == 0) {
    const mxArray *newRhs[3] = { NULL, NULL, NULL };

    newRhs[0] = prhs[0];
    newRhs[1] = prhs[2];
    newRhs[2] = prhs[3];
    return sf_car_model_FIXED_get_post_codegen_info(nlhs,plhs,3,newRhs);
  }

  if (strcmp(machineName, "vehdynlibtirecommon") == 0) {
    const mxArray *newRhs[3] = { NULL, NULL, NULL };

    newRhs[0] = prhs[0];
    newRhs[1] = prhs[2];
    newRhs[2] = prhs[3];
    return sf_vehdynlibtirecommon_get_post_codegen_info(nlhs,plhs,3,newRhs);
  }

  if (strcmp(machineName, "vehdynlibeom") == 0) {
    const mxArray *newRhs[3] = { NULL, NULL, NULL };

    newRhs[0] = prhs[0];
    newRhs[1] = prhs[2];
    newRhs[2] = prhs[3];
    return sf_vehdynlibeom_get_post_codegen_info(nlhs,plhs,3,newRhs);
  }

  return 0;
}

unsigned int sf_process_get_updateBuildInfo_args_info_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  extern unsigned int sf_car_model_FIXED_updateBuildInfo_args_info( int nlhs,
    mxArray * plhs[], int nrhs, const mxArray * prhs[] );
  extern unsigned int sf_vehdynlibtirecommon_updateBuildInfo_args_info( int nlhs,
    mxArray * plhs[], int nrhs, const mxArray * prhs[] );
  extern unsigned int sf_vehdynlibeom_updateBuildInfo_args_info( int nlhs,
    mxArray * plhs[], int nrhs, const mxArray * prhs[] );
  char commandName[64];
  char machineName[128];
  if (nrhs < 4) {
    return 0;
  }

  if (!mxIsChar(prhs[0]) || !mxIsChar(prhs[1]))
    return 0;
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;
  mxGetString(prhs[1], machineName,sizeof(machineName)/sizeof(char));
  machineName[(sizeof(machineName)/sizeof(char)-1)] = '\0';
  if (strcmp(machineName, "car_model_FIXED") == 0) {
    const mxArray *newRhs[3] = { NULL, NULL, NULL };

    newRhs[0] = prhs[0];
    newRhs[1] = prhs[2];
    newRhs[2] = prhs[3];
    return sf_car_model_FIXED_updateBuildInfo_args_info(nlhs,plhs,3,newRhs);
  }

  if (strcmp(machineName, "vehdynlibtirecommon") == 0) {
    const mxArray *newRhs[3] = { NULL, NULL, NULL };

    newRhs[0] = prhs[0];
    newRhs[1] = prhs[2];
    newRhs[2] = prhs[3];
    return sf_vehdynlibtirecommon_updateBuildInfo_args_info(nlhs,plhs,3,newRhs);
  }

  if (strcmp(machineName, "vehdynlibeom") == 0) {
    const mxArray *newRhs[3] = { NULL, NULL, NULL };

    newRhs[0] = prhs[0];
    newRhs[1] = prhs[2];
    newRhs[2] = prhs[3];
    return sf_vehdynlibeom_updateBuildInfo_args_info(nlhs,plhs,3,newRhs);
  }

  return 0;
}

unsigned int sf_process_get_eml_resolved_functions_info_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  extern unsigned int sf_car_model_FIXED_get_eml_resolved_functions_info( int
    nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] );
  extern unsigned int sf_vehdynlibtirecommon_get_eml_resolved_functions_info
    ( int nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] );
  extern unsigned int sf_vehdynlibeom_get_eml_resolved_functions_info( int nlhs,
    mxArray * plhs[], int nrhs, const mxArray * prhs[] );
  char commandName[64];
  char machineName[128];
  if (nrhs < 3) {
    return 0;
  }

  if (!mxIsChar(prhs[0]) || !mxIsChar(prhs[1]))
    return 0;
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;
  mxGetString(prhs[1], machineName,sizeof(machineName)/sizeof(char));
  machineName[(sizeof(machineName)/sizeof(char)-1)] = '\0';
  if (strcmp(machineName, "car_model_FIXED") == 0) {
    const mxArray *newRhs[3] = { NULL, NULL, NULL };

    newRhs[0] = prhs[0];
    newRhs[1] = prhs[2];
    newRhs[2] = prhs[3];
    return sf_car_model_FIXED_get_eml_resolved_functions_info(nlhs,plhs,3,newRhs);
  }

  if (strcmp(machineName, "vehdynlibtirecommon") == 0) {
    const mxArray *newRhs[3] = { NULL, NULL, NULL };

    newRhs[0] = prhs[0];
    newRhs[1] = prhs[2];
    newRhs[2] = prhs[3];
    return sf_vehdynlibtirecommon_get_eml_resolved_functions_info(nlhs,plhs,3,
      newRhs);
  }

  if (strcmp(machineName, "vehdynlibeom") == 0) {
    const mxArray *newRhs[3] = { NULL, NULL, NULL };

    newRhs[0] = prhs[0];
    newRhs[1] = prhs[2];
    newRhs[2] = prhs[3];
    return sf_vehdynlibeom_get_eml_resolved_functions_info(nlhs,plhs,3,newRhs);
  }

  return 0;
}

unsigned int sf_mex_unlock_call( int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[] )
{
  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_mex_unlock"))
    return 0;
  while (mexIsLocked()) {
    mexUnlock();
  }

  return(1);
}

static unsigned int ProcessMexSfunctionCmdLineCall(int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[])
{
  if (sf_process_check_sum_call(nlhs,plhs,nrhs,prhs))
    return 1;
  if (sf_mex_unlock_call(nlhs,plhs,nrhs,prhs))
    return 1;
  if (sf_process_get_third_party_uses_info_call(nlhs,plhs,nrhs,prhs))
    return 1;
  if (sf_process_get_jit_fallback_info_call(nlhs,plhs,nrhs,prhs))
    return 1;
  if (sf_process_get_post_codegen_info_call(nlhs,plhs,nrhs,prhs))
    return 1;
  if (sf_process_get_updateBuildInfo_args_info_call(nlhs,plhs,nrhs,prhs))
    return 1;
  if (sf_process_get_eml_resolved_functions_info_call(nlhs,plhs,nrhs,prhs))
    return 1;
  mexErrMsgTxt("Unsuccessful command.");
  return 0;
}

static unsigned int sfGlobalMdlStartCallCounts = 0;
unsigned int sf_machine_global_initializer_called(void)
{
  return(sfGlobalMdlStartCallCounts > 0);
}

extern unsigned int sf_car_model_FIXED_method_dispatcher(SimStruct *S, unsigned
  int chartFileNumber, const char* specsCksum, int_T method, void *data);
extern unsigned int sf_vehdynlibtirecommon_method_dispatcher(SimStruct *S,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data);
extern unsigned int sf_vehdynlibeom_method_dispatcher(SimStruct *S, unsigned int
  chartFileNumber, const char* specsCksum, int_T method, void *data);
unsigned int sf_machine_global_method_dispatcher(SimStruct *simstructPtr, const
  char *machineName, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (!strcmp(machineName,"car_model_FIXED")) {
    return(sf_car_model_FIXED_method_dispatcher(simstructPtr,chartFileNumber,
            specsCksum,method,data));
  }

  if (!strcmp(machineName,"vehdynlibtirecommon")) {
    return(sf_vehdynlibtirecommon_method_dispatcher(simstructPtr,chartFileNumber,
            specsCksum,method,data));
  }

  if (!strcmp(machineName,"vehdynlibeom")) {
    return(sf_vehdynlibeom_method_dispatcher(simstructPtr,chartFileNumber,
            specsCksum,method,data));
  }

  return 0;
}

extern void car_model_FIXED_terminator(void);
extern void vehdynlibtirecommon_terminator(void);
extern void vehdynlibeom_terminator(void);
void sf_machine_global_terminator(SimStruct* S)
{
  (void)S;
  sfGlobalMdlStartCallCounts--;
  if (sfGlobalMdlStartCallCounts == 0) {
    car_model_FIXED_terminator();
    vehdynlibtirecommon_terminator();
    vehdynlibeom_terminator();
  }

  return;
}

extern void car_model_FIXED_initializer(void);
extern void vehdynlibtirecommon_initializer(void);
extern void vehdynlibeom_initializer(void);
extern void car_model_FIXED_register_exported_symbols(SimStruct* S);
extern void vehdynlibtirecommon_register_exported_symbols(SimStruct* S);
extern void vehdynlibeom_register_exported_symbols(SimStruct* S);
void sf_register_machine_exported_symbols(SimStruct* S)
{
  car_model_FIXED_register_exported_symbols(S);
  vehdynlibtirecommon_register_exported_symbols(S);
  vehdynlibeom_register_exported_symbols(S);
}

bool callCustomFcn(char initFlag)
{
  return false;
}

void sf_machine_global_initializer(SimStruct* S)
{
  bool simModeIsRTWGen = sim_mode_is_rtw_gen(S);
  sfGlobalMdlStartCallCounts++;
  if (sfGlobalMdlStartCallCounts == 1) {
    if (simModeIsRTWGen) {
      sf_register_machine_exported_symbols(S);
    }

    car_model_FIXED_initializer();
    vehdynlibtirecommon_initializer();
    vehdynlibeom_initializer();
  }

  return;
}

#include "sf_runtime/stateflow_mdl_methods.stub"
