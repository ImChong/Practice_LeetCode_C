/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\src\commonString.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-24 00:56:52
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-28 23:28:53
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用字符串源文件
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commonString.h"

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 交换字符
 * =================================================================================
 * @param {char} *a     a字符地址
 * @param {char} *b     b字符地址
 * @return {void}
 */
void swapChar(char *a, char *b) {
    char tmp = *a;      /* 保存a字符 */
    *a = *b;            /* 将b字符赋值给a字符 */
    *b = tmp;           /* 将保存的a字符赋值给b字符 */
}

/**
 * @description: 反转字符串
 * =================================================================================
 * @param {char} *s             字符串地址
 * @param {int} leftIndex       左指针
 * @param {int} rightIndex      右指针
 * @return {void}
 */
void reverseStringSection(char *s, int leftIndex, int rightIndex) {
    while (leftIndex < rightIndex) {                    /* 左右指针未相遇 */
        swapChar(&s[leftIndex++], &s[rightIndex--]);        /* 交换字符，左指针右移，右指针左移 */
    }
}

/**
 * @description: 打印字符串
 * =================================================================================
 * @param {char} *s     字符串地址
 * @return {void}
 */
void printString(char *s) {
    printf("Str: %s\n", s);
}

/**
 * @description: 释放字符串
 * =================================================================================
 * @param {char} *s     字符串地址
 * @return {void}
 */
void freeString(char *s) {
    if (s != NULL) {        /* 字符串不为空 */
        free(s);                /* 释放字符串 */
        s = NULL;               /* 字符串指针置空 */
    }
}

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 验证字符串
 * =================================================================================
 * @param {char} testNum    测试编号
 * @param {int} expect      预期
 * @param {int} actual      实际
 * @return {void}
 */
void validateString(char testNum, char *expect, char *actual) {
    if (expect == NULL && actual == NULL) {
        printf("✅ Test %c Passed\n", testNum);
        return;
    } else if (expect == NULL || actual == NULL) {
        printf("❌ Test %c Failed\n", testNum);
        return;
    }
    if (strcmp(expect, actual) == 0) {
        printf("✅ Test %c Passed\n", testNum);
    } else {
        printf("❌ Test %c Failed\n", testNum);
    }
}