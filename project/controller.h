#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int sys_switch;
int arm_sys(); 
void* pthread_func(void *arg);
void print_thread(char *str); 
int disarm_sys(); 
int exit_sys(); 



#endif
