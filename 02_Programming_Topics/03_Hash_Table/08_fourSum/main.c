/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\08_fourSum\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-23 22:54:19
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-24 19:28:33
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 18. 四数之和：https://leetcode.cn/problems/4sum/
 * https://programmercarl.com/0018.%E5%9B%9B%E6%95%B0%E4%B9%8B%E5%92%8C.html
 * https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0018.%E5%9B%9B%E6%95%B0%E4%B9%8B%E5%92%8C.md
 *
 * 给一个由 n 个整数组成的数组 nums ，和一个目标值 target 。
 * 请找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
 *      0 <= a, b, c, d < n
 *      a、b、c 和 d 互不相同
 *      nums[a] + nums[b] + nums[c] + nums[d] == target
 *
 * 可以按 任意顺序 返回答案
 */
/* standard header file (标准头文件) */
#include <stdio.h>
/* 通用头文件 */
#include "commonTypeDef.h"
#include "commonArray.h"
/* 解题方法配置文件 */
#include "methodCfg.h"
/* 当前源文件头文件 */
#include "fourSum.h"

/**********************************************************************************/
/*                                                                                */
/*                               STRUCT DEFINITION                                */
/*                                                                                */
/**********************************************************************************/
/* 测试数据结构定义 */
struct InputStruct {
    int *arr;                       /* 输入数组 */
    int arrSize;                    /* 输入数组大小 */
    int target;                     /* 输入目标值 */
};

/* 输出数据结构定义 */
struct outputStruct {
    int rtnSize;                    /* 输出返回数组大小 */
    int *rtnColSize;                /* 输出返回数组列大小 */
    int **arr;                      /* 输出返回数组 */
};

/* 测试数据定义 */
struct TestStruct {
    char testNum;                   /* 测试编号 */
    struct InputStruct input;       /* 输入数据 */
    struct outputStruct output;     /* 期望输出 */
};

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 运行测试
 * =================================================================================
 * @param {struct TestStruct} *test
 * @return {void}
 */
void runTest(struct TestStruct *test) {
    /* 实际结果 */
    int *nums = test->input.arr;
    int numsSize = test->input.arrSize;
    int target = test->input.target;
    int actualRtnRowSize = 0;
    int *actualRtnColSize = NULL;
    int **actual2DArr = fourSum(nums, numsSize, target, &actualRtnRowSize, &actualRtnColSize);

    /* 预期结果 */
    int expectRtnRowSize = test->output.rtnSize;
    int *expectRtnColSize = test->output.rtnColSize;
    int **expect2DArr = test->output.arr;

    /* 比较结果 */
    validate2DArray(test->testNum,
                        expect2DArr, expectRtnRowSize, expectRtnColSize,
                        actual2DArr, actualRtnRowSize, actualRtnColSize,
                        SORT_TRUE);

    /* 释放内存 */
    freeArray(actualRtnColSize);
    free2DArray(actual2DArr, actualRtnRowSize);
}

/**
 * @description: 测试 1
 * 输入：nums = [1,0,-1,0,-2,2], target = 0
 * 输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 * =================================================================================
 * @return {void}
 */
void test_1(void) {
    struct TestStruct test;
    test.testNum = '1';
    int inputArr[] = {1, 0, -1, 0, -2, 2};
    test.input.arr = inputArr;
    test.input.arrSize = ARR_SIZE(inputArr);
    test.input.target = 0;
    test.output.rtnSize = 3;
    test.output.rtnColSize = (int[]){4, 4, 4};
    test.output.arr = (int*[]){(int[]){-2, -1, 1, 2}, (int[]){-2, 0, 0, 2}, (int[]){-1, 0, 0, 1}};
    runTest(&test);
}

/**
 * @description: 测试 2
 * 输入：nums = [2,2,2,2,2], target = 8
 * 输出：[[2,2,2,2]]
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    struct TestStruct test;
    test.testNum = '2';
    int inputArr[] = {2, 2, 2, 2, 2};
    test.input.arr = inputArr;
    test.input.arrSize = ARR_SIZE(inputArr);
    test.input.target = 8;
    test.output.rtnSize = 1;
    test.output.rtnColSize = (int[]){4};
    test.output.arr = (int*[]){(int[]){2, 2, 2, 2}};
    runTest(&test);
}

/**
 * @description: 测试 3
 * 输入：nums = [1,2,3,4,5,6,7,8,9,10], target = 20
 * 输出：[[1,2,7,10],[1,3,6,10],[1,4,5,10],[1,4,6,9],[2,3,5,10],[2,3,6,9],[2,4,5,9],[3,4,5,8],[3,4,6,7]]
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    struct TestStruct test;
    test.testNum = '3';
    int inputArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    test.input.arr = inputArr;
    test.input.arrSize = ARR_SIZE(inputArr);
    test.input.target = 20;
    test.output.rtnSize = 16;
    test.output.rtnColSize = (int[]){4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};
    test.output.arr = (int*[]){(int[]){1, 2, 7, 10},
                                (int[]){2, 3, 6, 9},
                                (int[]){1, 2, 8, 9},
                                (int[]){1, 3, 6, 10},
                                (int[]){1, 3, 7, 9},
                                (int[]){1, 4, 5, 10},
                                (int[]){1, 4, 6, 9},
                                (int[]){1, 4, 7, 8},
                                (int[]){1, 5, 6, 8},
                                (int[]){2, 3, 5, 10},
                                (int[]){2, 3, 7, 8},
                                (int[]){2, 4, 5, 9},
                                (int[]){2, 4, 6, 8},
                                (int[]){3, 4, 5, 8},
                                (int[]){2, 5, 6, 7},
                                (int[]){3, 4, 6, 7}};
    runTest(&test);
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
int main(int argc, const char* argv[]) {
#if DOUBLE_POINTER_METHOD_EN
    printf("DOUBLE_POINTER_METHOD_EN\r\n");
#elif HASH_TABLE_METHOD_EN
    printf("HASH_TABLE_METHOD_EN\r\n");
#endif
    test_1();
    test_2();
    test_3();
    return 0;
}