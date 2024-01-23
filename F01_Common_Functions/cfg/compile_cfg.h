/*
 * @FilePath     : \Practice_LeetCode_C\F01_Common_Functions\cfg\compileCfg.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-11-23 01:23:40
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-15 10:53:36
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : Common function configuration file (通用函数配置文件)
 */
#ifndef F01_COMMON_FUNCTIONS_CFG_COMPILE_CFG_H_
#define F01_COMMON_FUNCTIONS_CFG_COMPILE_CFG_H_

/**********************************************************************************/
/*                                                                                */
/*                                MACRO CONSTANTS                                 */
/*                                                                                */
/**********************************************************************************/
/* Common module compilation enable: 1: enable, 0: disable */
#define COMMON_ARRAY_EN 1             /* Common array compilation enable */
#define COMMON_BINARY_TREE_EN 1       /* Common binary tree compilation enable */
#define COMMON_CMD_EN 1               /* Common command compilation enable */
#define COMMON_HASH_TABLE_EN 1        /* Common hash table compilation enable */
#define COMMON_LINKED_LIST_EN 1       /* Common linked list compilation enable */
#define COMMON_LINKED_LIST_DUMMY_EN 1 /* Common linked list with dummy head compilation enable */
#define COMMON_QUEUE_EN 1             /* Common queue compilation enable */
#define COMMON_RING_BUFFER_EN 1       /* Common ring buffer compilation enable */
#define COMMON_SINGLE_VALUE_EN 1      /* Common single value compilation enable */
#define COMMON_STACK_EN 1             /* Common stack compilation enable */
#define COMMON_STRING_EN 1            /* Common string compilation enable */

/* solution method configuration for common binary tree module (通用二叉树模块解题方法配置) */
#if COMMON_BINARY_TREE_EN
    /* Recursion / iteration method for binary tree order traversal compilation enable */
    #define BTREE_ORDER_TRAVERSAL_RECURSION_METHOD_EN 1
    #define BTREE_ORDER_TRAVERSAL_ITERATION_METHOD_EN 0
    /* Array / structure method for binary tree level order traversal compilation enable */
    #define BTREE_LEVEL_ORDER_ARRAY_METHOD_EN 1
    #define BTREE_LEVEL_ORDER_STRUCT_METHOD_EN 0
#endif /* COMMON_BINARY_TREE_EN */

#endif /* F01_COMMON_FUNCTIONS_CFG_COMPILE_CFG_H_ */
