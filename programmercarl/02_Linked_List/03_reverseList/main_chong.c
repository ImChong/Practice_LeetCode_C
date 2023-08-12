/* 206. 反转链表：https://leetcode.cn/problems/reverse-linked-list/ */
/* https://programmercarl.com/0206.%E7%BF%BB%E8%BD%AC%E9%93%BE%E8%A1%A8.html */

#include <stdio.h>

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

/* TODO: 目标函数 */
struct ListNode* reverseList(struct ListNode* head){

}

/* NOTE: 主函数 */
int main(int argc, char const *argv[]) {


    return 0;
}