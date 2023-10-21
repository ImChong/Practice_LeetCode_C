/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\inc\commonHeader.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 13:42:27
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-21 17:44:44
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 本文件记录C语言常用宏定义及宏函数
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
#define UNIFORM_ERR     (-1)
#define UNIFORM_OK      0

/* 程序判断宏 */
#define UNIFORM_TRUE    1
#define UNIFORM_FALSE   0

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


#endif  /* __COMMON_HEADER_H */