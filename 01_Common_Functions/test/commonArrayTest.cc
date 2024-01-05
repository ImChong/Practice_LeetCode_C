/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\test\commonArrayTest.cc
 * @Author       : Chong Liu
 * @CreateDate   : 2023-12-01 02:17:51
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-15 23:15:25
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用数组单元测试
 */
/* gtest 头文件 */
#include "gtest/gtest.h"
/* 测试目标头文件 */
extern "C" {
    #include "commonTypeDef.h"
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
    EXPECT_EQ(2, compareElements(&a, &b)) << "Error occurred in compareElements a > b";

    /* 准备数据 */
    a = 3;
    b = 5;
    /* 运行结果 & 比较结果 */
    EXPECT_EQ(-2, compareElements(&a, &b)) << "Error occurred in compareElements a < b";

    /* 准备数据 */
    a = 5;
    b = 5;
    /* 运行结果 & 比较结果 */
    EXPECT_EQ(0, compareElements(&a, &b)) << "Error occurred in compareElements a = b";
}

/* ============================================================================== */
/* ArraySort */
/* ============================================================================== */
TEST_F(TestCommonArray, TestSortArray) {
    /* 准备数据 */
    int arr[5] = {5, 4, 3, 2, 1};

    /* 运行结果 */
    int result = ArraySort(arr, 5);

    /* 比较结果 */
    EXPECT_EQ(1, arr[0]) << "Error occurred in ArraySort arr[0]";
    EXPECT_EQ(2, arr[1]) << "Error occurred in ArraySort arr[1]";
    EXPECT_EQ(3, arr[2]) << "Error occurred in ArraySort arr[2]";
    EXPECT_EQ(4, arr[3]) << "Error occurred in ArraySort arr[3]";
    EXPECT_EQ(5, arr[4]) << "Error occurred in ArraySort arr[4]";
    EXPECT_EQ(COMMON_OK, result) << "Error occurred in ArraySort result";
}

/* ============================================================================== */
/* ArraySort2D */
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
    int result = ArraySort2D(arrPtr, 2, arrColSize);

    /* 比较结果 */
    EXPECT_EQ(0, arrPtr[0][0]) << "Error occurred in ArraySort2D arrPtr[0][0]";
    EXPECT_EQ(1, arrPtr[0][1]) << "Error occurred in ArraySort2D arrPtr[0][1]";
    EXPECT_EQ(2, arrPtr[0][2]) << "Error occurred in ArraySort2D arrPtr[0][2]";
    EXPECT_EQ(3, arrPtr[1][0]) << "Error occurred in ArraySort2D arrPtr[1][0]";
    EXPECT_EQ(4, arrPtr[1][1]) << "Error occurred in ArraySort2D arrPtr[1][1]";
    EXPECT_EQ(5, arrPtr[1][2]) << "Error occurred in ArraySort2D arrPtr[1][2]";
    EXPECT_EQ(COMMON_OK, result) << "Error occurred in ArraySort2D result";
}

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
/* ============================================================================== */
/* ArrayPrint */
/* ============================================================================== */
TEST_F(TestCommonArray, TestPrintArray) {
    /* 准备数据 */
    int arr[5] = {1, 2, 3, 4, 5};

    /* 运行结果 */
    printf("============================================================ Print Start.\n");
    int result = ArrayPrint(arr, 5);
    printf("============================================================ Print End.\n");

    /* 检查结果 */
    EXPECT_EQ(COMMON_OK, result) << "Error occurred in ArrayPrint";
}

/* ============================================================================== */
/* ArrayPrint2D */
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
    printf("============================================================ Print Start.\n");
    int result = ArrayPrint2D(arrPtr, 2, arrColSize);
    printf("============================================================ Print End.\n");

    /* 检查结果 */
    EXPECT_EQ(COMMON_OK, result) << "Error occurred in ArrayPrint2D";
}

/* ============================================================================== */
/* freeArray */
/* ============================================================================== */
TEST_F(TestCommonArray, TestFreeArray) {
    /* 准备数据 */
    int *arr = (int *)malloc(sizeof(int) * 5);              /* NOLINT(readability/casting) */

    /* 运行结果 */
    int result = freeArray(&arr);

    /* 比较结果 */
    EXPECT_EQ(nullptr, arr) << "Error occurred in freeArray";
    EXPECT_EQ(COMMON_OK, result) << "Error occurred in freeArray result";
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
    int result = free2DArray(&arrPtr, 2);

    /* 比较结果 */
    EXPECT_EQ(nullptr, arrPtr) << "Error occurred in free2DArray";
    EXPECT_EQ(COMMON_OK, result) << "Error occurred in free2DArray result";
}

/**********************************************************************************/
/*                                                                                */
/*                                  TEST_FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/* ============================================================================== */
/* validateArray */
/* ============================================================================== */
TEST_F(TestCommonArray, TestValidateArray) {
    /* 准备数据 */
    int expectArr[5] = {1, 2, 3, 4, 5};
    int actualArr[5] = {5, 4, 3, 2, 1};

    /* 运行结果 */
    ArraySort(actualArr, 5);
    printf("============================================================ Print Start.\n");
    int result = validateArray('1', expectArr, 5, actualArr, 5, 1);
    printf("============================================================ Print End.\n");

    /* 比较结果 */
    EXPECT_EQ(COMMON_OK, result) << "Error occurred in validateArray";
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
    ArraySort2D(actual2DArr, 2, actualRtnColSize);
    printf("============================================================ Print Start.\n");
    int result = validate2DArray('1', expect2DArr, 2, expectRtnColSize, actual2DArr, 2, actualRtnColSize, 1);
    printf("============================================================ Print End.\n");

    /* 比较结果 */
    EXPECT_EQ(COMMON_OK, result) << "Error occurred in validate2DArray";
}
