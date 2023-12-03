/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\inc\commonArray.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 19:15:36
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-03 18:12:07
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
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
int printArray(int *arr, int arrSize);                          /* 打印数组 */
int print2DArray(int **arr, int arrSize, int *arrColSizes);     /* 打印二维数组 */
int freeArray(int **arrPtr);                                    /* 释放数组 */
int free2DArray(int ***arrPtr, int arrSize);                    /* 释放二维数组 */

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
int compareElements(const void *a, const void *b);              /* 比较元素 */
void sortArray(int *arr, int arrSize);                          /* 排序数组 */
void sort2DArray(int **arr, int arrSize, int *arrColSizes);     /* 排序二维数组 */
int validateArray(char testNum,
                    int *expectArr, int expectLen,
                    int *actualArr, int actualLen,
                    int needSort);                              /* 验证数组 */
int validate2DArray(char testNum,
                        int **expect2DArr, int expectRtnRowSize, int *expectRtnColSize,
                        int **actual2DArr, int actualRtnRowSize, int *actualRtnColSize,
                        int needSort);                          /* 验证二维数组 */


#endif  /* __COMMON_ARRAY_H */  /* NOLINT(build/header_guard) */
