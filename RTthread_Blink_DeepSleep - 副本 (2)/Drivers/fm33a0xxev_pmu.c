/**
  ******************************************************************************
  * @file    fm33a0xxev_pmu.c
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/

#include "fm33a0xxev_pmu.h"

/** @addtogroup fm33a0xxev_StdPeriph_Driver
  * @{
  */

/** @defgroup PMU 
  * @brief PMU driver modules
  * @{
  */ 

/* LDO15ʹ�ܱ�־λ
1��LDO15���ڹ���״̬
0��LDO15���ر� ��غ��� */
FlagStatus PMU_CR_LDO15EN_Chk(void)
{
	if (PMU->CR & PMU_CR_LDO15EN_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* LDO15ʹ�ܱ�־����У��λ ��غ��� */
FlagStatus PMU_CR_LDO15EN_B_Chk(void)
{
	if (PMU->CR & PMU_CR_LDO15EN_B_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* Sleep/DeepSleep���Ѻ��ϵͳƵ��
00��RCHF-8MHz
01��RCHF-16MHz
10��RCHF-24MHz
11��RCHF-32MHz ��غ��� */
void PMU_CR_WKFSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = PMU->CR;
	tmpreg &= ~(PMU_CR_WKFSEL_Msk);
	tmpreg |= (SetValue & PMU_CR_WKFSEL_Msk);
	PMU->CR = tmpreg;
}

uint32_t PMU_CR_WKFSEL_Get(void)
{
	return (PMU->CR & PMU_CR_WKFSEL_Msk);
}

/* DeepSleep���ƼĴ���
1��DeepSleepģʽʹ�ܣ��¹رջ�׼��ѹԴ
0������Sleepģʽ
��Sleep�£������λ��SLPDPλ��ΪDeepSleepģʽ��
��λ����Sleep����Ч ��غ��� */
void PMU_CR_SLPDP_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = PMU->CR;
	tmpreg &= ~(PMU_CR_SLPDP_Msk);
	tmpreg |= (SetValue & PMU_CR_SLPDP_Msk);
	PMU->CR = tmpreg;
}

uint32_t PMU_CR_SLPDP_Get(void)
{
	return (PMU->CR & PMU_CR_SLPDP_Msk);
}

/* CoreVoltageScaling����
0���͹���ģʽ�²�ʹ���ں˵�ѹ����
1���͹���ģʽ�½����ں˵�ѹ
��λ����Sleep/DeepSleep/RTCBKPģʽ�������� ��غ��� */
void PMU_CR_CVS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = PMU->CR;
	tmpreg &= ~(PMU_CR_CVS_Msk);
	tmpreg |= (SetValue & PMU_CR_CVS_Msk);
	PMU->CR = tmpreg;
}

uint32_t PMU_CR_CVS_Get(void)
{
	return (PMU->CR & PMU_CR_CVS_Msk);
}

/* �͹���ģʽ���üĴ���
00��Active mode / LP Active mode
01��LPRUN mode
10��Sleep mode / DeepSleep mode
11��RTCBKP mode ��غ��� */
void PMU_CR_PMOD_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = PMU->CR;
	tmpreg &= ~(PMU_CR_PMOD_Msk);
	tmpreg |= (SetValue & PMU_CR_PMOD_Msk);
	PMU->CR = tmpreg;
}

uint32_t PMU_CR_PMOD_Get(void)
{
	return (PMU->CR & PMU_CR_PMOD_Msk);
}

/* Flash Stop���ѿ���
0��Stop�źŵȴ�ʱ�ӽ�����ͬ������
1��Stop�ź��첽���� ��غ��� */
void PMU_WKTR_STPCLR_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = PMU->WKTR;
	tmpreg &= ~(PMU_WKTR_STPCLR_Msk);
	tmpreg |= (SetValue & PMU_WKTR_STPCLR_Msk);
	PMU->WKTR = tmpreg;
}

uint32_t PMU_WKTR_STPCLR_Get(void)
{
	return (PMU->WKTR & PMU_WKTR_STPCLR_Msk);
}

/* �ɱ�̶��⻽���ӳ�
��DeepSleepģʽ�£�RCHFʱ�ӵ����󣬸��ݴ˼Ĵ������õȴ������ӳ�ʱ����ٶ�ȡFlashУ����
00��0us
01��2us
10��4us
11��8us ��غ��� */
void PMU_WKTR_T1A_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = PMU->WKTR;
	tmpreg &= ~(PMU_WKTR_T1A_Msk);
	tmpreg |= (SetValue & PMU_WKTR_T1A_Msk);
	PMU->WKTR = tmpreg;
}

uint32_t PMU_WKTR_T1A_Get(void)
{
	return (PMU->WKTR & PMU_WKTR_T1A_Msk);
}

/* ADC�жϻ��ѱ�־���жϳ���ʱӲ���Զ����� ��غ��� */
FlagStatus PMU_WKFR_ADCWKF_Chk(void)
{
	if (PMU->WKFR & PMU_WKFR_ADCWKF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* RTC�жϻ��ѱ�־���жϳ���ʱӲ���Զ����� ��غ��� */
FlagStatus PMU_WKFR_RTCWKF_Chk(void)
{
	if (PMU->WKFR & PMU_WKFR_RTCWKF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* SVD�жϻ��ѱ�־���жϳ���ʱӲ���Զ����� ��غ��� */
FlagStatus PMU_WKFR_SVDWKF_Chk(void)
{
	if (PMU->WKFR & PMU_WKFR_SVDWKF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 32768Hz����ͣ���жϻ��ѱ�־���жϳ���ʱӲ���Զ����� ��غ��� */
FlagStatus PMU_WKFR_LFDETWKF_Chk(void)
{
	if (PMU->WKFR & PMU_WKFR_LFDETWKF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* IO�жϻ��ѱ�־���жϳ���ʱӲ���Զ����� ��غ��� */
FlagStatus PMU_WKFR_IOWKF_Chk(void)
{
	if (PMU->WKFR & PMU_WKFR_IOWKF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* LPUART1�жϻ��ѱ�־���жϳ���ʱӲ���Զ����� ��غ��� */
FlagStatus PMU_WKFR_LPU1WKF_Chk(void)
{
	if (PMU->WKFR & PMU_WKFR_LPU1WKF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* LPUART0�жϻ��ѱ�־���жϳ���ʱӲ���Զ����� ��غ��� */
FlagStatus PMU_WKFR_LPU0WKF_Chk(void)
{
	if (PMU->WKFR & PMU_WKFR_LPU0WKF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* �Ƚ���out-of-window���ѱ�־���жϳ���ʱӲ���Զ����� ��غ��� */
FlagStatus PMU_WKFR_COMP_OOWF_Chk(void)
{
	if (PMU->WKFR & PMU_WKFR_COMP_OOWF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* �Ƚ���window���ѱ�־���жϳ���ʱӲ���Զ����� ��غ��� */
FlagStatus PMU_WKFR_COMP_WINF_Chk(void)
{
	if (PMU->WKFR & PMU_WKFR_COMP_WINF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* �Ƚ���2�жϻ��ѱ�־���жϳ���ʱӲ���Զ����� ��غ��� */
FlagStatus PMU_WKFR_COMP2WKF_Chk(void)
{
	if (PMU->WKFR & PMU_WKFR_COMP2WKF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* �Ƚ���1�жϻ��ѱ�־���жϳ���ʱӲ���Զ����� ��غ��� */
FlagStatus PMU_WKFR_COMP1WKF_Chk(void)
{
	if (PMU->WKFR & PMU_WKFR_COMP1WKF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/*  _32�жϻ��ѱ�־���жϳ���ʱӲ���Զ����� ��غ��� */
FlagStatus PMU_WKFR_LPTWKF_Chk(void)
{
	if (PMU->WKFR & PMU_WKFR_LPTWKF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* BSTIM32�жϻ��ѱ�־���жϳ���ʱӲ���Զ����� ��غ��� */
FlagStatus PMU_WKFR_BSTWKF_Chk(void)
{
	if (PMU->WKFR & PMU_WKFR_BSTWKF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* CPU Debugger���ѱ�־�����д1���� ��غ��� */
void PMU_WKFR_DBGWKF_Clr(void)
{
	PMU->WKFR = PMU_WKFR_DBGWKF_Msk;
}

FlagStatus PMU_WKFR_DBGWKF_Chk(void)
{
	if (PMU->WKFR & PMU_WKFR_DBGWKF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}


/* SLEEP�����ж�ʹ�� (Sleep mode Error Interrupt Enable)
1��ʹ��SLEEP�����ж�
0����ֹSLEEP�����ж� ��غ��� */
void PMU_IER_SLPEIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		PMU->IER |= (PMU_IER_SLPEIE_Msk);
	}
	else
	{
		PMU->IER &= ~(PMU_IER_SLPEIE_Msk);
	}
}

FunState PMU_IER_SLPEIE_Getable(void)
{
	if (PMU->IER & (PMU_IER_SLPEIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* RTCBKP�����ж�ʹ��(RTCBKP mode Error Interrupt Enable)
1��ʹ��RTCBKP�����ж�
0����ֹRTCBKP�����ж� ��غ��� */
void PMU_IER_RTCEIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		PMU->IER |= (PMU_IER_RTCEIE_Msk);
	}
	else
	{
		PMU->IER &= ~(PMU_IER_RTCEIE_Msk);
	}
}

FunState PMU_IER_RTCEIE_Getable(void)
{
	if (PMU->IER & (PMU_IER_RTCEIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* SLEEP�����жϱ�־��Ӳ����λ�����д1���� (Sleep Error Interrupt Flag, write 1 to clear)
1����PMOD=2��h2��CPUִ��WFI/WFEָ��ǰ��λ��SLEEPDEEP�Ĵ���ʱ��λ
0����PMOD=2��h2��CPU��ȷ����SLEEP ��غ��� */
void PMU_ISR_SLPEIF_Clr(void)
{
	PMU->ISR = PMU_ISR_SLPEIF_Msk;
}

FlagStatus PMU_ISR_SLPEIF_Chk(void)
{
	if (PMU->ISR & PMU_ISR_SLPEIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* RTCBKP�����жϱ�־��Ӳ����λ�����д1����(RTC Error Interrupt Flag, write 1 to clear)
1����PMOD=2��h3��δ��дCPU�ڲ��Ĵ���SLEEPDEEP=1��Ȼ��ִ��WFI/WFEָ�����ϵͳʱ������USB PHY����ͼ����RTCBKPģʽ
0����PMOD=2��h3��CPU������ȷ����DEEP SLEEP ��غ��� */
void PMU_ISR_RTCEIF_Clr(void)
{
	PMU->ISR = PMU_ISR_RTCEIF_Msk;
}

FlagStatus PMU_ISR_RTCEIF_Chk(void)
{
	if (PMU->ISR & PMU_ISR_RTCEIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}


void PMU_Deinit(void)
{
	//PMU->CR = 0x00020000;
	//PMU->WKTR = 0x00000001;
	//PMU->WKFR = 0x00000000;
	//PMU->IER = ;
	//PMU->ISR = ;
}

/********************************
���NWKUPx Pin���ѱ�־����
����:���NWKUPx Pin���ѱ�־����Sleep/DeepSleepģʽ����Ч��
���룺����NWKUPx Pin���ѱ�־������ֵ��д1.
 ********************************/
void PMU_WKFR_WKPxF_Clr(uint32_t NWKPinDef)
{
	PMU->WKFR = NWKPinDef;
}
/********************************
��ȡNWKUPx Pin���ѱ�־����
����:��ȡNWKUPx Pin���ѱ�־��
�����NWKUPx Pin���ѱ�־��ֵ
 ********************************/
FlagStatus PMU_WKFR_WKPxF_Chk(uint32_t NWKPinDef)
{
	if (PMU->WKFR & NWKPinDef)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
�͹���ģʽ�ĳ�ʼ������
����:�͹���ģʽ�¸������ã�SLEEPģʽ��RAM�������ã��ں˵�ѹ�������·�ȡ�
���룺�͹��Ĺ��ܿ���ǰ������.
 ********************************/
void PMU_SleepCfg_Init(PMU_SleepCfg_InitTypeDef* SleepCfg_InitStruct)
{
	PMU_CR_SLPDP_Set(SleepCfg_InitStruct->SLPDP);				/*!<DeepSleep���ƼĴ���  */	
	PMU_CR_CVS_Set(SleepCfg_InitStruct->CVS);				/*!<�ں˵�ѹ����ʹ�ܿ���  */	
	if(SleepCfg_InitStruct->SLPDP == PMU_CR_SLPDP_DEEPSLEEP)
	{
		PMU_WKTR_T1A_Set(SleepCfg_InitStruct->TIA);
	}		
	SCB->SCR = SleepCfg_InitStruct->SCR;							/*!<M0ϵͳ���ƼĴ�����һ������Ϊ0����  */
	PMU_CR_PMOD_Set(SleepCfg_InitStruct->PMOD);					/*!<�͹���ģʽ����  */

}

/******END OF FILE****/
