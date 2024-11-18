/**
  ******************************************************************************
  * @file    fm33a0xxev_rmu.c
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/

#include "fm33a0xxev_rmu.h"

/** @addtogroup fm33a0xxev_StdPeriph_Driver
  * @{
  */

/** @defgroup RMU 
  * @brief RMU driver modules
  * @{
  */ 

/* �µ縴λ��ѹ����00��1.5V01��1.25V����ֹʹ�ã�10��1.35V11��1.4V��Ĭ�ϣ� ��غ��� */
void RMU_PDRCR_PDRCFG_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RMU->PDRCR;
	tmpreg &= ~(RMU_PDRCR_PDRCFG_Msk);
	tmpreg |= (SetValue & RMU_PDRCR_PDRCFG_Msk);
	RMU->PDRCR = tmpreg;
}

uint32_t RMU_PDRCR_PDRCFG_Get(void)
{
	return (RMU->PDRCR & RMU_PDRCR_PDRCFG_Msk);
}

/* �µ縴λʹ��0���ر��µ縴λ1��ʹ���µ縴λ ��غ��� */
void RMU_PDRCR_PDREN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RMU->PDRCR |= (RMU_PDRCR_PDREN_Msk);
	}
	else
	{
		RMU->PDRCR &= ~(RMU_PDRCR_PDREN_Msk);
	}
}

FunState RMU_PDRCR_PDREN_Getable(void)
{
	if (RMU->PDRCR & (RMU_PDRCR_PDREN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �µ縴λ��ѹ����00��1.7V01��1.6V��Ĭ�ϣ�10��1.65V11��1.75V ��غ��� */
void RMU_BORCR_BOR_PDRCFG_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RMU->BORCR;
	tmpreg &= ~(RMU_BORCR_BOR_PDRCFG_Msk);
	tmpreg |= (SetValue & RMU_BORCR_BOR_PDRCFG_Msk);
	RMU->BORCR = tmpreg;
}

uint32_t RMU_BORCR_BOR_PDRCFG_Get(void)
{
	return (RMU->BORCR & RMU_BORCR_BOR_PDRCFG_Msk);
}

/* BORʹ�ܿ��ƼĴ���0��ʹ��BOR1���ر�BOR ��غ��� */
void RMU_BORCR_OFF_BOR_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
    RMU->BORCR |= (RMU_BORCR_OFF_BOR_Msk);
	}
	else
	{
		RMU->BORCR &= ~(RMU_BORCR_OFF_BOR_Msk);
	}
}

FunState RMU_BORCR_OFF_BOR_Getable(void)
{
	if (RMU->BORCR & (RMU_BORCR_OFF_BOR_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* LOCKUP��λʹ��1��ʹ��SC000 LOCKUP��λ0������SC000 LOCKUP��λ ��غ��� */
void RMU_RSTCFGR_LKUPRST_EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RMU->RSTCFGR |= (RMU_RSTCFGR_LKUPRST_EN_Msk);
	}
	else
	{
		RMU->RSTCFGR &= ~(RMU_RSTCFGR_LKUPRST_EN_Msk);
	}
}

FunState RMU_RSTCFGR_LKUPRST_EN_Getable(void)
{
	if (RMU->RSTCFGR & (RMU_RSTCFGR_LKUPRST_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���д0x5C5C_AABB����ȫ�ָ�λ ��غ��� */
void RMU_SOFTRST_Write(uint32_t SetValue)
{
	RMU->SOFTRST = (SetValue);
}

/* NRST���Ÿ�λ��־������Ч ��غ��� */
void RMU_RSR_NRSTN_FLAG_Clr(void)
{
	RMU->RSR = RMU_RSR_NRSTN_FLAG_Msk;
}

FlagStatus RMU_RSR_NRSTN_FLAG_Chk(void)
{
	if (RMU->RSR & RMU_RSR_NRSTN_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* TESTN���Ÿ�λ��־������Ч ��غ��� */
void RMU_RSR_TESTN_FLAG_Clr(void)
{
	RMU->RSR = RMU_RSR_TESTN_FLAG_Msk;
}

FlagStatus RMU_RSR_TESTN_FLAG_Chk(void)
{
	if (RMU->RSR & RMU_RSR_TESTN_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* �ϵ縴λ��־������Ч ��غ��� */
void RMU_RSR_PORN_FLAG_Clr(void)
{
	RMU->RSR = RMU_RSR_PORN_FLAG_Msk;
}

FlagStatus RMU_RSR_PORN_FLAG_Chk(void)
{
	if (RMU->RSR & RMU_RSR_PORN_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* �µ縴λ��־������Ч ��غ��� */
void RMU_RSR_PDRN_FLAG_Clr(void)
{
	RMU->RSR = RMU_RSR_PDRN_FLAG_Msk;
}

FlagStatus RMU_RSR_PDRN_FLAG_Chk(void)
{
	if (RMU->RSR & RMU_RSR_PDRN_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* �����λ��־������Ч ��غ��� */
void RMU_RSR_SOFTN_FLAG_Clr(void)
{
	RMU->RSR = RMU_RSR_SOFTN_FLAG_Msk;
}

FlagStatus RMU_RSR_SOFTN_FLAG_Chk(void)
{
	if (RMU->RSR & RMU_RSR_SOFTN_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* IWDT��λ��־������Ч ��غ��� */
void RMU_RSR_IWDTN_FLAG_Clr(void)
{
	RMU->RSR = RMU_RSR_IWDTN_FLAG_Msk;
}

FlagStatus RMU_RSR_IWDTN_FLAG_Chk(void)
{
	if (RMU->RSR & RMU_RSR_IWDTN_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* WWDT��λ��־������Ч ��غ��� */
void RMU_RSR_WWDTN_FLAG_Clr(void)
{
	RMU->RSR = RMU_RSR_WWDTN_FLAG_Msk;
}

FlagStatus RMU_RSR_WWDTN_FLAG_Chk(void)
{
	if (RMU->RSR & RMU_RSR_WWDTN_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* LOOKUP��λ��־������Ч ��غ��� */
void RMU_RSR_LKUPN_FLAG_Clr(void)
{
	RMU->RSR = RMU_RSR_LKUPN_FLAG_Msk;
}

FlagStatus RMU_RSR_LKUPN_FLAG_Chk(void)
{
	if (RMU->RSR & RMU_RSR_LKUPN_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* NVIC��λ��־������Ч ��غ��� */
void RMU_RSR_NVICN_FLAG_Clr(void)
{
	RMU->RSR = RMU_RSR_NVICN_FLAG_Msk;
}

FlagStatus RMU_RSR_NVICN_FLAG_Chk(void)
{
	if (RMU->RSR & RMU_RSR_NVICN_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ����ģ�鸴λʹ�ܣ�32bit��Ĵ�����ֻд����Դ˵�ַд0x1357_9BDF��ʹ�����踴λ���ܣ��˺����ͨ������ģ�鸴λ�Ĵ�����λ����ģ������Դ˵�ַд�����������ݣ����ر����踴λ���� ��غ��� */
void RMU_PRSTEN_Write(uint32_t SetValue)
{
	RMU->PRSTEN = (SetValue);
}

/* HASHģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
void RMU_AHBRST_HASHRST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RMU->AHBRST |= (RMU_AHBRST_HASHRST_Msk);
	}
	else
	{
		RMU->AHBRST &= ~(RMU_AHBRST_HASHRST_Msk);
	}
}

FunState RMU_AHBRST_HASHRST_Getable(void)
{
	if (RMU->AHBRST & (RMU_AHBRST_HASHRST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* PAEģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
void RMU_AHBRST_PAERST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RMU->AHBRST |= (RMU_AHBRST_PAERST_Msk);
	}
	else
	{
		RMU->AHBRST &= ~(RMU_AHBRST_PAERST_Msk);
	}
}

FunState RMU_AHBRST_PAERST_Getable(void)
{
	if (RMU->AHBRST & (RMU_AHBRST_PAERST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* DMAģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
void RMU_AHBRST_DMARST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RMU->AHBRST |= (RMU_AHBRST_DMARST_Msk);
	}
	else
	{
		RMU->AHBRST &= ~(RMU_AHBRST_DMARST_Msk);
	}
}

FunState RMU_AHBRST_DMARST_Getable(void)
{
	if (RMU->AHBRST & (RMU_AHBRST_DMARST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* UART5ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
void RMU_APBRST1_UART5RST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RMU->APBRST1 |= (RMU_APBRST1_UART5RST_Msk);
	}
	else
	{
		RMU->APBRST1 &= ~(RMU_APBRST1_UART5RST_Msk);
	}
}

FunState RMU_APBRST1_UART5RST_Getable(void)
{
	if (RMU->APBRST1 & (RMU_APBRST1_UART5RST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* UART4ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
void RMU_APBRST1_UART4RST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RMU->APBRST1 |= (RMU_APBRST1_UART4RST_Msk);
	}
	else
	{
		RMU->APBRST1 &= ~(RMU_APBRST1_UART4RST_Msk);
	}
}

FunState RMU_APBRST1_UART4RST_Getable(void)
{
	if (RMU->APBRST1 & (RMU_APBRST1_UART4RST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* UART3ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
void RMU_APBRST1_UART3RST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RMU->APBRST1 |= (RMU_APBRST1_UART3RST_Msk);
	}
	else
	{
		RMU->APBRST1 &= ~(RMU_APBRST1_UART3RST_Msk);
	}
}

FunState RMU_APBRST1_UART3RST_Getable(void)
{
	if (RMU->APBRST1 & (RMU_APBRST1_UART3RST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* UART2ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
void RMU_APBRST1_UART2RST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RMU->APBRST1 |= (RMU_APBRST1_UART2RST_Msk);
	}
	else
	{
		RMU->APBRST1 &= ~(RMU_APBRST1_UART2RST_Msk);
	}
}

FunState RMU_APBRST1_UART2RST_Getable(void)
{
	if (RMU->APBRST1 & (RMU_APBRST1_UART2RST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Timer array��λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
void RMU_APBRST1_TIMARST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RMU->APBRST1 |= (RMU_APBRST1_TIMARST_Msk);
	}
	else
	{
		RMU->APBRST1 &= ~(RMU_APBRST1_TIMARST_Msk);
	}
}

FunState RMU_APBRST1_TIMARST_Getable(void)
{
	if (RMU->APBRST1 & (RMU_APBRST1_TIMARST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* LCDģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
void RMU_APBRST1_LCDRST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RMU->APBRST1 |= (RMU_APBRST1_LCDRST_Msk);
	}
	else
	{
		RMU->APBRST1 &= ~(RMU_APBRST1_LCDRST_Msk);
	}
}

FunState RMU_APBRST1_LCDRST_Getable(void)
{
	if (RMU->APBRST1 & (RMU_APBRST1_LCDRST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* U7816ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
void RMU_APBRST1_U7816RST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RMU->APBRST1 |= (RMU_APBRST1_U7816RST_Msk);
	}
	else
	{
		RMU->APBRST1 &= ~(RMU_APBRST1_U7816RST_Msk);
	}
}

FunState RMU_APBRST1_U7816RST_Getable(void)
{
	if (RMU->APBRST1 & (RMU_APBRST1_U7816RST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* SPI3ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
void RMU_APBRST1_SPI4RST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RMU->APBRST1 |= (RMU_APBRST1_SPI4RST_Msk);
	}
	else
	{
		RMU->APBRST1 &= ~(RMU_APBRST1_SPI4RST_Msk);
	}
}

FunState RMU_APBRST1_SPI4RST_Getable(void)
{
	if (RMU->APBRST1 & (RMU_APBRST1_SPI4RST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* SPI2ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
void RMU_APBRST1_SPI3RST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RMU->APBRST1 |= (RMU_APBRST1_SPI3RST_Msk);
	}
	else
	{
		RMU->APBRST1 &= ~(RMU_APBRST1_SPI3RST_Msk);
	}
}

FunState RMU_APBRST1_SPI3RST_Getable(void)
{
	if (RMU->APBRST1 & (RMU_APBRST1_SPI3RST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* SPI2ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
void RMU_APBRST1_SPI2RST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RMU->APBRST1 |= (RMU_APBRST1_SPI2RST_Msk);
	}
	else
	{
		RMU->APBRST1 &= ~(RMU_APBRST1_SPI2RST_Msk);
	}
}

FunState RMU_APBRST1_SPI2RST_Getable(void)
{
	if (RMU->APBRST1 & (RMU_APBRST1_SPI2RST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* EUART0ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
void RMU_APBRST1_LPUART0RST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RMU->APBRST1 |= (RMU_APBRST1_LPUART0RST_Msk);
	}
	else
	{
		RMU->APBRST1 &= ~(RMU_APBRST1_LPUART0RST_Msk);
	}
}

FunState RMU_APBRST1_LPUART0RST_Getable(void)
{
	if (RMU->APBRST1 & (RMU_APBRST1_LPUART0RST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* I2C1ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
void RMU_APBRST1_I2C1RST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RMU->APBRST1 |= (RMU_APBRST1_I2C1RST_Msk);
	}
	else
	{
		RMU->APBRST1 &= ~(RMU_APBRST1_I2C1RST_Msk);
	}
}

FunState RMU_APBRST1_I2C1RST_Getable(void)
{
	if (RMU->APBRST1 & (RMU_APBRST1_I2C1RST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*  _32ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
void RMU_APBRST1_LPTRST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RMU->APBRST1 |= (RMU_APBRST1_LPTRST_Msk);
	}
	else
	{
		RMU->APBRST1 &= ~(RMU_APBRST1_LPTRST_Msk);
	}
}

FunState RMU_APBRST1_LPTRST_Getable(void)
{
	if (RMU->APBRST1 & (RMU_APBRST1_LPTRST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* UART1ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
void RMU_APBRST2_UART1RST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RMU->APBRST2 |= (RMU_APBRST2_UART1RST_Msk);
	}
	else
	{
		RMU->APBRST2 &= ~(RMU_APBRST2_UART1RST_Msk);
	}
}

FunState RMU_APBRST2_UART1RST_Getable(void)
{
	if (RMU->APBRST2 & (RMU_APBRST2_UART1RST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* UART0ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
void RMU_APBRST2_UART0RST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RMU->APBRST2 |= (RMU_APBRST2_UART0RST_Msk);
	}
	else
	{
		RMU->APBRST2 &= ~(RMU_APBRST2_UART0RST_Msk);
	}
}

FunState RMU_APBRST2_UART0RST_Getable(void)
{
	if (RMU->APBRST2 & (RMU_APBRST2_UART0RST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* UART����ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
void RMU_APBRST2_UARTIRRST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RMU->APBRST2 |= (RMU_APBRST2_UARTIRRST_Msk);
	}
	else
	{
		RMU->APBRST2 &= ~(RMU_APBRST2_UARTIRRST_Msk);
	}
}

FunState RMU_APBRST2_UARTIRRST_Getable(void)
{
	if (RMU->APBRST2 & (RMU_APBRST2_UARTIRRST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* BSTIMģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
void RMU_APBRST2_BSTRST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RMU->APBRST2 |= (RMU_APBRST2_BSTRST_Msk);
	}
	else
	{
		RMU->APBRST2 &= ~(RMU_APBRST2_BSTRST_Msk);
	}
}

FunState RMU_APBRST2_BSTRST_Getable(void)
{
	if (RMU->APBRST2 & (RMU_APBRST2_BSTRST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* CIC�˲�ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
void RMU_APBRST2_CICRST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RMU->APBRST2 |= (RMU_APBRST2_CICRST_Msk);
	}
	else
	{
		RMU->APBRST2 &= ~(RMU_APBRST2_CICRST_Msk);
	}
}

FunState RMU_APBRST2_CICRST_Getable(void)
{
	if (RMU->APBRST2 & (RMU_APBRST2_CICRST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ADCģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
void RMU_APBRST2_ADCRST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RMU->APBRST2 |= (RMU_APBRST2_ADCRST_Msk);
	}
	else
	{
		RMU->APBRST2 &= ~(RMU_APBRST2_ADCRST_Msk);
	}
}

FunState RMU_APBRST2_ADCRST_Getable(void)
{
	if (RMU->APBRST2 & (RMU_APBRST2_ADCRST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* AESģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
void RMU_APBRST2_AESRST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RMU->APBRST2 |= (RMU_APBRST2_AESRST_Msk);
	}
	else
	{
		RMU->APBRST2 &= ~(RMU_APBRST2_AESRST_Msk);
	}
}

FunState RMU_APBRST2_AESRST_Getable(void)
{
	if (RMU->APBRST2 & (RMU_APBRST2_AESRST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* CRCģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
void RMU_APBRST2_CRCRST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RMU->APBRST2 |= (RMU_APBRST2_CRCRST_Msk);
	}
	else
	{
		RMU->APBRST2 &= ~(RMU_APBRST2_CRCRST_Msk);
	}
}

FunState RMU_APBRST2_CRCRST_Getable(void)
{
	if (RMU->APBRST2 & (RMU_APBRST2_CRCRST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* RNGģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
void RMU_APBRST2_RNGRST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RMU->APBRST2 |= (RMU_APBRST2_RNGRST_Msk);
	}
	else
	{
		RMU->APBRST2 &= ~(RMU_APBRST2_RNGRST_Msk);
	}
}

FunState RMU_APBRST2_RNGRST_Getable(void)
{
	if (RMU->APBRST2 & (RMU_APBRST2_RNGRST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* SPI1ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
void RMU_APBRST2_SPI1RST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RMU->APBRST2 |= (RMU_APBRST2_SPI1RST_Msk);
	}
	else
	{
		RMU->APBRST2 &= ~(RMU_APBRST2_SPI1RST_Msk);
	}
}

FunState RMU_APBRST2_SPI1RST_Getable(void)
{
	if (RMU->APBRST2 & (RMU_APBRST2_SPI1RST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* SPI0ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
void RMU_APBRST2_SPI0RST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RMU->APBRST2 |= (RMU_APBRST2_SPI0RST_Msk);
	}
	else
	{
		RMU->APBRST2 &= ~(RMU_APBRST2_SPI0RST_Msk);
	}
}

FunState RMU_APBRST2_SPI0RST_Getable(void)
{
	if (RMU->APBRST2 & (RMU_APBRST2_SPI0RST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* EUART1ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
void RMU_APBRST2_LPUART1RST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RMU->APBRST2 |= (RMU_APBRST2_LPUART1RST_Msk);
	}
	else
	{
		RMU->APBRST2 &= ~(RMU_APBRST2_LPUART1RST_Msk);
	}
}

FunState RMU_APBRST2_LPUART1RST_Getable(void)
{
	if (RMU->APBRST2 & (RMU_APBRST2_LPUART1RST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* I2C0ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
void RMU_APBRST2_I2C0RST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RMU->APBRST2 |= (RMU_APBRST2_I2C0RST_Msk);
	}
	else
	{
		RMU->APBRST2 &= ~(RMU_APBRST2_I2C0RST_Msk);
	}
}

FunState RMU_APBRST2_I2C0RST_Getable(void)
{
	if (RMU->APBRST2 & (RMU_APBRST2_I2C0RST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* SVDģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
void RMU_APBRST2_SVDRST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RMU->APBRST2 |= (RMU_APBRST2_SVDRST_Msk);
	}
	else
	{
		RMU->APBRST2 &= ~(RMU_APBRST2_SVDRST_Msk);
	}
}

FunState RMU_APBRST2_SVDRST_Getable(void)
{
	if (RMU->APBRST2 & (RMU_APBRST2_SVDRST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �Ƚ���ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
void RMU_APBRST2_COMPRST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RMU->APBRST2 |= (RMU_APBRST2_COMPRST_Msk);
	}
	else
	{
		RMU->APBRST2 &= ~(RMU_APBRST2_COMPRST_Msk);
	}
}

FunState RMU_APBRST2_COMPRST_Getable(void)
{
	if (RMU->APBRST2 & (RMU_APBRST2_COMPRST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}


void RMU_Deinit(void)
{
	//RMU->PDRCR = 0x00000007;
	//RMU->BORCR = 0x00000002;
	//RMU->RSTCFGR = 0x00000000;
	//RMU->SOFTRST = 0x00000000;
	//RMU->RSR = 0x00000000;
	//RMU->PRSTEN = 0x00000000;
	//RMU->AHBRST = 0x00000000;
	//RMU->APBRST1 = 0x00000000;
	//RMU->APBRST2 = 0x00000000;
}

/******END OF FILE****/
