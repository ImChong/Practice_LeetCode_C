/*
 * @FilePath     : \Practice_LeetCode_C\01_Programming_Topics\08_Backtracking\01_combine\src\combine_cutBranch.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-12-26 13:19:53
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-26 23:54:14
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 组合 - 剪枝版本
 */
/* 解题方法配置文件 */
#include "methodCfg.h"
#if CUT_BRANCH_METHOD_EN
/* 标准头文件 */
#include <stdio.h>
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
int *path;          /* 记录当前 k 个数的组合 */
int pathTop;        /* 记录当前数的数量 */
int **ans;          /* 结果二维数组：记录所有 k 个数的组合 */
int ansTop;         /* 记录当前的组数 */

/**
 * @description: 回溯算法 - 剪枝解法
 * =================================================================================
 * @param {int} n               [1, n] 数据的最大范围
 * @param {int} k               k 个数的组合
 * @param {int} startNum      起始索引
 * @return {void}
 */
STATIC_FUNC void backtracking(int n, int k, int startNum) {
    if (pathTop == k) {                                         /* 当path中元素个数为k个时，我们需要将path数组放入ans二维数组中 */
        int *temp = (int*)malloc(sizeof(int) * k);                  /* path数组为我们动态申请，若直接将其地址放入二维数组，path数组中的值会随着我们回溯而逐渐变化，因此创建新的数组存储path中的值 */
        for (int i = 0; i < k; i++) {                               /* 将path数组内的数据移动至temp数组 */
            temp[i] = path[i];
        }
        ans[ansTop++] = temp;                                       /* 将temp数组放入结果二维数组的末尾 */
        return;
    }
    for (int j = startNum; j <= n - (k - pathTop) + 1; j++) {   /* NOTE: 从开始索引 startNum 遍历至最大数据范围 - 剪枝：保障剩下的数字数量大于等于还需要选择的数字数量 */
        path[pathTop++] = j;                                        /* 将当前结点 j 放入path数组 */
        backtracking(n, k, j + 1);                                  /* 进行递归，并将开始索引设置为 j + 1 */
        pathTop--;                                                  /* 将记录当前数的数量 pathTop - 1：进行回溯，将数组最上层结点弹出 */
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


#endif  /* CUT_BRANCH_METHOD_EN */
