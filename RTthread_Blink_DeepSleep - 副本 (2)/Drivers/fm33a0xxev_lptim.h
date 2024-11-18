/**
  ******************************************************************************
  * @file    fm33a0xxev_lptim.h
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file contains all the functions prototypes for the LPTIM firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33A0XXEV_LPTIM_H
#define __FM33A0XXEV_LPTIM_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33A0XXEV.h"
   
#define	LPTIM_CFGR_ETR_AFEN_Pos	24	/* LPT_ETR����ģ���˲�ʹ��(External Trigger input Analog Filter Enable)
0���ر�ģ���˲�
1��ʹ��ģ���˲����˲����Լ100ns */
#define	LPTIM_CFGR_ETR_AFEN_Msk	(0x1U << LPTIM_CFGR_ETR_AFEN_Pos)
	/* �ر�ģ���˲� */
	/* ʹ��ģ���˲����˲����Լ100ns */

#define	LPTIM_CFGR_PSCSEL_Pos	14	/* ʱ��Ԥ��Ƶ����ѡ��(Prescaler input Select)
0��CLKSELѡ���ʱ��
1��LPTETRF */
#define	LPTIM_CFGR_PSCSEL_Msk	(0x1U << LPTIM_CFGR_PSCSEL_Pos)
#define	LPTIM_CFGR_PSCSEL_CLKSEL	(0x0U << LPTIM_CFGR_PSCSEL_Pos)	/* CLKSELѡ���ʱ�� */
#define	LPTIM_CFGR_PSCSEL_LPTETRF	(0x1U << LPTIM_CFGR_PSCSEL_Pos)	/* LPTETRF */

#define	LPTIM_CFGR_DIVSEL_Pos	10	/* ����ʱ�ӷ�Ƶѡ��(Counter Clock Divider Select)
000��1��Ƶ
001��2��Ƶ
010��4��Ƶ
011��8��Ƶ
100��16��Ƶ
101��32��Ƶ
110��64��Ƶ
111��128��Ƶ */
#define	LPTIM_CFGR_DIVSEL_Msk	(0x7U << LPTIM_CFGR_DIVSEL_Pos)
#define	LPTIM_CFGR_DIVSEL_DIV1	(0x0U << LPTIM_CFGR_DIVSEL_Pos)	/* 1��Ƶ */
#define	LPTIM_CFGR_DIVSEL_DIV2	(0x1U << LPTIM_CFGR_DIVSEL_Pos)	/* 2��Ƶ */
#define	LPTIM_CFGR_DIVSEL_DIV4	(0x2U << LPTIM_CFGR_DIVSEL_Pos)	/* 4��Ƶ */
#define	LPTIM_CFGR_DIVSEL_DIV8	(0x3U << LPTIM_CFGR_DIVSEL_Pos)	/* 8��Ƶ */
#define	LPTIM_CFGR_DIVSEL_DIV16	(0x4U << LPTIM_CFGR_DIVSEL_Pos)	/* 16��Ƶ */
#define	LPTIM_CFGR_DIVSEL_DIV32	(0x5U << LPTIM_CFGR_DIVSEL_Pos)	/* 32��Ƶ */
#define	LPTIM_CFGR_DIVSEL_DIV64	(0x6U << LPTIM_CFGR_DIVSEL_Pos)	/* 64��Ƶ */
#define	LPTIM_CFGR_DIVSEL_DIV128	(0x7U << LPTIM_CFGR_DIVSEL_Pos)	/* 128��Ƶ */

#define	LPTIM_CFGR_EDGESEL_Pos	7	/* ETR�������ѡ��(ETR Clock Edge Select)
0��LPT_ETR�������ؼ���
1��LPT_ETR���½��ؼ��� */
#define	LPTIM_CFGR_EDGESEL_Msk	(0x1U << LPTIM_CFGR_EDGESEL_Pos)
#define	LPTIM_CFGR_EDGESEL_RISING	(0x0U << LPTIM_CFGR_EDGESEL_Pos)	/* LPT_ETR�������ؼ��� */
#define	LPTIM_CFGR_EDGESEL_FALLING	(0x1U << LPTIM_CFGR_EDGESEL_Pos)	/* LPT_ETR���½��ؼ��� */

#define	LPTIM_CFGR_TRIGCFG_Pos	5	/* �ⲿ��������ѡ����ʹ���ڲ�ʱ��ͬ������LPT_ETR��(ETR trigger Configuration)
00: LPT_ETR�����ź������ش���
01: LPT_ETR�����ź��½��ش���
10/11: �ⲿ�����ź������½��ش��� */
#define	LPTIM_CFGR_TRIGCFG_Msk	(0x3U << LPTIM_CFGR_TRIGCFG_Pos)
#define	LPTIM_CFGR_TRIGCFG_RISING	(0x0U << LPTIM_CFGR_TRIGCFG_Pos)
#define	LPTIM_CFGR_TRIGCFG_FALLING	(0x1U << LPTIM_CFGR_TRIGCFG_Pos)
#define	LPTIM_CFGR_TRIGCFG_EXTERNAL	(0x2U << LPTIM_CFGR_TRIGCFG_Pos)

#define	LPTIM_CFGR_ONST_Pos	2	/* ���μ���ģʽʹ��(One State Timer)
0����������ģʽ���������������󱣳����У�ֱ�����ر�Ϊֹ���������ﵽĿ��ֵ��ص�0���¿�ʼ����������������жϡ�
1�����μ���ģʽ���������������������Ŀ��ֵ��ص�0�����Զ�ֹͣ����������жϡ� */
#define	LPTIM_CFGR_ONST_Msk	(0x1U << LPTIM_CFGR_ONST_Pos)
#define	LPTIM_CFGR_ONST_CONTINUE	(0x0U << LPTIM_CFGR_ONST_Pos)	/* ��������ģʽ */
#define	LPTIM_CFGR_ONST_SINGLE	(0x1U << LPTIM_CFGR_ONST_Pos)	/* ���μ���ģʽ */

#define	LPTIM_CFGR_TMODE_Pos	0	/* ����ģʽѡ��(Timer operation Mode)
00����ͨ��ʱ��ģʽ
01��Trigger���崥������ģʽ
10���ⲿ�첽�������ģʽ
11��Timeoutģʽ */
#define	LPTIM_CFGR_TMODE_Msk	(0x3U << LPTIM_CFGR_TMODE_Pos)
#define	LPTIM_CFGR_TMODE_COUNTER	(0x0U << LPTIM_CFGR_TMODE_Pos)
#define	LPTIM_CFGR_TMODE_PULSE	(0x1U << LPTIM_CFGR_TMODE_Pos)
#define	LPTIM_CFGR_TMODE_ASY	(0x2U << LPTIM_CFGR_TMODE_Pos)
#define	LPTIM_CFGR_TMODE_TIMEOUT	(0x3U << LPTIM_CFGR_TMODE_Pos)

#define	LPTIM_CNTR_CNT32_Pos	0	/* 32bit��������ǰ����ֵ(Counter 32bits-wide) */
#define	LPTIM_CNTR_CNT32_Msk	(0xffffffffU << LPTIM_CNTR_CNT32_Pos)

#define	LPTIM_CCSR_CAP1SSEL_Pos	24	/* ͨ��1��׽Դѡ��(Capture channel 1 source select)������CH1ͨ������Ϊ���벶׽ʱ��Ч
00��LPT_CH1����
01��XTLF
10��RCLP
11��RCMF */
#define	LPTIM_CCSR_CAP1SSEL_Msk	(0x3U << LPTIM_CCSR_CAP1SSEL_Pos)
#define	LPTIM_CCSR_CAP1SSEL_LPT_CH1	(0x0U << LPTIM_CCSR_CAP1SSEL_Pos)
#define	LPTIM_CCSR_CAP1SSEL_XTLF	(0x1U << LPTIM_CCSR_CAP1SSEL_Pos)
#define	LPTIM_CCSR_CAP1SSEL_RCLP	(0x2U << LPTIM_CCSR_CAP1SSEL_Pos)
#define	LPTIM_CCSR_CAP1SSEL_RCMF	(0x3U << LPTIM_CCSR_CAP1SSEL_Pos)

#define	LPTIM_CCSR_CAP4EDGE_Pos	23	/* ͨ��4��ǰ����׽�ı��أ���CC2IF��λʱ����(Channel 4 Captured Edge)
0��������
1���½��� */
#define	LPTIM_CCSR_CAP4EDGE_Msk	(0x1U << LPTIM_CCSR_CAP4EDGE_Pos)
#define	LPTIM_CCSR_CAP4EDGE_RISING	(0x0U << LPTIM_CCSR_CAP4EDGE_Pos)
#define	LPTIM_CCSR_CAP4EDGE_FALLING	(0x1U << LPTIM_CCSR_CAP4EDGE_Pos)

#define	LPTIM_CCSR_CAP3EDGE_Pos	22
#define	LPTIM_CCSR_CAP3EDGE_Msk	(0x1U << LPTIM_CCSR_CAP3EDGE_Pos)
#define	LPTIM_CCSR_CAP3EDGE_RISING	(0x0U << LPTIM_CCSR_CAP3EDGE_Pos)
#define	LPTIM_CCSR_CAP3EDGE_FALLING	(0x1U << LPTIM_CCSR_CAP3EDGE_Pos)

#define	LPTIM_CCSR_CAP2EDGE_Pos	21
#define	LPTIM_CCSR_CAP2EDGE_Msk	(0x1U << LPTIM_CCSR_CAP2EDGE_Pos)
#define	LPTIM_CCSR_CAP2EDGE_RISING	(0x0U << LPTIM_CCSR_CAP2EDGE_Pos)
#define	LPTIM_CCSR_CAP2EDGE_FALLING	(0x1U << LPTIM_CCSR_CAP2EDGE_Pos)

#define	LPTIM_CCSR_CAP1EDGE_Pos	20
#define	LPTIM_CCSR_CAP1EDGE_Msk	(0x1U << LPTIM_CCSR_CAP1EDGE_Pos)
#define	LPTIM_CCSR_CAP1EDGE_RISING	(0x0U << LPTIM_CCSR_CAP1EDGE_Pos)
#define	LPTIM_CCSR_CAP1EDGE_FALLING	(0x1U << LPTIM_CCSR_CAP1EDGE_Pos)

#define	LPTIM_CCSR_POLAR4_Pos	19	/* ͨ��4�Ƚ�������μ���ѡ�� (Channel 4 compare output Polarity)
0�������Բ��Σ���ʼΪ�ͣ�����ֵ==�Ƚ�ֵʱ�øߣ�����ֵ==ARRʱ�ָ�Ϊ��
1�������Բ��Σ������Բ���ȡ�� */
#define	LPTIM_CCSR_POLAR4_Msk	(0x1U << LPTIM_CCSR_POLAR4_Pos)
#define	LPTIM_CCSR_POLAR4_POS	(0x0U << LPTIM_CCSR_POLAR4_Pos)
#define	LPTIM_CCSR_POLAR4_NEG	(0x1U << LPTIM_CCSR_POLAR4_Pos)

#define	LPTIM_CCSR_POLAR3_Pos	18
#define	LPTIM_CCSR_POLAR3_Msk	(0x1U << LPTIM_CCSR_POLAR3_Pos)
#define	LPTIM_CCSR_POLAR3_POS	(0x0U << LPTIM_CCSR_POLAR3_Pos)
#define	LPTIM_CCSR_POLAR3_NEG	(0x1U << LPTIM_CCSR_POLAR3_Pos)

#define	LPTIM_CCSR_POLAR2_Pos	17
#define	LPTIM_CCSR_POLAR2_Msk	(0x1U << LPTIM_CCSR_POLAR2_Pos)
#define	LPTIM_CCSR_POLAR2_POS	(0x0U << LPTIM_CCSR_POLAR2_Pos)
#define	LPTIM_CCSR_POLAR2_NEG	(0x1U << LPTIM_CCSR_POLAR2_Pos)

#define	LPTIM_CCSR_POLAR1_Pos	16
#define	LPTIM_CCSR_POLAR1_Msk	(0x1U << LPTIM_CCSR_POLAR1_Pos)
#define	LPTIM_CCSR_POLAR1_POS	(0x0U << LPTIM_CCSR_POLAR1_Pos)
#define	LPTIM_CCSR_POLAR1_NEG	(0x1U << LPTIM_CCSR_POLAR1_Pos)

#define	LPTIM_CCSR_CAPCFG4_Pos	14	/* ͨ��4��׽����ѡ��(Channel 4 Capture edge Config)
00�������ز�׽
01���½��ز�׽
10�������½��ز�׽
11��RFU */
#define	LPTIM_CCSR_CAPCFG4_Msk	(0x3U << LPTIM_CCSR_CAPCFG4_Pos)
#define	LPTIM_CCSR_CAPCFG4_RISING	(0x0U << LPTIM_CCSR_CAPCFG4_Pos)
#define	LPTIM_CCSR_CAPCFG4_FALLING	(0x1U << LPTIM_CCSR_CAPCFG4_Pos)
#define	LPTIM_CCSR_CAPCFG4_BOTH	(0x2U << LPTIM_CCSR_CAPCFG4_Pos)

#define	LPTIM_CCSR_CAPCFG3_Pos	12
#define	LPTIM_CCSR_CAPCFG3_Msk	(0x3U << LPTIM_CCSR_CAPCFG3_Pos)
#define	LPTIM_CCSR_CAPCFG3_RISING	(0x0U << LPTIM_CCSR_CAPCFG3_Pos)
#define	LPTIM_CCSR_CAPCFG3_FALLING	(0x1U << LPTIM_CCSR_CAPCFG3_Pos)
#define	LPTIM_CCSR_CAPCFG3_BOTH	(0x2U << LPTIM_CCSR_CAPCFG3_Pos)

#define	LPTIM_CCSR_CAPCFG2_Pos	10
#define	LPTIM_CCSR_CAPCFG2_Msk	(0x3U << LPTIM_CCSR_CAPCFG2_Pos)
#define	LPTIM_CCSR_CAPCFG2_RISING	(0x0U << LPTIM_CCSR_CAPCFG2_Pos)
#define	LPTIM_CCSR_CAPCFG2_FALLING	(0x1U << LPTIM_CCSR_CAPCFG2_Pos)
#define	LPTIM_CCSR_CAPCFG2_BOTH	(0x2U << LPTIM_CCSR_CAPCFG2_Pos)

#define	LPTIM_CCSR_CAPCFG1_Pos	8
#define	LPTIM_CCSR_CAPCFG1_Msk	(0x3U << LPTIM_CCSR_CAPCFG1_Pos)
#define	LPTIM_CCSR_CAPCFG1_RISING	(0x0U << LPTIM_CCSR_CAPCFG1_Pos)
#define	LPTIM_CCSR_CAPCFG1_FALLING	(0x1U << LPTIM_CCSR_CAPCFG1_Pos)
#define	LPTIM_CCSR_CAPCFG1_BOTH	(0x2U << LPTIM_CCSR_CAPCFG1_Pos)

#define	LPTIM_CCSR_CC4S_Pos	6	/* ͨ��4��׽/�ȽϹ���ʹ��(Channel 4 Capture/Compare Select)
00,11����ֹͨ��4��׽/�ȽϹ���
01��ʹ��ͨ��4��׽���ܣ�LPT_CH4Ϊ���룩
10��ʹ��ͨ��4�ȽϹ��ܣ�LPT_CH4Ϊ����� */
#define	LPTIM_CCSR_CC4S_Msk	(0x3U << LPTIM_CCSR_CC4S_Pos)
#define	LPTIM_CCSR_CC4S_NON	(0x0U << LPTIM_CCSR_CC4S_Pos)
#define	LPTIM_CCSR_CC4S_LPT_CH4_IN	(0x1U << LPTIM_CCSR_CC4S_Pos)
#define	LPTIM_CCSR_CC4S_LPT_CH4_OUT	(0x2U << LPTIM_CCSR_CC4S_Pos)

#define	LPTIM_CCSR_CC3S_Pos	4
#define	LPTIM_CCSR_CC3S_Msk	(0x3U << LPTIM_CCSR_CC3S_Pos)
#define	LPTIM_CCSR_CC3S_NON	(0x0U << LPTIM_CCSR_CC3S_Pos)
#define	LPTIM_CCSR_CC3S_LPT_CH3_IN	(0x1U << LPTIM_CCSR_CC3S_Pos)
#define	LPTIM_CCSR_CC3S_LPT_CH3_OUT	(0x2U << LPTIM_CCSR_CC3S_Pos)

#define	LPTIM_CCSR_CC2S_Pos	2
#define	LPTIM_CCSR_CC2S_Msk	(0x3U << LPTIM_CCSR_CC2S_Pos)
#define	LPTIM_CCSR_CC2S_NON	(0x0U << LPTIM_CCSR_CC2S_Pos)
#define	LPTIM_CCSR_CC2S_LPT_CH2_IN	(0x1U << LPTIM_CCSR_CC2S_Pos)
#define	LPTIM_CCSR_CC2S_LPT_CH2_OUT	(0x2U << LPTIM_CCSR_CC2S_Pos)

#define	LPTIM_CCSR_CC1S_Pos	0
#define	LPTIM_CCSR_CC1S_Msk	(0x3U << LPTIM_CCSR_CC1S_Pos)
#define	LPTIM_CCSR_CC1S_NON	(0x0U << LPTIM_CCSR_CC1S_Pos)
#define	LPTIM_CCSR_CC1S_LPT_CH1_IN	(0x1U << LPTIM_CCSR_CC1S_Pos)
#define	LPTIM_CCSR_CC1S_LPT_CH1_OUT	(0x2U << LPTIM_CCSR_CC1S_Pos)

#define	LPTIM_ARR_ARR_Pos	0	/* �Զ�����Ŀ��Ĵ���(Auto-Reload Register)
������������ֵ����ARRʱ���������ص���ֵ���¿�ʼ���ϼ��� */
#define	LPTIM_ARR_ARR_Msk	(0xffffffffU << LPTIM_ARR_ARR_Pos)

#define	LPTIM_IER_OVR4IE_Pos	11	/* ͨ��4��׽����ж�ʹ��(Channel 4 Over-Capture Interrupt Enable)
1�������ж�
0����ֹ�ж� */
#define	LPTIM_IER_OVR4IE_Msk	(0x1U << LPTIM_IER_OVR4IE_Pos)
	/* �����ж� */
	/* ��ֹ�ж� */

#define	LPTIM_IER_OVR3IE_Pos	10	/* ͨ��3��׽����ж�ʹ��(Channel 3 Over-Capture Interrupt Enable)
1�������ж�
0����ֹ�ж� */
#define	LPTIM_IER_OVR3IE_Msk	(0x1U << LPTIM_IER_OVR3IE_Pos)
	/* �����ж� */
	/* ��ֹ�ж� */

#define	LPTIM_IER_OVR2IE_Pos	9	/* ͨ��2��׽����ж�ʹ��(Channel 2 Over-Capture Interrupt Enable)
1�������ж�
0����ֹ�ж� */
#define	LPTIM_IER_OVR2IE_Msk	(0x1U << LPTIM_IER_OVR2IE_Pos)
	/* �����ж� */
	/* ��ֹ�ж� */

#define	LPTIM_IER_OVR1IE_Pos	8	/* ͨ��1��׽����ж�ʹ��(Channel 1 Over-Capture Interrupt Enable)
1�������ж�
0����ֹ�ж� */
#define	LPTIM_IER_OVR1IE_Msk	(0x1U << LPTIM_IER_OVR1IE_Pos)
	/* �����ж� */
	/* ��ֹ�ж� */

#define	LPTIM_IER_TRIGIE_Pos	7	/* �ⲿ���������ж�ʹ��λ(External Trigger Interrupt Enable)
1���ⲿ���������ж�ʹ��
0���ⲿ���������жϽ�ֹ */
#define	LPTIM_IER_TRIGIE_Msk	(0x1U << LPTIM_IER_TRIGIE_Pos)
	/* �ⲿ���������ж�ʹ�� */
	/* �ⲿ���������жϽ�ֹ */

#define	LPTIM_IER_OVIE_Pos	6	/* ����������ж�ʹ��λ(Counter Over-Flow Interrupt Enable)
1������������ж�ʹ��
0������������жϽ�ֹ */
#define	LPTIM_IER_OVIE_Msk	(0x1U << LPTIM_IER_OVIE_Pos)
	/* ����������ж�ʹ�� */
	/* ����������жϽ�ֹ */

#define	LPTIM_IER_CC4IE_Pos	3	/* ��׽/�Ƚ�ͨ��4�ж�ʹ��λ(Capture/Compare channel 4 Interrupt Enable)
1����׽/�Ƚ�ͨ��2�ж�ʹ��
0����׽/�Ƚ�ͨ��2�жϽ�ֹ */
#define	LPTIM_IER_CC4IE_Msk	(0x1U << LPTIM_IER_CC4IE_Pos)
	/* ��׽/�Ƚ�ͨ��2�ж�ʹ�� */
	/* ��׽/�Ƚ�ͨ��2�жϽ�ֹ */

#define	LPTIM_IER_CC3IE_Pos	2	/* ��׽/�Ƚ�ͨ��3�ж�ʹ��λ(Capture/Compare channel 3 Interrupt Enable)
1����׽/�Ƚ�ͨ��1�ж�ʹ��
0����׽/�Ƚ�ͨ��1�жϽ�ֹ */
#define	LPTIM_IER_CC3IE_Msk	(0x1U << LPTIM_IER_CC3IE_Pos)
	/* ��׽/�Ƚ�ͨ��1�ж�ʹ�� */
	/* ��׽/�Ƚ�ͨ��1�жϽ�ֹ */

#define	LPTIM_IER_CC2IE_Pos	1	/* ��׽/�Ƚ�ͨ��2�ж�ʹ��λ(Capture/Compare channel 2 Interrupt Enable)
1����׽/�Ƚ�ͨ��2�ж�ʹ��
0����׽/�Ƚ�ͨ��2�жϽ�ֹ */
#define	LPTIM_IER_CC2IE_Msk	(0x1U << LPTIM_IER_CC2IE_Pos)
	/* ��׽/�Ƚ�ͨ��2�ж�ʹ�� */
	/* ��׽/�Ƚ�ͨ��2�жϽ�ֹ */

#define	LPTIM_IER_CC1IE_Pos	0	/* ��׽/�Ƚ�ͨ��1�ж�ʹ��λ(Capture/Compare channel 1 Interrupt Enable)
1����׽/�Ƚ�ͨ��1�ж�ʹ��
0����׽/�Ƚ�ͨ��1�жϽ�ֹ */
#define	LPTIM_IER_CC1IE_Msk	(0x1U << LPTIM_IER_CC1IE_Pos)
	/* ��׽/�Ƚ�ͨ��1�ж�ʹ�� */
	/* ��׽/�Ƚ�ͨ��1�жϽ�ֹ */

#define	LPTIM_ISR_CAP4OVR_Pos	11
#define	LPTIM_ISR_CAP4OVR_Msk	(0x1U << LPTIM_ISR_CAP4OVR_Pos)

#define	LPTIM_ISR_CAP3OVR_Pos	10
#define	LPTIM_ISR_CAP3OVR_Msk	(0x1U << LPTIM_ISR_CAP3OVR_Pos)

#define	LPTIM_ISR_CAP2OVR_Pos	9
#define	LPTIM_ISR_CAP2OVR_Msk	(0x1U << LPTIM_ISR_CAP2OVR_Pos)

#define	LPTIM_ISR_CAP1OVR_Pos	8
#define	LPTIM_ISR_CAP1OVR_Msk	(0x1U << LPTIM_ISR_CAP1OVR_Pos)

#define	LPTIM_ISR_TRIGIF_Pos	7
#define	LPTIM_ISR_TRIGIF_Msk	(0x1U << LPTIM_ISR_TRIGIF_Pos)

#define	LPTIM_ISR_OVIF_Pos	6
#define	LPTIM_ISR_OVIF_Msk	(0x1U << LPTIM_ISR_OVIF_Pos)

#define	LPTIM_ISR_CC4IF_Pos	3
#define	LPTIM_ISR_CC4IF_Msk	(0x1U << LPTIM_ISR_CC4IF_Pos)

#define	LPTIM_ISR_CC3IF_Pos	2
#define	LPTIM_ISR_CC3IF_Msk	(0x1U << LPTIM_ISR_CC3IF_Pos)

#define	LPTIM_ISR_CC2IF_Pos	1
#define	LPTIM_ISR_CC2IF_Msk	(0x1U << LPTIM_ISR_CC2IF_Pos)

#define	LPTIM_ISR_CC1IF_Pos	0
#define	LPTIM_ISR_CC1IF_Msk	(0x1U << LPTIM_ISR_CC1IF_Pos)

#define	LPTIM_CR_EN_Pos	0	/* LPTIMʹ��λ(LPTIM Enable)
1��ʹ�ܼ���������
0����ֹ���������� */
#define	LPTIM_CR_EN_Msk	(0x1U << LPTIM_CR_EN_Pos)
	/* ʹ�ܼ��������� */
	/* ��ֹ���������� */

#define	LPTIM_CCR1_CCR1_Pos	0	/* ��׽/�Ƚ�ֵ�Ĵ���1 (Channel1 Capture/Compare Register) */
#define	LPTIM_CCR1_CCR1_Msk	(0xffffffffU << LPTIM_CCR1_CCR1_Pos)

#define	LPTIM_CCR2_CCR2_Pos	0	/* ��׽/�Ƚ�ֵ�Ĵ���2 (Channel2 Capture/Compare Register) */
#define	LPTIM_CCR2_CCR2_Msk	(0xffffffffU << LPTIM_CCR2_CCR2_Pos)

#define	LPTIM_CCR3_CCR3_Pos	0	/* ��׽/�Ƚ�ֵ�Ĵ���3 (Channel3 Capture/Compare Register) */
#define	LPTIM_CCR3_CCR3_Msk	(0xffffffffU << LPTIM_CCR3_CCR3_Pos)

#define	LPTIM_CCR4_CCR4_Pos	0	/* ��׽/�Ƚ�ֵ�Ĵ���4 (Channel4 Capture/Compare Register) */
#define	LPTIM_CCR4_CCR4_Msk	(0xffffffffU << LPTIM_CCR4_CCR4_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void LPTIM_Deinit(void);

/* LPT_ETR����ģ���˲�ʹ��(External Trigger input Analog Filter Enable)
0���ر�ģ���˲�
1��ʹ��ģ���˲����˲����Լ100ns ��غ��� */
extern void LPTIM_CFGR_ETR_AFEN_Setable(FunState NewState);
extern FunState LPTIM_CFGR_ETR_AFEN_Getable(void);

/* ʱ��Ԥ��Ƶ����ѡ��(Prescaler input Select)
0��CLKSELѡ���ʱ��
1��LPTETRF ��غ��� */
extern void LPTIM_CFGR_PSCSEL_Set(uint32_t SetValue);
extern uint32_t LPTIM_CFGR_PSCSEL_Get(void);

/* ����ʱ�ӷ�Ƶѡ��(Counter Clock Divider Select)
000��1��Ƶ
001��2��Ƶ
010��4��Ƶ
011��8��Ƶ
100��16��Ƶ
101��32��Ƶ
110��64��Ƶ
111��128��Ƶ ��غ��� */
extern void LPTIM_CFGR_DIVSEL_Set(uint32_t SetValue);
extern uint32_t LPTIM_CFGR_DIVSEL_Get(void);

/* ETR�������ѡ��(ETR Clock Edge Select)
0��LPT_ETR�������ؼ���
1��LPT_ETR���½��ؼ��� ��غ��� */
extern void LPTIM_CFGR_EDGESEL_Set(uint32_t SetValue);
extern uint32_t LPTIM_CFGR_EDGESEL_Get(void);

/* �ⲿ��������ѡ����ʹ���ڲ�ʱ��ͬ������LPT_ETR��(ETR trigger Configuration)
00: LPT_ETR�����ź������ش���
01: LPT_ETR�����ź��½��ش���
10/11: �ⲿ�����ź������½��ش��� ��غ��� */
extern void LPTIM_CFGR_TRIGCFG_Set(uint32_t SetValue);
extern uint32_t LPTIM_CFGR_TRIGCFG_Get(void);

/* ���μ���ģʽʹ��(One State Timer)
0����������ģʽ���������������󱣳����У�ֱ�����ر�Ϊֹ���������ﵽĿ��ֵ��ص�0���¿�ʼ����������������жϡ�
1�����μ���ģʽ���������������������Ŀ��ֵ��ص�0�����Զ�ֹͣ����������жϡ� ��غ��� */
extern void LPTIM_CFGR_ONST_Set(uint32_t SetValue);
extern uint32_t LPTIM_CFGR_ONST_Get(void);

/* ����ģʽѡ��(Timer operation Mode)
00����ͨ��ʱ��ģʽ
01��Trigger���崥������ģʽ
10���ⲿ�첽�������ģʽ
11��Timeoutģʽ ��غ��� */
extern void LPTIM_CFGR_TMODE_Set(uint32_t SetValue);
extern uint32_t LPTIM_CFGR_TMODE_Get(void);

/* 32bit��������ǰ����ֵ(Counter 32bits-wide) ��غ��� */
extern uint32_t LPTIM_CNTR_Read(void);

/* ͨ��1��׽Դѡ��(Capture channel 1 source select)������CH1ͨ������Ϊ���벶׽ʱ��Ч
00��LPT_CH1����
01��XTLF
10��RCLP
11��RCMF ��غ��� */
extern void LPTIM_CCSR_CAP1SSEL_Set(uint32_t SetValue);
extern uint32_t LPTIM_CCSR_CAP1SSEL_Get(void);

/* ͨ��4��ǰ����׽�ı��أ���CC2IF��λʱ����(Channel 4 Captured Edge)
0��������
1���½��� ��غ��� */
extern void LPTIM_CCSR_CAP4EDGE_Set(uint32_t SetValue);
extern uint32_t LPTIM_CCSR_CAP4EDGE_Get(void);
extern void LPTIM_CCSR_CAP3EDGE_Set(uint32_t SetValue);
extern uint32_t LPTIM_CCSR_CAP3EDGE_Get(void);
extern void LPTIM_CCSR_CAP2EDGE_Set(uint32_t SetValue);
extern uint32_t LPTIM_CCSR_CAP2EDGE_Get(void);
extern void LPTIM_CCSR_CAP1EDGE_Set(uint32_t SetValue);
extern uint32_t LPTIM_CCSR_CAP1EDGE_Get(void);

/* ͨ��4�Ƚ�������μ���ѡ�� (Channel 4 compare output Polarity)
0�������Բ��Σ���ʼΪ�ͣ�����ֵ==�Ƚ�ֵʱ�øߣ�����ֵ==ARRʱ�ָ�Ϊ��
1�������Բ��Σ������Բ���ȡ�� ��غ��� */
extern void LPTIM_CCSR_POLAR4_Set(uint32_t SetValue);
extern uint32_t LPTIM_CCSR_POLAR4_Get(void);
extern void LPTIM_CCSR_POLAR3_Set(uint32_t SetValue);
extern uint32_t LPTIM_CCSR_POLAR3_Get(void);
extern void LPTIM_CCSR_POLAR2_Set(uint32_t SetValue);
extern uint32_t LPTIM_CCSR_POLAR2_Get(void);
extern void LPTIM_CCSR_POLAR1_Set(uint32_t SetValue);
extern uint32_t LPTIM_CCSR_POLAR1_Get(void);

/* ͨ��4��׽����ѡ��(Channel 4 Capture edge Config)
00�������ز�׽
01���½��ز�׽
10�������½��ز�׽
11��RFU ��غ��� */
extern void LPTIM_CCSR_CAPCFG4_Set(uint32_t SetValue);
extern uint32_t LPTIM_CCSR_CAPCFG4_Get(void);
extern void LPTIM_CCSR_CAPCFG3_Set(uint32_t SetValue);
extern uint32_t LPTIM_CCSR_CAPCFG3_Get(void);
extern void LPTIM_CCSR_CAPCFG2_Set(uint32_t SetValue);
extern uint32_t LPTIM_CCSR_CAPCFG2_Get(void);
extern void LPTIM_CCSR_CAPCFG1_Set(uint32_t SetValue);
extern uint32_t LPTIM_CCSR_CAPCFG1_Get(void);

/* ͨ��4��׽/�ȽϹ���ʹ��(Channel 4 Capture/Compare Select)
00,11����ֹͨ��4��׽/�ȽϹ���
01��ʹ��ͨ��4��׽���ܣ�LPT_CH4Ϊ���룩
10��ʹ��ͨ��4�ȽϹ��ܣ�LPT_CH4Ϊ����� ��غ��� */
extern void LPTIM_CCSR_CC4S_Set(uint32_t SetValue);
extern uint32_t LPTIM_CCSR_CC4S_Get(void);
extern void LPTIM_CCSR_CC3S_Set(uint32_t SetValue);
extern uint32_t LPTIM_CCSR_CC3S_Get(void);
extern void LPTIM_CCSR_CC2S_Set(uint32_t SetValue);
extern uint32_t LPTIM_CCSR_CC2S_Get(void);
extern void LPTIM_CCSR_CC1S_Set(uint32_t SetValue);
extern uint32_t LPTIM_CCSR_CC1S_Get(void);

/* �Զ�����Ŀ��Ĵ���(Auto-Reload Register)
������������ֵ����ARRʱ���������ص���ֵ���¿�ʼ���ϼ��� ��غ��� */
extern void LPTIM_ARR_Write(uint32_t SetValue);
extern uint32_t LPTIM_ARR_Read(void);

/* ͨ��4��׽����ж�ʹ��(Channel 4 Over-Capture Interrupt Enable)
1�������ж�
0����ֹ�ж� ��غ��� */
extern void LPTIM_IER_OVR4IE_Setable(FunState NewState);
extern FunState LPTIM_IER_OVR4IE_Getable(void);

/* ͨ��3��׽����ж�ʹ��(Channel 3 Over-Capture Interrupt Enable)
1�������ж�
0����ֹ�ж� ��غ��� */
extern void LPTIM_IER_OVR3IE_Setable(FunState NewState);
extern FunState LPTIM_IER_OVR3IE_Getable(void);

/* ͨ��2��׽����ж�ʹ��(Channel 2 Over-Capture Interrupt Enable)
1�������ж�
0����ֹ�ж� ��غ��� */
extern void LPTIM_IER_OVR2IE_Setable(FunState NewState);
extern FunState LPTIM_IER_OVR2IE_Getable(void);

/* ͨ��1��׽����ж�ʹ��(Channel 1 Over-Capture Interrupt Enable)
1�������ж�
0����ֹ�ж� ��غ��� */
extern void LPTIM_IER_OVR1IE_Setable(FunState NewState);
extern FunState LPTIM_IER_OVR1IE_Getable(void);

/* �ⲿ���������ж�ʹ��λ(External Trigger Interrupt Enable)
1���ⲿ���������ж�ʹ��
0���ⲿ���������жϽ�ֹ ��غ��� */
extern void LPTIM_IER_TRIGIE_Setable(FunState NewState);
extern FunState LPTIM_IER_TRIGIE_Getable(void);

/* ����������ж�ʹ��λ(Counter Over-Flow Interrupt Enable)
1������������ж�ʹ��
0������������жϽ�ֹ ��غ��� */
extern void LPTIM_IER_OVIE_Setable(FunState NewState);
extern FunState LPTIM_IER_OVIE_Getable(void);

/* ��׽/�Ƚ�ͨ��4�ж�ʹ��λ(Capture/Compare channel 4 Interrupt Enable)
1����׽/�Ƚ�ͨ��2�ж�ʹ��
0����׽/�Ƚ�ͨ��2�жϽ�ֹ ��غ��� */
extern void LPTIM_IER_CC4IE_Setable(FunState NewState);
extern FunState LPTIM_IER_CC4IE_Getable(void);

/* ��׽/�Ƚ�ͨ��3�ж�ʹ��λ(Capture/Compare channel 3 Interrupt Enable)
1����׽/�Ƚ�ͨ��1�ж�ʹ��
0����׽/�Ƚ�ͨ��1�жϽ�ֹ ��غ��� */
extern void LPTIM_IER_CC3IE_Setable(FunState NewState);
extern FunState LPTIM_IER_CC3IE_Getable(void);

/* ��׽/�Ƚ�ͨ��2�ж�ʹ��λ(Capture/Compare channel 2 Interrupt Enable)
1����׽/�Ƚ�ͨ��2�ж�ʹ��
0����׽/�Ƚ�ͨ��2�жϽ�ֹ ��غ��� */
extern void LPTIM_IER_CC2IE_Setable(FunState NewState);
extern FunState LPTIM_IER_CC2IE_Getable(void);

/* ��׽/�Ƚ�ͨ��1�ж�ʹ��λ(Capture/Compare channel 1 Interrupt Enable)
1����׽/�Ƚ�ͨ��1�ж�ʹ��
0����׽/�Ƚ�ͨ��1�жϽ�ֹ ��غ��� */
extern void LPTIM_IER_CC1IE_Setable(FunState NewState);
extern FunState LPTIM_IER_CC1IE_Getable(void);
extern void LPTIM_ISR_CAP4OVR_Clr(void);
extern FlagStatus LPTIM_ISR_CAP4OVR_Chk(void);
extern void LPTIM_ISR_CAP3OVR_Clr(void);
extern FlagStatus LPTIM_ISR_CAP3OVR_Chk(void);
extern void LPTIM_ISR_CAP2OVR_Clr(void);
extern FlagStatus LPTIM_ISR_CAP2OVR_Chk(void);
extern void LPTIM_ISR_CAP1OVR_Clr(void);
extern FlagStatus LPTIM_ISR_CAP1OVR_Chk(void);
extern void LPTIM_ISR_TRIGIF_Clr(void);
extern FlagStatus LPTIM_ISR_TRIGIF_Chk(void);
extern void LPTIM_ISR_OVIF_Clr(void);
extern FlagStatus LPTIM_ISR_OVIF_Chk(void);
extern void LPTIM_ISR_CC4IF_Clr(void);
extern FlagStatus LPTIM_ISR_CC4IF_Chk(void);
extern void LPTIM_ISR_CC3IF_Clr(void);
extern FlagStatus LPTIM_ISR_CC3IF_Chk(void);
extern void LPTIM_ISR_CC2IF_Clr(void);
extern FlagStatus LPTIM_ISR_CC2IF_Chk(void);
extern void LPTIM_ISR_CC1IF_Clr(void);
extern FlagStatus LPTIM_ISR_CC1IF_Chk(void);




/* LPTIMʹ��λ(LPTIM Enable)
1��ʹ�ܼ���������
0����ֹ���������� ��غ��� */
extern void LPTIM_CR_EN_Setable(FunState NewState);
extern FunState LPTIM_CR_EN_Getable(void);

/* ��׽/�Ƚ�ֵ�Ĵ���1 (Channel1 Capture/Compare Register) ��غ��� */
extern void LPTIM_CCR1_Write(uint32_t SetValue);
extern uint32_t LPTIM_CCR1_Read(void);
extern void LPTIM_Deinit(void);

/* ��׽/�Ƚ�ֵ�Ĵ���2 (Channel2 Capture/Compare Register) ��غ��� */
extern void LPTIM_CCR2_Write(uint32_t SetValue);
extern uint32_t LPTIM_CCR2_Read(void);
extern void LPTIM_Deinit(void);

/* ��׽/�Ƚ�ֵ�Ĵ���3 (Channel3 Capture/Compare Register) ��غ��� */
extern void LPTIM_CCR3_Write(uint32_t SetValue);
extern uint32_t LPTIM_CCR3_Read(void);

/* ��׽/�Ƚ�ֵ�Ĵ���4 (Channel4 Capture/Compare Register) ��غ��� */
extern void LPTIM_CCR4_Write(uint32_t SetValue);
extern uint32_t LPTIM_CCR4_Read(void);
//Announce_End
#ifdef __cplusplus
}
#endif

#endif /*__FM33A0XXEV_LPTIM_H */
