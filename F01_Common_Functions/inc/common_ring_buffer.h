/*
 * @FilePath     : \Practice_LeetCode_C\F01_Common_Functions\inc\commonRingBuffer.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 14:22:20
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-18 23:14:08
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : common ring buffer header file
 */
#ifndef F01_COMMON_FUNCTIONS_INC_COMMON_RING_BUFFER_H_
#define F01_COMMON_FUNCTIONS_INC_COMMON_RING_BUFFER_H_

/* Standard header file (标准头文件) */
#include <stdint.h>

/**********************************************************************************/
/*                                                                                */
/*                                STRUCT DEFINITION                               */
/*                                                                                */
/**********************************************************************************/
typedef struct {
    uint8_t *pBuff;  /* Ring buffer array */
    int16_t buffLen; /* Ring buffer length */
    int16_t dataLen; /* Ring buffer data length */
    int16_t dataIdx; /* Ring buffer data index */
} RingBuffer;

/**********************************************************************************/
/*                                                                                */
/*                                 UTILITY FUNCTIONS                              */
/*                                                                                */
/**********************************************************************************/
int16_t RingBuffer_Init(RingBuffer *pRing, uint8_t *pBuff, int16_t buffLen); /* Initialize a ring buffer */
int16_t RingBuffer_AddByte(RingBuffer *pRing, uint8_t byte);   /* Add a byte to the ring buffer */
int16_t RingBuffer_GetByte(RingBuffer *pRing, uint8_t *pByte); /* Get a byte from the ring buffer */

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
void RingBuffer_Print(RingBuffer *pRing); /* Print ring buffer */
void RingBuffer_Free(RingBuffer *pRing);  /* Free ring buffer */

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
void Validate_RingBuffer(void); /* Validate ring buffer */

#endif /* F01_COMMON_FUNCTIONS_INC_COMMON_RING_BUFFER_H_ */
