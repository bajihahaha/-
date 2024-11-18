/**
  ******************************************************************************
  * @file    fm33a0xxev_i2c.h
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file contains all the functions prototypes for the I2C firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33A0XXEV_I2C_H
#define __FM33A0XXEV_I2C_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33A0XXEV.h" 
   
#define I2C_SEND_STARTBIT(I2Cx)			I2Cx_CR_SEN_Setable(I2Cx,ENABLE)
#define I2C_SEND_RESTARTBIT(I2Cx)		I2Cx_CR_RSEN_Setable(I2Cx,ENABLE)
#define I2C_SEND_STOPBIT(I2Cx)			I2Cx_CR_PEN_Setable(I2Cx,ENABLE)
	 
#define I2C_SEND_ACK_0(I2Cx)				I2Cx_SR_ACKMO_Set(I2Cx,I2Cx_SR_ACKMO_RESET)
#define I2C_SEND_ACK_1(I2Cx)				I2Cx_SR_ACKMO_Set(I2Cx,I2Cx_SR_ACKMO_SET)	 
	 
	 
#define	I2Cx_CFGR_AUTOEND_Pos	17	/* ����DMA�Զ���ֹ (Automatic Ending)
1��DMAָ�����ȴ�����ɺ��Զ�����STOPʱ��
0��DMAָ�����ȴ�����ɺ󣬵ȴ�����ӹ� */
#define	I2Cx_CFGR_AUTOEND_Msk	(0x1U << I2Cx_CFGR_AUTOEND_Pos)
#define	I2Cx_CFGR_AUTOEND_AUTO	(0x1U << I2Cx_CFGR_AUTOEND_Pos)	/* DMAָ�����ȴ�����ɺ��Զ�����STOPʱ�� */
#define	I2Cx_CFGR_AUTOEND_MANUAL	(0x0U << I2Cx_CFGR_AUTOEND_Pos)	/* DMAָ�����ȴ�����ɺ󣬵ȴ�����ӹ� */

#define	I2Cx_CFGR_MSP_DMAEN_Pos	16	/* ����DMAʹ�� (Master DMA Enable)
0���ر�DMA����
1��ʹ��DMA���� */
#define	I2Cx_CFGR_MSP_DMAEN_Msk	(0x1U << I2Cx_CFGR_MSP_DMAEN_Pos)
	/* �ر�DMA���� */
	/* ʹ��DMA���� */

#define	I2Cx_CFGR_TOEN_Pos	1	/* SCL���ͳ�ʱʹ�ܣ�TimeOut��
1��ʹ�ܳ�ʱ���ܣ���ʱ������MSPTO�Ĵ�������
0���رճ�ʱ���� */
#define	I2Cx_CFGR_TOEN_Msk	(0x1U << I2Cx_CFGR_TOEN_Pos)
#define	I2Cx_CFGR_TOEN_ENABLE	(0x1U << I2Cx_CFGR_TOEN_Pos)	/* ʹ�ܳ�ʱ���ܣ���ʱ������MSPTO�Ĵ������� */
#define	I2Cx_CFGR_TOEN_DISABLE	(0x0U << I2Cx_CFGR_TOEN_Pos)	/* �رճ�ʱ���� */

#define	I2Cx_CFGR_MSPEN_Pos	0	/* I2C����ģ��ʹ�ܿ���λ (Master Enable) 1 = I2C����ʹ�� 0 = I2C������ֹ */
#define	I2Cx_CFGR_MSPEN_Msk	(0x1U << I2Cx_CFGR_MSPEN_Pos)

#define	I2Cx_CR_RCEN_Pos	3	/* ���ؽ���ģʽ�£�����ʹ��λ (Receive Enable)
1 = ��������ʹ��
0 = ���ս�ֹ */
#define	I2Cx_CR_RCEN_Msk	(0x1U << I2Cx_CR_RCEN_Pos)

#define	I2Cx_CR_PEN_Pos	2	/* STOPʱ�����ʹ�ܿ���λ�����д1����STOPʱ�򣬷�����ɺ�Ӳ���Զ����� (Stop Enable) */
#define	I2Cx_CR_PEN_Msk	(0x1U << I2Cx_CR_PEN_Pos)

#define	I2Cx_CR_RSEN_Pos	1	/* Repeated STARTʱ�����ʹ�ܿ���λ�����д1����STOPʱ�򣬷�����ɺ�Ӳ���Զ����� (ReStart Enable) */
#define	I2Cx_CR_RSEN_Msk	(0x1U << I2Cx_CR_RSEN_Pos)

#define	I2Cx_CR_SEN_Pos	0	/* STARTʱ�����ʹ�ܿ���λ�����д1����STOPʱ�򣬷�����ɺ�Ӳ���Զ����� (Start Enable) */
#define	I2Cx_CR_SEN_Msk	(0x1U << I2Cx_CR_SEN_Pos)

#define	I2Cx_IER_WCOLE_Pos	6	/* WCOL�ж�ʹ�ܼĴ��� (Write Collide Enable)
1������д��ͻ�ж�
0����ֹд��ͻ�ж� */
#define	I2Cx_IER_WCOLE_Msk	(0x1U << I2Cx_IER_WCOLE_Pos)
	/* ����д��ͻ�ж� */
	/* ��ֹд��ͻ�ж� */

#define	I2Cx_IER_TOE_Pos	5	/* SCL��ʱ�ж�ʹ�ܼĴ��� (Time-Out Enable)
1������ʱ�ж�
0����ֹ��ʱ�ж� */
#define	I2Cx_IER_TOE_Msk	(0x1U << I2Cx_IER_TOE_Pos)

#define	I2Cx_IER_SE_Pos	4	/* STARTʱ���ж�ʹ�ܼĴ��� (START interrupt Enable)
1������STARTʱ���ж�
0����ֹSTARTʱ���ж� */
#define	I2Cx_IER_SE_Msk	(0x1U << I2Cx_IER_SE_Pos)
	/* ����STARTʱ���ж� */
	/* ��ֹSTARTʱ���ж� */

#define	I2Cx_IER_PE_Pos	3	/* STOPʱ���ж�ʹ�ܼĴ��� (STOP interrupt Enable)
1������STOPʱ���ж�
0����ֹSTOPʱ���ж� */
#define	I2Cx_IER_PE_Msk	(0x1U << I2Cx_IER_PE_Pos)
	/* ����STOPʱ���ж� */
	/* ��ֹSTOPʱ���ж� */

#define	I2Cx_IER_NACKE_Pos	2	/* ��������ģʽ��NACK�ж�ʹ�ܼĴ��� (Non-ACK interrupt Enable)
1�������յ�NACK�����ж�
0����ֹ����NACK�ж� */
#define	I2Cx_IER_NACKE_Msk	(0x1U << I2Cx_IER_NACKE_Pos)
	/* �����յ�NACK�����ж� */
	/* ��ֹ����NACK�ж� */

#define	I2Cx_IER_TXIE_Pos	1	/* I2C������������ж�ʹ�� (Transmit done interrupt enable)
1������������ж�
0����ֹ��������ж� */
#define	I2Cx_IER_TXIE_Msk	(0x1U << I2Cx_IER_TXIE_Pos)
	/* ����������ж� */
	/* ��ֹ��������ж� */

#define	I2Cx_IER_RXIE_Pos	0	/* I2C������������ж�ʹ�� (Receive done interrupt enable)
1�������������ж�
0����ֹ��������ж� */
#define	I2Cx_IER_RXIE_Msk	(0x1U << I2Cx_IER_RXIE_Pos)
	/* �����������ж� */
	/* ��ֹ��������ж� */

#define	I2Cx_ISR_WCOL_Pos	6	/* д��ͻ���λ��MCUֻ�������STARTʱ��������һ֡��д֮�����дSSPBUF��������д��ͻ��Ӳ����λ�����д1����
(Write Collide)
1 = ����д��ͻ
0 = δ������ͻ */
#define	I2Cx_ISR_WCOL_Msk	(0x1U << I2Cx_ISR_WCOL_Pos)

#define	I2Cx_ISR_TO_Pos	5	/* SCL�жϱ�־*/
#define	I2Cx_ISR_TO_Msk	(0x1U << I2Cx_ISR_TO_Pos)


#define	I2Cx_ISR_S_Pos	4	/* STARTʱ��������жϱ�־��Ӳ����λ�������ȡ������
(START done) */
#define	I2Cx_ISR_S_Msk	(0x1U << I2Cx_ISR_S_Pos)

#define	I2Cx_ISR_P_Pos	3	/* STOPʱ��������жϱ�־��Ӳ����λ�������ȡ������
(STOP done) */
#define	I2Cx_ISR_P_Msk	(0x1U << I2Cx_ISR_P_Pos)

#define	I2Cx_ISR_ACKSTA_Pos	2	/* ���ط���ģʽ�£����Դӻ��Ļ�Ӧ�źţ����������ͺ��յ�NACK���˱�־���Բ����жϣ�Ӳ����λ�����д1���㡣(Acknowledge Status)
1���ӻ���ӦNACK
0���ӻ���ӦACK */
#define	I2Cx_ISR_ACKSTA_Msk	(0x1U << I2Cx_ISR_ACKSTA_Pos)

#define	I2Cx_ISR_TXIF_Pos	1	/* I2C������������жϱ�־��Ӳ����λ�����д1���� (Transmit done interrupt flag) */
#define	I2Cx_ISR_TXIF_Msk	(0x1U << I2Cx_ISR_TXIF_Pos)

#define	I2Cx_ISR_RXIF_Pos	0	/* I2C������������жϱ�־��Ӳ����λ�����д1���� (Receive done interrupt flag) */
#define	I2Cx_ISR_RXIF_Msk	(0x1U << I2Cx_ISR_RXIF_Pos)

#define	I2Cx_SR_BUSY_Pos	5	/* I2Cͨ��״̬λ (I2C is busy)
1���ӿڴ��ڶ�д״̬�����ڽ������ݴ��䣬
0����������ݴ��� */
#define	I2Cx_SR_BUSY_Msk	(0x1U << I2Cx_SR_BUSY_Pos)

#define	I2Cx_SR_RW_Pos	4	/* I2C���䷽��״̬λ (Read or Write Bar)
1�������Ӵӻ���ȡ����
0��������ӻ�д������ */
#define	I2Cx_SR_RW_Msk	(0x1U << I2Cx_SR_RW_Pos)

#define	I2Cx_SR_BF_Pos	2	/* ��������״̬λ (Buffer full)
���գ�
1 = ������ɣ�SSPBUF��
0 = ����δ��ɣ�SSPBUF��
���ͣ�
1 = ���ڷ��ͣ�SSPBUF��
0 = ������ɣ�SSPBUF�� */
#define	I2Cx_SR_BF_Msk	(0x1U << I2Cx_SR_BF_Pos)

#define	I2Cx_SR_ACKMO_Pos	0	/* ���ؽ���ģʽ�£�������Ӧ�źŵ�״̬ (Acknowledge mode)
1�������ط�NACK
0�������ط�ACK

ע�⣺������P��־�Ĵ��������������£����������λACKMO
 */
#define	I2Cx_SR_ACKMO_Msk	(0x1U << I2Cx_SR_ACKMO_Pos)
#define	I2Cx_SR_ACKMO_RESET	(0x0U << I2Cx_SR_ACKMO_Pos)	/* 0�������ط�ACK */
#define	I2Cx_SR_ACKMO_SET	(0x1U << I2Cx_SR_ACKMO_Pos)	/* 1�������ط�NACK */

#define	I2Cx_BRG_MSPBRGH_Pos	16	/* �������͵�SCLʱ�Ӹߵ�ƽ��ȣ���I2C����ʱ�Ӽ��� */
#define	I2Cx_BRG_MSPBRGH_Msk	(0x1ffU << I2Cx_BRG_MSPBRGH_Pos)

#define	I2Cx_BRG_MSPBRGL_Pos	0	/* �������͵�SCLʱ�ӵ͵�ƽ��ȣ���I2C����ʱ�Ӽ��� */
#define	I2Cx_BRG_MSPBRGL_Msk	(0x1ffU << I2Cx_BRG_MSPBRGL_Pos)

#define	I2Cx_BUF_WR_Pos	0	/* SSPBUF[7:0]�����ݵĶ�дͨ����SSPBUF�Ĳ�����ɡ�����ʱ����SSPBUFִ��д������ͬʱҲ���������շ���λ�Ĵ���(SSPSR)������ʱ��SSPBUF��SSPSR���˫����ṹ����������ΪSSPBUF�����ݡ�������һ���ֽڵ����ݣ�SSPSR����������SSPBUF��ͬʱ��λI2CIF��SSPSR����ֱ�ӼĴ�����û�������ַ */
#define	I2Cx_BUF_WR_Msk	(0xffU << I2Cx_BUF_WR_Pos)

#define	I2Cx_TIMING_SDAHD_Pos	0	/* ����SDA�����SCL�½��صı���ʱ���������I2C����ʱ�Ӽ���
(SDA hold time) */
#define	I2Cx_TIMING_SDAHD_Msk	(0x1ffU << I2Cx_TIMING_SDAHD_Pos)

#define	I2Cx_TO_TIMEOUT_Pos	0	/* ����ӻ�SCL�͵�ƽ��չ��ʱ���ڣ����������MSPEN=0������¸�д
TSCL_STRETCHING_TIMEOUT=TIMEOUT[11:0] * TSCL */
#define	I2Cx_TO_TIMEOUT_Msk	(0xfffU << I2Cx_TO_TIMEOUT_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void I2Cx_Deinit(I2C_Type* I2Cx);

/* ����DMA�Զ���ֹ (Automatic Ending)
1��DMAָ�����ȴ�����ɺ��Զ�����STOPʱ��
0��DMAָ�����ȴ�����ɺ󣬵ȴ�����ӹ� ��غ��� */
extern void I2Cx_CFGR_AUTOEND_Set(I2C_Type* I2Cx, uint32_t SetValue);
extern uint32_t I2Cx_CFGR_AUTOEND_Get(I2C_Type* I2Cx);

/* ����DMAʹ�� (Master DMA Enable)
0���ر�DMA����
1��ʹ��DMA���� ��غ��� */
extern void I2Cx_CFGR_MSP_DMAEN_Setable(I2C_Type* I2Cx, FunState NewState);
extern FunState I2Cx_CFGR_MSP_DMAEN_Getable(I2C_Type* I2Cx);

/* SCL���ͳ�ʱʹ�ܣ�TimeOut��
1��ʹ�ܳ�ʱ���ܣ���ʱ������MSPTO�Ĵ�������
0���رճ�ʱ���� ��غ��� */
extern void I2Cx_CFGR_TOEN_Setable(I2C_Type* I2Cx, FunState NewState);
extern FunState I2Cx_CFGR_TOEN_Getable(I2C_Type* I2Cx);

/* I2C����ģ��ʹ�ܿ���λ (Master Enable)1 = I2C����ʹ��0 = I2C������ֹ ��غ��� */
extern void I2Cx_CFGR_MSPEN_Setable(I2C_Type* I2Cx, FunState NewState);
extern FunState I2Cx_CFGR_MSPEN_Getable(I2C_Type* I2Cx);

/* ���ؽ���ģʽ�£�����ʹ��λ (Receive Enable)
1 = ��������ʹ��
0 = ���ս�ֹ ��غ��� */
extern void I2Cx_CR_RCEN_Setable(I2C_Type* I2Cx, FunState NewState);
extern FunState I2Cx_CR_RCEN_Getable(I2C_Type* I2Cx);

/* STOPʱ�����ʹ�ܿ���λ�����д1����STOPʱ�򣬷�����ɺ�Ӳ���Զ����� (Stop Enable) ��غ��� */
extern void I2Cx_CR_PEN_Setable(I2C_Type* I2Cx, FunState NewState);
extern FunState I2Cx_CR_PEN_Getable(I2C_Type* I2Cx);

/* Repeated STARTʱ�����ʹ�ܿ���λ�����д1����STOPʱ�򣬷�����ɺ�Ӳ���Զ����� (ReStart Enable) ��غ��� */
extern void I2Cx_CR_RSEN_Setable(I2C_Type* I2Cx, FunState NewState);
extern FunState I2Cx_CR_RSEN_Getable(I2C_Type* I2Cx);

/* STARTʱ�����ʹ�ܿ���λ�����д1����STOPʱ�򣬷�����ɺ�Ӳ���Զ����� (Start Enable) ��غ��� */
extern void I2Cx_CR_SEN_Setable(I2C_Type* I2Cx, FunState NewState);
extern FunState I2Cx_CR_SEN_Getable(I2C_Type* I2Cx);

/* WCOL�ж�ʹ�ܼĴ��� (Write Collide Enable)
1������д��ͻ�ж�
0����ֹд��ͻ�ж� ��غ��� */
extern void I2Cx_IER_WCOLE_Setable(I2C_Type* I2Cx, FunState NewState);
extern FunState I2Cx_IER_WCOLE_Getable(I2C_Type* I2Cx);

/* SCL��ʱ�ж�ʹ�ܼĴ��� (Time-Out Enable)
1������ʱ�ж�
0����ֹ��ʱ�ж� ��غ��� */
extern void I2Cx_IER_TOE_Setable(I2C_Type* I2Cx, FunState NewState);
extern FunState I2Cx_IER_TOE_Getable(I2C_Type* I2Cx);

/* STARTʱ���ж�ʹ�ܼĴ��� (START interrupt Enable)
1������STARTʱ���ж�
0����ֹSTARTʱ���ж� ��غ��� */
extern void I2Cx_IER_SE_Setable(I2C_Type* I2Cx, FunState NewState);
extern FunState I2Cx_IER_SE_Getable(I2C_Type* I2Cx);

/* STOPʱ���ж�ʹ�ܼĴ��� (STOP interrupt Enable)
1������STOPʱ���ж�
0����ֹSTOPʱ���ж� ��غ��� */
extern void I2Cx_IER_PE_Setable(I2C_Type* I2Cx, FunState NewState);
extern FunState I2Cx_IER_PE_Getable(I2C_Type* I2Cx);

/* ��������ģʽ��NACK�ж�ʹ�ܼĴ��� (Non-ACK interrupt Enable)
1�������յ�NACK�����ж�
0����ֹ����NACK�ж� ��غ��� */
extern void I2Cx_IER_NACKE_Setable(I2C_Type* I2Cx, FunState NewState);
extern FunState I2Cx_IER_NACKE_Getable(I2C_Type* I2Cx);

/* I2C������������ж�ʹ�� (Transmit done interrupt enable)
1������������ж�
0����ֹ��������ж� ��غ��� */
extern void I2Cx_IER_TXIE_Setable(I2C_Type* I2Cx, FunState NewState);
extern FunState I2Cx_IER_TXIE_Getable(I2C_Type* I2Cx);

/* I2C������������ж�ʹ�� (Receive done interrupt enable)
1�������������ж�
0����ֹ��������ж� ��غ��� */
extern void I2Cx_IER_RXIE_Setable(I2C_Type* I2Cx, FunState NewState);
extern FunState I2Cx_IER_RXIE_Getable(I2C_Type* I2Cx);

/* д��ͻ���λ��MCUֻ�������STARTʱ��������һ֡��д֮�����дSSPBUF��������д��ͻ��Ӳ����λ�����д1����
(Write Collide)
1 = ����д��ͻ
0 = δ������ͻ ��غ��� */
extern void I2Cx_ISR_WCOL_Clr(I2C_Type* I2Cx);
extern FlagStatus I2Cx_ISR_WCOL_Chk(I2C_Type* I2Cx);

extern void I2Cx_ISR_OVT_Clr(I2C_Type* I2Cx);
extern FlagStatus I2Cx_ISR_OVT_Chk(I2C_Type* I2Cx);

/* STARTʱ��������жϱ�־��Ӳ����λ�������ȡ������
(START done) ��غ��� */
extern FlagStatus I2Cx_ISR_S_Chk(I2C_Type* I2Cx);

/* STOPʱ��������жϱ�־��Ӳ����λ�������ȡ������
(STOP done) ��غ��� */
extern FlagStatus I2Cx_ISR_P_Chk(I2C_Type* I2Cx);

/* ���ط���ģʽ�£����Դӻ��Ļ�Ӧ�źţ����������ͺ��յ�NACK���˱�־���Բ����жϣ�Ӳ����λ�����д1���㡣(Acknowledge Status)
1���ӻ���ӦNACK
0���ӻ���ӦACK ��غ��� */
extern void I2Cx_ISR_ACKSTA_Clr(I2C_Type* I2Cx);
extern FlagStatus I2Cx_ISR_ACKSTA_Chk(I2C_Type* I2Cx);

/* I2C������������жϱ�־��Ӳ����λ�����д1���� (Transmit done interrupt flag) ��غ��� */
extern void I2Cx_ISR_TXIF_Clr(I2C_Type* I2Cx);
extern FlagStatus I2Cx_ISR_TXIF_Chk(I2C_Type* I2Cx);

/* I2C������������жϱ�־��Ӳ����λ�����д1���� (Receive done interrupt flag) ��غ��� */
extern void I2Cx_ISR_RXIF_Clr(I2C_Type* I2Cx);
extern FlagStatus I2Cx_ISR_RXIF_Chk(I2C_Type* I2Cx);

/* I2Cͨ��״̬λ (I2C is busy)
1���ӿڴ��ڶ�д״̬�����ڽ������ݴ��䣬
0����������ݴ��� ��غ��� */
extern FlagStatus I2Cx_SR_BUSY_Chk(I2C_Type* I2Cx);

/* I2C���䷽��״̬λ (Read or Write Bar)
1�������Ӵӻ���ȡ����
0��������ӻ�д������ ��غ��� */
extern FlagStatus I2Cx_SR_RW_Chk(I2C_Type* I2Cx);

/* ��������״̬λ (Buffer full)
���գ�
1 = ������ɣ�SSPBUF��
0 = ����δ��ɣ�SSPBUF��
���ͣ�
1 = ���ڷ��ͣ�SSPBUF��
0 = ������ɣ�SSPBUF�� ��غ��� */
extern FlagStatus I2Cx_SR_BF_Chk(I2C_Type* I2Cx);

/* ���ؽ���ģʽ�£�������Ӧ�źŵ�״̬ (Acknowledge mode)
1�������ط�NACK
0�������ط�ACK

ע�⣺������P��־�Ĵ��������������£����������λACKMO
 ��غ��� */
extern void I2Cx_SR_ACKMO_Set(I2C_Type* I2Cx,uint32_t SetValue);
extern uint32_t I2Cx_SR_ACKMO_Get(I2C_Type* I2Cx);

/* �������͵�SCLʱ�Ӹߵ�ƽ��ȣ���I2C����ʱ�Ӽ��� ��غ��� */
extern void I2Cx_BRG_MSPBRGH_Set(I2C_Type* I2Cx, uint32_t SetValue);
extern uint32_t I2Cx_BRG_MSPBRGH_Get(I2C_Type* I2Cx);

/* �������͵�SCLʱ�ӵ͵�ƽ��ȣ���I2C����ʱ�Ӽ��� ��غ��� */
extern void I2Cx_BRG_MSPBRGL_Set(I2C_Type* I2Cx, uint32_t SetValue);
extern uint32_t I2Cx_BRG_MSPBRGL_Get(I2C_Type* I2Cx);

/* SSPBUF[7:0]�����ݵĶ�дͨ����SSPBUF�Ĳ�����ɡ�����ʱ����SSPBUFִ��д������ͬʱҲ���������շ���λ�Ĵ���(SSPSR)������ʱ��SSPBUF��SSPSR���˫����ṹ����������ΪSSPBUF�����ݡ�������һ���ֽڵ����ݣ�SSPSR����������SSPBUF��ͬʱ��λI2CIF��SSPSR����ֱ�ӼĴ�����û�������ַ ��غ��� */
extern void I2Cx_BUF_Write(I2C_Type* I2Cx, uint32_t SetValue);
extern uint32_t I2Cx_BUF_Read(I2C_Type* I2Cx);

/* ����SDA�����SCL�½��صı���ʱ���������I2C����ʱ�Ӽ���
(SDA hold time) ��غ��� */
extern void I2Cx_TIMING_Write(I2C_Type* I2Cx, uint32_t SetValue);
extern uint32_t I2Cx_TIMING_Read(I2C_Type* I2Cx);

/* ����ӻ�SCL�͵�ƽ��չ��ʱ���ڣ����������MSPEN=0������¸�д
TSCL_STRETCHING_TIMEOUT=TIMEOUT[11:0] * TSCL ��غ��� */
extern void I2Cx_TO_Write(I2C_Type* I2Cx, uint32_t SetValue);
extern uint32_t I2Cx_TO_Read(I2C_Type* I2Cx);

extern void I2Cx_Deinit(I2C_Type* I2Cx);
extern uint32_t I2C_BaudREG_Calc(uint32_t I2CClk, uint32_t APBClk);
//Announce_End
#ifdef __cplusplus
}
#endif

#endif /*__FM33A0XXEV_I2C_H */
