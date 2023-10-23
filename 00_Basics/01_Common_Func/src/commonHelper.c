/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\src\commonHelper.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-22 11:55:54
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-22 13:05:40
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用通用辅助函数源文件
 */
#include <stdio.h>
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
    if (expect == actual) {
        printf("✅ Test %c Passed\n", testNum);
    } else {
        printf("❌ Test %c Failed\n", testNum);
    }
}