#ifndef __RTC_H
#define __RTC_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33A0XXEV.h" 
#include "define_all.h"  
void RTC_Init(void);
void RTC_Alarm(RTC_AlarmTmieTypeDef TempAlarmTime);
uint08 RTC_GetRTC(RTC_TimeDateTypeDef* para);
uint08 RTC_SetRTC(RTC_TimeDateTypeDef* para);

     
#ifdef __cplusplus
}
#endif

#endif 
