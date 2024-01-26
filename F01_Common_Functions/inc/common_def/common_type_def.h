/*
 * @FilePath     : \Practice_LeetCode_C\F01_Common_Functions\inc\commonDef\common_type_def.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-22 12:30:36
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-23 00:05:03
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : Common type definition header file
 */
#ifndef F01_COMMON_FUNCTIONS_INC_COMMON_DEF_COMMON_TYPE_DEF_H_
#define F01_COMMON_FUNCTIONS_INC_COMMON_DEF_COMMON_TYPE_DEF_H_

/**********************************************************************************/
/*                                                                                */
/*                                MACRO CONSTANTS                                 */
/*                                                                                */
/**********************************************************************************/
/* Program status macro */
#define COMMON_ERR (-1)
#define COMMON_OK 0
#define COMMON_TRUE 1
#define COMMON_FALSE 0

/* Variable type macro */
#define STATIC static
#define STATIC_FUNC static
#define INLINE inline
#define INLINE_FUNC inline

/**********************************************************************************/
/*                                                                                */
/*                                MACRO FUNCTIONS                                 */
/*                                                                                */
/**********************************************************************************/
/* Define unused variable */
#define MAYBE_UNUSED attribute((unused))

/* Return error if condition is true */
#define RETURN_ERR_IF(condition) \
    do {                         \
        if (condition) {         \
            return COMMON_ERR;   \
        }                        \
    } while (0)

#endif /* F01_COMMON_FUNCTIONS_INC_COMMON_DEF_COMMON_TYPE_DEF_H_ */
