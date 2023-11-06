/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\src\commonLinkedListDummy.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 10:33:34
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-06 10:35:40
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用虚拟头节点链表源文件 - 使用虚拟头节点
 */
#include <stdio.h>
#include <stdlib.h>
#include "commonLinkedListDummy.h"

/**********************************************************************************/
/*                                                                                */
/*                                 UTILITY FUNCTIONS                              */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 创建链表
 * =================================================================================
 * @return {MyLinkedList} *dummyHead    返回虚拟头节点
 */
MyLinkedList *myLinkedListCreate(void) {
    MyLinkedList *dummyHead = (MyLinkedList*)malloc(sizeof(MyLinkedList));    /* 为虚拟头节点分配空间 */
    dummyHead->head = NULL;       /* 初始化链表头 */
    dummyHead->size = 0;          /* 初始化链表长度 */
    return dummyHead;             /* 返回虚拟头节点 */
}

/**
 * @description: 获取指定索引的节点数值
 * =================================================================================
 * @param {MyLinkedList} *dummyHead     虚拟头节点
 * @param {int} index                   索引
 * @return {int} ans                    返回指定索引的节点数值
 */
int myLinkedListGet(MyLinkedList *dummyHead, int index) {
    if (index < 0 || index >= dummyHead->size) {      /* 输入校验 */
        return -1;                                  /* 返回 -1 */
    }
    struct ListNode *curr = dummyHead->head;          /* 获取当前链表头节点的指针 */
    while (index-- > 0) {                       /* 循环索引次 */
        curr = curr->next;                          /* 指针向后移动一位 */
    }
    return curr->val;                           /* 返回指定索引的节点数值 */
}

/**
 * @description: 在链表头部添加新节点
 * =================================================================================
 * @param {MyLinkedList} *dummyHead       虚拟头节点
 * @param {int} val                 新节点数值
 * @return {void}
 */
void myLinkedListAddAtHead(MyLinkedList *dummyHead, int val) {
    struct ListNode *newHead = (struct ListNode*)malloc(sizeof(struct ListNode));    /* 为链表新头节点分配空间*/
    newHead->val = val;             /* 为链表新头节点赋值 */
    newHead->next = dummyHead->head;      /* 将链表新头节点的下一节点设置为链表旧头节点 */
    dummyHead->head = newHead;            /* 将虚拟头节点指向的链表头节点设置为链表新头节点 */
    dummyHead->size++;                    /* 链表长度 + 1 */
}

/**
 * @description: 在链表尾部添加新节点
 * =================================================================================
 * @param {MyLinkedList} *dummyHead       虚拟头节点
 * @param {int} val                 新节点数值
 * @return {void}
 */
void myLinkedListAddAtTail(MyLinkedList *dummyHead, int val) {
    struct ListNode *newTail = (struct ListNode*)malloc(sizeof(struct ListNode));    /* 为链表新尾节点分配空间*/
    newTail->val = val;                         /* 为链表新尾节点赋值 */
    newTail->next = NULL;                       /* 将链表新尾节点的下一节点设置为NULL */

    if (dummyHead->head == NULL) {                    /* 如果链表为空 */
        dummyHead->head = newTail;                        /* 将虚拟头节点指向的链表头节点设置为链表新尾节点 */
    } else {                                    /* 如果链表不为空 */
        struct ListNode *curr = dummyHead->head;          /* 获取当前链表头节点的指针 */
        while (curr->next != NULL) {                /* 当指针所指的节点不为NULL时 */
            curr = curr->next;                          /* 指针向后移动一位 */
        }
        curr->next = newTail;                       /* 将当前指针所指节点的下一节点指向新节点 */
    }
    dummyHead->size++;                                /* 链表长度 + 1 */
}

/**
 * @description: 在指定索引处插入新节点
 * =================================================================================
 * @param {MyLinkedList} *dummyHead       虚拟头节点
 * @param {int} index               索引
 * @param {int} val                 新节点数值
 * @return {void}
 */
void myLinkedListAddAtIndex(MyLinkedList *dummyHead, int index, int val) {
    if (index < 0 || index > dummyHead->size) {       /* 输入校验 */
        return;
    }

    if (index == 0) {                           /* 插入新头节点 */
        myLinkedListAddAtHead(dummyHead, val);
        return;
    }

    if (index == dummyHead->size) {                   /* 插入新尾节点 */
        myLinkedListAddAtTail(dummyHead, val);
        return;
    }

    struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));    /* 为链表新节点分配空间 */
    newNode->val = val;                         /* 为链表新节点赋值 */

    struct ListNode *curr = dummyHead->head;          /* 获取当前链表头节点的指针 */
    for (int i = 0; i < index - 1; i++) {       /* 因为新节点自己本身要占据一个节点位置，所以循环索引 - 1 次 */
        curr = curr->next;                          /* 指针向后移动一位 */
    }

    newNode->next = curr->next;                 /* 将新节点的下一节点指向当前指针所指节点的下一节点*/
    curr->next = newNode;                       /* 将当前指针所指节点的下一节点指向新节点 */
    dummyHead->size++;                                /* 链表长度 + 1 */
}

/**
 * @description: 删除指定索引的节点
 * =================================================================================
 * @param {MyLinkedList} *dummyHead       虚拟头节点
 * @param {int} index               索引
 * @return {void}
 */
void myLinkedListDeleteAtIndex(MyLinkedList *dummyHead, int index) {
    if (index < 0 || index >= dummyHead->size) {      /* 输入校验 */
        return;
    }

    struct ListNode *curr = dummyHead->head;          /* 获取当前链表头节点的指针 */
    if (index == 0) {                           /* 如果删除头节点 */
        dummyHead->head = curr->next;                    /* 将虚拟头节点所指向的链表头节点指向当前指针的下一节点 */
    } else {                                    /* 如果删除中间节点 */
        for (int i = 0; i < index - 1; i++) {       /* 因为目标节点自己本身要占据一个节点位置，所以循环索引 - 1 次 */
            curr = curr->next;                          /* 指针向后移动一位 */
        }
        if (curr->next) {                           /* 如果当前指针所指节点的下一节点存在*/
            struct ListNode* tmp = curr->next;          /* 获取待删除节点的指针 */
            curr->next = curr->next->next;              /* 将待删除节点上一节点的下一节点改为待删除节点的下一节点*/
            free(tmp);                                  /* 释放待删除节点内存空间 */
        }
    }
    dummyHead->size--;                                /* 链表长度 - 1 */
}

/**
 * @description: 释放链表内存空间
 * =================================================================================
 * @param {MyLinkedList} *dummyHead       虚拟头节点
 * @return {void}
 */
void myLinkedListFree(MyLinkedList *dummyHead) {
    struct ListNode *curr = dummyHead->head;      /* 获取当前链表头节点的指针 */
    while (curr != NULL) {                  /* 当指针所指的节点不为NULL时 */
        struct ListNode *tmp = curr;            /* 获取当前节点的指针 */
        curr = curr->next;                      /* 指针向后移动一位 */
        free(tmp);                              /* 释放当前指针所指节点的内存空间 */
    }
    free(dummyHead);                              /* 释放虚拟头节点的内存空间 */
}

/**********************************************************************************/
/*                                                                                */
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 将数组转换为链表
 * =================================================================================
 * @param {MyLinkedList} *list      虚拟头节点
 * @param {int} *nums               数组
 * @param {int} numsSize            数组大小
 * @return {void}
 */
void arrayToMyLinkedList(MyLinkedList *list, int *nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        myLinkedListAddAtTail(list, nums[i]);
    }
}

/**
 * @description: 打印链表
 * =================================================================================
 * @param {MyLinkedList} *list      虚拟头节点
 * @return {void}
 */
void printMyLinkedList(MyLinkedList *list) {
    printf("linked list (size: %d): ", list->size);     /* 打印链表长度 */
    for (int i = 0; i < list->size; i++) {              /* 循环打印链表节点数值 */
        printf("%d ", myLinkedListGet(list, i));            /* 打印链表节点数值 */
    }
    printf("\n");                                       /* 换行 */
}

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
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
void validateMyLinkedList(char testNum, MyLinkedList *expect, MyLinkedList *actual) {
    printf("=========================\n");
    for (int i = 0; i < expect->size; i++) {
        if (myLinkedListGet(expect, i) != myLinkedListGet(actual, i)) {
            printf(" - ❌ Test %c Failed\n", testNum);
            return;
        }
    }
    printf(" - ✅ Test %c Passed\n", testNum);

    printf("=========================\n");
    printf("- Expect: "); printMyLinkedList(expect);
    printf("- Actual: "); printMyLinkedList(actual);
}