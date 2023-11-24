/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\src\commonBinaryTree.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-01 20:07:37
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-24 23:02:48
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
 *
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
 *
 */
/* 编译配置文件 */
#include "compileCfg.h"
#if COMMON_BINARY_TREE_EN         /* 在每一道题 cfg 文件夹下的 compileCfg.h 开启编译宏定义 */
/* 标准头文件 */
#include <stdio.h>
#include <stdlib.h>
/* 常用头文件 */
#include "commonBinaryTree.h"

/**********************************************************************************/
/*                                                                                */
/*                                MACRO CONSTANTS                                 */
/*                                                                                */
/**********************************************************************************/
#define MAX_SIZE 100                /* 数组和栈的大小 */

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
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
    int *ans = (int *)malloc(sizeof(int) * MAX_SIZE);   /* 初始化一个MAX_SIZE长度的 ans 数组，用于储存遍历答案（后期需要free） */
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
    int *ans = (int *)malloc(sizeof(int) * MAX_SIZE);       /* 初始化一个MAX_SIZE长度的 ans 数组，用于储存遍历答案（后期需要free） */
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
/**
 * @description: 创建一个新的树节点
 * =================================================================================
 * @param {int} value           节点的值
 * @return {TreeNode} *node     新的树节点指针
 */
struct TreeNode *newNode(int value) {
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

    struct TreeNode **queue = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * arrSize);
    int queue_front = 0;
    int queue_rear = 0;
    queue[queue_rear++] = root;

    for (int i = 1; i < arrSize; i++) {
        struct TreeNode *node = queue[queue_front++];
        if (arr[i] != NULL) {
            node->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            node->left->val = arr[i];
            node->left->left = NULL;
            node->left->right = NULL;
            queue[queue_rear++] = node->left;
        }
        if (++i < arrSize && arr[i] != NULL) {
            node->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            node->right->val = arr[i];
            node->right->left = NULL;
            node->right->right = NULL;
            queue[queue_rear++] = node->right;
        }
    }
    free(queue);
    return root;
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


#endif      /* COMMON_BINARY_TREE_EN */