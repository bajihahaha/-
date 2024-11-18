#ifndef __LPTIMER32_H__
#define __LPTIMER32_H__

#include "define_all.h"  

#include <rtthread.h>

rt_uint32_t fm33xx_lptimer_get_countfreq(void);
rt_uint32_t fm33xx_lptimer_get_tick_max(void);
rt_uint32_t fm33xx_lptimer_get_current_tick(void);

rt_err_t fm33xx_lptimer_start(rt_uint32_t load);
void fm33xx_lptimer_stop(void);
int fm33xx_hw_lptimer_init(void);

#endif
