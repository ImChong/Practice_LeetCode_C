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
    int i = 0;  /* 防止无限循环 */
    while (listPtr != NULL && i < 20) {
        printf("%d ", listPtr->val);
        listPtr = listPtr->next;
        i++;
    }
    printf("\n");
}

/* ==================================================================================================== */
/* ==================================================================================================== */
/* TODO: 目标函数 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}
/* ==================================================================================================== */
/* ==================================================================================================== */

/* NOTE: 主函数 */
/* BUG: 答案index多了1 */
int main(int argc, const char* argv[]) {
    /* NOTE: Case 1 */
    printf("======== Case 1 ======== \n");
    int arr1[] = {3, 2, 0, -4};
    struct ListNode *ansList = createList(arr1, 4);
    struct ListNode *pPos = ansList;
    struct ListNode *pTail = ansList;
    while (pTail->next != NULL) {   /* 获取链表尾部节点 */
        pTail = pTail->next;
    }
    for (int i = 0; i < 1; i++) {   /* 获取链表指定节点 */
        pPos = pPos->next;
    }
    pTail->next = pPos;
    printList(ansList);
    printf("Pos: %d\n", detectCycle(ansList)->val);

    /* NOTE: Case 2 */
    printf("======== Case 2 ======== \n");
    struct ListNode b1 = {1, NULL}, b2 = {2, NULL};
    b1.next = &b2; b2.next = &b1;
    printList(&b1);
    printf("Pos: %d\n", detectCycle(&b1)->val);

    return 0;
}