/* 707. 设计链表：https://leetcode.cn/problems/design-linked-list/ */
/* https://programmercarl.com/0707.%E8%AE%BE%E8%AE%A1%E9%93%BE%E8%A1%A8.html */

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;                /* 节点数值 */
    struct ListNode *next;  /* 下一节点地址 */
};

typedef struct {
    struct ListNode *head;     /* 链表虚拟头节点 */
    int size;           /* 链表长度 */
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList *obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));    /* 为虚拟头节点分配空间 */
    obj->head = NULL;       /* 初始化链表头 */
    obj->size = 0;          /* 初始化链表长度 */
    return obj;             /* 返回虚拟头节点 */
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) {      /* 输入校验 */
        return -1;
    }
    struct ListNode *curr = obj->head;     /* 指针指向链表头节点 */
    while (index-- > 0) {           /* 移动链表至指定索引，index > 0 因为初始的指针已经指向0索引 */
        curr = curr->next;
    }
    return curr->val;               /* 返回对应节点数值 */
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    struct ListNode *newHead = (struct ListNode*)malloc(sizeof(struct ListNode));    /* 为链表新头节点分配空间*/
    newHead->val = val;             /* 为链表新头节点赋值 */
    newHead->next = obj->head;      /* 将链表新头节点的下一节点设置为链表旧头节点 */
    obj->head = newHead;            /* 将虚拟头节点指向的链表头节点设置为链表新头节点 */
    obj->size++;                    /* 链表长度 + 1 */
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    struct ListNode *newTail = (struct ListNode*)malloc(sizeof(struct ListNode));    /* 为链表新尾节点分配空间*/
    newTail->val = val;             /* 为链表新尾节点赋值 */
    newTail->next = NULL;           /* 尾节点的下一节点为 NULL*/

    if (obj->head == NULL) {            /* 如果虚拟头节点指向的头节点为 NULL*/
        obj->head = newTail;                /* 设置当前链表新尾节点为链表头节点 */
    } else {                            /* 反之 */
        struct ListNode *curr = obj->head;         /* 获取当前链表头节点的指针 */
        while (curr->next != NULL) {        /* 当当前指针所指节点的下一节点不为 NULL 时 */
            curr = curr->next;                  /* 指针向后移动一位 */
        }
        curr->next = newTail;               /* 当当前指针所指节点的下一节点为 NULL 时，将当前指针的下一节点设置为链表新尾节点 */
    }
    obj->size++;                        /* 链表长度 + 1 */
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
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
    newNode->val = val;                                         /* 为链表新节点赋值 */

    struct ListNode *curr = obj->head;                                 /* 获取当前链表头节点的指针 */
    for (int i = 0; i < index - 1; i++) {                       /* 因为新节点自己本身要占据一个节点位置，所以循环索引 - 1 次 */
        curr = curr->next;                                          /* 指针向后移动一位 */
    }

    newNode->next = curr->next;                                 /* 将新节点的下一节点指向当前指针所指节点的下一节点*/
    curr->next = newNode;                                       /* 将当前指针所指节点的下一节点指向新节点 */
    obj->size++;                                                /* 链表长度 + 1 */
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) {       /* 输入校验 */
        return;
    }

    struct ListNode *curr = obj->head;                 /* 获取当前链表头节点的指针 */
    if (index == 0) {                           /* 如果删除头节点 */
        obj->head = curr->next;                    /* 将虚拟头节点所指向的链表头节点指向当前指针的下一节点 */
    } else {                                    /* 如果删除中间节点 */
        for (int i = 0; i < index - 1; i++) {       /* 因为目标节点自己本身要占据一个节点位置，所以循环索引 - 1 次 */
            curr = curr->next;                          /* 指针向后移动一位 */
        }
        if (curr->next) {                           /* 如果当前指针所指节点的下一节点存在*/
            struct ListNode* tmp = curr->next;                 /* 获取待删除节点的指针 */
            curr->next = curr->next->next;              /* 将待删除节点上一节点的下一节点改为待删除节点的下一节点*/
            free(tmp);                                  /* 释放待删除节点内存空间 */
        }
    }
    obj->size--;                                /* 链表长度 - 1 */
}

void myLinkedListFree(MyLinkedList* obj) {
    struct ListNode *curr = obj->head;     /* 获取当前链表头节点的指针 */
    while (curr != NULL) {          /* 当指针所指的节点不为NULL时 */
        struct ListNode *tmp = curr;           /* 获取当前节点的指针 */
        curr = curr->next;              /* 指针向后移动一位 */
        free(tmp);                      /* 释放当前指针所指节点的内存空间 */
    }
    free(obj);                      /* 释放虚拟头节点的内存空间 */
}

/* 打印链表 */
void printLinkedList(MyLinkedList *list) {
    printf("linked list (size: %d): ", list->size);
    for (int i = 0; i < list->size; i++) {
        printf("%d ", myLinkedListGet(list, i));
    }
    printf("\n");
}

/* 主函数 */
int main(int argc, const char* argv[]) {
    /* NOTE: Case1 */
    // MyLinkedList *list = myLinkedListCreate();

    // myLinkedListAddAtHead(list, 1);
    // myLinkedListAddAtTail(list, 3);
    // myLinkedListAddAtIndex(list, 1, 2);

    // printf("linked list: ");
    // for (int i = 0; i < list->size; i++) {
    //     printf("%d ", myLinkedListGet(list, i));
    // }
    // printf("\n");

    // printf("%d ", myLinkedListGet(list, 1));
    // myLinkedListDeleteAtIndex(list, 0);
    // printf("%d ", myLinkedListGet(list, 0));

    // printf("\n");

    // printf("linked list: ");
    // for (int i = 0; i < list->size; i++) {
    //     printf("%d ", myLinkedListGet(list, i));
    // }
    // printf("\n");

    // myLinkedListFree(list);

    /* NOTE: Case2 */
    // /* ["MyLinkedList","addAtHead","deleteAtIndex","addAtHead","addAtHead","addAtHead","addAtHead","addAtHead","addAtTail","get","deleteAtIndex","deleteAtIndex"] */
    // /* [[],[2],[1],[2],[7],[3],[2],[5],[5],[5],[6],[4]] */

    // MyLinkedList *list = myLinkedListCreate();      /* MyLinkedList     [] */
    // myLinkedListAddAtHead(list, 2);                 /* addAtHead        [2] */
    // myLinkedListDeleteAtIndex(list, 1);             /* deleteAtIndex    [1] */
    // myLinkedListAddAtHead(list, 2);                 /* addAtHead        [2] */
    // myLinkedListAddAtHead(list, 7);                 /* addAtHead        [7] */
    // myLinkedListAddAtHead(list, 3);                 /* addAtHead        [3] */
    // myLinkedListAddAtHead(list, 2);                 /* addAtHead        [2] */
    // myLinkedListAddAtHead(list, 5);                 /* addAtHead        [5] */
    // myLinkedListAddAtTail(list, 5);                 /* addAtTail        [5] */
    // myLinkedListGet(list, 5);                       /* get          [5] */
    // myLinkedListDeleteAtIndex(list, 6);             /* deleteAtIndex    [6] */
    // myLinkedListDeleteAtIndex(list, 4);             /* deleteAtIndex    [4] */

    // printf("linked list: ");
    // for (int i = 0; i < list->size; i++) {
    //     printf("%d ", myLinkedListGet(list, i));
    // }
    // printf("\n");

    // myLinkedListFree(list);

    /* NOTE: Case3 */
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

    printLinkedList(list);

    return 0;
}