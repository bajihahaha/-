/**
  ******************************************************************************
  * @file    fm33a0xxev_gpio.h
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file contains all the functions prototypes for the GPIO firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33A0XXEV_GPIO_H
#define __FM33A0XXEV_GPIO_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33A0XXEV.h" 

//------------------------------------------------------------------------------
typedef enum
{ 
    GPIO_FCR_IN		= 0x00, /*!< GPIO ���� */
    GPIO_FCR_OUT	= 0x01, /*!< GPIO ��� */
    GPIO_FCR_DIG	= 0x02, /*!< GPIO �������⹦�� */
    GPIO_FCR_ANA	= 0x03  /*!< GPIO ģ�⹦�� */
}GPIO_FCR_TypeDef;

/** 
  * @brief  GPIO Output type enumeration 
  */  
typedef enum
{ 
    GPIO_OD_Dis = 0x00,
    GPIO_OD_En = 0x01
}GPIO_ODEN_TypeDef;

/** 
  * @brief  GPIO Configuration PullUp enumeration 
  */ 
typedef enum
{ 
    GPIO_PU_Dis = 0x00,
    GPIO_PU_En  = 0x01 
}GPIO_PUEN_TypeDef;

/** 
  * @brief  GPIO Configuration InEn enumeration 
  */ 
typedef enum
{ 
    GPIO_IN_Dis		= 0x00,
    GPIO_IN_En		= 0x01 
}GPIO_INEN_TypeDef;

/** 
  * @brief  GPIO Configuration HighDrive enumeration 
  */ 
typedef enum
{ 
    GPIO_HD_Dis		= 0x00,
    GPIO_HD_En		= 0x01 
}GPIO_HD_TypeDef;

/** 
  * @brief  GPIO Configuration AnalogChannel enumeration 
  */ 
typedef enum
{ 
    GPIO_ANEN_Dis		= 0x00,
    GPIO_ANEN_En		= 0x01 
}GPIO_ANEN_TypeDef;

/** 
  * @brief   GPIO Init structure definition  
  */ 
typedef struct
{
    uint32_t					Pin;     	//PINѡ��
    GPIO_FCR_TypeDef			PxFCR;		//IO����ѡ��
    GPIO_ODEN_TypeDef			PxODEN;		//��©���ʹ�ܿ���
    GPIO_PUEN_TypeDef			PxPUEN;		//��������ʹ�ܿ���
    GPIO_INEN_TypeDef			PxINEN;		//����ʹ�ܿ���
}GPIO_InitTypeDef;

/** 
  * @brief  GPIO Bit SET and Bit RESET enumeration 
  */ 
typedef enum
{ 
    Bit_RESET = 0,
    Bit_SET
}BitAction;
#define IS_GPIO_BIT_ACTION(ACTION) (((ACTION) == Bit_RESET) || ((ACTION) == Bit_SET))

typedef enum
{ 
    EXTI_RISING,
    EXTI_FALLING,
    EXTI_BOTH,
    EXTIDISABLE,
}GPIOExtiEdge;
#define IS_GPIO_INTERRUPT_TRIGER_EDGE(EDGE) (((EDGE) == EXTI_RISING) || ((EDGE) == EXTI_FALLING)|| ((EDGE) == EXTI_BOTH)|| ((EDGE) == EXTIDISABLE))


/* Exported constants --------------------------------------------------------*/

/** @defgroup GPIO_Exported_Constants
  * @{
  */
	 
/**
* @}
*/ 

/** @defgroup GPIO_Exported_Types
  * @{
  */

#define IS_GPIO_ALL_PERIPH(PERIPH) (((PERIPH) == GPIOA) || \
                                    ((PERIPH) == GPIOB) || \
                                    ((PERIPH) == GPIOC) || \
                                    ((PERIPH) == GPIOD)	|| \
                                    ((PERIPH) == GPIOE)	|| \
                                    ((PERIPH) == GPIOF)	|| \
                                    ((PERIPH) == GPIOG))
    
#define IS_GPIO_HD_PERIPH(PERIPH)  ((PERIPH) == GPIOH)	
/** @defgroup GPIO_pins_define 
  * @{
  */ 
#define GPIO_Pin_0                 ((uint32_t)0x00000001)  /* Pin 0 selected */
#define GPIO_Pin_1                 ((uint32_t)0x00000002)  /* Pin 1 selected */
#define GPIO_Pin_2                 ((uint32_t)0x00000004)  /* Pin 2 selected */
#define GPIO_Pin_3                 ((uint32_t)0x00000008)  /* Pin 3 selected */
#define GPIO_Pin_4                 ((uint32_t)0x00000010)  /* Pin 4 selected */
#define GPIO_Pin_5                 ((uint32_t)0x00000020)  /* Pin 5 selected */
#define GPIO_Pin_6                 ((uint32_t)0x00000040)  /* Pin 6 selected */
#define GPIO_Pin_7                 ((uint32_t)0x00000080)  /* Pin 7 selected */
#define GPIO_Pin_8                 ((uint32_t)0x00000100)  /* Pin 8 selected */
#define GPIO_Pin_9                 ((uint32_t)0x00000200)  /* Pin 9 selected */
#define GPIO_Pin_10                ((uint32_t)0x00000400)  /* Pin 10 selected */
#define GPIO_Pin_11                ((uint32_t)0x00000800)  /* Pin 11 selected */
#define GPIO_Pin_12                ((uint32_t)0x00001000)  /* Pin 12 selected */
#define GPIO_Pin_13                ((uint32_t)0x00002000)  /* Pin 13 selected */
#define GPIO_Pin_14                ((uint32_t)0x00004000)  /* Pin 14 selected */
#define GPIO_Pin_15                ((uint32_t)0x00008000)  /* Pin 15 selected */
#define GPIO_Pin_All               ((uint16_t)0xFFFF)  /*!< All pins selected */

#define IS_GPIO_PIN(PIN) ((((PIN) & (uint16_t)0x00) == 0x00) && ((PIN) != (uint16_t)0x00))
#define IS_GET_GPIO_PIN(PIN) (((PIN) == GPIO_Pin_0) || \
                              ((PIN) == GPIO_Pin_1) || \
                              ((PIN) == GPIO_Pin_2) || \
                              ((PIN) == GPIO_Pin_3) || \
                              ((PIN) == GPIO_Pin_4) || \
                              ((PIN) == GPIO_Pin_5) || \
                              ((PIN) == GPIO_Pin_6) || \
                              ((PIN) == GPIO_Pin_7) || \
                              ((PIN) == GPIO_Pin_8) || \
                              ((PIN) == GPIO_Pin_9) || \
                              ((PIN) == GPIO_Pin_10) || \
                              ((PIN) == GPIO_Pin_11) || \
                              ((PIN) == GPIO_Pin_12) || \
                              ((PIN) == GPIO_Pin_13) || \
                              ((PIN) == GPIO_Pin_14) || \
                              ((PIN) == GPIO_Pin_15))



#define IS_GET_GPIOH_PIN(PIN) (((PIN) == GPIO_Pin_0) || \
                              ((PIN) == GPIO_Pin_1) || \
                              ((PIN) == GPIO_Pin_2) || \
                              ((PIN) == GPIO_Pin_3))
/* Exported macro ------------------------------------------------------------*/


/* WKUP����ʹ��PIN�궨�� */
#define		PINWKEN_PD6	    7
#define		PINWKEN_PE9	    6
#define		PINWKEN_PE2	    5
#define		PINWKEN_PA13 	4
#define		PINWKEN_PG7	    3
#define		PINWKEN_PC13    2
#define		PINWKEN_PB0	    1
#define		PINWKEN_PF5	    0

// 1. PortX����ʹ�ܼĴ���
#define	GPIOx_INEN_INEN_Pos	0	//R/W: rw	ResetValue: 0x0
#define	GPIOx_INEN_INEN_Msk	(0xffffU << GPIOx_INEN_INEN_Pos)
								//GPIO����ʹ�ܿ���
								//0���ر�����ʹ��
								//1��������ʹ��

// 2. PortX����ʹ�ܼĴ���
#define	GPIOx_PUEN_PUEN_Pos	0	//R/W: rw	ResetValue: 0x0
#define	GPIOx_PUEN_PUEN_Msk	(0xffffU << GPIOx_PUEN_PUEN_Pos)								
								//GPIO��������
								//0���ر�����
								//1��ʹ������	

// 3. PortX��©ʹ�ܼĴ���								
#define	GPIOx_ODEN_ODEN_Pos	0	//R/W: rw	ResetValue: 0x0
#define	GPIOx_ODEN_ODEN_Msk	(0xffffU << GPIOx_ODEN_ODEN_Pos)
								//GPIO��©���ʹ��
								//0���رտ�©���
								//1��ʹ�ܿ�©���

// 4. PortX����ѡ��Ĵ���								
#define	GPIOx_FCR_Px15FCR_Pos	30	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px15FCR_Msk	(0x03U << GPIOx_FCR_Px15FCR_Pos)
								//Px[15]���Ź���ѡ��
								//00��GPIO����
								//01��GPIO���
								//10��Digital function
								//11��Analog function								
#define	GPIOx_FCR_Px14FCR_Pos	28	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px14FCR_Msk	(0x03U << GPIOx_FCR_Px14FCR_Pos)
								//Px[14]���Ź���ѡ��
								//00��GPIO����
								//01��GPIO���
								//10��Digital function
								//11��Analog function
#define	GPIOx_FCR_Px13FCR_Pos	26	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px13FCR_Msk	(0x03U << GPIOx_FCR_Px13FCR_Pos)
								//Px[13]���Ź���ѡ��
								//00��GPIO����
								//01��GPIO���
								//10��Digital function
								//11��Analog function
#define	GPIOx_FCR_Px12FCR_Pos	24	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px12FCR_Msk	(0x03U << GPIOx_FCR_Px12FCR_Pos)
								//Px[12]���Ź���ѡ��
								//00��GPIO����
								//01��GPIO���
								//10��Digital function
								//11��Analog function
#define	GPIOx_FCR_Px11FCR_Pos	22	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px11FCR_Msk	(0x03U << GPIOx_FCR_Px11FCR_Pos)
								//Px[11]���Ź���ѡ��
								//00��GPIO����
								//01��GPIO���
								//10��Digital function
								//11��Analog function
#define	GPIOx_FCR_Px10FCR_Pos	20	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px10FCR_Msk	(0x03U << GPIOx_FCR_Px10FCR_Pos)
								//Px[10]���Ź���ѡ��
								//00��GPIO����
								//01��GPIO���
								//10��Digital function
								//10��Analog function
#define	GPIOx_FCR_Px9FCR_Pos	18	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px9FCR_Msk	(0x03U << GPIOx_FCR_Px9FCR_Pos)
								//Px[9]���Ź���ѡ��
								//00��GPIO����
								//01��GPIO���
								//10��Digital function
								//11��Analog function	
#define	GPIOx_FCR_Px8FCR_Pos	16	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px8FCR_Msk	(0x03U << GPIOx_FCR_Px8FCR_Pos)
								//Px[8]���Ź���ѡ��
								//00��GPIO����
								//01��GPIO���
								//10��Digital function
								//11��Analog function
#define	GPIOx_FCR_Px7FCR_Pos	14	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px7FCR_Msk	(0x03U << GPIOx_FCR_Px7FCR_Pos)
								//Px[7]���Ź���ѡ��
								//00��GPIO����
								//01��GPIO���
								//10��Digital function
								//11��Analog function
#define	GPIOx_FCR_Px6FCR_Pos	12	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px6FCR_Msk	(0x03U << GPIOx_FCR_Px6FCR_Pos)
								//Px[6]���Ź���ѡ��
								//00��GPIO����
								//01��GPIO���
								//10��Digital function
								//11��Analog function
#define	GPIOx_FCR_Px5FCR_Pos	10	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px5FCR_Msk	(0x03U << GPIOx_FCR_Px5FCR_Pos)
								//Px[5]���Ź���ѡ��
								//00��GPIO����
								//01��GPIO���
								//10��Digital function
								//11��Analog function
#define	GPIOx_FCR_Px4FCR_Pos	8	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px4FCR_Msk	(0x03U << GPIOx_FCR_Px4FCR_Pos)
								//Px[4]���Ź���ѡ��
								//00��GPIO����
								//01��GPIO���
								//10��Digital function
								//11��Analog function
#define	GPIOx_FCR_Px3FCR_Pos	6	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px3FCR_Msk	(0x03U << GPIOx_FCR_Px3FCR_Pos)
								//Px[3]���Ź���ѡ��
								//00��GPIO����
								//01��GPIO���
								//10��Digital function
								//11��Analog function
#define	GPIOx_FCR_Px2FCR_Pos	4	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px2FCR_Msk	(0x03U << GPIOx_FCR_Px2FCR_Pos)
								//Px[2]���Ź���ѡ��
								//00��GPIO����
								//01��GPIO���
								//10��Digital function
								//11��Analog function
#define	GPIOx_FCR_Px1FCR_Pos	2	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px1FCR_Msk	(0x03U << GPIOx_FCR_Px1FCR_Pos)
								//Px[1]���Ź���ѡ��
								//00��GPIO����
								//01��GPIO���
								//10��Digital function
								//11��Analog function
#define	GPIOx_FCR_Px0FCR_Pos	0	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px0FCR_Msk	(0x03U << GPIOx_FCR_Px0FCR_Pos)
								//Px[0]���Ź���ѡ��
								//00��GPIO����
								//01��GPIO���
								//10��Digital function
								//11��Analog function	

// 5. PortX������ݼĴ���																						
#define	GPIOx_DO_DO_Pos	0	//R/W: rw	ResetValue: 0x0
#define	GPIOx_DO_DO_Msk	(0xffffU << GPIOx_DO_DO_Pos)
								//GPIO output data register

// 6. PortX���������λ�Ĵ���								
#define	GPIOx_DSET_DSET_Pos	0	//R/W: rw	ResetValue: 0x0
#define	GPIOx_DSET_DSET_Msk	(0xffffU << GPIOx_DSET_DSET_Pos)
								//GPIO output data set register
								//��������PADSETд0x0000_8000����PADOR[15]��λ������λ���ֲ��䡣
								//PASET/PBSETΪ16λ��PCSET/PDSETΪ13λ

// 7. PortX������ݸ�λ�Ĵ���								
#define	GPIOx_DRST_DRESET_Pos	0	//R/W: rw	ResetValue: 0x0
#define	GPIOx_DRST_DRESET_Msk	(0xffffU << GPIOx_DRST_DRESET_Pos)
								//GPIO output data reset register
								//��������PADRSTд0x0000_8000����PADOR[15]���㣬����λ���ֲ���
								//PASET/PBSETΪ16λ��PCSET/PDSETΪ13λ

// 8. PortX�������ݼĴ���																																															
#define	GPIOx_DIN_DIN_Pos	0	//R/W: rw	ResetValue: 0x0
#define	GPIOx_DIN_DIN_Msk	(0xffffU << GPIOx_DIN_DIN_Pos)
								//Portx input data register
								//�˼Ĵ�����ռ�õ�ַ�ռ䣬������ʵ�֡�
								//������˼Ĵ���ֱ�ӷ������������źţ�оƬ���������������������

// 9. PortX�������ֹ��ܼĴ���								
#define	GPIOx_DFS_DFS_Pos	0	//R/W: rw	ResetValue: 0x0
#define	GPIOx_DFS_DFS_Msk	(0xffffU << GPIOx_DFS_DFS_Pos)
								//Portx Digital Function Select
								//���ھ��ж���������蹦�ܵ����ţ�ͨ��PxDFS�Ĵ�������ѡ��ʹ���ĸ����蹦�ܡ�
								//ע�⣬���ڲ�ͬ��IO���飬��Ч�ļĴ���λ���ǲ�һ����

// 11. PortXģ�⿪��ʹ�ܼĴ���								
#define	GPIOx_ANEN_ANEN_Pos	0	//R/W: rw	ResetValue: 0x0
#define	GPIOx_ANEN_ANEN_Msk	(0xffffU << GPIOx_ANEN_ANEN_Pos)
								//PortX ģ�⿪��ʹ��
								//1��ʹ��IOģ�⿪��
								//0���ر�IOģ�⿪��
								//ע��֧��ģ�⿪�ص�IO��
								//PA6/PA7/PA13/PA14/PA15
								//PB0/PB1/PB13/PB14/PB15
								//PC0/PC1/PC6/PC7/PC8/PC9/PC10
								//PD0/PD1/PD2/PD11/PD12
								//��Ӧ����IO��PxANEN�Ĵ�����Ч������Ĵ��������塣


#define	GPIO_FOUTSEL_FOUT1SEL_Pos	8	/* FOUT���Ƶ��ѡ���ź� */
#define	GPIO_FOUTSEL_FOUT1SEL_Msk	(0x1fU << GPIO_FOUTSEL_FOUT1SEL_Pos)
#define	GPIO_FOUTSEL_FOUT1SEL_XTLF	(0x0U << GPIO_FOUTSEL_FOUT1SEL_Pos)	/* 00000: XTLF */
#define	GPIO_FOUTSEL_FOUT1SEL_RCLP	(0x1U << GPIO_FOUTSEL_FOUT1SEL_Pos)	/* 00001: RCLP */
#define	GPIO_FOUTSEL_FOUT1SEL_RCHFD64	(0x2U << GPIO_FOUTSEL_FOUT1SEL_Pos)	/* 00010: RCHF/64 */
#define	GPIO_FOUTSEL_FOUT1SEL_LSCLK	(0x3U << GPIO_FOUTSEL_FOUT1SEL_Pos)	/* 00011: LSCLK */
#define	GPIO_FOUTSEL_FOUT1SEL_AHBCLKD64	(0x4U << GPIO_FOUTSEL_FOUT1SEL_Pos)	/* 00100: AHBCLK/64 */
#define	GPIO_FOUTSEL_FOUT1SEL_RTC_TM	(0x5U << GPIO_FOUTSEL_FOUT1SEL_Pos)	/* 00101: RTC_TM */
#define	GPIO_FOUTSEL_FOUT1SEL_PLLHD64	(0x6U << GPIO_FOUTSEL_FOUT1SEL_Pos)	/* 00110: PLL_H/64 */
#define	GPIO_FOUTSEL_FOUT1SEL_RTCCLK64Hz	(0x7U << GPIO_FOUTSEL_FOUT1SEL_Pos)	/* 00111: RTCCLK64Hz */
#define	GPIO_FOUTSEL_FOUT1SEL_APBCLKD64	(0x8U << GPIO_FOUTSEL_FOUT1SEL_Pos)	/* 01000: APBCLK/64 */
#define	GPIO_FOUTSEL_FOUT1SEL_PLL_L	(0x9U << GPIO_FOUTSEL_FOUT1SEL_Pos)	/* 01001: PLL_L */
#define	GPIO_FOUTSEL_FOUT1SEL_RCMF	(0xAU << GPIO_FOUTSEL_FOUT1SEL_Pos)	/* 01010: RCMF */
#define	GPIO_FOUTSEL_FOUT1SEL_RCHF	(0xBU << GPIO_FOUTSEL_FOUT1SEL_Pos)	/* 01011: RCHF */
#define	GPIO_FOUTSEL_FOUT1SEL_XTHFD64	(0xCU << GPIO_FOUTSEL_FOUT1SEL_Pos)	/* 01100: XTHF/64 */
#define	GPIO_FOUTSEL_FOUT1SEL_ADCCLK	(0xDU << GPIO_FOUTSEL_FOUT1SEL_Pos)	/* 01101: ADCCLK */
#define	GPIO_FOUTSEL_FOUT1SEL_PLL_H	(0xEU << GPIO_FOUTSEL_FOUT1SEL_Pos)	/* 01110: PLL_H */
#define	GPIO_FOUTSEL_FOUT1SEL_BOOST_FLAG	(0x10U << GPIO_FOUTSEL_FOUT1SEL_Pos)	/* 10000: Boost Flag */
#define	GPIO_FOUTSEL_FOUT1SEL_AUTOTRIM_OUTPUT	(0x11U << GPIO_FOUTSEL_FOUT1SEL_Pos)	/* 10001: Autotrim output */


#define	GPIO_FOUTSEL_FOUT0SEL_Pos	0	/* FOUT���Ƶ��ѡ���ź� */
#define	GPIO_FOUTSEL_FOUT0SEL_Msk	(0x1fU << GPIO_FOUTSEL_FOUT0SEL_Pos)
#define	GPIO_FOUTSEL_FOUT0SEL_XTLF	(0x0U << GPIO_FOUTSEL_FOUT0SEL_Pos)	/* 00000: XTLF */
#define	GPIO_FOUTSEL_FOUT0SEL_RCLP	(0x1U << GPIO_FOUTSEL_FOUT0SEL_Pos)	/* 00001: RCLP */
#define	GPIO_FOUTSEL_FOUT0SEL_RCHFD64	(0x2U << GPIO_FOUTSEL_FOUT0SEL_Pos)	/* 00010: RCHF/64 */
#define	GPIO_FOUTSEL_FOUT0SEL_LSCLK	(0x3U << GPIO_FOUTSEL_FOUT0SEL_Pos)	/* 00011: LSCLK */
#define	GPIO_FOUTSEL_FOUT0SEL_AHBCLKD64	(0x4U << GPIO_FOUTSEL_FOUT0SEL_Pos)	/* 00100: AHBCLK/64 */
#define	GPIO_FOUTSEL_FOUT0SEL_RTC_TM	(0x5U << GPIO_FOUTSEL_FOUT0SEL_Pos)	/* 00101: RTC_TM */
#define	GPIO_FOUTSEL_FOUT0SEL_PLLHD64	(0x6U << GPIO_FOUTSEL_FOUT0SEL_Pos)	/* 00110: PLL_H/64 */
#define	GPIO_FOUTSEL_FOUT0SEL_RTCCLK64Hz	(0x7U << GPIO_FOUTSEL_FOUT0SEL_Pos)	/* 00111: RTCCLK64Hz */
#define	GPIO_FOUTSEL_FOUT0SEL_APBCLKD64	(0x8U << GPIO_FOUTSEL_FOUT0SEL_Pos)	/* 01000: APBCLK/64 */
#define	GPIO_FOUTSEL_FOUT0SEL_PLL_L	(0x9U << GPIO_FOUTSEL_FOUT0SEL_Pos)	/* 01001: PLL_L */
#define	GPIO_FOUTSEL_FOUT0SEL_RCMF	(0xAU << GPIO_FOUTSEL_FOUT0SEL_Pos)	/* 01010: RCMF */
#define	GPIO_FOUTSEL_FOUT0SEL_RCHF	(0xBU << GPIO_FOUTSEL_FOUT0SEL_Pos)	/* 01011: RCHF */
#define	GPIO_FOUTSEL_FOUT0SEL_XTHFD64	(0xCU << GPIO_FOUTSEL_FOUT0SEL_Pos)	/* 01100: XTHF/64 */
#define	GPIO_FOUTSEL_FOUT0SEL_ADCCLK	(0xDU << GPIO_FOUTSEL_FOUT0SEL_Pos)	/* 01101: ADCCLK */
#define	GPIO_FOUTSEL_FOUT0SEL_PLL_H	(0xEU << GPIO_FOUTSEL_FOUT0SEL_Pos)	/* 01110: PLL_H */
#define	GPIO_FOUTSEL_FOUT0SEL_BOOST_FLAG	(0x10U << GPIO_FOUTSEL_FOUT0SEL_Pos)	/* 10000: Boost Flag */

#define	GPIO_IOMCR_IOMUXSEL_Pos 1
#define	GPIO_IOMCR_IOMUXSEL_Msk	(0x3U << GPIO_IOMCR_IOMUXSEL_Pos)
#define	GPIO_IOMCR_IOMUXSEL_PD6	(0x0U << GPIO_IOMCR_IOMUXSEL_Pos)
#define	GPIO_IOMCR_IOMUXSEL_PD7	(0x1U << GPIO_IOMCR_IOMUXSEL_Pos)
#define	GPIO_IOMCR_IOMUXSEL_PG2	(0x2U << GPIO_IOMCR_IOMUXSEL_Pos)
#define	GPIO_IOMCR_IOMUXSEL_PG3	(0x3U << GPIO_IOMCR_IOMUXSEL_Pos)

#define	GPIO_IOMCR_IOMUXEN_Pos	0
#define	GPIO_IOMCR_IOMCUEN_Msk	(0x1U << GPIO_IOMCR_IOMUXEN_Pos)

#define	GPIO_PINWKEN_WKISEL_Pos	31	/* WKUP�ж����ѡ��Ĵ��� */
#define	GPIO_PINWKEN_WKISEL_Msk	(0x1U << GPIO_PINWKEN_WKISEL_Pos)
#define	GPIO_PINWKEN_WKISEL_NMI	(0x0U << GPIO_PINWKEN_WKISEL_Pos)   /* NMI�ж� */
#define	GPIO_PINWKEN_WKISEL_46	(0x1U << GPIO_PINWKEN_WKISEL_Pos)   /* #46�ж� */

#define	GPIO_PINWKEN_PINWKSEL_Pos	8	/* WKUP����ѡ��Ĵ���*/
#define	GPIO_PINWKEN_PINWKSEL_Msk	(0xffffU << GPIO_PINWKEN_PINWKSEL_Pos)
#define	GPIO_PINWKEN_PINWKSEL_FALLING   0   /* ��Ӧ��WKUP����Ϊ�½��ػ��� */
#define	GPIO_PINWKEN_PINWKSEL_RISING    1   /* ��Ӧ��WKUP����Ϊ�����ػ��� */
#define	GPIO_PINWKEN_PINWKSEL_BOTH      2   /* ��Ӧ��WKUP����Ϊ�������½��ػ��� */

#define	GPIO_PINWKEN_PINWKEN_Pos	0	/* WKUP����ʹ�ܼĴ��� */
#define	GPIO_PINWKEN_PINWKEN_Msk	(0xffU << GPIO_PINWKEN_PINWKEN_Pos)


//PortH������ݼĴ���																						
#define	GPIOH_DO_PHDO_Pos	0	
#define	GPIOH_DO_PHDO_Msk	(0xfU << GPIOH_DO_PHDO_Pos)

//PortH�������ݼĴ���																						
#define	GPIOH_DIN_PHDIN_Pos	0	
#define	GPIOH_DIN_PHDIN_Msk	(0xfU << GPIOH_DIN_PHDIN_Pos)
								//GPIO output data register
/* Exported functions --------------------------------------------------------*/ 

/* PortX������ݼĴ��� ��غ��� */
extern void GPIOx_DO_Write(GPIO_Type* GPIOx, uint32_t SetValue);
extern uint32_t GPIOx_DO_Read(GPIO_Type* GPIOx);

/* PortX���������λ�Ĵ��� ��غ��� */
extern void GPIOx_DSET_Write(GPIO_Type* GPIOx, uint32_t SetValue);

/* PortX������ݸ�λ�Ĵ��� ��غ��� */
extern void GPIOx_DRST_Write(GPIO_Type* GPIOx, uint32_t SetValue);

/* PortX�������ݼĴ��� ��غ��� */
extern uint32_t GPIOx_DIN_Read(GPIO_Type* GPIOx);

/* PortX�������ֹ��ܼĴ��� ��غ��� */
extern void GPIOx_DFS_Setable(GPIO_Type* GPIOx, uint32_t GPIO_Pin, FunState NewState);
extern FunState GPIOx_DFS_Getable(GPIO_Type* GPIOx, uint32_t GPIO_Pin);

/* PortXģ�⿪��ʹ�ܼĴ��� ��غ��� */
extern void GPIOx_ANEN_Setable(GPIO_Type* GPIOx, uint32_t GPIO_Pin, FunState NewState);
extern FunState GPIOx_ANEN_Getable(GPIO_Type* GPIOx, uint32_t GPIO_Pin);

/* GPIO ��ʼ������ */
extern void GPIO_Init(GPIO_Type* GPIOx, GPIO_InitTypeDef* para);

/* ��ȡһ��IO�ڵ����ò����ṹ�� 
	ע��һ��ֻ�ܶ�ȡһ��IO������*/
extern void GPIO_Get_InitPara(GPIO_Type* GPIOx, uint32_t GPIO_Pin, GPIO_InitTypeDef* para);

/* ��ȡGPIOx�������ݼĴ��� */
extern uint32_t GPIO_ReadInputData(GPIO_Type* GPIOx);

/* ��ȡGPIOx�������ݼĴ���bit */
extern uint8_t GPIO_ReadInputDataBit(GPIO_Type* GPIOx, uint32_t GPIO_Pin);

/* GPIOx���������1 */
extern void GPIO_SetBits(GPIO_Type* GPIOx, uint32_t GPIO_Pin);

/* GPIOx���������0 */
extern void GPIO_ResetBits(GPIO_Type* GPIOx, uint32_t GPIO_Pin);

/* GPIOx��������÷�ת */
extern void GPIO_ToggleBits(GPIO_Type* GPIOx, uint32_t GPIO_Pin);

/* GPIOH���������1 */
extern void GPIOH_SetBits(uint32_t GPIO_Pin);

/* GPIOH���������0 */
extern void GPIOH_ResetBits(uint32_t GPIO_Pin);

/* GPIOH��������÷�ת */
extern void GPIOH_ToggleBits(uint32_t GPIO_Pin);

/* ��ȡGPIOx������ݼĴ��� */
extern uint32_t GPIO_ReadOutputData(GPIO_Type* GPIOx);

/* ��ȡGPIOx������ݼĴ���bit */
extern uint8_t GPIO_ReadOutputDataBit(GPIO_Type* GPIOx, uint32_t GPIO_Pin);

/* �ⲿ����ѡ�� */
extern void GPIO_EXTI_Select_Pin(GPIO_Type* GPIOx,uint32_t GPIO_Pin);

/* �ⲿ�жϱ���ѡ�� */
extern void GPIO_EXTI_Select_Edge(GPIO_Type* GPIOx,uint32_t GPIO_Pin,GPIOExtiEdge edge_select);


/* EXTI�����˲����ƼĴ��� ��غ��� */
extern void GPIO_EXTI_EXTIDF_Setable(GPIO_Type* GPIOx, uint32_t GPIO_Pin, FunState NewState);

/* ��ȡEXTI�����źżĴ��� */
extern FunState GPIO_EXTI_EXTIDI_Getable(GPIO_Type* GPIOx, uint32_t GPIO_Pin);

/* ����жϱ�־ */
extern void GPIO_EXTI_EXTIISR_ClrEx(GPIO_Type* GPIOx,uint32_t GPIO_Pin);

/* ��ȡ�жϱ�־״̬ */
extern FlagStatus GPIO_EXTI_EXTIISR_ChkEx(GPIO_Type* GPIOx,uint32_t GPIO_Pin);

/* FOUT1������ú��� */
extern void GPIO_FOUTSEL_FOUT1SEL_Set(uint32_t SetValue);

/* ��FOUT1���״̬���� */
extern uint32_t GPIO_FOUTSEL_FOUT1SEL_Get(void);

/* FOUT0������ú��� */
extern void GPIO_FOUTSEL_FOUT0SEL_Set(uint32_t SetValue);

/* ��FOUT0���״̬���� */
extern uint32_t GPIO_FOUTSEL_FOUT0SEL_Get(void);

/* ����˵����GPIO_EXTI_Init �ⲿ�жϳ�ʼ�� */
extern void GPIO_EXTI_Init(GPIO_Type* GPIOx, uint32_t GPIO_Pin, GPIOExtiEdge edge_select, FunState DFState);

/* GPIO_EXTI_Close�ⲿ�жϹر� */
extern void GPIO_EXTI_Close(GPIO_Type* GPIOx,uint32_t GPIO_Pin);

/* GPIOH��ʼ�����ú��� */
extern void GPIOH_Init(GPIO_InitTypeDef* para);

/* ��ȡһ��IO���ò����ṹ�庯�� */
extern void GPIOH_Get_InitPara(uint32_t GPIO_Pin, GPIO_InitTypeDef* para);

/* GPIOH������ݼĴ������ú��� */
extern void GPIOH_DO_Write(uint32_t SetValue);

/* ��ȡGPIOH����Ĵ��� */
extern uint32_t GPIOH_ReadOutputData(void);

/* ���ܽ�Pin��ȡ����Ĵ��� */
extern uint8_t GPIOH_ReadOutputDataBit(uint32_t GPIO_Pin);

/* ��ȡGPIOH����Ĵ��� */
extern uint32_t GPIOH_ReadInputData(void);

/* ���ܽ�Pin��ȡ����Ĵ��� */
extern uint8_t GPIOH_ReadInputDataBit(uint32_t GPIO_Pin);

/*����IO��ѡһ���*/
extern void GPIO_IOMCR_IOMUXSEL_Set(uint32_t SetValue);
	
/*��IOMCR��ѡһ����״̬*/
extern uint32_t GPIO_IOMCR_IOMUXSEL_Get(void);

/* GPIO ��ѡһʹ�� ���� */
extern void GPIO_IOMCR_Setable(FunState NewState);

/* GPIO ��ȡGPIO ��ѡһʹ�� ���� */
extern FunState GPIO_IOMCR_Getable(void);

extern void GPIO_PINWKEN_SetableEx(uint32_t NWKPinDef, FunState NewState);
extern FunState GPIO_PINWKEN_GetableEx(uint32_t NWKPinDef);
extern void GPIO_PINWKSEL_SetEx(uint32_t NWKPinDef, uint32_t SetValue);
extern uint32_t GPIO_PINWKSEL_GetEx(uint32_t NWKPinDef);
extern void GPIO_PINWKEN_WKISEL_Set(uint32_t SetValue);
extern uint32_t GPIO_PINWKEN_WKISEL_Get(void);
            
#ifdef __cplusplus
}
#endif

#endif /* __FM33A0XXEV_GPIO_H */
