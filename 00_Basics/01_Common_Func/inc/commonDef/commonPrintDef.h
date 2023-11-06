/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\inc\commonPrintDef.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-22 12:55:48
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-22 12:56:30
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用打印定义头文件
 */
#ifndef __COMMON_PRINT_DEF_H
#define __COMMON_PRINT_DEF_H

/* 标准头文件 */
#include <stdio.h>

/**********************************************************************************/
/*                                                                                */
/*                                MACRO FUNCTIONS                                 */
/*                                                                                */
/**********************************************************************************/
/* （token-pasting：##）将两个标记符号合并为一个标记 */
#define TOKEN_CONCATENATE(x, y) x ## y

/* 重命名打印函数: 打印时可省略输入\r\n */
#define INFO(format, ...) printf(format "\r\n", ##__VA_ARGS__)

#endif  /* __COMMON_PRINT_DEF_H */