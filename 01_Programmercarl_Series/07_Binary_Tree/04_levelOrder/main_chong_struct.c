/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\07_Binary_Tree\04_levelOrder\main_chong_struct.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-11 21:17:11
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-09-13 20:32:04
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 102. 二叉树的层序遍历：从上往下层序遍历二叉树 - 此文件为队列结构体解法
 * 102. 二叉树的层序遍历: https://leetcode.cn/problems/binary-tree-level-order-traversal/
 * https://programmercarl.com/0102.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86.html
 * 解法参考：https://leetcode.cn/problems/binary-tree-level-order-traversal/solutions/1286876/er-cha-shu-de-ceng-xu-bian-li-cyu-yan-xi-jdk8/
 */
#include <stdio.h>
#include <stdlib.h>

/* NOTE: 树节点 */
struct TreeNode {
    int val;                    /* 节点的值 */
    struct TreeNode *left;      /* 左节点 */
    struct TreeNode *right;     /* 右节点 */
};

/* ==================================================================================================== */
/* ==================================================================================================== */
/* 层序遍历 借助其他数据结构，记录下，Tree 的下一层的所有结点。这样一层一层的遍历。直到结束 */

/* 层序遍历 + 链表队列 */
    /* 1：使用队列的数据结构存储对应的二叉树的结点 Queue */
    /* 2：使用变量 front 和 rear 维护队列，队列是具有先进先出的特点 */
    /* 3：使用 Queue[rear++] = root; 来入队 */
    /* 4：使用 nodeIt = Queue[front++]; 来出队 */
    /* 5：出队后，用nodeIt对应的子节点来操作，是否需要入队。 */

/* 1：采用队列结构存储每一层的结点 */
/* 2：因为队列的结构特性，操作是先进先出 */
/* 时间复杂度：O(n) 空间复杂度: O(n) */
/* ==================================================================================================== */
/* ==================================================================================================== */
#define MAX_SIZE 2000           /* 初始化大小 */

struct Queue {                  /* 队列结构体 */
    struct TreeNode *node;      /* 树节点指针 */
    struct Queue    *next;      /* 指向下一元素的指针 */
};

/**
 * @description: 入队 - 将新的树节点元素加入队尾
 * =================================================================================
 * @param {struct Queue} *queueHead     链表队列的虚拟头节点
 * @param {struct TreeNode} *node       待入队树节点元素
 * @return {void}
 */
void enQueue(struct Queue *queueHead, struct TreeNode *node) {
    struct Queue *queueIt = queueHead;          /* 初始化当前队列节点的指针为虚拟头节点的指针 */
    while (queueIt->next != NULL) {             /* 当当前队列节点指针的下一元素不为 NULL 时 */
        queueIt = queueIt->next;                    /* 队列节点指针向后移动一位，获取队列尾节点指针 */
    }
    struct Queue *queueNew = (struct Queue *)malloc(sizeof(struct Queue));      /* 为新队列节点分配空间 */
    queueNew->node = node;                      /* 将当前新队列节点的树节点指针指向目标树节点指针 node */
    queueNew->next = NULL;                      /* 将当前新队列节点的下一节点指向 NULL */
    queueIt->next = queueNew;                   /* 将队列尾节点的下一节点指向新队列节点 */
}

/**
 * @description: 出队 - 将队首树节点元素弹出队列
 * =================================================================================
 * @param {struct Queue} *queueHead     链表队列的虚拟头节点
 * @return {struct TreeNode} *node      出队树节点元素
 */
struct TreeNode *deQueue(struct Queue *queueHead) {
    struct Queue *queueIt = queueHead->next;    /* 初始化当前队列节点的指针为队首指针 */
    struct TreeNode *node;                      /* 初始化一个树节点指针 node */
    if (queueIt != NULL) {                      /* 如果队首节点指针不为 NULL */
        queueHead->next = queueIt->next;            /* 将【虚拟头节点的下一节点指针】指向【队首节点的下一节点指针所指节点】 */
        node = queueIt->node;                       /* 获取当前队首节点的树节点元素 */
        free(queueIt);                              /* 释放队首节点的空间 */
        return node;                                /* 返回队首树节点元素 */
    }
    return NULL;                                /* 如果当前队首节点指针为 NULL，则返回 NULL */
}

/**
 * @description: 释放队列空间
 * =================================================================================
 * @param {struct Queue} *queueHead     链表队列的虚拟头节点
 * @return {void}
 */
void freeQueue(struct Queue *queueHead) {
    struct Queue *queueIt = queueHead->next;    /* 初始化当前队列节点的指针为队首指针 */
    struct Queue *queuePre = queueHead->next;   /* 初始化前一队列节点的指针为队首指针 */
    while (queueIt != NULL) {                   /* 如果队首节点指针不为 NULL */
        queuePre = queueIt;                         /* 赋值【前一队列节点指针】为【当前队列节点指针】 */
        queueIt = queueIt->next;                    /* 当前队列节点指针向后移动一位 */
        free(queuePre);                             /* 释放前一队列节点的内存空间 */
    }
    free(queueHead);                            /* 释放虚拟头节点的内存空间 */
}

/**
 * @description: 广度优先搜索算法 Breadth-First Search
 * =================================================================================
 * @param {int} *returnSize             二叉树的层数
 * @param {int} **returnColumnSizes     二叉树对应层级的节点数
 * @param {int} **resultArray           结果二维数组
 * @param {struct Queue} *queueHead     链表队列的虚拟头节点
 * @return {void}
 */
void breadthFirstSearch(int *returnSize, int **returnColumnSizes, int **resultArray, struct Queue *queueHead) {
    struct Queue *queueIt = queueHead->next;                /* 初始化当前队列节点的指针为队首指针 */
    if (queueIt->node == NULL) {                            /* 如果队首节点的树节点指针为 NULL */
        return;                                                 /* 返回 */
    }

    int count = 0;                                                          /* 初始化计数器 count 为 0 */
    resultArray[*returnSize] = (int *)malloc(sizeof(int) * MAX_SIZE);       /* 结果二维数组的行号对应二叉树的层数：为二维数组的第 returnSize 行分配空间 - 2000个int类型数据 */

    while (1) {                                             /* 持续循环 */
        struct TreeNode *node = deQueue(queueHead);             /* 将队首树节点出队 */
        if (node == NULL) {                                     /* 如果队首树节点为 NULL */
            break;                                                  /* 停止循环 */
        }
        resultArray[*returnSize][count] = node->val;            /* 结果二维数组的 returnSize 行 count 列赋值为队首树节点的值 */
        count++;                                                /* 计数器count + 1 */
        if (node->left != NULL) {                               /* 如果队首树节点的左节点不为 NULL */
            enQueue(queueHead, node->left);                         /* 将队首树节点的左节点入队 */
        }
        if (node->right != NULL) {                              /* 如果队首树节点的右节点不为 NULL */
            enQueue(queueHead, node->right);                        /* 将队首树节点的右节点入队 */
        }
    }

    enQueue(queueHead, NULL);                               /* 将 NULL 入队 */
    (*returnColumnSizes)[*returnSize] = count;              /* *returnColumnSizes 数组的 *returnSize 位有 count 个节点 */
    *returnSize = *returnSize + 1;                          /* 二叉树的层数 + 1 */
    breadthFirstSearch(returnSize, returnColumnSizes, resultArray, queueHead);      /* 进行下一层的遍历 */
}

/**
 * DONE: 目标函数
 * @description: 二叉树的层序遍历
 * =================================================================================
 * @param {struct TreeNode} *root       二叉树的根节点
 * @param {int} *returnSize             二叉树的层数
 * @param {int} **returnColumnSizes     二叉树对应层级的节点数
 * @return {int} **resultArray          结果二维数组
 */
int** levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes) {
    *returnSize = 0;                                                                /* 初始化二叉树的层数为 0 */
    if (root == NULL) {                                                             /* 如果根节点为 NULL */
        return NULL;                                                                    /* 返回 NULL */
    }

    int **resultArray = (int **)malloc(sizeof(int *) * MAX_SIZE);                   /* 为二维数组分配空间 - 2000个int*类型数据 */
    *returnColumnSizes = (int *)malloc(sizeof(int) * MAX_SIZE);                     /* 用来记录二叉树每层的节点数（二维数组每行的列数）- 2000个int类型数据 */

    struct Queue *queueHead = (struct Queue *)malloc(sizeof(struct Queue));         /* 为链表队列的虚拟头节点分配空间 */
    queueHead->next = NULL;                                                         /* 虚拟头节点的下一队列节点为 NULL */
    queueHead->node = NULL;                                                         /* 虚拟头节点保存的树节点为 NULL */

    enQueue(queueHead, root);                                                       /* 将树的根节点入队 */
    enQueue(queueHead, NULL);                                                       /* 将 NULL 入队，表示当前树的层级结束 */
    breadthFirstSearch(returnSize, returnColumnSizes, resultArray, queueHead);      /* 开始广度优先搜索算法 */
    freeQueue(queueHead);                                                           /* 释放队列空间 */
    return resultArray;                                                             /* 返回结果二维数组 */
}

/* ==================================================================================================== */
/* ==================================================================================================== */
/* ==================================================================================================== */
/* ==================================================================================================== */

/**
 * @description: 创建树节点
 * =================================================================================
 * @param {int} value                   树节点的数值
 * @return {struct TreeNode} *node      新树节点的指针
 */
struct TreeNode *newNode(int value) {
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));     /* 初始化树节点：为树节点分配空间 */
    node->val = value;                                                              /* 树节点的值为 value */
    node->left = NULL;                                                              /* 树节点的左子节点为 NULL */
    node->right = NULL;                                                             /* 树节点的右子节点为 NULL */
    return node;                                                                    /* 返回树节点 */
}

/**
 * @description: 打印二维数组
 * =================================================================================
 * @param {int} **array                 二维数组
 * @param {int} size                    二维数组的行数
 * @param {int} *columnSizes            二维数组行数对应的列数
 * @return {void}
 */
void print2DArray(int **array, int size, int *columnSizes) {
    printf("[\n");                                          /* 打印总边框 [ */
    for (int i = 0; i < size; ++i) {                        /* 遍历二维数组的行 */
        printf("  [");                                          /* 打印行边框 [ */
        for (int j = 0; j < columnSizes[i]; ++j) {                  /* 遍历 i 行内的元素 */
            printf("%d", array[i][j]);                                  /* 打印 i 行内的元素 */
            if (j < columnSizes[i] - 1) {                               /* 打印分隔符：, */
                printf(", ");
            }
        }
        printf("]\n");                                          /* 打印行边框 ] */
    }
    printf("]\n");                                          /* 打印总边框 ] */
}

/**
 * @description: 主函数
 * =================================================================================
 * @param {int} argc        程序入参个数
 * @param {char} *argv[]    程序入参字符串数组
 * @return {int}            程序运行状态
 */
int main(int argc, const char *argv[]) {
    /*
     * 创建以下树结构
     *      1
     *     / \
     *    2   3
     *   / \ / \
     *  4  5 6  7
     */
    struct TreeNode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    root->left->left = newNode(4);
    root->left->right = newNode(5);

    root->right->left = newNode(6);
    root->right->right = newNode(7);

    int returnSize = 0;
    int *returnColumnSizes;

    /* NOTE: 函数调用 */
    int** result = levelOrder(root, &returnSize, &returnColumnSizes);
    print2DArray(result, returnSize, returnColumnSizes);

    return 0;
}