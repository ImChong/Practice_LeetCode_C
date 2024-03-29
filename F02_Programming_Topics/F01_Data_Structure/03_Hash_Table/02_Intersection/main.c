/*
 * @FilePath     : \Practice_LeetCode_C\02_Programming_Topics\03_Hash_Table\02_intersection\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-11-27 09:49:42
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-31 20:45:26
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 349. 两个数组的交集：https://leetcode.cn/problems/intersection-of-two-arrays/
 *      https://programmercarl.com/0349.%E4%B8%A4%E4%B8%AA%E6%95%B0%E7%BB%84%E7%9A%84%E4%BA%A4%E9%9B%86.html
 */
/* Standard header file (标准头文件) */
#include <stdio.h>
#include <stdlib.h>
/* Common function header file (通用头文件) */
#include "F01_Common_Functions/inc/common_def/common_type_def.h"
#include "F01_Common_Functions/inc/common_array.h"
/* solution method configuration file (解题方法配置文件) */
#include "methodCfg.h"
/* solution header file (题解头文件) */
#include "intersection.h"

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: Test 1
 * 输入：nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出：[2]
 * =================================================================================
 * @return {void}
 */
void Test1(void) {
    /* Function call (函数调用) */
    int nums1[] = {1, 2, 2, 1};
    int nums1Size = ARR_SIZE(nums1);
    int nums2[] = {2, 2};
    int nums2Size = ARR_SIZE(nums2);
    int returnSize = 0;
    int *ans = intersection(nums1, nums1Size, nums2, nums2Size, &returnSize);

    /* Expect result (期望结果) */
    int expect[] = {2};
    int expectSize = ARR_SIZE(expect);

    /* Validate result (验证函数调用结果) */
    Validate_Array('1', expect, expectSize, ans, returnSize, COMMON_TRUE);

    /* Free memory (释放内存) */
    free(ans);
}

/**
 * @description: Test 2
 * 输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出：[9,4] 或者 [4,9]
 * =================================================================================
 * @return {void}
 */
void Test2(void) {
    /* Function call (函数调用) */
    int nums1[] = {4, 9, 5};
    int nums1Size = ARR_SIZE(nums1);
    int nums2[] = {9, 4, 9, 8, 4};
    int nums2Size = ARR_SIZE(nums2);
    int returnSize = 0;
    int *ans = intersection(nums1, nums1Size, nums2, nums2Size, &returnSize);

    /* Expect result (期望结果) */
    int expect[] = {4, 9};
    int expectSize = ARR_SIZE(expect);

    /* Validate result (验证函数调用结果) */
    Validate_Array('2', expect, expectSize, ans, returnSize, COMMON_TRUE);

    /* Free memory (释放内存) */
    free(ans);
}

/**
 * @description: Test 3
 * 输入：nums1 = [1,2,3,4,5], nums2 = [6,7,8,9,10]
 * 输出：[]
 * =================================================================================
 * @return {void}
 */
void Test3(void) {
    /* Function call (函数调用) */
    int nums1[] = {1, 2, 3, 4, 5};
    int nums1Size = ARR_SIZE(nums1);
    int nums2[] = {6, 7, 8, 9, 10};
    int nums2Size = ARR_SIZE(nums2);
    int returnSize = 0;
    int *ans = intersection(nums1, nums1Size, nums2, nums2Size, &returnSize);

    /* Expect result (期望结果) */
    int expect[] = {};
    int expectSize = ARR_SIZE(expect);

    /* Validate result (验证函数调用结果) */
    Validate_Array('3', expect, expectSize, ans, returnSize, COMMON_TRUE);

    /* Free memory (释放内存) */
    free(ans);
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