/*
 * @FilePath     : \Practice_LeetCode_C\02_Programming_Topics\03_Software_Design_Pattern\01_Singleton\src\singleton.c
 * @Author       : Chong Liu
 * @CreateDate   : 2024-01-03 13:08:20
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-03 13:27:49
 * =================================================================================
 * Copyright (c) 2024 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : singleton source file 单例模式源文件
 */
/* standard header file (标准头文件) */
#include <stdio.h>
#include <stdlib.h>
/* singleton header file 单例模式头文件 */
#include "singleton.h"

/**********************************************************************************/
/*                                                                                */
/*                                 GLOBAL VARIABLES                               */
/*                                                                                */
/**********************************************************************************/
static Singleton *g_instance = NULL;    /* singleton instance 单例模式实例 */

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: get singleton
 * =================================================================================
 * @return {Singleton *}
 */
Singleton *getSingleton(void) {
    if (g_instance == NULL) {
        g_instance = (Singleton *)malloc(sizeof(Singleton));
        /* initialize the value of singleton */
        g_instance->value = 0;
    }
    return g_instance;
}

/**
 * @description: free singleton
 * =================================================================================
 * @return {void}
 */
void freeSingleton(void) {
    if (g_instance != NULL) {
        free(g_instance);
        g_instance = NULL;
    }
}
