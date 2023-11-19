/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\03_isHappy\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-05 14:47:06
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-19 20:35:01
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 202. 快乐数：https://leetcode.cn/problems/happy-number/
 * https://programmercarl.com/0202.%E5%BF%AB%E4%B9%90%E6%95%B0.html
 * https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0202.%E5%BF%AB%E4%B9%90%E6%95%B0.md
 *
 * 编写一个算法来判断一个数 n 是不是快乐数。
 *
 *「快乐数」 定义为：
 * 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
 * 然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
 * 如果这个过程 结果为 1，那么这个数就是快乐数。
 */
/* 标准头文件 */
#include <stdio.h>
#include <stdbool.h>
/* 通用头文件 */
#include "commonHelper.h"
/* 解题方法配置文件 */
#include "methodCfg.h"
/* 本文件头文件 */
#include "isHappy.h"

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 测试 1
 * 输入：n = 19
 * 输出：true
 * =================================================================================
 * @return {void}
 */
void test_1(void) {
    /* 实际结果 */
    int n = 19;
    bool actual = isHappy(n);

    /* 预期结果 */
    bool expect = true;

    /* 比较结果 */
    validateSingleValue('1', expect, actual);
}

/**
 * @description: 测试 2
 * 输入：n = 2
 * 输出：false
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    /* 实际结果 */
    int n = 2;
    bool actual = isHappy(n);

    /* 预期结果 */
    bool expect = false;

    /* 比较结果 */
    validateSingleValue('2', expect, actual);
}

/**
 * @description: 测试 3
 * 输入：n = 1
 * 输出：true
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    /* 实际结果 */
    int n = 1;
    bool actual = isHappy(n);

    /* 预期结果 */
    bool expect = true;

    /* 比较结果 */
    validateSingleValue('3', expect, actual);
}

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
int main(int argc, char const *argv[]) {
#if FAST_SLOW_POINTER_METHOD_EN
    printf("FAST_SLOW_POINTER_METHOD_EN\r\n");
#elif HASH_TABLE_METHOD_EN
    printf("HASH_TABLE_METHOD_EN\r\n");
#endif
    test_1();
    test_2();
    test_3();
    return 0;
}