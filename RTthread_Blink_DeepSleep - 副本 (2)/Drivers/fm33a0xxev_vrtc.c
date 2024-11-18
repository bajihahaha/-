/**
  ******************************************************************************
  * @file    fm33a0xxev_vrtc.c
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/

#include "fm33a0xxev_vrtc.h"

/** @addtogroup fm33a0xxev_StdPeriph_Driver
  * @{
  */

/** @defgroup VRTC 
  * @brief VRTC driver modules
  * @{
  */ 

/* RCMFʹ�ܼĴ���
0���ر�RCMF
1��ʹ��RCMF
��ע����ʹ����RTC�Զ��²���RCMF��Ӳ���������������͹ر� ��غ��� */
void VRTC_RCMFCR_EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		VRTC->RCMFCR |= (VRTC_RCMFCR_EN_Msk);
	}
	else
	{
		VRTC->RCMFCR &= ~(VRTC_RCMFCR_EN_Msk);
	}
}

FunState VRTC_RCMFCR_EN_Getable(void)
{
	if (VRTC->RCMFCR & (VRTC_RCMFCR_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* RCMFƵ�ʵ�У�Ĵ��� ��غ��� */
void VRTC_RCMFCR_TRIM_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = VRTC->RCMFCR;
	tmpreg &= ~(VRTC_RCMFCR_TRIM_Msk);
	tmpreg |= (SetValue & VRTC_RCMFCR_TRIM_Msk);
	VRTC->RCMFCR = tmpreg;
}

uint32_t VRTC_RCMFCR_TRIM_Get(void)
{
	return (VRTC->RCMFCR & VRTC_RCMFCR_TRIM_Msk);
}

/* Chopperʹ�� ��غ��� */
void VRTC_RCLPCR_CHOPEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		VRTC->RCLPCR |= (VRTC_RCLPCR_CHOPEN_Msk);
	}
	else
	{
		VRTC->RCLPCR &= ~(VRTC_RCLPCR_CHOPEN_Msk);
	}
}

FunState VRTC_RCLPCR_CHOPEN_Getable(void)
{
	if (VRTC->RCLPCR & (VRTC_RCLPCR_CHOPEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* RCLPʹ���ź�
0��ʹ��RCLP 
1���ر�RCLP
��ע��XTLF�쳣ͣ��ʱ���Զ�ʹ��RCLP ��غ��� */
void VRTC_RCLPCR_RCLP_OFF_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
    VRTC->RCLPCR |= (VRTC_RCLPCR_RCLP_OFF_Msk);
	}
	else
	{
		VRTC->RCLPCR &= ~(VRTC_RCLPCR_RCLP_OFF_Msk);
	}
}

FunState VRTC_RCLPCR_RCLP_OFF_Getable(void)
{
	if (VRTC->RCLPCR & (VRTC_RCLPCR_RCLP_OFF_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* RCLP��Уֵ�Ĵ���
0000 0000��Ƶ�����
1111 1111��Ƶ����� ��غ��� */
void VRTC_RCLPTR_Write(uint32_t SetValue)
{
	VRTC->RCLPTR = (SetValue & VRTC_RCLPTR_RCLP_TRIM_Msk);
}

uint32_t VRTC_RCLPTR_Read(void)
{
	return (VRTC->RCLPTR & VRTC_RCLPTR_RCLP_TRIM_Msk);
}
/*
rclpУ׼ֵ���뺯��
����:rclpУ׼ֵ����
���룺Ҫ���õ�RLPƵ��
*/
void VRTC_Init_RCLP_Trim(void)
{
	uint32_t Temp32;
	
	Temp32 = const_rclp_Trim;
	
	if( ((Temp32>>16)&0x000000FF) == ((~Temp32)&0x000000FF) )	//������У���ж�
	{
		if(VRTC->RCLPTR!=Temp32&0x000000FF)
		{
			VRTC_RCLPTR_Write(Temp32&0x000000FF);
		}
	}	
	else
	{
		VRTC_RCLPTR_Write(0x00000080);
	}
}

void VRTC_XTLFCR_XTLFIPW_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = VRTC->XTLFCR;
	tmpreg &= ~(VRTC_XTLFCR_XTLFIPW_Msk);
	tmpreg |= (SetValue & VRTC_XTLFCR_XTLFIPW_Msk);
	VRTC->XTLFCR = tmpreg;
}

uint32_t VRTC_XTLFCR_XTLFIPW_Get(void)
{
	return (VRTC->XTLFCR & VRTC_XTLFCR_XTLFIPW_Msk);
}

/* ADC����ʱ��ѡ��Ĵ���
000��RCMF
001��RCMF/2
010��RCMF/4
011��RCMF/8
100��RCMF/16
101��RCMF/32
110��RCLP
111��XTLF ��غ��� */
void VRTC_ADCCR_CKS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = VRTC->ADCCR;
	tmpreg &= ~(VRTC_ADCCR_CKS_Msk);
	tmpreg |= (SetValue & VRTC_ADCCR_CKS_Msk);
	VRTC->ADCCR = tmpreg;
}

uint32_t VRTC_ADCCR_CKS_Get(void)
{
	return (VRTC->ADCCR & VRTC_ADCCR_CKS_Msk);
}

/* ADC����ʱ��ʹ��
0���ر�ADC����ʱ��
1��ʹ��ADC����ʱ�� ��غ��� */
void VRTC_ADCCR_CKE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		VRTC->ADCCR |= (VRTC_ADCCR_CKE_Msk);
	}
	else
	{
		VRTC->ADCCR &= ~(VRTC_ADCCR_CKE_Msk);
	}
}

FunState VRTC_ADCCR_CKE_Getable(void)
{
	if (VRTC->ADCCR & (VRTC_ADCCR_CKE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* XTLF��Ƶ��ⱨ���ж�ʹ�ܣ�1��Ч ��غ��� */
void VRTC_LFDIER_LFDET_IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		VRTC->LFDIER |= (VRTC_LFDIER_LFDET_IE_Msk);
	}
	else
	{
		VRTC->LFDIER &= ~(VRTC_LFDIER_LFDET_IE_Msk);
	}
}

FunState VRTC_LFDIER_LFDET_IE_Getable(void)
{
	if (VRTC->LFDIER & (VRTC_LFDIER_LFDET_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��Ƶͣ����״̬���
1��XTLF����
0��XTLFͣ�� ��غ��� */
FlagStatus VRTC_LFDISR_LFDETO_Chk(void)
{
	if (VRTC->LFDISR & VRTC_LFDISR_LFDETO_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��Ƶͣ�����жϱ�־�Ĵ�����XTLFͣ��ʱӲ���첽��λ�����д1���㣻ֻ����LFDETO��Ϊ0������²��ܹ�����˼Ĵ��� ��غ��� */
void VRTC_LFDISR_LFDET_IF_Clr(void)
{
	VRTC->LFDISR = VRTC_LFDISR_LFDET_IF_Msk;
}

FlagStatus VRTC_LFDISR_LFDET_IF_Chk(void)
{
	if (VRTC->LFDISR & VRTC_LFDISR_LFDET_IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/*
rcmfУ׼ֵ���뺯��
����:rcmfУ׼ֵ����
���룺Ҫ���õ�RCMFƵ��
*/
void VRTC_Init_RCMF_Trim(void)
{
	uint32_t Temp32;
	
	Temp32 = const_rcmf_Trim;
	
	if( ((Temp32>>16)&0x0000FFFF) == ((~Temp32)&0x0000FFFF) )	//������У���ж�
	{
		VRTC_RCMFCR_TRIM_Set(Temp32&0x000000FF);
	}	
	else
	{
		VRTC_RCMFCR_TRIM_Set(0x0000001F);
	}
}

void VRTC_Deinit(void)
{
	//VRTC->RCMFCR = 0x00000040;
	//VRTC->RCLPCR = 0x00000000;
	//VRTC->RCLPTR = 0x00000000;
	//VRTC->XTLFCR = ;
	//VRTC->ADCCR = 0x00000004;
	//VRTC->LFDIER = 0x00000000;
	//VRTC->LFDISR = 0x00000000;
}

/******END OF FILE****/
