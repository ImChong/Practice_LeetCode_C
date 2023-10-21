/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\commandHeader.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 13:42:27
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-21 13:43:59
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 本文件记录C语言常用宏定义及宏函数
 */

/**********************************************************************************/
/*                                                                                */
/*                                MACRO FUNCTIONS                                 */
/*                                                                                */
/**********************************************************************************/
/* 获取数组长度 */
#define ARR_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

/* （token-pasting：##）将两个标记符号合并为一个标记 */
#define TOKEN_CONCATENATE(x, y) x ## y

/* 重命名打印函数: 打印时可省略输入\r\n */
#define INFO(format, ...) printf(format "\r\n", ##__VA_ARGS__)

/* 声明了一个变量或函数,但不确定后面是否会使用它时,可以加上这个宏 */
#define MAYBE_UNUSED attribute((unused))