/**
  ******************************************************************************
  * @file    fm33a0xxev_svd.h
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file contains all the functions prototypes for the SVD firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33A0XXEV_SVD_H
#define __FM33A0XXEV_SVD_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
   
#include "FM33A0XXEV.h"

typedef struct
{
	uint32_t	SVDMOD;		/*!<SVD����ģʽѡ��  */
	uint32_t	SVDITVL;	/*!<SVD��Ъʹ�ܼ��  */
	uint32_t	SVDLVL;		/*!<SVD������ֵ����  */
	FunState	DFEN;		/*!<SVD�����˲���SVDMODE=1ʱ������1��  */
	FunState	PFIE;		/*!<SVD��Դ�����ж�  */
	FunState	PRIE;		/*!<SVD��Դ�ָ��ж�  */
	FunState	SVDEN;		/*!<SVDʹ��  */
	
}SVD_InitTypeDef;
 
#define	SVD_CFGR_LVL_Pos	4	/* SVD������ֵ��λ���ã��μ�11.3.3�����ֵ
(SVD threshold level) */
#define	SVD_CFGR_LVL_Msk	(0xfU << SVD_CFGR_LVL_Pos)
#define	SVD_CFGR_LVL_1P800V	(0x0U << SVD_CFGR_LVL_Pos)
#define	SVD_CFGR_LVL_2P014V	(0x1U << SVD_CFGR_LVL_Pos)
#define	SVD_CFGR_LVL_2P229V	(0x2U << SVD_CFGR_LVL_Pos)
#define	SVD_CFGR_LVL_2P443V	(0x3U << SVD_CFGR_LVL_Pos)
#define	SVD_CFGR_LVL_2P657V	(0x4U << SVD_CFGR_LVL_Pos)
#define	SVD_CFGR_LVL_2P871V	(0x5U << SVD_CFGR_LVL_Pos)
#define	SVD_CFGR_LVL_3P086V	(0x6U << SVD_CFGR_LVL_Pos)
#define	SVD_CFGR_LVL_3P300V	(0x7U << SVD_CFGR_LVL_Pos)
#define	SVD_CFGR_LVL_3P514V	(0x8U << SVD_CFGR_LVL_Pos)
#define	SVD_CFGR_LVL_3P729V	(0x9U << SVD_CFGR_LVL_Pos)
#define	SVD_CFGR_LVL_3P943V	(0xaU << SVD_CFGR_LVL_Pos)
#define	SVD_CFGR_LVL_4P157V	(0xbU << SVD_CFGR_LVL_Pos)
#define	SVD_CFGR_LVL_4P371V	(0xcU << SVD_CFGR_LVL_Pos)
#define	SVD_CFGR_LVL_4P586V	(0xdU << SVD_CFGR_LVL_Pos)
#define	SVD_CFGR_LVL_4P800V	(0xeU << SVD_CFGR_LVL_Pos)
#define	SVD_CFGR_LVL_SVS	(0xfU << SVD_CFGR_LVL_Pos)

#define	SVD_CFGR_DFEN_Pos	3	/* �����˲�ʹ�ܣ�MOD=1ʱ������1��
(Digital Filter Enable)
1������SVD����������˲�
0���ر�SVD����������˲� */
#define	SVD_CFGR_DFEN_Msk	(0x1U << SVD_CFGR_DFEN_Pos)
	/* ����SVD����������˲� */
	/* �ر�SVD����������˲� */

#define	SVD_CFGR_MOD_Pos	2	/* SVD����ģʽѡ������ģʽ��Ҫ��λSVD_CR.EN�Ż�����SVD
(SVD Mode)
1����Ъʹ��ģʽ
0����ʹ��ģʽ
ע�⣺��Ъʹ��ģʽ�±��뿪�������˲� */
#define	SVD_CFGR_MOD_Msk	(0x1U << SVD_CFGR_MOD_Pos)
#define	SVD_CFGR_MOD_INTERVAL	(0x1U << SVD_CFGR_MOD_Pos)	/* ��Ъʹ��ģʽ */
#define	SVD_CFGR_MOD_ALWAYSON	(0x0U << SVD_CFGR_MOD_Pos)	/* ��ʹ��ģʽ */

#define	SVD_CFGR_ITVL_Pos	0	/* SVD��Ъʹ�ܼ�� (SVD interval enable period)
00��62.5ms
01��256ms
10��1s
11��4s */
#define	SVD_CFGR_ITVL_Msk	(0x3U << SVD_CFGR_ITVL_Pos)
#define	SVD_CFGR_ITVL_62P5MS	(0x0U << SVD_CFGR_ITVL_Pos)	/* 62.5ms */
#define	SVD_CFGR_ITVL_256MS	(0x1U << SVD_CFGR_ITVL_Pos)	/* 256ms */
#define	SVD_CFGR_ITVL_1S	(0x2U << SVD_CFGR_ITVL_Pos)	/* 1s */
#define	SVD_CFGR_ITVL_4S	(0x3U << SVD_CFGR_ITVL_Pos)	/* 4s */
	/* 62.5ms */
	/* 256ms */
	/* 1s */
	/* 4s */
#define	SVD_CR_TE_Pos	8	/* SVD����ʹ�ܣ�����д1 (SVD test enable) */
#define	SVD_CR_TE_Msk	(0x1U << SVD_CR_TE_Pos)

#define	SVD_CR_SVSEN_Pos	1	/* SVS�ⲿ��Դ���ͨ�������ź� 
(SVS external monitor channel enable)
0��SVSͨ���ر�
1��SVSͨ��ʹ��
��EN=1ʱ������SVDLVL�Ĵ�����������SVS������Ƿ񾭹��ڲ������ѹ�����LVL=1111����SVS���벻����ѹ�����LVL != 1111����SVS���뾭���ڲ������ѹ�� */
#define	SVD_CR_SVSEN_Msk	(0x1U << SVD_CR_SVSEN_Pos)
	/* SVSͨ���ر� */
	/* SVSͨ��ʹ�� */

#define	SVD_CR_SVDEN_Pos	0
#define	SVD_CR_SVDEN_Msk	(0x1U << SVD_CR_SVDEN_Pos)

#define	SVD_IER_PFIE_Pos	1	/* ��Դ�����ж�ʹ�ܼĴ�����1��Ч (Power Fall interrupt enable) */
#define	SVD_IER_PFIE_Msk	(0x1U << SVD_IER_PFIE_Pos)

#define	SVD_IER_PRIE_Pos	0	/* ��Դ�ָ��ж�ʹ�ܼĴ�����1��Ч (Power Rise interrupt enable) */
#define	SVD_IER_PRIE_Msk	(0x1U << SVD_IER_PRIE_Pos)

#define	SVD_ISR_SVDO_Pos	8	/* SVD��Դ������ (SVD output)
1����Դ��ѹ����SVD��ǰ��ֵ
0����Դ��ѹ����SVD��ǰ��ֵ */
#define	SVD_ISR_SVDO_Msk	(0x1U << SVD_ISR_SVDO_Pos)

#define	SVD_ISR_SVDR_Pos	7	/* SVD��������źţ����ֵ�·�����SVD״̬
(SVD registered output) */
#define	SVD_ISR_SVDR_Msk	(0x1U << SVD_ISR_SVDR_Pos)

#define	SVD_ISR_PFF_Pos	1	/* ��Դ�����жϱ�־�Ĵ�������Դ��ѹ���䵽SVD��ֵ֮��ʱ��λ�����д1���� (Power fall flag) */
#define	SVD_ISR_PFF_Msk	(0x1U << SVD_ISR_PFF_Pos)

#define	SVD_ISR_PRF_Pos	0	/* ��Դ�ָ��жϱ�־�Ĵ�������Դ��ѹ������SVD��ֵ֮��ʱ��λ�����д1���� (Power rise flag) */
#define	SVD_ISR_PRF_Msk	(0x1U << SVD_ISR_PRF_Pos)

#define	SVD_VSR_V1P0EN_Pos	2	/* 1.0V��׼����ʹ���ź� (1.0V reference enable)
1��ʹ��1.0V��׼����
0���ر�1.0V��׼���� */
#define	SVD_VSR_V1P0EN_Msk	(0x1U << SVD_VSR_V1P0EN_Pos)

#define	SVD_VSR_V0P95EN_Pos	1	/* 0.95V��׼����ʹ���ź� (0.95V reference enable)
1��ʹ��0.95V��׼����
0���ر�0.95V��׼���� */
#define	SVD_VSR_V0P95EN_Msk	(0x1U << SVD_VSR_V0P95EN_Pos)

#define	SVD_VSR_V0P9EN_Pos	0	/* 0.9V��׼����ʹ���ź� (0.9V reference enable)
1��ʹ��0.9V��׼����
0���ر�0.9V��׼���� */
#define	SVD_VSR_V0P9EN_Msk	(0x1U << SVD_VSR_V0P9EN_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void SVD_Deinit(void);

/* SVD������ֵ��λ���ã��μ�11.3.3�����ֵ
(SVD threshold level) ��غ��� */
extern void SVD_CFGR_LVL_Set(uint32_t SetValue);
extern uint32_t SVD_CFGR_LVL_Get(void);

/* �����˲�ʹ�ܣ�MOD=1ʱ������1��
(Digital Filter Enable)
1������SVD����������˲�
0���ر�SVD����������˲� ��غ��� */
extern void SVD_CFGR_DFEN_Setable(FunState NewState);
extern FunState SVD_CFGR_DFEN_Getable(void);

/* SVD����ģʽѡ������ģʽ��Ҫ��λSVD_CR.EN�Ż�����SVD
(SVD Mode)
1����Ъʹ��ģʽ
0����ʹ��ģʽ
ע�⣺��Ъʹ��ģʽ�±��뿪�������˲� ��غ��� */
extern void SVD_CFGR_MOD_Set(uint32_t SetValue);
extern uint32_t SVD_CFGR_MOD_Get(void);

/* SVD��Ъʹ�ܼ�� (SVD interval enable period)
00��62.5ms
01��256ms
10��1s
11��4s ��غ��� */
extern void SVD_CFGR_ITVL_Set(uint32_t SetValue);
extern uint32_t SVD_CFGR_ITVL_Get(void);

/* SVS�ⲿ��Դ���ͨ�������ź� 
(SVS external monitor channel enable)
0��SVSͨ���ر�
1��SVSͨ��ʹ��
��EN=1ʱ������SVDLVL�Ĵ�����������SVS������Ƿ񾭹��ڲ������ѹ�����LVL=1111����SVS���벻����ѹ�����LVL != 1111����SVS���뾭���ڲ������ѹ�� ��غ��� */
extern void SVD_CR_SVSEN_Setable(FunState NewState);
extern FunState SVD_CR_SVSEN_Getable(void);
extern void SVD_CR_SVDEN_Setable(FunState NewState);
extern FunState SVD_CR_SVDEN_Getable(void);

/* ��Դ�����ж�ʹ�ܼĴ�����1��Ч (Power Fall interrupt enable) ��غ��� */
extern void SVD_IER_PFIE_Setable(FunState NewState);
extern FunState SVD_IER_PFIE_Getable(void);

/* ��Դ�ָ��ж�ʹ�ܼĴ�����1��Ч (Power Rise interrupt enable) ��غ��� */
extern void SVD_IER_PRIE_Setable(FunState NewState);
extern FunState SVD_IER_PRIE_Getable(void);

/* SVD��Դ������ (SVD output)
1����Դ��ѹ����SVD��ǰ��ֵ
0����Դ��ѹ����SVD��ǰ��ֵ ��غ��� */
extern FlagStatus SVD_ISR_SVDO_Chk(void);

/* SVD��������źţ����ֵ�·�����SVD״̬
(SVD registered output) ��غ��� */
extern FlagStatus SVD_ISR_SVDR_Chk(void);

/* ��Դ�����жϱ�־�Ĵ�������Դ��ѹ���䵽SVD��ֵ֮��ʱ��λ�����д1���� (Power fall flag) ��غ��� */
extern void SVD_ISR_PFF_Clr(void);
extern FlagStatus SVD_ISR_PFF_Chk(void);

/* ��Դ�ָ��жϱ�־�Ĵ�������Դ��ѹ������SVD��ֵ֮��ʱ��λ�����д1���� (Power rise flag) ��غ��� */
extern void SVD_ISR_PRF_Clr(void);
extern FlagStatus SVD_ISR_PRF_Chk(void);

/* 1.0V��׼����ʹ���ź� (1.0V reference enable)
1��ʹ��1.0V��׼����
0���ر�1.0V��׼���� ��غ��� */
extern void SVD_VSR_V1P0EN_Setable(FunState NewState);
extern FunState SVD_VSR_V1P0EN_Getable(void);

/* 0.95V��׼����ʹ���ź� (0.95V reference enable)
1��ʹ��0.95V��׼����
0���ر�0.95V��׼���� ��غ��� */
extern void SVD_VSR_V0P95EN_Setable(FunState NewState);
extern FunState SVD_VSR_V0P95EN_Getable(void);

/* 0.9V��׼����ʹ���ź� (0.9V reference enable)
1��ʹ��0.9V��׼����
0���ر�0.9V��׼���� ��غ��� */
extern void SVD_VSR_V0P9EN_Setable(FunState NewState);
extern FunState SVD_VSR_V0P9EN_Getable(void);

extern void SVD_Init(SVD_InitTypeDef* para);
//Announce_End
#ifdef __cplusplus
}
#endif

#endif /* __FM33A0XXEV_SVD_H */
