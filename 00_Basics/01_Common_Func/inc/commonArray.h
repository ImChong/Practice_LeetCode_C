/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\inc\commonArray.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 19:15:36
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-22 13:30:42
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

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
void validateAnswerArray(char testNum, int *expectNums, int expectLen, int *actualNums, int actualLen);


#endif  /* __COMMON_ARRAY_H */
