/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\08_Backtracking\01_combine\main_chong_gpt4.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-28 09:44:35
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-09-16 16:38:24
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 77. 组合: https://leetcode.cn/problems/combinations/
 * 解法参考：ChatGPT - 4
 *
 * NOTE：剪枝解法
 *
 */
#include <stdio.h>
#include <stdlib.h>

/* ==================================================================================================== */
/* ==================================================================================================== */
/* TODO: 目标函数 */
/*
    回溯算法理论基础：https://programmercarl.com/%E5%9B%9E%E6%BA%AF%E7%AE%97%E6%B3%95%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80.html
        回溯法解决的问题都可以抽象为树形结构（N叉树），用树形结构来理解回溯
        因为回溯法解决的都是在集合中递归查找子集，集合的大小就构成了树的宽度，递归的深度，都构成的树的深度。
        递归就要有终止条件，所以必然是一棵高度有限的树（N叉树）。
*/
/* ==================================================================================================== */
/* ==================================================================================================== */




/**
 * @description: 目标函数：组合
 * =================================================================================
 * @param {int} n
 * @param {int} k
 * @param {int} *returnSize
 * @param {int} **returnColumnSizes
 * @return {int} **
 */
int **combine(int n, int k, int *returnSize, int **returnColumnSizes){
    return NULL;
}

/* ==================================================================================================== */
/* ==================================================================================================== */
/* ==================================================================================================== */
/* ==================================================================================================== */

/**
 * @description: 打印组合
 * =================================================================================
 * @param {int} **result        二维数组
 * @param {int} returnSize      二维数组的行数
 * @param {int} k               k 个数的组合
 * @return {void}
 */
void printCombinations(int **result, int returnSize, int k) {
    printf("[\n");
    for (int i = 0; i < returnSize; ++i) {
        printf("  [");
        for (int j = 0; j < k; ++j) {
            printf("%d", result[i][j]);
            if (j < k - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }
    printf("]\n");

    printf("nums of combination: %d\n", returnSize);
}

/**
 * @description: 主函数
 * =================================================================================
 * @param {int} argc        程序入参个数
 * @param {char} *argv[]    程序入参字符串数组
 * @return {int}            程序运行状态
 */
int main(int argc, const char *argv[]) {
    int n = 12;
    int k = 8;
    int returnSize;
    int *returnColumnSizes;
    int **result = combine(n, k, &returnSize, &returnColumnSizes);

    /* 调用打印函数 */
    printCombinations(result, returnSize, k);

    /* 释放内存 */
    for (int i = 0; i < returnSize; ++i) {
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);

    return 0;
}