/**
  ******************************************************************************
  * @file    fm33a0xxev_lcd.c
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/

#include "fm33a0xxev_lcd.h"

/** @addtogroup fm33a0xxev_StdPeriph_Driver
  * @{
  */

/** @defgroup LCD 
  * @brief LCD driver modules
  * @{
  */ 

/* ��������ģʽ������Ƶ��
000��Ƶ��Ϊ֡Ƶ*COM��
001��Ƶ��ΪLSCLK/8
010��Ƶ��ΪLSCLK/16
011��Ƶ��ΪLSCLK/32
100��Ƶ��ΪLSCLK/64
101��Ƶ��ΪLSCLK/128
110��Ƶ��ΪLSCLK/256
111��Ƶ��ΪLSCLK/512��غ��� */
void LCD_CR_SCSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LCD->CR;
	tmpreg &= ~(LCD_CR_SCSEL_Msk);
	tmpreg |= (SetValue & LCD_CR_SCSEL_Msk);
	LCD->CR = tmpreg;
}

uint32_t LCD_CR_SCSEL_Get(void)
{
	return (LCD->CR & LCD_CR_SCSEL_Msk);
}

/* ��������ģʽ��������ʽ���� 
00����������
01����������2��
10����������4��
11��������� ��غ��� */
void LCD_CR_SC_CTRL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LCD->CR;
	tmpreg &= ~(LCD_CR_SC_CTRL_Msk);
	tmpreg |= (SetValue & LCD_CR_SC_CTRL_Msk);
	LCD->CR = tmpreg;
}

uint32_t LCD_CR_SC_CTRL_Get(void)
{
	return (LCD->CR & LCD_CR_SC_CTRL_Msk);
}

/* ƫ�õ�·�������Դ��С���� (Input bias Current Control)
00���������
01�������δ�
10��������С
11��������С ��غ��� */
void LCD_CR_IC_CTRL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LCD->CR;
	tmpreg &= ~(LCD_CR_IC_CTRL_Msk);
	tmpreg |= (SetValue & LCD_CR_IC_CTRL_Msk);
	LCD->CR = tmpreg;
}

uint32_t LCD_CR_IC_CTRL_Get(void)
{
	return (LCD->CR & LCD_CR_IC_CTRL_Msk);
}

/* ����ģʽѡ�� (LCD Enabling Mode)
0��RFU
1��Ƭ�ڵ��������� ��غ��� */
void LCD_CR_ENMODE_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LCD->CR;
	tmpreg &= ~(LCD_CR_ENMODE_Msk);
	tmpreg |= (SetValue & LCD_CR_ENMODE_Msk);
	LCD->CR = tmpreg;
}

uint32_t LCD_CR_ENMODE_Get(void)
{
	return (LCD->CR & LCD_CR_ENMODE_Msk);
}

/* ��ʾ��˸ʹ��λ (LCD Flick Enable)
1����ʾ��˸����˸Ƶ����TON��TOFF�Ĵ�������
0���ر���˸ ��غ��� */
void LCD_CR_FLICK_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LCD->CR |= (LCD_CR_FLICK_Msk);
	}
	else
	{
		LCD->CR &= ~(LCD_CR_FLICK_Msk);
	}
}

FunState LCD_CR_FLICK_Getable(void)
{
	if (LCD->CR & (LCD_CR_FLICK_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* LCDƫ�õ�ƽѡ��λ��������ʾ�Ҷȿ��� (LCD Bias Voltage Select) ��غ��� */
void LCD_CR_BIAS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LCD->CR;
	tmpreg &= ~(LCD_CR_BIAS_Msk);
	tmpreg |= ((SetValue<<LCD_CR_BIAS_Pos) & LCD_CR_BIAS_Msk);
	LCD->CR = tmpreg;
}

uint32_t LCD_CR_BIAS_Get(void)
{
	return ((LCD->CR & LCD_CR_BIAS_Msk)>>LCD_CR_BIAS_Pos);
}

/* ƫ������ѡ�� (Bias Mode)
1��1/3 Bias
0��1/4 Bias ��غ��� */
void LCD_CR_BIASMD_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LCD->CR;
	tmpreg &= ~(LCD_CR_BIASMD_Msk);
	tmpreg |= (SetValue & LCD_CR_BIASMD_Msk);
	LCD->CR = tmpreg;
}

uint32_t LCD_CR_BIASMD_Get(void)
{
	return (LCD->CR & LCD_CR_BIASMD_Msk);
}

/* ������ʹ�� (Anti-Polarization)
1��COM��SEG��LCD�ر�����½ӵ�
0��COM��SEG��LCD�ر�����¸��� ��غ��� */
void LCD_CR_ANTIPOLAR_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LCD->CR;
	tmpreg &= ~(LCD_CR_ANTIPOLAR_Msk);
	tmpreg |= (SetValue & LCD_CR_ANTIPOLAR_Msk);
	LCD->CR = tmpreg;
}

uint32_t LCD_CR_ANTIPOLAR_Get(void)
{
	return (LCD->CR & LCD_CR_ANTIPOLAR_Msk);
}

/* ��������ѡ�� (Waveform Format)
1��B�ನ��
0��A�ನ�� ��غ��� */
void LCD_CR_WFT_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LCD->CR;
	tmpreg &= ~(LCD_CR_WFT_Msk);
	tmpreg |= (SetValue & LCD_CR_WFT_Msk);
	LCD->CR = tmpreg;
}

uint32_t LCD_CR_WFT_Get(void)
{
	return (LCD->CR & LCD_CR_WFT_Msk);
}

/* COM����ѡ�� (Segment Line Mux)
00��4COM
01��6COM
10/11��8COM ��غ��� */
void LCD_CR_LMUX_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LCD->CR;
	tmpreg &= ~(LCD_CR_LMUX_Msk);
	tmpreg |= (SetValue & LCD_CR_LMUX_Msk);
	LCD->CR = tmpreg;
}

uint32_t LCD_CR_LMUX_Get(void)
{
	return (LCD->CR & LCD_CR_LMUX_Msk);
}

/* LCD��ʾʹ��λ (LCD Enable)
1������LCD��ʾ
0���ر�LCD��ʾ ��غ��� */
void LCD_CR_EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LCD->CR |= (LCD_CR_EN_Msk);
	}
	else
	{
		LCD->CR &= ~(LCD_CR_EN_Msk);
	}
}

FunState LCD_CR_EN_Getable(void)
{
	if (LCD->CR & (LCD_CR_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* LCD���Կ���λ�����ڲ���ģʽ����Ч (Line Constant Control)
COM��SEG�����ƽ�ɲ���ģʽ�µ�����������ݼĴ�����������ͬ������SEG��COM����Ľ���μ����ı�� ��غ��� */
void LCD_TEST_LCCTRL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LCD->TEST;
	tmpreg &= ~(LCD_TEST_LCCTRL_Msk);
	tmpreg |= (SetValue & LCD_TEST_LCCTRL_Msk);
	LCD->TEST = tmpreg;
}

uint32_t LCD_TEST_LCCTRL_Get(void)
{
	return (LCD->TEST & LCD_TEST_LCCTRL_Msk);
}

/* ����ģʽʹ��λ (Test mode Enable)
1��LCD����ģʽʹ�ܡ���LCD����ģʽ�£�LCD���ž�̬���ģ��ֱ����ƽ�������붯̬ɨ��ʱ���Լ�ɨ�貨����ؼĴ���������Ч
0����������ģʽ������ģʽ��Ч����ز��ԼĴ���������Ч ��غ��� */
void LCD_TEST_TESTEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LCD->TEST |= (LCD_TEST_TESTEN_Msk);
	}
	else
	{
		LCD->TEST &= ~(LCD_TEST_TESTEN_Msk);
	}
}

FunState LCD_TEST_TESTEN_Getable(void)
{
	if (LCD->TEST & (LCD_TEST_TESTEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��ʾԤ��Ƶ�Ĵ��� (Display Frequency) ��غ��� */
void LCD_FCR_Write(uint32_t SetValue)
{
	LCD->FCR = (SetValue & LCD_FCR_DF_Msk);
}

uint32_t LCD_FCR_Read(void)
{
	return (LCD->FCR & LCD_FCR_DF_Msk);
}

/* ��˸��ʾϨ��ʱ��Ĵ��� (Display-Off Time)
TOFF��С����ΪTstep = COM*DF[7:0]*2*16/32768Hz��ʵ��OFFʱ��ΪTOFF * Tstep ��غ��� */
void LCD_FLKT_TOFF_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LCD->FLKT;
	tmpreg &= ~(LCD_FLKT_TOFF_Msk);
	tmpreg |= (SetValue & LCD_FLKT_TOFF_Msk);
	LCD->FLKT = tmpreg;
}

uint32_t LCD_FLKT_TOFF_Get(void)
{
	return (LCD->FLKT & LCD_FLKT_TOFF_Msk);
}

/* ��˸��ʾ����ʱ��Ĵ��� (Display-On Time)
TON��С����ΪTstep = COM*DF[7:0]*2*16/32768Hz��ʵ��ONʱ��ΪTON * Tstep ��غ��� */
void LCD_FLKT_TON_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LCD->FLKT;
	tmpreg &= ~(LCD_FLKT_TON_Msk);
	tmpreg |= (SetValue & LCD_FLKT_TON_Msk);
	LCD->FLKT = tmpreg;
}

uint32_t LCD_FLKT_TON_Get(void)
{
	return (LCD->FLKT & LCD_FLKT_TON_Msk);
}

/* ��ʾ�����ж�ʹ��λ (Display-On Interrupt Enable)
1����ʾ�����ж�ʹ��
0����ʾ�����жϽ�ֹ ��غ��� */
void LCD_IER_DONIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LCD->IER |= (LCD_IER_DONIE_Msk);
	}
	else
	{
		LCD->IER &= ~(LCD_IER_DONIE_Msk);
	}
}

FunState LCD_IER_DONIE_Getable(void)
{
	if (LCD->IER & (LCD_IER_DONIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��ʾϨ���ж�ʹ��λ (Display-OFF Interrupt Enable)
1����ʾϨ���ж�ʹ��
0����ʾϨ���жϽ�ֹ ��غ��� */
void LCD_IER_DOFFIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LCD->IER |= (LCD_IER_DOFFIE_Msk);
	}
	else
	{
		LCD->IER &= ~(LCD_IER_DOFFIE_Msk);
	}
}

FunState LCD_IER_DOFFIE_Getable(void)
{
	if (LCD->IER & (LCD_IER_DOFFIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��ʾ�����жϱ�־ (Display-On Interrupt Flag,write 1 to clear)
��ʾ�������ʱӲ�������жϱ�־��Ӳ����λ��������� ��غ��� */
void LCD_ISR_DONIF_Clr(void)
{
	LCD->ISR = LCD_ISR_DONIF_Msk;
}

FlagStatus LCD_ISR_DONIF_Chk(void)
{
	if (LCD->ISR & LCD_ISR_DONIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��ʾϨ���жϱ�־ (Display-OFF Interrupt Flag,write 1 to clear)
��ʾ��������ʱӲ�������жϱ�־��Ӳ����λ��������� ��غ��� */
void LCD_ISR_DOFFIF_Clr(void)
{
	LCD->ISR = LCD_ISR_DOFFIF_Msk;
}

FlagStatus LCD_ISR_DOFFIF_Chk(void)
{
	if (LCD->ISR & LCD_ISR_DOFFIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

void LCD_BSTCR_OSC_CFG_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LCD->BSTCR;
	tmpreg &= ~(LCD_BSTCR_OSC_CFG_Msk);
	tmpreg |= (SetValue & LCD_BSTCR_OSC_CFG_Msk);
	LCD->BSTCR = tmpreg;
}

uint32_t LCD_BSTCR_OSC_CFG_Get(void)
{
	return (LCD->BSTCR & LCD_BSTCR_OSC_CFG_Msk);
}

void LCD_BSTCR_BUF_OFF_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LCD->BSTCR |= (LCD_BSTCR_BUF_OFF_Msk);
	}
	else
	{
		 LCD->BSTCR &= ~(LCD_BSTCR_BUF_OFF_Msk);		
	}
}

FunState LCD_BSTCR_BUF_OFF_Getable(void)
{
	if (LCD->BSTCR & (LCD_BSTCR_BUF_OFF_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

void LCD_BSTCR_BUFBYP_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LCD->BSTCR |= (LCD_BSTCR_BUFBYP_Msk);
	}
	else
	{
		LCD->BSTCR &= ~(LCD_BSTCR_BUFBYP_Msk);
	}
}

FunState LCD_BSTCR_BUFBYP_Getable(void)
{
	if (LCD->BSTCR & (LCD_BSTCR_BUFBYP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

void LCD_BSTCR_VLCDPD_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LCD->BSTCR |= (LCD_BSTCR_VLCDPD_Msk);
	}
	else
	{
		LCD->BSTCR &= ~(LCD_BSTCR_VLCDPD_Msk);
	}
}

FunState LCD_BSTCR_VLCDPD_Getable(void)
{
	if (LCD->BSTCR & (LCD_BSTCR_VLCDPD_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

void LCD_BSTCR_VLCDCFG_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LCD->BSTCR;
	tmpreg &= ~(LCD_BSTCR_VLCDCFG_Msk);
	tmpreg |= (SetValue & LCD_BSTCR_VLCDCFG_Msk);
	LCD->BSTCR = tmpreg;
}

uint32_t LCD_BSTCR_VLCDCFG_Get(void)
{
	return (LCD->BSTCR & LCD_BSTCR_VLCDCFG_Msk);
}

void LCD_BSTCR_BOOST_TEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LCD->BSTCR |= (LCD_BSTCR_BOOST_TEN_Msk);
	}
	else
	{
		LCD->BSTCR &= ~(LCD_BSTCR_BOOST_TEN_Msk);
	}
}

FunState LCD_BSTCR_BOOST_TEN_Getable(void)
{
	if (LCD->BSTCR & (LCD_BSTCR_BOOST_TEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

void LCD_BSTCR_BOOST_EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LCD->BSTCR |= (LCD_BSTCR_BOOST_EN_Msk);
	}
	else
	{
		LCD->BSTCR &= ~(LCD_BSTCR_BOOST_EN_Msk);
	}
}

FunState LCD_BSTCR_BOOST_EN_Getable(void)
{
	if (LCD->BSTCR & (LCD_BSTCR_BOOST_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}


/*********************************
LCD ��ʾ���ƺ��� 
���ܣ�����LCD COM0~3���ʹ�ܿ���
����: 00-0F COM0-COM3
���: ��
*********************************/
void LCD_COM_EN_Write(uint32_t SetValue)
{
	LCD->COMEN = (SetValue & LCD_COM_EN_COMEN_Msk);
}
/*********************************
LCD ��ʾ���ƺ��� 
���ܣ���ȡLCD COM0~3���ʹ��״̬
����: ��
���: 00-0F COM0-COM3
*********************************/
uint32_t LCD_COM_EN_Read(void)
{
	return (LCD->COMEN & LCD_COM_EN_COMEN_Msk);
}


/*********************************
LCD ��ʾ���ƺ��� 
���ܣ�����LCD SEG0-31���ʹ�ܿ���
����: 00000000-ffffffff	SEG0-SEG31
���: ��
*********************************/
void LCD_SEG_EN0_Write(uint32_t SetValue)
{
	LCD->SEGEN0 = (SetValue);
}
/*********************************
LCD ��ʾ���ƺ��� 
���ܣ���ȡLCD SEG0-31���ʹ��״̬
����: ��
���: 00000000-ffffffff	SEG0-SEG31
*********************************/
uint32_t LCD_SEG_EN0_Read(void)
{
	return (LCD->SEGEN0);
}

/*********************************
LCD ��ʾ���ƺ��� 
���ܣ�����LCD SEG32~43(COM4-7)���ʹ�ܿ���
����: 00000000-00000fff	SEG32~43(COM4-7)
���: ��
*********************************/
void LCD_SEG_EN1_Write(uint32_t SetValue)
{
	LCD->SEGEN1 = (SetValue & LCD_SEG_EN1_SEGENx_Msk);
}
/*********************************
LCD ��ʾ���ƺ��� 
���ܣ���ȡLCD SEG32~43(COM4-7)���ʹ��״̬
����: ��
���: 00000000-00000fff	SEG32~43(COM4-7)
*********************************/
uint32_t LCD_SEG_EN1_Read(void)
{
	return (LCD->SEGEN1 & LCD_SEG_EN1_SEGENx_Msk);
}

/*DISPDATAx��ʾ���ݼĴ���ˢ��*/
void LCD_DISPDATAx_Refresh(uint32_t* DispBuf)
{
    LCD->DATA0 = DispBuf[0];
    LCD->DATA1 = DispBuf[1];
    LCD->DATA2 = DispBuf[2];
    LCD->DATA3 = DispBuf[3];
    LCD->DATA4 = DispBuf[4];
    LCD->DATA5 = DispBuf[5];
    LCD->DATA6 = DispBuf[6];
    LCD->DATA7 = DispBuf[7];
    LCD->DATA8 = DispBuf[8];
    LCD->DATA9 = DispBuf[9];
}

void LCD_Deinit(void)
{
	//LCD->CR = 0x00010e00;
	//LCD->TEST = 0x00000000;
	//LCD->FCR = 0x00000000;
	//LCD->FLKT = 0x00000000;
	//LCD->IER = 0x00000000;
	//LCD->ISR = 0x00000000;
	//LCD->BSTCR = 0x00000000;
}

/******END OF FILE****/
