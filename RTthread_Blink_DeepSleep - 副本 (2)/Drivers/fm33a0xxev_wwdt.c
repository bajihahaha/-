/**
  ******************************************************************************
  * @file    fm33a0xxev_wwdt.c
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/

#include "fm33a0xxev_wwdt.h"

/** @addtogroup fm33a0xxev_StdPeriph_Driver
  * @{
  */

/** @defgroup WWDT 
  * @brief WWDT driver modules
  * @{
  */ 

/* ��CPU��˵�ַд��0x5Aʱ����WWDT��ʱ�� (WWDT Control,write only)
������WWDT�󣬵�CPU��˵�ַд��0xACʱ��������� ��غ��� */
void WWDT_CR_Write(uint32_t SetValue)
{
	WWDT->CR = (SetValue & WWDT_CR_CON_Msk);
}

/* ����WWDT���Ź����ʱ�䣬��λֵ011�������ϵ��ϵͳʱ��Ĭ��Ϊ8Mhz������Ĭ��������ڴ�Լ32ms (WWDT Config)
000��TPCLK * 4096 * 1
001��TPCLK * 4096 * 4
010��TPCLK * 4096 * 16
011��TPCLK * 4096 * 64
100��TPCLK * 4096 * 128
101��TPCLK * 4096 * 256
110��TPCLK * 4096 * 512
111��TPCLK * 4096 * 1024 ��غ��� */
void WWDT_CFGR_Write(uint32_t SetValue)
{
	WWDT->CFGR = (SetValue & WWDT_CFGR_CFG_Msk);
}

uint32_t WWDT_CFGR_Read(void)
{
	return (WWDT->CFGR & WWDT_CFGR_CFG_Msk);
}

/* WWDT�����Ĵ���ֵ�������ͨ����ѯ�˼Ĵ����˽�WWDT��ʱ���� (WWDT Counter value,read only) ��غ��� */
uint32_t WWDT_CNTR_Read(void)
{
	return (WWDT->CNTR & WWDT_CNTR_CNT_Msk);
}

/* WWDT�ж�ʹ�� (WWDT Interrupt Enable)
0���ж�ʹ�ܽ�ֹ
1���ж�ʹ�ܴ� ��غ��� */
void WWDT_IER_IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		WWDT->IER |= (WWDT_IER_IE_Msk);
	}
	else
	{
		WWDT->IER &= ~(WWDT_IER_IE_Msk);
	}
}

FunState WWDT_IER_IE_Getable(void)
{
	if (WWDT->IER & (WWDT_IER_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* WWDT 75%��ʱ�жϱ�־��д1���� (Near Overflow Flag,write 1 to clear)
0�����жϲ���
1���жϱ�־��λ
���IE=1����˼Ĵ�����λ�������ж� ��غ��� */
void WWDT_ISR_NOVF_Clr(void)
{
	WWDT->ISR = WWDT_ISR_NOVF_Msk;
}

FlagStatus WWDT_ISR_NOVF_Chk(void)
{
	if (WWDT->ISR & WWDT_ISR_NOVF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* WWDT��4096Ԥ��Ƶ��������ǰ����ֵ��ֻ�� (WWDT prescaler Divider Counte,read only) ��غ��� */
uint32_t WWDT_PSCR_Read(void)
{
	return (WWDT->PSCR & WWDT_PSCR_DIV_CNT_Msk);
}


void WWDT_Deinit(void)
{
	//WWDT->CR = 0x00000000;
	//WWDT->CFGR = 0x00000003;
	//WWDT->CNTR = 0x00000000;
	//WWDT->IER = 0x00000000;
	//WWDT->ISR = 0x00000000;
	//WWDT->PSCR = 0x00000000;
}

/******END OF FILE****/
