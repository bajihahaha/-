/**
  ******************************************************************************
  * @file    fm33a0xxev_i2c.c
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/

#include "fm33a0xxev_i2c.h"
#include "fm33a0xxev_rmu.h"

/** @addtogroup fm33a0xxev_StdPeriph_Driver
  * @{
  */

/** @defgroup I2C 
  * @brief I2C driver modules
  * @{
  */

/* ����DMA�Զ���ֹ (Automatic Ending)
1��DMAָ�����ȴ�����ɺ��Զ�����STOPʱ��
0��DMAָ�����ȴ�����ɺ󣬵ȴ�����ӹ� ��غ��� */
void I2Cx_CFGR_AUTOEND_Set(I2C_Type* I2Cx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = I2Cx->CFGR ;
	tmpreg &= ~(I2Cx_CFGR_AUTOEND_Msk);
	tmpreg |= (SetValue & I2Cx_CFGR_AUTOEND_Msk);
	I2Cx->CFGR  = tmpreg;
}

uint32_t I2Cx_CFGR_AUTOEND_Get(I2C_Type* I2Cx)
{
	return (I2Cx->CFGR  & I2Cx_CFGR_AUTOEND_Msk);
}

/* ����DMAʹ�� (Master DMA Enable)
0���ر�DMA����
1��ʹ��DMA���� ��غ��� */
void I2Cx_CFGR_MSP_DMAEN_Setable(I2C_Type* I2Cx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2Cx->CFGR  |= (I2Cx_CFGR_MSP_DMAEN_Msk);
	}
	else
	{
		I2Cx->CFGR  &= ~(I2Cx_CFGR_MSP_DMAEN_Msk);
	}
}

FunState I2Cx_CFGR_MSP_DMAEN_Getable(I2C_Type* I2Cx)
{
	if (I2Cx->CFGR  & (I2Cx_CFGR_MSP_DMAEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* SCL���ͳ�ʱʹ�ܣ�TimeOut��
1��ʹ�ܳ�ʱ���ܣ���ʱ������MSPTO�Ĵ�������
0���رճ�ʱ���� ��غ��� */
void I2Cx_CFGR_TOEN_Setable(I2C_Type* I2Cx, FunState NewState)
{	
	if (NewState == ENABLE)
	{
		I2Cx->CFGR  |= (I2Cx_CFGR_TOEN_Msk);
	}
	else
	{
		I2Cx->CFGR  &= ~(I2Cx_CFGR_TOEN_Msk);
	}
}

FunState I2Cx_CFGR_TOEN_Getable(I2C_Type* I2Cx)
{
	if (I2Cx->CFGR  & (I2Cx_CFGR_TOEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* I2C����ģ��ʹ�ܿ���λ (Master Enable)1 = I2C����ʹ��0 = I2C������ֹ ��غ��� */
void I2Cx_CFGR_MSPEN_Setable(I2C_Type* I2Cx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2Cx->CFGR  |= (I2Cx_CFGR_MSPEN_Msk);
	}
	else
	{
		I2Cx->CFGR  &= ~(I2Cx_CFGR_MSPEN_Msk);
	}
}

FunState I2Cx_CFGR_MSPEN_Getable(I2C_Type* I2Cx)
{
	if (I2Cx->CFGR  & (I2Cx_CFGR_MSPEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���ؽ���ģʽ�£�����ʹ��λ (Receive Enable)
1 = ��������ʹ��
0 = ���ս�ֹ ��غ��� */
void I2Cx_CR_RCEN_Setable(I2C_Type* I2Cx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2Cx->CR  |= (I2Cx_CR_RCEN_Msk);
	}
	else
	{
		I2Cx->CR  &= ~(I2Cx_CR_RCEN_Msk);
	}
}

FunState I2Cx_CR_RCEN_Getable(I2C_Type* I2Cx)
{
	if (I2Cx->CR  & (I2Cx_CR_RCEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* STOPʱ�����ʹ�ܿ���λ�����д1����STOPʱ�򣬷�����ɺ�Ӳ���Զ����� (Stop Enable) ��غ��� */
void I2Cx_CR_PEN_Setable(I2C_Type* I2Cx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2Cx->CR  |= (I2Cx_CR_PEN_Msk);
	}
	else
	{
		I2Cx->CR  &= ~(I2Cx_CR_PEN_Msk);
	}
}

FunState I2Cx_CR_PEN_Getable(I2C_Type* I2Cx)
{
	if (I2Cx->CR  & (I2Cx_CR_PEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Repeated STARTʱ�����ʹ�ܿ���λ�����д1����STOPʱ�򣬷�����ɺ�Ӳ���Զ����� (ReStart Enable) ��غ��� */
void I2Cx_CR_RSEN_Setable(I2C_Type* I2Cx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2Cx->CR  |= (I2Cx_CR_RSEN_Msk);
	}
	else
	{
		I2Cx->CR  &= ~(I2Cx_CR_RSEN_Msk);
	}
}

FunState I2Cx_CR_RSEN_Getable(I2C_Type* I2Cx)
{
	if (I2Cx->CR  & (I2Cx_CR_RSEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* STARTʱ�����ʹ�ܿ���λ�����д1����STOPʱ�򣬷�����ɺ�Ӳ���Զ����� (Start Enable) ��غ��� */
void I2Cx_CR_SEN_Setable(I2C_Type* I2Cx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2Cx->CR  |= (I2Cx_CR_SEN_Msk);
	}
	else
	{
		I2Cx->CR  &= ~(I2Cx_CR_SEN_Msk);
	}
}

FunState I2Cx_CR_SEN_Getable(I2C_Type* I2Cx)
{
	if (I2Cx->CR  & (I2Cx_CR_SEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* WCOL�ж�ʹ�ܼĴ��� (Write Collide Enable)
1������д��ͻ�ж�
0����ֹд��ͻ�ж� ��غ��� */
void I2Cx_IER_WCOLE_Setable(I2C_Type* I2Cx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2Cx->IER  |= (I2Cx_IER_WCOLE_Msk);
	}
	else
	{
		I2Cx->IER  &= ~(I2Cx_IER_WCOLE_Msk);
	}
}

FunState I2Cx_IER_WCOLE_Getable(I2C_Type* I2Cx)
{
	if (I2Cx->IER  & (I2Cx_IER_WCOLE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* SCL��ʱ�ж�ʹ�ܼĴ��� (Time-Out Enable)
1������ʱ�ж�
0����ֹ��ʱ�ж� ��غ��� */
void I2Cx_IER_TOE_Setable(I2C_Type* I2Cx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2Cx->IER  |= (I2Cx_IER_TOE_Msk);
	}
	else
	{
		I2Cx->IER  &= ~(I2Cx_IER_TOE_Msk);
	}
}

FunState I2Cx_IER_TOE_Getable(I2C_Type* I2Cx)
{
	if (I2Cx->IER  & (I2Cx_IER_TOE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* STARTʱ���ж�ʹ�ܼĴ��� (START interrupt Enable)
1������STARTʱ���ж�
0����ֹSTARTʱ���ж� ��غ��� */
void I2Cx_IER_SE_Setable(I2C_Type* I2Cx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2Cx->IER  |= (I2Cx_IER_SE_Msk);
	}
	else
	{
		I2Cx->IER  &= ~(I2Cx_IER_SE_Msk);
	}
}

FunState I2Cx_IER_SE_Getable(I2C_Type* I2Cx)
{
	if (I2Cx->IER  & (I2Cx_IER_SE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* STOPʱ���ж�ʹ�ܼĴ��� (STOP interrupt Enable)
1������STOPʱ���ж�
0����ֹSTOPʱ���ж� ��غ��� */
void I2Cx_IER_PE_Setable(I2C_Type* I2Cx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2Cx->IER  |= (I2Cx_IER_PE_Msk);
	}
	else
	{
		I2Cx->IER  &= ~(I2Cx_IER_PE_Msk);
	}
}

FunState I2Cx_IER_PE_Getable(I2C_Type* I2Cx)
{
	if (I2Cx->IER  & (I2Cx_IER_PE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��������ģʽ��NACK�ж�ʹ�ܼĴ��� (Non-ACK interrupt Enable)
1�������յ�NACK�����ж�
0����ֹ����NACK�ж� ��غ��� */
void I2Cx_IER_NACKE_Setable(I2C_Type* I2Cx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2Cx->IER  |= (I2Cx_IER_NACKE_Msk);
	}
	else
	{
		I2Cx->IER  &= ~(I2Cx_IER_NACKE_Msk);
	}
}

FunState I2Cx_IER_NACKE_Getable(I2C_Type* I2Cx)
{
	if (I2Cx->IER  & (I2Cx_IER_NACKE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* I2C������������ж�ʹ�� (Transmit done interrupt enable)
1������������ж�
0����ֹ��������ж� ��غ��� */
void I2Cx_IER_TXIE_Setable(I2C_Type* I2Cx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2Cx->IER  |= (I2Cx_IER_TXIE_Msk);
	}
	else
	{
		I2Cx->IER  &= ~(I2Cx_IER_TXIE_Msk);
	}
}

FunState I2Cx_IER_TXIE_Getable(I2C_Type* I2Cx)
{
	if (I2Cx->IER  & (I2Cx_IER_TXIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* I2C������������ж�ʹ�� (Receive done interrupt enable)
1�������������ж�
0����ֹ��������ж� ��غ��� */
void I2Cx_IER_RXIE_Setable(I2C_Type* I2Cx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2Cx->IER  |= (I2Cx_IER_RXIE_Msk);
	}
	else
	{
		I2Cx->IER  &= ~(I2Cx_IER_RXIE_Msk);
	}
}

FunState I2Cx_IER_RXIE_Getable(I2C_Type* I2Cx)
{
	if (I2Cx->IER  & (I2Cx_IER_RXIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* д��ͻ���λ��MCUֻ�������STARTʱ��������һ֡��д֮�����дSSPBUF��������д��ͻ��Ӳ����λ�����д1����
(Write Collide)
1 = ����д��ͻ
0 = δ������ͻ ��غ��� */
void I2Cx_ISR_WCOL_Clr(I2C_Type* I2Cx)
{
	I2Cx->ISR  = I2Cx_ISR_WCOL_Msk;
}

FlagStatus I2Cx_ISR_WCOL_Chk(I2C_Type* I2Cx)
{
	if (I2Cx->ISR  & I2Cx_ISR_WCOL_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* SCL��ʱ�жϱ�־ ��غ��� */
void I2Cx_ISR_OVT_Clr(I2C_Type* I2Cx)
{
	I2Cx->ISR = I2Cx_ISR_TO_Msk;
}

FlagStatus I2Cx_ISR_OVT_Chk(I2C_Type* I2Cx)
{
	if (I2Cx->ISR & I2Cx_ISR_TO_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* STARTʱ��������жϱ�־��Ӳ����λ�������ȡ������
(START done) ��غ��� */
FlagStatus I2Cx_ISR_S_Chk(I2C_Type* I2Cx)
{
	if (I2Cx->ISR  & I2Cx_ISR_S_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* STOPʱ��������жϱ�־��Ӳ����λ�������ȡ������
(STOP done) ��غ��� */
FlagStatus I2Cx_ISR_P_Chk(I2C_Type* I2Cx)
{
	if (I2Cx->ISR  & I2Cx_ISR_P_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ���ط���ģʽ�£����Դӻ��Ļ�Ӧ�źţ����������ͺ��յ�NACK���˱�־���Բ����жϣ�Ӳ����λ�����д1���㡣(Acknowledge Status)
1���ӻ���ӦNACK
0���ӻ���ӦACK ��غ��� */
void I2Cx_ISR_ACKSTA_Clr(I2C_Type* I2Cx)
{
	I2Cx->ISR  = I2Cx_ISR_ACKSTA_Msk;
}

FlagStatus I2Cx_ISR_ACKSTA_Chk(I2C_Type* I2Cx)
{
	if (I2Cx->ISR  & I2Cx_ISR_ACKSTA_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* I2C������������жϱ�־��Ӳ����λ�����д1���� (Transmit done interrupt flag) ��غ��� */
void I2Cx_ISR_TXIF_Clr(I2C_Type* I2Cx)
{
	I2Cx->ISR  = I2Cx_ISR_TXIF_Msk;
}

FlagStatus I2Cx_ISR_TXIF_Chk(I2C_Type* I2Cx)
{
	if (I2Cx->ISR  & I2Cx_ISR_TXIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* I2C������������жϱ�־��Ӳ����λ�����д1���� (Receive done interrupt flag) ��غ��� */
void I2Cx_ISR_RXIF_Clr(I2C_Type* I2Cx)
{
	I2Cx->ISR  = I2Cx_ISR_RXIF_Msk;
}

FlagStatus I2Cx_ISR_RXIF_Chk(I2C_Type* I2Cx)
{
	if (I2Cx->ISR  & I2Cx_ISR_RXIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* I2Cͨ��״̬λ (I2C is busy)
1���ӿڴ��ڶ�д״̬�����ڽ������ݴ��䣬
0����������ݴ��� ��غ��� */
FlagStatus I2Cx_SR_BUSY_Chk(I2C_Type* I2Cx)
{
	if (I2Cx->SR  & I2Cx_SR_BUSY_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* I2C���䷽��״̬λ (Read or Write Bar)
1�������Ӵӻ���ȡ����
0��������ӻ�д������ ��غ��� */
FlagStatus I2Cx_SR_RW_Chk(I2C_Type* I2Cx)
{
	if (I2Cx->SR  & I2Cx_SR_RW_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��������״̬λ (Buffer full)
���գ�
1 = ������ɣ�SSPBUF��
0 = ����δ��ɣ�SSPBUF��
���ͣ�
1 = ���ڷ��ͣ�SSPBUF��
0 = ������ɣ�SSPBUF�� ��غ��� */
FlagStatus I2Cx_SR_BF_Chk(I2C_Type* I2Cx)
{
	if (I2Cx->SR  & I2Cx_SR_BF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ���ؽ���ģʽ�£�������Ӧ�źŵ�״̬ (Acknowledge mode)
1�������ط�NACK
0�������ط�ACK

ע�⣺������P��־�Ĵ��������������£����������λACKMO
 ��غ��� */
void I2Cx_SR_ACKMO_Set(I2C_Type* I2Cx,uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = I2Cx->SR;
	tmpreg &= ~(I2Cx_SR_ACKMO_Msk);
	tmpreg |= (SetValue & I2Cx_SR_ACKMO_Msk);
	I2Cx->SR = tmpreg;
}

uint32_t I2Cx_SR_ACKMO_Get(I2C_Type* I2Cx)
{
	return (I2Cx->SR & I2Cx_SR_ACKMO_Msk);
}

/* �������͵�SCLʱ�Ӹߵ�ƽ��ȣ���I2C����ʱ�Ӽ��� ��غ��� */
void I2Cx_BRG_MSPBRGH_Set(I2C_Type* I2Cx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = I2Cx->BRG;
	tmpreg &= ~(I2Cx_BRG_MSPBRGH_Msk);
	tmpreg |= (SetValue & I2Cx_BRG_MSPBRGH_Msk);
	I2Cx->BRG = tmpreg;
}

uint32_t I2Cx_BRG_MSPBRGH_Get(I2C_Type* I2Cx)
{
	return (I2Cx->BRG & I2Cx_BRG_MSPBRGH_Msk);
}

/* �������͵�SCLʱ�ӵ͵�ƽ��ȣ���I2C����ʱ�Ӽ��� ��غ��� */
void I2Cx_BRG_MSPBRGL_Set(I2C_Type* I2Cx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = I2Cx->BRG;
	tmpreg &= ~(I2Cx_BRG_MSPBRGL_Msk);
	tmpreg |= (SetValue & I2Cx_BRG_MSPBRGL_Msk);
	I2Cx->BRG = tmpreg;
}

uint32_t I2Cx_BRG_MSPBRGL_Get(I2C_Type* I2Cx)
{
	return (I2Cx->BRG & I2Cx_BRG_MSPBRGL_Msk);
}

/* SSPBUF[7:0]�����ݵĶ�дͨ����SSPBUF�Ĳ�����ɡ�����ʱ����SSPBUFִ��д������ͬʱҲ���������շ���λ�Ĵ���(SSPSR)������ʱ��SSPBUF��SSPSR���˫����ṹ����������ΪSSPBUF�����ݡ�������һ���ֽڵ����ݣ�SSPSR����������SSPBUF��ͬʱ��λI2CIF��SSPSR����ֱ�ӼĴ�����û�������ַ ��غ��� */
void I2Cx_BUF_Write(I2C_Type* I2Cx, uint32_t SetValue)
{
	I2Cx->BUF = (SetValue & I2Cx_BUF_WR_Msk);
}

uint32_t I2Cx_BUF_Read(I2C_Type* I2Cx)
{
	return (I2Cx->BUF & I2Cx_BUF_WR_Msk);
}

/* ����SDA�����SCL�½��صı���ʱ���������I2C����ʱ�Ӽ���
(SDA hold time) ��غ��� */
void I2Cx_TIMING_Write(I2C_Type* I2Cx, uint32_t SetValue)
{
	I2Cx->TIMING  = (SetValue & I2Cx_TIMING_SDAHD_Msk);
}

uint32_t I2Cx_TIMING_Read(I2C_Type* I2Cx)
{
	return (I2Cx->TIMING  & I2Cx_TIMING_SDAHD_Msk);
}

/* ����ӻ�SCL�͵�ƽ��չ��ʱ���ڣ����������MSPEN=0������¸�д
TSCL_STRETCHING_TIMEOUT=TIMEOUT[11:0] * TSCL ��غ��� */
void I2Cx_TO_Write(I2C_Type* I2Cx, uint32_t SetValue)
{
	I2Cx->TO = (SetValue & I2Cx_TO_TIMEOUT_Msk);
}

uint32_t I2Cx_TO_Read(I2C_Type* I2Cx)
{
	return (I2Cx->TO & I2Cx_TO_TIMEOUT_Msk);
}


void I2Cx_Deinit(I2C_Type* I2Cx)
{
	RMU_PRSTEN_Write(0x13579BDF);
	if(I2Cx == I2C0)
	{
		RMU_APBRST2_I2C0RST_Setable(ENABLE);  
		RMU_APBRST2_I2C0RST_Setable(DISABLE);
	}
	if(I2Cx == I2C1)
	{
		RMU_APBRST1_I2C1RST_Setable(ENABLE);  
		RMU_APBRST1_I2C1RST_Setable(DISABLE);
	}
  RMU_PRSTEN_Write(0x00000000);
}

 /********************************
 I2C�����ʼĴ���ֵ���㺯��
���ܣ�I2C�����ʼĴ���ֵ����
���룺����������@Hz�� APBClk @Hz
�����I2CBRG��Ӧ���������ʵ�����ֵ
********************************/
uint32_t I2C_BaudREG_Calc(uint32_t I2CClk, uint32_t APBClk)
{
	uint32_t TempREG;
	
	TempREG = APBClk/(2*I2CClk);
	if( TempREG >= 1 ) TempREG = TempREG - 1;
	
	return TempREG;
}

/******END OF FILE****/
