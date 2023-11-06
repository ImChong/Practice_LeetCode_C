/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\02_Linked_List\01_removeElements\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-29 11:29:28
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 203. 移除链表元素：https://leetcode.cn/problems/remove-linked-list-elements/
 * https://programmercarl.com/0203.%E7%A7%BB%E9%99%A4%E9%93%BE%E8%A1%A8%E5%85%83%E7%B4%A0.html
 */
#include <stdio.h>
#include <stdlib.h>
#include "commonArray.h"        /* 00_Basics\01_Common_Func\inc\commonArray.h */
#include "commonLinkedList.h"   /* 00_Basics\01_Common_Func\inc\commonLinkedList.h */

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 移除链表元素
 * TODO: 运行时长和内存占用可提升
 * =================================================================================
 * @param {ListNode} *head              链表虚拟头节点
 * @param {int} val                     目标值
 * @return {struct ListNode} *head      返回链表虚拟头节点
 */
struct ListNode *removeElements(struct ListNode *head, int val) {
    struct ListNode dummy;                          /* 创建虚拟头节点 */
    dummy.next = head;                              /* 将传入链表接在虚拟头节点后面 */

    struct ListNode *curr = &dummy;                 /* 创建指针：用于遍历列表 */
    while (curr->next != NULL) {                    /* 遍历链表 */
        if (curr->next->val == val) {                   /* 当前节点的下一个节点的值等于目标值 */
            struct ListNode *tmp = curr->next;              /* 保存当前节点的下一个节点 */
            curr->next = curr->next->next;                  /* 当前节点的下一个节点指向下下个节点 */
            free(tmp);                                      /* 释放当前节点的下一个节点 */
        } else {                                        /* 当前节点的下一个节点的值不等于目标值 */
            curr = curr->next;                              /* 当前节点指向下一个节点 */
        }
    }
    return dummy.next;                              /* 返回链表虚拟头节点 */
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
    int nums[] = {1, 2, 6, 3, 4, 5, 6};
    int numsSize = ARR_SIZE(nums);
    struct ListNode *head = linkedListFromArray(nums, numsSize);
    int removeVal = 6;
    struct ListNode *ansList = removeElements(head, removeVal);

    /* 预期结果 */
    int expectNums[] = {1, 2, 3, 4, 5};
    int expectLen = ARR_SIZE(expectNums);
    struct ListNode *expectList = linkedListFromArray(expectNums, expectLen);

    /* 比较结果 */
    validateLinkedList('1', expectList, ansList);

    /* 释放内存 */
    freeList(head);
    freeList(expectList);
}

/**
 * @description: 测试 2
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    /* 实际结果 */
    int nums[] = {1, 1, 1, 1, 1};
    int numsSize = ARR_SIZE(nums);
    struct ListNode *head = linkedListFromArray(nums, numsSize);
    int removeVal = 1;
    struct ListNode *ansList = removeElements(head, removeVal);

    /* 预期结果 */
    int expectNums[] = {};
    int expectLen = ARR_SIZE(expectNums);
    struct ListNode *expectList = linkedListFromArray(expectNums, expectLen);

    /* 比较结果 */
    validateLinkedList('2', expectList, ansList);

    /* 释放内存 */
    // freeList(head);      /* head 内存已被 removeElements 释放，故无需再释放 */
    freeList(expectList);
}

/**
 * @description: 测试 3
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    /* 实际结果 */
    int nums[] = {1, 2, 3, 4, 5};
    int numsSize = ARR_SIZE(nums);
    struct ListNode *head = linkedListFromArray(nums, numsSize);
    int removeVal = 6;
    struct ListNode *ansList = removeElements(head, removeVal);

    /* 预期结果 */
    int expectNums[] = {1, 2, 3, 4, 5};
    int expectLen = ARR_SIZE(expectNums);
    struct ListNode *expectList = linkedListFromArray(expectNums, expectLen);

    /* 比较结果 */
    validateLinkedList('3', expectList, ansList);

    /* 释放内存 */
    freeList(head);
    freeList(expectList);
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
int main(int argc, const char* argv[]) {
    test_1();
    test_2();
    test_3();
    return 0;
}