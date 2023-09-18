/*
 * @Author: truegrit rainaftermath@qq.com
 * @Date: 2023-09-17
 * @Description: 环形buffer
 */

#include "ring_buffer.h"
#include "base_type_def.h"

/* 环形Buffer长度 */
#define RING_BUFFER_SIZE 5

/* 接收环形Buffer */
uint8_t g_rxBuff[RING_BUFFER_SIZE];
/* 接收环形结构体 */
RingBufferSt g_rxRing;

/****************************************************************************
 * Function: RingBuffer_AddByte
 * Descrip : 往环形buffer中增加一个字节
 * Author  : liujia
 * Date    : 2023.9.17
 ***************************************************************************/
int16_t RingBuffer_AddByte(RingBufferSt* pRing, uint8_t byte)
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

/****************************************************************************
 * Function: RingBuffer_GetByte
 * Descrip : 从环形buffer中取出一个字节
 * Author  : liujia
 * Date    : 2023.9.17
 ***************************************************************************/
int16_t RingBuffer_GetByte(RingBufferSt *pRing, uint8_t* pByte)
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

/****************************************************************************
 * Function: RingBuffer_Print
 * Descrip : 打印环形buffer
 * Author  : liujia
 * Date    : 2023.9.17
 ***************************************************************************/
int16_t RingBuffer_Print(RingBufferSt *pRing)
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

/****************************************************************************
 * Function: RingBuffer_Init
 * Descrip : 环形buffer初始化
 * Author  : liujia
 * Date    : 2023.9.17
 ***************************************************************************/
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

/****************************************************************************
 * Function: RingBuffer_Test
 * Descrip : 测试环形buffer
 * Author  : liujia
 * Date    : 2023.9.17
 ***************************************************************************/
void RingBuffer_Test(void)
{
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