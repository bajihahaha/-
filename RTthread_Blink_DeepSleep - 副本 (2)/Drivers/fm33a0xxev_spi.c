/**
  ******************************************************************************
  * @file    fm33a0xxev_spi.c
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/

#include "fm33a0xxev_spi.h"
#include "fm33a0xxev_rmu.h"

/** @addtogroup fm33a0xxev_StdPeriph_Driver
  * @{
  */

/** @defgroup SPI 
  * @brief SPI driver modules
  * @{
  */ 

/* MOSI��MISO���Ž��� (IO swapping)
0��Ĭ������˳��
1����������˳�� ��غ��� */
void SPIx_CR1_IOSWAP_Set(SPI_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->CR1 ;
	tmpreg &= ~(SPIx_CR1_IOSWAP_Msk);
	tmpreg |= (SetValue & SPIx_CR1_IOSWAP_Msk);
	SPIx->CR1  = tmpreg;
}

uint32_t SPIx_CR1_IOSWAP_Get(SPI_Type* SPIx)
{
	return (SPIx->CR1  & SPIx_CR1_IOSWAP_Msk);
}

/* Master Sampling Position Adjustment��Master��MISO�źŵĲ���λ�õ��������ڸ���ͨ��ʱ����PCB�����ӳ�
1���������ӳٰ��SCK����
0�������� ��غ��� */
void SPIx_CR1_MSPA_Set(SPI_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->CR1 ;
	tmpreg &= ~(SPIx_CR1_MSPA_Msk);
	tmpreg |= (SetValue & SPIx_CR1_MSPA_Msk);
	SPIx->CR1  = tmpreg;
}

uint32_t SPIx_CR1_MSPA_Get(SPI_Type* SPIx)
{
	return (SPIx->CR1  & SPIx_CR1_MSPA_Msk);
}

/* Slave Sending Position Adjustment��Slave MISO����λ�õ���
1����ǰ���SCK���ڷ���
0�������� ��غ��� */
void SPIx_CR1_SSPA_Set(SPI_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->CR1 ;
	tmpreg &= ~(SPIx_CR1_SSPA_Msk);
	tmpreg |= (SetValue & SPIx_CR1_SSPA_Msk);
	SPIx->CR1  = tmpreg;
}

uint32_t SPIx_CR1_SSPA_Get(SPI_Type* SPIx)
{
	return (SPIx->CR1  & SPIx_CR1_SSPA_Msk);
}

/* Master/Slaveģʽѡ��(Master Mode)1��Masterģʽ0��Slaveģʽ ��غ��� */
void SPIx_CR1_MM_Set(SPI_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->CR1 ;
	tmpreg &= ~(SPIx_CR1_MM_Msk);
	tmpreg |= (SetValue & SPIx_CR1_MM_Msk);
	SPIx->CR1  = tmpreg;
}

uint32_t SPIx_CR1_MM_Get(SPI_Type* SPIx)
{
	return (SPIx->CR1  & SPIx_CR1_MM_Msk);
}

/* Masterģʽ�£�ÿ������һ֡���������(1+WAIT)��SCK cycle�ȴ�ʱ�䣬�ٴ�����һ֡�����ݡ����SSN��Ӳ�����ƣ�����SSNM=1����Ӳ�����Զ�����SSN�� ��غ��� */
void SPIx_CR1_WAIT_Set(SPI_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->CR1 ;
	tmpreg &= ~(SPIx_CR1_WAIT_Msk);
	tmpreg |= (SetValue & SPIx_CR1_WAIT_Msk);
	SPIx->CR1  = tmpreg;
}

uint32_t SPIx_CR1_WAIT_Get(SPI_Type* SPIx)
{
	return (SPIx->CR1  & SPIx_CR1_WAIT_Msk);
}

/* Masterģʽ����������λ: (Baud rate)000�� fAPBCLK/2001�� fAPBCLK/4010�� fAPBCLK/8011�� fAPBCLK/16100�� fAPBCLK/32101�� fAPBCLK/64110�� fAPBCLK/128111�� fAPBCLK/256��ͨ�����ڽ��е�ʱ�򣬲����޸���Щλ�� ��غ��� */
void SPIx_CR1_BAUD_Set(SPI_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->CR1 ;
	tmpreg &= ~(SPIx_CR1_BAUD_Msk);
	tmpreg |= (SetValue & SPIx_CR1_BAUD_Msk);
	SPIx->CR1  = tmpreg;
}

uint32_t SPIx_CR1_BAUD_Get(SPI_Type* SPIx)
{
	return (SPIx->CR1  & SPIx_CR1_BAUD_Msk);
}

/* ֡��ʽ (LSB First) 0���ȷ���MSB1���ȷ���LSBע����ͨ���ڽ���ʱ���ܸı��λ��ֵ�� ��غ��� */
void SPIx_CR1_LSBF_Set(SPI_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->CR1 ;
	tmpreg &= ~(SPIx_CR1_LSBF_Msk);
	tmpreg |= (SetValue & SPIx_CR1_LSBF_Msk);
	SPIx->CR1  = tmpreg;
}

uint32_t SPIx_CR1_LSBF_Get(SPI_Type* SPIx)
{
	return (SPIx->CR1  & SPIx_CR1_LSBF_Msk);
}

void SPIx_CR1_CPHOL_Set(SPI_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->CR1 ;
	tmpreg &= ~(SPIx_CR1_CPHOL_Msk);
	tmpreg |= (SetValue & SPIx_CR1_CPHOL_Msk);
	SPIx->CR1  = tmpreg;
}

uint32_t SPIx_CR1_CPHOL_Get(SPI_Type* SPIx)
{
	return (SPIx->CR1  & SPIx_CR1_CPHOL_Msk);
}

/* ʱ����λѡ�� (Clock Phase)1���ڶ���ʱ�ӱ����ǵ�һ����׽����0����һ��ʱ�ӱ����ǵ�һ����׽����ע����ͨ���ڽ���ʱ���ܸı��λ��ֵ�� ��غ��� */
void SPIx_CR1_CPHA_Set(SPI_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->CR1 ;
	tmpreg &= ~(SPIx_CR1_CPHA_Msk);
	tmpreg |= (SetValue & SPIx_CR1_CPHA_Msk);
	SPIx->CR1  = tmpreg;
}

uint32_t SPIx_CR1_CPHA_Get(SPI_Type* SPIx)
{
	return (SPIx->CR1  & SPIx_CR1_CPHA_Msk);
}

/* 4�߰�˫��Э�����Ƿ��ڶ������в���dummy cycle
(Dummy cycle Enable)
0��������dummy cycle
1���ڶ�����֮�����һ��dummy cycle ��غ��� */
void SPIx_CR2_DUMMY_EN_Setable(SPI_Type* SPIx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		SPIx->CR2  |= (SPIx_CR2_DUMMY_EN_Msk);
	}
	else
	{
		SPIx->CR2  &= ~(SPIx_CR2_DUMMY_EN_Msk);
	}
}

FunState SPIx_CR2_DUMMY_EN_Getable(SPI_Type* SPIx)
{
	if (SPIx->CR2  & (SPIx_CR2_DUMMY_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* RXONLY����λ���˼Ĵ�����λʱ��SPI�����������գ��������дTXBUF (Receive Only mode)
1������Master�ĵ�����ģʽ
0���رյ�����ģʽ���շ�ȫ˫���� ��غ��� */
void SPIx_CR2_RXO_Setable(SPI_Type* SPIx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		SPIx->CR2  |= (SPIx_CR2_RXO_Msk);
	}
	else
	{
		SPIx->CR2  &= ~(SPIx_CR2_RXO_Msk);
	}
}

FunState SPIx_CR2_RXO_Getable(SPI_Type* SPIx)
{
	if (SPIx->CR2  & (SPIx_CR2_RXO_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ͨ�������ֳ����� (Data Length)
00��8bit
01��16bit
10��24bit
11��32bit ��غ��� */
void SPIx_CR2_DLEN_Set(SPI_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->CR2 ;
	tmpreg &= ~(SPIx_CR2_DLEN_Msk);
	tmpreg |= (SetValue & SPIx_CR2_DLEN_Msk);
	SPIx->CR2  = tmpreg;
}

uint32_t SPIx_CR2_DLEN_Get(SPI_Type* SPIx)
{
	return (SPIx->CR2  & SPIx_CR2_DLEN_Msk);
}

/* ͨ��ģʽѡ�� (Half-Duplex mode)
0����׼SPIģʽ��4��ȫ˫��
1��DCNģʽ��4�߰�˫�� ��غ��� */
void SPIx_CR2_HALFDUPLEX_Set(SPI_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->CR2 ;
	tmpreg &= ~(SPIx_CR2_HALFDUPLEX_Msk);
	tmpreg |= (SetValue & SPIx_CR2_HALFDUPLEX_Msk);
	SPIx->CR2  = tmpreg;
}

uint32_t SPIx_CR2_HALFDUPLEX_Get(SPI_Type* SPIx)
{
	return (SPIx->CR2  & SPIx_CR2_HALFDUPLEX_Msk);
}

/* ��˫��ģʽ��������д�������� (Read/Write config for Half-Duplex mode)
0��4�߰�˫��Э��������д��ӻ�
1��4�߰�˫��Э����������ȡ�ӻ� ��غ��� */
void SPIx_CR2_HD_RW_Set(SPI_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->CR2 ;
	tmpreg &= ~(SPIx_CR2_HD_RW_Msk);
	tmpreg |= (SetValue & SPIx_CR2_HD_RW_Msk);
	SPIx->CR2  = tmpreg;
}

uint32_t SPIx_CR2_HD_RW_Get(SPI_Type* SPIx)
{
	return (SPIx->CR2  & SPIx_CR2_HD_RW_Msk);
}

/* ��˫��ģʽ�¶���command֡���� (Command 8 bits)
1��command֡�̶�Ϊ8bit
0��command֡������DLEN���� ��غ��� */
void SPIx_CR2_CMD8b_Set(SPI_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->CR2 ;
	tmpreg &= ~(SPIx_CR2_CMD8b_Msk);
	tmpreg |= (SetValue & SPIx_CR2_CMD8b_Msk);
	SPIx->CR2  = tmpreg;
}

uint32_t SPIx_CR2_CMD8b_Get(SPI_Type* SPIx)
{
	return (SPIx->CR2  & SPIx_CR2_CMD8b_Msk);
}

/* Masterģʽ��SSN����ģʽѡ�� (SSN mode)
1��ÿ������һ֡��Master����SSN��ά�ָߵ�ƽʱ����WAIT�Ĵ�������
0��ÿ������һ֡��Master����SSNΪ�� ��غ��� */
void SPIx_CR2_SSNM_Set(SPI_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->CR2 ;
	tmpreg &= ~(SPIx_CR2_SSNM_Msk);
	tmpreg |= (SetValue & SPIx_CR2_SSNM_Msk);
	SPIx->CR2  = tmpreg;
}

uint32_t SPIx_CR2_SSNM_Get(SPI_Type* SPIx)
{
	return (SPIx->CR2  & SPIx_CR2_SSNM_Msk);
}

/* TXONLYӲ���Զ���յ�ʹ�� (TXONLY auto-clear enable)1��TXONLYӲ���Զ�������Ч�����ʹ��TXO�󣬵ȴ�������Ϻ�Ӳ������0���ر�TXONLYӲ���Զ����� ��غ��� */
void SPIx_CR2_TXO_AC_Setable(SPI_Type* SPIx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		SPIx->CR2  |= (SPIx_CR2_TXO_AC_Msk);
	}
	else
	{
		SPIx->CR2  &= ~(SPIx_CR2_TXO_AC_Msk);
	}
}

FunState SPIx_CR2_TXO_AC_Getable(SPI_Type* SPIx)
{
	if (SPIx->CR2  & (SPIx_CR2_TXO_AC_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* TXONLY����λ (Transmit Only mode enable)
1������Master�ĵ�����ģʽ
0���رյ�����ģʽ���շ�ȫ˫���� ��غ��� */
void SPIx_CR2_TXO_Setable(SPI_Type* SPIx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		SPIx->CR2  |= (SPIx_CR2_TXO_Msk);
	}
	else
	{
		SPIx->CR2  &= ~(SPIx_CR2_TXO_Msk);
	}
}

FunState SPIx_CR2_TXO_Getable(SPI_Type* SPIx)
{
	if (SPIx->CR2  & (SPIx_CR2_TXO_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Masterģʽ�£����SSNSENΪ1���������ͨ����λ����SSN�����ƽ 1��SSN����ߵ�ƽ
0��SSN����͵�ƽ ��غ��� */
void SPIx_CR2_SSN_Set(SPI_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->CR2 ;
	tmpreg &= ~(SPIx_CR2_SSN_Msk);
	tmpreg |= (SetValue & SPIx_CR2_SSN_Msk);
	SPIx->CR2  = tmpreg;
}

uint32_t SPIx_CR2_SSN_Get(SPI_Type* SPIx)
{
	return (SPIx->CR2  & SPIx_CR2_SSN_Msk);
}

/* Masterģʽ�£��������SSNʹ�� (SSN Software Enable)
1��Masterģʽ��SSN������������
0��Masterģʽ��SSN�����Ӳ���Զ����� ��غ��� */
void SPIx_CR2_SSNSEN_Setable(SPI_Type* SPIx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		SPIx->CR2  |= (SPIx_CR2_SSNSEN_Msk);
	}
	else
	{
		SPIx->CR2  &= ~(SPIx_CR2_SSNSEN_Msk);
	}
}

FunState SPIx_CR2_SSNSEN_Getable(SPI_Type* SPIx)
{
	if (SPIx->CR2  & (SPIx_CR2_SSNSEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* SPIʹ�� (SPI enable)1��ʹ��SPI0���ر�SPI����շ��ͽ��ջ��� ��غ��� */
void SPIx_CR2_SPIEN_Setable(SPI_Type* SPIx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		SPIx->CR2  |= (SPIx_CR2_SPIEN_Msk);
	}
	else
	{
		SPIx->CR2  &= ~(SPIx_CR2_SPIEN_Msk);
	}
}

FunState SPIx_CR2_SPIEN_Getable(SPI_Type* SPIx)
{
	if (SPIx->CR2  & (SPIx_CR2_SPIEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Transmit Buffer Clear�����д1������ͻ��棬д0��Ч ��غ��� */
void SPIx_CR3_TXBFC_Clr(SPI_Type* SPIx)
{
	SPIx->CR3  = SPIx_CR3_TXBFC_Msk;
}

/* Receive Buffer Clear�����д1������ͻ��棬д0��Ч ��غ��� */
void SPIx_CR3_RXBFC_Clr(SPI_Type* SPIx)
{
	SPIx->CR3  = SPIx_CR3_RXBFC_Msk;
}

/* Master Error Clear�����д1���HSPISTA.MERR�Ĵ��� ��غ��� */
void SPIx_CR3_MERRC_Clr(SPI_Type* SPIx)
{
	SPIx->CR3  = SPIx_CR3_MERRC_Msk;
}

/* Slave Error Clear�����д1���HSPISTA.SERR�Ĵ��� ��غ��� */
void SPIx_CR3_SERRC_Clr(SPI_Type* SPIx)
{
	SPIx->CR3  = SPIx_CR3_SERRC_Msk;
}

/* SPI�����ж�ʹ�� (Error Interrupt Enable) ��غ��� */
void SPIx_IER_ERRIE_Setable(SPI_Type* SPIx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		SPIx->IER  |= (SPIx_IER_ERRIE_Msk);
	}
	else
	{
		SPIx->IER  &= ~(SPIx_IER_ERRIE_Msk);
	}
}

FunState SPIx_IER_ERRIE_Getable(SPI_Type* SPIx)
{
	if (SPIx->IER  & (SPIx_IER_ERRIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��������ж�ʹ�� (Transmit Interrupt Enable) ��غ��� */
void SPIx_IER_TXIE_Setable(SPI_Type* SPIx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		SPIx->IER  |= (SPIx_IER_TXIE_Msk);
	}
	else
	{
		SPIx->IER  &= ~(SPIx_IER_TXIE_Msk);
	}
}

FunState SPIx_IER_TXIE_Getable(SPI_Type* SPIx)
{
	if (SPIx->IER  & (SPIx_IER_TXIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��������ж�ʹ�� (Receive Interrupt Enable) ��غ��� */
void SPIx_IER_RXIE_Setable(SPI_Type* SPIx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		SPIx->IER  |= (SPIx_IER_RXIE_Msk);
	}
	else
	{
		SPIx->IER  &= ~(SPIx_IER_RXIE_Msk);
	}
}

FunState SPIx_IER_RXIE_Getable(SPI_Type* SPIx)
{
	if (SPIx->IER  & (SPIx_IER_RXIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��˫��ģʽ�£�HALFDUPLEX=1����������ÿ������֡�����bit���͵�DCN�źŵ�ƽ (Data/Command transmit config)
0��DCN=0����ʾ����֡
1��DCN=1����ʾ����֡
���Ӧ�ڷ���ǰ����DCN_TX�Ĵ��������DCN_TX=0��Ӳ�������һ֡���ͺ��Զ���DCN_TX��1����Ĭ��ֻ�ᷢ��һ������֡��������������֡�� ��غ��� */
void SPIx_ISR_DCN_TX_Set(SPI_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->ISR ;
	tmpreg &= ~(SPIx_ISR_DCN_TX_Msk);
	tmpreg |= (SetValue & SPIx_ISR_DCN_TX_Msk);
	SPIx->ISR  = tmpreg;
}

uint32_t SPIx_ISR_DCN_TX_Get(SPI_Type* SPIx)
{
	return (SPIx->ISR  & SPIx_ISR_DCN_TX_Msk);
}

/* ���ջ�����������д1���� (Receive Collision flag,write 1 to flag) ��غ��� */
void SPIx_ISR_RXCOL_Clr(SPI_Type* SPIx)
{
	SPIx->ISR  = SPIx_ISR_RXCOL_Msk;
}

FlagStatus SPIx_ISR_RXCOL_Chk(SPI_Type* SPIx)
{
	if (SPIx->ISR  & SPIx_ISR_RXCOL_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ���ͻ�����������д1���� (Transmit Collision flag,write 1 to clear) ��غ��� */
void SPIx_ISR_TXCOL_Clr(SPI_Type* SPIx)
{
	SPIx->ISR  = SPIx_ISR_TXCOL_Msk;
}

FlagStatus SPIx_ISR_TXCOL_Chk(SPI_Type* SPIx)
{
	if (SPIx->ISR  & SPIx_ISR_TXCOL_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* SPI���б�־��ֻ�� (busy flag)
1��SPI���������
0��SPI������� ��غ��� */
FlagStatus SPIx_ISR_BUSY_Chk(SPI_Type* SPIx)
{
	if (SPIx->ISR  & SPIx_ISR_BUSY_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* Master Error��־(Master Error flag)
��Master�´���δ��8λSSN�ͱ�����ʱ��MERR��λ ��غ��� */
FlagStatus SPIx_ISR_MERR_Chk(SPI_Type* SPIx)
{
	if (SPIx->ISR  & SPIx_ISR_MERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* Slave Error��־(Slave Error flag)
��Slave�´���δ��8λSSN�ͱ�����ʱ��SERR��λ ��غ��� */
FlagStatus SPIx_ISR_SERR_Chk(SPI_Type* SPIx)
{
	if (SPIx->ISR  & SPIx_ISR_SERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* TX Buffer Empty��־λ(TX Buffer Empty flag)
1�����ͻ���գ����дTXBUF����
0�����ͻ����� ��غ��� */
FlagStatus SPIx_ISR_TXBE_Chk(SPI_Type* SPIx)
{
	if (SPIx->ISR  & SPIx_ISR_TXBE_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* RX Buffer Full��־λ(RX Buffer Full flag)
1�����ջ������������RXBUF����
0�����ջ���� ��غ��� */
FlagStatus SPIx_ISR_RXBF_Chk(SPI_Type* SPIx)
{
	if (SPIx->ISR  & SPIx_ISR_RXBF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* SPI���ͻ��� (Transmit Buffer) ��غ��� */
void SPIx_TXBUF_Write(SPI_Type* SPIx, uint32_t SetValue)
{
	SPIx->TXBUF  = (SetValue);
}

/* SPI���ջ��� (Receive Buffer) ��غ��� */
uint32_t SPIx_RXBUF_Read(SPI_Type* SPIx)
{
	return (SPIx->RXBUF );
}

void SPIx_Deinit(SPI_Type* SPIx)
{
    RMU_PRSTEN_Write(0x13579BDF);
    if (SPIx == SPI0)
    {
        RMU_APBRST2_SPI0RST_Setable(ENABLE);
        RMU_APBRST2_SPI0RST_Setable(DISABLE);
    }
    else if (SPIx == SPI1)
    {
        RMU_APBRST2_SPI1RST_Setable(ENABLE);
        RMU_APBRST2_SPI1RST_Setable(DISABLE);
    }
    else if (SPIx == SPI2)
    {
        RMU_APBRST1_SPI2RST_Setable(ENABLE);
        RMU_APBRST1_SPI2RST_Setable(DISABLE);
    }
    else if (SPIx == SPI3)
    {
        RMU_APBRST1_SPI3RST_Setable(ENABLE);
        RMU_APBRST1_SPI3RST_Setable(DISABLE);
    }
    else if (SPIx == SPI4)
    {
        RMU_APBRST1_SPI4RST_Setable(ENABLE);
        RMU_APBRST1_SPI4RST_Setable(DISABLE);
    }
    RMU_PRSTEN_Write(0x00000000);
}

/********************************
 SPI��SSN���õ�ƽ�͵ĺ���
********************************/
void SPI_SSN_Set_Low(SPI_Type* SPIx)//������
{
	SPIx_CR2_SSN_Set(SPIx, SPIx_CR2_SSN_LOW);//����SSN�ź�
}

/********************************
 SPI��SSN���õ�ƽ�ߵĺ���
********************************/
void SPI_SSN_Set_High(SPI_Type* SPIx)//������
{
	SPIx_CR2_SSN_Set(SPIx, SPIx_CR2_SSN_HIGH);//����SSN�ź�
}

/********************************
 SPI���Ͳ�����һ���ֽڵĺ���
���ܣ�SPI���ͺͽ���һ���ֽ�
���룺SPIҪ���͵��ֽڣ������SPI�����ֽ�
********************************/
uint8_t SPI_RW_Byte(SPI_Type* SPIx, uint8_t data)//SPI���Ͳ�����һ�ֽ�
{
  unsigned char rx_data;
	uint32_t Temp32;
	uint32_t i;
	
	Temp32 = SPIx_CR1_BAUD_Get(SPIx);
	Temp32 = Temp32>>SPIx_CR1_BAUD_Pos;
	Temp32 = 0x1U<<(Temp32+1);
	Temp32 = Temp32*8;
	
    for(i=0; i<Temp32; i++)
    {
    	if (SPIx_ISR_TXBE_Chk(SPIx) == SET)
		{
			break;
		}		
    }
    SPIx_TXBUF_Write(SPIx, data);

    for(i=0; i<Temp32; i++)
    {
    	if (SPIx_ISR_RXBF_Chk(SPIx) == SET)
        {
            break;
        }
    }
    rx_data = SPIx_RXBUF_Read(SPIx);
    return rx_data;
}

/******END OF FILE****/
