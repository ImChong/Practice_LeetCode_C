/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\03_isHappy\src\commonFunc.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-30 23:52:25
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-18 19:01:14
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 快乐数 - 公共函数源文件
 */
/* 本文件头文件 */
#include "commonFunc.h"

/**********************************************************************************/
/*                                                                                */
/*                                 UTILITY FUNCTIONS                              */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 获取下一数字
 * getNext函数用于计算一个数字各位数字平方和。
 * =================================================================================
 * @param {int} n       当前数字
 * @return {int}        下一数字
 */
int getNext(int n) {
    int sum = 0;            /* 计算总和 */
    while (n > 0) {         /* 当数字大于0时保持循环 */
        int d = n % 10;         /* 获取个位的数值 */
        sum += d * d;           /* 总和加上个位数值的平方 */
        n /= 10;                /* 去除个位的数字 */
    }
    return sum;             /* 返回总和 */
}
