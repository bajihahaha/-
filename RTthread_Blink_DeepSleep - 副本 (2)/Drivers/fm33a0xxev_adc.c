/**
  ******************************************************************************
  * @file    fm33a0xxev_adc.c
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/

#include "fm33a0xxev_adc.h"

/** @addtogroup fm33a0xxev_StdPeriph_Driver
  * @{
  */ 

/** @defgroup ADC 
  * @brief ADC driver modules
  * @{
  */ 

/* ADC�ڲ��ۼ�ģʽ�ж�ʹ�� ��غ��� */
void ADC_CR_ADC_IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ADC->CR |= (ADC_CR_ADC_IE_Msk);
	}
	else
	{
		ADC->CR &= ~(ADC_CR_ADC_IE_Msk);
	}
}

FunState ADC_CR_ADC_IE_Getable(void)
{
	if (ADC->CR & (ADC_CR_ADC_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ADC�ⲿ�ۼ�ģʽ�ж�ʹ�� ��غ��� */
void ADC_CR_ACC_IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ADC->CR |= (ADC_CR_ACC_IE_Msk);
	}
	else
	{
		ADC->CR &= ~(ADC_CR_ACC_IE_Msk);
	}
}

FunState ADC_CR_ACC_IE_Getable(void)
{
	if (ADC->CR & (ADC_CR_ACC_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ADC����ģʽ
0���͹���ģʽ������ʱ�����1MHz
1���߹���ģʽ������ʱ�����2MHz ��غ��� */
void ADC_CR_HPEN_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ADC->CR;
	tmpreg &= ~(ADC_CR_HPEN_Msk);
	tmpreg |= (SetValue & ADC_CR_HPEN_Msk);
	ADC->CR = tmpreg;
}

uint32_t ADC_CR_HPEN_Get(void)
{
	return (ADC->CR & ADC_CR_HPEN_Msk);
}

/* ADC����ģʽ
0���ڲ��ۼ���ģʽ
1���ⲿ�ۼ�����CICģʽ ��غ��� */
void ADC_CR_MODE_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ADC->CR;
	tmpreg &= ~(ADC_CR_MODE_Msk);
	tmpreg |= (SetValue & ADC_CR_MODE_Msk);
	ADC->CR = tmpreg;
}

uint32_t ADC_CR_MODE_Get(void)
{
	return (ADC->CR & ADC_CR_MODE_Msk);
}

/* ��������λʹ�ܣ���MODE=1����ʹ���ⲿ�ۼ���ʱ��������λ�����������±��뱣��Ϊ0
0����ֹ�������ⲿ��λ
1������������ⲿ��λ ��غ��� */
void ADC_CR_RSTCTRL_EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ADC->CR |= (ADC_CR_RSTCTRL_EN_Msk);
	}
	else
	{
		ADC->CR &= ~(ADC_CR_RSTCTRL_EN_Msk);
	}
}

FunState ADC_CR_RSTCTRL_EN_Getable(void)
{
	if (ADC->CR & (ADC_CR_RSTCTRL_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ADCʹ���ź�
0��ADC��ʹ��
1��ADCʹ��

ע�⣺RTCִ���Զ��²�ʱ��Ӳ�����������Զ�ʹ��ADC ��غ��� */
void ADC_CR_EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ADC->CR |= (ADC_CR_EN_Msk);
	}
	else
	{
		ADC->CR &= ~(ADC_CR_EN_Msk);
	}
}

FunState ADC_CR_EN_Getable(void)
{
	if (ADC->CR & (ADC_CR_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ADC TRIMֵ��������ڲ��ۼ���ģʽ���
�ڲ��ۼ����ۼ����ڣ�Period = TRIM*2*TADC_CLK
�ۼ����ھ������������λ����TRIM=0x7FF���ֵʱ��ʵ���ۼ�����Ϊ4095 cycle����ADC������������Чλ����12bit ��غ��� */
void ADC_TRIM_Write(uint32_t SetValue)
{
	ADC->TRIM  = (SetValue & ADC_TRIM_ADC_TRIM_Msk);
}

uint32_t ADC_TRIM_Read(void)
{
	return (ADC->TRIM  & ADC_TRIM_ADC_TRIM_Msk);
}

/* ADC������ݣ�Ϊ�����ۼӽ����δ���������˲�������
��MODE=0ʱ�����ΪADC�ڲ��ۼӽ�������12bit��λ����ADC_TRIM����
��MODE=1ʱ�����λADC�ⲿ�ۼӽ�������14bit��λ����ACC_PERIOD���� ��غ��� */
uint32_t ADC_DR_Read(void)
{
	return (ADC->DR & ADC_DR_ADC_DATA_Msk);
}

/* ADC��ʼ����ɱ�־����MODE=1ʱ��Ч���������жϣ�
0��ADC��δ��ɳ�ʼ��
1��ADC��ɳ�ʼ��

ע��MODE=1��ADC_EN��λ�󣬵ȴ�MODE_CTRL_DELAYʱ��֮�󣬴˱�־��λ����ʾADC�ڲ�������������ɡ�MODE=0ʱ������ʱ����ADC�ڲ����п��ƣ��˱�־��Ч�� ��غ��� */
FlagStatus ADC_ISR_INIT_RDY_Chk(void)
{
	if (ADC->ISR  & ADC_ISR_INIT_RDY_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* �ۼ�������жϱ�־��Ӳ����λ�����д1���㣬д0��Ч ��غ��� */
void ADC_ISR_ACC_IF_Clr(void)
{
	ADC->ISR  = ADC_ISR_ACC_IF_Msk;
}

FlagStatus ADC_ISR_ACC_IF_Chk(void)
{
	if (ADC->ISR  & ADC_ISR_ACC_IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ADCת�������������ֻ�����������жϣ�
ת����ɺ���źű���Ϊ�ߵ�ƽ��ֻ�йر�ADC�Ż���0 ��غ��� */
FlagStatus ADC_ISR_ADC_DONE_Chk(void)
{
	if (ADC->ISR  & ADC_ISR_ADC_DONE_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ADCת������жϱ�־��Ӳ����λ�����д1���㣬д0��Ч ��غ��� */
void ADC_ISR_ADC_IF_Clr(void)
{
	ADC->ISR  = ADC_ISR_ADC_IF_Msk;
}

FlagStatus ADC_ISR_ADC_IF_Chk(void)
{
	if (ADC->ISR  & ADC_ISR_ADC_IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* �ⲿ�ۼ����ۼ��������ã���λADC_CLK
000��1023����Ӧ���10bit��
001��2047����Ӧ���11bit��
010��4095����Ӧ���12bit��
011��8191����Ӧ���13bit��
100��16383����Ӧ���14bit��
Others��4095 ��غ��� */
void ADC_CFGR_ACC_PERIOD_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ADC->CFGR;
	tmpreg &= ~(ADC_CFGR_ACC_PERIOD_Msk);
	tmpreg |= (SetValue & ADC_CFGR_ACC_PERIOD_Msk);
	ADC->CFGR = tmpreg;
}

uint32_t ADC_CFGR_ACC_PERIOD_Get(void)
{
	return (ADC->CFGR & ADC_CFGR_ACC_PERIOD_Msk);
}

/* SDADCʹ�ܺ�mode_ctrl�ӳٳ������ã���λ��ADC_CLK����
0x00�����ӳ�
0xFF���ӳ�255��ADC_CLK

ע�⣺��λֵΪ16��ʱ�����ڣ������޸�ΪС��16����ֵ ��غ��� */
void ADC_CFGR_RST_CTRL_DELAY_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ADC->CFGR;
	tmpreg &= ~(ADC_CFGR_RST_CTRL_DELAY_Msk);
	tmpreg |= (SetValue & ADC_CFGR_RST_CTRL_DELAY_Msk);
	ADC->CFGR = tmpreg;
}

uint32_t ADC_CFGR_RST_CTRL_DELAY_Get(void)
{
	return (ADC->CFGR & ADC_CFGR_RST_CTRL_DELAY_Msk);
}

/* ADC����ͨ��Bufferʹ�� ��غ��� */
void ADC_CFGR_BUFEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ADC->CFGR |= (ADC_CFGR_BUFEN_Msk);
	}
	else
	{
		ADC->CFGR &= ~(ADC_CFGR_BUFEN_Msk);
	}
}

FunState ADC_CFGR_BUFEN_Getable(void)
{
	if (ADC->CFGR & (ADC_CFGR_BUFEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ADC����ͨ��ѡ��
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
1110��VBAT
1111��TS ��غ��� */
void ADC_CFGR_BUFSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ADC->CFGR;
	tmpreg &= ~(ADC_CFGR_BUFSEL_Msk);
	tmpreg |= (SetValue & ADC_CFGR_BUFSEL_Msk);
	ADC->CFGR = tmpreg;
}

uint32_t ADC_CFGR_BUFSEL_Get(void)
{
	return (ADC->CFGR & ADC_CFGR_BUFSEL_Msk);
}

/* CIC�˲���������ݣ�����Ƶ����ADC����ʱ�Ӻ�OSR��ͬ������ע������������з���������ʽΪ�����Ʋ��롣��غ��� */
uint32_t CIC_DR_Read(void)
{
	return (CIC->DR & CIC_DR_ADC_CIC_DATA_Msk);
}

/* CIC�˲���������� offset���ƼĴ��������д��offsetֵ��Ӳ����CIC_DR����OS����Եõ��޷��Ͻ������غ��� */
void CIC_OS_Write(uint32_t SetValue)
{
	CIC ->OS = (SetValue & CIC_OS_ADC_CIC_OS_Msk);
}

uint32_t CIC_OS_Read(void)
{
	return (CIC ->OS & CIC_OS_ADC_CIC_OS_Msk);
}

/* CIC_DR + CIC_OS�õ����޷�������� ��غ��� */
uint32_t CIC_USDR_Read(void)
{
	return (CIC ->USDR  & CIC_USDR_ADC_CIC_USDR_Msk);
}

/* CIC�˲���ʹ�� (CIC enable)
0:�ر�CIC
1:ʹ��CIC ��غ��� */
void CIC_CR_CIC_EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		CIC ->CR |= (CIC_CR_CIC_EN_Msk);
	}
	else
	{
		CIC ->CR &= ~(CIC_CR_CIC_EN_Msk);
	}
}

FunState CIC_CR_CIC_EN_Getable(void)
{
	if (CIC ->CR & (CIC_CR_CIC_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* CICʹ�ܺ������������ (Number of Samples to be Discarded)
���Զ���ADCʹ�ܺ�ͷ�����0~255��������
��غ��� */
void CIC_CR_NS_DISC_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = CIC->CR;
	tmpreg &= ~(CIC_CR_NS_DISC_Msk);
	tmpreg |= (SetValue & CIC_CR_NS_DISC_Msk);
	CIC ->CR = tmpreg;
}

uint32_t CIC_CR_NS_DISC_Get(void)
{
	return (CIC ->CR & CIC_CR_NS_DISC_Msk);
}

/* CIC Overrun Interrupt enable
0:��ֹCIC����ж�
1:����CIC����ж� ��غ��� */
void CIC_CR_OVR_IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		CIC ->CR |= (CIC_CR_OVR_IE_Msk);
	}
	else
	{
		CIC ->CR &= ~(CIC_CR_OVR_IE_Msk);
	}
}

FunState CIC_CR_OVR_IE_Getable(void)
{
	if (CIC ->CR & (CIC_CR_OVR_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* CIC�ж�ʹ��(CIC interrupt enable)
0:��ֹCIC�ж�
1:����CIC�ж�,��CIC_IF��λʱ�����ж��¼� ��غ��� */
void CIC_CR_CIC_IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		CIC ->CR |= (CIC_CR_CIC_IE_Msk);
	}
	else
	{
		CIC ->CR &= ~(CIC_CR_CIC_IE_Msk);
	}
}

FunState CIC_CR_CIC_IE_Getable(void)
{
	if (CIC ->CR & (CIC_CR_CIC_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ������ݽ�ȡ���� (Truncate),�������ս���ж������λ��λ��;
��غ��� */
void CIC_CR_TRUNC_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = CIC ->CR;
	tmpreg &= ~(CIC_CR_TRUNC_Msk);
	tmpreg |= (SetValue & CIC_CR_TRUNC_Msk);
	CIC ->CR = tmpreg;
}

uint32_t CIC_CR_TRUNC_Get(void)
{
	return (CIC ->CR & CIC_CR_TRUNC_Msk);
}

/* ������������ (Over Sampling Rate)
000:x8
001:x16
010:x32
011:x64
100:x128
101:x256
110:x512
111:x1024 ��غ��� */
void CIC_CR_OSR_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = CIC ->CR;
	tmpreg &= ~(CIC_CR_OSR_Msk);
	tmpreg |= (SetValue & CIC_CR_OSR_Msk);
	CIC ->CR = tmpreg;
}

uint32_t CIC_CR_OSR_Get(void)
{
	return (CIC ->CR & CIC_CR_OSR_Msk);
}

void CIC_ISR_CIC_OVR_Clr(void)
{
	CIC ->ISR = CIC_ISR_CIC_OVR_Msk;
}

FlagStatus CIC_ISR_CIC_OVR_Chk(void)
{
	if (CIC ->ISR & CIC_ISR_CIC_OVR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

void CIC_ISR_CIC_IF_Clr(void)
{
	CIC ->ISR = CIC_ISR_CIC_IF_Msk;
}

FlagStatus CIC_ISR_CIC_IF_Chk(void)
{
	if (CIC ->ISR & CIC_ISR_CIC_IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

void ADC_Deinit(void)
{
	//ADC->CR = 0x00000000;
	//ADC->TRIM  = 0x00000000;
	//ADC->DR = 0x00000000;
	//ADC->ISR  = 0x00000000;
	//ADC->CFGR = 0x00000000;
}

/******END OF FILE****/
