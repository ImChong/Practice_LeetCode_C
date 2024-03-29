/*
 * @FilePath     : \Practice_LeetCode_C\F01_Common_Functions\src\common_array.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-22 09:31:20
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-27 14:30:51
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用数组源文件
 */
/* Common function configuration file (通用函数配置文件) */
#include "compile_cfg.h"    /* NOLINT */
#if COMMON_ARRAY_EN /* whether compile this file, the definition of this macro can be found in compileCfg.h */
/* Header file (本文件头文件) */
#include "F01_Common_Functions/inc/common_array.h"
/* Standard header file (标准头文件) */
#include <stdio.h>
#include <stdlib.h>
/* Common function header file (通用头文件) */
#include "F01_Common_Functions/inc/common_single_value.h"

/**********************************************************************************/
/*                                                                                */
/*                                 GLOBAL VARIABLES                               */
/*                                                                                */
/**********************************************************************************/
STATIC int g_2DArrRowSize = 0;

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 比较数组间的元素顺序
 * =================================================================================
 * @param {void} *a     数组元素a
 * @param {void} *b     数组元素b
 * @return {int}        比较结果，大于0表示a>b，小于0表示a<b，等于0表示a=b
 */
int Array_CmpElement(const void *a, const void *b) { return (*(int *)a - *(int *)b); /* NOLINT(readability/casting) */ }

/**
 * @description: 比较二维数组间的行顺序
 * =================================================================================
 * @param {void} *a     数组元素a
 * @param {void} *b     数组元素b
 * @return {int}        比较结果，大于0表示a>b，小于0表示a<b，等于0表示a=b
 */
STATIC_FUNC int CompareRows(const void *a, const void *b) {
    int *arrA = *(int **)a; /* NOLINT(readability/casting) */
    int *arrB = *(int **)b; /* NOLINT(readability/casting) */
    for (int i = 0; i < g_2DArrRowSize; i++) {
        if (arrA[i] != arrB[i]) {
            return (arrA[i] - arrB[i]);
        }
    }
    return 0;
}

/**
 * @description: 数组排序
 * =================================================================================
 * @param {int} *arr        数组
 * @param {int} arr_size     数组大小
 * @return {int}            排序结果
 */
int Array_Sort(int *arr, int arr_size) {
    if (arr == NULL || arr_size <= 0) {
        return COMMON_ERR;
    }
    qsort(arr, arr_size, sizeof(int), Array_CmpElement);
    return COMMON_OK;
}

/**
 * @description: 二维数组排序
 * =================================================================================
 * @param {int} **arr_2d           返回数组
 * @param {int} arr_size         返回数组大小
 * @param {int} *arr_col_sizes    返回数组列大小
 * @return {int}                排序结果
 */
int Array_Sort2D(int **arr_2d, int arr_size, int *arr_col_sizes) {
    if (arr_2d == NULL || arr_size <= 0 || arr_col_sizes == NULL) {
        return COMMON_ERR;
    }
    for (int i = 0; i < arr_size; i++) {
        if (arr_2d[i] == NULL || arr_col_sizes[i] <= 0) {
            return COMMON_ERR;
        }
        qsort(arr_2d[i], arr_col_sizes[i], sizeof(int), Array_CmpElement);
    }
    g_2DArrRowSize = arr_size;
    qsort(arr_2d, arr_size, sizeof(int *), CompareRows);
    return COMMON_OK;
}

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 打印数组
 * =================================================================================
 * @param {int} *arr        数组
 * @param {int} arr_size     数组大小
 * @return {int}            打印结果
 */
int Array_Print(int *arr, int arr_size) {
    if (printf("Arr (len: %d): [", arr_size) < 0) {
        return COMMON_ERR;
    }
    for (int i = 0; i < arr_size; i++) {
        if (printf("%d", arr[i]) < 0) {
            return COMMON_ERR;
        }
        if (i < arr_size - 1) {
            if (printf(",\t") < 0) {
                return COMMON_ERR;
            }
        }
    }
    if (printf("]\n") < 0) {
        return COMMON_ERR;
    }
    return COMMON_OK;
}

/**
 * @description: 打印二维数组
 * =================================================================================
 * @param {int} **2DArr             返回数组
 * @param {int} arr_size             返回数组大小
 * @param {int} *arr_col_sizes        返回数组列大小
 * @return {int}                    打印结果
 */
int Array_Print2D(int **arr_2d, int arr_size, int *arr_col_sizes) {
    if (printf("Ans: (row: %d, col: %d) [\n", arr_size, arr_col_sizes[0]) < 0) {
        return COMMON_ERR;
    }
    for (int i = 0; i < arr_size; i++) {
        if (printf("  [") < 0) {
            return COMMON_ERR;
        }
        for (int j = 0; j < arr_col_sizes[i]; j++) {
            if (printf("%d", arr_2d[i][j]) < 0) {
                return COMMON_ERR;
            }
            if (j < arr_col_sizes[i] - 1) {
                if (printf(",\t") < 0) {
                    return COMMON_ERR;
                }
            }
        }
        if (printf("]\n") < 0) {
            return COMMON_ERR;
        }
    }
    if (printf("]\n") < 0) {
        return COMMON_ERR;
    }
    return COMMON_OK;
}

/**
 * @description: 释放数组
 * =================================================================================
 * @param {int} **p_arr        返回数组
 * @return {int}                打印结果
 */
int Array_Free(int **p_arr) {
    if (*p_arr != NULL) {
        free(*p_arr);
        *p_arr = NULL;
    }
    return COMMON_OK;
}

/**
 * @description: 释放二维数组
 * =================================================================================
 * @param {int} ***p_arr_2d       返回数组
 * @param {int} arr_size         返回数组大小
 * @return {int}                打印结果
 */
int Array_Free2D(int ***p_arr_2d, int arr_size) {
    if (*p_arr_2d != NULL) {
        for (int i = 0; i < arr_size; i++) {
            if ((*p_arr_2d)[i] != NULL) {
                free((*p_arr_2d)[i]);
                (*p_arr_2d)[i] = NULL;
            }
        }
        free(*p_arr_2d);
        *p_arr_2d = NULL;
    }
    return COMMON_OK;
}

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 验证数组答案
 * =================================================================================
 * @param {char} testNum        测试编号
 * @param {int} *expectArr      预期结果
 * @param {int} expectLen       预期结果长度
 * @param {int} *actualArr      实际结果
 * @param {int} actualLen       实际结果长度
 * @param {int} needSort        是否排序
 * @return {int}                验证结果: 0-成功，-1-失败
 */
int Validate_Array(char testNum, int *expectArr, int expectLen, int *actualArr, int actualLen, int needSort) {
    if (needSort == COMMON_TRUE) {
        Array_Sort(expectArr, expectLen);
        Array_Sort(actualArr, actualLen);
    }

    int isSuccess = COMMON_TRUE;

    if (expectLen != actualLen) {
        isSuccess = COMMON_FALSE;
    } else {
        for (int i = 0; i < expectLen; i++) {
            if (expectArr[i] != actualArr[i]) {
                isSuccess = COMMON_FALSE;
                break;
            }
        }
    }

    printf("=========================\n");
    if (isSuccess) {
        printf(" - ✅ Test %c passed\n", testNum);
    } else {
        printf(" - ❌ Test %c failed\n", testNum);
    }
    printf("=========================\n");
    printf("- Expect: ");
    Array_Print(expectArr, expectLen);
    printf("- Actual: ");
    Array_Print(actualArr, actualLen);
    printf("\n");
    if (isSuccess) {
        return COMMON_OK;
    } else {
        return COMMON_ERR;
    }
}

/**
 * @description: 验证二维数组答案
 * =================================================================================
 * @param {char} testNum                测试编号
 * @param {int} **expect2DArr           预期结果
 * @param {int} expectRtnRowSize        预期结果大小
 * @param {int} *expectRtnColSize       预期结果列大小
 * @param {int} **actual2DArr           实际结果
 * @param {int} actualRtnRowSize        实际结果大小
 * @param {int} *actualRtnColSize       实际结果列大小
 * @param {int} needSort                是否排序
 * @return {int}                        验证结果: 0-成功，-1-失败
 */
int Validate_Array2D(char testNum, int **expect2DArr, int expectRtnRowSize, int *expectRtnColSize, int **actual2DArr,
                     int actualRtnRowSize, int *actualRtnColSize, int needSort) {
    if (needSort == COMMON_TRUE) {
        Array_Sort2D(expect2DArr, expectRtnRowSize, expectRtnColSize);
        Array_Sort2D(actual2DArr, actualRtnRowSize, actualRtnColSize);
    }

    int isSuccess = COMMON_TRUE;

    if (actualRtnRowSize != expectRtnRowSize) {
        isSuccess = COMMON_FALSE;
    } else {
        for (int i = 0; i < expectRtnRowSize; i++) {
            if (actualRtnColSize[i] != expectRtnColSize[i]) {
                isSuccess = COMMON_FALSE;
                break;
            }
            for (int j = 0; j < expectRtnColSize[i]; j++) {
                if (actual2DArr[i][j] != expect2DArr[i][j]) {
                    isSuccess = COMMON_FALSE;
                    break;
                }
            }
        }
    }

    printf("=========================\n");
    if (isSuccess) {
        printf(" - ✅ Test %c passed\n", testNum);
    } else {
        printf(" - ❌ Test %c failed\n", testNum);
    }
    printf("=========================\n");
    printf("- Expect: ");
    Array_Print2D(expect2DArr, expectRtnRowSize, expectRtnColSize);
    printf("- Actual: ");
    Array_Print2D(actual2DArr, actualRtnRowSize, actualRtnColSize);
    printf("\n");
    if (isSuccess) {
        return COMMON_OK;
    } else {
        return COMMON_ERR;
    }
}

#endif /* COMMON_ARRAY_EN */
