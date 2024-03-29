/*
 * @FilePath     : \Practice_LeetCode_C\F01_Common_Functions\src\common_cmd.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-04 08:56:01
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-26 10:30:49
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用命令行指令源文件
 */
/* Common function configuration file (通用函数配置文件) */
#include "compile_cfg.h"    /* NOLINT */
#if COMMON_CMD_EN /* whether compile this file, the definition of this macro can be found in compileCfg.h */
/* Header file (本文件头文件) */
#include "F01_Common_Functions/inc/common_cmd.h"
/* Common function header file (通用头文件) */
#include "F01_Common_Functions/inc/common_def/common_print_def.h"
#include "F01_Common_Functions/inc/common_def/common_type_def.h"

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
int Cmd_PrintInput(int argc, const char *argv[]) {
    INFO("Number of command-line arguments: %d", argc);
    INFO("Command-line arguments:");
    for (int i = 0; i < argc; i++) {
        INFO("%d -> %s", i, argv[i]);
    }
    return COMMON_OK;
}


#endif      /* COMMON_CMD_EN */
