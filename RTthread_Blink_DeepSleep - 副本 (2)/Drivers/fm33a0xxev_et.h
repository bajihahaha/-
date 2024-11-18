/**
  ******************************************************************************
  * @file    fm33a0xxev_et.h
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file contains all the functions prototypes for the ET firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33A0XXEV_ET_H
#define __FM33A0XXEV_ET_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33A0XXEV.h" 
   
#define	ETx_CR_OPOL_Pos	10	/* �������ѡ�� (Output Polarity)
0�������ȡ��
1�����ȡ�� */
#define	ETx_CR_OPOL_Msk	(0x1U << ETx_CR_OPOL_Pos)
#define	ETx_CR_OPOL_NORMAL	(0x0U << ETx_CR_OPOL_Pos)	/* �����ȡ�� */
#define	ETx_CR_OPOL_REVERSE	(0x1U << ETx_CR_OPOL_Pos)	/* ���ȡ�� */

#define	ETx_CR_EXFLT_Pos	9	/* �ⲿ�������������˲�ʹ��
1 = �����������ź������˲�
0 = �ر����������ź������˲� */
#define	ETx_CR_EXFLT_Msk	(0x1U << ETx_CR_EXFLT_Pos)
#define	ETx_CR_EXFLT_OPEN	(0x1U << ETx_CR_EXFLT_Pos)
#define	ETx_CR_EXFLT_CLOSE	(0x0U << ETx_CR_EXFLT_Pos)

#define	ETx_CR_PWM_Pos	8	/* PWM�������
1 = PWM���ʹ��
0 = PWM�����ֹ */
#define	ETx_CR_PWM_Msk	(0x1U << ETx_CR_PWM_Pos)

#define	ETx_CR_CEN_Pos	7	/* ��������
1 = ������ʱ�����ڼ�����ģʽ������ʱ��������ֵ�������������͹����Ĵ������ڲ�׽ģʽ�£�����ʱ���������㿪ʼ���ɼ�����������0xFFFF���������ź�Ȼ�����㿪ʼ���¼���
0 = ֹͣ���������� */
#define	ETx_CR_CEN_Msk	(0x1U << ETx_CR_CEN_Pos)

#define	ETx_CR_MOD_Pos	6	/* ����ģʽѡ��
1 = ��׽ģʽ
0 = ��ʱ/����ģʽ */
#define	ETx_CR_MOD_Msk	(0x1U << ETx_CR_MOD_Pos)
#define	ETx_CR_MOD_CAPTURE	(0x1U << ETx_CR_MOD_Pos)
#define	ETx_CR_MOD_COUNTER	(0x0U << ETx_CR_MOD_Pos)

#define	ETx_CR_CASEN_Pos	5	/* Cascade Enable����չ��ʱ������ʹ��
1 = ET1��ET3����ET2��ET4��������32bit��ʱ��
0 = 16bit��ʱ���������� */
#define	ETx_CR_CASEN_Msk	(0x1U << ETx_CR_CASEN_Pos)
#define	ETx_CR_CASEN_32BITS	(0x1U << ETx_CR_CASEN_Pos)
#define	ETx_CR_CASEN_16BITS	(0x0U << ETx_CR_CASEN_Pos)

#define	ETx_CR_EDGESEL_Pos	4	/* ����ģʽ���ط�ʽѡ��
������ʱ��ѡ��mcu_clkʱ��λ��Ч�����ǲ���mcu_clkʱ�������ؼ�����
1 = ����ģʽ���½���
0 = ����ģʽ�������� */
#define	ETx_CR_EDGESEL_Msk	(0x1U << ETx_CR_EDGESEL_Pos)
#define	ETx_CR_EDGESEL_FALLING	(0x1U << ETx_CR_EDGESEL_Pos)
#define	ETx_CR_EDGESEL_RISING	(0x0U << ETx_CR_EDGESEL_Pos)

#define	ETx_CR_CAPMOD_Pos	3	/* ��׽ģʽ����
1 = ����׽
0 = �������ڲ�׽ */
#define	ETx_CR_CAPMOD_Msk	(0x1U << ETx_CR_CAPMOD_Pos)
#define	ETx_CR_CAPMOD_PULSE	(0x1U << ETx_CR_CAPMOD_Pos)
#define	ETx_CR_CAPMOD_CYCLE	(0x0U << ETx_CR_CAPMOD_Pos)

#define	ETx_CR_CAPCLR_Pos	2	/* �����㲶׽ģʽ����
1 = �¼�������׽��ʹ�ܺ����������0����׽����һ����Ч��֮��timer�ſ�ʼ����
0 = ��׽�����㣬������һֱ���ɼ��� */
#define	ETx_CR_CAPCLR_Msk	(0x1U << ETx_CR_CAPCLR_Pos)
	/* ʹ�ܺ����������0����׽����һ����Ч��֮��timer�ſ�ʼ���� */

#define	ETx_CR_CAPONCE_Pos	1	/* ���β�׽����
1 = ���β�׽��Ч���ڲ�׽��һ���������ں������ֹͣ������Ҫ�ٴβ�׽����������
0 = ������׽ */
#define	ETx_CR_CAPONCE_Msk	(0x1U << ETx_CR_CAPONCE_Pos)
#define	ETx_CR_CAPONCE_SINGLE	(0x1U << ETx_CR_CAPONCE_Pos)
#define	ETx_CR_CAPONCE_CONTINUE	(0x0U << ETx_CR_CAPONCE_Pos)

#define	ETx_CR_CAPEDGE_Pos	0	/* ��׽��ѡ��
1 = ���ڲ�׽ģʽʱ���ز�׽
0 = ���ڲ�׽ģʽʱ���ز�׽ */
#define	ETx_CR_CAPEDGE_Msk	(0x1U << ETx_CR_CAPEDGE_Pos)
#define	ETx_CR_CAPEDGE_FALLING	(0x1U << ETx_CR_CAPEDGE_Pos)
#define	ETx_CR_CAPEDGE_RISING	(0x0U << ETx_CR_CAPEDGE_Pos)

#define	ETx_INSR_SIG2SEL_Pos	7	/* �ڲ��ź�2Դѡ��(��׽Դ)
1 = ��չ��ʱ��3���ڲ��ź�2ѡ��Group1
0 = ��չ��ʱ��3���ڲ��ź�2ѡ��Group2 */
#define	ETx_INSR_SIG2SEL_Msk	(0x1U << ETx_INSR_SIG2SEL_Pos)
#define	ETx_INSR_SIG2SEL_GROUP1	(0x1U << ETx_INSR_SIG2SEL_Pos)
#define	ETx_INSR_SIG2SEL_GROUP2	(0x0U << ETx_INSR_SIG2SEL_Pos)

#define	ETx_INSR_SIG1SEL_Pos	6	/* �ڲ��ź�1Դѡ���ڼ���ģʽ�¼���Դ���ɴ�ѡ�񣬲�׽ģʽ�¼���Դ��
1 = ��չ��ʱ��3���ڲ��ź�1ѡ��Group2
0 = ��չ��ʱ��3���ڲ��ź�1ѡ��Group1 */
#define	ETx_INSR_SIG1SEL_Msk	(0x1U << ETx_INSR_SIG1SEL_Pos)
#define	ETx_INSR_SIG1SEL_GROUP2	(0x1U << ETx_INSR_SIG1SEL_Pos)
#define	ETx_INSR_SIG1SEL_GROUP1	(0x0U << ETx_INSR_SIG1SEL_Pos)

#define	ETx_INSR_GRP2SEL_Pos	2	/* GROUP2 �ź�ѡ�����
ET1
000 = UART0_RX
001 = UART1_RX
010 = XTLF
011 = ET1_IN1
100 = ET1_IN2
101 = CMP1O���Ƚ���1�����
110 = CMP2O���Ƚ���2�����
111 = RCMF
ET2
000 = UART2_RX
001 = UART3_RX
010 = XTLF
011 = ET2_IN1
100 = ET2_IN2
101 = CMP1O���Ƚ���1�����
110 = CMP2O���Ƚ���2�����
111 = RCMF
ET3
000 = ET3_IN1
001 = XTLF 
010 = UART4_RX
011 = UART5_RX
100 = RTCSEC
101~111 = RFU
ET4
000 = ET4_IN1
001 = XTLF
010 = UART_RX2
011 = UART_RX0
100 = CMP1O���Ƚ���1�����
101 = CMP2O���Ƚ���2�����
110= RTCSEC
111= RCMF? */
#define	ETx_INSR_GRP2SEL_Msk	(0x7U << ETx_INSR_GRP2SEL_Pos)
#define	ETx_INSR_GRP2SEL_ET1_UART0_RX	(0x0U << ETx_INSR_GRP2SEL_Pos)
#define	ETx_INSR_GRP2SEL_ET1_UART1_RX	(0x1U << ETx_INSR_GRP2SEL_Pos)
#define	ETx_INSR_GRP2SEL_ET1_XTLF	(0x2U << ETx_INSR_GRP2SEL_Pos)
#define	ETx_INSR_GRP2SEL_ET1_IN1	(0x3U << ETx_INSR_GRP2SEL_Pos)
#define	ETx_INSR_GRP2SEL_ET1_IN2	(0x4U << ETx_INSR_GRP2SEL_Pos)
#define	ETx_INSR_GRP2SEL_ET1_CMP1O	(0x5U << ETx_INSR_GRP2SEL_Pos)
#define	ETx_INSR_GRP2SEL_ET1_CMP2O	(0x6U << ETx_INSR_GRP2SEL_Pos)
#define	ETx_INSR_GRP2SEL_ET1_RCMF	(0x7U << ETx_INSR_GRP2SEL_Pos)
#define	ETx_INSR_GRP2SEL_ET2_UART2_RX	(0x0U << ETx_INSR_GRP2SEL_Pos)
#define	ETx_INSR_GRP2SEL_ET2_UART3_RX	(0x1U << ETx_INSR_GRP2SEL_Pos)
#define	ETx_INSR_GRP2SEL_ET2_XTLF	(0x2U << ETx_INSR_GRP2SEL_Pos)
#define	ETx_INSR_GRP2SEL_ET2_IN1	(0x3U << ETx_INSR_GRP2SEL_Pos)
#define	ETx_INSR_GRP2SEL_ET2_IN2	(0x4U << ETx_INSR_GRP2SEL_Pos)
#define	ETx_INSR_GRP2SEL_ET2_CMP1O	(0x5U << ETx_INSR_GRP2SEL_Pos)
#define	ETx_INSR_GRP2SEL_ET2_CMP2O	(0x6U << ETx_INSR_GRP2SEL_Pos)
#define	ETx_INSR_GRP2SEL_ET2_RCMF	(0x7U << ETx_INSR_GRP2SEL_Pos)
#define	ETx_INSR_GRP2SEL_ET3_IN1	(0x0U << ETx_INSR_GRP2SEL_Pos)
#define	ETx_INSR_GRP2SEL_ET3_XTLF 	(0x1U << ETx_INSR_GRP2SEL_Pos)
#define	ETx_INSR_GRP2SEL_ET3_UART4_RX	(0x2U << ETx_INSR_GRP2SEL_Pos)
#define	ETx_INSR_GRP2SEL_ET3_UART5_RX	(0x3U << ETx_INSR_GRP2SEL_Pos)
#define	ETx_INSR_GRP2SEL_ET3_RTCSEC	(0x4U << ETx_INSR_GRP2SEL_Pos)
#define	ETx_INSR_GRP2SEL_ET4_IN	(0x0U << ETx_INSR_GRP2SEL_Pos)
#define	ETx_INSR_GRP2SEL_ET4_XTLF	(0x1U << ETx_INSR_GRP2SEL_Pos)
#define	ETx_INSR_GRP2SEL_ET4_UART_RX2	(0x2U << ETx_INSR_GRP2SEL_Pos)
#define	ETx_INSR_GRP2SEL_ET4_UART_RX0	(0x3U << ETx_INSR_GRP2SEL_Pos)
#define	ETx_INSR_GRP2SEL_ET4_CMP1O	(0x4U << ETx_INSR_GRP2SEL_Pos)
#define	ETx_INSR_GRP2SEL_ET4_CMP2O	(0x5U << ETx_INSR_GRP2SEL_Pos)
#define	ETx_INSR_GRP2SEL_ET4_RTCSEC	(0x6U << ETx_INSR_GRP2SEL_Pos)
#define	ETx_INSR_GRP2SEL_ET4_RCMF	(0x7U << ETx_INSR_GRP2SEL_Pos)

#define	ETx_INSR_GRP1SEL_Pos	0	/* GROUP1 �ź�ѡ�����
ET1
00 = APBCLK
01 = XTLF
10 = RCLP
11 = ET1_IN0
ET2
00 = APBCLK
01 = XTLF
10 = RCLP
11 = ET2_IN0
ET3
00 = APBCLK
01 = ET3_IN0
10 = RTCSEC
11 = RCLP
ET4
00 = APBCLK
01 = ET4_IN0
10 = RTC64HZ
11 = RCMF */
#define	ETx_INSR_GRP1SEL_Msk	(0x3U << ETx_INSR_GRP1SEL_Pos)
#define	ETx_INSR_GRP1SEL_ET1_APBCLK	(0x0U << ETx_INSR_GRP1SEL_Pos)
#define	ETx_INSR_GRP1SEL_ET1_XTLF	(0x1U << ETx_INSR_GRP1SEL_Pos)
#define	ETx_INSR_GRP1SEL_ET1_RCLP	(0x2U << ETx_INSR_GRP1SEL_Pos)
#define	ETx_INSR_GRP1SEL_ET1_IN0	(0x3U << ETx_INSR_GRP1SEL_Pos)
#define	ETx_INSR_GRP1SEL_ET2_APBCLK	(0x0U << ETx_INSR_GRP1SEL_Pos)
#define	ETx_INSR_GRP1SEL_ET2_XTLF	(0x1U << ETx_INSR_GRP1SEL_Pos)
#define	ETx_INSR_GRP1SEL_ET2_RCLP	(0x2U << ETx_INSR_GRP1SEL_Pos)
#define	ETx_INSR_GRP1SEL_ET2_IN0	(0x3U << ETx_INSR_GRP1SEL_Pos)
#define	ETx_INSR_GRP1SEL_ET3_APBCLK	(0x0U << ETx_INSR_GRP1SEL_Pos)
#define	ETx_INSR_GRP1SEL_ET3_IN0	(0x1U << ETx_INSR_GRP1SEL_Pos)
#define	ETx_INSR_GRP1SEL_ET3_RTCSEC	(0x2U << ETx_INSR_GRP1SEL_Pos)
#define	ETx_INSR_GRP1SEL_ET3_RCLP	(0x3U << ETx_INSR_GRP1SEL_Pos)
#define	ETx_INSR_GRP1SEL_ET4_APBCLK	(0x0U << ETx_INSR_GRP1SEL_Pos)
#define	ETx_INSR_GRP1SEL_ET4_IN0	(0x1U << ETx_INSR_GRP1SEL_Pos)
#define	ETx_INSR_GRP1SEL_ET4_RTC64HZ	(0x2U << ETx_INSR_GRP1SEL_Pos)
#define	ETx_INSR_GRP1SEL_ET4_RCMF	(0x3U << ETx_INSR_GRP1SEL_Pos)

#define	ETx_PSCR1_PRESCALE1_Pos	0	/* ����Signal1������Դ����Ԥ��Ƶ�Ĵ���
00��ʾ1��Ƶ��FF��ʾ256��Ƶ */
#define	ETx_PSCR1_PRESCALE1_Msk	(0xffU << ETx_PSCR1_PRESCALE1_Pos)

#define	ETx_PSCR2_PRESCALE2_Pos	0	/* ����Signal2����׽Դ����Ԥ��Ƶ�Ĵ���
00��ʾ1��Ƶ��FF��ʾ256��Ƶ�� */
#define	ETx_PSCR2_PRESCALE2_Msk	(0xffU << ETx_PSCR2_PRESCALE2_Pos)

#define	ETx_IVR_INITVALUE_Pos	0	/* ��չ��ʱ����ֵ�Ĵ��� */
#define	ETx_IVR_INITVALUE_Msk	(0xffffU << ETx_IVR_INITVALUE_Pos)

#define	ETx_CMPR_CMP_Pos	0	/* ��չ��ʱ���ȽϼĴ���
�üĴ�����������Ƚϣ�������ֵ���ڵ��ڸüĴ�����ֵ�����������ƥ���ź����������ģ�飬��������Ӧ�жϡ� */
#define	ETx_CMPR_CMP_Msk	(0xffffU << ETx_CMPR_CMP_Pos)

#define	ETx_IER_CMPIE_Pos	2	/* ��չ��ʱ���Ƚ��ж�ʹ��
1 = ʹ��
0 = ��ֹ */
#define	ETx_IER_CMPIE_Msk	(0x1U << ETx_IER_CMPIE_Pos)

#define	ETx_IER_CAPIE_Pos	1	/* ��չ��ʱ����׽�ж�ʹ��
1 = ʹ��
0 = ��ֹ */
#define	ETx_IER_CAPIE_Msk	(0x1U << ETx_IER_CAPIE_Pos)

#define	ETx_IER_OVIE_Pos	0	/* ��չ��ʱ��3����ж�ʹ��
1 = ʹ��
0 = ��ֹ */
#define	ETx_IER_OVIE_Msk	(0x1U << ETx_IER_OVIE_Pos)

#define	ETx_ISR_CMPIF_Pos	3	/* �Ƚ�״̬��д1��0
1 =��ǰ��������ֵ���ڵ��ڱȽϼĴ�����ֵ
0 =��ǰ��������ֵС�ڱȽϼĴ�����ֵ */
#define	ETx_ISR_CMPIF_Msk	(0x1U << ETx_ISR_CMPIF_Pos)

#define	ETx_ISR_EDGESTA_Pos	2	/* ��׽��״̬��־
1 = ��׽������
0 = ��׽������ */
#define	ETx_ISR_EDGESTA_Msk	(0x1U << ETx_ISR_EDGESTA_Pos)

#define	ETx_ISR_CAPIF_Pos	1	/* ��չ��ʱ����׽�����ź�
1 = ��׽��ָ������
0 = δ��׽��ָ������ */
#define	ETx_ISR_CAPIF_Msk	(0x1U << ETx_ISR_CAPIF_Pos)

#define	ETx_ISR_OVIF_Pos	0	/* ��չ��ʱ��3����źţ�����������ֵ��0xFFFF������ʱ����λ
1 = �����������
0 = δ������� */
#define	ETx_ISR_OVIF_Msk	(0x1U << ETx_ISR_OVIF_Pos)

#define	ETCNTx_CNT_Pos	0	
#define	ETCNTx_CNT_Msk	(0xffffU << ETCNTx_CNT_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void ETx_Deinit(ET_Type* ETx);

/* �������ѡ�� (Output Polarity)
0�������ȡ��
1�����ȡ�� ��غ��� */
extern void ETx_CR_OPOL_Set(ET_Type* ETx, uint32_t SetValue);
extern uint32_t ETx_CR_OPOL_Get(ET_Type* ETx);

/* �ⲿ�������������˲�ʹ��
1 = �����������ź������˲�
0 = �ر����������ź������˲� ��غ��� */
extern void ETx_CR_EXFLT_Set(ET_Type* ETx, uint32_t SetValue);
extern uint32_t ETx_CR_EXFLT_Get(ET_Type* ETx);

/* PWM�������
1 = PWM���ʹ��
0 = PWM�����ֹ ��غ��� */
extern void ETx_CR_PWM_Setable(ET_Type* ETx, FunState NewState);
extern FunState ETx_CR_PWM_Getable(ET_Type* ETx);

/* ��������
1 = ������ʱ�����ڼ�����ģʽ������ʱ��������ֵ�������������͹����Ĵ������ڲ�׽ģʽ�£�����ʱ���������㿪ʼ���ɼ�����������0xFFFF���������ź�Ȼ�����㿪ʼ���¼���
0 = ֹͣ���������� ��غ��� */
extern void ETx_CR_CEN_Setable(ET_Type* ETx, FunState NewState);
extern FunState ETx_CR_CEN_Getable(ET_Type* ETx);

/* ����ģʽѡ��
1 = ��׽ģʽ
0 = ��ʱ/����ģʽ ��غ��� */
extern void ETx_CR_MOD_Set(ET_Type* ETx, uint32_t SetValue);
extern uint32_t ETx_CR_MOD_Get(ET_Type* ETx);

/* Cascade Enable����չ��ʱ������ʹ��
1 = ET1��ET3����ET2��ET4��������32bit��ʱ��
0 = 16bit��ʱ���������� ��غ��� */
extern void ETx_CR_CASEN_Set(ET_Type* ETx, uint32_t SetValue);
extern uint32_t ETx_CR_CASEN_Get(ET_Type* ETx);

/* ����ģʽ���ط�ʽѡ��
������ʱ��ѡ��mcu_clkʱ��λ��Ч�����ǲ���mcu_clkʱ�������ؼ�����
1 = ����ģʽ���½���
0 = ����ģʽ�������� ��غ��� */
extern void ETx_CR_EDGESEL_Set(ET_Type* ETx, uint32_t SetValue);
extern uint32_t ETx_CR_EDGESEL_Get(ET_Type* ETx);

/* ��׽ģʽ����
1 = ����׽
0 = �������ڲ�׽ ��غ��� */
extern void ETx_CR_CAPMOD_Set(ET_Type* ETx, uint32_t SetValue);
extern uint32_t ETx_CR_CAPMOD_Get(ET_Type* ETx);

/* �����㲶׽ģʽ����
1 = �¼�������׽��ʹ�ܺ����������0����׽����һ����Ч��֮��timer�ſ�ʼ����
0 = ��׽�����㣬������һֱ���ɼ��� ��غ��� */
extern void ETx_CR_CAPCLR_Setable(ET_Type* ETx, FunState NewState);
extern FunState ETx_CR_CAPCLR_Getable(ET_Type* ETx);

/* ���β�׽����
1 = ���β�׽��Ч���ڲ�׽��һ���������ں������ֹͣ������Ҫ�ٴβ�׽����������
0 = ������׽ ��غ��� */
extern void ETx_CR_CAPONCE_Set(ET_Type* ETx, uint32_t SetValue);
extern uint32_t ETx_CR_CAPONCE_Get(ET_Type* ETx);

/* ��׽��ѡ��
1 = ���ڲ�׽ģʽʱ���ز�׽
0 = ���ڲ�׽ģʽʱ���ز�׽ ��غ��� */
extern void ETx_CR_CAPEDGE_Set(ET_Type* ETx, uint32_t SetValue);
extern uint32_t ETx_CR_CAPEDGE_Get(ET_Type* ETx);

/* �ڲ��ź�2Դѡ��(��׽Դ)
1 = ��չ��ʱ��3���ڲ��ź�2ѡ��Group1
0 = ��չ��ʱ��3���ڲ��ź�2ѡ��Group2 ��غ��� */
extern void ETx_INSR_SIG2SEL_Set(ET_Type* ETx, uint32_t SetValue);
extern uint32_t ETx_INSR_SIG2SEL_Get(ET_Type* ETx);

/* �ڲ��ź�1Դѡ���ڼ���ģʽ�¼���Դ���ɴ�ѡ�񣬲�׽ģʽ�¼���Դ��
1 = ��չ��ʱ��3���ڲ��ź�1ѡ��Group2
0 = ��չ��ʱ��3���ڲ��ź�1ѡ��Group1 ��غ��� */
extern void ETx_INSR_SIG1SEL_Set(ET_Type* ETx, uint32_t SetValue);
extern uint32_t ETx_INSR_SIG1SEL_Get(ET_Type* ETx);

/* GROUP2 �ź�ѡ�����
ET1
000 = UART0_RX
001 = UART1_RX
010 = XTLF
011 = ET1_IN1
100 = ET1_IN2
101 = CMP1O���Ƚ���1�����
110 = CMP2O���Ƚ���2�����
111 = RCMF
ET2
000 = UART2_RX
001 = UART3_RX
010 = XTLF
011 = ET2_IN1
100 = ET2_IN2
101 = CMP1O���Ƚ���1�����
110 = CMP2O���Ƚ���2�����
111 = RCMF
ET3
000 = ET3_IN1
001 = XTLF 
010 = UART4_RX
011 = UART5_RX
100 = RTCSEC
101~111 = RFU
ET4
000 = ET4_IN1
001 = XTLF
010 = UART_RX2
011 = UART_RX0
100 = CMP1O���Ƚ���1�����
101 = CMP2O���Ƚ���2�����
110= RTCSEC
111= RCMF? ��غ��� */
extern void ETx_INSR_GRP2SEL_Set(ET_Type* ETx, uint32_t SetValue);
extern uint32_t ETx_INSR_GRP2SEL_Get(ET_Type* ETx);

/* GROUP1 �ź�ѡ�����
ET1
00 = APBCLK
01 = XTLF
10 = RCLP
11 = ET1_IN0
ET2
00 = APBCLK
01 = XTLF
10 = RCLP
11 = ET2_IN0
ET3
00 = APBCLK
01 = ET3_IN0
10 = RTCSEC
11 = RCLP
ET4
00 = APBCLK
01 = ET4_IN0
10 = RTC64HZ
11 = RCMF ��غ��� */
extern void ETx_INSR_GRP1SEL_Set(ET_Type* ETx, uint32_t SetValue);
extern uint32_t ETx_INSR_GRP1SEL_Get(ET_Type* ETx);

/* ����Signal1������Դ����Ԥ��Ƶ�Ĵ���
00��ʾ1��Ƶ��FF��ʾ256��Ƶ ��غ��� */
extern void ETx_PSCR1_Write(ET_Type* ETx, uint32_t SetValue);
extern uint32_t ETx_PSCR1_Read(ET_Type* ETx);

/* ����Signal2����׽Դ����Ԥ��Ƶ�Ĵ���
00��ʾ1��Ƶ��FF��ʾ256��Ƶ�� ��غ��� */
extern void ETx_PSCR2_Write(ET_Type* ETx, uint32_t SetValue);
extern uint32_t ETx_PSCR2_Read(ET_Type* ETx);

/* ��չ��ʱ����ֵ�Ĵ��� ��غ��� */
extern void ETx_IVR_Write(ET_Type* ETx, uint32_t SetValue);
extern uint32_t ETx_IVR_Read(ET_Type* ETx);

/* ��չ��ʱ���ȽϼĴ���
�üĴ�����������Ƚϣ�������ֵ���ڵ��ڸüĴ�����ֵ�����������ƥ���ź����������ģ�飬��������Ӧ�жϡ� ��غ��� */
extern void ETx_CMPR_Write(ET_Type* ETx, uint32_t SetValue);
extern uint32_t ETx_CMPR_Read(ET_Type* ETx);

/* ��չ��ʱ���Ƚ��ж�ʹ��
1 = ʹ��
0 = ��ֹ ��غ��� */
extern void ETx_IER_CMPIE_Setable(ET_Type* ETx, FunState NewState);
extern FunState ETx_IER_CMPIE_Getable(ET_Type* ETx);

/* ��չ��ʱ����׽�ж�ʹ��
1 = ʹ��
0 = ��ֹ ��غ��� */
extern void ETx_IER_CAPIE_Setable(ET_Type* ETx, FunState NewState);
extern FunState ETx_IER_CAPIE_Getable(ET_Type* ETx);

/* ��չ��ʱ��3����ж�ʹ��
1 = ʹ��
0 = ��ֹ ��غ��� */
extern void ETx_IER_OVIE_Setable(ET_Type* ETx, FunState NewState);
extern FunState ETx_IER_OVIE_Getable(ET_Type* ETx);

/* �Ƚ�״̬��д1��0
1 =��ǰ��������ֵ���ڵ��ڱȽϼĴ�����ֵ
0 =��ǰ��������ֵС�ڱȽϼĴ�����ֵ ��غ��� */
extern void ETx_ISR_CMPIF_Clr(ET_Type* ETx);
extern FlagStatus ETx_ISR_CMPIF_Chk(ET_Type* ETx);

/* ��׽��״̬��־
1 = ��׽������
0 = ��׽������ */
extern FlagStatus ETx_ISR_EDGESTA_Chk(ET_Type* ETx);

/* ��չ��ʱ����׽�����ź�
1 = ��׽��ָ������
0 = δ��׽��ָ������ ��غ��� */
extern void ETx_ISR_CAPIF_Clr(ET_Type* ETx);
extern FlagStatus ETx_ISR_CAPIF_Chk(ET_Type* ETx);

/* ��չ��ʱ��3����źţ�����������ֵ��0xFFFF������ʱ����λ
1 = �����������
0 = δ������� ��غ��� */
extern void ETx_ISR_OVIF_Clr(ET_Type* ETx);
extern FlagStatus ETx_ISR_OVIF_Chk(ET_Type* ETx);

/*��ȡET ��������ֵ*/
extern uint32_t ETxCNT_CNTx_Read(ETCNT_Type* ETIMx);
//Announce_End
#ifdef __cplusplus
}
#endif

#endif /*__FM33A0XXEV_ET_H */
