/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\test\commonRingBufferTest.cc
 * @Author       : Chong Liu
 * @CreateDate   : 2023-12-15 22:59:03
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-15 23:03:58
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用环形缓冲区单元测试
 */
/* gtest 头文件 */
#include "gtest/gtest.h"
/* 测试目标头文件 */
extern "C" {
    #include "commonTypeDef.h"
    #include "commonRingBuffer.h"
}

/**********************************************************************************/
/*                                                                                */
/*                                   TEST SUITE                                   */
/*                                                                                */
/**********************************************************************************/
class TestCommonRingBuffer : public ::testing::Test {
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
/*                                 UTILITY FUNCTIONS                              */
/*                                                                                */
/**********************************************************************************/
TEST_F(TestCommonRingBuffer, TestRingBuffer_Init) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

TEST_F(TestCommonRingBuffer, TestRingBuffer_AddByte) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

TEST_F(TestCommonRingBuffer, TestRingBuffer_GetByte) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
TEST_F(TestCommonRingBuffer, TestRingBuffer_Print) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

