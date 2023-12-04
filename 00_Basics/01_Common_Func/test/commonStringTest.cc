
/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\test\commonStringTest.cc
 * @Author       : Chong Liu
 * @CreateDate   : 2023-12-01 02:24:32
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-05 01:34:30
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用二叉树单元测试
 */
/* gtest 头文件 */
#include "gtest/gtest.h"
/* 测试目标头文件 */
extern "C" {
    #include "commonTypeDef.h"
    #include "commonString.h"
}

/**********************************************************************************/
/*                                                                                */
/*                                   TEST SUITE                                   */
/*                                                                                */
/**********************************************************************************/
class TestCommonString : public ::testing::Test {
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
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/* ============================================================================== */
/* swapChar */
/* ============================================================================== */
TEST_F(TestCommonString, TestSwapChar) {
    /* 准备数据 */
    char a = 'a';
    char b = 'b';

    /* 运行结果 */
    int result = swapChar(&a, &b);

    /* 比较结果 */
    EXPECT_EQ(a, 'b') << "Error occurred at parameter a";
    EXPECT_EQ(b, 'a') << "Error occurred at parameter b";
    EXPECT_EQ(result, COMMON_OK) << "Error occurred at return value";
}

/* ============================================================================== */
/* reverseStringSection */
/* ============================================================================== */
TEST_F(TestCommonString, TestReverseStringSection) {
    /* 准备数据 */
    char *s = (char *)malloc(sizeof(char) * 8);     /* NOLINT(readability/casting) */
    int charSize = sizeof(s);
    snprintf(s, charSize, "%s", "abcdefg");

    /* 运行结果 */
    int result = reverseStringSection(s, 2, 5);

    /* 比较结果 */
    EXPECT_STREQ(s, "abfedcg") << "Error occurred at parameter s";
    EXPECT_EQ(result, COMMON_OK) << "Error occurred at return value";
}

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
/* ============================================================================== */
/* printString */
/* ============================================================================== */
TEST_F(TestCommonString, TestPrintString) {
    /* 准备数据 */
    char *s = "Hello World!";

    /* 运行结果 */
    printf("\n");
    int result = printString(s);
    printf("\n");

    /* 比较结果 */
    EXPECT_EQ(result, COMMON_OK) << "Error occurred at return value";
}

/* ============================================================================== */
/* freeString */
/* ============================================================================== */
TEST_F(TestCommonString, TestFreeString) {
    /* 准备数据 */
    char *s = (char *)malloc(sizeof(char) * 8);     /* NOLINT(readability/casting) */
    int charSize = sizeof(s);
    snprintf(s, charSize, "%s", "Hello World!");

    /* 运行结果 */
    int result = freeString(&s);

    /* 比较结果 */
    EXPECT_EQ(s, nullptr) << "Error occurred at parameter s";
    EXPECT_EQ(result, COMMON_OK) << "Error occurred at return value";
}

/* ============================================================================== */
/* validateString */
/* ============================================================================== */
TEST_F(TestCommonString, TestValidateString) {
    /* 准备数据 */
    char *expect = "Hello World!";
    char *actual = "Hello World!";

    /* 运行结果 */
    int result = validateString('1', expect, actual);

    /* 比较结果 */
    EXPECT_EQ(result, COMMON_OK) << "Error occurred at return value";
}
