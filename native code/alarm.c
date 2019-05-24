#include <stdio.h>

void react(int type){
	while(1){
	switch(type){
		case 0: SetCall("13612345678",0,0);
			printf("检测到烟雾浓度超标\n");
			break;
		case 1: printf("未及时输入密码，判为恶意\n");
			break;
		case 2: printf("恶意入侵\n");
			break;
	}
	taskDelay(10);
	}
}

void judge_offence(int switch_judge){
	if(switch_judge == 1) react(1);
}



