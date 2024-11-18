/**
  ******************************************************************************
  * @file    fm33a0xxev_flash.c
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/

#include "fm33a0xxev_flash.h"

/** @addtogroup fm33a0xxev_StdPeriph_Driver
  * @{
  */

/** @defgroup FLASH 
  * @brief FLASH driver modules
  * @{
  */ 

/* Flash���ȴ��������� (Wait Cycles Config)
00/11��0 wait cycle
01��1 wait cycle
10��2 wait cycles
CPU��ƵС�ڵ���24MHzʱ������Ҫ����wait����Ƶ����24MС��48Mhzʱʹ��1 wait����Ƶ����48Mhzʱʹ��2 wait ��غ��� */
void FLS_RDCR_WAIT_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = FLS->RDCR;
	tmpreg &= ~(FLS_RDCR_WAIT_Msk);
	tmpreg |= (SetValue & FLS_RDCR_WAIT_Msk);
	FLS->RDCR = tmpreg;
}

uint32_t FLS_RDCR_WAIT_Get(void)
{
	return (FLS->RDCR & FLS_RDCR_WAIT_Msk);
}

/* ָ��Ԥȡָʹ�ܣ���WAIT==00�������д1��Ч (Prefetch Enable)
1��ʹ��Prefetch
0����ֹPrefetch ��غ��� */
void FLS_PFCR_PRFTEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		FLS->PFCR |= (FLS_PFCR_PRFTEN_Msk);
	}
	else
	{
		FLS->PFCR &= ~(FLS_PFCR_PRFTEN_Msk);
	}
}

FunState FLS_PFCR_PRFTEN_Getable(void)
{
	if (FLS->PFCR & (FLS_PFCR_PRFTEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* DBG���ƼĴ���ʹ��
0������
1��ʹ�� */
FunState FLS_OPTBR_DBGCFGEN_Chk(void)
{
	if (FLS->OPTBR & FLS_OPTBR_DBGCFGEN_Msk)
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Information2��������־ (IF2 Lock Enable)
0��δ����
1����������������������ɸ�д������ ��غ��� */
FlagStatus FLS_OPTBR_IF2LOCK_Chk(void)
{
	if (FLS->OPTBR & FLS_OPTBR_IF2LOCK_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* Information1��������־ (IF1 Lock Enable)
0��δ����
1����������������������ɸ�д������ ��غ��� */
FlagStatus FLS_OPTBR_IF1LOCK_Chk(void)
{
	if (FLS->OPTBR & FLS_OPTBR_IF1LOCK_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* DataFlashʹ�� (DataFlash Enable)
0����data flash
1����data flash ��غ��� */
FunState FLS_OPTBR_DFLSEN_Getable(void)
{
	if (FLS->OPTBR & (FLS_OPTBR_DFLSEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* BootSwap����ʹ�� (BootSwap Enable)
00/01/11����ֹBootSwap����
10������BootSwap ��غ��� */
FunState FLS_OPTBR_BTSEN_Getable(void)
{
	if ((FLS->OPTBR & (FLS_OPTBR_BTSEN_Msk))==(0x10<<8))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Ӧ�ô���Ȩ������ʹ�� (AppCode Lock Enable)
00/01/11��ACLOCK��ʹ��
10��ACLOCKʹ�� ��غ��� */
FunState FLS_OPTBR_ACLOCKEN_Getable(void)
{
	if ((FLS->OPTBR & (FLS_OPTBR_ACLOCKEN_Msk))==(0x10<<2))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Debug Port��ȡ����ʹ�� (Debug Read Protection Enable)
00/01/11��DBRDP��ʹ��
10��DBRDPʹ�� ��غ��� */
uint32_t FLS_OPTBR_DBRDPEN_Getable(void)
{
	 return (FLS->OPTBR & (FLS_OPTBR_DBRDPEN_Msk));
	
}

uint32_t FLS_OPTBR_Read(void)
{
	return (FLS->OPTBR);
}



/* Flash������������ (Erase Type)
00/11��Page Erase
01��Sector Erase
10��Chip Erase (SWD only) ��غ��� */
void FLS_EPCR_ERTYPE_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = FLS->EPCR;
	tmpreg &= ~(FLS_EPCR_ERTYPE_Msk);
	tmpreg |= (SetValue & FLS_EPCR_ERTYPE_Msk);
	FLS->EPCR = tmpreg;
}

uint32_t FLS_EPCR_ERTYPE_Get(void)
{
	return (FLS->EPCR & FLS_EPCR_ERTYPE_Msk);
}

/* Program Request
�����λ��Ӳ����ɱ�̺��Զ����� ��غ��� */
void FLS_EPCR_PREQ_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = FLS->EPCR;
	tmpreg &= ~(FLS_EPCR_PREQ_Msk);
	tmpreg |= (SetValue & FLS_EPCR_PREQ_Msk);
	FLS->EPCR = tmpreg;
}

uint32_t FLS_EPCR_PREQ_Get(void)
{
	return (FLS->EPCR & FLS_EPCR_PREQ_Msk);
}

/* Erase Request
�����λ��Ӳ����ɲ������Զ����� ��غ��� */
void FLS_EPCR_EREQ_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = FLS->EPCR;
	tmpreg &= ~(FLS_EPCR_EREQ_Msk);
	tmpreg |= (SetValue & FLS_EPCR_EREQ_Msk);
	FLS->EPCR = tmpreg;
}

uint32_t FLS_EPCR_EREQ_Get(void)
{
	return (FLS->EPCR & FLS_EPCR_EREQ_Msk);
}

/* Flash��дKey����Ĵ������������SWD��������дǰ������ȷ����˵�ַд��Ϸ�KEY���С� (Flash Key) ��غ��� */
void FLS_KEY_Write(uint32_t SetValue)
{
	FLS->KEY = (SetValue);
}

/* OTP��̴����ж�ʹ�ܣ�1��Ч (OTP program error Interrupt Enable) ��غ��� */
void FLS_IER_OTPIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		FLS->IER |= (FLS_IER_OTPIE_Msk);
	}
	else
	{
		FLS->IER &= ~(FLS_IER_OTPIE_Msk);
	}
}

FunState FLS_IER_OTPIE_Getable(void)
{
	if (FLS->IER & (FLS_IER_OTPIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Flash��дȨ�޴����ж�ʹ�ܣ�1��Ч (Flash Authentication Error Interrupt Enable) ��غ��� */
void FLS_IER_AUTHIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		FLS->IER |= (FLS_IER_AUTHIE_Msk);
	}
	else
	{
		FLS->IER &= ~(FLS_IER_AUTHIE_Msk);
	}
}

FunState FLS_IER_AUTHIE_Getable(void)
{
	if (FLS->IER & (FLS_IER_AUTHIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Flash KEY�����ж�ʹ�ܣ�1��Ч (Flash Key Error Interrupt Enable) ��غ��� */
void FLS_IER_KEYIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		FLS->IER |= (FLS_IER_KEYIE_Msk);
	}
	else
	{
		FLS->IER &= ~(FLS_IER_KEYIE_Msk);
	}
}

FunState FLS_IER_KEYIE_Getable(void)
{
	if (FLS->IER & (FLS_IER_KEYIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��д��ʱʱ�Ӵ����ж�ʹ�ܣ�1��Ч (Erase/Program Clock Error Interrupt Enable) ��غ��� */
void FLS_IER_CKIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		FLS->IER |= (FLS_IER_CKIE_Msk);
	}
	else
	{
		FLS->IER &= ~(FLS_IER_CKIE_Msk);
	}
}

FunState FLS_IER_CKIE_Getable(void)
{
	if (FLS->IER & (FLS_IER_CKIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �����ɱ�־�ж�ʹ�ܣ�1��Ч (Program Done Interrupt Enable) ��غ��� */
void FLS_IER_PRDIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		FLS->IER |= (FLS_IER_PRDIE_Msk);
	}
	else
	{
		FLS->IER &= ~(FLS_IER_PRDIE_Msk);
	}
}

FunState FLS_IER_PRDIE_Getable(void)
{
	if (FLS->IER & (FLS_IER_PRDIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��д��ɱ�־�ж�ʹ�ܣ�1��Ч (Erase Done Interrupt Enable) ��غ��� */
void FLS_IER_ERDIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		FLS->IER |= (FLS_IER_ERDIE_Msk);
	}
	else
	{
		FLS->IER &= ~(FLS_IER_ERDIE_Msk);
	}
}

FunState FLS_IER_ERDIE_Getable(void)
{
	if (FLS->IER & (FLS_IER_ERDIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Flash��дKEY����״̬ (Flash Key Status)
000��Flashд����״̬��δ����KEY
001��ȫ������״̬
010������������״̬
011����̽���״̬
100��KEY��������״̬����Ҫ��λ���ܽ���
101/110/111��RFU ��غ��� */
uint32_t FLS_ISR_KEYSTA_Get(void)
{
	return (FLS->ISR & FLS_ISR_KEYSTA_Msk);
}

/* BootSwap��־�Ĵ��� (BootSwap)
0������������ΪFlash�����ַ0000H~1FFFH
1������������ΪFlash�����ַ2000H~3FFFH ��غ��� */
uint32_t FLS_ISR_BTSF_Get(void)
{
	return (FLS->ISR & FLS_ISR_BTSF_Msk);
}

/* OTP page���Ȩ�޴���Ӳ����λ�����д1���� (OTP program Error Flag. Write 1 to clear)
1�����Զ��ѱ�̵�OTP�ֽڽ��б��
0����OTP��̴��� ��غ��� */
void FLS_ISR_OTPERR_Clr(void)
{
	FLS->ISR = FLS_ISR_OTPERR_Msk;
}

FlagStatus FLS_ISR_OTPERR_Chk(void)
{
	if (FLS->ISR & FLS_ISR_OTPERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* Flash��дȨ�޴��󣬶�ȡLOCK�����ݻ��LOCK���дʱ��λ�����д1���㡣(Flash Authentication Error Flag, write 1 to clear)
1��Flash����Ȩ�޴���
0��Flash����û�з���Ȩ�޴��� ��غ��� */
void FLS_ISR_AUTHERR_Clr(void)
{
	FLS->ISR = FLS_ISR_AUTHERR_Msk;
}

FlagStatus FLS_ISR_AUTHERR_Chk(void)
{
	if (FLS->ISR & FLS_ISR_AUTHERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* Flash KEY����Ӳ����λ�����д1���� (Flash Key Error Flag, write 1 to clear) ��غ��� */
void FLS_ISR_KEYERR_Clr(void)
{
	FLS->ISR = FLS_ISR_KEYERR_Msk;
}

FlagStatus FLS_ISR_KEYERR_Chk(void)
{
	if (FLS->ISR & FLS_ISR_KEYERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��д��ʱʱ�Ӵ���NVMIF��дFlashʱ���RCHFδʹ�ܣ��򴥷�CKERR�жϣ����д1���㡣(Erase/Program Clock Error Flag, write 1 to clear) ��غ��� */
void FLS_ISR_CKERR_Clr(void)
{
	FLS->ISR = FLS_ISR_CKERR_Msk;
}

FlagStatus FLS_ISR_CKERR_Chk(void)
{
	if (FLS->ISR & FLS_ISR_CKERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* Program Done�������ɱ�־��Ӳ����λ�����д1����(Program Done Flag,write 1 to clear) ��غ��� */
void FLS_ISR_PRD_Clr(void)
{
	FLS->ISR = FLS_ISR_PRD_Msk;
}

FlagStatus FLS_ISR_PRD_Chk(void)
{
	if (FLS->ISR & FLS_ISR_PRD_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* Erase Done����д��ɱ�־��Ӳ����λ�����д1����(Erase Done Flag,write 1 to clear) ��غ��� */
void FLS_ISR_ERD_Clr(void)
{
	FLS->ISR = FLS_ISR_ERD_Msk;
}

FlagStatus FLS_ISR_ERD_Chk(void)
{
	if (FLS->ISR & FLS_ISR_ERD_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}


void FLS_Deinit(void)
{
	//FLS->RDCR = 0x00000000;
	//FLS->PFCR = 0x00000000;
	//FLS->OPTBR = 0x00000105;
	//FLS->EPCR = 0x00000000;
	//FLS->KEY = 0x00000000;
	//FLS->IER = 0x00000000;
	//FLS->ISR = 0x00000000;
}

/******END OF FILE****/
