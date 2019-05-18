#ifndef SYS_SETTING_H_INCLUDED
#define SYS_SETTING_H_INCLUDED
#include "print_info.h"
#include "safety.h"

int code_delay; /*感应到人以后留给用户输密码的时间*/
int start_delay;
int smoke_limit; /*烟雾浓度报警上限*/

void init_sys(); /*开启系统时的初始化*/
void change_code(); /*修改密码*/
void write_new_code(); /*把新密码存储下来*/
void modify_settings();/*修改各项设置*/
void modify_delay();/*修改报警间隔*/
void modify_phonenum();/*修改报警电话*/
void modify_codedelay(); /*修改留给主人输密码的时间长度*/
void modify_smokelimit(); /*修改烟雾浓度阈值*/
void modify_startdelay(); /*修改开启系统时延*/

#endif // SYS_SETTING_H_INCLUDED
