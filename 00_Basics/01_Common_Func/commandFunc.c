/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\commandFunc.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-04 08:56:01
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-21 13:54:37
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 本文件记录C语言常用宏定义技巧及常用函数
 */

/* 头文件 */
#include <stdio.h>
#include "commonHeader.h"

/**********************************************************************************/
/*                                                                                */
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
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

/**********************************************************************************/
/*                                                                                */
/*                                  MAIN FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 主函数
 * =================================================================================
 * @param {int} argc        程序入参个数
 * @param {char} *argv[]    程序入参字符串数组
 * @return {int}            程序运行状态
 */
int main(int argc, char *argv[]) {
    printCommandInfo(argc, argv);
    return 0;
}
