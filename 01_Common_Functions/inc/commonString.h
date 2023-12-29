/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\inc\commonString.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-24 00:56:41
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-04 01:07:19
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用字符串头文件
 */
#ifndef __COMMON_STRING_H       /* NOLINT(build/header_guard) */
#define __COMMON_STRING_H       /* NOLINT(build/header_guard) */

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
int swapChar(char *a, char *b);                                     /* 交换字符 */
int reverseStringSection(char *s, int leftIndex, int rightIndex);   /* 反转字符串 */

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
int printString(char *s);                                           /* 打印字符串 */
int freeString(char **s);                                           /* 释放字符串 */

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
int validateString(char testNum, char *expect, char *actual);       /* 验证字符串 */


#endif  /* __COMMON_STRING_H */     /* NOLINT(build/header_guard) */