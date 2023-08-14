/* 142. 环形链表 II：https://leetcode.cn/problems/linked-list-cycle-ii/ */
/* https://programmercarl.com/0142.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8II.html */

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
    while (listPtr != NULL) {
        printf("%d ", listPtr->val);
        listPtr = listPtr->next;
    }
    printf("\n");
}

/* ==================================================================================================== */
/* ==================================================================================================== */
/* TODO: 目标函数 */
struct ListNode *detectCycle(struct ListNode *head) {
    
}
/* ==================================================================================================== */
/* ==================================================================================================== */

/* NOTE: 主函数 */
int main(int argc, const char* argv[]) {

    return 0;
}