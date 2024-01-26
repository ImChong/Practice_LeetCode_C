/*
 * @FilePath     : \Practice_LeetCode_C\F02_Programming_Topics\F01_Data_Structure\01_Array\02_removeElement\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-21 01:42:33
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : leetcode 27. 移除元素：https://leetcode.cn/problems/remove-element/
 *      https://programmercarl.com/0027.%E7%A7%BB%E9%99%A4%E5%85%83%E7%B4%A0.html
 */
/* solution header file (题解头文件) */
#include "removeElement.h"
/* Standard header file (标准头文件) */
#include <stdio.h>
/* Common function header file (通用头文件) */
#include "commonArray.h"
/* solution method configuration header file (解题方法配置文件) */
// #include "methodCfg"     /* Uncomment this line if solution has multiple methods */

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: Test 1
 * Input: testNums = [3, 2, 2, 3], val = 3
 * Outut: 2, testNums = [2, 2]
 * =================================================================================
 * @return {void}
 */
void Test1(void) {
    /* Function call (函数调用) */
    int testNums[] = {3, 2, 2, 3};
    int removeVal = 3;
    int resultLen = removeElement(testNums, ARR_SIZE(testNums), removeVal);

    /* Expect result (期望结果) */
    int expectNums[] = {2, 2};
    int expectLen = ARR_SIZE(expectNums);

    /* Validate result (验证函数调用结果) */
    Validate_Array('1', expectNums, expectLen, testNums, resultLen, COMMON_FALSE);
}

/**
 * @description: Test 2
 * Input: testNums = [0, 1, 2, 2, 3, 0, 4, 2], val = 2
 * Outut: 5, testNums = [0, 1, 3, 0, 4]
 * =================================================================================
 * @return {void}
 */
void Test2(void) {
    /* Function call (函数调用) */
    int testNums[] = {0, 1, 2, 2, 3, 0, 4, 2};
    int removeVal = 2;
    int resultLen = removeElement(testNums, ARR_SIZE(testNums), removeVal);

    /* Expect result (期望结果) */
    int expectNums[] = {0, 1, 3, 0, 4};
    int expectLen = ARR_SIZE(expectNums);

    /* Validate result (验证函数调用结果) */
    Validate_Array('2', expectNums, expectLen, testNums, resultLen, COMMON_FALSE);
}

/**
 * @description: Test 3
 * Input: testNums = [1], val = 2
 * Outut: 1, testNums = [1]
 * =================================================================================
 * @return {void}
 */
void Test3(void) {
    /* Function call (函数调用) */
    int testNums[] = {1};
    int removeVal = 2;
    int resultLen = removeElement(testNums, ARR_SIZE(testNums), removeVal);

    /* Expect result (期望结果) */
    int expectNums[] = {1};
    int expectLen = ARR_SIZE(expectNums);

    /* Validate result (验证函数调用结果) */
    Validate_Array('3', expectNums, expectLen, testNums, resultLen, COMMON_FALSE);
}

/**
 * @description: Test 4
 * Input: testNums = [1], val = 1
 * Outut: 0, testNums = []
 * =================================================================================
 * @return {void}
 */
void Test4(void) {
    /* Function call (函数调用) */
    int testNums[] = {1};
    int removeVal = 1;
    int resultLen = removeElement(testNums, ARR_SIZE(testNums), removeVal);

    /* Expect result (期望结果) */
    int expectNums[] = {};
    int expectLen = ARR_SIZE(expectNums);

    /* Validate result (验证函数调用结果) */
    Validate_Array('4', expectNums, expectLen, testNums, resultLen, COMMON_FALSE);
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
    Test4();
    return 0;
};