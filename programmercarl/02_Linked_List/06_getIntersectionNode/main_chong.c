/* 面试题 02.07. 链表相交：https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/ */
/* https://programmercarl.com/%E9%9D%A2%E8%AF%95%E9%A2%9802.07.%E9%93%BE%E8%A1%A8%E7%9B%B8%E4%BA%A4.html */

#include <stdio.h>
#include <stdlib.h>

/* NOTE: 节点定义 */
struct ListNode {
    int val;
    struct ListNode *next;
};

/* NOTE: 创建链表，不使用虚拟头结点 */
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
void printList(struct ListNode *listPtr, char listChar) {
    printf("linked list %c: ", listChar);
    while (listPtr != NULL) {
        printf("%d ", listPtr->val);
        listPtr = listPtr->next;
    }
    printf("\n");
}

/* TODO: 目标函数 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    
}

/* NOTE: 主函数 */
int main(int argc, const char* argv[]) {
    /* NOTE: Case 1 */
    printf("Case 1: \n");
    int arrA1[] = {4, 1, 8, 4, 5};
    struct ListNode *listA = createList(arrA1, 5);
    printList(listA, 'A');

    int arrB1[] = {5, 0, 1};
    struct ListNode *listB = createList(arrB1, 3);
    /* 将B链表挂载至A链表 */
    struct ListNode *current = listB;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = listA->next->next;
    printList(listB, 'B');

    /* NOTE: Case 2 */
    printf("Case 2: \n");
    int arrA2[] = {2, 6, 4};
    listA = createList(arrA2, 3);
    printList(listA, 'A');

    int arrB2[] = {1, 5};
    listB = createList(arrB2, 2);
    printList(listB, 'B');
    return 0;
}