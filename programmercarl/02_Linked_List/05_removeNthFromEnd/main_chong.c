/* 19. 删除链表的倒数第 N 个结点：https://leetcode.cn/problems/remove-nth-node-from-end-of-list/ */
/* https://programmercarl.com/0019.%E5%88%A0%E9%99%A4%E9%93%BE%E8%A1%A8%E7%9A%84%E5%80%92%E6%95%B0%E7%AC%ACN%E4%B8%AA%E8%8A%82%E7%82%B9.html */

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
void printList(struct ListNode *listPtr) {
    printf("linked list: ");
    while (listPtr != NULL) {
        printf("%d ", listPtr->val);
        listPtr = listPtr->next;
    }
    printf("\n");
}

/* TODO: 目标函数 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if (!head || n <= 0) {
        return head;
    }

    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = head;

    struct ListNode *first = dummy;
    struct ListNode *second = dummy;

    for (int i = 0; i <= n; i++) {
        if (first != NULL) {
            first = first->next;
        } else {
            return head;
        }
    }

    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    struct ListNode *tmp = second->next;
    second->next = second->next->next;
    free(tmp);

    struct ListNode *newHead = dummy->next;
    free(dummy);
    return newHead;
}

/* NOTE: 主函数 */
int main(int argc, char const *argv[]) {
    int arr[5] = {1, 2, 3, 4, 5};
    struct ListNode *newList = createList(arr, 5);
    printList(newList);
    struct ListNode *ansList = removeNthFromEnd(newList, 2);
    printList(ansList);
    return 0;
}