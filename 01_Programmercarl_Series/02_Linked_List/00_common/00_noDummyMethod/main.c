/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\02_Linked_List\00_common\00_noDummyMethod\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 10:09:09
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-07 23:35:56
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 运行链表公共函数 - 未使用虚拟头节点
 */
/* 标准头文件 */
#include <stdio.h>
/* 通用头文件 */
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
void test_1(void) {
    /* 实际结果 */
    struct ListNode *actualList = NULL;
    actualList = linkedListAddAtTail(actualList, 1);
    actualList = linkedListAddAtTail(actualList, 2);
    actualList = linkedListAddAtTail(actualList, 3);
    actualList = linkedListDeleteAtIndex(actualList, 0);

    /* 预期结果 */
    int nums[] = {2, 3};
    struct ListNode *expectList = linkedListFromArray(nums, ARR_SIZE(nums));

    /* 比较结果 */
    validateLinkedList('1', expectList, actualList);

    /* 释放内存空间 */
    linkedListFree(actualList);
    linkedListFree(expectList);
}

/**
 * @description: 测试 2
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    /* 实际结果 */
    struct ListNode *actualList = NULL;
    actualList = linkedListAddAtTail(actualList, 1);
    actualList = linkedListDeleteAtIndex(actualList, 0);

    /* 预期结果 */
    int nums[] = {};
    struct ListNode *expectList = linkedListFromArray(nums, ARR_SIZE(nums));

    /* 比较结果 */
    validateLinkedList('2', expectList, actualList);

    /* 释放内存空间 */
    linkedListFree(actualList);
    linkedListFree(expectList);
}

void test_3(void) {
    /* 实际结果 */
    struct ListNode *actualList = NULL;
    actualList = linkedListAddAtTail(actualList, 1);
    actualList = linkedListAddAtTail(actualList, 2);
    actualList = linkedListAddAtTail(actualList, 1);
    actualList = linkedListAddAtTail(actualList, 2);
    actualList = linkedListAddAtTail(actualList, 1);
    actualList = linkedListAddAtTail(actualList, 2);
    actualList = linkedListDeleteElement(actualList, 2);

    /* 预期结果 */
    int nums[] = {1, 1, 1};
    struct ListNode *expectList = linkedListFromArray(nums, ARR_SIZE(nums));

    /* 比较结果 */
    validateLinkedList('3', expectList, actualList);

    /* 释放内存空间 */
    linkedListFree(actualList);
    linkedListFree(expectList);
}

void test_4(void) {
    /* 实际结果 */
    struct ListNode *actualList = NULL;
    actualList = linkedListAddAtTail(actualList, 1);
    actualList = linkedListAddAtTail(actualList, 2);
    actualList = linkedListAddAtTail(actualList, 1);
    actualList = linkedListAddAtTail(actualList, 2);
    actualList = linkedListAddAtTail(actualList, 1);
    actualList = linkedListAddAtTail(actualList, 2);
    int actualReturnSize = 0;
    int *actualIndexes = linkedListGetIndexes(actualList, 2, &actualReturnSize);

    /* 预期结果 */
    int expectIndexes[] = {1, 3, 5};

    /* 比较结果 */
    validateArray('4', expectIndexes, ARR_SIZE(expectIndexes), actualIndexes, actualReturnSize);

    /* 释放内存空间 */
    linkedListFree(actualList);
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