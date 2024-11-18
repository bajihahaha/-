/**
  ******************************************************************************
  * @file    fm33a0xxev_svd.c
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/

#include "fm33a0xxev_svd.h"

/** @addtogroup fm33a0xxev_StdPeriph_Driver
  * @{
  */

/** @defgroup SVD 
  * @brief SVD driver modules
  * @{
  */ 
 
/* SVD������ֵ��λ���ã��μ�11.3.3�����ֵ
(SVD threshold level) ��غ��� */
void SVD_CFGR_LVL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SVD->CFGR;
	tmpreg &= ~(SVD_CFGR_LVL_Msk);
	tmpreg |= (SetValue & SVD_CFGR_LVL_Msk);
	SVD->CFGR = tmpreg;
}

uint32_t SVD_CFGR_LVL_Get(void)
{
	return (SVD->CFGR & SVD_CFGR_LVL_Msk);
}

/* �����˲�ʹ�ܣ�MOD=1ʱ������1��
(Digital Filter Enable)
1������SVD����������˲�
0���ر�SVD����������˲� ��غ��� */
void SVD_CFGR_DFEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SVD->CFGR |= (SVD_CFGR_DFEN_Msk);
	}
	else
	{
		SVD->CFGR &= ~(SVD_CFGR_DFEN_Msk);
	}
}

FunState SVD_CFGR_DFEN_Getable(void)
{
	if (SVD->CFGR & (SVD_CFGR_DFEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* SVD����ģʽѡ������ģʽ��Ҫ��λSVD_CR.EN�Ż�����SVD
(SVD Mode)
1����Ъʹ��ģʽ
0����ʹ��ģʽ
ע�⣺��Ъʹ��ģʽ�±��뿪�������˲� ��غ��� */
void SVD_CFGR_MOD_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SVD->CFGR;
	tmpreg &= ~(SVD_CFGR_MOD_Msk);
	tmpreg |= (SetValue & SVD_CFGR_MOD_Msk);
	SVD->CFGR = tmpreg;
}

uint32_t SVD_CFGR_MOD_Get(void)
{
	return (SVD->CFGR & SVD_CFGR_MOD_Msk);
}

/* SVD Interval��SVD��Ъʹ�ܼ�� (SVD periodic interval)
00��62.5ms
01��256ms
10��1s
11��4s ��غ��� */
void SVD_CFGR_ITVL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SVD->CFGR;
	tmpreg &= ~(SVD_CFGR_ITVL_Msk);
	tmpreg |= (SetValue & SVD_CFGR_ITVL_Msk);
	SVD->CFGR = tmpreg;
}

uint32_t SVD_CFGR_ITVL_Get(void)
{
	return (SVD->CFGR & SVD_CFGR_ITVL_Msk);
}

/* SVD����ʹ�ܣ�����д1 (SVD test enable) ��غ��� */
void SVD_CR_TE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SVD->CR |= (SVD_CR_TE_Msk);
	}
	else
	{
		SVD->CR &= ~(SVD_CR_TE_Msk);
	}
}

FunState SVD_CR_TE_Getable(void)
{
	if (SVD->CR & (SVD_CR_TE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}


/* SVS�ⲿ��Դ���ͨ�������ź� 
(SVS external monitor channel enable)
0��SVSͨ���ر�
1��SVSͨ��ʹ��
��EN=1ʱ������SVDLVL�Ĵ�����������SVS������Ƿ񾭹��ڲ������ѹ�����LVL=1111����SVS���벻����ѹ�����LVL != 1111����SVS���뾭���ڲ������ѹ�� ��غ��� */
void SVD_CR_SVSEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SVD->CR |= (SVD_CR_SVSEN_Msk);
	}
	else
	{
		SVD->CR &= ~(SVD_CR_SVSEN_Msk);
	}
}

FunState SVD_CR_SVSEN_Getable(void)
{
	if (SVD->CR & (SVD_CR_SVSEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

void SVD_CR_SVDEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SVD->CR |= (SVD_CR_SVDEN_Msk);
	}
	else
	{
		SVD->CR &= ~(SVD_CR_SVDEN_Msk);
	}
}

FunState SVD_CR_SVDEN_Getable(void)
{
	if (SVD->CR & (SVD_CR_SVDEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��Դ�����ж�ʹ�ܼĴ�����1��Ч (Power Fall interrupt enable) ��غ��� */
void SVD_IER_PFIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SVD->IER |= (SVD_IER_PFIE_Msk);
	}
	else
	{
		SVD->IER &= ~(SVD_IER_PFIE_Msk);
	}
}

FunState SVD_IER_PFIE_Getable(void)
{
	if (SVD->IER & (SVD_IER_PFIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��Դ�ָ��ж�ʹ�ܼĴ�����1��Ч (Power Rise interrupt enable) ��غ��� */
void SVD_IER_PRIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SVD->IER |= (SVD_IER_PRIE_Msk);
	}
	else
	{
		SVD->IER &= ~(SVD_IER_PRIE_Msk);
	}
}

FunState SVD_IER_PRIE_Getable(void)
{
	if (SVD->IER & (SVD_IER_PRIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* SVD��Դ������ (SVD output)
1����Դ��ѹ����SVD��ǰ��ֵ
0����Դ��ѹ����SVD��ǰ��ֵ ��غ��� */
FlagStatus SVD_ISR_SVDO_Chk(void)
{
	if (SVD->ISR & SVD_ISR_SVDO_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* SVD��������źţ����ֵ�·�����SVD״̬
(SVD registered output) ��غ��� */
FlagStatus SVD_ISR_SVDR_Chk(void)
{
	if (SVD->ISR & SVD_ISR_SVDR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��Դ�����жϱ�־�Ĵ�������Դ��ѹ���䵽SVD��ֵ֮��ʱ��λ�����д1���� (Power fall flag) ��غ��� */
void SVD_ISR_PFF_Clr(void)
{
	SVD->ISR = SVD_ISR_PFF_Msk;
}

FlagStatus SVD_ISR_PFF_Chk(void)
{
	if (SVD->ISR & SVD_ISR_PFF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��Դ�ָ��жϱ�־�Ĵ�������Դ��ѹ������SVD��ֵ֮��ʱ��λ�����д1���� (Power rise flag) ��غ��� */
void SVD_ISR_PRF_Clr(void)
{
	SVD->ISR = SVD_ISR_PRF_Msk;
}

FlagStatus SVD_ISR_PRF_Chk(void)
{
	if (SVD->ISR & SVD_ISR_PRF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 1.0V��׼����ʹ���ź� (1.0V reference enable)
1��ʹ��1.0V��׼����
0���ر�1.0V��׼���� ��غ��� */
void SVD_VSR_V1P0EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SVD->VSR |= (SVD_VSR_V1P0EN_Msk);
	}
	else
	{
		SVD->VSR &= ~(SVD_VSR_V1P0EN_Msk);
	}
}

FunState SVD_VSR_V1P0EN_Getable(void)
{
	if (SVD->VSR & (SVD_VSR_V1P0EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 0.95V��׼����ʹ���ź� (0.95V reference enable)
1��ʹ��0.95V��׼����
0���ر�0.95V��׼���� ��غ��� */
void SVD_VSR_V0P95EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SVD->VSR |= (SVD_VSR_V0P95EN_Msk);
	}
	else
	{
		SVD->VSR &= ~(SVD_VSR_V0P95EN_Msk);
	}
}

FunState SVD_VSR_V0P95EN_Getable(void)
{
	if (SVD->VSR & (SVD_VSR_V0P95EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 0.9V��׼����ʹ���ź� (0.9V reference enable)
1��ʹ��0.9V��׼����
0���ر�0.9V��׼���� ��غ��� */
void SVD_VSR_V0P9EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SVD->VSR |= (SVD_VSR_V0P9EN_Msk);
	}
	else
	{
		SVD->VSR &= ~(SVD_VSR_V0P9EN_Msk);
	}
}

FunState SVD_VSR_V0P9EN_Getable(void)
{
	if (SVD->VSR & (SVD_VSR_V0P9EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}


void SVD_Deinit(void)
{
	//SVD->CFGR = 0x00000008;
	//SVD->CR = 0x00000000;
	//SVD->IER = 0x00000000;
	//SVD->ISR = 0x00000000;
	//SVD->VSR = 0x00000000;
}

/*********************************
SVD��ʼ�����ú��� 
���ܣ�SVD��ʼ������
����: ANAC_SVD_InitTypeDef* para���ṹ�庯�������ù���ģʽ����ֵ�������˲��ȹ���
���: ��
*********************************/
void SVD_Init(SVD_InitTypeDef* para)
{
	SVD_CFGR_MOD_Set(para->SVDMOD);	//SVD����ģʽѡ��
	SVD_CFGR_ITVL_Set(para->SVDITVL);	//SVD��Ъʹ�ܼ������
	SVD_CFGR_LVL_Set(para->SVDLVL);	//SVD������ֵ����
	SVD_CFGR_DFEN_Setable(para->DFEN);	//SVD�����˲����ã�SVDMODE=1ʱ������1��
	SVD_IER_PFIE_Setable(para->PFIE);	//SVD��Դ�����ж�����
	SVD_IER_PRIE_Setable(para->PRIE);	//SVD��Դ�ָ��ж�����
	SVD_CR_TE_Setable(DISABLE);	//�رղ��Թ���	
}	

/******END OF FILE****/
