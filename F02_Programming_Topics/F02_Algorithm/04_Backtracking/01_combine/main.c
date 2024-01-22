/*
 * @FilePath     : \Practice_LeetCode_C\02_Programming_Topics\08_Backtracking\01_combine\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-12-26 13:19:53
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-31 20:37:31
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 77. 组合: https://leetcode.cn/problems/combinations/
 * 解法参考:
 *      https://programmercarl.com/0077.%E7%BB%84%E5%90%88.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
 *      https://leetcode.cn/problems/combinations/solutions/857507/dai-ma-sui-xiang-lu-dai-ni-xue-tou-hui-s-0uql/
 */
 /* Standard header file (标准头文件) */
#include <stdio.h>
#include <stdlib.h>
/* Common function header file (通用头文件) */
#include "commonTypeDef.h"
#include "commonArray.h"
/* solution method configuration file (解题方法配置文件) */
#include "methodCfg.h"
/* solution header file (题解头文件) */
#include "combine.h"

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: Test 1
 * =================================================================================
 * @return {void}
 */
void Test1(void) {
    /* Function call (函数调用) */
    int n = 4;
    int k = 2;
    int actualRtnRowSize;
    int *actualRtnColSize;
    int **actual2DArr = combine(n, k, &actualRtnRowSize, &actualRtnColSize);

    /* Expect result (期望结果) */
    int expectRtnRowSize = 6;
    int expectRtnColSize[] = {2, 2, 2, 2, 2, 2};
    int *expect2DArr[] = {
        (int[]){1, 2},
        (int[]){1, 3},
        (int[]){1, 4},
        (int[]){2, 3},
        (int[]){2, 4},
        (int[]){3, 4},
    };

    /* Validate result (验证函数调用结果) */
    Validate_Array2D('1',
                    expect2DArr, expectRtnRowSize, expectRtnColSize,
                    actual2DArr, actualRtnRowSize, actualRtnColSize,
                    SORT_FALSE
    );

    /* Free memory (释放内存) */
    for (int i = 0; i < actualRtnRowSize; ++i) {
        free(actual2DArr[i]);
    }
    free(actual2DArr);
    free(actualRtnColSize);
}

/**
 * @description: Test 2
 * =================================================================================
 * @return {void}
 */
void Test2(void) {
    /* Function call (函数调用) */
    int n = 1;
    int k = 1;
    int actualRtnRowSize;
    int *actualRtnColSize;
    int **actual2DArr = combine(n, k, &actualRtnRowSize, &actualRtnColSize);

    /* Expect result (期望结果) */
    int expectRtnRowSize = 1;
    int expectRtnColSize[] = {1};
    int *expect2DArr[] = {
        (int[]){1},
    };

    /* Validate result (验证函数调用结果) */
    Validate_Array2D('2',
                    expect2DArr, expectRtnRowSize, expectRtnColSize,
                    actual2DArr, actualRtnRowSize, actualRtnColSize,
                    SORT_FALSE
    );

    /* Free memory (释放内存) */
    for (int i = 0; i < actualRtnRowSize; ++i) {
        free(actual2DArr[i]);
    }
    free(actual2DArr);
    free(actualRtnColSize);
}

/**
 * @description: 测试 3
 * =================================================================================
 * @return {void}
 */
void Test3(void) {
    /* Function call (函数调用) */
    int n = 5;
    int k = 3;
    int actualRtnRowSize;
    int *actualRtnColSize;
    int **actual2DArr = combine(n, k, &actualRtnRowSize, &actualRtnColSize);

    /* Expect result (期望结果) */
    int expectRtnRowSize = 10;
    int expectRtnColSize[] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
    int *expect2DArr[] = {
        (int[]){1, 2, 3},
        (int[]){1, 2, 4},
        (int[]){1, 2, 5},
        (int[]){1, 3, 4},
        (int[]){1, 3, 5},
        (int[]){1, 4, 5},
        (int[]){2, 3, 4},
        (int[]){2, 3, 5},
        (int[]){2, 4, 5},
        (int[]){3, 4, 5},
    };

    /* Validate result (验证函数调用结果) */
    Validate_Array2D('3',
                    expect2DArr, expectRtnRowSize, expectRtnColSize,
                    actual2DArr, actualRtnRowSize, actualRtnColSize,
                    SORT_FALSE
    );

    /* Free memory (释放内存) */
    for (int i = 0; i < actualRtnRowSize; ++i) {
        free(actual2DArr[i]);
    }
    free(actual2DArr);
    free(actualRtnColSize);
}

/**********************************************************************************/
/*                                                                                */
/*                                  MAIN FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 主函数
 * =================================================================================
 * @param {int} argc        程序入参个数
 * @param {char} *argv[]    程序入参字符串数组
 * @return {int}            程序运行状态
 */
int main(int argc, const char *argv[]) {
#if BASELINE_METHOD_EN
    printf("BASELINE_METHOD_EN\r\n");
#elif CUT_BRANCH_METHOD_EN
    printf("CUT_BRANCH_METHOD_EN\r\n");
#elif CUT_BRANCH_GPT4_METHOD_EN
    printf("CUT_BRANCH_GPT4_METHOD_EN\r\n");
#endif
    Test1();
    Test2();
    Test3();
    return 0;
}
