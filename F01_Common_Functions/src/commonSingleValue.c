/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\src\commonSingleValue.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-22 11:55:54
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-23 11:14:55
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用单值函数源文件
 */
/* Common function configuration file (通用函数配置文件) */
#include "compile_cfg.h"
#if COMMON_SINGLE_VALUE_EN /* whether compile this file, the definition of this macro can be found in compileCfg.h */
/* Header file (本文件头文件) */
#include "commonSingleValue.h"
/* Standard header file (标准头文件) */
#include <stdio.h>
/* Common function header file (通用头文件) */
#include "commonTypeDef.h"

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 验证单一值
 * =================================================================================
 * @param {char} testNum    测试编号
 * @param {int} expect      预期
 * @param {int} actual      实际
 * @return {int}            验证结果: 0-成功，-1-失败
 */
int Validate_SingleValue(char testNum, int expect, int actual) {
    int isSuccess = COMMON_TRUE;

    if (expect != actual) {
        isSuccess = COMMON_FALSE;
    }

    printf("=========================\n");
    if (isSuccess) {
        printf(" - ✅ Test %c Passed\n", testNum);
    } else {
        printf(" - ❌ Test %c Failed\n", testNum);
    }
    printf("=========================\n");
    printf("- Expect: %d\n", expect);
    printf("- Actual: %d\n", actual);
    printf("\n");
    if (isSuccess) {
        return COMMON_OK;
    } else {
        return COMMON_ERR;
    }
}


#endif      /* COMMON_SINGLE_VALUE_EN */
