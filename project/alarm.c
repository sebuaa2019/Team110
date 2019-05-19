#include <stdio.h>
#include <stdlib.h>
void alarm_bell(){

    return ;
}

void get_cellphone_number(){
    char line1[20];
    char line2[20];
    char tel_number[20];

	FILE *codein;

    codein = fopen("settings","r");
	fgets(line1,20,codein);
	fgets(line2,20,codein);
	fgets(tel_number,20,codein);
	fclose(codein);


}

void call(char* msg){
    get_cellphone_number();

    /* call for help */
}


void react(int type){
	switch(type){
		case 0: printf("检测到烟雾浓度超标\n");
			break;
		case 1: printf("未及时输入密码，判为恶意\n");
			break;
		case 2: printf("恶意入侵\n");
			break;
	}
}

void judge_offence(int switch_judge){
	if(switch_judge == 1) react(1);
}



