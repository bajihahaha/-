/**
  ******************************************************************************
  * @file    fm33a0xxev_dma.h
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file contains all the functions prototypes for the DMA firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33A0XXEV_DMA_H
#define __FM33A0XXEV_DMA_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33A0XXEV.h" 

typedef enum {
    DMA_CH0 = 0, DMA_CH1 = 1, DMA_CH2 = 2, DMA_CH3 = 3, DMA_CH4 = 4, DMA_CH5 = 5, DMA_CH6 = 6, DMA_CH7 = 7,	
    DMA_CH8 = 8, DMA_CH9 = 9, DMA_CH10 = 10, DMA_CH11 = 11
}DMA_CH_Type;

typedef struct
{
	DMA_CH_Type CHx;			//DMAͨ����
	uint32_t CHxTSIZE;          //ͨ�����䳤��
	uint32_t CHxPRI;            //ͨ�����ȼ�
	uint32_t CHxINC;            //CH0~CH10ͨ����ַ��������,CH11������
	uint32_t CHxSSEL;           //CH0~CH10����ͨ��ѡ��,CH11���䷽ʽѡ��
    uint32_t CHxDIR;            //CH0~CH10ͨ�����䷽��
    uint32_t CHxBDW;            //CH0~CH10ͨ���������
    FunState CHxCICR;           //CH0~CH10ѭ������ģʽ
	FunState CHxFTIE;           //ͨ����������ж�ʹ��
	FunState CHxHTIE;           //ͨ���������ж�ʹ��
	FunState CHxEN;             //ͨ��ʹ��
	uint32_t CHxRAMAD;          //CH0~CH11ͨ��RAMָ���ַ,ע��CH11ʹ�õ���word��ַ���������Ѵ�����ˣ�

    uint32_t CH11RI;            // RAM��ַ��������(��Flash��RAM��Ч)
    uint32_t CH11FI;            // FLS��ַ��������(��Flash��RAM��Ч)
	uint32_t CH11FLSAD;			//ͨ��FLASHָ���ַ�������ͨ��11������	
}DMA_InitTypeDef;

#define	DMA_GCR_DMA_ADDRERR_EN_Pos	1	/* DMA�����ַ�ж�ʹ��
1����������ַ�ж�
0����ֹ�����ַ�ж� */
#define	DMA_GCR_DMA_ADDRERR_EN_Msk	(0x1U << DMA_GCR_DMA_ADDRERR_EN_Pos)

#define	DMA_GCR_DMAEN_Pos	0	/* DMAȫ��ʹ��
1��DMAʹ��
0��DMA�ر� */
#define	DMA_GCR_DMAEN_Msk	(0x1U << DMA_GCR_DMAEN_Pos)

#define	DMA_CHxCR_CHxTSIZE_Pos	16	/* Channelx���䳤�ȣ�1-8192�δ��� */
#define	DMA_CHxCR_CHxTSIZE_Msk	(0x1fffU << DMA_CHxCR_CHxTSIZE_Pos)

#define	DMA_CHxCR_CHxPRI_Pos	12	/* Channelx���ȼ�
00��Low
01��Medium
10��High
11��Very High */
#define	DMA_CHxCR_CHxPRI_Msk	(0x3U << DMA_CHxCR_CHxPRI_Pos)
#define	DMA_CHxCR_CHxPRI_LOW	(0x0U << DMA_CHxCR_CHxPRI_Pos)	/* Low */
#define	DMA_CHxCR_CHxPRI_MEDIUM	(0x1U << DMA_CHxCR_CHxPRI_Pos)	/* Medium */
#define	DMA_CHxCR_CHxPRI_HIGH	(0x2U << DMA_CHxCR_CHxPRI_Pos)	/* High */
#define	DMA_CHxCR_CHxPRI_VERY_HIGH	(0x3U << DMA_CHxCR_CHxPRI_Pos)	/* Very High */

#define	DMA_CHxCR_CHxINC_Pos	11	/* RAM��ַ��������
1��RAM��ַ����
0��RAM��ַ�ݼ� */
#define	DMA_CHxCR_CHxINC_Msk	(0x1U << DMA_CHxCR_CHxINC_Pos)
#define	DMA_CHxCR_CHxINC_INCREASE	(0x1U << DMA_CHxCR_CHxINC_Pos)	/* RAM��ַ���� */
#define	DMA_CHxCR_CHxINC_DECREASE	(0x0U << DMA_CHxCR_CHxINC_Pos)	/* RAM��ַ�ݼ� */

#define	DMA_CHxCR_CHxSSEL_Pos	8	/* Channelx��������ӳ��
ÿ��ͨ�����Խ���8�������������������ӳ��μ�23.6.1DMA����ӳ�� */
#define	DMA_CHxCR_CHxSSEL_Msk	(0x7U << DMA_CHxCR_CHxSSEL_Pos)

#define DMA_CHxCR_CH0SSEL_ADC               (0x0U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH0SSEL_SPI3_RX           (0x1U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH0SSEL_LPUART0_RX        (0x2U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH0SSEL_LPUART1_RX        (0x3U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH0SSEL_UART2_RX          (0x4U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH0SSEL_UART4_RX          (0x5U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH0SSEL_AES_IN            (0x6U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH0SSEL_QSPI              (0x7U << DMA_CHxCR_CHxSSEL_Pos)

#define DMA_CHxCR_CH1SSEL_ADC               (0x0U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH1SSEL_SPI0_RX           (0x1U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH1SSEL_SPI2_RX           (0x2U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH1SSEL_SPI3_TX           (0x3U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH1SSEL_UART0_RX          (0x4U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH1SSEL_UART2_TX          (0x5U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH1SSEL_UART3_RX          (0x6U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH1SSEL_U7816_RX          (0x7U << DMA_CHxCR_CHxSSEL_Pos)

#define DMA_CHxCR_CH2SSEL_SPI0_TX           (0x0U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH2SSEL_SPI2_TX           (0x1U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH2SSEL_SPI4_RX           (0x2U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH2SSEL_UART0_TX          (0x3U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH2SSEL_UART3_TX          (0x4U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH2SSEL_UART5_RX          (0x5U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH2SSEL_U7816_TX          (0x6U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH2SSEL_AES_OUT           (0x7U << DMA_CHxCR_CHxSSEL_Pos)

#define DMA_CHxCR_CH3SSEL_SPI1_RX           (0x0U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH3SSEL_SPI4_TX           (0x1U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH3SSEL_LPUART0_RX        (0x2U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH3SSEL_UART1_RX          (0x3U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH3SSEL_UART4_RX          (0x4U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH3SSEL_UART5_TX          (0x5U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH3SSEL_I2C0_TX           (0x6U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH3SSEL_AES_IN            (0x7U << DMA_CHxCR_CHxSSEL_Pos)

#define DMA_CHxCR_CH4SSEL_SPI1_TX           (0x0U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH4SSEL_SPI3_RX           (0x1U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH4SSEL_LPUART0_TX        (0x2U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH4SSEL_UART1_TX          (0x3U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH4SSEL_UART2_RX          (0x4U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH4SSEL_UART4_TX          (0x5U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH4SSEL_I2C0_RX           (0x6U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH4SSEL_AES_OUT           (0x7U << DMA_CHxCR_CHxSSEL_Pos)

#define DMA_CHxCR_CH5SSEL_SPI0_RX           (0x0U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH5SSEL_SPI2_RX           (0x1U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH5SSEL_LPUART1_RX        (0x2U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH5SSEL_UART1_RX          (0x3U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH5SSEL_UART2_TX          (0x4U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH5SSEL_UART3_RX          (0x5U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH5SSEL_UART5_RX          (0x6U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH5SSEL_I2C1_TX           (0x7U << DMA_CHxCR_CHxSSEL_Pos)

#define DMA_CHxCR_CH6SSEL_SPI0_TX           (0x0U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH6SSEL_SPI2_TX           (0x1U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH6SSEL_LPUART1_TX        (0x2U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH6SSEL_UART1_TX          (0x3U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH6SSEL_UART3_TX          (0x4U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH6SSEL_UART5_TX          (0x5U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH6SSEL_I2C1_RX           (0x6U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH6SSEL_CRC               (0x7U << DMA_CHxCR_CHxSSEL_Pos)

#define DMA_CHxCR_CH7SSEL_ADC               (0x0U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH7SSEL_SPI1_RX           (0x1U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH7SSEL_SPI3_RX           (0x2U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH7SSEL_LPUART0_RX        (0x3U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH7SSEL_UART0_RX          (0x4U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH7SSEL_UART2_RX          (0x5U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH7SSEL_UART4_RX          (0x6U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH7SSEL_QSPI              (0x7U << DMA_CHxCR_CHxSSEL_Pos)

#define DMA_CHxCR_CH8SSEL_ADC               (0x0U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH8SSEL_SPI1_TX           (0x1U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH8SSEL_SPI2_RX           (0x2U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH8SSEL_SPI3_TX           (0x3U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH8SSEL_LPUART0_TX        (0x4U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH8SSEL_UART0_TX          (0x5U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH8SSEL_UART2_TX          (0x6U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH8SSEL_UART4_TX          (0x7U << DMA_CHxCR_CHxSSEL_Pos)

#define DMA_CHxCR_CH9SSEL_SPI0_RX           (0x0U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH9SSEL_SPI2_TX           (0x1U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH9SSEL_SPI4_RX           (0x2U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH9SSEL_LPUART1_RX        (0x3U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH9SSEL_UART1_RX          (0x4U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH9SSEL_UART3_RX          (0x5U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH9SSEL_UART5_RX          (0x6U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH9SSEL_I2C0_TX           (0x7U << DMA_CHxCR_CHxSSEL_Pos)

#define DMA_CHxCR_CH10SSEL_SPI0_TX          (0x0U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH10SSEL_SPI4_TX          (0x1U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH10SSEL_LPUART1_TX       (0x2U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH10SSEL_UART1_TX         (0x3U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH10SSEL_UART3_TX         (0x4U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH10SSEL_UART5_TX         (0x5U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH10SSEL_I2C0_RX          (0x6U << DMA_CHxCR_CHxSSEL_Pos)
#define DMA_CHxCR_CH10SSEL_CRC              (0x7U << DMA_CHxCR_CHxSSEL_Pos)

#define	DMA_CHxCR_CIRC_UPD_Pos	7	/* ѭ������ģʽ���Զ����´�����������ִ�����ɺ�shadow�Ĵ������ݸ��Ƶ����ƼĴ���
0����ֹ�Զ�����
1��ʹ���Զ�����
ע�⣺��ͨ��0~6֧�ִ˹��ܣ�ͨ��7~10�޴˼Ĵ��� */
#define	DMA_CHxCR_CIRC_UPD_Msk	(0x1U << DMA_CHxCR_CIRC_UPD_Pos)
	/* ��ֹ�Զ����� */
	/* ʹ���Զ����� */
	/* ��ͨ��0~6֧�ִ˹��ܣ�ͨ��7~10�޴˼Ĵ��� */

#define	DMA_CHxCR_DIR_Pos	6	/* ͨ�����䷽��
0���������ȡ����д��RAM
1����RAM��ȡ����д������ */
#define	DMA_CHxCR_DIR_Msk	(0x1U << DMA_CHxCR_DIR_Pos)
#define	DMA_CHxCR_DIR_TO_RAM	(0x0U << DMA_CHxCR_DIR_Pos)	/* �������ȡ����д��RAM */
#define	DMA_CHxCR_DIR_TO_PER	(0x1U << DMA_CHxCR_DIR_Pos)	/* ��RAM��ȡ����д������ */

#define	DMA_CHxCR_BDW_Pos	4	/* �����������
00���ֽڣ�8bit
01�����֣�16bit
10���֣�32bit
11��RFU */
#define	DMA_CHxCR_BDW_Msk	(0x3U << DMA_CHxCR_BDW_Pos)
#define	DMA_CHxCR_BDW_8BITS	(0x0U << DMA_CHxCR_BDW_Pos)	/* �ֽڣ�8bit */
#define	DMA_CHxCR_BDW_16BITS	(0x1U << DMA_CHxCR_BDW_Pos)	/* ���֣�16bit */
#define	DMA_CHxCR_BDW_32BITS	(0x2U << DMA_CHxCR_BDW_Pos)	/* �֣�32bit */

#define	DMA_CHxCR_CIRC_Pos	3	/* ѭ������ģʽ
0���ر�ѭ��ģʽ
1��ʹ��ѭ��ģʽ */
#define	DMA_CHxCR_CIRC_Msk	(0x1U << DMA_CHxCR_CIRC_Pos)
	/* �ر�ѭ��ģʽ */
	/* ʹ��ѭ��ģʽ */

#define	DMA_CHxCR_CHxFTIE_Pos	2	/* Channelx��������ж�ʹ��
1��ʹ�ܴ�������ж�
0���رմ�������ж� */
#define	DMA_CHxCR_CHxFTIE_Msk	(0x1U << DMA_CHxCR_CHxFTIE_Pos)
	/* ʹ�ܴ�������ж� */
	/* �رմ�������ж� */

#define	DMA_CHxCR_CHxHTIE_Pos	1	/* Channelx��̴�������ж�ʹ��
1��ʹ�ܰ���ж�
0���رհ���ж� */
#define	DMA_CHxCR_CHxHTIE_Msk	(0x1U << DMA_CHxCR_CHxHTIE_Pos)
	/* ʹ�ܰ���ж� */
	/* �رհ���ж� */

#define	DMA_CHxCR_ChxEN_Pos	0	/* Channelxʹ��
1������ͨ��0
0���ر�ͨ��0 */
#define	DMA_CHxCR_ChxEN_Msk	(0x1U << DMA_CHxCR_ChxEN_Pos)
	/* ����ͨ��0 */
	/* �ر�ͨ��0 */

#define	DMA_CHxMAR_CHxMEMAD_Pos	0	/* Channelx�洢��ָ���ַ��DMA��������ǰ�����˼Ĵ���д��洢��Ŀ���ַ��
��ָ��ָ��յ�ַʱ��DMA���ʽ�����hardfault
��ָ��ָ��Flashʱ����ֹ��Flashд�����ݡ�
������Բ�ѯ��ǰDMA�����Ŀ��洢����ַ��

ע�⣺��ָ���ָֹ��0x00080000~0x1FFFFFFF��ַ����ε�ַΪflash������Ϣ����ָ����ε�ַ������DMA�����е��²���Ԥ�ƵĽ�� */
#define	DMA_CHxMAR_CHxMEMAD_Msk	(0xffffffffU << DMA_CHxMAR_CHxMEMAD_Pos)

#define	DMA_CH11CR_CH11TSIZE_Pos	16	/* Channel11���䳤�ȣ�1-8192�δ��䣬����Flash->RAM����ʱ��Ч��RAM->Flash����Ϊ�̶�����64�δ��� */
#define	DMA_CH11CR_CH11TSIZE_Msk	(0x1fffU << DMA_CH11CR_CH11TSIZE_Pos)

#define	DMA_CH11CR_CH11PRI_Pos	12	/* Channel11���ȼ�
00��Low
01��Medium
10��High
11��Very High */
#define	DMA_CH11CR_CH11PRI_Msk	(0x3U << DMA_CH11CR_CH11PRI_Pos)
#define	DMA_CH11CR_CH11PRI_LOW	(0x0U << DMA_CH11CR_CH11PRI_Pos)	/* Low */
#define	DMA_CH11CR_CH11PRI_MEDIUM	(0x1U << DMA_CH11CR_CH11PRI_Pos)	/* Medium */
#define	DMA_CH11CR_CH11PRI_HIGH	(0x2U << DMA_CH11CR_CH11PRI_Pos)	/* High */
#define	DMA_CH11CR_CH11PRI_VERY_HIGH	(0x3U << DMA_CH11CR_CH11PRI_Pos)	/* Very High */

#define	DMA_CH11CR_CH11DIR_Pos	10	/* Channel11���䷽��
1��Flash->RAM����
0��RAM->Flash���� */
#define	DMA_CH11CR_CH11DIR_Msk	(0x1U << DMA_CH11CR_CH11DIR_Pos)
#define	DMA_CH11CR_CH11DIR_TO_RAM	(0x1U << DMA_CH11CR_CH11DIR_Pos)	/* Flash->RAM���� */
#define	DMA_CH11CR_CH11DIR_TO_FLASH	(0x0U << DMA_CH11CR_CH11DIR_Pos)	/* RAM->Flash���� */

#define	DMA_CH11CR_CH11RI_Pos	9	/* Channel11 RAM��ַ�������ã�����Flash->RAM��������Ч
1��RAM��ַ����
0��RAM��ַ�ݼ� */
#define	DMA_CH11CR_CH11RI_Msk	(0x1U << DMA_CH11CR_CH11RI_Pos)
#define	DMA_CH11CR_CH11RI_INCREASE	(0x1U << DMA_CH11CR_CH11RI_Pos)	/* RAM��ַ���� */
#define	DMA_CH11CR_CH11RI_DECREASE	(0x0U << DMA_CH11CR_CH11RI_Pos)	/* RAM��ַ�ݼ� */

#define	DMA_CH11CR_CH11FI_Pos	8	/* Channel11 Flash��ַ�������ã�����Flash->RAM��������Ч
1��Flash��ַ����
0��Flash��ַ�ݼ� */
#define	DMA_CH11CR_CH11FI_Msk	(0x1U << DMA_CH11CR_CH11FI_Pos)
#define	DMA_CH11CR_CH11FI_INCREASE	(0x1U << DMA_CH11CR_CH11FI_Pos)	/* Flash��ַ���� */
#define	DMA_CH11CR_CH11FI_DECREASE	(0x0U << DMA_CH11CR_CH11FI_Pos)	/* Flash��ַ�ݼ� */

#define	DMA_CH11CR_CH11FTIE_Pos	2	/* Channel11��������ж�ʹ��
1��ʹ�ܴ�������ж�
0���رմ�������ж� */
#define	DMA_CH11CR_CH11FTIE_Msk	(0x1U << DMA_CH11CR_CH11FTIE_Pos)
	/* ʹ�ܴ�������ж� */
	/* �رմ�������ж� */

#define	DMA_CH11CR_CH11HTIE_Pos	1	/* Channel11��̴�������ж�ʹ��
1��ʹ�ܰ���ж�
0���رհ���ж� */
#define	DMA_CH11CR_CH11HTIE_Msk	(0x1U << DMA_CH11CR_CH11HTIE_Pos)
	/* ʹ�ܰ���ж� */
	/* �رհ���ж� */

#define	DMA_CH11CR_CH11EN_Pos	0	/* Channel11ʹ��
1������ͨ��0
0���ر�ͨ��0 */
#define	DMA_CH11CR_CH11EN_Msk	(0x1U << DMA_CH11CR_CH11EN_Pos)
	/* ����ͨ��0 */
	/* �ر�ͨ��0 */

#define	DMA_CH11FAR_CH11FLSAD_Pos	0	/* Channel11 Flashָ���ַ��DMA��������ǰ�����˼Ĵ���д��FlashĿ���ַ��DMA������˼Ĵ�����DMA�����������Լ�
������Բ�ѯ��ǰDMA�����Ŀ��Flash��ַ
�˼Ĵ�����λ��bit5-0������Flash->RAM��������Ч��RAM->Flash������Ĭ�϶���Flash��half-sector��ʼ��ַ */
#define	DMA_CH11FAR_CH11FLSAD_Msk	(0x7fffU << DMA_CH11FAR_CH11FLSAD_Pos)

#define	DMA_CH11RAR_CH7RAMAD_Pos	0	/* Channel7 RAM��ָ���ַ��DMA��������ǰ�����˼Ĵ���д��RAMĿ���ַ��word��ַ����DMA������˼Ĵ�����DMA�����������Լ�
������Բ�ѯ��ǰDMA�����Ŀ��RAM��ַ */
#define	DMA_CH11RAR_CH7RAMAD_Msk	(0x7fffU << DMA_CH11RAR_CH7RAMAD_Pos)

#define	DMA_ISR_DMA_ADDRERR_Pos	28	/* DMA�����ַ�����־�����洢��ָ�볬��RAM��Flash�Ϸ���ַ��Χʱ��λ */
#define	DMA_ISR_DMA_ADDRERR_Msk	(0x1U << DMA_ISR_DMA_ADDRERR_Pos)

#define	DMA_ISR_DMACHFT_Pos	16	/* DMAͨ��x������ɱ�־��Ӳ����λ�����д1����
1����Ӧͨ���������
0����Ӧͨ������δ��� */
#define	DMA_ISR_DMACHFT_Msk	(0xfffU << DMA_ISR_DMACHFT_Pos)

#define	DMA_ISR_DMACHHT_Pos	0	/* DMAͨ��x�����̱�־��Ӳ����λ�����д1���� */
#define	DMA_ISR_DMACHHT_Msk	(0xfffU << DMA_ISR_DMACHHT_Pos)

#define	DMA_CHxCSR_CHxTSIZE_SDW_Pos	16	/* Channelx���䳤��shadow�Ĵ�����ѭ��ģʽ�����ʹ����CIRC_UPD�Ĵ��������ڱ��ִ�����ɺ�shadow�Ĵ���ֵ���Ƶ�CHxTSIZE�С� */
#define	DMA_CHxCSR_CHxTSIZE_SDW_Msk	(0x1fffU << DMA_CHxCSR_CHxTSIZE_SDW_Pos)

#define	DMA_CHxCSR_CHxINC_SDW_Pos	11	/* RAM��ַ��������shadow�Ĵ�����ѭ��ģʽ�����ʹ����CIRC_UPD�Ĵ��������ڱ��ִ�����ɺ�shadow�Ĵ���ֵ���Ƶ�CHxTSIZE�С� */
#define	DMA_CHxCSR_CHxINC_SDW_Msk	(0x1U << DMA_CHxCSR_CHxINC_SDW_Pos)

#define	DMA_CHxMASR_CHxMAD_SDW_Pos	0	/* Channelx�洢��ָ���ַӰ�ӼĴ�����
ѭ��ģʽ�����ʹ����CIRC_UPD�Ĵ��������ڱ��ִ�����ɺ�shadow�Ĵ���ֵ���Ƶ�CHxMEMAD�С� */
#define	DMA_CHxMASR_CHxMAD_SDW_Msk	(0xffffffffU << DMA_CHxMASR_CHxMAD_SDW_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void DMA_Deinit(void);

/* DMA�����ַ�ж�ʹ��
1����������ַ�ж�
0����ֹ�����ַ�ж� ��غ��� */
extern void DMA_GCR_DMA_ADDRERR_EN_Setable(FunState NewState);
extern FunState DMA_GCR_DMA_ADDRERR_EN_Getable(void);

/* DMAȫ��ʹ��
1��DMAʹ��
0��DMA�ر� ��غ��� */
extern void DMA_GCR_DMAEN_Setable(FunState NewState);
extern FunState DMA_GCR_DMAEN_Getable(void);

/* Channelx���䳤�ȣ�1-8192�δ��� ��غ��� */
extern void DMA_CHxCR_CHxTSIZE_Set(DMA_CH_Type CHx, uint32_t SetValue);
extern uint32_t DMA_CHxCR_CHxTSIZE_Get(DMA_CH_Type CHx);

/* Channelx���ȼ�
00��Low
01��Medium
10��High
11��Very High ��غ��� */
extern void DMA_CHxCR_CHxPRI_Set(DMA_CH_Type CHx, uint32_t SetValue);
extern uint32_t DMA_CHxCR_CHxPRI_Get(DMA_CH_Type CHx);

/* RAM��ַ��������
1��RAM��ַ����
0��RAM��ַ�ݼ� ��غ��� */
extern void DMA_CHxCR_CHxINC_Set(DMA_CH_Type CHx, uint32_t SetValue);
extern uint32_t DMA_CHxCR_CHxINC_Get(DMA_CH_Type CHx);

/* Channelx��������ӳ��
ÿ��ͨ�����Խ���8�������������������ӳ��μ�23.6.1DMA����ӳ�� ��غ��� */
extern void DMA_CHxCR_CHxSSEL_Set(DMA_CH_Type CHx, uint32_t SetValue);
extern uint32_t DMA_CHxCR_CHxSSEL_Get(DMA_CH_Type CHx);

/* ѭ������ģʽ���Զ����´�����������ִ�����ɺ�shadow�Ĵ������ݸ��Ƶ����ƼĴ���
0����ֹ�Զ�����
1��ʹ���Զ�����
ע�⣺��ͨ��0~6֧�ִ˹��ܣ�ͨ��7~10�޴˼Ĵ��� ��غ��� */
extern void DMA_CHxCR_CIRC_UPD_Setable(DMA_CH_Type CHx, FunState NewState);
extern FunState DMA_CHxCR_CIRC_UPD_Getable(DMA_CH_Type CHx);

/* ͨ�����䷽��
0���������ȡ����д��RAM
1����RAM��ȡ����д������ ��غ��� */
extern void DMA_CHxCR_DIR_Set(DMA_CH_Type CHx, uint32_t SetValue);
extern uint32_t DMA_CHxCR_DIR_Get(DMA_CH_Type CHx);

/* �����������
00���ֽڣ�8bit
01�����֣�16bit
10���֣�32bit
11��RFU ��غ��� */
extern void DMA_CHxCR_BDW_Set(DMA_CH_Type CHx, uint32_t SetValue);
extern uint32_t DMA_CHxCR_BDW_Get(DMA_CH_Type CHx);

/* ѭ������ģʽ
0���ر�ѭ��ģʽ
1��ʹ��ѭ��ģʽ ��غ��� */
extern void DMA_CHxCR_CIRC_Setable(DMA_CH_Type CHx, FunState NewState);
extern FunState DMA_CHxCR_CIRC_Getable(DMA_CH_Type CHx);

/* Channelx��������ж�ʹ��
1��ʹ�ܴ�������ж�
0���رմ�������ж� ��غ��� */
extern void DMA_CHxCR_CHxFTIE_Setable(DMA_CH_Type CHx, FunState NewState);
extern FunState DMA_CHxCR_CHxFTIE_Getable(DMA_CH_Type CHx);

/* Channelx��̴�������ж�ʹ��
1��ʹ�ܰ���ж�
0���رհ���ж� ��غ��� */
extern void DMA_CHxCR_CHxHTIE_Setable(DMA_CH_Type CHx, FunState NewState);
extern FunState DMA_CHxCR_CHxHTIE_Getable(DMA_CH_Type CHx);

/* Channelxʹ��
1������ͨ��0
0���ر�ͨ��0 ��غ��� */
extern void DMA_CHxCR_ChxEN_Setable(DMA_CH_Type CHx, FunState NewState);
extern FunState DMA_CHxCR_ChxEN_Getable(DMA_CH_Type CHx);

/* Channelx�洢��ָ���ַ��DMA��������ǰ�����˼Ĵ���д��洢��Ŀ���ַ��
��ָ��ָ��յ�ַʱ��DMA���ʽ�����hardfault
��ָ��ָ��Flashʱ����ֹ��Flashд�����ݡ�
������Բ�ѯ��ǰDMA�����Ŀ��洢����ַ��

ע�⣺��ָ���ָֹ��0x00080000~0x1FFFFFFF��ַ����ε�ַΪflash������Ϣ����ָ����ε�ַ������DMA�����е��²���Ԥ�ƵĽ�� ��غ��� */
extern void DMA_CHxMAR_Write(DMA_CH_Type CHx, uint32_t SetValue);
extern uint32_t DMA_CHxMAR_Read(DMA_CH_Type CHx);

/* Channel11���䳤�ȣ�1-8192�δ��䣬����Flash->RAM����ʱ��Ч��RAM->Flash����Ϊ�̶�����64�δ��� ��غ��� */
extern void DMA_CH11CR_CH11TSIZE_Set(uint32_t SetValue);
extern uint32_t DMA_CH11CR_CH11TSIZE_Get(void);

/* Channel11���ȼ�
00��Low
01��Medium
10��High
11��Very High ��غ��� */
extern void DMA_CH11CR_CH11PRI_Set(uint32_t SetValue);
extern uint32_t DMA_CH11CR_CH11PRI_Get(void);

/* Channel11���䷽��
1��Flash->RAM����
0��RAM->Flash���� ��غ��� */
extern void DMA_CH11CR_CH11DIR_Set(uint32_t SetValue);
extern uint32_t DMA_CH11CR_CH11DIR_Get(void);

/* Channel11 RAM��ַ�������ã�����Flash->RAM��������Ч
1��RAM��ַ����
0��RAM��ַ�ݼ� ��غ��� */
extern void DMA_CH11CR_CH11RI_Set(uint32_t SetValue);
extern uint32_t DMA_CH11CR_CH11RI_Get(void);

/* Channel11 Flash��ַ�������ã�����Flash->RAM��������Ч
1��Flash��ַ����
0��Flash��ַ�ݼ� ��غ��� */
extern void DMA_CH11CR_CH11FI_Set(uint32_t SetValue);
extern uint32_t DMA_CH11CR_CH11FI_Get(void);

/* Channel11��������ж�ʹ��
1��ʹ�ܴ�������ж�
0���رմ�������ж� ��غ��� */
extern void DMA_CH11CR_CH11FTIE_Setable(FunState NewState);
extern FunState DMA_CH11CR_CH11FTIE_Getable(void);

/* Channel11��̴�������ж�ʹ��
1��ʹ�ܰ���ж�
0���رհ���ж� ��غ��� */
extern void DMA_CH11CR_CH11HTIE_Setable(FunState NewState);
extern FunState DMA_CH11CR_CH11HTIE_Getable(void);

/* Channel11ʹ��
1������ͨ��0
0���ر�ͨ��0 ��غ��� */
extern void DMA_CH11CR_CH11EN_Setable(FunState NewState);
extern FunState DMA_CH11CR_CH11EN_Getable(void);

/* Channel11 Flashָ���ַ��DMA��������ǰ�����˼Ĵ���д��FlashĿ���ַ��DMA������˼Ĵ�����DMA�����������Լ�
������Բ�ѯ��ǰDMA�����Ŀ��Flash��ַ
�˼Ĵ�����λ��bit5-0������Flash->RAM��������Ч��RAM->Flash������Ĭ�϶���Flash��half-sector��ʼ��ַ ��غ��� */
extern void DMA_CH11FAR_Write(uint32_t SetValue);
extern uint32_t DMA_CH11FAR_Read(void);

/* Channel7 RAM��ָ���ַ��DMA��������ǰ�����˼Ĵ���д��RAMĿ���ַ��word��ַ����DMA������˼Ĵ�����DMA�����������Լ�
������Բ�ѯ��ǰDMA�����Ŀ��RAM��ַ ��غ��� */
extern void DMA_CH11RAR_Write(uint32_t SetValue);
extern uint32_t DMA_CH11RAR_Read(void);

/* DMA�����ַ�����־�����洢��ָ�볬��RAM��Flash�Ϸ���ַ��Χʱ��λ ��غ��� */
extern void DMA_ISR_DMA_ADDRERR_Clr(void);
extern FlagStatus DMA_ISR_DMA_ADDRERR_Chk(void);

/* DMAͨ��x������ɱ�־��Ӳ����λ�����д1����
1����Ӧͨ���������
0����Ӧͨ������δ��� ��غ��� */
extern void DMA_ISR_DMACHFT_Clr(DMA_CH_Type CHx);
extern FlagStatus DMA_ISR_DMACHFT_Chk(DMA_CH_Type CHx);

/* DMAͨ��x�����̱�־��Ӳ����λ�����д1���� ��غ��� */
extern void DMA_ISR_DMACHHT_Clr(DMA_CH_Type CHx);
extern FlagStatus DMA_ISR_DMACHHT_Chk(DMA_CH_Type CHx);

/* Channelx���䳤��shadow�Ĵ�����ѭ��ģʽ�����ʹ����CIRC_UPD�Ĵ��������ڱ��ִ�����ɺ�shadow�Ĵ���ֵ���Ƶ�CHxTSIZE�С� ��غ��� */
extern void DMA_CHxCSR_CHxTSIZE_SDW_Set(DMA_CH_Type CHx, uint32_t SetValue);
extern uint32_t DMA_CHxCSR_CHxTSIZE_SDW_Get(DMA_CH_Type CHx);

/* RAM��ַ��������shadow�Ĵ�����ѭ��ģʽ�����ʹ����CIRC_UPD�Ĵ��������ڱ��ִ�����ɺ�shadow�Ĵ���ֵ���Ƶ�CHxTSIZE�С� ��غ��� */
extern void DMA_CHxCSR_CHxINC_SDW_Set(DMA_CH_Type CHx, uint32_t SetValue);
extern uint32_t DMA_CHxCSR_CHxINC_SDW_Get(DMA_CH_Type CHx);

/* Channelx�洢��ָ���ַӰ�ӼĴ�����
ѭ��ģʽ�����ʹ����CIRC_UPD�Ĵ��������ڱ��ִ�����ɺ�shadow�Ĵ���ֵ���Ƶ�CHxMEMAD�С� ��غ��� */
extern void DMA_CHxMASR_Write(DMA_CH_Type CHx, uint32_t SetValue);
extern uint32_t DMA_CHxMASR_Read(DMA_CH_Type CHx);
//Announce_End

void DMA_DeInit(void);
void DMA_Init(DMA_InitTypeDef *para);
   
//Announce_End
#ifdef __cplusplus
}
#endif

#endif /* __FM33A0XXEV_DMA_H */
