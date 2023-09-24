/*
 * @FilePath     : /Practice_LeetCode_C/01_Programmercarl_Series/07_Binary_Tree/00_common/treeToArray.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-24 14:54:38
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-09-24 22:20:51
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 将树结构用数组表示
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100      /* 队列的最大容量 */

/**********************************************************************************/
/*                                                                                */
/*                                 GLOBAL VARIABLES                               */
/*                                                                                */
/**********************************************************************************/
/* 树节点 */
struct TreeNode {
    int val;                    /* 节点的值 */
    struct TreeNode *left;      /* 左节点 */
    struct TreeNode *right;     /* 右节点 */
};

/* 队列 */
typedef struct {
    struct TreeNode *data[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

/**********************************************************************************/
/*                                                                                */
/*                                 UTILITY FUNCTIONS                              */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 将一个节点加入队列
 * =================================================================================
 * @param {Queue} *q            队列指针
 * @param {struct TreeNode} *node      待加入队列的树节点指针
 * @return {void}
 */
void enqueue(Queue *q, struct TreeNode *node) {
    if ((q->rear + 1) % MAX_QUEUE_SIZE == q->front) {       /* 如果队列已满，输出错误信息并退出程序 */
        printf("Queue overflow\n");
        exit(1);
    }
    q->data[q->rear] = node;                                /* 将节点加入队列 */
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;               /* 更新队列尾指针 */
}

/**
 * @description:
 * =================================================================================
 * @param {Queue} *q
 * @return {*}
 */
struct TreeNode *dequeue(Queue *q) {
    if (q->front == q->rear) {
        printf("Queue underflow\n");
        exit(1);
    }
    struct TreeNode *item = q->data[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return item;
}

/**
 * @description:
 * =================================================================================
 * @param {Queue} *q
 * @return {*}
 */
int isEmpty(Queue *q) {
    return q->front == q->rear;
}

/**********************************************************************************/
/*                                                                                */
/*                                 TARGET FUNCTION                                */
/*                                                                                */
/**********************************************************************************/
/**
 * @description:
 * =================================================================================
 * @param {TreeNode} *root
 * @param {int} *returnSize
 * @return {*}
 */
int *treeToArray(struct TreeNode *root, int *returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    int *result = (int*) malloc(MAX_QUEUE_SIZE  *sizeof(int));
    Queue q;
    q.front = q.rear = 0;

    enqueue(&q, root);
    int index = 0;

    while (!isEmpty(&q)) {
        struct TreeNode *current = dequeue(&q);
        if (current) {
            result[index] = current->val;
            enqueue(&q, current->left);
            enqueue(&q, current->right);
        } else {
            result[index] = -1;  // 使用-1表示NULL，仅适用于不包含负值的树
        }
        index++;
    }

    *returnSize = index;
    return result;
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
int main(int argc, const char* argv[]) {
    // 测试代码
    struct TreeNode a = {1, NULL, NULL};
    struct TreeNode b = {2, NULL, NULL};
    struct TreeNode c = {3, NULL, NULL};
    a.left = &b;
    a.right = &c;

    int size;
    int *arr = treeToArray(&a, &size);
    for (int i = 0; i < size; i++) {
        if (arr[i] != -1)
            printf("%d ", arr[i]);
        else
            printf("NULL ");
    }
    free(arr);

    return 0;
}
