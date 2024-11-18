#include "define_all.h"  
#include "rtc.h"
#include "spi.h"
#include "uart.h"
#define RCLP_TRIM (uint8_t)(*(uint32_t *)0X1FFFFB20UL)
//cpu滴答定时器配置(软件延时用)
void Init_SysTick(void)
{
    CMU->SYSCLKCR &= 0xFFFFFF3F; //systick工作时钟选择SCLK
    SysTick_Config(0x1000000UL);
    SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |//关闭中断
                    //SysTick_CTRL_TICKINT_Msk |
                    SysTick_CTRL_ENABLE_Msk;
}
//调用软件延时前必须先配置SysTick
void TicksDelay(uint32_t ClkNum)
{
    uint32_t last = SysTick->VAL;
    
    ClkNum = ClkNum*clkmode;//适应不同主频，8M时最大定时2ms，32M时最大定时0.5ms
    if(ClkNum>0xF00000)
    {
        ClkNum = 0xF00000;
    }
    while(((last - SysTick->VAL)&0xFFFFFFUL ) < ClkNum);
} 
//ms软件延时
void TicksDelayMs(uint32_t ms , ConditionHook Hook)
{
    uint32_t ClkNum;
    
    ClkNum = (__SYSTEM_CLOCK/1000) ;
    for(;ms>0;ms--)
    {
        if(Hook!=NULL)
        {
            if(Hook()) return ;
        }
        TicksDelay(ClkNum);
    }
}
//us软件延时
void TicksDelayUs(uint32_t us)
{
    uint32_t ClkNum;
    
    if(us>100000)//不大于100ms
    {
        us = 100000;
    }
    ClkNum = us*(__SYSTEM_CLOCK/1000000) ;
    TicksDelay(ClkNum);
}

//校验寄存器
unsigned char CheckSysReg( __IO uint32_t *RegAddr, uint32_t Value )
{
	if( *RegAddr != Value ) 
	{
		*RegAddr = Value;
		return 1;
	}
	else
	{
		return 0;
	}
}

//查询NVIC寄存器对应向量号中断是否打开
//1 打开
//0 关闭
unsigned char CheckNvicIrqEn( IRQn_Type IRQn )
{
	if( 0 == ( NVIC->ISER[0U] & ((uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL)))) )
		return 0;
	else
		return 1;
}

//GPIOA~G  模拟功能配置
void AnalogIO( GPIO_Type* GPIOx, uint32_t GPIO_Pin )
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    GPIO_InitTypeDef  GPIO_InitStructureRun;

    GPIO_Get_InitPara(GPIOx, GPIO_Pin, &GPIO_InitStructureRun);

    if( (GPIO_InitStructureRun.Pin		!= GPIO_Pin) ||
    (GPIO_InitStructureRun.PxINEN	!= GPIO_IN_Dis) ||
    (GPIO_InitStructureRun.PxODEN	!= GPIO_OD_Dis) ||
    (GPIO_InitStructureRun.PxPUEN	!= GPIO_PU_Dis) ||
    (GPIO_InitStructureRun.PxFCR	!= GPIO_FCR_ANA) )
    {
        GPIO_InitStructure.Pin = GPIO_Pin;
        GPIO_InitStructure.PxINEN = GPIO_IN_Dis;
        GPIO_InitStructure.PxODEN = GPIO_OD_Dis;
        GPIO_InitStructure.PxPUEN = GPIO_PU_Dis;
        GPIO_InitStructure.PxFCR = GPIO_FCR_ANA;

        GPIO_Init(GPIOx, &GPIO_InitStructure);	
    }
}

//GPIOH 模拟功能配置
void AnalogIO_H(uint32_t GPIO_Pin )
{
    uint32_t pinpos = 0x00,pinbit = 0x00;

    if(CDIF_CR_INTF_EN_Getable() == DISABLE)
    {
        CDIF_CR_INTF_EN_Setable(ENABLE);
    }
    for (pinpos = 0; pinpos < 4; pinpos++)
    {
        pinbit = ((uint32_t)0x01) << pinpos;
        if(GPIO_Pin & pinbit)
        {
            GPIOH->INEN &= (~(1<<pinpos));
            GPIOH->FCR |= (3<<(pinpos*2)) ;
        }    
    } 
    if(CDIF_CR_INTF_EN_Getable() == ENABLE)
    {
         CDIF_CR_INTF_EN_Setable(DISABLE);
    }
}

//GPIOA~G 输入口配置 
//type 0 = 普通 
//type 1 = 上拉
//#define IN_NORMAL	0
//#define IN_PULLUP	1
void InputtIO( GPIO_Type* GPIOx, uint32_t GPIO_Pin, uint8_t Type )
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    GPIO_InitTypeDef  GPIO_InitStructureRun;

    GPIO_Get_InitPara(GPIOx, GPIO_Pin, &GPIO_InitStructureRun);

    if( (GPIO_InitStructureRun.Pin		!= GPIO_Pin) ||
    (GPIO_InitStructureRun.PxINEN	!= GPIO_IN_En) ||
    (GPIO_InitStructureRun.PxODEN	!= GPIO_OD_En) ||
    ((Type == IN_NORMAL)&&(GPIO_InitStructureRun.PxPUEN != GPIO_PU_Dis)) ||
    ((Type == IN_PULLUP)&&(GPIO_InitStructureRun.PxPUEN != GPIO_PU_En)) ||
    (GPIO_InitStructureRun.PxFCR	!= GPIO_FCR_IN) )
    {
        GPIO_InitStructure.Pin = GPIO_Pin;	
        GPIO_InitStructure.PxINEN = GPIO_IN_En;
        GPIO_InitStructure.PxODEN = GPIO_OD_En;
        if(Type == IN_NORMAL)		GPIO_InitStructure.PxPUEN = GPIO_PU_Dis;
        else						GPIO_InitStructure.PxPUEN = GPIO_PU_En;	
        GPIO_InitStructure.PxFCR = GPIO_FCR_IN;

        GPIO_Init(GPIOx, &GPIO_InitStructure);	
    }
}

//GPIOH 输入口配置 
//type 0 = 普通 
//type 1 = 上拉
//#define IN_NORMAL	0
//#define IN_PULLUP	1
void InputtIO_H(uint32_t GPIO_Pin, uint8_t Type )
{
    uint32_t pinpos = 0x00,pinbit = 0x00;

    if(CDIF_CR_INTF_EN_Getable() == DISABLE)
    {
        CDIF_CR_INTF_EN_Setable(ENABLE);
    }
    for (pinpos = 0; pinpos < 4; pinpos++)
    {
        pinbit = ((uint32_t)0x01) << pinpos;
        if(GPIO_Pin & pinbit)
        {
            if(Type==0)
            {
                GPIOH->PUEN &= (~(1<<pinpos));
            }
            else
            {
                GPIOH->PUEN |= (1<<pinpos);
            }
            GPIOH->FCR &= (~(3<<(pinpos*2)));
            GPIOH->INEN |= (1<<pinpos);    
        }    
    }
    if(CDIF_CR_INTF_EN_Getable() == ENABLE)
    {
        CDIF_CR_INTF_EN_Setable(DISABLE);
    }
}

//GPIOA~G输出口配置 
//type 0 = 普通 
//type 1 = OD
//#define OUT_PUSHPULL	0
//#define OUT_OPENDRAIN	1
void OutputIO( GPIO_Type* GPIOx, uint32_t GPIO_Pin, uint8_t Type )
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    GPIO_InitTypeDef  GPIO_InitStructureRun;

    GPIO_Get_InitPara(GPIOx, GPIO_Pin, &GPIO_InitStructureRun);

    if( (GPIO_InitStructureRun.Pin		!= GPIO_Pin) ||
    (GPIO_InitStructureRun.PxINEN	!= GPIO_IN_Dis) ||
    ((Type == OUT_PUSHPULL)&&(GPIO_InitStructureRun.PxODEN	!= GPIO_OD_Dis)) ||
    ((Type == OUT_OPENDRAIN)&&(GPIO_InitStructureRun.PxODEN	!= GPIO_OD_En)) ||
    (GPIO_InitStructureRun.PxPUEN	!= GPIO_PU_Dis) ||
    (GPIO_InitStructureRun.PxFCR	!= GPIO_FCR_OUT) )
    {
        GPIO_InitStructure.Pin = GPIO_Pin;
        GPIO_InitStructure.PxINEN = GPIO_IN_Dis;
        if(Type == OUT_PUSHPULL)	GPIO_InitStructure.PxODEN = GPIO_OD_Dis;
        else						GPIO_InitStructure.PxODEN = GPIO_OD_En;
        GPIO_InitStructure.PxPUEN = GPIO_PU_Dis;
        GPIO_InitStructure.PxFCR = GPIO_FCR_OUT;

        GPIO_Init(GPIOx, &GPIO_InitStructure);		
    }
}

//GPIOH输出口配置 
void OutputIO_H(uint32_t GPIO_Pin)
{
    uint32_t pinpos = 0x00,pinbit = 0x00;

    if(CDIF_CR_INTF_EN_Getable() == DISABLE)
    {
        CDIF_CR_INTF_EN_Setable(ENABLE);
    }
    for (pinpos = 0; pinpos < 4; pinpos++)
    { 
        pinbit = ((uint32_t)0x01) << pinpos;
        if(GPIO_Pin & pinbit)
        {
            GPIOH->INEN &= (~(1<<pinpos));
            GPIOH->PUEN &= (~(1<<pinpos));
            GPIOH->FCR &= (~(3<<(pinpos*2)));
            GPIOH->FCR |= (1<<(pinpos*2));
        }    
    }
    if(CDIF_CR_INTF_EN_Getable() == ENABLE)
    {
        CDIF_CR_INTF_EN_Setable(DISABLE);
    }
}

//IO数字特殊功能口 
//type 0 = 普通 
//type 1 = OD (OD功能仅部分特殊功能支持)
//type 2 = 普通+上拉 
//type 3 = OD+上拉
//#define ALTFUN_NORMAL				0
//#define ALTFUN_OPENDRAIN			1
//#define ALTFUN_PULLUP				2
//#define ALTFUN_OPENDRAIN_PULLUP	3
void AltFunIO( GPIO_Type* GPIOx, uint32_t GPIO_Pin, uint8_t Type  )
{																
    GPIO_InitTypeDef  GPIO_InitStructure;
    GPIO_InitTypeDef  GPIO_InitStructureRun;

    GPIO_Get_InitPara(GPIOx, GPIO_Pin, &GPIO_InitStructureRun);

    if( (GPIO_InitStructureRun.Pin		!= GPIO_Pin) ||
    (GPIO_InitStructureRun.PxINEN	!= GPIO_IN_Dis) ||
    (((Type & 0x01) == 0)&&(GPIO_InitStructureRun.PxODEN	!= GPIO_OD_Dis)) ||
    (((Type & 0x01) != 0)&&(GPIO_InitStructureRun.PxODEN	!= GPIO_OD_En)) ||
    (((Type & 0x02) == 0)&&(GPIO_InitStructureRun.PxPUEN	!= GPIO_PU_Dis)) ||
    (((Type & 0x02) != 0)&&(GPIO_InitStructureRun.PxPUEN	!= GPIO_PU_En)) ||
    (GPIO_InitStructureRun.PxFCR	!= GPIO_FCR_DIG) )
    {
        GPIO_InitStructure.Pin = GPIO_Pin;
        GPIO_InitStructure.PxINEN = GPIO_IN_Dis;
        if( (Type & 0x01) == 0 )	GPIO_InitStructure.PxODEN = GPIO_OD_Dis;
        else						GPIO_InitStructure.PxODEN = GPIO_OD_En;
        if( (Type & 0x02) == 0 )	GPIO_InitStructure.PxPUEN = GPIO_PU_Dis;
        else						GPIO_InitStructure.PxPUEN = GPIO_PU_En;	
        GPIO_InitStructure.PxFCR = GPIO_FCR_DIG;

        GPIO_Init(GPIOx, &GPIO_InitStructure);		
    }
}

//IO数字特殊功能口 
//type 0 = 普通 
//type 1= 普通+上拉 
void AltFunIO_H(uint32_t GPIO_Pin, uint8_t Type  )
{																
    uint32_t pinpos = 0x00,pinbit = 0x00;

    if(CDIF_CR_INTF_EN_Getable() == DISABLE)
    {
        CDIF_CR_INTF_EN_Setable(ENABLE);
    }
    for (pinpos = 0; pinpos < 4; pinpos++)
    { 
        pinbit = ((uint32_t)0x01) << pinpos;
        if(GPIO_Pin & pinbit)
        {
            GPIOH->INEN &= (~(1<<pinpos));
            if(Type==0)
            {
                GPIOH->PUEN &= (~(1<<pinpos));
            }
            else
            {
                GPIOH->PUEN |= (1<<pinpos);
            }
            GPIOH->FCR &= (~(3<<(pinpos*2)));
            GPIOH->FCR |= (2<<(pinpos*2));
        }    
    }
    if(CDIF_CR_INTF_EN_Getable() == ENABLE)
    {
        CDIF_CR_INTF_EN_Setable(DISABLE);
    }   
}

//IO关闭（GPIOA,B,C,D,E,F,G）（od输出高）
//配置IO为高阻态
void CloseIO( GPIO_Type* GPIOx, uint32_t GPIO_Pin )
{
    uint32_t pinpos = 0x00,pinbit = 0x00;

    for (pinpos = 0; pinpos < 16; pinpos++)
    { 
        pinbit = ((uint32_t)0x01) << pinpos;
        if(GPIO_Pin & pinbit)
        {
            GPIOx->INEN &=~(1<<pinpos);
            GPIOx->FCR  &= ~(3<<(pinpos*2));
        }    
    }
}

//IO GPIOH关闭（od输出高）
//配置IO为高阻态
void CloseH_IO( GPIOH_Type* GPIOx, uint32_t GPIO_Pin )
{
    uint32_t pinpos = 0x00,pinbit = 0x00;

    if(CDIF_CR_INTF_EN_Getable() == DISABLE)
    {
        CDIF_CR_INTF_EN_Setable(ENABLE);
    }
    for (pinpos = 0; pinpos < 4; pinpos++)
    { 
        pinbit = ((uint32_t)0x01) << pinpos;
        if(GPIO_Pin & pinbit)
        {
            GPIOx->INEN &=~(1<<pinpos);
            GPIOx->FCR  &= ~(3<<(pinpos*2));
        }    
    }
    if(CDIF_CR_INTF_EN_Getable() == ENABLE)
    {
        CDIF_CR_INTF_EN_Setable(DISABLE);
    } 
}

void IWDT_Clr(void)
{
  IWDT ->SERV =0x12345A5A;
}

void IWDT_Init(void)
{
    CMU_PERCLK_SetableEx(IWDTCLK, ENABLE); 
    IWDT->CFGR =0x06;  //周期2S，休眠4096S
    IWDT_Clr();
}









void LED0_Flash(uint08 Times)
{
    uint08 i;

    CMU_PERCLK_SetableEx(PADCLK, ENABLE);  
    OutputIO(LED0_GPIO,LED0_PIN,0 );

	for( i=0; i<Times; i++ )
	{
        LED0_ON;
        TicksDelayMs( 100, NULL );		
        LED0_OFF;
        TicksDelayMs( 100, NULL );	
	}
}

//系统时钟配置
//使用RCHF做主时钟,define_all.h 中SYSCLKdef宏控制系统时钟频率
void Init_SysClk(void)
{
	CMU_SYSCLK_InitTypeDef SYSCLK_InitStruct;
		
	SYSCLK_InitStruct.SYSCLKSEL =  CMU_SYSCLKCR_SYSCLKSEL_RCHF;	//选择RCHF做主时钟
	SYSCLK_InitStruct.AHBPRES =    CMU_SYSCLKCR_AHBPRES_DIV1;		//AHB不分频
	SYSCLK_InitStruct.APBPRES =   CMU_SYSCLKCR_APBPRES_DIV1;		//APB1不分频
	SYSCLK_InitStruct.SLP_ENEXTI = ENABLE;//休眠模式使能外部中断采样	
	CMU_SysClk_Init(&SYSCLK_InitStruct);
}

void Init_RCHF(void)
{
    CMU_RCHF_InitTypeDef RCHF_InitStruct;

    RCHF_InitStruct.FSEL = SYSCLKdef;//define_all.h 中SYSCLKdef宏控制系统时钟频率
    RCHF_InitStruct.RCHFEN = ENABLE;//打开RCHF

    CMU_RCHF_Init(&RCHF_InitStruct);

    CMU_Init_RCHF_Trim(clkmode);//RCHF振荡器校准值载入(芯片复位后自动载入8M的校准值)，只是调校RCHF常温精度  
}

void Init_RCLP(void)
{
    CDIF->CR = 0X0A;
    VRTC->RCLPTR = RCLP_TRIM;
    CDIF->CR = 0X05;
}
    
void Init_SysClk_Gen( void )				//时钟选择相关
{	  
    /*系统时钟超过24M后需要打开wait*/
    if( RCHFCLKCFG > 24 )
    {
        FLS_RDCR_WAIT_Set(FLS_RDCR_WAIT_1CYCLE);
        if( RCHFCLKCFG > 48)  
        {
            FLS_RDCR_WAIT_Set(FLS_RDCR_WAIT_2CYCLE);
        }
    } 
    {
        FLS_RDCR_WAIT_Set(FLS_RDCR_WAIT_0CYCLE);
    }	

    Init_RCHF();
    Init_RCLP();
    /*系统时钟配置*/
    Init_SysClk();	
}

void DEBUG_Init(void)
{
    DBG->CR =0x3; //DEBUG时关闭IWDT WWDT保持其他定时器原来的状态 
}

//外部中断初始化
void EXTI_Init()
{
		CMU_OPCCR1_EXTICKSEL_Set(CMU_OPCCR1_EXTICKSEL_LSCLK);//EXTI中断采样时钟选择
		CMU_OPCCR1_EXTICKE_Setable(ENABLE);			//EXTI工作时钟使能
		CMU_PERCLK_SetableEx(PADCLK, ENABLE); 		//IO控制时钟寄存器使能
		InputtIO(GP_TEST_GPIO,GP_TEST_PIN,IN_PULLUP);//上拉电阻
		InputtIO(PULSE_GPIO,PULSE_PIN,IN_NORMAL);
		GPIO_EXTI_Init(GP_TEST_GPIO,GP_TEST_PIN,EXTI_BOTH,ENABLE);//打开GP上下沿检测中断	
		GPIO_EXTI_Init(PULSE_GPIO,PULSE_PIN,EXTI_RISING,ENABLE);//打开脉冲上升沿检测中断
		
		/*NVIC中断配置*/
    NVIC_DisableIRQ(GPIO_IRQn);
    NVIC_SetPriority(GPIO_IRQn,2);//中断优先级配置
    NVIC_EnableIRQ(GPIO_IRQn);
} 
GPIO_InitTypeDef GPIO_Init_temp;
//IO口初始化
void IO_Init()
{		
		//Bat_Con
		GPIO_Init_temp.Pin=BAT_CON_PIN;
		GPIO_Init_temp.PxFCR=GPIO_FCR_OUT;
		GPIO_Init_temp.PxINEN=GPIO_IN_Dis;
		GPIO_Init_temp.PxODEN=GPIO_OD_Dis;
		GPIO_Init_temp.PxPUEN=GPIO_PU_Dis;
		GPIO_Init(BAT_CON_GPIO,&GPIO_Init_temp);
		GPIO_ResetBits(GPIOC,GPIO_Pin_13);
		//Spc_Con
		GPIO_Init_temp.Pin=SPC_CON_PIN;
		GPIO_Init(SPC_CON_GPIO,&GPIO_Init_temp);
		GPIO_SetBits(SPC_CON_GPIO,SPC_CON_PIN);
		//FLASH_CS1
		GPIO_Init_temp.Pin=FLASH_CS1_PIN;
		GPIO_Init(FLASH_CS1_GPIO,&GPIO_Init_temp);
		GPIO_ResetBits(FLASH_CS1_GPIO,FLASH_CS1_PIN);
		//FLASH_CON
		GPIO_Init_temp.Pin=FLASH_CON_PIN;
		GPIO_Init(FLASH_CON_GPIO,&GPIO_Init_temp);
		GPIO_ResetBits(FLASH_CON_GPIO,FLASH_CON_PIN);
		//LED_GREEN
		GPIO_Init_temp.Pin=LED_GREEN_PIN;
		GPIO_Init(LED_GREEN_GPIO,&GPIO_Init_temp);
		//LED_RED
		GPIO_Init_temp.Pin=LED_RED_PIN;
		GPIO_Init(LED_RED_GPIO,&GPIO_Init_temp);
		GPIO_SetBits(FLASH_CON_GPIO,FLASH_CON_PIN);
		//GP_CON
		GPIO_Init_temp.Pin=GP_CON_PIN;
		GPIO_Init(GP_CON_GPIO,&GPIO_Init_temp);
		GPIO_SetBits(GP_CON_GPIO,GP_CON_PIN);
		//SPC_EN
		GPIO_Init_temp.Pin=SPC_EN_PIN;
		GPIO_Init(SPC_EN_GPIO,&GPIO_Init_temp);
		GPIO_SetBits(SPC_EN_GPIO,SPC_EN_PIN);
		//GP_TEST
		GPIO_Init_temp.Pin=GP_TEST_PIN;
		GPIO_Init_temp.PxFCR=GPIO_FCR_IN;
		GPIO_Init_temp.PxPUEN=GPIO_PU_En;
		GPIO_Init_temp.PxINEN=GPIO_IN_En;
		GPIO_Init(GP_TEST_GPIO,&GPIO_Init_temp);
		
}
void LowPower_IO_Init()
{
    // 配置输出模式，输出低电平，禁用输入，禁用开漏，禁用上拉和下拉
    GPIO_Init_temp.PxFCR = GPIO_FCR_OUT;      // 设置为输出模式
    GPIO_Init_temp.PxINEN = GPIO_IN_Dis;      // 禁用输入
    GPIO_Init_temp.PxODEN = GPIO_OD_Dis;      // 禁用开漏
    GPIO_Init_temp.PxPUEN = GPIO_PU_Dis;      // 禁用上拉

    // 未使用的 GPIOA 引脚
    GPIO_Init_temp.Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 |
                         GPIO_Pin_10 | GPIO_Pin_13 | GPIO_Pin_14| GPIO_Pin_15;  // 未使用的引脚
    GPIO_Init(GPIOA, &GPIO_Init_temp);  // 初始化 GPIOA 的未使用引脚
    GPIO_ResetBits(GPIOA, GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 |
                         GPIO_Pin_10 | GPIO_Pin_13 | GPIO_Pin_14| GPIO_Pin_15); // 设置输出低电平

    // 未使用的 GPIOB 引脚
    GPIO_Init_temp.Pin = GPIO_Pin_0 | GPIO_Pin_1 |GPIO_Pin_4 | GPIO_Pin_5 |GPIO_Pin_6 | 
													GPIO_Pin_7 |GPIO_Pin_8 | GPIO_Pin_9 |GPIO_Pin_10 | GPIO_Pin_11 |
													GPIO_Pin_12 |GPIO_Pin_13 | GPIO_Pin_14 |GPIO_Pin_15;  // 未使用的引脚
    GPIO_Init(GPIOB, &GPIO_Init_temp);  // 初始化 GPIOB 的未使用引脚
    GPIO_ResetBits(GPIOB,GPIO_Pin_0 | GPIO_Pin_1 |GPIO_Pin_4 | GPIO_Pin_5 |GPIO_Pin_6 | 
													GPIO_Pin_7 |GPIO_Pin_8 | GPIO_Pin_9 |GPIO_Pin_10 | GPIO_Pin_11 |
													GPIO_Pin_12 |GPIO_Pin_13 | GPIO_Pin_14 |GPIO_Pin_15); // 设置输出低电平

    // 未使用的 GPIOC 引脚
    GPIO_Init_temp.Pin = GPIO_Pin_0 | GPIO_Pin_1 |GPIO_Pin_2 | GPIO_Pin_3 |GPIO_Pin_4 | GPIO_Pin_5 |GPIO_Pin_6 | 
													GPIO_Pin_7 |GPIO_Pin_8 | GPIO_Pin_9 |GPIO_Pin_10 | GPIO_Pin_11 |
													GPIO_Pin_13 | GPIO_Pin_14 |GPIO_Pin_15; // 未使用的引脚
    GPIO_Init(GPIOC, &GPIO_Init_temp);  // 初始化 GPIOC 的未使用引脚
    GPIO_ResetBits(GPIOC,GPIO_Pin_0 | GPIO_Pin_1 |GPIO_Pin_2 | GPIO_Pin_3 |GPIO_Pin_4 | GPIO_Pin_5 |GPIO_Pin_6 | 
													GPIO_Pin_7 |GPIO_Pin_8 | GPIO_Pin_9 |GPIO_Pin_10 | GPIO_Pin_11 |
													GPIO_Pin_13 | GPIO_Pin_14 |GPIO_Pin_15); // 设置输出低电平

//    // 未使用的 GPIOD 引脚
//    GPIO_Init_temp.Pin = GPIO_Pin_2;  // 假设 PD2 未使用
//    GPIO_Init(GPIOD, &GPIO_Init_temp);  // 初始化 GPIOD 的未使用引脚
//    GPIO_ResetBits(GPIOD, GPIO_Pin_2); // 设置输出低电平
}

void Init_System(void)
{		
	/*基础系统配置*/
    __disable_irq();			//关闭全局中断使能
    IWDT_Init();				//系统看门狗设置 （函数需要完善）
    IWDT_Clr();  				//清系统看门狗	
    Init_SysTick();				//cpu滴答定时器配置(软件延时用)	
    TicksDelayMs( 10, NULL );	//软件延时,系统上电后不要立刻将时钟切换为非RCHF8M，也不要立刻进休眠否则可能导致无法下载程序

    Init_SysClk_Gen();			//系统时钟配置	


    /*下电复位配置*/
    //pdr和bor两个下电复位至少要打开一个
    //当电源电压低于下电复位电压时，芯片会被复位住		
    //pdr电压档位不准但是功耗极低（几乎无法测量）
    //bor电压档位准确但是需要增加2uA功耗
    RMU_PDRCR_PDREN_Setable(ENABLE);		//打开PDR
    RMU_BORCR_BOR_PDRCFG_Set(RMU_BORCR_BOR_PDRCFG_1P75V);
    RMU_BORCR_OFF_BOR_Setable(DISABLE);	//打开BOR

    DEBUG_Init();
	
	
		EXTI_Init();
		RTC_Init();
		IO_Init();
		LowPower_IO_Init();
		Flash_Spi1_Init();
		Uartx_Init(UART4,115200,Eight8Bit,NONE,OneBit);//初始化uart配置8N1
		Uartx_Enable(UART4);//开启UART4的收发
		Uartx_Init(UART5,9600,Eight8Bit,NONE,OneBit);//初始化uart配置8N1
		Uartx_Enable(UART5);//开启UART5的收发
    /*RTC数值调整寄存器*/
    /*调校值复位后是个随机数，上电后可能是个较大的值影响RTC精度*/
    /*如应用中没有RTC调校，需要将这些注释放开*/
//    CMU_PERCLK_SetableEx(RTCCLK, ENABLE); 
//    RTC_ADJUST_Write(0);//RTC时钟温度补偿值写0，假如不操作调整寄存器，补偿值会是一个随机数，RTC时钟可能会偏差非常大
//    CMU_PERCLK_SetableEx(RTCCLK, DISABLE); 

    /*准备进入主循环*/
    TicksDelayMs( 100, NULL );	//软件延时


    __enable_irq();				//打开全局中断使能
}
