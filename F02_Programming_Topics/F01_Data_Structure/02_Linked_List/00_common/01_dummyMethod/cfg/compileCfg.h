/*
 * @FilePath     : \Practice_LeetCode_C\F02_Programming_Topics\F01_Data_Structure\02_Linked_List\00_common\01_dummyMethod\cfg\compileCfg.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-11-23 01:23:40
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-22 23:55:33
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : Common function configuration file (通用函数配置文件)
 */
#ifndef __COMPILE_CFG_H
#define __COMPILE_CFG_H

/**********************************************************************************/
/*                                                                                */
/*                                MACRO CONSTANTS                                 */
/*                                                                                */
/**********************************************************************************/
#define COMMON_ARRAY_EN                 1           /* 通用数组编译使能  1: enable, 0: disable */
#define COMMON_BINARY_TREE_EN           0           /* 通用二叉树编译使能  1: enable, 0: disable */
#define COMMON_CMD_EN                   0           /* 通用命令行编译使能  1: enable, 0: disable */
#define COMMON_HASH_TABLE_EN            0           /* 通用哈希表编译使能  1: enable, 0: disable */
#define COMMON_LINKED_LIST_EN           0           /* 通用链表编译使能  1: enable, 0: disable */
#define COMMON_LINKED_LIST_DUMMY_EN     1           /* 通用虚拟头节点链表编译使能  1: enable, 0: disable */
#define COMMON_QUEUE_EN                 0           /* 通用队列编译使能  1: enable, 0: disable */
#define COMMON_RING_BUFFER_EN           0           /* 通用环形缓冲区编译使能  1: enable, 0: disable */
#define COMMON_SINGLE_VALUE_EN          0           /* 通用单值函数编译使能  1: enable, 0: disable */
#define COMMON_STACK_EN                 0           /* 通用栈编译使能  1: enable, 0: disable */
#define COMMON_STRING_EN                0           /* 通用字符串编译使能  1: enable, 0: disable */

/* solution method configuration for common binary tree module (通用二叉树模块解题方法配置) */
#if COMMON_BINARY_TREE_EN
    #define BTREE_ORDER_TRAVERSAL_RECURSION_METHOD_EN 1 /* 二叉树递归遍历方法编译使能  1: enable, 0: disable */
    #define BTREE_ORDER_TRAVERSAL_ITERATION_METHOD_EN 0 /* 二叉树迭代遍历方法编译使能  1: enable, 0: disable */
    #define BTREE_LEVEL_ORDER_ARRAY_METHOD_EN 1         /* 二叉树层序遍历方法编译使能  1: enable, 0: disable */
    #define BTREE_LEVEL_ORDER_STRUCT_METHOD_EN 0        /* 二叉树层序遍历方法编译使能  1: enable, 0: disable */
#endif /* COMMON_BINARY_TREE_EN */

#endif  /* __COMPILE_CFG_H */