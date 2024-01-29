/*
 * @FilePath     : \Practice_LeetCode_C\F02_Programming_Topics\F01_Data_Structure\01_Array\05_GenerateMatrix\src\generate_matrix__layer_simulation.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-11-05 13:16:24
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-29 14:14:16
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : solution source file - 螺旋矩阵II头文件 - 按层模拟法
 */
/* Standard header file (标准头文件) */
#include <stdlib.h>
/* solution method configuration file (解题方法配置文件) */
#include "F02_Programming_Topics/F01_Data_Structure/01_Array/05_GenerateMatrix/cfg/method_cfg.h"
/* solution header file (题解头文件) */
#include "F02_Programming_Topics/F01_Data_Structure/01_Array/05_GenerateMatrix/inc/generate_matrix.h"

#if LAYER_SIMULATION_METHOD_EN
/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 螺旋矩阵II
 * 可以将矩阵看成若干层，首先填入矩阵最外层的元素，其次填入矩阵次外层的元素，直到填入矩阵最内层的元素。
 * =================================================================================
 * @param {int} n                       矩阵大小
 * @param {int} *returnSize             返回数组大小
 * @param {int} **returnColumnSizes     返回数组列大小
 * @return {int} **ans                  返回数组
 */
int **generateMatrix(int n, int *returnSize, int **returnColumnSizes) {
    int num = 1;                                                            /* 当前值 */

    /* 初始化矩阵，矩阵内数值均为 0 */
    int **matrix = (int **)malloc(sizeof(int *) * n);       /* NOLINT */
    *returnSize = n;
    *returnColumnSizes = (int *)malloc(sizeof(int) * n);        /* NOLINT */
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)calloc(n, sizeof(int));      /* NOLINT */
        (*returnColumnSizes)[i] = n;
    }

    int left = 0, right = n - 1, top = 0, bottom = n - 1;                   /* 左、右、上、下 */
    while (left <= right && top <= bottom) {                                /* 当左小于等于右 且 上小于等于下 */
        /* 从左到右 */
        for (int column = left; column <= right; column++) {
            matrix[top][column] = num++;
        }
        /* 从上到下 */
        for (int row = top + 1; row <= bottom; row++) {
            matrix[row][right] = num++;
        }
        /* 从右到左 */
        for (int column = right - 1; column >= left; column--) {
            matrix[bottom][column] = num++;
        }
        /* 从下到上 */
        for (int row = bottom - 1; row > top; row--) {
            matrix[row][left] = num++;
        }
        left++;                                                             /* 左自增 */
        right--;                                                            /* 右自减 */
        top++;                                                              /* 上自增 */
        bottom--;                                                           /* 下自减 */
    }
    return matrix;                                                          /* 返回二维数组 */
}

#endif /* LAYER_SIMULATION_METHOD_EN */
