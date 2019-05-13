#ifndef SYS_SETTING_H_INCLUDED
#define SYS_SETTING_H_INCLUDED
#include "print_info.h"
#include "safety.h"
void init_sys(); //开启系统时的初始化
void change_code(); //修改密码
void write_new_code(); //把新密码存储下来

void init_sys(){
    if(access("code",0) == -1){ //密码文件还不存在，初始默认密码为123456
        FILE *code;
        code = fopen("code","w");
        fprintf(code,"123456");
        fclose(code);
    }
}

void change_code(){
    char former[10]; //当前密码
    char newcode[10]; //新密码
    printf("请输入当前密码\n");
    int limittime = 5; //最多输入五次
    int i = 0;
    while(i<5){
        printf("当前密码: ");
        scanf("%s",former);
        int check = check_pssword(former);
        if(check==1) {
            printf("密码正确！\n");
            write_new_code();
            break;
        }
        printf("密码错误，请重新输入\n");
        i++;
    }
}

void write_new_code(){
    char once[10];
    char twice[10];
    printf("请输入新密码：");
    scanf("%s",once);
    printf("确认新密码：");
    scanf("%s",twice);
    if(strcmp(once,twice) == 0){
        FILE *code;
        code = fopen("code","w");
        fprintf(code,once);
        fclose(code);
        printf("修改密码成功！\n");
    }
    else{
        printf("输入不一致，修改失败\n");
    }
}
void modify_sys(){
    printf("您已进入系统参数修改中心\n");
    int id;
    printf("请输入您需要的功能:(输入对应序号)\n");
    printf("1: 修改传感器参数\n");
    printf("2: 退出系统参数修改中心\n");
    scanf("%d",&id);
    switch(id)
    {
        case 1:{
            modify_sensor_setting();
            break;
        }
        case 2:{
            printf("您已退出系统参数修改中心\n");
            break;
        }

    }
}
#endif // SYS_SETTING_H_INCLUDED
