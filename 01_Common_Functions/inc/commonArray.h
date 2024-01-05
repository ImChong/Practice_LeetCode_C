/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\inc\commonArray.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 19:15:36
 * @LastEditors: Chong Liu liuc12@miamioh.edu
 * @LastEditTime: 2024-01-05 18:20:44
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用数组头文件
 */
#ifndef __COMMON_ARRAY_H    /* NOLINT(build/header_guard) */
#define __COMMON_ARRAY_H    /* NOLINT(build/header_guard) */

/**********************************************************************************/
/*                                                                                */
/*                                MACRO FUNCTIONS                                 */
/*                                                                                */
/**********************************************************************************/
#define ARR_SIZE(arr)       (sizeof(arr) / sizeof((arr)[0]))    /* 获取数组长度：如果以地址形式传入则会报错 */

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
int compareElements(const void *a, const void *b);              /* 比较元素 */
int ArraySort(int *arr, int arrSize);                           /* 排序数组 */
int ArraySort2D(int **arr, int arrSize, int *arrColSizes);      /* 排序二维数组 */

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
int ArrayPrint(int *arr, int arrSize);                          /* 打印数组 */
int ArrayPrint2D(int **arr, int arrSize, int *arrColSizes);     /* 打印二维数组 */
int ArrayFree(int **arrPtr);                                    /* 释放数组 */
int ArrayFree2D(int ***arrPtr, int arrSize);                    /* 释放二维数组 */

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
int ValidateArray(char testNum,
                  int *expectArr, int expectLen,
                  int *actualArr, int actualLen,
                  int needSort);                              /* 验证数组 */
int validate2DArray(char testNum,
                    int **expect2DArr, int expectRtnRowSize, int *expectRtnColSize,
                    int **actual2DArr, int actualRtnRowSize, int *actualRtnColSize,
                    int needSort);                          /* 验证二维数组 */


#endif  /* __COMMON_ARRAY_H */  /* NOLINT(build/header_guard) */
