/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\src\commonHelper.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-22 11:55:54
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-18 13:44:10
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用通用辅助函数源文件
 */
/* 标准头文件 */
#include <stdio.h>
/* 常用头文件 */
#include "commonHelper.h"

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
 * @return {void}
 */
void validateSingleValue(char testNum, int expect, int actual) {
    printf("=========================\n");
    if (expect == actual) {
        printf(" - ✅ Test %c Passed\n", testNum);
    } else {
        printf(" - ❌ Test %c Failed\n", testNum);
    }
    printf("=========================\n");
    printf("- Expect: %d\n", expect);
    printf("- Actual: %d\n", actual);
    printf("\n");
}