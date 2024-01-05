/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\src\commonLinkedListDummy.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 10:33:34
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-02 18:51:31
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用虚拟头节点链表源文件 - 使用虚拟头节点
 */
/* 编译配置文件 */
#include "compileCfg.h"
#if COMMON_LINKED_LIST_DUMMY_EN         /* 在每一道题 cfg 文件夹下的 compileCfg.h 开启编译宏定义 */
/* standard header file (标准头文件) */
#include <stdio.h>
#include <stdlib.h>
/* 常用头文件 */
#include "commonTypeDef.h"
#include "commonLinkedListDummy.h"

/**********************************************************************************/
/*                                                                                */
/*                                 UTILITY FUNCTIONS                              */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 创建链表
 * =================================================================================
 * @return {DummyLinkedList *} dummyHead    返回虚拟头节点
 */
DummyLinkedList *DLinkedList_Create(void) {
    DummyLinkedList *dummyHead = (DummyLinkedList*)malloc(sizeof(DummyLinkedList)); /* NOLINT(readability/casting) */
    dummyHead->head = NULL;       /* 初始化链表头 */
    dummyHead->size = 0;          /* 初始化链表长度 */
    return dummyHead;             /* 返回虚拟头节点 */
}

/**
 * @description: 获取指定索引的节点数值
 * =================================================================================
 * @param {DummyLinkedList *} dummyHead     虚拟头节点
 * @param {int} index                       索引
 * @return {int} ans                        返回指定索引的节点数值
 */
int DLinkedList_Get(DummyLinkedList *dummyHead, int index) {
    if (index < 0 || index >= dummyHead->size) {        /* 输入校验 */
        return -1;                                          /* 返回 -1 */
    }
    struct ListNode *curr = dummyHead->head;            /* 获取当前链表头节点的指针 */
    while (index-- > 0) {                               /* 循环索引次 */
        curr = curr->next;                                  /* 指针向后移动一位 */
    }
    return curr->val;                                   /* 返回指定索引的节点数值 */
}

/**
 * @description: 在链表头部添加新节点
 * =================================================================================
 * @param {DummyLinkedList *} dummyHead     虚拟头节点
 * @param {int} val                         新节点数值
 * @return {void}
 */
void DLinkedList_AddAtHead(DummyLinkedList *dummyHead, int val) {
    struct ListNode *newHead = (struct ListNode*)malloc(sizeof(struct ListNode));    /* 为链表新头节点分配空间*/
    newHead->val = val;                     /* 为链表新头节点赋值 */
    newHead->next = dummyHead->head;        /* 将链表新头节点的下一节点设置为链表旧头节点 */
    dummyHead->head = newHead;              /* 将虚拟头节点指向的链表头节点设置为链表新头节点 */
    dummyHead->size++;                      /* 链表长度 + 1 */
}

/**
 * @description: 在链表尾部添加新节点
 * =================================================================================
 * @param {DummyLinkedList *} dummyHead     虚拟头节点
 * @param {int} val                         新节点数值
 * @return {void}
 */
void DLinkedList_AddAtTail(DummyLinkedList *dummyHead, int val) {
    struct ListNode *newTail = (struct ListNode*)malloc(sizeof(struct ListNode));    /* 为链表新尾节点分配空间*/
    newTail->val = val;                                 /* 为链表新尾节点赋值 */
    newTail->next = NULL;                               /* 将链表新尾节点的下一节点设置为NULL */

    if (dummyHead->head == NULL) {                      /* 如果链表为空 */
        dummyHead->head = newTail;                          /* 将虚拟头节点指向的链表头节点设置为链表新尾节点 */
    } else {                                            /* 如果链表不为空 */
        struct ListNode *curr = dummyHead->head;            /* 获取当前链表头节点的指针 */
        while (curr->next != NULL) {                        /* 当指针所指的节点不为NULL时 */
            curr = curr->next;                                  /* 指针向后移动一位 */
        }
        curr->next = newTail;                               /* 将当前指针所指节点的下一节点指向新节点 */
    }
    dummyHead->size++;                                  /* 链表长度 + 1 */
}

/**
 * @description: 在指定索引处插入新节点
 * =================================================================================
 * @param {DummyLinkedList *} dummyHead     虚拟头节点
 * @param {int} index                       索引
 * @param {int} val                         新节点数值
 * @return {void}
 */
void DLinkedList_AddAtIndex(DummyLinkedList *dummyHead, int index, int val) {
    if (index < 0 || index > dummyHead->size) {         /* 输入校验 */
        return;
    }

    if (index == 0) {                                   /* 插入新头节点 */
        DLinkedList_AddAtHead(dummyHead, val);
        return;
    }

    if (index == dummyHead->size) {                     /* 插入新尾节点 */
        DLinkedList_AddAtTail(dummyHead, val);
        return;
    }

    struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));    /* 为链表新节点分配空间 */
    newNode->val = val;                                 /* 为链表新节点赋值 */

    struct ListNode *curr = dummyHead->head;            /* 获取当前链表头节点的指针 */
    for (int i = 0; i < index - 1; i++) {               /* 因为新节点自己本身要占据一个节点位置，所以循环索引 - 1 次 */
        curr = curr->next;                                  /* 指针向后移动一位 */
    }

    newNode->next = curr->next;                         /* 将新节点的下一节点指向当前指针所指节点的下一节点*/
    curr->next = newNode;                               /* 将当前指针所指节点的下一节点指向新节点 */
    dummyHead->size++;                                  /* 链表长度 + 1 */
}

/**
 * @description: 删除指定索引的节点
 * =================================================================================
 * @param {DummyLinkedList *} dummyHead     虚拟头节点
 * @param {int} index                       索引
 * @return {void}
 */
void DLinkedList_DeleteAtIndex(DummyLinkedList *dummyHead, int index) {
    if (index < 0 || index >= dummyHead->size) {        /* 输入校验 */
        return;
    }

    struct ListNode *curr = dummyHead->head;            /* 获取当前链表头节点的指针 */
    if (index == 0) {                                   /* 如果删除头节点 */
        dummyHead->head = curr->next;                       /* 将虚拟头节点所指向的链表头节点指向当前指针的下一节点 */
    } else {                                            /* 如果删除中间节点 */
        for (int i = 0; i < index - 1; i++) {               /* 目标节点自己本身要占据一节点位置，所以循环索引-1次 */
            curr = curr->next;                                  /* 指针向后移动一位 */
        }
        if (curr->next) {                                   /* 如果当前指针所指节点的下一节点存在*/
            struct ListNode* tmp = curr->next;                  /* 获取待删除节点的指针 */
            curr->next = curr->next->next;                      /* 将待删除节点上节点的下节点改为待删除节点的下节点 */
            free(tmp);                                          /* 释放待删除节点内存空间 */
        }
    }
    dummyHead->size--;                                  /* 链表长度 - 1 */
}

/**
 * @description: 从链表中删除值为val的所有节点
 * =================================================================================
 * @param {DummyLinkedList *} dummyHead     虚拟头节点
 * @param {int} val                         目标值
 * @return {void}
 */
void DLinkedList_DeleteValue(DummyLinkedList *dummyHead, int val) {
    struct ListNode dummy;                          /* 创建虚拟头节点 */
    dummy.next = dummyHead->head;                   /* 将传入链表接在虚拟头节点后面 */

    struct ListNode *curr = &dummy;                 /* 创建指针：用于遍历列表 */
    while (curr->next != NULL) {                    /* 遍历链表 */
        if (curr->next->val == val) {                   /* 当前节点的下一个节点的值等于目标值 */
            struct ListNode *tmp = curr->next;              /* 保存当前节点的下一个节点 */
            curr->next = curr->next->next;                  /* 当前节点的下一个节点指向下下个节点 */
            free(tmp);                                      /* 释放当前节点的下一个节点 */
            dummyHead->size--;                              /* 链表长度 - 1 */
        } else {                                        /* 当前节点的下一个节点的值不等于目标值 */
            curr = curr->next;                              /* 指针向后移动一位 */
        }
    }
    dummyHead->head = dummy.next;                   /* 将虚拟头节点指向的链表头节点设置为链表新头节点 */
}

/**
 * @description: 获取链表中值为val的所有节点的索引
 * =================================================================================
 * @param {DummyLinkedList *} dummyHead     虚拟头节点
 * @param {int} val                         目标值
 * @param {int *} returnSize                返回索引数组的大小 / 值为val的节点个数
 * @return {int *} indexes                  返回索引数组
 */
int *DLinkedList_GetIndexes(DummyLinkedList *dummyHead, int val, int *returnSize) {
    int *indexes = (int *)malloc(sizeof(int) * dummyHead->size);    /* NOLINT(readability/casting) */
    int listIndex = 0;                                              /* 链表索引 */
    int elementIndex = 0;                                           /* 元素索引 */
    struct ListNode *curr = dummyHead->head;                        /* 获取当前链表头节点的指针 */
    while (curr != NULL) {                                          /* 当指针所指的节点不为NULL时 */
        if (curr->val == val) {                                         /* 当前节点的值等于目标值 */
            indexes[elementIndex++] = listIndex;                            /* 将当前节点的索引添加到索引数组中 */
        }
        curr = curr->next;                                              /* 指针向后移动一位 */
        listIndex++;                                                    /* 链表索引 + 1 */
    }
    *returnSize = elementIndex;                                     /* 返回索引数组的大小 */
    return indexes;                                                 /* 返回索引数组 */
}

/**********************************************************************************/
/*                                                                                */
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 将数组转换为链表
 * =================================================================================
 * @param {DummyLinkedList} *list      虚拟头节点
 * @param {int} *nums               数组
 * @param {int} numsSize            数组大小
 * @return {void}
 */
void DLinkedList_FromArray(DummyLinkedList *list, int *nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        DLinkedList_AddAtTail(list, nums[i]);
    }
}

/**
 * @description: 打印链表
 * =================================================================================
 * @param {DummyLinkedList} *list      虚拟头节点
 * @return {void}
 */
void DLinkedList_Print(DummyLinkedList *list) {
    printf("linked list (size: %d): Dummy -> ", list->size);    /* 打印链表长度 */

    for (int i = 0; i < list->size; i++) {                      /* 循环打印链表节点数值 */
        printf("%d", DLinkedList_Get(list, i));                  /* 打印链表节点数值 */
        if (i < list->size - 1) {                                   /* 如果不是最后一个节点 */
            printf(" -> ");                                             /* 打印箭头 */
        }
    }
    printf("\n");                                               /* 换行 */
}

/**
 * @description: 释放链表内存空间
 * =================================================================================
 * @param {DummyLinkedList} *dummyHead
 * @return {void}
 */
void dummyLinkedListFree(DummyLinkedList *dummyHead) {
    struct ListNode *curr = dummyHead->head;        /* 获取当前链表头节点的指针 */
    while (curr != NULL) {                          /* 当指针所指的节点不为NULL时 */
        struct ListNode *tmp = curr;                    /* 获取当前节点的指针 */
        curr = curr->next;                              /* 指针向后移动一位 */
        free(tmp);                                      /* 释放当前指针所指节点的内存空间 */
    }
    free(dummyHead);                                /* 释放虚拟头节点的内存空间 */
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
 * @param {DummyLinkedList} *expect    预期
 * @param {DummyLinkedList} *actual    实际
 * @return {void}
 */
void validateDummyLinkedList(char testNum, DummyLinkedList *expect, DummyLinkedList *actual) {
    int isSuccess = COMMON_TRUE;                                                /* 是否通过测试 */

    for (int i = 0; i < expect->size; i++) {                                    /* 循环比较每个节点的数值 */
        if (DLinkedList_Get(expect, i) != DLinkedList_Get(actual, i)) {       /* 如果节点数值不相等 */
            isSuccess = COMMON_FALSE;                                                   /* 未通过测试 */
            break;                                                                      /* 跳出循环 */
        }
    }

    printf("=========================\n");                                      /* 打印分割线 */
    if (isSuccess) {                                                            /* 如果通过测试 */
        printf(" - ✅ Test %c Passed\n", testNum);                                  /* 打印通过信息 */
    } else {                                                                    /* 如果未通过测试 */
        printf(" - ❌ Test %c Failed\n", testNum);                                  /* 打印未通过信息 */
    }
    printf("=========================\n");                                      /* 打印分割线 */
    printf("- Expect: "); DLinkedList_Print(expect);                         /* 打印预期结果 */
    printf("- Actual: "); DLinkedList_Print(actual);                         /* 打印实际结果 */
    printf("\n");
}


#endif      /* COMMON_LINKED_LIST_DUMMY_EN */
