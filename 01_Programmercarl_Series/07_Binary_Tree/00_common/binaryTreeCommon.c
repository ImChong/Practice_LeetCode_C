/*
 * @File: binaryTreeCommon.c
 * @Created Date: 2023-08-28 9:44:35 am
 * @Author: Chong Liu
 * @Brief: 二叉树的常用函数
 * =================================================================================
 * Copyright (c) 2023 Chong Liu
 * =================================================================================
 * Last Modified: Chong Liu - 2023-09-02 12:04:21 pm
 */

/* 用数组来存储二叉树: 如果父节点的数组下标是 i，那么它的左孩子就是 i * 2 + 1，右孩子就是 i * 2 + 2。*/
/*
 * 二叉树主要有两种遍历方式：
 *      深度优先遍历：先往深走，遇到叶子节点再往回走。
 *          前序遍历（递归法，迭代法）
 *          中序遍历（递归法，迭代法）
 *          后序遍历（递归法，迭代法）
 *      广度优先遍历：一层一层的去遍历。
 *          层次遍历（迭代法）
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100                /* 数组和栈的大小 */
#define PRE_ORDER_TRAVERSAL_EN 0    /* 前序遍历代码开关 */
#define IN_ORDER_TRAVERSAL_EN 0     /* 中序遍历代码开关 */
#define POST_ORDER_TRAVERSAL_EN 1   /* 后序遍历代码开关 */
#define RECURSION_EN 0              /* 递归代码开关 */
#define ITERATION_EN 1              /* 迭代代码开关 */

/* NOTE: 树节点 */
struct TreeNode {
    int val;                    /* 节点的值 */
    struct TreeNode *left;      /* 左节点 */
    struct TreeNode *right;     /* 右节点 */
};

#if PRE_ORDER_TRAVERSAL_EN
/* ==================================================================================================== */
/* preorderTraversal_recursion()
 *  Functionality: 前序遍历
 *  Arguments: struct TreeNode *root, int *returnSize
 *  Return: int *ret
 *  References: 144.二叉树的前序遍历：https://leetcode.cn/problems/binary-tree-preorder-traversal/
 ***********************************************************************************
 *  IMPORTANT NOTICE FOR READER
 *  遍历顺序：根节点 -> 左子树 -> 右子树
 *  用途：前序遍历通常用于复制二叉树或构建与原二叉树结构相同的二叉树。
 */
/* ==================================================================================================== */
    #if RECURSION_EN
/* NOTE: 前序遍历 - 递归 */
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
/* NOTE: 前序遍历 - 迭代 */
int* preorderTraversal_iteration(struct TreeNode *root, int *returnSize) {
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
/* inorderTraversal_recursion()
 *  Functionality: 中序遍历
 *  Arguments: struct TreeNode *root, int *returnSize
 *  Return: int *ret
 *  References: 94.二叉树的中序遍历: https://leetcode.cn/problems/binary-tree-inorder-traversal/
 ***********************************************************************************
 *  IMPORTANT NOTICE FOR READER
 *  遍历顺序：左子树 -> 根节点 -> 右子树
 *  用途：对于二叉搜索树（BST），中序遍历会按照递增的顺序访问所有节点。
 */
/* ==================================================================================================== */
    #if RECURSION_EN
/* NOTE: 中序遍历 - 递归 */
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
/* NOTE: 中序遍历 - 迭代 */
int* inorderTraversal_iteration(struct TreeNode* root, int* returnSize) {
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
/* postorderTraversal_recursion()
 *  Functionality: 后序遍历 - 递归
 *  Arguments: struct TreeNode *root, int *returnSize
 *  Return: int *ret
 *  References: 145.二叉树的后序遍历：https://leetcode.cn/problems/binary-tree-postorder-traversal/
 ***********************************************************************************
 *  IMPORTANT NOTICE FOR READER
 *  遍历顺序：左子树 -> 右子树 -> 根节点
 *  用途：后序遍历常用于删除二叉树或进行其他需要从底向上进行操作的场景。
 */
/* ==================================================================================================== */
    #if RECURSION_EN
/* NOTE: 后序遍历 - 递归 */
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
/* NOTE: 后序遍历 - 迭代 */
int* postorderTraversal_iteration(struct TreeNode* root, int* returnSize) {
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
/* printArray()
 *  Functionality: 打印结果数组
 *  Arguments: int *result, int returnSize
 *  Return: void
 *  References: document/website...
 ***********************************************************************************
 *  IMPORTANT NOTICE FOR READER
 */
/* ==================================================================================================== */
void printArray(int *result, int returnSize) {
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\r\n");
}

/* ==================================================================================================== */
/* main()
 *  Functionality: 主函数
 *  Arguments: int argc, const char* argv[]
 *  Return: int
 *  References: document/website...
 ***********************************************************************************
 *  IMPORTANT NOTICE FOR READER
 */
/* ==================================================================================================== */
int main(int argc, const char* argv[]) {
    /*
     * 创建以下树结构
     *      1
     *     / \
     *    2   3
     *   / \ / \
     *  4  5 6  7
     */
    struct TreeNode n1, n2, n3, n4, n5, n6, n7;     /* 初始化3个树节点 */
    n1.val = 1;     /* n1节点赋值为 1 */
    n2.val = 2;     /* n2节点赋值为 2 */
    n3.val = 3;     /* n3节点赋值为 3 */
    n4.val = 4;     /* n4节点赋值为 4 */
    n5.val = 5;     /* n5节点赋值为 5 */
    n6.val = 6;     /* n6节点赋值为 6 */
    n7.val = 7;     /* n7节点赋值为 7 */

    n1.left = &n2;      /* n1节点的左节点为 n2节点 */
    n1.right = &n3;     /* n1节点的右节点为 n3节点 */

    n2.left = &n4;      /* n2节点的左节点为 n4节点 */
    n2.right = &n5;     /* n2节点的右节点为 n5节点 */

    n3.left = &n6;      /* n3节点的左节点为 n6节点 */
    n3.right = &n7;     /* n3节点的右节点为 n7节点 */

    n4.left = NULL;     /* n4节点的左节点为 NULL */
    n4.right = NULL;    /* n4节点的右节点为 NULL */

    n5.left = NULL;     /* n5节点的左节点为 NULL */
    n5.right = NULL;    /* n5节点的右节点为 NULL */

    n6.left = NULL;     /* n6节点的左节点为 NULL */
    n6.right = NULL;    /* n6节点的右节点为 NULL */

    n7.left = NULL;     /* n7节点的左节点为 NULL */
    n7.right = NULL;    /* n7节点的右节点为 NULL */

    int returnSize = 0;
    int *result = NULL;

#if PRE_ORDER_TRAVERSAL_EN
    #if RECURSION_EN
    printf("preorderTraversal_recursion: \n");
    result = preorderTraversal_recursion(&n1, &returnSize);
    printArray(result, returnSize);
    #endif

    #if ITERATION_EN
    printf("preorderTraversal_iteration: \n");
    result = preorderTraversal_iteration(&n1, &returnSize);
    printArray(result, returnSize);
    #endif
#endif

#if IN_ORDER_TRAVERSAL_EN
    #if RECURSION_EN
    printf("inorderTraversal_recursion: \n");
    result = inorderTraversal_recursion(&n1, &returnSize);
    printArray(result, returnSize);
    #endif

    #if ITERATION_EN
    printf("inorderTraversal_iteration: \n");
    result = inorderTraversal_iteration(&n1, &returnSize);
    printArray(result, returnSize);
    #endif
#endif

#if POST_ORDER_TRAVERSAL_EN
    #if RECURSION_EN
    printf("postorderTraversal_recursion: \n");
    result = postorderTraversal_recursion(&n1, &returnSize);
    printArray(result, returnSize);
    #endif

    #if ITERATION_EN
    printf("postorderTraversal_iteration: \n");
    result = postorderTraversal_iteration(&n1, &returnSize);
    printArray(result, returnSize);
    #endif
#endif

    free(result);
    return 0;
}