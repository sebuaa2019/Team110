#include <stdio.h>
#include <string.h>

int check_pssword(char *pssword)
{
    /*FILE *check;
    char right[10];
    check = fopen("settings","r");
    fgets(right,10,check);
    right[strlen(right)-1] = '\0';
    fclose(check);
    if(strcmp(right,pssword) == 0) return 1;
    else return 0;*/
	return 1;
    /*查询密码用户名是否匹配，成功return 1, 失败 -1*/
}

void login_info(char* pssword)
{
    int limittime = 5;
    int i = 0;
    int check;
    printf("欢迎进入家庭报警系统，请输入密码，最多尝试五次\n");
    while(i<5){
        printf("密码: ");
        strcpy(pssword,keyboard_long());
	/*scanf("%s",pssword);*/
        check = check_pssword(pssword);
        if(check==1) {
            printf("登陆成功！\n");
            break;
        }
        printf("密码错误，请重新输入\n");
        i++;
    }
    if(i == 5) exit(0);
}

void open_close(char* pssword,int type)
{
    int limittime = 5;
    int i = 0;
    int check;
    char type_char[50];

    if(type==0){
        strcpy(type_char,"开启");
    }
    else if(type==1){
        strcpy(type_char,"关闭");
    }
    printf("%s系统，请输入密码，最多尝试五次\n",type_char);
    while(i<5){
        printf("密码: ");
        /*scanf("%s",pssword);*/
	strcpy(pssword,keyboard_code());
        check = check_pssword(pssword);
        if(check==1) {
            printf("%s成功！\n",type_char);
            break;
        }
        printf("密码错误，请重新输入\n");
        i++;
    }
    if(i == 5) {
        printf("%s失败\n");
    };
}

int choose_func()
{
    int id;
    printf("请输入您需要的功能:(输入对应序号)\n");
    printf("ARM安装系统\n");
    printf("DISARM解除系统\n");
    printf("1: 用摄像头监视房间\n");
    printf("2: 报告错误\n");
    printf("3: 重新配置系统或传感器\n");
    printf("4: 修改设置与密码\n");
    printf("5: 用户信息查询与修改\n");
    printf("6: 登出系统\n");
    id = keyboard_single();
    return id;
}



