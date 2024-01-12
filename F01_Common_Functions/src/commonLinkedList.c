/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\src\commonLinkedList.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-02 19:11:08
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用链表源文件 - 未使用虚拟头节点
 */
/* Common function configuration file (通用函数配置文件) */
#include "compileCfg.h"
#if COMMON_LINKED_LIST_EN /* whether compile this file, the definition of this macro can be found in compileCfg.h */
/* Header file (本文件头文件) */
#include "commonLinkedList.h"
/* Standard header file (标准头文件) */
#include <stdio.h>
#include <stdlib.h>
/* Common function header file (通用头文件) */
#include "commonTypeDef.h"

/**********************************************************************************/
/*                                                                                */
/*                                 UTILITY FUNCTIONS                              */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 获取链表中第index个节点的值
 * =================================================================================
 * @param {ListNode *} head     头节点指针
 * @param {int} index           目标节点索引
 * @return {int}                目标节点值
 */
int LinkedList_GetAtIndex(struct ListNode *head, int index) {
    struct ListNode *currentNode = head;
    while (index--) {
        currentNode = currentNode->next;
    }
    return currentNode->val;
}

/**
 * @description: 在链表头部添加一个节点
 * =================================================================================
 * @param {ListNode *} head     头节点指针
 * @param {int} val             目标节点值
 * @return {ListNode *} head    头节点指针
 */
struct ListNode *LinkedList_AddAtHead(struct ListNode *head, int val) {
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = head;
    return newNode;
}


/**
 * @description: 添加元素至链表 - 不使用虚拟头结点
 * =================================================================================
 * @param {ListNode *} head             头节点指针
 * @param {int} val                     元素值
 * @return {struct ListNode} *head      头节点指针
 */
struct ListNode *LinkedList_AddAtTail(struct ListNode *head, int val) {
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }
    struct ListNode *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

/**
 * @description: 在链表中第index个节点之前添加一个值为val的节点
 * =================================================================================
 * @param {ListNode *} head     头节点指针
 * @param {int} index           目标节点索引
 * @param {int} val             目标节点值
 * @return {ListNode *} head    头节点指针
 */
struct ListNode *LinkedList_AddAtIndex(struct ListNode *head, int index, int val) {
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }
    struct ListNode *currentNode = head;
    while (index--) {
        currentNode = currentNode->next;
    }
    newNode->next = currentNode->next;
    currentNode->next = newNode;
    return head;
}

/**
 * @description: 删除链表中第index个节点
 * =================================================================================
 * @param {ListNode *} head     头节点指针
 * @param {int} index           目标节点索引
 * @return {ListNode *} head    头节点指针
 */
struct ListNode *LinkedList_DeleteAtIndex(struct ListNode *head, int index) {
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *currentNode = dummy;
    while (index--) {
        currentNode = currentNode->next;
    }
    struct ListNode *temp = currentNode->next;
    currentNode->next = currentNode->next->next;
    free(temp);
    return dummy->next;
}

/**
 * @description: 移除链表元素
 * =================================================================================
 * @param {ListNode} *head              链表虚拟头节点
 * @param {int} val                     目标值
 * @return {struct ListNode} *head      返回链表虚拟头节点
 */
struct ListNode *LinkedList_DeleteValue(struct ListNode *head, int val) {
    struct ListNode dummy;                          /* 创建虚拟头节点 */
    dummy.next = head;                              /* 将传入链表接在虚拟头节点后面 */

    struct ListNode *currentNode = &dummy;                 /* 创建指针：用于遍历列表 */
    while (currentNode->next != NULL) {                    /* 遍历链表 */
        if (currentNode->next->val == val) {                   /* 当前节点的下一个节点的值等于目标值 */
            struct ListNode *temp = currentNode->next;              /* 保存当前节点的下一个节点 */
            currentNode->next = currentNode->next->next;                  /* 当前节点的下一个节点指向下下个节点 */
            free(temp);                                      /* 释放当前节点的下一个节点 */
        } else {                                        /* 当前节点的下一个节点的值不等于目标值 */
            currentNode = currentNode->next;                              /* 当前节点指向下一个节点 */
        }
    }
    return dummy.next;                              /* 返回链表虚拟头节点 */
}

/**
 * @description: 获取链表中值为val的所有节点的索引
 * =================================================================================
 * @param {ListNode} *head      链表头节点
 * @param {int} val             目标值
 * @param {int *} returnSize    返回数组大小
 * @return {int *} indexes      返回索引数组
 */
int *LinkedList_GetIndexes(struct ListNode *head, int val, int *returnSize) {
    int *indexes = (int *)malloc(sizeof(int) * 1000);       /* NOLINT(readability/casting) */
    int listIndex = 0;
    int elementIndex = 0;
    while (head != NULL) {
        if (head->val == val) {
            indexes[elementIndex++] = listIndex;
        }
        head = head->next;
        listIndex++;
    }
    *returnSize = elementIndex;
    return indexes;
}

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 创建链表 - 不使用虚拟头结点
 * =================================================================================
 * @param {int} *array                  数组
 * @param {int} size                    数组大小
 * @return {struct ListNode} *head      头节点指针
 */
struct ListNode *LinkedList_ArrayInit(int *array, int size) {
    struct ListNode *head = NULL;           /* 头节点指针 */
    struct ListNode *currentNode = NULL;    /* 当前节点指针 */

    for (int i = 0; i < size; i++) {
        /* 创建新结点 */
        struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
        new_node->val = array[i];
        new_node->next = NULL;

        /* 如果链表为空，则将新结点设置为头结点 */
        if (head == NULL) {
            head = new_node;
        } else {
            /* 否则，将新结点追加到链表末尾 */
            currentNode->next = new_node;
        }
        currentNode = new_node;
    }
    return head;
}

/**
 * @description: 打印链表
 * =================================================================================
 * @param {ListNode} *head          头节点指针
 * @return {void}
 */
void LinkedList_Print(struct ListNode *head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d", head->val);
        if (head->next != NULL) {
            printf(" -> ");
        }
        head = head->next;
    }
    printf("\n");
}

/**
 * @description: 释放链表
 * =================================================================================
 * @param {ListNode} *head          头节点指针
 * @return {void}
 */
void LinkedList_Free(struct ListNode *head) {
    struct ListNode *temp = NULL;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
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
 * @param {ListNode} *expectList    预期
 * @param {ListNode} *actualList    结果
 * @return {void}
 */
void Validate_LinkedList(char testNum, struct ListNode *expectList, struct ListNode *actualList) {
    int isSuccess = COMMON_TRUE;

    struct ListNode *curr1 = expectList, *curr2 = actualList;
    if (curr1 == NULL && curr2 == NULL) {
        isSuccess = COMMON_TRUE;
    } else {
        while (curr1 != NULL && curr2 != NULL) {
            if (curr1->val != curr2->val) {
                isSuccess = COMMON_FALSE;
                break;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
    }

    printf("=========================\n");
    if (isSuccess) {
        printf(" - ✅ Test %c Passed\n", testNum);
    } else {
        printf(" - ❌ Test %c Failed\n", testNum);
    }
    printf("=========================\n");
    printf("- Expect: "); LinkedList_Print(expectList);
    printf("- Actual: "); LinkedList_Print(actualList);
    printf("\n");
}


#endif      /* COMMON_LINKED_LIST_EN */
