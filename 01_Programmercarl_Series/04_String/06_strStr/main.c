/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\04_String\06_strStr\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-18 23:18:36
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-29 10:30:45
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 28. 实现 strStr()： https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/
 * https://programmercarl.com/0028.%E5%AE%9E%E7%8E%B0strStr.html
 * https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0028.%E5%AE%9E%E7%8E%B0strStr.md
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commonHelper.h"
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
    int hLen = strlen(haystack);        /* haystack长度 */
    int nLen = strlen(needle);          /* needle长度 */

    for (int i = 0; i + nLen <= hLen; i++) {    /* 遍历字符串 */
        int j = 0;                              /* 匹配指针 */
        for (; j < nLen; j++) {                 /* 遍历匹配字符串 */
            if (haystack[i + j] != needle[j]) {     /* 当前字符不匹配 */
                break;                                  /* 跳出循环 */
            }
        }
        if (j == nLen) {                        /* 匹配指针指向匹配字符串的最后一位 */
            return i;                               /* 返回匹配项下标 */
        }
    }
    return -1;
}

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 测试 1
 * 输入：haystack = "sadbutsad", needle = "sad"
 * 输出：0
 * =================================================================================
 * @return {void}
 */
void test_1(void) {
    /* 实际结果 */
    char *haystack = "sadbutsad";
    char *needle = "sad";
    int actual = strStr(haystack, needle);

    /* 预期结果 */
    int expect = 0;

    /* 比较结果 */
    validateSingleValue('1', expect, actual);
}

/**
 * @description: 测试 2
 * haystack = "leetcode", needle = "leeto"
 * 输出：-1
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    /* 实际结果 */
    char *haystack = "leetcode";
    char *needle = "leeto";
    int actual = strStr(haystack, needle);

    /* 预期结果 */
    int expect = -1;

    /* 比较结果 */
    validateSingleValue('2', expect, actual);
}

/**
 * @description: 测试 3
 * haystack = "a", needle = "a"
 * 输出：0
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    /* 实际结果 */
    char *haystack = "a";
    char *needle = "a";
    int actual = strStr(haystack, needle);

    /* 预期结果 */
    int expect = 0;

    /* 比较结果 */
    validateSingleValue('3', expect, actual);
}

/**
 * @description: 测试 4
 * haystack = "leetcode", needle = "code"
 * 输出：4
 * =================================================================================
 * @return {void}
 */
void test_4(void) {
    /* 实际结果 */
    char *haystack = "leetcode";
    char *needle = "code";
    int actual = strStr(haystack, needle);

    /* 预期结果 */
    int expect = 4;

    /* 比较结果 */
    validateSingleValue('4', expect, actual);
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
    test_4();
    return 0;
}