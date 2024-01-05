/*
 * @FilePath     : \Practice_LeetCode_C\02_Programming_Topics\07_Binary_Tree\05_levelOrderBottom\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-28 09:44:35
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-02 02:15:30
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 107. 二叉树的层序遍历 II：从下往上层序遍历二叉树
 * 107. 二叉树的层序遍历 II: https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/
 * https://programmercarl.com/0102.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86.html#_102-%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86
 * 解法参考：https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/solutions/402560/er-cha-shu-de-ceng-ci-bian-li-ii-by-leetcode-solut/
 * 解法参考：https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/solutions/1298370/er-cha-shu-de-ceng-xu-bian-li-ii-cyu-yan-u762/
 *
 *       1
 *      / \
 *     2   3
 *    / \ / \
 *   4  5 6  7
 *
 * 层序遍历：
 * [
 *   [4, 5, 6, 7]
 *   [2, 3]
 *   [1]
 * ]
 *
 */

/* standard header file (标准头文件) */
#include <stdio.h>
#include <stdlib.h>
/* common function header file (通用头文件) */
#include "commonArray.h"
#include "commonBinaryTree.h"
/* solution header file (题解头文件) */
#include "BTree_LevelOrderBottom.h"

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
    struct TreeNode *root = BTree_InitNode(1);
    root->left = BTree_InitNode(2);
    root->right = BTree_InitNode(3);

    root->left->left = BTree_InitNode(4);
    root->left->right = BTree_InitNode(5);

    root->right->left = BTree_InitNode(6);
    root->right->right = BTree_InitNode(7);

    int returnSize = 0;
    int *returnColumnSizes;

    /* 函数调用 */
    int** result = BTree_LevelOrderBottom(root, &returnSize, &returnColumnSizes);
    Array_Print2D(result, returnSize, returnColumnSizes);

    return 0;
}