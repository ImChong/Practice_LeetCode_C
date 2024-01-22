/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\04_String\07_repeatedSubstringPattern\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-18 23:18:36
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-22 18:33:28
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 459. 重复的子字符串： https://leetcode.cn/problems/repeated-substring-pattern/
 * https://programmercarl.com/0459.%E9%87%8D%E5%A4%8D%E7%9A%84%E5%AD%90%E5%AD%97%E7%AC%A6%E4%B8%B2.html
 * https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0459.%E9%87%8D%E5%A4%8D%E7%9A%84%E5%AD%90%E5%AD%97%E7%AC%A6%E4%B8%B2.md
 */
/* Standard header file (标准头文件) */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
/* Common function header file (通用头文件) */
#include "commonSingleValue.h"

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 重复的子字符串
 * =================================================================================
 * @param {char} *s     字符串地址
 * @return {bool}       是否为重复的子字符串
 */
bool repeatedSubstringPattern(char *s){
    int sLen = strlen(s);                       /* 字符串长度 */
    for (int i = 1; i * 2 <= sLen; i++) {       /* 遍历字符串长度的一半 */
        if (sLen % i == 0) {                        /* 字符串长度为 i 的倍数 */
            bool match = true;                          /* 是否匹配 */
            for (int j = i; j < sLen; j++) {            /* 遍历字符串 */
                if (s[j] != s[j - i]) {                     /* 字符串不匹配 */
                    match = false;                              /* 不匹配 */
                    break;                                      /* 跳出循环 */
                }
            }
            if (match) {                                /* 匹配 */
                return true;                                /* 返回 true */
            }
        }
    }

    return 0;
}

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: Test 1
 * 输入: s = "abab"
 * 输出: true
 * =================================================================================
 * @return {void}
 */
void Test1(void) {
    /* Function call (函数调用) */
    char *s = "abab";
    bool actual = repeatedSubstringPattern(s);

    /* Expect result (期望结果) */
    bool expect = true;

    /* Validate result (验证函数调用结果) */
    Validate_SingleValue('1', expect, actual);
}

/**
 * @description: Test 2
 * 输入: s = "aba"
 * 输出: false
 * =================================================================================
 * @return {void}
 */
void Test2(void) {
    /* Function call (函数调用) */
    char *s = "aba";
    bool actual = repeatedSubstringPattern(s);

    /* Expect result (期望结果) */
    bool expect = false;

    /* Validate result (验证函数调用结果) */
    Validate_SingleValue('2', expect, actual);
}

/**
 * @description: 测试 3
 * 输入: s = "abcabcabcabc"
 * 输出: true
 * =================================================================================
 * @return {void}
 */
void Test3(void) {
    /* Function call (函数调用) */
    char *s = "abcabcabcabc";
    bool actual = repeatedSubstringPattern(s);

    /* Expect result (期望结果) */
    bool expect = true;

    /* Validate result (验证函数调用结果) */
    Validate_SingleValue('3', expect, actual);
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