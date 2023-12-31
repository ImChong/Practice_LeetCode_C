/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\src\commonCmd.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-04 08:56:01
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-13 01:04:41
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用命令行指令源文件
 */
/* common function configuration file (通用函数配置文件) */
#include "compileCfg.h"
#if COMMON_CMD_EN         /* 在每一道题 cfg 文件夹下的 compileCfg.h 开启编译宏定义 */
/* common function header file (通用头文件) */
#include "commonTypeDef.h"
#include "commonPrintDef.h"
#include "commonCmd.h"

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
 * @return {int}            运行结果：0 - 成功；其他 - 失败
 */
int CMD_PrintInput(int argc, const char *argv[]) {
    INFO("Number of command-line arguments: %d", argc);
    INFO("Command-line arguments:");
    for (int i = 0; i < argc; i++) {
        INFO("%d -> %s", i, argv[i]);
    }
    return COMMON_OK;
}


#endif      /* COMMON_CMD_EN */
