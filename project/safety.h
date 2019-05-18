#ifndef SAFETY_H_INCLUDED
#define SAFETY_H_INCLUDED
void modify_sensor_setting();


void turn_on_smoke_sensor();
void turn_off_smoke_sensor();
void turn_on_invade_sensor();
void turn_off_invade_sensor();

double get_smoke_concen();
void cancel_invade_by_owner();/* 房主回家，在指定时间内输入密码，取消入侵检测*/
int onMovement();
int onDoor();
int detect_smoke();

int detect_invade();

#endif // SAFETY_H_INCLUDED
