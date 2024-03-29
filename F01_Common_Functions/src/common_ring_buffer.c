/*
 * @FilePath     : \Practice_LeetCode_C\F01_Common_Functions\src\common_ring_buffer.c
 * @Author       : Chong Liu | truegrit rainaftermath@qq.com
 * @CreateDate   : 2023-09-18 22:40:08
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-27 14:21:18
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
uint8_t g_rx_buffer[RING_BUFFER_SIZE];     /* 接收环形Buffer */
RingBuffer g_rx_ring_buffer;                  /* 接收环形结构体 */

/**********************************************************************************/
/*                                                                                */
/*                                 UTILITY FUNCTIONS                              */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 往环形 buffer 中增加一个字节
 * =================================================================================
 * @param {RingBuffer} *p_ring
 * @param {uint8_t} byte
 * @return {int16_t}
 */
int16_t RingBuffer_AddByte(RingBuffer *p_ring, uint8_t byte) {
    /* 指针空检验 */
    RETURN_ERR_IF(p_ring == NULL);

    /* 环形buffer数据已满 */
    if (p_ring->data_len == p_ring->buff_len) {
        return COMMON_ERR;
    }

    /* 找到第一个数据的索引号 */
    uint16_t idx = p_ring->data_idx + p_ring->data_len;
    if (idx >= p_ring->buff_len) {
        idx -= p_ring->buff_len;
    }

    p_ring->p_buff[idx] = byte;
    p_ring->data_len++;
    return COMMON_OK;
}

/**
 * @description: 从环形 buffer 中取出一个字节
 * =================================================================================
 * @param {RingBuffer} *p_ring
 * @param {uint8_t} *p_byte
 * @return {int16_t}
 */
int16_t RingBuffer_GetByte(RingBuffer *p_ring, uint8_t *p_byte) {
    /* 指针空检验 */
    RETURN_ERR_IF(p_ring == NULL);
    RETURN_ERR_IF(p_byte == NULL);

    /* 环形buffer数据为空 */
    if (p_ring->data_len <= 0) {
        return COMMON_ERR;
    }

    /* 取出一个字节 */
    *p_byte = p_ring->p_buff[p_ring->data_idx];
    p_ring->data_idx++;

    /* 当idx越界时归零 */
    if (p_ring->data_idx == p_ring->buff_len) {
        p_ring->data_idx = 0;
    }

    p_ring->data_len--;
    return COMMON_OK;
}

/**
 * @description: 打印环形 buffer
 * =================================================================================
 * @param {RingBuffer} *p_ring
 * @return {void}
 */
void RingBuffer_Print(RingBuffer *p_ring) {
    printf("Ring Buffer: ");
    for (int16_t i = 0; i < p_ring->data_len; ++i) {
        int16_t idx = (p_ring->data_idx + i) % p_ring->buff_len;
        printf("%d -> ", p_ring->p_buff[idx]);
    }
    printf("NULL\n");
}

/**
 * @description: 环形 buffer 初始化
 * =================================================================================
 * @param {RingBuffer} *p_ring
 * @param {uint8_t} *p_buff
 * @param {int16_t} buff_len
 * @return {int16_t}
 */
int16_t RingBuffer_Init(RingBuffer *p_ring, uint8_t *p_buff, int16_t buff_len) {
    RETURN_ERR_IF(p_ring == NULL);
    RETURN_ERR_IF(p_buff == NULL);
    RETURN_ERR_IF(buff_len <= 0);

    p_ring->p_buff = p_buff;
    p_ring->buff_len = buff_len;
    p_ring->data_len = 0;
    p_ring->data_idx = 0;
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
    RingBuffer_Init(&g_rx_ring_buffer, g_rx_buffer, ARR_SIZE(g_rx_buffer));
    RingBuffer_Print(&g_rx_ring_buffer);

    // 入队
    RingBuffer_AddByte(&g_rx_ring_buffer, 1);
    RingBuffer_AddByte(&g_rx_ring_buffer, 2);
    RingBuffer_AddByte(&g_rx_ring_buffer, 3);
    RingBuffer_AddByte(&g_rx_ring_buffer, 4);
    RingBuffer_AddByte(&g_rx_ring_buffer, 5);
    RingBuffer_AddByte(&g_rx_ring_buffer, 6);       // 只能存放5个数据
    RingBuffer_Print(&g_rx_ring_buffer);

    // 出队
    uint8_t data;
    RingBuffer_GetByte(&g_rx_ring_buffer, &data);
    RingBuffer_GetByte(&g_rx_ring_buffer, &data);
    RingBuffer_GetByte(&g_rx_ring_buffer, &data);
    RingBuffer_Print(&g_rx_ring_buffer);

    // 再入队
    RingBuffer_AddByte(&g_rx_ring_buffer, 7);
    RingBuffer_AddByte(&g_rx_ring_buffer, 8);
    RingBuffer_AddByte(&g_rx_ring_buffer, 9);
    RingBuffer_Print(&g_rx_ring_buffer);

    // 再出队
    RingBuffer_GetByte(&g_rx_ring_buffer, &data);
    RingBuffer_GetByte(&g_rx_ring_buffer, &data);
    RingBuffer_Print(&g_rx_ring_buffer);
}


#endif      /* COMMON_RING_BUFFER_EN */
