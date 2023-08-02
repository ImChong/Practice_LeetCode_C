#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    printf("%d\n", lists[0]->val);
    printf("%d\n", lists[1]->val);
    printf("%d\n", lists[2]->val);
    return NULL;
}

int main() {
    struct ListNode* list1 = malloc(sizeof(struct ListNode));
    list1->val = 1;
    list1->next = malloc(sizeof(struct ListNode));
    list1->next->val = 4;
    list1->next->next = malloc(sizeof(struct ListNode));
    list1->next->next->val = 5;
    list1->next->next->next = NULL;

    struct ListNode* list2 = malloc(sizeof(struct ListNode));
    list2->val = 1;
    list2->next = malloc(sizeof(struct ListNode));
    list2->next->val = 3;
    list2->next->next = malloc(sizeof(struct ListNode));
    list2->next->next->val = 4;
    list2->next->next->next = NULL;

    struct ListNode* list3 = malloc(sizeof(struct ListNode));
    list3->val = 2;
    list3->next = malloc(sizeof(struct ListNode));
    list3->next->val = 6;
    list3->next->next = NULL;

    struct ListNode* lists[3] = {list1, list2, list3};
    struct ListNode* mergedList = mergeKLists(lists, 3);

    while (mergedList != NULL) {
        printf("%d ", mergedList->val);
        mergedList = mergedList->next;
    }
    printf("\n");

    return 0;
}
