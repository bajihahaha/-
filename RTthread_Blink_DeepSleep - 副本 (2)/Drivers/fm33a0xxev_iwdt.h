/**
  ******************************************************************************
  * @file    fm33a0xxev_iwdt.h
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file contains all the functions prototypes for the IWDT firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33A0XXEV_IWDT_H
#define __FM33A0XXEV_IWDT_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33A0XXEV.h" 
#define IWDT_SERV_IWDTSERV_KEY  0x12345A5AU
#define	IWDT_SERV_IWDTSERV_Pos	0	/* IWDT�����������˵�ַд��0x1234_5A5Aʱ�幷 */
#define	IWDT_SERV_IWDTSERV_Msk	(0xffffffffU << IWDT_SERV_IWDTSERV_Pos)

#define	IWDT_CFGR_IWDTOVP_Pos	0	/* IWDT�����������
x00��125ms
x01��500ms
x10��2s
x11��8s
˵������bit2Ϊ0ʱ�����ߺ���ʹ�ö����ڣ���bit2Ϊ1ʱ�����ߺ��Զ�ʹ��4096s��������״̬�½�֧��125ms/500ms/2s/8s�������ڡ� */
#define	IWDT_CFGR_IWDTOVP_Msk	(0x7U << IWDT_CFGR_IWDTOVP_Pos)
#define IWDT_IWDTOVP_125MS    (0x0U << IWDT_CFGR_IWDTOVP_Pos)
#define IWDT_IWDTOVP_500MS    (0x1U << IWDT_CFGR_IWDTOVP_Pos)
#define IWDT_IWDTOVP_2S       (0x2U << IWDT_CFGR_IWDTOVP_Pos)
#define IWDT_IWDTOVP_8S      (0x3U << IWDT_CFGR_IWDTOVP_Pos)

#define IWDT_IWDTOVP_4096S    (0x4U << IWDT_CFGR_IWDTOVP_Pos)

#define	IWDT_CNTR_IWDTCNT_Pos	0	/* IWDT��ǰ����ֵ */
#define	IWDT_CNTR_IWDTCNT_Msk	(0xfffffU << IWDT_CNTR_IWDTCNT_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void IWDT_Deinit(void);

/* IWDT�����������˵�ַд��0x1234_5A5Aʱ�幷 ��غ��� */
extern void IWDT_SERV_IWDTSERV_Set(uint32_t SetValue);

/* IWDT�����������
x00��125ms
x01��500ms
x10��2s
x11��8s
˵������bit2Ϊ0ʱ�����ߺ���ʹ�ö����ڣ���bit2Ϊ1ʱ�����ߺ��Զ�ʹ��4096s��������״̬�½�֧��125ms/500ms/2s/8s�������ڡ� ��غ��� */
extern void IWDT_CFGR_Write(uint32_t SetValue);
extern uint32_t IWDT_CFGR_Read(void);

/* IWDT��ǰ����ֵ ��غ��� */
extern uint32_t IWDT_CNTR_IWDTCNT_Get(void);
//Announce_End
#ifdef __cplusplus
}
#endif

#endif /* __FM33A0XXEV_IWDT_H */
