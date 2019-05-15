#ifndef SYS_SETTING_H_INCLUDED
#define SYS_SETTING_H_INCLUDED
#include "print_info.h"
#include "safety.h"

void init_sys(); //开启系统时的初始化
void change_code(); //修改密码
void write_new_code(); //把新密码存储下来
void modify_settings();//修改各项设置
void modify_delay();//修改报警间隔
void modify_phonenum();//修改报警电话


#endif // SYS_SETTING_H_INCLUDED
