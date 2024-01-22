/*
 * @FilePath     : \Practice_LeetCode_C\02_Programming_Topics\03_Software_Design_Pattern\01_Creational_Pattern\03_Factory_Method\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2024-01-04 00:26:57
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-04 00:40:12
 * =================================================================================
 * Copyright (c) 2024 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : factory method main function 工厂方法模式主函数
 */
/* standard head file 标准头文件 */
#include <stdlib.h>
/* factory method head file 工厂方法模式头文件 */
#include "factoryMethod.h"

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: Test 1
 * =================================================================================
 * @return {void}
 */
void Test1(void) {
    Factory *factoryA = createFactoryA();
    Product *productA = factoryA->createProduct(factoryA);
    productA->use(productA);

    free(productA);
    free(factoryA);
}

/**
 * @description: 主函数
 * =================================================================================
 * @param {int} argc        程序入参个数
 * @param {char} *argv[]    程序入参字符串数组
 * @return {int}            程序运行状态
 */
int main(int argc, const char *argv[]) {
    Test1();
    return 0;
}