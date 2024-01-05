/*
 * @FilePath     : \Practice_LeetCode_C\01_Common_Functions\inc\commonString.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-24 00:56:41
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-06 00:58:05
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
int Char_Swap(char *a, char *b);                                     /* 交换字符 */
int String_ReverseSection(char *s, int leftIndex, int rightIndex);   /* 反转字符串 */

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
int String_Print(char *s);                                           /* 打印字符串 */
int String_Free(char **s);                                           /* 释放字符串 */

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
int validateString(char testNum, char *expect, char *actual);       /* 验证字符串 */


#endif  /* __COMMON_STRING_H */     /* NOLINT(build/header_guard) */
