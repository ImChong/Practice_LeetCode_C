/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\01_isAnagram\testFunc.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 09:25:37
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-21 10:01:06
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 测试函数
 */
#include "solutionFunc.h"
#include "testFunc.h"

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
 * 输入：s = "anagram", t = "nagaram"
 * 输出：true
 * =================================================================================
 * @return {void}
 */
void test_1(void) {
    /* 实际结果 */
    char s[] = "anagram";
    char t[] = "nagaram";
    bool actual = isAnagram(s, t);

    /* 预期结果 */
    bool expect = true;

    /* 比较结果 */

    /* Test case 1 */
    validateAnswer('1', expect, actual);
}

/**
 * @description: 测试 2
 * 输入：s = "rat", t = "car"
 * 输出：false
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    /* 实际结果 */
    char s[] = "rat";
    char t[] = "car";
    bool actual = isAnagram(s, t);

    /* 预期结果 */
    bool expect = false;

    /* 比较结果 */
    validateAnswer('2', expect, actual);
}

/**
 * @description: 测试 3
 * 输入：s = "", t = ""
 * 输出：true
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    /* 实际结果 */
    char s[] = "";
    char t[] = "";
    bool actual = isAnagram(s, t);

    /* 预期结果 */
    bool expect = true;

    /* 比较结果 */
    validateAnswer('3', expect, actual);
}