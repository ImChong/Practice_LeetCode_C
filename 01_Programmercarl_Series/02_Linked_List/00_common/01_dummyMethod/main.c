/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\02_Linked_List\00_common\01_dummyMethod\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-22 09:56:52
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 707. 设计链表：https://leetcode.cn/problems/design-linked-list/
 * https://programmercarl.com/0707.%E8%AE%BE%E8%AE%A1%E9%93%BE%E8%A1%A8.html
 */
#include <stdio.h>
#include "commonArray.h"                /* 00_Basics\01_Common_Func\inc\commonArray.h */
#include "commonLinkedListDummy.h"      /* 00_Basics\01_Common_Func\inc\commonLinkedListDummy.h */

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
    arrayToMyLinkedList(expectDummy, nums, ARR_SIZE(nums));

    /* 比较结果 */
    validateMyLinkedList('1', expectDummy, actualDummy);

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