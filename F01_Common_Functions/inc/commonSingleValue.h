/*
 * @FilePath     : \Practice_LeetCode_C\F01_Common_Functions\inc\commonSingleValue.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 13:42:27
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-19 06:07:11
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
/* Get the type of a pointer */
#define type_of_ptr(x) _Generic((x), int* : "int*", float* : "float*", double* : "double*", default : "other")
/* Get the type of a variable */
#define type_of(x) _Generic((x), int : "int", float : "float", double : "double", default : type_of_ptr(x))
/* Get maximum value */
#define MAX(a, b) ((a) > (b) ? (a) : (b))
/* Get minimum value */
#define MIN(a, b) ((a) < (b) ? (a) : (b))

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
int Validate_SingleValue(char testNum, int expect, int actual); /* Validate single value */

#endif /* F01_COMMON_FUNCTIONS_INC_COMMONSINGLEVALUE_H_ */
