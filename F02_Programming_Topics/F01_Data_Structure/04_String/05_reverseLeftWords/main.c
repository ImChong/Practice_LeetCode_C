/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\04_String\05_reverseLeftWords\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-18 23:18:36
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-22 18:32:49
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : LCR 182. 动态口令： https://leetcode.cn/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/
 * https://programmercarl.com/%E5%89%91%E6%8C%87Offer58-II.%E5%B7%A6%E6%97%8B%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2.html
 * https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E5%89%91%E6%8C%87Offer58-II.%E5%B7%A6%E6%97%8B%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2.md
 */
/* Standard header file (标准头文件) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Common function header file (通用头文件) */
#include "commonString.h"

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 动态口令
 * =================================================================================
 * @param {char} *password      字符串地址
 * @param {int} target          目标位置
 * @return {char} *ans          修改后的字符串
 */
char *dynamicPassword(char *password, int target) {
    int sLen = strlen(password);                            /* 字符串长度 */
    char *ans = (char *)malloc(sizeof(char) * sLen + 1);    /* 申请内存 */
    int index = 0;                                          /* 索引指针 */
    for (int i = target; i < sLen; i++) {                   /* 遍历字符串 */
        ans[index++] = password[i];                             /* 将当前字符赋值给 ans */
    }
    for (int i = 0; i < target; i++) {                      /* 遍历字符串 */
        ans[index++] = password[i];                             /* 将当前字符赋值给 ans */
    }
    ans[sLen] = '\0';                                       /* 将 ans 最后一位赋值为字符串结束符 */
    return ans;                                             /* 返回修改后的字符串 */
}

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 测试 1
 * 输入: password = "s3cur1tyC0d3", target = 4
 * 输出: "r1tyC0d3s3cu"
 * =================================================================================
 * @return {void}
 */
void Test1(void) {
    /* Function call (函数调用) */
    char s[] = "s3cur1tyC0d3";
    int target = 4;
    char *actual = dynamicPassword(s, target);

    /* Expect result (期望结果) */
    char *expect = "r1tyC0d3s3cu";

    /* 比较结果 */
    Validate_String('1', expect, actual);

    /* 释放内存 */
    String_Free(actual);
}

/**
 * @description: 测试 2
 * 输入: password = "lrloseumgh", target = 6
 * 输出: "umghlrlose"
 * =================================================================================
 * @return {void}
 */
void Test2(void) {
    /* Function call (函数调用) */
    char s[] = "lrloseumgh";
    int target = 6;
    char *actual = dynamicPassword(s, target);

    /* Expect result (期望结果) */
    char *expect = "umghlrlose";

    /* 比较结果 */
    Validate_String('2', expect, actual);

    /* 释放内存 */
    String_Free(actual);
}

/**
 * @description: 测试 3
 * 输入：password = "leetcode", target = 4
 * 输出："codeleet"
 * =================================================================================
 * @return {void}
 */
void Test3(void) {
    /* Function call (函数调用) */
    char s[] = "leetcode";
    int target = 4;
    char *actual = dynamicPassword(s, target);

    /* Expect result (期望结果) */
    char *expect = "codeleet";

    /* 比较结果 */
    Validate_String('3', expect, actual);

    /* 释放内存 */
    String_Free(actual);
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
    Test1();
    Test2();
    Test3();
    return 0;
}