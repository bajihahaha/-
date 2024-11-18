/**
  ******************************************************************************
  * @file    fm33a0xxev_cmu.h
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file contains all the functions prototypes for the CMU firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33A0XXEV_CMU_H
#define __FM33A0XXEV_CMU_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33A0XXEV.h" 
  

/* Defines------------------------------------------------------------------*/
#define HXVAR(object, addr)   (*((object *) (addr)))
#define const_rchf_Trim8 	HXVAR( uint32_t, 0x1FFFFB40 )	//RCHF 8MHz��Уֵ
#define const_rchf_Trim16 	HXVAR( uint32_t, 0x1FFFFB3C )	//RCHF 16MHz��Уֵ
#define const_rchf_Trim24 	HXVAR( uint32_t, 0x1FFFFB38 )	//RCHF 24MHz��Уֵ
#define const_rchf_Trim32 	HXVAR( uint32_t, 0x1FFFFB34)   //RCHF 32MHz��Уֵ
	 
#define __XTHF_CLOCK                (8000000) 
/* Exported constants --------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
typedef struct
{
	uint32_t			FSEL;		/*!<RCHFƵ��  */
	FunState			RCHFEN;			/*!<RCHFʹ�ܿ���  */
}CMU_RCHF_InitTypeDef;

typedef struct
{            
    uint32_t		PLLLDB;		/*!<PLL��Ƶ�����1023,pll��Ƶ�� = PLLDB + 1  */
	FunState		PLLL_EN;		/*!<PLLʹ�ܿ���  */
}CMU_PLL_L_InitTypeDef;


typedef struct
{            
    uint32_t		PLLHDB;		/*!<PLL��Ƶ�����1023,pll��Ƶ�� = PLLDB + 1  */
	uint32_t 		REFPRSC;	/*!<PLLH�ο�ʱ��Ԥ��Ƶ  */
	uint32_t		PLLH_OSEL;	/*!<PLL���ѡ�񣬵���Ҫ�������1024��ʱ�����������ģʽ  */
	uint32_t		PLLH_INSEL;	/*!<PLL����Դѡ��  */
	FunState		PLLH_EN;		/*!<PLLʹ�ܿ���  */
}CMU_PLL_H_InitTypeDef;


typedef struct
{
    uint32_t			SYSCLKSEL;		/*!<ϵͳʱ��ѡ�񣬴�����״̬���Ѻ���Զ��ָ�ΪRCHF8M  */	
	uint32_t			AHBPRES;		/*!<AHBʱ�ӷ�Ƶѡ��  */
	uint32_t			APBPRES;		/*!<APBʱ�ӷ�Ƶѡ��  */
	FunState			SLP_ENEXTI;		/*!<Sleep/DeepSleepģʽ��EXTI��������  */
	
}CMU_SYSCLK_InitTypeDef;

typedef struct
{
    uint32_t SYSCLK_Frequency;		/*!<  SYSCLK clock frequency expressed in Hz */
    uint32_t AHBCLK_Frequency;		/*!<  AHB clock frequency expressed in Hz  */
    uint32_t APBCLK_Frequency;		/*!<  APB clock frequency expressed in Hz  */
    uint32_t RCHF_Frequency;			/*!<  RCHF clock frequency expressed in Hz   */
    uint32_t PLL_H_Frequency;			/*!<  PLL H clock frequency expressed in Hz   */
    uint32_t XTHF_Frequency;			/*!<  XTHF clock frequency expressed in Hz   */
    uint32_t LSCLK_Frequency;			/*!<  LSCLK clock frequency expressed in Hz   */
}CMU_ClocksType;



#define	CMU_SYSCLKCR_SLP_ENEXTI_Pos	25
#define	CMU_SYSCLKCR_SLP_ENEXTI_Msk	(0x1U << CMU_SYSCLKCR_SLP_ENEXTI_Pos)

#define	CMU_SYSCLKCR_APBPRES_Pos	16	/* APBʱ�ӷ�Ƶѡ�� (APB1bus clock Prescaler)
000/001/010/011������Ƶ
100��2��Ƶ
101��4��Ƶ
110��8��Ƶ
111��16��Ƶ */
#define	CMU_SYSCLKCR_APBPRES_Msk	(0x7U << CMU_SYSCLKCR_APBPRES_Pos)
#define	CMU_SYSCLKCR_APBPRES_DIV1	(0x0U << CMU_SYSCLKCR_APBPRES_Pos)	/* ����Ƶ */
#define	CMU_SYSCLKCR_APBPRES_DIV2	(0x4U << CMU_SYSCLKCR_APBPRES_Pos)	/* 2��Ƶ */
#define	CMU_SYSCLKCR_APBPRES_DIV4	(0x5U << CMU_SYSCLKCR_APBPRES_Pos)	/* 4��Ƶ */
#define	CMU_SYSCLKCR_APBPRES_DIV8	(0x6U << CMU_SYSCLKCR_APBPRES_Pos)	/* 8��Ƶ */
#define	CMU_SYSCLKCR_APBPRES_DIV16	(0x7U << CMU_SYSCLKCR_APBPRES_Pos)	/* 16��Ƶ */

#define	CMU_SYSCLKCR_AHBPRES_Pos	8	/* AHBʱ�ӷ�Ƶѡ�� (AHB bus clock Prescaler)
000/001/010/011������Ƶ
100��2��Ƶ
101��4��Ƶ
110��8��Ƶ
111��16��Ƶ */
#define	CMU_SYSCLKCR_AHBPRES_Msk	(0x7U << CMU_SYSCLKCR_AHBPRES_Pos)
#define	CMU_SYSCLKCR_AHBPRES_DIV1	(0x0U << CMU_SYSCLKCR_AHBPRES_Pos)	/* ����Ƶ */
#define	CMU_SYSCLKCR_AHBPRES_DIV2	(0x4U << CMU_SYSCLKCR_AHBPRES_Pos)	/* 2��Ƶ */
#define	CMU_SYSCLKCR_AHBPRES_DIV4	(0x5U << CMU_SYSCLKCR_AHBPRES_Pos)	/* 4��Ƶ */
#define	CMU_SYSCLKCR_AHBPRES_DIV8	(0x6U << CMU_SYSCLKCR_AHBPRES_Pos)	/* 8��Ƶ */
#define	CMU_SYSCLKCR_AHBPRES_DIV16	(0x7U << CMU_SYSCLKCR_AHBPRES_Pos)	/* 16��Ƶ */

#define	CMU_SYSCLKCR_STCLKSEL_Pos	6	/* CPU�ں�systick����ʱ��ѡ�� (Systick clock select)
00��SCLK
01��LSCLK
10��RC4M
11��SYSCLK */
#define	CMU_SYSCLKCR_STCLKSEL_Msk	(0x3U << CMU_SYSCLKCR_STCLKSEL_Pos)
#define	CMU_SYSCLKCR_STCLKSEL_SCLK	(0x0U << CMU_SYSCLKCR_STCLKSEL_Pos)	/* SCLK */
#define	CMU_SYSCLKCR_STCLKSEL_LSCLK	(0x1U << CMU_SYSCLKCR_STCLKSEL_Pos)	/* LSCLK */
#define	CMU_SYSCLKCR_STCLKSEL_RC4M	(0x2U << CMU_SYSCLKCR_STCLKSEL_Pos)	/* RC4M */
#define	CMU_SYSCLKCR_STCLKSEL_SYSCLK	(0x3U << CMU_SYSCLKCR_STCLKSEL_Pos)	/* SYSCLK */

#define	CMU_SYSCLKCR_SYSCLKSEL_Pos	0	/* ϵͳʱ��Դѡ�� */
#define	CMU_SYSCLKCR_SYSCLKSEL_Msk	(0x7U << CMU_SYSCLKCR_SYSCLKSEL_Pos)
#define	CMU_SYSCLKCR_SYSCLKSEL_RCHF	(0x0U << CMU_SYSCLKCR_SYSCLKSEL_Pos)	/* RCHF */
#define	CMU_SYSCLKCR_SYSCLKSEL_XTHF	(0x1U << CMU_SYSCLKCR_SYSCLKSEL_Pos)	/* XTHF */
#define	CMU_SYSCLKCR_SYSCLKSEL_PLL_H	(0x2U << CMU_SYSCLKCR_SYSCLKSEL_Pos)	/* PLL_H */
#define	CMU_SYSCLKCR_SYSCLKSEL_LSCLK	(0x3U << CMU_SYSCLKCR_SYSCLKSEL_Pos)	/* LSCLK */

#define	CMU_RCHFCR_FSEL_Pos	16	/* RCHFƵ��ѡ��Ĵ���0000��8MHz
0001��16MHz
0010��24MHz
0011��32MHz
0111��40MHz
1111��48MHz
������RFU */
#define	CMU_RCHFCR_FSEL_Msk	(0xfU << CMU_RCHFCR_FSEL_Pos)
#define	CMU_RCHFCR_FSEL_8MHZ	(0x0U << CMU_RCHFCR_FSEL_Pos)	/* 8MHz */
#define	CMU_RCHFCR_FSEL_16MHZ	(0x1U << CMU_RCHFCR_FSEL_Pos)	/* 16MHz */
#define	CMU_RCHFCR_FSEL_24MHZ	(0x2U << CMU_RCHFCR_FSEL_Pos)	/* 24MHz */
#define	CMU_RCHFCR_FSEL_32MHZ	(0x3U << CMU_RCHFCR_FSEL_Pos)	/* 32MHZ */

#define	CMU_RCHFCR_RCHFEN_Pos	0	/* RCHFʹ�ܼĴ��� (RCHF Enable)
1��ʹ��RCHF
0���ر�RCHF */
#define	CMU_RCHFCR_RCHFEN_Msk	(0x1U << CMU_RCHFCR_RCHFEN_Pos)
	/* ʹ��RCHF */
	/* �ر�RCHF */

#define	CMU_RCHFTR_RCHFTRIM_Pos	0	/* RCHFƵ�ʵ�У�Ĵ�����8��h00��ʾƵ����ͣ�8��hFF��ʾƵ����ߣ���У��ΧΪ����Ƶ��+/-30%����У����Ϊ����Ƶ��0.25%
�ϵ��оƬ�Զ���LDT0��ȡ8MHz��Уֵ��д��˼Ĵ���
���ʹ������Ƶ��ʱ���������д�LDT0ָ����ַ��ȡ��У��Ϣ��д��˼Ĵ������Ӷ�ȷ�����Ƶ��׼ȷ�� */
#define	CMU_RCHFTR_RCHFTRIM_Msk	(0xffU << CMU_RCHFTR_RCHFTRIM_Pos)

#define	CMU_PLLLCR_PLLDB_Pos	16
#define	CMU_PLLLCR_PLLDB_Msk	(0x3ffU << CMU_PLLLCR_PLLDB_Pos)

#define	CMU_PLLLCR_LOCKED_Pos	7
#define	CMU_PLLLCR_LOCKED_Msk	(0x1U << CMU_PLLLCR_LOCKED_Pos)

#define	CMU_PLLLCR_PLLEN_Pos	0	/* PLLʹ�ܼĴ���
1��ʹ��PLL
0���ر�PLL */
#define	CMU_PLLLCR_PLLEN_Msk	(0x1U << CMU_PLLLCR_PLLEN_Pos)

#define	CMU_PLLHCR_PLLHDB_Pos	16	/* PLLH��Ƶ�ȣ��ο�ʱ��1Mhz
0000011111�����32��Ƶ
0101111�����48��Ƶ */
#define	CMU_PLLHCR_PLLHDB_Msk	(0x3ffU << CMU_PLLHCR_PLLHDB_Pos)
#define	CMU_PLLHCR_PLLHDB_X32	(0x1fU << CMU_PLLHCR_PLLHDB_Pos)	/* ���32��Ƶ */
#define	CMU_PLLHCR_PLLHDB_X48	(0x2fU << CMU_PLLHCR_PLLHDB_Pos)	/* ���48��Ƶ */
#define	CMU_PLLHCR_PLLHDB_X64	(0x3fU << CMU_PLLHCR_PLLHDB_Pos)	/* ���64��Ƶ */

#define	CMU_PLLHCR_LOCKED_Pos	7	/* PLLH������־�����ͨ����ѯ�˼Ĵ���ȷ��PLL�Ѿ���������״̬
1��PLL������
0��PLLδ���� */
#define	CMU_PLLHCR_LOCKED_Msk	(0x1U << CMU_PLLHCR_LOCKED_Pos)

#define	CMU_PLLHCR_REFPRSC_Pos	4	/* PLLH�ο�ʱ��Ԥ��Ƶ��Ŀ���ǲ���1MHz�ο�ʱ�Ӹ�PLL��
000������Ƶ
001��2��Ƶ
010��4��Ƶ
011��8��Ƶ
100��12��Ƶ
101��16��Ƶ
110��24��Ƶ
111��32��Ƶ */
#define	CMU_PLLHCR_REFPRSC_Msk	(0x7U << CMU_PLLHCR_REFPRSC_Pos)
#define	CMU_PLLHCR_REFPRSC_DIV1	(0x0U << CMU_PLLHCR_REFPRSC_Pos)	/* ����Ƶ */
#define	CMU_PLLHCR_REFPRSC_DIV2	(0x1U << CMU_PLLHCR_REFPRSC_Pos)	/* 2��Ƶ */
#define	CMU_PLLHCR_REFPRSC_DIV4	(0x2U << CMU_PLLHCR_REFPRSC_Pos)	/* 4��Ƶ */
#define	CMU_PLLHCR_REFPRSC_DIV8	(0x3U << CMU_PLLHCR_REFPRSC_Pos)	/* 8��Ƶ */
#define	CMU_PLLHCR_REFPRSC_DIV12	(0x4U << CMU_PLLHCR_REFPRSC_Pos)	/* 12��Ƶ */
#define	CMU_PLLHCR_REFPRSC_DIV16	(0x5U << CMU_PLLHCR_REFPRSC_Pos)	/* 16��Ƶ */
#define	CMU_PLLHCR_REFPRSC_DIV24	(0x6U << CMU_PLLHCR_REFPRSC_Pos)	/* 24��Ƶ */
#define	CMU_PLLHCR_REFPRSC_DIV32	(0x7U << CMU_PLLHCR_REFPRSC_Pos)	/* 32��Ƶ */

#define	CMU_PLLHCR_OSEL_Pos	3	/* PLLH���ѡ��Ĵ���
0��ѡ��PLLHһ�������Ϊ���ֵ�·�ڵ�PLLʱ��
1��ѡ��PLLH���������Ϊ���ֵ�·�ڵ�PLLʱ�� */
#define	CMU_PLLHCR_OSEL_Msk	(0x1U << CMU_PLLHCR_OSEL_Pos)
#define	CMU_PLLHCR_OSEL_X1	(0x0U << CMU_PLLHCR_OSEL_Pos)
#define	CMU_PLLHCR_OSEL_X2	(0x1U << CMU_PLLHCR_OSEL_Pos)

#define	CMU_PLLHCR_INSEL_Pos	1	/* PLLH����ѡ��Ĵ���
0��RCHF
1��XTHF */
#define	CMU_PLLHCR_INSEL_Msk	(0x1U << CMU_PLLHCR_INSEL_Pos)
#define	CMU_PLLHCR_INSEL_RCHF	(0x0U << CMU_PLLHCR_INSEL_Pos)
#define	CMU_PLLHCR_INSEL_XTHF	(0x1U << CMU_PLLHCR_INSEL_Pos)

#define	CMU_PLLHCR_EN_Pos	0	/* PLLHʹ�ܼĴ���
1��ʹ��PLLH
0���ر�PLLH */
#define	CMU_PLLHCR_EN_Msk	(0x1U << CMU_PLLHCR_EN_Pos)

#define	CMU_XTHFCR_XTHF_CFG_Pos	8	/* XTHF��ǿ������
000������
111����ǿ */
#define	CMU_XTHFCR_XTHF_CFG_Msk	(0x7U << CMU_XTHFCR_XTHF_CFG_Pos)
#define	CMU_XTHFCR_XTHF_CFG_MIN	(0x0U << CMU_XTHFCR_XTHF_CFG_Pos)	/* ���� */
#define	CMU_XTHFCR_XTHF_CFG_MAX	(0x7U << CMU_XTHFCR_XTHF_CFG_Pos)	/* ��ǿ */

#define	CMU_XTHFCR_XTHFEN_Pos	0	/* XTHFʹ�ܼĴ���
0���ر�XTHF
1��ʹ��XTHF */
#define	CMU_XTHFCR_XTHFEN_Msk	(0x1U << CMU_XTHFCR_XTHFEN_Pos)
	/* �ر�XTHF */
	/* ʹ��XTHF */

#define	CMU_IER_SYSCSE_IE_Pos	1
#define	CMU_IER_SYSCSE_IE_Msk	(0x1U << CMU_IER_SYSCSE_IE_Pos)

#define	CMU_IER_HFDET_IE_Pos	0
#define	CMU_IER_HFDET_IE_Msk	(0x1U << CMU_IER_HFDET_IE_Pos)


#define	CMU_ISR_HFDETO_Pos	8	/* ��Ƶ����ͣ����ģ�����
1��XTHFδͣ��
0��XTHFͣ�� */
#define	CMU_ISR_HFDETO_Msk	(0x1U << CMU_ISR_HFDETO_Pos)

#define	CMU_ISR_SYSCSE_IF_Pos	1/* SYSCLKʱ��ѡ������жϱ�־�Ĵ���������ѡ�е�ʱ��Դû��ʹ��ʱ�����жϱ�־��λ�����д1���㡣 */
#define	CMU_ISR_SYSCSE_IF_Msk	(0x1U << CMU_ISR_SYSCSE_IF_Pos)

#define	CMU_ISR_HFDET_IF_Pos	0	/* ��Ƶͣ�����жϱ�־�Ĵ�����XTHFͣ��ʱӲ���첽��λ�����д1���㣻ֻ����FFDETO��Ϊ0������²��ܹ�����˼Ĵ��� */
#define	CMU_ISR_HFDET_IF_Msk	(0x1U << CMU_ISR_HFDET_IF_Pos)

#define	CMU_PCLKCR1_COMP_PCE_Pos	9	/* COMP����ʱ��ʹ�ܣ���ʹ�� */
#define	CMU_PCLKCR1_COMP_PCE_Msk	(0x1U << CMU_PCLKCR1_COMP_PCE_Pos)

#define	CMU_PCLKCR1_SVD_PCE_Pos	8	/* SVD����ʱ��ʹ�ܣ���ʹ�� */
#define	CMU_PCLKCR1_SVD_PCE_Msk	(0x1U << CMU_PCLKCR1_SVD_PCE_Pos)

#define	CMU_PCLKCR1_PAD_PCE_Pos	7	/* PADCFG����ʱ��ʹ�ܣ���ʹ�� */
#define	CMU_PCLKCR1_PAD_PCE_Msk	(0x1U << CMU_PCLKCR1_PAD_PCE_Pos)

#define	CMU_PCLKCR1_ANAC_PCE_Pos	6	/* ANAC����ʱ��ʹ�ܣ���ʹ��
�˼Ĵ������ڿ���SVD���Ƚ���������ʱ�� */
#define	CMU_PCLKCR1_ANAC_PCE_Msk	(0x1U << CMU_PCLKCR1_ANAC_PCE_Pos)

#define	CMU_PCLKCR1_IWDT_PCE_Pos	5	/* IWDT����ʱ��ʹ�ܣ���ʹ�� */
#define	CMU_PCLKCR1_IWDT_PCE_Msk	(0x1U << CMU_PCLKCR1_IWDT_PCE_Pos)

#define	CMU_PCLKCR1_SCU_PCE_Pos	4	/* SCU����ʱ��ʹ�ܣ���ʹ�� */
#define	CMU_PCLKCR1_SCU_PCE_Msk	(0x1U << CMU_PCLKCR1_SCU_PCE_Pos)

#define	CMU_PCLKCR1_PMU_PCE_Pos	3	/* PMU����ʱ��ʹ�ܣ���ʹ�� */
#define	CMU_PCLKCR1_PMU_PCE_Msk	(0x1U << CMU_PCLKCR1_PMU_PCE_Pos)

#define	CMU_PCLKCR1_RTC_PCE_Pos	2	/* RTC����ʱ��ʹ�ܣ���ʹ�� */
#define	CMU_PCLKCR1_RTC_PCE_Msk	(0x1U << CMU_PCLKCR1_RTC_PCE_Pos)

#define	CMU_PCLKCR1_LPT_PCE_Pos	0	/*  _32����ʱ��ʹ�ܣ���ʹ�� */
#define	CMU_PCLKCR1_LPT_PCE_Msk	(0x1U << CMU_PCLKCR1_LPT_PCE_Pos)

#define	CMU_PCLKCR2_PAE_PCE_Pos	17
#define	CMU_PCLKCR2_PAE_PCE_Msk	(0x1U << CMU_PCLKCR2_PAE_PCE_Pos)

#define	CMU_PCLKCR2_SHA_PCE_Pos	16
#define	CMU_PCLKCR2_SHA_PCE_Msk	(0x1U << CMU_PCLKCR2_SHA_PCE_Pos)

#define	CMU_PCLKCR2_CIC_PCE_Pos	8	/* ADC����ʱ��ʹ�ܣ���ʹ�� */
#define	CMU_PCLKCR2_CIC_PCE_Msk	(0x1U << CMU_PCLKCR2_CIC_PCE_Pos)

#define	CMU_PCLKCR2_WWDT_PCE_Pos	7	/* WWDT����ʱ��ʹ�ܣ���ʹ�� */
#define	CMU_PCLKCR2_WWDT_PCE_Msk	(0x1U << CMU_PCLKCR2_WWDT_PCE_Pos)

#define	CMU_PCLKCR2_RAMBIST_PCE_Pos	6	/* RAMBIST����ʱ��ʹ�ܣ���ʹ�� */
#define	CMU_PCLKCR2_RAMBIST_PCE_Msk	(0x1U << CMU_PCLKCR2_RAMBIST_PCE_Pos)

#define	CMU_PCLKCR2_NVM_PCE_Pos	5	/* NVMIF��Flash��д������������ʱ��ʹ�ܣ���ʹ�� */
#define	CMU_PCLKCR2_NVM_PCE_Msk	(0x1U << CMU_PCLKCR2_NVM_PCE_Pos)

#define	CMU_PCLKCR2_DMA_PCE_Pos	4	/* DMA����ʱ��ʹ�ܣ���ʹ�� */
#define	CMU_PCLKCR2_DMA_PCE_Msk	(0x1U << CMU_PCLKCR2_DMA_PCE_Pos)

#define	CMU_PCLKCR2_LCD_PCE_Pos	3	/* LCD����ʱ��ʹ�ܣ���ʹ�� */
#define	CMU_PCLKCR2_LCD_PCE_Msk	(0x1U << CMU_PCLKCR2_LCD_PCE_Pos)

#define	CMU_PCLKCR2_AES_PCE_Pos	2	/* AES����ʱ��ʹ�ܣ���ʹ�� */
#define	CMU_PCLKCR2_AES_PCE_Msk	(0x1U << CMU_PCLKCR2_AES_PCE_Pos)

#define	CMU_PCLKCR2_TRNG_PCE_Pos	1	/* RNG����ʱ��ʹ�ܣ���ʹ�� */
#define	CMU_PCLKCR2_TRNG_PCE_Msk	(0x1U << CMU_PCLKCR2_TRNG_PCE_Pos)

#define	CMU_PCLKCR2_CRC_PCE_Pos	0	/* CRC����ʱ��ʹ�ܣ���ʹ�� */
#define	CMU_PCLKCR2_CRC_PCE_Msk	(0x1U << CMU_PCLKCR2_CRC_PCE_Pos)

#define	CMU_PCLKCR3_I2C1_PCE_Pos	25	/* I2C1����ʱ��ʹ�ܣ�����Ч */
#define	CMU_PCLKCR3_I2C1_PCE_Msk	(0x1U << CMU_PCLKCR3_I2C1_PCE_Pos)

#define	CMU_PCLKCR3_I2C0_PCE_Pos	24	/* I2C0����ʱ��ʹ�ܣ�����Ч */
#define	CMU_PCLKCR3_I2C0_PCE_Msk	(0x1U << CMU_PCLKCR3_I2C0_PCE_Pos)

#define	CMU_PCLKCR3_LPUART1_PCE_Pos	18	/* LPUART1����ʱ��ʹ�ܣ�����Ч */
#define	CMU_PCLKCR3_LPUART1_PCE_Msk	(0x1U << CMU_PCLKCR3_LPUART1_PCE_Pos)

#define	CMU_PCLKCR3_U7816_PCE_Pos	16	/* 7816����ʱ��ʹ�ܣ�����Ч */
#define	CMU_PCLKCR3_U7816_PCE_Msk	(0x1U << CMU_PCLKCR3_U7816_PCE_Pos)

#define	CMU_PCLKCR3_LPUART0_PCE_Pos	15	/* LPUART0����ʱ��ʹ�ܣ�����Ч */
#define	CMU_PCLKCR3_LPUART0_PCE_Msk	(0x1U << CMU_PCLKCR3_LPUART0_PCE_Pos)

#define	CMU_PCLKCR3_UICR_PCE_Pos	14	/* UART�����������ʹ�ܣ�����Ч */
#define	CMU_PCLKCR3_UICR_PCE_Msk	(0x1U << CMU_PCLKCR3_UICR_PCE_Pos)

#define	CMU_PCLKCR3_UART5_PCE_Pos	13	/* UART5����ʱ��ʹ�ܣ�����Ч */
#define	CMU_PCLKCR3_UART5_PCE_Msk	(0x1U << CMU_PCLKCR3_UART5_PCE_Pos)

#define	CMU_PCLKCR3_UART4_PCE_Pos	12	/* UART4����ʱ��ʹ�ܣ�����Ч */
#define	CMU_PCLKCR3_UART4_PCE_Msk	(0x1U << CMU_PCLKCR3_UART4_PCE_Pos)

#define	CMU_PCLKCR3_UART3_PCE_Pos	11	/* UART3����ʱ��ʹ�ܣ�����Ч */
#define	CMU_PCLKCR3_UART3_PCE_Msk	(0x1U << CMU_PCLKCR3_UART3_PCE_Pos)

#define	CMU_PCLKCR3_UART2_PCE_Pos	10	/* UART2����ʱ��ʹ�ܣ�����Ч */
#define	CMU_PCLKCR3_UART2_PCE_Msk	(0x1U << CMU_PCLKCR3_UART2_PCE_Pos)

#define	CMU_PCLKCR3_UART1_PCE_Pos	9	/* UART1����ʱ��ʹ�ܣ�����Ч */
#define	CMU_PCLKCR3_UART1_PCE_Msk	(0x1U << CMU_PCLKCR3_UART1_PCE_Pos)

#define	CMU_PCLKCR3_UART0_PCE_Pos	8	/* UART0����ʱ��ʹ�ܣ�����Ч */
#define	CMU_PCLKCR3_UART0_PCE_Msk	(0x1U << CMU_PCLKCR3_UART0_PCE_Pos)

#define	CMU_PCLKCR3_QSPI_PCE_Pos	7	/* QuadSPI����ʱ��ʹ�ܣ�����Ч */
#define	CMU_PCLKCR3_QSPI_PCE_Msk	(0x1U << CMU_PCLKCR3_QSPI_PCE_Pos)

#define	CMU_PCLKCR3_SPI4_PCE_Pos	4	/* SPI4����ʱ��ʹ�ܣ�����Ч */
#define	CMU_PCLKCR3_SPI4_PCE_Msk	(0x1U << CMU_PCLKCR3_SPI4_PCE_Pos)

#define	CMU_PCLKCR3_SPI3_PCE_Pos	3	/* SPI3����ʱ��ʹ�ܣ�����Ч */
#define	CMU_PCLKCR3_SPI3_PCE_Msk	(0x1U << CMU_PCLKCR3_SPI3_PCE_Pos)

#define	CMU_PCLKCR3_SPI2_PCE_Pos	2	/* SPI2����ʱ��ʹ�ܣ�����Ч */
#define	CMU_PCLKCR3_SPI2_PCE_Msk	(0x1U << CMU_PCLKCR3_SPI2_PCE_Pos)

#define	CMU_PCLKCR3_SPI1_PCE_Pos	1	/* SPI1����ʱ��ʹ�ܣ�����Ч */
#define	CMU_PCLKCR3_SPI1_PCE_Msk	(0x1U << CMU_PCLKCR3_SPI1_PCE_Pos)

#define	CMU_PCLKCR3_SPI0_PCE_Pos	0	/* SPI0����ʱ��ʹ�ܣ�����Ч */
#define	CMU_PCLKCR3_SPI0_PCE_Msk	(0x1U << CMU_PCLKCR3_SPI0_PCE_Pos)

#define	CMU_PCLKCR4_ET4_PCE_Pos	6	/* Etimer4ʱ��ʹ�ܣ���ʹ�� */
#define	CMU_PCLKCR4_ET4_PCE_Msk	(0x1U << CMU_PCLKCR4_ET4_PCE_Pos)

#define	CMU_PCLKCR4_ET3_PCE_Pos	5	/* Etimer3ʱ��ʹ�ܣ���ʹ�� */
#define	CMU_PCLKCR4_ET3_PCE_Msk	(0x1U << CMU_PCLKCR4_ET3_PCE_Pos)

#define	CMU_PCLKCR4_ET2_PCE_Pos	4	/* Etimer2ʱ��ʹ�ܣ���ʹ�� */
#define	CMU_PCLKCR4_ET2_PCE_Msk	(0x1U << CMU_PCLKCR4_ET2_PCE_Pos)

#define	CMU_PCLKCR4_ET1_PCE_Pos	3	/* Etimer1ʱ��ʹ�ܣ���ʹ�� */
#define	CMU_PCLKCR4_ET1_PCE_Msk	(0x1U << CMU_PCLKCR4_ET1_PCE_Pos)

#define	CMU_PCLKCR4_BT2_PCE_Pos	2	/* BaseTimer2ʱ��ʹ�ܣ���ʹ�� */
#define	CMU_PCLKCR4_BT2_PCE_Msk	(0x1U << CMU_PCLKCR4_BT2_PCE_Pos)

#define	CMU_PCLKCR4_BT1_PCE_Pos	1	/* BaseTimer1ʱ��ʹ�ܣ���ʹ�� */
#define	CMU_PCLKCR4_BT1_PCE_Msk	(0x1U << CMU_PCLKCR4_BT1_PCE_Pos)

#define	CMU_PCLKCR4_BSTIM_PCE_Pos	0	/* ������ʱ��BSTIM����ʱ��ʹ�ܣ���ʹ�� */
#define	CMU_PCLKCR4_BSTIM_PCE_Msk	(0x1U << CMU_PCLKCR4_BSTIM_PCE_Pos)

#define	CMU_OPCCR1_EXTICKE_Pos	31	/* EXTI����ʱ��ʹ�ܣ�����Ч */
#define	CMU_OPCCR1_EXTICKE_Msk	(0x1U << CMU_OPCCR1_EXTICKE_Pos)

#define	CMU_OPCCR1_EXTICKSEL_Pos	30	/* EXTI�жϲ���ʱ��ѡ�� */
#define	CMU_OPCCR1_EXTICKSEL_Msk	(0x1U << CMU_OPCCR1_EXTICKSEL_Pos)
#define	CMU_OPCCR1_EXTICKSEL_LSCLK	(0x1U << CMU_OPCCR1_EXTICKSEL_Pos) /* 1���ⲿ�����ж�ʹ��LSCLK���� */
#define	CMU_OPCCR1_EXTICKSEL_HCLK	  (0x0U << CMU_OPCCR1_EXTICKSEL_Pos) /* 0���ⲿ�����ж�ʹ��HCLK���� */

#define	CMU_OPCCR1_LPUART1CKE_Pos	29	/* LPUART1����ʱ��ʹ�ܣ�����Ч */
#define	CMU_OPCCR1_LPUART1CKE_Msk	(0x1U << CMU_OPCCR1_LPUART1CKE_Pos)

#define	CMU_OPCCR1_LPUART0CKE_Pos	28	/* LPUART0����ʱ��ʹ�ܣ�����Ч */
#define	CMU_OPCCR1_LPUART0CKE_Msk	(0x1U << CMU_OPCCR1_LPUART0CKE_Pos)

#define	CMU_OPCCR1_LPUART1CKS_Pos	26	/* LPUART1����ʱ��ѡ��
00��LSCLK
01��RCHF��Ƶ������RCHF��λ�Զ���Ƶ��32768Hz������
10��RFU
11��RFU */
#define	CMU_OPCCR1_LPUART1CKS_Msk	(0x3U << CMU_OPCCR1_LPUART1CKS_Pos)
#define	CMU_OPCCR1_LPUART1CKS_LSCLK	(0x0U << CMU_OPCCR1_LPUART1CKS_Pos)	/* LSCLK */
#define	CMU_OPCCR1_LPUART1CKS_RCHF	(0x1U << CMU_OPCCR1_LPUART1CKS_Pos)	/* RCHF��Ƶ������RCHF��λ�Զ���Ƶ��32768Hz������ */

#define	CMU_OPCCR1_LPUART0CKS_Pos	24	/* LPUART0����ʱ��ѡ��
00��LSCLK
01��RCHF��Ƶ������RCHF��λ�Զ���Ƶ��32768Hz������
10��RFU
11��RFU */
#define	CMU_OPCCR1_LPUART0CKS_Msk	(0x3U << CMU_OPCCR1_LPUART0CKS_Pos)
#define	CMU_OPCCR1_LPUART0CKS_LSCLK	(0x0U << CMU_OPCCR1_LPUART0CKS_Pos)	/* LSCLK */
#define	CMU_OPCCR1_LPUART0CKS_RCHF	(0x1U << CMU_OPCCR1_LPUART0CKS_Pos)	/* RCHF��Ƶ������RCHF��λ�Զ���Ƶ��32768Hz������ */

#define	CMU_OPCCR1_I2C1CKE_Pos	21	/* I2C1����ʱ��ʹ�� */
#define	CMU_OPCCR1_I2C1CKE_Msk	(0x1U << CMU_OPCCR1_I2C1CKE_Pos)

#define	CMU_OPCCR1_I2C0CKE_Pos	20	/* I2C0����ʱ��ʹ�� */
#define	CMU_OPCCR1_I2C0CKE_Msk	(0x1U << CMU_OPCCR1_I2C0CKE_Pos)

#define	CMU_OPCCR1_I2C1CKS_Pos	18	/* I2C1��������ʱ��ѡ��
00��APBCLK
01��RCHF
10��SYSCLK
11��APBCLK */
#define	CMU_OPCCR1_I2C1CKS_Msk	(0x3U << CMU_OPCCR1_I2C1CKS_Pos)
#define	CMU_OPCCR1_I2C1CKS_APBCLK	(0x0U << CMU_OPCCR1_I2C1CKS_Pos)	/* APBCLK */
#define	CMU_OPCCR1_I2C1CKS_RCHF	(0x1U << CMU_OPCCR1_I2C1CKS_Pos)	/* RCHF */
#define	CMU_OPCCR1_I2C1CKS_SYSCLK	(0x2U << CMU_OPCCR1_I2C1CKS_Pos)	/* SYSCLK */

#define	CMU_OPCCR1_I2C0CKS_Pos	16	/* I2C0��������ʱ��ѡ��
00��APBCLK
01��RCHF
10��SYSCLK
11��APBCLK */
#define	CMU_OPCCR1_I2C0CKS_Msk	(0x3U << CMU_OPCCR1_I2C0CKS_Pos)
#define	CMU_OPCCR1_I2C0CKS_APBCLK	(0x0U << CMU_OPCCR1_I2C0CKS_Pos)	/* APBCLK */
#define	CMU_OPCCR1_I2C0CKS_RCHF	(0x1U << CMU_OPCCR1_I2C0CKS_Pos)	/* RCHF */
#define	CMU_OPCCR1_I2C0CKS_SYSCLK	(0x2U << CMU_OPCCR1_I2C0CKS_Pos)	/* SYSCLK */

#define	CMU_OPCCR1_UART1CKE_Pos	9	/* UART1����ʱ��ʹ�ܣ�����Ч */
#define	CMU_OPCCR1_UART1CKE_Msk	(0x1U << CMU_OPCCR1_UART1CKE_Pos)

#define	CMU_OPCCR1_UART0CKE_Pos	8	/* UART0����ʱ��ʹ�ܣ�����Ч */
#define	CMU_OPCCR1_UART0CKE_Msk	(0x1U << CMU_OPCCR1_UART0CKE_Pos)

#define	CMU_OPCCR1_UART1CKS_Pos	2	/* UART1����ʱ��ѡ��
00��APBCLK
01��RCHF
10��SYSCLK
11��RFU */
#define	CMU_OPCCR1_UART1CKS_Msk	(0x3U << CMU_OPCCR1_UART1CKS_Pos)
#define	CMU_OPCCR1_UART1CKS_APBCLK	(0x0U << CMU_OPCCR1_UART1CKS_Pos)	/* APBCLK */
#define	CMU_OPCCR1_UART1CKS_RCHF	(0x1U << CMU_OPCCR1_UART1CKS_Pos)	/* RCHF */
#define	CMU_OPCCR1_UART1CKS_SYSCLK	(0x2U << CMU_OPCCR1_UART1CKS_Pos)	/* SYSCLK */

#define	CMU_OPCCR1_UART0CKS_Pos	0	/* UART0����ʱ��ѡ��
00��APBCLK
01��RCHF
10��SYSCLK
11��RFU */
#define	CMU_OPCCR1_UART0CKS_Msk	(0x3U << CMU_OPCCR1_UART0CKS_Pos)
#define	CMU_OPCCR1_UART0CKS_APBCLK	(0x0U << CMU_OPCCR1_UART0CKS_Pos)	/* APBCLK */
#define	CMU_OPCCR1_UART0CKS_RCHF	(0x1U << CMU_OPCCR1_UART0CKS_Pos)	/* RCHF */
#define	CMU_OPCCR1_UART0CKS_SYSCLK	(0x2U << CMU_OPCCR1_UART0CKS_Pos)	/* SYSCLK */

#define	CMU_OPCCR2_RNGPRSC_Pos	28	/* ���������������ʱ�ӷ�Ƶ
000������Ƶ
001��2��Ƶ
010��4��Ƶ
011��8��Ƶ
100��16��Ƶ
101��32��Ƶ
110, 111��RFU */
#define	CMU_OPCCR2_RNGPRSC_Msk	(0x7U << CMU_OPCCR2_RNGPRSC_Pos)
#define	CMU_OPCCR2_RNGPRSC_DIV1	(0x0U << CMU_OPCCR2_RNGPRSC_Pos)	/* ����Ƶ */
#define	CMU_OPCCR2_RNGPRSC_DIV2	(0x1U << CMU_OPCCR2_RNGPRSC_Pos)	/* 2��Ƶ */
#define	CMU_OPCCR2_RNGPRSC_DIV4	(0x2U << CMU_OPCCR2_RNGPRSC_Pos)	/* 4��Ƶ */
#define	CMU_OPCCR2_RNGPRSC_DIV8	(0x3U << CMU_OPCCR2_RNGPRSC_Pos)	/* 8��Ƶ */
#define	CMU_OPCCR2_RNGPRSC_DIV16	(0x4U << CMU_OPCCR2_RNGPRSC_Pos)	/* 16��Ƶ */
#define	CMU_OPCCR2_RNGPRSC_DIV32	(0x5U << CMU_OPCCR2_RNGPRSC_Pos)	/* 32��Ƶ */

#define	CMU_OPCCR2_NVMCKE_Pos	22	/* Flash��дʱ��ʹ�ܣ�����Ч */
#define	CMU_OPCCR2_NVMCKE_Msk	(0x1U << CMU_OPCCR2_NVMCKE_Pos)

#define	CMU_OPCCR2_RNGCKE_Pos	21	/* ���������������ʱ��ʹ�ܣ�����Ч */
#define	CMU_OPCCR2_RNGCKE_Msk	(0x1U << CMU_OPCCR2_RNGCKE_Pos)

#define	CMU_OPCCR2_LPTCKE_Pos	12	/*  _����ʱ��ʹ�ܣ�����Ч */
#define	CMU_OPCCR2_LPTCKE_Msk	(0x1U << CMU_OPCCR2_LPTCKE_Pos)

#define	CMU_OPCCR2_LPTCKS_Pos	8	/*  _����ʱ��ѡ��
00��APBCLK
01��LSCLK
10��RCLP
11��PLL_L */
#define	CMU_OPCCR2_LPTCKS_Msk	(0x3U << CMU_OPCCR2_LPTCKS_Pos)
#define	CMU_OPCCR2_LPTCKS_APBCLK	(0x0U << CMU_OPCCR2_LPTCKS_Pos)	/* APBCLK */
#define	CMU_OPCCR2_LPTCKS_LSCLK	(0x1U << CMU_OPCCR2_LPTCKS_Pos)	/* LSCLK */
#define	CMU_OPCCR2_LPTCKS_RCLP	(0x2U << CMU_OPCCR2_LPTCKS_Pos)	/* RCLP */
#define	CMU_OPCCR2_LPTCKS_PLL_L	(0x3U << CMU_OPCCR2_LPTCKS_Pos)	/* PLL_L */

#define	CMU_OPCCR2_BSTCKE_Pos	4	/* BSTIM����ʱ��ʹ�ܣ�����Ч */
#define	CMU_OPCCR2_BSTCKE_Msk	(0x1U << CMU_OPCCR2_BSTCKE_Pos)

#define	CMU_OPCCR2_BSTCKS_Pos	0	/* BSTIM����ʱ��Դѡ��
00��APBCLK
01��LSCLK
10��RCLP
11��SYSCLK */
#define	CMU_OPCCR2_BSTCKS_Msk	(0x3U << CMU_OPCCR2_BSTCKS_Pos)
#define	CMU_OPCCR2_BSTCKS_APBCLK	(0x0U << CMU_OPCCR2_BSTCKS_Pos)	/* APBCLK */
#define	CMU_OPCCR2_BSTCKS_LSCLK	(0x1U << CMU_OPCCR2_BSTCKS_Pos)	/* LSCLK */
#define	CMU_OPCCR2_BSTCKS_RCLP	(0x2U << CMU_OPCCR2_BSTCKS_Pos)	/* RCLP */
#define	CMU_OPCCR2_BSTCKS_SYSCLK	(0x3U << CMU_OPCCR2_BSTCKS_Pos)	/* SYSCLK */
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void CMU_Deinit(void);
extern void CMU_SYSCLKCR_SLP_ENEXTI_Setable(FunState NewState);
extern FunState CMU_SYSCLKCR_SLP_ENEXTI_Getable(void);

/* APBʱ�ӷ�Ƶѡ�� (APBbus clock Prescaler)
000/001/010/011������Ƶ
100��2��Ƶ
101��4��Ƶ
110��8��Ƶ
111��16��Ƶ ��غ��� */
extern void CMU_SYSCLKCR_APBPRES_Set(uint32_t SetValue);
extern uint32_t CMU_SYSCLKCR_APBPRES_Get(void);

/* AHBʱ�ӷ�Ƶѡ�� (AHB bus clock Prescaler)
000/001/010/011������Ƶ
100��2��Ƶ
101��4��Ƶ
110��8��Ƶ
111��16��Ƶ ��غ��� */
extern void CMU_SYSCLKCR_AHBPRES_Set(uint32_t SetValue);
extern uint32_t CMU_SYSCLKCR_AHBPRES_Get(void);

/* CPU�ں�systick����ʱ��ѡ�� (Systick clock select)
00��SCLK
01��LSCLK
10��RC4M
11��SYSCLK ��غ��� */
extern void CMU_SYSCLKCR_STCLKSEL_Set(uint32_t SetValue);
extern uint32_t CMU_SYSCLKCR_STCLKSEL_Get(void);

/* ϵͳʱ��Դѡ�� ��غ��� */
extern void CMU_SYSCLKCR_SYSCLKSEL_Set(uint32_t SetValue);
extern uint32_t CMU_SYSCLKCR_SYSCLKSEL_Get(void);

/* RCHFƵ��ѡ��Ĵ���0000��8MHz
0001��16MHz
0010��24MHz
0011��32MHz
0111��40MHz
1111��48MHz
������RFU ��غ��� */
extern void CMU_RCHFCR_FSEL_Set(uint32_t SetValue);
extern uint32_t CMU_RCHFCR_FSEL_Get(void);

/* RCHFʹ�ܼĴ��� (RCHF Enable)
1��ʹ��RCHF
0���ر�RCHF ��غ��� */
extern void CMU_RCHFCR_RCHFEN_Setable(FunState NewState);
extern FunState CMU_RCHFCR_RCHFEN_Getable(void);

/* RCHFƵ�ʵ�У�Ĵ�����8��h00��ʾƵ����ͣ�8��hFF��ʾƵ����ߣ���У��ΧΪ����Ƶ��+/-30%����У����Ϊ����Ƶ��0.25%
�ϵ��оƬ�Զ���LDT0��ȡ8MHz��Уֵ��д��˼Ĵ���
���ʹ������Ƶ��ʱ���������д�LDT0ָ����ַ��ȡ��У��Ϣ��д��˼Ĵ������Ӷ�ȷ�����Ƶ��׼ȷ�� ��غ��� */
extern void CMU_RCHFTR_RCHFTRIM_Set(uint32_t SetValue);
extern uint32_t CMU_RCHFTR_RCHFTRIM_Get(void);
extern FlagStatus CMU_PLLLCR_LOCKED_Chk(void);
extern void CMU_PLLLCR_PLLDB_Set(uint32_t SetValue);
extern uint32_t CMU_PLLLCR_PLLDB_Get(void);

/* PLLʹ�ܼĴ���
1��ʹ��PLL
0���ر�PLL ��غ��� */
extern void CMU_PLLLCR_PLLEN_Setable(FunState NewState);
extern FunState CMU_PLLLCR_PLLEN_Getable(void);

/* PLLH��Ƶ�ȣ��ο�ʱ��1Mhz
0000011111�����32��Ƶ
0101111�����48��Ƶ ��غ��� */
extern void CMU_PLLHCR_PLLHDB_Set(uint32_t SetValue);
extern uint32_t CMU_PLLHCR_PLLHDB_Get(void);

/* PLLH������־�����ͨ����ѯ�˼Ĵ���ȷ��PLL�Ѿ���������״̬
1��PLL������
0��PLLδ���� ��غ��� */
extern FlagStatus CMU_PLLHCR_LOCKED_Chk(void);

/* PLLH�ο�ʱ��Ԥ��Ƶ��Ŀ���ǲ���1MHz�ο�ʱ�Ӹ�PLL��
000������Ƶ
001��2��Ƶ
010��4��Ƶ
011��8��Ƶ
100��12��Ƶ
101��16��Ƶ
110��24��Ƶ
111��32��Ƶ ��غ��� */
extern void CMU_PLLHCR_REFPRSC_Set(uint32_t SetValue);
extern uint32_t CMU_PLLHCR_REFPRSC_Get(void);

/* PLLH���ѡ��Ĵ���
0��ѡ��PLLHһ�������Ϊ���ֵ�·�ڵ�PLLʱ��
1��ѡ��PLLH���������Ϊ���ֵ�·�ڵ�PLLʱ�� ��غ��� */
extern void CMU_PLLHCR_OSEL_Set(uint32_t SetValue);
extern uint32_t CMU_PLLHCR_OSEL_Get(void);

/* PLLH����ѡ��Ĵ���
00/11��RCHF
01��PLL_L
10��XTHF ��غ��� */
extern void CMU_PLLHCR_INSEL_Set(uint32_t SetValue);
extern uint32_t CMU_PLLHCR_INSEL_Get(void);

/* PLLHʹ�ܼĴ���
1��ʹ��PLLH
0���ر�PLLH ��غ��� */
extern void CMU_PLLHCR_EN_Setable(FunState NewState);
extern FunState CMU_PLLHCR_EN_Getable(void);

/* XTHF��ǿ������
000������
111����ǿ ��غ��� */
extern void CMU_XTHFCR_XTHF_CFG_Set(uint32_t SetValue);
extern uint32_t CMU_XTHFCR_XTHF_CFG_Get(void);

/* XTHFʹ�ܼĴ���
0���ر�XTHF
1��ʹ��XTHF ��غ��� */
extern void CMU_XTHFCR_XTHFEN_Setable(FunState NewState);
extern FunState CMU_XTHFCR_XTHFEN_Getable(void);
extern void CMU_IER_SYSCSE_IE_Setable(FunState NewState);
extern FunState CMU_IER_SYSCSE_IE_Getable(void);
extern void CMU_IER_HFDET_IE_Setable(FunState NewState);
extern FunState CMU_IER_HFDET_IE_Getable(void);


/* ��Ƶ����ͣ����ģ�����
1��XTHFδͣ��
0��XTHFͣ�� ��غ��� */
extern FlagStatus CMU_ISR_HFDETO_Chk(void);

/* ��Ƶ����ͣ����ģ�����
1��XTLFδͣ��
0��XTLFͣ�� ��غ��� */
extern FlagStatus CMU_ISR_LFDETO_Chk(void);

/* SYSCLKʱ��ѡ������жϱ�־�Ĵ���������ѡ�е�ʱ��Դû��ʹ��ʱ�����жϱ�־��λ�����д1���㡣 ��غ��� */
extern void CMU_ISR_SYSCSE_IF_Clr(void);
extern FlagStatus CMU_ISR_SYSCSE_IF_Chk(void);

/* ��Ƶͣ�����жϱ�־�Ĵ�����XTHFͣ��ʱӲ���첽��λ�����д1���㣻ֻ����FFDETO��Ϊ0������²��ܹ�����˼Ĵ��� ��غ��� */
extern void CMU_ISR_HFDET_IF_Clr(void);
extern FlagStatus CMU_ISR_HFDET_IF_Chk(void);

/* EXTI����ʱ��ʹ�ܣ�����Ч ��غ��� */
extern void CMU_OPCCR1_EXTICKE_Setable(FunState NewState);
extern FunState CMU_OPCCR1_EXTICKE_Getable(void);

/* EXTI�жϲ���ʱ��ѡ�� */
extern void CMU_OPCCR1_EXTICKSEL_Set(uint32_t SetValue);
extern uint32_t CMU_OPCCR1_EXTICKSEL_Get(void);

/* LPUART1����ʱ��ʹ�ܣ�����Ч ��غ��� */
extern void CMU_OPCCR1_LPUART1CKE_Setable(FunState NewState);
extern FunState CMU_OPCCR1_LPUART1CKE_Getable(void);

/* LPUART0����ʱ��ʹ�ܣ�����Ч ��غ��� */
extern void CMU_OPCCR1_LPUART0CKE_Setable(FunState NewState);
extern FunState CMU_OPCCR1_LPUART0CKE_Getable(void);

/* LPUART1����ʱ��ѡ��
00��LSCLK
01��RCHF��Ƶ������RCHF��λ�Զ���Ƶ��32768Hz������
10��RFU
11��RFU ��غ��� */
extern void CMU_OPCCR1_LPUART1CKS_Set(uint32_t SetValue);
extern uint32_t CMU_OPCCR1_LPUART1CKS_Get(void);

/* LPUART0����ʱ��ѡ��
00��LSCLK
01��RCHF��Ƶ������RCHF��λ�Զ���Ƶ��32768Hz������
10��RFU
11��RFU ��غ��� */
extern void CMU_OPCCR1_LPUART0CKS_Set(uint32_t SetValue);
extern uint32_t CMU_OPCCR1_LPUART0CKS_Get(void);

/* I2C1����ʱ��ʹ�� ��غ��� */
extern void CMU_OPCCR1_I2C1CKE_Setable(FunState NewState);
extern FunState CMU_OPCCR1_I2C1CKE_Getable(void);

/* I2C0����ʱ��ʹ�� ��غ��� */
extern void CMU_OPCCR1_I2C0CKE_Setable(FunState NewState);
extern FunState CMU_OPCCR1_I2C0CKE_Getable(void);

/* I2C1��������ʱ��ѡ��
00��APBCLK
01��RCHF
10��SYSCLK
11��APBCLK ��غ��� */
extern void CMU_OPCCR1_I2C1CKS_Set(uint32_t SetValue);
extern uint32_t CMU_OPCCR1_I2C1CKS_Get(void);


/* I2C0��������ʱ��ѡ��
00��APBCLK
01��RCHF
10��SYSCLK
11��APBCLK ��غ��� */
extern void CMU_OPCCR1_I2C0CKS_Set(uint32_t SetValue);
extern uint32_t CMU_OPCCR1_I2C0CKS_Get(void);

/* UART1����ʱ��ʹ�ܣ�����Ч ��غ��� */
extern void CMU_OPCCR1_UART1CKE_Setable(FunState NewState);
extern FunState CMU_OPCCR1_UART1CKE_Getable(void);

/* UART0����ʱ��ʹ�ܣ�����Ч ��غ��� */
extern void CMU_OPCCR1_UART0CKE_Setable(FunState NewState);
extern FunState CMU_OPCCR1_UART0CKE_Getable(void);

/* UART1����ʱ��ѡ��
00��APBCLK
01��RCHF
10��SYSCLK
11��RFU ��غ��� */
extern void CMU_OPCCR1_UART1CKS_Set(uint32_t SetValue);
extern uint32_t CMU_OPCCR1_UART1CKS_Get(void);

/* UART0����ʱ��ѡ��
00��APBCLK
01��RCHF
10��SYSCLK
11��RFU ��غ��� */
extern void CMU_OPCCR1_UART0CKS_Set(uint32_t SetValue);
extern uint32_t CMU_OPCCR1_UART0CKS_Get(void);

/* ���������������ʱ�ӷ�Ƶ
000������Ƶ
001��2��Ƶ
010��4��Ƶ
011��8��Ƶ
100��16��Ƶ
101��32��Ƶ
110, 111��RFU ��غ��� */
extern void CMU_OPCCR2_RNGPRSC_Set(uint32_t SetValue);
extern uint32_t CMU_OPCCR2_RNGPRSC_Get(void);

/* Flash��дʱ��ʹ�ܣ�����Ч ��غ��� */
extern void CMU_OPCCR2_NVMCKE_Setable(FunState NewState);
extern FunState CMU_OPCCR2_NVMCKE_Getable(void);

/* ���������������ʱ��ʹ�ܣ�����Ч ��غ��� */
extern void CMU_OPCCR2_RNGCKE_Setable(FunState NewState);
extern FunState CMU_OPCCR2_RNGCKE_Getable(void);

/*  _����ʱ��ʹ�ܣ�����Ч ��غ��� */
extern void CMU_OPCCR2_LPTCKE_Setable(FunState NewState);
extern FunState CMU_OPCCR2_LPTCKE_Getable(void);

/*  _����ʱ��ѡ��
00��APBCLK
01��LSCLK
10��RCLP
11��PLL_L ��غ��� */
extern void CMU_OPCCR2_LPTCKS_Set(uint32_t SetValue);
extern uint32_t CMU_OPCCR2_LPTCKS_Get(void);

/* BSTIM����ʱ��ʹ�ܣ�����Ч ��غ��� */
extern void CMU_OPCCR2_BSTCKE_Setable(FunState NewState);
extern FunState CMU_OPCCR2_BSTCKE_Getable(void);

/* BSTIM����ʱ��Դѡ��
00��APBCLK
01��LSCLK
10��RCLP
11��SYSCLK ��غ��� */
extern void CMU_OPCCR2_BSTCKS_Set(uint32_t SetValue);
extern uint32_t CMU_OPCCR2_BSTCKS_Get(void);
//Announce_End

/* ��ȡоƬ�����õĲ�ͬʱ��Ƶ�ʺ��� */
extern void CMU_GetClocksFreq(CMU_ClocksType* para);

/* RCHF��ʼ������ */
extern void CMU_RCHF_Init(CMU_RCHF_InitTypeDef* para);

/* PLL H��ʼ������ */
void CMU_PLL_H_Init(CMU_PLL_H_InitTypeDef* para);

/* rchf����У׼ֵ���뺯�� */
extern void CMU_Init_RCHF_Trim( uint8_t ClkMode );

/* ϵͳʱ�ӳ�ʼ�� */
extern void CMU_SysClk_Init(CMU_SYSCLK_InitTypeDef* para);

/* ����ʱ�ӿ��Ʋ������� */
#define	COMPCLK		    (0x01000000 + CMU_PCLKCR1_COMP_PCE_Pos)	//9	/* COMP����ʱ��ʹ�ܣ���ʹ�� */
#define	SVDCLK		    (0x01000000 + CMU_PCLKCR1_SVD_PCE_Pos)	//8	/* SVD����ʱ��ʹ�ܣ���ʹ�� */
#define	PADCLK			(0x01000000 + CMU_PCLKCR1_PAD_PCE_Pos)	//7	/* PADCFG����ʱ��ʹ�ܣ���ʹ�� */
#define	ANACCLK			(0x01000000 + CMU_PCLKCR1_ANAC_PCE_Pos)	//6	/* ANAC����ʱ��ʹ�ܣ���ʹ�ܴ˼Ĵ������ڿ���SVD���Ƚ���������ʱ�� */
#define	IWDTCLK			(0x01000000 + CMU_PCLKCR1_IWDT_PCE_Pos)	//5	/* IWDT����ʱ��ʹ�ܣ���ʹ�� */
#define	SCUCLK			(0x01000000 + CMU_PCLKCR1_SCU_PCE_Pos)	//4	/* SCU����ʱ��ʹ�ܣ���ʹ�� */
#define	PMUCLK			(0x01000000 + CMU_PCLKCR1_PMU_PCE_Pos)	//3	/* PMU����ʱ��ʹ�ܣ���ʹ�� */
#define	RTCCLK			(0x01000000 + CMU_PCLKCR1_RTC_PCE_Pos)	//2	/* RTC����ʱ��ʹ�ܣ���ʹ�� */
#define	LPTCLK			(0x01000000 + CMU_PCLKCR1_LPT_PCE_Pos)	//0	/* LPTIM����ʱ��ʹ�ܣ���ʹ�� */
        

#define	PAECLK			(0x02000000 + CMU_PCLKCR2_PAE_PCE_Pos)	//17	/* PAE����ʱ��ʹ�ܣ���ʹ�� */
#define	SHACLK			(0x02000000 + CMU_PCLKCR2_SHA_PCE_Pos)	//16	/* SHA����ʱ��ʹ�ܣ���ʹ�� */
#define	CICCLK			(0x02000000 + CMU_PCLKCR2_CIC_PCE_Pos)	//8	  /* CIC����ʱ��ʹ�ܣ���ʹ�� */
#define	WWDTCLK			(0x02000000 + CMU_PCLKCR2_WWDT_PCE_Pos)	//7	/* WWDTʱ��ʹ�ܣ���ʹ�� */
#define	RAMBISTCLK	    (0x02000000 + CMU_PCLKCR2_RAMBIST_PCE_Pos)	//6	/* RAMBISTʱ��ʹ�ܣ���ʹ�� */
#define	FLASHCLK		(0x02000000 + CMU_PCLKCR2_NVM_PCE_Pos)	//5	/* FLSC��Flash��д��������ʱ��ʹ�ܣ���ʹ�� */
#define	DMACLK			(0x02000000 + CMU_PCLKCR2_DMA_PCE_Pos)	//4	/* DMAʱ��ʹ�ܣ���ʹ�� */
#define	LCDCLK			(0x02000000 + CMU_PCLKCR2_LCD_PCE_Pos)	//3	/* LCDʱ��ʹ�ܣ���ʹ�� */
#define	AESCLK			(0x02000000 + CMU_PCLKCR2_AES_PCE_Pos)	//2	/* AESʱ��ʹ�ܣ���ʹ�� */
#define	TRNGCLK			(0x02000000 + CMU_PCLKCR2_TRNG_PCE_Pos)	//1	/* RNGʱ��ʹ�ܣ���ʹ�� */
#define	CRCCLK			(0x02000000 + CMU_PCLKCR2_CRC_PCE_Pos)	//0	/* CRCʱ��ʹ�ܣ���ʹ�� */

#define	I2C1CLK			(0x03000000 + CMU_PCLKCR3_I2C1_PCE_Pos)	//25	/* I2C1ʱ��ʹ�� */
#define	I2C0CLK			(0x03000000 + CMU_PCLKCR3_I2C0_PCE_Pos)	//24	/* I2C0ʱ��ʹ�� */
#define	LPUART1CLK	    (0x03000000 + CMU_PCLKCR3_LPUART1_PCE_Pos)	//18	/* LPUART1����ʱ��ʹ�� */
#define	U7816CLK		(0x03000000 + CMU_PCLKCR3_U7816_PCE_Pos)	//16	/* U7816-0ʱ��ʹ�� */
#define	LPUART0CLK	    (0x03000000 + CMU_PCLKCR3_LPUART0_PCE_Pos)	//15	/* LPUART0�Ĵ�������ʱ��ʹ�� */
#define	UARTIRCLK	    (0x03000000 + CMU_PCLKCR3_UICR_PCE_Pos)	//14	/* UART��������ʹ�ܣ���ʹ��*/
#define	UART5CLK		(0x03000000 + CMU_PCLKCR3_UART5_PCE_Pos)	//13	/* UART5ʱ��ʹ�� */
#define	UART4CLK		(0x03000000 + CMU_PCLKCR3_UART4_PCE_Pos)	//12	/* UART4ʱ��ʹ�� */
#define	UART3CLK		(0x03000000 + CMU_PCLKCR3_UART3_PCE_Pos)	//11	/* UART3ʱ��ʹ�� */
#define	UART2CLK		(0x03000000 + CMU_PCLKCR3_UART2_PCE_Pos)	//10	/* UART2ʱ��ʹ�� */
#define	UART1CLK		(0x03000000 + CMU_PCLKCR3_UART1_PCE_Pos)	//9	/* UART1ʱ��ʹ�� */
#define	UART0CLK		(0x03000000 + CMU_PCLKCR3_UART0_PCE_Pos)	//8	/* UART0ʱ��ʹ�� */
#define	QSPICLK			(0x03000000 + CMU_PCLKCR3_QSPI_PCE_Pos)	//7	/* QSPI����ʱ��ʹ�� */
#define	SPI4CLK			(0x03000000 + CMU_PCLKCR3_SPI4_PCE_Pos)	//4	/* SPI4ʱ��ʹ�� */
#define	SPI3CLK			(0x03000000 + CMU_PCLKCR3_SPI3_PCE_Pos)	//3	/* SPI3ʱ��ʹ�� */
#define	SPI2CLK			(0x03000000 + CMU_PCLKCR3_SPI2_PCE_Pos)	//2	/* SPI2ʱ��ʹ�� */
#define	SPI1CLK			(0x03000000 + CMU_PCLKCR3_SPI1_PCE_Pos)	//1	/* SPI1ʱ��ʹ�� */
#define	SPI0CLK			(0x03000000 + CMU_PCLKCR3_SPI0_PCE_Pos)	//0	/* SPI0ʱ��ʹ�� */


#define	ET4CLK			(0x04000000 + CMU_PCLKCR4_ET4_PCE_Pos)	//6	/* Etimer4ʱ��ʹ�ܣ���ʹ�� */
#define	ET3CLK			(0x04000000 + CMU_PCLKCR4_ET3_PCE_Pos)	//5	/* Etimer3ʱ��ʹ�ܣ���ʹ�� */
#define	ET2CLK			(0x04000000 + CMU_PCLKCR4_ET2_PCE_Pos)	//4	/* Etimer2ʱ��ʹ�ܣ���ʹ�� */
#define	ET1CLK			(0x04000000 + CMU_PCLKCR4_ET1_PCE_Pos)	//3	/* Etimer1ʱ��ʹ�ܣ���ʹ�� */
#define	BT2CLK			(0x04000000 + CMU_PCLKCR4_BT2_PCE_Pos)	//2	/* BaseTimer2ʱ��ʹ�ܣ���ʹ�� */
#define	BT1CLK			(0x04000000 + CMU_PCLKCR4_BT1_PCE_Pos)	//1	/* BaseTimer1ʱ��ʹ�ܣ���ʹ�� */
#define	BSTIMCLK	    (0x04000000 + CMU_PCLKCR4_BSTIM_PCE_Pos)	//0	/* ������ʱ��BSTIM����ʱ��ʹ�ܣ���ʹ�� */

/* ����ʱ��ʹ�ܺ��� */
extern void CMU_PERCLK_SetableEx(uint32_t periph_def, FunState NewState);
#ifdef __cplusplus
}
#endif

#endif /* __FM33A0XXEV_CMU_H */
