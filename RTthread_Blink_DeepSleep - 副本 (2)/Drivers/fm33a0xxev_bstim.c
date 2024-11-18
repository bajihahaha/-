/**
  ******************************************************************************
  * @file    fm33a0xxev_bstim.c
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/

#include "fm33a0xxev_bstim.h"

/** @addtogroup fm33a0xxev_StdPeriph_Driver
  * @{
  */

/** @defgroup BSTIM 
  * @brief BSTIM driver modules
  * @{
  */ 
  
/* Auto-reloadԤװ��ʹ�� (Auto-Reload Preload Enable)
0��ARR�Ĵ�����ʹ��preload
1��ARR�Ĵ���ʹ��preload ��غ��� */
void BSTIM_CR1_ARPE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		BSTIM->CR1 |= (BSTIM_CR1_ARPE_Msk);
	}
	else
	{
		BSTIM->CR1 &= ~(BSTIM_CR1_ARPE_Msk);
	}
}

FunState BSTIM_CR1_ARPE_Getable(void)
{
	if (BSTIM->CR1 & (BSTIM_CR1_ARPE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���������ģʽ (One Pulse Mode)
0��Update Event����ʱ��������ֹͣ
1��Update Event����ʱ������ֹͣ���Զ�����CEN�� ��غ��� */
void BSTIM_CR1_OPM_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BSTIM->CR1;
	tmpreg &= ~(BSTIM_CR1_OPM_Msk);
	tmpreg |= (SetValue & BSTIM_CR1_OPM_Msk);
	BSTIM->CR1 = tmpreg;
}

uint32_t BSTIM_CR1_OPM_Get(void)
{
	return (BSTIM->CR1 & BSTIM_CR1_OPM_Msk);
}

/* ��������ѡ�� (Update Request Select)
0�������¼��ܹ�����update�ж�
������������������
�����λUG�Ĵ���
�ӻ�����������update
1���������������������������update�жϻ�DMA���� ��غ��� */
void BSTIM_CR1_URS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BSTIM->CR1;
	tmpreg &= ~(BSTIM_CR1_URS_Msk);
	tmpreg |= (SetValue & BSTIM_CR1_URS_Msk);
	BSTIM->CR1 = tmpreg;
}

uint32_t BSTIM_CR1_URS_Get(void)
{
	return (BSTIM->CR1 & BSTIM_CR1_URS_Msk);
}

/* ��ֹupdate (Update Disable)
0��ʹ��update�¼��������¼�����ʱ����update�¼�
������������������
�����λUG�Ĵ���
�ӻ�����������update
1����ֹupdate�¼���������shadow�Ĵ�������UG��λ��ӻ��������յ�Ӳ��resetʱ���³�ʼ����������Ԥ��Ƶ���� ��غ��� */
void BSTIM_CR1_UDIS_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		BSTIM->CR1 |= (BSTIM_CR1_UDIS_Msk);
	}
	else
	{
		BSTIM->CR1 &= ~(BSTIM_CR1_UDIS_Msk);
	}
}

FunState BSTIM_CR1_UDIS_Getable(void)
{
	if (BSTIM->CR1 & (BSTIM_CR1_UDIS_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ������ʹ�� (Counter Enable)
0���������ر�
1��������ʹ��
ע�⣺�ⲿ����ģʽ�����Զ���λCEN ��غ��� */
void BSTIM_CR1_CEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		BSTIM->CR1 |= (BSTIM_CR1_CEN_Msk);
	}
	else
	{
		BSTIM->CR1 &= ~(BSTIM_CR1_CEN_Msk);
	}
}

FunState BSTIM_CR1_CEN_Getable(void)
{
	if (BSTIM->CR1 & (BSTIM_CR1_CEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ����ģʽѡ��������������ģʽ����ӻ����͵�ͬ�������źţ�TRGO��Դ (Master Mode Select)
000��BSTIM_EGR��UG�Ĵ���������TRGO
001��������ʹ���ź�CNT_EN������TRGO��������ͬʱ���������ʱ��
010��UE��update event���źű�����TRGO
011/100/111��RFU

ע�⣺�ӻ���ʱ����ADC��������ʹ�ܹ���ʱ�ӣ����ܽ���������ʱ�����͵�TRGO ��غ��� */
void BSTIM_CR2_Write(uint32_t SetValue)
{
	BSTIM->CR2 = (SetValue & BSTIM_CR2_MMS_Msk);
}

uint32_t BSTIM_CR2_Read(void)
{
	return (BSTIM->CR2 & BSTIM_CR2_MMS_Msk);
}

/* Update�¼��ж�ʹ�� (Update event Interrupt Enable)
0����ֹUpdate�¼��ж�
1������Update�¼��ж� ��غ��� */
void BSTIM_IER_UIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		BSTIM->IER |= (BSTIM_IER_UIE_Msk);
	}
	else
	{
		BSTIM->IER &= ~(BSTIM_IER_UIE_Msk);
	}
}

FunState BSTIM_IER_UIE_Getable(void)
{
	if (BSTIM->IER & (BSTIM_IER_UIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Update�¼��жϱ�־��Ӳ����λ�����д1���㡣(Update event Interrupt Flag,write 1 to flag)
�������¼�����ʱ��UIF��λ��������shadow�Ĵ���
-�ظ�������=0������UDIS=0������£��������������
-URS=0��UDIS=0������£������λUG�Ĵ�����ʼ��������
-URS=0��UDIS=0������£������¼���ʼ�������� ��غ��� */
void BSTIM_ISR_UIF_Clr(void)
{
	BSTIM->ISR = BSTIM_ISR_UIF_Msk;
}

FlagStatus BSTIM_ISR_UIF_Chk(void)
{
	if (BSTIM->ISR & BSTIM_ISR_UIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ���Update�¼��������λ�˼Ĵ�������Update�¼���Ӳ���Զ����� (User Generate)
�����λUGʱ�����³�ʼ��������������shadow�Ĵ�����Ԥ��Ƶ�����������㡣 ��غ��� */
void BSTIM_EGR_UG_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		BSTIM->EGR |= (BSTIM_EGR_UG_Msk);
	}
	else
	{
		BSTIM->EGR &= ~(BSTIM_EGR_UG_Msk);
	}
}

/* ������ֵ (Counter) ��غ��� */
void BSTIM_CNTR_Write(uint32_t SetValue)
{
	BSTIM->CNTR = (SetValue);
}

uint32_t BSTIM_CNTR_Read(void)
{
	return (BSTIM->CNTR);
}

/* ������ʱ�ӣ�CK_CNT��Ԥ��Ƶֵ (Counter Clock Prescaler)
fCK_CNT=fCK_PSC/(PSC[15:0]+1)
����һ��preload�Ĵ�������update�¼�����ʱ�����ݱ�����shadow�Ĵ��� ��غ��� */
void BSTIM_PSCR_Write(uint32_t SetValue)
{
	BSTIM->PSCR = (SetValue);
}

uint32_t BSTIM_PSCR_Read(void)
{
	return (BSTIM->PSCR);
}

/* �������ʱ���Զ�����ֵ (Auto-Reload Register)
����һ��preload�Ĵ�������update�¼�����ʱ�����ݱ�����shadow�Ĵ��� ��غ��� */
void BSTIM_ARR_Write(uint32_t SetValue)
{
	BSTIM->ARR = (SetValue);
}

uint32_t BSTIM_ARR_Read(void)
{
	return (BSTIM->ARR);
}


void BSTIM_Deinit(void)
{
	//BSTIM->CR1 = 0x00000000;
	//BSTIM->CR2 = 0x00000000;
	//BSTIM->IER = 0x00000000;
	//BSTIM->ISR = 0x00000000;
	//BSTIM->EGR = 0x00000000;
	//BSTIM->CNTR = 0x00000000;
	//BSTIM->PSCR = 0x00000000;
	//BSTIM->ARR = 0x00000000;
}

/******END OF FILE****/
