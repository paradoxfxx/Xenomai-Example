#include "task1.h"
#include <errno.h>  /* where the err code is defined */
#include <rtdk.h>/* where the rt_printf() is included */
#include <native/types.h>   /* where the RTIME is defined */
#include <native/task.h>

void task1func(void *cookie)
{
    while(1)
    {
        rt_print_auto_init(1);
        rt_printf("%s\n",cookie);
        RTIME time = 1e9;
        int ret = rt_task_sleep(time);
        if(ret)
        {
            switch(ret)
            {
            case -EINTR:
                rt_printf("rt_task_sleep is interupted by rt_task_unblock\n");
                break;
            case -EWOULDBLOCK:
                rt_printf("the system timer is inactive\n");
                break;
            case -EPERM:
                rt_printf("the contex can not sleep\n");
                break;
            default:
            break;
            }
        }
    }
    
}