/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\test\commonQueueTest.cc
 * @Author       : Chong Liu
 * @CreateDate   : 2023-12-13 22:37:54
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-16 00:16:13
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  :
 */
/* gtest 头文件 */
#include "gtest/gtest.h"
/* 测试目标头文件 */
extern "C" {
    #include "commonTypeDef.h"
    #include "commonQueue.h"
}

/**********************************************************************************/
/*                                                                                */
/*                                   TEST SUITE                                   */
/*                                                                                */
/**********************************************************************************/
class TestCommonQueue : public ::testing::Test {
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
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/* ============================================================================== */
/* Queue_Init */
/* ============================================================================== */
TEST_F(TestCommonQueue, TestInitQueue) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

/* ============================================================================== */
/* Queue_En */
/* ============================================================================== */
TEST_F(TestCommonQueue, TestEnQueue) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

/* ============================================================================== */
/* Queue_De */
/* ============================================================================== */
TEST_F(TestCommonQueue, TestDeQueue) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

/* ============================================================================== */
/* Queue_IsEmpty */
/* ============================================================================== */
TEST_F(TestCommonQueue, TestIsQueueEmpty) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

/* ============================================================================== */
/* Queue_IsFull */
/* ============================================================================== */
TEST_F(TestCommonQueue, TestIsQueueFull) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
/* ============================================================================== */
/* Queue_Print */
/* ============================================================================== */
TEST_F(TestCommonQueue, TestPrintQueue) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

/* ============================================================================== */
/* Queue_Free */
/* ============================================================================== */
TEST_F(TestCommonQueue, TestFreeQueue) {
    /* TODO */
    EXPECT_EQ(0, 0);
}
