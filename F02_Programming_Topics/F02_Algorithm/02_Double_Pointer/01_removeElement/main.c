/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\05_Double_Pointer\01_removeElement\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-18 23:18:36
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-28 00:16:27
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 27. 移除元素: https://leetcode.cn/problems/remove-element/
 * https://programmercarl.com/0027.%E7%A7%BB%E9%99%A4%E5%85%83%E7%B4%A0.html
 * https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0027.%E7%A7%BB%E9%99%A4%E5%85%83%E7%B4%A0.md
 */
/* Common function header file (通用头文件) */
#include "commonArray.h"

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
 * @param {int} *nums           数组地址
 * @param {int} numsSize        数组大小
 * @param {int} val             移除的元素
 * @return {int} returnSize     移除元素后的数组大小
 */
int removeElement(int *nums, int numsSize, int val){

    /* TODO */

    return 0;
}

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: Test 1
 * 输入：nums = [3,2,2,3], val = 3
 * 输出：2, nums = [2,2]
 * =================================================================================
 * @return {void}
 */
void Test1(void) {
    /* Function call (函数调用) */
    int nums[] = {3, 2, 2, 3};
    int numsSize = ARR_SIZE(nums);
    int val = 3;
    int actualSize = removeElement(nums, numsSize, val);

    /* Expect result (期望结果) */
    int expectSize = 2;
    int expectNums[] = {2, 2};

    /* Validate result (验证函数调用结果) */
    Validate_Array('1', expectNums, expectSize, nums, actualSize);
}

/**
 * @description: Test 2
 * 输入：nums = [0,1,2,2,3,0,4,2], val = 2
 * 输出：5, nums = [0,1,4,0,3]
 * =================================================================================
 * @return {void}
 */
void Test2(void) {
    /* Function call (函数调用) */
    int nums[] = {0, 1, 2, 2, 3, 0, 4, 2};
    int numsSize = ARR_SIZE(nums);
    int val = 2;
    int actualSize = removeElement(nums, numsSize, val);

    /* Expect result (期望结果) */
    int expectSize = 5;
    int expectNums[] = {0, 1, 4, 0, 3};

    /* Validate result (验证函数调用结果) */
    Validate_Array('2', expectNums, expectSize, nums, actualSize);
}

/**
 * @description: Test 3
 * 输入：nums = [3,3], val = 3
 * 输出：0, nums = []
 * =================================================================================
 * @return {void}
 */
void Test3(void) {
    /* Function call (函数调用) */
    int nums[] = {3, 3};
    int numsSize = ARR_SIZE(nums);
    int val = 3;
    int actualSize = removeElement(nums, numsSize, val);

    /* Expect result (期望结果) */
    int expectSize = 0;
    int expectNums[] = {};

    /* Validate result (验证函数调用结果) */
    Validate_Array('3', expectNums, expectSize, nums, actualSize);
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
    return 0;
}