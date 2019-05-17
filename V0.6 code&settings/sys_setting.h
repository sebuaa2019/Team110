#ifndef SYS_SETTING_H_INCLUDED
#define SYS_SETTING_H_INCLUDED
#include "print_info.h"
#include "safety.h"
void init_sys(); //����ϵͳʱ�ĳ�ʼ��
void change_code(); //�޸�����
void write_new_code(); //��������洢����
void modify_settings();//�޸ĸ�������
void modify_delay();//�޸ı������
void modify_phonenum();//�޸ı����绰

void init_sys(){
    if(access("settings",0) == -1){ //�����ļ��������ڣ���ʼĬ������Ϊ123456
        FILE *code;
        code = fopen("settings","w");
        fprintf(code,"123456");
        fclose(code);
    }
}

void modify_settings(){
    int choice;
    printf("��ѡ��Ҫ�޸ĵ���Ŀ\n");
    printf("1: �޸�����\n");
    printf("2: �޸Ĳ��ż��\n");
    printf("3: �޸ı����绰\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            change_code();
            break;
        case 2:
            modify_delay();
            break;
        case 3:
            modify_phonenum();
            break;
    }
}

void change_code(){
    char former[10]; //��ǰ����
    char newcode[10]; //������
    printf("�����뵱ǰ����\n");
    int limittime = 5; //����������
    int i = 0;
    while(i<5){
        printf("��ǰ����: ");
        scanf("%s",former);
        int check = check_pssword(former);
        if(check==1) {
            printf("������ȷ��\n");
            write_new_code();
            break;
        }
        printf("�����������������\n");
        i++;
    }
}

void write_new_code(){
    char once[10];
    char twice[10];
    printf("�����������룺");
    scanf("%s",once);
    printf("ȷ�������룺");
    scanf("%s",twice);
    if(strcmp(once,twice) == 0){
        FILE *code;
        code = fopen("settings","w");
        fprintf(code,once);
        fclose(code);
        printf("�޸�����ɹ���\n");
    }
    else{
        printf("���벻һ�£��޸�ʧ��\n");
    }
}

void modify_delay(){

}

void modify_phonenum(){

}

void modify_sys(){
    printf("���ѽ���ϵͳ�����޸�����\n");
    int id;
    printf("����������Ҫ�Ĺ���:(�����Ӧ���)\n");
    printf("1: �޸Ĵ���������\n");
    printf("2: �˳�ϵͳ�����޸�����\n");
    scanf("%d",&id);
    switch(id)
    {
        case 1:{
            modify_sensor_setting();
            break;
        }
        case 2:{
            printf("�����˳�ϵͳ�����޸�����\n");
            break;
        }

    }
}
#endif // SYS_SETTING_H_INCLUDED