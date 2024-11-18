/**
  ******************************************************************************
  * @file    fm33a0xxev_iwdt.c
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/

#include "fm33a0xxev_iwdt.h"

/** @addtogroup fm33a0xxev_StdPeriph_Driver
  * @{
  */

/** @defgroup IWDT 
  * @brief IWDT driver modules
  * @{
  */ 
 
/* IWDT�����������˵�ַд��0x1234_5A5Aʱ�幷 ��غ��� */
void IWDT_SERV_IWDTSERV_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = IWDT->SERV;
	tmpreg &= ~(IWDT_SERV_IWDTSERV_Msk);
	tmpreg |= (SetValue & IWDT_SERV_IWDTSERV_Msk);
	IWDT->SERV = tmpreg;
}

/* IWDT�����������
x00��125ms
x01��500ms
x10��2s
x11��8s
˵������bit2Ϊ0ʱ�����ߺ���ʹ�ö����ڣ���bit2Ϊ1ʱ�����ߺ��Զ�ʹ��4096s��������״̬�½�֧��125ms/500ms/2s/8s�������ڡ� ��غ��� */
void IWDT_CFGR_Write(uint32_t SetValue)
{
	IWDT->CFGR = (SetValue & IWDT_CFGR_IWDTOVP_Msk);
}

uint32_t IWDT_CFGR_Read(void)
{
	return (IWDT->CFGR & IWDT_CFGR_IWDTOVP_Msk);
}

/* IWDT��ǰ����ֵ ��غ��� */
uint32_t IWDT_CNTR_IWDTCNT_Get(void)
{
	return (IWDT->CNTR & IWDT_CNTR_IWDTCNT_Msk);
}


void IWDT_Deinit(void)
{
	//IWDT->SERV = 0x00000000;
	//IWDT->CFGR = 0x00000001;
	//IWDT->CNTR = ;
}

/******END OF FILE****/
