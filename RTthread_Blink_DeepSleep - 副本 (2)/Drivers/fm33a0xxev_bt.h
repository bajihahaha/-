/**
  ******************************************************************************
  * @file    fm33a0xxev_bt.h
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file contains all the functions prototypes for the BT firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33A0XXEV_BT_H
#define __FM33A0XXEV_BT_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33A0XXEV.h" 
   
#define	BTx_CR1_CHEN_Pos	7	/* ��8λ��������BT1H��BT2H����������  */
#define	BTx_CR1_CHEN_Msk	(0x1U << BTx_CR1_CHEN_Pos)

#define	BTx_CR1_CLEN_Pos	6	/* ��8λ��������BT1L��BT2L����������
(Counter-Lowend enable)
1��������8bit���������ڼ�����ģʽ������ʱ��Ԥ����ֵ�ͼ���ֵ�ֱ�������������ͱȽϼĴ�������׽ģʽ������ʱ���������㿪ʼ���ɼ�����������0xFFFF���������ź�Ȼ�����㿪ʼ���¼�������׽����ֻ������16λģʽ����16λ�Ķ�ʱ/�����Ͳ�׽ģʽ��CHEN��Ϊ���������������ƣ�CLEN�Զ�ʧЧ
0��ֹͣ��8bit���������� */
#define	BTx_CR1_CLEN_Msk	(0x1U << BTx_CR1_CLEN_Pos)
	/* ������8bit���������ڼ�����ģʽ������ʱ��Ԥ����ֵ�ͼ���ֵ�ֱ�������������ͱȽϼĴ�������׽ģʽ������ʱ���������㿪ʼ���ɼ�����������0xFFFF���������ź�Ȼ�����㿪ʼ���¼�������׽����ֻ������16λģʽ����16λ�Ķ�ʱ/�����Ͳ�׽ģʽ��CHEN��Ϊ���������������ƣ�CLEN�Զ�ʧЧ */
	/* ֹͣ��8bit���������� */

#define	BTx_CR1_MODE_Pos	5	/* ����ģʽѡ�� (work mode)
1��16λ��׽ģʽ
0��8λ��ʱ/����ģʽ������λ����������Դѡ��Ϊ��λ������������źţ����ʵ��16λ��ʱ/����ģʽ */
#define	BTx_CR1_MODE_Msk	(0x1U << BTx_CR1_MODE_Pos)
#define	BTx_CR1_MODE_CAPTURE	(0x1U << BTx_CR1_MODE_Pos)	/* 16λ��׽ģʽ */
#define	BTx_CR1_MODE_COUNTER	(0x0U << BTx_CR1_MODE_Pos)	/* 8λ��ʱ/����ģʽ������λ����������Դѡ��Ϊ��λ������������źţ����ʵ��16λ��ʱ/����ģʽ */

#define	BTx_CR1_EDGESEL_Pos	4	/* ����ģʽ�µļ����غ����ڲ�׽ʱ�Ĳ�׽��ѡ��λ (edge select)
1������ģʽ��������Դ�½��أ����ڲ�׽ģʽʱ���ز�׽
0������ģʽ��������Դ�����أ����ڲ�׽ģʽʱ���ز�׽
ע����֧��ϵͳʱ�ӵ��½��ؼ�������׽Դ�ͼ���ԴΪϵͳʱ��ʱѡ���½��ؽ�������Ч������ */
#define	BTx_CR1_EDGESEL_Msk	(0x1U << BTx_CR1_EDGESEL_Pos)
#define	BTx_CR1_EDGESEL_FALLING	(0x1U << BTx_CR1_EDGESEL_Pos)	/* ����ģʽ��������Դ�½��أ����ڲ�׽ģʽʱ���ز�׽ */
#define	BTx_CR1_EDGESEL_RISING	(0x0U << BTx_CR1_EDGESEL_Pos)	/* ����ģʽ��������Դ�����أ����ڲ�׽ģʽʱ���ز�׽ */

#define	BTx_CR1_CAPMOD_Pos	3	/* ��׽ģʽ���ƣ�ֻ�ڲ�׽ģʽ����Ч��(capture mode)
1�������Ȳ�׽
0���������ڲ�׽ */
#define	BTx_CR1_CAPMOD_Msk	(0x1U << BTx_CR1_CAPMOD_Pos)
#define	BTx_CR1_CAPMOD_PULSE	(0x1U << BTx_CR1_CAPMOD_Pos)	/* �����Ȳ�׽ */
#define	BTx_CR1_CAPMOD_CYCLE	(0x0U << BTx_CR1_CAPMOD_Pos)	/* �������ڲ�׽ */

#define	BTx_CR1_CAPCLR_Pos	2	/* �����㲶׽ģʽ���� (capture clear)
1�������������Ȼ������ڲ�׽����£���׽����һ���غ󽫼�������������жϣ���׽���ڶ����غ����棨���浽�ߵ�λԤ�����Ĵ���������ֵ��ͬʱ���������
0����׽�����㣬������һֱ���ɼ��� */
#define	BTx_CR1_CAPCLR_Msk	(0x1U << BTx_CR1_CAPCLR_Pos)
	/* �����������Ȼ������ڲ�׽����£���׽����һ���غ󽫼�������������жϣ���׽���ڶ����غ����棨���浽�ߵ�λԤ�����Ĵ���������ֵ��ͬʱ��������� */
	/* ��׽�����㣬������һֱ���ɼ��� */

#define	BTx_CR1_CAPONCE_Pos	1	/* ���β�׽���� (capture once)
1�����β�׽��Ч���ڲ�׽��һ�������Ȼ��������ں������ֹͣ������Ҫ�ٴβ�׽����������
0��������׽ */
#define	BTx_CR1_CAPONCE_Msk	(0x1U << BTx_CR1_CAPONCE_Pos)
#define	BTx_CR1_CAPONCE_SINGLE	(0x1U << BTx_CR1_CAPONCE_Pos)	/* ���β�׽��Ч���ڲ�׽��һ�������Ȼ��������ں������ֹͣ������Ҫ�ٴβ�׽���������� */
#define	BTx_CR1_CAPONCE_CONTINUE	(0x0U << BTx_CR1_CAPONCE_Pos)	/* ������׽ */

#define	BTx_CR1_PWM_Pos	0	/* PWMģʽ��� (pulse width modulation)
1��PWM���ʹ��
0��PWM �����ʹ�� */
#define	BTx_CR1_PWM_Msk	(0x1U << BTx_CR1_PWM_Pos)
	/* PWM���ʹ�� */
	/* PWM �����ʹ�� */

#define	BTx_CR2_SIG2SEL_Pos	7	/* �������ڲ�����Դ�ź�ѡ�� (signal group2 select)
1���ڲ�����Դ�ź�ѡ��Group2
0���ڲ�����Դ�ź�ѡ��Group1 */
#define	BTx_CR2_SIG2SEL_Msk	(0x1U << BTx_CR2_SIG2SEL_Pos)
#define	BTx_CR2_SIG2SEL_GROUP2	(0x1U << BTx_CR2_SIG2SEL_Pos)	/* �ڲ�����Դ�ź�ѡ��Group2 */
#define	BTx_CR2_SIG2SEL_GROUP1	(0x0U << BTx_CR2_SIG2SEL_Pos)	/* �ڲ�����Դ�ź�ѡ��Group1 */

#define	BTx_CR2_SIG1SEL_Pos	6	/* �������ڲ���׽Դ�ź�ѡ�� (signal group1 select)
1���ڲ���׽Դ�ź�ѡ��Group1
0���ڲ���׽Դ�ź�ѡ��Group2 */
#define	BTx_CR2_SIG1SEL_Msk	(0x1U << BTx_CR2_SIG1SEL_Pos)
#define	BTx_CR2_SIG1SEL_GROUP1	(0x1U << BTx_CR2_SIG1SEL_Pos)	/* �ڲ���׽Դ�ź�ѡ��Group1 */
#define	BTx_CR2_SIG1SEL_GROUP2	(0x0U << BTx_CR2_SIG1SEL_Pos)	/* �ڲ���׽Դ�ź�ѡ��Group2 */

#define	BTx_CR2_CNTHSEL_Pos	4	/* ��8λ����������Դѡ�� (Counter Highend source select)
00/11��ѡ��ET1�ĵ�λ������������źţ����λ���������16λ������
01��ѡ���ڲ���׽Դ�ź�
10��ѡ���ڲ�����Դ�źŻ��ⲿDIR��������ź� */
#define	BTx_CR2_CNTHSEL_Msk	(0x3U << BTx_CR2_CNTHSEL_Pos)
#define	BTx_CR2_CNTHSEL_COUNTER	(0x0U << BTx_CR2_CNTHSEL_Pos)	/* ѡ��ET1�ĵ�λ������������źţ����λ���������16λ������ */
#define	BTx_CR2_CNTHSEL_CAPTURE	(0x1U << BTx_CR2_CNTHSEL_Pos)	/* ѡ���ڲ���׽Դ�ź� */
#define	BTx_CR2_CNTHSEL_INNER	(0x2U << BTx_CR2_CNTHSEL_Pos)	/* ѡ���ڲ�����Դ�źŻ��ⲿDIR��������ź� */

#define	BTx_CR2_DIREN_Pos	3	/* �ⲿ����DIR����ʹ�ܡ�ͨ�������������ʱͬʱ�����һ���ɸߵ͵�ƽָʾ������ķ����ź�DIR����·��ͨ��DIR�źŵ�ƽ�ĸߵͣ��ֱ���Ƹ�λ�������͵�λ����������ʹ�ܣ���ʵ��������򡢷�������ĸ��ּ������� (direction bit enable)
1���ⲿ�����DIR�ź���Ч����ʱ�ߵ�λ�������Ƿ���������ⲿ�����DIR�źſ��ơ�
0���ⲿ�����DIR�ź���Ч����ʱ�ߵ�λ�������Ƿ���������ڲ������źſ��ơ� */
#define	BTx_CR2_DIREN_Msk	(0x1U << BTx_CR2_DIREN_Pos)
	/* �ⲿ�����DIR�ź���Ч����ʱ�ߵ�λ�������Ƿ���������ⲿ�����DIR�źſ��ơ� */
	/* �ⲿ�����DIR�ź���Ч����ʱ�ߵ�λ�������Ƿ���������ڲ������źſ��ơ� */

#define	BTx_CR2_STDIR_Pos	2	/* �ڲ�DIR�����źţ���DIRENΪ0�����ⲿ����DIR������Чʱ�����ɸ��źŴ���DIR���룬ֱ�ӿ����ڲ��������ļ���������Ҫ�ⲿDIR���룬��DIRENΪ1ʱ����λӦ����Ϊ0 (set direction)
1���ڲ�DIR�ź�Ϊ�ߵ�ƽ�����8λ���������� */
#define	BTx_CR2_STDIR_Msk	(0x1U << BTx_CR2_STDIR_Pos)
	/* �ڲ�DIR�ź�Ϊ�ߵ�ƽ�����8λ���������� */

#define	BTx_CR2_SRCSEL_Pos	1	/* ��λ����������ʹ�ܿ���ѡ���ź� (source select)
1��λ����������ʹ�ܶ�ѡ��ʹ�ܡ���ʱ��λ��������������DIR���ƣ��ɽ���������������һ������
0����λ����������ʹ�ܶ�ѡ���ɼĴ���STDIR���ⲿEX_SIG2������ơ� */
#define	BTx_CR2_SRCSEL_Msk	(0x1U << BTx_CR2_SRCSEL_Pos)
	/* ��λ����������ʹ�ܶ�ѡ���ɼĴ���STDIR���ⲿEX_SIG2������ơ� */

#define	BTx_CR2_DIRPO_Pos	0	/* �����ź�2����ѡ�� (direction polarity)
1�����ⲿ����DIR�ź�EX_SIG2����
0�����ⲿ����DIR�ź�EX_SIG2������ */
#define	BTx_CR2_DIRPO_Msk	(0x1U << BTx_CR2_DIRPO_Pos)
#define	BTx_CR2_DIRPO_REVERSE	(0x1U << BTx_CR2_DIRPO_Pos)	/* ���ⲿ����DIR�ź�EX_SIG2���� */
#define	BTx_CR2_DIRPO_NON	(0x0U << BTx_CR2_DIRPO_Pos)	/* ���ⲿ����DIR�ź�EX_SIG2������ */

#define	BTx_CFGR1_RTCSEL2_Pos	6	/* RTCOUT2�ź�ѡ�����2 (RTCOUT2 source select)
00 = 32768Hz��XTLFʱ�����
01 = RTCSec����RTCģ����������ź�
10 = RTCMin����RTCģ������ķ����ź�
11 = RFU */
#define	BTx_CFGR1_RTCSEL2_Msk	(0x3U << BTx_CFGR1_RTCSEL2_Pos)
#define	BTx_CFGR1_RTCSEL2_32768HZ	(0x0U << BTx_CFGR1_RTCSEL2_Pos)
#define	BTx_CFGR1_RTCSEL2_RTC_SEC	(0x1U << BTx_CFGR1_RTCSEL2_Pos)
#define	BTx_CFGR1_RTCSEL2_RTC_MIN	(0x2U << BTx_CFGR1_RTCSEL2_Pos)

#define	BTx_CFGR1_RTCSEL1_Pos	4	/* RTCOUT1�ź�ѡ�����1 (RTCOUT1 source select)
00 = 32768Hz��XTLFʱ�����
01 = RTCSec����RTCģ����������ź�
10 = RTCMin����RTCģ������ķ����ź�
11 = RFU */
#define	BTx_CFGR1_RTCSEL1_Msk	(0x3U << BTx_CFGR1_RTCSEL1_Pos)
#define	BTx_CFGR1_RTCSEL1_32768HZ	(0x0U << BTx_CFGR1_RTCSEL1_Pos)
#define	BTx_CFGR1_RTCSEL1_RTC_SEC	(0x1U << BTx_CFGR1_RTCSEL1_Pos)
#define	BTx_CFGR1_RTCSEL1_RTC_MIN	(0x2U << BTx_CFGR1_RTCSEL1_Pos)

#define	BTx_CFGR1_GRP2SEL_Pos	2	/* Group2�ź�ѡ����� (Group2 source select)
00 = APBCLK
01 = RTCOUT2
10 = IN_SIG2���ڲ������ź�2
11 = EX_SIG2���ⲿ�����ź�2
ע����֧��APBCLK���½��ز�׽�ͼ�������׽Դ�ͼ���ԴΪAPBCLKʱѡ���½��ؽ�������Ч��׽�ͼ����� */
#define	BTx_CFGR1_GRP2SEL_Msk	(0x3U << BTx_CFGR1_GRP2SEL_Pos)
#define	BTx_CFGR1_GRP2SEL_APBCLK	(0x0U << BTx_CFGR1_GRP2SEL_Pos)	/* ��֧��APBCLK���½��ز�׽�ͼ�������׽Դ�ͼ���ԴΪAPBCLKʱѡ���½��ؽ�������Ч��׽�ͼ����� */
#define	BTx_CFGR1_GRP2SEL_RTCOUT2	(0x1U << BTx_CFGR1_GRP2SEL_Pos)
#define	BTx_CFGR1_GRP2SEL_IN_SIG2	(0x2U << BTx_CFGR1_GRP2SEL_Pos)
#define	BTx_CFGR1_GRP2SEL_EX_SIG2	(0x3U << BTx_CFGR1_GRP2SEL_Pos)

#define	BTx_CFGR1_GRP1SEL_Pos	0	/* Group1�ź�ѡ����ƣ�����Ϊ��׽ģʽ�²���ʱ��ѡ��ͬʱ����Ϊ�źŲ�׽Դ��(Group1 source select)
00 = APBCLK
01 = RTCOUT1
10 = IN_SIG1���ڲ������ź�1
11 = EX_SIG1���ⲿ�����ź�1
ע����֧��APBCLK���½��ز�׽�ͼ�������׽Դ�ͼ���ԴΪAPBCLKʱѡ���½��ؽ�������Ч��׽�ͼ����� */
#define	BTx_CFGR1_GRP1SEL_Msk	(0x3U << BTx_CFGR1_GRP1SEL_Pos)
#define	BTx_CFGR1_GRP1SEL_APBCLK	(0x0U << BTx_CFGR1_GRP1SEL_Pos)	/* ��֧��APBCLK���½��ز�׽�ͼ�������׽Դ�ͼ���ԴΪAPBCLKʱѡ���½��ؽ�������Ч��׽�ͼ����� */
#define	BTx_CFGR1_GRP1SEL_RTCOUT1	(0x1U << BTx_CFGR1_GRP1SEL_Pos)
#define	BTx_CFGR1_GRP1SEL_IN_SIG1	(0x2U << BTx_CFGR1_GRP1SEL_Pos)
#define	BTx_CFGR1_GRP1SEL_EX_SIG1	(0x3U << BTx_CFGR1_GRP1SEL_Pos)

#define	BTx_CFGR2_EXSEL2_Pos	6	/* �ⲿ�����ź�ѡ�����2 (external source select2)
00 = BT1_IN0/BT2_IN0
01 = BT1_IN1/BT2_IN1
10 = BT1_IN2/BT2_IN2
11 = BT1_IN3/BT2_IN3 */
#define	BTx_CFGR2_EXSEL2_Msk	(0x3U << BTx_CFGR2_EXSEL2_Pos)
#define	BTx_CFGR2_EXSEL2_IN0	(0x0U << BTx_CFGR2_EXSEL2_Pos)
#define	BTx_CFGR2_EXSEL2_IN1	(0x1U << BTx_CFGR2_EXSEL2_Pos)
#define	BTx_CFGR2_EXSEL2_IN2	(0x2U << BTx_CFGR2_EXSEL2_Pos)
#define	BTx_CFGR2_EXSEL2_IN3	(0x3U << BTx_CFGR2_EXSEL2_Pos)

#define	BTx_CFGR2_EXSEL1_Pos	4	/* �ⲿ�����ź�ѡ�����1 (external source select1)
00 = BT1_IN0/BT2_IN0
01 = BT1_IN1/BT2_IN1
10 = BT1_IN2/BT2_IN2
11 = BT1_IN3/BT2_IN3 */
#define	BTx_CFGR2_EXSEL1_Msk	(0x3U << BTx_CFGR2_EXSEL1_Pos)
#define	BTx_CFGR2_EXSEL1_IN0	(0x0U << BTx_CFGR2_EXSEL1_Pos)
#define	BTx_CFGR2_EXSEL1_IN1	(0x1U << BTx_CFGR2_EXSEL1_Pos)
#define	BTx_CFGR2_EXSEL1_IN2	(0x2U << BTx_CFGR2_EXSEL1_Pos)
#define	BTx_CFGR2_EXSEL1_IN3	(0x3U << BTx_CFGR2_EXSEL1_Pos)

#define	BTx_CFGR2_INSEL2_Pos	2	/* �ڲ������ź�ѡ�����2 (internal source select 2)
00 = UART_RX3/UART_RX3
01 = UART_RX4/UART_RX4
10 = UART_RX5/UART_RX5
11 = RCLP/BT1_OUT */
#define	BTx_CFGR2_INSEL2_Msk	(0x3U << BTx_CFGR2_INSEL2_Pos)
#define	BTx_CFGR2_INSEL2_RX3	(0x0U << BTx_CFGR2_INSEL2_Pos)
#define	BTx_CFGR2_INSEL2_RX4	(0x1U << BTx_CFGR2_INSEL2_Pos)
#define	BTx_CFGR2_INSEL2_RX5	(0x2U << BTx_CFGR2_INSEL2_Pos)
#define	BTx_CFGR2_INSEL2_RCLP	(0x3U << BTx_CFGR2_INSEL2_Pos)

#define	BTx_CFGR2_INSEL1_Pos	0	/* �ڲ������ź�ѡ�����1 (internal source select 1)
00 = UART_RX0/UART_RX0
01 = UART_RX1/UART_RX1
10 = UART_RX2/UART_RX2
11 = RCLP/RCLP */
#define	BTx_CFGR2_INSEL1_Msk	(0x3U << BTx_CFGR2_INSEL1_Pos)
#define	BTx_CFGR2_INSEL1_RX0	(0x0U << BTx_CFGR2_INSEL1_Pos)
#define	BTx_CFGR2_INSEL1_RX1	(0x1U << BTx_CFGR2_INSEL1_Pos)
#define	BTx_CFGR2_INSEL1_RX2	(0x2U << BTx_CFGR2_INSEL1_Pos)
#define	BTx_CFGR2_INSEL1_RCLP	(0x3U << BTx_CFGR2_INSEL1_Pos)

#define	BTx_PRES_PRESCALE_Pos	0	/* ����Group1��Ԥ��Ƶ�Ĵ��� (Group1 input signal prescaler)
��Ƶ��=��X+1������00��ʾ1��Ƶ��FF��ʾ256��Ƶ��Ԥ��Ƶ����źŶ�Ϊ�������������ʽ��ռ�ձ�1:X */
#define	BTx_PRES_PRESCALE_Msk	(0xffU << BTx_PRES_PRESCALE_Pos)

#define	BTx_LOADCR_LHEN_Pos	4	/* ��λ���ؿ��� (Counter highend load enable)
д1��Ԥ�����Ĵ���ET1PRESETH�ͼ��ؼĴ���ET1LOADH�ֱ���ص�����ֵ�Ĵ���ET1CNTH�ͱȽϼĴ���ET1CMPH��д0��Ч����λӲ���Զ���0����16λ�Ķ�ʱ/������LHEN��Ϊ�������ļ��ؿ��ƣ�LLEN�Զ�ʧЧ */
#define	BTx_LOADCR_LHEN_Msk	(0x1U << BTx_LOADCR_LHEN_Pos)

#define	BTx_LOADCR_LLEN_Pos	0	/* ��λ���ؿ��� (Counter lowend load enable)
д1��Ԥ�����Ĵ���PRESETL�ͼ��ؼĴ���LOADL�ֱ���ص�����ֵ�Ĵ���ET1CNTL�ͱȽϼĴ���ET1CMPL��д0��Ч����λӲ���Զ���0����16λ�Ķ�ʱ/������LHEN��Ϊ�������ļ��ؿ��ƣ�LLEN�Զ�ʧЧ */
#define	BTx_LOADCR_LLEN_Msk	(0x1U << BTx_LOADCR_LLEN_Pos)

#define	BTx_CNTL_CNTL_Pos	0	/* ��������λ����ֵ�Ĵ��� (counter lowend)
LLEN��Чʱ����Ԥ�������üĴ����� */
#define	BTx_CNTL_CNTL_Msk	(0xffU << BTx_CNTL_CNTL_Pos)

#define	BTx_CNTH_CNTH_Pos	0	/* ��������λ����ֵ�Ĵ��� (counter highend)
LHEN��Чʱ����Ԥ�������üĴ����� */
#define	BTx_CNTH_CNTH_Msk	(0xffU << BTx_CNTH_CNTH_Pos)

#define	BTx_PRESET_PRESETH_Pos	8	/* ��������λԤ�����Ĵ��� (preset highend)
���ڱ����λ��������ֵ���򱣴沶׽�����8bit */
#define	BTx_PRESET_PRESETH_Msk	(0xffU << BTx_PRESET_PRESETH_Pos)

#define	BTx_PRESET_PRESETL_Pos	0	/* ��������λԤ�����Ĵ��� (preset lowend)
���ڱ����λ��������ֵ���򱣴沶׽�����8bit */
#define	BTx_PRESET_PRESETL_Msk	(0xffU << BTx_PRESET_PRESETL_Pos)

#define	BTx_LOADL_LOADL_Pos	0	/* ��������λ���ؼĴ��� (load lowend counter)
�ڼ���ƥ���ִ�м�������ʱ�����ؼĴ�����ֵ�������ȽϹ����Ĵ����� */
#define	BTx_LOADL_LOADL_Msk	(0xffU << BTx_LOADL_LOADL_Pos)

#define	BTx_LOADH_LOADH_Pos	0	/* ��������λ���ؼĴ��� (load highend counter)
�ڼ���ƥ���ִ�м�������ʱ�����ؼĴ�����ֵ�������ȽϹ����Ĵ�������������8λ��ʱ/������ģʽʱ���ø�λ���ؼĴ�����֧�ּ���ֵΪ0x00�����á� */
#define	BTx_LOADH_LOADH_Msk	(0xffU << BTx_LOADH_LOADH_Pos)

#define	BTx_CMPL_CMPL_Pos	0	/* ��������λ�ȽϼĴ��� (compare lowend )
���ؼĴ�����ֵ���غ�д��üĴ������üĴ�����������Ƚϣ�������ֵ���ڵ��ڸüĴ�����ֵ�����������ƥ���ź����������ģ�飬��������Ӧ�жϡ� */
#define	BTx_CMPL_CMPL_Msk	(0xffU << BTx_CMPL_CMPL_Pos)

#define	BTx_CMPH_CMPH_Pos	0	/* ��������λ�ȽϼĴ��� (compare highend)
���ؼĴ�����ֵ���غ�д��üĴ������üĴ�����������Ƚϣ�������ֵ���ڵ��ڸüĴ�����ֵ�����������ƥ���ź����������ģ�飬��������Ӧ�жϡ� */
#define	BTx_CMPH_CMPH_Msk	(0xffU << BTx_CMPH_CMPH_Pos)

#define	BTx_OUTCNT_OUTCNT_Pos	0	/* ��������������ȼ����� (output pulse width counter)
�üĴ������ڵ�����������ȡ�����ʱ��Ϊ32768Hz����Ӧ����������ȷ�ΧΪ30.5uS~125mS�����������=(OUTCNT+1)/32768�� */
#define	BTx_OUTCNT_OUTCNT_Msk	(0xfffU << BTx_OUTCNT_OUTCNT_Pos)

#define	BTx_OCR_OUTCLR_Pos	5
#define	BTx_OCR_OUTCLR_Msk	(0x1U << BTx_OCR_OUTCLR_Pos)
#define	BTx_OCR_OUTCLR_INVALID	(0x0U << BTx_OCR_OUTCLR_Pos)
#define	BTx_OCR_OUTCLR_CLEAR	(0x1U << BTx_OCR_OUTCLR_Pos)

#define	BTx_OCR_OUTINV_Pos	4
#define	BTx_OCR_OUTINV_Msk	(0x1U << BTx_OCR_OUTINV_Pos)
#define	BTx_OCR_OUTINV_NORMAL	(0x0U << BTx_OCR_OUTINV_Pos)
#define	BTx_OCR_OUTINV_REVERSE	(0x1U << BTx_OCR_OUTINV_Pos)

#define	BTx_OCR_OUTMOD_Pos	3
#define	BTx_OCR_OUTMOD_Msk	(0x1U << BTx_OCR_OUTMOD_Pos)
#define	BTx_OCR_OUTMOD_PULSE_SHIFT	(0x0U << BTx_OCR_OUTMOD_Pos)
#define	BTx_OCR_OUTMOD_NEG	(0x1U << BTx_OCR_OUTMOD_Pos)

#define	BTx_OCR_OUTSEL_Pos	0
#define	BTx_OCR_OUTSEL_Msk	(0x7U << BTx_OCR_OUTSEL_Pos)
#define	BTx_OCR_OUTSEL_HIGH	(0x0U << BTx_OCR_OUTSEL_Pos)
#define	BTx_OCR_OUTSEL_LOW	(0x1U << BTx_OCR_OUTSEL_Pos)
#define	BTx_OCR_OUTSEL_GROUP1	(0x2U << BTx_OCR_OUTSEL_Pos)
#define	BTx_OCR_OUTSEL_GROUP2	(0x3U << BTx_OCR_OUTSEL_Pos)
#define	BTx_OCR_OUTSEL_PWM	(0x4U << BTx_OCR_OUTSEL_Pos)

#define	BTx_IER_CMPHIE_Pos	4	/* ��չ��ʱ����λ�ȽϷ����ź� (compare highend interrupt enable)
1 = �ж�ʹ��
0 = �жϽ�ֹ */
#define	BTx_IER_CMPHIE_Msk	(0x1U << BTx_IER_CMPHIE_Pos)

#define	BTx_IER_CMPLIE_Pos	3	/* ��չ��ʱ����λ�ȽϷ����ź� (compare lowend interrupt enable)
1 = �ж�ʹ��
0 = �жϽ�ֹ */
#define	BTx_IER_CMPLIE_Msk	(0x1U << BTx_IER_CMPLIE_Pos)

#define	BTx_IER_OVHIE_Pos	2	/* ��ʱ����λ����ź� (highend overflow interrupt enable)
1 = �ж�ʹ��
0 = �жϽ�ֹ */
#define	BTx_IER_OVHIE_Msk	(0x1U << BTx_IER_OVHIE_Pos)

#define	BTx_IER_OVLIE_Pos	1	/* ��ʱ����λ����ź� (lowend overflow interrupt enable)
1 = �ж�ʹ��
0 = �жϽ�ֹ */
#define	BTx_IER_OVLIE_Msk	(0x1U << BTx_IER_OVLIE_Pos)

#define	BTx_IER_CAPIE_Pos	0	/* ��ʱ����׽�����ź� (capture interrupt enable)
1 = �ж�ʹ��
0 = �жϽ�ֹ */
#define	BTx_IER_CAPIE_Msk	(0x1U << BTx_IER_CAPIE_Pos)

#define	BTx_ISR_EDGESTA_Pos	5	/* ��׽��״̬
1 = ��׽������
0 = ��׽������ */
#define	BTx_ISR_EDGESTA_Msk	(0x1U << BTx_ISR_EDGESTA_Pos)

#define	BTx_ISR_CMPHIF_Pos	4	/* ��ʱ����λ�ȽϷ����ź� (compare highend interrupt flag)
1 = ��ǰ��������ֵ���ڵ��ڱȽϼĴ�����ֵ�����źŽ����¼����µļ��ؼĴ�����ֵ�������Ĵ�����
0 = ��ǰ��������ֵС�ڱȽϼĴ�����ֵ */
#define	BTx_ISR_CMPHIF_Msk	(0x1U << BTx_ISR_CMPHIF_Pos)

#define	BTx_ISR_CMPLIF_Pos	3	/* ��ʱ����λ�ȽϷ����ź� (compare lowend interrupt flag)
1 = ��ǰ��������ֵ���ڵ��ڱȽϼĴ�����ֵ�����źŽ����¼����µļ��ؼĴ�����ֵ�������Ĵ�����
0 = ��ǰ��������ֵС�ڱȽϼĴ�����ֵ */
#define	BTx_ISR_CMPLIF_Msk	(0x1U << BTx_ISR_CMPLIF_Pos)

#define	BTx_ISR_OVHIF_Pos	2	/* ��ʱ����λ����ź� (highend overflow interrupt flag)
1 = �����������
0 = δ������� */
#define	BTx_ISR_OVHIF_Msk	(0x1U << BTx_ISR_OVHIF_Pos)

#define	BTx_ISR_OVLIF_Pos	1	/* ��ʱ����λ����ź� (lowend overflow interrupt flag)
1 = �����������
0 = δ������� */
#define	BTx_ISR_OVLIF_Msk	(0x1U << BTx_ISR_OVLIF_Pos)

#define	BTx_ISR_CAPIF_Pos	0	/* ��ʱ����׽�����ź� (capture interrupt flag)
1 = ��׽��ָ������
0 = δ��׽��ָ������ */
#define	BTx_ISR_CAPIF_Msk	(0x1U << BTx_ISR_CAPIF_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void BTx_Deinit(BT_Type* BTx);

/* ��8λ��������BT1H��BT2H����������  ��غ��� */
extern void BTx_CR1_CHEN_Setable(BT_Type* BTx, FunState NewState);
extern FunState BTx_CR1_CHEN_Getable(BT_Type* BTx);

/* ��8λ��������BT1L��BT2L����������
(Counter-Lowend enable)
1��������8bit���������ڼ�����ģʽ������ʱ��Ԥ����ֵ�ͼ���ֵ�ֱ�������������ͱȽϼĴ�������׽ģʽ������ʱ���������㿪ʼ���ɼ�����������0xFFFF���������ź�Ȼ�����㿪ʼ���¼�������׽����ֻ������16λģʽ����16λ�Ķ�ʱ/�����Ͳ�׽ģʽ��CHEN��Ϊ���������������ƣ�CLEN�Զ�ʧЧ
0��ֹͣ��8bit���������� ��غ��� */
extern void BTx_CR1_CLEN_Setable(BT_Type* BTx, FunState NewState);
extern FunState BTx_CR1_CLEN_Getable(BT_Type* BTx);

/* ����ģʽѡ�� (work mode)
1��16λ��׽ģʽ
0��8λ��ʱ/����ģʽ������λ����������Դѡ��Ϊ��λ������������źţ����ʵ��16λ��ʱ/����ģʽ ��غ��� */
extern void BTx_CR1_MODE_Set(BT_Type* BTx, uint32_t SetValue);
extern uint32_t BTx_CR1_MODE_Get(BT_Type* BTx);

/* ����ģʽ�µļ����غ����ڲ�׽ʱ�Ĳ�׽��ѡ��λ (edge select)
1������ģʽ��������Դ�½��أ����ڲ�׽ģʽʱ���ز�׽
0������ģʽ��������Դ�����أ����ڲ�׽ģʽʱ���ز�׽
ע����֧��ϵͳʱ�ӵ��½��ؼ�������׽Դ�ͼ���ԴΪϵͳʱ��ʱѡ���½��ؽ�������Ч������ ��غ��� */
extern void BTx_CR1_EDGESEL_Set(BT_Type* BTx, uint32_t SetValue);
extern uint32_t BTx_CR1_EDGESEL_Get(BT_Type* BTx);

/* ��׽ģʽ���ƣ�ֻ�ڲ�׽ģʽ����Ч��(capture mode)
1�������Ȳ�׽
0���������ڲ�׽ ��غ��� */
extern void BTx_CR1_CAPMOD_Set(BT_Type* BTx, uint32_t SetValue);
extern uint32_t BTx_CR1_CAPMOD_Get(BT_Type* BTx);

/* �����㲶׽ģʽ���� (capture clear)
1�������������Ȼ������ڲ�׽����£���׽����һ���غ󽫼�������������жϣ���׽���ڶ����غ����棨���浽�ߵ�λԤ�����Ĵ���������ֵ��ͬʱ���������
0����׽�����㣬������һֱ���ɼ��� ��غ��� */
extern void BTx_CR1_CAPCLR_Setable(BT_Type* BTx, FunState NewState);
extern FunState BTx_CR1_CAPCLR_Getable(BT_Type* BTx);

/* ���β�׽���� (capture once)
1�����β�׽��Ч���ڲ�׽��һ�������Ȼ��������ں������ֹͣ������Ҫ�ٴβ�׽����������
0��������׽ ��غ��� */
extern void BTx_CR1_CAPONCE_Set(BT_Type* BTx, uint32_t SetValue);
extern uint32_t BTx_CR1_CAPONCE_Get(BT_Type* BTx);

/* PWMģʽ��� (pulse width modulation)
1��PWM���ʹ��
0��PWM �����ʹ�� ��غ��� */
extern void BTx_CR1_PWM_Setable(BT_Type* BTx, FunState NewState);
extern FunState BTx_CR1_PWM_Getable(BT_Type* BTx);

/* �������ڲ�����Դ�ź�ѡ�� (signal group2 select)
1���ڲ�����Դ�ź�ѡ��Group2
0���ڲ�����Դ�ź�ѡ��Group1 ��غ��� */
extern void BTx_CR2_SIG2SEL_Set(BT_Type* BTx, uint32_t SetValue);
extern uint32_t BTx_CR2_SIG2SEL_Get(BT_Type* BTx);

/* �������ڲ���׽Դ�ź�ѡ�� (signal group1 select)
1���ڲ���׽Դ�ź�ѡ��Group1
0���ڲ���׽Դ�ź�ѡ��Group2 ��غ��� */
extern void BTx_CR2_SIG1SEL_Set(BT_Type* BTx, uint32_t SetValue);
extern uint32_t BTx_CR2_SIG1SEL_Get(BT_Type* BTx);

/* ��8λ����������Դѡ�� (Counter Highend source select)
00/11��ѡ��ET1�ĵ�λ������������źţ����λ���������16λ������
01��ѡ���ڲ���׽Դ�ź�
10��ѡ���ڲ�����Դ�źŻ��ⲿDIR��������ź� ��غ��� */
extern void BTx_CR2_CNTHSEL_Set(BT_Type* BTx, uint32_t SetValue);
extern uint32_t BTx_CR2_CNTHSEL_Get(BT_Type* BTx);

/* �ⲿ����DIR����ʹ�ܡ�ͨ�������������ʱͬʱ�����һ���ɸߵ͵�ƽָʾ������ķ����ź�DIR����·��ͨ��DIR�źŵ�ƽ�ĸߵͣ��ֱ���Ƹ�λ�������͵�λ����������ʹ�ܣ���ʵ��������򡢷�������ĸ��ּ������� (direction bit enable)
1���ⲿ�����DIR�ź���Ч����ʱ�ߵ�λ�������Ƿ���������ⲿ�����DIR�źſ��ơ�
0���ⲿ�����DIR�ź���Ч����ʱ�ߵ�λ�������Ƿ���������ڲ������źſ��ơ� ��غ��� */
extern void BTx_CR2_DIREN_Setable(BT_Type* BTx, FunState NewState);
extern FunState BTx_CR2_DIREN_Getable(BT_Type* BTx);

/* �ڲ�DIR�����źţ���DIRENΪ0�����ⲿ����DIR������Чʱ�����ɸ��źŴ���DIR���룬ֱ�ӿ����ڲ��������ļ���������Ҫ�ⲿDIR���룬��DIRENΪ1ʱ����λӦ����Ϊ0 (set direction)
1���ڲ�DIR�ź�Ϊ�ߵ�ƽ�����8λ���������� ��غ��� */
extern void BTx_CR2_STDIR_Setable(BT_Type* BTx, FunState NewState);
extern FunState BTx_CR2_STDIR_Getable(BT_Type* BTx);

/* ��λ����������ʹ�ܿ���ѡ���ź� (source select)
1��λ����������ʹ�ܶ�ѡ��ʹ�ܡ���ʱ��λ��������������DIR���ƣ��ɽ���������������һ������
0����λ����������ʹ�ܶ�ѡ���ɼĴ���STDIR���ⲿEX_SIG2������ơ� ��غ��� */
extern void BTx_CR2_SRCSEL_Setable(BT_Type* BTx, FunState NewState);
extern FunState BTx_CR2_SRCSEL_Getable(BT_Type* BTx);

/* �����ź�2����ѡ�� (direction polarity)
1�����ⲿ����DIR�ź�EX_SIG2����
0�����ⲿ����DIR�ź�EX_SIG2������ ��غ��� */
extern void BTx_CR2_DIRPO_Set(BT_Type* BTx, uint32_t SetValue);
extern uint32_t BTx_CR2_DIRPO_Get(BT_Type* BTx);

/* RTCOUT2�ź�ѡ�����2 (RTCOUT2 source select)
00 = 32768Hz��XTLFʱ�����
01 = RTCSec����RTCģ����������ź�
10 = RTCMin����RTCģ������ķ����ź�
11 = RFU ��غ��� */
extern void BTx_CFGR1_RTCSEL2_Set(BT_Type* BTx, uint32_t SetValue);
extern uint32_t BTx_CFGR1_RTCSEL2_Get(BT_Type* BTx);

/* RTCOUT1�ź�ѡ�����1 (RTCOUT1 source select)
00 = 32768Hz��XTLFʱ�����
01 = RTCSec����RTCģ����������ź�
10 = RTCMin����RTCģ������ķ����ź�
11 = RFU ��غ��� */
extern void BTx_CFGR1_RTCSEL1_Set(BT_Type* BTx, uint32_t SetValue);
extern uint32_t BTx_CFGR1_RTCSEL1_Get(BT_Type* BTx);

/* Group2�ź�ѡ����� (Group2 source select)
00 = APBCLK
01 = RTCOUT2
10 = IN_SIG2���ڲ������ź�2
11 = EX_SIG2���ⲿ�����ź�2
ע����֧��APBCLK���½��ز�׽�ͼ�������׽Դ�ͼ���ԴΪAPBCLKʱѡ���½��ؽ�������Ч��׽�ͼ����� ��غ��� */
extern void BTx_CFGR1_GRP2SEL_Set(BT_Type* BTx, uint32_t SetValue);
extern uint32_t BTx_CFGR1_GRP2SEL_Get(BT_Type* BTx);

/* Group1�ź�ѡ����ƣ�����Ϊ��׽ģʽ�²���ʱ��ѡ��ͬʱ����Ϊ�źŲ�׽Դ��(Group1 source select)
00 = APBCLK
01 = RTCOUT1
10 = IN_SIG1���ڲ������ź�1
11 = EX_SIG1���ⲿ�����ź�1
ע����֧��APBCLK���½��ز�׽�ͼ�������׽Դ�ͼ���ԴΪAPBCLKʱѡ���½��ؽ�������Ч��׽�ͼ����� ��غ��� */
extern void BTx_CFGR1_GRP1SEL_Set(BT_Type* BTx, uint32_t SetValue);
extern uint32_t BTx_CFGR1_GRP1SEL_Get(BT_Type* BTx);

/* �ⲿ�����ź�ѡ�����2 (external source select2)
00 = BT1_IN0/BT2_IN0
01 = BT1_IN1/BT2_IN1
10 = BT1_IN2/BT2_IN2
11 = BT1_IN3/BT2_IN3 ��غ��� */
extern void BTx_CFGR2_EXSEL2_Set(BT_Type* BTx, uint32_t SetValue);
extern uint32_t BTx_CFGR2_EXSEL2_Get(BT_Type* BTx);

/* �ⲿ�����ź�ѡ�����1 (external source select1)
00 = BT1_IN0/BT2_IN0
01 = BT1_IN1/BT2_IN1
10 = BT1_IN2/BT2_IN2
11 = BT1_IN3/BT2_IN3 ��غ��� */
extern void BTx_CFGR2_EXSEL1_Set(BT_Type* BTx, uint32_t SetValue);
extern uint32_t BTx_CFGR2_EXSEL1_Get(BT_Type* BTx);

/* �ڲ������ź�ѡ�����2 (internal source select 2)
00 = UART_RX3/UART_RX3
01 = UART_RX4/UART_RX4
10 = UART_RX5/UART_RX5
11 = RCLP/BT1_OUT ��غ��� */
extern void BTx_CFGR2_INSEL2_Set(BT_Type* BTx, uint32_t SetValue);
extern uint32_t BTx_CFGR2_INSEL2_Get(BT_Type* BTx);

/* �ڲ������ź�ѡ�����1 (internal source select 1)
00 = UART_RX0/UART_RX0
01 = UART_RX1/UART_RX1
10 = UART_RX2/UART_RX2
11 = RCLP/RCLP ��غ��� */
extern void BTx_CFGR2_INSEL1_Set(BT_Type* BTx, uint32_t SetValue);
extern uint32_t BTx_CFGR2_INSEL1_Get(BT_Type* BTx);

/* ����Group1��Ԥ��Ƶ�Ĵ��� (Group1 input signal prescaler)
��Ƶ��=��X+1������00��ʾ1��Ƶ��FF��ʾ256��Ƶ��Ԥ��Ƶ����źŶ�Ϊ�������������ʽ��ռ�ձ�1:X ��غ��� */
extern void BTx_PRES_Write(BT_Type* BTx, uint32_t SetValue);
extern uint32_t BTx_PRES_Read(BT_Type* BTx);

/* ��λ���ؿ��� (Counter highend load enable)
д1��Ԥ�����Ĵ���ET1PRESETH�ͼ��ؼĴ���ET1LOADH�ֱ���ص�����ֵ�Ĵ���ET1CNTH�ͱȽϼĴ���ET1CMPH��д0��Ч����λӲ���Զ���0����16λ�Ķ�ʱ/������LHEN��Ϊ�������ļ��ؿ��ƣ�LLEN�Զ�ʧЧ ��غ��� */
extern void BTx_LOADCR_LHEN_Setable(BT_Type* BTx, FunState NewState);
extern FunState BTx_LOADCR_LHEN_Getable(BT_Type* BTx);

/* ��λ���ؿ��� (Counter lowend load enable)
д1��Ԥ�����Ĵ���PRESETL�ͼ��ؼĴ���LOADL�ֱ���ص�����ֵ�Ĵ���ET1CNTL�ͱȽϼĴ���ET1CMPL��д0��Ч����λӲ���Զ���0����16λ�Ķ�ʱ/������LHEN��Ϊ�������ļ��ؿ��ƣ�LLEN�Զ�ʧЧ ��غ��� */
extern void BTx_LOADCR_LLEN_Setable(BT_Type* BTx, FunState NewState);
extern FunState BTx_LOADCR_LLEN_Getable(BT_Type* BTx);

/* ��������λ����ֵ�Ĵ��� (counter lowend)
LLEN��Чʱ����Ԥ�������üĴ����� ��غ��� */
extern uint32_t BTx_CNTL_Read(BT_Type* BTx);

/* ��������λ����ֵ�Ĵ��� (counter highend)
LHEN��Чʱ����Ԥ�������üĴ����� ��غ��� */
extern uint32_t BTx_CNTH_Read(BT_Type* BTx);

/* ��������λԤ�����Ĵ��� (preset highend)
���ڱ����λ��������ֵ���򱣴沶׽�����8bit ��غ��� */
extern void BTx_PRESET_PRESETH_Set(BT_Type* BTx, uint32_t SetValue);
extern uint32_t BTx_PRESET_PRESETH_Get(BT_Type* BTx);

/* ��������λԤ�����Ĵ��� (preset lowend)
���ڱ����λ��������ֵ���򱣴沶׽�����8bit ��غ��� */
extern void BTx_PRESET_PRESETL_Set(BT_Type* BTx, uint32_t SetValue);
extern uint32_t BTx_PRESET_PRESETL_Get(BT_Type* BTx);

/* ��������λ���ؼĴ��� (load lowend counter)
�ڼ���ƥ���ִ�м�������ʱ�����ؼĴ�����ֵ�������ȽϹ����Ĵ����� ��غ��� */
extern void BTx_LOADL_Write(BT_Type* BTx, uint32_t SetValue);
extern uint32_t BTx_LOADL_Read(BT_Type* BTx);

/* ��������λ���ؼĴ��� (load highend counter)
�ڼ���ƥ���ִ�м�������ʱ�����ؼĴ�����ֵ�������ȽϹ����Ĵ�������������8λ��ʱ/������ģʽʱ���ø�λ���ؼĴ�����֧�ּ���ֵΪ0x00�����á� ��غ��� */
extern void BTx_LOADH_Write(BT_Type* BTx, uint32_t SetValue);
extern uint32_t BTx_LOADH_Read(BT_Type* BTx);

/* ��������λ�ȽϼĴ��� (compare lowend )
���ؼĴ�����ֵ���غ�д��üĴ������üĴ�����������Ƚϣ�������ֵ���ڵ��ڸüĴ�����ֵ�����������ƥ���ź����������ģ�飬��������Ӧ�жϡ� ��غ��� */
extern void BTx_CMPL_Write(BT_Type* BTx, uint32_t SetValue);
extern uint32_t BTx_CMPL_Read(BT_Type* BTx);

/* ��������λ�ȽϼĴ��� (compare highend)
���ؼĴ�����ֵ���غ�д��üĴ������üĴ�����������Ƚϣ�������ֵ���ڵ��ڸüĴ�����ֵ�����������ƥ���ź����������ģ�飬��������Ӧ�жϡ� ��غ��� */
extern void BTx_CMPH_Write(BT_Type* BTx, uint32_t SetValue);
extern uint32_t BTx_CMPH_Read(BT_Type* BTx);

/* ��������������ȼ����� (output pulse width counter)
�üĴ������ڵ�����������ȡ�����ʱ��Ϊ32768Hz����Ӧ����������ȷ�ΧΪ30.5uS~125mS�����������=(OUTCNT+1)/32768�� ��غ��� */
extern void BTx_OUTCNT_Write(BT_Type* BTx, uint32_t SetValue);
extern uint32_t BTx_OUTCNT_Read(BT_Type* BTx);
extern void BTx_OCR_OUTCLR_Set(BT_Type* BTx, uint32_t SetValue);
extern uint32_t BTx_OCR_OUTCLR_Get(BT_Type* BTx);
extern void BTx_OCR_OUTINV_Set(BT_Type* BTx, uint32_t SetValue);
extern uint32_t BTx_OCR_OUTINV_Get(BT_Type* BTx);
extern void BTx_OCR_OUTMOD_Set(BT_Type* BTx, uint32_t SetValue);
extern uint32_t BTx_OCR_OUTMOD_Get(BT_Type* BTx);
extern void BTx_OCR_OUTSEL_Set(BT_Type* BTx, uint32_t SetValue);
extern uint32_t BTx_OCR_OUTSEL_Get(BT_Type* BTx);

/* ��չ��ʱ����λ�ȽϷ����ź� (compare highend interrupt enable)
1 = �ж�ʹ��
0 = �жϽ�ֹ ��غ��� */
extern void BTx_IER_CMPHIE_Setable(BT_Type* BTx, FunState NewState);
extern FunState BTx_IER_CMPHIE_Getable(BT_Type* BTx);

/* ��չ��ʱ����λ�ȽϷ����ź� (compare lowend interrupt enable)
1 = �ж�ʹ��
0 = �жϽ�ֹ ��غ��� */
extern void BTx_IER_CMPLIE_Setable(BT_Type* BTx, FunState NewState);
extern FunState BTx_IER_CMPLIE_Getable(BT_Type* BTx);

/* ��ʱ����λ����ź� (highend overflow interrupt enable)
1 = �ж�ʹ��
0 = �жϽ�ֹ ��غ��� */
extern void BTx_IER_OVHIE_Setable(BT_Type* BTx, FunState NewState);
extern FunState BTx_IER_OVHIE_Getable(BT_Type* BTx);

/* ��ʱ����λ����ź� (lowend overflow interrupt enable)
1 = �ж�ʹ��
0 = �жϽ�ֹ ��غ��� */
extern void BTx_IER_OVLIE_Setable(BT_Type* BTx, FunState NewState);
extern FunState BTx_IER_OVLIE_Getable(BT_Type* BTx);

/* ��ʱ����׽�����ź� (capture interrupt enable)
1 = �ж�ʹ��
0 = �жϽ�ֹ ��غ��� */
extern void BTx_IER_CAPIE_Setable(BT_Type* BTx, FunState NewState);
extern FunState BTx_IER_CAPIE_Getable(BT_Type* BTx);

/* ��׽��״̬
1 = ��׽������
0 = ��׽������ */
extern FlagStatus BTx_ISR_EDGESTA_Chk(BT_Type* BTx);

/* ��ʱ����λ�ȽϷ����ź� (compare highend interrupt flag)
1 = ��ǰ��������ֵ���ڵ��ڱȽϼĴ�����ֵ�����źŽ����¼����µļ��ؼĴ�����ֵ�������Ĵ�����
0 = ��ǰ��������ֵС�ڱȽϼĴ�����ֵ ��غ��� */
extern void BTx_ISR_CMPHIF_Clr(BT_Type* BTx);
extern FlagStatus BTx_ISR_CMPHIF_Chk(BT_Type* BTx);

/* ��ʱ����λ�ȽϷ����ź� (compare lowend interrupt flag)
1 = ��ǰ��������ֵ���ڵ��ڱȽϼĴ�����ֵ�����źŽ����¼����µļ��ؼĴ�����ֵ�������Ĵ�����
0 = ��ǰ��������ֵС�ڱȽϼĴ�����ֵ ��غ��� */
extern void BTx_ISR_CMPLIF_Clr(BT_Type* BTx);
extern FlagStatus BTx_ISR_CMPLIF_Chk(BT_Type* BTx);

/* ��ʱ����λ����ź� (highend overflow interrupt flag)
1 = �����������
0 = δ������� ��غ��� */
extern void BTx_ISR_OVHIF_Clr(BT_Type* BTx);
extern FlagStatus BTx_ISR_OVHIF_Chk(BT_Type* BTx);

/* ��ʱ����λ����ź� (lowend overflow interrupt flag)
1 = �����������
0 = δ������� ��غ��� */
extern void BTx_ISR_OVLIF_Clr(BT_Type* BTx);
extern FlagStatus BTx_ISR_OVLIF_Chk(BT_Type* BTx);

/* ��ʱ����׽�����ź� (capture interrupt flag)
1 = ��׽��ָ������
0 = δ��׽��ָ������ ��غ��� */
extern void BTx_ISR_CAPIF_Clr(BT_Type* BTx);
extern FlagStatus BTx_ISR_CAPIF_Chk(BT_Type* BTx);
//Announce_End

#ifdef __cplusplus
}
#endif

#endif /*__FM33A0XXEV_BT_H */
