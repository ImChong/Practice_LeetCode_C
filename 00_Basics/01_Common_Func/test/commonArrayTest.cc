/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\test\commonArrayTest.cc
 * @Author       : Chong Liu
 * @CreateDate   : 2023-12-01 02:17:51
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-03 11:14:50
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用数组单元测试
 */
/* gtest 头文件 */
#include "gtest/gtest.h"
/* 测试目标头文件 */
extern "C" {
    #include "commonArray.h"
}

/**********************************************************************************/
/*                                                                                */
/*                                   TEST SUITE                                   */
/*                                                                                */
/**********************************************************************************/
class TestCommonArray : public ::testing::Test {
 public:
    static void SetUpTestCase() {
        // Code here will be called once before all tests
    }
    void SetUp() override {
        // Code here will be called before each test
    }
    void TearDown() override {
        // Code here will be called after each test
    }
    static void TearDownTestCase() {
        // Code here will be called once after all tests
    }
};

/**********************************************************************************/
/*                                                                                */
/*                                   TEST CASES                                   */
/*                                                                                */
/**********************************************************************************/

/**********************************************************************************/
/*                                                                                */
/*                                MACRO FUNCTIONS                                 */
/*                                                                                */
/**********************************************************************************/
/* ============================================================================== */
/* ARR_SIZE */
/* ============================================================================== */
TEST_F(TestCommonArray, TestArrSize) {
    /* 准备数据 */
    int arr[5] = {1, 2, 3, 4, 5};

    /* 运行结果 */
    int arrSize = ARR_SIZE(arr);

    /* 比较结果 */
    EXPECT_EQ(arrSize, 5);
}

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
/* ============================================================================== */
/* printArray */
/* ============================================================================== */
TEST_F(TestCommonArray, TestPrintArray) {
    /* 准备数据 */
    int arr[5] = {1, 2, 3, 4, 5};

    /* 运行结果 */
    printf("\n");
    printArray(arr, 5);
    printf("\n");
}

/* ============================================================================== */
/* print2DArray */
/* ============================================================================== */
TEST_F(TestCommonArray, TestPrint2DArray) {
    /* 准备数据 */
    int **arrPtr = (int **)malloc(sizeof(int *) * 2);       /* NOLINT(readability/casting) */
    for (int i = 0; i < 2; i++) {
        arrPtr[i] = (int *)malloc(sizeof(int) * 3);         /* NOLINT(readability/casting) */
    }
    arrPtr[0][0] = 1;
    arrPtr[0][1] = 2;
    arrPtr[0][2] = 3;
    arrPtr[1][0] = 4;
    arrPtr[1][1] = 5;
    arrPtr[1][2] = 6;
    int arrColSize[2] = {3, 3};

    /* 运行结果 */
    printf("\n");
    print2DArray(arrPtr, 2, arrColSize);
    printf("\n");
}

/* ============================================================================== */
/* freeArray */
/* ============================================================================== */
TEST_F(TestCommonArray, TestFreeArray) {
    /* 准备数据 */
    int *arr = (int *)malloc(sizeof(int) * 5);      /* NOLINT(readability/casting) */

    /* 运行结果 */
    freeArray(&arr);

    /* 比较结果 */
    EXPECT_EQ(arr, nullptr);
}

/* ============================================================================== */
/* free2DArray */
/* ============================================================================== */
TEST_F(TestCommonArray, TestFree2DArray) {
    /* 准备数据 */
    int **arrPtr = (int **)malloc(sizeof(int *) * 2);       /* NOLINT(readability/casting) */
    for (int i = 0; i < 2; i++) {
        arrPtr[i] = (int *)malloc(sizeof(int) * 3);         /* NOLINT(readability/casting) */
    }

    /* 运行结果 */
    free2DArray(&arrPtr, 2);

    /* 比较结果 */
    EXPECT_EQ(arrPtr, nullptr);
}

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/* ============================================================================== */
/* compareElements */
/* ============================================================================== */
TEST_F(TestCommonArray, TestCompareElements) {
    /* 准备数据 */
    int a = 5;
    int b = 3;
    /* 运行结果 & 比较结果 */
    EXPECT_EQ(compareElements(&a, &b), 2);

    /* 准备数据 */
    a = 3;
    b = 5;
    /* 运行结果 & 比较结果 */
    EXPECT_EQ(compareElements(&a, &b), -2);

    /* 准备数据 */
    a = 5;
    b = 5;
    /* 运行结果 & 比较结果 */
    EXPECT_EQ(compareElements(&a, &b), 0);
}

/* ============================================================================== */
/* sortArray */
/* ============================================================================== */
TEST_F(TestCommonArray, TestSortArray) {
    /* 准备数据 */
    int arr[5] = {5, 4, 3, 2, 1};

    /* 运行结果 */
    sortArray(arr, 5);

    /* 比较结果 */
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 3);
    EXPECT_EQ(arr[3], 4);
    EXPECT_EQ(arr[4], 5);
}

/* ============================================================================== */
/* sort2DArray */
/* ============================================================================== */
TEST_F(TestCommonArray, TestSort2DArray) {
    /* 准备数据 */
    int **arrPtr = (int **)malloc(sizeof(int *) * 2);       /* NOLINT(readability/casting) */
    for (int i = 0; i < 2; i++) {
        arrPtr[i] = (int *)malloc(sizeof(int) * 3);         /* NOLINT(readability/casting) */
    }
    arrPtr[0][0] = 5;
    arrPtr[0][1] = 4;
    arrPtr[0][2] = 3;
    arrPtr[1][0] = 2;
    arrPtr[1][1] = 1;
    arrPtr[1][2] = 0;
    int arrColSize[2] = {3, 3};

    /* 运行结果 */
    sort2DArray(arrPtr, 2, arrColSize);

    /* 比较结果 */
    EXPECT_EQ(arrPtr[0][0], 0);
    EXPECT_EQ(arrPtr[0][1], 1);
    EXPECT_EQ(arrPtr[0][2], 2);
    EXPECT_EQ(arrPtr[1][0], 3);
    EXPECT_EQ(arrPtr[1][1], 4);
    EXPECT_EQ(arrPtr[1][2], 5);
}

/* ============================================================================== */
/* validateArray */
/* ============================================================================== */
TEST_F(TestCommonArray, TestValidateArray) {
    /* 准备数据 */
    int expectArr[5] = {1, 2, 3, 4, 5};
    int actualArr[5] = {5, 4, 3, 2, 1};

    /* 运行结果 */
    sortArray(actualArr, 5);
    printf("\n");
    validateArray('1', expectArr, 5, actualArr, 5, 1);

    /* 比较结果 */
    EXPECT_EQ(actualArr[0], 1);
    EXPECT_EQ(actualArr[1], 2);
    EXPECT_EQ(actualArr[2], 3);
    EXPECT_EQ(actualArr[3], 4);
    EXPECT_EQ(actualArr[4], 5);
}

/* ============================================================================== */
/* validate2DArray */
/* ============================================================================== */
TEST_F(TestCommonArray, TestValidate2DArray) {
    /* 准备数据 */
    int **expect2DArr = (int **)malloc(sizeof(int *) * 2);       /* NOLINT(readability/casting) */
    for (int i = 0; i < 2; i++) {
        expect2DArr[i] = (int *)malloc(sizeof(int) * 3);         /* NOLINT(readability/casting) */
    }
    expect2DArr[0][0] = 1;
    expect2DArr[0][1] = 2;
    expect2DArr[0][2] = 3;
    expect2DArr[1][0] = 4;
    expect2DArr[1][1] = 5;
    expect2DArr[1][2] = 6;
    int expectRtnColSize[2] = {3, 3};

    int **actual2DArr = (int **)malloc(sizeof(int *) * 2);       /* NOLINT(readability/casting) */
    for (int i = 0; i < 2; i++) {
        actual2DArr[i] = (int *)malloc(sizeof(int) * 3);         /* NOLINT(readability/casting) */
    }
    actual2DArr[0][0] = 6;
    actual2DArr[0][1] = 5;
    actual2DArr[0][2] = 4;
    actual2DArr[1][0] = 3;
    actual2DArr[1][1] = 2;
    actual2DArr[1][2] = 1;
    int actualRtnColSize[2] = {3, 3};

    /* 运行结果 */
    sort2DArray(actual2DArr, 2, actualRtnColSize);
    printf("\n");
    validate2DArray('1', expect2DArr, 2, expectRtnColSize, actual2DArr, 2, actualRtnColSize, 1);

    /* 比较结果 */
    EXPECT_EQ(actual2DArr[0][0], 1);
    EXPECT_EQ(actual2DArr[0][1], 2);
    EXPECT_EQ(actual2DArr[0][2], 3);
    EXPECT_EQ(actual2DArr[1][0], 4);
    EXPECT_EQ(actual2DArr[1][1], 5);
    EXPECT_EQ(actual2DArr[1][2], 6);
}