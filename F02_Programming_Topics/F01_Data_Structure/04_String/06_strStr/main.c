/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\04_String\06_strStr\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-18 23:18:36
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-22 18:33:11
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 28. 实现 strStr()： https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/
 * https://programmercarl.com/0028.%E5%AE%9E%E7%8E%B0strStr.html
 * https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0028.%E5%AE%9E%E7%8E%B0strStr.md
 */
/* Standard header file (标准头文件) */
#include <stdio.h>
#include <stdlib.h>
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
 * @description: 找出字符串中第一个匹配项的下标
 * =================================================================================
 * @param {char} *haystack      字符串地址
 * @param {char} *needle        匹配字符串地址
 * @return {int} index          匹配项下标
 */
int strStr(char *haystack, char *needle){
    int hLen = strlen(haystack);                    /* haystack长度 */
    int nLen = strlen(needle);                      /* needle长度 */

    for (int i = 0; i + nLen <= hLen; i++) {        /* 遍历 haystack */
        int j = 0;                                      /* 初始化 needle 下标 */
        for (; j < nLen; j++) {                         /* 遍历 needle */
            if (haystack[i + j] != needle[j]) {             /* 不匹配则退出 */
                break;
            }
        }
        if (j == nLen) {                                /* 匹配则返回 haystack 下标 */
            return i;
        }
    }
    return -1;                                      /* 未匹配则返回 -1 */
}

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: Test 1
 * 输入：haystack = "sadbutsad", needle = "sad"
 * 输出：0
 * =================================================================================
 * @return {void}
 */
void Test1(void) {
    /* Function call (函数调用) */
    char *haystack = "sadbutsad";
    char *needle = "sad";
    int actual = strStr(haystack, needle);

    /* Expect result (期望结果) */
    int expect = 0;

    /* Validate result (验证函数调用结果) */
    Validate_SingleValue('1', expect, actual);
}

/**
 * @description: 测试 2
 * haystack = "leetcode", needle = "leeto"
 * 输出：-1
 * =================================================================================
 * @return {void}
 */
void Test2(void) {
    /* Function call (函数调用) */
    char *haystack = "leetcode";
    char *needle = "leeto";
    int actual = strStr(haystack, needle);

    /* Expect result (期望结果) */
    int expect = -1;

    /* Validate result (验证函数调用结果) */
    Validate_SingleValue('2', expect, actual);
}

/**
 * @description: 测试 3
 * haystack = "a", needle = "a"
 * 输出：0
 * =================================================================================
 * @return {void}
 */
void Test3(void) {
    /* Function call (函数调用) */
    char *haystack = "a";
    char *needle = "a";
    int actual = strStr(haystack, needle);

    /* Expect result (期望结果) */
    int expect = 0;

    /* Validate result (验证函数调用结果) */
    Validate_SingleValue('3', expect, actual);
}

/**
 * @description: 测试 4
 * haystack = "leetcode", needle = "code"
 * 输出：4
 * =================================================================================
 * @return {void}
 */
void Test4(void) {
    /* Function call (函数调用) */
    char *haystack = "leetcode";
    char *needle = "code";
    int actual = strStr(haystack, needle);

    /* Expect result (期望结果) */
    int expect = 4;

    /* Validate result (验证函数调用结果) */
    Validate_SingleValue('4', expect, actual);
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
    Test4();
    return 0;
}