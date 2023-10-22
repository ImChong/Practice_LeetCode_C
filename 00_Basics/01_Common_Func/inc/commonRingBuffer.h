/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\inc\commonRingBuffer.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 14:22:20
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-22 12:25:52
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用环形缓冲区头文件
 */
#ifndef __COMMON_RING_BUFFER_H
#define __COMMON_RING_BUFFER_H

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
int16_t RingBuffer_AddByte(RingBufferSt *pRing, uint8_t byte);
int16_t RingBuffer_GetByte(RingBufferSt *pRing, uint8_t *pByte);
void RingBuffer_Print(RingBufferSt *pRing);
int16_t RingBuffer_Init(RingBufferSt *pRing, uint8_t *pBuff, int16_t buffLen);

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
void Test_RingBuffer(void);


#endif  /* __COMMON_RING_BUFFER_H */