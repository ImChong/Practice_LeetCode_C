/*
 * @FilePath     : \Practice_LeetCode_C\01_Programming_Topics\07_Binary_Tree\04_levelOrder\src\levelOrder_struct.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-11-26 18:26:03
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-06 00:00:03
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 层序遍历二叉树源文件 - 结构体实现
 *
 * 层序遍历 - 借助链表结构体队列数据结构，记录下 Tree 的下一层的所有结点。这样一层一层的遍历。直到结束
 * 
 * 层序遍历 + 结构体链表队列
 * 关键点： 1：使用队列的数据结构存储对应的二叉树的结点Queue
 *          2：使用变量front和rear维护队列，队列是具有先进先出的特点
 *          3：使用Queue[front++] = root;来入队
 *          4: 使用nodeIt = Queue[rear++];来出队
 *          5：出队后，用 nodeIt 对应的子节点来操作，是否需要入队。
 *
 * 广度优先搜索
 * 关键点： 1：采用队列结构存储每一层的结点
 *          2：因为队列的结构特性，操作是先进先出
 *             时间复杂度：O(n) 空间复杂度: O(n)
 */
/* 解题方法配置文件 */
#include "methodCfg.h"
#if STRUCT_METHOD_EN
/* 标准头文件 */
#include <stdio.h>
/* 本文件头文件 */
#include "levelOrder.h"

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 二叉树的层序遍历
 * =================================================================================
 * @param {struct TreeNode} *root       二叉树的根节点
 * @param {int} *returnSize             二叉树的层数
 * @param {int} **returnColumnSizes     二叉树对应层级的节点数
 * @return {int} **resultArray          结果二维数组
 */
int **levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes) {


}


#endif  /* STRUCT_METHOD_EN */