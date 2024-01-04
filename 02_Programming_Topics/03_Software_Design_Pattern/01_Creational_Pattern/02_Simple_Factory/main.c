/*
 * @FilePath     : \Practice_LeetCode_C\02_Programming_Topics\03_Software_Design_Pattern\01_Creational_Pattern\02_Simple_Factory\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2024-01-04 00:03:18
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-04 10:42:15
 * =================================================================================
 * Copyright (c) 2024 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : simple factory main file 简单工厂模式主文件
 *      通过传入枚举输出不同的结构体
 */
/* standard header file 标准头文件 */
#include <stdio.h>
#include <stdlib.h>
/* simple factory header file 简单工厂模式头文件 */
#include "simpleFactory.h"



/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 测试 1
 * =================================================================================
 * @return {void}
 */
void test_1(void) {
    ProductA *a = (ProductA *)createProduct(PRODUCT_A);
    ProductB *b = (ProductB *)createProduct(PRODUCT_B);
    ProductC *c = (ProductC *)createProduct(PRODUCT_C);

    printf("a->type = %s\n", getProductTypeName(a->type));
    printf("b->type = %s\n", getProductTypeName(b->type));
    printf("c->type = %s\n", getProductTypeName(c->type));

    free(a);
    free(b);
    free(c);
}

/**********************************************************************************/
/*                                                                                */
/*                                  MAIN FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 主函数
 * =================================================================================
 * @param {int} argc        程序入参个数
 * @param {char} *argv[]    程序入参字符串数组
 * @return {int}            程序运行状态
 */
int main(int argc, const char *argv[]) {
    test_1();
    return 0;
}