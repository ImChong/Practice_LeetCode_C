/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_hashtable\07_threeSum\src\threeSum_doublePointer.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-11-13 23:44:54
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-20 23:37:49
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 三数之和源文件 - 双指针法
 */
/* solution method configuration file (解题方法配置文件) */
#include "methodCfg.h"
#if DOUBLE_POINTER_METHOD_EN
/* Standard header file (标准头文件) */
#include <stdlib.h>
/* Common function header file (通用头文件) */
#include "F01_Common_Functions/inc/common_array.h"
/* solution header file (题解头文件) */
#include "threeSum.h"

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description: 三数之和
 * =================================================================================
 * @param {int} *arr                    数组
 * @param {int} arr_size                 数组大小
 * @param {int} *returnSize             返回数组大小
 * @param {int} **returnColumnSizes     返回数组列大小
 * @return {int} **ans                  返回数组
 */
int **threeSum(int *arr, int arr_size, int *returnSize, int **returnColumnSizes) {
    *returnSize = 0;
    if (arr_size < 3) {
        return NULL;
    }
    qsort(arr, arr_size, sizeof(int), Array_CmpElement);
    int **ans = (int **)malloc(sizeof(int *) * arr_size * arr_size);
    *returnColumnSizes = (int *)malloc(sizeof(int) * arr_size * arr_size);
    int i, j, k, sum;

    int indexLeft = 0;
    int indexMiddle = 0;
    int indexRight = 0;

    for (indexLeft = 0; indexLeft < arr_size - 2; indexLeft++) {
        if (arr[indexLeft] > 0) {
            return ans;
        }

        if (indexLeft > 0 && arr[indexLeft] == arr[indexLeft - 1]) {
            continue;
        }
        indexMiddle = indexLeft + 1;
        indexRight = arr_size - 1;

        while (indexMiddle < indexRight) {
            sum = arr[indexLeft] + arr[indexMiddle] + arr[indexRight];
            if (sum == 0) {
                ans[*returnSize] = (int*)malloc(sizeof(int) * 3);
                (*returnColumnSizes)[*returnSize] = 3;
                ans[*returnSize][0] = arr[indexLeft];
                ans[*returnSize][1] = arr[indexMiddle];
                ans[*returnSize][2] = arr[indexRight];
                *returnSize += 1;
                while (indexMiddle < indexRight && arr[indexMiddle] == arr[++indexMiddle]);
                while (indexMiddle < indexRight && arr[indexRight] == arr[--indexRight]);
            } else if (sum > 0) {
                indexRight--;
            } else {
                indexMiddle++;
            }
        }
    }
    return ans;
}


#endif  /* DOUBLE_POINTER_METHOD_EN */