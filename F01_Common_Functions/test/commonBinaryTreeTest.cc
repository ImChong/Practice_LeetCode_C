/*
 * @FilePath     : \Practice_LeetCode_C\F01_Common_Functions\test\commonBinaryTreeTest.cc
 * @Author       : Chong Liu
 * @CreateDate   : 2023-12-13 00:47:48
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-12 23:37:28
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : Common Binary Tree Unit Test (通用二叉树单元测试)
 */
extern "C" {
    /* Target header file (目标头文件) */
    #include "commonBinaryTree.h"
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
class TestCommonBinaryTree : public ::testing::Test {
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
/* TreeLkListQueue */
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
