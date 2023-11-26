/*
 * @FilePath     : \Practice_LeetCode_C\01_Programming_Topics\02_Linked_List\08_mergeTwoLists\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-18 23:18:36
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-26 12:06:04
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 21. 合并两个有序链表: https://leetcode.cn/problems/merge-two-sorted-lists/
 * https://leetcode.cn/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/
 * https://labuladong.github.io/algo/di-ling-zh-bfe1b/shuang-zhi-0f7cc/
 */

/* TODO: 重构 */

/* 标准头文件 */
#include <stdio.h>
#include <stdlib.h>
/* 通用头文件 */
#include "commonArray.h"
#include "commonLinkedList.h"

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 合并两个有序链表
 * =================================================================================
 * @param {ListNode} *list1     链表1
 * @param {ListNode} *list2     链表2
 * @return {ListNode} *head     合并后的链表头节点
 */
struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2) {
    if (!list1) {
        return list2;
    }
    if (!list2) {
        return list1;
    }

    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *currNode = head;

    while (list1 && list2) {
        if (list1->val < list2->val) {
            currNode->next = list1;
            list1 = list1->next;
        } else {
            currNode->next = list2;
            list2 = list2->next;
        }
        currNode = currNode->next;
    }

    if (list1) {
        currNode->next = list1;
    } else {
        currNode->next = list2;
    }
    return head->next;
}

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 测试 1
 * 输入：l1 = [], l2 = []
 * 输出：[]
 * =================================================================================
 * @return {void}
 */
void test_1(void) {
    /* 实际结果 */
    printf("input: \n");
    struct ListNode *l1 = NULL;
    printf("\t"); linkedListPrint(l1);
    struct ListNode *l2 = NULL;
    printf("\t"); linkedListPrint(l2);
    struct ListNode *actual = mergeTwoLists(l1, l2);

    /* 预期结果 */
    struct ListNode *expect = NULL;

    /* 比较结果 */
    validateLinkedList('1', expect, actual);

    /* 释放内存 */
    linkedListFree(expect);
}

/**
 * @description: 测试 2
 * 输入：l1 = [1,2,4], l2 = [1,3,4]
 * 输出：[1,1,2,3,4,4]
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    /* 实际结果 */
    printf("input: \n");
    int array1[] = {1, 2, 4};
    struct ListNode *l1 = linkedListFromArray(array1, ARR_SIZE(array1));
    printf("\t"); linkedListPrint(l1);
    int array2[] = {1, 3, 4};
    struct ListNode *l2 = linkedListFromArray(array2, ARR_SIZE(array2));
    printf("\t"); linkedListPrint(l2);
    struct ListNode *actual = mergeTwoLists(l1, l2);

    /* 预期结果 */
    int array3[] = {1, 1, 2, 3, 4, 4};
    struct ListNode *expect = linkedListFromArray(array3, ARR_SIZE(array3));

    /* 比较结果 */
    validateLinkedList('2', expect, actual);

    /* 释放内存 */
    linkedListFree(expect);
}

/**
 * @description: 测试 3
 * 输入：l1 = [], l2 = [0]
 * 输出：[0]
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    /* 实际结果 */

    /* 预期结果 */

    /* 比较结果 */

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
    return 0;
}