/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\02_intersection\src\intersection_double_pointer.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-29 11:36:31
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-31 00:19:21
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 两个数组的交集 - 双指针解法源文件
 */

#include "methodCfg.h"
#if DOUBLE_POINTER_METHOD_EN
/* 标准头文件 */
#include <stdlib.h>
/* 本文件头文件 */
#include "intersection_double_pointer.h"

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 比较函数
 * qsort是C标准库中的一个函数，用于对数组进行快速排序。它接受四个参数：
 *      待排序的数组指针、
 *      数组中元素的个数、
 *      每个元素的大小（以字节为单位）
 *      一个比较函数指针 - 比较函数指针用于指定两个元素之间的比较方式，以确定它们在排序后的相对位置
 *      该算法的时间复杂度为O(nlogn)。排序后，数组中的元素将按照比较函数指定的顺序排列。
 *
 * cmp函数返回负数表示第一个参数指向的元素应该排在第二个参数指向的元素之前，
 *      返回正数表示第一个参数指向的元素应该排在第二个参数指向的元素之后，
 *      返回0表示两个元素相等，它们的相对位置不变。
 * 因此，当cmp函数返回负数时，qsort函数会将第一个参数指向的元素排在第二个参数指向的元素之前，从而实现递增排序。
 * =================================================================================
 * @param {void} *a     数组1的值
 * @param {void} *b     数组2的值
 * @return {int}
 */
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

/**
 * @description: 两个数组的交集
 * 这段代码是一个C语言函数，名为intersection，它接受两个整型数组numsA和numsB，以及它们的大小numsASize和numsBSize。
 *
 * 函数的目的是找到这两个数组中的相同元素，并将它们存储在一个新的数组中。
 *
 * 函数使用快速排序算法对两个数组进行排序，然后使用三个索引i、j和k来遍历两个数组并找到相同的元素。
 * 最后，函数返回一个指向结果数组的指针，并将结果数组的大小存储在returnSize指针所指向的位置。
 * =================================================================================
 * @param {int} *numsA          数组1
 * @param {int} numsASize       数组1大小
 * @param {int} *numsB          数组2
 * @param {int} numsBSize       数组2大小
 * @param {int} *returnSize     返回数组大小
 * @return {int} *res           返回结果数组
 */
int *intersection(int *numsA, int numsASize, int *numsB, int numsBSize, int *returnSize) {
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


#endif /* DOUBLE_POINTER_METHOD_EN */