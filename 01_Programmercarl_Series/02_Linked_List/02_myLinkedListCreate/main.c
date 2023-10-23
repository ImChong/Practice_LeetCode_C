/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\02_Linked_List\02_myLinkedListCreate\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-22 09:56:25
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 707. 设计链表：https://leetcode.cn/problems/design-linked-list/
 * https://programmercarl.com/0707.%E8%AE%BE%E8%AE%A1%E9%93%BE%E8%A1%A8.html
 */
#include <stdio.h>
#include <stdlib.h>
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

/**
 * @description: 测试 2
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    /* 实际结果 */
    /* ["MyLinkedList","addAtHead","deleteAtIndex","addAtHead","addAtHead","addAtHead","addAtHead","addAtHead","addAtTail","get","deleteAtIndex","deleteAtIndex"] */
    /* [[],[2],[1],[2],[7],[3],[2],[5],[5],[5],[6],[4]] */
    MyLinkedList *actualDummy = myLinkedListCreate();      /* MyLinkedList     [] */
    myLinkedListAddAtHead(actualDummy, 2);                 /* addAtHead        [2] */
    myLinkedListDeleteAtIndex(actualDummy, 1);             /* deleteAtIndex    [1] */
    myLinkedListAddAtHead(actualDummy, 2);                 /* addAtHead        [2] */
    myLinkedListAddAtHead(actualDummy, 7);                 /* addAtHead        [7] */
    myLinkedListAddAtHead(actualDummy, 3);                 /* addAtHead        [3] */
    myLinkedListAddAtHead(actualDummy, 2);                 /* addAtHead        [2] */
    myLinkedListAddAtHead(actualDummy, 5);                 /* addAtHead        [5] */
    myLinkedListAddAtTail(actualDummy, 5);                 /* addAtTail        [5] */
    myLinkedListGet(actualDummy, 5);                       /* get              [5] */
    myLinkedListDeleteAtIndex(actualDummy, 6);             /* deleteAtIndex    [6] */
    myLinkedListDeleteAtIndex(actualDummy, 4);             /* deleteAtIndex    [4] */
    printLinkedList(actualDummy);

    /* 预期结果 */
    MyLinkedList *expectDummy = myLinkedListCreate();
    int nums[] = {5, 2, 3, 7, 2};
    arrayToMyLinkedList(expectDummy, nums, ARR_SIZE(nums));

    /* 比较结果 */
    validateMyLinkedList('2', expectDummy, actualDummy);

    /* 释放内存空间 */
    myLinkedListFree(actualDummy);
}

/**
 * @description: 测试 3
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    /* 实际结果 */
    /* ["MyLinkedList","addAtHead","get","addAtHead","addAtHead","deleteAtIndex","addAtHead","get","get","get","addAtHead","deleteAtIndex"] */
    /* [[],[4],[1],[1],[5],[3],[7],[3],[3],[3],[1],[4]] */
    /* [null,null,-1,null,null,null,null,4,4,4,null,null] */
    MyLinkedList *actualDummy = myLinkedListCreate();  /* MyLinkedList     [ ] */
    myLinkedListAddAtHead(actualDummy, 4);             /* addAtHead        [4] */
    myLinkedListAddAtHead(actualDummy, 1);             /* addAtHead        [1] */
    myLinkedListAddAtHead(actualDummy, 2);             /* addAtHead        [2] */
    myLinkedListDeleteAtIndex(actualDummy, 3);         /* deleteAtIndex    [3] */
    myLinkedListAddAtHead(actualDummy, 7);             /* addAtHead        [7] */
    myLinkedListAddAtHead(actualDummy, 1);             /* addAtHead        [1] */
    myLinkedListDeleteAtIndex(actualDummy, 4);         /* deleteAtIndex    [4] */
    printLinkedList(actualDummy);

    /* 预期结果 */
    MyLinkedList *expectDummy = myLinkedListCreate();
    int nums[] = {1, 7, 2, 1};
    arrayToMyLinkedList(expectDummy, nums, ARR_SIZE(nums));

    /* 比较结果 */
    validateMyLinkedList('3', expectDummy, actualDummy);

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
    test_2();
    test_3();
    return 0;
}