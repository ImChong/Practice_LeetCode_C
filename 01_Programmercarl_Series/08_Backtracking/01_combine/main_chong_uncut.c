/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\08_Backtracking\01_combine\main_chong_uncut.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-28 09:44:35
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-09-16 14:33:03
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 77. 组合: https://leetcode.cn/problems/combinations/
 * https://programmercarl.com/0077.%E7%BB%84%E5%90%88.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
 * 解法参考：https://leetcode.cn/problems/combinations/solutions/857507/dai-ma-sui-xiang-lu-dai-ni-xue-tou-hui-s-0uql/
 *
 * NOTE：未剪枝解法
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
#define MAX_SIZE 1000000           /* 初始化大小 */

int *path;          /* 记录 k 个数的组合 */
int pathTop;        /* */
int **ans;          /* 记录所有 k 个数的组合 */
int ansTop;         /* */

/**
 * @description: 回溯算法
 * =================================================================================
 * @param {int} n               [1, n] 数据的最大范围
 * @param {int} k               k 个数的组合
 * @param {int} startIndex      起始索引
 * @return {void}
 */
void backtracking(int n, int k, int startIndex) {
    if (pathTop == k) {
        int *temp = (int*)malloc(sizeof(int) * k);
        for (int i = 0; i < k; i++) {
            temp[i] = path[i];
        }
        ans[ansTop++] = temp;
        return;
    }

    for (int j = startIndex; j <= n; j++) {
        path[pathTop++] = j;
        backtracking(n, k, j + 1);
        pathTop--;
    }
}

/**
 * @description: 目标函数：组合
 * =================================================================================
 * @param {int} n                       [1, n] 数据的最大范围
 * @param {int} k                       k 个数的组合
 * @param {int} *returnSize             返回二维数组的行数
 * @param {int} **returnColumnSizes     数组表示二维数组每行的列数
 * @return {int} **ans                  结果二维数组
 */
int **combine(int n, int k, int *returnSize, int **returnColumnSizes) {
    path = (int *)malloc(sizeof(int) * k);                              /* path数组存储符合条件的结果 */
    ans = (int **)malloc(sizeof(int *) * MAX_SIZE);                     /* ans二维数组存储符合条件的结果数组的集合。（数组足够大，避免极端情况） */
    pathTop = ansTop = 0;

    backtracking(n, k, 1);                                              /* 回溯算法 */

    *returnSize = ansTop;                                               /* 最后的返回大小为ans数组大小 */
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));    /* returnColumnSizes数组存储ans二维数组对应下标中一维数组的长度（都为k） */
    int i;
    for(i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = k;
    }

    return ans;                                                         /* 返回ans二维数组 */
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
    int n = 20;
    int k = 10;
    int returnSize;
    int *returnColumnSizes;
    int **result = combine(n, k, &returnSize, &returnColumnSizes);

    // 调用打印函数
    printCombinations(result, returnSize, k);

    // 释放内存
    for (int i = 0; i < returnSize; ++i) {
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);

    return 0;
}