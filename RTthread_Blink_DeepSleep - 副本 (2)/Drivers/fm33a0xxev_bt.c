/**
  ******************************************************************************
  * @file    fm33a0xxev_bt.c
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/

#include "fm33a0xxev_bt.h"

/** @addtogroup fm33a0xxev_StdPeriph_Driver
  * @{
  */

/** @defgroup BT
  * @brief BT driver modules
  * @{
  */ 
 
/* ��8λ��������BT1H��BT2H����������  ��غ��� */
void BTx_CR1_CHEN_Setable(BT_Type* BTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		BTx->CR1  |= (BTx_CR1_CHEN_Msk);
	}
	else
	{
		BTx->CR1  &= ~(BTx_CR1_CHEN_Msk);
	}
}

FunState BTx_CR1_CHEN_Getable(BT_Type* BTx)
{
	if (BTx->CR1  & (BTx_CR1_CHEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��8λ��������BT1L��BT2L����������
(Counter-Lowend enable)
1��������8bit���������ڼ�����ģʽ������ʱ��Ԥ����ֵ�ͼ���ֵ�ֱ�������������ͱȽϼĴ�������׽ģʽ������ʱ���������㿪ʼ���ɼ�����������0xFFFF���������ź�Ȼ�����㿪ʼ���¼�������׽����ֻ������16λģʽ����16λ�Ķ�ʱ/�����Ͳ�׽ģʽ��CHEN��Ϊ���������������ƣ�CLEN�Զ�ʧЧ
0��ֹͣ��8bit���������� ��غ��� */
void BTx_CR1_CLEN_Setable(BT_Type* BTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		BTx->CR1  |= (BTx_CR1_CLEN_Msk);
	}
	else
	{
		BTx->CR1  &= ~(BTx_CR1_CLEN_Msk);
	}
}

FunState BTx_CR1_CLEN_Getable(BT_Type* BTx)
{
	if (BTx->CR1  & (BTx_CR1_CLEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ����ģʽѡ�� (work mode)
1��16λ��׽ģʽ
0��8λ��ʱ/����ģʽ������λ����������Դѡ��Ϊ��λ������������źţ����ʵ��16λ��ʱ/����ģʽ ��غ��� */
void BTx_CR1_MODE_Set(BT_Type* BTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTx->CR1 ;
	tmpreg &= ~(BTx_CR1_MODE_Msk);
	tmpreg |= (SetValue & BTx_CR1_MODE_Msk);
	BTx->CR1  = tmpreg;
}

uint32_t BTx_CR1_MODE_Get(BT_Type* BTx)
{
	return (BTx->CR1  & BTx_CR1_MODE_Msk);
}

/* ����ģʽ�µļ����غ����ڲ�׽ʱ�Ĳ�׽��ѡ��λ (edge select)
1������ģʽ��������Դ�½��أ����ڲ�׽ģʽʱ���ز�׽
0������ģʽ��������Դ�����أ����ڲ�׽ģʽʱ���ز�׽
ע����֧��ϵͳʱ�ӵ��½��ؼ�������׽Դ�ͼ���ԴΪϵͳʱ��ʱѡ���½��ؽ�������Ч������ ��غ��� */
void BTx_CR1_EDGESEL_Set(BT_Type* BTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTx->CR1 ;
	tmpreg &= ~(BTx_CR1_EDGESEL_Msk);
	tmpreg |= (SetValue & BTx_CR1_EDGESEL_Msk);
	BTx->CR1  = tmpreg;
}

uint32_t BTx_CR1_EDGESEL_Get(BT_Type* BTx)
{
	return (BTx->CR1  & BTx_CR1_EDGESEL_Msk);
}

/* ��׽ģʽ���ƣ�ֻ�ڲ�׽ģʽ����Ч��(capture mode)
1�������Ȳ�׽
0���������ڲ�׽ ��غ��� */
void BTx_CR1_CAPMOD_Set(BT_Type* BTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTx->CR1 ;
	tmpreg &= ~(BTx_CR1_CAPMOD_Msk);
	tmpreg |= (SetValue & BTx_CR1_CAPMOD_Msk);
	BTx->CR1  = tmpreg;
}

uint32_t BTx_CR1_CAPMOD_Get(BT_Type* BTx)
{
	return (BTx->CR1  & BTx_CR1_CAPMOD_Msk);
}

/* �����㲶׽ģʽ���� (capture clear)
1�������������Ȼ������ڲ�׽����£���׽����һ���غ󽫼�������������жϣ���׽���ڶ����غ����棨���浽�ߵ�λԤ�����Ĵ���������ֵ��ͬʱ���������
0����׽�����㣬������һֱ���ɼ��� ��غ��� */
void BTx_CR1_CAPCLR_Setable(BT_Type* BTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		BTx->CR1  |= (BTx_CR1_CAPCLR_Msk);
	}
	else
	{
		BTx->CR1  &= ~(BTx_CR1_CAPCLR_Msk);
	}
}

FunState BTx_CR1_CAPCLR_Getable(BT_Type* BTx)
{
	if (BTx->CR1  & (BTx_CR1_CAPCLR_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���β�׽���� (capture once)
1�����β�׽��Ч���ڲ�׽��һ�������Ȼ��������ں������ֹͣ������Ҫ�ٴβ�׽����������
0��������׽ ��غ��� */
void BTx_CR1_CAPONCE_Set(BT_Type* BTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTx->CR1 ;
	tmpreg &= ~(BTx_CR1_CAPONCE_Msk);
	tmpreg |= (SetValue & BTx_CR1_CAPONCE_Msk);
	BTx->CR1  = tmpreg;
}

uint32_t BTx_CR1_CAPONCE_Get(BT_Type* BTx)
{
	return (BTx->CR1  & BTx_CR1_CAPONCE_Msk);
}

/* PWMģʽ��� (pulse width modulation)
1��PWM���ʹ��
0��PWM �����ʹ�� ��غ��� */
void BTx_CR1_PWM_Setable(BT_Type* BTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		BTx->CR1  |= (BTx_CR1_PWM_Msk);
	}
	else
	{
		BTx->CR1  &= ~(BTx_CR1_PWM_Msk);
	}
}

FunState BTx_CR1_PWM_Getable(BT_Type* BTx)
{
	if (BTx->CR1  & (BTx_CR1_PWM_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �������ڲ�����Դ�ź�ѡ�� (signal group2 select)
1���ڲ�����Դ�ź�ѡ��Group2
0���ڲ�����Դ�ź�ѡ��Group1 ��غ��� */
void BTx_CR2_SIG2SEL_Set(BT_Type* BTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTx->CR2 ;
	tmpreg &= ~(BTx_CR2_SIG2SEL_Msk);
	tmpreg |= (SetValue & BTx_CR2_SIG2SEL_Msk);
	BTx->CR2  = tmpreg;
}

uint32_t BTx_CR2_SIG2SEL_Get(BT_Type* BTx)
{
	return (BTx->CR2  & BTx_CR2_SIG2SEL_Msk);
}

/* �������ڲ���׽Դ�ź�ѡ�� (signal group1 select)
1���ڲ���׽Դ�ź�ѡ��Group1
0���ڲ���׽Դ�ź�ѡ��Group2 ��غ��� */
void BTx_CR2_SIG1SEL_Set(BT_Type* BTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTx->CR2 ;
	tmpreg &= ~(BTx_CR2_SIG1SEL_Msk);
	tmpreg |= (SetValue & BTx_CR2_SIG1SEL_Msk);
	BTx->CR2  = tmpreg;
}

uint32_t BTx_CR2_SIG1SEL_Get(BT_Type* BTx)
{
	return (BTx->CR2  & BTx_CR2_SIG1SEL_Msk);
}

/* ��8λ����������Դѡ�� (Counter Highend source select)
00/11��ѡ��ET1�ĵ�λ������������źţ����λ���������16λ������
01��ѡ���ڲ���׽Դ�ź�
10��ѡ���ڲ�����Դ�źŻ��ⲿDIR��������ź� ��غ��� */
void BTx_CR2_CNTHSEL_Set(BT_Type* BTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTx->CR2 ;
	tmpreg &= ~(BTx_CR2_CNTHSEL_Msk);
	tmpreg |= (SetValue & BTx_CR2_CNTHSEL_Msk);
	BTx->CR2  = tmpreg;
}

uint32_t BTx_CR2_CNTHSEL_Get(BT_Type* BTx)
{
	return (BTx->CR2  & BTx_CR2_CNTHSEL_Msk);
}

/* �ⲿ����DIR����ʹ�ܡ�ͨ�������������ʱͬʱ�����һ���ɸߵ͵�ƽָʾ������ķ����ź�DIR����·��ͨ��DIR�źŵ�ƽ�ĸߵͣ��ֱ���Ƹ�λ�������͵�λ����������ʹ�ܣ���ʵ��������򡢷�������ĸ��ּ������� (direction bit enable)
1���ⲿ�����DIR�ź���Ч����ʱ�ߵ�λ�������Ƿ���������ⲿ�����DIR�źſ��ơ�
0���ⲿ�����DIR�ź���Ч����ʱ�ߵ�λ�������Ƿ���������ڲ������źſ��ơ� ��غ��� */
void BTx_CR2_DIREN_Setable(BT_Type* BTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		BTx->CR2  |= (BTx_CR2_DIREN_Msk);
	}
	else
	{
		BTx->CR2  &= ~(BTx_CR2_DIREN_Msk);
	}
}

FunState BTx_CR2_DIREN_Getable(BT_Type* BTx)
{
	if (BTx->CR2  & (BTx_CR2_DIREN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �ڲ�DIR�����źţ���DIRENΪ0�����ⲿ����DIR������Чʱ�����ɸ��źŴ���DIR���룬ֱ�ӿ����ڲ��������ļ���������Ҫ�ⲿDIR���룬��DIRENΪ1ʱ����λӦ����Ϊ0 (set direction)
1���ڲ�DIR�ź�Ϊ�ߵ�ƽ�����8λ���������� ��غ��� */
void BTx_CR2_STDIR_Setable(BT_Type* BTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		BTx->CR2  |= (BTx_CR2_STDIR_Msk);
	}
	else
	{
		BTx->CR2  &= ~(BTx_CR2_STDIR_Msk);
	}
}

FunState BTx_CR2_STDIR_Getable(BT_Type* BTx)
{
	if (BTx->CR2  & (BTx_CR2_STDIR_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��λ����������ʹ�ܿ���ѡ���ź� (source select)
1��λ����������ʹ�ܶ�ѡ��ʹ�ܡ���ʱ��λ��������������DIR���ƣ��ɽ���������������һ������
0����λ����������ʹ�ܶ�ѡ���ɼĴ���STDIR���ⲿEX_SIG2������ơ� ��غ��� */
void BTx_CR2_SRCSEL_Setable(BT_Type* BTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		BTx->CR2  |= (BTx_CR2_SRCSEL_Msk);
	}
	else
	{
		BTx->CR2  &= ~(BTx_CR2_SRCSEL_Msk);
	}
}

FunState BTx_CR2_SRCSEL_Getable(BT_Type* BTx)
{
	if (BTx->CR2  & (BTx_CR2_SRCSEL_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �����ź�2����ѡ�� (direction polarity)
1�����ⲿ����DIR�ź�EX_SIG2����
0�����ⲿ����DIR�ź�EX_SIG2������ ��غ��� */
void BTx_CR2_DIRPO_Set(BT_Type* BTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTx->CR2 ;
	tmpreg &= ~(BTx_CR2_DIRPO_Msk);
	tmpreg |= (SetValue & BTx_CR2_DIRPO_Msk);
	BTx->CR2  = tmpreg;
}

uint32_t BTx_CR2_DIRPO_Get(BT_Type* BTx)
{
	return (BTx->CR2  & BTx_CR2_DIRPO_Msk);
}

/* RTCOUT2�ź�ѡ�����2 (RTCOUT2 source select)
00 = 32768Hz��XTLFʱ�����
01 = RTCSec����RTCģ����������ź�
10 = RTCMin����RTCģ������ķ����ź�
11 = RFU ��غ��� */
void BTx_CFGR1_RTCSEL2_Set(BT_Type* BTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTx->CFGR1 ;
	tmpreg &= ~(BTx_CFGR1_RTCSEL2_Msk);
	tmpreg |= (SetValue & BTx_CFGR1_RTCSEL2_Msk);
	BTx->CFGR1  = tmpreg;
}

uint32_t BTx_CFGR1_RTCSEL2_Get(BT_Type* BTx)
{
	return (BTx->CFGR1  & BTx_CFGR1_RTCSEL2_Msk);
}

/* RTCOUT1�ź�ѡ�����1 (RTCOUT1 source select)
00 = 32768Hz��XTLFʱ�����
01 = RTCSec����RTCģ����������ź�
10 = RTCMin����RTCģ������ķ����ź�
11 = RFU ��غ��� */
void BTx_CFGR1_RTCSEL1_Set(BT_Type* BTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTx->CFGR1 ;
	tmpreg &= ~(BTx_CFGR1_RTCSEL1_Msk);
	tmpreg |= (SetValue & BTx_CFGR1_RTCSEL1_Msk);
	BTx->CFGR1  = tmpreg;
}

uint32_t BTx_CFGR1_RTCSEL1_Get(BT_Type* BTx)
{
	return (BTx->CFGR1  & BTx_CFGR1_RTCSEL1_Msk);
}

/* Group2�ź�ѡ����� (Group2 source select)
00 = APBCLK
01 = RTCOUT2
10 = IN_SIG2���ڲ������ź�2
11 = EX_SIG2���ⲿ�����ź�2
ע����֧��APBCLK���½��ز�׽�ͼ�������׽Դ�ͼ���ԴΪAPBCLKʱѡ���½��ؽ�������Ч��׽�ͼ����� ��غ��� */
void BTx_CFGR1_GRP2SEL_Set(BT_Type* BTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTx->CFGR1 ;
	tmpreg &= ~(BTx_CFGR1_GRP2SEL_Msk);
	tmpreg |= (SetValue & BTx_CFGR1_GRP2SEL_Msk);
	BTx->CFGR1  = tmpreg;
}

uint32_t BTx_CFGR1_GRP2SEL_Get(BT_Type* BTx)
{
	return (BTx->CFGR1  & BTx_CFGR1_GRP2SEL_Msk);
}

/* Group1�ź�ѡ����ƣ�����Ϊ��׽ģʽ�²���ʱ��ѡ��ͬʱ����Ϊ�źŲ�׽Դ��(Group1 source select)
00 = APBCLK
01 = RTCOUT1
10 = IN_SIG1���ڲ������ź�1
11 = EX_SIG1���ⲿ�����ź�1
ע����֧��APBCLK���½��ز�׽�ͼ�������׽Դ�ͼ���ԴΪAPBCLKʱѡ���½��ؽ�������Ч��׽�ͼ����� ��غ��� */
void BTx_CFGR1_GRP1SEL_Set(BT_Type* BTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTx->CFGR1 ;
	tmpreg &= ~(BTx_CFGR1_GRP1SEL_Msk);
	tmpreg |= (SetValue & BTx_CFGR1_GRP1SEL_Msk);
	BTx->CFGR1  = tmpreg;
}

uint32_t BTx_CFGR1_GRP1SEL_Get(BT_Type* BTx)
{
	return (BTx->CFGR1  & BTx_CFGR1_GRP1SEL_Msk);
}

/* �ⲿ�����ź�ѡ�����2 (external source select2)
00 = BT1_IN0/BT2_IN0
01 = BT1_IN1/BT2_IN1
10 = BT1_IN2/BT2_IN2
11 = BT1_IN3/BT2_IN3 ��غ��� */
void BTx_CFGR2_EXSEL2_Set(BT_Type* BTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTx->CFGR2 ;
	tmpreg &= ~(BTx_CFGR2_EXSEL2_Msk);
	tmpreg |= (SetValue & BTx_CFGR2_EXSEL2_Msk);
	BTx->CFGR2  = tmpreg;
}

uint32_t BTx_CFGR2_EXSEL2_Get(BT_Type* BTx)
{
	return (BTx->CFGR2  & BTx_CFGR2_EXSEL2_Msk);
}

/* �ⲿ�����ź�ѡ�����1 (external source select1)
00 = BT1_IN0/BT2_IN0
01 = BT1_IN1/BT2_IN1
10 = BT1_IN2/BT2_IN2
11 = BT1_IN3/BT2_IN3 ��غ��� */
void BTx_CFGR2_EXSEL1_Set(BT_Type* BTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTx->CFGR2 ;
	tmpreg &= ~(BTx_CFGR2_EXSEL1_Msk);
	tmpreg |= (SetValue & BTx_CFGR2_EXSEL1_Msk);
	BTx->CFGR2  = tmpreg;
}

uint32_t BTx_CFGR2_EXSEL1_Get(BT_Type* BTx)
{
	return (BTx->CFGR2  & BTx_CFGR2_EXSEL1_Msk);
}

/* �ڲ������ź�ѡ�����2 (internal source select 2)
00 = UART_RX3/UART_RX3
01 = UART_RX4/UART_RX4
10 = UART_RX5/UART_RX5
11 = RCLP/BT1_OUT ��غ��� */
void BTx_CFGR2_INSEL2_Set(BT_Type* BTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTx->CFGR2 ;
	tmpreg &= ~(BTx_CFGR2_INSEL2_Msk);
	tmpreg |= (SetValue & BTx_CFGR2_INSEL2_Msk);
	BTx->CFGR2  = tmpreg;
}

uint32_t BTx_CFGR2_INSEL2_Get(BT_Type* BTx)
{
	return (BTx->CFGR2  & BTx_CFGR2_INSEL2_Msk);
}

/* �ڲ������ź�ѡ�����1 (internal source select 1)
00 = UART_RX0/UART_RX0
01 = UART_RX1/UART_RX1
10 = UART_RX2/UART_RX2
11 = RCLP/RCLP ��غ��� */
void BTx_CFGR2_INSEL1_Set(BT_Type* BTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTx->CFGR2 ;
	tmpreg &= ~(BTx_CFGR2_INSEL1_Msk);
	tmpreg |= (SetValue & BTx_CFGR2_INSEL1_Msk);
	BTx->CFGR2  = tmpreg;
}

uint32_t BTx_CFGR2_INSEL1_Get(BT_Type* BTx)
{
	return (BTx->CFGR2  & BTx_CFGR2_INSEL1_Msk);
}

/* ����Group1��Ԥ��Ƶ�Ĵ��� (Group1 input signal prescaler)
��Ƶ��=��X+1������00��ʾ1��Ƶ��FF��ʾ256��Ƶ��Ԥ��Ƶ����źŶ�Ϊ�������������ʽ��ռ�ձ�1:X ��غ��� */
void BTx_PRES_Write(BT_Type* BTx, uint32_t SetValue)
{
	BTx->PRES  = (SetValue & BTx_PRES_PRESCALE_Msk);
}

uint32_t BTx_PRES_Read(BT_Type* BTx)
{
	return (BTx->PRES  & BTx_PRES_PRESCALE_Msk);
}

/* ��λ���ؿ��� (Counter highend load enable)
д1��Ԥ�����Ĵ���ET1PRESETH�ͼ��ؼĴ���ET1LOADH�ֱ���ص�����ֵ�Ĵ���ET1CNTH�ͱȽϼĴ���ET1CMPH��д0��Ч����λӲ���Զ���0����16λ�Ķ�ʱ/������LHEN��Ϊ�������ļ��ؿ��ƣ�LLEN�Զ�ʧЧ ��غ��� */
void BTx_LOADCR_LHEN_Setable(BT_Type* BTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		BTx->LOADCR |= (BTx_LOADCR_LHEN_Msk);
	}
	else
	{
		BTx->LOADCR &= ~(BTx_LOADCR_LHEN_Msk);
	}
}

FunState BTx_LOADCR_LHEN_Getable(BT_Type* BTx)
{
	if (BTx->LOADCR & (BTx_LOADCR_LHEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��λ���ؿ��� (Counter lowend load enable)
д1��Ԥ�����Ĵ���PRESETL�ͼ��ؼĴ���LOADL�ֱ���ص�����ֵ�Ĵ���ET1CNTL�ͱȽϼĴ���ET1CMPL��д0��Ч����λӲ���Զ���0����16λ�Ķ�ʱ/������LHEN��Ϊ�������ļ��ؿ��ƣ�LLEN�Զ�ʧЧ ��غ��� */
void BTx_LOADCR_LLEN_Setable(BT_Type* BTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		BTx->LOADCR |= (BTx_LOADCR_LLEN_Msk);
	}
	else
	{
		BTx->LOADCR &= ~(BTx_LOADCR_LLEN_Msk);
	}
}

FunState BTx_LOADCR_LLEN_Getable(BT_Type* BTx)
{
	if (BTx->LOADCR & (BTx_LOADCR_LLEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��������λ����ֵ�Ĵ��� (counter lowend)
LLEN��Чʱ����Ԥ�������üĴ����� ��غ��� */
uint32_t BTx_CNTL_Read(BT_Type* BTx)
{
	return (BTx->CNTL  & BTx_CNTL_CNTL_Msk);
}

/* ��������λ����ֵ�Ĵ��� (counter highend)
LHEN��Чʱ����Ԥ�������üĴ����� ��غ��� */
uint32_t BTx_CNTH_Read(BT_Type* BTx)
{
	return (BTx->CNTH  & BTx_CNTH_CNTH_Msk);
}

/* ��������λԤ�����Ĵ��� (preset highend)
���ڱ����λ��������ֵ���򱣴沶׽�����8bit ��غ��� */
void BTx_PRESET_PRESETH_Set(BT_Type* BTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTx->PRESET ;
	tmpreg &= ~(BTx_PRESET_PRESETH_Msk);
	tmpreg |= (SetValue & BTx_PRESET_PRESETH_Msk);
	BTx->PRESET  = tmpreg;
}

uint32_t BTx_PRESET_PRESETH_Get(BT_Type* BTx)
{
	return (BTx->PRESET  & BTx_PRESET_PRESETH_Msk);
}

/* ��������λԤ�����Ĵ��� (preset lowend)
���ڱ����λ��������ֵ���򱣴沶׽�����8bit ��غ��� */
void BTx_PRESET_PRESETL_Set(BT_Type* BTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTx->PRESET ;
	tmpreg &= ~(BTx_PRESET_PRESETL_Msk);
	tmpreg |= (SetValue & BTx_PRESET_PRESETL_Msk);
	BTx->PRESET  = tmpreg;
}

uint32_t BTx_PRESET_PRESETL_Get(BT_Type* BTx)
{
	return (BTx->PRESET  & BTx_PRESET_PRESETL_Msk);
}

/* ��������λ���ؼĴ��� (load lowend counter)
�ڼ���ƥ���ִ�м�������ʱ�����ؼĴ�����ֵ�������ȽϹ����Ĵ����� ��غ��� */
void BTx_LOADL_Write(BT_Type* BTx, uint32_t SetValue)
{
	BTx->LOADL  = (SetValue & BTx_LOADL_LOADL_Msk);
}

uint32_t BTx_LOADL_Read(BT_Type* BTx)
{
	return (BTx->LOADL  & BTx_LOADL_LOADL_Msk);
}

/* ��������λ���ؼĴ��� (load highend counter)
�ڼ���ƥ���ִ�м�������ʱ�����ؼĴ�����ֵ�������ȽϹ����Ĵ�������������8λ��ʱ/������ģʽʱ���ø�λ���ؼĴ�����֧�ּ���ֵΪ0x00�����á� ��غ��� */
void BTx_LOADH_Write(BT_Type* BTx, uint32_t SetValue)
{
	BTx->LOADH  = (SetValue & BTx_LOADH_LOADH_Msk);
}

uint32_t BTx_LOADH_Read(BT_Type* BTx)
{
	return (BTx->LOADH  & BTx_LOADH_LOADH_Msk);
}

/* ��������λ�ȽϼĴ��� (compare lowend )
���ؼĴ�����ֵ���غ�д��üĴ������üĴ�����������Ƚϣ�������ֵ���ڵ��ڸüĴ�����ֵ�����������ƥ���ź����������ģ�飬��������Ӧ�жϡ� ��غ��� */
void BTx_CMPL_Write(BT_Type* BTx, uint32_t SetValue)
{
	BTx->CMPL  = (SetValue & BTx_CMPL_CMPL_Msk);
}

uint32_t BTx_CMPL_Read(BT_Type* BTx)
{
	return (BTx->CMPL  & BTx_CMPL_CMPL_Msk);
}

/* ��������λ�ȽϼĴ��� (compare highend)
���ؼĴ�����ֵ���غ�д��üĴ������üĴ�����������Ƚϣ�������ֵ���ڵ��ڸüĴ�����ֵ�����������ƥ���ź����������ģ�飬��������Ӧ�жϡ� ��غ��� */
void BTx_CMPH_Write(BT_Type* BTx, uint32_t SetValue)
{
	BTx->CMPH  = (SetValue & BTx_CMPH_CMPH_Msk);
}

uint32_t BTx_CMPH_Read(BT_Type* BTx)
{
	return (BTx->CMPH  & BTx_CMPH_CMPH_Msk);
}

/* ��������������ȼ����� (output pulse width counter)
�üĴ������ڵ�����������ȡ�����ʱ��Ϊ32768Hz����Ӧ����������ȷ�ΧΪ30.5uS~125mS�����������=(OUTCNT+1)/32768�� ��غ��� */
void BTx_OUTCNT_Write(BT_Type* BTx, uint32_t SetValue)
{
	BTx->OUTCNT  = (SetValue & BTx_OUTCNT_OUTCNT_Msk);
}

uint32_t BTx_OUTCNT_Read(BT_Type* BTx)
{
	return (BTx->OUTCNT  & BTx_OUTCNT_OUTCNT_Msk);
}

void BTx_OCR_OUTCLR_Set(BT_Type* BTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTx->OCR;
	tmpreg &= ~(BTx_OCR_OUTCLR_Msk);
	tmpreg |= (SetValue & BTx_OCR_OUTCLR_Msk);
	BTx->OCR = tmpreg;
}

uint32_t BTx_OCR_OUTCLR_Get(BT_Type* BTx)
{
	return (BTx->OCR & BTx_OCR_OUTCLR_Msk);
}

void BTx_OCR_OUTINV_Set(BT_Type* BTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTx->OCR;
	tmpreg &= ~(BTx_OCR_OUTINV_Msk);
	tmpreg |= (SetValue & BTx_OCR_OUTINV_Msk);
	BTx->OCR = tmpreg;
}

uint32_t BTx_OCR_OUTINV_Get(BT_Type* BTx)
{
	return (BTx->OCR & BTx_OCR_OUTINV_Msk);
}

void BTx_OCR_OUTMOD_Set(BT_Type* BTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTx->OCR;
	tmpreg &= ~(BTx_OCR_OUTMOD_Msk);
	tmpreg |= (SetValue & BTx_OCR_OUTMOD_Msk);
	BTx->OCR = tmpreg;
}

uint32_t BTx_OCR_OUTMOD_Get(BT_Type* BTx)
{
	return (BTx->OCR & BTx_OCR_OUTMOD_Msk);
}

void BTx_OCR_OUTSEL_Set(BT_Type* BTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTx->OCR;
	tmpreg &= ~(BTx_OCR_OUTSEL_Msk);
	tmpreg |= (SetValue & BTx_OCR_OUTSEL_Msk);
	BTx->OCR = tmpreg;
}

uint32_t BTx_OCR_OUTSEL_Get(BT_Type* BTx)
{
	return (BTx->OCR & BTx_OCR_OUTSEL_Msk);
}

/* ��չ��ʱ����λ�ȽϷ����ź� (compare highend interrupt enable)
1 = �ж�ʹ��
0 = �жϽ�ֹ ��غ��� */
void BTx_IER_CMPHIE_Setable(BT_Type* BTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		BTx->IER |= (BTx_IER_CMPHIE_Msk);
	}
	else
	{
		BTx->IER &= ~(BTx_IER_CMPHIE_Msk);
	}
}

FunState BTx_IER_CMPHIE_Getable(BT_Type* BTx)
{
	if (BTx->IER & (BTx_IER_CMPHIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��չ��ʱ����λ�ȽϷ����ź� (compare lowend interrupt enable)
1 = �ж�ʹ��
0 = �жϽ�ֹ ��غ��� */
void BTx_IER_CMPLIE_Setable(BT_Type* BTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		BTx->IER |= (BTx_IER_CMPLIE_Msk);
	}
	else
	{
		BTx->IER &= ~(BTx_IER_CMPLIE_Msk);
	}
}

FunState BTx_IER_CMPLIE_Getable(BT_Type* BTx)
{
	if (BTx->IER & (BTx_IER_CMPLIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��ʱ����λ����ź� (highend overflow interrupt enable)
1 = �ж�ʹ��
0 = �жϽ�ֹ ��غ��� */
void BTx_IER_OVHIE_Setable(BT_Type* BTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		BTx->IER |= (BTx_IER_OVHIE_Msk);
	}
	else
	{
		BTx->IER &= ~(BTx_IER_OVHIE_Msk);
	}
}

FunState BTx_IER_OVHIE_Getable(BT_Type* BTx)
{
	if (BTx->IER & (BTx_IER_OVHIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��ʱ����λ����ź� (lowend overflow interrupt enable)
1 = �ж�ʹ��
0 = �жϽ�ֹ ��غ��� */
void BTx_IER_OVLIE_Setable(BT_Type* BTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		BTx->IER |= (BTx_IER_OVLIE_Msk);
	}
	else
	{
		BTx->IER &= ~(BTx_IER_OVLIE_Msk);
	}
}

FunState BTx_IER_OVLIE_Getable(BT_Type* BTx)
{
	if (BTx->IER & (BTx_IER_OVLIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��ʱ����׽�����ź� (capture interrupt enable)
1 = �ж�ʹ��
0 = �жϽ�ֹ ��غ��� */
void BTx_IER_CAPIE_Setable(BT_Type* BTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		BTx->IER |= (BTx_IER_CAPIE_Msk);
	}
	else
	{
		BTx->IER &= ~(BTx_IER_CAPIE_Msk);
	}
}

FunState BTx_IER_CAPIE_Getable(BT_Type* BTx)
{
	if (BTx->IER & (BTx_IER_CAPIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽��״̬
1 = ��׽������
0 = ��׽������ */
FlagStatus BTx_ISR_EDGESTA_Chk(BT_Type* BTx)
{
	if (BTx->ISR & BTx_ISR_EDGESTA_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��ʱ����λ�ȽϷ����ź� (compare highend interrupt flag)
1 = ��ǰ��������ֵ���ڵ��ڱȽϼĴ�����ֵ�����źŽ����¼����µļ��ؼĴ�����ֵ�������Ĵ�����
0 = ��ǰ��������ֵС�ڱȽϼĴ�����ֵ ��غ��� */
void BTx_ISR_CMPHIF_Clr(BT_Type* BTx)
{
	BTx->ISR = BTx_ISR_CMPHIF_Msk;
}

FlagStatus BTx_ISR_CMPHIF_Chk(BT_Type* BTx)
{
	if (BTx->ISR & BTx_ISR_CMPHIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��ʱ����λ�ȽϷ����ź� (compare lowend interrupt flag)
1 = ��ǰ��������ֵ���ڵ��ڱȽϼĴ�����ֵ�����źŽ����¼����µļ��ؼĴ�����ֵ�������Ĵ�����
0 = ��ǰ��������ֵС�ڱȽϼĴ�����ֵ ��غ��� */
void BTx_ISR_CMPLIF_Clr(BT_Type* BTx)
{
	BTx->ISR = BTx_ISR_CMPLIF_Msk;
}

FlagStatus BTx_ISR_CMPLIF_Chk(BT_Type* BTx)
{
	if (BTx->ISR & BTx_ISR_CMPLIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��ʱ����λ����ź� (highend overflow interrupt flag)
1 = �����������
0 = δ������� ��غ��� */
void BTx_ISR_OVHIF_Clr(BT_Type* BTx)
{
	BTx->ISR = BTx_ISR_OVHIF_Msk;
}

FlagStatus BTx_ISR_OVHIF_Chk(BT_Type* BTx)
{
	if (BTx->ISR & BTx_ISR_OVHIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��ʱ����λ����ź� (lowend overflow interrupt flag)
1 = �����������
0 = δ������� ��غ��� */
void BTx_ISR_OVLIF_Clr(BT_Type* BTx)
{
	BTx->ISR = BTx_ISR_OVLIF_Msk;
}

FlagStatus BTx_ISR_OVLIF_Chk(BT_Type* BTx)
{
	if (BTx->ISR & BTx_ISR_OVLIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��ʱ����׽�����ź� (capture interrupt flag)
1 = ��׽��ָ������
0 = δ��׽��ָ������ ��غ��� */
void BTx_ISR_CAPIF_Clr(BT_Type* BTx)
{
	BTx->ISR = BTx_ISR_CAPIF_Msk;
}

FlagStatus BTx_ISR_CAPIF_Chk(BT_Type* BTx)
{
	if (BTx->ISR & BTx_ISR_CAPIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}


void BTx_Deinit(BT_Type* BTx)
{
	//BTx->CR1  = 0x00000000;
	//BTx->CR2  = 0x00000000;
	//BTx->CFGR1  = 0x00000000;
	//BTx->CFGR2  = 0x00000000;
	//BTx->PRES  = 0x00000000;
	//BTx->LOADCR = 0x00000000;
	//BTx->CNTL  = 0x00000000;
	//BTx->CNTH  = 0x00000000;
	//BTx->PRESET  = 0x00000000;
	//BTx->LOADL  = 0x00000000;
	//BTx->LOADH  = 0x00000000;
	//BTx->CMPL  = 0x00000000;
	//BTx->CMPH  = 0x00000000;
	//BTx->OUTCNT  = 0x00000000;
	//BTx->OCR = ;
	//BTx->IER = 0x00000000;
	//BTx->ISR = 0x00000000;
}
/******END OF FILE****/
