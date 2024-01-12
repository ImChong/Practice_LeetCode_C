/*
 * @FilePath     : \Practice_LeetCode_C\01_Common_Functions\inc\commonDef\commonPrintDef.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-22 12:55:48
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-08 21:23:08
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : Common print definition header file
 */
#ifndef F01_COMMON_FUNCTIONS_INC_COMMONDEF_COMMONPRINTDEF_H_
#define F01_COMMON_FUNCTIONS_INC_COMMONDEF_COMMONPRINTDEF_H_

/* standard header file (标准头文件) */
#include <stdio.h>

/**********************************************************************************/
/*                                                                                */
/*                                MACRO FUNCTIONS                                 */
/*                                                                                */
/**********************************************************************************/
/* （token-pasting：##）将两个标记符号合并为一个标记 */
#define TOKEN_CONCATENATE(x, y) x##y

/* 重命名打印函数: 打印时可省略输入\r\n */
#define INFO(format, ...) printf(format "\r\n", ##__VA_ARGS__)

#endif /* F01_COMMON_FUNCTIONS_INC_COMMONDEF_COMMONPRINTDEF_H_ */
