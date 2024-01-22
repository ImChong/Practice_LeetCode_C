/*
 * @FilePath     : \Practice_LeetCode_C\02_Programming_Topics\03_Hash_Table\01_isAnagram\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-05 14:47:06
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-31 20:42:27
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 242. 有效的字母异位词：https://leetcode.cn/problems/valid-anagram/
 */
/* Standard header file (标准头文件) */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
/* Common function header file (通用头文件) */
#include "commonTypeDef.h"
#include "commonSingleValue.h"
/* solution header file (题解头文件) */
#include "isAnagram.h"

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: Test 1
 * 输入：s = "anagram", t = "nagaram"
 * 输出：true
 * =================================================================================
 * @return {void}
 */
void Test1(void) {
    /* Function call (函数调用) */
    char s[] = "anagram";
    char t[] = "nagaram";
    int actual = isAnagram(s, t);

    /* Expect result (期望结果) */
    int expect = COMMON_TRUE;

    /* Validate result (验证函数调用结果) */
    Validate_SingleValue('1', expect, actual);
}

/**
 * @description: Test 2
 * 输入：s = "rat", t = "car"
 * 输出：false
 * =================================================================================
 * @return {void}
 */
void Test2(void) {
    /* Function call (函数调用) */
    char s[] = "rat";
    char t[] = "car";
    int actual = isAnagram(s, t);

    /* Expect result (期望结果) */
    int expect = COMMON_FALSE;

    /* Validate result (验证函数调用结果) */
    Validate_SingleValue('2', expect, actual);
}

/**
 * @description: 测试 3
 * 输入：s = "", t = ""
 * 输出：true
 * =================================================================================
 * @return {void}
 */
void Test3(void) {
    /* Function call (函数调用) */
    char s[] = "";
    char t[] = "";
    int actual = isAnagram(s, t);

    /* Expect result (期望结果) */
    int expect = COMMON_TRUE;

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
int main(int argc, char const *argv[]) {
    Test1();
    Test2();
    Test3();
    return 0;
}