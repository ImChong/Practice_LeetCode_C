/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\02_Linked_List\02_myLinkedListCreate\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-18 14:38:02
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 707. 设计链表：https://leetcode.cn/problems/design-linked-list/
 * https://programmercarl.com/0707.%E8%AE%BE%E8%AE%A1%E9%93%BE%E8%A1%A8.html
 */
/* Standard header file (标准头文件) */
#include <stdio.h>
#include <stdlib.h>
/* common function header file (通用头文件) */
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
    DummyLinkedList *actualDummy = myLinkedListCreate();
    DLinkedList_AddAtHead(actualDummy, 1);
    DLinkedList_AddAtTail(actualDummy, 3);
    DLinkedList_AddAtIndex(actualDummy, 1, 2);
    DLinkedList_DeleteAtIndex(actualDummy, 0);

    /* 预期结果 */
    DummyLinkedList *expectDummy = myLinkedListCreate();
    int nums[] = {2, 3};
    DLinkedList_ArrayInit(expectDummy, nums, ARR_SIZE(nums));

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
    /* ["DummyLinkedList","addAtHead","deleteAtIndex","addAtHead","addAtHead","addAtHead","addAtHead","addAtHead","addAtTail","get","deleteAtIndex","deleteAtIndex"] */
    /* [[],[2],[1],[2],[7],[3],[2],[5],[5],[5],[6],[4]] */
    DummyLinkedList *actualDummy = myLinkedListCreate();      /* DummyLinkedList     [] */
    DLinkedList_AddAtHead(actualDummy, 2);                 /* addAtHead        [2] */
    DLinkedList_DeleteAtIndex(actualDummy, 1);             /* deleteAtIndex    [1] */
    DLinkedList_AddAtHead(actualDummy, 2);                 /* addAtHead        [2] */
    DLinkedList_AddAtHead(actualDummy, 7);                 /* addAtHead        [7] */
    DLinkedList_AddAtHead(actualDummy, 3);                 /* addAtHead        [3] */
    DLinkedList_AddAtHead(actualDummy, 2);                 /* addAtHead        [2] */
    DLinkedList_AddAtHead(actualDummy, 5);                 /* addAtHead        [5] */
    DLinkedList_AddAtTail(actualDummy, 5);                 /* addAtTail        [5] */
    DLinkedList_GetAtIndex(actualDummy, 5);                       /* get              [5] */
    DLinkedList_DeleteAtIndex(actualDummy, 6);             /* deleteAtIndex    [6] */
    DLinkedList_DeleteAtIndex(actualDummy, 4);             /* deleteAtIndex    [4] */

    /* 预期结果 */
    DummyLinkedList *expectDummy = myLinkedListCreate();
    int nums[] = {5, 2, 3, 7, 2};
    DLinkedList_ArrayInit(expectDummy, nums, ARR_SIZE(nums));

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
    /* ["DummyLinkedList","addAtHead","get","addAtHead","addAtHead","deleteAtIndex","addAtHead","get","get","get","addAtHead","deleteAtIndex"] */
    /* [[],[4],[1],[1],[5],[3],[7],[3],[3],[3],[1],[4]] */
    /* [null,null,-1,null,null,null,null,4,4,4,null,null] */
    DummyLinkedList *actualDummy = myLinkedListCreate();  /* DummyLinkedList     [ ] */
    DLinkedList_AddAtHead(actualDummy, 4);             /* addAtHead        [4] */
    DLinkedList_AddAtHead(actualDummy, 1);             /* addAtHead        [1] */
    DLinkedList_AddAtHead(actualDummy, 2);             /* addAtHead        [2] */
    DLinkedList_DeleteAtIndex(actualDummy, 3);         /* deleteAtIndex    [3] */
    DLinkedList_AddAtHead(actualDummy, 7);             /* addAtHead        [7] */
    DLinkedList_AddAtHead(actualDummy, 1);             /* addAtHead        [1] */
    DLinkedList_DeleteAtIndex(actualDummy, 4);         /* deleteAtIndex    [4] */

    /* 预期结果 */
    DummyLinkedList *expectDummy = myLinkedListCreate();
    int nums[] = {1, 7, 2, 1};
    DLinkedList_ArrayInit(expectDummy, nums, ARR_SIZE(nums));

    /* 比较结果 */
    Validate_DLinkedList('3', expectDummy, actualDummy);

    /* 释放内存空间 */
    DLinkedList_Free(actualDummy);
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
    return 0;
}