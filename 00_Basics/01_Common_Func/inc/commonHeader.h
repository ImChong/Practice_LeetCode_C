/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\inc\commonHeader.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 13:42:27
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-22 12:14:36
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用头文件
 */
#ifndef __COMMON_HEADER_H
#define __COMMON_HEADER_H

#include <stdio.h>

/**********************************************************************************/
/*                                                                                */
/*                                MACRO CONSTANTS                                 */
/*                                                                                */
/**********************************************************************************/
/* 程序状态宏 */
#define COMMON_ERR     (-1)
#define COMMON_OK      0

/* 程序判断宏 */
#define COMMON_TRUE    1
#define COMMON_FALSE   0

/* 程序调试宏 */
#define STATIC          static
#define STATIC_FUNC     static

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
/* （token-pasting：##）将两个标记符号合并为一个标记 */
#define TOKEN_CONCATENATE(x, y) x ## y

/* 重命名打印函数: 打印时可省略输入\r\n */
#define INFO(format, ...) printf(format "\r\n", ##__VA_ARGS__)

/* 声明了一个变量或函数,但不确定后面是否会使用它时,可以加上这个宏 */
#define MAYBE_UNUSED attribute((unused))

/**********************************************************************************/
/*                                                                                */
/*                                MACRO FUNCTIONS                                 */
/*                                                                                */
/**********************************************************************************/
/* 返回错误码 */
#define RETURN_ERR_IF(condition)        do { \
                                            if (condition) { \
                                                return UNIFORM_ERR; \
                                            } \
                                        } while (0)

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
void validateAnswer(char testNum, int expect, int actual);


#endif  /* __COMMON_HEADER_H */