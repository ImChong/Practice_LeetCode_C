/*
 * @FilePath     : \Practice_LeetCode_C\F01_Common_Functions\test\commonRingBufferTest.cc
 * @Author       : Chong Liu
 * @CreateDate   : 2023-12-15 22:59:03
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-12 23:57:55
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : Common Ring Buffer Unit Test (通用环形缓冲区单元测试)
 */
extern "C" {
    /* Target header file (目标头文件) */
    #include "commonRingBuffer.h"
    /* Common function header file (通用头文件) */
    #include "common_type_def.h"
}
/* Google test header file (谷歌测试头文件) */
#include "gtest/gtest.h"

/**********************************************************************************/
/*                                                                                */
/*                                   TEST SUITE                                   */
/*                                                                                */
/**********************************************************************************/
class TestCommonRingBuffer : public ::testing::Test {
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
/*                                 UTILITY FUNCTIONS                              */
/*                                                                                */
/**********************************************************************************/
/* ============================================================================== */
/* RingBuffer_Init */
/* ============================================================================== */
TEST_F(TestCommonRingBuffer, TestRingBuffer_Init) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

/* ============================================================================== */
/* RingBuffer_AddByte */
/* ============================================================================== */
TEST_F(TestCommonRingBuffer, TestRingBuffer_AddByte) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

/* ============================================================================== */
/* RingBuffer_GetByte */
/* ============================================================================== */
TEST_F(TestCommonRingBuffer, TestRingBuffer_GetByte) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
/* ============================================================================== */
/* RingBuffer_Print */
/* ============================================================================== */
TEST_F(TestCommonRingBuffer, TestRingBuffer_Print) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

/* ============================================================================== */
/* RingBuffer_Free */
/* ============================================================================== */
TEST_F(TestCommonRingBuffer, TestRingBuffer_Free) {
    /* TODO */
    EXPECT_EQ(0, 0);
}
