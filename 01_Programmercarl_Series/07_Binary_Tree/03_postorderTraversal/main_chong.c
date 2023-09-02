/*
 * @File: main_chong.c
 * @Created Date: 2023-08-28 9:44:35 am
 * @Author: Chong Liu
 * @Brief: 145.二叉树的后序遍历：https://leetcode.cn/problems/binary-tree-postorder-traversal/
 * https://programmercarl.com/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E9%80%92%E5%BD%92%E9%81%8D%E5%8E%86.html
 * =================================================================================
 * Copyright (c) 2023 Chong Liu
 * =================================================================================
 * Last Modified: Chong Liu - 2023-09-02 11:06:46 am
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100            /* 数组和栈的大小 */

/* NOTE: 树节点 */
struct TreeNode {
    int val;                    /* 节点的值 */
    struct TreeNode *left;      /* 左节点 */
    struct TreeNode *right;     /* 右节点 */
};

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
 * 结果：4 5 2 6 7 3 1
 */
/* ==================================================================================================== */
/* DONE: 目标函数: 递归遍历 */
void postOrder(struct TreeNode *node, int *ret, int *returnSize) {
    if (node == NULL) {                             /* 如果当前节点为 NULL，直接返回 */
        return;
    }
    postOrder(node->left, ret, returnSize);         /* 后序遍历左节点 */
    postOrder(node->right, ret, returnSize);        /* 后序遍历右节点 */
    ret[(*returnSize)++] = node->val;               /* 把当前节点的值放入ret数组的 *returnSize 索引，并将 *returnSize 索引值 + 1 */
}

int *postorderTraversal_recursion(struct TreeNode *root, int *returnSize) {
    int *ret = (int *)malloc(sizeof(int) * MAX_SIZE);       /* 初始化一个 MAX_SIZE 长度的 ret 数组，用于储存遍历答案 */
    *returnSize = 0;                                        /* 初始化数的大小为 0 */
    postOrder(root, ret, returnSize);                       /* 后序遍历根节点 */
    return ret;                                             /* 返回结果 ret 数组 */
}

/* TODO: 目标函数：迭代遍历  */
int* postorderTraversal_iteration(struct TreeNode* root, int* returnSize) {

    return NULL;
}

/* ==================================================================================================== */
/* ==================================================================================================== */
/* NOTE: 打印结果数组 */
void printArray(int *result, int returnSize) {
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\r\n");
}

/* NOTE：主函数 */
int main(int argc, const char* argv[]) {
    /*
     * 创建以下树结构
     *    1
     *     \
     *      2
     *     /
     *    3
     */
    struct TreeNode n1, n2, n3;     /* 初始化3个树节点 */
    n1.val = 1;     /* n1节点赋值为 1 */
    n2.val = 2;     /* n2节点赋值为 2 */
    n3.val = 3;     /* n3节点赋值为 3 */
    n1.left = NULL;     /* n1节点的左节点为 NULL */
    n1.right = &n2;     /* n1 节点的右节点为 n2 节点 */
    n2.left = &n3;      /* n2 节点的左节点为 n3 节点 */
    n2.right = NULL;    /* n2节点的右节点为 NULL */
    n3.left = NULL;     /* n3节点的左节点为 NULL */
    n3.right = NULL;    /* n3节点的右节点为 NULL */

    int returnSize = 0;
    int *result = NULL;

    /* NOTE: Test case 1 */
    printf("======== Case 1 ======== \n");
    result = postorderTraversal_recursion(&n1, &returnSize);
    printArray(result, returnSize);

    /* NOTE: Test case 2 */
    printf("======== Case 2 ======== \n");
    // result = postorderTraversal_iteration(&n1, &returnSize);
    // printArray(result, returnSize);

    return 0;
}