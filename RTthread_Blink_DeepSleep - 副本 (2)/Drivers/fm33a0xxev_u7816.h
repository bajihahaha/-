/**
  ******************************************************************************
  * @file    fm33a0xxev_u7816.h
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file contains all the functions prototypes for the U7816 firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33A0XXEV_U7816_H
#define __FM33A0XXEV_U7816_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33A0XXEV.h" 
 
typedef struct
{
	FunState				TXEN;		//����ʹ��
	FunState				RXEN;		//����ʹ��
	FunState				CKOEN;		//U7816ʱ��CLK���ʹ�ܿ���
	FunState				HPUAT;		//U7816ͨ�����ݷ���ǿ���������Զ���Ч����
	FunState				HPUEN;		//U7816ͨ��ǿ����ʹ�ܿ���
	
	uint32_t				ERSW;		//ERROR SIGNAL���ѡ��
	uint32_t				ERSGD;		//ERROR SIGNAL��GUARDTIME���ѡ�񣨽��ڷ���ʱ��Ч��
	FunState				BGTEN;		//BGT��block guard time������
	uint32_t				REP_T;		//���ƽ���������żУ�����ʱ�Զ��ط�����
	uint32_t				PAR;		//��żУ������ѡ��
	uint32_t				SFREN;		//Guard Time���ȿ���λ������ʱ�ϸ���Э��2etu��
  uint32_t				RFREN;    //����Guard Time���ȿ���λ
	FunState				TREPEN;		//������������żУ���Ĵ���ʽѡ��
	FunState				RREPEN;		//����������żУ���Ĵ���ʽѡ��
	FunState				DICONV;		//������������ʹ��
	
	uint32_t				TXEGT;		//����ʱ�����EGTʱ�䣨��ETUΪ��λ��
	uint32_t				CLKDIV;		//U7816ʱ�������Ƶ���ƼĴ���
	uint32_t				PDIV;		//U7816Ԥ��Ƶ���ƼĴ���������7816ͨ�ŷ�Ƶ�ȣ������ʣ�
	
	FunState				RXIE;		//���ݽ����ж�ʹ��λ����ӦRX_FLAG�жϱ�־λ
	FunState				TXIE;		//���ݷ����ж�ʹ��λ����ӦTX_FLAG�жϱ�־λ
	FunState				LSIE;		//��·״̬�ж�ʹ��λ����ӦERROR_FLAG�жϱ�־λ
	
}U7816_InitTypeDef;


#define	U7816_CR_TXEN_Pos	5	/* U7816ͨ������ʹ�ܿ���λ (Transmit Enable)1��ͨ������ʹ�ܣ��ɷ�������0��ͨ�����ͽ�ֹ�����ɷ������ݣ����ض�����˿ڣ���SCL�ź�ת��Ϊ�͵�ƽ */
#define	U7816_CR_TXEN_Msk	(0x1U << U7816_CR_TXEN_Pos)

#define	U7816_CR_RXEN_Pos	4	/* U7816ͨ������ʹ�ܿ���λ (Receive Enable)1��ͨ������ʹ�ܣ��ɽ�������0��ͨ�����ս�ֹ�����ɽ������ݣ����ض�����˿� */
#define	U7816_CR_RXEN_Msk	(0x1U << U7816_CR_RXEN_Pos)

#define	U7816_CR_CKOEN_Pos	3	/* U7816ʱ��CLK���ʹ�ܿ���λ (Clock output Enable)1��7816ʱ�����ʹ��0��7816ʱ�������ֹ */
#define	U7816_CR_CKOEN_Msk	(0x1U << U7816_CR_CKOEN_Pos)

#define	U7816_CR_HPUAT_Pos	2	/* U7816ͨ�����ݷ���ǿ���������Զ���Ч����λ (High-Pullup Automatically)1�����ݷ���ʱ���������Զ���Ч������̬����������Ч0�����ݷ���ʱ���������Զ���Ч���ܽ�ֹ������������HPUEN��LPUEN���� */
#define	U7816_CR_HPUAT_Msk	(0x1U << U7816_CR_HPUAT_Pos)

#define	U7816_CR_HPUEN_Pos	1	/* U7816ͨ��ǿ����ʹ�ܿ���λ (High-Pullup Enable)1��ǿ������Ч0��ǿ������Ч */
#define	U7816_CR_HPUEN_Msk	(0x1U << U7816_CR_HPUEN_Pos)

#define	U7816_FFR_SFREN_Pos	11	/* Guard Time���ͳ��ȿ���λ (Send long Frame Enable)1��Guard timeΪ3 etu0��Guard timeΪ2 etu */
#define	U7816_FFR_SFREN_Msk	(0x1U << U7816_FFR_SFREN_Pos)
#define	U7816_FFR_SFREN_3ETU	(0x1U << U7816_FFR_SFREN_Pos)
#define	U7816_FFR_SFREN_2ETU	(0x0U << U7816_FFR_SFREN_Pos)

#define	U7816_FFR_ERSW_Pos	9	/* ERROR SIGNAL���ѡ�� (Error Signal Width)11��ERROR SIGNAL���Ϊ1ETU;10��ERROR SIGNAL���Ϊ1.5ETU;01��ERROR SIGNAL���Ϊ2ETU;00��ERROR SIGNAL���Ϊ2ETU; */
#define	U7816_FFR_ERSW_Msk	(0x3U << U7816_FFR_ERSW_Pos)
#define	U7816_FFR_ERSW_1ETU	(0x0U << U7816_FFR_ERSW_Pos)
#define	U7816_FFR_ERSW_1P5ETU	(0x1U << U7816_FFR_ERSW_Pos)
#define	U7816_FFR_ERSW_2ETU	(0x2U << U7816_FFR_ERSW_Pos)

#define	U7816_FFR_ERSGD_Pos	8	/* ERROR SIGNAL��GUARDTIME���ѡ�񣨽��ڷ���ʱ��Ч��
(Error Signal Guard Time)1��ERROR SIGNAL��GUARDTIMEΪ1~1.5ETU��0��ERROR SIGNAL��GUARDTIMEΪ2~2.5ETU��ERROR SIGNAL���Ϊ����ETUʱGUARDTIMEΪ1.5��2.5ETU��ERROR SIGNAL���Ϊ1.5ETUʱGUARDTIMEΪ1��2ETU */
#define	U7816_FFR_ERSGD_Msk	(0x1U << U7816_FFR_ERSGD_Pos)
#define	U7816_FFR_ERSGD_1ETU	(0x1U << U7816_FFR_ERSGD_Pos)	/* ERROR SIGNAL��GUARDTIMEΪ1~1.5ETU��0 */
#define	U7816_FFR_ERSGD_2ETU	(0x0U << U7816_FFR_ERSGD_Pos)

#define	U7816_FFR_BGTEN_Pos	7	/* BGT����λ�����ƽ���->����֮���Ƿ����BGT��BGT�ǽ���->����֮����Ҫ����Сʱ�䣨block guard time enable��1��BGTʹ�ܣ�����Block guard time(12 etu);0��BGT��ֹ��������Block guard time(12 etu); */
#define	U7816_FFR_BGTEN_Msk	(0x1U << U7816_FFR_BGTEN_Pos)

#define	U7816_FFR_REP_T_Pos	6	/* ���ƽ���������żУ�����ʱ�Զ��ط����� (Repeated Times)1��3��0��1�� */
#define	U7816_FFR_REP_T_Msk	(0x1U << U7816_FFR_REP_T_Pos)
#define	U7816_FFR_REP_T_1TIMES	(0x0U << U7816_FFR_REP_T_Pos)
#define	U7816_FFR_REP_T_3TIMES	(0x1U << U7816_FFR_REP_T_Pos)

#define	U7816_FFR_PAR_Pos	4	/* ��żУ������ѡ�� (Parity)00��Even01��Odd10��Always 111����У�飬���� */
#define	U7816_FFR_PAR_Msk	(0x3U << U7816_FFR_PAR_Pos)
#define	U7816_FFR_PAR_EVEN	(0x0U << U7816_FFR_PAR_Pos)
#define	U7816_FFR_PAR_ODD	(0x1U << U7816_FFR_PAR_Pos)
#define	U7816_FFR_PAR_1ALAWAYS	(0x2U << U7816_FFR_PAR_Pos)
#define	U7816_FFR_PAR_NON	(0x3U << U7816_FFR_PAR_Pos)

#define	U7816_FFR_RFREN_Pos	3	/* Guard Time���ճ��ȿ���λ (Receive short Frame )1��Guard timeΪ1 etu0��Guard timeΪ2 etu */
#define	U7816_FFR_RFREN_Msk	(0x1U << U7816_FFR_RFREN_Pos)
#define	U7816_FFR_RFREN_1ETU	(0x1U << U7816_FFR_RFREN_Pos)
#define	U7816_FFR_RFREN_2ETU	(0x0U << U7816_FFR_RFREN_Pos)

#define	U7816_FFR_TREPEN_Pos	2	/* ����������żУ���Ĵ���ʽѡ�� (Transmit Repeat Enable)1���յ���żУ������־��error signal��������T��0Э���Զ����лط����ڵ�һbyte�ظ����ʹ�������REP_T����tx_parity_err��־�������ж�0���յ�Error signalʱ�������Զ��ط�����tx_parity_err��־��ֱ���ж� */
#define	U7816_FFR_TREPEN_Msk	(0x1U << U7816_FFR_TREPEN_Pos)

#define	U7816_FFR_RREPEN_Pos	1	/* ����������żУ���Ĵ���ʽѡ�� (Receive Repeat Enable)1����żУ�������T=0Э���Զ��ط�ERROR SIGNAL����һBYTE�������մ�������REP_T����RX_PARITY_ERR��־�������ж�0����żУ������Զ�����ERROR SIGNAL����RX_PARITY_ERR��־�������ж� */
#define	U7816_FFR_RREPEN_Msk	(0x1U << U7816_FFR_RREPEN_Pos)

#define	U7816_FFR_DICONV_Pos	0	/* ������򣬱��뷽ʽѡ�� (bit Direction Conversion)1��������룬���շ�MSB��(�շ�����+У��λ)���߼���ƽ0��������룬���շ�LSB �� (�շ�����+У��λ)���߼���ƽ */
#define	U7816_FFR_DICONV_Msk	(0x1U << U7816_FFR_DICONV_Pos)
#define	U7816_FFR_DICONV_FORWARD	(0x0U << U7816_FFR_DICONV_Pos)
#define	U7816_FFR_DICONV_REVERSE	(0x1U << U7816_FFR_DICONV_Pos)

#define	U7816_EGTR_TXEGT_Pos	0	/* ����ʱ�����Extra Guard Timeʱ�䣨��ETUΪ��λ��
(Transmit Extra Guard Time) */
#define	U7816_EGTR_TXEGT_Msk	(0xffU << U7816_EGTR_TXEGT_Pos)

#define	U7816_PSC_CLKDIV_Pos	0	/* U7816ʱ�������Ƶ���ƼĴ���(Clock Divider)������7816����ʱ�ӷ�Ƶ����U7816����ʱ����APBCLK�ķ�Ƶ��ϵ��F7816=FAPBCLK/(CLKDIV+1)���������CLK_DIV���ó�0��1ʱ��F7816=FAPBCLK/2ע��7816Э��涨�Ĺ���ʱ�ӷ�Χ��1~5MHZ�� */
#define	U7816_PSC_CLKDIV_Msk	(0x1fU << U7816_PSC_CLKDIV_Pos)

#define	U7816_BGR_PDIV_Pos	0	/* U7816Ԥ��Ƶ���ƼĴ���(Pre-Divider)������7816ͨ�ŷ�Ƶ�ȣ������ʣ�Baud �� F7816/(PDIV �� 1)

ע�⣺PDIV��С����ֵ��0x1��Ӧ�ý�ֹ����0x0 */
#define	U7816_BGR_PDIV_Msk	(0xfffU << U7816_BGR_PDIV_Pos)

#define	U7816_RXBUF_RXBUF_Pos	0	/* U7816���ݽ��ջ���Ĵ��� (Receive Buffer) */
#define	U7816_RXBUF_RXBUF_Msk	(0xffU << U7816_RXBUF_RXBUF_Pos)

#define	U7816_TXBUF_TXBUF_Pos	0	/* U7816���ݷ��ͻ���Ĵ��� (Transmit Buffer) */
#define	U7816_TXBUF_TXBUF_Msk	(0xffU << U7816_TXBUF_TXBUF_Pos)

#define	U7816_IER_RXIE_Pos	2	/* ���ݽ����ж�ʹ��λ����ӦRXIF�жϱ�־λ (Receive Interrupt Enable)1����RXIF�Ĵ�����λʱ������������ж�0����ֹ��������ж� */
#define	U7816_IER_RXIE_Msk	(0x1U << U7816_IER_RXIE_Pos)

#define	U7816_IER_TXIE_Pos	1	/* ���ݷ����ж�ʹ��λ����ӦTXIF�жϱ�־λ(Transmit Interrupt Enable)1����TXIF�Ĵ�����λʱ������������ж�0����ֹ��������ж� */
#define	U7816_IER_TXIE_Msk	(0x1U << U7816_IER_TXIE_Pos)

#define	U7816_IER_LSIE_Pos	0	/* ��·״̬�ж�ʹ��λ����ӦERRIF�жϱ�־λ(Line Status Interrupt Enable)1����ERRIF�Ĵ�����λʱ������·�����ж�0����ֹ��·�����ж� */
#define	U7816_IER_LSIE_Msk	(0x1U << U7816_IER_LSIE_Pos)

#define	U7816_ISR_WAIT_RPT_Pos	18	/* U7816�ӿڷ����˴����źţ����ڵȴ��Է��ط����ݣ�(Waiting for Repeat flag)״̬�����뷢�ʹ����ź�״̬ʱ��λ���յ�������ʼλ���߽��뷢��״̬ʱӲ�����㣻���ֻ���� */
#define	U7816_ISR_WAIT_RPT_Msk	(0x1U << U7816_ISR_WAIT_RPT_Pos)

#define	U7816_ISR_TXBUSY_Pos	17	/* ��������æ��־����������ɺ��Զ����㣩(Transmission busy flag)1���������ݷ���״̬��������λ�Ĵ������ڷ������ݡ�����ʼ������ʼλ��1��ֹͣλ�м����㣩0�����ݷ��Ϳ��� */
#define	U7816_ISR_TXBUSY_Msk	(0x1U << U7816_ISR_TXBUSY_Pos)

#define	U7816_ISR_RXBUSY_Pos	16	/* ��������æ��־����������ɺ��Զ����㣩(Receiving busy flag)1���������ݽ���״̬��������λ�Ĵ������ڽ������ݡ����յ���ʼλ��1���յ�ֹͣλ���㣬���������ݳ������ط�����ط�error signalʱ���㡣�����ݼ�У��λ����֮�������Ƿ���Ҫ�ط�������Ҫ��ʱ����ñ�־��0�����ݽ��տ��� */
#define	U7816_ISR_RXBUSY_Msk	(0x1U << U7816_ISR_RXBUSY_Pos)

#define	U7816_ISR_TPARERR_Pos	11	/* ����������żУ������־λ��Ӳ����λ��д1���� (Transmit Parity Error,write 1 to clear) */
#define	U7816_ISR_TPARERR_Msk	(0x1U << U7816_ISR_TPARERR_Pos)

#define	U7816_ISR_RPARERR_Pos	10	/* ����������żУ������־λ��Ӳ����λ��д1���� (Receive Parity Error flag,write 1 to clear) */
#define	U7816_ISR_RPARERR_Msk	(0x1U << U7816_ISR_RPARERR_Pos)

#define	U7816_ISR_FRERR_Pos	9	/* ����֡��ʽ�����־λ��Ӳ����λ��д1���� (Frame Error flag,write 1 to clear)1��֡��ʽ�д��󣬽��յ���frame�ֽڳ����������յ���frame����stopλ����0����������ʱ����żУ����� */
#define	U7816_ISR_FRERR_Msk	(0x1U << U7816_ISR_FRERR_Pos)

#define	U7816_ISR_OVERR_Pos	8	/* ������������־λ��Ӳ����λ��д1���� (Receive Overflow Error,write 1 to clear)1�����ջ���Ĵ���δ���������ֽ��յ��µ����ݣ���������־��Ч��ԭ���ջ���Ĵ��������ݱ��¸���0����������� */
#define	U7816_ISR_OVERR_Msk	(0x1U << U7816_ISR_OVERR_Pos)

#define	U7816_ISR_RXIF_Pos	2	/* ������ɱ�־(Receive interrupt flag)��U7816�ӿڿ�����ÿ�յ�1byte���ݣ����ݽ��յ�ͨ����Ӧ����һ���жϡ�Ӳ����λ�������ݽ��ջ���Ĵ�������1�����յ�1byte���ݣ����ݽ��ջ�������0��δ���յ����ݣ����ݽ��ջ������� */
#define	U7816_ISR_RXIF_Msk	(0x1U << U7816_ISR_RXIF_Pos)

#define	U7816_ISR_TXIF_Pos	1	/* ���ͻ������ձ�־(Transmit interrupt flag)���ϵ縴λ��˱�־���Զ���λ����ʾ�������գ�����д�����ݡ����д�����ݺ��־�Զ���������ݴӷ��ͻ���������λ�Ĵ�������11�����ݷ��ͻ�������0�����ݷ��ͻ������������ݴ����� */
#define	U7816_ISR_TXIF_Msk	(0x1U << U7816_ISR_TXIF_Pos)

#define	U7816_ISR_ERRIF_Pos	0	/* �����־(Error interrupt flag)���Ĵ������ó����������г�����bit��TPARERR��RPARERR��FRERR��OVERR�Ļ����ͨ��������ϴ����־�Ĵ����������bit�� */
#define	U7816_ISR_ERRIF_Msk	(0x1U << U7816_ISR_ERRIF_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void U7816_Deinit(void);

/* U7816ͨ������ʹ�ܿ���λ (Transmit Enable)1��ͨ������ʹ�ܣ��ɷ�������0��ͨ�����ͽ�ֹ�����ɷ������ݣ����ض�����˿ڣ���SCL�ź�ת��Ϊ�͵�ƽ ��غ��� */
extern void U7816_CR_TXEN_Setable(FunState NewState);
extern FunState U7816_CR_TXEN_Getable(void);

/* U7816ͨ������ʹ�ܿ���λ (Receive Enable)1��ͨ������ʹ�ܣ��ɽ�������0��ͨ�����ս�ֹ�����ɽ������ݣ����ض�����˿� ��غ��� */
extern void U7816_CR_RXEN_Setable(FunState NewState);
extern FunState U7816_CR_RXEN_Getable(void);

/* U7816ʱ��CLK���ʹ�ܿ���λ (Clock output Enable)1��7816ʱ�����ʹ��0��7816ʱ�������ֹ ��غ��� */
extern void U7816_CR_CKOEN_Setable(FunState NewState);
extern FunState U7816_CR_CKOEN_Getable(void);

/* U7816ͨ�����ݷ���ǿ���������Զ���Ч����λ (High-Pullup Automatically)1�����ݷ���ʱ���������Զ���Ч������̬����������Ч0�����ݷ���ʱ���������Զ���Ч���ܽ�ֹ������������HPUEN��LPUEN���� ��غ��� */
extern void U7816_CR_HPUAT_Setable(FunState NewState);
extern FunState U7816_CR_HPUAT_Getable(void);

/* U7816ͨ��ǿ����ʹ�ܿ���λ (High-Pullup Enable)1��ǿ������Ч0��ǿ������Ч ��غ��� */
extern void U7816_CR_HPUEN_Setable(FunState NewState);
extern FunState U7816_CR_HPUEN_Getable(void);

/* Guard Time���ͳ��ȿ���λ (Send long Frame Enable)1��Guard timeΪ3 etu0��Guard timeΪ2 etu ��غ��� */
extern void U7816_FFR_SFREN_Set(uint32_t SetValue);
extern uint32_t U7816_FFR_SFREN_Get(void);

/* ERROR SIGNAL���ѡ�� (Error Signal Width)11��ERROR SIGNAL���Ϊ1ETU;10��ERROR SIGNAL���Ϊ1.5ETU;01��ERROR SIGNAL���Ϊ2ETU;00��ERROR SIGNAL���Ϊ2ETU; ��غ��� */
extern void U7816_FFR_ERSW_Set(uint32_t SetValue);
extern uint32_t U7816_FFR_ERSW_Get(void);

/* ERROR SIGNAL��GUARDTIME���ѡ�񣨽��ڷ���ʱ��Ч��
(Error Signal Guard Time)1��ERROR SIGNAL��GUARDTIMEΪ1~1.5ETU��0��ERROR SIGNAL��GUARDTIMEΪ2~2.5ETU��ERROR SIGNAL���Ϊ����ETUʱGUARDTIMEΪ1.5��2.5ETU��ERROR SIGNAL���Ϊ1.5ETUʱGUARDTIMEΪ1��2ETU ��غ��� */
extern void U7816_FFR_ERSGD_Set(uint32_t SetValue);
extern uint32_t U7816_FFR_ERSGD_Get(void);

/* BGT����λ�����ƽ���->����֮���Ƿ����BGT��BGT�ǽ���->����֮����Ҫ����Сʱ�䣨block guard time enable��1��BGTʹ�ܣ�����Block guard time(12 etu);0��BGT��ֹ��������Block guard time(12 etu); ��غ��� */
extern void U7816_FFR_BGTEN_Setable(FunState NewState);
extern FunState U7816_FFR_BGTEN_Getable(void);

/* ���ƽ���������żУ�����ʱ�Զ��ط����� (Repeated Times)1��3��0��1�� ��غ��� */
extern void U7816_FFR_REP_T_Set(uint32_t SetValue);
extern uint32_t U7816_FFR_REP_T_Get(void);

/* ��żУ������ѡ�� (Parity)00��Even01��Odd10��Always 111����У�飬���� ��غ��� */
extern void U7816_FFR_PAR_Set(uint32_t SetValue);
extern uint32_t U7816_FFR_PAR_Get(void);

/* Guard Time���ճ��ȿ���λ (Receive short Frame )1��Guard timeΪ1 etu0��Guard timeΪ2 etu ��غ��� */
extern void U7816_FFR_RFREN_Set(uint32_t SetValue);
extern uint32_t U7816_FFR_RFREN_Get(void);

/* ����������żУ���Ĵ���ʽѡ�� (Transmit Repeat Enable)1���յ���żУ������־��error signal��������T��0Э���Զ����лط����ڵ�һbyte�ظ����ʹ�������REP_T����tx_parity_err��־�������ж�0���յ�Error signalʱ�������Զ��ط�����tx_parity_err��־��ֱ���ж� ��غ��� */
extern void U7816_FFR_TREPEN_Setable(FunState NewState);
extern FunState U7816_FFR_TREPEN_Getable(void);

/* ����������żУ���Ĵ���ʽѡ�� (Receive Repeat Enable)1����żУ�������T=0Э���Զ��ط�ERROR SIGNAL����һBYTE�������մ�������REP_T����RX_PARITY_ERR��־�������ж�0����żУ������Զ�����ERROR SIGNAL����RX_PARITY_ERR��־�������ж� ��غ��� */
extern void U7816_FFR_RREPEN_Setable(FunState NewState);
extern FunState U7816_FFR_RREPEN_Getable(void);

/* ������򣬱��뷽ʽѡ�� (bit Direction Conversion)1��������룬���շ�MSB��(�շ�����+У��λ)���߼���ƽ0��������룬���շ�LSB �� (�շ�����+У��λ)���߼���ƽ ��غ��� */
extern void U7816_FFR_DICONV_Set(uint32_t SetValue);
extern uint32_t U7816_FFR_DICONV_Get(void);

/* ����ʱ�����Extra Guard Timeʱ�䣨��ETUΪ��λ��
(Transmit Extra Guard Time) ��غ��� */
extern void U7816_EGTR_Write(uint32_t SetValue);
extern uint32_t U7816_EGTR_Read(void);

/* U7816ʱ�������Ƶ���ƼĴ���(Clock Divider)������7816����ʱ�ӷ�Ƶ����U7816����ʱ����APBCLK�ķ�Ƶ��ϵ��F7816=FAPBCLK/(CLKDIV+1)���������CLK_DIV���ó�0��1ʱ��F7816=FAPBCLK/2ע��7816Э��涨�Ĺ���ʱ�ӷ�Χ��1~5MHZ�� ��غ��� */
extern void U7816_PSC_Write(uint32_t SetValue);
extern uint32_t U7816_PSC_Read(void);

/* U7816Ԥ��Ƶ���ƼĴ���(Pre-Divider)������7816ͨ�ŷ�Ƶ�ȣ������ʣ�Baud �� F7816/(PDIV �� 1)

ע�⣺PDIV��С����ֵ��0x1��Ӧ�ý�ֹ����0x0 ��غ��� */
extern void U7816_BGR_Write(uint32_t SetValue);
extern uint32_t U7816_BGR_Read(void);

/* U7816���ݽ��ջ���Ĵ��� (Receive Buffer) ��غ��� */
extern uint32_t U7816_RXBUF_Read(void);

/* U7816���ݷ��ͻ���Ĵ��� (Transmit Buffer) ��غ��� */
extern void U7816_TXBUF_Write(uint32_t SetValue);

/* ���ݽ����ж�ʹ��λ����ӦRXIF�жϱ�־λ (Receive Interrupt Enable)1����RXIF�Ĵ�����λʱ������������ж�0����ֹ��������ж� ��غ��� */
extern void U7816_IER_RXIE_Setable(FunState NewState);
extern FunState U7816_IER_RXIE_Getable(void);

/* ���ݷ����ж�ʹ��λ����ӦTXIF�жϱ�־λ(Transmit Interrupt Enable)1����TXIF�Ĵ�����λʱ������������ж�0����ֹ��������ж� ��غ��� */
extern void U7816_IER_TXIE_Setable(FunState NewState);
extern FunState U7816_IER_TXIE_Getable(void);

/* ��·״̬�ж�ʹ��λ����ӦERRIF�жϱ�־λ(Line Status Interrupt Enable)1����ERRIF�Ĵ�����λʱ������·�����ж�0����ֹ��·�����ж� ��غ��� */
extern void U7816_IER_LSIE_Setable(FunState NewState);
extern FunState U7816_IER_LSIE_Getable(void);

/* U7816�ӿڷ����˴����źţ����ڵȴ��Է��ط����ݣ�(Waiting for Repeat flag)״̬�����뷢�ʹ����ź�״̬ʱ��λ���յ�������ʼλ���߽��뷢��״̬ʱӲ�����㣻���ֻ���� ��غ��� */
extern FlagStatus U7816_ISR_WAIT_RPT_Chk(void);

/* ��������æ��־����������ɺ��Զ����㣩(Transmission busy flag)1���������ݷ���״̬��������λ�Ĵ������ڷ������ݡ�����ʼ������ʼλ��1��ֹͣλ�м����㣩0�����ݷ��Ϳ��� ��غ��� */
extern FlagStatus U7816_ISR_TXBUSY_Chk(void);

/* ��������æ��־����������ɺ��Զ����㣩(Receiving busy flag)1���������ݽ���״̬��������λ�Ĵ������ڽ������ݡ����յ���ʼλ��1���յ�ֹͣλ���㣬���������ݳ������ط�����ط�error signalʱ���㡣�����ݼ�У��λ����֮�������Ƿ���Ҫ�ط�������Ҫ��ʱ����ñ�־��0�����ݽ��տ��� ��غ��� */
extern FlagStatus U7816_ISR_RXBUSY_Chk(void);

/* ����������żУ������־λ��Ӳ����λ��д1���� (Transmit Parity Error,write 1 to clear) ��غ��� */
extern void U7816_ISR_TPARERR_Clr(void);
extern FlagStatus U7816_ISR_TPARERR_Chk(void);

/* ����������żУ������־λ��Ӳ����λ��д1���� (Receive Parity Error flag,write 1 to clear) ��غ��� */
extern void U7816_ISR_RPARERR_Clr(void);
extern FlagStatus U7816_ISR_RPARERR_Chk(void);

/* ����֡��ʽ�����־λ��Ӳ����λ��д1���� (Frame Error flag,write 1 to clear)1��֡��ʽ�д��󣬽��յ���frame�ֽڳ����������յ���frame����stopλ����0����������ʱ����żУ����� ��غ��� */
extern void U7816_ISR_FRERR_Clr(void);
extern FlagStatus U7816_ISR_FRERR_Chk(void);

/* ������������־λ��Ӳ����λ��д1���� (Receive Overflow Error,write 1 to clear)1�����ջ���Ĵ���δ���������ֽ��յ��µ����ݣ���������־��Ч��ԭ���ջ���Ĵ��������ݱ��¸���0����������� ��غ��� */
extern void U7816_ISR_OVERR_Clr(void);
extern FlagStatus U7816_ISR_OVERR_Chk(void);

/* ������ɱ�־(Receive interrupt flag)��U7816�ӿڿ�����ÿ�յ�1byte���ݣ����ݽ��յ�ͨ����Ӧ����һ���жϡ�Ӳ����λ�������ݽ��ջ���Ĵ�������1�����յ�1byte���ݣ����ݽ��ջ�������0��δ���յ����ݣ����ݽ��ջ������� ��غ��� */
extern FlagStatus U7816_ISR_RXIF_Chk(void);

/* ���ͻ������ձ�־(Transmit interrupt flag)���ϵ縴λ��˱�־���Զ���λ����ʾ�������գ�����д�����ݡ����д�����ݺ��־�Զ���������ݴӷ��ͻ���������λ�Ĵ�������11�����ݷ��ͻ�������0�����ݷ��ͻ������������ݴ����� ��غ��� */
extern FlagStatus U7816_ISR_TXIF_Chk(void);

/* �����־(Error interrupt flag)���Ĵ������ó����������г�����bit��TPARERR��RPARERR��FRERR��OVERR�Ļ����ͨ��������ϴ����־�Ĵ����������bit�� ��غ��� */
extern FlagStatus U7816_ISR_ERRIF_Chk(void);

/* U7816����������ʼ������ */
void U7816_Init( U7816_InitTypeDef* para);



//Announce_End
#ifdef __cplusplus
}
#endif

#endif /* __FM33A0XXEV_U7816_H */
