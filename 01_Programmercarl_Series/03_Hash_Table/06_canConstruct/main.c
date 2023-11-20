/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\06_canConstruct\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-20 23:15:12
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 383. 赎金信：https://leetcode.cn/problems/ransom-note/
 * https://programmercarl.com/0383.%E8%B5%8E%E9%87%91%E4%BF%A1.html
 * https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0383.%E8%B5%8E%E9%87%91%E4%BF%A1.md
 *
 * 给两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
 *
 */
/* 标准头文件 */
#include <stdio.h>
#include <stdbool.h>
/* 常用头文件 */
#include "commonHelper.h"

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 赎金信
 * 该函数接受两个参数 ransomNote 和 magazine，分别表示勒索信和杂志。
 * 函数的返回值为布尔类型，表示勒索信是否可以用杂志中的字符构造出来。
 *
 * 函数的实现思路是，首先遍历杂志中的字符，统计每个字符出现的次数，
 * 然后遍历勒索信中的字符，每遇到一个字符就将其在计数器中的数量减一，
 * 如果减一后数量小于零，则说明杂志中没有足够的该字符，无法构造出勒索信，返回 false。
 * 如果遍历完勒索信中的所有字符后都没有返回 false，则说明可以构造出勒索信，返回 true。
 * =================================================================================
 * @param {char} *ransomNote        勒索信
 * @param {char} *magazine          杂志
 * @return {bool}                   是否可以构造
 */
bool canConstruct(char *ransomNote, char *magazine) {
    int counter[26] = {0};                              /* 计数器 */

    for (int i = 0; magazine[i] != '\0'; i++) {         /* 统计杂志中的字符出现的次数 */
        counter[magazine[i] - 'a']++;                       /* 以字符的 ASCII 码作为数组下标，每遇到一个字符就将其在计数器中的数量 + 1 */
    }

    for (int i = 0; ransomNote[i] != '\0'; i++) {       /* 遍历勒索信中的字符 */
        counter[ransomNote[i] - 'a']--;                     /* 每遇到一个字符就将其在计数器中的数量 - 1 */

        if (counter[ransomNote[i] - 'a'] < 0) {             /* 如果减一后数量小于零 */
            return false;                                       /* 则说明杂志中没有足够的该字符，无法构造出勒索信，返回 false */
        }
    }
    return true;                                        /* 如果遍历完勒索信中的所有字符后都没有返回 false，则说明可以构造出勒索信，返回 true */
}

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 测试 1
 * 输入：ransomNote = "a", magazine = "b"
 * 输出：false
 * =================================================================================
 * @return {void}
 */
void test_1(void) {
    /* 实际结果 */
    char ransomNote[] = "a";
    char magazine[] = "b";
    bool actual = canConstruct(ransomNote, magazine);

    /* 预期结果 */
    bool expect = false;

    /* 比较结果 */
    validateSingleValue('1', expect, actual);
}

/**
 * @description: 测试 2
 * 输入：ransomNote = "aa", magazine = "ab"
 * 输出：false
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    /* 实际结果 */
    char ransomNote[] = "aa";
    char magazine[] = "ab";
    bool actual = canConstruct(ransomNote, magazine);

    /* 预期结果 */
    bool expect = false;

    /* 比较结果 */
    validateSingleValue('2', expect, actual);
}

/**
 * @description: 测试 3
 * 输入：ransomNote = "aa", magazine = "aab"
 * 输出：true
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    /* 实际结果 */
    char ransomNote[] = "aa";
    char magazine[] = "aab";
    bool actual = canConstruct(ransomNote, magazine);

    /* 预期结果 */
    bool expect = true;

    /* 比较结果 */
    validateSingleValue('3', expect, actual);
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