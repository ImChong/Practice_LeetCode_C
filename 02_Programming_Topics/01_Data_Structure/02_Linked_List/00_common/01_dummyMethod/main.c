/*
 * @FilePath     : \Practice_LeetCode_C\02_Programming_Topics\01_Data_Structure\02_Linked_List\00_common\01_dummyMethod\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-04 14:40:14
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 707. 设计链表：https://leetcode.cn/problems/design-linked-list/
 * https://programmercarl.com/0707.%E8%AE%BE%E8%AE%A1%E9%93%BE%E8%A1%A8.html
 */
/* standard header file (标准头文件) */
#include <stdio.h>
#include <stdlib.h>
/* common function header file (通用头文件) */
#include "commonTypeDef.h"
#include "commonArray.h"
#include "commonLinkedListDummy.h"

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
    /* 实际结果 */
    DummyLinkedList *actualDummy = DLinkedList_Init();
    DLinkedList_AddAtHead(actualDummy, 1);
    DLinkedList_AddAtTail(actualDummy, 3);
    DLinkedList_AddAtIndex(actualDummy, 1, 2);
    DLinkedList_DeleteAtIndex(actualDummy, 0);

    /* 预期结果 */
    DummyLinkedList *expectDummy = DLinkedList_Init();
    int nums[] = {2, 3};
    DLinkedList_FromArray(expectDummy, nums, ARR_SIZE(nums));

    /* 比较结果 */
    Validate_DLinkedList('1', expectDummy, actualDummy);

    /* 释放内存空间 */
    DLinkedList_Free(actualDummy);
}

/**
 * @description: 测试 2
 * =================================================================================
 * @return {void}
 */
void Test2(void) {
    /* 实际结果 */
    DummyLinkedList *actualDummy = DLinkedList_Init();
    DLinkedList_AddAtHead(actualDummy, 1);
    DLinkedList_DeleteAtIndex(actualDummy, 0);

    /* 预期结果 */
    DummyLinkedList *expectDummy = DLinkedList_Init();

    /* 比较结果 */
    Validate_DLinkedList('2', expectDummy, actualDummy);

    /* 释放内存空间 */
    DLinkedList_Free(actualDummy);
}

/**
 * @description: 测试 3
 * =================================================================================
 * @return {void}
 */
void Test3(void) {
    /* 实际结果 */
    DummyLinkedList *actualDummy = DLinkedList_Init();
    DLinkedList_AddAtTail(actualDummy, 1);
    DLinkedList_AddAtTail(actualDummy, 2);
    DLinkedList_AddAtTail(actualDummy, 1);
    DLinkedList_AddAtTail(actualDummy, 2);
    DLinkedList_AddAtTail(actualDummy, 1);
    DLinkedList_AddAtTail(actualDummy, 2);
    DLinkedList_DeleteValue(actualDummy, 2);

    /* 预期结果 */
    DummyLinkedList *expectDummy = DLinkedList_Init();
    int nums[] = {1, 1, 1};
    DLinkedList_FromArray(expectDummy, nums, ARR_SIZE(nums));

    /* 比较结果 */
    Validate_DLinkedList('3', expectDummy, actualDummy);

    /* 释放内存空间 */
    DLinkedList_Free(actualDummy);
}

void Test4(void) {
    /* 实际结果 */
    DummyLinkedList *actualDummy = DLinkedList_Init();
    DLinkedList_AddAtTail(actualDummy, 1);
    DLinkedList_AddAtTail(actualDummy, 2);
    DLinkedList_AddAtTail(actualDummy, 1);
    DLinkedList_AddAtTail(actualDummy, 2);
    DLinkedList_AddAtTail(actualDummy, 1);
    DLinkedList_AddAtTail(actualDummy, 2);
    int actualReturnSize = 0;
    int *actualIndexes = DLinkedList_GetIndexes(actualDummy, 2, &actualReturnSize);

    /* 预期结果 */
    int expectIndexes[] = {1, 3, 5};

    /* 比较结果 */
    Validate_Array('4', expectIndexes, ARR_SIZE(expectIndexes), actualIndexes, actualReturnSize, COMMON_FALSE);

    /* 释放内存空间 */
    DLinkedList_Free(actualDummy);
    free(actualIndexes);
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