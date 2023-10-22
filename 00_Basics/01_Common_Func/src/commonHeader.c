/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\src\commonHeader.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-22 11:55:54
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-22 12:11:34
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用源文件
 */
#include "commonHeader.h"

/**********************************************************************************/
/*                                                                                */
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 验证答案
 * =================================================================================
 * @param {char} testNum    测试编号
 * @param {int} expect      预期
 * @param {int} actual      实际
 * @return {void}
 */
void validateAnswer(char testNum, int expect, int actual) {
    if (expect == actual) {
        printf("✅ Test %c Passed\n", testNum);
    } else {
        printf("❌ Test %c Failed\n", testNum);
    }
}