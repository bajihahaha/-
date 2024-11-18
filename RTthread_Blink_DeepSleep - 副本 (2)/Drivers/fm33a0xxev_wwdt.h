/**
  ******************************************************************************
  * @file    fm33a0xxev_wwdt.h
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file contains all the functions prototypes for the WWDT firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33A0XXEV_WWDT_H
#define __FM33A0XXEV_WWDT_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33A0XXEV.h" 
   
#define	WWDT_CR_CON_Pos	0	/* ��CPU��˵�ַд��0x5Aʱ����WWDT��ʱ�� (WWDT Control,write only)
������WWDT�󣬵�CPU��˵�ַд��0xACʱ��������� */
#define	WWDT_CR_CON_Msk	(0xffU << WWDT_CR_CON_Pos)

#define	WWDT_CFGR_CFG_Pos	0	/* ����WWDT���Ź����ʱ�䣬��λֵ011�������ϵ��ϵͳʱ��Ĭ��Ϊ8Mhz������Ĭ��������ڴ�Լ32ms (WWDT Config)
000��TPCLK * 4096 * 1
001��TPCLK * 4096 * 4
010��TPCLK * 4096 * 16
011��TPCLK * 4096 * 64
100��TPCLK * 4096 * 128
101��TPCLK * 4096 * 256
110��TPCLK * 4096 * 512
111��TPCLK * 4096 * 1024 */
#define	WWDT_CFGR_CFG_Msk	(0x7U << WWDT_CFGR_CFG_Pos)

#define	WWDT_CNTR_CNT_Pos	0	/* WWDT�����Ĵ���ֵ�������ͨ����ѯ�˼Ĵ����˽�WWDT��ʱ���� (WWDT Counter value,read only) */
#define	WWDT_CNTR_CNT_Msk	(0x3ffU << WWDT_CNTR_CNT_Pos)

#define	WWDT_IER_IE_Pos	0	/* WWDT�ж�ʹ�� (WWDT Interrupt Enable)
0���ж�ʹ�ܽ�ֹ
1���ж�ʹ�ܴ� */
#define	WWDT_IER_IE_Msk	(0x1U << WWDT_IER_IE_Pos)
	/* �ж�ʹ�ܽ�ֹ */
	/* �ж�ʹ�ܴ� */

#define	WWDT_ISR_NOVF_Pos	0	/* WWDT 75%��ʱ�жϱ�־��д1���� (Near Overflow Flag,write 1 to clear)
0�����жϲ���
1���жϱ�־��λ
���IE=1����˼Ĵ�����λ�������ж� */
#define	WWDT_ISR_NOVF_Msk	(0x1U << WWDT_ISR_NOVF_Pos)

#define	WWDT_PSCR_DIV_CNT_Pos	0	/* WWDT��4096Ԥ��Ƶ��������ǰ����ֵ��ֻ�� (WWDT prescaler Divider Counte,read only) */
#define	WWDT_PSCR_DIV_CNT_Msk	(0xfffU << WWDT_PSCR_DIV_CNT_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void WWDT_Deinit(void);

/* ��CPU��˵�ַд��0x5Aʱ����WWDT��ʱ�� (WWDT Control,write only)
������WWDT�󣬵�CPU��˵�ַд��0xACʱ��������� ��غ��� */
extern void WWDT_CR_Write(uint32_t SetValue);

/* ����WWDT���Ź����ʱ�䣬��λֵ011�������ϵ��ϵͳʱ��Ĭ��Ϊ8Mhz������Ĭ��������ڴ�Լ32ms (WWDT Config)
000��TPCLK * 4096 * 1
001��TPCLK * 4096 * 4
010��TPCLK * 4096 * 16
011��TPCLK * 4096 * 64
100��TPCLK * 4096 * 128
101��TPCLK * 4096 * 256
110��TPCLK * 4096 * 512
111��TPCLK * 4096 * 1024 ��غ��� */
extern void WWDT_CFGR_Write(uint32_t SetValue);
extern uint32_t WWDT_CFGR_Read(void);

/* WWDT�����Ĵ���ֵ�������ͨ����ѯ�˼Ĵ����˽�WWDT��ʱ���� (WWDT Counter value,read only) ��غ��� */
extern uint32_t WWDT_CNTR_Read(void);

/* WWDT�ж�ʹ�� (WWDT Interrupt Enable)
0���ж�ʹ�ܽ�ֹ
1���ж�ʹ�ܴ� ��غ��� */
extern void WWDT_IER_IE_Setable(FunState NewState);
extern FunState WWDT_IER_IE_Getable(void);

/* WWDT 75%��ʱ�жϱ�־��д1���� (Near Overflow Flag,write 1 to clear)
0�����жϲ���
1���жϱ�־��λ
���IE=1����˼Ĵ�����λ�������ж� ��غ��� */
extern void WWDT_ISR_NOVF_Clr(void);
extern FlagStatus WWDT_ISR_NOVF_Chk(void);

/* WWDT��4096Ԥ��Ƶ��������ǰ����ֵ��ֻ�� (WWDT prescaler Divider Counte,read only) ��غ��� */
extern uint32_t WWDT_PSCR_Read(void);
//Announce_End
#ifdef __cplusplus
}
#endif

#endif /* __FM33A0XXEV_WWDT_H */
