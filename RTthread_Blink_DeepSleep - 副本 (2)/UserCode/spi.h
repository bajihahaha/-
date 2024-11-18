#ifndef __SPI_H
#define __SPI_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33A0XXEV.h" 
void Flash_Spi1_Init(void);
void SpiWrite(uint8_t *data, uint32_t length);
void SpiRead(uint8_t *data, uint32_t length);
     
#ifdef __cplusplus
}
#endif

#endif 

