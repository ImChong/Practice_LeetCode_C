/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\inc\commonSingleValue.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 13:42:27
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-02 17:58:15
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用单值函数头文件
 */
#ifndef COMMON_SINGLE_VALUE_H   /* NOLINT(build/header_guard) */
#define COMMON_SINGLE_VALUE_H   /* NOLINT(build/header_guard) */

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
void validateSingleValue(char testNum, int expect, int actual);     /* 验证单个值 */


#endif  /* COMMON_SINGLE_VALUE_H */     /* NOLINT(build/header_guard) */
