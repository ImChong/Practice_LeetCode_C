/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\inc\commonSingleValue.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 13:42:27
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-23 11:15:56
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用单值函数头文件
 */
#ifndef __COMMON_HEADER_H
#define __COMMON_HEADER_H

/**********************************************************************************/
/*                                                                                */
/*                                MACRO FUNCTIONS                                 */
/*                                                                                */
/**********************************************************************************/
#define MAX(a, b)   ((a) > (b) ? (a) : (b))     /* 取最大值 */
#define MIN(a, b)   ((a) < (b) ? (a) : (b))     /* 取最小值 */

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
void validateSingleValue(char testNum, int expect, int actual);     /* 验证单个值 */


#endif  /* __COMMON_HEADER_H */