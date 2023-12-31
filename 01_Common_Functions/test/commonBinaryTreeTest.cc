/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\test\commonBinaryTreeTest.cc
 * @Author       : Chong Liu
 * @CreateDate   : 2023-12-13 00:47:48
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-15 23:08:15
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用命令行指令单元测试
 */
/* gtest 头文件 */
#include "gtest/gtest.h"
/* 测试目标头文件 */
extern "C" {
    #include "commonTypeDef.h"
    #include "commonBinaryTree.h"
}

/**********************************************************************************/
/*                                                                                */
/*                                   TEST SUITE                                   */
/*                                                                                */
/**********************************************************************************/
class TestCommonBinaryTree : public ::testing::Test {
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
/* preOrderTraversal */
/* ============================================================================== */
TEST_F(TestCommonBinaryTree, TestPreOrderTraversal) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

/* ============================================================================== */
/* inOrderTraversal */
/* ============================================================================== */
TEST_F(TestCommonBinaryTree, TestInOrderTraversal) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

/* ============================================================================== */
/* postOrderTraversal */
/* ============================================================================== */
TEST_F(TestCommonBinaryTree, TestPostOrderTraversal) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

/* ============================================================================== */
/* levelOrder */
/* ============================================================================== */
TEST_F(TestCommonBinaryTree, TestLevelOrder) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
/* ============================================================================== */
/* TreeArrQueue */
/* ============================================================================== */
TEST_F(TestCommonBinaryTree, TestTreeArrQueue) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

/* ============================================================================== */
/* TreeListQueue */
/* ============================================================================== */
TEST_F(TestCommonBinaryTree, TestTreeListQueue) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

/* ============================================================================== */
/* TreeOperation */
/* ============================================================================== */
TEST_F(TestCommonBinaryTree, TestTreeOperation) {
    /* TODO */
    EXPECT_EQ(0, 0);
}
