#include "define_all.h"  
#include "adc.h"
#define const_adc_Slope 	(*((uint16_t *)(0x1FFFFA84)))	//ADCб�ʣ���1000��ʹ��
#define const_adc_Offset 	(*((int16_t *)(0x1FFFFA86)))	//ADC�ؾ࣬��100��ʹ�ã���λmV
struct ADC_Struct
{
	uint16* Bufu16;		//���ݻ�������ַ	//ע���ڴ����
	uint08 SampleNeed;	//��Ҫ���������ݸ���
	uint08 SampleCount; //�Ѿ����������ݸ���
};

struct ADC_Struct ADC_Struct;

uint32 ANAC_ADC_VoltageCalc(uint32_t ADCData)
{
    int32_t Volt = 0;
    Volt = (ADCData*const_adc_Slope/1000)+const_adc_Offset/100;	

    if(Volt&0x80000000) //VoltΪ��ֵ
    {
        Volt=0;
    }
    return Volt;
}

void ADC_IO_Init(void)
{
		CMU_PERCLK_SetableEx(PADCLK, ENABLE);		//IO����ʱ�ӼĴ���ʹ��
  
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
		CDIF_CR_INTF_EN_Setable(ENABLE);						//���Դ��ӿ�ʹ��
		VRTC_Init_RCMF_Trim();
		VRTC_RCMFCR_EN_Setable(ENABLE);
		VRTC_ADCCR_CKS_Set(VRTC_ADCCR_CKS_RCMF_2);				//ADC����ʱ��ѡ��
		VRTC_ADCCR_CKE_Setable(ENABLE);							//ADC����ʱ��ʹ��
		//ADC_CFGR_BUFSEL_Set(ADC_CFGR_BUFSEL_ADC_IN1);			//ADC����ͨ��ѡ��
		
		ADC_CFGR_BUFEN_Setable(ENABLE);							//ADC����ͨ��bufferʹ��/��ֹ
		ADC_CR_MODE_Set(ADC_CR_MODE_INNER);						//ADC����ģʽѡ���ڲ��ۼ���
//  ADC_TRIM_Write(0X7FF);									//adcƵ��1M ʱ ����ʱ��4ms
    ADC_TRIM_Write(0X3FF);									//adcƵ��1M ʱ ����ʱ��2ms
//	ADC_TRIM_Write(0X1FF);									//adcƵ��1M ʱ ����ʱ��1ms
  
		ADC_CR_ADC_IE_Setable(DISABLE);							//�ڲ��ۼ�ģʽ�жϽ�ֹ
		ADC_CR_EN_Setable(DISABLE);								//ADC�ر�
}

uint08 ADC_Wait_Finish(void)
{	
		uint32 timeout=0;
			do
			{
					if(SET == ADC_ISR_ADC_IF_Chk()) return 0;
					
			}while(timeout++ < 0xFFFFFFFFU);
		return 1;//��ʱ
}

//ADC�ⲿ����ͨ������
uint32 Test_ADC_ExVolt(uint32_t ADC_Channel)
{
		uint16 ADCData[8];
		uint08 i;
		volatile int32 fVlotage = 0;
		uint32 fTempADC = 0;

		ADC_IO_Init();					    //IO������ΪADC����
		ADC_Init_ExVolt();				    //����ADC
		ADC_CFGR_BUFSEL_Set(ADC_Channel);
		ADC_CR_EN_Setable(ENABLE);		    //ADC����
		
		fTempADC = 0;
		for(i=0; i<8; i++)
		{
				ADC_ISR_ADC_IF_Clr();		    //����жϱ�־
				
				ADCData[i] = 0;
				if(0 == ADC_Wait_Finish())	    //�ȴ�ת�����
				{
						ADCData[i] = ADC_DR_Read();	//��ȡADֵ
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
		
		fVlotage = ANAC_ADC_VoltageCalc(fTempADC);//ADֵת��Ϊ��ѹ,��Դ��ѹΪ5V
		
		return fVlotage;
}


//int main (void)
//{	
//	Init_System();				//ϵͳ��ʼ�� 
//	
//	ResultADC=Test_ADC_ExVolt();
//	for( ; ; )
//    {	
//        IWDT_Clr();             //��ϵͳ���Ź�	
//        LED0_TOG;
//        TicksDelayMs( 100, NULL );
//    }	
//}


