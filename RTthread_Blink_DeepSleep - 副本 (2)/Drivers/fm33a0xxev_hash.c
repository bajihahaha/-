/**
  ******************************************************************************
  * @file    fm33a0xxev_hash.c
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/

#include "fm33a0xxev_hash.h"

/** @addtogroup fm33a0xxev_StdPeriph_Driver
  * @{
  */

/** @defgroup HASH 
  * @brief HASH driver modules
  * @{
  */ 

/* HASH���������Ĵ��������д1�������㣬���������Ӳ���Զ����� ��غ��� */
void HASH_CSR_START_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		HASH->CSR |= (HASH_CSR_START_Msk);
	}
	else
	{
		HASH->CSR &= ~(HASH_CSR_START_Msk);
	}
}

FunState HASH_CSR_START_Getable(void)
{
	if (HASH->CSR & (HASH_CSR_START_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* SHA�㷨ѡ�� ��غ��� */
void HASH_CSR_HASHSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = HASH->CSR;
	tmpreg &= ~(HASH_CSR_HASHSEL_Msk);
	tmpreg |= (SetValue & HASH_CSR_HASHSEL_Msk);
	HASH->CSR = tmpreg;
}

uint32_t HASH_CSR_HASHSEL_Get(void)
{
	return (HASH->CSR & HASH_CSR_HASHSEL_Msk);
}

/* ������������˳�򽻻�����
00��������
01��half-word����
10��byte����
11��bit����
�˼Ĵ������ڶ�����32bit���ݵ�λ����е�������������Ϊ0x1234_5678��half-word������Ϊ0x5678_1234��byte������Ϊ0x7856_3412��bit������Ϊ0x1E6A_2C48
 ��غ��� */
void HASH_DTR_DATA_TYPE_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = HASH->DTR;
	tmpreg &= ~(HASH_DTR_DATA_TYPE_Msk);
	tmpreg |= (SetValue & HASH_DTR_DATA_TYPE_Msk);
	HASH->DTR = tmpreg;
}

uint32_t HASH_DTR_DATA_TYPE_Get(void)
{
	return (HASH->DTR & HASH_DTR_DATA_TYPE_Msk);
}


void HASH_Deinit(void)
{
	//HASH->CSR = 0x00000000;
	//HASH->DTR = 0x00000000;
}

/******END OF FILE****/
