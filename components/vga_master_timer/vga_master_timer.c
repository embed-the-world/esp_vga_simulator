
#include <stdio.h>
#include "driver/gptimer.h"

#include "vga_master_timer.h"


gptimer_handle_t vga_master_timer = NULL;

gptimer_config_t timer_config =
{
	.clk_src = GPTIMER_CLK_SRC_APB,
	.direction = GPTIMER_COUNT_UP,
	.resolution_hz = (MASTER_TIMER_MHZ * 1000 * 1000),
};


extern void vga_master_timer_reset_counter (void)
{
	gptimer_set_raw_count(vga_master_timer, 0);
}

extern void vga_master_timer_start (void* param)
{
	gptimer_new_timer(&timer_config, &vga_master_timer);
	gptimer_enable(vga_master_timer);
	gptimer_start(vga_master_timer);
}

extern void vga_master_timer_test ()
{
	uint64_t count = 0;

	while(true)
	{
		gptimer_get_raw_count(vga_master_timer, &count);
		if ( (MASTER_TIMER_MHZ*1000*1000) <= count )
		{
			gptimer_set_raw_count(vga_master_timer, 0);
		}
	}
}

extern void vga_master_timer_stop (void* param)
{
	gptimer_stop(vga_master_timer);
	gptimer_disable(vga_master_timer);
	gptimer_del_timer(vga_master_timer);
}

