/*
 * @FilePath     : \Practice_LeetCode_C\F01_Common_Functions\inc\commonRingBuffer.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 14:22:20
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-17 10:33:28
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : common ring buffer header file
 */
#ifndef F01_COMMON_FUNCTIONS_INC_COMMONRINGBUFFER_H_
#define F01_COMMON_FUNCTIONS_INC_COMMONRINGBUFFER_H_

/* Standard header file (标准头文件) */
#include <stdint.h>

/**********************************************************************************/
/*                                                                                */
/*                                STRUCT DEFINITION                               */
/*                                                                                */
/**********************************************************************************/
typedef struct {
    uint8_t *pBuff;  /* 环形buffer数组 */
    int16_t buffLen; /* 环形buffer长度 */
    int16_t dataLen; /* 环形buffer中数据总长度 */
    int16_t dataIdx; /* 环形buffer的数据头指针 */
} RingBuffer;

/**********************************************************************************/
/*                                                                                */
/*                                 UTILITY FUNCTIONS                              */
/*                                                                                */
/**********************************************************************************/
int16_t RingBuffer_Init(RingBuffer *pRing, uint8_t *pBuff, int16_t buffLen); /* 初始化环形buffer */
int16_t RingBuffer_AddByte(RingBuffer *pRing, uint8_t byte);   /* 向环形buffer中添加一个字节 */
int16_t RingBuffer_GetByte(RingBuffer *pRing, uint8_t *pByte); /* 从环形buffer中取出一个字节 */

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
void RingBuffer_Print(RingBuffer *pRing); /* 打印环形buffer中的数据 */
void RingBuffer_Free(RingBuffer *pRing);  /* 释放环形buffer */

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
void Validate_RingBuffer(void);

#endif /* F01_COMMON_FUNCTIONS_INC_COMMONRINGBUFFER_H_ */
