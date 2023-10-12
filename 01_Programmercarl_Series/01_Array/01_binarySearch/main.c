/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\01_Array\01_binarySearch\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-12 23:44:19
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 704. 二分查找：https://leetcode.cn/problems/binary-search/
 * https://programmercarl.com/0704.%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
 */
#include <stdio.h>

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
 * @description: 二分查找
 * =================================================================================
 * @param {int} *nums       有序数组
 * @param {int} numsSize    数组大小
 * @param {int} target      目标值
 * @return {int} ans        目标值在数组中的索引
 */
int search(int *nums, int numsSize, int target) {
    int left = 0;                               /* 左指针 */
    int right = numsSize - 1;                   /* 右指针 */

    while (left <= right) {                     /* 循环条件：左指针小于等于右指针 */
        int mid = left + (right - left) / 2;        /* 中间指针 */

        if (nums[mid] == target) {                  /* 找到目标值 */
            return mid;                                 /* 返回索引 */
        } else if (nums[mid] < target) {            /* 目标值在右侧 */
            left = mid + 1;                             /* 左指针右移 */
        } else {                                    /* 目标值在左侧 */
            right = mid - 1;                            /* 右指针左移 */
        }
    }
    return -1;                                  /* 未找到目标值 */
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
    int nums[] = {-1, 0, 3, 5, 9, 12};                  /* 有序数组 */
    int target = 9;
    int ans = search(nums, ARRAY_SIZE(nums), target);

    /* 预期结果 */
    int expect = 4;

    /* 比较结果 */
    validateAnswer('1', expect, ans);
}

/**
 * @description: 测试 2
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    /* 实际结果 */
    int nums[] = {-1, 0, 3, 5, 9, 12};                  /* 有序数组 */
    int target = 2;
    int ans = search(nums, ARRAY_SIZE(nums), target);

    /* 预期结果 */
    int expect = -1;

    /* 比较结果 */
    validateAnswer('2', expect, ans);
}

/**
 * @description: 测试 3
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    /* 实际结果 */
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};       /* 有序数组 */
    int target = 5;
    int ans = search(nums, ARRAY_SIZE(nums), target);

    /* 预期结果 */
    int expect = 4;

    /* 比较结果 */
    validateAnswer('3', expect, ans);
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