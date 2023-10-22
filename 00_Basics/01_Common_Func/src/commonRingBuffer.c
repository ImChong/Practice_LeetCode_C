/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\src\commonRingBuffer.c
 * @Author       : Chong Liu | truegrit rainaftermath@qq.com
 * @CreateDate   : 2023-09-18 22:40:08
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-22 12:42:22
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用环形缓冲区源文件
 */
#include <stdio.h>
#include <stdint.h>
#include "commonTypeDef.h"
#include "commonArray.h"
#include "commonRingBuffer.h"

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
uint8_t g_rxBuff[RING_BUFFER_SIZE];     /* 接收环形Buffer */
RingBufferSt g_rxRing;                  /* 接收环形结构体 */

/**********************************************************************************/
/*                                                                                */
/*                                 UTILITY FUNCTIONS                              */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 往环形 buffer 中增加一个字节
 * =================================================================================
 * @param {RingBufferSt} *pRing
 * @param {uint8_t} byte
 * @return {int16_t}
 */
int16_t RingBuffer_AddByte(RingBufferSt *pRing, uint8_t byte) {
    /* 指针空检验 */
    RETURN_ERR_IF(pRing == NULL);

    /* 环形buffer数据已满 */
    if (pRing->dataLen == pRing->buffLen) {
        return COMMON_ERR;
    }

    /* 找到第一个数据的索引号 */
    uint16_t idx = pRing->dataIdx + pRing->dataLen;
    if (idx >= pRing->buffLen) {
        idx -= pRing->buffLen;
    }

    pRing->pBuff[idx] = byte;
    pRing->dataLen++;
    return COMMON_OK;
}

/**
 * @description: 从环形 buffer 中取出一个字节
 * =================================================================================
 * @param {RingBufferSt} *pRing
 * @param {uint8_t} *pByte
 * @return {int16_t}
 */
int16_t RingBuffer_GetByte(RingBufferSt *pRing, uint8_t *pByte) {
    /* 指针空检验 */
    RETURN_ERR_IF(pRing == NULL);
    RETURN_ERR_IF(pByte == NULL);

    /* 环形buffer数据为空 */
    if (pRing->dataLen <= 0) {
        return COMMON_ERR;
    }

    /* 取出一个字节 */
    *pByte = pRing->pBuff[pRing->dataIdx];
    pRing->dataIdx++;

    /* 当idx越界时归零 */
    if (pRing->dataIdx == pRing->buffLen) {
        pRing->dataIdx = 0;
    }

    pRing->dataLen--;
    return COMMON_OK;
}

/**
 * @description: 打印环形 buffer
 * =================================================================================
 * @param {RingBufferSt} *pRing
 * @return {void}
 */
void RingBuffer_Print(RingBufferSt *pRing) {
    printf("Ring Buffer: ");
    for (int16_t i = 0; i < pRing->dataLen; ++i) {
        int16_t idx = (pRing->dataIdx + i) % pRing->buffLen;
        printf("%d -> ", pRing->pBuff[idx]);
    }
    printf("NULL\n");

//    printf("环形Buffer: ");
//    for (int16_t i = 0; i < pRing->buffLen; ++i) {
//        printf("%d -> ", pRing->pBuff[i]);
//    }
//    printf("NULL\n");
}

/**
 * @description: 环形 buffer 初始化
 * =================================================================================
 * @param {RingBufferSt} *pRing
 * @param {uint8_t} *pBuff
 * @param {int16_t} buffLen
 * @return {int16_t}
 */
int16_t RingBuffer_Init(RingBufferSt *pRing, uint8_t *pBuff, int16_t buffLen) {
    RETURN_ERR_IF(pRing == NULL);
    RETURN_ERR_IF(pBuff == NULL);
    RETURN_ERR_IF(buffLen <= 0);

    pRing->pBuff = pBuff;
    pRing->buffLen = buffLen;
    pRing->dataLen = 0;
    pRing->dataIdx = 0;
    return COMMON_OK;
}

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 测试环形 buffer
 * =================================================================================
 * @return {void}
 */
void Test_RingBuffer(void) {
    // 初始化
    RingBuffer_Init(&g_rxRing, g_rxBuff, ARR_SIZE(g_rxBuff));
    RingBuffer_Print(&g_rxRing);

    // 入队
    RingBuffer_AddByte(&g_rxRing, 1);
    RingBuffer_AddByte(&g_rxRing, 2);
    RingBuffer_AddByte(&g_rxRing, 3);
    RingBuffer_AddByte(&g_rxRing, 4);
    RingBuffer_AddByte(&g_rxRing, 5);
    RingBuffer_AddByte(&g_rxRing, 6); // 只能存放5个数据
    RingBuffer_Print(&g_rxRing);

    // 出队
    uint8_t data;
    RingBuffer_GetByte(&g_rxRing, &data);
    RingBuffer_GetByte(&g_rxRing, &data);
    RingBuffer_GetByte(&g_rxRing, &data);
    RingBuffer_Print(&g_rxRing);

    // 再入队
    RingBuffer_AddByte(&g_rxRing, 7);
    RingBuffer_AddByte(&g_rxRing, 8);
    RingBuffer_AddByte(&g_rxRing, 9);
    RingBuffer_Print(&g_rxRing);

    // 再出队
    RingBuffer_GetByte(&g_rxRing, &data);
    RingBuffer_GetByte(&g_rxRing, &data);
    RingBuffer_Print(&g_rxRing);
}
