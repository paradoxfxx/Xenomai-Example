#include "task3.h"
#include <rtdk.h>

void task3func(void * cookie)
{
    rt_print_auto_init(1);
    rt_printf("task3func\n");
}
