/*
 * @Author: truegrit rainaftermath@qq.com
 * @Date: 2023-09-17
 * @Description: 环形buffer头文件
 */
#ifndef _RING_BUFFER_H_
#define _RING_BUFFER_H_

#include "stdint.h"

typedef struct {
    uint8_t *pBuff;     /* 环形buffer数组 */
    int16_t buffLen;    /* 环形buffer长度 */
    int16_t dataLen;    /* 环形buffer中数据总长度 */
    int16_t dataIdx;    /* 环形buffer的数据头指针 */
} RingBufferSt;

int16_t RingBuffer_AddByte(RingBufferSt* pRing, uint8_t byte);
int16_t RingBuffer_GetByte(RingBufferSt *pRing, uint8_t* pByte);
int16_t RingBuffer_Print(RingBufferSt *pRing);
int16_t RingBuffer_Init(RingBufferSt *pRing, uint8_t *pBuff, int16_t buffLen);
void RingBuffer_Test(void);
#endif
