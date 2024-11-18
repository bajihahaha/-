/**
  ******************************************************************************
  * @file    fm33a0xxev_dbg.h
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file contains all the functions prototypes for the DBG firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33A0XXEV_DBG_H
#define __FM33A0XXEV_DBG_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33A0XXEV.h" 
   
#define	DBG_CR_DBG_LPT_STOP_Pos	15	/* Debug״̬�� _32ʹ�ܿ���λ
1��Debugʱ�ر�LPT
0��Debugʱ����LPTԭ��״̬ */
#define	DBG_CR_DBG_LPT_STOP_Msk	(0x1U << DBG_CR_DBG_LPT_STOP_Pos)
	/* Debugʱ�ر�LPT */
	/* Debugʱ����LPTԭ��״̬ */

#define	DBG_CR_DBG_BST_STOP_Pos	14	/* Debug״̬��GPTIM2ʹ�ܿ���λ
1��Debugʱ�ر�BSTIM
0��Debugʱ����BSTIMԭ��״̬ */
#define	DBG_CR_DBG_BST_STOP_Msk	(0x1U << DBG_CR_DBG_BST_STOP_Pos)
	/* Debugʱ�ر�BSTIM */
	/* Debugʱ����BSTIMԭ��״̬ */
  
#define	DBG_CR_DBG_ET4_STOP_Pos	13	/* Debug״̬��GPTIM2ʹ�ܿ���λ
1��Debugʱ�ر�ET4
0��Debugʱ����ET4ԭ��״̬ */
#define	DBG_CR_DBG_ET4_STOP_Msk	(0x1U << DBG_CR_DBG_ET4_STOP_Pos)
	/* Debugʱ�ر�ET4 */
	/* Debugʱ����ET4ԭ��״̬ */
   
#define	DBG_CR_DBG_ET3_STOP_Pos	12	/* Debug״̬��GPTIM2ʹ�ܿ���λ
1��Debugʱ�ر�ET3
0��Debugʱ����ET3ԭ��״̬ */
#define	DBG_CR_DBG_ET3_STOP_Msk	(0x1U << DBG_CR_DBG_ET3_STOP_Pos)
	/* Debugʱ�ر�ET3 */
	/* Debugʱ����ET3ԭ��״̬ */   
   
#define	DBG_CR_DBG_ET2_STOP_Pos	11	/* Debug״̬��GPTIM2ʹ�ܿ���λ
1��Debugʱ�ر�ET2
0��Debugʱ����ET2ԭ��״̬ */
#define	DBG_CR_DBG_ET2_STOP_Msk	(0x1U << DBG_CR_DBG_ET2_STOP_Pos)
	/* Debugʱ�ر�ET2 */
	/* Debugʱ����ET2ԭ��״̬ */

#define	DBG_CR_DBG_ET1_STOP_Pos	10	/* Debug״̬��GPTIM1ʹ�ܿ���λ
1��Debugʱ�ر�ET1
0��Debugʱ����ET1ԭ��״̬ */
#define	DBG_CR_DBG_ET1_STOP_Msk	(0x1U << DBG_CR_DBG_ET1_STOP_Pos)
	/* Debugʱ�ر�ET1 */
	/* Debugʱ����ET1ԭ��״̬ */

#define	DBG_CR_DBG_BT2_STOP_Pos	9	/* Debug״̬��BSTIMʹ�ܿ���λ
1��Debugʱ�ر�BT2
0��Debugʱ����BT2ԭ��״̬ */
#define	DBG_CR_DBG_BT2_STOP_Msk	(0x1U << DBG_CR_DBG_BT2_STOP_Pos)
	/* Debugʱ�ر�BT2 */
	/* Debugʱ����BT2ԭ��״̬ */
  
#define	DBG_CR_DBG_BT1_STOP_Pos	8	/* Debug״̬��BSTIMʹ�ܿ���λ
1��Debugʱ�ر�BT1
0��Debugʱ����BT1ԭ��״̬ */
#define	DBG_CR_DBG_BT1_STOP_Msk	(0x1U << DBG_CR_DBG_BT1_STOP_Pos)
	/* Debugʱ�ر�BT1 */
	/* Debugʱ����BT1ԭ��״̬ */

#define	DBG_CR_DBG_WWDT_STOP_Pos	1	/* Debug״̬��WWDTʹ�ܿ���λ
1��Debugʱ�ر�WWDT
0��Debugʱ����WWDTԭ��״̬ */
#define	DBG_CR_DBG_WWDT_STOP_Msk	(0x1U << DBG_CR_DBG_WWDT_STOP_Pos)
	/* Debugʱ�ر�WWDT */
	/* Debugʱ����WWDTԭ��״̬ */

#define	DBG_CR_DBG_IWDT_STOP_Pos	0	/* Debug״̬��IWDTʹ�ܿ���λ
1��Debugʱ�ر�IWDT
0��Debugʱ����IWDT���� */
#define	DBG_CR_DBG_IWDT_STOP_Msk	(0x1U << DBG_CR_DBG_IWDT_STOP_Pos)
	/* Debugʱ�ر�IWDT */
	/* Debugʱ����IWDT���� */

#define	DBG_HDFR_DABORT_ADDR_FLAG_Pos	6	/* ��ַ�Ƕ�����ʴ����־��д1����
1����ַ�Ƕ�����ʴ���
0��δ���е�ַ�Ƕ������ */
#define	DBG_HDFR_DABORT_ADDR_FLAG_Msk	(0x1U << DBG_HDFR_DABORT_ADDR_FLAG_Pos)

#define	DBG_HDFR_DABORT_RESP_FLAG_Pos	5	/* �Ƿ���ַ���ʴ����־��д1����
1�����ߴ����з����˷Ƿ���ַ����HRESPΪ�߲�������
0��δ���ʷǷ���ַ */
#define	DBG_HDFR_DABORT_RESP_FLAG_Msk	(0x1U << DBG_HDFR_DABORT_RESP_FLAG_Pos)

#define	DBG_HDFR_SVCUNDEF_FLAG_Pos	4	/* SVC instructionsδ�����־��д1����
if the SVCall priority is lower than the currently activelevel, 
or if HardFault or NMI is active, 
or PRIMASK is set,
the core should treat SVC instructions as though theywere UNDEFINED�� */
#define	DBG_HDFR_SVCUNDEF_FLAG_Msk	(0x1U << DBG_HDFR_SVCUNDEF_FLAG_Pos)

#define	DBG_HDFR_BKPT_FLAG_Pos	3	/* ִ��BKPTָ���־��д1����
1��ִ����BKPTָ��
0��δִ��BKPTָ�� */
#define	DBG_HDFR_BKPT_FLAG_Msk	(0x1U << DBG_HDFR_BKPT_FLAG_Pos)

#define	DBG_HDFR_TBIT_FLAG_Pos	2	/* Thumb-State��־��д1����
1���л���ARM״̬
0������Thumb-State */
#define	DBG_HDFR_TBIT_FLAG_Msk	(0x1U << DBG_HDFR_TBIT_FLAG_Pos)

#define	DBG_HDFR_SPECIAL_OP_FLAG_Pos	1	/* ����ָ���־��д1����
1��ִ��������ָ����룬����ͼ��XN������ȡָ
0��������ָ����뱻ִ�� */
#define	DBG_HDFR_SPECIAL_OP_FLAG_Msk	(0x1U << DBG_HDFR_SPECIAL_OP_FLAG_Pos)

#define	DBG_HDFR_HDF_REQUEST_FLAG_Pos	0	/* hardfault��־λ���κ����͵�hardfault���ᵼ�¸�λ��λ��д1����
1��hardfault ����
0����hardfault���� */
#define	DBG_HDFR_HDF_REQUEST_FLAG_Msk	(0x1U << DBG_HDFR_HDF_REQUEST_FLAG_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void DBG_Deinit(void);

/* Debug״̬��LPTIMʹ�ܿ���λ
1��Debugʱ�ر�LPTIM
0��Debugʱ����LPTIMԭ��״̬ ��غ��� */
extern void DBG_CR_DBG_LPT_STOP_Setable(FunState NewState);
extern FunState DBG_CR_DBG_LPT_STOP_Getable(void);

/* Debug״̬��BSTIMʹ�ܿ���λ
1��Debugʱ�ر�BSTIM
0��Debugʱ����BSTIMԭ��״̬ ��غ��� */
extern void DBG_CR_DBG_BST_STOP_Setable(FunState NewState);
extern FunState DBG_CR_DBG_BST_STOP_Getable(void);

/* Debug״̬��ET4ʹ�ܿ���λ
1��Debugʱ�ر�ET4
0��Debugʱ����ET4ԭ��״̬ ��غ��� */
extern void DBG_CR_DBG_ET4_STOP_Setable(FunState NewState);
extern FunState DBG_CR_DBG_ET4_STOP_Getable(void);

/* Debug״̬��ET3ʹ�ܿ���λ
1��Debugʱ�ر�ET3
0��Debugʱ����ET3ԭ��״̬ ��غ��� */
extern void DBG_CR_DBG_ET3_STOP_Setable(FunState NewState);
extern FunState DBG_CR_DBG_ET3_STOP_Getable(void);

/* Debug״̬��ET2ʹ�ܿ���λ
1��Debugʱ�ر�ET2
0��Debugʱ����ET2ԭ��״̬ ��غ��� */
extern void DBG_CR_DBG_ET2_STOP_Setable(FunState NewState);
extern FunState DBG_CR_DBG_ET2_STOP_Getable(void);

/* Debug״̬��ET1ʹ�ܿ���λ
1��Debugʱ�ر�ET1
0��Debugʱ����ET1ԭ��״̬ ��غ��� */
extern void DBG_CR_DBG_ET1_STOP_Setable(FunState NewState);
extern FunState DBG_CR_DBG_ET1_STOP_Getable(void);

/* Debug״̬��BT2ʹ�ܿ���λ
1��Debugʱ�ر�BT2
0��Debugʱ����BT2ԭ��״̬ ��غ��� */
extern void DBG_CR_DBG_BT2_STOP_Setable(FunState NewState);
extern FunState DBG_CR_DBG_BT2_STOP_Getable(void);

/* Debug״̬��BT1ʹ�ܿ���λ
1��Debugʱ�ر�BT1
0��Debugʱ����ET1ԭ��״̬ ��غ��� */
extern void DBG_CR_DBG_BT1_STOP_Setable(FunState NewState);
extern FunState DBG_CR_DBG_BT1_STOP_Getable(void);

/* Debug״̬��WWDTʹ�ܿ���λ
1��Debugʱ�ر�WWDT
0��Debugʱ����WWDTԭ��״̬ ��غ��� */
extern void DBG_CR_DBG_WWDT_STOP_Setable(FunState NewState);
extern FunState DBG_CR_DBG_WWDT_STOP_Getable(void);

/* Debug״̬��IWDTʹ�ܿ���λ
1��Debugʱ�ر�IWDT
0��Debugʱ����IWDT���� ��غ��� */
extern void DBG_CR_DBG_IWDT_STOP_Setable(FunState NewState);
extern FunState DBG_CR_DBG_IWDT_STOP_Getable(void);

/* ��ַ�Ƕ�����ʴ����־��д1����
1����ַ�Ƕ�����ʴ���
0��δ���е�ַ�Ƕ������ ��غ��� */
extern void DBG_HDFR_DABORT_ADDR_FLAG_Clr(void);
extern FlagStatus DBG_HDFR_DABORT_ADDR_FLAG_Chk(void);

/* �Ƿ���ַ���ʴ����־��д1����
1�����ߴ����з����˷Ƿ���ַ����HRESPΪ�߲�������
0��δ���ʷǷ���ַ ��غ��� */
extern void DBG_HDFR_DABORT_RESP_FLAG_Clr(void);
extern FlagStatus DBG_HDFR_DABORT_RESP_FLAG_Chk(void);

/* SVC instructionsδ�����־��д1����
if the SVCall priority is lower than the currently activelevel, 
or if HardFault or NMI is active, 
or PRIMASK is set,
the core should treat SVC instructions as though theywere UNDEFINED�� ��غ��� */
extern void DBG_HDFR_SVCUNDEF_FLAG_Clr(void);
extern FlagStatus DBG_HDFR_SVCUNDEF_FLAG_Chk(void);

/* ִ��BKPTָ���־��д1����
1��ִ����BKPTָ��
0��δִ��BKPTָ�� ��غ��� */
extern void DBG_HDFR_BKPT_FLAG_Clr(void);
extern FlagStatus DBG_HDFR_BKPT_FLAG_Chk(void);

/* Thumb-State��־��д1����
1���л���ARM״̬
0������Thumb-State ��غ��� */
extern void DBG_HDFR_TBIT_FLAG_Clr(void);
extern FlagStatus DBG_HDFR_TBIT_FLAG_Chk(void);

/* ����ָ���־��д1����
1��ִ��������ָ����룬����ͼ��XN������ȡָ
0��������ָ����뱻ִ�� ��غ��� */
extern void DBG_HDFR_SPECIAL_OP_FLAG_Clr(void);
extern FlagStatus DBG_HDFR_SPECIAL_OP_FLAG_Chk(void);

/* hardfault��־λ���κ����͵�hardfault���ᵼ�¸�λ��λ��д1����
1��hardfault ����
0����hardfault���� ��غ��� */
extern void DBG_HDFR_HDF_REQUEST_FLAG_Clr(void);
extern FlagStatus DBG_HDFR_HDF_REQUEST_FLAG_Chk(void);
//Announce_End
#ifdef __cplusplus
}
#endif

#endif /* __FM33A0XXEV_DBG_H */
