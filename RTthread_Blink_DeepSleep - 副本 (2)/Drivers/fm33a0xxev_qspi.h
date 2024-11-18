/**
  ******************************************************************************
  * @file    fm33a0xxev_qspi.h
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file contains all the functions prototypes for the QSPI firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33A0XXEV_QSPI_H
#define __FM33A0XXEV_QSPI_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33A0XXEV.h" 

typedef struct
{
    uint32_t Instruction;
    uint32_t Address;
    uint32_t AlternateByte;
    
    uint32_t AddressSize;
    uint32_t AlternateByteSize;
    uint32_t DummyCycles;
    
    uint32_t InstructionMode;
    uint32_t AddressMode;
    uint32_t AlternateByteMode;
    uint32_t DataMode;
}QSPI_CmdTypeDef;
     
#define	QSPI_CR_PRESCALER_Pos	24
#define	QSPI_CR_PRESCALER_Msk	(0xffU << QSPI_CR_PRESCALER_Pos)

#define	QSPI_CR_PMM_Pos	23	/* ��ѯƥ��ģʽ
0��ANDģʽ������bit��ƥ�����λSMF
1��ORģʽ������1bitƥ��ͻ���λSMF */
#define	QSPI_CR_PMM_Msk	(0x1U << QSPI_CR_PMM_Pos)
#define	QSPI_CR_PMM_AND	(0x0U << QSPI_CR_PMM_Pos)	/* ANDģʽ������bit��ƥ�����λSMF */
#define	QSPI_CR_PMM_OR	(0x1U << QSPI_CR_PMM_Pos)	/* ORģʽ������1bitƥ��ͻ���λSMF */

#define	QSPI_CR_TOIE_Pos	20	/* ��ʱ�ж�ʹ��
0����ֹ��ʱ�ж�
1������ʱ�ж� */
#define	QSPI_CR_TOIE_Msk	(0x1U << QSPI_CR_TOIE_Pos)
	/* ��ֹ��ʱ�ж� */
	/* ����ʱ�ж� */

#define	QSPI_CR_SMIE_Pos	19	/* ״̬ƥ���ж�ʹ��
0����ֹ״̬ƥ���ж�
1������״̬ƥ���ж� */
#define	QSPI_CR_SMIE_Msk	(0x1U << QSPI_CR_SMIE_Pos)
	/* ��ֹ״̬ƥ���ж� */
	/* ����״̬ƥ���ж� */

#define	QSPI_CR_FTIE_Pos	18	/* FIFOˮλ�ж�ʹ��
0����ֹFIFOˮλ�ж�
1������FIFOˮλ�ж� */
#define	QSPI_CR_FTIE_Msk	(0x1U << QSPI_CR_FTIE_Pos)
	/* ��ֹFIFOˮλ�ж� */
	/* ����FIFOˮλ�ж� */

#define	QSPI_CR_TCIE_Pos	17	/* ��������ж�ʹ��
0����ֹ��������ж�
1������������ж� */
#define	QSPI_CR_TCIE_Msk	(0x1U << QSPI_CR_TCIE_Pos)
	/* ��ֹ��������ж� */
	/* ����������ж� */

#define	QSPI_CR_TEIE_Pos	16	/* ��������ж�ʹ��
0����ֹ��������ж�
1������������ж� */
#define	QSPI_CR_TEIE_Msk	(0x1U << QSPI_CR_TEIE_Pos)
	/* ��ֹ��������ж� */
	/* ����������ж� */

#define	QSPI_CR_FIFOTHR_Pos	8	/* FIFOˮλ�Ĵ�����������ģʽ����Ч
����дģʽ��
0��FTF��FIFO���ֽڴ��ڵ���1ʱ��λ
1��FTF��FIFO���ֽڴ��ڵ���2ʱ��λ
����
15��FTF��FIFO���ֽڵ���16ʱ��λ
�����ģʽ��
0��FTF��FIFO���ֽ������ڵ���1ʱ��λ
1��FTF��FIFO���ֽ������ڵ���2ʱ��λ
����
15��FTF��FIFO���ֽ�������16ʱ��λ */
#define	QSPI_CR_FIFOTHR_Msk	(0xfU << QSPI_CR_FIFOTHR_Pos)
#define	QSPI_CR_FIFOTHR_1	(0x0U << QSPI_CR_FIFOTHR_Pos)   /* FTF��FIFO���ֽڴ��ڵ���1ʱ��λ */
#define	QSPI_CR_FIFOTHR_2	(0x1U << QSPI_CR_FIFOTHR_Pos)	/* FTF��FIFO���ֽڴ��ڵ���2ʱ��λ */
#define	QSPI_CR_FIFOTHR_3	(0x2U << QSPI_CR_FIFOTHR_Pos)	/* FTF��FIFO���ֽڴ��ڵ���3ʱ��λ */
#define	QSPI_CR_FIFOTHR_4	(0x3U << QSPI_CR_FIFOTHR_Pos)	/* FTF��FIFO���ֽڴ��ڵ���4ʱ��λ */
#define	QSPI_CR_FIFOTHR_5	(0x4U << QSPI_CR_FIFOTHR_Pos)	/* FTF��FIFO���ֽڴ��ڵ���5ʱ��λ */
#define	QSPI_CR_FIFOTHR_6	(0x5U << QSPI_CR_FIFOTHR_Pos)	/* FTF��FIFO���ֽڴ��ڵ���6ʱ��λ */
#define	QSPI_CR_FIFOTHR_7	(0x6U << QSPI_CR_FIFOTHR_Pos)	/* FTF��FIFO���ֽڴ��ڵ���7ʱ��λ */
#define	QSPI_CR_FIFOTHR_8	(0x7U << QSPI_CR_FIFOTHR_Pos)	/* FTF��FIFO���ֽڴ��ڵ���8ʱ��λ */
#define	QSPI_CR_FIFOTHR_9	(0x8U << QSPI_CR_FIFOTHR_Pos)	/* FTF��FIFO���ֽڴ��ڵ���9ʱ��λ */
#define	QSPI_CR_FIFOTHR_10	(0x9U << QSPI_CR_FIFOTHR_Pos)	/* FTF��FIFO���ֽڴ��ڵ���10ʱ��λ */
#define	QSPI_CR_FIFOTHR_11	(0x10U << QSPI_CR_FIFOTHR_Pos)	/* FTF��FIFO���ֽڴ��ڵ���11ʱ��λ */
#define	QSPI_CR_FIFOTHR_12	(0x11U << QSPI_CR_FIFOTHR_Pos)	/* FTF��FIFO���ֽڴ��ڵ���12ʱ��λ */
#define	QSPI_CR_FIFOTHR_13	(0x12U << QSPI_CR_FIFOTHR_Pos)	/* FTF��FIFO���ֽڴ��ڵ���13ʱ��λ */
#define	QSPI_CR_FIFOTHR_14	(0x13U << QSPI_CR_FIFOTHR_Pos)	/* FTF��FIFO���ֽڴ��ڵ���14ʱ��λ */
#define	QSPI_CR_FIFOTHR_15	(0x14U << QSPI_CR_FIFOTHR_Pos)	/* FTF��FIFO���ֽڴ��ڵ���15ʱ��λ */
#define	QSPI_CR_FIFOTHR_16	(0x15U << QSPI_CR_FIFOTHR_Pos)	/* FTF��FIFO���ֽڵ���16ʱ��λ */

#define	QSPI_CR_SSHFT_Pos	4	/* �ӳٲ���ʹ��
0���ر��ӳٲ�������
1��ʹ���ӳٲ������� */
#define	QSPI_CR_SSHFT_Msk	(0x1U << QSPI_CR_SSHFT_Pos)
	/* �ر��ӳٲ������� */
	/* ʹ���ӳٲ������� */

#define	QSPI_CR_TCEN_Pos	3	/* ���߳�ʱʹ�ܣ��˼Ĵ������ڴ洢��ӳ��ģʽ����Ч
��BUSY��λ�����QuadSPI�������QSPI�洢���ķ��ʣ���ʱ�Ĵ�����ʼ�������������������TIMEOUT�Ĵ������塣��QSPI���߳�ʱ���޶����������������nCS���Զ����ߣ�ǿ�ƽ�����ǰ������̡�
0���رճ�ʱ����
1��ʹ�ܳ�ʱ���� */
#define	QSPI_CR_TCEN_Msk	(0x1U << QSPI_CR_TCEN_Pos)
	/* �رճ�ʱ���� */
	/* ʹ�ܳ�ʱ���� */

#define	QSPI_CR_DMAEN_Pos	2	/* DMAʹ��
0��DMA���ܹرգ�QuadSPI���ᷢ��DMA����
1��DMA���ܿ�����QuadSPI����������ʱ����DMA���� */
#define	QSPI_CR_DMAEN_Msk	(0x1U << QSPI_CR_DMAEN_Pos)
	/* DMA���ܹرգ�QuadSPI���ᷢ��DMA���� */
	/* DMA���ܿ�����QuadSPI����������ʱ����DMA���� */

#define	QSPI_CR_ABORT_Pos	1	/* ��ǰ������ֹ�Ĵ��������д1��ֹ���䣬Ӳ������nCS���Զ����� */
#define	QSPI_CR_ABORT_Msk	(0x1U << QSPI_CR_ABORT_Pos)

#define	QSPI_CR_EN_Pos	0	/* QuadSPIģ��ʹ��
0���ر�QuadSPI
1��ʹ��QuadSPI */
#define	QSPI_CR_EN_Msk	(0x1U << QSPI_CR_EN_Pos)
	/* �ر�QuadSPI */
	/* ʹ��QuadSPI */

#define	QSPI_CFG_CSHT_Pos	8	/* nCS��С�ߵ�ƽʱ�䣬��������������֮֡��nCS���豣�ָߵ�ƽ�����ʱ�䣬��QSPI_CLK���ڼ���
0������1 cycle
1������2 cycles
����
7������8 cycles */
#define	QSPI_CFG_CSHT_Msk	(0x7U << QSPI_CFG_CSHT_Pos)
#define	QSPI_CFG_CSHT_1CYCLE	(0x0U << QSPI_CFG_CSHT_Pos)	/* ����1 cycle */
#define	QSPI_CFG_CSHT_2CYCLES	(0x1U << QSPI_CFG_CSHT_Pos)	/* ����2 cycles */
#define	QSPI_CFG_CSHT_3CYCLES	(0x2U << QSPI_CFG_CSHT_Pos)	/* ����3 cycles */
#define	QSPI_CFG_CSHT_4CYCLES	(0x3U << QSPI_CFG_CSHT_Pos)	/* ����4 cycles */
#define	QSPI_CFG_CSHT_5CYCLES	(0x4U << QSPI_CFG_CSHT_Pos)	/* ����5 cycles */
#define	QSPI_CFG_CSHT_6CYCLES	(0x5U << QSPI_CFG_CSHT_Pos)	/* ����6 cycles */
#define	QSPI_CFG_CSHT_7CYCLES	(0x6U << QSPI_CFG_CSHT_Pos)	/* ����7 cycles */
#define	QSPI_CFG_CSHT_8CYCLES	(0x7U << QSPI_CFG_CSHT_Pos)	/* ����8 cycles */

#define	QSPI_CFG_CKMODE_Pos	0	/* SPI Clock Mode�Ĵ���
0��mode 0
1��mode 3 */
#define	QSPI_CFG_CKMODE_Msk	(0x1U << QSPI_CFG_CKMODE_Pos)
#define	QSPI_CFG_CKMODE_MODE0	(0x0U << QSPI_CFG_CKMODE_Pos)	/* mode 0 */
#define	QSPI_CFG_CKMODE_MODE3	(0x1U << QSPI_CFG_CKMODE_Pos)	/* mode 3 */

#define	QSPI_SR_FIFOLVL_Pos	8	/* FIFOˮλ��־
�˼Ĵ�����ʾ��ǰFIFO�б���������ֽ�����0��ʾFIFO�գ�16��ʾFIFO��
�Զ���ѯģʽ�´˼Ĵ�������0 */
#define	QSPI_SR_FIFOLVL_Msk	(0x1fU << QSPI_SR_FIFOLVL_Pos)

#define	QSPI_SR_BUSY_Pos	5	/* 1��ʾQuadSPI��������У�ͨ�Ž������Զ����� */
#define	QSPI_SR_BUSY_Msk	(0x1U << QSPI_SR_BUSY_Pos)

#define	QSPI_SR_TOF_Pos	4	/* ��ʱ��־��Ӳ����λ�����д1���� */
#define	QSPI_SR_TOF_Msk	(0x1U << QSPI_SR_TOF_Pos)

#define	QSPI_SR_SMF_Pos	3	/* �Զ���ѯģʽ�±���״̬�Ĵ���ƥ��ɹ���Ӳ����λ�����д1���� */
#define	QSPI_SR_SMF_Msk	(0x1U << QSPI_SR_SMF_Pos)

#define	QSPI_SR_FTF_Pos	2	/* FIFO threshold��־��FIFOˮλ�����趨��ֵʱ�Զ���λ��������ֵʱ�Զ�����
�Զ���ѯģʽ�£�ÿ�ζ���һ��״ֵ̬�󶼻��Զ���λFTF����������ȡQSPI_DATA�Ĵ�����FTF���� */
#define	QSPI_SR_FTF_Msk	(0x1U << QSPI_SR_FTF_Pos)

#define	QSPI_SR_TCF_Pos	1	/* ������ɱ�־��Ӳ����λ�����д1���� */
#define	QSPI_SR_TCF_Msk	(0x1U << QSPI_SR_TCF_Pos)

#define	QSPI_DATALEN_QSPI_DATALEN_Pos	0	/* �������ݳ���ΪDATALEN+1��bytes�� */
#define	QSPI_DATALEN_QSPI_DATALEN_Msk	(0xffffffffU << QSPI_DATALEN_QSPI_DATALEN_Pos)

#define	QSPI_CCR_CRM_Pos	28	/* Continuous Read Mode
0��ÿ��ͨ�ŷ���ʱ��Ҫ����ָ��
1��ֻ�ڵ�һ��ͨ��ʱ����ָ�� */
#define	QSPI_CCR_CRM_Msk	(0x1U << QSPI_CCR_CRM_Pos)
#define	QSPI_CCR_CRM_ALWAYS	(0x0U << QSPI_CCR_CRM_Pos)	/* ÿ��ͨ�ŷ���ʱ��Ҫ����ָ�� */
#define	QSPI_CCR_CRM_ONLY	(0x1U << QSPI_CCR_CRM_Pos)	/* ֻ�ڵ�һ��ͨ��ʱ����ָ�� */

#define	QSPI_CCR_OPMODE_Pos	26	/* ����ģʽ
00������дģʽ
01�������ģʽ
10���Զ���ѯģʽ
11���洢��ӳ��ģʽ */
#define	QSPI_CCR_OPMODE_Msk	    (0x3U << QSPI_CCR_OPMODE_Pos)
#define	QSPI_CCR_OPMODE_WRITE	(0x0U << QSPI_CCR_OPMODE_Pos)	/* ����дģʽ */
#define	QSPI_CCR_OPMODE_READ	(0x1U << QSPI_CCR_OPMODE_Pos)	/* �����ģʽ */
#define	QSPI_CCR_OPMODE_QUERY	(0x2U << QSPI_CCR_OPMODE_Pos)	/* �Զ���ѯģʽ */
#define	QSPI_CCR_OPMODE_MAP	    (0x3U << QSPI_CCR_OPMODE_Pos)	/* �洢��ӳ��ģʽ */

#define	QSPI_CCR_DMODE_Pos	24	/* ����ͨ��ģʽ��data phase��
00��������
01������
10��˫��
11������ */
#define	QSPI_CCR_DMODE_Msk	    (0x3U << QSPI_CCR_DMODE_Pos)
#define	QSPI_CCR_DMODE_NONE	    (0x0U << QSPI_CCR_DMODE_Pos)	/* ������ */
#define	QSPI_CCR_DMODE_SINGLE	(0x1U << QSPI_CCR_DMODE_Pos)	/* ���� */
#define	QSPI_CCR_DMODE_DOUBLE	(0x2U << QSPI_CCR_DMODE_Pos)	/* ˫�� */
#define	QSPI_CCR_DMODE_FOUR	    (0x3U << QSPI_CCR_DMODE_Pos)	/* ���� */

#define	QSPI_CCR_DUMCYC_Pos	18	/* Dummy cycle�������ã���QSPI_CLK���ڼ��㣩��0~31 */
#define	QSPI_CCR_DUMCYC_Msk	(0x1fU << QSPI_CCR_DUMCYC_Pos)

#define	QSPI_CCR_ABSIZE_Pos	16	/* Alternate bytes����
00��8bits alternate bytes
01��16bits alternate bytes
10��24bits alternate bytes
11��32bits alternate bytes */
#define	QSPI_CCR_ABSIZE_Msk	    (0x3U << QSPI_CCR_ABSIZE_Pos)
#define	QSPI_CCR_ABSIZE_8BITS	(0x0U << QSPI_CCR_ABSIZE_Pos)	/* 8bits alternate bytes */
#define	QSPI_CCR_ABSIZE_16BITS	(0x1U << QSPI_CCR_ABSIZE_Pos)	/* 16bits alternate bytes */
#define	QSPI_CCR_ABSIZE_24BITS	(0x2U << QSPI_CCR_ABSIZE_Pos)	/* 24bits alternate bytes */
#define	QSPI_CCR_ABSIZE_32BITS	(0x3U << QSPI_CCR_ABSIZE_Pos)	/* 32bits alternate bytes */

#define	QSPI_CCR_ABMODE_Pos	14	/* Alternate bytes����ģʽ
00����alternate bytes
01������
10��˫��
11������ */
#define	QSPI_CCR_ABMODE_Msk	    (0x3U << QSPI_CCR_ABMODE_Pos)
#define	QSPI_CCR_ABMODE_NONE	(0x0U << QSPI_CCR_ABMODE_Pos)	/* ��alternate bytes */
#define	QSPI_CCR_ABMODE_SINGLE	(0x1U << QSPI_CCR_ABMODE_Pos)	/* ���� */
#define	QSPI_CCR_ABMODE_DOUBLE	(0x2U << QSPI_CCR_ABMODE_Pos)	/* ˫�� */
#define	QSPI_CCR_ABMODE_FOUR	(0x3U << QSPI_CCR_ABMODE_Pos)	/* ���� */

#define	QSPI_CCR_ADSIZE_Pos	12	/* ��ַ�ֽڳ���
00��8bits��ַ
01��16bits��ַ
10��24bits��ַ
11��32bits��ַ */
#define	QSPI_CCR_ADSIZE_Msk	    (0x3U << QSPI_CCR_ADSIZE_Pos)
#define	QSPI_CCR_ADSIZE_8BITS	(0x0U << QSPI_CCR_ADSIZE_Pos)	/* 8bits��ַ */
#define	QSPI_CCR_ADSIZE_16BITS	(0x1U << QSPI_CCR_ADSIZE_Pos)	/* 16bits��ַ */
#define	QSPI_CCR_ADSIZE_24BITS	(0x2U << QSPI_CCR_ADSIZE_Pos)	/* 24bits��ַ */
#define	QSPI_CCR_ADSIZE_32BITS	(0x3U << QSPI_CCR_ADSIZE_Pos)	/* 32bits��ַ */

#define	QSPI_CCR_ADMODE_Pos	10	/* ��ַ�ֽڷ���ģʽ
00���޵�ַ�ֽ�
01������
10��˫��
11������ */
#define	QSPI_CCR_ADMODE_Msk	    (0x3U << QSPI_CCR_ADMODE_Pos)
#define	QSPI_CCR_ADMODE_NONE	(0x0U << QSPI_CCR_ADMODE_Pos)	/* �޵�ַ�ֽ� */
#define	QSPI_CCR_ADMODE_SINGLE	(0x1U << QSPI_CCR_ADMODE_Pos)	/* ���� */
#define	QSPI_CCR_ADMODE_DOUBLE	(0x2U << QSPI_CCR_ADMODE_Pos)	/* ˫�� */
#define	QSPI_CCR_ADMODE_FOUR	(0x3U << QSPI_CCR_ADMODE_Pos)	/* ���� */

#define	QSPI_CCR_IMODE_Pos	8	/* ָ���ģʽ
00����ָ���ֽ�
01������
10��˫��
11������ */
#define	QSPI_CCR_IMODE_Msk	    (0x3U << QSPI_CCR_IMODE_Pos)
#define	QSPI_CCR_IMODE_NONE	    (0x0U << QSPI_CCR_IMODE_Pos)	/* ��ָ���ֽ� */
#define	QSPI_CCR_IMODE_SINGLE	(0x1U << QSPI_CCR_IMODE_Pos)	/* ���� */
#define	QSPI_CCR_IMODE_DOUBLE	(0x2U << QSPI_CCR_IMODE_Pos)	/* ˫�� */
#define	QSPI_CCR_IMODE_FOUR	    (0x3U << QSPI_CCR_IMODE_Pos)	/* ���� */

#define	QSPI_CCR_INSTRUCTION_Pos	0	/* QuadSPI���͵�ָ���ֽ� */
#define	QSPI_CCR_INSTRUCTION_Msk	(0xffU << QSPI_CCR_INSTRUCTION_Pos)

#define	QSPI_ADDR_QSPI_ADDR_Pos	0	/* ���͸�QSPI�洢���ĵ�ַ���ڴ洢��ӳ��ģʽ����Ч */
#define	QSPI_ADDR_QSPI_ADDR_Msk	(0xffffffffU << QSPI_ADDR_QSPI_ADDR_Pos)

#define	QSPI_ABR_QSPI_ABR_Pos	0	/* ���͸�QSPI�洢����alternate bytes */
#define	QSPI_ABR_QSPI_ABR_Msk	(0xffffffffU << QSPI_ABR_QSPI_ABR_Pos)

#define	QSPI_DR_QSPI_DATA_Pos	0	/* QSPI���ݼĴ���
����ģʽд����ʱ����QSPI_DR�Ĵ���д������ݽ���push FIFO��֧���ֽڡ����֡���д�룬�ֱ��FIFOѹ��1��2��4�ֽڣ����д���ֽ�������FIFO�п��ֽ�������ǰд����������ֱ��FIFO�����㹻�ռ����ɵ�ǰд�����ݡ�
����ģʽ������ʱ����ȡQSPI_DR�Ĵ�����pop FIFO��֧���ֽڡ����֡��ֶ�ȡ���ֱ��FIFO����1��2��4�ֽڣ������ȡ�ֽ�������FIFO����Ч�ֽ�������ǰ������������ֱ��FIFO�����㹻�ֽڿ��Ա���ȡ�����ߴ�����ɣ���һ�������ֻ������󼸸�ʵ����Ч�ֽڡ�
��QSPI_DR�ķ��ʱ������͵�ַ�����ֽڷ��ʱ������QSPI_DR[7:0]�����ַ��ʱ������QSPI_DR[15:0] */
#define	QSPI_DR_QSPI_DATA_Msk	(0xffffffffU << QSPI_DR_QSPI_DATA_Pos)

#define	QSPI_SMSK_QSPI_SMSK_Pos	0	/* �Զ�״̬��ѯģʽ�µ�״̬mask�Ĵ�������Ӧbitд0������Ӧ״̬λ */
#define	QSPI_SMSK_QSPI_SMSK_Msk	(0xffffffffU << QSPI_SMSK_QSPI_SMSK_Pos)

#define	QSPI_SMAT_QSPI_SMAT_Pos	0	/* �Զ�״̬��ѯģʽ�µ�״̬ƥ��Ĵ���
�Ƚ϶�����QSPI_DATA & QSPI_SMSK */
#define	QSPI_SMAT_QSPI_SMAT_Msk	(0xffffffffU << QSPI_SMAT_QSPI_SMAT_Pos)

#define	QSPI_PITV_QSPI_PITV_Pos	0	/* �Զ�״̬��ѯģʽ�µ���ѯ�����polling interval��������ΪQSPI_CLK������ */
#define	QSPI_PITV_QSPI_PITV_Msk	(0xffffU << QSPI_PITV_QSPI_PITV_Pos)

#define	QSPI_TO_QSPI_TO_Pos	0	/* ��ʱ�������ã�����ΪQSPI_CLK�����������ڴ洢��ӳ��ģʽ����Ч
��FIFO��֮��QSPI������Ϊֹͣ����ʱ��������ʼ����������ֵ����QSPI_TO�趨ֵ֮������nCS */
#define	QSPI_TO_QSPI_TO_Msk	(0xffffU << QSPI_TO_QSPI_TO_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void QSPI_Deinit(void);
extern void QSPI_CR_PRESCALER_Set(uint32_t SetValue);
extern uint32_t QSPI_CR_PRESCALER_Get(void);

/* ��ѯƥ��ģʽ
0��ANDģʽ������bit��ƥ�����λSMF
1��ORģʽ������1bitƥ��ͻ���λSMF ��غ��� */
extern void QSPI_CR_PMM_Set(uint32_t SetValue);
extern uint32_t QSPI_CR_PMM_Get(void);

/* ��ʱ�ж�ʹ��
0����ֹ��ʱ�ж�
1������ʱ�ж� ��غ��� */
extern void QSPI_CR_TOIE_Setable(FunState NewState);
extern FunState QSPI_CR_TOIE_Getable(void);

/* ״̬ƥ���ж�ʹ��
0����ֹ״̬ƥ���ж�
1������״̬ƥ���ж� ��غ��� */
extern void QSPI_CR_SMIE_Setable(FunState NewState);
extern FunState QSPI_CR_SMIE_Getable(void);

/* FIFOˮλ�ж�ʹ��
0����ֹFIFOˮλ�ж�
1������FIFOˮλ�ж� ��غ��� */
extern void QSPI_CR_FTIE_Setable(FunState NewState);
extern FunState QSPI_CR_FTIE_Getable(void);

/* ��������ж�ʹ��
0����ֹ��������ж�
1������������ж� ��غ��� */
extern void QSPI_CR_TCIE_Setable(FunState NewState);
extern FunState QSPI_CR_TCIE_Getable(void);

/* ��������ж�ʹ��
0����ֹ��������ж�
1������������ж� ��غ��� */
extern void QSPI_CR_TEIE_Setable(FunState NewState);
extern FunState QSPI_CR_TEIE_Getable(void);

/* FIFOˮλ�Ĵ�����������ģʽ����Ч
����дģʽ��
0��FTF��FIFO���ֽڴ��ڵ���1ʱ��λ
1��FTF��FIFO���ֽڴ��ڵ���2ʱ��λ
����
15��FTF��FIFO���ֽڵ���16ʱ��λ
�����ģʽ��
0��FTF��FIFO���ֽ������ڵ���1ʱ��λ
1��FTF��FIFO���ֽ������ڵ���2ʱ��λ
����
15��FTF��FIFO���ֽ�������16ʱ��λ ��غ��� */
extern void QSPI_CR_FIFOTHR_Set(uint32_t SetValue);
extern uint32_t QSPI_CR_FIFOTHR_Get(void);

/* �ӳٲ���ʹ��
0���ر��ӳٲ�������
1��ʹ���ӳٲ������� ��غ��� */
extern void QSPI_CR_SSHFT_Setable(FunState NewState);
extern FunState QSPI_CR_SSHFT_Getable(void);

/* ���߳�ʱʹ�ܣ��˼Ĵ������ڴ洢��ӳ��ģʽ����Ч
��BUSY��λ�����QuadSPI�������QSPI�洢���ķ��ʣ���ʱ�Ĵ�����ʼ�������������������TIMEOUT�Ĵ������塣��QSPI���߳�ʱ���޶����������������nCS���Զ����ߣ�ǿ�ƽ�����ǰ������̡�
0���رճ�ʱ����
1��ʹ�ܳ�ʱ���� ��غ��� */
extern void QSPI_CR_TCEN_Setable(FunState NewState);
extern FunState QSPI_CR_TCEN_Getable(void);

/* DMAʹ��
0��DMA���ܹرգ�QuadSPI���ᷢ��DMA����
1��DMA���ܿ�����QuadSPI����������ʱ����DMA���� ��غ��� */
extern void QSPI_CR_DMAEN_Setable(FunState NewState);
extern FunState QSPI_CR_DMAEN_Getable(void);

/* ��ǰ������ֹ�Ĵ��������д1��ֹ���䣬Ӳ������nCS���Զ����� ��غ��� */
extern void QSPI_CR_ABORT_Setable(FunState NewState);
extern FunState QSPI_CR_ABORT_Getable(void);

/* QuadSPIģ��ʹ��
0���ر�QuadSPI
1��ʹ��QuadSPI ��غ��� */
extern void QSPI_CR_EN_Setable(FunState NewState);
extern FunState QSPI_CR_EN_Getable(void);

/* nCS��С�ߵ�ƽʱ�䣬��������������֮֡��nCS���豣�ָߵ�ƽ�����ʱ�䣬��QSPI_CLK���ڼ���
0������1 cycle
1������2 cycles
����
7������8 cycles ��غ��� */
extern void QSPI_CFG_CSHT_Set(uint32_t SetValue);
extern uint32_t QSPI_CFG_CSHT_Get(void);

/* SPI Clock Mode�Ĵ���
0��mode 0
1��mode 3 ��غ��� */
extern void QSPI_CFG_CKMODE_Set(uint32_t SetValue);
extern uint32_t QSPI_CFG_CKMODE_Get(void);

/* FIFOˮλ��־
�˼Ĵ�����ʾ��ǰFIFO�б���������ֽ�����0��ʾFIFO�գ�16��ʾFIFO��
�Զ���ѯģʽ�´˼Ĵ�������0 ��غ��� */
extern uint32_t QSPI_SR_FIFOLVL_Get(void);

/* 1��ʾQuadSPI��������У�ͨ�Ž������Զ����� ��غ��� */
extern FlagStatus QSPI_SR_BUSY_Chk(void);

/* ��ʱ��־��Ӳ����λ�����д1���� ��غ��� */
extern void QSPI_SR_TOF_Clr(void);
extern FlagStatus QSPI_SR_TOF_Chk(void);

/* �Զ���ѯģʽ�±���״̬�Ĵ���ƥ��ɹ���Ӳ����λ�����д1���� ��غ��� */
extern void QSPI_SR_SMF_Clr(void);
extern FlagStatus QSPI_SR_SMF_Chk(void);

/* FIFO threshold��־��FIFOˮλ�����趨��ֵʱ�Զ���λ��������ֵʱ�Զ�����
�Զ���ѯģʽ�£�ÿ�ζ���һ��״ֵ̬�󶼻��Զ���λFTF����������ȡQSPI_DATA�Ĵ�����FTF���� ��غ��� */
extern FlagStatus QSPI_SR_FTF_Chk(void);

/* ������ɱ�־��Ӳ����λ�����д1���� ��غ��� */
extern void QSPI_SR_TCF_Clr(void);
extern FlagStatus QSPI_SR_TCF_Chk(void);

/* �������ݳ���ΪDATALEN+1��bytes�� ��غ��� */
extern void QSPI_DATALEN_Write(uint32_t SetValue);
extern uint32_t QSPI_DATALEN_Read(void);

/* QuadSPI ͨ�ſ��ƼĴ��� ��غ��� */
#define QSPI_CCR_DUMCYC_SET(value)          ((value << QSPI_CCR_DUMCYC_Pos) & QSPI_CCR_DUMCYC_Msk)
#define QSPI_CCR_DUMCYC_GET(value)          ((value >> QSPI_CCR_DUMCYC_Pos) & QSPI_CCR_DUMCYC_Msk)
#define QSPI_CCR_INSTRUCTION_SET(value)     ((value << QSPI_CCR_INSTRUCTION_Pos) & QSPI_CCR_INSTRUCTION_Msk)
#define QSPI_CCR_INSTRUCTION_GET(value)     ((value >> QSPI_CCR_INSTRUCTION_Pos) & QSPI_CCR_INSTRUCTION_Msk)

extern void QSPI_CCR_Write(uint32_t SetValue);
extern uint32_t QSPI_CCR_Read(void);

/* ���͸�QSPI�洢���ĵ�ַ���ڴ洢��ӳ��ģʽ����Ч ��غ��� */
extern void QSPI_ADDR_Write(uint32_t SetValue);
extern uint32_t QSPI_ADDR_Read(void);

/* ���͸�QSPI�洢����alternate bytes ��غ��� */
extern void QSPI_ABR_Write(uint32_t SetValue);
extern uint32_t QSPI_ABR_Read(void);

/* QSPI���ݼĴ���
����ģʽд����ʱ����QSPI_DR�Ĵ���д������ݽ���push FIFO��֧���ֽڡ����֡���д�룬�ֱ��FIFOѹ��1��2��4�ֽڣ����д���ֽ�������FIFO�п��ֽ�������ǰд����������ֱ��FIFO�����㹻�ռ����ɵ�ǰд�����ݡ�
����ģʽ������ʱ����ȡQSPI_DR�Ĵ�����pop FIFO��֧���ֽڡ����֡��ֶ�ȡ���ֱ��FIFO����1��2��4�ֽڣ������ȡ�ֽ�������FIFO����Ч�ֽ�������ǰ������������ֱ��FIFO�����㹻�ֽڿ��Ա���ȡ�����ߴ�����ɣ���һ�������ֻ������󼸸�ʵ����Ч�ֽڡ�
��QSPI_DR�ķ��ʱ������͵�ַ�����ֽڷ��ʱ������QSPI_DR[7:0]�����ַ��ʱ������QSPI_DR[15:0] ��غ��� */
extern void QSPI_DR_WriteByte(uint8_t SetValue);
extern uint8_t QSPI_DR_ReadByte(void);
extern void QSPI_DR_WriteHalfword(uint16_t SetValue);
extern uint16_t QSPI_DR_ReadHalfword(void);
extern void QSPI_DR_WriteWord(uint32_t SetValue);
extern uint32_t QSPI_DR_ReadWord(void);

/* �Զ�״̬��ѯģʽ�µ�״̬mask�Ĵ�������Ӧbitд0������Ӧ״̬λ ��غ��� */
extern void QSPI_SMSK_Write(uint32_t SetValue);
extern uint32_t QSPI_SMSK_Read(void);

/* �Զ�״̬��ѯģʽ�µ�״̬ƥ��Ĵ���
�Ƚ϶�����QSPI_DATA & QSPI_SMSK ��غ��� */
extern void QSPI_SMAT_Write(uint32_t SetValue);
extern uint32_t QSPI_SMAT_Read(void);

/* �Զ�״̬��ѯģʽ�µ���ѯ�����polling interval��������ΪQSPI_CLK������ ��غ��� */
extern void QSPI_PITV_Write(uint32_t SetValue);
extern uint32_t QSPI_PITV_Read(void);

/* ��ʱ�������ã�����ΪQSPI_CLK�����������ڴ洢��ӳ��ģʽ����Ч
��FIFO��֮��QSPI������Ϊֹͣ����ʱ��������ʼ����������ֵ����QSPI_TO�趨ֵ֮������nCS ��غ��� */
extern void QSPI_TO_Write(uint32_t SetValue);
extern uint32_t QSPI_TO_Read(void);

//Announce_End
void QSPI_Deinit(void);
void QSPI_Init(void);


#ifdef __cplusplus
}
#endif

#endif /* __FM33A0XXEV_QSPI_H */
