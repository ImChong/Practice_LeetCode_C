/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\02_Linked_List\06_getIntersectionNode\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-18 14:42:24
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 面试题 02.07. 链表相交：https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/
 * https://programmercarl.com/%E9%9D%A2%E8%AF%95%E9%A2%9802.07.%E9%93%BE%E8%A1%A8%E7%9B%B8%E4%BA%A4.html
 */
/* Standard header file (标准头文件) */
#include <stdio.h>
#include <stdlib.h>
/* Common function header file (通用头文件) */
#include "commonSingleValue.h"
#include "commonArray.h"
#include "commonLinkedList.h"

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/*
    这段选中的代码实现了一个函数 getIntersectionNode，用于查找两个链表的交点。
    该函数接受两个链表 headA 和 headB 作为输入，如果存在交点，则返回交点，否则返回 NULL。

    该函数使用两个指针 pA 和 pB 分别指向链表 headA 和 headB 的头节点。
    然后，两个指针同时向后遍历链表，直到两个指针相遇，或者同时到达链表的末尾。如果两个指针相遇，则说明存在交点，返回交点；
    否则，返回 NULL。

    在遍历链表时，如果一个指针到达链表的末尾，则将其重定向到另一个链表的头节点，这样可以保证两个指针同时到达交点。
    这个过程可以通过两个指针的循环遍历来实现。

    该实现的时间复杂度为 O(m+n)，其中 m 和 n 分别是两个链表的长度。空间复杂度为 O(1)，因为只使用了两个指针来遍历链表。
    这个实现简单高效，易于理解。
*/
/* ============================================================================== */
/* ============================================================================== */
/**
 * @description: 获取两个链表的交点
 * =================================================================================
 * @param {ListNode} *headA     链表A头指针
 * @param {ListNode} *headB     链表B头指针
 * @return {*}
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *pA = headA;                /* 链表A指针 */
    struct ListNode *pB = headB;                /* 链表B指针 */
    while (pA != pB) {                          /* 循环条件：两个指针不相等 */
        pA = pA != NULL ? pA->next : headB;         /* 链表A指针后移 */
        pB = pB != NULL ? pB->next : headA;         /* 链表B指针后移 */
    }
    return pA;                                  /* 返回交点 */
}

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: Test 1
 * listA: 4 -> 1 -> 8 -> 4 -> 5
 * listB: 5 -> 0 -> 1 -> 8 -> 4 -> 5
 * expected: 8
 * =================================================================================
 * @return {void}
 */
void Test1(void) {
    /* Function call (函数调用) */
    int arrA[] = {4, 1, 8, 4, 5};
    int arrASize = ARR_SIZE(arrA);
    struct ListNode *listA = LinkedList_ArrayInit(arrA, arrASize);
    int arrB[] = {5, 0, 1};
    int arrBSize = ARR_SIZE(arrB);
    struct ListNode *listB = LinkedList_ArrayInit(arrB, arrBSize);
    /* 将链表B的尾结点指向链表A的第二个结点 */
    struct ListNode *current = listB;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = listA->next->next;

    struct ListNode *intersectNode = getIntersectionNode(listA, listB);

    /* Expect result (期望结果) */
    int expect = 8;

    /* Validate result (验证函数调用结果) */
    Validate_SingleValue('1', expect, intersectNode->val);

    /* 释放内存 - A/B链表相互链接，不可 while 循环释放 */
    // LinkedList_Free(listA);
    // LinkedList_Free(listB);
}

/**
 * @description: Test 2
 * listA: 0 -> 9 -> 1 -> 2 -> 4
 * listB: 3 -> 2 -> 4
 * expected: 2
 * =================================================================================
 * @return {void}
 */
void Test2(void) {
    /* Function call (函数调用) */
    int arrA[] = {0, 9, 1, 2, 4};
    int arrASize = ARR_SIZE(arrA);
    struct ListNode *listA = LinkedList_ArrayInit(arrA, arrASize);
    int arrB[] = {3, 2, 4};
    int arrBSize = ARR_SIZE(arrB);
    struct ListNode *listB = LinkedList_ArrayInit(arrB, arrBSize);
    /* 将链表B的尾结点指向链表A的第四个结点 */
    struct ListNode *current = listB;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = listA->next->next->next;

    struct ListNode *intersectNode = getIntersectionNode(listA, listB);

    /* Expect result (期望结果) */
    int expect = 2;

    /* Validate result (验证函数调用结果) */
    Validate_SingleValue('2', expect, intersectNode->val);

    /* 释放内存 - A/B链表相互链接，不可 while 循环释放 */
}

/**
 * @description: 测试 3
 * listA: 2 -> 6 -> 4
 * listB: 1 -> 5
 * expected: NULL
 * =================================================================================
 * @return {void}
 */
void Test3(void) {
    /* Function call (函数调用) */
    int arrA[] = {2, 6, 4};
    int arrASize = ARR_SIZE(arrA);
    struct ListNode *listA = LinkedList_ArrayInit(arrA, arrASize);
    int arrB[] = {1, 5};
    int arrBSize = ARR_SIZE(arrB);
    struct ListNode *listB = LinkedList_ArrayInit(arrB, arrBSize);

    struct ListNode *intersectNode = getIntersectionNode(listA, listB);

    /* Expect result (期望结果) */
    struct ListNode *expect = NULL;

    /* Validate result (验证函数调用结果) */
    Validate_LinkedList('3', expect, intersectNode);

    /* Free memory (释放内存) */
    LinkedList_Free(listA);
    LinkedList_Free(listB);
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
    Test1();
    Test2();
    Test3();
    return 0;
}