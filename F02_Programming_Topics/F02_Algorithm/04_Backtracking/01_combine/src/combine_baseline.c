/*
 * @FilePath     : \Practice_LeetCode_C\02_Programming_Topics\08_Backtracking\01_combine\src\combine_baseline.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-12-22 16:12:53
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-31 20:34:50
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 组合 - 基线版本
 */
/* solution method configuration file (解题方法配置文件) */
#include "methodCfg.h"
#if BASELINE_METHOD_EN
/* Standard header file (标准头文件) */
#include <stdlib.h>
/* Common function header file (通用头文件) */
#include "commonTypeDef.h"
/* solution header file (题解头文件) */
#include "combine.h"

/**********************************************************************************/
/*                                                                                */
/*                                MACRO CONSTANTS                                 */
/*                                                                                */
/**********************************************************************************/
#define MAX_SIZE 1000       /* 初始化大小 */

/**********************************************************************************/
/*                                                                                */
/*                                 GLOBAL VARIABLES                               */
/*                                                                                */
/**********************************************************************************/
int *g_currArr;          /* 记录当前 k 个数的组合 */
int g_currArrTop;        /* 记录当前数的数量 */
int **g_ans2DArr;       /* 结果二维数组：记录所有 k 个数的组合 */
int g_ans2DArrTop;         /* 记录当前的组数 */

/**********************************************************************************/
/*                                                                                */
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/*
 *  回溯算法理论基础：https://programmercarl.com/%E5%9B%9E%E6%BA%AF%E7%AE%97%E6%B3%95%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80.html
 *      回溯法解决的问题都可以抽象为树形结构（N叉树），用树形结构来理解回溯
 *      因为回溯法解决的都是在集合中递归查找子集，集合的大小就构成了树的宽度，递归的深度，都构成的树的深度。
 *      递归就要有终止条件，所以必然是一棵高度有限的树（N叉树）。
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
STATIC_FUNC void backtracking(int n, int k, int startNum) {
    if (g_currArrTop == k) {
        int *temp = (int*)malloc(sizeof(int) * k);
        for (int i = 0; i < k; i++) {
            temp[i] = g_currArr[i];
        }
        g_ans2DArr[g_ans2DArrTop++] = temp;
        return;
    }

    for (int j = startNum; j <= n; j++) {
        g_currArr[g_currArrTop++] = j;
        backtracking(n, k, j + 1);
        g_currArrTop--;
    }
}

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 目标函数：组合
 * =================================================================================
 * @param {int} n                       [1, n] 数据的最大范围
 * @param {int} k                       k 个数的组合
 * @param {int} *returnSize             返回二维数组的行数
 * @param {int} **returnColumnSizes     数组表示二维数组每行的列数
 * @return {int} **g_ans2DArr                  结果二维数组
 */
int **combine(int n, int k, int *returnSize, int **returnColumnSizes) {
    g_currArr = (int *)malloc(sizeof(int) * k);
    g_ans2DArr = (int **)malloc(sizeof(int *) * MAX_SIZE);
    g_currArrTop = g_ans2DArrTop = 0;

    backtracking(n, k, 1);

    *returnSize = g_ans2DArrTop;
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
    for(int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = k;
    }

    return g_ans2DArr;
}


#endif  /* BASELINE_METHOD_EN */
