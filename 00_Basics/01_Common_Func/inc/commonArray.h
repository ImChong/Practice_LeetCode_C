/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\inc\commonArray.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 19:15:36
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-18 10:51:31
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用数组头文件
 */
#ifndef __COMMON_ARRAY_H
#define __COMMON_ARRAY_H

/**********************************************************************************/
/*                                                                                */
/*                                MACRO FUNCTIONS                                 */
/*                                                                                */
/**********************************************************************************/
#define ARR_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))          /* 获取数组长度 */

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
void printArray(int *arr, int arrSize);     /* 打印数组 */
void print2DArray(int **result, int returnSize, int *returnColumnSizes);        /* 打印二维数组 */
void freeArray(int *result);        /* 释放数组 */
void free2DArray(int **result, int returnSize);     /* 释放二维数组 */
void sort2DArray(int **arr, int arrSize, int *arrColSizes);       /* 排序二维数组 */

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
void validateArray(char testNum, int *expectArr, int expectLen, int *actualArr, int actualLen);     /* 验证数组 */
void validate2DArray(char testNum,
                            int **expect2DArr, int expectRtnSize, int *expectRtnColSize,
                            int **actual2DArr, int actualRtnSize, int *actualRtnColSize,
                            int needSort);        /* 验证二维数组 */


#endif  /* __COMMON_ARRAY_H */
