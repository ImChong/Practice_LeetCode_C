/*
 * @FilePath     : \Practice_LeetCode_C\F01_Common_Functions\src\common_string.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-24 00:56:52
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-27 11:28:54
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用字符串源文件
 */
/* Common function configuration file (通用函数配置文件) */
#include "compile_cfg.h"        /* NOLINT */
#if COMMON_STRING_EN /* whether compile this file, the definition of this macro can be found in compileCfg.h */
/* Header file (本文件头文件) */
#include "F01_Common_Functions/inc/common_string.h"
/* Standard header file (标准头文件) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Common function header file (通用头文件) */
#include "F01_Common_Functions/inc/common_def/common_type_def.h"

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
 * @return {int}        交换结果: 0-成功，-1-失败
 */
int Char_Swap(char *a, char *b) {
    if (a == NULL || b == NULL) {
        return COMMON_ERR;
    }
    char tmp = *a;      /* 保存a字符 */
    *a = *b;            /* 将b字符赋值给a字符 */
    *b = tmp;           /* 将保存的a字符赋值给b字符 */
    return COMMON_OK;
}

/**
 * @description: 反转字符串
 * =================================================================================
 * @param {char} *s             字符串地址
 * @param {int} left_index       左指针
 * @param {int} right_index      右指针
 * @return {int}                反转结果: 0-成功，-1-失败
 */
int String_Reverse(char *s, int left_index, int right_index) {
    if (s == NULL || left_index < 0 ||
            right_index >= (int)strlen(s) ||             /* NOLINT(readability/casting) */
            left_index > right_index) {
        return COMMON_ERR;
    }
    while (left_index < right_index) {                    /* 左右指针未相遇 */
        Char_Swap(&s[left_index++], &s[right_index--]);        /* 交换字符，左指针右移，右指针左移 */
    }
    return COMMON_OK;
}

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 打印字符串
 * =================================================================================
 * @param {char} *s     字符串地址
 * @return {int}
 */
int String_Print(char *s) {
    if (printf("Str: %s\n", s) < 0) {       /* 打印字符串 */
        return COMMON_ERR;                    /* 打印失败 */
    }
    return COMMON_OK;                       /* 打印成功 */
}

/**
 * @description: 释放字符串
 * =================================================================================
 * @param {char} **s     字符串地址
 * @return {int}
 */
int String_Free(char **s) {
    if (*s != NULL) {       /* 字符串不为空 */
        free(*s);               /* 释放字符串 */
        *s = NULL;              /* 字符串指针置空 */
    }
    return COMMON_OK;       /* 释放成功 */
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
 * @param {int} expect      预期字符串
 * @param {int} actual      实际字符串
 * @return {int}
 */
int Validate_String(char testNum, char *expect, char *actual) {
    int isSuccess = COMMON_TRUE;

    if (expect == NULL && actual == NULL) {
        isSuccess = COMMON_TRUE;
    } else if (expect == NULL || actual == NULL) {
        isSuccess = COMMON_FALSE;
    } else if (strcmp(expect, actual) == 0) {
        isSuccess = COMMON_TRUE;
    } else {
        isSuccess = COMMON_FALSE;
    }

    printf("=========================\n");          /* 打印分割线 */
    if (isSuccess) {                                /* 如果通过测试 */
        printf(" - ✅ Test %c Passed\n", testNum);      /* 打印通过信息 */
    } else {                                        /* 如果未通过测试 */
        printf(" - ❌ Test %c Failed\n", testNum);      /* 打印未通过信息 */
    }
    printf("=========================\n");
    printf("    - Expect: %s\n", expect);
    printf("    - Actual: %s\n", actual);
    if (isSuccess) {                                /* 如果通过测试 */
        return COMMON_OK;                               /* 返回成功 */
    } else {                                        /* 如果未通过测试 */
        return COMMON_ERR;                              /* 返回失败 */
    }
}


#endif          /* COMMON_STRING_EN */
