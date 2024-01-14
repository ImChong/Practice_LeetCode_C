/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\02_Linked_List\04_swapPairs\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-18 14:44:35
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 24. 两两交换链表中的节点：https://leetcode.cn/problems/swap-nodes-in-pairs/
 * https://programmercarl.com/0024.%E4%B8%A4%E4%B8%A4%E4%BA%A4%E6%8D%A2%E9%93%BE%E8%A1%A8%E4%B8%AD%E7%9A%84%E8%8A%82%E7%82%B9.html
 */
/* Standard header file (标准头文件) */
#include <stdio.h>
#include <stdlib.h>
/* Common function header file (通用头文件) */
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
 * @description: 两两交换链表中的节点
 * =================================================================================
 * @param {struct ListNode} *head       链表头结点
 * @return {struct ListNode} *head      交换后的链表头结点
 */
struct ListNode *swapPairs(struct ListNode* head){
    if (head == NULL || head->next == NULL) {       /* 递归终止条件 */
        return head;                                    /* 返回头结点 */
    }

    struct ListNode* newHead = head->next;          /* 交换后的头结点 */
    struct ListNode* prev = NULL;                   /* 前一节点指针 */

    while (head && head->next) {                    /* 循环条件：链表不为空 */
        struct ListNode *first = head;                  /* 第一个节点指针 */
        struct ListNode *second = head->next;           /* 第二个节点指针 */

        first->next = second->next;                     /* 改变链表指向：将第一个节点指针指向第三个节点 */
        second->next = first;                           /* 改变链表指向：将第二个节点指针指向第一个节点 */

        if (prev) {                                     /* 如果前一节点指针不为空 */
            prev->next = second;                            /* 改变链表指向：将前一节点指针指向第二个节点 */
        }
        prev = first;                                   /* 位移指针：将前一节点指针设置为第一个节点指针 */
        head = first->next;                             /* 位移指针：将头结点指针设置为第三个节点指针 */
    }
    return newHead;                                 /* 返回交换后的头结点 */
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
void Test1(void) {
    /* Function call (函数调用) */
    int arr[] = {1, 2, 3, 4};
    int arrSize = ARR_SIZE(arr);
    struct ListNode *arrList = LinkedList_ArrayInit(arr, arrSize);
    struct ListNode *ansList = swapPairs(arrList);

    /* Expect result (期望结果) */
    int expectArr[] = {2, 1, 4, 3};
    int expectSize = ARR_SIZE(expectArr);
    struct ListNode *expectList = LinkedList_ArrayInit(expectArr, expectSize);

    /* 比较结果 */
    Validate_LinkedList('1', expectList, ansList);

    /* 释放内存 */
    LinkedList_Free(arrList);
    LinkedList_Free(expectList);
}

/**
 * @description: 测试 2
 * =================================================================================
 * @return {void}
 */
void Test2(void) {
    /* Function call (函数调用) */
    int arr[] = {1, 2, 3, 4, 5};
    int arrSize = ARR_SIZE(arr);
    struct ListNode *arrList = LinkedList_ArrayInit(arr, arrSize);
    struct ListNode *ansList = swapPairs(arrList);

    /* Expect result (期望结果) */
    int expectArr[] = {2, 1, 4, 3, 5};
    int expectSize = ARR_SIZE(expectArr);
    struct ListNode *expectList = LinkedList_ArrayInit(expectArr, expectSize);

    /* 比较结果 */
    Validate_LinkedList('2', expectList, ansList);

    /* 释放内存 */
    LinkedList_Free(arrList);
    LinkedList_Free(expectList);
}

/**
 * @description: 测试 3
 * =================================================================================
 * @return {void}
 */
void Test3(void) {
    /* Function call (函数调用) */
    int arr[] = {1};
    int arrSize = ARR_SIZE(arr);
    struct ListNode *arrList = LinkedList_ArrayInit(arr, arrSize);
    struct ListNode *ansList = swapPairs(arrList);

    /* Expect result (期望结果) */
    int expectArr[] = {1};
    int expectSize = ARR_SIZE(expectArr);
    struct ListNode *expectList = LinkedList_ArrayInit(expectArr, expectSize);

    /* 比较结果 */
    Validate_LinkedList('3', expectList, ansList);

    /* 释放内存 */
    LinkedList_Free(arrList);
    LinkedList_Free(expectList);
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
    Test1();
    Test2();
    Test3();
    return 0;
}