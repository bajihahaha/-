#include "lptimer32.h"

//void LPTIM_IRQHandler(void)
//{
//    /* enter interrupt */
//    rt_interrupt_enter();

//    if(LPTIM_IER_OVIE_Getable() && LPTIM_ISR_OVIF_Chk())
//    {
//        LPTIM_ISR_OVIF_Clr();
//    }
//    
//    /* leave interrupt */
//    rt_interrupt_leave();
//}


/**
 * This function get current count value of LPTIM
 *
 * @return the count vlaue
 */
rt_uint32_t fm33xx_lptimer_get_current_tick(void)
{
    if (LPTIM_ARR_Read())
    {
        return LPTIM_ARR_Read();
    }
    else
    {
        return LPTIM_ARR_Read();
    }
}

/**
 * This function get the max value that LPTIM can count
 *
 * @return the max count
 */
rt_uint32_t fm33xx_lptimer_get_tick_max(void)
{
    return (0xFFFFFFFF);
}

/**
 * This function start LPTIM with reload value
 *
 * @param reload The value that LPTIM count down from
 *
 * @return RT_EOK
 */
rt_err_t fm33xx_lptimer_start(rt_uint32_t reload)
{
    LPTIM_IER_OVIE_Setable(ENABLE);
    LPTIM_ARR_Write(reload); 
    LPTIM_CR_EN_Setable(ENABLE);

    return (RT_EOK);
}

/**
 * This function stop LPTIM
 */
void fm33xx_lptimer_stop(void)
{
    LPTIM_CR_EN_Setable(DISABLE);
    LPTIM_ISR_OVIF_Clr();
    LPTIM_IER_OVIE_Setable(DISABLE);
}

/**
 * This function get the count clock of LPTIM
 *
 * @return the count clock frequency in Hz
 */
rt_uint32_t fm33xx_lptimer_get_countfreq(void)
{
    return 32768;
}

/**
 * This function initialize the lptim
 */
int fm33xx_hw_lptimer_init(void)
{
    CMU_PERCLK_SetableEx(LPTCLK, ENABLE); 
    CMU_OPCCR2_LPTCKS_Set(CMU_OPCCR2_LPTCKS_LSCLK);
    CMU_OPCCR2_LPTCKE_Setable(ENABLE);	 

    LPTIM_CFGR_ETR_AFEN_Setable(DISABLE);
    LPTIM_CFGR_PSCSEL_Set(LPTIM_CFGR_PSCSEL_CLKSEL);  
    LPTIM_CFGR_DIVSEL_Set(LPTIM_CFGR_DIVSEL_DIV1);  
    LPTIM_CFGR_ONST_Set(LPTIM_CFGR_ONST_SINGLE); 
    LPTIM_CFGR_TMODE_Set(LPTIM_CFGR_TMODE_COUNTER);

    LPTIM_ARR_Write(32768); 

    LPTIM_ISR_OVIF_Clr(); /* 清除计数器中断标志位 */
    LPTIM_IER_OVIE_Setable(ENABLE);  /* 开启计数器中断 */

    NVIC_DisableIRQ(LPTIM_IRQn);
    NVIC_SetPriority(LPTIM_IRQn,2);//中断优先级配置
    NVIC_EnableIRQ(LPTIM_IRQn);

    LPTIM_CR_EN_Setable( ENABLE);   /* 使能计数器: */
    return 0;
}
