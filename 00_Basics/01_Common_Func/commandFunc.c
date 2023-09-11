/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\commandFunc.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-04 08:56:01
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-09-11 20:00:49
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 本文件记录C语言常用宏定义技巧及常用函数
 */

/* 头文件 */
#include <stdio.h>

/* 获取数组长度 */
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

/* （token-pasting：##）将两个标记符号合并为一个标记 */
#define TOKEN_CONCATENATE(x, y) x ## y

/* 重命名打印函数: 打印时可省略输入\r\n */
#define INFO(format, ...) printf(format "\r\n", ##__VA_ARGS__)

/* 声明了一个变量或函数,但不确定后面是否会使用它时,可以加上这个宏 */
#define MAYBE_UNUSED attribute((unused))

/**
 * @description: 打印命令行参数
 * =================================================================================
 * @param {int} argc        程序入参个数
 * @param {char} *argv[]    程序入参字符串数组
 * @return {void}
 */
void printCommandInfo(int argc, char *argv[]) {
    INFO("Number of command-line arguments: %d", argc);
    INFO("Command-line arguments:");
    for (int i = 0; i < argc; i++)
    {
        INFO("%s", argv[i]);
    }
}

/* 命令行调用程序 */
// .\commandFunc.exe arg1 arg2 arg3

/* 打印输出 */
// Command-line arguments:
// ...\Practice_LeetCode_C\00_Basics\01_Common_Func\commandFunc.exe
// arg1
// arg2
// arg3

/**
 * @description: 主函数
 * =================================================================================
 * @param {int} argc        程序入参个数
 * @param {char} *argv[]    程序入参字符串数组
 * @return {int}            程序运行状态
 */
int main(int argc, char *argv[])
{
    printCommandInfo(argc, argv);
    return 0;
}
