/**
  ******************************************************************************
  * @file    fm33a0xxev_dbg.c
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/

#include "fm33a0xxev_dbg.h"

/** @addtogroup fm33a0xxev_StdPeriph_Driver
  * @{
  */

/** @defgroup DBG 
  * @brief DBG driver modules
  * @{
  */ 
  
/* Debug״̬��LPTIMʹ�ܿ���λ
1��Debugʱ�ر�LPTIM
0��Debugʱ����LPTIMԭ��״̬ ��غ��� */
void DBG_CR_DBG_LPT_STOP_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		DBG->CR |= (DBG_CR_DBG_LPT_STOP_Msk);
	}
	else
	{
		DBG->CR &= ~(DBG_CR_DBG_LPT_STOP_Msk);
	}
}

FunState DBG_CR_DBG_LPT_STOP_Getable(void)
{
	if (DBG->CR & (DBG_CR_DBG_LPT_STOP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Debug״̬��BSTIMʹ�ܿ���λ
1��Debugʱ�ر�BSTIM
0��Debugʱ����BSTIMԭ��״̬ ��غ��� */
void DBG_CR_DBG_BST_STOP_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		DBG->CR |= (DBG_CR_DBG_BST_STOP_Msk);
	}
	else
	{
		DBG->CR &= ~(DBG_CR_DBG_BST_STOP_Msk);
	}
}

FunState DBG_CR_DBG_BST_STOP_Getable(void)
{
	if (DBG->CR & (DBG_CR_DBG_BST_STOP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Debug״̬��ET4ʹ�ܿ���λ
1��Debugʱ�ر�ET4
0��Debugʱ����ET4ԭ��״̬ ��غ��� */
void DBG_CR_DBG_ET4_STOP_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		DBG->CR |= (DBG_CR_DBG_ET4_STOP_Msk);
	}
	else
	{
		DBG->CR &= ~(DBG_CR_DBG_ET4_STOP_Msk);
	}
}

FunState DBG_CR_DBG_ET4_STOP_Getable(void)
{
	if (DBG->CR & (DBG_CR_DBG_ET4_STOP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Debug״̬��ET3ʹ�ܿ���λ
1��Debugʱ�ر�ET3
0��Debugʱ����ET3ԭ��״̬ ��غ��� */
void DBG_CR_DBG_ET3_STOP_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		DBG->CR |= (DBG_CR_DBG_ET3_STOP_Msk);
	}
	else
	{
		DBG->CR &= ~(DBG_CR_DBG_ET3_STOP_Msk);
	}
}

FunState DBG_CR_DBG_ET3_STOP_Getable(void)
{
	if (DBG->CR & (DBG_CR_DBG_ET3_STOP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Debug״̬��ET2ʹ�ܿ���λ
1��Debugʱ�ر�ET2
0��Debugʱ����ET2ԭ��״̬ ��غ��� */
void DBG_CR_DBG_ET2_STOP_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		DBG->CR |= (DBG_CR_DBG_ET2_STOP_Msk);
	}
	else
	{
		DBG->CR &= ~(DBG_CR_DBG_ET2_STOP_Msk);
	}
}

FunState DBG_CR_DBG_ET2_STOP_Getable(void)
{
	if (DBG->CR & (DBG_CR_DBG_ET2_STOP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Debug״̬��ET1ʹ�ܿ���λ
1��Debugʱ�ر�ET1
0��Debugʱ����ET1ԭ��״̬ ��غ��� */
void DBG_CR_DBG_ET1_STOP_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		DBG->CR |= (DBG_CR_DBG_ET1_STOP_Msk);
	}
	else
	{
		DBG->CR &= ~(DBG_CR_DBG_ET1_STOP_Msk);
	}
}

FunState DBG_CR_DBG_ET1_STOP_Getable(void)
{
	if (DBG->CR & (DBG_CR_DBG_ET1_STOP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Debug״̬��BT2ʹ�ܿ���λ
1��Debugʱ�ر�BT2
0��Debugʱ����BT2ԭ��״̬ ��غ��� */
void DBG_CR_DBG_BT2_STOP_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		DBG->CR |= (DBG_CR_DBG_BT2_STOP_Msk);
	}
	else
	{
		DBG->CR &= ~(DBG_CR_DBG_BT2_STOP_Msk);
	}
}

FunState DBG_CR_DBG_BT2_STOP_Getable(void)
{
	if (DBG->CR & (DBG_CR_DBG_BT2_STOP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Debug״̬��BT1ʹ�ܿ���λ
1��Debugʱ�ر�BT1
0��Debugʱ����BT1ԭ��״̬ ��غ��� */
void DBG_CR_DBG_BT1_STOP_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		DBG->CR |= (DBG_CR_DBG_BT1_STOP_Msk);
	}
	else
	{
		DBG->CR &= ~(DBG_CR_DBG_BT1_STOP_Msk);
	}
}

FunState DBG_CR_DBG_BT1_STOP_Getable(void)
{
	if (DBG->CR & (DBG_CR_DBG_BT1_STOP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Debug״̬��WWDTʹ�ܿ���λ
1��Debugʱ�ر�WWDT
0��Debugʱ����WWDTԭ��״̬ ��غ��� */
void DBG_CR_DBG_WWDT_STOP_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		DBG->CR |= (DBG_CR_DBG_WWDT_STOP_Msk);
	}
	else
	{
		DBG->CR &= ~(DBG_CR_DBG_WWDT_STOP_Msk);
	}
}

FunState DBG_CR_DBG_WWDT_STOP_Getable(void)
{
	if (DBG->CR & (DBG_CR_DBG_WWDT_STOP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Debug״̬��IWDTʹ�ܿ���λ
1��Debugʱ�ر�IWDT
0��Debugʱ����IWDT���� ��غ��� */
void DBG_CR_DBG_IWDT_STOP_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		DBG->CR |= (DBG_CR_DBG_IWDT_STOP_Msk);
	}
	else
	{
		DBG->CR &= ~(DBG_CR_DBG_IWDT_STOP_Msk);
	}
}

FunState DBG_CR_DBG_IWDT_STOP_Getable(void)
{
	if (DBG->CR & (DBG_CR_DBG_IWDT_STOP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��ַ�Ƕ�����ʴ����־��д1����
1����ַ�Ƕ�����ʴ���
0��δ���е�ַ�Ƕ������ ��غ��� */
void DBG_HDFR_DABORT_ADDR_FLAG_Clr(void)
{
	DBG->HDFR = DBG_HDFR_DABORT_ADDR_FLAG_Msk;
}

FlagStatus DBG_HDFR_DABORT_ADDR_FLAG_Chk(void)
{
	if (DBG->HDFR & DBG_HDFR_DABORT_ADDR_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* �Ƿ���ַ���ʴ����־��д1����
1�����ߴ����з����˷Ƿ���ַ����HRESPΪ�߲�������
0��δ���ʷǷ���ַ ��غ��� */
void DBG_HDFR_DABORT_RESP_FLAG_Clr(void)
{
	DBG->HDFR = DBG_HDFR_DABORT_RESP_FLAG_Msk;
}

FlagStatus DBG_HDFR_DABORT_RESP_FLAG_Chk(void)
{
	if (DBG->HDFR & DBG_HDFR_DABORT_RESP_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* SVC instructionsδ�����־��д1����
if the SVCall priority is lower than the currently activelevel, 
or if HardFault or NMI is active, 
or PRIMASK is set,
the core should treat SVC instructions as though theywere UNDEFINED�� ��غ��� */
void DBG_HDFR_SVCUNDEF_FLAG_Clr(void)
{
	DBG->HDFR = DBG_HDFR_SVCUNDEF_FLAG_Msk;
}

FlagStatus DBG_HDFR_SVCUNDEF_FLAG_Chk(void)
{
	if (DBG->HDFR & DBG_HDFR_SVCUNDEF_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ִ��BKPTָ���־��д1����
1��ִ����BKPTָ��
0��δִ��BKPTָ�� ��غ��� */
void DBG_HDFR_BKPT_FLAG_Clr(void)
{
	DBG->HDFR = DBG_HDFR_BKPT_FLAG_Msk;
}

FlagStatus DBG_HDFR_BKPT_FLAG_Chk(void)
{
	if (DBG->HDFR & DBG_HDFR_BKPT_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* Thumb-State��־��д1����
1���л���ARM״̬
0������Thumb-State ��غ��� */
void DBG_HDFR_TBIT_FLAG_Clr(void)
{
	DBG->HDFR = DBG_HDFR_TBIT_FLAG_Msk;
}

FlagStatus DBG_HDFR_TBIT_FLAG_Chk(void)
{
	if (DBG->HDFR & DBG_HDFR_TBIT_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ����ָ���־��д1����
1��ִ��������ָ����룬����ͼ��XN������ȡָ
0��������ָ����뱻ִ�� ��غ��� */
void DBG_HDFR_SPECIAL_OP_FLAG_Clr(void)
{
	DBG->HDFR = DBG_HDFR_SPECIAL_OP_FLAG_Msk;
}

FlagStatus DBG_HDFR_SPECIAL_OP_FLAG_Chk(void)
{
	if (DBG->HDFR & DBG_HDFR_SPECIAL_OP_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* hardfault��־λ���κ����͵�hardfault���ᵼ�¸�λ��λ��д1����
1��hardfault ����
0����hardfault���� ��غ��� */
void DBG_HDFR_HDF_REQUEST_FLAG_Clr(void)
{
	DBG->HDFR = DBG_HDFR_HDF_REQUEST_FLAG_Msk;
}

FlagStatus DBG_HDFR_HDF_REQUEST_FLAG_Chk(void)
{
	if (DBG->HDFR & DBG_HDFR_HDF_REQUEST_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}


void DBG_Deinit(void)
{
	//DBG->CR = 0x00003d03;
	//DBG->HDFR = 0x00000000;
}

/******END OF FILE****/
