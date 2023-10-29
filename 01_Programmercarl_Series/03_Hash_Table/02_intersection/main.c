/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\02_intersection\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-05 14:47:06
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-30 00:29:13
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 349. 两个数组的交集：https://leetcode.cn/problems/intersection-of-two-arrays/
 * https://programmercarl.com/0349.%E4%B8%A4%E4%B8%AA%E6%95%B0%E7%BB%84%E7%9A%84%E4%BA%A4%E9%9B%86.html
 */
#include <stdlib.h>
#include "commonArray.h"            /* 00_Basics\01_Common_Func\inc\commonArray.h */
#include "methodCfg.h"
#if DOUBLE_POINTER_METHOD_EN
#include "intersection_double_pointer.h"
#elif HASH_TABLE_METHOD_EN
#include "intersection_hash_table.h"
#endif

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 测试 1
 * 输入：nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出：[2]
 * =================================================================================
 * @return {void}
 */
void test_1(void) {
    /* 实际结果 */
    int nums1[] = {1, 2, 2, 1};
    int nums1Size = ARR_SIZE(nums1);
    int nums2[] = {2, 2};
    int nums2Size = ARR_SIZE(nums2);
    int returnSize = 0;
    int *ans = intersection(nums1, nums1Size, nums2, nums2Size, &returnSize);

    /* 预期结果 */
    int expect[] = {2};
    int expectSize = ARR_SIZE(expect);

    /* 比较结果 */
    validateArray('1', expect, expectSize, ans, returnSize);

    /* 释放内存 */
    free(ans);
}

/**
 * @description: 测试 2
 * 输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出：[9,4] 或者 [4,9]
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    /* 实际结果 */
    int nums1[] = {4, 9, 5};
    int nums1Size = ARR_SIZE(nums1);
    int nums2[] = {9, 4, 9, 8, 4};
    int nums2Size = ARR_SIZE(nums2);
    int returnSize = 0;
    int *ans = intersection(nums1, nums1Size, nums2, nums2Size, &returnSize);

    /* 预期结果 */
    int expect[] = {4, 9};
    int expectSize = ARR_SIZE(expect);

    /* 比较结果 */
    validateArray('2', expect, expectSize, ans, returnSize);

    /* 释放内存 */
    free(ans);
}

/**
 * @description: 测试 3
 * 输入：nums1 = [1,2,3,4,5], nums2 = [6,7,8,9,10]
 * 输出：[]
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    /* 实际结果 */
    int nums1[] = {1, 2, 3, 4, 5};
    int nums1Size = ARR_SIZE(nums1);
    int nums2[] = {6, 7, 8, 9, 10};
    int nums2Size = ARR_SIZE(nums2);
    int returnSize = 0;
    int *ans = intersection(nums1, nums1Size, nums2, nums2Size, &returnSize);

    /* 预期结果 */
    int expect[] = {};
    int expectSize = ARR_SIZE(expect);

    /* 比较结果 */
    validateArray('3', expect, expectSize, ans, returnSize);

    /* 释放内存 */
    free(ans);
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