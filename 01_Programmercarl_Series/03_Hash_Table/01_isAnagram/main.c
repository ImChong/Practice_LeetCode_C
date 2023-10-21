/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\01_isAnagram\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-05 14:47:06
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-21 08:25:32
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 242. 有效的字母异位词：https://leetcode.cn/problems/valid-anagram/
 * https://programmercarl.com/0242.%E6%9C%89%E6%95%88%E7%9A%84%E5%AD%97%E6%AF%8D%E5%BC%82%E4%BD%8D%E8%AF%8D.html
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/* TODO: 目标函数 */
/* ============================================================================== */
/* ============================================================================== */
/**
 * @description: 有效的字母异位词
 * =================================================================================
 * @param {char} *s         s字符串
 * @param {char} *t         t字符串
 * @return {bool} status    返回状态
 */
bool isAnagram(char *s, char *t) {
    int sLen = strlen(s);               /* 获得s的长度 */
    int tLen = strlen(t);               /* 获得t的长度 */
    if (sLen != tLen) {                 /* 如果s和t的长度不相等则返回false */
        return false;
    }

    int count[26] = {0};                /* 初始化计数列表 */
    for (int i = 0; i < sLen; i++) {    /* 遍历字符串 */
        count[s[i] - 'a']++;                /* 给s对应字符的值 + 1 */
        count[t[i] - 'a']--;                /* 给t对应字符的值 - 1 */
    }
    for (int i = 0; i < 26; i++) {      /* 遍历计数列表 */
        if (count[i] != 0) {                /* 如果计数不为0 */
            return false;                       /* 返回false */
        }
    }
    return true;                        /* 计数都为0则返回true */
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
    test_1();
    test_2();
    test_3();
    return 0;
}