#include<stdio.h>
#include<string.h>
#include "keyboard.h"
void keyboard_init(){
    #ifdef	USER_APPL_INIT
	USER_APPL_INIT;		/* for backwards compatibility */
    #endif
	usrTffsConfig (0,0,"/tffs0");
	/* add application specific code here */
	HomeAlarmIODrvInit();
}

int keyboard_single(){
    while(1){
        if(OnArm()){
            printf("arm\n");
            return 12;
        }
        if(OnDisarm())
		{
			printf("disarm\n");
            return 13;
		}
		if(OnKey(&cKey))
		{
			if(cKey == '*')	{
                printf("off\n");
                return 10;
			}
			if(cKey == '#'){
                printf("on\n");
                return 11;
			}
			if(cKey == '0'){
                printf("0\n");
                return 0;
			}

			if(cKey == '1'){
                printf("1\n");
                return 1;
			}
            if(cKey == '2'){
                printf("2\n");
                return 2;
			}
			if(cKey == '3'){
                printf("3\n");
                return 3;
			}
			if(cKey == '4'){
                printf("4\n");
                return 4;
			}
			if(cKey == '5'){
                printf("5\n");
                return 5;
			}
			if(cKey == '6'){
                printf("6\n");
                return 6;
			}
			if(cKey == '7'){
                printf("7\n");
                return 7;
			}
			if(cKey == '8'){
                printf("8\n");
                return 8;
			}
			if(cKey == '9'){
                printf("9\n");
                return 9;
			}
		}
	taskDelay(5);	
		
    }
}

char* keyboard_long(){
    int temp=0;
    int i=0;
    static char num[50];
	strcpy(num,"");
    while(1){
		if(OnKey(&cKey))
		{
			if(cKey == '*'){
                printf("\n");
                return num;
			}
            if(cKey == '0'){
                strcat(num,"0");
                printf("0");
			}
			if(cKey == '1'){
                strcat(num,"1");
                printf("1");
			}
            if(cKey == '2'){
                strcat(num,"2");
                printf("2");
			}
			if(cKey == '3'){
			    strcat(num,"3");
                printf("3");
			}
			if(cKey == '4'){
			    strcat(num,"4");
                printf("4");
			}
			if(cKey == '5'){
                strcat(num,"5");
                printf("5");
			}
			if(cKey == '6'){
			    strcat(num,"6");
                printf("6");
			}
			if(cKey == '7'){
			    strcat(num,"7");
                printf("7");
			}
			if(cKey == '8'){
			    strcat(num,"8");
                printf("8");
			}
			if(cKey == '9'){
			    strcat(num,"9");
                printf("9");
			}
		}
		taskDelay(5);
    }
}

char* keyboard_code(){
    int temp=0;
    int i=0;
    static char num[50];
	strcpy(num,"");
    while(1){
		if(OnKey(&cKey))
		{
			if(cKey == '*'){
                printf("\n");
                return num;
			}
            if(cKey == '0'){
                strcat(num,"0");
                printf("*");
			}
			if(cKey == '1'){
                strcat(num,"1");
                printf("*");
			}
            if(cKey == '2'){
                strcat(num,"2");
                printf("*");
			}
			if(cKey == '3'){
			    strcat(num,"3");
                printf("*");
			}
			if(cKey == '4'){
			    strcat(num,"4");
                printf("*");
			}
			if(cKey == '5'){
                strcat(num,"5");
                printf("*");
			}
			if(cKey == '6'){
			    strcat(num,"6");
                printf("*");
			}
			if(cKey == '7'){
			    strcat(num,"7");
                printf("*");
			}
			if(cKey == '8'){
			    strcat(num,"8");
                printf("*");
			}
			if(cKey == '9'){
			    strcat(num,"9");
                printf("*");
			}
		}
		taskDelay(5);
    }
}