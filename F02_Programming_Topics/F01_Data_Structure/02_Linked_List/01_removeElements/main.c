/*
 * @FilePath     : \Practice_LeetCode_C\F02_Programming_Topics\F01_Data_Structure\02_Linked_List\01_removeElements\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-23 09:24:58
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 203. 移除链表元素：https://leetcode.cn/problems/remove-linked-list-elements/
 * https://programmercarl.com/0203.%E7%A7%BB%E9%99%A4%E9%93%BE%E8%A1%A8%E5%85%83%E7%B4%A0.html
 */
/* solution header file (题解头文件) */
#include "removeElements.h"
/* Standard header file (标准头文件) */
#include <stdio.h>
/* Common function header file (通用头文件) */
#include "commonArray.h"
#include "commonLinkedList.h"

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: Test 1
 * Input: LinkedList = [1, 2, 6, 3, 4, 5, 6], RemoveValue = 6
 * Output: [1, 2, 3, 4, 5]
 * =================================================================================
 * @return {void}
 */
void Test1(void) {
    /* Function call (函数调用) */
    int nums[] = {1, 2, 6, 3, 4, 5, 6};
    int numsSize = ARR_SIZE(nums);
    struct ListNode *head = LinkedList_ArrayInit(nums, numsSize);
    int removeValue = 6;
    struct ListNode *ansList = removeElements(head, removeValue);

    /* Expect result (期望结果) */
    int expectNums[] = {1, 2, 3, 4, 5};
    int expectLen = ARR_SIZE(expectNums);
    struct ListNode *expectList = LinkedList_ArrayInit(expectNums, expectLen);

    /* Validate result (验证函数调用结果) */
    Validate_LinkedList('1', expectList, ansList);

    /* Free memory (释放内存) */
    LinkedList_Free(head);
    LinkedList_Free(expectList);
}

/**
 * @description: Test 2
 * Input: LinkedList = [1, 1, 1, 1, 1], RemoveValue = 1
 * Output: []
 * =================================================================================
 * @return {void}
 */
void Test2(void) {
    /* Function call (函数调用) */
    int nums[] = {1, 1, 1, 1, 1};
    int numsSize = ARR_SIZE(nums);
    struct ListNode *head = LinkedList_ArrayInit(nums, numsSize);
    int removeValue = 1;
    struct ListNode *ansList = removeElements(head, removeValue);

    /* Expect result (期望结果) */
    int expectNums[] = {};
    int expectLen = ARR_SIZE(expectNums);
    struct ListNode *expectList = LinkedList_ArrayInit(expectNums, expectLen);

    /* Validate result (验证函数调用结果) */
    Validate_LinkedList('2', expectList, ansList);

    /* Free memory (释放内存) */
    // LinkedList_Free(head);      /* head 内存已被 removeElements 释放，故无需再释放 */
    LinkedList_Free(expectList);
}

/**
 * @description: Test 3
 * Input: LinkedList = [1, 2, 3, 4, 5], RemoveValue = 6
 * Output: [1, 2, 3, 4, 5]
 * =================================================================================
 * @return {void}
 */
void Test3(void) {
    /* Function call (函数调用) */
    int nums[] = {1, 2, 3, 4, 5};
    int numsSize = ARR_SIZE(nums);
    struct ListNode *head = LinkedList_ArrayInit(nums, numsSize);
    int removeValue = 6;
    struct ListNode *ansList = removeElements(head, removeValue);

    /* Expect result (期望结果) */
    int expectNums[] = {1, 2, 3, 4, 5};
    int expectLen = ARR_SIZE(expectNums);
    struct ListNode *expectList = LinkedList_ArrayInit(expectNums, expectLen);

    /* Validate result (验证函数调用结果) */
    Validate_LinkedList('3', expectList, ansList);

    /* Free memory (释放内存) */
    LinkedList_Free(head);
    LinkedList_Free(expectList);
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
int main(int argc, const char* argv[]) {
    Test1();
    Test2();
    Test3();
    return 0;
}
