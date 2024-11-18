/**
  ******************************************************************************
  * @file    fm33a0xxev_rtc.h
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file contains all the functions prototypes for the RTC firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33A0XXEV_RTC_H
#define __FM33A0XXEV_RTC_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33A0XXEV.h" 
  
typedef struct
{       
	uint8_t			Year;		/*!<RTC ��*/
	uint8_t			Month;		/*!<RTC ��*/
	uint8_t			Date;		/*!<RTC ��*/	
	uint8_t			Hour;		/*!<RTC ʱ*/
	uint8_t			Minute;		/*!<RTC ��*/	
	uint8_t			Second;		/*!<RTC ��*/			
	uint8_t			Week;		/*!<RTC ��*/	

}RTC_TimeDateTypeDef,RTC_StampTmieTypeDef;

typedef struct
{     
	uint8_t			Hour;		/*!<RTC���� ʱ*/		
	uint8_t			Minute;		/*!<RTC���� ��*/
	uint8_t			Second;		/*!<RTC���� ��*/

}RTC_AlarmTmieTypeDef;	 



#define RTC_WRITE_ENABLE    ((uint32_t)0xACACACAC)
#define RTC_WRITE_DISABLE   ((uint32_t)0x55AA55AA)	 
	 
#define	RTC_WER_RTCWE_Pos	0	/* RTCдʹ�ܼĴ�����
��CPU��RTCWEд��0xACACACACʱ������CPU��RTC��BCDʱ��Ĵ���д���ֵ����ʱRTCWE��1����CPU��RTCWEд�벻Ϊ0xACACACAC������ֵʱ�ָ�д����,��ʱRTCWE��0�� */
#define	RTC_WER_RTCWE_Msk	(0x1U << RTC_WER_RTCWE_Pos)

#define	RTC_IER_ADJ_IE_Pos	12	/* ��У�����ж�ʹ�ܡ�
1���ж�ʹ�ܴ�
0���ж�ʹ�ܽ�ֹ */
#define	RTC_IER_ADJ_IE_Msk	(0x1U << RTC_IER_ADJ_IE_Pos)
	/* �ж�ʹ�ܴ� */
	/* �ж�ʹ�ܽ�ֹ */

#define	RTC_IER_ALARM_IE_Pos	11	/* �����ж�ʹ�ܡ�
1���ж�ʹ�ܴ�
0���ж�ʹ�ܽ�ֹ */
#define	RTC_IER_ALARM_IE_Msk	(0x1U << RTC_IER_ALARM_IE_Pos)
	/* �ж�ʹ�ܴ� */
	/* �ж�ʹ�ܽ�ֹ */

#define	RTC_IER_1KHZ_IE_Pos	10	/* 1khz�ж�ʹ�ܡ�
1���ж�ʹ�ܴ�
0���ж�ʹ�ܽ�ֹ */
#define	RTC_IER_1KHZ_IE_Msk	(0x1U << RTC_IER_1KHZ_IE_Pos)
	/* �ж�ʹ�ܴ� */
	/* �ж�ʹ�ܽ�ֹ */

#define	RTC_IER_256HZ_IE_Pos	9	/* 256hz�ж�ʹ�ܡ�
1���ж�ʹ�ܴ�
0���ж�ʹ�ܽ�ֹ */
#define	RTC_IER_256HZ_IE_Msk	(0x1U << RTC_IER_256HZ_IE_Pos)
	/* �ж�ʹ�ܴ� */
	/* �ж�ʹ�ܽ�ֹ */

#define	RTC_IER_64HZ_IE_Pos	8	/* 64hz�ж�ʹ�ܡ�
1���ж�ʹ�ܴ�
0���ж�ʹ�ܽ�ֹ */
#define	RTC_IER_64HZ_IE_Msk	(0x1U << RTC_IER_64HZ_IE_Pos)
	/* �ж�ʹ�ܴ� */
	/* �ж�ʹ�ܽ�ֹ */
	
#define	RTC_IER_16HZ_IE_Pos	7	/* 16hz�ж�ʹ�ܡ�
1���ж�ʹ�ܴ�
0���ж�ʹ�ܽ�ֹ */
#define	RTC_IER_16HZ_IE_Msk	(0x1U << RTC_IER_16HZ_IE_Pos)
	/* �ж�ʹ�ܴ� */
	/* �ж�ʹ�ܽ�ֹ */

#define	RTC_IER_8HZ_IE_Pos	6	/* 8hz�ж�ʹ�ܡ�
1���ж�ʹ�ܴ�
0���ж�ʹ�ܽ�ֹ */
#define	RTC_IER_8HZ_IE_Msk	(0x1U << RTC_IER_8HZ_IE_Pos)
	/* �ж�ʹ�ܴ� */
	/* �ж�ʹ�ܽ�ֹ */

#define	RTC_IER_4HZ_IE_Pos	5	/* 4hz�ж�ʹ�ܡ�
1���ж�ʹ�ܴ�
0���ж�ʹ�ܽ�ֹ */
#define	RTC_IER_4HZ_IE_Msk	(0x1U << RTC_IER_4HZ_IE_Pos)
	/* �ж�ʹ�ܴ� */
	/* �ж�ʹ�ܽ�ֹ */

#define	RTC_IER_2HZ_IE_Pos	4	/* 2hz�ж�ʹ�ܡ�
1���ж�ʹ�ܴ�
0���ж�ʹ�ܽ�ֹ */
#define	RTC_IER_2HZ_IE_Msk	(0x1U << RTC_IER_2HZ_IE_Pos)
	/* �ж�ʹ�ܴ� */
	/* �ж�ʹ�ܽ�ֹ */

#define	RTC_IER_SEC_IE_Pos	3	/* ���ж�ʹ�ܡ�
1���ж�ʹ�ܴ�
0���ж�ʹ�ܽ�ֹ */
#define	RTC_IER_SEC_IE_Msk	(0x1U << RTC_IER_SEC_IE_Pos)
	/* �ж�ʹ�ܴ� */
	/* �ж�ʹ�ܽ�ֹ */

#define	RTC_IER_MIN_IE_Pos	2	/* ���ж�ʹ�ܡ�
1���ж�ʹ�ܴ�
0���ж�ʹ�ܽ�ֹ */
#define	RTC_IER_MIN_IE_Msk	(0x1U << RTC_IER_MIN_IE_Pos)
	/* �ж�ʹ�ܴ� */
	/* �ж�ʹ�ܽ�ֹ */

#define	RTC_IER_HOUR_IE_Pos	1	/* Сʱ�ж�ʹ�ܡ�
1���ж�ʹ�ܴ�
0���ж�ʹ�ܽ�ֹ */
#define	RTC_IER_HOUR_IE_Msk	(0x1U << RTC_IER_HOUR_IE_Pos)
	/* �ж�ʹ�ܴ� */
	/* �ж�ʹ�ܽ�ֹ */

#define	RTC_IER_DATE_IE_Pos	0	/* ���ж�ʹ�ܡ�
1���ж�ʹ�ܴ�
0���ж�ʹ�ܽ�ֹ */
#define	RTC_IER_DATE_IE_Msk	(0x1U << RTC_IER_DATE_IE_Pos)
	/* �ж�ʹ�ܴ� */
	/* �ж�ʹ�ܽ�ֹ */

#define	RTC_ISR_ADJ_IF_Pos	12	/* ��У�����жϱ�־��д1����
1���ж���λ
0�����жϲ��� */
#define	RTC_ISR_ADJ_IF_Msk	(0x1U << RTC_ISR_ADJ_IF_Pos)

#define	RTC_ISR_ALARM_IF_Pos	11	/* �����жϱ�־��д1����
1���ж���λ
0�����жϲ��� */
#define	RTC_ISR_ALARM_IF_Msk	(0x1U << RTC_ISR_ALARM_IF_Pos)

#define	RTC_ISR_1KHZ_IF_Pos	10	/* 1khz�жϱ�־��д1����
1���ж���λ
0�����жϲ��� */
#define	RTC_ISR_1KHZ_IF_Msk	(0x1U << RTC_ISR_1KHZ_IF_Pos)

#define	RTC_ISR_256HZ_IF_Pos	9	/* 256hz�жϱ�־��д1����
1���ж���λ
0�����жϲ��� */
#define	RTC_ISR_256HZ_IF_Msk	(0x1U << RTC_ISR_256HZ_IF_Pos)


#define	RTC_ISR_64HZ_IF_Pos	8	/* 64hz�жϱ�־��д1����
1���ж���λ
0�����жϲ��� */
#define	RTC_ISR_64HZ_IF_Msk	(0x1U << RTC_ISR_64HZ_IF_Pos)


#define	RTC_ISR_16HZ_IF_Pos	7	/* 16hz�жϱ�־��д1����
1���ж���λ
0�����жϲ��� */
#define	RTC_ISR_16HZ_IF_Msk	(0x1U << RTC_ISR_16HZ_IF_Pos)

#define	RTC_ISR_8HZ_IF_Pos	6	/* 8hz�жϱ�־��д1����
1���ж���λ
0�����жϲ��� */
#define	RTC_ISR_8HZ_IF_Msk	(0x1U << RTC_ISR_8HZ_IF_Pos)

#define	RTC_ISR_4HZ_IF_Pos	5	/* 4hz�жϱ�־��д1����
1���ж���λ
0�����жϲ��� */
#define	RTC_ISR_4HZ_IF_Msk	(0x1U << RTC_ISR_4HZ_IF_Pos)

#define	RTC_ISR_2HZ_IF_Pos	4	/* 2hz�жϱ�־��д1����
1���ж���λ
0�����жϲ��� */
#define	RTC_ISR_2HZ_IF_Msk	(0x1U << RTC_ISR_2HZ_IF_Pos)

#define	RTC_ISR_SEC_IF_Pos	3	/* ���жϱ�־��д1����
1���ж���λ
0�����жϲ��� */
#define	RTC_ISR_SEC_IF_Msk	(0x1U << RTC_ISR_SEC_IF_Pos)

#define	RTC_ISR_MIN_IF_Pos	2	/* ���жϱ�־��д1����
1���ж���λ
0�����жϲ��� */
#define	RTC_ISR_MIN_IF_Msk	(0x1U << RTC_ISR_MIN_IF_Pos)

#define	RTC_ISR_HOUR_IF_Pos	1	/* Сʱ�жϱ�־��д1����
1���ж���λ
0�����жϲ��� */
#define	RTC_ISR_HOUR_IF_Msk	(0x1U << RTC_ISR_HOUR_IF_Pos)

#define	RTC_ISR_DATE_IF_Pos	0	/* ���жϱ�־��д1����
1���ж���λ
0�����жϲ��� */
#define	RTC_ISR_DATE_IF_Msk	(0x1U << RTC_ISR_DATE_IF_Pos)

#define	RTC_BCDSEC_BCDSEC_Pos	0	/* ��ʱ����ֵ��BCD��ʽ�� */
#define	RTC_BCDSEC_BCDSEC_Msk	(0x7fU << RTC_BCDSEC_BCDSEC_Pos)

#define	RTC_BCDMIN_BCDMIN_Pos	0	/* ����ʱ����ֵ��BCD��ʽ�� */
#define	RTC_BCDMIN_BCDMIN_Msk	(0x7fU << RTC_BCDMIN_BCDMIN_Pos)

#define	RTC_BCDHOUR_BCDHOUR_Pos	0	/* Сʱ��ֵ��BCD��ʽ�� */
#define	RTC_BCDHOUR_BCDHOUR_Msk	(0x3fU << RTC_BCDHOUR_BCDHOUR_Pos)

#define	RTC_BCDDATE_BCDDATE_Pos	0	/* Сʱ��ֵ��BCD��ʽ�� */
#define	RTC_BCDDATE_BCDDATE_Msk	(0x3fU << RTC_BCDDATE_BCDDATE_Pos)

#define	RTC_BCDWEEK_BCDWEEK_Pos	0	/* ����ֵ��BCD��ʽ�� */
#define	RTC_BCDWEEK_BCDWEEK_Msk	(0x7U << RTC_BCDWEEK_BCDWEEK_Pos)

#define	RTC_BCDMONTH_BCDMONTH_Pos	0	/* ����ֵ��BCD��ʽ�� */
#define	RTC_BCDMONTH_BCDMONTH_Msk	(0x1fU << RTC_BCDMONTH_BCDMONTH_Pos)

#define	RTC_BCDYEAR_BCDYEAR_Pos	0	/* ����ֵ��BCD��ʽ�� */
#define	RTC_BCDYEAR_BCDYEAR_Msk	(0xffU << RTC_BCDYEAR_BCDYEAR_Pos)

#define	RTC_ALARM_ALMEN_Pos	31	/* ���ӹ���ʹ�� (alarm enable)
1��ʹ��Alarm����
0����ֹAlarm���� */
#define	RTC_ALARM_ALMEN_Msk	(0x1U << RTC_ALARM_ALMEN_Pos)
	/* ʹ��Alarm���� */
	/* ��ֹAlarm���� */

#define	RTC_ALARM_ALARMHOUR_Pos	16	/* ���ӵ�Сʱ��ֵ�� */
#define	RTC_ALARM_ALARMHOUR_Msk	(0x3fU << RTC_ALARM_ALARMHOUR_Pos)

#define	RTC_ALARM_ALARMMIN_Pos	8	/* ���ӵķ���ֵ�� */
#define	RTC_ALARM_ALARMMIN_Msk	(0x7fU << RTC_ALARM_ALARMMIN_Pos)

#define	RTC_ALARM_ALARMSEC_Pos	0	/* ���ӵ�����ֵ�� */
#define	RTC_ALARM_ALARMSEC_Msk	(0x7fU << RTC_ALARM_ALARMSEC_Pos)

#define	RTC_TMSEL_FSEL_Pos	0	/* Ƶ�����ѡ���źţ�
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
1111�����RTC�ڲ���ʱ�귽�� */
#define	RTC_TMSEL_FSEL_Msk	        (0xfU << RTC_TMSEL_FSEL_Pos)
#define	RTC_TMSEL_FSEL_PLL1HZ    	(0x0U << RTC_TMSEL_FSEL_Pos)// ���PLL��Ƶ�õ��ľ�ȷ1�뷽�� 
#define	RTC_TMSEL_FSEL_PLLD1HZ   	(0x1U << RTC_TMSEL_FSEL_Pos)//���PLL��Ƶ�Ŀɱ�ռ�ձȵľ�ȷ��ʱ�� 
#define	RTC_TMSEL_FSEL_SECOND    	(0x2U << RTC_TMSEL_FSEL_Pos)	/* 4��b0010��������������λ�źţ��ߵ�ƽ���1s */
#define	RTC_TMSEL_FSEL_MINUTE    	(0x3U << RTC_TMSEL_FSEL_Pos)	/* 4��b0011������ּ�������λ�źţ��ߵ�ƽ���1s */
#define	RTC_TMSEL_FSEL_HOUR	      (0x4U << RTC_TMSEL_FSEL_Pos)	/* 4��b0100�����Сʱ��������λ�źţ��ߵ�ƽ���1s */
#define	RTC_TMSEL_FSEL_DAY	        (0x5U << RTC_TMSEL_FSEL_Pos)	/* 4��b0101��������������λ�źţ��ߵ�ƽ���1s */
#define	RTC_TMSEL_FSEL_ALARM	      (0x6U << RTC_TMSEL_FSEL_Pos)	/* 4��b0110���������ƥ���ź� */
#define	RTC_TMSEL_FSEL_256S	      (0x7U << RTC_TMSEL_FSEL_Pos)	/* 4��b0111�����128�뷽���ź� */
#define	RTC_TMSEL_FSEL_PLLD1HZREV	(0x8U << RTC_TMSEL_FSEL_Pos)	/* 4��b1000���������PLL��Ƶ�ĸߵ�ƽ���80ms����ʱ�� */
#define	RTC_TMSEL_FSEL_SECONDREV	  (0x9U << RTC_TMSEL_FSEL_Pos)	/* 4��b1001������������������λ�ź� */
#define	RTC_TMSEL_FSEL_MINUTEREV	  (0xaU << RTC_TMSEL_FSEL_Pos)	/* 4��b1010����������ּ�������λ�ź� */
#define	RTC_TMSEL_FSEL_HOURREV	    (0xbU << RTC_TMSEL_FSEL_Pos)	/* 4��b1011���������Сʱ��������λ�ź� */
#define	RTC_TMSEL_FSEL_DAYREV	    (0xcU << RTC_TMSEL_FSEL_Pos)	/* 4��b1100������������������λ�ź� */
#define	RTC_TMSEL_FSEL_ALARMREV	  (0xdU << RTC_TMSEL_FSEL_Pos)	/* 4��b1101�������������ƥ���ź� */
#define	RTC_TMSEL_FSEL_PLL1HZREV	  (0xeU << RTC_TMSEL_FSEL_Pos)	/* 4��b1110���������PLL��Ƶ�ľ�ȷ1s�����ź� */
#define	RTC_TMSEL_FSEL_SECONDRUN	  (0xfU << RTC_TMSEL_FSEL_Pos)	/* 4��b1111�����RTC�ڲ���ʱ�귽�� */





#define	RTC_ADJUST_ADJUST_Pos	0	/* LTBC����������ֵ��ԭ���ʽ�� */
#define	RTC_ADJUST_ADJUST_Msk	(0x1fffU << RTC_ADJUST_ADJUST_Pos)

#define	RTC_ADSIGN_ADSIGN_Pos	0	/* LTBC��������
0����ʾ���Ӽ�����ֵ
1����ʾ���ټ�����ֵ */
#define	RTC_ADSIGN_ADSIGN_Msk	(0x1U << RTC_ADSIGN_ADSIGN_Pos)
#define	RTC_ADSIGN_ADSIGN_INCREASE	(0x0U << RTC_ADSIGN_ADSIGN_Pos)	/* ��ʾ���Ӽ�����ֵ */
#define	RTC_ADSIGN_ADSIGN_DECREASE	(0x1U << RTC_ADSIGN_ADSIGN_Pos)	/* ��ʾ���ټ�����ֵ */

#define	RTC_VCAL_PR1SEN_Pos	0	/* �����Уʹ���ź�
0����ʾ��ֹ�����У����
1����ʾʹ�������У���� */
#define	RTC_VCAL_PR1SEN_Msk	(0x1U << RTC_VCAL_PR1SEN_Pos)
	/* ��ʾ��ֹ�����У���� */
	/* ��ʾʹ�������У���� */

#define	RTC_MSCNT_MSCNT_Pos	0	/* ���������
CALSTEP=00/11����Чλ8bit������3.9ms
CALSTEP=01����Чֵ7bit������7.8ms
CALSTEP=10����Чֵ6bit������15.625ms */
#define	RTC_MSCNT_MSCNT_Msk	(0xffU << RTC_MSCNT_MSCNT_Pos)

#define	RTC_CALSTEP_CALSTEP_Pos	0	/* LTBC��С��У����ѡ��
10��0.06ppm������+/-0.03ppm��
01��0.119ppm������+/-0.06ppm��
00/11��0.238ppm������+/-0.119ppm�� */
#define	RTC_CALSTEP_CALSTEP_Msk	(0x1U << RTC_CALSTEP_CALSTEP_Pos)
#define	RTC_CALSTEP_CALSTEP_006PPM	(0x2U << RTC_CALSTEP_CALSTEP_Pos)	/* 0.06ppm������+/-0.03ppm�� */
#define	RTC_CALSTEP_CALSTEP_0119PPM	(0x1U << RTC_CALSTEP_CALSTEP_Pos)	/* 0.119ppm������+/-0.06ppm�� */
#define	RTC_CALSTEP_CALSTEP_0238PPM	(0x0U << RTC_CALSTEP_CALSTEP_Pos)	/* 0.238ppm������+/-0.119ppm�� */

#define	RTC_ADCNT_ADJCNT_Pos	0
#define	RTC_ADCNT_ADJCNT_Msk	(0x1ffU << RTC_ADCNT_ADJCNT_Pos)

#define	RTC_SSR_SSR_Pos	0	/* ��������� (sub-second counter register)
��������15.625ms */
#define	RTC_SSR_SSR_Msk	(0x3fU << RTC_SSR_SSR_Pos)

#define	RTC_SSA_SSAEN_Pos	7	/* ��������ʹ�� (sub-second alarm enable)
1��ʹ���������ӹ���
0����ֹ�������ӹ��� */
#define	RTC_SSA_SSAEN_Msk	(0x1U << RTC_SSA_SSAEN_Pos)
	/* ʹ���������ӹ��� */
	/* ��ֹ�������ӹ��� */

#define	RTC_SSA_SS_ALARM_Pos	0	/* �������� (sub-second alarm)
��SSAEN=1������SSR����ֵ����SS_ALARMʱ���жϱ�־��λ�� */
#define	RTC_SSA_SS_ALARM_Msk	(0x3fU << RTC_SSA_SS_ALARM_Pos)

#define	RTC_DTR_DUTY_Pos	0	/* RTC_A������ʱ�����ռ�ձȣ�����1�������ڸߵ�ƽ���ȣ���λĬ��ֵ��80ms�ߵ�ƽ */
#define	RTC_DTR_DUTY_Msk	(0x1ffffffU << RTC_DTR_DUTY_Pos)

#define	RTC_CR_RTC_EN_Pos	0	/* RTC_Aʱ�Ӻ�����ʹ�� (RTC_A Enable)
1��ʹ��RTC��ʱ
0��ֹͣRTC��ʱ

�˼Ĵ��������ſ�LSCLK���룬������㣬RTC������ֹͣ��ʱ�����������У���ܲ��ܴ˼Ĵ���Ӱ�졣 */
#define	RTC_CR_RTC_EN_Msk	(0x1U << RTC_CR_RTC_EN_Pos)
	/* ʹ��RTC��ʱ */
	/* ֹͣRTC��ʱ */
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void RTC_Deinit(void);

/* RTCдʹ�ܼĴ�����
��CPU��RTCWEд��0xACACACACʱ������CPU��RTC��BCDʱ��Ĵ���д���ֵ����ʱRTCWE��1����CPU��RTCWEд�벻Ϊ0xACACACAC������ֵʱ�ָ�д����,��ʱRTCWE��0�� ��غ��� */


extern void RTC_TimeDate_SetEx(RTC_TimeDateTypeDef* para);
extern void RTC_TimeDate_GetEx(RTC_TimeDateTypeDef* para);

extern void RTC_WER_Write(uint32_t SetValue);
extern void RTC_WER_RTCWE_Setable(FunState NewState);
extern FunState RTC_WER_RTCWE_Getable(void);

/* ��У�����ж�ʹ�ܡ�
1���ж�ʹ�ܴ�
0���ж�ʹ�ܽ�ֹ ��غ��� */
extern void RTC_IER_ADJ_IE_Setable(FunState NewState);
extern FunState RTC_IER_ADJ_IE_Getable(void);

/* �����ж�ʹ�ܡ�
1���ж�ʹ�ܴ�
0���ж�ʹ�ܽ�ֹ ��غ��� */
extern void RTC_IER_ALARM_IE_Setable(FunState NewState);
extern FunState RTC_IER_ALARM_IE_Getable(void);

/* 1khz�ж�ʹ�ܡ�
1���ж�ʹ�ܴ�
0���ж�ʹ�ܽ�ֹ ��غ��� */
extern void RTC_IER_1KHZ_IE_Setable(FunState NewState);
extern FunState RTC_IER_1KHZ_IE_Getable(void);

/* 256hz�ж�ʹ�ܡ�
1���ж�ʹ�ܴ�
0���ж�ʹ�ܽ�ֹ ��غ��� */
extern void RTC_IER_256HZ_IE_Setable(FunState NewState);
extern FunState RTC_IER_256HZ_IE_Getable(void);

/* 64hz�ж�ʹ�ܡ�
1���ж�ʹ�ܴ�
0���ж�ʹ�ܽ�ֹ ��غ��� */
extern void RTC_IER_64HZ_IE_Setable(FunState NewState);
extern FunState RTC_IER_64HZ_IE_Getable(void);

/* 16hz�ж�ʹ�ܡ�
1���ж�ʹ�ܴ�
0���ж�ʹ�ܽ�ֹ ��غ��� */
extern void RTC_IER_16HZ_IE_Setable(FunState NewState);
extern FunState RTC_IER_16HZ_IE_Getable(void);

/* 8hz�ж�ʹ�ܡ�
1���ж�ʹ�ܴ�
0���ж�ʹ�ܽ�ֹ ��غ��� */
extern void RTC_IER_8HZ_IE_Setable(FunState NewState);
extern FunState RTC_IER_8HZ_IE_Getable(void);

/* 4hz�ж�ʹ�ܡ�
1���ж�ʹ�ܴ�
0���ж�ʹ�ܽ�ֹ ��غ��� */
extern void RTC_IER_4HZ_IE_Setable(FunState NewState);
extern FunState RTC_IER_4HZ_IE_Getable(void);

/* 2hz�ж�ʹ�ܡ�
1���ж�ʹ�ܴ�
0���ж�ʹ�ܽ�ֹ ��غ��� */
extern void RTC_IER_2HZ_IE_Setable(FunState NewState);
extern FunState RTC_IER_2HZ_IE_Getable(void);

/* ���ж�ʹ�ܡ�
1���ж�ʹ�ܴ�
0���ж�ʹ�ܽ�ֹ ��غ��� */
extern void RTC_IER_SEC_IE_Setable(FunState NewState);
extern FunState RTC_IER_SEC_IE_Getable(void);

/* ���ж�ʹ�ܡ�
1���ж�ʹ�ܴ�
0���ж�ʹ�ܽ�ֹ ��غ��� */
extern void RTC_IER_MIN_IE_Setable(FunState NewState);
extern FunState RTC_IER_MIN_IE_Getable(void);

/* Сʱ�ж�ʹ�ܡ�
1���ж�ʹ�ܴ�
0���ж�ʹ�ܽ�ֹ ��غ��� */
extern void RTC_IER_HOUR_IE_Setable(FunState NewState);
extern FunState RTC_IER_HOUR_IE_Getable(void);

/* ���ж�ʹ�ܡ�
1���ж�ʹ�ܴ�
0���ж�ʹ�ܽ�ֹ ��غ��� */
extern void RTC_IER_DATE_IE_Setable(FunState NewState);
extern FunState RTC_IER_DATE_IE_Getable(void);

/* ��У�����жϱ�־��д1����
1���ж���λ
0�����жϲ��� ��غ��� */
extern void RTC_ISR_ADJ_IF_Clr(void);
extern FlagStatus RTC_ISR_ADJ_IF_Chk(void);

/* �����жϱ�־��д1����
1���ж���λ
0�����жϲ��� ��غ��� */
extern void RTC_ISR_ALARM_IF_Clr(void);
extern FlagStatus RTC_ISR_ALARM_IF_Chk(void);

/* 1khz�жϱ�־��д1����
1���ж���λ
0�����жϲ��� ��غ��� */
extern void RTC_ISR_1KHZ_IF_Clr(void);
extern FlagStatus RTC_ISR_1KHZ_IF_Chk(void);

/* 256hz�жϱ�־��д1����
1���ж���λ
0�����жϲ��� ��غ��� */
extern void RTC_ISR_256HZ_IF_Clr(void);
extern FlagStatus RTC_ISR_256HZ_IF_Chk(void);

/* 64hz�жϱ�־��д1����
1���ж���λ
0�����жϲ��� ��غ��� */
extern void RTC_ISR_64HZ_IF_Clr(void);
extern FlagStatus RTC_ISR_64HZ_IF_Chk(void);

/* 16hz�жϱ�־��д1����
1���ж���λ
0�����жϲ��� ��غ��� */
extern void RTC_ISR_16HZ_IF_Clr(void);
extern FlagStatus RTC_ISR_16HZ_IF_Chk(void);

/* 8hz�жϱ�־��д1����
1���ж���λ
0�����жϲ��� ��غ��� */
extern void RTC_ISR_8HZ_IF_Clr(void);
extern FlagStatus RTC_ISR_8HZ_IF_Chk(void);

/* 4hz�жϱ�־��д1����
1���ж���λ
0�����жϲ��� ��غ��� */
extern void RTC_ISR_4HZ_IF_Clr(void);
extern FlagStatus RTC_ISR_4HZ_IF_Chk(void);

/* 2hz�жϱ�־��д1����
1���ж���λ
0�����жϲ��� ��غ��� */
extern void RTC_ISR_2HZ_IF_Clr(void);
extern FlagStatus RTC_ISR_2HZ_IF_Chk(void);

/* ���жϱ�־��д1����
1���ж���λ
0�����жϲ��� ��غ��� */
extern void RTC_ISR_SEC_IF_Clr(void);
extern FlagStatus RTC_ISR_SEC_IF_Chk(void);

/* ���жϱ�־��д1����
1���ж���λ
0�����жϲ��� ��غ��� */
extern void RTC_ISR_MIN_IF_Clr(void);
extern FlagStatus RTC_ISR_MIN_IF_Chk(void);

/* Сʱ�жϱ�־��д1����
1���ж���λ
0�����жϲ��� ��غ��� */
extern void RTC_ISR_HOUR_IF_Clr(void);
extern FlagStatus RTC_ISR_HOUR_IF_Chk(void);

/* ���жϱ�־��д1����
1���ж���λ
0�����жϲ��� ��غ��� */
extern void RTC_ISR_DATE_IF_Clr(void);
extern FlagStatus RTC_ISR_DATE_IF_Chk(void);

/* ��ʱ����ֵ��BCD��ʽ�� ��غ��� */
extern void RTC_BCDSEC_Write(uint32_t SetValue);
extern uint32_t RTC_BCDSEC_Read(void);

/* ����ʱ����ֵ��BCD��ʽ�� ��غ��� */
extern void RTC_BCDMIN_Write(uint32_t SetValue);
extern uint32_t RTC_BCDMIN_Read(void);

/* Сʱ��ֵ��BCD��ʽ�� ��غ��� */
extern void RTC_BCDHOUR_Write(uint32_t SetValue);
extern uint32_t RTC_BCDHOUR_Read(void);

/* ����ֵ��BCD��ʽ�� ��غ��� */
extern void RTC_BCDWEEK_Write(uint32_t SetValue);
extern uint32_t RTC_BCDWEEK_Read(void);

/* ����ֵ��BCD��ʽ�� ��غ��� */
extern void RTC_BCDMONTH_Write(uint32_t SetValue);
extern uint32_t RTC_BCDMONTH_Read(void);

/* ����ֵ��BCD��ʽ�� ��غ��� */
extern void RTC_BCDYEAR_Write(uint32_t SetValue);
extern uint32_t RTC_BCDYEAR_Read(void);

/* ���ӹ���ʹ�� (alarm enable)
1��ʹ��Alarm����
0����ֹAlarm���� ��غ��� */
extern void RTC_ALARM_ALMEN_Setable(FunState NewState);
extern FunState RTC_ALARM_ALMEN_Getable(void);

/* ���ӵ�Сʱ��ֵ�� ��غ��� */
extern void RTC_ALARM_ALARMHOUR_Set(uint32_t SetValue);
extern uint32_t RTC_ALARM_ALARMHOUR_Get(void);

/* ���ӵķ���ֵ�� ��غ��� */
extern void RTC_ALARM_ALARMMIN_Set(uint32_t SetValue);
extern uint32_t RTC_ALARM_ALARMMIN_Get(void);

/* ���ӵ�����ֵ�� ��غ��� */
extern void RTC_ALARM_ALARMSEC_Set(uint32_t SetValue);
extern uint32_t RTC_ALARM_ALARMSEC_Get(void);

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
extern void RTC_TMSEL_Write(uint32_t SetValue);
extern uint32_t RTC_TMSEL_Read(void);

/* LTBC����������ֵ��ԭ���ʽ�� ��غ��� */
extern void RTC_ADJUST_Write(uint32_t SetValue);
extern uint32_t RTC_ADJUST_Read(void);

/* LTBC��������
0����ʾ���Ӽ�����ֵ
1����ʾ���ټ�����ֵ ��غ��� */
extern void RTC_ADSIGN_ADSIGN_Set(uint32_t SetValue);
extern uint32_t RTC_ADSIGN_ADSIGN_Get(void);

/* �����Уʹ���ź�
0����ʾ��ֹ�����У����
1����ʾʹ�������У���� ��غ��� */
extern void RTC_VCAL_PR1SEN_Setable(FunState NewState);
extern FunState RTC_VCAL_PR1SEN_Getable(void);

/* ���������
CALSTEP=00/11����Чλ8bit������3.9ms
CALSTEP=01����Чֵ7bit������7.8ms
CALSTEP=10����Чֵ6bit������15.625ms ��غ��� */
extern void RTC_MSCNT_Write(uint32_t SetValue);
extern uint32_t RTC_MSCNT_Read(void);

/* LTBC��С��У����ѡ��
10��0.06ppm������+/-0.03ppm��
01��0.119ppm������+/-0.06ppm��
00/11��0.238ppm������+/-0.119ppm�� ��غ��� */
extern void RTC_CALSTEP_CALSTEP_Set(uint32_t SetValue);
extern uint32_t RTC_CALSTEP_CALSTEP_Get(void);
extern uint32_t RTC_ADCNT_Read(void);

/* ��������� (sub-second counter register)
��������15.625ms ��غ��� */
extern uint32_t RTC_SSR_Read(void);

/* ��������ʹ�� (sub-second alarm enable)
1��ʹ���������ӹ���
0����ֹ�������ӹ��� ��غ��� */
extern void RTC_SSA_SSAEN_Setable(FunState NewState);
extern FunState RTC_SSA_SSAEN_Getable(void);

/* �������� (sub-second alarm)
��SSAEN=1������SSR����ֵ����SS_ALARMʱ���жϱ�־��λ�� ��غ��� */
extern void RTC_SSA_SS_ALARM_Set(uint32_t SetValue);
extern uint32_t RTC_SSA_SS_ALARM_Get(void);

/* RTC������ʱ�����ռ�ձȣ�����1�������ڸߵ�ƽ���ȣ���λĬ��ֵ��80ms�ߵ�ƽ ��غ��� */
extern void RTC_DTR_Write(uint32_t SetValue);
extern uint32_t RTC_DTR_Read(void);

/* RTCʱ�Ӻ�����ʹ�� (RTC_A Enable)
1��ʹ��RTC��ʱ
0��ֹͣRTC��ʱ

�˼Ĵ��������ſ�LSCLK���룬������㣬RTC������ֹͣ��ʱ�����������У���ܲ��ܴ˼Ĵ���Ӱ�졣 ��غ��� */
extern void RTC_CR_RTC_EN_Setable(FunState NewState);
extern FunState RTC_CR_RTC_EN_Getable(void);

extern void RTC_AlarmTime_SetEx(RTC_AlarmTmieTypeDef* para);


//Announce_End
#ifdef __cplusplus
}
#endif

#endif /* __FM33A0XXEV_RTC_H */
