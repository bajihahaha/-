/**
  ******************************************************************************
  * @file    fm33a0xxev_aes.h
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file contains all the functions prototypes for the AES firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33A0XXEV_AES_H
#define __FM33A0XXEV_AES_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33A0XXEV.h" 

//------------------------------------------------------------------------------   
typedef struct
{
	uint32_t	KEYLEN;			//AES������Կ���ȣ�AESEN=1ʱ�����޸�
	uint32_t	CHMOD;			//AES����������ģʽ��AESEN=1ʱ�����޸�
	uint32_t	MODE;			//AES����ģʽ��AESEN=1ʱ�����޸�
	uint32_t	DATATYP;		//ѡ���������ͣ�AESEN=1ʱ�����޸ġ����彻������ɲο�AES���������½�	
	FunState	DMAOEN;			//DMA�����Զ�����ʹ��
	FunState	DMAIEN;			//DMA�����Զ�д��ʹ��
	FunState	WERRIE;			//�����־��WRERR���ж�ʹ��
	FunState	RERRIE;			//�����־��RDERR���ж�ʹ��
	FunState	CCFIE;			//CCF��־�ж�ʹ��
	FunState	AESEN;			//AESʹ�� 
	
}AES_InitTypeDef;
	 
#define	AES_CR_KEYLEN_Pos	13	/* AES������Կ���ȣ�AESEN=1ʱ�����޸ġ�
(Key Length)
00��128bit
01��192bit
10��256bit
11������ */
#define	AES_CR_KEYLEN_Msk	(0x3U << AES_CR_KEYLEN_Pos)
#define	AES_CR_KEYLEN_128BIT	(0x0U << AES_CR_KEYLEN_Pos)	/* 128bit */
#define	AES_CR_KEYLEN_192BIT	(0x1U << AES_CR_KEYLEN_Pos)	/* 192bit */
#define	AES_CR_KEYLEN_256BIT	(0x2U << AES_CR_KEYLEN_Pos)	/* 256bit */
#define	AES_CR_KEYLEN_	(0x3U << AES_CR_KEYLEN_Pos)	/* ���� */

#define	AES_CR_DMAOEN_Pos	12	/* DMA�����Զ�����ʹ��
(DMA output enable)
0��������
1������
��λ��λ����ģʽ1��ģʽ3��ģʽ4��AESģ����Զ�����AES->RAM�Ĵ�������ģʽ2�²�������� */
#define	AES_CR_DMAOEN_Msk	(0x1U << AES_CR_DMAOEN_Pos)


#define	AES_CR_DMAIEN_Pos	11	/* ����DMA�����Զ�д��ʹ��
(DMA input enable)
0��������
1������
��λ����Ϊ1����ģʽ1��ģʽ3��ģʽ4�Լ�MultHģʽ��AESģ����Զ�����RAM->AES�Ĵ�������ģʽ2�²�������� */
#define	AES_CR_DMAIEN_Msk	(0x1U << AES_CR_DMAIEN_Pos)


#define	AES_CR_CHMOD_Pos	5	/* AES����������ģʽ��AESEN=1ʱ�����޸ġ�
(Cipher Mode)
00��ECB
01��CBC
10��CTR
11��ʹ��MultHģ�� */
#define	AES_CR_CHMOD_Msk	(0x3U << AES_CR_CHMOD_Pos)
#define	AES_CR_CHMOD_ECB	(0x0U << AES_CR_CHMOD_Pos)	/* ECB */
#define	AES_CR_CHMOD_CBC	(0x1U << AES_CR_CHMOD_Pos)	/* CBC */
#define	AES_CR_CHMOD_CTR	(0x2U << AES_CR_CHMOD_Pos)	/* CTR */
#define	AES_CR_CHMOD_MULTH	(0x3U << AES_CR_CHMOD_Pos)	/* ʹ��MultHģ�� */

#define	AES_CR_MODE_Pos	3	/* AES����ģʽ��AESEN=1ʱ�����޸ġ�
(operation MODE)
00��ģʽ1������
01��ģʽ2����Կ��չ
10��ģʽ3������
11��ģʽ4����Կ��չ+����
CTRģʽ�����ó�ģʽ4���Զ�����CTR�Ľ���ģʽ������CHMOD=2��b10ʱ����MODE=2��b11��AES������MODE=2��b10������ִ�С� */
#define	AES_CR_MODE_Msk	(0x3U << AES_CR_MODE_Pos)
#define	AES_CR_MODE_ENCRYPT	(0x0U << AES_CR_MODE_Pos)	/* ģʽ1 */
#define	AES_CR_MODE_KEYEXP	(0x1U << AES_CR_MODE_Pos)	/* ģʽ2 */
#define	AES_CR_MODE_DECRYPT	(0x2U << AES_CR_MODE_Pos)	/* ģʽ3 */
#define	AES_CR_MODE_KEYEXPDECRYPT	(0x3U << AES_CR_MODE_Pos)	/* ģʽ4 */

#define	AES_CR_DATATYP_Pos	1	/* ѡ���������ͣ�AESEN=1ʱ�����޸ġ����彻������ɲο�AES���������½ڡ�
(Data type)
00��32bit���ݲ�����
01��16bit���ݰ��ֽ���
10��8bit�����ֽڽ���
11��1bit���ݱ��ؽ��� */
#define	AES_CR_DATATYP_Msk	(0x3U << AES_CR_DATATYP_Pos)
#define	AES_CR_DATATYP_32BITNOEX	(0x0U << AES_CR_DATATYP_Pos)	/* 32bit���ݲ����� */
#define	AES_CR_DATATYP_16BITEX	(0x1U << AES_CR_DATATYP_Pos)	/* 16bit���ݰ��ֽ��� */
#define	AES_CR_DATATYP_8BITEX	(0x2U << AES_CR_DATATYP_Pos)	/* 8bit�����ֽڽ��� */
#define	AES_CR_DATATYP_1BITEX	(0x3U << AES_CR_DATATYP_Pos)	/* 1bit���ݱ��ؽ��� */

#define	AES_CR_EN_Pos	0	/* AESʹ�� (AES enable)
0����ʹ��
1��ʹ��
���κ�ʱ�����AESENλ���ܹ���λAESģ��
��ģʽ2�¸�λ����һ�μ�����ɺ�Ӳ���Զ���0 */
#define	AES_CR_EN_Msk	(0x1U << AES_CR_EN_Pos)
	/* ��ʹ�� */
	/* ʹ�� */

#define	AES_IER_WRERR_IE_Pos	2	/* д�����ж�ʹ�ܣ�1��Ч��(Write Error interrupt enable) */
#define	AES_IER_WRERR_IE_Msk	(0x1U << AES_IER_WRERR_IE_Pos)

#define	AES_IER_RDERR_IE_Pos	1	/* �������ж�ʹ�ܣ�1��Ч��(Read Error interrupt enable) */
#define	AES_IER_RDERR_IE_Msk	(0x1U << AES_IER_RDERR_IE_Pos)

#define	AES_IER_CCF_IE_Pos	0	/* AES��������ж�ʹ�ܣ�1��Ч��(Cipher Complete Interrupt enable) */
#define	AES_IER_CCF_IE_Msk	(0x1U << AES_IER_CCF_IE_Pos)

#define	AES_DIR_DIN_Pos	0	/* ��������Ĵ�������AES��Ҫ����ӽ�������ʱ��Ӧ�����üĴ�������д4�Ρ�(AES Data Input)
ģʽ1�����ܣ��������Ĵ�MSB��LSB��4��д�롣
ģʽ2����Կ��չ��������ʹ����������Ĵ���
ģʽ3��ģʽ4�����ܣ��������Ĵ�MSB��LSB��4��д�롣
MultHģʽ���ѳ���A��C��MSB��LSB��4��д�롣 */
#define	AES_DIR_DIN_Msk	(0xffffffffU << AES_DIR_DIN_Pos)

#define	AES_DOR_DOUT_Pos	0	/* ��������Ĵ�������AES������ɺ󣬿��Է��Ĵζ����ӽ��ܵĽ����(AES Data Output)
ģʽ1�����ܣ��������Ĵ�MSB��LSB��4�ζ�����
ģʽ2����Կ��չ��������ʹ������������Ĵ���
ģʽ3��ģʽ4�����ܣ��������Ĵ�MSB��LSB��4�������
MultHģʽ���������洢��IVR�Ĵ����У������ȡAES_DOUTR�Ĵ����� */
#define	AES_DOR_DOUT_Msk	(0xffffffffU << AES_DOR_DOUT_Pos)

#define	AES_KEY0_KEYx_Pos	0	/* AES������Կ���256bit��AESKEY0�����Կ���32bit��AESLKEY7�����Կ���32bit��(AES Key)
ע�⣺�˼Ĵ������ֻ��д�����ɶ����˼Ĵ������ݲ���WWDT��λӰ�� */
#define	AES_KEY0_KEYx_Msk	(0xffffffffU << AES_KEY0_KEYx_Pos)

#define	AES_KEY1_KEYx_Pos	0	/* AES������Կ���256bit��AESKEY0�����Կ���32bit��AESLKEY7�����Կ���32bit��(AES Key)
ע�⣺�˼Ĵ������ֻ��д�����ɶ����˼Ĵ������ݲ���WWDT��λӰ�� */
#define	AES_KEY1_KEYx_Msk	(0xffffffffU << AES_KEY1_KEYx_Pos)

#define	AES_KEY2_KEYx_Pos	0	/* AES������Կ���256bit��AESKEY0�����Կ���32bit��AESLKEY7�����Կ���32bit��(AES Key)
ע�⣺�˼Ĵ������ֻ��д�����ɶ����˼Ĵ������ݲ���WWDT��λӰ�� */
#define	AES_KEY2_KEYx_Msk	(0xffffffffU << AES_KEY2_KEYx_Pos)

#define	AES_KEY3_KEYx_Pos	0	/* AES������Կ���256bit��AESKEY0�����Կ���32bit��AESLKEY7�����Կ���32bit��(AES Key)
ע�⣺�˼Ĵ������ֻ��д�����ɶ����˼Ĵ������ݲ���WWDT��λӰ�� */
#define	AES_KEY3_KEYx_Msk	(0xffffffffU << AES_KEY3_KEYx_Pos)

#define	AES_KEY4_KEYx_Pos	0	/* AES������Կ���256bit��AESKEY0�����Կ���32bit��AESLKEY7�����Կ���32bit��(AES Key)
ע�⣺�˼Ĵ������ֻ��д�����ɶ����˼Ĵ������ݲ���WWDT��λӰ�� */
#define	AES_KEY4_KEYx_Msk	(0xffffffffU << AES_KEY4_KEYx_Pos)

#define	AES_KEY5_KEYx_Pos	0	/* AES������Կ���256bit��AESKEY0�����Կ���32bit��AESLKEY7�����Կ���32bit��(AES Key)
ע�⣺�˼Ĵ������ֻ��д�����ɶ����˼Ĵ������ݲ���WWDT��λӰ�� */
#define	AES_KEY5_KEYx_Msk	(0xffffffffU << AES_KEY5_KEYx_Pos)

#define	AES_KEY6_KEYx_Pos	0	/* AES������Կ���256bit��AESKEY0�����Կ���32bit��AESLKEY7�����Կ���32bit��(AES Key)
ע�⣺�˼Ĵ������ֻ��д�����ɶ����˼Ĵ������ݲ���WWDT��λӰ�� */
#define	AES_KEY6_KEYx_Msk	(0xffffffffU << AES_KEY6_KEYx_Pos)

#define	AES_KEY7_KEYx_Pos	0	/* AES������Կ���256bit��AESKEY0�����Կ���32bit��AESLKEY7�����Կ���32bit��(AES Key)
ע�⣺�˼Ĵ������ֻ��д�����ɶ����˼Ĵ������ݲ���WWDT��λӰ�� */
#define	AES_KEY7_KEYx_Msk	(0xffffffffU << AES_KEY7_KEYx_Pos)

#define	AES_IVR0_IVRx_Pos	0	/* AES����128bit��ʼ��������MultHģʽ�±�����������
(AES Initial Vector Registers) */
#define	AES_IVR0_IVRx_Msk	(0xffffffffU << AES_IVR0_IVRx_Pos)

#define	AES_IVR1_IVRx_Pos	0	/* AES����128bit��ʼ��������MultHģʽ�±�����������
(AES Initial Vector Registers) */
#define	AES_IVR1_IVRx_Msk	(0xffffffffU << AES_IVR1_IVRx_Pos)

#define	AES_IVR2_IVRx_Pos	0	/* AES����128bit��ʼ��������MultHģʽ�±�����������
(AES Initial Vector Registers) */
#define	AES_IVR2_IVRx_Msk	(0xffffffffU << AES_IVR2_IVRx_Pos)

#define	AES_IVR3_IVRx_Pos	0	/* AES����128bit��ʼ��������MultHģʽ�±�����������
(AES Initial Vector Registers) */
#define	AES_IVR3_IVRx_Msk	(0xffffffffU << AES_IVR3_IVRx_Pos)

#define	AES_H0_Hx_Pos	0	/* MultH����128bit����H���� (H Parameter)
H0����H[31:0]��H3����H[127:96] */
#define	AES_H0_Hx_Msk	(0xffffffffU << AES_H0_Hx_Pos)

#define	AES_H1_Hx_Pos	0	/* MultH����128bit����H���� (H Parameter)
H0����H[31:0]��H3����H[127:96] */
#define	AES_H1_Hx_Msk	(0xffffffffU << AES_H1_Hx_Pos)

#define	AES_H2_Hx_Pos	0	/* MultH����128bit����H���� (H Parameter)
H0����H[31:0]��H3����H[127:96] */
#define	AES_H2_Hx_Msk	(0xffffffffU << AES_H2_Hx_Pos)

#define	AES_H3_Hx_Pos	0	/* MultH����128bit����H���� (H Parameter)
H0����H[31:0]��H3����H[127:96] */
#define	AES_H3_Hx_Msk	(0xffffffffU << AES_H3_Hx_Pos)

#define	AES_ISR_WRERR_Pos	2	/* д�����־���ڼ��������׶η���д����ʱ��λ�����д1���� */
#define	AES_ISR_WRERR_Msk	(0x1U << AES_ISR_WRERR_Pos)

#define	AES_ISR_RDERR_Pos	1	/* �������־���ڼ��������׶η���������ʱ��λ�����д1���� */
#define	AES_ISR_RDERR_Msk	(0x1U << AES_ISR_RDERR_Pos)

#define	AES_ISR_CCF_Pos	0	/* AES������ɱ�־�����д1����
1���������
0������û����� */
#define	AES_ISR_CCF_Msk	(0x1U << AES_ISR_CCF_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void AES_Deinit(void);

/* AES������Կ���ȣ�AESEN=1ʱ�����޸ġ�
(Key Length)
00��128bit
01��192bit
10��256bit
11������ ��غ��� */
extern void AES_CR_KEYLEN_Set(uint32_t SetValue);
extern uint32_t AES_CR_KEYLEN_Get(void);

/* DMA�����Զ�����ʹ��
(DMA output enable)
0��������
1������
��λ��λ����ģʽ1��ģʽ3��ģʽ4��AESģ����Զ�����AES->RAM�Ĵ�������ģʽ2�²�������� ��غ��� */
extern void AES_CR_DMAOEN_Setable(FunState NewState);
extern FunState AES_CR_DMAOEN_Getable(void);


/* ����DMA�����Զ�д��ʹ��
(DMA input enable)
0��������
1������
��λ����Ϊ1����ģʽ1��ģʽ3��ģʽ4�Լ�MultHģʽ��AESģ����Զ�����RAM->AES�Ĵ�������ģʽ2�²�������� ��غ��� */
extern void AES_CR_DMAIEN_Setable(FunState NewState);
extern FunState FunStateAES_CR_DMAIEN_Getable(void);

/* AES����������ģʽ��AESEN=1ʱ�����޸ġ�
(Cipher Mode)
00��ECB
01��CBC
10��CTR
11��ʹ��MultHģ�� ��غ��� */
extern void AES_CR_CHMOD_Set(uint32_t SetValue);
extern uint32_t AES_CR_CHMOD_Get(void);

/* AES����ģʽ��AESEN=1ʱ�����޸ġ�
(operation MODE)
00��ģʽ1������
01��ģʽ2����Կ��չ
10��ģʽ3������
11��ģʽ4����Կ��չ+����
CTRģʽ�����ó�ģʽ4���Զ�����CTR�Ľ���ģʽ������CHMOD=2��b10ʱ����MODE=2��b11��AES������MODE=2��b10������ִ�С� ��غ��� */
extern void AES_CR_MODE_Set(uint32_t SetValue);
extern uint32_t AES_CR_MODE_Get(void);

/* ѡ���������ͣ�AESEN=1ʱ�����޸ġ����彻������ɲο�AES���������½ڡ�
(Data type)
00��32bit���ݲ�����
01��16bit���ݰ��ֽ���
10��8bit�����ֽڽ���
11��1bit���ݱ��ؽ��� ��غ��� */
extern void AES_CR_DATATYP_Set(uint32_t SetValue);
extern uint32_t AES_CR_DATATYP_Get(void);

/* AESʹ�� (AES enable)
0����ʹ��
1��ʹ��
���κ�ʱ�����AESENλ���ܹ���λAESģ��
��ģʽ2�¸�λ����һ�μ�����ɺ�Ӳ���Զ���0 ��غ��� */
extern void AES_CR_EN_Setable(FunState NewState);
extern FunState AES_CR_EN_Getable(void);

/* д�����ж�ʹ�ܣ�1��Ч��(Write Error interrupt enable) ��غ��� */
extern void AES_IER_WRERR_IE_Setable(FunState NewState);
extern FunState AES_IER_WRERR_IE_Getable(void);

/* �������ж�ʹ�ܣ�1��Ч��(Read Error interrupt enable) ��غ��� */
extern void AES_IER_RDERR_IE_Setable(FunState NewState);
extern FunState AES_IER_RDERR_IE_Getable(void);

/* AES��������ж�ʹ�ܣ�1��Ч��(Cipher Complete Interrupt enable) ��غ��� */
extern void AES_IER_CCF_IE_Setable(FunState NewState);
extern FunState AES_IER_CCF_IE_Getable(void);

/* ��������Ĵ�������AES��Ҫ����ӽ�������ʱ��Ӧ�����üĴ�������д4�Ρ�(AES Data Input)
ģʽ1�����ܣ��������Ĵ�MSB��LSB��4��д�롣
ģʽ2����Կ��չ��������ʹ����������Ĵ���
ģʽ3��ģʽ4�����ܣ��������Ĵ�MSB��LSB��4��д�롣
MultHģʽ���ѳ���A��C��MSB��LSB��4��д�롣 ��غ��� */
extern void AES_DIR_Write(uint32_t SetValue);
extern uint32_t AES_DIR_Read(void);

/* ��������Ĵ�������AES������ɺ󣬿��Է��Ĵζ����ӽ��ܵĽ����(AES Data Output)
ģʽ1�����ܣ��������Ĵ�MSB��LSB��4�ζ�����
ģʽ2����Կ��չ��������ʹ������������Ĵ���
ģʽ3��ģʽ4�����ܣ��������Ĵ�MSB��LSB��4�������
MultHģʽ���������洢��IVR�Ĵ����У������ȡAES_DOUTR�Ĵ����� ��غ��� */
extern uint32_t AES_DOR_Read(void);

/* AES������Կ���256bit��AESKEY0�����Կ���32bit��AESLKEY7�����Կ���32bit��(AES Key)
ע�⣺�˼Ĵ������ֻ��д�����ɶ����˼Ĵ������ݲ���WWDT��λӰ�� ��غ��� */
extern void AES_KEY0_Write(uint32_t SetValue);

/* AES������Կ���256bit��AESKEY0�����Կ���32bit��AESLKEY7�����Կ���32bit��(AES Key)
ע�⣺�˼Ĵ������ֻ��д�����ɶ����˼Ĵ������ݲ���WWDT��λӰ�� ��غ��� */
extern void AES_KEY1_Write(uint32_t SetValue);

/* AES������Կ���256bit��AESKEY0�����Կ���32bit��AESLKEY7�����Կ���32bit��(AES Key)
ע�⣺�˼Ĵ������ֻ��д�����ɶ����˼Ĵ������ݲ���WWDT��λӰ�� ��غ��� */
extern void AES_KEY2_Write(uint32_t SetValue);

/* AES������Կ���256bit��AESKEY0�����Կ���32bit��AESLKEY7�����Կ���32bit��(AES Key)
ע�⣺�˼Ĵ������ֻ��д�����ɶ����˼Ĵ������ݲ���WWDT��λӰ�� ��غ��� */
extern void AES_KEY3_Write(uint32_t SetValue);

/* AES������Կ���256bit��AESKEY0�����Կ���32bit��AESLKEY7�����Կ���32bit��(AES Key)
ע�⣺�˼Ĵ������ֻ��д�����ɶ����˼Ĵ������ݲ���WWDT��λӰ�� ��غ��� */
extern void AES_KEY4_Write(uint32_t SetValue);

/* AES������Կ���256bit��AESKEY0�����Կ���32bit��AESLKEY7�����Կ���32bit��(AES Key)
ע�⣺�˼Ĵ������ֻ��д�����ɶ����˼Ĵ������ݲ���WWDT��λӰ�� ��غ��� */
extern void AES_KEY5_Write(uint32_t SetValue);

/* AES������Կ���256bit��AESKEY0�����Կ���32bit��AESLKEY7�����Կ���32bit��(AES Key)
ע�⣺�˼Ĵ������ֻ��д�����ɶ����˼Ĵ������ݲ���WWDT��λӰ�� ��غ��� */
extern void AES_KEY6_Write(uint32_t SetValue);

/* AES������Կ���256bit��AESKEY0�����Կ���32bit��AESLKEY7�����Կ���32bit��(AES Key)
ע�⣺�˼Ĵ������ֻ��д�����ɶ����˼Ĵ������ݲ���WWDT��λӰ�� ��غ��� */
extern void AES_KEY7_Write(uint32_t SetValue);

/* AES����128bit��ʼ��������MultHģʽ�±�����������
(AES Initial Vector Registers) ��غ��� */
extern void AES_IVR0_Write(uint32_t SetValue);
extern uint32_t AES_IVR0_Read(void);

/* AES����128bit��ʼ��������MultHģʽ�±�����������
(AES Initial Vector Registers) ��غ��� */
extern void AES_IVR1_Write(uint32_t SetValue);
extern uint32_t AES_IVR1_Read(void);

/* AES����128bit��ʼ��������MultHģʽ�±�����������
(AES Initial Vector Registers) ��غ��� */
extern void AES_IVR2_Write(uint32_t SetValue);
extern uint32_t AES_IVR2_Read(void);

/* AES����128bit��ʼ��������MultHģʽ�±�����������
(AES Initial Vector Registers) ��غ��� */
extern void AES_IVR3_Write(uint32_t SetValue);
extern uint32_t AES_IVR3_Read(void);

/* MultH����128bit����H���� (H Parameter)
H0����H[31:0]��H3����H[127:96] ��غ��� */
extern void AES_H0_Write(uint32_t SetValue);
extern uint32_t AES_H0_Read(void);

/* MultH����128bit����H���� (H Parameter)
H0����H[31:0]��H3����H[127:96] ��غ��� */
extern void AES_H1_Write(uint32_t SetValue);
extern uint32_t AES_H1_Read(void);

/* MultH����128bit����H���� (H Parameter)
H0����H[31:0]��H3����H[127:96] ��غ��� */
extern void AES_H2_Write(uint32_t SetValue);
extern uint32_t AES_H2_Read(void);

/* MultH����128bit����H���� (H Parameter)
H0����H[31:0]��H3����H[127:96] ��غ��� */
extern void AES_H3_Write(uint32_t SetValue);
extern uint32_t AES_H3_Read(void);

/* д�����־���ڼ��������׶η���д����ʱ��λ�����д1���� ��غ��� */
extern void AES_ISR_WRERR_Clr(void);
extern FlagStatus AES_ISR_WRERR_Chk(void);

/* �������־���ڼ��������׶η���������ʱ��λ�����д1���� ��غ��� */
extern void AES_ISR_RDERR_Clr(void);
extern FlagStatus AES_ISR_RDERR_Chk(void);

/* AES������ɱ�־�����д1����
1���������
0������û����� ��غ��� */
extern void AES_ISR_CCF_Clr(void);
extern FlagStatus AES_ISR_CCF_Chk(void);
//Announce_End


extern void AES_KEY_WriteEx(uint8_t *KeyIn, uint8_t Len);
extern void AES_IVR_WriteEx(uint8_t *IVRIn);
extern void AES_IVR_ReadEx(uint8_t *IVROut);
extern void AES_DIN_GroupWrite_128BIT(uint8_t *DataIn);
extern void AES_DOUT_GroupRead_128BIT(uint8_t *DataOut);
extern uint8_t AES_GroupWriteAndRead_128BIT(uint8_t *DataIn, uint8_t *DataOut);
extern uint8_t AES_GroupWriteAndRead_128BIT_IVR(uint8_t *DataIn, uint8_t *DataOut);
extern void AES_Init(AES_InitTypeDef* para);
extern void AES_Hx_WriteEx(uint8_t *HxIn, uint8_t Len);
extern void AES_Hx_ReadEx(uint8_t *HxOut, uint8_t Len);

#ifdef __cplusplus
}
#endif

#endif /*__FM33A0XXEV_AES_H */
