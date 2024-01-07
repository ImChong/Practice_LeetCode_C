/*
 * @FilePath     : \Practice_LeetCode_C\01_Common_Functions\cfg\methodCfg.h
 * @Author       : Chong Liu
 * @CreateDate   : 2024-01-08 00:52:30
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-08 00:56:57
 * =================================================================================
 * Copyright (c) 2024 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : solution method configuration file (解题方法配置文件)
 */
#ifndef __METHOD_CFG_H /* NOLINT(build/header_guard) */
#define __METHOD_CFG_H /* NOLINT(build/header_guard) */

/* common function configuration file (通用函数配置文件) */
#include "compileCfg.h"

#if COMMON_BINARY_TREE_EN == 1
#define BTREE_RECURSION_METHOD_EN 1 /* 递归解法使能  1: enable, 0: disable */
#define BTREE_ITERATION_METHOD_EN 0 /* 迭代解法使能  1: enable, 0: disable */
#endif /* COMMON_BINARY_TREE_EN == 1 */

#endif  /* __METHOD_CFG_H */