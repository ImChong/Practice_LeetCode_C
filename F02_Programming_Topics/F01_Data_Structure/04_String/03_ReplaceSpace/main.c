/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\04_String\03_replaceSpace\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-18 23:18:36
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-22 18:32:00
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 剑指 Offer 05. 替换空格： https://leetcode.cn/problems/ti-huan-kong-ge-lcof/
 * https://programmercarl.com/%E5%89%91%E6%8C%87Offer05.%E6%9B%BF%E6%8D%A2%E7%A9%BA%E6%A0%BC.html
 * https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0005.%E6%9C%80%E9%95%BF%E5%9B%9E%E6%96%87%E5%AD%90%E4%B8%B2.md
 */
/* Standard header file (标准头文件) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Common function header file (通用头文件) */
#include "F01_Common_Functions/inc/common_string.h"

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: LCR 122. 路径加密
 * 假定一段路径记作字符串 path，其中以 "." 作为分隔符。
 * 现需将路径加密，加密方法为将 path 中的分隔符替换为空格 " "，请返回加密后的字符串。
 * =================================================================================
 * @param {char} *path      字符串地址
 * @return {char} *ans      修改后的字符串
 */
char *pathEncryption(char *path) {
    int sLen = strlen(path);                                    /* 字符串长度 */
    char *ans = (char *)malloc(sizeof(char) * sLen + 1);        /* 申请内存: +1 为 '\0' */
    for (int i = 0; i < sLen; i++) {                            /* 遍历字符串 */
        if (path[i] == '.') {                                       /* 如果 path[i] 字符为 '.' */
            ans[i] = ' ';                                               /* ans[i] 替换为空格 */
        } else {                                                    /* 如果 path[i] 字符不为 '.' */
            ans[i] = path[i];                                           /* ans[i] 不变 */
        }
    }
    ans[sLen] = '\0';                                           /* 字符串末尾添加 '\0' */
    return ans;                                                 /* 返回修改后的字符串 */
}

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: Test 1
 * 输入：path = "a.aef.qerf.bb"
 * 输出："a aef qerf bb"
 * =================================================================================
 * @return {void}
 */
void Test1(void) {
    /* Function call (函数调用) */
    char s[] = "a.aef.qerf.bb";
    char *actual = pathEncryption(s);

    /* Expect result (期望结果) */
    char *expect = "a aef qerf bb";

    /* Validate result (验证函数调用结果) */
    Validate_String('1', expect, actual);

    /* Free memory (释放内存) */
    String_Free(actual);
}

/**
 * @description: Test 2
 * 输入：path = "my.name.is.carl"
 * 输出："my name is carl"
 * =================================================================================
 * @return {void}
 */
void Test2(void) {
    /* Function call (函数调用) */
    char s[] = "my.name.is.carl";
    char *actual = pathEncryption(s);

    /* Expect result (期望结果) */
    char *expect = "my name is carl";

    /* Validate result (验证函数调用结果) */
    Validate_String('2', expect, actual);

    /* Free memory (释放内存) */
    String_Free(actual);
}

/**
 * @description: Test 3
 * 输入：path = "c.language.hello.world"
 * 输出："c language hello world"
 * =================================================================================
 * @return {void}
 */
void Test3(void) {
    /* Function call (函数调用) */
    char s[] = "c.language.hello.world";
    char *actual = pathEncryption(s);

    /* Expect result (期望结果) */
    char *expect = "c language hello world";

    /* Validate result (验证函数调用结果) */
    Validate_String('3', expect, actual);

    /* Free memory (释放内存) */
    String_Free(actual);
}

/**********************************************************************************/
/*                                                                                */
/*                                  MAIN FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: Main function, entry of program.
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