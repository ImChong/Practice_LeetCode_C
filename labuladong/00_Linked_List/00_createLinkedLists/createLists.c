#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


// 创建链表
struct ListNode *create_list(int *array, int size) {
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

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    struct ListNode *ansList = create_list(arr, 5);

    while (ansList != NULL) {
        printf("%d ", ansList->val);
        ansList = ansList->next;
    }
    printf("\n");

    return 0;
}
