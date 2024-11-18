/**
  ******************************************************************************
  * @file    fm33a0xxev_bstim.h
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file contains all the functions prototypes for the BSTIM firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33A0XXEV_BSTIM_H
#define __FM33A0XXEV_BSTIM_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33A0XXEV.h" 
   
#define	BSTIM_CR1_ARPE_Pos	7	/* Auto-reloadԤװ��ʹ�� (Auto-Reload Preload Enable)
0��ARR�Ĵ�����ʹ��preload
1��ARR�Ĵ���ʹ��preload */
#define	BSTIM_CR1_ARPE_Msk	(0x1U << BSTIM_CR1_ARPE_Pos)
	/* ARR�Ĵ�����ʹ��preload */
	/* ARR�Ĵ���ʹ��preload */

#define	BSTIM_CR1_OPM_Pos	3	/* ���������ģʽ (One Pulse Mode)
0��Update Event����ʱ��������ֹͣ
1��Update Event����ʱ������ֹͣ���Զ�����CEN�� */
#define	BSTIM_CR1_OPM_Msk	(0x1U << BSTIM_CR1_OPM_Pos)
#define	BSTIM_CR1_OPM_CONTINUE	(0x0U << BSTIM_CR1_OPM_Pos)	/* Update Event����ʱ��������ֹͣ */
#define	BSTIM_CR1_OPM_STOP	    (0x1U << BSTIM_CR1_OPM_Pos)	/* Update Event����ʱ������ֹͣ���Զ�����CEN�� */

#define	BSTIM_CR1_URS_Pos	2	/* ��������ѡ�� (Update Request Select)
0�������¼��ܹ�����update�ж�
������������������
�����λUG�Ĵ���
�ӻ�����������update
1���������������������������update�жϻ�DMA���� */
#define	BSTIM_CR1_URS_Msk	(0x1U << BSTIM_CR1_URS_Pos)
#define	BSTIM_CR1_URS_ALL	(0x0U << BSTIM_CR1_URS_Pos)	/* �����¼��ܹ�����update�ж� */
#define	BSTIM_CR1_URS_COUNT	(0x1U << BSTIM_CR1_URS_Pos)	/* �������������������������update�жϻ�DMA���� */

#define	BSTIM_CR1_UDIS_Pos	1	/* ��ֹupdate (Update Disable)
0��ʹ��update�¼��������¼�����ʱ����update�¼�
������������������
�����λUG�Ĵ���
�ӻ�����������update
1����ֹupdate�¼���������shadow�Ĵ�������UG��λ��ӻ��������յ�Ӳ��resetʱ���³�ʼ����������Ԥ��Ƶ���� */
#define	BSTIM_CR1_UDIS_Msk	(0x1U << BSTIM_CR1_UDIS_Pos)
	/* ʹ��update�¼��������¼�����ʱ����update�¼� */
	/* ��ֹupdate�¼���������shadow�Ĵ�������UG��λ��ӻ��������յ�Ӳ��resetʱ���³�ʼ����������Ԥ��Ƶ���� */

#define	BSTIM_CR1_CEN_Pos	0	/* ������ʹ�� (Counter Enable)
0���������ر�
1��������ʹ��
ע�⣺�ⲿ����ģʽ�����Զ���λCEN */
#define	BSTIM_CR1_CEN_Msk	(0x1U << BSTIM_CR1_CEN_Pos)
	/* �������ر� */
	/* ������ʹ�� */
	/* �ⲿ����ģʽ�����Զ���λCEN */

#define	BSTIM_CR2_MMS_Pos	4	/* ����ģʽѡ��������������ģʽ����ӻ����͵�ͬ�������źţ�TRGO��Դ (Master Mode Select)
000��BSTIM_EGR��UG�Ĵ���������TRGO
001��������ʹ���ź�CNT_EN������TRGO��������ͬʱ���������ʱ��
010��UE��update event���źű�����TRGO
011/100/111��RFU

ע�⣺�ӻ���ʱ����ADC��������ʹ�ܹ���ʱ�ӣ����ܽ���������ʱ�����͵�TRGO */
#define	BSTIM_CR2_MMS_Msk	(0x7U << BSTIM_CR2_MMS_Pos)

#define	BSTIM_IER_UIE_Pos	0	/* Update�¼��ж�ʹ�� (Update event Interrupt Enable)
0����ֹUpdate�¼��ж�
1������Update�¼��ж� */
#define	BSTIM_IER_UIE_Msk	(0x1U << BSTIM_IER_UIE_Pos)
	/* ��ֹUpdate�¼��ж� */
	/* ����Update�¼��ж� */

#define	BSTIM_ISR_UIF_Pos	0	/* Update�¼��жϱ�־��Ӳ����λ�����д1���㡣(Update event Interrupt Flag,write 1 to flag)
�������¼�����ʱ��UIF��λ��������shadow�Ĵ���
-�ظ�������=0������UDIS=0������£��������������
-URS=0��UDIS=0������£������λUG�Ĵ�����ʼ��������
-URS=0��UDIS=0������£������¼���ʼ�������� */
#define	BSTIM_ISR_UIF_Msk	(0x1U << BSTIM_ISR_UIF_Pos)

#define	BSTIM_EGR_UG_Pos	0	/* ���Update�¼��������λ�˼Ĵ�������Update�¼���Ӳ���Զ����� (User Generate)
�����λUGʱ�����³�ʼ��������������shadow�Ĵ�����Ԥ��Ƶ�����������㡣 */
#define	BSTIM_EGR_UG_Msk	(0x1U << BSTIM_EGR_UG_Pos)

#define	BSTIM_CNTR_CNT_Pos	0	/* ������ֵ (Counter) */
#define	BSTIM_CNTR_CNT_Msk	(0xffffffffU << BSTIM_CNTR_CNT_Pos)

#define	BSTIM_PSCR_PSC_Pos	0	/* ������ʱ�ӣ�CK_CNT��Ԥ��Ƶֵ (Counter Clock Prescaler)
fCK_CNT=fCK_PSC/(PSC[15:0]+1)
����һ��preload�Ĵ�������update�¼�����ʱ�����ݱ�����shadow�Ĵ��� */
#define	BSTIM_PSCR_PSC_Msk	(0xffffffffU << BSTIM_PSCR_PSC_Pos)

#define	BSTIM_ARR_ARR_Pos	0	/* �������ʱ���Զ�����ֵ (Auto-Reload Register)
����һ��preload�Ĵ�������update�¼�����ʱ�����ݱ�����shadow�Ĵ��� */
#define	BSTIM_ARR_ARR_Msk	(0xffffffffU << BSTIM_ARR_ARR_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void BSTIM_Deinit(void);

/* Auto-reloadԤװ��ʹ�� (Auto-Reload Preload Enable)
0��ARR�Ĵ�����ʹ��preload
1��ARR�Ĵ���ʹ��preload ��غ��� */
extern void BSTIM_CR1_ARPE_Setable(FunState NewState);
extern FunState BSTIM_CR1_ARPE_Getable(void);

/* ���������ģʽ (One Pulse Mode)
0��Update Event����ʱ��������ֹͣ
1��Update Event����ʱ������ֹͣ���Զ�����CEN�� ��غ��� */
extern void BSTIM_CR1_OPM_Set(uint32_t SetValue);
extern uint32_t BSTIM_CR1_OPM_Get(void);

/* ��������ѡ�� (Update Request Select)
0�������¼��ܹ�����update�ж�
������������������
�����λUG�Ĵ���
�ӻ�����������update
1���������������������������update�жϻ�DMA���� ��غ��� */
extern void BSTIM_CR1_URS_Set(uint32_t SetValue);
extern uint32_t BSTIM_CR1_URS_Get(void);

/* ��ֹupdate (Update Disable)
0��ʹ��update�¼��������¼�����ʱ����update�¼�
������������������
�����λUG�Ĵ���
�ӻ�����������update
1����ֹupdate�¼���������shadow�Ĵ�������UG��λ��ӻ��������յ�Ӳ��resetʱ���³�ʼ����������Ԥ��Ƶ���� ��غ��� */
extern void BSTIM_CR1_UDIS_Setable(FunState NewState);
extern FunState BSTIM_CR1_UDIS_Getable(void);

/* ������ʹ�� (Counter Enable)
0���������ر�
1��������ʹ��
ע�⣺�ⲿ����ģʽ�����Զ���λCEN ��غ��� */
extern void BSTIM_CR1_CEN_Setable(FunState NewState);
extern FunState BSTIM_CR1_CEN_Getable(void);

/* ����ģʽѡ��������������ģʽ����ӻ����͵�ͬ�������źţ�TRGO��Դ (Master Mode Select)
000��BSTIM_EGR��UG�Ĵ���������TRGO
001��������ʹ���ź�CNT_EN������TRGO��������ͬʱ���������ʱ��
010��UE��update event���źű�����TRGO
011/100/111��RFU

ע�⣺�ӻ���ʱ����ADC��������ʹ�ܹ���ʱ�ӣ����ܽ���������ʱ�����͵�TRGO ��غ��� */
extern void BSTIM_CR2_Write(uint32_t SetValue);
extern uint32_t BSTIM_CR2_Read(void);

/* Update�¼��ж�ʹ�� (Update event Interrupt Enable)
0����ֹUpdate�¼��ж�
1������Update�¼��ж� ��غ��� */
extern void BSTIM_IER_UIE_Setable(FunState NewState);
extern FunState BSTIM_IER_UIE_Getable(void);

/* Update�¼��жϱ�־��Ӳ����λ�����д1���㡣(Update event Interrupt Flag,write 1 to flag)
�������¼�����ʱ��UIF��λ��������shadow�Ĵ���
-�ظ�������=0������UDIS=0������£��������������
-URS=0��UDIS=0������£������λUG�Ĵ�����ʼ��������
-URS=0��UDIS=0������£������¼���ʼ�������� ��غ��� */
extern void BSTIM_ISR_UIF_Clr(void);
extern FlagStatus BSTIM_ISR_UIF_Chk(void);

/* ���Update�¼��������λ�˼Ĵ�������Update�¼���Ӳ���Զ����� (User Generate)
�����λUGʱ�����³�ʼ��������������shadow�Ĵ�����Ԥ��Ƶ�����������㡣 ��غ��� */
extern void BSTIM_EGR_UG_Setable(FunState NewState);

/* ������ֵ (Counter) ��غ��� */
extern void BSTIM_CNTR_Write(uint32_t SetValue);
extern uint32_t BSTIM_CNTR_Read(void);

/* ������ʱ�ӣ�CK_CNT��Ԥ��Ƶֵ (Counter Clock Prescaler)
fCK_CNT=fCK_PSC/(PSC[15:0]+1)
����һ��preload�Ĵ�������update�¼�����ʱ�����ݱ�����shadow�Ĵ��� ��غ��� */
extern void BSTIM_PSCR_Write(uint32_t SetValue);
extern uint32_t BSTIM_PSCR_Read(void);

/* �������ʱ���Զ�����ֵ (Auto-Reload Register)
����һ��preload�Ĵ�������update�¼�����ʱ�����ݱ�����shadow�Ĵ��� ��غ��� */
extern void BSTIM_ARR_Write(uint32_t SetValue);
extern uint32_t BSTIM_ARR_Read(void);
//Announce_End
#ifdef __cplusplus
}
#endif

#endif /* __FM33A0XXEV_BSTIM_H */
