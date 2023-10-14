/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\02_Linked_List\05_removeNthFromEnd\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-14 20:28:56
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 19. 删除链表的倒数第 N 个结点：https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
 * https://programmercarl.com/0019.%E5%88%A0%E9%99%A4%E9%93%BE%E8%A1%A8%E7%9A%84%E5%80%92%E6%95%B0%E7%AC%ACN%E4%B8%AA%E8%8A%82%E7%82%B9.html
 */
#include <stdio.h>
#include <stdlib.h>

/**********************************************************************************/
/*                                                                                */
/*                                MACRO FUNCTIONS                                 */
/*                                                                                */
/**********************************************************************************/
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))        /* 获取数组长度 */

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
/*                                 UTILITY FUNCTIONS                              */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 创建链表，不使用虚拟头结点
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
    printf("linked list: ");
    while (listPtr != NULL) {
        printf("%d ", listPtr->val);
        listPtr = listPtr->next;
    }
    printf("\n");
}

/**
 * @description: 释放链表内存
 * =================================================================================
 * @param {ListNode} *head      链表头指针
 * @return {void}
 */
void freeLinkedList(struct ListNode *head) {
    struct ListNode *current = head;
    while (current != NULL) {
        struct ListNode *temp = current;
        current = current->next;
        free(temp);
    }
}

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 删除链表的倒数第 N 个结点
 * =================================================================================
 * @param {ListNode*} head
 * @param {int} n
 * @return {struct ListNode} *head
 */
struct ListNode *removeNthFromEnd(struct ListNode* head, int n){
    if (!head || n <= 0) {                  /* 如果头节点不存在 或 n <= 0 时 */
        return head;                            /* 返回头节点 */
    }

    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));     /* 初始化虚拟头节点 */
    dummy->val = 0;                         /* 虚拟头节点值为0 */
    dummy->next = head;                     /* 虚拟头节点的下一节点指向链表头节点 */

    struct ListNode *first = dummy;         /* 设置第一指针指向虚拟头节点的位置 */
    struct ListNode *second = dummy;        /* 设置第二指针指向虚拟头节点的位置 */

    for (int i = 0; i <= n; i++) {          /* 循环 n + 1 次：需要末尾 NULL 作为循环结束条件，故 n + 1 */
        if (first != NULL) {                    /* 如果第一指针没有指向 NULL */
            first = first->next;                    /* 将第一指针向后移动一个位置 */
        } else {                                /* 循环过程中第一指针指向了 NULL */
            return head;                            /* 则返回头节点，代表出界 */
        }
    }

    while (first != NULL) {                 /* 当第一指针未指向 NULL 时循环 */
        first = first->next;                    /* 第一指针向后移动一个位置 */
        second = second->next;                  /* 第二指针向后移动一个位置，直到第二指针指向待删除节点的前一节点 */
    }

    struct ListNode *tmp = second->next;    /* 用一个临时指针储存第二指针所指的下一节点：待删除节点 */
    second->next = second->next->next;      /* 将第二指针的下一节点指向下下节点 */
    free(tmp);                              /* 删除指定节点 */

    struct ListNode *newHead = dummy->next; /* 设置链表头节点为虚拟头节点的下一节点 */
    free(dummy);                            /* 删除虚拟头节点 */
    return newHead;                         /* 返回链表头节点 */
}

/**********************************************************************************/
/*                                                                                */
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 验证答案
 * =================================================================================
 * @param {char} testNum    测试编号
 * @param {int} expect      预期
 * @param {int} actual      实际
 * @return {void}
 */
void validateAnswer(char testNum, int expect, int actual) {
    if (expect == actual) {
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
    int arr[] = {1, 2, 3, 4, 5};
    int arrSize = ARRAY_SIZE(arr);
    struct ListNode *newList = createList(arr, arrSize);

    /* 预期结果 */

    /* 比较结果 */

}

/**
 * @description: 测试 2
 * =================================================================================
 * @return {void}
 */
void test_2(void) {

}

/**
 * @description: 测试 3
 * =================================================================================
 * @return {void}
 */
void test_3(void) {

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
int main(int argc, char const *argv[]) {
    int arr[5] = {1, 2, 3, 4, 5};
    struct ListNode *newList = createList(arr, 5);
    printList(newList);

    /* Case 1 */
    printf("======== Case 1 ======== \n");
    struct ListNode *ansList = removeNthFromEnd(newList, 2);
    printList(ansList);

    /* Case 2 */
    printf("======== Case 2 ======== \n");
    ansList = removeNthFromEnd(newList, 3);
    printList(ansList);

    /* Case 3 */
    printf("======== Case 3 ======== \n");
    ansList = removeNthFromEnd(newList, 5);
    printList(ansList);

    return 0;
}