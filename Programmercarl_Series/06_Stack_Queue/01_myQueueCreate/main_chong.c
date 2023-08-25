/* 232. 用栈实现队列：https://leetcode.cn/problems/implement-queue-using-stacks/ */
/* https://programmercarl.com/0232.%E7%94%A8%E6%A0%88%E5%AE%9E%E7%8E%B0%E9%98%9F%E5%88%97.html */
/* https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0232.%E7%94%A8%E6%A0%88%E5%AE%9E%E7%8E%B0%E9%98%9F%E5%88%97.md */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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
    ret->stk = (int *)malloc(sizeof(int) * capacity);
    ret->stkSize = 0;
    ret->stkCapacity = capacity;
    return ret;
}

void stackPush(Stack* obj, int x) {
    obj->stk[obj->stkSize++] = x;
}

void stackPop(Stack* obj) {
    obj->stkSize--;
}

int stackTop(Stack* obj) {
    return obj->stk[obj->stkSize - 1];
}

bool stackEmpty(Stack* obj) {
    return obj->stkSize == 0;
}

void stackFree(Stack* obj) {
    free(obj->stk);
}


typedef struct {
    Stack *inStack;
    Stack *outStack;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue *ret = (MyQueue *)malloc(sizeof(MyQueue));
    ret->inStack = stackCreate(100);
    ret->outStack = stackCreate(100);
    return ret;
}

void in2out(MyQueue *obj) {
    while (!stackEmpty(obj->inStack)) {
        stackPush(obj->outStack, stackTop(obj->inStack));
        stackPop(obj->inStack);
    }
}

void myQueuePush(MyQueue* obj, int x) {
    stackPush(obj->inStack, x);
}

int myQueuePop(MyQueue* obj) {
    if (stackEmpty(obj->outStack)) {
        in2out(obj);
    }
    int x = stackTop(obj->outStack);
    stackPop(obj->outStack);
    return x;
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
    printf("peek val: %d \n", myQueuePeek(myQueue));
    printf("pop val: %d \n", myQueuePop(myQueue));
    printf("myQueue empty: %d \n", myQueueEmpty(myQueue));
    myQueueFree(myQueue);
    return 0;
}