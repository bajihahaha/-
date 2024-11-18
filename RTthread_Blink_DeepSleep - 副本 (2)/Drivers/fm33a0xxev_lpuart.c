/**
  ******************************************************************************
  * @file    fm33a0xxev_lpuart.c
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/

#include "fm33a0xxev_lpuart.h"

/** @addtogroup fm33a0xxev_StdPeriph_Driver
  * @{
  */

/** @defgroup LPUART 
  * @brief LPUART driver modules
  * @{
  */ 

/* LPUARTͨ�ű�־��ֻ�� (Busy)
1��LPUART����ͨ����
0��LPUART���� ��غ��� */
FlagStatus LPUARTx_CSR_BUSY_Chk(LPUART_Type* LPUARTx)
{
	if (LPUARTx ->CSR & LPUARTx_CSR_BUSY_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ���ݽ��ջ����������� ��غ��� */
void LPUARTx_CSR_WKBYTECFG_Setable(LPUART_Type* LPUARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPUARTx->CSR |= (LPUARTx_CSR_WKBYTECFG_Msk);
	}
	else
	{
		LPUARTx->CSR &= ~(LPUARTx_CSR_WKBYTECFG_Msk);
	}
}

/* ���ݽ��ջ����������� (Wakeup Byte Config)
1��������1�ֽڣ�������żУ���STOPλ����ȷ���Ŵ��������ж�
0��������1�ֽڣ������У��λ��STOPλ��ֱ�Ӵ��������ж� ��غ��� */
FlagStatus LPUARTx_CSR_WKBYTECFG_Chk(LPUART_Type* LPUARTx)
{
	if (LPUARTx ->CSR & LPUARTx_CSR_WKBYTECFG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* �����ж��¼����ã����ڿ��ƺ����¼�����CPU�ṩ�����ж�
(Receive Wakeup Event)
00��STARTλ��⻽��
01��1byte���ݽ������
10����������ƥ��ɹ�
11��RXD�½��ؼ�� ��غ��� */
void LPUARTx_CSR_RXEV_Set(LPUART_Type* LPUARTx,uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPUARTx ->CSR;
	tmpreg &= ~(LPUARTx_CSR_RXEV_Msk);
	tmpreg |= (SetValue & LPUARTx_CSR_RXEV_Msk);
	LPUARTx ->CSR = tmpreg;
}

uint32_t LPUARTx_CSR_RXEV_Get(LPUART_Type* LPUARTx)
{
	return (LPUARTx ->CSR & LPUARTx_CSR_RXEV_Msk);
}

/* RX��TX���Ž���
0��Ĭ��
1������ */
void LPUARTx_CSR_IOSWAP_Set(LPUART_Type* LPUARTx,uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPUARTx ->CSR;
	tmpreg &= ~(LPUARTx_CSR_IOSWAP_Msk);
	tmpreg |= (SetValue & LPUARTx_CSR_IOSWAP_Msk);
	LPUARTx ->CSR = tmpreg;
}

uint32_t LPUARTx_CSR_IOSWAP_Get(LPUART_Type* LPUARTx)
{
	return (LPUARTx ->CSR & LPUARTx_CSR_IOSWAP_Msk);
}

/* DMA��������ж�ʹ�ܣ�����LPUARTͨ��DMA���з���ʱ��Ч (DMA Transmit Interrupt Config)
1��IE=1������£�DMAģʽ�·��������һ֡�������ж��ź���������һ֮֡ǰ������֡������ɺ������ж��ź����
0���Ƿ������ж��ź��������IE���� ��غ��� */
void LPUARTx_CSR_DMATXIFCFG_Setable(LPUART_Type* LPUARTx,FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPUARTx ->CSR |= (LPUARTx_CSR_DMATXIFCFG_Msk);
	}
	else
	{
		LPUARTx ->CSR &= ~(LPUARTx_CSR_DMATXIFCFG_Msk);
	}
}

FunState LPUARTx_CSR_DMATXIFCFG_Getable(LPUART_Type* LPUARTx)
{
	if (LPUARTx ->CSR & (LPUARTx_CSR_DMATXIFCFG_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���ݷ���/����ʱ��λ˳�� (Bit Order)
0��LSB first
1��MSB first ��غ��� */
void LPUARTx_CSR_BITORD_Set(LPUART_Type* LPUARTx,uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPUARTx ->CSR;
	tmpreg &= ~(LPUARTx_CSR_BITORD_Msk);
	tmpreg |= (SetValue & LPUARTx_CSR_BITORD_Msk);
	LPUARTx ->CSR = tmpreg;
}

uint32_t LPUARTx_CSR_BITORD_Get(LPUART_Type* LPUARTx)
{
	return (LPUARTx ->CSR & LPUARTx_CSR_BITORD_Msk);
}

/* ֹͣλ������ã����Է���֡��ʽ��Ч������ʱ���ж�ֹͣλ���� (Stop bit Config)
0��1λֹͣλ
1��2λֹͣλ ��غ��� */
void LPUARTx_CSR_STOPCFG_Set(LPUART_Type* LPUARTx,uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPUARTx ->CSR;
	tmpreg &= ~(LPUARTx_CSR_STOPCFG_Msk);
	tmpreg |= (SetValue & LPUARTx_CSR_STOPCFG_Msk);
	LPUARTx ->CSR = tmpreg;
}

uint32_t LPUARTx_CSR_STOPCFG_Get(LPUART_Type* LPUARTx)
{
	return (LPUARTx ->CSR & LPUARTx_CSR_STOPCFG_Msk);
}

/* ÿ֡���ݳ���ѡ�񣻴˼Ĵ��������ݷ��ͺͽ���ͬʱ��Ч
(Payload Data length Select)
00��7λ����
01��8λ����
10��9λ����
11��6λ���� ��غ��� */
void LPUARTx_CSR_PDSEL_Set(LPUART_Type* LPUARTx,uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPUARTx ->CSR;
	tmpreg &= ~(LPUARTx_CSR_PDSEL_Msk);
	tmpreg |= (SetValue & LPUARTx_CSR_PDSEL_Msk);
	LPUARTx ->CSR = tmpreg;
}

uint32_t LPUARTx_CSR_PDSEL_Get(LPUART_Type* LPUARTx)
{
	return (LPUARTx ->CSR & LPUARTx_CSR_PDSEL_Msk);
}

/* У��λ���ã��˼Ĵ��������ݷ��ͺͽ���ͬʱ��Ч (Parity)
00����У��λ
01��żУ��
10����У��
11��RFU ��غ��� */
void LPUARTx_CSR_PARITY_Set(LPUART_Type* LPUARTx,uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPUARTx ->CSR;
	tmpreg &= ~(LPUARTx_CSR_PARITY_Msk);
	tmpreg |= (SetValue & LPUARTx_CSR_PARITY_Msk);
	LPUARTx ->CSR = tmpreg;
}

uint32_t LPUARTx_CSR_PARITY_Get(LPUART_Type* LPUARTx)
{
	return (LPUARTx ->CSR & LPUARTx_CSR_PARITY_Msk);
}

/* �������ݼ������� (Receive Polarity)
0������
1��ȡ�� ��غ��� */
void LPUARTx_CSR_RXPOL_Set(LPUART_Type* LPUARTx,uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPUARTx ->CSR;
	tmpreg &= ~(LPUARTx_CSR_RXPOL_Msk);
	tmpreg |= (SetValue & LPUARTx_CSR_RXPOL_Msk);
	LPUARTx ->CSR = tmpreg;
}

uint32_t LPUARTx_CSR_RXPOL_Get(LPUART_Type* LPUARTx)
{
	return (LPUARTx ->CSR & LPUARTx_CSR_RXPOL_Msk);
}

/* �������ݼ������� (Transmit Polarity)
0������
1��ȡ�� ��غ��� */
void LPUARTx_CSR_TXPOL_Set(LPUART_Type* LPUARTx,uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPUARTx ->CSR;
	tmpreg &= ~(LPUARTx_CSR_TXPOL_Msk);
	tmpreg |= (SetValue & LPUARTx_CSR_TXPOL_Msk);
	LPUARTx ->CSR = tmpreg;
}

uint32_t LPUARTx_CSR_TXPOL_Get(LPUART_Type* LPUARTx)
{
	return (LPUARTx ->CSR & LPUARTx_CSR_TXPOL_Msk);
}

/* ����ʹ�ܣ�1��Ч (Receive Enable) ��غ��� */
void LPUARTx_CSR_RXEN_Setable(LPUART_Type* LPUARTx,FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPUARTx ->CSR |= (LPUARTx_CSR_RXEN_Msk);
	}
	else
	{
		LPUARTx ->CSR &= ~(LPUARTx_CSR_RXEN_Msk);
	}
}

FunState LPUARTx_CSR_RXEN_Getable(LPUART_Type* LPUARTx)
{
	if (LPUARTx ->CSR & (LPUARTx_CSR_RXEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ����ʹ�ܣ�1��Ч (Transmit Enable) ��غ��� */
void LPUARTx_CSR_TXEN_Setable(LPUART_Type* LPUARTx,FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPUARTx ->CSR |= (LPUARTx_CSR_TXEN_Msk);
	}
	else
	{
		LPUARTx ->CSR &= ~(LPUARTx_CSR_TXEN_Msk);
	}
}

FunState LPUARTx_CSR_TXEN_Getable(LPUART_Type* LPUARTx)
{
	if (LPUARTx ->CSR & (LPUARTx_CSR_TXEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���ջ����¼��ж�ʹ�ܣ�1��Ч (Receive Event Interrupt Enable) ��غ��� */
void LPUARTx_IER_RXEV_IE_Setable(LPUART_Type* LPUARTx,FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPUARTx ->IER |= (LPUARTx_IER_RXEV_IE_Msk);
	}
	else
	{
		LPUARTx ->IER &= ~(LPUARTx_IER_RXEV_IE_Msk);
	}
}

FunState LPUARTx_IER_RXEV_IE_Getable(LPUART_Type* LPUARTx)
{
	if (LPUARTx ->IER & (LPUARTx_IER_RXEV_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���մ����ж�ʹ�ܣ�1��Ч (Receive Error Interrupt Enable) ��غ��� */
void LPUARTx_IER_RXERR_IE_Setable(LPUART_Type* LPUARTx,FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPUARTx ->IER |= (LPUARTx_IER_RXERR_IE_Msk);
	}
	else
	{
		LPUARTx ->IER &= ~(LPUARTx_IER_RXERR_IE_Msk);
	}
}

FunState LPUARTx_IER_RXERR_IE_Getable(LPUART_Type* LPUARTx)
{
	if (LPUARTx ->IER & (LPUARTx_IER_RXERR_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���ջ������ж�ʹ�ܣ�1��Ч (Receive Buffer Full Interrupt Enable) ��غ��� */
void LPUARTx_IER_RXBF_IE_Setable(LPUART_Type* LPUARTx,FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPUARTx ->IER |= (LPUARTx_IER_RXBF_IE_Msk);
	}
	else
	{
		LPUARTx ->IER &= ~(LPUARTx_IER_RXBF_IE_Msk);
	}
}

FunState LPUARTx_IER_RXBF_IE_Getable(LPUART_Type* LPUARTx)
{
	if (LPUARTx ->IER & (LPUARTx_IER_RXBF_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���ͻ�����ж�ʹ�ܣ�1��Ч (Transmit Buffer Empty Interrupt Enable) ��غ��� */
void LPUARTx_IER_TXBE_IE_Setable(LPUART_Type* LPUARTx,FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPUARTx ->IER |= (LPUARTx_IER_TXBE_IE_Msk);
	}
	else
	{
		LPUARTx ->IER &= ~(LPUARTx_IER_TXBE_IE_Msk);
	}
}

FunState LPUARTx_IER_TXBE_IE_Getable(LPUART_Type* LPUARTx)
{
	if (LPUARTx ->IER & (LPUARTx_IER_TXBE_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���ͻ�����ҷ�����λ�Ĵ������ж�ʹ�ܣ�1��Ч (Transmit Shift register Interrupt Enable) ��غ��� */
void LPUARTx_IER_TXSE_IE_Setable(LPUART_Type* LPUARTx,FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPUARTx ->IER |= (LPUARTx_IER_TXSE_IE_Msk);
	}
	else
	{
		LPUARTx ->IER &= ~(LPUARTx_IER_TXSE_IE_Msk);
	}
}

FunState LPUARTx_IER_TXSE_IE_Getable(LPUART_Type* LPUARTx)
{
	if (LPUARTx ->IER & (LPUARTx_IER_TXSE_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���ջ����¼��жϱ�־��Ӳ����λ�����д1���� (Receive Event Interrupt Flag)
�жϱ�־����Դ��LPUxCR.RXEV�Ĵ������á� ��غ��� */
void LPUARTx_ISR_RXEVF_Clr(LPUART_Type* LPUARTx)
{
	LPUARTx ->ISR = LPUARTx_ISR_RXEVF_Msk;
}

FlagStatus LPUARTx_ISR_RXEVF_Chk(LPUART_Type* LPUARTx)
{
	if (LPUARTx ->ISR & LPUARTx_ISR_RXEVF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ���ͻ����������Ӳ����λ�����д1���� (Transmit Overflow Error)
�����ͻ����е����ݻ�δ������λ�Ĵ�������ʱ��������ͻ���д�������ݣ�������TXOV��־��λ�� ��غ��� */
void LPUARTx_ISR_TXOV_Clr(LPUART_Type* LPUARTx)
{
	LPUARTx ->ISR = LPUARTx_ISR_TXOV_Msk;
}

FlagStatus LPUARTx_ISR_TXOV_Chk(LPUART_Type* LPUARTx)
{
	if (LPUARTx ->ISR & LPUARTx_ISR_TXOV_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��żУ������жϱ�־��Ӳ����λ�����д1���� (Parity Error) ��غ��� */
void LPUARTx_ISR_PERR_Clr(LPUART_Type* LPUARTx)
{
	LPUARTx ->ISR = LPUARTx_ISR_PERR_Msk;
}

FlagStatus LPUARTx_ISR_PERR_Chk(LPUART_Type* LPUARTx)
{
	if (LPUARTx ->ISR & LPUARTx_ISR_PERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ֡��ʽ�����жϱ�־��Ӳ����λ�����д1���� (Frame Error) ��غ��� */
void LPUARTx_ISR_FERR_Clr(LPUART_Type* LPUARTx)
{
	LPUARTx ->ISR = LPUARTx_ISR_FERR_Msk;
}

FlagStatus LPUARTx_ISR_FERR_Chk(LPUART_Type* LPUARTx)
{
	if (LPUARTx ->ISR & LPUARTx_ISR_FERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ���ջ�����������жϱ�־�������ջ�����������£��յ��µ�����ʱ��λ��Ӳ����λ�����д1���� (Receive Buffer Overflow Error) ��غ��� */
void LPUARTx_ISR_OERR_Clr(LPUART_Type* LPUARTx)
{
	LPUARTx ->ISR = LPUARTx_ISR_OERR_Msk;
}

FlagStatus LPUARTx_ISR_OERR_Chk(LPUART_Type* LPUARTx)
{
	if (LPUARTx ->ISR & LPUARTx_ISR_OERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ���ջ������жϱ�־��Ӳ����λ�����д1���߶�ȡRXBUFʱ���� (Receive Buffer Full) ��غ��� */
void LPUARTx_ISR_RXBF_Clr(LPUART_Type* LPUARTx)
{
	LPUARTx ->ISR = LPUARTx_ISR_RXBF_Msk;
}

FlagStatus LPUARTx_ISR_RXBF_Chk(LPUART_Type* LPUARTx)
{
	if (LPUARTx ->ISR & LPUARTx_ISR_RXBF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ���ͻ�����жϱ�־��Ӳ����λ��д��TXBUFʱ���� (Transmit Buffer Empty) ��غ��� */
FlagStatus LPUARTx_ISR_TXBE_Chk(LPUART_Type* LPUARTx)
{
	if (LPUARTx ->ISR & LPUARTx_ISR_TXBE_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ���ͻ�����ҷ�����λ�Ĵ������жϱ�־��Ӳ����λ�����д1���߷������ݱ�������λ�Ĵ���ʱ���� (Transmit Shift register Empty) ��غ��� */
void LPUARTx_ISR_TXSE_Clr(LPUART_Type* LPUARTx)
{
	LPUARTx ->ISR = LPUARTx_ISR_TXSE_Msk;
}

FlagStatus LPUARTx_ISR_TXSE_Chk(LPUART_Type* LPUARTx)
{
	if (LPUARTx ->ISR & LPUARTx_ISR_TXSE_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* LPUARTÿ��bit��λ����ƿ����źţ��μ�����!δ�ҵ�����Դ������!δ�ҵ�����Դ�� (Bit Modulation Control) ��غ��� */
void LPUARTx_BMR_MCTL_Set(LPUART_Type* LPUARTx,uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPUARTx ->BMR;
	tmpreg &= ~(LPUARTx_BMR_MCTL_Msk);
	tmpreg |= (SetValue & LPUARTx_BMR_MCTL_Msk);
	LPUARTx ->BMR = tmpreg;
}

uint32_t LPUARTx_BMR_MCTL_Get(LPUART_Type* LPUARTx)
{
	return (LPUARTx ->BMR & LPUARTx_BMR_MCTL_Msk);
}

/* �����ʿ��ƣ�bps��
000��9600
001��4800
010��2400
011��1200
100��600
101/110/111��300 ��غ��� */
void LPUARTx_BMR_BAUD_Set(LPUART_Type* LPUARTx,uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPUARTx ->BMR;
	tmpreg &= ~(LPUARTx_BMR_BAUD_Msk);
	tmpreg |= (SetValue & LPUARTx_BMR_BAUD_Msk);
	LPUARTx ->BMR = tmpreg;
}

uint32_t LPUARTx_BMR_BAUD_Get(LPUART_Type* LPUARTx)
{
	return (LPUARTx ->BMR & LPUARTx_BMR_BAUD_Msk);
}

/* �������ݻ���Ĵ��� (Receive Buffer) ��غ��� */
uint32_t LPUARTx_RXBUF_Read(LPUART_Type* LPUARTx)
{
	return (LPUARTx ->RXBUF & LPUARTx_RXBUF_RXBUF_Msk);
}

/* �������ݻ���Ĵ��� (Transmit Buffer) ��غ��� */
void LPUARTx_TXBUF_Write(LPUART_Type* LPUARTx,uint32_t SetValue)
{
	LPUARTx ->TXBUF = (SetValue & LPUARTx_TXBUF_TXBUF_Msk);
}

/* ��һ֡���ձȽ����ݣ����RXEV=10�������յ��ĵ�һ֡������MATD��ͬʱ������RXEVF�жϣ�������������ģʽ�µ����ݽ��ջ��ѡ�
(Matched Data) ��غ��� */
void LPUARTx_DMR_Write(LPUART_Type* LPUARTx,uint32_t SetValue)
{
	LPUARTx ->DMR = (SetValue & LPUARTx_DMR_MATD_Msk);
}

uint32_t LPUARTx_DMR_Read(LPUART_Type* LPUARTx)
{
	return (LPUARTx ->DMR & LPUARTx_DMR_MATD_Msk);
}


void LPUARTx_Deinit(LPUART_Type* LPUARTx)
{
	//LPUARTx ->CSR = 0x00000000;
	//LPUARTx ->IER = 0x00000000;
	//LPUARTx ->ISR = 0x00000002;
	//LPUARTx ->BMR = 0x00000000;
	//LPUARTx ->RXBUF = ;
	//LPUARTx ->TXBUF = ;
	//LPUARTx ->DMR = ;
}

/******END OF FILE****/
