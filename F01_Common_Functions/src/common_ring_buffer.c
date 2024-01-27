/*
 * @FilePath     : \Practice_LeetCode_C\F01_Common_Functions\src\common_ring_buffer.c
 * @Author       : Chong Liu | truegrit rainaftermath@qq.com
 * @CreateDate   : 2023-09-18 22:40:08
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-27 11:15:30
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用环形缓冲区源文件
 */
/* Common function configuration file (通用函数配置文件) */
#include "compile_cfg.h"        /* NOLINT */
#if COMMON_RING_BUFFER_EN /* whether compile this file, the definition of this macro can be found in compileCfg.h */
/* Header file (本文件头文件) */
#include "F01_Common_Functions/inc/common_ring_buffer.h"
/* Standard header file (标准头文件) */
#include <stdio.h>
#include <stdint.h>
/* Common function header file (通用头文件) */
#include "F01_Common_Functions/inc/common_def/common_type_def.h"
#include "F01_Common_Functions/inc/common_array.h"

/* TODO: refactor needed 重构 */

/**********************************************************************************/
/*                                                                                */
/*                                MACRO CONSTANTS                                 */
/*                                                                                */
/**********************************************************************************/
#define RING_BUFFER_SIZE        5       /* 环形 Buffer 长度 */

/**********************************************************************************/
/*                                                                                */
/*                                 GLOBAL VARIABLES                               */
/*                                                                                */
/**********************************************************************************/
uint8_t g_rxBuff[RING_BUFFER_SIZE];     /* 接收环形Buffer */
RingBuffer g_rxRing;                  /* 接收环形结构体 */

/**********************************************************************************/
/*                                                                                */
/*                                 UTILITY FUNCTIONS                              */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 往环形 buffer 中增加一个字节
 * =================================================================================
 * @param {RingBuffer} *pRing
 * @param {uint8_t} byte
 * @return {int16_t}
 */
int16_t RingBuffer_AddByte(RingBuffer *pRing, uint8_t byte) {
    /* 指针空检验 */
    RETURN_ERR_IF(pRing == NULL);

    /* 环形buffer数据已满 */
    if (pRing->dataLen == pRing->buff_len) {
        return COMMON_ERR;
    }

    /* 找到第一个数据的索引号 */
    uint16_t idx = pRing->dataIdx + pRing->dataLen;
    if (idx >= pRing->buff_len) {
        idx -= pRing->buff_len;
    }

    pRing->pBuff[idx] = byte;
    pRing->dataLen++;
    return COMMON_OK;
}

/**
 * @description: 从环形 buffer 中取出一个字节
 * =================================================================================
 * @param {RingBuffer} *pRing
 * @param {uint8_t} *pByte
 * @return {int16_t}
 */
int16_t RingBuffer_GetByte(RingBuffer *pRing, uint8_t *pByte) {
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
    if (pRing->dataIdx == pRing->buff_len) {
        pRing->dataIdx = 0;
    }

    pRing->dataLen--;
    return COMMON_OK;
}

/**
 * @description: 打印环形 buffer
 * =================================================================================
 * @param {RingBuffer} *pRing
 * @return {void}
 */
void RingBuffer_Print(RingBuffer *pRing) {
    printf("Ring Buffer: ");
    for (int16_t i = 0; i < pRing->dataLen; ++i) {
        int16_t idx = (pRing->dataIdx + i) % pRing->buff_len;
        printf("%d -> ", pRing->pBuff[idx]);
    }
    printf("NULL\n");

//    printf("环形Buffer: ");
//    for (int16_t i = 0; i < pRing->buff_len; ++i) {
//        printf("%d -> ", pRing->pBuff[i]);
//    }
//    printf("NULL\n");
}

/**
 * @description: 环形 buffer 初始化
 * =================================================================================
 * @param {RingBuffer} *pRing
 * @param {uint8_t} *p_buff
 * @param {int16_t} buff_len
 * @return {int16_t}
 */
int16_t RingBuffer_Init(RingBuffer *pRing, uint8_t *p_buff, int16_t buff_len) {
    RETURN_ERR_IF(pRing == NULL);
    RETURN_ERR_IF(pBuff == NULL);
    RETURN_ERR_IF(buff_len <= 0);

    pRing->pBuff = pBuff;
    pRing->buff_len = buff_len;
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
void Validate_RingBuffer(void) {
    // 初始化
    RingBuffer_Init(&g_rxRing, g_rxBuff, ARR_SIZE(g_rxBuff));
    RingBuffer_Print(&g_rxRing);

    // 入队
    RingBuffer_AddByte(&g_rxRing, 1);
    RingBuffer_AddByte(&g_rxRing, 2);
    RingBuffer_AddByte(&g_rxRing, 3);
    RingBuffer_AddByte(&g_rxRing, 4);
    RingBuffer_AddByte(&g_rxRing, 5);
    RingBuffer_AddByte(&g_rxRing, 6);       // 只能存放5个数据
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


#endif      /* COMMON_RING_BUFFER_EN */
