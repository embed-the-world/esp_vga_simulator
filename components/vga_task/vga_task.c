
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include "vga_master_timer.h"


TaskHandle_t vga_task_handle = NULL;


extern void start_tasking (void)
{
	xTaskCreate(master_timer_start, "my vga task", 4096, NULL, (configMAX_PRIORITIES-1), &vga_task_handle);

	return;
}

