/* 225. 用队列实现栈：https://leetcode.cn/problems/implement-stack-using-queues/ */
/* https://programmercarl.com/0225.%E7%94%A8%E9%98%9F%E5%88%97%E5%AE%9E%E7%8E%B0%E6%A0%88.html */
/* https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0225.%E7%94%A8%E9%98%9F%E5%88%97%E5%AE%9E%E7%8E%B0%E6%A0%88.md */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* ==================================================================================================== */
/* 方法二：一个队列 */
/* ==================================================================================================== */
/* TODO: 目标函数 */
typedef struct tagListNode {
    struct tagListNode *next;
    int val;
} ListNode;

typedef struct {
    ListNode *top;
} MyStack;

MyStack* myStackCreate() {
    MyStack *stk = (MyStack *)calloc(1, sizeof(MyStack));
    return stk;
}

void myStackPush(MyStack* obj, int x) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->val = x;
    node->next = obj->top;
    obj->top = node;
}

int myStackPop(MyStack* obj) {
    ListNode *node = obj->top;
    int val = node->val;
    obj->top = node->next;
    free(node);
    return val;
}

int myStackTop(MyStack* obj) {
    return obj->top->val;
}

bool myStackEmpty(MyStack* obj) {
    return (obj->top == NULL);
}

void myStackFree(MyStack* obj) {
    while (obj->top != NULL) {
        ListNode *node = obj->top;
        obj->top = obj->top->next;
        free(node);
    }
    free(obj);
}
/* ==================================================================================================== */
/* ==================================================================================================== */

/* NOTE：主函数 */
int main(int argc, const char* argv[]) {
    /* NOTE: Test case 1 */
    printf("======== Case 1 ======== \n");
    MyStack *myStack = myStackCreate();
    myStackPush(myStack, 1);
    myStackPush(myStack, 2);
    printf("myStackTop: %d \n", myStackTop(myStack));
    printf("myStackPop: %d \n", myStackPop(myStack));
    printf("myStackEmpty: %d \n", myStackEmpty(myStack));
    myStackFree(myStack);
    return 0;
}