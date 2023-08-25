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

}

void myStackPush(MyStack* obj, int x) {

}

int myStackPop(MyStack* obj) {
    return 0;
}

int myStackTop(MyStack* obj) {
    return 0;
}

bool myStackEmpty(MyStack* obj) {
    return false;
}

void myStackFree(MyStack* obj) {

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