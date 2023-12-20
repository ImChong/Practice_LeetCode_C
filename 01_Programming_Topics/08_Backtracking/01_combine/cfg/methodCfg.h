/*
 * @FilePath     : \Practice_LeetCode_C\01_Programming_Topics\07_Binary_Tree\04_levelOrder\cfg\methodCfg.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-29 11:32:41
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-08 20:19:18
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 解题方法配置文件
 */
#ifndef __METHOD_CFG_H
#define __METHOD_CFG_H

/**********************************************************************************/
/*                                                                                */
/*                                MACRO CONSTANTS                                 */
/*                                                                                */
/**********************************************************************************/
#define BASELINE_METHOD_EN          1                           /* 基础方法使能，1：使能，0：关闭 */
#define CUT_BRANCH_METHOD_EN        !BASELINE_METHOD_EN         /* 剪枝方法使能，1：使能，0：关闭 */
#define CUT_BRANCH_GPT4_METHOD_EN   0                           /* GPT4生成剪枝方法使能，1：使能，0：关闭 */

#endif  /* __METHOD_CFG_H */