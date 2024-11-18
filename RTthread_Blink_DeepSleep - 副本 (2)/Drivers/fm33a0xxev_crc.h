/**
  ******************************************************************************
  * @file    fm33a0xxev_crc.h
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file contains all the functions prototypes for the CRC firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33A0XXEV_CRC_H
#define __FM33A0XXEV_CRC_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33A0XXEV.h" 
	 
typedef struct
{       	
	uint32_t			CRCSEL;		/*!<CRCУ�����ʽλ��ѡ��*/
	uint32_t 			OPWD;	    /*!<WORD����ʹ��*/
	uint32_t            PARA;		/*!<CRC���ټ���ʹ��*/
	uint32_t			RFLTIN;		/*!<CRC���뷴ת����*/
	uint32_t			RFLTO;		/*!<CRC�����ת����*/
	FunState			XOR;		/*!<������ʹ��*/
	uint32_t			CRC_XOR;	/*!<���������Ĵ���*/
	uint32_t 			CRCPOLY;	/*!<CRC����ʽ�Ĵ���*/
	uint32_t			LFSR;		/*!<CRC��ʼֵ*/
}CRC_InitTypeDef;

#define	CRC_DR_DR_Pos	0	/* CRCDR������Ϊ��������Ĵ�������������������󱣴�CRC��������(CRC Data Register)
��Ϊ����ʱ����word����ʹ�ܣ����CRCDR[31:0]���м��㣬��4��byte���㣨�ɵ͵��ߣ��������CRCDR[7:0]���м��㣬��1��byte���㡣
������ʱ����Ϊ7λ����ʽ���������CRCDR[6:0]����Ϊ8λ����ʽ���������CRCDR[7:0]����Ϊ16λ����ʽ���������CRCDR[15:0]����Ϊ32λ����ʽ���������CRCDR[31:0]�� */
#define	CRC_DR_DR_Msk	(0xffffffffU << CRC_DR_DR_Pos)

#define	CRC_CR_OPWD_Pos	9	/* WORD����ʹ�� (Operation by Word)
0���ֽڲ�����CRC��������CRCDR����ֽڽ���
1���ֲ�����CRC�������CRCDRȫ��4�ֽڽ��� */
#define	CRC_CR_OPWD_Msk	(0x1U << CRC_CR_OPWD_Pos)
#define	CRC_CR_OPWD_BYTE	(0x0U << CRC_CR_OPWD_Pos)	/* �ֽڲ�����CRC��������CRCDR����ֽڽ��� */
#define	CRC_CR_OPWD_WORD	(0x1U << CRC_CR_OPWD_Pos)	/* �ֲ�����CRC�������CRCDRȫ��4�ֽڽ��� */

#define	CRC_CR_PARA_Pos	8	/* CRC���ټ���ʹ�� (Parallel Calculation)
0���������㣬����1���ֽ���Ҫ8��ʱ������
1�����м��㣬����1���ֽ���Ҫ1��ʱ������ */
#define	CRC_CR_PARA_Msk	(0x1U << CRC_CR_PARA_Pos)
#define	CRC_CR_PARA_SERIAL	(0x0U << CRC_CR_PARA_Pos)	/* �������㣬����1���ֽ���Ҫ8��ʱ������ */
#define	CRC_CR_PARA_PARALLEL	(0x1U << CRC_CR_PARA_Pos)	/* ���м��㣬����1���ֽ���Ҫ1��ʱ������ */

#define	CRC_CR_RFLTIN_Pos	6	/* CRC���뷴ת���� (Reflected Input)
00�����벻��ת
01�����밴�ֽڷ�ת
10�����밴���ַ�ת
11�����밴�ַ�ת
���磺��������Ϊ0x11223344��
���RFLTIN==01�������ݱ�Ϊ0x8844CC22���ٽ��м������RFLTIN==10�������ݱ�Ϊ0x448822CC���ٽ��м���
���RFLTIN==11�������ݱ�Ϊ0x22CC4488���ٽ��м��� */
#define	CRC_CR_RFLTIN_Msk	(0x3U << CRC_CR_RFLTIN_Pos)
#define	CRC_CR_RFLTIN_NONE	(0x0U << CRC_CR_RFLTIN_Pos)	/* ���벻��ת */
#define	CRC_CR_RFLTIN_BYTE	(0x1U << CRC_CR_RFLTIN_Pos)	/* ���밴�ֽڷ�ת */
#define	CRC_CR_RFLTIN_HALFWORD	(0x2U << CRC_CR_RFLTIN_Pos)	/* ���밴���ַ�ת */
#define	CRC_CR_RFLTIN_WORD	(0x3U << CRC_CR_RFLTIN_Pos)	/* ���밴�ַ�ת */

#define	CRC_CR_RFLTO_Pos	5	/* CRC�����ת���� (Reflected Output)
0�����벻��ת
1�����밴�ֽڷ�ת
���磺
���RFLTO==1������ǰ�����CRC���Ϊ0x1234��������Ľ��Ϊ0x2C48��� RFLTO==0����ֱ�����0x1234ע�⣺�˽����һ��Ϊ����������������Ҫ��XOR�Ƿ�Ϊ1��������Ĵ���bit2˵�� */
#define	CRC_CR_RFLTO_Msk	(0x1U << CRC_CR_RFLTO_Pos)
#define	CRC_CR_RFLTO_NON	(0x0U << CRC_CR_RFLTO_Pos)	/* ���벻��ת */
#define	CRC_CR_RFLTO_BYTE	(0x1U << CRC_CR_RFLTO_Pos)	/* ���밴�ֽڷ�ת */

#define	CRC_CR_RES_Pos	4	/* CRC�����־λ��ֻ�� (Result Flag)
0��CRC���Ϊ0
1��CRC�����ȫ0 */
#define	CRC_CR_RES_Msk	(0x1U << CRC_CR_RES_Pos)

#define	CRC_CR_BUSY_Pos	3	/* CRC�����־λ��ֻ�� (Busy)
0��CRC�������
1��CRC��������� */
#define	CRC_CR_BUSY_Msk	(0x1U << CRC_CR_BUSY_Pos)

#define	CRC_CR_XOR_Pos	2	/* ������ʹ�� (Output XORed with CRC_XOR register enable)
0����������CRC_XOR�Ĵ���
1��������CRC_XOR�Ĵ��� */
#define	CRC_CR_XOR_Msk	(0x1U << CRC_CR_XOR_Pos)
	/* ��������CRC_XOR�Ĵ��� */
	/* ������CRC_XOR�Ĵ��� */

#define	CRC_CR_SEL_Pos	0	/* CRC����ʽλ��ѡ�� (Polynomial width Selection)
00��32λ
01��16λ
10��8λ
11��7λ */
#define	CRC_CR_SEL_Msk	(0x3U << CRC_CR_SEL_Pos)
#define	CRC_CR_SEL_CRC32	(0x0U << CRC_CR_SEL_Pos)	/* 32λ */
#define	CRC_CR_SEL_CRC16	(0x1U << CRC_CR_SEL_Pos)	/* 16λ */
#define	CRC_CR_SEL_CRC8	(0x2U << CRC_CR_SEL_Pos)	/* 8λ */
#define	CRC_CR_SEL_CRC7	(0x3U << CRC_CR_SEL_Pos)	/* 7λ */

#define	CRC_LFSR_LFSR_Pos	0	/* CRC���Է�����λ�Ĵ��� (Linear Feedback Shift Register)
���㿪ʼǰ���������д��CRC��ʼֵ */
#define	CRC_LFSR_LFSR_Msk	(0xffffffffU << CRC_LFSR_LFSR_Pos)

#define	CRC_XOR_XOR_Pos	0	/* CRC���������Ĵ��� (eXclusive OR)
��CRC_CR.XORΪ1ʱ��CRC������ǰ�����˼Ĵ��������ݡ� */
#define	CRC_XOR_XOR_Msk	(0xffffffffU << CRC_XOR_XOR_Pos)

#define	CRC_POLY_POLY_Pos	0	/* CRC�������ʽϵ�� (CRC Polynominals) */
#define	CRC_POLY_POLY_Msk	(0xffffffffU << CRC_POLY_POLY_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void CRC_Deinit(void);

/* CRCDR������Ϊ��������Ĵ�������������������󱣴�CRC��������(CRC Data Register)
��Ϊ����ʱ����word����ʹ�ܣ����CRCDR[31:0]���м��㣬��4��byte���㣨�ɵ͵��ߣ��������CRCDR[7:0]���м��㣬��1��byte���㡣
������ʱ����Ϊ7λ����ʽ���������CRCDR[6:0]����Ϊ8λ����ʽ���������CRCDR[7:0]����Ϊ16λ����ʽ���������CRCDR[15:0]����Ϊ32λ����ʽ���������CRCDR[31:0]�� ��غ��� */
extern void CRC_DR_Write(uint32_t SetValue);
extern uint32_t CRC_DR_Read(void);

/* WORD����ʹ�� (Operation by Word)
0���ֽڲ�����CRC��������CRCDR����ֽڽ���
1���ֲ�����CRC�������CRCDRȫ��4�ֽڽ��� ��غ��� */
extern void CRC_CR_OPWD_Set(uint32_t SetValue);
extern uint32_t CRC_CR_OPWD_Get(void);

/* CRC���ټ���ʹ�� (Parallel Calculation)
0���������㣬����1���ֽ���Ҫ8��ʱ������
1�����м��㣬����1���ֽ���Ҫ1��ʱ������ ��غ��� */
extern void CRC_CR_PARA_Set(uint32_t SetValue);
extern uint32_t CRC_CR_PARA_Get(void);

/* CRC���뷴ת���� (Reflected Input)
00�����벻��ת
01�����밴�ֽڷ�ת
10�����밴���ַ�ת
11�����밴�ַ�ת
���磺��������Ϊ0x11223344��
���RFLTIN==01�������ݱ�Ϊ0x8844CC22���ٽ��м������RFLTIN==10�������ݱ�Ϊ0x448822CC���ٽ��м���
���RFLTIN==11�������ݱ�Ϊ0x22CC4488���ٽ��м��� ��غ��� */
extern void CRC_CR_RFLTIN_Set(uint32_t SetValue);
extern uint32_t CRC_CR_RFLTIN_Get(void);

/* CRC�����ת���� (Reflected Output)
0�����벻��ת
1�����밴�ֽڷ�ת
���磺
���RFLTO==1������ǰ�����CRC���Ϊ0x1234��������Ľ��Ϊ0x2C48��� RFLTO==0����ֱ�����0x1234ע�⣺�˽����һ��Ϊ����������������Ҫ��XOR�Ƿ�Ϊ1��������Ĵ���bit2˵�� ��غ��� */
extern void CRC_CR_RFLTO_Set(uint32_t SetValue);
extern uint32_t CRC_CR_RFLTO_Get(void);

/* CRC�����־λ��ֻ�� (Result Flag)
0��CRC���Ϊ0
1��CRC�����ȫ0 ��غ��� */
extern FlagStatus CRC_CR_RES_Chk(void);

/* CRC�����־λ��ֻ�� (Busy)
0��CRC�������
1��CRC��������� ��غ��� */
extern FlagStatus CRC_CR_BUSY_Chk(void);

/* ������ʹ�� (Output XORed with CRC_XOR register enable)
0����������CRC_XOR�Ĵ���
1��������CRC_XOR�Ĵ��� ��غ��� */
extern void CRC_CR_XOR_Setable(FunState NewState);
extern FunState CRC_CR_XOR_Getable(void);

/* CRC����ʽλ��ѡ�� (Polynomial width Selection)
00��32λ
01��16λ
10��8λ
11��7λ ��غ��� */
extern void CRC_CR_SEL_Set(uint32_t SetValue);
extern uint32_t CRC_CR_SEL_Get(void);

/* CRC���Է�����λ�Ĵ��� (Linear Feedback Shift Register)
���㿪ʼǰ���������д��CRC��ʼֵ ��غ��� */
extern void CRC_LFSR_Write(uint32_t SetValue);
extern uint32_t CRC_LFSR_Read(void);

/* CRC���������Ĵ��� (eXclusive OR)
��CRC_CR.XORΪ1ʱ��CRC������ǰ�����˼Ĵ��������ݡ� ��غ��� */
extern void CRC_XOR_Write(uint32_t SetValue);
extern uint32_t CRC_XOR_Read(void);

/* CRC�������ʽϵ�� (CRC Polynominals) ��غ��� */
extern void CRC_POLY_Write(uint32_t SetValue);
extern uint32_t CRC_POLY_Read(void);
//Announce_End
extern void CRC_Init(CRC_InitTypeDef* para);
#ifdef __cplusplus
}
#endif

#endif /* __FM33A0XXEV_CRC_H */
