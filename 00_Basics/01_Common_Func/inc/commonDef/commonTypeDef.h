/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\inc\commonTypeDef.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-22 12:30:36
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-22 12:36:27
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用类型定义头文件
 */
#ifndef __COMMON_TYPE_DEF_H
#define __COMMON_TYPE_DEF_H

/**********************************************************************************/
/*                                                                                */
/*                                MACRO CONSTANTS                                 */
/*                                                                                */
/**********************************************************************************/
/* 程序状态宏 */
#define COMMON_ERR              (-1)
#define COMMON_OK               0

/* 程序判断宏 */
#define COMMON_TRUE             1
#define COMMON_FALSE            0

/* 程序调试宏 */
#define STATIC                  static
#define STATIC_FUNC             static
#define INLINE                  inline
#define INLINE_FUNC             inline

/* 数据类型宏 */
typedef signed char             int8_t;
typedef unsigned char           uint8_t;
typedef short                   int16_t;
typedef unsigned short          uint16_t;
typedef int                     int32_t;
typedef unsigned                uint32_t;
typedef long long               int64_t;
typedef unsigned long long      uint64_t;

/**********************************************************************************/
/*                                                                                */
/*                                MACRO FUNCTIONS                                 */
/*                                                                                */
/**********************************************************************************/
/* 声明了一个变量或函数,但不确定后面是否会使用它时,可以加上这个宏 */
#define MAYBE_UNUSED            attribute((unused))

/* 返回错误码 */
#define RETURN_ERR_IF(condition)        do { \
                                            if (condition) { \
                                                return COMMON_ERR; \
                                            } \
                                        } while (0)

#endif  /* __COMMON_TYPE_DEF_H */
