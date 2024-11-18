/**
  ******************************************************************************
  * @file    fm33a0xxev_gpio.c
  * @author  FM33A0XXEV Application Team
  * @version V1.0.0
  * @date    16-April-2020
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/

#include "fm33a0xxev_gpio.h"
#include "define_all.h"
/** @addtogroup fm33a0xxev_StdPeriph_Driver
  * @{
  */

/** @defgroup GPIO 
  * @brief GPIO driver modules
  * @{
  */ 
	
#ifdef  USE_FULL_ASSERT

/**
  * @brief  The assert_param macro is used for function's parameters check.
  * @param  expr: If expr is false, it calls assert_failed function
  *   which reports the name of the source file and the source
  *   line number of the call that failed. 
  *   If expr is true, it returns no value.
  * @retval None
  */
#define assert_param(expr) ((expr) ? (void)0 : assert_failed((uint8_t *)__FILE__, __LINE__))
/* Exported functions ------------------------------------------------------- */
  void assert_failed(uint8_t* file, uint32_t line);
#else
  #define assert_param(expr) ((void)0)
#endif /* USE_FULL_ASSERT */

/********************************
 PortX������ݼĴ������ú���
����: ����PortX�������
���룺GPIOx_Type* GPIOx���ܽźţ�,  uint32_t SetValue�����ֵ��
���:��
********************************/
void GPIOx_DO_Write(GPIO_Type* GPIOx, uint32_t SetValue)
{
	GPIOx->DO = (SetValue & GPIOx_DO_DO_Msk);
}
/********************************
��PortX�������״̬����
����:��PortX�������״̬
���룺��
���:PortX���ֵ
********************************/
uint32_t GPIOx_DO_Read(GPIO_Type* GPIOx)
{
	return (GPIOx->DO & GPIOx_DO_DO_Msk);
}

/********************************
PortX���������λ�Ĵ�������
����:PortX���������λ������PADSETд0x0000_8000����PADO[15]��λ������λ���ֲ��䡣
���룺GPIOx_Type* GPIOx���ܽźţ�,  uint32_t SetValue�����ֵ��
���:��
********************************/
void GPIOx_DSET_Write(GPIO_Type* GPIOx, uint32_t SetValue)
{
	GPIOx->DSET = (SetValue & GPIOx_DSET_DSET_Msk);
}

/********************************
PortX������ݸ�λ�Ĵ�������
����:PortX������ݸ�λ������PADRSTд0x0000_8000����PADO[15]���㣬����λ���ֲ��䡣
���룺GPIOx_Type* GPIOx���ܽźţ�,  uint32_t SetValue�����ֵ��
���:��
********************************/
void GPIOx_DRST_Write(GPIO_Type* GPIOx, uint32_t SetValue)
{
	GPIOx->DRST = (SetValue & GPIOx_DRST_DRESET_Msk);
}

/********************************
PortX�������ݼĴ�������
����:PortX�������ݣ��˼Ĵ�����ռ�õ�ַ�ռ䣬������ʵ�֡�������˼Ĵ���ֱ�ӷ������������źţ�оƬ���������������������
���룺GPIOx_Type* GPIOx���ܽźţ�,  uint32_t SetValue������ֵ��
���:��
********************************/
uint32_t GPIOx_DIN_Read(GPIO_Type* GPIOx)
{
	return (GPIOx->DIN & GPIOx_DIN_DIN_Msk);
}

/* PortX�������ֹ��ܼĴ��� ��غ��� */
void GPIOx_DFS_Setable(GPIO_Type* GPIOx, uint32_t GPIO_Pin, FunState NewState)
{
	uint32_t tmpreg;
	
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    assert_param(IS_GET_GPIO_PIN(GPIO_Pin));
	
	tmpreg = GPIOx->DFS;
	if (NewState == ENABLE)
	{
		tmpreg |= (GPIO_Pin);
	}
	else
	{
		tmpreg &= ~(GPIO_Pin);
	}
	GPIOx->DFS = tmpreg;
}

FunState GPIOx_DFS_Getable(GPIO_Type* GPIOx, uint32_t GPIO_Pin)
{
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    assert_param(IS_GET_GPIO_PIN(GPIO_Pin));
	
	if (GPIOx->DFS & GPIO_Pin)
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* PortXģ�⿪��ʹ�ܼĴ��� ��غ��� */
void GPIOx_ANEN_Setable(GPIO_Type* GPIOx, uint32_t GPIO_Pin, FunState NewState)
{
	uint32_t tmpreg;
	
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    assert_param(IS_GET_GPIO_PIN(GPIO_Pin));
	
	tmpreg = GPIOx->ANEN;
	if (NewState == ENABLE)
	{
		tmpreg |= (GPIO_Pin);
	}
	else
	{
		tmpreg &= ~(GPIO_Pin);
	}
	GPIOx->ANEN = tmpreg;
}

FunState GPIOx_ANEN_Getable(GPIO_Type* GPIOx, uint32_t GPIO_Pin)
{
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    assert_param(IS_GET_GPIO_PIN(GPIO_Pin));
	
	if (GPIOx->ANEN & GPIO_Pin)
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/********************************
GPIO��ʼ�����ú���
����:GPIO��ʼ������
���룺GPIO�˿�  GPIO_PIN����
���: ��
********************************/
void GPIO_Init(GPIO_Type* GPIOx, GPIO_InitTypeDef* para)
{
    uint32_t pinpos = 0x00,pinbit = 0x00,currentpin =0x00;
    uint32_t tmpreg; 

    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));	
	
    for (pinpos = 0; pinpos < 16; pinpos++)
    {
        pinbit = ((uint32_t)0x01) << pinpos;
        currentpin = (para->Pin) & pinbit;
			
        if (currentpin == pinbit)
        {
            tmpreg = GPIOx->INEN;
            tmpreg &= ~pinbit;
            tmpreg |= (para->PxINEN) << pinpos;	
            GPIOx->INEN = tmpreg;

            tmpreg = GPIOx->PUEN;
            tmpreg &= ~pinbit;
            tmpreg |= (para->PxPUEN) << pinpos;
            GPIOx->PUEN = tmpreg;

            tmpreg = GPIOx->ODEN;
            tmpreg &= ~pinbit;
            tmpreg |= (para->PxODEN) << pinpos;
            GPIOx->ODEN = tmpreg;

            pinbit = (((uint32_t)0x00000003)) << (pinpos*2);
            tmpreg = GPIOx->FCR;
            tmpreg &= ~pinbit;
            tmpreg |= (para->PxFCR)<<(pinpos*2);
            GPIOx->FCR = tmpreg;
        }
    }
}

/* ��ȡһ��IO�ڵ����ò����ṹ�� 
	ע��һ��ֻ�ܶ�ȡһ��IO������
*/
/********************************
��ȡһ��IO���ò����ṹ�庯��
����:��ȡһ��IO���ò����ṹ��
���룺GPIO�˿�  GPIO_PIN���� ��������
���: ��
********************************/
void GPIO_Get_InitPara(GPIO_Type* GPIOx, uint32_t GPIO_Pin, GPIO_InitTypeDef* para)
{
  uint32_t pinbit = 0x00;
  uint32_t i,temp;

	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));	
	
	for (i = 0; i < 16; i++)
	{
		pinbit = GPIO_Pin & (1<<i);
		if(pinbit > 0) break;
	}
	
	if(i < 16)
	{
		pinbit = i;
		para->Pin = GPIO_Pin;
		
		temp = (GPIOx->INEN&GPIO_Pin)>>pinbit;
		if(temp == (uint32_t)GPIO_IN_En)
		{                                         
			para->PxINEN = GPIO_IN_En;
		}
		else
		{
			para->PxINEN = GPIO_IN_Dis;
		}   
		
		temp = (GPIOx->PUEN&GPIO_Pin)>>pinbit;                                    
		if(temp == (uint32_t)GPIO_PU_En)
		{                                         
			para->PxPUEN = GPIO_PU_En;
		}
		else
		{
			para->PxPUEN = GPIO_PU_Dis;
		}   
		
		temp = (GPIOx->ODEN&GPIO_Pin)>>pinbit;                                   
		if(temp == (uint32_t)GPIO_OD_En)
		{                                         
			para->PxODEN = GPIO_OD_En;
		}
		else
		{
			para->PxODEN = GPIO_OD_Dis;
		}  
		
		temp = (GPIOx->FCR>>(pinbit*2))&0x00000003;                                    
		if(temp == (uint32_t)GPIO_FCR_IN)
		{                                         
			para->PxFCR = GPIO_FCR_IN;
		}
		else if(temp == (uint32_t)GPIO_FCR_OUT)
		{
			para->PxFCR = GPIO_FCR_OUT;
		}
		else if(temp == (uint32_t)GPIO_FCR_DIG)
		{                                         
			para->PxFCR = GPIO_FCR_DIG;
		}
		else
		{
			para->PxFCR = GPIO_FCR_ANA;
		}
	}  
}

/********************************
��ȡGPIOx�������ݼĴ�������
����:��ȡGPIOx�������ݼĴ���
���룺GPIOx_PIN���� 
���: ���ݼĴ���ֵ
********************************/
uint32_t GPIO_ReadInputData(GPIO_Type* GPIOx)
{
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
	return (GPIOx->DIN);
}

/********************************
��ȡGPIOx�������ݼĴ���bit����
����:GPIOx�������ݼĴ���bit
���룺GPIO�˿�  GPIO_PIN���� 
���: bit״̬
********************************/
uint8_t GPIO_ReadInputDataBit(GPIO_Type* GPIOx, uint32_t GPIO_Pin)
{
	uint8_t bitstatus = 0x00;

	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
	assert_param(IS_GET_GPIO_PIN(GPIO_Pin));

	if ((GPIOx->DIN & GPIO_Pin) != (uint32_t)Bit_RESET)
	{
        bitstatus = (uint8_t)Bit_SET;
	}
	else
	{
        bitstatus = (uint8_t)Bit_RESET;
	}
	return bitstatus;
}

/********************************
GPIOx�����1����
����: GPIOx�����1
���룺GPIO�˿�  GPIO_PIN���� 
���: ��
********************************/
void GPIO_SetBits(GPIO_Type* GPIOx, uint32_t GPIO_Pin)
{
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN(GPIO_Pin));

    GPIOx->DSET = GPIO_Pin;
}

/********************************
GPIOx�����0����
����: GPIOx�����0
���룺GPIO�˿�  GPIO_PIN���� 
���: ��
********************************/
void GPIO_ResetBits(GPIO_Type* GPIOx, uint32_t GPIO_Pin)
{
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN(GPIO_Pin));
	
    GPIOx->DRST = GPIO_Pin;
}

/********************************
GPIOx�����ת����
����: GPIOx�����0
���룺GPIO�˿�  GPIO_PIN���� 
���: ��
********************************/
void GPIO_ToggleBits(GPIO_Type* GPIOx, uint32_t GPIO_Pin)
{
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN(GPIO_Pin));
	
	if(GPIO_Pin&GPIOx->DO)
	{
		GPIOx->DRST = GPIO_Pin;	
	}
	else
	{
		GPIOx->DSET = GPIO_Pin;
	}
}

/********************************
GPIOH�����1����
����: GPIOH�����1
���룺GPIO_PIN���� 
���: ��
Note:����GPIOH���CDIF(CDIF_CR_INTF_EN_Setable(ENABLE);)
********************************/
void GPIOH_SetBits(uint32_t GPIO_Pin)
{
    GPIOH->DO |= GPIO_Pin;
}

/********************************
GPIOH�����0����
����: GPIOH�����0
���룺GPIO_PIN���� 
���: ��
Note:����GPIOH���CDIF(CDIF_CR_INTF_EN_Setable(ENABLE);)
********************************/
void GPIOH_ResetBits(uint32_t GPIO_Pin)
{
    GPIOH->DO &= ~GPIO_Pin;
}

/********************************
GPIOH�����ת����
����: GPIOx�����0
���룺GPIOH�˿�  GPIO_PIN���� 
���: ��
Note:����GPIOH���CDIF(CDIF_CR_INTF_EN_Setable(ENABLE);)
********************************/
void GPIOH_ToggleBits(uint32_t GPIO_Pin)
{
	if(GPIO_Pin&GPIOH->DO)
	{
		 GPIOH->DO &= ~GPIO_Pin;	
	}
	else
	{
		 GPIOH->DO |= GPIO_Pin;
	}
}

/********************************
��ȡGPIOx������ݼĴ�������
����:��ȡGPIOx������ݼĴ���
���룺GPIOx_PIN���� 
���: ���ݼĴ���ֵ
********************************/
uint32_t GPIO_ReadOutputData(GPIO_Type* GPIOx)
{
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
	
	return (GPIOx->DO);
}

/********************************
��ȡGPIOx������ݼĴ���bit����
����:GPIOx������ݼĴ���bit
���룺GPIO�˿�  GPIO_PIN���� 
���: bit״̬
********************************/
uint8_t GPIO_ReadOutputDataBit(GPIO_Type* GPIOx, uint32_t GPIO_Pin)
{
    uint8_t bitstatus = 0x00;
	
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    assert_param(IS_GET_GPIO_PIN(GPIO_Pin));
	
    if (((GPIOx->DO) & GPIO_Pin) != (uint32_t)Bit_RESET)
    {
        bitstatus = (uint8_t)Bit_SET;
    }
    else
    {
        bitstatus = (uint8_t)Bit_RESET;
    }
    return bitstatus;
}

/********************************
WKUP�������ú���
���ܣ�WKUP��������
���룺WKUP GPIO_PIN����        
      ENABLE ʹ��WKUP����
      DISABLE �ر�WKUP����
���: ��
********************************/
void GPIO_PINWKEN_SetableEx(uint32_t NWKPinDef, FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPIO->PINWKEN |= (1 << NWKPinDef);
	}
	else
	{
		GPIO->PINWKEN &= ~ (1 << NWKPinDef);
	}
}

FunState GPIO_PINWKEN_GetableEx(uint32_t NWKPinDef)
{
	if (GPIO->PINWKEN & (1 << NWKPinDef))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}



/********************************
���� WKUP����ѡ����
���ܣWWKUP����ѡ��
���룺WKUP GPIO_PIN����        
SetValue��GPIO_PINWKEN_PINWKSEL_FALLING   ��Ӧ��WKUP����Ϊ�½��ػ��� 
SetValue��GPIO_PINWKEN_PINWKSEL_RISING    ��Ӧ��WKUP����Ϊ�����ػ��� 
SetValue��GPIO_PINWKEN_PINWKSEL_BOTH      ��Ӧ��WKUP����Ϊ�������½��ػ��� 
���: ��
********************************/
void GPIO_PINWKSEL_SetEx(uint32_t NWKPinDef, uint32_t SetValue)
{
    uint32_t tmpreg;
    uint32_t postion;
    postion = NWKPinDef * 2 + 8;
	tmpreg = GPIO->PINWKEN;
	tmpreg &= ~(3 << postion);
	tmpreg |= ((SetValue << postion) & GPIO_PINWKEN_PINWKSEL_Msk);
	GPIO->PINWKEN = tmpreg;
}

/********************************
��ȡ WKUP����ѡ���� 
���ܣWWKUP����ѡ��
���룺WKUP GPIO_PIN���� 
���: ��
����ֵ�� GPIO_PINWKEN_PINWKSEL_FALLING   ��Ӧ��WKUP����Ϊ�½��ػ��� 
        GPIO_PINWKEN_PINWKSEL_RISING    ��Ӧ��WKUP����Ϊ�����ػ��� 
        GPIO_PINWKEN_PINWKSEL_BOTH      ��Ӧ��WKUP����Ϊ�������½��ػ��� 
********************************/
uint32_t GPIO_PINWKSEL_GetEx(uint32_t NWKPinDef)
{
    uint32_t postion;
    postion = NWKPinDef * 2 + 8;
    return (((GPIO->PINWKEN  & (3 << postion)) & GPIO_PINWKEN_PINWKSEL_Msk) >> postion);
}


/********************************
WKUP�ж����ѡ����
���ܣWWKUP�ж����ѡ��
���룺GPIO_PINWKEN_WKISEL_NMI: NMI�ж�      
      GPIO_PINWKEN_WKISEL_46��#46�ж�
���: ��
********************************/
void GPIO_PINWKEN_WKISEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPIO->PINWKEN;
	tmpreg &= ~(GPIO_PINWKEN_WKISEL_Msk);
	tmpreg |= (SetValue & GPIO_PINWKEN_WKISEL_Msk);
	GPIO->PINWKEN = tmpreg;
}
/********************************
��ȡWKUP�ж����ѡ����
���ܣ���ȡWKUP�ж����ѡ��
���룺��     
���: GPIO_PINWKEN_WKISEL_NMI: NMI�ж� 
      GPIO_PINWKEN_WKISEL_46��#46�ж�
********************************/
uint32_t GPIO_PINWKEN_WKISEL_Get(void)
{
	return (GPIO->PINWKEN & GPIO_PINWKEN_WKISEL_Msk);
}

/*************************************************************************
 �������ƣ�GPIO_EXTI_Select_Pin
 ����˵����GPIO EXTI �ⲿ����ѡ��
 ���������GPIOx �˿� GPIO_Pinpin �˿������� 
 �����������
 ���ز����w��
 *************************************************************************/
void GPIO_EXTI_Select_Pin(GPIO_Type* GPIOx,uint32_t GPIO_Pin)
{
	uint32_t pin_num = 0,i;	
	uint32_t pin_shift;
	uint32_t tmpreg;
	
	for(i= 0;i<16;i++)
	{
		if(GPIO_Pin&(1<<i))
		{
			pin_num = i;
			break;
		}
	}

	if(i == 16)	return;
	
	switch((uint32_t)GPIOx)
	{
		case (uint32_t)GPIOE://
		case (uint32_t)GPIOF://
			if(pin_num > 11)  break;
		
			if((pin_num <= 3))//
			{
				pin_shift = 0;
			}
			else if((pin_num >= 4)&&(pin_num <= 7))
			{
				pin_shift = 2;
			}
			else
			{
				pin_shift = 4;
			}
			if((uint32_t)GPIOx == (uint32_t)GPIOF)
			{
				pin_shift += 8;
			}
			pin_num = pin_num % 4;
			tmpreg = GPIO->EXTISEL1;
			tmpreg &= (~(0x00000003 << pin_shift));
			tmpreg |= (pin_num << pin_shift);
			GPIO->EXTISEL1 = tmpreg;
			break;

		case (uint32_t)GPIOA://
		case (uint32_t)GPIOB://
		case (uint32_t)GPIOC://
		case (uint32_t)GPIOD://
			if(((uint32_t)GPIOx == (uint32_t)GPIOA) ||((uint32_t)GPIOx == (uint32_t)GPIOB)||((uint32_t)GPIOx == (uint32_t)GPIOC))
					if(pin_num > 15)  break;
			
			if((uint32_t)GPIOx == (uint32_t)GPIOD)
					if(pin_num > 11)  break;
			
			if((pin_num <= 3))//
			{
				pin_shift = 0;
			}
			else if((pin_num >= 4)&&(pin_num <= 7))
			{
				pin_shift = 2;
			}
			else if((pin_num >= 8)&&(pin_num <= 11))
			{
				pin_shift = 4;
			}
			else
			{
				pin_shift = 6;
			}
			
			if((uint32_t)GPIOx == (uint32_t)GPIOB)
			{
				pin_shift += 8;
			}
			
			if((uint32_t)GPIOx == (uint32_t)GPIOC)
			{
				pin_shift += 16;
			}
			
			if((uint32_t)GPIOx == (uint32_t)GPIOD)
			{
				pin_shift += 24;
			}
			
			pin_num = pin_num % 4;
			tmpreg = GPIO->EXTISEL0;
			tmpreg &= (~(0x00000003 << pin_shift));
			tmpreg |= (pin_num << pin_shift);
			GPIO->EXTISEL0 = tmpreg;
			break;
		default:
			break;
	}
}
/*************************************************************************
 �������ƣ�GPIO_EXTI_Select_Edge
 ����˵����GPIO EXTI_Select_Edge �ⲿ�жϱ���ѡ��
 ���������GPIOx �˿� ��GPIO_Pin �˿������� ,edge_select ������
 �����������
 ���ز����w��
 *************************************************************************/
void GPIO_EXTI_Select_Edge(GPIO_Type* GPIOx,uint32_t GPIO_Pin,GPIOExtiEdge edge_select)
{
	uint32_t pin_num = 0,i;	
	uint32_t pin_shift;
	uint32_t tmpreg;
	for(i= 0;i<16;i++)
	{
		if(GPIO_Pin&(1<<i))
		{
			pin_num = i;
			break;
		}							
	}	
	if(i == 16)	return;
	
	switch((uint32_t)GPIOx)
	{
		case (uint32_t)GPIOA:
		case (uint32_t)GPIOB:
		case (uint32_t)GPIOC:
		case (uint32_t)GPIOD:
			if(pin_num > 15) break;
			if((pin_num <= 3))//
			{
				pin_shift = 0;
			}
			else if((pin_num >= 4)&&(pin_num <= 7))
			{
				pin_shift = 2;
			}
			else if((pin_num >= 8)&&(pin_num <= 11))
			{
				pin_shift = 4;
			}
			else
			{
				pin_shift = 6;
			}
			
			if(((uint32_t)GPIOx == (uint32_t)GPIOB))
			{
				pin_shift += 8;
			}
			
			if(((uint32_t)GPIOx == (uint32_t)GPIOC))
			{
				pin_shift += 16;
			}
			
			if(((uint32_t)GPIOx == (uint32_t)GPIOD))
			{
				pin_shift += 24;
			}
			tmpreg = GPIO->EXTIEDS0;
			tmpreg &= (~(0x00000003 << pin_shift));			  
			tmpreg |= (edge_select << pin_shift);
			GPIO->EXTIEDS0 = tmpreg;
			break;

		case (uint32_t)GPIOE:
		case (uint32_t)GPIOF:
			if(pin_num > 11) break;
			if((pin_num <= 3))//
			{
				pin_shift = 0;
			}
			else if((pin_num >= 4)&&(pin_num <= 7))
			{
				pin_shift = 2;
			}
			else
			{
				pin_shift = 4;
			}
			
			if(((uint32_t)GPIOx == (uint32_t)GPIOF))
			{
				pin_shift += 8;
			}
			tmpreg = GPIO->EXTIEDS1;
			tmpreg &= (~(0x00000003 << pin_shift));			  
			tmpreg |= (edge_select << pin_shift);
			GPIO->EXTIEDS1 = tmpreg;
		default:
			break;
	}
}

/* EXTI�����˲����ƼĴ��� ��غ��� */
void GPIO_EXTI_EXTIDF_Setable(GPIO_Type* GPIOx, uint32_t GPIO_Pin, FunState NewState)
{
	uint32_t pin_num = 0,i;	
	uint32_t pin_shift;
	uint32_t tmpreg;
	for(i= 0;i<16;i++)
	{
		if(GPIO_Pin&(1<<i))
		{
			pin_num = i;
			break;
		}							
	}
	if(i == 16)	return;

	switch((uint32_t)GPIOx)
	{
		case (uint32_t)GPIOA:
		case (uint32_t)GPIOB:
		case (uint32_t)GPIOC:
		case (uint32_t)GPIOD:
		case (uint32_t)GPIOE:
		case (uint32_t)GPIOF:
			if(((uint32_t)GPIOx == (uint32_t)GPIOE) || ((uint32_t)GPIOx == (uint32_t)GPIOF))
			{
				if(pin_num > 11) break;
			}
			else
			{
				if(pin_num > 15) break;
			}
			
			if((pin_num <= 3))//
			{
				pin_shift = 0;
			}
			else if((pin_num >= 4)&&(pin_num <= 7))
			{
				pin_shift = 1;
			}
			else if((pin_num >= 8)&&(pin_num <= 11))
			{
				pin_shift = 2;
			}
			else
			{
				pin_shift = 3;
			}
			
			if((uint32_t)GPIOx == (uint32_t)GPIOB) 
			{
				pin_shift += 4;
			}
			if((uint32_t)GPIOx == (uint32_t)GPIOC) 
			{
				pin_shift += 8;
			}
			if((uint32_t)GPIOx == (uint32_t)GPIOD) 
			{
				pin_shift += 12;
			}
			if((uint32_t)GPIOx == (uint32_t)GPIOE) 
			{
				pin_shift += 16;
			}
			if((uint32_t)GPIOx == (uint32_t)GPIOF) 
			{
				pin_shift += 20;
			}

			tmpreg = GPIO->EXTIDF; 
			if(NewState == ENABLE)
			{
				tmpreg |= 1 << pin_shift;
			}
			else
			{
				tmpreg &= (~(1 << pin_shift));
			}
			GPIO->EXTIDF = tmpreg;
			break;

		default:
			break;
	}

}

/* ��ȡEXTI�����źżĴ��� */
FunState GPIO_EXTI_EXTIDI_Getable(GPIO_Type* GPIOx, uint32_t GPIO_Pin)
{
	uint32_t pin_num = 0,i;	
	uint32_t pin_shift;
	FunState Result = DISABLE;
	for(i= 0;i<16;i++)
	{
		if(GPIO_Pin&(1<<i))
		{
			pin_num = i;
			break;
		}							
	}
	
	if(i == 16)	return Result;
	
	switch((uint32_t)GPIOx)
	{
		case (uint32_t)GPIOA:
		case (uint32_t)GPIOB:
		case (uint32_t)GPIOC:
		case (uint32_t)GPIOD:
		case (uint32_t)GPIOE:
		case (uint32_t)GPIOF:
			if(((uint32_t)GPIOx == (uint32_t)GPIOE) || ((uint32_t)GPIOx == (uint32_t)GPIOF))
			{
				if(pin_num > 11) break;
			}
			else
			{
				if(pin_num > 15) break;
			}
			
			if((pin_num <= 3))//
			{
				pin_shift = 0;
			}
			else if((pin_num >= 4)&&(pin_num <= 7))
			{
				pin_shift = 1;
			}
			else if((pin_num >= 8)&&(pin_num <= 11))
			{
				pin_shift = 2;
			}
			else
			{
				pin_shift = 3;
			}
			
			if((uint32_t)GPIOx == (uint32_t)GPIOB) 
			{
				pin_shift += 4;
			}
			if((uint32_t)GPIOx == (uint32_t)GPIOC) 
			{
				pin_shift += 8;
			}
			if((uint32_t)GPIOx == (uint32_t)GPIOD) 
			{
				pin_shift += 12;
			}
			if((uint32_t)GPIOx == (uint32_t)GPIOE) 
			{
				pin_shift += 16;
			}
			if((uint32_t)GPIOx == (uint32_t)GPIOF) 
			{
				pin_shift += 20;
			}

			if((GPIO->EXTIDI & (1 << pin_shift)) == (1 << pin_shift)) 
			{
			  Result = ENABLE;
			}
			else
			{
			  Result = DISABLE;
			}
			break;
		default:
			break;
	}

	return Result;
}

/*************************************************************************
 �������ƣ�GPIO_EXTI_EXTIISR_ClrEx
 ����˵����GPIO_EXTI_EXTIISR_ClrEx ����жϱ�־
 ���������GPIOx �˿� ��GPIO_Pin �˿������� 
 �����������
 ���ز����w��
 *************************************************************************/
void GPIO_EXTI_EXTIISR_ClrEx(GPIO_Type* GPIOx,uint32_t GPIO_Pin)
{
	uint32_t pin_num = 0,i;	
	uint32_t pin_shift;
	uint32_t tmpreg;
	for(i= 0;i<16;i++)
	{
		if(GPIO_Pin&(1<<i))
		{
			pin_num = i;
			break;
		}							
	}

	if(i == 16)	return ;
	
	switch((uint32_t)GPIOx)
	{
		case (uint32_t)GPIOA:
		case (uint32_t)GPIOB:
		case (uint32_t)GPIOC:
		case (uint32_t)GPIOD:
		case (uint32_t)GPIOE:
		case (uint32_t)GPIOF:
			if(((uint32_t)GPIOx == (uint32_t)GPIOE) || ((uint32_t)GPIOx == (uint32_t)GPIOF))
			{
				if(pin_num > 11) break;
			}
			else
			{
				if(pin_num > 15) break;
			}
			
			if((pin_num <= 3))//
			{
				pin_shift = 0;
			}
			else if((pin_num >= 4)&&(pin_num <= 7))
			{
				pin_shift = 1;
			}
			else if((pin_num >= 8)&&(pin_num <= 11))
			{
				pin_shift = 2;
			}
			else
			{
				pin_shift = 3;
			}
			
			if((uint32_t)GPIOx == (uint32_t)GPIOB) 
			{
				pin_shift += 4;
			}
			if((uint32_t)GPIOx == (uint32_t)GPIOC) 
			{
				pin_shift += 8;
			}
			if((uint32_t)GPIOx == (uint32_t)GPIOD) 
			{
				pin_shift += 12;
			}
			if((uint32_t)GPIOx == (uint32_t)GPIOE) 
			{
				pin_shift += 16;
			}
			if((uint32_t)GPIOx == (uint32_t)GPIOF) 
			{
				pin_shift += 20;
			}

			tmpreg = GPIO->EXTIISR; 
			tmpreg |= (1 << pin_shift);
			GPIO->EXTIISR = tmpreg;
			break;

		default:
			break;
	}
}
  
/*************************************************************************
 �������ƣ�GPIO_EXTI_EXTIISR_ChkEx
 ����˵����GPIO_EXTI_EXTIISR_ChkEx ��ȡ�жϱ�־״̬
 ���������GPIOx �˿� ��GPIO_Pin �˿������� 
 �����������
 ���ز����wFlagStatus �жϱ�־״̬
 *************************************************************************/
FlagStatus GPIO_EXTI_EXTIISR_ChkEx(GPIO_Type* GPIOx,uint32_t GPIO_Pin)
{
	uint32_t pin_num = 0,i;	
	uint32_t pin_shift;
	FlagStatus Result = RESET;
	
	for(i= 0;i<16;i++)
	{
		if(GPIO_Pin&(1<<i))
		{
			pin_num = i;
			break;
		}							
	}
	
	if(i == 16)	return Result;
	
	switch((uint32_t)GPIOx)
	{
		case (uint32_t)GPIOA:
		case (uint32_t)GPIOB:
		case (uint32_t)GPIOC:
		case (uint32_t)GPIOD:
		case (uint32_t)GPIOE:
		case (uint32_t)GPIOF:
			if(((uint32_t)GPIOx == (uint32_t)GPIOE) || ((uint32_t)GPIOx == (uint32_t)GPIOF))
			{
				if(pin_num > 11) break;
			}
			else
			{
				if(pin_num > 15) break;
			}
			
			if((pin_num <= 3))//
			{
				pin_shift = 0;
			}
			else if((pin_num >= 4)&&(pin_num <= 7))
			{
				pin_shift = 1;
			}
			else if((pin_num >= 8)&&(pin_num <= 11))
			{
				pin_shift = 2;
			}
			else
			{
				pin_shift = 3;
			}
			
			if((uint32_t)GPIOx == (uint32_t)GPIOB) 
			{
				pin_shift += 4;
			}
			if((uint32_t)GPIOx == (uint32_t)GPIOC) 
			{
				pin_shift += 8;
			}
			if((uint32_t)GPIOx == (uint32_t)GPIOD) 
			{
				pin_shift += 12;
			}
			if((uint32_t)GPIOx == (uint32_t)GPIOE) 
			{
				pin_shift += 16;
			}
			if((uint32_t)GPIOx == (uint32_t)GPIOF) 
			{
				pin_shift += 20;
			}
			if((GPIO->EXTIISR & (1 << pin_shift)) == (1 << pin_shift)) 	Result = SET;
			break;
		default:
			break;
	}
	
	return Result;
}

/********************************
 FOUT1������ú���
����: ����FOUT1���
���룺���Ƶ��ѡ���ź�
���:��
********************************/
void GPIO_FOUTSEL_FOUT1SEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPIO->FOUTSEL;
	tmpreg &= ~(GPIO_FOUTSEL_FOUT1SEL_Msk);
	tmpreg |= (SetValue & GPIO_FOUTSEL_FOUT1SEL_Msk);
	GPIO->FOUTSEL = tmpreg;
}
/********************************
��FOUT1���״̬����
����:��FOUT1���״̬
���룺��
���:FOUT���ѡ��ֵ
********************************/
uint32_t GPIO_FOUTSEL_FOUT1SEL_Get(void)
{
	return (GPIO->FOUTSEL & GPIO_FOUTSEL_FOUT1SEL_Msk);
}

/********************************
 FOUT0������ú���
����: ����FOUT0���
���룺���Ƶ��ѡ���ź�
���:��
********************************/
void GPIO_FOUTSEL_FOUT0SEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPIO->FOUTSEL;
	tmpreg &= ~(GPIO_FOUTSEL_FOUT0SEL_Msk);
	tmpreg |= (SetValue & GPIO_FOUTSEL_FOUT0SEL_Msk);
	GPIO->FOUTSEL = tmpreg;
}
/********************************
��FOUT0���״̬����
����:��FOUT0���״̬
���룺��
���:FOUT���ѡ��ֵ
********************************/
uint32_t GPIO_FOUTSEL_FOUT0SEL_Get(void)
{
	return (GPIO->FOUTSEL & GPIO_FOUTSEL_FOUT0SEL_Msk);
}


/*************************************************************************
 �������ƣ�GPIO_EXTI_Init
 ����˵����GPIO_EXTI_Init �ⲿ�жϳ�ʼ��
 ���������port �˿� ��pin �˿������� ,edge ������
 �����������
 ���ز����w��
 *************************************************************************/
void GPIO_EXTI_Init(GPIO_Type* GPIOx, uint32_t GPIO_Pin, GPIOExtiEdge edge_select, FunState DFState)
{
	GPIO_EXTI_Select_Edge(GPIOx, GPIO_Pin, EXTIDISABLE);	//�رձ��ش���
	GPIO_EXTI_Select_Pin(GPIOx, GPIO_Pin);					//�ⲿ����ѡ��
	GPIO_EXTI_EXTIDF_Setable(GPIOx, GPIO_Pin, DFState);     //�����˲�ʹ��ѡ��
	GPIO_EXTI_Select_Edge(GPIOx, GPIO_Pin, edge_select);	//�޸ı���ѡ��
    TicksDelayUs(200);                                      //�ȴ�����4��lsclk
    GPIO_EXTI_EXTIISR_ClrEx(GPIOx, GPIO_Pin);				//����жϱ�־
    NVIC_ClearPendingIRQ(GPIO_IRQn);	                    //����жϹ���
}

/*************************************************************************
 �������ƣ�GPIO_EXTI_Close
 ����˵����GPIO_EXTI_Close �ⲿ�жϹر�
 ���������port �˿� ��pin �˿������� 
 �����������
 ���ز����w��
 *************************************************************************/
void GPIO_EXTI_Close(GPIO_Type* GPIOx,uint32_t GPIO_Pin)
{
	GPIO_EXTI_Select_Edge(GPIOx, GPIO_Pin, EXTIDISABLE);//�رձ��ش���
}


/********************************
GPIOH��ʼ�����ú���
����:GPIO��ʼ������
���룺GPIO�˿�  GPIO_PIN����
���: ��
********************************/
void GPIOH_Init(GPIO_InitTypeDef* para)
{
    uint32_t pinpos = 0x00,pinbit = 0x00,currentpin =0x00;
    uint32_t tmpreg; 
	
    for (pinpos = 0; pinpos < 4; pinpos++)
    {
        pinbit = ((uint32_t)0x01) <<pinpos;
        currentpin = (para->Pin) & pinbit;
			
        if (currentpin == pinbit)
        {
            tmpreg = GPIOH->INEN;
            tmpreg &= ~pinbit;
            tmpreg |= (para->PxINEN)<<pinpos;	
            GPIOH->INEN = tmpreg;
            
            tmpreg = GPIOH->PUEN;
            tmpreg &= ~pinbit;
            tmpreg |= (para->PxPUEN)<<pinpos;
            GPIOH->PUEN = tmpreg;

            pinbit = (((uint32_t)0x00000003)) <<(pinpos*2);
            tmpreg = GPIOH->FCR;
            tmpreg &= ~pinbit;
            tmpreg |= (para->PxFCR)<<(pinpos*2);
            GPIOH->FCR = tmpreg;
        }
    }
}

/********************************
��ȡһ��IO���ò����ṹ�庯��
����:��ȡһ��IO���ò����ṹ��
���룺GPIO�˿�  GPIO_PIN���� ��������
���: ��
********************************/
void GPIOH_Get_InitPara(uint32_t GPIO_Pin, GPIO_InitTypeDef* para)
{
    uint32_t pinbit = 0x00;
    uint32_t i,temp;

    assert_param(IS_GET_GPIOH_PIN(GPIO_Pin));
    for (i = 0; i < 4; i++)
    {
        pinbit = GPIO_Pin & (1<<i);
        if(pinbit > 0) break;
    }

    if(i < 4)
    {
        pinbit = i;
        para->Pin = GPIO_Pin;
        
        temp = (GPIOH->INEN&GPIO_Pin)>>pinbit;
        if(temp == (uint32_t)GPIO_IN_En)
        {                                         
            para->PxINEN = GPIO_IN_En;
        }
        else
        {
            para->PxINEN = GPIO_IN_Dis;
        }   
        
        temp = (GPIOH->PUEN&GPIO_Pin)>>pinbit;                                    
        if(temp == (uint32_t)GPIO_PU_En)
        {                                         
            para->PxPUEN = GPIO_PU_En;
        }
        else
        {
            para->PxPUEN = GPIO_PU_Dis;
        }   
                
        temp = (GPIOH->FCR>>(pinbit*2))&0x00000003;                                    
        if(temp == (uint32_t)GPIO_FCR_IN)
        {                                         
            para->PxFCR = GPIO_FCR_IN;
        }
        else if(temp == (uint32_t)GPIO_FCR_OUT)
        {
            para->PxFCR = GPIO_FCR_OUT;
        }
        else if(temp == (uint32_t)GPIO_FCR_DIG)
        {                                         
            para->PxFCR = GPIO_FCR_DIG;
        }
        else
        {
            para->PxFCR = GPIO_FCR_ANA;
        }
    }  
}

/********************************
 PortH������ݼĴ������ú���
����: ����PortH�������
���룺uint32_t SetValue�����ֵ��
���:��
Note:����GPIOH���CDIF(CDIF_CR_INTF_EN_Setable(ENABLE);)
********************************/
void GPIOH_DO_Write(uint32_t SetValue)
{
	GPIOH->DO = (SetValue & GPIOH_DO_PHDO_Msk);
}
/* 
��ȡGPIOH����Ĵ��� 
Note:����GPIOH���CDIF(CDIF_CR_INTF_EN_Setable(ENABLE);)
*/
uint32_t GPIOH_ReadOutputData(void)
{
	return (GPIOH->DO & GPIOH_DO_PHDO_Msk);
}

/* 
���ܽ�Pin��ȡ����Ĵ��� 
Note:����GPIOH���CDIF(CDIF_CR_INTF_EN_Setable(ENABLE);)
*/
uint8_t GPIOH_ReadOutputDataBit(uint32_t GPIO_Pin)
{
    uint8_t bitstatus = 0x00;
    assert_param(IS_GET_GPIOH_PIN(GPIO_Pin));
    if ((GPIOH->DO & GPIO_Pin) != (uint32_t)Bit_RESET)
    {
        bitstatus = (uint8_t)Bit_SET;
    }
    else
    {
        bitstatus = (uint8_t)Bit_RESET;
    }
    return bitstatus;
}

/* 
��ȡGPIOH����Ĵ��� 
Note:����GPIOH���CDIF(CDIF_CR_INTF_EN_Setable(ENABLE);)
*/
uint32_t GPIOH_ReadInputData(void)
{
	return (GPIOH->DIN & GPIOH_DIN_PHDIN_Msk);
}

/* 
���ܽ�Pin��ȡ����Ĵ���
Note:����GPIOH���CDIF(CDIF_CR_INTF_EN_Setable(ENABLE);)
*/
uint8_t GPIOH_ReadInputDataBit(uint32_t GPIO_Pin)
{
    uint8_t bitstatus = 0x00;
    assert_param(IS_GET_GPIOH_PIN(GPIO_Pin));
    if ((GPIOH->DIN & GPIO_Pin) != (uint32_t)Bit_RESET)
    {
        bitstatus = (uint8_t)Bit_SET;
    }
    else
    {
        bitstatus = (uint8_t)Bit_RESET;
    }
    return bitstatus;
}

/********************************
 IOMCR��ѡһ������ú���
����: ����IO��ѡһ���
���룺���IOͨ��ѡ������
���:��
********************************/
void GPIO_IOMCR_IOMUXSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPIO->IOMCR;
	tmpreg &= ~(GPIO_IOMCR_IOMUXSEL_Msk);
	tmpreg |= (SetValue & GPIO_IOMCR_IOMUXSEL_Msk);
	GPIO->IOMCR = tmpreg;
}
/********************************
��IOMCR��ѡһ���ú���
����:��IOMCR��ѡһ����״̬
���룺��
���:IOMCR��ѡһ����ѡ��ֵ
********************************/
uint32_t GPIO_IOMCR_IOMUXSEL_Get(void)
{
	return (GPIO->IOMCR & GPIO_IOMCR_IOMUXSEL_Msk);
}

/* GPIO ��ѡһʹ�� ���� */
void GPIO_IOMCR_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPIO->IOMCR |=  GPIO_IOMCR_IOMCUEN_Msk;
	}
	else
	{
		GPIO->IOMCR &= ~(GPIO_IOMCR_IOMCUEN_Msk);
	}
}

FunState GPIO_IOMCR_Getable(void)
{
	if (GPIO->IOMCR  & (GPIO_IOMCR_IOMCUEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/******END OF FILE****/
