/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\04_String\01_reverseString\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-21 22:14:49
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-24 10:21:48
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 344.反转字符串: https://leetcode.cn/problems/reverse-string/
 * https://programmercarl.com/0344.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2.html
 * https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0078.%E5%AD%90%E9%9B%86.md
 */
#include <stdio.h>
#include <string.h>
#include "commonString.h"

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 交换字符
 * =================================================================================
 * @param {char} *a
 * @param {char} *b
 * @return {void}
 */
void swapChar(char *a, char *b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * @description: 反转字符串
 * =================================================================================
 * @param {char} *s
 * @param {int} sSize
 * @return {void}
 */
void reverseString(char *s, int sSize){

    return;
}

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 测试 1
 * 输入：s = "hello"
 * 输出："olleh"
 * =================================================================================
 * @return {void}
 */
void test_1(void) {
    /* 实际结果 */
    char *s = "hello";
    int sSize = strlen(s);
    reverseString(s, sSize);

    /* 预期结果 */
    char *expect = "olleh";

    /* 比较结果 */
    validateString('1', expect, s);
}

/**
 * @description: 测试 2
 * 输入：s = "Hannah"
 * 输出："hannaH"
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    /* 实际结果 */
    char *s = "Hannah";
    int sSize = strlen(s);
    reverseString(s, sSize);

    /* 预期结果 */
    char *expect = "hannaH";

    /* 比较结果 */
    validateString('2', expect, s);
}

/**
 * @description: 测试 3
 * 输入：s = "1"
 * 输出："1"
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    /* 实际结果 */
    char *s = "1";
    int sSize = strlen(s);
    reverseString(s, sSize);

    /* 预期结果 */
    char *expect = "1";

    /* 比较结果 */
    validateString('3', expect, s);
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
int main(int argc, const char *argv[]) {
    test_1();
    test_2();
    test_3();
    return 0;
}