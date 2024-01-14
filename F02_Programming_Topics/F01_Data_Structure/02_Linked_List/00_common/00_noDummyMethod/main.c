/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\02_Linked_List\00_common\00_noDummyMethod\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 10:09:09
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-18 14:31:28
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 运行链表公共函数 - 未使用虚拟头节点
 */
/* Standard header file (标准头文件) */
#include <stdio.h>
/* Common function header file (通用头文件) */
#include "commonTypeDef.h"
#include "commonArray.h"
#include "commonLinkedList.h"

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
    struct ListNode *actualList = NULL;
    actualList = LinkedList_AddAtTail(actualList, 1);
    actualList = LinkedList_AddAtTail(actualList, 2);
    actualList = LinkedList_AddAtTail(actualList, 3);
    actualList = LinkedList_DeleteAtIndex(actualList, 0);

    /* Expect result (期望结果) */
    int nums[] = {2, 3};
    struct ListNode *expectList = LinkedList_ArrayInit(nums, ARR_SIZE(nums));

    /* Validate result (验证函数调用结果) */
    Validate_LinkedList('1', expectList, actualList);

    /* 释放内存空间 */
    LinkedList_Free(actualList);
    LinkedList_Free(expectList);
}

/**
 * @description: 测试 2
 * =================================================================================
 * @return {void}
 */
void Test2(void) {
    /* Function call (函数调用) */
    struct ListNode *actualList = NULL;
    actualList = LinkedList_AddAtTail(actualList, 1);
    actualList = LinkedList_DeleteAtIndex(actualList, 0);

    /* Expect result (期望结果) */
    int nums[] = {};
    struct ListNode *expectList = LinkedList_ArrayInit(nums, ARR_SIZE(nums));

    /* Validate result (验证函数调用结果) */
    Validate_LinkedList('2', expectList, actualList);

    /* 释放内存空间 */
    LinkedList_Free(actualList);
    LinkedList_Free(expectList);
}

void Test3(void) {
    /* Function call (函数调用) */
    struct ListNode *actualList = NULL;
    actualList = LinkedList_AddAtTail(actualList, 1);
    actualList = LinkedList_AddAtTail(actualList, 2);
    actualList = LinkedList_AddAtTail(actualList, 1);
    actualList = LinkedList_AddAtTail(actualList, 2);
    actualList = LinkedList_AddAtTail(actualList, 1);
    actualList = LinkedList_AddAtTail(actualList, 2);
    actualList = LinkedList_DeleteValue(actualList, 2);

    /* Expect result (期望结果) */
    int nums[] = {1, 1, 1};
    struct ListNode *expectList = LinkedList_ArrayInit(nums, ARR_SIZE(nums));

    /* Validate result (验证函数调用结果) */
    Validate_LinkedList('3', expectList, actualList);

    /* 释放内存空间 */
    LinkedList_Free(actualList);
    LinkedList_Free(expectList);
}

void Test4(void) {
    /* Function call (函数调用) */
    struct ListNode *actualList = NULL;
    actualList = LinkedList_AddAtTail(actualList, 1);
    actualList = LinkedList_AddAtTail(actualList, 2);
    actualList = LinkedList_AddAtTail(actualList, 1);
    actualList = LinkedList_AddAtTail(actualList, 2);
    actualList = LinkedList_AddAtTail(actualList, 1);
    actualList = LinkedList_AddAtTail(actualList, 2);
    int actualReturnSize = 0;
    int *actualIndexes = LinkedList_GetIndexes(actualList, 2, &actualReturnSize);

    /* Expect result (期望结果) */
    int expectIndexes[] = {1, 3, 5};

    /* Validate result (验证函数调用结果) */
    Validate_Array('4', expectIndexes, ARR_SIZE(expectIndexes), actualIndexes, actualReturnSize, COMMON_FALSE);

    /* 释放内存空间 */
    LinkedList_Free(actualList);
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
    Test4();
    return 0;
}