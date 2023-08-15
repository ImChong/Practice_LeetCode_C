/* 206. 反转链表：https://leetcode.cn/problems/reverse-linked-list/ */
/* https://programmercarl.com/0206.%E7%BF%BB%E8%BD%AC%E9%93%BE%E8%A1%A8.html */

#include <stdio.h>
#include <stdlib.h>

/* NOTE: 节点定义 */
struct ListNode {
    int val;
    struct ListNode *next;
};

/* NOTE: 创建链表 */
struct ListNode *createList(int *array, int size) {
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

/* NOTE: 打印链表 */
void printList(struct ListNode *listPtr) {
    printf("linked list: ");
    while (listPtr != NULL) {
        printf("%d ", listPtr->val);
        listPtr = listPtr->next;
    }
    printf("\n");
}

/* ==================================================================================================== */
/* ==================================================================================================== */
/* DONE: 目标函数 */
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *prev = NULL;   /* 初始化前一节点指针为NULL */
    struct ListNode *curr = head;   /* 初始化现节点指针头结点 */
    struct ListNode *next = NULL;   /* 初始化下一节点指针为NULL */

    while (curr != NULL) {      /* 如果当前指针指向的节点不为 NULL */
        next = curr->next;          /* 位移指针：配置下一节点*/
        curr->next = prev;          /* 改变链表指向：将现节点的下一节点指针指向前一节点 */
        prev = curr;                /* 位移指针：将现节点指针设置为前节点指针*/
        curr = next;                /* 位移指针：将下一节点指针设置为现节点指针 */
    }
    return prev;                /* 返回前一节点指针 */
}
/* ==================================================================================================== */
/* ==================================================================================================== */

/* NOTE: 主函数 */
int main(int argc, char const *argv[]) {
    int arr[5] = {1, 2, 3, 4, 5};
    struct ListNode *newList = createList(arr, 5);
    printList(newList);
    struct ListNode *ansList = reverseList(newList);
    printList(ansList);
    return 0;
}