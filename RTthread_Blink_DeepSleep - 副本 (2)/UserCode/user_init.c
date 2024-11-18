#include "define_all.h"  
#include "rtc.h"
#include "spi.h"
#include "uart.h"
#define RCLP_TRIM (uint8_t)(*(uint32_t *)0X1FFFFB20UL)
//cpu�δ�ʱ������(�����ʱ��)
void Init_SysTick(void)
{
    CMU->SYSCLKCR &= 0xFFFFFF3F; //systick����ʱ��ѡ��SCLK
    SysTick_Config(0x1000000UL);
    SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |//�ر��ж�
                    //SysTick_CTRL_TICKINT_Msk |
                    SysTick_CTRL_ENABLE_Msk;
}
//���������ʱǰ����������SysTick
void TicksDelay(uint32_t ClkNum)
{
    uint32_t last = SysTick->VAL;
    
    ClkNum = ClkNum*clkmode;//��Ӧ��ͬ��Ƶ��8Mʱ���ʱ2ms��32Mʱ���ʱ0.5ms
    if(ClkNum>0xF00000)
    {
        ClkNum = 0xF00000;
    }
    while(((last - SysTick->VAL)&0xFFFFFFUL ) < ClkNum);
} 
//ms�����ʱ
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
//us�����ʱ
void TicksDelayUs(uint32_t us)
{
    uint32_t ClkNum;
    
    if(us>100000)//������100ms
    {
        us = 100000;
    }
    ClkNum = us*(__SYSTEM_CLOCK/1000000) ;
    TicksDelay(ClkNum);
}

//У��Ĵ���
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

//��ѯNVIC�Ĵ�����Ӧ�������ж��Ƿ��
//1 ��
//0 �ر�
unsigned char CheckNvicIrqEn( IRQn_Type IRQn )
{
	if( 0 == ( NVIC->ISER[0U] & ((uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL)))) )
		return 0;
	else
		return 1;
}

//GPIOA~G  ģ�⹦������
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

//GPIOH ģ�⹦������
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

//GPIOA~G ��������� 
//type 0 = ��ͨ 
//type 1 = ����
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

//GPIOH ��������� 
//type 0 = ��ͨ 
//type 1 = ����
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

//GPIOA~G��������� 
//type 0 = ��ͨ 
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

//GPIOH��������� 
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

//IO�������⹦�ܿ� 
//type 0 = ��ͨ 
//type 1 = OD (OD���ܽ��������⹦��֧��)
//type 2 = ��ͨ+���� 
//type 3 = OD+����
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

//IO�������⹦�ܿ� 
//type 0 = ��ͨ 
//type 1= ��ͨ+���� 
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

//IO�رգ�GPIOA,B,C,D,E,F,G����od����ߣ�
//����IOΪ����̬
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

//IO GPIOH�رգ�od����ߣ�
//����IOΪ����̬
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
    IWDT->CFGR =0x06;  //����2S������4096S
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

//ϵͳʱ������
//ʹ��RCHF����ʱ��,define_all.h ��SYSCLKdef�����ϵͳʱ��Ƶ��
void Init_SysClk(void)
{
	CMU_SYSCLK_InitTypeDef SYSCLK_InitStruct;
		
	SYSCLK_InitStruct.SYSCLKSEL =  CMU_SYSCLKCR_SYSCLKSEL_RCHF;	//ѡ��RCHF����ʱ��
	SYSCLK_InitStruct.AHBPRES =    CMU_SYSCLKCR_AHBPRES_DIV1;		//AHB����Ƶ
	SYSCLK_InitStruct.APBPRES =   CMU_SYSCLKCR_APBPRES_DIV1;		//APB1����Ƶ
	SYSCLK_InitStruct.SLP_ENEXTI = ENABLE;//����ģʽʹ���ⲿ�жϲ���	
	CMU_SysClk_Init(&SYSCLK_InitStruct);
}

void Init_RCHF(void)
{
    CMU_RCHF_InitTypeDef RCHF_InitStruct;

    RCHF_InitStruct.FSEL = SYSCLKdef;//define_all.h ��SYSCLKdef�����ϵͳʱ��Ƶ��
    RCHF_InitStruct.RCHFEN = ENABLE;//��RCHF

    CMU_RCHF_Init(&RCHF_InitStruct);

    CMU_Init_RCHF_Trim(clkmode);//RCHF����У׼ֵ����(оƬ��λ���Զ�����8M��У׼ֵ)��ֻ�ǵ�УRCHF���¾���  
}

void Init_RCLP(void)
{
    CDIF->CR = 0X0A;
    VRTC->RCLPTR = RCLP_TRIM;
    CDIF->CR = 0X05;
}
    
void Init_SysClk_Gen( void )				//ʱ��ѡ�����
{	  
    /*ϵͳʱ�ӳ���24M����Ҫ��wait*/
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
    /*ϵͳʱ������*/
    Init_SysClk();	
}

void DEBUG_Init(void)
{
    DBG->CR =0x3; //DEBUGʱ�ر�IWDT WWDT����������ʱ��ԭ����״̬ 
}

//�ⲿ�жϳ�ʼ��
void EXTI_Init()
{
		CMU_OPCCR1_EXTICKSEL_Set(CMU_OPCCR1_EXTICKSEL_LSCLK);//EXTI�жϲ���ʱ��ѡ��
		CMU_OPCCR1_EXTICKE_Setable(ENABLE);			//EXTI����ʱ��ʹ��
		CMU_PERCLK_SetableEx(PADCLK, ENABLE); 		//IO����ʱ�ӼĴ���ʹ��
		InputtIO(GP_TEST_GPIO,GP_TEST_PIN,IN_PULLUP);//��������
		InputtIO(PULSE_GPIO,PULSE_PIN,IN_NORMAL);
		GPIO_EXTI_Init(GP_TEST_GPIO,GP_TEST_PIN,EXTI_BOTH,ENABLE);//��GP�����ؼ���ж�	
		GPIO_EXTI_Init(PULSE_GPIO,PULSE_PIN,EXTI_RISING,ENABLE);//�����������ؼ���ж�
		
		/*NVIC�ж�����*/
    NVIC_DisableIRQ(GPIO_IRQn);
    NVIC_SetPriority(GPIO_IRQn,2);//�ж����ȼ�����
    NVIC_EnableIRQ(GPIO_IRQn);
} 
GPIO_InitTypeDef GPIO_Init_temp;
//IO�ڳ�ʼ��
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
    // �������ģʽ������͵�ƽ���������룬���ÿ�©����������������
    GPIO_Init_temp.PxFCR = GPIO_FCR_OUT;      // ����Ϊ���ģʽ
    GPIO_Init_temp.PxINEN = GPIO_IN_Dis;      // ��������
    GPIO_Init_temp.PxODEN = GPIO_OD_Dis;      // ���ÿ�©
    GPIO_Init_temp.PxPUEN = GPIO_PU_Dis;      // ��������

    // δʹ�õ� GPIOA ����
    GPIO_Init_temp.Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 |
                         GPIO_Pin_10 | GPIO_Pin_13 | GPIO_Pin_14| GPIO_Pin_15;  // δʹ�õ�����
    GPIO_Init(GPIOA, &GPIO_Init_temp);  // ��ʼ�� GPIOA ��δʹ������
    GPIO_ResetBits(GPIOA, GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 |
                         GPIO_Pin_10 | GPIO_Pin_13 | GPIO_Pin_14| GPIO_Pin_15); // ��������͵�ƽ

    // δʹ�õ� GPIOB ����
    GPIO_Init_temp.Pin = GPIO_Pin_0 | GPIO_Pin_1 |GPIO_Pin_4 | GPIO_Pin_5 |GPIO_Pin_6 | 
													GPIO_Pin_7 |GPIO_Pin_8 | GPIO_Pin_9 |GPIO_Pin_10 | GPIO_Pin_11 |
													GPIO_Pin_12 |GPIO_Pin_13 | GPIO_Pin_14 |GPIO_Pin_15;  // δʹ�õ�����
    GPIO_Init(GPIOB, &GPIO_Init_temp);  // ��ʼ�� GPIOB ��δʹ������
    GPIO_ResetBits(GPIOB,GPIO_Pin_0 | GPIO_Pin_1 |GPIO_Pin_4 | GPIO_Pin_5 |GPIO_Pin_6 | 
													GPIO_Pin_7 |GPIO_Pin_8 | GPIO_Pin_9 |GPIO_Pin_10 | GPIO_Pin_11 |
													GPIO_Pin_12 |GPIO_Pin_13 | GPIO_Pin_14 |GPIO_Pin_15); // ��������͵�ƽ

    // δʹ�õ� GPIOC ����
    GPIO_Init_temp.Pin = GPIO_Pin_0 | GPIO_Pin_1 |GPIO_Pin_2 | GPIO_Pin_3 |GPIO_Pin_4 | GPIO_Pin_5 |GPIO_Pin_6 | 
													GPIO_Pin_7 |GPIO_Pin_8 | GPIO_Pin_9 |GPIO_Pin_10 | GPIO_Pin_11 |
													GPIO_Pin_13 | GPIO_Pin_14 |GPIO_Pin_15; // δʹ�õ�����
    GPIO_Init(GPIOC, &GPIO_Init_temp);  // ��ʼ�� GPIOC ��δʹ������
    GPIO_ResetBits(GPIOC,GPIO_Pin_0 | GPIO_Pin_1 |GPIO_Pin_2 | GPIO_Pin_3 |GPIO_Pin_4 | GPIO_Pin_5 |GPIO_Pin_6 | 
													GPIO_Pin_7 |GPIO_Pin_8 | GPIO_Pin_9 |GPIO_Pin_10 | GPIO_Pin_11 |
													GPIO_Pin_13 | GPIO_Pin_14 |GPIO_Pin_15); // ��������͵�ƽ

//    // δʹ�õ� GPIOD ����
//    GPIO_Init_temp.Pin = GPIO_Pin_2;  // ���� PD2 δʹ��
//    GPIO_Init(GPIOD, &GPIO_Init_temp);  // ��ʼ�� GPIOD ��δʹ������
//    GPIO_ResetBits(GPIOD, GPIO_Pin_2); // ��������͵�ƽ
}

void Init_System(void)
{		
	/*����ϵͳ����*/
    __disable_irq();			//�ر�ȫ���ж�ʹ��
    IWDT_Init();				//ϵͳ���Ź����� ��������Ҫ���ƣ�
    IWDT_Clr();  				//��ϵͳ���Ź�	
    Init_SysTick();				//cpu�δ�ʱ������(�����ʱ��)	
    TicksDelayMs( 10, NULL );	//�����ʱ,ϵͳ�ϵ��Ҫ���̽�ʱ���л�Ϊ��RCHF8M��Ҳ��Ҫ���̽����߷�����ܵ����޷����س���

    Init_SysClk_Gen();			//ϵͳʱ������	


    /*�µ縴λ����*/
    //pdr��bor�����µ縴λ����Ҫ��һ��
    //����Դ��ѹ�����µ縴λ��ѹʱ��оƬ�ᱻ��λס		
    //pdr��ѹ��λ��׼���ǹ��ļ��ͣ������޷�������
    //bor��ѹ��λ׼ȷ������Ҫ����2uA����
    RMU_PDRCR_PDREN_Setable(ENABLE);		//��PDR
    RMU_BORCR_BOR_PDRCFG_Set(RMU_BORCR_BOR_PDRCFG_1P75V);
    RMU_BORCR_OFF_BOR_Setable(DISABLE);	//��BOR

    DEBUG_Init();
	
	
		EXTI_Init();
		RTC_Init();
		IO_Init();
		LowPower_IO_Init();
		Flash_Spi1_Init();
		Uartx_Init(UART4,115200,Eight8Bit,NONE,OneBit);//��ʼ��uart����8N1
		Uartx_Enable(UART4);//����UART4���շ�
		Uartx_Init(UART5,9600,Eight8Bit,NONE,OneBit);//��ʼ��uart����8N1
		Uartx_Enable(UART5);//����UART5���շ�
    /*RTC��ֵ�����Ĵ���*/
    /*��Уֵ��λ���Ǹ���������ϵ������Ǹ��ϴ��ֵӰ��RTC����*/
    /*��Ӧ����û��RTC��У����Ҫ����Щע�ͷſ�*/
//    CMU_PERCLK_SetableEx(RTCCLK, ENABLE); 
//    RTC_ADJUST_Write(0);//RTCʱ���¶Ȳ���ֵд0�����粻���������Ĵ���������ֵ����һ���������RTCʱ�ӿ��ܻ�ƫ��ǳ���
//    CMU_PERCLK_SetableEx(RTCCLK, DISABLE); 

    /*׼��������ѭ��*/
    TicksDelayMs( 100, NULL );	//�����ʱ


    __enable_irq();				//��ȫ���ж�ʹ��
}
