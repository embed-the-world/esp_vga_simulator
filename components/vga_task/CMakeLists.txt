
set(
	VGA_TASK_LIB_SOURCES
		"vga_task.c"
)

idf_component_register(
	SRCS
		${VGA_TASK_LIB_SOURCES}
	INCLUDE_DIRS
		"."
	PRIV_REQUIRES
		vga_master_timer
)

