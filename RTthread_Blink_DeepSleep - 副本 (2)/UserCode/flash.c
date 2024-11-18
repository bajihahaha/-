#include "define_all.h"  
#include "flash.h"
#include "spi.h"

// 写入Flash的函数
void FlashWrite(uint16_t pageAddress, uint8_t byteAddress, uint8_t *data, uint32_t length) 
{
    //发送 Buffer 1 Write 命令
    uint8_t cmd = 0x84;  // 操作码
		uint8_t Dummy;
		uint8_t byteAddr = byteAddress;
		uint8_t pageAddrHigh;
		uint8_t pageAddrLow;
    SpiWrite(&cmd, 1);

    //发送页地址 (A19 - A8)+4Dummy Bits=16Dummy Bits
    SpiWrite(&Dummy, 1);
		SpiWrite(&Dummy, 1);

    //发送字节地址 (A7 - A0)
    // A7 - A0
    SpiWrite(&byteAddr, 1);

    //发送数据
    SpiWrite(data, length);

    //发送 Buffer 1 to Main Memory Program 命令
    cmd = 0x83;  // 操作码
    SpiWrite(&cmd, 1);
		pageAddrHigh = (pageAddress >> 8) & 0xFF; // 高8位
		pageAddrLow = (pageAddress & 0xFF); // 低8
		SpiWrite(&pageAddrHigh, 1);
    SpiWrite(&pageAddrLow, 1);
		//8Dummy
		SpiWrite(&pageAddrLow, 1);
}

// 从Flash读取数据的函数
void Flash_PageRead(uint16_t pageAddress,uint8_t *data) 
{		
		uint8_t pageAddrHigh;
		uint8_t pageAddrLow;
		uint8_t byteAddr;
    //发送 Main Memory Page Read 命令
    uint8_t cmd = 0xD2;  // 操作码
    SpiWrite(&cmd, 1);

    //发送页地址 XXXX,A19-A16
    pageAddrHigh = (pageAddress >> 8) & 0xFF; // 高8位
		//A15-A8
    pageAddrLow = (pageAddress & 0xFF); // 低8
    SpiWrite(&pageAddrHigh, 1);
    SpiWrite(&pageAddrLow, 1);

    //随便发送字节地址 (A7 - A0)
    byteAddr = pageAddrLow;  //就拿页地址的低8位再发一次
    SpiWrite(&byteAddr, 1);

    //读取数据
    SpiRead(data,256);
}

