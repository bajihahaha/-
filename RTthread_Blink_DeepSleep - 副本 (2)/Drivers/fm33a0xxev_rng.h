/**
  ******************************************************************************
  * @file    fm33a0xxev_rng.h
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file contains all the functions prototypes for the RNG firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33A0XXEV_RNG_H
#define __FM33A0XXEV_RNG_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33A0XXEV.h" 
   
#define	RNG_CR_EN_Pos	0	/* RNGʹ�ܼĴ��������д1���� (RNG enable)
1������RNG
0���ر�RNG */
#define	RNG_CR_EN_Msk	(0x1U << RNG_CR_EN_Pos)
	/* ����RNG */
	/* �ر�RNG */

#define	RNG_DOR_OUT_Pos	0	/* ��������ɽ����CRC�������Ĵ�����ֻ��
(RNG output) */
#define	RNG_DOR_OUT_Msk	(0xffffffffU << RNG_DOR_OUT_Pos)

#define	RNG_SR_LFSREN_Pos	1	/* LFSR״̬��־��ֻ�� (LFSR enable)
1��LFSR�������У����ɽ���CRC��֤
0��LFSR���������У��ɽ���CRC��֤
ע�����Ĵ�����������ģ���жϣ�������ѯ */
#define	RNG_SR_LFSREN_Msk	(0x1U << RNG_SR_LFSREN_Pos)
	/* LFSR�������У����ɽ���CRC��֤ */
	/* LFSR���������У��ɽ���CRC��֤ */
	/* ���Ĵ�����������ģ���жϣ�������ѯ */

#define	RNG_SR_RNF_Pos	0	/* ���������ʧ�ܱ�־�����д1���� (Random Number Fail)
1�������δ��ͨ���������
0�������ͨ��������� */
#define	RNG_SR_RNF_Msk	(0x1U << RNG_SR_RNF_Pos)

#define	RNG_CRC_CR_CRCEN_Pos	0	/* CRCʹ�ܿ��ƼĴ��������д1����CRC��������ɺ�Ӳ���Զ����� (CRC enable)
1��CRCʹ��
0��CRC�ر� */
#define	RNG_CRC_CR_CRCEN_Msk	(0x1U << RNG_CRC_CR_CRCEN_Pos)
	/* CRCʹ�� */
	/* CRC�ر� */

#define	RNG_CRC_DIR_CRCIN_Pos	0	/* CRC������������Ĵ��� (CRC data input) */
#define	RNG_CRC_DIR_CRCIN_Msk	(0xffffffffU << RNG_CRC_DIR_CRCIN_Pos)

#define	RNG_CRC_SR_CRCDONE_Pos	0	/* CRC������ɱ�־�����д0���� (CRC calculation done)
1��CRC�������
0��CRC����δ��� */
#define	RNG_CRC_SR_CRCDONE_Msk	(0x1U << RNG_CRC_SR_CRCDONE_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void RNG_Deinit(void);

/* RNGʹ�ܼĴ��������д1���� (RNG enable)
1������RNG
0���ر�RNG ��غ��� */
extern void RNG_CR_EN_Setable(FunState NewState);
extern FunState RNG_CR_EN_Getable(void);

/* ��������ɽ����CRC�������Ĵ�����ֻ��
(RNG output) ��غ��� */
extern uint32_t RNG_DOR_Read(void);

/* LFSR״̬��־��ֻ�� (LFSR enable)
1��LFSR�������У����ɽ���CRC��֤
0��LFSR���������У��ɽ���CRC��֤
ע�����Ĵ�����������ģ���жϣ�������ѯ ��غ��� */
extern FlagStatus RNG_SR_LFSREN_Chk(void);

/* ���������ʧ�ܱ�־�����д1���� (Random Number Fail)
1�������δ��ͨ���������
0�������ͨ��������� ��غ��� */
extern void RNG_SR_RNF_Clr(void);
extern FlagStatus RNG_SR_RNF_Chk(void);

/* CRCʹ�ܿ��ƼĴ��������д1����CRC��������ɺ�Ӳ���Զ����� (CRC enable)
1��CRCʹ��
0��CRC�ر� ��غ��� */
extern void RNG_CRC_CR_CRCEN_Setable(FunState NewState);
extern FunState RNG_CRC_CR_CRCEN_Getable(void);

/* CRC������������Ĵ��� (CRC data input) ��غ��� */
extern void RNG_CRC_DIR_Write(uint32_t SetValue);
extern uint32_t RNG_CRC_DIR_Read(void);

/* CRC������ɱ�־�����д0���� (CRC calculation done)
1��CRC�������
0��CRC����δ��� ��غ��� */
extern void RNG_CRC_SR_CRCDONE_Clr(void);
extern FlagStatus RNG_CRC_SR_CRCDONE_Chk(void);
//Announce_End
#ifdef __cplusplus
}
#endif

#endif /* __FM33A0XXEV_RNG_H */
