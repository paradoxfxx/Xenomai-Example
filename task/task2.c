
#include <native/task.h>
#include <rtdk.h>
#include <native/types.h> 
#include "task2.h"

void task2func(void *cookie)
{
    int j = 0;
    int * ptr = cookie;
    rt_print_auto_init(1);
    rt_printf("task2func\n");
    RT_TASK task1;
    switch(rt_task_bind(&task1,"task1",TM_INFINITE))
    {
    case 0:
        rt_printf("rt_task_bind succeed!\n");
        break;
    default:
        rt_printf("rt_task_bind failed!\n");
        break;
    }
    while(1)
    {
        j++;
        if(5 == j)
        {
            switch(rt_task_delete(&task1))
            {
            case 0:
                rt_printf("task1 is deleted\n");
                break;
            default:
                rt_printf("task1 can not be deleted\n");
                break;
            }

            
        }
            rt_task_delete(&task1);
        // rt_print_auto_init(1);
        int i;
        for(i=0; i<7; i++)
            rt_printf("%d\t", ptr[i]);
        rt_printf("\n");
        // rt_printf("%s\n",cookie);
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