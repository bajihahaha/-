#include "define_all.h" 
#include "rtc.h"

//RTC初始化函数
void RTC_Init(void)
{
		CMU_PERCLK_SetableEx(RTCCLK, ENABLE);  //RTC总线时钟使能
		RTC_VCAL_PR1SEN_Setable(DISABLE);		//虚拟调校使能关闭

		RTC_ISR_SEC_IF_Clr();		//清除秒中断标志											
		RTC_IER_SEC_IE_Setable(DISABLE);//RTC秒中断	
		
		NVIC_DisableIRQ(RTC_IRQn);				//NVIC中断控制器配置
		NVIC_SetPriority(RTC_IRQn,2);
		NVIC_EnableIRQ(RTC_IRQn);		
}

//设置RTC定时
void RTC_Alarm(RTC_AlarmTmieTypeDef TempAlarmTime)
{
		RTC_ALARM_ALMEN_Setable(DISABLE);//关闭闹钟功能使能
		RTC_IER_ALARM_IE_Setable(DISABLE);//关闭闹钟中断
		RTC_AlarmTime_SetEx(&TempAlarmTime);	//设置闹钟时间	
		RTC_ISR_ALARM_IF_Clr();		//清除闹钟中断标志											
		RTC_IER_ALARM_IE_Setable(ENABLE);//打开闹钟中断	
		RTC_ALARM_ALMEN_Setable(ENABLE);//闹钟功能使能
		RTC_CR_RTC_EN_Setable(ENABLE);
}


//读取RTC实时时间
uint08 RTC_GetRTC(RTC_TimeDateTypeDef* para)
{
	uint08 n, i;
	uint08 Result = 1;

	RTC_TimeDateTypeDef TempTime1,TempTime2;
	
	for(n=0 ;n<3; n++)
	{
		RTC_TimeDate_GetEx(&TempTime1);//读一次时间
		RTC_TimeDate_GetEx(&TempTime2);//再读一次时间
		
		for(i=0; i<7; i++)//两者一致, 表示读取成功
		{
			if(((uint08*)(&TempTime1))[i] != ((uint08*)(&TempTime2))[i]) break;
		}
		if(i == 7)
		{
			Result = 0;
			memcpy((uint08*)(para), (uint08*)(&TempTime1), 7);//读取正确则更新新的时间		
			break;
		}
	}
	return Result;
}

//设置RTC的实时时间
uint08 RTC_SetRTC(RTC_TimeDateTypeDef* para)
{
	uint08 n, i;
	uint08 Result;
	RTC_TimeDateTypeDef TempTime1;
	
	for(n=0 ;n<3; n++)
	{
		RTC_WER_Write(RTC_WRITE_ENABLE );	//解除RTC写保护
		RTC_TimeDate_SetEx(para);			//设置RTC
		RTC_WER_Write(RTC_WRITE_DISABLE );		//打开RTC写保护
		
		Result = RTC_GetRTC(&TempTime1);	//读取确认设置结果
		if(Result == 0)
		{
			Result = 1;
			for(i=0; i<7; i++)//两者一致, 表示设置成功
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
