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

/* ==================================================================================================== */
/* ==================================================================================================== */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if (!head || n <= 0) {      /* 如果头节点不存在 或 n <= 0 时 */
        return head;                /* 返回头节点 */
    }

    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));     /* 初始化虚拟头节点 */
    dummy->val = 0;         /* 虚拟头节点值为0 */
    dummy->next = head;     /* 虚拟头节点的下一节点指向链表头节点 */

    struct ListNode *first = dummy;         /* 设置第一指针指向虚拟头节点的位置 */
    struct ListNode *second = dummy;        /* 设置第二指针指向虚拟头节点的位置 */

    for (int i = 0; i <= n; i++) {          /* 循环 n + 1 次：需要末尾 NULL 作为循环结束条件，故 n + 1 */
        if (first != NULL) {                    /* 如果第一指针没有指向 NULL */
            first = first->next;                    /* 将第一指针向后移动一个位置 */
        } else {                                /* 循环过程中第一指针指向了 NULL */
            return head;                            /* 则返回头节点，代表出界 */
        }
    }

    while (first != NULL) {                 /* 当第一指针未指向 NULL 时循环 */
        first = first->next;                    /* 第一指针向后移动一个位置 */
        second = second->next;                  /* 第二指针向后移动一个位置，直到第二指针指向待删除节点的前一节点 */
    }

    struct ListNode *tmp = second->next;    /* 用一个临时指针储存第二指针所指的下一节点：待删除节点 */
    second->next = second->next->next;      /* 将第二指针的下一节点指向下下节点 */
    free(tmp);                              /* 删除指定节点 */

    struct ListNode *newHead = dummy->next; /* 设置链表头节点为虚拟头节点的下一节点 */
    free(dummy);                            /* 删除虚拟头节点 */
    return newHead;                         /* 返回链表头节点 */
}
/* ==================================================================================================== */
/* ==================================================================================================== */

/* NOTE: 主函数 */
int main(int argc, char const *argv[]) {
    int arr[5] = {1, 2, 3, 4, 5};
    struct ListNode *newList = createList(arr, 5);
    printList(newList);

    /* NOTE: Case 1 */
    printf("======== Case 1 ======== \n");
    struct ListNode *ansList = removeNthFromEnd(newList, 2);
    printList(ansList);

    /* NOTE: Case 2 */
    printf("======== Case 2 ======== \n");
    ansList = removeNthFromEnd(newList, 3);
    printList(ansList);

    /* NOTE: Case 3 */
    printf("======== Case 3 ======== \n");
    ansList = removeNthFromEnd(newList, 5);
    printList(ansList);

    return 0;
}