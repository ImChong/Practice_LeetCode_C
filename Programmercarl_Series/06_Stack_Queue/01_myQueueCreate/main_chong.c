/* 232. 用栈实现队列：https://leetcode.cn/problems/implement-queue-using-stacks/ */
/* https://programmercarl.com/0232.%E7%94%A8%E6%A0%88%E5%AE%9E%E7%8E%B0%E9%98%9F%E5%88%97.html */
/* https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0232.%E7%94%A8%E6%A0%88%E5%AE%9E%E7%8E%B0%E9%98%9F%E5%88%97.md */

#include <stdio.h>
#include <stdbool.h>

/* ==================================================================================================== */
/* ==================================================================================================== */
/* TODO: 目标函数 */
typedef struct {
    int *stk;
    int stkSize;
    int stkCapacity;
} Stack;

Stack* stackCreate(int capacity) {
    Stack *ret = (Stack *)malloc(sizeof(Stack));
    ret->stk = (int *)malloc(sizeof(int) * capacity)
    ret->stkSize = 0;
    ret->stkCapacity = capacity;
    return ret;
}

void stackPush(Stack* obj, int x) {

}

void stackPop(Stack* obj) {

}

int stackTop(Stack* obj) {

}

bool stackEmpty(Stack* obj) {

}

void stackFree(Stack* obj) {

}


typedef struct {
    Stack *inStack;
    Stack *outStack;
} MyQueue;


MyQueue* myQueueCreate() {

}

void myQueuePush(MyQueue* obj, int x) {

}

int myQueuePop(MyQueue* obj) {
    return 0;
}

int myQueuePeek(MyQueue* obj) {
    return 0;
}

bool myQueueEmpty(MyQueue* obj) {
    return false;
}

void myQueueFree(MyQueue* obj) {

}
/* ==================================================================================================== */
/* ==================================================================================================== */

/* NOTE：主函数 */
int main(int argc, const char* argv[]) {
    /* NOTE: Test case 1 */
    printf("======== Case 1 ======== \n");
    MyQueue *myQueue = myQueueCreate();
    myQueuePush(myQueue, 1);
    myQueuePush(myQueue, 2);
    printf("peek val: %d \r\n", myQueuePeek(myQueue));
    printf("pop val: %d \r\n", myQueuePop(myQueue));
    printf("myQueue empty: %d \r\n", myQueueEmpty(myQueue));
    myQueueFree(myQueue);
    return 0;
}