/*
 * @File: main.c
 * @Created Date: Monday, August 28th 2023, 9:44:35 am
 * @Author: Chong Liu
 * @Brief: 本文件记录C语言常用宏定义技巧及常用函数
 * =================================================================================
 * Copyright (c) 2023 Chong Liu
 * =================================================================================
 * Last Modified: Chong Liu - Tuesday, August 29th 2023, 10:46:34 am
 */
/* 头文件 */
#include <stdio.h>

/* 获取数组长度 */
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

/* （token-pasting：##）将两个标记符号合并为一个标记 */
#define TOKEN_CONCATENATE(x, y) x ## y

/* 重命名打印函数 */
#define INFO(format, ...) printf(format "\r\n", ##__VA_ARGS__)

/* printCommandInfo()
 *  Functionality: 打印命令行参数
 *  Arguments: int argc, char *argv[]
 *  Return: void
 *  References:
 ***********************************************************************************
 *  IMPORTANT NOTICE FOR READER
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

/* printCommandInfo()
 *  Functionality: 打印命令行参数
 *  Arguments: int argc, char *argv[]
 *  Return: void
 *  References:
 ***********************************************************************************
 *  IMPORTANT NOTICE FOR READER
 */
int main(int argc, char *argv[])
{
    printCommandInfo(argc, argv);
    return 0;
}

