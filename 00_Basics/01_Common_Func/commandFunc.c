/*
 * @File: main.c
 * @Created Date: Monday, August 28th 2023, 9:44:35 am
 * @Author: Chong Liu
 * @Brief: 本文件记录C语言常用宏定义技巧及常用函数
 * =================================================================================
 * Copyright (c) 2023 Chong Liu
 * =================================================================================
 * Last Modified: Chong Liu - Tuesday, August 29th 2023, 10:36:39 am
 */
/* 头文件 */
#include <stdio.h>

/* 获取数组长度 */
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

/* （token-pasting：##）将两个标记符号合并为一个标记 */
#define TOKEN_CONCATENATE(x, y) x ## y

/* 重命名打印函数 */
#define INFO(format, ...) printf(format "\r\n", ##__VA_ARGS__)

/* int main(int argc, char *argv[])
 *  Functionality: description...
 *  Arguments: arguments...
 *  Return: possibleReturnValues
 *  References: document/website...
 ***********************************************************************************
 *  IMPORTANT NOTICE FOR READER
 */
int main(int argc, char *argv[])
{
    INFO("Number of command-line arguments: %d", argc);

    INFO("Command-line arguments:");
    for (int i = 0; i < argc; i++)
    {
        INFO("%s", argv[i]);
    }

    return 0;
}

// $ ./program arg1 arg2 arg3
// Number of command-line arguments: 4
// ./program
// arg1
// arg2
// arg3