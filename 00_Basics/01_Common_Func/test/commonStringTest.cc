
/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\test\commonStringTest.cc
 * @Author       : Chong Liu
 * @CreateDate   : 2023-12-01 02:24:32
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-02 23:35:21
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用二叉树单元测试
 */
/* gtest 头文件 */
#include "gtest/gtest.h"
/* 测试目标头文件 */
extern "C" {
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
/* ============================================================================== */
/* swapChar */
/* ============================================================================== */
TEST_F(TestCommonString, TestSwapChar) {
    /* 准备数据 */
    char a = 'a';
    char b = 'b';

    /* 运行结果 */
    swapChar(&a, &b);

    /* 比较结果 */
    EXPECT_EQ(a, 'b');
    EXPECT_EQ(b, 'a');
}

/* ============================================================================== */
/* reverseStringSection */
/* ============================================================================== */
TEST_F(TestCommonString, TestReverseStringSection) {
    /* 准备数据 */
    char *s = (char *)malloc(sizeof(char) * 8);     /* NOLINT(readability/casting) */
    snprintf(s, 8, "%s", "abcdefg");

    /* 运行结果 */
    reverseStringSection(s, 2, 5);

    /* 比较结果 */
    EXPECT_STREQ(s, "abfedcg");
}
