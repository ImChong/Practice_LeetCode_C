/*
 * @FilePath     : \Practice_LeetCode_C\F02_Programming_Topics\F01_Data_Structure\02_Linked_List\05_RemoveNthFromEnd\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-02-05 11:22:01
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 19. 删除链表的倒数第 N 个结点：https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
 * https://programmercarl.com/0019.%E5%88%A0%E9%99%A4%E9%93%BE%E8%A1%A8%E7%9A%84%E5%80%92%E6%95%B0%E7%AC%ACN%E4%B8%AA%E8%8A%82%E7%82%B9.html
 */
/* Standard header file (标准头文件) */
#include <stdio.h>
/* solution header file (题解头文件) */
#include "F02_Programming_Topics/F01_Data_Structure/02_Linked_List/05_RemoveNthFromEnd/inc/remove_nth_from_end.h"
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
 * {1, 2, 3, 4, 5}
 * n = 2
 * =================================================================================
 * @return {void}
 */
void Test1(void) {
    /* Function call (函数调用) */
    int arr[] = {1, 2, 3, 4, 5};
    int arr_size = ARR_SIZE(arr);
    struct ListNode *newList = LinkedList_ArrayInit(arr, arr_size);
    int n = 2;
    struct ListNode *ansList = RemoveNthFromEnd(newList, n);

    /* Expect result (期望结果) */
    /* {1, 2, 3, 5} */
    int expectArr[] = {1, 2, 3, 5};
    int expectArrSize = ARR_SIZE(expectArr);
    struct ListNode *expectList = LinkedList_ArrayInit(expectArr, expectArrSize);

    /* Validate result (验证函数调用结果) */
    Validate_LinkedList('1', expectList, ansList);

    /* Free memory (释放内存) */
    LinkedList_Free(newList);
    LinkedList_Free(expectList);
}

/**
 * @description: Test 2
 * {1, 2, 3, 4, 5}
 * n = 7
 * =================================================================================
 * @return {void}
 */
void Test2(void) {
    /* Function call (函数调用) */
    int arr[] = {1, 2, 3, 4, 5};
    int arr_size = ARR_SIZE(arr);
    struct ListNode *newList = LinkedList_ArrayInit(arr, arr_size);
    int n = 7;
    struct ListNode *ansList = RemoveNthFromEnd(newList, n);

    /* Expect result (期望结果) */
    /* {1, 2, 3, 4, 5} */
    int expectArr[] = {1, 2, 3, 4, 5};
    int expectArrSize = ARR_SIZE(expectArr);
    struct ListNode *expectList = LinkedList_ArrayInit(expectArr, expectArrSize);

    /* Validate result (验证函数调用结果) */
    Validate_LinkedList('2', expectList, ansList);

    /* Free memory (释放内存) */
    LinkedList_Free(newList);
    LinkedList_Free(expectList);
}

/**
 * @description: Test 3
 * {1}
 * n = 1
 * =================================================================================
 * @return {void}
 */
void Test3(void) {
    /* Function call (函数调用) */
    int arr[] = {1};
    int arr_size = ARR_SIZE(arr);
    struct ListNode *newList = LinkedList_ArrayInit(arr, arr_size);
    int n = 1;
    struct ListNode *ansList = RemoveNthFromEnd(newList, n);

    /* Expect result (期望结果) */
    /* {} */
    int expectArr[] = {};
    int expectArrSize = ARR_SIZE(expectArr);
    struct ListNode *expectList = LinkedList_ArrayInit(expectArr, expectArrSize);

    /* Validate result (验证函数调用结果) */
    Validate_LinkedList('3', expectList, ansList);

    /* Free memory (释放内存) */
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
    int arr_size = ARR_SIZE(arr);
    struct ListNode *newList = LinkedList_ArrayInit(arr, arr_size);
    int n = 5;
    struct ListNode *ansList = RemoveNthFromEnd(newList, n);

    /* Expect result (期望结果) */
    /* {2, 3, 4, 5} */
    int expectArr[] = {2, 3, 4, 5};
    int expectArrSize = ARR_SIZE(expectArr);
    struct ListNode *expectList = LinkedList_ArrayInit(expectArr, expectArrSize);

    /* Validate result (验证函数调用结果) */
    Validate_LinkedList('4', expectList, ansList);

    /* Free memory (释放内存) */
    LinkedList_Free(ansList);        /* newList 的链表头已被释放内存 */
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
    Test4();
    return 0;
}