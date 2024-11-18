/**
  ******************************************************************************
  * @file    fm33a0xxev_rmu.h
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file contains all the functions prototypes for the RMU firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33A0XXEV_RMU_H
#define __FM33A0XXEV_RMU_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33A0XXEV.h" 
   
#define	RMU_PDRCR_PDRCFG_Pos	1	/* �µ縴λ��ѹ����00��1.5V01��1.25V����ֹʹ�ã�10��1.35V11��1.4V��Ĭ�ϣ� */
#define	RMU_PDRCR_PDRCFG_Msk	(0x3U << RMU_PDRCR_PDRCFG_Pos)
#define	RMU_PDRCR_PDRCFG_1P5V	(0x0U << RMU_PDRCR_PDRCFG_Pos)
#define	RMU_PDRCR_PDRCFG_1P25V	(0x1U << RMU_PDRCR_PDRCFG_Pos)
#define	RMU_PDRCR_PDRCFG_1P35V	(0x2U << RMU_PDRCR_PDRCFG_Pos)
#define	RMU_PDRCR_PDRCFG_1P4V	(0x3U << RMU_PDRCR_PDRCFG_Pos)

#define	RMU_PDRCR_PDREN_Pos	0	/* �µ縴λʹ��0���ر��µ縴λ1��ʹ���µ縴λ */
#define	RMU_PDRCR_PDREN_Msk	(0x1U << RMU_PDRCR_PDREN_Pos)
	/* �ر��µ縴λ */
	/* ʹ���µ縴λ */

#define	RMU_BORCR_BOR_PDRCFG_Pos	1	/* �µ縴λ��ѹ����00��1.7V01��1.6V��Ĭ�ϣ�10��1.65V11��1.75V */
#define	RMU_BORCR_BOR_PDRCFG_Msk	(0x3U << RMU_BORCR_BOR_PDRCFG_Pos)
#define	RMU_BORCR_BOR_PDRCFG_1P7V	(0x0U << RMU_BORCR_BOR_PDRCFG_Pos)
#define	RMU_BORCR_BOR_PDRCFG_1P6V	(0x1U << RMU_BORCR_BOR_PDRCFG_Pos)
#define	RMU_BORCR_BOR_PDRCFG_1P65V	(0x2U << RMU_BORCR_BOR_PDRCFG_Pos)
#define	RMU_BORCR_BOR_PDRCFG_1P75V	(0x3U << RMU_BORCR_BOR_PDRCFG_Pos)

#define	RMU_BORCR_OFF_BOR_Pos	0	/* BORʹ�ܿ��ƼĴ���0��ʹ��BOR1���ر�BOR */
#define	RMU_BORCR_OFF_BOR_Msk	(0x1U << RMU_BORCR_OFF_BOR_Pos)
	/* ʹ��BOR */
	/* �ر�BOR */

#define	RMU_RSTCFGR_LKUPRST_EN_Pos	1	/* LOCKUP��λʹ��1��ʹ��SC000 LOCKUP��λ0������SC000 LOCKUP��λ */
#define	RMU_RSTCFGR_LKUPRST_EN_Msk	(0x1U << RMU_RSTCFGR_LKUPRST_EN_Pos)
	/* ʹ��SC000 LOCKUP��λ */
	/* ����SC000 LOCKUP��λ */

#define	RMU_SOFTRST_SOFTRST_Pos	0	/* ���д0x5C5C_AABB����ȫ�ָ�λ */
#define	RMU_SOFTRST_SOFTRST_Msk	(0xffffffffU << RMU_SOFTRST_SOFTRST_Pos)

#define	RMU_RSR_NRSTN_FLAG_Pos	11	/* NRST���Ÿ�λ��־������Ч */
#define	RMU_RSR_NRSTN_FLAG_Msk	(0x1U << RMU_RSR_NRSTN_FLAG_Pos)

#define	RMU_RSR_TESTN_FLAG_Pos	10	/* TESTN���Ÿ�λ��־������Ч */
#define	RMU_RSR_TESTN_FLAG_Msk	(0x1U << RMU_RSR_TESTN_FLAG_Pos)

#define	RMU_RSR_PORN_FLAG_Pos	9	/* �ϵ縴λ��־������Ч */
#define	RMU_RSR_PORN_FLAG_Msk	(0x1U << RMU_RSR_PORN_FLAG_Pos)

#define	RMU_RSR_PDRN_FLAG_Pos	8	/* �µ縴λ��־������Ч */
#define	RMU_RSR_PDRN_FLAG_Msk	(0x1U << RMU_RSR_PDRN_FLAG_Pos)

#define	RMU_RSR_SOFTN_FLAG_Pos	5	/* �����λ��־������Ч */
#define	RMU_RSR_SOFTN_FLAG_Msk	(0x1U << RMU_RSR_SOFTN_FLAG_Pos)

#define	RMU_RSR_IWDTN_FLAG_Pos	4	/* IWDT��λ��־������Ч */
#define	RMU_RSR_IWDTN_FLAG_Msk	(0x1U << RMU_RSR_IWDTN_FLAG_Pos)

#define	RMU_RSR_WWDTN_FLAG_Pos	2	/* WWDT��λ��־������Ч */
#define	RMU_RSR_WWDTN_FLAG_Msk	(0x1U << RMU_RSR_WWDTN_FLAG_Pos)

#define	RMU_RSR_LKUPN_FLAG_Pos	1	/* LOOKUP��λ��־������Ч */
#define	RMU_RSR_LKUPN_FLAG_Msk	(0x1U << RMU_RSR_LKUPN_FLAG_Pos)

#define	RMU_RSR_NVICN_FLAG_Pos	0	/* NVIC��λ��־������Ч */
#define	RMU_RSR_NVICN_FLAG_Msk	(0x1U << RMU_RSR_NVICN_FLAG_Pos)

#define	RMU_PRSTEN_PERHRSTEN_Pos	0	/* ����ģ�鸴λʹ�ܣ�32bit��Ĵ�����ֻд����Դ˵�ַд0x1357_9BDF��ʹ�����踴λ���ܣ��˺����ͨ������ģ�鸴λ�Ĵ�����λ����ģ������Դ˵�ַд�����������ݣ����ر����踴λ���� */
#define	RMU_PRSTEN_PERHRSTEN_Msk	(0xffffffffU << RMU_PRSTEN_PERHRSTEN_Pos)

#define	RMU_AHBRST_HASHRST_Pos	2	/* HASHģ�鸴λ�����д1��λ��д0������λ0������λ1����λ */
#define	RMU_AHBRST_HASHRST_Msk	(0x1U << RMU_AHBRST_HASHRST_Pos)
	/* ����λ */
	/* ��λ */

#define	RMU_AHBRST_PAERST_Pos	1	/* PAEģ�鸴λ�����д1��λ��д0������λ0������λ1����λ */
#define	RMU_AHBRST_PAERST_Msk	(0x1U << RMU_AHBRST_PAERST_Pos)
	/* ����λ */
	/* ��λ */

#define	RMU_AHBRST_DMARST_Pos	0	/* DMAģ�鸴λ�����д1��λ��д0������λ0������λ1����λ */
#define	RMU_AHBRST_DMARST_Msk	(0x1U << RMU_AHBRST_DMARST_Pos)
	/* ����λ */
	/* ��λ */

#define	RMU_APBRST1_UART5RST_Pos	31	/* UART5ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ */
#define	RMU_APBRST1_UART5RST_Msk	(0x1U << RMU_APBRST1_UART5RST_Pos)
	/* ����λ */
	/* ��λ */

#define	RMU_APBRST1_UART4RST_Pos	30	/* UART4ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ */
#define	RMU_APBRST1_UART4RST_Msk	(0x1U << RMU_APBRST1_UART4RST_Pos)
	/* ����λ */
	/* ��λ */

#define	RMU_APBRST1_UART3RST_Pos	29	/* UART3ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ */
#define	RMU_APBRST1_UART3RST_Msk	(0x1U << RMU_APBRST1_UART3RST_Pos)
	/* ����λ */
	/* ��λ */

#define	RMU_APBRST1_UART2RST_Pos	28	/* UART2ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ */
#define	RMU_APBRST1_UART2RST_Msk	(0x1U << RMU_APBRST1_UART2RST_Pos)
	/* ����λ */
	/* ��λ */

#define	RMU_APBRST1_TIMARST_Pos	23	/* Timer array��λ�����д1��λ��д0������λ0������λ1����λ */
#define	RMU_APBRST1_TIMARST_Msk	(0x1U << RMU_APBRST1_TIMARST_Pos)
	/* ����λ */
	/* ��λ */

#define	RMU_APBRST1_LCDRST_Pos	16	/* LCDģ�鸴λ�����д1��λ��д0������λ0������λ1����λ */
#define	RMU_APBRST1_LCDRST_Msk	(0x1U << RMU_APBRST1_LCDRST_Pos)
	/* ����λ */
	/* ��λ */

#define	RMU_APBRST1_U7816RST_Pos	14	/* U7816ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ */
#define	RMU_APBRST1_U7816RST_Msk	(0x1U << RMU_APBRST1_U7816RST_Pos)
	/* ����λ */
	/* ��λ */

#define	RMU_APBRST1_SPI4RST_Pos	12	/* SPI3ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ */
#define	RMU_APBRST1_SPI4RST_Msk	(0x1U << RMU_APBRST1_SPI4RST_Pos)
	/* ����λ */
	/* ��λ */

#define	RMU_APBRST1_SPI3RST_Pos	11	/* SPI2ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ */
#define	RMU_APBRST1_SPI3RST_Msk	(0x1U << RMU_APBRST1_SPI3RST_Pos)
	/* ����λ */
	/* ��λ */

#define	RMU_APBRST1_SPI2RST_Pos	10	/* SPI2ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ */
#define	RMU_APBRST1_SPI2RST_Msk	(0x1U << RMU_APBRST1_SPI2RST_Pos)
	/* ����λ */
	/* ��λ */

#define	RMU_APBRST1_LPUART0RST_Pos	6	/* EUART0ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ */
#define	RMU_APBRST1_LPUART0RST_Msk	(0x1U << RMU_APBRST1_LPUART0RST_Pos)
	/* ����λ */
	/* ��λ */

#define	RMU_APBRST1_I2C1RST_Pos	3	/* I2C1ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ */
#define	RMU_APBRST1_I2C1RST_Msk	(0x1U << RMU_APBRST1_I2C1RST_Pos)
	/* ����λ */
	/* ��λ */

#define	RMU_APBRST1_LPTRST_Pos	0	/*  LPTIM ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ */
#define	RMU_APBRST1_LPTRST_Msk	(0x1U << RMU_APBRST1_LPTRST_Pos)
	/* ����λ */
	/* ��λ */

#define	RMU_APBRST2_UART1RST_Pos	31	/* UART1ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ */
#define	RMU_APBRST2_UART1RST_Msk	(0x1U << RMU_APBRST2_UART1RST_Pos)
	/* ����λ */
	/* ��λ */

#define	RMU_APBRST2_UART0RST_Pos	30	/* UART0ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ */
#define	RMU_APBRST2_UART0RST_Msk	(0x1U << RMU_APBRST2_UART0RST_Pos)
	/* ����λ */
	/* ��λ */

#define	RMU_APBRST2_UARTIRRST_Pos	29	/* UART����ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ */
#define	RMU_APBRST2_UARTIRRST_Msk	(0x1U << RMU_APBRST2_UARTIRRST_Pos)
	/* ����λ */
	/* ��λ */

#define	RMU_APBRST2_BSTRST_Pos	28	/* BSTIMģ�鸴λ�����д1��λ��д0������λ0������λ1����λ */
#define	RMU_APBRST2_BSTRST_Msk	(0x1U << RMU_APBRST2_BSTRST_Pos)
	/* ����λ */
	/* ��λ */

#define	RMU_APBRST2_CICRST_Pos	24	/* CIC�˲�ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ */
#define	RMU_APBRST2_CICRST_Msk	(0x1U << RMU_APBRST2_CICRST_Pos)
	/* ����λ */
	/* ��λ */

#define	RMU_APBRST2_ADCRST_Pos	23	/* ADCģ�鸴λ�����д1��λ��д0������λ0������λ1����λ */
#define	RMU_APBRST2_ADCRST_Msk	(0x1U << RMU_APBRST2_ADCRST_Pos)
	/* ����λ */
	/* ��λ */

#define	RMU_APBRST2_AESRST_Pos	18	/* AESģ�鸴λ�����д1��λ��д0������λ0������λ1����λ */
#define	RMU_APBRST2_AESRST_Msk	(0x1U << RMU_APBRST2_AESRST_Pos)
	/* ����λ */
	/* ��λ */

#define	RMU_APBRST2_CRCRST_Pos	17	/* CRCģ�鸴λ�����д1��λ��д0������λ0������λ1����λ */
#define	RMU_APBRST2_CRCRST_Msk	(0x1U << RMU_APBRST2_CRCRST_Pos)
	/* ����λ */
	/* ��λ */

#define	RMU_APBRST2_RNGRST_Pos	16	/* RNGģ�鸴λ�����д1��λ��д0������λ0������λ1����λ */
#define	RMU_APBRST2_RNGRST_Msk	(0x1U << RMU_APBRST2_RNGRST_Pos)
	/* ����λ */
	/* ��λ */

#define	RMU_APBRST2_SPI1RST_Pos	9	/* SPI1ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ */
#define	RMU_APBRST2_SPI1RST_Msk	(0x1U << RMU_APBRST2_SPI1RST_Pos)
	/* ����λ */
	/* ��λ */

#define	RMU_APBRST2_SPI0RST_Pos	8	/* SPI0ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ */
#define	RMU_APBRST2_SPI0RST_Msk	(0x1U << RMU_APBRST2_SPI0RST_Pos)
	/* ����λ */
	/* ��λ */

#define	RMU_APBRST2_LPUART1RST_Pos	7	/* EUART1ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ */
#define	RMU_APBRST2_LPUART1RST_Msk	(0x1U << RMU_APBRST2_LPUART1RST_Pos)
	/* ����λ */
	/* ��λ */

#define	RMU_APBRST2_I2C0RST_Pos	4	/* I2C0ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ */
#define	RMU_APBRST2_I2C0RST_Msk	(0x1U << RMU_APBRST2_I2C0RST_Pos)
	/* ����λ */
	/* ��λ */

#define	RMU_APBRST2_SVDRST_Pos	1	/* SVDģ�鸴λ�����д1��λ��д0������λ0������λ1����λ */
#define	RMU_APBRST2_SVDRST_Msk	(0x1U << RMU_APBRST2_SVDRST_Pos)
	/* ����λ */
	/* ��λ */

#define	RMU_APBRST2_COMPRST_Pos	0	/* �Ƚ���ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ */
#define	RMU_APBRST2_COMPRST_Msk	(0x1U << RMU_APBRST2_COMPRST_Pos)
	/* ����λ */
	/* ��λ */
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void RMU_Deinit(void);

/* �µ縴λ��ѹ����00��1.5V01��1.25V����ֹʹ�ã�10��1.35V11��1.4V��Ĭ�ϣ� ��غ��� */
extern void RMU_PDRCR_PDRCFG_Set(uint32_t SetValue);
extern uint32_t RMU_PDRCR_PDRCFG_Get(void);

/* �µ縴λʹ��0���ر��µ縴λ1��ʹ���µ縴λ ��غ��� */
extern void RMU_PDRCR_PDREN_Setable(FunState NewState);
extern FunState RMU_PDRCR_PDREN_Getable(void);

/* �µ縴λ��ѹ����00��1.7V01��1.6V��Ĭ�ϣ�10��1.65V11��1.75V ��غ��� */
extern void RMU_BORCR_BOR_PDRCFG_Set(uint32_t SetValue);
extern uint32_t RMU_BORCR_BOR_PDRCFG_Get(void);

/* BORʹ�ܿ��ƼĴ���0��ʹ��BOR1���ر�BOR ��غ��� */
extern void RMU_BORCR_OFF_BOR_Setable(FunState NewState);
extern FunState RMU_BORCR_OFF_BOR_Getable(void);

/* LOCKUP��λʹ��1��ʹ��SC000 LOCKUP��λ0������SC000 LOCKUP��λ ��غ��� */
extern void RMU_RSTCFGR_LKUPRST_EN_Setable(FunState NewState);
extern FunState RMU_RSTCFGR_LKUPRST_EN_Getable(void);

/* ���д0x5C5C_AABB����ȫ�ָ�λ ��غ��� */
extern void RMU_SOFTRST_Write(uint32_t SetValue);

/* NRST���Ÿ�λ��־������Ч ��غ��� */
extern void RMU_RSR_NRSTN_FLAG_Clr(void);
extern FlagStatus RMU_RSR_NRSTN_FLAG_Chk(void);

/* TESTN���Ÿ�λ��־������Ч ��غ��� */
extern void RMU_RSR_TESTN_FLAG_Clr(void);
extern FlagStatus RMU_RSR_TESTN_FLAG_Chk(void);

/* �ϵ縴λ��־������Ч ��غ��� */
extern void RMU_RSR_PORN_FLAG_Clr(void);
extern FlagStatus RMU_RSR_PORN_FLAG_Chk(void);

/* �µ縴λ��־������Ч ��غ��� */
extern void RMU_RSR_PDRN_FLAG_Clr(void);
extern FlagStatus RMU_RSR_PDRN_FLAG_Chk(void);

/* �����λ��־������Ч ��غ��� */
extern void RMU_RSR_SOFTN_FLAG_Clr(void);
extern FlagStatus RMU_RSR_SOFTN_FLAG_Chk(void);

/* IWDT��λ��־������Ч ��غ��� */
extern void RMU_RSR_IWDTN_FLAG_Clr(void);
extern FlagStatus RMU_RSR_IWDTN_FLAG_Chk(void);

/* WWDT��λ��־������Ч ��غ��� */
extern void RMU_RSR_WWDTN_FLAG_Clr(void);
extern FlagStatus RMU_RSR_WWDTN_FLAG_Chk(void);

/* LOOKUP��λ��־������Ч ��غ��� */
extern void RMU_RSR_LKUPN_FLAG_Clr(void);
extern FlagStatus RMU_RSR_LKUPN_FLAG_Chk(void);

/* NVIC��λ��־������Ч ��غ��� */
extern void RMU_RSR_NVICN_FLAG_Clr(void);
extern FlagStatus RMU_RSR_NVICN_FLAG_Chk(void);

/* ����ģ�鸴λʹ�ܣ�32bit��Ĵ�����ֻд����Դ˵�ַд0x1357_9BDF��ʹ�����踴λ���ܣ��˺����ͨ������ģ�鸴λ�Ĵ�����λ����ģ������Դ˵�ַд�����������ݣ����ر����踴λ���� ��غ��� */
extern void RMU_PRSTEN_Write(uint32_t SetValue);

/* HASHģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
extern void RMU_AHBRST_HASHRST_Setable(FunState NewState);
extern FunState RMU_AHBRST_HASHRST_Getable(void);

/* PAEģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
extern void RMU_AHBRST_PAERST_Setable(FunState NewState);
extern FunState RMU_AHBRST_PAERST_Getable(void);

/* DMAģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
extern void RMU_AHBRST_DMARST_Setable(FunState NewState);
extern FunState RMU_AHBRST_DMARST_Getable(void);

/* UART5ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
extern void RMU_APBRST1_UART5RST_Setable(FunState NewState);
extern FunState RMU_APBRST1_UART5RST_Getable(void);

/* UART4ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
extern void RMU_APBRST1_UART4RST_Setable(FunState NewState);
extern FunState RMU_APBRST1_UART4RST_Getable(void);

/* UART3ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
extern void RMU_APBRST1_UART3RST_Setable(FunState NewState);
extern FunState RMU_APBRST1_UART3RST_Getable(void);

/* UART2ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
extern void RMU_APBRST1_UART2RST_Setable(FunState NewState);
extern FunState RMU_APBRST1_UART2RST_Getable(void);

/* Timer array��λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
extern void RMU_APBRST1_TIMARST_Setable(FunState NewState);
extern FunState RMU_APBRST1_TIMARST_Getable(void);

/* LCDģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
extern void RMU_APBRST1_LCDRST_Setable(FunState NewState);
extern FunState RMU_APBRST1_LCDRST_Getable(void);

/* U7816ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
extern void RMU_APBRST1_U7816RST_Setable(FunState NewState);
extern FunState RMU_APBRST1_U7816RST_Getable(void);

/* SPI3ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
extern void RMU_APBRST1_SPI4RST_Setable(FunState NewState);
extern FunState RMU_APBRST1_SPI4RST_Getable(void);

/* SPI2ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
extern void RMU_APBRST1_SPI3RST_Setable(FunState NewState);
extern FunState RMU_APBRST1_SPI3RST_Getable(void);

/* SPI2ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
extern void RMU_APBRST1_SPI2RST_Setable(FunState NewState);
extern FunState RMU_APBRST1_SPI2RST_Getable(void);

/* EUART0ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
extern void RMU_APBRST1_LPUART0RST_Setable(FunState NewState);
extern FunState RMU_APBRST1_LPUART0RST_Getable(void);

/* I2C1ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
extern void RMU_APBRST1_I2C1RST_Setable(FunState NewState);
extern FunState RMU_APBRST1_I2C1RST_Getable(void);

/* LPTIM ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
extern void RMU_APBRST1_LPTRST_Setable(FunState NewState);
extern FunState RMU_APBRST1_LPTRST_Getable(void);

/* UART1ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
extern void RMU_APBRST2_UART1RST_Setable(FunState NewState);
extern FunState RMU_APBRST2_UART1RST_Getable(void);

/* UART0ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
extern void RMU_APBRST2_UART0RST_Setable(FunState NewState);
extern FunState RMU_APBRST2_UART0RST_Getable(void);

/* UART����ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
extern void RMU_APBRST2_UARTIRRST_Setable(FunState NewState);
extern FunState RMU_APBRST2_UARTIRRST_Getable(void);

/* BSTIMģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
extern void RMU_APBRST2_BSTRST_Setable(FunState NewState);
extern FunState RMU_APBRST2_BSTRST_Getable(void);

/* CIC�˲�ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
extern void RMU_APBRST2_CICRST_Setable(FunState NewState);
extern FunState RMU_APBRST2_CICRST_Getable(void);

/* ADCģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
extern void RMU_APBRST2_ADCRST_Setable(FunState NewState);
extern FunState RMU_APBRST2_ADCRST_Getable(void);

/* AESģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
extern void RMU_APBRST2_AESRST_Setable(FunState NewState);
extern FunState RMU_APBRST2_AESRST_Getable(void);

/* CRCģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
extern void RMU_APBRST2_CRCRST_Setable(FunState NewState);
extern FunState RMU_APBRST2_CRCRST_Getable(void);

/* RNGģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
extern void RMU_APBRST2_RNGRST_Setable(FunState NewState);
extern FunState RMU_APBRST2_RNGRST_Getable(void);

/* SPI1ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
extern void RMU_APBRST2_SPI1RST_Setable(FunState NewState);
extern FunState RMU_APBRST2_SPI1RST_Getable(void);

/* SPI0ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
extern void RMU_APBRST2_SPI0RST_Setable(FunState NewState);
extern FunState RMU_APBRST2_SPI0RST_Getable(void);

/* EUART1ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
extern void RMU_APBRST2_LPUART1RST_Setable(FunState NewState);
extern FunState RMU_APBRST2_LPUART1RST_Getable(void);

/* I2C0ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
extern void RMU_APBRST2_I2C0RST_Setable(FunState NewState);
extern FunState RMU_APBRST2_I2C0RST_Getable(void);

/* SVDģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
extern void RMU_APBRST2_SVDRST_Setable(FunState NewState);
extern FunState RMU_APBRST2_SVDRST_Getable(void);

/* �Ƚ���ģ�鸴λ�����д1��λ��д0������λ0������λ1����λ ��غ��� */
extern void RMU_APBRST2_COMPRST_Setable(FunState NewState);
extern FunState RMU_APBRST2_COMPRST_Getable(void);
//Announce_End
#ifdef __cplusplus
}
#endif

#endif /* __FM33A0XXEV_RMU_H */
