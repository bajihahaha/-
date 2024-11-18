/**
  ******************************************************************************
  * @file    fm33a0xxev_uart.c
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/

#include "fm33a0xxev_uart.h"
#include "fm33a0xxev_cmu.h"
/** @addtogroup fm33a0xxev_StdPeriph_Driver
  * @{
  */

/** @defgroup UART 
  * @brief UART driver modules
  * @{
  */ 

/* ���ƺ�����Ʒ�������ʱ��Ĭ��������� (Infra Red Flag)
0��������
1�������� ��غ��� */
void UARTIR_CR_IRFLAG_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = UARTIR->CR;
	tmpreg &= ~(UARTIR_CR_IRFLAG_Msk);
	tmpreg |= (SetValue & UARTIR_CR_IRFLAG_Msk);
	UARTIR->CR = tmpreg;
}

uint32_t UARTIR_CR_IRFLAG_Get(void)
{
	return (UARTIR->CR & UARTIR_CR_IRFLAG_Msk);
}

/* ����ռ�ձȵ��Ʋ��� (Tranmission High Duty) ��غ��� */
void UARTIR_CR_TH_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = UARTIR->CR;
	tmpreg &= ~(UARTIR_CR_TH_Msk);
	tmpreg |= (SetValue & UARTIR_CR_TH_Msk);
	UARTIR->CR = tmpreg;
}

uint32_t UARTIR_CR_TH_Get(void)
{
	return (UARTIR->CR & UARTIR_CR_TH_Msk);
}

/* �������Ƶ�� (Transmission Baud Rate) ��غ��� */
void UARTIR_CR_TZBRG_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = UARTIR->CR;
	tmpreg &= ~(UARTIR_CR_TZBRG_Msk);
	tmpreg |= (SetValue & UARTIR_CR_TZBRG_Msk);
	UARTIR->CR = tmpreg;
}

uint32_t UARTIR_CR_TZBRG_Get(void)
{
	return (UARTIR->CR & UARTIR_CR_TZBRG_Msk);
}

/* UARTͨ�ű�־��ֻ��
1��UART����ͨ����
0��UART���� ��غ��� */
FlagStatus UARTx_CSR_BUSY_Chk(UART_Type* UARTx)
{
	if (UARTx->CSR & UARTx_CSR_BUSY_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ���ͺ������ʹ��
1��ʹ�ܺ�����Ʒ���
0���رպ�����Ʒ��� ��غ��� */
void UARTx_CSR_TXIREN_Setable(UART_Type* UARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		UARTx->CSR |= (UARTx_CSR_TXIREN_Msk);
	}
	else
	{
		UARTx->CSR &= ~(UARTx_CSR_TXIREN_Msk);
	}
}

FunState UARTx_CSR_TXIREN_Getable(UART_Type* UARTx)
{
	if (UARTx->CSR & (UARTx_CSR_TXIREN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���ճ�ʱʹ��
1��ʹ�ܽ��ճ�ʱ����
0���رս��ճ�ʱ���� ��غ��� */
void UARTx_CSR_RXTOEN_Setable(UART_Type* UARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		UARTx->CSR |= (UARTx_CSR_RXTOEN_Msk);
	}
	else
	{
		UARTx->CSR &= ~(UARTx_CSR_RXTOEN_Msk);
	}
}

FunState UARTx_CSR_RXTOEN_Getable(UART_Type* UARTx)
{
	if (UARTx->CSR & (UARTx_CSR_RXTOEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* RX��TX���Ž���
0��Ĭ������˳�����װͼһ�£�
1����������˳�� ��غ��� */
void UARTx_CSR_IOSWAP_Set(UART_Type* UARTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = UARTx->CSR;
	tmpreg &= ~(UARTx_CSR_IOSWAP_Msk);
	tmpreg |= (SetValue & UARTx_CSR_IOSWAP_Msk);
	UARTx->CSR = tmpreg;
}

uint32_t UARTx_CSR_IOSWAP_Get(UART_Type* UARTx)
{
	return (UARTx->CSR & UARTx_CSR_IOSWAP_Msk);
}

/* DMA��������ж�ʹ�ܣ�����UARTͨ��DMA���з���ʱ��Ч
1��IE=1������£�DMAģʽ�·��������һ֡�������ж��ź���������һ֮֡ǰ������֡������ɺ������ж��ź����
0���Ƿ������ж��ź��������IE���� ��غ��� */
void UARTx_CSR_DMATXIFCFG_Setable(UART_Type* UARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		UARTx->CSR |= (UARTx_CSR_DMATXIFCFG_Msk);
	}
	else
	{
		UARTx->CSR &= ~(UARTx_CSR_DMATXIFCFG_Msk);
	}
}

FunState UARTx_CSR_DMATXIFCFG_Getable(UART_Type* UARTx)
{
	if (UARTx->CSR & (UARTx_CSR_DMATXIFCFG_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���ݷ���/����ʱ��λ˳��
0��LSB first
1��MSB first ��غ��� */
void UARTx_CSR_BITORD_Set(UART_Type* UARTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = UARTx->CSR;
	tmpreg &= ~(UARTx_CSR_BITORD_Msk);
	tmpreg |= (SetValue & UARTx_CSR_BITORD_Msk);
	UARTx->CSR = tmpreg;
}

uint32_t UARTx_CSR_BITORD_Get(UART_Type* UARTx)
{
	return (UARTx->CSR & UARTx_CSR_BITORD_Msk);
}

/* ֹͣλ������ã����Է���֡��ʽ��Ч������ʱ���ж�ֹͣλ����
0��1λֹͣλ
1��2λֹͣλ ��غ��� */
void UARTx_CSR_STOPCFG_Set(UART_Type* UARTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = UARTx->CSR;
	tmpreg &= ~(UARTx_CSR_STOPCFG_Msk);
	tmpreg |= (SetValue & UARTx_CSR_STOPCFG_Msk);
	UARTx->CSR = tmpreg;
}

uint32_t UARTx_CSR_STOPCFG_Get(UART_Type* UARTx)
{
	return (UARTx->CSR & UARTx_CSR_STOPCFG_Msk);
}

/* ÿ֡�����ݳ���ѡ�񣻴˼Ĵ��������ݷ��ͺͽ���ͬʱ��Ч
00��7λ����
01��8λ����
10��9λ����
11��6λ���� ��غ��� */
void UARTx_CSR_PDSEL_Set(UART_Type* UARTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = UARTx->CSR;
	tmpreg &= ~(UARTx_CSR_PDSEL_Msk);
	tmpreg |= (SetValue & UARTx_CSR_PDSEL_Msk);
	UARTx->CSR = tmpreg;
}

uint32_t UARTx_CSR_PDSEL_Get(UART_Type* UARTx)
{
	return (UARTx->CSR & UARTx_CSR_PDSEL_Msk);
}

/* У��λ���ã��˼Ĵ��������ݷ��ͺͽ���ͬʱ��Ч
00����У��λ
01��żУ��
10����У��
11��RFU ��غ��� */
void UARTx_CSR_PARITY_Set(UART_Type* UARTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = UARTx->CSR;
	tmpreg &= ~(UARTx_CSR_PARITY_Msk);
	tmpreg |= (SetValue & UARTx_CSR_PARITY_Msk);
	UARTx->CSR = tmpreg;
}

uint32_t UARTx_CSR_PARITY_Get(UART_Type* UARTx)
{
	return (UARTx->CSR & UARTx_CSR_PARITY_Msk);
}

/* �������ݼ�������
0������
1��ȡ�� ��غ��� */
void UARTx_CSR_RXPOL_Setable(UART_Type* UARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
    UARTx->CSR  |= (UARTx_CSR_RXPOL_Msk);
	}
	else
	{
		UARTx->CSR  &= ~(UARTx_CSR_RXPOL_Msk);
	}
}

FunState UARTx_CSR_RXPOL_Getable(UART_Type* UARTx)
{
	if (UARTx->CSR  & (UARTx_CSR_RXPOL_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �������ݼ�������
0������
1��ȡ�� ��غ��� */
void UARTx_CSR_TXPOL_Setable(UART_Type* UARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
    UARTx->CSR  |= (UARTx_CSR_TXPOL_Msk);
	}
	else
	{
		UARTx->CSR  &= ~(UARTx_CSR_TXPOL_Msk);
	}
}

FunState UARTx_CSR_TXPOL_Getable(UART_Type* UARTx)
{
	if (UARTx->CSR  & (UARTx_CSR_TXPOL_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ����ʹ�ܣ�1��Ч ��غ��� */
void UARTx_CSR_RXEN_Setable(UART_Type* UARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
    UARTx->CSR  |= (UARTx_CSR_RXEN_Msk);
	}
	else
	{
		UARTx->CSR  &= ~(UARTx_CSR_RXEN_Msk);
	}
}

FunState UARTx_CSR_RXEN_Getable(UART_Type* UARTx)
{
	if (UARTx->CSR  & (UARTx_CSR_RXEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ����ʹ�ܣ�1��Ч ��غ��� */
void UARTx_CSR_TXEN_Setable(UART_Type* UARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
    UARTx->CSR  |= (UARTx_CSR_TXEN_Msk);
	}
	else
	{
		UARTx->CSR  &= ~(UARTx_CSR_TXEN_Msk);
	}
}

FunState UARTx_CSR_TXEN_Getable(UART_Type* UARTx)
{
	if (UARTx->CSR  & (UARTx_CSR_TXEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���ճ�ʱ�ж�ʹ�ܣ�1��Ч
����UART0��UART1��Ч�� ��غ��� */
void UARTx_IER_RXTO_IE_Setable(UART_Type* UARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
    UARTx->IER  |= (UARTx_IER_RXTO_IE_Msk);
	}
	else
	{
		UARTx->IER  &= ~(UARTx_IER_RXTO_IE_Msk);
	}
}

FunState UARTx_IER_RXTO_IE_Getable(UART_Type* UARTx)
{
	if (UARTx->IER  & (UARTx_IER_RXTO_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���մ����ж�ʹ�ܣ�1��Ч ��غ��� */
void UARTx_IER_RXERR_IE_Setable(UART_Type* UARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
    UARTx->IER  |= (UARTx_IER_RXERR_IE_Msk);
	}
	else
	{
		UARTx->IER  &= ~(UARTx_IER_RXERR_IE_Msk);
	}
}

FunState UARTx_IER_RXERR_IE_Getable(UART_Type* UARTx)
{
	if (UARTx->IER  & (UARTx_IER_RXERR_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���ջ������ж�ʹ�ܣ�1��Ч ��غ��� */
void UARTx_IER_RXBF_IE_Setable(UART_Type* UARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
    UARTx->IER  |= (UARTx_IER_RXBF_IE_Msk);
	}
	else
	{
		UARTx->IER  &= ~(UARTx_IER_RXBF_IE_Msk);
	}
}

FunState UARTx_IER_RXBF_IE_Getable(UART_Type* UARTx)
{
	if (UARTx->IER  & (UARTx_IER_RXBF_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���ͻ�����ж�ʹ�ܣ�1��Ч ��غ��� */
void UARTx_IER_TXBE_IE_Setable(UART_Type* UARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
    UARTx->IER  |= (UARTx_IER_TXBE_IE_Msk);
	}
	else
	{
		UARTx->IER  &= ~(UARTx_IER_TXBE_IE_Msk);
	}
}

FunState UARTx_IER_TXBE_IE_Getable(UART_Type* UARTx)
{
	if (UARTx->IER  & (UARTx_IER_TXBE_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���ͻ�����ҷ�����λ�Ĵ������ж�ʹ�ܣ�1��Ч ��غ��� */
void UARTx_IER_TXSE_IE_Setable(UART_Type* UARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
    UARTx->IER  |= (UARTx_IER_TXSE_IE_Msk);
	}
	else
	{
		UARTx->IER  &= ~(UARTx_IER_TXSE_IE_Msk);
	}
}

FunState UARTx_IER_TXSE_IE_Getable(UART_Type* UARTx)
{
	if (UARTx->IER  & (UARTx_IER_TXSE_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��żУ������жϱ�־��Ӳ����λ�����д1���� ��غ��� */
void UARTx_ISR_PERR_Clr(UART_Type* UARTx)
{
	UARTx->ISR  = UARTx_ISR_PERR_Msk;
}

FlagStatus UARTx_ISR_PERR_Chk(UART_Type* UARTx)
{
	if (UARTx->ISR  & UARTx_ISR_PERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ֡��ʽ�����жϱ�־��Ӳ����λ�����д1���� ��غ��� */
void UARTx_ISR_FERR_Clr(UART_Type* UARTx)
{
	UARTx->ISR  = UARTx_ISR_FERR_Msk;
}

FlagStatus UARTx_ISR_FERR_Chk(UART_Type* UARTx)
{
	if (UARTx->ISR  & UARTx_ISR_FERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ���ջ�����������жϱ�־�������ջ�����������£��յ��µ�����ʱ��λ��Ӳ����λ�����д1���߶�ȡRXBUFʱ����
�������ʱ�����ջ�������ԭ�е����ݱ������ݸ��ǡ� ��غ��� */
void UARTx_ISR_OERR_Clr(UART_Type* UARTx)
{
	UARTx->ISR  = UARTx_ISR_OERR_Msk;
}

FlagStatus UARTx_ISR_OERR_Chk(UART_Type* UARTx)
{
	if (UARTx->ISR  & UARTx_ISR_OERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ���ճ�ʱ�жϱ�־��Ӳ����λ�����д1����
����UART0��UART1��Ч�� ��غ��� */
void UARTx_ISR_RXTO_Clr(UART_Type* UARTx)
{
	UARTx->ISR  = UARTx_ISR_RXTO_Msk;
}

FlagStatus UARTx_ISR_RXTO_Chk(UART_Type* UARTx)
{
	if (UARTx->ISR  & UARTx_ISR_RXTO_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ���ջ������жϱ�־��Ӳ����λ�����д1���߶�ȡRXBUFʱ���� ��غ��� */
void UARTx_ISR_RXBF_Clr(UART_Type* UARTx)
{
	UARTx->ISR  = UARTx_ISR_RXBF_Msk;
}

FlagStatus UARTx_ISR_RXBF_Chk(UART_Type* UARTx)
{
	if (UARTx->ISR  & UARTx_ISR_RXBF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}


FlagStatus UARTx_ISR_TXBE_Chk(UART_Type* UARTx)
{
	if (UARTx->ISR  & UARTx_ISR_TXBE_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ���ͻ��������λ�Ĵ�����������жϱ�־��Ӳ����λ�����д1�������д���ͻ���ʱ���� ��غ��� */
void UARTx_ISR_TXSE_Clr(UART_Type* UARTx)
{
	UARTx->ISR  = UARTx_ISR_TXSE_Msk;
}

FlagStatus UARTx_ISR_TXSE_Chk(UART_Type* UARTx)
{
	if (UARTx->ISR  & UARTx_ISR_TXSE_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* �����ӳ٣����255baud ��غ��� */
void UARTx_TODR_TXDLY_LEN_Set(UART_Type* UARTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = UARTx->TODR ;
	tmpreg &= ~(UARTx_TODR_TXDLY_LEN_Msk);
	tmpreg |= (SetValue & UARTx_TODR_TXDLY_LEN_Msk);
	UARTx->TODR  = tmpreg;
}

uint32_t UARTx_TODR_TXDLY_LEN_Get(UART_Type* UARTx)
{
	return (UARTx->TODR  & UARTx_TODR_TXDLY_LEN_Msk);
}

/* ���ճ�ʱ������ȣ����255baud ��غ��� */
void UARTx_TODR_RXTO_LEN_Set(UART_Type* UARTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = UARTx->TODR ;
	tmpreg &= ~(UARTx_TODR_RXTO_LEN_Msk);
	tmpreg |= (SetValue & UARTx_TODR_RXTO_LEN_Msk);
	UARTx->TODR  = tmpreg;
}

uint32_t UARTx_TODR_RXTO_LEN_Get(UART_Type* UARTx)
{
	return (UARTx->TODR  & UARTx_TODR_RXTO_LEN_Msk);
}

/* �������ݻ���Ĵ������� ��غ��� */
uint32_t UARTx_RXBUF_Read(UART_Type* UARTx)
{
	return (UARTx->RXBUF  & UARTx_RXBUF_RXBUF_Msk);
}

/* �������ݻ���Ĵ������� ��غ��� */
void UARTx_TXBUF_Write(UART_Type* UARTx, uint32_t SetValue)
{
	UARTx->TXBUF  = (SetValue & UARTx_TXBUF_TXBUF_Msk);
}

uint32_t UARTx_TXBUF_Read(UART_Type* UARTx)
{
	return (UARTx->TXBUF  & UARTx_TXBUF_TXBUF_Msk);
}

/* �����ʲ������Ĵ���ֵ ��غ��� */
void UARTx_BGR_Write(UART_Type* UARTx, uint32_t SetValue)
{
	UARTx->BGR  = (SetValue & UARTx_BRG_SPBRG_Msk);
}

uint32_t UARTx_BGR_Read(UART_Type* UARTx)
{
	return (UARTx->BGR  & UARTx_BRG_SPBRG_Msk);
}

/*
�������Ƶ��ռ�ձ����ú���
����:�������Ƶ��ռ�ձ����ú���
���룺�������Ƶ��ռ�ձ�����
*/
void UART_IRModulation_Init( uint32_t ModuFreq, uint8_t ModuDutyCycle, uint32_t Clk )
{
	uint32_t tempTZBRG, tempTH;
	
	if((ModuFreq > 0)&&(Clk >= ModuFreq)&&(ModuDutyCycle < 100))
	{
		tempTZBRG = (uint32_t)((float)Clk/(float)ModuFreq + 0.5) - 1;
		UARTIR_CR_TZBRG_Set((tempTZBRG&UARTIR_CR_TZBRG_Msk)<<UARTIR_CR_TZBRG_Pos);//�������Ƶ������
		
		if((tempTZBRG>>4) != 0)
		{
			
			tempTH = (uint32_t)(((float)ModuDutyCycle/100.0)*((float)(tempTZBRG + 1)/(float)(tempTZBRG>>4)) + 0.5);
		}
		else
		{
			tempTH = (uint32_t)(((float)ModuDutyCycle/100.0)*(float)(tempTZBRG + 1) + 0.5);
			
		}
		UARTIR_CR_TH_Set((tempTH<<UARTIR_CR_TH_Pos)&UARTIR_CR_TH_Msk);//�������ռ�ձ�����
	}
}

/*
UART����������ʼ������
����:UART����������ʼ��
���룺���ں� ����
*/
void UART_Init(UART_Type* UARTx, UART_InitTypeDef* para)
{
	UARTx_BGR_Write(UARTx, para->SPBRG);		//�����ʲ������Ĵ���
	UARTx_CSR_PDSEL_Set(UARTx, para->PDSEL);		// ���ݳ���ѡ��
	UARTx_CSR_PARITY_Set(UARTx, para->PARITY);		// У��λ����	
	UARTx_CSR_STOPCFG_Set(UARTx, para->STOPSEL);	//ֹͣλѡ��	
	UARTx_IER_RXERR_IE_Setable(UARTx, para->ERRIE);		//�����ж�ʹ�ܿ���
  UARTx_IER_RXTO_IE_Setable(UARTx, para->RXTO_IE);		//���ճ�ʱ�ж�
	UARTx_IER_RXBF_IE_Setable(UARTx, para->RXBF_IE);		//�����ж�
	UARTx_IER_TXBE_IE_Setable(UARTx, para->TXBE_IE);		//�����ж�
	UARTx_IER_TXSE_IE_Setable(UARTx, para->TXSE_IE);		//�����ж�	
	UARTx_CSR_RXPOL_Setable(UARTx, para->RXDFLAG);	//��������ȡ������λ
	UARTx_CSR_TXPOL_Setable(UARTx, para->TXDFLAG);	//��������ȡ������λ
	UARTx_CSR_RXEN_Setable(UARTx, para->RXEN);		//����ģ��ʹ�ܿ���
	UARTx_CSR_TXEN_Setable(UARTx, para->TXEN);		//����ģ��ʹ�ܿ���
	UARTx_CSR_TXIREN_Setable(UARTx, para->IREN);		//���ͺ������ʹ��λ
}

/*
д�벨���ʲ������Ĵ�������
����:д�벨����
����:Ҫ���õĲ�����
*/
uint32_t UART_BaudREGCalc(uint32_t BaudRate, uint32_t Clk)
{
	uint32_t tmpSPBRG;
	float tmpfloat;
	
	tmpfloat = (float)Clk/(float)BaudRate;
	
	if(tmpfloat > 1)
	{
		tmpSPBRG = (uint32_t)(tmpfloat - 1.0 + 0.5);
	}
	else
	{
		tmpSPBRG = 0;
	}
	
	return tmpSPBRG;
}

/*
UART�򵥲�����ʼ����������
����:UART�򵥲�����ʼ��
���룺���ں� ����
*/
void UART_SInit(UART_Type* UARTx, UART_SInitTypeDef* para,CMU_ClocksType* CMU_Clocks)
{
	UART_InitTypeDef para2 ;

	if(UARTx == UART0)
	{
		CMU_OPCCR1_UART0CKS_Set(para->ClockSrc);				//UART0����ʱ��ѡ��	
		CMU_OPCCR1_UART0CKE_Setable(ENABLE);            //UART0����ʱ��ʹ�� 
		CMU_PERCLK_SetableEx(UART0CLK,ENABLE);  					//UART0����ʱ��ʹ��
		switch(para->ClockSrc)
		{
				case CMU_OPCCR1_UART0CKS_APBCLK:
						para2.SPBRG = UART_BaudREGCalc(para->BaudRate, CMU_Clocks->APBCLK_Frequency);
						break;    
				case CMU_OPCCR1_UART0CKS_RCHF:
						CMU_RCHFCR_RCHFEN_Setable(ENABLE);
						para2.SPBRG = UART_BaudREGCalc(para->BaudRate, CMU_Clocks->RCHF_Frequency);
						break;
				case CMU_OPCCR1_UART0CKS_SYSCLK:
						para2.SPBRG = UART_BaudREGCalc(para->BaudRate, CMU_Clocks->SYSCLK_Frequency);
						break;
			  default:
			      break;
		}
	}
	else if(UARTx == UART1)
	{
	  CMU_OPCCR1_UART1CKS_Set(para->ClockSrc);				//UART1����ʱ��ѡ��	
		CMU_OPCCR1_UART1CKE_Setable(ENABLE);            //UART1����ʱ��ʹ�� 
		CMU_PERCLK_SetableEx(UART1CLK,ENABLE);  					//UART1����ʱ��ʹ��
		switch(para->ClockSrc)
		{
				case CMU_OPCCR1_UART1CKS_APBCLK:
						para2.SPBRG = UART_BaudREGCalc(para->BaudRate, CMU_Clocks->APBCLK_Frequency);
						break;    
				case CMU_OPCCR1_UART1CKS_RCHF:
						CMU_RCHFCR_RCHFEN_Setable(ENABLE);					
						para2.SPBRG = UART_BaudREGCalc(para->BaudRate, CMU_Clocks->RCHF_Frequency);
						break;
				case CMU_OPCCR1_UART1CKS_SYSCLK:
						para2.SPBRG = UART_BaudREGCalc(para->BaudRate, CMU_Clocks->SYSCLK_Frequency);
						break;
			  default:
			      break;
		}	
	}
  else if(UARTx == UART2)
	{
		CMU_PERCLK_SetableEx(UART2CLK,ENABLE);  					//UART2����ʱ��ʹ��
		para2.SPBRG = UART_BaudREGCalc(para->BaudRate, CMU_Clocks->APBCLK_Frequency);
	}
  else if(UARTx == UART3)
	{
		CMU_PERCLK_SetableEx(UART3CLK,ENABLE);  					//UART3����ʱ��ʹ��
		para2.SPBRG = UART_BaudREGCalc(para->BaudRate, CMU_Clocks->APBCLK_Frequency);
	}
	else if(UARTx == UART4)
	{
		CMU_PERCLK_SetableEx(UART4CLK,ENABLE);  					//UART4����ʱ��ʹ��
		para2.SPBRG = UART_BaudREGCalc(para->BaudRate, CMU_Clocks->APBCLK_Frequency);
	}
	else if(UARTx == UART5)
	{
		CMU_PERCLK_SetableEx(UART5CLK,ENABLE);  					//UART5����ʱ��ʹ��
		para2.SPBRG = UART_BaudREGCalc(para->BaudRate, CMU_Clocks->APBCLK_Frequency);
	}
		
	if(Eight8Bit == para->DataBit)
	{
		  para2.PDSEL = UARTx_CSR_PDSEL_8BIT;
			if(EVEN == para->ParityBit)
			{
				para2.PARITY= UARTx_CSR_PARITY_EVEN;//8bitżУ��
			}
			else if(ODD == para->ParityBit)
			{
				para2.PARITY = UARTx_CSR_PARITY_ODD;//8bit��У��
			}
			else
			{
				para2.PARITY = UARTx_CSR_PARITY_NONE;//8bit������У��
			}
	}
	else if(Nine9Bit == para->DataBit)
	{
		  para2.PDSEL = UARTx_CSR_PDSEL_9BIT;
			if(EVEN == para->ParityBit)
			{
				para2.PARITY = UARTx_CSR_PARITY_EVEN;//9bitżУ��
			}
			else if(ODD == para->ParityBit)
			{
				para2.PARITY = UARTx_CSR_PARITY_ODD;//9bit��У��
			}
			else
			{
				para2.PARITY = UARTx_CSR_PARITY_NONE;//9bit������У��
			}
	}
		else if(Seven7Bit == para->DataBit)
	{
		  para2.PDSEL = UARTx_CSR_PDSEL_7BIT;
			if(EVEN == para->ParityBit)
			{
				para2.PARITY = UARTx_CSR_PARITY_EVEN;//7bitżУ��
			}
			else if(ODD == para->ParityBit)
			{
				para2.PARITY = UARTx_CSR_PARITY_ODD;//7bit��У��
			}
			else
			{
				para2.PARITY = UARTx_CSR_PARITY_NONE;//7bit������У��
			}
	}
	else
	{
		  para2.PDSEL = UARTx_CSR_PDSEL_6BIT;
			if(EVEN == para->ParityBit)
			{
				para2.PARITY = UARTx_CSR_PARITY_EVEN;//6bitżУ��
			}
			else if(ODD == para->ParityBit)
			{
				para2.PARITY = UARTx_CSR_PARITY_ODD;//6bit��У��
			}
			else
			{
				para2.PARITY = UARTx_CSR_PARITY_NONE;//6bit������У��
			}

	}
	
	if(OneBit == para->StopBit)
	{
		para2.STOPSEL = UARTx_CSR_STOPCFG_1STOPBIT;
	}
	else
	{
		para2.STOPSEL = UARTx_CSR_STOPCFG_2STOPBIT;
	}
	
	para2.RXBF_IE = DISABLE;		//�رս����ж�
	para2.TXBE_IE = DISABLE;		//�رշ����ж�
	para2.TXSE_IE = DISABLE;		//�رշ����ж�
	para2.ERRIE = DISABLE;		//�رմ����ж�
  para2.RXTO_IE = DISABLE;		//���ճ�ʱ�ж�
  
	para2.RXDFLAG = DISABLE;	//�رս�������ȡ������λ
	para2.TXDFLAG = DISABLE;	//�رշ�������ȡ������λ

	para2.RXEN = DISABLE;		//�رս���ģ��ʹ�ܿ���
	para2.TXEN = DISABLE;		//�رշ���ģ��ʹ�ܿ���
	para2.IREN = DISABLE;		//�رշ��ͺ������ʹ��λ
	
	UART_Init(UARTx, &para2);
}

void UART_Deinit(void)
{
	//UART->IRCR = 0x00000000;
}

void UARTx_Deinit(UART_Type* UARTx)
{
	//UARTx->CSR = 0x00000000;
	//UARTx->IER  = 0x00000000;
	//UARTx->ISR  = 0x00000000;
	//UARTx->TODR  = 0x00000000;
	//UARTx->RXBUF  = ;
	//UARTx->TXBUF  = ;
	//UARTx->BRG  = 0x00000341;
}

/******END OF FILE****/
