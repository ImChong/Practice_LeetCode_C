/*
 * @FilePath     : \Practice_LeetCode_C\F02_Programming_Topics\F01_Data_Structure\02_Linked_List\04_swapPairs\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-02-02 20:00:56
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 24. 两两交换链表中的节点：https://leetcode.cn/problems/swap-nodes-in-pairs/
 * https://programmercarl.com/0024.%E4%B8%A4%E4%B8%A4%E4%BA%A4%E6%8D%A2%E9%93%BE%E8%A1%A8%E4%B8%AD%E7%9A%84%E8%8A%82%E7%82%B9.html
 */
/* Standard header file (标准头文件) */
#include <stdio.h>
/* solution header file (题解头文件) */
#include "F02_Programming_Topics/F01_Data_Structure/02_Linked_List/04_swapPairs/inc/swap_pairs.h"
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
    int arr[] = {1, 2, 3, 4};
    int arr_size = ARR_SIZE(arr);
    struct ListNode *arrList = LinkedList_ArrayInit(arr, arr_size);
    struct ListNode *ansList = SwapPairs(arrList);

    /* Expect result (期望结果) */
    int expectArr[] = {2, 1, 4, 3};
    int expectSize = ARR_SIZE(expectArr);
    struct ListNode *expectList = LinkedList_ArrayInit(expectArr, expectSize);

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
    int arr[] = {1, 2, 3, 4, 5};
    int arr_size = ARR_SIZE(arr);
    struct ListNode *arrList = LinkedList_ArrayInit(arr, arr_size);
    struct ListNode *ansList = SwapPairs(arrList);

    /* Expect result (期望结果) */
    int expectArr[] = {2, 1, 4, 3, 5};
    int expectSize = ARR_SIZE(expectArr);
    struct ListNode *expectList = LinkedList_ArrayInit(expectArr, expectSize);

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
    int arr[] = {1};
    int arr_size = ARR_SIZE(arr);
    struct ListNode *arrList = LinkedList_ArrayInit(arr, arr_size);
    struct ListNode *ansList = SwapPairs(arrList);

    /* Expect result (期望结果) */
    int expectArr[] = {1};
    int expectSize = ARR_SIZE(expectArr);
    struct ListNode *expectList = LinkedList_ArrayInit(expectArr, expectSize);

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