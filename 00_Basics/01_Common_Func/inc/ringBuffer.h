/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\inc\ringBuffer.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 14:22:20
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-21 14:35:31
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 环形buffer
 */
#ifndef __RINGBUFFER_H__
#define __RINGBUFFER_H__

#include <stdint.h>

/**********************************************************************************/
/*                                                                                */
/*                                MACRO CONSTANTS                                 */
/*                                                                                */
/**********************************************************************************/
/* 环形 Buffer 长度 */
#define RING_BUFFER_SIZE        5

/**********************************************************************************/
/*                                                                                */
/*                                 GLOBAL VARIABLES                               */
/*                                                                                */
/**********************************************************************************/
typedef struct {
    uint8_t *pBuff;     /* 环形buffer数组 */
    int16_t buffLen;    /* 环形buffer长度 */
    int16_t dataLen;    /* 环形buffer中数据总长度 */
    int16_t dataIdx;    /* 环形buffer的数据头指针 */
} RingBufferSt;

#endif  /* __RINGBUFFER_H__ */