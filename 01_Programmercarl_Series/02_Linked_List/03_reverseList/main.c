/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\02_Linked_List\03_reverseList\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-22 13:16:38
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 206. 反转链表：https://leetcode.cn/problems/reverse-linked-list/
 * https://programmercarl.com/0206.%E7%BF%BB%E8%BD%AC%E9%93%BE%E8%A1%A8.html
 */
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
 * @description: 反转链表
 * =================================================================================
 * @param {ListNode*} head
 * @return {struct ListNode} *prev
 */
struct ListNode *reverseList(struct ListNode* head){
    struct ListNode *prev = NULL;   /* 初始化前一节点指针为NULL */
    struct ListNode *curr = head;   /* 初始化现节点指针头结点 */
    struct ListNode *next = NULL;   /* 初始化下一节点指针为NULL */

    while (curr != NULL) {          /* 如果当前指针指向的节点不为 NULL */
        next = curr->next;              /* 位移指针：配置下一节点*/
        curr->next = prev;              /* 改变链表指向：将现节点的下一节点指针指向前一节点 */
        prev = curr;                    /* 位移指针：将现节点指针设置为前节点指针*/
        curr = next;                    /* 位移指针：将下一节点指针设置为现节点指针 */
    }
    return prev;                    /* 返回前一节点指针 */
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
    int arr[] = {1, 2, 3, 4, 5};
    int arrSize = ARR_SIZE(arr);
    struct ListNode *arrList = linkedListFromArray(arr, arrSize);
    struct ListNode *ansList = reverseList(arrList);

    /* 预期结果 */
    int expect[] = {5, 4, 3, 2, 1};
    int expectSize = ARR_SIZE(expect);
    struct ListNode *expectList = linkedListFromArray(expect, expectSize);

    /* 比较结果 */
    validateLinkedList('1', expectList, ansList);

    /* 释放内存 */
    freeList(arrList);
    freeList(expectList);
}

/**
 * @description: 测试 2
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    /* 实际结果 */
    int arr[] = {1};
    int arrSize = ARR_SIZE(arr);
    struct ListNode *arrList = linkedListFromArray(arr, arrSize);
    struct ListNode *ansList = reverseList(arrList);

    /* 预期结果 */
    int expect[] = {1};
    int expectSize = ARR_SIZE(expect);
    struct ListNode *expectList = linkedListFromArray(expect, expectSize);

    /* 比较结果 */
    validateLinkedList('2', expectList, ansList);

    /* 释放内存 */
    freeList(arrList);
    freeList(expectList);
}

/**
 * @description: 测试 3
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    /* 实际结果 */
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arrSize = ARR_SIZE(arr);
    struct ListNode *arrList = linkedListFromArray(arr, arrSize);
    struct ListNode *ansList = reverseList(arrList);

    /* 预期结果 */
    int expect[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int expectSize = ARR_SIZE(expect);
    struct ListNode *expectList = linkedListFromArray(expect, expectSize);

    /* 比较结果 */
    validateLinkedList('3', expectList, ansList);

    /* 释放内存 */
    freeList(arrList);
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
int main(int argc, char const *argv[]) {
    test_1();
    test_2();
    test_3();
    return 0;
}