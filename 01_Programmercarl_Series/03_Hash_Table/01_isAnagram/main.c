/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\01_isAnagram\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-05 14:47:06
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-22 13:24:27
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 242. 有效的字母异位词：https://leetcode.cn/problems/valid-anagram/
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "commonHelper.h"           /* 00_Basics\01_Common_Func\inc\commonHelper.h */

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 有效的字母异位词
 * 这段代码是一个 C 语言函数，名为 isAnagram，它接受两个参数：两个指向字符的指针 s 和 t，分别表示两个字符串。
 *
 * 函数的作用是判断这两个字符串是否为字母异位词，即这两个字符串中的字母出现次数是否完全相同。
 *
 * 函数首先获得两个字符串的长度，如果它们的长度不相等，则返回 false。
 * 接着，函数初始化一个长度为 26 的整型数组 count，用于记录每个字母出现的次数。
 * 然后，函数遍历两个字符串，对于每个字符，将其在 count 数组中对应的位置的值加 1（对于 s 字符串）或减 1（对于 t 字符串）。
 * 最后，函数遍历 count 数组，如果有任何一个位置的值不为 0，则说明两个字符串不是字母异位词，返回 false。
 * 如果 count 数组中所有位置的值都为 0，则说明两个字符串是字母异位词，返回 true。
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