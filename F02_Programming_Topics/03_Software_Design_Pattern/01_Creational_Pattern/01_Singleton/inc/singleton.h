/*
 * @FilePath     : \Practice_LeetCode_C\02_Programming_Topics\03_Software_Design_Pattern\01_Singleton\inc\singleton.h
 * @Author       : Chong Liu
 * @CreateDate   : 2024-01-03 13:08:09
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-03 13:29:28
 * =================================================================================
 * Copyright (c) 2024 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : singleton header file 单例模式头文件
 */
#ifndef __SINGLETON_H
#define __SINGLETON_H

/**********************************************************************************/
/*                                                                                */
/*                               STRUCT DEFINITION                                */
/*                                                                                */
/**********************************************************************************/
typedef struct _singleton {
    int value;
} Singleton;

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
Singleton *getSingleton(void);

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
void freeSingleton(void);

#endif  /* __SINGLETON_H */
