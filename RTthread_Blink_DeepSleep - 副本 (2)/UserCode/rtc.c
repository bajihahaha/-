#include "define_all.h" 
#include "rtc.h"

//RTC��ʼ������
void RTC_Init(void)
{
		CMU_PERCLK_SetableEx(RTCCLK, ENABLE);  //RTC����ʱ��ʹ��
		RTC_VCAL_PR1SEN_Setable(DISABLE);		//�����Уʹ�ܹر�

		RTC_ISR_SEC_IF_Clr();		//������жϱ�־											
		RTC_IER_SEC_IE_Setable(DISABLE);//RTC���ж�	
		
		NVIC_DisableIRQ(RTC_IRQn);				//NVIC�жϿ���������
		NVIC_SetPriority(RTC_IRQn,2);
		NVIC_EnableIRQ(RTC_IRQn);		
}

//����RTC��ʱ
void RTC_Alarm(RTC_AlarmTmieTypeDef TempAlarmTime)
{
		RTC_ALARM_ALMEN_Setable(DISABLE);//�ر����ӹ���ʹ��
		RTC_IER_ALARM_IE_Setable(DISABLE);//�ر������ж�
		RTC_AlarmTime_SetEx(&TempAlarmTime);	//��������ʱ��	
		RTC_ISR_ALARM_IF_Clr();		//��������жϱ�־											
		RTC_IER_ALARM_IE_Setable(ENABLE);//�������ж�	
		RTC_ALARM_ALMEN_Setable(ENABLE);//���ӹ���ʹ��
		RTC_CR_RTC_EN_Setable(ENABLE);
}


//��ȡRTCʵʱʱ��
uint08 RTC_GetRTC(RTC_TimeDateTypeDef* para)
{
	uint08 n, i;
	uint08 Result = 1;

	RTC_TimeDateTypeDef TempTime1,TempTime2;
	
	for(n=0 ;n<3; n++)
	{
		RTC_TimeDate_GetEx(&TempTime1);//��һ��ʱ��
		RTC_TimeDate_GetEx(&TempTime2);//�ٶ�һ��ʱ��
		
		for(i=0; i<7; i++)//����һ��, ��ʾ��ȡ�ɹ�
		{
			if(((uint08*)(&TempTime1))[i] != ((uint08*)(&TempTime2))[i]) break;
		}
		if(i == 7)
		{
			Result = 0;
			memcpy((uint08*)(para), (uint08*)(&TempTime1), 7);//��ȡ��ȷ������µ�ʱ��		
			break;
		}
	}
	return Result;
}

//����RTC��ʵʱʱ��
uint08 RTC_SetRTC(RTC_TimeDateTypeDef* para)
{
	uint08 n, i;
	uint08 Result;
	RTC_TimeDateTypeDef TempTime1;
	
	for(n=0 ;n<3; n++)
	{
		RTC_WER_Write(RTC_WRITE_ENABLE );	//���RTCд����
		RTC_TimeDate_SetEx(para);			//����RTC
		RTC_WER_Write(RTC_WRITE_DISABLE );		//��RTCд����
		
		Result = RTC_GetRTC(&TempTime1);	//��ȡȷ�����ý��
		if(Result == 0)
		{
			Result = 1;
			for(i=0; i<7; i++)//����һ��, ��ʾ���óɹ�
			{
				if(((uint08*)(&TempTime1))[i] != ((uint08*)(para))[i]) break;
			}
			if(i == 7)
			{
				Result = 0;
				break;
			}
		}
	}
	return Result;
}
