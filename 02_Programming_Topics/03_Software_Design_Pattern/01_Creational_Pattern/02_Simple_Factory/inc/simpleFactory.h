/*
 * @FilePath     : \Practice_LeetCode_C\02_Programming_Topics\03_Software_Design_Pattern\01_Creational_Pattern\02_Simple_Factory\inc\simpleFactory.h
 * @Author       : Chong Liu
 * @CreateDate   : 2024-01-03 23:51:26
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-04 00:19:22
 * =================================================================================
 * Copyright (c) 2024 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : simple factory header file 简单工厂模式头文件
 */
#ifndef __SIMPLE_FACTORY_H
#define __SIMPLE_FACTORY_H

/**********************************************************************************/
/*                                                                                */
/*                               STRUCT DEFINITION                                */
/*                                                                                */
/**********************************************************************************/
typedef struct {
    int type;
    /* other specific fields */
} ProductA;

typedef struct {
    int type;
    /* other specific fields */
} ProductB;

typedef struct {
    int type;
    /* other specific fields */
} ProductC;

/**********************************************************************************/
/*                                                                                */
/*                                ENUM DEFINITION                                 */
/*                                                                                */
/**********************************************************************************/
typedef enum {
    PRODUCT_A,
    PRODUCT_B,
    PRODUCT_C
} ProductType;

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
void *createProduct(ProductType type);

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
const char *getProductTypeName(ProductType type);

#endif  /* __SIMPLE_FACTORY_H */
