
#include "driver/gpio.h"
#include "soc/gpio_struct.h"
#include "vga_gpio_interface.h"


#define RGB_PIN_RED_0 (GPIO_NUM_13)
#define RGB_PIN_RED_1 (GPIO_NUM_12)
#define RGB_PIN_RED_2 (GPIO_NUM_14)
#define RGB_PIN_RED_3 (GPIO_NUM_27)
#define RGB_PIN_RED_4 (GPIO_NUM_26)
#define RGB_PIN_RED_5 (GPIO_NUM_25)
#define RGB_PIN_RED_6 (GPIO_NUM_33)
#define RGB_PIN_RED_7 (GPIO_NUM_32)


static uint32_t value_set_register_0 = 0;
static uint32_t value_set_register_1 = 0;
static uint32_t value_clear_register_0 = 0;
static uint32_t value_clear_register_1 = 0;


static void prepare_single_pin (int pin_value, int pin_no, int new_decimal);
static void mark_pin_for_setting (int pin_no);
static void mark_pin_for_clearing (int pin_no);
static void update_output (void);


void vga_gpio_interface_setup (void)
{
	gpio_reset_pin(RGB_PIN_RED_0);
	gpio_reset_pin(RGB_PIN_RED_1);
	gpio_reset_pin(RGB_PIN_RED_2);
	gpio_reset_pin(RGB_PIN_RED_3);
	gpio_reset_pin(RGB_PIN_RED_4);
	gpio_reset_pin(RGB_PIN_RED_5);
	gpio_reset_pin(RGB_PIN_RED_6);
	gpio_reset_pin(RGB_PIN_RED_7);

	gpio_set_direction(RGB_PIN_RED_0, GPIO_MODE_OUTPUT);
	gpio_set_direction(RGB_PIN_RED_1, GPIO_MODE_OUTPUT);
	gpio_set_direction(RGB_PIN_RED_2, GPIO_MODE_OUTPUT);
	gpio_set_direction(RGB_PIN_RED_3, GPIO_MODE_OUTPUT);
	gpio_set_direction(RGB_PIN_RED_4, GPIO_MODE_OUTPUT);
	gpio_set_direction(RGB_PIN_RED_5, GPIO_MODE_OUTPUT);
	gpio_set_direction(RGB_PIN_RED_6, GPIO_MODE_OUTPUT);
	gpio_set_direction(RGB_PIN_RED_7, GPIO_MODE_OUTPUT);
}

extern void vga_gpio_interface_set_red_value (int red_value_absolute)
{
	prepare_single_pin(0, RGB_PIN_RED_0, red_value_absolute);
	prepare_single_pin(1, RGB_PIN_RED_1, red_value_absolute);
	prepare_single_pin(2, RGB_PIN_RED_2, red_value_absolute);
	prepare_single_pin(3, RGB_PIN_RED_3, red_value_absolute);
	prepare_single_pin(4, RGB_PIN_RED_4, red_value_absolute);
	prepare_single_pin(5, RGB_PIN_RED_5, red_value_absolute);
	prepare_single_pin(6, RGB_PIN_RED_6, red_value_absolute);
	prepare_single_pin(7, RGB_PIN_RED_7, red_value_absolute);

	update_output();
}

/****************************************************/

void prepare_single_pin (int pin_value, int pin_no, int new_decimal)
{
	if( (1 << pin_value) & new_decimal )
	{
		mark_pin_for_setting(pin_no);
	}
	else
	{
		mark_pin_for_clearing(pin_no);
	}
}

void mark_pin_for_setting (int pin_no)
{
	if(pin_no < 32)
	{
		value_set_register_0 |= (1 << (pin_no));
	}
	else
	{
		value_set_register_1 |= (1 << (pin_no - 32));
	}
}

void mark_pin_for_clearing (int pin_no)
{
	if(pin_no < 32)
	{
		value_clear_register_0 |= (1 << (pin_no));
	}
	else
	{
		value_clear_register_1 |= (1 << (pin_no - 32));
	}
}

static void update_output (void)
{
	GPIO.out_w1ts  = value_set_register_0;
	GPIO.out1_w1ts.val = value_set_register_1;
	GPIO.out_w1tc  = value_clear_register_0;
	GPIO.out1_w1tc.val = value_clear_register_1;
}

