/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\inc\commonRingBuffer.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 14:22:20
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-06 10:40:33
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用环形缓冲区头文件
 */
#ifndef __COMMON_RING_BUFFER_H      /* NOLINT(build/header_guard) */
#define __COMMON_RING_BUFFER_H      /* NOLINT(build/header_guard) */

/* 标准头文件 */
#include <stdint.h>

/**********************************************************************************/
/*                                                                                */
/*                                STRUCT DEFINITION                               */
/*                                                                                */
/**********************************************************************************/
typedef struct {
    uint8_t *pBuff;     /* 环形buffer数组 */
    int16_t buffLen;    /* 环形buffer长度 */
    int16_t dataLen;    /* 环形buffer中数据总长度 */
    int16_t dataIdx;    /* 环形buffer的数据头指针 */
} RingBufferSt;

/**********************************************************************************/
/*                                                                                */
/*                                 UTILITY FUNCTIONS                              */
/*                                                                                */
/**********************************************************************************/
int16_t RingBuffer_AddByte(RingBufferSt *pRing, uint8_t byte);      /* 向环形buffer中添加一个字节 */
int16_t RingBuffer_GetByte(RingBufferSt *pRing, uint8_t *pByte);        /* 从环形buffer中取出一个字节 */
void RingBuffer_Print(RingBufferSt *pRing);     /* 打印环形buffer中的数据 */
int16_t RingBuffer_Init(RingBufferSt *pRing, uint8_t *pBuff, int16_t buffLen);      /* 初始化环形buffer */

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
void Test_RingBuffer(void);


#endif  /* __COMMON_RING_BUFFER_H */        /* NOLINT(build/header_guard) */