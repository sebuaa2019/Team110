#ifndef SAFETY_H_INCLUDED
#define SAFETY_H_INCLUDED
void modify_sensor_setting();

void turn_on_smoke_sensor();
void turn_off_smoke_sensor();
void turn_on_invade_sensor();
void turn_off_invade_sensor();

int detect_smoke();

int detect_invade();

#endif // SAFETY_H_INCLUDED
