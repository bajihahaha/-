#include "define_all.h"  
#include "adc.h"
#define const_adc_Slope 	(*((uint16_t *)(0x1FFFFA84)))	//ADC斜率，除1000后使用
#define const_adc_Offset 	(*((int16_t *)(0x1FFFFA86)))	//ADC截距，除100后使用，单位mV
struct ADC_Struct
{
	uint16* Bufu16;		//数据缓冲区地址	//注意内存对齐
	uint08 SampleNeed;	//需要采样的数据个数
	uint08 SampleCount; //已经采样的数据个数
};

struct ADC_Struct ADC_Struct;

uint32 ANAC_ADC_VoltageCalc(uint32_t ADCData)
{
    int32_t Volt = 0;
    Volt = (ADCData*const_adc_Slope/1000)+const_adc_Offset/100;	

    if(Volt&0x80000000) //Volt为负值
    {
        Volt=0;
    }
    return Volt;
}

void ADC_IO_Init(void)
{
		CMU_PERCLK_SetableEx(PADCLK, ENABLE);		//IO控制时钟寄存器使能
  
		AnalogIO(GPIOC,GPIO_Pin_12);//ADC_IN1
		GPIOx_ANEN_Setable(GPIOC,GPIO_Pin_12,ENABLE);
	
//	AnalogIO(GPIOC,GPIO_Pin_13);//ADC_IN2
//	GPIOx_ANEN_Setable(GPIOC,GPIO_Pin_13,ENABLE);
	
//	AnalogIO(GPIOD,GPIO_Pin_0);//ADC_IN3
//	GPIOx_ANEN_Setable(GPIOD,GPIO_Pin_0,ENABLE);
//	
//	AnalogIO(GPIOD,GPIO_Pin_1);//ADC_IN4
//	GPIOx_ANEN_Setable(GPIOD,GPIO_Pin_1,ENABLE);
//	
//	AnalogIO(GPIOF,GPIO_Pin_6);//ADC_IN5
//	GPIOx_ANEN_Setable(GPIOF,GPIO_Pin_6,ENABLE);
//	
		AnalogIO(GPIOC,GPIO_Pin_15);//ADC_IN6
		GPIOx_ANEN_Setable(GPIOC,GPIO_Pin_15,ENABLE);
//	
//	AnalogIO(GPIOB,GPIO_Pin_2);//ADC_IN7
//	GPIOx_ANEN_Setable(GPIOB,GPIO_Pin_2,ENABLE);
//	
//	AnalogIO(GPIOB,GPIO_Pin_3);//ADC_IN8
//	GPIOx_ANEN_Setable(GPIOB,GPIO_Pin_3,ENABLE);
//	
//	AnalogIO_H(GPIO_Pin_0);//ADC_IN9
//	AnalogIO_H(GPIO_Pin_1);//ADC_IN10
//	AnalogIO_H(GPIO_Pin_2);//ADC_IN11
//	AnalogIO_H(GPIO_Pin_3);//ADC_IN12  
}


void ADC_Init_ExVolt(void)
{
		CDIF_CR_INTF_EN_Setable(ENABLE);						//跨电源域接口使能
		VRTC_Init_RCMF_Trim();
		VRTC_RCMFCR_EN_Setable(ENABLE);
		VRTC_ADCCR_CKS_Set(VRTC_ADCCR_CKS_RCMF_2);				//ADC工作时钟选择
		VRTC_ADCCR_CKE_Setable(ENABLE);							//ADC工作时钟使能
		//ADC_CFGR_BUFSEL_Set(ADC_CFGR_BUFSEL_ADC_IN1);			//ADC输入通道选择
		
		ADC_CFGR_BUFEN_Setable(ENABLE);							//ADC输入通道buffer使能/禁止
		ADC_CR_MODE_Set(ADC_CR_MODE_INNER);						//ADC工作模式选择内部累加器
//  ADC_TRIM_Write(0X7FF);									//adc频率1M 时 计算时间4ms
    ADC_TRIM_Write(0X3FF);									//adc频率1M 时 计算时间2ms
//	ADC_TRIM_Write(0X1FF);									//adc频率1M 时 计算时间1ms
  
		ADC_CR_ADC_IE_Setable(DISABLE);							//内部累加模式中断禁止
		ADC_CR_EN_Setable(DISABLE);								//ADC关闭
}

uint08 ADC_Wait_Finish(void)
{	
		uint32 timeout=0;
			do
			{
					if(SET == ADC_ISR_ADC_IF_Chk()) return 0;
					
			}while(timeout++ < 0xFFFFFFFFU);
		return 1;//超时
}

//ADC外部输入通道测试
uint32 Test_ADC_ExVolt(uint32_t ADC_Channel)
{
		uint16 ADCData[8];
		uint08 i;
		volatile int32 fVlotage = 0;
		uint32 fTempADC = 0;

		ADC_IO_Init();					    //IO口配置为ADC输入
		ADC_Init_ExVolt();				    //配置ADC
		ADC_CFGR_BUFSEL_Set(ADC_Channel);
		ADC_CR_EN_Setable(ENABLE);		    //ADC启动
		
		fTempADC = 0;
		for(i=0; i<8; i++)
		{
				ADC_ISR_ADC_IF_Clr();		    //清除中断标志
				
				ADCData[i] = 0;
				if(0 == ADC_Wait_Finish())	    //等待转换完成
				{
						ADCData[i] = ADC_DR_Read();	//读取AD值
						fTempADC += ADCData[i];
				}
				else
				{
						break;
				}
		}
		
		if( i == 8 )
		{
				fTempADC = fTempADC/8;
		}
		
		fVlotage = ANAC_ADC_VoltageCalc(fTempADC);//AD值转换为电压,电源电压为5V
		
		return fVlotage;
}


//int main (void)
//{	
//	Init_System();				//系统初始化 
//	
//	ResultADC=Test_ADC_ExVolt();
//	for( ; ; )
//    {	
//        IWDT_Clr();             //清系统看门狗	
//        LED0_TOG;
//        TicksDelayMs( 100, NULL );
//    }	
//}


