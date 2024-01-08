/*
 * @FilePath     : \Practice_LeetCode_C\01_Common_Functions\inc\commonSingleValue.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 13:42:27
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-06 00:54:05
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : Common single value header file
 */
#ifndef __COMMON_SINGLE_VALUE_H   /* NOLINT(build/header_guard) */
#define __COMMON_SINGLE_VALUE_H   /* NOLINT(build/header_guard) */

/**********************************************************************************/
/*                                                                                */
/*                                MACRO FUNCTIONS                                 */
/*                                                                                */
/**********************************************************************************/
#define type_of_ptr(x)      _Generic((x), \
                                int*: "int*", \
                                float*: "float*", \
                                double*: "double*", \
                                default: "other")

#define type_of(x)          _Generic((x), \
                                int: "int", \
                                float: "float", \
                                double: "double", \
                                default: type_of_ptr(x))

#define MAX(a, b)           ((a) > (b) ? (a) : (b))     /* 取最大值 */
#define MIN(a, b)           ((a) < (b) ? (a) : (b))     /* 取最小值 */

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
int Validate_SingleValue(char testNum, int expect, int actual);     /* 验证单个值 */


#endif  /* __COMMON_SINGLE_VALUE_H */     /* NOLINT(build/header_guard) */
