/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\inc\commonArray.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 19:15:36
 * @LastEditors: Chong Liu liuc12@miamioh.edu
 * @LastEditTime: 2024-01-05 18:50:43
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : Common array header file
 */
#ifndef __COMMON_ARRAY_H /* NOLINT(build/header_guard) */
#define __COMMON_ARRAY_H /* NOLINT(build/header_guard) */

/**********************************************************************************/
/*                                                                                */
/*                                MACRO FUNCTIONS                                 */
/*                                                                                */
/**********************************************************************************/
#define ARR_SIZE(arr) (sizeof(arr) / sizeof((arr)[0])) /* 获取数组长度：如果以地址形式传入则会报错 */

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
int Array_CmpElement(const void *a, const void *b);         /* 比较元素 */
int Array_Sort(int *arr, int arrSize);                      /* 排序数组 */
int Array_Sort2D(int **arr, int arrSize, int *arrColSizes); /* 排序二维数组 */
int Array_Reverse(int *arr, int leftIndex, int rightIndex); /* 反转数组 */

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
int Array_Print(int *arr, int arrSize);                      /* 打印数组 */
int Array_Print2D(int **arr, int arrSize, int *arrColSizes); /* 打印二维数组 */
int Array_Free(int **arrPtr);                                /* 释放数组 */
int Array_Free2D(int ***arrPtr, int arrSize);                /* 释放二维数组 */

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
int Validate_Array(char testNum, int *expectArr, int expectLen, int *actualArr, int actualLen,
                   int needSort); /* 验证数组 */
int Validate_Array2D(char testNum, int **expect2DArr, int expectRtnRowSize, int *expectRtnColSize, int **actual2DArr,
                     int actualRtnRowSize, int *actualRtnColSize, int needSort); /* 验证二维数组 */

#endif /* __COMMON_ARRAY_H */ /* NOLINT(build/header_guard) */
