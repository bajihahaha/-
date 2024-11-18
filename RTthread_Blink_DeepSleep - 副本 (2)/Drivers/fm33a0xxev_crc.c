/**
  ******************************************************************************
  * @file    fm33a0xxev_crc.c
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/

#include "fm33a0xxev_crc.h"

/** @addtogroup fm33a0xxev_StdPeriph_Driver
  * @{
  */

/** @defgroup CRC 
  * @brief CRC driver modules
  * @{
  */ 

/* CRCDR������Ϊ��������Ĵ�������������������󱣴�CRC��������(CRC Data Register)
��Ϊ����ʱ����word����ʹ�ܣ����CRCDR[31:0]���м��㣬��4��byte���㣨�ɵ͵��ߣ��������CRCDR[7:0]���м��㣬��1��byte���㡣
������ʱ����Ϊ7λ����ʽ���������CRCDR[6:0]����Ϊ8λ����ʽ���������CRCDR[7:0]����Ϊ16λ����ʽ���������CRCDR[15:0]����Ϊ32λ����ʽ���������CRCDR[31:0]�� ��غ��� */
void CRC_DR_Write(uint32_t SetValue)
{
	CRC->DR = (SetValue);
}

uint32_t CRC_DR_Read(void)
{
	return (CRC->DR);
}

/* WORD����ʹ�� (Operation by Word)
0���ֽڲ�����CRC��������CRCDR����ֽڽ���
1���ֲ�����CRC�������CRCDRȫ��4�ֽڽ��� ��غ��� */
void CRC_CR_OPWD_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = CRC->CR;
	tmpreg &= ~(CRC_CR_OPWD_Msk);
	tmpreg |= (SetValue & CRC_CR_OPWD_Msk);
	CRC->CR = tmpreg;
}

uint32_t CRC_CR_OPWD_Get(void)
{
	return (CRC->CR & CRC_CR_OPWD_Msk);
}

/* CRC���ټ���ʹ�� (Parallel Calculation)
0���������㣬����1���ֽ���Ҫ8��ʱ������
1�����м��㣬����1���ֽ���Ҫ1��ʱ������ ��غ��� */
void CRC_CR_PARA_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = CRC->CR;
	tmpreg &= ~(CRC_CR_PARA_Msk);
	tmpreg |= (SetValue & CRC_CR_PARA_Msk);
	CRC->CR = tmpreg;
}

uint32_t CRC_CR_PARA_Get(void)
{
	return (CRC->CR & CRC_CR_PARA_Msk);
}

/* CRC���뷴ת���� (Reflected Input)
00�����벻��ת
01�����밴�ֽڷ�ת
10�����밴���ַ�ת
11�����밴�ַ�ת
���磺��������Ϊ0x11223344��
���RFLTIN==01�������ݱ�Ϊ0x8844CC22���ٽ��м������RFLTIN==10�������ݱ�Ϊ0x448822CC���ٽ��м���
���RFLTIN==11�������ݱ�Ϊ0x22CC4488���ٽ��м��� ��غ��� */
void CRC_CR_RFLTIN_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = CRC->CR;
	tmpreg &= ~(CRC_CR_RFLTIN_Msk);
	tmpreg |= (SetValue & CRC_CR_RFLTIN_Msk);
	CRC->CR = tmpreg;
}

uint32_t CRC_CR_RFLTIN_Get(void)
{
	return (CRC->CR & CRC_CR_RFLTIN_Msk);
}

/* CRC�����ת���� (Reflected Output)
0�����벻��ת
1�����밴�ֽڷ�ת
���磺
���RFLTO==1������ǰ�����CRC���Ϊ0x1234��������Ľ��Ϊ0x2C48��� RFLTO==0����ֱ�����0x1234ע�⣺�˽����һ��Ϊ����������������Ҫ��XOR�Ƿ�Ϊ1��������Ĵ���bit2˵�� ��غ��� */
void CRC_CR_RFLTO_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = CRC->CR;
	tmpreg &= ~(CRC_CR_RFLTO_Msk);
	tmpreg |= (SetValue & CRC_CR_RFLTO_Msk);
	CRC->CR = tmpreg;
}

uint32_t CRC_CR_RFLTO_Get(void)
{
	return (CRC->CR & CRC_CR_RFLTO_Msk);
}

/* CRC�����־λ��ֻ�� (Result Flag)
0��CRC���Ϊ0
1��CRC�����ȫ0 ��غ��� */
FlagStatus CRC_CR_RES_Chk(void)
{
	if (CRC->CR & CRC_CR_RES_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* CRC�����־λ��ֻ�� (Busy)
0��CRC�������
1��CRC��������� ��غ��� */
FlagStatus CRC_CR_BUSY_Chk(void)
{
	if (CRC->CR & CRC_CR_BUSY_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ������ʹ�� (Output XORed with CRC_XOR register enable)
0����������CRC_XOR�Ĵ���
1��������CRC_XOR�Ĵ��� ��غ��� */
void CRC_CR_XOR_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		CRC->CR |= (CRC_CR_XOR_Msk);
	}
	else
	{
		CRC->CR &= ~(CRC_CR_XOR_Msk);
	}
}

FunState CRC_CR_XOR_Getable(void)
{
	if (CRC->CR & (CRC_CR_XOR_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* CRC����ʽλ��ѡ�� (Polynomial width Selection)
00��32λ
01��16λ
10��8λ
11��7λ ��غ��� */
void CRC_CR_SEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = CRC->CR;
	tmpreg &= ~(CRC_CR_SEL_Msk);
	tmpreg |= (SetValue & CRC_CR_SEL_Msk);
	CRC->CR = tmpreg;
}

uint32_t CRC_CR_SEL_Get(void)
{
	return (CRC->CR & CRC_CR_SEL_Msk);
}

/* CRC���Է�����λ�Ĵ��� (Linear Feedback Shift Register)
���㿪ʼǰ���������д��CRC��ʼֵ ��غ��� */
void CRC_LFSR_Write(uint32_t SetValue)
{
	CRC->LFSR = (SetValue);
}

uint32_t CRC_LFSR_Read(void)
{
	return (CRC->LFSR);
}

/* CRC���������Ĵ��� (eXclusive OR)
��CRC_CR.XORΪ1ʱ��CRC������ǰ�����˼Ĵ��������ݡ� ��غ��� */
void CRC_XOR_Write(uint32_t SetValue)
{
	CRC->XOR = (SetValue);
}

uint32_t CRC_XOR_Read(void)
{
	return (CRC->XOR);
}

/* CRC�������ʽϵ�� (CRC Polynominals) ��غ��� */
void CRC_POLY_Write(uint32_t SetValue)
{
	CRC->POLY = (SetValue);
}

uint32_t CRC_POLY_Read(void)
{
	return (CRC->POLY);
}


void CRC_Deinit(void)
{
	//CRC->DR = 0xFFFFFFFF;
	//CRC->CR = 0x00000002;
	//CRC->LFSR = 0xFFFFFFFF;
	//CRC->XOR = 0x00000000;
	//CRC->POLY = 0x00000000;
}
//Code_End

/* CRC��ʼ�����ú���*/
void CRC_Init(CRC_InitTypeDef* para)
{
	CRC_LFSR_Write(para->LFSR);				/*!<��ֵ�Ĵ���*/
	CRC_CR_SEL_Set(para->CRCSEL);			/*!<CRCУ�����ʽλ��ѡ��*/
	CRC_CR_OPWD_Set(para->OPWD);			/*!<WORD����ʹ��*/
	CRC_CR_PARA_Set(para->PARA);			/*!<CRC���ټ���ʹ��*/
	CRC_CR_RFLTIN_Set(para->RFLTIN);	    /*!<CRC���뷴ת����*/
	CRC_CR_RFLTO_Set(para->RFLTO);		    /*!<CRC�����ת����*/
	CRC_CR_XOR_Setable(para->XOR);		    /*!<������ʹ��*/
	CRC_XOR_Write(para->CRC_XOR);			/*!<���������Ĵ���*/
	CRC_POLY_Write(para->CRCPOLY);		    /*!<CRC����ʽ�Ĵ���*/
}

/******END OF FILE****/
