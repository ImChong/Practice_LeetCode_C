/*
 * @FilePath     : \Practice_LeetCode_C\02_Programming_Topics\08_Backtracking\01_combine\src\combine_baseline.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-12-22 16:12:53
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-31 20:14:22
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 组合 - 基线版本
 */
/* 解题方法配置文件 */
#include "methodCfg.h"
#if BASELINE_METHOD_EN
/* 标准头文件 */
#include <stdlib.h>
/* 通用头文件 */
#include "commonTypeDef.h"
/* 本文件头文件 */
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
int *g_path;          /* 记录当前 k 个数的组合 */
int g_pathTop;        /* 记录当前数的数量 */
int **g_ans;          /* 结果二维数组：记录所有 k 个数的组合 */
int g_ansTop;         /* 记录当前的组数 */

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
    if (g_pathTop == k) {                             /* 当path中元素个数为k个时，我们需要将path数组放入ans二维数组中 */
        int *temp = (int*)malloc(sizeof(int) * k);      /* path数组为我们动态申请，若直接将其地址放入二维数组，path数组中的值会随着我们回溯而逐渐变化，因此创建新的数组存储path中的值 */
        for (int i = 0; i < k; i++) {                   /* 将path数组内的数据移动至temp数组 */
            temp[i] = g_path[i];
        }
        g_ans[g_ansTop++] = temp;                           /* 将temp数组放入结果二维数组的末尾 */
        return;
    }

    for (int j = startNum; j <= n; j++) {           /* 从开始索引 startNum 遍历至最大数据范围 */
        g_path[g_pathTop++] = j;                            /* 将当前结点 j 放入path数组 */
        backtracking(n, k, j + 1);                      /* 进行递归，并将开始索引设置为 j + 1 */
        g_pathTop--;                                      /* 将记录当前数的数量 g_pathTop - 1：进行回溯，将数组最上层结点弹出 */
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
 * @return {int} **g_ans                  结果二维数组
 */
int **combine(int n, int k, int *returnSize, int **returnColumnSizes) {
    g_path = (int *)malloc(sizeof(int) * k);                              /* path数组存储符合条件的结果 */
    g_ans = (int **)malloc(sizeof(int *) * MAX_SIZE);                     /* ans二维数组存储符合条件的结果数组的集合。（数组足够大，避免极端情况） */
    g_pathTop = g_ansTop = 0;                                               /* 初始化当前数的数量 g_pathTop 和 当前的组数 g_ansTop 为 0 */

    backtracking(n, k, 1);                                              /* 回溯算法，组合初始范围为 1 */

    *returnSize = g_ansTop;                                               /* 最后的返回大小为当前的组数 */
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));    /* returnColumnSizes数组存储ans二维数组对应下标中一维数组的长度（都为k） */
    for(int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = k;
    }

    return g_ans;                                                         /* 返回ans二维数组 */
}


#endif  /* BASELINE_METHOD_EN */
