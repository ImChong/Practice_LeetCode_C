/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\src\commonCmd.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-04 08:56:01
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-27 02:51:55
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用命令行指令源文件
 */
#include "commonPrintDef.h"     /* 00_Basics\01_Common_Func\inc\commonDef\commonPrintDef.h */
#include "commonHelper.h"       /* 00_Basics\01_Common_Func\inc\commonHelper.h */
#include "commonCmd.h"          /* 00_Basics\01_Common_Func\inc\commonCmd.h */

/**********************************************************************************/
/*                                                                                */
/*                                 UTILITY FUNCTIONS                              */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 打印命令行参数
 * 命令行调用程序
 *      .\main.exe arg1 arg2 arg3
 *
 * 打印输出
 *      Number of command-line arguments: 4
 *      Command-line arguments:
 *      0 -> E:\WS_Programming\Practice_LeetCode_C\00_Basics\01_Common_Func\main.exe
 *      1 -> arg1
 *      2 -> arg2
 *      3 -> arg3
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
        INFO("%d -> %s", i, argv[i]);
    }
}
