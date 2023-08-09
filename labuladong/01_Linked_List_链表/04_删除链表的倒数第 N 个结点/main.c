#include <stdio.h>
#include <stdlib.h>

// 节点定义
struct ListNode {
    int val;
    struct ListNode *next;
};

// 创建链表
struct ListNode *createList(int *array, int size) {
    struct ListNode *head = NULL;    // 头节点指针
    struct ListNode *current = NULL;    // 当前节点指针

    for (int i = 0; i < size; i++) {
        // 创建新结点
        struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
        new_node->val = array[i];
        new_node->next = NULL;
        
        // 如果链表为空，则将新结点设置为头结点
        if (head == NULL) {
            head = new_node;
        } else {
            // 否则，将新结点追加到链表末尾
            current->next = new_node;
        }
        current = new_node;
    }
    return head;
}

// 打印链表
void printList(struct ListNode *listPtr) {
    while (listPtr != NULL) {
        printf("%d ", listPtr->val);
        listPtr = listPtr->next;
    }
    printf("\n");
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    // TODO: write code here
}

int main()
{

    return 0;
}