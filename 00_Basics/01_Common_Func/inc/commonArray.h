/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\inc\commonArray.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 19:15:36
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-23 23:04:51
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用数组头文件
 */
#ifndef __COMMON_ARRAY_H
#define __COMMON_ARRAY_H

/**********************************************************************************/
/*                                                                                */
/*                               STRUCT DEFINITION                                */
/*                                                                                */
/**********************************************************************************/
/* 测试数据结构定义 */
struct InputStruct {
    int *Arr;                       /* 输入数组 */
    int target;                     /* 输入目标值 */
};

/* 输出数据结构定义 */
struct outputStruct {
    int rtnSize;                    /* 输出返回数组大小 */
    int *rtnColSize;                /* 输出返回数组列大小 */
    int **Arr;                      /* 输出返回数组 */
};

/* 测试数据定义 */
struct TestStruct {
    char testNum;                   /* 测试编号 */
    struct InputStruct input;       /* 输入数据 */
    struct outputStruct output;     /* 期望输出 */
};

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
