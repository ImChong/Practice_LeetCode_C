/*
 * @FilePath     : \Practice_LeetCode_C\F02_Programming_Topics\F01_Data_Structure\02_Linked_List\03_ReverseList\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-02-05 11:08:18
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 206. 反转链表：https://leetcode.cn/problems/reverse-linked-list/
 * https://programmercarl.com/0206.%E7%BF%BB%E8%BD%AC%E9%93%BE%E8%A1%A8.html
 */
/* Standard header file (标准头文件) */
#include <stdio.h>
#include <stdlib.h>
/* solution header file (题解头文件) */
#include "F02_Programming_Topics/F01_Data_Structure/02_Linked_List/03_reverseList/inc/reverse_list.h"
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
 * =================================================================================
 * @return {void}
 */
void Test1(void) {
    /* Function call (函数调用) */
    int arr[] = {1, 2, 3, 4, 5};
    int arr_size = ARR_SIZE(arr);
    struct ListNode *arrList = LinkedList_ArrayInit(arr, arr_size);
    struct ListNode *ansList = ReverseList(arrList);

    /* Expect result (期望结果) */
    int expect[] = {5, 4, 3, 2, 1};
    int expectSize = ARR_SIZE(expect);
    struct ListNode *expectList = LinkedList_ArrayInit(expect, expectSize);

    /* Validate result (验证函数调用结果) */
    Validate_LinkedList('1', expectList, ansList);

    /* Free memory (释放内存) */
    LinkedList_Free(arrList);
    LinkedList_Free(expectList);
}

/**
 * @description: Test 2
 * =================================================================================
 * @return {void}
 */
void Test2(void) {
    /* Function call (函数调用) */
    int arr[] = {1};
    int arr_size = ARR_SIZE(arr);
    struct ListNode *arrList = LinkedList_ArrayInit(arr, arr_size);
    struct ListNode *ansList = ReverseList(arrList);

    /* Expect result (期望结果) */
    int expect[] = {1};
    int expectSize = ARR_SIZE(expect);
    struct ListNode *expectList = LinkedList_ArrayInit(expect, expectSize);

    /* Validate result (验证函数调用结果) */
    Validate_LinkedList('2', expectList, ansList);

    /* Free memory (释放内存) */
    LinkedList_Free(arrList);
    LinkedList_Free(expectList);
}

/**
 * @description: Test 3
 * =================================================================================
 * @return {void}
 */
void Test3(void) {
    /* Function call (函数调用) */
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr_size = ARR_SIZE(arr);
    struct ListNode *arrList = LinkedList_ArrayInit(arr, arr_size);
    struct ListNode *ansList = ReverseList(arrList);

    /* Expect result (期望结果) */
    int expect[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int expectSize = ARR_SIZE(expect);
    struct ListNode *expectList = LinkedList_ArrayInit(expect, expectSize);

    /* Validate result (验证函数调用结果) */
    Validate_LinkedList('3', expectList, ansList);

    /* Free memory (释放内存) */
    LinkedList_Free(arrList);
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
int main(int argc, char const *argv[]) {
    Test1();
    Test2();
    Test3();
    return 0;
}
