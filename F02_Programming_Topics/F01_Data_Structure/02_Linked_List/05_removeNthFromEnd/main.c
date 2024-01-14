/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\02_Linked_List\05_removeNthFromEnd\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-18 14:40:37
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 19. 删除链表的倒数第 N 个结点：https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
 * https://programmercarl.com/0019.%E5%88%A0%E9%99%A4%E9%93%BE%E8%A1%A8%E7%9A%84%E5%80%92%E6%95%B0%E7%AC%ACN%E4%B8%AA%E8%8A%82%E7%82%B9.html
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
 * @description: 删除链表的倒数第 N 个结点
 * =================================================================================
 * @param {struct ListNode*} head       链表头节点
 * @param {int} n                       倒数第 n 个节点
 * @return {struct ListNode} *head      返回链表头节点
 */
struct ListNode *removeNthFromEnd(struct ListNode* head, int n){
    if (!head || n <= 0) {                      /* 如果头节点不存在 或 n <= 0 时 */
        return head;                                /* 返回头节点 */
    }

    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));     /* 初始化虚拟头节点 */
    dummy->val = 0;                             /* 虚拟头节点值为0 */
    dummy->next = head;                         /* 虚拟头节点的下一节点指向链表头节点 */

    struct ListNode *first = dummy;             /* 设置第一指针指向虚拟头节点的位置 */
    struct ListNode *second = dummy;            /* 设置第二指针指向虚拟头节点的位置 */

    for (int i = 0; i <= n; i++) {              /* 循环 n + 1 次：需要末尾 NULL 作为循环结束条件，故 n + 1 */
        if (first != NULL) {                        /* 如果第一指针没有指向 NULL */
            first = first->next;                        /* 将第一指针向后移动一个位置 */
        } else {                                    /* 循环过程中第一指针指向了 NULL */
            return head;                                /* 则返回头节点，代表出界 */
        }
    }

    while (first != NULL) {                     /* 当第一指针未指向 NULL 时循环 */
        first = first->next;                        /* 第一指针向后移动一个位置 */
        second = second->next;                      /* 第二指针向后移动一个位置，直到第二指针指向待删除节点的前一节点 */
    }

    struct ListNode *tmp = second->next;        /* 用一个临时指针储存第二指针所指的下一节点：待删除节点 */
    second->next = second->next->next;          /* 将第二指针的下一节点指向下下节点 */
    free(tmp);                                  /* 删除指定节点 */

    struct ListNode *newHead = dummy->next;     /* 设置链表头节点为虚拟头节点的下一节点 */
    free(dummy);                                /* 删除虚拟头节点 */
    return newHead;                             /* 返回链表头节点 */
}

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 测试 1
 * {1, 2, 3, 4, 5}
 * n = 2
 * =================================================================================
 * @return {void}
 */
void Test1(void) {
    /* Function call (函数调用) */
    int arr[] = {1, 2, 3, 4, 5};
    int arrSize = ARR_SIZE(arr);
    struct ListNode *newList = LinkedList_ArrayInit(arr, arrSize);
    int n = 2;
    struct ListNode *ansList = removeNthFromEnd(newList, n);

    /* 预期结果 */
    /* {1, 2, 3, 5} */
    int expectArr[] = {1, 2, 3, 5};
    int expectArrSize = ARR_SIZE(expectArr);
    struct ListNode *expectList = LinkedList_ArrayInit(expectArr, expectArrSize);

    /* 比较结果 */
    Validate_LinkedList('1', expectList, ansList);

    /* 释放内存 */
    LinkedList_Free(newList);
    LinkedList_Free(expectList);
}

/**
 * @description: 测试 2
 * {1, 2, 3, 4, 5}
 * n = 7
 * =================================================================================
 * @return {void}
 */
void Test2(void) {
    /* Function call (函数调用) */
    int arr[] = {1, 2, 3, 4, 5};
    int arrSize = ARR_SIZE(arr);
    struct ListNode *newList = LinkedList_ArrayInit(arr, arrSize);
    int n = 7;
    struct ListNode *ansList = removeNthFromEnd(newList, n);

    /* 预期结果 */
    /* {1, 2, 3, 4, 5} */
    int expectArr[] = {1, 2, 3, 4, 5};
    int expectArrSize = ARR_SIZE(expectArr);
    struct ListNode *expectList = LinkedList_ArrayInit(expectArr, expectArrSize);

    /* 比较结果 */
    Validate_LinkedList('2', expectList, ansList);

    /* 释放内存 */
    LinkedList_Free(newList);
    LinkedList_Free(expectList);
}

/**
 * @description: 测试 3
 * {1}
 * n = 1
 * =================================================================================
 * @return {void}
 */
void Test3(void) {
    /* Function call (函数调用) */
    int arr[] = {1};
    int arrSize = ARR_SIZE(arr);
    struct ListNode *newList = LinkedList_ArrayInit(arr, arrSize);
    int n = 1;
    struct ListNode *ansList = removeNthFromEnd(newList, n);

    /* 预期结果 */
    /* {} */
    int expectArr[] = {};
    int expectArrSize = ARR_SIZE(expectArr);
    struct ListNode *expectList = LinkedList_ArrayInit(expectArr, expectArrSize);

    /* 比较结果 */
    Validate_LinkedList('3', expectList, ansList);

    /* 释放内存 */
    /* 内存已清除，无需再释放内存 */
}

/**
 * @description: 测试 4
 * {1, 2, 3, 4, 5}
 * n = 5
 * =================================================================================
 * @return {void}
 */
void Test4(void) {
    /* Function call (函数调用) */
    int arr[] = {1, 2, 3, 4, 5};
    int arrSize = ARR_SIZE(arr);
    struct ListNode *newList = LinkedList_ArrayInit(arr, arrSize);
    int n = 5;
    struct ListNode *ansList = removeNthFromEnd(newList, n);

    /* 预期结果 */
    /* {2, 3, 4, 5} */
    int expectArr[] = {2, 3, 4, 5};
    int expectArrSize = ARR_SIZE(expectArr);
    struct ListNode *expectList = LinkedList_ArrayInit(expectArr, expectArrSize);

    /* 比较结果 */
    Validate_LinkedList('4', expectList, ansList);

    /* 释放内存 */
    LinkedList_Free(ansList);        /* newList 的链表头已被释放内存 */
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
    Test4();
    return 0;
}