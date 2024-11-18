/**
  ******************************************************************************
  * @file    fm33a0xxev_pae.h
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file contains all the functions prototypes for the PAE firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33A0XXEV_PAE_H
#define __FM33A0XXEV_PAE_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33A0XXEV.h" 
   
	 
//ECC����ģʽ˵��
#define ECC_STD_DBL				0x00	 //�ſ˱����걶��
#define ECC_STD_ADD				0x01	 //���������
#define ECC_ALG1_DBLADD			0x02	 //����1��ʽ�����ǵ�ӱ���
#define ECC_ALG2_ECDBL			0x03	 //����2��ʽ1��ECDBL
#define ECC_ALG2_ECADDDBL		0x04	 //����2��ʽ2��ECADDDBL
#define ECC_ALG2_YRECOVER		0x05	 //����2��ʽ3���ָ���ӰY����
	 

//Macro_START
//2020-03-12-14-15-07
//FM33A0XX_Driver_Gen_V1.4

#define	PAE_CSR_DATA_TYPE_Pos	8	/* ��������˳�򽻻�����
00��������
01��half-word����
10��byte����
11��bit����
�˼Ĵ������ڶ�����32bit���ݵ�λ����е�������������Ϊ0x1234_5678��half-word������Ϊ0x5678_1234��byte������Ϊ0x7856_3412��bit������Ϊ0x1E6A_2C48 */
#define	PAE_CSR_DATA_TYPE_Msk	(0x3U << PAE_CSR_DATA_TYPE_Pos)
#define	PAE_CSR_DATA_TYPE_NONE	(0x0U << PAE_CSR_DATA_TYPE_Pos)	/* ������ */
#define	PAE_CSR_DATA_TYPE_HALFWORD	(0x1U << PAE_CSR_DATA_TYPE_Pos)	/* half-word���� */
#define	PAE_CSR_DATA_TYPE_BYTE	(0x2U << PAE_CSR_DATA_TYPE_Pos)	/* byte���� */
#define	PAE_CSR_DATA_TYPE_BIT	(0x3U << PAE_CSR_DATA_TYPE_Pos)	/* bit���� */

#define	PAE_CSR_START_Pos	7	/* ��������λ�����д1�������㣬���������Ӳ���Զ����� */
#define	PAE_CSR_START_Msk	(0x1U << PAE_CSR_START_Pos)

#define	PAE_CSR_RUN_MODE_Pos	4	/* ģ�鹤��ģʽ��
00��ģʽ0������ģ���㣬������4Block/16Block
01��ģʽ1�����ε����㣬�̶�16Block
10��ģʽ2��32bit��Կ����RSA���㣬�̶�4Block
11��ģʽ3��32bit��Կ����ECC���㣬�̶�16Block */
#define	PAE_CSR_RUN_MODE_Msk	(0x3U << PAE_CSR_RUN_MODE_Pos)
#define	PAE_CSR_RUN_MODE_MOD	(0x0U << PAE_CSR_RUN_MODE_Pos)
#define	PAE_CSR_RUN_MODE_DOT	(0x1U << PAE_CSR_RUN_MODE_Pos)	/* ģʽ0������ģ���㣬������4Block/16Block */
#define	PAE_CSR_RUN_MODE_RSA	(0x2U << PAE_CSR_RUN_MODE_Pos)	/* ģʽ1�����ε����㣬�̶�16Block */
#define	PAE_CSR_RUN_MODE_ECC	(0x3U << PAE_CSR_RUN_MODE_Pos)	/* ģʽ2��32bit��Կ����RSA���㣬�̶�4Block */

#define	PAE_CSR_SOFT_RST_Pos	3	/* PAE�����λ�����д1��λPAE�ڲ���Ҫ�Ĵ�����ģ���Ĵ���PAE_MLR��ģ�μĴ���PAE_MPR����Ӱ�죩����λ������Ӳ���Զ�����
ע�⣺���дSOFT_RST֮�����������һ��NOPָ�����д��PAE�����Ĵ�������SOFT_RST����������дPAE�Ĵ�������д��ʧ�ܡ� */
#define	PAE_CSR_SOFT_RST_Msk	(0x1U << PAE_CSR_SOFT_RST_Pos)
	/* ���дSOFT_RST֮�����������һ��NOPָ�����д��PAE�����Ĵ�������SOFT_RST����������дPAE�Ĵ�������д��ʧ�ܡ� */

#define	PAE_CSR_PAEIE_Pos	2	/* PAE�ж�ʹ��
1��ʹ���ж����
0����ֹ�ж���� */
#define	PAE_CSR_PAEIE_Msk	(0x1U << PAE_CSR_PAEIE_Pos)
#define	PAE_CSR_PAEIE_ENABLE	(0x1U << PAE_CSR_PAEIE_Pos)	/* ʹ���ж���� */
#define	PAE_CSR_PAEIE_DISABLE	(0x0U << PAE_CSR_PAEIE_Pos)	/* ��ֹ�ж���� */

#define	PAE_CSR_PAEIF_Pos	1	/* PAE�жϱ�־�Ĵ��� */
#define	PAE_CSR_PAEIF_Msk	(0x1U << PAE_CSR_PAEIF_Pos)

#define	PAE_CSR_BUSY_Pos	0	/* PAE������־
1��PAE����������
0��PAE���� */
#define	PAE_CSR_BUSY_Msk	(0x1U << PAE_CSR_BUSY_Pos)

#define	PAE_MLR_PAE_MLR_Pos	0	/* ��RAM����Ϊ4 Blockʱ��ģ�����Ϊ2048bit��
ģ��=��MLR[5:0]+1��*32λ��
��RAM����Ϊ16 Blockʱ��ģ�����Ϊ512bit��MLRֻ�е�4bit��Ч��
ģ��=��MLR[3:0]+1��*32λ�� */
#define	PAE_MLR_PAE_MLR_Msk	(0x3fU << PAE_MLR_PAE_MLR_Pos)

#define	PAE_MPR_PAE_MPR_Pos	0	/* 32bitģ�μĴ�����ֻ��д�����ɶ� */
#define	PAE_MPR_PAE_MPR_Msk	(0xffffffffU << PAE_MPR_PAE_MPR_Pos)

#define	PAE_M0CFG_BLKCFG_Pos	15	/* RAM Block����λ
1���㷨RAM����Ϊ16 Block
0���㷨RAM����λ4 Block */
#define	PAE_M0CFG_BLKCFG_Msk	(0x1U << PAE_M0CFG_BLKCFG_Pos)
#define	PAE_M0CFG_BLKCFG_16BLOCK	(0x1U << PAE_M0CFG_BLKCFG_Pos)	/* �㷨RAM����Ϊ16 Block */
#define	PAE_M0CFG_BLKCFG_4BLOCK	(0x0U << PAE_M0CFG_BLKCFG_Pos)	/* �㷨RAM����λ4 Block */

#define	PAE_M0CFG_INS_M0_Pos	12	/* ����ģ����ָ�
00���ɸ�����ģ��
01���ɸ�����ģ��
10��RFU
11���ɸ�����ģ�� */
#define	PAE_M0CFG_INS_M0_Msk	(0x3U << PAE_M0CFG_INS_M0_Pos)
#define	PAE_M0CFG_INS_M0_MUL	(0x0U << PAE_M0CFG_INS_M0_Pos)
#define	PAE_M0CFG_INS_M0_ADD	(0x1U << PAE_M0CFG_INS_M0_Pos)	/* �ɸ�����ģ�� */
#define	PAE_M0CFG_INS_M0_SUB	(0x3U << PAE_M0CFG_INS_M0_Pos)	/* �ɸ�����ģ�� */

#define	PAE_M0CFG_RES_BLK_Pos	8	/* ��������������Block
��BLK_CFG==1��4bit��Ч����ʾBlock0~Block15
��BLK_CFG==0����2bit��Ч����ʾBlock0~Block3 */
#define	PAE_M0CFG_RES_BLK_Msk	(0xfU << PAE_M0CFG_RES_BLK_Pos)
#define	PAE_M0CFG_RES_BLK_BLOCK0	(0x0U << PAE_M0CFG_RES_BLK_Pos)
#define	PAE_M0CFG_RES_BLK_BLOCK1	(0x1U << PAE_M0CFG_RES_BLK_Pos)
#define	PAE_M0CFG_RES_BLK_BLOCK2	(0x2U << PAE_M0CFG_RES_BLK_Pos)
#define	PAE_M0CFG_RES_BLK_BLOCK3	(0x3U << PAE_M0CFG_RES_BLK_Pos)
#define	PAE_M0CFG_RES_BLK_BLOCK4	(0x4U << PAE_M0CFG_RES_BLK_Pos)
#define	PAE_M0CFG_RES_BLK_BLOCK5	(0x5U << PAE_M0CFG_RES_BLK_Pos)
#define	PAE_M0CFG_RES_BLK_BLOCK6	(0x6U << PAE_M0CFG_RES_BLK_Pos)
#define	PAE_M0CFG_RES_BLK_BLOCK7	(0x7U << PAE_M0CFG_RES_BLK_Pos)
#define	PAE_M0CFG_RES_BLK_BLOCK8	(0x8U << PAE_M0CFG_RES_BLK_Pos)
#define	PAE_M0CFG_RES_BLK_BLOCK9	(0x9U << PAE_M0CFG_RES_BLK_Pos)
#define	PAE_M0CFG_RES_BLK_BLOCK10	(0xAU << PAE_M0CFG_RES_BLK_Pos)
#define	PAE_M0CFG_RES_BLK_BLOCK11	(0xBU << PAE_M0CFG_RES_BLK_Pos)
#define	PAE_M0CFG_RES_BLK_BLOCK12	(0xCU << PAE_M0CFG_RES_BLK_Pos)
#define	PAE_M0CFG_RES_BLK_BLOCK13	(0xDU << PAE_M0CFG_RES_BLK_Pos)
#define	PAE_M0CFG_RES_BLK_BLOCK14	(0xEU << PAE_M0CFG_RES_BLK_Pos)
#define	PAE_M0CFG_RES_BLK_BLOCK15	(0xFU << PAE_M0CFG_RES_BLK_Pos)






#define	PAE_M0CFG_OP1_BLK_Pos	4	/* ������1��ַ��
��BLK_CFG==1��4bit��Ч����ʾBlock0~Block15
��BLK_CFG==0����2bit��Ч����ʾBlock0~Block3 */
#define	PAE_M0CFG_OP1_BLK_Msk	(0xfU << PAE_M0CFG_OP1_BLK_Pos)
#define	PAE_M0CFG_OP1_BLK_BLOCK0	(0x0U << PAE_M0CFG_OP1_BLK_Pos)
#define	PAE_M0CFG_OP1_BLK_BLOCK1	(0x1U << PAE_M0CFG_OP1_BLK_Pos)
#define	PAE_M0CFG_OP1_BLK_BLOCK2	(0x2U << PAE_M0CFG_OP1_BLK_Pos)
#define	PAE_M0CFG_OP1_BLK_BLOCK3	(0x3U << PAE_M0CFG_OP1_BLK_Pos)
#define	PAE_M0CFG_OP1_BLK_BLOCK4	(0x4U << PAE_M0CFG_OP1_BLK_Pos)
#define	PAE_M0CFG_OP1_BLK_BLOCK5	(0x5U << PAE_M0CFG_OP1_BLK_Pos)
#define	PAE_M0CFG_OP1_BLK_BLOCK6	(0x6U << PAE_M0CFG_OP1_BLK_Pos)
#define	PAE_M0CFG_OP1_BLK_BLOCK7	(0x7U << PAE_M0CFG_OP1_BLK_Pos)
#define	PAE_M0CFG_OP1_BLK_BLOCK8	(0x8U << PAE_M0CFG_OP1_BLK_Pos)
#define	PAE_M0CFG_OP1_BLK_BLOCK9	(0x9U << PAE_M0CFG_OP1_BLK_Pos)
#define	PAE_M0CFG_OP1_BLK_BLOCK10	(0xAU << PAE_M0CFG_OP1_BLK_Pos)
#define	PAE_M0CFG_OP1_BLK_BLOCK11	(0xBU << PAE_M0CFG_OP1_BLK_Pos)
#define	PAE_M0CFG_OP1_BLK_BLOCK12	(0xCU << PAE_M0CFG_OP1_BLK_Pos)
#define	PAE_M0CFG_OP1_BLK_BLOCK13	(0xDU << PAE_M0CFG_OP1_BLK_Pos)
#define	PAE_M0CFG_OP1_BLK_BLOCK14	(0xEU << PAE_M0CFG_OP1_BLK_Pos)
#define	PAE_M0CFG_OP1_BLK_BLOCK15	(0xFU << PAE_M0CFG_OP1_BLK_Pos)




#define	PAE_M0CFG_OP2_BLK_Pos	0	/* ������2��ַ��
��BLK_CFG==1��4bit��Ч����ʾBlock0~Block15
��BLK_CFG==0����2bit��Ч����ʾBlock0~Block3 */
#define	PAE_M0CFG_OP2_BLK_Msk	(0xfU << PAE_M0CFG_OP2_BLK_Pos)
#define	PAE_M0CFG_OP2_BLK_BLOCK0	(0x0U << PAE_M0CFG_OP2_BLK_Pos)
#define	PAE_M0CFG_OP2_BLK_BLOCK1	(0x1U << PAE_M0CFG_OP2_BLK_Pos)
#define	PAE_M0CFG_OP2_BLK_BLOCK2	(0x2U << PAE_M0CFG_OP2_BLK_Pos)
#define	PAE_M0CFG_OP2_BLK_BLOCK3	(0x3U << PAE_M0CFG_OP2_BLK_Pos)
#define	PAE_M0CFG_OP2_BLK_BLOCK4	(0x4U << PAE_M0CFG_OP2_BLK_Pos)
#define	PAE_M0CFG_OP2_BLK_BLOCK5	(0x5U << PAE_M0CFG_OP2_BLK_Pos)
#define	PAE_M0CFG_OP2_BLK_BLOCK6	(0x6U << PAE_M0CFG_OP2_BLK_Pos)
#define	PAE_M0CFG_OP2_BLK_BLOCK7	(0x7U << PAE_M0CFG_OP2_BLK_Pos)
#define	PAE_M0CFG_OP2_BLK_BLOCK8	(0x8U << PAE_M0CFG_OP2_BLK_Pos)
#define	PAE_M0CFG_OP2_BLK_BLOCK9	(0x9U << PAE_M0CFG_OP2_BLK_Pos)
#define	PAE_M0CFG_OP2_BLK_BLOCK10	(0xAU << PAE_M0CFG_OP2_BLK_Pos)
#define	PAE_M0CFG_OP2_BLK_BLOCK11	(0xBU << PAE_M0CFG_OP2_BLK_Pos)
#define	PAE_M0CFG_OP2_BLK_BLOCK12	(0xCU << PAE_M0CFG_OP2_BLK_Pos)
#define	PAE_M0CFG_OP2_BLK_BLOCK13	(0xDU << PAE_M0CFG_OP2_BLK_Pos)
#define	PAE_M0CFG_OP2_BLK_BLOCK14	(0xEU << PAE_M0CFG_OP2_BLK_Pos)
#define	PAE_M0CFG_OP2_BLK_BLOCK15	(0xFU << PAE_M0CFG_OP2_BLK_Pos)


#define	PAE_M1CFG_INS_M1_Pos	4	/* ���ε�����ָ�
000��Jacobin���걶������
001���������������
010��RFU
011���ɸ�������˱������㣨ECDBL��
100���ɸ�������˱��������㣨ECADDDBL��
101���ɸ��������Y����ָ����㣨ECYRecover��
110��RFU
111��RFU */
#define	PAE_M1CFG_INS_M1_Msk	(0x7U << PAE_M1CFG_INS_M1_Pos)
#define	PAE_M1CFG_INS_M1_JACOBIN	(0x0U << PAE_M1CFG_INS_M1_Pos)	/* Jacobin���걶������ */
#define	PAE_M1CFG_INS_M1_MIXADD	(0x1U << PAE_M1CFG_INS_M1_Pos)	/* ������������� */
#define	PAE_M1CFG_INS_M1_ECDBL	(0x3U << PAE_M1CFG_INS_M1_Pos)	/* �ɸ�������˱������㣨ECDBL�� */
#define	PAE_M1CFG_INS_M1_ECADDDBL	(0x4U << PAE_M1CFG_INS_M1_Pos)	/* �ɸ�������˱��������㣨ECADDDBL�� */
#define	PAE_M1CFG_INS_M1_ECYRECOVER	(0x5U << PAE_M1CFG_INS_M1_Pos)	/* �ɸ��������Y����ָ����㣨ECYRecover�� */

#define	PAE_M1CFG_AEN3_M1_Pos	1	/* ����Aָʾ�ź�
1��A����-3
0��A������-3 */
#define	PAE_M1CFG_AEN3_M1_Msk	(0x1U << PAE_M1CFG_AEN3_M1_Pos)
#define	PAE_M1CFG_AEN3_M1_NE3	(0x1U << PAE_M1CFG_AEN3_M1_Pos)	/* A����-3 */
#define	PAE_M1CFG_AEN3_M1_EQ3	(0x0U << PAE_M1CFG_AEN3_M1_Pos)	/* A������-3 */

#define	PAE_M1CFG_BIT_VALUE_M1_Pos	0	/* ��ǰ������Կλָʾ��־
1����ǰλΪ1
0����ǰλΪ0 */
#define	PAE_M1CFG_BIT_VALUE_M1_Msk	(0x1U << PAE_M1CFG_BIT_VALUE_M1_Pos)
#define	PAE_M1CFG_BIT_VALUE_M1_VALUE1	(0x1U << PAE_M1CFG_BIT_VALUE_M1_Pos)	/* ��ǰλΪ1 */
#define	PAE_M1CFG_BIT_VALUE_M1_VALUE0	(0x0U << PAE_M1CFG_BIT_VALUE_M1_Pos)	/* ��ǰλΪ0 */

#define	PAE_M2CFG_ALWAYS_MULT_Pos	4	/* ��ģ�˿���λ
1����ǰ��ԿλΪ0ʱͬ������ģ�˲���
0����ǰ��ԿλΪ0ʱ������ģ�˲��� */
#define	PAE_M2CFG_ALWAYS_MULT_Msk	(0x1U << PAE_M2CFG_ALWAYS_MULT_Pos)
#define	PAE_M2CFG_ALWAYS_MULT_ALWAYS	(0x1U << PAE_M2CFG_ALWAYS_MULT_Pos)	/* ��ǰ��ԿλΪ0ʱͬ������ģ�˲��� */
#define	PAE_M2CFG_ALWAYS_MULT_NONE	(0x0U << PAE_M2CFG_ALWAYS_MULT_Pos)	/* ��ǰ��ԿλΪ0ʱ������ģ�˲��� */

#define	PAE_M2CFG_FBO_M2_Pos	0	/* ��Կλָʾ�źţ�Ӳ���Զ���λ���������
1�����ҵ�Ϊ1��bit
0��δ�ҵ�Ϊ1��bit */
#define	PAE_M2CFG_FBO_M2_Msk	(0x1U << PAE_M2CFG_FBO_M2_Pos)
#define	PAE_M2CFG_FBO_M2_FB1	(0x1U << PAE_M2CFG_FBO_M2_Pos)	/* ���ҵ�Ϊ1��bit */
#define	PAE_M2CFG_FBO_M2_NFB1	(0x0U << PAE_M2CFG_FBO_M2_Pos)	/* δ�ҵ�Ϊ1��bit */

#define	PAE_M3CFG_AEN3_M3_Pos	4	/* ����Aָʾ�ź�
1��A����-3
0��A������-3 */
#define	PAE_M3CFG_AEN3_M3_Msk	(0x1U << PAE_M3CFG_AEN3_M3_Pos)
#define	PAE_M3CFG_AEN3_M3_EQ3	(0x1U << PAE_M3CFG_AEN3_M3_Pos)	/* A����-3 */
#define	PAE_M3CFG_AEN3_M3_NE3	(0x0U << PAE_M3CFG_AEN3_M3_Pos)	/* A������-3 */

#define	PAE_M3CFG_FBO_M3_Pos	0	/* ��Կλָʾ�źţ�Ӳ���Զ���λ���������
1�����ҵ�Ϊ1��bit
0��δ�ҵ�Ϊ1��bit */
#define	PAE_M3CFG_FBO_M3_Msk	(0x1U << PAE_M3CFG_FBO_M3_Pos)
#define	PAE_M3CFG_FBO_M3_FB1	(0x1U << PAE_M3CFG_FBO_M3_Pos)	/* ���ҵ�Ϊ1��bit */
#define	PAE_M3CFG_FBO_M3_NFB1	(0x0U << PAE_M3CFG_FBO_M3_Pos)	/* δ�ҵ�Ϊ1��bit */

#define	PAE_WORD_PAE_WORD_Pos	0	/* 32bit���ݼĴ�����ֻ��д�����ɶ�����������RSA���������ECC����ģʽ����Ч�� */
#define	PAE_WORD_PAE_WORD_Msk	(0xffffffffU << PAE_WORD_PAE_WORD_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void PAE_Deinit(void);

/* ��������˳�򽻻�����
00��������
01��half-word����
10��byte����
11��bit����
�˼Ĵ������ڶ�����32bit���ݵ�λ����е�������������Ϊ0x1234_5678��half-word������Ϊ0x5678_1234��byte������Ϊ0x7856_3412��bit������Ϊ0x1E6A_2C48 ��غ��� */
extern void PAE_CSR_DATA_TYPE_Set(uint32_t SetValue);
extern uint32_t PAE_CSR_DATA_TYPE_Get(void);

/* ��������λ�����д1�������㣬���������Ӳ���Զ����� ��غ��� */
extern void PAE_CSR_START_Setable(FunState NewState);

/* ģ�鹤��ģʽ��
00��ģʽ0������ģ���㣬������4Block/16Block
01��ģʽ1�����ε����㣬�̶�16Block
10��ģʽ2��32bit��Կ����RSA���㣬�̶�4Block
11��ģʽ3��32bit��Կ����ECC���㣬�̶�16Block ��غ��� */
extern void PAE_CSR_RUN_MODE_Set(uint32_t SetValue);
extern uint32_t PAE_CSR_RUN_MODE_Get(void);

/* PAE�����λ�����д1��λPAE�ڲ���Ҫ�Ĵ�����ģ���Ĵ���PAE_MLR��ģ�μĴ���PAE_MPR����Ӱ�죩����λ������Ӳ���Զ�����
ע�⣺���дSOFT_RST֮�����������һ��NOPָ�����д��PAE�����Ĵ�������SOFT_RST����������дPAE�Ĵ�������д��ʧ�ܡ� ��غ��� */
extern void PAE_CSR_SOFT_RST_Setable(FunState NewState);

/* PAE�ж�ʹ��
1��ʹ���ж����
0����ֹ�ж���� ��غ��� */
extern void PAE_CSR_PAEIE_Setable(FunState NewState);
extern FunState PAE_CSR_PAEIE_Getable(void);

/* PAE�жϱ�־�Ĵ��� ��غ��� */
extern void PAE_CSR_PAEIF_Clr(void);
extern FlagStatus PAE_CSR_PAEIF_Chk(void);

/* PAE������־
1��PAE����������
0��PAE���� ��غ��� */
extern FlagStatus PAE_CSR_BUSY_Chk(void);

/* ��RAM����Ϊ4 Blockʱ��ģ�����Ϊ2048bit��
ģ��=��MLR[5:0]+1��*32λ��
��RAM����Ϊ16 Blockʱ��ģ�����Ϊ512bit��MLRֻ�е�4bit��Ч��
ģ��=��MLR[3:0]+1��*32λ�� ��غ��� */
extern void PAE_MLR_Write(uint32_t SetValue);
extern uint32_t PAE_MLR_Read(void);

/* 32bitģ�μĴ�����ֻ��д�����ɶ� ��غ��� */
extern void PAE_MPR_Write(uint32_t SetValue);

/* RAM Block����λ
1���㷨RAM����Ϊ16 Block
0���㷨RAM����λ4 Block ��غ��� */
extern void PAE_M0CFG_BLKCFG_Set(uint32_t SetValue);
extern uint32_t PAE_M0CFG_BLKCFG_Get(void);

/* ����ģ����ָ�
00���ɸ�����ģ��
01���ɸ�����ģ��
10��RFU
11���ɸ�����ģ�� ��غ��� */
extern void PAE_M0CFG_INS_M0_Set(uint32_t SetValue);
extern uint32_t PAE_M0CFG_INS_M0_Get(void);

/* ��������������Block
��BLK_CFG==1��4bit��Ч����ʾBlock0~Block15
��BLK_CFG==0����2bit��Ч����ʾBlock0~Block3 ��غ��� */
extern void PAE_M0CFG_RES_BLK_Set(uint32_t SetValue);
extern uint32_t PAE_M0CFG_RES_BLK_Get(void);

/* ������1��ַ��
��BLK_CFG==1��4bit��Ч����ʾBlock0~Block15
��BLK_CFG==0����2bit��Ч����ʾBlock0~Block3 ��غ��� */
extern void PAE_M0CFG_OP1_BLK_Set(uint32_t SetValue);
extern uint32_t PAE_M0CFG_OP1_BLK_Get(void);

/* ������2��ַ��
��BLK_CFG==1��4bit��Ч����ʾBlock0~Block15
��BLK_CFG==0����2bit��Ч����ʾBlock0~Block3 ��غ��� */
extern void PAE_M0CFG_OP2_BLK_Set(uint32_t SetValue);
extern uint32_t PAE_M0CFG_OP2_BLK_Get(void);

/* ���ε�����ָ�
000��Jacobin���걶������
001���������������
010��RFU
011���ɸ�������˱������㣨ECDBL��
100���ɸ�������˱��������㣨ECADDDBL��
101���ɸ��������Y����ָ����㣨ECYRecover��
110��RFU
111��RFU ��غ��� */
extern void PAE_M1CFG_INS_M1_Set(uint32_t SetValue);
extern uint32_t PAE_M1CFG_INS_M1_Get(void);

/* ����Aָʾ�ź�
1��A����-3
0��A������-3 ��غ��� */
extern void PAE_M1CFG_AEN3_M1_Set(uint32_t SetValue);
extern uint32_t PAE_M1CFG_AEN3_M1_Get(void);

/* ��ǰ������Կλָʾ��־
1����ǰλΪ1
0����ǰλΪ0 ��غ��� */
extern void PAE_M1CFG_BIT_VALUE_M1_Set(uint32_t SetValue);
extern uint32_t PAE_M1CFG_BIT_VALUE_M1_Get(uint32_t SetValue);
/* ��ģ�˿���λ
1����ǰ��ԿλΪ0ʱͬ������ģ�˲���
0����ǰ��ԿλΪ0ʱ������ģ�˲��� ��غ��� */
extern void PAE_M2CFG_ALWAYS_MULT_Set(uint32_t SetValue);
extern uint32_t PAE_M2CFG_ALWAYS_MULT_Get(void);

/* ��Կλָʾ�źţ�Ӳ���Զ���λ���������
1�����ҵ�Ϊ1��bit
0��δ�ҵ�Ϊ1��bit ��غ��� */
extern void PAE_M2CFG_FBO_M2_Set(uint32_t SetValue);
extern uint32_t PAE_M2CFG_FBO_M2_Get(void);

/* ����Aָʾ�ź�
1��A����-3
0��A������-3 ��غ��� */
extern void PAE_M3CFG_AEN3_M3_Set(uint32_t SetValue);
extern uint32_t PAE_M3CFG_AEN3_M3_Get(void);

/* ��Կλָʾ�źţ�Ӳ���Զ���λ���������
1�����ҵ�Ϊ1��bit
0��δ�ҵ�Ϊ1��bit ��غ��� */
extern void PAE_M3CFG_FBO_M3_Set(uint32_t SetValue);
extern uint32_t PAE_M3CFG_FBO_M3_Get(void);

/* 32bit���ݼĴ�����ֻ��д�����ɶ�����������RSA���������ECC����ģʽ����Ч�� ��غ��� */
extern void PAE_WORD_Write(uint32_t SetValue);
//Announce_End


#ifdef __cplusplus
}
#endif

#endif /* __FM33A0XXEV_PAE_H */
