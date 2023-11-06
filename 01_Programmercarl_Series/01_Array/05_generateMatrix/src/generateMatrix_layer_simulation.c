/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\01_Array\05_generateMatrix\src\generateMatrix_layer_simulation.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-11-05 13:16:24
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-06 10:02:27
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 螺旋矩阵II头文件 - 按层模拟法
 */
/* 标准头文件 */
#include <stdlib.h>
/* 解题方法配置文件 */
#include "methodCfg.h"
/* 题解头文件 */
#include "generateMatrix.h"

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
    int num = 1;

    /* 初始化矩阵，矩阵内数值均为 0 */
    int **matrix = (int **)malloc(sizeof(int *) * n);
    *returnSize = n;
    *returnColumnSizes = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)calloc(n, sizeof(int));
        (*returnColumnSizes)[i] = n;
    }

    int left = 0, right = n - 1, top = 0, bottom = n - 1;
    while (left <= right && top <= bottom) {
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
        left++;
        right--;
        top++;
        bottom--;
    }
    return matrix;
}

#endif /* LAYER_SIMULATION_METHOD_EN */