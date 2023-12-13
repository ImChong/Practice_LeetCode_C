/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\test\commonHashTableTest.cc
 * @Author       : Chong Liu
 * @CreateDate   : 2023-12-13 21:58:33
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-13 22:04:41
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用哈希表单元测试
 */
/* gtest 头文件 */
#include "gtest/gtest.h"
/* 测试目标头文件 */
extern "C" {
    #include "commonTypeDef.h"
    #include "commonHashTable.h"
}

/**********************************************************************************/
/*                                                                                */
/*                                   TEST SUITE                                   */
/*                                                                                */
/**********************************************************************************/
class TestCommonHashTable : public ::testing::Test {
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
TEST_F(TestCommonHashTable, TestCreateHashTable) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

TEST_F(TestCommonHashTable, TestInsertHashTable) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

TEST_F(TestCommonHashTable, TestSearchHashTable) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

TEST_F(TestCommonHashTable, TestRemoveHashTable) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

TEST_F(TestCommonHashTable, TestFreeHashTable) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

TEST_F(TestCommonHashTable, TestPrintHashTable) {
    /* TODO */
    EXPECT_EQ(0, 0);
}
