/*
 * @FilePath     : \Practice_LeetCode_C\F01_Common_Functions\inc\commonDef\common_print_def.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-22 12:55:48
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-24 00:07:16
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : Common print definition header file
 */
#ifndef F01_COMMON_FUNCTIONS_INC_COMMON_DEF_COMMON_PRINT_DEF_H_
#define F01_COMMON_FUNCTIONS_INC_COMMON_DEF_COMMON_PRINT_DEF_H_

/* Standard header file (标准头文件) */
#include <stdio.h>

/**********************************************************************************/
/*                                                                                */
/*                                MACRO FUNCTIONS                                 */
/*                                                                                */
/**********************************************************************************/
/* （token-pasting：##）concatenate two tokens (将两个标记连接起来) */
#define TOKEN_CONCATENATE(x, y) x##y

/* Rename printf function to ignore the \r\n at the end of the string (重命名printf函数，忽略字符串末尾的\r\n) */
#define INFO(format, ...) printf(format "\r\n", ##__VA_ARGS__)

#endif /* F01_COMMON_FUNCTIONS_INC_COMMON_DEF_COMMON_PRINT_DEF_H_ */
