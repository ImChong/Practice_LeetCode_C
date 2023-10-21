/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\02_Linked_List\01_removeElements\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-21 10:27:46
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 203. 移除链表元素：https://leetcode.cn/problems/remove-linked-list-elements/
 * https://programmercarl.com/0203.%E7%A7%BB%E9%99%A4%E9%93%BE%E8%A1%A8%E5%85%83%E7%B4%A0.html
 */
#include <stdio.h>
#include <stdlib.h>

/**********************************************************************************/
/*                                                                                */
/*                                MACRO FUNCTIONS                                 */
/*                                                                                */
/**********************************************************************************/
#define ARR_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))        /* 获取数组长度 */

/**********************************************************************************/
/*                                                                                */
/*                                 GLOBAL VARIABLES                               */
/*                                                                                */
/**********************************************************************************/
/* 节点定义 */
struct ListNode {
    int val;
    struct ListNode *next;
};

/**********************************************************************************/
/*                                                                                */
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 从数组创建链表
 * =================================================================================
 * @param {int} *array                  数组
 * @param {int} size                    数组大小
 * @return {struct ListNode} *head      头节点指针
 */
struct ListNode *arrayToLinkedList(int *array, int size) {
    struct ListNode *head = NULL;       /* 头节点指针 */
    struct ListNode *current = NULL;    /* 当前节点指针 */

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
            current->next = new_node;
        }
        current = new_node;
    }
    return head;
}

/**
 * @description: 打印链表
 * =================================================================================
 * @param {ListNode} *listPtr
 * @return {void}
 */
void printList(struct ListNode *listPtr) {
    while (listPtr != NULL) {
        printf("%d ", listPtr->val);
        listPtr = listPtr->next;
    }
    printf("\n");
}

/**
 * @description: 释放链表
 * =================================================================================
 * @param {ListNode} *listPtr
 * @return {void}
 */
void freeList(struct ListNode *listPtr) {
    if (listPtr == NULL) {
        return;
    }
    struct ListNode *tmp = NULL;
    while (listPtr != NULL) {
        tmp = listPtr;
        listPtr = listPtr->next;
        free(tmp);
    }
}

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/* TODO: 运行时长和内存占用可提升*/
/* ============================================================================== */
/* ============================================================================== */
/**
 * @description: 移除链表元素
 * =================================================================================
 * @param {ListNode} *head              链表虚拟头节点
 * @param {int} val                     目标值
 * @return {struct ListNode} *head      返回链表虚拟头节点
 */
struct ListNode *removeElements(struct ListNode *head, int val) {
    struct ListNode dummy;                          /* 创建虚拟头节点 */
    dummy.next = head;                              /* 将传入链表接在虚拟头节点后面 */

    struct ListNode *curr = &dummy;                 /* 创建指针：用于遍历列表 */
    while (curr->next != NULL) {                    /* 遍历链表 */
        if (curr->next->val == val) {                   /* 当前节点的下一个节点的值等于目标值 */
            struct ListNode *tmp = curr->next;              /* 保存当前节点的下一个节点 */
            curr->next = curr->next->next;                  /* 当前节点的下一个节点指向下下个节点 */
            free(tmp);                                      /* 释放当前节点的下一个节点 */
        } else {                                        /* 当前节点的下一个节点的值不等于目标值 */
            curr = curr->next;                              /* 当前节点指向下一个节点 */
        }
    }
    return dummy.next;                              /* 返回链表虚拟头节点 */
}

/**********************************************************************************/
/*                                                                                */
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 验证答案
 * =================================================================================
 * @param {char} testNum            测试编号
 * @param {ListNode} *expectList    预期
 * @param {ListNode} *ansList       结果
 * @return {void}
 */
void validateAnswer(char testNum, struct ListNode *expectList, struct ListNode *ansList) {
    struct ListNode *curr1 = expectList, *curr2 = ansList;
    while (curr1 != NULL && curr2 != NULL) {
        if (curr1->val != curr2->val) {
            printf("❌ Test %c Failed\n", testNum);
            return;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    if (curr1 == NULL && curr2 == NULL) {
        printf("✅ Test %c Passed\n", testNum);
    } else {
        printf("❌ Test %c Failed\n", testNum);
    }
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
    int nums[] = {1, 2, 6, 3, 4, 5, 6};
    int numsSize = ARR_SIZE(nums);
    struct ListNode *head = arrayToLinkedList(nums, numsSize);
    int removeVal = 6;
    struct ListNode *ansList = removeElements(head, removeVal);

    /* 预期结果 */
    int expectNums[] = {1, 2, 3, 4, 5};
    int expectLen = ARR_SIZE(expectNums);
    struct ListNode *expectList = arrayToLinkedList(expectNums, expectLen);

    /* 比较结果 */
    validateAnswer('1', expectList, ansList);

    /* 释放内存 */
    freeList(head);
    freeList(expectList);
}

/**
 * @description: 测试 2
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    /* 实际结果 */
    int nums[] = {1, 1, 1, 1, 1};
    int numsSize = ARR_SIZE(nums);
    struct ListNode *head = arrayToLinkedList(nums, numsSize);
    int removeVal = 1;
    struct ListNode *ansList = removeElements(head, removeVal);

    /* 预期结果 */
    int expectNums[] = {};
    int expectLen = ARR_SIZE(expectNums);
    struct ListNode *expectList = arrayToLinkedList(expectNums, expectLen);

    /* 比较结果 */
    validateAnswer('2', expectList, ansList);

    /* 释放内存 */
    // freeList(head);      /* head 内存已被 removeElements 释放，故无需再释放 */
    freeList(expectList);
}

/**
 * @description: 测试 3
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    /* 实际结果 */
    int nums[] = {1, 2, 3, 4, 5};
    int numsSize = ARR_SIZE(nums);
    struct ListNode *head = arrayToLinkedList(nums, numsSize);
    int removeVal = 6;
    struct ListNode *ansList = removeElements(head, removeVal);

    /* 预期结果 */
    int expectNums[] = {1, 2, 3, 4, 5};
    int expectLen = ARR_SIZE(expectNums);
    struct ListNode *expectList = arrayToLinkedList(expectNums, expectLen);

    /* 比较结果 */
    validateAnswer('3', expectList, ansList);

    /* 释放内存 */
    freeList(head);
    freeList(expectList);
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
int main(int argc, const char* argv[]) {
    test_1();
    test_2();
    test_3();
    return 0;
}