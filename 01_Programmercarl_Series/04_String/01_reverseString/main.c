/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\04_String\01_reverseString\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-21 22:14:49
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-18 09:21:13
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 344.反转字符串: https://leetcode.cn/problems/reverse-string/
 * https://programmercarl.com/0344.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2.html
 * https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0078.%E5%AD%90%E9%9B%86.md
 */
#include <stdio.h>
#include <string.h>

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/* TODO：目标函数 */
/* ============================================================================== */
/* ============================================================================== */
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
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 验证答案
 * =================================================================================
 * @param {char} testNum    测试编号
 * @param {int} expect      预期
 * @param {int} actual      实际
 * @return {void}
 */
void validateAnswer(char testNum, int expect, int actual) {
    if (expect == actual) {
        printf("✅ Test %c Passed\n", testNum);
    } else {
        printf("❌ Test %c Failed\n", testNum);
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
void test_1(void) {
    /* 实际结果 */
    char *s = "hello";
    int sSize = strlen(s);
    char *actual = reverseString(s, sSize);

    /* 预期结果 */
    char *expect = "olleh";

    /* 比较结果 */
    validateAnswer("1", expect, actual);
}

/**
 * @description: 测试 2
 * 输入：s = ["H","a","n","n","a","h"]
 * 输出：["h","a","n","n","a","H"]
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    /* 实际结果 */
    char *s = "Hannah";
    int sSize = strlen(s);
    char *actual = reverseString(s, sSize);

    /* 预期结果 */
    char *expect = "hannaH";

    /* 比较结果 */
    validateAnswer("2", expect, actual);
}

/**
 * @description: 测试 3
 * 输入：s = ["1"]
 * 输出：["1"]
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    /* 实际结果 */
    char *s = "1";
    int sSize = strlen(s);
    char *actual = reverseString(s, sSize);

    /* 预期结果 */
    char *expect = "1";

    /* 比较结果 */
    validateAnswer("3", expect, actual);
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