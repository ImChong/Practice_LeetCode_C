/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\01_Array\05_generateMatrix\src\generateMatrix_simulation.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-11-05 13:16:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-05 22:56:11
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 螺旋矩阵II头文件 - 模拟法
 */
/* 标准头文件 */
#include <stdlib.h>
/* 解题方法配置文件 */
#include "methodCfg.h"
/* 题解头文件 */
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
 * 模拟矩阵的生成。按照要求，初始位置设为矩阵的左上角，初始方向设为向右。
 * 若下一步的位置超出矩阵边界，或者是之前访问过的位置，则顺时针旋转，进入下一个方向。
 * 如此反复直至填入 n^2 个元素。
 * =================================================================================
 * @param {int} n                       矩阵大小
 * @param {int} *returnSize             返回数组大小
 * @param {int} **returnColumnSizes     返回数组列大小
 * @return {int} **ans                  返回数组
 */
int **generateMatrix(int n, int *returnSize, int **returnColumnSizes) {
    int maxNum = n * n;                                                                 /* 最大值 */
    int curNum = 1;                                                                     /* 当前值 */

    /* 初始化二维数组 */
    int **matrix = (int **)malloc(sizeof(int *) * n);                                   /* 二维数组 */
    *returnSize = n;                                                                    /* 返回数组大小 */
    *returnColumnSizes = (int *)malloc(sizeof(int) * n);                                /* 返回数组列大小 */
    for (int i = 0; i < n; i++) {                                                       /* 二维数组初始化 */
        matrix[i] = (int *)calloc(n, sizeof(int));                                          /* 将每一行都初始化为0 */
        (*returnColumnSizes)[i] = n;                                                        /* 将每一行的列大小都初始化为n */
    }

    int row = 0, column = 0;                                                            /* 行、列 */
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};                          /* 方向 */
    int directionIndex = 0;                                                             /* 方向索引 */
    while (curNum <= maxNum) {                                                          /* 当前值小于等于最大值 */
        matrix[row][column] = curNum;                                                       /* 赋值 */
        curNum++;                                                                           /* 当前值自增 */
        int nextRow = row + directions[directionIndex][0];                                  /* 下一行 */
        int nextColumn = column + directions[directionIndex][1];                            /* 下一列 */
        if (nextRow < 0 || nextRow >= n || nextColumn < 0 || nextColumn >= n || matrix[nextRow][nextColumn] != 0) {     /* 越界或者已经赋值 */
            directionIndex = (directionIndex + 1) % 4;                                          /* 方向索引自增 */
        }
        row = row + directions[directionIndex][0];                                          /* 行自增 */
        column = column + directions[directionIndex][1];                                    /* 列自增 */
    }
    return matrix;                                                                      /* 返回二维数组 */
}

#endif /* SIMULATION_METHOD_EN */