/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\02_Linked_List\06_getIntersectionNode\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-14 21:16:40
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 面试题 02.07. 链表相交：https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/
 * https://programmercarl.com/%E9%9D%A2%E8%AF%95%E9%A2%9802.07.%E9%93%BE%E8%A1%A8%E7%9B%B8%E4%BA%A4.html
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
 * @return {struct ListNode} *head      链表头指针
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
 * @param {ListNode} *listPtr           链表头指针
 * @param {char} listChar               链表标识字符
 * @return {void}
 */
void printList(struct ListNode *listPtr, char listChar) {
    printf("linked list %c: ", listChar);
    while (listPtr != NULL) {
        printf("%d ", listPtr->val);
        listPtr = listPtr->next;
    }
    printf("\n");
}

/**
 * @description: 释放链表内存
 * =================================================================================
 * @param {ListNode} *head              链表头指针
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
/*
    这段选中的代码实现了一个函数 getIntersectionNode，用于查找两个链表的交点。
    该函数接受两个链表 headA 和 headB 作为输入，如果存在交点，则返回交点，否则返回 NULL。

    该函数使用两个指针 pA 和 pB 分别指向链表 headA 和 headB 的头节点。
    然后，两个指针同时向后遍历链表，直到两个指针相遇，或者同时到达链表的末尾。如果两个指针相遇，则说明存在交点，返回交点；
    否则，返回 NULL。

    在遍历链表时，如果一个指针到达链表的末尾，则将其重定向到另一个链表的头节点，这样可以保证两个指针同时到达交点。
    这个过程可以通过两个指针的循环遍历来实现。

    该实现的时间复杂度为 O(m+n)，其中 m 和 n 分别是两个链表的长度。空间复杂度为 O(1)，因为只使用了两个指针来遍历链表。
    这个实现简单高效，易于理解。
*/
/* ============================================================================== */
/* ============================================================================== */
/**
 * @description: 获取两个链表的交点
 * =================================================================================
 * @param {ListNode} *headA     链表A头指针
 * @param {ListNode} *headB     链表B头指针
 * @return {*}
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *pA = headA;                /* 链表A指针 */
    struct ListNode *pB = headB;                /* 链表B指针 */
    while (pA != pB) {                          /* 循环条件：两个指针不相等 */
        pA = pA != NULL ? pA->next : headB;         /* 链表A指针后移 */
        pB = pB != NULL ? pB->next : headA;         /* 链表B指针后移 */
    }
    return pA;                                  /* 返回交点 */
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
 * listA: 4 -> 1 -> 8 -> 4 -> 5
 * listB: 5 -> 0 -> 1 -> 8 -> 4 -> 5
 * expected: 8
 * =================================================================================
 * @return {void}
 */
void test_1(void) {

}

/**
 * @description: 测试 2
 * listA: 0 -> 9 -> 1 -> 2 -> 4
 * listB: 3 -> 2 -> 4
 * expected: 2
 * =================================================================================
 * @return {void}
 */
void test_2(void) {

}

/**
 * @description: 测试 3
 * listA: 2 -> 6 -> 4
 * listB: 1 -> 5
 * expected: NULL
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
int main(int argc, const char* argv[]) {
    /* Case 1 */
    printf("======== Case 1 ======== \n");
    int arrA1[] = {4, 1, 8, 4, 5};
    struct ListNode *listA = arrayToLinkedList(arrA1, 5);
    printList(listA, 'A');

    int arrB1[] = {5, 0, 1};
    struct ListNode *listB = arrayToLinkedList(arrB1, 3);
    /* 将B链表挂载至A链表 */
    struct ListNode *current = listB;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = listA->next->next;
    printList(listB, 'B');

    struct ListNode *intersectNode = getIntersectionNode(listA, listB);
    if (intersectNode != NULL) {
        printf("Intersection: %d\n", intersectNode->val);
    } else {
        printf("Intersection: NULL\n");
    }

    /* Case 2 */
    printf("======== Case 2 ======== \n");
    int arrA2[] = {2, 6, 4};
    listA = arrayToLinkedList(arrA2, 3);
    printList(listA, 'A');

    int arrB2[] = {1, 5};
    listB = arrayToLinkedList(arrB2, 2);
    printList(listB, 'B');

    intersectNode = getIntersectionNode(listA, listB);
    if (intersectNode != NULL) {
        printf("Intersection: %d\n", intersectNode->val);
    } else {
        printf("Intersection: NULL\n");
    }

    return 0;
}