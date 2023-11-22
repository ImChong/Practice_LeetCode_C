/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\07_threeSum\cfg\methodCfg.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-31 00:22:36
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-23 01:20:54
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
#define HASH_TABLE_METHOD_EN        1                       /* 哈希表法求解  1: enable, 0: disable */
#define COMMON_HASH_TABLE_EN        HASH_TABLE_METHOD_EN    /* 通用哈希表法求解  1: enable, 0: disable */
#define DOUBLE_POINTER_METHOD_EN    !HASH_TABLE_METHOD_EN   /* 双指针法求解  1: enable, 0: disable */

#endif  /* __METHOD_CFG_H */