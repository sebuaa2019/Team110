#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <loglib.h>
#include <stddef.h>
#include <time.h>
#include <tasklib.h>
#include "controller.h"
#include "safety.h"
#include "sys_setting.h"
int task;
int task_open=0;
int task_time=0;

int arm_sys()
{
    int err;
    int count_down;

    if(sys_switch==0){
        printf("正在打开系统\n");
	count_down=start_delay;
     	while(count_down>0){
		printf("还有%d秒开启系统\n",count_down);
		taskDelay(60);
		count_down-=1;
	}
	if(task_open==0){
		task=taskSpawn("task1",200,0,1000,(FUNCPTR)pthread_func,0,0,0,0,0,0,0,0,0,0);
		if(task == ERROR)
        	{
            		printf("创建线程失败\n");
            		return 0;
        	}
        	else{
			SetLed(1,1); /*  redled */
			task_open=1;
            		printf("系统成功打开\n");
        	}
	}
	else{
		SetLed(1,1); /*  redled */
		printf("系统成功打开\n");
	}
	SetLed(1,1); /*  redled */
        sys_switch=1;
	task_time=0;
        return 1;
    }
    else{
        printf("系统已经打开，无需重复开启\n");
        return 1;
    }
    return 0;
}

void* pthread_func(void *arg)
{
	int count;
    printf("系统正在运行中，可监视烟雾和入侵\n");
    for(;;){
        taskDelay(20);
        if(sys_switch==1){
            task_time+=5;
            /*printf("系统正在运行中，已启动%d秒\n",task_time);*/
            if(OnFire(0) > smoke_limit){
                react(0,0);
            }
            if(OnFire(1) > smoke_limit){
                react(0,1);
            }
            if(OnMovement(0) == 1){
                react(2,0);
            }
            if(OnMovement(1) == 1){
                react(2,1);
            }
            if(Ondoor(0) == 1){
		count=code_delay;
		while(count>0){
			taskDelay(60);
			if(OnMovement(0) == 1){
                		react(2,0);
				count=0;
            		}
           		 if(OnMovement(1) == 1){
                		react(2,1);
				count=0;
            		}
			count--;
		}
                judge_offence(sys_switch,0);
                
            }
            if(Ondoor(1)==1){
		count=code_delay;
		while(count>0){
			taskDelay(60);
			if(OnMovement(0) == 1){
                		react(2,0);
				count=0;
            		}
           		 if(OnMovement(1) == 1){
                		react(2,1);
				count=0;
            		}
			count--;
		}
                judge_offence(sys_switch,1);
       
            }
            if(OnWater(0) == 1){
                react(3,0);
            }
            if(OnWater(1) == 1){
                react(3,1);
            }
            

        }
    }

    return NULL;
}

int disarm_sys()
{
    if(sys_switch==1){
        sys_switch=0;
	SetLed(1,0);
        printf("系统已成功关闭\n");
    }
    else{
        printf("系统未打开，无需关闭\n");
    }
    return 1;
}

int exit_sys()
{
    printf("成功退出系统，期待您的下次使用\n");
    return 1;
}
