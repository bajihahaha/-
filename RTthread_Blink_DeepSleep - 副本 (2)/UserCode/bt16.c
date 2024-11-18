#include "define_all.h"  
#include "bt16.h"

extern int ret;

void BTx_IRQHandler(void)
{
	if(	BTx_ISR_CMPHIF_Chk(BT1)==SET)
	{	
		BTx_ISR_CMPLIF_Clr(BT1);
		BTx_ISR_CMPHIF_Clr(BT1);
		BTx_CR1_CHEN_Setable(BT1,DISABLE);	
		AT_IS_OverTime=1;//atָ�ʱ
	}
	if(	BTx_ISR_CMPHIF_Chk(BT2)==SET)
	{	BTx_ISR_CMPLIF_Clr(BT2);
		BTx_ISR_CMPHIF_Clr(BT2);
		BTx_CR1_CHEN_Setable(BT2,DISABLE);
	}

}


/*8λ��ʱ����ʱ��Դѡ��8M APB ���ʱΪ65535*256/8000000= 2.097s*/
void BtimerInit(BT_Type* BTx,int time_second)
{
	uint8_t temp;
  if((BTx != BT1) && (BTx != BT2))    return;
        
	if(BTx == BT1)
        CMU_PERCLK_SetableEx(BT1CLK, ENABLE); 
	else
		CMU_PERCLK_SetableEx(BT2CLK, ENABLE);
    
	BTx_CR1_MODE_Set(BTx,BTx_CR1_MODE_COUNTER);		                //������					
	BTx_CR1_EDGESEL_Set(BTx,BTx_CR1_EDGESEL_FALLING);	            //�½���
	BTx_CR2_SIG2SEL_Set(BTx,BTx_CR2_SIG2SEL_GROUP1); 			    //����Դѡ��group1
	BTx_CFGR1_GRP1SEL_Set(BTx,BTx_CFGR1_GRP1SEL_APBCLK);	        //����Դѡ��group1-APB 
	
	temp=3125*time_second;
	
	BTx_PRES_Write(BTx,256-1);			                            //Ԥ��Ƶ100
	BTx_LOADL_Write(BTx,temp&0xFF);				                        //װ��ֵ 8000(=0x1F40),��ʱ����Ϊ8000*100/8000000=100ms
	BTx_LOADH_Write(BTx,(temp>>8)&0xff);
	
	BTx_CR2_CNTHSEL_Set(BTx,BTx_CR2_CNTHSEL_COUNTER);	            //��λ������ԴΪ��λ�����������16λ������
	BTx_CR2_STDIR_Setable(BTx,DISABLE);                             //�ڲ�DIR�����źţ���DIRENΪ0�����ⲿ����DIR������Чʱ�����ɸ��źŴ���DIR���룬ֱ�ӿ����ڲ��������ļ���������Ҫ�ⲿDIR���룬��DIRENΪ1ʱ����λӦ����Ϊ0 (set direction)
	BTx_ISR_CMPHIF_Clr(BTx);
	BTx_LOADCR_LLEN_Setable(BTx,ENABLE);
	BTx_LOADCR_LHEN_Setable(BTx,ENABLE);	

	NVIC_DisableIRQ(BTx_IRQn);
	NVIC_SetPriority(BTx_IRQn,3);
	NVIC_EnableIRQ(BTx_IRQn);
	BTx_IER_CMPHIE_Setable(BTx,ENABLE);
	BTx_IER_OVHIE_Setable(BTx,ENABLE);		
}

void BtimerStart(BT_Type* BTx)
{
    if((BTx != BT1) && (BTx != BT2))    return;
	
		BTx_CR1_CHEN_Setable(BTx,ENABLE);	
	
}
void BtimerStop(BT_Type* BTx)
{
	if((BTx != BT1) && (BTx != BT2))    return;
	
		BTx_CR1_CHEN_Setable(BTx,DISABLE);	

}




