/* 225. 用队列实现栈：https://leetcode.cn/problems/implement-stack-using-queues/ */
/* https://programmercarl.com/0225.%E7%94%A8%E9%98%9F%E5%88%97%E5%AE%9E%E7%8E%B0%E6%A0%88.html */
/* https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0225.%E7%94%A8%E9%98%9F%E5%88%97%E5%AE%9E%E7%8E%B0%E6%A0%88.md */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define LEN 20
/* ==================================================================================================== */
/* ==================================================================================================== */
/* TODO: 目标函数 */
typedef struct {
    int *data;
    int head;
    int tail;
    int size;
} Queue;

typedef struct {
    Queue *queue1;
    Queue *queue2;
} MyStack;

Queue *initQueue(int k) {
    Queue *obj = (Queue *)malloc(sizeof(Queue));
    obj->data = (int *)malloc(sizeof(int) * k);
    obj->head = -1;
    obj->tail = -1;
    obj->size = k;
    return obj;
}

void enQueue(Queue *obj, int x) {
    if (obj->head == -1) {
        obj->head = 0;
    }
    obj->tail - (obj->tail + 1) % obj->size;
    obj->data[obj->tail] = x;
}

int deQueue(Queue *obj) {
    int a = obj->data[obj->head];
    if (obj->head == obj->tail) {
        obj->head = -1;
        obj->tail = -1;
        return a;
    }
    obj->head = (obj->head + 1) % obj->size;
    return a;
}

int isQueueEmpty(Queue *obj) {
    return obj->head == -1;
}

MyStack* myStackCreate() {
    MyStack *obj = (MyStack *)malloc(sizeof(MyStack));
    obj->queue1 = initQueue(LEN);
    obj->queue2 = initQueue(LEN);
    return obj;
}

void myStackPush(MyStack* obj, int x) {
    if (isQueueEmpty(obj->queue1)) {
        enQueue(obj->queue2, x);
    } else {
        enQueue(obj->queue1, x);
    }
}

int myStackPop(MyStack* obj) {
    if (isQueueEmpty(obj->queue1)) {
        while (obj->queue2->head != obj->queue2->tail) {
            enQueue(obj->queue1, deQueue(obj->queue2));
        }
        return deQueue(obj->queue2);
    }
    while (obj->queue1->head != obj->queue1->tail) {
        enQueue(obj->queue2, deQueue(obj->queue1));
    }
    return deQueue(obj->queue1);
}

int myStackTop(MyStack* obj) {
    if (isQueueEmpty(obj->queue1)) {
        return obj->queue2->data[obj->queue2->tail];
    }
    return obj->queue1->data[obj->queue1->tail];
}

bool myStackEmpty(MyStack* obj) {
    if (obj->queue1->head == -1 && obj->queue2->head == -1) {
        return true;
    }
    return false;
}

void myStackFree(MyStack* obj) {
    free(obj->queue1->data);
    obj->queue1->data = NULL;
    free(obj->queue1);
    obj->queue1 = NULL;
    free(obj->queue2->data);
    obj->queue2->data = NULL;
    free(obj->queue2);
    obj->queue2 = NULL;
    free(obj);
    obj = NULL;
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