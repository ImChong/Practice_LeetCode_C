/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\ringBuffer.c
 * @Author       : Chong Liu | truegrit rainaftermath@qq.com
 * @CreateDate   : 2023-09-18 22:40:08
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-21 13:52:38
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 环形buffer
 */
#include <stdio.h>
#include <stdint.h>
#include "commonHeader.h"

/* 环形 Buffer 长度 */
#define RING_BUFFER_SIZE                5
/* 程序状态宏 */
#define UNIFORM_ERR                     (-1)
#define UNIFORM_OK                      0
/* 宏函数 */
#define ARR_SIZE(arr)                   (sizeof(arr) / sizeof((arr)[0]))
#define RETURN_ERR_IF(condition)        do { \
                                            if (condition) { \
                                                return UNIFORM_ERR; \
                                            } \
                                        } while (0)

typedef struct {
    uint8_t *pBuff;     /* 环形buffer数组 */
    int16_t buffLen;    /* 环形buffer长度 */
    int16_t dataLen;    /* 环形buffer中数据总长度 */
    int16_t dataIdx;    /* 环形buffer的数据头指针 */
} RingBufferSt;

/* 接收环形Buffer */
uint8_t g_rxBuff[RING_BUFFER_SIZE];
/* 接收环形结构体 */
RingBufferSt g_rxRing;

/**
 * @description: 往环形 buffer 中增加一个字节
 * =================================================================================
 * @param {RingBufferSt} *pRing
 * @param {uint8_t} byte
 * @return {int16_t}
 */
int16_t RingBuffer_AddByte(RingBufferSt *pRing, uint8_t byte)
{
    /* 指针空检验 */
    RETURN_ERR_IF(pRing == NULL);

    /* 环形buffer数据已满 */
    if (pRing->dataLen == pRing->buffLen) {
        return UNIFORM_ERR;
    }

    /* 找到第一个数据的索引号 */
    uint16_t idx = pRing->dataIdx + pRing->dataLen;
    if (idx >= pRing->buffLen) {
        idx -= pRing->buffLen;
    }

    pRing->pBuff[idx] = byte;
    pRing->dataLen++;
    return UNIFORM_OK;
}

/**
 * @description: 从环形 buffer 中取出一个字节
 * =================================================================================
 * @param {RingBufferSt} *pRing
 * @param {uint8_t} *pByte
 * @return {int16_t}
 */
int16_t RingBuffer_GetByte(RingBufferSt *pRing, uint8_t *pByte)
{
    /* 指针空检验 */
    RETURN_ERR_IF(pRing == NULL);
    RETURN_ERR_IF(pByte == NULL);

    /* 环形buffer数据为空 */
    if (pRing->dataLen <= 0) {
        return UNIFORM_ERR;
    }

    /* 取出一个字节 */
    *pByte = pRing->pBuff[pRing->dataIdx];
    pRing->dataIdx++;

    /* 当idx越界时归零 */
    if (pRing->dataIdx == pRing->buffLen) {
        pRing->dataIdx = 0;
    }

    pRing->dataLen--;
    return UNIFORM_OK;
}

/**
 * @description: 打印环形 buffer
 * =================================================================================
 * @param {RingBufferSt} *pRing
 * @return {void}
 */
void RingBuffer_Print(RingBufferSt *pRing)
{
    printf("环形Buffer: ");
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
int16_t RingBuffer_Init(RingBufferSt *pRing, uint8_t *pBuff, int16_t buffLen)
{
    RETURN_ERR_IF(pRing == NULL);
    RETURN_ERR_IF(pBuff == NULL);
    RETURN_ERR_IF(buffLen <= 0);

    pRing->pBuff = pBuff;
    pRing->buffLen = buffLen;
    pRing->dataLen = 0;
    pRing->dataIdx = 0;
    return UNIFORM_OK;
}

/**
 * @description: 测试环形 buffer
 * =================================================================================
 * @param {int} argc        程序入参个数
 * @param {char} *argv[]    程序入参字符串数组
 * @return {int}            程序运行状态
 */
int main(int argc, const char *argv[]) {
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

    printCommandInfo(argc, argv);

    return 0;
}