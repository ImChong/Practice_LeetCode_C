/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\01_Array\02_removeElement\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-22 12:27:14
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 27. 移除元素：https://leetcode.cn/problems/remove-element/
 * https://programmercarl.com/0027.%E7%A7%BB%E9%99%A4%E5%85%83%E7%B4%A0.html
 */
#include <stdio.h>
#include "commonArray.h"        /* 00_Basics\01_Common_Func\inc\commonArray.h */

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 移除元素
 * =================================================================================
 * @param {int} *nums       数组
 * @param {int} numsSize    数组大小
 * @param {int} val         目标值
 * @return {int} slow       慢指针
 */
int removeElement(int *nums, int numsSize, int val) {
    int quick, slow;                                        /* 初始化快慢指针 */
    for (quick = 0, slow = 0; quick < numsSize; quick++) {  /* 快指针遍历数组 */
        if (nums[quick] != val) {                               /* 当快指针所指向的值不等于val时*/
            nums[slow] = nums[quick];                           /* 慢指针的值等于快指针的值 */
            slow++;                                             /* 慢指针位置 + 1 */
        }
    }
    return slow;                                            /* 返回慢指针  */
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
    int nums[] = {3, 2, 2, 3};
    int removeVal = 3;
    int resultLen = removeElement(nums, ARR_SIZE(nums), removeVal);

    /* 预期结果 */
    int expectNums[] = {2, 2};
    int expectLen = ARR_SIZE(expectNums);

    /* 比较结果 */
    validateAnswerArray('1', expectNums, expectLen, nums, resultLen);
}

/**
 * @description: 测试 2
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    /* 实际结果 */
    int nums[] = {0, 1, 2, 2, 3, 0, 4, 2};
    int removeVal = 2;
    int resultLen = removeElement(nums, ARR_SIZE(nums), removeVal);

    /* 预期结果 */
    int expectNums[] = {0, 1, 3, 0, 4};
    int expectLen = ARR_SIZE(expectNums);

    /* 比较结果 */
    validateAnswerArray('2', expectNums, expectLen, nums, resultLen);
}

/**
 * @description: 测试 3
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    /* 实际结果 */
    int nums[] = {1};
    int removeVal = 2;
    int resultLen = removeElement(nums, ARR_SIZE(nums), removeVal);

    /* 预期结果 */
    int expectNums[] = {1};
    int expectLen = ARR_SIZE(expectNums);

    /* 比较结果 */
    validateAnswerArray('3', expectNums, expectLen, nums, resultLen);
}

/**
 * @description: 测试 4
 * =================================================================================
 * @return {void}
 */
void test_4(void) {
    /* 实际结果 */
    int nums[] = {1};
    int removeVal = 1;
    int resultLen = removeElement(nums, ARR_SIZE(nums), removeVal);

    /* 预期结果 */
    int expectNums[] = {};
    int expectLen = ARR_SIZE(expectNums);

    /* 比较结果 */
    validateAnswerArray('4', expectNums, expectLen, nums, resultLen);
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
    test_4();
    return 0;
};