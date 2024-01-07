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
/* common function configuration file (通用函数配置文件) */
#include "compileCfg.h"
#if COMMON_SINGLE_VALUE_EN         /* 在每一道题 cfg 文件夹下的 compileCfg.h 开启编译宏定义 */
/* standard header file (标准头文件) */
#include <stdio.h>
/* 常用头文件 */
#include "commonTypeDef.h"
#include "commonSingleValue.h"

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
