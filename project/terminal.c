#include <stdio.h>
#include "controller.h"
#include "print_info.h"
#include "user_management.h"

char pssword[16];

void monitor_room(){}
void report_errs(){}
void modify_sys(){}
void modify_settings(){}


int main()
{
    int choose_id;
    int err;


    login_info(pssword);
    choose_id = choose_func();
    while(1){
        switch(choose_id)
        {
        case 1:     
            err=arm_sys();
            if(err!=1){
                printf("系统启动失败\n"); 
            }
            break;
        case 2:     
            err=disarm_sys();
            if(err!=1){
                printf("系统关闭失败\n");   
	    }
            break;
        case 3:    
            monitor_room();
            break;
        case 4:     
            report_errs();
            break;
        case 5:    
            modify_sys();
            break;
        case 6:
            modify_settings();
            break;
        case 7:
            err=user_information();
            if(err!=1){
                printf("进入用户细信息管理系统失败\n"); 
            }
            break;
        case 8:    
            err=exit_sys();
            if(err!=1){
                printf("系统关闭失败\n");   
            }
            else{
                return 0;
            }
            break;
        }

        printf("请继续您的操作(输入序号)\n");
        scanf("%d",&choose_id);
    }
    return 0;
}