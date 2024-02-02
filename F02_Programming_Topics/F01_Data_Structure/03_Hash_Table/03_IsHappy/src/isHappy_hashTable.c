/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\03_isHappy\src\isHappy_hash_table.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-30 23:45:15
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-18 19:20:55
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 快乐数 - 哈希表法源文件
 */
/* solution method configuration file (解题方法配置文件) */
#include "methodCfg.h"
#if HASH_TABLE_METHOD_EN
/* Standard header file (标准头文件) */
#include <stdio.h>
#include <stdbool.h>
/* Common function header file (通用头文件) */
#include "commonFunc.h"
/* solution header file (题解头文件) */
#include "isHappy.h"

/**********************************************************************************/
/*                                                                                */
/*                                MACRO CONSTANTS                                 */
/*                                                                                */
/**********************************************************************************/
#define HASH_SIZE 163

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 快乐数
 * isHappy函数用于判断一个数字是否为快乐数。
 *
 * 快乐数是指对于一个正整数，如果对其各个位上的数字分别平方，然后再将得到的数相加，最终结果为1，则该数为快乐数。
 * 这段代码使用了一个哈希表算法来判断一个数字是否为快乐数。
 * =================================================================================
 * @param {int} n       当前数字
 * @return {bool}       是否为快乐数
 */
bool isHappy(int n) {
    int visited[HASH_SIZE] = {0};               /* 初始化哈希表 */
    int sum = getNext(n);                       /* 初始化总和，获取下一数字的下一数字 */
    int next_n = sum;                           /* 初始化下一数字 */

    while (next_n != 1) {                       /* 当下一数字不为 1 时，保持循环 */
        sum = getNext(next_n);                      /* 计算总和 */
        if (visited[sum]) {                         /* 如果总和已经在哈希表中存在，则返回 false */
            return false;
        }
        visited[sum] = 1;                           /* 将总和加入哈希表 */
        next_n = sum;                               /* 更新下一数字 */
    };

    return true;                                /* 当开始循环且下一数字为 1 时，返回 true */
}

#endif  /* HASH_TABLE_METHOD_EN */