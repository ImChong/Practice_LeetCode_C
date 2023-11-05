/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\01_Array\05_generateMatrix\src\generateMatrix_simulation.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-11-05 13:16:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-05 21:21:19
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 螺旋矩阵II头文件 - 模拟法
 */
#include <stdlib.h>
#include "methodCfg.h"
#include "generateMatrix.h"

#if SIMULATION_METHOD_EN
/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 螺旋矩阵II
 * =================================================================================
 * @param {int} n                       矩阵大小
 * @param {int} *returnSize             返回数组大小
 * @param {int} **returnColumnSizes     返回数组列大小
 * @return {int} **ans                  返回数组
 */
int **generateMatrix(int n, int *returnSize, int **returnColumnSizes) {
    int maxNum = n * n;
    int curNum = 1;
    int **matrix = (int **)malloc(sizeof(int *) * n);
    *returnSize = n;
    *returnColumnSizes = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)calloc(n, sizeof(int));
        (*returnColumnSizes)[i] = n;
    }
}

#endif /* SIMULATION_METHOD_EN */