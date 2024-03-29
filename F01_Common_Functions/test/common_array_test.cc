/*
 * @FilePath     : \Practice_LeetCode_C\F01_Common_Functions\test\common_array_test.cc
 * @Author       : Chong Liu
 * @CreateDate   : 2023-12-01 02:17:51
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-24 00:37:11
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : Common Array Unit Test (通用数组单元测试)
 */
extern "C" {
    /* Target header file (目标头文件) */
    #include "F01_Common_Functions/inc/common_array.h"
}
/* Google test header file (谷歌测试头文件) */
#include "gtest/gtest.h"

/**********************************************************************************/
/*                                                                                */
/*                                   TEST SUITE                                   */
/*                                                                                */
/**********************************************************************************/
class TestCommonArray : public ::testing::Test {
 public:
    static void SetUpTestCase() {
        /* Code here will be called once before all tests */
    }
    void SetUp() override {
        /* Code here will be called before each test */
    }
    void TearDown() override {
        /* Code here will be called after each test */
    }
    static void TearDownTestCase() {
        /* Code here will be called once after all tests */
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
    int arr_size = ARR_SIZE(arr);

    /* Validate result (验证函数调用结果) */
    EXPECT_EQ(arr_size, 5);
}

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/* ============================================================================== */
/* Array_CmpElement */
/* ============================================================================== */
TEST_F(TestCommonArray, TestCompareElements) {
    /* 准备数据 */
    int a = 5;
    int b = 3;
    /* 运行结果 & 比较结果 */
    EXPECT_EQ(2, Array_CmpElement(&a, &b)) << "Error occurred in Array_CmpElement a > b";

    /* 准备数据 */
    a = 3;
    b = 5;
    /* 运行结果 & 比较结果 */
    EXPECT_EQ(-2, Array_CmpElement(&a, &b)) << "Error occurred in Array_CmpElement a < b";

    /* 准备数据 */
    a = 5;
    b = 5;
    /* 运行结果 & 比较结果 */
    EXPECT_EQ(0, Array_CmpElement(&a, &b)) << "Error occurred in Array_CmpElement a = b";
}

/* ============================================================================== */
/* Array_Sort */
/* ============================================================================== */
TEST_F(TestCommonArray, TestSortArray) {
    /* 准备数据 */
    int arr[5] = {5, 4, 3, 2, 1};

    /* 运行结果 */
    int result = Array_Sort(arr, 5);

    /* Validate result (验证函数调用结果) */
    EXPECT_EQ(1, arr[0]) << "Error occurred in Array_Sort arr[0]";
    EXPECT_EQ(2, arr[1]) << "Error occurred in Array_Sort arr[1]";
    EXPECT_EQ(3, arr[2]) << "Error occurred in Array_Sort arr[2]";
    EXPECT_EQ(4, arr[3]) << "Error occurred in Array_Sort arr[3]";
    EXPECT_EQ(5, arr[4]) << "Error occurred in Array_Sort arr[4]";
    EXPECT_EQ(COMMON_OK, result) << "Error occurred in Array_Sort result";
}

/* ============================================================================== */
/* Array_Sort2D */
/* ============================================================================== */
TEST_F(TestCommonArray, TestSort2DArray) {
    /* 准备数据 */
    int **p_arr = (int **)malloc(sizeof(int *) * 2); /* NOLINT(readability/casting) */
    for (int i = 0; i < 2; i++) {
        p_arr[i] = (int *)malloc(sizeof(int) * 3); /* NOLINT(readability/casting) */
    }
    p_arr[0][0] = 5;
    p_arr[0][1] = 4;
    p_arr[0][2] = 3;
    p_arr[1][0] = 2;
    p_arr[1][1] = 1;
    p_arr[1][2] = 0;
    int arrColSize[2] = {3, 3};

    /* 运行结果 */
    int result = Array_Sort2D(p_arr, 2, arrColSize);

    /* Validate result (验证函数调用结果) */
    EXPECT_EQ(0, p_arr[0][0]) << "Error occurred in Array_Sort2D p_arr[0][0]";
    EXPECT_EQ(1, p_arr[0][1]) << "Error occurred in Array_Sort2D p_arr[0][1]";
    EXPECT_EQ(2, p_arr[0][2]) << "Error occurred in Array_Sort2D p_arr[0][2]";
    EXPECT_EQ(3, p_arr[1][0]) << "Error occurred in Array_Sort2D p_arr[1][0]";
    EXPECT_EQ(4, p_arr[1][1]) << "Error occurred in Array_Sort2D p_arr[1][1]";
    EXPECT_EQ(5, p_arr[1][2]) << "Error occurred in Array_Sort2D p_arr[1][2]";
    EXPECT_EQ(COMMON_OK, result) << "Error occurred in Array_Sort2D result";
}

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
/* ============================================================================== */
/* Array_Print */
/* ============================================================================== */
TEST_F(TestCommonArray, TestPrintArray) {
    /* 准备数据 */
    int arr[5] = {1, 2, 3, 4, 5};

    /* 运行结果 */
    printf("============================================================ Print Start.\n");
    int result = Array_Print(arr, 5);
    printf("============================================================ Print End.\n");

    /* 检查结果 */
    EXPECT_EQ(COMMON_OK, result) << "Error occurred in Array_Print";
}

/* ============================================================================== */
/* Array_Print2D */
/* ============================================================================== */
TEST_F(TestCommonArray, TestPrint2DArray) {
    /* 准备数据 */
    int **p_arr = (int **)malloc(sizeof(int *) * 2); /* NOLINT(readability/casting) */
    for (int i = 0; i < 2; i++) {
        p_arr[i] = (int *)malloc(sizeof(int) * 3); /* NOLINT(readability/casting) */
    }
    p_arr[0][0] = 1;
    p_arr[0][1] = 2;
    p_arr[0][2] = 3;
    p_arr[1][0] = 4;
    p_arr[1][1] = 5;
    p_arr[1][2] = 6;
    int arrColSize[2] = {3, 3};

    /* 运行结果 */
    printf("============================================================ Print Start.\n");
    int result = Array_Print2D(p_arr, 2, arrColSize);
    printf("============================================================ Print End.\n");

    /* 检查结果 */
    EXPECT_EQ(COMMON_OK, result) << "Error occurred in Array_Print2D";
}

/* ============================================================================== */
/* Array_Free */
/* ============================================================================== */
TEST_F(TestCommonArray, TestFreeArray) {
    /* 准备数据 */
    int *arr = (int *)malloc(sizeof(int) * 5); /* NOLINT(readability/casting) */

    /* 运行结果 */
    int result = Array_Free(&arr);

    /* Validate result (验证函数调用结果) */
    EXPECT_EQ(nullptr, arr) << "Error occurred in Array_Free";
    EXPECT_EQ(COMMON_OK, result) << "Error occurred in Array_Free result";
}

/* ============================================================================== */
/* Array_Free2D */
/* ============================================================================== */
TEST_F(TestCommonArray, TestFree2DArray) {
    /* 准备数据 */
    int **p_arr = (int **)malloc(sizeof(int *) * 2); /* NOLINT(readability/casting) */
    for (int i = 0; i < 2; i++) {
        p_arr[i] = (int *)malloc(sizeof(int) * 3); /* NOLINT(readability/casting) */
    }

    /* 运行结果 */
    int result = Array_Free2D(&p_arr, 2);

    /* Validate result (验证函数调用结果) */
    EXPECT_EQ(nullptr, p_arr) << "Error occurred in Array_Free2D";
    EXPECT_EQ(COMMON_OK, result) << "Error occurred in Array_Free2D result";
}

/**********************************************************************************/
/*                                                                                */
/*                                  TEST_FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/* ============================================================================== */
/* Validate_Array */
/* ============================================================================== */
TEST_F(TestCommonArray, TestValidateArray) {
    /* 准备数据 */
    int expectArr[5] = {1, 2, 3, 4, 5};
    int actualArr[5] = {5, 4, 3, 2, 1};

    /* 运行结果 */
    Array_Sort(actualArr, 5);
    printf("============================================================ Print Start.\n");
    int result = Validate_Array('1', expectArr, 5, actualArr, 5, 1);
    printf("============================================================ Print End.\n");

    /* Validate result (验证函数调用结果) */
    EXPECT_EQ(COMMON_OK, result) << "Error occurred in Validate_Array";
}

/* ============================================================================== */
/* Validate_Array2D */
/* ============================================================================== */
TEST_F(TestCommonArray, TestValidate2DArray) {
    /* 准备数据 */
    int **expect2DArr = (int **)malloc(sizeof(int *) * 2); /* NOLINT(readability/casting) */
    for (int i = 0; i < 2; i++) {
        expect2DArr[i] = (int *)malloc(sizeof(int) * 3); /* NOLINT(readability/casting) */
    }
    expect2DArr[0][0] = 1;
    expect2DArr[0][1] = 2;
    expect2DArr[0][2] = 3;
    expect2DArr[1][0] = 4;
    expect2DArr[1][1] = 5;
    expect2DArr[1][2] = 6;
    int expectRtnColSize[2] = {3, 3};

    int **actual2DArr = (int **)malloc(sizeof(int *) * 2); /* NOLINT(readability/casting) */
    for (int i = 0; i < 2; i++) {
        actual2DArr[i] = (int *)malloc(sizeof(int) * 3); /* NOLINT(readability/casting) */
    }
    actual2DArr[0][0] = 6;
    actual2DArr[0][1] = 5;
    actual2DArr[0][2] = 4;
    actual2DArr[1][0] = 3;
    actual2DArr[1][1] = 2;
    actual2DArr[1][2] = 1;
    int actualRtnColSize[2] = {3, 3};

    /* 运行结果 */
    Array_Sort2D(actual2DArr, 2, actualRtnColSize);
    printf("============================================================ Print Start.\n");
    int result = Validate_Array2D('1', expect2DArr, 2, expectRtnColSize, actual2DArr, 2, actualRtnColSize, 1);
    printf("============================================================ Print End.\n");

    /* Validate result (验证函数调用结果) */
    EXPECT_EQ(COMMON_OK, result) << "Error occurred in Validate_Array2D";
}
