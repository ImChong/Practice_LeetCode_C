/*
 * @File: main_chong.c
 * @Created Date: 2023-08-28 9:44:35 am
 * @Author: Chong Liu
 * @Brief: 145.二叉树的后序遍历：https://leetcode.cn/problems/binary-tree-postorder-traversal/
 * https://programmercarl.com/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E9%80%92%E5%BD%92%E9%81%8D%E5%8E%86.html
 * =================================================================================
 * Copyright (c) 2023 Chong Liu
 * =================================================================================
 * Last Modified: Chong Liu - 2023-09-02 12:44:42 pm
 */

/* TODO: 重构 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100            /* 数组和栈的大小 */
#define RECURSION_EN 1          /* 递归代码开关 */
#define ITERATION_EN 1          /* 迭代代码开关 */

/* 树节点 */
struct TreeNode {
    int val;                    /* 节点的值 */
    struct TreeNode *left;      /* 左节点 */
    struct TreeNode *right;     /* 右节点 */
};

/* ==================================================================================================== */
/* ==================================================================================================== */
/* postorderTraversal()
 *  Functionality: 二叉树的后序遍历
 *  Arguments: struct TreeNode* root, int* returnSize
 *  Return: int *ret
 *  References: https://programmercarl.com/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E9%80%92%E5%BD%92%E9%81%8D%E5%8E%86.html
 ***********************************************************************************
 *  IMPORTANT NOTICE FOR READER
 *  遍历顺序：左子树 -> 右子树 -> 根节点
 *  用途：后序遍历常用于删除二叉树或进行其他需要从底向上进行操作的场景。
 *
 *  创建以下树结构
 *      1
 *     / \
 *    2   3
 *   / \ / \
 *  4  5 6  7
 *
 * 结果：[4, 5, 2, 6, 7, 3, 1]
 */
/* ==================================================================================================== */
/* ==================================================================================================== */
#if RECURSION_EN
/* 递归遍历 */
void postOrder(struct TreeNode *node, int *ret, int *returnSize) {
    if (node == NULL) {                                     /* 如果当前节点为 NULL，直接返回 */
        return;
    }
    postOrder(node->left, ret, returnSize);                 /* 后序遍历左节点 */
    postOrder(node->right, ret, returnSize);                /* 后序遍历右节点 */
    ret[(*returnSize)++] = node->val;                       /* 把当前节点的值放入ret数组的 *returnSize 索引，并将 *returnSize 索引值 + 1 */
}

int *postorderTraversal_recursion(struct TreeNode *root, int *returnSize) {
    int *ret = (int *)malloc(sizeof(int) * MAX_SIZE);       /* 初始化一个 MAX_SIZE 长度的 ret 数组，用于储存遍历答案 */
    *returnSize = 0;                                        /* 初始化数组的大小为 0 */
    postOrder(root, ret, returnSize);                       /* 后序遍历根节点 */
    return ret;                                             /* 返回结果 ret 数组 */
}
#endif

#if ITERATION_EN
/* 迭代遍历  */
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

/* ==================================================================================================== */
/* ==================================================================================================== */

/* 打印结果数组 */
void printArray(int *result, int returnSize) {
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\r\n");
}

/* 主函数 */
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

#if RECURSION_EN
    /* NOTE: Test case 1 */
    printf("======== recursion ======== \n");
    result = postorderTraversal_recursion(&n1, &returnSize);
    printArray(result, returnSize);
#endif

#if ITERATION_EN
    /* NOTE: Test case 2 */
    printf("======== iteration ======== \n");
    result = postorderTraversal_iteration(&n1, &returnSize);
    printArray(result, returnSize);
#endif

    return 0;
}