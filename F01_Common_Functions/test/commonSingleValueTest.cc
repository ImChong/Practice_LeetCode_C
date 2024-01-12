/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\test\commonSingleValueTest.cc
 * @Author       : Chong Liu
 * @CreateDate   : 2023-12-16 00:25:02
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-16 00:28:06
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用单值函数单元测试
 */
/* gtest 头文件 */
#include "gtest/gtest.h"
/* 测试目标头文件 */
extern "C" {
    #include "commonTypeDef.h"
    #include "commonSingleValue.h"
}

/**********************************************************************************/
/*                                                                                */
/*                                   TEST SUITE                                   */
/*                                                                                */
/**********************************************************************************/
class TestCommonSingleValue : public ::testing::Test {
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
/* type_of_ptr */
/* ============================================================================== */
TEST_F(TestCommonSingleValue, TestTypeOfPtr) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

/* ============================================================================== */
/* type_of */
/* ============================================================================== */
TEST_F(TestCommonSingleValue, TestTypeOf) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

/* ============================================================================== */
/* MAX */
/* ============================================================================== */
TEST_F(TestCommonSingleValue, TestMAX) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

/* ============================================================================== */
/* MIN */
/* ============================================================================== */
TEST_F(TestCommonSingleValue, TestMIN) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

/**********************************************************************************/
/*                                                                                */
/*                                  TEST_FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/* ============================================================================== */
/* Validate_SingleValue */
/* ============================================================================== */
TEST_F(TestCommonSingleValue, TestValidateSingleValue) {
    /* TODO */
    EXPECT_EQ(0, 0);
}
