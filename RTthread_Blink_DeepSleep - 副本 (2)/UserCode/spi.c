#include "define_all.h"  
#include "spi.h"
void Flash_Spi1_Init(void)
{
    CMU_PERCLK_SetableEx(SPI1CLK, ENABLE);   //����SPI1����ʱ��
  
    SPIx_CR1_IOSWAP_Set(SPI1, SPIx_CR1_IOSWAP_DEFAULT);  // MISO��MOSIĬ������ ������
    SPIx_CR1_MM_Set(SPI1, SPIx_CR1_MM_MASTER);           //masterģʽ
    SPIx_CR1_WAIT_Set(SPI1, SPIx_CR1_WAIT_1WAIT);        // ÿ������һ֡�����һ��CLK
    SPIx_CR1_BAUD_Set(SPI1, SPIx_CR1_BAUD_DIV2);         //����������Ϊ����ʱ��2��Ƶ
    SPIx_CR1_LSBF_Set(SPI1, SPIx_CR1_LSBF_MSB);          //֡��ʽ�ȷ���MSB
    SPIx_CR1_CPHOL_Set(SPI1, SPIx_CR1_CPHOL_LOW);        //CLKֹͣ�ڵ͵�ƽ
    SPIx_CR1_CPHA_Set(SPI1, SPIx_CR1_CPHA_1CLOCK);       //��һ��ʱ�ӱ��ز�׽
    SPIx_CR2_SSNSEN_Setable(SPI1, DISABLE);                 //SSN��Ӳ���Զ�����

    SPIx_CR2_RXO_Setable(SPI1, DISABLE);                 //SPI����Ϊȫ˫��
    SPIx_CR2_DLEN_Set(SPI1, SPIx_CR2_DLEN_8BIT);         //ͨ�������ֳ�8bit
    SPIx_CR2_HALFDUPLEX_Set(SPI1, SPIx_CR2_HALFDUPLEX_SPI); //SPI����Ϊ��׼SPIģʽ
    SPIx_CR2_SSNM_Set(SPI1, SPIx_CR2_SSNM_LOW);             //ÿ�η���master��ssn���ֵ�
    SPIx_CR2_TXO_AC_Setable(SPI1, DISABLE);                 //�ر�TXONLY�Զ���0
    SPIx_CR2_TXO_Setable(SPI1, DISABLE);                    //�ر�TXONLYģʽ
    SPIx_CR2_SSN_Set(SPI1, SPIx_CR2_SSN_LOW);               //SSNSENΪ��ʱSNN����͵�ƽ
    
    SPIx_CR3_SERRC_Clr(SPI1);             //����ӻ������־
    SPIx_CR3_MERRC_Clr(SPI1);             //������������־
    SPIx_CR3_RXBFC_Clr(SPI1);             //���RXBUF
    SPIx_CR3_TXBFC_Clr(SPI1);             //���TXBUF
    
    SPIx_CR2_SPIEN_Setable(SPI1, ENABLE);          //ʹ��SPI1
    
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


