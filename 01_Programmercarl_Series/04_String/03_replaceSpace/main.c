/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\04_String\03_replaceSpace\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-18 23:18:36
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-26 01:34:41
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 剑指 Offer 05. 替换空格： https://leetcode.cn/problems/ti-huan-kong-ge-lcof/
 * https://programmercarl.com/%E5%89%91%E6%8C%87Offer05.%E6%9B%BF%E6%8D%A2%E7%A9%BA%E6%A0%BC.html
 * https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0005.%E6%9C%80%E9%95%BF%E5%9B%9E%E6%96%87%E5%AD%90%E4%B8%B2.md
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commonString.h"

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 替换空格
 * =================================================================================
 * @param {char} *path      字符串地址
 * @return {char} *ans      修改后的字符串
 */
char *pathEncryption(char *path) {
    int sLen = strlen(path);
    char *ans = (char *)malloc(sizeof(char) * sLen + 1);
    for (int i = 0; i < sLen; i++) {
        if (path[i] == '.') {
            ans[i] = ' ';
        } else {
            ans[i] = path[i];
        }
    }
    ans[sLen] = '\0';
    return ans;
}

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 测试 1
 * 输入：path = "a.aef.qerf.bb"
 * 输出："a aef qerf bb"
 * =================================================================================
 * @return {void}
 */
void test_1(void) {
    /* 实际结果 */
    char s[] = "a.aef.qerf.bb";
    char *actual = pathEncryption(s);

    /* 预期结果 */
    char *expect = "a aef qerf bb";

    /* 比较结果 */
    validateString('1', expect, actual);

    /* 释放内存 */
    freeString(actual);
}

/**
 * @description: 测试 2
 * 输入：path = "my.name.is.carl"
 * 输出："my name is carl"
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    /* 实际结果 */
    char s[] = "my.name.is.carl";
    char *actual = pathEncryption(s);

    /* 预期结果 */
    char *expect = "my name is carl";

    /* 比较结果 */
    validateString('2', expect, actual);

    /* 释放内存 */
    freeString(actual);
}

/**
 * @description: 测试 3
 * 输入：path = "c.language.hello.world"
 * 输出："c language hello world"
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    /* 实际结果 */
    char s[] = "c.language.hello.world";
    char *actual = pathEncryption(s);

    /* 预期结果 */
    char *expect = "c language hello world";

    /* 比较结果 */
    validateString('3', expect, actual);

    /* 释放内存 */
    freeString(actual);
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