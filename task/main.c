#include <stdio.h>
#include <native/task.h> /* where the rt_task_creat is included */
#include "task1.h"
#include "task2.h"
#include "task3.h"
// #include <unistd.h>
int main()
{
    RT_TASK task1;
    RT_TASK task2;
    RT_TASK task3;
    char*cookie = "12 20 30";
    int a1[6] = {1,2,3,4,5,6};
    switch(rt_task_spawn(&task1, "task1", 0, 99, T_FPU|T_CPU(0), task1func, cookie))
    {
    case 0:
        printf("task1 spawn succeed\n");
        break;
    case -ENOMEM:
        printf("no memory\n");
        break;
    case -EEXIST:
        printf("name is already exist\n");
        break;
    case -EPERM:
        printf("spawn is not permitted\n");
        break;
    default:
        break;
    }
    rt_task_spawn(&task2, "task2", 0, 90, T_FPU|T_CPU(0), task2func, a1);
    rt_task_spawn(&task3, "task3", 0, 90, T_FPU, task3func, NULL);
    sleep(20);
    int err = rt_task_delete(&task3);
    if(err < 0)
    {
        fprintf(stderr, "Failed to delete task3: %s\n", strerror(-err));
    }
    switch(rt_task_delete(&task3))
    {
    case 0:
        printf("task3 is deleted\n");
        break;
    case -EINVAL:
        printf("task3 is invaliad\n");
        break;
    case -EPERM:
        printf("rt_task_delete is not permitted\n");
        break;
    case -EINTR:
        printf(" rt_task_unblock() has been invoked for the caller\n");
        break;
    case -EIDRM:
        printf("task is a deleted task descriptor\n");
    default:
        break;
    }
    sleep(5);
    rt_task_delete(&task1);
    sleep(5);
    rt_task_delete(&task2);
    sleep(5);
    printf("all task is deleted\n");
    return 0;
}