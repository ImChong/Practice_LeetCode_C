/*
 * @FilePath     : \Practice_LeetCode_C\F01_Common_Functions\inc\common_array.h
 * @Author       : Chong Liu
 * @CreateDate   : 2024-01-09 17:28:45
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-27 14:28:48
 * =================================================================================
 * Copyright (c) 2024 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : Common array header file
 */
#ifndef F01_COMMON_FUNCTIONS_INC_COMMON_ARRAY_H_
#define F01_COMMON_FUNCTIONS_INC_COMMON_ARRAY_H_

/* Common function header file (通用头文件) */
#include "F01_Common_Functions/inc/common_def/common_type_def.h"

/**********************************************************************************/
/*                                                                                */
/*                                MACRO CONSTANTS                                 */
/*                                                                                */
/**********************************************************************************/
/* Whether the array is need to be sorted before comparing */
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
int Array_Sort(int *arr, int arr_size);                      /* Sort array in place */
int Array_Sort2D(int **arr_2d, int arr_size, int *arr_col_sizes); /* Sort 2D array in place */
int Array_Reverse(int *arr, int left_index, int right_index); /* Reverse array in place */

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
int Array_Print(int *arr, int arr_size);                      /* Print array */
int Array_Print2D(int **arr_2d, int arr_size, int *arr_col_sizes); /* Print 2D array */
int Array_Free(int **p_arr);                                /* Free array */
int Array_Free2D(int ***p_arr_2d, int arr_size);                /* Free 2D array */

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

#endif /* F01_COMMON_FUNCTIONS_INC_COMMON_ARRAY_H_ */
