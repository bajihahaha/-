#include "define_all.h"  
#include "spi.h"
void Flash_Spi1_Init(void)
{
    CMU_PERCLK_SetableEx(SPI1CLK, ENABLE);   //开启SPI1总线时钟
  
    SPIx_CR1_IOSWAP_Set(SPI1, SPIx_CR1_IOSWAP_DEFAULT);  // MISO、MOSI默认引脚 不交换
    SPIx_CR1_MM_Set(SPI1, SPIx_CR1_MM_MASTER);           //master模式
    SPIx_CR1_WAIT_Set(SPI1, SPIx_CR1_WAIT_1WAIT);        // 每发送完一帧后插入一个CLK
    SPIx_CR1_BAUD_Set(SPI1, SPIx_CR1_BAUD_DIV2);         //波特率设置为外设时钟2分频
    SPIx_CR1_LSBF_Set(SPI1, SPIx_CR1_LSBF_MSB);          //帧格式先发送MSB
    SPIx_CR1_CPHOL_Set(SPI1, SPIx_CR1_CPHOL_LOW);        //CLK停止在低电平
    SPIx_CR1_CPHA_Set(SPI1, SPIx_CR1_CPHA_1CLOCK);       //第一个时钟边沿捕捉
    SPIx_CR2_SSNSEN_Setable(SPI1, DISABLE);                 //SSN由硬件自动控制

    SPIx_CR2_RXO_Setable(SPI1, DISABLE);                 //SPI设置为全双工
    SPIx_CR2_DLEN_Set(SPI1, SPIx_CR2_DLEN_8BIT);         //通信数据字长8bit
    SPIx_CR2_HALFDUPLEX_Set(SPI1, SPIx_CR2_HALFDUPLEX_SPI); //SPI设置为标准SPI模式
    SPIx_CR2_SSNM_Set(SPI1, SPIx_CR2_SSNM_LOW);             //每次发完master后ssn保持低
    SPIx_CR2_TXO_AC_Setable(SPI1, DISABLE);                 //关闭TXONLY自动清0
    SPIx_CR2_TXO_Setable(SPI1, DISABLE);                    //关闭TXONLY模式
    SPIx_CR2_SSN_Set(SPI1, SPIx_CR2_SSN_LOW);               //SSNSEN为１时SNN输出低电平
    
    SPIx_CR3_SERRC_Clr(SPI1);             //清除从机错误标志
    SPIx_CR3_MERRC_Clr(SPI1);             //清除主机错误标志
    SPIx_CR3_RXBFC_Clr(SPI1);             //清除RXBUF
    SPIx_CR3_TXBFC_Clr(SPI1);             //清除TXBUF
    
    SPIx_CR2_SPIEN_Setable(SPI1, ENABLE);          //使能SPI1
    
    AltFunIO(GPIOC, GPIO_Pin_6, ALTFUN_NORMAL);    // SSN
    AltFunIO(GPIOC, GPIO_Pin_7, ALTFUN_NORMAL);    // SCK
    AltFunIO(GPIOC, GPIO_Pin_8, ALTFUN_NORMAL);    // MISO
    AltFunIO(GPIOC, GPIO_Pin_9, ALTFUN_NORMAL);    // MOSI
}

uint32_t SpiWriteAndRead(uint32_t data)
{
    SPIx_TXBUF_Write(SPI1, data);
    while (!SPIx_ISR_TXBE_Chk(SPI1));
    while (!SPIx_ISR_RXBF_Chk(SPI1));
    data = SPIx_RXBUF_Read(SPI1);
    
    return data;
}

	void SpiWrite(uint8_t *data, uint32_t length)
	{
			while (length--)
			{
					SpiWriteAndRead(*data);
					data++;
			}
	}

	void SpiRead(uint8_t *data, uint32_t length)
	{
			while (length--)
			{
					*data = SpiWriteAndRead(0x00);
					data++;
			}
	}

//uint8_t wBuff[8] = {0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x7f, 0xff};
//uint8_t rBuff[8];

//int main (void)
//{	
//	Init_System();
//    SpiInit();
//    
//    SpiWrite(wBuff, 8);
//    SpiRead(rBuff, 8);
//    
//	while(1)
//    {
//        IWDT_Clr();
//        
//        LED0_TOG;
//        TicksDelayMs(1000, NULL);
//    }
//}


