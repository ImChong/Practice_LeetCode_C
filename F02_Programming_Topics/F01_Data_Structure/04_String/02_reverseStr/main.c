/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\04_String\02_reverseStr\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-21 22:14:49
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-22 18:31:32
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 541. 反转字符串 II： https://leetcode.cn/problems/reverse-string-ii/
 * https://programmercarl.com/0541.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2II.html
 * https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0541.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2II.md
 */
/* Standard header file (标准头文件) */
#include <stdio.h>
#include <string.h>
/* Common function header file (通用头文件) */
#include "commonSingleValue.h"
#include "commonString.h"

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 反转字符串 II
 * =================================================================================
 * @param {char} *s         字符串地址
 * @param {int} k           反转长度
 * @return {char} *ans      反转后的字符串
 */
char *reverseStr(char *s, int k){
    int sLen = strlen(s);                                               /* 字符串长度 */
    for (int i = 0; i < sLen; i += 2 * k) {                             /* 每隔 2k 个字符反转 k 个字符 */
        String_Reverse(s, i, i + k - 1);                              /* 反转字符串 */
    }
    return s;                                                           /* 返回反转后的字符串 */
}

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 测试 1
 * 输入：s = "abcdefg", k = 2
 * 输出："bacdfeg"
 * =================================================================================
 * @return {void}
 */
void Test1(void) {
    /* Function call (函数调用) */
    char s[] = "abcdefg";
    int k = 2;
    char *actual = reverseStr(s, k);

    /* Expect result (期望结果) */
    char *expect = "bacdfeg";

    /* Validate result (验证函数调用结果) */
    Validate_String('1', expect, actual);
}

/**
 * @description: 测试 2
 * 输入：s = "abcd", k = 2
 * 输出："bacd"
 * =================================================================================
 * @return {void}
 */
void Test2(void) {
    /* Function call (函数调用) */
    char s[] = "abcd";
    int k = 2;
    char *actual = reverseStr(s, k);

    /* Expect result (期望结果) */
    char *expect = "bacd";

    /* Validate result (验证函数调用结果) */
    Validate_String('2', expect, actual);
}

/**
 * @description: 测试 3
 * 输入：s = "abcdefg", k = 4
 * 输出："dcbaefg"
 * =================================================================================
 * @return {void}
 */
void Test3(void) {
    /* Function call (函数调用) */
    char s[] = "abcdefg";
    int k = 4;
    char *actual = reverseStr(s, k);

    /* Expect result (期望结果) */
    char *expect = "dcbaefg";

    /* Validate result (验证函数调用结果) */
    Validate_String('3', expect, actual);
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
    Test1();
    Test2();
    Test3();
    return 0;
}