/*
 * @FilePath     : \Practice_LeetCode_C\F02_Programming_Topics\F01_Data_Structure\02_Linked_List\09_MergeTwoLists\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-18 23:18:36
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-02-08 21:54:15
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 21. 合并两个有序链表: https://leetcode.cn/problems/merge-two-sorted-lists/
 * https://leetcode.cn/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/
 * https://labuladong.github.io/algo/di-ling-zh-bfe1b/shuang-zhi-0f7cc/
 */
/* Standard header file (标准头文件) */
#include <stdio.h>
#include <stdlib.h>
/* solution header file (题解头文件) */
#include "F02_Programming_Topics/F01_Data_Structure/02_Linked_List/09_MergeTwoLists/inc/merge_two_lists.h"
/* Common function header file (通用头文件) */
#include "F01_Common_Functions/inc/common_array.h"
#include "F01_Common_Functions/inc/common_linked_list.h"

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: Test 1
 * 输入：l1 = [], l2 = []
 * 输出：[]
 * =================================================================================
 * @return {void}
 */
void Test1(void) {
    /* Function call (函数调用) */
    printf("input: \n");
    struct ListNode *l1 = NULL;
    printf("\t"); LinkedList_Print(l1);
    struct ListNode *l2 = NULL;
    printf("\t"); LinkedList_Print(l2);
    struct ListNode *actual = MergeTwoLists(l1, l2);

    /* Expect result (期望结果) */
    struct ListNode *expect = NULL;

    /* Validate result (验证函数调用结果) */
    Validate_LinkedList('1', expect, actual);

    /* Free memory (释放内存) */
    LinkedList_Free(expect);
}

/**
 * @description: Test 2
 * 输入：l1 = [1,2,4], l2 = [1,3,4]
 * 输出：[1,1,2,3,4,4]
 * =================================================================================
 * @return {void}
 */
void Test2(void) {
    /* Function call (函数调用) */
    printf("input: \n");
    int array1[] = {1, 2, 4};
    struct ListNode *l1 = LinkedList_ArrayInit(array1, ARR_SIZE(array1));
    printf("\t"); LinkedList_Print(l1);
    int array2[] = {1, 3, 4};
    struct ListNode *l2 = LinkedList_ArrayInit(array2, ARR_SIZE(array2));
    printf("\t"); LinkedList_Print(l2);
    struct ListNode *actual = MergeTwoLists(l1, l2);

    /* Expect result (期望结果) */
    int array3[] = {1, 1, 2, 3, 4, 4};
    struct ListNode *expect = LinkedList_ArrayInit(array3, ARR_SIZE(array3));

    /* Validate result (验证函数调用结果) */
    Validate_LinkedList('2', expect, actual);

    /* Free memory (释放内存) */
    LinkedList_Free(expect);
}

/**
 * @description: Test 3
 * 输入：l1 = [], l2 = [0]
 * 输出：[0]
 * =================================================================================
 * @return {void}
 */
void Test3(void) {
    /* Function call (函数调用) */
    printf("input: \n");
    int array1[] = {};
    struct ListNode *l1 = LinkedList_ArrayInit(array1, ARR_SIZE(array1));
    printf("\t"); LinkedList_Print(l1);
    int array2[] = {0};
    struct ListNode *l2 = LinkedList_ArrayInit(array2, ARR_SIZE(array2));
    printf("\t"); LinkedList_Print(l2);
    struct ListNode *actual = MergeTwoLists(l1, l2);

    /* Expect result (期望结果) */
    int array3[] = {0};
    struct ListNode *expect = LinkedList_ArrayInit(array3, ARR_SIZE(array3));

    /* Validate result (验证函数调用结果) */
    Validate_LinkedList('3', expect, actual);

    /* Free memory (释放内存) */
    LinkedList_Free(expect);
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
    return 0;
}