#ifndef __PM25_H__
#define __PM25_H__

#include <board.h>

struct pms5003_data_type
{
		float pm1_val;
		float pm10_val;
		float pm25_val;
};

/* ���ڽ�����Ϣ�ṹ*/
struct rx_msg
{
    rt_device_t dev;
    rt_size_t size;
};
/* ��Ϣ���п��ƿ� */
static struct rt_messagequeue rx_mq;


#endif

