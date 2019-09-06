#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>
#include "key.h"
#include "led_alert.h"

#define KEY1_PIN	GET_PIN(A,0)

/* �����жϻص����� */
void key_callback(void *args)
{
		if(rt_pin_read(KEY1_PIN)==1)
		{
				rt_kprintf("press\nmsh >");
				rt_pin_write(LED1_PIN, PIN_LOW);
		}
		else if(rt_pin_read(KEY1_PIN)==0)
		{
				rt_kprintf("up\nmsh >");
				rt_pin_write(LED1_PIN, PIN_HIGH);
		}
}
/* ������ʼ�� */
void key_init(void)
{
		/* ��������Ϊ����ģʽ */
		rt_pin_mode(KEY1_PIN, PIN_MODE_INPUT_PULLDOWN);
}
/* �������Ժ��� */
static int key_sample(void)
{
		/* �������ų�ʼ�� */
		key_init();
		/* ���жϣ����ش���ģʽ���ص�������Ϊkey_callback */
		rt_pin_attach_irq(KEY1_PIN, PIN_IRQ_MODE_RISING_FALLING, key_callback, RT_NULL);
		/* ʹ���ж� */
		rt_pin_irq_enable(KEY1_PIN, PIN_IRQ_ENABLE);
}
MSH_CMD_EXPORT(key_sample, key press sample);


