
set(
	VGA_MASTER_TIMER_LIB_SOURCES
		"vga_master_timer.c"
)

idf_component_register(
	SRCS
		${VGA_MASTER_TIMER_LIB_SOURCES}
	INCLUDE_DIRS
		"."
	REQUIRES
		driver
)
