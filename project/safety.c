#include<stdio.h>
#include "safety.h"
#include "sys_setting.h"

int switch_smoke_sensor = 1;
int switch_invade_sensor = 1;
double smoke_thresh = 50.0;
int delay_invade_time_thresh = 0;


int cancel_invade = 0;

int onMovement(){
	return 0;
}

int onDoor(){
	return 0;
}

void modify_sensor_setting(){
    int id;
    printf("您已进入传感器参数修改中心\n");
    printf("请输入您需要的功能:(输入对应序号)\n");
    printf("1: 开启烟雾传感器\n");
    printf("2: 关闭烟雾传感器\n");
    printf("3: 开启红外传感器\n");
    printf("4: 关闭红外传感器\n");
    printf("5: 烟雾传感数据阈值设置\n");
    printf("6: 人体检测延迟时间设置\n");
    printf("7: 退出\n");
    scanf("%d",&id);
    switch(id)
    {
        case 1:{
            turn_on_smoke_sensor();
            break;
        }
        case 2:{
            turn_off_smoke_sensor();
            break;
        }
        case 3:{
            turn_on_invade_sensor();
            break;
        }
        case 4:{
            turn_off_invade_sensor();
            break;
        }
        case 5:{
            set_smoke_thresh();
            break;
        }
        case 6:{
            set_delay_invade();
        }
        default:{
            printf("您已退出传感器参数修改中心\n");
        }
    }
}
void double get_smoke_concen(){
    return 50;
}
void set_smoke_thresh(){
    double n;
    printf("原有烟雾浓度阈值为: %f\n请输入新设定阈值: ",smoke_thresh);
    while(1){
        scanf("%f",&n);
        if(n<=0){
            printf("您输入的值不合法，请重新输入: ");
        }
        else{
            smoke_thresh = n;
            printf("烟雾浓度阈值被成功修改为: %f\n",smoke_thresh);
            break;
        }
    }

}
void set_delay_invade(){
    int n;
    printf("原有入侵检测延迟时间为: %d\n请输入新设定延迟时间: ",delay_invade_time_thresh);
    while(1){
        scanf("%d",&n);
        if(n<=0){
            printf("您输入的值不合法，请重新输入: ");
        }
        else{
            delay_invade_time_thresh = n;
            printf("延迟时间被成功修改为: %d\n",delay_invade_time_thresh);
            break;
        }
    }
}
void turn_on_smoke_sensor(){
    switch_smoke_sensor = 1;
    printf("烟雾传感器成功开启\n");
}
void turn_off_smoke_sensor(){
    switch_smoke_sensor = 0;
    printf("烟雾传感器成功关闭\n");

}
void turn_on_invade_sensor(){
    switch_invade_sensor = 1;
    printf("红外传感器成功开启\n");
}
void turn_off_invade_sensor(){
    switch_invade_sensor = 0;
    printf("红外传感器成功关闭\n");
}
void cancel_invade_by_owner(){
    cancel_invade = 1;
    printf("房主回家，人体红外检测本次取消\n");
}
int detect_smoke(){
/*need basic sensor data to analyze*/
/*return 0 means no smoke*/
    double data = get_smoke_concen();
    if(switch_smoke_sensor){
        if(data >= smoke_thresh){
            return 1;
        }
        else {
            return 0;
        }

    }
    else return 0;

}

int delay_time = 0;
int detect_invade(){
    delay_time+=5;
    if(switch_invade_sensor){
        if(1){
            if(cancel_invade==0){
                if(delay_time>=delay_invade_time_thresh){ // 延迟检测时间，过长报警
                    delay_time = 0;
                    return 1;
                }
                delay_time = 0;
                return 0;

            }
            else {  //用户入门，取消检测
                cancel_invade = 0;//初始化，避免下一次也被取消
                delay_time = 0;
                return 0;
            }
        }
        else{
             return 0;
        }
    }
    else return 0;
}

