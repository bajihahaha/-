/**
  ******************************************************************************
  * @file    fm33a0xxev_pmu.h
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file contains all the functions prototypes for the PMU firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33A0XXEV_PMU_H
#define __FM33A0XXEV_PMU_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "FM33A0XXEV.h"
typedef struct
{
	uint32_t PMOD;				/*!<�͹���ģʽ����  */	
	uint32_t SLPDP;				/*!<DeepSleep���ƼĴ���  */
	FunState CVS;				/*!<�ں˵�ѹ����ʹ�ܿ���  */
	uint32_t SCR;				/*!<M0ϵͳ���ƼĴ�����һ������Ϊ0����  */	
	uint32_t TIA;				/*!�ɱ�̶��⻽���ӳ� */	
}PMU_SleepCfg_InitTypeDef;
   
#define	PMU_CR_LDO15EN_Pos	17	/* LDO15ʹ�ܱ�־λ
1��LDO15���ڹ���״̬
0��LDO15���ر� */
#define	PMU_CR_LDO15EN_Msk	(0x1U << PMU_CR_LDO15EN_Pos)

#define	PMU_CR_LDO15EN_B_Pos	16	/* LDO15ʹ�ܱ�־����У��λ */
#define	PMU_CR_LDO15EN_B_Msk	(0x1U << PMU_CR_LDO15EN_B_Pos)

#define	PMU_CR_WKFSEL_Pos	10	/* Sleep/DeepSleep���Ѻ��ϵͳƵ��
00��RCHF-8MHz
01��RCHF-16MHz
10��RCHF-24MHz
11��RCHF-32MHz */
#define	PMU_CR_WKFSEL_Msk	(0x3U << PMU_CR_WKFSEL_Pos)
#define	PMU_CR_WKFSEL_RCHF_8M	(0x0U << PMU_CR_WKFSEL_Pos)	/* RCHF-8MHz */
#define	PMU_CR_WKFSEL_RCHF_16M	(0x1U << PMU_CR_WKFSEL_Pos)	/* RCHF-16MHz */
#define	PMU_CR_WKFSEL_RCHF_24M	(0x2U << PMU_CR_WKFSEL_Pos)	/* RCHF-24MHz */
#define	PMU_CR_WKFSEL_RCHF_32M	(0x3U << PMU_CR_WKFSEL_Pos)	/* RCHF-32MHz */

#define	PMU_CR_SLPDP_Pos	9	/* DeepSleep���ƼĴ���
1��DeepSleepģʽʹ�ܣ��¹رջ�׼��ѹԴ
0������Sleepģʽ
��Sleep�£������λ��SLPDPλ��ΪDeepSleepģʽ��
��λ����Sleep����Ч */
#define	PMU_CR_SLPDP_Msk	(0x1U << PMU_CR_SLPDP_Pos)
#define	PMU_CR_SLPDP_DEEPSLEEP	(0x1U << PMU_CR_SLPDP_Pos)	/* DeepSleepģʽʹ�ܣ��¹رջ�׼��ѹԴ */
#define	PMU_CR_SLPDP_SLEEP	(0x0U << PMU_CR_SLPDP_Pos)	/* ����Sleepģʽ */

#define	PMU_CR_CVS_Pos	8	/* CoreVoltageScaling����
0���͹���ģʽ�²�ʹ���ں˵�ѹ����
1���͹���ģʽ�½����ں˵�ѹ
��λ����Sleep/DeepSleep/RTCBKPģʽ�������� */
#define	PMU_CR_CVS_Msk	(0x1U << PMU_CR_CVS_Pos)
#define	PMU_CR_CVS_DISABLE	(0x0U << PMU_CR_CVS_Pos)	/* �͹���ģʽ�²�ʹ���ں˵�ѹ���� */
#define	PMU_CR_CVS_ENABLE	(0x1U << PMU_CR_CVS_Pos)	/* �͹���ģʽ�½����ں˵�ѹ */

#define	PMU_CR_PMOD_Pos	0	/* �͹���ģʽ���üĴ���
00��Active mode / LP Active mode
01��LPRUN mode
10��Sleep mode / DeepSleep mode
11��RTCBKP mode */
#define	PMU_CR_PMOD_Msk	(0x3U << PMU_CR_PMOD_Pos)
#define	PMU_CR_PMOD_ACTIVE	(0x0U << PMU_CR_PMOD_Pos)	/* Active mode / LP Active mode */
#define	PMU_CR_PMOD_LPRUN 	(0x1U << PMU_CR_PMOD_Pos)	/* LPRUN mode */
#define	PMU_CR_PMOD_SLEEP	(0x2U << PMU_CR_PMOD_Pos)	/* Sleep mode / DeepSleep mode */

#define	PMU_WKTR_STPCLR_Pos	2	/* Flash Stop���ѿ���
0��Stop�źŵȴ�ʱ�ӽ�����ͬ������
1��Stop�ź��첽���� */
#define	PMU_WKTR_STPCLR_Msk	(0x1U << PMU_WKTR_STPCLR_Pos)
#define	PMU_WKTR_STPCLR_SYN	(0x0U << PMU_WKTR_STPCLR_Pos)	/* Stop�źŵȴ�ʱ�ӽ�����ͬ������ */
#define	PMU_WKTR_STPCLR_ASY	(0x1U << PMU_WKTR_STPCLR_Pos)	/* Stop�ź��첽���� */

#define	PMU_WKTR_T1A_Pos	0	/* �ɱ�̶��⻽���ӳ�
��DeepSleepģʽ�£�RCHFʱ�ӵ����󣬸��ݴ˼Ĵ������õȴ������ӳ�ʱ����ٶ�ȡFlashУ����
00��0us
01��2us
10��4us
11��8us */
#define	PMU_WKTR_T1A_Msk	(0x3U << PMU_WKTR_T1A_Pos)
#define	PMU_WKTR_T1A_0US	(0x0U << PMU_WKTR_T1A_Pos)	/* 0us */
#define	PMU_WKTR_T1A_2US	(0x1U << PMU_WKTR_T1A_Pos)	/* 2us */
#define	PMU_WKTR_T1A_4US	(0x2U << PMU_WKTR_T1A_Pos)	/* 4us */
#define	PMU_WKTR_T1A_8US	(0x3U << PMU_WKTR_T1A_Pos)	/* 8us */

#define	PMU_WKFR_ADCWKF_Pos	31	/* ADC�жϻ��ѱ�־���жϳ���ʱӲ���Զ����� */
#define	PMU_WKFR_ADCWKF_Msk	(0x1U << PMU_WKFR_ADCWKF_Pos)

#define	PMU_WKFR_RTCWKF_Pos	28	/* RTC�жϻ��ѱ�־���жϳ���ʱӲ���Զ����� */
#define	PMU_WKFR_RTCWKF_Msk	(0x1U << PMU_WKFR_RTCWKF_Pos)

#define	PMU_WKFR_SVDWKF_Pos	27	/* SVD�жϻ��ѱ�־���жϳ���ʱӲ���Զ����� */
#define	PMU_WKFR_SVDWKF_Msk	(0x1U << PMU_WKFR_SVDWKF_Pos)

#define	PMU_WKFR_LFDETWKF_Pos	26	/* 32768Hz����ͣ���жϻ��ѱ�־���жϳ���ʱӲ���Զ����� */
#define	PMU_WKFR_LFDETWKF_Msk	(0x1U << PMU_WKFR_LFDETWKF_Pos)

#define	PMU_WKFR_IOWKF_Pos	24	/* IO�жϻ��ѱ�־���жϳ���ʱӲ���Զ����� */
#define	PMU_WKFR_IOWKF_Msk	(0x1U << PMU_WKFR_IOWKF_Pos)

#define	PMU_WKFR_LPU1WKF_Pos	21	/* LPUART1�жϻ��ѱ�־���жϳ���ʱӲ���Զ����� */
#define	PMU_WKFR_LPU1WKF_Msk	(0x1U << PMU_WKFR_LPU1WKF_Pos)

#define	PMU_WKFR_LPU0WKF_Pos	20	/* LPUART0�жϻ��ѱ�־���жϳ���ʱӲ���Զ����� */
#define	PMU_WKFR_LPU0WKF_Msk	(0x1U << PMU_WKFR_LPU0WKF_Pos)

#define	PMU_WKFR_COMP_OOWF_Pos	19	/* �Ƚ���out-of-window���ѱ�־���жϳ���ʱӲ���Զ����� */
#define	PMU_WKFR_COMP_OOWF_Msk	(0x1U << PMU_WKFR_COMP_OOWF_Pos)

#define	PMU_WKFR_COMP_WINF_Pos	18	/* �Ƚ���window���ѱ�־���жϳ���ʱӲ���Զ����� */
#define	PMU_WKFR_COMP_WINF_Msk	(0x1U << PMU_WKFR_COMP_WINF_Pos)

#define	PMU_WKFR_COMP2WKF_Pos	17	/* �Ƚ���2�жϻ��ѱ�־���жϳ���ʱӲ���Զ����� */
#define	PMU_WKFR_COMP2WKF_Msk	(0x1U << PMU_WKFR_COMP2WKF_Pos)

#define	PMU_WKFR_COMP1WKF_Pos	16	/* �Ƚ���1�жϻ��ѱ�־���жϳ���ʱӲ���Զ����� */
#define	PMU_WKFR_COMP1WKF_Msk	(0x1U << PMU_WKFR_COMP1WKF_Pos)

#define	PMU_WKFR_LPTWKF_Pos	10	/*  _32�жϻ��ѱ�־���жϳ���ʱӲ���Զ����� */
#define	PMU_WKFR_LPTWKF_Msk	(0x1U << PMU_WKFR_LPTWKF_Pos)

#define	PMU_WKFR_BSTWKF_Pos	9	/* BSTIM32�жϻ��ѱ�־���жϳ���ʱӲ���Զ����� */
#define	PMU_WKFR_BSTWKF_Msk	(0x1U << PMU_WKFR_BSTWKF_Pos)

#define	PMU_WKFR_DBGWKF_Pos	8	/* CPU Debugger���ѱ�־�����д1���� */
#define	PMU_WKFR_DBGWKF_Msk	(0x1U << PMU_WKFR_DBGWKF_Pos)


#define	PMU_IER_SLPEIE_Pos	1	/* SLEEP�����ж�ʹ�� (Sleep mode Error Interrupt Enable)
1��ʹ��SLEEP�����ж�
0����ֹSLEEP�����ж� */
#define	PMU_IER_SLPEIE_Msk	(0x1U << PMU_IER_SLPEIE_Pos)
	/* ʹ��SLEEP�����ж� */
	/* ��ֹSLEEP�����ж� */

#define	PMU_IER_RTCEIE_Pos	0	/* RTCBKP�����ж�ʹ��(RTCBKP mode Error Interrupt Enable)
1��ʹ��RTCBKP�����ж�
0����ֹRTCBKP�����ж� */
#define	PMU_IER_RTCEIE_Msk	(0x1U << PMU_IER_RTCEIE_Pos)
	/* ʹ��RTCBKP�����ж� */
	/* ��ֹRTCBKP�����ж� */

#define	PMU_ISR_SLPEIF_Pos	1	/* SLEEP�����жϱ�־��Ӳ����λ�����д1���� (Sleep Error Interrupt Flag, write 1 to clear)
1����PMOD=2��h2��CPUִ��WFI/WFEָ��ǰ��λ��SLEEPDEEP�Ĵ���ʱ��λ
0����PMOD=2��h2��CPU��ȷ����SLEEP */
#define	PMU_ISR_SLPEIF_Msk	(0x1U << PMU_ISR_SLPEIF_Pos)

#define	PMU_ISR_RTCEIF_Pos	0	/* RTCBKP�����жϱ�־��Ӳ����λ�����д1����(RTC Error Interrupt Flag, write 1 to clear)
1����PMOD=2��h3��δ��дCPU�ڲ��Ĵ���SLEEPDEEP=1��Ȼ��ִ��WFI/WFEָ�����ϵͳʱ������USB PHY����ͼ����RTCBKPģʽ
0����PMOD=2��h3��CPU������ȷ����DEEP SLEEP */
#define	PMU_ISR_RTCEIF_Msk	(0x1U << PMU_ISR_RTCEIF_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void PMU_Deinit(void);

/* LDO15ʹ�ܱ�־λ
1��LDO15���ڹ���״̬
0��LDO15���ر� ��غ��� */
extern FlagStatus PMU_CR_LDO15EN_Chk(void);

/* LDO15ʹ�ܱ�־����У��λ ��غ��� */
extern FlagStatus PMU_CR_LDO15EN_B_Chk(void);

/* Sleep/DeepSleep���Ѻ��ϵͳƵ��
00��RCHF-8MHz
01��RCHF-16MHz
10��RCHF-24MHz
11��RCHF-32MHz ��غ��� */
extern void PMU_CR_WKFSEL_Set(uint32_t SetValue);
extern uint32_t PMU_CR_WKFSEL_Get(void);

/* DeepSleep���ƼĴ���
1��DeepSleepģʽʹ�ܣ��¹رջ�׼��ѹԴ
0������Sleepģʽ
��Sleep�£������λ��SLPDPλ��ΪDeepSleepģʽ��
��λ����Sleep����Ч ��غ��� */
extern void PMU_CR_SLPDP_Set(uint32_t SetValue);
extern uint32_t PMU_CR_SLPDP_Get(void);

/* CoreVoltageScaling����
0���͹���ģʽ�²�ʹ���ں˵�ѹ����
1���͹���ģʽ�½����ں˵�ѹ
��λ����Sleep/DeepSleep/RTCBKPģʽ�������� ��غ��� */
extern void PMU_CR_CVS_Set(uint32_t SetValue);
extern uint32_t PMU_CR_CVS_Get(void);

/* �͹���ģʽ���üĴ���
00��Active mode / LP Active mode
01��LPRUN mode
10��Sleep mode / DeepSleep mode
11��RTCBKP mode ��غ��� */
extern void PMU_CR_PMOD_Set(uint32_t SetValue);
extern uint32_t PMU_CR_PMOD_Get(void);

/* Flash Stop���ѿ���
0��Stop�źŵȴ�ʱ�ӽ�����ͬ������
1��Stop�ź��첽���� ��غ��� */
extern void PMU_WKTR_STPCLR_Set(uint32_t SetValue);
extern uint32_t PMU_WKTR_STPCLR_Get(void);

/* �ɱ�̶��⻽���ӳ�
��DeepSleepģʽ�£�RCHFʱ�ӵ����󣬸��ݴ˼Ĵ������õȴ������ӳ�ʱ����ٶ�ȡFlashУ����
00��0us
01��2us
10��4us
11��8us ��غ��� */
extern void PMU_WKTR_T1A_Set(uint32_t SetValue);
extern uint32_t PMU_WKTR_T1A_Get(void);

/* ADC�жϻ��ѱ�־���жϳ���ʱӲ���Զ����� ��غ��� */
extern FlagStatus PMU_WKFR_ADCWKF_Chk(void);

/* RTC�жϻ��ѱ�־���жϳ���ʱӲ���Զ����� ��غ��� */
extern FlagStatus PMU_WKFR_RTCWKF_Chk(void);

/* SVD�жϻ��ѱ�־���жϳ���ʱӲ���Զ����� ��غ��� */
extern FlagStatus PMU_WKFR_SVDWKF_Chk(void);

/* 32768Hz����ͣ���жϻ��ѱ�־���жϳ���ʱӲ���Զ����� ��غ��� */
extern FlagStatus PMU_WKFR_LFDETWKF_Chk(void);

/* IO�жϻ��ѱ�־���жϳ���ʱӲ���Զ����� ��غ��� */
extern FlagStatus PMU_WKFR_IOWKF_Chk(void);

/* LPUART1�жϻ��ѱ�־���жϳ���ʱӲ���Զ����� ��غ��� */
extern FlagStatus PMU_WKFR_LPU1WKF_Chk(void);

/* LPUART0�жϻ��ѱ�־���жϳ���ʱӲ���Զ����� ��غ��� */
extern FlagStatus PMU_WKFR_LPU0WKF_Chk(void);

/* �Ƚ���out-of-window���ѱ�־���жϳ���ʱӲ���Զ����� ��غ��� */
extern FlagStatus PMU_WKFR_COMP_OOWF_Chk(void);

/* �Ƚ���window���ѱ�־���жϳ���ʱӲ���Զ����� ��غ��� */
extern FlagStatus PMU_WKFR_COMP_WINF_Chk(void);

/* �Ƚ���2�жϻ��ѱ�־���жϳ���ʱӲ���Զ����� ��غ��� */
extern FlagStatus PMU_WKFR_COMP2WKF_Chk(void);

/* �Ƚ���1�жϻ��ѱ�־���жϳ���ʱӲ���Զ����� ��غ��� */
extern FlagStatus PMU_WKFR_COMP1WKF_Chk(void);

/*  _32�жϻ��ѱ�־���жϳ���ʱӲ���Զ����� ��غ��� */
extern FlagStatus PMU_WKFR_LPTWKF_Chk(void);

/* BSTIM32�жϻ��ѱ�־���жϳ���ʱӲ���Զ����� ��غ��� */
extern FlagStatus PMU_WKFR_BSTWKF_Chk(void);

/* CPU Debugger���ѱ�־�����д1���� ��غ��� */
extern void PMU_WKFR_DBGWKF_Clr(void);
extern FlagStatus PMU_WKFR_DBGWKF_Chk(void);


/* SLEEP�����ж�ʹ�� (Sleep mode Error Interrupt Enable)
1��ʹ��SLEEP�����ж�
0����ֹSLEEP�����ж� ��غ��� */
extern void PMU_IER_SLPEIE_Setable(FunState NewState);
extern FunState PMU_IER_SLPEIE_Getable(void);

/* RTCBKP�����ж�ʹ��(RTCBKP mode Error Interrupt Enable)
1��ʹ��RTCBKP�����ж�
0����ֹRTCBKP�����ж� ��غ��� */
extern void PMU_IER_RTCEIE_Setable(FunState NewState);
extern FunState PMU_IER_RTCEIE_Getable(void);

/* SLEEP�����жϱ�־��Ӳ����λ�����д1���� (Sleep Error Interrupt Flag, write 1 to clear)
1����PMOD=2��h2��CPUִ��WFI/WFEָ��ǰ��λ��SLEEPDEEP�Ĵ���ʱ��λ
0����PMOD=2��h2��CPU��ȷ����SLEEP ��غ��� */
extern void PMU_ISR_SLPEIF_Clr(void);
extern FlagStatus PMU_ISR_SLPEIF_Chk(void);

/* RTCBKP�����жϱ�־��Ӳ����λ�����д1����(RTC Error Interrupt Flag, write 1 to clear)
1����PMOD=2��h3��δ��дCPU�ڲ��Ĵ���SLEEPDEEP=1��Ȼ��ִ��WFI/WFEָ�����ϵͳʱ������USB PHY����ͼ����RTCBKPģʽ
0����PMOD=2��h3��CPU������ȷ����DEEP SLEEP ��غ��� */
extern void PMU_ISR_RTCEIF_Clr(void);
extern FlagStatus PMU_ISR_RTCEIF_Chk(void);

extern void PMU_WKFR_WKPxF_Clr(uint32_t NWKPinDef);
extern FlagStatus PMU_WKFR_WKPxF_Chk(uint32_t NWKPinDef);
extern void PMU_SleepCfg_Init(PMU_SleepCfg_InitTypeDef* SleepCfg_InitStruct);

//Announce_End
#ifdef __cplusplus
}
#endif

#endif /* __FM33A0XXEV_PMU_H */
