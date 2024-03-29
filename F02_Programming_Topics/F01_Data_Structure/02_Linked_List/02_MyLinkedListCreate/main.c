/*
 * @FilePath     : \Practice_LeetCode_C\F02_Programming_Topics\F01_Data_Structure\02_Linked_List\02_myLinkedListCreate\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-02-02 19:31:00
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 707. 设计链表：https://leetcode.cn/problems/design-linked-list/
 * https://programmercarl.com/0707.%E8%AE%BE%E8%AE%A1%E9%93%BE%E8%A1%A8.html
 */
/* Standard header file (标准头文件) */
#include <stdio.h>
#include <stdlib.h>
/* solution header file (题解头文件) */
#include "F01_Common_Functions/inc/common_linked_list_dummy.h"
/* Common function header file (通用头文件) */
#include "F01_Common_Functions/inc/common_array.h"

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
 * =================================================================================
 * @return {void}
 */
void Test2(void) {
    /* Function call (函数调用) */
    /* ["DummyLinkedList","addAtHead","deleteAtIndex","addAtHead","addAtHead","addAtHead","addAtHead","addAtHead","addAtTail","get","deleteAtIndex","deleteAtIndex"] */
    /* [[],[2],[1],[2],[7],[3],[2],[5],[5],[5],[6],[4]] */
    DummyLinkedList *actualDummy = DLinkedList_Init();      /* DummyLinkedList     [] */
    DLinkedList_AddAtHead(actualDummy, 2);                 /* addAtHead        [2] */
    DLinkedList_DeleteAtIndex(actualDummy, 1);             /* deleteAtIndex    [1] */
    DLinkedList_AddAtHead(actualDummy, 2);                 /* addAtHead        [2] */
    DLinkedList_AddAtHead(actualDummy, 7);                 /* addAtHead        [7] */
    DLinkedList_AddAtHead(actualDummy, 3);                 /* addAtHead        [3] */
    DLinkedList_AddAtHead(actualDummy, 2);                 /* addAtHead        [2] */
    DLinkedList_AddAtHead(actualDummy, 5);                 /* addAtHead        [5] */
    DLinkedList_AddAtTail(actualDummy, 5);                 /* addAtTail        [5] */
    DLinkedList_GetValueAtIndex(actualDummy, 5);                       /* get              [5] */
    DLinkedList_DeleteAtIndex(actualDummy, 6);             /* deleteAtIndex    [6] */
    DLinkedList_DeleteAtIndex(actualDummy, 4);             /* deleteAtIndex    [4] */

    /* Expect result (期望结果) */
    DummyLinkedList *expectDummy = DLinkedList_Init();
    int nums[] = {5, 2, 3, 7, 2};
    DLinkedList_ArrayInit(expectDummy, nums, ARR_SIZE(nums));

    /* Validate result (验证函数调用结果) */
    Validate_DLinkedList('2', expectDummy, actualDummy);

    /* Free memory (释放内存空间) */
    DLinkedList_Free(actualDummy);
}

/**
 * @description: Test 3
 * =================================================================================
 * @return {void}
 */
void Test3(void) {
    /* Function call (函数调用) */
    /* ["DummyLinkedList","addAtHead","get","addAtHead","addAtHead","deleteAtIndex","addAtHead","get","get","get","addAtHead","deleteAtIndex"] */
    /* [[],[4],[1],[1],[5],[3],[7],[3],[3],[3],[1],[4]] */
    /* [null,null,-1,null,null,null,null,4,4,4,null,null] */
    DummyLinkedList *actualDummy = DLinkedList_Init();  /* DummyLinkedList     [ ] */
    DLinkedList_AddAtHead(actualDummy, 4);             /* addAtHead        [4] */
    DLinkedList_AddAtHead(actualDummy, 1);             /* addAtHead        [1] */
    DLinkedList_AddAtHead(actualDummy, 2);             /* addAtHead        [2] */
    DLinkedList_DeleteAtIndex(actualDummy, 3);         /* deleteAtIndex    [3] */
    DLinkedList_AddAtHead(actualDummy, 7);             /* addAtHead        [7] */
    DLinkedList_AddAtHead(actualDummy, 1);             /* addAtHead        [1] */
    DLinkedList_DeleteAtIndex(actualDummy, 4);         /* deleteAtIndex    [4] */

    /* Expect result (期望结果) */
    DummyLinkedList *expectDummy = DLinkedList_Init();
    int nums[] = {1, 7, 2, 1};
    DLinkedList_ArrayInit(expectDummy, nums, ARR_SIZE(nums));

    /* Validate result (验证函数调用结果) */
    Validate_DLinkedList('3', expectDummy, actualDummy);

    /* Free memory (释放内存空间) */
    DLinkedList_Free(actualDummy);
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
    return 0;
}