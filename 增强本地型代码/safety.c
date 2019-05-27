#include<stdio.h>
#include "safety.h"
#include "sys_setting.h"

int switch_smoke_sensor = 1;
int switch_invade_sensor = 1;
int switch_tem_sensor=1;

double get_smoke_concen(){
    return 50;
}

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
    printf("5: 退出\n");

    /*scanf("%d",&id);*/
    id = keyboard_single();

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
        default:{
            printf("您已退出传感器参数修改中心\n");
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

int detect_smoke(){
/*need basic sensor data to analyze*/
/*return 0 means no smoke*/
    if(switch_smoke_sensor){
        if(OnSmooke(0)>=smoke_limit){
            return 1;
        }
        if(OnSmooke(1)>=smoke_limit){
            return 2;
        }
    }
    else return 0;
    return 0;
}

int detect_water(){

    if(switch_smoke_sensor){
        if(OnWater(0)){
            return 1;
        }
        if(OnWater(1)){
            return 2;
        }
    }
    else return 0;
    return 0;
}

int detect_invade(){
    if(switch_invade_sensor){
        if(OnMovement(0)){
            return 1;
        }
        if(OnMovement(1)){
            return 2;
        }
        if(Ondoor(0)){
            return 3;
        }
        if(Ondoor(1)){
            return 4;
        }
    }
    else return 0;
    return 0;
}

int detect_tem(){
    if(switch_tem_sensor){
        if(OnFire(0)>tem_limit) return 1;
        if(OnFire(1)>tem_limit) return 2;
    }
    else return 0;
    return 0;
}
