#include <stdio.h>
#include <io.h>

int check_pssword(char *pssword)
{
    FILE *check;
    char right[10];
    check = fopen("settings","r");
    fgets(right,10,check);
    if(strcmp(right,pssword) == 0) return 1;
    else return 0;
    //查询密码用户名是否匹配，成功return 1, 失败 -1
}
void login_info(char* pssword)
{
    printf("欢迎进入家庭报警系统，请输入密码，最多尝试五次\n");
    int limittime = 5; //最多输入五次
    int i = 0;
    while(i<5){
        printf("密码: ");
        scanf("%s",pssword);
        int check = check_pssword(pssword);
        if(check==1) {
            printf("登陆成功！\n");
            break;
        }
        printf("密码错误，请重新输入\n");
        i++;
    }
    if(i == 5) exit(0);
}
int choose_func()
{
    int id;
    printf("请输入您需要的功能:(输入对应序号)\n");
    printf("1: 安装系统\n");
    printf("2: 解除系统\n");
    printf("3: 用摄像头监视房间\n");
    printf("4: 报告错误\n");
    printf("5: 重新配置系统或传感器\n");
    printf("6: 修改设置与密码\n");
    printf("7: 用户信息查询与修改\n");
    printf("8: 登出系统\n");
    scanf("%d",&id);
    return id;
}



