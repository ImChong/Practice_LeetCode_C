/* 23. 合并 K 个升序链表：https://leetcode.cn/problems/merge-k-sorted-lists/ */
/* https://leetcode.cn/problems/vvXgSW/ */
/* https://labuladong.github.io/algo/di-ling-zh-bfe1b/shuang-zhi-0f7cc/ */

/* TODO: 重构 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *head = malloc(sizeof(struct ListNode));
    struct ListNode *tail = head;
    head->next = NULL;
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return head->next;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if (listsSize == 0) {
        return NULL;
    }
    struct ListNode* l1, *l2;
    l1 = lists[0];
    for (int i = 1; i < listsSize; i++) {
        l2 = lists[i];
        l1 = mergeTwoLists(l1, l2);
    }
    return l1;
}

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 测试 1
 * =================================================================================
 * @return {void}
 */
void Test1(void) {
    /* 实际结果 */

    /* 预期结果 */

    /* 比较结果 */

}

/**
 * @description: 测试 2
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    /* 实际结果 */

    /* 预期结果 */

    /* 比较结果 */

}

/**
 * @description: 测试 3
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    /* 实际结果 */

    /* 预期结果 */

    /* 比较结果 */

}

/**********************************************************************************/
/*                                                                                */
/*                                  MAIN FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 主函数
 * =================================================================================
 * @param {int} argc        程序入参个数
 * @param {char} *argv[]    程序入参字符串数组
 * @return {int}            程序运行状态
 */
int main(int argc, const char *argv[]) {
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
