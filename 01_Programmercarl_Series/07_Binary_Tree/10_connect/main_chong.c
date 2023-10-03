/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\07_Binary_Tree\10_connect\main_chong.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-18 23:18:36
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-03 08:49:04
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 116. 填充每个节点的下一个右侧节点指针: https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/
 * 解法参考: https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/solutions/446938/tian-chong-mei-ge-jie-dian-de-xia-yi-ge-you-ce-2-4/
 */
#include <stdio.h>
#include <stdlib.h>

/**********************************************************************************/
/*                                                                                */
/*                                MACRO CONSTANTS                                 */
/*                                                                                */
/**********************************************************************************/
#define LEVEL_ORDER_METHOD_EN   1       /* 层次遍历方法使能 */
#define NEXT_POINTER_METHOD_EN  0       /* 使用已建立的 next 指针方法使能 */
#define MAX_QUEUE_SIZE          5000    /* 定义数组的最大大小 */

/**********************************************************************************/
/*                                                                                */
/*                                 GLOBAL VARIABLES                               */
/*                                                                                */
/**********************************************************************************/
/* 树节点 */
struct Node {
    int val;                /* 节点的值 */
    struct Node *left;      /* 左节点 */
    struct Node *right;     /* 右节点 */
    struct Node *next;      /* next 指针 */
};

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/*
    方法一：层次遍历
        题目本身希望我们将二叉树的每一层节点都连接起来形成一个链表。
        因此直观的做法我们可以对二叉树进行层次遍历，在层次遍历的过程中将我们将二叉树每一层的节点拿出来遍历并连接。

    层次遍历基于广度优先搜索
        它与广度优先搜索的不同之处在于，广度优先搜索每次只会取出一个节点来拓展，而层次遍历会每次将队列中的所有元素都拿出来拓展
        这样能保证每次从队列中拿出来遍历的元素都是属于同一层的
        因此我们可以在遍历的过程中修改每个节点的 next 指针，同时拓展下一层的新队列。
*/
/* ============================================================================== */
/* ============================================================================== */
#if LEVEL_ORDER_METHOD_EN

struct Node *connect(struct Node *root) {
    if (root == NULL) {
        return root;
    }

    struct Node *queue[MAX_QUEUE_SIZE];
    int left = 0, right = 0;
    queue[right++] = root;
    /* TODO */
	return NULL;
}

#endif /* LEVEL_ORDER_METHOD_EN */

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/*
    方法二：使用已建立的 next 指针
    TODO

*/
/* ============================================================================== */
/* ============================================================================== */
#if NEXT_POINTER_METHOD_EN

struct Node *connect(struct Node *root) {
    /* TODO */
	return NULL;
}

#endif /* NEXT_POINTER_METHOD_EN */

/**********************************************************************************/
/*                                                                                */
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 新建节点
 * =================================================================================
 * @param {int} val                 节点的值
 * @return {struct Node} *node      新建的节点
 */
struct Node *newNode(int val) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    node->next = NULL;
    return node;
}

/**
 * @description: 打印树节点 next 指针的值
 * =================================================================================
 * @param {struct Node} *root       树的根节点
 * @return {void}
 */
void printTree(struct Node *root) {
    if (!root) return;
    printf("%d -> ", root->val);
    if (root->next) {
        printf("%d\n", root->next->val);
    } else {
        printf("NULL\n");
    }
    printTree(root->left);
    printTree(root->right);
}

/**********************************************************************************/
/*                                                                                */
/*                                  MAIN FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
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
    struct Node *root = newNode(1);

    return 0;
}