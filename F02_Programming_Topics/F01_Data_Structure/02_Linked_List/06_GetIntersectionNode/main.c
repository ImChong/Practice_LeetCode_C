/*
 * @FilePath     : \Practice_LeetCode_C\F02_Programming_Topics\F01_Data_Structure\02_Linked_List\06_GetIntersectionNode\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-02-05 11:36:42
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 面试题 02.07. 链表相交：https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/
 * https://programmercarl.com/%E9%9D%A2%E8%AF%95%E9%A2%9802.07.%E9%93%BE%E8%A1%A8%E7%9B%B8%E4%BA%A4.html
 */
/* Standard header file (标准头文件) */
#include <stdio.h>
/* solution header file (题解头文件) */
#include "F02_Programming_Topics/F01_Data_Structure/02_Linked_List/06_GetIntersectionNode/inc/get_intersection_node.h"
/* Common function header file (通用头文件) */
#include "F01_Common_Functions/inc/common_single_value.h"
#include "F01_Common_Functions/inc/common_array.h"
#include "F01_Common_Functions/inc/common_linked_list.h"

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
 * @description: Test 3
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