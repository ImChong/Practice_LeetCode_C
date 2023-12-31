/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\test\commonHashTableTest.cc
 * @Author       : Chong Liu
 * @CreateDate   : 2023-12-13 21:58:33
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-15 23:23:22
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
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/* ============================================================================== */
/* HashTable_Init */
/* ============================================================================== */
TEST_F(TestCommonHashTable, TestHashTable_Create) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

/* ============================================================================== */
/* HashTable_Insert */
/* ============================================================================== */
TEST_F(TestCommonHashTable, TestHashTable_Insert) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

/* ============================================================================== */
/* HashTable_Search */
/* ============================================================================== */
TEST_F(TestCommonHashTable, TestHashTable_Search) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

/* ============================================================================== */
/* HashTable_Remove */
/* ============================================================================== */
TEST_F(TestCommonHashTable, TestHashTable_Remove) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
/* ============================================================================== */
/* HashTable_Print */
/* ============================================================================== */
TEST_F(TestCommonHashTable, TestHashTable_Print) {
    /* TODO */
    EXPECT_EQ(0, 0);
}

/* ============================================================================== */
/* HashTable_Free */
/* ============================================================================== */
TEST_F(TestCommonHashTable, TestHashTable_Free) {
    /* TODO */
    EXPECT_EQ(0, 0);
}
