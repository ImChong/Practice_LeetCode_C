/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 14:03:07
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-21 14:43:48
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 主函数
 */
#include "commonHeader.h"       /* 00_Basics\02_Common_Header\commonHeader.h */
#include "printCommand.h"
#include "ringBuffer.h"

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
    INFO("== printCommandInfo =============================");
    printCommandInfo(argc, argv);

    INFO("== Test_RingBuffer =============================");
    Test_RingBuffer();
    return 0;
}