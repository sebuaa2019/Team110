
#include <stdio.h>
#include <pthread.h>　
#include "controller.h"
#include "safety.h"

int arm_sys()
{
    int err;
    pthread_t ntid;

    if(sys_switch==0){
        printf("正在打开系统\n");
        err=pthread_create(&ntid,NULL,pthread_func,NULL);
        if(err!=0)
        {
            printf("创建线程失败\n");
            return 0;
        }
        else{
            printf("系统成功打开\n");
        }
        print_thread("主线程"); //打印主线程号
        sys_switch=1;
        return 1;
    }
    else{
        printf("系统已经打开，无需重复开启\n");
        return 1;
    }
    return 0;
}

void* pthread_func(void *arg) //系统运行线程函数
{
    int time=0;  //系统已运行的时间
    printf("系统正在运行中，可监视烟雾和入侵\n");
    print_thread("新线程");  //打印新建线程号
    for(;;){
        if(sys_switch==0){
             pthread_exit(0);
        }
        else{
            Sleep(5000);
            time+=5;
            printf("系统正在运行中，已启动%d秒(因为以五秒为一个单位，可能在关闭后还显示一次)\n",time);
            if(detect_invade()){

                printf("检测到入侵，报警\n");
            }
            if(detect_smoke()){
                printf("检测到烟雾，报警\n");
            }
        }
    }

    return NULL;
}

void print_thread(char *str) //输出线程号和进程号，便于测试
{
    pid_t pid; //进程标识符
    pthread_t tid; //线程标识符

    pid=getpid();   //获得进程号
    tid=pthread_self(); //获得线程号
    printf("%s的进程号:%u 线程号:%u\n",str,(unsigned int)pid,(unsigned int)tid); //打印进程号和线程号
}

int disarm_sys()//关闭系统
{
    if(sys_switch==1){
        printf("系统已成功关闭\n");
    }
    else{
        printf("系统未打开，无需关闭\n");
    }
    sys_switch=0;
    return 1;
}

int exit_sys()//退出系统
{
    printf("成功退出系统，期待您的下次使用\n");
    return 1;
}
