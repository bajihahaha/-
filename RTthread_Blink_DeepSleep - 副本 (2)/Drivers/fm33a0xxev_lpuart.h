/**
  ******************************************************************************
  * @file    fm33a0xxev_lpuart.h
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file contains all the functions prototypes for the LPUART firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33A0XXEV_LPUART_H
#define __FM33A0XXEV_LPUART_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33A0XXEV.h" 
	 
#define LPUARTx_MCTL_FOR9600 (0x00000552<<16)
#define LPUARTx_MCTL_FOR4800 (0x00001EFB<<16)
#define LPUARTx_MCTL_FOR2400 (0x000016DB<<16)
#define LPUARTx_MCTL_FOR1200 (0x00000492<<16)
#define LPUARTx_MCTL_FOR600  (0x000016D6<<16)
#define LPUARTx_MCTL_FOR300  (0x00000842<<16)	 
	 
#define	LPUARTx_CSR_BUSY_Pos	24	/* LPUARTͨ�ű�־��ֻ�� (Busy)
1��LPUART����ͨ����
0��LPUART���� */
#define	LPUARTx_CSR_BUSY_Msk	(0x1U << LPUARTx_CSR_BUSY_Pos)

#define	LPUARTx_CSR_WKBYTECFG_Pos	19	/* ���ݽ��ջ����������� (Wakeup Byte Config)
1��������1�ֽڣ�������żУ���STOPλ����ȷ���Ŵ��������ж�
0��������1�ֽڣ������У��λ��STOPλ��ֱ�Ӵ��������ж� */
#define	LPUARTx_CSR_WKBYTECFG_Msk	(0x1U << LPUARTx_CSR_WKBYTECFG_Pos)

#define	LPUARTx_CSR_RXEV_Pos	16	/* �����ж��¼����ã����ڿ��ƺ����¼�����CPU�ṩ�����ж�
(Receive Wakeup Event)
00��STARTλ��⻽��
01��1byte���ݽ������
10����������ƥ��ɹ�
11��RXD�½��ؼ�� */
#define	LPUARTx_CSR_RXEV_Msk	(0x3U << LPUARTx_CSR_RXEV_Pos)
#define	LPUARTx_CSR_RXEV_START	(0x0U << LPUARTx_CSR_RXEV_Pos)	/* STARTλ��⻽�� */
#define	LPUARTx_CSR_RXEV_1BYTE	(0x1U << LPUARTx_CSR_RXEV_Pos)	/* 1byte���ݽ������ */
#define	LPUARTx_CSR_RXEV_MATCH	(0x2U << LPUARTx_CSR_RXEV_Pos)	/* ��������ƥ��ɹ� */
#define	LPUARTx_CSR_RXEV_FALLING	(0x3U << LPUARTx_CSR_RXEV_Pos)	/* RXD�½��ؼ�� */

#define	LPUARTx_CSR_IOSWAP_Pos	11	/* RX��TX���Ž���
0��Ĭ��
1������ */
#define	LPUARTx_CSR_IOSWAP_Msk	(0x1U << LPUARTx_CSR_IOSWAP_Pos)
#define	LPUARTx_CSR_IOSWAP_DEFUALT	(0x0U << LPUARTx_CSR_IOSWAP_Pos)	/* Ĭ�� */
#define	LPUARTx_CSR_IOSWAP_SWAP		(0x1U << LPUARTx_CSR_IOSWAP_Pos)	/* ���� */


#define	LPUARTx_CSR_DMATXIFCFG_Pos	10	/* DMA��������ж�ʹ�ܣ�����LPUARTͨ��DMA���з���ʱ��Ч (DMA Transmit Interrupt Config)
1��IE=1������£�DMAģʽ�·��������һ֡�������ж��ź���������һ֮֡ǰ������֡������ɺ������ж��ź����
0���Ƿ������ж��ź��������IE���� */
#define	LPUARTx_CSR_DMATXIFCFG_Msk	(0x1U << LPUARTx_CSR_DMATXIFCFG_Pos)
	/* IE=1������£�DMAģʽ�·��������һ֡�������ж��ź���������һ֮֡ǰ������֡������ɺ������ж��ź���� */
	/* �Ƿ������ж��ź��������IE���� */

#define	LPUARTx_CSR_BITORD_Pos	9	/* ���ݷ���/����ʱ��λ˳�� (Bit Order)
0��LSB first
1��MSB first */
#define	LPUARTx_CSR_BITORD_Msk	(0x1U << LPUARTx_CSR_BITORD_Pos)
#define	LPUARTx_CSR_BITORD_LSB	(0x0U << LPUARTx_CSR_BITORD_Pos)	/* LSB first */
#define	LPUARTx_CSR_BITORD_MSB	(0x1U << LPUARTx_CSR_BITORD_Pos)	/* MSB first */

#define	LPUARTx_CSR_STOPCFG_Pos	8	/* ֹͣλ������ã����Է���֡��ʽ��Ч������ʱ���ж�ֹͣλ���� (Stop bit Config)
0��1λֹͣλ
1��2λֹͣλ */
#define	LPUARTx_CSR_STOPCFG_Msk	(0x1U << LPUARTx_CSR_STOPCFG_Pos)
#define	LPUARTx_CSR_STOPCFG_1STOP	(0x0U << LPUARTx_CSR_STOPCFG_Pos)	/* 1λֹͣλ */
#define	LPUARTx_CSR_STOPCFG_2STOP	(0x1U << LPUARTx_CSR_STOPCFG_Pos)	/* 2λֹͣλ */

#define	LPUARTx_CSR_PDSEL_Pos	6	/* ÿ֡���ݳ���ѡ�񣻴˼Ĵ��������ݷ��ͺͽ���ͬʱ��Ч
(Payload Data length Select)
00��7λ����
01��8λ����
10��9λ����
11��6λ���� */
#define	LPUARTx_CSR_PDSEL_Msk	(0x3U << LPUARTx_CSR_PDSEL_Pos)
#define	LPUARTx_CSR_PDSEL_7BITS	(0x0U << LPUARTx_CSR_PDSEL_Pos)	/* 7λ���� */
#define	LPUARTx_CSR_PDSEL_8BITS	(0x1U << LPUARTx_CSR_PDSEL_Pos)	/* 8λ���� */
#define	LPUARTx_CSR_PDSEL_9BITS	(0x2U << LPUARTx_CSR_PDSEL_Pos)	/* 9λ���� */
#define	LPUARTx_CSR_PDSEL_6BITS	(0x3U << LPUARTx_CSR_PDSEL_Pos)	/* 6λ���� */

#define	LPUARTx_CSR_PARITY_Pos	4	/* У��λ���ã��˼Ĵ��������ݷ��ͺͽ���ͬʱ��Ч (Parity)
00����У��λ
01��żУ��
10����У��
11��RFU */
#define	LPUARTx_CSR_PARITY_Msk	(0x3U << LPUARTx_CSR_PARITY_Pos)
#define	LPUARTx_CSR_PARITY_NON	(0x0U << LPUARTx_CSR_PARITY_Pos)	/* ��У��λ */
#define	LPUARTx_CSR_PARITY_EVEN	(0x1U << LPUARTx_CSR_PARITY_Pos)	/* żУ�� */
#define	LPUARTx_CSR_PARITY_ODD	(0x2U << LPUARTx_CSR_PARITY_Pos)	/* ��У�� */

#define	LPUARTx_CSR_RXPOL_Pos	3	/* �������ݼ������� (Receive Polarity)
0������
1��ȡ�� */
#define	LPUARTx_CSR_RXPOL_Msk	(0x1U << LPUARTx_CSR_RXPOL_Pos)
#define	LPUARTx_CSR_RXPOL_POS	(0x0U << LPUARTx_CSR_RXPOL_Pos)	/* ���� */
#define	LPUARTx_CSR_RXPOL_NEG	(0x1U << LPUARTx_CSR_RXPOL_Pos)	/* ȡ�� */

#define	LPUARTx_CSR_TXPOL_Pos	2	/* �������ݼ������� (Transmit Polarity)
0������
1��ȡ�� */
#define	LPUARTx_CSR_TXPOL_Msk	(0x1U << LPUARTx_CSR_TXPOL_Pos)
#define	LPUARTx_CSR_TXPOL_POS	(0x0U << LPUARTx_CSR_TXPOL_Pos)	/* ���� */
#define	LPUARTx_CSR_TXPOL_NEG	(0x1U << LPUARTx_CSR_TXPOL_Pos)	/* ȡ�� */

#define	LPUARTx_CSR_RXEN_Pos	1	/* ����ʹ�ܣ�1��Ч (Receive Enable) */
#define	LPUARTx_CSR_RXEN_Msk	(0x1U << LPUARTx_CSR_RXEN_Pos)

#define	LPUARTx_CSR_TXEN_Pos	0	/* ����ʹ�ܣ�1��Ч (Transmit Enable) */
#define	LPUARTx_CSR_TXEN_Msk	(0x1U << LPUARTx_CSR_TXEN_Pos)

#define	LPUARTx_IER_RXEV_IE_Pos	12	/* ���ջ����¼��ж�ʹ�ܣ�1��Ч (Receive Event Interrupt Enable) */
#define	LPUARTx_IER_RXEV_IE_Msk	(0x1U << LPUARTx_IER_RXEV_IE_Pos)

#define	LPUARTx_IER_RXERR_IE_Pos	10	/* ���մ����ж�ʹ�ܣ�1��Ч (Receive Error Interrupt Enable) */
#define	LPUARTx_IER_RXERR_IE_Msk	(0x1U << LPUARTx_IER_RXERR_IE_Pos)

#define	LPUARTx_IER_RXBF_IE_Pos	8	/* ���ջ������ж�ʹ�ܣ�1��Ч (Receive Buffer Full Interrupt Enable) */
#define	LPUARTx_IER_RXBF_IE_Msk	(0x1U << LPUARTx_IER_RXBF_IE_Pos)

#define	LPUARTx_IER_TXBE_IE_Pos	1	/* ���ͻ�����ж�ʹ�ܣ�1��Ч (Transmit Buffer Empty Interrupt Enable) */
#define	LPUARTx_IER_TXBE_IE_Msk	(0x1U << LPUARTx_IER_TXBE_IE_Pos)

#define	LPUARTx_IER_TXSE_IE_Pos	0	/* ���ͻ�����ҷ�����λ�Ĵ������ж�ʹ�ܣ�1��Ч (Transmit Shift register Interrupt Enable) */
#define	LPUARTx_IER_TXSE_IE_Msk	(0x1U << LPUARTx_IER_TXSE_IE_Pos)

#define	LPUARTx_ISR_RXEVF_Pos	24	/* ���ջ����¼��жϱ�־��Ӳ����λ�����д1���� (Receive Event Interrupt Flag)
�жϱ�־����Դ��LPUxCR.RXEV�Ĵ������á� */
#define	LPUARTx_ISR_RXEVF_Msk	(0x1U << LPUARTx_ISR_RXEVF_Pos)

#define	LPUARTx_ISR_TXOV_Pos	19	/* ���ͻ����������Ӳ����λ�����д1���� (Transmit Overflow Error)
�����ͻ����е����ݻ�δ������λ�Ĵ�������ʱ��������ͻ���д�������ݣ�������TXOV��־��λ�� */
#define	LPUARTx_ISR_TXOV_Msk	(0x1U << LPUARTx_ISR_TXOV_Pos)

#define	LPUARTx_ISR_PERR_Pos	18	/* ��żУ������жϱ�־��Ӳ����λ�����д1���� (Parity Error) */
#define	LPUARTx_ISR_PERR_Msk	(0x1U << LPUARTx_ISR_PERR_Pos)

#define	LPUARTx_ISR_FERR_Pos	17	/* ֡��ʽ�����жϱ�־��Ӳ����λ�����д1���� (Frame Error) */
#define	LPUARTx_ISR_FERR_Msk	(0x1U << LPUARTx_ISR_FERR_Pos)

#define	LPUARTx_ISR_OERR_Pos	16	/* ���ջ�����������жϱ�־�������ջ�����������£��յ��µ�����ʱ��λ��Ӳ����λ�����д1���� (Receive Buffer Overflow Error) */
#define	LPUARTx_ISR_OERR_Msk	(0x1U << LPUARTx_ISR_OERR_Pos)

#define	LPUARTx_ISR_RXBF_Pos	8	/* ���ջ������жϱ�־��Ӳ����λ�����д1���߶�ȡRXBUFʱ���� (Receive Buffer Full) */
#define	LPUARTx_ISR_RXBF_Msk	(0x1U << LPUARTx_ISR_RXBF_Pos)

#define	LPUARTx_ISR_TXBE_Pos	1	/* ���ͻ�����жϱ�־��Ӳ����λ��д��TXBUFʱ���� (Transmit Buffer Empty) */
#define	LPUARTx_ISR_TXBE_Msk	(0x1U << LPUARTx_ISR_TXBE_Pos)

#define	LPUARTx_ISR_TXSE_Pos	0	/* ���ͻ�����ҷ�����λ�Ĵ������жϱ�־��Ӳ����λ�����д1���߷������ݱ�������λ�Ĵ���ʱ���� (Transmit Shift register Empty) */
#define	LPUARTx_ISR_TXSE_Msk	(0x1U << LPUARTx_ISR_TXSE_Pos)

#define	LPUARTx_BMR_MCTL_Pos	16	/* LPUARTÿ��bit��λ����ƿ����źţ��μ�����!δ�ҵ�����Դ������!δ�ҵ�����Դ�� (Bit Modulation Control) */
#define	LPUARTx_BMR_MCTL_Msk	(0x1fffU << LPUARTx_BMR_MCTL_Pos)

#define	LPUARTx_BMR_BAUD_Pos	0	/* �����ʿ��ƣ�bps��
000��9600
001��4800
010��2400
011��1200
100��600
101/110/111��300 */
#define	LPUARTx_BMR_BAUD_Msk	(0x7U << LPUARTx_BMR_BAUD_Pos)
#define	LPUARTx_BMR_BAUD_9600	(0x0U << LPUARTx_BMR_BAUD_Pos)	/* 9600 */
#define	LPUARTx_BMR_BAUD_4800	(0x1U << LPUARTx_BMR_BAUD_Pos)	/* 4800 */
#define	LPUARTx_BMR_BAUD_2400	(0x2U << LPUARTx_BMR_BAUD_Pos)	/* 2400 */
#define	LPUARTx_BMR_BAUD_1200	(0x3U << LPUARTx_BMR_BAUD_Pos)	/* 1200 */
#define	LPUARTx_BMR_BAUD_600	(0x4U << LPUARTx_BMR_BAUD_Pos)	/* 600 */
#define	LPUARTx_BMR_BAUD_300	(0x5U << LPUARTx_BMR_BAUD_Pos)	/* 300 */

#define	LPUARTx_RXBUF_RXBUF_Pos	0	/* �������ݻ���Ĵ��� (Receive Buffer) */
#define	LPUARTx_RXBUF_RXBUF_Msk	(0x1ffU << LPUARTx_RXBUF_RXBUF_Pos)

#define	LPUARTx_TXBUF_TXBUF_Pos	0	/* �������ݻ���Ĵ��� (Transmit Buffer) */
#define	LPUARTx_TXBUF_TXBUF_Msk	(0x1ffU << LPUARTx_TXBUF_TXBUF_Pos)

#define	LPUARTx_DMR_MATD_Pos	0	/* ��һ֡���ձȽ����ݣ����RXEV=10�������յ��ĵ�һ֡������MATD��ͬʱ������RXEVF�жϣ�������������ģʽ�µ����ݽ��ջ��ѡ�
(Matched Data) */
#define	LPUARTx_DMR_MATD_Msk	(0x1ffU << LPUARTx_DMR_MATD_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void LPUARTx_Deinit(LPUART_Type* LPUARTx);

/* LPUARTͨ�ű�־��ֻ�� (Busy)
1��LPUART����ͨ����
0��LPUART���� ��غ��� */
extern FlagStatus LPUARTx_CSR_BUSY_Chk(LPUART_Type* LPUARTx);

/* ���ݽ��ջ����������� ��غ��� */
extern void LPUARTx_CSR_WKBYTECFG_Setable(LPUART_Type* LPUARTx, FunState NewState);
	
/* ���ݽ��ջ����������� (Wakeup Byte Config)
1��������1�ֽڣ�������żУ���STOPλ����ȷ���Ŵ��������ж�
0��������1�ֽڣ������У��λ��STOPλ��ֱ�Ӵ��������ж� ��غ��� */
extern FlagStatus LPUARTx_CSR_WKBYTECFG_Chk(LPUART_Type* LPUARTx);

/* �����ж��¼����ã����ڿ��ƺ����¼�����CPU�ṩ�����ж�
(Receive Wakeup Event)
00��STARTλ��⻽��
01��1byte���ݽ������
10����������ƥ��ɹ�
11��RXD�½��ؼ�� ��غ��� */
extern void LPUARTx_CSR_RXEV_Set(LPUART_Type* LPUARTx,uint32_t SetValue);
extern uint32_t LPUARTx_CSR_RXEV_Get(LPUART_Type* LPUARTx);

/* RX��TX���Ž���
0��Ĭ��
1������ */
extern void LPUARTx_CSR_IOSWAP_Set(LPUART_Type* LPUARTx,uint32_t SetValue);
extern uint32_t LPUARTx_CSR_IOSWAP_Get(LPUART_Type* LPUARTx);


/* DMA��������ж�ʹ�ܣ�����LPUARTͨ��DMA���з���ʱ��Ч (DMA Transmit Interrupt Config)
1��IE=1������£�DMAģʽ�·��������һ֡�������ж��ź���������һ֮֡ǰ������֡������ɺ������ж��ź����
0���Ƿ������ж��ź��������IE���� ��غ��� */
extern void LPUARTx_CSR_DMATXIFCFG_Setable(LPUART_Type* LPUARTx,FunState NewState);
extern FunState LPUARTx_CSR_DMATXIFCFG_Getable(LPUART_Type* LPUARTx);

/* ���ݷ���/����ʱ��λ˳�� (Bit Order)
0��LSB first
1��MSB first ��غ��� */
extern void LPUARTx_CSR_BITORD_Set(LPUART_Type* LPUARTx,uint32_t SetValue);
extern uint32_t LPUARTx_CSR_BITORD_Get(LPUART_Type* LPUARTx);

/* ֹͣλ������ã����Է���֡��ʽ��Ч������ʱ���ж�ֹͣλ���� (Stop bit Config)
0��1λֹͣλ
1��2λֹͣλ ��غ��� */
extern void LPUARTx_CSR_STOPCFG_Set(LPUART_Type* LPUARTx,uint32_t SetValue);
extern uint32_t LPUARTx_CSR_STOPCFG_Get(LPUART_Type* LPUARTx);

/* ÿ֡���ݳ���ѡ�񣻴˼Ĵ��������ݷ��ͺͽ���ͬʱ��Ч
(Payload Data length Select)
00��7λ����
01��8λ����
10��9λ����
11��6λ���� ��غ��� */
extern void LPUARTx_CSR_PDSEL_Set(LPUART_Type* LPUARTx,uint32_t SetValue);
extern uint32_t LPUARTx_CSR_PDSEL_Get(LPUART_Type* LPUARTx);

/* У��λ���ã��˼Ĵ��������ݷ��ͺͽ���ͬʱ��Ч (Parity)
00����У��λ
01��żУ��
10����У��
11��RFU ��غ��� */
extern void LPUARTx_CSR_PARITY_Set(LPUART_Type* LPUARTx,uint32_t SetValue);
extern uint32_t LPUARTx_CSR_PARITY_Get(LPUART_Type* LPUARTx);

/* �������ݼ������� (Receive Polarity)
0������
1��ȡ�� ��غ��� */
extern void LPUARTx_CSR_RXPOL_Set(LPUART_Type* LPUARTx,uint32_t SetValue);
extern uint32_t LPUARTx_CSR_RXPOL_Get(LPUART_Type* LPUARTx);

/* �������ݼ������� (Transmit Polarity)
0������
1��ȡ�� ��غ��� */
extern void LPUARTx_CSR_TXPOL_Set(LPUART_Type* LPUARTx,uint32_t SetValue);
extern uint32_t LPUARTx_CSR_TXPOL_Get(LPUART_Type* LPUARTx);

/* ����ʹ�ܣ�1��Ч (Receive Enable) ��غ��� */
extern void LPUARTx_CSR_RXEN_Setable(LPUART_Type* LPUARTx,FunState NewState);
extern FunState LPUARTx_CSR_RXEN_Getable(LPUART_Type* LPUARTx);

/* ����ʹ�ܣ�1��Ч (Transmit Enable) ��غ��� */
extern void LPUARTx_CSR_TXEN_Setable(LPUART_Type* LPUARTx,FunState NewState);
extern FunState LPUARTx_CSR_TXEN_Getable(LPUART_Type* LPUARTx);

/* ���ջ����¼��ж�ʹ�ܣ�1��Ч (Receive Event Interrupt Enable) ��غ��� */
extern void LPUARTx_IER_RXEV_IE_Setable(LPUART_Type* LPUARTx,FunState NewState);
extern FunState LPUARTx_IER_RXEV_IE_Getable(LPUART_Type* LPUARTx);

/* ���մ����ж�ʹ�ܣ�1��Ч (Receive Error Interrupt Enable) ��غ��� */
extern void LPUARTx_IER_RXERR_IE_Setable(LPUART_Type* LPUARTx,FunState NewState);
extern FunState LPUARTx_IER_RXERR_IE_Getable(LPUART_Type* LPUARTx);

/* ���ջ������ж�ʹ�ܣ�1��Ч (Receive Buffer Full Interrupt Enable) ��غ��� */
extern void LPUARTx_IER_RXBF_IE_Setable(LPUART_Type* LPUARTx,FunState NewState);
extern FunState LPUARTx_IER_RXBF_IE_Getable(LPUART_Type* LPUARTx);

/* ���ͻ�����ж�ʹ�ܣ�1��Ч (Transmit Buffer Empty Interrupt Enable) ��غ��� */
extern void LPUARTx_IER_TXBE_IE_Setable(LPUART_Type* LPUARTx,FunState NewState);
extern FunState LPUARTx_IER_TXBE_IE_Getable(LPUART_Type* LPUARTx);

/* ���ͻ�����ҷ�����λ�Ĵ������ж�ʹ�ܣ�1��Ч (Transmit Shift register Interrupt Enable) ��غ��� */
extern void LPUARTx_IER_TXSE_IE_Setable(LPUART_Type* LPUARTx,FunState NewState);
extern FunState LPUARTx_IER_TXSE_IE_Getable(LPUART_Type* LPUARTx);

/* ���ջ����¼��жϱ�־��Ӳ����λ�����д1���� (Receive Event Interrupt Flag)
�жϱ�־����Դ��LPUxCR.RXEV�Ĵ������á� ��غ��� */
extern void LPUARTx_ISR_RXEVF_Clr(LPUART_Type* LPUARTx);
extern FlagStatus LPUARTx_ISR_RXEVF_Chk(LPUART_Type* LPUARTx);

/* ���ͻ����������Ӳ����λ�����д1���� (Transmit Overflow Error)
�����ͻ����е����ݻ�δ������λ�Ĵ�������ʱ��������ͻ���д�������ݣ�������TXOV��־��λ�� ��غ��� */
extern void LPUARTx_ISR_TXOV_Clr(LPUART_Type* LPUARTx);
extern FlagStatus LPUARTx_ISR_TXOV_Chk(LPUART_Type* LPUARTx);

/* ��żУ������жϱ�־��Ӳ����λ�����д1���� (Parity Error) ��غ��� */
extern void LPUARTx_ISR_PERR_Clr(LPUART_Type* LPUARTx);
extern FlagStatus LPUARTx_ISR_PERR_Chk(LPUART_Type* LPUARTx);

/* ֡��ʽ�����жϱ�־��Ӳ����λ�����д1���� (Frame Error) ��غ��� */
extern void LPUARTx_ISR_FERR_Clr(LPUART_Type* LPUARTx);
extern FlagStatus LPUARTx_ISR_FERR_Chk(LPUART_Type* LPUARTx);

/* ���ջ�����������жϱ�־�������ջ�����������£��յ��µ�����ʱ��λ��Ӳ����λ�����д1���� (Receive Buffer Overflow Error) ��غ��� */
extern void LPUARTx_ISR_OERR_Clr(LPUART_Type* LPUARTx);
extern FlagStatus LPUARTx_ISR_OERR_Chk(LPUART_Type* LPUARTx);

/* ���ջ������жϱ�־��Ӳ����λ�����д1���߶�ȡRXBUFʱ���� (Receive Buffer Full) ��غ��� */
extern void LPUARTx_ISR_RXBF_Clr(LPUART_Type* LPUARTx);
extern FlagStatus LPUARTx_ISR_RXBF_Chk(LPUART_Type* LPUARTx);

/* ���ͻ�����жϱ�־��Ӳ����λ��д��TXBUFʱ���� (Transmit Buffer Empty) ��غ��� */
extern FlagStatus LPUARTx_ISR_TXBE_Chk(LPUART_Type* LPUARTx);

/* ���ͻ�����ҷ�����λ�Ĵ������жϱ�־��Ӳ����λ�����д1���߷������ݱ�������λ�Ĵ���ʱ���� (Transmit Shift register Empty) ��غ��� */
extern void LPUARTx_ISR_TXSE_Clr(LPUART_Type* LPUARTx);
extern FlagStatus LPUARTx_ISR_TXSE_Chk(LPUART_Type* LPUARTx);

/* LPUARTÿ��bit��λ����ƿ����źţ��μ�����!δ�ҵ�����Դ������!δ�ҵ�����Դ�� (Bit Modulation Control) ��غ��� */
extern void LPUARTx_BMR_MCTL_Set(LPUART_Type* LPUARTx,uint32_t SetValue);
extern uint32_t LPUARTx_BMR_MCTL_Get(LPUART_Type* LPUARTx);

/* �����ʿ��ƣ�bps��
000��9600
001��4800
010��2400
011��1200
100��600
101/110/111��300 ��غ��� */
extern void LPUARTx_BMR_BAUD_Set(LPUART_Type* LPUARTx,uint32_t SetValue);
extern uint32_t LPUARTx_BMR_BAUD_Get(LPUART_Type* LPUARTx);

/* �������ݻ���Ĵ��� (Receive Buffer) ��غ��� */
extern uint32_t LPUARTx_RXBUF_Read(LPUART_Type* LPUARTx);

/* �������ݻ���Ĵ��� (Transmit Buffer) ��غ��� */
extern void LPUARTx_TXBUF_Write(LPUART_Type* LPUARTx,uint32_t SetValue);

/* ��һ֡���ձȽ����ݣ����RXEV=10�������յ��ĵ�һ֡������MATD��ͬʱ������RXEVF�жϣ�������������ģʽ�µ����ݽ��ջ��ѡ�
(Matched Data) ��غ��� */
extern void LPUARTx_DMR_Write(LPUART_Type* LPUARTx,uint32_t SetValue);
extern uint32_t LPUARTx_DMR_Read(LPUART_Type* LPUARTx);
//Announce_End
#ifdef __cplusplus
}
#endif

#endif /*__FM33A0XXEV_LPUART_H */
