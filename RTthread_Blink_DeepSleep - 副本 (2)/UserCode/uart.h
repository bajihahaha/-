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
extern  uint8_t GPRS_RX_Buffer[BUFFER_SIZE];//接收缓冲区
extern uint8_t GPRS_TX_Buffer[BUFFER_SIZE];//发送缓冲区
extern volatile uint16_t GPRS_rx_index;//
extern volatile uint16_t GPRS_recv_lenth;//接收数据的目标长度
extern volatile uint8_t GPRS_tx_index;
extern volatile uint8_t GPRS_tx_length;//发送数据的目标长度

extern uint8_t EVC_RX_Buffer[BUFFER_SIZE];//接收缓冲区
extern uint8_t EVC_TX_Buffer[BUFFER_SIZE];//发送缓冲区
extern volatile uint16_t EVC_rx_index;//
extern volatile uint16_t EVC_recv_lenth;//接收数据的目标长度
extern volatile uint8_t EVC_tx_index;
extern volatile uint8_t EVC_tx_length;//发送数据的目标长度

extern volatile uint8_t GPRS_recv_state; // 0 = 等待标志, 1 = 等待长度, 2 = 接收数据
extern uint8_t EVC_byte;
extern rt_sem_t sem_EVC_Uart_Revice;
extern volatile uint8_t EVC_recv_state; // 0 = 等待标志, 1 = 等待功能码, 2 = 等待长度，3=接收数据
extern uint8_t ADDR_CODE;//EVC地址码
extern uint8_t GPRS_byte;

void Uartx_Enable(UART_Type* UARTx);
void Uartx_Init(UART_Type* UARTx,uint32_t	BaudRate,UART_DataBitTypeDef DataBit,UART_ParityBitTypeDef ParityBit,UART_StopBitTypeDef StopBit);
void UART5_Send();
void UART4_Send();

#ifdef __cplusplus
}
#endif

#endif 
