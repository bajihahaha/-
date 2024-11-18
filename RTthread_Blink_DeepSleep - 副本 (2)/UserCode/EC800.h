#ifndef __EC800_H
#define __EC800_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33A0XXEV.h" 
#include "define_all.h" 
#include "uart.h"
#include "bt16.h"
#include "string.h"

extern uint8_t Is_connected;
extern int  AT_IS_OverTime;
extern uint8_t Signal_Strength;
extern uint8_t Is_connecting;
extern uint8_t ICCID[20];
int  Connect();
void Send_AT_Command(char flag);
void Disconnect();
     
#ifdef __cplusplus
}
#endif

#endif 
