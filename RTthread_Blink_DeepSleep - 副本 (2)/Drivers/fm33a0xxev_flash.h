/**
  ******************************************************************************
  * @file    fm33a0xxev_flash.h
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file contains all the functions prototypes for the FLASH firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33A0XXEV_FLASH_H
#define __FM33A0XXEV_FLASH_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33A0XXEV.h" 
   
#define	FLS_RDCR_WAIT_Pos	0	/* Flash���ȴ��������� (Wait Cycles Config)
00/11��0 wait cycle
01��1 wait cycle
10��2 wait cycles
CPU��ƵС�ڵ���24MHzʱ������Ҫ����wait����Ƶ����24MС��48Mhzʱʹ��1 wait����Ƶ����48Mhzʱʹ��2 wait */
#define	FLS_RDCR_WAIT_Msk	(0x3U << FLS_RDCR_WAIT_Pos)
#define	FLS_RDCR_WAIT_0CYCLE	(0x0U << FLS_RDCR_WAIT_Pos)	/* 0 wait cycle */
#define	FLS_RDCR_WAIT_1CYCLE	(0x1U << FLS_RDCR_WAIT_Pos)	/* 1 wait cycle */
#define	FLS_RDCR_WAIT_2CYCLE	(0x2U << FLS_RDCR_WAIT_Pos)	/* 2 wait cycles */

#define	FLS_PFCR_PRFTEN_Pos	0	/* ָ��Ԥȡָʹ�ܣ���WAIT==00�������д1��Ч (Prefetch Enable)
1��ʹ��Prefetch
0����ֹPrefetch */
#define	FLS_PFCR_PRFTEN_Msk	(0x1U << FLS_PFCR_PRFTEN_Pos)
	/* ʹ��Prefetch */
	/* ��ֹPrefetch */

#define	FLS_OPTBR_DBGCFGEN_Pos	31	
#define	FLS_OPTBR_DBGCFGEN_Msk	(0x1U << FLS_OPTBR_DBGCFGEN_Pos)

#define	FLS_OPTBR_IF2LOCK_Pos	18	/* Information2��������־ (IF2 Lock Enable)
0��δ����
1����������������������ɸ�д������ */
#define	FLS_OPTBR_IF2LOCK_Msk	(0x1U << FLS_OPTBR_IF2LOCK_Pos)

#define	FLS_OPTBR_IF1LOCK_Pos	17	/* Information1��������־ (IF1 Lock Enable)
0��δ����
1����������������������ɸ�д������ */
#define	FLS_OPTBR_IF1LOCK_Msk	(0x1U << FLS_OPTBR_IF1LOCK_Pos)

#define	FLS_OPTBR_DFLSEN_Pos	10	/* DataFlashʹ�� (DataFlash Enable)
0����data flash
1����data flash */
#define	FLS_OPTBR_DFLSEN_Msk	(0x1U << FLS_OPTBR_DFLSEN_Pos)
	/* ��data flash */
	/* ��data flash */

#define	FLS_OPTBR_BTSEN_Pos	8	/* BootSwap����ʹ�� (BootSwap Enable)
00/01/11����ֹBootSwap����
10������BootSwap */
#define	FLS_OPTBR_BTSEN_Msk	(0x3U << FLS_OPTBR_BTSEN_Pos)
	/* ��ֹBootSwap���� */
	/* ��ֹBootSwap���� */
	/* ��ֹBootSwap���� */
	/* ����BootSwap */

#define	FLS_OPTBR_ACLOCKEN_Pos	4	/* Ӧ�ô���Ȩ������ʹ�� (AppCode Lock Enable)
00/01/11��ACLOCK��ʹ��
10��ACLOCKʹ�� */
#define	FLS_OPTBR_ACLOCKEN_Msk	(0x3U << FLS_OPTBR_ACLOCKEN_Pos)
	/* ACLOCK��ʹ�� */
	/* ACLOCK��ʹ�� */
	/* ACLOCK��ʹ�� */
	/* ACLOCKʹ�� */

#define	FLS_OPTBR_DBRDPEN_Pos	0	/* Debug Port��ȡ����ʹ�� (Debug Read Protection Enable)
00/01/11��DBRDP��ʹ��
10��DBRDPʹ�� */
#define	FLS_OPTBR_DBRDPEN_Msk	(0xfU << FLS_OPTBR_DBRDPEN_Pos)
	/* DBRDP��ʹ�� */
	/* DBRDP��ʹ�� */
	/* DBRDP��ʹ�� */
	/* DBRDPʹ�� */

#define	FLS_OPTBR_LOCK1_Pos	0	/* ACLOCK���üĴ�����32bit���ֱ����ڿ���Block15~Block0��Ӧ�ô����д������ÿ��Block��СΪ8KB��ÿ��Blockʹ��2bit����Ȩ�޿��ơ� */
#define	FLS_OPTBR_LOCK1_Msk	(0xffffffffU << FLS_OPTBR_LOCK1_Pos)

#define	FLS_OPTBR_LOCK2_Pos	0	/* ACLOCK���üĴ�����32bit���ֱ����ڿ���Block31~Block16��Ӧ�ô����д������ÿ��Block��СΪ8KB��ÿ��Blockʹ��2bit����Ȩ�޿��� */
#define	FLS_OPTBR_LOCK2_Msk	(0xffffffffU << FLS_OPTBR_LOCK2_Pos)

#define	FLS_OPTBR_LOCK3_Pos	0	/* ACLOCK���üĴ�����32bit���ֱ����ڿ���Block31~Block16��Ӧ�ô����д������ÿ��Block��СΪ8KB��ÿ��Blockʹ��2bit����Ȩ�޿��� */
#define	FLS_OPTBR_LOCK3_Msk	(0xffffffffU << FLS_OPTBR_LOCK3_Pos)

#define	FLS_OPTBR_LOCK4_Pos	0	/* ACLOCK���üĴ�����32bit���ֱ����ڿ���Block31~Block16��Ӧ�ô����д������ÿ��Block��СΪ8KB��ÿ��Blockʹ��2bit����Ȩ�޿��� */
#define	FLS_OPTBR_LOCK4_Msk	(0xffffffffU << FLS_OPTBR_LOCK4_Pos)

#define	FLS_EPCR_ERTYPE_Pos	8	/* Flash������������ (Erase Type)
00/11��Page Erase
01��Sector Erase
10��Chip Erase (SWD only) */
#define	FLS_EPCR_ERTYPE_Msk	(0x3U << FLS_EPCR_ERTYPE_Pos)
#define	FLS_EPCR_ERTYPE_PAGE	(0x0U << FLS_EPCR_ERTYPE_Pos)	/* Page Erase */
#define	FLS_EPCR_ERTYPE_SECTOR	(0x1U << FLS_EPCR_ERTYPE_Pos)	/* Sector Erase */
#define	FLS_EPCR_ERTYPE_CHIP_ERASE	(0x2U << FLS_EPCR_ERTYPE_Pos)	/* Chip Erase (SWD only) */

#define	FLS_EPCR_PREQ_Pos	1	/* Program Request
�����λ��Ӳ����ɱ�̺��Զ����� */
#define	FLS_EPCR_PREQ_Msk	(0x1U << FLS_EPCR_PREQ_Pos)

#define	FLS_EPCR_EREQ_Pos	0	/* Erase Request
�����λ��Ӳ����ɲ������Զ����� */
#define	FLS_EPCR_EREQ_Msk	(0x1U << FLS_EPCR_EREQ_Pos)

#define	FLS_KEY_KEY_Pos	0	/* Flash��дKey����Ĵ������������SWD��������дǰ������ȷ����˵�ַд��Ϸ�KEY���С� (Flash Key) */
#define	FLS_KEY_KEY_Msk	(0xffffffffU << FLS_KEY_KEY_Pos)

#define	FLS_IER_OTPIE_Pos	11	/* OTP��̴����ж�ʹ�ܣ�1��Ч (OTP program error Interrupt Enable) */
#define	FLS_IER_OTPIE_Msk	(0x1U << FLS_IER_OTPIE_Pos)

#define	FLS_IER_AUTHIE_Pos	10	/* Flash��дȨ�޴����ж�ʹ�ܣ�1��Ч (Flash Authentication Error Interrupt Enable) */
#define	FLS_IER_AUTHIE_Msk	(0x1U << FLS_IER_AUTHIE_Pos)

#define	FLS_IER_KEYIE_Pos	9	/* Flash KEY�����ж�ʹ�ܣ�1��Ч (Flash Key Error Interrupt Enable) */
#define	FLS_IER_KEYIE_Msk	(0x1U << FLS_IER_KEYIE_Pos)

#define	FLS_IER_CKIE_Pos	8	/* ��д��ʱʱ�Ӵ����ж�ʹ�ܣ�1��Ч (Erase/Program Clock Error Interrupt Enable) */
#define	FLS_IER_CKIE_Msk	(0x1U << FLS_IER_CKIE_Pos)

#define	FLS_IER_PRDIE_Pos	1	/* �����ɱ�־�ж�ʹ�ܣ�1��Ч (Program Done Interrupt Enable) */
#define	FLS_IER_PRDIE_Msk	(0x1U << FLS_IER_PRDIE_Pos)

#define	FLS_IER_ERDIE_Pos	0	/* ��д��ɱ�־�ж�ʹ�ܣ�1��Ч (Erase Done Interrupt Enable) */
#define	FLS_IER_ERDIE_Msk	(0x1U << FLS_IER_ERDIE_Pos)

#define	FLS_ISR_KEYSTA_Pos	17	/* Flash��дKEY����״̬ (Flash Key Status)
000��Flashд����״̬��δ����KEY
001��ȫ������״̬
010������������״̬
011����̽���״̬
100��KEY��������״̬����Ҫ��λ���ܽ���
101/110/111��RFU */
#define	FLS_ISR_KEYSTA_Msk	(0x7U << FLS_ISR_KEYSTA_Pos)
#define	FLS_ISR_KEYSTA_KEY_NONE_PROTECT	(0x0U << FLS_ISR_KEYSTA_Pos)	/* Flashд����״̬��δ����KEY */
#define	FLS_ISR_KEYSTA_CHIP_ERASE	(0x1U << FLS_ISR_KEYSTA_Pos)	/* ȫ������״̬ */
#define	FLS_ISR_KEYSTA_SECTOR_ERASE	(0x2U << FLS_ISR_KEYSTA_Pos)	/* ����������״̬ */
#define	FLS_ISR_KEYSTA_PROGRAM	(0x3U << FLS_ISR_KEYSTA_Pos)	/* ��̽���״̬ */
#define	FLS_ISR_KEYSTA_KEY_ERR_PROTECT	(0x4U << FLS_ISR_KEYSTA_Pos)	/* KEY��������״̬����Ҫ��λ���ܽ��� */

#define	FLS_ISR_BTSF_Pos	16	/* BootSwap��־�Ĵ��� (BootSwap)
0������������ΪFlash�����ַ0000H~1FFFH
1������������ΪFlash�����ַ2000H~3FFFH */
#define	FLS_ISR_BTSF_Msk	(0x1U << FLS_ISR_BTSF_Pos)
#define	FLS_ISR_BTSF_START_0000H	(0x0U << FLS_ISR_BTSF_Pos)	/* ����������ΪFlash�����ַ0000H~1FFFH */
#define	FLS_ISR_BTSF_START_2000H	(0x1U << FLS_ISR_BTSF_Pos)	/* ����������ΪFlash�����ַ2000H~3FFFH */

#define	FLS_ISR_OTPERR_Pos	11	/* OTP page���Ȩ�޴���Ӳ����λ�����д1���� (OTP program Error Flag. Write 1 to clear)
1�����Զ��ѱ�̵�OTP�ֽڽ��б��
0����OTP��̴��� */
#define	FLS_ISR_OTPERR_Msk	(0x1U << FLS_ISR_OTPERR_Pos)

#define	FLS_ISR_AUTHERR_Pos	10	/* Flash��дȨ�޴��󣬶�ȡLOCK�����ݻ��LOCK���дʱ��λ�����д1���㡣(Flash Authentication Error Flag, write 1 to clear)
1��Flash����Ȩ�޴���
0��Flash����û�з���Ȩ�޴��� */
#define	FLS_ISR_AUTHERR_Msk	(0x1U << FLS_ISR_AUTHERR_Pos)

#define	FLS_ISR_KEYERR_Pos	9	/* Flash KEY����Ӳ����λ�����д1���� (Flash Key Error Flag, write 1 to clear) */
#define	FLS_ISR_KEYERR_Msk	(0x1U << FLS_ISR_KEYERR_Pos)

#define	FLS_ISR_CKERR_Pos	8	/* ��д��ʱʱ�Ӵ���NVMIF��дFlashʱ���RCHFδʹ�ܣ��򴥷�CKERR�жϣ����д1���㡣(Erase/Program Clock Error Flag, write 1 to clear) */
#define	FLS_ISR_CKERR_Msk	(0x1U << FLS_ISR_CKERR_Pos)

#define	FLS_ISR_PRD_Pos	1	/* Program Done�������ɱ�־��Ӳ����λ�����д1����(Program Done Flag,write 1 to clear) */
#define	FLS_ISR_PRD_Msk	(0x1U << FLS_ISR_PRD_Pos)

#define	FLS_ISR_ERD_Pos	0	/* Erase Done����д��ɱ�־��Ӳ����λ�����д1����(Erase Done Flag,write 1 to clear) */
#define	FLS_ISR_ERD_Msk	(0x1U << FLS_ISR_ERD_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void FLS_Deinit(void);

/* Flash���ȴ��������� (Wait Cycles Config)
00/11��0 wait cycle
01��1 wait cycle
10��2 wait cycles
CPU��ƵС�ڵ���24MHzʱ������Ҫ����wait����Ƶ����24MС��48Mhzʱʹ��1 wait����Ƶ����48Mhzʱʹ��2 wait ��غ��� */
extern void FLS_RDCR_WAIT_Set(uint32_t SetValue);
extern uint32_t FLS_RDCR_WAIT_Get(void);

/* ָ��Ԥȡָʹ�ܣ���WAIT==00�������д1��Ч (Prefetch Enable)
1��ʹ��Prefetch
0����ֹPrefetch ��غ��� */
extern void FLS_PFCR_PRFTEN_Setable(FunState NewState);
extern FunState FLS_PFCR_PRFTEN_Getable(void);

/* IWDT������ģʽ���Ƿ�����Ӧ����ͣ���� (IWDT Sleep Enable)
1������Ӧ��������ģʽ����ͣIWDT����
0����ֹӦ��������ģʽ����ͣIWDT���� ��غ��� */
extern FunState FLS_OPTBR_IWDTSLP_Getable(void);

extern FunState FLS_OPTBR_DBGCFGEN_Chk(void);

/* Information2��������־ (IF2 Lock Enable)
0��δ����
1����������������������ɸ�д������ ��غ��� */
extern FlagStatus FLS_OPTBR_IF2LOCK_Chk(void);

/* Information1��������־ (IF1 Lock Enable)
0��δ����
1����������������������ɸ�д������ ��غ��� */
extern FlagStatus FLS_OPTBR_IF1LOCK_Chk(void);

/* DataFlashʹ�� (DataFlash Enable)
0����data flash
1����data flash ��غ��� */
extern FunState FLS_OPTBR_DFLSEN_Getable(void);

/* BootSwap����ʹ�� (BootSwap Enable)
00/01/11����ֹBootSwap����
10������BootSwap ��غ��� */
extern FunState FLS_OPTBR_BTSEN_Getable(void);

/* Ӧ�ô���Ȩ������ʹ�� (AppCode Lock Enable)
00/01/11��ACLOCK��ʹ��
10��ACLOCKʹ�� ��غ��� */
extern FunState FLS_OPTBR_ACLOCKEN_Getable(void);

/* Debug Port��ȡ����ʹ�� (Debug Read Protection Enable)
00/01/11��DBRDP��ʹ��
10��DBRDPʹ�� ��غ��� */
extern uint32_t FLS_OPTBR_DBRDPEN_Getable(void);

/* Flash������������ (Erase Type)
00/11��Page Erase
01��Sector Erase
10��Chip Erase (SWD only) ��غ��� */
extern void FLS_EPCR_ERTYPE_Set(uint32_t SetValue);
extern uint32_t FLS_EPCR_ERTYPE_Get(void);

/* Program Request
�����λ��Ӳ����ɱ�̺��Զ����� ��غ��� */
extern void FLS_EPCR_PREQ_Set(uint32_t SetValue);
extern uint32_t FLS_EPCR_PREQ_Get(void);

/* Erase Request
�����λ��Ӳ����ɲ������Զ����� ��غ��� */
extern void FLS_EPCR_EREQ_Set(uint32_t SetValue);
extern uint32_t FLS_EPCR_EREQ_Get(void);

/* Flash��дKey����Ĵ������������SWD��������дǰ������ȷ����˵�ַд��Ϸ�KEY���С� (Flash Key) ��غ��� */
extern void FLS_KEY_Write(uint32_t SetValue);

/* OTP��̴����ж�ʹ�ܣ�1��Ч (OTP program error Interrupt Enable) ��غ��� */
extern void FLS_IER_OTPIE_Setable(FunState NewState);
extern FunState FLS_IER_OTPIE_Getable(void);

/* Flash��дȨ�޴����ж�ʹ�ܣ�1��Ч (Flash Authentication Error Interrupt Enable) ��غ��� */
extern void FLS_IER_AUTHIE_Setable(FunState NewState);
extern FunState FLS_IER_AUTHIE_Getable(void);

/* Flash KEY�����ж�ʹ�ܣ�1��Ч (Flash Key Error Interrupt Enable) ��غ��� */
extern void FLS_IER_KEYIE_Setable(FunState NewState);
extern FunState FLS_IER_KEYIE_Getable(void);

/* ��д��ʱʱ�Ӵ����ж�ʹ�ܣ�1��Ч (Erase/Program Clock Error Interrupt Enable) ��غ��� */
extern void FLS_IER_CKIE_Setable(FunState NewState);
extern FunState FLS_IER_CKIE_Getable(void);

/* �����ɱ�־�ж�ʹ�ܣ�1��Ч (Program Done Interrupt Enable) ��غ��� */
extern void FLS_IER_PRDIE_Setable(FunState NewState);
extern FunState FLS_IER_PRDIE_Getable(void);

/* ��д��ɱ�־�ж�ʹ�ܣ�1��Ч (Erase Done Interrupt Enable) ��غ��� */
extern void FLS_IER_ERDIE_Setable(FunState NewState);
extern FunState FLS_IER_ERDIE_Getable(void);

/* Flash��дKEY����״̬ (Flash Key Status)
000��Flashд����״̬��δ����KEY
001��ȫ������״̬
010������������״̬
011����̽���״̬
100��KEY��������״̬����Ҫ��λ���ܽ���
101/110/111��RFU ��غ��� */
extern uint32_t FLS_ISR_KEYSTA_Get(void);

/* BootSwap��־�Ĵ��� (BootSwap)
0������������ΪFlash�����ַ0000H~1FFFH
1������������ΪFlash�����ַ2000H~3FFFH ��غ��� */
extern uint32_t FLS_ISR_BTSF_Get(void);

/* OTP page���Ȩ�޴���Ӳ����λ�����д1���� (OTP program Error Flag. Write 1 to clear)
1�����Զ��ѱ�̵�OTP�ֽڽ��б��
0����OTP��̴��� ��غ��� */
extern void FLS_ISR_OTPERR_Clr(void);
extern FlagStatus FLS_ISR_OTPERR_Chk(void);

/* Flash��дȨ�޴��󣬶�ȡLOCK�����ݻ��LOCK���дʱ��λ�����д1���㡣(Flash Authentication Error Flag, write 1 to clear)
1��Flash����Ȩ�޴���
0��Flash����û�з���Ȩ�޴��� ��غ��� */
extern void FLS_ISR_AUTHERR_Clr(void);
extern FlagStatus FLS_ISR_AUTHERR_Chk(void);

/* Flash KEY����Ӳ����λ�����д1���� (Flash Key Error Flag, write 1 to clear) ��غ��� */
extern void FLS_ISR_KEYERR_Clr(void);
extern FlagStatus FLS_ISR_KEYERR_Chk(void);

/* ��д��ʱʱ�Ӵ���NVMIF��дFlashʱ���RCHFδʹ�ܣ��򴥷�CKERR�жϣ����д1���㡣(Erase/Program Clock Error Flag, write 1 to clear) ��غ��� */
extern void FLS_ISR_CKERR_Clr(void);
extern FlagStatus FLS_ISR_CKERR_Chk(void);

/* Program Done�������ɱ�־��Ӳ����λ�����д1����(Program Done Flag,write 1 to clear) ��غ��� */
extern void FLS_ISR_PRD_Clr(void);
extern FlagStatus FLS_ISR_PRD_Chk(void);

/* Erase Done����д��ɱ�־��Ӳ����λ�����д1����(Erase Done Flag,write 1 to clear) ��غ��� */
extern void FLS_ISR_ERD_Clr(void);
extern FlagStatus FLS_ISR_ERD_Chk(void);
//Announce_End
#ifdef __cplusplus
}
#endif

#endif /* __FM33A0XXEV_FLASH_H */
