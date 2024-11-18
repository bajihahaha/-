/**
  ******************************************************************************
  * @file    fm33a0xxev_comp.h
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file contains all the functions prototypes for the COMP firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33A0XXEV_COMP_H
#define __FM33A0XXEV_COMP_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33A0XXEV.h" 
   
#define	COMP_CR1_DFLEN_Pos	19	/* �Ƚ���1��������˲��������üĴ������˲�����������DFLEN+1
00010��3��APBCLK����
����
11111��32��APBCLK���� */
#define	COMP_CR1_DFLEN_Msk	(0x1fU << COMP_CR1_DFLEN_Pos)
#define	COMP_CR1_DFLEN_X3	(0x2U << COMP_CR1_DFLEN_Pos)	/* 3��APBCLK���� */
#define	COMP_CR1_DFLEN_X32	(0x1fU << COMP_CR1_DFLEN_Pos)	/* 32��APBCLK���� */

#define	COMP_CR1_WINMODE_Pos	18	/* �Ƚ���1����ģʽ���ƼĴ���
0����ֹ����ģʽ
1��ʹ�ܴ���ģʽ */
#define	COMP_CR1_WINMODE_Msk	(0x1U << COMP_CR1_WINMODE_Pos)
	/* ��ֹ����ģʽ */
	/* ʹ�ܴ���ģʽ */

#define	COMP_CR1_POLAR_Pos	17	/* �Ƚ���1������Կ���
0���������
1��ȡ����� */
#define	COMP_CR1_POLAR_Msk	(0x1U << COMP_CR1_POLAR_Pos)
#define	COMP_CR1_POLAR_POS	(0x0U << COMP_CR1_POLAR_Pos)	/* ������� */
#define	COMP_CR1_POLAR_NEG	(0x1U << COMP_CR1_POLAR_Pos)	/* ȡ����� */

#define	COMP_CR1_DFEN_Pos	16	/* �Ƚ���1��������˲�ʹ��
0����ֹ��������˲�
1��ʹ����������˲� */
#define	COMP_CR1_DFEN_Msk	(0x1U << COMP_CR1_DFEN_Pos)
	/* ��ֹ��������˲� */
	/* ʹ����������˲� */

#define	COMP_CR1_CMP1OR_Pos	9	/* �Ƚ���1����������˲�ǰ�������ֻ�� */
#define	COMP_CR1_CMP1OR_Msk	(0x1U << COMP_CR1_CMP1OR_Pos)

#define	COMP_CR1_CMP1OF_Pos	8	/* �Ƚ���1����������˲��󣩣����ֻ�� */
#define	COMP_CR1_CMP1OF_Msk	(0x1U << COMP_CR1_CMP1OF_Pos)

#define	COMP_CR1_V1NSEL_Pos	4	/* �Ƚ���1��������ѡ��
000��COMP1_INN1
001��COMP1_INN2
010��VREF
011��3/4 VREF
100��1/2 VREF
101��1/4 VREF
110��1/8 VREF
111��RFU */
#define	COMP_CR1_V1NSEL_Msk	(0x7U << COMP_CR1_V1NSEL_Pos)
#define	COMP_CR1_V1NSEL_COMP1_INN1	(0x0U << COMP_CR1_V1NSEL_Pos)	/* COMP1_INN1 */
#define	COMP_CR1_V1NSEL_COMP1_INN2	(0x1U << COMP_CR1_V1NSEL_Pos)	/* COMP1_INN2 */
#define	COMP_CR1_V1NSEL_VREF	(0x2U << COMP_CR1_V1NSEL_Pos)	/* VREF */
#define	COMP_CR1_V1NSEL_3_4_VREF	(0x3U << COMP_CR1_V1NSEL_Pos)	/* 3/4 VREF */
#define	COMP_CR1_V1NSEL_1_2_VREF	(0x4U << COMP_CR1_V1NSEL_Pos)	/* 1/2 VREF */
#define	COMP_CR1_V1NSEL_1_4_VREF	(0x5U << COMP_CR1_V1NSEL_Pos)	/* 1/4 VREF */
#define	COMP_CR1_V1NSEL_1_8_VREF	(0x6U << COMP_CR1_V1NSEL_Pos)	/* 1/8 VREF */

#define	COMP_CR1_V1PSEL_Pos	1	/* �Ƚ���1��������ѡ��
00��COMP1_INP1
01��COMP1_INP2
10��COMP1_INP3
11��COMP1_INP4 */
#define	COMP_CR1_V1PSEL_Msk	(0x3U << COMP_CR1_V1PSEL_Pos)
#define	COMP_CR1_V1PSEL_COMP1_INP1	(0x0U << COMP_CR1_V1PSEL_Pos)	/* COMP1_INP1 */
#define	COMP_CR1_V1PSEL_COMP1_INP2	(0x1U << COMP_CR1_V1PSEL_Pos)	/* COMP1_INP2 */
#define	COMP_CR1_V1PSEL_COMP1_INP3	(0x2U << COMP_CR1_V1PSEL_Pos)	/* COMP1_INP3 */
#define	COMP_CR1_V1PSEL_COMP1_INP4	(0x3U << COMP_CR1_V1PSEL_Pos)	/* COMP1_INP4 */

#define	COMP_CR1_CMP1EN_Pos	0	/* �Ƚ���1ʹ��λ
0���رձȽ���1
1��ʹ�ܱȽ���1 */
#define	COMP_CR1_CMP1EN_Msk	(0x1U << COMP_CR1_CMP1EN_Pos)
	/* �رձȽ���1 */
	/* ʹ�ܱȽ���1 */

#define	COMP_CR2_DFLEN_Pos	19	/* �Ƚ���1��������˲��������üĴ������˲�����������DFLEN+1
00010��3��APBCLK����
����
11111��32��APBCLK���� */
#define	COMP_CR2_DFLEN_Msk	(0x1fU << COMP_CR2_DFLEN_Pos)
#define	COMP_CR2_DFLEN_X3	(0x2U << COMP_CR2_DFLEN_Pos)	/* 3��APBCLK���� */
#define	COMP_CR2_DFLEN_X32	(0x1fU << COMP_CR2_DFLEN_Pos)	/* 32��APBCLK���� */

#define	COMP_CR2_WINMODE_Pos	18	/* �Ƚ���2����ģʽ���ƼĴ���
0����ֹ����ģʽ
1��ʹ�ܴ���ģʽ */
#define	COMP_CR2_WINMODE_Msk	(0x1U << COMP_CR2_WINMODE_Pos)
	/* ��ֹ����ģʽ */
	/* ʹ�ܴ���ģʽ */

#define	COMP_CR2_POLAR_Pos	17	/* �Ƚ���2������Կ���
0���������
1��ȡ����� */
#define	COMP_CR2_POLAR_Msk	(0x1U << COMP_CR2_POLAR_Pos)
#define	COMP_CR2_POLAR_POS	(0x0U << COMP_CR2_POLAR_Pos)	/* ������� */
#define	COMP_CR2_POLAR_NEG	(0x1U << COMP_CR2_POLAR_Pos)	/* ȡ����� */

#define	COMP_CR2_DFEN_Pos	16	/* �Ƚ���2��������˲�ʹ��
0����ֹ��������˲�
1��ʹ����������˲� */
#define	COMP_CR2_DFEN_Msk	(0x1U << COMP_CR2_DFEN_Pos)
	/* ��ֹ��������˲� */
	/* ʹ����������˲� */

#define	COMP_CR2_CMP2OR_Pos	9	/* �Ƚ���2����������˲�ǰ�������ֻ�� */
#define	COMP_CR2_CMP2OR_Msk	(0x1U << COMP_CR2_CMP2OR_Pos)

#define	COMP_CR2_CMP2OF_Pos	8	/* �Ƚ���2����������˲��󣩣����ֻ�� */
#define	COMP_CR2_CMP2OF_Msk	(0x1U << COMP_CR2_CMP2OF_Pos)

#define	COMP_CR2_V2NSEL_Pos	4	/* �Ƚ���2��������ѡ��
000��COMP2_INN1
001��COMP2_INN2
010��VREF
011��3/4 VREF
100��1/2 VREF
101��1/4 VREF
110��1/8 VREF
111��REFIN(PD6) */
#define	COMP_CR2_V2NSEL_Msk	(0x7U << COMP_CR2_V2NSEL_Pos)
#define	COMP_CR2_V2NSEL_COMP2_INN1	(0x0U << COMP_CR2_V2NSEL_Pos)	/* COMP2_INN1 */
#define	COMP_CR2_V2NSEL_COMP2_INN2	(0x1U << COMP_CR2_V2NSEL_Pos)	/* COMP2_INN2 */
#define	COMP_CR2_V2NSEL_VREF	(0x2U << COMP_CR2_V2NSEL_Pos)	/* VREF */
#define	COMP_CR2_V2NSEL_3_4_VREF	(0x3U << COMP_CR2_V2NSEL_Pos)	/* 3/4 VREF */
#define	COMP_CR2_V2NSEL_1_2_VREF	(0x4U << COMP_CR2_V2NSEL_Pos)	/* 1/2 VREF */
#define	COMP_CR2_V2NSEL_1_4_VREF	(0x5U << COMP_CR2_V2NSEL_Pos)	/* 1/4 VREF */
#define	COMP_CR2_V2NSEL_1_8_VREF	(0x6U << COMP_CR2_V2NSEL_Pos)	/* 1/8 VREF */
#define	COMP_CR2_V2NSEL_REFIN     	(0x7U << COMP_CR2_V2NSEL_Pos)	/* REFIN(PD6) */

#define	COMP_CR2_V2PSEL_Pos	1	/* �Ƚ���2��������ѡ��
000��COMP2_INP1
001��COMP2_INP2
010��COMP1_INP1
011��COMP1_INP2
100��AVREF
101��VDD15
110, 111��RFU */
#define	COMP_CR2_V2PSEL_Msk	(0x7U << COMP_CR2_V2PSEL_Pos)
#define	COMP_CR2_V2PSEL_COMP2_INP1	(0x0U << COMP_CR2_V2PSEL_Pos)	/* COMP2_INP1 */
#define	COMP_CR2_V2PSEL_COMP2_INP2	(0x1U << COMP_CR2_V2PSEL_Pos)	/* COMP2_INP2 */
#define	COMP_CR2_V2PSEL_COMP1_INP1	(0x2U << COMP_CR2_V2PSEL_Pos)	/* COMP1_INP1 */
#define	COMP_CR2_V2PSEL_COMP1_INP2	(0x3U << COMP_CR2_V2PSEL_Pos)	/* COMP1_INP2 */
#define	COMP_CR2_V2PSEL_AVREF	(0x4U << COMP_CR2_V2PSEL_Pos)	/* AVREF */
#define	COMP_CR2_V2PSEL_VDD15	(0x5U << COMP_CR2_V2PSEL_Pos)	/* VDD15 */

#define	COMP_CR2_CMP2EN_Pos	0	/* �Ƚ���2ʹ��λ
0���رձȽ���2
1��ʹ�ܱȽ���2 */
#define	COMP_CR2_CMP2EN_Msk	(0x1U << COMP_CR2_CMP2EN_Pos)
	/* �رձȽ���2 */
	/* ʹ�ܱȽ���2 */

#define	COMP_ICR_OOW_IE_Pos	9	/* Out-Of-Window�ж�ʹ�� */
#define	COMP_ICR_OOW_IE_Msk	(0x1U << COMP_ICR_OOW_IE_Pos)

#define	COMP_ICR_WIN_IE_Pos	8	/* Window�ж�ʹ�� */
#define	COMP_ICR_WIN_IE_Msk	(0x1U << COMP_ICR_WIN_IE_Pos)

#define	COMP_ICR_BUFBYP_Pos	7	/* �Ƚ���Buffer Bypass
0����Bypass�Ƚ���Buffer
1��Bypass�Ƚ���Buffer */
#define	COMP_ICR_BUFBYP_Msk	(0x1U << COMP_ICR_BUFBYP_Pos)

#define	COMP_ICR_BUF_OFF_Pos	6	/* �Ƚ���Bufferʹ��
0��ʹ�ܱȽ���Buffer
1����ֹ�Ƚ���Buffer */
#define	COMP_ICR_BUF_OFF_Msk	(0x1U << COMP_ICR_BUF_OFF_Pos)

#define	COMP_ICR_CMP2SEL_Pos	4	/* �Ƚ���2�ж�Դѡ��
00/11���Ƚ���2����������½��ز����ж�
01���Ƚ���2��������ز����ж�
10���Ƚ���2����½��ز����ж� */
#define	COMP_ICR_CMP2SEL_Msk	(0x3U << COMP_ICR_CMP2SEL_Pos)
#define	COMP_ICR_CMP2SEL_BOTH	(0x0U << COMP_ICR_CMP2SEL_Pos)
#define	COMP_ICR_CMP2SEL_RISING	(0x1U << COMP_ICR_CMP2SEL_Pos)
#define	COMP_ICR_CMP2SEL_FALLING	(0x2U << COMP_ICR_CMP2SEL_Pos)

#define	COMP_ICR_CMP1SEL_Pos	2	/* �Ƚ���1�ж�Դѡ��
00/11���Ƚ���1����������½��ز����ж�
01���Ƚ���1��������ز����ж�
10���Ƚ���1����½��ز����ж� */
#define	COMP_ICR_CMP1SEL_Msk	(0x3U << COMP_ICR_CMP1SEL_Pos)
#define	COMP_ICR_CMP1SEL_BOTH	(0x0U << COMP_ICR_CMP1SEL_Pos)
#define	COMP_ICR_CMP1SEL_RISING	(0x1U << COMP_ICR_CMP1SEL_Pos)
#define	COMP_ICR_CMP1SEL_FALLING	(0x2U << COMP_ICR_CMP1SEL_Pos)

#define	COMP_ICR_CMP2IE_Pos	1	/* �Ƚ���2�ж�ʹ�� */
#define	COMP_ICR_CMP2IE_Msk	(0x1U << COMP_ICR_CMP2IE_Pos)

#define	COMP_ICR_CMP1IE_Pos	0	/* �Ƚ���1�ж�ʹ�� */
#define	COMP_ICR_CMP1IE_Msk	(0x1U << COMP_ICR_CMP1IE_Pos)

#define	COMP_ISR_OOW_IF_Pos	3	/* Out-of-Window�жϱ�־��Ӳ����λ�����д1���� */
#define	COMP_ISR_OOW_IF_Msk	(0x1U << COMP_ISR_OOW_IF_Pos)

#define	COMP_ISR_WIN_IF_Pos	2	/* Window�жϱ�־��Ӳ����λ�����д1���� */
#define	COMP_ISR_WIN_IF_Msk	(0x1U << COMP_ISR_WIN_IF_Pos)

#define	COMP_ISR_CMP2IF_Pos	1	/* �Ƚ���2�жϱ�־��Ӳ����λ�����д1���� */
#define	COMP_ISR_CMP2IF_Msk	(0x1U << COMP_ISR_CMP2IF_Pos)

#define	COMP_ISR_CMP1IF_Pos	0	/* �Ƚ���1�жϱ�־��Ӳ����λ�����д1���� */
#define	COMP_ISR_CMP1IF_Msk	(0x1U << COMP_ISR_CMP1IF_Pos)

#define	COMP_PCR_HSCMPBUF_EN_Pos	2	/* �Ƚ���BUFFER����ģʽ
0���͹���ģʽ
1������ģʽ */
#define	COMP_PCR_HSCMPBUF_EN_Msk	(0x1U << COMP_PCR_HSCMPBUF_EN_Pos)
#define	COMP_PCR_HSCMPBUF_EN_SLOW	(0x0U << COMP_PCR_HSCMPBUF_EN_Pos)	/* �͹���ģʽ */
#define	COMP_PCR_HSCMPBUF_EN_FAST	(0x1U << COMP_PCR_HSCMPBUF_EN_Pos)	/* ����ģʽ */

#define	COMP_PCR_HSCMP2_EN_Pos	1	/* �Ƚ���2����ģʽ
0���͹���ģʽ
1������ģʽ */
#define	COMP_PCR_HSCMP2_EN_Msk	(0x1U << COMP_PCR_HSCMP2_EN_Pos)
#define	COMP_PCR_HSCMP2_EN_SLOW	(0x0U << COMP_PCR_HSCMP2_EN_Pos)	/* �͹���ģʽ */
#define	COMP_PCR_HSCMP2_EN_FAST	(0x1U << COMP_PCR_HSCMP2_EN_Pos)	/* ����ģʽ */

#define	COMP_PCR_HSCMP1_EN_Pos	0	/* �Ƚ���1����ģʽ
0���͹���ģʽ
1������ģʽ */
#define	COMP_PCR_HSCMP1_EN_Msk	(0x1U << COMP_PCR_HSCMP1_EN_Pos)
#define	COMP_PCR_HSCMP1_EN_SLOW	(0x0U << COMP_PCR_HSCMP1_EN_Pos)	/* �͹���ģʽ */
#define	COMP_PCR_HSCMP1_EN_FAST	(0x1U << COMP_PCR_HSCMP1_EN_Pos)	/* ����ģʽ*/

//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void COMP_Deinit(void);

/* �Ƚ���1��������˲��������üĴ������˲�����������DFLEN+1
00010��3��APBCLK����
����
11111��32��APBCLK���� ��غ��� */
extern void COMP_CR1_DFLEN_Set(uint32_t SetValue);
extern uint32_t COMP_CR1_DFLEN_Get(void);

/* �Ƚ���1����ģʽ���ƼĴ���
0����ֹ����ģʽ
1��ʹ�ܴ���ģʽ ��غ��� */
extern void COMP_CR1_WINMODE_Setable(FunState NewState);
extern FunState COMP_CR1_WINMODE_Getable(void);

/* �Ƚ���1������Կ���
0���������
1��ȡ����� ��غ��� */
extern void COMP_CR1_POLAR_Set(uint32_t SetValue);
extern uint32_t COMP_CR1_POLAR_Get(void);

/* �Ƚ���1��������˲�ʹ��
0����ֹ��������˲�
1��ʹ����������˲� ��غ��� */
extern void COMP_CR1_DFEN_Setable(FunState NewState);
extern FunState COMP_CR1_DFEN_Getable(void);

/* �Ƚ���1����������˲�ǰ�������ֻ�� ��غ��� */
extern FlagStatus COMP_CR1_CMP1OR_Chk(void);

/* �Ƚ���1����������˲��󣩣����ֻ�� ��غ��� */
extern FlagStatus COMP_CR1_CMP1OF_Chk(void);

/* �Ƚ���1��������ѡ��
000��COMP1_INN1
001��COMP1_INN2
010��VREF
011��3/4 VREF
100��1/2 VREF
101��1/4 VREF
110��1/8 VREF
111��RFU ��غ��� */
extern void COMP_CR1_V1NSEL_Set(uint32_t SetValue);
extern uint32_t COMP_CR1_V1NSEL_Get(void);

/* �Ƚ���1��������ѡ��
00��COMP1_INP1
01��COMP1_INP2
10��COMP1_INP3
11��COMP1_INP4 ��غ��� */
extern void COMP_CR1_V1PSEL_Set(uint32_t SetValue);
extern uint32_t COMP_CR1_V1PSEL_Get(void);

/* �Ƚ���1ʹ��λ
0���رձȽ���1
1��ʹ�ܱȽ���1 ��غ��� */
extern void COMP_CR1_CMP1EN_Setable(FunState NewState);
extern FunState COMP_CR1_CMP1EN_Getable(void);

/* �Ƚ���2��������˲��������üĴ������˲�����������DFLEN+1
00010��3��APBCLK����
����
11111��32��APBCLK���� ��غ��� */
extern void COMP_CR2_DFLEN_Set(uint32_t SetValue);
extern uint32_t COMP_CR2_DFLEN_Get(void);

/* �Ƚ���2����ģʽ���ƼĴ���
0����ֹ����ģʽ
1��ʹ�ܴ���ģʽ ��غ��� */
extern void COMP_CR2_WINMODE_Setable(FunState NewState);
extern FunState COMP_CR2_WINMODE_Getable(void);

/* �Ƚ���2������Կ���
0���������
1��ȡ����� ��غ��� */
extern void COMP_CR2_POLAR_Set(uint32_t SetValue);
extern uint32_t COMP_CR2_POLAR_Get(void);

/* �Ƚ���2��������˲�ʹ��
0����ֹ��������˲�
1��ʹ����������˲� ��غ��� */
extern void COMP_CR2_DFEN_Setable(FunState NewState);
extern FunState COMP_CR2_DFEN_Getable(void);

/* �Ƚ���2����������˲�ǰ�������ֻ�� ��غ��� */
extern FlagStatus COMP_CR2_CMP2OR_Chk(void);

/* �Ƚ���2����������˲��󣩣����ֻ�� ��غ��� */
extern FlagStatus COMP_CR2_CMP2OF_Chk(void);

/* �Ƚ���2��������ѡ��
000��COMP2_INN1
001��COMP2_INN2
010��VREF
011��3/4 VREF
100��1/2 VREF
101��1/4 VREF
110��1/8 VREF
111��RFU */
extern void COMP_CR2_V2NSEL_Set(uint32_t SetValue);
extern uint32_t COMP_CR2_V2NSEL_Get(void);

/* �Ƚ���2��������ѡ��
000��COMP2_INP1
001��COMP2_INP2
010��COMP1_INP1
011��COMP1_INP2
100��AVREF
101��VDD15
110, 111��RFU ��غ��� */
extern void COMP_CR2_V2PSEL_Set(uint32_t SetValue);
extern uint32_t COMP_CR2_V2PSEL_Get(void);

/* �Ƚ���2ʹ��λ
0���رձȽ���2
1��ʹ�ܱȽ���2 ��غ��� */
extern void COMP_CR2_CMP2EN_Setable(FunState NewState);
extern FunState COMP_CR2_CMP2EN_Getable(void);

/* Out-Of-Window�ж�ʹ�� ��غ��� */
extern void COMP_ICR_OOW_IE_Setable(FunState NewState);
extern FunState COMP_ICR_OOW_IE_Getable(void);

/* Window�ж�ʹ�� ��غ��� */
extern void COMP_ICR_WIN_IE_Setable(FunState NewState);
extern FunState COMP_ICR_WIN_IE_Getable(void);

/* �Ƚ���Buffer Bypass
0����Bypass�Ƚ���Buffer
1��Bypass�Ƚ���Buffer ��غ��� */
extern void COMP_ICR_BUFBYP_Setable(FunState NewState);
extern FunState COMP_ICR_BUFBYP_Getable(void);

/* �Ƚ���Bufferʹ��
0��ʹ�ܱȽ���Buffer
1����ֹ�Ƚ���Buffer ��غ��� */
extern void COMP_ICR_BUF_OFF_Setable(FunState NewState);
extern FunState COMP_ICR_BUF_OFF_Getable(void);

/* �Ƚ���2�ж�Դѡ��
00/11���Ƚ���2����������½��ز����ж�
01���Ƚ���2��������ز����ж�
10���Ƚ���2����½��ز����ж� ��غ��� */
extern void COMP_ICR_CMP2SEL_Set(uint32_t SetValue);
extern uint32_t COMP_ICR_CMP2SEL_Get(void);

/* �Ƚ���1�ж�Դѡ��
00/11���Ƚ���1����������½��ز����ж�
01���Ƚ���1��������ز����ж�
10���Ƚ���1����½��ز����ж� ��غ��� */
extern void COMP_ICR_CMP1SEL_Set(uint32_t SetValue);
extern uint32_t COMP_ICR_CMP1SEL_Get(void);

/* �Ƚ���2�ж�ʹ�� ��غ��� */
extern void COMP_ICR_CMP2IE_Setable(FunState NewState);
extern FunState COMP_ICR_CMP2IE_Getable(void);

/* �Ƚ���1�ж�ʹ�� ��غ��� */
extern void COMP_ICR_CMP1IE_Setable(FunState NewState);
extern FunState COMP_ICR_CMP1IE_Getable(void);

/* Out-of-Window�жϱ�־��Ӳ����λ�����д1���� ��غ��� */
extern void COMP_ISR_OOW_IF_Clr(void);
extern FlagStatus COMP_ISR_OOW_IF_Chk(void);

/* Window�жϱ�־��Ӳ����λ�����д1���� ��غ��� */
extern void COMP_ISR_WIN_IF_Clr(void);
extern FlagStatus COMP_ISR_WIN_IF_Chk(void);

/* �Ƚ���2�жϱ�־��Ӳ����λ�����д1���� ��غ��� */
extern void COMP_ISR_CMP2IF_Clr(void);
extern FlagStatus COMP_ISR_CMP2IF_Chk(void);

/* �Ƚ���1�жϱ�־��Ӳ����λ�����д1���� ��غ��� */
extern void COMP_ISR_CMP1IF_Clr(void);
extern FlagStatus COMP_ISR_CMP1IF_Chk(void);

/* �Ƚ���BUFFER����ģʽ
0���͹���ģʽ
1������ģʽ ��غ��� */
extern void COMP_PCR_HSCMPBUF_EN_Set(uint32_t SetValue);
extern uint32_t COMP_PCR_HSCMPBUF_EN_Get(void);

/* �Ƚ���2����ģʽ
0���͹���ģʽ
1������ģʽ ��غ��� */
extern void COMP_PCR_HSCMP2_EN_Set(uint32_t SetValue);
extern uint32_t COMP_PCR_HSCMP2_EN_Get(void);

/* �Ƚ���1����ģʽ
0���͹���ģʽ
1������ģʽ ��غ��� */
extern void COMP_PCR_HSCMP1_EN_Set(uint32_t SetValue);
extern uint32_t COMP_PCR_HSCMP1_EN_Get(void);


//Announce_End
#ifdef __cplusplus
}
#endif

#endif /* __FM33A0XXEV_COMP_H */
