/**
  ******************************************************************************
  * @file    fm33a0xxev_cmu.c
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/

#include "fm33a0xxev_cmu.h"

/** @addtogroup fm33a0xxev_StdPeriph_Driver
  * @{
  */

/** @defgroup CMU 
  * @brief CMU driver modules
  * @{
  */ 

void CMU_SYSCLKCR_SLP_ENEXTI_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		CMU->SYSCLKCR |= (CMU_SYSCLKCR_SLP_ENEXTI_Msk);
	}
	else
	{
		CMU->SYSCLKCR &= ~(CMU_SYSCLKCR_SLP_ENEXTI_Msk);
	}
}

FunState CMU_SYSCLKCR_SLP_ENEXTI_Getable(void)
{
	if (CMU->SYSCLKCR & (CMU_SYSCLKCR_SLP_ENEXTI_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* APBʱ�ӷ�Ƶѡ�� (APBbus clock Prescaler)
000/001/010/011������Ƶ
100��2��Ƶ
101��4��Ƶ
110��8��Ƶ
111��16��Ƶ ��غ��� */
void CMU_SYSCLKCR_APBPRES_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = CMU->SYSCLKCR;
	tmpreg &= ~(CMU_SYSCLKCR_APBPRES_Msk);
	tmpreg |= (SetValue & CMU_SYSCLKCR_APBPRES_Msk);
	CMU->SYSCLKCR = tmpreg;
}

uint32_t CMU_SYSCLKCR_APBPRES_Get(void)
{
	return (CMU->SYSCLKCR & CMU_SYSCLKCR_APBPRES_Msk);
}

/* AHBʱ�ӷ�Ƶѡ�� (AHB bus clock Prescaler)
000/001/010/011������Ƶ
100��2��Ƶ
101��4��Ƶ
110��8��Ƶ
111��16��Ƶ ��غ��� */
void CMU_SYSCLKCR_AHBPRES_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = CMU->SYSCLKCR;
	tmpreg &= ~(CMU_SYSCLKCR_AHBPRES_Msk);
	tmpreg |= (SetValue & CMU_SYSCLKCR_AHBPRES_Msk);
	CMU->SYSCLKCR = tmpreg;
}

uint32_t CMU_SYSCLKCR_AHBPRES_Get(void)
{
	return (CMU->SYSCLKCR & CMU_SYSCLKCR_AHBPRES_Msk);
}

/* CPU�ں�systick����ʱ��ѡ�� (Systick clock select)
00��SCLK
01��LSCLK
10��RC4M
11��SYSCLK ��غ��� */
void CMU_SYSCLKCR_STCLKSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = CMU->SYSCLKCR;
	tmpreg &= ~(CMU_SYSCLKCR_STCLKSEL_Msk);
	tmpreg |= (SetValue & CMU_SYSCLKCR_STCLKSEL_Msk);
	CMU->SYSCLKCR = tmpreg;
}

uint32_t CMU_SYSCLKCR_STCLKSEL_Get(void)
{
	return (CMU->SYSCLKCR & CMU_SYSCLKCR_STCLKSEL_Msk);
}

/* ϵͳʱ��Դѡ�� ��غ��� */
void CMU_SYSCLKCR_SYSCLKSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = CMU->SYSCLKCR;
	tmpreg &= ~(CMU_SYSCLKCR_SYSCLKSEL_Msk);
	tmpreg |= (SetValue & CMU_SYSCLKCR_SYSCLKSEL_Msk);
	CMU->SYSCLKCR = tmpreg;
}

uint32_t CMU_SYSCLKCR_SYSCLKSEL_Get(void)
{
	return (CMU->SYSCLKCR & CMU_SYSCLKCR_SYSCLKSEL_Msk);
}

/* RCHFƵ��ѡ��Ĵ���0000��8MHz
0001��16MHz
0010��24MHz
0011��32MHz
0111��40MHz
1111��48MHz
������RFU ��غ��� */
void CMU_RCHFCR_FSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = CMU->RCHFCR;
	tmpreg &= ~(CMU_RCHFCR_FSEL_Msk);
	tmpreg |= (SetValue & CMU_RCHFCR_FSEL_Msk);
	CMU->RCHFCR = tmpreg;
}

uint32_t CMU_RCHFCR_FSEL_Get(void)
{
	return (CMU->RCHFCR & CMU_RCHFCR_FSEL_Msk);
}

/* RCHFʹ�ܼĴ��� (RCHF Enable)
1��ʹ��RCHF
0���ر�RCHF ��غ��� */
void CMU_RCHFCR_RCHFEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		CMU->RCHFCR |= (CMU_RCHFCR_RCHFEN_Msk);
	}
	else
	{
		CMU->RCHFCR &= ~(CMU_RCHFCR_RCHFEN_Msk);
	}
}

FunState CMU_RCHFCR_RCHFEN_Getable(void)
{
	if (CMU->RCHFCR & (CMU_RCHFCR_RCHFEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* RCHFƵ�ʵ�У�Ĵ�����8��h00��ʾƵ����ͣ�8��hFF��ʾƵ����ߣ���У��ΧΪ����Ƶ��+/-30%����У����Ϊ����Ƶ��0.25%
�ϵ��оƬ�Զ���LDT0��ȡ8MHz��Уֵ��д��˼Ĵ���
���ʹ������Ƶ��ʱ���������д�LDT0ָ����ַ��ȡ��У��Ϣ��д��˼Ĵ������Ӷ�ȷ�����Ƶ��׼ȷ�� ��غ��� */
void CMU_RCHFTR_RCHFTRIM_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = CMU->RCHFTR;
	tmpreg &= ~(CMU_RCHFTR_RCHFTRIM_Msk);
	tmpreg |= (SetValue & CMU_RCHFTR_RCHFTRIM_Msk);
	CMU->RCHFTR = tmpreg;
}

uint32_t CMU_RCHFTR_RCHFTRIM_Get(void)
{
	return (CMU->RCHFTR & CMU_RCHFTR_RCHFTRIM_Msk);
}

void CMU_PLLLCR_PLLDB_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = CMU->PLLLCR;
	tmpreg &= ~(CMU_PLLLCR_PLLDB_Msk);
	tmpreg |= (SetValue & CMU_PLLLCR_PLLDB_Msk);
	CMU->PLLLCR = tmpreg;
}

uint32_t CMU_PLLLCR_PLLDB_Get(void)
{
	return (CMU->PLLLCR & CMU_PLLLCR_PLLDB_Msk);
}

/* PLL_L������־
1��PLL_L������
0��PLL_Lδ���� ��غ��� */
FlagStatus CMU_PLLLCR_LOCKED_Chk(void)
{
	if (CMU->PLLLCR & CMU_PLLLCR_LOCKED_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* PLLʹ�ܼĴ���
1��ʹ��PLL
0���ر�PLL ��غ��� */
void CMU_PLLLCR_PLLEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		CMU->PLLLCR |= (CMU_PLLLCR_PLLEN_Msk);
	}
	else
	{
		CMU->PLLLCR &= ~(CMU_PLLLCR_PLLEN_Msk);
	}
}

FunState CMU_PLLLCR_PLLEN_Getable(void)
{
	if (CMU->PLLLCR & (CMU_PLLLCR_PLLEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* PLLH��Ƶ�ȣ��ο�ʱ��1Mhz
0000011111�����32��Ƶ
0101111�����48��Ƶ ��غ��� */
void CMU_PLLHCR_PLLHDB_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = CMU->PLLHCR;
	tmpreg &= ~(CMU_PLLHCR_PLLHDB_Msk);
	tmpreg |= (SetValue & CMU_PLLHCR_PLLHDB_Msk);
	CMU->PLLHCR = tmpreg;
}

uint32_t CMU_PLLHCR_PLLHDB_Get(void)
{
	return (CMU->PLLHCR & CMU_PLLHCR_PLLHDB_Msk);
}

/* PLLH������־�����ͨ����ѯ�˼Ĵ���ȷ��PLL�Ѿ���������״̬
1��PLL������
0��PLLδ���� ��غ��� */
FlagStatus CMU_PLLHCR_LOCKED_Chk(void)
{
	if (CMU->PLLHCR & CMU_PLLHCR_LOCKED_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* PLLH�ο�ʱ��Ԥ��Ƶ��Ŀ���ǲ���1MHz�ο�ʱ�Ӹ�PLL��
000������Ƶ
001��2��Ƶ
010��4��Ƶ
011��8��Ƶ
100��12��Ƶ
101��16��Ƶ
110��24��Ƶ
111��32��Ƶ ��غ��� */
void CMU_PLLHCR_REFPRSC_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = CMU->PLLHCR;
	tmpreg &= ~(CMU_PLLHCR_REFPRSC_Msk);
	tmpreg |= (SetValue & CMU_PLLHCR_REFPRSC_Msk);
	CMU->PLLHCR = tmpreg;
}

uint32_t CMU_PLLHCR_REFPRSC_Get(void)
{
	return (CMU->PLLHCR & CMU_PLLHCR_REFPRSC_Msk);
}

/* PLLH���ѡ��Ĵ���
0��ѡ��PLLHһ�������Ϊ���ֵ�·�ڵ�PLLʱ��
1��ѡ��PLLH���������Ϊ���ֵ�·�ڵ�PLLʱ�� ��غ��� */
void CMU_PLLHCR_OSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = CMU->PLLHCR;
	tmpreg &= ~(CMU_PLLHCR_OSEL_Msk);
	tmpreg |= (SetValue & CMU_PLLHCR_OSEL_Msk);
	CMU->PLLHCR = tmpreg;
}

uint32_t CMU_PLLHCR_OSEL_Get(void)
{
	return (CMU->PLLHCR & CMU_PLLHCR_OSEL_Msk);
}

/* PLLH����ѡ��Ĵ���
0��RCHF
1��XTHF */
void CMU_PLLHCR_INSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = CMU->PLLHCR;
	tmpreg &= ~(CMU_PLLHCR_INSEL_Msk);
	tmpreg |= (SetValue & CMU_PLLHCR_INSEL_Msk);
	CMU->PLLHCR = tmpreg;
}

uint32_t CMU_PLLHCR_INSEL_Get(void)
{
	return (CMU->PLLHCR & CMU_PLLHCR_INSEL_Msk);
}

/* PLLHʹ�ܼĴ���
1��ʹ��PLLH
0���ر�PLLH ��غ��� */
void CMU_PLLHCR_EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		CMU->PLLHCR |= (CMU_PLLHCR_EN_Msk);
	}
	else
	{
		CMU->PLLHCR &= ~(CMU_PLLHCR_EN_Msk);
	}
}

FunState CMU_PLLHCR_EN_Getable(void)
{
	if (CMU->PLLHCR & (CMU_PLLHCR_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* XTHF��ǿ������
000������
111����ǿ ��غ��� */
void CMU_XTHFCR_XTHF_CFG_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = CMU->XTHFCR;
	tmpreg &= ~(CMU_XTHFCR_XTHF_CFG_Msk);
	tmpreg |= (SetValue & CMU_XTHFCR_XTHF_CFG_Msk);
	CMU->XTHFCR = tmpreg;
}

uint32_t CMU_XTHFCR_XTHF_CFG_Get(void)
{
	return (CMU->XTHFCR & CMU_XTHFCR_XTHF_CFG_Msk);
}

/* XTHFʹ�ܼĴ���
0���ر�XTHF
1��ʹ��XTHF ��غ��� */
void CMU_XTHFCR_XTHFEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		CMU->XTHFCR |= (CMU_XTHFCR_XTHFEN_Msk);
	}
	else
	{
		CMU->XTHFCR &= ~(CMU_XTHFCR_XTHFEN_Msk);
	}
}

FunState CMU_XTHFCR_XTHFEN_Getable(void)
{
	if (CMU->XTHFCR & (CMU_XTHFCR_XTHFEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

void CMU_IER_SYSCSE_IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		CMU->IER |= (CMU_IER_SYSCSE_IE_Msk);
	}
	else
	{
		CMU->IER &= ~(CMU_IER_SYSCSE_IE_Msk);
	}
}

FunState CMU_IER_SYSCSE_IE_Getable(void)
{
	if (CMU->IER & (CMU_IER_SYSCSE_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

void CMU_IER_HFDET_IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		CMU->IER |= (CMU_IER_HFDET_IE_Msk);
	}
	else
	{
		CMU->IER &= ~(CMU_IER_HFDET_IE_Msk);
	}
}

FunState CMU_IER_HFDET_IE_Getable(void)
{
	if (CMU->IER & (CMU_IER_HFDET_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}


/* ��Ƶ����ͣ����ģ�����
1��XTHFδͣ��
0��XTHFͣ�� ��غ��� */
FlagStatus CMU_ISR_HFDETO_Chk(void)
{
	if (CMU->ISR & CMU_ISR_HFDETO_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}


/* SYSCLKʱ��ѡ������жϱ�־�Ĵ���������ѡ�е�ʱ��Դû��ʹ��ʱ�����жϱ�־��λ�����д1���㡣 ��غ��� */
void CMU_ISR_SYSCSE_IF_Clr(void)
{
	CMU->ISR = CMU_ISR_SYSCSE_IF_Msk;
}

FlagStatus CMU_ISR_SYSCSE_IF_Chk(void)
{
	if (CMU->ISR & CMU_ISR_SYSCSE_IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��Ƶͣ�����жϱ�־�Ĵ�����XTHFͣ��ʱӲ���첽��λ�����д1���㣻ֻ����FFDETO��Ϊ0������²��ܹ�����˼Ĵ��� ��غ��� */
void CMU_ISR_HFDET_IF_Clr(void)
{
	CMU->ISR = CMU_ISR_HFDET_IF_Msk;
}

FlagStatus CMU_ISR_HFDET_IF_Chk(void)
{
	if (CMU->ISR & CMU_ISR_HFDET_IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* EXTI����ʱ��ʹ�ܣ�����Ч ��غ��� */
void CMU_OPCCR1_EXTICKE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		CMU->OPCCR1 |= (CMU_OPCCR1_EXTICKE_Msk);
	}
	else
	{
		CMU->OPCCR1 &= ~(CMU_OPCCR1_EXTICKE_Msk);
	}
}

FunState CMU_OPCCR1_EXTICKE_Getable(void)
{
	if (CMU->OPCCR1 & (CMU_OPCCR1_EXTICKE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* EXTI�жϲ���ʱ��ѡ�� */
void CMU_OPCCR1_EXTICKSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = CMU->OPCCR1;
	tmpreg &= ~(CMU_OPCCR1_EXTICKSEL_Msk);
	tmpreg |= (SetValue & CMU_OPCCR1_EXTICKSEL_Msk);
	CMU->OPCCR1 = tmpreg;
}

uint32_t CMU_OPCCR1_EXTICKSEL_Get(void)
{
	return (CMU->OPCCR1 & CMU_OPCCR1_EXTICKSEL_Msk);
}

/* LPUART1����ʱ��ʹ�ܣ�����Ч ��غ��� */
void CMU_OPCCR1_LPUART1CKE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		CMU->OPCCR1 |= (CMU_OPCCR1_LPUART1CKE_Msk);
	}
	else
	{
		CMU->OPCCR1 &= ~(CMU_OPCCR1_LPUART1CKE_Msk);
	}
}

FunState CMU_OPCCR1_LPUART1CKE_Getable(void)
{
	if (CMU->OPCCR1 & (CMU_OPCCR1_LPUART1CKE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* LPUART0����ʱ��ʹ�ܣ�����Ч ��غ��� */
void CMU_OPCCR1_LPUART0CKE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		CMU->OPCCR1 |= (CMU_OPCCR1_LPUART0CKE_Msk);
	}
	else
	{
		CMU->OPCCR1 &= ~(CMU_OPCCR1_LPUART0CKE_Msk);
	}
}

FunState CMU_OPCCR1_LPUART0CKE_Getable(void)
{
	if (CMU->OPCCR1 & (CMU_OPCCR1_LPUART0CKE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* LPUART1����ʱ��ѡ��
00��LSCLK
01��RCHF��Ƶ������RCHF��λ�Զ���Ƶ��32768Hz������
10��RFU
11��RFU ��غ��� */
void CMU_OPCCR1_LPUART1CKS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = CMU->OPCCR1;
	tmpreg &= ~(CMU_OPCCR1_LPUART1CKS_Msk);
	tmpreg |= (SetValue & CMU_OPCCR1_LPUART1CKS_Msk);
	CMU->OPCCR1 = tmpreg;
}

uint32_t CMU_OPCCR1_LPUART1CKS_Get(void)
{
	return (CMU->OPCCR1 & CMU_OPCCR1_LPUART1CKS_Msk);
}

/* LPUART0����ʱ��ѡ��
00��LSCLK
01��RCHF��Ƶ������RCHF��λ�Զ���Ƶ��32768Hz������
10��RFU
11��RFU ��غ��� */
void CMU_OPCCR1_LPUART0CKS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = CMU->OPCCR1;
	tmpreg &= ~(CMU_OPCCR1_LPUART0CKS_Msk);
	tmpreg |= (SetValue & CMU_OPCCR1_LPUART0CKS_Msk);
	CMU->OPCCR1 = tmpreg;
}

uint32_t CMU_OPCCR1_LPUART0CKS_Get(void)
{
	return (CMU->OPCCR1 & CMU_OPCCR1_LPUART0CKS_Msk);
}

/* I2C1����ʱ��ʹ�� ��غ��� */
void CMU_OPCCR1_I2C1CKE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		CMU->OPCCR1 |= (CMU_OPCCR1_I2C1CKE_Msk);
	}
	else
	{
		CMU->OPCCR1 &= ~(CMU_OPCCR1_I2C1CKE_Msk);
	}
}

FunState CMU_OPCCR1_I2C1CKE_Getable(void)
{
	if (CMU->OPCCR1 & (CMU_OPCCR1_I2C1CKE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* I2C0����ʱ��ʹ�� ��غ��� */
void CMU_OPCCR1_I2C0CKE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		CMU->OPCCR1 |= (CMU_OPCCR1_I2C0CKE_Msk);
	}
	else
	{
		CMU->OPCCR1 &= ~(CMU_OPCCR1_I2C0CKE_Msk);
	}
}

FunState CMU_OPCCR1_I2C0CKE_Getable(void)
{
	if (CMU->OPCCR1 & (CMU_OPCCR1_I2C0CKE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* I2C1��������ʱ��ѡ��
00��APBCLK
01��RCHF
10��SYSCLK
11��APBCLK ��غ��� */
void CMU_OPCCR1_I2C1CKS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = CMU->OPCCR1;
	tmpreg &= ~(CMU_OPCCR1_I2C1CKS_Msk);
	tmpreg |= (SetValue & CMU_OPCCR1_I2C1CKS_Msk);
	CMU->OPCCR1 = tmpreg;
}

uint32_t CMU_OPCCR1_I2C1CKS_Get(void)
{
	return (CMU->OPCCR1 & CMU_OPCCR1_I2C1CKS_Msk);
}


/* I2C0��������ʱ��ѡ��
00��APBCLK
01��RCHF
10��SYSCLK
11��APBCLK ��غ��� */
void CMU_OPCCR1_I2C0CKS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = CMU->OPCCR1;
	tmpreg &= ~(CMU_OPCCR1_I2C0CKS_Msk);
	tmpreg |= (SetValue & CMU_OPCCR1_I2C0CKS_Msk);
	CMU->OPCCR1 = tmpreg;
}

uint32_t CMU_OPCCR1_I2C0CKS_Get(void)
{
	return (CMU->OPCCR1 & CMU_OPCCR1_I2C0CKS_Msk);
}

/* UART1����ʱ��ʹ�ܣ�����Ч ��غ��� */
void CMU_OPCCR1_UART1CKE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		CMU->OPCCR1 |= (CMU_OPCCR1_UART1CKE_Msk);
	}
	else
	{
		CMU->OPCCR1 &= ~(CMU_OPCCR1_UART1CKE_Msk);
	}
}

FunState CMU_OPCCR1_UART1CKE_Getable(void)
{
	if (CMU->OPCCR1 & (CMU_OPCCR1_UART1CKE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* UART0����ʱ��ʹ�ܣ�����Ч ��غ��� */
void CMU_OPCCR1_UART0CKE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		CMU->OPCCR1 |= (CMU_OPCCR1_UART0CKE_Msk);
	}
	else
	{
		CMU->OPCCR1 &= ~(CMU_OPCCR1_UART0CKE_Msk);
	}
}

FunState CMU_OPCCR1_UART0CKE_Getable(void)
{
	if (CMU->OPCCR1 & (CMU_OPCCR1_UART0CKE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* UART1����ʱ��ѡ��
00��APBCLK
01��RCHF
10��SYSCLK
11��RFU ��غ��� */
void CMU_OPCCR1_UART1CKS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = CMU->OPCCR1;
	tmpreg &= ~(CMU_OPCCR1_UART1CKS_Msk);
	tmpreg |= (SetValue & CMU_OPCCR1_UART1CKS_Msk);
	CMU->OPCCR1 = tmpreg;
}

uint32_t CMU_OPCCR1_UART1CKS_Get(void)
{
	return (CMU->OPCCR1 & CMU_OPCCR1_UART1CKS_Msk);
}

/* UART0����ʱ��ѡ��
00��APBCLK
01��RCHF
10��SYSCLK
11��RFU ��غ��� */
void CMU_OPCCR1_UART0CKS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = CMU->OPCCR1;
	tmpreg &= ~(CMU_OPCCR1_UART0CKS_Msk);
	tmpreg |= (SetValue & CMU_OPCCR1_UART0CKS_Msk);
	CMU->OPCCR1 = tmpreg;
}

uint32_t CMU_OPCCR1_UART0CKS_Get(void)
{
	return (CMU->OPCCR1 & CMU_OPCCR1_UART0CKS_Msk);
}

/* ���������������ʱ�ӷ�Ƶ
000������Ƶ
001��2��Ƶ
010��4��Ƶ
011��8��Ƶ
100��16��Ƶ
101��32��Ƶ
110, 111��RFU ��غ��� */
void CMU_OPCCR2_RNGPRSC_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = CMU->OPCCR2;
	tmpreg &= ~(CMU_OPCCR2_RNGPRSC_Msk);
	tmpreg |= (SetValue & CMU_OPCCR2_RNGPRSC_Msk);
	CMU->OPCCR2 = tmpreg;
}

uint32_t CMU_OPCCR2_RNGPRSC_Get(void)
{
	return (CMU->OPCCR2 & CMU_OPCCR2_RNGPRSC_Msk);
}

/* Flash��дʱ��ʹ�ܣ�����Ч ��غ��� */
void CMU_OPCCR2_NVMCKE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		CMU->OPCCR2 |= (CMU_OPCCR2_NVMCKE_Msk);
	}
	else
	{
		CMU->OPCCR2 &= ~(CMU_OPCCR2_NVMCKE_Msk);
	}
}

FunState CMU_OPCCR2_NVMCKE_Getable(void)
{
	if (CMU->OPCCR2 & (CMU_OPCCR2_NVMCKE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���������������ʱ��ʹ�ܣ�����Ч ��غ��� */
void CMU_OPCCR2_RNGCKE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		CMU->OPCCR2 |= (CMU_OPCCR2_RNGCKE_Msk);
	}
	else
	{
		CMU->OPCCR2 &= ~(CMU_OPCCR2_RNGCKE_Msk);
	}
}

FunState CMU_OPCCR2_RNGCKE_Getable(void)
{
	if (CMU->OPCCR2 & (CMU_OPCCR2_RNGCKE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*  _����ʱ��ʹ�ܣ�����Ч ��غ��� */
void CMU_OPCCR2_LPTCKE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		CMU->OPCCR2 |= (CMU_OPCCR2_LPTCKE_Msk);
	}
	else
	{
		CMU->OPCCR2 &= ~(CMU_OPCCR2_LPTCKE_Msk);
	}
}

FunState CMU_OPCCR2_LPTCKE_Getable(void)
{
	if (CMU->OPCCR2 & (CMU_OPCCR2_LPTCKE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*  _����ʱ��ѡ��
00��APBCLK
01��LSCLK
10��RCLP
11��PLL_L ��غ��� */
void CMU_OPCCR2_LPTCKS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = CMU->OPCCR2;
	tmpreg &= ~(CMU_OPCCR2_LPTCKS_Msk);
	tmpreg |= (SetValue & CMU_OPCCR2_LPTCKS_Msk);
	CMU->OPCCR2 = tmpreg;
}

uint32_t CMU_OPCCR2_LPTCKS_Get(void)
{
	return (CMU->OPCCR2 & CMU_OPCCR2_LPTCKS_Msk);
}

/* BSTIM����ʱ��ʹ�ܣ�����Ч ��غ��� */
void CMU_OPCCR2_BSTCKE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		CMU->OPCCR2 |= (CMU_OPCCR2_BSTCKE_Msk);
	}
	else
	{
		CMU->OPCCR2 &= ~(CMU_OPCCR2_BSTCKE_Msk);
	}
}

FunState CMU_OPCCR2_BSTCKE_Getable(void)
{
	if (CMU->OPCCR2 & (CMU_OPCCR2_BSTCKE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* BSTIM����ʱ��Դѡ��
00��APBCLK
01��LSCLK
10��RCLP
11��SYSCLK ��غ��� */
void CMU_OPCCR2_BSTCKS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = CMU->OPCCR2;
	tmpreg &= ~(CMU_OPCCR2_BSTCKS_Msk);
	tmpreg |= (SetValue & CMU_OPCCR2_BSTCKS_Msk);
	CMU->OPCCR2 = tmpreg;
}

uint32_t CMU_OPCCR2_BSTCKS_Get(void)
{
	return (CMU->OPCCR2 & CMU_OPCCR2_BSTCKS_Msk);
}

void CMU_Deinit(void)
{
	//CMU->SYSCLKCR = ;
	//CMU->RCHFCR = 0x00000000;
	//CMU->RCHFTR = 0x00000000;
	//CMU->PLLLCR = ;
	//CMU->PLLHCR = 0x00000000;
	//CMU->XTHFCR = 0x00000000;
	//CMU->IER = ;
	//CMU->ISR = ;
	//CMU->PCLKCR1 = 0x00000058;
	//CMU->PCLKCR2 = 0x00000000;
	//CMU->PCLKCR3 = 0x00000000;
	//CMU->PCLKCR4 = ;
	//CMU->OPCCR1 = 0x00000000;
	//CMU->OPCCR2 = 0x00000000;
}
//Code_End


/********************************
��ȡоƬ�����õĲ�ͬʱ��Ƶ�ʺ���
����:��ȡоƬ�����õĲ�ͬʱ��Ƶ��
RCHF_Frequency 
PLL_H_Frequency 
SYSCLK_Frequency 
AHBCLK_Frequency 
APBCLK_Frequency 
********************************/
void CMU_GetClocksFreq(CMU_ClocksType* para)
{
    uint32_t tmp32 = 0;
    para->RCHF_Frequency = 0;
    para->PLL_H_Frequency = 0;
    para->SYSCLK_Frequency = 0;
    para->AHBCLK_Frequency = 0;
    para->APBCLK_Frequency = 0;
		
	/* Get RCHF FSEL */
	if(ENABLE == CMU_RCHFCR_RCHFEN_Getable())
	{
		tmp32 = CMU_RCHFCR_FSEL_Get();
		tmp32 = tmp32 >> CMU_RCHFCR_FSEL_Pos;  
		/* RCHF clock frequency */
        para->RCHF_Frequency = __RCHF_INITIAL_CLOCK * (tmp32 + 1);

	}

	if(ENABLE == CMU_PLLHCR_EN_Getable())
	{
		/* PLLH��Ƶ�� */
		tmp32 = CMU_PLLHCR_PLLHDB_Get();
		tmp32 = tmp32 >> CMU_PLLHCR_PLLHDB_Pos;
		para->PLL_H_Frequency = (tmp32 + 1) * 1000000;
		/* PLLH���ѡ��Ĵ��� */
		if( CMU_PLLHCR_OSEL_X2 == CMU_PLLHCR_OSEL_Get() )
		{
			para->PLL_H_Frequency = (para->PLL_H_Frequency)*2;
		}
	}
  
	/* Get SYSCLK source */
    tmp32 = CMU_SYSCLKCR_SYSCLKSEL_Get();
    tmp32 = tmp32 >> CMU_SYSCLKCR_SYSCLKSEL_Pos;
    switch (tmp32)
    {
        case 0x00:  /* RCHF used as system clock source */
            para->SYSCLK_Frequency = para->RCHF_Frequency;
            break;
        case 0x01:  /* XTHF used as system clock  source */
            para->SYSCLK_Frequency = __XTHF_CLOCK;
            break;
        case 0x02:  /* PLL_H used as system clock  source */
            para->SYSCLK_Frequency = para->PLL_H_Frequency;
            break;
        case 0x03:  /* LSCLK used as system clock  source */
            para->SYSCLK_Frequency = __XTLF_CLOCK;
            break;
        default:
            para->SYSCLK_Frequency = para->RCHF_Frequency;
            break;
    }
	
	/* Get AHB PRES */
    tmp32 = CMU_SYSCLKCR_AHBPRES_Get();
    tmp32 = tmp32 >> CMU_SYSCLKCR_AHBPRES_Pos;  
    switch(tmp32)
    {
        case 0x04: //100:DIV2
            para->AHBCLK_Frequency = para->SYSCLK_Frequency/2;
            break;
        case 0x05: //101:DIV4
            para->AHBCLK_Frequency = para->SYSCLK_Frequency/4;
            break;
        case 0x06: //110:DIV8
            para->AHBCLK_Frequency = para->SYSCLK_Frequency/8;
            break;
        case 0x07: //111:DIV16
            para->AHBCLK_Frequency = para->SYSCLK_Frequency/16;
            break;
        default: //0XX:DIV1
            para->AHBCLK_Frequency = para->SYSCLK_Frequency;
            break;
    }

	/* Get APB PRES */
    tmp32 = CMU_SYSCLKCR_APBPRES_Get();
    tmp32 = tmp32 >> CMU_SYSCLKCR_APBPRES_Pos; 
	/* APB clock frequency */
    switch(tmp32)
    {
        case 0x04: //100:DIV2
            para->APBCLK_Frequency = para->AHBCLK_Frequency/2;
            break;
        case 0x05: //101:DIV4
            para->APBCLK_Frequency = para->AHBCLK_Frequency/4;
            break;
        case 0x06: //110:DIV8
            para->APBCLK_Frequency = para->AHBCLK_Frequency/8;
            break;
        case 0x07: //111:DIV16
            para->APBCLK_Frequency = para->AHBCLK_Frequency/16;
            break;
        default: //0XX:DIV1
            para->APBCLK_Frequency = para->AHBCLK_Frequency;
            break;
    }
}


/********************************
����ʱ��ʹ�ܺ���
����:������ģ������Ҫ�Ķ�Ӧʱ�ӽ���ʹ��
���룺periph_def�ⲿģ����
      NewStateʹ��λ
 ********************************/
void CMU_PERCLK_SetableEx(uint32_t periph_def, FunState NewState)
{
	__IO uint32_t *p_reg = 0;
	uint32_t TempREG;
	
    switch((periph_def & 0x0F000000))
    {
		case 0x01000000:
			p_reg = &(CMU->PCLKCR1);
			break;
		
		case 0x02000000:
			p_reg = &(CMU->PCLKCR2);
			break;
		
		case 0x03000000:
			p_reg = &(CMU->PCLKCR3);
			break;
		
		case 0x04000000:
			p_reg = &(CMU->PCLKCR4);
			break;
		
		default:
			break;
    }
	if(p_reg)
	{
		periph_def &= 0xFFFF;
		TempREG = (0x1U << periph_def);
		
		if (NewState != DISABLE)
		{
			*p_reg |= TempREG;
		}
		else
		{
			*p_reg &= ~TempREG;
		}
	}
}


/********************************
RCHF��ʼ������
����:��RCHF���г�ʼ��
���룺RCHFƵ�ʺ�ʹ��
 ********************************/
void CMU_RCHF_Init(CMU_RCHF_InitTypeDef* para)
{
	CMU_RCHFCR_FSEL_Set(para->FSEL);
	CMU_RCHFCR_RCHFEN_Setable(para->RCHFEN);
}

/********************************
PLL H��ʼ������
����:��PLL H���г�ʼ��
���룺��PLL H���õ���ز���
 ********************************/
void CMU_PLL_H_Init(CMU_PLL_H_InitTypeDef* para)
{
	CMU_PLLHCR_PLLHDB_Set(para->PLLHDB);
	CMU_PLLHCR_REFPRSC_Set(para->REFPRSC);
	CMU_PLLHCR_OSEL_Set(para->PLLH_OSEL);
	CMU_PLLHCR_INSEL_Set(para->PLLH_INSEL);
	CMU_PLLHCR_EN_Setable(para->PLLH_EN);
}

/* ϵͳʱ�ӳ�ʼ�� */
void CMU_SysClk_Init(CMU_SYSCLK_InitTypeDef* para)
{
	CMU_SYSCLKCR_SYSCLKSEL_Set(para->SYSCLKSEL);
	CMU_SYSCLKCR_AHBPRES_Set(para->AHBPRES);
	CMU_SYSCLKCR_APBPRES_Set(para->APBPRES);
	CMU_SYSCLKCR_SLP_ENEXTI_Setable(para->SLP_ENEXTI);
}

/********************************
rchf����У׼ֵ���뺯��
����:rchf����У׼ֵ����(rchf����У׼ֵ����(оƬ��λ���Զ�����8M��У׼ֵ))
���룺Ҫ���õ�RCHFƵ��
			ClkMode 1 = 8M
			ClkMode 2 = 16M
			ClkMode 3 = 24M
			ClkMode 4 = 32M
 ********************************/
void CMU_Init_RCHF_Trim( uint8_t ClkMode )
{
	uint32_t Temp32;
	
	if( ClkMode == 1 )	//8M
	{
		Temp32 = const_rchf_Trim8;
	}
	else if( ClkMode == 2 )//16M
	{
		Temp32 = const_rchf_Trim16;
	}
	else if( ClkMode == 3 )//24M
	{
		Temp32 = const_rchf_Trim24;
	}
	else if( ClkMode == 4 )//32M
	{
		Temp32 = const_rchf_Trim32;
	}
	else//Ĭ��8M
	{
		Temp32 = const_rchf_Trim8;
	}
	
	if( ((Temp32>>16)&0x0000FFFF) == ((~Temp32)&0x0000FFFF) )	//������У���ж�
	{
		CMU_RCHFTR_RCHFTRIM_Set(Temp32&0x000000FF);
	}	
	else
	{
		CMU_RCHFTR_RCHFTRIM_Set(0x0000006B);
	}
}

/******END OF FILE****/
