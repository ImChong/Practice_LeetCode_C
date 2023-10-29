/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\02_intersection\inc\intersection_double_pointer.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-29 11:37:46
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-30 00:27:24
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  :
 */
#ifndef __INTERSECTION_DOUBLE_POINTER_H
#define __INTERSECTION_DOUBLE_POINTER_H

int cmp(const void *a, const void *b);
int *intersection(int *numsA, int numsASize, int *numsB, int numsBSize, int *returnSize);

#endif  /* __INTERSECTION_DOUBLE_POINTER_H */