/*
 * @FilePath     : \Practice_LeetCode_C\01_Programming_Topics\08_Backtracking\01_combine\src\combine_cutBranch._gpt4.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-12-26 13:19:53
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-27 00:15:43
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 组合 - GPT4 剪枝版本
 */
/* solution method configuration file (解题方法配置文件) */
#include "methodCfg.h"
#if CUT_BRANCH_GPT4_METHOD_EN
/* Standard header file (标准头文件) */
#include <stdio.h>
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
 * @description: 回溯函数
 * =================================================================================
 * @param {int} n                       表示从 1 到 n 的整数中选择数字
 * @param {int} k                       表示需要选择 k 个不同的整数
 * @param {int} start                   回溯算法的起始数字 - 算法会从这个数字开始，向后尝试每一个可能的整数
 * @param {int} *path                   存储当前组合（路径）的数组 - 在回溯过程中，这个数组会不断地被修改
 * @param {int} depth                   当前递归的深度，也代表了 path 数组中已存储的数字的数量
 * @param {int} ***returnArray          存储所有有效组合的二维数组 - (输出参数)
 * @param {int} *returnSize             用来存储返回的组合的数量 - (输出参数)
 * @param {int} *returnColumnSizes      用来存储每个组合中整数的数量 - (输出参数)
 * @return {void}
 */
void backtrack(int n, int k, int start, int *path, int depth, int ***returnArray, int *returnSize, int *returnColumnSizes) {
    if (depth == k) {                                                                           /* 如果路径长度达到k */
        (*returnArray)[*returnSize] = (int*)malloc(k * sizeof(int));                                /* 分配内存给新的组合 */
        for (int i = 0; i < k; ++i) {                                                               /* 复制路径到新的组合 */
            (*returnArray)[*returnSize][i] = path[i];
        }
        returnColumnSizes[*returnSize] = k;                                                         /* 设置新组合的长度（其实就是k）*/
        (*returnSize)++;                                                                            /* 组合数增加 1 */
        return;                                                                                     /* 返回，进入回溯 */
    }

    if (n - start + 1 < k - depth) {                                                            /* NOTE: 剪枝 - 如果剩下的数字数量小于还需要选择的数字数量，直接返回 */
        return;
    }

    for (int i = start; i <= n; ++i) {                                                          /* 从start开始，遍历所有可能的数字 */
        path[depth] = i;                                                                            /* 将当前数字加入路径 */
        backtrack(n, k, i + 1, path, depth + 1, returnArray, returnSize, returnColumnSizes);        /* 递归调用，深入下一层 */
    }
}

/**
 * @description: 目标函数：包含所有由 n 个数中选出的 k 个不同整数的组合
 * =================================================================================
 * @param {int} n                       表示从 1 到 n 的整数中选择数字
 * @param {int} k                       表示需要选择 k 个不同的整数
 * @param {int} *returnSize             来存储返回的组合的数量 - 这是一个输出参数
 * @param {int} **returnColumnSizes     用来存储每个组合中整数的数量（对于这个问题，这个值始终是 k ）- 这也是一个输出参数
 * @return {int} **returnArray          二维数组，包含所有由 n 个数中选出的 k 个不同整数的组合
 */
int **combine(int n, int k, int *returnSize, int **returnColumnSizes) {
    *returnSize = 0;                                                                            /* 初始化返回的组合数为0 */
    int maxReturnSize = MAX_SIZE;                                                               /* 最大可能的组合数，可根据需要调整 */
    int **returnArray = (int**)malloc(maxReturnSize * sizeof(int*));                            /* 分配返回数组的内存 */
    *returnColumnSizes = (int*)malloc(maxReturnSize * sizeof(int));                             /* 分配返回数组每行的列数的内存 */

    int* path = (int*)malloc(k * sizeof(int));                                                  /* 分配当前路径（组合）的内存 */
    backtrack(n, k, 1, path, 0, &returnArray, returnSize, *returnColumnSizes);                  /* 调用回溯函数 */
    free(path);                                                                                 /* 释放路径的内存 */
    return returnArray;                                                                         /* 返回结果数组 */
}



#endif  /* CUT_BRANCH_GPT4_METHOD_EN */
