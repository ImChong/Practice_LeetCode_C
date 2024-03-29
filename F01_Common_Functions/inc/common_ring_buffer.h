/*
 * @FilePath     : \Practice_LeetCode_C\F01_Common_Functions\inc\common_ring_buffer.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 14:22:20
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-27 12:01:47
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
    uint8_t *p_buff;  /* Ring buffer array */
    int16_t buff_len; /* Ring buffer length */
    int16_t data_len; /* Ring buffer data length */
    int16_t data_idx; /* Ring buffer data index */
} RingBuffer;

/**********************************************************************************/
/*                                                                                */
/*                                 UTILITY FUNCTIONS                              */
/*                                                                                */
/**********************************************************************************/
int16_t RingBuffer_Init(RingBuffer *p_ring, uint8_t *p_buff, int16_t buff_len); /* Initialize a ring buffer */
int16_t RingBuffer_AddByte(RingBuffer *p_ring, uint8_t byte);   /* Add a byte to the ring buffer */
int16_t RingBuffer_GetByte(RingBuffer *p_ring, uint8_t *p_byte); /* Get a byte from the ring buffer */

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
void RingBuffer_Print(RingBuffer *p_ring); /* Print ring buffer */
void RingBuffer_Free(RingBuffer *p_ring);  /* Free ring buffer */

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
void Validate_RingBuffer(void); /* Validate ring buffer */

#endif /* F01_COMMON_FUNCTIONS_INC_COMMON_RING_BUFFER_H_ */
