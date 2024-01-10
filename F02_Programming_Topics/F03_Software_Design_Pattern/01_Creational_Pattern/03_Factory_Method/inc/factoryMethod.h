/*
 * @FilePath     : \Practice_LeetCode_C\02_Programming_Topics\03_Software_Design_Pattern\01_Creational_Pattern\03_Factory_Method\inc\factoryMethod.h
 * @Author       : Chong Liu
 * @CreateDate   : 2024-01-04 00:27:35
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-04 00:45:20
 * =================================================================================
 * Copyright (c) 2024 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : factory method header file 工厂方法模式头文件
 */
#ifndef __FACTORY_METHOD_H
#define __FACTORY_METHOD_H

/**********************************************************************************/
/*                                                                                */
/*                               STRUCT DEFINITION                                */
/*                                                                                */
/**********************************************************************************/
typedef struct Product {
    void (*use)(struct Product *product);   /* function pointer: simulate virtual function */
    /* other member */
} Product;

typedef struct Factory {
    Product *(*createProduct)(struct Factory *factory);     /* function pointer: simulate virtual function */
    /* other member */
} Factory;

typedef struct ConcreteProductA {
    Product base;   /* inherit from Product */
    /* other member */
} ConcreteProductA;

typedef struct ConcreteFactoryA {
    Factory base;   /* inherit from Factory */
    /* other member */
} ConcreteFactoryA;

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/* ============================================================================== */
/* product functions */
/* ============================================================================== */
void useProductA(Product *product);
Product *createProductA(Factory *factory);
/* ============================================================================== */
/* factory functions */
/* ============================================================================== */
Product *createConcreteProductA(Factory *factory);
Factory *createFactoryA();

#endif  /* __FACTORY_METHOD_H */
