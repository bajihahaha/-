#include "define_all.h"  
#include "lptim.h"

void LPTIM_COUNTER_5Min(void) //定时5分钟
{
  CMU_PERCLK_SetableEx(LPTCLK, ENABLE); //外设总线时钟使能
  CMU_OPCCR2_LPTCKS_Set(CMU_OPCCR2_LPTCKS_RCLP);//选择工作时钟源
  CMU_OPCCR2_LPTCKE_Setable(ENABLE);     //工作时钟源使能

  LPTIM_CFGR_ETR_AFEN_Setable(DISABLE);//ETR输入滤波
  LPTIM_CFGR_PSCSEL_Set(LPTIM_CFGR_PSCSEL_LPTETRF);  //时钟预分频输入选择
  LPTIM_CFGR_DIVSEL_Set(LPTIM_CFGR_DIVSEL_DIV32);  //时钟分频选择
  LPTIM_CFGR_ONST_Set(LPTIM_CFGR_ONST_CONTINUE); //发生计数器不停止
  LPTIM_CFGR_TMODE_Set(LPTIM_CFGR_TMODE_COUNTER);//普通定时器模式

  LPTIM_ARR_Write(299999); 

  LPTIM_ISR_OVIF_Clr(); /* 清除计数器中断标志位 */
  LPTIM_IER_OVIE_Setable(ENABLE);  /* 开启计数器中断 */

  NVIC_DisableIRQ(LPTIM_IRQn);
  NVIC_SetPriority(LPTIM_IRQn,2);//中断优先级配置
  NVIC_EnableIRQ(LPTIM_IRQn);

  LPTIM_CR_EN_Setable( ENABLE);   /* 使能计数器: */    
}


void LPTIM_OutClkTrig(void) //Trigger脉冲触发计数  PA13 输入脉冲
{
    CMU_PERCLK_SetableEx(PADCLK, ENABLE); //外设总线时钟使能
    AltFunIO(GPIOA, GPIO_Pin_13, 0);//PA13，数字特殊功能口，普通, LP32ETR

    CMU_PERCLK_SetableEx(LPTCLK, ENABLE); //外设总线时钟使能
    CMU_OPCCR2_LPTCKS_Set(CMU_OPCCR2_LPTCKS_RCLP);//选择工作时钟源
    CMU_OPCCR2_LPTCKE_Setable(ENABLE);     //工作时钟源使能

    LPTIM_CFGR_ETR_AFEN_Setable(ENABLE);//ETR输入滤波
    LPTIM_CFGR_PSCSEL_Set(LPTIM_CFGR_PSCSEL_CLKSEL);  //时钟选择
    LPTIM_CFGR_DIVSEL_Set(LPTIM_CFGR_DIVSEL_DIV1);  //时钟分频选择
    LPTIM_CFGR_TRIGCFG_Set(LPTIM_CFGR_TRIGCFG_RISING);//外部触发边沿选择
    LPTIM_CFGR_ONST_Set(LPTIM_CFGR_ONST_CONTINUE); //发生计数器不停止
    LPTIM_CFGR_TMODE_Set(LPTIM_CFGR_TMODE_PULSE);//普通定时器模式

    LPTIM_ARR_Write(1999); 
    LPTIM_CR_EN_Setable( ENABLE);   /* 使能计数器: */      

    LPTIM_ISR_OVIF_Clr(); /* 清除计数器中断标志位 */
    LPTIM_IER_OVIE_Setable(ENABLE);  /* 开启计数器中断 */

    NVIC_DisableIRQ(LPTIM_IRQn);
    NVIC_SetPriority(LPTIM_IRQn,2);//中断优先级配置
    NVIC_EnableIRQ(LPTIM_IRQn);

    LPTIM_CR_EN_Setable( ENABLE);   /* 使能计数器: */    
}


void LPTIM_OutClkCount(void) //外部异步脉冲计数模式 PA13 输入脉冲
{
    CMU_PERCLK_SetableEx(PADCLK, ENABLE); //外设总线时钟使能
    AltFunIO(GPIOA, GPIO_Pin_13, 0);//PA13，数字特殊功能口，普通, LP32ETR

    CMU_PERCLK_SetableEx(LPTCLK, ENABLE); //外设总线时钟使能
    CMU_OPCCR2_LPTCKS_Set(CMU_OPCCR2_LPTCKS_APBCLK);//选择工作时钟源
    CMU_OPCCR2_LPTCKE_Setable(ENABLE);     //工作时钟源使能

    LPTIM_CFGR_ETR_AFEN_Setable(ENABLE);//ETR输入滤波
    LPTIM_CFGR_PSCSEL_Set(LPTIM_CFGR_PSCSEL_LPTETRF);  //时钟选择
    LPTIM_CFGR_DIVSEL_Set(LPTIM_CFGR_DIVSEL_DIV1);  //时钟分频选择
    LPTIM_CFGR_ONST_Set(LPTIM_CFGR_ONST_CONTINUE); //发生计数器不停止
    LPTIM_CFGR_TMODE_Set(LPTIM_CFGR_TMODE_ASY);//外部异步脉冲计数

    LPTIM_ARR_Write(199); 

    LPTIM_ISR_OVIF_Clr(); /* 清除计数器中断标志位 */
    LPTIM_IER_OVIE_Setable(ENABLE);  /* 开启计数器中断 */

    NVIC_DisableIRQ(LPTIM_IRQn);
    NVIC_SetPriority(LPTIM_IRQn,2);//中断优先级配置
    NVIC_EnableIRQ(LPTIM_IRQn);
    LPTIM_CR_EN_Setable( ENABLE);   /* 使能计数器: */    
}


void LPTIM_Timeout(void) //Timeout模式 PA13 触发计数
{
    CMU_PERCLK_SetableEx(PADCLK, ENABLE); //外设总线时钟使能
    AltFunIO(GPIOA, GPIO_Pin_13, 0);//PA13，数字特殊功能口，普通, LP32ETR

    CMU_PERCLK_SetableEx(LPTCLK, ENABLE); //外设总线时钟使能
    CMU_OPCCR2_LPTCKS_Set(CMU_OPCCR2_LPTCKS_APBCLK);//选择工作时钟源
    CMU_OPCCR2_LPTCKE_Setable(ENABLE);     //工作时钟源使能

    LPTIM_CFGR_ETR_AFEN_Setable(ENABLE);//ETR输入滤波
    LPTIM_CFGR_PSCSEL_Set(LPTIM_CFGR_PSCSEL_CLKSEL);  //时钟选择
    LPTIM_CFGR_DIVSEL_Set(LPTIM_CFGR_DIVSEL_DIV128);  //时钟分频选择
    LPTIM_CFGR_ONST_Set(LPTIM_CFGR_ONST_CONTINUE); //发生计数器不停止
    LPTIM_CFGR_TMODE_Set(LPTIM_CFGR_TMODE_TIMEOUT);//外部异步脉冲计数

    LPTIM_ARR_Write(399); //时钟选择LSCLK 128分频 arr=399  溢出时间为1.562s

    LPTIM_ISR_OVIF_Clr(); /* 清除计数器中断标志位 */
    LPTIM_IER_OVIE_Setable(ENABLE);  /* 开启计数器中断 */

    NVIC_DisableIRQ(LPTIM_IRQn);
    NVIC_SetPriority(LPTIM_IRQn,2);//中断优先级配置
    NVIC_EnableIRQ(LPTIM_IRQn);

    LPTIM_CR_EN_Setable( ENABLE);   /* 使能计数器: */    
}



void LPTIM_COUNTER_PLL_L(void) //选择PLL_L作为Lptimer时钟源，普通定时器模式，1s定时
{
    /* PLL_L默认选择XTLF作为时钟源， XTLF上电默认开启，等待XTLF起振，大约1s，PLL_L=16.384Mhz */
    CMU_PLLLCR_PLLDB_Set(499 << CMU_PLLLCR_PLLDB_Pos);
    CMU_PLLLCR_PLLEN_Setable(ENABLE);
    while(CMU_PLLLCR_LOCKED_Chk() == RESET);

    /* 选择PLL_L作为Lptimer时钟源 */
    CMU_PERCLK_SetableEx(LPTCLK, ENABLE); //外设总线时钟使能
    CMU_OPCCR2_LPTCKS_Set(CMU_OPCCR2_LPTCKS_PLL_L);
    CMU_OPCCR2_LPTCKE_Setable(ENABLE);


    LPTIM_CFGR_PSCSEL_Set(LPTIM_CFGR_PSCSEL_CLKSEL);  //时钟选择
    LPTIM_CFGR_DIVSEL_Set(LPTIM_CFGR_DIVSEL_DIV1);  //时钟分频选择
    LPTIM_CFGR_ONST_Set(LPTIM_CFGR_ONST_CONTINUE); //发生计数器不停止
    LPTIM_CFGR_TMODE_Set(LPTIM_CFGR_TMODE_COUNTER);//普通定时器模式

    LPTIM_ARR_Write(16384000 - 1); 

    LPTIM_ISR_OVIF_Clr(); /* 清除计数器中断标志位 */
    LPTIM_IER_OVIE_Setable(ENABLE);  /* 开启计数器中断 */

    NVIC_DisableIRQ(LPTIM_IRQn);
    NVIC_SetPriority(LPTIM_IRQn,2);//中断优先级配置
    NVIC_EnableIRQ(LPTIM_IRQn);

    LPTIM_CR_EN_Setable( ENABLE);   /* 使能计数器: */    
}





//int main (void)
//{    
//    Init_System();                //系统初始化 

//    LPTIM_COUNTER();//普通定时器模式 100us
////    LPTIM_OutClkTrig();//Trigger脉冲触发计数 PA13 输入脉冲
////    LPTIM_OutClkCount();//外部异步脉冲计数模式 PA13 输入脉冲
////    LPTIM_Timeout();//Timeout模式 PA13 触发计数
////    LPTIM_COUNTER_PLL_L();//选择PLL_L作为Lptimer时钟源，普通定时器模式，1s定时

//    while(1)
//    {
//        IWDT_Clr();
//        TicksDelayMs( 200, NULL );    
//    }
//}


