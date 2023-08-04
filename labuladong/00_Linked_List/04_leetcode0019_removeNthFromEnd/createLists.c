#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};


// 创建链表
struct node *create_list(int *array, int size) {
    struct node *head = NULL;
    struct node *current = NULL;

    for (int i = 0; i < size; i++) {
        // 创建新结点
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = array[i];
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

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    return 0;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    struct node *ansList = create_list(arr, 5);
    
    while (ansList != NULL) {
        printf("%d ", ansList->data);
        ansList = ansList->next;
    }
    printf("\n");

    return 0;
}
