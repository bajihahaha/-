/**
  ******************************************************************************
  * @file    fm33a0xxev_rtc.c
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/

#include "fm33a0xxev_rtc.h"

/** @addtogroup fm33a0xxev_StdPeriph_Driver
  * @{
  */

/** @defgroup RTC 
  * @brief RTC driver modules
  * @{
  */ 

/* RTCдʹ�ܼĴ�����
��CPU��RTCWEд��0xACACACACʱ������CPU��RTC��BCDʱ��Ĵ���д���ֵ����ʱRTCWE��1����CPU��RTCWEд�벻Ϊ0xACACACAC������ֵʱ�ָ�д����,��ʱRTCWE��0�� ��غ��� */

void RTC_WER_Write(uint32_t SetValue)
{
	RTC->WER  = (SetValue );
}



void RTC_WER_RTCWE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RTC->WER = RTC_WRITE_ENABLE;
	}
	else
	{
		RTC->WER = RTC_WRITE_DISABLE;
	}
}

FunState RTC_WER_RTCWE_Getable(void)
{
	if (RTC->WER & (RTC_WER_RTCWE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��У�����ж�ʹ�ܡ�
1���ж�ʹ�ܴ�
0���ж�ʹ�ܽ�ֹ ��غ��� */
void RTC_IER_ADJ_IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RTC->IER |= (RTC_IER_ADJ_IE_Msk);
	}
	else
	{
		RTC->IER &= ~(RTC_IER_ADJ_IE_Msk);
	}
}

FunState RTC_IER_ADJ_IE_Getable(void)
{
	if (RTC->IER & (RTC_IER_ADJ_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �����ж�ʹ�ܡ�
1���ж�ʹ�ܴ�
0���ж�ʹ�ܽ�ֹ ��غ��� */
void RTC_IER_ALARM_IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RTC->IER |= (RTC_IER_ALARM_IE_Msk);
	}
	else
	{
		RTC->IER &= ~(RTC_IER_ALARM_IE_Msk);
	}
}

FunState RTC_IER_ALARM_IE_Getable(void)
{
	if (RTC->IER & (RTC_IER_ALARM_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 1khz�ж�ʹ�ܡ�
1���ж�ʹ�ܴ�
0���ж�ʹ�ܽ�ֹ ��غ��� */
void RTC_IER_1KHZ_IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RTC->IER |= (RTC_IER_1KHZ_IE_Msk);
	}
	else
	{
		RTC->IER &= ~(RTC_IER_1KHZ_IE_Msk);
	}
}

FunState RTC_IER_1KHZ_IE_Getable(void)
{
	if (RTC->IER & (RTC_IER_1KHZ_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 256hz�ж�ʹ�ܡ�
1���ж�ʹ�ܴ�
0���ж�ʹ�ܽ�ֹ ��غ��� */
void RTC_IER_256HZ_IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RTC->IER |= (RTC_IER_256HZ_IE_Msk);
	}
	else
	{
		RTC->IER &= ~(RTC_IER_256HZ_IE_Msk);
	}
}

FunState RTC_IER_256HZ_IE_Getable(void)
{
	if (RTC->IER & (RTC_IER_256HZ_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 64hz�ж�ʹ�ܡ�
1���ж�ʹ�ܴ�
0���ж�ʹ�ܽ�ֹ ��غ��� */
void RTC_IER_64HZ_IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RTC->IER |= (RTC_IER_64HZ_IE_Msk);
	}
	else
	{
		RTC->IER &= ~(RTC_IER_64HZ_IE_Msk);
	}
}

FunState RTC_IER_64HZ_IE_Getable(void)
{
	if (RTC->IER & (RTC_IER_64HZ_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}


/* 16hz�ж�ʹ�ܡ�
1���ж�ʹ�ܴ�
0���ж�ʹ�ܽ�ֹ ��غ��� */
void RTC_IER_16HZ_IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RTC->IER |= (RTC_IER_16HZ_IE_Msk);
	}
	else
	{
		RTC->IER &= ~(RTC_IER_16HZ_IE_Msk);
	}
}

FunState RTC_IER_16HZ_IE_Getable(void)
{
	if (RTC->IER & (RTC_IER_16HZ_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 8hz�ж�ʹ�ܡ�
1���ж�ʹ�ܴ�
0���ж�ʹ�ܽ�ֹ ��غ��� */
void RTC_IER_8HZ_IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RTC->IER |= (RTC_IER_8HZ_IE_Msk);
	}
	else
	{
		RTC->IER &= ~(RTC_IER_8HZ_IE_Msk);
	}
}

FunState RTC_IER_8HZ_IE_Getable(void)
{
	if (RTC->IER & (RTC_IER_8HZ_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 4hz�ж�ʹ�ܡ�
1���ж�ʹ�ܴ�
0���ж�ʹ�ܽ�ֹ ��غ��� */
void RTC_IER_4HZ_IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RTC->IER |= (RTC_IER_4HZ_IE_Msk);
	}
	else
	{
		RTC->IER &= ~(RTC_IER_4HZ_IE_Msk);
	}
}

FunState RTC_IER_4HZ_IE_Getable(void)
{
	if (RTC->IER & (RTC_IER_4HZ_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 2hz�ж�ʹ�ܡ�
1���ж�ʹ�ܴ�
0���ж�ʹ�ܽ�ֹ ��غ��� */
void RTC_IER_2HZ_IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RTC->IER |= (RTC_IER_2HZ_IE_Msk);
	}
	else
	{
		RTC->IER &= ~(RTC_IER_2HZ_IE_Msk);
	}
}

FunState RTC_IER_2HZ_IE_Getable(void)
{
	if (RTC->IER & (RTC_IER_2HZ_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���ж�ʹ�ܡ�
1���ж�ʹ�ܴ�
0���ж�ʹ�ܽ�ֹ ��غ��� */
void RTC_IER_SEC_IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RTC->IER |= (RTC_IER_SEC_IE_Msk);
	}
	else
	{
		RTC->IER &= ~(RTC_IER_SEC_IE_Msk);
	}
}

FunState RTC_IER_SEC_IE_Getable(void)
{
	if (RTC->IER & (RTC_IER_SEC_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���ж�ʹ�ܡ�
1���ж�ʹ�ܴ�
0���ж�ʹ�ܽ�ֹ ��غ��� */
void RTC_IER_MIN_IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RTC->IER |= (RTC_IER_MIN_IE_Msk);
	}
	else
	{
		RTC->IER &= ~(RTC_IER_MIN_IE_Msk);
	}
}

FunState RTC_IER_MIN_IE_Getable(void)
{
	if (RTC->IER & (RTC_IER_MIN_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Сʱ�ж�ʹ�ܡ�
1���ж�ʹ�ܴ�
0���ж�ʹ�ܽ�ֹ ��غ��� */
void RTC_IER_HOUR_IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RTC->IER |= (RTC_IER_HOUR_IE_Msk);
	}
	else
	{
		RTC->IER &= ~(RTC_IER_HOUR_IE_Msk);
	}
}

FunState RTC_IER_HOUR_IE_Getable(void)
{
	if (RTC->IER & (RTC_IER_HOUR_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���ж�ʹ�ܡ�
1���ж�ʹ�ܴ�
0���ж�ʹ�ܽ�ֹ ��غ��� */
void RTC_IER_DATE_IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RTC->IER |= (RTC_IER_DATE_IE_Msk);
	}
	else
	{
		RTC->IER &= ~(RTC_IER_DATE_IE_Msk);
	}
}

FunState RTC_IER_DATE_IE_Getable(void)
{
	if (RTC->IER & (RTC_IER_DATE_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��У�����жϱ�־��д1����
1���ж���λ
0�����жϲ��� ��غ��� */
void RTC_ISR_ADJ_IF_Clr(void)
{
	RTC->ISR = RTC_ISR_ADJ_IF_Msk;
}

FlagStatus RTC_ISR_ADJ_IF_Chk(void)
{
	if (RTC->ISR & RTC_ISR_ADJ_IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* �����жϱ�־��д1����
1���ж���λ
0�����жϲ��� ��غ��� */
void RTC_ISR_ALARM_IF_Clr(void)
{
	RTC->ISR = RTC_ISR_ALARM_IF_Msk;
}

FlagStatus RTC_ISR_ALARM_IF_Chk(void)
{
	if (RTC->ISR & RTC_ISR_ALARM_IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 1khz�жϱ�־��д1����
1���ж���λ
0�����жϲ��� ��غ��� */
void RTC_ISR_1KHZ_IF_Clr(void)
{
	RTC->ISR = RTC_ISR_1KHZ_IF_Msk;
}

FlagStatus RTC_ISR_1KHZ_IF_Chk(void)
{
	if (RTC->ISR & RTC_ISR_1KHZ_IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 256hz�жϱ�־��д1����
1���ж���λ
0�����жϲ��� ��غ��� */
void RTC_ISR_256HZ_IF_Clr(void)
{
	RTC->ISR = RTC_ISR_256HZ_IF_Msk;
}

FlagStatus RTC_ISR_256HZ_IF_Chk(void)
{
	if (RTC->ISR & RTC_ISR_256HZ_IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 64hz�жϱ�־��д1����
1���ж���λ
0�����жϲ��� ��غ��� */
void RTC_ISR_64HZ_IF_Clr(void)
{
	RTC->ISR = RTC_ISR_64HZ_IF_Msk;
}

FlagStatus RTC_ISR_64HZ_IF_Chk(void)
{
	if (RTC->ISR & RTC_ISR_64HZ_IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}


/* 16hz�жϱ�־��д1����
1���ж���λ
0�����жϲ��� ��غ��� */
void RTC_ISR_16HZ_IF_Clr(void)
{
	RTC->ISR = RTC_ISR_16HZ_IF_Msk;
}

FlagStatus RTC_ISR_16HZ_IF_Chk(void)
{
	if (RTC->ISR & RTC_ISR_16HZ_IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 8hz�жϱ�־��д1����
1���ж���λ
0�����жϲ��� ��غ��� */
void RTC_ISR_8HZ_IF_Clr(void)
{
	RTC->ISR = RTC_ISR_8HZ_IF_Msk;
}

FlagStatus RTC_ISR_8HZ_IF_Chk(void)
{
	if (RTC->ISR & RTC_ISR_8HZ_IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 4hz�жϱ�־��д1����
1���ж���λ
0�����жϲ��� ��غ��� */
void RTC_ISR_4HZ_IF_Clr(void)
{
	RTC->ISR = RTC_ISR_4HZ_IF_Msk;
}

FlagStatus RTC_ISR_4HZ_IF_Chk(void)
{
	if (RTC->ISR & RTC_ISR_4HZ_IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 2hz�жϱ�־��д1����
1���ж���λ
0�����жϲ��� ��غ��� */
void RTC_ISR_2HZ_IF_Clr(void)
{
	RTC->ISR = RTC_ISR_2HZ_IF_Msk;
}

FlagStatus RTC_ISR_2HZ_IF_Chk(void)
{
	if (RTC->ISR & RTC_ISR_2HZ_IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ���жϱ�־��д1����
1���ж���λ
0�����жϲ��� ��غ��� */
void RTC_ISR_SEC_IF_Clr(void)
{
	RTC->ISR = RTC_ISR_SEC_IF_Msk;
}

FlagStatus RTC_ISR_SEC_IF_Chk(void)
{
	if (RTC->ISR & RTC_ISR_SEC_IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ���жϱ�־��д1����
1���ж���λ
0�����жϲ��� ��غ��� */
void RTC_ISR_MIN_IF_Clr(void)
{
	RTC->ISR = RTC_ISR_MIN_IF_Msk;
}

FlagStatus RTC_ISR_MIN_IF_Chk(void)
{
	if (RTC->ISR & RTC_ISR_MIN_IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* Сʱ�жϱ�־��д1����
1���ж���λ
0�����жϲ��� ��غ��� */
void RTC_ISR_HOUR_IF_Clr(void)
{
	RTC->ISR = RTC_ISR_HOUR_IF_Msk;
}

FlagStatus RTC_ISR_HOUR_IF_Chk(void)
{
	if (RTC->ISR & RTC_ISR_HOUR_IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ���жϱ�־��д1����
1���ж���λ
0�����жϲ��� ��غ��� */
void RTC_ISR_DATE_IF_Clr(void)
{
	RTC->ISR = RTC_ISR_DATE_IF_Msk;
}

FlagStatus RTC_ISR_DATE_IF_Chk(void)
{
	if (RTC->ISR & RTC_ISR_DATE_IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��ʱ����ֵ��BCD��ʽ�� ��غ��� */
void RTC_BCDSEC_Write(uint32_t SetValue)
{
	RTC->BCDSEC = (SetValue & RTC_BCDSEC_BCDSEC_Msk);
}

uint32_t RTC_BCDSEC_Read(void)
{
	return (RTC->BCDSEC & RTC_BCDSEC_BCDSEC_Msk);
}

/* ����ʱ����ֵ��BCD��ʽ�� ��غ��� */
void RTC_BCDMIN_Write(uint32_t SetValue)
{
	RTC->BCDMIN = (SetValue & RTC_BCDMIN_BCDMIN_Msk);
}

uint32_t RTC_BCDMIN_Read(void)
{
	return (RTC->BCDMIN & RTC_BCDMIN_BCDMIN_Msk);
}

/* Сʱ��ֵ��BCD��ʽ�� ��غ��� */
void RTC_BCDHOUR_Write(uint32_t SetValue)
{
	RTC->BCDHOUR = (SetValue & RTC_BCDHOUR_BCDHOUR_Msk);
}

uint32_t RTC_BCDHOUR_Read(void)
{
	return (RTC->BCDHOUR & RTC_BCDHOUR_BCDHOUR_Msk);
}

/* Сʱ��ֵ��BCD��ʽ�� ��غ��� */
void RTC_BCDDATE_Write(uint32_t SetValue)
{
	RTC->BCDDATE = (SetValue & RTC_BCDDATE_BCDDATE_Msk);
}

uint32_t RTC_BCDDATE_Read(void)
{
	return (RTC->BCDDATE & RTC_BCDDATE_BCDDATE_Msk);
}


/* ����ֵ��BCD��ʽ�� ��غ��� */
void RTC_BCDWEEK_Write(uint32_t SetValue)
{
	RTC->BCDWEEK = (SetValue & RTC_BCDWEEK_BCDWEEK_Msk);
}

uint32_t RTC_BCDWEEK_Read(void)
{
	return (RTC->BCDWEEK & RTC_BCDWEEK_BCDWEEK_Msk);
}

/* ����ֵ��BCD��ʽ�� ��غ��� */
void RTC_BCDMONTH_Write(uint32_t SetValue)
{
	RTC->BCDMONTH = (SetValue & RTC_BCDMONTH_BCDMONTH_Msk);
}

uint32_t RTC_BCDMONTH_Read(void)
{
	return (RTC->BCDMONTH & RTC_BCDMONTH_BCDMONTH_Msk);
}

/* ����ֵ��BCD��ʽ�� ��غ��� */
void RTC_BCDYEAR_Write(uint32_t SetValue)
{
	RTC->BCDYEAR = (SetValue & RTC_BCDYEAR_BCDYEAR_Msk);
}

uint32_t RTC_BCDYEAR_Read(void)
{
	return (RTC->BCDYEAR & RTC_BCDYEAR_BCDYEAR_Msk);
}

/* ���ӹ���ʹ�� (alarm enable)
1��ʹ��Alarm����
0����ֹAlarm���� ��غ��� */
void RTC_ALARM_ALMEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RTC->ALARM |= (RTC_ALARM_ALMEN_Msk);
	}
	else
	{
		RTC->ALARM &= ~(RTC_ALARM_ALMEN_Msk);
	}
}

FunState RTC_ALARM_ALMEN_Getable(void)
{
	if (RTC->ALARM & (RTC_ALARM_ALMEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���ӵ�Сʱ��ֵ�� ��غ��� */
void RTC_ALARM_ALARMHOUR_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RTC->ALARM;
	tmpreg &= ~(RTC_ALARM_ALARMHOUR_Msk);
	tmpreg |= (SetValue & RTC_ALARM_ALARMHOUR_Msk);
	RTC->ALARM = tmpreg;
}

uint32_t RTC_ALARM_ALARMHOUR_Get(void)
{
	return (RTC->ALARM & RTC_ALARM_ALARMHOUR_Msk) >> RTC_ALARM_ALARMHOUR_Pos;
}

/* ���ӵķ���ֵ�� ��غ��� */
void RTC_ALARM_ALARMMIN_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RTC->ALARM;
	tmpreg &= ~(RTC_ALARM_ALARMMIN_Msk);
	tmpreg |= (SetValue & RTC_ALARM_ALARMMIN_Msk);
	RTC->ALARM = tmpreg;
}

uint32_t RTC_ALARM_ALARMMIN_Get(void)
{
	return (RTC->ALARM & RTC_ALARM_ALARMMIN_Msk) >> RTC_ALARM_ALARMMIN_Pos;
}

/* ���ӵ�����ֵ�� ��غ��� */
void RTC_ALARM_ALARMSEC_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RTC->ALARM;
	tmpreg &= ~(RTC_ALARM_ALARMSEC_Msk);
	tmpreg |= (SetValue & RTC_ALARM_ALARMSEC_Msk);
	RTC->ALARM = tmpreg;
}

uint32_t RTC_ALARM_ALARMSEC_Get(void)
{
	return (RTC->ALARM & RTC_ALARM_ALARMSEC_Msk) >> RTC_ALARM_ALARMSEC_Pos;
}

/* Ƶ�����ѡ���źţ�
0000�����PLL��Ƶ�õ��ľ�ȷ1�뷽�� 
0001�����PLL��Ƶ�Ŀɱ�ռ�ձȵľ�ȷ��ʱ�� 
0010��������������λ�źţ��ߵ�ƽ���1s
0011������ּ�������λ�źţ��ߵ�ƽ���1s
0100�����Сʱ��������λ�źţ��ߵ�ƽ���1s
0101��������������λ�źţ��ߵ�ƽ���1s
0110���������ƥ���ź�
0111�����256�뷽���ź�
1000���������PLL��Ƶ�Ŀɱ�ռ�ձȵľ�ȷ��ʱ��
1001������������������λ�ź�
1010����������ּ�������λ�ź�
1011���������Сʱ��������λ�ź�
1100������������������λ�ź�
1101�������������ƥ���ź�
1110���������PLL��Ƶ�ľ�ȷ1s�����ź�
1111�����RTC�ڲ���ʱ�귽�� ��غ��� */
void RTC_TMSEL_Write(uint32_t SetValue)
{
	RTC->TMSEL = (SetValue & RTC_TMSEL_FSEL_Msk);
}

uint32_t RTC_TMSEL_Read(void)
{
	return (RTC->TMSEL & RTC_TMSEL_FSEL_Msk);
}

/* LTBC����������ֵ��ԭ���ʽ�� ��غ��� */
void RTC_ADJUST_Write(uint32_t SetValue)
{
	RTC->ADJUST = (SetValue & RTC_ADJUST_ADJUST_Msk);
}

uint32_t RTC_ADJUST_Read(void)
{
	return (RTC->ADJUST & RTC_ADJUST_ADJUST_Msk);
}

/* LTBC��������
0����ʾ���Ӽ�����ֵ
1����ʾ���ټ�����ֵ ��غ��� */
void RTC_ADSIGN_ADSIGN_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RTC->ADSIGN;
	tmpreg &= ~(RTC_ADSIGN_ADSIGN_Msk);
	tmpreg |= (SetValue & RTC_ADSIGN_ADSIGN_Msk);
	RTC->ADSIGN = tmpreg;
}

uint32_t RTC_ADSIGN_ADSIGN_Get(void)
{
	return (RTC->ADSIGN & RTC_ADSIGN_ADSIGN_Msk);
}

/* �����Уʹ���ź�
0����ʾ��ֹ�����У����
1����ʾʹ�������У���� ��غ��� */
void RTC_VCAL_PR1SEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RTC->VCAL |= (RTC_VCAL_PR1SEN_Msk);
	}
	else
	{
		RTC->VCAL &= ~(RTC_VCAL_PR1SEN_Msk);
	}
}

FunState RTC_VCAL_PR1SEN_Getable(void)
{
	if (RTC->VCAL & (RTC_VCAL_PR1SEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���������
CALSTEP=00/11����Чλ8bit������3.9ms
CALSTEP=01����Чֵ7bit������7.8ms
CALSTEP=10����Чֵ6bit������15.625ms ��غ��� */
void RTC_MSCNT_Write(uint32_t SetValue)
{
	RTC->MSCNT = (SetValue & RTC_MSCNT_MSCNT_Msk);
}

uint32_t RTC_MSCNT_Read(void)
{
	return (RTC->MSCNT & RTC_MSCNT_MSCNT_Msk);
}

/* LTBC��С��У����ѡ��
10��0.06ppm������+/-0.03ppm��
01��0.119ppm������+/-0.06ppm��
00/11��0.238ppm������+/-0.119ppm�� ��غ��� */
void RTC_CALSTEP_CALSTEP_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RTC->CALSTEP;
	tmpreg &= ~(RTC_CALSTEP_CALSTEP_Msk);
	tmpreg |= (SetValue & RTC_CALSTEP_CALSTEP_Msk);
	RTC->CALSTEP = tmpreg;
}

uint32_t RTC_CALSTEP_CALSTEP_Get(void)
{
	return (RTC->CALSTEP & RTC_CALSTEP_CALSTEP_Msk);
}

uint32_t RTC_ADCNT_Read(void)
{
	return (RTC->ADCNT & RTC_ADCNT_ADJCNT_Msk);
}



/* ��������� (sub-second counter register)
��������15.625ms ��غ��� */
uint32_t RTC_SSR_Read(void)
{
	return (RTC->SSR & RTC_SSR_SSR_Msk);
}

/* ��������ʹ�� (sub-second alarm enable)
1��ʹ���������ӹ���
0����ֹ�������ӹ��� ��غ��� */
void RTC_SSA_SSAEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RTC->SSA |= (RTC_SSA_SSAEN_Msk);
	}
	else
	{
		RTC->SSA &= ~(RTC_SSA_SSAEN_Msk);
	}
}

FunState RTC_SSA_SSAEN_Getable(void)
{
	if (RTC->SSA & (RTC_SSA_SSAEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �������� (sub-second alarm)
��SSAEN=1������SSR����ֵ����SS_ALARMʱ���жϱ�־��λ�� ��غ��� */
void RTC_SSA_SS_ALARM_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RTC->SSA;
	tmpreg &= ~(RTC_SSA_SS_ALARM_Msk);
	tmpreg |= (SetValue & RTC_SSA_SS_ALARM_Msk);
	RTC->SSA = tmpreg;
}

uint32_t RTC_SSA_SS_ALARM_Get(void)
{
	return (RTC->SSA & RTC_SSA_SS_ALARM_Msk);
}

/* RTC������ʱ�����ռ�ձȣ�����1�������ڸߵ�ƽ���ȣ���λĬ��ֵ��80ms�ߵ�ƽ ��غ��� */
void RTC_DTR_Write(uint32_t SetValue)
{
	RTC->DTR = (SetValue & RTC_DTR_DUTY_Msk);
}

uint32_t RTC_DTR_Read(void)
{
	return (RTC->DTR & RTC_DTR_DUTY_Msk);
}

/* RTCʱ�Ӻ�����ʹ�� (RTC_A Enable)
1��ʹ��RTC��ʱ
0��ֹͣRTC��ʱ

�˼Ĵ��������ſ�LSCLK���룬������㣬RTC������ֹͣ��ʱ�����������У���ܲ��ܴ˼Ĵ���Ӱ�졣 ��غ��� */
void RTC_CR_RTC_EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RTC->CR |= (RTC_CR_RTC_EN_Msk);
	}
	else
	{
		RTC->CR &= ~(RTC_CR_RTC_EN_Msk);
	}
}

FunState RTC_CR_RTC_EN_Getable(void)
{
	if (RTC->CR & (RTC_CR_RTC_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}


void RTC_AlarmTime_SetEx(RTC_AlarmTmieTypeDef* para)
{
	RTC_ALARM_ALARMSEC_Set(((uint32_t)para->Second<<RTC_ALARM_ALARMSEC_Pos));
	RTC_ALARM_ALARMMIN_Set(((uint32_t)para->Minute<<RTC_ALARM_ALARMMIN_Pos));
	RTC_ALARM_ALARMHOUR_Set(((uint32_t)para->Hour<<RTC_ALARM_ALARMHOUR_Pos));
}


/********************************
 RTC����ʱ�亯��
����:����ʱ�䣬�룬�֣�ʱ���죬�£��꣬�ܣ�BCD��ʽ
���룺Ҫ�����õ�ʱ������
		
********************************/
void RTC_TimeDate_SetEx(RTC_TimeDateTypeDef* para)
{
	RTC_BCDSEC_Write((uint32_t)para->Second);
	RTC_BCDMIN_Write((uint32_t)para->Minute);
	RTC_BCDHOUR_Write((uint32_t)para->Hour);
	RTC_BCDDATE_Write((uint32_t)para->Date);
	RTC_BCDMONTH_Write((uint32_t)para->Month);
	RTC_BCDYEAR_Write((uint32_t)para->Year);
	RTC_BCDWEEK_Write((uint32_t)para->Week);	
}

/********************************
 RTC��ȡʱ�亯��
����:��ȡʱ�䣬�룬�֣�ʱ���죬�£��꣬�ܣ�BCD��ʽ
�������ȡ��ǰʱ�䣬����Ϊ����
		
********************************/
void RTC_TimeDate_GetEx(RTC_TimeDateTypeDef* para)
{
	para->Second = RTC_BCDSEC_Read();
	para->Minute = RTC_BCDMIN_Read();
	para->Hour = RTC_BCDHOUR_Read();
	para->Date = RTC_BCDDATE_Read();
	para->Month = RTC_BCDMONTH_Read();
	para->Year = RTC_BCDYEAR_Read();
	para->Week = RTC_BCDWEEK_Read();	
}






void RTC_Deinit(void)
{
	//RTC->WER = 0x00000000;
	//RTC->IER = 0x00000000;
	//RTC->ISR = 0x00000000;
	//RTC->BCDSEC = 0x00000000;
	//RTC->BCDMIN = 0x00000000;
	//RTC->BCDHOUR = 0x00000000;
	//RTC->BCDWEEK = 0x00000000;
	//RTC->BCDMONTH = 0x00000000;
	//RTC->BCDYEAR = 0x00000000;
	//RTC->ALARM = 0x00000000;
	//RTC->TMSEL = 0x00000000;
	//RTC->ADJUST = 0x00000000;
	//RTC->ADSIGN = 0x00000000;
	//RTC->VCAL = 0x00000000;
	//RTC->MSCNT = 0x00000000;
	//RTC->CALSTEP = 0x00000000;
	//RTC->ADCNT = ;
	//RTC->SSR = 0x00000000;
	//RTC->SSA = 0x00000000;
	//RTC->DTR = 0x00000001;
	//RTC->CR = 0x00000000;
}

/******END OF FILE****/
