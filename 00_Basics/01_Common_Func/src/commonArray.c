/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\src\commonArray.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-22 09:31:20
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-22 22:44:10
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用数组源文件
 */
#include <stdio.h>
#include <stdlib.h>
#include "commonArray.h"

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 打印数组
 * =================================================================================
 * @param {int} *arr            数组
 * @param {int} arrSize         数组大小
 * @return {void}
 */
void printArray(int *arr, int arrSize) {
    printf("Arr: ");
    for (int i = 0; i < arrSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * @description: 打印二维数组
 * =================================================================================
 * @param {int} **result
 * @param {int} returnSize
 * @param {int} *returnColumnSizes
 * @return {void}
 */
void print2DArray(int **result, int returnSize, int *returnColumnSizes) {
    printf("Ans: [\n");
    for (int i = 0; i < returnSize; i++) {
        printf("  [");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j < returnColumnSizes[i] - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }
    printf("]\n");
}

/**
 * @description: 释放二维数组
 * =================================================================================
 * @param {int} ***result
 * @param {int} *returnSize
 * @param {int} **returnColumnSizes
 * @return {void}
 */
void free2DArray(int ***result, int *returnSize, int **returnColumnSizes) {
    for (int i = 0; i < *returnSize; i++) {
        free((*result)[i]);
    }
    free(*result);
    free(*returnColumnSizes);
}

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 验证答案
 * =================================================================================
 * @param {char} testNum        测试编号
 * @param {int} *expectNums     预期结果
 * @param {int} expectLen       预期结果长度
 * @param {int} *actualNums     实际结果
 * @param {int} actualLen       实际结果长度
 * @return {void}
 */
void validateAnswerArray(char testNum, int *expectNums, int expectLen, int *actualNums, int actualLen) {
    if (expectLen != actualLen) {
        printf("❌ Test %c Failed\n", testNum);
    }
    for (int i = 0; i < expectLen; i++) {
        if (expectNums[i] != actualNums[i]) {
            printf("❌ Test %c Failed\n", testNum);
        }
    }
    printf("✅ Test %c Passed\n", testNum);
}
