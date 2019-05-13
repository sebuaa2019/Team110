#include <stdio.h>

int check_pssword(char *usrname, char *pssword)
{
    //查询密码用户名是否匹配，成功return 1, 失败 -1
    return 1;
}
void login_info(char* usrname, char* pssword)
{
    printf("欢迎进入家庭报警系统，请先登陆\n");
    while(1){
        printf("用户名：");
        scanf("%s",usrname);
        printf("密码: ");
        scanf("%s",pssword);
        int check = check_pssword(usrname,pssword);
        if(check==1) {
            printf("登陆成功！\n");
            break;
        }
        printf("用户名或密码错误，请重新输入\n");
    }
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
    printf("6: 登出系统\n");
    scanf("%d",&id);
    return id;
}



