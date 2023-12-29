/*
 * @FilePath     : \Practice_LeetCode_C\01_Programming_Topics\01_Array\02_removeElement\src\removeElement.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-12-28 11:28:50
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-29 10:17:33
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : solution source file - removeElement
 */
/* 本文件头文件 */
#include "removeElement.h"

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 移除元素
 * =================================================================================
 * @param {int} *nums       数组
 * @param {int} numsSize    数组大小
 * @param {int} val         目标值
 * @return {int} slow       慢指针
 */
int removeElement(int *nums, int numsSize, int val) {
    int quick, slow;                                        /* 初始化快慢指针 */
    for (quick = 0, slow = 0; quick < numsSize; quick++) {  /* 快指针遍历数组 */
        if (nums[quick] != val) {                               /* 当快指针所指向的值不等于val时*/
            nums[slow] = nums[quick];                           /* 慢指针的值等于快指针的值 */
            slow++;                                             /* 慢指针位置 + 1 */
        }
    }
    return slow;                                            /* 返回慢指针  */
}
