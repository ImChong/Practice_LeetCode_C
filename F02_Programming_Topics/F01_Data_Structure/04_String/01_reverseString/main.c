/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\04_String\01_reverseString\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-21 22:14:49
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-22 18:31:05
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 344.反转字符串: https://leetcode.cn/problems/reverse-string/
 * https://programmercarl.com/0344.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2.html
 * https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0078.%E5%AD%90%E9%9B%86.md
 */
/* Standard header file (标准头文件) */
#include <stdio.h>
#include <string.h>
/* Common function header file (通用头文件) */
#include "commonString.h"
#include "commonArray.h"

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 反转字符串
 * =================================================================================
 * @param {char} *s         字符串地址
 * @param {int} sSize       字符串长度
 * @return {void}
 */
void reverseString(char *s, int sSize) {
    int left = 0;                           /* 左指针 */
    int right = sSize - 1;                  /* 右指针 */
    while (left < right) {                  /* 左右指针交换 */
        Char_Swap(s + left, s + right);          /* 交换字符 */
        left++;                                 /* 左指针右移 */
        right--;                                /* 右指针左移 */
    }
}

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 测试 1
 * 输入：s = ["h","e","l","l","o"]
 * 输出：["o","l","l","e","h"]
 * =================================================================================
 * @return {void}
 */
void Test1(void) {
    /* Function call (函数调用) */
    // char *s = "hello";                                  /* strlen: 5, ARR_SIZE: 8, 字符串不可修改 */
    char s[] = "hello";                                 /* strlen: 5, ARR_SIZE: 6, 字符串可修改 */
    // char s[6] = {'h', 'e', 'l', 'l', 'o', '\0'};        /* strlen: 5, ARR_SIZE: 6, 字符串可修改 */
    int sSize = strlen(s);
    // printf("strlen: %d, ARR_SIZE: %d\n", strlen(s), ARR_SIZE(s));
    reverseString(s, sSize);

    /* Expect result (期望结果) */
    char *expect = "olleh";

    /* Validate result (验证函数调用结果) */
    Validate_String('1', expect, s);
}

/**
 * @description: 测试 2
 * 输入: s = ["H","a","n","n","a","h"]
 * 输出：["h","a","n","n","a","H"]
 * =================================================================================
 * @return {void}
 */
void Test2(void) {
    /* Function call (函数调用) */
    char s[] = "Hannah";
    int sSize = strlen(s);
    reverseString(s, sSize);

    /* Expect result (期望结果) */
    char *expect = "hannaH";

    /* Validate result (验证函数调用结果) */
    Validate_String('2', expect, s);
}

/**
 * @description: 测试 3
 * 输入：s = ["1"]
 * 输出：["1"]
 * =================================================================================
 * @return {void}
 */
void Test3(void) {
    /* Function call (函数调用) */
    char s[] = "1";
    int sSize = strlen(s);
    reverseString(s, sSize);

    /* Expect result (期望结果) */
    char *expect = "1";

    /* Validate result (验证函数调用结果) */
    Validate_String('3', expect, s);
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