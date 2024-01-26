/*
 * @FilePath     : \Practice_LeetCode_C\F02_Programming_Topics\F01_Data_Structure\02_Linked_List\00_common\01_dummyMethod\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-23 00:19:21
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 707. 设计链表：https://leetcode.cn/problems/design-linked-list/
 * https://programmercarl.com/0707.%E8%AE%BE%E8%AE%A1%E9%93%BE%E8%A1%A8.html
 */
/* solution header file (题解头文件) */
#include "F01_Common_Functions/inc/common_linked_list_dummy.h"
/* Standard header file (标准头文件) */
#include <stdio.h>
#include <stdlib.h>
/* Common function header file (通用头文件) */
#include "F01_Common_Functions/inc/common_def/common_type_def.h"
#include "commonArray.h"

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: Test 1
 * Input: DummyLinkedList = [1, 2, 3], DeleteAtIndex = 0
 * Output: [2, 3]
 * =================================================================================
 * @return {void}
 */
void Test1(void) {
    /* Function call (函数调用) */
    DummyLinkedList *actualDummy = DLinkedList_Init();
    DLinkedList_AddAtHead(actualDummy, 1);
    DLinkedList_AddAtTail(actualDummy, 3);
    DLinkedList_AddAtIndex(actualDummy, 1, 2);
    DLinkedList_DeleteAtIndex(actualDummy, 0);

    /* Expect result (期望结果) */
    DummyLinkedList *expectDummy = DLinkedList_Init();
    int nums[] = {2, 3};
    DLinkedList_ArrayInit(expectDummy, nums, ARR_SIZE(nums));

    /* Validate result (验证函数调用结果) */
    Validate_DLinkedList('1', expectDummy, actualDummy);

    /* Free memory (释放内存空间) */
    DLinkedList_Free(actualDummy);
}

/**
 * @description: Test 2
 * Input: DummyLinkedList = [1], DeleteAtIndex = 0
 * Output: []
 * =================================================================================
 * @return {void}
 */
void Test2(void) {
    /* Function call (函数调用) */
    DummyLinkedList *actualDummy = DLinkedList_Init();
    DLinkedList_AddAtHead(actualDummy, 1);
    DLinkedList_DeleteAtIndex(actualDummy, 0);

    /* Expect result (期望结果) */
    DummyLinkedList *expectDummy = DLinkedList_Init();

    /* Validate result (验证函数调用结果) */
    Validate_DLinkedList('2', expectDummy, actualDummy);

    /* Free memory (释放内存空间) */
    DLinkedList_Free(actualDummy);
}

/**
 * @description: Test 3
 * Input: DummyLinkedList = [1, 2, 1, 2, 1, 2], DeleteValue = 2
 * Output: [1, 1, 1]
 * =================================================================================
 * @return {void}
 */
void Test3(void) {
    /* Function call (函数调用) */
    DummyLinkedList *actualDummy = DLinkedList_Init();
    DLinkedList_AddAtTail(actualDummy, 1);
    DLinkedList_AddAtTail(actualDummy, 2);
    DLinkedList_AddAtTail(actualDummy, 1);
    DLinkedList_AddAtTail(actualDummy, 2);
    DLinkedList_AddAtTail(actualDummy, 1);
    DLinkedList_AddAtTail(actualDummy, 2);
    DLinkedList_DeleteValue(actualDummy, 2);

    /* Expect result (期望结果) */
    DummyLinkedList *expectDummy = DLinkedList_Init();
    int nums[] = {1, 1, 1};
    DLinkedList_ArrayInit(expectDummy, nums, ARR_SIZE(nums));

    /* Validate result (验证函数调用结果) */
    Validate_DLinkedList('3', expectDummy, actualDummy);

    /* Free memory (释放内存空间) */
    DLinkedList_Free(actualDummy);
}

/**
 * @description: Test 4
 * Input: DummyLinkedList = [1, 2, 1, 2, 1, 2], GetValueIndexes = 2
 * Output: [1, 3, 5]
 * =================================================================================
 * @return {void}
 */
void Test4(void) {
    /* Function call (函数调用) */
    DummyLinkedList *actualDummy = DLinkedList_Init();
    DLinkedList_AddAtTail(actualDummy, 1);
    DLinkedList_AddAtTail(actualDummy, 2);
    DLinkedList_AddAtTail(actualDummy, 1);
    DLinkedList_AddAtTail(actualDummy, 2);
    DLinkedList_AddAtTail(actualDummy, 1);
    DLinkedList_AddAtTail(actualDummy, 2);
    int actualReturnSize = 0;
    int *actualIndexes = DLinkedList_GetValueIndexes(actualDummy, 2, &actualReturnSize);

    /* Expect result (期望结果) */
    int expectIndexes[] = {1, 3, 5};

    /* Validate result (验证函数调用结果) */
    Validate_Array('4', expectIndexes, ARR_SIZE(expectIndexes), actualIndexes, actualReturnSize, COMMON_FALSE);

    /* Free memory (释放内存空间) */
    DLinkedList_Free(actualDummy);
    free(actualIndexes);
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
    Test4();
    return 0;
}