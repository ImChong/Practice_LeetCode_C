/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\test\commonArrayTest.cc
 * @Author       : Chong Liu
 * @CreateDate   : 2023-12-01 02:17:51
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-02 20:23:00
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
/* ============================================================================== */
/* ARR_SIZE */
/* ============================================================================== */
TEST_F(TestCommonArray, TestArrSize) {
    int arr[5] = {1, 2, 3, 4, 5};
    EXPECT_EQ((int)ARR_SIZE(arr), 5);
}

/* ============================================================================== */
/* compareElements */
/* ============================================================================== */
TEST_F(TestCommonArray, TestCompareElements) {
    int a = 5;
    int b = 3;
    EXPECT_EQ(compareElements(&a, &b), 2);

    a = 3;
    b = 5;
    EXPECT_EQ(compareElements(&a, &b), -2);

    a = 5;
    b = 5;
    EXPECT_EQ(compareElements(&a, &b), 0);
}

/* ============================================================================== */
/* sortArray */
/* ============================================================================== */
TEST_F(TestCommonArray, TestSortArray) {
    int arr[5] = {5, 4, 3, 2, 1};
    sortArray(arr, 5);
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
    int arr[2][3] = {{5, 4, 3}, {2, 1, 0}};
    int *arrPtr[2] = {arr[0], arr[1]};
    int arrColSize[2] = {3, 3};
    sort2DArray(arrPtr, 2, arrColSize);

    EXPECT_EQ(arr[0][0], 3);
    EXPECT_EQ(arr[0][1], 4);
    EXPECT_EQ(arr[0][2], 5);
    EXPECT_EQ(arr[1][0], 0);
    EXPECT_EQ(arr[1][1], 1);
    EXPECT_EQ(arr[1][2], 2);

    EXPECT_EQ(arrPtr[0][0], 0);
    EXPECT_EQ(arrPtr[0][1], 1);
    EXPECT_EQ(arrPtr[0][2], 2);
    EXPECT_EQ(arrPtr[1][0], 3);
    EXPECT_EQ(arrPtr[1][1], 4);
    EXPECT_EQ(arrPtr[1][2], 5);
}