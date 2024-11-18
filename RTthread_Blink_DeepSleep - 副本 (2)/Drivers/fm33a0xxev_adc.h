/**
  ******************************************************************************
  * @file    fm33a0xxev_adc.h
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file contains all the functions prototypes for the ADC firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
 
#ifndef __FM33A0XXEV_ADC_H
#define __FM33A0XXEV_ADC_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33A0XXEV.h" 
   
#define	ADC_CR_ADC_IE_Pos	7	/* ADC�ڲ��ۼ�ģʽ�ж�ʹ�� */
#define	ADC_CR_ADC_IE_Msk	(0x1U << ADC_CR_ADC_IE_Pos)

#define	ADC_CR_ACC_IE_Pos	6	/* ADC�ⲿ�ۼ�ģʽ�ж�ʹ�� */
#define	ADC_CR_ACC_IE_Msk	(0x1U << ADC_CR_ACC_IE_Pos)

#define	ADC_CR_HPEN_Pos	3	/* ADC����ģʽ
0���͹���ģʽ������ʱ�����1MHz
1���߹���ģʽ������ʱ�����2MHz */
#define	ADC_CR_HPEN_Msk	(0x1U << ADC_CR_HPEN_Pos)
#define	ADC_CR_HPEN_1MHZ	(0x0U << ADC_CR_HPEN_Pos)	/* �͹���ģʽ������ʱ�����1MHz */
#define	ADC_CR_HPEN_2MHZ	(0x1U << ADC_CR_HPEN_Pos)	/* �߹���ģʽ������ʱ�����2MHz */

#define	ADC_CR_MODE_Pos	2	/* ADC����ģʽ
0���ڲ��ۼ���ģʽ
1���ⲿ�ۼ�����CICģʽ */
#define	ADC_CR_MODE_Msk	(0x1U << ADC_CR_MODE_Pos)
#define	ADC_CR_MODE_INNER	(0x0U << ADC_CR_MODE_Pos)	/* �ڲ��ۼ���ģʽ */
#define	ADC_CR_MODE_EXTERNAL	(0x1U << ADC_CR_MODE_Pos)	/* �ⲿ�ۼ�����CICģʽ */

#define	ADC_CR_RSTCTRL_EN_Pos	1	/* ��������λʹ�ܣ���MODE=1����ʹ���ⲿ�ۼ���ʱ��������λ�����������±��뱣��Ϊ0
0����ֹ�������ⲿ��λ
1������������ⲿ��λ */
#define	ADC_CR_RSTCTRL_EN_Msk	(0x1U << ADC_CR_RSTCTRL_EN_Pos)
	/* ��ֹ�������ⲿ��λ */
	/* ����������ⲿ��λ */

#define	ADC_CR_EN_Pos	0	/* ADCʹ���ź�
0��ADC��ʹ��
1��ADCʹ��

ע�⣺RTCִ���Զ��²�ʱ��Ӳ�����������Զ�ʹ��ADC */
#define	ADC_CR_EN_Msk	(0x1U << ADC_CR_EN_Pos)
	/* ADC��ʹ�� */
	/* ADCʹ�� */
	/* RTCִ���Զ��²�ʱ��Ӳ�����������Զ�ʹ��ADC */

#define	ADC_TRIM_ADC_TRIM_Pos	0	/* ADC TRIMֵ��������ڲ��ۼ���ģʽ���
�ڲ��ۼ����ۼ����ڣ�Period = TRIM*2*TADC_CLK
�ۼ����ھ������������λ����TRIM=0x7FF���ֵʱ��ʵ���ۼ�����Ϊ4095 cycle����ADC������������Чλ����12bit */
#define	ADC_TRIM_ADC_TRIM_Msk	(0x7ffU << ADC_TRIM_ADC_TRIM_Pos)

#define	ADC_DR_ADC_DATA_Pos	0	/* ADC������ݣ�Ϊ�����ۼӽ����δ���������˲�������
��MODE=0ʱ�����ΪADC�ڲ��ۼӽ�������12bit��λ����ADC_TRIM����
��MODE=1ʱ�����λADC�ⲿ�ۼӽ�������14bit��λ����ACC_PERIOD���� */
#define	ADC_DR_ADC_DATA_Msk	(0xffffU << ADC_DR_ADC_DATA_Pos)

#define	ADC_ISR_INIT_RDY_Pos	9	/* ADC��ʼ����ɱ�־����MODE=1ʱ��Ч���������жϣ�
0��ADC��δ��ɳ�ʼ��
1��ADC��ɳ�ʼ��

ע��MODE=1��ADC_EN��λ�󣬵ȴ�MODE_CTRL_DELAYʱ��֮�󣬴˱�־��λ����ʾADC�ڲ�������������ɡ�MODE=0ʱ������ʱ����ADC�ڲ����п��ƣ��˱�־��Ч�� */
#define	ADC_ISR_INIT_RDY_Msk	(0x1U << ADC_ISR_INIT_RDY_Pos)

#define	ADC_ISR_ACC_IF_Pos	8	/* �ۼ�������жϱ�־��Ӳ����λ�����д1���㣬д0��Ч */
#define	ADC_ISR_ACC_IF_Msk	(0x1U << ADC_ISR_ACC_IF_Pos)

#define	ADC_ISR_ADC_DONE_Pos	1	/* ADCת�������������ֻ�����������жϣ�
ת����ɺ���źű���Ϊ�ߵ�ƽ��ֻ�йر�ADC�Ż���0 */
#define	ADC_ISR_ADC_DONE_Msk	(0x1U << ADC_ISR_ADC_DONE_Pos)

#define	ADC_ISR_ADC_IF_Pos	0	/* ADCת������жϱ�־��Ӳ����λ�����д1���㣬д0��Ч */
#define	ADC_ISR_ADC_IF_Msk	(0x1U << ADC_ISR_ADC_IF_Pos)

#define	ADC_CFGR_ACC_PERIOD_Pos	16	/* �ⲿ�ۼ����ۼ��������ã���λADC_CLK
000��1023����Ӧ���10bit��
001��2047����Ӧ���11bit��
010��4095����Ӧ���12bit��
011��8191����Ӧ���13bit��
100��16383����Ӧ���14bit��
Others��4095 */
#define	ADC_CFGR_ACC_PERIOD_Msk	(0x7U << ADC_CFGR_ACC_PERIOD_Pos)
#define	ADC_CFGR_ACC_PERIOD_10BITS	(0x0U << ADC_CFGR_ACC_PERIOD_Pos)	/* 1023����Ӧ���10bit�� */
#define	ADC_CFGR_ACC_PERIOD_11BITS	(0x1U << ADC_CFGR_ACC_PERIOD_Pos)	/* 2047����Ӧ���11bit�� */
#define	ADC_CFGR_ACC_PERIOD_12BITS	(0x2U << ADC_CFGR_ACC_PERIOD_Pos)	/* 4095����Ӧ���12bit�� */
#define	ADC_CFGR_ACC_PERIOD_13BITS	(0x3U << ADC_CFGR_ACC_PERIOD_Pos)	/* 8191����Ӧ���13bit�� */
#define	ADC_CFGR_ACC_PERIOD_14BITS	(0x4U << ADC_CFGR_ACC_PERIOD_Pos)	/* 16383����Ӧ���14bit�� */

#define	ADC_CFGR_RST_CTRL_DELAY_Pos	8	/* SDADCʹ�ܺ�mode_ctrl�ӳٳ������ã���λ��ADC_CLK����
0x00�����ӳ�
0xFF���ӳ�255��ADC_CLK

ע�⣺��λֵΪ16��ʱ�����ڣ������޸�ΪС��16����ֵ */
#define	ADC_CFGR_RST_CTRL_DELAY_Msk	(0xffU << ADC_CFGR_RST_CTRL_DELAY_Pos)

#define	ADC_CFGR_BUFEN_Pos	5	/* ADC����ͨ��Bufferʹ�� */
#define	ADC_CFGR_BUFEN_Msk	(0x1U << ADC_CFGR_BUFEN_Pos)

#define	ADC_CFGR_BUFSEL_Pos	0	/* ADC����ͨ��ѡ��
0000��ADC_IN0
0001��ADC_IN1
0010��ADC_IN2
0011��ADC_IN3
0100��ADC_IN4
0101��ADC_IN5
0110��ADC_IN6
0111��ADC_IN7
1000��ADC_IN8
1001��ADC_IN9
1010��ADC_IN10
1011��ADC_IN11
1100��ADC_IN12
1101��ADC_IN13
1110��VBAT
1111��TS */
#define	ADC_CFGR_BUFSEL_Msk	(0xfU << ADC_CFGR_BUFSEL_Pos)
#define	ADC_CFGR_BUFSEL_ADC_IN1	(0x1U << ADC_CFGR_BUFSEL_Pos)	/* ADC_IN1 */
#define	ADC_CFGR_BUFSEL_ADC_IN2	(0x2U << ADC_CFGR_BUFSEL_Pos)	/* ADC_IN2 */
#define	ADC_CFGR_BUFSEL_ADC_IN3	(0x3U << ADC_CFGR_BUFSEL_Pos)	/* ADC_IN3 */
#define	ADC_CFGR_BUFSEL_ADC_IN4	(0x4U << ADC_CFGR_BUFSEL_Pos)	/* ADC_IN4 */
#define	ADC_CFGR_BUFSEL_ADC_IN5	(0x5U << ADC_CFGR_BUFSEL_Pos)	/* ADC_IN5 */
#define	ADC_CFGR_BUFSEL_ADC_IN6	(0x6U << ADC_CFGR_BUFSEL_Pos)	/* ADC_IN6 */
#define	ADC_CFGR_BUFSEL_ADC_IN7	(0x7U << ADC_CFGR_BUFSEL_Pos)	/* ADC_IN7 */
#define	ADC_CFGR_BUFSEL_ADC_IN8	(0x8U << ADC_CFGR_BUFSEL_Pos)	/* ADC_IN8 */
#define	ADC_CFGR_BUFSEL_ADC_IN9	(0x9U << ADC_CFGR_BUFSEL_Pos)	/* ADC_IN9 */
#define	ADC_CFGR_BUFSEL_ADC_IN10	(0xaU << ADC_CFGR_BUFSEL_Pos)	/* ADC_IN10 */
#define	ADC_CFGR_BUFSEL_ADC_IN11	(0xbU << ADC_CFGR_BUFSEL_Pos)	/* ADC_IN11 */
#define	ADC_CFGR_BUFSEL_ADC_IN12	(0xcU << ADC_CFGR_BUFSEL_Pos)	/* ADC_IN12 */
#define	ADC_CFGR_BUFSEL_VBAT	(0xeU << ADC_CFGR_BUFSEL_Pos)	/* VBAT */
#define	ADC_CFGR_BUFSEL_TS	(0xfU << ADC_CFGR_BUFSEL_Pos)	/* TS */

#define	CIC_DR_ADC_CIC_DATA_Pos	0	/* CIC�˲���������ݣ�����Ƶ����ADC����ʱ�Ӻ�OSR��ͬ������ע������������з���������ʽΪ�����Ʋ��롣 */
#define	CIC_DR_ADC_CIC_DATA_Msk	(0xffffffU << CIC_DR_ADC_CIC_DATA_Pos)

#define	CIC_OS_ADC_CIC_OS_Pos	0	/* CIC�˲����������offset�����Ĵ��������д��offsetֵ��Ӳ����ADC_CIC_DR����OS����Եõ��޷��Ž�� */
#define	CIC_OS_ADC_CIC_OS_Msk	(0xffffffU << CIC_OS_ADC_CIC_OS_Pos)

#define	CIC_USDR_ADC_CIC_USDR_Pos	0	/* ADC_CIC_DR + ADC_CIC_OS�õ����޷�������� */
#define	CIC_USDR_ADC_CIC_USDR_Msk	(0xffffffU << CIC_USDR_ADC_CIC_USDR_Pos)

#define	CIC_CR_CIC_EN_Pos	31	/* CIC�˲���ʹ�� (CIC enable)
0���ر�CIC
1��ʹ��CIC */
#define	CIC_CR_CIC_EN_Msk	(0x1U << CIC_CR_CIC_EN_Pos)
	/* �ر�CIC */
	/* ʹ��CIC */

#define	CIC_CR_NS_DISC_Pos	8	/* CICʹ�ܺ������������ (Number of Samples to be Discarded)
���Զ���ADCʹ�ܺ�ͷ�����0~255��������
Ĭ��ֵ0x4��������ǰ4��ת��������ӵ�5�������ʼ����CIC_IF */
#define	CIC_CR_NS_DISC_Msk	(0xffU << CIC_CR_NS_DISC_Pos)

#define	CIC_CR_OVR_IE_Pos	7	/* CIC Overrun Interrupt enable
0����ֹCIC����ж�
1������CIC����ж� */
#define	CIC_CR_OVR_IE_Msk	(0x1U << CIC_CR_OVR_IE_Pos)
	/* ��ֹCIC����ж� */
	/* ����CIC����ж� */

#define	CIC_CR_CIC_IE_Pos	6	/* CIC�ж�ʹ�� (CIC interrupt enable)
0����ֹCIC�ж�
1������CIC�жϣ���CIC_IF��λʱ�����ж��¼� */
#define	CIC_CR_CIC_IE_Msk	(0x1U << CIC_CR_CIC_IE_Pos)
	/* ��ֹCIC�ж� */
	/* ����CIC�жϣ���CIC_IF��λʱ�����ж��¼� */

#define	CIC_CR_TRUNC_Pos	3	/* ������ݽ�ȡ���� (Truncate)���������ս���ж������λ��λ����
����TRUNC=0x4�����ս���������4bit�����ADC_CIC_DATA�Ĵ��� */
#define	CIC_CR_TRUNC_Msk	(0x7U << CIC_CR_TRUNC_Pos)

#define	CIC_CR_OSR_Pos	0	/* ������������ (Over Sampling Rate)
000��x8
001��x16
010��x32
011��x64
100��x128
101��x256
110��x512
111��x1024 */
#define CIC_CR_OSR_Msk	(0x7U << CIC_CR_OSR_Pos)
#define	CIC_CR_OSR_X8	(0x0U << CIC_CR_OSR_Pos)	/* x8 */
#define	CIC_CR_OSR_X16	(0x1U << CIC_CR_OSR_Pos)	/* x16 */
#define	CIC_CR_OSR_X32	(0x2U << CIC_CR_OSR_Pos)	/* x32 */
#define	CIC_CR_OSR_X64	(0x3U << CIC_CR_OSR_Pos)	/* x64 */
#define	CIC_CR_OSR_X128	(0x4U << CIC_CR_OSR_Pos)	/* x128 */
#define	CIC_CR_OSR_X256	(0x5U << CIC_CR_OSR_Pos)	/* x256 */
#define	CIC_CR_OSR_X512	(0x6U << CIC_CR_OSR_Pos)	/* x512 */
#define	CIC_CR_OSR_X1024	(0x7U << CIC_CR_OSR_Pos)	/* x1024 */

#define	CIC_ISR_CIC_OVR_Pos	1
#define	CIC_ISR_CIC_OVR_Msk	(0x1U << CIC_ISR_CIC_OVR_Pos)

#define	CIC_ISR_CIC_IF_Pos	0
#define	CIC_ISR_CIC_IF_Msk	(0x1U << CIC_ISR_CIC_IF_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void ADC_Deinit(void);

/* ADC�ڲ��ۼ�ģʽ�ж�ʹ�� ��غ��� */
extern void ADC_CR_ADC_IE_Setable(FunState NewState);
extern FunState ADC_CR_ADC_IE_Getable(void);

/* ADC�ⲿ�ۼ�ģʽ�ж�ʹ�� ��غ��� */
extern void ADC_CR_ACC_IE_Setable(FunState NewState);
extern FunState ADC_CR_ACC_IE_Getable(void);

/* ADC����ģʽ
0���͹���ģʽ������ʱ�����1MHz
1���߹���ģʽ������ʱ�����2MHz ��غ��� */
extern void ADC_CR_HPEN_Set(uint32_t SetValue);
extern uint32_t ADC_CR_HPEN_Get(void);

/* ADC����ģʽ
0���ڲ��ۼ���ģʽ
1���ⲿ�ۼ�����CICģʽ ��غ��� */
extern void ADC_CR_MODE_Set(uint32_t SetValue);
extern uint32_t ADC_CR_MODE_Get(void);

/* ��������λʹ�ܣ���MODE=1����ʹ���ⲿ�ۼ���ʱ��������λ�����������±��뱣��Ϊ0
0����ֹ�������ⲿ��λ
1������������ⲿ��λ ��غ��� */
extern void ADC_CR_RSTCTRL_EN_Setable(FunState NewState);
extern FunState ADC_CR_RSTCTRL_EN_Getable(void);

/* ADCʹ���ź�
0��ADC��ʹ��
1��ADCʹ��

ע�⣺RTCִ���Զ��²�ʱ��Ӳ�����������Զ�ʹ��ADC ��غ��� */
extern void ADC_CR_EN_Setable(FunState NewState);
extern FunState ADC_CR_EN_Getable(void);

/* ADC TRIMֵ��������ڲ��ۼ���ģʽ���
�ڲ��ۼ����ۼ����ڣ�Period = TRIM*2*TADC_CLK
�ۼ����ھ������������λ����TRIM=0x7FF���ֵʱ��ʵ���ۼ�����Ϊ4095 cycle����ADC������������Чλ����12bit ��غ��� */
extern void ADC_TRIM_Write(uint32_t SetValue);
extern uint32_t ADC_TRIM_Read(void);

/* ADC������ݣ�Ϊ�����ۼӽ����δ���������˲�������
��MODE=0ʱ�����ΪADC�ڲ��ۼӽ�������12bit��λ����ADC_TRIM����
��MODE=1ʱ�����λADC�ⲿ�ۼӽ�������14bit��λ����ACC_PERIOD���� ��غ��� */
extern uint32_t ADC_DR_Read(void);

/* ADC��ʼ����ɱ�־����MODE=1ʱ��Ч���������жϣ�
0��ADC��δ��ɳ�ʼ��
1��ADC��ɳ�ʼ��

ע��MODE=1��ADC_EN��λ�󣬵ȴ�MODE_CTRL_DELAYʱ��֮�󣬴˱�־��λ����ʾADC�ڲ�������������ɡ�MODE=0ʱ������ʱ����ADC�ڲ����п��ƣ��˱�־��Ч�� ��غ��� */
extern FlagStatus ADC_ISR_INIT_RDY_Chk(void);

/* �ۼ�������жϱ�־��Ӳ����λ�����д1���㣬д0��Ч ��غ��� */
extern void ADC_ISR_ACC_IF_Clr(void);
extern FlagStatus ADC_ISR_ACC_IF_Chk(void);

/* ADCת�������������ֻ�����������жϣ�
ת����ɺ���źű���Ϊ�ߵ�ƽ��ֻ�йر�ADC�Ż���0 ��غ��� */
extern FlagStatus ADC_ISR_ADC_DONE_Chk(void);

/* ADCת������жϱ�־��Ӳ����λ�����д1���㣬д0��Ч ��غ��� */
extern void ADC_ISR_ADC_IF_Clr(void);
extern FlagStatus ADC_ISR_ADC_IF_Chk(void);

/* �ⲿ�ۼ����ۼ��������ã���λADC_CLK
000��1023����Ӧ���10bit��
001��2047����Ӧ���11bit��
010��4095����Ӧ���12bit��
011��8191����Ӧ���13bit��
100��16383����Ӧ���14bit��
Others��4095 ��غ��� */
extern void ADC_CFGR_ACC_PERIOD_Set(uint32_t SetValue);
extern uint32_t ADC_CFGR_ACC_PERIOD_Get(void);

/* SDADCʹ�ܺ�mode_ctrl�ӳٳ������ã���λ��ADC_CLK����
0x00�����ӳ�
0xFF���ӳ�255��ADC_CLK

ע�⣺��λֵΪ16��ʱ�����ڣ������޸�ΪС��16����ֵ ��غ��� */
extern void ADC_CFGR_RST_CTRL_DELAY_Set(uint32_t SetValue);
extern uint32_t ADC_CFGR_RST_CTRL_DELAY_Get(void);

/* ADC����ͨ��Bufferʹ�� ��غ��� */
extern void ADC_CFGR_BUFEN_Setable(FunState NewState);
extern FunState ADC_CFGR_BUFEN_Getable(void);

/* ADC����ͨ��ѡ��
0000��ADC_IN0
0001��ADC_IN1
0010��ADC_IN2
0011��ADC_IN3
0100��ADC_IN4
0101��ADC_IN5
0110��ADC_IN6
0111��ADC_IN7
1000��ADC_IN8
1001��ADC_IN9
1010��ADC_IN10
1011��ADC_IN11
1100��ADC_IN12
1101��ADC_IN13
1110��VBAT
1111��TS ��غ��� */
extern void ADC_CFGR_BUFSEL_Set(uint32_t SetValue);
extern uint32_t ADC_CFGR_BUFSEL_Get(void);

/* CIC�˲���������ݣ�����Ƶ����ADC����ʱ�Ӻ�OSR��ͬ������ע������������з���������ʽΪ�����Ʋ��롣 ��غ��� */
extern uint32_t CIC_DR_Read(void);

/* CIC�˲����������offset�����Ĵ��������д��offsetֵ��Ӳ����ADC_CIC_DR����OS����Եõ��޷��Ž�� ��غ��� */
extern void ACIC_OS_Write(uint32_t SetValue);
extern uint32_t CIC_OS_Read(void);

/* ADC_CIC_DR + ADC_CIC_OS�õ����޷�������� ��غ��� */
extern uint32_t CIC_USDR_Read(void);

/* CIC�˲���ʹ�� (CIC enable)
0���ر�CIC
1��ʹ��CIC ��غ��� */
extern void CIC_CR_CIC_EN_Setable(FunState NewState);
extern FunState CIC_CR_CIC_EN_Getable(void);

/* CICʹ�ܺ������������ (Number of Samples to be Discarded)
���Զ���ADCʹ�ܺ�ͷ�����0~255��������
Ĭ��ֵ0x4��������ǰ4��ת��������ӵ�5�������ʼ����CIC_IF ��غ��� */
extern void ACIC_CR_NS_DISC_Set(uint32_t SetValue);
extern uint32_t CIC_CR_NS_DISC_Get(void);

/* CIC Overrun Interrupt enable
0����ֹCIC����ж�
1������CIC����ж� ��غ��� */
extern void CIC_CR_OVR_IE_Setable(FunState NewState);
extern FunState CIC_CR_OVR_IE_Getable(void);

/* CIC�ж�ʹ�� (CIC interrupt enable)
0����ֹCIC�ж�
1������CIC�жϣ���CIC_IF��λʱ�����ж��¼� ��غ��� */
extern void CIC_CR_CIC_IE_Setable(FunState NewState);
extern FunState IC_CR_CIC_IE_Getable(void);

/* ������ݽ�ȡ���� (Truncate)���������ս���ж������λ��λ����
����TRUNC=0x4�����ս���������4bit�����ADC_CIC_DATA�Ĵ��� ��غ��� */
extern void CIC_CR_TRUNC_Set(uint32_t SetValue);
extern uint32_t CIC_CR_TRUNC_Get(void);

/* ������������ (Over Sampling Rate)
000��x8
001��x16
010��x32
011��x64
100��x128
101��x256
110��x512
111��x1024 ��غ��� */
extern void CIC_CR_OSR_Set(uint32_t SetValue);
extern uint32_t CIC_CR_OSR_Get(void);
extern void CIC_ISR_CIC_OVR_Clr(void);
extern FlagStatus CIC_ISR_CIC_OVR_Chk(void);
extern void CIC_ISR_CIC_IF_Clr(void);
extern FlagStatus CIC_ISR_CIC_IF_Chk(void);

#ifdef __cplusplus
}
#endif

#endif /* __FM33A0XXEV_ADC_H */
