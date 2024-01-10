/*
 * @FilePath     : \Practice_LeetCode_C\02_Programming_Topics\03_Software_Design_Pattern\01_Creational_Pattern\03_Factory_Method\src\factoryMethod.c
 * @Author       : Chong Liu
 * @CreateDate   : 2024-01-04 00:27:22
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-04 00:48:01
 * =================================================================================
 * Copyright (c) 2024 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : factory method source file 工厂方法模式源文件
 */
/* standard head file 标准头文件 */
#include <stdio.h>
#include <stdlib.h>
/* factory method head file 工厂方法模式头文件 */
#include "factoryMethod.h"

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/* ============================================================================== */
/* product functions */
/* ============================================================================== */
/**
 * @description: 使用产品 A
 * =================================================================================
 * @param {Product} *product        产品
 * @return {void}
 */
void useProductA(Product *product) {
    printf("Using Product A\n");
}

/**
 * @description: 创建产品 A
 * =================================================================================
 * @param {Factory} *factory        工厂
 * @return {Product *} product      产品
 */
Product *createProductA(Factory *factory) {
    ConcreteProductA *product = (ConcreteProductA *)malloc(sizeof(ConcreteProductA));
    product->base.use = useProductA;
    return (Product *)product;
}

/* ============================================================================== */
/* factory functions */
/* ============================================================================== */
/**
 * @description: 创建产品 A
 * =================================================================================
 * @param {Factory} *factory
 * @return {*}
 */
Product *createConcreteProductA(Factory *factory) {
    return createProductA(factory);
}

/**
 * @description: 创建工厂 A
 * =================================================================================
 * @return {*}
 */
Factory *createFactoryA() {
    ConcreteFactoryA *factory = (ConcreteFactoryA *)malloc(sizeof(ConcreteFactoryA));
    factory->base.createProduct = createConcreteProductA;
    return (Factory *)factory;
}
