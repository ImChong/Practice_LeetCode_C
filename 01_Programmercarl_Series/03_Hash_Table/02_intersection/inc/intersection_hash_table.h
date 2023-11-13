/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\02_intersection\inc\intersection_hash_table.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-29 11:37:56
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-13 23:37:15
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 两个数组的交集 - 哈希表解法头文件
 */
#ifndef __INTERSECTION_HASH_TABLE_H
#define __INTERSECTION_HASH_TABLE_H

/**********************************************************************************/
/*                                                                                */
/*                                MACRO CONSTANTS                                 */
/*                                                                                */
/**********************************************************************************/
#define HASH_SIZE 1000

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
int *intersection(int *numsA, int numsASize, int *numsB, int numsBSize, int *returnSize);       /* 两个数组的交集 */

#endif  /* __INTERSECTION_HASH_TABLE_H */