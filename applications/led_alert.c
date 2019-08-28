#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>
#include "led_alert.h"

/* led���ų�ʼ�� */
void led_init(uint32_t pin)
{
		rt_pin_mode(pin, PIN_MODE_OUTPUT);
}
/* ����led */
void led_on(uint32_t pin)
{
		rt_pin_write(pin, PIN_LOW);
}
/* �ر�led */
void led_off(uint32_t pin)
{
		rt_pin_write(pin, PIN_HIGH);
}
/* le��˸ */
void led_blink(uint32_t pin)
{
			led_on(pin);
			rt_thread_delay(100);
			led_off(pin);
			rt_thread_delay(100);
}
//MSH_CMD_EXPORT(led_blink, led blink sample);
