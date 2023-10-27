/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\04_String\07_repeatedSubstringPattern\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-18 23:18:36
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-27 23:48:23
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 459. 重复的子字符串： https://leetcode.cn/problems/repeated-substring-pattern/
 * https://programmercarl.com/0459.%E9%87%8D%E5%A4%8D%E7%9A%84%E5%AD%90%E5%AD%97%E7%AC%A6%E4%B8%B2.html
 * https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0459.%E9%87%8D%E5%A4%8D%E7%9A%84%E5%AD%90%E5%AD%97%E7%AC%A6%E4%B8%B2.md
 */
#include <stdio.h>
#include <stdbool.h>
#include "commonHelper.h"

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

    /* TODO */

    return 0;
}

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 测试 1
 * 输入: s = "abab"
 * 输出: true
 * =================================================================================
 * @return {void}
 */
void test_1(void) {
    /* 实际结果 */
    char *s = "abab";
    bool actual = repeatedSubstringPattern(s);

    /* 预期结果 */
    bool expect = true;

    /* 比较结果 */
    validateSingleValue('1', expect, actual);
}

/**
 * @description: 测试 2
 * 输入: s = "aba"
 * 输出: false
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    /* 实际结果 */
    char *s = "aba";
    bool actual = repeatedSubstringPattern(s);

    /* 预期结果 */
    bool expect = false;

    /* 比较结果 */
    validateSingleValue('2', expect, actual);
}

/**
 * @description: 测试 3
 * 输入: s = "abcabcabcabc"
 * 输出: true
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    /* 实际结果 */

    /* 预期结果 */

    /* 比较结果 */

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