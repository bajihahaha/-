/**
  ******************************************************************************
  * @file    fm33a0xxev_uart.h
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file contains all the functions prototypes for the UART firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33A0XXEV_UART_H
#define __FM33A0XXEV_UART_H

#ifdef __cplusplus
 extern "C" {
#endif
   
/* Includes ------------------------------------------------------------------*/

#include "FM33A0XXEV.h" 
#include "fm33a0xxev_CMU.h" 
   
typedef enum
{
	RxInt,
	TxInt	
}UART_IntTypeDef;

typedef enum
{
	Seven7Bit,		
	Eight8Bit,
	Nine9Bit,
	Six6Bit	
}UART_DataBitTypeDef;

typedef enum
{
	NONE,
	EVEN,
	ODD	
}UART_ParityBitTypeDef;

typedef enum
{
	OneBit,
	TwoBit
}UART_StopBitTypeDef;

typedef struct
{
	uint32_t				      BaudRate;		//������
	UART_DataBitTypeDef		DataBit;		//����λ��
	UART_ParityBitTypeDef	ParityBit; 	//У��λ
	UART_StopBitTypeDef		StopBit;		//ֹͣλ
	uint32_t 				      ClockSrc;   // ʱ��Դѡ��
}UART_SInitTypeDef;	

typedef struct
{
	FunState				RXBF_IE;		    //�����ж�
	FunState				TXBE_IE;		//���ͻ�����ж�
	FunState				TXSE_IE;		//���ͻ�����ҷ��ͼĴ������ж�
	uint32_t				SPBRG;		  //�����ʲ������Ĵ���
	uint32_t				PDSEL;		  //���ݳ���ѡ��
	uint32_t				PARITY;		  //У��λ����
  FunState				RXTO_IE;		//���ճ�ʱ�ж�
	FunState				ERRIE;		  //�����ж�ʹ�ܿ���
	FunState				RXEN;		    //����ģ��ʹ�ܿ���
	uint32_t				STOPSEL;	  //ֹͣλѡ��
	FunState				TXEN;		    //����ģ��ʹ�ܿ���
	FunState				IREN;		    //���ͺ������ʹ��λ
	FunState				RXDFLAG;	  //��������ȡ������λ
	FunState				TXDFLAG;	  //��������ȡ������λ	
}UART_InitTypeDef;	

#define	UARTIR_CR_IRFLAG_Pos	15	/* ���ƺ�����Ʒ�������ʱ��Ĭ��������� (Infra Red Flag)
0��������
1�������� */
#define	UARTIR_CR_IRFLAG_Msk	(0x1U << UARTIR_CR_IRFLAG_Pos)
#define	UARTIR_CR_IRFLAG_POSITIVE	(0x0U << UARTIR_CR_IRFLAG_Pos)	/* ������ */
#define	UARTIR_CR_IRFLAG_NEGTIVE	(0x1U << UARTIR_CR_IRFLAG_Pos)	/* ������ */

#define	UARTIR_CR_TH_Pos	11	/* ����ռ�ձȵ��Ʋ��� (Tranmission High Duty) */
#define	UARTIR_CR_TH_Msk	(0xfU << UARTIR_CR_TH_Pos)

#define	UARTIR_CR_TZBRG_Pos	0	/* �������Ƶ�� (Transmission Baud Rate) */
#define	UARTIR_CR_TZBRG_Msk	(0x7ffU << UARTIR_CR_TZBRG_Pos)

#define	UARTx_CSR_BUSY_Pos	24	/* UARTͨ�ű�־��ֻ��
1��UART����ͨ����
0��UART���� */
#define	UARTx_CSR_BUSY_Msk	(0x1U << UARTx_CSR_BUSY_Pos)

#define	UARTx_CSR_TXIREN_Pos	17	/* ���ͺ������ʹ��
1��ʹ�ܺ�����Ʒ���
0���رպ�����Ʒ��� */
#define	UARTx_CSR_TXIREN_Msk	(0x1U << UARTx_CSR_TXIREN_Pos)
	/* ʹ�ܺ�����Ʒ��� */
	/* �رպ�����Ʒ��� */

#define	UARTx_CSR_RXTOEN_Pos	16	/* ���ճ�ʱʹ��
1��ʹ�ܽ��ճ�ʱ����
0���رս��ճ�ʱ���� */
#define	UARTx_CSR_RXTOEN_Msk	(0x1U << UARTx_CSR_RXTOEN_Pos)
	/* ʹ�ܽ��ճ�ʱ���� */
	/* �رս��ճ�ʱ���� */

#define	UARTx_CSR_IOSWAP_Pos	12	/* RX��TX���Ž���
0��Ĭ������˳�����װͼһ�£�
1����������˳�� */
#define	UARTx_CSR_IOSWAP_Msk	(0x1U << UARTx_CSR_IOSWAP_Pos)
#define	UARTx_CSR_IOSWAP_DEFAULT	(0x0U << UARTx_CSR_IOSWAP_Pos)	/* Ĭ������˳�����װͼһ�£� */
#define	UARTx_CSR_IOSWAP_EXCHANGE	(0x1U << UARTx_CSR_IOSWAP_Pos)	/* ��������˳�� */

#define	UARTx_CSR_DMATXIFCFG_Pos	10	/* DMA��������ж�ʹ�ܣ�����UARTͨ��DMA���з���ʱ��Ч
1��IE=1������£�DMAģʽ�·��������һ֡�������ж��ź���������һ֮֡ǰ������֡������ɺ������ж��ź����
0���Ƿ������ж��ź��������IE���� */
#define	UARTx_CSR_DMATXIFCFG_Msk	(0x1U << UARTx_CSR_DMATXIFCFG_Pos)
	/* IE=1������£�DMAģʽ�·��������һ֡�������ж��ź���������һ֮֡ǰ������֡������ɺ������ж��ź���� */
	/* �Ƿ������ж��ź��������IE���� */

#define	UARTx_CSR_BITORD_Pos	9	/* ���ݷ���/����ʱ��λ˳��
0��LSB first
1��MSB first */
#define	UARTx_CSR_BITORD_Msk	(0x1U << UARTx_CSR_BITORD_Pos)
#define	UARTx_CSR_BITORD_LSB	(0x0U << UARTx_CSR_BITORD_Pos)	/* LSB first */
#define	UARTx_CSR_BITORD_MSB	(0x1U << UARTx_CSR_BITORD_Pos)	/* MSB first */

#define	UARTx_CSR_STOPCFG_Pos	8	/* ֹͣλ������ã����Է���֡��ʽ��Ч������ʱ���ж�ֹͣλ����
0��1λֹͣλ
1��2λֹͣλ */
#define	UARTx_CSR_STOPCFG_Msk	(0x1U << UARTx_CSR_STOPCFG_Pos)
#define	UARTx_CSR_STOPCFG_1STOPBIT	(0x0U << UARTx_CSR_STOPCFG_Pos)	/* 1λֹͣλ */
#define	UARTx_CSR_STOPCFG_2STOPBIT	(0x1U << UARTx_CSR_STOPCFG_Pos)	/* 2λֹͣλ */

#define	UARTx_CSR_PDSEL_Pos	6	/* ÿ֡�����ݳ���ѡ�񣻴˼Ĵ��������ݷ��ͺͽ���ͬʱ��Ч
00��7λ����
01��8λ����
10��9λ����
11��6λ���� */
#define	UARTx_CSR_PDSEL_Msk	(0x3U << UARTx_CSR_PDSEL_Pos)
#define	UARTx_CSR_PDSEL_7BIT	(0x0U << UARTx_CSR_PDSEL_Pos)	/* 7λ���� */
#define	UARTx_CSR_PDSEL_8BIT	(0x1U << UARTx_CSR_PDSEL_Pos)	/* 8λ���� */
#define	UARTx_CSR_PDSEL_9BIT	(0x2U << UARTx_CSR_PDSEL_Pos)	/* 9λ���� */
#define	UARTx_CSR_PDSEL_6BIT	(0x3U << UARTx_CSR_PDSEL_Pos)	/* 6λ���� */

#define	UARTx_CSR_PARITY_Pos	4	/* У��λ���ã��˼Ĵ��������ݷ��ͺͽ���ͬʱ��Ч
00����У��λ
01��żУ��
10����У��
11��RFU */
#define	UARTx_CSR_PARITY_Msk	(0x3U << UARTx_CSR_PARITY_Pos)
#define	UARTx_CSR_PARITY_NONE	(0x0U << UARTx_CSR_PARITY_Pos)	/* ��У��λ */
#define	UARTx_CSR_PARITY_EVEN	(0x1U << UARTx_CSR_PARITY_Pos)	/* żУ�� */
#define	UARTx_CSR_PARITY_ODD	(0x2U << UARTx_CSR_PARITY_Pos)	/* ��У�� */

#define	UARTx_CSR_RXPOL_Pos	3	/* �������ݼ�������
0������
1��ȡ�� */
#define	UARTx_CSR_RXPOL_Msk	(0x1U << UARTx_CSR_RXPOL_Pos)
#define	UARTx_CSR_RXPOL_POSITIVE	(0x0U << UARTx_CSR_RXPOL_Pos)	/* ���� */
#define	UARTx_CSR_RXPOL_NEGTIVE	(0x1U << UARTx_CSR_RXPOL_Pos)	/* ȡ�� */

#define	UARTx_CSR_TXPOL_Pos	2	/* �������ݼ�������
0������
1��ȡ�� */
#define	UARTx_CSR_TXPOL_Msk	(0x1U << UARTx_CSR_TXPOL_Pos)
#define	UARTx_CSR_TXPOL_POSITIVE	(0x0U << UARTx_CSR_TXPOL_Pos)	/* ���� */
#define	UARTx_CSR_TXPOL_NEGTIVE	(0x1U << UARTx_CSR_TXPOL_Pos)	/* ȡ�� */

#define	UARTx_CSR_RXEN_Pos	1	/* ����ʹ�ܣ�1��Ч */
#define	UARTx_CSR_RXEN_Msk	(0x1U << UARTx_CSR_RXEN_Pos)
#define	UARTx_CSR_RXEN_DISBALE	(0x0U << UARTx_CSR_RXEN_Pos)
#define	UARTx_CSR_RXEN_ENABLE	(0x1U << UARTx_CSR_RXEN_Pos)

#define	UARTx_CSR_TXEN_Pos	0	/* ����ʹ�ܣ�1��Ч */
#define	UARTx_CSR_TXEN_Msk	(0x1U << UARTx_CSR_TXEN_Pos)
#define	UARTx_CSR_TXEN_DISBALE	(0x0U << UARTx_CSR_TXEN_Pos)
#define	UARTx_CSR_TXEN_ENABLE	(0x1U << UARTx_CSR_TXEN_Pos)

#define	UARTx_IER_RXTO_IE_Pos	11	/* ���ճ�ʱ�ж�ʹ�ܣ�1��Ч
����UART0��UART1��Ч�� */
#define	UARTx_IER_RXTO_IE_Msk	(0x1U << UARTx_IER_RXTO_IE_Pos)

#define	UARTx_IER_RXERR_IE_Pos	10	/* ���մ����ж�ʹ�ܣ�1��Ч */
#define	UARTx_IER_RXERR_IE_Msk	(0x1U << UARTx_IER_RXERR_IE_Pos)

#define	UARTx_IER_RXBF_IE_Pos	8	/* ���ջ������ж�ʹ�ܣ�1��Ч */
#define	UARTx_IER_RXBF_IE_Msk	(0x1U << UARTx_IER_RXBF_IE_Pos)

#define	UARTx_IER_NEWUP_IE_Pos	7	/* RX�½����첽����ж�ʹ�ܣ�1��Ч����UART0��UART1��Ч�� */
#define	UARTx_IER_NEWUP_IE_Msk	(0x1U << UARTx_IER_NEWUP_IE_Pos)

#define	UARTx_IER_TXBE_IE_Pos	1	/* ���ͻ�����ж�ʹ�ܣ�1��Ч */
#define	UARTx_IER_TXBE_IE_Msk	(0x1U << UARTx_IER_TXBE_IE_Pos)

#define	UARTx_IER_TXSE_IE_Pos	0	/* ���ͻ�����ҷ�����λ�Ĵ������ж�ʹ�ܣ�1��Ч */
#define	UARTx_IER_TXSE_IE_Msk	(0x1U << UARTx_IER_TXSE_IE_Pos)

#define	UARTx_ISR_PERR_Pos	18	/* ��żУ������жϱ�־��Ӳ����λ�����д1���� */
#define	UARTx_ISR_PERR_Msk	(0x1U << UARTx_ISR_PERR_Pos)

#define	UARTx_ISR_FERR_Pos	17	/* ֡��ʽ�����жϱ�־��Ӳ����λ�����д1���� */
#define	UARTx_ISR_FERR_Msk	(0x1U << UARTx_ISR_FERR_Pos)

#define	UARTx_ISR_OERR_Pos	16	/* ���ջ�����������жϱ�־�������ջ�����������£��յ��µ�����ʱ��λ��Ӳ����λ�����д1���߶�ȡRXBUFʱ����
�������ʱ�����ջ�������ԭ�е����ݱ������ݸ��ǡ� */
#define	UARTx_ISR_OERR_Msk	(0x1U << UARTx_ISR_OERR_Pos)

#define	UARTx_ISR_RXTO_Pos	11	/* ���ճ�ʱ�жϱ�־��Ӳ����λ�����д1����
����UART0��UART1��Ч�� */
#define	UARTx_ISR_RXTO_Msk	(0x1U << UARTx_ISR_RXTO_Pos)

#define	UARTx_ISR_RXBF_Pos	8	/* ���ջ������жϱ�־��Ӳ����λ�����д1���߶�ȡRXBUFʱ���� */
#define	UARTx_ISR_RXBF_Msk	(0x1U << UARTx_ISR_RXBF_Pos)

#define	UARTx_ISR_TXBE_Pos	1	/* ���ͻ�����жϱ�־��Ӳ����λ�����д��TXBUFʱ���� */
#define	UARTx_ISR_TXBE_Msk	(0x1U << UARTx_ISR_TXBE_Pos)

#define	UARTx_ISR_TXSE_Pos	0	/* ���ͻ��������λ�Ĵ�����������жϱ�־��Ӳ����λ�����д1�������д���ͻ���ʱ���� */
#define	UARTx_ISR_TXSE_Msk	(0x1U << UARTx_ISR_TXSE_Pos)

#define	UARTx_TODR_TXDLY_LEN_Pos	8	/* �����ӳ٣����255baud */
#define	UARTx_TODR_TXDLY_LEN_Msk	(0xffU << UARTx_TODR_TXDLY_LEN_Pos)

#define	UARTx_TODR_RXTO_LEN_Pos	0	/* ���ճ�ʱ������ȣ����255baud */
#define	UARTx_TODR_RXTO_LEN_Msk	(0xffU << UARTx_TODR_RXTO_LEN_Pos)

#define	UARTx_RXBUF_RXBUF_Pos	0	/* �������ݻ���Ĵ������� */
#define	UARTx_RXBUF_RXBUF_Msk	(0x1ffU << UARTx_RXBUF_RXBUF_Pos)

#define	UARTx_TXBUF_TXBUF_Pos	0	/* �������ݻ���Ĵ������� */
#define	UARTx_TXBUF_TXBUF_Msk	(0x1ffU << UARTx_TXBUF_TXBUF_Pos)

#define	UARTx_BRG_SPBRG_Pos	0	/* �����ʲ������Ĵ���ֵ */
#define	UARTx_BRG_SPBRG_Msk	(0xffffU << UARTx_BRG_SPBRG_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void UART_Deinit(void);

/* ���ƺ�����Ʒ�������ʱ��Ĭ��������� (Infra Red Flag)
0��������
1�������� ��غ��� */
extern void UARTIR_CR_IRFLAG_Set(uint32_t SetValue);
extern uint32_t UARTIR_CR_IRFLAG_Get(void);

/* ����ռ�ձȵ��Ʋ��� (Tranmission High Duty) ��غ��� */
extern void UARTIR_CR_TH_Set(uint32_t SetValue);
extern uint32_t UARTIR_CR_TH_Get(void);

/* �������Ƶ�� (Transmission Baud Rate) ��غ��� */
extern void UARTIR_CR_TZBRG_Set(uint32_t SetValue);
extern uint32_t UARTIR_CR_TZBRG_Get(void);
extern void UARTx_Deinit(UART_Type* UARTx);

/* UARTͨ�ű�־��ֻ��
1��UART����ͨ����
0��UART���� ��غ��� */
extern FlagStatus UARTx_CSR_BUSY_Chk(UART_Type* UARTx);

/* ���ͺ������ʹ��
1��ʹ�ܺ�����Ʒ���
0���رպ�����Ʒ��� ��غ��� */
extern void UARTx_CSR_TXIREN_Setable(UART_Type* UARTx, FunState NewState);
extern FunState UARTx_CSR_TXIREN_Getable(UART_Type* UARTx);

/* ���ճ�ʱʹ��
1��ʹ�ܽ��ճ�ʱ����
0���رս��ճ�ʱ���� ��غ��� */
extern void UARTx_CSR_RXTOEN_Setable(UART_Type* UARTx, FunState NewState);
extern FunState UARTx_CSR_RXTOEN_Getable(UART_Type* UARTx);

/* RX��TX���Ž���
0��Ĭ������˳�����װͼһ�£�
1����������˳�� ��غ��� */
extern void UARTx_CSR_IOSWAP_Set(UART_Type* UARTx, uint32_t SetValue);
extern uint32_t UARTx_CSR_IOSWAP_Get(UART_Type* UARTx);

/* DMA��������ж�ʹ�ܣ�����UARTͨ��DMA���з���ʱ��Ч
1��IE=1������£�DMAģʽ�·��������һ֡�������ж��ź���������һ֮֡ǰ������֡������ɺ������ж��ź����
0���Ƿ������ж��ź��������IE���� ��غ��� */
extern void UARTx_CSR_DMATXIFCFG_Setable(UART_Type* UARTx, FunState NewState);
extern FunState UARTx_CSR_DMATXIFCFG_Getable(UART_Type* UARTx);

/* ���ݷ���/����ʱ��λ˳��
0��LSB first
1��MSB first ��غ��� */
extern void UARTx_CSR_BITORD_Set(UART_Type* UARTx, uint32_t SetValue);
extern uint32_t UARTx_CSR_BITORD_Get(UART_Type* UARTx);

/* ֹͣλ������ã����Է���֡��ʽ��Ч������ʱ���ж�ֹͣλ����
0��1λֹͣλ
1��2λֹͣλ ��غ��� */
extern void UARTx_CSR_STOPCFG_Set(UART_Type* UARTx, uint32_t SetValue);
extern uint32_t UARTx_CSR_STOPCFG_Get(UART_Type* UARTx);

/* ÿ֡�����ݳ���ѡ�񣻴˼Ĵ��������ݷ��ͺͽ���ͬʱ��Ч
00��7λ����
01��8λ����
10��9λ����
11��6λ���� ��غ��� */
extern void UARTx_CSR_PDSEL_Set(UART_Type* UARTx, uint32_t SetValue);
extern uint32_t UARTx_CSR_PDSEL_Get(UART_Type* UARTx);

/* У��λ���ã��˼Ĵ��������ݷ��ͺͽ���ͬʱ��Ч
00����У��λ
01��żУ��
10����У��
11��RFU ��غ��� */
extern void UARTx_CSR_PARITY_Set(UART_Type* UARTx, uint32_t SetValue);
extern uint32_t UARTx_CSR_PARITY_Get(UART_Type* UARTx);

/* �������ݼ�������
0������
1��ȡ�� ��غ��� */
extern void UARTx_CSR_RXPOL_Setable(UART_Type* UARTx,FunState NewState);
extern FunState UARTx_CSR_RXPOL_Getable(UART_Type* UARTx);

/* �������ݼ�������
0������
1��ȡ�� ��غ��� */
extern void UARTx_CSR_TXPOL_Setable(UART_Type* UARTx, FunState NewState);
extern FunState UARTx_CSR_TXPOL_Getable(UART_Type* UARTx);

/* ����ʹ�ܣ�1��Ч ��غ��� */
extern void UARTx_CSR_RXEN_Setable(UART_Type* UARTx, FunState NewState);
extern FunState UARTx_CSR_RXEN_Getable(UART_Type* UARTx);

/* ����ʹ�ܣ�1��Ч ��غ��� */
extern void UARTx_CSR_TXEN_Setable(UART_Type* UARTx, FunState NewState);
extern FunState UARTx_CSR_TXEN_Getable(UART_Type* UARTx);

/* ���ճ�ʱ�ж�ʹ�ܣ�1��Ч
����UART0��UART1��Ч�� ��غ��� */
extern void UARTx_IER_RXTO_IE_Setable(UART_Type* UARTx, FunState NewState);
extern FunState UARTx_IER_RXTO_IE_Getable(UART_Type* UARTx);

/* ���մ����ж�ʹ�ܣ�1��Ч ��غ��� */
extern void UARTx_IER_RXERR_IE_Setable(UART_Type* UARTx, FunState NewState);
extern FunState UARTx_IER_RXERR_IE_Getable(UART_Type* UARTx);

/* ���ջ������ж�ʹ�ܣ�1��Ч ��غ��� */
extern void UARTx_IER_RXBF_IE_Setable(UART_Type* UARTx, FunState NewState);
extern FunState UARTx_IER_RXBF_IE_Getable(UART_Type* UARTx);

/* RX�½����첽����ж�ʹ�ܣ�1��Ч����UART0��UART1��Ч�� ��غ��� */
extern void UARTx_IER_NEWUP_IE_Setable(UART_Type* UARTx, FunState NewState);
extern FunState UARTx_IER_NEWUP_IE_Getable(UART_Type* UARTx);

/* ���ͻ�����ж�ʹ�ܣ�1��Ч ��غ��� */
extern void UARTx_IER_TXBE_IE_Setable(UART_Type* UARTx, FunState NewState);
extern FunState UARTx_IER_TXBE_IE_Getable(UART_Type* UARTx);

/* ���ͻ�����ҷ�����λ�Ĵ������ж�ʹ�ܣ�1��Ч ��غ��� */
extern void UARTx_IER_TXSE_IE_Setable(UART_Type* UARTx, FunState NewState);
extern FunState UARTx_IER_TXSE_IE_Getable(UART_Type* UARTx);

/* ��żУ������жϱ�־��Ӳ����λ�����д1���� ��غ��� */
extern void UARTx_ISR_PERR_Clr(UART_Type* UARTx);
extern FlagStatus UARTx_ISR_PERR_Chk(UART_Type* UARTx);

/* ֡��ʽ�����жϱ�־��Ӳ����λ�����д1���� ��غ��� */
extern void UARTx_ISR_FERR_Clr(UART_Type* UARTx);
extern FlagStatus UARTx_ISR_FERR_Chk(UART_Type* UARTx);

/* ���ջ�����������жϱ�־�������ջ�����������£��յ��µ�����ʱ��λ��Ӳ����λ�����д1���߶�ȡRXBUFʱ����
�������ʱ�����ջ�������ԭ�е����ݱ������ݸ��ǡ� ��غ��� */
extern void UARTx_ISR_OERR_Clr(UART_Type* UARTx);
extern FlagStatus UARTx_ISR_OERR_Chk(UART_Type* UARTx);

/* ���ճ�ʱ�жϱ�־��Ӳ����λ�����д1����
����UART0��UART1��Ч�� ��غ��� */
extern void UARTx_ISR_RXTO_Clr(UART_Type* UARTx);
extern FlagStatus UARTx_ISR_RXTO_Chk(UART_Type* UARTx);

/* ���ջ������жϱ�־��Ӳ����λ�����д1���߶�ȡRXBUFʱ���� ��غ��� */
extern void UARTx_ISR_RXBF_Clr(UART_Type* UARTx);
extern FlagStatus UARTx_ISR_RXBF_Chk(UART_Type* UARTx);

/* RX�½����첽����жϱ�־��Ӳ����λ�����д1����
����UART0��UART1��Ч�� ��غ��� */
extern void UARTx_ISR_NEWKF_Clr(UART_Type* UARTx);
extern FlagStatus UARTx_ISR_NEWKF_Chk(UART_Type* UARTx);

/* ���ͻ�����жϱ�־��Ӳ����λ�����д��TXBUFʱ���� ��غ��� */
extern FlagStatus UARTx_ISR_TXBE_Chk(UART_Type* UARTx);

/* ���ͻ��������λ�Ĵ�����������жϱ�־��Ӳ����λ�����д1�������д���ͻ���ʱ���� ��غ��� */
extern void UARTx_ISR_TXSE_Clr(UART_Type* UARTx);
extern FlagStatus UARTx_ISR_TXSE_Chk(UART_Type* UARTx);

/* �����ӳ٣����255baud ��غ��� */
extern void UARTx_TODR_TXDLY_LEN_Set(UART_Type* UARTx, uint32_t SetValue);
extern uint32_t UARTx_TODR_TXDLY_LEN_Get(UART_Type* UARTx);

/* ���ճ�ʱ������ȣ����255baud ��غ��� */
extern void UARTx_TODR_RXTO_LEN_Set(UART_Type* UARTx, uint32_t SetValue);
extern uint32_t UARTx_TODR_RXTO_LEN_Get(UART_Type* UARTx);

/* �������ݻ���Ĵ������� ��غ��� */
extern uint32_t UARTx_RXBUF_Read(UART_Type* UARTx);

/* �������ݻ���Ĵ������� ��غ��� */
extern void UARTx_TXBUF_Write(UART_Type* UARTx, uint32_t SetValue);
extern uint32_t UARTx_TXBUF_Read(UART_Type* UARTx);

/* �����ʲ������Ĵ���ֵ ��غ��� */
extern void UARTx_BGR_Write(UART_Type* UARTx, uint32_t SetValue);
extern uint32_t UARTx_BGR_Read(UART_Type* UARTx);

extern uint32_t UART_BaudREGCalc(uint32_t BaudRate, uint32_t Clk);
extern void UART_IRModulation_Init( uint32_t ModuFreq, uint8_t ModuDutyCycle, uint32_t Clk );
extern void UART_Init(UART_Type* UARTx, UART_InitTypeDef* para);
extern void UART_SInit(UART_Type* UARTx, UART_SInitTypeDef* para,CMU_ClocksType* CMU_Clocks);

//Announce_End
#ifdef __cplusplus
}
#endif

#endif /*__FM33A0XXEV_UART_H */
