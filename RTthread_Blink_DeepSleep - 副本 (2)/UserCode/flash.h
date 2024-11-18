#ifndef __FLASH_H
#define __FLASH_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33A0XXEV.h" 
#include "define_all.h"  


void FlashWrite(uint16_t pageAddress, uint8_t byteAddress, uint8_t *data, uint32_t length);
void Flash_PageRead(uint16_t pageAddress,uint8_t *data);
     
#ifdef __cplusplus
}
#endif

#endif 
