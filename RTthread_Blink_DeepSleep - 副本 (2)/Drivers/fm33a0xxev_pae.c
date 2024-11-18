/**
  ******************************************************************************
  * @file    fm33a0xxev_pae.c
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/

#include "fm33a0xxev_pae.h"

/** @addtogroup fm33a0xxev_StdPeriph_Driver
  * @{
  */

/** @defgroup PAE 
  * @brief PAE driver modules
  * @{
  */ 

/* ��������˳�򽻻�����
00��������
01��half-word����
10��byte����
11��bit����
�˼Ĵ������ڶ�����32bit���ݵ�λ����е�������������Ϊ0x1234_5678��half-word������Ϊ0x5678_1234��byte������Ϊ0x7856_3412��bit������Ϊ0x1E6A_2C48 ��غ��� */
void PAE_CSR_DATA_TYPE_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = PAE->CSR;
	tmpreg &= ~(PAE_CSR_DATA_TYPE_Msk);
	tmpreg |= (SetValue & PAE_CSR_DATA_TYPE_Msk);
	PAE->CSR = tmpreg;
}

uint32_t PAE_CSR_DATA_TYPE_Get(void)
{
	return (PAE->CSR & PAE_CSR_DATA_TYPE_Msk);
}

/* ��������λ�����д1�������㣬���������Ӳ���Զ����� ��غ��� */
void PAE_CSR_START_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		PAE->CSR |= (PAE_CSR_START_Msk);
	}
	else
	{
		PAE->CSR &= ~(PAE_CSR_START_Msk);
	}
}

/* ģ�鹤��ģʽ��
00��ģʽ0������ģ���㣬������4Block/16Block
01��ģʽ1�����ε����㣬�̶�16Block
10��ģʽ2��32bit��Կ����RSA���㣬�̶�4Block
11��ģʽ3��32bit��Կ����ECC���㣬�̶�16Block ��غ��� */
void PAE_CSR_RUN_MODE_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = PAE->CSR;
	tmpreg &= ~(PAE_CSR_RUN_MODE_Msk);
	tmpreg |= (SetValue & PAE_CSR_RUN_MODE_Msk);
	PAE->CSR = tmpreg;
}

uint32_t PAE_CSR_RUN_MODE_Get(void)
{
	return (PAE->CSR & PAE_CSR_RUN_MODE_Msk);
}

/* PAE�����λ�����д1��λPAE�ڲ���Ҫ�Ĵ�����ģ���Ĵ���PAE_MLR��ģ�μĴ���PAE_MPR����Ӱ�죩����λ������Ӳ���Զ�����
ע�⣺���дSOFT_RST֮�����������һ��NOPָ�����д��PAE�����Ĵ�������SOFT_RST����������дPAE�Ĵ�������д��ʧ�ܡ� ��غ��� */
void PAE_CSR_SOFT_RST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		PAE->CSR |= (PAE_CSR_SOFT_RST_Msk);
	}
	else
	{
		PAE->CSR &= ~(PAE_CSR_SOFT_RST_Msk);
	}
}

/* PAE�ж�ʹ��
1��ʹ���ж����
0����ֹ�ж���� ��غ��� */
void PAE_CSR_PAEIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		PAE->CSR |= (PAE_CSR_PAEIE_Msk);
	}
	else
	{
		PAE->CSR &= ~(PAE_CSR_PAEIE_Msk);
	}
}

FunState PAE_CSR_PAEIE_Getable(void)
{
	if (PAE->CSR & (PAE_CSR_PAEIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}
/* PAE�жϱ�־�Ĵ��� ��غ��� */
void PAE_CSR_PAEIF_Clr(void)
{
	PAE->CSR = PAE_CSR_PAEIF_Msk;
}

FlagStatus PAE_CSR_PAEIF_Chk(void)
{
	if (PAE->CSR & PAE_CSR_PAEIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* PAE������־
1��PAE����������
0��PAE���� ��غ��� */
FlagStatus PAE_CSR_BUSY_Chk(void)
{
	if (PAE->CSR & PAE_CSR_BUSY_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��RAM����Ϊ4 Blockʱ��ģ�����Ϊ2048bit��
ģ��=��MLR[5:0]+1��*32λ��
��RAM����Ϊ16 Blockʱ��ģ�����Ϊ512bit��MLRֻ�е�4bit��Ч��
ģ��=��MLR[3:0]+1��*32λ�� ��غ��� */
void PAE_MLR_Write(uint32_t SetValue)
{
	PAE->MLR = (SetValue & PAE_MLR_PAE_MLR_Msk);
}

uint32_t PAE_MLR_Read(void)
{
	return (PAE->MLR & PAE_MLR_PAE_MLR_Msk);
}

/* 32bitģ�μĴ�����ֻ��д�����ɶ� ��غ��� */
void PAE_MPR_Write(uint32_t SetValue)
{
	PAE->MPR = (SetValue);
}

/* RAM Block����λ
1���㷨RAM����Ϊ16 Block
0���㷨RAM����λ4 Block ��غ��� */
void PAE_M0CFG_BLKCFG_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = PAE->M0CFG;
	tmpreg &= ~(PAE_M0CFG_BLKCFG_Msk);
	tmpreg |= (SetValue & PAE_M0CFG_BLKCFG_Msk);
	PAE->M0CFG = tmpreg;
}

uint32_t PAE_M0CFG_BLKCFG_Get(void)
{
	return (PAE->M0CFG & PAE_M0CFG_BLKCFG_Msk);
}

/* ����ģ����ָ�
00���ɸ�����ģ��
01���ɸ�����ģ��
10��RFU
11���ɸ�����ģ�� ��غ��� */
void PAE_M0CFG_INS_M0_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = PAE->M0CFG;
	tmpreg &= ~(PAE_M0CFG_INS_M0_Msk);
	tmpreg |= (SetValue & PAE_M0CFG_INS_M0_Msk);
	PAE->M0CFG = tmpreg;
}

uint32_t PAE_M0CFG_INS_M0_Get(void)
{
	return (PAE->M0CFG & PAE_M0CFG_INS_M0_Msk);
}

/* ��������������Block
��BLK_CFG==1��4bit��Ч����ʾBlock0~Block15
��BLK_CFG==0����2bit��Ч����ʾBlock0~Block3 ��غ��� */
void PAE_M0CFG_RES_BLK_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = PAE->M0CFG;
	tmpreg &= ~(PAE_M0CFG_RES_BLK_Msk);
	tmpreg |= (SetValue & PAE_M0CFG_RES_BLK_Msk);
	PAE->M0CFG = tmpreg;
}

uint32_t PAE_M0CFG_RES_BLK_Get(void)
{
	return (PAE->M0CFG & PAE_M0CFG_RES_BLK_Msk);
}

/* ������1��ַ��
��BLK_CFG==1��4bit��Ч����ʾBlock0~Block15
��BLK_CFG==0����2bit��Ч����ʾBlock0~Block3 ��غ��� */
void PAE_M0CFG_OP1_BLK_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = PAE->M0CFG;
	tmpreg &= ~(PAE_M0CFG_OP1_BLK_Msk);
	tmpreg |= (SetValue & PAE_M0CFG_OP1_BLK_Msk);
	PAE->M0CFG = tmpreg;
}

uint32_t PAE_M0CFG_OP1_BLK_Get(void)
{
	return (PAE->M0CFG & PAE_M0CFG_OP1_BLK_Msk);
}

/* ������2��ַ��
��BLK_CFG==1��4bit��Ч����ʾBlock0~Block15
��BLK_CFG==0����2bit��Ч����ʾBlock0~Block3 ��غ��� */
void PAE_M0CFG_OP2_BLK_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = PAE->M0CFG;
	tmpreg &= ~(PAE_M0CFG_OP2_BLK_Msk);
	tmpreg |= (SetValue & PAE_M0CFG_OP2_BLK_Msk);
	PAE->M0CFG = tmpreg;
}

uint32_t PAE_M0CFG_OP2_BLK_Get(void)
{
	return (PAE->M0CFG & PAE_M0CFG_OP2_BLK_Msk);
}

/* ���ε�����ָ�
000��Jacobin���걶������
001���������������
010��RFU
011���ɸ�������˱������㣨ECDBL��
100���ɸ�������˱��������㣨ECADDDBL��
101���ɸ��������Y����ָ����㣨ECYRecover��
110��RFU
111��RFU ��غ��� */
void PAE_M1CFG_INS_M1_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = PAE->M1CFG;
	tmpreg &= ~(PAE_M1CFG_INS_M1_Msk);
	tmpreg |= (SetValue & PAE_M1CFG_INS_M1_Msk);
	PAE->M1CFG = tmpreg;
}

uint32_t PAE_M1CFG_INS_M1_Get(void)
{
	return (PAE->M1CFG & PAE_M1CFG_INS_M1_Msk);
}

/* ����Aָʾ�ź�
1��A����-3
0��A������-3 ��غ��� */
void PAE_M1CFG_AEN3_M1_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = PAE->M1CFG;
	tmpreg &= ~(PAE_M1CFG_AEN3_M1_Msk);
	tmpreg |= (SetValue & PAE_M1CFG_AEN3_M1_Msk);
	PAE->M1CFG = tmpreg;
}

uint32_t PAE_M1CFG_AEN3_M1_Get(void)
{
	return (PAE->M1CFG & PAE_M1CFG_AEN3_M1_Msk);
}

/* ��ǰ������Կλָʾ��־
1����ǰλΪ1
0����ǰλΪ0 ��غ��� */
void PAE_M1CFG_BIT_VALUE_M1_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = PAE->M1CFG;
	tmpreg &= ~(PAE_M1CFG_BIT_VALUE_M1_Msk);
	tmpreg |= (SetValue & PAE_M1CFG_BIT_VALUE_M1_Msk);
	PAE->M1CFG = tmpreg;
}

uint32_t PAE_M1CFG_BIT_VALUE_M1_Get(uint32_t SetValue)
{
	return (PAE->M1CFG & PAE_M1CFG_BIT_VALUE_M1_Msk);
}

/* ��ģ�˿���λ
1����ǰ��ԿλΪ0ʱͬ������ģ�˲���
0����ǰ��ԿλΪ0ʱ������ģ�˲��� ��غ��� */
void PAE_M2CFG_ALWAYS_MULT_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = PAE->M2CFG;
	tmpreg &= ~(PAE_M2CFG_ALWAYS_MULT_Msk);
	tmpreg |= (SetValue & PAE_M2CFG_ALWAYS_MULT_Msk);
	PAE->M2CFG = tmpreg;
}

uint32_t PAE_M2CFG_ALWAYS_MULT_Get(void)
{
	return (PAE->M2CFG & PAE_M2CFG_ALWAYS_MULT_Msk);
}

/* ��Կλָʾ�źţ�Ӳ���Զ���λ���������
1�����ҵ�Ϊ1��bit
0��δ�ҵ�Ϊ1��bit ��غ��� */
void PAE_M2CFG_FBO_M2_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = PAE->M2CFG;
	tmpreg &= ~(PAE_M2CFG_FBO_M2_Msk);
	tmpreg |= (SetValue & PAE_M2CFG_FBO_M2_Msk);
	PAE->M2CFG = tmpreg;
}

uint32_t PAE_M2CFG_FBO_M2_Get(void)
{
	return (PAE->M2CFG & PAE_M2CFG_FBO_M2_Msk);
}

/* ����Aָʾ�ź�
1��A����-3
0��A������-3 ��غ��� */
void PAE_M3CFG_AEN3_M3_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = PAE->M3CFG;
	tmpreg &= ~(PAE_M3CFG_AEN3_M3_Msk);
	tmpreg |= (SetValue & PAE_M3CFG_AEN3_M3_Msk);
	PAE->M3CFG = tmpreg;
}

uint32_t PAE_M3CFG_AEN3_M3_Get(void)
{
	return (PAE->M3CFG & PAE_M3CFG_AEN3_M3_Msk);
}

/* ��Կλָʾ�źţ�Ӳ���Զ���λ���������
1�����ҵ�Ϊ1��bit
0��δ�ҵ�Ϊ1��bit ��غ��� */
void PAE_M3CFG_FBO_M3_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = PAE->M3CFG;
	tmpreg &= ~(PAE_M3CFG_FBO_M3_Msk);
	tmpreg |= (SetValue & PAE_M3CFG_FBO_M3_Msk);
	PAE->M3CFG = tmpreg;
}

uint32_t PAE_M3CFG_FBO_M3_Get(void)
{
	return (PAE->M3CFG & PAE_M3CFG_FBO_M3_Msk);
}

/* 32bit���ݼĴ�����ֻ��д�����ɶ�����������RSA���������ECC����ģʽ����Ч�� ��غ��� */
void PAE_WORD_Write(uint32_t SetValue)
{
	PAE->WORD = (SetValue);
}


void PAE_Deinit(void)
{
	//PAE->CSR = 0x00000000;
	//PAE->MLR = 0x00000000;
	//PAE->MPR = 0x00000000;
	//PAE->M0CFG = 0x00000000;
	//PAE->M1CFG = 0x00000000;
	//PAE->M2CFG = 0x00000000;
	//PAE->M3CFG = 0x00000000;
	//PAE->WORD = 0x00000000;
}

/******END OF FILE****/

