
/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\test\commonStringTest.cc
 * @Author       : Chong Liu
 * @CreateDate   : 2023-12-01 02:24:32
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-15 23:05:31
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
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/* ============================================================================== */
/* Char_Swap */
/* ============================================================================== */
TEST_F(TestCommonString, TestSwapChar) {
    /* 准备数据 */
    char a = 'a';
    char b = 'b';

    /* 运行结果 */
    int result = Char_Swap(&a, &b);

    /* 比较结果 */
    EXPECT_EQ(a, 'b') << "Error occurred at parameter a";
    EXPECT_EQ(b, 'a') << "Error occurred at parameter b";
    EXPECT_EQ(result, COMMON_OK) << "Error occurred at return value";
}

/* ============================================================================== */
/* String_Reverse */
/* ============================================================================== */
TEST_F(TestCommonString, TestReverseStringSection) {
    /* 准备数据 */
    char *s = (char *)malloc(sizeof(char) * 8);     /* NOLINT(readability/casting) */
    int charSize = sizeof(s);
    snprintf(s, charSize, "%s", "abcdefg");

    /* 运行结果 */
    int result = String_Reverse(s, 2, 5);

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
/* String_Print */
/* ============================================================================== */
TEST_F(TestCommonString, TestPrintString) {
    /* 准备数据 */
    char *s = (char *)malloc(sizeof(char) * 13);        /* NOLINT(readability/casting) */
    int charSize = 13;
    snprintf(s, charSize, "%s", "Hello World!");

    /* 运行结果 */
    printf("============================================================ Print Start.\n");
    int result = String_Print(s);
    printf("============================================================ Print End.\n");

    /* 比较结果 */
    EXPECT_EQ(result, COMMON_OK) << "Error occurred at return value";
}

/* ============================================================================== */
/* String_Free */
/* ============================================================================== */
TEST_F(TestCommonString, TestFreeString) {
    /* 准备数据 */
    int strSize = 13;
    char *s = (char *)malloc(sizeof(char) * strSize);       /* NOLINT(readability/casting) */
    snprintf(s, strSize, "%s", "Hello World!");

    /* 运行结果 */
    int result = String_Free(&s);

    /* 比较结果 */
    EXPECT_EQ(s, nullptr) << "Error occurred at parameter s";
    EXPECT_EQ(result, COMMON_OK) << "Error occurred at return value";
}

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/* ============================================================================== */
/* Validate_String */
/* ============================================================================== */
TEST_F(TestCommonString, TestValidateString) {
    /* 准备数据 */
    int expectCharSize = 13;
    char *expect = (char *)malloc(sizeof(char) * expectCharSize);     /* NOLINT(readability/casting) */
    snprintf(expect, expectCharSize, "%s", "Hello World!");
    int actualCharSize = 13;
    char *actual = (char *)malloc(sizeof(char) * actualCharSize);     /* NOLINT(readability/casting) */
    snprintf(actual, actualCharSize, "%s", "Hello World!");

    /* 运行结果 */
    printf("============================================================ Print Start.\n");
    int result = Validate_String('1', expect, actual);
    printf("============================================================ Print End.\n");

    /* 比较结果 */
    EXPECT_EQ(result, COMMON_OK) << "Error occurred at return value";
}
