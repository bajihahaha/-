#include "define_all.h"  
#include "flash.h"
#include "spi.h"

// д��Flash�ĺ���
void FlashWrite(uint16_t pageAddress, uint8_t byteAddress, uint8_t *data, uint32_t length) 
{
    //���� Buffer 1 Write ����
    uint8_t cmd = 0x84;  // ������
		uint8_t Dummy;
		uint8_t byteAddr = byteAddress;
		uint8_t pageAddrHigh;
		uint8_t pageAddrLow;
    SpiWrite(&cmd, 1);

    //����ҳ��ַ (A19 - A8)+4Dummy Bits=16Dummy Bits
    SpiWrite(&Dummy, 1);
		SpiWrite(&Dummy, 1);

    //�����ֽڵ�ַ (A7 - A0)
    // A7 - A0
    SpiWrite(&byteAddr, 1);

    //��������
    SpiWrite(data, length);

    //���� Buffer 1 to Main Memory Program ����
    cmd = 0x83;  // ������
    SpiWrite(&cmd, 1);
		pageAddrHigh = (pageAddress >> 8) & 0xFF; // ��8λ
		pageAddrLow = (pageAddress & 0xFF); // ��8
		SpiWrite(&pageAddrHigh, 1);
    SpiWrite(&pageAddrLow, 1);
		//8Dummy
		SpiWrite(&pageAddrLow, 1);
}

// ��Flash��ȡ���ݵĺ���
void Flash_PageRead(uint16_t pageAddress,uint8_t *data) 
{		
		uint8_t pageAddrHigh;
		uint8_t pageAddrLow;
		uint8_t byteAddr;
    //���� Main Memory Page Read ����
    uint8_t cmd = 0xD2;  // ������
    SpiWrite(&cmd, 1);

    //����ҳ��ַ XXXX,A19-A16
    pageAddrHigh = (pageAddress >> 8) & 0xFF; // ��8λ
		//A15-A8
    pageAddrLow = (pageAddress & 0xFF); // ��8
    SpiWrite(&pageAddrHigh, 1);
    SpiWrite(&pageAddrLow, 1);

    //��㷢���ֽڵ�ַ (A7 - A0)
    byteAddr = pageAddrLow;  //����ҳ��ַ�ĵ�8λ�ٷ�һ��
    SpiWrite(&byteAddr, 1);

    //��ȡ����
    SpiRead(data,256);
}

