/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\src\commonArray.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-22 09:31:20
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-23 22:08:13
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用数组源文件
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
 * @param {int} **result                返回数组
 * @param {int} returnSize              返回数组大小
 * @param {int} *returnColumnSizes      返回数组列大小
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
 * @param {int} ***result               返回数组
 * @param {int} *returnSize             返回数组大小
 * @return {void}
 */
void free2DArray(int **result, int returnSize) {
    for (int i = 0; i < returnSize; i++) {                                  /* 遍历二维数组的每一行 */
        free(result[i]);                                                        /* free每一行数组占用的空间 */
    }
    free(result);                                                           /* 最后free二维数组本身 */
}


/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 验证数组答案
 * =================================================================================
 * @param {char} testNum        测试编号
 * @param {int} *expectArr      预期结果
 * @param {int} expectLen       预期结果长度
 * @param {int} *actualArr      实际结果
 * @param {int} actualLen       实际结果长度
 * @return {void}
 */
void validateArray(char testNum, int *expectArr, int expectLen, int *actualArr, int actualLen) {
    if (expectLen != actualLen) {
        printf("❌ Test %c Failed\n", testNum);
    }
    for (int i = 0; i < expectLen; i++) {
        if (expectArr[i] != actualArr[i]) {
            printf("❌ Test %c Failed\n", testNum);
        }
    }
    printf("✅ Test %c Passed\n", testNum);
}

/**
 * @description: 验证二维数组答案
 * =================================================================================
 * @param {char} testNum                测试编号
 * @param {int} **expect2DArr           预期结果
 * @param {int} expectRtnSize           预期结果大小
 * @param {int} *expectRtnColSize       预期结果列大小
 * @param {int} **actual2DArr           实际结果
 * @param {int} actualRtnSize           实际结果大小
 * @param {int} *actualRtnColSize       实际结果列大小
 * @return {void}
 */
void validate2DArray(char testNum, int **expect2DArr, int expectRtnSize, int *expectRtnColSize,
                                int **actual2DArr, int actualRtnSize, int *actualRtnColSize) {

    bool isSuccess = true;

    if (actualRtnSize != expectRtnSize) {
        isSuccess = false;
    } else {
        for (int i = 0; i < expectRtnSize; i++) {
            if (actualRtnColSize[i] != expectRtnColSize[i]) {
                isSuccess = false;
                break;
            }
            for (int j = 0; j < expectRtnColSize[i]; j++) {
                if (actual2DArr[i][j] != expect2DArr[i][j]) {
                    isSuccess = false;
                    break;
                }
            }
        }
    }

    if (isSuccess) {
        printf("✅ Test %c passed\n", testNum);
    } else {
        printf("❌ Test %c failed\n", testNum);
    }
}