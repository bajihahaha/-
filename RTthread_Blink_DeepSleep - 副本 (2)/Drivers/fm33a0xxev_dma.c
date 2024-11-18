/**
  ******************************************************************************
  * @file    fm33a0xxev_dma.c
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/

#include "fm33a0xxev_dma.h"
#include "fm33a0xxev_rmu.h"

/** @addtogroup fm33a0xxev_StdPeriph_Driver
  * @{
  */

/** @defgroup DMA 
  * @brief DMA driver modules
  * @{
  */ 

/* DMA�����ַ�ж�ʹ��
1����������ַ�ж�
0����ֹ�����ַ�ж� ��غ��� */
void DMA_GCR_DMA_ADDRERR_EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		DMA->GCR |= (DMA_GCR_DMA_ADDRERR_EN_Msk);
	}
	else
	{
		DMA->GCR &= ~(DMA_GCR_DMA_ADDRERR_EN_Msk);
	}
}

FunState DMA_GCR_DMA_ADDRERR_EN_Getable(void)
{
	if (DMA->GCR & (DMA_GCR_DMA_ADDRERR_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* DMAȫ��ʹ��
1��DMAʹ��
0��DMA�ر� ��غ��� */
void DMA_GCR_DMAEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		DMA->GCR |= (DMA_GCR_DMAEN_Msk);
	}
	else
	{
		DMA->GCR &= ~(DMA_GCR_DMAEN_Msk);
	}
}

FunState DMA_GCR_DMAEN_Getable(void)
{
	if (DMA->GCR & (DMA_GCR_DMAEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Channelx���䳤�ȣ�1-8192�δ��� ��غ��� */
void DMA_CHxCR_CHxTSIZE_Set(DMA_CH_Type CHx, uint32_t SetValue)
{
	uint32_t *pREG;
	uint32_t tmpreg;    
	pREG = (uint32_t *)(DMA_BASE + 0x04 + CHx*8);//DMA->CH0CTRL;
	
	SetValue <<= DMA_CHxCR_CHxTSIZE_Pos;//�ֹ����
	
	tmpreg = *pREG;
	tmpreg &= ~(DMA_CHxCR_CHxTSIZE_Msk);
	tmpreg |= (SetValue&DMA_CHxCR_CHxTSIZE_Msk);
	*pREG = tmpreg;
}

uint32_t DMA_CHxCR_CHxTSIZE_Get(DMA_CH_Type CHx)
{
	uint32_t *pREG;
	pREG = (uint32_t *)(DMA_BASE + 0x04 + CHx*8);
	return (uint32_t)((*pREG & DMA_CHxCR_CHxTSIZE_Msk) >> DMA_CHxCR_CHxTSIZE_Pos);
}

/* Channelx���ȼ�
00��Low
01��Medium
10��High
11��Very High ��غ��� */
void DMA_CHxCR_CHxPRI_Set(DMA_CH_Type CHx, uint32_t SetValue)
{
	
	uint32_t *pREG;
	uint32_t tmpreg;    
	pREG = (uint32_t *)(DMA_BASE + 0x04 + CHx*8);//DMA->CH0CTRL;

	tmpreg = *pREG;
	tmpreg &= ~(DMA_CHxCR_CHxPRI_Msk);
	tmpreg |= (SetValue&DMA_CHxCR_CHxPRI_Msk);
	*pREG = tmpreg;
}

uint32_t DMA_CHxCR_CHxPRI_Get(DMA_CH_Type CHx)
{
	uint32_t *pREG;
	
	pREG = (uint32_t *)(DMA_BASE + 0x04 + CHx*8);
	return (*pREG & DMA_CHxCR_CHxPRI_Msk);
}

/* RAM��ַ��������
1��RAM��ַ����
0��RAM��ַ�ݼ� ��غ��� */
void DMA_CHxCR_CHxINC_Set(DMA_CH_Type CHx, uint32_t SetValue)
{
	
	uint32_t *pREG;
	uint32_t tmpreg;    
	pREG = (uint32_t *)(DMA_BASE + 0x04 + CHx*8);//DMA->CH0CTRL;

	tmpreg = *pREG;
	tmpreg &= ~(DMA_CHxCR_CHxINC_Msk);
	tmpreg |= (SetValue&DMA_CHxCR_CHxINC_Msk);
	*pREG = tmpreg;
}

uint32_t DMA_CHxCR_CHxINC_Get(DMA_CH_Type CHx)
{
	uint32_t *pREG;
	
	pREG = (uint32_t *)(DMA_BASE + 0x04 + CHx*8);
	return (*pREG & DMA_CHxCR_CHxINC_Msk);
}

/* Channelx��������ӳ��
ÿ��ͨ�����Խ���8�������������������ӳ��μ�23.6.1DMA����ӳ�� ��غ��� */
void DMA_CHxCR_CHxSSEL_Set(DMA_CH_Type CHx, uint32_t SetValue)
{
	
	
	uint32_t *pREG;
	uint32_t tmpreg;    
	pREG = (uint32_t *)(DMA_BASE + 0x04 + CHx*8);//DMA->CH0CTRL;

	tmpreg = *pREG;
	tmpreg &= ~(DMA_CHxCR_CHxSSEL_Msk);
	tmpreg |= (SetValue&DMA_CHxCR_CHxSSEL_Msk);
	*pREG = tmpreg;
}

uint32_t DMA_CHxCR_CHxSSEL_Get(DMA_CH_Type CHx)
{
	uint32_t *pREG;
	pREG = (uint32_t *)(DMA_BASE + 0x04 + CHx*8);
	return (*pREG & DMA_CHxCR_CHxSSEL_Msk);
}

/* ѭ������ģʽ���Զ����´�����������ִ�����ɺ�shadow�Ĵ������ݸ��Ƶ����ƼĴ���
0����ֹ�Զ�����
1��ʹ���Զ�����
ע�⣺��ͨ��0~6֧�ִ˹��ܣ�ͨ��7~10�޴˼Ĵ��� ��غ��� */
void DMA_CHxCR_CIRC_UPD_Setable(DMA_CH_Type CHx, FunState NewState)
{
	uint32_t *pREG;
	
	pREG = (uint32_t *)(DMA_BASE + 0x04 + CHx*8);
	if (NewState == ENABLE)
	{
		*pREG |= (DMA_CHxCR_CIRC_UPD_Msk);
	}
	else
	{
		*pREG &= ~(DMA_CHxCR_CIRC_UPD_Msk);
	}
}

FunState DMA_CHxCR_CIRC_UPD_Getable(DMA_CH_Type CHx)
{
	uint32_t *pREG;
	
	pREG = (uint32_t *)(DMA_BASE + 0x04 + CHx*8);;
	if (*pREG & (DMA_CHxCR_CIRC_UPD_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ͨ�����䷽��
0���������ȡ����д��RAM
1����RAM��ȡ����д������ ��غ��� */
void DMA_CHxCR_DIR_Set(DMA_CH_Type CHx, uint32_t SetValue)
{
	uint32_t *pREG;
	uint32_t tmpreg;    
	pREG = (uint32_t *)(DMA_BASE + 0x04 + CHx*8);//DMA->CH0CTRL;
	
	tmpreg = *pREG;
	tmpreg &= ~(DMA_CHxCR_DIR_Msk);
	tmpreg |= (SetValue&DMA_CHxCR_DIR_Msk);
	*pREG = tmpreg;

}

uint32_t DMA_CHxCR_DIR_Get(DMA_CH_Type CHx)
{
	uint32_t *pREG;
	pREG = (uint32_t *)(DMA_BASE + 0x04 + CHx*8);
	return (*pREG & DMA_CHxCR_DIR_Msk);
}

/* �����������
00���ֽڣ�8bit
01�����֣�16bit
10���֣�32bit
11��RFU ��غ��� */
void DMA_CHxCR_BDW_Set(DMA_CH_Type CHx, uint32_t SetValue)
{
	uint32_t *pREG;
	uint32_t tmpreg;    
	pREG = (uint32_t *)(DMA_BASE + 0x04 + CHx*8);//DMA->CH0CTRL;
	
	tmpreg = *pREG;
	tmpreg &= ~(DMA_CHxCR_BDW_Msk);
	tmpreg |= (SetValue&DMA_CHxCR_BDW_Msk);
	*pREG = tmpreg;
}

uint32_t DMA_CHxCR_BDW_Get(DMA_CH_Type CHx)
{
	uint32_t *pREG;
	pREG = (uint32_t *)(DMA_BASE + 0x04 + CHx*8);
	return (*pREG & DMA_CHxCR_BDW_Msk);
}

/* ѭ������ģʽ
0���ر�ѭ��ģʽ
1��ʹ��ѭ��ģʽ ��غ��� */
void DMA_CHxCR_CIRC_Setable(DMA_CH_Type CHx, FunState NewState)
{
	
	uint32_t *pREG;
	
	pREG = (uint32_t *)(DMA_BASE + 0x04 + CHx*8);
	if (NewState == ENABLE)
	{
		*pREG |= (DMA_CHxCR_CIRC_Msk);
	}
	else
	{
		*pREG &= ~(DMA_CHxCR_CIRC_Msk);
	}
	
}

FunState DMA_CHxCR_CIRC_Getable(DMA_CH_Type CHx)
{
	
	uint32_t *pREG;
	
	pREG = (uint32_t *)(DMA_BASE + 0x04 + CHx*8);;
	if (*pREG & (DMA_CHxCR_CIRC_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Channelx��������ж�ʹ��
1��ʹ�ܴ�������ж�
0���رմ�������ж� ��غ��� */
void DMA_CHxCR_CHxFTIE_Setable(DMA_CH_Type CHx, FunState NewState)
{
	uint32_t *pREG;
	
	pREG = (uint32_t *)(DMA_BASE + 0x04 + CHx*8);
	if (NewState == ENABLE)
	{
		*pREG |= (DMA_CHxCR_CHxFTIE_Msk);
	}
	else
	{
		*pREG &= ~(DMA_CHxCR_CHxFTIE_Msk);
	}
}

FunState DMA_CHxCR_CHxFTIE_Getable(DMA_CH_Type CHx)
{
	uint32_t *pREG;
	
	pREG = (uint32_t *)(DMA_BASE + 0x04 + CHx*8);;
	if (*pREG & (DMA_CHxCR_CHxFTIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Channelx��̴�������ж�ʹ��
1��ʹ�ܰ���ж�
0���رհ���ж� ��غ��� */
void DMA_CHxCR_CHxHTIE_Setable(DMA_CH_Type CHx, FunState NewState)
{
	uint32_t *pREG;
	
	pREG = (uint32_t *)(DMA_BASE + 0x04 + CHx*8);
	if (NewState == ENABLE)
	{
		*pREG |= (DMA_CHxCR_CHxHTIE_Msk);
	}
	else
	{
		*pREG &= ~(DMA_CHxCR_CHxHTIE_Msk);
	}
	
}

FunState DMA_CHxCR_CHxHTIE_Getable(DMA_CH_Type CHx)
{
	uint32_t *pREG;
	
	pREG = (uint32_t *)(DMA_BASE + 0x04 + CHx*8);;
	if (*pREG & (DMA_CHxCR_CHxHTIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Channelxʹ��
1������ͨ��0
0���ر�ͨ��0 ��غ��� */
void DMA_CHxCR_ChxEN_Setable(DMA_CH_Type CHx, FunState NewState)
{
	uint32_t *pREG;
	pREG = (uint32_t *)(DMA_BASE + 0x04 + CHx*8);
	if (NewState == ENABLE)
	{
		*pREG |= (DMA_CHxCR_ChxEN_Msk);
		
	}
	else
	{
		*pREG &= ~(DMA_CHxCR_ChxEN_Msk);
	}

}

FunState DMA_CHxCR_ChxEN_Getable(DMA_CH_Type CHx)
{
	uint32_t *pREG;
	pREG = (uint32_t *)(DMA_BASE + 0x04 + CHx*8);;
	if (*pREG & (DMA_CHxCR_ChxEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Channelx�洢��ָ���ַ��DMA��������ǰ�����˼Ĵ���д��洢��Ŀ���ַ��
��ָ��ָ��յ�ַʱ��DMA���ʽ�����hardfault
��ָ��ָ��Flashʱ����ֹ��Flashд�����ݡ�
������Բ�ѯ��ǰDMA�����Ŀ��洢����ַ��

ע�⣺��ָ���ָֹ��0x00080000~0x1FFFFFFF��ַ����ε�ַΪflash������Ϣ����ָ����ε�ַ������DMA�����е��²���Ԥ�ƵĽ�� ��غ��� */
void DMA_CHxMAR_Write(DMA_CH_Type CHx, uint32_t SetValue)
{
	uint32_t *pREG;
	pREG = (uint32_t *)(DMA_BASE + 8 + CHx*8);
	*pREG = SetValue;
}

uint32_t DMA_CHxMAR_Read(DMA_CH_Type CHx)
{
	uint32_t *pREG;
	pREG = (uint32_t *)(DMA_BASE + 8 + CHx*8);
	return (*pREG);
}

/* Channel11���䳤�ȣ�1-8192�δ��䣬����Flash->RAM����ʱ��Ч��RAM->Flash����Ϊ�̶�����64�δ��� ��غ��� */
void DMA_CH11CR_CH11TSIZE_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
    
    SetValue <<= DMA_CH11CR_CH11TSIZE_Pos;
	
    tmpreg = DMA->CH11CR;
	tmpreg &= ~(DMA_CH11CR_CH11TSIZE_Msk);
	tmpreg |= (SetValue & DMA_CH11CR_CH11TSIZE_Msk);
	DMA->CH11CR = tmpreg;
}

uint32_t DMA_CH11CR_CH11TSIZE_Get(void)
{
	return (uint32_t)((DMA->CH11CR & DMA_CH11CR_CH11TSIZE_Msk) >> DMA_CH11CR_CH11TSIZE_Pos);
}

/* Channel11���ȼ�
00��Low
01��Medium
10��High
11��Very High ��غ��� */
void DMA_CH11CR_CH11PRI_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = DMA->CH11CR;
	tmpreg &= ~(DMA_CH11CR_CH11PRI_Msk);
	tmpreg |= (SetValue & DMA_CH11CR_CH11PRI_Msk);
	DMA->CH11CR = tmpreg;
}

uint32_t DMA_CH11CR_CH11PRI_Get(void)
{
	return (DMA->CH11CR & DMA_CH11CR_CH11PRI_Msk);
}

/* Channel11���䷽��
1��Flash->RAM����
0��RAM->Flash���� ��غ��� */
void DMA_CH11CR_CH11DIR_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = DMA->CH11CR;
	tmpreg &= ~(DMA_CH11CR_CH11DIR_Msk);
	tmpreg |= (SetValue & DMA_CH11CR_CH11DIR_Msk);
	DMA->CH11CR = tmpreg;
}

uint32_t DMA_CH11CR_CH11DIR_Get(void)
{
	return (DMA->CH11CR & DMA_CH11CR_CH11DIR_Msk);
}

/* Channel11 RAM��ַ�������ã�����Flash->RAM��������Ч
1��RAM��ַ����
0��RAM��ַ�ݼ� ��غ��� */
void DMA_CH11CR_CH11RI_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = DMA->CH11CR;
	tmpreg &= ~(DMA_CH11CR_CH11RI_Msk);
	tmpreg |= (SetValue & DMA_CH11CR_CH11RI_Msk);
	DMA->CH11CR = tmpreg;
}

uint32_t DMA_CH11CR_CH11RI_Get(void)
{
	return (DMA->CH11CR & DMA_CH11CR_CH11RI_Msk);
}

/* Channel11 Flash��ַ�������ã�����Flash->RAM��������Ч
1��Flash��ַ����
0��Flash��ַ�ݼ� ��غ��� */
void DMA_CH11CR_CH11FI_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = DMA->CH11CR;
	tmpreg &= ~(DMA_CH11CR_CH11FI_Msk);
	tmpreg |= (SetValue & DMA_CH11CR_CH11FI_Msk);
	DMA->CH11CR = tmpreg;
}

uint32_t DMA_CH11CR_CH11FI_Get(void)
{
	return (DMA->CH11CR & DMA_CH11CR_CH11FI_Msk);
}

/* Channel11��������ж�ʹ��
1��ʹ�ܴ�������ж�
0���رմ�������ж� ��غ��� */
void DMA_CH11CR_CH11FTIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		DMA->CH11CR |= (DMA_CH11CR_CH11FTIE_Msk);
	}
	else
	{
		DMA->CH11CR &= ~(DMA_CH11CR_CH11FTIE_Msk);
	}
}

FunState DMA_CH11CR_CH11FTIE_Getable(void)
{
	if (DMA->CH11CR & (DMA_CH11CR_CH11FTIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Channel11��̴�������ж�ʹ��
1��ʹ�ܰ���ж�
0���رհ���ж� ��غ��� */
void DMA_CH11CR_CH11HTIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		DMA->CH11CR |= (DMA_CH11CR_CH11HTIE_Msk);
	}
	else
	{
		DMA->CH11CR &= ~(DMA_CH11CR_CH11HTIE_Msk);
	}
}

FunState DMA_CH11CR_CH11HTIE_Getable(void)
{
	if (DMA->CH11CR & (DMA_CH11CR_CH11HTIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Channel11ʹ��
1������ͨ��0
0���ر�ͨ��0 ��غ��� */
void DMA_CH11CR_CH11EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		DMA->CH11CR |= (DMA_CH11CR_CH11EN_Msk);
	}
	else
	{
		DMA->CH11CR &= ~(DMA_CH11CR_CH11EN_Msk);
	}
}

FunState DMA_CH11CR_CH11EN_Getable(void)
{
	if (DMA->CH11CR & (DMA_CH11CR_CH11EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Channel11 Flashָ���ַ��DMA��������ǰ�����˼Ĵ���д��FlashĿ���ַ��DMA������˼Ĵ�����DMA�����������Լ�
������Բ�ѯ��ǰDMA�����Ŀ��Flash��ַ
�˼Ĵ�����λ��bit5-0������Flash->RAM��������Ч��RAM->Flash������Ĭ�϶���Flash��half-sector��ʼ��ַ ��غ��� */
void DMA_CH11FAR_Write(uint32_t SetValue)
{
	DMA->CH11FAR = ((SetValue >> 2) & DMA_CH11FAR_CH11FLSAD_Msk);
}

uint32_t DMA_CH11FAR_Read(void)
{
	return (DMA->CH11FAR & DMA_CH11FAR_CH11FLSAD_Msk);
}

/* Channel7 RAM��ָ���ַ��DMA��������ǰ�����˼Ĵ���д��RAMĿ���ַ��word��ַ����DMA������˼Ĵ�����DMA�����������Լ�
������Բ�ѯ��ǰDMA�����Ŀ��RAM��ַ ��غ��� */
void DMA_CH11RAR_Write(uint32_t SetValue)
{
	DMA->CH11RAR = ((SetValue >> 2) & DMA_CH11RAR_CH7RAMAD_Msk);
}

uint32_t DMA_CH11RAR_Read(void)
{
	return (DMA->CH11RAR & DMA_CH11RAR_CH7RAMAD_Msk);
}

/* DMA�����ַ�����־�����洢��ָ�볬��RAM��Flash�Ϸ���ַ��Χʱ��λ ��غ��� */
void DMA_ISR_DMA_ADDRERR_Clr(void)
{
	DMA->ISR = DMA_ISR_DMA_ADDRERR_Msk;
}

FlagStatus DMA_ISR_DMA_ADDRERR_Chk(void)
{
	if (DMA->ISR & DMA_ISR_DMA_ADDRERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* DMAͨ��x������ɱ�־��Ӳ����λ�����д1����
1����Ӧͨ���������
0����Ӧͨ������δ��� ��غ��� */
void DMA_ISR_DMACHFT_Clr(DMA_CH_Type CHx)
{
	DMA->ISR = ((1 << DMA_ISR_DMACHFT_Pos) << CHx);
}

FlagStatus DMA_ISR_DMACHFT_Chk(DMA_CH_Type CHx)
{
	if (DMA->ISR & ((1 << DMA_ISR_DMACHFT_Pos) << CHx))
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* DMAͨ��x�����̱�־��Ӳ����λ�����д1���� ��غ��� */
void DMA_ISR_DMACHHT_Clr(DMA_CH_Type CHx)
{
	DMA->ISR = (1 << DMA_ISR_DMACHHT_Pos) << CHx;
}

FlagStatus DMA_ISR_DMACHHT_Chk(DMA_CH_Type CHx)
{
	if (DMA->ISR & ((1 << DMA_ISR_DMACHHT_Pos) << CHx))
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* Channelx���䳤��shadow�Ĵ�����ѭ��ģʽ�����ʹ����CIRC_UPD�Ĵ��������ڱ��ִ�����ɺ�shadow�Ĵ���ֵ���Ƶ�CHxTSIZE�С� ��غ��� */
void DMA_CHxCSR_CHxTSIZE_SDW_Set(DMA_CH_Type CHx, uint32_t SetValue)
{
	
	uint32_t *pREG;
	uint32_t tmpreg;    
	pREG = (uint32_t *)(DMA_BASE + 0x100 + CHx*8);//DMA->CH0CTRL;
	SetValue <<= DMA_CHxCSR_CHxTSIZE_SDW_Pos;//�ֹ����	
	
	tmpreg = *pREG;
	tmpreg &= ~(DMA_CHxCSR_CHxTSIZE_SDW_Msk);
	tmpreg |= (SetValue&DMA_CHxCSR_CHxTSIZE_SDW_Msk);
	*pREG = tmpreg;

}

uint32_t DMA_CHxCSR_CHxTSIZE_SDW_Get(DMA_CH_Type CHx)
{
	uint32_t *pREG;
	pREG = (uint32_t *)(DMA_BASE + 0x100 + CHx*8);
	return (uint32_t)((*pREG & DMA_CHxCSR_CHxTSIZE_SDW_Msk) >> DMA_CHxCSR_CHxTSIZE_SDW_Pos);
}

/* RAM��ַ��������shadow�Ĵ�����ѭ��ģʽ�����ʹ����CIRC_UPD�Ĵ��������ڱ��ִ�����ɺ�shadow�Ĵ���ֵ���Ƶ�CHxTSIZE�С� ��غ��� */
void DMA_CHxCSR_CHxINC_SDW_Set(DMA_CH_Type CHx, uint32_t SetValue)
{
	uint32_t *pREG;
	uint32_t tmpreg;    
	pREG = (uint32_t *)(DMA_BASE + 0x100 + CHx*8);//DMA->CH0CTRL;
	
	tmpreg = *pREG;
	tmpreg &= ~(DMA_CHxCSR_CHxINC_SDW_Msk);
	tmpreg |= (SetValue&DMA_CHxCSR_CHxINC_SDW_Msk);
	*pREG = tmpreg;

}

uint32_t DMA_CHxCSR_CHxINC_SDW_Get(DMA_CH_Type CHx)
{
	uint32_t *pREG;
	pREG = (uint32_t *)(DMA_BASE + 0x100 + CHx*8);
	return (*pREG & DMA_CHxCSR_CHxINC_SDW_Msk);
}

/* Channelx�洢��ָ���ַӰ�ӼĴ�����
ѭ��ģʽ�����ʹ����CIRC_UPD�Ĵ��������ڱ��ִ�����ɺ�shadow�Ĵ���ֵ���Ƶ�CHxMEMAD�С� ��غ��� */
void DMA_CHxMASR_Write(DMA_CH_Type CHx, uint32_t SetValue)
{
	uint32_t *pREG;
	pREG = (uint32_t *)(DMA_BASE + 0x104 + CHx*8);
	*pREG = SetValue;
}

uint32_t DMA_CHxMASR_Read(DMA_CH_Type CHx)
{
	uint32_t *pREG;
	pREG = (uint32_t *)(DMA_BASE + 0x104 + CHx*8);
	return (*pREG);
}


void DMA_DeInit(void)
{
    RMU_PRSTEN_Write(0x13579BDF);
    RMU_AHBRST_DMARST_Setable(ENABLE);
    RMU_AHBRST_DMARST_Setable(DISABLE);
    RMU_PRSTEN_Write(0x00000000);
}

void DMA_Init(DMA_InitTypeDef *para)
{
    if (DMA_CH11 == para->CHx)
    {
		DMA_CHxCR_ChxEN_Setable(para->CHx, DISABLE);    	// ͨ���ر�ʹ��
        DMA_CH11CR_CH11TSIZE_Set(para->CHxTSIZE);   		// ͨ�����䳤��
        DMA_CH11CR_CH11PRI_Set(para->CHxPRI);       		// ͨ�����ȼ�
        DMA_CH11CR_CH11DIR_Set(para->CHxDIR);       		// ���ݴ��䷽��
        DMA_CH11CR_CH11RI_Set(para->CH11RI);        		// RAM��������
        DMA_CH11CR_CH11FI_Set(para->CH11FI);        		// FLS��������
        DMA_CH11CR_CH11FTIE_Setable(para->CHxFTIE);    		// ��������ж�
        DMA_CH11CR_CH11HTIE_Setable(para->CHxHTIE);    		// ��������ж�
        
        DMA_CHxMAR_Write(para->CHx, para->CHxRAMAD);        // DMA����RAM��ַ
        DMA_CH11FAR_Write(para->CH11FLSAD);                 // DMA����Flash��ַ
		
		DMA_CH11CR_CH11EN_Setable(para->CHxEN);        		// ͨ��ʹ��
    }
    else
    {
		DMA_CHxCR_ChxEN_Setable(para->CHx, DISABLE);    	// ͨ���ر�ʹ��
        DMA_CHxCR_CHxTSIZE_Set(para->CHx, para->CHxTSIZE);  // ͨ�����䳤��
        DMA_CHxCR_CHxPRI_Set(para->CHx, para->CHxPRI);      // ͨ�����ȼ�
        DMA_CHxCR_CHxINC_Set(para->CHx, para->CHxINC);      // ͨ����ַ��������
        DMA_CHxCR_CHxSSEL_Set(para->CHx, para->CHxSSEL);    // ͨ������ѡ��
        DMA_CHxCR_DIR_Set(para->CHx, para->CHxDIR);         // ͨ�����䷽��
        DMA_CHxCR_BDW_Set(para->CHx, para->CHxBDW);         // ͨ���������
        DMA_CHxCR_CIRC_Setable(para->CHx, para->CHxCICR);   // ѭ������ģʽ
        DMA_CHxCR_CHxFTIE_Setable(para->CHx, para->CHxFTIE);    // ��������ж�
        DMA_CHxCR_CHxHTIE_Setable(para->CHx, para->CHxHTIE);    // ��������ж�
        
        DMA_CHxMAR_Write(para->CHx, para->CHxRAMAD);        // DMA����RAM��ַ
		
		DMA_CHxCR_ChxEN_Setable(para->CHx, para->CHxEN);    // ͨ��ʹ��
    }
}


/******END OF FILE****/
