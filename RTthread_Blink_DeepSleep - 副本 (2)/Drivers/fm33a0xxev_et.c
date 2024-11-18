/**
  ******************************************************************************
  * @file    fm33a0xxev_et.c
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/

#include "fm33a0xxev_et.h"

/** @addtogroup fm33a0xxev_StdPeriph_Driver
  * @{
  */

/** @defgroup ET 
  * @brief ET driver modules
  * @{
  */ 

/* �������ѡ�� (Output Polarity)
0�������ȡ��
1�����ȡ�� ��غ��� */
void ETx_CR_OPOL_Set(ET_Type* ETx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ETx->CR ;
	tmpreg &= ~(ETx_CR_OPOL_Msk);
	tmpreg |= (SetValue & ETx_CR_OPOL_Msk);
	ETx->CR  = tmpreg;
}

uint32_t ETx_CR_OPOL_Get(ET_Type* ETx)
{
	return (ETx->CR  & ETx_CR_OPOL_Msk);
}

/* �ⲿ�������������˲�ʹ��
1 = �����������ź������˲�
0 = �ر����������ź������˲� ��غ��� */
void ETx_CR_EXFLT_Set(ET_Type* ETx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ETx->CR ;
	tmpreg &= ~(ETx_CR_EXFLT_Msk);
	tmpreg |= (SetValue & ETx_CR_EXFLT_Msk);
	ETx->CR  = tmpreg;
}

uint32_t ETx_CR_EXFLT_Get(ET_Type* ETx)
{
	return (ETx->CR  & ETx_CR_EXFLT_Msk);
}

/* PWM�������
1 = PWM���ʹ��
0 = PWM�����ֹ ��غ��� */
void ETx_CR_PWM_Setable(ET_Type* ETx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		ETx->CR  |= (ETx_CR_PWM_Msk);
	}
	else
	{
		ETx->CR  &= ~(ETx_CR_PWM_Msk);
	}
}

FunState ETx_CR_PWM_Getable(ET_Type* ETx)
{
	if (ETx->CR  & (ETx_CR_PWM_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��������
1 = ������ʱ�����ڼ�����ģʽ������ʱ��������ֵ�������������͹����Ĵ������ڲ�׽ģʽ�£�����ʱ���������㿪ʼ���ɼ�����������0xFFFF���������ź�Ȼ�����㿪ʼ���¼���
0 = ֹͣ���������� ��غ��� */
void ETx_CR_CEN_Setable(ET_Type* ETx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		ETx->CR  |= (ETx_CR_CEN_Msk);
	}
	else
	{
		ETx->CR  &= ~(ETx_CR_CEN_Msk);
	}
}

FunState ETx_CR_CEN_Getable(ET_Type* ETx)
{
	if (ETx->CR  & (ETx_CR_CEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ����ģʽѡ��
1 = ��׽ģʽ
0 = ��ʱ/����ģʽ ��غ��� */
void ETx_CR_MOD_Set(ET_Type* ETx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ETx->CR ;
	tmpreg &= ~(ETx_CR_MOD_Msk);
	tmpreg |= (SetValue & ETx_CR_MOD_Msk);
	ETx->CR  = tmpreg;
}

uint32_t ETx_CR_MOD_Get(ET_Type* ETx)
{
	return (ETx->CR  & ETx_CR_MOD_Msk);
}

/* Cascade Enable����չ��ʱ������ʹ��
1 = ET1��ET3����ET2��ET4��������32bit��ʱ��
0 = 16bit��ʱ���������� ��غ��� */
void ETx_CR_CASEN_Set(ET_Type* ETx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ETx->CR ;
	tmpreg &= ~(ETx_CR_CASEN_Msk);
	tmpreg |= (SetValue & ETx_CR_CASEN_Msk);
	ETx->CR  = tmpreg;
}

uint32_t ETx_CR_CASEN_Get(ET_Type* ETx)
{
	return (ETx->CR  & ETx_CR_CASEN_Msk);
}

/* ����ģʽ���ط�ʽѡ��
������ʱ��ѡ��mcu_clkʱ��λ��Ч�����ǲ���mcu_clkʱ�������ؼ�����
1 = ����ģʽ���½���
0 = ����ģʽ�������� ��غ��� */
void ETx_CR_EDGESEL_Set(ET_Type* ETx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ETx->CR ;
	tmpreg &= ~(ETx_CR_EDGESEL_Msk);
	tmpreg |= (SetValue & ETx_CR_EDGESEL_Msk);
	ETx->CR  = tmpreg;
}

uint32_t ETx_CR_EDGESEL_Get(ET_Type* ETx)
{
	return (ETx->CR  & ETx_CR_EDGESEL_Msk);
}

/* ��׽ģʽ����
1 = ����׽
0 = �������ڲ�׽ ��غ��� */
void ETx_CR_CAPMOD_Set(ET_Type* ETx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ETx->CR ;
	tmpreg &= ~(ETx_CR_CAPMOD_Msk);
	tmpreg |= (SetValue & ETx_CR_CAPMOD_Msk);
	ETx->CR  = tmpreg;
}

uint32_t ETx_CR_CAPMOD_Get(ET_Type* ETx)
{
	return (ETx->CR  & ETx_CR_CAPMOD_Msk);
}

/* �����㲶׽ģʽ����
1 = �¼�������׽��ʹ�ܺ����������0����׽����һ����Ч��֮��timer�ſ�ʼ����
0 = ��׽�����㣬������һֱ���ɼ��� ��غ��� */
void ETx_CR_CAPCLR_Setable(ET_Type* ETx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		ETx->CR  |= (ETx_CR_CAPCLR_Msk);
	}
	else
	{
		ETx->CR  &= ~(ETx_CR_CAPCLR_Msk);
	}
}

FunState ETx_CR_CAPCLR_Getable(ET_Type* ETx)
{
	if (ETx->CR  & (ETx_CR_CAPCLR_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���β�׽����
1 = ���β�׽��Ч���ڲ�׽��һ���������ں������ֹͣ������Ҫ�ٴβ�׽����������
0 = ������׽ ��غ��� */
void ETx_CR_CAPONCE_Set(ET_Type* ETx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ETx->CR ;
	tmpreg &= ~(ETx_CR_CAPONCE_Msk);
	tmpreg |= (SetValue & ETx_CR_CAPONCE_Msk);
	ETx->CR  = tmpreg;
}

uint32_t ETx_CR_CAPONCE_Get(ET_Type* ETx)
{
	return (ETx->CR  & ETx_CR_CAPONCE_Msk);
}

/* ��׽��ѡ��
1 = ���ڲ�׽ģʽʱ���ز�׽
0 = ���ڲ�׽ģʽʱ���ز�׽ ��غ��� */
void ETx_CR_CAPEDGE_Set(ET_Type* ETx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ETx->CR ;
	tmpreg &= ~(ETx_CR_CAPEDGE_Msk);
	tmpreg |= (SetValue & ETx_CR_CAPEDGE_Msk);
	ETx->CR  = tmpreg;
}

uint32_t ETx_CR_CAPEDGE_Get(ET_Type* ETx)
{
	return (ETx->CR  & ETx_CR_CAPEDGE_Msk);
}

/* �ڲ��ź�2Դѡ��(��׽Դ)
1 = ��չ��ʱ��3���ڲ��ź�2ѡ��Group1
0 = ��չ��ʱ��3���ڲ��ź�2ѡ��Group2 ��غ��� */
void ETx_INSR_SIG2SEL_Set(ET_Type* ETx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ETx->INSR ;
	tmpreg &= ~(ETx_INSR_SIG2SEL_Msk);
	tmpreg |= (SetValue & ETx_INSR_SIG2SEL_Msk);
	ETx->INSR  = tmpreg;
}

uint32_t ETx_INSR_SIG2SEL_Get(ET_Type* ETx)
{
	return (ETx->INSR  & ETx_INSR_SIG2SEL_Msk);
}

/* �ڲ��ź�1Դѡ���ڼ���ģʽ�¼���Դ���ɴ�ѡ�񣬲�׽ģʽ�¼���Դ��
1 = ��չ��ʱ��3���ڲ��ź�1ѡ��Group2
0 = ��չ��ʱ��3���ڲ��ź�1ѡ��Group1 ��غ��� */
void ETx_INSR_SIG1SEL_Set(ET_Type* ETx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ETx->INSR ;
	tmpreg &= ~(ETx_INSR_SIG1SEL_Msk);
	tmpreg |= (SetValue & ETx_INSR_SIG1SEL_Msk);
	ETx->INSR  = tmpreg;
}

uint32_t ETx_INSR_SIG1SEL_Get(ET_Type* ETx)
{
	return (ETx->INSR  & ETx_INSR_SIG1SEL_Msk);
}

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
void ETx_INSR_GRP2SEL_Set(ET_Type* ETx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ETx->INSR ;
	tmpreg &= ~(ETx_INSR_GRP2SEL_Msk);
	tmpreg |= (SetValue & ETx_INSR_GRP2SEL_Msk);
	ETx->INSR  = tmpreg;
}

uint32_t ETx_INSR_GRP2SEL_Get(ET_Type* ETx)
{
	return (ETx->INSR  & ETx_INSR_GRP2SEL_Msk);
}

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
void ETx_INSR_GRP1SEL_Set(ET_Type* ETx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ETx->INSR ;
	tmpreg &= ~(ETx_INSR_GRP1SEL_Msk);
	tmpreg |= (SetValue & ETx_INSR_GRP1SEL_Msk);
	ETx->INSR  = tmpreg;
}

uint32_t ETx_INSR_GRP1SEL_Get(ET_Type* ETx)
{
	return (ETx->INSR  & ETx_INSR_GRP1SEL_Msk);
}

/* ����Signal1������Դ����Ԥ��Ƶ�Ĵ���
00��ʾ1��Ƶ��FF��ʾ256��Ƶ ��غ��� */
void ETx_PSCR1_Write(ET_Type* ETx, uint32_t SetValue)
{
	ETx->PSCR1  = (SetValue & ETx_PSCR1_PRESCALE1_Msk);
}

uint32_t ETx_PSCR1_Read(ET_Type* ETx)
{
	return (ETx->PSCR1  & ETx_PSCR1_PRESCALE1_Msk);
}

/* ����Signal2����׽Դ����Ԥ��Ƶ�Ĵ���
00��ʾ1��Ƶ��FF��ʾ256��Ƶ�� ��غ��� */
void ETx_PSCR2_Write(ET_Type* ETx, uint32_t SetValue)
{
	ETx->PSCR2  = (SetValue & ETx_PSCR2_PRESCALE2_Msk);
}

uint32_t ETx_PSCR2_Read(ET_Type* ETx)
{
	return (ETx->PSCR2  & ETx_PSCR2_PRESCALE2_Msk);
}

/* ��չ��ʱ����ֵ�Ĵ��� ��غ��� */
void ETx_IVR_Write(ET_Type* ETx, uint32_t SetValue)
{
	ETx->IVR  = (SetValue & ETx_IVR_INITVALUE_Msk);
}

uint32_t ETx_IVR_Read(ET_Type* ETx)
{
	return (ETx->IVR  & ETx_IVR_INITVALUE_Msk);
}

/* ��չ��ʱ���ȽϼĴ���
�üĴ�����������Ƚϣ�������ֵ���ڵ��ڸüĴ�����ֵ�����������ƥ���ź����������ģ�飬��������Ӧ�жϡ� ��غ��� */
void ETx_CMPR_Write(ET_Type* ETx, uint32_t SetValue)
{
	ETx->CMPR  = (SetValue & ETx_CMPR_CMP_Msk);
}

uint32_t ETx_CMPR_Read(ET_Type* ETx)
{
	return (ETx->CMPR  & ETx_CMPR_CMP_Msk);
}

/* ��չ��ʱ���Ƚ��ж�ʹ��
1 = ʹ��
0 = ��ֹ ��غ��� */
void ETx_IER_CMPIE_Setable(ET_Type* ETx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		ETx->IER  |= (ETx_IER_CMPIE_Msk);
	}
	else
	{
		ETx->IER  &= ~(ETx_IER_CMPIE_Msk);
	}
}

FunState ETx_IER_CMPIE_Getable(ET_Type* ETx)
{
	if (ETx->IER  & (ETx_IER_CMPIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��չ��ʱ����׽�ж�ʹ��
1 = ʹ��
0 = ��ֹ ��غ��� */
void ETx_IER_CAPIE_Setable(ET_Type* ETx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		ETx->IER  |= (ETx_IER_CAPIE_Msk);
	}
	else
	{
		ETx->IER  &= ~(ETx_IER_CAPIE_Msk);
	}
}

FunState ETx_IER_CAPIE_Getable(ET_Type* ETx)
{
	if (ETx->IER  & (ETx_IER_CAPIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��չ��ʱ��3����ж�ʹ��
1 = ʹ��
0 = ��ֹ ��غ��� */
void ETx_IER_OVIE_Setable(ET_Type* ETx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		ETx->IER  |= (ETx_IER_OVIE_Msk);
	}
	else
	{
		ETx->IER  &= ~(ETx_IER_OVIE_Msk);
	}
}

FunState ETx_IER_OVIE_Getable(ET_Type* ETx)
{
	if (ETx->IER  & (ETx_IER_OVIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �Ƚ�״̬��д1��0
1 =��ǰ��������ֵ���ڵ��ڱȽϼĴ�����ֵ
0 =��ǰ��������ֵС�ڱȽϼĴ�����ֵ ��غ��� */
void ETx_ISR_CMPIF_Clr(ET_Type* ETx)
{
	ETx->ISR  = ETx_ISR_CMPIF_Msk;
}

FlagStatus ETx_ISR_CMPIF_Chk(ET_Type* ETx)
{
	if (ETx->ISR  & ETx_ISR_CMPIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��׽��״̬��־
1 = ��׽������
0 = ��׽������ */ 
FlagStatus ETx_ISR_EDGESTA_Chk(ET_Type* ETx)
{
    if (ETx->ISR  & ETx_ISR_EDGESTA_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��չ��ʱ����׽�����ź�
1 = ��׽��ָ������
0 = δ��׽��ָ������ ��غ��� */
void ETx_ISR_CAPIF_Clr(ET_Type* ETx)
{
	ETx->ISR  = ETx_ISR_CAPIF_Msk;
}

FlagStatus ETx_ISR_CAPIF_Chk(ET_Type* ETx)
{
	if (ETx->ISR  & ETx_ISR_CAPIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��չ��ʱ��3����źţ�����������ֵ��0xFFFF������ʱ����λ
1 = �����������
0 = δ������� ��غ��� */
void ETx_ISR_OVIF_Clr(ET_Type* ETx)
{
	ETx->ISR  = ETx_ISR_OVIF_Msk;
}

FlagStatus ETx_ISR_OVIF_Chk(ET_Type* ETx)
{
	if (ETx->ISR  & ETx_ISR_OVIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/*********************************
��ȡET ��������ֵ����
���ܣ���ȡET ��������ֵ
����: ET1/ET2/ET3/ET4  	��ʱ������
���: 00-FFFF
      ����Ϊ��Чֵ
*********************************/
uint32_t ETxCNT_CNTx_Read(ETCNT_Type* ETIMx)
{
    volatile uint8_t tmp08;
    uint32_t tmp32;
    tmp08 = ((uint32_t)ETIMx - ET1_BASE)>>5;	//��ȡETIM
    switch(tmp08)
    {
        case 0:
            tmp32 = (ETCNT->CNT1 & ETCNTx_CNT_Msk);
        break;
        case 1:
            tmp32 = (ETCNT->CNT2 & ETCNTx_CNT_Msk);
        break;
        case 2:
            tmp32 = (ETCNT->CNT3 & ETCNTx_CNT_Msk);
        break;
        case 3:
            tmp32 = (ETCNT->CNT4 & ETCNTx_CNT_Msk);
        break;
        default:
            tmp32 = 0x1fffffff;
        break;
    }
    return tmp32;
}

void ETx_Deinit(ET_Type* ETx)
{
	ETx->CR  = 0x00000000;
	ETx->INSR  = 0x00000000;
	ETx->PSCR1  = 0x00000000;
	ETx->PSCR2  = 0x00000000;
	ETx->IVR  = 0x00000000;
	ETx->CMPR  = 0x00000000;
	ETx->IER  = 0x00000000;
	ETx->ISR  = 0x00000000;
}

/******END OF FILE****/
