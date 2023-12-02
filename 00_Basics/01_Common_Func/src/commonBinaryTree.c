/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\src\commonBinaryTree.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-01 20:07:37
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-02 17:54:25
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用二叉树源文件
 *
 * 二叉树主要有两种遍历方式：
 *   深度优先遍历：先往深走，遇到叶子节点再往回走。
 *       前序遍历（递归法，迭代法）
 *       中序遍历（递归法，迭代法）
 *       后序遍历（递归法，迭代法）
 *   广度优先遍历：一层一层的去遍历。
 *       层次遍历（迭代法）
 *
 * 数组形式表示：
 * [1, 2, 3, 4, 5, 6, 7]    用数组来存储二叉树: 如果父节点的数组下标是 i，那么它的左孩子就是 i * 2 + 1，右孩子就是 i * 2 + 2。
 * 树结构表示：
 *       1
 *      / \
 *     2   3
 *    / \ / \
 *   4  5 6  7
 *
 * 前序遍历：
 * [1, 2, 4, 5, 3, 6, 7]
 *
 * 中序遍历：
 * [4, 2, 5, 1, 6, 3, 7]
 *
 * 后序遍历：
 * [4, 5, 2, 6, 7, 3, 1]
 */
/* 编译配置文件 */
#include "compileCfg.h"
#if COMMON_BINARY_TREE_EN         /* 在每一道题 cfg 文件夹下的 compileCfg.h 开启编译宏定义 */
/* 标准头文件 */
#include <stdio.h>
#include <stdlib.h>
#include "limits.h"
/* 常用头文件 */
#include "commonBinaryTree.h"

/**********************************************************************************/
/*                                                                                */
/*                                MACRO CONSTANTS                                 */
/*                                                                                */
/**********************************************************************************/
#define MAX_SIZE 1000           /* 数组和栈的大小 */

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/* ============================================================================== */
/* ============================================================================== */
/*
 * 树结构表示：
 *       1
 *      / \
 *     2   3
 *    / \ / \
 *   4  5 6  7
 *
 * 前序遍历：
 * [1, 2, 4, 5, 3, 6, 7]
 */
/* ============================================================================== */
/* ============================================================================== */
/**
 * @description: 前序遍历
 * =================================================================================
 * @param {TreeNode} *node      当前节点指针
 * @param {int} *ans            用于储存遍历答案的数组
 * @param {int} *returnSize     用于储存遍历答案的数组的大小
 * @return {void}
 */
void preOrder(struct TreeNode *node, int *ans, int *returnSize) {
    if (node == NULL) {                                 /* 如果当前节点为 NULL，直接返回 */
        return;
    }
    ans[(*returnSize)++] = node->val;                   /* 把当前节点的值放入ret数组的 *returnSize 索引，并将 *returnSize 索引值 + 1 */
    preOrder(node->left, ans, returnSize);              /* 前序遍历左节点 */
    preOrder(node->right, ans, returnSize);             /* 前序遍历右节点 */
}

/**
 * @description: 前序遍历 - 递归方法
 * =================================================================================
 * @param {TreeNode} *root      根节点指针
 * @param {int} *returnSize     用于储存遍历答案的数组的大小
 * @return {int} *ans           用于储存遍历答案的数组
 */
int *preorderTraversal_recursion(struct TreeNode *root, int *returnSize) {
    int *ans = (int *)malloc(sizeof(int) * MAX_SIZE);   /* NOLINT(readability/casting) */
    *returnSize = 0;                                    /* 初始化数组的大小为 0 */
    preOrder(root, ans, returnSize);                    /* 前序遍历根节点 */
    return ans;                                         /* 返回结果 ans 数组 */
}

/**
 * @description: 前序遍历 - 迭代方法
 * =================================================================================
 * @param {TreeNode} *root      根节点指针
 * @param {int} *returnSize     用于储存遍历答案的数组的大小
 * @return {int} *ans           用于储存遍历答案的数组
 */
int *preorderTraversal_iteration(struct TreeNode *root, int *returnSize) {
    int *ans = (int *)malloc(sizeof(int) * MAX_SIZE);   /* 初始化一个MAX_SIZE长度的 ans 数组，用于储存遍历答案（后期需要free） */
    *returnSize = 0;                                    /* 初始化数组的大小为 0 */
    if (root == NULL) {                                 /* 如果当前节点为 NULL，直接返回 */
        return ans;
    }

    struct TreeNode *stk[MAX_SIZE];                     /* 用数组实现初始化一个MAX_SIZE容量的树节点栈 */
    int stk_top = 0;                                    /* 栈顶索引为 0 */
    struct TreeNode *node = root;                       /* 获取根节点的指针 */
    while (stk_top > 0 || node != NULL) {               /* 当栈顶索引大于0 或者 节点指针不指向NULL */
        while (node != NULL) {                              /* 当结点指针不指向NULL */
            ans[(*returnSize)++] = node->val;                   /* 把当前节点的值放入ret数组的 *returnSize 索引，并将 *returnSize 索引值 + 1 */
            stk[stk_top++] = node;                              /* 入栈：将当前节点指针放入栈顶，并将栈顶索引 + 1 */
            node = node->left;                                  /* 节点指针向左移动 */
        }
        node = stk[--stk_top];                              /* 出栈：当节点指针指向NULL - 左节点指针已经到头：获取栈顶节点指针，并将栈顶索引 - 1 */
        node = node->right;                                 /* 节点指针向右移动 */
    }
    return ans;                                         /* 返回结果数组 */
}

/* ============================================================================== */
/* ============================================================================== */
/*
 * 树结构表示：
 *       1
 *      / \
 *     2   3
 *    / \ / \
 *   4  5 6  7
 *
 * 中序遍历：
 * [4, 2, 5, 1, 6, 3, 7]
 */
/* ============================================================================== */
/* ============================================================================== */
/**
 * @description: 中序遍历
 * =================================================================================
 * @param {TreeNode} *node      当前节点指针
 * @param {int} *ans            用于储存遍历答案的数组
 * @param {int} *returnSize     用于储存遍历答案的数组的大小
 * @return {void}
 */
void inOrder(struct TreeNode *node, int *ans, int *returnSize) {
    if (node == NULL) {                                 /* 如果当前节点为 NULL，直接返回 */
        return;
    }
    inOrder(node->left, ans, returnSize);               /* 中序遍历左节点 */
    ans[(*returnSize)++] = node->val;                   /* 把当前节点的值放入ret数组的 *returnSize 索引，并将 *returnSize 索引值 + 1 */
    inOrder(node->right, ans, returnSize);              /* 中序遍历右节点 */
}

/**
 * @description: 中序遍历 - 递归方法
 * =================================================================================
 * @param {TreeNode} *root      根节点指针
 * @param {int} *returnSize     用于储存遍历答案的数组的大小
 * @return {int} *ans           用于储存遍历答案的数组
 */
int *inorderTraversal_recursion(struct TreeNode *root, int *returnSize) {
    int *ans = (int *)malloc(sizeof(int) * MAX_SIZE);   /* 初始化一个100长度的 ans 数组，用于储存遍历答案（后期需要free） */
    *returnSize = 0;                                    /* 初始化数组的大小为 0 */
    inOrder(root, ans, returnSize);                     /* 中序遍历根节点 */
    return ans;                                         /* 返回结果 ans 数组 */
}

/**
 * @description: 中序遍历 - 迭代方法
 * =================================================================================
 * @param {TreeNode} *root      根节点指针
 * @param {int} *returnSize     用于储存遍历答案的数组的大小
 * @return {int} *ans           用于储存遍历答案的数组
 */
int *inorderTraversal_iteration(struct TreeNode *root, int *returnSize) {
    int *ans = (int *)malloc(sizeof(int) * MAX_SIZE);   /* 初始化一个MAX_SIZE长度的 ans 数组，用于储存遍历答案 */
    *returnSize = 0;                                    /* 初始化数组的大小为 0 */
    if (root == NULL) {                                 /* 如果当前节点为 NULL，直接返回 */
        return ans;
    }

    struct TreeNode **stk = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * MAX_SIZE);   /* 分配一个MAX_SIZE容量的树节点栈空间（后期需要free） */
    int stk_top = 0;                                    /* 栈顶索引为 0 */
    struct TreeNode *node = root;                       /* 获取根节点的指针 */
    while (node != NULL || stk_top > 0) {               /* 当栈顶索引大于0 或者 节点指针不指向NULL */
        while (node != NULL) {                              /* 当结点指针不指向NULL */
            stk[stk_top++] = node;                              /* 入栈：将当前节点指针放入栈顶，并将栈顶索引 + 1 */
            node = node->left;                                  /* 节点指针向左移动 */
        }
        node = stk[--stk_top];                              /* 出栈：当节点指针指向NULL - 左节点指针已经到头：获取栈顶节点指针，并将栈顶索引 - 1 */
        ans[(*returnSize)++] = node->val;                   /* 把当前节点的值放入ret数组的 *returnSize 索引，并将 *returnSize 索引值 + 1 */
        node = node->right;                                 /* 节点指针向右移动 */
    }
    return ans;                                         /* 返回结果数组 */
}

/* ============================================================================== */
/* ============================================================================== */
/*
 * 树结构表示：
 *       1
 *      / \
 *     2   3
 *    / \ / \
 *   4  5 6  7
 *
 * 后序遍历：
 * [4, 5, 2, 6, 7, 3, 1]
 */
/* ============================================================================== */
/* ============================================================================== */
/**
 * @description: 后序遍历
 * =================================================================================
 * @param {TreeNode} *node      当前节点指针
 * @param {int} *ans            用于储存遍历答案的数组
 * @param {int} *returnSize     用于储存遍历答案的数组的大小
 * @return {void}
 */
void postOrder(struct TreeNode *node, int *ans, int *returnSize) {
    if (node == NULL) {                                     /* 如果当前节点为 NULL，直接返回 */
        return;
    }
    postOrder(node->left, ans, returnSize);                 /* 后序遍历左节点 */
    postOrder(node->right, ans, returnSize);                /* 后序遍历右节点 */
    ans[(*returnSize)++] = node->val;                       /* 把当前节点的值放入ret数组的 *returnSize 索引，并将 *returnSize 索引值 + 1 */
}

/**
 * @description: 后序遍历 - 递归方法
 * =================================================================================
 * @param {TreeNode} *root      根节点指针
 * @param {int} *returnSize     用于储存遍历答案的数组的大小
 * @return {int} *ans           用于储存遍历答案的数组
 */
int *postorderTraversal_recursion(struct TreeNode *root, int *returnSize) {
    int *ans = (int *)malloc(sizeof(int) * MAX_SIZE);       /* 初始化一个 MAX_SIZE 长度的 ans 数组，用于储存遍历答案（后期需要free） */
    *returnSize = 0;                                        /* 初始化数组的大小为 0 */
    postOrder(root, ans, returnSize);                       /* 后序遍历根节点 */
    return ans;                                             /* 返回结果 ans 数组 */
}

/**
 * @description: 后序遍历 - 迭代方法
 * =================================================================================
 * @param {TreeNode} *root      根节点指针
 * @param {int} *returnSize     用于储存遍历答案的数组的大小
 * @return {int} *ans           用于储存遍历答案的数组
 */
int *postorderTraversal_iteration(struct TreeNode *root, int *returnSize) {
    int *ans = (int *)malloc(sizeof(int) * MAX_SIZE);       /* NOLINT(readability/casting) */
    *returnSize = 0;                                        /* 初始化数组的大小为 0 */
    if (root == NULL) {                                     /* 如果当前节点为 NULL，直接返回 */
        return ans;
    }

    struct TreeNode *stk[MAX_SIZE];                         /* 用数组实现初始化一个MAX_SIZE容量的树节点栈 */
    int stk_top = 0;                                        /* 栈顶索引为 0 */
    struct TreeNode *node = root;                           /* 获取根节点的指针 */
    struct TreeNode *prev = NULL;                           /* 设置前节点的指针为 NULL */
    while (node != NULL || stk_top > 0) {                   /* 当栈顶索引大于0 或者 节点指针不指向NULL */
        while (node != NULL) {                                  /* 当结点指针不指向NULL */
            stk[stk_top++] = node;                                  /* 入栈：将当前节点指针放入栈顶，并将栈顶索引 + 1 */
            node = node->left;                                      /* 节点指针向左移动 */
        }
        node = stk[--stk_top];                                  /* 出栈：当节点指针指向NULL - 左节点指针已经到头：获取栈顶节点指针，并将栈顶索引 - 1 */
        if (node->right == NULL || node->right == prev) {       /* 如果右节点为NULL 或者 右节点为前节点 */
            ans[(*returnSize)++] = node->val;                       /* 把当前节点的值放入ret数组的 *returnSize 索引，并将 *returnSize 索引值 + 1 */
            prev = node;                                            /* 给前节点指针赋值为当前节点 */
            node = NULL;                                            /* 把当前节点指针赋值为 NULL*/
        } else {                                                /* 否则 */
            stk[stk_top++] = node;                                  /* 入栈：将当前节点指针放入栈顶，并将栈顶索引 + 1 */
            node = node->right;                                     /* 节点指针向右移动 */
        }
    }
    return ans;                                             /* 返回结果数组 */
}

/**********************************************************************************/
/*                                                                                */
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/* ============================================================================== */
/* 树列表队列操作 */
/* ============================================================================== */
/**
 * @description: 创建一个新的二叉树节点队列
 * =================================================================================
 * @param {int} queueSize       队列的大小
 * @return {TreeArrQueue} *queue   新的二叉树节点队列指针
 */
TreeArrQueue *newTreeArrQueue(int queueSize) {
    TreeArrQueue *queue = (TreeArrQueue *)malloc(sizeof(TreeArrQueue)); /* NOLINT(readability/casting) */
    queue->array = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * queueSize);
    queue->head = 0;
    queue->tail = 0;
    queue->size = queueSize;
    return queue;
}

/**
 * @description: 将节点加入队列
 * =================================================================================
 * @param {TreeArrQueue} *queue    二叉树节点队列指针
 * @param {TreeNode} *node      节点指针
 * @return {void}
 */
void enTreeArrQueue(TreeArrQueue *queue, struct TreeNode *node) {
    if ((queue->tail + 1) % queue->size == queue->head) {
        printf("Queue is full.\n");
        return;
    }
    queue->array[queue->tail] = node;
    queue->tail = (queue->tail + 1) % queue->size;
}

/**
 * @description: 从队列中取出一个节点
 * =================================================================================
 * @param {TreeArrQueue} *queue        二叉树节点队列指针
 * @return {TreeNode} *node         节点指针
 */
struct TreeNode *deTreeArrQueue(TreeArrQueue *queue) {
    if (queue->head == queue->tail) {
        printf("Queue is empty.\n");
        return NULL;
    }
    struct TreeNode *node = queue->array[queue->head];
    queue->head = (queue->head + 1) % queue->size;
    return node;
}

/**
 * @description: 判断队列是否为空
 * =================================================================================
 * @param {TreeArrQueue} *queue        二叉树节点队列指针
 * @return {int}                    如果队列为空，返回1；否则返回0
 */
int isTreeArrQueueEmpty(TreeArrQueue *queue) {
    return queue->head == queue->tail;
}

/**
 * @description: 判断队列是否为满
 * =================================================================================
 * @param {TreeArrQueue} *queue        二叉树节点队列指针
 * @return {int}                    如果队列为满，返回1；否则返回0
 */
int isTreeArrQueueFull(TreeArrQueue *queue) {
    return (queue->tail + 1) % queue->size == queue->head;
}

/**
 * @description: 打印二叉树节点队列
 * =================================================================================
 * @param {TreeArrQueue} *queue        二叉树节点队列指针
 * @return {void}
 */
void printTreeArrQueue(TreeArrQueue *queue) {
    printf("TreeArrQueue (size = %d): [", queue->size);
    for (int i = queue->head; i != queue->tail; i = (i + 1) % queue->size) {
        printf("%d", queue->array[i]->val);
        if ((i + 1) % queue->size != queue->tail) {
            printf(", ");
        }
    }
    printf("]\n");
}

/**
 * @description: 释放二叉树节点队列的空间
 * =================================================================================
 * @param {TreeArrQueue} *queue    二叉树节点队列指针
 * @return {void}
 */
void freeTreeArrQueue(TreeArrQueue *queue) {
    free(queue->array);
    free(queue);
}

/* ============================================================================== */
/* 树链表队列操作 */
/* ============================================================================== */
/**
 * @description: 创建一个新的二叉树节点链表队列
 * =================================================================================
 * @return {TreeListQueue} *queue   新的二叉树节点链表队列指针
 */
TreeListQueue *newTreeListQueue(void) {

}

/**
 * @description: 将节点加入队列
 * =================================================================================
 * @param {TreeListQueue} *queue    二叉树节点链表队列指针
 * @param {TreeNode} *node          节点指针
 * @return {void}
 */
void enTreeListQueue(TreeListQueue *queue, struct TreeNode *node) {

}

/**
 * @description: 从队列中取出一个节点
 * =================================================================================
 * @param {TreeListQueue} *queue    二叉树节点链表队列指针
 * @return {TreeNode} *node         节点指针
 */
struct TreeNode *deTreeListQueue(TreeListQueue *queue) {

}

/**
 * @description: 判断队列是否为空
 * =================================================================================
 * @param {TreeListQueue} *queue    二叉树节点链表队列指针
 * @return {int}                    如果队列为空，返回1；否则返回0
 */
int isTreeListQueueEmpty(TreeListQueue *queue) {

}

/**
 * @description: 判断队列是否为满
 * =================================================================================
 * @param {TreeListQueue} *queue    二叉树节点链表队列指针
 * @return {int}                    如果队列为满，返回1；否则返回0
 */
int isTreeListQueueFull(TreeListQueue *queue) {

}

/**
 * @description: 打印二叉树节点链表队列
 * =================================================================================
 * @param {TreeListQueue} *queue    二叉树节点链表队列指针
 * @return {void}
 */
void printTreeListQueue(TreeListQueue *queue) {

}

/**
 * @description: 释放二叉树节点链表队列的空间
 * =================================================================================
 * @param {TreeListQueue} *queue    二叉树节点链表队列指针
 * @return {void}
 */
void freeTreeListQueue(TreeListQueue *queue) {

}

/* ============================================================================== */
/* 树操作 */
/* ============================================================================== */
/**
 * @description: 创建一个新的树节点
 * =================================================================================
 * @param {int} value           节点的值
 * @return {TreeNode} *node     新的树节点指针
 */
struct TreeNode *newTreeNode(int value) {
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/**
 * @description: 将数组转换为二叉树
 * =================================================================================
 * @param {int*} arr                数组指针
 * @param {int} arrSize             数组大小
 * @return {TreeNode} *node         根节点指针
 */
struct TreeNode *arrayToTree(int* arr, int arrSize) {
    if (arrSize == 0) {
        return NULL;
    }

    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = arr[0];
    root->left = NULL;
    root->right = NULL;

    TreeArrQueue *queue = newTreeArrQueue(arrSize);
    queue->array[queue->tail++] = root;

    for (int i = 1; i < arrSize; i++) {
        struct TreeNode *node = queue->array[queue->head++];
        if (i < arrSize) {
            node->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            node->left->val = arr[i];
            node->left->left = NULL;
            node->left->right = NULL;
            queue->array[queue->tail++] = node->left;
        }
        if (++i < arrSize) {
            node->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            node->right->val = arr[i];
            node->right->left = NULL;
            node->right->right = NULL;
            queue->array[queue->tail++] = node->right;
        }
    }
    freeTreeArrQueue(queue);
    return root;
}

/**
 * @description: 将二叉树转换为数组
 * =================================================================================
 * @param {TreeNode} *root      根节点指针
 * @param {int} *returnSize     数组长度指针
 * @return {int} *result        转换后的数组指针
 */
int *treeToArray(struct TreeNode *root, int *returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    int *result = (int *)malloc(MAX_SIZE * sizeof(int));
    TreeArrQueue *q = newTreeArrQueue(MAX_SIZE);
    enTreeArrQueue(q, root);
    int index = 0;

    while (!isTreeArrQueueEmpty(q)) {
        struct TreeNode *current = deTreeArrQueue(q);
        if (current) {
            result[index] = current->val;
            enTreeArrQueue(q, current->left);
            enTreeArrQueue(q, current->right);
        } else {
            result[index] = INT_MIN;
        }
        index++;
    }

    *returnSize = index;
    freeTreeArrQueue(q);
    return result;
}

/**
 * @description: 打印示意树结构
 * =================================================================================
 * @return {void}
 */
void printTestTree(void) {
    printf("Test Tree:\n");
    printf("      1 \n");
    printf("     / \\ \n");
    printf("    2   3 \n");
    printf("   / \\ / \\ \n");
    printf("  4  5 6  7 \n");
    printf("\n");
}

/**
 * @description: 打印二叉树
 * =================================================================================
 * @param {TreeNode} *root      根节点指针
 * @return {void}
 */
void printTree(struct TreeNode *root) {
    if (root == NULL) {             /* 如果传入节点为 NULL 则返回 */
        return;
    }
    printf("%d ", root->val);       /* 打印当前节点的值 */
    printTree(root->left);          /* 遍历打印左节点 */
    printTree(root->right);         /* 遍历打印右节点 */
}

/**
 * @description: 释放二叉树的空间
 * =================================================================================
 * @param {TreeNode} *root      根节点指针
 * @return {void}
 */
void freeTree(struct TreeNode *root) {
    if (root == NULL) {             /* 如果传入节点为 NULL 则返回 */
        return;
    }
    freeTree(root->left);           /* 遍历释放左节点空间 */
    freeTree(root->right);          /* 遍历释放右节点空间 */
    free(root);                     /* 释放当前节点空间 */
}


#endif      /* COMMON_BINARY_TREE_EN */