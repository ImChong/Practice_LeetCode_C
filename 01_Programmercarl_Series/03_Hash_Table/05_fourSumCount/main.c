/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\05_fourSumCount\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-23 22:54:19
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-19 21:31:32
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 454. 四数相加 II：https://leetcode.cn/problems/4sum-ii/
 * https://programmercarl.com/0454.%E5%9B%9B%E6%95%B0%E7%9B%B8%E5%8A%A0II.html
 * https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0454.%E5%9B%9B%E6%95%B0%E7%9B%B8%E5%8A%A0II.md
 */
/* 标准头文件 */
#include <stdio.h>
#include <stdlib.h>
/* 通用头文件 */
#include "commonHelper.h"
#include "commonArray.h"
/* 解题方法配置文件 */
#include "methodCfg.h"
/* 本文件头文件 */
#include "fourSumCount.h"

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 测试 1
 * 输入：nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
 * 输出：2
 *
 * 2个元组如下：
 * 1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
 * 2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
 * =================================================================================
 * @return {void}
 */
void test_1(void) {
    /* 实际结果 */
    int A[] = {1, 2};
    int B[] = {-2, -1};
    int C[] = {-1, 2};
    int D[] = {0, 2};
    int actual = fourSumCount(A, ARR_SIZE(A), B, ARR_SIZE(B), C, ARR_SIZE(C), D, ARR_SIZE(D));

    /* 预期结果 */
    int expect = 2;

    /* 比较结果 */
    validateSingleValue('1', expect, actual);
}

/**
 * @description: 测试 2
 * 输入：nums1 = [1,1], nums2 = [-1,-1], nums3 = [1,-1], nums4 = [1,-1]
 * 输出：8
 *
 * 8个元组如下：
 * 1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-1) + 1 + (-1) = 0
 * 2. (0, 1, 0, 1) -> nums1[0] + nums2[1] + nums3[0] + nums4[1] = 1 + (-1) + 1 + (-1) = 0
 * 3. (1, 0, 0, 1) -> nums1[1] + nums2[0] + nums3[0] + nums4[1] = 1 + (-1) + 1 + (-1) = 0
 * 4. (1, 1, 0, 1) -> nums1[1] + nums2[1] + nums3[0] + nums4[1] = 1 + (-1) + 1 + (-1) = 0
 * 5. (0, 0, 1, 0) -> nums1[0] + nums2[0] + nums3[1] + nums4[0] = 1 + (-1) + (-1) + 1 = 0
 * 6. (0, 1, 1, 0) -> nums1[0] + nums2[1] + nums3[1] + nums4[0] = 1 + (-1) + (-1) + 1 = 0
 * 7. (1, 0, 1, 0) -> nums1[1] + nums2[0] + nums3[1] + nums4[0] = 1 + (-1) + (-1) + 1 = 0
 * 8. (1, 1, 1, 0) -> nums1[1] + nums2[1] + nums3[1] + nums4[0] = 1 + (-1) + (-1) + 1 = 0
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    /* 实际结果 */
    int A[] = {1,1};
    int B[] = {-1,-1};
    int C[] = {1,-1};
    int D[] = {1,-1};
    int actual = fourSumCount(A, ARR_SIZE(A), B, ARR_SIZE(B), C, ARR_SIZE(C), D, ARR_SIZE(D));

    /* 预期结果 */
    int expect = 8;

    /* 比较结果 */
    validateSingleValue('2', expect, actual);
}

/**
 * @description: 测试 3
 * 输入：nums1 = [0,200,-1], nums2 = [-200,1,0], nums3 = [0,0,1], nums4 = [-1,1,1]
 * 输出：9
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    /* 实际结果 */
    int A[] = {0,200,-1};
    int B[] = {-200,1,0};
    int C[] = {0,0,1};
    int D[] = {-1,1,1};
    int actual = fourSumCount(A, ARR_SIZE(A), B, ARR_SIZE(B), C, ARR_SIZE(C), D, ARR_SIZE(D));

    /* 预期结果 */
    int expect = 9;

    /* 比较结果 */
    validateSingleValue('3', expect, actual);
}

/**
 * @description: 测试 4
 * 输入：nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
 * 输出：1
 * =================================================================================
 * @return {void}
 */
void test_4(void) {
    /* 实际结果 */
    int A[] = {0};
    int B[] = {0};
    int C[] = {0};
    int D[] = {0};
    int actual = fourSumCount(A, ARR_SIZE(A), B, ARR_SIZE(B), C, ARR_SIZE(C), D, ARR_SIZE(D));

    /* 预期结果 */
    int expect = 1;

    /* 比较结果 */
    validateSingleValue('4', expect, actual);
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
    test_1();
    test_2();
    test_3();
    test_4();
    return 0;
}