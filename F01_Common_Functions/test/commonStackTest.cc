/*
 * @FilePath     : \Practice_LeetCode_C\F01_Common_Functions\test\commonStackTest.cc
 * @Author       : Chong Liu
 * @CreateDate   : 2023-12-16 00:25:13
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-12 23:59:32
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : Common Stack Unit Test (通用栈单元测试)
 */
extern "C" {
    /* Target header file (目标头文件) */
    #include "commonStack.h"
    /* Common function header file (通用头文件) */
    #include "F01_Common_Functions/inc/common_def/common_type_def.h"
}
/* Google test header file (谷歌测试头文件) */
#include "gtest/gtest.h"

/**********************************************************************************/
/*                                                                                */
/*                                   TEST SUITE                                   */
/*                                                                                */
/**********************************************************************************/
class TestCommonStack : public ::testing::Test {
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
/* StackCreate */
/* ============================================================================== */
TEST_F(TestCommonStack, TestStackCreate) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

/* ============================================================================== */
/* StackPush */
/* ============================================================================== */
TEST_F(TestCommonStack, TestStackPush) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

/* ============================================================================== */
/* StackPop */
/* ============================================================================== */
TEST_F(TestCommonStack, TestStackPop) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

/* ============================================================================== */
/* StackTop */
/* ============================================================================== */
TEST_F(TestCommonStack, TestStackTop) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

/* ============================================================================== */
/* StackIsEmpty */
/* ============================================================================== */
TEST_F(TestCommonStack, TestStackIsEmpty) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

/* ============================================================================== */
/* StackIsFull */
/* ============================================================================== */
TEST_F(TestCommonStack, TestStackIsFull) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
/* ============================================================================== */
/* StackPrint */
/* ============================================================================== */
TEST_F(TestCommonStack, TestStackPrint) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

/* ============================================================================== */
/* StackFree */
/* ============================================================================== */
TEST_F(TestCommonStack, TestStackFree) {
    /* TODO */
    EXPECT_EQ(0, 0);
}
