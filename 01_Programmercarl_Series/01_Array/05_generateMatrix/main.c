/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\01_Array\05_generateMatrix\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-05 21:41:12
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 59.螺旋矩阵II：https://leetcode.cn/problems/spiral-matrix-ii/
 * https://programmercarl.com/0059.%E8%9E%BA%E6%97%8B%E7%9F%A9%E9%98%B5II.html
 *
 * 给一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
 *
 */
#include <stdio.h>
#include "generateMatrix.h"

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 测试 1
 * 输入：n = 3
 * 输出：[[1,2,3],[8,9,4],[7,6,5]]
 * =================================================================================
 * @return {void}
 */
void test_1(void) {
    /* 实际结果 */
    int n = 3;
    int returnSize = 0;
    int *returnColumnSizes = NULL;
    int **ans = generateMatrix(n, &returnSize, &returnColumnSizes);

    /* 期望结果 */

    /* 测试结果 */

}

/**
 * @description: 测试 2
 * 输入：n = 1
 * 输出：[[1]]
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    /* 实际结果 */

    /* 期望结果 */

    /* 测试结果 */

}

/**
 * @description: 测试 3
 * 输入：n = 4
 * 输出：[[1,2,3,4],[12,13,14,5],[11,16,15,6],[10,9,8,7]]
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    /* 实际结果 */

    /* 期望结果 */

    /* 测试结果 */

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
    printf("LAYER_SIMULATION_METHOD_EN\n");
#elif SIMULATION_METHOD_EN
    printf("SIMULATION_METHOD_EN\n");
#endif
    test_1();
    test_2();
    test_3();
    return 0;
}
