
set(
	VGA_GPIO_INTERFACE
		"vga_gpio_interface.c"
)

idf_component_register(
	SRCS
		${VGA_GPIO_INTERFACE}
	INCLUDE_DIRS
		"."
	REQUIRES
		driver
)
