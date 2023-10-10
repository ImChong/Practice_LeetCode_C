/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\01_isAnagram\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-05 14:47:06
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-10 10:10:53
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
 * @param {char} *s
 * @param {char} *t
 * @return {*}
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
    /* Test case 1 */
    printf("======== Case 1 ======== \n");
    char s1[] = "anagram";
    char t1[] = "nagaram";
    printf("Test case 1: %d\n", isAnagram(s1, t1));

    /* Test case 2 */
    printf("======== Case 2 ======== \n");
    char s2[] = "rat";
    char t2[] = "car";
    printf("Test case 2: %d\n", isAnagram(s2, t2));

    return 0;
}