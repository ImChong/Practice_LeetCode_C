/*
 * @FilePath     : \Practice_LeetCode_C\F02_Programming_Topics\F01_Data_Structure\02_Linked_List\07_DetectCycle\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-02-06 11:24:04
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 142. 环形链表 II：https://leetcode.cn/problems/linked-list-cycle-ii/
 * https://programmercarl.com/0142.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8II.html
 */
/* Standard header file (标准头文件) */
#include <stdio.h>
#include <stdlib.h>
/* solution header file (题解头文件) */
#include "F02_Programming_Topics/F01_Data_Structure/02_Linked_List/07_DetectCycle/inc/detect_cycle.h"
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
 * =================================================================================
 * @return {void}
 */
void Test1(void) {
    /* Function call (函数调用) */
    int arr[] = {3, 2, 0, -4};
    int arr_size = ARR_SIZE(arr);
    struct ListNode *arrList = LinkedList_ArrayInit(arr, arr_size);
    arrList->next->next->next->next = arrList->next;   /* 将尾节点指向指定节点 */
    int actual = DetectCycle(arrList)->val;

    /* Expect result (期望结果) */
    int expect = 2;

    /* Validate result (验证函数调用结果) */
    Validate_SingleValue('1', expect, actual);

    /* Free memory (释放内存) */
    /* 需要释放指定长度，否则会进入无限循环 */
}

/**
 * @description: Test 2
 * =================================================================================
 * @return {void}
 */
void Test2(void) {
    /* Function call (函数调用) */
    int arr[] = {1, 2};
    int arr_size = ARR_SIZE(arr);
    struct ListNode *arrList = LinkedList_ArrayInit(arr, arr_size);
    arrList->next->next = arrList;   /* 将尾节点指向指定节点 */
    int actual = DetectCycle(arrList)->val;

    /* Expect result (期望结果) */
    int expect = 1;

    /* Validate result (验证函数调用结果) */
    Validate_SingleValue('2', expect, actual);

    /* Free memory (释放内存) */
    /* 需要释放指定长度，否则会进入无限循环 */
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
    struct ListNode *actual = DetectCycle(arrList);

    /* Expect result (期望结果) */
    struct ListNode *expect = NULL;

    /* Validate result (验证函数调用结果) */
    Validate_LinkedList('3', expect, actual);

    /* Free memory (释放内存) */
    LinkedList_Free(arrList);
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
