/*
 * @FilePath     : /Practice_LeetCode_C/01_Programmercarl_Series/07_Binary_Tree/00_common/treeToArray.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-24 14:54:38
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-09-24 22:48:09
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 将树结构用数组表示
 */
#include <stdio.h>
#include <stdlib.h>

/**********************************************************************************/
/*                                                                                */
/*                                MACRO CONSTANTS                                 */
/*                                                                                */
/**********************************************************************************/
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
    struct TreeNode *data[MAX_QUEUE_SIZE];  /* 队列的数据 */
    int front;                              /* 队首指针 */
    int rear;                               /* 队尾指针 */
} Queue;

/**********************************************************************************/
/*                                                                                */
/*                                 UTILITY FUNCTIONS                              */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 将一个节点加入队列
 * =================================================================================
 * @param {Queue} *q                    队列指针
 * @param {struct TreeNode} *node       待加入队列的树节点指针
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
 * @description: 从队列中取出一个节点
 * =================================================================================
 * @param {Queue} *q                    队列指针
 * @return {struct TreeNode} *item      取出的树节点指针
 */
struct TreeNode *dequeue(Queue *q) {
    if (q->front == q->rear) {                      /* 如果队列为空，输出错误信息并退出程序 */
        printf("Queue underflow\n");
        exit(1);
    }
    struct TreeNode *item = q->data[q->front];      /* 取出队首节点 */
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;     /* 更新队首指针 */
    return item;                                    /* 返回取出的节点指针 */
}

/**
 * @description: 判断队列是否为空
 * =================================================================================
 * @param {Queue} *q    队列指针
 * @return {int}        如果队列为空，返回1；否则返回0
 */
int isEmpty(Queue *q) {
    return q->front == q->rear;     /* 如果队首指针等于队尾指针，说明队列为空 */
}

/**********************************************************************************/
/*                                                                                */
/*                                 TARGET FUNCTION                                */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 将二叉树转换为数组
 * =================================================================================
 * @param {struct TreeNode} *root   二叉树根节点指针
 * @param {int} *returnSize         数组长度指针
 * @return {int} result             转换后的数组指针
 */
int *treeToArray(struct TreeNode *root, int *returnSize) {
    if (!root) {                                                    /* 如果根节点为空 */
        *returnSize = 0;                                                /* 返回数组大小为0 */
        return NULL;                                                    /* 返回空指针 */
    }

    int *result = (int*) malloc(MAX_QUEUE_SIZE * sizeof(int));      /* 动态分配数组内存 */
    Queue q;                                                        /* 创建队列 */
    q.front = q.rear = 0;                                           /* 初始化队列 */

    enqueue(&q, root);                                              /* 将根节点加入队列 */
    int index = 0;                                                  /* 初始化数组下标 */

    while (!isEmpty(&q)) {                                          /* 队列不为空时 */
        struct TreeNode *current = dequeue(&q);                         /* 取出队首节点 */
        if (current) {                                                  /* 如果节点不为空 */
            result[index] = current->val;
            enqueue(&q, current->left);
            enqueue(&q, current->right);
        } else {
            result[index] = -1;
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
    /* Test case 1 */
    printf("======== Case 1 ======== \n");
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
