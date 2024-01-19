/*
 * @FilePath     : \Practice_LeetCode_C\F01_Common_Functions\inc\commonArray.h
 * @Author       : Chong Liu
 * @CreateDate   : 2024-01-09 17:28:45
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-20 00:47:35
 * =================================================================================
 * Copyright (c) 2024 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : Common array header file
 */
#ifndef F01_COMMON_FUNCTIONS_INC_COMMONARRAY_H_
#define F01_COMMON_FUNCTIONS_INC_COMMONARRAY_H_

/* Common function header file (通用头文件) */
#include "commonTypeDef.h"

/**********************************************************************************/
/*                                                                                */
/*                                MACRO CONSTANTS                                 */
/*                                                                                */
/**********************************************************************************/
#define SORT_TRUE COMMON_TRUE
#define SORT_FALSE COMMON_FALSE

/**********************************************************************************/
/*                                                                                */
/*                                MACRO FUNCTIONS                                 */
/*                                                                                */
/**********************************************************************************/
/* Get array size. if arr is a pointer other than array, macro will not work */
#define ARR_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
int Array_CmpElement(const void *a, const void *b);         /* Compare array element */
int Array_Sort(int *arr, int arrSize);                      /* Sort array in place */
int Array_Sort2D(int **arr, int arrSize, int *arrColSizes); /* Sort 2D array in place */
int Array_Reverse(int *arr, int leftIndex, int rightIndex); /* Reverse array in place */

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
int Array_Print(int *arr, int arrSize);                      /* Print array */
int Array_Print2D(int **arr, int arrSize, int *arrColSizes); /* Print 2D array */
int Array_Free(int **arrPtr);                                /* Free array */
int Array_Free2D(int ***arrPtr, int arrSize);                /* Free 2D array */

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/* Validate array */
int Validate_Array(char testNum, int *expectArr, int expectLen, int *actualArr, int actualLen, int needSort);
/* Validate 2D array */
int Validate_Array2D(char testNum, int **expect2DArr, int expectRtnRowSize, int *expectRtnColSize, int **actual2DArr,
                     int actualRtnRowSize, int *actualRtnColSize, int needSort);

#endif /* F01_COMMON_FUNCTIONS_INC_COMMONARRAY_H_ */
