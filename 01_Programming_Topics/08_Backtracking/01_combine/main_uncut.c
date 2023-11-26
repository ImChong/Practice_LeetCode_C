/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\08_Backtracking\01_combine\main_uncut.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-28 09:44:35
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-17 23:34:45
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 77. 组合: https://leetcode.cn/problems/combinations/
 * https://programmercarl.com/0077.%E7%BB%84%E5%90%88.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
 * 解法参考：https://leetcode.cn/problems/combinations/solutions/857507/dai-ma-sui-xiang-lu-dai-ni-xue-tou-hui-s-0uql/
 *
 * 未剪枝解法
 *
 */
#include <stdio.h>
#include <stdlib.h>

/**********************************************************************************/
/*                                                                                */
/*                                MACRO CONSTANTS                                 */
/*                                                                                */
/**********************************************************************************/
#define MAX_SIZE 1000000           /* 初始化大小 */

/**********************************************************************************/
/*                                                                                */
/*                                 GLOBAL VARIABLES                               */
/*                                                                                */
/**********************************************************************************/
int *path;          /* 记录当前 k 个数的组合 */
int pathTop;        /* 记录当前数的数量 */
int **ans;          /* 结果二维数组：记录所有 k 个数的组合 */
int ansTop;         /* 记录当前的组数 */

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/*
    回溯算法理论基础：https://programmercarl.com/%E5%9B%9E%E6%BA%AF%E7%AE%97%E6%B3%95%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80.html
        回溯法解决的问题都可以抽象为树形结构（N叉树），用树形结构来理解回溯
        因为回溯法解决的都是在集合中递归查找子集，集合的大小就构成了树的宽度，递归的深度，都构成的树的深度。
        递归就要有终止条件，所以必然是一棵高度有限的树（N叉树）。
*/
/* ============================================================================== */
/* ============================================================================== */
/**
 * @description: 回溯算法
 * =================================================================================
 * @param {int} n               [1, n] 数据的最大范围
 * @param {int} k               k 个数的组合
 * @param {int} startNum      起始索引
 * @return {void}
 */
void backtracking(int n, int k, int startNum) {
    if (pathTop == k) {                             /* 当path中元素个数为k个时，我们需要将path数组放入ans二维数组中 */
        int *temp = (int*)malloc(sizeof(int) * k);      /* path数组为我们动态申请，若直接将其地址放入二维数组，path数组中的值会随着我们回溯而逐渐变化，因此创建新的数组存储path中的值 */
        for (int i = 0; i < k; i++) {                   /* 将path数组内的数据移动至temp数组 */
            temp[i] = path[i];
        }
        ans[ansTop++] = temp;                           /* 将temp数组放入结果二维数组的末尾 */
        return;
    }

    for (int j = startNum; j <= n; j++) {           /* 从开始索引 startNum 遍历至最大数据范围 */
        path[pathTop++] = j;                            /* 将当前结点 j 放入path数组 */
        backtracking(n, k, j + 1);                      /* 进行递归，并将开始索引设置为 j + 1 */
        pathTop--;                                      /* 将记录当前数的数量 pathTop - 1：进行回溯，将数组最上层结点弹出 */
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
    pathTop = ansTop = 0;                                               /* 初始化当前数的数量 pathTop 和 当前的组数 ansTop 为 0 */

    backtracking(n, k, 1);                                              /* 回溯算法，回溯初始值为 1 */

    *returnSize = ansTop;                                               /* 最后的返回大小为当前的组数 */
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));    /* returnColumnSizes数组存储ans二维数组对应下标中一维数组的长度（都为k） */
    for(int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = k;
    }

    return ans;                                                         /* 返回ans二维数组 */
}

/**********************************************************************************/
/*                                                                                */
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
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

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 测试 1
 * =================================================================================
 * @return {void}
 */
void test_1(void) {
    /* 实际结果 */

    /* 预期结果 */

    /* 比较结果 */

}

/**
 * @description: 测试 2
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    /* 实际结果 */

    /* 预期结果 */

    /* 比较结果 */

}

/**
 * @description: 测试 3
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    /* 实际结果 */

    /* 预期结果 */

    /* 比较结果 */

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
    int n = 20;
    int k = 10;
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