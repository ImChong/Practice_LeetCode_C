/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\07_Binary_Tree\10_connect\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-18 23:18:36
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-03 09:05:45
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
/**
 * @description:
 * =================================================================================
 * @param {struct Node} *root       树的根节点
 * @return {struct Node} *root      修改后树的根节点
 */
struct Node *connect(struct Node *root) {
    if (root == NULL) {                             /* 如果根节点为空，直接返回 */
        return root;
    }

    struct Node *queue[MAX_QUEUE_SIZE];             /* 定义队列 */
    int left = 0, right = 0;                        /* 定义队列的左右指针 */
    queue[right++] = root;                          /* 根节点入队 */

    while (left < right) {                          /* 队列不为空时，循环遍历 */
        int size = right - left;                        /* 记录当前层的节点个数 */
        for (int i = 0; i < size; i++) {                /* 遍历当前层的节点 */
            struct Node *node = queue[left++];              /* 队首元素出队 */

            if (i < size - 1) {                             /* 如果不是当前层的最后一个节点 */
                node->next = queue[left];                       /* 将队首元素的 next 指针指向队首元素的下一个元素 */
            }

            if (node->left != NULL) {                       /* 如果左节点不为空，左节点入队 */
                queue[right++] = node->left;
            }
            if (node->right != NULL) {                      /* 如果右节点不为空，右节点入队 */
                queue[right++] = node->right;
            }
        }
    }
	return root;                                    /* 返回根节点 */
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
void printTreeNext(struct Node *root) {
    if (!root) return;
    printf("%d -> ", root->val);
    if (root->next) {
        printf("%d\n", root->next->val);
    } else {
        printf("NULL\n");
    }
    printTreeNext(root->left);
    printTreeNext(root->right);
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
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    /*
     * 预期结果
     *        1 > NULL
     *     /     \
     *    2   >   3 > NULL
     *   / \     / \
     *  4 > 5 > 6 > 7 > NULL
     */
    root = connect(root);
    printTreeNext(root);

    free(root->left->left);
    free(root->left->right);
    free(root->right->left);
    free(root->right->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}