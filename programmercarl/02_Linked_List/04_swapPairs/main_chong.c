/* 24. 两两交换链表中的节点：https://leetcode.cn/problems/swap-nodes-in-pairs/ */
/* https://programmercarl.com/0024.%E4%B8%A4%E4%B8%A4%E4%BA%A4%E6%8D%A2%E9%93%BE%E8%A1%A8%E4%B8%AD%E7%9A%84%E8%8A%82%E7%82%B9.html */

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

/* TODO: 目标函数 */
struct ListNode* swapPairs(struct ListNode* head){
    if (head == NULL || head->next == NULL) {   /* 如果当前头节点和头节点的下一节点不存在的话，返回当前头节点*/
        return head;
    }

    struct ListNode* newHead = head->next;      /* 新头节点为现头节点的下一节点 */
    struct ListNode* prev = NULL;               /* 前节点初始化为NULL */

    while (head && head->next) {                /* 当当前节点和下一节点存在的时候 */
        struct ListNode *first = head;              /* 第一节点为现头节点 */
        struct ListNode *second = head->next;       /* 第二节点为现头节点的下一节点 */

        first->next = second->next;                 /* 改变链表指向：第一节点的下一节点指向第二节点的下一节点 */
        second->next = first;                       /* 改变链表指向：第二节点的下一节点指向第一节点 */

        if (prev) {                                 /* 如果前节点存在 */
            prev->next = second;                        /* 前节点的下一节点指向第二节点 */
        }

        prev = first;                               /* 将第一节点设置为前节点 */
        head = first->next;                         /* 将第一节点的下一节点设置为头节点 */
    }
    return newHead;                             /* 返回新头节点 */
}

/* NOTE: 主函数 */
int main(int argc, char const *argv[]) {
    int arr[5] = {1, 2, 3, 4, 5};
    struct ListNode *newList = createList(arr, 5);
    printList(newList);
    struct ListNode *ansList = swapPairs(newList);
    printList(ansList);
    return 0;
}