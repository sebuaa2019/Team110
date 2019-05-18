#include <stdlib.h>
#include "print_info.h"
#include "safety.h"
#include "controller.h"
#include "sys_setting.h"

void init_sys(){
    char setting[20];
    FILE *code;
	FILE *setall;
	if((code = fopen("settings","w")) == NULL){
 		creat("settings",00700);
		code = fopen("settings","w");
        	fprintf(code,"123456\n");
		fprintf(code,"20\n");
		fprintf(code,"13900000000\n");
		fprintf(code,"15\n");
		fprintf(code,"100\n");
		fprintf(code,"10\n");
        	fclose(code);
	}
	setall = fopen("settings","r");

	fgets(setting,20,setall);
    	setting[strlen(setting)-1] = '\0';

	fgets(setting,20,setall);
    	setting[strlen(setting)-1] = '\0';

	fgets(setting,20,setall);
    	setting[strlen(setting)-1] = '\0';

	fgets(setting,20,setall);
    	setting[strlen(setting)-1] = '\0';
	code_delay = atoi(setting);

	fgets(setting,20,setall);
    	setting[strlen(setting)-1] = '\0';
	smoke_limit = atoi(setting);

	fgets(setting,20,setall);
    	setting[strlen(setting)-1] = '\0';
	start_delay = atoi(setting);

	fclose(setall);
}

void modify_settings(){
    int choice;
    printf("请选择要修改的项目\n");
    printf("1: 修改密码\n");
    printf("2: 修改拨号间隔\n");
    printf("3: 修改报警电话\n");
    printf("4: 修改主人输密码时长\n");
    printf("5: 修改烟雾浓度阈值\n");
    printf("6: 修改开启系统时延\n");
    printf("7: 修改传感器参数\n");
    printf("8: 放弃修改\n");
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
	    modify_codedelay();
	    break;
	case 5:
	    modify_smokelimit();
	    break;
	case 6:
	    modify_startdelay();
	    break;
	case 7:
	    modify_sensor_setting();
	    break;
    }
    case 8:
        break;
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
    char line4[20];
    char line5[20];
    char line6[20];
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
	fgets(line4,20,codein);
	fgets(line5,20,codein);
	fgets(line6,20,codein);
	fclose(codein);

	codeout = fopen("settings","w");
        fprintf(codeout,"%s\n",once);
	fprintf(codeout,"%s",line2);
	fprintf(codeout,"%s",line3);
	fprintf(codeout,"%s",line4);
	fprintf(codeout,"%s",line5);
	fprintf(codeout,"%s",line6);
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
    char line4[20];
    char line5[20];
    char line6[20];

	FILE *codein;
        FILE *codeout;

        codein = fopen("settings","r");
	fgets(line1,20,codein);
	fgets(line2,20,codein);
	fgets(line3,20,codein);
	fgets(line4,20,codein);
	fgets(line5,20,codein);
	fgets(line6,20,codein);
	fclose(codein);

	printf("当前报警间隔为(单位：s)：%s",line2);
	printf("请输入新报警间隔：");
	scanf("%s",once);

	codeout = fopen("settings","w");
        fprintf(codeout,"%s",line1);
	fprintf(codeout,"%s\n",once);
	fprintf(codeout,"%s",line3);
	fprintf(codeout,"%s",line4);
	fprintf(codeout,"%s",line5);
	fprintf(codeout,"%s",line6);
        fclose(codeout);

        printf("修改间隔成功！\n");

}

void modify_phonenum(){
    char once[10];
    char line1[20];
    char line2[20];
    char line3[20];
    char line4[20];
    char line5[20];
    char line6[20];

	FILE *codein;
        FILE *codeout;

        codein = fopen("settings","r");
	fgets(line1,20,codein);
	fgets(line2,20,codein);
	fgets(line3,20,codein);
	fgets(line4,20,codein);
	fgets(line5,20,codein);
	fgets(line6,20,codein);
	fclose(codein);

	printf("当前报警电话为：%s",line3);
	printf("请输入新报警电话：");
	scanf("%s",once);

	codeout = fopen("settings","w");
        fprintf(codeout,"%s",line1);
	fprintf(codeout,"%s",line2);
	fprintf(codeout,"%s\n",once);
	fprintf(codeout,"%s",line4);
	fprintf(codeout,"%s",line5);
	fprintf(codeout,"%s",line6);
        fclose(codeout);

        printf("修改电话成功！\n");
}

void modify_codedelay(){
    char once[10];
    char line1[20];
    char line2[20];
    char line3[20];
    char line4[20];
    char line5[20];
    char line6[20];

	FILE *codein;
        FILE *codeout;

        codein = fopen("settings","r");
	fgets(line1,20,codein);
	fgets(line2,20,codein);
	fgets(line3,20,codein);
	fgets(line4,20,codein);
	fgets(line5,20,codein);
	fgets(line6,20,codein);
	fclose(codein);

	printf("当前输密码时长为：%s",line4);
	printf("请输入新时长：");



    while(1){
        scanf("%s",once);

        if(atoi(once)<=0){
            printf("您输入的值不合法，请重新输入: ");
        }
        else{
            code_delay = atoi(once);
            break;
        }
    }

	codeout = fopen("settings","w");
        fprintf(codeout,"%s",line1);
	fprintf(codeout,"%s",line2);
	fprintf(codeout,"%s",line3);
	fprintf(codeout,"%s\n",once);
	fprintf(codeout,"%s",line5);
	fprintf(codeout,"%s",line6);
        fclose(codeout);

        printf("修改成功！\n");
}

void modify_smokelimit(){
    char once[10];
    char line1[20];
    char line2[20];
    char line3[20];
    char line4[20];
    char line5[20];
    char line6[20];

	FILE *codein;
        FILE *codeout;

        codein = fopen("settings","r");
	fgets(line1,20,codein);
	fgets(line2,20,codein);
	fgets(line3,20,codein);
	fgets(line4,20,codein);
	fgets(line5,20,codein);
	fgets(line6,20,codein);
	fclose(codein);

	printf("当前烟雾浓度阈值为：%s",line5);
	printf("请输入新阈值：");

	 while(1){
        scanf("%s",&once);
        if(atoi(once)<=0){
            printf("您输入的值不合法，请重新输入: ");
        }
        else{
            smoke_limit = atoi(once);
            break;
        }
    }

	codeout = fopen("settings","w");
        fprintf(codeout,"%s",line1);
	fprintf(codeout,"%s",line2);
	fprintf(codeout,"%s",line3);
	fprintf(codeout,"%s",line4);
	fprintf(codeout,"%s\n",once);
	fprintf(codeout,"%s",line6);
        fclose(codeout);

        printf("修改成功！\n");
}

void modify_startdelay(){
    char once[10];
    char line1[20];
    char line2[20];
    char line3[20];
    char line4[20];
    char line5[20];
    char line6[20];

	FILE *codein;
        FILE *codeout;

        codein = fopen("settings","r");
	fgets(line1,20,codein);
	fgets(line2,20,codein);
	fgets(line3,20,codein);
	fgets(line4,20,codein);
	fgets(line5,20,codein);
	fgets(line6,20,codein);
	fclose(codein);

	printf("当前系统开启时延：%s",line6);
	printf("请输入新时延：");
	scanf("%s",once);
	start_delay = atoi(once);

	codeout = fopen("settings","w");
        fprintf(codeout,"%s",line1);
	fprintf(codeout,"%s",line2);
	fprintf(codeout,"%s",line3);
	fprintf(codeout,"%s",line4);
	fprintf(codeout,"%s",line5);
	fprintf(codeout,"%s\n",once);
        fclose(codeout);

        printf("修改成功！\n");
}


