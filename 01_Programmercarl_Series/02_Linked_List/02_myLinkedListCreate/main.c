/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\02_Linked_List\02_myLinkedListCreate\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-13 20:08:09
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 707. 设计链表：https://leetcode.cn/problems/design-linked-list/
 * https://programmercarl.com/0707.%E8%AE%BE%E8%AE%A1%E9%93%BE%E8%A1%A8.html
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
struct ListNode {
    int val;                    /* 节点数值 */
    struct ListNode *next;      /* 下一节点地址 */
};

typedef struct {
    struct ListNode *head;      /* 链表虚拟头节点 */
    int size;                   /* 链表长度 */
} MyLinkedList;

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 创建链表
 * =================================================================================
 * @return {MyLinkedList} *obj      返回虚拟头节点
 */
MyLinkedList *myLinkedListCreate() {
    MyLinkedList *obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));    /* 为虚拟头节点分配空间 */
    obj->head = NULL;       /* 初始化链表头 */
    obj->size = 0;          /* 初始化链表长度 */
    return obj;             /* 返回虚拟头节点 */
}

/**
 * @description: 获取指定索引的节点数值
 * =================================================================================
 * @param {MyLinkedList} *obj       虚拟头节点
 * @param {int} index               索引
 * @return {int} ans                返回指定索引的节点数值
 */
int myLinkedListGet(MyLinkedList *obj, int index) {
    if (index < 0 || index >= obj->size) {      /* 输入校验 */
        return -1;                                  /* 返回 -1 */
    }
    struct ListNode *curr = obj->head;          /* 获取当前链表头节点的指针 */
    while (index-- > 0) {                       /* 循环索引次 */
        curr = curr->next;                          /* 指针向后移动一位 */
    }
    return curr->val;                           /* 返回指定索引的节点数值 */
}

/**
 * @description: 在链表头部添加新节点
 * =================================================================================
 * @param {MyLinkedList} *obj       虚拟头节点
 * @param {int} val                 新节点数值
 * @return {void}
 */
void myLinkedListAddAtHead(MyLinkedList *obj, int val) {
    struct ListNode *newHead = (struct ListNode*)malloc(sizeof(struct ListNode));    /* 为链表新头节点分配空间*/
    newHead->val = val;             /* 为链表新头节点赋值 */
    newHead->next = obj->head;      /* 将链表新头节点的下一节点设置为链表旧头节点 */
    obj->head = newHead;            /* 将虚拟头节点指向的链表头节点设置为链表新头节点 */
    obj->size++;                    /* 链表长度 + 1 */
}

/**
 * @description: 在链表尾部添加新节点
 * =================================================================================
 * @param {MyLinkedList} *obj       虚拟头节点
 * @param {int} val                 新节点数值
 * @return {void}
 */
void myLinkedListAddAtTail(MyLinkedList *obj, int val) {
    struct ListNode *newTail = (struct ListNode*)malloc(sizeof(struct ListNode));    /* 为链表新尾节点分配空间*/
    newTail->val = val;                         /* 为链表新尾节点赋值 */
    newTail->next = NULL;                       /* 将链表新尾节点的下一节点设置为NULL */

    if (obj->head == NULL) {                    /* 如果链表为空 */
        obj->head = newTail;                        /* 将虚拟头节点指向的链表头节点设置为链表新尾节点 */
    } else {                                    /* 如果链表不为空 */
        struct ListNode *curr = obj->head;          /* 获取当前链表头节点的指针 */
        while (curr->next != NULL) {                /* 当指针所指的节点不为NULL时 */
            curr = curr->next;                          /* 指针向后移动一位 */
        }
        curr->next = newTail;                       /* 将当前指针所指节点的下一节点指向新节点 */
    }
    obj->size++;                                /* 链表长度 + 1 */
}

/**
 * @description: 在指定索引处插入新节点
 * =================================================================================
 * @param {MyLinkedList} *obj       虚拟头节点
 * @param {int} index               索引
 * @param {int} val                 新节点数值
 * @return {void}
 */
void myLinkedListAddAtIndex(MyLinkedList *obj, int index, int val) {
    if (index < 0 || index > obj->size) {       /* 输入校验 */
        return;
    }

    if (index == 0) {                           /* 插入新头节点 */
        myLinkedListAddAtHead(obj, val);
        return;
    }

    if (index == obj->size) {                   /* 插入新尾节点 */
        myLinkedListAddAtTail(obj, val);
        return;
    }

    struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));    /* 为链表新节点分配空间 */
    newNode->val = val;                         /* 为链表新节点赋值 */

    struct ListNode *curr = obj->head;          /* 获取当前链表头节点的指针 */
    for (int i = 0; i < index - 1; i++) {       /* 因为新节点自己本身要占据一个节点位置，所以循环索引 - 1 次 */
        curr = curr->next;                          /* 指针向后移动一位 */
    }

    newNode->next = curr->next;                 /* 将新节点的下一节点指向当前指针所指节点的下一节点*/
    curr->next = newNode;                       /* 将当前指针所指节点的下一节点指向新节点 */
    obj->size++;                                /* 链表长度 + 1 */
}

/**
 * @description: 删除指定索引的节点
 * =================================================================================
 * @param {MyLinkedList} *obj       虚拟头节点
 * @param {int} index               索引
 * @return {void}
 */
void myLinkedListDeleteAtIndex(MyLinkedList *obj, int index) {
    if (index < 0 || index >= obj->size) {      /* 输入校验 */
        return;
    }

    struct ListNode *curr = obj->head;          /* 获取当前链表头节点的指针 */
    if (index == 0) {                           /* 如果删除头节点 */
        obj->head = curr->next;                    /* 将虚拟头节点所指向的链表头节点指向当前指针的下一节点 */
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
    obj->size--;                                /* 链表长度 - 1 */
}

/**
 * @description: 释放链表内存空间
 * =================================================================================
 * @param {MyLinkedList} *obj       虚拟头节点
 * @return {void}
 */
void myLinkedListFree(MyLinkedList *obj) {
    struct ListNode *curr = obj->head;      /* 获取当前链表头节点的指针 */
    while (curr != NULL) {                  /* 当指针所指的节点不为NULL时 */
        struct ListNode *tmp = curr;            /* 获取当前节点的指针 */
        curr = curr->next;                      /* 指针向后移动一位 */
        free(tmp);                              /* 释放当前指针所指节点的内存空间 */
    }
    free(obj);                              /* 释放虚拟头节点的内存空间 */
}

/**********************************************************************************/
/*                                                                                */
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 打印链表
 * =================================================================================
 * @param {MyLinkedList} *list      虚拟头节点
 * @return {void}
 */
void printLinkedList(MyLinkedList *list) {
    printf("linked list (size: %d): ", list->size);     /* 打印链表长度 */
    for (int i = 0; i < list->size; i++) {              /* 循环打印链表节点数值 */
        printf("%d ", myLinkedListGet(list, i));            /* 打印链表节点数值 */
    }
    printf("\n");                                       /* 换行 */
}

/**
 * @description: 验证答案
 * =================================================================================
 * @param {char} testNum
 * @param {MyLinkedList} *expect
 * @param {MyLinkedList} *actual
 * @return {*}
 */
void validateAnswer(char testNum, MyLinkedList *expect, MyLinkedList *actual) {
    for (int i = 0; i < expect->size; i++) {
        if (myLinkedListGet(expect, i) != myLinkedListGet(actual, i)) {
            printf("❌ Test %c Failed\n", testNum);
            return;
        }
    }
    printf("✅ Test %c Passed\n", testNum);
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
    MyLinkedList *actualDummy = myLinkedListCreate();

    myLinkedListAddAtHead(actualDummy, 1);
    myLinkedListAddAtTail(actualDummy, 3);
    myLinkedListAddAtIndex(actualDummy, 1, 2);
    myLinkedListDeleteAtIndex(actualDummy, 0);
    printLinkedList(actualDummy);

    /* 预期结果 */
    MyLinkedList *expectDummy = myLinkedListCreate();
    myLinkedListAddAtTail(expectDummy, 2);
    myLinkedListAddAtTail(expectDummy, 3);

    /* 比较结果 */
    validateAnswer('1', expectDummy, actualDummy);

    /* 释放内存空间 */
    myLinkedListFree(actualDummy);
}

/**
 * @description: 测试 2
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    printf("==================== \n");
    printf("test_2: \n");

    /* ["MyLinkedList","addAtHead","deleteAtIndex","addAtHead","addAtHead","addAtHead","addAtHead","addAtHead","addAtTail","get","deleteAtIndex","deleteAtIndex"] */
    /* [[],[2],[1],[2],[7],[3],[2],[5],[5],[5],[6],[4]] */

    MyLinkedList *list = myLinkedListCreate();      /* MyLinkedList     [] */
    myLinkedListAddAtHead(list, 2);                 /* addAtHead        [2] */
    myLinkedListDeleteAtIndex(list, 1);             /* deleteAtIndex    [1] */
    myLinkedListAddAtHead(list, 2);                 /* addAtHead        [2] */
    myLinkedListAddAtHead(list, 7);                 /* addAtHead        [7] */
    myLinkedListAddAtHead(list, 3);                 /* addAtHead        [3] */
    myLinkedListAddAtHead(list, 2);                 /* addAtHead        [2] */
    myLinkedListAddAtHead(list, 5);                 /* addAtHead        [5] */
    myLinkedListAddAtTail(list, 5);                 /* addAtTail        [5] */
    myLinkedListGet(list, 5);                       /* get              [5] */
    myLinkedListDeleteAtIndex(list, 6);             /* deleteAtIndex    [6] */
    myLinkedListDeleteAtIndex(list, 4);             /* deleteAtIndex    [4] */

    printf("linked list: ");
    for (int i = 0; i < list->size; i++) {
        printf("%d ", myLinkedListGet(list, i));
    }
    printf("\n");

    /* 释放内存空间 */
    myLinkedListFree(list);
}

/**
 * @description: 测试 3
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    printf("==================== \n");
    printf("test_3: \n");

    /* ["MyLinkedList","addAtHead","get","addAtHead","addAtHead","deleteAtIndex","addAtHead","get","get","get","addAtHead","deleteAtIndex"] */
    /* [[],[4],[1],[1],[5],[3],[7],[3],[3],[3],[1],[4]] */
    /* [null,null,-1,null,null,null,null,4,4,4,null,null] */

    MyLinkedList *list = myLinkedListCreate();  /* MyLinkedList     [ ] */
    myLinkedListAddAtHead(list, 4);             /* addAtHead        [4] */

    printLinkedList(list);

    myLinkedListGet(list, 1);                   /* get              [1] */
    myLinkedListAddAtHead(list, 1);             /* addAtHead        [1] */
    myLinkedListAddAtHead(list, 2);             /* addAtHead        [2] */

    printLinkedList(list);

    myLinkedListDeleteAtIndex(list, 3);         /* deleteAtIndex    [3] */
    myLinkedListAddAtHead(list, 7);             /* addAtHead        [7] */

    printLinkedList(list);

    printf("%d \n", myLinkedListGet(list, 3));  /* get              [3] */
    printf("%d \n", myLinkedListGet(list, 3));  /* get              [3] */
    printf("%d \n", myLinkedListGet(list, 3));  /* get              [3] */
    myLinkedListAddAtHead(list, 1);             /* addAtHead        [1] */
    myLinkedListDeleteAtIndex(list, 4);         /* deleteAtIndex    [4] */

    /* 释放内存空间 */
    printLinkedList(list);
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
    // test_2();
    // test_3();
    return 0;
}