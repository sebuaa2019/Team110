#ifndef USER_MANAGEMENT_H_INCLUDED
#define USER_MANAGEMENT_H_INCLUDED

int user_information();

int change_user_file_path(char* new_path);
int open_file_for_read();
int open_file_for_write();
int close_file();

int save_name(char* name_to_save);
int save_address(char* address_to_save);
int save_user_phone(char* user_phone_to_save);
int save_alarm_phone(char* alarm_phone_to_save);
int change_line(int line,char* content);

char* query_name();
char* query_address();
char* query_user_phone();
char* query_alarm_phone();
int check_file();


#endif
