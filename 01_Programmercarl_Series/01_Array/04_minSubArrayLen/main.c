/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\01_Array\04_minSubArrayLen\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-12 23:54:50
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 209.长度最小的子数组：https://leetcode.cn/problems/minimum-size-subarray-sum/
 * https://programmercarl.com/0209.%E9%95%BF%E5%BA%A6%E6%9C%80%E5%B0%8F%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84.html
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**********************************************************************************/
/*                                                                                */
/*                                MACRO FUNCTIONS                                 */
/*                                                                                */
/**********************************************************************************/
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))        /* 获取数组长度 */

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 长度最小的子数组
 * =================================================================================
 * @param {int} target      目标值
 * @param {int} *nums       数组
 * @param {int} numsSize    数组大小
 * @return {int} minLen     最小长度
 */
int minSubArrayLen(int target, int *nums, int numsSize) {
    int minLen = INT_MAX;                                   /* 记录最小长度 */
    int sum = 0;                                            /* 记录子数组的合 */

    int left = 0, right = 0;                                /* 初始化左右指针 */
    for (; right < numsSize; right++) {                     /* 遍历数组 */
        sum += nums[right];                                     /* 添加右侧数字 */
        while (sum >= target) {                                 /* 当sum大于target时 */
            int subLen = right - left + 1;                          /* 计算子长度*/
            minLen = minLen < subLen ? minLen : subLen;             /* 更新最小子长度 */
            sum -= nums[left++];                                    /* 去除左侧数字*/
        }
    }
    return minLen == INT_MAX ? 0 : minLen;                  /* 返回最小长度 */
}

/**********************************************************************************/
/*                                                                                */
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 验证答案
 * =================================================================================
 * @param {char} testNum    测试编号
 * @param {int} expect      预期
 * @param {int} actual      实际
 * @return {void}
 */
void validateAnswer(char testNum, int expect, int actual) {
    if (expect == actual) {
        printf("✅ Test %c Passed\n", testNum);
    } else {
        printf("❌ Test %c Failed\n", testNum);
    }
}

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 测试 1
 * =================================================================================
 * @return {void}
 */
void test_1(void) {
    /* 实际结果 */
    int nums[] = {2, 3, 1, 2, 4, 3};
    int numsSize = ARRAY_SIZE(nums);
    int target = 7;
    int resultLen = minSubArrayLen(target, nums, numsSize);

    /* 预期结果 */
    int expectLen = 2;

    /* 比较结果 */
    validateAnswer('1', expectLen, resultLen);
}

/**
 * @description: 测试 2
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    /* 实际结果 */
    int nums[] = {1, 1, 1, 1, 1, 1, 1, 1};
    int numsSize = ARRAY_SIZE(nums);
    int target = 11;
    int resultLen = minSubArrayLen(target, nums, numsSize);

    /* 预期结果 */
    int expectLen = 0;

    /* 比较结果 */
    validateAnswer('2', expectLen, resultLen);
}

/**
 * @description: 测试 3
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    /* 实际结果 */
    int nums[] = {1, 2, 3, 4, 5};
    int numsSize = ARRAY_SIZE(nums);
    int target = 11;
    int resultLen = minSubArrayLen(target, nums, numsSize);

    /* 预期结果 */
    int expectLen = 3;

    /* 比较结果 */
    validateAnswer('3', expectLen, resultLen);
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