/*
 * @FilePath     : \Practice_LeetCode_C\F01_Common_Functions\test\commonCmdTest.cc
 * @Author       : Chong Liu
 * @CreateDate   : 2023-12-13 00:47:48
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-25 10:33:14
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : Common Command Unit Test (通用命令单元测试)
 */
extern "C" {
    /* Target header file (目标头文件) */
    #include "F01_Common_Functions/inc/common_cmd.h"
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
class TestCommonCmd : public ::testing::Test {
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
/* CMD_PrintInput */
/* ============================================================================== */
TEST_F(TestCommonCmd, TestPrintCommandInfo) {
    /* 准备数据 */
    const char *argv[] = {"./test", "-h"};
    int argc = sizeof(argv) / sizeof(char *);
    /* 执行函数 */
    printf("============================================================ Print Start.\n");
    int ret = CMD_PrintInput(argc, argv);
    printf("============================================================ Print End.\n");
    /* 验证结果 */
    EXPECT_EQ(COMMON_OK, ret) << "Error occurred in CMD_PrintInput()";
}
