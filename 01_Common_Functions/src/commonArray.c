/*
 * @FilePath     : \Practice_LeetCode_C\01_Common_Functions\src\commonArray.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-22 09:31:20
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-31 20:30:38
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用数组源文件
 */

/* 编译配置文件 */
#include "compileCfg.h"
#if COMMON_ARRAY_EN         /* 在每一道题 cfg 文件夹下的 compileCfg.h 开启编译宏定义 */
/* standard header file (标准头文件) */
#include <stdio.h>
#include <stdlib.h>
/* 常用头文件 */
#include "commonTypeDef.h"
#include "commonSingleValue.h"
#include "commonArray.h"

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
 * @param {void} *a             数组元素a
 * @param {void} *b             数组元素b
 * @return {int}                比较结果，大于0表示a>b，小于0表示a<b，等于0表示a=b
 */
int compareElements(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);       /* NOLINT(readability/casting) */
}

/**
 * @description: 比较二维数组间的行顺序
 * =================================================================================
 * @param {void} *a             数组元素a
 * @param {void} *b             数组元素b
 * @return {int}                比较结果，大于0表示a>b，小于0表示a<b，等于0表示a=b
 */
STATIC_FUNC int compareRows(const void *a, const void *b) {
    int *arrA = *(int **)a;             /* NOLINT(readability/casting) */
    int *arrB = *(int **)b;             /* NOLINT(readability/casting) */
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
 * @param {int} *arr            数组
 * @param {int} arrSize         数组大小
 * @return {int}                排序结果
 */
int ArraySort(int *arr, int arrSize) {
    if (arr == NULL || arrSize <= 0) {
        return COMMON_ERR;
    }
    qsort(arr, arrSize, sizeof(int), compareElements);
    return COMMON_OK;
}

/**
 * @description: 二维数组排序
 * =================================================================================
 * @param {int} **arr           返回数组
 * @param {int} arrSize         返回数组大小
 * @param {int} *arrColSizes    返回数组列大小
 * @return {int}                排序结果
 */
int sort2DArray(int **arr, int arrSize, int *arrColSizes) {
    if (arr == NULL || arrSize <= 0 || arrColSizes == NULL) {
        return COMMON_ERR;
    }
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == NULL || arrColSizes[i] <= 0) {
            return COMMON_ERR;
        }
        qsort(arr[i], arrColSizes[i], sizeof(int), compareElements);
    }
    g_2DArrRowSize = arrSize;
    qsort(arr, arrSize, sizeof(int *), compareRows);
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
 * @param {int} *arr            数组
 * @param {int} arrSize         数组大小
 * @return {int}                打印结果
 */
int printArray(int *arr, int arrSize) {
    if (printf("Arr (len: %d): [", arrSize) < 0) {
        return COMMON_ERR;
    }
    for (int i = 0; i < arrSize; i++) {
        if (printf("%d", arr[i]) < 0) {
            return COMMON_ERR;
        }
        if (i < arrSize - 1) {
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
 * @param {int} arrSize             返回数组大小
 * @param {int} *arrColSizes        返回数组列大小
 * @return {int}                    打印结果
 */
int print2DArray(int **arr, int arrSize, int *arrColSizes) {
    if (printf("Ans: (row: %d, col: %d) [\n", arrSize, arrColSizes[0]) < 0) {
        return COMMON_ERR;
    }
    for (int i = 0; i < arrSize; i++) {
        if (printf("  [") < 0) {
            return COMMON_ERR;
        }
        for (int j = 0; j < arrColSizes[i]; j++) {
            if (printf("%d", arr[i][j]) < 0) {
                return COMMON_ERR;
            }
            if (j < arrColSizes[i] - 1) {
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
 * @param {int} **arrPtr            返回数组
 * @return {int}                    打印结果
 */
int freeArray(int **arrPtr) {
    if (*arrPtr != NULL) {
        free(*arrPtr);
        *arrPtr = NULL;
    }
    return COMMON_OK;
}

/**
 * @description: 释放二维数组
 * =================================================================================
 * @param {int} ***arrPtr           返回数组
 * @param {int} arrSize             返回数组大小
 * @return {int}                    打印结果
 */
int free2DArray(int ***arrPtr, int arrSize) {
    if (*arrPtr != NULL) {
        for (int i = 0; i < arrSize; i++) {
            if ((*arrPtr)[i] != NULL) {
                free((*arrPtr)[i]);
                (*arrPtr)[i] = NULL;
            }
        }
        free(*arrPtr);
        *arrPtr = NULL;
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
int validateArray(char testNum, int *expectArr, int expectLen, int *actualArr, int actualLen, int needSort) {
    if (needSort == COMMON_TRUE) {
        ArraySort(expectArr, expectLen);
        ArraySort(actualArr, actualLen);
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
    printf("- Expect: "); printArray(expectArr, expectLen);
    printf("- Actual: "); printArray(actualArr, actualLen);
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
int validate2DArray(char testNum,
                            int **expect2DArr, int expectRtnRowSize, int *expectRtnColSize,
                            int **actual2DArr, int actualRtnRowSize, int *actualRtnColSize,
                            int needSort) {
    if (needSort == COMMON_TRUE) {
        sort2DArray(expect2DArr, expectRtnRowSize, expectRtnColSize);
        sort2DArray(actual2DArr, actualRtnRowSize, actualRtnColSize);
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
    printf("- Expect: "); print2DArray(expect2DArr, expectRtnRowSize, expectRtnColSize);
    printf("- Actual: "); print2DArray(actual2DArr, actualRtnRowSize, actualRtnColSize);
    printf("\n");
    if (isSuccess) {
        return COMMON_OK;
    } else {
        return COMMON_ERR;
    }
}


#endif /* COMMON_ARRAY_EN */
