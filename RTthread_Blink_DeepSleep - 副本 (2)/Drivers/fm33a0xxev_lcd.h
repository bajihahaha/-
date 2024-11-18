/**
  ******************************************************************************
  * @file    fm33a0xxev_lcd.h
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file contains all the functions prototypes for the LCD firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33A0XXEV_LCD_H
#define __FM33A0XXEV_LCD_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33A0XXEV.h" 
  
#define	LCD_CR_SCSEL_Pos	20/* ��������ģʽ������Ƶ��
000��Ƶ��Ϊ֡Ƶ*COM��
001��Ƶ��ΪLSCLK/8
010��Ƶ��ΪLSCLK/16
011��Ƶ��ΪLSCLK/32
100��Ƶ��ΪLSCLK/64
101��Ƶ��ΪLSCLK/128
110��Ƶ��ΪLSCLK/256
111��Ƶ��ΪLSCLK/512��غ��� */
#define	LCD_CR_SCSEL_Msk	(0x7U << LCD_CR_SCSEL_Pos)
#define	LCD_CR_SCSEL_LSCLK_COM		(0x0U << LCD_CR_SCSEL_Pos)	/* Ƶ��Ϊ֡Ƶ*COM�� */
#define	LCD_CR_SCSEL_LSCLK_8		(0x1U << LCD_CR_SCSEL_Pos)	/* Ƶ��ΪLSCLK/8*/
#define	LCD_CR_SCSEL_LSCLK_16		(0x2U << LCD_CR_SCSEL_Pos)	/* Ƶ��ΪLSCLK/16 */
#define	LCD_CR_SCSEL_LSCLK_32		(0x3U << LCD_CR_SCSEL_Pos)	/* Ƶ��ΪLSCLK/32 */
#define	LCD_CR_SCSEL_LSCLK_64		(0x4U << LCD_CR_SCSEL_Pos)	/* Ƶ��ΪLSCLK/64 */
#define	LCD_CR_SCSEL_LSCLK_128		(0x5U << LCD_CR_SCSEL_Pos)	/* Ƶ��ΪLSCLK/128 */
#define	LCD_CR_SCSEL_LSCLK_256		(0x6U << LCD_CR_SCSEL_Pos)	/* Ƶ��ΪLSCLK/256 */
#define	LCD_CR_SCSEL_LSCLK_512		(0x7U << LCD_CR_SCSEL_Pos)	/* Ƶ��ΪLSCLK/512 */

#define	LCD_CR_SC_CTRL_Pos	18/* ��������ģʽ��������ʽ���� 
00����������
01����������2��
10����������4��
11��������� ��غ��� */
#define	LCD_CR_SC_CTRL_Msk	(0x3U << LCD_CR_SC_CTRL_Pos)
#define	LCD_CR_SC_CTRL_S0	(0x0U << LCD_CR_SC_CTRL_Pos)	/* �������� */
#define	LCD_CR_SC_CTRL_S1	(0x1U << LCD_CR_SC_CTRL_Pos)	/* ��������2��*/
#define	LCD_CR_SC_CTRL_S2	(0x2U << LCD_CR_SC_CTRL_Pos)	/* ��������4�� */
#define	LCD_CR_SC_CTRL_S3	(0x3U << LCD_CR_SC_CTRL_Pos)	/* ������� */

	 
#define	LCD_CR_IC_CTRL_Pos	16	/* ƫ�õ�·�������Դ��С���� (Input bias Current Control)
00���������
01�������δ�
10��������С
11��������С */
#define	LCD_CR_IC_CTRL_Msk	(0x3U << LCD_CR_IC_CTRL_Pos)
#define	LCD_CR_IC_CTRL_L3	(0x0U << LCD_CR_IC_CTRL_Pos)	/* ������� */
#define	LCD_CR_IC_CTRL_L2	(0x1U << LCD_CR_IC_CTRL_Pos)	/* �����δ� */
#define	LCD_CR_IC_CTRL_L1	(0x2U << LCD_CR_IC_CTRL_Pos)	/* ������С */
#define	LCD_CR_IC_CTRL_L0	(0x3U << LCD_CR_IC_CTRL_Pos)	/* ������С */

#define	LCD_CR_ENMODE_Pos	15	/* ����ģʽѡ�� (LCD Enabling Mode)
0��RFU
1��Ƭ�ڵ��������� */
#define	LCD_CR_ENMODE_Msk	(0x1U << LCD_CR_ENMODE_Pos)
#define	LCD_CR_ENMODE_EXTERNALCAP	(0x0U << LCD_CR_ENMODE_Pos)	/* 0 = Ƭ��������� */
#define	LCD_CR_ENMODE_INNERRESISTER	(0x1U << LCD_CR_ENMODE_Pos)	/* 1 = Ƭ�ڵ��������� */

#define	LCD_CR_FLICK_Pos	14	/* ��ʾ��˸ʹ��λ (LCD Flick Enable)
1����ʾ��˸����˸Ƶ����TON��TOFF�Ĵ�������
0���ر���˸ */
#define	LCD_CR_FLICK_Msk	(0x1U << LCD_CR_FLICK_Pos)
	/* ��ʾ��˸����˸Ƶ����TON��TOFF�Ĵ������� */
	/* �ر���˸ */

#define	LCD_CR_BIAS_Pos	8	/* LCDƫ�õ�ƽѡ��λ��������ʾ�Ҷȿ��� (LCD Bias Voltage Select) */
#define	LCD_CR_BIAS_Msk	(0xfU << LCD_CR_BIAS_Pos)

#define	LCD_CR_BIASMD_Pos	5	/* ƫ������ѡ�� (Bias Mode)
1��1/3 Bias
0��1/4 Bias */
#define	LCD_CR_BIASMD_Msk	(0x1U << LCD_CR_BIASMD_Pos)
#define	LCD_CR_BIASMD_3BIAS	(0x1U << LCD_CR_BIASMD_Pos)	/* 1/3 Bias */
#define	LCD_CR_BIASMD_4BIAS	(0x0U << LCD_CR_BIASMD_Pos)	/* 1/4 Bias */

#define	LCD_CR_ANTIPOLAR_Pos	4	/* ������ʹ�� (Anti-Polarization)
1��COM��SEG��LCD�ر�����½ӵ�
0��COM��SEG��LCD�ر�����¸��� */
#define	LCD_CR_ANTIPOLAR_Msk	(0x1U << LCD_CR_ANTIPOLAR_Pos)
#define	LCD_CR_ANTIPOLAR_GND	(0x1U << LCD_CR_ANTIPOLAR_Pos)	/* COM��SEG��LCD�ر�����½ӵ� */
#define	LCD_CR_ANTIPOLAR_FLOAT	(0x0U << LCD_CR_ANTIPOLAR_Pos)	/* COM��SEG��LCD�ر�����¸��� */

#define	LCD_CR_WFT_Pos	3	/* ��������ѡ�� (Waveform Format)
1��B�ನ��
0��A�ನ�� */
#define	LCD_CR_WFT_Msk	(0x1U << LCD_CR_WFT_Pos)
#define	LCD_CR_WFT_BTYPE	(0x1U << LCD_CR_WFT_Pos)	/* B�ನ�� */
#define	LCD_CR_WFT_ATYPE	(0x0U << LCD_CR_WFT_Pos)	/* A�ನ�� */

#define	LCD_CR_LMUX_Pos	1	/* COM����ѡ�� (Segment Line Mux)
00��4COM
01��6COM
10/11��8COM */
#define	LCD_CR_LMUX_Msk	(0x3U << LCD_CR_LMUX_Pos)
#define	LCD_CR_LMUX_4COM	(0x0U << LCD_CR_LMUX_Pos)	/* 4COM */
#define	LCD_CR_LMUX_6COM	(0x1U << LCD_CR_LMUX_Pos)	/* 6COM */
#define	LCD_CR_LMUX_8COM	(0x2U << LCD_CR_LMUX_Pos)	/* 8COM */


#define	LCD_CR_EN_Pos	0	/* LCD��ʾʹ��λ (LCD Enable)
1������LCD��ʾ
0���ر�LCD��ʾ */
#define	LCD_CR_EN_Msk	(0x1U << LCD_CR_EN_Pos)
	/* ����LCD��ʾ */
	/* �ر�LCD��ʾ */

#define	LCD_TEST_LCCTRL_Pos	7	/* LCD���Կ���λ�����ڲ���ģʽ����Ч (Line Constant Control)
COM��SEG�����ƽ�ɲ���ģʽ�µ�����������ݼĴ�����������ͬ������SEG��COM����Ľ���μ����ı�� */
#define	LCD_TEST_LCCTRL_Msk	(0x1U << LCD_TEST_LCCTRL_Pos)
#define	LCD_TEST_LCCTRL_LOW	(0x0U << LCD_TEST_LCCTRL_Pos)
#define	LCD_TEST_LCCTRL_HIGH	(0x1U << LCD_TEST_LCCTRL_Pos)

#define	LCD_TEST_TESTEN_Pos	0	/* ����ģʽʹ��λ (Test mode Enable)
1��LCD����ģʽʹ�ܡ���LCD����ģʽ�£�LCD���ž�̬���ģ��ֱ����ƽ�������붯̬ɨ��ʱ���Լ�ɨ�貨����ؼĴ���������Ч
0����������ģʽ������ģʽ��Ч����ز��ԼĴ���������Ч */
#define	LCD_TEST_TESTEN_Msk	(0x1U << LCD_TEST_TESTEN_Pos)
	/* LCD����ģʽʹ�ܡ���LCD����ģʽ�£�LCD���ž�̬���ģ��ֱ����ƽ�������붯̬ɨ��ʱ���Լ�ɨ�貨����ؼĴ���������Ч */
	/* ��������ģʽ������ģʽ��Ч����ز��ԼĴ���������Ч */

#define	LCD_FCR_DF_Pos	0	/* ��ʾԤ��Ƶ�Ĵ��� (Display Frequency) */
#define	LCD_FCR_DF_Msk	(0xffU << LCD_FCR_DF_Pos)

#define	LCD_FLKT_TOFF_Pos	8	/* ��˸��ʾϨ��ʱ��Ĵ��� (Display-Off Time)
TOFF��С����ΪTstep = COM*DF[7:0]*2*16/32768Hz��ʵ��OFFʱ��ΪTOFF * Tstep */
#define	LCD_FLKT_TOFF_Msk	(0xffU << LCD_FLKT_TOFF_Pos)

#define	LCD_FLKT_TON_Pos	0	/* ��˸��ʾ����ʱ��Ĵ��� (Display-On Time)
TON��С����ΪTstep = COM*DF[7:0]*2*16/32768Hz��ʵ��ONʱ��ΪTON * Tstep */
#define	LCD_FLKT_TON_Msk	(0xffU << LCD_FLKT_TON_Pos)

#define	LCD_IER_DONIE_Pos	1	/* ��ʾ�����ж�ʹ��λ (Display-On Interrupt Enable)
1����ʾ�����ж�ʹ��
0����ʾ�����жϽ�ֹ */
#define	LCD_IER_DONIE_Msk	(0x1U << LCD_IER_DONIE_Pos)
	/* ��ʾ�����ж�ʹ�� */
	/* ��ʾ�����жϽ�ֹ */

#define	LCD_IER_DOFFIE_Pos	0	/* ��ʾϨ���ж�ʹ��λ (Display-OFF Interrupt Enable)
1����ʾϨ���ж�ʹ��
0����ʾϨ���жϽ�ֹ */
#define	LCD_IER_DOFFIE_Msk	(0x1U << LCD_IER_DOFFIE_Pos)
	/* ��ʾϨ���ж�ʹ�� */
	/* ��ʾϨ���жϽ�ֹ */

#define	LCD_ISR_DONIF_Pos	1	/* ��ʾ�����жϱ�־ (Display-On Interrupt Flag,write 1 to clear)
��ʾ�������ʱӲ�������жϱ�־��Ӳ����λ��������� */
#define	LCD_ISR_DONIF_Msk	(0x1U << LCD_ISR_DONIF_Pos)

#define	LCD_ISR_DOFFIF_Pos	0	/* ��ʾϨ���жϱ�־ (Display-OFF Interrupt Flag,write 1 to clear)
��ʾ��������ʱӲ�������жϱ�־��Ӳ����λ��������� */
#define	LCD_ISR_DOFFIF_Msk	(0x1U << LCD_ISR_DOFFIF_Pos)

#define	LCD_BSTCR_OSC_CFG_Pos	12
#define	LCD_BSTCR_OSC_CFG_Msk	(0xfU << LCD_BSTCR_OSC_CFG_Pos)

#define	LCD_BSTCR_BUF_OFF_Pos	9
#define	LCD_BSTCR_BUF_OFF_Msk	(0x1U << LCD_BSTCR_BUF_OFF_Pos)

#define	LCD_BSTCR_BUFBYP_Pos	8
#define	LCD_BSTCR_BUFBYP_Msk	(0x1U << LCD_BSTCR_BUFBYP_Pos)

#define	LCD_BSTCR_VLCDPD_Pos	7
#define	LCD_BSTCR_VLCDPD_Msk	(0x1U << LCD_BSTCR_VLCDPD_Pos)

#define	LCD_BSTCR_VLCDCFG_Pos	2
#define	LCD_BSTCR_VLCDCFG_Msk	(0x1fU << LCD_BSTCR_VLCDCFG_Pos)
#define	LCD_BSTCR_VLCDCFG_2_4V	(0x0U << LCD_BSTCR_VLCDCFG_Pos)
#define	LCD_BSTCR_VLCDCFG_2_6V	(0x1U << LCD_BSTCR_VLCDCFG_Pos)
#define	LCD_BSTCR_VLCDCFG_2_8V	(0x2U << LCD_BSTCR_VLCDCFG_Pos)
#define	LCD_BSTCR_VLCDCFG_3_0V	(0x3U << LCD_BSTCR_VLCDCFG_Pos)
#define	LCD_BSTCR_VLCDCFG_3_2V	(0x4U << LCD_BSTCR_VLCDCFG_Pos)
#define	LCD_BSTCR_VLCDCFG_3_4V	(0x5U << LCD_BSTCR_VLCDCFG_Pos)
#define	LCD_BSTCR_VLCDCFG_3_6V	(0x6U << LCD_BSTCR_VLCDCFG_Pos)
#define	LCD_BSTCR_VLCDCFG_3_8V	(0x7U << LCD_BSTCR_VLCDCFG_Pos)
#define	LCD_BSTCR_VLCDCFG_4_0V	(0x8U << LCD_BSTCR_VLCDCFG_Pos)
#define	LCD_BSTCR_VLCDCFG_4_2V	(0x9U << LCD_BSTCR_VLCDCFG_Pos)
#define	LCD_BSTCR_VLCDCFG_4_4V	(0xaU << LCD_BSTCR_VLCDCFG_Pos)
#define	LCD_BSTCR_VLCDCFG_4_6V	(0xbU << LCD_BSTCR_VLCDCFG_Pos)
#define	LCD_BSTCR_VLCDCFG_4_8V	(0xcU << LCD_BSTCR_VLCDCFG_Pos)
#define	LCD_BSTCR_VLCDCFG_5_0V	(0xdU << LCD_BSTCR_VLCDCFG_Pos)
#define	LCD_BSTCR_VLCDCFG_5_2V	(0xeU << LCD_BSTCR_VLCDCFG_Pos)
#define	LCD_BSTCR_VLCDCFG_5_4V	(0xfU << LCD_BSTCR_VLCDCFG_Pos)

#define	LCD_BSTCR_BOOST_TEN_Pos	1
#define	LCD_BSTCR_BOOST_TEN_Msk	(0x1U << LCD_BSTCR_BOOST_TEN_Pos)

#define	LCD_BSTCR_BOOST_EN_Pos	0
#define	LCD_BSTCR_BOOST_EN_Msk	(0x1U << LCD_BSTCR_BOOST_EN_Pos)

#define	LCD_COM_EN_COMEN_Pos	0	/* LCD COM0~3���ʹ�ܿ��� */
#define	LCD_COM_EN_COMEN_Msk	(0xfU << LCD_COM_EN_COMEN_Pos)

#define	LCD_SEG_EN0_SEGENx_Pos	0	/* LCD SEG0~31���ʹ�ܿ��� */
#define	LCD_SEG_EN0_SEGENx_Msk	(0xffffffffU << LCD_SEG_EN0_SEGENx_Pos)

#define	LCD_SEG_EN1_SEGENx_Pos	0	/* LCD SEG32~43,COM4~7���ʹ�ܿ��� */
#define	LCD_SEG_EN1_SEGENx_Msk	(0xfffU << LCD_SEG_EN1_SEGENx_Pos)

#define	LCD_COM_EN_COMEN3_Pos	3	/* COM3�������@4\6\8COMģʽ */
#define	LCD_COM_EN_COMEN3_Msk	(0x1U << LCD_COM_EN_COMEN3_Pos)

#define	LCD_COM_EN_COMEN2_Pos	2	/* COM2�������@4\6\8COMģʽ */
#define	LCD_COM_EN_COMEN2_Msk	(0x1U << LCD_COM_EN_COMEN2_Pos)

#define	LCD_COM_EN_COMEN1_Pos	1	/* COM1�������@4\6\8COMģʽ */
#define	LCD_COM_EN_COMEN1_Msk	(0x1U << LCD_COM_EN_COMEN1_Pos)

#define	LCD_COM_EN_COMEN0_Pos	0	/* COM0�������@4\6\8COMģʽ */
#define	LCD_COM_EN_COMEN0_Msk	(0x1U << LCD_COM_EN_COMEN0_Pos)

#define	LCD_SEG_EN0_SEGEN31_Pos	31	/* SEG31������� */
#define	LCD_SEG_EN0_SEGEN31_Msk	(0x1U << LCD_SEG_EN0_SEGEN31_Pos)

#define	LCD_SEG_EN0_SEGEN30_Pos	30	/* SEG30������� */
#define	LCD_SEG_EN0_SEGEN30_Msk	(0x1U << LCD_SEG_EN0_SEGEN30_Pos)

#define	LCD_SEG_EN0_SEGEN29_Pos	29	/* SEG29������� */
#define	LCD_SEG_EN0_SEGEN29_Msk	(0x1U << LCD_SEG_EN0_SEGEN29_Pos)

#define	LCD_SEG_EN0_SEGEN28_Pos	28	/* SEG28������� */
#define	LCD_SEG_EN0_SEGEN28_Msk	(0x1U << LCD_SEG_EN0_SEGEN28_Pos)

#define	LCD_SEG_EN0_SEGEN27_Pos	27	/* SEG27������� */
#define	LCD_SEG_EN0_SEGEN27_Msk	(0x1U << LCD_SEG_EN0_SEGEN27_Pos)

#define	LCD_SEG_EN0_SEGEN26_Pos	26	/* SEG26������� */
#define	LCD_SEG_EN0_SEGEN26_Msk	(0x1U << LCD_SEG_EN0_SEGEN26_Pos)

#define	LCD_SEG_EN0_SEGEN25_Pos	25	/* SEG25������� */
#define	LCD_SEG_EN0_SEGEN25_Msk	(0x1U << LCD_SEG_EN0_SEGEN25_Pos)

#define	LCD_SEG_EN0_SEGEN24_Pos	24	/* SEG24������� */
#define	LCD_SEG_EN0_SEGEN24_Msk	(0x1U << LCD_SEG_EN0_SEGEN24_Pos)

#define	LCD_SEG_EN0_SEGEN23_Pos	23	/* SEG23������� */
#define	LCD_SEG_EN0_SEGEN23_Msk	(0x1U << LCD_SEG_EN0_SEGEN23_Pos)

#define	LCD_SEG_EN0_SEGEN22_Pos	22	/* SEG22������� */
#define	LCD_SEG_EN0_SEGEN22_Msk	(0x1U << LCD_SEG_EN0_SEGEN22_Pos)

#define	LCD_SEG_EN0_SEGEN21_Pos	21	/* SEG21������� */
#define	LCD_SEG_EN0_SEGEN21_Msk	(0x1U << LCD_SEG_EN0_SEGEN21_Pos)

#define	LCD_SEG_EN0_SEGEN20_Pos	20	/* SEG20������� */
#define	LCD_SEG_EN0_SEGEN20_Msk	(0x1U << LCD_SEG_EN0_SEGEN20_Pos)

#define	LCD_SEG_EN0_SEGEN19_Pos	19	/* SEG19������� */
#define	LCD_SEG_EN0_SEGEN19_Msk	(0x1U << LCD_SEG_EN0_SEGEN19_Pos)

#define	LCD_SEG_EN0_SEGEN18_Pos	18	/* SEG18������� */
#define	LCD_SEG_EN0_SEGEN18_Msk	(0x1U << LCD_SEG_EN0_SEGEN18_Pos)

#define	LCD_SEG_EN0_SEGEN17_Pos	17	/* SEG17������� */
#define	LCD_SEG_EN0_SEGEN17_Msk	(0x1U << LCD_SEG_EN0_SEGEN17_Pos)

#define	LCD_SEG_EN0_SEGEN16_Pos	16	/* SEG16������� */
#define	LCD_SEG_EN0_SEGEN16_Msk	(0x1U << LCD_SEG_EN0_SEGEN16_Pos)

#define	LCD_SEG_EN0_SEGEN15_Pos	15	/* SEG15������� */
#define	LCD_SEG_EN0_SEGEN15_Msk	(0x1U << LCD_SEG_EN0_SEGEN15_Pos)

#define	LCD_SEG_EN0_SEGEN14_Pos	14	/* SEG14������� */
#define	LCD_SEG_EN0_SEGEN14_Msk	(0x1U << LCD_SEG_EN0_SEGEN14_Pos)

#define	LCD_SEG_EN0_SEGEN13_Pos	13	/* SEG13������� */
#define	LCD_SEG_EN0_SEGEN13_Msk	(0x1U << LCD_SEG_EN0_SEGEN13_Pos)

#define	LCD_SEG_EN0_SEGEN12_Pos	12	/* SEG12������� */
#define	LCD_SEG_EN0_SEGEN12_Msk	(0x1U << LCD_SEG_EN0_SEGEN12_Pos)

#define	LCD_SEG_EN0_SEGEN11_Pos	11	/* SEG11������� */
#define	LCD_SEG_EN0_SEGEN11_Msk	(0x1U << LCD_SEG_EN0_SEGEN11_Pos)

#define	LCD_SEG_EN0_SEGEN10_Pos	10	/* SEG10������� */
#define	LCD_SEG_EN0_SEGEN10_Msk	(0x1U << LCD_SEG_EN0_SEGEN10_Pos)

#define	LCD_SEG_EN0_SEGEN9_Pos	9	/* SEG9������� */
#define	LCD_SEG_EN0_SEGEN9_Msk	(0x1U << LCD_SEG_EN0_SEGEN9_Pos)

#define	LCD_SEG_EN0_SEGEN8_Pos	8	/* SEG8������� */
#define	LCD_SEG_EN0_SEGEN8_Msk	(0x1U << LCD_SEG_EN0_SEGEN8_Pos)

#define	LCD_SEG_EN0_SEGEN7_Pos	7	/* SEG7������� */
#define	LCD_SEG_EN0_SEGEN7_Msk	(0x1U << LCD_SEG_EN0_SEGEN7_Pos)

#define	LCD_SEG_EN0_SEGEN6_Pos	6	/* SEG6������� */
#define	LCD_SEG_EN0_SEGEN6_Msk	(0x1U << LCD_SEG_EN0_SEGEN6_Pos)

#define	LCD_SEG_EN0_SEGEN5_Pos	5	/* SEG5������� */
#define	LCD_SEG_EN0_SEGEN5_Msk	(0x1U << LCD_SEG_EN0_SEGEN5_Pos)

#define	LCD_SEG_EN0_SEGEN4_Pos	4	/* SEG4������� */
#define	LCD_SEG_EN0_SEGEN4_Msk	(0x1U << LCD_SEG_EN0_SEGEN4_Pos)

#define	LCD_SEG_EN0_SEGEN3_Pos	3	/* SEG3������� */
#define	LCD_SEG_EN0_SEGEN3_Msk	(0x1U << LCD_SEG_EN0_SEGEN3_Pos)

#define	LCD_SEG_EN0_SEGEN2_Pos	2	/* SEG2������� */
#define	LCD_SEG_EN0_SEGEN2_Msk	(0x1U << LCD_SEG_EN0_SEGEN2_Pos)

#define	LCD_SEG_EN0_SEGEN1_Pos	1	/* SEG1������� */
#define	LCD_SEG_EN0_SEGEN1_Msk	(0x1U << LCD_SEG_EN0_SEGEN1_Pos)

#define	LCD_SEG_EN0_SEGEN0_Pos	0	/* SEG0������� */
#define	LCD_SEG_EN0_SEGEN0_Msk	(0x1U << LCD_SEG_EN0_SEGEN0_Pos)

#define	LCD_SEG_EN1_SEGEN43_Pos	11	/* SEG43������� */
#define	LCD_SEG_EN1_SEGEN43_Msk	(0x1U << LCD_SEG_EN1_SEGEN43_Pos)

#define	LCD_SEG_EN1_SEGEN42_Pos	10	/* SEG42������� */
#define	LCD_SEG_EN1_SEGEN42_Msk	(0x1U << LCD_SEG_EN1_SEGEN42_Pos)

#define	LCD_SEG_EN1_SEGEN41_Pos	9	/* SEG41������� */
#define	LCD_SEG_EN1_SEGEN41_Msk	(0x1U << LCD_SEG_EN1_SEGEN41_Pos)

#define	LCD_SEG_EN1_SEGEN40_Pos	8	/* SEG40������� */
#define	LCD_SEG_EN1_SEGEN40_Msk	(0x1U << LCD_SEG_EN1_SEGEN40_Pos)

#define	LCD_SEG_EN1_SEGEN39_Pos	7	/* SEG39������� */
#define	LCD_SEG_EN1_SEGEN39_Msk	(0x1U << LCD_SEG_EN1_SEGEN39_Pos)

#define	LCD_SEG_EN1_SEGEN38_Pos	6	/* SEG38������� */
#define	LCD_SEG_EN1_SEGEN38_Msk	(0x1U << LCD_SEG_EN1_SEGEN38_Pos)

#define	LCD_SEG_EN1_SEGEN37_Pos	5	/* SEG37������� */
#define	LCD_SEG_EN1_SEGEN37_Msk	(0x1U << LCD_SEG_EN1_SEGEN37_Pos)

#define	LCD_SEG_EN1_SEGEN36_Pos	4	/* SEG36������� */
#define	LCD_SEG_EN1_SEGEN36_Msk	(0x1U << LCD_SEG_EN1_SEGEN36_Pos)

#define	LCD_SEG_EN1_SEGEN35_Pos	3	/* SEG35������� */
#define	LCD_SEG_EN1_SEGEN35_Msk	(0x1U << LCD_SEG_EN1_SEGEN35_Pos)

#define	LCD_SEG_EN1_SEGEN34_Pos	2	/* SEG34������� */
#define	LCD_SEG_EN1_SEGEN34_Msk	(0x1U << LCD_SEG_EN1_SEGEN34_Pos)

#define	LCD_SEG_EN1_SEGEN33_Pos	1	/* SEG33������� */
#define	LCD_SEG_EN1_SEGEN33_Msk	(0x1U << LCD_SEG_EN1_SEGEN33_Pos)

#define	LCD_SEG_EN1_SEGEN32_Pos	0	/* SEG32������� */
#define	LCD_SEG_EN1_SEGEN32_Msk	(0x1U << LCD_SEG_EN1_SEGEN32_Pos)

#define	LCD_SEG_EN1_COMEN7_Pos	11	/* COM7����SEGEN43 */
#define	LCD_SEG_EN1_COMEN7_Msk	(0x1U << LCD_SEG_EN1_COMEN7_Pos)

#define	LCD_SEG_EN1_COMEN6_Pos	10	/* COM6����SEGEN42 */
#define	LCD_SEG_EN1_COMEN6_Msk	(0x1U << LCD_SEG_EN1_COMEN6_Pos)

#define	LCD_SEG_EN1_COMEN5_Pos	9	/* COM5����SEGEN41 */
#define	LCD_SEG_EN1_COMEN5_Msk	(0x1U << LCD_SEG_EN1_COMEN5_Pos)

#define	LCD_SEG_EN1_COMEN4_Pos	8	/* COM4����SEGEN40 */
#define	LCD_SEG_EN1_COMEN4_Msk	(0x1U << LCD_SEG_EN1_COMEN4_Pos)

//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void LCD_Deinit(void);

/* ��������ģʽ������Ƶ��
000��Ƶ��Ϊ֡Ƶ*COM��
001��Ƶ��ΪLSCLK/8
010��Ƶ��ΪLSCLK/16
011��Ƶ��ΪLSCLK/32
100��Ƶ��ΪLSCLK/64
101��Ƶ��ΪLSCLK/128
110��Ƶ��ΪLSCLK/256
111��Ƶ��ΪLSCLK/512��غ��� */
extern void LCD_CR_SCSEL_Set(uint32_t SetValue);
extern uint32_t LCD_CR_SCSEL_Get(void);

/* ��������ģʽ��������ʽ���� 
00����������
01����������2��
10����������4��
11��������� ��غ��� */
extern void LCD_CR_SC_CTRL_Set(uint32_t SetValue);
extern uint32_t LCD_CR_SC_CTRL_Get(void);

/* ƫ�õ�·�������Դ��С���� (Input bias Current Control)
00���������
01�������δ�
10��������С
11��������С ��غ��� */
extern void LCD_CR_IC_CTRL_Set(uint32_t SetValue);
extern uint32_t LCD_CR_IC_CTRL_Get(void);

/* ����ģʽѡ�� (LCD Enabling Mode)
0��RFU
1��Ƭ�ڵ��������� ��غ��� */
extern void LCD_CR_ENMODE_Set(uint32_t SetValue);
extern uint32_t LCD_CR_ENMODE_Get(void);

/* ��ʾ��˸ʹ��λ (LCD Flick Enable)
1����ʾ��˸����˸Ƶ����TON��TOFF�Ĵ�������
0���ر���˸ ��غ��� */
extern void LCD_CR_FLICK_Setable(FunState NewState);
extern FunState LCD_CR_FLICK_Getable(void);

/* LCDƫ�õ�ƽѡ��λ��������ʾ�Ҷȿ��� (LCD Bias Voltage Select) ��غ��� */
extern void LCD_CR_BIAS_Set(uint32_t SetValue);
extern uint32_t LCD_CR_BIAS_Get(void);

/* ƫ������ѡ�� (Bias Mode)
1��1/3 Bias
0��1/4 Bias ��غ��� */
extern void LCD_CR_BIASMD_Set(uint32_t SetValue);
extern uint32_t LCD_CR_BIASMD_Get(void);

/* ������ʹ�� (Anti-Polarization)
1��COM��SEG��LCD�ر�����½ӵ�
0��COM��SEG��LCD�ر�����¸��� ��غ��� */
extern void LCD_CR_ANTIPOLAR_Set(uint32_t SetValue);
extern uint32_t LCD_CR_ANTIPOLAR_Get(void);

/* ��������ѡ�� (Waveform Format)
1��B�ನ��
0��A�ನ�� ��غ��� */
extern void LCD_CR_WFT_Set(uint32_t SetValue);
extern uint32_t LCD_CR_WFT_Get(void);

/* COM����ѡ�� (Segment Line Mux)
00��4COM
01��6COM
10/11��8COM ��غ��� */
extern void LCD_CR_LMUX_Set(uint32_t SetValue);
extern uint32_t LCD_CR_LMUX_Get(void);

/* LCD��ʾʹ��λ (LCD Enable)
1������LCD��ʾ
0���ر�LCD��ʾ ��غ��� */
extern void LCD_CR_EN_Setable(FunState NewState);
extern FunState LCD_CR_EN_Getable(void);

/* LCD���Կ���λ�����ڲ���ģʽ����Ч (Line Constant Control)
COM��SEG�����ƽ�ɲ���ģʽ�µ�����������ݼĴ�����������ͬ������SEG��COM����Ľ���μ����ı�� ��غ��� */
extern void LCD_TEST_LCCTRL_Set(uint32_t SetValue);
extern uint32_t LCD_TEST_LCCTRL_Get(void);

/* ����ģʽʹ��λ (Test mode Enable)
1��LCD����ģʽʹ�ܡ���LCD����ģʽ�£�LCD���ž�̬���ģ��ֱ����ƽ�������붯̬ɨ��ʱ���Լ�ɨ�貨����ؼĴ���������Ч
0����������ģʽ������ģʽ��Ч����ز��ԼĴ���������Ч ��غ��� */
extern void LCD_TEST_TESTEN_Setable(FunState NewState);
extern FunState LCD_TEST_TESTEN_Getable(void);

/* ��ʾԤ��Ƶ�Ĵ��� (Display Frequency) ��غ��� */
extern void LCD_FCR_Write(uint32_t SetValue);
extern uint32_t LCD_FCR_Read(void);

/* ��˸��ʾϨ��ʱ��Ĵ��� (Display-Off Time)
TOFF��С����ΪTstep = COM*DF[7:0]*2*16/32768Hz��ʵ��OFFʱ��ΪTOFF * Tstep ��غ��� */
extern void LCD_FLKT_TOFF_Set(uint32_t SetValue);
extern uint32_t LCD_FLKT_TOFF_Get(void);

/* ��˸��ʾ����ʱ��Ĵ��� (Display-On Time)
TON��С����ΪTstep = COM*DF[7:0]*2*16/32768Hz��ʵ��ONʱ��ΪTON * Tstep ��غ��� */
extern void LCD_FLKT_TON_Set(uint32_t SetValue);
extern uint32_t LCD_FLKT_TON_Get(void);

/* ��ʾ�����ж�ʹ��λ (Display-On Interrupt Enable)
1����ʾ�����ж�ʹ��
0����ʾ�����жϽ�ֹ ��غ��� */
extern void LCD_IER_DONIE_Setable(FunState NewState);
extern FunState LCD_IER_DONIE_Getable(void);

/* ��ʾϨ���ж�ʹ��λ (Display-OFF Interrupt Enable)
1����ʾϨ���ж�ʹ��
0����ʾϨ���жϽ�ֹ ��غ��� */
extern void LCD_IER_DOFFIE_Setable(FunState NewState);
extern FunState LCD_IER_DOFFIE_Getable(void);

/* ��ʾ�����жϱ�־ (Display-On Interrupt Flag,write 1 to clear)
��ʾ�������ʱӲ�������жϱ�־��Ӳ����λ��������� ��غ��� */
extern void LCD_ISR_DONIF_Clr(void);
extern FlagStatus LCD_ISR_DONIF_Chk(void);

/* ��ʾϨ���жϱ�־ (Display-OFF Interrupt Flag,write 1 to clear)
��ʾ��������ʱӲ�������жϱ�־��Ӳ����λ��������� ��غ��� */
extern void LCD_ISR_DOFFIF_Clr(void);
extern FlagStatus LCD_ISR_DOFFIF_Chk(void);
extern void LCD_BSTCR_OSC_CFG_Set(uint32_t SetValue);
extern uint32_t LCD_BSTCR_OSC_CFG_Get(void);
extern void LCD_BSTCR_BUF_OFF_Setable(FunState NewState);
extern FunState LCD_BSTCR_BUF_OFF_Getable(void);
extern void LCD_BSTCR_BUFBYP_Setable(FunState NewState);
extern FunState LCD_BSTCR_BUFBYP_Getable(void);
extern void LCD_BSTCR_VLCDPD_Setable(FunState NewState);
extern FunState LCD_BSTCR_VLCDPD_Getable(void);
extern void LCD_BSTCR_VLCDCFG_Set(uint32_t SetValue);
extern uint32_t LCD_BSTCR_VLCDCFG_Get(void);
extern void LCD_BSTCR_BOOST_TEN_Setable(FunState NewState);
extern FunState LCD_BSTCR_BOOST_TEN_Getable(void);
extern void LCD_BSTCR_BOOST_EN_Setable(FunState NewState);
extern FunState LCD_BSTCR_BOOST_EN_Getable(void);

/* LCD COM0~3���ʹ�ܿ��� ��غ��� */
extern void LCD_COM_EN_Write(uint32_t SetValue);
extern uint32_t LCD_COM_EN_Read(void);

/* LCD SEG0~31���ʹ�ܿ��� ��غ��� */
extern void LCD_SEG_EN0_Write(uint32_t SetValue);
extern uint32_t LCD_SEG_EN0_Read(void);

/* LCD SEG32~43,COM4~7���ʹ�ܿ��� ��غ��� */
extern void LCD_SEG_EN1_Write(uint32_t SetValue);
extern uint32_t LCD_SEG_EN1_Read(void);
//Announce_End

/*DISPDATAx��ʾ���ݼĴ���ˢ��*/
extern void LCD_DISPDATAx_Refresh(uint32_t* DispBuf);

#ifdef __cplusplus
}
#endif

#endif /* __FM33A0XXEV_LCD_H */
