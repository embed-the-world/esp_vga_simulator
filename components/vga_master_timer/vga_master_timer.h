#ifndef VGA_MASTER_TIMER_H
#define VGA_MASTER_TIMER_H


#define MASTER_TIMER_MHZ (40)


extern void vga_master_timer_start (void* param);
extern void vga_master_timer_stop ();
extern void vga_master_timer_test ();
extern void vga_master_timer_reset_counter (void);


#endif /* VGA_MASTER_TIMER_H */
