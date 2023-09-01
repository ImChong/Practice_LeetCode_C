/*
 * @File: main_chong.c
 * @Created Date: 2023-08-28 9:44:35 am
 * @Author: Chong Liu
 * @Brief: 94.二叉树的中序遍历: https://leetcode.cn/problems/binary-tree-inorder-traversal/
 * https://programmercarl.com/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E9%80%92%E5%BD%92%E9%81%8D%E5%8E%86.html
 * =================================================================================
 * Copyright (c) 2023 Chong Liu
 * =================================================================================
 * Last Modified: Chong Liu - 2023-09-01 10:40:54 am
 */
#include <stdio.h>

/* ==================================================================================================== */
/* inorderTraversal()
 *  Functionality: 二叉树的中序遍历
 *  Arguments: struct TreeNode* root, int* returnSize
 *  Return: int *ret
 *  References: https://programmercarl.com/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E9%80%92%E5%BD%92%E9%81%8D%E5%8E%86.html
 ***********************************************************************************
 *  IMPORTANT NOTICE FOR READER
 */
/* ==================================================================================================== */
/* TODO: 目标函数: 递归遍历 */
int* inorderTraversal_recursion(struct TreeNode* root, int* returnSize){

}

/* TODO: 目标函数：迭代遍历  */
int* inorderTraversal_iteration(struct TreeNode* root, int* returnSize){

}

/* ==================================================================================================== */
/* ==================================================================================================== */

/* NOTE：主函数 */
int main(int argc, const char* argv[]) {
    /*
     * 创建以下树结构
     *    1
     *   / \
     *  2   3
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

    /* NOTE: Test case 1 */
    printf("======== Case 1 ======== \n");
    int *result = inorderTraversal_recursion(&n1, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    /* NOTE: Test case 2 */
    printf("======== Case 2 ======== \n");
    result = inorderTraversal_iteration(&n1, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}