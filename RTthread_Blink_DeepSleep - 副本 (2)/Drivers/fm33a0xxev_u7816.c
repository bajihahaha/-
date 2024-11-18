/**
  ******************************************************************************
  * @file    fm33a0xxev_u7816.c
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/

#include "fm33a0xxev_u7816.h"

/** @addtogroup fm33a0xxev_StdPeriph_Driver
  * @{
  */

/** @defgroup U7816 
  * @brief U7816 driver modules
  * @{
  */ 

/* U7816ͨ������ʹ�ܿ���λ (Transmit Enable)1��ͨ������ʹ�ܣ��ɷ�������0��ͨ�����ͽ�ֹ�����ɷ������ݣ����ض�����˿ڣ���SCL�ź�ת��Ϊ�͵�ƽ ��غ��� */
void U7816_CR_TXEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		U7816->CR |= (U7816_CR_TXEN_Msk);
	}
	else
	{
		U7816->CR &= ~(U7816_CR_TXEN_Msk);
	}
}

FunState U7816_CR_TXEN_Getable(void)
{
	if (U7816->CR & (U7816_CR_TXEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* U7816ͨ������ʹ�ܿ���λ (Receive Enable)1��ͨ������ʹ�ܣ��ɽ�������0��ͨ�����ս�ֹ�����ɽ������ݣ����ض�����˿� ��غ��� */
void U7816_CR_RXEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		U7816->CR |= (U7816_CR_RXEN_Msk);
	}
	else
	{
		U7816->CR &= ~(U7816_CR_RXEN_Msk);
	}
}

FunState U7816_CR_RXEN_Getable(void)
{
	if (U7816->CR & (U7816_CR_RXEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* U7816ʱ��CLK���ʹ�ܿ���λ (Clock output Enable)1��7816ʱ�����ʹ��0��7816ʱ�������ֹ ��غ��� */
void U7816_CR_CKOEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		U7816->CR |= (U7816_CR_CKOEN_Msk);
	}
	else
	{
		U7816->CR &= ~(U7816_CR_CKOEN_Msk);
	}
}

FunState U7816_CR_CKOEN_Getable(void)
{
	if (U7816->CR & (U7816_CR_CKOEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* U7816ͨ�����ݷ���ǿ���������Զ���Ч����λ (High-Pullup Automatically)1�����ݷ���ʱ���������Զ���Ч������̬����������Ч0�����ݷ���ʱ���������Զ���Ч���ܽ�ֹ������������HPUEN��LPUEN���� ��غ��� */
void U7816_CR_HPUAT_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		U7816->CR |= (U7816_CR_HPUAT_Msk);
	}
	else
	{
		U7816->CR &= ~(U7816_CR_HPUAT_Msk);
	}
}

FunState U7816_CR_HPUAT_Getable(void)
{
	if (U7816->CR & (U7816_CR_HPUAT_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* U7816ͨ��ǿ����ʹ�ܿ���λ (High-Pullup Enable)1��ǿ������Ч0��ǿ������Ч ��غ��� */
void U7816_CR_HPUEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		U7816->CR |= (U7816_CR_HPUEN_Msk);
	}
	else
	{
		U7816->CR &= ~(U7816_CR_HPUEN_Msk);
	}
}

FunState U7816_CR_HPUEN_Getable(void)
{
	if (U7816->CR & (U7816_CR_HPUEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Guard Time���ͳ��ȿ���λ (Send long Frame Enable)1��Guard timeΪ3 etu0��Guard timeΪ2 etu ��غ��� */
void U7816_FFR_SFREN_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = U7816->FFR;
	tmpreg &= ~(U7816_FFR_SFREN_Msk);
	tmpreg |= (SetValue & U7816_FFR_SFREN_Msk);
	U7816->FFR = tmpreg;
}

uint32_t U7816_FFR_SFREN_Get(void)
{
	return (U7816->FFR & U7816_FFR_SFREN_Msk);
}

/* ERROR SIGNAL���ѡ�� (Error Signal Width)11��ERROR SIGNAL���Ϊ1ETU;10��ERROR SIGNAL���Ϊ1.5ETU;01��ERROR SIGNAL���Ϊ2ETU;00��ERROR SIGNAL���Ϊ2ETU; ��غ��� */
void U7816_FFR_ERSW_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = U7816->FFR;
	tmpreg &= ~(U7816_FFR_ERSW_Msk);
	tmpreg |= (SetValue & U7816_FFR_ERSW_Msk);
	U7816->FFR = tmpreg;
}

uint32_t U7816_FFR_ERSW_Get(void)
{
	return (U7816->FFR & U7816_FFR_ERSW_Msk);
}

/* ERROR SIGNAL��GUARDTIME���ѡ�񣨽��ڷ���ʱ��Ч��
(Error Signal Guard Time)1��ERROR SIGNAL��GUARDTIMEΪ1~1.5ETU��0��ERROR SIGNAL��GUARDTIMEΪ2~2.5ETU��ERROR SIGNAL���Ϊ����ETUʱGUARDTIMEΪ1.5��2.5ETU��ERROR SIGNAL���Ϊ1.5ETUʱGUARDTIMEΪ1��2ETU ��غ��� */
void U7816_FFR_ERSGD_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = U7816->FFR;
	tmpreg &= ~(U7816_FFR_ERSGD_Msk);
	tmpreg |= (SetValue & U7816_FFR_ERSGD_Msk);
	U7816->FFR = tmpreg;
}

uint32_t U7816_FFR_ERSGD_Get(void)
{
	return (U7816->FFR & U7816_FFR_ERSGD_Msk);
}

/* BGT����λ�����ƽ���->����֮���Ƿ����BGT��BGT�ǽ���->����֮����Ҫ����Сʱ�䣨block guard time enable��1��BGTʹ�ܣ�����Block guard time(12 etu);0��BGT��ֹ��������Block guard time(12 etu); ��غ��� */
void U7816_FFR_BGTEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		U7816->FFR |= (U7816_FFR_BGTEN_Msk);
	}
	else
	{
		U7816->FFR &= ~(U7816_FFR_BGTEN_Msk);
	}
}

FunState U7816_FFR_BGTEN_Getable(void)
{
	if (U7816->FFR & (U7816_FFR_BGTEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���ƽ���������żУ�����ʱ�Զ��ط����� (Repeated Times)1��3��0��1�� ��غ��� */
void U7816_FFR_REP_T_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = U7816->FFR;
	tmpreg &= ~(U7816_FFR_REP_T_Msk);
	tmpreg |= (SetValue & U7816_FFR_REP_T_Msk);
	U7816->FFR = tmpreg;
}

uint32_t U7816_FFR_REP_T_Get(void)
{
	return (U7816->FFR & U7816_FFR_REP_T_Msk);
}

/* ��żУ������ѡ�� (Parity)00��Even01��Odd10��Always 111����У�飬���� ��غ��� */
void U7816_FFR_PAR_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = U7816->FFR;
	tmpreg &= ~(U7816_FFR_PAR_Msk);
	tmpreg |= (SetValue & U7816_FFR_PAR_Msk);
	U7816->FFR = tmpreg;
}

uint32_t U7816_FFR_PAR_Get(void)
{
	return (U7816->FFR & U7816_FFR_PAR_Msk);
}

/* Guard Time���ճ��ȿ���λ (Receive short Frame )1��Guard timeΪ1 etu0��Guard timeΪ2 etu ��غ��� */
void U7816_FFR_RFREN_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = U7816->FFR;
	tmpreg &= ~(U7816_FFR_RFREN_Msk);
	tmpreg |= (SetValue & U7816_FFR_RFREN_Msk);
	U7816->FFR = tmpreg;
}

uint32_t U7816_FFR_RFREN_Get(void)
{
	return (U7816->FFR & U7816_FFR_RFREN_Msk);
}

/* ����������żУ���Ĵ���ʽѡ�� (Transmit Repeat Enable)1���յ���żУ������־��error signal��������T��0Э���Զ����лط����ڵ�һbyte�ظ����ʹ�������REP_T����tx_parity_err��־�������ж�0���յ�Error signalʱ�������Զ��ط�����tx_parity_err��־��ֱ���ж� ��غ��� */
void U7816_FFR_TREPEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		U7816->FFR |= (U7816_FFR_TREPEN_Msk);
	}
	else
	{
		U7816->FFR &= ~(U7816_FFR_TREPEN_Msk);
	}
}

FunState U7816_FFR_TREPEN_Getable(void)
{
	if (U7816->FFR & (U7816_FFR_TREPEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ����������żУ���Ĵ���ʽѡ�� (Receive Repeat Enable)1����żУ�������T=0Э���Զ��ط�ERROR SIGNAL����һBYTE�������մ�������REP_T����RX_PARITY_ERR��־�������ж�0����żУ������Զ�����ERROR SIGNAL����RX_PARITY_ERR��־�������ж� ��غ��� */
void U7816_FFR_RREPEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		U7816->FFR |= (U7816_FFR_RREPEN_Msk);
	}
	else
	{
		U7816->FFR &= ~(U7816_FFR_RREPEN_Msk);
	}
}

FunState U7816_FFR_RREPEN_Getable(void)
{
	if (U7816->FFR & (U7816_FFR_RREPEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ������򣬱��뷽ʽѡ�� (bit Direction Conversion)1��������룬���շ�MSB��(�շ�����+У��λ)���߼���ƽ0��������룬���շ�LSB �� (�շ�����+У��λ)���߼���ƽ ��غ��� */
void U7816_FFR_DICONV_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = U7816->FFR;
	tmpreg &= ~(U7816_FFR_DICONV_Msk);
	tmpreg |= (SetValue & U7816_FFR_DICONV_Msk);
	U7816->FFR = tmpreg;
}

uint32_t U7816_FFR_DICONV_Get(void)
{
	return (U7816->FFR & U7816_FFR_DICONV_Msk);
}

/* ����ʱ�����Extra Guard Timeʱ�䣨��ETUΪ��λ��
(Transmit Extra Guard Time) ��غ��� */
void U7816_EGTR_Write(uint32_t SetValue)
{
	U7816->EGTR = (SetValue & U7816_EGTR_TXEGT_Msk);
}

uint32_t U7816_EGTR_Read(void)
{
	return (U7816->EGTR & U7816_EGTR_TXEGT_Msk);
}

/* U7816ʱ�������Ƶ���ƼĴ���(Clock Divider)������7816����ʱ�ӷ�Ƶ����U7816����ʱ����APBCLK�ķ�Ƶ��ϵ��F7816=FAPBCLK/(CLKDIV+1)���������CLK_DIV���ó�0��1ʱ��F7816=FAPBCLK/2ע��7816Э��涨�Ĺ���ʱ�ӷ�Χ��1~5MHZ�� ��غ��� */
void U7816_PSC_Write(uint32_t SetValue)
{
	U7816->PSC = (SetValue & U7816_PSC_CLKDIV_Msk);
}

uint32_t U7816_PSC_Read(void)
{
	return (U7816->PSC & U7816_PSC_CLKDIV_Msk);
}

/* U7816Ԥ��Ƶ���ƼĴ���(Pre-Divider)������7816ͨ�ŷ�Ƶ�ȣ������ʣ�Baud �� F7816/(PDIV �� 1)

ע�⣺PDIV��С����ֵ��0x1��Ӧ�ý�ֹ����0x0 ��غ��� */
void U7816_BGR_Write(uint32_t SetValue)
{
	U7816->BGR = (SetValue & U7816_BGR_PDIV_Msk);
}

uint32_t U7816_BGR_Read(void)
{
	return (U7816->BGR & U7816_BGR_PDIV_Msk);
}

/* U7816���ݽ��ջ���Ĵ��� (Receive Buffer) ��غ��� */
uint32_t U7816_RXBUF_Read(void)
{
	return (U7816->RXBUF & U7816_RXBUF_RXBUF_Msk);
}

/* U7816���ݷ��ͻ���Ĵ��� (Transmit Buffer) ��غ��� */
void U7816_TXBUF_Write(uint32_t SetValue)
{
	U7816->TXBUF = (SetValue & U7816_TXBUF_TXBUF_Msk);
}

/* ���ݽ����ж�ʹ��λ����ӦRXIF�жϱ�־λ (Receive Interrupt Enable)1����RXIF�Ĵ�����λʱ������������ж�0����ֹ��������ж� ��غ��� */
void U7816_IER_RXIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		U7816->IER |= (U7816_IER_RXIE_Msk);
	}
	else
	{
		U7816->IER &= ~(U7816_IER_RXIE_Msk);
	}
}

FunState U7816_IER_RXIE_Getable(void)
{
	if (U7816->IER & (U7816_IER_RXIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���ݷ����ж�ʹ��λ����ӦTXIF�жϱ�־λ(Transmit Interrupt Enable)1����TXIF�Ĵ�����λʱ������������ж�0����ֹ��������ж� ��غ��� */
void U7816_IER_TXIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		U7816->IER |= (U7816_IER_TXIE_Msk);
	}
	else
	{
		U7816->IER &= ~(U7816_IER_TXIE_Msk);
	}
}

FunState U7816_IER_TXIE_Getable(void)
{
	if (U7816->IER & (U7816_IER_TXIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��·״̬�ж�ʹ��λ����ӦERRIF�жϱ�־λ(Line Status Interrupt Enable)1����ERRIF�Ĵ�����λʱ������·�����ж�0����ֹ��·�����ж� ��غ��� */
void U7816_IER_LSIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		U7816->IER |= (U7816_IER_LSIE_Msk);
	}
	else
	{
		U7816->IER &= ~(U7816_IER_LSIE_Msk);
	}
}

FunState U7816_IER_LSIE_Getable(void)
{
	if (U7816->IER & (U7816_IER_LSIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* U7816�ӿڷ����˴����źţ����ڵȴ��Է��ط����ݣ�(Waiting for Repeat flag)״̬�����뷢�ʹ����ź�״̬ʱ��λ���յ�������ʼλ���߽��뷢��״̬ʱӲ�����㣻���ֻ���� ��غ��� */
FlagStatus U7816_ISR_WAIT_RPT_Chk(void)
{
	if (U7816->ISR & U7816_ISR_WAIT_RPT_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��������æ��־����������ɺ��Զ����㣩(Transmission busy flag)1���������ݷ���״̬��������λ�Ĵ������ڷ������ݡ�����ʼ������ʼλ��1��ֹͣλ�м����㣩0�����ݷ��Ϳ��� ��غ��� */
FlagStatus U7816_ISR_TXBUSY_Chk(void)
{
	if (U7816->ISR & U7816_ISR_TXBUSY_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��������æ��־����������ɺ��Զ����㣩(Receiving busy flag)1���������ݽ���״̬��������λ�Ĵ������ڽ������ݡ����յ���ʼλ��1���յ�ֹͣλ���㣬���������ݳ������ط�����ط�error signalʱ���㡣�����ݼ�У��λ����֮�������Ƿ���Ҫ�ط�������Ҫ��ʱ����ñ�־��0�����ݽ��տ��� ��غ��� */
FlagStatus U7816_ISR_RXBUSY_Chk(void)
{
	if (U7816->ISR & U7816_ISR_RXBUSY_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ����������żУ������־λ��Ӳ����λ��д1���� (Transmit Parity Error,write 1 to clear) ��غ��� */
void U7816_ISR_TPARERR_Clr(void)
{
	U7816->ISR = U7816_ISR_TPARERR_Msk;
}

FlagStatus U7816_ISR_TPARERR_Chk(void)
{
	if (U7816->ISR & U7816_ISR_TPARERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ����������żУ������־λ��Ӳ����λ��д1���� (Receive Parity Error flag,write 1 to clear) ��غ��� */
void U7816_ISR_RPARERR_Clr(void)
{
	U7816->ISR = U7816_ISR_RPARERR_Msk;
}

FlagStatus U7816_ISR_RPARERR_Chk(void)
{
	if (U7816->ISR & U7816_ISR_RPARERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ����֡��ʽ�����־λ��Ӳ����λ��д1���� (Frame Error flag,write 1 to clear)1��֡��ʽ�д��󣬽��յ���frame�ֽڳ����������յ���frame����stopλ����0����������ʱ����żУ����� ��غ��� */
void U7816_ISR_FRERR_Clr(void)
{
	U7816->ISR = U7816_ISR_FRERR_Msk;
}

FlagStatus U7816_ISR_FRERR_Chk(void)
{
	if (U7816->ISR & U7816_ISR_FRERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ������������־λ��Ӳ����λ��д1���� (Receive Overflow Error,write 1 to clear)1�����ջ���Ĵ���δ���������ֽ��յ��µ����ݣ���������־��Ч��ԭ���ջ���Ĵ��������ݱ��¸���0����������� ��غ��� */
void U7816_ISR_OVERR_Clr(void)
{
	U7816->ISR = U7816_ISR_OVERR_Msk;
}

FlagStatus U7816_ISR_OVERR_Chk(void)
{
	if (U7816->ISR & U7816_ISR_OVERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ������ɱ�־(Receive interrupt flag)��U7816�ӿڿ�����ÿ�յ�1byte���ݣ����ݽ��յ�ͨ����Ӧ����һ���жϡ�Ӳ����λ�������ݽ��ջ���Ĵ�������1�����յ�1byte���ݣ����ݽ��ջ�������0��δ���յ����ݣ����ݽ��ջ������� ��غ��� */
FlagStatus U7816_ISR_RXIF_Chk(void)
{
	if (U7816->ISR & U7816_ISR_RXIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ���ͻ������ձ�־(Transmit interrupt flag)���ϵ縴λ��˱�־���Զ���λ����ʾ�������գ�����д�����ݡ����д�����ݺ��־�Զ���������ݴӷ��ͻ���������λ�Ĵ�������11�����ݷ��ͻ�������0�����ݷ��ͻ������������ݴ����� ��غ��� */
FlagStatus U7816_ISR_TXIF_Chk(void)
{
	if (U7816->ISR & U7816_ISR_TXIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* �����־(Error interrupt flag)���Ĵ������ó����������г�����bit��TPARERR��RPARERR��FRERR��OVERR�Ļ����ͨ��������ϴ����־�Ĵ����������bit�� ��غ��� */
FlagStatus U7816_ISR_ERRIF_Chk(void)
{
	if (U7816->ISR & U7816_ISR_ERRIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}


void U7816_Deinit(void)
{
	U7816->CR = 0x00000000;
	U7816->FFR = 0x00000006;
	//U7816->EGTR = 0x00000000;
	//U7816->PSC = 0x00000000;
	//U7816->BGR = 0x00000100;
	//U7816->RXBUF = 0x00000000;
	//U7816->TXBUF = 0x00000000;
	//U7816->IER = 0x00000000;
	//U7816->ISR = 0x00000002;
}


/* U7816����������ʼ������ */
/*******************************************
��������U7816_Init
��������: U7816����������ʼ������
���������U7816x��U78160��U78161
          para��U7816_InitTypeDef����
�������: ��
*******************************************/
void U7816_Init(U7816_InitTypeDef* para)
{
	
	U7816_CR_TXEN_Setable(para->TXEN);		//����ʹ��
	U7816_CR_RXEN_Setable(para->RXEN);		//����ʹ��
	U7816_CR_CKOEN_Setable(para->CKOEN);		//U7816ʱ��CLK���ʹ�ܿ���
	U7816_CR_HPUAT_Setable(para->HPUAT);		//U7816ͨ�����ݷ���ǿ���������Զ���Ч����
	U7816_CR_HPUEN_Setable(para->HPUEN);		//U7816ͨ��ǿ����ʹ�ܿ���
		
	U7816_FFR_ERSW_Set(para->ERSW);		//ERROR SIGNAL���ѡ��
	U7816_FFR_ERSGD_Set(para->ERSGD);		//ERROR SIGNAL��GUARDTIME���ѡ�񣨽��ڷ���ʱ��Ч��
	U7816_FFR_BGTEN_Setable(para->BGTEN);		//BGT��block guard time������
	U7816_FFR_REP_T_Set(para->REP_T);		//���ƽ���������żУ�����ʱ�Զ��ط�����
	U7816_FFR_PAR_Set(para->PAR);		//��żУ������ѡ��
	U7816_FFR_SFREN_Set(para->SFREN);		//Guard Time���ȿ���λ������ʱ�ϸ���Э��2etu�� 
  U7816_FFR_RFREN_Set(para->RFREN);   //����Guard Time���ȿ���λ
	U7816_FFR_TREPEN_Setable(para->TREPEN);		//������������żУ���Ĵ���ʽѡ��
	U7816_FFR_RREPEN_Setable(para->RREPEN);		//����������żУ���Ĵ���ʽѡ��
	U7816_FFR_DICONV_Set(para->DICONV);		//������������ʹ��
	
	U7816_EGTR_Write(para->TXEGT);		//����ʱ�����EGTʱ�䣨��ETUΪ��λ��
	U7816_PSC_Write(para->CLKDIV);		//U7816ʱ�������Ƶ���ƼĴ���
	U7816_BGR_Write(para->PDIV);		//U7816Ԥ��Ƶ���ƼĴ���������7816ͨ�ŷ�Ƶ�ȣ������ʣ�
	
	U7816_IER_RXIE_Setable(para->RXIE);		//���ݽ����ж�ʹ��λ����ӦRX_FLAG�жϱ�־λ
	U7816_IER_TXIE_Setable(para->TXIE);		//���ݷ����ж�ʹ��λ����ӦTX_FLAG�жϱ�־λ
	U7816_IER_LSIE_Setable(para->LSIE);		//��·״̬�ж�ʹ��λ����ӦERROR_FLAG�жϱ�־λ
	
}

/******END OF FILE****/
