/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\02_intersection\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-05 14:47:06
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-19 00:54:22
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 349. 两个数组的交集：https://leetcode.cn/problems/intersection-of-two-arrays/
 * https://programmercarl.com/0349.%E4%B8%A4%E4%B8%AA%E6%95%B0%E7%BB%84%E7%9A%84%E4%BA%A4%E9%9B%86.html
 */
#include <stdio.h>
#include <stdlib.h>

/**********************************************************************************/
/*                                                                                */
/*                                MACRO FUNCTIONS                                 */
/*                                                                                */
/**********************************************************************************/
#define ARR_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))          /* 获取数组长度 */

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/* TODO */
/* ============================================================================== */
/* ============================================================================== */
/**
 * @description: 比较函数
 * =================================================================================
 * @param {void} *a
 * @param {void} *b
 * @return {int}
 */
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

/**
 * @description: 两个数组的交集
 * =================================================================================
 * @param {int} *numsA
 * @param {int} numsASize
 * @param {int} *numsB
 * @param {int} numsBSize
 * @param {int} *returnSize
 * @return {int} *res
 */
int *intersection(int *numsA, int numsASize, int *numsB, int numsBSize, int *returnSize){
    qsort(numsA, numsASize, sizeof(int), cmp);          /* 将数组1排序 */
    qsort(numsB, numsBSize, sizeof(int), cmp);          /* 将数组2排序 */
    int *res = (int *)malloc(sizeof(int) * (numsASize < numsBSize ? numsASize : numsBSize));    /* 创建一个新数组用于保存结果 */
    int i = 0, j = 0, k = 0;                            /* 创建3个索引 */
    while (i < numsASize && j < numsBSize) {            /* 当i和j索引没有出界时，保持循环 */
        if (numsA[i] == numsB[j]) {                         /* 如果 数组1索引i的值 等于 数组2索引j的值 */
            if (k == 0 || res[k - 1] != numsA[i]) {             /* 结果去除重复元素 */
                res[k++] = numsA[i];                                /* 将相同元素添加至结果数组 */
            }
            i++;                                                /* i向后移动一位 */
            j++;                                                /* j向后移动一位 */
        } else if (numsA[i] < numsB[j]) {                   /* 如果 数组1索引i的值 小于 数组2索引j的值*/
            i++;                                                /* i向后移动一位 */
        } else {                                            /* 反之 */
            j++;                                                /* j向后移动一位 */
        }
    }
    *returnSize = k;                                    /* 返回数组大小为k */
    return res;                                         /* 返回结果数组 */
}

/**********************************************************************************/
/*                                                                                */
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 打印数组
 * =================================================================================
 * @param {int} *arr            数组
 * @param {int} arrSize         数组大小
 * @return {void}
 */
void printArray(int *arr, int arrSize) {
    printf("Arr: ");
    for (int i = 0; i < arrSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * @description: 验证答案
 * =================================================================================
 * @param {char} testNum        测试编号
 * @param {int} *expect         预期
 * @param {int} expectSize      预期大小
 * @param {int} *actual         实际
 * @param {int} actualSize      实际大小
 * @return {*}
 */
void validateAnswer(char testNum, int *expect, int expectSize, int *actual, int actualSize) {
    if (expectSize != actualSize) {
        printf("❌ Test %c Failed\n", testNum);
        return;
    } else {
        for (int i = 0; i < expectSize; i++) {
            if (expect[i] != actual[i]) {
                printf("❌ Test %c Failed\n", testNum);
                return;
            }
        }
    }
    printf("✅ Test %c Passed\n", testNum);
}

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
    validateAnswer('1', expect, expectSize, ans, returnSize);

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
    validateAnswer('2', expect, expectSize, ans, returnSize);

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
    validateAnswer('3', expect, expectSize, ans, returnSize);

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