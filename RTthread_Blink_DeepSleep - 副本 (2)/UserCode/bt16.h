#ifndef __BT16_H
#define __BT16_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33A0XXEV.h" 
#include "define_all.h" 
#include "EC800.h"

void BtimerStart(BT_Type* BTx);
void BtimerInit(BT_Type* BTx,int time_second);
void BtimerStop(BT_Type* BTx);

     
#ifdef __cplusplus
}
#endif

#endif 

