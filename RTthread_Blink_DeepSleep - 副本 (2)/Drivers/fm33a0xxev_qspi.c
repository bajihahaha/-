/**
  ******************************************************************************
  * @file    fm33a0xxev_qspi.c
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/

#include "fm33a0xxev_qspi.h"
#include "fm33a0xxev_rmu.h"

/** @addtogroup fm33a0xxev_StdPeriph_Driver
  * @{
  */

/** @defgroup QSPI 
  * @brief QSPI driver modules
  * @{
  */ 

void QSPI_CR_PRESCALER_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
    
    SetValue <<= QSPI_CR_PRESCALER_Pos;
    
	tmpreg = QSPI->CR;
	tmpreg &= ~(QSPI_CR_PRESCALER_Msk);
	tmpreg |= (SetValue & QSPI_CR_PRESCALER_Msk);
	QSPI->CR = tmpreg;
}

uint32_t QSPI_CR_PRESCALER_Get(void)
{
	return (QSPI->CR & QSPI_CR_PRESCALER_Msk);
}

/* ��ѯƥ��ģʽ
0��ANDģʽ������bit��ƥ�����λSMF
1��ORģʽ������1bitƥ��ͻ���λSMF ��غ��� */
void QSPI_CR_PMM_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = QSPI->CR;
	tmpreg &= ~(QSPI_CR_PMM_Msk);
	tmpreg |= (SetValue & QSPI_CR_PMM_Msk);
	QSPI->CR = tmpreg;
}

uint32_t QSPI_CR_PMM_Get(void)
{
	return (QSPI->CR & QSPI_CR_PMM_Msk);
}

/* ��ʱ�ж�ʹ��
0����ֹ��ʱ�ж�
1������ʱ�ж� ��غ��� */
void QSPI_CR_TOIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		QSPI->CR |= (QSPI_CR_TOIE_Msk);
	}
	else
	{
		QSPI->CR &= ~(QSPI_CR_TOIE_Msk);
	}
}

FunState QSPI_CR_TOIE_Getable(void)
{
	if (QSPI->CR & (QSPI_CR_TOIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ״̬ƥ���ж�ʹ��
0����ֹ״̬ƥ���ж�
1������״̬ƥ���ж� ��غ��� */
void QSPI_CR_SMIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		QSPI->CR |= (QSPI_CR_SMIE_Msk);
	}
	else
	{
		QSPI->CR &= ~(QSPI_CR_SMIE_Msk);
	}
}

FunState QSPI_CR_SMIE_Getable(void)
{
	if (QSPI->CR & (QSPI_CR_SMIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* FIFOˮλ�ж�ʹ��
0����ֹFIFOˮλ�ж�
1������FIFOˮλ�ж� ��غ��� */
void QSPI_CR_FTIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		QSPI->CR |= (QSPI_CR_FTIE_Msk);
	}
	else
	{
		QSPI->CR &= ~(QSPI_CR_FTIE_Msk);
	}
}

FunState QSPI_CR_FTIE_Getable(void)
{
	if (QSPI->CR & (QSPI_CR_FTIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��������ж�ʹ��
0����ֹ��������ж�
1������������ж� ��غ��� */
void QSPI_CR_TCIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		QSPI->CR |= (QSPI_CR_TCIE_Msk);
	}
	else
	{
		QSPI->CR &= ~(QSPI_CR_TCIE_Msk);
	}
}

FunState QSPI_CR_TCIE_Getable(void)
{
	if (QSPI->CR & (QSPI_CR_TCIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��������ж�ʹ��
0����ֹ��������ж�
1������������ж� ��غ��� */
void QSPI_CR_TEIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		QSPI->CR |= (QSPI_CR_TEIE_Msk);
	}
	else
	{
		QSPI->CR &= ~(QSPI_CR_TEIE_Msk);
	}
}

FunState QSPI_CR_TEIE_Getable(void)
{
	if (QSPI->CR & (QSPI_CR_TEIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* FIFOˮλ�Ĵ�����������ģʽ����Ч
����дģʽ��
0��FTF��FIFO���ֽڴ��ڵ���1ʱ��λ
1��FTF��FIFO���ֽڴ��ڵ���2ʱ��λ
����
15��FTF��FIFO���ֽڵ���16ʱ��λ
�����ģʽ��
0��FTF��FIFO���ֽ������ڵ���1ʱ��λ
1��FTF��FIFO���ֽ������ڵ���2ʱ��λ
����
15��FTF��FIFO���ֽ�������16ʱ��λ ��غ��� */
void QSPI_CR_FIFOTHR_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = QSPI->CR;
	tmpreg &= ~(QSPI_CR_FIFOTHR_Msk);
	tmpreg |= (SetValue & QSPI_CR_FIFOTHR_Msk);
	QSPI->CR = tmpreg;
}

uint32_t QSPI_CR_FIFOTHR_Get(void)
{
	return (QSPI->CR & QSPI_CR_FIFOTHR_Msk);
}

/* �ӳٲ���ʹ��
0���ر��ӳٲ�������
1��ʹ���ӳٲ������� ��غ��� */
void QSPI_CR_SSHFT_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		QSPI->CR |= (QSPI_CR_SSHFT_Msk);
	}
	else
	{
		QSPI->CR &= ~(QSPI_CR_SSHFT_Msk);
	}
}

FunState QSPI_CR_SSHFT_Getable(void)
{
	if (QSPI->CR & (QSPI_CR_SSHFT_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���߳�ʱʹ�ܣ��˼Ĵ������ڴ洢��ӳ��ģʽ����Ч
��BUSY��λ�����QuadSPI�������QSPI�洢���ķ��ʣ���ʱ�Ĵ�����ʼ�������������������TIMEOUT�Ĵ������塣��QSPI���߳�ʱ���޶����������������nCS���Զ����ߣ�ǿ�ƽ�����ǰ������̡�
0���رճ�ʱ����
1��ʹ�ܳ�ʱ���� ��غ��� */
void QSPI_CR_TCEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		QSPI->CR |= (QSPI_CR_TCEN_Msk);
	}
	else
	{
		QSPI->CR &= ~(QSPI_CR_TCEN_Msk);
	}
}

FunState QSPI_CR_TCEN_Getable(void)
{
	if (QSPI->CR & (QSPI_CR_TCEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* DMAʹ��
0��DMA���ܹرգ�QuadSPI���ᷢ��DMA����
1��DMA���ܿ�����QuadSPI����������ʱ����DMA���� ��غ��� */
void QSPI_CR_DMAEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		QSPI->CR |= (QSPI_CR_DMAEN_Msk);
	}
	else
	{
		QSPI->CR &= ~(QSPI_CR_DMAEN_Msk);
	}
}

FunState QSPI_CR_DMAEN_Getable(void)
{
	if (QSPI->CR & (QSPI_CR_DMAEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��ǰ������ֹ�Ĵ��������д1��ֹ���䣬Ӳ������nCS���Զ����� ��غ��� */
void QSPI_CR_ABORT_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		QSPI->CR |= (QSPI_CR_ABORT_Msk);
	}
	else
	{
		QSPI->CR &= ~(QSPI_CR_ABORT_Msk);
	}
}

FunState QSPI_CR_ABORT_Getable(void)
{
	if (QSPI->CR & (QSPI_CR_ABORT_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* QuadSPIģ��ʹ��
0���ر�QuadSPI
1��ʹ��QuadSPI ��غ��� */
void QSPI_CR_EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		QSPI->CR |= (QSPI_CR_EN_Msk);
	}
	else
	{
		QSPI->CR &= ~(QSPI_CR_EN_Msk);
	}
}

FunState QSPI_CR_EN_Getable(void)
{
	if (QSPI->CR & (QSPI_CR_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* nCS��С�ߵ�ƽʱ�䣬��������������֮֡��nCS���豣�ָߵ�ƽ�����ʱ�䣬��QSPI_CLK���ڼ���
0������1 cycle
1������2 cycles
����
7������8 cycles ��غ��� */
void QSPI_CFG_CSHT_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = QSPI->CFG;
	tmpreg &= ~(QSPI_CFG_CSHT_Msk);
	tmpreg |= (SetValue & QSPI_CFG_CSHT_Msk);
	QSPI->CFG = tmpreg;
}

uint32_t QSPI_CFG_CSHT_Get(void)
{
	return (QSPI->CFG & QSPI_CFG_CSHT_Msk);
}

/* SPI Clock Mode�Ĵ���
0��mode 0
1��mode 3 ��غ��� */
void QSPI_CFG_CKMODE_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = QSPI->CFG;
	tmpreg &= ~(QSPI_CFG_CKMODE_Msk);
	tmpreg |= (SetValue & QSPI_CFG_CKMODE_Msk);
	QSPI->CFG = tmpreg;
}

uint32_t QSPI_CFG_CKMODE_Get(void)
{
	return (QSPI->CFG & QSPI_CFG_CKMODE_Msk);
}

/* FIFOˮλ��־
�˼Ĵ�����ʾ��ǰFIFO�б���������ֽ�����0��ʾFIFO�գ�16��ʾFIFO��
�Զ���ѯģʽ�´˼Ĵ�������0 ��غ��� */
uint32_t QSPI_SR_FIFOLVL_Get(void)
{
	return (QSPI->SR & QSPI_SR_FIFOLVL_Msk) >> QSPI_SR_FIFOLVL_Pos;
}

/* 1��ʾQuadSPI��������У�ͨ�Ž������Զ����� ��غ��� */
FlagStatus QSPI_SR_BUSY_Chk(void)
{
	if (QSPI->SR & QSPI_SR_BUSY_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��ʱ��־��Ӳ����λ�����д1���� ��غ��� */
void QSPI_SR_TOF_Clr(void)
{
	QSPI->SR = QSPI_SR_TOF_Msk;
}

FlagStatus QSPI_SR_TOF_Chk(void)
{
	if (QSPI->SR & QSPI_SR_TOF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* �Զ���ѯģʽ�±���״̬�Ĵ���ƥ��ɹ���Ӳ����λ�����д1���� ��غ��� */
void QSPI_SR_SMF_Clr(void)
{
	QSPI->SR = QSPI_SR_SMF_Msk;
}

FlagStatus QSPI_SR_SMF_Chk(void)
{
	if (QSPI->SR & QSPI_SR_SMF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* FIFO threshold��־��FIFOˮλ�����趨��ֵʱ�Զ���λ��������ֵʱ�Զ�����
�Զ���ѯģʽ�£�ÿ�ζ���һ��״ֵ̬�󶼻��Զ���λFTF����������ȡQSPI_DATA�Ĵ�����FTF���� ��غ��� */
FlagStatus QSPI_SR_FTF_Chk(void)
{
	if (QSPI->SR & QSPI_SR_FTF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ������ɱ�־��Ӳ����λ�����д1���� ��غ��� */
void QSPI_SR_TCF_Clr(void)
{
	QSPI->SR = QSPI_SR_TCF_Msk;
}

FlagStatus QSPI_SR_TCF_Chk(void)
{
	if (QSPI->SR & QSPI_SR_TCF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* �������ݳ���ΪDATALEN+1��bytes�� ��غ��� */
void QSPI_DATALEN_Write(uint32_t SetValue)
{
	QSPI->DATALEN = (SetValue);
}

uint32_t QSPI_DATALEN_Read(void)
{
	return (QSPI->DATALEN);
}

/* QuadSPI ͨ�ſ��ƼĴ��� ��غ��� */
void QSPI_CCR_Write(uint32_t SetValue)
{
    QSPI->CCR = (SetValue);
}

uint32_t QSPI_CCR_Read(void)
{
    return (QSPI->CCR);
}

/* ���͸�QSPI�洢���ĵ�ַ���ڴ洢��ӳ��ģʽ����Ч ��غ��� */
void QSPI_ADDR_Write(uint32_t SetValue)
{
	QSPI->ADDR = (SetValue);
}

uint32_t QSPI_ADDR_Read(void)
{
	return (QSPI->ADDR);
}

/* ���͸�QSPI�洢����alternate bytes ��غ��� */
void QSPI_ABR_Write(uint32_t SetValue)
{
	QSPI->ABR = (SetValue);
}

uint32_t QSPI_ABR_Read(void)
{
	return (QSPI->ABR);
}

/* QSPI���ݼĴ���
����ģʽд����ʱ����QSPI_DR�Ĵ���д������ݽ���push FIFO��֧���ֽڡ����֡���д�룬�ֱ��FIFOѹ��1��2��4�ֽڣ����д���ֽ�������FIFO�п��ֽ�������ǰд����������ֱ��FIFO�����㹻�ռ����ɵ�ǰд�����ݡ�
����ģʽ������ʱ����ȡQSPI_DR�Ĵ�����pop FIFO��֧���ֽڡ����֡��ֶ�ȡ���ֱ��FIFO����1��2��4�ֽڣ������ȡ�ֽ�������FIFO����Ч�ֽ�������ǰ������������ֱ��FIFO�����㹻�ֽڿ��Ա���ȡ�����ߴ�����ɣ���һ�������ֻ������󼸸�ʵ����Ч�ֽڡ�
��QSPI_DR�ķ��ʱ������͵�ַ�����ֽڷ��ʱ������QSPI_DR[7:0]�����ַ��ʱ������QSPI_DR[15:0] ��غ��� */
void QSPI_DR_WriteByte(uint8_t SetValue)
{
	*((uint8_t *)&(QSPI->DR)) = (SetValue);
}

uint8_t QSPI_DR_ReadByte(void)
{
	return (*((uint8_t *)&(QSPI->DR)));
}

void QSPI_DR_WriteHalfword(uint16_t SetValue)
{
	*((uint16_t *)&(QSPI->DR)) = (SetValue);
}

uint16_t QSPI_DR_ReadHalfword(void)
{
	return (*((uint16_t *)&(QSPI->DR)));
}

void QSPI_DR_WriteWord(uint32_t SetValue)
{
	*((uint32_t *)&(QSPI->DR)) = (SetValue);
}

uint32_t QSPI_DR_ReadWord(void)
{
	return (*((uint32_t *)&(QSPI->DR)));
}

/* �Զ�״̬��ѯģʽ�µ�״̬mask�Ĵ�������Ӧbitд0������Ӧ״̬λ ��غ��� */
void QSPI_SMSK_Write(uint32_t SetValue)
{
	QSPI->SMSK = (SetValue);
}

uint32_t QSPI_SMSK_Read(void)
{
	return (QSPI->SMSK);
}

/* �Զ�״̬��ѯģʽ�µ�״̬ƥ��Ĵ���
�Ƚ϶�����QSPI_DATA & QSPI_SMSK ��غ��� */
void QSPI_SMAT_Write(uint32_t SetValue)
{
	QSPI->SMAT = (SetValue);
}

uint32_t QSPI_SMAT_Read(void)
{
	return (QSPI->SMAT);
}

/* �Զ�״̬��ѯģʽ�µ���ѯ�����polling interval��������ΪQSPI_CLK������ ��غ��� */
void QSPI_PITV_Write(uint32_t SetValue)
{
	QSPI->PITV = (SetValue & QSPI_PITV_QSPI_PITV_Msk);
}

uint32_t QSPI_PITV_Read(void)
{
	return (QSPI->PITV & QSPI_PITV_QSPI_PITV_Msk);
}

/* ��ʱ�������ã�����ΪQSPI_CLK�����������ڴ洢��ӳ��ģʽ����Ч
��FIFO��֮��QSPI������Ϊֹͣ����ʱ��������ʼ����������ֵ����QSPI_TO�趨ֵ֮������nCS ��غ��� */
void QSPI_TO_Write(uint32_t SetValue)
{
	QSPI->TO = (SetValue & QSPI_TO_QSPI_TO_Msk);
}

uint32_t QSPI_TO_Read(void)
{
	return (QSPI->TO & QSPI_TO_QSPI_TO_Msk);
}


void QSPI_Deinit(void)
{
    
}

void QSPI_Init(void)
{
    
}

/******END OF FILE****/
