/**
  ******************************************************************************
  * @file    fm33a0xxev_rng.c
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/

#include "fm33a0xxev_rng.h"

/** @addtogroup fm33a0xxev_StdPeriph_Driver
  * @{
  */

/** @defgroup RNG 
  * @brief RNG driver modules
  * @{
  */ 

/* RNGʹ�ܼĴ��������д1���� (RNG enable)
1������RNG
0���ر�RNG ��غ��� */
void RNG_CR_EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RNG->CR |= (RNG_CR_EN_Msk);
	}
	else
	{
		RNG->CR &= ~(RNG_CR_EN_Msk);
	}
}

FunState RNG_CR_EN_Getable(void)
{
	if (RNG->CR & (RNG_CR_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��������ɽ����CRC�������Ĵ�����ֻ��
(RNG output) ��غ��� */
uint32_t RNG_DOR_Read(void)
{
	return (RNG->DOR);
}

/* LFSR״̬��־��ֻ�� (LFSR enable)
1��LFSR�������У����ɽ���CRC��֤
0��LFSR���������У��ɽ���CRC��֤
ע�����Ĵ�����������ģ���жϣ�������ѯ ��غ��� */
FlagStatus RNG_SR_LFSREN_Chk(void)
{
	if (RNG->SR & (RNG_SR_LFSREN_Msk))
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ���������ʧ�ܱ�־�����д1���� (Random Number Fail)
1�������δ��ͨ���������
0�������ͨ��������� ��غ��� */
void RNG_SR_RNF_Clr(void)
{
	RNG->SR = RNG_SR_RNF_Msk;
}

FlagStatus RNG_SR_RNF_Chk(void)
{
	if (RNG->SR & RNG_SR_RNF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* CRCʹ�ܿ��ƼĴ��������д1����CRC��������ɺ�Ӳ���Զ����� (CRC enable)
1��CRCʹ��
0��CRC�ر� ��غ��� */
void RNG_CRC_CR_CRCEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RNG->CRC_CR |= (RNG_CRC_CR_CRCEN_Msk);
	}
	else
	{
		RNG->CRC_CR &= ~(RNG_CRC_CR_CRCEN_Msk);
	}
}

FunState RNG_CRC_CR_CRCEN_Getable(void)
{
	if (RNG->CRC_CR & (RNG_CRC_CR_CRCEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* CRC������������Ĵ��� (CRC data input) ��غ��� */
void RNG_CRC_DIR_Write(uint32_t SetValue)
{
	RNG->CRC_DIR = (SetValue);
}

uint32_t RNG_CRC_DIR_Read(void)
{
	return (RNG->CRC_DIR);
}

/* CRC������ɱ�־�����д0���� (CRC calculation done)
1��CRC�������
0��CRC����δ��� ��غ��� */
void RNG_CRC_SR_CRCDONE_Clr(void)
{
	RNG->CRC_SR &= ~(RNG_CRC_SR_CRCDONE_Msk);
}

FlagStatus RNG_CRC_SR_CRCDONE_Chk(void)
{
	if (RNG->CRC_SR & RNG_CRC_SR_CRCDONE_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}


void RNG_Deinit(void)
{
	//RNG->CR = 0x00000000;
	//RNG->DOR = 0x00000000;
	//RNG->SR = 0x00000000;
	//RNG->CRC_CR = 0x00000000;
	//RNG->CRC_DIR = 0xFFFFFFFF;
	//RNG->CRC_SR = 0x00000000;
}

/******END OF FILE****/
