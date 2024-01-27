/*
 * @FilePath     : \Practice_LeetCode_C\01_Programming_Topics\07_Binary_Tree\12_maxDepth\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-28 09:44:35
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-26 17:43:06
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 104. 二叉树的最大深度: https://leetcode.cn/problems/maximum-depth-of-binary-tree/
 * 解法参考: https://leetcode.cn/problems/maximum-depth-of-binary-tree/solutions/349250/er-cha-shu-de-zui-da-shen-du-by-leetcode-solution/
 */

/* TODO: 重构 */
/* Standard header file (标准头文件) */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* Common function header file (通用头文件) */
#include "F01_Common_Functions/inc/common_single_value.h"
#include "commonBinaryTree.h"

/**********************************************************************************/
/*                                                                                */
/*                                MACRO CONSTANTS                                 */
/*                                                                                */
/**********************************************************************************/
/* 方法使能宏，注意一次只能使能一个方法，否则会出现函数重定义告警 */
#define DFS_METHOD_EN 1     /* 深度优先搜索方法使能 */
#define BFS_METHOD_EN 0     /* 广度优先搜索方法使能 */


/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/*
    方法一：深度优先搜索
        如果我们知道了左子树和右子树的最大深度 l 和 r，那么该二叉树的最大深度即为 max(l,r) + 1
        而左子树和右子树的最大深度又可以以同样的方式进行计算
        因此我们可以用「深度优先搜索」的方法来计算二叉树的最大深度
        具体而言，在计算当前二叉树的最大深度时，可以先递归计算出其左子树和右子树的最大深度
        然后在 O(1) 时间内计算出当前二叉树的最大深度。递归在访问到空节点时退出
*/
/* ============================================================================== */
/* ============================================================================== */
#if DFS_METHOD_EN
/**
 * @description: 二叉树的最大深度 - 深度优先搜索
 * =================================================================================
 * @param {struct TreeNode*} root   根节点
 * @return {int} depth              最大深度
 */
int maxDepth(struct TreeNode* root) {
    if (root == NULL) {                             /* 递归终止条件 */
        return 0;
    } else {                                        /* 递归计算最大深度 */
        int leftHeight = maxDepth(root->left);          /* 递归计算左子树的最大深度 */
        int rightHeight = maxDepth(root->right);        /* 递归计算右子树的最大深度 */
        return fmax(leftHeight, rightHeight) + 1;       /* 当前二叉树的最大深度 = max(左子树最大深度, 右子树最大深度) + 1 */
    }
}
#endif /* DFS_METHOD_EN */

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/*
    方法二：广度优先搜索
        我们也可以用「广度优先搜索」的方法来解决这道题目，但我们需要对其进行一些修改
        我们按照树的层次去迭代，先迭代出第一层，再迭代出第二层，以此类推
        当迭代完最后一层以后，我们就可以得到二叉树的最大深度
        广度优先搜索的性质保证了我们搜索到的第一个叶子节点的深度一定最大
        因此当我们遍历到最后一个叶子节点时，我们即得到了二叉树的最大深度
*/
/* ============================================================================== */
/* ============================================================================== */
#if BFS_METHOD_EN
/* 队列节点 */
struct QueueNode {
    struct TreeNode *node;      /* 节点指针 */
    struct QueueNode *next;     /* 下一个节点指针 */
};

/**
 * @description: 初始化队列 - 虚拟头节点
 * =================================================================================
 * @param {struct QueueNode} **queue    队列指针
 * @param {struct TreeNode} *node       节点指针
 * @return {void}
 */
void Queue_Init(struct QueueNode **queue, struct TreeNode *node) {
    *queue = (struct QueueNode *)malloc(sizeof(struct QueueNode));      /* 申请内存空间 */
    (*queue)->node = node;                                              /* 节点指针赋值 */
    (*queue)->next = NULL;                                              /* 下一个节点指针赋值 */
}

/**
 * @description: 二叉树的最大深度 - 广度优先搜索
 * =================================================================================
 * @param {struct TreeNode*} root   根节点
 * @return {int} depth              最大深度
 */
int maxDepth(struct TreeNode* root) {
    if (root == NULL) {                                         /* 如果根节点为 NULL 则返回 0 */
        return 0;
    }
    struct QueueNode *left, *right;                             /* 定义左右节点指针 */
    Queue_Init(&left, root);                                     /* 初始化左节点 */
    right = left;                                               /* 初始化右节点 */
    int ans = 0, sz = 1, tmp = 0;                               /* 定义最大深度、当前层节点个数、当前层节点个数的临时变量 */
    while (left != NULL) {                                      /* 当左节点不为空时 */
        tmp = 0;                                                    /* 重置当前层节点个数的临时变量 */
        while (sz > 0) {                                            /* 遍历当前层的节点 */
            if (left->node->left != NULL) {                             /* 如果左节点不为空 */
                Queue_Init(&right->next, left->node->left);                  /* 初始化左节点 */
                right = right->next;                                        /* 右节点指针指向下一个节点 */
                tmp++;                                                      /* 当前层节点个数 + 1 */
            }
            if (left->node->right != NULL) {                            /* 如果右节点不为空 */
                Queue_Init(&right->next, left->node->right);                 /* 初始化右节点 */
                right = right->next;                                        /* 右节点指针指向下一个节点 */
                tmp++;                                                      /* 当前层节点个数 + 1 */
            }
            left = left->next;                                          /* 左节点指针指向下一个节点 */
            sz--;                                                       /* 当前层节点个数 - 1 */
        }
        sz += tmp;                                                  /* 更新当前层节点个数 */
        ans++;                                                      /* 最大深度 + 1 */
    }
    free(left);                                                 /* Free memory (释放内存空间) */
    return ans;                                                 /* 返回最大深度 */
}
#endif /* BFS_METHOD_EN */

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 测试函数 1
 * =================================================================================
 * @return {void}
 */
void Test1(void) {
    /* Expect result (期望结果) */
    int expect = 3;

    /* 构建二叉树 */
    struct TreeNode *root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    /* Function call (函数调用) */
    int actual = maxDepth(root);

    /* Validate result (验证函数调用结果) */
    Validate_SingleValue('1', expect, actual);

    /* Free memory (释放内存空间) */
    free(root->right->right);
    free(root->right->left);
    free(root->right);
    free(root->left);
    free(root);
}

/**
 * @description: 测试函数 2
 * =================================================================================
 * @return {void}
 */
void Test2(void) {
    /* Expect result (期望结果) */
    int expect = 2;

    /* 构建二叉树 */
    struct TreeNode *root = newNode(1);
    root->right = newNode(2);

    /* Function call (函数调用) */
    int actual = maxDepth(root);

    /* Validate result (验证函数调用结果) */
    Validate_SingleValue('2', expect, actual);

    /* Free memory (释放内存空间) */
    free(root->right);
    free(root);
}

/**********************************************************************************/
/*                                                                                */
/*                                  MAIN FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: Main function, entry of program.
 * =================================================================================
 * @param {int} argc        程序入参个数
 * @param {char} *argv[]    程序入参字符串数组
 * @return {int}            程序运行状态
 */
int main(int argc, const char *argv[]) {
    Test1();
    Test2();
    return 0;
}