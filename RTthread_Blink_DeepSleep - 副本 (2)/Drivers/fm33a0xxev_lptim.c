/**
  ******************************************************************************
  * @file    fm33a0xxev_lptim.c
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/

#include "fm33a0xxev_lptim.h"

/** @addtogroup fm33a0xxev_StdPeriph_Driver
  * @{
  */

/** @defgroup LPTIM 
  * @brief LPTIM driver modules
  * @{
  */ 

/* LPT_ETR����ģ���˲�ʹ��(External Trigger input Analog Filter Enable)
0���ر�ģ���˲�
1��ʹ��ģ���˲����˲����Լ100ns ��غ��� */
void LPTIM_CFGR_ETR_AFEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPTIM->CFGR |= (LPTIM_CFGR_ETR_AFEN_Msk);
	}
	else
	{
		LPTIM->CFGR &= ~(LPTIM_CFGR_ETR_AFEN_Msk);
	}
}

FunState LPTIM_CFGR_ETR_AFEN_Getable(void)
{
	if (LPTIM->CFGR & (LPTIM_CFGR_ETR_AFEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ʱ��Ԥ��Ƶ����ѡ��(Prescaler input Select)
0��CLKSELѡ���ʱ��
1��LPTETRF ��غ��� */
void LPTIM_CFGR_PSCSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->CFGR;
	tmpreg &= ~(LPTIM_CFGR_PSCSEL_Msk);
	tmpreg |= (SetValue & LPTIM_CFGR_PSCSEL_Msk);
	LPTIM->CFGR = tmpreg;
}

uint32_t LPTIM_CFGR_PSCSEL_Get(void)
{
	return (LPTIM->CFGR & LPTIM_CFGR_PSCSEL_Msk);
}

/* ����ʱ�ӷ�Ƶѡ��(Counter Clock Divider Select)
000��1��Ƶ
001��2��Ƶ
010��4��Ƶ
011��8��Ƶ
100��16��Ƶ
101��32��Ƶ
110��64��Ƶ
111��128��Ƶ ��غ��� */
void LPTIM_CFGR_DIVSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->CFGR;
	tmpreg &= ~(LPTIM_CFGR_DIVSEL_Msk);
	tmpreg |= (SetValue & LPTIM_CFGR_DIVSEL_Msk);
	LPTIM->CFGR = tmpreg;
}

uint32_t LPTIM_CFGR_DIVSEL_Get(void)
{
	return (LPTIM->CFGR & LPTIM_CFGR_DIVSEL_Msk);
}

/* ETR�������ѡ��(ETR Clock Edge Select)
0��LPT_ETR�������ؼ���
1��LPT_ETR���½��ؼ��� ��غ��� */
void LPTIM_CFGR_EDGESEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->CFGR;
	tmpreg &= ~(LPTIM_CFGR_EDGESEL_Msk);
	tmpreg |= (SetValue & LPTIM_CFGR_EDGESEL_Msk);
	LPTIM->CFGR = tmpreg;
}

uint32_t LPTIM_CFGR_EDGESEL_Get(void)
{
	return (LPTIM->CFGR & LPTIM_CFGR_EDGESEL_Msk);
}

/* �ⲿ��������ѡ����ʹ���ڲ�ʱ��ͬ������LPT_ETR��(ETR trigger Configuration)
00: LPT_ETR�����ź������ش���
01: LPT_ETR�����ź��½��ش���
10/11: �ⲿ�����ź������½��ش��� ��غ��� */
void LPTIM_CFGR_TRIGCFG_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->CFGR;
	tmpreg &= ~(LPTIM_CFGR_TRIGCFG_Msk);
	tmpreg |= (SetValue & LPTIM_CFGR_TRIGCFG_Msk);
	LPTIM->CFGR = tmpreg;
}

uint32_t LPTIM_CFGR_TRIGCFG_Get(void)
{
	return (LPTIM->CFGR & LPTIM_CFGR_TRIGCFG_Msk);
}

/* ���μ���ģʽʹ��(One State Timer)
0����������ģʽ���������������󱣳����У�ֱ�����ر�Ϊֹ���������ﵽĿ��ֵ��ص�0���¿�ʼ����������������жϡ�
1�����μ���ģʽ���������������������Ŀ��ֵ��ص�0�����Զ�ֹͣ����������жϡ� ��غ��� */
void LPTIM_CFGR_ONST_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->CFGR;
	tmpreg &= ~(LPTIM_CFGR_ONST_Msk);
	tmpreg |= (SetValue & LPTIM_CFGR_ONST_Msk);
	LPTIM->CFGR = tmpreg;
}

uint32_t LPTIM_CFGR_ONST_Get(void)
{
	return (LPTIM->CFGR & LPTIM_CFGR_ONST_Msk);
}

/* ����ģʽѡ��(Timer operation Mode)
00����ͨ��ʱ��ģʽ
01��Trigger���崥������ģʽ
10���ⲿ�첽�������ģʽ
11��Timeoutģʽ ��غ��� */
void LPTIM_CFGR_TMODE_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->CFGR;
	tmpreg &= ~(LPTIM_CFGR_TMODE_Msk);
	tmpreg |= (SetValue & LPTIM_CFGR_TMODE_Msk);
	LPTIM->CFGR = tmpreg;
}

uint32_t LPTIM_CFGR_TMODE_Get(void)
{
	return (LPTIM->CFGR & LPTIM_CFGR_TMODE_Msk);
}

/* 32bit��������ǰ����ֵ(Counter 32bits-wide) ��غ��� */
uint32_t LPTIM_CNTR_Read(void)
{
	return (LPTIM->CNTR);
}

/* ͨ��1��׽Դѡ��(Capture channel 1 source select)������CH1ͨ������Ϊ���벶׽ʱ��Ч
00��LPT_CH1����
01��XTLF
10��RCLP
11��RCMF ��غ��� */
void LPTIM_CCSR_CAP1SSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->CCSR;
	tmpreg &= ~(LPTIM_CCSR_CAP1SSEL_Msk);
	tmpreg |= (SetValue & LPTIM_CCSR_CAP1SSEL_Msk);
	LPTIM->CCSR = tmpreg;
}

uint32_t LPTIM_CCSR_CAP1SSEL_Get(void)
{
	return (LPTIM->CCSR & LPTIM_CCSR_CAP1SSEL_Msk);
}

/* ͨ��4��ǰ����׽�ı��أ���CC2IF��λʱ����(Channel 4 Captured Edge)
0��������
1���½��� ��غ��� */
void LPTIM_CCSR_CAP4EDGE_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->CCSR;
	tmpreg &= ~(LPTIM_CCSR_CAP4EDGE_Msk);
	tmpreg |= (SetValue & LPTIM_CCSR_CAP4EDGE_Msk);
	LPTIM->CCSR = tmpreg;
}

uint32_t LPTIM_CCSR_CAP4EDGE_Get(void)
{
	return (LPTIM->CCSR & LPTIM_CCSR_CAP4EDGE_Msk);
}

void LPTIM_CCSR_CAP3EDGE_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->CCSR;
	tmpreg &= ~(LPTIM_CCSR_CAP3EDGE_Msk);
	tmpreg |= (SetValue & LPTIM_CCSR_CAP3EDGE_Msk);
	LPTIM->CCSR = tmpreg;
}

uint32_t LPTIM_CCSR_CAP3EDGE_Get(void)
{
	return (LPTIM->CCSR & LPTIM_CCSR_CAP3EDGE_Msk);
}

void LPTIM_CCSR_CAP2EDGE_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->CCSR;
	tmpreg &= ~(LPTIM_CCSR_CAP2EDGE_Msk);
	tmpreg |= (SetValue & LPTIM_CCSR_CAP2EDGE_Msk);
	LPTIM->CCSR = tmpreg;
}

uint32_t LPTIM_CCSR_CAP2EDGE_Get(void)
{
	return (LPTIM->CCSR & LPTIM_CCSR_CAP2EDGE_Msk);
}

void LPTIM_CCSR_CAP1EDGE_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->CCSR;
	tmpreg &= ~(LPTIM_CCSR_CAP1EDGE_Msk);
	tmpreg |= (SetValue & LPTIM_CCSR_CAP1EDGE_Msk);
	LPTIM->CCSR = tmpreg;
}

uint32_t LPTIM_CCSR_CAP1EDGE_Get(void)
{
	return (LPTIM->CCSR & LPTIM_CCSR_CAP1EDGE_Msk);
}

/* ͨ��4�Ƚ�������μ���ѡ�� (Channel 4 compare output Polarity)
0�������Բ��Σ���ʼΪ�ͣ�����ֵ==�Ƚ�ֵʱ�øߣ�����ֵ==ARRʱ�ָ�Ϊ��
1�������Բ��Σ������Բ���ȡ�� ��غ��� */
void LPTIM_CCSR_POLAR4_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->CCSR;
	tmpreg &= ~(LPTIM_CCSR_POLAR4_Msk);
	tmpreg |= (SetValue & LPTIM_CCSR_POLAR4_Msk);
	LPTIM->CCSR = tmpreg;
}

uint32_t LPTIM_CCSR_POLAR4_Get(void)
{
	return (LPTIM->CCSR & LPTIM_CCSR_POLAR4_Msk);
}

void LPTIM_CCSR_POLAR3_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->CCSR;
	tmpreg &= ~(LPTIM_CCSR_POLAR3_Msk);
	tmpreg |= (SetValue & LPTIM_CCSR_POLAR3_Msk);
	LPTIM->CCSR = tmpreg;
}

uint32_t LPTIM_CCSR_POLAR3_Get(void)
{
	return (LPTIM->CCSR & LPTIM_CCSR_POLAR3_Msk);
}

void LPTIM_CCSR_POLAR2_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->CCSR;
	tmpreg &= ~(LPTIM_CCSR_POLAR2_Msk);
	tmpreg |= (SetValue & LPTIM_CCSR_POLAR2_Msk);
	LPTIM->CCSR = tmpreg;
}

uint32_t LPTIM_CCSR_POLAR2_Get(void)
{
	return (LPTIM->CCSR & LPTIM_CCSR_POLAR2_Msk);
}

void LPTIM_CCSR_POLAR1_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->CCSR;
	tmpreg &= ~(LPTIM_CCSR_POLAR1_Msk);
	tmpreg |= (SetValue & LPTIM_CCSR_POLAR1_Msk);
	LPTIM->CCSR = tmpreg;
}

uint32_t LPTIM_CCSR_POLAR1_Get(void)
{
	return (LPTIM->CCSR & LPTIM_CCSR_POLAR1_Msk);
}

/* ͨ��4��׽����ѡ��(Channel 4 Capture edge Config)
00�������ز�׽
01���½��ز�׽
10�������½��ز�׽
11��RFU ��غ��� */
void LPTIM_CCSR_CAPCFG4_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->CCSR;
	tmpreg &= ~(LPTIM_CCSR_CAPCFG4_Msk);
	tmpreg |= (SetValue & LPTIM_CCSR_CAPCFG4_Msk);
	LPTIM->CCSR = tmpreg;
}

uint32_t LPTIM_CCSR_CAPCFG4_Get(void)
{
	return (LPTIM->CCSR & LPTIM_CCSR_CAPCFG4_Msk);
}

void LPTIM_CCSR_CAPCFG3_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->CCSR;
	tmpreg &= ~(LPTIM_CCSR_CAPCFG3_Msk);
	tmpreg |= (SetValue & LPTIM_CCSR_CAPCFG3_Msk);
	LPTIM->CCSR = tmpreg;
}

uint32_t LPTIM_CCSR_CAPCFG3_Get(void)
{
	return (LPTIM->CCSR & LPTIM_CCSR_CAPCFG3_Msk);
}

void LPTIM_CCSR_CAPCFG2_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->CCSR;
	tmpreg &= ~(LPTIM_CCSR_CAPCFG2_Msk);
	tmpreg |= (SetValue & LPTIM_CCSR_CAPCFG2_Msk);
	LPTIM->CCSR = tmpreg;
}

uint32_t LPTIM_CCSR_CAPCFG2_Get(void)
{
	return (LPTIM->CCSR & LPTIM_CCSR_CAPCFG2_Msk);
}

void LPTIM_CCSR_CAPCFG1_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->CCSR;
	tmpreg &= ~(LPTIM_CCSR_CAPCFG1_Msk);
	tmpreg |= (SetValue & LPTIM_CCSR_CAPCFG1_Msk);
	LPTIM->CCSR = tmpreg;
}

uint32_t LPTIM_CCSR_CAPCFG1_Get(void)
{
	return (LPTIM->CCSR & LPTIM_CCSR_CAPCFG1_Msk);
}

/* ͨ��4��׽/�ȽϹ���ʹ��(Channel 4 Capture/Compare Select)
00,11����ֹͨ��4��׽/�ȽϹ���
01��ʹ��ͨ��4��׽���ܣ�LPT_CH4Ϊ���룩
10��ʹ��ͨ��4�ȽϹ��ܣ�LPT_CH4Ϊ����� ��غ��� */
void LPTIM_CCSR_CC4S_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->CCSR;
	tmpreg &= ~(LPTIM_CCSR_CC4S_Msk);
	tmpreg |= (SetValue & LPTIM_CCSR_CC4S_Msk);
	LPTIM->CCSR = tmpreg;
}

uint32_t LPTIM_CCSR_CC4S_Get(void)
{
	return (LPTIM->CCSR & LPTIM_CCSR_CC4S_Msk);
}

void LPTIM_CCSR_CC3S_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->CCSR;
	tmpreg &= ~(LPTIM_CCSR_CC3S_Msk);
	tmpreg |= (SetValue & LPTIM_CCSR_CC3S_Msk);
	LPTIM->CCSR = tmpreg;
}

uint32_t LPTIM_CCSR_CC3S_Get(void)
{
	return (LPTIM->CCSR & LPTIM_CCSR_CC3S_Msk);
}

void LPTIM_CCSR_CC2S_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->CCSR;
	tmpreg &= ~(LPTIM_CCSR_CC2S_Msk);
	tmpreg |= (SetValue & LPTIM_CCSR_CC2S_Msk);
	LPTIM->CCSR = tmpreg;
}

uint32_t LPTIM_CCSR_CC2S_Get(void)
{
	return (LPTIM->CCSR & LPTIM_CCSR_CC2S_Msk);
}

void LPTIM_CCSR_CC1S_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->CCSR;
	tmpreg &= ~(LPTIM_CCSR_CC1S_Msk);
	tmpreg |= (SetValue & LPTIM_CCSR_CC1S_Msk);
	LPTIM->CCSR = tmpreg;
}

uint32_t LPTIM_CCSR_CC1S_Get(void)
{
	return (LPTIM->CCSR & LPTIM_CCSR_CC1S_Msk);
}

/* �Զ�����Ŀ��Ĵ���(Auto-Reload Register)
������������ֵ����ARRʱ���������ص���ֵ���¿�ʼ���ϼ��� ��غ��� */
void LPTIM_ARR_Write(uint32_t SetValue)
{
	LPTIM->ARR = (SetValue);
}

uint32_t LPTIM_ARR_Read(void)
{
	return (LPTIM->ARR);
}

/* ͨ��4��׽����ж�ʹ��(Channel 4 Over-Capture Interrupt Enable)
1�������ж�
0����ֹ�ж� ��غ��� */
void LPTIM_IER_OVR4IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPTIM->IER |= (LPTIM_IER_OVR4IE_Msk);
	}
	else
	{
		LPTIM->IER &= ~(LPTIM_IER_OVR4IE_Msk);
	}
}

FunState LPTIM_IER_OVR4IE_Getable(void)
{
	if (LPTIM->IER & (LPTIM_IER_OVR4IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ͨ��3��׽����ж�ʹ��(Channel 3 Over-Capture Interrupt Enable)
1�������ж�
0����ֹ�ж� ��غ��� */
void LPTIM_IER_OVR3IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPTIM->IER |= (LPTIM_IER_OVR3IE_Msk);
	}
	else
	{
		LPTIM->IER &= ~(LPTIM_IER_OVR3IE_Msk);
	}
}

FunState LPTIM_IER_OVR3IE_Getable(void)
{
	if (LPTIM->IER & (LPTIM_IER_OVR3IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ͨ��2��׽����ж�ʹ��(Channel 2 Over-Capture Interrupt Enable)
1�������ж�
0����ֹ�ж� ��غ��� */
void LPTIM_IER_OVR2IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPTIM->IER |= (LPTIM_IER_OVR2IE_Msk);
	}
	else
	{
		LPTIM->IER &= ~(LPTIM_IER_OVR2IE_Msk);
	}
}

FunState LPTIM_IER_OVR2IE_Getable(void)
{
	if (LPTIM->IER & (LPTIM_IER_OVR2IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ͨ��1��׽����ж�ʹ��(Channel 1 Over-Capture Interrupt Enable)
1�������ж�
0����ֹ�ж� ��غ��� */
void LPTIM_IER_OVR1IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPTIM->IER |= (LPTIM_IER_OVR1IE_Msk);
	}
	else
	{
		LPTIM->IER &= ~(LPTIM_IER_OVR1IE_Msk);
	}
}

FunState LPTIM_IER_OVR1IE_Getable(void)
{
	if (LPTIM->IER & (LPTIM_IER_OVR1IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �ⲿ���������ж�ʹ��λ(External Trigger Interrupt Enable)
1���ⲿ���������ж�ʹ��
0���ⲿ���������жϽ�ֹ ��غ��� */
void LPTIM_IER_TRIGIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPTIM->IER |= (LPTIM_IER_TRIGIE_Msk);
	}
	else
	{
		LPTIM->IER &= ~(LPTIM_IER_TRIGIE_Msk);
	}
}

FunState LPTIM_IER_TRIGIE_Getable(void)
{
	if (LPTIM->IER & (LPTIM_IER_TRIGIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ����������ж�ʹ��λ(Counter Over-Flow Interrupt Enable)
1������������ж�ʹ��
0������������жϽ�ֹ ��غ��� */
void LPTIM_IER_OVIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPTIM->IER |= (LPTIM_IER_OVIE_Msk);
	}
	else
	{
		LPTIM->IER &= ~(LPTIM_IER_OVIE_Msk);
	}
}

FunState LPTIM_IER_OVIE_Getable(void)
{
	if (LPTIM->IER & (LPTIM_IER_OVIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽/�Ƚ�ͨ��4�ж�ʹ��λ(Capture/Compare channel 4 Interrupt Enable)
1����׽/�Ƚ�ͨ��2�ж�ʹ��
0����׽/�Ƚ�ͨ��2�жϽ�ֹ ��غ��� */
void LPTIM_IER_CC4IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPTIM->IER |= (LPTIM_IER_CC4IE_Msk);
	}
	else
	{
		LPTIM->IER &= ~(LPTIM_IER_CC4IE_Msk);
	}
}

FunState LPTIM_IER_CC4IE_Getable(void)
{
	if (LPTIM->IER & (LPTIM_IER_CC4IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽/�Ƚ�ͨ��3�ж�ʹ��λ(Capture/Compare channel 3 Interrupt Enable)
1����׽/�Ƚ�ͨ��1�ж�ʹ��
0����׽/�Ƚ�ͨ��1�жϽ�ֹ ��غ��� */
void LPTIM_IER_CC3IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPTIM->IER |= (LPTIM_IER_CC3IE_Msk);
	}
	else
	{
		LPTIM->IER &= ~(LPTIM_IER_CC3IE_Msk);
	}
}

FunState LPTIM_IER_CC3IE_Getable(void)
{
	if (LPTIM->IER & (LPTIM_IER_CC3IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽/�Ƚ�ͨ��2�ж�ʹ��λ(Capture/Compare channel 2 Interrupt Enable)
1����׽/�Ƚ�ͨ��2�ж�ʹ��
0����׽/�Ƚ�ͨ��2�жϽ�ֹ ��غ��� */
void LPTIM_IER_CC2IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPTIM->IER |= (LPTIM_IER_CC2IE_Msk);
	}
	else
	{
		LPTIM->IER &= ~(LPTIM_IER_CC2IE_Msk);
	}
}

FunState LPTIM_IER_CC2IE_Getable(void)
{
	if (LPTIM->IER & (LPTIM_IER_CC2IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽/�Ƚ�ͨ��1�ж�ʹ��λ(Capture/Compare channel 1 Interrupt Enable)
1����׽/�Ƚ�ͨ��1�ж�ʹ��
0����׽/�Ƚ�ͨ��1�жϽ�ֹ ��غ��� */
void LPTIM_IER_CC1IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPTIM->IER |= (LPTIM_IER_CC1IE_Msk);
	}
	else
	{
		LPTIM->IER &= ~(LPTIM_IER_CC1IE_Msk);
	}
}

FunState LPTIM_IER_CC1IE_Getable(void)
{
	if (LPTIM->IER & (LPTIM_IER_CC1IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

void LPTIM_ISR_CAP4OVR_Clr(void)
{
	LPTIM->ISR = LPTIM_ISR_CAP4OVR_Msk;
}

FlagStatus LPTIM_ISR_CAP4OVR_Chk(void)
{
	if (LPTIM->ISR & LPTIM_ISR_CAP4OVR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

void LPTIM_ISR_CAP3OVR_Clr(void)
{
	LPTIM->ISR = LPTIM_ISR_CAP3OVR_Msk;
}

FlagStatus LPTIM_ISR_CAP3OVR_Chk(void)
{
	if (LPTIM->ISR & LPTIM_ISR_CAP3OVR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

void LPTIM_ISR_CAP2OVR_Clr(void)
{
	LPTIM->ISR = LPTIM_ISR_CAP2OVR_Msk;
}

FlagStatus LPTIM_ISR_CAP2OVR_Chk(void)
{
	if (LPTIM->ISR & LPTIM_ISR_CAP2OVR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

void LPTIM_ISR_CAP1OVR_Clr(void)
{
	LPTIM->ISR = LPTIM_ISR_CAP1OVR_Msk;
}

FlagStatus LPTIM_ISR_CAP1OVR_Chk(void)
{
	if (LPTIM->ISR & LPTIM_ISR_CAP1OVR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

void LPTIM_ISR_TRIGIF_Clr(void)
{
	LPTIM->ISR = LPTIM_ISR_TRIGIF_Msk;
}

FlagStatus LPTIM_ISR_TRIGIF_Chk(void)
{
	if (LPTIM->ISR & LPTIM_ISR_TRIGIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

void LPTIM_ISR_OVIF_Clr(void)
{
	LPTIM->ISR = LPTIM_ISR_OVIF_Msk;
}

FlagStatus LPTIM_ISR_OVIF_Chk(void)
{
	if (LPTIM->ISR & LPTIM_ISR_OVIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

void LPTIM_ISR_CC4IF_Clr(void)
{
	LPTIM->ISR = LPTIM_ISR_CC4IF_Msk;
}

FlagStatus LPTIM_ISR_CC4IF_Chk(void)
{
	if (LPTIM->ISR & LPTIM_ISR_CC4IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

void LPTIM_ISR_CC3IF_Clr(void)
{
	LPTIM->ISR = LPTIM_ISR_CC3IF_Msk;
}

FlagStatus LPTIM_ISR_CC3IF_Chk(void)
{
	if (LPTIM->ISR & LPTIM_ISR_CC3IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

void LPTIM_ISR_CC2IF_Clr(void)
{
	LPTIM->ISR = LPTIM_ISR_CC2IF_Msk;
}

FlagStatus LPTIM_ISR_CC2IF_Chk(void)
{
	if (LPTIM->ISR & LPTIM_ISR_CC2IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

void LPTIM_ISR_CC1IF_Clr(void)
{
	LPTIM->ISR = LPTIM_ISR_CC1IF_Msk;
}

FlagStatus LPTIM_ISR_CC1IF_Chk(void)
{
	if (LPTIM->ISR & LPTIM_ISR_CC1IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* LPTIMʹ��λ(LPTIM Enable)
1��ʹ�ܼ���������
0����ֹ���������� ��غ��� */
void LPTIM_CR_EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPTIM->CR |= (LPTIM_CR_EN_Msk);
	}
	else
	{
		LPTIM->CR &= ~(LPTIM_CR_EN_Msk);
	}
}

FunState LPTIM_CR_EN_Getable(void)
{
	if (LPTIM->CR & (LPTIM_CR_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽/�Ƚ�ֵ�Ĵ���1 (Channel1 Capture/Compare Register) ��غ��� */
void LPTIM_CCR1_Write(uint32_t SetValue)
{
	LPTIM->CCR1 = (SetValue);
}

uint32_t LPTIM_CCR1_Read(void)
{
	return (LPTIM->CCR1);
}

/* ��׽/�Ƚ�ֵ�Ĵ���2 (Channel2 Capture/Compare Register) ��غ��� */
void LPTIM_CCR2_Write(uint32_t SetValue)
{
	LPTIM->CCR2 = (SetValue);
}

uint32_t LPTIM_CCR2_Read(void)
{
	return (LPTIM->CCR2);
}

/* ��׽/�Ƚ�ֵ�Ĵ���3 (Channel3 Capture/Compare Register) ��غ��� */
void LPTIM_CCR3_Write(uint32_t SetValue)
{
	LPTIM->CCR3 = (SetValue);
}

uint32_t LPTIM_CCR3_Read(void)
{
	return (LPTIM->CCR3);
}

/* ��׽/�Ƚ�ֵ�Ĵ���4 (Channel4 Capture/Compare Register) ��غ��� */
void LPTIM_CCR4_Write(uint32_t SetValue)
{
	LPTIM->CCR4 = (SetValue);
}

uint32_t LPTIM_CCR4_Read(void)
{
	return (LPTIM->CCR4);
}

void LPTIM_Deinit(void)
{
	//LPTIM->CFGR = 0x00000000;
	//LPTIM->CNTR = 0x00000000;
	//LPTIM->CCSR = ;
	//LPTIM->ARR = 0x00000000;
	//LPTIM->IER = 0x00000000;
	//LPTIM->ISR = ;
	//LPTIM->CR = 0x00000000;
	//LPTIM->CCR1 = 0x00000000;
}

/******END OF FILE****/
