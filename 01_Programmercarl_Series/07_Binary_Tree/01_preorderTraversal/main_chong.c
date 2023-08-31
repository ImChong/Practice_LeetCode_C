/*
 * @File: main_chong.c
 * @Created Date: 2023-08-28 9:44:35 am
 * @Author: Chong Liu
 * @Brief: 144.二叉树的前序遍历：https://leetcode.cn/problems/binary-tree-preorder-traversal/
 * https://programmercarl.com/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E8%BF%AD%E4%BB%A3%E9%81%8D%E5%8E%86.html
 * =================================================================================
 * Copyright (c) 2023 Chong Liu
 * =================================================================================
 * Last Modified: Chong Liu - 2023-08-31 8:40:54 pm
 */
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/* ==================================================================================================== */
/* ==================================================================================================== */
/* TODO: 目标函数: 递归遍历 */
void preOrder(struct TreeNode *node, int *ret, int *returnSize) {
    if (node == NULL) {                             /* 如果当前节点为 NULL，直接返回 */
        return;
    }
    ret[(*returnSize)++] = node->val;               /* 把当前节点的值放入ret数组的 *returnSize 索引，并将 *returnSize 索引值 + 1 */
    preOrder(node->left, ret, returnSize);          /* 前序遍历左节点 */
    preOrder(node->right, ret, returnSize);         /* 前序遍历右节点 */
}

int *preorderTraversal_recursion(struct TreeNode *root, int *returnSize) {
    int *ret = (int *)malloc(sizeof(int) * 100);    /* 初始化一个100长度的 ret 数组，用于储存遍历答案 */
    *returnSize = 0;                                /* 初始化数的大小为 0 */
    preOrder(root, ret, returnSize);                /* 前序遍历根节点 */
    return ret;                                     /* 返回结果 ret 数组 */
}

/* TODO: 目标函数：迭代遍历  */
int* preorderTraversal_iteration(struct TreeNode *root, int *returnSize) {
    int *res = (int *)malloc(sizeof(int) * 2000);
    *returnSize = 0;
    if (!root) {
        return res;
    }

    struct TreeNode *stk[2000];
    struct TreeNode *node = root;
    int stk_top = 0;
    while (stk_top > 0 || node != NULL) {
        while (node != NULL) {
            res[(*returnSize)++] = node->val;
            stk[stk_top++] = node;
            node = node->left;
        }
        node = stk[--stk_top];
        node = node->right;
    }
    return res;
}
/* ==================================================================================================== */
/* ==================================================================================================== */

/* NOTE：主函数 */
int main(int argc, const char* argv[]) {
    /* NOTE: Test case 1 */
    printf("======== Case 1 ======== \n");

    /*
     * 创建以下树结构
     *
     *    1
     *   / \
     *  2   3
     *
     */


    struct TreeNode n1, n2, n3;     /* 初始化3个树节点 */
    n1.val = 1;     /* n1节点赋值为 1 */
    n2.val = 2;     /* n2节点赋值为 2 */
    n3.val = 3;     /* n3节点赋值为 3 */
    n1.left = NULL;     /* n1节点的左节点为 NULL */
    n1.right = &n2;     /* n1节点的右节点为 n2 节点 */
    n2.left = &n3;      /* n2节点的左节点为 n3 */
    n2.right = NULL;    /* n2节点的右节点为 NULL */
    n3.left = NULL;     /* n3节点的左节点为 NULL */
    n3.right = NULL;    /* n3节点的右节点为 NULL */

    int returnSize = 0;
    int *result = preorderTraversal_recursion(&n1, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }

    free(result);
    return 0;
}