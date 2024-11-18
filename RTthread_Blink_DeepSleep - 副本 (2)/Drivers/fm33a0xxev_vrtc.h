/**
  ******************************************************************************
  * @file    fm33a0xxev_vrtc.h
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file contains all the functions prototypes for the VRTC firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33A0XXEV_VRTC_H
#define __FM33A0XXEV_VRTC_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33A0XXEV.h" 

#define HXVAR(object, addr)   (*((object *) (addr)))
#define const_rcmf_Trim 	HXVAR( uint32_t, 0x1FFFFB44 )	//RCMF 2MHz��Уֵ
#define const_rclp_Trim 	HXVAR( uint32_t, 0x1FFFFB20 )	//RCLP��Уֵ   
#define	VRTC_PDRCR_CFG_Pos	0	/*  VRTC��Դ����PDR����*/
#define	VRTC_PDRCR_CFG_Msk	(0x1U << VRTC_PDRCR_CFG_Pos) 
      
/*0���ر�RCMF
1��ʹ��RCMF
��ע����ʹ����RTC�Զ��²���RCMF��Ӳ���������������͹ر� */
#define	VRTC_RCMFCR_EN_Msk	(0x1U << VRTC_RCMFCR_EN_Pos)
	/* �ر�RCMF */
	/* ʹ��RCMF */
   
#define	VRTC_RCMFCR_EN_Pos	7	/* RCMFʹ�ܼĴ���
0���ر�RCMF
1��ʹ��RCMF
��ע����ʹ����RTC�Զ��²���RCMF��Ӳ���������������͹ر� */
#define	VRTC_RCMFCR_EN_Msk	(0x1U << VRTC_RCMFCR_EN_Pos)
	/* �ر�RCMF */
	/* ʹ��RCMF */

#define	VRTC_RCMFCR_TRIM_Pos	0	/* RCMFƵ�ʵ�У�Ĵ��� */
#define	VRTC_RCMFCR_TRIM_Msk	(0x3fU << VRTC_RCMFCR_TRIM_Pos)

#define	VRTC_RCLPCR_CHOPEN_Pos	1	/* Chopperʹ�� */
#define	VRTC_RCLPCR_CHOPEN_Msk	(0x1U << VRTC_RCLPCR_CHOPEN_Pos)

#define	VRTC_RCLPCR_RCLP_OFF_Pos	0	/* RCLPʹ���ź�
0��ʹ��RCLP 
1���ر�RCLP
��ע��XTLF�쳣ͣ��ʱ���Զ�ʹ��RCLP */
#define	VRTC_RCLPCR_RCLP_OFF_Msk	(0x1U << VRTC_RCLPCR_RCLP_OFF_Pos)
	/* ʹ��RCLP  */
	/* �ر�RCLP */

#define	VRTC_RCLPTR_RCLP_TRIM_Pos	0	/* RCLP��Уֵ�Ĵ���
0000 0000��Ƶ�����
1111 1111��Ƶ����� */
#define	VRTC_RCLPTR_RCLP_TRIM_Msk	(0xffU << VRTC_RCLPTR_RCLP_TRIM_Pos)

#define	VRTC_XTLFCR_XTLFIPW_Pos	0
#define	VRTC_XTLFCR_XTLFIPW_Msk	(0xfU << VRTC_XTLFCR_XTLFIPW_Pos)
#define	VRTC_XTLFCR_XTLFIPW_850NA	(0x0U << VRTC_XTLFCR_XTLFIPW_Pos)
#define	VRTC_XTLFCR_XTLFIPW_800NA	(0x1U << VRTC_XTLFCR_XTLFIPW_Pos)
#define	VRTC_XTLFCR_XTLFIPW_750NA	(0x2U << VRTC_XTLFCR_XTLFIPW_Pos)
#define	VRTC_XTLFCR_XTLFIPW_700NA	(0x3U << VRTC_XTLFCR_XTLFIPW_Pos)
#define	VRTC_XTLFCR_XTLFIPW_650NA	(0x4U << VRTC_XTLFCR_XTLFIPW_Pos)
#define	VRTC_XTLFCR_XTLFIPW_600NA	(0x5U << VRTC_XTLFCR_XTLFIPW_Pos)
#define	VRTC_XTLFCR_XTLFIPW_550NA	(0x6U << VRTC_XTLFCR_XTLFIPW_Pos)
#define	VRTC_XTLFCR_XTLFIPW_500NA	(0x7U << VRTC_XTLFCR_XTLFIPW_Pos)
#define	VRTC_XTLFCR_XTLFIPW_450NA	(0x8U << VRTC_XTLFCR_XTLFIPW_Pos)
#define	VRTC_XTLFCR_XTLFIPW_400NA	(0x9U << VRTC_XTLFCR_XTLFIPW_Pos)
#define	VRTC_XTLFCR_XTLFIPW_350NA	(0xaU << VRTC_XTLFCR_XTLFIPW_Pos)
#define	VRTC_XTLFCR_XTLFIPW_300NA	(0xbU << VRTC_XTLFCR_XTLFIPW_Pos)
#define	VRTC_XTLFCR_XTLFIPW_250NA	(0xcU << VRTC_XTLFCR_XTLFIPW_Pos)
#define	VRTC_XTLFCR_XTLFIPW_200NA	(0xdU << VRTC_XTLFCR_XTLFIPW_Pos)
#define	VRTC_XTLFCR_XTLFIPW_150NA	(0xeU << VRTC_XTLFCR_XTLFIPW_Pos)
#define	VRTC_XTLFCR_XTLFIPW_100NA	(0xfU << VRTC_XTLFCR_XTLFIPW_Pos)

#define	VRTC_ADCCR_CKS_Pos	1	/* ADC����ʱ��ѡ��Ĵ���
000��RCMF
001��RCMF/2
010��RCMF/4
011��RCMF/8
100��RCMF/16
101��RCMF/32
110��RCLP
111��XTLF */
#define	VRTC_ADCCR_CKS_Msk	(0x7U << VRTC_ADCCR_CKS_Pos)
#define	VRTC_ADCCR_CKS_RCMF	(0x0U << VRTC_ADCCR_CKS_Pos)	/* RCMF */
#define	VRTC_ADCCR_CKS_RCMF_2	(0x1U << VRTC_ADCCR_CKS_Pos)	/* RCMF/2 */
#define	VRTC_ADCCR_CKS_RCMF_4	(0x2U << VRTC_ADCCR_CKS_Pos)	/* RCMF/4 */
#define	VRTC_ADCCR_CKS_RCMF_8	(0x3U << VRTC_ADCCR_CKS_Pos)	/* RCMF/8 */
#define	VRTC_ADCCR_CKS_RCMF_16	(0x4U << VRTC_ADCCR_CKS_Pos)	/* RCMF/16 */
#define	VRTC_ADCCR_CKS_RCMF_32	(0x5U << VRTC_ADCCR_CKS_Pos)	/* RCMF/32 */
#define	VRTC_ADCCR_CKS_RCLP	(0x6U << VRTC_ADCCR_CKS_Pos)	/* RCLP */
#define	VRTC_ADCCR_CKS_XTLF	(0x7U << VRTC_ADCCR_CKS_Pos)	/* XTLF */

#define	VRTC_ADCCR_CKE_Pos	0	/* ADC����ʱ��ʹ��
0���ر�ADC����ʱ��
1��ʹ��ADC����ʱ�� */
#define	VRTC_ADCCR_CKE_Msk	(0x1U << VRTC_ADCCR_CKE_Pos)
	/* �ر�ADC����ʱ�� */
	/* ʹ��ADC����ʱ�� */

#define	VRTC_LFDIER_LFDET_IE_Pos	0	/* XTLF��Ƶ��ⱨ���ж�ʹ�ܣ�1��Ч */
#define	VRTC_LFDIER_LFDET_IE_Msk	(0x1U << VRTC_LFDIER_LFDET_IE_Pos)

#define	VRTC_LFDISR_LFDETO_Pos	1	/* ��Ƶͣ����״̬���
1��XTLF����
0��XTLFͣ�� */
#define	VRTC_LFDISR_LFDETO_Msk	(0x1U << VRTC_LFDISR_LFDETO_Pos)

#define	VRTC_LFDISR_LFDET_IF_Pos	0	/* ��Ƶͣ�����жϱ�־�Ĵ�����XTLFͣ��ʱӲ���첽��λ�����д1���㣻ֻ����LFDETO��Ϊ0������²��ܹ�����˼Ĵ��� */
#define	VRTC_LFDISR_LFDET_IF_Msk	(0x1U << VRTC_LFDISR_LFDET_IF_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void VRTC_Deinit(void);

/* RCMFʹ�ܼĴ���
0���ر�RCMF
1��ʹ��RCMF
��ע����ʹ����RTC�Զ��²���RCMF��Ӳ���������������͹ر� ��غ��� */
extern void VRTC_RCMFCR_EN_Setable(FunState NewState);
extern FunState VRTC_RCMFCR_EN_Getable(void);

/* RCMFƵ�ʵ�У�Ĵ��� ��غ��� */
extern void VRTC_RCMFCR_TRIM_Set(uint32_t SetValue);
extern uint32_t VRTC_RCMFCR_TRIM_Get(void);

/* Chopperʹ�� ��غ��� */
extern void VRTC_RCLPCR_CHOPEN_Setable(FunState NewState);
extern FunState VRTC_RCLPCR_CHOPEN_Getable(void);

/* RCLPʹ���ź�
0��ʹ��RCLP 
1���ر�RCLP
��ע��XTLF�쳣ͣ��ʱ���Զ�ʹ��RCLP ��غ��� */
extern void VRTC_RCLPCR_RCLP_OFF_Setable(FunState NewState);
extern FunState VRTC_RCLPCR_RCLP_OFF_Getable(void);

/* RCLP��Уֵ�Ĵ���
0000 0000��Ƶ�����
1111 1111��Ƶ����� ��غ��� */
extern void VRTC_RCLPTR_Write(uint32_t SetValue);
extern uint32_t VRTC_RCLPTR_Read(void);
/*
rclpУ׼ֵ���뺯��
����:rclpУ׼ֵ����
���룺Ҫ���õ�RLPƵ��
*/
extern void VRTC_Init_RCLP_Trim(void);

extern void VRTC_XTLFCR_XTLFIPW_Set(uint32_t SetValue);
extern uint32_t VRTC_XTLFCR_XTLFIPW_Get(void);

/* ADC����ʱ��ѡ��Ĵ���
000��RCMF
001��RCMF/2
010��RCMF/4
011��RCMF/8
100��RCMF/16
101��RCMF/32
110��RCLP
111��XTLF ��غ��� */
extern void VRTC_ADCCR_CKS_Set(uint32_t SetValue);
extern uint32_t VRTC_ADCCR_CKS_Get(void);

/* ADC����ʱ��ʹ��
0���ر�ADC����ʱ��
1��ʹ��ADC����ʱ�� ��غ��� */
extern void VRTC_ADCCR_CKE_Setable(FunState NewState);
extern FunState VRTC_ADCCR_CKE_Getable(void);

/* XTLF��Ƶ��ⱨ���ж�ʹ�ܣ�1��Ч ��غ��� */
extern void VRTC_LFDIER_LFDET_IE_Setable(FunState NewState);
extern FunState VRTC_LFDIER_LFDET_IE_Getable(void);

/* ��Ƶͣ����״̬���
1��XTLF����
0��XTLFͣ�� ��غ��� */
extern FlagStatus VRTC_LFDISR_LFDETO_Chk(void);

/* ��Ƶͣ�����жϱ�־�Ĵ�����XTLFͣ��ʱӲ���첽��λ�����д1���㣻ֻ����LFDETO��Ϊ0������²��ܹ�����˼Ĵ��� ��غ��� */
extern void VRTC_LFDISR_LFDET_IF_Clr(void);
extern FlagStatus VRTC_LFDISR_LFDET_IF_Chk(void);

extern void VRTC_Init_RCMF_Trim(void);
//Announce_End
#ifdef __cplusplus
}
#endif

#endif /* __FM33A0XXEV_VRTC_H */
