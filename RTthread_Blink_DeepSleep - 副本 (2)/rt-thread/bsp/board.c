/*
 * Copyright (c) 2006-2019, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2017-07-24     Tanek        the first version
 * 2018-11-12     Ernest Chen  modify copyright
 */
 
#include <stdint.h>
#include <rthw.h>
#include <rtthread.h>
#include "define_all.h" 
#include "user_init.h"
#include "uart.h"
#include "lptimer32.h"
#include "sleep.h"

char output[1024];

#define _SCB_BASE       (0xE000E010UL)
#define _SYSTICK_CTRL   (*(rt_uint32_t *)(_SCB_BASE + 0x0))
#define _SYSTICK_LOAD   (*(rt_uint32_t *)(_SCB_BASE + 0x4))
#define _SYSTICK_VAL    (*(rt_uint32_t *)(_SCB_BASE + 0x8))
#define _SYSTICK_CALIB  (*(rt_uint32_t *)(_SCB_BASE + 0xC))
#define _SYSTICK_PRI    (*(rt_uint8_t  *)(0xE000ED23UL))

// Updates the variable SystemCoreClock and must be called 
// whenever the core clock is changed during program execution.
extern void SystemCoreClockUpdate(void);

// Holds the system core clock, which is the system clock 
// frequency supplied to the SysTick timer and the processor 
// core clock.
extern uint32_t SystemCoreClock;

static uint32_t _SysTick_Config(rt_uint32_t ticks)
{
    if ((ticks - 1) > 0xFFFFFF)
    {
        return 1;
    }
    
    _SYSTICK_LOAD = ticks - 1; 
    _SYSTICK_PRI = 0xFF;
    _SYSTICK_VAL  = 0;
    _SYSTICK_CTRL = 0x07;  
    
    return 0;
}

#if defined(RT_USING_USER_MAIN) && defined(RT_USING_HEAP)
#define RT_HEAP_SIZE 1024
static uint32_t rt_heap[RT_HEAP_SIZE];     // heap default size: 4K(1024 * 4)
RT_WEAK void *rt_heap_begin_get(void)
{
    return rt_heap;
}

RT_WEAK void *rt_heap_end_get(void)
{
    return rt_heap + RT_HEAP_SIZE;
}
#endif

static void nothing(void)
{
	    //rt_schedule();
}

static void sleep(void)
{
   rt_tick_t timeout_tick, delta_tick; 
   rt_uint32_t ret, freq;
   static rt_uint32_t os_tick_remain = 0;
   
   /* ��ȡlptimer����ʱ��Ƶ�� */
   freq = fm33xx_lptimer_get_countfreq();
    
   timeout_tick = rt_timer_next_timeout_tick() - rt_tick_get();

   fm33xx_lptimer_start((freq - 1) * timeout_tick / RT_TICK_PER_SECOND);
   DeepSleep();
    
   rt_enter_critical();
   ret = fm33xx_lptimer_get_current_tick() + 1;

   delta_tick = (ret * RT_TICK_PER_SECOND + os_tick_remain) / freq;

   os_tick_remain += (ret * RT_TICK_PER_SECOND);
   os_tick_remain %= freq;
   rt_exit_critical();
   
   fm33xx_lptimer_stop();
   rt_tick_set(rt_tick_get() + delta_tick);
   {
       struct rt_thread *thread;
       thread = rt_thread_self();
       if(thread->remaining_tick <= delta_tick)
       {
           thread->remaining_tick = thread->init_tick;
           rt_thread_yield();
       }
       else
       {
           thread->remaining_tick -= delta_tick;
       }
       rt_timer_check();
   }
}
/**
 * This function will initial your board.
 */
void rt_hw_board_init()
{
    /* user init */
	Init_System();	
    /* System Clock Update */
    SystemCoreClockUpdate();
    /* SysTick configuration */
    SysTick_Config(SystemCoreClock / RT_TICK_PER_SECOND);
        /* lptimer init*/
    fm33xx_hw_lptimer_init();
    /* idle thread :sleep */
    rt_thread_idle_sethook(nothing);
    /* Call components board initial (use INIT_BOARD_EXPORT()) */
#ifdef RT_USING_COMPONENTS_INIT
    rt_components_board_init();
#endif

#if defined(RT_USING_USER_MAIN) && defined(RT_USING_HEAP)
    rt_system_heap_init(rt_heap_begin_get(), rt_heap_end_get());
#endif
}

void SysTick_Handler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();
		
    rt_tick_increase();
    /* leave interrupt */
    rt_interrupt_leave();
}
void rt_hw_console_output(const char *str)
{
//    rt_size_t i = 0, size = 0;

//    size = rt_strlen(str);
//    for (i = 0; i < size; i++)
//    {
//        if (*(str + i) == '\n')
//        {
//            UARTx_TXBUF_Write(UART0, 0X0D);		
//            //while(RESET == UARTx_ISR_TXSE_Chk(UART0));	
//		}
//        UARTx_TXBUF_Write(UART0, *(uint8_t *)(str + i));
//	    //while(RESET == UARTx_ISR_TXSE_Chk(UART0));	
//    }
    rt_size_t i = 0, size = 0;
    rt_size_t output_index = strlen(output); // �ӵ�ǰ�����ĩβ��ʼд��

    size = rt_strlen(str); // ��ȡ�����ַ����ĳ���

    // ���������ַ�����������������
    for (i = 0; i < size; i++)
    {
        // ��黺�����Ƿ�����
        if (output_index >= 1024- 1) // ��ֹ���
        {
            // �������������������ѡ����ջ���
            // ����ѡ��򵥵��������
            output_index = 0; // ��������
            output[output_index] = '\0'; // ������������
        }

        // �����з�
        if (*(str + i) == '\n')
        {
            output[output_index++] = '\r'; // ��ӻس���
        }
        
        // ����ַ������������
        output[output_index++] = *(str + i);
    }

    // ��ӽ�����
    output[output_index] = '\0'; // ȷ���ַ�����ȷ����


}

char rt_hw_console_getchar(void)
{
    int ch = -1;

    if(SET == UARTx_ISR_RXBF_Chk(UART0))		
    {
        ch = UARTx_RXBUF_Read(UART0);			
    }
    else
    {
        rt_thread_mdelay(10);
    }
    return ch;
}
