/**
  ******************************************************************************
  * @file    fm33a0xxev_hash.h
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file contains all the functions prototypes for the HASH firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33A0XXEV_HASH_H
#define __FM33A0XXEV_HASH_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33A0XXEV.h" 
   
#define	HASH_CSR_START_Pos	7	/* HASH���������Ĵ��������д1�������㣬���������Ӳ���Զ����� */
#define	HASH_CSR_START_Msk	(0x1U << HASH_CSR_START_Pos)

#define	HASH_CSR_BUSY_Pos	6	/* HASH����״̬��Ӳ����λ�����ֻ�� */
#define	HASH_CSR_BUSY_Msk	(0x1U << HASH_CSR_BUSY_Pos)

#define	HASH_CSR_HASHSEL_Pos	1	/* SHA�㷨ѡ�� */
#define	HASH_CSR_HASHSEL_Msk	(0x1U << HASH_CSR_HASHSEL_Pos)
#define	HASH_CSR_HASHSEL_SHA256	(0x0U << HASH_CSR_HASHSEL_Pos)	/* 0��SHA256 */
#define	HASH_CSR_HASHSEL_SHA1	(0x1U << HASH_CSR_HASHSEL_Pos)	/* 1��SHA1 */

#define	HASH_DTR_DATA_TYPE_Pos	0	/* ������������˳�򽻻�����
00��������
01��half-word����
10��byte����
11��bit����
�˼Ĵ������ڶ�����32bit���ݵ�λ����е�������������Ϊ0x1234_5678��half-word������Ϊ0x5678_1234��byte������Ϊ0x7856_3412��bit������Ϊ0x1E6A_2C48
 */
#define	HASH_DTR_DATA_TYPE_Msk	(0x3U << HASH_DTR_DATA_TYPE_Pos)
#define	HASH_DTR_DATA_TYPE_NONE	(0x0U << HASH_DTR_DATA_TYPE_Pos)	/* ������ */
#define	HASH_DTR_DATA_TYPE_HALFWORD	(0x1U << HASH_DTR_DATA_TYPE_Pos)	/* half-word���� */
#define	HASH_DTR_DATA_TYPE_BYTE	(0x2U << HASH_DTR_DATA_TYPE_Pos)	/* byte���� */
#define	HASH_DTR_DATA_TYPE_BIT	(0x3U << HASH_DTR_DATA_TYPE_Pos)	/* bit���� */
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void HASH_Deinit(void);

/* HASH���������Ĵ��������д1�������㣬���������Ӳ���Զ����� ��غ��� */
extern void HASH_CSR_START_Setable(FunState NewState);
extern FunState HASH_CSR_START_Getable(void);


/* SHA�㷨ѡ�� ��غ��� */
extern void HASH_CSR_HASHSEL_Set(uint32_t SetValue);
extern uint32_t HASH_CSR_HASHSEL_Get(void);

/* ������������˳�򽻻�����
00��������
01��half-word����
10��byte����
11��bit����
�˼Ĵ������ڶ�����32bit���ݵ�λ����е�������������Ϊ0x1234_5678��half-word������Ϊ0x5678_1234��byte������Ϊ0x7856_3412��bit������Ϊ0x1E6A_2C48
 ��غ��� */
extern void HASH_DTR_DATA_TYPE_Set(uint32_t SetValue);
extern uint32_t HASH_DTR_DATA_TYPE_Get(void);
//Announce_End
#ifdef __cplusplus
}
#endif

#endif /* __FM33A0XXEV_HASH_H */
