/* 707. 设计链表：https://leetcode.cn/problems/design-linked-list/ */
/* https://programmercarl.com/0707.%E8%AE%BE%E8%AE%A1%E9%93%BE%E8%A1%A8.html */
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

/* DONE: 目标函数 */
typedef struct {
    ListNode *head;
    int size;
} MyLinkedList;

/* DONE: 目标函数 */
MyLinkedList* myLinkedListCreate() {
    MyLinkedList *obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->size = 0;
    return obj;
}

/* TODO: 目标函数 */
int myLinkedListGet(MyLinkedList* obj, int index) {
    
    return 0;
}

/* TODO: 目标函数 */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {

}

/* TODO: 目标函数 */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {

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