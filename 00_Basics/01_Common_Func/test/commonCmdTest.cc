/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\test\commonCmdTest.cc
 * @Author       : Chong Liu
 * @CreateDate   : 2023-12-13 00:47:48
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-12-13 01:02:08
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
    #include "commonCmd.h"
}

/**********************************************************************************/
/*                                                                                */
/*                                   TEST SUITE                                   */
/*                                                                                */
/**********************************************************************************/
class TestCommonCmd : public ::testing::Test {
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

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
TEST_F(TestCommonCmd, TestCmdHelp) {
    /* 准备数据 */
    char *argv[] = {"./test", "-h"};
    int argc = sizeof(argv) / sizeof(char *);
    /* 执行函数 */
    printf("\n");
    int ret = printCommandInfo(argc, argv);
    printf("\n");
    /* 验证结果 */
    EXPECT_EQ(COMMON_OK, ret) << "Error occurred in printCommandInfo()";
}
