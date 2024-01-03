/*
 * @FilePath     : \Practice_LeetCode_C\02_Programming_Topics\03_Software_Design_Pattern\01_Singleton\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2024-01-03 13:07:30
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-03 13:31:49
 * =================================================================================
 * Copyright (c) 2024 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : singleton main file 单例模式主文件
 *      单例设计模式（Singleton Design Pattern）是一种软件设计模式，用于确保一个类只有一个实例，并提供一个全局访问点来获取这个实例。
 *      这个模式在需要严格控制如何以及何时访问某个共享资源时非常有用。
 */
/* standard header file (标准头文件) */
#include <stdio.h>
/* singleton header file 单例模式头文件 */
#include "singleton.h"

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: demo function
 * =================================================================================
 * @return {void}
 */
void demoFunction() {
    /* get singleton */
    Singleton *s = getSingleton();
    printf("Singleton value: %d\n", s->value);
    /* change the value of singleton */
    s->value = 42;
}

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: test 1 function
 * =================================================================================
 * @return {void}
 */
void test_1(void) {
    demoFunction();
    /* call demoFunction() again */
    demoFunction();
    /* free singleton */
    freeSingleton();
}

/**********************************************************************************/
/*                                                                                */
/*                                  MAIN FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: main function 主函数
 * =================================================================================
 * @param {int} argc        程序入参个数
 * @param {char} *argv[]    程序入参字符串数组
 * @return {int}            程序运行状态
 */
int main(int argc, const char *argv[]) {
    test_1();
    return 0;
}