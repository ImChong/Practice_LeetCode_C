/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\inc\commonHelper.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 13:42:27
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-22 12:38:13
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用辅助函数头文件
 */
#ifndef __COMMON_HEADER_H
#define __COMMON_HEADER_H

#include <stdio.h>

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
/* （token-pasting：##）将两个标记符号合并为一个标记 */
#define TOKEN_CONCATENATE(x, y) x ## y

/* 重命名打印函数: 打印时可省略输入\r\n */
#define INFO(format, ...) printf(format "\r\n", ##__VA_ARGS__)

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
void validateAnswer(char testNum, int expect, int actual);


#endif  /* __COMMON_HEADER_H */