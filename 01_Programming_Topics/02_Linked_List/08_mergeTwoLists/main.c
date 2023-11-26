/*
 * @FilePath     : \Practice_LeetCode_C\01_Programming_Topics\02_Linked_List\08_mergeTwoLists\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-18 23:18:36
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-26 11:42:53
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
    struct ListNode *t = head;

    while (list1 && list2) {
        if (list1->val < list2->val) {
            t->next = list1;
            list1 = list1->next;
        } else {
            t->next = list2;
            list2 = list2->next;
        }
        t = t->next;
    }

    if (list1) {
        t->next = list1;
    } else {
        t->next = list2;
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
 * =================================================================================
 * @return {void}
 */
void test_1(void) {
    /* 实际结果 */

    /* 预期结果 */

    /* 比较结果 */

}

/**
 * @description: 测试 2
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    /* 实际结果 */

    /* 预期结果 */

    /* 比较结果 */

}

/**
 * @description: 测试 3
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
    /* Test case 1 */
    struct ListNode *l1 = NULL;
    struct ListNode *l2 = NULL;

    struct ListNode *merged = mergeTwoLists(l1, l2);

    /* Print merged list */
    while (merged != NULL) {
        printf("%d ", merged->val);
        merged = merged->next;
    }

    printf("\n");

    /* Test case 2 */
    l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->val = 1;
    l1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->next->val = 2;
    l1->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->next->next->val = 4;
    l1->next->next->next = NULL;

    l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->val = 1;
    l2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->next->val = 3;
    l2->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->next->next->val = 4;
    l2->next->next->next = NULL;

    merged = mergeTwoLists(l1, l2);

    /* Print merged list */
    while (merged != NULL) {
        printf("%d ", merged->val);
        merged = merged->next;
    }

    printf("\n");

    return 0;
}