/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\02_Linked_List\00_common\01_dummyMethod\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-18 14:31:53
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
void test_1(void) {
    /* 实际结果 */
    DummyLinkedList *actualDummy = myLinkedListCreate();
    dummyLinkedListAddAtHead(actualDummy, 1);
    dummyLinkedListAddAtTail(actualDummy, 3);
    dummyLinkedListAddAtIndex(actualDummy, 1, 2);
    dummyLinkedListDeleteAtIndex(actualDummy, 0);

    /* 预期结果 */
    DummyLinkedList *expectDummy = myLinkedListCreate();
    int nums[] = {2, 3};
    dummyLinkedListFromArray(expectDummy, nums, ARR_SIZE(nums));

    /* 比较结果 */
    validateDummyLinkedList('1', expectDummy, actualDummy);

    /* 释放内存空间 */
    dummyLinkedListFree(actualDummy);
}

/**
 * @description: 测试 2
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    /* 实际结果 */
    DummyLinkedList *actualDummy = myLinkedListCreate();
    dummyLinkedListAddAtHead(actualDummy, 1);
    dummyLinkedListDeleteAtIndex(actualDummy, 0);

    /* 预期结果 */
    DummyLinkedList *expectDummy = myLinkedListCreate();

    /* 比较结果 */
    validateDummyLinkedList('2', expectDummy, actualDummy);

    /* 释放内存空间 */
    dummyLinkedListFree(actualDummy);
}

/**
 * @description: 测试 3
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    /* 实际结果 */
    DummyLinkedList *actualDummy = myLinkedListCreate();
    dummyLinkedListAddAtTail(actualDummy, 1);
    dummyLinkedListAddAtTail(actualDummy, 2);
    dummyLinkedListAddAtTail(actualDummy, 1);
    dummyLinkedListAddAtTail(actualDummy, 2);
    dummyLinkedListAddAtTail(actualDummy, 1);
    dummyLinkedListAddAtTail(actualDummy, 2);
    dummyLinkedListDeleteElement(actualDummy, 2);

    /* 预期结果 */
    DummyLinkedList *expectDummy = myLinkedListCreate();
    int nums[] = {1, 1, 1};
    dummyLinkedListFromArray(expectDummy, nums, ARR_SIZE(nums));

    /* 比较结果 */
    validateDummyLinkedList('3', expectDummy, actualDummy);

    /* 释放内存空间 */
    dummyLinkedListFree(actualDummy);
}

void test_4(void) {
    /* 实际结果 */
    DummyLinkedList *actualDummy = myLinkedListCreate();
    dummyLinkedListAddAtTail(actualDummy, 1);
    dummyLinkedListAddAtTail(actualDummy, 2);
    dummyLinkedListAddAtTail(actualDummy, 1);
    dummyLinkedListAddAtTail(actualDummy, 2);
    dummyLinkedListAddAtTail(actualDummy, 1);
    dummyLinkedListAddAtTail(actualDummy, 2);
    int actualReturnSize = 0;
    int *actualIndexes = dummyLinkedListGetIndexes(actualDummy, 2, &actualReturnSize);

    /* 预期结果 */
    int expectIndexes[] = {1, 3, 5};

    /* 比较结果 */
    validateArray('4', expectIndexes, ARR_SIZE(expectIndexes), actualIndexes, actualReturnSize, COMMON_FALSE);

    /* 释放内存空间 */
    dummyLinkedListFree(actualDummy);
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
    test_1();
    test_2();
    test_3();
    test_4();
    return 0;
}