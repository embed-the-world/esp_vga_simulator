
set(
	VGA_LOGIC_SOURCES
		"vga_logic.c"
)

idf_component_register(
	SRCS
		${VGA_GPIO_INTERFACE}
	INCLUDE_DIRS
		"."
	PRIV_REQUIRES
		vga_gpio_interface
		vga_master_timer
		vga_task
)
