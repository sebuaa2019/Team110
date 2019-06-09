#include <stdio.h>
#include "controller.h"
#include "print_info.h"
#include "user_management.h"

char pssword[16];

void monitor_room(){}
void report_errs(){}


int main()
{
	FILE *code;
    int choose_id;
    int err;
    keyboard_init();
    init_sys(); 

	code = fopen("settings","w");
        	fprintf(code,"123456\n");
		fprintf(code,"20\n");
		fprintf(code,"13900000000\n");
		fprintf(code,"15\n");
		fprintf(code,"80\n");
		fprintf(code,"10\n");
        	fclose(code);
	
    login_info(pssword);
    choose_id = choose_func();
    while(1){
        switch(choose_id)
        {
        case 12: 
            open_close(pssword,0);    
            err=arm_sys();
            if(err!=1){
                printf("系统启动失败\n"); 
            }
            break;
        case 13:     
            open_close(pssword,1);
            err=disarm_sys();
            if(err!=1){
                printf("系统关闭失败\n");   
	    }
            break;
        case 1:    
            monitor_room();
            break;
        case 2:     
            report_errs();
            break;
        case 3:    
            modify_sensor_setting();
            break;
        case 4:
            modify_settings();
            break;
        case 5:
            err=user_information();
            if(err!=1){
                printf("进入用户细信息管理系统失败\n"); 
            }
            break;
        case 6:    
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
       	choose_id = keyboard_single();
    }
    return 0;
}
