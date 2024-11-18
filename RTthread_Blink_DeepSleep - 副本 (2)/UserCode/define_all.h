#ifndef	__DEFINEALL_H__
#define __DEFINEALL_H__

//定义常量, 常数

//系统时钟默认使用RCHF
#define RCHFCLKCFG	8	//8, 16, 24,32MHZ

//define_all.h中RCHFCLKCFG控制系统时钟
#if( RCHFCLKCFG == 8 )//8.0MHz
#define clkmode   1
#define SYSCLKdef CMU_RCHFCR_FSEL_8MHZ//RCHF中心频率8MHz 
#elif( RCHFCLKCFG == 16 )//16.0MHz
#define clkmode   2
#define SYSCLKdef CMU_RCHFCR_FSEL_16MHZ//RCHF中心频率16MHz
#elif( RCHFCLKCFG == 24 )//24.0MHz
#define clkmode   3
#define SYSCLKdef CMU_RCHFCR_FSEL_24MHZ//RCHF中心频率24MHz
#elif( RCHFCLKCFG == 32 )//32.0MHz
#define clkmode   4
#define SYSCLKdef CMU_RCHFCR_FSEL_32MHZ//RCHF中心频率32MHz
#elif( RCHFCLKCFG == 40 )//40.0MHz
#define clkmode   5
#define SYSCLKdef CMU_RCHFCR_FSEL_40MHZ//RCHF中心频率40MHz
#elif( RCHFCLKCFG == 48 )//48.0MHz
#define clkmode   6
#define SYSCLKdef CMU_RCHFCR_FSEL_48MHZ//RCHF中心频率48MHz
#endif
 
/*变量类型定义*/
typedef union
{
  unsigned char B08;
  struct
  {
    unsigned char bit0:1;
    unsigned char bit1:1;
    unsigned char bit2:1;
    unsigned char bit3:1;
    unsigned char bit4:1;
    unsigned char bit5:1;
    unsigned char bit6:1;
    unsigned char bit7:1;
  }Bit;
}B08_Bit;

#define	uint08 uint8_t
#define	uint16 uint16_t
#define uint32 uint32_t
#define	int08 int8_t		
#define	int16 int16_t
#define	int32 int32_t

/*功能IO宏定义*/
#define LED0_GPIO		GPIOC
#define LED0_PIN		GPIO_Pin_12

/*操作宏定义*/
#define LED0_ON			GPIO_ResetBits(LED0_GPIO, LED0_PIN)
#define LED0_OFF		GPIO_SetBits(LED0_GPIO, LED0_PIN)
#define LED0_TOG		GPIO_ToggleBits(LED0_GPIO, LED0_PIN)


/* GPIO配置函数参数宏定义 */
//IO输入口配置 
//type 0 = 普通 
//type 1 = 上拉
#define IN_NORMAL	0
#define IN_PULLUP	1

#define BUFFER_SIZE  512

//IO输出口配置 
//type 0 = 普通 
//type 1 = OD
#define OUT_PUSHPULL	0
#define OUT_OPENDRAIN	1

//IO数字特殊功能口 
//type 0 = 普通 
//type 1 = OD (OD功能仅部分特殊功能支持)
//type 2 = 普通+上拉 
//type 3 = OD+上拉
#define ALTFUN_NORMAL			0
#define ALTFUN_OPENDRAIN		1
#define ALTFUN_PULLUP			2
#define ALTFUN_OPENDRAIN_PULLUP	3


#define GP_TEST_GPIO      GPIOB
#define GP_TEST_PIN       GPIO_Pin_2 	

#define PULSE_GPIO        GPIOA
#define PULSE_PIN         GPIO_Pin_11

#define FLASH_CS1_GPIO    GPIOA
#define FLASH_CS1_PIN 		GPIO_Pin_0
#define FLASH_CON_GPIO    GPIOF
#define FLASH_CON_PIN     GPIO_Pin_8

#define BAT_CON_GPIO 			GPIOE
#define BAT_CON_PIN  			GPIO_Pin_5

#define SPC_CON_GPIO 			GPIOE
#define SPC_CON_PIN  			GPIO_Pin_8

#define GP_CON_GPIO       GPIOD
#define GP_CON_PIN        GPIO_Pin_7

#define LED_GREEN_GPIO    GPIOF
#define LED_GREEN_PIN     GPIO_Pin_6

#define LED_RED_GPIO      GPIOF
#define LED_RED_PIN       GPIO_Pin_5

#define SPC_EN_GPIO GPIOF
#define SPC_EN_PIN  GPIO_Pin_12






/*include*/
#include "FM33A0XXEV.h"
#include "fm33a0xxev_include_all.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "bintohex.h"
#include "user_init.h"

typedef enum{
    CPIN=1,
    CREG,
    CEREG,
    CSGP,
    CSQ,
    ACT,
    OPEN,
		CLOSE,
		DEACT,
		CCID,
}error_num;

#define DTU_ADDR 0x03

#define PROTOCOL 1


#endif



