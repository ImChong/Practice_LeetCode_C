/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\07_Binary_Tree\00_common\binaryTreeCommon.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-01 20:07:37
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-09-15 12:17:54
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 二叉树的常用函数
 *
 * 用数组来存储二叉树: 如果父节点的数组下标是 i，那么它的左孩子就是 i * 2 + 1，右孩子就是 i * 2 + 2。
 *
 * 二叉树主要有两种遍历方式：
 *   深度优先遍历：先往深走，遇到叶子节点再往回走。
 *       前序遍历（递归法，迭代法）
 *       中序遍历（递归法，迭代法）
 *       后序遍历（递归法，迭代法）
 *   广度优先遍历：一层一层的去遍历。
 *       层次遍历（迭代法）
 *
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
#include <stdio.h>
#include <stdlib.h>

/* 控制函数运行的宏定义 */
#define MAX_SIZE 100                /* 数组和栈的大小 */
#define PRE_ORDER_TRAVERSAL_EN 1    /* 前序遍历代码开关 */
#define IN_ORDER_TRAVERSAL_EN 1     /* 中序遍历代码开关 */
#define POST_ORDER_TRAVERSAL_EN 1   /* 后序遍历代码开关 */
#define RECURSION_EN 1              /* 递归代码开关 */
#define ITERATION_EN 1              /* 迭代代码开关 */

/* 树节点 */
struct TreeNode {
    int val;                    /* 节点的值 */
    struct TreeNode *left;      /* 左节点 */
    struct TreeNode *right;     /* 右节点 */
};

#if PRE_ORDER_TRAVERSAL_EN
/* ==================================================================================================== */
/**
 * @description: 144.二叉树的前序遍历：https://leetcode.cn/problems/binary-tree-preorder-traversal/
 * 遍历顺序：根节点 -> 左子树 -> 右子树
 * 用途：前序遍历通常用于复制二叉树或构建与原二叉树结构相同的二叉树。
 * =================================================================================
 * @param {struct TreeNode} *root   二叉树的根节点
 * @param {int} *returnSize         返回数组的大小
 * @return {int} *ret               返回数组的指针
 */
/* ==================================================================================================== */
    #if RECURSION_EN
/* 前序遍历 - 递归 */
void preOrder(struct TreeNode *node, int *ret, int *returnSize) {
    if (node == NULL) {                                 /* 如果当前节点为 NULL，直接返回 */
        return;
    }
    ret[(*returnSize)++] = node->val;                   /* 把当前节点的值放入ret数组的 *returnSize 索引，并将 *returnSize 索引值 + 1 */
    preOrder(node->left, ret, returnSize);              /* 前序遍历左节点 */
    preOrder(node->right, ret, returnSize);             /* 前序遍历右节点 */
}

int *preorderTraversal_recursion(struct TreeNode *root, int *returnSize) {
    int *ret = (int *)malloc(sizeof(int) * MAX_SIZE);   /* 初始化一个MAX_SIZE长度的 ret 数组，用于储存遍历答案（后期需要free） */
    *returnSize = 0;                                    /* 初始化数组的大小为 0 */
    preOrder(root, ret, returnSize);                    /* 前序遍历根节点 */
    return ret;                                         /* 返回结果 ret 数组 */
}
    #endif

    #if ITERATION_EN
/* 前序遍历 - 迭代 */
int *preorderTraversal_iteration(struct TreeNode *root, int *returnSize) {
    int *res = (int *)malloc(sizeof(int) * MAX_SIZE);   /* 初始化一个MAX_SIZE长度的 ret 数组，用于储存遍历答案（后期需要free） */
    *returnSize = 0;                                    /* 初始化数组的大小为 0 */
    if (root == NULL) {                                 /* 如果当前节点为 NULL，直接返回 */
        return res;
    }

    struct TreeNode *stk[MAX_SIZE];                     /* 用数组实现初始化一个MAX_SIZE容量的树节点栈 */
    int stk_top = 0;                                    /* 栈顶索引为 0 */
    struct TreeNode *node = root;                       /* 获取根节点的指针 */
    while (stk_top > 0 || node != NULL) {               /* 当栈顶索引大于0 或者 节点指针不指向NULL */
        while (node != NULL) {                              /* 当结点指针不指向NULL */
            res[(*returnSize)++] = node->val;                   /* 把当前节点的值放入ret数组的 *returnSize 索引，并将 *returnSize 索引值 + 1 */
            stk[stk_top++] = node;                              /* 入栈：将当前节点指针放入栈顶，并将栈顶索引 + 1 */
            node = node->left;                                  /* 节点指针向左移动 */
        }
        node = stk[--stk_top];                              /* 出栈：当节点指针指向NULL - 左节点指针已经到头：获取栈顶节点指针，并将栈顶索引 - 1 */
        node = node->right;                                 /* 节点指针向右移动 */
    }
    return res;                                         /* 返回结果数组 */
}
    #endif
#endif


#if IN_ORDER_TRAVERSAL_EN
/* ==================================================================================================== */
/**
 * @description: 94.二叉树的中序遍历: https://leetcode.cn/problems/binary-tree-inorder-traversal/
 * 遍历顺序：左子树 -> 根节点 -> 右子树
 * 用途：对于二叉搜索树（BST），中序遍历会按照递增的顺序访问所有节点。
 * =================================================================================
 * @param {struct TreeNode} *root   二叉树的根节点
 * @param {int} *returnSize         返回数组的大小
 * @return {int} *ret               返回数组的指针
 */
/* ==================================================================================================== */
    #if RECURSION_EN
/* 中序遍历 - 递归 */
void inOrder(struct TreeNode *node, int *ret, int *returnSize) {
    if (node == NULL) {                                 /* 如果当前节点为 NULL，直接返回 */
        return;
    }
    inOrder(node->left, ret, returnSize);               /* 中序遍历左节点 */
    ret[(*returnSize)++] = node->val;                   /* 把当前节点的值放入ret数组的 *returnSize 索引，并将 *returnSize 索引值 + 1 */
    inOrder(node->right, ret, returnSize);              /* 中序遍历右节点 */
}

int *inorderTraversal_recursion(struct TreeNode *root, int *returnSize) {
    int *ret = (int *)malloc(sizeof(int) * MAX_SIZE);   /* 初始化一个100长度的 ret 数组，用于储存遍历答案（后期需要free） */
    *returnSize = 0;                                    /* 初始化数组的大小为 0 */
    inOrder(root, ret, returnSize);                     /* 中序遍历根节点 */
    return ret;                                         /* 返回结果 ret 数组 */
}
    #endif

    #if ITERATION_EN
/* 中序遍历 - 迭代 */
int *inorderTraversal_iteration(struct TreeNode *root, int *returnSize) {
    int *res = (int *)malloc(sizeof(int) * MAX_SIZE);   /* 初始化一个MAX_SIZE长度的 ret 数组，用于储存遍历答案 */
    *returnSize = 0;                                    /* 初始化数组的大小为 0 */
    if (root == NULL) {                                 /* 如果当前节点为 NULL，直接返回 */
        return res;
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
        res[(*returnSize)++] = node->val;                   /* 把当前节点的值放入ret数组的 *returnSize 索引，并将 *returnSize 索引值 + 1 */
        node = node->right;                                 /* 节点指针向右移动 */
    }
    return res;                                         /* 返回结果数组 */
}
    #endif
#endif


#if POST_ORDER_TRAVERSAL_EN
/* ==================================================================================================== */
/**
 * @description: 145.二叉树的后序遍历：https://leetcode.cn/problems/binary-tree-postorder-traversal/
 * 遍历顺序：左子树 -> 右子树 -> 根节点
 * 用途：后序遍历常用于删除二叉树或进行其他需要从底向上进行操作的场景。
 * =================================================================================
 * @param {struct TreeNode} *root   二叉树的根节点
 * @param {int} *returnSize         返回数组的大小
 * @return {int} *ret               返回数组的指针
 */
/* ==================================================================================================== */
    #if RECURSION_EN
/* 后序遍历 - 递归 */
void postOrder(struct TreeNode *node, int *ret, int *returnSize) {
    if (node == NULL) {                                     /* 如果当前节点为 NULL，直接返回 */
        return;
    }
    postOrder(node->left, ret, returnSize);                 /* 后序遍历左节点 */
    postOrder(node->right, ret, returnSize);                /* 后序遍历右节点 */
    ret[(*returnSize)++] = node->val;                       /* 把当前节点的值放入ret数组的 *returnSize 索引，并将 *returnSize 索引值 + 1 */
}

int *postorderTraversal_recursion(struct TreeNode *root, int *returnSize) {
    int *ret = (int *)malloc(sizeof(int) * MAX_SIZE);       /* 初始化一个 MAX_SIZE 长度的 ret 数组，用于储存遍历答案（后期需要free） */
    *returnSize = 0;                                        /* 初始化数组的大小为 0 */
    postOrder(root, ret, returnSize);                       /* 后序遍历根节点 */
    return ret;                                             /* 返回结果 ret 数组 */
}
    #endif

    #if ITERATION_EN
/* 后序遍历 - 迭代 */
int *postorderTraversal_iteration(struct TreeNode *root, int *returnSize) {
    int *res = (int *)malloc(sizeof(int) * MAX_SIZE);       /* 初始化一个MAX_SIZE长度的 ret 数组，用于储存遍历答案（后期需要free） */
    *returnSize = 0;                                        /* 初始化数组的大小为 0 */
    if (root == NULL) {                                     /* 如果当前节点为 NULL，直接返回 */
        return res;
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
            res[(*returnSize)++] = node->val;                       /* 把当前节点的值放入ret数组的 *returnSize 索引，并将 *returnSize 索引值 + 1 */
            prev = node;                                            /* 给前节点指针赋值为当前节点 */
            node = NULL;                                            /* 把当前节点指针赋值为 NULL*/
        } else {                                                /* 否则 */
            stk[stk_top++] = node;                                  /* 入栈：将当前节点指针放入栈顶，并将栈顶索引 + 1 */
            node = node->right;                                     /* 节点指针向右移动 */
        }
    }
    return res;                                             /* 返回结果数组 */
}
    #endif
#endif

/* ==================================================================================================== */
/* ==================================================================================================== */
/* ==================================================================================================== */
/* ==================================================================================================== */

/**
 * @description: 创建树节点
 * =================================================================================
 * @param {int} value                   节点数值
 * @return {struct TreeNode} *node      二叉树节点
 */
struct TreeNode *newNode(int value) {
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/**
 * @description: 后续遍历释放树所占用的空间
 * =================================================================================
 * @param {TreeNode} *root
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
 * @description: 打印树结构
 * =================================================================================
 * @return {void}
 */
void printTree(void) {
    printf("      1 \n");
    printf("     / \\ \n");
    printf("    2   3 \n");
    printf("   / \\ / \\ \n");
    printf("  4  5 6  7 \n");
    printf("\n");
}

/**
 * @description: 打印一维数组
 * =================================================================================
 * @param {int} *array      一维数组
 * @param {int} size        一维数组的大小
 * @return {void}
 */
void print1DArray(int *array, int size) {
    printf("[");                        /* 打印行边框 [ */
    for (int i = 0; i < size; ++i) {        /* 遍历 array 内的元素 */
        printf("%d", array[i]);                 /* 打印 array 内的元素 */
        if (i < size - 1) {                     /* 打印分隔符：, */
            printf(", ");
        }
    }
    printf("]\n");                      /* 打印行边框 ] */
}

/**
 * @description: 主函数
 * =================================================================================
 * @param {int} argc        程序入参个数
 * @param {char} *argv[]    程序入参字符串数组
 * @return {int}            程序运行状态
 */
int main(int argc, const char* argv[]) {
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

    printTree();            /* 打印树结构 */

    int returnSize = 0;     /* 初始化结果数组大小 */
    int *result = NULL;     /* 初始化结果数组指针为 NULL */

#if PRE_ORDER_TRAVERSAL_EN
    #if RECURSION_EN
    printf("preorderTraversal_recursion: \n");
    result = preorderTraversal_recursion(root, &returnSize);
    print1DArray(result, returnSize);
    #endif

    #if ITERATION_EN
    printf("preorderTraversal_iteration: \n");
    result = preorderTraversal_iteration(root, &returnSize);
    print1DArray(result, returnSize);
    #endif
#endif

#if IN_ORDER_TRAVERSAL_EN
    #if RECURSION_EN
    printf("inorderTraversal_recursion: \n");
    result = inorderTraversal_recursion(root, &returnSize);
    print1DArray(result, returnSize);
    #endif

    #if ITERATION_EN
    printf("inorderTraversal_iteration: \n");
    result = inorderTraversal_iteration(root, &returnSize);
    print1DArray(result, returnSize);
    #endif
#endif

#if POST_ORDER_TRAVERSAL_EN
    #if RECURSION_EN
    printf("postorderTraversal_recursion: \n");
    result = postorderTraversal_recursion(root, &returnSize);
    print1DArray(result, returnSize);
    #endif

    #if ITERATION_EN
    printf("postorderTraversal_iteration: \n");
    result = postorderTraversal_iteration(root, &returnSize);
    print1DArray(result, returnSize);
    #endif
#endif

    free(result);
    return 0;
}