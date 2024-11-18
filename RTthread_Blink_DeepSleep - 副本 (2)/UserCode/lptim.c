#include "define_all.h"  
#include "lptim.h"

void LPTIM_COUNTER_5Min(void) //��ʱ5����
{
  CMU_PERCLK_SetableEx(LPTCLK, ENABLE); //��������ʱ��ʹ��
  CMU_OPCCR2_LPTCKS_Set(CMU_OPCCR2_LPTCKS_RCLP);//ѡ����ʱ��Դ
  CMU_OPCCR2_LPTCKE_Setable(ENABLE);     //����ʱ��Դʹ��

  LPTIM_CFGR_ETR_AFEN_Setable(DISABLE);//ETR�����˲�
  LPTIM_CFGR_PSCSEL_Set(LPTIM_CFGR_PSCSEL_LPTETRF);  //ʱ��Ԥ��Ƶ����ѡ��
  LPTIM_CFGR_DIVSEL_Set(LPTIM_CFGR_DIVSEL_DIV32);  //ʱ�ӷ�Ƶѡ��
  LPTIM_CFGR_ONST_Set(LPTIM_CFGR_ONST_CONTINUE); //������������ֹͣ
  LPTIM_CFGR_TMODE_Set(LPTIM_CFGR_TMODE_COUNTER);//��ͨ��ʱ��ģʽ

  LPTIM_ARR_Write(299999); 

  LPTIM_ISR_OVIF_Clr(); /* ����������жϱ�־λ */
  LPTIM_IER_OVIE_Setable(ENABLE);  /* �����������ж� */

  NVIC_DisableIRQ(LPTIM_IRQn);
  NVIC_SetPriority(LPTIM_IRQn,2);//�ж����ȼ�����
  NVIC_EnableIRQ(LPTIM_IRQn);

  LPTIM_CR_EN_Setable( ENABLE);   /* ʹ�ܼ�����: */    
}


void LPTIM_OutClkTrig(void) //Trigger���崥������  PA13 ��������
{
    CMU_PERCLK_SetableEx(PADCLK, ENABLE); //��������ʱ��ʹ��
    AltFunIO(GPIOA, GPIO_Pin_13, 0);//PA13���������⹦�ܿڣ���ͨ, LP32ETR

    CMU_PERCLK_SetableEx(LPTCLK, ENABLE); //��������ʱ��ʹ��
    CMU_OPCCR2_LPTCKS_Set(CMU_OPCCR2_LPTCKS_RCLP);//ѡ����ʱ��Դ
    CMU_OPCCR2_LPTCKE_Setable(ENABLE);     //����ʱ��Դʹ��

    LPTIM_CFGR_ETR_AFEN_Setable(ENABLE);//ETR�����˲�
    LPTIM_CFGR_PSCSEL_Set(LPTIM_CFGR_PSCSEL_CLKSEL);  //ʱ��ѡ��
    LPTIM_CFGR_DIVSEL_Set(LPTIM_CFGR_DIVSEL_DIV1);  //ʱ�ӷ�Ƶѡ��
    LPTIM_CFGR_TRIGCFG_Set(LPTIM_CFGR_TRIGCFG_RISING);//�ⲿ��������ѡ��
    LPTIM_CFGR_ONST_Set(LPTIM_CFGR_ONST_CONTINUE); //������������ֹͣ
    LPTIM_CFGR_TMODE_Set(LPTIM_CFGR_TMODE_PULSE);//��ͨ��ʱ��ģʽ

    LPTIM_ARR_Write(1999); 
    LPTIM_CR_EN_Setable( ENABLE);   /* ʹ�ܼ�����: */      

    LPTIM_ISR_OVIF_Clr(); /* ����������жϱ�־λ */
    LPTIM_IER_OVIE_Setable(ENABLE);  /* �����������ж� */

    NVIC_DisableIRQ(LPTIM_IRQn);
    NVIC_SetPriority(LPTIM_IRQn,2);//�ж����ȼ�����
    NVIC_EnableIRQ(LPTIM_IRQn);

    LPTIM_CR_EN_Setable( ENABLE);   /* ʹ�ܼ�����: */    
}


void LPTIM_OutClkCount(void) //�ⲿ�첽�������ģʽ PA13 ��������
{
    CMU_PERCLK_SetableEx(PADCLK, ENABLE); //��������ʱ��ʹ��
    AltFunIO(GPIOA, GPIO_Pin_13, 0);//PA13���������⹦�ܿڣ���ͨ, LP32ETR

    CMU_PERCLK_SetableEx(LPTCLK, ENABLE); //��������ʱ��ʹ��
    CMU_OPCCR2_LPTCKS_Set(CMU_OPCCR2_LPTCKS_APBCLK);//ѡ����ʱ��Դ
    CMU_OPCCR2_LPTCKE_Setable(ENABLE);     //����ʱ��Դʹ��

    LPTIM_CFGR_ETR_AFEN_Setable(ENABLE);//ETR�����˲�
    LPTIM_CFGR_PSCSEL_Set(LPTIM_CFGR_PSCSEL_LPTETRF);  //ʱ��ѡ��
    LPTIM_CFGR_DIVSEL_Set(LPTIM_CFGR_DIVSEL_DIV1);  //ʱ�ӷ�Ƶѡ��
    LPTIM_CFGR_ONST_Set(LPTIM_CFGR_ONST_CONTINUE); //������������ֹͣ
    LPTIM_CFGR_TMODE_Set(LPTIM_CFGR_TMODE_ASY);//�ⲿ�첽�������

    LPTIM_ARR_Write(199); 

    LPTIM_ISR_OVIF_Clr(); /* ����������жϱ�־λ */
    LPTIM_IER_OVIE_Setable(ENABLE);  /* �����������ж� */

    NVIC_DisableIRQ(LPTIM_IRQn);
    NVIC_SetPriority(LPTIM_IRQn,2);//�ж����ȼ�����
    NVIC_EnableIRQ(LPTIM_IRQn);
    LPTIM_CR_EN_Setable( ENABLE);   /* ʹ�ܼ�����: */    
}


void LPTIM_Timeout(void) //Timeoutģʽ PA13 ��������
{
    CMU_PERCLK_SetableEx(PADCLK, ENABLE); //��������ʱ��ʹ��
    AltFunIO(GPIOA, GPIO_Pin_13, 0);//PA13���������⹦�ܿڣ���ͨ, LP32ETR

    CMU_PERCLK_SetableEx(LPTCLK, ENABLE); //��������ʱ��ʹ��
    CMU_OPCCR2_LPTCKS_Set(CMU_OPCCR2_LPTCKS_APBCLK);//ѡ����ʱ��Դ
    CMU_OPCCR2_LPTCKE_Setable(ENABLE);     //����ʱ��Դʹ��

    LPTIM_CFGR_ETR_AFEN_Setable(ENABLE);//ETR�����˲�
    LPTIM_CFGR_PSCSEL_Set(LPTIM_CFGR_PSCSEL_CLKSEL);  //ʱ��ѡ��
    LPTIM_CFGR_DIVSEL_Set(LPTIM_CFGR_DIVSEL_DIV128);  //ʱ�ӷ�Ƶѡ��
    LPTIM_CFGR_ONST_Set(LPTIM_CFGR_ONST_CONTINUE); //������������ֹͣ
    LPTIM_CFGR_TMODE_Set(LPTIM_CFGR_TMODE_TIMEOUT);//�ⲿ�첽�������

    LPTIM_ARR_Write(399); //ʱ��ѡ��LSCLK 128��Ƶ arr=399  ���ʱ��Ϊ1.562s

    LPTIM_ISR_OVIF_Clr(); /* ����������жϱ�־λ */
    LPTIM_IER_OVIE_Setable(ENABLE);  /* �����������ж� */

    NVIC_DisableIRQ(LPTIM_IRQn);
    NVIC_SetPriority(LPTIM_IRQn,2);//�ж����ȼ�����
    NVIC_EnableIRQ(LPTIM_IRQn);

    LPTIM_CR_EN_Setable( ENABLE);   /* ʹ�ܼ�����: */    
}



void LPTIM_COUNTER_PLL_L(void) //ѡ��PLL_L��ΪLptimerʱ��Դ����ͨ��ʱ��ģʽ��1s��ʱ
{
    /* PLL_LĬ��ѡ��XTLF��Ϊʱ��Դ�� XTLF�ϵ�Ĭ�Ͽ������ȴ�XTLF���񣬴�Լ1s��PLL_L=16.384Mhz */
    CMU_PLLLCR_PLLDB_Set(499 << CMU_PLLLCR_PLLDB_Pos);
    CMU_PLLLCR_PLLEN_Setable(ENABLE);
    while(CMU_PLLLCR_LOCKED_Chk() == RESET);

    /* ѡ��PLL_L��ΪLptimerʱ��Դ */
    CMU_PERCLK_SetableEx(LPTCLK, ENABLE); //��������ʱ��ʹ��
    CMU_OPCCR2_LPTCKS_Set(CMU_OPCCR2_LPTCKS_PLL_L);
    CMU_OPCCR2_LPTCKE_Setable(ENABLE);


    LPTIM_CFGR_PSCSEL_Set(LPTIM_CFGR_PSCSEL_CLKSEL);  //ʱ��ѡ��
    LPTIM_CFGR_DIVSEL_Set(LPTIM_CFGR_DIVSEL_DIV1);  //ʱ�ӷ�Ƶѡ��
    LPTIM_CFGR_ONST_Set(LPTIM_CFGR_ONST_CONTINUE); //������������ֹͣ
    LPTIM_CFGR_TMODE_Set(LPTIM_CFGR_TMODE_COUNTER);//��ͨ��ʱ��ģʽ

    LPTIM_ARR_Write(16384000 - 1); 

    LPTIM_ISR_OVIF_Clr(); /* ����������жϱ�־λ */
    LPTIM_IER_OVIE_Setable(ENABLE);  /* �����������ж� */

    NVIC_DisableIRQ(LPTIM_IRQn);
    NVIC_SetPriority(LPTIM_IRQn,2);//�ж����ȼ�����
    NVIC_EnableIRQ(LPTIM_IRQn);

    LPTIM_CR_EN_Setable( ENABLE);   /* ʹ�ܼ�����: */    
}





//int main (void)
//{    
//    Init_System();                //ϵͳ��ʼ�� 

//    LPTIM_COUNTER();//��ͨ��ʱ��ģʽ 100us
////    LPTIM_OutClkTrig();//Trigger���崥������ PA13 ��������
////    LPTIM_OutClkCount();//�ⲿ�첽�������ģʽ PA13 ��������
////    LPTIM_Timeout();//Timeoutģʽ PA13 ��������
////    LPTIM_COUNTER_PLL_L();//ѡ��PLL_L��ΪLptimerʱ��Դ����ͨ��ʱ��ģʽ��1s��ʱ

//    while(1)
//    {
//        IWDT_Clr();
//        TicksDelayMs( 200, NULL );    
//    }
//}


