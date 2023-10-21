/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\02_Linked_List\00_common\01_dummyMethod\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-21 22:05:55
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 707. 设计链表：https://leetcode.cn/problems/design-linked-list/
 * https://programmercarl.com/0707.%E8%AE%BE%E8%AE%A1%E9%93%BE%E8%A1%A8.html
 */
#include <stdio.h>
#include "commonArray.h"
#include "dummyLinkedListCommon.h"

/**********************************************************************************/
/*                                                                                */
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 验证答案
 * =================================================================================
 * @param {char} testNum            测试编号
 * @param {MyLinkedList} *expect    预期
 * @param {MyLinkedList} *actual    实际
 * @return {void}
 */
void validateAnswer(char testNum, MyLinkedList *expect, MyLinkedList *actual) {
    for (int i = 0; i < expect->size; i++) {
        if (myLinkedListGet(expect, i) != myLinkedListGet(actual, i)) {
            printf("❌ Test %c Failed\n", testNum);
            return;
        }
    }
    printf("✅ Test %c Passed\n", testNum);
}

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
    MyLinkedList *actualDummy = myLinkedListCreate();
    myLinkedListAddAtHead(actualDummy, 1);
    myLinkedListAddAtTail(actualDummy, 3);
    myLinkedListAddAtIndex(actualDummy, 1, 2);
    myLinkedListDeleteAtIndex(actualDummy, 0);
    printLinkedList(actualDummy);

    /* 预期结果 */
    MyLinkedList *expectDummy = myLinkedListCreate();
    int nums[] = {2, 3};
    arrayToLinkedList(expectDummy, nums, ARR_SIZE(nums));

    /* 比较结果 */
    validateAnswer('1', expectDummy, actualDummy);

    /* 释放内存空间 */
    myLinkedListFree(actualDummy);
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
    return 0;
}