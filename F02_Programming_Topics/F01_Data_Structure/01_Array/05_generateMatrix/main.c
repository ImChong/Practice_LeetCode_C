/*
 * @FilePath     : \Practice_LeetCode_C\F02_Programming_Topics\F01_Data_Structure\01_Array\05_generateMatrix\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-15 02:26:35
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : leetcode 59.螺旋矩阵II：https://leetcode.cn/problems/spiral-matrix-ii/
 *      https://programmercarl.com/0059.%E8%9E%BA%E6%97%8B%E7%9F%A9%E9%98%B5II.html
 */
/* solution header file (题解头文件) */
#include "generateMatrix.h"
/* Standard header file (标准头文件) */
#include <stdio.h>
#include <stdlib.h>
/* Common function header file (通用头文件) */
#include "commonTypeDef.h"
#include "commonArray.h"
/* solution method configuration file (解题方法配置文件) */
#include "methodCfg.h"

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: Test 1
 * Input: n = 3
 * Output: [[1,2,3],[8,9,4],[7,6,5]]
 * =================================================================================
 * @return {void}
 */
void Test1(void) {
    /* Function call (函数调用) */
    int n = 3;
    int actualRtnRowSize = 0;
    int *actualRtnColSize = NULL;
    int **actual2DArr = generateMatrix(n, &actualRtnRowSize, &actualRtnColSize);

    /* Expect result (期望结果) */
    int expectRtnRowSize = 3;
    int expectRtnColSize[] = {3, 3, 3};
    int *expect2DArr[] = {
        (int[]){1, 2, 3},
        (int[]){8, 9, 4},
        (int[]){7, 6, 5}
    };

    /* Validate result (验证函数调用结果) */
    Validate_Array2D('1',
                    expect2DArr, expectRtnRowSize, expectRtnColSize,
                    actual2DArr, actualRtnRowSize, actualRtnColSize,
                    SORT_FALSE);

    /* Free memory (释放内存) */
    Array_Free2D(&actual2DArr, actualRtnRowSize);
    free(actualRtnColSize);
}

/**
 * @description: Test 2
 * Input: n = 1
 * Output: [[1]]
 * =================================================================================
 * @return {void}
 */
void Test2(void) {
    /* Function call (函数调用) */
    int n = 1;
    int actualRtnRowSize = 0;
    int *actualRtnColSize = NULL;
    int **actual2DArr = generateMatrix(n, &actualRtnRowSize, &actualRtnColSize);

    /* Expect result (期望结果) */
    int expectRtnRowSize = 1;
    int expectRtnColSize[] = {1};
    int *expect2DArr[] = {
        (int[]){1}
    };

    /* Validate result (验证函数调用结果) */
    Validate_Array2D('2',
                    expect2DArr, expectRtnRowSize, expectRtnColSize,
                    actual2DArr, actualRtnRowSize, actualRtnColSize,
                    SORT_FALSE);

    /* Free memory (释放内存) */
    Array_Free2D(&actual2DArr, actualRtnRowSize);
    free(actualRtnColSize);
}

/**
 * @description: Test 3
 * Input: n = 4
 * Output: [[1,2,3,4],[12,13,14,5],[11,16,15,6],[10,9,8,7]]
 * =================================================================================
 * @return {void}
 */
void Test3(void) {
    /* Function call (函数调用) */
    int n = 4;
    int actualRtnRowSize = 0;
    int *actualRtnColSize = NULL;
    int **actual2DArr = generateMatrix(n, &actualRtnRowSize, &actualRtnColSize);

    /* Expect result (期望结果) */
    int expectRtnRowSize = 4;
    int expectRtnColSize[] = {4, 4, 4, 4};
    int *expect2DArr[] = {
        (int[]){1,  2,  3,  4},
        (int[]){12, 13, 14, 5},
        (int[]){11, 16, 15, 6},
        (int[]){10, 9,  8,  7}
    };

    /* Validate result (验证函数调用结果) */
    Validate_Array2D('3',
                    expect2DArr, expectRtnRowSize, expectRtnColSize,
                    actual2DArr, actualRtnRowSize, actualRtnColSize,
                    SORT_FALSE);

    /* Free memory (释放内存) */
    Array_Free2D(&actual2DArr, actualRtnRowSize);
    free(actualRtnColSize);
}

/**********************************************************************************/
/*                                                                                */
/*                                  MAIN FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 主函数
 * =================================================================================
 * @param {int} argc        程序入参个数
 * @param {char} *argv[]    程序入参字符串数组
 * @return {int}            程序运行状态
 */
int main(int argc, const char *argv[]) {
#if LAYER_SIMULATION_METHOD_EN
    printf("LAYER_SIMULATION_METHOD_EN\r\n");
#elif SIMULATION_METHOD_EN
    printf("SIMULATION_METHOD_EN\r\n");
#endif
    Test1();
    Test2();
    Test3();
    return 0;
}
