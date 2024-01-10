/*
 * @FilePath     : \Practice_LeetCode_C\02_Programming_Topics\03_Software_Design_Pattern\01_Creational_Pattern\02_Simple_Factory\src\simpleFactory.c
 * @Author       : Chong Liu
 * @CreateDate   : 2024-01-03 23:51:37
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-04 00:20:09
 * =================================================================================
 * Copyright (c) 2024 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : simple factory source file 简单工厂模式源文件
 */
/* standard header file 标准头文件 */
#include <stdio.h>
#include <stdlib.h>
/* simple factory header file 简单工厂模式头文件 */
#include "simpleFactory.h"

/**********************************************************************************/
/*                                                                                */
/*                                 GLOBAL VARIABLES                               */
/*                                                                                */
/**********************************************************************************/
const char *ProductTypeNames[] = {
    "PRODUCT_A",
    "PRODUCT_B",
    "PRODUCT_C"
};

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 创建产品 A
 * =================================================================================
 * @return {static void *} product      产品
 */
static void *createProductA(void) {
    void *product = (void *)malloc(sizeof(ProductA));
    ((ProductA *)product)->type = PRODUCT_A;
    return product;
}

/**
 * @description: 创建产品 B
 * =================================================================================
 * @return {static void *} product      产品
 */
static void *createProductB(void) {
    void *product = (void *)malloc(sizeof(ProductB));
    ((ProductB *)product)->type = PRODUCT_B;
    return product;
}

/**
 * @description: 创建产品 C
 * =================================================================================
 * @return {static void *} product      产品
 */
static void *createProductC(void) {
    void *product = (void *)malloc(sizeof(ProductC));
    ((ProductC *)product)->type = PRODUCT_C;
    return product;
}

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 创建产品
 * =================================================================================
 * @param {ProductType} type        产品类型
 * @return {void *} product         产品
 */
void *createProduct(ProductType type) {
    void *product = NULL;
    switch (type) {
        case PRODUCT_A:
            product = createProductA();
            break;
        case PRODUCT_B:
            product = createProductB();
            break;
        case PRODUCT_C:
            product = createProductC();
            break;
    }
    return product;
}

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 获取产品类型名称
 * =================================================================================
 * @param {ProductType} type                    产品类型
 * @return {const char *} product type name     产品类型名称
 */
const char *getProductTypeName(ProductType type) {
    return ProductTypeNames[type];
}