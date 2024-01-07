/*
 * @FilePath     : \Practice_LeetCode_C\01_Common_Functions\cfg\methodCfg.h
 * @Author       : Chong Liu
 * @CreateDate   : 2024-01-08 00:52:30
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-08 02:29:42
 * =================================================================================
 * Copyright (c) 2024 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : solution method configuration file (解题方法配置文件)
 *    This file is intended to left empty.
 *    The solution method configuration is set in the CMakelists.txt file instead.
 */
#ifndef __METHOD_CFG_H /* NOLINT(build/header_guard) */
#define __METHOD_CFG_H /* NOLINT(build/header_guard) */

/* common function configuration file (通用函数配置文件) */
#include "compileCfg.h"

/* solution method configuration for common binary tree module (通用二叉树模块解题方法配置) */
#if COMMON_BINARY_TREE_EN
#define BTREE_ORDER_TRAVERSAL_RECURSION_METHOD_EN 1 /* 二叉树递归遍历方法编译使能  1: enable, 0: disable */
#define BTREE_ORDER_TRAVERSAL_ITERATION_METHOD_EN 0 /* 二叉树迭代遍历方法编译使能  1: enable, 0: disable */
#define BTREE_LEVEL_ORDER_ARRAY_METHOD_EN 1         /* 二叉树层序遍历方法编译使能  1: enable, 0: disable */
#define BTREE_LEVEL_ORDER_STRUCT_METHOD_EN 0        /* 二叉树层序遍历方法编译使能  1: enable, 0: disable */
#endif /* COMMON_BINARY_TREE_EN */

#endif  /* __METHOD_CFG_H */ /* NOLINT(build/header_guard) */
