#include "print_info.h"
#include "safety.h"

void init_sys(); /*开启系统时的初始化*/
void change_code(); /*修改密码*/
void write_new_code(); /*把新密码存储下来*/
void modify_settings();/*修改各项设置*/
void modify_delay();/*修改报警间隔*/
void modify_phonenum();/*修改报警电话*/

void init_sys(){
    FILE *code;
	if((code = fopen("settings","w")) == NULL){
 		creat("settings",00700);       
		code = fopen("settings","w");
        	fprintf(code,"123456\n");
		fprintf(code,"20\n");
		fprintf(code,"13900000000\n");
        	fclose(code);
	}
}

void modify_settings(){
    int choice;
    printf("请选择要修改的项目\n");
    printf("1: 修改密码\n");
    printf("2: 修改拨号间隔\n");
    printf("3: 修改报警电话\n");
    printf("4: 放弃修改\n");
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
	case 4:
	    break;
    }
}

void change_code(){
    char former[10]; /*当前密码*/
    char newcode[10]; /*新密码*/
    int limittime = 5; /*最多输入五次*/
    int check;
    int i = 0;
    printf("请输入当前密码\n");
    while(i<5){
        printf("当前密码: ");
        scanf("%s",former);
        check = check_pssword(former);
        if(check==1) {
            printf("密码正确！\n");
            write_new_code();
            break;
        }
        printf("密码错误，请重新输入\n");
        i++;
    }
}

void write_new_code(){
    char once[10];
    char twice[10];
    char line2[20];
    char line3[20];
    printf("请输入新密码：");
    scanf("%s",once);
    printf("确认新密码：");
    scanf("%s",twice);
    if(strcmp(once,twice) == 0){
	FILE *codein;
        FILE *codeout;

        codein = fopen("settings","r");
	fgets(line2,20,codein);
	fgets(line2,20,codein);
	fgets(line3,20,codein);
	fclose(codein);

	codeout = fopen("settings","w");	
        fprintf(codeout,"%s\n",once);
	fprintf(codeout,"%s",line2);
	fprintf(codeout,"%s",line3);
        fclose(codeout);
	
        printf("修改密码成功！\n");
    }
    else{
        printf("输入不一致，修改失败\n");
    }
}

void modify_delay(){
    char once[10];
    char line1[20];
    char line2[20];
    char line3[20];

	FILE *codein;
        FILE *codeout;

        codein = fopen("settings","r");
	fgets(line1,20,codein);
	fgets(line2,20,codein);
	fgets(line3,20,codein);
	fclose(codein);

	printf("当前报警间隔为(单位：s)：%s",line2);
	printf("请输入新报警间隔：");
	scanf("%s",once);

	codeout = fopen("settings","w");	
        fprintf(codeout,"%s",line1);
	fprintf(codeout,"%s\n",once);
	fprintf(codeout,"%s",line3);
        fclose(codeout);
	
        printf("修改间隔成功！\n");

}

void modify_phonenum(){
    char once[10];
    char line1[20];
    char line2[20];
    char line3[20];

	FILE *codein;
        FILE *codeout;

        codein = fopen("settings","r");
	fgets(line1,20,codein);
	fgets(line2,20,codein);
	fgets(line3,20,codein);
	fclose(codein);

	printf("当前报警电话为：%s",line3);
	printf("请输入新报警电话：");
	scanf("%s",once);

	codeout = fopen("settings","w");	
        fprintf(codeout,"%s",line1);
	fprintf(codeout,"%s",line2);
	fprintf(codeout,"%s\n",once);
        fclose(codeout);
	
        printf("修改电话成功！\n");
}

void modify_sys(){
    int id;
    printf("您已进入系统参数修改中心\n");
    printf("请输入您需要的功能:(输入对应序号)\n");
    printf("1: 修改传感器参数\n");
    printf("2: 退出系统参数修改中心\n");
    scanf("%d",&id);
    switch(id)
    {
        case 1:{
            modify_sensor_setting();
            break;
        }
        case 2:{
            printf("您已退出系统参数修改中心\n");
            break;
        }
    }
}