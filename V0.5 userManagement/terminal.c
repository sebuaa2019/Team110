#include <stdio.h>
#include "controller.h"
#include "print_info.h"
#include "sys_setting.h"
#include "user_management.h"

char pssword[16];
//void arm_sys(){}
//void disarm_sys(){}
void monitor_room(){}
void report_errs(){}

//void exit_sys(){}

int main()
{
    int choose_id;
    int err;

    init_sys();

    login_info(pssword);
    choose_id = choose_func();
    while(1){
        switch(choose_id)
        {
        case 1:     //安装系统
            err=arm_sys();
            if(err!=1){
                printf("系统启动失败\n");   //报错，后面完善
            }
            break;
        case 2:     //解除系统
            err=disarm_sys();
            if(err!=1){
                printf("系统关闭失败\n");   //报错，后面完善
            }
            break;
        case 3:      //摄像头
            monitor_room();
            break;
        case 4:     //报告错误
            report_errs();
            break;
        case 5:     //重新配置传感器或系统
            modify_sys();
            break;
        case 6:
            change_code();
            break;
        case 7:
            err=user_information();
            if(err!=1){
                printf("进入用户细信息管理系统失败\n");   //报错，后面完善
            }
            break;
        case 8:     //退出系统
            err=exit_sys();
            if(err!=1){
                printf("系统关闭失败\n");   //报错，后面完善
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
