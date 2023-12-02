/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\test\commonArrayTest.cc
 * @Author       : Chong Liu
 * @CreateDate   : 2023-12-01 02:17:51
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-02 10:56:03
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用数组单元测试
 */
/* gtest 头文件 */
#include "gtest/gtest.h"
/* 测试目标头文件 */
extern "C" {
    #include "commonArray.h"
}

/**********************************************************************************/
/*                                                                                */
/*                                   TEST SUITE                                   */
/*                                                                                */
/**********************************************************************************/
class TestCommonArray : public ::testing::Test {
protected:
    // void SetUpTestCase() {
    //     // Code here will be called immediately after the constructor (right
    //     // before each test).
    // }

    // void TearDownTestCase() {
    //     // Code here will be called immediately after each test (right
    //     // before the destructor).
    // }

    void SetUp() override {
        // Code here will be called before each test
    }

    void TearDown() override {
        // Code here will be called after each test
    }
};

/**********************************************************************************/
/*                                                                                */
/*                                   TEST CASES                                   */
/*                                                                                */
/**********************************************************************************/
/* 测试用例名称 */
TEST_F(TestCommonArray, TestCompareElements) {
    int a = 5;
    int b = 3;
    EXPECT_EQ(compareElements(&a, &b), 2);

    a = 3;
    b = 5;
    EXPECT_EQ(compareElements(&a, &b), -2);

    a = 5;
    b = 5;
    EXPECT_EQ(compareElements(&a, &b), 0);
}