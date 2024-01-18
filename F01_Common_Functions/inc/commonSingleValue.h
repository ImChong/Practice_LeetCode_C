/*
 * @FilePath     : \Practice_LeetCode_C\01_Common_Functions\inc\commonSingleValue.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 13:42:27
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-09 01:27:32
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : Common single value header file
 */
#ifndef F01_COMMON_FUNCTIONS_INC_COMMONSINGLEVALUE_H_
#define F01_COMMON_FUNCTIONS_INC_COMMONSINGLEVALUE_H_

/**********************************************************************************/
/*                                                                                */
/*                                MACRO FUNCTIONS                                 */
/*                                                                                */
/**********************************************************************************/
#define type_of_ptr(x) _Generic((x), int* : "int*", float* : "float*", double* : "double*", default : "other")
#define type_of(x) _Generic((x), int : "int", float : "float", double : "double", default : type_of_ptr(x))
#define MAX(a, b) ((a) > (b) ? (a) : (b)) /* Get maximum value */
#define MIN(a, b) ((a) < (b) ? (a) : (b)) /* Get minimum value */

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
int Validate_SingleValue(char testNum, int expect, int actual); /* Validate single value */

#endif /* F01_COMMON_FUNCTIONS_INC_COMMONSINGLEVALUE_H_ */
