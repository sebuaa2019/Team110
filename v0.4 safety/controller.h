#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int sys_switch;
int arm_sys(); //打开系统
void* pthread_func(void *arg); //线程函数
void print_thread(char *str);  //输出线程号和进程号
int disarm_sys(); //关闭系统
int exit_sys(); //退出系统



#endif // CONTROLLER_H_INCLUDED
