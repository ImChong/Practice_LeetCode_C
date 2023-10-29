/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\04_String\04_reverseWords\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-18 23:18:36
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-29 10:18:03
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 151. 反转字符串中的单词：https://leetcode.cn/problems/reverse-words-in-a-string/
 * https://programmercarl.com/0151.%E7%BF%BB%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2%E9%87%8C%E7%9A%84%E5%8D%95%E8%AF%8D.html
 * https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0151.%E7%BF%BB%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2%E9%87%8C%E7%9A%84%E5%8D%95%E8%AF%8D.md
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
 * @description: 删除字符串中多余的空格
 * =================================================================================
 * @param {char} *s     字符串地址
 * @return {void}
 */
void removeExtraSpace(char *s) {
    int start = 0;                                  /* 左指针 */
    int end = strlen(s) - 1;                        /* 右指针 */
    while (s[start] == ' ') {                       /* 左指针指向空格 */
        start++;                                        /* 左指针右移 */
    }
    while (s[end] == ' ') {                         /* 右指针指向空格 */
        end--;                                          /* 右指针左移 */
    }
    int slow = 0;                                   /* 慢指针 */
    for (int i = start; i <= end; i++) {            /* 遍历字符串 */
        if (s[i] == ' ' && s[i + 1] == ' ') {           /* 当前字符为空格，且下一个字符也为空格 */
            continue;                                       /* 跳过当前字符 */
        }
        s[slow++] = s[i];                               /* 将当前字符赋值给慢指针指向的字符，慢指针 + 1 */
    }
    s[slow] = '\0';                                 /* 将慢指针指向的字符赋值为字符串结束符 */
}

/**
 * @description: 反转字符串中的单词
 * =================================================================================
 * @param {char} *s         字符串地址
 * @return {char} *ans      修改后的字符串
 */
char *reverseWords(char *s) {
    removeExtraSpace(s);
    reverseStringSection(s, 0, strlen(s) - 1);
    int slow = 0;
    for (int i = 0; i <= strlen(s); i++) {
        if (s[i] == ' ' || s[i] == '\0') {
            reverseStringSection(s, slow, i - 1);
            slow = i + 1;
        }
    }
    return s;
}

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 测试 1
 * 输入：s = "the sky is blue"
 * 输出："blue is sky the"
 * =================================================================================
 * @return {void}
 */
void test_1(void) {
    /* 实际结果 */
    char s[] = "the sky is blue";
    char *actual = reverseWords(s);

    /* 预期结果 */
    char *expect = "blue is sky the";

    /* 比较结果 */
    validateString('1', expect, actual);
}

/**
 * @description: 测试 2
 * 输入：s = "  hello world  "
 * 输出："world hello"
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    /* 实际结果 */
    char s[] = "  hello world  ";
    char *actual = reverseWords(s);

    /* 预期结果 */
    char *expect = "world hello";

    /* 比较结果 */
    validateString('2', expect, actual);
}

/**
 * @description: 测试 3
 * 输入：s = "a good   example"
 * 输出："example good a"
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    /* 实际结果 */
    char s[] = "a good   example";
    char *actual = reverseWords(s);

    /* 预期结果 */
    char *expect = "example good a";

    /* 比较结果 */
    validateString('3', expect, actual);
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