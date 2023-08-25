/* 232. 用栈实现队列：https://leetcode.cn/problems/implement-queue-using-stacks/ */
/* https://programmercarl.com/0232.%E7%94%A8%E6%A0%88%E5%AE%9E%E7%8E%B0%E9%98%9F%E5%88%97.html */
/* https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0232.%E7%94%A8%E6%A0%88%E5%AE%9E%E7%8E%B0%E9%98%9F%E5%88%97.md */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* ==================================================================================================== */
/* ==================================================================================================== */
/* TODO: 目标函数 */
/* TODO: 添加注释 */
typedef struct {
    int *stk;           /* 栈数组：用于存储数据 */
    int stkSize;        /* 栈大小：记录当前栈的大小 */
    int stkCapacity;    /* 栈容量：记录栈大小的最大值 */
} Stack;

Stack* stackCreate(int capacity) {
    Stack *ret = (Stack *)malloc(sizeof(Stack));        /* 为栈结构体分配空间 */
    ret->stk = (int *)malloc(sizeof(int) * capacity);   /* 为栈数组分配空间，大小为最大容量 */
    ret->stkSize = 0;                                   /* 当前栈大小为0 */
    ret->stkCapacity = capacity;                        /* 记录栈容量 */
    return ret;                                         /* 返回创建的栈结构体 */
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
    if (stackEmpty(obj->outStack)) {
        in2out(obj);
    }
    return stackTop(obj->outStack);
}

bool myQueueEmpty(MyQueue* obj) {
    return (stackEmpty(obj->inStack) && stackEmpty(obj->outStack));
}

void myQueueFree(MyQueue* obj) {
    stackFree(obj->inStack);
    stackFree(obj->outStack);
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
    printf("myQueuePeek: %d \n", myQueuePeek(myQueue));
    printf("myQueuePop: %d \n", myQueuePop(myQueue));
    printf("myQueueEmpty: %d \n", myQueueEmpty(myQueue));
    myQueueFree(myQueue);
    return 0;
}