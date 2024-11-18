/**
  ******************************************************************************
  * @file    fm33a0xxev_comp.c
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/

#include "fm33a0xxev_comp.h"

/** @addtogroup fm33a0xxev_StdPeriph_Driver
  * @{
  */

/** @defgroup COMP 
  * @brief COMP driver modules
  * @{
  */ 

/* �Ƚ���1��������˲��������üĴ������˲�����������DFLEN+1
00010��3��APBCLK����
����
11111��32��APBCLK���� ��غ��� */
void COMP_CR1_DFLEN_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = COMP->CR1;
	tmpreg &= ~(COMP_CR1_DFLEN_Msk);
	tmpreg |= (SetValue & COMP_CR1_DFLEN_Msk);
	COMP->CR1 = tmpreg;
}

uint32_t COMP_CR1_DFLEN_Get(void)
{
	return (COMP->CR1 & COMP_CR1_DFLEN_Msk);
}

/* �Ƚ���1����ģʽ���ƼĴ���
0����ֹ����ģʽ
1��ʹ�ܴ���ģʽ ��غ��� */
void COMP_CR1_WINMODE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		COMP->CR1 |= (COMP_CR1_WINMODE_Msk);
	}
	else
	{
		COMP->CR1 &= ~(COMP_CR1_WINMODE_Msk);
	}
}

FunState COMP_CR1_WINMODE_Getable(void)
{
	if (COMP->CR1 & (COMP_CR1_WINMODE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �Ƚ���1������Կ���
0���������
1��ȡ����� ��غ��� */
void COMP_CR1_POLAR_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = COMP->CR1;
	tmpreg &= ~(COMP_CR1_POLAR_Msk);
	tmpreg |= (SetValue & COMP_CR1_POLAR_Msk);
	COMP->CR1 = tmpreg;
}

uint32_t COMP_CR1_POLAR_Get(void)
{
	return (COMP->CR1 & COMP_CR1_POLAR_Msk);
}

/* �Ƚ���1��������˲�ʹ��
0����ֹ��������˲�
1��ʹ����������˲� ��غ��� */
void COMP_CR1_DFEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		COMP->CR1 |= (COMP_CR1_DFEN_Msk);
	}
	else
	{
		COMP->CR1 &= ~(COMP_CR1_DFEN_Msk);
	}
}

FunState COMP_CR1_DFEN_Getable(void)
{
	if (COMP->CR1 & (COMP_CR1_DFEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �Ƚ���1����������˲�ǰ�������ֻ�� ��غ��� */
FlagStatus COMP_CR1_CMP1OR_Chk(void)
{
	if (COMP->CR1 & COMP_CR1_CMP1OR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* �Ƚ���1����������˲��󣩣����ֻ�� ��غ��� */
FlagStatus COMP_CR1_CMP1OF_Chk(void)
{
	if (COMP->CR1 & COMP_CR1_CMP1OF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* �Ƚ���1��������ѡ��
000��COMP1_INN1
001��COMP1_INN2
010��VREF
011��3/4 VREF
100��1/2 VREF
101��1/4 VREF
110��1/8 VREF
111��RFU ��غ��� */
void COMP_CR1_V1NSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = COMP->CR1;
	tmpreg &= ~(COMP_CR1_V1NSEL_Msk);
	tmpreg |= (SetValue & COMP_CR1_V1NSEL_Msk);
	COMP->CR1 = tmpreg;
}

uint32_t COMP_CR1_V1NSEL_Get(void)
{
	return (COMP->CR1 & COMP_CR1_V1NSEL_Msk);
}

/* �Ƚ���1��������ѡ��
00��COMP1_INP1
01��COMP1_INP2
10��COMP1_INP3
11��COMP1_INP4 ��غ��� */
void COMP_CR1_V1PSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = COMP->CR1;
	tmpreg &= ~(COMP_CR1_V1PSEL_Msk);
	tmpreg |= (SetValue & COMP_CR1_V1PSEL_Msk);
	COMP->CR1 = tmpreg;
}

uint32_t COMP_CR1_V1PSEL_Get(void)
{
	return (COMP->CR1 & COMP_CR1_V1PSEL_Msk);
}

/* �Ƚ���1ʹ��λ
0���رձȽ���1
1��ʹ�ܱȽ���1 ��غ��� */
void COMP_CR1_CMP1EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		COMP->CR1 |= (COMP_CR1_CMP1EN_Msk);
	}
	else
	{
		COMP->CR1 &= ~(COMP_CR1_CMP1EN_Msk);
	}
}

FunState COMP_CR1_CMP1EN_Getable(void)
{
	if (COMP->CR1 & (COMP_CR1_CMP1EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �Ƚ���2��������˲��������üĴ������˲�����������DFLEN+1
00010��3��APBCLK����
����
11111��32��APBCLK���� ��غ��� */
void COMP_CR2_DFLEN_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = COMP->CR2;
	tmpreg &= ~(COMP_CR2_DFLEN_Msk);
	tmpreg |= (SetValue & COMP_CR2_DFLEN_Msk);
	COMP->CR2 = tmpreg;
}

uint32_t COMP_CR2_DFLEN_Get(void)
{
	return (COMP->CR2 & COMP_CR2_DFLEN_Msk);
}

/* �Ƚ���2��������˲�ʹ��
0����ֹ��������˲�
1��ʹ����������˲� ��غ��� */
void COMP_CR2_DFEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		COMP->CR2 |= (COMP_CR2_DFEN_Msk);
	}
	else
	{
		COMP->CR2 &= ~(COMP_CR2_DFEN_Msk);
	}
}

FunState COMP_CR2_DFEN_Getable(void)
{
	if (COMP->CR2 & (COMP_CR2_DFEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}


/* �Ƚ���2����ģʽ���ƼĴ���
0����ֹ����ģʽ
1��ʹ�ܴ���ģʽ ��غ��� */
void COMP_CR2_WINMODE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		COMP->CR2 |= (COMP_CR2_WINMODE_Msk);
	}
	else
	{
		COMP->CR2 &= ~(COMP_CR2_WINMODE_Msk);
	}
}

FunState COMP_CR2_WINMODE_Getable(void)
{
	if (COMP->CR2 & (COMP_CR2_WINMODE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �Ƚ���2������Կ���
0���������
1��ȡ����� ��غ��� */
void COMP_CR2_POLAR_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = COMP->CR2;
	tmpreg &= ~(COMP_CR2_POLAR_Msk);
	tmpreg |= (SetValue & COMP_CR2_POLAR_Msk);
	COMP->CR2 = tmpreg;
}

uint32_t COMP_CR2_POLAR_Get(void)
{
	return (COMP->CR2 & COMP_CR2_POLAR_Msk);
}


/* �Ƚ���2����������˲�ǰ�������ֻ�� ��غ��� */
FlagStatus COMP_CR2_CMP2OR_Chk(void)
{
	if (COMP->CR2 & COMP_CR2_CMP2OR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* �Ƚ���2����������˲��󣩣����ֻ�� ��غ��� */
FlagStatus COMP_CR2_CMP2OF_Chk(void)
{
	if (COMP->CR2 & COMP_CR2_CMP2OF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}


/* �Ƚ���2��������ѡ��
000��COMP2_INN1
001��COMP2_INN2
010��VREF
011��3/4 VREF
100��1/2 VREF
101��1/4 VREF
110��1/8 VREF
111��REFIN(PD6) */
void COMP_CR2_V2NSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = COMP->CR2;
	tmpreg &= ~(COMP_CR2_V2NSEL_Msk);
	tmpreg |= (SetValue & COMP_CR2_V2NSEL_Msk);
	COMP->CR2 = tmpreg;
}

uint32_t COMP_CR2_V2NSEL_Get(void)
{
	return (COMP->CR2 & COMP_CR2_V2NSEL_Msk);
}

/* �Ƚ���2��������ѡ��
000��COMP2_INP1
001��COMP2_INP2
010��COMP1_INP1
011��COMP1_INP2
100��AVREF
101��VDD15
110, 111��RFU ��غ��� */
void COMP_CR2_V2PSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = COMP->CR2;
	tmpreg &= ~(COMP_CR2_V2PSEL_Msk);
	tmpreg |= (SetValue & COMP_CR2_V2PSEL_Msk);
	COMP->CR2 = tmpreg;
}

uint32_t COMP_CR2_V2PSEL_Get(void)
{
	return (COMP->CR2 & COMP_CR2_V2PSEL_Msk);
}

/* �Ƚ���2ʹ��λ
0���رձȽ���2
1��ʹ�ܱȽ���2 ��غ��� */
void COMP_CR2_CMP2EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		COMP->CR2 |= (COMP_CR2_CMP2EN_Msk);
	}
	else
	{
		COMP->CR2 &= ~(COMP_CR2_CMP2EN_Msk);
	}
}

FunState COMP_CR2_CMP2EN_Getable(void)
{
	if (COMP->CR2 & (COMP_CR2_CMP2EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Out-Of-Window�ж�ʹ�� ��غ��� */
void COMP_ICR_OOW_IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		COMP->ICR |= (COMP_ICR_OOW_IE_Msk);
	}
	else
	{
		COMP->ICR &= ~(COMP_ICR_OOW_IE_Msk);
	}
}

FunState COMP_ICR_OOW_IE_Getable(void)
{
	if (COMP->ICR & (COMP_ICR_OOW_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Window�ж�ʹ�� ��غ��� */
void COMP_ICR_WIN_IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		COMP->ICR |= (COMP_ICR_WIN_IE_Msk);
	}
	else
	{
		COMP->ICR &= ~(COMP_ICR_WIN_IE_Msk);
	}
}

FunState COMP_ICR_WIN_IE_Getable(void)
{
	if (COMP->ICR & (COMP_ICR_WIN_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �Ƚ���Buffer Bypass
0����Bypass�Ƚ���Buffer
1��Bypass�Ƚ���Buffer ��غ��� */
void COMP_ICR_BUFBYP_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		COMP->ICR |= (COMP_ICR_BUFBYP_Msk);
	}
	else
	{
		COMP->ICR &= ~(COMP_ICR_BUFBYP_Msk);
	}
}

FunState COMP_ICR_BUFBYP_Getable(void)
{
	if (COMP->ICR & (COMP_ICR_BUFBYP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �Ƚ���Bufferʹ��
0��ʹ�ܱȽ���Buffer
1����ֹ�Ƚ���Buffer ��غ��� */
void COMP_ICR_BUF_OFF_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		COMP->ICR |= (COMP_ICR_BUF_OFF_Msk);
	}
	else
	{
		COMP->ICR &= ~(COMP_ICR_BUF_OFF_Msk);
	}
}

FunState COMP_ICR_BUF_OFF_Getable(void)
{
	if (COMP->ICR & (COMP_ICR_BUF_OFF_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �Ƚ���2�ж�Դѡ��
00/11���Ƚ���2����������½��ز����ж�
01���Ƚ���2��������ز����ж�
10���Ƚ���2����½��ز����ж� ��غ��� */
void COMP_ICR_CMP2SEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = COMP->ICR;
	tmpreg &= ~(COMP_ICR_CMP2SEL_Msk);
	tmpreg |= (SetValue & COMP_ICR_CMP2SEL_Msk);
	COMP->ICR = tmpreg;
}

uint32_t COMP_ICR_CMP2SEL_Get(void)
{
	return (COMP->ICR & COMP_ICR_CMP2SEL_Msk);
}

/* �Ƚ���1�ж�Դѡ��
00/11���Ƚ���1����������½��ز����ж�
01���Ƚ���1��������ز����ж�
10���Ƚ���1����½��ز����ж� ��غ��� */
void COMP_ICR_CMP1SEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = COMP->ICR;
	tmpreg &= ~(COMP_ICR_CMP1SEL_Msk);
	tmpreg |= (SetValue & COMP_ICR_CMP1SEL_Msk);
	COMP->ICR = tmpreg;
}

uint32_t COMP_ICR_CMP1SEL_Get(void)
{
	return (COMP->ICR & COMP_ICR_CMP1SEL_Msk);
}

/* �Ƚ���2�ж�ʹ�� ��غ��� */
void COMP_ICR_CMP2IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		COMP->ICR |= (COMP_ICR_CMP2IE_Msk);
	}
	else
	{
		COMP->ICR &= ~(COMP_ICR_CMP2IE_Msk);
	}
}

FunState COMP_ICR_CMP2IE_Getable(void)
{
	if (COMP->ICR & (COMP_ICR_CMP2IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �Ƚ���1�ж�ʹ�� ��غ��� */
void COMP_ICR_CMP1IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		COMP->ICR |= (COMP_ICR_CMP1IE_Msk);
	}
	else
	{
		COMP->ICR &= ~(COMP_ICR_CMP1IE_Msk);
	}
}

FunState COMP_ICR_CMP1IE_Getable(void)
{
	if (COMP->ICR & (COMP_ICR_CMP1IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Out-of-Window�жϱ�־��Ӳ����λ�����д1���� ��غ��� */
void COMP_ISR_OOW_IF_Clr(void)
{
	COMP->ISR = COMP_ISR_OOW_IF_Msk;
}

FlagStatus COMP_ISR_OOW_IF_Chk(void)
{
	if (COMP->ISR & COMP_ISR_OOW_IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* Window�жϱ�־��Ӳ����λ�����д1���� ��غ��� */
void COMP_ISR_WIN_IF_Clr(void)
{
	COMP->ISR = COMP_ISR_WIN_IF_Msk;
}

FlagStatus COMP_ISR_WIN_IF_Chk(void)
{
	if (COMP->ISR & COMP_ISR_WIN_IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* �Ƚ���2�жϱ�־��Ӳ����λ�����д1���� ��غ��� */
void COMP_ISR_CMP2IF_Clr(void)
{
	COMP->ISR = COMP_ISR_CMP2IF_Msk;
}

FlagStatus COMP_ISR_CMP2IF_Chk(void)
{
	if (COMP->ISR & COMP_ISR_CMP2IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* �Ƚ���1�жϱ�־��Ӳ����λ�����д1���� ��غ��� */
void COMP_ISR_CMP1IF_Clr(void)
{
	COMP->ISR = COMP_ISR_CMP1IF_Msk;
}

FlagStatus COMP_ISR_CMP1IF_Chk(void)
{
	if (COMP->ISR & COMP_ISR_CMP1IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* �Ƚ���BUFFER����ģʽ
0���͹���ģʽ
1������ģʽ ��غ��� */
void COMP_PCR_HSCMPBUF_EN_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = COMP->PCR;
	tmpreg &= ~(COMP_PCR_HSCMPBUF_EN_Msk);
	tmpreg |= (SetValue & COMP_PCR_HSCMPBUF_EN_Msk);
	COMP->PCR = tmpreg;
}

uint32_t COMP_PCR_HSCMPBUF_EN_Get(void)
{
	return (COMP->PCR & COMP_PCR_HSCMPBUF_EN_Msk);
}


/* �Ƚ���2����ģʽ
0���͹���ģʽ
1������ģʽ ��غ��� */
void COMP_PCR_HSCMP2_EN_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = COMP->PCR;
	tmpreg &= ~(COMP_PCR_HSCMP2_EN_Msk);
	tmpreg |= (SetValue & COMP_PCR_HSCMP2_EN_Msk);
	COMP->PCR = tmpreg;
}

uint32_t COMP_PCR_HSCMP2_EN_Get(void)
{
	return (COMP->PCR & COMP_PCR_HSCMP2_EN_Msk);
}

/* �Ƚ���1����ģʽ
0���͹���ģʽ
1������ģʽ ��غ��� */
void COMP_PCR_HSCMP1_EN_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = COMP->PCR;
	tmpreg &= ~(COMP_PCR_HSCMP1_EN_Msk);
	tmpreg |= (SetValue & COMP_PCR_HSCMP1_EN_Msk);
	COMP->PCR = tmpreg;
}

uint32_t COMP_PCR_HSCMP1_EN_Get(void)
{
	return (COMP->PCR & COMP_PCR_HSCMP1_EN_Msk);
}

void COMP_Deinit(void)
{
	//COMP->CR1 = 0x00000000;
	//COMP->CR2 = 0x00000000;
	//COMP->ICR = ;
	//COMP->ISR = 0x00000000;
}
/******END OF FILE****/
