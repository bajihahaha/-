/**
  ******************************************************************************
  * @file    fm33a0xxev_aes.c
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/

#include "fm33a0xxev_aes.h"

/** @addtogroup fm33a0xxev_StdPeriph_Driver
  * @{
  */

/** @defgroup AES 
  * @brief AES driver modules
  * @{
  */ 
  
/* AES������Կ���ȣ�AESEN=1ʱ�����޸ġ�
(Key Length)
00��128bit
01��192bit
10��256bit
11������ ��غ��� */
void AES_CR_KEYLEN_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = AES->CR;
	tmpreg &= ~(AES_CR_KEYLEN_Msk);
	tmpreg |= (SetValue & AES_CR_KEYLEN_Msk);
	AES->CR = tmpreg;
}

uint32_t AES_CR_KEYLEN_Get(void)
{
	return (AES->CR & AES_CR_KEYLEN_Msk);
}

/* DMA�����Զ�����ʹ��
(DMA output enable)
0��������
1������
��λ��λ����ģʽ1��ģʽ3��ģʽ4��AESģ����Զ�����AES->RAM�Ĵ�������ģʽ2�²�������� ��غ��� */
void AES_CR_DMAOEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		AES->CR |= (AES_CR_DMAOEN_Msk);
	}
	else
	{
		AES->CR &= ~(AES_CR_DMAOEN_Msk);
	}

}

FunState AES_CR_DMAOEN_Getable(void)
{
	if (AES->CR & (AES_CR_DMAOEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ����DMA�����Զ�д��ʹ��
(DMA input enable)
0��������
1������
��λ����Ϊ1����ģʽ1��ģʽ3��ģʽ4�Լ�MultHģʽ��AESģ����Զ�����RAM->AES�Ĵ�������ģʽ2�²�������� ��غ��� */
/* AESʹ�� (AES enable)
0����ʹ��
1��ʹ��
���κ�ʱ�����AESENλ���ܹ���λAESģ��
��ģʽ2�¸�λ����һ�μ�����ɺ�Ӳ���Զ���0 ��غ��� */

void AES_CR_DMAIEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		AES->CR |= (AES_CR_DMAIEN_Msk);
	}
	else
	{
		AES->CR &= ~(AES_CR_DMAIEN_Msk);
	}
}

FunState AES_CR_DMAIEN_Getable(void)
{
	if (AES->CR & (AES_CR_DMAIEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* AES����������ģʽ��AESEN=1ʱ�����޸ġ�
(Cipher Mode)
00��ECB
01��CBC
10��CTR
11��ʹ��MultHģ�� ��غ��� */
void AES_CR_CHMOD_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = AES->CR;
	tmpreg &= ~(AES_CR_CHMOD_Msk);
	tmpreg |= (SetValue & AES_CR_CHMOD_Msk);
	AES->CR = tmpreg;
}

uint32_t AES_CR_CHMOD_Get(void)
{
	return (AES->CR & AES_CR_CHMOD_Msk);
}

/* AES����ģʽ��AESEN=1ʱ�����޸ġ�
(operation MODE)
00��ģʽ1������
01��ģʽ2����Կ��չ
10��ģʽ3������
11��ģʽ4����Կ��չ+����
CTRģʽ�����ó�ģʽ4���Զ�����CTR�Ľ���ģʽ������CHMOD=2��b10ʱ����MODE=2��b11��AES������MODE=2��b10������ִ�С� ��غ��� */
void AES_CR_MODE_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = AES->CR;
	tmpreg &= ~(AES_CR_MODE_Msk);
	tmpreg |= (SetValue & AES_CR_MODE_Msk);
	AES->CR = tmpreg;
}

uint32_t AES_CR_MODE_Get(void)
{
	return (AES->CR & AES_CR_MODE_Msk);
}

/* ѡ���������ͣ�AESEN=1ʱ�����޸ġ����彻������ɲο�AES���������½ڡ�
(Data type)
00��32bit���ݲ�����
01��16bit���ݰ��ֽ���
10��8bit�����ֽڽ���
11��1bit���ݱ��ؽ��� ��غ��� */
void AES_CR_DATATYP_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = AES->CR;
	tmpreg &= ~(AES_CR_DATATYP_Msk);
	tmpreg |= (SetValue & AES_CR_DATATYP_Msk);
	AES->CR = tmpreg;
}

uint32_t AES_CR_DATATYP_Get(void)
{
	return (AES->CR & AES_CR_DATATYP_Msk);
}

/* AESʹ�� (AES enable)
0����ʹ��
1��ʹ��
���κ�ʱ�����AESENλ���ܹ���λAESģ��
��ģʽ2�¸�λ����һ�μ�����ɺ�Ӳ���Զ���0 ��غ��� */
void AES_CR_EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		AES->CR |= (AES_CR_EN_Msk);
	}
	else
	{
		AES->CR &= ~(AES_CR_EN_Msk);
	}
}

FunState AES_CR_EN_Getable(void)
{
	if (AES->CR & (AES_CR_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* д�����ж�ʹ�ܣ�1��Ч��(Write Error interrupt enable) ��غ��� */
void AES_IER_WRERR_IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		AES->IER |= (AES_IER_WRERR_IE_Msk);
	}
	else
	{
		AES->IER &= ~(AES_IER_WRERR_IE_Msk);
	}
}

FunState AES_IER_WRERR_IE_Getable(void)
{
	if (AES->IER & (AES_IER_WRERR_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �������ж�ʹ�ܣ�1��Ч��(Read Error interrupt enable) ��غ��� */
void AES_IER_RDERR_IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		AES->IER |= (AES_IER_RDERR_IE_Msk);
	}
	else
	{
		AES->IER &= ~(AES_IER_RDERR_IE_Msk);
	}
}

FunState AES_IER_RDERR_IE_Getable(void)
{
	if (AES->IER & (AES_IER_RDERR_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* AES��������ж�ʹ�ܣ�1��Ч��(Cipher Complete Interrupt enable) ��غ��� */
void AES_IER_CCF_IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		AES->IER |= (AES_IER_CCF_IE_Msk);
	}
	else
	{
		AES->IER &= ~(AES_IER_CCF_IE_Msk);
	}
}

FunState AES_IER_CCF_IE_Getable(void)
{
	if (AES->IER & (AES_IER_CCF_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��������Ĵ�������AES��Ҫ����ӽ�������ʱ��Ӧ�����üĴ�������д4�Ρ�(AES Data Input)
ģʽ1�����ܣ��������Ĵ�MSB��LSB��4��д�롣
ģʽ2����Կ��չ��������ʹ����������Ĵ���
ģʽ3��ģʽ4�����ܣ��������Ĵ�MSB��LSB��4��д�롣
MultHģʽ���ѳ���A��C��MSB��LSB��4��д�롣 ��غ��� */
void AES_DIR_Write(uint32_t SetValue)
{
	AES->DIR = (SetValue);
}

uint32_t AES_DIR_Read(void)
{
	return (AES->DIR);
}

/* ��������Ĵ�������AES������ɺ󣬿��Է��Ĵζ����ӽ��ܵĽ����(AES Data Output)
ģʽ1�����ܣ��������Ĵ�MSB��LSB��4�ζ�����
ģʽ2����Կ��չ��������ʹ������������Ĵ���
ģʽ3��ģʽ4�����ܣ��������Ĵ�MSB��LSB��4�������
MultHģʽ���������洢��IVR�Ĵ����У������ȡAES_DOUTR�Ĵ����� ��غ��� */
uint32_t AES_DOR_Read(void)
{
	return (AES->DOR);
}

/* AES������Կ���256bit��AESKEY0�����Կ���32bit��AESLKEY7�����Կ���32bit��(AES Key)
ע�⣺�˼Ĵ������ֻ��д�����ɶ����˼Ĵ������ݲ���WWDT��λӰ�� ��غ��� */
void AES_KEY0_Write(uint32_t SetValue)
{
	AES->KEY0 = (SetValue);
}

/* AES������Կ���256bit��AESKEY0�����Կ���32bit��AESLKEY7�����Կ���32bit��(AES Key)
ע�⣺�˼Ĵ������ֻ��д�����ɶ����˼Ĵ������ݲ���WWDT��λӰ�� ��غ��� */
void AES_KEY1_Write(uint32_t SetValue)
{
	AES->KEY1 = (SetValue);
}

/* AES������Կ���256bit��AESKEY0�����Կ���32bit��AESLKEY7�����Կ���32bit��(AES Key)
ע�⣺�˼Ĵ������ֻ��д�����ɶ����˼Ĵ������ݲ���WWDT��λӰ�� ��غ��� */
void AES_KEY2_Write(uint32_t SetValue)
{
	AES->KEY2 = (SetValue);
}

/* AES������Կ���256bit��AESKEY0�����Կ���32bit��AESLKEY7�����Կ���32bit��(AES Key)
ע�⣺�˼Ĵ������ֻ��д�����ɶ����˼Ĵ������ݲ���WWDT��λӰ�� ��غ��� */
void AES_KEY3_Write(uint32_t SetValue)
{
	AES->KEY3 = (SetValue);
}

/* AES������Կ���256bit��AESKEY0�����Կ���32bit��AESLKEY7�����Կ���32bit��(AES Key)
ע�⣺�˼Ĵ������ֻ��д�����ɶ����˼Ĵ������ݲ���WWDT��λӰ�� ��غ��� */
void AES_KEY4_Write(uint32_t SetValue)
{
	AES->KEY4 = (SetValue);
}

/* AES������Կ���256bit��AESKEY0�����Կ���32bit��AESLKEY7�����Կ���32bit��(AES Key)
ע�⣺�˼Ĵ������ֻ��д�����ɶ����˼Ĵ������ݲ���WWDT��λӰ�� ��غ��� */
void AES_KEY5_Write(uint32_t SetValue)
{
	AES->KEY5 = (SetValue);
}

/* AES������Կ���256bit��AESKEY0�����Կ���32bit��AESLKEY7�����Կ���32bit��(AES Key)
ע�⣺�˼Ĵ������ֻ��д�����ɶ����˼Ĵ������ݲ���WWDT��λӰ�� ��غ��� */
void AES_KEY6_Write(uint32_t SetValue)
{
	AES->KEY6 = (SetValue);
}

/* AES������Կ���256bit��AESKEY0�����Կ���32bit��AESLKEY7�����Կ���32bit��(AES Key)
ע�⣺�˼Ĵ������ֻ��д�����ɶ����˼Ĵ������ݲ���WWDT��λӰ�� ��غ��� */
void AES_KEY7_Write(uint32_t SetValue)
{
	AES->KEY7 = (SetValue);
}

/* AES����128bit��ʼ��������MultHģʽ�±�����������
(AES Initial Vector Registers) ��غ��� */
void AES_IVR0_Write(uint32_t SetValue)
{
	AES->IVR0 = (SetValue);
}

uint32_t AES_IVR0_Read(void)
{
	return (AES->IVR0);
}

/* AES����128bit��ʼ��������MultHģʽ�±�����������
(AES Initial Vector Registers) ��غ��� */
void AES_IVR1_Write(uint32_t SetValue)
{
	AES->IVR1 = (SetValue);
}

uint32_t AES_IVR1_Read(void)
{
	return (AES->IVR1);
}

/* AES����128bit��ʼ��������MultHģʽ�±�����������
(AES Initial Vector Registers) ��غ��� */
void AES_IVR2_Write(uint32_t SetValue)
{
	AES->IVR2 = (SetValue);
}

uint32_t AES_IVR2_Read(void)
{
	return (AES->IVR2);
}

/* AES����128bit��ʼ��������MultHģʽ�±�����������
(AES Initial Vector Registers) ��غ��� */
void AES_IVR3_Write(uint32_t SetValue)
{
	AES->IVR3 = (SetValue);
}

uint32_t AES_IVR3_Read(void)
{
	return (AES->IVR3);
}

/* MultH����128bit����H���� (H Parameter)
H0����H[31:0]��H3����H[127:96] ��غ��� */
void AES_H0_Write(uint32_t SetValue)
{
	AES->H0 = (SetValue);
}

uint32_t AES_H0_Read(void)
{
	return (AES->H0);
}

/* MultH����128bit����H���� (H Parameter)
H0����H[31:0]��H3����H[127:96] ��غ��� */
void AES_H1_Write(uint32_t SetValue)
{
	AES->H1 = (SetValue);
}

uint32_t AES_H1_Read(void)
{
	return (AES->H1);
}

/* MultH����128bit����H���� (H Parameter)
H0����H[31:0]��H3����H[127:96] ��غ��� */
void AES_H2_Write(uint32_t SetValue)
{
	AES->H2 = (SetValue);
}

uint32_t AES_H2_Read(void)
{
	return (AES->H2);
}

/* MultH����128bit����H���� (H Parameter)
H0����H[31:0]��H3����H[127:96] ��غ��� */
void AES_H3_Write(uint32_t SetValue)
{
	AES->H3 = (SetValue);
}

uint32_t AES_H3_Read(void)
{
	return (AES->H3);
}


/* д�����־���ڼ��������׶η���д����ʱ��λ�����д1���� ��غ��� */
void AES_ISR_WRERR_Clr(void)
{
	AES->ISR = AES_ISR_WRERR_Msk;
}

FlagStatus AES_ISR_WRERR_Chk(void)
{
	if (AES->ISR & AES_ISR_WRERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* �������־���ڼ��������׶η���������ʱ��λ�����д1���� ��غ��� */
void AES_ISR_RDERR_Clr(void)
{
	AES->ISR = AES_ISR_RDERR_Msk;
}

FlagStatus AES_ISR_RDERR_Chk(void)
{
	if (AES->ISR & AES_ISR_RDERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* AES������ɱ�־�����д1����
1���������
0������û����� ��غ��� */
void AES_ISR_CCF_Clr(void)
{
	AES->ISR = AES_ISR_CCF_Msk;
}

FlagStatus AES_ISR_CCF_Chk(void)
{
	if (AES->ISR & AES_ISR_CCF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

void AES_Deinit(void)
{
	//AES->CR = 0x00000000;
	//AES->IER = 0x00000000;
	//AES->DIR = 0x00000000;
	//AES->DOR = 0x00000000;
	//AES->KEY0 = 0x00000000;
	//AES->KEY1 = 0x00000000;
	//AES->KEY2 = 0x00000000;
	//AES->KEY3 = 0x00000000;
	//AES->KEY4 = 0x00000000;
	//AES->KEY5 = 0x00000000;
	//AES->KEY6 = 0x00000000;
	//AES->KEY7 = 0x00000000;
	//AES->IVR0 = 0x00000000;
	//AES->IVR1 = 0x00000000;
	//AES->IVR2 = 0x00000000;
	//AES->IVR3 = 0x00000000;
	//AES->H0 = 0x00000000;
	//AES->H1 = 0x00000000;
	//AES->H2 = 0x00000000;
	//AES->H3 = 0x00000000;
}
//Code_End

/********************************
AES ���ܿ��ƺ���
����: �ӽ�����Կ����(key0�����Կ���32bit)
���룺��Կ	16/24/32�ֽڳ��ȵ���Կ
			����	16/24/32
���: ��
********************************/
void AES_KEY_WriteEx(uint8_t *KeyIn, uint8_t Len)
{
	uint8_t i;
	__IO uint32_t *PointKeyReg;
	__IO uint32_t Temp32;
	
	if( (Len != 16) && (Len != 24) && (Len != 32) ) return;
	if(KeyIn == NULL) return;
    
	PointKeyReg = (&AES->KEY0);
	for(i=0; i<Len; i=i+4)
	{
		Temp32 = (KeyIn[0+i]<<24)|(KeyIn[1+i]<<16)|(KeyIn[2+i]<<8)|(KeyIn[3+i]<<0);
		PointKeyReg[(Len-i)/4-1] = Temp32;
	}
}



/*��ʼ�������� */
void AES_IVR_WriteEx(uint8_t *IVRIn)
{
	uint8_t i;
	__IO uint32_t *PointIvrReg;
	__IO uint32_t Temp32;
	if(IVRIn == NULL) return;
    
	PointIvrReg = (&AES->IVR0);
	for(i=0; i<4*4; i=i+4)
	{
		Temp32 = (IVRIn[0+i]<<24)|(IVRIn[1+i]<<16)|(IVRIn[2+i]<<8)|(IVRIn[3+i]<<0);
		PointIvrReg[(16-i)/4-1] = Temp32;
	}
}

/*��ʼ������ȡ */
void AES_IVR_ReadEx(uint8_t *IVROut)
{
	uint8_t i;
	__IO uint32_t *PointIvrReg;
	__IO uint32_t Temp32;
	
    if(IVROut == NULL) return;
    
	PointIvrReg = (&AES->IVR0);
	for(i=0; i<4*4; i=i+4)
	{
		Temp32 = PointIvrReg[(4*4-i)/4-1];
		IVROut[0+i] = Temp32>>24;
		IVROut[1+i] = Temp32>>16;
		IVROut[2+i] = Temp32>>8;
		IVROut[3+i] = Temp32>>0;	
	}
}


/*�ӽ����������룬16�ֽڣ�128bit��������������  */
void AES_DIN_GroupWrite_128BIT(uint8_t *DataIn)
{
	uint8_t i;
	__IO uint32_t Temp32;

    if(DataIn == NULL) return;
    
	for(i=0; i<16; i=i+4)
	{
		Temp32 = (DataIn[0+i]<<24)|(DataIn[1+i]<<16)|(DataIn[2+i]<<8)|(DataIn[3+i]<<0);
		AES->DIR = Temp32;
	}
}

/*�ӽ������������16�ֽڣ�128bit�������������  */
void AES_DOUT_GroupRead_128BIT(uint8_t *DataOut)
{
	uint8_t i;
	__IO uint32_t Temp32;

    if(DataOut == NULL) return;
    
	for(i=0; i<16; i=i+4)
	{
		Temp32 = AES->DOR;
		DataOut[0+i] = Temp32>>24;
		DataOut[1+i] = Temp32>>16;
		DataOut[2+i] = Temp32>>8;
		DataOut[3+i] = Temp32>>0;
	}
}


uint8_t AES_GroupWriteAndRead_128BIT(uint8_t *DataIn, uint8_t *DataOut)
{	
	uint16_t i;
	
    if((DataIn == NULL) || (DataOut == NULL)) return 1;
    
	//����ӽ�������
	AES_DIN_GroupWrite_128BIT(DataIn);
	
	//�ȴ�CCF��־����,��ɼ����Լ��Ҫ100��ʱ������
	for(i=0;i<500;i++)
	{
		if(SET == AES_ISR_CCF_Chk() ) break;
	}
	//��CCF��־
	//��ȡǰ�������
	AES_ISR_CCF_Clr();
	
	//��ȡ���
	AES_DOUT_GroupRead_128BIT(DataOut);
	
	if(i==500) return 1;
	else return 0;
}


uint8_t AES_GroupWriteAndRead_128BIT_IVR(uint8_t *DataIn, uint8_t *DataOut)
{	
	uint16_t i;
	
    if((DataIn == NULL) || (DataOut == NULL)) return 1;
    
	//����ӽ�������
	AES_DIN_GroupWrite_128BIT(DataIn);
	
	//�ȴ�CCF��־����,��ɼ����Լ��Ҫ100��ʱ������
	for(i=0;i<500;i++)
	{
		if(SET == AES_ISR_CCF_Chk() ) break;
	}
	//��CCF��־
	//��ȡǰ�������
	AES_ISR_CCF_Clr();
	
	//��ȡ���
	AES_IVR_ReadEx(DataOut);
	
	if(i==500) return 1;
	else return 0;
}

/********************************
AES ���ܿ��ƺ���
����: MultH�����Ĵ�������(h0�����Կ���32bit)
���룺MultH����128bit����H����	
���: ��
********************************/
void AES_Hx_WriteEx(uint8_t *HxIn, uint8_t Len)
{
	uint8_t i;
	__IO uint32_t *PointHxReg;
	__IO uint32_t Temp32;
	
	if(Len != 16) return;
    
    if(HxIn == NULL) return;
	
	PointHxReg = (&AES->H0);
	for(i=0; i<Len; i=i+4)
	{
		Temp32 = (HxIn[0+i]<<24)|(HxIn[1+i]<<16)|(HxIn[2+i]<<8)|(HxIn[3+i]<<0);
		PointHxReg[(Len-i)/4-1] = Temp32;
	}
}


/********************************
Hx ������ȡ
����: MultH�����Ĵ�������(h0�����Կ���32bit)
���룺H��������
�����MultH����128bit����H����	
���أ���
********************************/
void AES_Hx_ReadEx(uint8_t *HxOut, uint8_t Len)
{
	uint8_t i;
	__IO uint32_t *PointKeyReg;
	__IO uint32_t Temp32;
	
	if(Len != 16) return;
    
    if(HxOut == NULL)return;
	
	PointKeyReg = (&AES->H0);
	for(i=0; i<Len; i=i+4)
	{
		Temp32 = PointKeyReg[(Len-i)/4-1];
		HxOut[0+i] = Temp32>>24;
		HxOut[1+i] = Temp32>>16;
		HxOut[2+i] = Temp32>>8;
		HxOut[3+i] = Temp32>>0;
	}
}
/* AESģ���ʼ������ */
void AES_Init(AES_InitTypeDef* para)
{
	AES_CR_KEYLEN_Set(para->KEYLEN);			//AES������Կ���ȣ�AESEN=1ʱ�����޸�
	AES_CR_CHMOD_Set(para->CHMOD);			    //AES����������ģʽ��AESEN=1ʱ�����޸�
	AES_CR_MODE_Set(para->MODE);				//AES����ģʽ��AESEN=1ʱ�����޸�
	AES_CR_DATATYP_Set(para->DATATYP);		    //ѡ���������ͣ�AESEN=1ʱ�����޸ġ����彻������ɲο�AES���������½�	
	AES_CR_DMAOEN_Setable(para->DMAOEN);		//DMA�����Զ�����ʹ��
	AES_CR_DMAIEN_Setable(para->DMAIEN);		//DMA�����Զ�д��ʹ��
	AES_IER_WRERR_IE_Setable(para->WERRIE);		//�����־��WRERR���ж�ʹ��
	AES_IER_RDERR_IE_Setable(para->RERRIE);	    //�����־��RDERR���ж�ʹ��
	AES_IER_CCF_IE_Setable(para->CCFIE);	    //CCF��־�ж�ʹ��
	AES_CR_EN_Setable(para->AESEN);			    //AESʹ�� 
}
 
/******END OF FILE****/
