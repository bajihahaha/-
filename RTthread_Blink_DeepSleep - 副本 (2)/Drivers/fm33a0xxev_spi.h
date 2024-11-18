/**
  ******************************************************************************
  * @file    fm33a0xxev_spi.h
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file contains all the functions prototypes for the SPI firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33A0XXEV_SPI_H
#define __FM33A0XXEV_SPI_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33A0XXEV.h" 
   
//------------------------------------------------------------------------------
     
#define	SPIx_CR1_IOSWAP_Pos	11	/* MOSI��MISO���Ž��� (IO swapping)
0��Ĭ������˳��
1����������˳�� */
#define	SPIx_CR1_IOSWAP_Msk	(0x1U << SPIx_CR1_IOSWAP_Pos)
#define	SPIx_CR1_IOSWAP_DEFAULT	(0x0U << SPIx_CR1_IOSWAP_Pos)	/* Ĭ������˳�� */
#define	SPIx_CR1_IOSWAP_EXCHANGE	(0x1U << SPIx_CR1_IOSWAP_Pos)	/* ��������˳�� */

#define	SPIx_CR1_MSPA_Pos	10	/* Master Sampling Position Adjustment��Master��MISO�źŵĲ���λ�õ��������ڸ���ͨ��ʱ����PCB�����ӳ�
1���������ӳٰ��SCK����
0�������� */
#define	SPIx_CR1_MSPA_Msk	(0x1U << SPIx_CR1_MSPA_Pos)
#define	SPIx_CR1_MSPA_DELAY	(0x1U << SPIx_CR1_MSPA_Pos)	/* �������ӳٰ��SCK���� */
#define	SPIx_CR1_MSPA_NORMAL	(0x0U << SPIx_CR1_MSPA_Pos)	/* ������ */

#define	SPIx_CR1_SSPA_Pos	9	/* Slave Sending Position Adjustment��Slave MISO����λ�õ���
1����ǰ���SCK���ڷ���
0�������� */
#define	SPIx_CR1_SSPA_Msk	(0x1U << SPIx_CR1_SSPA_Pos)
#define	SPIx_CR1_SSPA_EARLY	(0x1U << SPIx_CR1_SSPA_Pos)	/* ��ǰ���SCK���ڷ��� */
#define	SPIx_CR1_SSPA_NORMAL	(0x0U << SPIx_CR1_SSPA_Pos)	/* ������ */

#define	SPIx_CR1_MM_Pos	8	/* Master/Slaveģʽѡ��(Master Mode)1��Masterģʽ0��Slaveģʽ */
#define	SPIx_CR1_MM_Msk	(0x1U << SPIx_CR1_MM_Pos)
#define	SPIx_CR1_MM_MASTER	(0x1U << SPIx_CR1_MM_Pos)
#define	SPIx_CR1_MM_SLAVE	(0x0U << SPIx_CR1_MM_Pos)

#define	SPIx_CR1_WAIT_Pos	6	/* Masterģʽ�£�ÿ������һ֡���������(1+WAIT)��SCK cycle�ȴ�ʱ�䣬�ٴ�����һ֡�����ݡ����SSN��Ӳ�����ƣ�����SSNM=1����Ӳ�����Զ�����SSN�� */
#define	SPIx_CR1_WAIT_Msk	(0x3U << SPIx_CR1_WAIT_Pos)
#define	SPIx_CR1_WAIT_1WAIT	(0x0U << SPIx_CR1_WAIT_Pos)
#define	SPIx_CR1_WAIT_2WAIT	(0x1U << SPIx_CR1_WAIT_Pos)
#define	SPIx_CR1_WAIT_3WAIT	(0x2U << SPIx_CR1_WAIT_Pos)
#define	SPIx_CR1_WAIT_4WAIT	(0x3U << SPIx_CR1_WAIT_Pos)

#define	SPIx_CR1_BAUD_Pos	3	/* Masterģʽ����������λ: (Baud rate)000�� fAPBCLK/2001�� fAPBCLK/4010�� fAPBCLK/8011�� fAPBCLK/16100�� fAPBCLK/32101�� fAPBCLK/64110�� fAPBCLK/128111�� fAPBCLK/256��ͨ�����ڽ��е�ʱ�򣬲����޸���Щλ�� */
#define	SPIx_CR1_BAUD_Msk	(0x7U << SPIx_CR1_BAUD_Pos)
#define	SPIx_CR1_BAUD_DIV2	(0x0U << SPIx_CR1_BAUD_Pos)
#define	SPIx_CR1_BAUD_DIV4	(0x1U << SPIx_CR1_BAUD_Pos)
#define	SPIx_CR1_BAUD_DIV8	(0x2U << SPIx_CR1_BAUD_Pos)
#define	SPIx_CR1_BAUD_DIV16	(0x3U << SPIx_CR1_BAUD_Pos)
#define	SPIx_CR1_BAUD_DIV32	(0x4U << SPIx_CR1_BAUD_Pos)
#define	SPIx_CR1_BAUD_DIV64	(0x5U << SPIx_CR1_BAUD_Pos)
#define	SPIx_CR1_BAUD_DIV128	(0x6U << SPIx_CR1_BAUD_Pos)
#define	SPIx_CR1_BAUD_DIV256	(0x7U << SPIx_CR1_BAUD_Pos)

#define	SPIx_CR1_LSBF_Pos	2	/* ֡��ʽ (LSB First) 0���ȷ���MSB1���ȷ���LSBע����ͨ���ڽ���ʱ���ܸı��λ��ֵ�� */
#define	SPIx_CR1_LSBF_Msk	(0x1U << SPIx_CR1_LSBF_Pos)
#define	SPIx_CR1_LSBF_MSB	(0x0U << SPIx_CR1_LSBF_Pos)
#define	SPIx_CR1_LSBF_LSB	(0x1U << SPIx_CR1_LSBF_Pos)

#define	SPIx_CR1_CPHOL_Pos	1
#define	SPIx_CR1_CPHOL_Msk	(0x1U << SPIx_CR1_CPHOL_Pos)
#define	SPIx_CR1_CPHOL_LOW	(0x0U << SPIx_CR1_CPHOL_Pos)
#define	SPIx_CR1_CPHOL_HIGH	(0x1U << SPIx_CR1_CPHOL_Pos)

#define	SPIx_CR1_CPHA_Pos	0	/* ʱ����λѡ�� (Clock Phase)1���ڶ���ʱ�ӱ����ǵ�һ����׽����0����һ��ʱ�ӱ����ǵ�һ����׽����ע����ͨ���ڽ���ʱ���ܸı��λ��ֵ�� */
#define	SPIx_CR1_CPHA_Msk	(0x1U << SPIx_CR1_CPHA_Pos)
#define	SPIx_CR1_CPHA_1CLOCK	(0x0U << SPIx_CR1_CPHA_Pos)
#define	SPIx_CR1_CPHA_2CLOCK	(0x1U << SPIx_CR1_CPHA_Pos)

#define	SPIx_CR2_DUMMY_EN_Pos	15	/* 4�߰�˫��Э�����Ƿ��ڶ������в���dummy cycle
(Dummy cycle Enable)
0��������dummy cycle
1���ڶ�����֮�����һ��dummy cycle */
#define	SPIx_CR2_DUMMY_EN_Msk	(0x1U << SPIx_CR2_DUMMY_EN_Pos)
	/* ������dummy cycle */
	/* �ڶ�����֮�����һ��dummy cycle */

#define	SPIx_CR2_RXO_Pos	11	/* RXONLY����λ���˼Ĵ�����λʱ��SPI�����������գ��������дTXBUF (Receive Only mode)
1������Master�ĵ�����ģʽ
0���رյ�����ģʽ���շ�ȫ˫���� */
#define	SPIx_CR2_RXO_Msk	(0x1U << SPIx_CR2_RXO_Pos)
	/* ����Master�ĵ�����ģʽ */
	/* �رյ�����ģʽ���շ�ȫ˫���� */

#define	SPIx_CR2_DLEN_Pos	9	/* ͨ�������ֳ����� (Data Length)
00��8bit
01��16bit
10��24bit
11��32bit */
#define	SPIx_CR2_DLEN_Msk	(0x3U << SPIx_CR2_DLEN_Pos)
#define	SPIx_CR2_DLEN_8BIT	(0x0U << SPIx_CR2_DLEN_Pos)	/* 8bit */
#define	SPIx_CR2_DLEN_16BIT	(0x1U << SPIx_CR2_DLEN_Pos)	/* 16bit */
#define	SPIx_CR2_DLEN_24BIT	(0x2U << SPIx_CR2_DLEN_Pos)	/* 24bit */
#define	SPIx_CR2_DLEN_32BIT	(0x3U << SPIx_CR2_DLEN_Pos)	/* 32bit */

#define	SPIx_CR2_HALFDUPLEX_Pos	8	/* ͨ��ģʽѡ�� (Half-Duplex mode)
0����׼SPIģʽ��4��ȫ˫��
1��DCNģʽ��4�߰�˫�� */
#define	SPIx_CR2_HALFDUPLEX_Msk	(0x1U << SPIx_CR2_HALFDUPLEX_Pos)
#define	SPIx_CR2_HALFDUPLEX_SPI	(0x0U << SPIx_CR2_HALFDUPLEX_Pos)	/* ��׼SPIģʽ��4��ȫ˫�� */
#define	SPIx_CR2_HALFDUPLEX_DCN	(0x1U << SPIx_CR2_HALFDUPLEX_Pos)	/* DCNģʽ��4�߰�˫�� */

#define	SPIx_CR2_HD_RW_Pos	7	/* ��˫��ģʽ��������д�������� (Read/Write config for Half-Duplex mode)
0��4�߰�˫��Э��������д��ӻ�
1��4�߰�˫��Э����������ȡ�ӻ� */
#define	SPIx_CR2_HD_RW_Msk	(0x1U << SPIx_CR2_HD_RW_Pos)
#define	SPIx_CR2_HD_RW_WRITE	(0x0U << SPIx_CR2_HD_RW_Pos)	/* 4�߰�˫��Э��������д��ӻ� */
#define	SPIx_CR2_HD_RW_READ	(0x1U << SPIx_CR2_HD_RW_Pos)	/* 4�߰�˫��Э����������ȡ�ӻ� */

#define	SPIx_CR2_CMD8b_Pos	6	/* ��˫��ģʽ�¶���command֡���� (Command 8 bits)
1��command֡�̶�Ϊ8bit
0��command֡������DLEN���� */
#define	SPIx_CR2_CMD8b_Msk	(0x1U << SPIx_CR2_CMD8b_Pos)
#define	SPIx_CR2_CMD8b_8BIT	(0x1U << SPIx_CR2_CMD8b_Pos)	/* command֡�̶�Ϊ8bit */
#define	SPIx_CR2_CMD8b_DLEN	(0x0U << SPIx_CR2_CMD8b_Pos)	/* command֡������DLEN���� */

#define	SPIx_CR2_SSNM_Pos	5	/* Masterģʽ��SSN����ģʽѡ�� (SSN mode)
1��ÿ������һ֡��Master����SSN��ά�ָߵ�ƽʱ����WAIT�Ĵ�������
0��ÿ������һ֡��Master����SSNΪ�� */
#define	SPIx_CR2_SSNM_Msk	(0x1U << SPIx_CR2_SSNM_Pos)
#define	SPIx_CR2_SSNM_HIGH	(0x1U << SPIx_CR2_SSNM_Pos)	/* ÿ������һ֡��Master����SSN��ά�ָߵ�ƽʱ����WAIT�Ĵ������� */
#define	SPIx_CR2_SSNM_LOW	(0x0U << SPIx_CR2_SSNM_Pos)	/* ÿ������һ֡��Master����SSNΪ�� */

#define	SPIx_CR2_TXO_AC_Pos	4	/* TXONLYӲ���Զ���յ�ʹ�� (TXONLY auto-clear enable)1��TXONLYӲ���Զ�������Ч�����ʹ��TXO�󣬵ȴ�������Ϻ�Ӳ������0���ر�TXONLYӲ���Զ����� */
#define	SPIx_CR2_TXO_AC_Msk	(0x1U << SPIx_CR2_TXO_AC_Pos)

#define	SPIx_CR2_TXO_Pos	3	/* TXONLY����λ (Transmit Only mode enable)
1������Master�ĵ�����ģʽ
0���رյ�����ģʽ���շ�ȫ˫���� */
#define	SPIx_CR2_TXO_Msk	(0x1U << SPIx_CR2_TXO_Pos)
	/* ����Master�ĵ�����ģʽ */
	/* �رյ�����ģʽ���շ�ȫ˫���� */

#define	SPIx_CR2_SSN_Pos	2	/* Masterģʽ�£����SSNSENΪ1���������ͨ����λ����SSN�����ƽ 1��SSN����ߵ�ƽ
0��SSN����͵�ƽ */
#define	SPIx_CR2_SSN_Msk	(0x1U << SPIx_CR2_SSN_Pos)
#define	SPIx_CR2_SSN_LOW	(0x0U << SPIx_CR2_SSN_Pos)	/* SSN����ߵ�ƽ */
#define	SPIx_CR2_SSN_HIGH	(0x1U << SPIx_CR2_SSN_Pos)	/* SSN����͵�ƽ */

#define	SPIx_CR2_SSNSEN_Pos	1	/* Masterģʽ�£��������SSNʹ�� (SSN Software Enable)
1��Masterģʽ��SSN������������
0��Masterģʽ��SSN�����Ӳ���Զ����� */
#define	SPIx_CR2_SSNSEN_Msk	(0x1U << SPIx_CR2_SSNSEN_Pos)
	/* Masterģʽ��SSN������������ */
	/* Masterģʽ��SSN�����Ӳ���Զ����� */

#define	SPIx_CR2_SPIEN_Pos	0	/* SPIʹ�� (SPI enable)1��ʹ��SPI0���ر�SPI����շ��ͽ��ջ��� */
#define	SPIx_CR2_SPIEN_Msk	(0x1U << SPIx_CR2_SPIEN_Pos)

#define	SPIx_CR3_TXBFC_Pos	3	/* Transmit Buffer Clear�����д1������ͻ��棬д0��Ч */
#define	SPIx_CR3_TXBFC_Msk	(0x1U << SPIx_CR3_TXBFC_Pos)

#define	SPIx_CR3_RXBFC_Pos	2	/* Receive Buffer Clear�����д1������ͻ��棬д0��Ч */
#define	SPIx_CR3_RXBFC_Msk	(0x1U << SPIx_CR3_RXBFC_Pos)

#define	SPIx_CR3_MERRC_Pos	1	/* Master Error Clear�����д1���HSPISTA.MERR�Ĵ��� */
#define	SPIx_CR3_MERRC_Msk	(0x1U << SPIx_CR3_MERRC_Pos)

#define	SPIx_CR3_SERRC_Pos	0	/* Slave Error Clear�����д1���HSPISTA.SERR�Ĵ��� */
#define	SPIx_CR3_SERRC_Msk	(0x1U << SPIx_CR3_SERRC_Pos)

#define	SPIx_IER_ERRIE_Pos	2	/* SPI�����ж�ʹ�� (Error Interrupt Enable) */
#define	SPIx_IER_ERRIE_Msk	(0x1U << SPIx_IER_ERRIE_Pos)

#define	SPIx_IER_TXIE_Pos	1	/* ��������ж�ʹ�� (Transmit Interrupt Enable) */
#define	SPIx_IER_TXIE_Msk	(0x1U << SPIx_IER_TXIE_Pos)

#define	SPIx_IER_RXIE_Pos	0	/* ��������ж�ʹ�� (Receive Interrupt Enable) */
#define	SPIx_IER_RXIE_Msk	(0x1U << SPIx_IER_RXIE_Pos)

#define	SPIx_ISR_DCN_TX_Pos	12	/* ��˫��ģʽ�£�HALFDUPLEX=1����������ÿ������֡�����bit���͵�DCN�źŵ�ƽ (Data/Command transmit config)
0��DCN=0����ʾ����֡
1��DCN=1����ʾ����֡
���Ӧ�ڷ���ǰ����DCN_TX�Ĵ��������DCN_TX=0��Ӳ�������һ֡���ͺ��Զ���DCN_TX��1����Ĭ��ֻ�ᷢ��һ������֡��������������֡�� */
#define	SPIx_ISR_DCN_TX_Msk	(0x1U << SPIx_ISR_DCN_TX_Pos)
#define	SPIx_ISR_DCN_TX_COMMAND	(0x0U << SPIx_ISR_DCN_TX_Pos)	/* DCN=0����ʾ����֡ */
#define	SPIx_ISR_DCN_TX_DATA	(0x1U << SPIx_ISR_DCN_TX_Pos)	/* DCN=1����ʾ����֡ */

#define	SPIx_ISR_RXCOL_Pos	10	/* ���ջ�����������д1���� (Receive Collision flag,write 1 to flag) */
#define	SPIx_ISR_RXCOL_Msk	(0x1U << SPIx_ISR_RXCOL_Pos)

#define	SPIx_ISR_TXCOL_Pos	9	/* ���ͻ�����������д1���� (Transmit Collision flag,write 1 to clear) */
#define	SPIx_ISR_TXCOL_Msk	(0x1U << SPIx_ISR_TXCOL_Pos)

#define	SPIx_ISR_BUSY_Pos	8	/* SPI���б�־��ֻ�� (busy flag)
1��SPI���������
0��SPI������� */
#define	SPIx_ISR_BUSY_Msk	(0x1U << SPIx_ISR_BUSY_Pos)

#define	SPIx_ISR_MERR_Pos	6	/* Master Error��־(Master Error flag)
��Master�´���δ��8λSSN�ͱ�����ʱ��MERR��λ */
#define	SPIx_ISR_MERR_Msk	(0x1U << SPIx_ISR_MERR_Pos)

#define	SPIx_ISR_SERR_Pos	5	/* Slave Error��־(Slave Error flag)
��Slave�´���δ��8λSSN�ͱ�����ʱ��SERR��λ */
#define	SPIx_ISR_SERR_Msk	(0x1U << SPIx_ISR_SERR_Pos)

#define	SPIx_ISR_TXBE_Pos	1	/* TX Buffer Empty��־λ(TX Buffer Empty flag)
1�����ͻ���գ����дTXBUF����
0�����ͻ����� */
#define	SPIx_ISR_TXBE_Msk	(0x1U << SPIx_ISR_TXBE_Pos)

#define	SPIx_ISR_RXBF_Pos	0	/* RX Buffer Full��־λ(RX Buffer Full flag)
1�����ջ������������RXBUF����
0�����ջ���� */
#define	SPIx_ISR_RXBF_Msk	(0x1U << SPIx_ISR_RXBF_Pos)

#define	SPIx_TXBUF_TXBUF_Pos	0	/* SPI���ͻ��� (Transmit Buffer) */
#define	SPIx_TXBUF_TXBUF_Msk	(0xffffffffU << SPIx_TXBUF_TXBUF_Pos)

#define	SPIx_RXBUF_RXBUF_Pos	0	/* SPI���ջ��� (Receive Buffer) */
#define	SPIx_RXBUF_RXBUF_Msk	(0xffffffffU << SPIx_RXBUF_RXBUF_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void SPIx_Deinit(SPI_Type* SPIx);

/* MOSI��MISO���Ž��� (IO swapping)
0��Ĭ������˳��
1����������˳�� ��غ��� */
extern void SPIx_CR1_IOSWAP_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR1_IOSWAP_Get(SPI_Type* SPIx);

/* Master Sampling Position Adjustment��Master��MISO�źŵĲ���λ�õ��������ڸ���ͨ��ʱ����PCB�����ӳ�
1���������ӳٰ��SCK����
0�������� ��غ��� */
extern void SPIx_CR1_MSPA_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR1_MSPA_Get(SPI_Type* SPIx);

/* Slave Sending Position Adjustment��Slave MISO����λ�õ���
1����ǰ���SCK���ڷ���
0�������� ��غ��� */
extern void SPIx_CR1_SSPA_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR1_SSPA_Get(SPI_Type* SPIx);

/* Master/Slaveģʽѡ��(Master Mode)1��Masterģʽ0��Slaveģʽ ��غ��� */
extern void SPIx_CR1_MM_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR1_MM_Get(SPI_Type* SPIx);

/* Masterģʽ�£�ÿ������һ֡���������(1+WAIT)��SCK cycle�ȴ�ʱ�䣬�ٴ�����һ֡�����ݡ����SSN��Ӳ�����ƣ�����SSNM=1����Ӳ�����Զ�����SSN�� ��غ��� */
extern void SPIx_CR1_WAIT_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR1_WAIT_Get(SPI_Type* SPIx);

/* Masterģʽ����������λ: (Baud rate)000�� fAPBCLK/2001�� fAPBCLK/4010�� fAPBCLK/8011�� fAPBCLK/16100�� fAPBCLK/32101�� fAPBCLK/64110�� fAPBCLK/128111�� fAPBCLK/256��ͨ�����ڽ��е�ʱ�򣬲����޸���Щλ�� ��غ��� */
extern void SPIx_CR1_BAUD_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR1_BAUD_Get(SPI_Type* SPIx);

/* ֡��ʽ (LSB First) 0���ȷ���MSB1���ȷ���LSBע����ͨ���ڽ���ʱ���ܸı��λ��ֵ�� ��غ��� */
extern void SPIx_CR1_LSBF_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR1_LSBF_Get(SPI_Type* SPIx);
extern void SPIx_CR1_CPHOL_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR1_CPHOL_Get(SPI_Type* SPIx);

/* ʱ����λѡ�� (Clock Phase)1���ڶ���ʱ�ӱ����ǵ�һ����׽����0����һ��ʱ�ӱ����ǵ�һ����׽����ע����ͨ���ڽ���ʱ���ܸı��λ��ֵ�� ��غ��� */
extern void SPIx_CR1_CPHA_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR1_CPHA_Get(SPI_Type* SPIx);

/* 4�߰�˫��Э�����Ƿ��ڶ������в���dummy cycle
(Dummy cycle Enable)
0��������dummy cycle
1���ڶ�����֮�����һ��dummy cycle ��غ��� */
extern void SPIx_CR2_DUMMY_EN_Setable(SPI_Type* SPIx, FunState NewState);
extern FunState SPIx_CR2_DUMMY_EN_Getable(SPI_Type* SPIx);

/* RXONLY����λ���˼Ĵ�����λʱ��SPI�����������գ��������дTXBUF (Receive Only mode)
1������Master�ĵ�����ģʽ
0���رյ�����ģʽ���շ�ȫ˫���� ��غ��� */
extern void SPIx_CR2_RXO_Setable(SPI_Type* SPIx, FunState NewState);
extern FunState SPIx_CR2_RXO_Getable(SPI_Type* SPIx);

/* ͨ�������ֳ����� (Data Length)
00��8bit
01��16bit
10��24bit
11��32bit ��غ��� */
extern void SPIx_CR2_DLEN_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR2_DLEN_Get(SPI_Type* SPIx);

/* ͨ��ģʽѡ�� (Half-Duplex mode)
0����׼SPIģʽ��4��ȫ˫��
1��DCNģʽ��4�߰�˫�� ��غ��� */
extern void SPIx_CR2_HALFDUPLEX_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR2_HALFDUPLEX_Get(SPI_Type* SPIx);

/* ��˫��ģʽ��������д�������� (Read/Write config for Half-Duplex mode)
0��4�߰�˫��Э��������д��ӻ�
1��4�߰�˫��Э����������ȡ�ӻ� ��غ��� */
extern void SPIx_CR2_HD_RW_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR2_HD_RW_Get(SPI_Type* SPIx);

/* ��˫��ģʽ�¶���command֡���� (Command 8 bits)
1��command֡�̶�Ϊ8bit
0��command֡������DLEN���� ��غ��� */
extern void SPIx_CR2_CMD8b_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR2_CMD8b_Get(SPI_Type* SPIx);

/* Masterģʽ��SSN����ģʽѡ�� (SSN mode)
1��ÿ������һ֡��Master����SSN��ά�ָߵ�ƽʱ����WAIT�Ĵ�������
0��ÿ������һ֡��Master����SSNΪ�� ��غ��� */
extern void SPIx_CR2_SSNM_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR2_SSNM_Get(SPI_Type* SPIx);

/* TXONLYӲ���Զ���յ�ʹ�� (TXONLY auto-clear enable)1��TXONLYӲ���Զ�������Ч�����ʹ��TXO�󣬵ȴ�������Ϻ�Ӳ������0���ر�TXONLYӲ���Զ����� ��غ��� */
extern void SPIx_CR2_TXO_AC_Setable(SPI_Type* SPIx, FunState NewState);
extern FunState SPIx_CR2_TXO_AC_Getable(SPI_Type* SPIx);

/* TXONLY����λ (Transmit Only mode enable)
1������Master�ĵ�����ģʽ
0���رյ�����ģʽ���շ�ȫ˫���� ��غ��� */
extern void SPIx_CR2_TXO_Setable(SPI_Type* SPIx, FunState NewState);
extern FunState SPIx_CR2_TXO_Getable(SPI_Type* SPIx);

/* Masterģʽ�£����SSNSENΪ1���������ͨ����λ����SSN�����ƽ 1��SSN����ߵ�ƽ
0��SSN����͵�ƽ ��غ��� */
extern void SPIx_CR2_SSN_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR2_SSN_Get(SPI_Type* SPIx);

/* Masterģʽ�£��������SSNʹ�� (SSN Software Enable)
1��Masterģʽ��SSN������������
0��Masterģʽ��SSN�����Ӳ���Զ����� ��غ��� */
extern void SPIx_CR2_SSNSEN_Setable(SPI_Type* SPIx, FunState NewState);
extern FunState SPIx_CR2_SSNSEN_Getable(SPI_Type* SPIx);

/* SPIʹ�� (SPI enable)1��ʹ��SPI0���ر�SPI����շ��ͽ��ջ��� ��غ��� */
extern void SPIx_CR2_SPIEN_Setable(SPI_Type* SPIx, FunState NewState);
extern FunState SPIx_CR2_SPIEN_Getable(SPI_Type* SPIx);

/* Transmit Buffer Clear�����д1������ͻ��棬д0��Ч ��غ��� */
extern void SPIx_CR3_TXBFC_Clr(SPI_Type* SPIx);

/* Receive Buffer Clear�����д1������ͻ��棬д0��Ч ��غ��� */
extern void SPIx_CR3_RXBFC_Clr(SPI_Type* SPIx);

/* Master Error Clear�����д1���HSPISTA.MERR�Ĵ��� ��غ��� */
extern void SPIx_CR3_MERRC_Clr(SPI_Type* SPIx);

/* Slave Error Clear�����д1���HSPISTA.SERR�Ĵ��� ��غ��� */
extern void SPIx_CR3_SERRC_Clr(SPI_Type* SPIx);

/* SPI�����ж�ʹ�� (Error Interrupt Enable) ��غ��� */
extern void SPIx_IER_ERRIE_Setable(SPI_Type* SPIx, FunState NewState);
extern FunState SPIx_IER_ERRIE_Getable(SPI_Type* SPIx);

/* ��������ж�ʹ�� (Transmit Interrupt Enable) ��غ��� */
extern void SPIx_IER_TXIE_Setable(SPI_Type* SPIx, FunState NewState);
extern FunState SPIx_IER_TXIE_Getable(SPI_Type* SPIx);

/* ��������ж�ʹ�� (Receive Interrupt Enable) ��غ��� */
extern void SPIx_IER_RXIE_Setable(SPI_Type* SPIx, FunState NewState);
extern FunState SPIx_IER_RXIE_Getable(SPI_Type* SPIx);

/* ��˫��ģʽ�£�HALFDUPLEX=1����������ÿ������֡�����bit���͵�DCN�źŵ�ƽ (Data/Command transmit config)
0��DCN=0����ʾ����֡
1��DCN=1����ʾ����֡
���Ӧ�ڷ���ǰ����DCN_TX�Ĵ��������DCN_TX=0��Ӳ�������һ֡���ͺ��Զ���DCN_TX��1����Ĭ��ֻ�ᷢ��һ������֡��������������֡�� ��غ��� */
extern void SPIx_ISR_DCN_TX_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_ISR_DCN_TX_Get(SPI_Type* SPIx);

/* ���ջ�����������д1���� (Receive Collision flag,write 1 to flag) ��غ��� */
extern void SPIx_ISR_RXCOL_Clr(SPI_Type* SPIx);
extern FlagStatus SPIx_ISR_RXCOL_Chk(SPI_Type* SPIx);

/* ���ͻ�����������д1���� (Transmit Collision flag,write 1 to clear) ��غ��� */
extern void SPIx_ISR_TXCOL_Clr(SPI_Type* SPIx);
extern FlagStatus SPIx_ISR_TXCOL_Chk(SPI_Type* SPIx);

/* SPI���б�־��ֻ�� (busy flag)
1��SPI���������
0��SPI������� ��غ��� */
extern FlagStatus SPIx_ISR_BUSY_Chk(SPI_Type* SPIx);

/* Master Error��־(Master Error flag)
��Master�´���δ��8λSSN�ͱ�����ʱ��MERR��λ ��غ��� */
extern FlagStatus SPIx_ISR_MERR_Chk(SPI_Type* SPIx);

/* Slave Error��־(Slave Error flag)
��Slave�´���δ��8λSSN�ͱ�����ʱ��SERR��λ ��غ��� */
extern FlagStatus SPIx_ISR_SERR_Chk(SPI_Type* SPIx);

/* TX Buffer Empty��־λ(TX Buffer Empty flag)
1�����ͻ���գ����дTXBUF����
0�����ͻ����� ��غ��� */
extern FlagStatus SPIx_ISR_TXBE_Chk(SPI_Type* SPIx);

/* RX Buffer Full��־λ(RX Buffer Full flag)
1�����ջ������������RXBUF����
0�����ջ���� ��غ��� */
extern FlagStatus SPIx_ISR_RXBF_Chk(SPI_Type* SPIx);

/* SPI���ͻ��� (Transmit Buffer) ��غ��� */
extern void SPIx_TXBUF_Write(SPI_Type* SPIx, uint32_t SetValue);

/* SPI���ջ��� (Receive Buffer) ��غ��� */
extern uint32_t SPIx_RXBUF_Read(SPI_Type* SPIx);
//Announce_End

void SPIx_Deinit(SPI_Type* SPIx);
void SPI_SSN_Set_Low(SPI_Type* SPIx);
void SPI_SSN_Set_High(SPI_Type* SPIx);
uint8_t SPI_RW_Byte(SPI_Type* SPIx, uint8_t data);

#ifdef __cplusplus
}
#endif

#endif /*__FM33A0XXEV_SPI_H */
