#ifndef __UART_H
#define __UART_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33A0XXEV.h" 
#include "define_all.h" 
#include "rtthread.h"
#include "EC800.h"


extern rt_sem_t sem_GPRS_Uart_Revice;
extern  uint8_t GPRS_RX_Buffer[BUFFER_SIZE];//���ջ�����
extern uint8_t GPRS_TX_Buffer[BUFFER_SIZE];//���ͻ�����
extern volatile uint16_t GPRS_rx_index;//
extern volatile uint16_t GPRS_recv_lenth;//�������ݵ�Ŀ�곤��
extern volatile uint8_t GPRS_tx_index;
extern volatile uint8_t GPRS_tx_length;//�������ݵ�Ŀ�곤��

extern uint8_t EVC_RX_Buffer[BUFFER_SIZE];//���ջ�����
extern uint8_t EVC_TX_Buffer[BUFFER_SIZE];//���ͻ�����
extern volatile uint16_t EVC_rx_index;//
extern volatile uint16_t EVC_recv_lenth;//�������ݵ�Ŀ�곤��
extern volatile uint8_t EVC_tx_index;
extern volatile uint8_t EVC_tx_length;//�������ݵ�Ŀ�곤��

extern volatile uint8_t GPRS_recv_state; // 0 = �ȴ���־, 1 = �ȴ�����, 2 = ��������
extern uint8_t EVC_byte;
extern rt_sem_t sem_EVC_Uart_Revice;
extern volatile uint8_t EVC_recv_state; // 0 = �ȴ���־, 1 = �ȴ�������, 2 = �ȴ����ȣ�3=��������
extern uint8_t ADDR_CODE;//EVC��ַ��
extern uint8_t GPRS_byte;

void Uartx_Enable(UART_Type* UARTx);
void Uartx_Init(UART_Type* UARTx,uint32_t	BaudRate,UART_DataBitTypeDef DataBit,UART_ParityBitTypeDef ParityBit,UART_StopBitTypeDef StopBit);
void UART5_Send();
void UART4_Send();

#ifdef __cplusplus
}
#endif

#endif 
