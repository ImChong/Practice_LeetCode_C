/*
 * @FilePath     : \Practice_LeetCode_C\F01_Common_Functions\test\commonHashTableTest.cc
 * @Author       : Chong Liu
 * @CreateDate   : 2023-12-13 21:58:33
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-26 10:21:10
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : Common Hash Table Unit Test (通用哈希表单元测试)
 */
extern "C" {
    /* Header file (本文件头文件) */
    #include "F01_Common_Functions/inc/common_hash_table.h"
}
/* Google test header file (谷歌测试头文件) */
#include "gtest/gtest.h"

/**********************************************************************************/
/*                                                                                */
/*                                   TEST SUITE                                   */
/*                                                                                */
/**********************************************************************************/
class TestCommonHashTable : public ::testing::Test {
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
