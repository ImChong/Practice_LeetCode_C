/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\inc\commonArray.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 19:15:36
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-23 19:07:10
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
void printArray(int *arr, int arrSize);
void print2DArray(int **result, int returnSize, int *returnColumnSizes);
void freeArray(int *result);
void free2DArray(int **result, int returnSize);

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
void validateArray(char testNum, int *expectArr, int expectLen, int *actualArr, int actualLen);
void validate2DArray(char testNum, int **expect2DArr, int expectRtnSize, int *expectRtnColSize,
                                int **actual2DArr, int actualRtnSize, int *actualRtnColSize);


#endif  /* __COMMON_ARRAY_H */
