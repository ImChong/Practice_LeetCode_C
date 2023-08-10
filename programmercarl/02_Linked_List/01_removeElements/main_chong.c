/* 203. 移除链表元素：https://leetcode.cn/problems/remove-linked-list-elements/ */
/* https://programmercarl.com/0203.%E7%A7%BB%E9%99%A4%E9%93%BE%E8%A1%A8%E5%85%83%E7%B4%A0.html */

#include <stdio.h>

/* 节点定义 */
struct ListNode {
    int val;
    struct ListNode *next;
};

/* 创建链表 */
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

/* 打印链表 */
void printList(struct ListNode *listPtr) {
    while (listPtr != NULL) {
        printf("%d ", listPtr->val);
        listPtr = listPtr->next;
    }
    printf("\n");
}

/* TODO: 题目函数 */
struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode dummy;
    dummy.next = head;
    return 0;
}

int main(int argc, const char* argv[]) {
    int arr[5] = {1, 2, 3, 4, 5};
    struct ListNode *ansList = createList(arr, 5);
    printList(ansList);
    return 0;
}