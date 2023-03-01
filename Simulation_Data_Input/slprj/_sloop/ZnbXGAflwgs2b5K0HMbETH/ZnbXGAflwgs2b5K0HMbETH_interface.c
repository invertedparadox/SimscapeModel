/* Interface file for out-of-process execution of library:
 * ZnbXGAflwgs2b5K0HMbETH
 */

#include "xil_interface.h"
#include "xil_data_stream.h"

#include "ZnbXGAflwgs2b5K0HMbETH_interface.h"

#include <stdlib.h>

#include <string.h>

/* Function Init/Term */
void customcode_ZnbXGAflwgs2b5K0HMbETH_initializer(void)
{
}

void customcode_ZnbXGAflwgs2b5K0HMbETH_terminator(void)
{
}

/* Function isDebug */
boolean_T customcode_ZnbXGAflwgs2b5K0HMbETH_isdebug(void)
{
   return false;
}


/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
void pivot_on_ZnbXGAflwgs2b5K0HMbETH(Tableau *tab, int32_T row, int32_T col)
{
    pivot_on(tab, row, col);
}

int32_T find_pivot_column_ZnbXGAflwgs2b5K0HMbETH(Tableau *tab)
{
    return find_pivot_column(tab);
}

int32_T find_pivot_row_ZnbXGAflwgs2b5K0HMbETH(Tableau *tab, int32_T pivot_col)
{
    return find_pivot_row(tab, pivot_col);
}

void add_slack_variables_ZnbXGAflwgs2b5K0HMbETH(Tableau *tab)
{
    add_slack_variables(tab);
}

void check_b_positive_ZnbXGAflwgs2b5K0HMbETH(Tableau *tab)
{
    check_b_positive(tab);
}

int32_T find_basis_variable_ZnbXGAflwgs2b5K0HMbETH(Tableau *tab, int32_T col)
{
    return find_basis_variable(tab, col);
}

void print_optimal_vector_ZnbXGAflwgs2b5K0HMbETH(Tableau *tab, real_T *T1, real_T *T2, real_T *T3, real_T *T4)
{
    print_optimal_vector(tab, T1, T2, T3, T4);
}

int32_T simplex_ZnbXGAflwgs2b5K0HMbETH(Tableau *tab, real_T *T1, real_T *T2, real_T *T3, real_T *T4)
{
    return simplex(tab, T1, T2, T3, T4);
}

int32_T bigM_func_ZnbXGAflwgs2b5K0HMbETH(real_T T2F_1, real_T T2F_2, real_T T2F_3, real_T T2F_4, real_T b, real_T A_1, real_T A_2, real_T A_3, real_T A_4, real_T beq, real_T Aeq_1, real_T Aeq_2, real_T Aeq_3, real_T Aeq_4, real_T lb_1, real_T lb_2, real_T lb_3, real_T lb_4, real_T ub_1, real_T ub_2, real_T ub_3, real_T ub_4, real_T *T1, real_T *T2, real_T *T3, real_T *T4, real_T yaw_err_limit)
{
    return bigM_func(T2F_1, T2F_2, T2F_3, T2F_4, b, A_1, A_2, A_3, A_4, beq, Aeq_1, Aeq_2, Aeq_3, Aeq_4, lb_1, lb_2, lb_3, lb_4, ub_1, ub_2, ub_3, ub_4, T1, T2, T3, T4, yaw_err_limit);
}



XIL_INTERFACE_ERROR_CODE xilInitTargetData()
{
    return XIL_INTERFACE_SUCCESS;
}



XIL_INTERFACE_ERROR_CODE xilGetHostToTargetData(uint32_T xilFcnId, XIL_COMMAND_TYPE_ENUM xilCommandType, uint32_T xilCommandIdx, XILIOData **xilIOData)
{
    UNUSED_PARAMETER(xilFcnId);
    UNUSED_PARAMETER(xilCommandType);
    UNUSED_PARAMETER(xilCommandIdx);
    UNUSED_PARAMETER(xilIOData);

    return XIL_INTERFACE_UNKNOWN_TID;
}

XIL_INTERFACE_ERROR_CODE xilOutput(uint32_T xilFcnId, uint32_T xilTID)
{
    UNUSED_PARAMETER(xilTID);

    static uint32_T sizeData = (uint32_T) sizeof(uint32_T);
    static uint32_T sizeScopeID = (uint32_T) sizeof(uint8_T);

    switch (xilFcnId) {
    case 0:
    {


        customcode_ZnbXGAflwgs2b5K0HMbETH_initializer();



        MemUnit_T responseId = XIL_RESPONSE_OUTPUT_DATA;
        if (xilWriteData(&responseId, (uint32_T) sizeof(MemUnit_T)) != XIL_DATA_STREAM_SUCCESS) {
            return XIL_INTERFACE_COMMS_FAILURE;
        }


        break;
    }

    case 1:
    {


        customcode_ZnbXGAflwgs2b5K0HMbETH_terminator();



        MemUnit_T responseId = XIL_RESPONSE_OUTPUT_DATA;
        if (xilWriteData(&responseId, (uint32_T) sizeof(MemUnit_T)) != XIL_DATA_STREAM_SUCCESS) {
            return XIL_INTERFACE_COMMS_FAILURE;
        }


        break;
    }

    case 2:
    {
        uint32_T dataWidth_isAllowToDebug = 0;
        xilReadData((MemUnit_T *) &dataWidth_isAllowToDebug, sizeData);
        uint8_T scopeID_isAllowToDebug = 0;
        xilReadData((MemUnit_T *) &scopeID_isAllowToDebug, sizeScopeID);
        boolean_T isAllowToDebug = 0;



        isAllowToDebug = customcode_ZnbXGAflwgs2b5K0HMbETH_isdebug();



        MemUnit_T responseId = XIL_RESPONSE_OUTPUT_DATA;
        if (xilWriteData(&responseId, (uint32_T) sizeof(MemUnit_T)) != XIL_DATA_STREAM_SUCCESS) {
            return XIL_INTERFACE_COMMS_FAILURE;
        }

        if (xilWriteData((MemUnit_T *) &isAllowToDebug, (uint32_T) sizeof(boolean_T)) != XIL_DATA_STREAM_SUCCESS) {
            return XIL_INTERFACE_COMMS_FAILURE;
        }


        break;
    }

    case 3:
    {
        uint32_T dataWidth_tab = 0;
        xilReadData((MemUnit_T *) &dataWidth_tab, sizeData);
        uint8_T scopeID_tab = 0;
        xilReadData((MemUnit_T *) &scopeID_tab, sizeScopeID);
        Tableau *tab = (Tableau *) calloc((size_t) dataWidth_tab, sizeof(Tableau));
        if (scopeID_tab < 2) {
            xilReadData((MemUnit_T *) tab, dataWidth_tab * ((uint32_T) sizeof(Tableau)));
        }

        uint32_T dataWidth_row = 0;
        xilReadData((MemUnit_T *) &dataWidth_row, sizeData);
        uint8_T scopeID_row = 0;
        xilReadData((MemUnit_T *) &scopeID_row, sizeScopeID);
        int32_T row = 0;
        xilReadData((MemUnit_T *) &row, (uint32_T) sizeof(int32_T));

        uint32_T dataWidth_col = 0;
        xilReadData((MemUnit_T *) &dataWidth_col, sizeData);
        uint8_T scopeID_col = 0;
        xilReadData((MemUnit_T *) &scopeID_col, sizeScopeID);
        int32_T col = 0;
        xilReadData((MemUnit_T *) &col, (uint32_T) sizeof(int32_T));



        pivot_on_ZnbXGAflwgs2b5K0HMbETH(tab, row, col);



        MemUnit_T responseId = XIL_RESPONSE_OUTPUT_DATA;
        if (xilWriteData(&responseId, (uint32_T) sizeof(MemUnit_T)) != XIL_DATA_STREAM_SUCCESS) {
            return XIL_INTERFACE_COMMS_FAILURE;
        }

        if (scopeID_tab > 0) {
            if (xilWriteData((MemUnit_T *) tab, dataWidth_tab * ((uint32_T) sizeof(Tableau))) != XIL_DATA_STREAM_SUCCESS) {
                return XIL_INTERFACE_COMMS_FAILURE;
            }
        }

        free(tab);

        break;
    }

    case 4:
    {
        uint32_T dataWidth_out = 0;
        xilReadData((MemUnit_T *) &dataWidth_out, sizeData);
        uint8_T scopeID_out = 0;
        xilReadData((MemUnit_T *) &scopeID_out, sizeScopeID);
        int32_T out = 0;

        uint32_T dataWidth_tab = 0;
        xilReadData((MemUnit_T *) &dataWidth_tab, sizeData);
        uint8_T scopeID_tab = 0;
        xilReadData((MemUnit_T *) &scopeID_tab, sizeScopeID);
        Tableau *tab = (Tableau *) calloc((size_t) dataWidth_tab, sizeof(Tableau));
        if (scopeID_tab < 2) {
            xilReadData((MemUnit_T *) tab, dataWidth_tab * ((uint32_T) sizeof(Tableau)));
        }



        out = find_pivot_column_ZnbXGAflwgs2b5K0HMbETH(tab);



        MemUnit_T responseId = XIL_RESPONSE_OUTPUT_DATA;
        if (xilWriteData(&responseId, (uint32_T) sizeof(MemUnit_T)) != XIL_DATA_STREAM_SUCCESS) {
            return XIL_INTERFACE_COMMS_FAILURE;
        }

        if (xilWriteData((MemUnit_T *) &out, (uint32_T) sizeof(int32_T)) != XIL_DATA_STREAM_SUCCESS) {
            return XIL_INTERFACE_COMMS_FAILURE;
        }

        if (scopeID_tab > 0) {
            if (xilWriteData((MemUnit_T *) tab, dataWidth_tab * ((uint32_T) sizeof(Tableau))) != XIL_DATA_STREAM_SUCCESS) {
                return XIL_INTERFACE_COMMS_FAILURE;
            }
        }

        free(tab);

        break;
    }

    case 5:
    {
        uint32_T dataWidth_out = 0;
        xilReadData((MemUnit_T *) &dataWidth_out, sizeData);
        uint8_T scopeID_out = 0;
        xilReadData((MemUnit_T *) &scopeID_out, sizeScopeID);
        int32_T out = 0;

        uint32_T dataWidth_tab = 0;
        xilReadData((MemUnit_T *) &dataWidth_tab, sizeData);
        uint8_T scopeID_tab = 0;
        xilReadData((MemUnit_T *) &scopeID_tab, sizeScopeID);
        Tableau *tab = (Tableau *) calloc((size_t) dataWidth_tab, sizeof(Tableau));
        if (scopeID_tab < 2) {
            xilReadData((MemUnit_T *) tab, dataWidth_tab * ((uint32_T) sizeof(Tableau)));
        }

        uint32_T dataWidth_pivot_col = 0;
        xilReadData((MemUnit_T *) &dataWidth_pivot_col, sizeData);
        uint8_T scopeID_pivot_col = 0;
        xilReadData((MemUnit_T *) &scopeID_pivot_col, sizeScopeID);
        int32_T pivot_col = 0;
        xilReadData((MemUnit_T *) &pivot_col, (uint32_T) sizeof(int32_T));



        out = find_pivot_row_ZnbXGAflwgs2b5K0HMbETH(tab, pivot_col);



        MemUnit_T responseId = XIL_RESPONSE_OUTPUT_DATA;
        if (xilWriteData(&responseId, (uint32_T) sizeof(MemUnit_T)) != XIL_DATA_STREAM_SUCCESS) {
            return XIL_INTERFACE_COMMS_FAILURE;
        }

        if (xilWriteData((MemUnit_T *) &out, (uint32_T) sizeof(int32_T)) != XIL_DATA_STREAM_SUCCESS) {
            return XIL_INTERFACE_COMMS_FAILURE;
        }

        if (scopeID_tab > 0) {
            if (xilWriteData((MemUnit_T *) tab, dataWidth_tab * ((uint32_T) sizeof(Tableau))) != XIL_DATA_STREAM_SUCCESS) {
                return XIL_INTERFACE_COMMS_FAILURE;
            }
        }

        free(tab);

        break;
    }

    case 6:
    {
        uint32_T dataWidth_tab = 0;
        xilReadData((MemUnit_T *) &dataWidth_tab, sizeData);
        uint8_T scopeID_tab = 0;
        xilReadData((MemUnit_T *) &scopeID_tab, sizeScopeID);
        Tableau *tab = (Tableau *) calloc((size_t) dataWidth_tab, sizeof(Tableau));
        if (scopeID_tab < 2) {
            xilReadData((MemUnit_T *) tab, dataWidth_tab * ((uint32_T) sizeof(Tableau)));
        }



        add_slack_variables_ZnbXGAflwgs2b5K0HMbETH(tab);



        MemUnit_T responseId = XIL_RESPONSE_OUTPUT_DATA;
        if (xilWriteData(&responseId, (uint32_T) sizeof(MemUnit_T)) != XIL_DATA_STREAM_SUCCESS) {
            return XIL_INTERFACE_COMMS_FAILURE;
        }

        if (scopeID_tab > 0) {
            if (xilWriteData((MemUnit_T *) tab, dataWidth_tab * ((uint32_T) sizeof(Tableau))) != XIL_DATA_STREAM_SUCCESS) {
                return XIL_INTERFACE_COMMS_FAILURE;
            }
        }

        free(tab);

        break;
    }

    case 7:
    {
        uint32_T dataWidth_tab = 0;
        xilReadData((MemUnit_T *) &dataWidth_tab, sizeData);
        uint8_T scopeID_tab = 0;
        xilReadData((MemUnit_T *) &scopeID_tab, sizeScopeID);
        Tableau *tab = (Tableau *) calloc((size_t) dataWidth_tab, sizeof(Tableau));
        if (scopeID_tab < 2) {
            xilReadData((MemUnit_T *) tab, dataWidth_tab * ((uint32_T) sizeof(Tableau)));
        }



        check_b_positive_ZnbXGAflwgs2b5K0HMbETH(tab);



        MemUnit_T responseId = XIL_RESPONSE_OUTPUT_DATA;
        if (xilWriteData(&responseId, (uint32_T) sizeof(MemUnit_T)) != XIL_DATA_STREAM_SUCCESS) {
            return XIL_INTERFACE_COMMS_FAILURE;
        }

        if (scopeID_tab > 0) {
            if (xilWriteData((MemUnit_T *) tab, dataWidth_tab * ((uint32_T) sizeof(Tableau))) != XIL_DATA_STREAM_SUCCESS) {
                return XIL_INTERFACE_COMMS_FAILURE;
            }
        }

        free(tab);

        break;
    }

    case 8:
    {
        uint32_T dataWidth_out = 0;
        xilReadData((MemUnit_T *) &dataWidth_out, sizeData);
        uint8_T scopeID_out = 0;
        xilReadData((MemUnit_T *) &scopeID_out, sizeScopeID);
        int32_T out = 0;

        uint32_T dataWidth_tab = 0;
        xilReadData((MemUnit_T *) &dataWidth_tab, sizeData);
        uint8_T scopeID_tab = 0;
        xilReadData((MemUnit_T *) &scopeID_tab, sizeScopeID);
        Tableau *tab = (Tableau *) calloc((size_t) dataWidth_tab, sizeof(Tableau));
        if (scopeID_tab < 2) {
            xilReadData((MemUnit_T *) tab, dataWidth_tab * ((uint32_T) sizeof(Tableau)));
        }

        uint32_T dataWidth_col = 0;
        xilReadData((MemUnit_T *) &dataWidth_col, sizeData);
        uint8_T scopeID_col = 0;
        xilReadData((MemUnit_T *) &scopeID_col, sizeScopeID);
        int32_T col = 0;
        xilReadData((MemUnit_T *) &col, (uint32_T) sizeof(int32_T));



        out = find_basis_variable_ZnbXGAflwgs2b5K0HMbETH(tab, col);



        MemUnit_T responseId = XIL_RESPONSE_OUTPUT_DATA;
        if (xilWriteData(&responseId, (uint32_T) sizeof(MemUnit_T)) != XIL_DATA_STREAM_SUCCESS) {
            return XIL_INTERFACE_COMMS_FAILURE;
        }

        if (xilWriteData((MemUnit_T *) &out, (uint32_T) sizeof(int32_T)) != XIL_DATA_STREAM_SUCCESS) {
            return XIL_INTERFACE_COMMS_FAILURE;
        }

        if (scopeID_tab > 0) {
            if (xilWriteData((MemUnit_T *) tab, dataWidth_tab * ((uint32_T) sizeof(Tableau))) != XIL_DATA_STREAM_SUCCESS) {
                return XIL_INTERFACE_COMMS_FAILURE;
            }
        }

        free(tab);

        break;
    }

    case 9:
    {
        uint32_T dataWidth_tab = 0;
        xilReadData((MemUnit_T *) &dataWidth_tab, sizeData);
        uint8_T scopeID_tab = 0;
        xilReadData((MemUnit_T *) &scopeID_tab, sizeScopeID);
        Tableau *tab = (Tableau *) calloc((size_t) dataWidth_tab, sizeof(Tableau));
        if (scopeID_tab < 2) {
            xilReadData((MemUnit_T *) tab, dataWidth_tab * ((uint32_T) sizeof(Tableau)));
        }

        uint32_T dataWidth_T1 = 0;
        xilReadData((MemUnit_T *) &dataWidth_T1, sizeData);
        uint8_T scopeID_T1 = 0;
        xilReadData((MemUnit_T *) &scopeID_T1, sizeScopeID);
        real_T *T1 = (real_T *) calloc((size_t) dataWidth_T1, sizeof(real_T));
        if (scopeID_T1 < 2) {
            xilReadData((MemUnit_T *) T1, dataWidth_T1 * ((uint32_T) sizeof(real_T)));
        }

        uint32_T dataWidth_T2 = 0;
        xilReadData((MemUnit_T *) &dataWidth_T2, sizeData);
        uint8_T scopeID_T2 = 0;
        xilReadData((MemUnit_T *) &scopeID_T2, sizeScopeID);
        real_T *T2 = (real_T *) calloc((size_t) dataWidth_T2, sizeof(real_T));
        if (scopeID_T2 < 2) {
            xilReadData((MemUnit_T *) T2, dataWidth_T2 * ((uint32_T) sizeof(real_T)));
        }

        uint32_T dataWidth_T3 = 0;
        xilReadData((MemUnit_T *) &dataWidth_T3, sizeData);
        uint8_T scopeID_T3 = 0;
        xilReadData((MemUnit_T *) &scopeID_T3, sizeScopeID);
        real_T *T3 = (real_T *) calloc((size_t) dataWidth_T3, sizeof(real_T));
        if (scopeID_T3 < 2) {
            xilReadData((MemUnit_T *) T3, dataWidth_T3 * ((uint32_T) sizeof(real_T)));
        }

        uint32_T dataWidth_T4 = 0;
        xilReadData((MemUnit_T *) &dataWidth_T4, sizeData);
        uint8_T scopeID_T4 = 0;
        xilReadData((MemUnit_T *) &scopeID_T4, sizeScopeID);
        real_T *T4 = (real_T *) calloc((size_t) dataWidth_T4, sizeof(real_T));
        if (scopeID_T4 < 2) {
            xilReadData((MemUnit_T *) T4, dataWidth_T4 * ((uint32_T) sizeof(real_T)));
        }



        print_optimal_vector_ZnbXGAflwgs2b5K0HMbETH(tab, T1, T2, T3, T4);



        MemUnit_T responseId = XIL_RESPONSE_OUTPUT_DATA;
        if (xilWriteData(&responseId, (uint32_T) sizeof(MemUnit_T)) != XIL_DATA_STREAM_SUCCESS) {
            return XIL_INTERFACE_COMMS_FAILURE;
        }

        if (scopeID_tab > 0) {
            if (xilWriteData((MemUnit_T *) tab, dataWidth_tab * ((uint32_T) sizeof(Tableau))) != XIL_DATA_STREAM_SUCCESS) {
                return XIL_INTERFACE_COMMS_FAILURE;
            }
        }

        if (scopeID_T1 > 0) {
            if (xilWriteData((MemUnit_T *) T1, dataWidth_T1 * ((uint32_T) sizeof(real_T))) != XIL_DATA_STREAM_SUCCESS) {
                return XIL_INTERFACE_COMMS_FAILURE;
            }
        }

        if (scopeID_T2 > 0) {
            if (xilWriteData((MemUnit_T *) T2, dataWidth_T2 * ((uint32_T) sizeof(real_T))) != XIL_DATA_STREAM_SUCCESS) {
                return XIL_INTERFACE_COMMS_FAILURE;
            }
        }

        if (scopeID_T3 > 0) {
            if (xilWriteData((MemUnit_T *) T3, dataWidth_T3 * ((uint32_T) sizeof(real_T))) != XIL_DATA_STREAM_SUCCESS) {
                return XIL_INTERFACE_COMMS_FAILURE;
            }
        }

        if (scopeID_T4 > 0) {
            if (xilWriteData((MemUnit_T *) T4, dataWidth_T4 * ((uint32_T) sizeof(real_T))) != XIL_DATA_STREAM_SUCCESS) {
                return XIL_INTERFACE_COMMS_FAILURE;
            }
        }

        free(tab);
        free(T1);
        free(T2);
        free(T3);
        free(T4);

        break;
    }

    case 10:
    {
        uint32_T dataWidth_out = 0;
        xilReadData((MemUnit_T *) &dataWidth_out, sizeData);
        uint8_T scopeID_out = 0;
        xilReadData((MemUnit_T *) &scopeID_out, sizeScopeID);
        int32_T out = 0;

        uint32_T dataWidth_tab = 0;
        xilReadData((MemUnit_T *) &dataWidth_tab, sizeData);
        uint8_T scopeID_tab = 0;
        xilReadData((MemUnit_T *) &scopeID_tab, sizeScopeID);
        Tableau *tab = (Tableau *) calloc((size_t) dataWidth_tab, sizeof(Tableau));
        if (scopeID_tab < 2) {
            xilReadData((MemUnit_T *) tab, dataWidth_tab * ((uint32_T) sizeof(Tableau)));
        }

        uint32_T dataWidth_T1 = 0;
        xilReadData((MemUnit_T *) &dataWidth_T1, sizeData);
        uint8_T scopeID_T1 = 0;
        xilReadData((MemUnit_T *) &scopeID_T1, sizeScopeID);
        real_T *T1 = (real_T *) calloc((size_t) dataWidth_T1, sizeof(real_T));
        if (scopeID_T1 < 2) {
            xilReadData((MemUnit_T *) T1, dataWidth_T1 * ((uint32_T) sizeof(real_T)));
        }

        uint32_T dataWidth_T2 = 0;
        xilReadData((MemUnit_T *) &dataWidth_T2, sizeData);
        uint8_T scopeID_T2 = 0;
        xilReadData((MemUnit_T *) &scopeID_T2, sizeScopeID);
        real_T *T2 = (real_T *) calloc((size_t) dataWidth_T2, sizeof(real_T));
        if (scopeID_T2 < 2) {
            xilReadData((MemUnit_T *) T2, dataWidth_T2 * ((uint32_T) sizeof(real_T)));
        }

        uint32_T dataWidth_T3 = 0;
        xilReadData((MemUnit_T *) &dataWidth_T3, sizeData);
        uint8_T scopeID_T3 = 0;
        xilReadData((MemUnit_T *) &scopeID_T3, sizeScopeID);
        real_T *T3 = (real_T *) calloc((size_t) dataWidth_T3, sizeof(real_T));
        if (scopeID_T3 < 2) {
            xilReadData((MemUnit_T *) T3, dataWidth_T3 * ((uint32_T) sizeof(real_T)));
        }

        uint32_T dataWidth_T4 = 0;
        xilReadData((MemUnit_T *) &dataWidth_T4, sizeData);
        uint8_T scopeID_T4 = 0;
        xilReadData((MemUnit_T *) &scopeID_T4, sizeScopeID);
        real_T *T4 = (real_T *) calloc((size_t) dataWidth_T4, sizeof(real_T));
        if (scopeID_T4 < 2) {
            xilReadData((MemUnit_T *) T4, dataWidth_T4 * ((uint32_T) sizeof(real_T)));
        }



        out = simplex_ZnbXGAflwgs2b5K0HMbETH(tab, T1, T2, T3, T4);



        MemUnit_T responseId = XIL_RESPONSE_OUTPUT_DATA;
        if (xilWriteData(&responseId, (uint32_T) sizeof(MemUnit_T)) != XIL_DATA_STREAM_SUCCESS) {
            return XIL_INTERFACE_COMMS_FAILURE;
        }

        if (xilWriteData((MemUnit_T *) &out, (uint32_T) sizeof(int32_T)) != XIL_DATA_STREAM_SUCCESS) {
            return XIL_INTERFACE_COMMS_FAILURE;
        }

        if (scopeID_tab > 0) {
            if (xilWriteData((MemUnit_T *) tab, dataWidth_tab * ((uint32_T) sizeof(Tableau))) != XIL_DATA_STREAM_SUCCESS) {
                return XIL_INTERFACE_COMMS_FAILURE;
            }
        }

        if (scopeID_T1 > 0) {
            if (xilWriteData((MemUnit_T *) T1, dataWidth_T1 * ((uint32_T) sizeof(real_T))) != XIL_DATA_STREAM_SUCCESS) {
                return XIL_INTERFACE_COMMS_FAILURE;
            }
        }

        if (scopeID_T2 > 0) {
            if (xilWriteData((MemUnit_T *) T2, dataWidth_T2 * ((uint32_T) sizeof(real_T))) != XIL_DATA_STREAM_SUCCESS) {
                return XIL_INTERFACE_COMMS_FAILURE;
            }
        }

        if (scopeID_T3 > 0) {
            if (xilWriteData((MemUnit_T *) T3, dataWidth_T3 * ((uint32_T) sizeof(real_T))) != XIL_DATA_STREAM_SUCCESS) {
                return XIL_INTERFACE_COMMS_FAILURE;
            }
        }

        if (scopeID_T4 > 0) {
            if (xilWriteData((MemUnit_T *) T4, dataWidth_T4 * ((uint32_T) sizeof(real_T))) != XIL_DATA_STREAM_SUCCESS) {
                return XIL_INTERFACE_COMMS_FAILURE;
            }
        }

        free(tab);
        free(T1);
        free(T2);
        free(T3);
        free(T4);

        break;
    }

    case 11:
    {
        uint32_T dataWidth_out = 0;
        xilReadData((MemUnit_T *) &dataWidth_out, sizeData);
        uint8_T scopeID_out = 0;
        xilReadData((MemUnit_T *) &scopeID_out, sizeScopeID);
        int32_T out = 0;

        uint32_T dataWidth_T2F_1 = 0;
        xilReadData((MemUnit_T *) &dataWidth_T2F_1, sizeData);
        uint8_T scopeID_T2F_1 = 0;
        xilReadData((MemUnit_T *) &scopeID_T2F_1, sizeScopeID);
        real_T T2F_1 = 0;
        xilReadData((MemUnit_T *) &T2F_1, (uint32_T) sizeof(real_T));

        uint32_T dataWidth_T2F_2 = 0;
        xilReadData((MemUnit_T *) &dataWidth_T2F_2, sizeData);
        uint8_T scopeID_T2F_2 = 0;
        xilReadData((MemUnit_T *) &scopeID_T2F_2, sizeScopeID);
        real_T T2F_2 = 0;
        xilReadData((MemUnit_T *) &T2F_2, (uint32_T) sizeof(real_T));

        uint32_T dataWidth_T2F_3 = 0;
        xilReadData((MemUnit_T *) &dataWidth_T2F_3, sizeData);
        uint8_T scopeID_T2F_3 = 0;
        xilReadData((MemUnit_T *) &scopeID_T2F_3, sizeScopeID);
        real_T T2F_3 = 0;
        xilReadData((MemUnit_T *) &T2F_3, (uint32_T) sizeof(real_T));

        uint32_T dataWidth_T2F_4 = 0;
        xilReadData((MemUnit_T *) &dataWidth_T2F_4, sizeData);
        uint8_T scopeID_T2F_4 = 0;
        xilReadData((MemUnit_T *) &scopeID_T2F_4, sizeScopeID);
        real_T T2F_4 = 0;
        xilReadData((MemUnit_T *) &T2F_4, (uint32_T) sizeof(real_T));

        uint32_T dataWidth_b = 0;
        xilReadData((MemUnit_T *) &dataWidth_b, sizeData);
        uint8_T scopeID_b = 0;
        xilReadData((MemUnit_T *) &scopeID_b, sizeScopeID);
        real_T b = 0;
        xilReadData((MemUnit_T *) &b, (uint32_T) sizeof(real_T));

        uint32_T dataWidth_A_1 = 0;
        xilReadData((MemUnit_T *) &dataWidth_A_1, sizeData);
        uint8_T scopeID_A_1 = 0;
        xilReadData((MemUnit_T *) &scopeID_A_1, sizeScopeID);
        real_T A_1 = 0;
        xilReadData((MemUnit_T *) &A_1, (uint32_T) sizeof(real_T));

        uint32_T dataWidth_A_2 = 0;
        xilReadData((MemUnit_T *) &dataWidth_A_2, sizeData);
        uint8_T scopeID_A_2 = 0;
        xilReadData((MemUnit_T *) &scopeID_A_2, sizeScopeID);
        real_T A_2 = 0;
        xilReadData((MemUnit_T *) &A_2, (uint32_T) sizeof(real_T));

        uint32_T dataWidth_A_3 = 0;
        xilReadData((MemUnit_T *) &dataWidth_A_3, sizeData);
        uint8_T scopeID_A_3 = 0;
        xilReadData((MemUnit_T *) &scopeID_A_3, sizeScopeID);
        real_T A_3 = 0;
        xilReadData((MemUnit_T *) &A_3, (uint32_T) sizeof(real_T));

        uint32_T dataWidth_A_4 = 0;
        xilReadData((MemUnit_T *) &dataWidth_A_4, sizeData);
        uint8_T scopeID_A_4 = 0;
        xilReadData((MemUnit_T *) &scopeID_A_4, sizeScopeID);
        real_T A_4 = 0;
        xilReadData((MemUnit_T *) &A_4, (uint32_T) sizeof(real_T));

        uint32_T dataWidth_beq = 0;
        xilReadData((MemUnit_T *) &dataWidth_beq, sizeData);
        uint8_T scopeID_beq = 0;
        xilReadData((MemUnit_T *) &scopeID_beq, sizeScopeID);
        real_T beq = 0;
        xilReadData((MemUnit_T *) &beq, (uint32_T) sizeof(real_T));

        uint32_T dataWidth_Aeq_1 = 0;
        xilReadData((MemUnit_T *) &dataWidth_Aeq_1, sizeData);
        uint8_T scopeID_Aeq_1 = 0;
        xilReadData((MemUnit_T *) &scopeID_Aeq_1, sizeScopeID);
        real_T Aeq_1 = 0;
        xilReadData((MemUnit_T *) &Aeq_1, (uint32_T) sizeof(real_T));

        uint32_T dataWidth_Aeq_2 = 0;
        xilReadData((MemUnit_T *) &dataWidth_Aeq_2, sizeData);
        uint8_T scopeID_Aeq_2 = 0;
        xilReadData((MemUnit_T *) &scopeID_Aeq_2, sizeScopeID);
        real_T Aeq_2 = 0;
        xilReadData((MemUnit_T *) &Aeq_2, (uint32_T) sizeof(real_T));

        uint32_T dataWidth_Aeq_3 = 0;
        xilReadData((MemUnit_T *) &dataWidth_Aeq_3, sizeData);
        uint8_T scopeID_Aeq_3 = 0;
        xilReadData((MemUnit_T *) &scopeID_Aeq_3, sizeScopeID);
        real_T Aeq_3 = 0;
        xilReadData((MemUnit_T *) &Aeq_3, (uint32_T) sizeof(real_T));

        uint32_T dataWidth_Aeq_4 = 0;
        xilReadData((MemUnit_T *) &dataWidth_Aeq_4, sizeData);
        uint8_T scopeID_Aeq_4 = 0;
        xilReadData((MemUnit_T *) &scopeID_Aeq_4, sizeScopeID);
        real_T Aeq_4 = 0;
        xilReadData((MemUnit_T *) &Aeq_4, (uint32_T) sizeof(real_T));

        uint32_T dataWidth_lb_1 = 0;
        xilReadData((MemUnit_T *) &dataWidth_lb_1, sizeData);
        uint8_T scopeID_lb_1 = 0;
        xilReadData((MemUnit_T *) &scopeID_lb_1, sizeScopeID);
        real_T lb_1 = 0;
        xilReadData((MemUnit_T *) &lb_1, (uint32_T) sizeof(real_T));

        uint32_T dataWidth_lb_2 = 0;
        xilReadData((MemUnit_T *) &dataWidth_lb_2, sizeData);
        uint8_T scopeID_lb_2 = 0;
        xilReadData((MemUnit_T *) &scopeID_lb_2, sizeScopeID);
        real_T lb_2 = 0;
        xilReadData((MemUnit_T *) &lb_2, (uint32_T) sizeof(real_T));

        uint32_T dataWidth_lb_3 = 0;
        xilReadData((MemUnit_T *) &dataWidth_lb_3, sizeData);
        uint8_T scopeID_lb_3 = 0;
        xilReadData((MemUnit_T *) &scopeID_lb_3, sizeScopeID);
        real_T lb_3 = 0;
        xilReadData((MemUnit_T *) &lb_3, (uint32_T) sizeof(real_T));

        uint32_T dataWidth_lb_4 = 0;
        xilReadData((MemUnit_T *) &dataWidth_lb_4, sizeData);
        uint8_T scopeID_lb_4 = 0;
        xilReadData((MemUnit_T *) &scopeID_lb_4, sizeScopeID);
        real_T lb_4 = 0;
        xilReadData((MemUnit_T *) &lb_4, (uint32_T) sizeof(real_T));

        uint32_T dataWidth_ub_1 = 0;
        xilReadData((MemUnit_T *) &dataWidth_ub_1, sizeData);
        uint8_T scopeID_ub_1 = 0;
        xilReadData((MemUnit_T *) &scopeID_ub_1, sizeScopeID);
        real_T ub_1 = 0;
        xilReadData((MemUnit_T *) &ub_1, (uint32_T) sizeof(real_T));

        uint32_T dataWidth_ub_2 = 0;
        xilReadData((MemUnit_T *) &dataWidth_ub_2, sizeData);
        uint8_T scopeID_ub_2 = 0;
        xilReadData((MemUnit_T *) &scopeID_ub_2, sizeScopeID);
        real_T ub_2 = 0;
        xilReadData((MemUnit_T *) &ub_2, (uint32_T) sizeof(real_T));

        uint32_T dataWidth_ub_3 = 0;
        xilReadData((MemUnit_T *) &dataWidth_ub_3, sizeData);
        uint8_T scopeID_ub_3 = 0;
        xilReadData((MemUnit_T *) &scopeID_ub_3, sizeScopeID);
        real_T ub_3 = 0;
        xilReadData((MemUnit_T *) &ub_3, (uint32_T) sizeof(real_T));

        uint32_T dataWidth_ub_4 = 0;
        xilReadData((MemUnit_T *) &dataWidth_ub_4, sizeData);
        uint8_T scopeID_ub_4 = 0;
        xilReadData((MemUnit_T *) &scopeID_ub_4, sizeScopeID);
        real_T ub_4 = 0;
        xilReadData((MemUnit_T *) &ub_4, (uint32_T) sizeof(real_T));

        uint32_T dataWidth_T1 = 0;
        xilReadData((MemUnit_T *) &dataWidth_T1, sizeData);
        uint8_T scopeID_T1 = 0;
        xilReadData((MemUnit_T *) &scopeID_T1, sizeScopeID);
        real_T *T1 = (real_T *) calloc((size_t) dataWidth_T1, sizeof(real_T));
        if (scopeID_T1 < 2) {
            xilReadData((MemUnit_T *) T1, dataWidth_T1 * ((uint32_T) sizeof(real_T)));
        }

        uint32_T dataWidth_T2 = 0;
        xilReadData((MemUnit_T *) &dataWidth_T2, sizeData);
        uint8_T scopeID_T2 = 0;
        xilReadData((MemUnit_T *) &scopeID_T2, sizeScopeID);
        real_T *T2 = (real_T *) calloc((size_t) dataWidth_T2, sizeof(real_T));
        if (scopeID_T2 < 2) {
            xilReadData((MemUnit_T *) T2, dataWidth_T2 * ((uint32_T) sizeof(real_T)));
        }

        uint32_T dataWidth_T3 = 0;
        xilReadData((MemUnit_T *) &dataWidth_T3, sizeData);
        uint8_T scopeID_T3 = 0;
        xilReadData((MemUnit_T *) &scopeID_T3, sizeScopeID);
        real_T *T3 = (real_T *) calloc((size_t) dataWidth_T3, sizeof(real_T));
        if (scopeID_T3 < 2) {
            xilReadData((MemUnit_T *) T3, dataWidth_T3 * ((uint32_T) sizeof(real_T)));
        }

        uint32_T dataWidth_T4 = 0;
        xilReadData((MemUnit_T *) &dataWidth_T4, sizeData);
        uint8_T scopeID_T4 = 0;
        xilReadData((MemUnit_T *) &scopeID_T4, sizeScopeID);
        real_T *T4 = (real_T *) calloc((size_t) dataWidth_T4, sizeof(real_T));
        if (scopeID_T4 < 2) {
            xilReadData((MemUnit_T *) T4, dataWidth_T4 * ((uint32_T) sizeof(real_T)));
        }

        uint32_T dataWidth_yaw_err_limit = 0;
        xilReadData((MemUnit_T *) &dataWidth_yaw_err_limit, sizeData);
        uint8_T scopeID_yaw_err_limit = 0;
        xilReadData((MemUnit_T *) &scopeID_yaw_err_limit, sizeScopeID);
        real_T yaw_err_limit = 0;
        xilReadData((MemUnit_T *) &yaw_err_limit, (uint32_T) sizeof(real_T));



        out = bigM_func_ZnbXGAflwgs2b5K0HMbETH(T2F_1, T2F_2, T2F_3, T2F_4, b, A_1, A_2, A_3, A_4, beq, Aeq_1, Aeq_2, Aeq_3, Aeq_4, lb_1, lb_2, lb_3, lb_4, ub_1, ub_2, ub_3, ub_4, T1, T2, T3, T4, yaw_err_limit);



        MemUnit_T responseId = XIL_RESPONSE_OUTPUT_DATA;
        if (xilWriteData(&responseId, (uint32_T) sizeof(MemUnit_T)) != XIL_DATA_STREAM_SUCCESS) {
            return XIL_INTERFACE_COMMS_FAILURE;
        }

        if (xilWriteData((MemUnit_T *) &out, (uint32_T) sizeof(int32_T)) != XIL_DATA_STREAM_SUCCESS) {
            return XIL_INTERFACE_COMMS_FAILURE;
        }

        if (scopeID_T1 > 0) {
            if (xilWriteData((MemUnit_T *) T1, dataWidth_T1 * ((uint32_T) sizeof(real_T))) != XIL_DATA_STREAM_SUCCESS) {
                return XIL_INTERFACE_COMMS_FAILURE;
            }
        }

        if (scopeID_T2 > 0) {
            if (xilWriteData((MemUnit_T *) T2, dataWidth_T2 * ((uint32_T) sizeof(real_T))) != XIL_DATA_STREAM_SUCCESS) {
                return XIL_INTERFACE_COMMS_FAILURE;
            }
        }

        if (scopeID_T3 > 0) {
            if (xilWriteData((MemUnit_T *) T3, dataWidth_T3 * ((uint32_T) sizeof(real_T))) != XIL_DATA_STREAM_SUCCESS) {
                return XIL_INTERFACE_COMMS_FAILURE;
            }
        }

        if (scopeID_T4 > 0) {
            if (xilWriteData((MemUnit_T *) T4, dataWidth_T4 * ((uint32_T) sizeof(real_T))) != XIL_DATA_STREAM_SUCCESS) {
                return XIL_INTERFACE_COMMS_FAILURE;
            }
        }

        free(T1);
        free(T2);
        free(T3);
        free(T4);

        break;
    }

    default:
        return XIL_INTERFACE_UNKNOWN_FCNID;
    }

    return XIL_INTERFACE_SUCCESS;
}

XIL_INTERFACE_ERROR_CODE xilGetTargetToHostData(uint32_T xilFcnId, XIL_COMMAND_TYPE_ENUM xilCommandType, uint32_T xilCommandIdx, XILIOData **xilIOData, MemUnit_T responseId, uint32_T serverFcnId)
{
    UNUSED_PARAMETER(xilFcnId);
    UNUSED_PARAMETER(xilCommandType);
    UNUSED_PARAMETER(xilCommandIdx);
    UNUSED_PARAMETER(xilIOData);
    UNUSED_PARAMETER(responseId);
    UNUSED_PARAMETER(serverFcnId);

    return XIL_INTERFACE_UNKNOWN_TID;
}

XIL_INTERFACE_ERROR_CODE xilGetTargetToHostPreData(uint32_T xilFcnId, XIL_COMMAND_TYPE_ENUM xilCommandType, uint32_T xilCommandIdx, XILIOData **xilIOData, MemUnit_T responseId, uint32_T serverFcnId)
{
    UNUSED_PARAMETER(xilFcnId);
    UNUSED_PARAMETER(xilCommandType);
    UNUSED_PARAMETER(xilCommandIdx);
    UNUSED_PARAMETER(xilIOData);
    UNUSED_PARAMETER(responseId);
    UNUSED_PARAMETER(serverFcnId);

    return XIL_INTERFACE_UNKNOWN_TID;
}

