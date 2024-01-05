/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\06_canConstruct\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-20 23:19:11
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
/* standard header file (标准头文件) */
#include <stdio.h>
#include <stdbool.h>
/* 常用头文件 */
#include "commonSingleValue.h"
/* 方法配置文件 */
#include "methodCfg.h"
/* 本题头文件 */
#include "canConstruct.h"

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
void Test1(void) {
    /* 实际结果 */
    char ransomNote[] = "a";
    char magazine[] = "b";
    bool actual = canConstruct(ransomNote, magazine);

    /* 预期结果 */
    bool expect = false;

    /* 比较结果 */
    Validate_SingleValue('1', expect, actual);
}

/**
 * @description: 测试 2
 * 输入：ransomNote = "aa", magazine = "ab"
 * 输出：false
 * =================================================================================
 * @return {void}
 */
void Test2(void) {
    /* 实际结果 */
    char ransomNote[] = "aa";
    char magazine[] = "ab";
    bool actual = canConstruct(ransomNote, magazine);

    /* 预期结果 */
    bool expect = false;

    /* 比较结果 */
    Validate_SingleValue('2', expect, actual);
}

/**
 * @description: 测试 3
 * 输入：ransomNote = "aa", magazine = "aab"
 * 输出：true
 * =================================================================================
 * @return {void}
 */
void Test3(void) {
    /* 实际结果 */
    char ransomNote[] = "aa";
    char magazine[] = "aab";
    bool actual = canConstruct(ransomNote, magazine);

    /* 预期结果 */
    bool expect = true;

    /* 比较结果 */
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
#if DOUBLE_POINTER_METHOD_EN
    printf("DOUBLE_POINTER_METHOD_EN\r\n");
#elif HASH_TABLE_METHOD_EN
    printf("HASH_TABLE_METHOD_EN\r\n");
#endif
    Test1();
    Test2();
    Test3();
    return 0;
}