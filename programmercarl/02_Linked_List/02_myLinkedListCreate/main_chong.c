/* 707. 设计链表：https://leetcode.cn/problems/design-linked-list/ */
/* https://programmercarl.com/0707.%E8%AE%BE%E8%AE%A1%E9%93%BE%E8%A1%A8.html */
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;                /* 节点数值 */
    struct ListNode *next;  /* 下一节点地址 */
} ListNode;

/* DONE: 目标函数 */
typedef struct {
    ListNode *head;     /* 链表虚拟头节点 */
    int size;           /* 链表尺寸 */
} MyLinkedList;

/* DONE: 目标函数 */
MyLinkedList* myLinkedListCreate() {
    MyLinkedList *obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));    /* 为虚拟头节点分配空间 */
    obj->head = NULL;       /* 初始化链表头 */
    obj->size = 0;          /* 初始化链表长度 */
    return obj;             /* 返回虚拟头节点 */
}

/* DONE: 目标函数 */
int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) {      /* 输入校验 */
        return -1;
    }
    ListNode *curr = obj->head;     /* 指针指向链表头节点 */
    while (index-- > 0) {           /* 移动链表至指定索引，index > 0 因为初始的指针已经指向0索引 */
        curr = curr->next;
    }
    return curr->val;               /* 返回对应节点数值 */
}

/* DONE: 目标函数 */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    ListNode *newHead = (ListNode*)malloc(sizeof(ListNode));    /* 为链表新头节点分配空间*/
    newHead->val = val;             /* 为链表新头节点赋值 */
    newHead->next = obj->head;      /* 将链表新头节点的下一节点设置为链表旧头节点 */
    obj->head = newHead;            /* 将虚拟头节点指向的链表头节点设置为链表新头节点 */
    obj->size++;                    /* 链表大小 + 1 */
}

/* DONE: 目标函数 */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    ListNode *newTail = (ListNode*)malloc(sizeof(ListNode));    /* 为链表新尾节点分配空间*/
    newTail->val = val;             /* 为链表新尾节点赋值 */
    newTail->next = NULL;           /* 尾节点的下一节点为 NULL*/

    if (obj->head == NULL) {            /* 如果虚拟头节点指向的头节点为 NULL*/
        obj->head = newTail;                /* 设置当前链表新尾节点为链表头节点 */
    } else {                            /* 反之 */
        ListNode *curr = obj->head;         /* 获取当前链表头节点的指针 */
        while (curr->next != NULL) {        /* 当当前指针所指节点的下一节点不为 NULL 时 */
            curr = curr->next;                  /* 指针向后移动一位 */
        }
        curr->next = newTail;               /* 当当前指针所指节点的下一节点为 NULL 时，将当前指针的下一节点设置为链表新尾节点 */
    }
    obj->size++;                        /* 链表大小 + 1 */
}

/* TODO: 目标函数 */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {

}

/* TODO: 目标函数 */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {

}

/* DONE: 目标函数 */
void myLinkedListFree(MyLinkedList* obj) {
    ListNode *curr = obj->head;
    while (curr != NULL) {
        ListNode *tmp = curr;
        curr = curr->next;
        free(tmp);
    }
    free(obj);
}

/* 主函数 */
int main(int argc, const char* argv[]) {
    MyLinkedList *list = myLinkedListCreate();

    myLinkedListAddAtHead(list, 1);
    myLinkedListAddAtTail(list, 2);
    myLinkedListAddAtIndex(list, 1, 3);

    printf("linked list: ");
    for (int i = 0; i < list->size; i++) {
        printf("%d ", myLinkedListGet(list, i));
    }
    printf("\n");

    myLinkedListFree(list);
    return 0;
}