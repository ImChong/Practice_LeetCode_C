/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\02_intersection\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-05 14:47:06
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-10 10:14:42
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 349. 两个数组的交集：https://leetcode.cn/problems/intersection-of-two-arrays/
 * https://programmercarl.com/0349.%E4%B8%A4%E4%B8%AA%E6%95%B0%E7%BB%84%E7%9A%84%E4%BA%A4%E9%9B%86.html
 */
#include <stdio.h>
#include <stdlib.h>

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
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
 * @description:
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
 * @param {int} *arr
 * @param {int} arrSize
 * @return {void}
 */
void printArray(int *arr, int arrSize) {
    printf("Arr: ");
    for (int i = 0; i < arrSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
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
    /* Test case 1 */
    printf("======== Case 1 ======== \n");
    int nums1[] = {1, 2, 2, 1};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2[] = {2, 2};
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
    int returnSize = 0;
    int *ans = intersection(nums1, nums1Size, nums2, nums2Size, &returnSize);
    printArray(ans, returnSize);

    /* Test case 2 */
    printf("======== Case 2 ======== \n");
    int nums3[] = {4, 9, 5};
    int nums4[] = {9, 4, 9, 8, 4};
    printArray(nums4, 5);
    ans = intersection(nums3, 3, nums4, 5, &returnSize);
    printArray(ans, returnSize);

    return 0;
}